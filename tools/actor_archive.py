#!/usr/bin/env python3
"""Export and rebuild FoMT actor frames from the native indexed archive.

The actor archive is not a linear sprite sheet.  Its seven counted tables
contain animation sequences, 16-byte frame descriptors, 8-byte OAM pieces,
4bpp tiles, palettes, and frame timing entries.  This tool keeps that native
layout in ROM/assembly and exposes only complete, OAM-composited indexed PNG
frames for editing.  It deliberately has no JSON layout sidecar: all geometry
is read directly from the archive that the game consumes.
"""

from __future__ import annotations

import argparse
import hashlib
from dataclasses import dataclass
from pathlib import Path

from portrait_archive import (
    Archive,
    OAM_DIMENSIONS,
    assign_native_pixel,
    load_archive,
    palette,
    read_png_indexed,
    read_u16,
    tile_pixels,
    write_png_indexed,
)


ACTOR_ARCHIVE_COUNTS = (2551, 3009, 4795, 24398, 162, 0, 3990)


@dataclass(frozen=True)
class Frame:
    oam_count: int
    oam_start: int
    tile_count: int
    tile_start: int
    palette_id: int


@dataclass(frozen=True)
class OamPiece:
    x: int
    y: int
    width: int
    height: int
    tile_start: int
    h_flip: bool
    v_flip: bool


def parse_ids(text: str) -> list[int]:
    values: list[int] = []
    for raw_part in text.split(","):
        part = raw_part.strip()
        if not part:
            continue
        if "-" not in part:
            values.append(int(part, 0))
            continue
        start_text, end_text = part.split("-", 1)
        start = int(start_text.strip(), 0)
        end = int(end_text.strip(), 0)
        if end < start:
            raise argparse.ArgumentTypeError(
                f"animation range must ascend, got {part}"
            )
        values.extend(range(start, end + 1))
    if not values:
        raise argparse.ArgumentTypeError("at least one animation ID or range is required")
    return values


def animation_frames(archive: Archive, animation_id: int) -> list[tuple[int, int]]:
    if not 0 <= animation_id < archive.counts[0]:
        raise ValueError(f"animation {animation_id} is outside the animation table")
    offset = archive.table_offsets[0] + animation_id * 4
    entry_count = read_u16(archive.data, offset)
    first_entry = read_u16(archive.data, offset + 2)
    if first_entry + entry_count > archive.counts[6]:
        raise ValueError(f"animation {animation_id} points outside the frame-entry table")
    return [
        (
            read_u16(archive.data, archive.table_offsets[6] + (first_entry + index) * 4),
            read_u16(archive.data, archive.table_offsets[6] + (first_entry + index) * 4 + 2),
        )
        for index in range(entry_count)
    ]


def frame_descriptor(archive: Archive, frame_id: int) -> Frame:
    if not 0 <= frame_id < archive.counts[1]:
        raise ValueError(f"frame {frame_id} is outside the frame-descriptor table")
    offset = archive.table_offsets[1] + frame_id * 16
    frame = Frame(
        read_u16(archive.data, offset),
        read_u16(archive.data, offset + 2),
        read_u16(archive.data, offset + 4),
        read_u16(archive.data, offset + 6),
        read_u16(archive.data, offset + 10),
    )
    if frame.oam_start + frame.oam_count > archive.counts[2]:
        raise ValueError(f"frame {frame_id} OAM range is outside table three")
    if frame.tile_start + frame.tile_count > archive.counts[3]:
        raise ValueError(f"frame {frame_id} tile range is outside table four")
    if frame.palette_id >= archive.counts[4]:
        raise ValueError(f"frame {frame_id} palette is outside table five")
    return frame


def frame_oam(archive: Archive, frame_id: int) -> list[OamPiece]:
    frame = frame_descriptor(archive, frame_id)
    pieces: list[OamPiece] = []
    for index in range(frame.oam_count):
        offset = archive.table_offsets[2] + (frame.oam_start + index) * 8
        attr0 = read_u16(archive.data, offset)
        attr1 = read_u16(archive.data, offset + 2)
        attr2 = read_u16(archive.data, offset + 4)
        dimensions = OAM_DIMENSIONS.get(((attr0 >> 14) & 3, (attr1 >> 14) & 3))
        if dimensions is None:
            raise ValueError(f"frame {frame_id} OAM {index} has an invalid shape/size")
        width, height = dimensions
        local_tile = attr2 & 0x3FF
        if local_tile + width * height // 64 > frame.tile_count:
            raise ValueError(f"frame {frame_id} OAM {index} reads outside its tile range")
        x = attr1 & 0x1FF
        y = attr0 & 0xFF
        if x > 255:
            x -= 512
        if y > 127:
            y -= 256
        pieces.append(OamPiece(
            x, y, width, height, frame.tile_start + local_tile,
            bool(attr1 & 0x1000), bool(attr1 & 0x2000),
        ))
    return pieces


def frame_canvas(archive: Archive, frame_id: int) -> tuple[int, int, int, int, list[OamPiece]]:
    pieces = frame_oam(archive, frame_id)
    if not pieces:
        raise ValueError(f"frame {frame_id} has no drawable OAM pieces")
    min_x = min(piece.x for piece in pieces)
    min_y = min(piece.y for piece in pieces)
    max_x = max(piece.x + piece.width for piece in pieces)
    max_y = max(piece.y + piece.height for piece in pieces)
    return min_x, min_y, max_x - min_x, max_y - min_y, pieces


def rendered_pixel_layers(archive: Archive, frame_id: int) -> tuple[int, int, bytes, list[list[tuple[int, int]]]]:
    """Return the OAM-composited frame plus its visible native-pixel mapping."""
    min_x, min_y, width, height, pieces = frame_canvas(archive, frame_id)
    baseline = bytearray(width * height)
    layers: list[list[tuple[int, int]]] = [[] for _ in range(width * height)]
    for piece in pieces:
        tiles_wide = piece.width // 8
        tiles_high = piece.height // 8
        for source_tile_y in range(tiles_high):
            for source_tile_x in range(tiles_wide):
                global_tile = piece.tile_start + source_tile_y * tiles_wide + source_tile_x
                values = tile_pixels(archive, global_tile)
                draw_tile_x = tiles_wide - 1 - source_tile_x if piece.h_flip else source_tile_x
                draw_tile_y = tiles_high - 1 - source_tile_y if piece.v_flip else source_tile_y
                for source_pixel_y in range(8):
                    for source_pixel_x in range(8):
                        draw_pixel_x = 7 - source_pixel_x if piece.h_flip else source_pixel_x
                        draw_pixel_y = 7 - source_pixel_y if piece.v_flip else source_pixel_y
                        target_x = piece.x - min_x + draw_tile_x * 8 + draw_pixel_x
                        target_y = piece.y - min_y + draw_tile_y * 8 + draw_pixel_y
                        target = target_y * width + target_x
                        native_pixel = source_pixel_y * 8 + source_pixel_x
                        layers[target].append((global_tile, native_pixel))
                        value = values[native_pixel]
                        if value:
                            baseline[target] = value
    return width, height, bytes(baseline), layers


def selected_frame_ids(archive: Archive, animation_ids: list[int]) -> list[int]:
    result: set[int] = set()
    for animation_id in animation_ids:
        for frame_id, _duration in animation_frames(archive, animation_id):
            frame_descriptor(archive, frame_id)
            result.add(frame_id)
    return sorted(result)


def source_file(sources: list[Path], frame_id: int) -> Path:
    matches = [source / "full" / f"frame_{frame_id:04d}.png" for source in sources]
    matches = [filename for filename in matches if filename.is_file()]
    if not matches:
        locations = ", ".join(str(source / "full") for source in sources)
        raise ValueError(f"missing authored frame {frame_id:04d} in: {locations}")
    if len(matches) != 1:
        locations = ", ".join(map(str, matches))
        raise ValueError(f"frame {frame_id:04d} occurs in multiple actor sources: {locations}")
    return matches[0]


def audit(archive: Archive) -> None:
    if archive.counts != ACTOR_ARCHIVE_COUNTS:
        raise ValueError(f"unexpected actor archive table counts: {archive.counts}")
    referenced_frames: set[int] = set()
    for animation_id in range(archive.counts[0]):
        for frame_id, _duration in animation_frames(archive, animation_id):
            referenced_frames.add(frame_id)
    for frame_id in sorted(referenced_frames):
        frame_oam(archive, frame_id)
    print(f"tables: {', '.join(map(str, archive.counts))}")
    print(f"referenced frame descriptors: {len(referenced_frames)} / {archive.counts[1]}")
    print("animation descriptors, frame records, OAM ranges, tile ranges, and palettes verified")


def export_frames(archive: Archive, animation_ids: list[int], output: Path, replace: bool) -> None:
    audit(archive)
    frame_ids = selected_frame_ids(archive, animation_ids)
    preserved = 0
    written = 0
    for frame_id in frame_ids:
        frame = frame_descriptor(archive, frame_id)
        width, height, indexes, _layers = rendered_pixel_layers(archive, frame_id)
        destination = output / "full" / f"frame_{frame_id:04d}.png"
        source_palette = palette(archive, frame.palette_id)
        if destination.is_file() and not replace:
            existing = read_png_indexed(destination)
            if existing == (width, height, indexes, source_palette):
                preserved += 1
                continue
            raise ValueError(
                f"{destination} already contains authored pixels; use --replace to overwrite it"
            )
        write_png_indexed(destination, width, height, indexes, source_palette)
        written += 1
    print(
        f"exported {written} and preserved {preserved} complete OAM-composited frame PNGs "
        f"in {output / 'full'}"
    )


def rebuild_frames(archive: Archive, animation_ids: list[int], sources: list[Path], output: Path) -> None:
    audit(archive)
    tile_offset = archive.table_offsets[3]
    native = bytearray(archive.data[tile_offset:tile_offset + archive.counts[3] * 32])
    assignments: dict[tuple[int, int], int] = {}
    changed_pixels = 0
    for frame_id in selected_frame_ids(archive, animation_ids):
        frame = frame_descriptor(archive, frame_id)
        filename = source_file(sources, frame_id)
        width, height, source_indexes, source_palette = read_png_indexed(filename)
        expected_width, expected_height, baseline, layers = rendered_pixel_layers(archive, frame_id)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != palette(archive, frame.palette_id):
            raise ValueError(f"{filename} has changed its native 16-color palette")
        for target, value in enumerate(source_indexes):
            if value == baseline[target]:
                continue
            changed_pixels += 1
            if not layers[target]:
                if value:
                    raise ValueError(f"{filename} draws outside frame {frame_id}'s OAM bounds")
                continue
            if value == 0:
                for global_tile, native_pixel in layers[target]:
                    assign_native_pixel(native, assignments, global_tile, native_pixel, 0)
            else:
                global_tile, native_pixel = layers[target][-1]
                assign_native_pixel(native, assignments, global_tile, native_pixel, value)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(native)
    print(f"rebuilt {len(native)} actor-tile bytes with {changed_pixels} visible pixel changes")
    print(f"actor tile SHA-256: {hashlib.sha256(native).hexdigest()}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="retail ROM containing the actor archive")
    parser.add_argument("--offset", required=True, type=lambda text: int(text, 0), help="actor archive ROM offset")
    parser.add_argument("--length", default=0xDB638, type=lambda text: int(text, 0), help="full actor archive length")
    parser.add_argument("--sha256", help="expected complete archive SHA-256")
    subparsers = parser.add_subparsers(dest="command", required=True)
    subparsers.add_parser("audit", help="validate native actor archive relationships")
    export_parser = subparsers.add_parser("export", help="write complete indexed actor frame PNGs")
    export_parser.add_argument(
        "--animations", required=True, type=parse_ids,
        help="comma-separated animation IDs or inclusive ranges (for example 0x212-0x216)",
    )
    export_parser.add_argument("--output", required=True, type=Path)
    export_parser.add_argument("--replace", action="store_true", help="replace existing authored PNGs")
    rebuild_parser = subparsers.add_parser("rebuild", help="rebuild native actor table-four tiles from complete PNGs")
    rebuild_parser.add_argument(
        "--animations", required=True, type=parse_ids,
        help="comma-separated animation IDs or inclusive ranges (for example 0x212-0x216)",
    )
    rebuild_parser.add_argument(
        "--source", required=True, nargs="+", type=Path,
        help="one or more actor source directories; each frame may occur in only one",
    )
    rebuild_parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    archive = load_archive(args.rom, args.offset, args.length, trailing_bytes=0)
    digest = hashlib.sha256(archive.data).hexdigest()
    if args.sha256 and digest != args.sha256.lower():
        raise ValueError(f"archive SHA-256 mismatch: expected {args.sha256.lower()}, got {digest}")
    print(f"archive SHA-256: {digest}")
    if args.command == "audit":
        audit(archive)
    elif args.command == "export":
        export_frames(archive, args.animations, args.output, args.replace)
    elif args.command == "rebuild":
        rebuild_frames(archive, args.animations, args.source, args.output)
    else:
        raise AssertionError("unreachable")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

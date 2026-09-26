#!/usr/bin/env python3
"""Rebuild the four regional indexed OAM archives initialized by func_08000914.

The native archive has seven counted tables.  Its first table selects frames,
the second describes their OAM/tile/palette ranges, and its third through
fifth tables contain ordinary GBA OAM records, 4bpp tiles, and BGR555
palettes.  Geometry is always read from those tables: complete indexed PNG
frames are authoring inputs, and there is deliberately no JSON layout file.
The title logo frames are 8bpp and use the complete runtime OBJ palette,
whose low banks are loaded outside this archive.  A captured, verified
512-byte palette therefore accompanies each regional source group.

JP, US/EU, and DE each retain their own source directory.  US and EU are
byte-identical; JP and DE have independently verified layouts and must not be
silently treated as a shared resource.
"""

from __future__ import annotations

import argparse
import hashlib
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path[:0] = [str(TOOLS), str(TOOLS / "scripts")]

from actor_archive import (  # type: ignore[import-not-found]
    animation_frames,
    frame_descriptor,
    frame_oam,
    selected_frame_ids,
)
from decompress import unpack  # type: ignore[import-not-found]
from portrait_archive import (  # type: ignore[import-not-found]
    Archive,
    TABLE_STRIDES,
    palette,
    read_u32,
)
from tile_grid import colors_from_bgr555, read_png, write_png  # type: ignore[import-not-found]


@dataclass(frozen=True)
class Region:
    offset: int
    length: int
    sha256: str
    source_group: str


REGIONS = {
    "jp": Region(0x4CDBDC, 0x2D90, "e38a172d4e1b6a0b5440c2ae33a46c68efa8b6c86e49879809bbd839996d9716", "jp"),
    "us": Region(0x747A74, 0x2764, "82c85aa740e76fa0b3266746c1031c0532d08b458b87a70fdc271206b33cfeef", "us_eu"),
    "eu": Region(0x747AD0, 0x2764, "82c85aa740e76fa0b3266746c1031c0532d08b458b87a70fdc271206b33cfeef", "us_eu"),
    "de": Region(0x4CEEE8, 0x275C, "d92d18ce162cec7cfff8ee53f8dfcb035635d073e7d386276fb2d7185db025ad", "de"),
}


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def source_dir(root: Path, region: str) -> Path:
    return root / REGIONS[region].source_group


def load_runtime_obj_palette(directory: Path) -> bytes:
    filename = directory / "runtime_obj_palette.gbapal"
    data = filename.read_bytes()
    if len(data) != 512:
        raise ValueError(f"{filename} must contain exactly 512 bytes")
    return data


def archive_from_data(data: bytes) -> Archive:
    """Parse exactly the seven counted tables established by the C++ constructor."""
    cursor = 0
    counts: list[int] = []
    offsets: list[int] = []
    for stride in TABLE_STRIDES:
        if cursor + 4 > len(data):
            raise ValueError("indexed archive ends in a table count")
        count = read_u32(data, cursor)
        cursor += 4
        offsets.append(cursor)
        end = cursor + count * stride
        if end > len(data):
            raise ValueError("indexed archive table exceeds decoded range")
        counts.append(count)
        cursor = end
    if cursor != len(data):
        raise ValueError(
            f"indexed archive has {len(data) - cursor:#x} trailing bytes after its frame-entry table"
        )
    return Archive(data, tuple(offsets), tuple(counts), cursor)


def load_region(path: Path, region: str) -> tuple[bytes, bytes, str, str, Archive]:
    config = REGIONS[region]
    rom = path.read_bytes()
    packed = rom[config.offset:config.offset + config.length]
    if len(packed) != config.length:
        raise ValueError(f"{region}: archive range exceeds ROM bounds")
    if digest(packed) != config.sha256:
        raise ValueError(f"{region}: packed archive SHA-256 does not match the retail baseline")
    decoded, format_spec, ladder = unpack(packed)
    if format_spec not in ("120", "220"):
        raise ValueError(f"{region}: unsupported indexed archive format {format_spec}")
    return packed, bytes(decoded), format_spec, ladder, archive_from_data(bytes(decoded))


def selected_frames(archive: Archive) -> list[int]:
    return selected_frame_ids(archive, list(range(archive.counts[0])))


def frame_bpp(archive: Archive, frame_id: int) -> int:
    """Return the hardware OBJ colour depth used by one frame."""
    frame = frame_descriptor(archive, frame_id)
    depths: set[int] = set()
    for index in range(frame.oam_count):
        offset = archive.table_offsets[2] + (frame.oam_start + index) * 8
        attr0 = int.from_bytes(archive.data[offset:offset + 2], "little")
        depths.add(8 if attr0 & 0x2000 else 4)
    if len(depths) != 1:
        raise ValueError(f"frame {frame_id} mixes unsupported OBJ colour depths: {sorted(depths)}")
    return depths.pop()


def frame_palette(
    archive: Archive,
    frame_id: int,
    bpp: int,
    runtime_obj_palette: bytes | None = None,
) -> tuple[tuple[int, int, int, int], ...]:
    frame = frame_descriptor(archive, frame_id)
    if bpp == 4:
        return palette(archive, frame.palette_id)
    if runtime_obj_palette is not None:
        if len(runtime_obj_palette) != 512:
            raise ValueError("an 8bpp runtime OBJ palette must contain exactly 512 bytes")
        return colors_from_bgr555(runtime_obj_palette, 8)
    if frame.palette_id + 16 > archive.counts[4]:
        raise ValueError(f"frame {frame_id} 8bpp palette exceeds table five")
    offset = archive.table_offsets[4] + frame.palette_id * 32
    return colors_from_bgr555(archive.data[offset:offset + 512], 8)


def rendered_frame(
    archive: Archive, frame_id: int
) -> tuple[int, int, bytes, list[list[tuple[int, int]]], int]:
    """Composite a 4bpp or 8bpp OBJ frame and retain native-byte mappings.

    Each mapping is ``(byte_offset, shift)`` relative to table four.  A shift
    of -1 denotes an 8bpp byte; 0 and 4 denote the low/high 4bpp nibble.
    """
    frame = frame_descriptor(archive, frame_id)
    pieces = frame_oam(archive, frame_id)
    if not pieces:
        raise ValueError(f"frame {frame_id} has no drawable OAM pieces")
    bpp = frame_bpp(archive, frame_id)
    min_x = min(piece.x for piece in pieces)
    min_y = min(piece.y for piece in pieces)
    max_x = max(piece.x + piece.width for piece in pieces)
    max_y = max(piece.y + piece.height for piece in pieces)
    width, height = max_x - min_x, max_y - min_y
    baseline = bytearray(width * height)
    layers: list[list[tuple[int, int]]] = [[] for _ in range(width * height)]
    tile_table = archive.table_offsets[3]

    for piece in pieces:
        tiles_wide = piece.width // 8
        tiles_high = piece.height // 8
        unit_stride = 2 if bpp == 8 else 1
        local_start = piece.tile_start - frame.tile_start
        required_units = tiles_wide * tiles_high * unit_stride
        if local_start + required_units > frame.tile_count:
            raise ValueError(f"frame {frame_id} OAM piece reads outside its tile range")
        for source_tile_y in range(tiles_high):
            for source_tile_x in range(tiles_wide):
                logical_tile = source_tile_y * tiles_wide + source_tile_x
                unit = piece.tile_start + logical_tile * unit_stride
                tile_offset = tile_table + unit * 32
                if bpp == 8:
                    values = archive.data[tile_offset:tile_offset + 64]
                else:
                    packed = archive.data[tile_offset:tile_offset + 32]
                    values = bytes(value for byte in packed for value in (byte & 15, byte >> 4))
                draw_tile_x = tiles_wide - 1 - source_tile_x if piece.h_flip else source_tile_x
                draw_tile_y = tiles_high - 1 - source_tile_y if piece.v_flip else source_tile_y
                for source_pixel_y in range(8):
                    for source_pixel_x in range(8):
                        draw_pixel_x = 7 - source_pixel_x if piece.h_flip else source_pixel_x
                        draw_pixel_y = 7 - source_pixel_y if piece.v_flip else source_pixel_y
                        target_x = piece.x - min_x + draw_tile_x * 8 + draw_pixel_x
                        target_y = piece.y - min_y + draw_tile_y * 8 + draw_pixel_y
                        target = target_y * width + target_x
                        pixel = source_pixel_y * 8 + source_pixel_x
                        if bpp == 8:
                            mapping = (unit * 32 + pixel, -1)
                        else:
                            mapping = (unit * 32 + pixel // 2, 4 if pixel & 1 else 0)
                        layers[target].append(mapping)
                        value = values[pixel]
                        if value:
                            baseline[target] = value
    return width, height, bytes(baseline), layers, bpp


def assign_native_pixel(
    native: bytearray,
    assignments: dict[tuple[int, int], int],
    mapping: tuple[int, int],
    value: int,
) -> None:
    existing = assignments.get(mapping)
    if existing is not None and existing != value:
        raise ValueError(f"conflicting edits assign {existing} and {value} to native pixel {mapping}")
    assignments[mapping] = value
    offset, shift = mapping
    if shift < 0:
        native[offset] = value
    else:
        mask = 15 << shift
        native[offset] = (native[offset] & ~mask) | value << shift


def audit(archive: Archive, region: str, format_spec: str, ladder: str) -> list[int]:
    """Prove the descriptor/OAM relationships before PNGs become sources."""
    frames = selected_frames(archive)
    for animation_id in range(archive.counts[0]):
        animation_frames(archive, animation_id)
    for frame_id in frames:
        frame_oam(archive, frame_id)
    all_frames = set(range(archive.counts[1]))
    missing = sorted(all_frames - set(frames))
    print(
        f"{region.upper()}: format={format_spec}, ladder={ladder}, "
        f"selectors={archive.counts[0]}, frames={len(frames)}/{archive.counts[1]}, "
        f"OAM={archive.counts[2]}, tiles={archive.counts[3]}, palettes={archive.counts[4]}"
    )
    if missing:
        print(f"{region.upper()}: {len(missing)} unselected frame descriptor(s) remain baseline-preserved")
    else:
        print(f"{region.upper()}: every frame descriptor is selected and OAM-range verified")
    empty = sum(not frame_oam(archive, frame_id) for frame_id in frames)
    if empty:
        print(f"{region.upper()}: {empty} selected descriptor(s) have no drawable OAM and remain table-only")
    return frames


def frame_source(directory: Path, frame_id: int) -> Path:
    return directory / "full" / f"frame_{frame_id:04d}.png"


def export_frames(
    archive: Archive,
    frames: list[int],
    directory: Path,
    replace: bool,
    runtime_obj_palette: bytes | None = None,
) -> None:
    written = 0
    preserved = 0
    for frame_id in frames:
        if not frame_oam(archive, frame_id):
            continue
        width, height, indexes, _layers, bpp = rendered_frame(archive, frame_id)
        output = frame_source(directory, frame_id)
        expected = (
            indexes,
            width,
            height,
            frame_palette(archive, frame_id, bpp, runtime_obj_palette),
        )
        if output.exists() and not replace:
            if read_png(output, bpp) != expected:
                raise ValueError(f"{output} differs from retail data; use --replace to overwrite it")
            preserved += 1
            continue
        write_png(output, *expected)
        written += 1
    print(f"exported {written} and preserved {preserved} OAM-composited frame PNG(s) in {directory / 'full'}")


def rebuild_tiles(
    archive: Archive,
    frames: list[int],
    directory: Path,
    runtime_obj_palette: bytes | None = None,
) -> bytes:
    tile_offset = archive.table_offsets[3]
    native = bytearray(archive.data[tile_offset:tile_offset + archive.counts[3] * 32])
    assignments: dict[tuple[int, int], int] = {}
    for frame_id in frames:
        if not frame_oam(archive, frame_id):
            continue
        filename = frame_source(directory, frame_id)
        expected_width, expected_height, baseline, layers, bpp = rendered_frame(archive, frame_id)
        source_indexes, width, height, source_palette = read_png(filename, bpp)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != frame_palette(archive, frame_id, bpp, runtime_obj_palette):
            raise ValueError(f"{filename} has changed its verified runtime palette")
        for target, value in enumerate(source_indexes):
            if value == baseline[target]:
                continue
            if not layers[target]:
                if value:
                    raise ValueError(f"{filename} draws outside frame {frame_id}'s OAM bounds")
                continue
            if value == 0:
                for mapping in layers[target]:
                    assign_native_pixel(native, assignments, mapping, 0)
            else:
                assign_native_pixel(native, assignments, layers[target][-1], value)
    return bytes(native)


def patched_decoded(
    archive: Archive,
    frames: list[int],
    directory: Path,
    runtime_obj_palette: bytes | None = None,
) -> bytes:
    result = bytearray(archive.data)
    tile_offset = archive.table_offsets[3]
    tiles = rebuild_tiles(archive, frames, directory, runtime_obj_palette)
    result[tile_offset:tile_offset + len(tiles)] = tiles
    return bytes(result)


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path) for region, path in arguments.rom}
    if set(inputs) != set(REGIONS):
        raise ValueError("export requires jp, us, eu, and de ROMs")
    streams: dict[str, bytes] = {}
    for region in REGIONS:
        packed, _decoded, format_spec, ladder, archive = load_region(inputs[region], region)
        streams[region] = packed
        frames = audit(archive, region, format_spec, ladder)
        directory = source_dir(arguments.source_root, region)
        export_frames(
            archive,
            frames,
            directory,
            arguments.replace,
            load_runtime_obj_palette(directory),
        )
    if streams["us"] != streams["eu"]:
        raise AssertionError("US and EU indexed archives must remain byte-identical")
    print("verified US/EU shared archive bytes; JP and DE retain independent sources")


def build_decoded(arguments: argparse.Namespace) -> None:
    """Apply complete frame PNG edits to a source-assembled native archive."""
    archive = archive_from_data(arguments.source_archive.read_bytes())
    frames = audit(archive, arguments.region, "decoded source", "source-owned")
    directory = source_dir(arguments.source_root, arguments.region)
    source = patched_decoded(
        archive,
        frames,
        directory,
        load_runtime_obj_palette(directory),
    )
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(source)
    print(f"rebuilt {arguments.region.upper()} indexed archive ({len(source):#x} decoded bytes)")


def verify(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        packed, decoded, format_spec, ladder, archive = load_region(path, region)
        frames = audit(archive, region, format_spec, ladder)
        directory = source_dir(arguments.source_root, region)
        rebuilt = patched_decoded(
            archive,
            frames,
            directory,
            load_runtime_obj_palette(directory),
        )
        if rebuilt != decoded:
            raise AssertionError(f"{region}: unchanged PNG sources do not reproduce decoded retail bytes")
        output = directory / "archive.lz"
        if output.read_bytes() != packed:
            raise AssertionError(f"{region}: built archive differs from retail packed bytes")
    print("verified every regional indexed archive against retail bytes")


def edit_test(arguments: argparse.Namespace) -> None:
    archive = archive_from_data(arguments.source_archive.read_bytes())
    frames = audit(archive, arguments.region, "decoded source", "source-owned")
    source_directory = source_dir(arguments.source_root, arguments.region)
    original = (source_directory / "archive.original.lz").read_bytes()
    runtime_palette = load_runtime_obj_palette(source_directory)
    drawable = next(frame_id for frame_id in frames if frame_oam(archive, frame_id))
    with tempfile.TemporaryDirectory(prefix="fomt-indexed-archive-") as temporary:
        staged_root = Path(temporary) / "sources"
        shutil.copytree(arguments.source_root, staged_root)
        filename = frame_source(source_dir(staged_root, arguments.region), drawable)
        _expected_width, _expected_height, _baseline, _layers, bpp = rendered_frame(archive, drawable)
        pixels, width, height, colors = read_png(filename, bpp)
        index = next(index for index, value in enumerate(pixels) if value)
        edited = bytearray(pixels)
        edited[index] = (edited[index] % 15) + 1
        write_png(filename, bytes(edited), width, height, colors)
        source = patched_decoded(
            archive,
            frames,
            source_dir(staged_root, arguments.region),
            runtime_palette,
        )
        edited = Path(temporary) / "edited.bin"
        rebuilt_path = Path(temporary) / "archive.lz"
        edited.write_bytes(source)
        subprocess.run(
            [str(arguments.compressor), "rebuild-native", str(edited),
             str(source_directory / "archive.original.lz"), str(rebuilt_path)],
            check=True,
        )
        rebuilt = rebuilt_path.read_bytes()
        checked, _format_spec, _ladder = unpack(rebuilt)
        if bytes(checked) != source or rebuilt == original:
            raise AssertionError("native C compressor did not preserve the edited image")
    print(
        f"{arguments.region.upper()} indexed archive PNG edit test: frame {drawable:04d}, pixel {index:#x}; "
        f"packed {len(rebuilt):#x} bytes in a {len(original):#x}-byte slot"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-root", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build-decoded")
    build_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    build_parser.add_argument("--source-archive", type=Path, required=True)
    build_parser.add_argument("--source-root", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-root", type=Path, required=True)
    verify_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    edit_parser.add_argument("--source-archive", type=Path, required=True)
    edit_parser.add_argument("--compressor", type=Path, required=True)
    edit_parser.add_argument("--source-root", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "verify":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    elif arguments.command == "export":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build-decoded":
        build_decoded(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        raise AssertionError("unreachable")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Rebuild the four regional indexed OAM archives initialized by func_08000914.

The native archive has seven counted tables.  Its first table selects frames,
the second describes their OAM/tile/palette ranges, and its third through
fifth tables contain ordinary GBA OAM records, 4bpp tiles, and BGR555
palettes.  Geometry is always read from those tables: complete indexed PNG
frames are authoring inputs, and there is deliberately no JSON layout file.

JP, US/EU, and DE each retain their own source directory.  US and EU are
byte-identical; JP and DE have independently verified layouts and must not be
silently treated as a shared resource.
"""

from __future__ import annotations

import argparse
import hashlib
import shutil
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
    rendered_pixel_layers,
    selected_frame_ids,
)
from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff4_lz2, encode_huff8_lz2  # type: ignore[import-not-found]
from portrait_archive import (  # type: ignore[import-not-found]
    Archive,
    TABLE_STRIDES,
    assign_native_pixel,
    palette,
    read_png_indexed,
    read_u32,
    write_png_indexed,
)


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


def export_frames(archive: Archive, frames: list[int], directory: Path, replace: bool) -> None:
    written = 0
    preserved = 0
    for frame_id in frames:
        frame = frame_descriptor(archive, frame_id)
        if not frame_oam(archive, frame_id):
            continue
        width, height, indexes, _layers = rendered_pixel_layers(archive, frame_id)
        output = frame_source(directory, frame_id)
        expected = (width, height, indexes, palette(archive, frame.palette_id))
        if output.exists() and not replace:
            if read_png_indexed(output) != expected:
                raise ValueError(f"{output} differs from retail data; use --replace to overwrite it")
            preserved += 1
            continue
        write_png_indexed(output, *expected)
        written += 1
    print(f"exported {written} and preserved {preserved} OAM-composited frame PNG(s) in {directory / 'full'}")


def rebuild_tiles(archive: Archive, frames: list[int], directory: Path) -> bytes:
    tile_offset = archive.table_offsets[3]
    native = bytearray(archive.data[tile_offset:tile_offset + archive.counts[3] * 32])
    assignments: dict[tuple[int, int], int] = {}
    for frame_id in frames:
        frame = frame_descriptor(archive, frame_id)
        if not frame_oam(archive, frame_id):
            continue
        filename = frame_source(directory, frame_id)
        width, height, source_indexes, source_palette = read_png_indexed(filename)
        expected_width, expected_height, baseline, layers = rendered_pixel_layers(archive, frame_id)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != palette(archive, frame.palette_id):
            raise ValueError(f"{filename} has changed its native 16-colour palette")
        for target, value in enumerate(source_indexes):
            if value == baseline[target]:
                continue
            if not layers[target]:
                if value:
                    raise ValueError(f"{filename} draws outside frame {frame_id}'s OAM bounds")
                continue
            if value == 0:
                for tile_id, pixel_id in layers[target]:
                    assign_native_pixel(native, assignments, tile_id, pixel_id, 0)
            else:
                tile_id, pixel_id = layers[target][-1]
                assign_native_pixel(native, assignments, tile_id, pixel_id, value)
    return bytes(native)


def patched_decoded(archive: Archive, frames: list[int], directory: Path) -> bytes:
    result = bytearray(archive.data)
    tile_offset = archive.table_offsets[3]
    tiles = rebuild_tiles(archive, frames, directory)
    result[tile_offset:tile_offset + len(tiles)] = tiles
    return bytes(result)


def rebuild_stream(source: bytes, baseline: bytes, format_spec: str, ladder: str) -> bytes:
    original, original_format, original_ladder = unpack(baseline)
    if source == original:
        return baseline
    if format_spec == "120":
        encoded = encode_huff4_lz2(source, ladder)
    elif format_spec == "220":
        encoded = encode_huff8_lz2(source, ladder)
    else:
        raise AssertionError(f"unsupported indexed archive format {format_spec}")
    if len(encoded) > len(baseline):
        raise ValueError(
            f"edited archive needs {len(encoded):#x} bytes but its native slot holds {len(baseline):#x}"
        )
    result = encoded + bytes(len(baseline) - len(encoded))
    checked, checked_format, checked_ladder = unpack(result)
    if bytes(checked) != source or (checked_format, checked_ladder) != (original_format, original_ladder):
        raise AssertionError("rebuilt indexed archive failed strict native decode validation")
    return result


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path) for region, path in arguments.rom}
    if set(inputs) != set(REGIONS):
        raise ValueError("export requires jp, us, eu, and de ROMs")
    streams: dict[str, bytes] = {}
    for region in REGIONS:
        packed, _decoded, format_spec, ladder, archive = load_region(inputs[region], region)
        streams[region] = packed
        frames = audit(archive, region, format_spec, ladder)
        export_frames(archive, frames, source_dir(arguments.source_root, region), arguments.replace)
    if streams["us"] != streams["eu"]:
        raise AssertionError("US and EU indexed archives must remain byte-identical")
    print("verified US/EU shared archive bytes; JP and DE retain independent sources")


def build(arguments: argparse.Namespace) -> None:
    packed, _decoded, format_spec, ladder, archive = load_region(arguments.rom, arguments.region)
    frames = audit(archive, arguments.region, format_spec, ladder)
    source = patched_decoded(archive, frames, source_dir(arguments.source_root, arguments.region))
    rebuilt = rebuild_stream(source, packed, format_spec, ladder)
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(rebuilt)
    print(f"rebuilt {arguments.region.upper()} indexed archive ({len(rebuilt):#x} packed bytes)")


def verify(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        packed, _decoded, format_spec, ladder, archive = load_region(path, region)
        frames = audit(archive, region, format_spec, ladder)
        rebuilt = rebuild_stream(
            patched_decoded(archive, frames, source_dir(arguments.source_root, region)),
            packed,
            format_spec,
            ladder,
        )
        if rebuilt != packed:
            raise AssertionError(f"{region}: unchanged PNG sources do not reproduce retail packed bytes")
        original_rom = path.read_bytes()
        patched_rom = bytearray(original_rom)
        offset = REGIONS[region].offset
        patched_rom[offset:offset + len(rebuilt)] = rebuilt
        if patched_rom != original_rom:
            raise AssertionError(f"{region}: unchanged full-ROM patch differs from the retail input")
        if arguments.output_root is not None:
            output = arguments.output_root / region / "graphics" / "intro_scene" / "indexed_archive" / "archive.0x70"
            if output.read_bytes() != packed:
                raise AssertionError(f"{region}: built archive differs from retail packed bytes")
    print("verified every regional indexed archive and unchanged full-ROM patch")


def edit_test(arguments: argparse.Namespace) -> None:
    packed, _decoded, format_spec, ladder, archive = load_region(arguments.rom, arguments.region)
    frames = audit(archive, arguments.region, format_spec, ladder)
    drawable = next(frame_id for frame_id in frames if frame_oam(archive, frame_id))
    with tempfile.TemporaryDirectory(prefix="fomt-indexed-archive-") as temporary:
        staged_root = Path(temporary) / "sources"
        shutil.copytree(arguments.source_root, staged_root)
        filename = frame_source(source_dir(staged_root, arguments.region), drawable)
        width, height, pixels, colors = read_png_indexed(filename)
        index = next(index for index, value in enumerate(pixels) if value)
        edited = bytearray(pixels)
        edited[index] = (edited[index] % 15) + 1
        write_png_indexed(filename, width, height, bytes(edited), colors)
        source = patched_decoded(archive, frames, source_dir(staged_root, arguments.region))
    rebuilt = rebuild_stream(source, packed, format_spec, ladder)
    if rebuilt == packed:
        raise AssertionError("indexed archive edit did not change the packed stream")
    print(
        f"{arguments.region.upper()} indexed archive PNG edit test: frame {drawable:04d}, pixel {index:#x}; "
        f"packed {len(rebuilt):#x} bytes in a {len(packed):#x}-byte slot"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-root", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-root", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-root", type=Path, required=True)
    verify_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    verify_parser.add_argument("--output-root", type=Path)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    edit_parser.add_argument("--source-root", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "verify":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    elif arguments.command == "export":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        raise AssertionError("unreachable")


if __name__ == "__main__":
    main()

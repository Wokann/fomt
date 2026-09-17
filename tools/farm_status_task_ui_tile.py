#!/usr/bin/env python3
"""Build and verify the Farm Status Harvest Sprite task UI tile.

The retail menu uploads exactly one 8-by-8 4bpp tile to OBJ VRAM and its
adjacent 16-colour BGR555 record to OBJ palette RAM.  Because this pair is a
complete one-tile image, it can use a PNG source without inventing an OAM or
tilemap layout.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from tile_grid import (  # noqa: E402
    bgr555_from_colors,
    colors_from_bgr555,
    decode,
    encode,
    read_png,
    write_png,
)


TILE_LENGTH = 0x20
PALETTE_LENGTH = 0x20
OFFSETS = {
    "jp": (0x4D6BF8, 0x4D6C18),
    "us": (0x750C4C, 0x750C6C),
    "eu": (0x750CA8, 0x750CC8),
    "de": (0x4D8168, 0x4D8188),
}
TILE_SHA256 = "e98672a456687f9c428628c321ff964b8507028878310d4e3eaebd3cfbe37e49"
PALETTE_SHA256 = "9985d2bb7b07b88d53543f5ab323df57ac3eb3402671d800405dfdf4f9c18237"
SOURCE_NAME = "harvest_sprite_task_ui_tile.png"


def original_bytes(rom: bytes, region: str) -> tuple[bytes, bytes]:
    tile_offset, palette_offset = OFFSETS[region]
    tiles = rom[tile_offset:tile_offset + TILE_LENGTH]
    palette = rom[palette_offset:palette_offset + PALETTE_LENGTH]
    if len(tiles) != TILE_LENGTH or len(palette) != PALETTE_LENGTH:
        raise ValueError(f"{region} ROM ends within Farm Status task UI tile")
    if hashlib.sha256(tiles).hexdigest() != TILE_SHA256:
        raise ValueError(f"{region} task UI-tile hash mismatch")
    if hashlib.sha256(palette).hexdigest() != PALETTE_SHA256:
        raise ValueError(f"{region} task UI-tile palette hash mismatch")
    return tiles, palette


def source_path(directory: Path) -> Path:
    return directory / SOURCE_NAME


def export(arguments: argparse.Namespace) -> None:
    output = source_path(arguments.output_dir)
    if output.exists() and not arguments.replace:
        raise ValueError(f"{output} exists; pass --replace to overwrite it")
    tiles, palette = original_bytes(arguments.rom.read_bytes(), arguments.region)
    pixels, height = decode(tiles, 8, 4)
    if height != 8:
        raise ValueError("task UI-tile bounds do not describe an 8x8 tile")
    write_png(output, pixels, 8, 8, colors_from_bgr555(palette, 4))
    print(f"exported verified Farm Status task UI tile to {output}")


def build_source(source: Path) -> tuple[bytes, bytes]:
    pixels, width, height, colors = read_png(source, 4)
    if (width, height) != (8, 8):
        raise ValueError(f"{source} must remain an 8x8 indexed 4bpp PNG")
    return encode(pixels, width, height, 4), bgr555_from_colors(colors, 4)


def build(arguments: argparse.Namespace) -> None:
    tiles, palette = build_source(source_path(arguments.source_dir))
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / "harvest_sprite_task_ui_tile.4bpp").write_bytes(tiles)
    (arguments.output_dir / "harvest_sprite_task_ui_tile.gbapal").write_bytes(palette)
    print(f"rebuilt Farm Status task UI tile in {arguments.output_dir}")


def verify(arguments: argparse.Namespace) -> None:
    tiles, palette = build_source(source_path(arguments.source_dir))
    for region, path in arguments.rom:
        original_tiles, original_palette = original_bytes(path.read_bytes(), region)
        if tiles != original_tiles or palette != original_palette:
            raise ValueError(f"{region} Farm Status task UI tile does not round-trip")
    print(f"Farm Status task UI tile matches {len(arguments.rom)} regional ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", type=Path, required=True)
    export_parser.add_argument("--region", choices=tuple(OFFSETS), required=True)
    export_parser.add_argument("--output-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--rom", action="append", nargs=2, metavar=("REGION", "ROM"), required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    else:
        regions = [region for region, _ in arguments.rom]
        if len(set(regions)) != len(regions) or any(region not in OFFSETS for region in regions):
            raise ValueError("each --rom region must be one known, unique region")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        verify(arguments)


if __name__ == "__main__":
    main()

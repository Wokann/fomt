#!/usr/bin/env python3
"""Export, rebuild, and verify the Records Screen's seven task icons.

Each entry is a directly loaded 16-by-16 4bpp tile grid followed by its own
16-colour BGR555 palette.  The physical order here is the ROM order.  The C++
records-screen table chooses its own presentation order through pointers, so
this tool deliberately does not invent a second layout or table description.
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


RESOURCE_COUNT = 7
TILE_LENGTH = 0x80
PALETTE_LENGTH = 0x20
STRIDE = TILE_LENGTH + PALETTE_LENGTH
REGION_BASE_OFFSETS = {
    "jp": 0x4D7EB8,
    "us": 0x751F0C,
    "eu": 0x751F68,
    "de": 0x4D9428,
}
TILE_SHA256 = (
    "71378c2cfeb8b0b3b8609fe8b05a6a28a6b365dc6e69d92380d8cafdb20421fd",
    "594cc1815366f372da6526c73bb450440b200dbebcb656b96cdc5d3f0d9cda20",
    "ce71e0264877e4c91323022582583eb425433ebb2655ebfe2f42f38edf16dc35",
    "1f801982bd010577f6ed3ef40b90990811ac069d4684bbacf954a56105be5ca0",
    "d3aa779b36066d8c2bc71d47d72c5b9f61584a0d213af7d9d226d77a33c1bda2",
    "629efc82328f202e280b6766657397f15aa11fef28020a8c0ffd94c7bd42cde0",
    "79a4b02dfd169f3a12d21aa404d1750aa05cb6c0a155628977cfcb4e0c43745f",
)
PALETTE_SHA256 = (
    "177698b73af8992b354aa70c6aa8bdf4f9fffefcaea2b7d42a6dbffbe2ebce04",
    "11aaf8eb28533ed3e9c8562e57377d6b18dee82cceb74fb75dc5e8bfe648d448",
    "11aaf8eb28533ed3e9c8562e57377d6b18dee82cceb74fb75dc5e8bfe648d448",
    "177698b73af8992b354aa70c6aa8bdf4f9fffefcaea2b7d42a6dbffbe2ebce04",
    "177698b73af8992b354aa70c6aa8bdf4f9fffefcaea2b7d42a6dbffbe2ebce04",
    "11aaf8eb28533ed3e9c8562e57377d6b18dee82cceb74fb75dc5e8bfe648d448",
    "8ccfa81508cf1d41de4b21b2a7e7978e38053a2ac5d86683dcc5a0d0b88571a2",
)


def resource_bytes(rom: bytes, region: str, index: int) -> tuple[bytes, bytes]:
    offset = REGION_BASE_OFFSETS[region] + index * STRIDE
    tiles = rom[offset:offset + TILE_LENGTH]
    palette = rom[offset + TILE_LENGTH:offset + STRIDE]
    if len(tiles) != TILE_LENGTH or len(palette) != PALETTE_LENGTH:
        raise ValueError(f"{region} ROM ends within task icon {index:02d}")
    if hashlib.sha256(tiles).hexdigest() != TILE_SHA256[index]:
        raise ValueError(f"{region} task icon {index:02d} tile hash mismatch")
    if hashlib.sha256(palette).hexdigest() != PALETTE_SHA256[index]:
        raise ValueError(f"{region} task icon {index:02d} palette hash mismatch")
    return tiles, palette


def source_path(directory: Path, index: int) -> Path:
    return directory / f"task_{index:02d}.png"


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for index in range(RESOURCE_COUNT):
        output = source_path(arguments.output_dir, index)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; pass --replace to overwrite it")
        tiles, palette = resource_bytes(rom, arguments.region, index)
        pixels, height = decode(tiles, 16, 4)
        if height != 16:
            raise ValueError("task icon tile bounds do not describe 16x16 pixels")
        write_png(output, pixels, 16, 16, colors_from_bgr555(palette, 4))
    print(f"exported {RESOURCE_COUNT} verified Records Screen task icons to {arguments.output_dir}")


def build_icon(source: Path) -> tuple[bytes, bytes]:
    pixels, width, height, colors = read_png(source, 4)
    if (width, height) != (16, 16):
        raise ValueError(f"{source} must remain a 16x16 indexed 4bpp PNG")
    return encode(pixels, width, height, 4), bgr555_from_colors(colors, 4)


def build(arguments: argparse.Namespace) -> None:
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for index in range(RESOURCE_COUNT):
        tiles, palette = build_icon(source_path(arguments.source_dir, index))
        (arguments.output_dir / f"task_{index:02d}.4bpp").write_bytes(tiles)
        (arguments.output_dir / f"task_{index:02d}.gbapal").write_bytes(palette)
    print(f"rebuilt {RESOURCE_COUNT} Records Screen task icons in {arguments.output_dir}")


def verify(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    for index in range(RESOURCE_COUNT):
        tiles, palette = build_icon(source_path(arguments.source_dir, index))
        for region, rom in roms.items():
            original_tiles, original_palette = resource_bytes(rom, region, index)
            if tiles != original_tiles or palette != original_palette:
                raise ValueError(f"{region} task icon {index:02d} does not round-trip")
    print(f"all {RESOURCE_COUNT} Records Screen task icons match {len(roms)} regional ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", type=Path, required=True)
    export_parser.add_argument("--region", choices=tuple(REGION_BASE_OFFSETS), required=True)
    export_parser.add_argument("--output-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--rom", action="append", nargs=2, metavar=("REGION", "ROM"), required=True,
                               help="one or more REGION ROM pairs")
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    else:
        regions = [region for region, _ in arguments.rom]
        if len(set(regions)) != len(regions) or any(region not in REGION_BASE_OFFSETS for region in regions):
            raise ValueError("each --rom region must be one known, unique region")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        verify(arguments)


if __name__ == "__main__":
    main()

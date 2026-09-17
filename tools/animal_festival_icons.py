#!/usr/bin/env python3
"""Losslessly manage the ten shared Animal Festival 16-by-16 icons.

Each native record is a linear 4bpp tile grid followed immediately by its
own 16-colour BGR555 palette.  The records are byte-identical in JP, US, EU
and DE.  Their neutral physical order is retained: runtime call sites choose
the records independently, so this tool does not invent a second layout.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from tile_grid import bgr555_from_colors, colors_from_bgr555, decode, encode, read_png, write_png  # noqa: E402


COUNT = 10
TILE_LENGTH = 0x80
PALETTE_LENGTH = 0x20
STRIDE = TILE_LENGTH + PALETTE_LENGTH
LENGTH = COUNT * STRIDE
OFFSETS = {"jp": 0x4D7878, "us": 0x7518CC, "eu": 0x751928, "de": 0x4D8DE8}
SHA256 = "38ffc2dc46e7d720773ca0ee78e7329bceaced0848a8f4c123cdb7a7a97739af"


def retail(rom: bytes, region: str) -> bytes:
    data = rom[OFFSETS[region]:OFFSETS[region] + LENGTH]
    if len(data) != LENGTH or hashlib.sha256(data).hexdigest() != SHA256:
        raise ValueError(f"{region}: Animal Festival icon archive does not match its verified range")
    return data


def source(directory: Path, index: int) -> Path:
    return directory / f"icon_{index:02d}.png"


def icon(data: bytes, index: int) -> tuple[bytes, bytes]:
    start = index * STRIDE
    return data[start:start + TILE_LENGTH], data[start + TILE_LENGTH:start + STRIDE]


def export(args: argparse.Namespace) -> None:
    data = retail(args.rom.read_bytes(), args.region)
    for index in range(COUNT):
        output = source(args.output_dir, index)
        if output.exists() and not args.replace:
            raise ValueError(f"{output} exists; pass --replace to overwrite it")
        tiles, palette = icon(data, index)
        pixels, height = decode(tiles, 16, 4)
        if height != 16:
            raise AssertionError("unexpected icon geometry")
        write_png(output, pixels, 16, 16, colors_from_bgr555(palette, 4))


def build_icon(path: Path) -> tuple[bytes, bytes]:
    pixels, width, height, colors = read_png(path, 4)
    if (width, height) != (16, 16):
        raise ValueError(f"{path} must remain a 16x16 indexed 4bpp PNG")
    return encode(pixels, width, height, 4), bgr555_from_colors(colors, 4)


def build(args: argparse.Namespace) -> None:
    args.output_dir.mkdir(parents=True, exist_ok=True)
    for index in range(COUNT):
        tiles, palette = build_icon(source(args.source_dir, index))
        (args.output_dir / f"icon_{index:02d}.4bpp").write_bytes(tiles)
        (args.output_dir / f"icon_{index:02d}.gbapal").write_bytes(palette)


def verify(args: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in args.rom}
    for region, rom in roms.items():
        retail(rom, region)
    for index in range(COUNT):
        expected = b"".join(build_icon(source(args.source_dir, index)))
        for region, rom in roms.items():
            if expected != retail(rom, region)[index * STRIDE:(index + 1) * STRIDE]:
                raise ValueError(f"{region}: Animal Festival icon {index:02d} does not round-trip")
    print(f"all {COUNT} Animal Festival icons match {len(roms)} regional ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    command = commands.add_parser("export")
    command.add_argument("--rom", type=Path, required=True)
    command.add_argument("--region", choices=tuple(OFFSETS), required=True)
    command.add_argument("--output-dir", type=Path, required=True)
    command.add_argument("--replace", action="store_true")
    command = commands.add_parser("build")
    command.add_argument("--source-dir", type=Path, required=True)
    command.add_argument("--output-dir", type=Path, required=True)
    command = commands.add_parser("verify")
    command.add_argument("--source-dir", type=Path, required=True)
    command.add_argument("--rom", action="append", nargs=2, metavar=("REGION", "ROM"), required=True)
    args = parser.parse_args()
    if args.command == "export":
        export(args)
    elif args.command == "build":
        build(args)
    else:
        if len({region for region, _path in args.rom}) != len(args.rom) or any(region not in OFFSETS for region, _path in args.rom):
            raise ValueError("supply each known region exactly once")
        args.rom = [(region, Path(path)) for region, path in args.rom]
        verify(args)


if __name__ == "__main__":
    main()

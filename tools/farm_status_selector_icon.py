#!/usr/bin/env python3
"""Losslessly manage Farm Status' independently selected case-09 icon.

The UI resource selector in func_08060FD8 associates selector case 9 with a
16-by-16 4bpp tile record and its following 16-colour BGR555 palette.  This
is deliberately named after the proven selector case, rather than assigning
an unverified gameplay or character name to the icon.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from tile_grid import bgr555_from_colors, colors_from_bgr555, decode, encode, read_png, write_png  # noqa: E402


TILE_LENGTH = 0x80
PALETTE_LENGTH = 0x20
TILE_SHA256 = "a7c75b890d8167dec85b5aa76645fe9f4b5685963fb82b3e70bbb26b93df1e19"
PALETTE_SHA256 = "366e7449453ed4cee3ca5346b7e2001cfbb60cd138519b8cc5c24eb153eabf37"
OFFSETS = {
    "jp": (0x4D8DF8, 0x4D8E78),
    "us": (0x752E4C, 0x752ECC),
    "eu": (0x752EA8, 0x752F28),
    "de": (0x4DA368, 0x4DA3E8),
}


def read_records(rom: bytes, region: str) -> tuple[bytes, bytes]:
    tile_offset, palette_offset = OFFSETS[region]
    tiles = rom[tile_offset:tile_offset + TILE_LENGTH]
    palette = rom[palette_offset:palette_offset + PALETTE_LENGTH]
    if hashlib.sha256(tiles).hexdigest() != TILE_SHA256:
        raise ValueError(f"{region}: selector case-09 tile record does not match its verified range")
    if hashlib.sha256(palette).hexdigest() != PALETTE_SHA256:
        raise ValueError(f"{region}: selector case-09 palette record does not match its verified range")
    return tiles, palette


def build_source(path: Path) -> tuple[bytes, bytes]:
    pixels, width, height, colors = read_png(path, 4)
    if (width, height) != (16, 16):
        raise ValueError(f"{path} must remain a 16x16 indexed 4bpp PNG")
    return encode(pixels, width, height, 4), bgr555_from_colors(colors, 4)


def export(args: argparse.Namespace) -> None:
    if args.output.exists() and not args.replace:
        raise ValueError(f"{args.output} exists; pass --replace to overwrite it")
    tiles, palette = read_records(args.rom.read_bytes(), args.region)
    pixels, height = decode(tiles, 16, 4)
    if height != 16:
        raise AssertionError("unexpected selector icon geometry")
    write_png(args.output, pixels, 16, 16, colors_from_bgr555(palette, 4))


def build(args: argparse.Namespace) -> None:
    tiles, palette = build_source(args.source)
    args.output_dir.mkdir(parents=True, exist_ok=True)
    (args.output_dir / "selector_case_09.4bpp").write_bytes(tiles)
    (args.output_dir / "selector_case_09.gbapal").write_bytes(palette)


def verify(args: argparse.Namespace) -> None:
    expected = b"".join(build_source(args.source))
    for region, path in args.rom:
        if region not in OFFSETS:
            raise ValueError(f"unknown region: {region}")
        if expected != b"".join(read_records(path.read_bytes(), region)):
            raise ValueError(f"{region}: selector case-09 icon does not round-trip")
    print(f"Farm Status selector case-09 icon matches {len(args.rom)} regional ROMs")


def edit_test(args: argparse.Namespace) -> None:
    pixels, width, height, colors = read_png(args.source, 4)
    if (width, height) != (16, 16):
        raise ValueError(f"{args.source} must remain a 16x16 indexed 4bpp PNG")
    changed = list(pixels)
    changed[0] = (changed[0] + 1) % 16
    tiles = encode(changed, width, height, 4)
    palette = bgr555_from_colors(colors, 4)
    if len(tiles) != TILE_LENGTH or len(palette) != PALETTE_LENGTH:
        raise AssertionError("a selector icon edit changed its fixed native record size")
    decoded, decoded_height = decode(tiles, 16, 4)
    if decoded_height != 16 or decoded != bytes(changed):
        raise AssertionError("a selector icon edit failed its native 4bpp round-trip")
    print("Farm Status selector case-09 one-pixel edit keeps the fixed native record sizes")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", type=Path, required=True)
    export_parser.add_argument("--region", choices=OFFSETS, required=True)
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source", type=Path, required=True)
    verify_parser.add_argument("--rom", action="append", nargs=2, metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--source", type=Path, required=True)
    args = parser.parse_args()
    if args.command == "export":
        export(args)
    elif args.command == "build":
        build(args)
    elif args.command == "verify":
        args.rom = [(region, Path(path)) for region, path in args.rom]
        if len({region for region, _path in args.rom}) != len(args.rom):
            raise ValueError("supply each region at most once")
        verify(args)
    else:
        edit_test(args)


if __name__ == "__main__":
    main()

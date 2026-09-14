#!/usr/bin/env python3
"""Round-trip a 16-bank GBA 4bpp BGR555 palette through one indexed PNG."""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import bgr555_from_colors, colors_from_bgr555, read_png, write_png


WIDTH = 256
HEIGHT = 8


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    palette = rom[arguments.offset:arguments.offset + 0x200]
    if len(palette) != 0x200:
        raise ValueError("ROM ends before the requested 16-bank palette")
    if hashlib.sha256(palette).hexdigest().lower() != arguments.sha256.lower():
        raise ValueError("palette range hash mismatch; refusing to export an unverified palette")
    if arguments.output.exists() and not arguments.replace:
        raise ValueError(f"{arguments.output} exists; pass --replace to overwrite it")
    indexes = bytes(range(WIDTH)) * HEIGHT
    write_png(arguments.output, indexes, WIDTH, HEIGHT, colors_from_bgr555(palette, 8))
    print(f"exported verified 16-bank palette to {arguments.output}")


def build(arguments: argparse.Namespace) -> None:
    indexes, width, height, colors = read_png(arguments.source, 8)
    if (width, height) != (WIDTH, HEIGHT) or indexes != bytes(range(WIDTH)) * HEIGHT:
        raise ValueError(
            f"{arguments.source} must be a {WIDTH}x{HEIGHT} palette-swatch PNG; "
            "each row must contain indices 0 through 255 in order"
        )
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(bgr555_from_colors(colors, 8))
    print(f"rebuilt 16-bank palette to {arguments.output}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("rom", type=Path)
    export_parser.add_argument("--offset", type=lambda value: int(value, 0), required=True)
    export_parser.add_argument("--sha256", required=True)
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    else:
        build(arguments)


if __name__ == "__main__":
    main()

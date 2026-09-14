#!/usr/bin/env python3
"""Round-trip one to sixteen GBA 4bpp BGR555 palette banks through an indexed PNG."""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import bgr555_from_colors, colors_from_bgr555, read_png, write_png


HEIGHT = 8


def dimensions(banks: int) -> tuple[int, int]:
    if not 1 <= banks <= 16:
        raise ValueError("the palette source must contain from one to sixteen 4bpp banks")
    return banks * 16, HEIGHT


def export(arguments: argparse.Namespace) -> None:
    width, height = dimensions(arguments.banks)
    rom = arguments.rom.read_bytes()
    palette = rom[arguments.offset:arguments.offset + width * 2]
    if len(palette) != width * 2:
        raise ValueError("ROM ends before the requested palette-bank range")
    if hashlib.sha256(palette).hexdigest().lower() != arguments.sha256.lower():
        raise ValueError("palette range hash mismatch; refusing to export an unverified palette")
    if arguments.output.exists() and not arguments.replace:
        raise ValueError(f"{arguments.output} exists; pass --replace to overwrite it")
    indexes = bytes(range(width)) * height
    write_png(arguments.output, indexes, width, height, colors_from_bgr555(palette, color_count=width))
    print(f"exported verified {arguments.banks}-bank palette to {arguments.output}")


def build(arguments: argparse.Namespace) -> None:
    width, height = dimensions(arguments.banks)
    indexes, source_width, source_height, colors = read_png(arguments.source, color_count=width)
    if (source_width, source_height) != (width, height) or indexes != bytes(range(width)) * height:
        raise ValueError(
            f"{arguments.source} must be a {width}x{height} palette-swatch PNG; "
            f"each row must contain indices 0 through {width - 1} in order"
        )
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(bgr555_from_colors(colors, color_count=width))
    print(f"rebuilt {arguments.banks}-bank palette to {arguments.output}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("rom", type=Path)
    export_parser.add_argument("--offset", type=lambda value: int(value, 0), required=True)
    export_parser.add_argument("--banks", type=int, default=16)
    export_parser.add_argument("--sha256", required=True)
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--banks", type=int, default=16)
    build_parser.add_argument("--output", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    else:
        build(arguments)


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Rebuild a verified FoMT graphics source PNG from a retail ROM.

The command line names the physical ROM interval and verified source hash.
This keeps the authored PNG workflow file-based: no JSON manifest is used to
map an image onto a ROM range.
"""

from __future__ import annotations

import argparse
import hashlib
import subprocess
import sys
import tempfile
from pathlib import Path


def parse_number(value: str) -> int:
    return int(value, 0)


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def command(arguments: list[str]) -> None:
    print("+", " ".join(arguments))
    subprocess.run(arguments, check=True)


def extract_font_1bpp(args: argparse.Namespace) -> None:
    offset = parse_number(args.offset)
    length = parse_number(args.length)
    rom = Path(args.rom)
    with rom.open("rb") as handle:
        handle.seek(offset)
        native = handle.read(length)
    if len(native) != length:
        raise ValueError(f"ROM ends before the declared interval at 0x{offset:X}")
    actual_hash = digest(native)
    expected_hash = args.sha256.lower()
    if actual_hash != expected_hash:
        raise ValueError(
            "ROM interval hash mismatch: expected "
            f"{expected_hash}, got {actual_hash}; refusing to export a different asset"
        )

    glyph_count = args.glyph_count
    record_bytes = 12 if args.glyph_width == 8 else 24
    if glyph_count * record_bytes != length:
        raise ValueError("glyph count and record size do not cover the declared ROM interval")

    output = Path(args.output).resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="fomt-gfx-") as temporary:
        temporary_path = Path(temporary)
        native_path = temporary_path / "font.native.1bpp"
        padded_path = temporary_path / "font.1bpp"
        native_path.write_bytes(native)
        if args.glyph_width == 8:
            pack_command = "pack-grid-12-to-16"
            png_tile_width = args.grid_columns
        else:
            pack_command = "pack-grid-16x12-to-16x16"
            png_tile_width = args.grid_columns * 2
        command([
            str(Path(args.fontpad)), pack_command, str(native_path),
            str(padded_path), str(args.grid_columns),
        ])
        command([
            str(Path(args.gbagfx)), str(padded_path), str(output),
            "-width", str(png_tile_width),
        ])

    print(f"exported verified font source to {output}")
    print(f"verified source SHA-256: {actual_hash}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="format", required=True)
    font = subparsers.add_parser("font-1bpp", help="export a verified regional 1bpp font")
    font.add_argument("--rom", required=True, help="retail ROM containing the declared interval")
    font.add_argument("--offset", required=True, help="font ROM offset, for example 0x7515A8")
    font.add_argument("--length", required=True, help="font byte length, for example 0x16D4")
    font.add_argument("--sha256", required=True, help="expected source SHA-256")
    font.add_argument("--glyph-count", required=True, type=int, help="number of native 8x12 or 16x12 glyphs")
    font.add_argument("--glyph-width", required=True, type=int, choices=(8, 16), help="native glyph width")
    font.add_argument("--grid-columns", required=True, type=int, help="glyph columns in the source PNG")
    font.add_argument("--gbagfx", required=True, help="path to the built gbagfx executable")
    font.add_argument("--fontpad", required=True, help="path to the built fontpad executable")
    font.add_argument("--output", required=True, help="output indexed PNG path")
    args = parser.parse_args()

    try:
        if args.format == "font-1bpp":
            extract_font_1bpp(args)
            return 0
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        print(f"extract_gfx: {error}", file=sys.stderr)
        return 1
    raise AssertionError("unreachable")


if __name__ == "__main__":
    raise SystemExit(main())

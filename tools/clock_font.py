#!/usr/bin/env python3
"""Losslessly manage the overseas direct-copy clock/calendar glyph records.

The overseas UI copies each glyph as an independent 0x20-byte 4bpp record.
The renderer palette has not yet been bounded, so the indexed PNG uses an
editor-only index palette.  It preserves every native pixel index but makes
no claim about the game's on-screen colours.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from tile_grid import decode, encode, read_png, write_png  # noqa: E402


GLYPH_BYTES = 0x20
GLYPH_COUNT = 128
GLYPH_DATA_BYTES = GLYPH_BYTES * GLYPH_COUNT
TAIL_BYTES = 4
GRID_COLUMNS = 16
GRID_WIDTH = GRID_COLUMNS * 8
GRID_HEIGHT = (GLYPH_COUNT // GRID_COLUMNS) * 8
INDEX_COLORS = tuple((index * 17, index * 17, index * 17, 255) for index in range(16))
RECORDS = {
    "us": (0x75A440, "c5ae19339aeaedfcb4715e284f0ddc125d10b30c9c5b4eb27509bbf0225357cd"),
    "eu": (0x75A49C, "c5ae19339aeaedfcb4715e284f0ddc125d10b30c9c5b4eb27509bbf0225357cd"),
    "de": (0x4E195C, "b52c700aa1600e3129485328e42f4beeadd230dd69ce0b4ea90e9cbb57052256"),
}
TAIL_SHA256 = "10a4ac7a3bbd1bc41e0d48c9683c7ccdc7bbf2e313f001d85b21aeafcbb48e8c"


def native_record(rom: bytes, region: str) -> tuple[bytes, bytes]:
    offset, expected_hash = RECORDS[region]
    record = rom[offset:offset + GLYPH_DATA_BYTES + TAIL_BYTES]
    if len(record) != GLYPH_DATA_BYTES + TAIL_BYTES or hashlib.sha256(record).hexdigest() != expected_hash:
        raise ValueError(f"{region}: clock-font record does not match its verified range")
    return record[:GLYPH_DATA_BYTES], record[GLYPH_DATA_BYTES:]


def grid_from_native(native: bytes) -> bytes:
    pixels = bytearray(GRID_WIDTH * GRID_HEIGHT)
    for glyph in range(GLYPH_COUNT):
        tile, height = decode(native[glyph * GLYPH_BYTES:(glyph + 1) * GLYPH_BYTES], 8, 4)
        if height != 8:
            raise AssertionError("clock-font glyph is not an 8x8 4bpp tile")
        x, y = glyph % GRID_COLUMNS * 8, glyph // GRID_COLUMNS * 8
        for row in range(8):
            pixels[(y + row) * GRID_WIDTH + x:(y + row) * GRID_WIDTH + x + 8] = tile[row * 8:(row + 1) * 8]
    return bytes(pixels)


def native_from_grid(path: Path) -> bytes:
    pixels, width, height, _colors = read_png(path, 4)
    if (width, height) != (GRID_WIDTH, GRID_HEIGHT):
        raise ValueError(f"{path} must remain a {GRID_WIDTH}x{GRID_HEIGHT} indexed 4bpp glyph grid")
    native = bytearray()
    for glyph in range(GLYPH_COUNT):
        x, y = glyph % GRID_COLUMNS * 8, glyph // GRID_COLUMNS * 8
        tile = b"".join(pixels[(y + row) * width + x:(y + row) * width + x + 8] for row in range(8))
        native.extend(encode(tile, 8, 8, 4))
    return bytes(native)


def export(args: argparse.Namespace) -> None:
    if args.output.exists() and not args.replace:
        raise ValueError(f"{args.output} exists; pass --replace to overwrite it")
    native, tail = native_record(args.rom.read_bytes(), args.region)
    write_png(args.output, grid_from_native(native), GRID_WIDTH, GRID_HEIGHT, INDEX_COLORS)
    args.tail.parent.mkdir(parents=True, exist_ok=True)
    args.tail.write_bytes(tail)


def build(args: argparse.Namespace) -> None:
    tail = args.tail.read_bytes()
    if len(tail) != TAIL_BYTES or hashlib.sha256(tail).hexdigest() != TAIL_SHA256:
        raise ValueError("clock-font tail does not match the verified four-byte native record")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(native_from_grid(args.source) + tail)


def verify(args: argparse.Namespace) -> None:
    expected_tail = args.tail.read_bytes()
    built = {region: path for region, path in args.built}
    for region, path, source in args.rom:
        native, tail = native_record(path.read_bytes(), region)
        if native_from_grid(source) != native or expected_tail != tail:
            raise ValueError(f"{region}: clock-font source does not round-trip")
        if region in built and built[region].read_bytes() != native + tail:
            raise ValueError(f"{region}: built clock-font record does not match its verified ROM range")
    print(f"clock-font glyph sources match {len(args.rom)} regional ROMs")


def edit_test(args: argparse.Namespace) -> None:
    pixels, width, height, _colors = read_png(args.source, 4)
    changed = bytearray(pixels)
    changed[0] = (changed[0] + 1) % 16
    temporary = args.source.with_suffix(".edit-test.png")
    try:
        write_png(temporary, bytes(changed), width, height, INDEX_COLORS)
        native = native_from_grid(temporary)
    finally:
        temporary.unlink(missing_ok=True)
    if len(native) != GLYPH_DATA_BYTES or grid_from_native(native) != bytes(changed):
        raise AssertionError("clock-font glyph edit failed the fixed native 4bpp round-trip")
    print("clock-font one-pixel edit keeps the fixed 0x1000-byte glyph payload")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", type=Path, required=True)
    export_parser.add_argument("--region", choices=RECORDS, required=True)
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--tail", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--tail", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--tail", type=Path, required=True)
    verify_parser.add_argument("--rom", action="append", nargs=3, metavar=("REGION", "ROM", "SOURCE"), required=True)
    verify_parser.add_argument("--built", action="append", nargs=2, metavar=("REGION", "OUTPUT"), default=[])
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--source", type=Path, required=True)
    args = parser.parse_args()
    if args.command == "export":
        export(args)
    elif args.command == "build":
        build(args)
    elif args.command == "verify":
        args.rom = [(region, Path(rom), Path(source)) for region, rom, source in args.rom]
        args.built = [(region, Path(output)) for region, output in args.built]
        if len({region for region, _rom, _source in args.rom}) != len(args.rom):
            raise ValueError("supply each region at most once")
        if len({region for region, _output in args.built}) != len(args.built):
            raise ValueError("supply each built output at most once")
        verify(args)
    else:
        edit_test(args)


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Losslessly manage twenty shared 16-by-16 Farm Status UI icon records.

Every native record is a linear 4bpp tile grid immediately followed by its
own 16-colour BGR555 palette.  The records are byte-identical in JP, US, EU,
and DE.  Their physical order is retained because runtime callers select the
individual original labels rather than an authored presentation table.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from tile_grid import bgr555_from_colors, colors_from_bgr555, decode, encode, read_png, write_png  # noqa: E402


COUNT = 20
TILE_LENGTH = 0x80
PALETTE_LENGTH = 0x20
STRIDE = TILE_LENGTH + PALETTE_LENGTH
GROUP_LENGTH = 10 * STRIDE
GROUPS = (
    (0, {"jp": 0x4D8318, "us": 0x75236C, "eu": 0x7523C8, "de": 0x4D9888},
     "7095571e9e9b0ca2ba0ae87e9f0f9cc2d2f74bd674e76f78f4ed770809ed6ae8"),
    (10, {"jp": 0x4D8E98, "us": 0x752EEC, "eu": 0x752F48, "de": 0x4DA408},
     "3f3af3b3491fb338cbc6003a73453e03454b47a374a61b15a4eb09f974be6bb5"),
)
REGIONS = tuple(GROUPS[0][1])


def archive(rom: bytes, region: str, group: tuple[int, dict[str, int], str]) -> bytes:
    _first, offsets, expected_hash = group
    data = rom[offsets[region]:offsets[region] + GROUP_LENGTH]
    if len(data) != GROUP_LENGTH or hashlib.sha256(data).hexdigest() != expected_hash:
        raise ValueError(f"{region}: Farm Status UI icon group does not match its verified range")
    return data


def archives(rom: bytes, region: str) -> tuple[bytes, ...]:
    return tuple(archive(rom, region, group) for group in GROUPS)


def source(directory: Path, index: int) -> Path:
    return directory / f"icon_{index:02d}.png"


def icon(group_data: tuple[bytes, ...], index: int) -> tuple[bytes, bytes]:
    group_index, local_index = divmod(index, 10)
    data = group_data[group_index]
    start = local_index * STRIDE
    return data[start:start + TILE_LENGTH], data[start + TILE_LENGTH:start + STRIDE]


def export(args: argparse.Namespace) -> None:
    data = archives(args.rom.read_bytes(), args.region)
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
    retail = {region: archives(rom, region) for region, rom in roms.items()}
    for index in range(COUNT):
        expected = b"".join(build_icon(source(args.source_dir, index)))
        for region, rom in roms.items():
            if expected != b"".join(icon(retail[region], index)):
                raise ValueError(f"{region}: Farm Status UI icon {index:02d} does not round-trip")
    print(f"all {COUNT} Farm Status UI icon records match {len(roms)} regional ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    command = commands.add_parser("export")
    command.add_argument("--rom", type=Path, required=True)
    command.add_argument("--region", choices=REGIONS, required=True)
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
        if len({region for region, _path in args.rom}) != len(args.rom) or any(region not in REGIONS for region, _path in args.rom):
            raise ValueError("supply each known region exactly once")
        args.rom = [(region, Path(path)) for region, path in args.rom]
        verify(args)


if __name__ == "__main__":
    main()

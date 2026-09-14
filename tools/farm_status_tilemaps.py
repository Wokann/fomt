#!/usr/bin/env python3
"""Manage the Farm Status building-preview BG tilemaps without sidecars.

The preview images are composed from the editable Farm Status tile grid,
palette banks, and these native two-byte BG map entries.  A rendered PNG is
useful reference material, but it cannot uniquely preserve tile IDs, flip
bits, or palette-bank bits.  The checked-in ``.tilemap`` files are therefore
the authoritative editable layout source and are rebuilt verbatim.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from farm_status_previews import PREVIEWS, map_bytes  # noqa: E402


VARIANTS = ("primary", "alternate")


def source_path(directory: Path, preview_name: str, variant: str) -> Path:
    return directory / f"{preview_name}_{variant}.tilemap"


def expected_length(preview) -> int:
    return preview.width_tiles * preview.height_tiles * 2


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for preview in PREVIEWS:
        for variant, suffix in enumerate(VARIANTS):
            output = source_path(arguments.output_dir, preview.name, suffix)
            if output.exists() and not arguments.replace:
                raise ValueError(f"{output} exists; pass --replace to overwrite it")
            output.write_bytes(map_bytes(rom, preview, variant, arguments.region))
    print(f"exported {len(PREVIEWS) * len(VARIANTS)} Farm Status preview tilemaps to {arguments.output_dir}")


def build(arguments: argparse.Namespace) -> None:
    bundle = bytearray()
    for preview in PREVIEWS:
        for suffix in VARIANTS:
            source = source_path(arguments.source_dir, preview.name, suffix)
            data = source.read_bytes()
            if len(data) != expected_length(preview):
                raise ValueError(f"{source} must be exactly {expected_length(preview):#x} bytes")
            bundle.extend(data)
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(bundle)
    print(f"rebuilt {len(PREVIEWS) * len(VARIANTS)} Farm Status preview tilemaps into {arguments.output}")


def verify(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    for preview in PREVIEWS:
        for variant, suffix in enumerate(VARIANTS):
            source = source_path(arguments.source_dir, preview.name, suffix)
            data = source.read_bytes()
            if len(data) != expected_length(preview):
                raise ValueError(f"{source} must be exactly {expected_length(preview):#x} bytes")
            for region, rom in roms.items():
                if data != map_bytes(rom, preview, variant, region):
                    raise ValueError(f"{source.name} does not match the {region} ROM")
    print(f"all {len(PREVIEWS) * len(VARIANTS)} Farm Status tilemaps match {len(roms)} regional ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", type=Path, required=True)
    export_parser.add_argument("--region", choices=("jp", "us", "eu", "de"), required=True)
    export_parser.add_argument("--output-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--rom", action="append", nargs=2, metavar=("REGION", "ROM"), required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    else:
        valid_regions = {"jp", "us", "eu", "de"}
        regions = [region for region, _ in arguments.rom]
        if len(set(regions)) != len(regions) or any(region not in valid_regions for region in regions):
            raise ValueError("each --rom region must be one known, unique region")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        verify(arguments)


if __name__ == "__main__":
    main()

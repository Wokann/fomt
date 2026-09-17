#!/usr/bin/env python3
"""Build and verify the shared raw MapData presentation-template tables.

These two tables are delivered straight from ROM, rather than through a
compression codec.  They are not standalone images: one contains palette
template records and the other contains 16-bit BG tilemap entries selected by
the map-state renderer.  Keeping their native bytes as sources is therefore
the only reversible representation until the renderer proves individual table
record boundaries and tile/palette ownership.
"""

from __future__ import annotations

import argparse
import hashlib
from pathlib import Path


REGIONS = ("jp", "us", "eu", "de")
RECORDS = (
    (
        "map_state_palette_templates",
        "map_state_palette_templates.bin",
        0x4ECC,
        "afa739cad1afdbcbcc37db16a6e54030e31a23d105a16e39162caa142306dcad",
        {"jp": 0x45D654, "us": 0x6D74F8, "eu": 0x6D7554, "de": 0x45E594},
    ),
    (
        "map_state_tilemap_templates",
        "map_state_tilemap_templates.bin",
        0xC4E8,
        "e512d2c0dfc1fbbf9d7623519c7991ae72adef95e8316b6b2185f7c17dd95ec9",
        {"jp": 0x464950, "us": 0x6DE7F4, "eu": 0x6DE850, "de": 0x465890},
    ),
)


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def record_bytes(rom: bytes, region: str, record: tuple) -> bytes:
    name, _filename, size, expected_hash, offsets = record
    offset = offsets[region]
    value = rom[offset:offset + size]
    if len(value) != size or digest(value) != expected_hash:
        raise ValueError(f"{region}: {name} retail baseline mismatch")
    return value


def require_regions(roms: dict[str, Path]) -> None:
    if set(roms) != set(REGIONS):
        raise ValueError("requires exactly jp, us, eu and de ROMs")


def source_path(source_dir: Path, record: tuple) -> Path:
    return source_dir / record[1]


def read_source(source_dir: Path, record: tuple) -> bytes:
    path = source_path(source_dir, record)
    value = path.read_bytes()
    if len(value) != record[2]:
        raise ValueError(f"{path} must be exactly {record[2]:#x} bytes")
    return value


def output_path(output_dir: Path, record: tuple) -> Path:
    return output_dir / record[1]


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    require_regions({region: path for region, path in arguments.rom})
    for record in RECORDS:
        values = [record_bytes(roms[region], region, record) for region in REGIONS]
        if len(set(values)) != 1:
            raise ValueError(f"{record[0]} differs across retail regions; refusing a shared source")
        path = source_path(arguments.source_dir, record)
        if path.exists() and not arguments.replace:
            raise ValueError(f"{path} exists; pass --replace to refresh it")
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(values[0])
    print(f"exported {len(RECORDS)} verified shared map-state template tables")


def build(arguments: argparse.Namespace) -> None:
    baseline = arguments.rom.read_bytes()
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for record in RECORDS:
        record_bytes(baseline, arguments.region, record)
        output_path(arguments.output_dir, record).write_bytes(read_source(arguments.source_dir, record))
    print(f"rebuilt {len(RECORDS)} map-state template tables for {arguments.region}")


def verify(arguments: argparse.Namespace) -> None:
    baseline = arguments.rom.read_bytes()
    for record in RECORDS:
        retail = record_bytes(baseline, arguments.region, record)
        if read_source(arguments.source_dir, record) != retail:
            raise ValueError(f"{arguments.region}: source {record[0]} does not reproduce retail bytes")
        if output_path(arguments.output_dir, record).read_bytes() != retail:
            raise ValueError(f"{arguments.region}: rebuilt {record[0]} differs from retail bytes")
    print(f"verified {len(RECORDS)} map-state template tables for {arguments.region}")


def patch_bytes(image: bytearray, baseline: bytes, region: str, output_dir: Path) -> None:
    for record in RECORDS:
        name, _filename, size, _expected_hash, offsets = record
        offset = offsets[region]
        replacement = output_path(output_dir, record).read_bytes()
        expected = record_bytes(baseline, region, record)
        current = bytes(image[offset:offset + size])
        if len(replacement) != size:
            raise ValueError(f"{region}: {name} generated length mismatch")
        if current not in (expected, replacement):
            raise ValueError(f"{region}: {name} target contains third-party bytes")
        image[offset:offset + size] = replacement


def patch(arguments: argparse.Namespace) -> None:
    baselines = {region: path.read_bytes() for region, path in arguments.all_rom}
    require_regions({region: path for region, path in arguments.all_rom})
    image = bytearray(arguments.rom.read_bytes())
    patch_bytes(image, baselines[arguments.region], arguments.region, arguments.output_dir)
    arguments.rom.write_bytes(image)
    print(f"patched map-state template tables into {arguments.region} ROM")


def patch_test(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    require_regions({region: path for region, path in arguments.rom})
    for region in REGIONS:
        image = bytearray(roms[region])
        patch_bytes(image, roms[region], region, arguments.output_root / region / "graphics/map_state_templates")
        if bytes(image) != roms[region]:
            raise ValueError(f"{region}: unchanged template patch changed the ROM")
    print("verified post-link map-state template patching against JP, US, EU and DE ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    require_regions({region: path for region, path in arguments.rom})
    for record in RECORDS:
        source = bytearray(record_bytes(roms["jp"], "jp", record))
        source[len(source) // 2] ^= 1
        for region in REGIONS:
            image = bytearray(roms[region])
            _name, _filename, size, _expected_hash, offsets = record
            offset = offsets[region]
            image[offset:offset + size] = source
            if bytes(image[offset:offset + size]) != source:
                raise AssertionError(f"{region}: {record[0]} fixed-range edit failed")
            if image[:offset] != roms[region][:offset] or image[offset + size:] != roms[region][offset + size:]:
                raise AssertionError(f"{region}: {record[0]} edit escaped its fixed range")
    print(f"verified fixed-range editable coverage for {len(RECORDS)} map-state template tables")


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(description=__doc__)
    commands = result.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--region", choices=REGIONS, required=True)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        command.add_argument("--output-dir", type=Path, required=True)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=REGIONS, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    patch_parser.add_argument("--all-rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_test_parser = commands.add_parser("edit-test")
    edit_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    return result


def main() -> None:
    arguments = parser().parse_args()
    if hasattr(arguments, "rom") and isinstance(arguments.rom, list):
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if hasattr(arguments, "all_rom"):
        arguments.all_rom = [(region, Path(path)) for region, path in arguments.all_rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch":
        patch(arguments)
    elif arguments.command == "patch-test":
        patch_test(arguments)
    else:
        edit_test(arguments)


if __name__ == "__main__":
    main()

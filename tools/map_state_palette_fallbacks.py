#!/usr/bin/env python3
"""Rebuild the five MapData state-fallback palette streams.

The regional map-state routines select these streams for their fallback
branches. Each one decodes through the native ``0x30`` Raw-LZ path to exactly
fifteen BGR555 palette banks. They are not tile images: the authoritative
editable source is the ordered native ``.gbapal`` byte stream.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_popuri  # type: ignore[import-not-found]


REGIONS = ("jp", "us", "eu", "de")
DECODED_LENGTH = 0x1E0
FALLBACKS = (
    ("fallback_00", 0xA0, "00f24dd083bc5f9435eb7f7d90069b8612b7eed34e0ea5c92cd701d312fabd27", "19297f6d026c99f1b4cbe7e1c53661d9d45ff861e1ebf588b6042a0ef0c8ac0a"),
    ("fallback_01", 0x8C, "5eb927662660f0d053ff96932a55a32658ac34bb0ae76c87d5b43b71c21d6d09", "41dbde1f9599e8adfcb84ceb1ae5e414d8c5abd61c7a681f902d25518d1a1884"),
    ("fallback_02", 0x98, "c5aeb9ec2ca0b5bc83592337aac82c03f2900dda98f4cb9c69281e1abfdd6af5", "d5fd0b168d5d1d94f0f8418069e562e8729749e9cbb528993a116ffd54aadd39"),
    ("fallback_03", 0x94, "469868d4995c0456563d88551a12a841fb82bc9f2769063d049c85f31ce409af", "f31cfa8ebe4b13fd9988fe79938c008a935b40d3a45a61f59558b48621d3eee1"),
    ("fallback_04", 0x94, "65676eef9bc7d520e1c5250ef75d5974407cf72b977e5f1e9818c4d36c2ca4fe", "c34f14059e32c92196f429e6cce18fb586a00eedf487b15555908410775c6184"),
)
OFFSETS = {
    "jp": (0x49AB8C, 0x49ACBC, 0x49AD48, 0x49D0E0, 0x49D214),
    "us": (0x714A30, 0x714B60, 0x714BEC, 0x716F84, 0x7170B8),
    "eu": (0x714A8C, 0x714BBC, 0x714C48, 0x716FE0, 0x717114),
    "de": (0x49BACC, 0x49BBFC, 0x49BC88, 0x49E020, 0x49E154),
}


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def paths(source_dir: Path, output_dir: Path, name: str) -> tuple[Path, Path]:
    return source_dir / f"{name}.gbapal", output_dir / f"{name}.0x70"


def retail(rom: bytes, region: str, index: int) -> tuple[bytes, bytes, str, str]:
    name, length, packed_hash, decoded_hash = FALLBACKS[index]
    offset = OFFSETS[region][index]
    packed = rom[offset:offset + length]
    if len(packed) != length or digest(packed) != packed_hash:
        raise ValueError(f"{region}: {name} packed baseline mismatch")
    decoded, format_spec, ladder = unpack(packed)
    decoded = bytes(decoded)
    if (len(decoded), digest(decoded), format_spec) != (DECODED_LENGTH, decoded_hash, "030"):
        raise ValueError(f"{region}: {name} decode contract mismatch")
    return packed, decoded, format_spec, ladder


def read_source(path: Path) -> bytes:
    data = path.read_bytes()
    if len(data) != DECODED_LENGTH:
        raise ValueError(f"{path} must be exactly {DECODED_LENGTH:#x} bytes (15 BGR555 banks)")
    return data


def packed_source(source: bytes, baseline: bytes, format_spec: str, ladder: str, name: str) -> bytes:
    original, original_format, original_ladder = unpack(baseline)
    original = bytes(original)
    if source == original:
        return baseline
    packed = encode_popuri(source, format_spec, ladder)
    if len(packed) > len(baseline):
        raise ValueError(f"edited {name} needs {len(packed):#x} bytes; native slot holds {len(baseline):#x}")
    packed += bytes(len(baseline) - len(packed))
    decoded, checked_format, checked_ladder = unpack(packed)
    if bytes(decoded) != source or (checked_format, checked_ladder) != (original_format, original_ladder):
        raise AssertionError(f"{name}: encoded stream failed strict native decode")
    return packed


def require_regions(roms: dict[str, bytes]) -> None:
    if set(roms) != set(REGIONS):
        raise ValueError("export requires exactly jp, us, eu and de ROMs")


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    require_regions(roms)
    for index, (name, _length, _packed_hash, _decoded_hash) in enumerate(FALLBACKS):
        values = [retail(roms[region], region, index) for region in REGIONS]
        if len({item[0] for item in values}) != 1 or len({item[1] for item in values}) != 1:
            raise ValueError(f"{name} differs across retail regions; refusing a shared source")
        source, _output = paths(arguments.source_dir, arguments.source_dir, name)
        if source.exists() and not arguments.replace:
            raise ValueError(f"{source} exists; pass --replace to refresh it")
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_bytes(values[0][1])
    print(f"exported {len(FALLBACKS)} verified shared four-region map-state palette groups")


def build(arguments: argparse.Namespace) -> None:
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    rom = arguments.rom.read_bytes()
    for index, (name, _length, _packed_hash, _decoded_hash) in enumerate(FALLBACKS):
        baseline, _decoded, format_spec, ladder = retail(rom, arguments.region, index)
        source, output = paths(arguments.source_dir, arguments.output_dir, name)
        output.write_bytes(packed_source(read_source(source), baseline, format_spec, ladder, name))
    print(f"rebuilt {len(FALLBACKS)} map-state fallback palette groups for {arguments.region}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for index, (name, _length, _packed_hash, _decoded_hash) in enumerate(FALLBACKS):
        baseline, _decoded, format_spec, ladder = retail(rom, arguments.region, index)
        _source, output = paths(arguments.source_dir, arguments.output_dir, name)
        source = read_source(_source)
        if packed_source(source, baseline, format_spec, ladder, name) != baseline:
            raise ValueError(f"{arguments.region}: source {name} does not reproduce retail bytes")
        if output.read_bytes() != baseline:
            raise ValueError(f"{arguments.region}: rebuilt {name} differs from retail bytes")
    print(f"verified {len(FALLBACKS)} map-state fallback palette groups for {arguments.region}")


def patch_bytes(image: bytearray, baseline: bytes, region: str, output_dir: Path) -> None:
    for index, (name, length, _packed_hash, _decoded_hash) in enumerate(FALLBACKS):
        offset = OFFSETS[region][index]
        replacement = (output_dir / f"{name}.0x70").read_bytes()
        current = bytes(image[offset:offset + length])
        expected = baseline[offset:offset + length]
        if len(replacement) != length:
            raise ValueError(f"{region}: {name} generated length mismatch")
        if current not in (expected, replacement):
            raise ValueError(f"{region}: {name} target contains third-party bytes")
        image[offset:offset + length] = replacement


def patch(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.all_rom}
    if set(roms) != set(REGIONS):
        raise ValueError("patch requires jp, us, eu and de baseline ROMs")
    image = bytearray(arguments.rom.read_bytes())
    patch_bytes(image, roms[arguments.region], arguments.region, arguments.output_dir)
    arguments.rom.write_bytes(image)
    print(f"patched map-state fallback palettes into {arguments.region} ROM")


def patch_test(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("patch-test requires jp, us, eu and de ROMs")
    for region in REGIONS:
        image = bytearray(roms[region])
        patch_bytes(image, roms[region], region, arguments.output_root / region / "graphics/map_state_palettes")
        if bytes(image) != roms[region]:
            raise ValueError(f"{region}: unchanged fallback-palette patch changed the ROM")
    print("verified post-link map-state fallback palette patching against JP, US, EU and DE ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("edit-test requires jp, us, eu and de ROMs")
    for index, (name, _length, _packed_hash, _decoded_hash) in enumerate(FALLBACKS):
        baseline, source, format_spec, ladder = retail(roms["us"], "us", index)
        for position in range(len(source)):
            edited = bytearray(source)
            edited[position] ^= 1
            try:
                packed_source(bytes(edited), baseline, format_spec, ladder, name)
            except ValueError:
                continue
            break
        else:
            raise ValueError(f"{name}: no one-byte capacity-fitting edit found")
    print(f"verified capacity-fitting editable coverage for {len(FALLBACKS)} map-state palette groups")


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

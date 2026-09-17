#!/usr/bin/env python3
"""Preserve the overseas ``func_08077810`` LZ0 32-by-20 BG tilemap.

The source is a native array of 16-bit BG entries.  Its Huffman-4/LZ0 packed
stream is byte-identical in US, EU and DE.  No fixed-slot LZ0 encoder has yet
passed capacity validation, so an edited source fails explicitly instead of
silently changing the stream format or overflowing its proven ROM interval.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent / "scripts"))
from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff4_lz0  # type: ignore[import-not-found]


STREAMS = {"us": (0x74EB60, 0x16C), "eu": (0x74EBBC, 0x16C), "de": (0x4D5FCC, 0x16C)}
DECODED_SIZE = 0x500
SOURCE_NAME = "layer_1.tilemap"
OUTPUT_NAME = f"{SOURCE_NAME}.0x70"


def source_path(directory: Path) -> Path:
    return directory / SOURCE_NAME


def output_path(directory: Path) -> Path:
    return directory / OUTPUT_NAME


def packed(rom: bytes, region: str) -> bytes:
    offset, length = STREAMS[region]
    result = rom[offset:offset + length]
    if len(result) != length:
        raise ValueError(f"{region} LZ0 stream exceeds ROM bounds")
    return result


def decoded(rom: bytes, region: str) -> bytes:
    result, format_spec, ladder = unpack(packed(rom, region))
    if len(result) != DECODED_SIZE or (format_spec, ladder) != ("100", "110"):
        raise ValueError(f"{region} stream is not the expected 0x500-byte Huffman-4/LZ0 tilemap")
    return bytes(result)


def rebuild(source: bytes, baseline: bytes, region: str) -> bytes:
    if len(source) != DECODED_SIZE:
        raise ValueError(f"{region} tilemap source must be exactly {DECODED_SIZE:#x} bytes")
    original, format_spec, ladder = unpack(baseline)
    if len(original) != DECODED_SIZE or (format_spec, ladder) != ("100", "110"):
        raise ValueError(f"{region} baseline is not the expected Huffman-4/LZ0 tilemap")
    if source == bytes(original):
        return baseline
    encoded = encode_huff4_lz0(source, ladder)
    if len(encoded) > len(baseline):
        raise ValueError(f"edited {region} LZ0 tilemap needs {len(encoded):#x}; native slot holds {len(baseline):#x}")
    result = encoded + bytes(len(baseline) - len(encoded))
    checked, checked_format, checked_ladder = unpack(result)
    if bytes(checked) != source or (checked_format, checked_ladder) != (format_spec, ladder):
        raise AssertionError("rebuilt LZ0 tilemap failed strict native decode validation")
    return result


def export(arguments: argparse.Namespace) -> None:
    roms = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(roms) != set(STREAMS):
        raise ValueError("export requires exactly US, EU and DE ROMs")
    compressed = {region: hashlib.sha256(packed(roms[region], region)).digest() for region in STREAMS}
    payloads = {region: decoded(roms[region], region) for region in STREAMS}
    if len(set(compressed.values())) != 1 or len(set(payloads.values())) != 1:
        raise ValueError("overseas LZ0 tilemap differs; refusing a shared source")
    output = source_path(arguments.source_dir)
    if output.exists() and not arguments.replace:
        raise ValueError(f"{output} exists; use --replace to refresh it")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(payloads["us"])
    print("exported shared US/EU/DE func_08077810 LZ0 tilemap")


def build(arguments: argparse.Namespace) -> None:
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    if arguments.region == "jp":
        print("func_08077810 LZ0 tilemap has no JP counterpart; no output required")
        return
    result = rebuild(
        source_path(arguments.source_dir).read_bytes(),
        packed(arguments.rom.read_bytes(), arguments.region),
        arguments.region,
    )
    output_path(arguments.output_dir).write_bytes(result)
    print(f"preserved func_08077810 LZ0 tilemap for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    if arguments.region == "jp":
        print("verified JP: no matching func_08077810 LZ0 tilemap")
        return
    baseline = packed(arguments.rom.read_bytes(), arguments.region)
    if rebuild(source_path(arguments.source_dir).read_bytes(), baseline, arguments.region) != baseline:
        raise AssertionError(f"{arguments.region} LZ0 tilemap differs from retail bytes")
    if arguments.output_dir is not None and output_path(arguments.output_dir).read_bytes() != baseline:
        raise AssertionError(f"built {arguments.region} LZ0 tilemap differs from retail bytes")
    print(f"verified func_08077810 LZ0 tilemap against {arguments.region.upper()} ROM")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        if region != "jp":
            offset, length = STREAMS[region]
            generated = output_path(arguments.output_root / region / "graphics" / "ui" / "scene_08077810").read_bytes()
            if generated != baseline[offset:offset + length]:
                raise AssertionError(f"generated {region} LZ0 tilemap differs from retail bytes")
            baseline = baseline[:offset] + generated + baseline[offset + length:]
        if baseline != Path(path).read_bytes():
            raise AssertionError(f"unchanged {region} LZ0 patch differs from retail ROM")
    print("verified unchanged LZ0 tilemap output against JP/US/EU/DE ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    source = decoded(rom, "us")
    edited = bytes([source[0] ^ 1]) + source[1:]
    result = rebuild(edited, packed(rom, "us"), "us")
    checked, _format, _ladder = unpack(result)
    if bytes(checked) != edited:
        raise AssertionError("edited LZ0 fixture did not round trip")
    print(f"func_08077810 LZ0 edit test: {len(result):#x} / {STREAMS['us'][1]:#x} bytes")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--region", choices=("jp", *STREAMS), required=True)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        if name == "build":
            command.add_argument("--output-dir", type=Path, required=True)
        else:
            command.add_argument("--output-dir", type=Path)
    export_command = commands.add_parser("export")
    export_command.add_argument("--source-dir", type=Path, required=True)
    export_command.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_command.add_argument("--replace", action="store_true")
    patch_command = commands.add_parser("patch-test")
    patch_command.add_argument("--output-root", type=Path, required=True)
    patch_command.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_command = commands.add_parser("edit-test")
    edit_command.add_argument("--rom", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export": export(arguments)
    elif arguments.command == "build": build(arguments)
    elif arguments.command == "verify": verify(arguments)
    elif arguments.command == "patch-test": patch_test(arguments)
    else: edit_test(arguments)


if __name__ == "__main__":
    main()

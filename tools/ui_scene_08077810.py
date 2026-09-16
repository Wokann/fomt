#!/usr/bin/env python3
"""Manage the overseas-only BG tilemap loaded by ``func_08077810``.

The US, EU and DE versions unpack the same 0x1000-byte Huffman-4/LZ3 stream
to VRAM ``0x0600C800``.  The stream is a native 32-by-32 BG tilemap, so the
editable source deliberately remains its 1024 little-endian tile entries.
JP has a separately laid-out implementation and no ``gUnk_0874ECCC``
consumer; this tool therefore leaves JP untouched rather than inventing a
false regional correspondence.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff4_lz3  # type: ignore[import-not-found]


STREAMS = {
    "us": (0x74ECCC, 0x16C),
    "eu": (0x74ED28, 0x16C),
    "de": (0x4D6138, 0x16C),
}
DECODED_SIZE = 0x1000
SOURCE_NAME = "layer_0.tilemap"
OUTPUT_NAME = f"{SOURCE_NAME}.0x70"


def source_path(source_dir: Path) -> Path:
    return source_dir / SOURCE_NAME


def output_path(output_dir: Path) -> Path:
    return output_dir / OUTPUT_NAME


def packed(rom: bytes, region: str) -> bytes:
    offset, length = STREAMS[region]
    result = rom[offset:offset + length]
    if len(result) != length:
        raise ValueError(f"{region} stream exceeds ROM bounds")
    return result


def decoded(rom: bytes, region: str) -> tuple[bytes, str, str]:
    data, format_spec, ladder = unpack(packed(rom, region))
    if len(data) != DECODED_SIZE or format_spec != "130":
        raise ValueError(
            f"{region} stream decoded as {len(data):#x} bytes / {format_spec}; "
            "expected a 0x1000-byte Huffman-4/LZ3 BG tilemap"
        )
    return bytes(data), format_spec, ladder


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STREAMS):
        raise ValueError("export requires exactly us, eu and de ROMs")
    packed_hashes = {region: hashlib.sha256(packed(inputs[region], region)).digest() for region in STREAMS}
    payloads = {region: decoded(inputs[region], region)[0] for region in STREAMS}
    if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
        raise ValueError("overseas func_08077810 tilemap differs; refusing a shared source")
    output = source_path(arguments.source_dir)
    if output.exists() and not arguments.replace:
        raise ValueError(f"{output} exists; use --replace to refresh it")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(payloads["us"])
    print("exported one shared US/EU/DE func_08077810 BG tilemap")


def rebuild(source: bytes, baseline: bytes, region: str) -> bytes:
    if len(source) != DECODED_SIZE:
        raise ValueError(f"{region} tilemap source must be exactly {DECODED_SIZE:#x} bytes")
    original, format_spec, ladder = unpack(baseline)
    if bytes(original) == source:
        return baseline
    encoded = encode_huff4_lz3(source, ladder)
    if len(encoded) > len(baseline):
        raise ValueError(
            f"edited {region} tilemap needs {len(encoded):#x} bytes; "
            f"its native slot holds only {len(baseline):#x}"
        )
    result = encoded + bytes(len(baseline) - len(encoded))
    checked, checked_format, checked_ladder = unpack(result)
    if bytes(checked) != source or checked_format != format_spec or checked_ladder != ladder:
        raise AssertionError("rebuilt func_08077810 tilemap failed strict native decode validation")
    return result


def build(arguments: argparse.Namespace) -> None:
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    if arguments.region == "jp":
        print("func_08077810 has no JP gUnk_0874ECCC consumer; no output required")
        return
    source = source_path(arguments.source_dir).read_bytes()
    if len(source) != DECODED_SIZE:
        raise ValueError(f"{source_path(arguments.source_dir)} must be exactly {DECODED_SIZE:#x} bytes")
    rebuilt = rebuild(source, packed(arguments.rom.read_bytes(), arguments.region), arguments.region)
    output_path(arguments.output_dir).write_bytes(rebuilt)
    print(f"rebuilt func_08077810 BG tilemap for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    if arguments.region == "jp":
        print("verified JP: func_08077810 has no matching gUnk_0874ECCC consumer")
        return
    source = source_path(arguments.source_dir).read_bytes()
    baseline = packed(arguments.rom.read_bytes(), arguments.region)
    rebuilt = rebuild(source, baseline, arguments.region)
    if rebuilt != baseline:
        raise AssertionError(f"func_08077810 source does not match retail {arguments.region.upper()} bytes")
    if arguments.output_dir is not None and output_path(arguments.output_dir).read_bytes() != baseline:
        raise AssertionError(f"built func_08077810 output does not match retail {arguments.region.upper()} bytes")
    print(f"verified func_08077810 BG tilemap against {arguments.region.upper()} ROM")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        if region == "jp":
            result = baseline
        else:
            output = output_path(arguments.output_root / region / "graphics" / "ui" / "scene_08077810").read_bytes()
            offset, length = STREAMS[region]
            if output != baseline[offset:offset + length]:
                raise AssertionError(f"generated {region.upper()} stream differs from retail bytes")
            result = baseline[:offset] + output + baseline[offset + length:]
        if result != baseline:
            raise AssertionError(f"unchanged func_08077810 patch differs from retail {region.upper()} ROM")
    print("verified unchanged func_08077810 output against JP/US/EU/DE ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    source, _format, _ladder = decoded(arguments.rom.read_bytes(), "us")
    try:
        rebuild(source + b"\0", packed(arguments.rom.read_bytes(), "us"), "us")
    except ValueError as error:
        if "exactly" not in str(error):
            raise
        print("func_08077810 source-size guard: rejects data outside the 0x1000-byte BG map domain")
        return
    raise AssertionError("func_08077810 source-size guard unexpectedly accepted an oversized tilemap")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=("jp", *STREAMS), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=("jp", *STREAMS), required=True)
    verify_parser.add_argument("--rom", type=Path, required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    patch_parser = commands.add_parser("patch-test")
    patch_parser.add_argument("--output-root", type=Path, required=True)
    patch_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--rom", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch-test":
        patch_test(arguments)
    else:
        edit_test(arguments)


if __name__ == "__main__":
    main()

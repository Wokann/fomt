#!/usr/bin/env python3
"""Manage the twenty verified native Intro Scene object-tile streams.

Each stream decompresses to exactly 0x500 bytes and is copied by
``func_0805FBB8`` into its 0x500-byte object-tile staging slot.  The native
OAM composition and palette selection are intentionally *not* guessed here:
the checked-in ``.4bpp`` files are editable native tile sources, not claimed
full-frame PNGs.  A future OAM-aware exporter can consume the same sources.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_raw_lz  # type: ignore[import-not-found]


@dataclass(frozen=True)
class Stream:
    index: int
    offset: int
    length: int


LENGTHS = (
    0x2FC, 0x54, 0xF4, 0x6C, 0x140, 0x98, 0x120, 0x78, 0x94, 0x60,
    0xD8, 0x74, 0x26C, 0x24, 0x274, 0x38, 0x304, 0x50, 0x30C, 0x68,
)
STARTS = {
    "jp": 0x4C7B5C,
    "us": 0x7419F4,
    "eu": 0x741A50,
    "de": 0x4C8E68,
}


def streams(region: str) -> tuple[Stream, ...]:
    cursor = STARTS[region]
    result: list[Stream] = []
    for index, length in enumerate(LENGTHS):
        result.append(Stream(index, cursor, length))
        cursor += length
    return tuple(result)


def source_path(source_dir: Path, index: int) -> Path:
    return source_dir / f"object_{index:02d}.4bpp"


def packed(rom: bytes, stream: Stream) -> bytes:
    result = rom[stream.offset:stream.offset + stream.length]
    if len(result) != stream.length:
        raise ValueError(f"stream {stream.index:02d} exceeds ROM bounds")
    return result


def decoded(rom: bytes, stream: Stream) -> tuple[bytes, str, str]:
    data, format_spec, ladder = unpack(packed(rom, stream))
    if len(data) != 0x500:
        raise ValueError(f"stream {stream.index:02d} decoded to {len(data):#x}, expected 0x500")
    if format_spec not in ("010", "020", "030"):
        raise ValueError(f"stream {stream.index:02d} has unsupported native format {format_spec}")
    return bytes(data), format_spec, ladder


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STARTS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for index in range(len(LENGTHS)):
        entries = {region: streams(region)[index] for region in STARTS}
        packed_hashes = {region: hashlib.sha256(packed(inputs[region], entry)).hexdigest() for region, entry in entries.items()}
        payloads = {region: decoded(inputs[region], entry)[0] for region, entry in entries.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"stream {index:02d} differs across retail regions; refusing a shared source")
        output = source_path(arguments.source_dir, index)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.write_bytes(payloads["jp"])
    print(f"exported {len(LENGTHS)} shared Intro Scene native object-tile sources")


def rebuild(source: bytes, baseline: bytes) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if source == original:
        return baseline
    encoded = encode_raw_lz(source, int(format_spec[1]), ladder)
    if len(encoded) > len(baseline):
        raise ValueError(f"edited stream needs {len(encoded):#x} bytes but its native slot holds {len(baseline):#x}")
    result = encoded + bytes(len(baseline) - len(encoded))
    check, check_format, check_ladder = unpack(result)
    if check != source or check_format != format_spec or check_ladder != ladder:
        raise AssertionError("rebuilt stream failed strict native decode validation")
    return result


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    output_dir = arguments.output_dir
    output_dir.mkdir(parents=True, exist_ok=True)
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream.index).read_bytes()
        if len(source) != 0x500:
            raise ValueError(f"{source_path(arguments.source_dir, stream.index)} must be exactly 0x500 bytes")
        (output_dir / f"object_{stream.index:02d}.0x70").write_bytes(rebuild(source, packed(rom, stream)))
    print(f"rebuilt {len(LENGTHS)} Intro Scene object streams for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream.index).read_bytes()
        baseline = packed(rom, stream)
        rebuilt = rebuild(source, baseline)
        if rebuilt != baseline:
            raise AssertionError(f"stream {stream.index:02d} no longer matches the retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None:
            output = arguments.output_dir / f"object_{stream.index:02d}.0x70"
            if output.read_bytes() != baseline:
                raise AssertionError(f"built stream {output} does not match the retail {arguments.region.upper()} bytes")
    print(f"verified {len(LENGTHS)} Intro Scene object streams against {arguments.region.upper()} ROM")


def edit_test(arguments: argparse.Namespace) -> None:
    """Exercise one deterministic native-tile edit without changing sources."""
    rom = arguments.rom.read_bytes()
    stream = streams(arguments.region)[0]
    source, _format, _ladder = decoded(rom, stream)
    edited = bytearray(source)
    index = next(index for index, value in enumerate(edited) if value)
    edited[index] ^= 1
    rebuilt = rebuild(bytes(edited), packed(rom, stream))
    check, _format, _ladder = unpack(rebuilt)
    if check != edited or rebuilt == packed(rom, stream):
        raise AssertionError("edited Intro Scene object stream did not strictly round-trip")
    print(f"Intro Scene object edit test: object_00 byte {index:#x}; packed {len(rebuilt):#x} bytes")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(STARTS), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=tuple(STARTS), required=True)
    verify_parser.add_argument("--rom", type=Path, required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(STARTS), required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    else:
        edit_test(arguments)


if __name__ == "__main__":
    main()

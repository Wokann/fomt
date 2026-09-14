#!/usr/bin/env python3
"""Manage the four verified Intro Scene startup BG-tilemap streams.

``func_08001A90`` unpacks each 0x1000-byte stream into two interleaved
0x800-byte halves, then copies the halves row-by-row to two 32x32 BG tilemaps
in VRAM.  The checked-in ``.tilemap`` files keep that exact native interleaved
order; they are source data, not guessed rendered PNGs.
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
from marvelous_codec import encode_huff4_lz3  # type: ignore[import-not-found]


@dataclass(frozen=True)
class Stream:
    index: int
    offset: int
    length: int


LENGTHS = (0x3DC, 0x21C, 0xF4, 0xFC)
STARTS = {
    "jp": 0x4D096C,
    "us": 0x74A1D8,
    "eu": 0x74A234,
    "de": 0x4D1644,
}


def streams(region: str) -> tuple[Stream, ...]:
    cursor = STARTS[region]
    result: list[Stream] = []
    for index, length in enumerate(LENGTHS):
        result.append(Stream(index, cursor, length))
        cursor += length
    return tuple(result)


def source_path(source_dir: Path, index: int) -> Path:
    return source_dir / f"startup_{index:02d}.tilemap"


def packed(rom: bytes, stream: Stream) -> bytes:
    result = rom[stream.offset:stream.offset + stream.length]
    if len(result) != stream.length:
        raise ValueError(f"stream {stream.index:02d} exceeds ROM bounds")
    return result


def decoded(rom: bytes, stream: Stream) -> tuple[bytes, str, str]:
    data, format_spec, ladder = unpack(packed(rom, stream))
    if len(data) != 0x1000 or format_spec != "130":
        raise ValueError(
            f"stream {stream.index:02d} decoded as {len(data):#x} bytes / {format_spec}; "
            "expected 0x1000-byte Huffman-4 LZ3 tilemap data"
        )
    return bytes(data), format_spec, ladder


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STARTS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for index in range(len(LENGTHS)):
        entries = {region: streams(region)[index] for region in STARTS}
        packed_hashes = {
            region: hashlib.sha256(packed(inputs[region], entry)).hexdigest()
            for region, entry in entries.items()
        }
        payloads = {region: decoded(inputs[region], entry)[0] for region, entry in entries.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"startup stream {index:02d} differs across retail regions; refusing a shared source")
        output = source_path(arguments.source_dir, index)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.write_bytes(payloads["jp"])
    print(f"exported {len(LENGTHS)} shared Intro Scene startup tilemap sources")


def rebuild(source: bytes, baseline: bytes) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if source == original:
        return baseline
    encoded = encode_huff4_lz3(source, ladder)
    if len(encoded) > len(baseline):
        raise ValueError(f"edited startup stream needs {len(encoded):#x} bytes but its native slot holds {len(baseline):#x}")
    result = encoded + bytes(len(baseline) - len(encoded))
    check, check_format, check_ladder = unpack(result)
    if check != source or check_format != format_spec or check_ladder != ladder:
        raise AssertionError("rebuilt startup stream failed strict native decode validation")
    return result


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream.index).read_bytes()
        if len(source) != 0x1000:
            raise ValueError(f"{source_path(arguments.source_dir, stream.index)} must be exactly 0x1000 bytes")
        output = arguments.output_dir / f"startup_{stream.index:02d}.0x70"
        output.write_bytes(rebuild(source, packed(rom, stream)))
    print(f"rebuilt {len(LENGTHS)} Intro Scene startup tilemap streams for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream.index).read_bytes()
        baseline = packed(rom, stream)
        rebuilt = rebuild(source, baseline)
        if rebuilt != baseline:
            raise AssertionError(f"startup stream {stream.index:02d} no longer matches retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None:
            output = arguments.output_dir / f"startup_{stream.index:02d}.0x70"
            if output.read_bytes() != baseline:
                raise AssertionError(f"built stream {output} does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(LENGTHS)} Intro Scene startup tilemap streams against {arguments.region.upper()} ROM")


def edit_test(arguments: argparse.Namespace) -> None:
    """Exercise a deterministic edit without changing the checked-in source."""
    rom = arguments.rom.read_bytes()
    stream = streams(arguments.region)[0]
    source, _format, _ladder = decoded(rom, stream)
    edited = bytearray(source)
    index = next(index for index, value in enumerate(edited) if value)
    edited[index] ^= 1
    rebuilt = rebuild(bytes(edited), packed(rom, stream))
    check, _format, _ladder = unpack(rebuilt)
    if check != edited or rebuilt == packed(rom, stream):
        raise AssertionError("edited startup tilemap did not strictly round-trip")
    print(f"Intro Scene startup edit test: startup_00 byte {index:#x}; packed {len(rebuilt):#x} bytes")


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

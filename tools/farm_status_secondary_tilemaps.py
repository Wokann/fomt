#!/usr/bin/env python3
"""Manage the Farm Status Screen's secondary 64-by-44 BG tilemaps.

``func_0806EC94`` selects one of two three-layer layouts.  For every layout,
``func_0806EB70`` unpacks one 0x1600-byte stream and writes its 44 rows of 64
u16 BG entries into a selected screen block.  These files therefore preserve
the native tilemap order directly instead of claiming a guessed rendered PNG.
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


LENGTHS = (0x110, 0x1D8, 0xB0, 0x114, 0x1D0, 0xB0)
STARTS = {
    "jp": (0x2AD394, 0x2AD4A4, 0x2AD67C, 0x2B0834, 0x2B0948, 0x2B0B18),
    "us": (0x527238, 0x527348, 0x527520, 0x52A6D8, 0x52A7EC, 0x52A9BC),
    "eu": (0x527294, 0x5273A4, 0x52757C, 0x52A734, 0x52A848, 0x52AA18),
    "de": (0x2AE2D4, 0x2AE3E4, 0x2AE5BC, 0x2B1774, 0x2B1888, 0x2B1A58),
}


@dataclass(frozen=True)
class Stream:
    index: int
    offset: int
    length: int

    @property
    def variant(self) -> int:
        return self.index // 3

    @property
    def layer(self) -> int:
        return self.index % 3


def streams(region: str) -> tuple[Stream, ...]:
    return tuple(Stream(index, offset, LENGTHS[index]) for index, offset in enumerate(STARTS[region]))


def stem(stream: Stream) -> str:
    return f"secondary_{stream.index:02d}"


def source_path(source_dir: Path, stream: Stream) -> Path:
    return source_dir / f"{stem(stream)}.tilemap"


def output_path(output_dir: Path, stream: Stream) -> Path:
    return output_dir / f"{stem(stream)}.0x70"


def packed(rom: bytes, stream: Stream) -> bytes:
    result = rom[stream.offset:stream.offset + stream.length]
    if len(result) != stream.length:
        raise ValueError(f"secondary stream {stream.index:02d} exceeds ROM bounds")
    return result


def decoded(rom: bytes, stream: Stream) -> tuple[bytes, str, str]:
    data, format_spec, ladder = unpack(packed(rom, stream))
    if len(data) != 0x1600 or format_spec != "130":
        raise ValueError(
            f"secondary stream {stream.index:02d} decoded as {len(data):#x} bytes / {format_spec}; "
            "expected a 0x1600-byte Huffman-4 LZ3 BG tilemap"
        )
    return bytes(data), format_spec, ladder


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STARTS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    for index in range(len(LENGTHS)):
        entries = {region: streams(region)[index] for region in STARTS}
        packed_hashes = {region: hashlib.sha256(packed(inputs[region], entry)).digest() for region, entry in entries.items()}
        payloads = {region: decoded(inputs[region], entry)[0] for region, entry in entries.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"secondary stream {index:02d} differs across retail regions; refusing a shared source")
        output = source_path(arguments.source_dir, entries["jp"])
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_bytes(payloads["jp"])
    print("exported 6 shared Farm Status secondary BG tilemaps")


def rebuild(source: bytes, baseline: bytes) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if source == original:
        return baseline
    encoded = encode_huff4_lz3(source, ladder)
    if len(encoded) > len(baseline):
        raise ValueError(f"edited secondary tilemap needs {len(encoded):#x} bytes but its native slot holds {len(baseline):#x}")
    result = encoded + bytes(len(baseline) - len(encoded))
    check, check_format, check_ladder = unpack(result)
    if check != source or check_format != format_spec or check_ladder != ladder:
        raise AssertionError("rebuilt secondary tilemap failed strict native decode validation")
    return result


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream).read_bytes()
        if len(source) != 0x1600:
            raise ValueError(f"{source_path(arguments.source_dir, stream)} must be exactly 0x1600 bytes")
        output = output_path(arguments.output_dir, stream)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_bytes(rebuild(source, packed(rom, stream)))
    print(f"rebuilt 6 Farm Status secondary tilemaps for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in streams(arguments.region):
        baseline = packed(rom, stream)
        source = source_path(arguments.source_dir, stream).read_bytes()
        rebuilt = rebuild(source, baseline)
        if rebuilt != baseline:
            raise AssertionError(f"secondary stream {stream.index:02d} no longer matches retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None and output_path(arguments.output_dir, stream).read_bytes() != baseline:
            raise AssertionError(f"built {output_path(arguments.output_dir, stream)} does not match retail bytes")
    print(f"verified 6 Farm Status secondary tilemaps against {arguments.region.upper()} ROM")


def edit_test(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    stream = streams(arguments.region)[0]
    source, _format, _ladder = decoded(rom, stream)
    edited = bytearray(source)
    edited[next(index for index, value in enumerate(edited) if value)] ^= 1
    try:
        rebuild(bytes(edited), packed(rom, stream))
    except ValueError as error:
        if "native slot holds" not in str(error):
            raise
        print(f"Farm Status secondary capacity guard: {stem(stream)}")
        return
    raise AssertionError("capacity-guard fixture unexpectedly fit in its native slot")


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

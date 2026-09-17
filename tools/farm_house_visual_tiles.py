#!/usr/bin/env python3
"""Manage the seven code-proven FarmHouse visual 4bpp tile streams.

``gFarmHouseVisualDescriptors`` has seven records.  Each record's ``+0x18``
pointer is passed directly to ``Unpack`` and the ``+0x1C`` value selects its
VRAM tile destination.  The decoded bytes are therefore native linear 4bpp
tile data, not a guessed full image.  The descriptor's surrounding lookup and
palette-copy data intentionally stay outside this tool: their physical labels
overlap the copy domains and do not yet prove one complete static layout.

All seven packed streams and their decoded tile bytes are byte-identical in
the JP, US, EU and DE retail ROMs.  The tool obtains each region's physical
start from the original descriptor table, rather than assuming that the four
asset containers have the same layout.
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
from marvelous_codec import (  # type: ignore[import-not-found]
    encode_huff4_lz2,
    encode_huff8_lz2,
    encode_huff8_lz3,
)


ROM_BASE = 0x08000000
VISUAL_TABLE_OFFSET = 0x128
VISUAL_DESCRIPTOR_SIZE = 0x2C
PACKED_STREAM_POINTER_OFFSET = 0x18

# Physical addresses of gFarmHouseTilePatchData.  The visual table begins at
# +0x128 in every retail layout; reading the ROM table preserves EU's small
# asset-container displacement without a hard-coded guessed resource offset.
TABLE_BASES = {
    "jp": 0x106C24,
    "us": 0x1070DC,
    "eu": 0x107134,
    "de": 0x107B00,
}


@dataclass(frozen=True)
class Stream:
    index: int
    packed_length: int
    decoded_length: int
    format_spec: str
    ladder: str

    @property
    def source_name(self) -> str:
        return f"visual_{self.index:02d}.4bpp"

    @property
    def output_name(self) -> str:
        return f"visual_{self.index:02d}.0x70"


# These fixed intervals end at the immediately following code-backed resource
# label in every region.  They are not inferred from the decoder's stopping
# position, which is intentionally unavailable to the original runtime.
STREAMS = (
    Stream(0, 0x3C4, 0x800, "230", "148"),
    Stream(1, 0x424, 0x7E0, "121", "24567811"),
    Stream(2, 0x418, 0x7E0, "121", "24567810"),
    Stream(3, 0xB9C, 0x13E0, "230", "1811"),
    Stream(4, 0x16EC, 0x2BE0, "220", "267891113"),
    Stream(5, 0x364, 0x7E0, "120", "2456788"),
    Stream(6, 0x10DC, 0x1BE0, "230", "1812"),
)


def stream_offset(rom: bytes, region: str, stream: Stream) -> int:
    table = TABLE_BASES[region] + VISUAL_TABLE_OFFSET
    cursor = table + stream.index * VISUAL_DESCRIPTOR_SIZE + PACKED_STREAM_POINTER_OFFSET
    pointer = int.from_bytes(rom[cursor:cursor + 4], "little")
    if pointer < ROM_BASE or pointer >= ROM_BASE + len(rom):
        raise ValueError(f"{region} visual_{stream.index:02d}: invalid ROM pointer {pointer:#010x}")
    offset = pointer - ROM_BASE
    if rom[offset:offset + 1] != b"\x70":
        raise ValueError(f"{region} visual_{stream.index:02d}: descriptor pointer does not start a 0x70 stream")
    return offset


def packed(rom: bytes, region: str, stream: Stream) -> bytes:
    offset = stream_offset(rom, region, stream)
    result = rom[offset:offset + stream.packed_length]
    if len(result) != stream.packed_length:
        raise ValueError(f"{region} {stream.source_name}: fixed interval leaves the ROM")
    return result


def decoded(rom: bytes, region: str, stream: Stream) -> bytes:
    result, format_spec, ladder = unpack(packed(rom, region, stream))
    if len(result) != stream.decoded_length or format_spec != stream.format_spec or ladder != stream.ladder:
        raise ValueError(
            f"{region} {stream.source_name}: decoded {len(result):#x} bytes / "
            f"{format_spec}/{ladder}; expected {stream.decoded_length:#x} / "
            f"{stream.format_spec}/{stream.ladder}"
        )
    return bytes(result)


def source_path(source_dir: Path, stream: Stream) -> Path:
    return source_dir / stream.source_name


def output_path(output_dir: Path, stream: Stream) -> Path:
    return output_dir / stream.output_name


def inverse_nibble_diff(data: bytes) -> bytes:
    """Invert the retail ``diff1`` filter before Huffman/LZ encoding.

    The native decoder accumulates high then low 4-bit values across the
    complete byte stream.  Subtracting the preceding decoded nibble restores
    the atom stream consumed by the H4/LZ2 encoder.
    """
    accumulator = 0
    result = bytearray()
    for value in data:
        high = value >> 4
        low = value & 0x0F
        result.append(((high - accumulator) & 0x0F) << 4 | ((low - high) & 0x0F))
        accumulator = low
    return bytes(result)


def encode(source: bytes, stream: Stream) -> bytes:
    if stream.format_spec == "230":
        return encode_huff8_lz3(source)
    if stream.format_spec == "120":
        return encode_huff4_lz2(source, stream.ladder)
    if stream.format_spec == "121":
        return encode_huff4_lz2(inverse_nibble_diff(source), stream.ladder, differential_filter=1)
    if stream.format_spec == "220":
        return encode_huff8_lz2(source, stream.ladder)
    raise AssertionError(f"no encoder registered for {stream.format_spec}")


def rebuild(source: bytes, baseline: bytes, stream: Stream) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if len(original) != stream.decoded_length or format_spec != stream.format_spec or ladder != stream.ladder:
        raise AssertionError(f"baseline {stream.source_name} no longer matches its audited format")
    result = baseline if bytes(original) == source else encode(source, stream)
    if len(result) > stream.packed_length:
        raise ValueError(
            f"edited {stream.source_name} needs {len(result):#x} bytes; its verified native slot holds "
            f"only {stream.packed_length:#x} bytes"
        )
    result += bytes(stream.packed_length - len(result))
    checked, checked_format, checked_ladder = unpack(result)
    # The unchanged source keeps its publisher stream (including its original
    # distance ladder) byte-for-byte.  A changed Huffman-8/LZ3 source may use
    # the deterministic encoder's valid canonical ladder instead, so only the
    # decoder mode and reconstructed native bytes are invariant after edits.
    if bytes(checked) != source or checked_format != stream.format_spec:
        raise AssertionError(f"{stream.source_name} failed strict native decode validation")
    return result


def export(arguments: argparse.Namespace) -> None:
    roms = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(roms) != set(TABLE_BASES):
        raise ValueError("export requires exactly jp, us, eu and de ROMs")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for stream in STREAMS:
        packed_hashes = {region: hashlib.sha256(packed(rom, region, stream)).digest() for region, rom in roms.items()}
        payloads = {region: decoded(rom, region, stream) for region, rom in roms.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"{stream.source_name} differs between retail regions; refusing a shared source")
        output = source_path(arguments.source_dir, stream)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; pass --replace to refresh it")
        output.write_bytes(payloads["jp"])
    print(f"exported {len(STREAMS)} shared FarmHouse visual native tile sources")


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for stream in STREAMS:
        source = source_path(arguments.source_dir, stream).read_bytes()
        if len(source) != stream.decoded_length:
            raise ValueError(f"{source_path(arguments.source_dir, stream)} must be exactly {stream.decoded_length:#x} bytes")
        output_path(arguments.output_dir, stream).write_bytes(rebuild(source, packed(rom, arguments.region, stream), stream))
    print(f"rebuilt {len(STREAMS)} FarmHouse visual tile streams for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in STREAMS:
        source = source_path(arguments.source_dir, stream).read_bytes()
        built = rebuild(source, packed(rom, arguments.region, stream), stream)
        baseline = packed(rom, arguments.region, stream)
        if built != baseline:
            raise AssertionError(f"unchanged {stream.source_name} does not reproduce retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None and output_path(arguments.output_dir, stream).read_bytes() != baseline:
            raise AssertionError(f"built {stream.source_name} does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(STREAMS)} FarmHouse visual streams against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, region: str, output_dir: Path) -> bytes:
    result = bytearray(target)
    for stream in STREAMS:
        generated = output_path(output_dir, stream).read_bytes()
        expected = packed(baseline, region, stream)
        offset = stream_offset(baseline, region, stream)
        current = target[offset:offset + stream.packed_length]
        if len(generated) != stream.packed_length:
            raise ValueError(f"generated {stream.output_name} has incorrect length")
        if current != expected and current != generated:
            raise ValueError(f"target {stream.source_name} differs from both retail baseline and generated bytes")
        result[offset:offset + stream.packed_length] = generated
    return bytes(result)


def patch(arguments: argparse.Namespace) -> None:
    target = arguments.rom.read_bytes()
    baseline = arguments.baseline.read_bytes()
    arguments.rom.write_bytes(apply(target, baseline, arguments.region, arguments.output_dir))
    print(f"patched {len(STREAMS)} FarmHouse visual streams into {arguments.rom} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        output_dir = arguments.output_root / region / "graphics" / "farm_house_visual"
        if apply(baseline, baseline, region, output_dir) != baseline:
            raise AssertionError(f"unchanged FarmHouse visual patch differs from retail {region.upper()} ROM")
    print("verified unchanged FarmHouse visual post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    streams = (STREAMS[arguments.stream],) if arguments.stream is not None else STREAMS
    for stream in streams:
        source = bytearray(decoded(rom, arguments.region, stream))
        for index, value in enumerate(source):
            for mask in (1, 2, 4, 8, 16, 32, 64, 128):
                source[index] = value ^ mask
                try:
                    result = rebuild(bytes(source), packed(rom, arguments.region, stream), stream)
                except ValueError:
                    source[index] = value
                    continue
                payload, format_spec, ladder = unpack(result)
                if bytes(payload) != bytes(source) or format_spec != stream.format_spec:
                    raise AssertionError(f"edited {stream.source_name} did not strictly round-trip")
                print(f"FarmHouse edit test: {stream.source_name} byte {index:#x} xor {mask:#x}; packed {len(result):#x} bytes")
                return
            source[index] = value
    raise AssertionError("no deterministic in-place FarmHouse visual edit fits any fixed retail stream")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    verify_parser.add_argument("--rom", type=Path, required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    edit_parser.add_argument("--stream", type=int, choices=range(len(STREAMS)), help="test one descriptor stream")
    arguments = parser.parse_args()
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

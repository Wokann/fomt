#!/usr/bin/env python3
"""Manage the four verified BG streams loaded by ``func_080A2BA4``.

The routine clears BG screen blocks at VRAM ``0x0600E000`` through
``0x0600F000`` and then loads three 32-by-20 native tilemaps there.  Its
fourth stream is copied to BG character memory at ``0x06000000`` and decodes
to exactly 160 4bpp tiles.  The nearby palette copy overlaps an indexed
resource archive, so this tool deliberately keeps only the proven native tile
and tilemap sources; it does not manufacture a coloured composite PNG.
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
    name: str
    offset: int
    length: int
    decoded_size: int
    format_spec: str
    ladder: str


STARTS = {
    "jp": 0x4D5430,
    "us": 0x74EF14,
    "eu": 0x74EF70,
    "de": 0x4D6380,
}
SPECS = (
    ("layer_0.tilemap", 0x28, 0x500, "030", "125"),
    ("layer_1.tilemap", 0xB0, 0x500, "020", "1234679"),
    ("layer_2.tilemap", 0x64, 0x500, "020", "1234679"),
    ("tiles.4bpp", 0x29C, 0x1400, "020", "125681012"),
)


def streams(region: str) -> tuple[Stream, ...]:
    cursor = STARTS[region]
    result: list[Stream] = []
    for name, length, decoded_size, format_spec, ladder in SPECS:
        result.append(Stream(name, cursor, length, decoded_size, format_spec, ladder))
        cursor += length
    return tuple(result)


def packed(rom: bytes, stream: Stream) -> bytes:
    result = rom[stream.offset:stream.offset + stream.length]
    if len(result) != stream.length:
        raise ValueError(f"{stream.name} exceeds ROM bounds")
    return result


def decoded(rom: bytes, stream: Stream) -> bytes:
    payload, format_spec, ladder = unpack(packed(rom, stream))
    if len(payload) != stream.decoded_size or format_spec != stream.format_spec or ladder != stream.ladder:
        raise ValueError(
            f"{stream.name}: decoded {len(payload):#x} bytes / {format_spec}/{ladder}; "
            f"expected {stream.decoded_size:#x} / {stream.format_spec}/{stream.ladder}"
        )
    return bytes(payload)


def source_path(source_dir: Path, stream: Stream) -> Path:
    return source_dir / stream.name


def output_path(output_dir: Path, stream: Stream) -> Path:
    return output_dir / f"{stream.name}.0x70"


def region_output_dir(output_root: Path, region: str) -> Path:
    return output_root / region / "graphics" / "ui" / "scene_080a2ba4"


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STARTS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for index, jp_stream in enumerate(streams("jp")):
        entries = {region: streams(region)[index] for region in STARTS}
        packed_hashes = {
            region: hashlib.sha256(packed(inputs[region], stream)).digest()
            for region, stream in entries.items()
        }
        payloads = {region: decoded(inputs[region], stream) for region, stream in entries.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"{jp_stream.name} differs across retail regions; refusing shared source")
        output = source_path(arguments.source_dir, jp_stream)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.write_bytes(payloads["jp"])
    print(f"exported {len(SPECS)} shared native sources for func_080A2BA4")


def rebuild(source: bytes, baseline: bytes, stream: Stream) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if bytes(original) != source:
        encoded = encode_raw_lz(source, int(format_spec[1]), ladder)
        if len(encoded) > len(baseline):
            raise ValueError(
                f"edited {stream.name} needs {len(encoded):#x} bytes; "
                f"its native slot holds only {len(baseline):#x}"
            )
        result = encoded + bytes(len(baseline) - len(encoded))
    else:
        result = baseline
    payload, checked_format, checked_ladder = unpack(result)
    if bytes(payload) != source or checked_format != stream.format_spec or checked_ladder != stream.ladder:
        raise AssertionError(f"{stream.name} failed strict native decode validation")
    return result


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream)
        payload = source.read_bytes()
        if len(payload) != stream.decoded_size:
            raise ValueError(f"{source} must be exactly {stream.decoded_size:#x} bytes")
        output_path(arguments.output_dir, stream).write_bytes(rebuild(payload, packed(rom, stream), stream))
    print(f"rebuilt {len(SPECS)} func_080A2BA4 streams for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    for stream in streams(arguments.region):
        source = source_path(arguments.source_dir, stream).read_bytes()
        baseline = packed(rom, stream)
        rebuilt = rebuild(source, baseline, stream)
        if rebuilt != baseline:
            raise AssertionError(f"{stream.name} no longer matches retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None and output_path(arguments.output_dir, stream).read_bytes() != baseline:
            raise AssertionError(f"built {stream.name} does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(SPECS)} func_080A2BA4 streams against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, outputs: Path, region: str) -> bytes:
    patched = bytearray(target)
    for stream in streams(region):
        generated = output_path(outputs, stream).read_bytes()
        if len(generated) != stream.length:
            raise ValueError(f"generated {stream.name} has {len(generated):#x} bytes; expected {stream.length:#x}")
        current = target[stream.offset:stream.offset + stream.length]
        expected = packed(baseline, stream)
        if current != expected and current != generated:
            raise ValueError(f"target {stream.name} differs from both retail baseline and generated bytes")
        patched[stream.offset:stream.offset + stream.length] = generated
    return bytes(patched)


def patch(arguments: argparse.Namespace) -> None:
    target_path = arguments.rom
    target_path.write_bytes(apply(
        target_path.read_bytes(), arguments.baseline.read_bytes(), arguments.output_dir, arguments.region
    ))
    print(f"patched {len(SPECS)} func_080A2BA4 streams into {target_path} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        result = apply(baseline, baseline, region_output_dir(arguments.output_root, region), region)
        if result != baseline:
            raise AssertionError(f"unchanged func_080A2BA4 patch differs from retail {region.upper()} ROM")
    print("verified unchanged func_080A2BA4 post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    # Retail streams have finite in-place slots. Search a small deterministic
    # edit rather than claiming every arbitrary edit will fit that slot.
    for stream in streams(arguments.region):
        source = bytearray(decoded(rom, stream))
        for index, value in enumerate(source):
            for mask in (1, 2, 4, 8, 16, 32, 64, 128):
                edited = bytearray(source)
                edited[index] = value ^ mask
                try:
                    rebuilt = rebuild(bytes(edited), packed(rom, stream), stream)
                except ValueError:
                    continue
                payload, _format, _ladder = unpack(rebuilt)
                if bytes(payload) != bytes(edited) or rebuilt == packed(rom, stream):
                    raise AssertionError("edited func_080A2BA4 stream did not strictly round-trip")
                print(
                    f"func_080A2BA4 edit test: {stream.name} byte {index:#x} xor {mask:#x}; "
                    f"packed {len(rebuilt):#x} bytes"
                )
                return
    raise AssertionError("no deterministic in-place edit fits any func_080A2BA4 stream")


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
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=tuple(STARTS), required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
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
    elif arguments.command == "patch":
        patch(arguments)
    elif arguments.command == "patch-test":
        patch_test(arguments)
    else:
        edit_test(arguments)


if __name__ == "__main__":
    main()

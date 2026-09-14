#!/usr/bin/env python3
"""Manage profiles of verified three-stream native BG scene resources.

The code loads two 32-by-32 background tilemaps and one native 4bpp tile
stream.  A nearby 0x200-byte palette-memory copy crosses an existing assembly
boundary into unclassified data, so it intentionally remains unmanaged.
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


PROFILES = {
    "080b7164": (
        {
            "jp": 0x4B3734, "us": 0x72D5CC,
            "eu": 0x72D628, "de": 0x4B48A0,
        },
        (
            ("layer_0.tilemap", 0x64, 0x800, "030", "357"),
            ("layer_1.tilemap", 0xA8, 0x800, "030", "159"),
            ("tiles.4bpp", 0x70C, 0xEC0, "020", "2578101112"),
        ),
    ),
    "080c160c": (
        {
            "jp": 0x4C5530, "us": 0x73F3C8,
            "eu": 0x73F424, "de": 0x4C683C,
        },
        (
            ("layer_0.tilemap", 0x20C, 0x800, "020", "236791011"),
            ("layer_1.tilemap", 0xD8, 0x800, "030", "379"),
            ("tiles.4bpp", 0xA38, 0xE80, "020", "246781012"),
        ),
    ),
    "080bcfac": (
        {
            "jp": 0x4C1F8C, "us": 0x73BE24,
            "eu": 0x73BE80, "de": 0x4C3190,
        },
        (
            ("layer_0.tilemap", 0x124, 0x800, "030", "2610"),
            ("layer_1.tilemap", 0xA8, 0x800, "030", "169"),
            ("tiles.4bpp", 0xC04, 0x7BE2, "020", "256791113"),
        ),
    ),
    "080b55d0_aux": (
        {
            "jp": 0x4B2738, "us": 0x72C5D0,
            "eu": 0x72C62C, "de": 0x4B38A4,
        },
        (
            ("layer_0.tilemap", 0x16C, 0x800, "030", "125"),
            ("layer_1.tilemap", 0x110, 0x800, "030", "159"),
            ("tiles.4bpp", 0xD60, 0x1180, "020", "2589101112"),
        ),
    ),
}
PROFILE = "080b7164"
STARTS, SPECS = PROFILES[PROFILE]


def configure(profile: str) -> None:
    global PROFILE, STARTS, SPECS
    PROFILE = profile
    STARTS, SPECS = PROFILES[profile]


def scene_name() -> str:
    return f"func_{PROFILE.upper()}"


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
    return output_root / region / "graphics" / "ui" / f"scene_{PROFILE}"


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(STARTS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for index, jp_stream in enumerate(streams("jp")):
        entries = {region: streams(region)[index] for region in STARTS}
        packed_hashes = {region: hashlib.sha256(packed(inputs[region], stream)).digest() for region, stream in entries.items()}
        payloads = {region: decoded(inputs[region], stream) for region, stream in entries.items()}
        if len(set(packed_hashes.values())) != 1 or len(set(payloads.values())) != 1:
            raise ValueError(f"{jp_stream.name} differs across retail regions; refusing shared source")
        output = source_path(arguments.source_dir, jp_stream)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.write_bytes(payloads["jp"])
    print(f"exported {len(SPECS)} shared native sources for {scene_name()}")


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
        source = source_path(arguments.source_dir, stream).read_bytes()
        if len(source) != stream.decoded_size:
            raise ValueError(f"{source_path(arguments.source_dir, stream)} must be exactly {stream.decoded_size:#x} bytes")
        output_path(arguments.output_dir, stream).write_bytes(rebuild(source, packed(rom, stream), stream))
    print(f"rebuilt {len(SPECS)} {scene_name()} streams for {arguments.region.upper()}")


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
    print(f"verified {len(SPECS)} {scene_name()} streams against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, outputs: Path, region: str) -> bytes:
    patched = bytearray(target)
    for stream in streams(region):
        generated = output_path(outputs, stream).read_bytes()
        expected = packed(baseline, stream)
        current = target[stream.offset:stream.offset + stream.length]
        if len(generated) != stream.length:
            raise ValueError(f"generated {stream.name} has incorrect length")
        if current != expected and current != generated:
            raise ValueError(f"target {stream.name} differs from both retail baseline and generated bytes")
        patched[stream.offset:stream.offset + stream.length] = generated
    return bytes(patched)


def patch(arguments: argparse.Namespace) -> None:
    target_path = arguments.rom
    target_path.write_bytes(apply(
        target_path.read_bytes(), arguments.baseline.read_bytes(), arguments.output_dir, arguments.region
    ))
    print(f"patched {len(SPECS)} {scene_name()} streams into {target_path} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        result = apply(baseline, baseline, region_output_dir(arguments.output_root, region), region)
        if result != baseline:
            raise AssertionError(f"unchanged {scene_name()} patch differs from retail {region.upper()} ROM")
    print(f"verified unchanged {scene_name()} post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
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
                    raise AssertionError(f"edited {scene_name()} stream did not strictly round-trip")
                print(f"{scene_name()} edit test: {stream.name} byte {index:#x} xor {mask:#x}; packed {len(rebuilt):#x} bytes")
                return
    raise AssertionError(f"no deterministic in-place edit fits any {scene_name()} stream")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--profile", choices=tuple(PROFILES), default=PROFILE)
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
    configure(arguments.profile)
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

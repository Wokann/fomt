#!/usr/bin/env python3
"""Manage FarmHouse descriptor tilemap-patch source buffers.

Each ``FarmHouseVisualDescriptor`` begins with a
``FieldRenderRectDescriptor``.  ``func_080A5BD8`` copies its non-null source
buffers as native 16-bit tilemap rows into live field layers.  The source
length is therefore proven by ``width * height * 2``; it is not inferred from
the neighbouring ROM label.  This tool exports those 14 bounded buffers as
native ``.tilemap`` sources, rebuilds them verbatim, and applies them only at
the original region-specific pointers recorded in the retail descriptor
table.

The descriptor lookup value/index arrays and palette domains are deliberately
outside this scope: their complete independent bounds and higher-level visual
semantics have not yet been proven.
"""

from __future__ import annotations

import argparse
import hashlib
from dataclasses import dataclass
from pathlib import Path


ROM_BASE = 0x08000000
VISUAL_TABLE_OFFSET = 0x128
VISUAL_DESCRIPTOR_SIZE = 0x2C
DESCRIPTOR_COUNT = 7
SOURCE_BUFFER_OFFSET = 0x04
SOURCE_BUFFER_COUNT = 3
TABLE_BASES = {
    "jp": 0x106C24,
    "us": 0x1070DC,
    "eu": 0x107134,
    "de": 0x107B00,
}


@dataclass(frozen=True)
class TilemapPatch:
    descriptor: int
    buffer: int
    width: int
    height: int
    offsets: dict[str, int]

    @property
    def length(self) -> int:
        return self.width * self.height * 2

    @property
    def name(self) -> str:
        return f"patch_{self.descriptor:02d}_buffer_{self.buffer}.tilemap"


def parse_region(rom: bytes, region: str) -> dict[tuple[int, int], tuple[int, int, int]]:
    table = TABLE_BASES[region] + VISUAL_TABLE_OFFSET
    result: dict[tuple[int, int], tuple[int, int, int]] = {}
    for descriptor in range(DESCRIPTOR_COUNT):
        offset = table + descriptor * VISUAL_DESCRIPTOR_SIZE
        width, height = rom[offset], rom[offset + 1]
        if width == 0 or height == 0:
            raise ValueError(f"{region.upper()} descriptor {descriptor}: invalid empty dimensions")
        for buffer in range(SOURCE_BUFFER_COUNT):
            pointer = int.from_bytes(
                rom[offset + SOURCE_BUFFER_OFFSET + buffer * 4:offset + SOURCE_BUFFER_OFFSET + (buffer + 1) * 4],
                "little",
            )
            if pointer == 0:
                continue
            if not ROM_BASE <= pointer < ROM_BASE + len(rom):
                raise ValueError(
                    f"{region.upper()} descriptor {descriptor} buffer {buffer}: invalid ROM pointer {pointer:#010x}"
                )
            length = width * height * 2
            source = pointer - ROM_BASE
            if source + length > len(rom):
                raise ValueError(f"{region.upper()} descriptor {descriptor} buffer {buffer}: source exceeds ROM")
            result[(descriptor, buffer)] = (width, height, source)
    return result


def catalog(inputs: dict[str, bytes]) -> tuple[TilemapPatch, ...]:
    if set(inputs) != set(TABLE_BASES):
        raise ValueError("requires exactly jp, us, eu and de ROMs")
    parsed = {region: parse_region(rom, region) for region, rom in inputs.items()}
    signatures = set(parsed["jp"])
    for region, values in parsed.items():
        if set(values) != signatures:
            raise ValueError(f"{region.upper()} FarmHouse source-buffer membership differs from JP")

    patches: list[TilemapPatch] = []
    for descriptor, buffer in sorted(signatures):
        dimensions = {(values[(descriptor, buffer)][0], values[(descriptor, buffer)][1]) for values in parsed.values()}
        if len(dimensions) != 1:
            raise ValueError(f"FarmHouse descriptor {descriptor} buffer {buffer}: regional dimensions differ")
        width, height = next(iter(dimensions))
        offsets = {region: values[(descriptor, buffer)][2] for region, values in parsed.items()}
        patch = TilemapPatch(descriptor, buffer, width, height, offsets)
        payload_hashes = {
            hashlib.sha256(inputs[region][offset:offset + patch.length]).digest()
            for region, offset in offsets.items()
        }
        if len(payload_hashes) != 1:
            raise ValueError(f"FarmHouse descriptor {descriptor} buffer {buffer}: retail payloads differ")
        patches.append(patch)
    return tuple(patches)


def source_path(source_dir: Path, patch: TilemapPatch) -> Path:
    return source_dir / patch.name


def output_path(output_dir: Path, patch: TilemapPatch) -> Path:
    return output_dir / patch.name


def payload(rom: bytes, region: str, patch: TilemapPatch) -> bytes:
    offset = patch.offsets[region]
    result = rom[offset:offset + patch.length]
    if len(result) != patch.length:
        raise AssertionError(f"{region.upper()} {patch.name}: source bounds changed")
    return result


def checked_source(source_dir: Path, patch: TilemapPatch) -> bytes:
    source = source_path(source_dir, patch).read_bytes()
    if len(source) != patch.length:
        raise ValueError(f"{source_path(source_dir, patch)} must be exactly {patch.length:#x} bytes")
    return source


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    for patch in catalog(inputs):
        source = source_path(arguments.source_dir, patch)
        if source.exists() and not arguments.replace:
            raise ValueError(f"{source} exists; use --replace to refresh it")
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_bytes(payload(inputs["jp"], "jp", patch))
    print("exported 14 shared FarmHouse native tilemap patch sources")


def build(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.all_rom}
    patches = catalog(inputs)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for patch in patches:
        output_path(arguments.output_dir, patch).write_bytes(checked_source(arguments.source_dir, patch))
    print(f"rebuilt {len(patches)} FarmHouse tilemap patches for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.all_rom}
    patches = catalog(inputs)
    rom = inputs[arguments.region]
    for patch in patches:
        source = checked_source(arguments.source_dir, patch)
        baseline = payload(rom, arguments.region, patch)
        if source != baseline:
            raise AssertionError(f"unchanged {patch.name} does not reproduce retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None and output_path(arguments.output_dir, patch).read_bytes() != baseline:
            raise AssertionError(f"built {patch.name} does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(patches)} FarmHouse tilemap patches against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, region: str, patches: tuple[TilemapPatch, ...], output_dir: Path) -> bytes:
    result = bytearray(target)
    for patch in patches:
        generated = output_path(output_dir, patch).read_bytes()
        expected = payload(baseline, region, patch)
        offset = patch.offsets[region]
        if len(generated) != patch.length:
            raise ValueError(f"generated {patch.name} has incorrect length")
        current = target[offset:offset + patch.length]
        if current != expected and current != generated:
            raise ValueError(f"target {patch.name} differs from both retail baseline and generated bytes")
        result[offset:offset + patch.length] = generated
    return bytes(result)


def patch(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.all_rom}
    patches = catalog(inputs)
    baseline = arguments.baseline.read_bytes()
    target = arguments.rom.read_bytes()
    arguments.rom.write_bytes(apply(target, baseline, arguments.region, patches, arguments.output_dir))
    print(f"patched {len(patches)} FarmHouse tilemap patches into {arguments.rom} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    patches = catalog(inputs)
    for region, baseline in inputs.items():
        output_dir = arguments.output_root / region / "graphics" / "farm_house_visual_tilemaps"
        if apply(baseline, baseline, region, patches, output_dir) != baseline:
            raise AssertionError(f"unchanged FarmHouse tilemap patch differs from retail {region.upper()} ROM")
    print("verified unchanged FarmHouse tilemap post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    patches = catalog(inputs)
    patch = patches[0]
    changed = bytearray(payload(inputs["jp"], "jp", patch))
    changed[0] ^= 1
    if len(changed) != patch.length:
        raise AssertionError("FarmHouse tilemap edit changed its fixed bounds")
    print(f"FarmHouse tilemap edit test: {patch.name} byte 0x0 xor 0x1; fixed {patch.length:#x}-byte slot")


def add_all_roms(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--all-rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    add_all_roms(build_parser)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    add_all_roms(verify_parser)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    add_all_roms(patch_parser)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
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

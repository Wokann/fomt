#!/usr/bin/env python3
"""Manage FarmHouse descriptor BGR555 palette-source buffers.

For each non-null ``FarmHouseVisualDescriptor.palette_sources`` entry, retail
code calls DMA helper ``func_08008E64`` with exactly
``palette_bank_count * 0x20`` bytes.  The descriptor's adjacent
``palette_bank`` selects the destination 16-colour slot.  This tool exports
the ten four-region-identical streams as native BGR555 ``.gbapal`` files,
copies them to per-region build output, and patches only their proven ROM
ranges after linking.

The sources intentionally remain binary rather than PNG palette swatches:
they are the exact authoring bytes used by the game and have no independent
full-screen layout yet.
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
PALETTE_SOURCE_OFFSET = 0x20
PALETTE_SOURCE_COUNT = 2
PALETTE_BANK_OFFSET = 0x28
PALETTE_BANK_COUNT_OFFSET = 0x29
PALETTE_BANK_BYTES = 0x20
TABLE_BASES = {
    "jp": 0x106C24,
    "us": 0x1070DC,
    "eu": 0x107134,
    "de": 0x107B00,
}


@dataclass(frozen=True)
class PaletteBuffer:
    descriptor: int
    buffer: int
    palette_bank: int
    bank_count: int
    offsets: dict[str, int]

    @property
    def length(self) -> int:
        return self.bank_count * PALETTE_BANK_BYTES

    @property
    def name(self) -> str:
        return f"palette_{self.descriptor:02d}_buffer_{self.buffer}.gbapal"


def pointer_offset(rom: bytes, pointer_offset: int, region: str, descriptor: int, buffer: int) -> int | None:
    pointer = int.from_bytes(rom[pointer_offset:pointer_offset + 4], "little")
    if pointer == 0:
        return None
    if not ROM_BASE <= pointer < ROM_BASE + len(rom):
        raise ValueError(
            f"{region.upper()} descriptor {descriptor} buffer {buffer}: invalid ROM pointer {pointer:#010x}"
        )
    return pointer - ROM_BASE


def parse_region(rom: bytes, region: str) -> dict[tuple[int, int], tuple[int, int, int]]:
    table = TABLE_BASES[region] + VISUAL_TABLE_OFFSET
    result: dict[tuple[int, int], tuple[int, int, int]] = {}
    for descriptor in range(DESCRIPTOR_COUNT):
        record = table + descriptor * VISUAL_DESCRIPTOR_SIZE
        palette_bank = rom[record + PALETTE_BANK_OFFSET]
        bank_count = rom[record + PALETTE_BANK_COUNT_OFFSET]
        if bank_count == 0:
            raise ValueError(f"{region.upper()} descriptor {descriptor}: empty palette bank count")
        for buffer in range(PALETTE_SOURCE_COUNT):
            offset = pointer_offset(
                rom, record + PALETTE_SOURCE_OFFSET + buffer * 4, region, descriptor, buffer
            )
            if offset is None:
                continue
            length = bank_count * PALETTE_BANK_BYTES
            if offset + length > len(rom):
                raise ValueError(f"{region.upper()} descriptor {descriptor} buffer {buffer}: source exceeds ROM")
            result[(descriptor, buffer)] = (palette_bank, bank_count, offset)
    return result


def catalog(inputs: dict[str, bytes]) -> tuple[PaletteBuffer, ...]:
    if set(inputs) != set(TABLE_BASES):
        raise ValueError("requires exactly jp, us, eu and de ROMs")
    parsed = {region: parse_region(rom, region) for region, rom in inputs.items()}
    membership = set(parsed["jp"])
    for region, entries in parsed.items():
        if set(entries) != membership:
            raise ValueError(f"{region.upper()} FarmHouse palette-source membership differs from JP")

    result: list[PaletteBuffer] = []
    for descriptor, buffer in sorted(membership):
        metadata = {(entry[(descriptor, buffer)][0], entry[(descriptor, buffer)][1]) for entry in parsed.values()}
        if len(metadata) != 1:
            raise ValueError(f"descriptor {descriptor} buffer {buffer}: regional palette metadata differs")
        palette_bank, bank_count = next(iter(metadata))
        offsets = {region: entries[(descriptor, buffer)][2] for region, entries in parsed.items()}
        candidate = PaletteBuffer(descriptor, buffer, palette_bank, bank_count, offsets)
        hashes = {
            hashlib.sha256(inputs[region][offset:offset + candidate.length]).digest()
            for region, offset in offsets.items()
        }
        if len(hashes) != 1:
            raise ValueError(f"descriptor {descriptor} buffer {buffer}: retail palette bytes differ")
        result.append(candidate)
    return tuple(result)


def source_path(source_dir: Path, palette: PaletteBuffer) -> Path:
    return source_dir / palette.name


def output_path(output_dir: Path, palette: PaletteBuffer) -> Path:
    return output_dir / palette.name


def payload(rom: bytes, region: str, palette: PaletteBuffer) -> bytes:
    offset = palette.offsets[region]
    value = rom[offset:offset + palette.length]
    if len(value) != palette.length:
        raise AssertionError(f"{region.upper()} {palette.name}: source bounds changed")
    return value


def checked_source(source_dir: Path, palette: PaletteBuffer) -> bytes:
    value = source_path(source_dir, palette).read_bytes()
    if len(value) != palette.length:
        raise ValueError(f"{source_path(source_dir, palette)} must be exactly {palette.length:#x} bytes")
    return value


def read_inputs(arguments: argparse.Namespace, field: str) -> dict[str, bytes]:
    return {region: Path(path).read_bytes() for region, path in getattr(arguments, field)}


def export(arguments: argparse.Namespace) -> None:
    inputs = read_inputs(arguments, "rom")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    for palette in catalog(inputs):
        output = source_path(arguments.source_dir, palette)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.write_bytes(payload(inputs["jp"], "jp", palette))
    print("exported 10 shared FarmHouse native BGR555 palette sources")


def build(arguments: argparse.Namespace) -> None:
    inputs = read_inputs(arguments, "all_rom")
    palettes = catalog(inputs)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    for palette in palettes:
        output_path(arguments.output_dir, palette).write_bytes(checked_source(arguments.source_dir, palette))
    print(f"rebuilt {len(palettes)} FarmHouse palette buffers for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    inputs = read_inputs(arguments, "all_rom")
    palettes = catalog(inputs)
    for palette in palettes:
        source = checked_source(arguments.source_dir, palette)
        baseline = payload(inputs[arguments.region], arguments.region, palette)
        if source != baseline:
            raise AssertionError(f"unchanged {palette.name} does not reproduce retail {arguments.region.upper()} bytes")
        if arguments.output_dir is not None and output_path(arguments.output_dir, palette).read_bytes() != baseline:
            raise AssertionError(f"built {palette.name} does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(palettes)} FarmHouse palette buffers against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, region: str, palettes: tuple[PaletteBuffer, ...], output_dir: Path) -> bytes:
    result = bytearray(target)
    for palette in palettes:
        generated = output_path(output_dir, palette).read_bytes()
        expected = payload(baseline, region, palette)
        offset = palette.offsets[region]
        if len(generated) != palette.length:
            raise ValueError(f"generated {palette.name} has incorrect length")
        current = target[offset:offset + palette.length]
        if current != expected and current != generated:
            raise ValueError(f"target {palette.name} differs from both retail baseline and generated bytes")
        result[offset:offset + palette.length] = generated
    return bytes(result)


def patch(arguments: argparse.Namespace) -> None:
    inputs = read_inputs(arguments, "all_rom")
    palettes = catalog(inputs)
    baseline = arguments.baseline.read_bytes()
    arguments.rom.write_bytes(apply(arguments.rom.read_bytes(), baseline, arguments.region, palettes, arguments.output_dir))
    print(f"patched {len(palettes)} FarmHouse palette buffers into {arguments.rom} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    inputs = read_inputs(arguments, "rom")
    palettes = catalog(inputs)
    for region, baseline in inputs.items():
        output_dir = arguments.output_root / region / "graphics" / "farm_house_visual_palettes"
        if apply(baseline, baseline, region, palettes, output_dir) != baseline:
            raise AssertionError(f"unchanged FarmHouse palette patch differs from retail {region.upper()} ROM")
    print("verified unchanged FarmHouse palette post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    palettes = catalog(read_inputs(arguments, "rom"))
    candidate = palettes[0]
    edited = bytearray(checked_source(arguments.source_dir, candidate))
    edited[0] ^= 1
    if len(edited) != candidate.length:
        raise AssertionError("palette edit changed its fixed source bounds")
    print(f"FarmHouse palette edit test: {candidate.name} byte 0x0 xor 0x1; fixed {candidate.length:#x}-byte slot")


def add_roms(parser: argparse.ArgumentParser, field: str) -> None:
    parser.add_argument(f"--{field.replace('_', '-')}", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    add_roms(export_parser, "rom")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    add_roms(build_parser, "all_rom")
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    add_roms(verify_parser, "all_rom")
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=tuple(TABLE_BASES), required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    add_roms(patch_parser, "all_rom")
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    add_roms(patch_test_parser, "rom")
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--source-dir", type=Path, required=True)
    add_roms(edit_parser, "rom")
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

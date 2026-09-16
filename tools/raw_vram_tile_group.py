#!/usr/bin/env python3
"""Manage directly DMA-loaded native 4bpp tile groups with proven ROM bounds.

The tool deliberately uses a native ``.4bpp`` source when the consuming code
proves a tile range but does not yet prove the palette and OAM/BG layout needed
to make an editable full-image PNG.  It is a lossless source pipeline, not a
layout guesser.
"""

from __future__ import annotations

import argparse
import hashlib
from dataclasses import dataclass
from pathlib import Path


REGIONS = ("jp", "us", "eu", "de")


@dataclass(frozen=True)
class Profile:
    name: str
    offsets: dict[str, int]
    length: int
    sha256: str
    source_name: str
    output_name: str


PROFILES = {
    "08697920": Profile(
        name="gUnk_08697920",
        offsets={"jp": 0x41DA7C, "us": 0x697920, "eu": 0x69797C, "de": 0x41E9BC},
        length=0x11E0,
        sha256="c96ae146f633dd5f3bf42dfb802ff294bdca0f5f4758150ac4896a543914be44",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08698e14": Profile(
        name="gUnk_08698E14",
        offsets={"jp": 0x41EF70, "us": 0x698E14, "eu": 0x698E70, "de": 0x41FEB0},
        length=0x11E0,
        sha256="06b60f66dfabae472ce929a164912c2e88ae4d8c468f6181db5a4304ce50e6bf",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0869a0a4": Profile(
        name="gUnk_0869A0A4",
        offsets={"jp": 0x420200, "us": 0x69A0A4, "eu": 0x69A100, "de": 0x421140},
        length=0x11E0,
        sha256="69f5649e9bcb3da8816bab1a5155e7aecbd7a6757596e32bcdc07ecd199bda45",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "086d5508": Profile(
        name="gUnk_086D5508",
        offsets={"jp": 0x45B664, "us": 0x6D5508, "eu": 0x6D5564, "de": 0x45C5A4},
        length=0xE60,
        sha256="cdc8b2e5448f68894d102c8ca9c672ecd8a18f5932d5a932ff38411619c5ca28",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "086d6698": Profile(
        name="gUnk_086D6698",
        offsets={"jp": 0x45C7F4, "us": 0x6D6698, "eu": 0x6D66F4, "de": 0x45D734},
        length=0xE60,
        sha256="6282b44093e405b3cdcd10a2ca0d6de388705f284cdb4376d6eff47b7f920786",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08750c4c": Profile(
        name="gUnk_08750C4C",
        offsets={"jp": 0x4D6BF8, "us": 0x750C4C, "eu": 0x750CA8, "de": 0x4D8168},
        length=0x20,
        sha256="e98672a456687f9c428628c321ff964b8507028878310d4e3eaebd3cfbe37e49",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08750c8c": Profile(
        name="gUnk_08750C8C",
        offsets={"jp": 0x4D6C38, "us": 0x750C8C, "eu": 0x750CE8, "de": 0x4D81A8},
        length=0x1C0,
        sha256="2b7c39eab1900bb410cced0daa2ffd21055045e47ddcf99f318255775e77ec4f",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "087510ac": Profile(
        name="gUnk_087510AC",
        offsets={"jp": 0x4D7058, "us": 0x7510AC, "eu": 0x751108, "de": 0x4D85C8},
        length=0x120,
        sha256="c477e41b27535552a2455bf44fa3b970cd335c9e5c8fe920f46959f871438583",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0875166c": Profile(
        name="gUnk_0875166C",
        offsets={"jp": 0x4D7618, "us": 0x75166C, "eu": 0x7516C8, "de": 0x4D8B88},
        length=0x120,
        sha256="bbf625be269f793c6bbe13c09ac11bc6f851b41588f4439f921255a9cb15ce1a",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
}


def profile(name: str) -> Profile:
    return PROFILES[name]


def range_from_rom(rom: bytes, region: str, item: Profile) -> bytes:
    offset = item.offsets[region]
    payload = rom[offset:offset + item.length]
    if len(payload) != item.length:
        raise ValueError(f"{item.name}: {region.upper()} range exceeds ROM bounds")
    return payload


def checked_retail(rom: bytes, region: str, item: Profile) -> bytes:
    payload = range_from_rom(rom, region, item)
    if hashlib.sha256(payload).hexdigest() != item.sha256:
        raise ValueError(f"{item.name}: {region.upper()} range differs from the verified retail payload")
    return payload


def source_path(source_dir: Path, item: Profile) -> Path:
    return source_dir / item.source_name


def output_path(output_dir: Path, item: Profile) -> Path:
    return output_dir / item.output_name


def checked_source(source_dir: Path, item: Profile) -> bytes:
    source = source_path(source_dir, item).read_bytes()
    if len(source) != item.length:
        raise ValueError(f"{source_path(source_dir, item)} must be exactly {item.length:#x} bytes")
    return source


def export(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    inputs = {region: path.read_bytes() for region, path in arguments.rom}
    if set(inputs) != set(REGIONS):
        raise ValueError("export requires exactly one JP, US, EU and DE ROM")
    payloads = {region: checked_retail(rom, region, item) for region, rom in inputs.items()}
    if len(set(payloads.values())) != 1:
        raise ValueError(f"{item.name}: regional payloads differ; refusing a shared source")
    destination = source_path(arguments.source_dir, item)
    if destination.exists() and not arguments.replace:
        raise ValueError(f"{destination} exists; pass --replace to refresh it")
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes(payloads["jp"])
    print(f"exported one shared native 4bpp source for {item.name}")


def build(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    source = checked_source(arguments.source_dir, item)
    # Always validate the selected baseline range. The editable source may
    # differ from it, but the target location must remain the proven one.
    checked_retail(arguments.rom.read_bytes(), arguments.region, item)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    output_path(arguments.output_dir, item).write_bytes(source)
    print(f"rebuilt {item.name} native tile range for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    source = checked_source(arguments.source_dir, item)
    baseline = checked_retail(arguments.rom.read_bytes(), arguments.region, item)
    if source != baseline:
        raise AssertionError(f"{item.name}: source no longer reproduces retail {arguments.region.upper()} bytes")
    if arguments.output_dir is not None and output_path(arguments.output_dir, item).read_bytes() != baseline:
        raise AssertionError(f"{item.name}: built output differs from retail {arguments.region.upper()} bytes")
    print(f"verified {item.name} against {arguments.region.upper()} ROM")


def apply_payload(target: bytes, baseline: bytes, generated: bytes, region: str, item: Profile) -> bytes:
    if len(generated) != item.length:
        raise ValueError(f"{item.name}: generated tile range has an invalid size")
    offset = item.offsets[region]
    expected = checked_retail(baseline, region, item)
    current = target[offset:offset + item.length]
    if current != expected and current != generated:
        raise ValueError(f"{item.name}: target differs from both retail baseline and generated bytes")
    result = bytearray(target)
    result[offset:offset + item.length] = generated
    return bytes(result)


def apply(target: bytes, baseline: bytes, output_dir: Path, region: str, item: Profile) -> bytes:
    return apply_payload(target, baseline, output_path(output_dir, item).read_bytes(), region, item)


def patch(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    target = arguments.rom.read_bytes()
    result = apply(target, arguments.baseline.read_bytes(), arguments.output_dir, arguments.region, item)
    arguments.rom.write_bytes(result)
    print(f"patched {item.name} into {arguments.rom} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    for region, path in arguments.rom:
        baseline = path.read_bytes()
        output_dir = arguments.output_root / region / "graphics" / "ui" / "raw_vram_tiles" / arguments.profile
        if apply(baseline, baseline, output_dir, region, item) != baseline:
            raise AssertionError(f"{item.name}: unchanged {region.upper()} ROM patch differs from retail bytes")
    print(f"verified unchanged {item.name} post-link patches against all four retail ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    baseline = arguments.rom.read_bytes()
    original = checked_retail(baseline, arguments.region, item)
    edited = bytearray(original)
    index = next(index for index, value in enumerate(edited) if value)
    edited[index] ^= 1
    if len(edited) != item.length or edited == original:
        raise AssertionError(f"{item.name}: native edit fixture did not preserve the exact range")
    result = apply_payload(baseline, baseline, bytes(edited), arguments.region, item)
    offset = item.offsets[arguments.region]
    if (result[:offset] != baseline[:offset]
            or result[offset:offset + item.length] != bytes(edited)
            or result[offset + item.length:] != baseline[offset + item.length:]):
        raise AssertionError(f"{item.name}: native edit escaped its proven fixed range")
    print(f"{item.name} edit test: byte {index:#x}; fixed {item.length:#x}-byte native tile range")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--region", choices=REGIONS, required=True)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        command.add_argument("--output-dir", type=Path)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=REGIONS, required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=REGIONS, required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        regions = [region for region, _path in arguments.rom]
        if len(set(regions)) != len(regions) or set(regions) != set(REGIONS):
            raise ValueError("export ROM arguments must name JP, US, EU and DE exactly once")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    elif arguments.command == "patch-test":
        regions = [region for region, _path in arguments.rom]
        if len(set(regions)) != len(regions) or set(regions) != set(REGIONS):
            raise ValueError("patch-test ROM arguments must name JP, US, EU and DE exactly once")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        if arguments.output_dir is None:
            raise ValueError("build requires --output-dir")
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

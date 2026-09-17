#!/usr/bin/env python3
"""Manage directly DMA-loaded native graphics records with proven ROM bounds.

The tool deliberately uses a native ``.4bpp`` source when the consuming code
proves a tile range but does not yet prove the palette and OAM/BG layout needed
to make an editable full-image PNG.  It also preserves direct BGR555 palette
records as ``.gbapal`` when that is what the consumer proves. It is a lossless
source pipeline, not a layout guesser.
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
    "087517ac": Profile(
        name="gUnk_087517AC",
        offsets={"jp": 0x4D7758, "us": 0x7517AC, "eu": 0x751808, "de": 0x4D8CC8},
        length=0x120,
        sha256="c7a0b84c724745c4430e04c21fa72ebca8a52e9b769c2190ae01c21be4f5d89e",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0875178c": Profile(
        name="gUnk_0875178C",
        offsets={"jp": 0x4D7738, "us": 0x75178C, "eu": 0x7517E8, "de": 0x4D8CA8},
        length=0x20,
        sha256="786cebe9ac9654a40caf028be177f840f8737b11fd1e5c6da5609f867ae48da4",
        source_name="palette.gbapal",
        output_name="palette.gbapal",
    ),
    "08750f8c": Profile(
        name="gUnk_08750F8C",
        offsets={"jp": 0x4D6F38, "us": 0x750F8C, "eu": 0x750FE8, "de": 0x4D84A8},
        length=0x120,
        sha256="fc2bda977d99c32f7fe6f8e480a47193d891ff65946dcbbbba85162e4146a331",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08750f6c": Profile(
        name="gUnk_08750F6C",
        offsets={"jp": 0x4D6F18, "us": 0x750F6C, "eu": 0x750FC8, "de": 0x4D8488},
        length=0x20,
        sha256="9985d2bb7b07b88d53543f5ab323df57ac3eb3402671d800405dfdf4f9c18237",
        source_name="palette.gbapal",
        output_name="palette.gbapal",
    ),
    "08750e4c": Profile(
        name="gUnk_08750E4C",
        offsets={"jp": 0x4D6DF8, "us": 0x750E4C, "eu": 0x750EA8, "de": 0x4D8368},
        length=0x120,
        sha256="a3b99c81ab8bac0912cd6c7d928f34f9bb739630701489b284e7ebf8e7fd047d",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "087511cc": Profile(
        name="gUnk_087511CC",
        offsets={"jp": 0x4D7178, "us": 0x7511CC, "eu": 0x751228, "de": 0x4D86E8},
        length=0x120,
        sha256="0246e5f8a7ce9136217957ade7c5cfdbd2aa7be7f208a419b15a768c18963f75",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0875154c": Profile(
        name="gUnk_0875154C",
        offsets={"jp": 0x4D74F8, "us": 0x75154C, "eu": 0x7515A8, "de": 0x4D8A68},
        length=0x120,
        sha256="acfc397f1fb7813b07fd714a306bb890cc4ccec2b94cee6ff10754408c7cebf6",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0875130c": Profile(
        name="gUnk_0875130C",
        offsets={"jp": 0x4D72B8, "us": 0x75130C, "eu": 0x751368, "de": 0x4D8828},
        length=0x120,
        sha256="b078a388eb2836e81fa338079b4185f05f6a0f635ed977b2e1d8052a72b78777",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "0875142c": Profile(
        name="gUnk_0875142C",
        offsets={"jp": 0x4D73D8, "us": 0x75142C, "eu": 0x751488, "de": 0x4D8948},
        length=0x120,
        sha256="aa637cc310aea66cedff57eb3080b430e380c20703184036a73c2f87eba97dbb",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752dcc": Profile(
        name="gUnk_08752DCC",
        offsets={"jp": 0x4D8D78, "us": 0x752DCC, "eu": 0x752E28, "de": 0x4DA2E8},
        length=0x20,
        sha256="edfe3b0dfa05ba559f7edb9dadc37610f2d68962dee6ebe21f4236e2da72f434",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752b4c": Profile(
        name="gUnk_08752B4C",
        offsets={"jp": 0x4D8AF8, "us": 0x752B4C, "eu": 0x752BA8, "de": 0x4DA068},
        length=0x20,
        sha256="fd2f2ed59600716e8751a9a95cd3a57e3305878909400c20a0790044862f38fd",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "087529ac": Profile(
        name="gUnk_087529AC",
        offsets={"jp": 0x4D8958, "us": 0x7529AC, "eu": 0x752A08, "de": 0x4D9EC8},
        length=0x20,
        sha256="e65a24b3b2280d111ba0d1236b82953023ef8eb4fc099ea4b3af5350d9c27214",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752d4c": Profile(
        name="gUnk_08752D4C",
        offsets={"jp": 0x4D8CF8, "us": 0x752D4C, "eu": 0x752DA8, "de": 0x4DA268},
        length=0x80,
        sha256="bbed8d40d3b50a112b0044f5cb15532a8373cd3979856ca2d420d71d65ae5dcf",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752acc": Profile(
        name="gUnk_08752ACC",
        offsets={"jp": 0x4D8A78, "us": 0x752ACC, "eu": 0x752B28, "de": 0x4D9FE8},
        length=0x80,
        sha256="544c753c94d191908294f5db94a19d1cec38b880dbc83c1bd46e53d38a8d7004",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752a2c": Profile(
        name="gUnk_08752A2C",
        offsets={"jp": 0x4D89D8, "us": 0x752A2C, "eu": 0x752A88, "de": 0x4D9F48},
        length=0x20,
        sha256="1eb989f756d8a797e4c33dbb012c7d4f1a3637dab164e4eab9fd867edfd2d532",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752aac": Profile(
        name="gUnk_08752AAC",
        offsets={"jp": 0x4D8A58, "us": 0x752AAC, "eu": 0x752B08, "de": 0x4D9FC8},
        length=0x20,
        sha256="16651959cfb2129a001de5974a24772259962d7e5d22e88096280f1c57371186",
        source_name="palette.gbapal",
        output_name="palette.gbapal",
    ),
    "08752ccc": Profile(
        name="gUnk_08752CCC",
        offsets={"jp": 0x4D8C78, "us": 0x752CCC, "eu": 0x752D28, "de": 0x4DA1E8},
        length=0x20,
        sha256="7ad0e85a313266549b865f289aed4f47dcfbd36e5d28ab1270b3729a86d0f5be",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752bcc": Profile(
        name="gUnk_08752BCC",
        offsets={"jp": 0x4D8B78, "us": 0x752BCC, "eu": 0x752C28, "de": 0x4DA0E8},
        length=0x20,
        sha256="bd19e0c23ddca6d07e9306ef5a9ba2c4f906e6e5aa6c1b4c45b0db65125e3ae8",
        source_name="tiles.4bpp",
        output_name="tiles.4bpp",
    ),
    "08752c4c": Profile(
        name="gUnk_08752C4C",
        offsets={"jp": 0x4D8BF8, "us": 0x752C4C, "eu": 0x752CA8, "de": 0x4DA168},
        length=0x20,
        sha256="7cfc23dbe168b6540cfde63d355a87a45bcbff5d940529924641f9e1fdddb4c3",
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
    print(f"exported one shared native {item.source_name} source for {item.name}")


def build(arguments: argparse.Namespace) -> None:
    item = profile(arguments.profile)
    source = checked_source(arguments.source_dir, item)
    # Always validate the selected baseline range. The editable source may
    # differ from it, but the target location must remain the proven one.
    checked_retail(arguments.rom.read_bytes(), arguments.region, item)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    output_path(arguments.output_dir, item).write_bytes(source)
    print(f"rebuilt {item.name} native record for {arguments.region.upper()}")


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
        raise ValueError(f"{item.name}: generated native record has an invalid size")
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
    print(f"{item.name} edit test: byte {index:#x}; fixed {item.length:#x}-byte native record")


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

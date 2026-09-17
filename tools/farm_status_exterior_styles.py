#!/usr/bin/env python3
"""Round-trip Farm Status exterior-style tile groups without layout sidecars.

``func_0806EC94`` selects one contiguous style from each raw resource and
copies it into the Farm Status BG tile grid.  Each four-byte header is native
little-endian ``u16 tiles_per_style, u16 style_count``.  The three resource
families and their tile order are proven by the exact VRAM copies and by the
Farm Status BG maps:

* doghouse: four tiles per style, mapped as a 2-by-2 block at tile IDs 22-25;
* mailbox: two tiles per style, mapped as a 1-by-2 block at tile IDs 26-27;
* window: twenty-two tiles per style, mapped as an 11-by-2 block at IDs 0-21.

The editable PNGs are therefore native tile-order images, not guessed scene
composites.  They share bank 5 of the verified Farm Status base palette.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import decode, encode, read_png, write_png


@dataclass(frozen=True)
class StyleGroup:
    name: str
    tiles_per_style: int
    styles: int
    width: int
    offsets: dict[str, int]
    expected_sha256: str

    @property
    def length(self) -> int:
        return 4 + self.tiles_per_style * self.styles * 32

    @property
    def style_height(self) -> int:
        return self.tiles_per_style * 64 // self.width


GROUPS = (
    StyleGroup("doghouse", 4, 3, 16, {
        "jp": 0x2AFAF0, "us": 0x529994, "eu": 0x5299F0, "de": 0x2B0A30,
    }, "a7c34975c02f06e89a39353d17f6c8c67e7e8d4ad360727f9cf8e99acec3b622"),
    StyleGroup("mailbox", 2, 3, 8, {
        "jp": 0x2AFD04, "us": 0x529BA8, "eu": 0x529C04, "de": 0x2B0C44,
    }, "caeb2b633ac9b0fbc84e26a98782eb9be5151858db261644b554b78b869f77b9"),
    StyleGroup("window", 22, 3, 88, {
        "jp": 0x2AFF00, "us": 0x529DA4, "eu": 0x529E00, "de": 0x2B0E40,
    }, "0359dcc45d94bbf97eeb46d71a3f529a32a16a8abc49d9eba794ccb250668078"),
)


def group_bytes(rom: bytes, group: StyleGroup, region: str) -> bytes:
    result = rom[group.offsets[region]:group.offsets[region] + group.length]
    if len(result) != group.length:
        raise ValueError(f"{region} {group.name} leaves the ROM")
    return result


def validate_native(group: StyleGroup, data: bytes) -> None:
    if len(data) != group.length:
        raise ValueError(f"{group.name} must be exactly {group.length:#x} bytes")
    if hashlib.sha256(data).hexdigest() != group.expected_sha256:
        raise ValueError(f"{group.name} physical range hash mismatch")
    if int.from_bytes(data[:2], "little") != group.tiles_per_style:
        raise ValueError(f"{group.name} tiles-per-style header mismatch")
    if int.from_bytes(data[2:4], "little") != group.styles:
        raise ValueError(f"{group.name} style-count header mismatch")


def bank_five_colors(palette_source: Path):
    indexes, width, height, colors = read_png(palette_source, 8)
    if (width, height) != (256, 8) or indexes != bytes(range(256)) * 8:
        raise ValueError("base palette source must retain its verified 256x8 swatch layout")
    return colors[5 * 16:6 * 16]


def export_group(group: StyleGroup, data: bytes, source_dir: Path, colors, replace: bool) -> None:
    validate_native(group, data)
    for style in range(group.styles):
        target = source_dir / group.name / f"style_{style:02d}.png"
        if target.exists() and not replace:
            raise ValueError(f"{target} exists; pass --replace to overwrite it")
        start = 4 + style * group.tiles_per_style * 32
        pixels, height = decode(data[start:start + group.tiles_per_style * 32], group.width, 4)
        if height != group.style_height:
            raise ValueError(f"{group.name} exported to an unexpected height")
        write_png(target, pixels, group.width, height, colors)


def build_group(group: StyleGroup, source_dir: Path) -> bytes:
    result = bytearray(group.tiles_per_style.to_bytes(2, "little") + group.styles.to_bytes(2, "little"))
    for style in range(group.styles):
        source = source_dir / group.name / f"style_{style:02d}.png"
        pixels, width, height, _colors = read_png(source, 4)
        if (width, height) != (group.width, group.style_height):
            raise ValueError(
                f"{source} must be {group.width}x{group.style_height}, got {width}x{height}"
            )
        encoded = encode(pixels, width, height, 4)
        if len(encoded) != group.tiles_per_style * 32:
            raise ValueError(f"{source} does not contain exactly one {group.name} style")
        result.extend(encoded)
    if len(result) != group.length:
        raise ValueError(f"{group.name} build changed its native range length")
    return bytes(result)


def verify_region(region: str, rom: Path, source_dir: Path, output_dir: Path) -> None:
    rom_bytes = rom.read_bytes()
    for group in GROUPS:
        native = group_bytes(rom_bytes, group, region)
        if native != build_group(group, source_dir):
            raise ValueError(f"{region} {group.name} rebuilt bytes differ from its ROM range")
        output = output_dir / f"{group.name}.4bpp"
        if output.exists() and output.read_bytes() != native:
            raise ValueError(f"{region} {output} differs from its ROM range")
    print(f"verified {region} Farm Status exterior styles ({len(GROUPS)} native ranges)")


def edit_test(source_dir: Path) -> None:
    for group in GROUPS:
        original = build_group(group, source_dir)
        style = source_dir / group.name / "style_00.png"
        pixels, width, height, _colors = read_png(style, 4)
        edited = bytearray(pixels)
        edited[0] = (edited[0] + 1) & 15
        rebuilt = bytearray(group.tiles_per_style.to_bytes(2, "little") + group.styles.to_bytes(2, "little"))
        rebuilt.extend(encode(bytes(edited), width, height, 4))
        rebuilt.extend(original[4 + group.tiles_per_style * 32:])
        if len(rebuilt) != group.length or rebuilt == original:
            raise ValueError(f"{group.name} one-pixel edit does not preserve its fixed raw range")
    print(f"verified fixed-size one-pixel edits for {len(GROUPS)} Farm Status exterior groups")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=("export", "build", "verify", "edit-test"))
    parser.add_argument("--region", choices=("jp", "us", "eu", "de"))
    parser.add_argument("--rom", type=Path)
    parser.add_argument("--source-dir", type=Path, required=True)
    parser.add_argument("--palette-source", type=Path)
    parser.add_argument("--output-dir", type=Path)
    parser.add_argument("--replace", action="store_true")
    arguments = parser.parse_args()

    if arguments.command == "export":
        if arguments.region is None or arguments.rom is None or arguments.palette_source is None:
            parser.error("export requires --region, --rom and --palette-source")
        data = arguments.rom.read_bytes()
        colors = bank_five_colors(arguments.palette_source)
        for group in GROUPS:
            export_group(group, group_bytes(data, group, arguments.region), arguments.source_dir, colors, arguments.replace)
        print(f"exported {sum(group.styles for group in GROUPS)} Farm Status exterior style PNGs")
    elif arguments.command == "build":
        if arguments.output_dir is None:
            parser.error("build requires --output-dir")
        arguments.output_dir.mkdir(parents=True, exist_ok=True)
        for group in GROUPS:
            (arguments.output_dir / f"{group.name}.4bpp").write_bytes(build_group(group, arguments.source_dir))
        print(f"built {len(GROUPS)} Farm Status exterior native ranges")
    elif arguments.command == "verify":
        if arguments.region is None or arguments.rom is None or arguments.output_dir is None:
            parser.error("verify requires --region, --rom and --output-dir")
        verify_region(arguments.region, arguments.rom, arguments.source_dir, arguments.output_dir)
    else:
        edit_test(arguments.source_dir)


if __name__ == "__main__":
    main()

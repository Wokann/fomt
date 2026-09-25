#!/usr/bin/env python3
"""Manage code-proven palette and visual references for direct UI BG scenes.

Each profiled routine copies 0x200 bytes from the listed ROM address to
palette RAM after unpacking its two 32-by-32 tilemaps and 4bpp tiles. Some
copies run into an adjacent archive; the profile length covers only real
palette bytes. The tilemap and tile streams remain the lossless authoring
inputs; ordinary PNGs
cannot retain tile IDs, flip flags, or palette-bank attributes.  This tool
therefore writes PNGs as faithful, directly viewable references rather than
pretending that they are a hidden layout sidecar or a reversible tilemap.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import (  # noqa: E402
    bgr555_from_colors,
    colors_from_bgr555,
    decode,
    read_png,
    write_png,
)


PALETTE_LENGTH = 0x200
PALETTE_OUTPUT = "palettes.gbapal"
TILES_SOURCE = "tiles.4bpp"
TILEMAP_SOURCES = ("layer_0.tilemap", "layer_1.tilemap")
REFERENCE_NAMES = ("layer_0.png", "layer_1.png")
COMPOSITE_REFERENCE = "scene.png"

# Each consumer copies 0x200 bytes; profile lengths stop at the actual palette
# boundary so following archive data is never encoded as a color.
PROFILES = {
    "080b7164": {
        "offsets": {"jp": 0x4B3F4C, "us": 0x72DDE4, "eu": 0x72DE40, "de": 0x4B50B8},
        "length": 0x60,
        "sha256": {"jp": "556f3423f4da49c183dafea8575bba9330a4b4d3d5f9b3c11b31e360832955b3", "us": "556f3423f4da49c183dafea8575bba9330a4b4d3d5f9b3c11b31e360832955b3", "eu": "556f3423f4da49c183dafea8575bba9330a4b4d3d5f9b3c11b31e360832955b3", "de": "556f3423f4da49c183dafea8575bba9330a4b4d3d5f9b3c11b31e360832955b3"},
        "sources": {"jp": "palettes.pal", "us": "palettes.pal", "eu": "palettes.pal", "de": "palettes.pal"},
        "palette_source": "palettes.pal",
        "first_palette_bank": 0,
    },
    "080bcfac": {
        "offsets": {"jp": 0x4C2D5C, "us": 0x73CBF4, "eu": 0x73CC50, "de": 0x4C3F60},
        "length": 0xC0,
        "sha256": {"jp": "f52675fe893d77e2fba976c7b291acd6a6359d433e8283bc04cbf5a35e34f469", "us": "f52675fe893d77e2fba976c7b291acd6a6359d433e8283bc04cbf5a35e34f469", "eu": "f52675fe893d77e2fba976c7b291acd6a6359d433e8283bc04cbf5a35e34f469", "de": "f52675fe893d77e2fba976c7b291acd6a6359d433e8283bc04cbf5a35e34f469"},
        "sources": {"jp": "palettes.pal", "us": "palettes.pal", "eu": "palettes.pal", "de": "palettes.pal"},
        "palette_source": "palettes.pal",
        "first_palette_bank": 0,
    },
    "080c160c": {
        "offsets": {"jp": 0x4C624C, "us": 0x7400E4, "eu": 0x740140, "de": 0x4C7558},
        "length": 0xC0,
        "sha256": {"jp": "3cd46474231b5f816641cec654275a7dde0612f764272a2fd6b7990e77c49bd4", "us": "3cd46474231b5f816641cec654275a7dde0612f764272a2fd6b7990e77c49bd4", "eu": "3cd46474231b5f816641cec654275a7dde0612f764272a2fd6b7990e77c49bd4", "de": "3cd46474231b5f816641cec654275a7dde0612f764272a2fd6b7990e77c49bd4"},
        "sources": {"jp": "palettes.pal", "us": "palettes.pal", "eu": "palettes.pal", "de": "palettes.pal"},
        "palette_source": "palettes.pal",
        "first_palette_bank": 1,
    },
    "080ae7d0": {
        "offsets": {"jp": 0x4B7AA8, "us": 0x731940, "eu": 0x73199C, "de": 0x4B8CAC},
        "sha256": {"jp": "f00f6c6244f3c5497846998979764889717faf5eb805d1630b36001e60ece437", "us": "f00f6c6244f3c5497846998979764889717faf5eb805d1630b36001e60ece437", "eu": "f00f6c6244f3c5497846998979764889717faf5eb805d1630b36001e60ece437", "de": "f00f6c6244f3c5497846998979764889717faf5eb805d1630b36001e60ece437"},
        "sources": {"jp": "palette_banks.png", "us": "palette_banks.png", "eu": "palette_banks.png", "de": "palette_banks.png"},
        "palette_source": "palette_banks.png",
        "first_palette_bank": 0,
    },
}


def palette_from_rom(rom: bytes, region: str, profile: str) -> bytes:
    specification = PROFILES[profile]
    offset = specification["offsets"][region]
    length = specification.get("length", PALETTE_LENGTH)
    palette = rom[offset:offset + length]
    if len(palette) != length:
        raise ValueError(f"{region} ROM ends within the scene palette")
    if hashlib.sha256(palette).hexdigest() != specification["sha256"][region]:
        raise ValueError(f"{region} scene palette does not match the four-region baseline")
    if any(struct.unpack_from("<H", palette, index)[0] & 0x8000 for index in range(0, len(palette), 2)):
        raise ValueError(f"{region} scene palette contains a non-color bit; check the resource boundary")
    return palette


def colors_from_palette(palette: bytes) -> tuple[tuple[int, int, int, int], ...]:
    return colors_from_bgr555(palette, color_count=len(palette) // 2)


def palette_from_colors(colors: tuple[tuple[int, int, int, int], ...]) -> bytes:
    if any(alpha not in (0, 255) for _, _, _, alpha in colors):
        raise ValueError("palette PNG alpha must be 0 or 255")
    return bgr555_from_colors(colors, color_count=len(colors))


def palette_path(source_dir: Path, profile: str, region: str) -> Path:
    return source_dir / PROFILES[profile]["sources"][region]


def palette_from_source(source_dir: Path, profile: str, region: str) -> bytes:
    source = palette_path(source_dir, profile, region)
    if source.suffix == ".pal":
        lines = source.read_text(encoding="ascii").splitlines()
        color_count = PROFILES[profile].get("length", PALETTE_LENGTH) // 2
        if lines[:3] != ["JASC-PAL", "0100", str(color_count)] or len(lines) != color_count + 3:
            raise ValueError(f"{source.name} must contain exactly {color_count} JASC-PAL colors")
        colors = []
        for line in lines[3:]:
            components = tuple(int(component) for component in line.split())
            if len(components) != 3 or any(not 0 <= value <= 255 for value in components):
                raise ValueError(f"{source.name} has an invalid RGB color")
            colors.append((*components, 255))
        return palette_from_colors(tuple(colors))
    indexes, width, height, colors = read_png(source, color_count=256)
    if (width, height) != (256, 8) or indexes != bytes(range(256)) * 8:
        raise ValueError(f"{source.name} must remain a 256x8 ordered 16-bank palette swatch")
    return palette_from_colors(colors)


def render(tiles: bytes, tilemap: bytes, first_palette_bank: int) -> bytes:
    if len(tilemap) != 0x800:
        raise ValueError("scene tilemap must be exactly 0x800 bytes (32 by 32 entries)")
    # Native tile buffers can include a short trailing payload outside the
    # complete 8x8 tile sequence. Preserve it in the editable raw source, but
    # never invent pixels for it. Tilemap validation below proves whether the
    # visible layout actually refers only to complete tiles.
    whole_tile_bytes = len(tiles) // 32 * 32
    pixels, tile_height = decode(tiles[:whole_tile_bytes], 8, 4)
    tile_count = tile_height // 8
    output = bytearray(256 * 256)
    for cell in range(32 * 32):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id >= tile_count:
            if tile_id == 0x3FF:
                continue
            raise ValueError(f"tilemap entry {cell:#x} refers to unavailable tile {tile_id:#x}")
        flip_x = bool(entry & 0x400)
        flip_y = bool(entry & 0x800)
        palette_bank = entry >> 12 & 0xF
        if palette_bank < first_palette_bank:
            raise ValueError(f"tilemap entry {cell:#x} selects palette bank {palette_bank}, below the loaded palette range")
        output_x = cell % 32 * 8
        output_y = cell // 32 * 8
        source_y = tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(output_y + pixel_y) * 256 + output_x + pixel_x] = (palette_bank - first_palette_bank) * 16 + color
    return bytes(output)


def write_references(source_dir: Path, reference_dir: Path, profile: str, region: str) -> None:
    palette = palette_from_source(source_dir, profile, region)
    tiles = (source_dir / TILES_SOURCE).read_bytes()
    colors = colors_from_palette(palette)
    if palette_path(source_dir, profile, region).suffix == ".pal":
        write_png(reference_dir / "palettes.png", bytes(range(len(colors))), 16, len(colors) // 16, colors)
    layers = [render(tiles, (source_dir / source).read_bytes(), PROFILES[profile]["first_palette_bank"]) for source in TILEMAP_SOURCES]
    for layer, name in zip(layers, REFERENCE_NAMES, strict=True):
        write_png(reference_dir / name, layer, 256, 256, colors)

    # BG palette index zero is transparent to lower-priority BGs. The second
    # map is configured above the first in the profiled routines, so use its non-zero
    # pixel values over layer 0 for the code-backed readable composition.
    composite = bytearray(layers[0])
    for position, index in enumerate(layers[1]):
        if index & 0x0F:
            composite[position] = index
    write_png(reference_dir / COMPOSITE_REFERENCE, bytes(composite), 256, 256, colors)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(PROFILES[arguments.profile]["offsets"]):
        raise ValueError("export requires JP, US, EU and DE ROMs")
    palettes = {region: palette_from_rom(rom, region, arguments.profile) for region, rom in roms.items()}
    source_groups: dict[str, list[str]] = {}
    for region, source in PROFILES[arguments.profile]["sources"].items():
        source_groups.setdefault(source, []).append(region)
    for source, regions in source_groups.items():
        values = {palettes[region] for region in regions}
        if len(values) != 1:
            raise ValueError(f"{source} groups non-identical regional palettes")
        output = arguments.source_dir / source
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} already exists; use --replace to refresh it")
        palette = next(iter(values))
        if output.suffix == ".pal":
            colors = colors_from_palette(palette)
            output.write_bytes((
                f"JASC-PAL\r\n0100\r\n{len(colors)}\r\n"
                + "".join(f"{red} {green} {blue}\r\n" for red, green, blue, _ in colors)
            ).encode("ascii"))
        else:
            write_png(output, bytes(range(256)) * 8, 256, 8, colors_from_palette(palette))
        output_dir = arguments.reference_dir if len(source_groups) == 1 else arguments.reference_dir / source.removesuffix(".png")
        write_references(arguments.source_dir, output_dir, arguments.profile, regions[0])
    print(f"exported {len(source_groups)} verified palette source(s) and visual references to {arguments.source_dir}")


def build(arguments: argparse.Namespace) -> None:
    palette = palette_from_source(arguments.source_dir, arguments.profile, arguments.region)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / PALETTE_OUTPUT).write_bytes(palette)
    print(f"rebuilt scene palette for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    palette = palette_from_source(arguments.source_dir, arguments.profile, arguments.region)
    expected = palette_from_rom(arguments.rom.read_bytes(), arguments.region, arguments.profile)
    if palette != expected:
        raise AssertionError(f"scene palette differs from retail {arguments.region.upper()} bytes")
    if arguments.output_dir is not None and (arguments.output_dir / PALETTE_OUTPUT).read_bytes() != expected:
        raise AssertionError(f"built scene palette differs from retail {arguments.region.upper()} bytes")
    print(f"verified scene palette against {arguments.region.upper()} ROM")


def apply(target: bytes, baseline: bytes, output_dir: Path, region: str, profile: str) -> bytes:
    generated = (output_dir / PALETTE_OUTPUT).read_bytes()
    expected = palette_from_rom(baseline, region, profile)
    offset = PROFILES[profile]["offsets"][region]
    length = len(expected)
    current = target[offset:offset + length]
    if len(generated) != length:
        raise ValueError("generated scene palette has an incorrect length")
    if current != expected and current != generated:
        raise ValueError("target scene palette differs from retail baseline and generated data")
    result = bytearray(target)
    result[offset:offset + length] = generated
    return bytes(result)


def patch(arguments: argparse.Namespace) -> None:
    arguments.rom.write_bytes(apply(
        arguments.rom.read_bytes(), arguments.baseline.read_bytes(), arguments.output_dir, arguments.region, arguments.profile,
    ))
    print(f"patched scene palette into {arguments.rom} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    for region, path in arguments.rom:
        baseline = Path(path).read_bytes()
        if apply(baseline, baseline, arguments.output_root / region / f"graphics/ui/scene_{arguments.profile}", region, arguments.profile) != baseline:
            raise AssertionError(f"unchanged scene palette patch differs from retail {region.upper()} ROM")
    print("verified unchanged scene palette post-link patches against all four retail ROMs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--reference-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    export_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=("jp", "us", "eu", "de"), required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    build_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    preview_parser = commands.add_parser("preview")
    preview_parser.add_argument("--region", choices=("jp", "us", "eu", "de"), required=True)
    preview_parser.add_argument("--source-dir", type=Path, required=True)
    preview_parser.add_argument("--reference-dir", type=Path, required=True)
    preview_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=("jp", "us", "eu", "de"), required=True)
    verify_parser.add_argument("--rom", type=Path, required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    verify_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=("jp", "us", "eu", "de"), required=True)
    patch_parser.add_argument("--baseline", type=Path, required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--output-dir", type=Path, required=True)
    patch_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    patch_test_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    patch_test_parser.add_argument("--profile", choices=tuple(PROFILES), required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "preview":
        write_references(arguments.source_dir, arguments.reference_dir, arguments.profile, arguments.region)
        print(f"rendered three scene references to {arguments.reference_dir}")
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch":
        patch(arguments)
    else:
        patch_test(arguments)


if __name__ == "__main__":
    main()

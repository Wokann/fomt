#!/usr/bin/env python3
"""Manage code-proven palette and visual references for direct UI BG scenes.

Each profiled routine explicitly copies 0x200 bytes from the listed palette
address to palette RAM after unpacking its two 32-by-32 tilemaps and 4bpp tiles. The
tilemap and tile streams remain the lossless authoring inputs; ordinary PNGs
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
PALETTE_SOURCE = "palettes.png"
PALETTE_OUTPUT = "palettes.gbapal"
TILES_SOURCE = "tiles.4bpp"
TILEMAP_SOURCES = ("layer_0.tilemap", "layer_1.tilemap")
REFERENCE_NAMES = ("layer_0.png", "layer_1.png")
COMPOSITE_REFERENCE = "scene.png"

# Each entry represents one exact 0x200-byte palette copy proven in the
# consumer routine. Both ranges are common to JP, US, EU and DE.
PROFILES = {
    "080b7164": {
        "offsets": {"jp": 0x4B3F4C, "us": 0x72DDE4, "eu": 0x72DE40, "de": 0x4B50B8},
        "sha256": "27d34fdaddf10393f59fb1f89ad87d10e8d1b3d06176d3870216e36fcf3b0750",
    },
    "080bcfac": {
        "offsets": {"jp": 0x4C2D5C, "us": 0x73CBF4, "eu": 0x73CC50, "de": 0x4C3F60},
        "sha256": "f22d1e3fbc046353944f725f6e025ef0148545ac998b3c1268019aff5a090672",
    },
}


def palette_from_rom(rom: bytes, region: str, profile: str) -> bytes:
    specification = PROFILES[profile]
    offset = specification["offsets"][region]
    palette = rom[offset:offset + PALETTE_LENGTH]
    if len(palette) != PALETTE_LENGTH:
        raise ValueError(f"{region} ROM ends within the scene palette")
    if hashlib.sha256(palette).hexdigest() != specification["sha256"]:
        raise ValueError(f"{region} scene palette does not match the four-region baseline")
    return palette


def colors_from_palette(palette: bytes) -> tuple[tuple[int, int, int, int], ...]:
    """Use PNG alpha value 254 to retain otherwise invisible BGR555 bit 15."""
    colors = list(colors_from_bgr555(palette, color_count=256))
    for index in range(1, len(colors)):
        if struct.unpack_from("<H", palette, index * 2)[0] & 0x8000:
            red, green, blue, _ = colors[index]
            colors[index] = (red, green, blue, 254)
    return tuple(colors)


def palette_from_colors(colors: tuple[tuple[int, int, int, int], ...]) -> bytes:
    if any(alpha not in (0, 254, 255) for _, _, _, alpha in colors):
        raise ValueError("palette PNG alpha must be 0, 254, or 255")
    result = bytearray(bgr555_from_colors(colors, color_count=256))
    for index, (_, _, _, alpha) in enumerate(colors):
        if index and alpha == 254:
            value = struct.unpack_from("<H", result, index * 2)[0] | 0x8000
            struct.pack_into("<H", result, index * 2, value)
    return bytes(result)


def palette_from_source(source_dir: Path) -> bytes:
    indexes, width, height, colors = read_png(source_dir / PALETTE_SOURCE, color_count=256)
    if (width, height) != (256, 8) or indexes != bytes(range(256)) * 8:
        raise ValueError("palettes.png must remain a 256x8 ordered 16-bank palette swatch")
    return palette_from_colors(colors)


def render(tiles: bytes, tilemap: bytes) -> bytes:
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
        output_x = cell % 32 * 8
        output_y = cell // 32 * 8
        source_y = tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(output_y + pixel_y) * 256 + output_x + pixel_x] = palette_bank * 16 + color
    return bytes(output)


def write_references(source_dir: Path, reference_dir: Path) -> None:
    palette = palette_from_source(source_dir)
    tiles = (source_dir / TILES_SOURCE).read_bytes()
    colors = colors_from_palette(palette)
    layers = [render(tiles, (source_dir / source).read_bytes()) for source in TILEMAP_SOURCES]
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
    if len(set(palettes.values())) != 1:
        raise ValueError("scene palette differs by region; refusing a shared source")
    output = arguments.source_dir / PALETTE_SOURCE
    if output.exists() and not arguments.replace:
        raise ValueError(f"{output} already exists; use --replace to refresh it")
    write_png(output, bytes(range(256)) * 8, 256, 8, colors_from_palette(palettes["jp"]))
    write_references(arguments.source_dir, arguments.reference_dir)
    print(f"exported one shared palette and three visual references to {arguments.source_dir}")


def build(arguments: argparse.Namespace) -> None:
    palette = palette_from_source(arguments.source_dir)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / PALETTE_OUTPUT).write_bytes(palette)
    print(f"rebuilt scene palette for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    palette = palette_from_source(arguments.source_dir)
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
    current = target[offset:offset + PALETTE_LENGTH]
    if len(generated) != PALETTE_LENGTH:
        raise ValueError("generated scene palette has an incorrect length")
    if current != expected and current != generated:
        raise ValueError("target scene palette differs from retail baseline and generated data")
    result = bytearray(target)
    result[offset:offset + PALETTE_LENGTH] = generated
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
        write_references(arguments.source_dir, arguments.reference_dir)
        print(f"rendered three scene references to {arguments.reference_dir}")
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch":
        patch(arguments)
    else:
        patch_test(arguments)


if __name__ == "__main__":
    main()

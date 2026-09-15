#!/usr/bin/env python3
"""Render the static, code-built three-BG scene from ``func_0805AB08``.

The routine expands four small per-row templates into BG3, BG2, and BG1
screen blocks, loads the shared 4bpp characters into BG character block zero,
and copies 0x200 palette bytes. The palette range crosses the following
labelled resource, so this creates a verified read-only reference while the
separately managed tile stream remains the reversible authoring source.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]  # noqa: E402
from tile_grid import colors_from_bgr555, decode, write_png  # noqa: E402


REGIONS = ("jp", "us", "eu", "de")
OFFSETS = {
    "jp": {"bg3": 0x4B5284, "bg2": 0x4B5324, "bg1": 0x4B5354, "bg2_special": 0x4B5D64, "tiles": 0x4B5384, "palette": 0x4B5C04},
    "us": {"bg3": 0x72F11C, "bg2": 0x72F1BC, "bg1": 0x72F1EC, "bg2_special": 0x72FBFC, "tiles": 0x72F21C, "palette": 0x72FA9C},
    "eu": {"bg3": 0x72F178, "bg2": 0x72F218, "bg1": 0x72F248, "bg2_special": 0x72FC58, "tiles": 0x72F278, "palette": 0x72FAF8},
    "de": {"bg3": 0x4B6488, "bg2": 0x4B6528, "bg1": 0x4B6558, "bg2_special": 0x4B6F68, "tiles": 0x4B6588, "palette": 0x4B6E08},
}
STREAMS = {
    "bg3": (0xA0, "bd33e16fade336e624dd46573117ceecac9c5db381af677e0c47181eb4f31db5", "030", "125"),
    "bg2": (0x30, "da7be21c1d4e45d9563c51ce1e90b7d3a3f54b0e5aee32f6e3f12711d4541f67", "020", "1234567"),
    "bg1": (0x30, "57a7894247e1ea27086387ba74ef20a74e290a5ffa96b335c7ae80587dcfb0d3", "030", "247"),
    "bg2_special": (0x38, "d9baf01cd0809529aac6f842f16f8e26dc4f6890a4fd34ff90827a9a3289e304", "030", "135"),
    "tiles": (0x880, "9f24f2b35674dbcfd5d50880bc606e14b2346d8cee5ad71ef793d9c6102aa910", "020", "35710111214"),
}
PALETTE_LENGTH = 0x200
PALETTE_SHA256 = "510bffee99520a3a266887802fc339142ca794b89ba78714016b19e4ecdd5e7f"
TILES_SHA256 = "1c973dde3b5691265de3f113103517583fe122254b43d549c1106010e646a473"
WIDTH = HEIGHT = 256


def unpack_checked(rom: bytes, region: str, name: str) -> bytes:
    length, expected_hash, expected_format, expected_ladder = STREAMS[name]
    data = rom[OFFSETS[region][name]:OFFSETS[region][name] + length]
    if len(data) != length or hashlib.sha256(data).hexdigest() != expected_hash:
        raise ValueError(f"{region.upper()} {name} stream does not match verified retail data")
    payload, format_spec, ladder = unpack(data)
    expected_size = 0x2CC0 if name == "tiles" else 0x180
    if len(payload) != expected_size or format_spec != expected_format or ladder != expected_ladder:
        raise ValueError(f"{region.upper()} {name} stream does not decode as expected")
    return bytes(payload)


def checked_palette(rom: bytes, region: str) -> bytes:
    data = rom[OFFSETS[region]["palette"]:OFFSETS[region]["palette"] + PALETTE_LENGTH]
    if len(data) != PALETTE_LENGTH or hashlib.sha256(data).hexdigest() != PALETTE_SHA256:
        raise ValueError(f"{region.upper()} crossing palette copy does not match verified retail data")
    return data


def checked_tiles(source_dir: Path, decoded_tiles: bytes) -> bytes:
    source = (source_dir / "tiles.4bpp").read_bytes()
    if len(source) != 0x2CC0 or hashlib.sha256(source).hexdigest() != TILES_SHA256:
        raise ValueError("tiles.4bpp is not the verified shared retail tile source")
    if source != decoded_tiles:
        raise ValueError("tiles.4bpp differs from the verified runtime tile stream")
    return source


def build_maps(rows: dict[str, bytes]) -> tuple[bytes, bytes, bytes]:
    maps = [bytearray(b"\xff" * 0x800) for _ in range(3)]
    for row in range(32):
        source_offset, target_offset = row * 12, row * 64
        for group in range(5):
            target = target_offset + group * 12
            maps[0][target:target + 12] = rows["bg3"][source_offset:source_offset + 12]
            maps[1][target:target + 12] = rows["bg2_special" if group == 3 else "bg2"][source_offset:source_offset + 12]
            maps[2][target:target + 12] = rows["bg1"][source_offset:source_offset + 12]
    return bytes(maps[0]), bytes(maps[1]), bytes(maps[2])


def render_layer(tiles: bytes, tilemap: bytes) -> bytes:
    pixels, tile_height = decode(tiles, 8, 4)
    tile_count = tile_height // 8
    output = bytearray(WIDTH * HEIGHT)
    for cell in range(32 * 32):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id == 0x3FF:
            continue
        if tile_id >= tile_count:
            raise ValueError(f"tilemap entry {cell:#x} refers to unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        bank = entry >> 12 & 0xF
        out_x, out_y, source_y = cell % 32 * 8, cell // 32 * 8, tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(out_y + pixel_y) * WIDTH + out_x + pixel_x] = bank * 16 + color
    return bytes(output)


def composite(layers: tuple[bytes, bytes, bytes]) -> bytes:
    # BG3, BG2, BG1 use priorities 3, 2, 1 respectively.
    output = bytearray(layers[0])
    for layer in layers[1:]:
        for index, color in enumerate(layer):
            if color & 0x0F:
                output[index] = color
    return bytes(output)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires JP, US, EU and DE ROMs")
    decoded = {region: {name: unpack_checked(rom, region, name) for name in STREAMS} for region, rom in roms.items()}
    palettes = {region: checked_palette(rom, region) for region, rom in roms.items()}
    if any(decoded[region] != decoded["jp"] for region in REGIONS[1:]) or len(set(palettes.values())) != 1:
        raise ValueError("func_0805AB08 inputs unexpectedly differ between retail regions")
    tiles = checked_tiles(arguments.source_dir, decoded["jp"]["tiles"])
    maps = build_maps(decoded["jp"])
    layers = tuple(render_layer(tiles, tilemap) for tilemap in maps)
    scene = composite(layers)
    colors = colors_from_bgr555(palettes["jp"], color_count=256)
    for index, layer in enumerate(layers):
        write_png(arguments.reference_dir / f"layer_{index}.png", layer, WIDTH, HEIGHT, colors)
    write_png(arguments.reference_dir / "scene.png", scene, WIDTH, HEIGHT, colors)
    screen = b"".join(scene[row * WIDTH:row * WIDTH + 240] for row in range(160))
    write_png(arguments.reference_dir / "screen.png", screen, 240, 160, colors)
    print(f"rendered verified func_0805AB08 BG references to {arguments.reference_dir}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source-dir", type=Path, required=True)
    parser.add_argument("--reference-dir", type=Path, required=True)
    parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    arguments = parser.parse_args()
    arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    export(arguments)


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Render the static, code-backed BG3 base from ``func_08054F40``.

The routine directly unpacks a 32-by-20 map and a 4bpp tile stream, then
configures BG3 with screen block ``0x0600E000`` and character block zero.  Its
0x200-byte palette-memory copy crosses the following labelled resource, so
the PNG is a verified read-only reference rather than an editable palette
source.  The existing tile stream retains its separate reversible pipeline.
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
MAP_OFFSETS = {"jp": 0x4BEC40, "us": 0x738AD8, "eu": 0x738B34, "de": 0x4BFE44}
TILE_OFFSETS = {"jp": 0x4BEE84, "us": 0x738D1C, "eu": 0x738D78, "de": 0x4C0088}
PALETTE_OFFSETS = {"jp": 0x4BFB2C, "us": 0x7399C4, "eu": 0x739A20, "de": 0x4C0D30}
MAP_PACKED_LENGTH = 0x1F0
TILE_PACKED_LENGTH = 0xCA8
PALETTE_LENGTH = 0x200
MAP_PACKED_SHA256 = "91bd413189c1ab2f0228d4be27761f7c8ac8ec3f2a7e523a389615435ad86473"
TILE_PACKED_SHA256 = "00ae8e164ffed10b091e6f86a32ce83721fb96d9decb4322f0da99ba13ed34dd"
PALETTE_SHA256 = "29f6febfa2a825075377c2fea77c86bf8dca099e9fe06d2783d57215b875c100"
TILES_SHA256 = "de5997db9603377c0ebc305533788dbd83f361e8e1cea417c595728be3efbce3"
MAP_WIDTH, MAP_HEIGHT = 256, 160


def checked_slice(rom: bytes, offset: int, length: int, expected_hash: str, label: str) -> bytes:
    data = rom[offset:offset + length]
    if len(data) != length or hashlib.sha256(data).hexdigest() != expected_hash:
        raise ValueError(f"{label} does not match the verified four-region retail data")
    return data


def map_from_rom(rom: bytes, region: str) -> bytes:
    packed = checked_slice(rom, MAP_OFFSETS[region], MAP_PACKED_LENGTH, MAP_PACKED_SHA256, f"{region.upper()} BG3 map")
    payload, format_spec, ladder = unpack(packed)
    if len(payload) != 0x500 or format_spec != "000" or ladder != "46":
        raise ValueError(f"{region.upper()} BG3 map does not decode as expected")
    return bytes(payload)


def checked_tiles(source_dir: Path, rom: bytes, region: str) -> bytes:
    source = (source_dir / "tiles.4bpp").read_bytes()
    if len(source) != 0x2900 or hashlib.sha256(source).hexdigest() != TILES_SHA256:
        raise ValueError("tiles.4bpp is not the verified shared retail tile source")
    packed = checked_slice(rom, TILE_OFFSETS[region], TILE_PACKED_LENGTH, TILE_PACKED_SHA256, f"{region.upper()} tile stream")
    payload, format_spec, ladder = unpack(packed)
    if bytes(payload) != source or format_spec != "020" or ladder != "2578101314":
        raise ValueError(f"{region.upper()} tile stream does not decode as expected")
    return source


def palette_from_rom(rom: bytes, region: str) -> bytes:
    return checked_slice(rom, PALETTE_OFFSETS[region], PALETTE_LENGTH, PALETTE_SHA256, f"{region.upper()} palette copy")


def render(tiles: bytes, tilemap: bytes) -> bytes:
    pixels, tile_height = decode(tiles, 8, 4)
    tile_count = tile_height // 8
    output = bytearray(MAP_WIDTH * MAP_HEIGHT)
    for cell in range(32 * 20):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id == 0x3FF:
            continue
        if tile_id >= tile_count:
            raise ValueError(f"map entry {cell:#x} refers to unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        bank = entry >> 12 & 0xF
        out_x, out_y, source_y = cell % 32 * 8, cell // 32 * 8, tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(out_y + pixel_y) * MAP_WIDTH + out_x + pixel_x] = bank * 16 + color
    return bytes(output)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires JP, US, EU and DE ROMs")
    maps = {region: map_from_rom(rom, region) for region, rom in roms.items()}
    palettes = {region: palette_from_rom(rom, region) for region, rom in roms.items()}
    tiles = {region: checked_tiles(arguments.source_dir, rom, region) for region, rom in roms.items()}
    if len(set(maps.values())) != 1 or len(set(palettes.values())) != 1 or len(set(tiles.values())) != 1:
        raise ValueError("func_08054F40 inputs unexpectedly differ between retail regions")
    image = render(tiles["jp"], maps["jp"])
    # Native map width is 256; the GBA display uses the leftmost 240 pixels.
    screen = b"".join(image[row * MAP_WIDTH:row * MAP_WIDTH + 240] for row in range(MAP_HEIGHT))
    write_png(arguments.reference_dir / "base_layer_3.png", image, MAP_WIDTH, MAP_HEIGHT, colors_from_bgr555(palettes["jp"], color_count=256))
    write_png(arguments.reference_dir / "screen.png", screen, 240, MAP_HEIGHT, colors_from_bgr555(palettes["jp"], color_count=256))
    print(f"rendered verified func_08054F40 BG3 references to {arguments.reference_dir}")


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

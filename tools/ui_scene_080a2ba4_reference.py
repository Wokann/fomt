#!/usr/bin/env python3
"""Render read-only, code-backed previews of the ``func_080A2BA4`` UI scene.

The routine unpacks three 32-by-20 BG maps and a common 4bpp tile buffer, then
copies a 0x200-byte palette range to BG palette RAM. That range also overlaps a
separately consumed resource archive, so this tool deliberately creates only
reference PNGs; it never treats the palette as an independently editable or
patchable source.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import colors_from_bgr555, decode, write_png  # noqa: E402


REGIONS = ("jp", "us", "eu", "de")
PALETTE_OFFSETS = {"jp": 0x4D5808, "us": 0x74F2EC, "eu": 0x74F348, "de": 0x4D6758}
PALETTE_SHA256 = {
    "jp": "8dc4469b720a6df89ce4b3fa4c16a334e4c4d6f341d63e1aece04adec711589e",
    "us": "a0c6e024f255c2bd141824c304fdd787bdd22b0ab8e28ca1809ecbabbc02e898",
    "eu": "a0c6e024f255c2bd141824c304fdd787bdd22b0ab8e28ca1809ecbabbc02e898",
    "de": "897f8d2b0ca8388cb4ed5992b05aa12c6983efd3a90c984121c634f9ad1d89b9",
}
PALETTE_LENGTH = 0x200
SOURCE_HASHES = {
    "layer_0.tilemap": "ef4a820e5599b2b106ad62b707fb902597f0729912abd6dc49dd634b4e112395",
    "layer_1.tilemap": "9276f3222a68cffb906f3e120dd099540ef7e9734402923a45dc9878f473a5ea",
    "layer_2.tilemap": "21780f011d60eac907829059da63f704d8282e56f7cdfe1fd33ea85e89539e4e",
    "tiles.4bpp": "58ec8432846ec97a8b56ae6b092292389b541d800573be42e2e7bd451135ae4e",
}
TILEMAPS = ("layer_0.tilemap", "layer_1.tilemap", "layer_2.tilemap")
TILES = "tiles.4bpp"
WIDTH, HEIGHT = 256, 160


def checked_sources(source_dir: Path) -> tuple[bytes, list[bytes]]:
    payloads: dict[str, bytes] = {}
    for name, expected_hash in SOURCE_HASHES.items():
        data = (source_dir / name).read_bytes()
        if hashlib.sha256(data).hexdigest() != expected_hash:
            raise ValueError(f"{source_dir / name} does not match the four-region retail source")
        payloads[name] = data
    if any(len(payloads[name]) != 0x500 for name in TILEMAPS) or len(payloads[TILES]) != 0x1400:
        raise ValueError("func_080A2BA4 source dimensions are invalid")
    return payloads[TILES], [payloads[name] for name in TILEMAPS]


def palette(rom: bytes, region: str) -> bytes:
    offset = PALETTE_OFFSETS[region]
    data = rom[offset:offset + PALETTE_LENGTH]
    if len(data) != PALETTE_LENGTH or hashlib.sha256(data).hexdigest() != PALETTE_SHA256[region]:
        raise ValueError(f"{region.upper()} palette range does not match the verified runtime copy")
    return data


def render_layer(tiles: bytes, tilemap: bytes) -> bytes:
    pixels, tile_height = decode(tiles, 8, 4)
    tile_count = tile_height // 8
    output = bytearray(WIDTH * HEIGHT)
    for cell in range(32 * 20):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id >= tile_count:
            if tile_id == 0x3FF:
                continue
            raise ValueError(f"tilemap entry {cell:#x} references unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        palette_bank = entry >> 12 & 0xF
        out_x, out_y, source_y = cell % 32 * 8, cell // 32 * 8, tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(out_y + pixel_y) * WIDTH + out_x + pixel_x] = palette_bank * 16 + color
    return bytes(output)


def composite(layers: list[bytes]) -> bytes:
    # BGCNT priorities: layer_1 (1), layer_2 (2), layer_0 (3).
    output = bytearray(layers[0])
    for layer in (layers[2], layers[1]):
        for index, color in enumerate(layer):
            if color & 0x0F:
                output[index] = color
    return bytes(output)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires JP, US, EU and DE ROMs")
    tiles, tilemaps = checked_sources(arguments.source_dir)
    layers = [render_layer(tiles, tilemap) for tilemap in tilemaps]
    view = composite(layers)
    for region in REGIONS:
        colors = colors_from_bgr555(palette(roms[region], region), color_count=256)
        output = arguments.reference_dir / region
        for index, layer in enumerate(layers):
            write_png(output / f"layer_{index}.png", layer, WIDTH, HEIGHT, colors)
        # The native map is 256 pixels wide; this is the actual 240x160 GBA viewport.
        cropped = b"".join(view[row * WIDTH:row * WIDTH + 240] for row in range(HEIGHT))
        write_png(output / "screen.png", cropped, 240, HEIGHT, colors)
    print(f"rendered verified read-only references for {len(REGIONS)} regions to {arguments.reference_dir}")


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

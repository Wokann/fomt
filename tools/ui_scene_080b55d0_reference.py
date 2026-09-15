#!/usr/bin/env python3
"""Render the code-proven, read-only auxiliary BG view from ``func_080B55D0``.

The function supplies palette banks 0-6 through a compressed 0x1E0-byte copy
and then overwrites banks 7-15 through a 0x200-byte raw copy that also reaches
OBJ palette memory and overlaps later resources. Consequently this is a
verified visual reference, never an independently editable palette pipeline.
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
INITIAL_OFFSETS = {"jp": 0x4832F8, "us": 0x6FD19C, "eu": 0x6FD1F8, "de": 0x484238}
RAW_OFFSETS = {"jp": 0x4B3714, "us": 0x72D5AC, "eu": 0x72D608, "de": 0x4B4880}
INITIAL_PACKED_SHA256 = "83c4f6b8f8b09d04e3bdf1dbe288f91e1dda4b5f1e4331d0de8238895dec6d50"
INITIAL_DECODED_SHA256 = "bf8f9aa1825250d77ccdaf06106887b8fb3296f252aa53323e97516de624dea1"
RAW_SHA256 = "9fc50557c12af808dfb902df57462dce6814789a0e0272a44d156851a8c5ec40"
SOURCE_HASHES = {
    "layer_0.tilemap": "a9f7155d6178589cd19869456ff854e9ee42167f5a7a22c7e3c79cd60c0495b3",
    "layer_1.tilemap": "9fcc19fcff64d5b8b61c9575de819affab6b5669206b5a34aa7e13ea1276ff58",
    "tiles.4bpp": "f673709f5a15ccffbbfb5df9c4398e575c561de15ccc8300c7fefcf391b1fdeb",
}
WIDTH = HEIGHT = 256


def checked_sources(source_dir: Path) -> tuple[bytes, bytes, bytes]:
    payloads = {name: (source_dir / name).read_bytes() for name in SOURCE_HASHES}
    for name, data in payloads.items():
        if hashlib.sha256(data).hexdigest() != SOURCE_HASHES[name]:
            raise ValueError(f"{source_dir / name} does not match the verified shared retail source")
    if len(payloads["layer_0.tilemap"]) != 0x800 or len(payloads["layer_1.tilemap"]) != 0x800 or len(payloads["tiles.4bpp"]) != 0x1180:
        raise ValueError("func_080B55D0 auxiliary source dimensions are invalid")
    return payloads["tiles.4bpp"], payloads["layer_0.tilemap"], payloads["layer_1.tilemap"]


def palette(rom: bytes, region: str) -> bytes:
    initial_packed = rom[INITIAL_OFFSETS[region]:INITIAL_OFFSETS[region] + 0xA4]
    raw = rom[RAW_OFFSETS[region]:RAW_OFFSETS[region] + 0x200]
    if hashlib.sha256(initial_packed).hexdigest() != INITIAL_PACKED_SHA256 or hashlib.sha256(raw).hexdigest() != RAW_SHA256:
        raise ValueError(f"{region.upper()} palette inputs do not match retail data")
    decoded, format_spec, ladder = unpack(initial_packed)
    if len(decoded) != 0x1E0 or format_spec != "030" or ladder != "144" or hashlib.sha256(decoded).hexdigest() != INITIAL_DECODED_SHA256:
        raise ValueError(f"{region.upper()} initial palette stream does not decode as expected")
    result = bytearray(0x200)
    result[:0x1E0] = decoded
    # The later raw copy begins at 0x050000E0. Only its first 0x120 bytes are
    # BG palette RAM; its remaining bytes target OBJ palette RAM.
    result[0xE0:] = raw[:0x120]
    return bytes(result)


def render_layer(tiles: bytes, tilemap: bytes) -> bytes:
    pixels, tile_height = decode(tiles, 8, 4)
    tile_count = tile_height // 8
    output = bytearray(WIDTH * HEIGHT)
    for cell in range(32 * 32):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id >= tile_count:
            if tile_id == 0x3FF:
                continue
            raise ValueError(f"tilemap entry {cell:#x} references unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        bank = entry >> 12 & 0xF
        out_x, out_y, source_y = cell % 32 * 8, cell // 32 * 8, tile_id * 8
        for y in range(8):
            read_y = 7 - y if flip_y else y
            for x in range(8):
                read_x = 7 - x if flip_x else x
                color = pixels[(source_y + read_y) * 8 + read_x]
                output[(out_y + y) * WIDTH + out_x + x] = bank * 16 + color
    return bytes(output)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires JP, US, EU and DE ROMs")
    palettes = {region: palette(rom, region) for region, rom in roms.items()}
    if len(set(palettes.values())) != 1:
        raise ValueError("auxiliary scene palette differs between retail regions")
    tiles, back, front = checked_sources(arguments.source_dir)
    layers = [render_layer(tiles, back), render_layer(tiles, front)]
    view = bytearray(layers[0])
    for index, color in enumerate(layers[1]):
        if color & 0x0F:
            view[index] = color
    colors = colors_from_bgr555(palettes["jp"], color_count=256)
    write_png(arguments.reference_dir / "layer_0.png", layers[0], WIDTH, HEIGHT, colors)
    write_png(arguments.reference_dir / "layer_1.png", layers[1], WIDTH, HEIGHT, colors)
    write_png(arguments.reference_dir / "scene.png", bytes(view), WIDTH, HEIGHT, colors)
    cropped = b"".join(view[row * WIDTH:row * WIDTH + 240] for row in range(160))
    write_png(arguments.reference_dir / "screen.png", cropped, 240, 160, colors)
    print(f"rendered one verified read-only auxiliary scene reference to {arguments.reference_dir}")


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

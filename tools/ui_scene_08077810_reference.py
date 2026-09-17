#!/usr/bin/env python3
"""Render the verified overseas Natsume startup-background references.

``func_08077810`` loads one non-tile-aligned Huffman-8/LZ3 buffer and two
native BG tilemaps.  The tilemaps are already managed as reversible sources;
this tool only makes their code-backed visual result available for review.  It
does not turn the trailing two non-tile bytes in the common character stream
into a guessed editable asset.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from tile_grid import colors_from_bgr555, decode, write_png  # type: ignore[import-not-found]


REGIONS = ("us", "eu", "de")
RANGES = {
    "us": {
        "tiles": (0x74E648, 0x4F8),
        "palette": (0x74EB40, 0x20),
        "layer_1": (0x74EB60, 0x16C),
        "layer_0": (0x74ECCC, 0x16C),
    },
    "eu": {
        "tiles": (0x74E6A4, 0x4F8),
        "palette": (0x74EB9C, 0x20),
        "layer_1": (0x74EBBC, 0x16C),
        "layer_0": (0x74ED28, 0x16C),
    },
    "de": {
        "tiles": (0x4D5AB4, 0x4F8),
        "palette": (0x4D5FAC, 0x20),
        "layer_1": (0x4D5FCC, 0x16C),
        "layer_0": (0x4D6138, 0x16C),
    },
}
PACKED_HASHES = {
    "tiles": "40a4339338b7d0a11335c325d697c1f9971bc5fdcabf1ccb1883ccb22e44ec87",
    "palette": "51d75bd9affde28e7b4baf19af92de0b3c648b203b5944a8ad173bf63622792b",
    "layer_1": "331374d3ef973dff24a3200e367593fe6fbaad92c8ab0a2a7c49aff7241f276e",
    "layer_0": "75d5bddfe3c45bfd96b145062a0cc929e4c4fa7b2b1127a6f7217cf17fafeab9",
}
DECODED_LAYOUTS = {
    "tiles": (0x2BE2, "230"),
    "layer_1": (0x500, "100"),
    "layer_0": (0x1000, "130"),
}
MAP_SIZES = {"layer_1": (32, 20), "layer_0": (32, 32)}


def range_data(rom: bytes, region: str, name: str) -> bytes:
    offset, length = RANGES[region][name]
    data = rom[offset:offset + length]
    if len(data) != length or hashlib.sha256(data).hexdigest() != PACKED_HASHES[name]:
        raise ValueError(f"{region.upper()} {name} does not match the verified overseas ROM range")
    return data


def decoded(rom: bytes, region: str, name: str) -> bytes:
    data, format_spec, _ladder = unpack(range_data(rom, region, name))
    length, expected_format = DECODED_LAYOUTS[name]
    if len(data) != length or format_spec != expected_format:
        raise ValueError(
            f"{region.upper()} {name} decoded as {len(data):#x} bytes / {format_spec}; "
            f"expected {length:#x} / {expected_format}"
        )
    return bytes(data)


def render(tiles: bytes, tilemap: bytes, width_tiles: int, height_tiles: int) -> bytes:
    tile_bytes = len(tiles) // 32 * 32
    pixels, tile_height = decode(tiles[:tile_bytes], 8, 4)
    tile_count = tile_height // 8
    output_width, output_height = width_tiles * 8, height_tiles * 8
    output = bytearray(output_width * output_height)
    for cell in range(width_tiles * height_tiles):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id >= tile_count:
            if tile_id == 0x3FF:
                continue
            raise ValueError(f"tilemap cell {cell:#x} references unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        out_x, out_y, source_y = cell % width_tiles * 8, cell // width_tiles * 8, tile_id * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                output[(out_y + pixel_y) * output_width + out_x + pixel_x] = pixels[(source_y + read_y) * 8 + read_x]
    return bytes(output)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("reference export requires exactly US, EU and DE ROMs")
    common = {
        name: [decoded(roms[region], region, name) for region in REGIONS]
        for name in DECODED_LAYOUTS
    }
    palette_ranges = [range_data(roms[region], region, "palette") for region in REGIONS]
    if any(len(set(payloads)) != 1 for payloads in common.values()) or len(set(palette_ranges)) != 1:
        raise ValueError("overseas Natsume startup resources differ; refusing a shared reference")

    tiles = common["tiles"][0]
    palette = colors_from_bgr555(palette_ranges[0], 4)
    layer_1 = render(tiles, common["layer_1"][0], *MAP_SIZES["layer_1"])
    layer_0 = render(tiles, common["layer_0"][0], *MAP_SIZES["layer_0"])
    output = arguments.reference_dir
    write_png(output / "layer_0.png", layer_0, 256, 256, palette)
    write_png(output / "layer_1.png", layer_1, 256, 160, palette)
    screen = b"".join(layer_1[row * 256:row * 256 + 240] for row in range(160))
    write_png(output / "screen.png", screen, 240, 160, palette)
    print(f"rendered verified overseas Natsume startup references to {output}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference-dir", type=Path, required=True)
    parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    arguments = parser.parse_args()
    arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    export(arguments)


if __name__ == "__main__":
    main()

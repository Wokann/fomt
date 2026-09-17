#!/usr/bin/env python3
"""Render code-proven MapData layers as derived, non-authoritative PNGs.

Every MapData record supplies one 1024-tile 4bpp stream, two 15-bank BGR555
palette streams, and up to three width-by-height native GBA BG tilemaps.  The
native sources remain under ``graphics/maps/shared``; this tool only renders
individual layer references from them.  It intentionally does not invent BG
priority, scrolling, or a composite screen layout.

Palette bank 15 is not resident in either per-map 15-bank palette stream.
Layers using that bank are reported and skipped rather than rendered with a
guessed colour.  Their raw source remains managed by ``map_resources.py``.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from map_resources import (MAP_COUNT, MAP_RECORD_SIZE, MAP_TABLES, Resource,
                           catalog, read_source, rom_offset)
from tile_grid import colors_from_bgr555, decode, write_png


TILE_BYTES = 0x8000
PALETTE_BYTES = 0x1E0
PALETTE_BANKS = 15
TILE_WIDTH = 256


def source_for(resources: tuple[Resource, ...], map_id: int, layer: int) -> Resource:
    for resource in resources:
        if (map_id, layer) in resource.members:
            return resource
    raise ValueError(f"MapData map {map_id:02d} layer {layer} has no visual resource")


def source_bytes(source_dir: Path, resources: tuple[Resource, ...], map_id: int, layer: int) -> bytes:
    resource = source_for(resources, map_id, layer)
    path = source_dir / resource.source_relative()
    if not path.exists():
        raise ValueError(f"missing managed MapData source {path}")
    return read_source(path, resource)


def palette_colors(raw: bytes) -> tuple[tuple[int, int, int, int], ...]:
    if len(raw) != PALETTE_BYTES:
        raise ValueError(f"MapData palette must contain {PALETTE_BYTES:#x} bytes")
    colors = colors_from_bgr555(raw, color_count=PALETTE_BANKS * 16)
    # Palette entry zero is transparent in every native 4bpp bank, not only
    # the first global entry.  This affects derived layer readability only;
    # the BGR555 source bytes stay untouched.
    return tuple((red, green, blue, 0 if index % 16 == 0 else alpha)
                 for index, (red, green, blue, alpha) in enumerate(colors))


def render_layer(tiles: bytes, palette: bytes, tilemap: bytes, width: int, height: int) -> bytes:
    if len(tiles) != TILE_BYTES:
        raise ValueError(f"MapData tiles must contain {TILE_BYTES:#x} bytes")
    if len(tilemap) != width * height * 2:
        raise ValueError(f"native tilemap must be exactly {width}x{height} entries")
    pixels, tile_height = decode(tiles, TILE_WIDTH, 4)
    tile_count = TILE_WIDTH // 8 * (tile_height // 8)
    result = bytearray(width * 8 * height * 8)
    for cell in range(width * height):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id, bank = entry & 0x3FF, entry >> 12
        if bank >= PALETTE_BANKS:
            raise ValueError(f"tilemap cell {cell:#x} requires external palette bank {bank}")
        if tile_id >= tile_count:
            raise ValueError(f"tilemap cell {cell:#x} selects unavailable tile {tile_id:#x}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        output_x, output_y = cell % width * 8, cell // width * 8
        source_x, source_y = tile_id % (TILE_WIDTH // 8) * 8, tile_id // (TILE_WIDTH // 8) * 8
        for y in range(8):
            read_y = 7 - y if flip_y else y
            for x in range(8):
                read_x = 7 - x if flip_x else x
                pixel = pixels[(source_y + read_y) * TILE_WIDTH + source_x + read_x]
                result[(output_y + y) * width * 8 + output_x + x] = bank * 16 + pixel
    return bytes(result)


def map_dimensions(rom: bytes, region: str, map_id: int) -> tuple[int, int]:
    table = rom_offset(MAP_TABLES[region])
    record = table + map_id * MAP_RECORD_SIZE
    return (
        int.from_bytes(rom[record + 0x20:record + 0x22], "little"),
        int.from_bytes(rom[record + 0x22:record + 0x24], "little"),
    )


def render(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    requested = arguments.map_id if arguments.map_id else list(range(MAP_COUNT))
    references, skipped = 0, []
    for map_id in requested:
        dimensions = {
            region: map_dimensions(rom, region, map_id)
            for region, rom in inputs.items()
        }
        if len(set(dimensions.values())) != 1:
            raise ValueError(
                f"MapData map {map_id:02d} has region-specific dimensions: {dimensions}"
            )
        width, height = dimensions["jp"]
        directory = arguments.output_dir / f"map_{map_id:02d}"
        tiles = source_bytes(arguments.source_dir, resources, map_id, 0)
        palettes = {
            palette_id: source_bytes(arguments.source_dir, resources, map_id, palette_id)
            for palette_id in (1, 2)
        }
        for palette_id, palette in palettes.items():
            output = directory / f"palette_{palette_id}.png"
            write_png(output, bytes(range(PALETTE_BANKS * 16)) * 8, PALETTE_BANKS * 16, 8, palette_colors(palette))
        for layer in (3, 4, 5):
            try:
                tilemap = source_bytes(arguments.source_dir, resources, map_id, layer)
            except ValueError:
                continue
            for palette_id, palette in palettes.items():
                try:
                    image = render_layer(tiles, palette, tilemap, width, height)
                except ValueError as error:
                    skipped.append(f"map_{map_id:02d}/layer_{layer}/palette_{palette_id}: {error}")
                    continue
                write_png(directory / f"layer_{layer}_palette_{palette_id}.png", image, width * 8, height * 8, palette_colors(palette))
                references += 1
    print(f"rendered {references} code-backed MapData layer references")
    for message in skipped:
        print(f"skipped {message}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("render", nargs="?")
    parser.add_argument("--source-dir", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    parser.add_argument("--map-id", type=int, action="append", choices=range(MAP_COUNT))
    arguments = parser.parse_args()
    render(arguments)


if __name__ == "__main__":
    main()

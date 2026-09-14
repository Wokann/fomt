#!/usr/bin/env python3
"""Render Farm Status building-preview tilemaps as indexed PNG references.

The source is the editable 4bpp background tile grid, its 16 palette banks,
and the checked-in native ``.tilemap`` source.  PNG previews are derived
references: a BG map's tile IDs, flip bits and palette-bank bits cannot be
losslessly represented by an ordinary image or a JSON layout sidecar.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from tile_grid import read_png, write_png


@dataclass(frozen=True)
class Preview:
    name: str
    width_tiles: int
    height_tiles: int
    offsets: dict[str, tuple[int, int]]


# These pairs are the exact first/second pointers in
# gFarmStatusScreenFarmHousePreviews, gFarmStatusScreenCoopPreviews and
# gFarmStatusScreenBarnPreviews.  EU has physical stream offsets distinct from
# its logical labels, hence its explicitly recovered entries below.
PREVIEWS = (
    Preview("farm_house_level_0", 4, 6, {
        "jp": (0x2AFED0, 0x2B317C), "us": (0x529D74, 0x52D020),
        "eu": (0x529DD0, 0x52D07C), "de": (0x2B0E10, 0x2B40BC),
    }),
    Preview("farm_house_level_1", 8, 6, {
        "jp": (0x2AFE70, 0x2B311C), "us": (0x529D14, 0x52CFC0),
        "eu": (0x529D70, 0x52D01C), "de": (0x2B0DB0, 0x2B405C),
    }),
    Preview("farm_house_level_2", 12, 7, {
        "jp": (0x2AFDC8, 0x2B3074), "us": (0x529C6C, 0x52CF18),
        "eu": (0x529CC8, 0x52CF74), "de": (0x2B0D08, 0x2B3FB4),
    }),
    Preview("coop_level_0", 4, 6, {
        "jp": (0x2AFCD4, 0x2B2F80), "us": (0x529B78, 0x52CE24),
        "eu": (0x529BD4, 0x52CE80), "de": (0x2B0C14, 0x2B3EC0),
    }),
    Preview("coop_level_1", 8, 6, {
        "jp": (0x2AFC74, 0x2B2F20), "us": (0x529B18, 0x52CDC4),
        "eu": (0x529B74, 0x52CE20), "de": (0x2B0BB4, 0x2B3E60),
    }),
    Preview("barn_level_0", 6, 7, {
        "jp": (0x2B07E0, 0x2B3A8C), "us": (0x52A684, 0x52D930),
        "eu": (0x52A6E0, 0x52D98C), "de": (0x2B1720, 0x2B49CC),
    }),
    Preview("barn_level_1", 11, 7, {
        "jp": (0x2B0744, 0x2B39F0), "us": (0x52A5E8, 0x52D894),
        "eu": (0x52A644, 0x52D8F0), "de": (0x2B1684, 0x2B4930),
    }),
)


def map_bytes(rom: bytes, preview: Preview, variant: int, region: str) -> bytes:
    offset = preview.offsets[region][variant]
    length = preview.width_tiles * preview.height_tiles * 2
    result = rom[offset:offset + length]
    if len(result) != length:
        raise ValueError(f"{region} {preview.name} map leaves the ROM")
    return result


def source_map_bytes(directory: Path, preview: Preview, variant: int) -> bytes:
    suffix = ("primary", "alternate")[variant]
    result = (directory / f"{preview.name}_{suffix}.tilemap").read_bytes()
    expected = preview.width_tiles * preview.height_tiles * 2
    if len(result) != expected:
        raise ValueError(f"{preview.name}_{suffix}.tilemap must be exactly {expected:#x} bytes")
    return result


def render(tile_pixels: bytes, tile_width: int, tile_height: int,
           preview: Preview, tilemap: bytes) -> bytes:
    tile_count = tile_width * tile_height // 64
    output_width = preview.width_tiles * 8
    output_height = preview.height_tiles * 8
    result = bytearray(output_width * output_height)
    for cell in range(preview.width_tiles * preview.height_tiles):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        if tile_id >= tile_count:
            # Tile 0x3FF is the screen's pre-cleared blank tile rather than a
            # member of the 576-tile 4bpp base stream.
            continue
        flip_x = bool(entry & 0x400)
        flip_y = bool(entry & 0x800)
        palette_bank = entry >> 12 & 0xF
        output_x = cell % preview.width_tiles * 8
        output_y = cell // preview.width_tiles * 8
        source_x = tile_id % (tile_width // 8) * 8
        source_y = tile_id // (tile_width // 8) * 8
        for pixel_y in range(8):
            read_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                read_x = 7 - pixel_x if flip_x else pixel_x
                color_index = tile_pixels[(source_y + read_y) * tile_width + source_x + read_x]
                result[(output_y + pixel_y) * output_width + output_x + pixel_x] = palette_bank * 16 + color_index
    return bytes(result)


def verify_regions(roms: dict[str, Path]) -> None:
    contents = {region: path.read_bytes() for region, path in roms.items()}
    for preview in PREVIEWS:
        for variant, suffix in enumerate(("primary", "alternate")):
            hashes = {
                region: hashlib.sha256(map_bytes(data, preview, variant, region)).hexdigest()
                for region, data in contents.items()
            }
            if len(set(hashes.values())) != 1:
                raise ValueError(f"{preview.name}_{suffix} is not byte-identical across regions: {hashes}")
    print(f"verified {len(PREVIEWS) * 2} Farm Status tilemaps across JP, US, EU and DE")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--tiles-source", type=Path, required=True)
    parser.add_argument("--palettes-source", type=Path, required=True)
    parser.add_argument("--tilemaps-source", type=Path)
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--region", choices=("jp", "us", "eu", "de"), default="us")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--replace", action="store_true")
    parser.add_argument("--verify-jp", type=Path)
    parser.add_argument("--verify-us", type=Path)
    parser.add_argument("--verify-eu", type=Path)
    parser.add_argument("--verify-de", type=Path)
    arguments = parser.parse_args()

    verification_paths = {
        region: path for region, path in {
            "jp": arguments.verify_jp, "us": arguments.verify_us,
            "eu": arguments.verify_eu, "de": arguments.verify_de,
        }.items() if path is not None
    }
    if verification_paths:
        if set(verification_paths) != {"jp", "us", "eu", "de"}:
            parser.error("supply all four --verify-* ROM paths together")
        verify_regions(verification_paths)

    pixels, width, height, _tile_palette = read_png(arguments.tiles_source, 4)
    palette_indexes, palette_width, palette_height, palette = read_png(arguments.palettes_source, 8)
    if (palette_width, palette_height) != (256, 8) or palette_indexes != bytes(range(256)) * 8:
        raise ValueError("the palette source must retain the verified 256x8 swatch layout")
    rom = arguments.rom.read_bytes()
    arguments.output.mkdir(parents=True, exist_ok=True)
    for preview in PREVIEWS:
        for variant, suffix in enumerate(("primary", "alternate")):
            path = arguments.output / f"{preview.name}_{suffix}.png"
            if path.exists() and not arguments.replace:
                raise ValueError(f"{path} exists; pass --replace to overwrite it")
            tilemap = (source_map_bytes(arguments.tilemaps_source, preview, variant)
                       if arguments.tilemaps_source is not None
                       else map_bytes(rom, preview, variant, arguments.region))
            write_png(path, render(pixels, width, height, preview, tilemap),
                      preview.width_tiles * 8, preview.height_tiles * 8, palette)
    print(f"rendered {len(PREVIEWS) * 2} verified-reference previews to {arguments.output}")


if __name__ == "__main__":
    main()

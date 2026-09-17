#!/usr/bin/env python3
"""Build the code-bounded non-winter background used by ``func_08077EC0``.

The routine expands one Huffman-8/LZ2 4bpp stream into character VRAM, copies
two native 30-by-13 BG maps, and uploads exactly six BGR555 palette banks.
The editable inputs deliberately retain those three native representations:
the tile PNG stores only 4bpp indices, the palette PNG stores all six banks,
and the maps remain raw 16-bit GBA BG entries.  ``reference/*.png`` is a
derived, code-backed rendering of each map, never a reconstruction input.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff8_lz2
from tile_grid import (bgr555_from_colors, colors_from_bgr555, decode, encode,
                       read_png, write_png)


REGIONS = ("jp", "us", "eu", "de")
STREAM_LENGTH = 0x2298
TILES_LENGTH = 0x8000
PALETTE_LENGTH = 0xC0
MAP_LENGTH = 0x30C
MAP_WIDTH = 30
MAP_HEIGHT = 13
STREAM_SHA256 = "fbe7362cf81e9965753dee43f108c033e3e0081e8d79207e1f44f39cc98e1f9a"
TILES_SHA256 = "e53686f0fa24cf092c18387da6b437bb6250d3a517691a067d6217dbe4c1baa6"
PALETTE_SHA256 = "aebda16d14cda88265adc73057792f4b5254830acf480841988eb35c03eae9f0"
MAP_SHA256 = {
    "bg_30": "e4efc433aba1112d8905ef11ddeba996e6da3c0696701835f1dab01050d931c9",
    "bg_29": "2a26300c064c909316837469167a24edfe03e420e81fded9d6d0a2df3f5c40c7",
}
OFFSETS = {
    "jp": {"stream": 0x4DB7F4, "palette": 0x4DDA8C, "bg_30": 0x4DB1DC, "bg_29": 0x4DB4E8},
    "us": {"stream": 0x755848, "palette": 0x757AE0, "bg_30": 0x755230, "bg_29": 0x75553C},
    "eu": {"stream": 0x7558A4, "palette": 0x757B3C, "bg_30": 0x75528C, "bg_29": 0x755598},
    "de": {"stream": 0x4DCD64, "palette": 0x4DEFFC, "bg_30": 0x4DC74C, "bg_29": 0x4DCA58},
}
FORMAT = "220"
LADDER = "25810111214"
TILES_SOURCE = "nonwinter_tiles.png"
PALETTE_SOURCE = "nonwinter_palette_banks.png"


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def range_data(rom: bytes, region: str, name: str, length: int) -> bytes:
    offset = OFFSETS[region][name]
    data = rom[offset:offset + length]
    if len(data) != length:
        raise ValueError(f"{region}: {name} leaves the ROM")
    return data


def retail_stream(rom: bytes, region: str) -> tuple[bytes, bytes]:
    packed = range_data(rom, region, "stream", STREAM_LENGTH)
    if sha256(packed) != STREAM_SHA256:
        raise ValueError(f"{region}: non-winter stream hash mismatch")
    tiles, format_spec, ladder = unpack(packed)
    if (len(tiles), format_spec, ladder, sha256(tiles)) != (TILES_LENGTH, FORMAT, LADDER, TILES_SHA256):
        raise ValueError(f"{region}: unexpected H8/LZ2 decode contract")
    return packed, bytes(tiles)


def retail_palette(rom: bytes, region: str) -> bytes:
    palette = range_data(rom, region, "palette", PALETTE_LENGTH)
    if sha256(palette) != PALETTE_SHA256:
        raise ValueError(f"{region}: six-bank palette hash mismatch")
    return palette


def retail_map(rom: bytes, region: str, name: str) -> bytes:
    tilemap = range_data(rom, region, name, MAP_LENGTH)
    if sha256(tilemap) != MAP_SHA256[name]:
        raise ValueError(f"{region}: {name} tilemap hash mismatch")
    return tilemap


def source_paths(source_dir: Path) -> tuple[Path, Path, dict[str, Path]]:
    return (
        source_dir / TILES_SOURCE,
        source_dir / PALETTE_SOURCE,
        {name: source_dir / f"{name}.tilemap" for name in MAP_SHA256},
    )


def read_tiles(source: Path) -> bytes:
    pixels, width, height, _colors = read_png(source, 4)
    if (width, height) != (256, 256):
        raise ValueError(f"{source} must remain a 256x256 indexed 4bpp tile grid")
    result = encode(pixels, width, height, 4)
    if len(result) != TILES_LENGTH:
        raise AssertionError("tile source did not produce the expected 0x8000 bytes")
    return result


def read_palette(source: Path) -> bytes:
    indexes, width, height, colors = read_png(source, color_count=96)
    if (width, height) != (96, 8) or indexes != bytes(range(96)) * 8:
        raise ValueError(f"{source} must remain a six-bank 96x8 ordered palette swatch")
    return bgr555_from_colors(colors, color_count=96)


def read_map(source: Path) -> bytes:
    result = source.read_bytes()
    if len(result) != MAP_LENGTH:
        raise ValueError(f"{source} must be exactly {MAP_LENGTH:#x} bytes (30x13 native BG entries)")
    return result


def pack_tiles(tiles: bytes, baseline: bytes) -> bytes:
    original, format_spec, ladder = unpack(baseline)
    if tiles == original:
        return baseline
    packed = encode_huff8_lz2(tiles, ladder)
    if len(packed) > STREAM_LENGTH:
        raise ValueError(f"edited non-winter tiles need {len(packed):#x} bytes; slot holds {STREAM_LENGTH:#x}")
    result = packed + bytes(STREAM_LENGTH - len(packed))
    decoded, got_format, got_ladder = unpack(result)
    if decoded != tiles or (got_format, got_ladder) != (format_spec, ladder):
        raise AssertionError("rebuilt H8/LZ2 stream failed strict native decode")
    return result


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    streams = {region: retail_stream(rom, region) for region, rom in roms.items()}
    palettes = {region: retail_palette(rom, region) for region, rom in roms.items()}
    maps = {name: {region: retail_map(rom, region, name) for region, rom in roms.items()} for name in MAP_SHA256}
    if len({value[0] for value in streams.values()}) != 1 or len({value[1] for value in streams.values()}) != 1:
        raise ValueError("non-winter tile stream differs across regions; refusing a shared source")
    if len(set(palettes.values())) != 1 or any(len(set(values.values())) != 1 for values in maps.values()):
        raise ValueError("seasonal background palette or map differs across regions; refusing a shared source")
    tiles_source, palette_source, map_sources = source_paths(arguments.source_dir)
    for path in (tiles_source, palette_source, *map_sources.values()):
        if path.exists() and not arguments.replace:
            raise ValueError(f"{path} exists; pass --replace to refresh it")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    pixels, height = decode(streams["jp"][1], 256, 4)
    write_png(tiles_source, pixels, 256, height, colors_from_bgr555(palettes["jp"][:0x20], 4))
    write_png(palette_source, bytes(range(96)) * 8, 96, 8, colors_from_bgr555(palettes["jp"], color_count=96))
    for name, path in map_sources.items():
        path.write_bytes(maps[name]["jp"])
    print("exported verified shared non-winter seasonal background sources")


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    baseline, _original = retail_stream(rom, arguments.region)
    retail_palette(rom, arguments.region)
    for name in MAP_SHA256:
        retail_map(rom, arguments.region, name)
    tiles_source, palette_source, map_sources = source_paths(arguments.source_dir)
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / "nonwinter_tiles.0x70").write_bytes(pack_tiles(read_tiles(tiles_source), baseline))
    (arguments.output_dir / "nonwinter_palette_banks.gbapal").write_bytes(read_palette(palette_source))
    for name, source in map_sources.items():
        (arguments.output_dir / f"{name}.tilemap").write_bytes(read_map(source))
    print(f"rebuilt non-winter seasonal background for {arguments.region}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    baseline, _tiles = retail_stream(rom, arguments.region)
    expected = {
        "nonwinter_tiles.0x70": baseline,
        "nonwinter_palette_banks.gbapal": retail_palette(rom, arguments.region),
        **{f"{name}.tilemap": retail_map(rom, arguments.region, name) for name in MAP_SHA256},
    }
    for name, original in expected.items():
        output = (arguments.output_dir / name).read_bytes()
        if output != original:
            raise ValueError(f"{arguments.region}: rebuilt {name} differs from verified retail range")
    print(f"verified non-winter seasonal background for {arguments.region}")


def render_layer(tiles: bytes, palette: bytes, tilemap: bytes) -> bytes:
    pixels, tile_height = decode(tiles, 256, 4)
    tile_count = 256 // 8 * (tile_height // 8)
    result = bytearray(MAP_WIDTH * 8 * MAP_HEIGHT * 8)
    for cell in range(MAP_WIDTH * MAP_HEIGHT):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id, bank = entry & 0x3FF, entry >> 12 & 0xF
        if tile_id == 0x3FF:
            continue
        if tile_id >= tile_count or bank >= 6:
            raise ValueError(f"native map entry {cell:#x} has unavailable tile {tile_id:#x} or palette {bank}")
        flip_x, flip_y = bool(entry & 0x400), bool(entry & 0x800)
        out_x, out_y = cell % MAP_WIDTH * 8, cell // MAP_WIDTH * 8
        source_x, source_y = tile_id % 32 * 8, tile_id // 32 * 8
        for y in range(8):
            read_y = 7 - y if flip_y else y
            for x in range(8):
                read_x = 7 - x if flip_x else x
                result[(out_y + y) * MAP_WIDTH * 8 + out_x + x] = bank * 16 + pixels[(source_y + read_y) * 256 + source_x + read_x]
    return bytes(result)


def reference(arguments: argparse.Namespace) -> None:
    tiles_source, palette_source, map_sources = source_paths(arguments.source_dir)
    tiles, palette = read_tiles(tiles_source), read_palette(palette_source)
    colors = colors_from_bgr555(palette, color_count=96)
    for name, source in map_sources.items():
        output = arguments.reference_dir / f"{name}.png"
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; pass --replace to refresh it")
        write_png(output, render_layer(tiles, palette, read_map(source)), MAP_WIDTH * 8, MAP_HEIGHT * 8, colors)
    print(f"rendered two code-backed seasonal BG layer references to {arguments.reference_dir}")


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(description=__doc__)
    commands = result.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--region", choices=REGIONS, required=True)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        command.add_argument("--output-dir", type=Path, required=True)
    reference_parser = commands.add_parser("reference")
    reference_parser.add_argument("--source-dir", type=Path, required=True)
    reference_parser.add_argument("--reference-dir", type=Path, required=True)
    reference_parser.add_argument("--replace", action="store_true")
    return result


def main() -> None:
    arguments = parser().parse_args()
    if arguments.command == "export":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    else:
        reference(arguments)


if __name__ == "__main__":
    main()

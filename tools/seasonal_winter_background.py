#!/usr/bin/env python3
"""Build the code-bounded winter background selected by ``func_08077EC0``.

The same routine selects the non-winter and winter character streams, six
palette banks, and two 30-by-13 BG maps.  The first map is physically shared
with the non-winter presentation, so this tool owns only the winter-exclusive
tile stream, palette banks and second map.  The sources remain native tile and
tilemap representations; rendered views are not build inputs.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import WINTER_MATCH_CANDIDATES, encode_huff8_lz3
from tile_grid import (bgr555_from_colors, colors_from_bgr555, decode, encode,
                       read_png, write_png)


REGIONS = ("jp", "us", "eu", "de")
STREAM_LENGTH = 0x212C
TILES_LENGTH = 0x8000
PALETTE_LENGTH = 0xC0
MAP_LENGTH = 0x30C
MAP_WIDTH = 30
MAP_HEIGHT = 13
STREAM_SHA256 = "77bfcdfa8918452edf8fa69de854011016f7447fb417468488565aa953a97672"
TILES_SHA256 = "bd8c727ca1011d1d02e43c3e471616b792a628de8adaa9b77d11d0ce07415bef"
PALETTE_SHA256 = "17701fd1dee0213e49b85be683d33db814f0e9eefe75efdef79e0ce68935d36b"
SHARED_BG30_SHA256 = "e4efc433aba1112d8905ef11ddeba996e6da3c0696701835f1dab01050d931c9"
WINTER_BG29_SHA256 = "295839488a968ee23b0e76521f136217a340429ef8aa2d6f21875ca1964ba8d7"
OFFSETS = {
    "jp": {"stream": 0x4DE1D8, "palette": 0x4E0304, "bg_30": 0x4DB1DC, "bg_29": 0x4DDECC},
    "us": {"stream": 0x75822C, "palette": 0x75A358, "bg_30": 0x757C14, "bg_29": 0x757F20},
    "eu": {"stream": 0x758288, "palette": 0x75A3B4, "bg_30": 0x757C70, "bg_29": 0x757F7C},
    "de": {"stream": 0x4DF748, "palette": 0x4E1874, "bg_30": 0x4DC74C, "bg_29": 0x4DF43C},
}


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def range_data(rom: bytes, region: str, name: str, length: int) -> bytes:
    offset = OFFSETS[region][name]
    result = rom[offset:offset + length]
    if len(result) != length:
        raise ValueError(f"{region}: winter {name} leaves the ROM")
    return result


def retail_stream(rom: bytes, region: str) -> tuple[bytes, bytes]:
    packed = range_data(rom, region, "stream", STREAM_LENGTH)
    if sha256(packed) != STREAM_SHA256:
        raise ValueError(f"{region}: winter stream hash mismatch")
    tiles, format_spec, ladder = unpack(packed)
    if len(tiles) != TILES_LENGTH or sha256(bytes(tiles)) != TILES_SHA256:
        raise ValueError(f"{region}: winter stream has an unexpected decode contract")
    if format_spec != "230" or ladder != "41013":
        raise ValueError(f"{region}: winter stream uses an unexpected native format {format_spec}/{ladder}")
    return packed, bytes(tiles)


def retail_data(rom: bytes, region: str, name: str, length: int, expected_hash: str) -> bytes:
    result = range_data(rom, region, name, length)
    if sha256(result) != expected_hash:
        raise ValueError(f"{region}: winter {name} hash mismatch")
    return result


def paths(source_dir: Path) -> tuple[Path, Path, Path, Path]:
    return (
        source_dir / "winter_tiles.png",
        source_dir / "winter_palette_banks.png",
        source_dir.parent / "shared" / "bg_30.tilemap",
        source_dir / "winter_bg_29.tilemap",
    )


def read_tiles(source: Path) -> bytes:
    pixels, width, height, _colors = read_png(source, 4)
    if (width, height) != (256, 256):
        raise ValueError(f"{source} must remain a 256x256 indexed 4bpp tile grid")
    result = encode(pixels, width, height, 4)
    if len(result) != TILES_LENGTH:
        raise AssertionError("winter tile source did not produce 0x8000 bytes")
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
    original, _format_spec, _ladder = unpack(baseline)
    if tiles == original:
        return baseline
    packed = encode_huff8_lz3(tiles, match_candidates=WINTER_MATCH_CANDIDATES)
    if len(packed) > STREAM_LENGTH:
        raise ValueError(f"edited winter tiles need {len(packed):#x} bytes; slot holds {STREAM_LENGTH:#x}")
    result = packed + bytes(STREAM_LENGTH - len(packed))
    decoded, _format_spec, _ladder = unpack(result)
    if decoded != tiles:
        raise AssertionError("rebuilt winter stream failed strict native decode")
    return result


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires jp, us, eu and de ROMs")
    streams = {region: retail_stream(rom, region) for region, rom in roms.items()}
    palettes = {region: retail_data(rom, region, "palette", PALETTE_LENGTH, PALETTE_SHA256)
                for region, rom in roms.items()}
    shared_maps = {region: retail_data(rom, region, "bg_30", MAP_LENGTH, SHARED_BG30_SHA256)
                   for region, rom in roms.items()}
    winter_maps = {region: retail_data(rom, region, "bg_29", MAP_LENGTH, WINTER_BG29_SHA256)
                   for region, rom in roms.items()}
    if (len({value[0] for value in streams.values()}) != 1
            or len({value[1] for value in streams.values()}) != 1
            or len(set(palettes.values())) != 1
            or len(set(shared_maps.values())) != 1
            or len(set(winter_maps.values())) != 1):
        raise ValueError("winter presentation differs across regions; refusing a shared source")
    tiles_path, palette_path, shared_map_path, winter_map_path = paths(arguments.source_dir)
    for path in (tiles_path, palette_path, winter_map_path):
        if path.exists() and not arguments.replace:
            raise ValueError(f"{path} exists; pass --replace to refresh it")
    if not shared_map_path.exists() or read_map(shared_map_path) != shared_maps["jp"]:
        raise ValueError(f"{shared_map_path} must contain the verified shared winter/non-winter BG30 map")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    pixels, height = decode(streams["jp"][1], 256, 4)
    write_png(tiles_path, pixels, 256, height, colors_from_bgr555(palettes["jp"][:0x20], 4))
    write_png(palette_path, bytes(range(96)) * 8, 96, 8, colors_from_bgr555(palettes["jp"], color_count=96))
    winter_map_path.write_bytes(winter_maps["jp"])
    print("exported verified shared winter seasonal-background sources")


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    baseline, _tiles = retail_stream(rom, arguments.region)
    retail_data(rom, arguments.region, "palette", PALETTE_LENGTH, PALETTE_SHA256)
    retail_data(rom, arguments.region, "bg_30", MAP_LENGTH, SHARED_BG30_SHA256)
    retail_data(rom, arguments.region, "bg_29", MAP_LENGTH, WINTER_BG29_SHA256)
    tiles_path, palette_path, shared_map_path, winter_map_path = paths(arguments.source_dir)
    if read_map(shared_map_path) != retail_data(rom, arguments.region, "bg_30", MAP_LENGTH, SHARED_BG30_SHA256):
        raise ValueError("shared BG30 map no longer matches the retail winter presentation")
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / "winter_tiles.0x70").write_bytes(pack_tiles(read_tiles(tiles_path), baseline))
    (arguments.output_dir / "winter_palette_banks.gbapal").write_bytes(read_palette(palette_path))
    (arguments.output_dir / "winter_bg_29.tilemap").write_bytes(read_map(winter_map_path))
    print(f"rebuilt winter seasonal background for {arguments.region}")


def verify(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    baseline, _tiles = retail_stream(rom, arguments.region)
    expected = {
        "winter_tiles.0x70": baseline,
        "winter_palette_banks.gbapal": retail_data(rom, arguments.region, "palette", PALETTE_LENGTH, PALETTE_SHA256),
        "winter_bg_29.tilemap": retail_data(rom, arguments.region, "bg_29", MAP_LENGTH, WINTER_BG29_SHA256),
    }
    for name, original in expected.items():
        output = (arguments.output_dir / name).read_bytes()
        if output != original:
            raise ValueError(f"{arguments.region}: rebuilt winter {name} differs from the retail range")
    print(f"verified winter seasonal background for {arguments.region}")


def render_layer(tiles: bytes, palette: bytes, tilemap: bytes) -> bytes:
    """Render one code-bounded 30-by-13 BG layer as an indexed reference."""
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
        output_x, output_y = cell % MAP_WIDTH * 8, cell // MAP_WIDTH * 8
        source_x, source_y = tile_id % 32 * 8, tile_id // 32 * 8
        for y in range(8):
            read_y = 7 - y if flip_y else y
            for x in range(8):
                read_x = 7 - x if flip_x else x
                result[(output_y + y) * MAP_WIDTH * 8 + output_x + x] = (
                    bank * 16 + pixels[(source_y + read_y) * 256 + source_x + read_x]
                )
    return bytes(result)


def reference(arguments: argparse.Namespace) -> None:
    tiles_path, palette_path, shared_map_path, winter_map_path = paths(arguments.source_dir)
    tiles, palette = read_tiles(tiles_path), read_palette(palette_path)
    colors = colors_from_bgr555(palette, color_count=96)
    arguments.reference_dir.mkdir(parents=True, exist_ok=True)
    for name, source in (("winter_bg_30", shared_map_path), ("winter_bg_29", winter_map_path)):
        output = arguments.reference_dir / f"{name}.png"
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; pass --replace to refresh it")
        write_png(output, render_layer(tiles, palette, read_map(source)), MAP_WIDTH * 8, MAP_HEIGHT * 8, colors)
    print(f"rendered two code-backed winter BG layer references to {arguments.reference_dir}")


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

#!/usr/bin/env python3
"""Export and render the shared Intro Scene startup BG art.

``func_080019D8`` expands one 0x8000-byte Huffman-8/LZ3 tile payload, copies
sixteen palette banks, then unpacks four native streams whose alternating
0x40-byte rows form two 32-by-32 BG maps.  The tile PNG, palette-bank PNG and
interleaved map files are the lossless native inputs.  The eight rendered PNGs
are readable, code-backed layer references only: an ordinary PNG cannot retain
the map's tile number, flip and palette-bank fields.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff8_lz3  # type: ignore[import-not-found]
from tile_grid import (  # type: ignore[import-not-found]
    bgr555_from_colors,
    colors_from_bgr555,
    decode,
    encode,
    read_png,
    write_png,
)


STREAM_LENGTH = 0x3970
TILES_LENGTH = 0x8000
PALETTE_LENGTH = 0x200
TILES_SHA256 = "50373093e3e4a2918155156d6833cc011a341b778d3c22a425b3297f434685eb"
PALETTE_SHA256 = "d503e20b342424db39c68a212268de64fa9307148860754d9cc7d6c2b75b453e"
STREAM_SHA256 = "20269c8c8acaa2cdfd0ec72cacca882ec6e21cda7e2abc961b97d62626ac877b"
REGIONS = {
    "jp": (0x4D1154, 0x4D4AC4),
    "us": (0x74A9C0, 0x74E330),
    "eu": (0x74AA1C, 0x74E38C),
    "de": (0x4D1E2C, 0x4D579C),
}
SOURCE_TILES = "startup_tiles.png"
SOURCE_PALETTES = "startup_palette_banks.png"


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def extract(rom: bytes, region: str) -> tuple[bytes, bytes, bytes]:
    stream_offset, palette_offset = REGIONS[region]
    stream = rom[stream_offset:stream_offset + STREAM_LENGTH]
    palette = rom[palette_offset:palette_offset + PALETTE_LENGTH]
    if len(stream) != STREAM_LENGTH or len(palette) != PALETTE_LENGTH:
        raise ValueError(f"{region}: startup data exceeds ROM bounds")
    if digest(stream) != STREAM_SHA256:
        raise ValueError(f"{region}: startup H8/LZ3 stream hash mismatch")
    if digest(palette) != PALETTE_SHA256:
        raise ValueError(f"{region}: startup palette hash mismatch")
    tiles, format_spec, _ladder = unpack(stream)
    if len(tiles) != TILES_LENGTH or format_spec != "230":
        raise ValueError(
            f"{region}: expected 0x8000-byte H8/LZ3 startup tiles, got {len(tiles):#x} / {format_spec}"
        )
    if digest(tiles) != TILES_SHA256:
        raise ValueError(f"{region}: startup decoded tile hash mismatch")
    return stream, bytes(tiles), palette


def palette_png(palette: bytes, output: Path) -> None:
    write_png(
        output,
        bytes(range(256)) * 8,
        256,
        8,
        colors_from_bgr555(palette, color_count=256),
    )


def read_sources(source_dir: Path) -> tuple[bytes, bytes]:
    pixels, width, height, _colors = read_png(source_dir / SOURCE_TILES, 4)
    if (width, height) != (256, 256):
        raise ValueError("startup tile source must remain a 256x256 indexed 4bpp grid")
    tiles = encode(pixels, width, height, 4)
    indexes, width, height, colors = read_png(source_dir / SOURCE_PALETTES, color_count=256)
    if (width, height) != (256, 8) or indexes != bytes(range(256)) * 8:
        raise ValueError("startup palette source must retain the 256x8 native swatch layout")
    palette = bgr555_from_colors(colors, color_count=256)
    return tiles, palette


def rebuild_tiles(source: bytes, baseline: bytes) -> bytes:
    """Preserve retail bytes unchanged; strictly fit and validate edited tiles."""
    original, format_spec, _ladder = unpack(baseline)
    if source == original:
        return baseline
    encoded = encode_huff8_lz3(source)
    if len(encoded) > len(baseline):
        raise ValueError(
            f"edited startup tiles need {len(encoded):#x} bytes but the native slot holds only {len(baseline):#x}"
        )
    result = encoded + bytes(len(baseline) - len(encoded))
    decoded, checked_format, _checked_ladder = unpack(result)
    if decoded != source or checked_format != format_spec:
        raise AssertionError("rebuilt startup tiles failed strict native decode validation")
    return result


def map_layers(data: bytes) -> tuple[bytes, bytes]:
    """Split the code-proven alternating 32-entry rows into two native maps."""
    if len(data) != 0x1000:
        raise ValueError("each startup map stream must decode to 0x1000 bytes")
    first = bytearray(0x800)
    second = bytearray(0x800)
    for row in range(32):
        source = row * 0x80
        target = row * 0x40
        first[target:target + 0x40] = data[source:source + 0x40]
        second[target:target + 0x40] = data[source + 0x40:source + 0x80]
    return bytes(first), bytes(second)


def render_layer(tile_pixels: bytes, palette: tuple[tuple[int, int, int, int], ...], tilemap: bytes) -> bytes:
    result = bytearray(256 * 256)
    for cell in range(32 * 32):
        entry = int.from_bytes(tilemap[cell * 2:cell * 2 + 2], "little")
        tile_id = entry & 0x3FF
        palette_bank = entry >> 12 & 0xF
        if tile_id >= TILES_LENGTH // 32:
            raise ValueError(f"startup map cell {cell:#x} references unavailable tile {tile_id:#x}")
        flip_x = bool(entry & 0x400)
        flip_y = bool(entry & 0x800)
        output_x, output_y = cell % 32 * 8, cell // 32 * 8
        tile_x, tile_y = tile_id % 32 * 8, tile_id // 32 * 8
        for pixel_y in range(8):
            source_y = 7 - pixel_y if flip_y else pixel_y
            for pixel_x in range(8):
                source_x = 7 - pixel_x if flip_x else pixel_x
                value = tile_pixels[(tile_y + source_y) * 256 + tile_x + source_x]
                result[(output_y + pixel_y) * 256 + output_x + pixel_x] = palette_bank * 16 + value
    return bytes(result)


def export(arguments: argparse.Namespace) -> None:
    roms = {region: Path(path).read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires exactly jp, us, eu and de ROMs")
    records = {region: extract(rom, region) for region, rom in roms.items()}
    streams = {stream for stream, _tiles, _palette in records.values()}
    tiles = {tiles for _stream, tiles, _palette in records.values()}
    palettes = {palette for _stream, _tiles, palette in records.values()}
    if len(streams) != len(tiles) != len(palettes) != 1:
        raise ValueError("startup art differs across regions; refusing a falsely shared source")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    output_tiles = arguments.source_dir / SOURCE_TILES
    output_palette = arguments.source_dir / SOURCE_PALETTES
    if (output_tiles.exists() or output_palette.exists()) and not arguments.replace:
        raise ValueError("startup sources already exist; use --replace to refresh them")
    pixels, height = decode(next(iter(tiles)), 256, 4)
    if height != 256:
        raise AssertionError("startup native grid height changed unexpectedly")
    write_png(output_tiles, pixels, 256, height, colors_from_bgr555(next(iter(palettes))[:0x20], 4))
    palette_png(next(iter(palettes)), output_palette)
    print("exported one four-region-verified Intro Scene startup tile/palette source set")


def verify(arguments: argparse.Namespace) -> None:
    tiles, palette = read_sources(arguments.source_dir)
    if digest(tiles) != TILES_SHA256 or digest(palette) != PALETTE_SHA256:
        raise ValueError("startup sources do not reproduce the verified native tile or palette bytes")
    for region, path in arguments.rom:
        stream, original_tiles, original_palette = extract(path.read_bytes(), region)
        if tiles != original_tiles or palette != original_palette:
            raise AssertionError(f"startup source mismatch for {region}")
        if arguments.output_dir is not None:
            output = arguments.output_dir / f"startup_tiles.{region}.0x70"
            if output.read_bytes() != stream:
                raise AssertionError(f"built startup stream {output} does not match retail {region.upper()} bytes")
    print("verified Intro Scene startup tiles and palette against all four retail ROMs")


def build(arguments: argparse.Namespace) -> None:
    tiles, palette = read_sources(arguments.source_dir)
    stream, _original_tiles, _original_palette = extract(arguments.rom.read_bytes(), arguments.region)
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(rebuild_tiles(tiles, stream))
    arguments.palette_output.parent.mkdir(parents=True, exist_ok=True)
    arguments.palette_output.write_bytes(palette)
    print(f"rebuilt Intro Scene startup tile stream for {arguments.region.upper()}")


def edit_test(arguments: argparse.Namespace) -> None:
    """Prove that a deterministic pixel change has a valid fixed-slot stream."""
    stream, tiles, _palette = extract(arguments.rom.read_bytes(), arguments.region)
    edited = bytearray(tiles)
    index = next(index for index, value in enumerate(edited) if value)
    edited[index] ^= 1
    rebuilt = rebuild_tiles(bytes(edited), stream)
    decoded, format_spec, _ladder = unpack(rebuilt)
    if decoded != edited or format_spec != "230" or rebuilt == stream:
        raise AssertionError("edited Intro Scene startup tile stream did not strictly round-trip")
    print(
        f"Intro Scene startup tile edit test: byte {index:#x}; "
        f"packed {len(rebuilt):#x} bytes in a {len(stream):#x}-byte slot"
    )


def reference(arguments: argparse.Namespace) -> None:
    tiles, palette_data = read_sources(arguments.source_dir)
    pixels, height = decode(tiles, 256, 4)
    if height != 256:
        raise AssertionError("startup tile grid has unexpected height")
    palette = colors_from_bgr555(palette_data, color_count=256)
    arguments.reference_dir.mkdir(parents=True, exist_ok=True)
    for index in range(4):
        source = (arguments.tilemaps_dir / f"startup_{index:02d}.tilemap").read_bytes()
        first, second = map_layers(source)
        for layer, tilemap in enumerate((first, second)):
            output = arguments.reference_dir / f"startup_{index:02d}_layer_{layer}.png"
            if output.exists() and not arguments.replace:
                raise ValueError(f"{output} exists; use --replace to regenerate references")
            write_png(output, render_layer(pixels, palette, tilemap), 256, 256, palette)
    print("rendered eight code-backed Intro Scene startup layer references")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True, type=str)
    verify_parser.add_argument("--output-dir", type=Path)
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    build_parser.add_argument("--palette-output", type=Path, required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(REGIONS), required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    reference_parser = commands.add_parser("reference")
    reference_parser.add_argument("--source-dir", type=Path, required=True)
    reference_parser.add_argument("--tilemaps-dir", type=Path, required=True)
    reference_parser.add_argument("--reference-dir", type=Path, required=True)
    reference_parser.add_argument("--replace", action="store_true")
    arguments = parser.parse_args()
    if arguments.command == "verify":
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        reference(arguments)


if __name__ == "__main__":
    main()

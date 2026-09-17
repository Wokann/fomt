#!/usr/bin/env python3
"""Build the JP-only ``func_08077810`` background resource group.

The Japanese implementation uses three direct assets which do not share the
overseas stream layout: a 96-tile 4bpp sheet, one 16-colour BGR555 palette,
and a 32-by-20 BG tilemap.  The sources below preserve those physical
boundaries and native codecs; they intentionally do not claim that this is
the same screen or resource family as the US/EU/DE group.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff4_lz2, encode_huff4_lz3  # type: ignore[import-not-found]
from tile_grid import (  # type: ignore[import-not-found]
    bgr555_from_colors,
    colors_from_bgr555,
    decode,
    encode,
    read_png,
    write_png,
)


TILES = (0x4D4DDC, 0x4C0, 0xC00, "130", "1410", "tiles.0x70")
PALETTE = (0x4D529C, 0x20, "palette.gbapal")
TILEMAP = (0x4D52BC, 0x98, 0x500, "120", "12345610", "layer_1.tilemap.0x70")
TILE_WIDTH = 128
TILE_HEIGHT = 48
SOURCE_TILES = "tiles.png"
SOURCE_TILEMAP = "layer_1.tilemap"


def read_range(rom: bytes, offset: int, length: int, name: str) -> bytes:
    payload = rom[offset:offset + length]
    if len(payload) != length:
        raise ValueError(f"{name} range exceeds the JP ROM")
    return payload


def decode_stream(rom: bytes, stream: tuple[int, int, int, str, str, str], name: str) -> bytes:
    offset, length, decoded_size, format_spec, ladder, _output = stream
    decoded, actual_format, actual_ladder = unpack(read_range(rom, offset, length, name))
    if (len(decoded), actual_format, actual_ladder) != (decoded_size, format_spec, ladder):
        raise ValueError(
            f"{name} decoded as {len(decoded):#x} / {actual_format} / {actual_ladder}; "
            f"expected {decoded_size:#x} / {format_spec} / {ladder}"
        )
    return bytes(decoded)


def rebuild(source: bytes, baseline: bytes, stream: tuple[int, int, int, str, str, str], name: str) -> bytes:
    _offset, slot_size, decoded_size, format_spec, ladder, _output = stream
    original, actual_format, actual_ladder = unpack(baseline)
    if (len(source), len(original), actual_format, actual_ladder) != (
        decoded_size, decoded_size, format_spec, ladder,
    ):
        raise ValueError(f"{name} source or baseline no longer matches its proven native contract")
    if source == bytes(original):
        return baseline
    if format_spec == "130":
        encoded = encode_huff4_lz3(source, ladder)
    elif format_spec == "120":
        encoded = encode_huff4_lz2(source, ladder)
    else:  # Defensive: all supported formats are asserted above.
        raise AssertionError(f"unsupported {name} format {format_spec}")
    if len(encoded) > slot_size:
        raise ValueError(f"edited {name} needs {len(encoded):#x}; native slot holds only {slot_size:#x}")
    result = encoded + bytes(slot_size - len(encoded))
    checked, checked_format, checked_ladder = unpack(result)
    if (bytes(checked), checked_format, checked_ladder) != (source, format_spec, ladder):
        raise AssertionError(f"rebuilt {name} failed strict native decode validation")
    return result


def source_payload(source_dir: Path) -> tuple[bytes, bytes, bytes]:
    pixels, width, height, colors = read_png(source_dir / SOURCE_TILES, 4)
    if (width, height) != (TILE_WIDTH, TILE_HEIGHT):
        raise ValueError(f"{SOURCE_TILES} must remain {TILE_WIDTH}x{TILE_HEIGHT} indexed 4bpp")
    tiles = encode(pixels, width, height, 4)
    if len(tiles) != TILES[2]:
        raise AssertionError("tile PNG no longer encodes to the proven 0xC00-byte domain")
    palette = bgr555_from_colors(colors, 4)
    if len(palette) != PALETTE[1]:
        raise AssertionError("tile PNG palette no longer encodes to one BGR555 bank")
    tilemap = (source_dir / SOURCE_TILEMAP).read_bytes()
    if len(tilemap) != TILEMAP[2]:
        raise ValueError(f"{SOURCE_TILEMAP} must remain exactly {TILEMAP[2]:#x} bytes")
    return tiles, palette, tilemap


def outputs(output_dir: Path) -> tuple[Path, Path, Path]:
    return output_dir / TILES[5], output_dir / PALETTE[2], output_dir / TILEMAP[5]


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    tile_source = arguments.source_dir / SOURCE_TILES
    map_source = arguments.source_dir / SOURCE_TILEMAP
    if not arguments.replace and any(path.exists() for path in (tile_source, map_source)):
        raise ValueError("JP sources already exist; pass --replace only to restore the retail source")
    tiles = decode_stream(rom, TILES, "JP tiles")
    palette = read_range(rom, PALETTE[0], PALETTE[1], "JP palette")
    tilemap = decode_stream(rom, TILEMAP, "JP tilemap")
    pixels, height = decode(tiles, TILE_WIDTH, 4)
    if height != TILE_HEIGHT:
        raise AssertionError("JP 4bpp tile sheet dimensions no longer match the proven payload")
    arguments.source_dir.mkdir(parents=True, exist_ok=True)
    write_png(tile_source, pixels, TILE_WIDTH, TILE_HEIGHT, colors_from_bgr555(palette, 4))
    map_source.write_bytes(tilemap)
    print(f"exported JP-only func_08077810 resources to {arguments.source_dir}")


def build(arguments: argparse.Namespace) -> None:
    tiles, palette, tilemap = source_payload(arguments.source_dir)
    rom = arguments.rom.read_bytes()
    tile_stream = rebuild(tiles, read_range(rom, TILES[0], TILES[1], "JP tiles"), TILES, "JP tiles")
    map_stream = rebuild(tilemap, read_range(rom, TILEMAP[0], TILEMAP[1], "JP tilemap"), TILEMAP, "JP tilemap")
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    tile_output, palette_output, map_output = outputs(arguments.output_dir)
    tile_output.write_bytes(tile_stream)
    palette_output.write_bytes(palette)
    map_output.write_bytes(map_stream)
    print("rebuilt JP-only func_08077810 resources")


def verify(arguments: argparse.Namespace) -> None:
    tiles, palette, tilemap = source_payload(arguments.source_dir)
    rom = arguments.rom.read_bytes()
    tile_baseline = read_range(rom, TILES[0], TILES[1], "JP tiles")
    map_baseline = read_range(rom, TILEMAP[0], TILEMAP[1], "JP tilemap")
    if rebuild(tiles, tile_baseline, TILES, "JP tiles") != tile_baseline:
        raise AssertionError("JP tile source does not reproduce retail bytes")
    if palette != read_range(rom, PALETTE[0], PALETTE[1], "JP palette"):
        raise AssertionError("JP palette source does not reproduce retail bytes")
    if rebuild(tilemap, map_baseline, TILEMAP, "JP tilemap") != map_baseline:
        raise AssertionError("JP tilemap source does not reproduce retail bytes")
    if arguments.output_dir is not None:
        tile_output, palette_output, map_output = outputs(arguments.output_dir)
        if (tile_output.read_bytes(), palette_output.read_bytes(), map_output.read_bytes()) != (
            tile_baseline,
            read_range(rom, PALETTE[0], PALETTE[1], "JP palette"),
            map_baseline,
        ):
            raise AssertionError("built JP-only outputs differ from retail bytes")
    print("verified JP-only func_08077810 resources against the retail JP ROM")


def patch_test(arguments: argparse.Namespace) -> None:
    tiles, palette, tilemap = source_payload(arguments.source_dir)
    original = arguments.rom.read_bytes()
    rebuilt = bytearray(original)
    rebuilt[TILES[0]:TILES[0] + TILES[1]] = rebuild(
        tiles, read_range(original, TILES[0], TILES[1], "JP tiles"), TILES, "JP tiles"
    )
    rebuilt[PALETTE[0]:PALETTE[0] + PALETTE[1]] = palette
    rebuilt[TILEMAP[0]:TILEMAP[0] + TILEMAP[1]] = rebuild(
        tilemap, read_range(original, TILEMAP[0], TILEMAP[1], "JP tilemap"), TILEMAP, "JP tilemap"
    )
    if bytes(rebuilt) != original:
        raise AssertionError("unchanged JP-only sources changed the complete ROM image")
    print("verified unchanged complete JP ROM patch")


def edit_test(arguments: argparse.Namespace) -> None:
    tiles, _palette, tilemap = source_payload(arguments.source_dir)
    rom = arguments.rom.read_bytes()
    tile_index = next(index for index, value in enumerate(tiles) if value not in (0, 0xF0, 0xFF))
    edited_tiles = bytearray(tiles)
    edited_tiles[tile_index] ^= 1
    tile_result = rebuild(bytes(edited_tiles), read_range(rom, TILES[0], TILES[1], "JP tiles"), TILES, "JP tiles")
    edited_map = bytearray(tilemap)
    edited_map[0] ^= 1
    map_result = rebuild(bytes(edited_map), read_range(rom, TILEMAP[0], TILEMAP[1], "JP tilemap"), TILEMAP, "JP tilemap")
    print(f"JP-only edit test: tiles {len(tile_result):#x}/{TILES[1]:#x}, tilemap {len(map_result):#x}/{TILEMAP[1]:#x}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for name in ("export", "build", "verify", "patch-test", "edit-test"):
        command = commands.add_parser(name)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        if name == "export":
            command.add_argument("--replace", action="store_true")
        if name in ("build", "verify"):
            command.add_argument("--output-dir", type=Path)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        if arguments.output_dir is None:
            raise ValueError("build requires --output-dir")
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch-test":
        patch_test(arguments)
    else:
        edit_test(arguments)


if __name__ == "__main__":
    main()

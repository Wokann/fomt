#!/usr/bin/env python3
"""Manage the complete overseas ``func_08077810`` character stream.

The stream contains 351 complete 4bpp tiles followed by two bytes that are
loaded into VRAM with the same compressed payload but do not form a tile.  The
two-byte trailer is therefore kept as an explicit binary source rather than
being silently discarded or presented as pixels.  US, EU, and DE share the
complete packed range; JP has no matching consumer and remains untouched.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

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


REGIONS = ("us", "eu", "de")
STREAMS = {
    "us": (0x74E648, 0x4F8),
    "eu": (0x74E6A4, 0x4F8),
    "de": (0x4D5AB4, 0x4F8),
}
PALETTES = {
    "us": (0x74EB40, 0x20),
    "eu": (0x74EB9C, 0x20),
    "de": (0x4D5FAC, 0x20),
}
PACKED_SHA256 = "40a4339338b7d0a11335c325d697c1f9971bc5fdcabf1ccb1883ccb22e44ec87"
PALETTE_SHA256 = "51d75bd9affde28e7b4baf19af92de0b3c648b203b5944a8ad173bf63622792b"
FORMAT = "230"
DECODED_LENGTH = 0x2BE2
TILE_LENGTH = 0x2BE0
TRAILER_LENGTH = DECODED_LENGTH - TILE_LENGTH
TILE_WIDTH = 216  # 27 tiles per row; 351 total tiles form 27 rows.
TILE_HEIGHT = 104
SOURCE_TILES = "tiles.png"
SOURCE_TRAILER = "tiles_trailer.bin"
OUTPUT_STREAM = "tiles.0x70"
OUTPUT_PALETTE = "palette.gbapal"


def read_range(rom: bytes, table: dict[str, tuple[int, int]], region: str, expected_hash: str) -> bytes:
    offset, length = table[region]
    payload = rom[offset:offset + length]
    if len(payload) != length:
        raise ValueError(f"{region.upper()} range exceeds ROM bounds")
    if hashlib.sha256(payload).hexdigest() != expected_hash:
        raise ValueError(f"{region.upper()} range does not match the verified retail payload")
    return payload


def decode_stream(rom: bytes, region: str) -> bytes:
    payload = read_range(rom, STREAMS, region, PACKED_SHA256)
    decoded, format_spec, _ladder = unpack(payload)
    if len(decoded) != DECODED_LENGTH or format_spec != FORMAT:
        raise ValueError(
            f"{region.upper()} character stream decoded as {len(decoded):#x} / {format_spec}; "
            f"expected {DECODED_LENGTH:#x} / {FORMAT}"
        )
    return bytes(decoded)


def sources(source_dir: Path) -> tuple[Path, Path]:
    return (
        source_dir / SOURCE_TILES,
        source_dir / SOURCE_TRAILER,
    )


def source_payload(source_dir: Path) -> tuple[bytes, bytes]:
    tile_source, trailer_source = sources(source_dir)
    pixels, width, height, colors = read_png(tile_source, 4)
    if (width, height) != (TILE_WIDTH, TILE_HEIGHT):
        raise ValueError(f"{tile_source} must remain {TILE_WIDTH}x{TILE_HEIGHT} indexed 4bpp")
    tiles = encode(pixels, width, height, 4)
    if len(tiles) != TILE_LENGTH:
        raise AssertionError("tile PNG does not encode to the proven character-data length")
    trailer = trailer_source.read_bytes()
    if len(trailer) != TRAILER_LENGTH:
        raise ValueError(f"{trailer_source} must contain exactly {TRAILER_LENGTH} non-tile bytes")
    palette = bgr555_from_colors(colors, 4)
    return tiles + trailer, palette


def rebuild(decoded: bytes, baseline: bytes) -> bytes:
    original, original_format, _original_ladder = unpack(baseline)
    if len(original) != DECODED_LENGTH or len(decoded) != DECODED_LENGTH or original_format != FORMAT:
        raise AssertionError("baseline does not match the established character-stream contract")
    if decoded == bytes(original):
        return baseline
    encoded = encode_huff8_lz3(decoded)
    if len(encoded) > len(baseline):
        raise ValueError(
            f"edited character stream needs {len(encoded):#x} bytes; "
            f"the original fixed slot holds {len(baseline):#x}"
        )
    result = encoded + bytes(len(baseline) - len(encoded))
    checked, format_spec, _ladder = unpack(result)
    if bytes(checked) != decoded or format_spec != FORMAT:
        raise AssertionError("rebuilt character stream failed strict native decode validation")
    return result


def export(arguments: argparse.Namespace) -> None:
    roms = {region: path.read_bytes() for region, path in arguments.rom}
    if set(roms) != set(REGIONS):
        raise ValueError("export requires exactly US, EU, and DE ROMs")
    decoded = {region: decode_stream(rom, region) for region, rom in roms.items()}
    palettes = {region: read_range(rom, PALETTES, region, PALETTE_SHA256) for region, rom in roms.items()}
    if len(set(decoded.values())) != 1 or len(set(palettes.values())) != 1:
        raise ValueError("overseas character stream or palette differs; refusing a shared source")
    output = arguments.source_dir
    output.mkdir(parents=True, exist_ok=True)
    tile_source, trailer_source = sources(output)
    if not arguments.replace and any(path.exists() for path in (tile_source, trailer_source)):
        raise ValueError("shared sources already exist; pass --replace to refresh them")
    payload = decoded["us"]
    pixels, height = decode(payload[:TILE_LENGTH], TILE_WIDTH, 4)
    if height != TILE_HEIGHT:
        raise AssertionError("proven tile grid dimensions no longer match the decoded payload")
    palette = palettes["us"]
    write_png(tile_source, pixels, TILE_WIDTH, TILE_HEIGHT, colors_from_bgr555(palette, 4))
    trailer_source.write_bytes(payload[TILE_LENGTH:])
    print(f"exported shared US/EU/DE character tiles and trailer to {output}")


def build(arguments: argparse.Namespace) -> None:
    if arguments.region == "jp":
        print("verified JP: func_08077810 has no matching character-stream consumer")
        return
    decoded, palette = source_payload(arguments.source_dir)
    rom = arguments.rom.read_bytes()
    packed = rebuild(decoded, read_range(rom, STREAMS, arguments.region, PACKED_SHA256))
    arguments.output_dir.mkdir(parents=True, exist_ok=True)
    (arguments.output_dir / OUTPUT_STREAM).write_bytes(packed)
    (arguments.output_dir / OUTPUT_PALETTE).write_bytes(palette)
    print(f"rebuilt func_08077810 character stream for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    if arguments.region == "jp":
        print("verified JP: func_08077810 has no matching character-stream consumer")
        return
    decoded, palette = source_payload(arguments.source_dir)
    rom = arguments.rom.read_bytes()
    baseline = read_range(rom, STREAMS, arguments.region, PACKED_SHA256)
    if rebuild(decoded, baseline) != baseline:
        raise AssertionError(f"{arguments.region.upper()} character source does not reproduce retail bytes")
    if palette != read_range(rom, PALETTES, arguments.region, PALETTE_SHA256):
        raise AssertionError(f"{arguments.region.upper()} palette source does not reproduce retail bytes")
    if arguments.output_dir is not None:
        if (arguments.output_dir / OUTPUT_STREAM).read_bytes() != baseline:
            raise AssertionError(f"{arguments.region.upper()} built character stream does not match retail bytes")
        if (arguments.output_dir / OUTPUT_PALETTE).read_bytes() != palette:
            raise AssertionError(f"{arguments.region.upper()} built character palette does not match retail bytes")
    print(f"verified func_08077810 character stream against {arguments.region.upper()} ROM")


def edit_test(arguments: argparse.Namespace) -> None:
    decoded, _palette = source_payload(arguments.source_dir)
    edited = bytearray(decoded)
    index = next(index for index, value in enumerate(edited[:TILE_LENGTH]) if value not in (0, 0xF0, 0xFF))
    edited[index] ^= 1
    rebuilt = rebuild(bytes(edited), read_range(arguments.rom.read_bytes(), STREAMS, "us", PACKED_SHA256))
    if len(rebuilt) != STREAMS["us"][1]:
        raise AssertionError("edited character stream escaped its fixed native slot")
    print(f"func_08077810 character tile edit test: byte {index:#x}; packed {len(rebuilt):#x} bytes")


def patch_test(arguments: argparse.Namespace) -> None:
    decoded, palette = source_payload(arguments.source_dir)
    for region, path in arguments.rom:
        original = path.read_bytes()
        rebuilt = bytearray(original)
        if region in REGIONS:
            stream = rebuild(decoded, read_range(original, STREAMS, region, PACKED_SHA256))
            stream_offset, stream_length = STREAMS[region]
            palette_offset, palette_length = PALETTES[region]
            rebuilt[stream_offset:stream_offset + stream_length] = stream
            rebuilt[palette_offset:palette_offset + palette_length] = palette
        if rebuilt != original:
            raise AssertionError(f"unchanged {region.upper()} source changed the complete ROM image")
    print(f"verified unchanged full-ROM patch for {len(arguments.rom)} regional inputs")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--region", choices=("jp", *REGIONS), required=True)
        command.add_argument("--rom", type=Path, required=True)
        command.add_argument("--source-dir", type=Path, required=True)
        command.add_argument("--output-dir", type=Path)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--rom", type=Path, required=True)
    edit_parser.add_argument("--source-dir", type=Path, required=True)
    patch_parser = commands.add_parser("patch-test")
    patch_parser.add_argument("--source-dir", type=Path, required=True)
    patch_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        regions = [region for region, _ in arguments.rom]
        if len(set(regions)) != len(regions) or any(region not in REGIONS for region in regions):
            raise ValueError("export ROM arguments must be one each of US, EU, and DE")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        export(arguments)
    elif arguments.command == "build":
        if arguments.output_dir is None:
            raise ValueError("build requires --output-dir")
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        regions = [region for region, _ in arguments.rom]
        if len(set(regions)) != len(regions) or any(region not in ("jp", *REGIONS) for region in regions):
            raise ValueError("patch test regions must be unique JP/US/EU/DE inputs")
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
        patch_test(arguments)


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Losslessly export, rebuild, and verify linear GBA 4bpp or 8bpp tile grids.

This handles an asset whose native tile order is ordinary left-to-right,
top-to-bottom rows.  It intentionally does not guess OAM layout, compression,
or tile maps: those are separate resource classes with their own tools.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import zlib
from pathlib import Path


def number(value: str) -> int:
    return int(value, 0)


def chunk(kind: bytes, payload: bytes) -> bytes:
    return struct.pack(">I", len(payload)) + kind + payload + struct.pack(">I", zlib.crc32(kind + payload) & 0xFFFFFFFF)


def colors_from_bgr555(data: bytes, bpp: int) -> tuple[tuple[int, int, int, int], ...]:
    color_count = 1 << bpp
    if len(data) != color_count * 2:
        raise ValueError(f"a {bpp}bpp palette must be {color_count * 2} bytes")
    colors = []
    for index in range(color_count):
        value = struct.unpack_from("<H", data, index * 2)[0]
        colors.append((
            (value & 31) * 255 // 31,
            ((value >> 5) & 31) * 255 // 31,
            ((value >> 10) & 31) * 255 // 31,
            0 if index == 0 else 255,
        ))
    return tuple(colors)


def bgr555_from_colors(colors: tuple[tuple[int, int, int, int], ...], bpp: int) -> bytes:
    if len(colors) != 1 << bpp:
        raise ValueError(f"the indexed PNG must retain exactly {1 << bpp} palette entries")
    return b"".join(struct.pack("<H", (red * 31 + 127) // 255 | ((green * 31 + 127) // 255 << 5) | ((blue * 31 + 127) // 255 << 10))
                    for red, green, blue, _ in colors)


def write_png(path: Path, pixels: bytes, width: int, height: int, colors: tuple[tuple[int, int, int, int], ...]) -> None:
    if len(pixels) != width * height:
        raise ValueError("wrong indexed image size")
    rows = b"".join(b"\0" + pixels[y * width:(y + 1) * width] for y in range(height))
    png = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0))
           + chunk(b"PLTE", bytes(component for color in colors for component in color[:3]))
           + chunk(b"tRNS", bytes(color[3] for color in colors))
           + chunk(b"IDAT", zlib.compress(rows, 9)) + chunk(b"IEND", b""))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(png)


def read_png(path: Path, bpp: int) -> tuple[bytes, int, int, tuple[tuple[int, int, int, int], ...]]:
    data = path.read_bytes()
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        raise ValueError(f"{path} is not a PNG")
    cursor, palette, alpha, compressed = 8, b"", b"", bytearray()
    width = height = depth = color_type = -1
    while cursor < len(data):
        size = struct.unpack_from(">I", data, cursor)[0]
        kind, payload = data[cursor + 4:cursor + 8], data[cursor + 8:cursor + 8 + size]
        if len(payload) != size:
            raise ValueError(f"{path} has a truncated PNG chunk")
        if kind == b"IHDR":
            width, height, depth, color_type, compression, filtering, interlace = struct.unpack(">IIBBBBB", payload)
            if (depth, color_type, compression, filtering, interlace) != (8, 3, 0, 0, 0):
                raise ValueError(f"{path} must be an 8-bit non-interlaced indexed PNG")
        elif kind == b"PLTE":
            palette = payload
        elif kind == b"tRNS":
            alpha = payload
        elif kind == b"IDAT":
            compressed.extend(payload)
        elif kind == b"IEND":
            break
        cursor += size + 12
    if width <= 0 or height <= 0 or width % 8 or height % 8:
        raise ValueError(f"{path} dimensions must be positive multiples of 8")
    color_count = 1 << bpp
    if len(palette) != color_count * 3 or len(alpha) != color_count:
        raise ValueError(f"{path} must retain a native {color_count}-colour palette")
    decoded = zlib.decompress(compressed)
    if len(decoded) != (width + 1) * height:
        raise ValueError(f"{path} has unexpected PNG rows")
    pixels = b"".join(decoded[row * (width + 1) + 1:(row + 1) * (width + 1)] for row in range(height))
    if any(index >= color_count for index in pixels) or any(decoded[row * (width + 1)] != 0 for row in range(height)):
        raise ValueError(f"{path} uses unsupported palette indexes or PNG row filters")
    colors = tuple((palette[i * 3], palette[i * 3 + 1], palette[i * 3 + 2], alpha[i]) for i in range(color_count))
    return pixels, width, height, colors


def decode(raw: bytes, width: int, bpp: int) -> tuple[bytes, int]:
    bytes_per_tile = 32 if bpp == 4 else 64
    if width <= 0 or width % 8 or len(raw) % bytes_per_tile:
        raise ValueError("tile data and width must describe whole 8x8 tiles")
    tiles_per_row = width // 8
    if len(raw) // bytes_per_tile % tiles_per_row:
        raise ValueError("tile count does not fill the requested width")
    height = len(raw) // bytes_per_tile // tiles_per_row * 8
    pixels = bytearray(width * height)
    for tile_id in range(len(raw) // bytes_per_tile):
        tx, ty = tile_id % tiles_per_row * 8, tile_id // tiles_per_row * 8
        for y in range(8):
            if bpp == 4:
                for pair in range(4):
                    value = raw[tile_id * 32 + y * 4 + pair]
                    pixels[(ty + y) * width + tx + pair * 2] = value & 15
                    pixels[(ty + y) * width + tx + pair * 2 + 1] = value >> 4
            else:
                start = tile_id * 64 + y * 8
                pixels[(ty + y) * width + tx:(ty + y) * width + tx + 8] = raw[start:start + 8]
    return bytes(pixels), height


def encode(pixels: bytes, width: int, height: int, bpp: int) -> bytes:
    raw = bytearray()
    for ty in range(0, height, 8):
        for tx in range(0, width, 8):
            for y in range(8):
                if bpp == 4:
                    for pair in range(4):
                        first = pixels[(ty + y) * width + tx + pair * 2]
                        second = pixels[(ty + y) * width + tx + pair * 2 + 1]
                        raw.append(first | second << 4)
                else:
                    raw.extend(pixels[(ty + y) * width + tx:(ty + y) * width + tx + 8])
    return bytes(raw)


def export_payload(raw: bytes, palette: bytes, arguments: argparse.Namespace) -> None:
    palette_length = (1 << arguments.bpp) * 2
    if len(raw) != arguments.tiles_length or len(palette) != palette_length:
        raise ValueError("asset data does not match the requested native bounds")
    if hashlib.sha256(raw).hexdigest().lower() != arguments.sha256.lower():
        raise ValueError("tile range hash mismatch; refusing to export an unverified asset")
    if arguments.output.exists() and not arguments.replace:
        raise ValueError(f"{arguments.output} exists; pass --replace to overwrite it")
    if arguments.palette_sha256 and hashlib.sha256(palette).hexdigest().lower() != arguments.palette_sha256.lower():
        raise ValueError("palette range hash mismatch; refusing to export an unverified asset")
    pixels, height = decode(raw, arguments.width, arguments.bpp)
    write_png(arguments.output, pixels, arguments.width, height, colors_from_bgr555(palette, arguments.bpp))
    print(f"exported verified {arguments.width}x{height} indexed tile grid to {arguments.output}")


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    palette_length = (1 << arguments.bpp) * 2
    raw = rom[arguments.tiles_offset:arguments.tiles_offset + arguments.tiles_length]
    palette = rom[arguments.palette_offset:arguments.palette_offset + palette_length]
    export_payload(raw, palette, arguments)


def export_unpacked(arguments: argparse.Namespace) -> None:
    """Export a linear tile grid stored in a verified native ``0x70`` stream."""
    import sys

    sys.path.insert(0, str(Path(__file__).with_name("scripts")))
    from decompress import unpack  # type: ignore[import-not-found]

    rom = arguments.rom.read_bytes()
    packed = rom[arguments.stream_offset:arguments.stream_offset + arguments.stream_length]
    if len(packed) != arguments.stream_length:
        raise ValueError("ROM ends before the requested packed stream")
    if hashlib.sha256(packed).hexdigest().lower() != arguments.stream_sha256.lower():
        raise ValueError("packed stream hash mismatch; refusing to export an unverified asset")
    raw, _format, _ladder = unpack(packed)
    palette_length = (1 << arguments.bpp) * 2
    palette = rom[arguments.palette_offset:arguments.palette_offset + palette_length]
    export_payload(raw, palette, arguments)


def build(arguments: argparse.Namespace) -> None:
    pixels, width, height, colors = read_png(arguments.source, arguments.bpp)
    arguments.tiles.parent.mkdir(parents=True, exist_ok=True)
    arguments.palette.parent.mkdir(parents=True, exist_ok=True)
    arguments.tiles.write_bytes(encode(pixels, width, height, arguments.bpp))
    arguments.palette.write_bytes(bgr555_from_colors(colors, arguments.bpp))
    print(f"rebuilt {width}x{height} tile grid")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("rom", type=Path)
    export_parser.add_argument("--tiles-offset", type=number, required=True)
    export_parser.add_argument("--tiles-length", type=number, required=True)
    export_parser.add_argument("--palette-offset", type=number, required=True)
    export_parser.add_argument("--width", type=int, required=True)
    export_parser.add_argument("--bpp", type=int, choices=(4, 8), default=4)
    export_parser.add_argument("--sha256", required=True)
    export_parser.add_argument("--palette-sha256")
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    unpacked_parser = commands.add_parser("export-unpacked")
    unpacked_parser.add_argument("rom", type=Path)
    unpacked_parser.add_argument("--stream-offset", type=number, required=True)
    unpacked_parser.add_argument("--stream-length", type=number, required=True)
    unpacked_parser.add_argument("--stream-sha256", required=True)
    unpacked_parser.add_argument("--tiles-length", type=number, required=True)
    unpacked_parser.add_argument("--palette-offset", type=number, required=True)
    unpacked_parser.add_argument("--width", type=int, required=True)
    unpacked_parser.add_argument("--bpp", type=int, choices=(4, 8), default=4)
    unpacked_parser.add_argument("--sha256", required=True)
    unpacked_parser.add_argument("--palette-sha256")
    unpacked_parser.add_argument("--output", type=Path, required=True)
    unpacked_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--tiles", type=Path, required=True)
    build_parser.add_argument("--palette", type=Path, required=True)
    build_parser.add_argument("--bpp", type=int, choices=(4, 8), default=4)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "export-unpacked":
        export_unpacked(arguments)
    else:
        build(arguments)


if __name__ == "__main__":
    main()

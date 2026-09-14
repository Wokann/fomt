#!/usr/bin/env python3
"""Losslessly export, rebuild, and verify linear GBA 4bpp tile grids.

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


def colors_from_bgr555(data: bytes) -> tuple[tuple[int, int, int, int], ...]:
    if len(data) != 32:
        raise ValueError("a 4bpp palette must be 32 bytes")
    colors = []
    for index in range(16):
        value = struct.unpack_from("<H", data, index * 2)[0]
        colors.append((
            (value & 31) * 255 // 31,
            ((value >> 5) & 31) * 255 // 31,
            ((value >> 10) & 31) * 255 // 31,
            0 if index == 0 else 255,
        ))
    return tuple(colors)


def bgr555_from_colors(colors: tuple[tuple[int, int, int, int], ...]) -> bytes:
    if len(colors) != 16:
        raise ValueError("the indexed PNG must retain exactly 16 palette entries")
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


def read_png(path: Path) -> tuple[bytes, int, int, tuple[tuple[int, int, int, int], ...]]:
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
    if len(palette) != 48 or len(alpha) != 16:
        raise ValueError(f"{path} must retain a native 16-colour palette")
    decoded = zlib.decompress(compressed)
    if len(decoded) != (width + 1) * height:
        raise ValueError(f"{path} has unexpected PNG rows")
    pixels = b"".join(decoded[row * (width + 1) + 1:(row + 1) * (width + 1)] for row in range(height))
    if any(index >= 16 for index in pixels) or any(decoded[row * (width + 1)] != 0 for row in range(height)):
        raise ValueError(f"{path} uses unsupported palette indexes or PNG row filters")
    colors = tuple((palette[i * 3], palette[i * 3 + 1], palette[i * 3 + 2], alpha[i]) for i in range(16))
    return pixels, width, height, colors


def decode(raw: bytes, width: int) -> tuple[bytes, int]:
    if width <= 0 or width % 8 or len(raw) % 32:
        raise ValueError("tile data and width must describe whole 8x8 tiles")
    tiles_per_row = width // 8
    if len(raw) // 32 % tiles_per_row:
        raise ValueError("tile count does not fill the requested width")
    height = len(raw) // 32 // tiles_per_row * 8
    pixels = bytearray(width * height)
    for tile_id in range(len(raw) // 32):
        tx, ty = tile_id % tiles_per_row * 8, tile_id // tiles_per_row * 8
        for y in range(8):
            for pair in range(4):
                value = raw[tile_id * 32 + y * 4 + pair]
                pixels[(ty + y) * width + tx + pair * 2] = value & 15
                pixels[(ty + y) * width + tx + pair * 2 + 1] = value >> 4
    return bytes(pixels), height


def encode(pixels: bytes, width: int, height: int) -> bytes:
    raw = bytearray()
    for ty in range(0, height, 8):
        for tx in range(0, width, 8):
            for y in range(8):
                for pair in range(4):
                    first = pixels[(ty + y) * width + tx + pair * 2]
                    second = pixels[(ty + y) * width + tx + pair * 2 + 1]
                    raw.append(first | second << 4)
    return bytes(raw)


def export(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    raw = rom[arguments.tiles_offset:arguments.tiles_offset + arguments.tiles_length]
    palette = rom[arguments.palette_offset:arguments.palette_offset + 32]
    if len(raw) != arguments.tiles_length or len(palette) != 32:
        raise ValueError("ROM ends before the requested asset range")
    if hashlib.sha256(raw).hexdigest().lower() != arguments.sha256.lower():
        raise ValueError("tile range hash mismatch; refusing to export an unverified asset")
    if arguments.output.exists() and not arguments.replace:
        raise ValueError(f"{arguments.output} exists; pass --replace to overwrite it")
    pixels, height = decode(raw, arguments.width)
    write_png(arguments.output, pixels, arguments.width, height, colors_from_bgr555(palette))
    print(f"exported verified {arguments.width}x{height} indexed tile grid to {arguments.output}")


def build(arguments: argparse.Namespace) -> None:
    pixels, width, height, colors = read_png(arguments.source)
    arguments.tiles.parent.mkdir(parents=True, exist_ok=True)
    arguments.palette.parent.mkdir(parents=True, exist_ok=True)
    arguments.tiles.write_bytes(encode(pixels, width, height))
    arguments.palette.write_bytes(bgr555_from_colors(colors))
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
    export_parser.add_argument("--sha256", required=True)
    export_parser.add_argument("--output", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source", type=Path, required=True)
    build_parser.add_argument("--tiles", type=Path, required=True)
    build_parser.add_argument("--palette", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    else:
        build(arguments)


if __name__ == "__main__":
    main()

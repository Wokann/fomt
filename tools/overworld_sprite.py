#!/usr/bin/env python3
"""Losslessly export and rebuild FoMT's fixed six-tile overworld sprite frames.

The covered resource class consists of a 16x16 body (four sequential 4bpp
tiles) and an 8x16 lower-body strip (two sequential tiles) drawn at x=4.  The
tool deliberately exposes each frame as a complete 16x32 indexed PNG instead
of a raw tile sheet, while rebuilding the original six-tile physical order.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import zlib
from pathlib import Path


FRAME_WIDTH = 16
FRAME_HEIGHT = 32
TILE_BYTES = 32
FRAME_TILES = 6
FRAME_BYTES = FRAME_TILES * TILE_BYTES


def read_u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def colors_from_bgr555(raw: bytes) -> tuple[tuple[int, int, int, int], ...]:
    if len(raw) != 32:
        raise ValueError("a 4bpp palette must contain exactly 32 bytes")
    colors = []
    for index in range(16):
        value = read_u16(raw, index * 2)
        colors.append((
            (value & 0x1F) * 255 // 31,
            ((value >> 5) & 0x1F) * 255 // 31,
            ((value >> 10) & 0x1F) * 255 // 31,
            0 if index == 0 else 255,
        ))
    return tuple(colors)


def bgr555_from_colors(colors: tuple[tuple[int, int, int, int], ...]) -> bytes:
    if len(colors) != 16:
        raise ValueError("an indexed sprite PNG must contain exactly 16 palette entries")
    encoded = bytearray()
    for red, green, blue, _alpha in colors:
        value = ((red * 31 + 127) // 255
                 | ((green * 31 + 127) // 255) << 5
                 | ((blue * 31 + 127) // 255) << 10)
        encoded.extend(struct.pack("<H", value))
    return bytes(encoded)


def chunk(kind: bytes, payload: bytes) -> bytes:
    return (struct.pack(">I", len(payload)) + kind + payload
            + struct.pack(">I", zlib.crc32(kind + payload) & 0xFFFFFFFF))


def write_indexed_png(path: Path, indexes: bytes, colors: tuple[tuple[int, int, int, int], ...],
                      width: int = FRAME_WIDTH, height: int = FRAME_HEIGHT) -> None:
    if len(indexes) != width * height:
        raise ValueError("invalid indexed PNG pixel count")
    palette = bytes(component for color in colors for component in color[:3])
    alpha = bytes(color[3] for color in colors)
    rows = b"".join(
        b"\x00" + indexes[row * width:(row + 1) * width]
        for row in range(height)
    )
    output = (b"\x89PNG\r\n\x1a\n"
              + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0))
              + chunk(b"PLTE", palette)
              + chunk(b"tRNS", alpha)
              + chunk(b"IDAT", zlib.compress(rows, level=9))
              + chunk(b"IEND", b""))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(output)


def read_indexed_png(path: Path) -> tuple[bytes, tuple[tuple[int, int, int, int], ...]]:
    data = path.read_bytes()
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        raise ValueError(f"{path} is not a PNG")
    cursor = 8
    width = height = 0
    palette = b""
    alpha = b""
    compressed = bytearray()
    while cursor < len(data):
        if cursor + 12 > len(data):
            raise ValueError(f"{path} has a truncated PNG chunk")
        size = struct.unpack_from(">I", data, cursor)[0]
        kind = data[cursor + 4:cursor + 8]
        payload = data[cursor + 8:cursor + 8 + size]
        if len(payload) != size:
            raise ValueError(f"{path} has a truncated PNG payload")
        if kind == b"IHDR":
            width, height, depth, color_type, compression, filtering, interlace = struct.unpack(
                ">IIBBBBB", payload
            )
            if (width, height, depth, color_type, compression, filtering, interlace) != (
                FRAME_WIDTH, FRAME_HEIGHT, 8, 3, 0, 0, 0
            ):
                raise ValueError(f"{path} must be a {FRAME_WIDTH}x{FRAME_HEIGHT} non-interlaced indexed PNG")
        elif kind == b"PLTE":
            palette = payload
        elif kind == b"tRNS":
            alpha = payload
        elif kind == b"IDAT":
            compressed.extend(payload)
        elif kind == b"IEND":
            break
        cursor += size + 12
    if len(palette) != 48 or len(alpha) != 16:
        raise ValueError(f"{path} must retain its native 16-colour palette and transparency")
    decoded = zlib.decompress(compressed)
    row_size = FRAME_WIDTH + 1
    if len(decoded) != FRAME_HEIGHT * row_size:
        raise ValueError(f"{path} has an unexpected indexed pixel payload")
    indexes = bytearray(FRAME_WIDTH * FRAME_HEIGHT)
    for row in range(FRAME_HEIGHT):
        start = row * row_size
        if decoded[start] != 0:
            raise ValueError(f"{path} uses a PNG row filter unsupported by this lossless pipeline")
        indexes[row * FRAME_WIDTH:(row + 1) * FRAME_WIDTH] = decoded[start + 1:start + row_size]
    if any(index >= 16 for index in indexes):
        raise ValueError(f"{path} uses a palette index outside its native 4bpp range")
    colors = tuple(
        (palette[index * 3], palette[index * 3 + 1], palette[index * 3 + 2], alpha[index])
        for index in range(16)
    )
    return bytes(indexes), colors


def decode_tile(data: bytes) -> bytes:
    if len(data) != TILE_BYTES:
        raise ValueError("invalid 4bpp tile")
    indexes = bytearray(64)
    for row in range(8):
        for pair in range(4):
            value = data[row * 4 + pair]
            indexes[row * 8 + pair * 2] = value & 0x0F
            indexes[row * 8 + pair * 2 + 1] = value >> 4
    return bytes(indexes)


def encode_tile(indexes: bytes) -> bytes:
    if len(indexes) != 64 or any(index >= 16 for index in indexes):
        raise ValueError("invalid 4bpp tile pixels")
    output = bytearray(TILE_BYTES)
    for row in range(8):
        for pair in range(4):
            output[row * 4 + pair] = indexes[row * 8 + pair * 2] | (indexes[row * 8 + pair * 2 + 1] << 4)
    return bytes(output)


def place_tile(frame: bytearray, tile: bytes, x: int, y: int) -> None:
    for row in range(8):
        frame[(y + row) * FRAME_WIDTH + x:(y + row) * FRAME_WIDTH + x + 8] = tile[row * 8:(row + 1) * 8]


def take_tile(frame: bytes, x: int, y: int) -> bytes:
    tile = bytearray(64)
    for row in range(8):
        tile[row * 8:(row + 1) * 8] = frame[(y + row) * FRAME_WIDTH + x:(y + row) * FRAME_WIDTH + x + 8]
    return bytes(tile)


def raw_to_frame(raw: bytes) -> bytes:
    if len(raw) != FRAME_BYTES:
        raise ValueError("invalid raw overworld frame")
    frame = bytearray(FRAME_WIDTH * FRAME_HEIGHT)
    for tile_id, (x, y) in enumerate(((0, 0), (8, 0), (0, 8), (8, 8), (4, 16), (4, 24))):
        place_tile(frame, decode_tile(raw[tile_id * TILE_BYTES:(tile_id + 1) * TILE_BYTES]), x, y)
    return bytes(frame)


def frame_to_raw(frame: bytes) -> bytes:
    if len(frame) != FRAME_WIDTH * FRAME_HEIGHT:
        raise ValueError("invalid full-frame PNG pixels")
    output = bytearray()
    for x, y in ((0, 0), (8, 0), (0, 8), (8, 8), (4, 16), (4, 24)):
        output.extend(encode_tile(take_tile(frame, x, y)))
    return bytes(output)


def parse_number(value: str) -> int:
    return int(value, 0)


def frame_paths(source: Path, expected_count: int | None = None) -> list[Path]:
    paths = sorted(source.glob("[0-9][0-9][0-9].png"))
    if not paths:
        raise ValueError(f"{source} contains no numbered frame PNGs")
    expected_names = [f"{index:03d}.png" for index in range(len(paths))]
    if [path.name for path in paths] != expected_names:
        raise ValueError(f"{source} must contain consecutive names 000.png through {len(paths) - 1:03d}.png")
    if expected_count is not None and len(paths) != expected_count:
        raise ValueError(f"{source} has {len(paths)} frames; expected {expected_count}")
    return paths


def export_frames(rom_path: Path, tiles_offset: int, tiles_length: int, palette_offset: int,
                  output: Path, replace: bool) -> None:
    rom = rom_path.read_bytes()
    if tiles_length <= 0 or tiles_length % FRAME_BYTES:
        raise ValueError("tile length must be a positive multiple of six 4bpp tiles")
    raw = rom[tiles_offset:tiles_offset + tiles_length]
    palette = rom[palette_offset:palette_offset + 32]
    if len(raw) != tiles_length or len(palette) != 32:
        raise ValueError("ROM ends before requested sprite data")
    colors = colors_from_bgr555(palette)
    count = tiles_length // FRAME_BYTES
    existing = list(output.glob("*.png"))
    if existing and not replace:
        raise ValueError(f"{output} already contains source PNGs; pass --replace to regenerate them")
    if replace:
        for path in existing:
            path.unlink()
    for index in range(count):
        frame = raw_to_frame(raw[index * FRAME_BYTES:(index + 1) * FRAME_BYTES])
        write_indexed_png(output / f"{index:03d}.png", frame, colors)
    print(f"exported {count} full 16x32 frames to {output}")


def build_frames(source: Path, tiles_path: Path, palette_path: Path) -> None:
    paths = frame_paths(source)
    tiles = bytearray()
    native_palette: bytes | None = None
    for path in paths:
        frame, colors = read_indexed_png(path)
        palette = bgr555_from_colors(colors)
        if native_palette is None:
            native_palette = palette
        elif native_palette != palette:
            raise ValueError(f"{path} has a different palette from the first frame")
        tiles.extend(frame_to_raw(frame))
    assert native_palette is not None
    tiles_path.parent.mkdir(parents=True, exist_ok=True)
    palette_path.parent.mkdir(parents=True, exist_ok=True)
    tiles_path.write_bytes(tiles)
    palette_path.write_bytes(native_palette)
    print(f"rebuilt {len(paths)} frames: {len(tiles)} tile bytes and 32 palette bytes")


def write_contact_sheet(source: Path, output: Path, columns: int, scale: int) -> None:
    """Render numbered editable frames as an enlarged palette-indexed preview."""
    if columns <= 0 or scale <= 0:
        raise ValueError("contact-sheet columns and scale must be positive")
    paths = frame_paths(source)
    frames = []
    palette: tuple[tuple[int, int, int, int], ...] | None = None
    for path in paths:
        indexes, colors = read_indexed_png(path)
        if palette is None:
            palette = colors
        elif colors != palette:
            raise ValueError(f"{path} has a different palette from the first frame")
        frames.append(indexes)
    assert palette is not None
    rows = (len(frames) + columns - 1) // columns
    cell_width = FRAME_WIDTH * scale
    cell_height = FRAME_HEIGHT * scale
    width = columns * cell_width
    height = rows * cell_height
    indexes = bytearray(width * height)
    for frame_id, frame in enumerate(frames):
        cell_x = frame_id % columns * cell_width
        cell_y = frame_id // columns * cell_height
        for y in range(FRAME_HEIGHT):
            for x in range(FRAME_WIDTH):
                value = frame[y * FRAME_WIDTH + x]
                for scale_y in range(scale):
                    row = (cell_y + y * scale + scale_y) * width + cell_x + x * scale
                    indexes[row:row + scale] = bytes((value,)) * scale
    write_indexed_png(output, bytes(indexes), palette, width, height)
    print(f"wrote {len(frames)}-frame contact sheet to {output}")


def verify(rom_path: Path, tiles_offset: int, palette_offset: int, tiles_path: Path, palette_path: Path, expected_sha256: str | None) -> None:
    tiles = tiles_path.read_bytes()
    palette = palette_path.read_bytes()
    if len(tiles) == 0 or len(tiles) % FRAME_BYTES:
        raise ValueError("rebuilt tile data is not a whole number of six-tile frames")
    if len(palette) != 32:
        raise ValueError("rebuilt palette is not 32 bytes")
    if expected_sha256 and hashlib.sha256(tiles).hexdigest().lower() != expected_sha256.lower():
        raise ValueError("rebuilt tile stream does not match its declared SHA-256")
    rom = rom_path.read_bytes()
    reference_tiles = rom[tiles_offset:tiles_offset + len(tiles)]
    reference_palette = rom[palette_offset:palette_offset + len(palette)]
    if reference_tiles != tiles:
        raise ValueError(f"{rom_path}: tile stream differs from offset 0x{tiles_offset:X}")
    if reference_palette != palette:
        raise ValueError(f"{rom_path}: palette differs from offset 0x{palette_offset:X}")
    print(f"{rom_path}: {len(tiles) // FRAME_BYTES} frames, tiles and palette are byte-identical")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)

    export = subparsers.add_parser("export", help="export raw six-tile frames as indexed full PNGs")
    export.add_argument("rom", type=Path)
    export.add_argument("--tiles-offset", required=True, type=parse_number)
    export.add_argument("--tiles-length", required=True, type=parse_number)
    export.add_argument("--palette-offset", required=True, type=parse_number)
    export.add_argument("--output", required=True, type=Path)
    export.add_argument("--replace", action="store_true", help="replace existing numbered source PNGs")

    build = subparsers.add_parser("build", help="rebuild raw six-tile frames from indexed full PNGs")
    build.add_argument("--source", required=True, type=Path)
    build.add_argument("--tiles", required=True, type=Path)
    build.add_argument("--palette", required=True, type=Path)

    contact_sheet = subparsers.add_parser("contact-sheet", help="write an enlarged indexed preview of numbered source frames")
    contact_sheet.add_argument("--source", required=True, type=Path)
    contact_sheet.add_argument("--output", required=True, type=Path)
    contact_sheet.add_argument("--columns", type=int, default=8)
    contact_sheet.add_argument("--scale", type=int, default=4)

    check = subparsers.add_parser("verify", help="compare rebuilt streams with one ROM")
    check.add_argument("rom", type=Path)
    check.add_argument("--tiles-offset", required=True, type=parse_number)
    check.add_argument("--palette-offset", required=True, type=parse_number)
    check.add_argument("--tiles", required=True, type=Path)
    check.add_argument("--palette", required=True, type=Path)
    check.add_argument("--sha256")

    args = parser.parse_args()
    try:
        if args.command == "export":
            export_frames(args.rom, args.tiles_offset, args.tiles_length, args.palette_offset, args.output, args.replace)
        elif args.command == "build":
            build_frames(args.source, args.tiles, args.palette)
        elif args.command == "contact-sheet":
            write_contact_sheet(args.source, args.output, args.columns, args.scale)
        else:
            verify(args.rom, args.tiles_offset, args.palette_offset, args.tiles, args.palette, args.sha256)
    except (OSError, ValueError, zlib.error) as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()

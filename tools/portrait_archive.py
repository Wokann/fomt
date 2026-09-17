#!/usr/bin/env python3
"""Inspect FoMT's fixed-layout dialogue portrait archive without external packages.

The archive is an IndexedResourceArchive: a row of count-prefixed tables,
including portrait descriptors, OAM layouts, 4bpp tile data and BGR555
palettes.  This tool intentionally verifies those relationships before a
resource is treated as an editable image.
"""

from __future__ import annotations

import argparse
import hashlib
import re
import struct
import zlib
from dataclasses import dataclass
from pathlib import Path


TABLE_STRIDES = (4, 16, 8, 32, 32, 8, 4)
OAM_DIMENSIONS = {
    (0, 0): (8, 8), (0, 1): (16, 16), (0, 2): (32, 32), (0, 3): (64, 64),
    (1, 0): (16, 8), (1, 1): (32, 8), (1, 2): (32, 16), (1, 3): (64, 32),
    (2, 0): (8, 16), (2, 1): (8, 32), (2, 2): (16, 32), (2, 3): (32, 64),
}


@dataclass(frozen=True)
class Archive:
    data: bytes
    table_offsets: tuple[int, ...]
    counts: tuple[int, ...]
    trailing_offset: int

    @property
    def tile_count(self) -> int:
        return self.counts[3]


def read_u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def read_u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def load_archive(path: Path, offset: int, length: int, trailing_bytes: int = 32) -> Archive:
    """Load one indexed archive with an explicitly declared trailing payload.

    Portrait archives carry one unindexed 32-byte palette after their seven
    counted tables.  Other users of the same native archive format, such as
    actor animations, do not.  Keeping the tail size at the call site avoids
    silently treating unrelated bytes as a palette.
    """
    with path.open("rb") as stream:
        stream.seek(offset)
        data = stream.read(length)
    if len(data) != length:
        raise ValueError(f"ROM ends before archive at 0x{offset:X}")

    counts: list[int] = []
    table_offsets: list[int] = []
    cursor = 0
    for stride in TABLE_STRIDES:
        if cursor + 4 > len(data):
            raise ValueError("archive ends in a table count")
        count = read_u32(data, cursor)
        cursor += 4
        table_offsets.append(cursor)
        count_bytes = count * stride
        if cursor + count_bytes > len(data):
            raise ValueError("archive table exceeds declared archive range")
        counts.append(count)
        cursor += count_bytes
    if trailing_bytes < 0:
        raise ValueError("archive trailing byte count cannot be negative")
    if len(data) - cursor != trailing_bytes:
        raise ValueError(
            f"archive has {len(data) - cursor} unexpected bytes after the seventh table "
            f"(expected {trailing_bytes})"
        )
    return Archive(data, tuple(table_offsets), tuple(counts), cursor)


def portrait_descriptor(archive: Archive, portrait_id: int) -> tuple[int, int, int, int, int]:
    if not 0 <= portrait_id < archive.counts[0]:
        raise ValueError(f"portrait ID {portrait_id} is outside the table")
    entry_offset = archive.table_offsets[0] + portrait_id * 4
    descriptor_id = read_u16(archive.data, entry_offset + 2)
    if descriptor_id >= archive.counts[1]:
        raise ValueError(f"portrait {portrait_id} references descriptor {descriptor_id} out of range")
    descriptor_offset = archive.table_offsets[1] + descriptor_id * 16
    return (
        read_u16(archive.data, descriptor_offset),
        read_u16(archive.data, descriptor_offset + 2),
        read_u16(archive.data, descriptor_offset + 4),
        read_u16(archive.data, descriptor_offset + 6),
        read_u16(archive.data, descriptor_offset + 10),
    )


def audit(archive: Archive) -> None:
    if archive.counts[:7] != (184, 184, 1037, 11586, 52, 0, 184):
        raise ValueError(f"unexpected portrait archive table counts: {archive.counts}")

    claimed_tiles: dict[int, list[int]] = {}
    total_descriptor_tiles = 0
    highest_palette_id = 0
    for portrait_id in range(archive.counts[0]):
        oam_count, oam_start, tile_count, tile_start, palette_id = portrait_descriptor(archive, portrait_id)
        if oam_start + oam_count > archive.counts[2]:
            raise ValueError(f"portrait {portrait_id} OAM range is outside table three")
        if tile_start + tile_count > archive.counts[3]:
            raise ValueError(f"portrait {portrait_id} tile range is outside table four")
        if palette_id >= archive.counts[4]:
            raise ValueError(f"portrait {portrait_id} palette is outside table five")
        highest_palette_id = max(highest_palette_id, palette_id)
        total_descriptor_tiles += tile_count
        for tile in range(tile_start, tile_start + tile_count):
            claimed_tiles.setdefault(tile, []).append(portrait_id)

        for oam_id in range(oam_count):
            offset = archive.table_offsets[2] + (oam_start + oam_id) * 8
            attr0 = read_u16(archive.data, offset)
            attr1 = read_u16(archive.data, offset + 2)
            attr2 = read_u16(archive.data, offset + 4)
            dimensions = OAM_DIMENSIONS.get(((attr0 >> 14) & 3, (attr1 >> 14) & 3))
            if dimensions is None:
                raise ValueError(f"portrait {portrait_id} OAM {oam_id} has invalid shape/size")
            tile_width, tile_height = dimensions
            local_tile = attr2 & 0x3FF
            required_tiles = tile_width * tile_height // 64
            if local_tile + required_tiles > tile_count:
                raise ValueError(
                    f"portrait {portrait_id} OAM {oam_id} uses tiles outside its descriptor range"
                )

    overlap_count = sum(1 for owners in claimed_tiles.values() if len(owners) > 1)
    uncovered_count = archive.counts[3] - len(claimed_tiles)
    print(f"tables: {', '.join(map(str, archive.counts))}")
    print(f"descriptor tile total: {total_descriptor_tiles}")
    print(f"unique claimed tiles: {len(claimed_tiles)} / {archive.counts[3]}")
    print(f"overlapping tile slots: {overlap_count}")
    print(f"unclaimed tile slots: {uncovered_count}")
    print(f"highest referenced palette: {highest_palette_id} / {archive.counts[4] - 1}")
    print(f"unindexed trailing palette bytes: {len(archive.data) - archive.trailing_offset}")
    print("archive layout and every portrait OAM range verified")


def parse_names(path: Path | None) -> dict[int, str]:
    if path is None:
        return {}
    names: dict[int, str] = {}
    expression = re.compile(r"^\s*(TALK_PORTRAIT_[A-Z0-9_]+)\s*=\s*(\d+),", re.MULTILINE)
    for symbol, number in expression.findall(path.read_text(encoding="utf-8")):
        names[int(number)] = symbol
    return names


def display_name(portrait_id: int, names: dict[int, str]) -> str:
    return names.get(portrait_id, f"TALK_PORTRAIT_{portrait_id:03d}")


def portrait_source_file(source_directory: Path, kind: str, portrait_id: int) -> Path:
    """Resolve a source by its stable numeric filename prefix.

    The suffix is descriptive only.  This keeps a renamed enum or a better
    human label from changing the physical portrait binding, and avoids a
    second manifest that mirrors the files already present on disk.
    """
    matches = sorted((source_directory / kind).glob(f"{portrait_id:03d}_*.png"))
    if len(matches) == 1:
        return matches[0]
    if not matches:
        raise ValueError(f"missing {kind} PNG for portrait {portrait_id:03d}")
    names = ", ".join(path.name for path in matches)
    raise ValueError(f"multiple {kind} PNGs claim portrait {portrait_id:03d}: {names}")


def palette(archive: Archive, palette_id: int) -> tuple[tuple[int, int, int, int], ...]:
    offset = archive.table_offsets[4] + palette_id * 32
    colors: list[tuple[int, int, int, int]] = []
    for color_id in range(16):
        color = read_u16(archive.data, offset + color_id * 2)
        colors.append((
            (color & 0x1F) * 255 // 31,
            ((color >> 5) & 0x1F) * 255 // 31,
            ((color >> 10) & 0x1F) * 255 // 31,
            0 if color_id == 0 else 255,
        ))
    return tuple(colors)


def tile_pixels(archive: Archive, tile_id: int) -> tuple[int, ...]:
    if not 0 <= tile_id < archive.counts[3]:
        raise ValueError(f"tile {tile_id} is outside table four")
    offset = archive.table_offsets[3] + tile_id * 32
    pixels: list[int] = []
    for value in archive.data[offset:offset + 32]:
        pixels.append(value & 0x0F)
        pixels.append(value >> 4)
    return tuple(pixels)


def write_png_rgba(path: Path, width: int, height: int, pixels: bytes) -> None:
    if len(pixels) != width * height * 4:
        raise ValueError("invalid RGBA image buffer size")

    def chunk(kind: bytes, payload: bytes) -> bytes:
        return (
            struct.pack(">I", len(payload)) + kind + payload
            + struct.pack(">I", zlib.crc32(kind + payload) & 0xFFFFFFFF)
        )

    rows = b"".join(
        b"\x00" + pixels[row * width * 4:(row + 1) * width * 4]
        for row in range(height)
    )
    encoded = (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
        + chunk(b"IDAT", zlib.compress(rows, level=9))
        + chunk(b"IEND", b"")
    )
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(encoded)


def write_png_indexed(path: Path, width: int, height: int, indexes: bytes,
                      colors: tuple[tuple[int, int, int, int], ...]) -> None:
    if len(indexes) != width * height or len(colors) != 16:
        raise ValueError("invalid indexed portrait image")

    def chunk(kind: bytes, payload: bytes) -> bytes:
        return (
            struct.pack(">I", len(payload)) + kind + payload
            + struct.pack(">I", zlib.crc32(kind + payload) & 0xFFFFFFFF)
        )

    rows = b"".join(
        b"\x00" + indexes[row * width:(row + 1) * width]
        for row in range(height)
    )
    palette_data = bytes(component for color in colors for component in color[:3])
    transparency = bytes(color[3] for color in colors)
    encoded = (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0))
        + chunk(b"PLTE", palette_data)
        + chunk(b"tRNS", transparency)
        + chunk(b"IDAT", zlib.compress(rows, level=9))
        + chunk(b"IEND", b"")
    )
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(encoded)


def read_png_rgba(path: Path) -> tuple[int, int, bytes]:
    data = path.read_bytes()
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        raise ValueError(f"{path} is not a PNG")
    cursor = 8
    width = height = 0
    payload = bytearray()
    while cursor < len(data):
        if cursor + 12 > len(data):
            raise ValueError(f"{path} has a truncated PNG chunk")
        length = struct.unpack_from(">I", data, cursor)[0]
        kind = data[cursor + 4:cursor + 8]
        content = data[cursor + 8:cursor + 8 + length]
        if len(content) != length:
            raise ValueError(f"{path} has a truncated PNG payload")
        if kind == b"IHDR":
            width, height, depth, color_type, compression, filtering, interlace = struct.unpack(
                ">IIBBBBB", content
            )
            if (depth, color_type, compression, filtering, interlace) != (8, 6, 0, 0, 0):
                raise ValueError(f"{path} must be a non-interlaced RGBA8 PNG exported by portrait_archive")
        elif kind == b"IDAT":
            payload.extend(content)
        elif kind == b"IEND":
            break
        cursor += 12 + length
    if width <= 0 or height <= 0:
        raise ValueError(f"{path} has no valid PNG header")
    decoded = zlib.decompress(payload)
    stride = width * 4
    expected = height * (stride + 1)
    if len(decoded) != expected:
        raise ValueError(f"{path} has an unexpected PNG data length")
    pixels = bytearray(width * height * 4)
    for row in range(height):
        source = row * (stride + 1)
        if decoded[source] != 0:
            raise ValueError(f"{path} uses PNG filters not supported by this lossless pipeline")
        pixels[row * stride:(row + 1) * stride] = decoded[source + 1:source + 1 + stride]
    return width, height, bytes(pixels)


def read_png_indexed(path: Path) -> tuple[int, int, bytes, tuple[tuple[int, int, int, int], ...]]:
    data = path.read_bytes()
    if not data.startswith(b"\x89PNG\r\n\x1a\n"):
        raise ValueError(f"{path} is not a PNG")
    cursor = 8
    width = height = 0
    palette_data = b""
    transparency = b""
    payload = bytearray()
    while cursor < len(data):
        if cursor + 12 > len(data):
            raise ValueError(f"{path} has a truncated PNG chunk")
        length = struct.unpack_from(">I", data, cursor)[0]
        kind = data[cursor + 4:cursor + 8]
        content = data[cursor + 8:cursor + 8 + length]
        if len(content) != length:
            raise ValueError(f"{path} has a truncated PNG payload")
        if kind == b"IHDR":
            width, height, depth, color_type, compression, filtering, interlace = struct.unpack(
                ">IIBBBBB", content
            )
            if (depth, color_type, compression, filtering, interlace) != (8, 3, 0, 0, 0):
                raise ValueError(f"{path} must be an indexed PNG exported by portrait_archive")
        elif kind == b"PLTE":
            palette_data = content
        elif kind == b"tRNS":
            transparency = content
        elif kind == b"IDAT":
            payload.extend(content)
        elif kind == b"IEND":
            break
        cursor += 12 + length
    if width <= 0 or height <= 0 or len(palette_data) != 48 or len(transparency) != 16:
        raise ValueError(f"{path} has incomplete indexed palette metadata")
    colors = tuple(
        (palette_data[index * 3], palette_data[index * 3 + 1], palette_data[index * 3 + 2], transparency[index])
        for index in range(16)
    )
    decoded = zlib.decompress(payload)
    stride = width
    expected = height * (stride + 1)
    if len(decoded) != expected:
        raise ValueError(f"{path} has an unexpected PNG data length")
    indexes = bytearray(width * height)
    for row in range(height):
        source = row * (stride + 1)
        if decoded[source] != 0:
            raise ValueError(f"{path} uses PNG filters not supported by this lossless pipeline")
        indexes[row * stride:(row + 1) * stride] = decoded[source + 1:source + 1 + stride]
    if any(index >= 16 for index in indexes):
        raise ValueError(f"{path} uses a palette index outside its native 16-color palette")
    return width, height, bytes(indexes), colors


def render_tile_grid(archive: Archive, tile_start: int, tile_count: int,
                     colors: tuple[tuple[int, int, int, int], ...]) -> tuple[int, int, bytes]:
    tile_columns = 32
    width = tile_columns * 8
    height = ((tile_count + tile_columns - 1) // tile_columns) * 8
    indexes = bytearray(width * height)
    for local_tile in range(tile_count):
        tile_x = (local_tile % tile_columns) * 8
        tile_y = (local_tile // tile_columns) * 8
        values = tile_pixels(archive, tile_start + local_tile)
        for pixel_y in range(8):
            for pixel_x in range(8):
                indexes[(tile_y + pixel_y) * width + tile_x + pixel_x] = values[pixel_y * 8 + pixel_x]
    return width, height, bytes(indexes)


def portrait_oam(archive: Archive, portrait_id: int) -> list[tuple[int, int, int, int, int]]:
    oam_count, oam_start, tile_count, tile_start, _ = portrait_descriptor(archive, portrait_id)
    entries: list[tuple[int, int, int, int, int]] = []
    for oam_id in range(oam_count):
        offset = archive.table_offsets[2] + (oam_start + oam_id) * 8
        attr0 = read_u16(archive.data, offset)
        attr1 = read_u16(archive.data, offset + 2)
        attr2 = read_u16(archive.data, offset + 4)
        width, height = OAM_DIMENSIONS[((attr0 >> 14) & 3, (attr1 >> 14) & 3)]
        x = attr1 & 0x1FF
        y = attr0 & 0xFF
        if x > 255:
            x -= 512
        if y > 127:
            y -= 256
        local_tile = attr2 & 0x3FF
        if local_tile + width * height // 64 > tile_count:
            raise ValueError(f"portrait {portrait_id} OAM tile range failed validation")
        entries.append((x, y, width, height, tile_start + local_tile))
    return entries


def portrait_canvas(archive: Archive, portrait_id: int) -> tuple[int, int, int, int, list[tuple[int, int, int, int, int]]]:
    entries = portrait_oam(archive, portrait_id)
    min_x = min(entry[0] for entry in entries)
    min_y = min(entry[1] for entry in entries)
    max_x = max(entry[0] + entry[2] for entry in entries)
    max_y = max(entry[1] + entry[3] for entry in entries)
    return min_x, min_y, max_x - min_x, max_y - min_y, entries


def render_preview_indexes(archive: Archive, portrait_id: int) -> tuple[int, int, bytes]:
    min_x, min_y, width, height, entries = portrait_canvas(archive, portrait_id)
    indexes = bytearray(width * height)
    for x, y, sprite_width, sprite_height, tile_start in entries:
        tiles_wide = sprite_width // 8
        for tile_y in range(sprite_height // 8):
            for tile_x in range(tiles_wide):
                values = tile_pixels(archive, tile_start + tile_y * tiles_wide + tile_x)
                for pixel_y in range(8):
                    for pixel_x in range(8):
                        value = values[pixel_y * 8 + pixel_x]
                        if value == 0:
                            continue
                        target_x = x - min_x + tile_x * 8 + pixel_x
                        target_y = y - min_y + tile_y * 8 + pixel_y
                        indexes[target_y * width + target_x] = value
    return width, height, bytes(indexes)


def render_preview(archive: Archive, portrait_id: int,
                   colors: tuple[tuple[int, int, int, int], ...]) -> tuple[int, int, bytes]:
    width, height, indexes = render_preview_indexes(archive, portrait_id)
    pixels = bytearray(width * height * 4)
    for index, color_index in enumerate(indexes):
        if color_index == 0:
            continue
        pixels[index * 4:(index + 1) * 4] = bytes(colors[color_index])
    return width, height, bytes(pixels)


def export(archive: Archive, output: Path, names: dict[int, str]) -> None:
    audit(archive)
    for portrait_id in range(archive.counts[0]):
        symbol = display_name(portrait_id, names)
        _, _, tile_count, tile_start, palette_id = portrait_descriptor(archive, portrait_id)
        colors = palette(archive, palette_id)
        grid = render_tile_grid(archive, tile_start, tile_count, colors)
        preview = render_preview(archive, portrait_id, colors)
        full = render_preview_indexes(archive, portrait_id)
        filename = f"{portrait_id:03d}_{symbol}"
        write_png_indexed(output / "tiles" / f"{filename}.png", *grid, colors)
        write_png_indexed(output / "full" / f"{filename}.png", *full, colors)
        write_png_rgba(output / "preview" / f"{filename}.png", *preview)
    print(
        f"exported {archive.counts[0]} full indexed portraits, rendered previews, "
        f"and editable tile groups to {output}"
    )


def encode_tile(indexes: bytes, width: int, tile_x: int, tile_y: int) -> bytes:
    encoded = bytearray(32)
    for pixel_y in range(8):
        for pair in range(4):
            first = indexes[(tile_y + pixel_y) * width + tile_x + pair * 2]
            second = indexes[(tile_y + pixel_y) * width + tile_x + pair * 2 + 1]
            encoded[pixel_y * 4 + pair] = first | (second << 4)
    return bytes(encoded)


def rebuild(archive: Archive, source_directory: Path, output: Path) -> None:
    audit(archive)
    t4_offset = archive.table_offsets[3]
    native = bytearray(archive.data[t4_offset:t4_offset + archive.counts[3] * 32])
    assigned: dict[int, bytes] = {}
    for portrait_id in range(archive.counts[0]):
        _, _, tile_count, tile_start, palette_id = portrait_descriptor(archive, portrait_id)
        filename = portrait_source_file(source_directory, "tiles", portrait_id)
        width, height, indexes, source_palette = read_png_indexed(filename)
        expected_width = 32 * 8
        expected_height = ((tile_count + 31) // 32) * 8
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != palette(archive, palette_id):
            raise ValueError(f"{filename} has changed its native 16-color palette")
        for local_tile in range(tile_count):
            tile_x = (local_tile % 32) * 8
            tile_y = (local_tile // 32) * 8
            encoded = encode_tile(indexes, width, tile_x, tile_y)
            global_tile = tile_start + local_tile
            previous = assigned.setdefault(global_tile, encoded)
            if previous != encoded:
                raise ValueError(
                    f"portrait sources disagree over shared native tile {global_tile}; edit all owners consistently"
                )
            native[global_tile * 32:(global_tile + 1) * 32] = encoded
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(native)
    print(f"rebuilt {len(native)} bytes of portrait tiles from {source_directory}")
    print(f"portrait tile SHA-256: {hashlib.sha256(native).hexdigest()}")


def rendered_pixel_layers(archive: Archive, portrait_id: int) -> tuple[int, int, bytes, list[list[tuple[int, int]]]]:
    """Return the visible baseline and every native OAM pixel behind it.

    Full portrait PNGs intentionally describe what an artist sees, not hidden
    pixels under later OAM pieces.  The layer lists retain the physical mapping
    so a changed visible pixel can be written safely while an unchanged source
    preserves every hidden base-ROM nibble byte-for-byte.
    """
    min_x, min_y, width, height, entries = portrait_canvas(archive, portrait_id)
    baseline = bytearray(width * height)
    layers: list[list[tuple[int, int]]] = [[] for _ in range(width * height)]
    for x, y, sprite_width, sprite_height, tile_start in entries:
        tiles_wide = sprite_width // 8
        for tile_y in range(sprite_height // 8):
            for tile_x in range(tiles_wide):
                global_tile = tile_start + tile_y * tiles_wide + tile_x
                values = tile_pixels(archive, global_tile)
                for pixel_y in range(8):
                    for pixel_x in range(8):
                        target_x = x - min_x + tile_x * 8 + pixel_x
                        target_y = y - min_y + tile_y * 8 + pixel_y
                        target = target_y * width + target_x
                        native_pixel = pixel_y * 8 + pixel_x
                        layers[target].append((global_tile, native_pixel))
                        value = values[native_pixel]
                        if value != 0:
                            baseline[target] = value
    return width, height, bytes(baseline), layers


def assign_native_pixel(native: bytearray, assignments: dict[tuple[int, int], int],
                        global_tile: int, native_pixel: int, value: int) -> None:
    key = (global_tile, native_pixel)
    previous = assignments.setdefault(key, value)
    if previous != value:
        raise ValueError(
            f"full portrait sources disagree over shared native tile {global_tile}, pixel {native_pixel}"
        )
    offset = global_tile * 32 + native_pixel // 2
    if native_pixel & 1:
        native[offset] = (native[offset] & 0x0F) | (value << 4)
    else:
        native[offset] = (native[offset] & 0xF0) | value


def rebuild_full_data(archive: Archive, source_directory: Path) -> tuple[bytes, int]:
    audit(archive)
    t4_offset = archive.table_offsets[3]
    native = bytearray(archive.data[t4_offset:t4_offset + archive.counts[3] * 32])
    assignments: dict[tuple[int, int], int] = {}
    changed_pixels = 0
    for portrait_id in range(archive.counts[0]):
        _, _, _, _, palette_id = portrait_descriptor(archive, portrait_id)
        filename = portrait_source_file(source_directory, "full", portrait_id)
        width, height, source, source_palette = read_png_indexed(filename)
        expected_width, expected_height, baseline, layers = rendered_pixel_layers(archive, portrait_id)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != palette(archive, palette_id):
            raise ValueError(f"{filename} has changed its native 16-color palette")
        for target, value in enumerate(source):
            if value == baseline[target]:
                continue
            changed_pixels += 1
            if not layers[target]:
                if value != 0:
                    raise ValueError(f"{filename} draws outside its OAM layout at pixel {target}")
                continue
            if value == 0:
                for global_tile, native_pixel in layers[target]:
                    assign_native_pixel(native, assignments, global_tile, native_pixel, 0)
            else:
                global_tile, native_pixel = layers[target][-1]
                assign_native_pixel(native, assignments, global_tile, native_pixel, value)
    return bytes(native), changed_pixels


def rebuild_full(archive: Archive, source_directory: Path, output: Path) -> None:
    native, changed_pixels = rebuild_full_data(archive, source_directory)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(native)
    print(f"rebuilt {len(native)} bytes from {source_directory}/full with {changed_pixels} visible pixel changes")
    print(f"portrait tile SHA-256: {hashlib.sha256(native).hexdigest()}")


def verify_full(archive: Archive, source_directory: Path) -> None:
    """Prove that the editable full portraits reconstruct table four exactly.

    The archive's first three tables, palette table, and trailing data remain
    immutable build-time structure. Full PNG sources own only table four, so
    this comparison checks that precise native interval rather than treating
    the complete archive as a PNG-derived payload.
    """

    native, changed_pixels = rebuild_full_data(archive, source_directory)
    table_four_offset = archive.table_offsets[3]
    retail = archive.data[table_four_offset:table_four_offset + len(native)]
    if native != retail:
        raise ValueError(
            "full portrait PNGs do not reconstruct the retail table-four "
            "4bpp tile payload"
        )
    print(
        f"verified {len(native)} full-portrait tile bytes against archive "
        f"table four with {changed_pixels} visible pixel changes"
    )


def render_full_previews(archive: Archive, source_directory: Path) -> None:
    """Render preview PNGs from the current complete-image authoring sources.

    This deliberately reuses rebuild_full_data instead of trusting an editor's
    visible compositing. The preview therefore shows exactly the tile bytes a
    build would emit, including OAM overlap and palette-index semantics.
    """
    native, changed_pixels = rebuild_full_data(archive, source_directory)
    t4_offset = archive.table_offsets[3]
    archive_data = bytearray(archive.data)
    archive_data[t4_offset:t4_offset + len(native)] = native
    rebuilt_archive = Archive(
        bytes(archive_data), archive.table_offsets, archive.counts, archive.trailing_offset
    )
    for portrait_id in range(rebuilt_archive.counts[0]):
        _, _, _, _, palette_id = portrait_descriptor(rebuilt_archive, portrait_id)
        preview = render_preview(rebuilt_archive, portrait_id, palette(rebuilt_archive, palette_id))
        filename = portrait_source_file(source_directory, "full", portrait_id)
        write_png_rgba(source_directory / "preview" / filename.name, *preview)
    print(
        f"rendered {rebuilt_archive.counts[0]} previews from {source_directory}/full "
        f"with {changed_pixels} visible pixel changes"
    )


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="retail ROM containing the portrait archive")
    parser.add_argument("--offset", required=True, type=lambda text: int(text, 0), help="archive ROM offset")
    parser.add_argument("--length", default=0x5E0A4, type=lambda text: int(text, 0), help="full archive length")
    parser.add_argument("--sha256", help="expected full-archive SHA-256")
    parser.add_argument("--names-header", type=Path, help="Mary-C portrait enum used only for output names")
    subparsers = parser.add_subparsers(dest="command", required=True)
    subparsers.add_parser("audit", help="verify archive table and OAM relationships")
    export_parser = subparsers.add_parser("export", help="write separate colored tile groups and portrait previews")
    export_parser.add_argument("--output", required=True, type=Path)
    rebuild_parser = subparsers.add_parser("rebuild", help="rebuild native 4bpp table four from tile group PNGs")
    rebuild_parser.add_argument("--source", required=True, type=Path)
    rebuild_parser.add_argument("--output", required=True, type=Path)
    rebuild_full_parser = subparsers.add_parser("rebuild-full", help="patch native 4bpp table four from full portrait PNGs")
    rebuild_full_parser.add_argument("--source", required=True, type=Path)
    rebuild_full_parser.add_argument("--output", required=True, type=Path)
    verify_full_parser = subparsers.add_parser(
        "verify-full", help="verify that full portrait PNGs reconstruct native table four"
    )
    verify_full_parser.add_argument("--source", required=True, type=Path)
    preview_parser = subparsers.add_parser(
        "render-full-preview", help="render preview PNGs from current full portrait PNGs"
    )
    preview_parser.add_argument("--source", required=True, type=Path)
    args = parser.parse_args()
    expected_hash = args.sha256.lower() if args.sha256 else None
    archive = load_archive(args.rom, args.offset, args.length)
    actual_hash = hashlib.sha256(archive.data).hexdigest()
    if expected_hash is not None and actual_hash != expected_hash:
        raise ValueError(
            f"archive SHA-256 mismatch: expected {expected_hash}, got {actual_hash}; refusing to process a different archive"
        )
    print(f"archive SHA-256: {actual_hash}")
    if args.command == "audit":
        audit(archive)
    elif args.command == "export":
        export(archive, args.output, parse_names(args.names_header))
    elif args.command == "rebuild":
        rebuild(archive, args.source, args.output)
    elif args.command == "rebuild-full":
        rebuild_full(archive, args.source, args.output)
    elif args.command == "verify-full":
        verify_full(archive, args.source)
    elif args.command == "render-full-preview":
        render_full_previews(archive, args.source)
    else:
        raise AssertionError("unreachable")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

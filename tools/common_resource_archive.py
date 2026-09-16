#!/usr/bin/env python3
"""Rebuild FoMT's shared common IndexedResourceArchive without sidecar layouts.

The complete four-region-identical archive contains 500 group descriptors.
Each drawable group owns a verified OAM range, 4bpp tile range, and one BGR555
palette.  Its ``full/group_NNN.png`` indexed PNG is the editable source; the
native selection, descriptor, OAM, and palette tables remain the ROM's layout
source of truth.  Unchanged sources retain the original fixed-size archive
byte-for-byte.  This deliberately does not use a JSON manifest.
"""

from __future__ import annotations

import argparse
import hashlib
import shutil
import struct
import tempfile
from dataclasses import dataclass
from pathlib import Path

from portrait_archive import (
    Archive,
    OAM_DIMENSIONS,
    load_archive,
    palette,
    read_png_indexed,
    tile_pixels,
    write_png_indexed,
    write_png_rgba,
)


EXPECTED_COUNTS = (493, 500, 101, 1624, 342, 0, 532)


@dataclass(frozen=True)
class Descriptor:
    oam_count: int
    oam_start: int
    tile_count: int
    tile_start: int
    palette_count: int
    palette_start: int


@dataclass(frozen=True)
class OamEntry:
    x: int
    y: int
    width: int
    height: int
    tile_start: int
    horizontal_flip: bool
    vertical_flip: bool


def read_u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def load_checked(path: Path, offset: int, length: int, expected_hash: str | None) -> Archive:
    archive = load_archive(path, offset, length, trailing_bytes=0)
    actual_hash = hashlib.sha256(archive.data).hexdigest()
    if expected_hash is not None and actual_hash != expected_hash.lower():
        raise ValueError(
            f"archive SHA-256 mismatch: expected {expected_hash}, got {actual_hash}; "
            "refusing to process an unverified range"
        )
    if archive.counts != EXPECTED_COUNTS:
        raise ValueError(f"unexpected common archive table counts: {archive.counts}")
    return archive


def descriptor(archive: Archive, group_id: int) -> Descriptor:
    if not 0 <= group_id < archive.counts[1]:
        raise ValueError(f"group {group_id} is outside the descriptor table")
    values = struct.unpack_from("<8H", archive.data, archive.table_offsets[1] + group_id * 16)
    if values[6:] != (0, 0):
        raise ValueError(f"group {group_id} uses an unimplemented sixth descriptor range")
    return Descriptor(*values[:6])


def oam_entries(archive: Archive, group_id: int) -> list[OamEntry]:
    item = descriptor(archive, group_id)
    if item.oam_start + item.oam_count > archive.counts[2]:
        raise ValueError(f"group {group_id} OAM range exceeds table three")
    if item.tile_start + item.tile_count > archive.counts[3]:
        raise ValueError(f"group {group_id} tile range exceeds table four")
    if item.palette_count != 1 or item.palette_start >= archive.counts[4]:
        raise ValueError(f"group {group_id} does not select exactly one valid palette")
    result: list[OamEntry] = []
    for local_id in range(item.oam_count):
        offset = archive.table_offsets[2] + (item.oam_start + local_id) * 8
        attr0 = read_u16(archive.data, offset)
        attr1 = read_u16(archive.data, offset + 2)
        attr2 = read_u16(archive.data, offset + 4)
        dimensions = OAM_DIMENSIONS.get(((attr0 >> 14) & 3, (attr1 >> 14) & 3))
        if dimensions is None:
            raise ValueError(f"group {group_id} OAM {local_id} has invalid shape/size")
        if attr0 & 0x0300:
            raise ValueError(f"group {group_id} OAM {local_id} uses affine layout")
        width, height = dimensions
        local_tile = attr2 & 0x3FF
        if local_tile + width * height // 64 > item.tile_count:
            raise ValueError(f"group {group_id} OAM {local_id} exceeds its tile range")
        x, y = attr1 & 0x1FF, attr0 & 0xFF
        if x > 255:
            x -= 512
        if y > 127:
            y -= 256
        result.append(OamEntry(
            x, y, width, height, item.tile_start + local_tile,
            bool(attr1 & 0x1000), bool(attr1 & 0x2000),
        ))
    return result


def resource_canvas(archive: Archive, group_id: int) -> tuple[int, int, int, int, list[OamEntry]]:
    entries = oam_entries(archive, group_id)
    if not entries:
        raise ValueError(f"group {group_id} is a non-drawable native record")
    min_x = min(entry.x for entry in entries)
    min_y = min(entry.y for entry in entries)
    max_x = max(entry.x + entry.width for entry in entries)
    max_y = max(entry.y + entry.height for entry in entries)
    return min_x, min_y, max_x - min_x, max_y - min_y, entries


def rendered_pixel_layers(archive: Archive, group_id: int) -> tuple[int, int, bytes, list[list[tuple[int, int]]]]:
    min_x, min_y, width, height, entries = resource_canvas(archive, group_id)
    baseline = bytearray(width * height)
    layers: list[list[tuple[int, int]]] = [[] for _ in range(width * height)]
    for entry in entries:
        tiles_wide = entry.width // 8
        for visual_y in range(entry.height):
            native_y = entry.height - 1 - visual_y if entry.vertical_flip else visual_y
            tile_y, pixel_y = divmod(native_y, 8)
            for visual_x in range(entry.width):
                native_x = entry.width - 1 - visual_x if entry.horizontal_flip else visual_x
                tile_x, pixel_x = divmod(native_x, 8)
                tile_id = entry.tile_start + tile_y * tiles_wide + tile_x
                pixel_id = pixel_y * 8 + pixel_x
                target_x = entry.x - min_x + visual_x
                target_y = entry.y - min_y + visual_y
                target = target_y * width + target_x
                layers[target].append((tile_id, pixel_id))
                value = tile_pixels(archive, tile_id)[pixel_id]
                if value:
                    baseline[target] = value
    return width, height, bytes(baseline), layers


def source_file(source_dir: Path, group_id: int) -> Path:
    return source_dir / "full" / f"group_{group_id:03d}.png"


def selection_entries(archive: Archive) -> list[tuple[int, int]]:
    entries: list[tuple[int, int]] = []
    for index in range(archive.counts[6]):
        offset = archive.table_offsets[6] + index * 4
        entries.append((read_u16(archive.data, offset), read_u16(archive.data, offset + 2)))
    return entries


def drawable_group_ids(archive: Archive) -> list[int]:
    return [group_id for group_id in range(archive.counts[1]) if descriptor(archive, group_id).oam_count]


def audit(archive: Archive) -> None:
    entries = selection_entries(archive)
    for selection_id in range(archive.counts[0]):
        offset = archive.table_offsets[0] + selection_id * 4
        count, first = read_u16(archive.data, offset), read_u16(archive.data, offset + 2)
        if first + count > len(entries):
            raise ValueError(f"selection {selection_id} exceeds the entry table")
        for group_id, _ in entries[first:first + count]:
            if group_id >= archive.counts[1]:
                raise ValueError(f"selection {selection_id} references invalid group {group_id}")

    claimed_tiles: set[int] = set()
    flipped = 0
    empty: list[int] = []
    for group_id in range(archive.counts[1]):
        item = descriptor(archive, group_id)
        if not item.oam_count:
            if item != Descriptor(0, 0, 0, 0, 0, 0):
                raise ValueError(f"non-drawable group {group_id} has unexpected nonzero metadata")
            empty.append(group_id)
            continue
        for entry in oam_entries(archive, group_id):
            flipped += entry.horizontal_flip + entry.vertical_flip
        resource_canvas(archive, group_id)
        claimed_tiles.update(range(item.tile_start, item.tile_start + item.tile_count))
    if claimed_tiles != set(range(archive.counts[3])):
        raise ValueError("drawable group descriptors do not claim every native tile")
    if empty != [316, 429]:
        raise ValueError(f"unexpected common archive non-drawable groups: {empty}")
    print(f"tables: {', '.join(map(str, archive.counts))}")
    print(
        f"verified {len(entries)} selection entries, {len(drawable_group_ids(archive))} drawable OAM groups, "
        f"{archive.counts[3]} 4bpp tiles, {archive.counts[4]} palettes, and {flipped} flipped OAM entries"
    )


def export(archive: Archive, output: Path) -> None:
    audit(archive)
    for group_id in drawable_group_ids(archive):
        item = descriptor(archive, group_id)
        width, height, indexes, _ = rendered_pixel_layers(archive, group_id)
        colors = palette(archive, item.palette_start)
        name = f"group_{group_id:03d}.png"
        write_png_indexed(output / "full" / name, width, height, indexes, colors)
        rgba = bytearray(width * height * 4)
        for index, color_index in enumerate(indexes):
            if color_index:
                rgba[index * 4:index * 4 + 4] = bytes(colors[color_index])
        write_png_rgba(output / "preview" / name, width, height, bytes(rgba))
    print(f"exported {len(drawable_group_ids(archive))} indexed OAM group PNGs to {output}")


def assign_native_pixel(native: bytearray, assignments: dict[tuple[int, int], int],
                        tile_id: int, pixel_id: int, value: int) -> None:
    key = (tile_id, pixel_id)
    prior = assignments.setdefault(key, value)
    if prior != value:
        raise ValueError(f"source PNGs disagree over shared native tile {tile_id}, pixel {pixel_id}")
    offset = tile_id * 32 + pixel_id // 2
    if pixel_id & 1:
        native[offset] = (native[offset] & 0x0F) | (value << 4)
    else:
        native[offset] = (native[offset] & 0xF0) | value


def rebuild_data(archive: Archive, source_dir: Path) -> tuple[bytes, int]:
    audit(archive)
    tile_offset = archive.table_offsets[3]
    native = bytearray(archive.data[tile_offset:tile_offset + archive.counts[3] * 32])
    assignments: dict[tuple[int, int], int] = {}
    changed = 0
    for group_id in drawable_group_ids(archive):
        item = descriptor(archive, group_id)
        filename = source_file(source_dir, group_id)
        width, height, source, source_palette = read_png_indexed(filename)
        expected_width, expected_height, baseline, layers = rendered_pixel_layers(archive, group_id)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}")
        if source_palette != palette(archive, item.palette_start):
            raise ValueError(f"{filename} has changed its native 16-color palette")
        for target, value in enumerate(source):
            if value == baseline[target]:
                continue
            changed += 1
            if not layers[target]:
                if value:
                    raise ValueError(f"{filename} draws outside native OAM at pixel {target}")
                continue
            if value == 0:
                for tile_id, pixel_id in layers[target]:
                    assign_native_pixel(native, assignments, tile_id, pixel_id, 0)
            else:
                tile_id, pixel_id = layers[target][-1]
                assign_native_pixel(native, assignments, tile_id, pixel_id, value)
    rebuilt = bytearray(archive.data)
    rebuilt[tile_offset:tile_offset + len(native)] = native
    return bytes(rebuilt), changed


def build(archive: Archive, source_dir: Path, output: Path) -> None:
    data, changed = rebuild_data(archive, source_dir)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(data)
    print(f"rebuilt {len(data):#x}-byte common resource archive with {changed} visible pixel changes")
    print(f"archive SHA-256: {hashlib.sha256(data).hexdigest()}")


def verify(source_dir: Path, archive: Archive) -> None:
    rebuilt, changed = rebuild_data(archive, source_dir)
    if changed or rebuilt != archive.data:
        raise AssertionError("unchanged common OAM PNG sources do not rebuild the retail archive")
    print("verified unchanged common OAM PNG reconstruction against the retail archive")


def patch_bytes(target: bytes, baseline: Archive, offset: int, rebuilt: bytes) -> bytes:
    if len(rebuilt) != len(baseline.data):
        raise ValueError("rebuilt archive length does not match its fixed allocation")
    end = offset + len(rebuilt)
    if len(target) < end or target[offset:end] != baseline.data:
        raise ValueError("target ROM does not retain the verified archive baseline")
    patched = bytearray(target)
    patched[offset:end] = rebuilt
    return bytes(patched)


def patch(archive: Archive, offset: int, target_path: Path, rebuilt_path: Path) -> None:
    target_path.write_bytes(patch_bytes(target_path.read_bytes(), archive, offset, rebuilt_path.read_bytes()))
    print(f"patched {target_path} at {offset:#x}-{offset + len(archive.data):#x}")


def patch_test(arguments: argparse.Namespace) -> None:
    built = {region: Path(path).read_bytes() for region, path in arguments.archive}
    for region, rom_path, offset_text in arguments.all_rom:
        baseline_path = Path(rom_path)
        offset = int(offset_text, 0)
        baseline = load_checked(baseline_path, offset, arguments.length, arguments.sha256)
        original = baseline_path.read_bytes()
        if region not in built or patch_bytes(original, baseline, offset, built[region]) != original:
            raise AssertionError(f"unchanged {region.upper()} common archive patch changes retail ROM bytes")
    print("verified unchanged common resource archive post-link patches against all four retail ROMs")


def edit_test(archive: Archive, source_dir: Path) -> None:
    with tempfile.TemporaryDirectory(prefix="fomt_common_archive_") as temporary:
        copied = Path(temporary) / "source"
        shutil.copytree(source_dir, copied)
        owners: dict[tuple[int, int], list[tuple[int, int]]] = {}
        for group_id in drawable_group_ids(archive):
            _, _, _, layers = rendered_pixel_layers(archive, group_id)
            for target, native_pixels in enumerate(layers):
                for native_pixel in native_pixels:
                    owners.setdefault(native_pixel, []).append((group_id, target))
        shared = next((pixel for pixel, users in owners.items() if len(users) >= 2), None)
        if shared is None:
            raise AssertionError("common archive unexpectedly has no shared drawable tile pixel")
        users = owners[shared]
        changed_sources: set[int] = set()
        for group_id, target in users:
            if group_id in changed_sources:
                continue
            filename = source_file(copied, group_id)
            width, height, indexes, colors = read_png_indexed(filename)
            edited = bytearray(indexes)
            edited[target] = 1 if edited[target] != 1 else 2
            write_png_indexed(filename, width, height, bytes(edited), colors)
            changed_sources.add(group_id)
        rebuilt, changed = rebuild_data(archive, copied)
        tile_offset = archive.table_offsets[3]
        tile_end = tile_offset + archive.counts[3] * 32
        if not changed or rebuilt == archive.data:
            raise AssertionError("shared OAM pixel edit did not change the common archive")
        if rebuilt[:tile_offset] != archive.data[:tile_offset] or rebuilt[tile_end:] != archive.data[tile_end:]:
            raise AssertionError("common OAM edit changed metadata outside table four")
    print("verified a shared visible common-OAM edit preserves metadata and fixed archive bounds")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--offset", required=True, type=lambda text: int(text, 0))
    parser.add_argument("--length", default=0x12848, type=lambda text: int(text, 0))
    parser.add_argument("--sha256")
    commands = parser.add_subparsers(dest="command", required=True)
    commands.add_parser("audit")
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--output", required=True, type=Path)
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--source-dir", required=True, type=Path)
    build_parser.add_argument("--output", required=True, type=Path)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", required=True, type=Path)
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--target", required=True, type=Path)
    patch_parser.add_argument("--archive", required=True, type=Path)
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--archive", nargs=2, action="append", metavar=("REGION", "PATH"), required=True)
    patch_test_parser.add_argument("--all-rom", nargs=3, action="append", metavar=("REGION", "ROM", "OFFSET"), required=True)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--source-dir", required=True, type=Path)
    args = parser.parse_args()
    archive = load_checked(args.rom, args.offset, args.length, args.sha256)
    if args.command == "audit":
        audit(archive)
    elif args.command == "export":
        export(archive, args.output)
    elif args.command == "build":
        build(archive, args.source_dir, args.output)
    elif args.command == "verify":
        verify(args.source_dir, archive)
    elif args.command == "patch":
        patch(archive, args.offset, args.target, args.archive)
    elif args.command == "patch-test":
        patch_test(args)
    else:
        edit_test(archive, args.source_dir)


if __name__ == "__main__":
    main()

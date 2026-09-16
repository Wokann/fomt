#!/usr/bin/env python3
"""Rebuild the shared Farm Status / Town Map OAM resource archive.

The native IndexedResourceArchive at JP 0x4D977C (and its US/EU/DE physical
counterparts) contains forty compact OAM resources.  Its six counted tables
are parsed by ``IndexedResourceArchive``; the second table selects an OAM
range, 4bpp tile range and BGR555 palette range for each resource.

``full/resource_NNN.png`` is the authoring input.  It is a palette-indexed,
OAM-composited view, while the archive's original table layout remains the
source of truth.  Rebuilds retain every non-tile byte and patch only pixels
that changed visibly in the source PNGs.  This is deliberately not a JSON
layout pipeline.
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
    encode_tile,
    load_archive,
    palette,
    read_png_indexed,
    tile_pixels,
    write_png_indexed,
    write_png_rgba,
)


EXPECTED_COUNTS = (20, 40, 11, 73, 13, 0, 40)


@dataclass(frozen=True)
class Descriptor:
    oam_count: int
    oam_start: int
    tile_count: int
    tile_start: int
    palette_count: int
    palette_start: int


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
        raise ValueError(f"unexpected Farm Status archive table counts: {archive.counts}")
    return archive


def descriptor(archive: Archive, resource_id: int) -> Descriptor:
    if not 0 <= resource_id < archive.counts[1]:
        raise ValueError(f"resource {resource_id} is outside the group descriptor table")
    offset = archive.table_offsets[1] + resource_id * 16
    values = struct.unpack_from("<8H", archive.data, offset)
    if values[6:] != (0, 0):
        raise ValueError(f"resource {resource_id} uses the unimplemented sixth descriptor table")
    return Descriptor(*values[:6])


def oam_entries(archive: Archive, resource_id: int) -> list[tuple[int, int, int, int, int]]:
    item = descriptor(archive, resource_id)
    if item.oam_start + item.oam_count > archive.counts[2]:
        raise ValueError(f"resource {resource_id} OAM range is outside table three")
    if item.tile_start + item.tile_count > archive.counts[3]:
        raise ValueError(f"resource {resource_id} tile range is outside table four")
    if item.palette_count != 1 or item.palette_start >= archive.counts[4]:
        raise ValueError(f"resource {resource_id} does not select exactly one valid BGR555 palette")

    entries: list[tuple[int, int, int, int, int]] = []
    for local_oam_id in range(item.oam_count):
        offset = archive.table_offsets[2] + (item.oam_start + local_oam_id) * 8
        attr0 = read_u16(archive.data, offset)
        attr1 = read_u16(archive.data, offset + 2)
        attr2 = read_u16(archive.data, offset + 4)
        dimensions = OAM_DIMENSIONS.get(((attr0 >> 14) & 3, (attr1 >> 14) & 3))
        if dimensions is None:
            raise ValueError(f"resource {resource_id} OAM {local_oam_id} has invalid shape/size")
        if attr0 & 0x0300 or attr1 & 0x3000:
            raise ValueError(
                f"resource {resource_id} OAM {local_oam_id} uses affine or flip bits "
                "outside this verified archive layout"
            )
        width, height = dimensions
        local_tile = attr2 & 0x3FF
        required_tiles = width * height // 64
        if local_tile + required_tiles > item.tile_count:
            raise ValueError(f"resource {resource_id} OAM {local_oam_id} exceeds its tile range")
        x = attr1 & 0x1FF
        y = attr0 & 0xFF
        if x > 255:
            x -= 512
        if y > 127:
            y -= 256
        entries.append((x, y, width, height, item.tile_start + local_tile))
    if not entries:
        raise ValueError(f"resource {resource_id} has no drawable OAM entries")
    return entries


def resource_canvas(archive: Archive, resource_id: int) -> tuple[int, int, int, int, list[tuple[int, int, int, int, int]]]:
    entries = oam_entries(archive, resource_id)
    min_x = min(x for x, _, _, _, _ in entries)
    min_y = min(y for _, y, _, _, _ in entries)
    max_x = max(x + width for x, _, width, _, _ in entries)
    max_y = max(y + height for _, y, _, height, _ in entries)
    return min_x, min_y, max_x - min_x, max_y - min_y, entries


def rendered_pixel_layers(archive: Archive, resource_id: int) -> tuple[int, int, bytes, list[list[tuple[int, int]]]]:
    min_x, min_y, width, height, entries = resource_canvas(archive, resource_id)
    baseline = bytearray(width * height)
    layers: list[list[tuple[int, int]]] = [[] for _ in range(width * height)]
    for x, y, sprite_width, sprite_height, tile_start in entries:
        tiles_wide = sprite_width // 8
        for tile_y in range(sprite_height // 8):
            for tile_x in range(tiles_wide):
                tile_id = tile_start + tile_y * tiles_wide + tile_x
                values = tile_pixels(archive, tile_id)
                for pixel_y in range(8):
                    for pixel_x in range(8):
                        target_x = x - min_x + tile_x * 8 + pixel_x
                        target_y = y - min_y + tile_y * 8 + pixel_y
                        target = target_y * width + target_x
                        native_pixel = pixel_y * 8 + pixel_x
                        layers[target].append((tile_id, native_pixel))
                        value = values[native_pixel]
                        if value:
                            baseline[target] = value
    return width, height, bytes(baseline), layers


def source_file(source_dir: Path, resource_id: int) -> Path:
    return source_dir / "full" / f"resource_{resource_id:03d}.png"


def audit(archive: Archive) -> None:
    claimed_tiles: dict[int, list[int]] = {}
    for selection_id in range(archive.counts[0]):
        offset = archive.table_offsets[0] + selection_id * 4
        count = read_u16(archive.data, offset)
        first = read_u16(archive.data, offset + 2)
        if count != 2 or first + count > archive.counts[6]:
            raise ValueError(f"selection {selection_id} has an invalid two-entry resource range")
        for entry_id in range(first, first + count):
            entry_offset = archive.table_offsets[6] + entry_id * 4
            resource_id = read_u16(archive.data, entry_offset)
            metric = read_u16(archive.data, entry_offset + 2)
            if resource_id >= archive.counts[1] or metric != 16:
                raise ValueError(f"selection {selection_id} references an invalid archive resource")

    for resource_id in range(archive.counts[1]):
        item = descriptor(archive, resource_id)
        oam_entries(archive, resource_id)
        for tile_id in range(item.tile_start, item.tile_start + item.tile_count):
            claimed_tiles.setdefault(tile_id, []).append(resource_id)
        _, _, width, height, _ = resource_canvas(archive, resource_id)
        if (width, height) not in {(8, 8), (16, 16)}:
            raise ValueError(f"resource {resource_id} has unexpected canvas {width}x{height}")

    if len(claimed_tiles) != archive.counts[3]:
        raise ValueError("the resource groups do not claim every native tile")
    print(f"tables: {', '.join(map(str, archive.counts))}")
    print(f"verified {archive.counts[1]} OAM resources, {archive.counts[3]} 4bpp tiles, and {archive.counts[4]} palettes")


def export(archive: Archive, output: Path) -> None:
    audit(archive)
    for resource_id in range(archive.counts[1]):
        item = descriptor(archive, resource_id)
        width, height, indexes, _ = rendered_pixel_layers(archive, resource_id)
        colors = palette(archive, item.palette_start)
        name = f"resource_{resource_id:03d}.png"
        write_png_indexed(output / "full" / name, width, height, indexes, colors)
        rgba = bytearray(width * height * 4)
        for index, color_index in enumerate(indexes):
            if color_index:
                rgba[index * 4:index * 4 + 4] = bytes(colors[color_index])
        write_png_rgba(output / "preview" / name, width, height, bytes(rgba))
    print(f"exported {archive.counts[1]} indexed OAM resource PNGs to {output}")


def assign_native_pixel(native: bytearray, assignments: dict[tuple[int, int], int],
                        tile_id: int, pixel_id: int, value: int) -> None:
    key = (tile_id, pixel_id)
    previous = assignments.setdefault(key, value)
    if previous != value:
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
    changed_pixels = 0
    for resource_id in range(archive.counts[1]):
        item = descriptor(archive, resource_id)
        filename = source_file(source_dir, resource_id)
        width, height, source, source_palette = read_png_indexed(filename)
        expected_width, expected_height, baseline, layers = rendered_pixel_layers(archive, resource_id)
        if (width, height) != (expected_width, expected_height):
            raise ValueError(
                f"{filename} must remain {expected_width}x{expected_height}, got {width}x{height}"
            )
        if source_palette != palette(archive, item.palette_start):
            raise ValueError(f"{filename} has changed its native 16-color palette")
        for target, value in enumerate(source):
            if value == baseline[target]:
                continue
            changed_pixels += 1
            if not layers[target]:
                if value:
                    raise ValueError(f"{filename} draws outside its native OAM layout at pixel {target}")
                continue
            if value == 0:
                for tile_id, pixel_id in layers[target]:
                    assign_native_pixel(native, assignments, tile_id, pixel_id, 0)
            else:
                tile_id, pixel_id = layers[target][-1]
                assign_native_pixel(native, assignments, tile_id, pixel_id, value)

    rebuilt = bytearray(archive.data)
    rebuilt[tile_offset:tile_offset + len(native)] = native
    return bytes(rebuilt), changed_pixels


def build(archive: Archive, source_dir: Path, output: Path) -> None:
    data, changed = rebuild_data(archive, source_dir)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(data)
    print(f"rebuilt {len(data):#x}-byte Farm Status/Town Map archive with {changed} visible pixel changes")
    print(f"archive SHA-256: {hashlib.sha256(data).hexdigest()}")


def patch_bytes(target: bytes, baseline: Archive, offset: int, rebuilt: bytes) -> bytes:
    if len(rebuilt) != len(baseline.data):
        raise ValueError("rebuilt archive length does not match its fixed native allocation")
    start = offset
    end = start + len(rebuilt)
    if len(target) < end:
        raise ValueError("target ROM ends before the archive allocation")
    if target[start:end] != baseline.data:
        raise ValueError("target ROM archive differs from its verified baseline before patching")
    patched = bytearray(target)
    patched[start:end] = rebuilt
    return bytes(patched)


def patch(archive: Archive, offset: int, target_path: Path, rebuilt_path: Path) -> None:
    rebuilt = rebuilt_path.read_bytes()
    target = target_path.read_bytes()
    target_path.write_bytes(patch_bytes(target, archive, offset, rebuilt))
    print(f"patched {target_path} at {offset:#x}-{offset + len(rebuilt):#x}")


def patch_test(arguments: argparse.Namespace) -> None:
    """Prove each regional post-link replacement is byte-neutral when unchanged."""
    built = {region: Path(path).read_bytes() for region, path in arguments.archive}
    for region, rom_path, offset_text in arguments.all_rom:
        if region not in built:
            raise ValueError(f"missing built archive for {region}")
        baseline_path = Path(rom_path)
        baseline = load_checked(
            baseline_path, int(offset_text, 0), arguments.length, arguments.sha256
        )
        original_rom = baseline_path.read_bytes()
        if patch_bytes(original_rom, baseline, int(offset_text, 0), built[region]) != original_rom:
            raise AssertionError(f"unchanged {region.upper()} archive patch changes retail ROM bytes")
    print("verified unchanged Farm Status/Town Map archive post-link patches against all four retail ROMs")


def verify(source_dir: Path, archive: Archive) -> None:
    rebuilt, changed = rebuild_data(archive, source_dir)
    if changed or rebuilt != archive.data:
        raise AssertionError("unchanged OAM resource PNG sources do not rebuild the original archive")
    print("verified unchanged OAM-resource source rebuild against the retail archive")


def edit_test(archive: Archive, source_dir: Path) -> None:
    """Edit a shared native pixel through both of its visible OAM sources."""
    with tempfile.TemporaryDirectory(prefix="fomt_farm_status_archive_") as temporary:
        copied = Path(temporary) / "source"
        shutil.copytree(source_dir, copied)
        _, _, _, layers0 = rendered_pixel_layers(archive, 0)
        _, _, _, layers1 = rendered_pixel_layers(archive, 1)
        reverse0 = {native: pixel for pixel, natives in enumerate(layers0) for native in natives}
        reverse1 = {native: pixel for pixel, natives in enumerate(layers1) for native in natives}
        common = next((native for native in reverse0 if native in reverse1), None)
        if common is None:
            raise AssertionError("resource 0 and 1 unexpectedly share no native OAM pixel")
        for resource_id, reverse in ((0, reverse0), (1, reverse1)):
            filename = source_file(copied, resource_id)
            width, height, indexes, colors = read_png_indexed(filename)
            edited = bytearray(indexes)
            target = reverse[common]
            edited[target] = 1 if edited[target] != 1 else 2
            write_png_indexed(filename, width, height, bytes(edited), colors)
        rebuilt, changed = rebuild_data(archive, copied)
        tile_offset = archive.table_offsets[3]
        tile_end = tile_offset + archive.counts[3] * 32
        if changed != 2 or rebuilt == archive.data:
            raise AssertionError("shared OAM-pixel edit was not recorded")
        if rebuilt[:tile_offset] != archive.data[:tile_offset] or rebuilt[tile_end:] != archive.data[tile_end:]:
            raise AssertionError("OAM resource edit changed metadata outside the native tile table")
    print("verified a shared visible OAM-pixel edit preserves archive metadata and fixed bounds")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="retail ROM containing the archive")
    parser.add_argument("--offset", required=True, type=lambda text: int(text, 0))
    parser.add_argument("--length", default=0xEA4, type=lambda text: int(text, 0))
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
    patch_test_parser.add_argument(
        "--all-rom", nargs=3, action="append", metavar=("REGION", "ROM", "OFFSET"), required=True
    )
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

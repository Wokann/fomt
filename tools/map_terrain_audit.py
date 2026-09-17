#!/usr/bin/env python3
"""Audit the non-visual fields of FoMT's 66-entry MapData table.

``MapData`` fields +0x18 and +0x1C are not graphics pointers.  The latter is
a one-byte-per-cell terrain-index grid, with an exact ``width * height``
extent.  The former is its four-byte ``TerrainInfo`` table: the grid's largest
index establishes the minimum range actually read by the retail field path.

This tool intentionally records only those proven accesses.  It does not
invent a complete TerrainInfo-table boundary from the following ROM label and
does not export either field as an image resource.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
from dataclasses import dataclass
from pathlib import Path


ROM_BASE = 0x08000000
MAP_COUNT = 66
MAP_RECORD_SIZE = 0x28
MAP_TABLES = {
    "jp": 0x105A24,
    "us": 0x105EDC,
    "eu": 0x105F34,
    "de": 0x106900,
}


@dataclass(frozen=True)
class TerrainMap:
    map_id: int
    width: int
    height: int
    terrain_data_offset: int | None
    terrain_map_offset: int | None
    max_index: int | None
    terrain_map: bytes
    terrain_info_minimum: bytes

    @property
    def cell_count(self) -> int:
        return self.width * self.height

    @property
    def terrain_info_minimum_count(self) -> int:
        return 0 if self.max_index is None else self.max_index + 1


def pointer_offset(rom: bytes, offset: int, region: str, field: str) -> int | None:
    pointer = int.from_bytes(rom[offset:offset + 4], "little")
    if pointer == 0:
        return None
    if not ROM_BASE <= pointer < ROM_BASE + len(rom):
        raise ValueError(f"{region.upper()} {field}: invalid ROM pointer {pointer:#010x}")
    return pointer - ROM_BASE


def parse_region(rom: bytes, region: str) -> tuple[TerrainMap, ...]:
    table = MAP_TABLES[region]
    result: list[TerrainMap] = []
    for map_id in range(MAP_COUNT):
        record = table + map_id * MAP_RECORD_SIZE
        width = int.from_bytes(rom[record + 0x20:record + 0x22], "little")
        height = int.from_bytes(rom[record + 0x22:record + 0x24], "little")
        if width == 0 or height == 0:
            raise ValueError(f"{region.upper()} map {map_id:02d}: empty dimensions")
        terrain_data_offset = pointer_offset(rom, record + 0x18, region, f"map {map_id:02d} terrain-data")
        terrain_map_offset = pointer_offset(rom, record + 0x1C, region, f"map {map_id:02d} terrain-map")
        if (terrain_data_offset is None) != (terrain_map_offset is None):
            raise ValueError(f"{region.upper()} map {map_id:02d}: only one terrain pointer is null")
        if terrain_data_offset is None:
            result.append(TerrainMap(map_id, width, height, None, None, None, b"", b""))
            continue
        cell_count = width * height
        terrain_map = rom[terrain_map_offset:terrain_map_offset + cell_count]
        if len(terrain_map) != cell_count:
            raise ValueError(f"{region.upper()} map {map_id:02d}: terrain map exceeds ROM")
        max_index = max(terrain_map)
        terrain_info_minimum = rom[terrain_data_offset:terrain_data_offset + (max_index + 1) * 4]
        if len(terrain_info_minimum) != (max_index + 1) * 4:
            raise ValueError(f"{region.upper()} map {map_id:02d}: minimum TerrainInfo range exceeds ROM")
        result.append(TerrainMap(
            map_id, width, height, terrain_data_offset, terrain_map_offset,
            max_index, terrain_map, terrain_info_minimum,
        ))
    return tuple(result)


def check_regions(inputs: dict[str, bytes]) -> dict[str, tuple[TerrainMap, ...]]:
    if set(inputs) != set(MAP_TABLES):
        raise ValueError("requires exactly jp, us, eu and de ROMs")
    maps = {region: parse_region(rom, region) for region, rom in inputs.items()}
    for map_id in range(MAP_COUNT):
        variants = [maps[region][map_id] for region in MAP_TABLES]
        if len({(entry.width, entry.height) for entry in variants}) != 1:
            raise ValueError(f"map {map_id:02d}: regional dimensions differ")
        if len({entry.max_index for entry in variants}) != 1:
            raise ValueError(f"map {map_id:02d}: regional terrain-index domain differs")
        if len({hashlib.sha256(entry.terrain_info_minimum).digest() for entry in variants}) != 1:
            raise ValueError(f"map {map_id:02d}: referenced TerrainInfo entries differ")
    return maps


def write_csv(path: Path, maps: dict[str, tuple[TerrainMap, ...]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle)
        writer.writerow((
            "map_id", "width", "height", "terrain_cells", "max_terrain_index",
            "minimum_terrain_info_entries", "jp_terrain_data_offset", "jp_terrain_map_offset",
            "terrain_map_shared", "terrain_info_minimum_shared",
        ))
        for map_id in range(MAP_COUNT):
            entries = [maps[region][map_id] for region in MAP_TABLES]
            first = entries[0]
            writer.writerow((
                f"{map_id:02d}", first.width, first.height, first.cell_count,
                "" if first.max_index is None else first.max_index,
                first.terrain_info_minimum_count,
                "" if first.terrain_data_offset is None else f"0x{first.terrain_data_offset:X}",
                "" if first.terrain_map_offset is None else f"0x{first.terrain_map_offset:X}",
                len({hashlib.sha256(entry.terrain_map).digest() for entry in entries}) == 1,
                len({hashlib.sha256(entry.terrain_info_minimum).digest() for entry in entries}) == 1,
            ))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    parser.add_argument("--csv", type=Path, help="write the per-map audit table")
    arguments = parser.parse_args()
    maps = check_regions({region: Path(path).read_bytes() for region, path in arguments.rom})
    entries = [maps[region][map_id] for map_id in range(MAP_COUNT) for region in ("jp",)]
    shared_grids = sum(
        len({hashlib.sha256(maps[region][map_id].terrain_map).digest() for region in MAP_TABLES}) == 1
        for map_id in range(MAP_COUNT)
        if maps["jp"][map_id].max_index is not None
    )
    total_cells = sum(entry.cell_count for entry in entries)
    terrain_entries = [entry for entry in entries if entry.max_index is not None]
    max_index = max(entry.max_index for entry in terrain_entries)
    if arguments.csv:
        write_csv(arguments.csv, maps)
    print(
        f"verified {len(terrain_entries)} MapData terrain grids and referenced TerrainInfo ranges; "
        f"{shared_grids}/{len(terrain_entries)} terrain grids are byte-identical across regions; "
        f"{total_cells} cells, maximum terrain index {max_index}"
    )


if __name__ == "__main__":
    main()

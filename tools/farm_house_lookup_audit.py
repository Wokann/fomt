#!/usr/bin/env python3
"""Audit the non-image lookup fields in FarmHouse visual descriptors.

``func_080A5BD8`` reads each descriptor's ``lookup_indices`` rectangle,
multiplies each byte by four, and stores the selected 32-bit
``lookup_values`` entry in the field renderer's fourth working buffer.  This
tool records the only bounds established by that code path: an index grid of
``width * height`` bytes and values through the largest index actually read.

It intentionally neither exports an image nor guesses that the 32-bit values
are a palette.  The data is retained in ROM until the field-buffer consumer's
semantic meaning is independently established.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
from dataclasses import dataclass
from pathlib import Path


ROM_BASE = 0x08000000
VISUAL_TABLE_OFFSET = 0x128
VISUAL_DESCRIPTOR_SIZE = 0x2C
DESCRIPTOR_COUNT = 7
LOOKUP_VALUES_OFFSET = 0x10
LOOKUP_INDICES_OFFSET = 0x14
TABLE_BASES = {
    "jp": 0x106C24,
    "us": 0x1070DC,
    "eu": 0x107134,
    "de": 0x107B00,
}


@dataclass(frozen=True)
class LookupRect:
    descriptor: int
    width: int
    height: int
    values_offset: int
    indices_offset: int
    indices: bytes
    values_minimum: bytes

    @property
    def cell_count(self) -> int:
        return self.width * self.height

    @property
    def max_index(self) -> int:
        return max(self.indices)

    @property
    def value_count(self) -> int:
        return self.max_index + 1


def pointer_offset(rom: bytes, pointer_offset: int, region: str, descriptor: int, field: str) -> int:
    pointer = int.from_bytes(rom[pointer_offset:pointer_offset + 4], "little")
    if not ROM_BASE <= pointer < ROM_BASE + len(rom):
        raise ValueError(
            f"{region.upper()} descriptor {descriptor}: invalid {field} pointer {pointer:#010x}"
        )
    return pointer - ROM_BASE


def parse_region(rom: bytes, region: str) -> tuple[LookupRect, ...]:
    table = TABLE_BASES[region] + VISUAL_TABLE_OFFSET
    result: list[LookupRect] = []
    for descriptor in range(DESCRIPTOR_COUNT):
        record = table + descriptor * VISUAL_DESCRIPTOR_SIZE
        width, height = rom[record], rom[record + 1]
        if width == 0 or height == 0:
            raise ValueError(f"{region.upper()} descriptor {descriptor}: invalid empty rectangle")
        values_offset = pointer_offset(
            rom, record + LOOKUP_VALUES_OFFSET, region, descriptor, "lookup-values"
        )
        indices_offset = pointer_offset(
            rom, record + LOOKUP_INDICES_OFFSET, region, descriptor, "lookup-indices"
        )
        indices = rom[indices_offset:indices_offset + width * height]
        if len(indices) != width * height:
            raise ValueError(f"{region.upper()} descriptor {descriptor}: lookup-indices exceed ROM")
        maximum = max(indices)
        values_minimum = rom[values_offset:values_offset + (maximum + 1) * 4]
        if len(values_minimum) != (maximum + 1) * 4:
            raise ValueError(f"{region.upper()} descriptor {descriptor}: lookup-values exceed ROM")
        result.append(LookupRect(
            descriptor, width, height, values_offset, indices_offset, indices, values_minimum
        ))
    return tuple(result)


def check_regions(inputs: dict[str, bytes]) -> dict[str, tuple[LookupRect, ...]]:
    if set(inputs) != set(TABLE_BASES):
        raise ValueError("requires exactly jp, us, eu and de ROMs")
    values = {region: parse_region(rom, region) for region, rom in inputs.items()}
    for descriptor in range(DESCRIPTOR_COUNT):
        entries = [values[region][descriptor] for region in TABLE_BASES]
        if len({(entry.width, entry.height) for entry in entries}) != 1:
            raise ValueError(f"descriptor {descriptor}: regional dimensions differ")
        if len({entry.max_index for entry in entries}) != 1:
            raise ValueError(f"descriptor {descriptor}: regional lookup index domains differ")
        if len({hashlib.sha256(entry.indices).digest() for entry in entries}) != 1:
            raise ValueError(f"descriptor {descriptor}: lookup index grids differ")
        if len({hashlib.sha256(entry.values_minimum).digest() for entry in entries}) != 1:
            raise ValueError(f"descriptor {descriptor}: referenced lookup values differ")
    return values


def write_csv(path: Path, values: dict[str, tuple[LookupRect, ...]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle)
        writer.writerow((
            "descriptor", "width", "height", "cells", "distinct_indices", "max_index",
            "minimum_values", "jp_values_offset", "jp_indices_offset", "all_regions_shared",
        ))
        for descriptor in range(DESCRIPTOR_COUNT):
            entries = [values[region][descriptor] for region in TABLE_BASES]
            entry = entries[0]
            writer.writerow((
                descriptor, entry.width, entry.height, entry.cell_count, len(set(entry.indices)),
                entry.max_index, entry.value_count, f"0x{entry.values_offset:X}",
                f"0x{entry.indices_offset:X}", True,
            ))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    parser.add_argument("--csv", type=Path, help="write the per-descriptor audit table")
    arguments = parser.parse_args()
    values = check_regions({region: Path(path).read_bytes() for region, path in arguments.rom})
    if arguments.csv:
        write_csv(arguments.csv, values)
    cells = sum(entry.cell_count for entry in values["jp"])
    max_index = max(entry.max_index for entry in values["jp"])
    print(
        f"verified {DESCRIPTOR_COUNT} FarmHouse lookup rectangles across all regions; "
        f"{cells} cells, maximum lookup index {max_index}, all referenced values are shared"
    )


if __name__ == "__main__":
    main()

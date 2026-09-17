#!/usr/bin/env python3
"""Inventory literal DMA descriptors that copy named ROM data into video RAM.

The scan intentionally recognises only a narrow assembly pattern around
``func_08008F0C``: a named ``g*`` source loaded into r1, plus a completely
literal r2 destination in character VRAM or palette RAM and r3 byte count.
Literal values may be loaded directly or assembled with `movs`, left shifts
and additions. Rows are code-backed audit leads, never assertions about image
format or ownership.
"""

from __future__ import annotations

import argparse
import csv
import re
from dataclasses import dataclass
from pathlib import Path


CALL = "bl func_08008F0C"
SOURCE = re.compile(r"\bldr\s+r1,\s+[^@]+@\s*=\s*(g[A-Za-z0-9_]+)")
REGISTER = r"(?:r[0-3]|r8|sb|sl)"
LITERAL_LOAD = re.compile(
    rf"\bldr\s+({REGISTER}),\s+[^@]+@\s*=\s*(0x[0-9A-Fa-f]+|\d+)"
)
MOV_IMMEDIATE = re.compile(rf"\bmovs?\s+({REGISTER}),\s*#(0x[0-9A-Fa-f]+|\d+)")
MOV_REGISTER = re.compile(rf"\bmovs?\s+({REGISTER}),\s*({REGISTER})")
SHIFT = re.compile(
    rf"\blsls?\s+({REGISTER}),\s*({REGISTER}),\s*#(0x[0-9A-Fa-f]+|\d+)"
)
SHIFT_SELF = re.compile(rf"\blsls?\s+({REGISTER}),\s*#(0x[0-9A-Fa-f]+|\d+)")
ADD_REGISTERS = re.compile(rf"\badds?\s+({REGISTER}),\s*({REGISTER}),\s*({REGISTER})")
ADD_IMMEDIATE = re.compile(rf"\badds?\s+({REGISTER}),\s*({REGISTER}),\s*#(0x[0-9A-Fa-f]+|\d+)")
ADD_SELF_REGISTER = re.compile(rf"\badds?\s+({REGISTER}),\s*({REGISTER})")
ADD_SELF_IMMEDIATE = re.compile(rf"\badds?\s+({REGISTER}),\s*#(0x[0-9A-Fa-f]+|\d+)")
WRITES_REGISTER = re.compile(rf"^\s*(?:[a-z.]+)\s+({REGISTER})(?:,|\s|$)")


@dataclass(frozen=True)
class Row:
    source: str
    line: int
    symbol: str
    destination: int
    byte_count: int


def literal(value: str) -> int:
    return int(value, 0)


def literal_registers(window: list[str]) -> tuple[str | None, int | None, int | None]:
    """Evaluate only the literal register expressions accepted by this audit."""

    values: dict[str, int | None] = {
        **{f"r{index}": None for index in range(4)},
        "r8": None,
        "sb": None,
        "sl": None,
    }
    source = None
    for line in window:
        if match := SOURCE.search(line):
            source = match.group(1)
            values["r1"] = None
            continue
        if match := LITERAL_LOAD.search(line):
            register = match.group(1)
            values[register] = literal(match.group(2))
            if register == "r1":
                source = None
            continue
        if match := MOV_IMMEDIATE.search(line):
            register = match.group(1)
            values[register] = literal(match.group(2))
            if register == "r1":
                source = None
            continue
        if match := MOV_REGISTER.search(line):
            destination, source_register = match.groups()
            values[destination] = values[source_register]
            if destination == "r1":
                source = None
            continue
        if match := SHIFT.search(line):
            destination, source_register, shift = match.groups()
            value = values[source_register]
            values[destination] = None if value is None else value << literal(shift)
            if destination == "r1":
                source = None
            continue
        if match := SHIFT_SELF.search(line):
            destination, shift = match.groups()
            value = values[destination]
            values[destination] = None if value is None else value << literal(shift)
            if destination == "r1":
                source = None
            continue
        if match := ADD_REGISTERS.search(line):
            destination, left, right = match.groups()
            left_value, right_value = values[left], values[right]
            values[destination] = (
                None if left_value is None or right_value is None else left_value + right_value
            )
            if destination == "r1":
                source = None
            continue
        if match := ADD_IMMEDIATE.search(line):
            destination, source_register, immediate = match.groups()
            value = values[source_register]
            values[destination] = None if value is None else value + literal(immediate)
            if destination == "r1":
                source = None
            continue
        if match := ADD_SELF_REGISTER.search(line):
            destination, source_register = match.groups()
            destination_value, source_value = values[destination], values[source_register]
            values[destination] = (
                None if destination_value is None or source_value is None
                else destination_value + source_value
            )
            if destination == "r1":
                source = None
            continue
        if match := ADD_SELF_IMMEDIATE.search(line):
            destination, immediate = match.groups()
            value = values[destination]
            values[destination] = None if value is None else value + literal(immediate)
            if destination == "r1":
                source = None
            continue
        # An unrecognised assignment invalidates any earlier literal value.
        if match := WRITES_REGISTER.search(line):
            values[match.group(1)] = None
            if match.group(1) == "r1":
                source = None
    return source, values["r2"], values["r3"]


def scan_file(path: Path, root: Path) -> list[Row]:
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    rows: list[Row] = []
    for index, line in enumerate(lines):
        if CALL not in line:
            continue
        # Several functions establish a reusable literal helper register before
        # loading the final source and DMA arguments.  Keep a conservative
        # local window while invalidating every overwritten tracked register.
        window = lines[max(0, index - 64):index]
        source, destination, count = literal_registers(window)
        if source is None or destination is None or count is None:
            continue
        is_character_vram = 0x06000000 <= destination < 0x06018000
        is_palette_ram = 0x05000000 <= destination < 0x05000400
        if is_character_vram or is_palette_ram:
            rows.append(Row(path.relative_to(root).as_posix(), index + 1,
                            source, destination, count))
    return rows


def rows(root: Path) -> list[Row]:
    result: list[Row] = []
    for path in sorted((root / "asm").glob("*.s")):
        result.extend(scan_file(path, root))
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path)
    parser.add_argument("--csv", type=Path)
    arguments = parser.parse_args()
    result = rows(arguments.root)
    if arguments.csv is None:
        for row in result:
            print(f"{row.source}:{row.line}: {row.symbol} -> "
                  f"{row.destination:#010x}, {row.byte_count:#x} bytes")
        return
    arguments.csv.parent.mkdir(parents=True, exist_ok=True)
    with arguments.csv.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(("source", "line", "symbol", "destination", "byte_count"))
        for row in result:
            writer.writerow((row.source, row.line, row.symbol,
                             f"{row.destination:#010x}", f"{row.byte_count:#x}"))


if __name__ == "__main__":
    main()

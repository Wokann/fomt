#!/usr/bin/env python3
"""Inventory literal DMA descriptors that copy named ROM data into VRAM.

The scan intentionally recognises only a narrow assembly pattern around
``func_08008F0C``: a named ``g*`` source loaded into r1, a literal VRAM
destination loaded into r2, and a simple literal r3 byte count.  Rows are
code-backed audit leads, never assertions about image format or ownership.
"""

from __future__ import annotations

import argparse
import csv
import re
from dataclasses import dataclass
from pathlib import Path


CALL = "bl func_08008F0C"
SOURCE = re.compile(r"\bldr\s+r1,\s+[^@]+@\s*=\s*(g[A-Za-z0-9_]+)")
DESTINATION = re.compile(r"\bldr\s+r2,\s+[^@]+@\s*=\s*(0x060[0-9A-Fa-f]+)")
MOV_R3 = re.compile(r"\bmovs\s+r3,\s*#(0x[0-9A-Fa-f]+|\d+)")
SHIFT_R3 = re.compile(r"\blsls\s+r3,\s*(?:r3,\s*)?#(0x[0-9A-Fa-f]+|\d+)")


@dataclass(frozen=True)
class Row:
    source: str
    line: int
    symbol: str
    vram_destination: int
    byte_count: int


def literal(value: str) -> int:
    return int(value, 0)


def scan_file(path: Path, root: Path) -> list[Row]:
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    rows: list[Row] = []
    for index, line in enumerate(lines):
        if CALL not in line:
            continue
        window = lines[max(0, index - 12):index]
        source = next((match.group(1) for item in reversed(window)
                       if (match := SOURCE.search(item))), None)
        destination = next((match.group(1) for item in reversed(window)
                            if (match := DESTINATION.search(item))), None)
        count = None
        for item in window:
            if match := MOV_R3.search(item):
                count = literal(match.group(1))
            elif count is not None and (match := SHIFT_R3.search(item)):
                count <<= literal(match.group(1))
        if source is not None and destination is not None and count is not None:
            rows.append(Row(path.relative_to(root).as_posix(), index + 1,
                            source, literal(destination), count))
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
                  f"{row.vram_destination:#010x}, {row.byte_count:#x} bytes")
        return
    arguments.csv.parent.mkdir(parents=True, exist_ok=True)
    with arguments.csv.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(("source", "line", "symbol", "vram_destination", "byte_count"))
        for row in result:
            writer.writerow((row.source, row.line, row.symbol,
                             f"{row.vram_destination:#010x}", f"{row.byte_count:#x}"))


if __name__ == "__main__":
    main()

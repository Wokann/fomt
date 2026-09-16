#!/usr/bin/env python3
"""Inventory labelled ``func_08008E64`` copies into VRAM or palette RAM.

The helper performs an ordinary memory copy rather than DMA or decompression.
Rows are code-backed leads only: a source reaching VRAM does not by itself
prove 4bpp tiles, palette ownership, or an editable visual layout.
"""

from __future__ import annotations

import argparse
import csv
from pathlib import Path

from unpack_inventory import calls


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="project root containing asm/")
    parser.add_argument("--csv", type=Path, help="write CSV instead of text")
    arguments = parser.parse_args()
    root = arguments.root.resolve()
    rows = [
        row for row in calls(root, "func_08008E64", include_size=True)
        if row.destination_kind in {"vram", "palette_ram"}
    ]
    if arguments.csv:
        arguments.csv.parent.mkdir(parents=True, exist_ok=True)
        with arguments.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow(("source", "line", "function", "symbol", "destination_kind", "destination", "byte_count"))
            for row in rows:
                writer.writerow((
                    row.source, row.line, row.function, row.symbol,
                    row.destination_kind, row.destination, row.byte_count,
                ))
        return
    print(f"conservative labelled func_08008E64 paths to VRAM/palette RAM: {len(rows)}")
    for row in rows:
        size = row.byte_count or "unknown size"
        print(f"{row.source}:{row.line}: {row.symbol} -> {row.destination_kind} {row.destination}, {size}")


if __name__ == "__main__":
    main()

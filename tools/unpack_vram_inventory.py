#!/usr/bin/env python3
"""Write the VRAM-only view of :mod:`unpack_inventory`.

The shared control-flow-aware audit retains alternative branch sources before
this narrow report filters them to literal VRAM destinations.  A row proves a
labelled source can reach ``Unpack`` at that address; it does not prove tile,
palette, OAM, or image ownership.
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
    rows = [row for row in calls(root) if row.destination_kind == "vram"]
    if arguments.csv:
        arguments.csv.parent.mkdir(parents=True, exist_ok=True)
        with arguments.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow(("source", "line", "symbol", "vram_destination"))
            for row in rows:
                writer.writerow((row.source, row.line, row.symbol, row.destination))
        return
    print(f"conservative labelled Unpack-to-VRAM paths: {len(rows)}")
    for row in rows:
        print(f"{row.source}:{row.line}: {row.symbol} -> {row.destination}")


if __name__ == "__main__":
    main()

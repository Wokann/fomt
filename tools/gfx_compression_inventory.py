#!/usr/bin/env python3
"""Inventory direct ROM ranges that begin with a verified Popuri ``0x70`` stream.

This is deliberately an audit tool, not an extractor.  A successful decode only
proves that a labelled ROM range begins with a compressed payload and records
its decoded size and codec settings.  It does *not* establish whether the
payload is graphics, a tilemap, sound, or another data family, nor whether the
surrounding ``.incbin`` range is its exact packed boundary.
"""

from __future__ import annotations

import argparse
import csv
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import UnpackException, unpack_with_consumed  # type: ignore[import-not-found]
from gfx_incbin_inventory import Range, iter_ranges


@dataclass(frozen=True)
class Candidate:
    source: str
    line: int
    symbol: str
    rom: str
    offset: int
    container_end: int
    consumed_size: int
    decoded_size: int
    format_spec: str
    ladder_spec: str


def decode_candidate(root: Path, entry: Range) -> Candidate | None:
    if entry.offset is None or entry.length is None or entry.length < 4:
        return None
    rom_path = root / entry.rom
    if not rom_path.is_file():
        return None
    rom = rom_path.read_bytes()
    if entry.offset < 0 or entry.offset + entry.length > len(rom):
        return None
    if rom[entry.offset] != 0x70:
        return None
    try:
        payload, format_spec, ladder_spec, consumed_size = unpack_with_consumed(rom, entry.offset)
    except (UnpackException, IndexError, ValueError):
        return None
    return Candidate(
        source=entry.source.relative_to(root).as_posix(),
        line=entry.line,
        symbol=entry.symbol or "",
        rom=entry.rom,
        offset=entry.offset,
        container_end=entry.offset + entry.length,
        consumed_size=consumed_size,
        decoded_size=len(payload),
        format_spec=format_spec,
        ladder_spec=ladder_spec,
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="project root containing asm/ and baserom files")
    parser.add_argument("--csv", type=Path, help="write CSV instead of the text report")
    arguments = parser.parse_args()

    root = arguments.root.resolve()
    candidates = [candidate for entry in iter_ranges(root / "asm") if (candidate := decode_candidate(root, entry))]
    candidates.sort(key=lambda candidate: (candidate.rom, candidate.offset, candidate.source, candidate.line))

    if arguments.csv:
        arguments.csv.parent.mkdir(parents=True, exist_ok=True)
        with arguments.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow((
                "rom", "source", "line", "symbol", "offset", "container_end", "consumed_size",
                "decoded_size", "format", "ladder",
            ))
            for candidate in candidates:
                writer.writerow((
                    candidate.rom, candidate.source, candidate.line, candidate.symbol,
                    f"0x{candidate.offset:X}", f"0x{candidate.container_end:X}", f"0x{candidate.consumed_size:X}",
                    f"0x{candidate.decoded_size:X}", candidate.format_spec, candidate.ladder_spec,
                ))
        return

    print(f"verified 0x70 starts in direct ROM ranges: {len(candidates)}")
    for candidate in candidates:
        name = candidate.symbol or "-"
        print(
            f"{candidate.rom:15} {candidate.source}:{candidate.line} {name}: "
            f"0x{candidate.offset:08X} within 0x{candidate.offset:08X}-0x{candidate.container_end:08X}; "
            f"decoder reads {candidate.consumed_size:#x}; "
            f"output {candidate.decoded_size:#x}, format {candidate.format_spec}, ladder {candidate.ladder_spec}"
        )


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Exercise one editable complete portrait without changing repository art.

The baseline proves that every committed full portrait reconstitutes the
archive's native table-four tile data. The edited half changes one visible
palette-indexed pixel in a temporary copy and proves that the emitted bytes
stay inside that portrait descriptor's fixed native tile interval.
"""

from __future__ import annotations

import argparse
import shutil
import tempfile
from pathlib import Path

from portrait_archive import (
    audit,
    load_archive,
    portrait_descriptor,
    read_png_indexed,
    rebuild_full_data,
    write_png_indexed,
)


def parse_number(text: str) -> int:
    return int(text, 0)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--offset", required=True, type=parse_number)
    parser.add_argument("--length", default=0x5E0A4, type=parse_number)
    parser.add_argument("--source", required=True, type=Path)
    arguments = parser.parse_args()

    archive = load_archive(arguments.rom, arguments.offset, arguments.length)
    audit(archive)
    source_full = arguments.source / "full"
    candidate = next(iter(sorted(source_full.glob("000_*.png"))), None)
    if candidate is None:
        raise FileNotFoundError("missing portrait 000 full PNG")

    with tempfile.TemporaryDirectory(prefix="fomt_portrait_edit_") as temporary:
        temporary_root = Path(temporary)
        source = temporary_root / "source"
        shutil.copytree(source_full, source / "full")

        baseline, baseline_changes = rebuild_full_data(archive, source)
        if baseline_changes != 0:
            raise AssertionError("unmodified full portrait sources report visible changes")
        table_four = archive.table_offsets[3]
        retail = archive.data[table_four:table_four + len(baseline)]
        if baseline != retail:
            raise AssertionError("unmodified full portraits did not reproduce native tiles")

        edited_path = source / "full" / candidate.name
        width, height, indexes, palette = read_png_indexed(edited_path)
        changed = bytearray(indexes)
        pixel = next((index for index, value in enumerate(changed) if value != 0), None)
        if pixel is None:
            raise AssertionError("test portrait has no visible pixels")
        changed[pixel] = (changed[pixel] % 15) + 1
        write_png_indexed(edited_path, width, height, bytes(changed), palette)

        edited, changed_pixels = rebuild_full_data(archive, source)
        changed_bytes = [
            index for index, (before, after) in enumerate(zip(baseline, edited))
            if before != after
        ]
        if changed_pixels != 1 or not changed_bytes:
            raise AssertionError("one visible portrait edit did not alter native tile bytes")

        portrait_id = int(candidate.name.split("_", 1)[0], 10)
        _, _, tile_count, tile_start, _ = portrait_descriptor(archive, portrait_id)
        owned = range(tile_start * 32, (tile_start + tile_count) * 32)
        unexpected = [index for index in changed_bytes if index not in owned]
        if unexpected:
            raise AssertionError(
                "portrait edit changed bytes outside its descriptor tile range: "
                f"{unexpected[:8]}"
            )

        print(
            f"portrait edit test: {candidate.name}, {len(changed_bytes)} native "
            "tile byte(s) changed within its descriptor range"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

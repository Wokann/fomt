#!/usr/bin/env python3
"""Exercise a real editable actor PNG without changing repository sources.

The baseline half proves that selected complete OAM PNGs rebuild exactly to
the native table-four bytes. The edited half changes one visible nonzero pixel
in a temporary copy, verifies that the resulting 4bpp bytes change, and proves
that every changed byte belongs to a tile range claimed by the tested frames.
"""

from __future__ import annotations

import argparse
import shutil
import sys
import tempfile
from pathlib import Path

from actor_archive import (
    ACTOR_ARCHIVE_COUNTS,
    frame_descriptor,
    rebuild_frames,
    selected_frame_ids,
)
from portrait_archive import load_archive, read_png_indexed, write_png_indexed


def parse_number(text: str) -> int:
    return int(text, 0)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--offset", required=True, type=parse_number)
    parser.add_argument("--length", default=0xDB638, type=parse_number)
    parser.add_argument("--source", required=True, type=Path)
    args = parser.parse_args()

    archive = load_archive(args.rom, args.offset, args.length, trailing_bytes=0)
    if archive.counts != ACTOR_ARCHIVE_COUNTS:
        raise ValueError(f"unexpected actor archive table counts: {archive.counts}")

    # Rick selector 0x212 is covered by the committed source set and references
    # a small, independent group of three complete OAM-composited frames.
    animation_ids = [0x212]
    frame_ids = selected_frame_ids(archive, animation_ids)
    if not frame_ids:
        raise AssertionError("test selector has no frames")

    with tempfile.TemporaryDirectory(prefix="fomt_actor_edit_") as temporary:
        temporary_root = Path(temporary)
        source = temporary_root / "rick"
        for frame_id in frame_ids:
            filename = f"frame_{frame_id:04d}.png"
            original = args.source / "full" / filename
            if not original.is_file():
                raise FileNotFoundError(f"missing committed test frame: {original}")
            destination = source / "full" / filename
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(original, destination)

        baseline_path = temporary_root / "baseline.4bpp"
        rebuild_frames(archive, animation_ids, [source], baseline_path)
        native_offset = archive.table_offsets[3]
        native = archive.data[native_offset:native_offset + archive.counts[3] * 32]
        baseline = baseline_path.read_bytes()
        if baseline != native:
            raise AssertionError("unmodified complete frames did not reproduce native actor tiles")

        edited_id = frame_ids[0]
        edited_path = source / "full" / f"frame_{edited_id:04d}.png"
        width, height, indexes, colors = read_png_indexed(edited_path)
        changed = bytearray(indexes)
        pixel_index = next((index for index, value in enumerate(changed) if value), None)
        if pixel_index is None:
            raise AssertionError(f"test frame {edited_id:04d} has no visible pixels")
        changed[pixel_index] = 2 if changed[pixel_index] == 1 else 1
        write_png_indexed(edited_path, width, height, bytes(changed), colors)

        edited_path_output = temporary_root / "edited.4bpp"
        rebuild_frames(archive, animation_ids, [source], edited_path_output)
        edited = edited_path_output.read_bytes()
        changed_bytes = [
            offset for offset, (before, after) in enumerate(zip(native, edited))
            if before != after
        ]
        if not changed_bytes:
            raise AssertionError("editing a visible source pixel did not change actor tiles")

        owned_bytes: set[int] = set()
        for frame_id in frame_ids:
            frame = frame_descriptor(archive, frame_id)
            owned_bytes.update(range(frame.tile_start * 32, (frame.tile_start + frame.tile_count) * 32))
        unexpected = [offset for offset in changed_bytes if offset not in owned_bytes]
        if unexpected:
            raise AssertionError(
                f"edited frame changed bytes outside its native tile ranges: {unexpected[:8]}"
            )

        print(
            f"actor edit test: selector 0x212, frames {', '.join(map(str, frame_ids))}, "
            f"{len(changed_bytes)} native tile byte(s) changed within owned ranges"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

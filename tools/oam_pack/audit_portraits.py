#!/usr/bin/env python3
"""Exercise the C forward OAM packer against every checked-in portrait.

The reference ROM is a regression oracle only.  The packer receives only the
full indexed PNG while producing its tiles, palette and OAM records.  A byte
match is reported, but is not required: legacy portraits can contain invisible
padding and overlapping OAM pieces which cannot be inferred from visible PNG
pixels alone.
"""

from __future__ import annotations

import argparse
from pathlib import Path
import subprocess
import sys


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("packer", type=Path)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--archive-offset", required=True)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    arguments = parser.parse_args()

    images = sorted(arguments.source.glob("*.png"))
    if not images:
        parser.error("source directory contains no PNG files")
    arguments.output.mkdir(parents=True, exist_ok=True)

    exact = []
    for expected_id, image in enumerate(images):
        try:
            portrait_id = int(image.name.split("_", 1)[0], 10)
        except ValueError as error:
            raise SystemExit(f"invalid portrait filename: {image.name}") from error
        if portrait_id != expected_id:
            raise SystemExit(
                f"portrait numbering must be contiguous: expected {expected_id:03d}, got {image.name}"
            )
        command = [
            str(arguments.packer), str(image),
            "--tiles", str(arguments.output / "portrait.4bpp"),
            "--palette", str(arguments.output / "portrait.gbapal"),
            "--oam", str(arguments.output / "portrait.oam"),
            "--origin-x", "-24", "--origin-y", "-72", "--strategy", "canvas",
            "--reference-rom", str(arguments.rom),
            "--reference-offset", arguments.archive_offset,
            "--portrait-id", str(portrait_id), "--report-only",
        ]
        result = subprocess.run(command, text=True, capture_output=True)
        if result.returncode:
            sys.stderr.write(result.stderr)
            sys.stderr.write(result.stdout)
            raise SystemExit(f"OAM generation failed for {image.name}")
        if result.stdout.count(", identical") == 3:
            exact.append(portrait_id)

    print(f"canvas generated valid tile/OAM data for {len(images)}/{len(images)} portraits")
    print(f"byte-identical tile/palette/OAM portraits: {len(exact)}/{len(images)} ({', '.join(map(str, exact))})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

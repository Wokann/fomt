#!/usr/bin/env python3
"""Verify region-local IndexedResourceArchive post-link patches.

Unlike the shared archive helper, a localized archive can have a distinct
fixed allocation and descriptor table in every region.  This tool deliberately
accepts every range explicitly, validates its native profile, then exercises
the common patch routine without writing to any retail ROM.
"""

from __future__ import annotations

import argparse
from pathlib import Path

import common_resource_archive as archive_tool


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--case",
        action="append",
        nargs=7,
        metavar=("REGION", "ROM", "OFFSET", "LENGTH", "SHA256", "PROFILE", "ARCHIVE"),
        required=True,
        help="one independently bounded regional archive",
    )
    args = parser.parse_args()

    seen: set[str] = set()
    for region, rom_text, offset_text, length_text, digest, profile_name, archive_text in args.case:
        normalized = region.upper()
        if normalized in seen:
            raise ValueError(f"duplicate regional archive case: {normalized}")
        seen.add(normalized)
        if profile_name not in archive_tool.PROFILES:
            raise ValueError(f"unknown common archive profile: {profile_name}")

        archive_tool.ACTIVE_PROFILE = archive_tool.PROFILES[profile_name]
        rom = Path(rom_text)
        offset = int(offset_text, 0)
        length = int(length_text, 0)
        baseline = archive_tool.load_checked(rom, offset, length, digest)
        built = Path(archive_text).read_bytes()
        original = rom.read_bytes()
        if archive_tool.patch_bytes(original, baseline, offset, built) != original:
            raise AssertionError(
                f"unchanged {normalized} localized archive patch changes retail ROM bytes"
            )

    if seen != {"JP", "US", "EU", "DE"}:
        raise ValueError("regional archive patch verification requires JP, US, EU, and DE cases")
    print("verified unchanged localized archive post-link patches against all four retail ROMs")


if __name__ == "__main__":
    main()

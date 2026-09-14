#!/usr/bin/env python3
"""Inspect the native IndexedResourceArchive header without guessing its payload type.

``src/resource_handle.cc`` proves this header's six counted descriptor blocks
and final four-byte entries.  The individual descriptor fields are not all
understood yet, so this tool reports only their proven boundaries and compares
the complete native archive across regional ROMs.  It is an inventory tool,
not a graphics extractor.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
from dataclasses import dataclass
from pathlib import Path


SECTION_SIZES = (4, 16, 8, 32, 32, 8)


@dataclass(frozen=True)
class Archive:
    offset: int
    section_counts: tuple[int, ...]
    entry_count: int
    encoded_length: int
    sha256: str


def parse(data: bytes, offset: int) -> Archive:
    """Parse exactly the layout established by IndexedResourceArchive's constructor."""
    cursor = offset
    counts: list[int] = []
    for element_size in SECTION_SIZES:
        if cursor + 4 > len(data):
            raise ValueError(f"archive header at {offset:#x} exceeds ROM bounds")
        count, _reserved = struct.unpack_from("<HH", data, cursor)
        cursor += 4
        end = cursor + count * element_size
        if end > len(data):
            raise ValueError(f"archive section at {offset:#x} exceeds ROM bounds")
        counts.append(count)
        cursor = end

    if cursor + 4 > len(data):
        raise ValueError(f"archive entry count at {offset:#x} exceeds ROM bounds")
    entry_count, _reserved = struct.unpack_from("<HH", data, cursor)
    cursor += 4
    end = cursor + entry_count * 4
    if end > len(data):
        raise ValueError(f"archive entries at {offset:#x} exceed ROM bounds")
    payload = data[offset:end]
    return Archive(
        offset=offset,
        section_counts=tuple(counts),
        entry_count=entry_count,
        encoded_length=len(payload),
        sha256=hashlib.sha256(payload).hexdigest(),
    )


def format_archive(region: str, archive: Archive) -> str:
    counts = ", ".join(str(value) for value in archive.section_counts)
    return (
        f"{region}: offset={archive.offset:#x}, length={archive.encoded_length:#x}, "
        f"descriptor-counts=[{counts}], entries={archive.entry_count}, sha256={archive.sha256}"
    )


def inspect(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    print(format_archive(arguments.region, parse(rom, arguments.offset)))


def compare(arguments: argparse.Namespace) -> None:
    archives: dict[str, Archive] = {}
    for region, rom_path, offset_text in arguments.rom:
        if region in archives:
            raise ValueError(f"duplicate region: {region}")
        archives[region] = parse(Path(rom_path).read_bytes(), int(offset_text, 0))
    if len(archives) < 2:
        raise ValueError("compare requires at least two --rom REGION ROM OFFSET inputs")
    for region in sorted(archives):
        print(format_archive(region, archives[region]))
    reference = next(iter(archives.values()))
    if any(archive.encoded_length != reference.encoded_length for archive in archives.values()):
        raise ValueError("regional archive boundaries differ")
    if any(archive.sha256 != reference.sha256 for archive in archives.values()):
        raise ValueError("regional archive bytes differ")
    print(f"verified {len(archives)} identical IndexedResourceArchive payloads")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    inspect_parser = commands.add_parser("inspect")
    inspect_parser.add_argument("--region", required=True)
    inspect_parser.add_argument("--rom", type=Path, required=True)
    inspect_parser.add_argument("--offset", type=lambda value: int(value, 0), required=True)
    compare_parser = commands.add_parser("compare")
    compare_parser.add_argument(
        "--rom", nargs=3, action="append", metavar=("REGION", "ROM", "OFFSET"), required=True,
    )
    arguments = parser.parse_args()
    if arguments.command == "inspect":
        inspect(arguments)
    else:
        compare(arguments)


if __name__ == "__main__":
    main()

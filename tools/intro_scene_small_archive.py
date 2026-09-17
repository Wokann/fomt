#!/usr/bin/env python3
"""Rebuild the shared raw IndexedResourceArchive initialized by func_08000914.

This 0x118-byte archive is not compressed.  It contains one selector, three
complete OAM-composited 16-by-16 frames, four 4bpp tiles, and one BGR555
palette.  All four retail regions have identical bytes, so one shared PNG
source directory is authoritative.  Frame geometry is parsed from the archive
itself; no JSON layout metadata is used.
"""

from __future__ import annotations

import argparse
import hashlib
import shutil
import sys
import tempfile
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path.insert(0, str(TOOLS))

from actor_archive import frame_oam  # type: ignore[import-not-found]
from intro_scene_indexed_archive import (  # type: ignore[import-not-found]
    archive_from_data,
    audit,
    export_frames,
    frame_source,
    patched_decoded,
    selected_frames,
)
from portrait_archive import read_png_indexed, write_png_indexed  # type: ignore[import-not-found]


LENGTH = 0x118
SHA256 = "7dac0700376ced9be7f93da9873a1d65569f4bc05a9f18a24c60f32c45b22a51"
OFFSETS = {"jp": 0x4D4CC4, "us": 0x74E530, "eu": 0x74E58C, "de": 0x4D599C}


def load(path: Path, region: str) -> tuple[bytes, object]:
    data = path.read_bytes()[OFFSETS[region]:OFFSETS[region] + LENGTH]
    if len(data) != LENGTH:
        raise ValueError(f"{region}: small archive exceeds ROM bounds")
    if hashlib.sha256(data).hexdigest() != SHA256:
        raise ValueError(f"{region}: small archive SHA-256 does not match the retail baseline")
    return data, archive_from_data(data)


def export(arguments: argparse.Namespace) -> None:
    archives: dict[str, bytes] = {}
    for region, filename in arguments.rom:
        data, archive = load(Path(filename), region)
        archives[region] = data
        frames = audit(archive, region, "raw", "none")
        export_frames(archive, frames, arguments.source_dir, arguments.replace)
    if set(archives) != set(OFFSETS) or len(set(archives.values())) != 1:
        raise ValueError("export requires four identical jp/us/eu/de retail archives")
    print("verified one shared raw indexed-archive PNG source set")


def build(arguments: argparse.Namespace) -> None:
    baseline, archive = load(arguments.rom, arguments.region)
    frames = audit(archive, arguments.region, "raw", "none")
    output = patched_decoded(archive, frames, arguments.source_dir)
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(output)
    print(f"rebuilt {arguments.region.upper()} raw indexed archive ({len(output):#x} bytes)")
    if output == baseline:
        return


def verify(arguments: argparse.Namespace) -> None:
    for region, filename in arguments.rom:
        path = Path(filename)
        baseline, archive = load(path, region)
        frames = audit(archive, region, "raw", "none")
        rebuilt = patched_decoded(archive, frames, arguments.source_dir)
        if rebuilt != baseline:
            raise AssertionError(f"{region}: unchanged PNG sources do not reproduce the raw archive")
        original_rom = path.read_bytes()
        patched_rom = bytearray(original_rom)
        offset = OFFSETS[region]
        patched_rom[offset:offset + len(rebuilt)] = rebuilt
        if patched_rom != original_rom:
            raise AssertionError(f"{region}: unchanged full-ROM patch differs from retail input")
        if arguments.output_root is not None:
            output = arguments.output_root / region / "graphics" / "intro_scene" / "small_indexed_archive" / "archive.bin"
            if output.read_bytes() != baseline:
                raise AssertionError(f"{region}: built raw archive differs from retail bytes")
    print("verified every shared raw archive range and unchanged full-ROM patch")


def edit_test(arguments: argparse.Namespace) -> None:
    baseline, archive = load(arguments.rom, arguments.region)
    frames = audit(archive, arguments.region, "raw", "none")
    drawable = next(frame_id for frame_id in frames if frame_oam(archive, frame_id))
    with tempfile.TemporaryDirectory(prefix="fomt-small-indexed-archive-") as temporary:
        staged = Path(temporary) / "source"
        shutil.copytree(arguments.source_dir, staged)
        filename = frame_source(staged, drawable)
        width, height, pixels, colors = read_png_indexed(filename)
        index = next(index for index, value in enumerate(pixels) if value)
        edited = bytearray(pixels)
        edited[index] = (edited[index] % 15) + 1
        write_png_indexed(filename, width, height, bytes(edited), colors)
        rebuilt = patched_decoded(archive, frames, staged)
    if rebuilt == baseline:
        raise AssertionError("small indexed-archive PNG edit did not change native bytes")
    print(f"{arguments.region.upper()} raw indexed archive PNG edit test: frame {drawable:04d}, pixel {index:#x}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    export_parser.add_argument("--replace", action="store_true")
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(OFFSETS), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output", type=Path, required=True)
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--rom", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)
    verify_parser.add_argument("--output-root", type=Path)
    edit_parser = commands.add_parser("edit-test")
    edit_parser.add_argument("--region", choices=tuple(OFFSETS), required=True)
    edit_parser.add_argument("--rom", type=Path, required=True)
    edit_parser.add_argument("--source-dir", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command in ("export", "verify"):
        arguments.rom = [(region, Path(path)) for region, path in arguments.rom]
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        raise AssertionError("unreachable")


if __name__ == "__main__":
    main()

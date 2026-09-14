#!/usr/bin/env python3
"""Rebuild a verified FoMT graphics source PNG from a retail ROM.

The manifest supplies every physical fact: ROM interval, native image format,
and expected source hash.  This tool intentionally supports only formats with
a verified layout; adding a manifest for an unknown blob is not enough to make
it an image asset.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import sys
import tempfile
from pathlib import Path


def parse_number(value: str) -> int:
    return int(value, 0)


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def command(arguments: list[str]) -> None:
    print("+", " ".join(arguments))
    subprocess.run(arguments, check=True)


def extract_font_1bpp(args: argparse.Namespace) -> None:
    manifest_path = Path(args.manifest).resolve()
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    sources = manifest.get("sources")
    if not isinstance(sources, dict):
        raise ValueError("manifest does not declare regional sources")
    source = sources.get(args.region.upper())
    if not isinstance(source, dict):
        available = ", ".join(sorted(sources))
        raise ValueError(
            f"manifest has no source for {args.region.upper()}; available regions: {available}"
        )
    format_info = manifest["format"]
    kind = format_info["kind"]
    if kind not in {"font_1bpp_8x12", "font_1bpp_16x12"}:
        raise ValueError(f"unsupported font layout: {kind}")

    offset = parse_number(source["rom_offset"])
    length = parse_number(source["length"])
    rom = Path(args.rom)
    with rom.open("rb") as handle:
        handle.seek(offset)
        native = handle.read(length)
    if len(native) != length:
        raise ValueError(f"ROM ends before the declared interval at 0x{offset:X}")
    actual_hash = digest(native)
    expected_hash = source["sha256"].lower()
    if actual_hash != expected_hash:
        raise ValueError(
            "ROM interval hash mismatch: expected "
            f"{expected_hash}, got {actual_hash}; refusing to export a different asset"
        )

    glyph_count = int(format_info["glyph_count"])
    record_bytes = int(format_info["native_record_bytes"])
    if glyph_count * record_bytes != length:
        raise ValueError("manifest glyph count and record size do not cover the ROM interval")

    output = Path(args.output).resolve() if args.output else manifest_path.parent / manifest["image"]
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="fomt-gfx-") as temporary:
        temporary_path = Path(temporary)
        native_path = temporary_path / "font.native.1bpp"
        padded_path = temporary_path / "font.1bpp"
        native_path.write_bytes(native)
        if kind == "font_1bpp_8x12":
            pack_command = "pack-grid-12-to-16"
            png_tile_width = int(format_info["grid_columns"])
        else:
            pack_command = "pack-grid-16x12-to-16x16"
            png_tile_width = int(format_info["grid_columns"]) * 2
        command([
            str(Path(args.fontpad)), pack_command, str(native_path),
            str(padded_path), str(format_info["grid_columns"]),
        ])
        command([
            str(Path(args.gbagfx)), str(padded_path), str(output),
            "-width", str(png_tile_width),
        ])

    print(f"exported {manifest['id']} to {output}")
    print(f"verified source SHA-256: {actual_hash}")


def extract_tiles_4bpp(args: argparse.Namespace) -> None:
    manifest_path = Path(args.manifest).resolve()
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    sources = manifest.get("sources")
    if not isinstance(sources, dict):
        raise ValueError("manifest does not declare regional sources")
    source = sources.get(args.region.upper())
    if not isinstance(source, dict):
        available = ", ".join(sorted(sources))
        raise ValueError(
            f"manifest has no source for {args.region.upper()}; available regions: {available}"
        )
    format_info = manifest["format"]
    if format_info["kind"] != "tiles_4bpp":
        raise ValueError("manifest is not a raw 4bpp tile sheet")

    offset = parse_number(source["rom_offset"])
    length = parse_number(source["length"])
    rom = Path(args.rom)
    with rom.open("rb") as handle:
        handle.seek(offset)
        native = handle.read(length)
    if len(native) != length:
        raise ValueError(f"ROM ends before the declared interval at 0x{offset:X}")
    actual_hash = digest(native)
    expected_hash = source["sha256"].lower()
    if actual_hash != expected_hash:
        raise ValueError(
            "ROM interval hash mismatch: expected "
            f"{expected_hash}, got {actual_hash}; refusing to export a different asset"
        )

    tile_count = int(format_info["tile_count"])
    if tile_count * 32 != length:
        raise ValueError("manifest tile count does not cover the ROM interval")

    output = Path(args.output).resolve() if args.output else manifest_path.parent / manifest["image"]
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="fomt-gfx-") as temporary:
        native_path = Path(temporary) / "tiles.4bpp"
        native_path.write_bytes(native)
        command([
            str(Path(args.gbagfx)), str(native_path), str(output),
            "-width", str(format_info["grid_columns"]),
        ])

    print(f"exported {manifest['id']} to {output}")
    print(f"verified source SHA-256: {actual_hash}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="format", required=True)
    font = subparsers.add_parser("font-1bpp", help="export a verified regional 1bpp font")
    font.add_argument("--manifest", required=True, help="JSON asset metadata")
    font.add_argument("--region", required=True, choices=("JP", "US", "EU", "DE", "jp", "us", "eu", "de"), help="retail ROM region")
    font.add_argument("--rom", required=True, help="retail ROM containing the declared interval")
    font.add_argument("--gbagfx", required=True, help="path to the built gbagfx executable")
    font.add_argument("--fontpad", required=True, help="path to the built fontpad executable")
    font.add_argument("--output", help="override the manifest image path")
    tiles = subparsers.add_parser("tiles-4bpp", help="export a verified regional 4bpp tile sheet")
    tiles.add_argument("--manifest", required=True, help="JSON asset metadata")
    tiles.add_argument("--region", required=True, choices=("JP", "US", "EU", "DE", "jp", "us", "eu", "de"), help="retail ROM region")
    tiles.add_argument("--rom", required=True, help="retail ROM containing the declared interval")
    tiles.add_argument("--gbagfx", required=True, help="path to the built gbagfx executable")
    tiles.add_argument("--output", help="override the manifest image path")
    args = parser.parse_args()

    try:
        if args.format == "font-1bpp":
            extract_font_1bpp(args)
            return 0
        if args.format == "tiles-4bpp":
            extract_tiles_4bpp(args)
            return 0
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        print(f"extract_gfx: {error}", file=sys.stderr)
        return 1
    raise AssertionError("unreachable")


if __name__ == "__main__":
    raise SystemExit(main())

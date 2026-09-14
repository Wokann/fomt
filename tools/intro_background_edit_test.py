#!/usr/bin/env python3
"""Prove an edited Intro Scene background still has a valid fitting 0x70 stream."""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff8_lz3
from palette_banks import dimensions
from tile_grid import encode, read_png


STREAM_OFFSET = 0x743058
STREAM_LENGTH = 0x49BC
STREAM_SHA256 = "f0c828f16cafc75c3b277841bca74d1b7f62bbdf3551c9b591103c0f46213d4f"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("tiles_source", type=Path)
    parser.add_argument("palette_source", type=Path)
    arguments = parser.parse_args()

    baseline = arguments.rom.read_bytes()[STREAM_OFFSET:STREAM_OFFSET + STREAM_LENGTH]
    if hashlib.sha256(baseline).hexdigest() != STREAM_SHA256:
        raise ValueError("US Intro Scene stream hash does not match the verified retail payload")
    pixels, width, height, _colors = read_png(arguments.tiles_source, 4)
    palette_pixels, palette_width, palette_height, _palette_colors = read_png(arguments.palette_source, color_count=48)
    expected_width, expected_height = dimensions(3)
    if (palette_width, palette_height) != (expected_width, expected_height) or palette_pixels != bytes(range(expected_width)) * expected_height:
        raise AssertionError("the three-bank palette source is not in its verified swatch layout")

    edited = bytearray(pixels)
    source_index = next(index for index, value in enumerate(edited) if value not in (0, 15))
    edited[source_index] = (edited[source_index] + 1) & 0xF
    native = encode(bytes(edited), width, height, 4)
    original, _format, _ladder = unpack(baseline)
    if native == original:
        raise AssertionError("the selected pixel edit did not alter the native tile payload")
    packed = encode_huff8_lz3(native)
    if len(packed) > STREAM_LENGTH:
        raise AssertionError(f"edited stream needs {len(packed)} bytes but the native slot holds {STREAM_LENGTH}")
    rebuilt, _format, _ladder = unpack(packed + bytes(STREAM_LENGTH - len(packed)))
    if rebuilt != native:
        raise AssertionError("edited stream does not strictly round-trip")
    print(f"intro-background edit test: pixel {source_index} changed; packed {len(packed)} / {STREAM_LENGTH} bytes")


if __name__ == "__main__":
    main()

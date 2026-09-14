#!/usr/bin/env python3
"""Prove one edited farm-status pixel remains encodable in its native slot."""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff8_lz3
from tile_grid import encode, read_png


STREAM_OFFSET_US = 0x5275D0
STREAM_LENGTH = 0x21C4
STREAM_SHA256 = "669dec9d78bbe0d2ceb08383495eea9da863086b00c7dbd4687d90e5c01cddc5"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("source", type=Path)
    arguments = parser.parse_args()

    rom = arguments.rom.read_bytes()
    baseline = rom[STREAM_OFFSET_US:STREAM_OFFSET_US + STREAM_LENGTH]
    if hashlib.sha256(baseline).hexdigest() != STREAM_SHA256:
        raise ValueError("US farm-status stream hash does not match the verified retail payload")

    pixels, width, height, _colors = read_png(arguments.source, 8)
    edited = bytearray(pixels)
    source_index = next(index for index, value in enumerate(edited) if value not in (0, 255))
    edited[source_index] = (edited[source_index] + 1) & 0xFF
    native = encode(bytes(edited), width, height, 8)
    original, _format, _ladder = unpack(baseline)
    if native == original:
        raise AssertionError("the selected pixel edit did not alter the native tile payload")

    packed = encode_huff8_lz3(native)
    if len(packed) > STREAM_LENGTH:
        raise AssertionError(
            f"the edited payload needs {len(packed)} bytes but the native slot holds {STREAM_LENGTH}"
        )
    rebuilt, _format, _ladder = unpack(packed + bytes(STREAM_LENGTH - len(packed)))
    if rebuilt != native:
        raise AssertionError("the edited packed payload failed strict decoder round trip")
    print(
        f"farm-status edit test: pixel {source_index} changed; "
        f"packed {len(packed)} / {STREAM_LENGTH} bytes"
    )


if __name__ == "__main__":
    main()

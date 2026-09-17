#!/usr/bin/env python3
"""Verify that a real winter tile-source edit fits its fixed H8/LZ3 slot."""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import WINTER_MATCH_CANDIDATES, encode_huff8_lz3
from tile_grid import encode, read_png


STREAM_LENGTH = 0x212C
STREAM_SHA256 = "77bfcdfa8918452edf8fa69de854011016f7447fb417468488565aa953a97672"
STREAM_OFFSETS = {
    "jp": 0x4DE1D8,
    "us": 0x75822C,
    "eu": 0x758288,
    "de": 0x4DF748,
}


def stream(rom: bytes, region: str) -> bytes:
    result = rom[STREAM_OFFSETS[region]:STREAM_OFFSETS[region] + STREAM_LENGTH]
    if len(result) != STREAM_LENGTH:
        raise ValueError(f"{region}: winter stream exceeds ROM bounds")
    if hashlib.sha256(result).hexdigest() != STREAM_SHA256:
        raise ValueError(f"{region}: winter stream hash does not match the verified retail payload")
    return result


def main() -> None:
    root = Path(__file__).resolve().parent.parent
    baselines = {
        region: stream((root / f"baserom_{region}.gba").read_bytes(), region)
        for region in STREAM_OFFSETS
    }
    if len(set(baselines.values())) != 1:
        raise AssertionError("winter seasonal stream is not shared across retail regions")
    decoded, format_spec, _ladder = unpack(baselines["us"])
    if (len(decoded), format_spec) != (0x8000, "230"):
        raise AssertionError("unexpected winter H8/LZ3 decode contract")

    source = root / "graphics" / "ui" / "seasonal_background" / "winter" / "winter_tiles.png"
    pixels, width, height, _colors = read_png(source, 4)
    native = encode(pixels, width, height, 4)
    if native != decoded:
        raise AssertionError("winter tile PNG no longer matches the verified retail source")
    edited = bytearray(native)
    index = next(index for index, value in enumerate(edited) if value not in (0, 0xF))
    edited[index] = (edited[index] + 1) & 0xF
    rebuilt = encode_huff8_lz3(bytes(edited), match_candidates=WINTER_MATCH_CANDIDATES)
    if len(rebuilt) > STREAM_LENGTH:
        raise AssertionError("edited winter H8/LZ3 payload does not fit the retail slot")
    check, check_format, _check_ladder = unpack(rebuilt)
    if check != edited or check_format != "230":
        raise AssertionError("edited winter H8/LZ3 payload failed strict native decode validation")
    print(f"seasonal winter H8/LZ3 PNG edit test: byte {index:#x}; "
          f"edited {len(rebuilt):#x} / {STREAM_LENGTH:#x}")


if __name__ == "__main__":
    main()

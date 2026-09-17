#!/usr/bin/env python3
"""Verify the seasonal non-winter H8/LZ2 stream fits its immutable ROM slot."""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

TOOLS = Path(__file__).parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_huff8_lz2
from tile_grid import encode, read_png


STREAM_LENGTH = 0x2298
STREAM_SHA256 = "fbe7362cf81e9965753dee43f108c033e3e0081e8d79207e1f44f39cc98e1f9a"
STREAM_OFFSETS = {
    "jp": 0x4DB7F4,
    "us": 0x755848,
    "eu": 0x7558A4,
    "de": 0x4DCD64,
}
EXPECTED_FORMAT = "220"
EXPECTED_LADDER = "25810111214"


def stream(rom: bytes, region: str) -> bytes:
    result = rom[STREAM_OFFSETS[region]:STREAM_OFFSETS[region] + STREAM_LENGTH]
    if len(result) != STREAM_LENGTH:
        raise ValueError(f"{region}: seasonal stream exceeds ROM bounds")
    if hashlib.sha256(result).hexdigest() != STREAM_SHA256:
        raise ValueError(f"{region}: seasonal stream hash does not match the verified retail payload")
    return result


def verify_round_trip(payload: bytes, baseline: bytes) -> int:
    rebuilt, format_spec, ladder = unpack(payload)
    original, original_format, original_ladder = unpack(baseline)
    if rebuilt != original or format_spec != original_format or ladder != original_ladder:
        raise AssertionError("H8/LZ2 output failed strict native decode validation")
    return len(payload)


def main() -> None:
    root = Path(__file__).resolve().parent.parent
    baselines = {
        region: stream((root / f"baserom_{region}.gba").read_bytes(), region)
        for region in STREAM_OFFSETS
    }
    if len(set(baselines.values())) != 1:
        raise AssertionError("seasonal non-winter stream is not shared across retail regions")
    baseline = baselines["us"]
    decoded, format_spec, ladder = unpack(baseline)
    if (len(decoded), format_spec, ladder) != (0x8000, EXPECTED_FORMAT, EXPECTED_LADDER):
        raise AssertionError("unexpected seasonal non-winter decode contract")

    unchanged = encode_huff8_lz2(decoded, ladder)
    unchanged_length = verify_round_trip(unchanged, baseline)
    if unchanged_length > STREAM_LENGTH:
        raise AssertionError("unchanged H8/LZ2 payload does not fit the retail slot")

    source = root / "graphics" / "ui" / "seasonal_background" / "shared" / "nonwinter_tiles.png"
    pixels, width, height, _colors = read_png(source, 4)
    native = encode(pixels, width, height, 4)
    if native != decoded:
        raise AssertionError("seasonal tile PNG no longer matches the verified retail source")
    edited = bytearray(native)
    index = next(index for index, value in enumerate(edited) if value not in (0, 0xF))
    edited[index] = (edited[index] + 1) & 0xF
    changed = encode_huff8_lz2(bytes(edited), ladder)
    if len(changed) > STREAM_LENGTH:
        raise AssertionError("edited H8/LZ2 payload does not fit the retail slot")
    check, check_format, check_ladder = unpack(changed)
    if check != edited or (check_format, check_ladder) != (EXPECTED_FORMAT, EXPECTED_LADDER):
        raise AssertionError("edited H8/LZ2 payload failed strict native decode validation")
    print(
        f"seasonal non-winter H8/LZ2 PNG edit test: byte {index:#x}; "
        f"unchanged {unchanged_length:#x}, edited {len(changed):#x} / {STREAM_LENGTH:#x}"
    )


if __name__ == "__main__":
    main()

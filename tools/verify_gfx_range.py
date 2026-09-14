#!/usr/bin/env python3
"""Compare a generated graphics payload with one exact ROM byte range."""

from __future__ import annotations

import argparse
import hashlib
from pathlib import Path


def number(value: str) -> int:
    return int(value, 0)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--offset", required=True, type=number)
    parser.add_argument("--input", required=True, type=Path)
    parser.add_argument("--sha256", required=True)
    arguments = parser.parse_args()

    payload = arguments.input.read_bytes()
    actual_sha256 = hashlib.sha256(payload).hexdigest()
    if actual_sha256.lower() != arguments.sha256.lower():
        raise SystemExit(
            f"{arguments.input}: SHA-256 {actual_sha256} does not match declared {arguments.sha256}"
        )
    rom = arguments.rom.read_bytes()
    reference = rom[arguments.offset:arguments.offset + len(payload)]
    if len(reference) != len(payload):
        raise SystemExit(f"{arguments.rom}: range 0x{arguments.offset:X} exceeds the ROM")
    if reference != payload:
        for index, (actual, expected) in enumerate(zip(payload, reference)):
            if actual != expected:
                raise SystemExit(
                    f"{arguments.rom}: differs from {arguments.input} at 0x{arguments.offset + index:X} "
                    f"(generated {actual:02X}, ROM {expected:02X})"
                )
        raise SystemExit(f"{arguments.rom}: generated payload differs from reference range")
    print(f"{arguments.rom}: {arguments.input} is byte-identical at 0x{arguments.offset:X}")


if __name__ == "__main__":
    main()

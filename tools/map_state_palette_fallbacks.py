#!/usr/bin/env python3
"""Build MapData fallback-palette streams from project-owned sources.

Each ``.gbapal`` is an editable sequence of fifteen BGR555 palette banks.
The matching ``.0x70`` stream is generated beside it and is directly included
by the assembly source, just like the ordinary graphics conversions in the
project. No ROM is read or patched by this build tool.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_raw_lz3_greedy  # type: ignore[import-not-found]


DECODED_LENGTH = 0x1E0
FALLBACKS: dict[str, tuple[int, str]] = {
    "fallback_00": (0xA0, "145"),
    "fallback_01": (0x8C, "147"),
    "fallback_02": (0x98, "456"),
    "fallback_03": (0x94, "456"),
    "fallback_04": (0x94, "147"),
}


def read_source(path: Path) -> bytes:
    if path.suffix != ".gbapal":
        raise ValueError(f"{path}: expected a .gbapal source")
    data = path.read_bytes()
    if len(data) != DECODED_LENGTH:
        raise ValueError(
            f"{path}: expected exactly {DECODED_LENGTH:#x} bytes "
            "(fifteen BGR555 palette banks)"
        )
    return data


def profile(path: Path) -> tuple[int, str]:
    try:
        return FALLBACKS[path.stem]
    except KeyError as error:
        known = ", ".join(FALLBACKS)
        raise ValueError(f"{path}: unknown fallback palette (expected one of {known})") from error


def output_path(source: Path) -> Path:
    return source.with_suffix(".0x70")


def encode(source_path: Path) -> bytes:
    source = read_source(source_path)
    capacity, ladder = profile(source_path)
    packed = encode_raw_lz3_greedy(source, ladder)
    if len(packed) > capacity:
        raise ValueError(
            f"{source_path}: encoded stream is {len(packed):#x} bytes; "
            f"the native slot is {capacity:#x} bytes"
        )
    packed += bytes(capacity - len(packed))

    decoded, format_spec, decoded_ladder = unpack(packed)
    if bytes(decoded) != source or (format_spec, decoded_ladder) != ("030", ladder):
        raise AssertionError(f"{source_path}: generated stream failed its native decode contract")
    return packed


def build(arguments: argparse.Namespace) -> None:
    source = arguments.source
    output = arguments.output
    if output != output_path(source):
        raise ValueError(f"{output}: output must be {output_path(source)}")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(encode(source))


def verify(arguments: argparse.Namespace) -> None:
    source = arguments.source
    output = arguments.output
    expected_output = output_path(source)
    if output != expected_output:
        raise ValueError(f"{output}: output must be {expected_output}")
    if output.read_bytes() != encode(source):
        raise ValueError(f"{output}: does not match the current {source}")


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(description=__doc__)
    commands = result.add_subparsers(dest="command", required=True)
    for name in ("build", "verify"):
        command = commands.add_parser(name)
        command.add_argument("--source", type=Path, required=True)
        command.add_argument("--output", type=Path, required=True)
    return result


def main() -> None:
    arguments = parser().parse_args()
    if arguments.command == "build":
        build(arguments)
    else:
        verify(arguments)


if __name__ == "__main__":
    main()

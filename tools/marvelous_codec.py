#!/usr/bin/env python3
"""Encode the verified FoMT ``0x70`` stream variant used by 8bpp screen art.

The ROM's native ``Unpack`` routine at 0x080D102C selects an atom reader, an
LZ mode and an optional differential filter from the byte following the 0x70
header.  This encoder writes the ``0x13`` combination (Huffman-8 atoms,
pair-oriented LZ mode 3, no differential filter).  It is deliberately a
deterministic, valid encoder rather than a claim to reproduce the original
publisher's exact bit stream.  An unchanged asset must retain its original
stream; this encoder is for a deliberately edited payload and callers must
check that the result fits the allocated ROM interval.
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import heapq
import struct
from dataclasses import dataclass
from pathlib import Path


class BitWriter:
    """Native reader-compatible MSB-first bits stored as little-endian words."""

    def __init__(self) -> None:
        self._words: list[int] = []
        self._word = 0
        self._used = 0

    def write(self, value: int, count: int) -> None:
        if count < 0 or value < 0 or value >= (1 << count):
            raise ValueError(f"{value} does not fit in {count} bits")
        while count:
            space = 32 - self._used
            take = min(space, count)
            shift = count - take
            self._word |= ((value >> shift) & ((1 << take) - 1)) << (space - take)
            self._used += take
            count -= take
            if self._used == 32:
                self._words.append(self._word)
                self._word = 0
                self._used = 0

    def finish(self) -> bytes:
        if self._used:
            self._words.append(self._word)
            self._word = 0
            self._used = 0
        return b"".join(struct.pack("<I", word) for word in self._words)


@dataclass(frozen=True)
class HuffmanCode:
    value: int
    bits: int


def huffman_codes(data: bytes) -> tuple[dict[int, HuffmanCode], list[list[int]]]:
    """Build a canonical binary Huffman code compatible with ReadHuff8."""
    frequencies = collections.Counter(data)
    if not frequencies:
        raise ValueError("cannot encode an empty stream")
    if len(frequencies) == 1:
        # The native decoder requires a complete tree, so add a harmless leaf.
        only = next(iter(frequencies))
        frequencies[(only + 1) & 0xFF] = 1

    serial = 0
    heap: list[tuple[int, int, object]] = []
    for symbol, frequency in frequencies.items():
        heap.append((frequency, serial, symbol))
        serial += 1
    heapq.heapify(heap)
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        heapq.heappush(heap, (left[0] + right[0], serial, (left[2], right[2])))
        serial += 1

    lengths: dict[int, int] = {}

    def walk(node: object, depth: int) -> None:
        if isinstance(node, int):
            lengths[node] = depth
            return
        left, right = node  # type: ignore[misc]
        walk(left, depth + 1)
        walk(right, depth + 1)

    walk(heap[0][2], 0)
    if max(lengths.values()) > 16:
        raise ValueError("Huffman tree exceeds the native 16-bit code-depth limit")

    by_length: list[list[int]] = [[] for _ in range(16)]
    for symbol, length in lengths.items():
        by_length[length - 1].append(symbol)
    for symbols in by_length:
        symbols.sort()

    code = 0
    previous_length = 0
    result: dict[int, HuffmanCode] = {}
    for length, symbols in enumerate(by_length, 1):
        code <<= length - previous_length
        for symbol in symbols:
            result[symbol] = HuffmanCode(code, length)
            code += 1
        previous_length = length
    return result, by_length


def emit_huffman_tree(writer: BitWriter, by_length: list[list[int]]) -> None:
    for symbols in by_length:
        writer.write(len(symbols), 8)
        for symbol in symbols:
            writer.write(symbol, 8)


LADDER = ((1, 4), (17, 8), (273, 13))
MAX_LOOKUP_PAIRS = 512


def ladder_entry(distance: int) -> tuple[int, int, int]:
    for index, (start, bits) in enumerate(LADDER):
        if distance < start + (1 << bits):
            return index, start, bits
    raise ValueError(f"LZ distance {distance} exceeds native mode-3 ladder")


def emit_vli(writer: BitWriter, value: int, bits_per_atom: int) -> None:
    """Write the big-endian continuation integer consumed by ``vli``."""
    if value < 0:
        raise ValueError("VLI values must be non-negative")
    digit_bits = bits_per_atom - 1
    digits = [value & ((1 << digit_bits) - 1)]
    value >>= digit_bits
    while value:
        digits.append(value & ((1 << digit_bits) - 1))
        value >>= digit_bits
    for index, digit in enumerate(reversed(digits)):
        writer.write((digit << 1) | int(index + 1 < len(digits)), bits_per_atom)


def match_options(data: bytes, position: int, candidates: list[int]) -> list[tuple[int, int, int]]:
    """Return the longest usable pair match in each native distance ladder."""
    best = [(0, 0) for _ in LADDER]
    maximum = min(MAX_LOOKUP_PAIRS * 2, len(data) - position)
    maximum &= ~1
    # Keep a bounded suffix for practical build times.  The caller preserves
    # the full native distance window, but screen-art rows overwhelmingly find
    # their useful match among the most recent positions.
    for candidate in reversed(candidates[-96:]):
        distance = position - candidate
        if distance > 8464 * 2:
            continue
        length = 0
        while length < maximum and data[candidate + length] == data[position + length]:
            length += 1
        length -= length % 2
        if length >= 4:
            index, _start, _bits = ladder_entry(distance // 2)
            if length > best[index][0]:
                best[index] = (length, distance)
    return [(index, length // 2, distance // 2) for index, (length, distance) in enumerate(best) if length]


def vli_cost(value: int, bits_per_atom: int) -> int:
    digits = 1
    value >>= bits_per_atom - 1
    while value:
        digits += 1
        value >>= bits_per_atom - 1
    return digits * bits_per_atom


def plan_lz3(data: bytes, codes: dict[int, HuffmanCode]) -> list[tuple[str, int, int]]:
    """Choose a minimum-bit sequence of literal pairs and native LZ lookups."""
    pair_count = len(data) // 2
    infinity = 1 << 60
    costs = [infinity] * (pair_count + 1)
    choices: list[tuple[str, int, int] | None] = [None] * (pair_count + 1)
    costs[0] = 0
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)

    for pair_position in range(pair_count):
        position = pair_position * 2
        literal_cost = 1 + codes[data[position]].bits + codes[data[position + 1]].bits
        if costs[pair_position] + literal_cost < costs[pair_position + 1]:
            costs[pair_position + 1] = costs[pair_position] + literal_cost
            choices[pair_position + 1] = ("literal", 1, 0)

        key = data[position:position + 4]
        for index, maximum_pairs, distance in match_options(data, position, candidates.get(key, [])):
            _start, distance_bits = LADDER[index]
            for pairs in range(2, min(9, maximum_pairs) + 1):
                candidate_cost = costs[pair_position] + 1 + 2 + distance_bits + 3
                target = pair_position + pairs
                if candidate_cost < costs[target]:
                    costs[target] = candidate_cost
                    choices[target] = ("lookup", pairs, index << 16 | distance)
            for pairs in range(10, maximum_pairs + 1):
                lookup_count = (pairs - 2) >> 3
                candidate_cost = costs[pair_position] + 1 + 2 + vli_cost(lookup_count, 3) + 1 + 2 + distance_bits + 3
                target = pair_position + pairs
                if candidate_cost < costs[target]:
                    costs[target] = candidate_cost
                    choices[target] = ("lookup", pairs, index << 16 | distance)

        if position + 4 <= len(data):
            values = candidates[key]
            values.append(position)
            while values and values[0] < position - 8464 * 2:
                values.pop(0)

    operations: list[tuple[str, int, int]] = []
    cursor = pair_count
    while cursor:
        choice = choices[cursor]
        if choice is None:
            raise ValueError("LZ planner failed to cover the source stream")
        kind, pairs, argument = choice
        operations.append(choice)
        cursor -= pairs
    operations.reverse()
    return operations


def literal_payload(data: bytes, operations: list[tuple[str, int, int]]) -> bytes:
    """Return the atom stream actually emitted as LZ literals.

    Huffman coding applies only to literals; building its tree from every byte
    in the original payload overweights regions replaced by LZ lookups.  This
    helper permits the encoder to converge on the literal distribution chosen
    by its own parse.
    """
    result = bytearray()
    position = 0
    for kind, pairs, _argument in operations:
        if kind == "literal":
            result.extend(data[position : position + pairs * 2])
        position += pairs * 2
    return bytes(result)


def encode_huff8_lz3(data: bytes) -> bytes:
    """Encode an even-length payload using the retail screen-art format 0x13."""
    if not data or len(data) & 1:
        raise ValueError("mode-3 payloads must be non-empty and an even number of bytes")
    codes, by_length = huffman_codes(data)
    # Rebuild the entropy model from the literals retained by the LZ parse.
    # A handful of iterations is deterministic and normally converges quickly.
    operations: list[tuple[str, int, int]] = []
    for _ in range(8):
        operations = plan_lz3(data, codes)
        next_codes, next_by_length = huffman_codes(literal_payload(data, operations))
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan_lz3(data, codes)
    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(0x13, 8)  # Huffman-8, LZ mode 3, no differential filter.
    emit_huffman_tree(writer, by_length)
    for _start, bits in LADDER:
        writer.write(bits - 1, 4)

    position = 0
    operation_index = 0
    while operation_index < len(operations):
        kind, pairs, argument = operations[operation_index]
        if kind == "literal":
            # Mode 3 has an extended literal form.  The planner models a
            # literal pair independently because that keeps its state local;
            # fold a long consecutive run here when the native VLI form is
            # actually cheaper than one control bit per pair.
            run_pairs = pairs
            following = operation_index + 1
            while following < len(operations) and operations[following][0] == "literal":
                run_pairs += operations[following][1]
                following += 1
            extended_cost = 1 + 2 + vli_cost(run_pairs - 1, 3) + 1
            if extended_cost < run_pairs:
                writer.write(1, 1)
                writer.write(3, 2)
                emit_vli(writer, run_pairs - 1, 3)
                writer.write(0, 1)
                for offset in range(run_pairs * 2):
                    code = codes[data[position + offset]]
                    writer.write(code.value, code.bits)
                position += run_pairs * 2
                operation_index = following
                continue
        if kind == "lookup":
            index, pair_distance = argument >> 16, argument & 0xFFFF
            start, bits = LADDER[index]
            writer.write(1, 1)
            if pairs <= 9:
                writer.write(index, 2)
            else:
                # Extended mode uses idx 3, a base-4 VLI count, then the
                # actual ladder entry and the low three pair-count bits.
                writer.write(3, 2)
                remainder = pairs - 2
                emit_vli(writer, remainder >> 3, 3)
                writer.write(1, 1)
                writer.write(index, 2)
            writer.write(pair_distance - start, bits)
            writer.write((pairs - 2) & 7, 3)
        else:
            writer.write(0, 1)
            writer.write(codes[data[position]].value, codes[data[position]].bits)
            writer.write(codes[data[position + 1]].value, codes[data[position + 1]].bits)
        position += pairs * 2
        operation_index += 1
    return writer.finish()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--baseline-rom", type=Path,
                        help="preserve the retail packed stream when the payload is unchanged")
    parser.add_argument("--baseline-offset", type=lambda value: int(value, 0))
    parser.add_argument("--baseline-length", type=lambda value: int(value, 0))
    parser.add_argument("--baseline-sha256")
    arguments = parser.parse_args()
    source = arguments.input.read_bytes()
    baseline_options = (
        arguments.baseline_rom,
        arguments.baseline_offset,
        arguments.baseline_length,
        arguments.baseline_sha256,
    )
    if any(option is not None for option in baseline_options) and not all(option is not None for option in baseline_options):
        parser.error("--baseline-rom, --baseline-offset, --baseline-length and --baseline-sha256 must be supplied together")

    preserved = False
    if arguments.baseline_rom is not None:
        import sys

        sys.path.insert(0, str(Path(__file__).with_name("scripts")))
        from decompress import unpack  # type: ignore[import-not-found]

        baseline_rom = arguments.baseline_rom.read_bytes()
        start = arguments.baseline_offset
        end = start + arguments.baseline_length
        baseline = baseline_rom[start:end]
        if len(baseline) != arguments.baseline_length:
            raise ValueError("baseline ROM ends before the requested packed interval")
        if hashlib.sha256(baseline).hexdigest().lower() != arguments.baseline_sha256.lower():
            raise ValueError("baseline packed range hash mismatch")
        original_payload, _format, _ladder = unpack(baseline)
        if original_payload == source:
            encoded = baseline
            preserved = True
        else:
            encoded = encode_huff8_lz3(source)
            if len(encoded) > len(baseline):
                raise ValueError(
                    f"edited packed stream is {len(encoded)} bytes but the native interval holds only {len(baseline)} bytes"
                )
            encoded += bytes(len(baseline) - len(encoded))
            checked_payload, _format, _ladder = unpack(encoded)
            if checked_payload != source:
                raise ValueError("encoded stream did not round-trip through the strict unpacker")
    else:
        encoded = encode_huff8_lz3(source)
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_bytes(encoded)
    action = "preserved original" if preserved else "encoded"
    print(f"{action} {arguments.input} ({arguments.input.stat().st_size} bytes) to {arguments.output} ({len(encoded)} bytes)")


if __name__ == "__main__":
    main()

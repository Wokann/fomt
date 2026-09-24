#!/usr/bin/env python3
"""Encode verified FoMT ``0x70`` stream variants for editable graphics.

The ROM's native ``Unpack`` routine at 0x080D102C selects an atom reader, an
LZ mode and an optional differential filter from the byte following the 0x70
header. The managed formats include the Raw, Huffman-4 and Huffman-8 modes
used by audited resource families, with their original LZ ladders and optional
differential filters. This is a deliberately deterministic, valid encoder
rather than a claim to reproduce the original publisher's exact bit stream.
An unchanged asset must retain its original stream; these encoders are for
deliberately edited payloads, and callers must check that a result fits the
allocated ROM interval.
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import heapq
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Callable


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


def inverse_differential(data: bytes, filter_id: int) -> bytes:
    """Invert the decoder's optional differential filter.

    ``decompress.py`` applies the filter after the LZ stream has been decoded.
    An encoder must therefore transform an authored payload back to the atom
    stream first, while retaining the same filter ID in the Popuri header.
    The filters operate on nibbles, bytes, little-endian words, or independent
    even/odd byte lanes respectively.  They are deliberately kept here rather
    than duplicated by every resource-family builder.
    """
    if filter_id == 0:
        return bytes(data)
    if not 1 <= filter_id <= 4:
        raise ValueError(f"unsupported differential filter {filter_id}")

    result = bytearray(data)
    if filter_id == 1:
        accumulator = 0
        for index, value in enumerate(data):
            high = value >> 4
            low = value & 0x0F
            result[index] = ((high - accumulator) & 0x0F) << 4 | ((low - high) & 0x0F)
            accumulator = low
        return bytes(result)

    if filter_id == 2:
        accumulator = 0
        for index, value in enumerate(data):
            result[index] = (value - accumulator) & 0xFF
            accumulator = value
        return bytes(result)

    if len(data) & 1:
        raise ValueError(f"differential filter {filter_id} requires an even-length payload")
    if filter_id == 3:
        accumulator = 0
        for index in range(0, len(data), 2):
            value = data[index] | (data[index + 1] << 8)
            raw = (value - accumulator) & 0xFFFF
            result[index] = raw & 0xFF
            result[index + 1] = raw >> 8
            accumulator = value
        return bytes(result)

    even_accumulator = 0
    odd_accumulator = 0
    for index in range(0, len(data), 2):
        even = data[index]
        odd = data[index + 1]
        result[index] = (even - even_accumulator) & 0xFF
        result[index + 1] = (odd - odd_accumulator) & 0xFF
        even_accumulator = even
        odd_accumulator = odd
    return bytes(result)


@dataclass(frozen=True)
class HuffmanCode:
    value: int
    bits: int


def huffman_codes(data: bytes, symbol_bits: int = 8) -> tuple[dict[int, HuffmanCode], list[list[int]]]:
    """Build a canonical binary Huffman code compatible with ReadHuff8."""
    frequencies = collections.Counter(data)
    if not frequencies:
        raise ValueError("cannot encode an empty stream")
    if len(frequencies) == 1:
        # The native decoder requires a complete tree, so add a harmless leaf.
        only = next(iter(frequencies))
        frequencies[(only + 1) & ((1 << symbol_bits) - 1)] = 1

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
    if max(lengths.values()) > symbol_bits * 2:
        return balanced_huffman_codes(frequencies, symbol_bits)

    by_length: list[list[int]] = [[] for _ in range(symbol_bits * 2)]
    for symbol, length in lengths.items():
        by_length[length - 1].append(symbol)
    for symbols in by_length:
        symbols.sort()

    # The native format stores the count at each depth in one atom.  A
    # perfectly balanced 16-symbol Huffman-4 tree would require a count of
    # 16, which cannot be represented in a four-bit count field.  Fall back
    # to a complete, near-balanced tree whose per-depth counts are encodable.
    if any(len(symbols) >= (1 << symbol_bits) for symbols in by_length):
        return balanced_huffman_codes(frequencies, symbol_bits)

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


def balanced_huffman_codes(
    frequencies: collections.Counter[int], symbol_bits: int,
) -> tuple[dict[int, HuffmanCode], list[list[int]]]:
    """Build a bounded complete tree when raw Huffman lengths are unencodable."""
    symbols = sorted(frequencies, key=lambda symbol: (-frequencies[symbol], symbol))
    count = len(symbols)
    if count < 2:
        raise ValueError("Huffman tree needs at least two leaves")
    if count > (1 << symbol_bits):
        raise ValueError("Huffman alphabet exceeds atom size")

    if count == 1 << symbol_bits:
        # 1×3-bit, 13×4-bit and 2×5-bit leaves are a complete 16-leaf tree
        # while every depth count fits in the format's four-bit field.
        lengths = [symbol_bits - 1, *([symbol_bits] * (count - 3)), symbol_bits + 1, symbol_bits + 1]
    else:
        shallow = count.bit_length() - 1
        shallow_count = (1 << (shallow + 1)) - count
        lengths = [shallow] * shallow_count + [shallow + 1] * (count - shallow_count)

    by_length: list[list[int]] = [[] for _ in range(symbol_bits * 2)]
    for symbol, length in zip(symbols, lengths, strict=True):
        by_length[length - 1].append(symbol)
    for values in by_length:
        values.sort()

    code = 0
    previous_length = 0
    result: dict[int, HuffmanCode] = {}
    for length, values in enumerate(by_length, 1):
        code <<= length - previous_length
        for symbol in values:
            result[symbol] = HuffmanCode(code, length)
            code += 1
        previous_length = length
    return result, by_length


def emit_huffman_tree(writer: BitWriter, by_length: list[list[int]], symbol_bits: int = 8) -> None:
    for symbols in by_length:
        writer.write(len(symbols), symbol_bits)
        for symbol in symbols:
            writer.write(symbol, symbol_bits)


LADDER = ((1, 4), (17, 8), (273, 13))
# The historic 96-candidate budget remains the generic encoder default.  The
# winter seasonal tile stream opts in to 512 candidates because it needs that
# deterministic search depth to fit its immutable 0x212C-byte slot.  Native
# distance validation remains independent of this search cap.
DEFAULT_MATCH_CANDIDATES = 96
WINTER_MATCH_CANDIDATES = 512


def ladder_entry(distance: int, entries: tuple[tuple[int, int], ...] | list[tuple[int, int]] = LADDER) -> tuple[int, int, int]:
    for index, (start, bits) in enumerate(entries):
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


def match_options(
    data: bytes,
    position: int,
    candidates: list[int],
    entries: tuple[tuple[int, int], ...] | list[tuple[int, int]] = LADDER,
    candidate_limit: int = DEFAULT_MATCH_CANDIDATES,
) -> list[tuple[int, int, int]]:
    """Return the longest usable pair match in each native distance ladder."""
    best = [(0, 0) for _ in entries]
    # Mode-3 encodes the match length as a VLI, so the source remainder is
    # the only meaningful length bound here.  In particular, do not impose a
    # short implementation cap on legal long runs in tile data.
    maximum = len(data) - position
    maximum &= ~1
    # Keep a bounded suffix for practical build times.  The caller preserves
    # the full native distance window, but screen-art rows overwhelmingly find
    # their useful match among the most recent positions.
    for candidate in reversed(candidates[-candidate_limit:]):
        distance = position - candidate
        maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
        if distance > maximum_distance * 2:
            continue
        # Compare byte ranges in C rather than advancing one Python byte at a
        # time. Equality is monotonic with prefix length, so binary search
        # produces the same longest common prefix as the former loop.
        low = 0
        high = maximum
        while low < high:
            probe = (low + high + 1) // 2
            if data[candidate:candidate + probe] == data[position:position + probe]:
                low = probe
            else:
                high = probe - 1
        length = low
        length -= length % 2
        if length >= 4:
            index, _start, _bits = ladder_entry(distance // 2, entries)
            if length > best[index][0]:
                best[index] = (length, distance)
    return [(index, length // 2, distance // 2) for index, (length, distance) in enumerate(best) if length]


def precompute_lz3_matches(
    data: bytes,
    entries: tuple[tuple[int, int], ...] | list[tuple[int, int]] = LADDER,
    candidate_limit: int = DEFAULT_MATCH_CANDIDATES,
) -> list[list[tuple[int, int, int]]]:
    """Cache source-only LZ3 options for repeated Huffman parse iterations.

    The Huffman model changes literal costs but cannot change which native LZ
    lookups are legal.  Building this deterministic table once removes the
    repeated byte-comparison pass from every entropy-model iteration.
    """
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)
    result: list[list[tuple[int, int, int]]] = []
    maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
    for pair_position in range(len(data) // 2):
        position = pair_position * 2
        key = data[position:position + 4]
        result.append(match_options(data, position, candidates.get(key, []), entries, candidate_limit))
        if position + 4 <= len(data):
            values = candidates[key]
            values.append(position)
            while values and values[0] < position - maximum_distance * 2:
                values.pop(0)
    return result


def vli_cost(value: int, bits_per_atom: int) -> int:
    digits = 1
    value >>= bits_per_atom - 1
    while value:
        digits += 1
        value >>= bits_per_atom - 1
    return digits * bits_per_atom


def plan_lz3(
    data: bytes,
    literal_bits: Callable[[int, int], int],
    entries: tuple[tuple[int, int], ...] | list[tuple[int, int]] = LADDER,
    precomputed_matches: list[list[tuple[int, int, int]]] | None = None,
) -> list[tuple[str, int, int]]:
    """Choose a minimum-bit sequence of literal pairs and native LZ lookups.

    A mode-3 lookup can name a long VLI length.  Its bit cost is constant
    across each VLI digit-width interval, so enumerating every length was an
    accidental quadratic implementation limit (and was the reason lookup
    matches were formerly capped at 512 pairs).  Keep each equal-cost interval
    as a deferred range relaxation instead.  At a target pair position the
    cheapest active interval supplies the precise source and length, giving
    the same dynamic-programming domain without a synthetic native limit.
    """
    pair_count = len(data) // 2
    infinity = 1 << 60
    costs = [infinity] * (pair_count + 1)
    choices: list[tuple[str, int, int] | None] = [None] * (pair_count + 1)
    costs[0] = 0
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)

    # ``pending[start]`` contains inclusive target-pair intervals.  Heap
    # records are ``(cost, source, argument, end)`` so ties remain fully
    # deterministic without comparing an implementation-defined object.
    pending: list[list[tuple[int, int, int, int]]] = [[] for _ in range(pair_count + 1)]
    active: list[tuple[int, int, int, int]] = []

    def relax_range(
        source: int,
        start: int,
        end: int,
        cost: int,
        argument: int,
    ) -> None:
        """Schedule an equal-cost lookup interval within the DP domain."""
        start = max(start, source + 2)
        end = min(end, pair_count)
        if start > end:
            return
        pending[start].append((cost, source, argument, end))

    for pair_position in range(pair_count):
        for record in pending[pair_position]:
            heapq.heappush(active, record)
        while active and active[0][3] < pair_position:
            heapq.heappop(active)
        if active and active[0][0] < costs[pair_position]:
            cost, source, argument, _end = active[0]
            costs[pair_position] = cost
            choices[pair_position] = ("lookup", pair_position - source, argument)

        if costs[pair_position] == infinity:
            raise ValueError("LZ planner reached an uncovered pair position")
        position = pair_position * 2
        literal_cost = 1 + literal_bits(data[position], data[position + 1])
        if costs[pair_position] + literal_cost < costs[pair_position + 1]:
            costs[pair_position + 1] = costs[pair_position] + literal_cost
            choices[pair_position + 1] = ("literal", 1, 0)

        key = data[position:position + 4]
        options = (
            match_options(data, position, candidates.get(key, []), entries)
            if precomputed_matches is None else precomputed_matches[pair_position]
        )
        for index, maximum_pairs, distance in options:
            _start, distance_bits = entries[index]
            argument = index << 16 | distance
            # Short form: pairs 2 through 9 all share one fixed cost.
            relax_range(
                pair_position,
                pair_position + 2,
                pair_position + min(9, maximum_pairs),
                costs[pair_position] + 1 + 2 + distance_bits + 3,
                argument,
            )
            # Extended form: ``lookup_count`` is VLI-encoded in base four.
            # Each VLI digit width covers a contiguous, equal-cost run of
            # pair counts.  Schedule precisely those runs rather than every
            # individual length.
            maximum_pairs = min(maximum_pairs, pair_count - pair_position)
            minimum_pairs = 10
            digits = 1
            while minimum_pairs <= maximum_pairs:
                minimum_count = 1 if digits == 1 else 1 << (2 * (digits - 1))
                maximum_count = (1 << (2 * digits)) - 1
                start_pairs = max(minimum_pairs, minimum_count * 8 + 2)
                end_pairs = min(maximum_pairs, maximum_count * 8 + 9)
                if start_pairs <= end_pairs:
                    relaxed_cost = (
                        costs[pair_position] + 1 + 2 + digits * 3 + 1 + 2 + distance_bits + 3
                    )
                    relax_range(
                        pair_position,
                        pair_position + start_pairs,
                        pair_position + end_pairs,
                        relaxed_cost,
                        argument,
                    )
                minimum_pairs = maximum_count * 8 + 10
                digits += 1

        if precomputed_matches is None and position + 4 <= len(data):
            values = candidates[key]
            values.append(position)
            maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
            while values and values[0] < position - maximum_distance * 2:
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


def huff4_symbols(data: bytes) -> bytes:
    """Expand bytes to the high/low four-bit atoms read by ``ReadHuff4``."""
    return bytes(component for value in data for component in (value >> 4, value & 0x0F))


def write_huff4_byte(writer: BitWriter, value: int, codes: dict[int, HuffmanCode]) -> None:
    high = codes[value >> 4]
    low = codes[value & 0x0F]
    writer.write(high.value, high.bits)
    writer.write(low.value, low.bits)


def encode_huff8_lz3(
    data: bytes,
    *,
    ladder_spec: str | None = None,
    differential_filter: int = 0,
    match_candidates: int = DEFAULT_MATCH_CANDIDATES,
) -> bytes:
    """Encode an even-length Huffman-8/LZ3 payload with its native ladder.

    ``match_candidates`` controls only deterministic encoder search effort;
    it never changes the native mode-3 distance domain.  Resource pipelines
    opt into a larger value only after demonstrating a fixed-slot benefit.
    """
    data = bytes(data)
    if not data or len(data) & 1:
        raise ValueError("mode-3 payloads must be non-empty and an even number of bytes")
    if match_candidates <= 0:
        raise ValueError("match_candidates must be positive")
    if not 0 <= differential_filter <= 4:
        raise ValueError("Huffman-8 LZ3 differential filter must be in 0..4")
    entries = LADDER if ladder_spec is None else ladder_entries(ladder_spec, 3)
    matches = precompute_lz3_matches(data, entries, candidate_limit=match_candidates)
    codes, by_length = huffman_codes(data)
    # Rebuild the entropy model from the literals retained by the LZ parse.
    # A handful of iterations is deterministic and normally converges quickly.
    operations: list[tuple[str, int, int]] = []
    for _ in range(8):
        operations = plan_lz3(
            data, lambda first, second: codes[first].bits + codes[second].bits,
            entries,
            precomputed_matches=matches,
        )
        next_codes, next_by_length = huffman_codes(literal_payload(data, operations))
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan_lz3(
            data, lambda first, second: codes[first].bits + codes[second].bits,
            entries,
            precomputed_matches=matches,
        )
    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(0x13 | (differential_filter << 5), 8)
    emit_huffman_tree(writer, by_length)
    emit_ladder(writer, entries)

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
            start, bits = entries[index]
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


def lz2_match_options(
    data: bytes,
    position: int,
    candidates: list[int],
    entries: list[tuple[int, int]],
) -> list[tuple[int, int, int]]:
    """Return the longest byte match in each LZ2 distance ladder entry."""
    best = [(0, 0) for _ in entries]
    maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
    maximum_length = min(0x400, len(data) - position)
    # The recent suffix is deterministic and keeps the authored-image build
    # practical. Each ladder still receives its best usable candidate.
    for candidate in reversed(candidates[-48:]):
        distance = position - candidate
        if distance > maximum_distance:
            continue
        # ``bytes`` equality is implemented in C.  Find the maximal common
        # prefix with a binary search instead of comparing up to 0x400 Python
        # byte pairs for every candidate and every Huffman-model iteration.
        # Prefix equality is monotonic, so this is exactly equivalent to the
        # previous byte-by-byte loop while keeping large visual-tile rebuilds
        # practical.
        lower, upper = 0, maximum_length
        while lower < upper:
            middle = (lower + upper + 1) // 2
            if data[candidate:candidate + middle] == data[position:position + middle]:
                lower = middle
            else:
                upper = middle - 1
        length = lower
        if length < 3:
            continue
        index, _start, _bits = ladder_entry(distance, entries)
        if length > best[index][0]:
            best[index] = (length, distance)
    return [(index, length, distance) for index, (length, distance) in enumerate(best) if length]


def plan_lz2(
    data: bytes,
    literal_bits: Callable[[int], int],
    entries: list[tuple[int, int]],
) -> list[tuple[str, int, int]]:
    """Choose a minimum-bit byte parse for the native LZ2 grammar."""
    infinity = 1 << 60
    costs = [infinity] * (len(data) + 1)
    choices: list[tuple[str, int, int] | None] = [None] * (len(data) + 1)
    costs[0] = 0
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)

    for position in range(len(data)):
        if costs[position] == infinity:
            continue
        literal_cost = costs[position] + 1 + literal_bits(data[position])
        if literal_cost < costs[position + 1]:
            costs[position + 1] = literal_cost
            choices[position + 1] = ("literal", 1, 0)

        key = data[position:position + 3]
        for index, maximum, distance in lz2_match_options(data, position, candidates.get(key, []), entries):
            _start, distance_bits = entries[index]
            for length in range(3, min(maximum, 18) + 1):
                target = position + length
                candidate_cost = costs[position] + 1 + 3 + distance_bits + 4
                if candidate_cost < costs[target]:
                    costs[target] = candidate_cost
                    choices[target] = ("lookup", length, index << 16 | distance)
            # LZ2's extended length cost changes only every sixteen bytes.
            # Keep every value in the first bucket, then each later bucket's
            # endpoint plus the exact maximum. This avoids quadratic planning
            # on large repeated tile regions without changing the decoder
            # grammar or the original distance domain.
            long_lengths = list(range(19, min(maximum, 34) + 1))
            long_lengths.extend(range(50, maximum + 1, 16))
            if maximum >= 19 and (not long_lengths or long_lengths[-1] != maximum):
                long_lengths.append(maximum)
            for length in long_lengths:
                target = position + length
                lookup_count = (length - 3) >> 4
                candidate_cost = costs[position] + 1 + 3 + vli_cost(lookup_count, 4) + 1 + 3 + distance_bits + 4
                if candidate_cost < costs[target]:
                    costs[target] = candidate_cost
                    choices[target] = ("lookup", length, index << 16 | distance)

        if position + 3 <= len(data):
            values = candidates[key]
            values.append(position)
            maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
            while values and values[0] < position - maximum_distance:
                values.pop(0)

    operations: list[tuple[str, int, int]] = []
    cursor = len(data)
    while cursor:
        choice = choices[cursor]
        if choice is None:
            raise ValueError("LZ2 planner failed to cover the source stream")
        operations.append(choice)
        cursor -= choice[1]
    operations.reverse()
    return operations


def literal_payload_lz2(data: bytes, operations: list[tuple[str, int, int]]) -> bytes:
    """Return only literal atoms selected by a byte-oriented LZ2 parse."""
    result = bytearray()
    position = 0
    for kind, length, _argument in operations:
        if kind == "literal":
            result.extend(data[position:position + length])
        position += length
    return bytes(result)


def encode_huff8_lz2(data: bytes, ladder_spec: str, *, differential_filter: int = 0) -> bytes:
    """Encode a Huffman-8/LZ2 stream using its original seven-entry ladder."""
    data = bytes(data)
    if not data:
        raise ValueError("Huffman-8/LZ2 payloads must be non-empty")
    if not 0 <= differential_filter <= 4:
        raise ValueError("Huffman-8 LZ2 differential filter must be in 0..4")
    entries = ladder_entries(ladder_spec, 7)
    codes, by_length = huffman_codes(data)
    operations: list[tuple[str, int, int]] = []
    for _ in range(8):
        operations = plan_lz2(data, lambda value: codes[value].bits, entries)
        next_codes, next_by_length = huffman_codes(literal_payload_lz2(data, operations))
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan_lz2(data, lambda value: codes[value].bits, entries)

    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(0x12 | (differential_filter << 5), 8)
    emit_huffman_tree(writer, by_length)
    emit_ladder(writer, entries)

    position = 0
    operation_index = 0
    while operation_index < len(operations):
        kind, length, argument = operations[operation_index]
        if kind == "literal":
            run_length = length
            following = operation_index + 1
            while following < len(operations) and operations[following][0] == "literal":
                run_length += operations[following][1]
                following += 1
            extended_cost = 1 + 3 + vli_cost(run_length - 1, 4) + 1
            if extended_cost < run_length:
                writer.write(1, 1)
                writer.write(7, 3)
                emit_vli(writer, run_length - 1, 4)
                writer.write(0, 1)
                for offset in range(run_length):
                    code = codes[data[position + offset]]
                    writer.write(code.value, code.bits)
                position += run_length
                operation_index = following
                continue
        if kind == "lookup":
            index, distance = argument >> 16, argument & 0xFFFF
            start, bits = entries[index]
            writer.write(1, 1)
            if length <= 18:
                writer.write(index, 3)
            else:
                writer.write(7, 3)
                emit_vli(writer, (length - 3) >> 4, 4)
                writer.write(1, 1)
                writer.write(index, 3)
            writer.write(distance - start, bits)
            writer.write((length - 3) & 15, 4)
        else:
            writer.write(0, 1)
            code = codes[data[position]]
            writer.write(code.value, code.bits)
        position += length
        operation_index += 1
    return writer.finish()


def encode_huff4_lz2(data: bytes, ladder_spec: str, *, differential_filter: int = 0) -> bytes:
    """Encode a Huffman-4/LZ2 stream using its original seven-entry ladder.

    H4/LZ2 is used by the JP-localized indexed scene archive.  It shares the
    byte-oriented LZ2 grammar with :func:`encode_huff8_lz2`; only literal
    atoms differ, because every source byte is represented by two four-bit
    Huffman symbols.  Callers retain the original stream when no source has
    changed and still enforce the immutable packed-slot size after an edit.
    ``differential_filter`` is the native header field (0-4); callers supply
    already inverse-filtered atoms when it is nonzero.
    """
    data = bytes(data)
    if not data:
        raise ValueError("Huffman-4/LZ2 payloads must be non-empty")
    entries = ladder_entries(ladder_spec, 7)
    codes, by_length = huffman_codes(huff4_symbols(data), 4)
    operations: list[tuple[str, int, int]] = []
    for _ in range(8):
        operations = plan_lz2(
            data,
            lambda value: codes[value >> 4].bits + codes[value & 0x0F].bits,
            entries,
        )
        next_codes, next_by_length = huffman_codes(
            huff4_symbols(literal_payload_lz2(data, operations)), 4,
        )
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan_lz2(
            data,
            lambda value: codes[value >> 4].bits + codes[value & 0x0F].bits,
            entries,
        )

    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    if not 0 <= differential_filter <= 4:
        raise ValueError("Huffman-4/LZ2 differential filter must be in 0..4")
    writer.write(0x0A | (differential_filter << 5), 8)  # H4 atoms, LZ2.
    emit_huffman_tree(writer, by_length, 4)
    emit_ladder(writer, entries)

    position = 0
    operation_index = 0
    while operation_index < len(operations):
        kind, length, argument = operations[operation_index]
        if kind == "literal":
            run_length = length
            following = operation_index + 1
            while following < len(operations) and operations[following][0] == "literal":
                run_length += operations[following][1]
                following += 1
            extended_cost = 1 + 3 + vli_cost(run_length - 1, 4) + 1
            if extended_cost < run_length:
                writer.write(1, 1)
                writer.write(7, 3)
                emit_vli(writer, run_length - 1, 4)
                writer.write(0, 1)
                for offset in range(run_length):
                    write_huff4_byte(writer, data[position + offset], codes)
                position += run_length
                operation_index = following
                continue
        if kind == "lookup":
            index, distance = argument >> 16, argument & 0xFFFF
            start, bits = entries[index]
            writer.write(1, 1)
            if length <= 18:
                writer.write(index, 3)
            else:
                writer.write(7, 3)
                emit_vli(writer, (length - 3) >> 4, 4)
                writer.write(1, 1)
                writer.write(index, 3)
            writer.write(distance - start, bits)
            writer.write((length - 3) & 15, 4)
        else:
            writer.write(0, 1)
            write_huff4_byte(writer, data[position], codes)
        position += length
        operation_index += 1
    return writer.finish()


def encode_huff4_lz3(
    data: bytes, ladder_spec: str, *, differential_filter: int = 0,
) -> bytes:
    """Encode a Huffman-4 / LZ3 stream used by Intro Scene tilemaps.

    The original packed bytes are retained whenever a source is unchanged.
    This routine is only used after an intentional edit, and callers still
    enforce the immutable ROM-slot length before accepting its result.
    """
    data = bytes(data)
    if not data or len(data) & 1:
        raise ValueError("Huffman-4 LZ3 payloads must be non-empty and even-sized")
    if not 0 <= differential_filter <= 4:
        raise ValueError("Huffman-4 LZ3 differential filter must be in 0..4")
    entries = ladder_entries(ladder_spec, 3)
    codes, by_length = huffman_codes(huff4_symbols(data), 4)
    operations: list[tuple[str, int, int]] = []
    for _ in range(8):
        operations = plan_lz3(
            data,
            lambda first, second: (
                codes[first >> 4].bits + codes[first & 0x0F].bits
                + codes[second >> 4].bits + codes[second & 0x0F].bits
            ),
            entries,
        )
        next_codes, next_by_length = huffman_codes(huff4_symbols(literal_payload(data, operations)), 4)
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan_lz3(
            data,
            lambda first, second: (
                codes[first >> 4].bits + codes[first & 0x0F].bits
                + codes[second >> 4].bits + codes[second & 0x0F].bits
            ),
            entries,
        )

    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(0x0B | (differential_filter << 5), 8)
    emit_huffman_tree(writer, by_length, 4)
    emit_ladder(writer, entries)

    position = 0
    operation_index = 0
    while operation_index < len(operations):
        kind, pairs, argument = operations[operation_index]
        if kind == "literal":
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
                    write_huff4_byte(writer, data[position + offset], codes)
                position += run_pairs * 2
                operation_index = following
                continue
        if kind == "lookup":
            index, pair_distance = argument >> 16, argument & 0xFFFF
            start, bits = entries[index]
            writer.write(1, 1)
            if pairs <= 9:
                writer.write(index, 2)
            else:
                writer.write(3, 2)
                emit_vli(writer, (pairs - 2) >> 3, 3)
                writer.write(1, 1)
                writer.write(index, 2)
            writer.write(pair_distance - start, bits)
            writer.write((pairs - 2) & 7, 3)
        else:
            writer.write(0, 1)
            write_huff4_byte(writer, data[position], codes)
            write_huff4_byte(writer, data[position + 1], codes)
        position += pairs * 2
        operation_index += 1
    return writer.finish()


def encode_huff4_lz0(data: bytes, ladder_spec: str) -> bytes:
    """Encode a Huffman-4/LZ0 stream using a bounded minimum-bit parse."""
    data = bytes(data)
    if not data or len(data) > 0x40000:
        raise ValueError("Huffman-4/LZ0 payload must contain 1 through 0x40000 bytes")
    entries = ladder_entries(ladder_spec, 2)
    maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1

    def plan(codes: dict[int, HuffmanCode]) -> list[tuple[str, int, int | tuple[int, int] | None]]:
        infinity = 1 << 60
        costs = [infinity] * (len(data) + 1)
        choices: list[tuple[str, int, int | tuple[int, int] | None] | None] = [None] * (len(data) + 1)
        costs[0] = 0
        candidates: dict[bytes, list[int]] = collections.defaultdict(list)
        for position in range(len(data)):
            if costs[position] == infinity:
                continue
            literal_bits = 0
            for length in range(1, min(64, len(data) - position) + 1):
                value = data[position + length - 1]
                literal_bits += codes[value >> 4].bits + codes[value & 0x0F].bits
                target = position + length
                if costs[position] + 8 + literal_bits < costs[target]:
                    costs[target] = costs[position] + 8 + literal_bits
                    choices[target] = ("literal", length, None)
            run_length = 1
            while run_length < 66 and position + run_length < len(data) and data[position + run_length] == data[position]:
                run_length += 1
            for length in range(2, run_length + 1):
                target = position + length
                if costs[position] + 16 < costs[target]:
                    costs[target] = costs[position] + 16
                    choices[target] = ("run", length, data[position])
            key = data[position:position + 3]
            best = [(0, 0) for _ in entries]
            for candidate in reversed(candidates[key]):
                distance = position - candidate
                if distance > maximum_distance:
                    continue
                length = 0
                while length < 66 and position + length < len(data) and data[candidate + length] == data[position + length]:
                    length += 1
                if length >= 3:
                    index, _start, _width = ladder_entry(distance, entries)
                    if length > best[index][0]:
                        best[index] = (length, distance)
            for index, (maximum, distance) in enumerate(best):
                for length in range(3, maximum + 1):
                    target = position + length
                    cost = costs[position] + 2 + entries[index][1] + 6
                    if cost < costs[target]:
                        costs[target] = cost
                        choices[target] = ("lookup", length, (index, distance))
            if position + 3 <= len(data):
                candidates[key].append(position)
        result = []
        cursor = len(data)
        while cursor:
            choice = choices[cursor]
            if choice is None:
                raise ValueError("Huffman-4/LZ0 planner did not cover the source")
            result.append(choice)
            cursor -= choice[1]
        result.reverse()
        return result

    def literal_payload(operations: list[tuple[str, int, int | tuple[int, int] | None]]) -> bytes:
        position, result = 0, bytearray()
        for kind, length, _argument in operations:
            if kind == "literal":
                result.extend(data[position:position + length])
            position += length
        return bytes(result)

    codes, by_length = huffman_codes(huff4_symbols(data), 4)
    for _ in range(8):
        operations = plan(codes)
        next_codes, next_by_length = huffman_codes(huff4_symbols(literal_payload(operations)), 4)
        if next_codes == codes:
            break
        codes, by_length = next_codes, next_by_length
    else:
        operations = plan(codes)
    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(0x08, 8)
    emit_huffman_tree(writer, by_length, 4)
    emit_ladder(writer, entries)
    position = 0
    for kind, length, argument in operations:
        if kind == "literal":
            writer.write(2, 2)
            writer.write(length - 1, 6)
            for value in data[position:position + length]:
                write_huff4_byte(writer, value, codes)
        elif kind == "run":
            writer.write(3, 2)
            writer.write(length - 2, 6)
            assert isinstance(argument, int)
            writer.write(argument, 8)
        else:
            assert isinstance(argument, tuple)
            index, distance = argument
            start, width = entries[index]
            writer.write(index, 2)
            writer.write(distance - start, width)
            writer.write(length - 3, 6)
        position += length
    return writer.finish()


def encode_raw_lz0(data: bytes, ladder_spec: str, *, differential_filter: int = 0) -> bytes:
    """Encode a Raw-atom LZ0 stream with literal, run and lookup packets."""
    data = bytes(data)
    if not data or len(data) > 0x40000:
        raise ValueError("Raw-LZ0 payload must contain 1 through 0x40000 bytes")
    if not 0 <= differential_filter <= 4:
        raise ValueError("Raw-LZ0 differential filter must be in 0..4")
    entries = ladder_entries(ladder_spec, 2)
    maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
    infinity = 1 << 60
    costs = [infinity] * (len(data) + 1)
    choices: list[tuple[str, int, int | tuple[int, int] | None] | None] = [None] * (len(data) + 1)
    costs[0] = 0
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)
    for position in range(len(data)):
        if costs[position] == infinity:
            continue
        for length in range(1, min(64, len(data) - position) + 1):
            target = position + length
            if costs[position] + 8 + length * 8 < costs[target]:
                costs[target] = costs[position] + 8 + length * 8
                choices[target] = ("literal", length, None)
        run_length = 1
        while run_length < 66 and position + run_length < len(data) and data[position + run_length] == data[position]:
            run_length += 1
        for length in range(2, run_length + 1):
            target = position + length
            if costs[position] + 16 < costs[target]:
                costs[target] = costs[position] + 16
                choices[target] = ("run", length, data[position])
        key = data[position:position + 3]
        best = [(0, 0) for _ in entries]
        for candidate in reversed(candidates[key]):
            distance = position - candidate
            if distance > maximum_distance:
                continue
            length = 0
            while length < 66 and position + length < len(data) and data[candidate + length] == data[position + length]:
                length += 1
            if length >= 3:
                index, _start, _width = ladder_entry(distance, entries)
                if length > best[index][0]:
                    best[index] = (length, distance)
        for index, (maximum, distance) in enumerate(best):
            for length in range(3, maximum + 1):
                target = position + length
                cost = costs[position] + 2 + entries[index][1] + 6
                if cost < costs[target]:
                    costs[target] = cost
                    choices[target] = ("lookup", length, (index, distance))
        if position + 3 <= len(data):
            candidates[key].append(position)
    operations: list[tuple[str, int, int | tuple[int, int] | None]] = []
    cursor = len(data)
    while cursor:
        choice = choices[cursor]
        if choice is None:
            raise ValueError("Raw-LZ0 planner did not cover the payload")
        operations.append(choice)
        cursor -= choice[1]
    operations.reverse()
    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(differential_filter << 5, 8)
    emit_ladder(writer, entries)
    position = 0
    for kind, length, argument in operations:
        if kind == "literal":
            writer.write(2, 2)
            writer.write(length - 1, 6)
            for value in data[position:position + length]:
                writer.write(value, 8)
        elif kind == "run":
            writer.write(3, 2)
            writer.write(length - 2, 6)
            assert isinstance(argument, int)
            writer.write(argument, 8)
        else:
            assert isinstance(argument, tuple)
            index, distance = argument
            start, width = entries[index]
            writer.write(index, 2)
            writer.write(distance - start, width)
            writer.write(length - 3, 6)
        position += length
    return writer.finish()


def ladder_entries(spec: str | tuple[int, ...] | list[int], expected_entries: int) -> list[tuple[int, int]]:
    """Decode the native distance-ladder declaration used by Raw LZ modes.

    ``Unpack`` stores each entry as a four-bit ``width - 1`` value.  The
    readable compact form returned by the strict decoder is sufficient here:
    every character is the width of one consecutive distance range.
    """
    if not isinstance(spec, str):
        widths = list(spec)
        if len(widths) != expected_entries or any(not 1 <= width <= 16 for width in widths):
            raise ValueError(f"expected {expected_entries} Raw-LZ ladder widths, got {spec!r}")
        start = 1
        entries = []
        for width in widths:
            entries.append((start, width))
            start += 1 << width
        return entries
    # The decoder's historical compact representation concatenates decimal
    # widths (for example ``26810`` means 2, 6, 8, 10), so split it by the
    # known entry count rather than treating each character as one width.
    possibilities: list[list[int]] = []

    def split(cursor: int, values: list[int]) -> None:
        if len(values) == expected_entries:
            if cursor == len(spec):
                possibilities.append(values)
            return
        for width in range(1, 17):
            text = str(width)
            if spec.startswith(text, cursor):
                split(cursor + len(text), [*values, width])

    split(0, [])
    if len(possibilities) != 1:
        raise ValueError(f"expected an unambiguous {expected_entries}-entry Raw-LZ ladder, got {spec!r}")
    start = 1
    entries: list[tuple[int, int]] = []
    for width in possibilities[0]:
        entries.append((start, width))
        start += 1 << width
    return entries


def emit_ladder(writer: BitWriter, entries: list[tuple[int, int]]) -> None:
    for _start, width in entries:
        writer.write(width - 1, 4)


def longest_match(data: bytes, position: int, *, max_distance: int, max_length: int, unit: int = 1) -> tuple[int, int]:
    """Return the longest legal backwards match at ``position``.

    The original compressor is unknown.  This deliberately deterministic
    planner only needs to create a valid stream which fits the fixed retail
    slot; unchanged sources retain their original packed bytes verbatim.
    """
    best_length = 0
    best_distance = 0
    limit = min(max_distance, position // unit)
    for distance_units in range(1, limit + 1):
        distance = distance_units * unit
        length = 0
        while length < max_length and position + length < len(data) and data[position + length] == data[position + length - distance]:
            length += 1
        length -= length % unit
        if length > best_length:
            best_length = length
            best_distance = distance_units
            if best_length == max_length:
                break
    return best_distance, best_length


def raw_lz3_match_options(data: bytes, position: int, entries: list[tuple[int, int]], candidates: list[int]) -> list[tuple[int, int, int]]:
    """Find the best even-byte match in every LZ3 distance range."""
    best = [(0, 0) for _ in entries]
    for candidate in reversed(candidates[-512:]):
        distance = (position - candidate) // 2
        entry_index = next((index for index, (start, width) in enumerate(entries)
                            if start <= distance < start + (1 << width)), None)
        if entry_index is None:
            continue
        length = 0
        while position + length < len(data) and data[candidate + length] == data[position + length]:
            length += 1
        pairs = length // 2
        if pairs >= 2 and pairs > best[entry_index][0]:
            best[entry_index] = (pairs, distance)
    return [(index, pairs, distance) for index, (pairs, distance) in enumerate(best) if pairs]


def encode_raw_lz3(
    data: bytes, entries: list[tuple[int, int]], *, differential_filter: int = 0,
) -> bytes:
    """Use dynamic programming to pack Raw LZ3 tile payloads compactly."""
    pair_count = len(data) // 2
    infinity = 1 << 60
    costs = [infinity] * (pair_count + 1)
    choices: list[tuple[str, int, int, int] | None] = [None] * (pair_count + 1)
    costs[0] = 0
    candidates: dict[bytes, list[int]] = collections.defaultdict(list)

    for pair_position in range(pair_count):
        if costs[pair_position] == infinity:
            continue
        position = pair_position * 2
        literal_cost = costs[pair_position] + 17
        if literal_cost < costs[pair_position + 1]:
            costs[pair_position + 1] = literal_cost
            choices[pair_position + 1] = ("literal", 1, 0, 0)

        # The extended literal form is useful only from eight pairs onward.
        for pairs in range(8, pair_count - pair_position + 1):
            cost = costs[pair_position] + 4 + vli_cost(pairs - 1, 3) + pairs * 16
            target = pair_position + pairs
            if cost < costs[target]:
                costs[target] = cost
                choices[target] = ("literal_extended", pairs, 0, 0)

        key = data[position:position + 4]
        for entry_index, maximum_pairs, distance in raw_lz3_match_options(data, position, entries, candidates.get(key, [])):
            _start, distance_bits = entries[entry_index]
            for pairs in range(2, maximum_pairs + 1):
                if pairs <= 9:
                    cost = costs[pair_position] + 1 + 2 + distance_bits + 3
                else:
                    cost = costs[pair_position] + 1 + 2 + vli_cost((pairs - 2) >> 3, 3) + 1 + 2 + distance_bits + 3
                target = pair_position + pairs
                if cost < costs[target]:
                    costs[target] = cost
                    choices[target] = ("lookup", pairs, entry_index, distance)
        candidates[key].append(position)

    operations: list[tuple[str, int, int, int]] = []
    cursor = pair_count
    while cursor:
        choice = choices[cursor]
        if choice is None:
            raise ValueError("Raw LZ3 planner did not cover the payload")
        operations.append(choice)
        cursor -= choice[1]
    operations.reverse()

    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    if not 0 <= differential_filter <= 4:
        raise ValueError("Raw LZ3 differential filter must be in 0..4")
    writer.write(3 | (differential_filter << 5), 8)
    emit_ladder(writer, entries)
    position = 0
    for kind, pairs, entry_index, distance in operations:
        if kind == "literal":
            writer.write(0, 1)
            writer.write((data[position] << 8) | data[position + 1], 16)
        elif kind == "literal_extended":
            writer.write(1, 1)
            writer.write(3, 2)
            emit_vli(writer, pairs - 1, 3)
            writer.write(0, 1)
            for _ in range(pairs):
                writer.write((data[position] << 8) | data[position + 1], 16)
                position += 2
            continue
        else:
            start, width = entries[entry_index]
            writer.write(1, 1)
            if pairs <= 9:
                writer.write(entry_index, 2)
            else:
                writer.write(3, 2)
                emit_vli(writer, (pairs - 2) >> 3, 3)
                writer.write(1, 1)
                writer.write(entry_index, 2)
            writer.write(distance - start, width)
            writer.write((pairs - 2) & 7, 3)
        position += pairs * 2
    return writer.finish()


def encode_raw_lz(
    data: bytes, lz_mode: int, ladder_spec: str, *, differential_filter: int = 0,
) -> bytes:
    """Encode a native Raw-atom LZ stream (formats ``010``, ``020``, ``030``).

    These are the three formats used by the introductory object tiles.  The
    encoder intentionally uses only their short lookup forms: this keeps the
    output simple, deterministic, and fully accepted by the retail decoder.
    """
    if not data or len(data) > 0x40000:
        raise ValueError("Raw-LZ payload must be between 1 and 0x40000 bytes")
    if lz_mode not in (1, 2, 3):
        raise ValueError(f"unsupported Raw-LZ mode {lz_mode}")
    if lz_mode == 3 and len(data) & 1:
        raise ValueError("Raw-LZ mode 3 requires an even-length payload")
    if not 0 <= differential_filter <= 4:
        raise ValueError("Raw-LZ differential filter must be in 0..4")

    entry_count = {1: 4, 2: 7, 3: 3}[lz_mode]
    entries = ladder_entries(ladder_spec, entry_count)
    if lz_mode == 3:
        return encode_raw_lz3(data, entries, differential_filter=differential_filter)
    maximum_distance = entries[-1][0] + (1 << entries[-1][1]) - 1
    unit = 2 if lz_mode == 3 else 1
    maximum_length = 18 if lz_mode == 1 else len(data)

    writer = BitWriter()
    writer.write((len(data) << 8) | 0x70, 32)
    writer.write(lz_mode | (differential_filter << 5), 8)
    emit_ladder(writer, entries)

    position = 0
    while position < len(data):
        distance, length = longest_match(
            data,
            position,
            max_distance=maximum_distance,
            max_length=min(maximum_length, len(data) - position),
            unit=unit,
        )
        minimum = 4 if lz_mode == 3 else 3
        if length < minimum:
            # Raw LZ mode 2/3 also offers an extended literal form.  Long
            # unique spans occur frequently in hand-drawn object tiles; using
            # the form is what lets a one-pixel edit remain inside many of
            # the retail-sized source intervals.
            run = unit
            probe = position + unit
            while probe < len(data):
                _distance, probe_length = longest_match(
                    data,
                    probe,
                    max_distance=maximum_distance,
                    max_length=min(maximum_length, len(data) - probe),
                    unit=unit,
                )
                if probe_length >= minimum:
                    break
                run += unit
                probe += unit
            atoms = run // unit
            extended_literal = (lz_mode == 2 and atoms >= 10) or (lz_mode == 3 and atoms >= 8)
            if extended_literal:
                writer.write(1, 1)
                if lz_mode == 2:
                    writer.write(7, 3)
                    emit_vli(writer, atoms - 1, 4)
                else:
                    writer.write(3, 2)
                    emit_vli(writer, atoms - 1, 3)
                writer.write(0, 1)
                for cursor in range(position, position + run, unit):
                    if lz_mode == 3:
                        writer.write((data[cursor] << 8) | data[cursor + 1], 16)
                    else:
                        writer.write(data[cursor], 8)
                position += run
                continue
            writer.write(0, 1)
            if lz_mode == 3:
                writer.write((data[position] << 8) | data[position + 1], 16)
                position += 2
            else:
                writer.write(data[position], 8)
                position += 1
            continue

        entry_index = next(index for index, (start, width) in enumerate(entries)
                           if start <= distance < start + (1 << width))
        start, width = entries[entry_index]
        writer.write(1, 1)
        if lz_mode == 3 and length // 2 >= 10:
            pairs = length // 2
            writer.write(3, 2)
            emit_vli(writer, (pairs - 2) >> 3, 3)
            writer.write(1, 1)
            writer.write(entry_index, 2)
            writer.write(distance - start, width)
            writer.write((pairs - 2) & 7, 3)
        elif lz_mode == 2 and length >= 19:
            writer.write(7, 3)
            emit_vli(writer, (length - 3) >> 4, 4)
            writer.write(1, 1)
            writer.write(entry_index, 3)
            writer.write(distance - start, width)
            writer.write((length - 3) & 15, 4)
        else:
            writer.write(entry_index, 2 if lz_mode in (1, 3) else 3)
            writer.write(distance - start, width)
            if lz_mode == 3:
                writer.write(length // 2 - 2, 3)
            else:
                writer.write(length - 3, 4)
        position += length
    return writer.finish()


def encode_popuri(data: bytes, format_spec: str, ladder_spec: str) -> bytes:
    """Encode an authored payload using its audited native Popuri format.

    ``format_spec`` is the decoder's ``atom/LZ/differential`` triplet, such
    as ``"231"`` for Huffman-8, LZ3 and the nibble differential filter.
    This is intentionally a strict router: an unfamiliar format is an error,
    never a reason to substitute a different codec that happens to decode.
    """
    if len(format_spec) != 3 or not format_spec.isdigit():
        raise ValueError(f"invalid Popuri format {format_spec!r}")
    atom_format, lz_mode, differential_filter = (int(value) for value in format_spec)
    filtered = inverse_differential(data, differential_filter)

    if atom_format == 0 and lz_mode in (1, 2, 3):
        return encode_raw_lz(
            filtered, lz_mode, ladder_spec, differential_filter=differential_filter,
        )
    if atom_format == 0 and lz_mode == 0:
        return encode_raw_lz0(
            filtered, ladder_spec, differential_filter=differential_filter,
        )
    if atom_format == 1 and lz_mode == 0 and differential_filter == 0:
        return encode_huff4_lz0(filtered, ladder_spec)
    if atom_format == 1 and lz_mode == 2:
        return encode_huff4_lz2(
            filtered, ladder_spec, differential_filter=differential_filter,
        )
    if atom_format == 1 and lz_mode == 3:
        return encode_huff4_lz3(
            filtered, ladder_spec, differential_filter=differential_filter,
        )
    if atom_format == 2 and lz_mode == 2:
        return encode_huff8_lz2(
            filtered, ladder_spec, differential_filter=differential_filter,
        )
    if atom_format == 2 and lz_mode == 3:
        return encode_huff8_lz3(
            filtered, ladder_spec=ladder_spec, differential_filter=differential_filter,
        )
    raise ValueError(
        f"no verified encoder for Popuri format {format_spec} "
        f"(atom {atom_format}, LZ {lz_mode}, differential {differential_filter})"
    )


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
        original_payload, original_format, original_ladder = unpack(baseline)
        if original_payload == source:
            encoded = baseline
            preserved = True
        else:
            encoded = encode_popuri(source, original_format, original_ladder)
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

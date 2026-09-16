#!/usr/bin/env python3
"""Inventory statically labelled ``Unpack`` sources and destination classes.

This is deliberately an assembly-audit aid, not an asset converter.  It follows
only a small literal/register subset through direct intra-routine branches.
Each register retains at most sixteen alternative literal values; wider joins
are intentionally forgotten.  A row proves that a named ROM label reaches
``Unpack`` on a statically visible path; it does not prove that the decoded
bytes are graphics or that an indirect destination has a particular runtime
meaning.
"""

from __future__ import annotations

import argparse
import csv
import re
from dataclasses import dataclass
from pathlib import Path


REGISTER = r"r(?:[0-9]|1[0-2])|r8|sb|sl"
LITERAL_LOAD_RE = re.compile(
    rf"^\s*ldr\s+(?P<register>{REGISTER}),\s+\S+\s+@\s*=\s*(?P<value>\S+)\s*$"
)
MOV_RE = re.compile(
    rf"^\s*(?:mov|adds)\s+(?P<destination>{REGISTER}),\s+(?P<source>{REGISTER})(?:,\s*#0)?\s*$"
)
MOV_IMMEDIATE_RE = re.compile(
    rf"^\s*movs\s+(?P<register>{REGISTER}),\s*#(?P<value>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
SHIFT_RE = re.compile(
    rf"^\s*lsls\s+(?P<destination>{REGISTER}),\s+(?P<source>{REGISTER}),\s*#(?P<shift>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
ADD_IMMEDIATE_RE = re.compile(
    rf"^\s*adds\s+(?P<register>{REGISTER}),\s*#(?P<value>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
WRITE_RE = re.compile(
    rf"^\s*(?:add|adds|sub|subs|rsb|rsbs|mov|movs|ldr|ldrb|ldrh|ldrsb|ldrsh|"
    rf"lsls|lsrs|asrs|rors|ands|orrs|eors|bics|muls|negs|adcs|sbcs|mvns)\s+"
    rf"(?P<register>{REGISTER})(?:,|\s|$)"
)
FUNCTION_RE = re.compile(r"^\s*thumb_func_start\s+(?P<symbol>\S+)\s*$")
CALL_RE = re.compile(r"^\s*bl\s+(?P<symbol>\S+)\s*$")
BRANCH_RE = re.compile(
    r"^\s*(?P<opcode>b(?:eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?)\s+"
    r"(?P<target>\.?[A-Za-z_][A-Za-z0-9_.$]*)\s*$"
)
RETURN_RE = re.compile(r"^\s*(?:bx\s+\S+|pop\s+\{[^}]*\bpc\b[^}]*\})")
MAX_TRACKED_VALUES = 16


@dataclass(frozen=True)
class Call:
    source: str
    line: int
    function: str
    symbol: str
    destination_kind: str
    destination: str
    byte_count: str


def parse_number(value: str) -> int | None:
    try:
        return int(value, 0)
    except ValueError:
        return None


def describe_destination(value: int | str | None) -> tuple[str, str]:
    if not isinstance(value, int):
        return "runtime_or_unknown", ""
    if 0x06000000 <= value < 0x06020000:
        return "vram", f"0x{value:08X}"
    if 0x05000000 <= value < 0x05000400:
        return "palette_ram", f"0x{value:08X}"
    return "other_literal", f"0x{value:08X}"


Value = int | str
State = dict[str, frozenset[Value]]


def bounded(values: frozenset[Value]) -> frozenset[Value]:
    """Forget an over-merged register rather than inventing branch paths."""

    return values if len(values) <= MAX_TRACKED_VALUES else frozenset()


def merge_states(current: State | None, incoming: State) -> State:
    if current is None:
        return incoming
    merged: State = {}
    for register in current.keys() | incoming.keys():
        values = bounded(current.get(register, frozenset()) | incoming.get(register, frozenset()))
        if values:
            merged[register] = values
    return merged


def transfer(line: str, state: State) -> State:
    result = dict(state)
    if match := LITERAL_LOAD_RE.match(line):
        value = match.group("value")
        number = parse_number(value)
        result[match.group("register")] = frozenset((number if number is not None else value,))
    elif match := MOV_RE.match(line):
        destination = match.group("destination")
        if values := result.get(match.group("source")):
            result[destination] = values
        else:
            result.pop(destination, None)
    elif match := MOV_IMMEDIATE_RE.match(line):
        result[match.group("register")] = frozenset((int(match.group("value"), 0),))
    elif match := SHIFT_RE.match(line):
        destination = match.group("destination")
        values = result.get(match.group("source"), frozenset())
        if values and all(isinstance(value, int) for value in values):
            result[destination] = bounded(frozenset(value << int(match.group("shift"), 0) for value in values))
        else:
            result.pop(destination, None)
    elif match := ADD_IMMEDIATE_RE.match(line):
        register = match.group("register")
        values = result.get(register, frozenset())
        if values and all(isinstance(value, int) for value in values):
            result[register] = bounded(frozenset(value + int(match.group("value"), 0) for value in values))
        else:
            result.pop(register, None)
    elif match := WRITE_RE.match(line):
        # The operation writes a tracked destination but is outside the tiny
        # expression subset above.  Forget it instead of carrying a stale
        # literal through an unrelated arithmetic operation.
        result.pop(match.group("register"), None)
    elif CALL_RE.match(line):
        # AAPCS: r0-r3 are caller-clobbered.  High registers remain available
        # because several routines deliberately reuse them as literals.
        for register in ("r0", "r1", "r2", "r3"):
            result.pop(register, None)
    return result


def successors(lines: list[str], index: int, labels: dict[str, int]) -> list[int]:
    line = lines[index]
    if RETURN_RE.match(line):
        return []
    if match := BRANCH_RE.match(line):
        target = labels.get(match.group("target"))
        if target is None:
            return []
        if match.group("opcode") == "b":
            return [target]
        return [target, index + 1] if index + 1 < len(lines) else [target]
    return [index + 1] if index + 1 < len(lines) else []


def function_calls(
    source: Path,
    root: Path,
    name: str,
    lines: list[str],
    start_line: int,
    callee: str,
    include_size: bool,
) -> list[Call]:
    labels = {
        match.group(1): index
        for index, line in enumerate(lines)
        if (match := re.match(r"^\s*(\.?[A-Za-z_][A-Za-z0-9_.$]*):", line))
    }
    states: dict[int, State] = {0: {}}
    pending = [0]
    while pending:
        index = pending.pop()
        outgoing = transfer(lines[index], states[index])
        for target in successors(lines, index, labels):
            merged = merge_states(states.get(target), outgoing)
            if states.get(target) != merged:
                states[target] = merged
                pending.append(target)

    result: list[Call] = []
    for index, line in enumerate(lines):
        if not (match := CALL_RE.match(line)) or match.group("symbol") != callee:
            continue
        state = states.get(index, {})
        symbols = sorted(value for value in state.get("r0", frozenset()) if isinstance(value, str) and value.startswith("g"))
        destinations = state.get("r1", frozenset()) or frozenset((None,))
        sizes = (state.get("r2", frozenset()) or frozenset((None,))) if include_size else frozenset((None,))
        for symbol in symbols:
            for destination_value in destinations:
                destination_kind, destination = describe_destination(destination_value)
                for size_value in sizes:
                    byte_count = f"0x{size_value:X}" if isinstance(size_value, int) else ""
                    result.append(Call(
                        source=source.relative_to(root).as_posix(),
                        line=start_line + index,
                        function=name,
                        symbol=symbol,
                        destination_kind=destination_kind,
                        destination=destination,
                        byte_count=byte_count,
                    ))
    return result


def calls(root: Path, callee: str = "Unpack", include_size: bool = False) -> list[Call]:
    result: list[Call] = []
    for source in sorted((root / "asm").rglob("*.s")):
        lines = source.read_text(encoding="utf-8", errors="replace").splitlines()
        starts = [(index, match.group("symbol")) for index, line in enumerate(lines) if (match := FUNCTION_RE.match(line))]
        for position, (start, name) in enumerate(starts):
            end = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
            result.extend(function_calls(
                source, root, name, lines[start:end], start + 1, callee, include_size
            ))
    return sorted(set(result), key=lambda row: (
        row.source, row.line, row.symbol, row.destination_kind, row.destination, row.byte_count
    ))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="project root containing asm/")
    parser.add_argument("--csv", type=Path, help="write a CSV audit report")
    arguments = parser.parse_args()
    root = arguments.root.resolve()
    rows = calls(root)
    if arguments.csv:
        arguments.csv.parent.mkdir(parents=True, exist_ok=True)
        with arguments.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow(("source", "line", "function", "symbol", "destination_kind", "destination"))
            for row in rows:
                writer.writerow((row.source, row.line, row.function, row.symbol, row.destination_kind, row.destination))
        return
    print(f"conservative labelled Unpack calls: {len(rows)}")
    for row in rows:
        destination = row.destination or "runtime/unknown"
        print(f"{row.source}:{row.line}: {row.function}: {row.symbol} -> {row.destination_kind} {destination}")


if __name__ == "__main__":
    main()

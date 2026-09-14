#!/usr/bin/env python3
"""Inventory labelled resources that code proves are unpacked into VRAM.

The inventory follows only simple literal/register data flow in the generated
assembly. It deliberately does not infer a tile, palette, OAM, or image format
from a destination: every row is merely a code-backed lead for the graphics
audit.
"""

from __future__ import annotations

import argparse
import csv
import re
from dataclasses import dataclass
from pathlib import Path


LITERAL_LOAD_RE = re.compile(
    r"^\s*ldr\s+(?P<register>r(?:[0-9]|1[0-2])|r8|sb|sl),\s+\S+\s+@\s*=\s*(?P<value>\S+)\s*$"
)
MOV_RE = re.compile(
    r"^\s*(?:mov|adds)\s+(?P<destination>r(?:[0-9]|1[0-2])|r8|sb|sl),\s+(?P<source>r(?:[0-9]|1[0-2])|r8|sb|sl)(?:,\s*#0)?\s*$"
)
MOV_IMMEDIATE_RE = re.compile(
    r"^\s*movs\s+(?P<register>r(?:[0-9]|1[0-2])|r8|sb|sl),\s*#(?P<value>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
SHIFT_RE = re.compile(
    r"^\s*lsls\s+(?P<destination>r(?:[0-9]|1[0-2])|r8|sb|sl),\s+(?P<source>r(?:[0-9]|1[0-2])|r8|sb|sl),\s*#(?P<shift>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
ADD_IMMEDIATE_RE = re.compile(
    r"^\s*adds\s+(?P<register>r(?:[0-9]|1[0-2])|r8|sb|sl),\s*#(?P<value>0x[0-9A-Fa-f]+|[0-9]+)\s*$"
)
CALL_RE = re.compile(r"^\s*bl\s+(?P<symbol>\S+)\s*$")
FUNCTION_RE = re.compile(r"^\s*thumb_func_start\s+")


@dataclass(frozen=True)
class Call:
    source: str
    line: int
    symbol: str
    destination: int


def parse_number(value: str) -> int | None:
    try:
        return int(value, 0)
    except ValueError:
        return None


def vram_address(value: int | str | None) -> int | None:
    if isinstance(value, int) and 0x06000000 <= value < 0x06020000:
        return value
    return None


def calls(root: Path) -> list[Call]:
    result: list[Call] = []
    for source in sorted((root / "asm").rglob("*.s")):
        registers: dict[str, int | str] = {}
        for line_number, line in enumerate(source.read_text(encoding="utf-8").splitlines(), 1):
            if FUNCTION_RE.match(line):
                registers.clear()
                continue
            if match := LITERAL_LOAD_RE.match(line):
                registers[match.group("register")] = parse_number(match.group("value")) or match.group("value")
                continue
            if match := MOV_RE.match(line):
                destination = match.group("destination")
                source_register = match.group("source")
                if source_register in registers:
                    registers[destination] = registers[source_register]
                else:
                    registers.pop(destination, None)
                continue
            if match := MOV_IMMEDIATE_RE.match(line):
                registers[match.group("register")] = int(match.group("value"), 0)
                continue
            if match := SHIFT_RE.match(line):
                destination = match.group("destination")
                value = registers.get(match.group("source"))
                if isinstance(value, int):
                    registers[destination] = value << int(match.group("shift"), 0)
                else:
                    registers.pop(destination, None)
                continue
            if match := ADD_IMMEDIATE_RE.match(line):
                register = match.group("register")
                value = registers.get(register)
                if isinstance(value, int):
                    registers[register] = value + int(match.group("value"), 0)
                else:
                    registers.pop(register, None)
                continue
            if match := CALL_RE.match(line):
                if match.group("symbol") == "Unpack":
                    symbol = registers.get("r0")
                    destination = vram_address(registers.get("r1"))
                    if isinstance(symbol, str) and symbol.startswith("g") and destination is not None:
                        result.append(Call(
                            source=source.relative_to(root).as_posix(),
                            line=line_number,
                            symbol=symbol,
                            destination=destination,
                        ))
                # AAPCS makes r0-r3 caller-clobbered. Preserve high registers
                # because the surrounding assembly deliberately uses them for
                # reusable VRAM destinations.
                for register in ("r0", "r1", "r2", "r3"):
                    registers.pop(register, None)
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="project root containing asm/")
    parser.add_argument("--csv", type=Path, help="write CSV instead of text")
    arguments = parser.parse_args()
    root = arguments.root.resolve()
    rows = calls(root)
    if arguments.csv:
        arguments.csv.parent.mkdir(parents=True, exist_ok=True)
        with arguments.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow(("source", "line", "symbol", "vram_destination"))
            for row in rows:
                writer.writerow((row.source, row.line, row.symbol, f"0x{row.destination:08X}"))
        return
    print(f"proven labelled Unpack-to-VRAM calls: {len(rows)}")
    for row in rows:
        print(f"{row.source}:{row.line}: {row.symbol} -> {row.destination:#010x}")


if __name__ == "__main__":
    main()

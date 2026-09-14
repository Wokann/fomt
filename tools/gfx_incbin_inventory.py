#!/usr/bin/env python3
"""List direct baserom .incbin ranges still present in assembly sources.

This is an inventory aid, not a graphics extractor.  A ROM range is listed as
an *unclassified candidate* until a format, a consuming symbol, and a
lossless rebuild route have been independently verified.
"""

from __future__ import annotations

import argparse
import ast
import csv
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


INCBIN_RE = re.compile(
    r'^\s*\.incbin\s+"(?P<rom>baserom_[a-z]+\.gba)"'
    r'(?:\s*,\s*(?P<offset>[^,]+?)\s*,\s*(?P<length>.+?))?\s*(?:@.*)?$'
)


@dataclass(frozen=True)
class Range:
    source: Path
    line: int
    rom: str
    offset: int | None
    length: int | None
    offset_expression: str | None
    length_expression: str | None


def integer_expression(value: str) -> int | None:
    """Evaluate only integer literals joined by +, -, and parentheses."""
    try:
        tree = ast.parse(value.strip(), mode="eval")
    except SyntaxError:
        return None

    def visit(node: ast.AST) -> int:
        if isinstance(node, ast.Expression):
            return visit(node.body)
        if isinstance(node, ast.Constant) and isinstance(node.value, int):
            return node.value
        if isinstance(node, ast.UnaryOp) and isinstance(node.op, (ast.UAdd, ast.USub)):
            operand = visit(node.operand)
            return operand if isinstance(node.op, ast.UAdd) else -operand
        if isinstance(node, ast.BinOp) and isinstance(node.op, (ast.Add, ast.Sub)):
            left, right = visit(node.left), visit(node.right)
            return left + right if isinstance(node.op, ast.Add) else left - right
        raise ValueError("not a numeric assembly expression")

    try:
        return visit(tree)
    except ValueError:
        return None


def iter_ranges(root: Path) -> Iterable[Range]:
    sources = sorted(
        source for source in root.rglob("*")
        if source.is_file() and source.suffix.lower() in {".s", ".inc"}
    )
    for source in sources:
        for line_number, line in enumerate(source.read_text(encoding="utf-8").splitlines(), 1):
            match = INCBIN_RE.match(line)
            if not match:
                continue
            offset_expression = match.group("offset")
            length_expression = match.group("length")
            yield Range(
                source=source,
                line=line_number,
                rom=match.group("rom"),
                offset=integer_expression(offset_expression) if offset_expression else None,
                length=integer_expression(length_expression) if length_expression else None,
                offset_expression=offset_expression,
                length_expression=length_expression,
            )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("root", type=Path, help="project root containing asm/")
    parser.add_argument("--csv", type=Path, help="write machine-readable CSV instead of the text report")
    args = parser.parse_args()

    root = args.root.resolve()
    rows = list(iter_ranges(root / "asm"))
    if args.csv:
        with args.csv.open("w", encoding="utf-8", newline="") as handle:
            writer = csv.writer(handle)
            writer.writerow(("rom", "source", "line", "offset", "length", "offset_expression", "length_expression"))
            for row in rows:
                writer.writerow((
                    row.rom,
                    row.source.relative_to(root).as_posix(),
                    row.line,
                    f"0x{row.offset:X}" if row.offset is not None else "",
                    f"0x{row.length:X}" if row.length is not None else "",
                    row.offset_expression or "",
                    row.length_expression or "",
                ))
        return

    resolved = [row for row in rows if row.offset is not None and row.length is not None]
    print(f"direct baserom incbins: {len(rows)} ({len(resolved)} numeric ranges)")
    for row in rows:
        location = row.source.relative_to(root).as_posix()
        if row.offset is None or row.length is None:
            print(f"{row.rom:15} {location}:{row.line}: unresolved {row.offset_expression!r}, {row.length_expression!r}")
        else:
            print(f"{row.rom:15} {location}:{row.line}: 0x{row.offset:08X}-0x{row.offset + row.length:08X} ({row.length:#x})")


if __name__ == "__main__":
    main()

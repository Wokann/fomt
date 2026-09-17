#!/usr/bin/env python3
"""Inventory labelled FoMT IndexedResourceArchive payloads across four ROMs.

The DE initial data include records the original project already bounds with
``.incbin``.  This tool considers only those labelled records, then applies the
native IndexedResourceArchive header parser and checks whether the complete
encoded payload occurs unchanged in JP, US, EU and DE.  It deliberately does
not scan arbitrary ROM bytes or guess semantic names.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path

from indexed_resource_archive import Archive, parse


LABELLED_INCBIN = re.compile(
    r"\.global\s+(gUnk_[0-9A-Fa-f]+)\s*\n"
    r"\1:\s*\n\s*\.incbin\s+\"baserom_de\.gba\",\s*"
    r"(0x[0-9A-Fa-f]+),\s*(0x[0-9A-Fa-f]+)",
    re.MULTILINE,
)

REBUILT_SOURCES = {
    "gUnk_087401A4": "graphics/shared_resource_087401a4/",
    "gUnk_0873ED1C": "graphics/shared_resource_0873ed1c/",
    "gUnk_0873E5B0": "graphics/shared_resource_0873e5b0/",
    "gUnk_0873DE44": "graphics/shared_resource_0873de44/",
    "gUnk_0873D5FC": "graphics/shared_resource_0873d5fc/",
    "gUnk_0873D234": "graphics/shared_resource_0873d234/",
    "gUnk_0873CF90": "graphics/shared_resource_0873cf90/",
    "gUnk_0873CEAC": "graphics/shared_resource_0873ceac/",
    "gUnk_0873CCB4": "graphics/shared_resource_0873ccb4/",
    "gUnk_0873AFC8": "graphics/shared_resource_0873afc8/",
    "gUnk_0873AE54": "graphics/shared_resource_0873ae54/",
    "gUnk_08731B40": "graphics/shared_resource_08731b40/",
    "gUnk_0872EE78": "graphics/shared_resource_0872ee78/",
    "gUnk_08729460": "graphics/shared_resource_08729460/",
    "gUnk_0872937C": "graphics/shared_resource_0872937c/",
    "gUnk_08728320": "graphics/shared_resource_08728320/",
    "gUnk_08727A74": "graphics/shared_resource_08727a74/",
    "gUnk_08727368": "graphics/shared_resource_08727368/",
    "gUnk_08726CCC": "graphics/shared_resource_08726ccc/",
    "gUnk_08527094": "graphics/shared_resource_08527094/",
    "gUnk_086F2FAC": "graphics/shared_resource_086f2fac/",
    "gUnk_086FAA80": "graphics/shared_resource_086faa80/",
    "gUnk_0871ECAC": "graphics/shared_resource_0871ecac/",
    "gUnk_0871EDD4": "graphics/shared_resource_0871edd4/",
    "gUnk_08667060": "graphics/small_companion_archive/",
    "gUnk_086678A0": "graphics/common_resource_archive/",
    "gUnk_0871E7A8": "graphics/ui/menu_resource_archive/",
    "gUnk_0871EF00": "graphics/large_resource_archive/",
    "gUnk_08725DA0": "graphics/shared_resource_08725da0/",
    "gUnk_087537D0": "graphics/ui/farm_status/resource_archive/",
    "gUnk_08754674": "graphics/ui/cooking_resource_archive/",
    "gUnk_08754C0C": "graphics/ui/small_resource_archive/",
}


def labels(initial: Path) -> list[tuple[str, int, int]]:
    return [
        (name, int(offset, 0), int(length, 0))
        for name, offset, length in LABELLED_INCBIN.findall(initial.read_text())
    ]


def physical_matches(payload: bytes, roms: dict[str, bytes]) -> dict[str, int]:
    return {region: rom.find(payload) for region, rom in roms.items()}


def archive_rows(initial: Path, roms: dict[str, bytes]) -> list[tuple[str, int, int, Archive, dict[str, int]]]:
    rows = []
    for name, offset, declared_length in labels(initial):
        try:
            archive = parse(roms["de"], offset)
        except ValueError:
            continue
        if archive.encoded_length > declared_length or archive.encoded_length < 0x80:
            continue
        payload = roms["de"][offset:offset + archive.encoded_length]
        rows.append((name, offset, declared_length, archive, physical_matches(payload, roms)))
    return rows


def location(value: int) -> str:
    return f"`0x{value:X}`" if value >= 0 else "different"


def write_markdown(output: Path, rows: list[tuple[str, int, int, Archive, dict[str, int]]]) -> None:
    lines = [
        "# Label-bound IndexedResourceArchive inventory",
        "",
        "This generated inventory examines only DE `.incbin` records already",
        "bounded by the project, then validates the native archive header. It is not",
        "a blind ROM scan and does not claim that every parseable byte sequence is an",
        "image resource. `different` means that the complete DE archive payload does",
        "not occur verbatim in that regional ROM and therefore requires a separate",
        "regional pipeline before it can be treated as shared.",
        "",
        "| Label | JP | US | EU | DE | Length | Header counts | Entries | Source status |",
        "| --- | --- | --- | --- | --- | ---: | --- | ---: | --- |",
    ]
    rebuilt = 0
    identical_unmanaged = 0
    regional = 0
    for name, de_offset, _declared, archive, matches in rows:
        counts = ", ".join(str(value) for value in archive.section_counts)
        identical = all(matches[region] >= 0 for region in ("jp", "us", "eu", "de"))
        source = REBUILT_SOURCES.get(name)
        if source:
            status = f"rebuild: `{source}`"
            rebuilt += 1
        elif identical:
            status = "unmanaged, four-region identical"
            identical_unmanaged += 1
        else:
            status = "regional payload differs"
            regional += 1
        lines.append(
            f"| `{name}` | {location(matches['jp'])} | {location(matches['us'])} | "
            f"{location(matches['eu'])} | `0x{de_offset:X}` | `0x{archive.encoded_length:X}` | "
            f"{counts} | {archive.entry_count} | {status} |"
        )
    lines.extend([
        "",
        (
            f"Generated records: {len(rows)} ({rebuilt} rebuilt, "
            f"{identical_unmanaged} unmanaged but four-region identical, "
            f"{regional} regionally different). Regenerate with:"
        ),
        "",
        "```console",
        "make indexed-resource-archive-inventory",
        "```",
        "",
    ])
    output.write_text("\n".join(lines), newline="\n")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--de-inventory", type=Path, required=True)
    parser.add_argument("--jp", type=Path, required=True)
    parser.add_argument("--us", type=Path, required=True)
    parser.add_argument("--eu", type=Path, required=True)
    parser.add_argument("--de", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    roms = {region: path.read_bytes() for region, path in {
        "jp": args.jp, "us": args.us, "eu": args.eu, "de": args.de,
    }.items()}
    rows = archive_rows(args.de_inventory, roms)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    write_markdown(args.output, rows)
    print(f"wrote {len(rows)} label-bound IndexedResourceArchive records to {args.output}")


if __name__ == "__main__":
    main()

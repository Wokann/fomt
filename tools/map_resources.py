#!/usr/bin/env python3
"""Export and verify the native MapData visual resource streams.

The retail ``MapData`` table has 66 entries.  Its first six pointers are
visual-resource streams: layer 0 is copied by ``func_080A5EA0`` to VRAM, layers
1/2 are loaded by ``func_080A5DB8``, and layers 3--5 are BG tilemaps loaded by
``func_080A5CC0``.  This first map-resource phase deliberately preserves each
retail packed stream byte-for-byte.  It gives every unique stream a native,
editable decoded source, but refuses an edited source until its specific
Marvelous compression format has a proven encoder.

There is no layout sidecar: the authoritative alias and boundary information
is derived from the selected ROM's MapData table on every invocation.  A
source belongs to the lowest numbered MapData owner of its physical stream;
other map/layer references are aliases of that same file.
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent / "scripts"))

from decompress import unpack  # type: ignore[import-not-found]


ROM_BASE = 0x08000000
MAP_COUNT = 66
MAP_RECORD_SIZE = 0x28
VISUAL_LAYER_COUNT = 6
LAST_STREAM_LENGTH = 0x128
MAP_TABLES = {
    "jp": 0x08105A24,
    "us": 0x08105EDC,
    "eu": 0x08105F34,
    "de": 0x08106900,
}


@dataclass(frozen=True)
class Resource:
    members: tuple[tuple[int, int], ...]
    offsets: dict[str, int]
    length: int
    decoded_size: int
    format_spec: str
    ladder: str

    @property
    def owner(self) -> tuple[int, int]:
        return self.members[0]

    @property
    def extension(self) -> str:
        layers = {layer for _map_id, layer in self.members}
        if layers == {0}:
            return ".4bpp"
        if layers <= {3, 4, 5}:
            return ".tilemap"
        return ".bin"

    def source_relative(self) -> Path:
        map_id, layer = self.owner
        return Path(f"map_{map_id:02d}") / f"layer_{layer}{self.extension}"

    def output_relative(self) -> Path:
        map_id, layer = self.owner
        return Path(f"map_{map_id:02d}") / f"layer_{layer}.0x70"


def rom_offset(pointer: int) -> int:
    if pointer < ROM_BASE:
        raise ValueError(f"MapData pointer {pointer:#x} is not a ROM pointer")
    return pointer - ROM_BASE


def visual_members(rom: bytes, region: str) -> dict[int, tuple[tuple[int, int], ...]]:
    table = rom_offset(MAP_TABLES[region])
    result: dict[int, list[tuple[int, int]]] = {}
    for map_id in range(MAP_COUNT):
        record = table + map_id * MAP_RECORD_SIZE
        for layer in range(VISUAL_LAYER_COUNT):
            pointer = int.from_bytes(rom[record + layer * 4:record + layer * 4 + 4], "little")
            if pointer:
                result.setdefault(rom_offset(pointer), []).append((map_id, layer))
    return {offset: tuple(members) for offset, members in result.items()}


def boundaries(offsets: dict[int, tuple[tuple[int, int], ...]]) -> dict[int, int]:
    starts = sorted(offsets)
    result: dict[int, int] = {}
    for index, start in enumerate(starts):
        if index + 1 < len(starts):
            result[start] = starts[index + 1] - start
        else:
            result[start] = LAST_STREAM_LENGTH
    return result


def retail_stream(rom: bytes, offset: int, length: int) -> tuple[bytes, bytes, str, str]:
    packed = rom[offset:offset + length]
    if len(packed) != length:
        raise ValueError(f"stream at {offset:#x} exceeds ROM bounds")
    payload, format_spec, ladder = unpack(packed)
    return packed, bytes(payload), format_spec, ladder


def catalog(inputs: dict[str, bytes]) -> tuple[Resource, ...]:
    if set(inputs) != set(MAP_TABLES):
        raise ValueError("requires exactly jp, us, eu and de ROMs")
    member_tables = {region: visual_members(rom, region) for region, rom in inputs.items()}
    boundary_tables = {region: boundaries(table) for region, table in member_tables.items()}
    jp_members = member_tables["jp"]
    signatures = {members for members in jp_members.values()}
    for region, members in member_tables.items():
        region_signatures = {value for value in members.values()}
        if region_signatures != signatures:
            raise ValueError(f"{region.upper()} MapData aliases differ from JP; shared export is unsafe")

    result: list[Resource] = []
    for members in sorted(signatures):
        offsets: dict[str, int] = {}
        streams: dict[str, tuple[bytes, bytes, str, str]] = {}
        for region in MAP_TABLES:
            inverse = {value: key for key, value in member_tables[region].items()}
            offset = inverse[members]
            offsets[region] = offset
            streams[region] = retail_stream(inputs[region], offset, boundary_tables[region][offset])
        lengths = {len(value[0]) for value in streams.values()}
        payloads = {hashlib.sha256(value[1]).digest() for value in streams.values()}
        formats = {(value[2], value[3]) for value in streams.values()}
        if len(lengths) != 1 or len(payloads) != 1 or len(formats) != 1:
            owner = members[0]
            raise ValueError(
                f"map {owner[0]:02d} layer {owner[1]} differs across retail regions; "
                "refusing a shared source"
            )
        packed, payload, format_spec, ladder = streams["jp"]
        result.append(Resource(members, offsets, len(packed), len(payload), format_spec, ladder))
    return tuple(result)


def source_path(source_dir: Path, resource: Resource) -> Path:
    return source_dir / resource.source_relative()


def output_path(output_dir: Path, resource: Resource) -> Path:
    return output_dir / resource.output_relative()


def archive_path(output_dir: Path) -> Path:
    return output_dir / "map_visual_archive.0x70"


def ordered_for(region: str, resources: tuple[Resource, ...]) -> tuple[Resource, ...]:
    return tuple(sorted(resources, key=lambda resource: resource.offsets[region]))


def payload_for(inputs: dict[str, bytes], resource: Resource, region: str) -> bytes:
    packed, payload, _format, _ladder = retail_stream(inputs[region], resource.offsets[region], resource.length)
    if len(packed) != resource.length:
        raise AssertionError("catalog stream length changed")
    return payload


def export(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    for resource in resources:
        output = source_path(arguments.source_dir, resource)
        if output.exists() and not arguments.replace:
            raise ValueError(f"{output} exists; use --replace to refresh it")
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_bytes(payload_for(inputs, resource, "jp"))
    print(f"exported {len(resources)} shared MapData visual sources")


def build(arguments: argparse.Namespace) -> None:
    rom = arguments.rom.read_bytes()
    inputs = {region: Path(path).read_bytes() for region, path in arguments.all_rom}
    resources = catalog(inputs)
    archive = bytearray()
    expected_offset: int | None = None
    for resource in ordered_for(arguments.region, resources):
        source = source_path(arguments.source_dir, resource)
        if not source.exists():
            raise ValueError(f"missing source {source}")
        original = payload_for(inputs, resource, arguments.region)
        if source.read_bytes() != original:
            raise ValueError(
                f"{source}: edited MapData stream {resource.owner[0]:02d}/{resource.owner[1]} "
                f"uses native format {resource.format_spec}/{resource.ladder}; its encoder is not yet proven"
            )
        output = output_path(arguments.output_dir, resource)
        output.parent.mkdir(parents=True, exist_ok=True)
        offset = resource.offsets[arguments.region]
        packed = rom[offset:offset + resource.length]
        output.write_bytes(packed)
        if expected_offset is not None and offset != expected_offset:
            raise AssertionError(f"MapData archive has a gap before {offset:#x}")
        archive.extend(packed)
        expected_offset = offset + resource.length
    archive_path(arguments.output_dir).write_bytes(archive)
    print(f"rebuilt {len(resources)} byte-identical MapData streams for {arguments.region.upper()}")


def verify(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    for resource in resources:
        source = source_path(arguments.source_dir, resource)
        if source.read_bytes() != payload_for(inputs, resource, arguments.region):
            raise AssertionError(f"{source} no longer matches its retail decoded source")
        if arguments.output_dir is not None:
            output = output_path(arguments.output_dir, resource)
            baseline = inputs[arguments.region][resource.offsets[arguments.region]:resource.offsets[arguments.region] + resource.length]
            if output.read_bytes() != baseline:
                raise AssertionError(f"{output} does not match retail {arguments.region.upper()} bytes")
    if arguments.output_dir is not None:
        ordered = ordered_for(arguments.region, resources)
        first = ordered[0].offsets[arguments.region]
        last = ordered[-1].offsets[arguments.region] + ordered[-1].length
        baseline_archive = inputs[arguments.region][first:last]
        if archive_path(arguments.output_dir).read_bytes() != baseline_archive:
            raise AssertionError(f"MapData archive does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(resources)} MapData streams against {arguments.region.upper()} ROM")


def audit(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    by_extension: dict[str, int] = {}
    for resource in resources:
        by_extension[resource.extension] = by_extension.get(resource.extension, 0) + 1
    print(f"{len(resources)} unique MapData visual streams")
    print(" ".join(f"{kind}:{count}" for kind, count in sorted(by_extension.items())))
    print(f"decoded bytes: {sum(resource.decoded_size for resource in resources):#x}")


def add_roms(parser: argparse.ArgumentParser, destination: str = "rom") -> None:
    parser.add_argument(f"--{destination}", nargs=2, action="append", metavar=("REGION", "ROM"), required=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    export_parser = commands.add_parser("export")
    export_parser.add_argument("--source-dir", type=Path, required=True)
    export_parser.add_argument("--replace", action="store_true")
    add_roms(export_parser)
    build_parser = commands.add_parser("build")
    build_parser.add_argument("--region", choices=tuple(MAP_TABLES), required=True)
    build_parser.add_argument("--rom", type=Path, required=True)
    build_parser.add_argument("--source-dir", type=Path, required=True)
    build_parser.add_argument("--output-dir", type=Path, required=True)
    add_roms(build_parser, "all-rom")
    verify_parser = commands.add_parser("verify")
    verify_parser.add_argument("--region", choices=tuple(MAP_TABLES), required=True)
    verify_parser.add_argument("--source-dir", type=Path, required=True)
    verify_parser.add_argument("--output-dir", type=Path)
    add_roms(verify_parser)
    audit_parser = commands.add_parser("audit")
    add_roms(audit_parser)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    else:
        audit(arguments)


if __name__ == "__main__":
    main()

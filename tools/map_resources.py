#!/usr/bin/env python3
"""Export and verify the native MapData visual resource streams.

The retail ``MapData`` table has 66 entries.  Its first six pointers are
visual-resource streams: layer 0 is copied by ``func_080A5EA0`` to VRAM, layers
1/2 are loaded by ``func_080A5DB8``, and layers 3--5 are BG tilemaps loaded by
``func_080A5CC0``. Each unique stream has a native decoded source. Unchanged
sources preserve retail packed bytes exactly; edited sources are rebuilt with
the audited atom/LZ/differential format and must fit their original fixed
packed interval.

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
sys.path.insert(0, str(Path(__file__).parent))

from decompress import unpack  # type: ignore[import-not-found]
from marvelous_codec import encode_popuri  # type: ignore[import-not-found]


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
        if layers <= {1, 2}:
            return ".gbapal"
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


def read_source(path: Path, resource: Resource) -> bytes:
    """Read one decoded source with the catalog's proven payload bound."""
    source = path.read_bytes()
    if len(source) != resource.decoded_size:
        raise ValueError(
            f"{path}: expected {resource.decoded_size:#x} decoded bytes for "
            f"MapData {resource.owner[0]:02d}/{resource.owner[1]}, got {len(source):#x}"
        )
    return source


def output_path(output_dir: Path, resource: Resource) -> Path:
    return output_dir / resource.output_relative()


def archive_path(output_dir: Path) -> Path:
    return output_dir / "map_visual_archive.0x70"


def ordered_for(region: str, resources: tuple[Resource, ...]) -> tuple[Resource, ...]:
    return tuple(sorted(resources, key=lambda resource: resource.offsets[region]))


def archive_bounds(region: str, resources: tuple[Resource, ...]) -> tuple[int, int]:
    ordered = ordered_for(region, resources)
    return ordered[0].offsets[region], ordered[-1].offsets[region] + ordered[-1].length


def apply_archive(target: bytes, baseline: bytes, archive: bytes, region: str, resources: tuple[Resource, ...]) -> bytes:
    """Replace only the proven continuous MapData visual archive range.

    The existing ROM code and its C/C++ pointer tables continue to address the
    original physical offsets.  Accepting only a baseline or already-patched
    target range prevents this post-link stage from silently overwriting data
    owned by another pipeline.
    """
    first, last = archive_bounds(region, resources)
    expected = baseline[first:last]
    if len(archive) != last - first:
        raise ValueError(f"MapData archive is {len(archive):#x} bytes; expected {last - first:#x}")
    current = target[first:last]
    if current != expected and current != archive:
        raise ValueError(
            f"target ROM MapData range {first:#x}-{last:#x} differs from both the retail baseline "
            "and this generated archive; refusing to overwrite it"
        )
    patched = bytearray(target)
    patched[first:last] = archive
    return bytes(patched)


def payload_for(inputs: dict[str, bytes], resource: Resource, region: str) -> bytes:
    packed, payload, _format, _ladder = retail_stream(inputs[region], resource.offsets[region], resource.length)
    if len(packed) != resource.length:
        raise AssertionError("catalog stream length changed")
    return payload


def rebuild(source: bytes, baseline: bytes, resource: Resource) -> bytes:
    """Preserve an unchanged stream or rebuild one edited fixed-slot stream."""
    original, format_spec, ladder = unpack(baseline)
    if format_spec != resource.format_spec or ladder != resource.ladder:
        raise AssertionError(
            f"MapData {resource.owner[0]:02d}/{resource.owner[1]} no longer matches "
            f"its audited format {resource.format_spec}/{resource.ladder}"
        )
    if bytes(original) == source:
        return baseline
    encoded = encode_popuri(source, format_spec, ladder)
    if len(encoded) > resource.length:
        raise ValueError(
            f"edited MapData {resource.owner[0]:02d}/{resource.owner[1]} needs "
            f"{len(encoded):#x} bytes but its fixed native interval holds only "
            f"{resource.length:#x} bytes"
        )
    rebuilt = encoded + bytes(resource.length - len(encoded))
    checked, checked_format, checked_ladder = unpack(rebuilt)
    if bytes(checked) != source or checked_format != format_spec or checked_ladder != ladder:
        raise AssertionError(
            f"rebuilt MapData {resource.owner[0]:02d}/{resource.owner[1]} failed strict native decode validation"
        )
    return rebuilt


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
        output = output_path(arguments.output_dir, resource)
        output.parent.mkdir(parents=True, exist_ok=True)
        offset = resource.offsets[arguments.region]
        packed = rom[offset:offset + resource.length]
        rebuilt = rebuild(read_source(source, resource), packed, resource)
        output.write_bytes(rebuilt)
        if expected_offset is not None and offset != expected_offset:
            raise AssertionError(f"MapData archive has a gap before {offset:#x}")
        archive.extend(rebuilt)
        expected_offset = offset + resource.length
    archive_path(arguments.output_dir).write_bytes(archive)
    print(f"rebuilt {len(resources)} MapData streams for {arguments.region.upper()}")


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
        first, last = archive_bounds(arguments.region, resources)
        baseline_archive = inputs[arguments.region][first:last]
        if archive_path(arguments.output_dir).read_bytes() != baseline_archive:
            raise AssertionError(f"MapData archive does not match retail {arguments.region.upper()} bytes")
    print(f"verified {len(resources)} MapData streams against {arguments.region.upper()} ROM")


def patch(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.all_rom}
    resources = catalog(inputs)
    target_path = arguments.rom
    target = target_path.read_bytes()
    archive = arguments.archive.read_bytes()
    target_path.write_bytes(apply_archive(target, inputs[arguments.region], archive, arguments.region, resources))
    first, last = archive_bounds(arguments.region, resources)
    print(f"patched {target_path} MapData range {first:#x}-{last:#x} for {arguments.region.upper()}")


def patch_test(arguments: argparse.Namespace) -> None:
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    for region, baseline in inputs.items():
        archive = archive_path(arguments.output_root / region / "graphics" / "maps").read_bytes()
        patched = apply_archive(baseline, baseline, archive, region, resources)
        if patched != baseline:
            raise AssertionError(f"unmodified MapData archive changes retail {region.upper()} ROM bytes")
    print("verified post-link MapData archive patching against JP, US, EU and DE ROMs")


def edit_test(arguments: argparse.Namespace) -> None:
    """Exercise one capacity-fitting authored edit for every retail format.

    The source tree remains unmodified. This validates the generic encoder
    router, inverse differential filters, fixed-slot bound, and strict decoder
    for all format families that MapData actually uses.
    """
    inputs = {region: Path(path).read_bytes() for region, path in arguments.rom}
    resources = catalog(inputs)
    remaining = {resource.format_spec for resource in resources}
    verified: dict[str, tuple[int, int]] = {}
    for resource in resources:
        if resource.format_spec not in remaining:
            continue
        original = payload_for(inputs, resource, "jp")
        edited = bytearray(original)
        edited[-1] ^= 1
        baseline = inputs["jp"][resource.offsets["jp"]:resource.offsets["jp"] + resource.length]
        try:
            rebuilt = rebuild(bytes(edited), baseline, resource)
        except ValueError:
            continue
        checked, checked_format, checked_ladder = unpack(rebuilt)
        if bytes(checked) != bytes(edited) or checked_format != resource.format_spec or checked_ladder != resource.ladder:
            raise AssertionError(f"edited MapData {resource.owner} did not survive strict round-trip")
        for region, rom in inputs.items():
            regional_baseline = rom[resource.offsets[region]:resource.offsets[region] + resource.length]
            _regional_payload, regional_format, regional_ladder = unpack(regional_baseline)
            if regional_format != resource.format_spec or regional_ladder != resource.ladder:
                raise AssertionError(f"MapData {resource.owner} has an unrecorded {region.upper()} format difference")
            if len(rebuilt) != len(regional_baseline):
                raise AssertionError(f"edited MapData {resource.owner} does not fit the {region.upper()} fixed interval")
        verified[resource.format_spec] = resource.owner
        remaining.remove(resource.format_spec)
    if remaining:
        missing = ", ".join(sorted(remaining))
        raise AssertionError(f"no capacity-fitting edit test found for MapData formats: {missing}")
    details = ", ".join(f"{key}:{owner[0]:02d}/{owner[1]}" for key, owner in sorted(verified.items()))
    print(f"verified editable MapData format coverage ({details})")


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
    patch_parser = commands.add_parser("patch")
    patch_parser.add_argument("--region", choices=tuple(MAP_TABLES), required=True)
    patch_parser.add_argument("--rom", type=Path, required=True)
    patch_parser.add_argument("--archive", type=Path, required=True)
    add_roms(patch_parser, "all-rom")
    patch_test_parser = commands.add_parser("patch-test")
    patch_test_parser.add_argument("--output-root", type=Path, required=True)
    add_roms(patch_test_parser)
    edit_test_parser = commands.add_parser("edit-test")
    add_roms(edit_test_parser)
    audit_parser = commands.add_parser("audit")
    add_roms(audit_parser)
    arguments = parser.parse_args()
    if arguments.command == "export":
        export(arguments)
    elif arguments.command == "build":
        build(arguments)
    elif arguments.command == "verify":
        verify(arguments)
    elif arguments.command == "patch":
        patch(arguments)
    elif arguments.command == "patch-test":
        patch_test(arguments)
    elif arguments.command == "edit-test":
        edit_test(arguments)
    else:
        audit(arguments)


if __name__ == "__main__":
    main()

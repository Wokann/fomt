# Indexed resource archive audit

This document records ROM ranges consumed by `IndexedResourceArchive` in
`src/resource_handle.cc`. They are **not** automatically image resources:
their descriptor payloads may select graphics, animation data, layout records,
or other runtime data. They remain direct baseline-ROM data until a consumer
and a lossless source format are established.

The constructor establishes six counted descriptor blocks with element sizes
4, 16, 8, 32, 32, and 8 bytes, followed by a counted table of four-byte
entries. `tools/indexed_resource_archive.py` parses only these proven bounds;
it intentionally does not assign guessed meanings to descriptor fields.

## Confirmed shared archives

| Archive | JP | US | EU | DE | Native length | Header counts | Entries | SHA-256 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Common resource archive | `0x3ED9FC` | `0x6678A0` | `0x6678FC` | `0x3EE93C` | `0x12848` | `493, 500, 101, 1624, 342, 0` | 532 | `c28eff40e6965f89015da48b9527ea995eeec0d7ec30c4f1f2aeda5b8f3f9f33` |
| Small companion archive | `0x3ED1BC` | `0x667060` | `0x6670BC` | `0x3EE0FC` | `0x840` | `3, 16, 3, 52, 2, 0` | 16 | `45596a1fced2bdeb33c101de5f124c26939d03ee0f2d71e361ba5ffab53a7cc7` |
| Small shared UI archive | `0x4DABB8` | `0x754C0C` | `0x754C68` | `0x4DC128` | `0x548` | `2, 4, 2, 36, 2, 0` | 5 | `2908231dba2fb5105723476b17f7fd4ab3d4fe597144df7a0dc06ef065ffca6b` |
| Cooking UI archive | `0x4DA620` | `0x754674` | `0x7546D0` | `0x4DBB90` | `0x598` | `1, 3, 3, 40, 1, 0` | 4 | `3ad7d5722ca026e54678295cb52f199e435ae313e99a8c0cadf4b62e89566fda` |
| Farm Status / Town Map archive | `0x4D977C` | `0x7537D0` | `0x75382C` | `0x4DACEC` | `0xEA4` | `20, 40, 11, 73, 13, 0` | 40 | `480a114e52b941e289d67055ddd632b6c0bbee3cfa66263523ad91c7e1d4dfc1` |

All five complete native archive payloads are byte-identical across JP, US,
EU, and DE. The common archive is the data currently exposed under
`gUnk_086678A0` in non-JP regional assembly; the JP physical match was found
by the exact complete payload, not by inventing a JP label.

The common archive's group-descriptor consumer is fully bounded. Every
drawable descriptor selects valid GBA OAM, 4bpp tile, and BGR555 palette
ranges; `func_0805E790` resolves the fields and `func_080757E8` uploads tiles
and palettes to OBJ memory. Its 498 indexed PNG sources and fixed-size rebuild
live under `graphics/common_resource_archive/`. The two all-zero groups (`316`,
`429`) are native non-drawable records and are deliberately not artwork.

The small companion archive follows the same fully bounded group-descriptor
contract. Its sixteen descriptors select three native GBA OAM records, fifty-
two 4bpp tiles, and two BGR555 palettes. Every group is drawable; shared OAM
records intentionally map multiple editable group views onto their native tile
ranges. Its complete indexed PNG sources and fixed-size rebuild live under
`graphics/small_companion_archive/`.

The small shared UI archive is independently bounded at the four locations in
the table. Its four descriptors contain three drawable resources and one
all-zero native slot; together they select two OAM records, 36 4bpp tiles, two
BGR555 palettes, and five selection entries. Generic UI and cooking-screen
constructors both instantiate it, so its `graphics/ui/small_resource_archive/`
PNG sources deliberately retain neutral physical group names rather than
inventing a single-screen interpretation.

The cooking UI archive is independently bounded at the four locations in the
table. Its three descriptors contain two drawable resources and one all-zero
native slot; together they select three OAM records, 40 4bpp tiles, one BGR555
palette, and four selection entries. Cooking constructors instantiate it, so
its PNG sources live under `graphics/ui/cooking_resource_archive/`; their
neutral physical group names avoid guessing a separate gameplay role for each
selection-frame variant.

The Farm Status screen constructs a third archive at `0x4D977C` in JP and
`0x7537D0` in US (with the regional locations recorded by its rebuild tool).
Town Map uses the same complete `0xEA4` payload. Its consumer path is fully
bounded: forty group descriptors select valid OAM, 4bpp tile, and BGR555
palette ranges, and runtime code uploads the latter two ranges to OBJ memory.
Complete indexed-PNG sources and the fixed-size lossless rebuild are under
`graphics/ui/farm_status/resource_archive/`.

Recheck the evidence with:

```console
python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x3ED9FC ^
  --rom us baserom_us.gba 0x6678A0 ^
  --rom eu baserom_eu.gba 0x6678FC ^
  --rom de baserom_de.gba 0x3EE93C

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x3ED1BC ^
  --rom us baserom_us.gba 0x667060 ^
  --rom eu baserom_eu.gba 0x6670BC ^
  --rom de baserom_de.gba 0x3EE0FC

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4DABB8 ^
  --rom us baserom_us.gba 0x754C0C ^
  --rom eu baserom_eu.gba 0x754C68 ^
  --rom de baserom_de.gba 0x4DC128

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4DA620 ^
  --rom us baserom_us.gba 0x754674 ^
  --rom eu baserom_eu.gba 0x7546D0 ^
  --rom de baserom_de.gba 0x4DBB90
```

The `^` continuation marker is for `cmd.exe`; remove it or use the shell's
own continuation syntax elsewhere.

## Consequence for the graphics pipeline

The managed actor tile stream, Records Screen task icon/palette pairs, and
other confirmed resource payloads retain their existing direct runtime labels.
Any future archive conversion must preserve its parsed boundary, descriptor
counts, entry ordering, and every pointer or caller that resolves an archive
index.

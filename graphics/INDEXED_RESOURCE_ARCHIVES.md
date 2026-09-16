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

Both complete native archive payloads are byte-identical across JP, US, EU,
and DE. The common archive is the data currently exposed under
`gUnk_086678A0` in non-JP regional assembly; the JP physical match was found
by the exact complete payload, not by inventing a JP label.

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
```

The `^` continuation marker is for `cmd.exe`; remove it or use the shell's
own continuation syntax elsewhere.

## Consequence for the graphics pipeline

The managed actor tile stream, Records Screen task icon/palette pairs, and
other confirmed resource payloads retain their existing direct runtime labels.
These two archive containers are their metadata/selection layer and are not
replaced by a PNG export. Any future conversion must preserve the parsed
boundary, all descriptor counts, entry ordering, and every pointer or caller
that resolves an archive index.

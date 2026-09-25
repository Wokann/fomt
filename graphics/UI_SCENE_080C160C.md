# `func_080C160C` BG resource set

`func_080C160C` directly unpacks two labelled 32-by-32 background tilemaps to
`0x0600F800` and `0x0600F000`, then loads a 4bpp tile source at
`0x06000000`. It configures BG controls `0x1E41` and `0x1F42` for those screen
blocks. The current native sources preserve exactly the three proven streams.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x20C` | `0x800` (32x32 u16 entries) | `020`, ladder `236791011` | `0x0600F800` |
| `layer_1.tilemap` | `0xD8` | `0x800` (32x32 u16 entries) | `030`, ladder `379` | `0x0600F000` |
| `tiles.4bpp` | `0xA38` | `0xE80` (116 4bpp tiles) | `020`, ladder `246781012` | `0x06000000` |

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4C5530` | `0x4C5814` |
| US | `0x73F3C8` | `0x73F6AC` |
| EU | `0x73F424` | `0x73F708` |
| DE | `0x4C683C` | `0x4C6B20` |

Immediately after unpacking, the routine copies exactly `0x200` bytes to
palette RAM at `0x05000020`, i.e. beginning with BG palette bank 1. Every
nonblank tilemap entry selects banks 1 through 6. These six actual palette
banks occupy `0xC0` bytes. The adjacent indexed resource archive starts at
`+0xC0`; the remaining `0x140` bytes read by the overlong hardware copy are
archive data, not colors. The copy also extends beyond BG palette RAM into
OBJ palette RAM, which does not change the archive's ROM ownership.

The original JP function's literal-pool pointer is `0x084C624C`; this corrects
an earlier invalid simple-offset estimate (`0x084C61CC`). The JP payload at the
correct pointer exactly matches US, EU and DE. All four `0xC0`-byte palette
prefixes share SHA-256
`3cd46474231b5f816641cec654275a7dde0612f764272a2fd6b7990e77c49bd4`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4C624C` | `0xC0` |
| US | `0x7400E4` | `0xC0` |
| EU | `0x740140` | `0xC0` |
| DE | `0x4C7558` | `0xC0` |

`shared/palettes.pal` is the editable independent JASC-PAL source for the 96
actual colors. The generic `%.gbapal: %.pal` rule creates a source-adjacent
binary that assembly links directly. `reference/palettes.png` is a view of
those colors, not a build input. `reference/layer_0.png`, `layer_1.png`, and `scene.png`
are code-backed 256-by-256 views; `scene.png` composites the upper BG map over
the lower one using palette index zero as transparent. The native tilemaps
remain authoritative for tile IDs, flip flags and actual palette-bank values;
no JSON layout sidecar is used.

```console
make gfx-ui-scene-080c160c-all
make gfx-ui-scene-080c160c-preview
make fomt_jp fomt_us fomt_eu fomt_de
```

The C Raw-LZ tool builds source-adjacent `.tilemap.lz` and `.4bpp.lz`
files, which assembly includes directly under relocatable symbols. The tile
stream uses the encoder's general `--literal-tail` strategy to preserve the
retail final three-byte literal run. The palette is also directly linked;
its bytes no longer require a post-`objcopy` patch. The hardware's `0x200`-byte
copy still reads into the separately owned archive. An edited stream must
still fit its original slot until adjacent data is made relocatable.

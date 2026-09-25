# `func_080BCFAC` BG resource set

`func_080BCFAC` is the direct consumer of this resource group. It unpacks two
labelled 32-by-32 background tilemaps to `0x0600F800` and `0x0600F000`, then
unpacks a native 4bpp tile buffer at `0x06000000`. It configures BG controls
`0x1E41` and `0x1F42`. `func_080BD064` calls this initializer but does not
perform these three `Unpack` calls itself.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x124` | `0x800` (32x32 u16 entries) | `030`, ladder `2610` | `0x0600F800` |
| `layer_1.tilemap` | `0xA8` | `0x800` (32x32 u16 entries) | `030`, ladder `169` | `0x0600F000` |
| `tiles.4bpp` | `0xC04` | `0x7BE2` | `020`, ladder `256791113` | `0x06000000` |

The tile buffer contains 991 complete 4bpp tiles plus a two-byte tail. All
tilemap references are within the complete-tile portion; the tail is retained
unchanged in `tiles.4bpp` and is never fabricated as visible pixels. Thus the
native tilemaps still provide the lossless source of tile IDs, flips and
palette-bank selectors, while the checked-in PNGs can faithfully show this
particular two-layer scene.

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4C1F8C` | `0x4C2158` |
| US | `0x73BE24` | `0x73BFF0` |
| EU | `0x73BE80` | `0x73C04C` |
| DE | `0x4C3190` | `0x4C335C` |

Immediately after unpacking, the function copies exactly `0x200` bytes from
`gUiScene080BCFACPalette` to BG palette RAM (`0x05000000`). The copy length
is not the ROM ownership length: the tilemaps select banks 0, 1, 2, 3 and 5;
the first six banks occupy `0xC0` bytes. The indexed resource archive starts
at `+0xC0`. The remaining `0x140` bytes copied by the routine are archive
data, not colors. The four-region palette prefix has SHA-256
`f52675fe893d77e2fba976c7b291acd6a6359d433e8283bc04cbf5a35e34f469`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4C2D5C` | `0xC0` |
| US | `0x73CBF4` | `0xC0` |
| EU | `0x73CC50` | `0xC0` |
| DE | `0x4C3F60` | `0xC0` |

`shared/palettes.pal` is the editable six-bank JASC-PAL source. The bit-15
word previously represented with PNG alpha `254` was actually in the adjacent
archive, not in this palette. The generic `%.gbapal: %.pal` rule now creates
the source-adjacent binary used directly by assembly. `reference/palettes.png`
is a view, not a build input. `reference/layer_0.png`, `layer_1.png`, and
`scene.png` are code-backed 256-by-256 visual references; the latter composites
the upper layer over the lower one with palette index zero transparent. These
references are not a replacement for the native tilemaps, and no JSON layout
sidecar is used.

```console
make gfx-ui-scene-080bcfac-all
make gfx-ui-scene-080bcfac-preview
make fomt_jp fomt_us fomt_eu fomt_de
```

The C Raw-LZ tool builds source-adjacent `.tilemap.lz` and `.4bpp.lz`
files, which assembly includes directly under relocatable symbols. The
palette is also linked directly, without a post-`objcopy` Python patch.
The hardware copy still reads into the separately owned archive. An edited
stream must fit its original slot until adjacent data is made relocatable.

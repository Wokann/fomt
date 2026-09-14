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
`gUnk_0873CBF4` to BG palette RAM (`0x05000000`). The load length is an
explicit code boundary, so the source remains valid even though it crosses an
assembly-only label boundary. The whole palette is shared by JP, US, EU and
DE and has SHA-256
`f22d1e3fbc046353944f725f6e025ef0148545ac998b3c1268019aff5a090672`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4C2D5C` | `0x200` |
| US | `0x73CBF4` | `0x200` |
| EU | `0x73CC50` | `0x200` |
| DE | `0x4C3F60` | `0x200` |

`shared/palettes.png` is the editable indexed sixteen-bank palette source.
One native entry has BGR555 bit 15 set; because the bit is not visible on the
GBA, the PNG stores it as alpha `254` (ordinary opaque entries use `255`) and
the build restores it exactly. `reference/layer_0.png`, `layer_1.png`, and
`scene.png` are code-backed 256-by-256 visual references; the latter composites
the upper layer over the lower one with palette index zero transparent. These
references are not a replacement for the native tilemaps, and no JSON layout
sidecar is used.

```console
make gfx-ui-scene-080bcfac-all
make gfx-ui-scene-080bcfac-preview
make gfx-ui-scene-080bcfac-patch-test
```

The normal ROM recipe rebuilds the selected region's three native streams and
palette, then patches only their original intervals after `objcopy`. Unchanged
sources reproduce retail bytes exactly; edited tile/map data uses the verified
Raw-LZ encoder and is rejected if it does not fit the original fixed slot.

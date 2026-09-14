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

The tile buffer contains 991 complete 4bpp tiles plus a two-byte tail. That
does not establish a standalone full-image layout, so it remains an exact
native source buffer rather than a guessed PNG composition.

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4C1F8C` | `0x4C2158` |
| US | `0x73BE24` | `0x73BFF0` |
| EU | `0x73BE80` | `0x73C04C` |
| DE | `0x4C3190` | `0x4C335C` |

The adjoining code copies `0x200` bytes from `gUnk_0873CBF4` to palette
memory. Its declared assembly range is only `0xC0` bytes and ends at
`gUnk_0873CCB4`, so the copy crosses an unclassified boundary. The palette
span is intentionally not exported or rebuilt here.

```console
make gfx-ui-scene-080bcfac-all
make gfx-ui-scene-080bcfac-patch-test
```

The normal ROM recipe rebuilds the selected region's three native streams and
patches only their original intervals after `objcopy`. Unchanged sources
reproduce retail bytes exactly; edited data uses the verified Raw-LZ encoder
and is rejected if it does not fit the original fixed slot.

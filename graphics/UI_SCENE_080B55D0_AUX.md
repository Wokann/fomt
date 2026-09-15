# `func_080B55D0` auxiliary BG resource set

`func_080B55D0` loads a larger scene with several unrelated resource classes.
Its main `gUnk_086FB004` stream uses native format `230`, which has no
verified encoder and is deliberately left as original ROM data. This pipeline
only manages the later, contiguous, independently decodable streams loaded to
two BG map blocks and one 4bpp tile block.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x16C` | `0x800` (32x32 u16 entries) | `030`, ladder `125` | `0x0600E800` |
| `layer_1.tilemap` | `0x110` | `0x800` (32x32 u16 entries) | `030`, ladder `159` | `0x0600F800` |
| `tiles.4bpp` | `0xD60` | `0x1180` (140 4bpp tiles) | `020`, ladder `2589101112` | `0x06004000` |

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4B2738` | `0x4B29B4` |
| US | `0x72C5D0` | `0x72C84C` |
| EU | `0x72C62C` | `0x72C8A8` |
| DE | `0x4B38A4` | `0x4B3B20` |

The full scene also loads a compressed `0x1E0`-byte palette stream at
`gUnk_086FD19C` to BG palette bank 0, then copies `0x200` bytes beginning at
`gUnk_0872D5AC` to `0x050000E0` (BG bank 7 through into OBJ palette RAM).
The auxiliary maps use BG bank 2 and bank 7 respectively, so those two runtime
operations prove the colours of the visible auxiliary layers. Both ranges
overlap other resource classes, therefore neither is an independently editable
palette source.

`reference/layer_0.png`, `layer_1.png`, `scene.png`, and the 240-by-160
`screen.png` are consequently verified read-only references. The latter is
only the auxiliary BG composition: the routine's larger unhandled main stream
and later objects may add further runtime content. Before emitting the PNGs,
the renderer verifies the two palette operations, their decoded format, and
all four retail regions. No JSON layout sidecar is used.

```console
make gfx-ui-scene-080b55d0-aux-all
make gfx-ui-scene-080b55d0-aux-reference
make gfx-ui-scene-080b55d0-aux-patch-test
```

The normal ROM recipe rebuilds only these three selected streams after
`objcopy`. Unchanged sources reproduce their retail physical ranges exactly;
an edit is rejected if its Raw-LZ result exceeds the original slot.

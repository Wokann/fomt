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

The code also copies `0x200` bytes beginning at `gUnk_0872D5AC` into palette
memory, yet its declared assembly range is only `0x20` bytes. This crosses
multiple unclassified data boundaries, so the palette copy remains unmanaged.

```console
make gfx-ui-scene-080b55d0-aux-all
make gfx-ui-scene-080b55d0-aux-patch-test
```

The normal ROM recipe rebuilds only these three selected streams after
`objcopy`. Unchanged sources reproduce their retail physical ranges exactly;
an edit is rejected if its Raw-LZ result exceeds the original slot.

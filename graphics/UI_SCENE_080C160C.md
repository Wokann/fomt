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
| JP | `0x4C5530` | `0x4C5C14` |
| US | `0x73F3C8` | `0x73F6AC` |
| EU | `0x73F424` | `0x73F708` |
| DE | `0x4C683C` | `0x4C6B20` |

The adjoining code copies `0x200` bytes from `gUnk_087400E4` to palette
memory. Its declared assembly range ends after `0xC0` bytes at
`gUnk_087401A4`, so that copy crosses an unclassified boundary. It is not yet
safe to describe the span as one palette source or render it to a PNG. The
native tile and map sources are still lossless and independently editable.

```console
make gfx-ui-scene-080c160c-all
make gfx-ui-scene-080c160c-patch-test
```

The normal ROM recipe rebuilds the selected region's streams and patches only
their original intervals after `objcopy`. Unchanged sources reproduce retail
bytes exactly; changed sources use the proven Raw-LZ encoder and are rejected
if their fixed native slots are too small.

# `func_080B7164` BG resource set

`func_080B7164` directly unpacks two labelled 32-by-32 background tilemaps to
`0x0600F000` and `0x0600F800`, then loads a 4bpp tile source at
`0x06000000`. It configures BG controls `0x1F41` and `0x1E42` for those screen
blocks. The current native sources preserve exactly those proven streams.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x64` | `0x800` (32x32 u16 entries) | `030`, ladder `357` | `0x0600F000` |
| `layer_1.tilemap` | `0xA8` | `0x800` (32x32 u16 entries) | `030`, ladder `159` | `0x0600F800` |
| `tiles.4bpp` | `0x70C` | `0xEC0` (118 4bpp tiles) | `020`, ladder `2578101112` | `0x06000000` |

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4B3734` | `0x4B3840` |
| US | `0x72D5CC` | `0x72D6D8` |
| EU | `0x72D628` | `0x72D734` |
| DE | `0x4B48A0` | `0x4B49AC` |

The adjoining code copies 0x200 bytes from `gUnk_0872DDE4`, but that operation
crosses the following assembly boundary at `gUnk_0872DE44`. It is not yet safe
to call the range an isolated palette or render it as a source PNG. The native
tile and map sources remain useful and lossless without making that claim.

```console
make gfx-ui-scene-080b7164-all
make gfx-ui-scene-080b7164-patch-test
```

The normal ROM recipe rebuilds the selected region's streams and patches only
their original intervals after `objcopy`. Unchanged sources reproduce retail
bytes exactly; changed sources use the proven Raw-LZ encoder and are rejected
if their fixed native slots are too small.

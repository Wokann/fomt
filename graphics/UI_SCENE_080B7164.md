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

Immediately after these unpack operations, the same function copies exactly
`0x200` bytes from `gUnk_0872DDE4` to BG palette RAM (`0x05000000`). This is a
code-proven complete sixteen-bank BGR555 palette, rather than an inferred
adjacent data range. Its common four-region payload has SHA-256
`27d34fdaddf10393f59fb1f89ad87d10e8d1b3d06176d3870216e36fcf3b0750`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4B3F4C` | `0x200` |
| US | `0x72DDE4` | `0x200` |
| EU | `0x72DE40` | `0x200` |
| DE | `0x4B50B8` | `0x200` |

`shared/palettes.png` is the editable indexed source for those sixteen banks.
The native tilemaps remain the authoritative lossless layout source because
they retain tile IDs, X/Y flip flags, and palette-bank selectors. The generated
`reference/layer_0.png` and `reference/layer_1.png` are therefore genuine,
code-backed visual renderings of the two 256-by-256 BG layers.
`reference/scene.png` follows the routine's BG priority and treats index zero
as transparent in the upper layer, providing the readable combined scene.
These PNGs are references rather than a lossy replacement for the native
tilemaps. No JSON layout sidecar is used.

```console
make gfx-ui-scene-080b7164-all
make gfx-ui-scene-080b7164-preview
make gfx-ui-scene-080b7164-patch-test
```

The normal ROM recipe rebuilds the selected region's streams and patches only
their original intervals after `objcopy`. Unchanged sources reproduce retail
bytes exactly; changed sources use the proven Raw-LZ encoder and are rejected
if their fixed native slots are too small.

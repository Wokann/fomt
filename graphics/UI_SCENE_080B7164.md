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

Immediately after these unpack operations, the function copies `0x200` bytes
from `gUnk_0872DDE4` to BG palette RAM (`0x05000000`). The copy length is not
the ownership length: the two tilemaps select only palette banks 0, 1 and 2.
Those three banks occupy the first `0x60` bytes. At `+0x60`, the next indexed
resource archive begins; the remaining `0x1A0` copied bytes belong to that
archive, not to a fourth through sixteenth palette bank. The four-region
palette prefix has SHA-256
`556f3423f4da49c183dafea8575bba9330a4b4d3d5f9b3c11b31e360832955b3`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4B3F4C` | `0x60` |
| US | `0x72DDE4` | `0x60` |
| EU | `0x72DE40` | `0x60` |
| DE | `0x4B50B8` | `0x60` |

`shared/palettes.pal` is the independent JASC-PAL source for those three
banks. The generic `%.gbapal: %.pal` rule converts it beside the `.pal` file;
`reference/palettes.png` is only a viewable swatch, not a build input. Assembly
links the generated `.gbapal` at the original ROM position and retains the
`gUnk_0872DE44` archive label immediately afterward in the western layout.
The four-region retail SHA-256 above matches the directly linked palette.

The palette and archive are now separate source ranges despite the routine's
overlong hardware copy. The archive still has a separate post-link builder;
its migration into the ordinary linker path remains future work. No palette
source bytes overlap the archive, so editing a color does not alter archive
tables or pixel indices.

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
make fomt_jp fomt_us fomt_eu fomt_de
```

The C `fomt-lz` tool now rebuilds all three streams beside their editable
sources as `.tilemap.lz` and `.4bpp.lz` files. Assembly includes them directly
under `gUiTwoLayerBackgroundMap0`, `gUiTwoLayerBackgroundMap1`, and
`gUiTwoLayerBackgroundTiles`; the consuming literal pools use those symbols.
The three streams no longer use a baseline ROM or a post-`objcopy` patch in
the normal build. Their original slot sizes are checked during compression,
and unchanged sources produce byte-identical JP/US/EU/DE ROMs. The palette
no longer has its own post-link patch; the adjacent archive remains a
separate item to migrate.

# JP `func_08077810` resource group

This directory is intentionally separate from `../shared/`.  The Japanese
implementation reaches a different three-stream group through its preserved
regional intro-scene code:

| Source | JP ROM range | Native contract | Editable representation |
| --- | ---: | --- | --- |
| `tiles.4bpp.lz` | `0x4D4DDC..0x4D529C` | `0xC00` bytes, format `130`, ladder `1410` | `tiles.png`, 128×48 indexed 4bpp |
| `tiles.gbapal` | `0x4D529C..0x4D52BC` | one 16-colour BGR555 bank | palette embedded in `tiles.png` |
| `layer_1.tilemap.lz` | `0x4D52BC..0x4D5354` | `0x500` bytes, format `120`, ladder `12345610` | `layer_1.tilemap`, native 16-bit entries |

The following bytes through `0x4D7878` belong to a separate interval. The
three resources above are generated beside their editable sources with gbagfx
and the existing C codec, then included directly in the assembly at their
original labels. Their `.original.lz` files preserve the native byte layout.

This group is not a JP rendering of the US/EU/DE `scene_08077810` resources:
its source labels, decoded dimensions, palette, and codec boundaries differ.
No shared asset or full-screen composition is inferred from the matching
function address.

```console
make GAME_REGION=JP gfx-ui-scene-08077810-test
make -j4 fomt_jp
```

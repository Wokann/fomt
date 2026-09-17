# JP `func_08077810` resource group

This directory is intentionally separate from `../shared/`.  The Japanese
implementation reaches a different three-stream group through its preserved
regional intro-scene code:

| Source | JP ROM range | Native contract | Editable representation |
| --- | ---: | --- | --- |
| `tiles.0x70` | `0x4D4DDC..0x4D529C` | `0xC00` bytes, format `130`, ladder `1410` | `tiles.png`, 128×48 indexed 4bpp |
| `palette.gbapal` | `0x4D529C..0x4D52BC` | one 16-colour BGR555 bank | palette embedded in `tiles.png` |
| `layer_1.tilemap.0x70` | `0x4D52BC..0x4D5354` | `0x500` bytes, format `120`, ladder `12345610` | `layer_1.tilemap`, native 16-bit entries |

The following bytes through `0x4D7878` are a separate raw interval and remain
baseline data.  The tool writes only the proven `0x98`-byte compressed map
slot, so it cannot overwrite the following Animal Festival resources.

This group is not a JP rendering of the US/EU/DE `scene_08077810` resources:
its source labels, decoded dimensions, palette, and codec boundaries differ.
No shared asset or full-screen composition is inferred from the matching
function address.

```console
make gfx-ui-scene-08077810-all
make gfx-ui-scene-08077810-patch-test
make gfx-ui-scene-08077810-edit-test
```

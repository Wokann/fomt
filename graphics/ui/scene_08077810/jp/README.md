# JP `func_08077810` resource group

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

This directory is intentionally separate from `../shared/`.  The Japanese
implementation reaches a different three-stream group through its preserved
regional intro-scene code:

| Source | JP ROM range | Native contract | Editable representation |
| --- | ---: | --- | --- |
| `tiles.4bpp.lz` | `0x4D4DDC..0x4D529C` | `0xC00` bytes, format `130`, ladder `1410` | `tiles.png`, 128×48 indexed 4bpp |
| `tiles.gbapal` | `0x4D529C..0x4D52BC` | one 16-colour BGR555 bank | independent `tiles.pal` |
| `layer_1.tilemap.lz` | `0x4D52BC..0x4D5354` | `0x500` bytes, format `120`, ladder `12345610` | `layer_1.tilemap`, native 16-bit entries |

The following bytes through `0x4D7878` belong to a separate interval. The
three resources above are generated beside their editable sources with gbagfx
and the existing C codec, then included directly in the assembly at their
original labels. `tiles.4bpp.lz` is encoded directly from `tiles.4bpp` with
the tested C codec parameters, and its `.original.lz` file is now only a
packed-byte comparison reference. `layer_1.tilemap.lz` is also encoded directly
from `layer_1.tilemap`, using `encode-huff4-lz2 1,2,3,4,5,6,10 0 --tie=last`.
This general tie rule orders alphabetic leaves, selects the last-created node
among equal weights, and assigns canonical codes by depth then frequency.
Neither source rule reads a saved Huffman tree or the original packed stream;
the map's `.original.lz` is only a packed-byte comparison reference. The final
`0` in the map parameters requests the natural output size, not slot padding.

This group is not a JP rendering of the US/EU/DE `scene_08077810` resources:
its source labels, decoded dimensions, palette, and codec boundaries differ.
No shared asset or full-screen composition is inferred from the matching
function address.

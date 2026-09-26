# Regional resource `08738144`

`gUnk_08738144` is a `0x994`-byte IndexedResourceArchive in every region.
The selector, descriptor, OAM, palette, and final-index tables are identical;
only the 72 native 4bpp tiles differ across three source domains:

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Drawable groups / tiles / palettes |
| --- | --- | --- | ---: | --- | --- |
| `jp/` | JP | `0x4BE2AC` | `0x994` | `3, 3, 2, 72, 1, 0` | 3 / 72 / 1 |
| `us_eu/` | US / EU | `0x738144` / `0x7381A0` | `0x994` | `3, 3, 2, 72, 1, 0` | 3 / 72 / 1 |
| `de/` | DE | `0x4BF4B0` | `0x994` | `3, 3, 2, 72, 1, 0` | 3 / 72 / 1 |

Each `full/native.png` stores its 72 tiles in physical ROM order; root
`native.pal` stores the one palette shared across regions. Generic graphics
rules compile these sources to adjacent `.4bpp` and `.gbapal` products.
`archive.inc` links the common tables once and selects only the regional tile
stream at the original ROM position. JP and DE `group_*.png` files are old
OAM-composited reference views, not build inputs.

The previous US/EU build profile incorrectly used `0x731B40` / `0x731B9C`,
which are the starts of the preceding 20-group `gUnk_08731B40` archive. Its
20 group PNGs and 20 previews here were exact duplicates of that archive and
have been removed. The three-group US/EU archive starts *after* those `0x6604`
bytes, at the offsets in the table above.

The normal build neither reads a base ROM for this archive nor patches the
linked ROM afterward. Each native PNG and the palette round-trip byte-exactly,
and JP, US, EU, and DE complete ROM builds match their original SHA-1 values.

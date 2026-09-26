# Regional resource `0874F34C`

`gUnk_0874F34C` has 22 drawable OAM groups in every retail region but three
regional descriptor, OAM, and tile layouts. US and EU are byte-identical;
the selector table, three palettes, empty count, and final index are common
to all four regions.

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Groups / tiles / palettes |
| --- | --- | --- | ---: | --- | --- |
| `jp/` | JP | `0x4D5868` | `0xE24` | `22, 22, 3, 92, 3, 0` | 22 / 92 / 3 |
| `us_eu/` | US / EU | `0x74F34C` / `0x74F3A8` | `0x1394` | `22, 22, 9, 134, 3, 0` | 22 / 134 / 3 |
| `de/` | DE | `0x4D67B8` | `0x1444` | `22, 22, 7, 140, 3, 0` | 22 / 140 / 3 |

Each `full/native.png` stores its region's tiles in physical ROM order:
92 for JP, 134 for US/EU, and 140 for DE. Root `native.pal` stores the shared
48 colors. The ordinary graphics rules generate source-adjacent `.4bpp` and
`.gbapal` products; the JASC source declares exactly 48 colors. One
`archive.inc` places the common and regional tables around these products
in the original archive order without a JSON layout sidecar. The JP ROM
label and its code reference now use the
same `gUnk_0874F34C` symbol as the other regions.

`full/group_*.png` and `preview/` are old OAM-composited reference views,
not compilation inputs. Native PNG and PAL round trips recover every original
tile and color byte. The normal build directly links the tables and assets;
it neither rebuilds this archive from a base ROM nor patches the ROM after
linking. Complete JP, US, EU, and DE ROM builds match their original SHA-1.

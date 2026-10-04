# Regional resource `0871D51C`

This is one logical `IndexedResourceArchive` family with four independently
verified native layouts. It is not a shared payload:

| Region | ROM offset | Fixed length | Native groups / tiles / selections |
| --- | ---: | ---: | ---: |
| JP | `0x4A3678` | `0x1298` | 31 / 124 / 46 |
| US | `0x71D51C` | `0x128C` | 31 / 124 / 43 |
| EU | `0x71D578` | `0x128C` | 31 / 124 / 43 |
| DE | `0x4A45B8` | `0x13BC` | 33 / 132 / 47 |

Each region's `full/native.png` is the editable atlas in the archive's actual
4bpp tile order; `full/native.pal` is its single palette bank. The generic
graphics rules produce adjacent `.4bpp` and `.gbapal` files, which the original
assembly includes at the tile and palette positions. The selection, descriptor,
OAM and final index tables remain in physical order in that assembly. No ROM
input, separate archive builder or post-link patch is used in the normal build.

The atlas is two tiles (16 pixels) wide. Each four-tile icon therefore appears
as its two-by-two tile image, with consecutive icons stacked vertically.
JP/US/EU use 16-by-496 pixels, and DE uses 16-by-528 pixels. This replaces the
old four-tile-wide view without changing tile order, pixel indices, palette
values, or compiled archive bytes; the standard conversion rule is unchanged.

图集宽度为两个图块（16 像素），每个图标的四个图块按两行拼成完整图标，
后续图标依次向下排列。JP/US/EU 尺寸为 16×496，DE 为 16×528。
这只是将旧的四图块宽视图改为两图块宽视图，图块顺序、像素索引、
色板及编译后的归档字节均不变；仍使用原有通用转换规则。

`full/group_*.png` and `preview/` are OAM-composited references. They do not
retain the archive's native tile order and are not build inputs.

The US and EU payloads happen to be byte-identical at different ROM offsets,
but retain separate source directories so future localization-specific edits
cannot silently affect both builds. JP and DE have different descriptor, tile
and selection-table sizes; their assembly tables and native images preserve
those differences. All four ROM SHA-1 comparisons pass with this layout.

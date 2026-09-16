# `gUnk_08697920` native VRAM tile group

`func_080A748C` queues this complete `0x11E0`-byte range for DMA to
`0x06006E20`.  In 4bpp units that destination is tile `0x371`; the payload
contains 143 tiles and ends exactly at tile `0x3FF`, the end of its 1024-tile
character block.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x41DA7C` | `0x11E0` | `c96ae146f633dd5f3bf42dfb802ff294bdca0f5f4758150ac4896a543914be44` |
| US | `0x697920` | `0x11E0` | same |
| EU | `0x69797C` | `0x11E0` | same |
| DE | `0x41E9BC` | `0x11E0` | same |

`shared/tiles.4bpp` is the authoritative editable native source. It is kept
as a raw 4bpp byte stream because the currently proven code only establishes
the DMA destination and size. It does **not** establish a palette owner, a BG
tilemap, an OBJ OAM layout, or display priority. Therefore no arbitrary tile
grid, grayscale view, or guessed composite is checked in as source artwork.

The build emits the same fixed-size byte range for each selected region and
patches it after linking at the listed original offset. Unchanged source bytes
reproduce all four retail ranges exactly; the edit fixture changes one native
tile byte while retaining the exact `0x11E0`-byte boundary.

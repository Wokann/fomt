# Field renderer native VRAM tile variants

`func_080A748C` selects the three independent payloads below and DMA-copies
each selected payload to `0x06006E20`.  Each range is `0x11E0` bytes: 143
native 4bpp tiles that fill tile indices `0x371` through `0x3FF` of the same
1024-tile character block.  The selector conditions remain part of the field
renderer and have not been named here.

| Symbol | Editable source | JP | US | EU | DE | SHA-256 |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `gUnk_08698E14` | `08698e14/shared/tiles.4bpp` | `0x41EF70` | `0x698E14` | `0x698E70` | `0x41FEB0` | `06b60f66dfabae472ce929a164912c2e88ae4d8c468f6181db5a4304ce50e6bf` |
| `gUnk_0869A0A4` | `0869a0a4/shared/tiles.4bpp` | `0x420200` | `0x69A0A4` | `0x69A100` | `0x421140` | `69f5649e9bcb3da8816bab1a5155e7aecbd7a6757596e32bcdc07ecd199bda45` |

The following leading variants are also selected independently by the field
renderer. They DMA-copy to `0x06005FC0`, covering the 115 native 4bpp tiles
from `0x2FE` through `0x370`, immediately before the tail range above.

| Symbol | Editable source | JP | US | EU | DE | SHA-256 |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `gUnk_086D5508` | `086d5508/shared/tiles.4bpp` | `0x45B664` | `0x6D5508` | `0x6D5564` | `0x45C5A4` | `cdc8b2e5448f68894d102c8ca9c672ecd8a18f5932d5a932ff38411619c5ca28` |
| `gUnk_086D6698` | `086d6698/shared/tiles.4bpp` | `0x45C7F4` | `0x6D6698` | `0x6D66F4` | `0x45D734` | `6282b44093e405b3cdcd10a2ca0d6de388705f284cdb4376d6eff47b7f920786` |

All four retail ranges for each row are byte-identical.  The source files are
therefore shared rather than copied per region.  The native stream is the
authoritative editable source.  No palette, tilemap, OAM layout, or displayed
full-image PNG has been asserted: the proven code only establishes the source
range, byte count, and VRAM destination.  Build and post-link patch rules keep
each range fixed to its listed original regional boundary.

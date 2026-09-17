# Farm Status Harvest Sprite List tiles — BG slot `0x09C`

`func_080645F0` (Farm Status Harvest Sprite List) copies this `0x120`-byte
native 4bpp record to BG character RAM slot `0x09C` (`0x06001380`).  The
Earnings Report uses a different source, `gUnk_0875166C`, at the same slot;
the two records therefore are screen-local alternatives, not interchangeable
aliases.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D7758` | `0x120` | `c7a0b84c724745c4430e04c21fa72ebca8a52e9b769c2190ae01c21be4f5d89e` |
| US | `0x7517AC` | `0x120` | same |
| EU | `0x751808` | `0x120` | same |
| DE | `0x4D8CC8` | `0x120` | same |

`tiles.4bpp` is the authoritative fixed-size source.  No tilemap or final
screen composite has been inferred from its contiguous VRAM upload.

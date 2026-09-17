# Farm Status Harvest Sprite List tiles — BG slot `0x0A5`

`func_080645F0` (Farm Status Harvest Sprite List) copies this `0x120`-byte
native 4bpp record to BG character RAM slot `0x0A5` (`0x060014A0`).  The
Earnings Report uses a different source, `gUnk_087510AC`, at that same slot;
the two records are screen-local alternatives.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D6F38` | `0x120` | `fc2bda977d99c32f7fe6f8e480a47193d891ff65946dcbbbba85162e4146a331` |
| US | `0x750F8C` | `0x120` | same |
| EU | `0x750FE8` | `0x120` | same |
| DE | `0x4D84A8` | `0x120` | same |

`tiles.4bpp` is the authoritative fixed-size source.  The final tilemap
arrangement is not yet proven, so no guessed PNG composite is stored.

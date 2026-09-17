# Farm Status Harvest Sprite List native tiles

`func_080645F0` begins the Farm Status Harvest Sprite List screen.  It copies
this complete `0x120`-byte record to BG character RAM at `0x060015C0`; the
same screen immediately copies the companion `gUnk_08750F6C` record to BG
palette RAM at `0x05000060`.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D6DF8` | `0x120` | `a3b99c81ab8bac0912cd6c7d928f34f9bb739630701489b284e7ebf8e7fd047d` |
| US | `0x750E4C` | `0x120` | same |
| EU | `0x750EA8` | `0x120` | same |
| DE | `0x4D8368` | `0x120` | same |

`tiles.4bpp` is the authoritative editable source.  The renderer proves its
native tile format, exact size, palette companion and VRAM destination, but
does not yet prove the screen's BG tilemap arrangement.  It therefore must
remain a native source rather than a guessed PNG composite.

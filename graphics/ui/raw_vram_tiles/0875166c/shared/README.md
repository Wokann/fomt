# Farm Status Earnings Report native tiles

`func_0806644C` begins the Farm Status Earnings Report screen.  It copies
this complete `0x120`-byte record to BG character RAM at `0x06001380`; the
same screen immediately copies companion palette `gUnk_0875178C` to
`0x05000040`.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D7618` | `0x120` | `bbf625be269f793c6bbe13c09ac11bc6f851b41588f4439f921255a9cb15ce1a` |
| US | `0x75166C` | `0x120` | same |
| EU | `0x7516C8` | `0x120` | same |
| DE | `0x4D8B88` | `0x120` | same |

`tiles.4bpp` is the authoritative editable source.  The proven runtime path
does not reveal the final BG tilemap arrangement, so no inferred PNG composite
is checked in as a source asset.

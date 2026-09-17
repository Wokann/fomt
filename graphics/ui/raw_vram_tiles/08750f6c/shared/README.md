# Farm Status Harvest Sprite List palette

`func_080645F0` copies this exact `0x20`-byte BGR555 palette record to
`0x05000060` immediately after it has loaded the companion Harvest Sprite List
tile record, `gUnk_08750E4C`.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D6F18` | `0x20` | `9985d2bb7b07b88d53543f5ab323df57ac3eb3402671d800405dfdf4f9c18237` |
| US | `0x750F6C` | `0x20` | same |
| EU | `0x750FC8` | `0x20` | same |
| DE | `0x4D8488` | `0x20` | same |

`palette.gbapal` is the authoritative fixed-size source.  It is intentionally
not presented as a standalone PNG palette because the matching tilemap is not
yet proven.

# Farm Status Earnings Report palette

`func_0806644C` copies this exact `0x20`-byte BGR555 palette record to
`0x05000040` immediately after it has loaded companion Earnings Report tile
record `gUnk_0875166C`.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D7738` | `0x20` | `786cebe9ac9654a40caf028be177f840f8737b11fd1e5c6da5609f867ae48da4` |
| US | `0x75178C` | `0x20` | same |
| EU | `0x7517E8` | `0x20` | same |
| DE | `0x4D8CA8` | `0x20` | same |

`palette.gbapal` is the authoritative fixed-size source.  It remains separate
from a composite PNG until the matching tilemap is recovered from the screen
renderer.

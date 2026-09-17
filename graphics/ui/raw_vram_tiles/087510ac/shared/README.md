# Farm Status Earnings Report tiles — BG slot `0x0A5`

`func_0806644C` (Farm Status Earnings Report) copies this `0x120`-byte native
4bpp record to BG character RAM slot `0x0A5` (`0x060014A0`).  The Harvest
Sprite List selects distinct source `gUnk_08750F8C` for the same slot.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D7058` | `0x120` | `c477e41b27535552a2455bf44fa3b970cd335c9e5c8fe920f46959f871438583` |
| US | `0x7510AC` | `0x120` | same |
| EU | `0x751108` | `0x120` | same |
| DE | `0x4D85C8` | `0x120` | same |

`tiles.4bpp` is the authoritative fixed-size source; no final composite PNG
is accepted until the screen tilemap is independently recovered.

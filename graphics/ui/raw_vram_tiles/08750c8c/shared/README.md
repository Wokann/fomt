# Shared UI tiles — BG slot `0x150`

`func_0806644C` (Farm Status Earnings Report) and cooking-menu routines
`func_0809800C` / `func_0809964C` all consume this complete `0x1C0`-byte
native 4bpp record.  The Earnings Report loads it into BG character RAM slot
`0x150` (`0x06002A00`).  One caller consumes only its leading `0x1A0` bytes;
the source nevertheless retains the complete verified `0x1C0`-byte record.

| Region | ROM offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| JP | `0x4D6C38` | `0x1C0` | `2b7c39eab1900bb410cced0daa2ffd21055045e47ddcf99f318255775e77ec4f` |
| US | `0x750C8C` | `0x1C0` | same |
| EU | `0x750CE8` | `0x1C0` | same |
| DE | `0x4D81A8` | `0x1C0` | same |

`tiles.4bpp` is the authoritative fixed-size source.  Its screen tilemap
arrangement remains unproven and is not replaced with a speculative PNG.

# UI direct-DMA native tile groups

The consumers below call `func_08008F0C` with a named ROM source, literal
character-VRAM destination, and fixed byte count.  Every listed physical range
is byte-identical in the JP, US, EU, and DE retail ROMs, so each has one shared
native `.4bpp` source.

| Symbol | Source | Bytes | JP | US | EU | DE | SHA-256 |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `gUnk_08750C4C` | `08750c4c/shared/tiles.4bpp` | `0x20` | `0x4D6BF8` | `0x750C4C` | `0x750CA8` | `0x4D8168` | `e98672a456687f9c428628c321ff964b8507028878310d4e3eaebd3cfbe37e49` |
| `gUnk_08750C8C` | `08750c8c/shared/tiles.4bpp` | `0x1C0` | `0x4D6C38` | `0x750C8C` | `0x750CE8` | `0x4D81A8` | `2b7c39eab1900bb410cced0daa2ffd21055045e47ddcf99f318255775e77ec4f` |
| `gUnk_087510AC` | `087510ac/shared/tiles.4bpp` | `0x120` | `0x4D7058` | `0x7510AC` | `0x751108` | `0x4D85C8` | `c477e41b27535552a2455bf44fa3b970cd335c9e5c8fe920f46959f871438583` |
| `gUnk_0875166C` | `0875166c/shared/tiles.4bpp` | `0x120` | `0x4D7618` | `0x75166C` | `0x7516C8` | `0x4D8B88` | `bbf625be269f793c6bbe13c09ac11bc6f851b41588f4439f921255a9cb15ce1a` |

`gUnk_08750C8C` is copied in both `0x1A0`-byte and `0x1C0`-byte forms.  The
managed source therefore preserves its complete proven `0x1C0`-byte record;
the smaller call consumes its leading subrange.  The other three consumers
copy their complete listed record.

The sources are raw character tiles, not composited images.  No palette bank,
tilemap, OAM layout, or UI ownership is yet proven, so this pipeline
intentionally emits neither a guessed PNG nor a JSON layout sidecar.  Build
and post-link patch rules constrain every replacement to the listed original
regional range.

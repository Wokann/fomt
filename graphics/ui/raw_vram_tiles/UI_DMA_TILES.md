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
| `gUnk_087517AC` | `087517ac/shared/tiles.4bpp` | `0x120` | `0x4D7758` | `0x7517AC` | `0x751808` | `0x4D8CC8` | `c7a0b84c724745c4430e04c21fa72ebca8a52e9b769c2190ae01c21be4f5d89e` |
| `gUnk_08750F8C` | `08750f8c/shared/tiles.4bpp` | `0x120` | `0x4D6F38` | `0x750F8C` | `0x750FE8` | `0x4D84A8` | `fc2bda977d99c32f7fe6f8e480a47193d891ff65946dcbbbba85162e4146a331` |
| `gUnk_08750E4C` | `08750e4c/shared/tiles.4bpp` | `0x120` | `0x4D6DF8` | `0x750E4C` | `0x750EA8` | `0x4D8368` | `a3b99c81ab8bac0912cd6c7d928f34f9bb739630701489b284e7ebf8e7fd047d` |
| `gUnk_087511CC` | `087511cc/shared/tiles.4bpp` | `0x120` | `0x4D7178` | `0x7511CC` | `0x751228` | `0x4D86E8` | `0246e5f8a7ce9136217957ade7c5cfdbd2aa7be7f208a419b15a768c18963f75` |
| `gUnk_0875154C` | `0875154c/shared/tiles.4bpp` | `0x120` | `0x4D74F8` | `0x75154C` | `0x7515A8` | `0x4D8A68` | `acfc397f1fb7813b07fd714a306bb890cc4ccec2b94cee6ff10754408c7cebf6` |
| `gUnk_0875130C` | `0875130c/shared/tiles.4bpp` | `0x120` | `0x4D72B8` | `0x75130C` | `0x751368` | `0x4D8828` | `b078a388eb2836e81fa338079b4185f05f6a0f635ed977b2e1d8052a72b78777` |
| `gUnk_0875142C` | `0875142c/shared/tiles.4bpp` | `0x120` | `0x4D73D8` | `0x75142C` | `0x751488` | `0x4D8948` | `aa637cc310aea66cedff57eb3080b430e380c20703184036a73c2f87eba97dbb` |

`gUnk_08750C8C` is copied in both `0x1A0`-byte and `0x1C0`-byte forms.  The
managed source therefore preserves its complete proven `0x1C0`-byte record;
the smaller call consumes its leading subrange.  The remaining ten records are
each consumed in full by a direct DMA call.

The sources are raw character tiles, not composited images.  No palette bank,
tilemap, OAM layout, or UI ownership is yet proven, so this pipeline
intentionally emits neither a guessed PNG nor a JSON layout sidecar.  Build
and post-link patch rules constrain every replacement to the listed original
regional range.

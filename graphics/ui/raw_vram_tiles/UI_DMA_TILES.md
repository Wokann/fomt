# UI direct-DMA native graphics records

The consumers below call `func_08008F0C` with a named ROM source and fixed byte
count. Their targets are literal character VRAM except for four explicit
BGR555 palette-RAM uploads. Every listed physical range is byte-identical in
the JP, US, EU, and DE retail ROMs, so each has one shared native source.

| Symbol | Source | Bytes | JP | US | EU | DE | SHA-256 |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `gUnk_08750C8C` | `08750c8c/shared/tiles.4bpp` | `0x1C0` | `0x4D6C38` | `0x750C8C` | `0x750CE8` | `0x4D81A8` | `2b7c39eab1900bb410cced0daa2ffd21055045e47ddcf99f318255775e77ec4f` |
| `gUnk_087510AC` | `087510ac/shared/tiles.4bpp` | `0x120` | `0x4D7058` | `0x7510AC` | `0x751108` | `0x4D85C8` | `c477e41b27535552a2455bf44fa3b970cd335c9e5c8fe920f46959f871438583` |
| `gUnk_0875166C` | `0875166c/shared/tiles.4bpp` | `0x120` | `0x4D7618` | `0x75166C` | `0x7516C8` | `0x4D8B88` | `bbf625be269f793c6bbe13c09ac11bc6f851b41588f4439f921255a9cb15ce1a` |
| `gUnk_0875178C` | `0875178c/shared/palette.gbapal` | `0x20` | `0x4D7738` | `0x75178C` | `0x7517E8` | `0x4D8CA8` | `786cebe9ac9654a40caf028be177f840f8737b11fd1e5c6da5609f867ae48da4` |
| `gUnk_087517AC` | `087517ac/shared/tiles.4bpp` | `0x120` | `0x4D7758` | `0x7517AC` | `0x751808` | `0x4D8CC8` | `c7a0b84c724745c4430e04c21fa72ebca8a52e9b769c2190ae01c21be4f5d89e` |
| `gUnk_08750F6C` | `08750f6c/shared/palette.gbapal` | `0x20` | `0x4D6F18` | `0x750F6C` | `0x750FC8` | `0x4D8488` | `9985d2bb7b07b88d53543f5ab323df57ac3eb3402671d800405dfdf4f9c18237` |
| `gUnk_08750F8C` | `08750f8c/shared/tiles.4bpp` | `0x120` | `0x4D6F38` | `0x750F8C` | `0x750FE8` | `0x4D84A8` | `fc2bda977d99c32f7fe6f8e480a47193d891ff65946dcbbbba85162e4146a331` |
| `gUnk_08750E4C` | `08750e4c/shared/tiles.4bpp` | `0x120` | `0x4D6DF8` | `0x750E4C` | `0x750EA8` | `0x4D8368` | `a3b99c81ab8bac0912cd6c7d928f34f9bb739630701489b284e7ebf8e7fd047d` |
| `gUnk_087511CC` | `087511cc/shared/tiles.4bpp` | `0x120` | `0x4D7178` | `0x7511CC` | `0x751228` | `0x4D86E8` | `0246e5f8a7ce9136217957ade7c5cfdbd2aa7be7f208a419b15a768c18963f75` |
| `gUnk_0875154C` | `0875154c/shared/tiles.4bpp` | `0x120` | `0x4D74F8` | `0x75154C` | `0x7515A8` | `0x4D8A68` | `acfc397f1fb7813b07fd714a306bb890cc4ccec2b94cee6ff10754408c7cebf6` |
| `gUnk_0875130C` | `0875130c/shared/tiles.4bpp` | `0x120` | `0x4D72B8` | `0x75130C` | `0x751368` | `0x4D8828` | `b078a388eb2836e81fa338079b4185f05f6a0f635ed977b2e1d8052a72b78777` |
| `gUnk_0875142C` | `0875142c/shared/tiles.4bpp` | `0x120` | `0x4D73D8` | `0x75142C` | `0x751488` | `0x4D8948` | `aa637cc310aea66cedff57eb3080b430e380c20703184036a73c2f87eba97dbb` |
| `gUnk_08752DCC` | `08752dcc/shared/tiles.4bpp` | `0x20` | `0x4D8D78` | `0x752DCC` | `0x752E28` | `0x4DA2E8` | `edfe3b0dfa05ba559f7edb9dadc37610f2d68962dee6ebe21f4236e2da72f434` |
| `gUnk_08752B4C` | `08752b4c/shared/tiles.4bpp` | `0x20` | `0x4D8AF8` | `0x752B4C` | `0x752BA8` | `0x4DA068` | `fd2f2ed59600716e8751a9a95cd3a57e3305878909400c20a0790044862f38fd` |
| `gUnk_087529AC` | `087529ac/shared/tiles.4bpp` | `0x20` | `0x4D8958` | `0x7529AC` | `0x752A08` | `0x4D9EC8` | `e65a24b3b2280d111ba0d1236b82953023ef8eb4fc099ea4b3af5350d9c27214` |
| `gUnk_08752D4C` | `08752d4c/shared/tiles.4bpp` | `0x80` | `0x4D8CF8` | `0x752D4C` | `0x752DA8` | `0x4DA268` | `bbed8d40d3b50a112b0044f5cb15532a8373cd3979856ca2d420d71d65ae5dcf` |
| `gUnk_08752ACC` | `08752acc/shared/tiles.4bpp` | `0x80` | `0x4D8A78` | `0x752ACC` | `0x752B28` | `0x4D9FE8` | `544c753c94d191908294f5db94a19d1cec38b880dbc83c1bd46e53d38a8d7004` |
| `gUnk_08752A2C` | `08752a2c/shared/tiles.4bpp` | `0x20` | `0x4D89D8` | `0x752A2C` | `0x752A88` | `0x4D9F48` | `1eb989f756d8a797e4c33dbb012c7d4f1a3637dab164e4eab9fd867edfd2d532` |
| `gUnk_08752AAC` | `08752aac/shared/palette.gbapal` | `0x20` | `0x4D8A58` | `0x752AAC` | `0x752B08` | `0x4D9FC8` | `16651959cfb2129a001de5974a24772259962d7e5d22e88096280f1c57371186` |
| `gUnk_08752CCC` | `08752ccc/shared/tiles.4bpp` | `0x20` | `0x4D8C78` | `0x752CCC` | `0x752D28` | `0x4DA1E8` | `7ad0e85a313266549b865f289aed4f47dcfbd36e5d28ab1270b3729a86d0f5be` |
| `gUnk_08752BCC` | `08752bcc/shared/tiles.4bpp` | `0x20` | `0x4D8B78` | `0x752BCC` | `0x752C28` | `0x4DA0E8` | `bd19e0c23ddca6d07e9306ef5a9ba2c4f906e6e5aa6c1b4c45b0db65125e3ae8` |
| `gUnk_08752C4C` | `08752c4c/shared/tiles.4bpp` | `0x20` | `0x4D8BF8` | `0x752C4C` | `0x752CA8` | `0x4DA168` | `7cfc23dbe168b6540cfde63d355a87a45bcbff5d940529924641f9e1fdddb4c3` |

`gUnk_08750C8C` is copied in both `0x1A0`-byte and `0x1C0`-byte forms. The
managed source therefore preserves its complete proven `0x1C0`-byte record;
the smaller call consumes its leading subrange. `gUnk_0875290C` is deliberately
absent from this table because it is the complete ninth Farm Status icon record
and is owned by `farm_status/creature_icons/shared/icon_09.png`, together with
its adjacent `gUnk_0875298C` palette. A second manual audit confirms that the
remaining raw records include nineteen character-VRAM uploads and three
palette-RAM uploads. `gUnk_08750C4C` and its adjacent palette
`gUnk_08750C6C` are no longer raw records: their one-tile layout is proven
and they are managed by the Farm Status Harvest Sprite task tile PNG pipeline.
The final ten raw records are used by
the Farm Status UI. Nine are character-VRAM tile uploads; the exception is
`gUnk_08752AAC`, which `func_08068344` copies to `0x05000000` as one 16-colour
BGR555 palette record. The neighboring `gUnk_08752A2C` range is only consumed
as a `0x20`-byte tile subrange by that function, so no full-image layout is
inferred from their adjacency.

The remaining graphic records are raw character tiles and BGR555 palettes, not
composited images. No tilemap or OAM layout is yet proven, so this pipeline
intentionally emits neither a guessed PNG nor a JSON layout sidecar. Build and
post-link patch rules constrain every replacement to the listed original
regional range.

## Proven runtime scope, without invented layouts

The three adjacent records at the start of this group have enough caller
evidence to classify their scope, but not enough to derive a single authored
screen layout:

* `gUnk_08750C4C` and `gUnk_08750C6C` have moved to
  `graphics/ui/farm_status/harvest_sprite_task_ui_tile/shared/` as one
  editable 8x8 PNG source. `func_080645F0` and `func_0806644C` upload the
  one-tile 4bpp record together with its adjacent 16-colour BGR555 palette to
  OBJ tile and palette RAM. The shared caller path invokes
  `GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task`; this proves a complete
  Harvest Sprite task/experience UI tile rather than a guessed composite.
* `gUnk_08750C8C` is a 14-tile 4bpp sheet. It is loaded by the same Harvest
  Sprite path, by the cooking ingredient and recipe-screen constructors
  (`func_0809800C` and `func_0809964C`), and by two other UI constructors in
  `code_809E804.s`. It is consequently a shared UI glyph/tile sheet, not a
  resource belonging exclusively to either menu.

No caller above supplies a complete static BG tilemap and palette selection
for every use. The checked-in native `.4bpp` / `.gbapal` records are therefore
the authoritative editable source. A rendered PNG would be only a
context-specific reference, not a replacement source, until such a complete
layout is proven.

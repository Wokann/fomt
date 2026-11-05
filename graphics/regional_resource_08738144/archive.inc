    @ Common selector, descriptor, OAM, palette and index tables; regional native tiles.
    .word (.Lregional_resource_08738144_selections_end - .Lregional_resource_08738144_selections) / 4
.Lregional_resource_08738144_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
.Lregional_resource_08738144_selections_end:
    .word (.Lregional_resource_08738144_groups_end - .Lregional_resource_08738144_groups) / 16
.Lregional_resource_08738144_groups:
    .2byte 2, 0, 24, 0, 1, 0, 0, 0
    .2byte 2, 0, 24, 24, 1, 0, 0, 0
    .2byte 2, 0, 24, 48, 1, 0, 0, 0
.Lregional_resource_08738144_groups_end:
    .word (.Lregional_resource_08738144_sprites_end - .Lregional_resource_08738144_sprites) / 8
.Lregional_resource_08738144_sprites:
    .2byte 0, 32768, 0, 0
    .2byte 32768, 32800, 16, 0
.Lregional_resource_08738144_sprites_end:
    .word (.Lregional_resource_08738144_tiles_end - .Lregional_resource_08738144_tiles) / 32
.Lregional_resource_08738144_tiles:
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08738144/jp/full/native.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "graphics/regional_resource_08738144/de/full/native.4bpp"
    .else
    .incbin "graphics/regional_resource_08738144/us_eu/full/native.4bpp"
    .endif
    .endif
.Lregional_resource_08738144_tiles_end:
    .word (.Lregional_resource_08738144_palettes_end - .Lregional_resource_08738144_palettes) / 32
.Lregional_resource_08738144_palettes:
    .incbin "graphics/regional_resource_08738144/native.gbapal"
.Lregional_resource_08738144_palettes_end:
    .word (.Lregional_resource_08738144_sixth_end - .Lregional_resource_08738144_sixth) / 8
.Lregional_resource_08738144_sixth:
.Lregional_resource_08738144_sixth_end:
    .word (.Lregional_resource_08738144_entries_end - .Lregional_resource_08738144_entries) / 4
.Lregional_resource_08738144_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
.Lregional_resource_08738144_entries_end:

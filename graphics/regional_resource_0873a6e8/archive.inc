    @ Common archive tables and palette; DE selects its native tile stream.
    .word (.Lregional_resource_0873a6e8_selections_end - .Lregional_resource_0873a6e8_selections) / 4
.Lregional_resource_0873a6e8_selections:
    .2byte 1, 0
.Lregional_resource_0873a6e8_selections_end:
    .word (.Lregional_resource_0873a6e8_groups_end - .Lregional_resource_0873a6e8_groups) / 16
.Lregional_resource_0873a6e8_groups:
    .2byte 3, 0, 56, 0, 1, 0, 0, 0
.Lregional_resource_0873a6e8_groups_end:
    .word (.Lregional_resource_0873a6e8_sprites_end - .Lregional_resource_0873a6e8_sprites) / 8
.Lregional_resource_0873a6e8_sprites:
    .2byte 16384, 49152, 0, 0
    .2byte 0, 32832, 32, 0
    .2byte 32768, 32864, 48, 0
.Lregional_resource_0873a6e8_sprites_end:
    .word (.Lregional_resource_0873a6e8_tiles_end - .Lregional_resource_0873a6e8_tiles) / 32
.Lregional_resource_0873a6e8_tiles:
    .ifdef REGION_DE
    .incbin "graphics/regional_resource_0873a6e8/de/full/native.4bpp"
    .else
    .incbin "graphics/regional_resource_0873a6e8/shared/full/native.4bpp"
    .endif
.Lregional_resource_0873a6e8_tiles_end:
    .word (.Lregional_resource_0873a6e8_palettes_end - .Lregional_resource_0873a6e8_palettes) / 32
.Lregional_resource_0873a6e8_palettes:
    .incbin "graphics/regional_resource_0873a6e8/native.gbapal"
.Lregional_resource_0873a6e8_palettes_end:
    .word (.Lregional_resource_0873a6e8_sixth_end - .Lregional_resource_0873a6e8_sixth) / 8
.Lregional_resource_0873a6e8_sixth:
.Lregional_resource_0873a6e8_sixth_end:
    .word (.Lregional_resource_0873a6e8_entries_end - .Lregional_resource_0873a6e8_entries) / 4
.Lregional_resource_0873a6e8_entries:
    .2byte 0, 0
.Lregional_resource_0873a6e8_entries_end:

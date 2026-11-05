    @ One archive in original order; DE has an extra OAM entry and eight tiles.
    .word (.Lregional_resource_0873d6d8_selections_end - .Lregional_resource_0873d6d8_selections) / 4
.Lregional_resource_0873d6d8_selections:
    .2byte 1, 0

.Lregional_resource_0873d6d8_selections_end:
    .word (.Lregional_resource_0873d6d8_groups_end - .Lregional_resource_0873d6d8_groups) / 16
.Lregional_resource_0873d6d8_groups:
    .ifdef REGION_DE
    .2byte 4, 0, 64, 0, 1, 0, 0, 0
.Lregional_resource_0873d6d8_groups_end:
    .word (.Lregional_resource_0873d6d8_sprites_end - .Lregional_resource_0873d6d8_sprites) / 8
.Lregional_resource_0873d6d8_sprites:
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0
    .2byte 0x8000, 0x8070, 0x0038, 0
.Lregional_resource_0873d6d8_sprites_end:
    .word (.Lregional_resource_0873d6d8_tiles_end - .Lregional_resource_0873d6d8_tiles) / 32
.Lregional_resource_0873d6d8_tiles:
    .incbin "graphics/regional_resource_0873d6d8/de/full/native.4bpp"
    .else
    .2byte 3, 0, 56, 0, 1, 0, 0, 0
.Lregional_resource_0873d6d8_groups_end:
    .word (.Lregional_resource_0873d6d8_sprites_end - .Lregional_resource_0873d6d8_sprites) / 8
.Lregional_resource_0873d6d8_sprites:
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0
.Lregional_resource_0873d6d8_sprites_end:
    .word (.Lregional_resource_0873d6d8_tiles_end - .Lregional_resource_0873d6d8_tiles) / 32
.Lregional_resource_0873d6d8_tiles:
    .incbin "graphics/regional_resource_0873d6d8/shared/full/native.4bpp"
    .endif

.Lregional_resource_0873d6d8_tiles_end:
    .word (.Lregional_resource_0873d6d8_palettes_end - .Lregional_resource_0873d6d8_palettes) / 32
.Lregional_resource_0873d6d8_palettes:
    .incbin "graphics/regional_resource_0873d6d8/native.gbapal"
.Lregional_resource_0873d6d8_palettes_end:
    .word (.Lregional_resource_0873d6d8_sixth_end - .Lregional_resource_0873d6d8_sixth) / 8
.Lregional_resource_0873d6d8_sixth:
.Lregional_resource_0873d6d8_sixth_end:
    .word (.Lregional_resource_0873d6d8_entries_end - .Lregional_resource_0873d6d8_entries) / 4
.Lregional_resource_0873d6d8_entries:
    .2byte 0, 0
.Lregional_resource_0873d6d8_entries_end:

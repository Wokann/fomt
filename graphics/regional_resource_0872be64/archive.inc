    @ One source-owned archive at each original regional assembly position.
    @ DE has one extra OAM record and eight additional native tiles.
    .ifdef REGION_DE
    .word (.Lregional_resource_0872be64_selections_end - .Lregional_resource_0872be64_selections) / 4
.Lregional_resource_0872be64_selections:
    .2byte 1, 0

.Lregional_resource_0872be64_selections_end:
    .word (.Lregional_resource_0872be64_groups_end - .Lregional_resource_0872be64_groups) / 16
.Lregional_resource_0872be64_groups:
    .2byte 4, 0, 64, 0, 1, 0, 0, 0

.Lregional_resource_0872be64_groups_end:
    .word (.Lregional_resource_0872be64_sprites_end - .Lregional_resource_0872be64_sprites) / 8
.Lregional_resource_0872be64_sprites:
    .2byte 0x4000, 0xC000, 0x0000, 0x0000
    .2byte 0x0000, 0x8040, 0x0020, 0x0000
    .2byte 0x8000, 0x8060, 0x0030, 0x0000
    .2byte 0x8000, 0x8070, 0x0038, 0x0000

.Lregional_resource_0872be64_sprites_end:
    .word (.Lregional_resource_0872be64_tiles_end - .Lregional_resource_0872be64_tiles) / 32
.Lregional_resource_0872be64_tiles:
    .incbin "graphics/regional_resource_0872be64/de/full/native.4bpp"

.Lregional_resource_0872be64_tiles_end:
    .word (.Lregional_resource_0872be64_palettes_end - .Lregional_resource_0872be64_palettes) / 32
.Lregional_resource_0872be64_palettes:
    .incbin "graphics/regional_resource_0872be64/shared/full/native.gbapal"

.Lregional_resource_0872be64_palettes_end:
    .word (.Lregional_resource_0872be64_sixth_end - .Lregional_resource_0872be64_sixth) / 8
.Lregional_resource_0872be64_sixth:

.Lregional_resource_0872be64_sixth_end:
    .word (.Lregional_resource_0872be64_entries_end - .Lregional_resource_0872be64_entries) / 4
.Lregional_resource_0872be64_entries:
    .2byte 0, 0
.Lregional_resource_0872be64_entries_end:

    .else
    .word (.Lregional_resource_0872be64_selections_end - .Lregional_resource_0872be64_selections) / 4
.Lregional_resource_0872be64_selections:
    .2byte 1, 0

.Lregional_resource_0872be64_selections_end:
    .word (.Lregional_resource_0872be64_groups_end - .Lregional_resource_0872be64_groups) / 16
.Lregional_resource_0872be64_groups:
    .2byte 3, 0, 56, 0, 1, 0, 0, 0

.Lregional_resource_0872be64_groups_end:
    .word (.Lregional_resource_0872be64_sprites_end - .Lregional_resource_0872be64_sprites) / 8
.Lregional_resource_0872be64_sprites:
    .2byte 0x4000, 0xC000, 0x0000, 0x0000
    .2byte 0x0000, 0x8040, 0x0020, 0x0000
    .2byte 0x8000, 0x8060, 0x0030, 0x0000

.Lregional_resource_0872be64_sprites_end:
    .word (.Lregional_resource_0872be64_tiles_end - .Lregional_resource_0872be64_tiles) / 32
.Lregional_resource_0872be64_tiles:
    .incbin "graphics/regional_resource_0872be64/shared/full/native.4bpp"

.Lregional_resource_0872be64_tiles_end:
    .word (.Lregional_resource_0872be64_palettes_end - .Lregional_resource_0872be64_palettes) / 32
.Lregional_resource_0872be64_palettes:
    .incbin "graphics/regional_resource_0872be64/shared/full/native.gbapal"

.Lregional_resource_0872be64_palettes_end:
    .word (.Lregional_resource_0872be64_sixth_end - .Lregional_resource_0872be64_sixth) / 8
.Lregional_resource_0872be64_sixth:

.Lregional_resource_0872be64_sixth_end:
    .word (.Lregional_resource_0872be64_entries_end - .Lregional_resource_0872be64_entries) / 4
.Lregional_resource_0872be64_entries:
    .2byte 0, 0
.Lregional_resource_0872be64_entries_end:

    .endif

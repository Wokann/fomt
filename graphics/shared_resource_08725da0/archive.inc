    @ Four-region-identical native IndexedResourceArchive in ROM order.
    .word (.Lshared_resource_08725da0_selections_end - .Lshared_resource_08725da0_selections) / 4
.Lshared_resource_08725da0_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5

.Lshared_resource_08725da0_selections_end:
    .word (.Lshared_resource_08725da0_groups_end - .Lshared_resource_08725da0_groups) / 16
.Lshared_resource_08725da0_groups:
    .2byte 8, 0, 39, 0, 1, 0, 0, 0
    .2byte 8, 8, 48, 39, 1, 0, 0, 0
    .2byte 4, 16, 22, 87, 1, 0, 0, 0
    .2byte 8, 0, 39, 0, 1, 1, 0, 0
    .2byte 8, 8, 48, 39, 1, 1, 0, 0
    .2byte 4, 16, 22, 87, 1, 1, 0, 0

.Lshared_resource_08725da0_groups_end:
    .word (.Lshared_resource_08725da0_sprites_end - .Lshared_resource_08725da0_sprites) / 8
.Lshared_resource_08725da0_sprites:
    .2byte 0x4000, 0x8000, 0x0000, 0x0000
    .2byte 0x4000, 0x8020, 0x0008, 0x0000
    .2byte 0x4000, 0x8040, 0x0010, 0x0000
    .2byte 0x8000, 0x0060, 0x0018, 0x0000
    .2byte 0x4010, 0x4000, 0x001A, 0x0000
    .2byte 0x4010, 0x4020, 0x001E, 0x0000
    .2byte 0x4010, 0x4040, 0x0022, 0x0000
    .2byte 0x0010, 0x0060, 0x0026, 0x0000
    .2byte 0x4000, 0x8000, 0x0000, 0x0000
    .2byte 0x4000, 0x8020, 0x0008, 0x0000
    .2byte 0x4000, 0x8040, 0x0010, 0x0000
    .2byte 0x4000, 0x8060, 0x0018, 0x0000
    .2byte 0x4010, 0x4000, 0x0020, 0x0000
    .2byte 0x4010, 0x4020, 0x0024, 0x0000
    .2byte 0x4010, 0x4040, 0x0028, 0x0000
    .2byte 0x4010, 0x4060, 0x002C, 0x0000
    .2byte 0x4000, 0x8000, 0x0000, 0x0000
    .2byte 0x4000, 0x8020, 0x0008, 0x0000
    .2byte 0x0000, 0x4040, 0x0010, 0x0000
    .2byte 0x8000, 0x0050, 0x0014, 0x0000

.Lshared_resource_08725da0_sprites_end:
    .word (.Lshared_resource_08725da0_tiles_end - .Lshared_resource_08725da0_tiles) / 32
.Lshared_resource_08725da0_tiles:
    .incbin "graphics/shared_resource_08725da0/full/native.4bpp"

.Lshared_resource_08725da0_tiles_end:
    .word (.Lshared_resource_08725da0_palettes_end - .Lshared_resource_08725da0_palettes) / 32
.Lshared_resource_08725da0_palettes:
    .incbin "graphics/shared_resource_08725da0/full/native.gbapal"

.Lshared_resource_08725da0_palettes_end:
    .word (.Lshared_resource_08725da0_sixth_end - .Lshared_resource_08725da0_sixth) / 8
.Lshared_resource_08725da0_sixth:
.Lshared_resource_08725da0_sixth_end:
    .word (.Lshared_resource_08725da0_entries_end - .Lshared_resource_08725da0_entries) / 4
.Lshared_resource_08725da0_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0
.Lshared_resource_08725da0_entries_end:

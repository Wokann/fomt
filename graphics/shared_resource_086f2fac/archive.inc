    @ Native IndexedResourceArchive tables, followed by native-order tiles
    @ and four palette banks stored in one editable .pal file.
    .word (.Lshared_resource_086f2fac_selections_end - .Lshared_resource_086f2fac_selections) / 4
.Lshared_resource_086f2fac_selections:
    .2byte 4, 0
    .2byte 4, 4
    .2byte 4, 8
    .2byte 4, 12

.Lshared_resource_086f2fac_selections_end:
    .word (.Lshared_resource_086f2fac_groups_end - .Lshared_resource_086f2fac_groups) / 16
.Lshared_resource_086f2fac_groups:
    .2byte 2, 0, 24, 0, 1, 0, 0, 0
    .2byte 2, 0, 24, 24, 1, 0, 0, 0
    .2byte 2, 0, 24, 48, 1, 0, 0, 0
    .2byte 2, 0, 24, 72, 1, 0, 0, 0
    .2byte 2, 0, 24, 96, 1, 1, 0, 0
    .2byte 2, 0, 24, 120, 1, 1, 0, 0
    .2byte 2, 0, 24, 144, 1, 1, 0, 0
    .2byte 2, 0, 24, 168, 1, 1, 0, 0
    .2byte 2, 0, 24, 192, 1, 2, 0, 0
    .2byte 2, 0, 24, 216, 1, 2, 0, 0
    .2byte 2, 0, 24, 240, 1, 2, 0, 0
    .2byte 2, 0, 24, 264, 1, 2, 0, 0
    .2byte 2, 0, 24, 288, 1, 3, 0, 0
    .2byte 2, 0, 24, 312, 1, 3, 0, 0
    .2byte 2, 0, 24, 336, 1, 3, 0, 0
    .2byte 2, 0, 24, 360, 1, 3, 0, 0

.Lshared_resource_086f2fac_groups_end:
    .word (.Lshared_resource_086f2fac_sprites_end - .Lshared_resource_086f2fac_sprites) / 8
.Lshared_resource_086f2fac_sprites:
    .2byte 0, 0x8000, 0, 0
    .2byte 0x8000, 0x8020, 0x0010, 0

.Lshared_resource_086f2fac_sprites_end:
    .word (.Lshared_resource_086f2fac_tiles_end - .Lshared_resource_086f2fac_tiles) / 32
.Lshared_resource_086f2fac_tiles:
    .incbin "graphics/shared_resource_086f2fac/full/native.4bpp"

.Lshared_resource_086f2fac_tiles_end:
    .word (.Lshared_resource_086f2fac_palettes_end - .Lshared_resource_086f2fac_palettes) / 32
.Lshared_resource_086f2fac_palettes:
    .incbin "graphics/shared_resource_086f2fac/full/native.gbapal"

.Lshared_resource_086f2fac_palettes_end:
    .word (.Lshared_resource_086f2fac_sixth_end - .Lshared_resource_086f2fac_sixth) / 8
.Lshared_resource_086f2fac_sixth:
.Lshared_resource_086f2fac_sixth_end:
    .word (.Lshared_resource_086f2fac_entries_end - .Lshared_resource_086f2fac_entries) / 4
.Lshared_resource_086f2fac_entries:
    .2byte 0, 12
    .2byte 1, 12
    .2byte 2, 12
    .2byte 3, 12
    .2byte 4, 12
    .2byte 5, 12
    .2byte 6, 12
    .2byte 7, 12
    .2byte 8, 14
    .2byte 9, 14
    .2byte 10, 14
    .2byte 11, 14
    .2byte 12, 12
    .2byte 13, 12
    .2byte 14, 12
    .2byte 15, 12
.Lshared_resource_086f2fac_entries_end:

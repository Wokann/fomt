    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_086faa80_selections_end - .Lshared_resource_086faa80_selections) / 4
.Lshared_resource_086faa80_selections:
    .2byte 1, 0
    .2byte 4, 1
    .2byte 4, 5

.Lshared_resource_086faa80_selections_end:
    .word (.Lshared_resource_086faa80_groups_end - .Lshared_resource_086faa80_groups) / 16
.Lshared_resource_086faa80_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0
    .2byte 1, 0, 4, 24, 1, 0, 0, 0
    .2byte 1, 0, 4, 28, 1, 0, 0, 0
    .2byte 1, 0, 4, 32, 1, 0, 0, 0

.Lshared_resource_086faa80_groups_end:
    .word (.Lshared_resource_086faa80_sprites_end - .Lshared_resource_086faa80_sprites) / 8
.Lshared_resource_086faa80_sprites:
    .2byte 0, 16384, 3072, 0

.Lshared_resource_086faa80_sprites_end:
    .word (.Lshared_resource_086faa80_tiles_end - .Lshared_resource_086faa80_tiles) / 32
.Lshared_resource_086faa80_tiles:
    .incbin "graphics/shared_resource_086faa80/full/native.4bpp"

.Lshared_resource_086faa80_tiles_end:
    .word (.Lshared_resource_086faa80_palettes_end - .Lshared_resource_086faa80_palettes) / 32
.Lshared_resource_086faa80_palettes:
    .incbin "graphics/shared_resource_086faa80/full/native.gbapal"

.Lshared_resource_086faa80_palettes_end:
    .word (.Lshared_resource_086faa80_sixth_end - .Lshared_resource_086faa80_sixth) / 8
.Lshared_resource_086faa80_sixth:
.Lshared_resource_086faa80_sixth_end:
    .word (.Lshared_resource_086faa80_entries_end - .Lshared_resource_086faa80_entries) / 4
.Lshared_resource_086faa80_entries:
    .2byte 0, 4
    .2byte 1, 8
    .2byte 2, 8
    .2byte 3, 8
    .2byte 4, 8
    .2byte 5, 8
    .2byte 6, 8
    .2byte 7, 8
    .2byte 8, 8
.Lshared_resource_086faa80_entries_end:

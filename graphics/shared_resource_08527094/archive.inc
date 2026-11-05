    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_08527094_selections_end - .Lshared_resource_08527094_selections) / 4
.Lshared_resource_08527094_selections:
    .2byte 2, 0
    .2byte 2, 2
    .2byte 2, 4
    .2byte 2, 6

.Lshared_resource_08527094_selections_end:
    .word (.Lshared_resource_08527094_groups_end - .Lshared_resource_08527094_groups) / 16
.Lshared_resource_08527094_groups:
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 1, 1, 1, 1, 0, 0, 0
    .2byte 1, 2, 1, 0, 1, 0, 0, 0
    .2byte 1, 3, 1, 1, 1, 0, 0, 0
    .2byte 1, 4, 1, 2, 1, 0, 0, 0
    .2byte 1, 1, 1, 3, 1, 0, 0, 0
    .2byte 1, 5, 1, 2, 1, 0, 0, 0
    .2byte 1, 6, 1, 3, 1, 0, 0, 0

.Lshared_resource_08527094_groups_end:
    .word (.Lshared_resource_08527094_sprites_end - .Lshared_resource_08527094_sprites) / 8
.Lshared_resource_08527094_sprites:
    .2byte 1, 0, 0, 0
    .2byte 0, 0, 0, 0
    .2byte 255, 8192, 0, 0
    .2byte 0, 8192, 0, 0
    .2byte 0, 511, 0, 0
    .2byte 0, 4097, 0, 0
    .2byte 0, 4096, 0, 0

.Lshared_resource_08527094_sprites_end:
    .word (.Lshared_resource_08527094_tiles_end - .Lshared_resource_08527094_tiles) / 32
.Lshared_resource_08527094_tiles:
    .incbin "graphics/shared_resource_08527094/full/native.4bpp"

.Lshared_resource_08527094_tiles_end:
    .word (.Lshared_resource_08527094_palettes_end - .Lshared_resource_08527094_palettes) / 32
.Lshared_resource_08527094_palettes:
    .incbin "graphics/shared_resource_08527094/full/native.gbapal"

.Lshared_resource_08527094_palettes_end:
    .word (.Lshared_resource_08527094_sixth_end - .Lshared_resource_08527094_sixth) / 8
.Lshared_resource_08527094_sixth:
.Lshared_resource_08527094_sixth_end:
    .word (.Lshared_resource_08527094_entries_end - .Lshared_resource_08527094_entries) / 4
.Lshared_resource_08527094_entries:
    .2byte 0, 12
    .2byte 1, 12
    .2byte 2, 12
    .2byte 3, 12
    .2byte 4, 12
    .2byte 5, 12
    .2byte 6, 12
    .2byte 7, 12
.Lshared_resource_08527094_entries_end:

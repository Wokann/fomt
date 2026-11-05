    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_087506e0_selections_end - .Lshared_resource_087506e0_selections) / 4
.Lshared_resource_087506e0_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3

.Lshared_resource_087506e0_selections_end:
    .word (.Lshared_resource_087506e0_groups_end - .Lshared_resource_087506e0_groups) / 16
.Lshared_resource_087506e0_groups:
    .2byte 3, 0, 8, 0, 1, 0, 0, 0
    .2byte 4, 3, 9, 8, 1, 0, 0, 0
    .2byte 3, 0, 8, 17, 1, 0, 0, 0
    .2byte 3, 7, 11, 25, 1, 0, 0, 0

.Lshared_resource_087506e0_groups_end:
    .word (.Lshared_resource_087506e0_sprites_end - .Lshared_resource_087506e0_sprites) / 8
.Lshared_resource_087506e0_sprites:
    .2byte 0, 16384, 0, 0
    .2byte 32768, 16, 4, 0
    .2byte 16400, 0, 6, 0
    .2byte 0, 16384, 0, 0
    .2byte 32768, 16, 4, 0
    .2byte 16400, 0, 6, 0
    .2byte 16, 16, 8, 0
    .2byte 16638, 32768, 0, 0
    .2byte 16398, 0, 8, 0
    .2byte 14, 16, 10, 0

.Lshared_resource_087506e0_sprites_end:
    .word (.Lshared_resource_087506e0_tiles_end - .Lshared_resource_087506e0_tiles) / 32
.Lshared_resource_087506e0_tiles:
    .incbin "graphics/shared_resource_087506e0/full/native.4bpp"

.Lshared_resource_087506e0_tiles_end:
    .word (.Lshared_resource_087506e0_palettes_end - .Lshared_resource_087506e0_palettes) / 32
.Lshared_resource_087506e0_palettes:
    .incbin "graphics/shared_resource_087506e0/full/native.gbapal"

.Lshared_resource_087506e0_palettes_end:
    .word (.Lshared_resource_087506e0_sixth_end - .Lshared_resource_087506e0_sixth) / 8
.Lshared_resource_087506e0_sixth:
.Lshared_resource_087506e0_sixth_end:
    .word (.Lshared_resource_087506e0_entries_end - .Lshared_resource_087506e0_entries) / 4
.Lshared_resource_087506e0_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
.Lshared_resource_087506e0_entries_end:

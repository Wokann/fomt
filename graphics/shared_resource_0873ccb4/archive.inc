    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0873ccb4_selections_end - .Lshared_resource_0873ccb4_selections) / 4
.Lshared_resource_0873ccb4_selections:
    .2byte 2, 0

.Lshared_resource_0873ccb4_selections_end:
    .word (.Lshared_resource_0873ccb4_groups_end - .Lshared_resource_0873ccb4_groups) / 16
.Lshared_resource_0873ccb4_groups:
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0

.Lshared_resource_0873ccb4_groups_end:
    .word (.Lshared_resource_0873ccb4_sprites_end - .Lshared_resource_0873ccb4_sprites) / 8
.Lshared_resource_0873ccb4_sprites:
    .2byte 0x00F5, 0x41FD, 0, 0
    .2byte 0x80F5, 0x000D, 4, 0

.Lshared_resource_0873ccb4_sprites_end:
    .word (.Lshared_resource_0873ccb4_tiles_end - .Lshared_resource_0873ccb4_tiles) / 32
.Lshared_resource_0873ccb4_tiles:
    .incbin "graphics/shared_resource_0873ccb4/full/native.4bpp"

.Lshared_resource_0873ccb4_tiles_end:
    .word (.Lshared_resource_0873ccb4_palettes_end - .Lshared_resource_0873ccb4_palettes) / 32
.Lshared_resource_0873ccb4_palettes:
    .incbin "graphics/shared_resource_0873ccb4/full/native.gbapal"

.Lshared_resource_0873ccb4_palettes_end:
    .word (.Lshared_resource_0873ccb4_sixth_end - .Lshared_resource_0873ccb4_sixth) / 8
.Lshared_resource_0873ccb4_sixth:
.Lshared_resource_0873ccb4_sixth_end:
    .word (.Lshared_resource_0873ccb4_entries_end - .Lshared_resource_0873ccb4_entries) / 4
.Lshared_resource_0873ccb4_entries:
    .2byte 0, 0
    .2byte 1, 0
.Lshared_resource_0873ccb4_entries_end:

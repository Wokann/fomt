    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0873d234_selections_end - .Lshared_resource_0873d234_selections) / 4
.Lshared_resource_0873d234_selections:
    .2byte 2, 0
    .2byte 2, 2
    .2byte 2, 4

.Lshared_resource_0873d234_selections_end:
    .word (.Lshared_resource_0873d234_groups_end - .Lshared_resource_0873d234_groups) / 16
.Lshared_resource_0873d234_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0

.Lshared_resource_0873d234_groups_end:
    .word (.Lshared_resource_0873d234_sprites_end - .Lshared_resource_0873d234_sprites) / 8
.Lshared_resource_0873d234_sprites:
    .2byte 0, 0x4000, 0, 0

.Lshared_resource_0873d234_sprites_end:
    .word (.Lshared_resource_0873d234_tiles_end - .Lshared_resource_0873d234_tiles) / 32
.Lshared_resource_0873d234_tiles:
    .incbin "graphics/shared_resource_0873d234/full/native.4bpp"

.Lshared_resource_0873d234_tiles_end:
    .word (.Lshared_resource_0873d234_palettes_end - .Lshared_resource_0873d234_palettes) / 32
.Lshared_resource_0873d234_palettes:
    .incbin "graphics/shared_resource_0873d234/full/native.gbapal"

.Lshared_resource_0873d234_palettes_end:
    .word (.Lshared_resource_0873d234_sixth_end - .Lshared_resource_0873d234_sixth) / 8
.Lshared_resource_0873d234_sixth:
.Lshared_resource_0873d234_sixth_end:
    .word (.Lshared_resource_0873d234_entries_end - .Lshared_resource_0873d234_entries) / 4
.Lshared_resource_0873d234_entries:
    .2byte 0, 0x28
    .2byte 1, 0x28
    .2byte 2, 0x0C
    .2byte 3, 0x0C
    .2byte 4, 0x08
    .2byte 5, 0x08
.Lshared_resource_0873d234_entries_end:

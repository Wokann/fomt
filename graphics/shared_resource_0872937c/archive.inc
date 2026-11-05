    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0872937c_selections_end - .Lshared_resource_0872937c_selections) / 4
.Lshared_resource_0872937c_selections:
    .2byte 3, 0

.Lshared_resource_0872937c_selections_end:
    .word (.Lshared_resource_0872937c_groups_end - .Lshared_resource_0872937c_groups) / 16
.Lshared_resource_0872937c_groups:
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0

.Lshared_resource_0872937c_groups_end:
    .word (.Lshared_resource_0872937c_sprites_end - .Lshared_resource_0872937c_sprites) / 8
.Lshared_resource_0872937c_sprites:
    .2byte 0x00F8, 0x01FD, 0, 0

.Lshared_resource_0872937c_sprites_end:
    .word (.Lshared_resource_0872937c_tiles_end - .Lshared_resource_0872937c_tiles) / 32
.Lshared_resource_0872937c_tiles:
    .incbin "graphics/shared_resource_0872937c/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0872937c/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0872937c/full/group_002.4bpp"

.Lshared_resource_0872937c_tiles_end:
    .word (.Lshared_resource_0872937c_palettes_end - .Lshared_resource_0872937c_palettes) / 32
.Lshared_resource_0872937c_palettes:
    .incbin "graphics/shared_resource_0872937c/full/group_000.gbapal"

.Lshared_resource_0872937c_palettes_end:
    .word (.Lshared_resource_0872937c_sixth_end - .Lshared_resource_0872937c_sixth) / 8
.Lshared_resource_0872937c_sixth:
.Lshared_resource_0872937c_sixth_end:
    .word (.Lshared_resource_0872937c_entries_end - .Lshared_resource_0872937c_entries) / 4
.Lshared_resource_0872937c_entries:
    .2byte 0, 8
    .2byte 1, 8
    .2byte 2, 8
.Lshared_resource_0872937c_entries_end:

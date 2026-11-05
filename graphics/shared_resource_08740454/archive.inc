    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_08740454_selections_end - .Lshared_resource_08740454_selections) / 4
.Lshared_resource_08740454_selections:
    .hword 3, 0

.Lshared_resource_08740454_selections_end:
    .word (.Lshared_resource_08740454_groups_end - .Lshared_resource_08740454_groups) / 16
.Lshared_resource_08740454_groups:
    .2byte 2, 0, 2, 0, 1, 0, 0, 0
    .2byte 2, 0, 2, 2, 1, 0, 0, 0
    .2byte 2, 0, 2, 4, 1, 0, 0, 0

.Lshared_resource_08740454_groups_end:
    .word (.Lshared_resource_08740454_sprites_end - .Lshared_resource_08740454_sprites) / 8
.Lshared_resource_08740454_sprites:
    .2byte 33016, 496, 0, 0
    .2byte 33016, 4104, 0, 0

.Lshared_resource_08740454_sprites_end:
    .word (.Lshared_resource_08740454_tiles_end - .Lshared_resource_08740454_tiles) / 32
.Lshared_resource_08740454_tiles:
    .incbin "graphics/shared_resource_08740454/full/native.4bpp"

.Lshared_resource_08740454_tiles_end:
    .word (.Lshared_resource_08740454_palettes_end - .Lshared_resource_08740454_palettes) / 32
.Lshared_resource_08740454_palettes:
    .incbin "graphics/shared_resource_08740454/full/native.gbapal"

.Lshared_resource_08740454_palettes_end:
    .word (.Lshared_resource_08740454_sixth_end - .Lshared_resource_08740454_sixth) / 8
.Lshared_resource_08740454_sixth:
.Lshared_resource_08740454_sixth_end:
    .word (.Lshared_resource_08740454_entries_end - .Lshared_resource_08740454_entries) / 4
.Lshared_resource_08740454_entries:
    .2byte 0, 4
    .2byte 1, 4
    .2byte 2, 4
.Lshared_resource_08740454_entries_end:

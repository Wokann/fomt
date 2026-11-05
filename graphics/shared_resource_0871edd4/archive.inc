    @ The adjacent five-entry IndexedResourceArchive uses the same native
    @ seven-table layout as 0871ECAC, with a different selector and entries.
    .word (.Lshared_resource_0871edd4_selections_end - .Lshared_resource_0871edd4_selections) / 4
.Lshared_resource_0871edd4_selections:
    .2byte 5, 0

.Lshared_resource_0871edd4_selections_end:
    .word (.Lshared_resource_0871edd4_groups_end - .Lshared_resource_0871edd4_groups) / 16
.Lshared_resource_0871edd4_groups:
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0
    .2byte 1, 0, 1, 3, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

.Lshared_resource_0871edd4_groups_end:
    .word (.Lshared_resource_0871edd4_sprites_end - .Lshared_resource_0871edd4_sprites) / 8
.Lshared_resource_0871edd4_sprites:
    .2byte 0x00FC, 0x01FC, 0, 0

.Lshared_resource_0871edd4_sprites_end:
    .word (.Lshared_resource_0871edd4_tiles_end - .Lshared_resource_0871edd4_tiles) / 32
.Lshared_resource_0871edd4_tiles:
    .incbin "graphics/shared_resource_0871edd4/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_003.4bpp"

.Lshared_resource_0871edd4_tiles_end:
    .word (.Lshared_resource_0871edd4_palettes_end - .Lshared_resource_0871edd4_palettes) / 32
.Lshared_resource_0871edd4_palettes:
    .incbin "graphics/shared_resource_0871edd4/full/group_000.gbapal"

.Lshared_resource_0871edd4_palettes_end:
    .word (.Lshared_resource_0871edd4_sixth_end - .Lshared_resource_0871edd4_sixth) / 8
.Lshared_resource_0871edd4_sixth:
.Lshared_resource_0871edd4_sixth_end:
    .word (.Lshared_resource_0871edd4_entries_end - .Lshared_resource_0871edd4_entries) / 4
.Lshared_resource_0871edd4_entries:
    .2byte 0, 16, 1, 10, 2, 12, 3, 14, 4, 24
.Lshared_resource_0871edd4_entries_end:

    @ IndexedResourceArchive: one selector, five descriptors, one OAM entry,
    @ four native 4bpp tiles, one shared palette, no sixth-table entries,
    @ and four selection entries. Kept in ROM table order.
    .word (.Lshared_resource_0871ecac_selections_end - .Lshared_resource_0871ecac_selections) / 4
.Lshared_resource_0871ecac_selections:
    .2byte 4, 0

.Lshared_resource_0871ecac_selections_end:
    .word (.Lshared_resource_0871ecac_groups_end - .Lshared_resource_0871ecac_groups) / 16
.Lshared_resource_0871ecac_groups:
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0
    .2byte 1, 0, 1, 3, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

.Lshared_resource_0871ecac_groups_end:
    .word (.Lshared_resource_0871ecac_sprites_end - .Lshared_resource_0871ecac_sprites) / 8
.Lshared_resource_0871ecac_sprites:
    .2byte 0x00FC, 0x01FC, 0, 0

.Lshared_resource_0871ecac_sprites_end:
    .word (.Lshared_resource_0871ecac_tiles_end - .Lshared_resource_0871ecac_tiles) / 32
.Lshared_resource_0871ecac_tiles:
    .incbin "graphics/shared_resource_0871ecac/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_003.4bpp"

.Lshared_resource_0871ecac_tiles_end:
    .word (.Lshared_resource_0871ecac_palettes_end - .Lshared_resource_0871ecac_palettes) / 32
.Lshared_resource_0871ecac_palettes:
    .incbin "graphics/shared_resource_0871ecac/full/group_000.gbapal"

.Lshared_resource_0871ecac_palettes_end:
    .word (.Lshared_resource_0871ecac_sixth_end - .Lshared_resource_0871ecac_sixth) / 8
.Lshared_resource_0871ecac_sixth:
.Lshared_resource_0871ecac_sixth_end:
    .word (.Lshared_resource_0871ecac_entries_end - .Lshared_resource_0871ecac_entries) / 4
.Lshared_resource_0871ecac_entries:
    .2byte 0, 6, 1, 6, 2, 6, 3, 8
.Lshared_resource_0871ecac_entries_end:

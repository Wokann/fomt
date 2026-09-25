    @ IndexedResourceArchive: one selector, five descriptors, one OAM entry,
    @ four native 4bpp tiles, one shared palette, no sixth-table entries,
    @ and four selection entries. Kept in ROM table order.
    .4byte 1
    .2byte 4, 0

    .4byte 5
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0
    .2byte 1, 0, 1, 3, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

    .4byte 1
    .2byte 0x00FC, 0x01FC, 0, 0

    .4byte 4
    .incbin "graphics/shared_resource_0871ecac/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0871ecac/full/group_003.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0871ecac/full/group_000.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 6, 1, 6, 2, 6, 3, 8

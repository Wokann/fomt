    @ The adjacent five-entry IndexedResourceArchive uses the same native
    @ seven-table layout as 0871ECAC, with a different selector and entries.
    .4byte 1
    .2byte 5, 0

    .4byte 5
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0
    .2byte 1, 0, 1, 3, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

    .4byte 1
    .2byte 0x00FC, 0x01FC, 0, 0

    .4byte 4
    .incbin "graphics/shared_resource_0871edd4/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0871edd4/full/group_003.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0871edd4/full/group_000.gbapal"

    .4byte 0
    .4byte 5
    .2byte 0, 16, 1, 10, 2, 12, 3, 14, 4, 24

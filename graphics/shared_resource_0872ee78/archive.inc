    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 4
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3

    .4byte 4
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0

    .4byte 1
    .2byte 0, 0x4000, 0, 0

    .4byte 16
    .incbin "graphics/shared_resource_0872ee78/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0872ee78/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0872ee78/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0872ee78/full/group_003.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0872ee78/full/group_000.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0

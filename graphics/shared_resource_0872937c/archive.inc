    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 3, 0

    .4byte 3
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 0, 1, 1, 1, 0, 0, 0
    .2byte 1, 0, 1, 2, 1, 0, 0, 0

    .4byte 1
    .2byte 0x00F8, 0x01FD, 0, 0

    .4byte 3
    .incbin "graphics/shared_resource_0872937c/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0872937c/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0872937c/full/group_002.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0872937c/full/group_000.gbapal"

    .4byte 0
    .4byte 3
    .2byte 0, 8
    .2byte 1, 8
    .2byte 2, 8

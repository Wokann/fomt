    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .2byte 2, 0, 4, 0, 1, 0, 0, 0

    .4byte 2
    .2byte 0x4000, 0, 0, 0
    .2byte 0x4008, 0, 2, 0

    .4byte 4
    .incbin "graphics/shared_resource_0873ceac/full/group_000.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0873ceac/full/group_000.gbapal"

    .4byte 0
    .4byte 1
    .2byte 0, 0

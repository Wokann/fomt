    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .2byte 3, 0, 56, 0, 1, 0, 0, 0

    .4byte 3
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0

    .4byte 56
    .incbin "graphics/shared_resource_0873e5b0/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0873e5b0/full/native.gbapal"

    .4byte 0
    .4byte 1
    .2byte 0, 0

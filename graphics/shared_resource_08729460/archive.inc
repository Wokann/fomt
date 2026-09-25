    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 3, 0

    .4byte 3
    .2byte 9, 0, 110, 0, 1, 0, 0, 0
    .2byte 9, 0, 110, 110, 1, 0, 0, 0
    .2byte 9, 0, 110, 220, 1, 0, 0, 0

    .4byte 9
    .2byte 0x0000, 0xC000, 0x0000, 0
    .2byte 0x8000, 0x8040, 0x0040, 0
    .2byte 0x8020, 0x8040, 0x0048, 0
    .2byte 0x4040, 0x8000, 0x0050, 0
    .2byte 0x4040, 0x8020, 0x0058, 0
    .2byte 0x0040, 0x4040, 0x0060, 0
    .2byte 0x4050, 0x4000, 0x0064, 0
    .2byte 0x4050, 0x4020, 0x0068, 0
    .2byte 0x4050, 0x0040, 0x006C, 0

    .4byte 330
    .incbin "graphics/shared_resource_08729460/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_08729460/full/native.gbapal"

    .4byte 0
    .4byte 3
    .2byte 0, 4
    .2byte 1, 4
    .2byte 2, 4

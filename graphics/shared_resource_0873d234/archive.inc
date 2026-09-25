    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 3
    .2byte 2, 0
    .2byte 2, 2
    .2byte 2, 4

    .4byte 6
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0

    .4byte 1
    .2byte 0, 0x4000, 0, 0

    .4byte 24
    .incbin "graphics/shared_resource_0873d234/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0873d234/full/native.gbapal"

    .4byte 0
    .4byte 6
    .2byte 0, 0x28
    .2byte 1, 0x28
    .2byte 2, 0x0C
    .2byte 3, 0x0C
    .2byte 4, 0x08
    .2byte 5, 0x08

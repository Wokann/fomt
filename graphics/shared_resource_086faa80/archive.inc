    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 3
    .2byte 1, 0
    .2byte 4, 1
    .2byte 4, 5

    .4byte 9
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0
    .2byte 1, 0, 4, 24, 1, 0, 0, 0
    .2byte 1, 0, 4, 28, 1, 0, 0, 0
    .2byte 1, 0, 4, 32, 1, 0, 0, 0

    .4byte 1
    .2byte 0, 16384, 3072, 0

    .4byte 36
    .incbin "graphics/shared_resource_086faa80/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_086faa80/full/native.gbapal"

    .4byte 0
    .4byte 9
    .2byte 0, 4
    .2byte 1, 8
    .2byte 2, 8
    .2byte 3, 8
    .2byte 4, 8
    .2byte 5, 8
    .2byte 6, 8
    .2byte 7, 8
    .2byte 8, 8

    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 4
    .2byte 2, 0
    .2byte 2, 2
    .2byte 2, 4
    .2byte 2, 6

    .4byte 8
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 1, 1, 1, 1, 0, 0, 0
    .2byte 1, 2, 1, 0, 1, 0, 0, 0
    .2byte 1, 3, 1, 1, 1, 0, 0, 0
    .2byte 1, 4, 1, 2, 1, 0, 0, 0
    .2byte 1, 1, 1, 3, 1, 0, 0, 0
    .2byte 1, 5, 1, 2, 1, 0, 0, 0
    .2byte 1, 6, 1, 3, 1, 0, 0, 0

    .4byte 7
    .2byte 1, 0, 0, 0
    .2byte 0, 0, 0, 0
    .2byte 255, 8192, 0, 0
    .2byte 0, 8192, 0, 0
    .2byte 0, 511, 0, 0
    .2byte 0, 4097, 0, 0
    .2byte 0, 4096, 0, 0

    .4byte 4
    .incbin "graphics/shared_resource_08527094/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_08527094/full/native.gbapal"

    .4byte 0
    .4byte 8
    .2byte 0, 12
    .2byte 1, 12
    .2byte 2, 12
    .2byte 3, 12
    .2byte 4, 12
    .2byte 5, 12
    .2byte 6, 12
    .2byte 7, 12

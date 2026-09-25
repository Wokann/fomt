    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 4
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3

    .4byte 4
    .2byte 3, 0, 8, 0, 1, 0, 0, 0
    .2byte 4, 3, 9, 8, 1, 0, 0, 0
    .2byte 3, 0, 8, 17, 1, 0, 0, 0
    .2byte 3, 7, 11, 25, 1, 0, 0, 0

    .4byte 10
    .2byte 0, 16384, 0, 0
    .2byte 32768, 16, 4, 0
    .2byte 16400, 0, 6, 0
    .2byte 0, 16384, 0, 0
    .2byte 32768, 16, 4, 0
    .2byte 16400, 0, 6, 0
    .2byte 16, 16, 8, 0
    .2byte 16638, 32768, 0, 0
    .2byte 16398, 0, 8, 0
    .2byte 14, 16, 10, 0

    .4byte 36
    .incbin "graphics/shared_resource_087506e0/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_087506e0/full/native.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0

    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .4byte 3

    .4byte 3
    .2byte 2, 0, 2, 0, 1, 0, 0, 0
    .2byte 2, 0, 2, 2, 1, 0, 0, 0
    .2byte 2, 0, 2, 4, 1, 0, 0, 0

    .4byte 2
    .2byte 33016, 496, 0, 0
    .2byte 33016, 4104, 0, 0

    .4byte 6
    .incbin "graphics/shared_resource_08740454/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_08740454/full/native.gbapal"

    .4byte 0
    .4byte 3
    .2byte 0, 4
    .2byte 1, 4
    .2byte 2, 4

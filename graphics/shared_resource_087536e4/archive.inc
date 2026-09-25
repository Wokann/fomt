    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 2
    .2byte 2, 0
    .2byte 2, 2

    .4byte 4
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 1, 1, 0, 1, 0, 0, 0
    .2byte 1, 2, 1, 1, 1, 0, 0, 0
    .2byte 1, 1, 1, 1, 1, 0, 0, 0

    .4byte 3
    .2byte 1, 0, 0, 0
    .2byte 0, 0, 0, 0
    .2byte 255, 0, 0, 0

    .4byte 2
    .incbin "graphics/shared_resource_087536e4/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_087536e4/full/native.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 16
    .2byte 1, 12
    .2byte 2, 16
    .2byte 3, 12

    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 2
    .2byte 1, 0
    .2byte 1, 0

    .4byte 1
    .2byte 2, 0, 24, 0, 1, 0, 0, 0

    .4byte 2
    .2byte 0, 32768, 0, 0
    .2byte 32768, 32800, 16, 0

    .4byte 24
    .incbin "graphics/shared_resource_087405a0/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_087405a0/full/native.gbapal"

    .4byte 0
    .4byte 1
    .2byte 0, 0

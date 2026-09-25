    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 2, 0

    .4byte 2
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0

    .4byte 2
    .2byte 0x00F5, 0x41FD, 0, 0
    .2byte 0x80F5, 0x000D, 4, 0

    .4byte 12
    .incbin "graphics/shared_resource_0873ccb4/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_0873ccb4/full/native.gbapal"

    .4byte 0
    .4byte 2
    .2byte 0, 0
    .2byte 1, 0

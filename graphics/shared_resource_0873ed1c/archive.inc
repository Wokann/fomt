    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 3
    .2byte 4, 0
    .2byte 4, 4
    .2byte 3, 8

    .4byte 10
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 2, 1, 6, 4, 1, 0, 0, 0
    .2byte 1, 3, 4, 10, 1, 0, 0, 0
    .2byte 1, 4, 1, 14, 1, 0, 0, 0
    .2byte 1, 5, 4, 15, 1, 1, 0, 0
    .2byte 1, 6, 4, 19, 1, 1, 0, 0
    .2byte 1, 7, 4, 23, 1, 1, 0, 0
    .2byte 2, 8, 6, 27, 1, 1, 0, 0
    .2byte 1, 10, 4, 33, 1, 1, 0, 0
    .2byte 1, 10, 4, 37, 1, 1, 0, 0

    .4byte 11
    .2byte 0x00F3, 0x4007, 0, 0
    .2byte 0x00F0, 0x400D, 0, 0
    .2byte 0x80F0, 0x001D, 4, 0
    .2byte 0x00F3, 0x401A, 0, 0
    .2byte 0x00F8, 0, 0, 0
    .2byte 0x00F4, 0x41ED, 0, 0
    .2byte 0x00F5, 0x41EA, 0, 0
    .2byte 0x00F3, 0x41E8, 0, 0
    .2byte 0x00F8, 0x41F7, 0, 0
    .2byte 0x80F8, 0x0007, 4, 0
    .2byte 0x00F2, 0x41F6, 0, 0

    .4byte 41
    .incbin "graphics/shared_resource_0873ed1c/full/native.4bpp"

    .4byte 2
    .incbin "graphics/shared_resource_0873ed1c/full/palettes.gbapal"

    .4byte 0
    .4byte 11
    .2byte 0, 6
    .2byte 1, 6
    .2byte 2, 6
    .2byte 3, 6
    .2byte 5, 9
    .2byte 6, 9
    .2byte 3, 9
    .2byte 4, 9
    .2byte 7, 8
    .2byte 8, 8
    .2byte 9, 8

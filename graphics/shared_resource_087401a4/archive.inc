    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .4byte 4

    .4byte 4
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 1, 4, 4, 1, 0, 0, 0
    .2byte 1, 2, 4, 8, 1, 0, 0, 0
    .2byte 1, 3, 4, 12, 1, 0, 0, 0

    .4byte 4
    .2byte 224, 16880, 0, 0
    .2byte 226, 16886, 0, 0
    .2byte 228, 16890, 0, 0
    .2byte 230, 16893, 0, 0

    .4byte 16
    .incbin "graphics/shared_resource_087401a4/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_087401a4/full/native.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 6
    .2byte 1, 6
    .2byte 2, 6
    .2byte 3, 6

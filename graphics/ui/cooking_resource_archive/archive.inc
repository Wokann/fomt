    @ Cooking UI IndexedResourceArchive in physical ROM order.
    .4byte 1
    .2byte 4, 0

    .4byte 3
    .2byte 3, 0, 20, 0, 1, 0, 0, 0
    .2byte 3, 0, 20, 20, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

    .4byte 3
    .2byte 0x4000, 0x8000, 0, 0
    .2byte 0x4000, 0x8020, 8, 0
    .2byte 0, 0x4040, 16, 0

    .4byte 40
    .incbin "graphics/ui/cooking_resource_archive/full/native.4bpp"

    .4byte 1
    .incbin "graphics/ui/cooking_resource_archive/full/native.gbapal"

    .4byte 0
    .4byte 4
    .2byte 0, 20, 1, 10, 2, 12, 1, 10

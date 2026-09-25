    @ Native IndexedResourceArchive tables in physical ROM order.
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .2byte 9, 0, 48, 0, 1, 0, 0, 0

    .4byte 9
    .2byte 228, 33252, 0, 0
    .2byte 32996, 32772, 16, 0
    .2byte 32996, 16404, 24, 0
    .2byte 16388, 33252, 28, 0
    .2byte 4, 16388, 36, 0
    .2byte 32772, 20, 40, 0
    .2byte 16404, 16868, 42, 0
    .2byte 16404, 4, 46, 0
    .2byte 20, 20, 0, 0

    .4byte 48
    .incbin "graphics/shared_resource_08726ccc/full/native.4bpp"

    .4byte 1
    .incbin "graphics/shared_resource_08726ccc/full/native.gbapal"

    .4byte 0
    .4byte 1
    .2byte 0, 0

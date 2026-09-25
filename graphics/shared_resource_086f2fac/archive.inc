    @ Native IndexedResourceArchive tables, followed by native-order tiles
    @ and four palette banks stored in one editable .pal file.
    .4byte 4
    .2byte 4, 0
    .2byte 4, 4
    .2byte 4, 8
    .2byte 4, 12

    .4byte 16
    .2byte 2, 0, 24, 0, 1, 0, 0, 0
    .2byte 2, 0, 24, 24, 1, 0, 0, 0
    .2byte 2, 0, 24, 48, 1, 0, 0, 0
    .2byte 2, 0, 24, 72, 1, 0, 0, 0
    .2byte 2, 0, 24, 96, 1, 1, 0, 0
    .2byte 2, 0, 24, 120, 1, 1, 0, 0
    .2byte 2, 0, 24, 144, 1, 1, 0, 0
    .2byte 2, 0, 24, 168, 1, 1, 0, 0
    .2byte 2, 0, 24, 192, 1, 2, 0, 0
    .2byte 2, 0, 24, 216, 1, 2, 0, 0
    .2byte 2, 0, 24, 240, 1, 2, 0, 0
    .2byte 2, 0, 24, 264, 1, 2, 0, 0
    .2byte 2, 0, 24, 288, 1, 3, 0, 0
    .2byte 2, 0, 24, 312, 1, 3, 0, 0
    .2byte 2, 0, 24, 336, 1, 3, 0, 0
    .2byte 2, 0, 24, 360, 1, 3, 0, 0

    .4byte 2
    .2byte 0, 0x8000, 0, 0
    .2byte 0x8000, 0x8020, 0x0010, 0

    .4byte 384
    .incbin "graphics/shared_resource_086f2fac/full/native.4bpp"

    .4byte 4
    .incbin "graphics/shared_resource_086f2fac/full/native.gbapal"

    .4byte 0
    .4byte 16
    .2byte 0, 12
    .2byte 1, 12
    .2byte 2, 12
    .2byte 3, 12
    .2byte 4, 12
    .2byte 5, 12
    .2byte 6, 12
    .2byte 7, 12
    .2byte 8, 14
    .2byte 9, 14
    .2byte 10, 14
    .2byte 11, 14
    .2byte 12, 12
    .2byte 13, 12
    .2byte 14, 12
    .2byte 15, 12

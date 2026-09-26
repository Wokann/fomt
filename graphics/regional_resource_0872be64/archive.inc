    @ One source-owned archive at each original regional assembly position.
    @ DE has one extra OAM record and eight additional native tiles.
    .ifdef REGION_DE
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .2byte 4, 0, 64, 0, 1, 0, 0, 0

    .4byte 4
    .2byte 0x4000, 0xC000, 0x0000, 0x0000
    .2byte 0x0000, 0x8040, 0x0020, 0x0000
    .2byte 0x8000, 0x8060, 0x0030, 0x0000
    .2byte 0x8000, 0x8070, 0x0038, 0x0000

    .4byte 64
    .incbin "graphics/regional_resource_0872be64/de/full/native.4bpp"

    .4byte 1
    .incbin "graphics/regional_resource_0872be64/shared/full/native.gbapal"

    .4byte 0

    .4byte 1
    .2byte 0, 0

    .else
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .2byte 3, 0, 56, 0, 1, 0, 0, 0

    .4byte 3
    .2byte 0x4000, 0xC000, 0x0000, 0x0000
    .2byte 0x0000, 0x8040, 0x0020, 0x0000
    .2byte 0x8000, 0x8060, 0x0030, 0x0000

    .4byte 56
    .incbin "graphics/regional_resource_0872be64/shared/full/native.4bpp"

    .4byte 1
    .incbin "graphics/regional_resource_0872be64/shared/full/native.gbapal"

    .4byte 0

    .4byte 1
    .2byte 0, 0

    .endif

    @ One archive in original order; DE has an extra OAM entry and eight tiles.
    .4byte 1
    .2byte 1, 0

    .4byte 1
    .ifdef REGION_DE
    .2byte 4, 0, 64, 0, 1, 0, 0, 0
    .4byte 4
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0
    .2byte 0x8000, 0x8070, 0x0038, 0
    .4byte 64
    .incbin "graphics/regional_resource_0873d6d8/de/full/native.4bpp"
    .else
    .2byte 3, 0, 56, 0, 1, 0, 0, 0
    .4byte 3
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0
    .4byte 56
    .incbin "graphics/regional_resource_0873d6d8/shared/full/native.4bpp"
    .endif

    .4byte 1
    .incbin "graphics/regional_resource_0873d6d8/native.gbapal"
    .4byte 0
    .4byte 1
    .2byte 0, 0

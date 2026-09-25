    @ One selection, three descriptors/OAM records, four shared tiles.
    .4byte 1
    .2byte 4, 0

    .4byte 3
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 1, 4, 0, 1, 0, 0, 0
    .2byte 1, 2, 4, 0, 1, 0, 0, 0

    .4byte 3
    .2byte 0x00FB, 0x41F0, 0, 0
    .2byte 0x00FB, 0x41F1, 0, 0
    .2byte 0x00FB, 0x41F2, 0, 0

    .4byte 4
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08728208/jp/full/group_000.4bpp"
    .else
    .incbin "graphics/regional_resource_08728208/overseas/full/group_000.4bpp"
    .endif

    .4byte 1
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08728208/jp/full/group_000.gbapal"
    .else
    .incbin "graphics/regional_resource_08728208/overseas/full/group_000.gbapal"
    .endif

    .4byte 0
    .4byte 4
    .2byte 0, 6
    .2byte 1, 6
    .2byte 2, 6
    .2byte 1, 6

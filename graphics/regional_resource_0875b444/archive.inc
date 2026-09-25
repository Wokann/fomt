    @ Six-group IndexedResourceArchive. PNG tiles and palette are built by
    @ the shared graphics suffix rules; tables stay in native ROM order.
    .4byte 6
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5

    .4byte 6
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0

    .4byte 1
    .2byte 0, 0x4000, 0, 0

    .4byte 24
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_0875b444/jp/full/group_000.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_001.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_002.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_003.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_004.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_005.4bpp"
    .else
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_000.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_001.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_002.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_003.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_004.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_005.4bpp"
    .endif

    .4byte 1
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_0875b444/jp/full/group_000.gbapal"
    .else
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_000.gbapal"
    .endif

    .4byte 0
    .4byte 6
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0

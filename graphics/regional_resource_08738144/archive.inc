    @ Common selector, descriptor, OAM, palette and index tables; regional native tiles.
    .4byte 3
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .4byte 3
    .2byte 2, 0, 24, 0, 1, 0, 0, 0
    .2byte 2, 0, 24, 24, 1, 0, 0, 0
    .2byte 2, 0, 24, 48, 1, 0, 0, 0
    .4byte 2
    .2byte 0, 32768, 0, 0
    .2byte 32768, 32800, 16, 0
    .4byte 72
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08738144/jp/full/native.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "graphics/regional_resource_08738144/de/full/native.4bpp"
    .else
    .incbin "graphics/regional_resource_08738144/us_eu/full/native.4bpp"
    .endif
    .endif
    .4byte 1
    .incbin "graphics/regional_resource_08738144/native.gbapal"
    .4byte 0
    .4byte 3
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0

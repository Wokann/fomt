    @ Common archive tables and palette; DE selects its native tile stream.
    .4byte 1
    .2byte 1, 0
    .4byte 1
    .2byte 3, 0, 56, 0, 1, 0, 0, 0
    .4byte 3
    .2byte 16384, 49152, 0, 0
    .2byte 0, 32832, 32, 0
    .2byte 32768, 32864, 48, 0
    .4byte 56
    .ifdef REGION_DE
    .incbin "graphics/regional_resource_0873a6e8/de/full/native.4bpp"
    .else
    .incbin "graphics/regional_resource_0873a6e8/shared/full/native.4bpp"
    .endif
    .4byte 1
    .incbin "graphics/regional_resource_0873a6e8/native.gbapal"
    .4byte 0
    .4byte 1
    .2byte 0, 0

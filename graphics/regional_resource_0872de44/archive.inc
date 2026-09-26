    @ The 27 selectors, palette and final index are identical in all regions.
    @ Only descriptors, OAM and native tiles differ in DE.
    .4byte 27
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5
    .2byte 1, 6
    .2byte 1, 7
    .2byte 1, 8
    .2byte 1, 9
    .2byte 1, 10
    .2byte 1, 11
    .2byte 1, 12
    .2byte 1, 13
    .2byte 1, 14
    .2byte 1, 15
    .2byte 1, 16
    .2byte 1, 17
    .2byte 1, 18
    .2byte 1, 19
    .2byte 1, 20
    .2byte 1, 21
    .2byte 1, 22
    .2byte 1, 23
    .2byte 1, 24
    .2byte 1, 25
    .2byte 1, 26

    .4byte 27
    .ifdef REGION_DE
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0
    .2byte 2, 0, 6, 12, 1, 0, 0, 0
    .2byte 2, 0, 6, 18, 1, 0, 0, 0
    .2byte 2, 0, 6, 24, 1, 0, 0, 0
    .2byte 2, 0, 6, 30, 1, 0, 0, 0
    .2byte 2, 0, 6, 36, 1, 0, 0, 0
    .2byte 2, 0, 6, 42, 1, 0, 0, 0
    .2byte 2, 0, 6, 48, 1, 0, 0, 0
    .2byte 2, 0, 6, 54, 1, 0, 0, 0
    .2byte 1, 2, 1, 60, 1, 0, 0, 0
    .2byte 1, 0, 4, 61, 1, 0, 0, 0
    .2byte 1, 3, 2, 65, 1, 0, 0, 0
    .2byte 1, 3, 2, 67, 1, 0, 0, 0
    .2byte 1, 3, 2, 69, 1, 0, 0, 0
    .2byte 1, 3, 2, 71, 1, 0, 0, 0
    .2byte 1, 3, 2, 73, 1, 0, 0, 0
    .2byte 1, 3, 2, 75, 1, 0, 0, 0
    .2byte 1, 3, 2, 77, 1, 0, 0, 0
    .2byte 1, 3, 2, 79, 1, 0, 0, 0
    .2byte 1, 3, 2, 81, 1, 0, 0, 0
    .2byte 1, 3, 2, 83, 1, 0, 0, 0
    .2byte 1, 2, 1, 85, 1, 0, 0, 0
    .2byte 1, 3, 2, 86, 1, 0, 0, 0
    .2byte 2, 4, 6, 88, 1, 0, 0, 0
    .2byte 2, 4, 6, 94, 1, 0, 0, 0
    .2byte 3, 6, 10, 100, 1, 0, 0, 0
    .else
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0
    .2byte 2, 0, 6, 12, 1, 0, 0, 0
    .2byte 2, 0, 6, 18, 1, 0, 0, 0
    .2byte 2, 0, 6, 24, 1, 0, 0, 0
    .2byte 2, 0, 6, 30, 1, 0, 0, 0
    .2byte 2, 0, 6, 36, 1, 0, 0, 0
    .2byte 2, 0, 6, 42, 1, 0, 0, 0
    .2byte 2, 0, 6, 48, 1, 0, 0, 0
    .2byte 2, 0, 6, 54, 1, 0, 0, 0
    .2byte 1, 2, 1, 60, 1, 0, 0, 0
    .2byte 1, 0, 4, 61, 1, 0, 0, 0
    .2byte 1, 3, 2, 65, 1, 0, 0, 0
    .2byte 1, 3, 2, 67, 1, 0, 0, 0
    .2byte 1, 3, 2, 69, 1, 0, 0, 0
    .2byte 1, 3, 2, 71, 1, 0, 0, 0
    .2byte 1, 3, 2, 73, 1, 0, 0, 0
    .2byte 1, 3, 2, 75, 1, 0, 0, 0
    .2byte 1, 3, 2, 77, 1, 0, 0, 0
    .2byte 1, 3, 2, 79, 1, 0, 0, 0
    .2byte 1, 3, 2, 81, 1, 0, 0, 0
    .2byte 1, 3, 2, 83, 1, 0, 0, 0
    .2byte 1, 2, 1, 85, 1, 0, 0, 0
    .2byte 1, 3, 2, 86, 1, 0, 0, 0
    .2byte 2, 4, 6, 88, 1, 0, 0, 0
    .2byte 2, 4, 6, 94, 1, 0, 0, 0
    .2byte 2, 4, 6, 100, 1, 0, 0, 0
    .endif

    .ifdef REGION_DE
    .4byte 9
    .2byte 0x0000, 0x4000, 0x0000, 0x0000
    .2byte 0x4010, 0x0000, 0x0004, 0x0000
    .2byte 0x0000, 0x0000, 0x0000, 0x0000
    .2byte 0x8000, 0x0000, 0x0000, 0x0000
    .2byte 0x0000, 0x4000, 0x0000, 0x0000
    .2byte 0x8000, 0x0010, 0x0004, 0x0000
    .2byte 0x0000, 0x4000, 0x0000, 0x0000
    .2byte 0x8000, 0x0010, 0x0004, 0x0000
    .2byte 0x0000, 0x4018, 0x0006, 0x0000
    .4byte 110
    .incbin "graphics/regional_resource_0872de44/de/full/native.4bpp"
    .else
    .4byte 6
    .2byte 0x0000, 0x4000, 0x0000, 0x0000
    .2byte 0x4010, 0x0000, 0x0004, 0x0000
    .2byte 0x0000, 0x0000, 0x0000, 0x0000
    .2byte 0x8000, 0x0000, 0x0000, 0x0000
    .2byte 0x0000, 0x4000, 0x0000, 0x0000
    .2byte 0x8000, 0x0010, 0x0004, 0x0000
    .4byte 106
    .incbin "graphics/regional_resource_0872de44/shared/full/native.4bpp"
    .endif

    .4byte 1
    .incbin "graphics/regional_resource_0872de44/shared/full/native.gbapal"
    .4byte 0
    .4byte 27
    .2byte 0, 1
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0
    .2byte 6, 0
    .2byte 7, 0
    .2byte 8, 0
    .2byte 9, 0
    .2byte 10, 0
    .2byte 11, 0
    .2byte 12, 0
    .2byte 13, 0
    .2byte 14, 0
    .2byte 15, 0
    .2byte 16, 0
    .2byte 17, 0
    .2byte 18, 0
    .2byte 19, 0
    .2byte 20, 0
    .2byte 21, 0
    .2byte 22, 0
    .2byte 23, 0
    .2byte 24, 0
    .2byte 25, 0
    .2byte 26, 0

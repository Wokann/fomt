    @ JP Intro Scene IndexedResourceArchive: seven native tables.
    @ Format 120, ladder 36810121315; decoded SHA-256 f59d0e0791ea60134b32239b3108c09bfc53de6e384f024b7a0288df2af0c58a.
    @ Separate native 8bpp title and 4bpp frame PNGs preserve every tile.
    @ Complete OAM frame PNGs are references, not competing build inputs.

    @ Table 1: 9 records, 4 bytes each.
    .4byte 9
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 4, 3
    .2byte 2, 7
    .2byte 1, 9
    .2byte 4, 10
    .2byte 2, 14
    .2byte 1, 16

    @ Table 2: 11 records, 16 bytes each.
    .4byte 11
    .2byte 13, 0, 270, 0, 16, 0, 0, 0
    .2byte 10, 13, 452, 270, 16, 0, 0, 0
    .2byte 3, 23, 20, 722, 1, 16, 0, 0
    .2byte 3, 26, 20, 722, 1, 16, 0, 0
    .2byte 3, 29, 20, 722, 1, 16, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0
    .2byte 3, 23, 20, 742, 1, 16, 0, 0
    .2byte 3, 26, 20, 742, 1, 16, 0, 0
    .2byte 3, 29, 20, 742, 1, 16, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0
    .2byte 6, 32, 48, 762, 1, 17, 0, 0

    @ Table 3: 38 records, 8 bytes each.
    .4byte 38
    .2byte 24586, 49580, 0, 0
    .2byte 24586, 49644, 64, 0
    .2byte 24618, 33196, 128, 0
    .2byte 24618, 33228, 144, 0
    .2byte 24618, 33260, 160, 0
    .2byte 24618, 32780, 176, 0
    .2byte 8202, 32812, 192, 0
    .2byte 40970, 16460, 224, 0
    .2byte 24618, 32812, 232, 0
    .2byte 41002, 76, 248, 0
    .2byte 24578, 16860, 252, 0
    .2byte 24578, 16892, 260, 0
    .2byte 8194, 28, 268, 0
    .2byte 8416, 49632, 0, 0
    .2byte 8416, 49184, 128, 0
    .2byte 8416, 49568, 256, 0
    .2byte 41184, 32864, 384, 0
    .2byte 8192, 16480, 400, 0
    .2byte 41192, 16496, 408, 0
    .2byte 41184, 33168, 416, 0
    .2byte 41192, 16776, 432, 0
    .2byte 8192, 16784, 440, 0
    .2byte 24592, 400, 448, 0
    .2byte 16384, 32768, 0, 0
    .2byte 16384, 32800, 8, 0
    .2byte 0, 16448, 16, 0
    .2byte 16385, 32768, 0, 0
    .2byte 16385, 32800, 8, 0
    .2byte 1, 16448, 16, 0
    .2byte 16386, 32768, 0, 0
    .2byte 16386, 32800, 8, 0
    .2byte 2, 16448, 16, 0
    .2byte 16384, 33184, 0, 0
    .2byte 16384, 33216, 8, 0
    .2byte 16384, 33248, 16, 0
    .2byte 16384, 32768, 24, 0
    .2byte 16384, 32800, 32, 0
    .2byte 16384, 32832, 40, 0

    @ Table 4: 810 records, 32 bytes each.
    .4byte 810
    .incbin "graphics/intro_scene/indexed_archive/jp/title_tiles.8bpp"
    .incbin "graphics/intro_scene/indexed_archive/jp/frame_tiles.4bpp"

    @ Table 5: 18 records, 32 bytes each.
    .4byte 18
    .incbin "graphics/intro_scene/indexed_archive/jp/palettes_00_15.gbapal"
    .incbin "graphics/intro_scene/indexed_archive/jp/palettes_16_17.gbapal"

    @ Table 6: 0 records, 8 bytes each.
    .4byte 0

    @ Table 7: 17 records, 4 bytes each.
    .4byte 17
    .4byte 262144
    .4byte 262145
    .4byte 262146
    .4byte 655362
    .4byte 655363
    .4byte 655364
    .4byte 655363
    .4byte 262146
    .4byte 262149
    .4byte 6
    .4byte 655366
    .4byte 655367
    .4byte 655368
    .4byte 655367
    .4byte 262150
    .4byte 262153
    .4byte 10

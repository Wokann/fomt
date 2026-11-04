    @ JP Intro Scene IndexedResourceArchive: seven native tables.
    @ Format 120, ladder 36810121315; decoded SHA-256 f59d0e0791ea60134b32239b3108c09bfc53de6e384f024b7a0288df2af0c58a.
    @ Separate native 8bpp title and 4bpp frame PNGs preserve every tile.
    @ Complete OAM frame PNGs are references, not competing build inputs.

.LIntroArchiveStart:

    @ Table 1: 4-byte records.
    .word (.LIntroTable1End - .LIntroTable1) / 4
.LIntroTable1:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 4, 3
    .2byte 2, 7
    .2byte 1, 9
    .2byte 4, 10
    .2byte 2, 14
    .2byte 1, 16
.LIntroTable1End:

    @ Table 2: 16-byte records.
    .word (.LIntroTable2End - .LIntroTable2) / 16
.LIntroTable2:
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
.LIntroTable2End:

    @ Table 3: 8-byte records.
    .word (.LIntroTable3End - .LIntroTable3) / 8
.LIntroTable3:
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
.LIntroTable3End:

    @ Table 4: 32-byte records.
    .word (.LIntroTable4End - .LIntroTable4) / 32
.LIntroTable4:
    .incbin "graphics/intro_scene/indexed_archive/jp/title_tiles.8bpp"
    .incbin "graphics/intro_scene/indexed_archive/jp/frame_tiles.4bpp"
.LIntroTable4End:

    @ Table 5: 32-byte records.
    .word (.LIntroTable5End - .LIntroTable5) / 32
.LIntroTable5:
    .incbin "graphics/intro_scene/indexed_archive/jp/palettes_00_15.gbapal"
    .incbin "graphics/intro_scene/indexed_archive/jp/palettes_16_17.gbapal"
.LIntroTable5End:

    @ Table 6: 8-byte records.
    .word (.LIntroTable6End - .LIntroTable6) / 8
.LIntroTable6:
.LIntroTable6End:

    @ Table 7: 4-byte records.
    .word (.LIntroTable7End - .LIntroTable7) / 4
.LIntroTable7:
    .word 262144
    .word 262145
    .word 262146
    .word 655362
    .word 655363
    .word 655364
    .word 655363
    .word 262146
    .word 262149
    .word 6
    .word 655366
    .word 655367
    .word 655368
    .word 655367
    .word 262150
    .word 262153
    .word 10
.LIntroTable7End:
.LIntroArchiveEnd:

    .if ((.LIntroTable1End - .LIntroTable1) % 4) != 0 || ((.LIntroTable1End - .LIntroTable1) / 4) > 0xFFFF
    .error "Intro archive table 1 has an invalid record count or width"
    .endif
    .if ((.LIntroTable2End - .LIntroTable2) % 16) != 0 || ((.LIntroTable2End - .LIntroTable2) / 16) > 0xFFFF
    .error "Intro archive table 2 has an invalid record count or width"
    .endif
    .if ((.LIntroTable3End - .LIntroTable3) % 8) != 0 || ((.LIntroTable3End - .LIntroTable3) / 8) > 0xFFFF
    .error "Intro archive table 3 has an invalid record count or width"
    .endif
    .if ((.LIntroTable4End - .LIntroTable4) % 32) != 0 || ((.LIntroTable4End - .LIntroTable4) / 32) > 0xFFFF
    .error "Intro archive table 4 has an invalid record count or width"
    .endif
    .if ((.LIntroTable5End - .LIntroTable5) % 32) != 0 || ((.LIntroTable5End - .LIntroTable5) / 32) > 0xFFFF
    .error "Intro archive table 5 has an invalid record count or width"
    .endif
    .if ((.LIntroTable6End - .LIntroTable6) % 8) != 0 || ((.LIntroTable6End - .LIntroTable6) / 8) > 0xFFFF
    .error "Intro archive table 6 has an invalid record count or width"
    .endif
    .if ((.LIntroTable7End - .LIntroTable7) % 4) != 0 || ((.LIntroTable7End - .LIntroTable7) / 4) > 0xFFFF
    .error "Intro archive table 7 has an invalid record count or width"
    .endif

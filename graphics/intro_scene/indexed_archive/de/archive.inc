    @ DE Intro Scene IndexedResourceArchive: seven native tables.
    @ Format 220, ladder 36810111315; decoded SHA-256 6a6635e1576ebcea94cc826b0b049fe113b17c98c12ed919398024013722e067.
    @ Separate native 8bpp title and 4bpp frame PNGs preserve every tile.
    @ Complete OAM frame PNGs are references, not competing build inputs.

.LIntroArchiveStart:

    @ Table 1: 4-byte records.
    .word (.LIntroTable1End - .LIntroTable1) / 4
.LIntroTable1:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 4, 2
    .2byte 2, 6
    .2byte 1, 8
    .2byte 4, 9
    .2byte 2, 13
    .2byte 1, 15
.LIntroTable1End:

    @ Table 2: 16-byte records.
    .word (.LIntroTable2End - .LIntroTable2) / 16
.LIntroTable2:
    .2byte 17, 0, 474, 0, 16, 0, 0, 0
    .2byte 4, 17, 16, 474, 1, 16, 0, 0
    .2byte 4, 21, 16, 474, 1, 16, 0, 0
    .2byte 4, 25, 16, 474, 1, 16, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0
    .2byte 4, 29, 21, 490, 1, 17, 0, 0
    .2byte 4, 33, 21, 490, 1, 17, 0, 0
    .2byte 4, 37, 21, 490, 1, 17, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0
    .2byte 8, 41, 60, 511, 1, 18, 0, 0
.LIntroTable2End:

    @ Table 3: 8-byte records.
    .word (.LIntroTable3End - .LIntroTable3) / 8
.LIntroTable3:
    .2byte 8192, 33241, 0, 0
    .2byte 8192, 33273, 32, 0
    .2byte 8224, 33201, 64, 0
    .2byte 8224, 33233, 96, 0
    .2byte 8224, 33265, 128, 0
    .2byte 8224, 32785, 160, 0
    .2byte 40960, 32793, 192, 0
    .2byte 40960, 16425, 208, 0
    .2byte 8192, 32817, 216, 0
    .2byte 8224, 32817, 248, 0
    .2byte 8192, 33209, 280, 0
    .2byte 8216, 433, 312, 0
    .2byte 8256, 33201, 314, 0
    .2byte 8256, 33233, 346, 0
    .2byte 8256, 33265, 378, 0
    .2byte 8256, 32785, 410, 0
    .2byte 8256, 32817, 442, 0
    .2byte 16384, 32768, 0, 0
    .2byte 0, 16416, 8, 0
    .2byte 32768, 48, 12, 0
    .2byte 16632, 0, 14, 0
    .2byte 16385, 32768, 0, 0
    .2byte 1, 16416, 8, 0
    .2byte 32769, 48, 12, 0
    .2byte 16633, 0, 14, 0
    .2byte 16386, 32768, 0, 0
    .2byte 2, 16416, 8, 0
    .2byte 32770, 48, 12, 0
    .2byte 16634, 0, 14, 0
    .2byte 16384, 32768, 0, 0
    .2byte 16384, 32800, 8, 0
    .2byte 16632, 16384, 16, 0
    .2byte 248, 32, 20, 0
    .2byte 16385, 32768, 0, 0
    .2byte 16385, 32800, 8, 0
    .2byte 16633, 16384, 16, 0
    .2byte 249, 32, 20, 0
    .2byte 16386, 32768, 0, 0
    .2byte 16386, 32800, 8, 0
    .2byte 16634, 16384, 16, 0
    .2byte 250, 32, 20, 0
    .2byte 16384, 33160, 0, 0
    .2byte 16384, 33192, 8, 0
    .2byte 16384, 33224, 16, 0
    .2byte 16384, 33256, 24, 0
    .2byte 16384, 32776, 32, 0
    .2byte 16384, 32808, 40, 0
    .2byte 16384, 32840, 48, 0
    .2byte 0, 16488, 56, 0
.LIntroTable3End:

    @ Table 4: 32-byte records.
    .word (.LIntroTable4End - .LIntroTable4) / 32
.LIntroTable4:
    .incbin "graphics/intro_scene/indexed_archive/de/title_tiles.8bpp"
    .incbin "graphics/intro_scene/indexed_archive/de/frame_tiles.4bpp"
.LIntroTable4End:

    @ Table 5: 32-byte records.
    .word (.LIntroTable5End - .LIntroTable5) / 32
.LIntroTable5:
    .incbin "graphics/intro_scene/indexed_archive/de/palettes_00_15.gbapal"
    .incbin "graphics/intro_scene/indexed_archive/de/palettes_16_18.gbapal"
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
    .word 655361
    .word 655362
    .word 655363
    .word 655362
    .word 262145
    .word 262148
    .word 262149
    .word 655365
    .word 655366
    .word 655367
    .word 655366
    .word 262149
    .word 262152
    .word 9
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

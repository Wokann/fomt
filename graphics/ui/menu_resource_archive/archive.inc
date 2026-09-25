    @ Seven native IndexedResourceArchive tables in physical ROM order.
    @ Each of the eight PNGs supplies four 4bpp tiles.
    .4byte 8
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5
    .2byte 1, 6
    .2byte 1, 7

    .4byte 8
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0
    .2byte 1, 0, 4, 24, 1, 0, 0, 0
    .2byte 1, 0, 4, 28, 1, 0, 0, 0

    .4byte 1
    .2byte 0x00F8, 0x41F8, 0, 0

    .4byte 32
    .incbin "graphics/ui/menu_resource_archive/full/group_000.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_001.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_002.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_003.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_004.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_005.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_006.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_007.4bpp"

    .4byte 1
    .incbin "graphics/ui/menu_resource_archive/full/group_000.gbapal"

    .4byte 0
    .4byte 8
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0
    .2byte 6, 0
    .2byte 7, 0

    @ Seven native IndexedResourceArchive tables in physical ROM order.
    @ Three drawable descriptors own 4 + 16 + 16 PNG-derived 4bpp tiles.
    .4byte 2
    .2byte 1, 0
    .2byte 4, 1

    .4byte 4
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 1, 16, 4, 1, 1, 0, 0
    .2byte 1, 1, 16, 20, 1, 1, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

    .4byte 2
    .2byte 0, 0x4000, 0, 0
    .2byte 0x00F0, 0x81F0, 0, 0

    .4byte 36
    .incbin "graphics/ui/small_resource_archive/full/group_000.4bpp"
    .incbin "graphics/ui/small_resource_archive/full/group_001.4bpp"
    .incbin "graphics/ui/small_resource_archive/full/group_002.4bpp"

    .4byte 2
    .incbin "graphics/ui/small_resource_archive/full/group_000.gbapal"
    .incbin "graphics/ui/small_resource_archive/full/group_001.gbapal"

    .4byte 0
    .4byte 5
    .2byte 0, 4, 1, 20, 2, 10, 3, 12, 2, 10

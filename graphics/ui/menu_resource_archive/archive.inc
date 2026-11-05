    @ Seven native IndexedResourceArchive tables in physical ROM order.
    @ Each of the eight PNGs supplies four 4bpp tiles.
    .word (.Lui_menu_resource_archive_selections_end - .Lui_menu_resource_archive_selections) / 4
.Lui_menu_resource_archive_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5
    .2byte 1, 6
    .2byte 1, 7

.Lui_menu_resource_archive_selections_end:
    .word (.Lui_menu_resource_archive_groups_end - .Lui_menu_resource_archive_groups) / 16
.Lui_menu_resource_archive_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0
    .2byte 1, 0, 4, 24, 1, 0, 0, 0
    .2byte 1, 0, 4, 28, 1, 0, 0, 0

.Lui_menu_resource_archive_groups_end:
    .word (.Lui_menu_resource_archive_sprites_end - .Lui_menu_resource_archive_sprites) / 8
.Lui_menu_resource_archive_sprites:
    .2byte 0x00F8, 0x41F8, 0, 0

.Lui_menu_resource_archive_sprites_end:
    .word (.Lui_menu_resource_archive_tiles_end - .Lui_menu_resource_archive_tiles) / 32
.Lui_menu_resource_archive_tiles:
    .incbin "graphics/ui/menu_resource_archive/full/group_000.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_001.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_002.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_003.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_004.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_005.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_006.4bpp"
    .incbin "graphics/ui/menu_resource_archive/full/group_007.4bpp"

.Lui_menu_resource_archive_tiles_end:
    .word (.Lui_menu_resource_archive_palettes_end - .Lui_menu_resource_archive_palettes) / 32
.Lui_menu_resource_archive_palettes:
    .incbin "graphics/ui/menu_resource_archive/full/group_000.gbapal"

.Lui_menu_resource_archive_palettes_end:
    .word (.Lui_menu_resource_archive_sixth_end - .Lui_menu_resource_archive_sixth) / 8
.Lui_menu_resource_archive_sixth:
.Lui_menu_resource_archive_sixth_end:
    .word (.Lui_menu_resource_archive_entries_end - .Lui_menu_resource_archive_entries) / 4
.Lui_menu_resource_archive_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0
    .2byte 6, 0
    .2byte 7, 0
.Lui_menu_resource_archive_entries_end:

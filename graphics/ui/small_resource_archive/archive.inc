    @ Seven native IndexedResourceArchive tables in physical ROM order.
    @ Three drawable descriptors own 4 + 16 + 16 PNG-derived 4bpp tiles.
    .word (.Lui_small_resource_archive_selections_end - .Lui_small_resource_archive_selections) / 4
.Lui_small_resource_archive_selections:
    .2byte 1, 0
    .2byte 4, 1

.Lui_small_resource_archive_selections_end:
    .word (.Lui_small_resource_archive_groups_end - .Lui_small_resource_archive_groups) / 16
.Lui_small_resource_archive_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 1, 16, 4, 1, 1, 0, 0
    .2byte 1, 1, 16, 20, 1, 1, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

.Lui_small_resource_archive_groups_end:
    .word (.Lui_small_resource_archive_sprites_end - .Lui_small_resource_archive_sprites) / 8
.Lui_small_resource_archive_sprites:
    .2byte 0, 0x4000, 0, 0
    .2byte 0x00F0, 0x81F0, 0, 0

.Lui_small_resource_archive_sprites_end:
    .word (.Lui_small_resource_archive_tiles_end - .Lui_small_resource_archive_tiles) / 32
.Lui_small_resource_archive_tiles:
    .incbin "graphics/ui/small_resource_archive/full/group_000.4bpp"
    .incbin "graphics/ui/small_resource_archive/full/group_001.4bpp"
    .incbin "graphics/ui/small_resource_archive/full/group_002.4bpp"

.Lui_small_resource_archive_tiles_end:
    .word (.Lui_small_resource_archive_palettes_end - .Lui_small_resource_archive_palettes) / 32
.Lui_small_resource_archive_palettes:
    .incbin "graphics/ui/small_resource_archive/full/group_000.gbapal"
    .incbin "graphics/ui/small_resource_archive/full/group_001.gbapal"

.Lui_small_resource_archive_palettes_end:
    .word (.Lui_small_resource_archive_sixth_end - .Lui_small_resource_archive_sixth) / 8
.Lui_small_resource_archive_sixth:
.Lui_small_resource_archive_sixth_end:
    .word (.Lui_small_resource_archive_entries_end - .Lui_small_resource_archive_entries) / 4
.Lui_small_resource_archive_entries:
    .2byte 0, 4, 1, 20, 2, 10, 3, 12, 2, 10
.Lui_small_resource_archive_entries_end:

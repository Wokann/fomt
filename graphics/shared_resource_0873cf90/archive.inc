    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0873cf90_selections_end - .Lshared_resource_0873cf90_selections) / 4
.Lshared_resource_0873cf90_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3

.Lshared_resource_0873cf90_selections_end:
    .word (.Lshared_resource_0873cf90_groups_end - .Lshared_resource_0873cf90_groups) / 16
.Lshared_resource_0873cf90_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0

.Lshared_resource_0873cf90_groups_end:
    .word (.Lshared_resource_0873cf90_sprites_end - .Lshared_resource_0873cf90_sprites) / 8
.Lshared_resource_0873cf90_sprites:
    .2byte 0, 0x4000, 0, 0

.Lshared_resource_0873cf90_sprites_end:
    .word (.Lshared_resource_0873cf90_tiles_end - .Lshared_resource_0873cf90_tiles) / 32
.Lshared_resource_0873cf90_tiles:
    .incbin "graphics/shared_resource_0873cf90/full/group_000.4bpp"
    .incbin "graphics/shared_resource_0873cf90/full/group_001.4bpp"
    .incbin "graphics/shared_resource_0873cf90/full/group_002.4bpp"
    .incbin "graphics/shared_resource_0873cf90/full/group_003.4bpp"

.Lshared_resource_0873cf90_tiles_end:
    .word (.Lshared_resource_0873cf90_palettes_end - .Lshared_resource_0873cf90_palettes) / 32
.Lshared_resource_0873cf90_palettes:
    .incbin "graphics/shared_resource_0873cf90/full/group_000.gbapal"

.Lshared_resource_0873cf90_palettes_end:
    .word (.Lshared_resource_0873cf90_sixth_end - .Lshared_resource_0873cf90_sixth) / 8
.Lshared_resource_0873cf90_sixth:
.Lshared_resource_0873cf90_sixth_end:
    .word (.Lshared_resource_0873cf90_entries_end - .Lshared_resource_0873cf90_entries) / 4
.Lshared_resource_0873cf90_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
.Lshared_resource_0873cf90_entries_end:

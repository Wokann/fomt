    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0873ceac_selections_end - .Lshared_resource_0873ceac_selections) / 4
.Lshared_resource_0873ceac_selections:
    .2byte 1, 0

.Lshared_resource_0873ceac_selections_end:
    .word (.Lshared_resource_0873ceac_groups_end - .Lshared_resource_0873ceac_groups) / 16
.Lshared_resource_0873ceac_groups:
    .2byte 2, 0, 4, 0, 1, 0, 0, 0

.Lshared_resource_0873ceac_groups_end:
    .word (.Lshared_resource_0873ceac_sprites_end - .Lshared_resource_0873ceac_sprites) / 8
.Lshared_resource_0873ceac_sprites:
    .2byte 0x4000, 0, 0, 0
    .2byte 0x4008, 0, 2, 0

.Lshared_resource_0873ceac_sprites_end:
    .word (.Lshared_resource_0873ceac_tiles_end - .Lshared_resource_0873ceac_tiles) / 32
.Lshared_resource_0873ceac_tiles:
    .incbin "graphics/shared_resource_0873ceac/full/group_000.4bpp"

.Lshared_resource_0873ceac_tiles_end:
    .word (.Lshared_resource_0873ceac_palettes_end - .Lshared_resource_0873ceac_palettes) / 32
.Lshared_resource_0873ceac_palettes:
    .incbin "graphics/shared_resource_0873ceac/full/group_000.gbapal"

.Lshared_resource_0873ceac_palettes_end:
    .word (.Lshared_resource_0873ceac_sixth_end - .Lshared_resource_0873ceac_sixth) / 8
.Lshared_resource_0873ceac_sixth:
.Lshared_resource_0873ceac_sixth_end:
    .word (.Lshared_resource_0873ceac_entries_end - .Lshared_resource_0873ceac_entries) / 4
.Lshared_resource_0873ceac_entries:
    .2byte 0, 0
.Lshared_resource_0873ceac_entries_end:

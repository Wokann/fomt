    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_08726ccc_selections_end - .Lshared_resource_08726ccc_selections) / 4
.Lshared_resource_08726ccc_selections:
    .2byte 1, 0

.Lshared_resource_08726ccc_selections_end:
    .word (.Lshared_resource_08726ccc_groups_end - .Lshared_resource_08726ccc_groups) / 16
.Lshared_resource_08726ccc_groups:
    .2byte 9, 0, 48, 0, 1, 0, 0, 0

.Lshared_resource_08726ccc_groups_end:
    .word (.Lshared_resource_08726ccc_sprites_end - .Lshared_resource_08726ccc_sprites) / 8
.Lshared_resource_08726ccc_sprites:
    .2byte 228, 33252, 0, 0
    .2byte 32996, 32772, 16, 0
    .2byte 32996, 16404, 24, 0
    .2byte 16388, 33252, 28, 0
    .2byte 4, 16388, 36, 0
    .2byte 32772, 20, 40, 0
    .2byte 16404, 16868, 42, 0
    .2byte 16404, 4, 46, 0
    .2byte 20, 20, 0, 0

.Lshared_resource_08726ccc_sprites_end:
    .word (.Lshared_resource_08726ccc_tiles_end - .Lshared_resource_08726ccc_tiles) / 32
.Lshared_resource_08726ccc_tiles:
    .incbin "graphics/shared_resource_08726ccc/full/native.4bpp"

.Lshared_resource_08726ccc_tiles_end:
    .word (.Lshared_resource_08726ccc_palettes_end - .Lshared_resource_08726ccc_palettes) / 32
.Lshared_resource_08726ccc_palettes:
    .incbin "graphics/shared_resource_08726ccc/full/native.gbapal"

.Lshared_resource_08726ccc_palettes_end:
    .word (.Lshared_resource_08726ccc_sixth_end - .Lshared_resource_08726ccc_sixth) / 8
.Lshared_resource_08726ccc_sixth:
.Lshared_resource_08726ccc_sixth_end:
    .word (.Lshared_resource_08726ccc_entries_end - .Lshared_resource_08726ccc_entries) / 4
.Lshared_resource_08726ccc_entries:
    .2byte 0, 0
.Lshared_resource_08726ccc_entries_end:

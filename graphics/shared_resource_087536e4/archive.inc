    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_087536e4_selections_end - .Lshared_resource_087536e4_selections) / 4
.Lshared_resource_087536e4_selections:
    .2byte 2, 0
    .2byte 2, 2

.Lshared_resource_087536e4_selections_end:
    .word (.Lshared_resource_087536e4_groups_end - .Lshared_resource_087536e4_groups) / 16
.Lshared_resource_087536e4_groups:
    .2byte 1, 0, 1, 0, 1, 0, 0, 0
    .2byte 1, 1, 1, 0, 1, 0, 0, 0
    .2byte 1, 2, 1, 1, 1, 0, 0, 0
    .2byte 1, 1, 1, 1, 1, 0, 0, 0

.Lshared_resource_087536e4_groups_end:
    .word (.Lshared_resource_087536e4_sprites_end - .Lshared_resource_087536e4_sprites) / 8
.Lshared_resource_087536e4_sprites:
    .2byte 1, 0, 0, 0
    .2byte 0, 0, 0, 0
    .2byte 255, 0, 0, 0

.Lshared_resource_087536e4_sprites_end:
    .word (.Lshared_resource_087536e4_tiles_end - .Lshared_resource_087536e4_tiles) / 32
.Lshared_resource_087536e4_tiles:
    .incbin "graphics/shared_resource_087536e4/full/native.4bpp"

.Lshared_resource_087536e4_tiles_end:
    .word (.Lshared_resource_087536e4_palettes_end - .Lshared_resource_087536e4_palettes) / 32
.Lshared_resource_087536e4_palettes:
    .incbin "graphics/shared_resource_087536e4/full/native.gbapal"

.Lshared_resource_087536e4_palettes_end:
    .word (.Lshared_resource_087536e4_sixth_end - .Lshared_resource_087536e4_sixth) / 8
.Lshared_resource_087536e4_sixth:
.Lshared_resource_087536e4_sixth_end:
    .word (.Lshared_resource_087536e4_entries_end - .Lshared_resource_087536e4_entries) / 4
.Lshared_resource_087536e4_entries:
    .2byte 0, 16
    .2byte 1, 12
    .2byte 2, 16
    .2byte 3, 12
.Lshared_resource_087536e4_entries_end:

    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_087409e4_selections_end - .Lshared_resource_087409e4_selections) / 4
.Lshared_resource_087409e4_selections:
    .hword 4, 0

.Lshared_resource_087409e4_selections_end:
    .word (.Lshared_resource_087409e4_groups_end - .Lshared_resource_087409e4_groups) / 16
.Lshared_resource_087409e4_groups:
    .2byte 9, 0, 36, 0, 1, 0, 0, 0
    .2byte 9, 9, 42, 36, 1, 0, 0, 0
    .2byte 9, 9, 42, 78, 1, 0, 0, 0

.Lshared_resource_087409e4_groups_end:
    .word (.Lshared_resource_087409e4_sprites_end - .Lshared_resource_087409e4_sprites) / 8
.Lshared_resource_087409e4_sprites:
    .2byte 252, 33276, 0, 0
    .2byte 33020, 32796, 16, 0
    .2byte 33020, 16428, 0, 0
    .2byte 16412, 33276, 24, 0
    .2byte 28, 16412, 32, 0
    .2byte 32796, 44, 0, 0
    .2byte 16428, 16892, 0, 0
    .2byte 16428, 28, 0, 0
    .2byte 44, 44, 0, 0
    .2byte 252, 33276, 0, 0
    .2byte 33020, 32796, 16, 0
    .2byte 33020, 16428, 0, 0
    .2byte 16412, 33276, 24, 0
    .2byte 28, 16412, 32, 0
    .2byte 32796, 44, 0, 0
    .2byte 16428, 16892, 36, 0
    .2byte 16428, 28, 40, 0
    .2byte 44, 44, 0, 0

.Lshared_resource_087409e4_sprites_end:
    .word (.Lshared_resource_087409e4_tiles_end - .Lshared_resource_087409e4_tiles) / 32
.Lshared_resource_087409e4_tiles:
    .incbin "graphics/shared_resource_087409e4/full/native.4bpp"

.Lshared_resource_087409e4_tiles_end:
    .word (.Lshared_resource_087409e4_palettes_end - .Lshared_resource_087409e4_palettes) / 32
.Lshared_resource_087409e4_palettes:
    .incbin "graphics/shared_resource_087409e4/full/native.gbapal"

.Lshared_resource_087409e4_palettes_end:
    .word (.Lshared_resource_087409e4_sixth_end - .Lshared_resource_087409e4_sixth) / 8
.Lshared_resource_087409e4_sixth:
.Lshared_resource_087409e4_sixth_end:
    .word (.Lshared_resource_087409e4_entries_end - .Lshared_resource_087409e4_entries) / 4
.Lshared_resource_087409e4_entries:
    .2byte 0, 8
    .2byte 1, 8
    .2byte 2, 8
    .2byte 1, 8
.Lshared_resource_087409e4_entries_end:

    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_087405a0_selections_end - .Lshared_resource_087405a0_selections) / 4
.Lshared_resource_087405a0_selections:
    .2byte 1, 0
    .2byte 1, 0

.Lshared_resource_087405a0_selections_end:
    .word (.Lshared_resource_087405a0_groups_end - .Lshared_resource_087405a0_groups) / 16
.Lshared_resource_087405a0_groups:
    .2byte 2, 0, 24, 0, 1, 0, 0, 0

.Lshared_resource_087405a0_groups_end:
    .word (.Lshared_resource_087405a0_sprites_end - .Lshared_resource_087405a0_sprites) / 8
.Lshared_resource_087405a0_sprites:
    .2byte 0, 32768, 0, 0
    .2byte 32768, 32800, 16, 0

.Lshared_resource_087405a0_sprites_end:
    .word (.Lshared_resource_087405a0_tiles_end - .Lshared_resource_087405a0_tiles) / 32
.Lshared_resource_087405a0_tiles:
    .incbin "graphics/shared_resource_087405a0/full/native.4bpp"

.Lshared_resource_087405a0_tiles_end:
    .word (.Lshared_resource_087405a0_palettes_end - .Lshared_resource_087405a0_palettes) / 32
.Lshared_resource_087405a0_palettes:
    .incbin "graphics/shared_resource_087405a0/full/native.gbapal"

.Lshared_resource_087405a0_palettes_end:
    .word (.Lshared_resource_087405a0_sixth_end - .Lshared_resource_087405a0_sixth) / 8
.Lshared_resource_087405a0_sixth:
.Lshared_resource_087405a0_sixth_end:
    .word (.Lshared_resource_087405a0_entries_end - .Lshared_resource_087405a0_entries) / 4
.Lshared_resource_087405a0_entries:
    .2byte 0, 0
.Lshared_resource_087405a0_entries_end:

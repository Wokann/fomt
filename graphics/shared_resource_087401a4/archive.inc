    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_087401a4_selections_end - .Lshared_resource_087401a4_selections) / 4
.Lshared_resource_087401a4_selections:
    .hword 4, 0

.Lshared_resource_087401a4_selections_end:
    .word (.Lshared_resource_087401a4_groups_end - .Lshared_resource_087401a4_groups) / 16
.Lshared_resource_087401a4_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 1, 4, 4, 1, 0, 0, 0
    .2byte 1, 2, 4, 8, 1, 0, 0, 0
    .2byte 1, 3, 4, 12, 1, 0, 0, 0

.Lshared_resource_087401a4_groups_end:
    .word (.Lshared_resource_087401a4_sprites_end - .Lshared_resource_087401a4_sprites) / 8
.Lshared_resource_087401a4_sprites:
    .2byte 224, 16880, 0, 0
    .2byte 226, 16886, 0, 0
    .2byte 228, 16890, 0, 0
    .2byte 230, 16893, 0, 0

.Lshared_resource_087401a4_sprites_end:
    .word (.Lshared_resource_087401a4_tiles_end - .Lshared_resource_087401a4_tiles) / 32
.Lshared_resource_087401a4_tiles:
    .incbin "graphics/shared_resource_087401a4/full/native.4bpp"

.Lshared_resource_087401a4_tiles_end:
    .word (.Lshared_resource_087401a4_palettes_end - .Lshared_resource_087401a4_palettes) / 32
.Lshared_resource_087401a4_palettes:
    .incbin "graphics/shared_resource_087401a4/full/native.gbapal"

.Lshared_resource_087401a4_palettes_end:
    .word (.Lshared_resource_087401a4_sixth_end - .Lshared_resource_087401a4_sixth) / 8
.Lshared_resource_087401a4_sixth:
.Lshared_resource_087401a4_sixth_end:
    .word (.Lshared_resource_087401a4_entries_end - .Lshared_resource_087401a4_entries) / 4
.Lshared_resource_087401a4_entries:
    .2byte 0, 6
    .2byte 1, 6
    .2byte 2, 6
    .2byte 3, 6
.Lshared_resource_087401a4_entries_end:

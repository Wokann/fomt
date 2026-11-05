    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_0873de44_selections_end - .Lshared_resource_0873de44_selections) / 4
.Lshared_resource_0873de44_selections:
    .2byte 1, 0

.Lshared_resource_0873de44_selections_end:
    .word (.Lshared_resource_0873de44_groups_end - .Lshared_resource_0873de44_groups) / 16
.Lshared_resource_0873de44_groups:
    .2byte 3, 0, 56, 0, 1, 0, 0, 0

.Lshared_resource_0873de44_groups_end:
    .word (.Lshared_resource_0873de44_sprites_end - .Lshared_resource_0873de44_sprites) / 8
.Lshared_resource_0873de44_sprites:
    .2byte 0x4000, 0xC000, 0, 0
    .2byte 0, 0x8040, 0x0020, 0
    .2byte 0x8000, 0x8060, 0x0030, 0

.Lshared_resource_0873de44_sprites_end:
    .word (.Lshared_resource_0873de44_tiles_end - .Lshared_resource_0873de44_tiles) / 32
.Lshared_resource_0873de44_tiles:
    .incbin "graphics/shared_resource_0873de44/full/native.4bpp"

.Lshared_resource_0873de44_tiles_end:
    .word (.Lshared_resource_0873de44_palettes_end - .Lshared_resource_0873de44_palettes) / 32
.Lshared_resource_0873de44_palettes:
    .incbin "graphics/shared_resource_0873de44/full/native.gbapal"

.Lshared_resource_0873de44_palettes_end:
    .word (.Lshared_resource_0873de44_sixth_end - .Lshared_resource_0873de44_sixth) / 8
.Lshared_resource_0873de44_sixth:
.Lshared_resource_0873de44_sixth_end:
    .word (.Lshared_resource_0873de44_entries_end - .Lshared_resource_0873de44_entries) / 4
.Lshared_resource_0873de44_entries:
    .2byte 0, 0
.Lshared_resource_0873de44_entries_end:

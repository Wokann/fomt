    @ Native IndexedResourceArchive tables in physical ROM order.
    .word (.Lshared_resource_08729460_selections_end - .Lshared_resource_08729460_selections) / 4
.Lshared_resource_08729460_selections:
    .2byte 3, 0

.Lshared_resource_08729460_selections_end:
    .word (.Lshared_resource_08729460_groups_end - .Lshared_resource_08729460_groups) / 16
.Lshared_resource_08729460_groups:
    .2byte 9, 0, 110, 0, 1, 0, 0, 0
    .2byte 9, 0, 110, 110, 1, 0, 0, 0
    .2byte 9, 0, 110, 220, 1, 0, 0, 0

.Lshared_resource_08729460_groups_end:
    .word (.Lshared_resource_08729460_sprites_end - .Lshared_resource_08729460_sprites) / 8
.Lshared_resource_08729460_sprites:
    .2byte 0x0000, 0xC000, 0x0000, 0
    .2byte 0x8000, 0x8040, 0x0040, 0
    .2byte 0x8020, 0x8040, 0x0048, 0
    .2byte 0x4040, 0x8000, 0x0050, 0
    .2byte 0x4040, 0x8020, 0x0058, 0
    .2byte 0x0040, 0x4040, 0x0060, 0
    .2byte 0x4050, 0x4000, 0x0064, 0
    .2byte 0x4050, 0x4020, 0x0068, 0
    .2byte 0x4050, 0x0040, 0x006C, 0

.Lshared_resource_08729460_sprites_end:
    .word (.Lshared_resource_08729460_tiles_end - .Lshared_resource_08729460_tiles) / 32
.Lshared_resource_08729460_tiles:
    .incbin "graphics/shared_resource_08729460/full/native.4bpp"

.Lshared_resource_08729460_tiles_end:
    .word (.Lshared_resource_08729460_palettes_end - .Lshared_resource_08729460_palettes) / 32
.Lshared_resource_08729460_palettes:
    .incbin "graphics/shared_resource_08729460/full/native.gbapal"

.Lshared_resource_08729460_palettes_end:
    .word (.Lshared_resource_08729460_sixth_end - .Lshared_resource_08729460_sixth) / 8
.Lshared_resource_08729460_sixth:
.Lshared_resource_08729460_sixth_end:
    .word (.Lshared_resource_08729460_entries_end - .Lshared_resource_08729460_entries) / 4
.Lshared_resource_08729460_entries:
    .2byte 0, 4
    .2byte 1, 4
    .2byte 2, 4
.Lshared_resource_08729460_entries_end:

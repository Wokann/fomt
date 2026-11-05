    @ Cooking UI IndexedResourceArchive in physical ROM order.
    .word (.Lui_cooking_resource_archive_selections_end - .Lui_cooking_resource_archive_selections) / 4
.Lui_cooking_resource_archive_selections:
    .2byte 4, 0

.Lui_cooking_resource_archive_selections_end:
    .word (.Lui_cooking_resource_archive_groups_end - .Lui_cooking_resource_archive_groups) / 16
.Lui_cooking_resource_archive_groups:
    .2byte 3, 0, 20, 0, 1, 0, 0, 0
    .2byte 3, 0, 20, 20, 1, 0, 0, 0
    .2byte 0, 0, 0, 0, 0, 0, 0, 0

.Lui_cooking_resource_archive_groups_end:
    .word (.Lui_cooking_resource_archive_sprites_end - .Lui_cooking_resource_archive_sprites) / 8
.Lui_cooking_resource_archive_sprites:
    .2byte 0x4000, 0x8000, 0, 0
    .2byte 0x4000, 0x8020, 8, 0
    .2byte 0, 0x4040, 16, 0

.Lui_cooking_resource_archive_sprites_end:
    .word (.Lui_cooking_resource_archive_tiles_end - .Lui_cooking_resource_archive_tiles) / 32
.Lui_cooking_resource_archive_tiles:
    .incbin "graphics/ui/cooking_resource_archive/full/native.4bpp"

.Lui_cooking_resource_archive_tiles_end:
    .word (.Lui_cooking_resource_archive_palettes_end - .Lui_cooking_resource_archive_palettes) / 32
.Lui_cooking_resource_archive_palettes:
    .incbin "graphics/ui/cooking_resource_archive/full/native.gbapal"

.Lui_cooking_resource_archive_palettes_end:
    .word (.Lui_cooking_resource_archive_sixth_end - .Lui_cooking_resource_archive_sixth) / 8
.Lui_cooking_resource_archive_sixth:
.Lui_cooking_resource_archive_sixth_end:
    .word (.Lui_cooking_resource_archive_entries_end - .Lui_cooking_resource_archive_entries) / 4
.Lui_cooking_resource_archive_entries:
    .2byte 0, 20, 1, 10, 2, 12, 1, 10
.Lui_cooking_resource_archive_entries_end:

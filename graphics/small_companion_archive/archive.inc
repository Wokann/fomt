    @ Small companion IndexedResourceArchive in original ROM order.
    .word (.Lsmall_companion_archive_selections_end - .Lsmall_companion_archive_selections) / 4
.Lsmall_companion_archive_selections:
    .2byte 6, 0
    .2byte 6, 6
    .2byte 4, 12

.Lsmall_companion_archive_selections_end:
    .word (.Lsmall_companion_archive_groups_end - .Lsmall_companion_archive_groups) / 16
.Lsmall_companion_archive_groups:
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0
    .2byte 2, 0, 6, 12, 1, 0, 0, 0
    .2byte 2, 0, 6, 18, 1, 0, 0, 0
    .2byte 2, 0, 6, 24, 1, 0, 0, 0
    .2byte 2, 0, 6, 30, 1, 0, 0, 0
    .2byte 2, 0, 6, 0, 1, 0, 0, 0
    .2byte 2, 0, 6, 6, 1, 0, 0, 0
    .2byte 2, 0, 6, 12, 1, 0, 0, 0
    .2byte 2, 0, 6, 18, 1, 0, 0, 0
    .2byte 2, 0, 6, 24, 1, 0, 0, 0
    .2byte 2, 0, 6, 30, 1, 0, 0, 0
    .2byte 1, 2, 4, 36, 1, 1, 0, 0
    .2byte 1, 2, 4, 40, 1, 1, 0, 0
    .2byte 1, 2, 4, 44, 1, 1, 0, 0
    .2byte 1, 2, 4, 48, 1, 1, 0, 0

.Lsmall_companion_archive_groups_end:
    .word (.Lsmall_companion_archive_sprites_end - .Lsmall_companion_archive_sprites) / 8
.Lsmall_companion_archive_sprites:
    .2byte 232, 16888, 0, 0
    .2byte 16632, 504, 4, 0
    .2byte 248, 16888, 0, 0

.Lsmall_companion_archive_sprites_end:
    .word (.Lsmall_companion_archive_tiles_end - .Lsmall_companion_archive_tiles) / 32
.Lsmall_companion_archive_tiles:
    .incbin "graphics/small_companion_archive/full/native.4bpp"

.Lsmall_companion_archive_tiles_end:
    .word (.Lsmall_companion_archive_palettes_end - .Lsmall_companion_archive_palettes) / 32
.Lsmall_companion_archive_palettes:
    .incbin "graphics/small_companion_archive/full/native.gbapal"

.Lsmall_companion_archive_palettes_end:
    .word (.Lsmall_companion_archive_sixth_end - .Lsmall_companion_archive_sixth) / 8
.Lsmall_companion_archive_sixth:

.Lsmall_companion_archive_sixth_end:
    .word (.Lsmall_companion_archive_entries_end - .Lsmall_companion_archive_entries) / 4
.Lsmall_companion_archive_entries:
    .2byte 0, 16
    .2byte 1, 16
    .2byte 2, 16
    .2byte 3, 16
    .2byte 4, 16
    .2byte 5, 16
    .2byte 6, 16
    .2byte 7, 16
    .2byte 8, 16
    .2byte 9, 16
    .2byte 10, 16
    .2byte 11, 16
    .2byte 12, 18
    .2byte 13, 18
    .2byte 14, 18
    .2byte 15, 18
.Lsmall_companion_archive_entries_end:

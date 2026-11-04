    @ One selection uses the complete animation-entry list below.
    .word (.Lui_hand_selections_end - .Lui_hand_selections) / 4
.Lui_hand_selections:
    .2byte (.Lui_hand_entries_end - .Lui_hand_entries) / 4, 0
.Lui_hand_selections_end:

    .word (.Lui_hand_groups_end - .Lui_hand_groups) / 16
.Lui_hand_groups:
    @ Every pose shares all tiles and selects palette bank zero. The menu
    @ allocates one OBJ palette bank, not all banks in the archive.
    .2byte 1, 0, (.Lui_hand_tiles_end - .Lui_hand_tiles) / 32, 0, 1, 0, 0, 0
    .2byte 1, 1, (.Lui_hand_tiles_end - .Lui_hand_tiles) / 32, 0, 1, 0, 0, 0
    .2byte 1, 2, (.Lui_hand_tiles_end - .Lui_hand_tiles) / 32, 0, 1, 0, 0, 0
.Lui_hand_groups_end:

    .word (.Lui_hand_sprites_end - .Lui_hand_sprites) / 8
.Lui_hand_sprites:
    .2byte 0x00FB, 0x41F0, 0, 0
    .2byte 0x00FB, 0x41F1, 0, 0
    .2byte 0x00FB, 0x41F2, 0, 0
.Lui_hand_sprites_end:

    .word (.Lui_hand_tiles_end - .Lui_hand_tiles) / 32
.Lui_hand_tiles:
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08728208/jp/full/group_000.4bpp"
    .else
    .incbin "graphics/regional_resource_08728208/overseas/full/group_000.4bpp"
    .endif
.Lui_hand_tiles_end:

    .word (.Lui_hand_palettes_end - .Lui_hand_palettes) / 32
.Lui_hand_palettes:
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_08728208/jp/full/group_000.gbapal"
    .else
    .incbin "graphics/regional_resource_08728208/overseas/full/group_000.gbapal"
    .endif
.Lui_hand_palettes_end:

    .word (.Lui_hand_sixth_end - .Lui_hand_sixth) / 8
.Lui_hand_sixth:
.Lui_hand_sixth_end:
    .word (.Lui_hand_entries_end - .Lui_hand_entries) / 4
.Lui_hand_entries:
    .2byte 0, 6
    .2byte 1, 6
    .2byte 2, 6
    .2byte 1, 6
.Lui_hand_entries_end:

    .if ((.Lui_hand_tiles_end - .Lui_hand_tiles) % 32) != 0
    .error "UI hand cursor tile payload must contain complete 32-byte units"
    .endif
    .if ((.Lui_hand_palettes_end - .Lui_hand_palettes) % 32) != 0
    .error "UI hand cursor palette payload must contain complete 16-color banks"
    .endif

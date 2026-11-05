    @ Six-group IndexedResourceArchive. PNG tiles and palette are built by
    @ the shared graphics suffix rules; tables stay in native ROM order.
    .word (.Lregional_resource_0875b444_selections_end - .Lregional_resource_0875b444_selections) / 4
.Lregional_resource_0875b444_selections:
    .2byte 1, 0
    .2byte 1, 1
    .2byte 1, 2
    .2byte 1, 3
    .2byte 1, 4
    .2byte 1, 5

.Lregional_resource_0875b444_selections_end:
    .word (.Lregional_resource_0875b444_groups_end - .Lregional_resource_0875b444_groups) / 16
.Lregional_resource_0875b444_groups:
    .2byte 1, 0, 4, 0, 1, 0, 0, 0
    .2byte 1, 0, 4, 4, 1, 0, 0, 0
    .2byte 1, 0, 4, 8, 1, 0, 0, 0
    .2byte 1, 0, 4, 12, 1, 0, 0, 0
    .2byte 1, 0, 4, 16, 1, 0, 0, 0
    .2byte 1, 0, 4, 20, 1, 0, 0, 0

.Lregional_resource_0875b444_groups_end:
    .word (.Lregional_resource_0875b444_sprites_end - .Lregional_resource_0875b444_sprites) / 8
.Lregional_resource_0875b444_sprites:
    .2byte 0, 0x4000, 0, 0

.Lregional_resource_0875b444_sprites_end:
    .word (.Lregional_resource_0875b444_tiles_end - .Lregional_resource_0875b444_tiles) / 32
.Lregional_resource_0875b444_tiles:
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_0875b444/jp/full/group_000.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_001.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_002.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_003.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_004.4bpp"
    .incbin "graphics/regional_resource_0875b444/jp/full/group_005.4bpp"
    .else
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_000.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_001.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_002.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_003.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_004.4bpp"
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_005.4bpp"
    .endif

.Lregional_resource_0875b444_tiles_end:
    .word (.Lregional_resource_0875b444_palettes_end - .Lregional_resource_0875b444_palettes) / 32
.Lregional_resource_0875b444_palettes:
    .ifdef REGION_JP
    .incbin "graphics/regional_resource_0875b444/jp/full/group_000.gbapal"
    .else
    .incbin "graphics/regional_resource_0875b444/overseas/full/group_000.gbapal"
    .endif

.Lregional_resource_0875b444_palettes_end:
    .word (.Lregional_resource_0875b444_sixth_end - .Lregional_resource_0875b444_sixth) / 8
.Lregional_resource_0875b444_sixth:
.Lregional_resource_0875b444_sixth_end:
    .word (.Lregional_resource_0875b444_entries_end - .Lregional_resource_0875b444_entries) / 4
.Lregional_resource_0875b444_entries:
    .2byte 0, 0
    .2byte 1, 0
    .2byte 2, 0
    .2byte 3, 0
    .2byte 4, 0
    .2byte 5, 0
.Lregional_resource_0875b444_entries_end:

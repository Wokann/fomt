    .ifdef REGION_JP
    @ JP revision 0 localized data.  Event RIFF containers begin later at
    @ ROM offset 0x4E0CE0; the early portions below are ordinary static data.
    .section .rodata.script_engine_ui_error_trailer_after
    .incbin "baserom_jp.gba", 0xF9735, (0xF97DC - 0xF9735)

    .section .rodata.name_entry_preset_animal_names_trailer_prefix
    .incbin "baserom_jp.gba", 0xF996C, (0xF9994 - 0xF996C)

    .section .rodata.library_info_trailer
jp_data_080fccf3_start:
    .incbin "baserom_jp.gba", 0xFCCF3, (0xFD084 - 0xFCCF3)

    @ Rectangular Town Map area ranges.  Their record contents remain raw,
    @ but the Town Map lookup table keeps typed relocations to these starts.
    .global gUnk_TownMapAreaBounds_000
    .set gUnk_TownMapAreaBounds_000, jp_data_080fccf3_start + 0x1
    .global gUnk_TownMapAreaBounds_001
    .set gUnk_TownMapAreaBounds_001, jp_data_080fccf3_start + 0x36D
    .global gUnk_TownMapAreaBounds_003
    .set gUnk_TownMapAreaBounds_003, jp_data_080fccf3_start + 0xD9
    .global gUnk_TownMapAreaBounds_005
    .set gUnk_TownMapAreaBounds_005, jp_data_080fccf3_start + 0x15D
    .global gUnk_TownMapAreaBounds_007
    .set gUnk_TownMapAreaBounds_007, jp_data_080fccf3_start + 0x2A1










    .section .rodata.link_communication_trailer
    .incbin "baserom_jp.gba", 0x1003BA, (0x1005B0 - 0x1003BA)

    .section .rodata.cooking_recipe_inventory_trailer
    .incbin "baserom_jp.gba", 0x100C48, (0x103194 - 0x100C48)

    .section .rodata.static_data_after_item_discard
    .global gUnk_08118CF4
gUnk_08118CF4:
    .incbin "baserom_jp.gba", 0x118CF4, (0x13BCF8 - 0x118CF4)

    @ Region-neutral labels for FarmHouse visual descriptor resources.
    @ Their payload formats remain in this raw data range.
    .global gUnk_FarmHouseVisualResource_002
    .set gUnk_FarmHouseVisualResource_002, gUnk_08118CF4 + 0x19F04
    .global gUnk_FarmHouseVisualResource_003
    .set gUnk_FarmHouseVisualResource_003, gUnk_08118CF4 + 0x19F0C
    .global gUnk_FarmHouseVisualResource_008
    .set gUnk_FarmHouseVisualResource_008, gUnk_08118CF4 + 0x1AC6C
    .global gUnk_FarmHouseVisualResource_009
    .set gUnk_FarmHouseVisualResource_009, gUnk_08118CF4 + 0x1AC74
    .global gUnk_FarmHouseVisualResource_020
    .set gUnk_FarmHouseVisualResource_020, gUnk_08118CF4 + 0x1AD94
    .global gUnk_FarmHouseVisualResource_021
    .set gUnk_FarmHouseVisualResource_021, gUnk_08118CF4 + 0x1AD9C
    .global gUnk_FarmHouseVisualResource_026
    .set gUnk_FarmHouseVisualResource_026, gUnk_08118CF4 + 0x1AE38
    .global gUnk_FarmHouseVisualResource_027
    .set gUnk_FarmHouseVisualResource_027, gUnk_08118CF4 + 0x1AE40
    .global gUnk_FarmHouseVisualResource_032
    .set gUnk_FarmHouseVisualResource_032, gUnk_08118CF4 + 0x1ACE0
    .global gUnk_FarmHouseVisualResource_033
    .set gUnk_FarmHouseVisualResource_033, gUnk_08118CF4 + 0x1ACE8
    .global gUnk_FarmHouseVisualResource_039
    .set gUnk_FarmHouseVisualResource_039, gUnk_08118CF4 + 0x1ACFC
    .global gUnk_FarmHouseVisualResource_040
    .set gUnk_FarmHouseVisualResource_040, gUnk_08118CF4 + 0x1AD04

    @ Region-neutral labels for gMapData raw resource targets.
    @ Their payload types are not decoded yet.
    .global gUnk_MapDataResource_098
    .set gUnk_MapDataResource_098, gUnk_08118CF4 + 0x130
    .global gUnk_MapDataResource_099
    .set gUnk_MapDataResource_099, gUnk_08118CF4 + 0x160
    .global gUnk_MapDataResource_247
    .set gUnk_MapDataResource_247, gUnk_08118CF4 + 0x429C
    .global gUnk_MapDataResource_248
    .set gUnk_MapDataResource_248, gUnk_08118CF4 + 0x42BC
    .global gUnk_MapDataResource_062
    .set gUnk_MapDataResource_062, gUnk_08118CF4 + 0x4604
    .global gUnk_MapDataResource_063
    .set gUnk_MapDataResource_063, gUnk_08118CF4 + 0x4638
    .global gUnk_MapDataResource_271
    .set gUnk_MapDataResource_271, gUnk_08118CF4 + 0x5EE8
    .global gUnk_MapDataResource_272
    .set gUnk_MapDataResource_272, gUnk_08118CF4 + 0x5F1C
    .global gUnk_MapDataResource_276
    .set gUnk_MapDataResource_276, gUnk_08118CF4 + 0x6264
    .global gUnk_MapDataResource_277
    .set gUnk_MapDataResource_277, gUnk_08118CF4 + 0x6294
    .global gUnk_MapDataResource_198
    .set gUnk_MapDataResource_198, gUnk_08118CF4 + 0x6604
    .global gUnk_MapDataResource_199
    .set gUnk_MapDataResource_199, gUnk_08118CF4 + 0x662C
    .global gUnk_MapDataResource_181
    .set gUnk_MapDataResource_181, gUnk_08118CF4 + 0x6DB8
    .global gUnk_MapDataResource_182
    .set gUnk_MapDataResource_182, gUnk_08118CF4 + 0x6DE8
    .global gUnk_MapDataResource_006
    .set gUnk_MapDataResource_006, gUnk_08118CF4 + 0x72B8
    .global gUnk_MapDataResource_007
    .set gUnk_MapDataResource_007, gUnk_08118CF4 + 0x7300
    .global gUnk_MapDataResource_087
    .set gUnk_MapDataResource_087, gUnk_08118CF4 + 0xA388
    .global gUnk_MapDataResource_088
    .set gUnk_MapDataResource_088, gUnk_08118CF4 + 0xA3AC
    .global gUnk_MapDataResource_312
    .set gUnk_MapDataResource_312, gUnk_08118CF4 + 0xC3AC
    .global gUnk_MapDataResource_313
    .set gUnk_MapDataResource_313, gUnk_08118CF4 + 0xC3DC
    .global gUnk_MapDataResource_171
    .set gUnk_MapDataResource_171, gUnk_08118CF4 + 0xC724
    .global gUnk_MapDataResource_172
    .set gUnk_MapDataResource_172, gUnk_08118CF4 + 0xC764
    .global gUnk_MapDataResource_164
    .set gUnk_MapDataResource_164, gUnk_08118CF4 + 0xCD6C
    .global gUnk_MapDataResource_165
    .set gUnk_MapDataResource_165, gUnk_08118CF4 + 0xCDB4
    .global gUnk_MapDataResource_232
    .set gUnk_MapDataResource_232, gUnk_08118CF4 + 0xD45C
    .global gUnk_MapDataResource_233
    .set gUnk_MapDataResource_233, gUnk_08118CF4 + 0xD4A0
    .global gUnk_MapDataResource_227
    .set gUnk_MapDataResource_227, gUnk_08118CF4 + 0xD938
    .global gUnk_MapDataResource_228
    .set gUnk_MapDataResource_228, gUnk_08118CF4 + 0xD964
    .global gUnk_MapDataResource_326
    .set gUnk_MapDataResource_326, gUnk_08118CF4 + 0xDCAC
    .global gUnk_MapDataResource_327
    .set gUnk_MapDataResource_327, gUnk_08118CF4 + 0xDCD0
    .global gUnk_MapDataResource_188
    .set gUnk_MapDataResource_188, gUnk_08118CF4 + 0xE018
    .global gUnk_MapDataResource_189
    .set gUnk_MapDataResource_189, gUnk_08118CF4 + 0xE050
    .global gUnk_MapDataResource_193
    .set gUnk_MapDataResource_193, gUnk_08118CF4 + 0xE804
    .global gUnk_MapDataResource_194
    .set gUnk_MapDataResource_194, gUnk_08118CF4 + 0xE834
    .global gUnk_MapDataResource_147
    .set gUnk_MapDataResource_147, gUnk_08118CF4 + 0xEFD4
    .global gUnk_MapDataResource_148
    .set gUnk_MapDataResource_148, gUnk_08118CF4 + 0xF004
    .global gUnk_MapDataResource_152
    .set gUnk_MapDataResource_152, gUnk_08118CF4 + 0xF7B8
    .global gUnk_MapDataResource_153
    .set gUnk_MapDataResource_153, gUnk_08118CF4 + 0xF7F4
    .global gUnk_MapDataResource_157
    .set gUnk_MapDataResource_157, gUnk_08118CF4 + 0xFFB8
    .global gUnk_MapDataResource_158
    .set gUnk_MapDataResource_158, gUnk_08118CF4 + 0xFFE4
    .global gUnk_MapDataResource_215
    .set gUnk_MapDataResource_215, gUnk_08118CF4 + 0x10770
    .global gUnk_MapDataResource_216
    .set gUnk_MapDataResource_216, gUnk_08118CF4 + 0x10798
    .global gUnk_MapDataResource_220
    .set gUnk_MapDataResource_220, gUnk_08118CF4 + 0x10AE0
    .global gUnk_MapDataResource_221
    .set gUnk_MapDataResource_221, gUnk_08118CF4 + 0x10B08
    .global gUnk_MapDataResource_205
    .set gUnk_MapDataResource_205, gUnk_08118CF4 + 0x10E50
    .global gUnk_MapDataResource_206
    .set gUnk_MapDataResource_206, gUnk_08118CF4 + 0x10E84
    .global gUnk_MapDataResource_210
    .set gUnk_MapDataResource_210, gUnk_08118CF4 + 0x111CC
    .global gUnk_MapDataResource_211
    .set gUnk_MapDataResource_211, gUnk_08118CF4 + 0x11208
    .global gUnk_MapDataResource_319
    .set gUnk_MapDataResource_319, gUnk_08118CF4 + 0x11550
    .global gUnk_MapDataResource_320
    .set gUnk_MapDataResource_320, gUnk_08118CF4 + 0x11578
    .global gUnk_MapDataResource_307
    .set gUnk_MapDataResource_307, gUnk_08118CF4 + 0x118C0
    .global gUnk_MapDataResource_308
    .set gUnk_MapDataResource_308, gUnk_08118CF4 + 0x118EC
    .global gUnk_MapDataResource_264
    .set gUnk_MapDataResource_264, gUnk_08118CF4 + 0x11D44
    .global gUnk_MapDataResource_265
    .set gUnk_MapDataResource_265, gUnk_08118CF4 + 0x11D78
    .global gUnk_MapDataResource_259
    .set gUnk_MapDataResource_259, gUnk_08118CF4 + 0x123FC
    .global gUnk_MapDataResource_260
    .set gUnk_MapDataResource_260, gUnk_08118CF4 + 0x12430
    .global gUnk_MapDataResource_254
    .set gUnk_MapDataResource_254, gUnk_08118CF4 + 0x12A18
    .global gUnk_MapDataResource_255
    .set gUnk_MapDataResource_255, gUnk_08118CF4 + 0x12A48
    .global gUnk_MapDataResource_076
    .set gUnk_MapDataResource_076, gUnk_08118CF4 + 0x12DDC
    .global gUnk_MapDataResource_077
    .set gUnk_MapDataResource_077, gUnk_08118CF4 + 0x12DF0
    .global gUnk_MapDataResource_034
    .set gUnk_MapDataResource_034, gUnk_08118CF4 + 0x139F0
    .global gUnk_MapDataResource_035
    .set gUnk_MapDataResource_035, gUnk_08118CF4 + 0x13A74
    .global gUnk_MapDataResource_125
    .set gUnk_MapDataResource_125, gUnk_08118CF4 + 0x176F4
    .global gUnk_MapDataResource_126
    .set gUnk_MapDataResource_126, gUnk_08118CF4 + 0x17728
    .global gUnk_MapDataResource_130
    .set gUnk_MapDataResource_130, gUnk_08118CF4 + 0x17A84
    .global gUnk_MapDataResource_131
    .set gUnk_MapDataResource_131, gUnk_08118CF4 + 0x17AAC
    .global gUnk_MapDataResource_343
    .set gUnk_MapDataResource_343, gUnk_08118CF4 + 0x17DF4
    .global gUnk_MapDataResource_344
    .set gUnk_MapDataResource_344, gUnk_08118CF4 + 0x17E00
    .global gUnk_MapDataResource_348
    .set gUnk_MapDataResource_348, gUnk_08118CF4 + 0x1810C
    .global gUnk_MapDataResource_349
    .set gUnk_MapDataResource_349, gUnk_08118CF4 + 0x18114
    .global gUnk_MapDataResource_353
    .set gUnk_MapDataResource_353, gUnk_08118CF4 + 0x1917C
    .global gUnk_MapDataResource_354
    .set gUnk_MapDataResource_354, gUnk_08118CF4 + 0x19184
    .global gUnk_MapDataResource_358
    .set gUnk_MapDataResource_358, gUnk_08118CF4 + 0x19670
    .global gUnk_MapDataResource_359
    .set gUnk_MapDataResource_359, gUnk_08118CF4 + 0x19678
    .global gUnk_MapDataResource_363
    .set gUnk_MapDataResource_363, gUnk_08118CF4 + 0x19984
    .global gUnk_MapDataResource_364
    .set gUnk_MapDataResource_364, gUnk_08118CF4 + 0x19994
    .global gUnk_MapDataResource_368
    .set gUnk_MapDataResource_368, gUnk_08118CF4 + 0x19BEC
    .global gUnk_MapDataResource_369
    .set gUnk_MapDataResource_369, gUnk_08118CF4 + 0x19BF8
    .global gUnk_MapDataResource_020
    .set gUnk_MapDataResource_020, gUnk_08118CF4 + 0x19F24
    .global gUnk_MapDataResource_021
    .set gUnk_MapDataResource_021, gUnk_08118CF4 + 0x19F4C
    .global gUnk_MapDataResource_135
    .set gUnk_MapDataResource_135, gUnk_08118CF4 + 0x1B0C8
    .global gUnk_MapDataResource_136
    .set gUnk_MapDataResource_136, gUnk_08118CF4 + 0x1B0E8
    .global gUnk_MapDataResource_140
    .set gUnk_MapDataResource_140, gUnk_08118CF4 + 0x1B430
    .global gUnk_MapDataResource_141
    .set gUnk_MapDataResource_141, gUnk_08118CF4 + 0x1B44C
    .global gUnk_MapDataResource_331
    .set gUnk_MapDataResource_331, gUnk_08118CF4 + 0x1B794
    .global gUnk_MapDataResource_332
    .set gUnk_MapDataResource_332, gUnk_08118CF4 + 0x1B7BC
    .global gUnk_MapDataResource_176
    .set gUnk_MapDataResource_176, gUnk_08118CF4 + 0x1BB04
    .global gUnk_MapDataResource_177
    .set gUnk_MapDataResource_177, gUnk_08118CF4 + 0x1BB34
    .global gUnk_MapDataResource_242
    .set gUnk_MapDataResource_242, gUnk_08118CF4 + 0x1BE94
    .global gUnk_MapDataResource_243
    .set gUnk_MapDataResource_243, gUnk_08118CF4 + 0x1BEF8
    .global gUnk_MapDataResource_237
    .set gUnk_MapDataResource_237, gUnk_08118CF4 + 0x1C9A8
    .global gUnk_MapDataResource_238
    .set gUnk_MapDataResource_238, gUnk_08118CF4 + 0x1C9E4
    .global gUnk_MapDataResource_295
    .set gUnk_MapDataResource_295, gUnk_08118CF4 + 0x1D088
    .global gUnk_MapDataResource_296
    .set gUnk_MapDataResource_296, gUnk_08118CF4 + 0x1D0B8
    .global gUnk_MapDataResource_048
    .set gUnk_MapDataResource_048, gUnk_08118CF4 + 0x1D400
    .global gUnk_MapDataResource_049
    .set gUnk_MapDataResource_049, gUnk_08118CF4 + 0x1D44C
    .global gUnk_MapDataResource_112
    .set gUnk_MapDataResource_112, gUnk_08118CF4 + 0x2007C
    .global gUnk_MapDataResource_113
    .set gUnk_MapDataResource_113, gUnk_08118CF4 + 0x2008C
    .global gUnk_MapDataResource_336
    .set gUnk_MapDataResource_336, gUnk_08118CF4 + 0x20E9C
    .global gUnk_MapDataResource_337
    .set gUnk_MapDataResource_337, gUnk_08118CF4 + 0x20ECC
    .global gUnk_MapDataResource_372
    .set gUnk_MapDataResource_372, gUnk_08118CF4 + 0x21214
    .global gUnk_MapDataResource_373
    .set gUnk_MapDataResource_373, gUnk_08118CF4 + 0x2121C
    .global gUnk_MapDataResource_300
    .set gUnk_MapDataResource_300, gUnk_08118CF4 + 0x21474
    .global gUnk_MapDataResource_301
    .set gUnk_MapDataResource_301, gUnk_08118CF4 + 0x214A4
    .global gUnk_MapDataResource_283
    .set gUnk_MapDataResource_283, gUnk_08118CF4 + 0x217EC
    .global gUnk_MapDataResource_284
    .set gUnk_MapDataResource_284, gUnk_08118CF4 + 0x21824
    .global gUnk_MapDataResource_288
    .set gUnk_MapDataResource_288, gUnk_08118CF4 + 0x21B6C
    .global gUnk_MapDataResource_289
    .set gUnk_MapDataResource_289, gUnk_08118CF4 + 0x21B90
    @ Region-neutral labels for FieldRenderRectDescriptor raw resources.
    @ Their payload types are not decoded yet.
    .global gUnk_FieldRenderResource_146
    .set gUnk_FieldRenderResource_146, gUnk_08118CF4 + 0x24
    .global gUnk_FieldRenderResource_147
    .set gUnk_FieldRenderResource_147, gUnk_08118CF4 + 0x30
    .global gUnk_FieldRenderResource_120
    .set gUnk_FieldRenderResource_120, gUnk_08118CF4 + 0x3BF8
    .global gUnk_FieldRenderResource_121
    .set gUnk_FieldRenderResource_121, gUnk_08118CF4 + 0x3C0C
    .global gUnk_FieldRenderResource_137
    .set gUnk_FieldRenderResource_137, gUnk_08118CF4 + 0x5A38
    .global gUnk_FieldRenderResource_138
    .set gUnk_FieldRenderResource_138, gUnk_08118CF4 + 0x5A48
    .global gUnk_FieldRenderResource_130
    .set gUnk_FieldRenderResource_130, gUnk_08118CF4 + 0x5D60
    .global gUnk_FieldRenderResource_131
    .set gUnk_FieldRenderResource_131, gUnk_08118CF4 + 0x5D74
    .global gUnk_FieldRenderResource_141
    .set gUnk_FieldRenderResource_141, gUnk_08118CF4 + 0x5EC8
    .global gUnk_FieldRenderResource_142
    .set gUnk_FieldRenderResource_142, gUnk_08118CF4 + 0x5ED0
    .global gUnk_FieldRenderResource_041
    .set gUnk_FieldRenderResource_041, gUnk_08118CF4 + 0x7130
    .global gUnk_FieldRenderResource_042
    .set gUnk_FieldRenderResource_042, gUnk_08118CF4 + 0x713C
    .global gUnk_FieldRenderResource_033
    .set gUnk_FieldRenderResource_033, gUnk_08118CF4 + 0x722C
    .global gUnk_FieldRenderResource_034
    .set gUnk_FieldRenderResource_034, gUnk_08118CF4 + 0x7238
    .global gUnk_FieldRenderResource_014
    .set gUnk_FieldRenderResource_014, gUnk_08118CF4 + 0x9F00
    .global gUnk_FieldRenderResource_015
    .set gUnk_FieldRenderResource_015, gUnk_08118CF4 + 0x9F0C
    .global gUnk_FieldRenderResource_008
    .set gUnk_FieldRenderResource_008, gUnk_08118CF4 + 0xA044
    .global gUnk_FieldRenderResource_009
    .set gUnk_FieldRenderResource_009, gUnk_08118CF4 + 0xA050
    .global gUnk_FieldRenderResource_002
    .set gUnk_FieldRenderResource_002, gUnk_08118CF4 + 0xA120
    .global gUnk_FieldRenderResource_003
    .set gUnk_FieldRenderResource_003, gUnk_08118CF4 + 0xA12C
    .global gUnk_FieldRenderResource_026
    .set gUnk_FieldRenderResource_026, gUnk_08118CF4 + 0xA194
    .global gUnk_FieldRenderResource_027
    .set gUnk_FieldRenderResource_027, gUnk_08118CF4 + 0xA1A0
    .global gUnk_FieldRenderResource_020
    .set gUnk_FieldRenderResource_020, gUnk_08118CF4 + 0xA2D4
    .global gUnk_FieldRenderResource_021
    .set gUnk_FieldRenderResource_021, gUnk_08118CF4 + 0xA2E0
    .global gUnk_FieldRenderResource_155
    .set gUnk_FieldRenderResource_155, gUnk_08118CF4 + 0xCD4C
    .global gUnk_FieldRenderResource_156
    .set gUnk_FieldRenderResource_156, gUnk_08118CF4 + 0xCD50
    .global gUnk_FieldRenderResource_152
    .set gUnk_FieldRenderResource_152, gUnk_08118CF4 + 0xD39C
    .global gUnk_FieldRenderResource_153
    .set gUnk_FieldRenderResource_153, gUnk_08118CF4 + 0xD3A0
    .global gUnk_FieldRenderResource_167
    .set gUnk_FieldRenderResource_167, gUnk_08118CF4 + 0xD3A8
    .global gUnk_FieldRenderResource_168
    .set gUnk_FieldRenderResource_168, gUnk_08118CF4 + 0xD3AC
    .global gUnk_FieldRenderResource_161
    .set gUnk_FieldRenderResource_161, gUnk_08118CF4 + 0xD3DC
    .global gUnk_FieldRenderResource_162
    .set gUnk_FieldRenderResource_162, gUnk_08118CF4 + 0xD3E0
    .global gUnk_FieldRenderResource_164
    .set gUnk_FieldRenderResource_164, gUnk_08118CF4 + 0xD410
    .global gUnk_FieldRenderResource_165
    .set gUnk_FieldRenderResource_165, gUnk_08118CF4 + 0xD414
    .global gUnk_FieldRenderResource_108
    .set gUnk_FieldRenderResource_108, gUnk_08118CF4 + 0xD444
    .global gUnk_FieldRenderResource_109
    .set gUnk_FieldRenderResource_109, gUnk_08118CF4 + 0xD44C
    .global gUnk_FieldRenderResource_104
    .set gUnk_FieldRenderResource_104, gUnk_08118CF4 + 0x11C34
    .global gUnk_FieldRenderResource_105
    .set gUnk_FieldRenderResource_105, gUnk_08118CF4 + 0x11C38
    .global gUnk_FieldRenderResource_090
    .set gUnk_FieldRenderResource_090, gUnk_08118CF4 + 0x11C48
    .global gUnk_FieldRenderResource_091
    .set gUnk_FieldRenderResource_091, gUnk_08118CF4 + 0x11C50
    .global gUnk_FieldRenderResource_100
    .set gUnk_FieldRenderResource_100, gUnk_08118CF4 + 0x11C80
    .global gUnk_FieldRenderResource_101
    .set gUnk_FieldRenderResource_101, gUnk_08118CF4 + 0x11C8C
    .global gUnk_FieldRenderResource_084
    .set gUnk_FieldRenderResource_084, gUnk_08118CF4 + 0x11CA0
    .global gUnk_FieldRenderResource_085
    .set gUnk_FieldRenderResource_085, gUnk_08118CF4 + 0x11CAC
    .global gUnk_FieldRenderResource_097
    .set gUnk_FieldRenderResource_097, gUnk_08118CF4 + 0x123EC
    .global gUnk_FieldRenderResource_098
    .set gUnk_FieldRenderResource_098, gUnk_08118CF4 + 0x123F0
    .global gUnk_FieldRenderResource_072
    .set gUnk_FieldRenderResource_072, gUnk_08118CF4 + 0x1291C
    .global gUnk_FieldRenderResource_073
    .set gUnk_FieldRenderResource_073, gUnk_08118CF4 + 0x12924
    .global gUnk_FieldRenderResource_080
    .set gUnk_FieldRenderResource_080, gUnk_08118CF4 + 0x12930
    .global gUnk_FieldRenderResource_081
    .set gUnk_FieldRenderResource_081, gUnk_08118CF4 + 0x12938
    .global gUnk_FieldRenderResource_076
    .set gUnk_FieldRenderResource_076, gUnk_08118CF4 + 0x12944
    .global gUnk_FieldRenderResource_077
    .set gUnk_FieldRenderResource_077, gUnk_08118CF4 + 0x1294C
    .global gUnk_FieldRenderResource_060
    .set gUnk_FieldRenderResource_060, gUnk_08118CF4 + 0x12958
    .global gUnk_FieldRenderResource_061
    .set gUnk_FieldRenderResource_061, gUnk_08118CF4 + 0x12960
    .global gUnk_FieldRenderResource_056
    .set gUnk_FieldRenderResource_056, gUnk_08118CF4 + 0x12978
    .global gUnk_FieldRenderResource_057
    .set gUnk_FieldRenderResource_057, gUnk_08118CF4 + 0x12980
    .global gUnk_FieldRenderResource_068
    .set gUnk_FieldRenderResource_068, gUnk_08118CF4 + 0x12998
    .global gUnk_FieldRenderResource_069
    .set gUnk_FieldRenderResource_069, gUnk_08118CF4 + 0x129A0
    .global gUnk_FieldRenderResource_064
    .set gUnk_FieldRenderResource_064, gUnk_08118CF4 + 0x129BC
    .global gUnk_FieldRenderResource_065
    .set gUnk_FieldRenderResource_065, gUnk_08118CF4 + 0x129C0
    .global gUnk_FieldRenderResource_087
    .set gUnk_FieldRenderResource_087, gUnk_08118CF4 + 0x129DC
    .global gUnk_FieldRenderResource_088
    .set gUnk_FieldRenderResource_088, gUnk_08118CF4 + 0x129E8
    .global gUnk_FieldRenderResource_052
    .set gUnk_FieldRenderResource_052, gUnk_08118CF4 + 0x12D90
    .global gUnk_FieldRenderResource_053
    .set gUnk_FieldRenderResource_053, gUnk_08118CF4 + 0x12D98
    .global gUnk_FieldRenderResource_048
    .set gUnk_FieldRenderResource_048, gUnk_08118CF4 + 0x12DB0
    .global gUnk_FieldRenderResource_049
    .set gUnk_FieldRenderResource_049, gUnk_08118CF4 + 0x12DB8
    .global gUnk_FieldRenderResource_094
    .set gUnk_FieldRenderResource_094, gUnk_08118CF4 + 0x12DD0
    .global gUnk_FieldRenderResource_095
    .set gUnk_FieldRenderResource_095, gUnk_08118CF4 + 0x12DD4
    .global gUnk_FieldRenderResource_116
    .set gUnk_FieldRenderResource_116, gUnk_08118CF4 + 0x1BE7C
    .global gUnk_FieldRenderResource_117
    .set gUnk_FieldRenderResource_117, gUnk_08118CF4 + 0x1BE84
    .global gUnk_FieldRenderResource_112
    .set gUnk_FieldRenderResource_112, gUnk_08118CF4 + 0x1D05C
    .global gUnk_FieldRenderResource_113
    .set gUnk_FieldRenderResource_113, gUnk_08118CF4 + 0x1D064
    .global gUnk_FieldRenderResource_124
    .set gUnk_FieldRenderResource_124, gUnk_08118CF4 + 0x1FF8C
    .global gUnk_FieldRenderResource_125
    .set gUnk_FieldRenderResource_125, gUnk_08118CF4 + 0x1FF9C
    @ Additional region-neutral labels for later gFieldRenderRectDescriptors entries.
    @ Their payload types are not known yet.
    .global gUnk_FieldRenderResource_171
    .set gUnk_FieldRenderResource_171, gUnk_08118CF4 + 0xFF80
    .global gUnk_FieldRenderResource_172
    .set gUnk_FieldRenderResource_172, gUnk_08118CF4 + 0xFF84
    .global gUnk_FieldRenderResource_174
    .set gUnk_FieldRenderResource_174, gUnk_08118CF4 + 0x17A70
    .global gUnk_FieldRenderResource_175
    .set gUnk_FieldRenderResource_175, gUnk_08118CF4 + 0x17A74
    .global gUnk_FieldRenderResource_180
    .set gUnk_FieldRenderResource_180, gUnk_08118CF4 + 0xEFC0
    .global gUnk_FieldRenderResource_181
    .set gUnk_FieldRenderResource_181, gUnk_08118CF4 + 0xEFC4
    .global gUnk_FieldRenderResource_184
    .set gUnk_FieldRenderResource_184, gUnk_08118CF4 + 0xF7A4
    .global gUnk_FieldRenderResource_185
    .set gUnk_FieldRenderResource_185, gUnk_08118CF4 + 0xF7A8
    .global gUnk_FieldRenderResource_188
    .set gUnk_FieldRenderResource_188, gUnk_08118CF4 + 0xF790
    .global gUnk_FieldRenderResource_189
    .set gUnk_FieldRenderResource_189, gUnk_08118CF4 + 0xF794
    .global gUnk_FieldRenderResource_192
    .set gUnk_FieldRenderResource_192, gUnk_08118CF4 + 0xFFA4
    .global gUnk_FieldRenderResource_193
    .set gUnk_FieldRenderResource_193, gUnk_08118CF4 + 0xFFA8
    .global gUnk_FieldRenderResource_196
    .set gUnk_FieldRenderResource_196, gUnk_08118CF4 + 0xFF90
    .global gUnk_FieldRenderResource_197
    .set gUnk_FieldRenderResource_197, gUnk_08118CF4 + 0xFF94
    .global gUnk_FieldRenderResource_200
    .set gUnk_FieldRenderResource_200, gUnk_08118CF4 + 0xE7F0
    .global gUnk_FieldRenderResource_201
    .set gUnk_FieldRenderResource_201, gUnk_08118CF4 + 0xE7F4
    .global gUnk_FieldRenderResource_204
    .set gUnk_FieldRenderResource_204, gUnk_08118CF4 + 0xE7DC
    .global gUnk_FieldRenderResource_205
    .set gUnk_FieldRenderResource_205, gUnk_08118CF4 + 0xE7E0
    .global gUnk_FieldRenderResource_208
    .set gUnk_FieldRenderResource_208, gUnk_08118CF4 + 0x65F0
    .global gUnk_FieldRenderResource_209
    .set gUnk_FieldRenderResource_209, gUnk_08118CF4 + 0x65F4
    .global gUnk_FieldRenderResource_212
    .set gUnk_FieldRenderResource_212, gUnk_08118CF4 + 0x65DC
    .global gUnk_FieldRenderResource_213
    .set gUnk_FieldRenderResource_213, gUnk_08118CF4 + 0x65E0
    .global gUnk_FieldRenderResource_216
    .set gUnk_FieldRenderResource_216, gUnk_08118CF4 + 0x1D074
    .global gUnk_FieldRenderResource_217
    .set gUnk_FieldRenderResource_217, gUnk_08118CF4 + 0x1D078
    .global gUnk_FieldRenderResource_220
    .set gUnk_FieldRenderResource_220, gUnk_08118CF4 + 0xCD58
    .global gUnk_FieldRenderResource_221
    .set gUnk_FieldRenderResource_221, gUnk_08118CF4 + 0xCD5C

    .else
	.section .rodata.localized_data_suffix

	.global gUnk_080F9ED9
gUnk_080F9ED9:
	.incbin "baserom_us.gba", 0xF9ED9, 0x7

	.global gUnk_080F9EE0
gUnk_080F9EE0:
	.incbin "baserom_us.gba", 0xF9EE0, 0x14

	.global gUnk_080F9EF4
gUnk_080F9EF4:
	.incbin "baserom_us.gba", 0xF9EF4, 0x48

	.global gUnk_080F9F3C
gUnk_080F9F3C:
	.incbin "baserom_us.gba", 0xF9F3C, 0x34

	.global gUnk_080F9F70
gUnk_080F9F70:
	.incbin "baserom_us.gba", 0xF9F70, 0x4

	.global gUnk_080F9F74
gUnk_080F9F74:
	.incbin "baserom_us.gba", 0xF9F74, 0x4

	.global gUnk_080F9F78
gUnk_080F9F78:
	.incbin "baserom_us.gba", 0xF9F78, 0x4

	.section .rodata.name_entry_preset_animal_names_prefix
	.incbin "baserom_us.gba", 0xF9F7C, 0x4

	.section .rodata.library_info_trailer

us_data_080fd583_start:
	.incbin "baserom_us.gba", 0xFD583, (0xFD914 - 0xFD583)

	@ Rectangular Town Map area ranges.  Their record contents remain raw,
	@ but the Town Map lookup table keeps typed relocations to these starts.
	.global gUnk_TownMapAreaBounds_000
	.set gUnk_TownMapAreaBounds_000, us_data_080fd583_start + 0x1
	.global gUnk_TownMapAreaBounds_001
	.set gUnk_TownMapAreaBounds_001, us_data_080fd583_start + 0x36D
	.global gUnk_TownMapAreaBounds_003
	.set gUnk_TownMapAreaBounds_003, us_data_080fd583_start + 0xD9
	.global gUnk_TownMapAreaBounds_005
	.set gUnk_TownMapAreaBounds_005, us_data_080fd583_start + 0x15D
	.global gUnk_TownMapAreaBounds_007
	.set gUnk_TownMapAreaBounds_007, us_data_080fd583_start + 0x2A1





	.section .rodata.unextracted_shop_data


	.section .rodata.unextracted_shop_data




	.section .rodata.link_communication_trailer

	.global gUnk_08100A36
gUnk_08100A36:
	.incbin "baserom_us.gba", 0x100A36, 0x62

	.section .rodata.cooking_recipe_inventory_trailer

	.global gUnk_0810110C
gUnk_0810110C:
	.incbin "baserom_us.gba", 0x10110C, 0x254C

	.section .rodata.static_data_after_item_discard
	.incbin "baserom_us.gba", 0x117B14, (0x117B20 - 0x117B14)

	.global gUnk_08117B20
gUnk_08117B20:
	.incbin "baserom_us.gba", 0x117B20, 0xC

	.global gUnk_08117B2C
gUnk_08117B2C:
	.incbin "baserom_us.gba", 0x117B2C, 0xC

	.global gUnk_08117B38
gUnk_08117B38:
	.incbin "baserom_us.gba", 0x117B38, 0xC

	.global gUnk_08117B44
gUnk_08117B44:
	.incbin "baserom_us.gba", 0x117B44, 0xC

	.global gUnk_08117B50
gUnk_08117B50:
	.incbin "baserom_us.gba", 0x117B50, 0xC

	.global gUnk_08117B5C
gUnk_08117B5C:
	.incbin "baserom_us.gba", 0x117B5C, 0xC

	.global gUnk_08117B68
gUnk_08117B68:
	.incbin "baserom_us.gba", 0x117B68, 0xC

	.global gUnk_08117B74
gUnk_08117B74:
	.incbin "baserom_us.gba", 0x117B74, 0xC

	.global gUnk_08117B80
gUnk_08117B80:
	.incbin "baserom_us.gba", 0x117B80, 0xC

	.global gUnk_08117B8C
gUnk_08117B8C:
	.incbin "baserom_us.gba", 0x117B8C, 0xC

	.global gUnk_08117B98
gUnk_08117B98:
	.incbin "baserom_us.gba", 0x117B98, 0xC

	.global gUnk_08117BA4
gUnk_08117BA4:
	.incbin "baserom_us.gba", 0x117BA4, 0xC

	.global gUnk_08117BB0
gUnk_08117BB0:
	.incbin "baserom_us.gba", 0x117BB0, 0xC

	.global gUnk_08117BBC
gUnk_08117BBC:
	.incbin "baserom_us.gba", 0x117BBC, 0xC

	.global gUnk_08117BC8
gUnk_08117BC8:
	.incbin "baserom_us.gba", 0x117BC8, 0x21EC0

	@ Region-neutral labels for FarmHouse visual descriptor resources.
	@ Their payload formats remain in this raw data range.
	.global gUnk_FarmHouseVisualResource_002
	.set gUnk_FarmHouseVisualResource_002, gUnk_08117BC8 + 0x19EEC
	.global gUnk_FarmHouseVisualResource_003
	.set gUnk_FarmHouseVisualResource_003, gUnk_08117BC8 + 0x19EF4
	.global gUnk_FarmHouseVisualResource_008
	.set gUnk_FarmHouseVisualResource_008, gUnk_08117BC8 + 0x1AC54
	.global gUnk_FarmHouseVisualResource_009
	.set gUnk_FarmHouseVisualResource_009, gUnk_08117BC8 + 0x1AC5C
	.global gUnk_FarmHouseVisualResource_020
	.set gUnk_FarmHouseVisualResource_020, gUnk_08117BC8 + 0x1AD7C
	.global gUnk_FarmHouseVisualResource_021
	.set gUnk_FarmHouseVisualResource_021, gUnk_08117BC8 + 0x1AD84
	.global gUnk_FarmHouseVisualResource_026
	.set gUnk_FarmHouseVisualResource_026, gUnk_08117BC8 + 0x1AE20
	.global gUnk_FarmHouseVisualResource_027
	.set gUnk_FarmHouseVisualResource_027, gUnk_08117BC8 + 0x1AE28
	.global gUnk_FarmHouseVisualResource_032
	.set gUnk_FarmHouseVisualResource_032, gUnk_08117BC8 + 0x1ACC8
	.global gUnk_FarmHouseVisualResource_033
	.set gUnk_FarmHouseVisualResource_033, gUnk_08117BC8 + 0x1ACD0
	.global gUnk_FarmHouseVisualResource_039
	.set gUnk_FarmHouseVisualResource_039, gUnk_08117BC8 + 0x1ACE4
	.global gUnk_FarmHouseVisualResource_040
	.set gUnk_FarmHouseVisualResource_040, gUnk_08117BC8 + 0x1ACEC

	@ Region-neutral labels for gMapData raw resource targets.
	@ Their payload types are not decoded yet.
	.global gUnk_MapDataResource_098
	.set gUnk_MapDataResource_098, gUnk_08117BC8 + 0x118
	.global gUnk_MapDataResource_099
	.set gUnk_MapDataResource_099, gUnk_08117BC8 + 0x148
	.global gUnk_MapDataResource_247
	.set gUnk_MapDataResource_247, gUnk_08117BC8 + 0x4284
	.global gUnk_MapDataResource_248
	.set gUnk_MapDataResource_248, gUnk_08117BC8 + 0x42A4
	.global gUnk_MapDataResource_062
	.set gUnk_MapDataResource_062, gUnk_08117BC8 + 0x45EC
	.global gUnk_MapDataResource_063
	.set gUnk_MapDataResource_063, gUnk_08117BC8 + 0x4620
	.global gUnk_MapDataResource_271
	.set gUnk_MapDataResource_271, gUnk_08117BC8 + 0x5ED0
	.global gUnk_MapDataResource_272
	.set gUnk_MapDataResource_272, gUnk_08117BC8 + 0x5F04
	.global gUnk_MapDataResource_276
	.set gUnk_MapDataResource_276, gUnk_08117BC8 + 0x624C
	.global gUnk_MapDataResource_277
	.set gUnk_MapDataResource_277, gUnk_08117BC8 + 0x627C
	.global gUnk_MapDataResource_198
	.set gUnk_MapDataResource_198, gUnk_08117BC8 + 0x65EC
	.global gUnk_MapDataResource_199
	.set gUnk_MapDataResource_199, gUnk_08117BC8 + 0x6614
	.global gUnk_MapDataResource_181
	.set gUnk_MapDataResource_181, gUnk_08117BC8 + 0x6DA0
	.global gUnk_MapDataResource_182
	.set gUnk_MapDataResource_182, gUnk_08117BC8 + 0x6DD0
	.global gUnk_MapDataResource_006
	.set gUnk_MapDataResource_006, gUnk_08117BC8 + 0x72A0
	.global gUnk_MapDataResource_007
	.set gUnk_MapDataResource_007, gUnk_08117BC8 + 0x72E8
	.global gUnk_MapDataResource_087
	.set gUnk_MapDataResource_087, gUnk_08117BC8 + 0xA370
	.global gUnk_MapDataResource_088
	.set gUnk_MapDataResource_088, gUnk_08117BC8 + 0xA394
	.global gUnk_MapDataResource_312
	.set gUnk_MapDataResource_312, gUnk_08117BC8 + 0xC394
	.global gUnk_MapDataResource_313
	.set gUnk_MapDataResource_313, gUnk_08117BC8 + 0xC3C4
	.global gUnk_MapDataResource_171
	.set gUnk_MapDataResource_171, gUnk_08117BC8 + 0xC70C
	.global gUnk_MapDataResource_172
	.set gUnk_MapDataResource_172, gUnk_08117BC8 + 0xC74C
	.global gUnk_MapDataResource_164
	.set gUnk_MapDataResource_164, gUnk_08117BC8 + 0xCD54
	.global gUnk_MapDataResource_165
	.set gUnk_MapDataResource_165, gUnk_08117BC8 + 0xCD9C
	.global gUnk_MapDataResource_232
	.set gUnk_MapDataResource_232, gUnk_08117BC8 + 0xD444
	.global gUnk_MapDataResource_233
	.set gUnk_MapDataResource_233, gUnk_08117BC8 + 0xD488
	.global gUnk_MapDataResource_227
	.set gUnk_MapDataResource_227, gUnk_08117BC8 + 0xD920
	.global gUnk_MapDataResource_228
	.set gUnk_MapDataResource_228, gUnk_08117BC8 + 0xD94C
	.global gUnk_MapDataResource_326
	.set gUnk_MapDataResource_326, gUnk_08117BC8 + 0xDC94
	.global gUnk_MapDataResource_327
	.set gUnk_MapDataResource_327, gUnk_08117BC8 + 0xDCB8
	.global gUnk_MapDataResource_188
	.set gUnk_MapDataResource_188, gUnk_08117BC8 + 0xE000
	.global gUnk_MapDataResource_189
	.set gUnk_MapDataResource_189, gUnk_08117BC8 + 0xE038
	.global gUnk_MapDataResource_193
	.set gUnk_MapDataResource_193, gUnk_08117BC8 + 0xE7EC
	.global gUnk_MapDataResource_194
	.set gUnk_MapDataResource_194, gUnk_08117BC8 + 0xE81C
	.global gUnk_MapDataResource_147
	.set gUnk_MapDataResource_147, gUnk_08117BC8 + 0xEFBC
	.global gUnk_MapDataResource_148
	.set gUnk_MapDataResource_148, gUnk_08117BC8 + 0xEFEC
	.global gUnk_MapDataResource_152
	.set gUnk_MapDataResource_152, gUnk_08117BC8 + 0xF7A0
	.global gUnk_MapDataResource_153
	.set gUnk_MapDataResource_153, gUnk_08117BC8 + 0xF7DC
	.global gUnk_MapDataResource_157
	.set gUnk_MapDataResource_157, gUnk_08117BC8 + 0xFFA0
	.global gUnk_MapDataResource_158
	.set gUnk_MapDataResource_158, gUnk_08117BC8 + 0xFFCC
	.global gUnk_MapDataResource_215
	.set gUnk_MapDataResource_215, gUnk_08117BC8 + 0x10758
	.global gUnk_MapDataResource_216
	.set gUnk_MapDataResource_216, gUnk_08117BC8 + 0x10780
	.global gUnk_MapDataResource_220
	.set gUnk_MapDataResource_220, gUnk_08117BC8 + 0x10AC8
	.global gUnk_MapDataResource_221
	.set gUnk_MapDataResource_221, gUnk_08117BC8 + 0x10AF0
	.global gUnk_MapDataResource_205
	.set gUnk_MapDataResource_205, gUnk_08117BC8 + 0x10E38
	.global gUnk_MapDataResource_206
	.set gUnk_MapDataResource_206, gUnk_08117BC8 + 0x10E6C
	.global gUnk_MapDataResource_210
	.set gUnk_MapDataResource_210, gUnk_08117BC8 + 0x111B4
	.global gUnk_MapDataResource_211
	.set gUnk_MapDataResource_211, gUnk_08117BC8 + 0x111F0
	.global gUnk_MapDataResource_319
	.set gUnk_MapDataResource_319, gUnk_08117BC8 + 0x11538
	.global gUnk_MapDataResource_320
	.set gUnk_MapDataResource_320, gUnk_08117BC8 + 0x11560
	.global gUnk_MapDataResource_307
	.set gUnk_MapDataResource_307, gUnk_08117BC8 + 0x118A8
	.global gUnk_MapDataResource_308
	.set gUnk_MapDataResource_308, gUnk_08117BC8 + 0x118D4
	.global gUnk_MapDataResource_264
	.set gUnk_MapDataResource_264, gUnk_08117BC8 + 0x11D2C
	.global gUnk_MapDataResource_265
	.set gUnk_MapDataResource_265, gUnk_08117BC8 + 0x11D60
	.global gUnk_MapDataResource_259
	.set gUnk_MapDataResource_259, gUnk_08117BC8 + 0x123E4
	.global gUnk_MapDataResource_260
	.set gUnk_MapDataResource_260, gUnk_08117BC8 + 0x12418
	.global gUnk_MapDataResource_254
	.set gUnk_MapDataResource_254, gUnk_08117BC8 + 0x12A00
	.global gUnk_MapDataResource_255
	.set gUnk_MapDataResource_255, gUnk_08117BC8 + 0x12A30
	.global gUnk_MapDataResource_076
	.set gUnk_MapDataResource_076, gUnk_08117BC8 + 0x12DC4
	.global gUnk_MapDataResource_077
	.set gUnk_MapDataResource_077, gUnk_08117BC8 + 0x12DD8
	.global gUnk_MapDataResource_034
	.set gUnk_MapDataResource_034, gUnk_08117BC8 + 0x139D8
	.global gUnk_MapDataResource_035
	.set gUnk_MapDataResource_035, gUnk_08117BC8 + 0x13A5C
	.global gUnk_MapDataResource_125
	.set gUnk_MapDataResource_125, gUnk_08117BC8 + 0x176DC
	.global gUnk_MapDataResource_126
	.set gUnk_MapDataResource_126, gUnk_08117BC8 + 0x17710
	.global gUnk_MapDataResource_130
	.set gUnk_MapDataResource_130, gUnk_08117BC8 + 0x17A6C
	.global gUnk_MapDataResource_131
	.set gUnk_MapDataResource_131, gUnk_08117BC8 + 0x17A94
	.global gUnk_MapDataResource_343
	.set gUnk_MapDataResource_343, gUnk_08117BC8 + 0x17DDC
	.global gUnk_MapDataResource_344
	.set gUnk_MapDataResource_344, gUnk_08117BC8 + 0x17DE8
	.global gUnk_MapDataResource_348
	.set gUnk_MapDataResource_348, gUnk_08117BC8 + 0x180F4
	.global gUnk_MapDataResource_349
	.set gUnk_MapDataResource_349, gUnk_08117BC8 + 0x180FC
	.global gUnk_MapDataResource_353
	.set gUnk_MapDataResource_353, gUnk_08117BC8 + 0x19164
	.global gUnk_MapDataResource_354
	.set gUnk_MapDataResource_354, gUnk_08117BC8 + 0x1916C
	.global gUnk_MapDataResource_358
	.set gUnk_MapDataResource_358, gUnk_08117BC8 + 0x19658
	.global gUnk_MapDataResource_359
	.set gUnk_MapDataResource_359, gUnk_08117BC8 + 0x19660
	.global gUnk_MapDataResource_363
	.set gUnk_MapDataResource_363, gUnk_08117BC8 + 0x1996C
	.global gUnk_MapDataResource_364
	.set gUnk_MapDataResource_364, gUnk_08117BC8 + 0x1997C
	.global gUnk_MapDataResource_368
	.set gUnk_MapDataResource_368, gUnk_08117BC8 + 0x19BD4
	.global gUnk_MapDataResource_369
	.set gUnk_MapDataResource_369, gUnk_08117BC8 + 0x19BE0
	.global gUnk_MapDataResource_020
	.set gUnk_MapDataResource_020, gUnk_08117BC8 + 0x19F0C
	.global gUnk_MapDataResource_021
	.set gUnk_MapDataResource_021, gUnk_08117BC8 + 0x19F34
	.global gUnk_MapDataResource_135
	.set gUnk_MapDataResource_135, gUnk_08117BC8 + 0x1B0B0
	.global gUnk_MapDataResource_136
	.set gUnk_MapDataResource_136, gUnk_08117BC8 + 0x1B0D0
	.global gUnk_MapDataResource_140
	.set gUnk_MapDataResource_140, gUnk_08117BC8 + 0x1B418
	.global gUnk_MapDataResource_141
	.set gUnk_MapDataResource_141, gUnk_08117BC8 + 0x1B434
	.global gUnk_MapDataResource_331
	.set gUnk_MapDataResource_331, gUnk_08117BC8 + 0x1B77C
	.global gUnk_MapDataResource_332
	.set gUnk_MapDataResource_332, gUnk_08117BC8 + 0x1B7A4
	.global gUnk_MapDataResource_176
	.set gUnk_MapDataResource_176, gUnk_08117BC8 + 0x1BAEC
	.global gUnk_MapDataResource_177
	.set gUnk_MapDataResource_177, gUnk_08117BC8 + 0x1BB1C
	.global gUnk_MapDataResource_242
	.set gUnk_MapDataResource_242, gUnk_08117BC8 + 0x1BE7C
	.global gUnk_MapDataResource_243
	.set gUnk_MapDataResource_243, gUnk_08117BC8 + 0x1BEE0
	.global gUnk_MapDataResource_237
	.set gUnk_MapDataResource_237, gUnk_08117BC8 + 0x1C990
	.global gUnk_MapDataResource_238
	.set gUnk_MapDataResource_238, gUnk_08117BC8 + 0x1C9CC
	.global gUnk_MapDataResource_295
	.set gUnk_MapDataResource_295, gUnk_08117BC8 + 0x1D070
	.global gUnk_MapDataResource_296
	.set gUnk_MapDataResource_296, gUnk_08117BC8 + 0x1D0A0
	.global gUnk_MapDataResource_048
	.set gUnk_MapDataResource_048, gUnk_08117BC8 + 0x1D3E8
	.global gUnk_MapDataResource_049
	.set gUnk_MapDataResource_049, gUnk_08117BC8 + 0x1D434
	.global gUnk_MapDataResource_112
	.set gUnk_MapDataResource_112, gUnk_08117BC8 + 0x20064
	.global gUnk_MapDataResource_113
	.set gUnk_MapDataResource_113, gUnk_08117BC8 + 0x20074
	.global gUnk_MapDataResource_336
	.set gUnk_MapDataResource_336, gUnk_08117BC8 + 0x20E84
	.global gUnk_MapDataResource_337
	.set gUnk_MapDataResource_337, gUnk_08117BC8 + 0x20EB4
	.global gUnk_MapDataResource_372
	.set gUnk_MapDataResource_372, gUnk_08117BC8 + 0x211FC
	.global gUnk_MapDataResource_373
	.set gUnk_MapDataResource_373, gUnk_08117BC8 + 0x21204
	.global gUnk_MapDataResource_300
	.set gUnk_MapDataResource_300, gUnk_08117BC8 + 0x2145C
	.global gUnk_MapDataResource_301
	.set gUnk_MapDataResource_301, gUnk_08117BC8 + 0x2148C
	.global gUnk_MapDataResource_283
	.set gUnk_MapDataResource_283, gUnk_08117BC8 + 0x217D4
	.global gUnk_MapDataResource_284
	.set gUnk_MapDataResource_284, gUnk_08117BC8 + 0x2180C
	.global gUnk_MapDataResource_288
	.set gUnk_MapDataResource_288, gUnk_08117BC8 + 0x21B54
	.global gUnk_MapDataResource_289
	.set gUnk_MapDataResource_289, gUnk_08117BC8 + 0x21B78

	@ Region-neutral labels for FieldRenderRectDescriptor raw resources.
	@ Their payload types are not decoded yet.
	.global gUnk_FieldRenderResource_146
	.set gUnk_FieldRenderResource_146, gUnk_08117BC8 + 0xC
	.global gUnk_FieldRenderResource_147
	.set gUnk_FieldRenderResource_147, gUnk_08117BC8 + 0x18
	.global gUnk_FieldRenderResource_120
	.set gUnk_FieldRenderResource_120, gUnk_08117BC8 + 0x3BE0
	.global gUnk_FieldRenderResource_121
	.set gUnk_FieldRenderResource_121, gUnk_08117BC8 + 0x3BF4
	.global gUnk_FieldRenderResource_137
	.set gUnk_FieldRenderResource_137, gUnk_08117BC8 + 0x5A20
	.global gUnk_FieldRenderResource_138
	.set gUnk_FieldRenderResource_138, gUnk_08117BC8 + 0x5A30
	.global gUnk_FieldRenderResource_130
	.set gUnk_FieldRenderResource_130, gUnk_08117BC8 + 0x5D48
	.global gUnk_FieldRenderResource_131
	.set gUnk_FieldRenderResource_131, gUnk_08117BC8 + 0x5D5C
	.global gUnk_FieldRenderResource_141
	.set gUnk_FieldRenderResource_141, gUnk_08117BC8 + 0x5EB0
	.global gUnk_FieldRenderResource_142
	.set gUnk_FieldRenderResource_142, gUnk_08117BC8 + 0x5EB8
	.global gUnk_FieldRenderResource_041
	.set gUnk_FieldRenderResource_041, gUnk_08117BC8 + 0x7118
	.global gUnk_FieldRenderResource_042
	.set gUnk_FieldRenderResource_042, gUnk_08117BC8 + 0x7124
	.global gUnk_FieldRenderResource_033
	.set gUnk_FieldRenderResource_033, gUnk_08117BC8 + 0x7214
	.global gUnk_FieldRenderResource_034
	.set gUnk_FieldRenderResource_034, gUnk_08117BC8 + 0x7220
	.global gUnk_FieldRenderResource_014
	.set gUnk_FieldRenderResource_014, gUnk_08117BC8 + 0x9EE8
	.global gUnk_FieldRenderResource_015
	.set gUnk_FieldRenderResource_015, gUnk_08117BC8 + 0x9EF4
	.global gUnk_FieldRenderResource_008
	.set gUnk_FieldRenderResource_008, gUnk_08117BC8 + 0xA02C
	.global gUnk_FieldRenderResource_009
	.set gUnk_FieldRenderResource_009, gUnk_08117BC8 + 0xA038
	.global gUnk_FieldRenderResource_002
	.set gUnk_FieldRenderResource_002, gUnk_08117BC8 + 0xA108
	.global gUnk_FieldRenderResource_003
	.set gUnk_FieldRenderResource_003, gUnk_08117BC8 + 0xA114
	.global gUnk_FieldRenderResource_026
	.set gUnk_FieldRenderResource_026, gUnk_08117BC8 + 0xA17C
	.global gUnk_FieldRenderResource_027
	.set gUnk_FieldRenderResource_027, gUnk_08117BC8 + 0xA188
	.global gUnk_FieldRenderResource_020
	.set gUnk_FieldRenderResource_020, gUnk_08117BC8 + 0xA2BC
	.global gUnk_FieldRenderResource_021
	.set gUnk_FieldRenderResource_021, gUnk_08117BC8 + 0xA2C8
	.global gUnk_FieldRenderResource_155
	.set gUnk_FieldRenderResource_155, gUnk_08117BC8 + 0xCD34
	.global gUnk_FieldRenderResource_156
	.set gUnk_FieldRenderResource_156, gUnk_08117BC8 + 0xCD38
	.global gUnk_FieldRenderResource_152
	.set gUnk_FieldRenderResource_152, gUnk_08117BC8 + 0xD384
	.global gUnk_FieldRenderResource_153
	.set gUnk_FieldRenderResource_153, gUnk_08117BC8 + 0xD388
	.global gUnk_FieldRenderResource_167
	.set gUnk_FieldRenderResource_167, gUnk_08117BC8 + 0xD390
	.global gUnk_FieldRenderResource_168
	.set gUnk_FieldRenderResource_168, gUnk_08117BC8 + 0xD394
	.global gUnk_FieldRenderResource_161
	.set gUnk_FieldRenderResource_161, gUnk_08117BC8 + 0xD3C4
	.global gUnk_FieldRenderResource_162
	.set gUnk_FieldRenderResource_162, gUnk_08117BC8 + 0xD3C8
	.global gUnk_FieldRenderResource_164
	.set gUnk_FieldRenderResource_164, gUnk_08117BC8 + 0xD3F8
	.global gUnk_FieldRenderResource_165
	.set gUnk_FieldRenderResource_165, gUnk_08117BC8 + 0xD3FC
	.global gUnk_FieldRenderResource_108
	.set gUnk_FieldRenderResource_108, gUnk_08117BC8 + 0xD42C
	.global gUnk_FieldRenderResource_109
	.set gUnk_FieldRenderResource_109, gUnk_08117BC8 + 0xD434
	.global gUnk_FieldRenderResource_104
	.set gUnk_FieldRenderResource_104, gUnk_08117BC8 + 0x11C1C
	.global gUnk_FieldRenderResource_105
	.set gUnk_FieldRenderResource_105, gUnk_08117BC8 + 0x11C20
	.global gUnk_FieldRenderResource_090
	.set gUnk_FieldRenderResource_090, gUnk_08117BC8 + 0x11C30
	.global gUnk_FieldRenderResource_091
	.set gUnk_FieldRenderResource_091, gUnk_08117BC8 + 0x11C38
	.global gUnk_FieldRenderResource_100
	.set gUnk_FieldRenderResource_100, gUnk_08117BC8 + 0x11C68
	.global gUnk_FieldRenderResource_101
	.set gUnk_FieldRenderResource_101, gUnk_08117BC8 + 0x11C74
	.global gUnk_FieldRenderResource_084
	.set gUnk_FieldRenderResource_084, gUnk_08117BC8 + 0x11C88
	.global gUnk_FieldRenderResource_085
	.set gUnk_FieldRenderResource_085, gUnk_08117BC8 + 0x11C94
	.global gUnk_FieldRenderResource_097
	.set gUnk_FieldRenderResource_097, gUnk_08117BC8 + 0x123D4
	.global gUnk_FieldRenderResource_098
	.set gUnk_FieldRenderResource_098, gUnk_08117BC8 + 0x123D8
	.global gUnk_FieldRenderResource_072
	.set gUnk_FieldRenderResource_072, gUnk_08117BC8 + 0x12904
	.global gUnk_FieldRenderResource_073
	.set gUnk_FieldRenderResource_073, gUnk_08117BC8 + 0x1290C
	.global gUnk_FieldRenderResource_080
	.set gUnk_FieldRenderResource_080, gUnk_08117BC8 + 0x12918
	.global gUnk_FieldRenderResource_081
	.set gUnk_FieldRenderResource_081, gUnk_08117BC8 + 0x12920
	.global gUnk_FieldRenderResource_076
	.set gUnk_FieldRenderResource_076, gUnk_08117BC8 + 0x1292C
	.global gUnk_FieldRenderResource_077
	.set gUnk_FieldRenderResource_077, gUnk_08117BC8 + 0x12934
	.global gUnk_FieldRenderResource_060
	.set gUnk_FieldRenderResource_060, gUnk_08117BC8 + 0x12940
	.global gUnk_FieldRenderResource_061
	.set gUnk_FieldRenderResource_061, gUnk_08117BC8 + 0x12948
	.global gUnk_FieldRenderResource_056
	.set gUnk_FieldRenderResource_056, gUnk_08117BC8 + 0x12960
	.global gUnk_FieldRenderResource_057
	.set gUnk_FieldRenderResource_057, gUnk_08117BC8 + 0x12968
	.global gUnk_FieldRenderResource_068
	.set gUnk_FieldRenderResource_068, gUnk_08117BC8 + 0x12980
	.global gUnk_FieldRenderResource_069
	.set gUnk_FieldRenderResource_069, gUnk_08117BC8 + 0x12988
	.global gUnk_FieldRenderResource_064
	.set gUnk_FieldRenderResource_064, gUnk_08117BC8 + 0x129A4
	.global gUnk_FieldRenderResource_065
	.set gUnk_FieldRenderResource_065, gUnk_08117BC8 + 0x129A8
	.global gUnk_FieldRenderResource_087
	.set gUnk_FieldRenderResource_087, gUnk_08117BC8 + 0x129C4
	.global gUnk_FieldRenderResource_088
	.set gUnk_FieldRenderResource_088, gUnk_08117BC8 + 0x129D0
	.global gUnk_FieldRenderResource_052
	.set gUnk_FieldRenderResource_052, gUnk_08117BC8 + 0x12D78
	.global gUnk_FieldRenderResource_053
	.set gUnk_FieldRenderResource_053, gUnk_08117BC8 + 0x12D80
	.global gUnk_FieldRenderResource_048
	.set gUnk_FieldRenderResource_048, gUnk_08117BC8 + 0x12D98
	.global gUnk_FieldRenderResource_049
	.set gUnk_FieldRenderResource_049, gUnk_08117BC8 + 0x12DA0
	.global gUnk_FieldRenderResource_094
	.set gUnk_FieldRenderResource_094, gUnk_08117BC8 + 0x12DB8
	.global gUnk_FieldRenderResource_095
	.set gUnk_FieldRenderResource_095, gUnk_08117BC8 + 0x12DBC
	.global gUnk_FieldRenderResource_116
	.set gUnk_FieldRenderResource_116, gUnk_08117BC8 + 0x1BE64
	.global gUnk_FieldRenderResource_117
	.set gUnk_FieldRenderResource_117, gUnk_08117BC8 + 0x1BE6C
	.global gUnk_FieldRenderResource_112
	.set gUnk_FieldRenderResource_112, gUnk_08117BC8 + 0x1D044
	.global gUnk_FieldRenderResource_113
	.set gUnk_FieldRenderResource_113, gUnk_08117BC8 + 0x1D04C
	.global gUnk_FieldRenderResource_124
	.set gUnk_FieldRenderResource_124, gUnk_08117BC8 + 0x1FF74
	.global gUnk_FieldRenderResource_125
	.set gUnk_FieldRenderResource_125, gUnk_08117BC8 + 0x1FF84

	@ Additional region-neutral labels for later gFieldRenderRectDescriptors entries.
	@ Their payload types are not known yet.
	.global gUnk_FieldRenderResource_171
	.set gUnk_FieldRenderResource_171, gUnk_08117BC8 + 0xFF68
	.global gUnk_FieldRenderResource_172
	.set gUnk_FieldRenderResource_172, gUnk_08117BC8 + 0xFF6C
	.global gUnk_FieldRenderResource_174
	.set gUnk_FieldRenderResource_174, gUnk_08117BC8 + 0x17A58
	.global gUnk_FieldRenderResource_175
	.set gUnk_FieldRenderResource_175, gUnk_08117BC8 + 0x17A5C
	.global gUnk_FieldRenderResource_180
	.set gUnk_FieldRenderResource_180, gUnk_08117BC8 + 0xEFA8
	.global gUnk_FieldRenderResource_181
	.set gUnk_FieldRenderResource_181, gUnk_08117BC8 + 0xEFAC
	.global gUnk_FieldRenderResource_184
	.set gUnk_FieldRenderResource_184, gUnk_08117BC8 + 0xF78C
	.global gUnk_FieldRenderResource_185
	.set gUnk_FieldRenderResource_185, gUnk_08117BC8 + 0xF790
	.global gUnk_FieldRenderResource_188
	.set gUnk_FieldRenderResource_188, gUnk_08117BC8 + 0xF778
	.global gUnk_FieldRenderResource_189
	.set gUnk_FieldRenderResource_189, gUnk_08117BC8 + 0xF77C
	.global gUnk_FieldRenderResource_192
	.set gUnk_FieldRenderResource_192, gUnk_08117BC8 + 0xFF8C
	.global gUnk_FieldRenderResource_193
	.set gUnk_FieldRenderResource_193, gUnk_08117BC8 + 0xFF90
	.global gUnk_FieldRenderResource_196
	.set gUnk_FieldRenderResource_196, gUnk_08117BC8 + 0xFF78
	.global gUnk_FieldRenderResource_197
	.set gUnk_FieldRenderResource_197, gUnk_08117BC8 + 0xFF7C
	.global gUnk_FieldRenderResource_200
	.set gUnk_FieldRenderResource_200, gUnk_08117BC8 + 0xE7D8
	.global gUnk_FieldRenderResource_201
	.set gUnk_FieldRenderResource_201, gUnk_08117BC8 + 0xE7DC
	.global gUnk_FieldRenderResource_204
	.set gUnk_FieldRenderResource_204, gUnk_08117BC8 + 0xE7C4
	.global gUnk_FieldRenderResource_205
	.set gUnk_FieldRenderResource_205, gUnk_08117BC8 + 0xE7C8
	.global gUnk_FieldRenderResource_208
	.set gUnk_FieldRenderResource_208, gUnk_08117BC8 + 0x65D8
	.global gUnk_FieldRenderResource_209
	.set gUnk_FieldRenderResource_209, gUnk_08117BC8 + 0x65DC
	.global gUnk_FieldRenderResource_212
	.set gUnk_FieldRenderResource_212, gUnk_08117BC8 + 0x65C4
	.global gUnk_FieldRenderResource_213
	.set gUnk_FieldRenderResource_213, gUnk_08117BC8 + 0x65C8
	.global gUnk_FieldRenderResource_216
	.set gUnk_FieldRenderResource_216, gUnk_08117BC8 + 0x1D05C
	.global gUnk_FieldRenderResource_217
	.set gUnk_FieldRenderResource_217, gUnk_08117BC8 + 0x1D060
	.global gUnk_FieldRenderResource_220
	.set gUnk_FieldRenderResource_220, gUnk_08117BC8 + 0xCD40
	.global gUnk_FieldRenderResource_221
	.set gUnk_FieldRenderResource_221, gUnk_08117BC8 + 0xCD44

	.global gUnk_08139A88
gUnk_08139A88:
	.incbin "baserom_us.gba", 0x139A88, 0x90

	.global gUnk_08139B18
gUnk_08139B18:
	.incbin "baserom_us.gba", 0x139B18, 0xB4

	.global gUnk_08139BCC
gUnk_08139BCC:
	.incbin "baserom_us.gba", 0x139BCC, 0x30

	.global gUnk_08139BFC
gUnk_08139BFC:
	.incbin "baserom_us.gba", 0x139BFC, 0x18

	.global gUnk_08139C14
gUnk_08139C14:
	.incbin "baserom_us.gba", 0x139C14, 0x84

	.global gUnk_08139C98
gUnk_08139C98:
	.incbin "baserom_us.gba", 0x139C98, 0x18

	.global gUnk_08139CB0
gUnk_08139CB0:
	.incbin "baserom_us.gba", 0x139CB0, 0x3C

	.global gUnk_08139CEC
gUnk_08139CEC:
	.incbin "baserom_us.gba", 0x139CEC, 0x10

	.global gUnk_08139CFC
gUnk_08139CFC:
	.incbin "baserom_us.gba", 0x139CFC, 0x34

	.global gUnk_08139D30
gUnk_08139D30:
	.incbin "baserom_us.gba", 0x139D30, 0xE84
    .endif

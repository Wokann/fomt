    .ifdef REGION_JP
    @ JP revision 0 localized data.  Event RIFF containers begin later at
    @ ROM offset 0x4E0CE0; the early portions below are ordinary static data.
    .section .rodata.localized_data_prefix
    .incbin "baserom_jp.gba", 0xF9708, (0xF9714 - 0xF9708)

    .section .rodata.script_engine_ui_error_trailer
    .incbin "baserom_jp.gba", 0xF971A, (0xF97E6 - 0xF971A)

    .section .rodata.name_entry_preset_animal_names_trailer_prefix
    .incbin "baserom_jp.gba", 0xF996C, (0xF9994 - 0xF996C)

    .section .rodata.frisbee_scoreboard_trailer
    .incbin "baserom_jp.gba", 0xF99AB, (0xF9BD4 - 0xF99AB)

    .section .rodata.frisbee_text_trailer
    .incbin "baserom_jp.gba", 0xF9F4F, (0xF9FD6 - 0xF9F4F)

    .section .rodata.animal_festival_livestock_contestant_names_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA1DE, (0xFA280 - 0xFA1DE)

    .section .rodata.horse_race_dialogue_trailer
    .incbin "baserom_jp.gba", 0xFA712, (0xFA73C - 0xFA712)

    .section .rodata.horse_race_ticket_controls_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA88C, (0xFA898 - 0xFA88C)

    .section .rodata.horse_race_prize_catalog_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA988, (0xFA9A0 - 0xFA988)

    .section .rodata.intro_scene_prefix
    .incbin "baserom_jp.gba", 0xFAA38, (0xFAABC - 0xFAA38)

    .section .rodata.intro_scene_text_trailer
    .incbin "baserom_jp.gba", 0xFB10F, (0xFB11C - 0xFB10F)

    .section .rodata.staff_credits_trailer_prefix
    .incbin "baserom_jp.gba", 0xFBE88, (0xFBE9C - 0xFBE88)

    .section .rodata.town_map_trailer
    .incbin "baserom_jp.gba", 0xFCB08, (0xFCCB8 - 0xFCB08)

    .section .rodata.library_info_trailer
    .incbin "baserom_jp.gba", 0xFCCF3, (0xFD0B0 - 0xFCCF3)

    .section .rodata.library_menu_trailer
    .incbin "baserom_jp.gba", 0xFD0C2, (0xFD0D0 - 0xFD0C2)










    .section .rodata.carpenter_catalog_trailer
    .incbin "baserom_jp.gba", 0xFF214, (0xFF218 - 0xFF214)

    .section .rodata.carpenter_trailer
    .incbin "baserom_jp.gba", 0xFF4FC, (0xFF508 - 0xFF4FC)

    .section .rodata.link_communication_trailer
    .incbin "baserom_jp.gba", 0x100130, (0x1005EA - 0x100130)

    .section .rodata.recovery_status_trailer_prefix
    .incbin "baserom_jp.gba", 0x1008F9, (0x1008FC - 0x1008F9)

    .section .rodata.cooking_recipe_inventory_trailer
    .incbin "baserom_jp.gba", 0x100C24, (0x103194 - 0x100C24)

    .section .rodata.fishing_results_trailer
    .incbin "baserom_jp.gba", 0x1035F8, (0x103BFC - 0x1035F8)

    .section .rodata.character_names_table_trailer
    .incbin "baserom_jp.gba", 0x103EF4, (0x10447C - 0x103EF4)

    .section .rodata.map_data_after
    .global gUnk_08106474
gUnk_08106474:
    .incbin "baserom_jp.gba", 0x106474, (0x1070F4 - 0x106474)

    @ These aliases identify the still-raw targets of gActorDataSelectionEntries.
    @ Their payload types are not known yet.
    .global gUnk_ActorDataSelection_00_00
    .set gUnk_ActorDataSelection_00_00, gUnk_08106474 + 0x4F8
    .global gUnk_ActorDataSelection_00_04
    .set gUnk_ActorDataSelection_00_04, gUnk_08106474 + 0x510
    .global gUnk_ActorDataSelection_01_00
    .set gUnk_ActorDataSelection_01_00, gUnk_08106474 + 0x528
    .global gUnk_ActorDataSelection_01_04
    .set gUnk_ActorDataSelection_01_04, gUnk_08106474 + 0x540
    .global gUnk_ActorDataSelection_02_00
    .set gUnk_ActorDataSelection_02_00, gUnk_08106474 + 0x558
    .global gUnk_ActorDataSelection_02_04
    .set gUnk_ActorDataSelection_02_04, gUnk_08106474 + 0x570
    .global gUnk_ActorDataSelection_03_00
    .set gUnk_ActorDataSelection_03_00, gUnk_08106474 + 0x588
    .global gUnk_ActorDataSelection_03_04
    .set gUnk_ActorDataSelection_03_04, gUnk_08106474 + 0x5A0
    .global gUnk_ActorDataSelection_04_00
    .set gUnk_ActorDataSelection_04_00, gUnk_08106474 + 0x5B8
    .global gUnk_ActorDataSelection_04_04
    .set gUnk_ActorDataSelection_04_04, gUnk_08106474 + 0x5D0
    .global gUnk_ActorDataSelection_05_00
    .set gUnk_ActorDataSelection_05_00, gUnk_08106474 + 0x5E8
    .global gUnk_ActorDataSelection_05_04
    .set gUnk_ActorDataSelection_05_04, gUnk_08106474 + 0x600
    .global gUnk_ActorDataSelection_06_00
    .set gUnk_ActorDataSelection_06_00, gUnk_08106474 + 0x618
    .global gUnk_ActorDataSelection_06_04
    .set gUnk_ActorDataSelection_06_04, gUnk_08106474 + 0x630
    .global gUnk_ActorDataSelection_07_00
    .set gUnk_ActorDataSelection_07_00, gUnk_08106474 + 0x648
    .global gUnk_ActorDataSelection_07_04
    .set gUnk_ActorDataSelection_07_04, gUnk_08106474 + 0x660
    .global gUnk_ActorDataSelection_08_00
    .set gUnk_ActorDataSelection_08_00, gUnk_08106474 + 0x6D8
    .global gUnk_ActorDataSelection_08_04
    .set gUnk_ActorDataSelection_08_04, gUnk_08106474 + 0x6F0
    .global gUnk_ActorDataSelection_09_00
    .set gUnk_ActorDataSelection_09_00, gUnk_08106474 + 0x708
    .global gUnk_ActorDataSelection_09_04
    .set gUnk_ActorDataSelection_09_04, gUnk_08106474 + 0x720
    .global gUnk_ActorDataSelection_10_00
    .set gUnk_ActorDataSelection_10_00, gUnk_08106474 + 0x678
    .global gUnk_ActorDataSelection_10_04
    .set gUnk_ActorDataSelection_10_04, gUnk_08106474 + 0x690
    .global gUnk_ActorDataSelection_11_00
    .set gUnk_ActorDataSelection_11_00, gUnk_08106474 + 0x6A8
    .global gUnk_ActorDataSelection_11_04
    .set gUnk_ActorDataSelection_11_04, gUnk_08106474 + 0x6C0
    .global gUnk_ActorDataSelection_12_00
    .set gUnk_ActorDataSelection_12_00, gUnk_08106474 + 0x2E8
    .global gUnk_ActorDataSelection_12_04
    .set gUnk_ActorDataSelection_12_04, gUnk_08106474 + 0x2D0
    .global gUnk_ActorDataSelection_13_00
    .set gUnk_ActorDataSelection_13_00, gUnk_08106474 + 0x738
    .global gUnk_ActorDataSelection_13_04
    .set gUnk_ActorDataSelection_13_04, gUnk_08106474 + 0x750

    .section .rodata.harvest_sprite_minigames_animal_husbandry_trailer
    .incbin "baserom_jp.gba", 0x10737B, (0x1073B9 - 0x10737B)

.section .rodata.chicken_festival_contestant_names_trailer
.incbin "baserom_jp.gba", 0x1074BD, (0x1074C0 - 0x1074BD)

.section .rodata.harvest_sprite_minigames_chicken_festival_opening_trailer
.incbin "baserom_jp.gba", 0x1075EA, (0x1075EC - 0x1075EA)

.section .rodata.harvest_sprite_minigames_chicken_festival_mid
.incbin "baserom_jp.gba", 0x1075EC, (0x107620 - 0x1075EC)

.section .rodata.harvest_sprite_minigames_chicken_festival_trailer
.incbin "baserom_jp.gba", 0x107801, (0x1078E0 - 0x107801)

    .section .rodata.harvest_sprite_minigames_harvest_instructions_trailer
    .incbin "baserom_jp.gba", 0x107A5B, (0x107A5C - 0x107A5B)

    .section .rodata.harvest_sprite_minigames_harvest_results_trailer
    .incbin "baserom_jp.gba", 0x107AA9, (0x107B1C - 0x107AA9)

    .section .rodata.harvest_sprite_minigames_watering_instructions_trailer
    .incbin "baserom_jp.gba", 0x107D37, (0x107D38 - 0x107D37)

    .section .rodata.harvest_sprite_minigames_watering_results_trailer
    .incbin "baserom_jp.gba", 0x107D89, (0x107DAC - 0x107D89)

	.section .rodata.shop_common_unextracted_prefix
	.incbin "baserom_jp.gba", 0x1189D4, (0x1189F4 - 0x1189D4)

	.section .rodata.shop_common_unextracted_trailer
	.incbin "baserom_jp.gba", 0x118A14, (0x118B94 - 0x118A14)

    .section .rodata.static_data_after_item_discard
    .global gUnk_08118CF4
gUnk_08118CF4:
    .incbin "baserom_jp.gba", 0x118CF4, (0x13BCF8 - 0x118CF4)

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
    .else
    .section .rodata.localized_data_prefix

	.incbin "baserom_us.gba", 0xF9EAC, (0xF9EB8 - 0xF9EAC)

	.section .rodata.script_engine_ui_error_trailer
	.incbin "baserom_us.gba", 0xF9EBE, (0xF9EC5 - 0xF9EBE)

	.section .rodata.localized_data_suffix

	.global gUnk_080F9EC5
gUnk_080F9EC5:
	.incbin "baserom_us.gba", 0xF9EC5, 0x14

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
	.incbin "baserom_us.gba", 0xF9F7C, (0xF9F8A - 0xF9F7C)

	.section .rodata.name_entry_ui_character_codes

	.global gUnk_080FA12E
gUnk_080FA12E:
	.incbin "baserom_us.gba", 0xFA12E, 0x2A

	.section .rodata.frisbee_scoreboard_trailer

	.global gUnk_080FA174
gUnk_080FA174:
	.incbin "baserom_us.gba", 0xFA174, 0xD2

	.global gUnk_080FA246
gUnk_080FA246:
	.incbin "baserom_us.gba", 0xFA246, 0x1E

	.global gUnk_080FA264
gUnk_080FA264:
	.incbin "baserom_us.gba", 0xFA264, 0x84

	.global gUnk_080FA2E8
gUnk_080FA2E8:
	.incbin "baserom_us.gba", 0xFA2E8, 0x84

	.global gUnk_080FA36C
gUnk_080FA36C:
	.incbin "baserom_us.gba", 0xFA36C, 0x6

	.global gUnk_080FA372
gUnk_080FA372:
	.incbin "baserom_us.gba", 0xFA372, 0xA

	.global gUnk_080FA37C
gUnk_080FA37C:
	.incbin "baserom_us.gba", 0xFA37C, 0x20

	.section .rodata.frisbee_text_trailer
	.incbin "baserom_us.gba", 0xFA710, 0xC

	.global gUnk_080FA71C
gUnk_080FA71C:
	.incbin "baserom_us.gba", 0xFA71C, 0xC

	.global gUnk_080FA728
gUnk_080FA728:
	.incbin "baserom_us.gba", 0xFA728, 0x6E

	.section .rodata.animal_festival_livestock_contestant_names_trailer_prefix

	.global gUnk_080FA99E
gUnk_080FA99E:
	.incbin "baserom_us.gba", 0xFA99E, 0xA2

	.section .rodata.horse_race_dialogue_trailer

	.global gUnk_080FAE6A
gUnk_080FAE6A:
	.incbin "baserom_us.gba", 0xFAE6A, 0x32

	.section .rodata.horse_race_ticket_controls_trailer_prefix

	.global gUnk_080FAFF4
gUnk_080FAFF4:
	.incbin "baserom_us.gba", 0xFAFF4, 0xC

	.section .rodata.horse_race_prize_catalog_trailer_prefix

	.global gUnk_080FB0F0
gUnk_080FB0F0:
	.incbin "baserom_us.gba", 0xFB0F0, 0x18

	.section .rodata.intro_scene_prefix

	.global gUnk_080FB1A6
gUnk_080FB1A6:
	.incbin "baserom_us.gba", 0xFB1A6, 0x3E

	.global gUnk_080FB1E4
gUnk_080FB1E4:
	.incbin "baserom_us.gba", 0xFB1E4, 0x50

	.section .rodata.intro_scene_text_trailer
	.incbin "baserom_us.gba", 0xFB817, (0xFB824 - 0xFB817)

	.section .rodata.staff_credits_trailer_prefix

	.global gUnk_080FC6B8
gUnk_080FC6B8:
	.incbin "baserom_us.gba", 0xFC6B8, (0xFC6C2 - 0xFC6B8)

	.global gUnk_080FC6C2
gUnk_080FC6C2:
	.incbin "baserom_us.gba", 0xFC6C2, 0xA

	.section .rodata.town_map_trailer

	.global gUnk_080FD3A0
gUnk_080FD3A0:
	.incbin "baserom_us.gba", 0xFD3A0, 0x1A0

	.global gUnk_080FD540
gUnk_080FD540:
	.incbin "baserom_us.gba", 0xFD540, 0x8

	.global gUnk_080FD548
gUnk_080FD548:
	.incbin "baserom_us.gba", 0xFD548, 0x8

	.section .rodata.library_info_trailer
	.incbin "baserom_us.gba", 0xFD583, (0xFD920 - 0xFD583)

	.global gUnk_080FD920
gUnk_080FD920:
	.incbin "baserom_us.gba", 0xFD920, 0x20

	.section .rodata.library_menu_trailer
	.incbin "baserom_us.gba", 0xFD958, (0xFD964 - 0xFD958)





	.section .rodata.unextracted_shop_data


	.section .rodata.unextracted_shop_data




    .section .rodata.carpenter_catalog_trailer
    .global gUnk_080FF838
gUnk_080FF838:
    .incbin "baserom_us.gba", 0xFF838, 0x4

    .section .rodata.carpenter_trailer
    .incbin "baserom_us.gba", 0xFFB54, (0xFFB60 - 0xFFB54)

	.section .rodata.link_communication_trailer

	.global gUnk_081007AC
gUnk_081007AC:
	.incbin "baserom_us.gba", 0x1007AC, 0x28

	.global gUnk_081007D4
gUnk_081007D4:
	.incbin "baserom_us.gba", 0x1007D4, 0x28

	.global gUnk_081007FC
gUnk_081007FC:
	.incbin "baserom_us.gba", 0x1007FC, 0x28

	.global gUnk_08100824
gUnk_08100824:
	.incbin "baserom_us.gba", 0x100824, 0x28

	.global gUnk_0810084C
gUnk_0810084C:
	.incbin "baserom_us.gba", 0x10084C, 0x28

	.global gUnk_08100874
gUnk_08100874:
	.incbin "baserom_us.gba", 0x100874, 0x28

	.global gUnk_0810089C
gUnk_0810089C:
	.incbin "baserom_us.gba", 0x10089C, 0x28

	.global gUnk_081008C4
gUnk_081008C4:
	.incbin "baserom_us.gba", 0x1008C4, 0x28

	.global gUnk_081008EC
gUnk_081008EC:
	.incbin "baserom_us.gba", 0x1008EC, 0x28

	.global gUnk_08100914
gUnk_08100914:
	.incbin "baserom_us.gba", 0x100914, 0x28

	.global gUnk_0810093C
gUnk_0810093C:
	.incbin "baserom_us.gba", 0x10093C, 0x28

	.global gUnk_08100964
gUnk_08100964:
	.incbin "baserom_us.gba", 0x100964, 0x28

	.global gUnk_0810098C
gUnk_0810098C:
	.incbin "baserom_us.gba", 0x10098C, 0x28

	.global gUnk_081009B4
gUnk_081009B4:
	.incbin "baserom_us.gba", 0x1009B4, 0x28

	.global gUnk_081009DC
gUnk_081009DC:
	.incbin "baserom_us.gba", 0x1009DC, 0x28

	.global gUnk_08100A04
gUnk_08100A04:
	.incbin "baserom_us.gba", 0x100A04, 0x32

	.global gUnk_08100A36
gUnk_08100A36:
	.incbin "baserom_us.gba", 0x100A36, 0x62

	.global gUnk_08100A98
gUnk_08100A98:
	.incbin "baserom_us.gba", 0x100A98, 0x8

	.global gUnk_08100AA0
gUnk_08100AA0:
	.incbin "baserom_us.gba", 0x100AA0, 0x20

	.global gUnk_08100AC0
gUnk_08100AC0:
	.incbin "baserom_us.gba", 0x100AC0, 0x2

	.global gUnk_08100AC2
gUnk_08100AC2:
	.incbin "baserom_us.gba", 0x100AC2, 0x10

	.section .rodata.cooking_recipe_inventory_trailer

	.global gUnk_081010E8
gUnk_081010E8:
	.incbin "baserom_us.gba", 0x1010E8, 0x24

	.global gUnk_0810110C
gUnk_0810110C:
	.incbin "baserom_us.gba", 0x10110C, 0x254C

	.section .rodata.reference_guide_harvest_sprite_minigames_after_fishing_results

	.global gUnk_08103B10
gUnk_08103B10:
	.incbin "baserom_us.gba", 0x103B10, 0x28

	.global gUnk_08103B38
gUnk_08103B38:
	.incbin "baserom_us.gba", 0x103B38, 0x104

	.global gUnk_08103C3C
gUnk_08103C3C:
	.incbin "baserom_us.gba", 0x103C3C, 0x38

	.global gUnk_08103C74
gUnk_08103C74:
	.incbin "baserom_us.gba", 0x103C74, 0x310

	.global gUnk_08103F84
gUnk_08103F84:
	.incbin "baserom_us.gba", 0x103F84, 0x14

	.global gUnk_08103F98
gUnk_08103F98:
	.incbin "baserom_us.gba", 0x103F98, 0x4C

	.global gUnk_08103FE4
gUnk_08103FE4:
	.incbin "baserom_us.gba", 0x103FE4, 0x28

	.global gUnk_0810400C
gUnk_0810400C:
	.incbin "baserom_us.gba", 0x10400C, 0xE0

	.global gUnk_081040EC
gUnk_081040EC:
	.incbin "baserom_us.gba", 0x1040EC, 0x1C

	.section .rodata.reference_guide_harvest_sprite_minigames_after_character_names

	.global gUnk_081043BC
gUnk_081043BC:
	.incbin "baserom_us.gba", 0x1043BC, 0x57C

	.section .rodata.map_data_after

	.global gUnk_0810692C
gUnk_0810692C:
	.incbin "baserom_us.gba", 0x10692C, 0x18

	.global gUnk_08106944
gUnk_08106944:
	.incbin "baserom_us.gba", 0x106944, 0x18

	.global gUnk_0810695C
gUnk_0810695C:
	.incbin "baserom_us.gba", 0x10695C, 0x18

	.global gUnk_08106974
gUnk_08106974:
	.incbin "baserom_us.gba", 0x106974, 0x18

	.global gUnk_0810698C
gUnk_0810698C:
	.incbin "baserom_us.gba", 0x10698C, 0x18

	.global gUnk_081069A4
gUnk_081069A4:
	.incbin "baserom_us.gba", 0x1069A4, 0x18

	.global gUnk_081069BC
gUnk_081069BC:
	.incbin "baserom_us.gba", 0x1069BC, 0x18

	.global gUnk_081069D4
gUnk_081069D4:
	.incbin "baserom_us.gba", 0x1069D4, 0x18

	.global gUnk_081069EC
gUnk_081069EC:
	.incbin "baserom_us.gba", 0x1069EC, 0x18

	.global gUnk_08106A04
gUnk_08106A04:
	.incbin "baserom_us.gba", 0x106A04, 0x18

	.global gUnk_08106A1C
gUnk_08106A1C:
	.incbin "baserom_us.gba", 0x106A1C, 0x18

	.global gUnk_08106A34
gUnk_08106A34:
	.incbin "baserom_us.gba", 0x106A34, 0x18

	.global gUnk_08106A4C
gUnk_08106A4C:
	.incbin "baserom_us.gba", 0x106A4C, 0x18

	.global gUnk_08106A64
gUnk_08106A64:
	.incbin "baserom_us.gba", 0x106A64, 0x18

	.global gUnk_08106A7C
gUnk_08106A7C:
	.incbin "baserom_us.gba", 0x106A7C, 0x18

	.global gUnk_08106A94
gUnk_08106A94:
	.incbin "baserom_us.gba", 0x106A94, 0x18

	.global gUnk_08106AAC
gUnk_08106AAC:
	.incbin "baserom_us.gba", 0x106AAC, 0x18

	.global gUnk_08106AC4
gUnk_08106AC4:
	.incbin "baserom_us.gba", 0x106AC4, 0x18

	.global gUnk_08106ADC
gUnk_08106ADC:
	.incbin "baserom_us.gba", 0x106ADC, 0x18

	.global gUnk_08106AF4
gUnk_08106AF4:
	.incbin "baserom_us.gba", 0x106AF4, 0x18

	.global gUnk_08106B0C
gUnk_08106B0C:
	.incbin "baserom_us.gba", 0x106B0C, 0x18

	.global gUnk_08106B24
gUnk_08106B24:
	.incbin "baserom_us.gba", 0x106B24, 0x18

	.global gUnk_08106B3C
gUnk_08106B3C:
	.incbin "baserom_us.gba", 0x106B3C, 0x18

	.global gUnk_08106B54
gUnk_08106B54:
	.incbin "baserom_us.gba", 0x106B54, 0x18

	.global gUnk_08106B6C
gUnk_08106B6C:
	.incbin "baserom_us.gba", 0x106B6C, 0x18

	.global gUnk_08106B84
gUnk_08106B84:
	.incbin "baserom_us.gba", 0x106B84, 0x18

	.global gUnk_08106B9C
gUnk_08106B9C:
	.incbin "baserom_us.gba", 0x106B9C, 0x18

	.global gUnk_08106BB4
gUnk_08106BB4:
	.incbin "baserom_us.gba", 0x106BB4, 0x18

	.global gUnk_08106BCC
gUnk_08106BCC:
	.incbin "baserom_us.gba", 0x106BCC, 0x18

	.global gUnk_08106BE4
gUnk_08106BE4:
	.incbin "baserom_us.gba", 0x106BE4, 0x48

	.global gUnk_08106C2C
gUnk_08106C2C:
	.incbin "baserom_us.gba", 0x106C2C, 0x18

	.global gUnk_08106C44
gUnk_08106C44:
	.incbin "baserom_us.gba", 0x106C44, 0x18

	.global gUnk_08106C5C
gUnk_08106C5C:
	.incbin "baserom_us.gba", 0x106C5C, 0x18

	.global gUnk_08106C74
gUnk_08106C74:
	.incbin "baserom_us.gba", 0x106C74, 0x18

	.global gUnk_08106C8C
gUnk_08106C8C:
	.incbin "baserom_us.gba", 0x106C8C, 0x18

	.global gUnk_08106CA4
gUnk_08106CA4:
	.incbin "baserom_us.gba", 0x106CA4, 0x18

	.global gUnk_08106CBC
gUnk_08106CBC:
	.incbin "baserom_us.gba", 0x106CBC, 0x18

	.global gUnk_08106CD4
gUnk_08106CD4:
	.incbin "baserom_us.gba", 0x106CD4, 0x18

	.global gUnk_08106CEC
gUnk_08106CEC:
	.incbin "baserom_us.gba", 0x106CEC, 0x18

	.global gUnk_08106D04
gUnk_08106D04:
	.incbin "baserom_us.gba", 0x106D04, 0x18

	.global gUnk_08106D1C
gUnk_08106D1C:
	.incbin "baserom_us.gba", 0x106D1C, 0x18

	.global gUnk_08106D34
gUnk_08106D34:
	.incbin "baserom_us.gba", 0x106D34, 0x18

	.global gUnk_08106D4C
gUnk_08106D4C:
	.incbin "baserom_us.gba", 0x106D4C, 0x18

	.global gUnk_08106D64
gUnk_08106D64:
	.incbin "baserom_us.gba", 0x106D64, 0x18

	.global gUnk_08106D7C
gUnk_08106D7C:
	.incbin "baserom_us.gba", 0x106D7C, 0x18

	.global gUnk_08106D94
gUnk_08106D94:
	.incbin "baserom_us.gba", 0x106D94, 0x18

	.global gUnk_08106DAC
gUnk_08106DAC:
	.incbin "baserom_us.gba", 0x106DAC, 0x18

	.global gUnk_08106DC4
gUnk_08106DC4:
	.incbin "baserom_us.gba", 0x106DC4, 0x18

	.global gUnk_08106DDC
gUnk_08106DDC:
	.incbin "baserom_us.gba", 0x106DDC, 0x18

	.global gUnk_08106DF4
gUnk_08106DF4:
	.incbin "baserom_us.gba", 0x106DF4, 0x18

    .global gUnk_08106E0C
gUnk_08106E0C:
	.incbin "baserom_us.gba", 0x106E0C, 0x288

	@ These aliases identify the still-raw targets of gActorDataSelectionEntries.
	@ Their payload types are not known yet.
	.global gUnk_ActorDataSelection_00_00
	.set gUnk_ActorDataSelection_00_00, gUnk_08106E0C + 0x18
	.global gUnk_ActorDataSelection_00_04
	.set gUnk_ActorDataSelection_00_04, gUnk_08106E0C + 0x30
	.global gUnk_ActorDataSelection_01_00
	.set gUnk_ActorDataSelection_01_00, gUnk_08106E0C + 0x48
	.global gUnk_ActorDataSelection_01_04
	.set gUnk_ActorDataSelection_01_04, gUnk_08106E0C + 0x60
	.global gUnk_ActorDataSelection_02_00
	.set gUnk_ActorDataSelection_02_00, gUnk_08106E0C + 0x78
	.global gUnk_ActorDataSelection_02_04
	.set gUnk_ActorDataSelection_02_04, gUnk_08106E0C + 0x90
	.global gUnk_ActorDataSelection_03_00
	.set gUnk_ActorDataSelection_03_00, gUnk_08106E0C + 0xA8
	.global gUnk_ActorDataSelection_03_04
	.set gUnk_ActorDataSelection_03_04, gUnk_08106E0C + 0xC0
	.global gUnk_ActorDataSelection_04_00
	.set gUnk_ActorDataSelection_04_00, gUnk_08106E0C + 0xD8
	.global gUnk_ActorDataSelection_04_04
	.set gUnk_ActorDataSelection_04_04, gUnk_08106E0C + 0xF0
	.global gUnk_ActorDataSelection_05_00
	.set gUnk_ActorDataSelection_05_00, gUnk_08106E0C + 0x108
	.global gUnk_ActorDataSelection_05_04
	.set gUnk_ActorDataSelection_05_04, gUnk_08106E0C + 0x120
	.global gUnk_ActorDataSelection_06_00
	.set gUnk_ActorDataSelection_06_00, gUnk_08106E0C + 0x138
	.global gUnk_ActorDataSelection_06_04
	.set gUnk_ActorDataSelection_06_04, gUnk_08106E0C + 0x150
	.global gUnk_ActorDataSelection_07_00
	.set gUnk_ActorDataSelection_07_00, gUnk_08106E0C + 0x168
	.global gUnk_ActorDataSelection_07_04
	.set gUnk_ActorDataSelection_07_04, gUnk_08106E0C + 0x180
	.global gUnk_ActorDataSelection_08_00
	.set gUnk_ActorDataSelection_08_00, gUnk_08106E0C + 0x1F8
	.global gUnk_ActorDataSelection_08_04
	.set gUnk_ActorDataSelection_08_04, gUnk_08106E0C + 0x210
	.global gUnk_ActorDataSelection_09_00
	.set gUnk_ActorDataSelection_09_00, gUnk_08106E0C + 0x228
	.global gUnk_ActorDataSelection_09_04
	.set gUnk_ActorDataSelection_09_04, gUnk_08106E0C + 0x240
	.global gUnk_ActorDataSelection_10_00
	.set gUnk_ActorDataSelection_10_00, gUnk_08106E0C + 0x198
	.global gUnk_ActorDataSelection_10_04
	.set gUnk_ActorDataSelection_10_04, gUnk_08106E0C + 0x1B0
	.global gUnk_ActorDataSelection_11_00
	.set gUnk_ActorDataSelection_11_00, gUnk_08106E0C + 0x1C8
	.global gUnk_ActorDataSelection_11_04
	.set gUnk_ActorDataSelection_11_04, gUnk_08106E0C + 0x1E0
	.global gUnk_ActorDataSelection_12_00
	.set gUnk_ActorDataSelection_12_00, gUnk_08106BE4 + 0x30
	.global gUnk_ActorDataSelection_12_04
	.set gUnk_ActorDataSelection_12_04, gUnk_08106BE4 + 0x18
	.global gUnk_ActorDataSelection_13_00
	.set gUnk_ActorDataSelection_13_00, gUnk_08106E0C + 0x258
	.global gUnk_ActorDataSelection_13_04
	.set gUnk_ActorDataSelection_13_04, gUnk_08106E0C + 0x270

	.global gUnk_08107094
gUnk_08107094:
	.incbin "baserom_us.gba", 0x107094, 0x18

	.global gUnk_081070AC
gUnk_081070AC:
	.incbin "baserom_us.gba", 0x1070AC, 0x18

	.global gUnk_081070C4
gUnk_081070C4:
	.incbin "baserom_us.gba", 0x1070C4, 0x18

	.global gUnk_081070DC
gUnk_081070DC:
	.incbin "baserom_us.gba", 0x1070DC, 0x8

	.global gUnk_081070E4
gUnk_081070E4:
	.incbin "baserom_us.gba", 0x1070E4, 0x8

	.global gUnk_081070EC
gUnk_081070EC:
	.incbin "baserom_us.gba", 0x1070EC, 0x8

	.global gUnk_081070F4
gUnk_081070F4:
	.incbin "baserom_us.gba", 0x1070F4, 0x8

	.global gUnk_081070FC
gUnk_081070FC:
	.incbin "baserom_us.gba", 0x1070FC, 0x8

	.global gUnk_08107104
gUnk_08107104:
	.incbin "baserom_us.gba", 0x107104, 0x8

	.global gUnk_0810710C
gUnk_0810710C:
	.incbin "baserom_us.gba", 0x10710C, 0x8

	.global gUnk_08107114
gUnk_08107114:
	.incbin "baserom_us.gba", 0x107114, 0xC

	.global gUnk_08107120
gUnk_08107120:
	.incbin "baserom_us.gba", 0x107120, 0xC

	.global gUnk_0810712C
gUnk_0810712C:
	.incbin "baserom_us.gba", 0x10712C, 0xC

	.global gUnk_08107138
gUnk_08107138:
	.incbin "baserom_us.gba", 0x107138, 0xC

	.global gUnk_08107144
gUnk_08107144:
	.incbin "baserom_us.gba", 0x107144, 0x8

	.global gUnk_0810714C
gUnk_0810714C:
	.incbin "baserom_us.gba", 0x10714C, 0x8

	.global gUnk_08107154
gUnk_08107154:
	.incbin "baserom_us.gba", 0x107154, 0x8

	.global gUnk_0810715C
gUnk_0810715C:
	.incbin "baserom_us.gba", 0x10715C, 0xC

	.global gUnk_08107168
gUnk_08107168:
	.incbin "baserom_us.gba", 0x107168, 0xC

	.global gUnk_08107174
gUnk_08107174:
	.incbin "baserom_us.gba", 0x107174, 0xC

	.global gUnk_08107180
gUnk_08107180:
	.incbin "baserom_us.gba", 0x107180, 0xC

	.global gUnk_0810718C
gUnk_0810718C:
	.incbin "baserom_us.gba", 0x10718C, 0xC

	.global gUnk_08107198
gUnk_08107198:
	.incbin "baserom_us.gba", 0x107198, 0xC

	.global gUnk_081071A4
gUnk_081071A4:
	.incbin "baserom_us.gba", 0x1071A4, 0xC

	.global gUnk_081071B0
gUnk_081071B0:
	.incbin "baserom_us.gba", 0x1071B0, 0xC

	.global gUnk_081071BC
gUnk_081071BC:
	.incbin "baserom_us.gba", 0x1071BC, 0xC

	.global gUnk_081071C8
gUnk_081071C8:
	.incbin "baserom_us.gba", 0x1071C8, 0xC

	.global gUnk_081071D4
gUnk_081071D4:
	.incbin "baserom_us.gba", 0x1071D4, 0xC

	.global gUnk_081071E0
gUnk_081071E0:
	.incbin "baserom_us.gba", 0x1071E0, 0xC

	.global gUnk_081071EC
gUnk_081071EC:
	.incbin "baserom_us.gba", 0x1071EC, 0xC

	.global gUnk_081071F8
gUnk_081071F8:
	.incbin "baserom_us.gba", 0x1071F8, 0xC

	.global gUnk_08107204
gUnk_08107204:
	.incbin "baserom_us.gba", 0x107204, 0x2C

	.global gUnk_08107230
gUnk_08107230:
	.incbin "baserom_us.gba", 0x107230, 0x2C

	.global gUnk_0810725C
gUnk_0810725C:
	.incbin "baserom_us.gba", 0x10725C, 0x2C

	.global gUnk_08107288
gUnk_08107288:
	.incbin "baserom_us.gba", 0x107288, 0x2C

	.global gUnk_081072B4
gUnk_081072B4:
	.incbin "baserom_us.gba", 0x1072B4, 0x2C

	.global gUnk_081072E0
gUnk_081072E0:
	.incbin "baserom_us.gba", 0x1072E0, 0x2C

	.global gUnk_0810730C
gUnk_0810730C:
	.incbin "baserom_us.gba", 0x10730C, 0x2C

	.global gUnk_08107338
gUnk_08107338:
	.incbin "baserom_us.gba", 0x107338, 0xC

	.global gUnk_08107344
gUnk_08107344:
	.incbin "baserom_us.gba", 0x107344, 0x44

	.global gUnk_08107388
gUnk_08107388:
	.incbin "baserom_us.gba", 0x107388, 0xC

	.global gUnk_08107394
gUnk_08107394:
	.incbin "baserom_us.gba", 0x107394, 0xC

	.global gUnk_081073A0
gUnk_081073A0:
	.incbin "baserom_us.gba", 0x1073A0, 0xC

	.global gUnk_081073AC
gUnk_081073AC:
	.incbin "baserom_us.gba", 0x1073AC, 0xC

	.global gUnk_081073B8
gUnk_081073B8:
	.incbin "baserom_us.gba", 0x1073B8, 0xC

	.global gUnk_081073C4
gUnk_081073C4:
	.incbin "baserom_us.gba", 0x1073C4, 0x8

	.global gUnk_081073CC
gUnk_081073CC:
	.incbin "baserom_us.gba", 0x1073CC, 0x4

	.global gUnk_081073D0
gUnk_081073D0:
	.incbin "baserom_us.gba", 0x1073D0, 0x20

	.global gUnk_081073F0
gUnk_081073F0:
	.incbin "baserom_us.gba", 0x1073F0, 0x10

	.global gUnk_08107400
gUnk_08107400:
	.incbin "baserom_us.gba", 0x107400, 0x20

	.global gUnk_08107420
gUnk_08107420:
	.incbin "baserom_us.gba", 0x107420, 0xE

	.global gUnk_0810742E
gUnk_0810742E:
	.incbin "baserom_us.gba", 0x10742E, 0x3

	.global gUnk_08107431
gUnk_08107431:
	.incbin "baserom_us.gba", 0x107431, 0x3

	.global gUnk_08107434
gUnk_08107434:
	.incbin "baserom_us.gba", 0x107434, 0x4

	.global gUnk_08107438
gUnk_08107438:
	.incbin "baserom_us.gba", 0x107438, 0x18

	.global gUnk_08107450
gUnk_08107450:
	.incbin "baserom_us.gba", 0x107450, 0x8

	.global gUnk_08107458
gUnk_08107458:
	.incbin "baserom_us.gba", 0x107458, 0x9E

	.global gUnk_081074F6
gUnk_081074F6:
	.incbin "baserom_us.gba", 0x1074F6, 0x36

	.global gUnk_0810752C
gUnk_0810752C:
	.incbin "baserom_us.gba", 0x10752C, 0x14

	.global gUnk_08107540
gUnk_08107540:
	.incbin "baserom_us.gba", 0x107540, 0x28

	.global gUnk_08107568
gUnk_08107568:
	.incbin "baserom_us.gba", 0x107568, 0x4

	.global gUnk_0810756C
gUnk_0810756C:
	.incbin "baserom_us.gba", 0x10756C, 0x1C

	.global gUnk_08107588
gUnk_08107588:
	.incbin "baserom_us.gba", 0x107588, 0x14

	.global gUnk_0810759C
gUnk_0810759C:
	.incbin "baserom_us.gba", 0x10759C, 0x14

	.section .rodata.harvest_sprite_minigames_animal_husbandry_trailer

	.global gUnk_0810787C
gUnk_0810787C:
	.incbin "baserom_us.gba", 0x10787C, 0x6

	.global gUnk_08107882
gUnk_08107882:
	.incbin "baserom_us.gba", 0x107882, 0x8

	.global gUnk_0810788A
gUnk_0810788A:
	.incbin "baserom_us.gba", 0x10788A, 0x6

	.global gUnk_08107890
gUnk_08107890:
	.incbin "baserom_us.gba", 0x107890, 0xA

	.global gUnk_0810789A
gUnk_0810789A:
	.incbin "baserom_us.gba", 0x10789A, 0x6

	.global gUnk_081078A0
gUnk_081078A0:
	.incbin "baserom_us.gba", 0x1078A0, 0x1C

	.global gUnk_081078BC
gUnk_081078BC:
	.incbin "baserom_us.gba", 0x1078BC, 0x1

	.section .rodata.chicken_festival_contestant_names_trailer

	.global gUnk_081079C1
gUnk_081079C1:
	.incbin "baserom_us.gba", 0x1079C1, 0x3

	.section .rodata.harvest_sprite_minigames_chicken_festival_mid

	.global gUnk_08107ACC
gUnk_08107ACC:
	.incbin "baserom_us.gba", 0x107ACC, 0x30

	.global gUnk_08107AFC
gUnk_08107AFC:
	.incbin "baserom_us.gba", 0x107AFC, 0x4

	.section .rodata.harvest_sprite_minigames_chicken_festival_instructions_trailer
	.incbin "baserom_us.gba", 0x107CFB, 0x1

	.section .rodata.harvest_sprite_minigames_chicken_festival_trailer

	.global gUnk_08107CFC
gUnk_08107CFC:
	.incbin "baserom_us.gba", 0x107CFC, 0x40

	.global gUnk_08107D3C
gUnk_08107D3C:
	.incbin "baserom_us.gba", 0x107D3C, 0xA

	.global gUnk_08107D46
gUnk_08107D46:
	.incbin "baserom_us.gba", 0x107D46, 0x20

	.global gUnk_08107D66
gUnk_08107D66:
	.incbin "baserom_us.gba", 0x107D66, 0x6

	.global gUnk_08107D6C
gUnk_08107D6C:
	.incbin "baserom_us.gba", 0x107D6C, 0x4C

	.global gUnk_08107DB8
gUnk_08107DB8:
	.incbin "baserom_us.gba", 0x107DB8, 0x4

	.global gUnk_08107DBC
gUnk_08107DBC:
	.incbin "baserom_us.gba", 0x107DBC, 0x1C

	.section .rodata.harvest_sprite_minigames_harvest_instructions_trailer
	.incbin "baserom_us.gba", 0x107F5F, 0x1

	.section .rodata.harvest_sprite_minigames_harvest_results_trailer

	.global gUnk_08107FB0
gUnk_08107FB0:
	.incbin "baserom_us.gba", 0x107FB0, 0x16

	.global gUnk_08107FC6
gUnk_08107FC6:
	.incbin "baserom_us.gba", 0x107FC6, 0x1A

	.global gUnk_08107FE0
gUnk_08107FE0:
	.incbin "baserom_us.gba", 0x107FE0, 0x20

	.global gUnk_08108000
gUnk_08108000:
	.incbin "baserom_us.gba", 0x108000, 0x4

	.global gUnk_08108004
gUnk_08108004:
	.incbin "baserom_us.gba", 0x108004, 0x1C

	.section .rodata.harvest_sprite_minigames_watering_instructions_trailer
	.incbin "baserom_us.gba", 0x108217, 0x1

	.section .rodata.harvest_sprite_minigames_watering_results_trailer
	.incbin "baserom_us.gba", 0x108267, 0x1

	.global gUnk_08108268
gUnk_08108268:
	.incbin "baserom_us.gba", 0x108268, 0x14

	.global gUnk_0810827C
gUnk_0810827C:
	.incbin "baserom_us.gba", 0x10827C, 0x10

	.section .rodata.reference_guide_unextracted_trailer
	.incbin "baserom_us.gba", 0x1177EC, (0x1177F6 - 0x1177EC)

	.section .rodata.tool_status_prefix

	.global gUnk_081177F6
gUnk_081177F6:
	.incbin "baserom_us.gba", 0x1177F6, 0x16

	.section .rodata.shop_common_unextracted_trailer
	.incbin "baserom_us.gba", 0x11782C, (0x117838 - 0x11782C)

	.section .rodata.tool_status_prefix_trailer

	.global gUnk_08117838
gUnk_08117838:
	.incbin "baserom_us.gba", 0x117838, 0x4

	.global gUnk_0811783C
gUnk_0811783C:
	.incbin "baserom_us.gba", 0x11783C, 0x20

	.global gUnk_0811785C
gUnk_0811785C:
	.incbin "baserom_us.gba", 0x11785C, 0x4

	.global gUnk_08117860
gUnk_08117860:
	.incbin "baserom_us.gba", 0x117860, 0x2C

	.global gUnk_0811788C
gUnk_0811788C:
	.incbin "baserom_us.gba", 0x11788C, 0x4

	.global gUnk_08117890
gUnk_08117890:
	.incbin "baserom_us.gba", 0x117890, 0x11C

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

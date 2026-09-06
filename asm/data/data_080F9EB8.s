    .ifdef REGION_JP
    @ JP revision 0 localized data.  Event RIFF containers begin later at
    @ ROM offset 0x4E0CE0; the early portions below are ordinary static data.
    .section .rodata.localized_data_prefix
    .incbin "baserom_jp.gba", 0xF9708, (0xF9714 - 0xF9708)

    .section .rodata.script_engine_ui_error_trailer
    .incbin "baserom_jp.gba", 0xF971A, (0xF97E6 - 0xF971A)

    .section .rodata.festival_contestants_set0_trailer_prefix
    .incbin "baserom_jp.gba", 0xF996C, (0xF9994 - 0xF996C)

    .section .rodata.frisbee_scoreboard_trailer
    .incbin "baserom_jp.gba", 0xF99AB, (0xF9BD4 - 0xF99AB)

    .section .rodata.frisbee_text_trailer
    .incbin "baserom_jp.gba", 0xF9F4F, (0xF9FD6 - 0xF9F4F)

    .section .rodata.festival_contestants_set1_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA1DE, (0xFA280 - 0xFA1DE)

    .section .rodata.horse_race_dialogue_trailer
    .incbin "baserom_jp.gba", 0xFA712, (0xFA73C - 0xFA712)

    .section .rodata.horse_race_ticket_controls_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA88C, (0xFA898 - 0xFA88C)

    .section .rodata.horse_race_prize_catalog_trailer_prefix
    .incbin "baserom_jp.gba", 0xFA988, (0xFA9A0 - 0xFA988)

    .section .rodata.horse_race_prize_exchange_padding
    .incbin "baserom_jp.gba", 0xFAA37, (0xFAA38 - 0xFAA37)

    .section .rodata.horse_race_prize_exchange_trailer_prefix
    .incbin "baserom_jp.gba", 0xFAA38, (0xFB11C - 0xFAA38)

    .section .rodata.farm_status_trailer_prefix
    .incbin "baserom_jp.gba", 0xFB224, (0xFB230 - 0xFB224)

    .section .rodata.animal_contest_bad_alloc
    .incbin "baserom_jp.gba", 0xFB618, (0xFB624 - 0xFB618)

    .section .rodata.animal_contest_confirmation_padding
    .incbin "baserom_jp.gba", 0xFB643, (0xFB644 - 0xFB643)

    .section .rodata.animal_contest_trailer
    .incbin "baserom_jp.gba", 0xFB644, (0xFB764 - 0xFB644)

    .section .rodata.records_trailer
    .incbin "baserom_jp.gba", 0xFB8B8, (0xFB938 - 0xFB8B8)

    .section .rodata.staff_credits_trailer_prefix
    .incbin "baserom_jp.gba", 0xFBE88, (0xFBE9C - 0xFBE88)

    .section .rodata.town_map_padding
    .incbin "baserom_jp.gba", 0xFC7E5, (0xFC7E8 - 0xFC7E5)

    .section .rodata.town_map_trailer
    .incbin "baserom_jp.gba", 0xFC7E8, (0xFCCB8 - 0xFC7E8)

    .section .rodata.library_info_trailer
    .incbin "baserom_jp.gba", 0xFCCF3, (0xFD0B0 - 0xFCCF3)

    .section .rodata.library_menu_trailer
    .incbin "baserom_jp.gba", 0xFD0C2, (0xFD0D0 - 0xFD0C2)

    .section .rodata.poultry_shop_menu_padding
    .incbin "baserom_jp.gba", 0xFD0E9, (0xFD0EC - 0xFD0E9)

    .section .rodata.poultry_shop_status_prefix_padding
    .incbin "baserom_jp.gba", 0xFD152, (0xFD154 - 0xFD152)

    .section .rodata.poultry_shop_status_padding
    .incbin "baserom_jp.gba", 0xFD1E3, (0xFD1E4 - 0xFD1E3)

    .section .rodata.poultry_shop_trailer
    .incbin "baserom_jp.gba", 0xFD552, (0xFD560 - 0xFD552)

    .section .rodata.supermarket_trailer
    .incbin "baserom_jp.gba", 0xFD804, (0xFD810 - 0xFD804)

    .section .rodata.clinic_text_padding
    .incbin "baserom_jp.gba", 0xFD9D6, (0xFD9D8 - 0xFD9D6)

    .section .rodata.inn_shop_prefix
    .incbin "baserom_jp.gba", 0xFD9D8, (0xFD9E4 - 0xFD9D8)

    .section .rodata.inn_shop_trailer
    .incbin "baserom_jp.gba", 0xFDBE4, (0xFDBF0 - 0xFDBE4)

    .section .rodata.won_shop_post_dialogue_padding
    .incbin "baserom_jp.gba", 0xFDEA2, (0xFDEA4 - 0xFDEA2)

    .section .rodata.won_shop_trailer
    .incbin "baserom_jp.gba", 0xFDF90, (0xFDF9C - 0xFDF90)

    .section .rodata.winery_shop_trailer
    .incbin "baserom_jp.gba", 0xFE178, (0xFE184 - 0xFE178)

    .section .rodata.special_merchant_shop_trailer
    .incbin "baserom_jp.gba", 0xFE394, (0xFE3A0 - 0xFE394)

    .section .rodata.beach_cafe_shop_trailer
    .incbin "baserom_jp.gba", 0xFE530, (0xFE53C - 0xFE530)

    .section .rodata.blacksmith_menu_padding
    .incbin "baserom_jp.gba", 0xFE6A0, (0xFE6A4 - 0xFE6A0)

    .section .rodata.carpenter_menu_prefix
    .incbin "baserom_jp.gba", 0xFEC84, (0xFEC90 - 0xFEC84)

    .section .rodata.carpenter_catalog_trailer
    .incbin "baserom_jp.gba", 0xFF214, (0xFF218 - 0xFF214)

    .section .rodata.carpenter_trailer
    .incbin "baserom_jp.gba", 0xFF4FC, (0xFF508 - 0xFF4FC)

    .section .rodata.livestock_shop_menu_padding
    .incbin "baserom_jp.gba", 0xFF539, (0xFF53C - 0xFF539)

    .section .rodata.livestock_shop_status_prefix_padding
    .incbin "baserom_jp.gba", 0xFF61A, (0xFF61C - 0xFF61A)

    .section .rodata.livestock_shop_status_padding
    .incbin "baserom_jp.gba", 0xFF6C3, (0xFF6C4 - 0xFF6C3)

    .section .rodata.livestock_shop_dialogue_padding
    .incbin "baserom_jp.gba", 0xFF9A2, (0xFF9A4 - 0xFF9A2)

    .section .rodata.home_storage_prefix
    .incbin "baserom_jp.gba", 0xFF9A4, (0xFF9B4 - 0xFF9A4)

    .section .rodata.home_storage_fridge_trailer
    .incbin "baserom_jp.gba", 0xFFA14, (0xFFA20 - 0xFFA14)

    .section .rodata.home_storage_confirmation_padding
    .incbin "baserom_jp.gba", 0xFFA30, (0xFFA34 - 0xFFA30)

    .section .rodata.home_storage_tool_chest_category_trailer
    .incbin "baserom_jp.gba", 0xFFA44, (0xFFA54 - 0xFFA44)

    .section .rodata.home_storage_shelf_trailer
    .incbin "baserom_jp.gba", 0xFFAB4, (0xFFAC4 - 0xFFAB4)

    .section .rodata.home_storage_trailer
    .incbin "baserom_jp.gba", 0xFFAD4, (0xFFAE0 - 0xFFAD4)

    .section .rodata.blacksmith_upgrade_prefix
    .incbin "baserom_jp.gba", 0xFFAE0, (0xFFAE4 - 0xFFAE0)

    .section .rodata.blacksmith_upgrade_result_padding
    .incbin "baserom_jp.gba", 0xFFD04, (0xFFD08 - 0xFFD04)

    .section .rodata.gift_wrap_prefix
    .incbin "baserom_jp.gba", 0xFFD54, (0xFFD64 - 0xFFD54)

    .section .rodata.gift_wrap_trailer
    .incbin "baserom_jp.gba", 0xFFE64, (0xFFE70 - 0xFFE64)

    .section .rodata.link_communication_trailer
    .incbin "baserom_jp.gba", 0x100130, (0x1005EA - 0x100130)

    .section .rodata.recovery_status_trailer_prefix
    .incbin "baserom_jp.gba", 0x1008F9, (0x1008FC - 0x1008F9)

    .section .rodata.cooking_menu_padding
    .incbin "baserom_jp.gba", 0x100A0F, (0x100A10 - 0x100A0F)

    .section .rodata.cooking_result_padding
    .incbin "baserom_jp.gba", 0x100A22, (0x100A24 - 0x100A22)

    .section .rodata.cooking_recipe_actions_padding
    .incbin "baserom_jp.gba", 0x100B21, (0x100B24 - 0x100B21)

    .section .rodata.cooking_recipe_actions_extra_padding
    .incbin "baserom_jp.gba", 0x100B4E, (0x100B50 - 0x100B4E)

    .section .rodata.cooking_recipe_inventory_trailer
    .incbin "baserom_jp.gba", 0x100C24, (0x103194 - 0x100C24)

    .section .rodata.animal_unnamed_trailer

    .global gUnk_08103660
gUnk_08103660:
    .incbin "baserom_jp.gba", 0x10319C, (0x1031BC - 0x10319C)

    .global gUnk_08103680
gUnk_08103680:
    .incbin "baserom_jp.gba", 0x1031BC, (0x1031DC - 0x1031BC)

    .global gUnk_081036A0
gUnk_081036A0:
    .incbin "baserom_jp.gba", 0x1031DC, (0x1031FC - 0x1031DC)

    .global gActorStateMaxValues
gActorStateMaxValues:
    .incbin "baserom_jp.gba", 0x1031FC, 0x6
    .incbin "baserom_jp.gba", 0x103202, (0x1032C4 - 0x103202)

    .section .rodata.fishing_results_text_padding
    .incbin "baserom_jp.gba", 0x103509, (0x10350C - 0x103509)

    .section .rodata.fishing_results_trailer
    .incbin "baserom_jp.gba", 0x1035F8, (0x103BFC - 0x1035F8)

    .global gText_CharacterName_Empty
gText_CharacterName_Empty:
    .incbin "baserom_jp.gba", 0x103BFC, (0x103C1C - 0x103BFC)

    .section .rodata.character_names_text_padding
    .incbin "baserom_jp.gba", 0x103D9B, (0x103D9C - 0x103D9B)

    .section .rodata.character_names_table_trailer
    .incbin "baserom_jp.gba", 0x103EF4, (0x10447C - 0x103EF4)

    .section .rodata.calendar_dynamic_season_names_trailer
    .incbin "baserom_jp.gba", 0x10448C, (0x1044B0 - 0x10448C)

    .section .rodata.calendar_festival_dynamic_padding
    .incbin "baserom_jp.gba", 0x1048DB, (0x1048DC - 0x1048DB)

    .section .rodata.calendar_no_plans_trailer
    .incbin "baserom_jp.gba", 0x104935, (0x104958 - 0x104935)

    .section .rodata.possessive_labels_trailer
    .incbin "baserom_jp.gba", 0x104988, (0x104994 - 0x104988)

    .section .rodata.random_item_fallback_trailer
    .incbin "baserom_jp.gba", 0x10499C, (0x105A24 - 0x10499C)

    .global gMapData
gMapData:
    .incbin "baserom_jp.gba", 0x105A24, (0x1070F4 - 0x105A24)

    .section .rodata.harvest_sprite_minigames_animal_husbandry_trailer
    .incbin "baserom_jp.gba", 0x10737B, (0x1073B9 - 0x10737B)

.section .rodata.festival_contestants_set2_trailer
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
    .incbin "baserom_jp.gba", 0x118CF4, (0x13BCF8 - 0x118CF4)
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

	.section .rodata.festival_contestants_set1_trailer_prefix

	.global gUnk_080FA99E
gUnk_080FA99E:
	.incbin "baserom_us.gba", 0xFA99E, 0xA2

	.section .rodata.horse_race_dialogue_trailer

	.global gUnk_080FAE6A
gUnk_080FAE6A:
	.incbin "baserom_us.gba", 0xFAE6A, 0x32

	.section .rodata.horse_race_ticket_ui_padding
	.incbin "baserom_us.gba", 0xFAFC6, (0xFAFC8 - 0xFAFC6)

	.section .rodata.horse_race_ticket_controls_trailer_prefix

	.global gUnk_080FAFF4
gUnk_080FAFF4:
	.incbin "baserom_us.gba", 0xFAFF4, 0xC

	.section .rodata.horse_race_prize_catalog_trailer_prefix

	.global gUnk_080FB0F0
gUnk_080FB0F0:
	.incbin "baserom_us.gba", 0xFB0F0, 0x18

	.section .rodata.horse_race_prize_exchange_trailer

	.global gUnk_080FB1A6
gUnk_080FB1A6:
	.incbin "baserom_us.gba", 0xFB1A6, 0x3E

	.global gUnk_080FB1E4
gUnk_080FB1E4:
	.incbin "baserom_us.gba", 0xFB1E4, 0x50

	.global gUnk_080FB234
gUnk_080FB234:
	.incbin "baserom_us.gba", 0xFB234, 0x8

	.global gUnk_080FB23C
gUnk_080FB23C:
	.incbin "baserom_us.gba", 0xFB23C, 0x40

	.global gUnk_080FB27C
gUnk_080FB27C:
	.incbin "baserom_us.gba", 0xFB27C, 0x8

	.global gUnk_080FB284
gUnk_080FB284:
	.incbin "baserom_us.gba", 0xFB284, 0x4C

	.global gUnk_080FB2D0
gUnk_080FB2D0:
	.incbin "baserom_us.gba", 0xFB2D0, 0x24

	.global gUnk_080FB2F4
gUnk_080FB2F4:
	.incbin "baserom_us.gba", 0xFB2F4, 0xC

	.global gUnk_080FB300
gUnk_080FB300:
	.incbin "baserom_us.gba", 0xFB300, 0x8

	.global gUnk_080FB308
gUnk_080FB308:
	.incbin "baserom_us.gba", 0xFB308, 0x90

	.global gUnk_080FB398
gUnk_080FB398:
	.incbin "baserom_us.gba", 0xFB398, 0x34

	.global gUnk_080FB3CC
gUnk_080FB3CC:
	.incbin "baserom_us.gba", 0xFB3CC, 0x54

	.global gUnk_080FB420
gUnk_080FB420:
	.incbin "baserom_us.gba", 0xFB420, 0x4C

	.global gUnk_080FB46C
gUnk_080FB46C:
	.incbin "baserom_us.gba", 0xFB46C, 0x18

	.global gUnk_080FB484
gUnk_080FB484:
	.incbin "baserom_us.gba", 0xFB484, 0x50

	.global gUnk_080FB4D4
gUnk_080FB4D4:
	.incbin "baserom_us.gba", 0xFB4D4, 0x48

	.global gUnk_080FB51C
gUnk_080FB51C:
	.incbin "baserom_us.gba", 0xFB51C, 0x4

	.global gUnk_080FB520
gUnk_080FB520:
	.incbin "baserom_us.gba", 0xFB520, 0x14

	.global gUnk_080FB534
gUnk_080FB534:
	.incbin "baserom_us.gba", 0xFB534, 0x8

	.global gUnk_080FB53C
gUnk_080FB53C:
	.incbin "baserom_us.gba", 0xFB53C, 0x8

	.global gUnk_080FB544
gUnk_080FB544:
	.incbin "baserom_us.gba", 0xFB544, 0x34

	.global gUnk_080FB578
gUnk_080FB578:
	.incbin "baserom_us.gba", 0xFB578, 0x5C

	.global gUnk_080FB5D4
gUnk_080FB5D4:
	.incbin "baserom_us.gba", 0xFB5D4, 0x60

	.global gUnk_080FB634
gUnk_080FB634:
	.incbin "baserom_us.gba", 0xFB634, 0x8C

	.global gUnk_080FB6C0
gUnk_080FB6C0:
	.incbin "baserom_us.gba", 0xFB6C0, 0x50

	.global gUnk_080FB710
gUnk_080FB710:
	.incbin "baserom_us.gba", 0xFB710, 0x28

	.global gUnk_080FB738
gUnk_080FB738:
	.incbin "baserom_us.gba", 0xFB738, 0x1C

	.global gUnk_080FB754
gUnk_080FB754:
	.incbin "baserom_us.gba", 0xFB754, 0x4C

	.global gUnk_080FB7A0
gUnk_080FB7A0:
	.incbin "baserom_us.gba", 0xFB7A0, 0x50

	.global gUnk_080FB7F0
gUnk_080FB7F0:
	.incbin "baserom_us.gba", 0xFB7F0, 0x34

	.section .rodata.farm_status_trailer_prefix

	.global gUnk_080FB954
gUnk_080FB954:
	.incbin "baserom_us.gba", 0xFB954, 0xC

	.section .rodata.animal_contest_bad_alloc
	.incbin "baserom_us.gba", 0xFBD0C, (0xFBD18 - 0xFBD0C)

	.section .rodata.animal_contest_confirmation_padding
	.incbin "baserom_us.gba", 0xFBD2F, (0xFBD30 - 0xFBD2F)

	.section .rodata.animal_contest_trailer

	.global gUnk_080FBD30
gUnk_080FBD30:
	.incbin "baserom_us.gba", 0xFBD30, 0x64

	.global gUnk_080FBD94
gUnk_080FBD94:
	.incbin "baserom_us.gba", 0xFBD94, 0x10

	.global gUnk_080FBDA4
gUnk_080FBDA4:
	.incbin "baserom_us.gba", 0xFBDA4, 0x50

	.global gUnk_080FBDF4
gUnk_080FBDF4:
	.incbin "baserom_us.gba", 0xFBDF4, 0x30

	.global gUnk_080FBE24
gUnk_080FBE24:
	.incbin "baserom_us.gba", 0xFBE24, 0x20

	.global gUnk_080FBE44
gUnk_080FBE44:
	.incbin "baserom_us.gba", 0xFBE44, 0x20

	.global gUnk_080FBE64
gUnk_080FBE64:
	.incbin "baserom_us.gba", 0xFBE64, 0x3

	.global gUnk_080FBE67
gUnk_080FBE67:
	.incbin "baserom_us.gba", 0xFBE67, 0x15

	.section .rodata.records_trailer

	.global gUnk_080FC024
gUnk_080FC024:
	.incbin "baserom_us.gba", 0xFC024, 0x42

	.global gUnk_080FC066
gUnk_080FC066:
	.incbin "baserom_us.gba", 0xFC066, 0x1C

	.global gUnk_080FC082
gUnk_080FC082:
	.incbin "baserom_us.gba", 0xFC082, (0xFC0A4 - 0xFC082)

	.section .rodata.staff_credits_trailer_prefix

	.global gUnk_080FC6B8
gUnk_080FC6B8:
	.incbin "baserom_us.gba", 0xFC6B8, (0xFC6C2 - 0xFC6B8)

	.global gUnk_080FC6C2
gUnk_080FC6C2:
	.incbin "baserom_us.gba", 0xFC6C2, 0xA

	.section .rodata.town_map_padding
	.incbin "baserom_us.gba", 0xFD07E, (0xFD080 - 0xFD07E)

	.section .rodata.town_map_trailer

	.global gUnk_080FD080
gUnk_080FD080:
	.incbin "baserom_us.gba", 0xFD080, 0x14

	.global gUnk_080FD094
gUnk_080FD094:
	.incbin "baserom_us.gba", 0xFD094, 0x14

	.global gUnk_080FD0A8
gUnk_080FD0A8:
	.incbin "baserom_us.gba", 0xFD0A8, 0x2F8

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

	.section .rodata.poultry_shop_menu_padding
	.incbin "baserom_us.gba", 0xFD985, (0xFD988 - 0xFD985)

	.section .rodata.poultry_shop_status_prefix_padding
	.incbin "baserom_us.gba", 0xFD9EE, (0xFD9F0 - 0xFD9EE)

	.section .rodata.poultry_shop_status_padding
	.incbin "baserom_us.gba", 0xFDA7A, (0xFDA7C - 0xFDA7A)

	.section .rodata.poultry_shop_trailer
	.incbin "baserom_us.gba", 0xFDDCC, (0xFDDD8 - 0xFDDCC)

	.section .rodata.supermarket_primary_text_padding
	.incbin "baserom_us.gba", 0xFDFA1, (0xFDFA4 - 0xFDFA1)

	.section .rodata.supermarket_secondary_text_padding
	.incbin "baserom_us.gba", 0xFE043, (0xFE044 - 0xFE043)

	.section .rodata.supermarket_trailer
	.incbin "baserom_us.gba", 0xFE044, (0xFE050 - 0xFE044)

	.section .rodata.clinic_text_padding
	.incbin "baserom_us.gba", 0xFE257, (0xFE258 - 0xFE257)

	.section .rodata.inn_shop_prefix
	.incbin "baserom_us.gba", 0xFE258, (0xFE264 - 0xFE258)

	.section .rodata.inn_shop_trailer
	.incbin "baserom_us.gba", 0xFE478, (0xFE484 - 0xFE478)

	.section .rodata.won_shop_trailer
	.incbin "baserom_us.gba", 0xFE734, (0xFE740 - 0xFE734)

	.section .rodata.unextracted_shop_data

	.section .rodata.winery_shop_trailer
	.incbin "baserom_us.gba", 0xFE8F0, (0xFE8FC - 0xFE8F0)

	.section .rodata.unextracted_shop_data

	.section .rodata.special_merchant_shop_trailer
	.incbin "baserom_us.gba", 0xFEAE8, (0xFEAF4 - 0xFEAE8)

	.section .rodata.beach_cafe_shop_trailer
	.incbin "baserom_us.gba", 0xFEC70, (0xFEC7C - 0xFEC70)

    .section .rodata.carpenter_menu_prefix
    .incbin "baserom_us.gba", 0xFF350, (0xFF35C - 0xFF350)

    .section .rodata.carpenter_catalog_trailer
    .global gUnk_080FF838
gUnk_080FF838:
    .incbin "baserom_us.gba", 0xFF838, 0x4

    .section .rodata.carpenter_trailer
    .incbin "baserom_us.gba", 0xFFB54, (0xFFB60 - 0xFFB54)

	.section .rodata.livestock_shop_menu_padding
	.incbin "baserom_us.gba", 0xFFB8F, (0xFFB90 - 0xFFB8F)

	.section .rodata.livestock_shop_status_prefix_padding
	.incbin "baserom_us.gba", 0xFFC6E, (0xFFC70 - 0xFFC6E)

	.section .rodata.livestock_shop_status_padding
	.incbin "baserom_us.gba", 0xFFD3B, (0xFFD3C - 0xFFD3B)

	.section .rodata.livestock_shop_trailer_prefix
	.incbin "baserom_us.gba", 0x100024, (0x100030 - 0x100024)

	.section .rodata.home_storage_prefix

	.global gUnk_08100030
gUnk_08100030:
	.incbin "baserom_us.gba", 0x100030, 0x4

	.section .rodata.home_storage_fridge_trailer
	.incbin "baserom_us.gba", 0x10009C, (0x1000A8 - 0x10009C)

	.section .rodata.home_storage_tool_chest_category_padding
	.global gUnk_081000B0
gUnk_081000B0:
	.incbin "baserom_us.gba", 0x1000B0, 0x4

	.section .rodata.home_storage_tool_chest_category_trailer
	.incbin "baserom_us.gba", 0x1000C4, (0x1000D0 - 0x1000C4)

	.global gUnk_081000D0
gUnk_081000D0:
	.incbin "baserom_us.gba", 0x1000D0, 0x4

	.section .rodata.home_storage_shelf_trailer
	.incbin "baserom_us.gba", 0x100138, (0x100144 - 0x100138)

	.global gUnk_08100144
gUnk_08100144:
	.incbin "baserom_us.gba", 0x100144, 0x4

	.section .rodata.home_storage_trailer
	.incbin "baserom_us.gba", 0x10015C, (0x100168 - 0x10015C)

	.section .rodata.blacksmith_upgrade_prefix

	.global gUnk_08100168
gUnk_08100168:
	.incbin "baserom_us.gba", 0x100168, 0x4

	.section .rodata.blacksmith_upgrade_result_padding

	.global gUnk_08100398
gUnk_08100398:
	.incbin "baserom_us.gba", 0x100398, 0x4

	.section .rodata.gift_wrap_prefix
	.incbin "baserom_us.gba", 0x1003E4, (0x1003F0 - 0x1003E4)

	.global gUnk_081003F0
gUnk_081003F0:
	.incbin "baserom_us.gba", 0x1003F0, 0x4

	.section .rodata.gift_wrap_trailer
	.incbin "baserom_us.gba", 0x1004D4, (0x1004E0 - 0x1004D4)

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

	.section .rodata.recovery_status_padding
	.incbin "baserom_us.gba", 0x100DE1, (0x100DE4 - 0x100DE1)

	.section .rodata.cooking_menu_padding
	.incbin "baserom_us.gba", 0x100EEF, (0x100EF0 - 0x100EEF)

	.section .rodata.cooking_result_padding
	.incbin "baserom_us.gba", 0x100F03, (0x100F04 - 0x100F03)

	.section .rodata.cooking_recipe_actions_padding
	.incbin "baserom_us.gba", 0x100FDD, (0x100FE0 - 0x100FDD)

	.section .rodata.cooking_recipe_actions_extra_padding
	.incbin "baserom_us.gba", 0x101007, (0x101008 - 0x101007)

	.section .rodata.cooking_recipe_inventory_trailer

	.global gUnk_081010E8
gUnk_081010E8:
	.incbin "baserom_us.gba", 0x1010E8, 0x24

	.global gUnk_0810110C
gUnk_0810110C:
	.incbin "baserom_us.gba", 0x10110C, 0x254C

	.section .rodata.animal_unnamed_trailer

	.global gUnk_08103660
gUnk_08103660:
	.incbin "baserom_us.gba", 0x103660, 0x20

	.global gUnk_08103680
gUnk_08103680:
	.incbin "baserom_us.gba", 0x103680, 0x20

	.global gUnk_081036A0
gUnk_081036A0:
	.incbin "baserom_us.gba", 0x1036A0, 0x20

	.global gActorStateMaxValues
gActorStateMaxValues:
	.incbin "baserom_us.gba", 0x1036C0, 0x6
	.incbin "baserom_us.gba", 0x1036C6, (0x1036D4 - 0x1036C6)

	.global gUnk_081036D4
gUnk_081036D4:
	.incbin "baserom_us.gba", 0x1036D4, (0x103788 - 0x1036D4)

	.section .rodata.fishing_results_text_padding
	.incbin "baserom_us.gba", 0x103A16, (0x103A18 - 0x103A16)

	.section .rodata.fishing_results_trailer
	.incbin "baserom_us.gba", 0x103B04, (0x103B10 - 0x103B04)

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

	.global gText_CharacterName_Empty
gText_CharacterName_Empty:
	.incbin "baserom_us.gba", 0x104108, 0x1

	.global gUnk_08104109
gUnk_08104109:
	.incbin "baserom_us.gba", 0x104109, 0x5

	.global gUnk_0810410E
gUnk_0810410E:
	.incbin "baserom_us.gba", 0x10410E, 0x5

	.global gUnk_08104113
gUnk_08104113:
	.incbin "baserom_us.gba", 0x104113, 0x5

	.global gUnk_08104118
gUnk_08104118:
	.incbin "baserom_us.gba", 0x104118, 0x5

	.global gUnk_0810411D
gUnk_0810411D:
	.incbin "baserom_us.gba", 0x10411D, 0x5

	.global gUnk_08104122
gUnk_08104122:
	.incbin "baserom_us.gba", 0x104122, (0x104128 - 0x104122)

	.section .rodata.character_names_text_padding
	.incbin "baserom_us.gba", 0x104256, (0x104258 - 0x104256)

	.section .rodata.character_names_table_trailer
	.incbin "baserom_us.gba", 0x1043B0, (0x1043BC - 0x1043B0)

	.section .rodata.reference_guide_harvest_sprite_minigames_after_character_names

	.global gUnk_081043BC
gUnk_081043BC:
	.incbin "baserom_us.gba", 0x1043BC, 0x57C

	.section .rodata.calendar_dynamic_season_names_trailer
	.incbin "baserom_us.gba", 0x104958, (0x10497C - 0x104958)

	.section .rodata.calendar_festival_dynamic_padding
	.incbin "baserom_us.gba", 0x104D96, 0x2

	.section .rodata.calendar_no_plans_trailer
	.incbin "baserom_us.gba", 0x104DEA, (0x104E0C - 0x104DEA)

	.section .rodata.static_data_after_possessive_labels
	.incbin "baserom_us.gba", 0x104E40, (0x104E4C - 0x104E40)

	.section .rodata.random_item_fallback_trailer

	.global gUnk_08104E54
gUnk_08104E54:
	.incbin "baserom_us.gba", 0x104E54, 0x20

	.global gUnk_08104E74
gUnk_08104E74:
	.incbin "baserom_us.gba", 0x104E74, 0x38

	.global gUnk_08104EAC
gUnk_08104EAC:
	.incbin "baserom_us.gba", 0x104EAC, 0x24

	.global gUnk_08104ED0
gUnk_08104ED0:
	.incbin "baserom_us.gba", 0x104ED0, 0x2

	.global gUnk_08104ED2
gUnk_08104ED2:
	.incbin "baserom_us.gba", 0x104ED2, 0x7

	.global gUnk_08104ED9
gUnk_08104ED9:
	.incbin "baserom_us.gba", 0x104ED9, 0x7

	.global gUnk_08104EE0
gUnk_08104EE0:
	.incbin "baserom_us.gba", 0x104EE0, 0x7

	.global gUnk_08104EE7
gUnk_08104EE7:
	.incbin "baserom_us.gba", 0x104EE7, 0x755

	.global gUnk_0810563C
gUnk_0810563C:
	.incbin "baserom_us.gba", 0x10563C, 0xCC

	.global gUnk_08105708
gUnk_08105708:
	.incbin "baserom_us.gba", 0x105708, 0x7D4

	.global gMapData
gMapData: @ map data
	.incbin "baserom_us.gba", 0x105EDC, 0xA50

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

	.section .rodata.festival_contestants_set2_trailer

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

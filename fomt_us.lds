OUTPUT_ARCH(arm)

_M4aNumMusicPlayers = 5;
_M4aMaxLines = 0x50;

gMPlayJumpTableTemplate = 0x08139A88;
gScaleTable = 0x08139B18;
gFreqTable = 0x08139BCC;
gPcmSamplesPerVBlankTable = 0x08139BFC;
gCgbScaleTable = 0x08139C14;
gCgbFreqTable = 0x08139C98;
gNoiseTable = 0x08139CB0;
gCgb3Vol = 0x08139CEC;
gClockTable = 0x08139CFC;
gXcmdTable = 0x08139D30;

MEMORY
{
    EWRAM (w!x) : ORIGIN = 0x02000000, LENGTH = 256K
    IWRAM (w!x) : ORIGIN = 0x03000000, LENGTH = 32K
    ROM   (rx)  : ORIGIN = 0x08000000, LENGTH = 32M
}

SECTIONS
{
    .ewram_bss (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/sound_data.o(.sbss);
        . = ALIGN(4); src/m4a.o(.gSoundInfo);
        . = ALIGN(4); src/m4a.o(.gMPlayJumpTable);
        . = ALIGN(4); src/m4a.o(.gCgbChans);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerA);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerB);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerC);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerE);
        . = ALIGN(4); src/m4a.o(.gMPlayMemAccArea);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerD);
        __ewram_bss_end = .;
    } > EWRAM

    .bss (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/m4a.o(.bss);
        . = ALIGN(4);
        . = 0x000400; gUnk_03000400 = .;
        . = 0x000402; gUnk_03000402 = .;
        . = 0x000404; gUnk_03000404 = .;
        . = 0x000408; gUnk_03000408 = .;
        . = 0x00040C; gUnk_0300040C = .;
        . = 0x000410; gUnk_03000410 = .;
        . = 0x000414; gUnk_03000414 = .;
        . = 0x000418; gUnk_03000418 = .;
        . = 0x00041C; gUnk_0300041C = .;
        . = 0x000420; gUnk_03000420 = .;
        . = 0x000430; gUnk_03000430 = .;
        . = 0x000450; gUnk_03000450 = .;
        . = 0x000490; /* end */
    } > IWRAM

    .rom : ALIGN(4)
    {
        src/crt0.o(.rom_header);
        asm/main.o(.text);
        asm/sram_proxy_1.o(.text);
        asm/interrupt.o(.text);
        src/new.o(.text);
        src/pure_virtual.o(.text);
        asm/sram_proxy_2.o(.text);
        src/scene.o(.text);
        asm/scene.o(.text);
        asm/intro_scene.o(.text);
        asm/new_game.o(.text);
        src/hardware.o(.text);
        asm/hardware.o(.text);
        src/farm.o(.text);
        src/field.o(.text);
        src/shipping_bin.o(.text);
        src/tool_chest.o(.text);
        src/fridge.o(.text);
        src/shelf.o(.text);
        src/record_player.o(.text);
        src/code_0800BC58.o(.text);
        src/farm_house.o(.text);
        src/coop.o(.text);
        src/barn.o(.text);
        src/item.o(.text);
        src/code_0800E2E4.o(.text);
        src/farmer.o(.text);
        src/rucksack_item.o(.text);
        src/held_item.o(.text);
        src/rucksack.o(.text);
        asm/more_items.o(.text);
        asm/game_scene.o(.text);
        asm/game_state.o(.text);
        src/entity.o(.text);
        src/code_entity_08020018.o(.text);
        asm/code_entities.o(.text);
        src/entity_actor.o(.text);
        asm/code_entities_080320DC.o(.text);
        src/npc_entity.o(.text);
        asm/code_entities_08034CEC.o(.text);

        asm/code_0803A8A4.o(.text);
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);

        src/actor.o(.text);
        src/animal.o(.text);
        src/pet.o(.text);
        src/livestock.o(.text);
        src/barn_animal.o(.text);
        src/dog.o(.text);
        src/horse.o(.text);
        src/chicken.o(.text);
        src/cow.o(.text);
        src/sheep.o(.text);
        src/code_actor_0809BFE8.o(.text);
        asm/code_actor_0809BFE8.o(.text);
        src/npc.o(.text);
        src/bachelorette.o(.text);
        src/harvest_sprite.o(.text);

        asm/code_809E804.o(.text);

        src/m4a_1.o(.text);
        src/m4a.o(.text);
        asm/code_lib_syscall.o(.text);
        asm/code_lib_sram.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        /* these need to be recompiled using -mthumb-interwork */
        /* *libc.a:memcmp.o(.text); */
        /* *libc.a:memcpy.o(.text); */
        /* *libc.a:memmove.o(.text); */
        /* *libc.a:memset.o(.text); */
        /* *libc.a:strcat.o(.text); */
        /* *libc.a:strcpy.o(.text); */
        /* *libc.a:strlen.o(.text); */
        asm/code_libc_string.o(.text);

        asm/code_linkonce.o(.text.code_080D3BC0);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        asm/code_linkonce.o(.text.code_080D68C0);
        *(.gnu.linkonce.t.__as__5SheepRC5Sheep);
        *(.gnu.linkonce.t.__as__3CowRC3Cow);
        *(.gnu.linkonce.t.__as__9LivestockRC9Livestock);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        asm/code_linkonce.o(.text.code_080D7CFC);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        asm/code_linkonce.o(.text.code_080E0EF0);

        *(.gnu.linkonce.d.__vt_6AScene);
        *(.gnu.linkonce.d.__vt_13AUnk_0800080C);
        . = ALIGN(4); asm/vtables.o(.rodata);
        *(.gnu.linkonce.d.__vt_7AEntity);
        . = ALIGN(4); asm/vtables.o(.rodata.080E6284);
        *(.gnu.linkonce.d.__vt_13AScriptEngine);
        . = ALIGN(4); asm/vtables.o(.rodata.080E7824);

        . = ALIGN(4); asm/data/data_080E8610.o(.rodata);
        data/text/common/sram_signature.o(.rodata.sram_signature);
        asm/data/data_080E8610.o(.rodata.sram_signature_trailer);
        . = ALIGN(4); data/text/new_game_menu.o(.rodata.new_game_menu_labels);
        . = ALIGN(4); src/new_game_menu_data.o(.rodata.new_game_menu_label_pointers);
        . = ALIGN(4); data/text/new_game_status.o(.rodata.new_game_status_labels);
        . = ALIGN(4); data/text/new_game_help.o(.rodata.new_game_help_text);
        . = ALIGN(4); data/text/new_game_save.o(.rodata.new_game_save_text);
        . = ALIGN(4); asm/data/data_080E8610.o(.rodata.new_game_save_trailer);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_prefix);
        . = ALIGN(4); asm/data/data_080E8610.o(.rodata.new_game_identity_prefix_trailer);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_labels);
        . = ALIGN(4); asm/data/data_080E8610.o(.rodata.new_game_identity_labels_trailer);
        data/text/new_game_name_entry.o(.rodata.new_game_name_entry_characters);
        data/text/new_game_name_entry_ui.o(.rodata.new_game_name_entry_ui);
        asm/data/data_080E8610.o(.rodata.new_game_name_entry_trailer);
        asm/data/data_080E8610.o(.rodata.field_plot_prefix);
        src/field_data.o(.rodata.field_plot_weather_ordinary);
        src/field_data.o(.rodata.field_plot_weather_special_3);
        src/field_data.o(.rodata.field_plot_weather_special_4);
        src/field_data.o(.rodata.field_plot_growth_transitions);
        src/field_data.o(.rodata.field_plot_definitions);
        src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        . = ALIGN(4); src/item.o(.rodata);
        . = ALIGN(4); data/text/tool.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/item.o(.rodata.item_tool);
        FILL(0xFF);
        . = ALIGN(4); data/text/food.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/item.o(.rodata.item_food);
        FILL(0xFF);
        . = ALIGN(4); data/text/article.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/item.o(.rodata.item_article);
        FILL(0xFF);
        . = ALIGN(4); src/item.o(.rodata.item_product);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata);
        FILL(0x00);
        data/text/calendar.o(.rodata.calendar.season);
        data/text/calendar.o(.rodata.calendar.none);
        data/text/calendar.o(.rodata.calendar.weekday);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata.calendar_trailer);
        FILL(0x00);
        data/text/load_error.o(.rodata.load_error);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata.load_error_trailer);
        FILL(0x00);
        data/text/help_menu.o(.rodata.help_menu);
        asm/data/data_080F0348.o(.rodata.help_menu_trailer);
        FILL(0x00);
        data/text/animal_memorial.o(.rodata.animal_memorial);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata.animal_memorial_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/not_available.o(.rodata.not_available);
        asm/data/data_080F0348.o(.rodata.not_available_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/fixed_labels.o(.rodata.fixed_labels);
        asm/data/data_080F0348.o(.rodata.fixed_labels_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/common/ui_error.o(.rodata.ui_error);
        asm/data/data_080F0348.o(.rodata.ui_error_trailer);
        FILL(0x00);
        . = ALIGN(4); src/menu_data.o(.rodata.menu_entry_ids);
        FILL(0x00);
        . = ALIGN(4); data/text/menu.o(.rodata.menu_labels);
        FILL(0x00);
        . = ALIGN(4); src/menu_data.o(.rodata.menu_label_pointers);
        FILL(0xFF);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata.menu_data_trailer);
        FILL(0xFF);
        . = ALIGN(4); src/data_schedules.o(.rodata);
        . = ALIGN(4); asm/data/data_080F1A80.o(.rodata);
        . = ALIGN(4); src/script_engine.o(.rodata);
        . = ALIGN(4); asm/data/data_080F9EB8.o(.rodata.reference_guide_harvest_sprite_minigames_prefix);
        . = 0x103788; data/text/fishing_results.o(.rodata.fishing_results);
        . = 0x103A18; src/fishing_results_data.o(.rodata.fishing_record_names);
        . = 0x103B04; asm/data/data_080F9EB8.o(.rodata.fishing_results_trailer);
        . = 0x103B10; asm/data/data_080F9EB8.o(.rodata.reference_guide_harvest_sprite_minigames_after_fishing_results);
        . = 0x104128; data/text/character_names.o(.rodata.character_names);
        . = 0x104258; src/character_names_data.o(.rodata.character_name_entries);
        . = 0x1043B0; asm/data/data_080F9EB8.o(.rodata.character_names_table_trailer);
        . = 0x1043BC; asm/data/data_080F9EB8.o(.rodata.reference_guide_harvest_sprite_minigames_after_character_names);
        . = 0x1084B0; data/text/reference_guide/harvest_sprite_minigames.o(.rodata.reference_guide_harvest_sprite_minigames_text);
        . = 0x108F68; src/reference_guide.o(.rodata.reference_guide_harvest_sprite_minigames_lines);
        . = 0x109124; data/text/reference_guide/festival_hints.o(.rodata.reference_guide_festival_hints_text);
        . = 0x109650; src/reference_guide.o(.rodata.reference_guide_festival_hints_lines);
        . = 0x109734; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page02_text);
        . = 0x109A0C; src/reference_guide.o(.rodata.reference_guide_controls_page02_lines);
        . = 0x109AD0; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page03_text);
        . = 0x109CA0; src/reference_guide.o(.rodata.reference_guide_controls_page03_lines);
        . = 0x109D0C; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page04_text);
        . = 0x109D98; src/reference_guide.o(.rodata.reference_guide_controls_page04_lines);
        . = 0x109DCC; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page05_text);
        . = 0x109EDC; src/reference_guide.o(.rodata.reference_guide_controls_page05_lines);
        . = 0x109F38; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page06_text);
        . = 0x10A08C; src/reference_guide.o(.rodata.reference_guide_controls_page06_lines);
        . = 0x10A0F8; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page07_text);
        . = 0x10A1A4; src/reference_guide.o(.rodata.reference_guide_controls_page07_lines);
        . = 0x10A1FC; data/text/reference_guide/controls.o(.rodata.reference_guide_controls_page08_text);
        . = 0x10A344; src/reference_guide.o(.rodata.reference_guide_controls_page08_lines);
        . = 0x10A370; src/reference_guide.o(.rodata.reference_guide_tool_and_item_controls_additional_lines);
        . = 0x10A3B0; data/text/reference_guide/crops.o(.rodata.reference_guide_crops_page09_text);
        . = 0x10A7CC; src/reference_guide.o(.rodata.reference_guide_crops_page09_lines);
        . = 0x10A8D0; data/text/reference_guide/crops.o(.rodata.reference_guide_crops_page10_text);
        . = 0x10AC60; src/reference_guide.o(.rodata.reference_guide_crops_page10_lines);
        . = 0x10ADF8; data/text/reference_guide/mines.o(.rodata.reference_guide_mines_text);
        . = 0x10B1B0; src/reference_guide.o(.rodata.reference_guide_mines_lines);
        . = 0x10B2A0; data/text/reference_guide/cooking.o(.rodata.reference_guide_how_to_cook_text);
        . = 0x10B6C8; src/reference_guide.o(.rodata.reference_guide_how_to_cook_lines);
        . = 0x10B824; data/text/reference_guide/stamina.o(.rodata.reference_guide_stamina_and_fatigue_text);
        . = 0x10BBB0; src/reference_guide.o(.rodata.reference_guide_stamina_and_fatigue_lines);
        . = 0x10BC94; data/text/reference_guide/sell_price.o(.rodata.reference_guide_sell_price_text);
        . = 0x10C11C; src/reference_guide.o(.rodata.reference_guide_sell_price_lines);
        . = 0x10C25C; data/text/reference_guide/using_tools.o(.rodata.reference_guide_using_tools_text);
        . = 0x10D14C; src/reference_guide.o(.rodata.reference_guide_using_tools_lines);
        . = 0x10D550; data/text/reference_guide/fishing.o(.rodata.reference_guide_fishing_text);
        . = 0x10DA4C; src/reference_guide.o(.rodata.reference_guide_fishing_lines);
        . = 0x10DB50; data/text/reference_guide/animal_care.o(.rodata.reference_guide_animal_care_text);
        . = 0x10E414; src/reference_guide.o(.rodata.reference_guide_animal_care_lines);
        . = 0x10E5B0; data/text/reference_guide/awl_profiles/takakura.o(.rodata.reference_guide_awl_takakura_text);
        . = 0x10E6E8; src/reference_guide.o(.rodata.reference_guide_awl_takakura_lines);
        . = 0x10E734; data/text/reference_guide/awl_profiles/romana.o(.rodata.reference_guide_awl_romana_text);
        . = 0x10E904; src/reference_guide.o(.rodata.reference_guide_awl_romana_lines);
        . = 0x10E95C; data/text/reference_guide/awl_profiles/lumina.o(.rodata.reference_guide_awl_lumina_text);
        . = 0x10EA48; src/reference_guide.o(.rodata.reference_guide_awl_lumina_lines);
        . = 0x10EA80; data/text/reference_guide/awl_profiles/sebastian.o(.rodata.reference_guide_awl_sebastian_text);
        . = 0x10EBD4; src/reference_guide.o(.rodata.reference_guide_awl_sebastian_lines);
        . = 0x10EC1C; data/text/reference_guide/awl_profiles/wally.o(.rodata.reference_guide_awl_wally_text);
        . = 0x10ECDC; src/reference_guide.o(.rodata.reference_guide_awl_wally_lines);
        . = 0x10ED04; data/text/reference_guide/awl_profiles/chris.o(.rodata.reference_guide_awl_chris_text);
        . = 0x10EDF8; src/reference_guide.o(.rodata.reference_guide_awl_chris_lines);
        . = 0x10EE34; data/text/reference_guide/awl_profiles/hugh.o(.rodata.reference_guide_awl_hugh_text);
        . = 0x10EE9C; src/reference_guide.o(.rodata.reference_guide_awl_hugh_lines);
        . = 0x10EEB8; data/text/reference_guide/awl_profiles/grant.o(.rodata.reference_guide_awl_grant_text);
        . = 0x10F02C; src/reference_guide.o(.rodata.reference_guide_awl_grant_lines);
        . = 0x10F07C; data/text/reference_guide/awl_profiles/samantha.o(.rodata.reference_guide_awl_samantha_text);
        . = 0x10F0F8; src/reference_guide.o(.rodata.reference_guide_awl_samantha_lines);
        . = 0x10F110; asm/data/data_080F9EB8.o(.rodata.reference_guide_awl_samantha_trailer);
        . = 0x1177F6; asm/data/data_080F9EB8.o(.rodata);
        . = ALIGN(4); src/sound_data.o(.rodata.*);
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
    } > ROM = 0xFF

    .iwram : ALIGN(4)
    {
        asm/code_iwram.o(.iwram);
    } > IWRAM AT> ROM = 0xFF

    __iwram_vma     = ADDR(.iwram);
    __iwram_vma_end = ADDR(.iwram) + SIZEOF(.iwram);
    __iwram_lma     = LOADADDR(.iwram);

    .pad : ALIGN(4)
    {
        LONG(0);
        . = 0x08800000 - 0x0875C240;
    } > ROM = 0xFF

    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}

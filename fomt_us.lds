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
        . = 0x3BDE4; /* US ROM 0x0803BDE4, set a u16 pair */
        src/code_0803BDE4.o(.text);
        . = 0x3BDFC; /* US ROM 0x0803BDFC, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BDFC);
        . = 0x3BE9C; /* US ROM 0x0803BE9C, unpack a packed value */
        src/code_0803BE9C.o(.text);
        . = 0x3BEB0; /* US ROM 0x0803BEB0, forward owned operations */
        src/code_0803BEB0.o(.text);
        . = 0x3BED4; /* US ROM 0x0803BED4, forward owned operations */
        src/code_0803BED4.o(.text);
        . = 0x3BEEC; /* US ROM 0x0803BEEC, read signed pair values */
        src/code_0803BEEC.o(.text);
        . = 0x3BEFC; /* US ROM 0x0803BEFC, forward pair operations */
        src/code_0803BEFC.o(.text);
        . = 0x3BF14; /* US ROM 0x0803BF14, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BF14);
        . = 0x3C518; /* US ROM 0x0803C518, activate control bytes */
        src/code_0803C518.o(.text);
        . = 0x3C540; /* US ROM 0x0803C540, read and clear control bytes */
        src/code_0803C540.o(.text);
        . = 0x3C54C; /* US ROM 0x0803C54C, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803C54C);
        . = 0x3E40C; /* US ROM shared Lou/Ruby Sunday schedule gate. */
        src/code_0803E40C.o(.text);
        . = 0x3E448; /* US ROM 0x0803E448, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803E448);
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);
        . = 0x50D5C; /* US ROM shared first-field forwarding adapters. */
        src/code_08050D5C.o(.text);
        . = 0x50D8C; /* US ROM shared argument-normalizing forwarding adapters. */
        src/code_08050D8C.o(.text);
        . = 0x50DD8; /* US ROM shared first-field status-byte adapters. */
        src/code_08050DD8.o(.text);
        . = 0x50DF0; /* US ROM shared first-field query adapter. */
        src/code_08050DF0.o(.text);
        . = 0x50E0C; /* US ROM shared long-argument forwarding adapters. */
        src/code_08050E0C.o(.text);
        . = 0x50E50; /* US ROM shared first-field UI-adjacent adapters. */
        src/code_08050E50.o(.text);
        . = 0x50E98; /* US ROM shared first-field UI-flag adapters. */
        src/code_08050E98.o(.text);
        . = 0x50EE4; /* US ROM 0x08050EE4, remaining raw UI-adjacent code. */
        asm/code_0803EE94.o(.text.code_08050E50);

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
        . = 0x9BFE8; /* US ROM 0x0809BFE8, independently matched */
        src/code_actor_0809BFE8.o(.text);
        . = 0x9C160; /* US ROM 0x0809C160, unlabelled raw helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C160);
        . = 0x9C22C; /* US ROM 0x0809C22C, shared selector */
        src/code_actor_0809C22C.o(.text);
        . = 0x9C304; /* US ROM 0x0809C304, shared table accessor */
        src/code_actor_0809C304.o(.text);
        . = 0x9C318; /* US ROM 0x0809C318, raw actor helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C318);
        . = 0x9C32C; /* US ROM 0x0809C32C, shared paired-state predicate */
        src/code_actor_0809C32C.o(.text);
        . = 0x9C38C; /* US ROM 0x0809C38C, shared nonzero-state predicate */
        src/code_actor_0809C38C.o(.text);
        . = 0x9C3BC; /* US ROM 0x0809C3BC, shared state initializer */
        src/code_actor_0809C3BC.o(.text);
        . = 0x9C3E0; /* US ROM 0x0809C3E0, shared state advancement */
        src/code_actor_0809C3E0.o(.text);
        . = 0x9C420; /* US ROM 0x0809C420, shared state reset */
        src/code_actor_0809C420.o(.text);
        . = 0x9C444; /* US ROM 0x0809C444, shared conditional state advance */
        src/code_actor_0809C444.o(.text);
        . = 0x9C474; /* US ROM 0x0809C474, shared state-update dispatcher */
        src/code_actor_0809C474.o(.text);
        . = 0x9C4B4; /* US ROM 0x0809C4B4, shared state-update dispatcher */
        src/code_actor_0809C4B4.o(.text);
        . = 0x9C4E4; /* US ROM 0x0809C4E4, shared word clear */
        src/code_actor_0809C4E4.o(.text);
        . = 0x9C4EC; /* US ROM 0x0809C4EC, shared selection helper and raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C4EC);
        . = 0x9C5B4; /* US ROM 0x0809C5B4, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C5D0; /* US ROM 0x0809C5D0, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C5EC; /* US ROM 0x0809C5EC, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C5F4; /* US ROM 0x0809C5F4, test flag word */
        src/code_actor_0809C5F4.o(.text);
        . = 0x9C600; /* US ROM 0x0809C600, register event-state variable */
        src/code_actor_0809C600.o(.text);
        . = 0x9C644; /* US ROM 0x0809C644, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C644);
        . = 0x9C694; /* US ROM 0x0809C694, compare selected u16 */
        src/code_actor_0809C694.o(.text);
        . = 0x9C6AC; /* US ROM 0x0809C6AC, set selected u16 */
        src/code_actor_0809C6AC.o(.text);
        . = 0x9C6B0; /* US ROM 0x0809C6B0, reset selected u16 */
        src/code_actor_0809C6B0.o(.text);
        . = 0x9C6BC; /* US ROM 0x0809C6BC, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C6BC);
        . = 0x9CD78; /* US ROM 0x0809CD78, clear tracked counters */
        src/code_actor_0809CD78.o(.text);
        . = 0x9CD98; /* US ROM 0x0809CD98, update count and maximum */
        src/code_actor_0809CD98.o(.text);
        . = 0x9CDCC; /* US ROM 0x0809CDCC, test tracked counts */
        src/code_actor_0809CDCC.o(.text);
        . = 0x9CDEC; /* US ROM 0x0809CDEC, sum tracked counts */
        src/code_actor_0809CDEC.o(.text);
        . = 0x9CE1C; /* US ROM 0x0809CE1C, get record count */
        src/code_actor_0809CE1C.o(.text);
        . = 0x9CE24; /* US ROM 0x0809CE24, get record maximum */
        src/code_actor_0809CE24.o(.text);
        . = 0x9CE30; /* US ROM 0x0809CE30, map six input codes */
        src/code_actor_0809CE30.o(.text);
        . = 0x9CE7C; /* US ROM 0x0809CE7C, get fishing-record name */
        src/code_actor_0809CE7C.o(.text);
        . = 0x9CE8C; /* US ROM 0x0809CE8C, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CE8C);
        . = 0x9D418; /* US ROM 0x0809D418, map a segmented input value */
        src/code_actor_0809D418.o(.text);
        . = 0x9D470; /* US ROM 0x0809D470, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D470);
        . = 0x9D7D8; /* US ROM 0x0809D7D8, classify actor-state value */
        src/code_actor_0809D7D8.o(.text);
        . = 0x9D8A0; /* US ROM 0x0809D8A0, read state value */
        src/code_actor_0809D8A0.o(.text);
        . = 0x9D8A4; /* US ROM 0x0809D8A4, map one state value */
        src/code_actor_0809D8A4.o(.text);
        . = 0x9D8B8; /* US ROM 0x0809D8B8, map two state values */
        src/code_actor_0809D8B8.o(.text);
        . = 0x9D8D4; /* US ROM 0x0809D8D4, read packed grid-cell value */
        src/code_actor_0809D8D4.o(.text);
        . = 0x9D8E8; /* US ROM 0x0809D8E8, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9DF2C; /* US ROM 0x0809DF2C, query tool availability by group */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9DFAC; /* US ROM 0x0809DFAC, count actor-state flag bits */
        src/code_actor_0809DFAC.o(.text);
        . = 0x9E02C; /* US ROM 0x0809E02C, count actor-state flag bits */
        src/code_actor_0809E02C.o(.text);
        . = 0x9E0AC; /* US ROM 0x0809E0AC, select actor-state cell-type data */
        src/code_actor_0809E0AC.o(.text);
        . = 0x9E118; /* US ROM 0x0809E118, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9E174; /* US ROM 0x0809E174, read actor-state bit 0 */
        src/code_actor_0809E174.o(.text);
        . = 0x9E184; /* US ROM 0x0809E184, read actor-state bit 2 */
        src/code_actor_0809E184.o(.text);
        . = 0x9E194; /* US ROM 0x0809E194, read actor-state bit 3 */
        src/code_actor_0809E194.o(.text);
        . = 0x9E1A4; /* US ROM 0x0809E1A4, read actor-state bit 4 */
        src/code_actor_0809E1A4.o(.text);
        . = 0x9E1B4; /* US ROM 0x0809E1B4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        src/npc.o(.text);
        src/bachelorette.o(.text);
        src/harvest_sprite.o(.text);

        asm/code_809E804.o(.text);
        . = 0x9EACC; /* US ROM 0x0809EACC, shared NPC runtime fields. */
        src/npc_runtime_data.o(.text);
        . = 0x9EAF8; /* US ROM 0x0809EAF8, remaining raw NPC runtime code. */
        asm/code_809E804.o(.text.npc_runtime_data_after);

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
        . = ALIGN(4); src/new_game_menu_data.o(.rodata);
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
        . = ALIGN(4); asm/data/data_080F9EB8.o(.rodata.localized_data_prefix);
        . = 0xF9F7C; asm/data/data_080F9EB8.o(.rodata.name_entry_preset_animal_names_prefix);
        . = 0xF9F8A; data/text/new_game_name_entry.o(.rodata.name_entry_preset_animal_names);
        . = 0xFA12E; asm/data/data_080F9EB8.o(.rodata.name_entry_ui_character_codes);
        . = 0xFA158; data/text/frisbee.o(.rodata.frisbee_scoreboard);
        . = 0xFA174; asm/data/data_080F9EB8.o(.rodata.frisbee_scoreboard_trailer);
        . = 0xFA39C; data/text/frisbee.o(.rodata.frisbee);
        . = 0xFA710; asm/data/data_080F9EB8.o(.rodata.frisbee_text_trailer);
        . = 0xFA796; data/text/festival_contestants.o(.rodata.festival_contestants_set1);
        . = 0xFA99E; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set1_trailer_prefix);
        . = 0xFAA40; data/text/horse_race.o(.rodata.horse_race_dialogue);
        . = 0xFAE6A; asm/data/data_080F9EB8.o(.rodata.horse_race_dialogue_trailer);
        . = 0xFAE9C; data/text/horse_race.o(.rodata.horse_race_ticket_ui);
        . = 0xFAFC6; asm/data/data_080F9EB8.o(.rodata.horse_race_ticket_ui_padding);
        . = 0xFAFC8; src/horse_race_data.o(.rodata.horse_race_ticket_controls);
        . = 0xFAFF4; asm/data/data_080F9EB8.o(.rodata.horse_race_ticket_controls_trailer_prefix);
        . = 0xFB000; data/text/horse_race_prizes.o(.rodata.horse_race_prize_catalog);
        . = 0xFB0F0; asm/data/data_080F9EB8.o(.rodata.horse_race_prize_catalog_trailer_prefix);
        . = 0xFB108; data/text/horse_race_prizes.o(.rodata.horse_race_prize_exchange);
        . = 0xFB1A6; asm/data/data_080F9EB8.o(.rodata.horse_race_prize_exchange_trailer);
        . = 0xFB824; data/text/farm_status.o(.rodata);
        . = 0xFB954; asm/data/data_080F9EB8.o(.rodata.farm_status_trailer_prefix);
        . = 0xFB960; data/text/animal_contest.o(.rodata.animal_contest_status_prefix);
        . = 0xFB97C; data/text/animal_contest.o(.rodata.animal_contest_status);
        . = 0xFB9C8; data/text/animal_contest.o(.rodata.animal_contest);
        . = 0xFBD0C; asm/data/data_080F9EB8.o(.rodata.animal_contest_bad_alloc);
        . = 0xFBD18; data/text/animal_contest.o(.rodata.animal_contest_confirmation);
        . = 0xFBD2F; asm/data/data_080F9EB8.o(.rodata.animal_contest_confirmation_padding);
        . = 0xFBD30; asm/data/data_080F9EB8.o(.rodata.animal_contest_trailer);
        . = 0xFBE7C; data/text/records.o(.rodata);
        . = 0xFC024; asm/data/data_080F9EB8.o(.rodata.records_trailer);
        . = 0xFC0A4; data/text/staff_credits.o(.rodata.staff_credits);
        . = 0xFC6B8; asm/data/data_080F9EB8.o(.rodata.staff_credits_trailer_prefix);
        . = 0xFC6CC; data/text/town_map.o(.rodata);
        . = 0xFD07E; asm/data/data_080F9EB8.o(.rodata.town_map_padding);
        . = 0xFD080; asm/data/data_080F9EB8.o(.rodata.town_map_trailer);
        . = 0xFD550; data/text/library.o(.rodata.library_info);
        . = 0xFD583; asm/data/data_080F9EB8.o(.rodata.library_info_trailer);
        . = 0xFD940; data/text/library.o(.rodata.library_menu);
        . = 0xFD958; asm/data/data_080F9EB8.o(.rodata.library_menu_trailer);
        . = 0xFD964; data/text/poultry_shop.o(.rodata.poultry_shop_menu);
        . = 0xFD985; asm/data/data_080F9EB8.o(.rodata.poultry_shop_menu_padding);
        . = 0xFD988; src/poultry_shop_data.o(.rodata.poultry_shop_catalog);
        . = 0xFD9EC; data/text/poultry_shop.o(.rodata.poultry_shop_status_prefix);
        . = 0xFD9EE; asm/data/data_080F9EB8.o(.rodata.poultry_shop_status_prefix_padding);
        . = 0xFD9F0; data/text/poultry_shop.o(.rodata.poultry_shop_status);
        . = 0xFDA7A; asm/data/data_080F9EB8.o(.rodata.poultry_shop_status_padding);
        . = 0xFDA7C; data/text/poultry_shop.o(.rodata.poultry_shop_dialogue);
        . = 0xFDDCC; asm/data/data_080F9EB8.o(.rodata.poultry_shop_trailer);
        . = 0xFDDD8; src/supermarket_data.o(.rodata.supermarket_crop_catalog);
        . = 0xFDE40; data/text/supermarket.o(.rodata.supermarket_primary_text);
        . = 0xFDFA1; asm/data/data_080F9EB8.o(.rodata.supermarket_primary_text_padding);
        . = 0xFDFA4; src/supermarket_data.o(.rodata.supermarket_additional_seed_catalog);
        . = 0xFDFE4; data/text/supermarket.o(.rodata.supermarket_secondary_text);
        . = 0xFE043; asm/data/data_080F9EB8.o(.rodata.supermarket_secondary_text_padding);
        . = 0xFE044; asm/data/data_080F9EB8.o(.rodata.supermarket_trailer);
        . = 0xFE050; src/clinic_data.o(.rodata.clinic_catalog);
        . = 0xFE070; data/text/clinic.o(.rodata.clinic_text);
        . = 0xFE257; asm/data/data_080F9EB8.o(.rodata.clinic_text_padding);
        . = 0xFE258; asm/data/data_080F9EB8.o(.rodata.inn_shop_prefix);
        . = 0xFE264; data/text/inn_shop.o(.rodata.inn_shop_descriptions);
        . = 0xFE2D8; src/inn_shop_data.o(.rodata.inn_shop_catalog);
        . = 0xFE3D4; data/text/inn_shop.o(.rodata.inn_shop_dialogue);
        . = 0xFE478; asm/data/data_080F9EB8.o(.rodata.inn_shop_trailer);
        . = 0xFE484; src/won_shop_data.o(.rodata.won_shop_catalog);
        . = 0xFE4D4; data/text/won_shop.o(.rodata.won_shop_dialogue);
        . = 0xFE734; asm/data/data_080F9EB8.o(.rodata.won_shop_trailer);
        . = 0xFE740; src/winery_shop_data.o(.rodata.winery_shop_catalog);
        . = 0xFE750; data/text/winery_shop.o(.rodata.winery_shop_dialogue);
        FILL(0x00);
        . = 0xFE8F0; asm/data/data_080F9EB8.o(.rodata.winery_shop_trailer);
        . = 0xFE8FC; src/special_merchant_shop_data.o(.rodata.special_merchant_shop_catalog);
        . = 0xFE974; data/text/special_merchant_shop.o(.rodata.special_merchant_shop_text);
        . = 0xFEAE8; asm/data/data_080F9EB8.o(.rodata.special_merchant_shop_trailer);
        . = 0xFEAF4; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_descriptions);
        . = 0xFEB60; src/beach_cafe_shop_data.o(.rodata.beach_cafe_shop_catalog);
        . = 0xFEBEC; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_dialogue);
        . = 0xFEC70; asm/data/data_080F9EB8.o(.rodata.beach_cafe_shop_trailer);
        . = 0xFEC7C; data/text/blacksmith.o(.rodata.blacksmith_menu);
        . = 0xFED8C; src/blacksmith_data.o(.rodata.blacksmith_catalog);
        . = 0xFEE68; data/text/blacksmith.o(.rodata.blacksmith_dialogue);
        . = 0xFF350; asm/data/data_080F9EB8.o(.rodata.carpenter_menu_prefix);
        FILL(0x00);
        . = 0xFF35C; data/text/carpenter.o(.rodata.carpenter_menu);
        . = 0xFF6A8; src/carpenter_data.o(.rodata.carpenter_catalog);
        FILL(0xFF);
        . = 0xFF838; asm/data/data_080F9EB8.o(.rodata.carpenter_catalog_trailer);
        FILL(0x00);
        . = 0xFF83C; data/text/carpenter.o(.rodata.carpenter_dialogue);
        . = 0xFFB54; asm/data/data_080F9EB8.o(.rodata.carpenter_trailer);
        FILL(0xFF);
        . = 0xFFB60; data/text/livestock_shop.o(.rodata.livestock_shop_menu);
        . = 0xFFB8F; asm/data/data_080F9EB8.o(.rodata.livestock_shop_menu_padding);
        . = 0xFFB90; src/livestock_shop_data.o(.rodata.livestock_shop_catalog);
        . = 0xFFC6C; data/text/livestock_shop.o(.rodata.livestock_shop_status_prefix);
        . = 0xFFC6E; asm/data/data_080F9EB8.o(.rodata.livestock_shop_status_prefix_padding);
        . = 0xFFC70; data/text/livestock_shop.o(.rodata.livestock_shop_status);
        . = 0xFFD3B; asm/data/data_080F9EB8.o(.rodata.livestock_shop_status_padding);
        . = 0xFFD3C; data/text/livestock_shop.o(.rodata.livestock_shop_dialogue);
        . = 0x100024; asm/data/data_080F9EB8.o(.rodata.livestock_shop_trailer_prefix);
        . = 0x100030; asm/data/data_080F9EB8.o(.rodata.home_storage_prefix);
        FILL(0x00);
        . = 0x100034; data/text/home_storage.o(.rodata.home_storage_fridge);
        . = 0x10009C; asm/data/data_080F9EB8.o(.rodata.home_storage_fridge_trailer);
        . = 0x1000A8; data/text/home_storage.o(.rodata.home_storage_confirmation);
        . = 0x1000B0; asm/data/data_080F9EB8.o(.rodata.home_storage_tool_chest_category_padding);
        . = 0x1000B4; data/text/home_storage.o(.rodata.home_storage_tool_chest_category);
        . = 0x1000C4; asm/data/data_080F9EB8.o(.rodata.home_storage_tool_chest_category_trailer);
        . = 0x1000D4; data/text/home_storage.o(.rodata.home_storage_shelf);
        . = 0x100138; asm/data/data_080F9EB8.o(.rodata.home_storage_shelf_trailer);
        . = 0x100148; data/text/home_storage.o(.rodata.home_storage_tool_chest_header);
        . = 0x10015C; asm/data/data_080F9EB8.o(.rodata.home_storage_trailer);
        . = 0x100168; asm/data/data_080F9EB8.o(.rodata.blacksmith_upgrade_prefix);
        FILL(0x00);
        . = 0x10016C; data/text/blacksmith.o(.rodata.blacksmith_upgrade_prompts);
        FILL(0xFF);
        . = 0x100350; data/text/blacksmith.o(.rodata.blacksmith_upgrade_dynamic);
        . = 0x100398; asm/data/data_080F9EB8.o(.rodata.blacksmith_upgrade_result_padding);
        FILL(0x00);
        . = 0x10039C; data/text/blacksmith.o(.rodata.blacksmith_upgrade_result);
        . = 0x1003E4; asm/data/data_080F9EB8.o(.rodata.gift_wrap_prefix);
        . = 0x1003F4; data/text/gift_wrap.o(.rodata.gift_wrap);
        . = 0x1004D4; asm/data/data_080F9EB8.o(.rodata.gift_wrap_trailer);
        FILL(0x00);
        . = 0x1004E0; data/text/link_communication.o(.rodata.link_communication);
        . = 0x1007AC; asm/data/data_080F9EB8.o(.rodata.link_communication_trailer);
        . = 0x100AD2; data/text/recovery_status.o(.rodata);
        . = 0x100DE1; asm/data/data_080F9EB8.o(.rodata.recovery_status_padding);
        . = 0x100DE4; data/text/cooking_menu.o(.rodata);
        . = 0x100EEF; asm/data/data_080F9EB8.o(.rodata.cooking_menu_padding);
        . = 0x100EF0; data/text/cooking_menu.o(.rodata.cooking_result_text);
        . = 0x100F03; asm/data/data_080F9EB8.o(.rodata.cooking_result_padding);
        . = 0x100F04; data/text/cooking_menu.o(.rodata.cooking_result_success_text);
        . = 0x100F78; data/text/cooking_recipe_actions.o(.rodata);
        . = 0x100FDD; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_actions_padding);
        . = 0x100FE0; data/text/cooking_recipe_actions.o(.rodata.cooking_recipe_actions_extra_text);
        . = 0x101007; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_actions_extra_padding);
        . = 0x101008; data/text/cooking_recipe_inventory.o(.rodata);
        . = 0x1010E8; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_inventory_trailer);
        . = 0x103788; data/text/fishing_results.o(.rodata);
        . = 0x103A16; asm/data/data_080F9EB8.o(.rodata.fishing_results_text_padding);
        . = 0x103A18; src/fishing_results_data.o(.rodata.fishing_record_names);
        . = 0x103B04; asm/data/data_080F9EB8.o(.rodata.fishing_results_trailer);
        . = 0x103B10; asm/data/data_080F9EB8.o(.rodata.reference_guide_harvest_sprite_minigames_after_fishing_results);
        . = 0x104128; data/text/character_names.o(.rodata);
        . = 0x104256; asm/data/data_080F9EB8.o(.rodata.character_names_text_padding);
        . = 0x104258; src/character_names_data.o(.rodata.character_name_entries);
        . = 0x1043B0; asm/data/data_080F9EB8.o(.rodata.character_names_table_trailer);
        . = 0x1043BC; asm/data/data_080F9EB8.o(.rodata.reference_guide_harvest_sprite_minigames_after_character_names);
        . = 0x104938; data/text/calendar.o(.rodata.calendar.dynamic_season_names);
        . = 0x104958; asm/data/data_080F9EB8.o(.rodata.calendar_dynamic_season_names_trailer);
        . = 0x10497C; data/text/calendar.o(.rodata.calendar.festival_text);
        . = 0x104D96; asm/data/data_080F9EB8.o(.rodata.calendar_festival_dynamic_padding);
        . = 0x104D98; data/text/calendar.o(.rodata.calendar.festival_dynamic_text);
        . = 0x104DDC; data/text/calendar.o(.rodata.calendar.no_plans_text);
        . = 0x104DEA; asm/data/data_080F9EB8.o(.rodata.calendar_no_plans_trailer);
        . = 0x104E0C; data/text/possessive_labels.o(.rodata.possessive_labels);
        . = 0x104E40; asm/data/data_080F9EB8.o(.rodata.static_data_after_possessive_labels);
        . = 0x1075B0; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_animal_husbandry);
        . = 0x10787C; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_animal_husbandry_trailer);
        . = 0x1078BD; data/text/festival_contestants.o(.rodata.festival_contestants_set2);
        . = 0x1079C1; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set2_trailer);
        . = 0x1079C4; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_opening);
        . = 0x107ACC; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_mid);
        . = 0x107B00; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_instructions);
        . = 0x107CFB; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_instructions_trailer);
        . = 0x107CFC; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_trailer);
        . = 0x107DD8; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_instructions);
        . = 0x107F5F; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_harvest_instructions_trailer);
        . = 0x107F60; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_results);
        . = 0x107FB0; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_harvest_results_trailer);
        . = 0x108020; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_instructions);
        . = 0x108217; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_watering_instructions_trailer);
        . = 0x108218; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_results);
        . = 0x108267; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_watering_results_trailer);
        . = 0x10828C; src/reference_guide.o(.rodata.reference_guide);
        . = 0x1177EC; asm/data/data_080F9EB8.o(.rodata.reference_guide_unextracted_trailer);
        . = 0x1177F6; asm/data/data_080F9EB8.o(.rodata.tool_status_prefix);
        . = 0x11780C; data/text/shop_common.o(.rodata.shop_common_prefix);
        . = 0x117814; data/text/shop_common_refs.o(.rodata.shop_common_quantity_suffix_text_ref);
        . = 0x117818; data/text/shop_common.o(.rodata.shop_common_owned_quantity_label);
        . = 0x117828; data/text/shop_common_refs.o(.rodata.shop_common_owned_quantity_label_text_ref);
        . = 0x11782C; asm/data/data_080F9EB8.o(.rodata.shop_common_unextracted_trailer);
        . = 0x117838; asm/data/data_080F9EB8.o(.rodata.tool_status_prefix_trailer);
        . = 0x1179AC; data/text/tool_status.o(.rodata.tool_status);
        . = 0x117A0C; data/text/animal_status.o(.rodata.animal_status);
        . = 0x117A50; data/text/item_status.o(.rodata.item_status_basket);
        . = 0x117A8C; data/text/item_status.o(.rodata.item_status_wrapped_as_present);
        . = 0x117AA4; data/text/item_status_refs.o(.rodata.item_status_wrapped_as_present_text_ref);
        . = 0x117AA8; data/text/item_discard.o(.rodata.item_discard_confirm);
        . = 0x117ABC; data/text/item_discard_refs.o(.rodata.item_discard_confirm_text_ref);
        . = 0x117AC0; data/text/item_discard.o(.rodata.item_discard_cannot_discard);
        . = 0x117ADC; data/text/item_discard_refs.o(.rodata.item_discard_cannot_discard_text_ref);
        . = 0x117AE0; data/text/item_discard.o(.rodata.item_discard_cursed);
        . = 0x117B10; data/text/item_discard_refs.o(.rodata.item_discard_cursed_text_ref);
        . = 0x117B14; asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard);
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

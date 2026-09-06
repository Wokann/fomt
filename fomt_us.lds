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
        . = 0xFBE7C; data/text/records.o(.rodata);
        . = 0xFC024; asm/data/data_080F9EB8.o(.rodata.records_trailer);
        . = 0xFC0A4; data/text/staff_credits.o(.rodata.staff_credits);
        . = 0xFC6B8; asm/data/data_080F9EB8.o(.rodata.staff_credits_trailer_prefix);
        . = 0x100AD2; data/text/recovery_status.o(.rodata);
        . = 0x100DE1; asm/data/data_080F9EB8.o(.rodata.recovery_status_padding);
        . = 0x100DE4; data/text/cooking_menu.o(.rodata);
        . = 0x100EEF; asm/data/data_080F9EB8.o(.rodata.cooking_menu_padding);
        . = 0x100EF0; asm/data/data_080F9EB8.o(.rodata.cooking_menu_trailer);
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
        . = 0x1078BD; data/text/festival_contestants.o(.rodata.festival_contestants_set2);
        . = 0x1079C1; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set2_trailer);
        . = 0x10828C; src/reference_guide.o(.rodata.reference_guide);
        . = 0x1177EC; asm/data/data_080F9EB8.o(.rodata.reference_guide_unextracted_trailer);
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

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
        . = 0x324B8; /* JP/US-shared default entity-UI false handler. */
        src/entity_ui.o(.text.entity_ui_default_no_action);
        . = 0x324BC; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_default_no_action_after);
        . = 0x32900; /* JP/US-shared entity-UI coordinate classifier. */
        src/entity_ui.o(.text.entity_ui_region_classification);
        . = 0x32934; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_region_classification_after);
        . = 0x32A00; /* JP/US-shared entity-UI constructor. */
        src/entity_ui.o(.text.entity_ui_constructor);
        . = 0x32A30; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_constructor_after);
        . = 0x33914; /* JP/US-shared Harvest Sprite task experience transform. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_task_experience);
        . = 0x33928; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_harvest_sprite_task_experience_after);
        . = 0x33B24; /* JP/US-shared Harvest Sprite UI entry test. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_selection);
        . = 0x33B7C; /* JP/US-shared entity-UI byte-0x41 clearer. */
        src/entity_ui.o(.text.entity_ui_unknown_flag);
        . = 0x33B84; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_unknown_flag_after);
        . = 0x34248; /* JP/US-shared entity-UI animation lookup. */
        src/entity_ui.o(.text.entity_ui_animation_lookup);
        . = 0x34260; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_animation_lookup_after);
        . = 0x34BFC; /* JP/US-shared entity-UI resource setup. */
        src/entity_ui.o(.text.entity_ui_resource_setup);
        . = 0x34C40; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_get_value_30);
        . = 0x34C48; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_get_pointer_10);
        . = 0x34C4C; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_dispatch_value_30);
        . = 0x34C64; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_resource_setup_after);
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
        . = 0x4E4AC; /* Ordinary 2D glyph compositor. */
        src/font_draw.o(.text.font_draw_normal);
        . = 0x4E5AC; /* Extended palette glyph compositor. */
        src/font_draw_ext.o(.text);
        . = 0x4E7A0; /* Shared 2D tile-buffer fillers and Shift-JIS renderers. */
        src/font_draw.o(.text);
        . = 0x4E9D0; src/font_draw.o(.text.font_draw_after);
        . = 0x4E9F4; asm/code_0803EE94.o(.text.font_draw_after);
        . = 0x503FC; /* JP/US-shared nonzero UI-state setter. */
        src/ui_state.o(.text.set_ui_object_state_two_if_nonzero);
        . = 0x50410; /* JP/US-shared nonzero UI-state clearer. */
        src/ui_state.o(.text.clear_ui_object_state_if_nonzero);
        . = 0x50424; asm/code_0803EE94.o(.text.ui_object_state_after);
        . = 0x50B3C; /* JP/US-shared UI action-state first-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01dc);
        . = 0x50B50; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01dc_after);
        . = 0x50C18; /* JP/US-shared UI action-state second-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01f0);
        . = 0x50C2C; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01f0_after);
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
        . = 0x522D8; /* JP/US-shared animal-festival ranking entry copy. */
        src/animal_festival_ranking.o(.text.copy_animal_festival_ranking_entry);
        . = 0x522E8; /* JP/US-shared animal-festival ranking entry setter. */
        src/animal_festival_ranking.o(.text.set_animal_festival_ranking_entry);
        . = 0x522F8; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E6CC; /* JP/US-shared indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E760; /* JP/US-shared indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E790; asm/code_0803EE94.o(.text.indexed_resource_archive_resolve_after);
        . = 0x5E81C; /* JP/US-shared indexed resource-archive group count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_group_descriptor_count);
        . = 0x5E820; /* JP/US-shared indexed resource-archive entry count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_entry_descriptor_count);
        . = 0x5E824; /* JP/US-shared indexed resource-handle constructor. */
        src/resource_handle.o(.text.indexed_resource_handle_constructor);
        . = 0x5E850; /* JP/US-shared indexed resource-handle initializer. */
        src/resource_handle.o(.text.initialize_indexed_resource_handle);
        . = 0x5E860; /* JP/US-shared indexed resource-handle resolver. */
        src/resource_handle.o(.text.resolve_indexed_resource_handle);
        . = 0x5E894; asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
        . = 0x75DB8; /* JP/US-shared scroll-position reset. */
        src/scroll_state.o(.text.reset_scroll_position);
        . = 0x75DD4; /* JP/US-shared scroll-buffer clear. */
        src/scroll_state.o(.text.clear_scroll_buffer);
        . = 0x75DEC; asm/code_0803EE94.o(.text.clear_scroll_buffer_after);
        . = 0x76BE0; /* JP/US-shared selection-index state setter. */
        src/selection_state.o(.text.set_selection_index);
        . = 0x76BEC; /* JP/US-shared selection-index state getter. */
        src/selection_state.o(.text.get_selection_index);
        . = 0x76BFC; asm/code_0803EE94.o(.text.get_selection_index_after);
        . = 0x77E34; /* JP/US-shared 30x13 BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_30x13);
        . = 0x77E64; /* JP/US-shared rectangular BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_rect);
        . = 0x77EC0; asm/code_0803EE94.o(.text.copy_bg_map_rect_after);
        . = 0x782C4; /* JP/US-shared town-map cursor hit test. */
        src/town_map_data.o(.text.town_map_hotspot_contains);
        . = 0x782EC; asm/code_0803EE94.o(.text.town_map_hotspot_contains_after);

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
        . = 0xA4698;
        src/map_data.o(.text.get_map_data);
        . = 0xA46AC;
        asm/code_809E804.o(.text.get_map_data_after);
        . = 0xD0CD4; /* Shift-JIS glyph-map index converter and renderer. */
        src/font.o(.text);
        . = 0xD0EBC; /* Remaining font support code. */
        asm/code_809E804.o(.text.font_after);

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
        . = ALIGN(4); src/vtables.o(.rodata);
        . = ALIGN(4); asm/vtables.o(.rodata);
        *(.gnu.linkonce.d.__vt_7AEntity);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6284);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6310);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_639c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6428);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_64b4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_64c8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6554);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_65e0);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_65f4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6644);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6658);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6708);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_671c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_676c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_681c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6828);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6864);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_aactor_entity);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_68b4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_68c8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6904);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6918);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6958);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6998);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_69d8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6a18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6a58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6a98);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6ad8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6b18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6b58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6b98);
        . = ALIGN(4); asm/vtables.o(.rodata.080E6BD8);
        *(.gnu.linkonce.d.__vt_13AScriptEngine);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_script_engine);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_script_engine_adjacent);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7928);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7934);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7944);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7950);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7960);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7970);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_797c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_798c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_799c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79a8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79b8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79c8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79dc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79e8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_79f8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a08);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a28);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a38);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a48);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a68);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a78);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7a88);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7a98);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7aa8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ab4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ac4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ad0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ae0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7aec);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7afc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b0c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b1c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b2c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b3c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b4c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b5c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b68);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b78);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b88);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7b98);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ba4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bb4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bc0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bd0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bdc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bec);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7bf8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c08);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c14);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c20);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c30);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c40);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c4c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c5c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c68);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c78);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c84);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7c94);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ca0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7cb0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7cbc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ccc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7cd8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7ce8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7cf4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d04);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d14);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d20);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d30);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d3c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d4c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d58);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d68);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d74);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d84);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7d90);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7da0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7dac);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7dbc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7dc8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7dd8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7de4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7df4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7f00);
. = ALIGN(4); src/vtables.o(.rodata.vtable_7f0c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8018);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8028);
. = ALIGN(4); src/vtables.o(.rodata.vtable_812c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8230);
. = ALIGN(4); src/vtables.o(.rodata.vtable_823c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_824c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_825c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8268);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8278);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8288);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8298);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82a8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82b8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82d8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82e4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_830c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_831c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8344);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8404);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8440);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8500);
. = ALIGN(4); src/vtables.o(.rodata.vtable_850c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_851c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8528);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8538);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8544);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8554);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8560);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8570);
. = ALIGN(4); src/vtables.o(.rodata.vtable_857c);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8588);
. = ALIGN(4); src/vtables.o(.rodata.vtable_8594);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85a0);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85ac);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85bc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85cc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85dc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85e8);

        . = ALIGN(4); src/crt0_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        data/text/common/sram_signature.o(.rodata.sram_signature);
        src/intro_scene_data.o(.rodata.intro_scene_startup_resources);
        . = ALIGN(4); src/new_game_menu_data.o(.rodata);
        . = ALIGN(4); data/text/new_game_status.o(.rodata.new_game_status_labels);
        . = ALIGN(4); data/text/new_game_help.o(.rodata.new_game_help_text);
        . = ALIGN(4); data/text/new_game_save.o(.rodata.new_game_save_text);
        . = ALIGN(4); data/text/new_game_save.o(.rodata.new_game_save_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_prefix);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_prefix_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_labels);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_labels_trailer);
        data/text/new_game_name_entry.o(.rodata.new_game_name_entry_characters);
        data/text/new_game_name_entry_ui.o(.rodata.new_game_name_entry_ui);
        data/text/new_game_name_entry_ui.o(.rodata.new_game_name_entry_ui_trailer);
        FILL(0x00);
        . = ALIGN(4);
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
        src/item.o(.rodata.item_product_trailer);
        FILL(0x00);
        data/text/calendar.o(.rodata.calendar.season);
        data/text/calendar.o(.rodata.calendar.none);
        data/text/calendar.o(.rodata.calendar.weekday);
        . = ALIGN(4); data/text/calendar.o(.rodata.calendar_trailer);
        src/game_state.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); data/text/load_error.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/help_menu.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        data/text/animal_memorial.o(.rodata);
        src/animal_data.o(.rodata.animal_data_prefix);
        src/animal_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/entity_ui.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/fixed_labels.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/ui_error.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/menu_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/data_schedules.o(.rodata);
        . = ALIGN(4); src/entity_ui.o(.rodata.entity_ui_resource_selector);
        FILL(0x00);
        . = ALIGN(4); asm/data/data_080F1A80.o(.rodata.data_080f1a80_suffix);
        . = ALIGN(4); src/script_engine.o(.rodata);
        . = 0xF9EA4; src/script_engine.o(.rodata.script_engine_string_error);
        . = 0xF9EAC; src/script_engine.o(.rodata.script_engine_ui_error_prefix);
        FILL(0x00);
        . = 0xF9EB8; src/script_engine.o(.rodata.script_engine_ui_error);
        FILL(0x00);
        . = 0xF9EC0; src/script_engine.o(.rodata.script_engine_ui_error_trailer);
        . = 0xF9EC5; src/cooking_festival_data.o(.rodata);
        src/thomas_stocking_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/spouse_gift_data.o(.rodata);
        . = 0xF9EF4; src/farm_house.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/code_08050E0C.o(.rodata);
        src/ui_state.o(.rodata);
        . = 0xF9F7C; data/text/new_game_name_entry.o(.rodata.new_game_name_entry_preset_animal_names_runtime);
        . = 0xF9F8A; data/text/new_game_name_entry.o(.rodata.name_entry_preset_animal_names);
        . = 0xFA12E; data/text/new_game_name_entry_ui.o(.rodata.name_entry_ui_character_codes);
        . = 0xFA158; data/text/frisbee.o(.rodata.frisbee_scoreboard);
        . = 0xFA174; src/animal_festival_ranking.o(.rodata.animal_festival_ranking_score_table);
        . = 0xFA23C; data/text/frisbee.o(.rodata.frisbee_scoreboard_trailer_runtime);
        . = 0xFA246; src/animal_festival_ranking.o(.rodata.animal_festival_ranking_data);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_reward_article_ids);
        . = 0xFA39C; data/text/frisbee.o(.rodata.frisbee);
        . = 0xFA710; data/text/frisbee.o(.rodata.frisbee_text_trailer_runtime);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_random_range_pairs);
        . = 0xFA78C; data/text/animal_festival.o(.rodata.animal_festival_livestock_contestant_names_runtime);
        . = 0xFA796; data/text/animal_festival.o(.rodata.animal_festival_livestock_contestant_names);
        . = 0xFA99E; src/animal_festival_ranking.o(.rodata.animal_festival_livestock_contestant_values);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFAA40; data/text/horse_race.o(.rodata.horse_race_dialogue);
        . = 0xFAE6A; data/text/horse_race.o(.rodata.horse_race_ticket_character_codes);
        . = 0xFAE9C; data/text/horse_race.o(.rodata.horse_race_ticket_ui);
        . = 0xFAFC8; src/horse_race_data.o(.rodata.horse_race_ticket_controls);
        . = 0xFAFF4; src/horse_race_data.o(.rodata.horse_race_ticket_controls_trailer);
        FILL(0x00);
        . = 0xFB000; data/text/horse_race_prizes.o(.rodata.horse_race_prize_catalog);
        . = 0xFB0F0; src/horse_race_data.o(.rodata.horse_race_prize_item_ids);
        . = 0xFB108; data/text/horse_race_prizes.o(.rodata.horse_race_prize_exchange);
        . = 0xFB1A6; src/horse_race_data.o(.rodata.horse_race_prize_exchange_character_codes);
        . = 0xFB1D8; data/text/intro_scene.o(.rodata.intro_scene_prefix_runtime);
        . = 0xFB1E4; src/intro_scene_data.o(.rodata);
        . = 0xFB234; data/text/intro_scene.o(.rodata.intro_scene_text);
        FILL(0x00);
        . = 0xFB818; data/text/intro_scene.o(.rodata.intro_scene_text_trailer);
        . = 0xFB824; data/text/farm_status.o(.rodata);
        . = 0xFB960; data/text/animal_status_screen.o(.rodata);
        . = 0xFB9C8; data/text/animal_contest.o(.rodata);
        . = 0xFBD30; src/farm_status_screen_data.o(.rodata);
        . = 0xFBE7C; data/text/records.o(.rodata);
        . = 0xFC024; src/records_screen_data.o(.rodata);
        . = 0xFC0A4; data/text/staff_credits.o(.rodata);
        . = 0xFC6B8; src/town_map_data.o(.rodata.staff_credits_trailer);
        src/town_map_data.o(.rodata.town_map_resource_ids);
        FILL(0x00);
        . = ALIGN(4); data/text/town_map.o(.rodata);
        . = 0xFD080; src/town_map_data.o(.rodata.town_map_hotspots);
        . = 0xFD3A0; src/town_map_data.o(.rodata.town_map_area_lookup);
        . = 0xFD550; data/text/library.o(.rodata.library_info);
        FILL(0x00);
        . = ALIGN(4); src/town_map_data.o(.rodata.town_map_area_bounds);
        src/library_data.o(.rodata.library_info_runtime);
        FILL(0x00);
        . = ALIGN(4); src/library_data.o(.rodata.library_initial_entry_ids);
        . = 0xFD940; data/text/library.o(.rodata.library_menu);
        . = 0xFD958; data/text/library.o(.rodata.library_menu_trailer);
        . = 0xFD964; data/text/poultry_shop.o(.rodata.poultry_shop_menu);
        . = ALIGN(4); src/poultry_shop_data.o(.rodata.poultry_shop_catalog);
        data/text/poultry_shop.o(.rodata.poultry_shop_status_prefix);
        FILL(0x00);
        . = ALIGN(4); data/text/poultry_shop.o(.rodata.poultry_shop_status);
        FILL(0x00);
        . = ALIGN(4); data/text/poultry_shop.o(.rodata.poultry_shop_dialogue);
        FILL(0x00);
        . = ALIGN(4); data/text/poultry_shop.o(.rodata.poultry_shop_trailer);
        FILL(0x00);
        . = ALIGN(4); src/supermarket_data.o(.rodata.supermarket_crop_catalog);
        . = 0xFDE40; data/text/supermarket.o(.rodata.supermarket_primary_text);
        FILL(0x00);
        . = ALIGN(4); src/supermarket_data.o(.rodata.supermarket_additional_seed_catalog);
        . = 0xFDFE4; data/text/supermarket.o(.rodata.supermarket_secondary_text);
        FILL(0x00);
        . = ALIGN(4); data/text/supermarket.o(.rodata.supermarket_trailer);
        FILL(0x00);
        . = ALIGN(4); src/clinic_data.o(.rodata.clinic_catalog);
        . = 0xFE070; data/text/clinic.o(.rodata.clinic_text);
        FILL(0x00);
        . = ALIGN(4); data/text/clinic.o(.rodata.clinic_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/inn_shop.o(.rodata.inn_shop_descriptions);
        . = ALIGN(4); src/inn_shop_data.o(.rodata.inn_shop_catalog);
        . = 0xFE3D4; data/text/inn_shop.o(.rodata.inn_shop_dialogue);
        FILL(0x00);
        . = ALIGN(4); data/text/inn_shop.o(.rodata.inn_shop_trailer);
        FILL(0x00);
        . = ALIGN(4); src/won_shop_data.o(.rodata.won_shop_catalog);
        . = 0xFE4D4; data/text/won_shop.o(.rodata.won_shop_dialogue);
        FILL(0x00);
        . = ALIGN(4); data/text/won_shop.o(.rodata.won_shop_trailer);
        FILL(0x00);
        . = ALIGN(4); src/winery_shop_data.o(.rodata.winery_shop_catalog);
        . = 0xFE750; data/text/winery_shop.o(.rodata.winery_shop_dialogue);
        FILL(0x00);
        . = ALIGN(4); data/text/winery_shop.o(.rodata.winery_shop_trailer);
        FILL(0x00);
        . = ALIGN(4); src/special_merchant_shop_data.o(.rodata.special_merchant_shop_catalog);
        . = 0xFE974; data/text/special_merchant_shop.o(.rodata.special_merchant_shop_text);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFEAF4; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_descriptions);
        . = 0xFEB60; src/beach_cafe_shop_data.o(.rodata.beach_cafe_shop_catalog);
        . = 0xFEBEC; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_dialogue);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFEC7C; data/text/blacksmith.o(.rodata.blacksmith_menu);
        . = 0xFED8C; src/blacksmith_data.o(.rodata.blacksmith_catalog);
        . = 0xFEE68; data/text/blacksmith.o(.rodata.blacksmith_dialogue);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFF35C; data/text/carpenter.o(.rodata.carpenter_menu);
        . = 0xFF6A8; src/carpenter_data.o(.rodata.carpenter_catalog);
        FILL(0xFF);
        . = 0xFF838; data/text/common/carpenter.o(.rodata.carpenter_initial_page_break);
        FILL(0x00);
        . = ALIGN(4); data/text/carpenter.o(.rodata.carpenter_dialogue);
        . = 0xFFB54; data/text/carpenter.o(.rodata.carpenter_trailer);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0xFF);
        . = 0xFFB60; src/livestock_shop.o(.rodata);
        . = 0x100024; data/text/home_storage.o(.rodata);
        FILL(0x00);
        . = 0x100168; data/text/blacksmith.o(.rodata.blacksmith_upgrade);
        . = 0x1003E4; data/text/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0x1004E0; data/text/link_communication.o(.rodata.link_communication);
        . = 0x1007AC; src/link_communication_data.o(.rodata);
        data/text/link_communication.o(.rodata.link_communication_character_codes);
        src/link_communication_data.o(.rodata.link_communication_game_codes);
        FILL(0x00);
        . = ALIGN(4);
        . = 0x100AC0; data/text/common/cooking_recipe_inventory.o(.rodata);
        . = 0x100AC2; src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_utensil_values);
        . = 0x100AD2; data/text/recovery_status.o(.rodata);
        . = 0x100DE4; data/text/cooking_menu.o(.rodata);
        . = 0x100EF0; data/text/cooking_menu.o(.rodata.cooking_result_text);
        . = 0x100F04; data/text/cooking_menu.o(.rodata.cooking_result_success_text);
        . = 0x100F78; data/text/cooking_recipe_actions.o(.rodata);
        . = 0x100FE0; data/text/cooking_recipe_actions.o(.rodata.cooking_recipe_actions_extra_text);
        . = 0x101008; data/text/cooking_recipe_inventory.o(.rodata);
        . = 0x1010E8; src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_mask_entries);
        . = 0x10110C; src/cooking_recipe_inventory_data.o(.rodata);
        data/text/common/animal.o(.rodata.animal_unnamed);
        . = 0x103660; src/livestock.o(.rodata.livestock_day_update);
        . = 0x1036C0; src/code_actor_0809C3E0.o(.rodata.actor_state_max_values);
        . = 0x1036C8; src/code_actor_0809C3E0.o(.rodata);
        . = 0x103788; data/text/fishing_results.o(.rodata);
        . = 0x103A18; src/fishing_results_data.o(.rodata.fishing_record_names);
        . = 0x103B04; src/fishing_results_data.o(.rodata);
        . = 0x103B10; src/code_actor_0809BFE8.o(.rodata);
        . = 0x104108; data/text/character_names_empty.o(.rodata);
        . = 0x104109; src/bachelorette.o(.rodata);
        . = 0x104128; data/text/character_names.o(.rodata);
        . = 0x104258; src/character_names_data.o(.rodata.character_name_entries);
        . = 0x1043B0; src/character_names_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/field_data.o(.rodata.field_item_records);
        FILL(0x00);
        . = ALIGN(4);
        . = 0x104938; data/text/calendar.o(.rodata.calendar.dynamic_season_names);
        . = 0x10497C; data/text/calendar.o(.rodata.calendar.festival_text);
        . = 0x104D98; data/text/calendar.o(.rodata.calendar.festival_dynamic_text);
        . = 0x104DDC; data/text/calendar.o(.rodata.calendar.no_plans_text);
        . = 0x104DEC; data/text/calendar.o(.rodata);
        . = 0x104E0C; data/text/possessive_labels.o(.rodata.possessive_labels);
        . = 0x104E40; data/text/possessive_labels.o(.rodata);
        . = 0x104E4C; data/text/random_item.o(.rodata.random_item_fallback);
        . = 0x104E54; src/fishing_results_data.o(.rodata.fishing_record_article_ids);
        . = 0x104E74; src/field_data.o(.rodata.field_plot_position_values);
        . = 0x104EAC; src/random_item.o(.rodata.random_item_selection_weights);
        . = 0x104ED0; src/random_item.o(.rodata.random_item_candidate_configurations);
        . = 0x105630; src/random_item.o(.rodata);
        . = 0x10563C; src/field_data.o(.rodata.field_plot_position_rules);
        . = 0x1056FC; src/field_data.o(.rodata);
        . = 0x105708; src/code_0800E2E4.o(.rodata.time_of_day_transition_table);
        . = 0x105748; src/code_0800E2E4.o(.rodata.time_of_day_transition_records);
        . = 0x105EDC; src/map_data.o(.rodata.map_data);
        . = 0x10692C; src/field_data.o(.rodata.field_render_rect_descriptors);
        . = 0x1070DC; src/farm_house.o(.rodata.farm_house_tile_patches);
        . = 0x107204; src/farm_house.o(.rodata.farm_house_visual_descriptors);
        . = 0x107338; src/farm_house.o(.rodata.farm_house_tile_patch_animations);
        . = 0x107350; src/field_data.o(.rodata.field_render_resource_first_values);
        . = 0x10735C; src/field_data.o(.rodata.field_render_resource_second_values);
        . = 0x107370; src/field_data.o(.rodata.field_render_resource_runtime_strings);
        . = 0x107388; src/field_data.o(.rodata.field_render_parallel_tables);
        . = 0x1073C4; src/field_data.o(.rodata.field_render_patch_arguments);
        . = 0x107424; src/field_data.o(.rodata.field_render_patch_arguments_after);
        . = 0x10742E; src/farm_house.o(.rodata.farm_house_style_nibble_lookup);
        FILL(0x00);
        . = 0x107438; src/bachelorette.o(.rodata.bachelorette_marriage_candidate_character_ids);
        . = 0x107450; src/field_data.o(.rodata.field_render_seasonal_record_ranges);
        . = 0x107458; src/field_data.o(.rodata.field_render_lookup_values);
        . = 0x1074A0; src/field_data.o(.rodata.field_render_runtime_strings);
        . = 0x1074F6; src/field_data.o(.rodata.field_render_sorted_values);
        . = 0x107514; src/field_data.o(.rodata.field_render_sorted_values_runtime_strings);
        . = 0x10752C; src/field_data.o(.rodata.unk_080AE894_values);
        . = 0x107568; src/field_data.o(.rodata.unk_080B0708_default_glyph);
        . = 0x10756C; src/field_data.o(.rodata.unk_080B09B0_index_values);
        . = 0x107588; src/field_data.o(.rodata.unk_080B0BB8_values);
        . = 0x1075B0; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_animal_husbandry);
        . = 0x10787C; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_match_values);
        . = 0x107882; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_u16_tables);
        . = 0x1078B0; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime);
        . = 0x1078BC; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime_empty);
        . = 0x1078BD; data/text/chicken_festival.o(.rodata.chicken_festival_contestant_names);
        . = 0x1079C4; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_opening);
        . = 0x107ACC; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_values);
        . = 0x107AFC; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_offsets);
        . = 0x107B00; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_instructions);
        . = 0x107CFC; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data);
        . = 0x107DD8; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_instructions);
        . = 0x107F60; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_results);
        . = 0x107FB0; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_first_values);
        . = 0x107FC6; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_second_values);
        . = 0x107FD4; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values);
        . = 0x108020; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_instructions);
        . = 0x108218; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_results);
        . = 0x108268; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_watering_results_values);
        . = 0x10828C; src/reference_guide.o(.rodata.reference_guide);
        . = 0x1177EC; src/shop_common.o(.rodata.shop_common_digit_glyphs);
        . = 0x11780C; data/text/shop_common.o(.rodata);
        . = 0x11782C; src/shop_common.o(.rodata);
        . = 0x1179AC; data/text/tool_status.o(.rodata.tool_status);
        . = 0x117A0C; data/text/animal_status.o(.rodata);
        . = 0x117A50; data/text/item_status.o(.rodata);
        . = 0x117AA8; data/text/item_discard.o(.rodata);
        . = 0x117B14; src/font.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard);
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

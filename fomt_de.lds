OUTPUT_ARCH(arm)

_M4aNumMusicPlayers = 5;
_M4aMaxLines = 0x50;

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
        . = ALIGN(4); src/m4a.o(.gMusicPlayerTrackA);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerTrackB);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerTrackC);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerTrackD);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerTrackE);
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
        src/main.o(.text);
        src/sram_proxy_1.o(.text);
        asm/interrupt.o(.text);
        src/new.o(.text);
        src/pure_virtual.o(.text);
        asm/sram_proxy_2.o(.text);
        src/sram_proxy_2.o(.text);
        asm/sram_proxy_2.o(.text.sram_proxy_2_after_006e4);
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
        . = 0x323CC; /* DE ROM 0x080323CC, entity-UI false handler. */
        src/entity_ui.o(.text.entity_ui_default_no_action);
        . = 0x323D0; /* DE ROM 0x080323D0, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_default_no_action_after);
        . = 0x32814; /* DE ROM 0x08032814, entity-UI coordinate classifier. */
        src/entity_ui.o(.text.entity_ui_region_classification);
        . = 0x32848; /* DE ROM 0x08032848, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_region_classification_after);
        . = 0x32914; /* DE ROM 0x08032914, entity-UI constructor. */
        src/entity_ui.o(.text.entity_ui_constructor);
        . = 0x32944; /* DE ROM 0x08032944, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_constructor_after);
        . = 0x33828; /* DE ROM 0x08033828, Harvest Sprite task experience transform. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_task_experience);
        . = 0x3383C; /* DE ROM 0x0803383C, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_harvest_sprite_task_experience_after);
        . = 0x33A38; /* DE ROM 0x08033A38, Harvest Sprite UI entry test. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_selection);
        . = 0x33A90; /* DE ROM 0x08033A90, entity-UI byte-0x41 clearer. */
        src/entity_ui.o(.text.entity_ui_unknown_flag);
        . = 0x33A98; /* DE ROM 0x08033A98, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_unknown_flag_after);
        . = 0x3415C; /* DE ROM 0x0803415C, entity-UI animation lookup. */
        src/entity_ui.o(.text.entity_ui_animation_lookup);
        . = 0x34174; /* DE ROM 0x08034174, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_animation_lookup_after);
        . = 0x34B10; /* DE ROM 0x08034B10, entity-UI resource setup. */
        src/entity_ui.o(.text.entity_ui_resource_setup);
        . = 0x34B54; /* DE ROM 0x08034B54, entity-UI value accessor. */
        src/entity_ui.o(.text.entity_ui_get_value_30);
        . = 0x34B5C; /* DE ROM 0x08034B5C, entity-UI pointer accessor. */
        src/entity_ui.o(.text.entity_ui_get_pointer_10);
        . = 0x34B60; /* DE ROM 0x08034B60, entity-UI value dispatcher. */
        src/entity_ui.o(.text.entity_ui_dispatch_value_30);
        . = 0x34B78; /* DE ROM 0x08034B78, entity-UI continuation. */
        asm/code_entities_080320DC.o(.text.entity_ui_resource_setup_after);
        src/npc_entity.o(.text);
        asm/code_entities_08034CEC.o(.text);

        . = 0x3A7B8; /* DE ROM 0x0803A7B8, remaining raw control code. */
        asm/code_0803A8A4.o(.text);
        . = 0x3BCF8; /* DE ROM 0x0803BCF8, set a u16 pair. */
        src/code_0803BDE4.o(.text);
        . = 0x3BD10; /* DE ROM 0x0803BD10, remaining raw control code. */
        asm/code_0803A8A4.o(.text.code_0803BDFC);
        . = 0x3BDB0; /* DE ROM 0x0803BDB0, unpack a packed value. */
        src/code_0803BE9C.o(.text);
        . = 0x3BDC4; /* DE ROM 0x0803BDC4, forward owned operations. */
        src/code_0803BEB0.o(.text);
        . = 0x3BDE8; /* DE ROM 0x0803BDE8, forward owned operations. */
        src/code_0803BED4.o(.text);
        . = 0x3BE00; /* DE ROM 0x0803BE00, read signed pair values. */
        src/code_0803BEEC.o(.text);
        . = 0x3BE10; /* DE ROM 0x0803BE10, forward pair operations. */
        src/code_0803BEFC.o(.text);
        . = 0x3BE28; /* DE ROM 0x0803BE28, remaining raw control code. */
        asm/code_0803A8A4.o(.text.code_0803BF14);
        . = 0x3C42C; /* DE ROM 0x0803C42C, activate control bytes. */
        src/code_0803C518.o(.text);
        . = 0x3C454; /* DE ROM 0x0803C454, read and clear control bytes. */
        src/code_0803C540.o(.text);
        . = 0x3C460; /* DE ROM 0x0803C460, remaining raw control code. */
        asm/code_0803A8A4.o(.text.code_0803C54C);
        . = 0x3E304; /* DE ROM 0x0803E304, Lou/Ruby Sunday schedule gate. */
        src/code_0803E40C.o(.text);
        . = 0x3E340; /* DE ROM 0x0803E340, remaining raw control code. */
        asm/code_0803A8A4.o(.text.code_0803E448);
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);
        . = 0x4E3A4; /* DE ROM 0x0804E3A4, ordinary 2D glyph compositor. */
        src/font_draw.o(.text.font_draw_normal);
        . = 0x4E4A4; /* DE ROM 0x0804E4A4, extended palette glyph compositor. */
        src/font_draw_ext.o(.text);
        . = 0x4E698; /* DE ROM 0x0804E698, tile-buffer fillers and renderer. */
        src/font_draw.o(.text);
        . = 0x4E8C8; src/font_draw.o(.text.font_draw_after);
        asm/code_0803EE94.o(.text.font_draw_after);
        . = 0x502F4; /* DE ROM 0x080502F4, nonzero UI-state setter. */
        src/ui_state.o(.text.set_ui_object_state_two_if_nonzero);
        . = 0x50308; /* DE ROM 0x08050308, nonzero UI-state clearer. */
        src/ui_state.o(.text.clear_ui_object_state_if_nonzero);
        . = 0x5031C; asm/code_0803EE94.o(.text.ui_object_state_after);
        . = 0x50A34; /* DE ROM 0x08050A34, UI action-state first-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01dc);
        . = 0x50A48; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01dc_after);
        . = 0x50B10; /* DE ROM 0x08050B10, UI action-state second-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01f0);
        . = 0x50B24; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01f0_after);
        . = 0x50C54; /* DE ROM 0x08050C54, UI-state adapter block. */
        src/ui_state.o(.text.ui_state_adapters);
        . = 0x50DDC; /* DE ROM 0x08050DDC, remaining UI-adjacent code. */
        asm/code_0803EE94.o(.text.code_08050E50);
        . = 0x521D0; /* DE ROM 0x080521D0, animal-festival ranking entry copy. */
        src/animal_festival_ranking.o(.text.copy_animal_festival_ranking_entry);
        . = 0x521E0; /* DE ROM 0x080521E0, animal-festival ranking entry setter. */
        src/animal_festival_ranking.o(.text.set_animal_festival_ranking_entry);
        . = 0x521F0; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E5C4; /* DE ROM 0x0805E5C4, indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E658; /* DE ROM 0x0805E658, indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E688; asm/code_0803EE94.o(.text.indexed_resource_archive_resolve_after);
        . = 0x5E714; /* DE ROM 0x0805E714, indexed resource-archive group count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_group_descriptor_count);
        . = 0x5E718; /* DE ROM 0x0805E718, indexed resource-archive entry count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_entry_descriptor_count);
        . = 0x5E71C; /* DE ROM 0x0805E71C, indexed resource-handle constructor. */
        src/resource_handle.o(.text.indexed_resource_handle_constructor);
        . = 0x5E748; /* DE ROM 0x0805E748, indexed resource-handle initializer. */
        src/resource_handle.o(.text.initialize_indexed_resource_handle);
        . = 0x5E758; /* DE ROM 0x0805E758, indexed resource-handle resolver. */
        src/resource_handle.o(.text.resolve_indexed_resource_handle);
        . = 0x5E78C; asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
        . = 0x75CB0; /* DE ROM 0x08075CB0, scroll-position reset. */
        src/scroll_state.o(.text.reset_scroll_position);
        . = 0x75CCC; /* DE ROM 0x08075CCC, scroll-buffer clear. */
        src/scroll_state.o(.text.clear_scroll_buffer);
        . = 0x75CE4; asm/code_0803EE94.o(.text.clear_scroll_buffer_after);
        . = 0x76AD8; /* DE ROM 0x08076AD8, selection-index state setter. */
        src/selection_state.o(.text.set_selection_index);
        . = 0x76AE4; /* DE ROM 0x08076AE4, selection-index state getter. */
        src/selection_state.o(.text.get_selection_index);
        . = 0x76AF4; /* DE ROM 0x08076AF4, selection-index continuation. */
        asm/code_0803EE94.o(.text.get_selection_index_after);
        . = 0x77D2C; /* DE ROM 0x08077D2C, 30x13 BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_30x13);
        . = 0x77D5C; /* DE ROM 0x08077D5C, rectangular BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_rect);
        . = 0x77DB8; /* DE ROM 0x08077DB8, town-map copy continuation. */
        asm/code_0803EE94.o(.text.copy_bg_map_rect_after);
        . = 0x781BC; /* DE ROM 0x080781BC, town-map cursor hit test. */
        src/town_map_data.o(.text.town_map_hotspot_contains);
        . = 0x781E4; /* DE ROM 0x080781E4, town-map continuation. */
        asm/code_0803EE94.o(.text.town_map_hotspot_contains_after);
        asm/code_0803EE94.o(.text.town_map_hotspot_contains_after_de_tail);

        /* DE places the shared actor constructor group after a 0x4C-byte
           regional code fragment in the preceding raw block.  Keep this
           group's physical start correct while that fragment is promoted. */
        . = 0x9B064;
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
        . = 0x9BF48; /* DE ROM 0x0809BF48, independently matched */
        src/code_actor_0809BFE8.o(.text);
        . = 0x9C0C0; /* DE ROM 0x0809C0C0, unlabelled raw helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C160);
        . = 0x9C18C; /* DE ROM 0x0809C18C, shared selector */
        src/code_actor_0809C22C.o(.text);
        . = 0x9C264; /* DE ROM 0x0809C264, shared table accessor */
        src/code_actor_0809C304.o(.text);
        . = 0x9C278; /* DE ROM 0x0809C278, raw actor helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C318);
        . = 0x9C28C; /* DE ROM 0x0809C28C, shared paired-state predicate */
        src/code_actor_0809C32C.o(.text);
        . = 0x9C2EC; /* DE ROM 0x0809C2EC, shared nonzero-state predicate */
        src/code_actor_0809C38C.o(.text);
        . = 0x9C31C; /* DE ROM 0x0809C31C, shared state initializer */
        src/code_actor_0809C3BC.o(.text);
        . = 0x9C340; /* DE ROM 0x0809C340, shared state advancement */
        src/code_actor_0809C3E0.o(.text);
        . = 0x9C380; /* DE ROM 0x0809C380, shared state reset */
        src/code_actor_0809C420.o(.text);
        . = 0x9C3A4; /* DE ROM 0x0809C3A4, shared conditional state advance */
        src/code_actor_0809C444.o(.text);
        . = 0x9C3D4; /* DE ROM 0x0809C3D4, shared state-update dispatcher */
        src/code_actor_0809C474.o(.text);
        . = 0x9C414; /* DE ROM 0x0809C414, shared state-update dispatcher */
        src/code_actor_0809C4B4.o(.text);
        . = 0x9C444; /* DE ROM 0x0809C444, shared word clear */
        src/code_actor_0809C4E4.o(.text);
        . = 0x9C44C; /* DE ROM 0x0809C44C, shared selection helper and raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C4EC);
        . = 0x9C514; /* DE ROM 0x0809C514, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C530; /* DE ROM 0x0809C530, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C54C; /* DE ROM 0x0809C54C, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C554; /* DE ROM 0x0809C554, test flag word */
        src/code_actor_0809C5F4.o(.text);
        . = 0x9C560; /* DE ROM 0x0809C560, register event-state variable */
        src/code_actor_0809C600.o(.text);
        . = 0x9C5A4; /* DE ROM 0x0809C5A4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C644);
        . = 0x9C5F4; /* DE ROM 0x0809C5F4, compare selected u16 */
        src/code_actor_0809C694.o(.text);
        . = 0x9C60C; /* DE ROM 0x0809C60C, set selected u16 */
        src/code_actor_0809C6AC.o(.text);
        . = 0x9C610; /* DE ROM 0x0809C610, reset selected u16 */
        src/code_actor_0809C6B0.o(.text);
        . = 0x9C61C; /* DE ROM 0x0809C61C, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C6BC);
        . = 0x9CCD8; /* DE ROM 0x0809CCD8, clear tracked counters */
        src/code_actor_0809CD78.o(.text);
        . = 0x9CCF8; /* DE ROM 0x0809CCF8, update count and maximum */
        src/code_actor_0809CD98.o(.text);
        . = 0x9CD2C; /* DE ROM 0x0809CD2C, test tracked counts */
        src/code_actor_0809CDCC.o(.text);
        . = 0x9CD4C; /* DE ROM 0x0809CD4C, sum tracked counts */
        src/code_actor_0809CDEC.o(.text);
        . = 0x9CD7C; /* DE ROM 0x0809CD7C, get record count */
        src/code_actor_0809CE1C.o(.text);
        . = 0x9CD84; /* DE ROM 0x0809CD84, get record maximum */
        src/code_actor_0809CE24.o(.text);
        . = 0x9CD90; /* DE ROM 0x0809CD90, map six input codes */
        src/code_actor_0809CE30.o(.text);
        . = 0x9CDDC; /* DE ROM 0x0809CDDC, get fishing-record name */
        src/code_actor_0809CE7C.o(.text);
        . = 0x9CDEC; /* DE ROM 0x0809CDEC, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CE8C);
        . = 0x9D378; /* DE ROM 0x0809D378, map a segmented input value */
        src/code_actor_0809D418.o(.text);
        . = 0x9D3D0; /* DE ROM 0x0809D3D0, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D470);
        . = 0x9D738; /* DE ROM 0x0809D738, classify actor-state value */
        src/code_actor_0809D7D8.o(.text);
        . = 0x9D800; /* DE ROM 0x0809D800, read state value */
        src/code_actor_0809D8A0.o(.text);
        . = 0x9D804; /* DE ROM 0x0809D804, map one state value */
        src/code_actor_0809D8A4.o(.text);
        . = 0x9D818; /* DE ROM 0x0809D818, map two state values */
        src/code_actor_0809D8B8.o(.text);
        . = 0x9D834; /* DE ROM 0x0809D834, read packed grid-cell value */
        src/code_actor_0809D8D4.o(.text);
        . = 0x9D848; /* DE ROM 0x0809D848, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9DE8C; /* DE ROM 0x0809DE8C, query tool availability by group */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9DF0C; /* DE ROM 0x0809DF0C, count actor-state flag bits */
        src/code_actor_0809DFAC.o(.text);
        . = 0x9DF8C; /* DE ROM 0x0809DF8C, count actor-state flag bits */
        src/code_actor_0809E02C.o(.text);
        . = 0x9E00C; /* DE ROM 0x0809E00C, select actor-state cell-type data */
        src/code_actor_0809E0AC.o(.text);
        . = 0x9E078; /* DE ROM 0x0809E078, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9E0D4; /* DE ROM 0x0809E0D4, read actor-state bit 0 */
        src/code_actor_0809E174.o(.text);
        . = 0x9E0E4; /* DE ROM 0x0809E0E4, read actor-state bit 2 */
        src/code_actor_0809E184.o(.text);
        . = 0x9E0F4; /* DE ROM 0x0809E0F4, read actor-state bit 3 */
        src/code_actor_0809E194.o(.text);
        . = 0x9E104; /* DE ROM 0x0809E104, read actor-state bit 4 */
        src/code_actor_0809E1A4.o(.text);
        . = 0x9E114; /* DE ROM 0x0809E114, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        src/npc.o(.text);
        src/bachelorette.o(.text);
        src/harvest_sprite.o(.text);

        . = 0x9E764; /* DE ROM 0x0809E764, shared NPC helper block. */
        asm/code_809E804.o(.text);
        . = 0x9EA2C; /* DE ROM 0x0809EA2C, NPC runtime fields. */
        src/npc_runtime_data.o(.text);
        . = 0x9EA58; /* DE ROM 0x0809EA58, remaining NPC runtime code. */
        asm/code_809E804.o(.text.npc_runtime_data_after);
        . = 0xA45F8; /* DE ROM 0x080A45F8, map-data accessor. */
        src/map_data.o(.text.get_map_data);
        . = 0xA460C; /* DE ROM 0x080A460C, remaining map-data code. */
        asm/code_809E804.o(.text.get_map_data_after);
        . = 0xD0C38; /* DE ROM 0x080D0C38, glyph-map index converter and renderer. */
        src/font.o(.text);
        . = 0xD0E20; /* DE ROM 0x080D0E20, remaining font support code. */
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
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6bd8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6c18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6c58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6c98);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6cd8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6d18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6d58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6d98);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6dd8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6e18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6e58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6e98);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6ed8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6f18);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6f58);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6f98);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_6fd8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7018);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7058);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7098);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_70d8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7118);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7158);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7198);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_npc_entity);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7218);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_725c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_72a0);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_72e4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7328);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_736c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7380);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_73b4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_73e8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_73fc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7430);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7444);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7478);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_748c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_749c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_74ac);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_74bc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_74cc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_74dc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7568);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_759c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_75b4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_75cc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_75e4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_75fc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7614);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_762c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7644);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_765c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7674);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_768c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_76a4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_76bc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_76d4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_76e8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_76f8);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7708);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7714);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7728);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7738);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7748);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7758);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7768);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7778);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_77a4);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_77d0);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_77e0);
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
        src/sram_proxy_1.o(.rodata);
        src/intro_scene_startup.o(.rodata);
        . = 0xE860C; /* DE ROM 0x080E860C, new-game regional text and tables. */
        src/new_game_menu_data.o(.rodata);
        . = 0xE8CD0; /* DE ROM 0x080E8CD0, following field data. */
        src/field_data.o(.rodata);
        . = 0xE95D8; src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        /* Item text, catalogs, products, and trailer. */
        src/item.o(.rodata);
        /* Calendar rows, labels, and state data. */
        . = 0xF09B2; src/game_state.o(.rodata);
        FILL(0x00);
        /* Help-menu text and byte table. */
        . = 0xF0A50; src/help_menu.o(.rodata);
        /* Animal memorial text and animal data. */
        . = 0xF0B18; src/animal_data.o(.rodata);
        /* Entity UI labels and native UI data. */
        . = 0xF1368; src/entity_ui.o(.rodata);
        FILL(0x00);
        /* Common UI labels, fallback text, menu data, and pointer table. */
        . = 0xF1E5C; src/common_ui.o(.rodata);
        FILL(0x00);
        . = 0xF1F68; src/data_schedules.o(.rodata);
        /* Entity UI resource-selector data follows schedule data. */
        . = ALIGN(4); src/entity_ui_resource_selector.o(.rodata);
        FILL(0x00);
        . = 0xF47D8; asm/data/data_080F1A80.o(.rodata.data_080f1a80_suffix);
        . = 0xF8EBC; data/scripts/script_table.o(.rodata.mary_script_table);
        . = ALIGN(4); src/script_engine.o(.rodata);
         src/cooking_festival_data.o(.rodata);
        src/thomas_stocking_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/spouse_gift_data.o(.rodata);
         src/farm_house.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/ui_state.o(.rodata);
        /* New Game preset regional data: names and UI glyphs. */
        data/text/new_game_preset.o(.rodata);
         src/new_game_name_entry_ui_data.o(.rodata);
        FILL(0x00);
         data/text/frisbee_scoreboard.o(.rodata);
         src/animal_festival_ranking.o(.rodata.animal_festival_ranking_score_table);
         src/animal_festival_ranking.o(.rodata.animal_festival_ranking_scoreboard_trailer);
         src/animal_festival_ranking.o(.rodata.animal_festival_ranking_data);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_reward_article_ids);
         data/text/frisbee.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_random_range_pairs);
         data/text/animal_festival.o(.rodata);
         src/animal_festival_ranking.o(.rodata.animal_festival_livestock_contestant_values);
        FILL(0x00);
        . = ALIGN(4);
         src/horse_race_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Intro-scene resource table, dialogue, and runtime tail. */
        src/intro_scene_data.o(.rodata);
        FILL(0x00);
        /* Farm Status regional data: two text groups and UI data. */
        . = 0xFBE5C; src/farm_status_screen_data.o(.rodata);
        FILL(0x00);
        . = 0xFC580; src/records_screen_data.o(.rodata);
        . = 0xFC7B0; data/text/staff_credits.o(.rodata);
        . = 0xFCDC4; src/town_map_data.o(.rodata.staff_credits_trailer);
        src/town_map_data.o(.rodata.town_map_resource_ids);
        /* Town Map regional data: labels, hotspots, and lookup. */
        FILL(0x00);
         src/town_map_data.o(.rodata);
         src/library_data.o(.rodata.library_opening_hours);
        FILL(0x00);
        . = ALIGN(4); src/town_map_data.o(.rodata.town_map_area_bounds);
        src/library_data.o(.rodata.library_info);
        FILL(0x00);
        . = ALIGN(4); src/library_data.o(.rodata.library_initial_entry_ids);
        src/library_data.o(.rodata.library_menu);
        src/poultry_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/supermarket_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/clinic_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/inn_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/won_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/winery_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/special_merchant_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
         src/beach_cafe_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFF4AC; src/blacksmith_menu_data.o(.rodata);
        src/blacksmith_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFFB98; src/carpenter_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0x00);
        src/livestock_shop.o(.rodata);
         data/text/home_storage.o(.rodata);
        FILL(0x00);
         src/blacksmith_upgrade_data.o(.rodata);
         data/text/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Link-communication regional data: text, tables, codes. */
        FILL(0x00);
        . = 0x100EA0; src/link_communication_data.o(.rodata);
        . = 0x1014DC;
         src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break);
         src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_utensil_values);
         data/text/recovery_status.o(.rodata);
         data/text/cooking.o(.rodata);
         src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_mask_entries);
         src/cooking_recipe_inventory_data.o(.rodata);
        src/animal.o(.rodata.animal_unnamed);
         src/livestock.o(.rodata.livestock_day_update);
         src/code_actor_0809C3E0.o(.rodata.actor_state_max_values);
         src/code_actor_0809C3E0.o(.rodata);
        /* Fishing-record regional data: names, lookup, trailer. */
         src/fishing_results_data.o(.rodata);
        FILL(0x00);
         src/code_actor_0809BFE8.o(.rodata);
         src/character_names_data.o(.rodata.character_names_empty);
         src/bachelorette.o(.rodata);
        /* Character-name regional data: names, lookup, trailer. */
         src/character_names_data.o(.rodata);
        FILL(0x00);
        src/field_item_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0x105390; data/text/calendar_events.o(.rodata);
         data/text/possessive_labels.o(.rodata);
         data/text/random_item.o(.rodata);
         src/fishing_results_data.o(.rodata.fishing_record_article_ids);
        src/field_plot_position_values.o(.rodata);
         src/random_item.o(.rodata.random_item_selection_weights);
         src/random_item.o(.rodata.random_item_candidate_configurations);
         src/random_item.o(.rodata);
        src/field_plot_position_rules.o(.rodata);
        src/code_0800E2E4.o(.rodata.time_of_day_transition_table);
         src/code_0800E2E4.o(.rodata.time_of_day_transition_records);
         src/map_data.o(.rodata.map_data);
        src/field_render_rect_descriptors.o(.rodata);
         src/field_render_farm_house_data.o(.rodata);
        src/field_render_resource_data.o(.rodata);
        FILL(0x00);
         src/bachelorette.o(.rodata.bachelorette_marriage_candidate_character_ids);
        src/field_render_runtime_data.o(.rodata);
        src/harvest_sprite.o(.rodata);
         src/reference_guide.o(.rodata.reference_guide);
         src/shop_common.o(.rodata.shop_common_digit_glyphs);
         data/text/shop_common.o(.rodata);
         src/shop_common.o(.rodata);
         data/text/status_ui.o(.rodata);
         src/font.o(.rodata);
        FILL(0x00);
        . = 0x119C54; asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard);
        . = 0x13BB08; src/m4a.o(.rodata);
        . = 0x13BDE0; src/m4a.o(.rodata.gM4aVoiceGroups);
        . = 0x13CC34; src/m4a.o(.rodata.gMusicPlayerTable);
        . = ALIGN(4); src/m4a.o(.rodata.gSongTable);
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
        . = 0x4E2E74; data/scripts/scripts.o(.rodata.mary_scripts);
        . = 0x71DDD4; asm/data/data_0813B288.o(.rodata.mary_scripts_tail);
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
        . = 0x08800000 - (__iwram_lma + SIZEOF(.iwram));
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

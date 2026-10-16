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
        . = 0x000404; src/hardware.o(.bss COMMON);
        . = 0x000408; src/hardware_refcount.o(.bss COMMON);
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

    .text : ALIGN(4)
    {
        src/crt0.o(.rom_header);
        src/main.o(.text);
        src/sram_proxy_1.o(.text);
        src/interrupt.o(.text);
        src/new.o(.text);
        src/pure_virtual.o(.text);
        src/sram_proxy_2.o(.text.func_0800063C .text.func_08000640 .text.func_08000664);
        asm/sram_proxy_2.o(.text);
        src/sram_proxy_2.o(.text.func_080006E4 .text.func_08000714 .text.func_08000728);
        src/scene.o(.text);
        src/intro_scene.o(.text.intro_scene_core_constructor);
        src/intro_scene.o(.text.intro_scene_core_run);
        src/intro_scene.o(.text.intro_scene_core_startup);
        asm/intro_scene.o(.text.intro_scene_core_after_startup);
        src/intro_scene.o(.text.intro_scene_core_sequence);
        asm/intro_scene.o(.text.intro_scene_core_after_sequence);
        src/intro_scene.o(.text.intro_scene_sprite_submission);
        src/intro_scene.o(.text);
        asm/new_game.o(.text);
        src/new_game.o(.text);
        asm/new_game.o(.text.new_game_after_fades);
        src/new_game.o(.text.new_game_menu_update);
        asm/new_game.o(.text.new_game_after_status_update);
        src/new_game.o(.text.new_game_scene_lifecycle);
        asm/new_game.o(.text.new_game_after_scene_lifecycle);
        src/new_game.o(.text.new_game_identity_core_cleanup);
        src/new_game.o(.text.new_game_identity_core_run);
        src/new_game.o(.text.new_game_identity_core_initialization);
        asm/new_game.o(.text.new_game_identity_core_after_initialization);
        src/new_game.o(.text.new_game_identity_core_update);
        src/new_game.o(.text.new_game_identity_scene);
        src/new_game.o(.text.new_game_name_input_core_constructor);
        src/new_game.o(.text.new_game_name_input_core_cleanup);
        src/new_game.o(.text.new_game_name_input_core_run);
        asm/new_game.o(.text.new_game_name_input_after_core_run);
        src/new_game.o(.text.new_game_name_input_sprites);
        src/new_game.o(.text.new_game_name_input_reset);
        asm/new_game.o(.text.new_game_name_input_after_reset);
        src/new_game.o(.text.new_game_name_input_submit_sprites);
        src/new_game.o(.text.new_game_name_input_cursor_sprites);
        src/new_game.o(.text.new_game_name_input_keyboard_cursor);
        src/new_game.o(.text.new_game_name_input_insert_character);
        src/new_game.o(.text.new_game_name_input_erase_character);
        src/new_game.o(.text.new_game_name_input_normalization);
        src/new_game.o(.text.new_game_name_input_keys);
        src/new_game.o(.text.new_game_name_input_confirmation);
        src/new_game.o(.text.new_game_name_input_scene);
        src/hardware.o(.text);
        src/hardware_allocator.o(.text);
        asm/hardware.o(.text.hardware_allocator_after);
        src/hardware_resource.o(.text);
        src/hardware_mask.o(.text);
        asm/hardware.o(.text.hardware_mask_after);
        src/hardware_refcount.o(.text);
        asm/hardware.o(.text.hardware_refcount_after);
        src/hardware_refcount.o(.text.hardware_shared_state_handles);
        src/hardware_state_properties.o(.text);
        asm/hardware.o(.text.hardware_state_properties_after);
        src/hardware_state_clear.o(.text);
        src/hardware_bootstrap.o(.text);
        src/hardware_state_accessors.o(.text);
        src/hardware_manager.o(.text);
        src/hardware_nested_accessors.o(.text);
        src/hardware_sound.o(.text);
        src/hardware_music_player.o(.text);
        src/hardware_song.o(.text);
        src/hardware_dma.o(.text);
        src/hardware_dma_descriptor.o(.text);
        src/hardware_input.o(.text);
        src/hardware_input_repeat.o(.text);
        src/hardware_blend.o(.text);
        asm/hardware.o(.text.hardware_blend_after);
        src/hardware_blend_object.o(.text);
        src/hardware_interrupt_guard.o(.text);
        src/hardware_display_output.o(.text);
        src/hardware_oam_state.o(.text);
        src/hardware_linked_list.o(.text);
        src/hardware_linked_list.o(.text.hardware_linked_list_constructor);
        src/hardware_linked_list.o(.text.hardware_linked_list_tail);
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
        src/time_of_day.o(.text);
        src/farmer.o(.text);
        src/rucksack_item.o(.text);
        src/held_item.o(.text);
        src/rucksack.o(.text);
        src/more_items.o(.text);
        asm/more_items.o(.text);
        asm/game_scene.o(.text);
        src/game_scene.o(.text.func_08010*);
        asm/game_scene.o(.text.game_scene_post);
        src/game_state.o(.text.GetNonzeroRandomValue .text.__18GameStateSaveImagePCcT1G8GameDateT1 .text.Get*__C18GameStateSaveImage .text.AllAnimalsHaveHighAffection__C18GameStateSaveImage .text.SetFlag[0-3]__18GameStateSaveImage);
        asm/game_state.o(.text.game_state_after_startup_accessors);
        src/game_state.o(.text.CollectShippingRevenue__18GameStateSaveImage .text.SetFlag4__18GameStateSaveImage .text.UpdateUnknown*__18GameStateSaveImageUi);
        src/game_state.o(.text.InitializeGameDisplayOptions);
        src/game_state.o(.text.*);
        asm/game_state.o(.text.game_state_after_display_options);
        src/game_scene.o(.text._._9GameScene);
        /* Keep the recovered member runs around the native opener and menus.
         * Patterns in one input selector keep the object's section order. */
        src/game_scene.o(
            .text.Run__9GameScene* .text.GetEntity*__9GameScene*
            .text.SetEntityA*__9GameScene* .text.SetEntityFacing__9GameScene*
            .text.SetEntityPosition__9GameScene* .text.SetEntitySpritePriority__9GameScene*
            .text.MoveEntity*__9GameScene* .text.WaitFor*__9GameScene*
            .text.NoOp*__9GameScene* .text.HideEntity__9GameScene* .text.OffsetEntityPosition__9GameScene*
            .text.StartEntityEffect__9GameScene* .text.Stop*__9GameScene*
            .text.ChangeMap__9GameScene* .text.P[al]*__9GameScene*);
        asm/game_state.o(.text.game_scene_entity_commands_after);
        src/game_scene.o(
            .text.Talk*__9GameScene* .text.FadeScreen__9GameScene*
            .text.TextVariable*__9GameScene* .text.CallScript__9GameScene*
            .text.QueueScript__9GameScene* .text.WaitFrames__9GameScene*);
        asm/game_state.o(.text.game_scene_text_variable_commands_after);
        src/game_scene.o(.text.*__9GameScene*);
        asm/game_state.o(.text.game_scene_menu_hooks_after);
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
        . = 0x34B78; /* NPC schedule query and entity methods. */
        src/npc_entity.o(.text.func_08034C64 .text.*ANpcEntity* .text.func_08034E* .text.func_08034F00);
        asm/code_entities_08034CEC.o(.text);
        src/npc_entity.o(.text.func_08035908 .text.func_08035940);
        asm/code_entities_08034CEC.o(.text.npc_schedule_transition_query);
        src/npc_entity.o(.text.func_08035A48 .text.func_08035AE0);
        asm/code_entities_08034CEC.o(.text.npc_characters_after);

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
        src/npc.o(.text.InitializeSchedule__3NpcRC12ScheduleInfoPCv);
        src/npc_collection.o(.text.InitializeSchedules__13NpcCollectionRC18GameStateSaveImage);
        asm/code_0803A8A4.o(.text.npc_schedule_after);
        . = 0x3E304; /* DE ROM 0x0803E304, Lou/Ruby Sunday schedule gate. */
        src/code_0803E40C.o(.text);
        . = 0x3E340; /* DE ROM 0x0803E340, remaining raw control code. */
        asm/code_0803A8A4.o(.text.code_0803E448);
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);
        . = 0x4E3A4; /* DE ROM 0x0804E3A4, ordinary 2D glyph compositor. */
        asm/font_draw.o(.text.font_draw_normal);
        . = 0x4E4A4; /* DE ROM 0x0804E4A4, extended palette glyph compositor. */
        asm/font_draw.o(.text.font_draw_ext);
        . = 0x4E698; /* DE ROM 0x0804E698, tile-buffer fillers and renderer. */
        src/font_draw.o(.text.Clear2DGfxBuffer);
        asm/font_draw.o(.text.font_draw_clear_rectangle);
        src/font_draw.o(.text.DrawStringTo2DGfxBuffer);
        src/font_draw.o(.text.DrawStringTo2DGfxBufferExt);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferUnaligned);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferExtUnaligned);
        . = 0x4E8C8; src/font_draw.o(.text.Copy2DGfxBuffer);
        src/font_draw.o(.text.Fill2DGfxTilemapRect);
        src/font_draw.o(.text.InitializeUnkFontDrawObject);
        src/font_draw.o(.text.DestroyUnkFontDrawObject);
        asm/code_0803EE94.o(.text.font_draw_after);
        src/font.o(.text.font_decimal);
        asm/code_0803EE94.o(.text.font_decimal_after);
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
        . = 0x50BB8; /* DE ROM 0x08050BB8, UI owner and adapter block. */
        src/ui_state.o(.text.ui_state_adapters);
        asm/code_0803EE94.o(.text.code_08050E50);
        src/ui_state.o(.text);
        asm/code_0803EE94.o(.text.ui_state_helpers_after);
        src/ui_state.o(.text.ui_state_selection);
        asm/code_0803EE94.o(.text.ui_state_selection_after);
        src/animal_festival_ranking.o(.text);
        . = 0x521F0; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E5C4; /* DE ROM 0x0805E5C4, indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E658; /* DE ROM 0x0805E658, indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E688; src/resource_handle.o(.text.indexed_resource_archive_get_group_data);
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
        . = 0x5E78C; src/resource_handle.o(.text.indexed_resource_handle_predict_wrap);
        asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
        src/resource_handle.o(.text.indexed_resource_sprite_transform);
        asm/code_0803EE94.o(.text.indexed_resource_sprite_transform_after);
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
        src/cooking_recipe_inventory_data.o(.text);
        asm/code_0803EE94.o(.text.cooking_recipe_inventory_after);
        src/money_account.o(.text.money_account_update);
        asm/code_0803EE94.o(.text.money_account_history);
        src/money_account.o(.text);

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
        src/actor_runtime_data.o(.text);
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
        src/actor_state.o(.text.func_0809C3E0);
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
        . = 0x9C554; /* Event-variable registrations, romance marker and packed save state. */
        src/event_state.o(.text);
        . = 0x9CCD8; /* Fishing-record storage and queries. */
        src/fishing_results_data.o(.text);
        . = 0x9CDEC; /* DE ROM 0x0809CDEC, remaining raw actor code */
        src/actor_state.o(.text.__14ActorStateGrid);
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CF34);
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
        src/actor_state.o(.text.func_0809D8D4);
        . = 0x9D848; /* DE ROM 0x0809D848, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9DE8C; /* DE ROM 0x0809DE8C, query tool availability by group */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9DF0C; /* DE ROM 0x0809DF0C, count actor-state flag bits */
        src/actor_state.o(.text.func_0809DFAC);
        . = 0x9DF8C; /* DE ROM 0x0809DF8C, count actor-state flag bits */
        src/actor_state.o(.text.func_0809E02C);
        . = 0x9E00C; /* DE ROM 0x0809E00C, select actor-state cell-type data */
        src/actor_state.o(.text.func_0809E0AC);
        . = 0x9E078; /* DE ROM 0x0809E078, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9E0D4; /* DE ROM 0x0809E0D4, read actor-state bit 0 */
        src/actor_state.o(.text.func_0809E174);
        . = 0x9E0E4; /* DE ROM 0x0809E0E4, read actor-state bit 2 */
        src/actor_state.o(.text.func_0809E184);
        . = 0x9E0F4; /* DE ROM 0x0809E0F4, read actor-state bit 3 */
        src/actor_state.o(.text.func_0809E194);
        . = 0x9E104; /* DE ROM 0x0809E104, read actor-state bit 4 */
        src/actor_state.o(.text.func_0809E1A4);
        . = 0x9E114; /* DE ROM 0x0809E114, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        src/npc.o(.text .text.*);
        src/bachelorette.o(.text);
        src/harvest_sprite.o(.text .text.*__*);

        . = 0x9E918; /* Child constructors, birthday, age and walking state. */
        src/child.o(.text);
        . = 0x9EAAC; /* Gotz, Saibara and Van saved state. */
        src/gotz.o(.text);
        src/saibara.o(.text);
        src/van.o(.text);
        src/npc_collection.o(.text.__13NpcCollection);
        asm/code_809E804.o(.text.npc_after_child);
        src/npc_collection.o(.text.GetPartnerCharacterId__C13NpcCollection .text.GetSpouseCharacterId__C13NpcCollection .text.IsMarried__C13NpcCollection);
        asm/code_809E804.o(.text.npc_after_partner_queries);
        src/npc_collection.o(.text.GetNpc__13NpcCollectionUi .text.GetBachelorette__13NpcCollectionUi .text.GetHarvestSpriteByCharacterId__13NpcCollectionUi .text.GetHarvestSpriteByIndex__13NpcCollectionUi);
        src/npc_collection.o(.text.GetChild__13NpcCollection);
        src/npc_collection.o(.text.AddUnk00_0__13NpcCollectionUi .text.AddUnk00_6__13NpcCollectionUi .text.IncrementUnk01_5OncePerDay__13NpcCollection .text.GetSouthTownNpcLocation1__13NpcCollectionUi .text.GetSouthTownNpcLocation2__13NpcCollectionUi .text.GetYodelRanchHouseNpcLocation__13NpcCollection .text.GetInnSecondFloorNpcLocation__13NpcCollection);
        src/npc_collection.o(.text.DayUpdate__13NpcCollectionRC14GameStateClockRC14GameEventStateRC6FarmerRC4Farm);
        src/npc_collection.o(.text.SetWeddingDate__13NpcCollectionRC11WeddingDate .text.GetWeddingDate__C13NpcCollection);
        asm/code_809E804.o(.text.npc_after_wedding_date);
        src/npc_locations.o(.text);
        src/field_item_data.o(.text);
        asm/code_809E804.o(.text.field_item_after);
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
        src/libsram.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        src/libc_string.o(.text);

        src/new.o(.text.new_retry);
        src/intro_scene.o(.text.intro_scene_transitions);
        *(.gnu.linkonce.t._._19IntroMenuTransition);
        *(.gnu.linkonce.t._._24IntroNameEntryTransition);
        asm/code_linkonce.o(.text.code_080D3C78);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        asm/code_linkonce.o(.text.code_080D68C0);
        src/hardware.o(.text.hardware_free_list);
        src/hardware_resource.o(.text.code_080D6DB8);
        src/hardware_refcount.o(.text.hardware_shared_state_tile_tree);
        asm/code_linkonce.o(.text.hardware_shared_state_tile_tree_after);
        src/hardware_refcount.o(.text.hardware_shared_state_tile_tree_after);
        src/hardware_refcount.o(.text.hardware_shared_state_tile_tree_unreserve);
        asm/code_linkonce.o(.text.hardware_shared_state_tile_tree_unreserve_after);
        src/hardware_refcount.o(.text.hardware_shared_state_tile_tree_unreserve_after);
        src/hardware_refcount.o(.text.hardware_shared_state_tile_tree_operations);
        src/hardware_refcount.o(.text.hardware_shared_state_free_list);
        src/hardware_state_clear.o(.text.hardware_shared_state_free_list_after);
        src/hardware_bootstrap.o(.text.hardware_frame_commands);
        asm/code_linkonce.o(.text.hardware_dma_command);
        src/hardware_bootstrap.o(.text.hardware_frame_command_cleanup);
        asm/code_linkonce.o(.text.hardware_frame_commands_after);
        *(.gnu.linkonce.t.__as__5SheepRC5Sheep);
        *(.gnu.linkonce.t.__as__3CowRC3Cow);
        *(.gnu.linkonce.t.__as__9LivestockRC9Livestock);
        *(.gnu.linkonce.t.push_back__Q28Rucksackt5Slots1Z12RucksackItemG12RucksackItem);
        *(.gnu.linkonce.t.push_front__Q28Rucksackt5Slots1Z12RucksackItemG12RucksackItem);
        *(.gnu.linkonce.t.push_back__Q28Rucksackt5Slots1Z9ToolStackG9ToolStack);
        *(.gnu.linkonce.t.push_front__Q28Rucksackt5Slots1Z9ToolStackG9ToolStack);
        asm/code_linkonce.o(.text.code_080D7CFC);
        src/npc_entity.o(.text.FindScheduleEntryUpperBound);
        src/game_scene.o(.text.func_080D7F*);
        asm/code_linkonce.o(.text.game_scene_state_callbacks_after);
        src/game_scene.o(.text.CreateScene__18CalendarTransition);
        asm/code_linkonce.o(.text.scene_calendar_after);
        src/game_scene.o(.text.CreateScene__19ToolChestTransition);
        asm/code_linkonce.o(.text.scene_tool_chest_after);
        src/game_scene.o(.text.CreateScene__22RefrigeratorTransition);
        asm/code_linkonce.o(.text.scene_refrigerator_after);
        src/game_scene.o(.text.CreateScene__15ShelfTransition);
        asm/code_linkonce.o(.text.scene_shelf_after);
        src/game_scene.o(.text.CreateScene__17CookingTransition);
        asm/code_linkonce.o(.text.scene_cooking_after);
        src/game_scene.o(.text.CreateScene__23ReferencePageTransition);
        asm/code_linkonce.o(.text.scene_reference_page_after);
        src/game_scene.o(.text.CreateScene__29SpecialMerchantShopTransition);
        asm/code_linkonce.o(.text.scene_special_merchant_shop_after);
        src/game_scene.o(.text.CreateScene__22GiftWrappingTransition);
        asm/code_linkonce.o(.text.scene_gift_wrapping_after);
        src/game_scene.o(.text.CreateScene__24YodelRanchShopTransition);
        asm/code_linkonce.o(.text.scene_yodel_ranch_shop_after);
        src/game_scene.o(.text.CreateScene__25PoultryFarmShopTransition);
        asm/code_linkonce.o(.text.scene_poultry_farm_shop_after);
        src/game_scene.o(.text.CreateScene__20WineryShopTransition);
        asm/code_linkonce.o(.text.scene_winery_shop_after);
        src/game_scene.o(.text.CreateScene__17InnShopTransition);
        asm/code_linkonce.o(.text.scene_inn_shop_after);
        src/game_scene.o(.text.CreateScene__23BeachCafeShopTransition);
        asm/code_linkonce.o(.text.scene_beach_cafe_shop_after);
        src/game_scene.o(.text.CreateScene__17WonShopTransition);
        asm/code_linkonce.o(.text.scene_won_shop_after);
        src/game_scene.o(.text.CreateScene__23CarpenterShopTransition);
        asm/code_linkonce.o(.text.scene_carpenter_shop_after);
        src/game_scene.o(.text.CreateScene__20ClinicShopTransition);
        asm/code_linkonce.o(.text.scene_clinic_shop_after);
        src/game_scene.o(.text.CreateScene__24BlacksmithShopTransition);
        asm/code_linkonce.o(.text.scene_blacksmith_shop_after);
        src/game_scene.o(.text.CreateScene__29SupermarketPurchaseTransition);
        asm/code_linkonce.o(.text.scene_supermarket_purchase_after);
        src/game_scene.o(.text.CreateScene__21SupermarketTransition);
        asm/code_linkonce.o(.text.scene_supermarket_after);
        src/game_scene.o(.text.CreateScene__15ClockTransition);
        asm/code_linkonce.o(.text.scene_clock_after);
        src/game_scene.o(.text.CreateScene__17ReturnToGameScene);
        asm/code_linkonce.o(.text.scene_return_after);
        src/npc_entity.o(.text.FindTimedPathPointUpperBound);
        asm/code_linkonce.o(.text.npc_timed_path_search_after);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        asm/code_linkonce.o(.text.code_080E0EF0);
        src/font.o(.text.font_unsigned_decimal);
        asm/code_linkonce.o(.text.code_080E0F48);
        src/harvest_sprite.o(.text.FindHarvestSpriteWorkTarget);
        asm/code_linkonce.o(.text.sprite_work_target_search_after);

    } > ROM = 0xFF

    .rodata : ALIGN(4)
    {
        *(.gnu.linkonce.d.__vt_6AScene);
        *(.gnu.linkonce.d.__vt_15SceneTransition);
        *(.gnu.linkonce.d.__vt_19IntroMenuTransition);
        *(.gnu.linkonce.d.__vt_24IntroNameEntryTransition);
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
. = ALIGN(4); src/vtables.o(.rodata.vtable_82c8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82d4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82d8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82e4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82fc);
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

        /* Start of the source-owned localization islands. */
        . = ABSOLUTE(0x080E8574); src/crt0_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/sram_proxy_1.o(.rodata);
        src/intro_scene_startup.o(.rodata);
        . = ABSOLUTE(0x080E860C); /* DE ROM 0x080E860C, new-game regional text and tables. */
        src/new_game_data.o(.rodata);
        . = ABSOLUTE(0x080E8CD0); /* DE ROM 0x080E8CD0, following field data. */
        src/field_data.o(.rodata);
        . = ABSOLUTE(0x080E95D8); src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        /* Item text, catalogs, products, and trailer. */
        src/item.o(.rodata);
        /* Calendar rows, labels, and state data. */
        . = ABSOLUTE(0x080F09B2); src/game_state.o(.rodata);
        FILL(0x00);
        /* Help-menu text and byte table. */
        . = ABSOLUTE(0x080F0A50); src/help_menu.o(.rodata);
        /* Animal memorial text and animal data. */
        FILL(0x00);
        . = ALIGN(4); src/animal_data.o(.rodata);
        /* Entity UI labels and native UI data. */
        . = ABSOLUTE(0x080F1368); src/entity_ui.o(.rodata);
        FILL(0x00);
        /* Common UI labels, fallback text, menu data, and pointer table. */
        . = ABSOLUTE(0x080F1E5C); src/common_ui.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x080F1F68); src/data_schedules.o(.rodata);
        /* Other NPC schedule records follow the individually declared schedules. */
        . = ALIGN(4); src/npc_schedule_data.o(.rodata);
        . = ABSOLUTE(0x080F8EBC); data/scripts/script_table.o(.rodata.mary_script_table);
        /* The ordinary source block bounds the preceding Mary script table. */
        . = ABSOLUTE(0x080FA380); src/script_engine.o(.rodata);
         src/cooking_festival.o(.rodata);
        src/thomas_stocking.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/spouse_gift.o(.rodata);
         src/farm_house.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/ui_state.o(.rodata);
        /* New Game preset regional data: names and UI glyphs. */
        src/new_game_name_entry_ui_data.o(.rodata);
        FILL(0x00);
        src/frisbee_scoreboard.o(.rodata);
        src/animal_festival_ranking_score_data.o(.rodata);
        src/frisbee.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
         src/horse_race_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Intro-scene resource table, dialogue, and runtime tail. */
        src/intro_scene_data.o(.rodata);
        FILL(0x00);
        /* Farm Status screen data. */
        . = ABSOLUTE(0x080FBE5C); src/farm_status_screen_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x080FC580); src/records_screen_data.o(.rodata);
        . = ABSOLUTE(0x080FC7B0); src/staff_credits.o(.rodata);
        /* Town Map regional data: labels, hotspots, and lookup. */
        . = ABSOLUTE(0x080FCDCE); src/town_map_data.o(.rodata);
         src/library_opening_hours_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/town_map_area_data.o(.rodata);
        src/library_data.o(.rodata);
        . = ABSOLUTE(0x080FE0B8); src/poultry_shop_data.o(.rodata);
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
        . = ABSOLUTE(0x080FF4AC); src/blacksmith_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x080FFB98); src/carpenter_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0x00);
        src/livestock_shop.o(.rodata);
         src/home_storage.o(.rodata);
        FILL(0x00);
         src/blacksmith_upgrade_data.o(.rodata);
         src/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Link-communication regional data: text, tables, codes. */
        FILL(0x00);
        . = ABSOLUTE(0x08100EA0); src/link_communication_data.o(.rodata);
        . = ABSOLUTE(0x081014DC); src/cooking_recipe_inventory_page_data.o(.rodata);
         src/recovery_status.o(.rodata);
         src/cooking.o(.rodata);
         src/cooking_recipe_inventory_data.o(.rodata);
        src/animal.o(.rodata);
         src/livestock_day_update_data.o(.rodata);
         src/actor_state.o(.rodata);
        /* Fishing-record regional data: names, lookup, trailer. */
         src/fishing_results_data.o(.rodata);
        FILL(0x00);
         src/actor_runtime_data.o(.rodata);
         src/character_names_empty.o(.rodata);
         src/bachelorette.o(.rodata);
        /* Character-name regional data: names, lookup, trailer. */
         src/character_names_data.o(.rodata);
        FILL(0x00);
        src/field_item_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x08105390); src/calendar_events.o(.rodata);
         src/possessive_labels.o(.rodata);
         src/random_item_unavailable.o(.rodata);
         src/fishing_record_article_ids.o(.rodata);
        src/field_plot_position_values.o(.rodata);
         src/random_item_selection.o(.rodata);
        src/field_plot_position_rules.o(.rodata);
        src/time_of_day.o(.rodata);
         src/map_data.o(.rodata);
        src/field_render_rect_descriptors.o(.rodata);
         src/field_render_farm_house_data.o(.rodata);
        src/field_render_resource_data.o(.rodata);
        FILL(0x00);
         src/bachelorette_marriage_candidate_data.o(.rodata);
        src/field_render_runtime_data.o(.rodata);
        src/harvest_sprite.o(.rodata);
         src/reference_guide.o(.rodata.reference_guide);
         src/shop_common.o(.rodata);
         src/font.o(.rodata);
        . = ABSOLUTE(0x08119C54); asm/data/static_resources.o(.rodata);
        . = ABSOLUTE(0x0813BB08); src/m4a.o(.rodata);
        . = ABSOLUTE(0x0813BDE0); src/m4a.o(.rodata.gM4aVoiceGroups);
        . = ABSOLUTE(0x0813CC34); src/m4a.o(.rodata.gMusicPlayerTable);
        . = ALIGN(4); src/m4a.o(.rodata.gSongTable);
        /* SongEnt is eight bytes; use the actual table length, including unused slots. */
        _M4aNumSongs = ABSOLUTE((. - gSongTable) / 8);
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
        . = ABSOLUTE(0x084E2E74); data/scripts/scripts.o(.rodata.mary_scripts);
        . = ABSOLUTE(0x0871DDD4); asm/data/data_0813B288.o(.rodata.mary_scripts_tail);
        src/libsram.o(.rodata);
        asm/data/data_0813B288.o(.rodata.after_sram);
    } > ROM = 0xFF

    .iwram : ALIGN(4)
    {
        asm/code_iwram.o(.iwram);
        src/hardware_oam_state.o(.rodata);
        asm/code_iwram.o(.iwram.after_dimensions);
        src/iwram_sort.o(.text);
        asm/code_iwram.o(.iwram.after_sort);
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

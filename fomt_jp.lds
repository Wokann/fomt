/*
 * Harvest Moon: Friends of Mineral Town (JP, revision 0) ROM layout.
 *
 * This is a static linker script for the normal source/object build.  Its
 * ROM placements were verified against baserom_jp.gba before being recorded;
 * do not replace the object list with a whole-ROM incbin.
 */

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
        . = 0x000430; src/interrupt.o(.bss COMMON);
        . = 0x000490; /* end */
    } > IWRAM

    .text : ALIGN(4)
    {
        . = 0x0; /* JP ROM 0x08000000, independently matched */
        src/crt0.o(.rom_header);
        . = 0x18C; /* JP ROM 0x0800018C, independently matched */
        src/main.o(.text);
        . = 0x2E0; /* JP ROM 0x080002E0, independently matched */
        src/sram_proxy_1.o(.text);
        . = 0x4C4; /* JP ROM 0x080004C4, independently matched */
        src/interrupt.o(.text);
        . = 0x59C; /* JP ROM 0x0800059C, independently matched */
        src/new.o(.text);
        src/pure_virtual.o(.text);
        . = 0x63C; /* JP ROM 0x0800063C, independently matched */
        src/sram_proxy_2.o(.text.func_0800063C .text.func_08000640 .text.func_08000664);
        asm/sram_proxy_2.o(.text);
        src/sram_proxy_2.o(.text.func_080006E4 .text.func_08000714 .text.func_08000728);
        . = 0x7EC; /* JP ROM 0x080007EC, independently matched */
        src/scene.o(.text);
        . = 0x914; /* JP ROM 0x08000914, independently matched */
        src/intro_scene.o(.text.intro_scene_core_constructor);
        src/intro_scene.o(.text.intro_scene_core_run);
        src/intro_scene.o(.text.intro_scene_core_startup);
        asm/intro_scene.o(.text.intro_scene_core_after_startup);
        src/intro_scene.o(.text.intro_scene_core_sequence);
        asm/intro_scene.o(.text.intro_scene_core_after_sequence);
        src/intro_scene.o(.text.intro_scene_sprite_submission);
        src/intro_scene.o(.text);
        . = 0x37A8; /* JP ROM 0x080037A8, independently matched */
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
        . = 0x7130; /* JP ROM 0x08007130, independently matched */
        src/hardware.o(.text);
        . = 0x7374; /* JP ROM 0x08007374, independently matched */
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
        . = 0x9A50; /* JP ROM 0x08009A50, independently matched */
        src/farm.o(.text);
        . = 0x9F94; /* JP ROM 0x08009F94, independently matched */
        src/field.o(.text);
        . = 0xB0BC; /* JP ROM 0x0800B0BC, independently matched */
        src/shipping_bin.o(.text);
        . = 0xB2CC; /* JP ROM 0x0800B2CC, independently matched */
        src/tool_chest.o(.text);
        . = 0xB640; /* JP ROM 0x0800B640, independently matched */
        src/fridge.o(.text);
        . = 0xB8C4; /* JP ROM 0x0800B8C4, independently matched */
        src/shelf.o(.text);
        . = 0xBB40; /* JP ROM 0x0800BB40, independently matched */
        src/record_player.o(.text);
        . = 0xBC38; /* JP ROM 0x0800BC38, independently matched */
        src/code_0800BC58.o(.text);
        . = 0xBE50; /* JP ROM 0x0800BE50, independently matched */
        src/farm_house.o(.text);
        . = 0xC430; /* JP ROM 0x0800C430, independently matched */
        src/coop.o(.text);
        . = 0xCD9C; /* JP ROM 0x0800CD9C, independently matched */
        src/barn.o(.text);
        . = 0xDB0C; /* JP ROM 0x0800DB0C, independently matched */
        src/item.o(.text);
        . = 0xE2C4; /* JP ROM 0x0800E2C4, independently matched */
        src/time_of_day.o(.text.func_0800E2E4 .text.func_0800E304 .text.func_0800E324);
        . = 0xE334; /* JP ROM 0x0800E334, independently matched */
        src/farmer.o(.text);
        . = 0xEFCC; /* JP ROM 0x0800EFCC, independently matched */
        src/rucksack_item.o(.text);
        . = 0xF150; /* JP ROM 0x0800F150, independently matched */
        src/held_item.o(.text);
        . = 0xF554; /* JP ROM 0x0800F554, independently matched */
        src/rucksack.o(.text);
        . = 0xFF6C; /* JP ROM 0x0800FF6C, independently matched */
        src/more_items.o(.text);
        asm/more_items.o(.text);
        . = 0x1002C; /* JP ROM 0x0801002C, independently matched */
        asm/game_scene.o(.text);
        src/game_scene.o(.text.func_08010*);
        asm/game_scene.o(.text.game_scene_post);
        . = 0x10328; /* JP ROM 0x08010328, bounded by game_scene and entity */
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
        src/game_scene.o(.text.func_0801468C);
        asm/game_state.o(.text.game_scene_song_players_after);
        src/game_scene.o(.text.func_0801740C .text.func_0801746C .text.func_080174C8);
        asm/game_state.o(.text.game_scene_field_item_tool_after);
        src/game_scene.o(.text.func_08019F38 .text.GetWorldMapPixelWidth .text.GetWorldMapPixelHeight .text.GetWorldMapTerrain);
        asm/game_state.o(.text.game_scene_after_map_terrain);
        src/game_scene.o(.text.GetWorldTimeOfDayPeriod);
        asm/game_state.o(.text.game_scene_after_time_of_day_period);
        src/game_scene.o(.text.func_0801B5C0);
        asm/game_state.o(.text.game_scene_palette_resource_selector_after);
        src/game_scene.o(.text.TryGetFarmPlotAtLocation);
        asm/game_state.o(.text.game_scene_farm_plot_query_after);
        src/game_scene.o(.text.func_0801C29C);
        asm/game_state.o(.text.game_scene_farm_plot_action_after);
        src/game_scene.o(.text.func_0801D3FC .text.func_0801D4E0 .text.func_0801D5BC
            .text.PickUpFieldItemAtLocation .text.func_0801D7B0 .text.func_0801D88C
            .text.func_0801D8CC .text.func_0801D948 .text.func_0801D9A8
            .text.func_0801D9BC .text.func_0801DB44 .text.func_0801DB58
            .text.func_0801DC24 .text.func_0801DCA8 .text.CollectDailyShippingRevenue
            .text.func_0801DD18 .text.func_0801DD24 .text.func_0801DD30 .text.func_0801DD3C .text.func_0801DD48 .text.func_0801DD54 .text.func_0801DD60 .text.func_0801DD6C .text.func_0801DD78 .text.RemoveRecordPlayerAlbum
            .text.func_0801DDCC .text.func_0801DDF8 .text.func_0801DE24 .text.func_0801DE30 .text.func_0801DE3C .text.func_0801DE48
            .text.SwapRecordPlayerAlbum);
        asm/game_state.o(.text.game_scene_after_record_player_album);
        src/game_scene.o(.text.func_0801FB* .text.func_0801FC* .text.func_0801FD*);
        . = 0x1FB0C; /* JP ROM 0x0801FB0C, independently matched */
        src/entity.o(.text);
        . = 0x1FDAC; /* JP ROM 0x0801FDAC, independently matched */
        src/code_entity_08020018.o(.text);
        . = 0x1FDF4; /* JP ROM 0x0801FDF4, independently matched */
        asm/code_entities.o(.text);
        . = 0x31E70; /* JP ROM 0x08031E70, independently matched */
        src/entity_actor.o(.text);
        . = 0x321C0; /* JP ROM 0x080321C0, independently matched */
        asm/code_entities_080320DC.o(.text);
        . = 0x3224C; /* JP counterpart of default entity-UI false handler. */
        src/entity_ui.o(.text.entity_ui_default_no_action);
        . = 0x32250; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_default_no_action_after);
        . = 0x32694; /* JP counterpart of entity-UI coordinate classifier. */
        src/entity_ui.o(.text.entity_ui_region_classification);
        . = 0x326C8; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_region_classification_after);
        . = 0x32794; /* JP counterpart of entity-UI constructor. */
        src/entity_ui.o(.text.entity_ui_constructor);
        . = 0x327C4; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_constructor_after);
        . = 0x336A8; /* JP counterpart of Harvest Sprite task experience transform. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_task_experience);
        . = 0x336BC; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_harvest_sprite_task_experience_after);
        . = 0x338B8; /* JP counterpart of Harvest Sprite UI entry test. */
        src/entity_ui.o(.text.entity_ui_harvest_sprite_selection);
        . = 0x33910; /* JP counterpart of entity-UI byte-0x41 clearer. */
        src/entity_ui.o(.text.entity_ui_unknown_flag);
        . = 0x33918; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_unknown_flag_after);
        . = 0x33FDC; /* JP counterpart of entity-UI animation lookup. */
        src/entity_ui.o(.text.entity_ui_animation_lookup);
        . = 0x33FF4; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_animation_lookup_after);
        . = 0x34990; /* JP counterpart of entity-UI resource setup. */
        src/entity_ui.o(.text.entity_ui_resource_setup);
        . = 0x349D4; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_get_value_30);
        . = 0x349DC; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_get_pointer_10);
        . = 0x349E0; /* Continue the surrounding entity-UI ROM block. */
        src/entity_ui.o(.text.entity_ui_dispatch_value_30);
        . = 0x349F8; /* NPC schedule query and entity methods. */
        src/npc_entity.o(.text.func_08034C64 .text.*ANpcEntity* .text.func_08034E* .text.func_08034F00);
        . = 0x35114; /* JP ROM 0x08035114, independently matched */
        asm/code_entities_08034CEC.o(.text);
        src/npc_entity.o(.text.func_08035908 .text.func_08035940);
        asm/code_entities_08034CEC.o(.text.npc_schedule_transition_query);
        src/npc_entity.o(.text.func_08035A48 .text.func_08035AE0);
        asm/code_entities_08034CEC.o(.text.npc_characters_after);

        . = 0x3A518; /* JP ROM 0x0803A518, independently matched */

        asm/code_0803A8A4.o(.text);
        src/map_data.o(.text.SelectMapDataId);
        asm/code_0803A8A4.o(.text.world_sprite_groups_constructor);
        src/game_scene.o(.text._._21GameSceneWorldUnk1020);
        asm/code_0803A8A4.o(.text.world_sprite_groups_after_destructor);
        . = 0x3BB78; /* JP counterpart of US function 0x0803BDE4. */
        src/code_0803BDE4.o(.text);
        . = 0x3BB90; /* JP ROM 0x0803BDFC, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BDFC);
        . = 0x3BC30; /* JP counterpart of US function 0x0803BE9C. */
        src/code_0803BE9C.o(.text);
        . = 0x3BC44; /* JP counterparts of US functions 0x0803BEB0..0x0803BEC8. */
        src/code_0803BEB0.o(.text);
        . = 0x3BC68; /* JP counterparts of US functions 0x0803BED4/0x0803BEE0. */
        src/code_0803BED4.o(.text);
        . = 0x3BC80; /* JP counterparts of US functions 0x0803BEEC/0x0803BEF4. */
        src/code_0803BEEC.o(.text);
        . = 0x3BC90; /* JP counterparts of US functions 0x0803BEFC/0x0803BF08. */
        src/code_0803BEFC.o(.text);
        . = 0x3BCA8; /* JP ROM 0x0803BF14, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BF14);
        . = 0x3C2AC; /* JP counterparts of US functions 0x0803C518/0x0803C52C. */
        src/code_0803C518.o(.text);
        . = 0x3C2D4; /* JP counterparts of US functions 0x0803C540/0x0803C544. */
        src/code_0803C540.o(.text);
        . = 0x3C2E0; /* JP ROM 0x0803C54C, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803C54C);
        src/npc.o(.text.InitializeSchedule__3NpcRC12ScheduleInfoPCv);
        src/npc_collection.o(.text.InitializeSchedules__13NpcCollectionRC18GameStateSaveImage);
        asm/code_0803A8A4.o(.text.npc_schedule_after);
        . = 0x3E080; /* JP counterpart of shared schedule gate func_0803E40C. */
        src/code_0803E40C.o(.text);
        . = 0x3E0BC; /* JP ROM 0x0803E448, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803E448);
        . = 0x3EB08; /* JP ROM 0x0803EB08, independently matched */
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);
        . = 0x4E2D4; /* JP ordinary 2D glyph compositor. */
        asm/font_draw.o(.text.font_draw_normal);
        . = 0x4E3D4; /* JP extended palette glyph compositor. */
        asm/font_draw.o(.text.font_draw_ext);
        . = 0x4E5C8; /* Shared 2D tile-buffer fillers and Shift-JIS renderers. */
        src/font_draw.o(.text.Clear2DGfxBuffer);
        asm/font_draw.o(.text.font_draw_clear_rectangle);
        src/font_draw.o(.text.DrawStringTo2DGfxBuffer);
        src/font_draw.o(.text.DrawStringTo2DGfxBufferExt);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferUnaligned);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferExtUnaligned);
        . = 0x4E7F8; src/font_draw.o(.text.Copy2DGfxBuffer);
        src/font_draw.o(.text.Fill2DGfxTilemapRect);
        src/font_draw.o(.text.InitializeUnkFontDrawObject);
        src/font_draw.o(.text.DestroyUnkFontDrawObject);
        asm/code_0803EE94.o(.text.font_draw_after);
        src/font.o(.text.font_decimal);
        asm/code_0803EE94.o(.text.font_decimal_after);
        . = 0x50188; /* JP/US-shared nonzero UI-state setter. */
        src/ui_state.o(.text.set_ui_object_state_two_if_nonzero);
        . = 0x5019C; /* JP/US-shared nonzero UI-state clearer. */
        src/ui_state.o(.text.clear_ui_object_state_if_nonzero);
        . = 0x501B0; asm/code_0803EE94.o(.text.ui_object_state_after);
        . = 0x508C8; /* JP/US-shared UI action-state first-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01dc);
        . = 0x508DC; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01dc_after);
        . = 0x509A4; /* JP/US-shared UI action-state second-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01f0);
        . = 0x509B8; asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01f0_after);
        . = 0x50A4C; /* JP ROM contiguous UI owner and adapter block. */
        src/ui_state.o(.text.ui_state_adapters);
        asm/code_0803EE94.o(.text.code_08050E50);
        src/ui_state.o(.text);
        asm/code_0803EE94.o(.text.ui_state_helpers_after);
        src/ui_state.o(.text.ui_state_selection);
        asm/code_0803EE94.o(.text.ui_state_selection_after);
        src/animal_festival_ranking.o(.text);
        . = 0x52088; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E410; /* JP/US-shared indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E4A4; /* JP/US-shared indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E4D4; src/resource_handle.o(.text.indexed_resource_archive_get_group_data);
        . = 0x5E560; /* JP/US-shared indexed resource-archive group count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_group_descriptor_count);
        . = 0x5E564; /* JP/US-shared indexed resource-archive entry count. */
        src/resource_handle.o(.text.indexed_resource_archive_get_entry_descriptor_count);
        . = 0x5E568; /* JP/US-shared indexed resource-handle constructor. */
        src/resource_handle.o(.text.indexed_resource_handle_constructor);
        . = 0x5E594; /* JP/US-shared indexed resource-handle initializer. */
        src/resource_handle.o(.text.initialize_indexed_resource_handle);
        . = 0x5E5A4; /* JP/US-shared indexed resource-handle resolver. */
        src/resource_handle.o(.text.resolve_indexed_resource_handle);
        . = 0x5E5D8; src/resource_handle.o(.text.indexed_resource_handle_predict_wrap);
        asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
        src/resource_handle.o(.text.indexed_resource_sprite_transform);
        asm/code_0803EE94.o(.text.indexed_resource_sprite_transform_after);
        . = 0x75A14; /* JP/US-shared scroll-position reset. */
        src/scroll_state.o(.text.reset_scroll_position);
        . = 0x75A30; /* JP/US-shared scroll-buffer clear. */
        src/scroll_state.o(.text.clear_scroll_buffer);
        . = 0x75A48; asm/code_0803EE94.o(.text.clear_scroll_buffer_after);
        . = 0x76840; /* JP/US-shared selection-index state setter. */
        src/selection_state.o(.text.set_selection_index);
        . = 0x7684C; /* JP/US-shared selection-index state getter. */
        src/selection_state.o(.text.get_selection_index);
        . = 0x7685C; asm/code_0803EE94.o(.text.get_selection_index_after);
        . = 0x779BC; /* JP/US-shared 30x13 BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_30x13);
        . = 0x779EC; /* JP/US-shared rectangular BG map copier. */
        src/town_map_data.o(.text.copy_bg_map_rect);
        . = 0x77A48; asm/code_0803EE94.o(.text.copy_bg_map_rect_after);
        . = 0x77E4C; /* JP/US-shared town-map cursor hit test. */
        src/town_map_data.o(.text.town_map_hotspot_contains);
        . = 0x77E74; asm/code_0803EE94.o(.text.town_map_hotspot_contains_after);
        . = 0x78670; asm/code_0803EE94.o(.text.func_08078670);
        . = 0x786A0; asm/code_0803EE94.o(.text.func_080786A0);
        src/cooking_recipe_inventory_data.o(.text);
        asm/code_0803EE94.o(.text.cooking_recipe_inventory_after);
        src/money_account.o(.text.money_account_update);
        asm/code_0803EE94.o(.text.money_account_history);
        src/money_account.o(.text);

        . = 0x9AB3C; /* JP ROM 0x0809AB3C, independently matched */

        src/actor.o(.text);
        . = 0x9AB64; /* JP ROM 0x0809AB64, independently matched */
        src/animal.o(.text);
        . = 0x9AD64; /* JP ROM 0x0809AD64, independently matched */
        src/pet.o(.text);
        . = 0x9AE8C; /* JP ROM 0x0809AE8C, independently matched */
        src/livestock.o(.text);
        . = 0x9B260; /* JP ROM 0x0809B260, independently matched */
        src/barn_animal.o(.text);
        . = 0x9B40C; /* JP ROM 0x0809B40C, independently matched */
        src/dog.o(.text);
        . = 0x9B608; /* JP ROM 0x0809B608, independently matched */
        src/horse.o(.text);
        . = 0x9B69C; /* JP ROM 0x0809B69C, independently matched */
        src/chicken.o(.text);
        . = 0x9B780; /* JP ROM 0x0809B780, independently matched */
        src/cow.o(.text);
        . = 0x9B8CC; /* JP ROM 0x0809B8CC, independently matched */
        src/sheep.o(.text);
        . = 0x9BA20; /* JP ROM 0x0809BA20, independently matched */
        src/actor_runtime_data.o(.text);
        . = 0x9BB98; /* JP ROM 0x0809BB98, unlabelled raw helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C160);
        . = 0x9BC64; /* JP ROM 0x0809BC64, shared selector */
        src/code_actor_0809C22C.o(.text);
        . = 0x9BD3C; /* JP ROM 0x0809BD3C, shared table accessor */
        src/code_actor_0809C304.o(.text);
        . = 0x9BD50; /* JP ROM 0x0809BD50, raw actor helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C318);
        . = 0x9BD64; /* JP ROM 0x0809BD64, shared paired-state predicate */
        src/code_actor_0809C32C.o(.text);
        . = 0x9BDC4; /* JP ROM 0x0809BDC4, shared nonzero-state predicate */
        src/code_actor_0809C38C.o(.text);
        . = 0x9BDF4; /* JP ROM 0x0809BDF4, shared state initializer */
        src/code_actor_0809C3BC.o(.text);
        . = 0x9BE18; /* JP ROM 0x0809BE18, shared state advancement */
        src/actor_state.o(.text.func_0809C3E0);
        . = 0x9BE58; /* JP ROM 0x0809BE58, shared state reset */
        src/code_actor_0809C420.o(.text);
        . = 0x9BE7C; /* JP ROM 0x0809BE7C, shared conditional state advance */
        src/code_actor_0809C444.o(.text);
        . = 0x9BEAC; /* JP ROM 0x0809BEAC, shared state-update dispatcher */
        src/code_actor_0809C474.o(.text);
        . = 0x9BEEC; /* JP ROM 0x0809BEEC, shared state-update dispatcher */
        src/code_actor_0809C4B4.o(.text);
        . = 0x9BF1C; /* JP ROM 0x0809BF1C, shared word clear */
        src/code_actor_0809C4E4.o(.text);
        . = 0x9BF24; /* JP ROM 0x0809BF24, shared selection helper and raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C4EC);
        src/actor_state.o(.text.SelectMapFlagPatch);
        . = 0x9BFEC; /* JP ROM 0x0809BFEC, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C008; /* JP ROM 0x0809C008, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C024; /* JP ROM 0x0809C024, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C02C; /* Event-variable registrations, romance marker and packed save state. */
        src/event_state.o(.text);
        . = 0x9C7B0; /* Fishing-record storage and queries. */
        src/fishing_results_data.o(.text);
        . = 0x9C8C4; /* JP ROM 0x0809C8C4, remaining raw actor code */
        src/actor_state.o(.text.__14ActorStateGrid);
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CF34);
        . = 0x9CE50; /* JP ROM 0x0809D418, map a segmented input value */
        src/code_actor_0809D418.o(.text);
        . = 0x9CEA8; /* JP ROM 0x0809D470, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D470);
        . = 0x9D210; /* JP ROM 0x0809D7D8, classify actor-state value */
        src/code_actor_0809D7D8.o(.text);
        . = 0x9D2D8; /* JP ROM 0x0809D8A0, read state value */
        src/code_actor_0809D8A0.o(.text);
        . = 0x9D2DC; /* JP ROM 0x0809D8A4, map one state value */
        src/code_actor_0809D8A4.o(.text);
        . = 0x9D2F0; /* JP ROM 0x0809D8B8, map two state values */
        src/code_actor_0809D8B8.o(.text);
        . = 0x9D30C; /* JP ROM 0x0809D8D4, read packed grid-cell value */
        src/actor_state.o(.text.func_0809D8D4);
        . = 0x9D320; /* JP ROM 0x0809D8E8, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9D964; /* JP counterpart of US function 0x0809DF2C. */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9D9E4; /* JP ROM 0x0809DFAC, count actor-state flag bits */
        src/actor_state.o(.text.func_0809DFAC);
        . = 0x9DA64; /* JP ROM 0x0809E02C, count actor-state flag bits */
        src/actor_state.o(.text.func_0809E02C);
        . = 0x9DAE4; /* JP ROM 0x0809E0AC, select actor-state cell-type data */
        src/actor_state.o(.text.func_0809E0AC);
        . = 0x9DB50; /* JP ROM 0x0809E118, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9DBAC; /* JP ROM 0x0809E174, read actor-state bit 0 */
        src/actor_state.o(.text.func_0809E174);
        . = 0x9DBBC; /* JP ROM 0x0809E184, read actor-state bit 2 */
        src/actor_state.o(.text.func_0809E184);
        . = 0x9DBCC; /* JP ROM 0x0809E194, read actor-state bit 3 */
        src/actor_state.o(.text.func_0809E194);
        . = 0x9DBDC; /* JP ROM 0x0809E1A4, read actor-state bit 4 */
        src/actor_state.o(.text.func_0809E1A4);
        . = 0x9DBEC; /* JP ROM 0x0809E1B4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        . = 0x9DD0C; /* JP ROM 0x0809DD0C, independently matched */
        src/npc.o(.text .text.*);
        . = 0x9DE90; /* JP ROM 0x0809DE90, independently matched */
        src/bachelorette.o(.text);
        . = 0x9E060; /* JP ROM 0x0809E060, independently matched */
        src/harvest_sprite.o(.text .text.*__*);

        . = 0x9E3F0; /* Child constructors, birthday, age and walking state. */
        src/child.o(.text);
        . = 0x9E584; /* Gotz, Saibara and Van saved state. */
        src/gotz.o(.text);
        src/saibara.o(.text);
        src/van.o(.text);
        src/npc_collection.o(.text.__13NpcCollection);
        asm/code_809E804.o(.text.npc_after_child);
        src/npc_collection.o(.text.GetHarvestSpriteByIndex__C13NpcCollectionUi);
        asm/code_809E804.o(.text.npc_after_sprite_const_lookup);
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
        src/time_of_day.o(.text.GetTimeOfDayTransitionValue);
        . = 0xA40D0;
        src/map_data.o(.text.GetMapData);
        . = 0xA40E4;
        asm/code_809E804.o(.text.get_map_data_after);
        src/game_scene.o(.text._._19GameSceneSpriteBase);
        asm/code_809E804.o(.text.game_scene_sprite_base_after);
        src/game_scene.o(.text.__22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib);
        asm/code_809E804.o(.text.game_scene_indexed_sprite_after);
        src/game_scene.o(.text.UpdateWorldMap);
        asm/code_809E804.o(.text.game_map_after_update);
        src/game_scene.o(.text.func_080A58EC .text.func_080A5960 .text.func_080A59BC .text.func_080A5A9C);
        asm/code_809E804.o(.text.game_map_after_camera_query);
        src/game_scene.o(.text.ApplyMapTilePatch);
        src/game_scene.o(.text.LoadWorldMapTilemaps .text.SetWorldMapTimeOfDayPalette .text.LoadWorldMapTimeOfDayPalette);
        asm/code_809E804.o(.text.game_map_time_palette_after);
        src/game_scene.o(.text.LoadWorldMapTiles .text.func_080A5EB8);
        asm/code_809E804.o(.text.game_map_after_tiles);
        src/game_scene.o(.text.func_080A601C .text.RefreshCoopFeedTrough);
        asm/code_809E804.o(.text.game_map_barn_feed);
        src/game_scene.o(.text.func_080A6138 .text.func_080A6194 .text.func_080A61F0 .text.func_080A6234 .text.func_080A6278 .text.func_080A62BC .text.func_080A6300 .text.func_080A635C .text.func_080A63B8);
        src/game_scene.o(.text.SelectDefaultWorldMapData .text.GetWorldMapTileAttributes .text.GetWorldMapDataId .text.GetWorldMapId .text.GetWorldMapViewY .text.GetWorldMapViewX);
        asm/code_809E804.o(.text.game_map_after_patch_dispatchers);
        src/game_scene.o(.text.UpdateSavedMapTileAnimationTimers);
        src/game_scene.o(.text.DrawSavedWorldMap);
        src/game_scene.o(.text.ResetSavedMapTileAnimationFrames);
        asm/code_809E804.o(.text.game_map_after_animation_reset);
        src/game_scene.o(.text.RefreshFieldPlotTiles .text.func_080AA850 .text.func_080AA89C .text.func_080AA8BC .text.func_080AA8DC);
        asm/code_809E804.o(.text.game_map_after_flag_updates);
        src/map_data.o(.text.IsMapTerrainBoxBlocked);
        asm/code_809E804.o(.text.game_map_after_terrain_query);
        . = 0xD0558; /* Shift-JIS glyph-map index converter and renderer. */
        src/font.o(.text);
        . = 0xD0674; /* Remaining JP font support code. */
        asm/code_809E804.o(.text.font_after);

        . = 0xD0D4C; /* JP ROM 0x080D0D4C, independently matched */

        src/m4a_1.o(.text);
        . = 0xD1968; /* JP ROM 0x080D1968, independently matched */
        src/m4a.o(.text);
        . = 0xD2F00; /* JP ROM 0x080D2F00, independently matched */
        asm/code_lib_syscall.o(.text);
        . = 0xD2F30; /* JP ROM 0x080D2F30, independently matched */
        src/libsram.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        . = 0xD3100; /* JP ROM 0x080D3100, independently matched */
        src/libc_string.o(.text);

        . = 0xD3378; /* JP ROM 0x080D3378, independently matched */

        src/new.o(.text.new_retry);
        src/intro_scene.o(.text.intro_scene_transitions);
        *(.gnu.linkonce.t._._19IntroMenuTransition);
        *(.gnu.linkonce.t._._24IntroNameEntryTransition);
        asm/code_linkonce.o(.text.code_080D3C78);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        . = 0xD6078; /* JP ROM 0x080D6078, independently matched */
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
        src/hardware_manager.o(.text.hardware_manager_vblank_binding);
        asm/code_linkonce.o(.text.hardware_manager_vblank_after);
        *(.gnu.linkonce.t.__as__5SheepRC5Sheep);
        *(.gnu.linkonce.t.__as__3CowRC3Cow);
        *(.gnu.linkonce.t.__as__9LivestockRC9Livestock);
        *(.gnu.linkonce.t.push_back__Q28Rucksackt5Slots1Z12RucksackItemG12RucksackItem);
        *(.gnu.linkonce.t.push_front__Q28Rucksackt5Slots1Z12RucksackItemG12RucksackItem);
        *(.gnu.linkonce.t.push_back__Q28Rucksackt5Slots1Z9ToolStackG9ToolStack);
        *(.gnu.linkonce.t.push_front__Q28Rucksackt5Slots1Z9ToolStackG9ToolStack);
        . = 0xD761C; /* JP ROM 0x080D761C, direct function match */
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
        src/game_scene.o(.gnu.linkonce.t._._22GameSceneIndexedSprite);
        asm/code_linkonce.o(.text.game_scene_indexed_sprite_dtor_after);
        src/npc_entity.o(.text.FindTimedPathPointUpperBound);
        asm/code_linkonce.o(.text.npc_timed_path_search_after);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        . = 0xE0690; /* JP ROM 0x080E0690, independently matched */
        asm/code_linkonce.o(.text.code_080E0EF0);
        src/font.o(.text.font_unsigned_decimal);
        asm/code_linkonce.o(.text.code_080E0F48);
        src/harvest_sprite.o(.text.FindHarvestSpriteWorkTarget);
        asm/code_linkonce.o(.text.sprite_work_target_search_after);

    } > ROM = 0xFF

    .rodata : ALIGN(4)
    {
        . = ABSOLUTE(0x080E4E0C); /* JP C++ table region begins after code_linkonce. */
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
        . = ALIGN(4); src/game_scene.o(.gnu.linkonce.d.__vt_22GameSceneIndexedSprite);
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
. = ALIGN(4); src/vtables.o(.rodata.vtable_6f1c);
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
. = ALIGN(4); src/vtables.o(.rodata.vtable_6fac);
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
. = ALIGN(4); src/game_scene.o(.gnu.linkonce.d.__vt_19GameSceneSpriteBase);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82d4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82d8);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82e4);
. = ALIGN(4); src/vtables.o(.rodata.vtable_82fc);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_830c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_831c);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7774);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_8344);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7834);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_8404);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7870);
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

        /* Source-owned localization island; Mary script table is its upper bound. */
        . = ABSOLUTE(0x080E7A40);
        src/crt0_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/sram_proxy_1.o(.rodata);
        src/intro_scene_startup.o(.rodata);
        src/new_game_data.o(.rodata);
        src/field_data.o(.rodata);
        src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        /* Item text, catalogs, products, and trailer. */
        src/item.o(.rodata);
        /* Calendar rows, labels, and state data. */
        src/game_state.o(.rodata);
        FILL(0x00);
        /* Help-menu text and byte table. */
        src/help_menu.o(.rodata);
        FILL(0x00);
        /* Animal memorial text and animal data. */
        . = ALIGN(4); src/animal_data.o(.rodata);
        FILL(0x00);
        /* Entity UI labels and native UI data. */
        src/entity_ui.o(.rodata);
        FILL(0x00);
        /* Common UI labels, fallback text, menu data, and pointer table. */
        src/common_ui.o(.rodata);
        FILL(0x00);
        src/data_schedules.o(.rodata);
        /* Other NPC schedule records follow the individually declared schedules. */
        . = ALIGN(4); src/npc_schedule_data.o(.rodata);
        . = ABSOLUTE(0x080F8230); data/scripts/script_table.o(.rodata.mary_script_table);
        /* Source-owned localization island; raw static resources are its upper bound. */
        . = ABSOLUTE(0x080F96F4); src/script_engine.o(.rodata);
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
        FILL(0x00);
        src/animal_festival_ranking_score_data.o(.rodata);
        src/frisbee.o(.rodata);
        FILL(0x00);
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
        src/farm_status_screen_data.o(.rodata);
        FILL(0x00);
        src/records_screen_data.o(.rodata);
        . = ALIGN(4); src/staff_credits.o(.rodata);
        /* Town Map regional data: labels, hotspots, and lookup. */
        src/town_map_data.o(.rodata);
        src/library_opening_hours_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/town_map_area_data.o(.rodata);
        src/library_data.o(.rodata);
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
        src/blacksmith_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/carpenter_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0x00);
        src/livestock_shop.o(.rodata);
        FILL(0x00);
        src/home_storage.o(.rodata);
        FILL(0x00);
        src/blacksmith_upgrade_data.o(.rodata);
        src/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Link-communication regional data: text, tables, codes. */
        FILL(0x00);
        src/link_communication_data.o(.rodata);
        src/cooking_recipe_inventory_page_data.o(.rodata);
        src/recovery_status.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
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
        /* Character-name text, lookup table, and runtime trailer. */
        src/character_names_data.o(.rodata);
        FILL(0x00);
        src/field_item_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/calendar_events.o(.rodata);
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
        . = ABSOLUTE(0x08118D18); asm/data/static_resources.o(.rodata);
        . = ABSOLUTE(0x0813ABCC); src/m4a.o(.rodata);
        . = ABSOLUTE(0x0813AEA4); src/m4a.o(.rodata.gM4aVoiceGroups);
        . = ABSOLUTE(0x0813BCF8); src/m4a.o(.rodata.gMusicPlayerTable);
        src/m4a.o(.rodata.gSongTable);
        /* SongEnt is eight bytes; use the actual table length, including unused slots. */
        _M4aNumSongs = ABSOLUTE((. - gSongTable) / 8);
        . = ABSOLUTE(0x0813C3CC); /* JP asset container, independently matched. */
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
        . = ABSOLUTE(0x084E0CE0); data/scripts/scripts.o(.rodata.mary_scripts);
        . = ABSOLUTE(0x087515A8); asm/data/data_0813B288.o(.rodata.mary_scripts_tail);
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
        /* JP asset data ends at 0x0877FE58 after the IWRAM load image. */
        . = 0x000801A8;
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
        *(.gnu.linkonce.d.__vt_*)
        *(.gnu.linkonce.t._._*)
        *(*);
    }
}

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
        . = 0x000400; src/sram_proxy_2.o(.bss);
        . = 0x000404; src/hardware.o(.bss COMMON);
        . = 0x000408; src/hardware_refcount.o(.bss COMMON);
        . = 0x00040C; gUnk_0300040C = .;
        . = 0x000410; src/hardware_manager.o(.bss COMMON);
        . = 0x000414; gUnk_03000414 = .;
        . = 0x000418; src/heap.o(.bss COMMON);
        . = 0x00041C; src/joy_bus.o(.bss);
        . = 0x000430; src/interrupt.o(.bss COMMON);
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
        src/sram_proxy_2.o(.text);
        src/scene.o(.text);
        src/intro_scene.o(.text.intro_scene_core_constructor);
        src/intro_scene.o(.text.intro_scene_core_run);
        src/intro_scene.o(.text.intro_scene_core_startup);
        asm/intro_scene.o(.text.intro_scene_core_after_startup);
        src/intro_scene.o(.text.intro_scene_core_sequence);
        asm/intro_scene.o(.text.intro_scene_core_after_sequence);
        src/intro_scene.o(.text.intro_scene_sprite_submission);
        src/intro_scene.o(.text);
        asm/new_game_menu.o(.text);
        src/new_game_menu.o(.text);
        asm/new_game_menu.o(.text.new_game_menu_label_tiles);
        src/new_game_menu.o(.text.new_game_menu_update);
        asm/new_game_menu.o(.text.new_game_menu_core_run);
        src/new_game_menu.o(.text.new_game_menu_scene);
        src/new_game.o(.text.new_game_scene_lifecycle);
        src/new_game.o(.text.new_game_name_entry_workflow);
        asm/new_game_identity.o(.text.new_game_identity_core_constructor);
        src/new_game_identity.o(.text.new_game_identity_core_cleanup);
        src/new_game_identity.o(.text.new_game_identity_core_run);
        src/new_game_identity.o(.text.new_game_identity_core_initialization);
        asm/new_game_identity.o(.text.new_game_identity_screen);
        src/new_game_identity.o(.text.new_game_identity_core_update);
        src/new_game_identity.o(.text.new_game_identity_scene);
        src/new_game_name_input.o(.text.new_game_name_input_core_constructor);
        src/new_game_name_input.o(.text.new_game_name_input_core_cleanup);
        src/new_game_name_input.o(.text.new_game_name_input_core_run);
        asm/new_game_name_input.o(.text.new_game_name_input_after_core_run);
        src/new_game_name_input.o(.text.new_game_name_input_sprites);
        src/new_game_name_input.o(.text.new_game_name_input_reset);
        asm/new_game_name_input.o(.text.new_game_name_input_after_reset);
        src/new_game_name_input.o(.text.new_game_name_input_submit_sprites);
        src/new_game_name_input.o(.text.new_game_name_input_cursor_sprites);
        src/new_game_name_input.o(.text.new_game_name_input_keyboard_cursor);
        src/new_game_name_input.o(.text.new_game_name_input_insert_character);
        src/new_game_name_input.o(.text.new_game_name_input_erase_character);
        src/new_game_name_input.o(.text.new_game_name_input_normalization);
        src/new_game_name_input.o(.text.new_game_name_input_keys);
        src/new_game_name_input.o(.text.new_game_name_input_confirmation);
        src/new_game_name_input.o(.text.new_game_name_input_scene);
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
        src/hardware_display_output.o(.text.hardware_display_control_commands);
        src/hardware_bootstrap.o(.text.hardware_frame_update);
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
        src/farm.o(.text .text.__4FarmPCc .text.[A-Za-z]*);
        src/field.o(.text);
        src/shipping_bin.o(.text);
        src/tool_chest.o(.text);
        src/fridge.o(.text);
        src/shelf.o(.text);
        src/record_player.o(.text);
        src/furniture.o(.text);
        src/farm_house.o(.text);
        src/coop.o(.text);
        src/barn.o(.text);
        src/item.o(.text);
        src/time_of_day.o(.text.func_0800E2E4 .text.func_0800E304 .text.func_0800E324);
        src/farmer.o(.text .text.__6FarmerPCcRC8GameDate .text.__Q* .text.[A-Za-z]*);
        src/rucksack_item.o(.text);
        src/held_item.o(.text);
        src/rucksack.o(.text .text.__8Rucksack .text.[A-Za-z]*);
        src/more_items.o(.text);
        asm/more_items.o(.text);
        src/game_scene.o(.text.Run__25GameSceneScriptController);
        src/game_scene.o(
            .text.GetSceneActorRecords
            .text.GetSceneEventIconRecords
            .text.GetSceneScriptQueue0
            .text.GetScenePreservedPlayerLocation
            .text.func_08010138
            .text.func_08010148
            .text.GetSceneScriptEngine);
        src/game_scene.o(.text._._25GameSceneScriptController);
        src/game_scene.o(.text.__25GameSceneScriptControllerG23GameStateSaveImageOwner);
        src/game_scene.o(.text.__25GameSceneScriptControllerPCcT1G8GameDateT1);
        src/game_state.o(.text.GetNonzeroRandomValue .text.__18GameStateSaveImagePCcT1G8GameDateT1 .text.Get*__C18GameStateSaveImage .text.AllAnimalsHaveHighAffection__C18GameStateSaveImage .text.SetFlag[0-3]__18GameStateSaveImage);
        asm/game_state.o(.text.game_state_after_startup_accessors);
        src/game_state.o(.text.CollectShippingRevenue__18GameStateSaveImage .text.SetFlag4__18GameStateSaveImage .text.UpdateUnknown*__18GameStateSaveImageUi);
        src/game_state.o(.text.InitializeGameDisplayOptions);
        src/game_state.o(.text.__* .text.[A-Za-z]*);
        asm/game_state.o(.text.game_state_after_display_options);
        src/game_scene.o(.text.UpdateGameSceneHardwareFrame);
        src/game_scene.o(.text.__9GameSceneP18GameStateSaveImage*);
        src/game_scene.o(.text._._9GameScene);
        /* Entity location commands keep their native order across modules. */
        src/game_scene.o(.text.Run__9GameScene*);
        src/entity_location.o(.text.SetEntityPosition__9GameScene* .text.GetEntity*__9GameScene* .text.SetEntityFacing__9GameScene*);
        src/game_scene.o(.text.SetEntitySpritePriority__9GameScene*);
        src/entity_location.o(.text.MoveEntity*__9GameScene* .text.WaitForEntityMovement__9GameScene*);
        src/game_scene.o(
            .text.SetEntityA*__9GameScene* .text.WaitForCameraMovement__9GameScene*
            .text.NoOp*__9GameScene* .text.HideEntity__9GameScene* .text.OffsetEntityPosition__9GameScene*
            .text.StartEntityEffect__9GameScene* .text.StopEntityEffect__9GameSceneUi
            .text.ChangeMap__9GameScene* .text.PanCameraTo__9GameScene*);
        src/scene_audio.o(
            .text.PlayBGM__9GameScene* .text.StopBGM__9GameScene
            .text.PlaySong__9GameScene* .text.StopAllSongs__9GameScene);
        asm/game_state.o(.text.game_scene_entity_commands_after);
        src/game_scene.o(
            .text.Talk*__9GameScene* .text.FadeScreen__9GameScene*
            .text.TextVariable*__9GameScene* .text.CallScript__9GameScene*
            .text.QueueScript__9GameScene* .text.WaitFrames__9GameScene*);
        asm/game_state.o(.text.game_scene_text_variable_commands_after);
        src/game_scene.o(
            .text.PrepareClockMenuTransition__9GameScene
            .text.RestoreAfterClockMenu__9GameScene
            .text.PrepareCookingMenuTransition__9GameScene
            .text.RestoreAfterCookingMenu__9GameScene
            .text.PrepareRecipeMenuTransition__9GameScene
            .text.RestoreAfterRecipeMenu__9GameScene
            .text.RefreshBarnFeedTrough__9GameScene23MaryBarnFeedTroughIndex
            .text.RefreshChickenFeedTrough__9GameScene30MaryChickenCoopFeedTroughIndex
            .text.StartShipmentBoxDepositAnimation__9GameScene
            .text.IsPlayerRidingHorse__9GameScene
            .text.TryShipPlayerHeldItem__9GameScene
            .text.SetPlayerHeldItem__9GameSceneRC12RucksackItemb
            .text.GivePlayerBasket__9GameScene
            .text.ThrowPlayerHeldItem__9GameScene
            .text.UsePlayerHeldItem__9GameScene
            .text.ClearPlayerHeldItem__9GameScene
            .text.RemoveRecordPlayerAlbum__9GameScene
            .text.SwapRecordPlayerAlbum__9GameScene17MaryItemArticleId
            .text.SetEntityEventScript__9GameSceneUii
            .text.ClearEntityEventScript__9GameSceneUi
            .text.SetTelevisionProgram__9GameScene23MaryTelevisionProgramId
            .text.EndTelevisionProgram__9GameScene
            .text.EnableScriptedNpcControl__9GameScene
            .text.DisableScriptedNpcControl__9GameScene);
        asm/game_state.o(.text.game_scene_menu_hooks_after);
        src/scene_audio.o(.text.GetSceneSongPlayerPool);
        src/game_scene.o(
            .text.LightFireplaceAtLocation__9GameScene9MaryMapId
            .text.SetVaseArticleId__9GameScene17MaryItemArticleId
            .text.BeginEggIncubation__9GameScene29MaryChickenCoopIncubatorIndex);
        asm/game_state.o(.text.game_scene_song_players_after);
        src/game_scene.o(
            .text.RefreshAllNpcSchedules__9GameScene
            .text.ChangePlayerStaminaAndFatigue__9GameSceneii
            .text.CreateFarmHorse__9GameScene8MaryBool23MaryAnimalHorseAgeStage9MaryMapIdii
            .text.RemoveFarmHorse__9GameScene8MaryBooli
            .text.GetInteractingAnimalIndex__9GameScene
            .text.IsPlayerHoldingTool__9GameScene);
        asm/game_state.o(.text.game_scene_after_actor_commands);
        src/game_scene.o(
            .text.BeginHoldingActorGraphic__9GameScene15MaryAnimationId
            .text.ObtainPowerBerry__9GameScene
            .text.ObtainMysticBerry__9GameScene
            .text.IsHarvestSpriteDailyWorkComplete__9GameScene15MaryCharacterId
            .text.GetPresentedItemKind__9GameScene
            .text.GetPresentedItemId__9GameScene
            .text.IsPresentedItemGiftWrapped__9GameScene);
        asm/game_state.o(.text.game_scene_after_player_presentation);
        src/scene_audio.o(.text.StartWorldBackgroundMusic__9GameScene .text.FadeOutBackgroundMusic__9GameScene);
        src/game_scene.o(.text.GetCaughtFish__9GameScene);
        src/scene_audio.o(.text.IsBackgroundMusicActive__9GameScene);
        src/game_scene.o(
            .text.CreatePlayerChildEntity__9GameScene
            .text.SetContestAnimal__9GameScene14MaryAnimalKind19MaryAnimalSlotIndex);
        asm/game_state.o(.text.game_scene_after_contest_registration);
        src/game_scene.o(
            .text.OpenDoor__9GameScene13MaryDoorIndex
            .text.CloseDoor__9GameScene13MaryDoorIndex
            .text.RedrawRucksackShelfAfterPurchase__9GameScene
            .text.RedrawBlueFeatherShelfAfterPurchase__9GameScene
            .text.func_08016C10__9GameScene
            .text.CreateNewYearSunriseEffect__9GameScene
            .text.PlayNewYearSunriseEffect__9GameScene
            .text.DestroyNewYearSunriseEffect__9GameScene
            .text.PlayStarSparkleEffect__9GameScene
            .text.EnterHotSpringBathingState__9GameScene
            .text.ExitHotSpringBathingState__9GameScene
            .text.RefreshEntity__9GameScene12MaryEntityId);
        src/game_scene.o(
            .text.RemoveEntity__9GameScene12MaryEntityId
            .text.PreservePlayerLocationForNextDay__9GameScene
            .text.ClearPreservedPlayerLocation__9GameScene
            .text.GetPreservedPlayerMapId__9GameScene);
        src/game_scene.o(
            .text.EatRandomMeal__9GameScene
            .text.PreparePlayerForScriptedAnimation__9GameScene
            .text.RestorePlayerAfterScriptedAnimation__9GameScene);
        src/game_scene.o(
            .text.CreateEventIcon__9GameScene17MaryEventIconSlotii18MaryEventIconLayeri
            .text.RemoveEventIcon__9GameScene17MaryEventIconSlot);
        src/game_scene.o(
            .text.SetPlayerActorUpdateSuspended__9GameScene8MaryBool
            .text.ShowPlayerHoldingTool__9GameScene14MaryItemToolId);
        src/game_scene.o(.text.CureAllSickLivestock__9GameScene);
        src/entity_location.o(.text.RelocateEntityToMap__9GameSceneiUiiiUi);
        asm/farm_terrain.o(.text);
        src/farm_terrain.o(.text);
        src/game_world.o(.text.func_0801740C .text.func_0801746C .text.func_080174C8);
        asm/game_state.o(.text.game_scene_field_item_tool_after);
        src/world_control.o(.text.IsWorldTimePaused);
        asm/game_state.o(.text.world_update_after_pause_query);
        src/world_lighting.o(.text.RefreshWorldMapTimeOfDayPalette);
        asm/game_state.o(.text.world_after_palette_refresh);
        src/game_world.o(.text.func_08019F38 .text.GetWorldMapPixelWidth .text.GetWorldMapPixelHeight .text.GetWorldMapTerrain);
        asm/game_state.o(.text.game_scene_after_map_terrain);
        src/world_lighting.o(.text.GetWorldTimeOfDayPeriod);
        asm/game_state.o(.text.game_scene_after_time_of_day_period);
        src/game_world.o(.text.func_0801B5C0);
        asm/game_state.o(.text.game_scene_palette_resource_selector_after);
        src/game_world.o(.text.TryGetFarmPlotAtLocation);
        asm/game_state.o(.text.game_scene_farm_plot_query_after);
        src/game_world.o(.text.func_0801C29C);
        asm/game_state.o(.text.game_scene_farm_plot_action_after);
        src/game_world.o(.text.func_0801D3FC .text.func_0801D4E0 .text.func_0801D5BC
            .text.PickUpFieldItemAtLocation .text.func_0801D7B0 .text.func_0801D88C);
        src/world_control.o(.text.SuspendWorldUpdates .text.ResumeWorldUpdates);
        src/game_world.o(.text.QueueWorldScript);
        src/world_audio.o(.text.SelectWorldBackgroundAudio .text.GetWorldSongPlayerPool
            .text.UpdateWorldBackgroundAudio);
        src/game_world.o(.text.func_0801DC24 .text.func_0801DCA8 .text.CollectDailyShippingRevenue
            .text.func_0801DD18 .text.func_0801DD24 .text.func_0801DD30 .text.func_0801DD3C .text.func_0801DD48 .text.func_0801DD54 .text.func_0801DD60 .text.func_0801DD6C .text.func_0801DD78 .text.RemoveRecordPlayerAlbum
            .text.func_0801DDCC .text.func_0801DDF8 .text.func_0801DE24 .text.func_0801DE30 .text.func_0801DE3C .text.func_0801DE48
            .text.SwapRecordPlayerAlbum);
        asm/game_state.o(.text.game_scene_after_record_player_album);
        src/game_world.o(
            .text.func_0801FBDC
            .text.func_0801FBE8
            .text.func_0801FBF4
            .text.func_0801FC00
            .text.func_0801FC0C
            .text.func_0801FC18
            .text.func_0801FC24
            .text.func_0801FC30
            .text.func_0801FC3C
            .text.func_0801FC48
            .text.func_0801FC54
            .text.func_0801FC60
            .text.GetWorldActorAnimationArchive
            .text.func_0801FC78
            .text.func_0801FC9C
            .text.func_0801FCA0
            .text.GetWorldClock);
        src/world_runtime.o(.text.GetWorldSpritePaletteBank .text.ClearWorldSpritePaletteResourceFlag);
        src/game_world.o(
            .text.GetEntity__C20GameSceneWorldPrefixUi
            .text.GetEntity__20GameSceneWorldPrefixUi
            .text.RemoveWorldEntity
            .text.func_0801FD30
            .text.IsWorldCameraMovementComplete
            .text.GetWorldCameraY
            .text.GetWorldCameraX
            .text.GetWorldCurrentMapId
            .text.PanWorldCameraTo
            .text.SetWorldCameraPosition);
        src/entity.o(.text);
        src/code_entity_08020018.o(.text);
        src/entity_actor.o(.text.entity_actor_movement);
        asm/code_entities.o(.text.entity_actor_sound);
        src/entity_actor.o(.text.entity_actor_animation_complete .text.entity_actor_apply_movement);
        asm/code_entities.o(.text);
        src/livestock_actor.o(.text.IsSick__C12ChickenActor);
        asm/code_entities.o(.text.livestock_actor_chicken_after_sick_check);
        src/livestock_actor.o(.text.CureSickness__12ChickenActor);
        asm/code_entities.o(.text.livestock_actor_chicken_after_cure);
        src/livestock_actor.o(.text.IsSick__C8CowActor);
        asm/code_entities.o(.text.livestock_actor_cow_after_sick_check);
        src/livestock_actor.o(.text.CureSickness__8CowActor);
        asm/code_entities.o(.text.livestock_actor_cow_after_cure);
        src/livestock_actor.o(.text.IsSick__C10SheepActor);
        asm/code_entities.o(.text.livestock_actor_sheep_after_sick_check);
        src/livestock_actor.o(.text.CureSickness__10SheepActor);
        asm/code_entities.o(.text.livestock_actor_sheep_after_cure);
        src/player_actor.o(.text);
        asm/code_entities.o(.text.player_actor_update_state_after);
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
        . = 0x34C64; /* NPC schedule query and entity methods. */
        src/npc_entity.o(.text.func_08034C64 .text.*ANpcEntity* .text.func_08034E* .text.func_08034F00);
        asm/code_entities_08034CEC.o(.text);
        src/npc_entity.o(.text.func_08035908 .text.func_08035940);
        asm/code_entities_08034CEC.o(.text.npc_schedule_transition_query);
        src/npc_entity.o(.text.func_08035A48 .text.func_08035AE0);
        asm/code_entities_08034CEC.o(.text.npc_characters_after);
        src/entity_event_effects.o(.text.CreateEntityNewYearSunriseEffect .text.PlayEntityNewYearSunriseEffect .text.IsEntityNewYearSunriseEffectComplete .text.DestroyEntityNewYearSunriseEffect .text.PlayEntityStarSparkleEffect .text.HasEntityStarSparkleEffect);
        asm/code_entities_08034CEC.o(.text.entity_event_effects_after);
        src/entity_event_effects.o(.text.CreateControllerNewYearSunriseEffect .text.PlayControllerNewYearSunriseEffect .text.IsControllerNewYearSunriseEffectComplete .text.DestroyControllerNewYearSunriseEffect);
        asm/code_entities_08034CEC.o(.text.entity_event_effects_after_sunrise);

        src/map_data.o(.text.SelectMapDataId);
        asm/code_0803A8A4.o(.text.world_sprite_groups_constructor);
        src/world_runtime.o(.text._._21GameSceneWorldUnk1020);
        asm/code_0803A8A4.o(.text.world_sprite_groups_after_destructor);
        . = 0x3BDE4; /* US ROM 0x0803BDE4, set a u16 pair */
        src/code_0803BDE4.o(.text);
        . = 0x3BDFC; /* US ROM 0x0803BDFC, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BDFC);
        . = 0x3BE9C; /* US ROM 0x0803BE9C, unpack a packed value */
        src/code_0803BE9C.o(.text);

        . = 0x3BEB0; /* Shared control callbacks, in ROM order. */
        src/control_widget.o(.text);
        . = 0x3BF14; /* US ROM 0x0803BF14, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BF14);
        . = 0x3C518; /* US ROM 0x0803C518, activate control bytes */
        src/code_0803C518.o(.text);
        . = 0x3C540; /* US ROM 0x0803C540, read and clear control bytes */
        src/code_0803C540.o(.text);
        . = 0x3C54C; /* US ROM 0x0803C54C, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803C54C);
        src/map_clock_status.o(.text.__24MapClockStatusHudContent .text._._24MapClockStatusHudContent .text.DrawMapClockStatusHud);
        asm/code_0803A8A4.o(.text.map_clock_status_calendar);
        src/map_clock_status.o(.text.SetMapClockStatusHud* .text.ClearMapClockStatusHud*);
        src/map_clock_status.o(.text.*MapClockStatusWidget*);
        asm/code_0803A8A4.o(.text.farming_calendar_helpers);
        src/npc.o(.text.InitializeSchedule__3NpcRC12ScheduleInfoPCv);
        src/npc_collection.o(.text.InitializeSchedules__13NpcCollectionRC18GameStateSaveImage);
        asm/code_0803A8A4.o(.text.npc_schedule_after);
        . = 0x3E40C; /* US ROM shared Lou/Ruby Sunday schedule gate. */
        src/code_0803E40C.o(.text);
        . = 0x3E448; /* US ROM 0x0803E448, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803E448);
        src/script_engine.o(.text);
        asm/code_0803EE94.o(.text);
        . = 0x4E4AC; /* Ordinary 2D glyph compositor. */
        asm/font_draw.o(.text.font_draw_normal);
        . = 0x4E5AC; /* Extended palette glyph compositor. */
        asm/font_draw.o(.text.font_draw_ext);
        . = 0x4E7A0; /* Shared 2D tile-buffer fillers and Shift-JIS renderers. */
        src/font_draw.o(.text.Clear2DGfxBuffer);
        asm/font_draw.o(.text.font_draw_clear_rectangle);
        src/font_draw.o(.text.DrawStringTo2DGfxBuffer);
        src/font_draw.o(.text.DrawStringTo2DGfxBufferExt);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferUnaligned);
        src/font_draw.o(.text.DrawCharacterGlyphTo2DGfxBufferExtUnaligned);
        . = 0x4E9D0; src/font_draw.o(.text.Copy2DGfxBuffer);
        src/font_draw.o(.text.Fill2DGfxTilemapRect);
        src/font_draw.o(.text.__22FontTilemapRectCommandPUsUsUiUiUsUi);
        src/font_draw.o(.text._._22FontTilemapRectCommand);
        asm/code_0803EE94.o(.text.font_draw_after);
        src/font.o(.text.font_decimal);
        src/font_draw.o(.text.Run__22FontTilemapRectCommand);
        src/ui_state.o(.text.ui_text_tile_copy);
        src/ui_state.o(.text.ui_text_output_callbacks);
        src/ui_state.o(.text.ui_text_input_callbacks);
        src/ui_state.o(.text.ui_text_window_setup);
        asm/code_0803EE94.o(.text.ui_text_window_setup_after);
        src/ui_state.o(.text.ui_payload_destructor);
        asm/code_0803EE94.o(.text.ui_payload_destructor_after);
        src/ui_state.o(.text.ui_payload_open);
        . = 0x503FC; /* JP/US-shared nonzero UI-state setter. */
        src/ui_state.o(.text.set_ui_object_state_two_if_nonzero);
        . = 0x50410; /* JP/US-shared nonzero UI-state clearer. */
        src/ui_state.o(.text.clear_ui_object_state_if_nonzero);
        src/ui_state.o(.text.ui_payload_text);
        src/ui_state.o(.text.ui_payload_choices);
        src/ui_state.o(.text.ui_choice_labels);
        asm/code_0803EE94.o(.text.ui_choice_labels_after);
        . = 0x50B3C; /* JP/US-shared UI action-state first-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01dc);
        src/ui_state.o(.text.ui_nameplate);
        . = 0x50C18; /* JP/US-shared UI action-state second-flag clearer. */
        src/ui_state.o(.text.clear_ui_action_state_flag_01f0);
        src/ui_state.o(.text.ui_heart_indicator);
        asm/code_0803EE94.o(.text.clear_ui_action_state_flag_01f0_after);
        . = 0x50CC0; /* US ROM contiguous UI owner and adapter block. */
        src/ui_state.o(.text.ui_state_adapters);
        asm/code_0803EE94.o(.text.code_08050E50);
        src/ui_state.o(.text.__18UiTextInputAdapterRCUiUc .text.func_08050F70 .text.func_08050F74);
        asm/code_0803EE94.o(.text.ui_state_helpers_after);
        src/ui_state.o(.text.ui_state_selection);
        asm/code_0803EE94.o(.text.ui_state_selection_after);
        src/animal_festival_ranking.o(.text);
        . = 0x522F8; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E6CC; /* JP/US-shared indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E760; /* JP/US-shared indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E790; src/resource_handle.o(.text.indexed_resource_archive_get_group_data);
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
        . = 0x5E894; src/resource_handle.o(.text.indexed_resource_handle_predict_wrap);
        asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
        src/resource_handle.o(.text.indexed_resource_sprite_transform);
        src/intro_story_scene.o(.text.InitializeIntroStorySceneCore);
        asm/intro_story_scene.o(.text);
        src/intro_story_scene.o(.text.UpdateIntroStoryUi);
        asm/intro_story_scene.o(.text.intro_story_graphics);
        src/intro_story_scene.o(.text.__15IntroStorySceneRP15SceneTransitionP18GameStateSaveImage .text._._15IntroStoryScene .text.Run__15IntroStoryScene);
        asm/code_0803EE94.o(.text.intro_story_scene_after);
        src/new_game.o(.text.new_game_birthday_core);
        asm/code_0803EE94.o(.text.new_game_birthday_core_after);
        src/new_game.o(.text.new_game_birthday_ui);
        src/new_game.o(.text.new_game_birthday_navigation);
        asm/code_0803EE94.o(.text.new_game_birthday_navigation_after);
        src/new_game.o(.text.new_game_birthday_selection);
        asm/code_0803EE94.o(.text.new_game_birthday_selection_after);
        src/new_game.o(.text.new_game_birthday_cursor_setup);
        src/new_game.o(.text.new_game_birthday_glyph_layout);
        src/new_game.o(.text.new_game_birthday_glyph_append);
        src/new_game.o(.text.new_game_birthday_sprite_render);
        src/new_game.o(.text.new_game_birthday_input_scene);
        asm/code_0803EE94.o(.text.new_game_birthday_input_after);
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
        src/game_scene.o(.text.Run__18ReferencePageScene);
        asm/code_0803EE94.o(.text.after_reference_page_scene_run);
        src/game_scene.o(.text.Run__20PoultryFarmShopScene);
        asm/code_0803EE94.o(.text.after_poultry_farm_shop_scene_run);
        src/game_scene.o(.text.Run__16SupermarketScene);
        asm/code_0803EE94.o(.text.after_supermarket_scene_run);
        src/game_scene.o(.text.Run__24SupermarketPurchaseScene);
        asm/code_0803EE94.o(.text.after_supermarket_purchase_scene_run);
        src/game_scene.o(.text.Run__15ClinicShopScene);
        asm/code_0803EE94.o(.text.after_clinic_shop_scene_run);
        src/game_scene.o(.text.Run__12InnShopScene);
        asm/code_0803EE94.o(.text.after_inn_shop_scene_run);
        src/game_scene.o(.text.Run__12WonShopScene);
        asm/code_0803EE94.o(.text.after_won_shop_scene_run);
        src/game_scene.o(.text.Run__15WineryShopScene);
        asm/code_0803EE94.o(.text.after_winery_shop_scene_run);
        src/game_scene.o(.text.Run__24SpecialMerchantShopScene);
        asm/code_0803EE94.o(.text.after_special_merchant_shop_scene_run);
        src/game_scene.o(.text.Run__18BeachCafeShopScene);
        asm/code_0803EE94.o(.text.after_beach_cafe_shop_scene_run);
        src/game_scene.o(.text.Run__19BlacksmithShopScene);
        asm/code_0803EE94.o(.text.after_blacksmith_shop_scene_run);
        src/game_scene.o(.text.Run__18CarpenterShopScene);
        asm/code_0803EE94.o(.text.after_carpenter_shop_scene_run);
        src/game_scene.o(.text.Run__19YodelRanchShopScene);
        asm/code_0803EE94.o(.text.after_yodel_ranch_shop_scene_run);
        src/game_scene.o(.text.Run__14ToolChestScene);
        asm/code_0803EE94.o(.text.after_tool_chest_scene_run);
        src/game_scene.o(.text.Run__17RefrigeratorScene);
        asm/code_0803EE94.o(.text.after_refrigerator_scene_run);
        src/game_scene.o(.text.Run__10ShelfScene);
        asm/code_0803EE94.o(.text.after_shelf_scene_run);
        src/game_scene.o(.text.__25BlacksmithShopResultSceneG20SceneTransitionOwnerP18GameStateSaveImageUc .text._._25BlacksmithShopResultScene .text.Run__25BlacksmithShopResultScene);
        asm/code_0803EE94.o(.text.after_blacksmith_shop_result_scene);
        src/game_scene.o(.text.Run__17GiftWrappingScene);
        asm/code_0803EE94.o(.text.after_gift_wrapping_scene_run);
        src/game_scene.o(.text.Run__12CookingScene);
        asm/code_0803EE94.o(.text.after_cooking_scene_run);
        src/cooking_recipe_inventory.o(.text);
        src/money_account.o(.text.money_account_update);
        asm/code_0803EE94.o(.text.money_account_history);
        src/money_account.o(.text .text.__12MoneyAccount .text.[A-Za-z]*);

        src/actor.o(.text);
        src/animal.o(.text);
        src/pet.o(.text);
        src/livestock.o(.text);
        src/barn_animal.o(.text);
        src/dog.o(.text .text.__3Dog* .text.[A-Za-z]*);
        src/horse.o(.text);
        src/chicken.o(.text);
        src/cow.o(.text);
        src/sheep.o(.text);
        . = 0x9BFE8; /* US ROM 0x0809BFE8, independently matched */
        src/actor_runtime_data.o(.text);
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
        src/actor_state.o(.text.func_0809C3E0);
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
        src/actor_state.o(.text.SelectMapFlagPatch);
        . = 0x9C5B4; /* US ROM 0x0809C5B4, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C5D0; /* US ROM 0x0809C5D0, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C5EC; /* US ROM 0x0809C5EC, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C5F4; /* Event-variable registrations, romance marker and packed save state. */
        src/event_state.o(.text);
        . = 0x9CD78; /* Fishing-record storage and queries. */
        src/fishing_results_data.o(.text);
        . = 0x9CE8C; /* US ROM 0x0809CE8C, remaining raw actor code */
        src/actor_state.o(.text.__14ActorStateGrid);
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CF34);
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
        src/actor_state.o(.text.func_0809D8D4);
        . = 0x9D8E8; /* US ROM 0x0809D8E8, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9DF2C; /* US ROM 0x0809DF2C, query tool availability by group */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9DFAC; /* US ROM 0x0809DFAC, count actor-state flag bits */
        src/actor_state.o(.text.func_0809DFAC);
        . = 0x9E02C; /* US ROM 0x0809E02C, count actor-state flag bits */
        src/actor_state.o(.text.func_0809E02C);
        . = 0x9E0AC; /* US ROM 0x0809E0AC, select actor-state cell-type data */
        src/actor_state.o(.text.func_0809E0AC);
        . = 0x9E118; /* US ROM 0x0809E118, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9E174; /* US ROM 0x0809E174, read actor-state bit 0 */
        src/actor_state.o(.text.func_0809E174);
        . = 0x9E184; /* US ROM 0x0809E184, read actor-state bit 2 */
        src/actor_state.o(.text.func_0809E184);
        . = 0x9E194; /* US ROM 0x0809E194, read actor-state bit 3 */
        src/actor_state.o(.text.func_0809E194);
        . = 0x9E1A4; /* US ROM 0x0809E1A4, read actor-state bit 4 */
        src/actor_state.o(.text.func_0809E1A4);
        . = 0x9E1B4; /* US ROM 0x0809E1B4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        src/npc.o(.text .text.*);
        src/bachelorette.o(.text);
        src/harvest_sprite.o(.text .text.*__*);

        . = 0x9E9B8; /* Child constructors, birthday, age and walking state. */
        src/child.o(.text);
        . = 0x9EB4C; /* Gotz, Saibara and Van saved state. */
        src/gotz.o(.text);
        src/saibara.o(.text);
        src/van.o(.text);
        src/npc_collection.o(.text.__13NpcCollection);
        asm/code_809E804.o(.text.npc_after_child);
        src/npc_collection.o(.text.GetPartnerCharacterId__C13NpcCollection .text.GetSpouseCharacterId__C13NpcCollection .text.IsMarried__C13NpcCollection);
        asm/code_809E804.o(.text.npc_after_partner_queries);
        src/npc_collection.o(.text.GetNpc__13NpcCollectionUi .text.GetBachelorette__13NpcCollectionUi .text.GetHarvestSpriteByCharacterId__13NpcCollectionUi .text.GetHarvestSpriteByIndex__13NpcCollectionUi);
        src/npc_collection.o(.text.GetChild__13NpcCollection);
        src/npc_collection.o(.text.AddUnk00_0__13NpcCollectionUi .text.AddUnk00_6__13NpcCollectionUi .text.RecordLibrarySecondFloorVisit__13NpcCollection .text.GetSouthTownNpcLocation1__13NpcCollectionUi .text.GetSouthTownNpcLocation2__13NpcCollectionUi .text.GetYodelRanchHouseNpcLocation__13NpcCollection .text.GetInnSecondFloorNpcLocation__13NpcCollection);
        src/npc_collection.o(.text.DayUpdate__13NpcCollectionRC14GameStateClockRC14GameEventStateRC6FarmerRC4Farm);
        src/npc_collection.o(.text.SetWeddingDate__13NpcCollectionRC11WeddingDate .text.GetWeddingDate__C13NpcCollection);
        asm/code_809E804.o(.text.npc_after_wedding_date);
        src/npc_locations.o(.text);
        src/field_item_data.o(.text);
        asm/code_809E804.o(.text.field_item_after);
        src/game_scene.o(.text.Run__13CalendarScene);
        asm/code_809E804.o(.text.after_calendar_scene_run);
        src/game_scene.o(.text.Run__19SavedNameEntryScene .text.__19SavedNameEntrySceneG20SceneTransitionOwnerP18GameStateSaveImage17MaryNameEntryKindUc);
        asm/code_809E804.o(.text.after_saved_name_scene);
        src/time_of_day.o(.text.GetTimeOfDayTransitionValue);
        . = 0xA4698;
        src/map_data.o(.text.GetMapData);
        . = 0xA46AC;
        src/scene_sprite.o(
            .text.__19GameSceneSpriteBaseP10GameObjectUiPCiUi
            .text.__19GameSceneSpriteBaseP10GameObjectUii
            .text._._19GameSceneSpriteBase
            .text.QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC32IndexedResourceDescriptor32Range
            .text.UploadPalettes__19GameSceneSpriteBaseRC32IndexedResourceDescriptor32RangeUc
            .text.__22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiPCiUib
            .text.__22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
            .text.Submit__C19GameSceneSpriteBaseP21WorldSpriteDrawBufferiiUiUiRC26IndexedResourceSpriteRangeP10GameObject
        );
        src/world_map.o(.text.__17GameSceneWorldMap .text._._17GameSceneWorldMap);
        src/world_map.o(.text.Update__17GameSceneWorldMap);
        asm/code_809E804.o(.text.game_map_after_update);
        src/world_map.o(
            .text.Run__25MapViewportTilemapCommand
            .text.SetLocation__17GameSceneWorldMapRC8LocationiUiUi
            .text.RefreshAppearance__17GameSceneWorldMapiUiUi
            .text.ClampWorldMapCameraPosition
            .text.SetWorldMapCameraPosition
            .text.PanWorldMapCameraTo
            .text.IsWorldMapCameraMovementComplete
            .text.QueueMapTilePatch
            .text.ApplyMapTilePatch
            .text.LoadTilemaps__17GameSceneWorldMap
            .text.SetWorldMapTimeOfDayPalette
            .text.LoadTimeOfDayPalette__17GameSceneWorldMapiUi
        );
        asm/code_809E804.o(.text.game_map_time_palette_after);
        src/world_map.o(
            .text.LoadTiles__17GameSceneWorldMapR16HardwareDmaQueue
            .text.func_080A5EB8
            .text.ClearWorldMapTileRectangle
            .text.StartWorldMapTilePatchCountdown
            .text.RefreshCoopFeedTrough
        );
        asm/code_809E804.o(.text.game_map_barn_feed);
        src/world_map.o(.text.func_080A6138 .text.func_080A6194 .text.func_080A61F0 .text.func_080A6234 .text.func_080A6278 .text.func_080A62BC .text.func_080A6300 .text.func_080A635C .text.func_080A63B8);
        src/world_map.o(.text.SelectMapData__17GameSceneWorldMap .text.GetWorldMapTileAttributes .text.GetWorldMapDataId .text.GetWorldMapId .text.GetWorldMapViewY .text.GetWorldMapViewX);
        asm/code_809E804.o(.text.game_map_after_patch_dispatchers);
        src/world_map.o(.text.UpdateSavedMapTileAnimationTimers);
        src/world_map.o(.text.DrawSavedWorldMap);
        src/world_map.o(.text.RefreshSavedWorldMapAppearance);
        asm/code_809E804.o(.text.game_map_after_animation_reset);
        src/world_map.o(.text.RefreshFieldPlotTiles .text.func_080AA850 .text.func_080AA89C .text.func_080AA8BC .text.func_080AA8DC);
        asm/code_809E804.o(.text.game_map_after_flag_updates);
        src/random.o(.text);
        src/actor_facing.o(.text.GetRelativeFacing);
        asm/actor_behavior.o(.text);
        src/entity_actor.o(.text.actor_movement_bounds);
        src/terrain_movement.o(.text);
        src/actor_facing.o(.text.SelectApproachFacing .text.SelectRetreatFacing);
        src/map_data.o(.text.IsMapTerrainBoxBlocked .text.ClipMapTerrainMovement .text.ClipMapTerrainMovementIgnoringFlag1);
        asm/map_data.o(.text);
        asm/world_runtime.o(.text);
        asm/code_809E804.o(.text.world_runtime_after);
        src/ui_state.o(.text.ui_portrait_group);
        src/ui_state.o(.text.ui_text_stream_setup);
        src/ui_state.o(.text.ui_text_stream_update);
        asm/code_809E804.o(.text.ui_text_stream_update_after);
        src/game_menu.o(.text.GetMenuGridLeftCellPosition__FPC28GameSceneMenuOwnedDataPrefixi);
        src/game_menu.o(.text.GetMenuGridLeftHeaderPosition__FPC28GameSceneMenuOwnedDataPrefix);
        asm/code_809E804.o(.text.after_menu_grid_left_positions);
        src/game_menu.o(.text.GetMenuGridRightCellPosition__FPC28GameSceneMenuOwnedDataPrefixi);
        src/game_menu.o(.text.GetMenuGridRightHeaderPosition__FPC28GameSceneMenuOwnedDataPrefix);
        src/game_menu.o(.text.__23GameSceneMenuCorePrefixP18GameStateSaveImage);
        asm/code_809E804.o(.text.after_menu_core_prefix_constructor);
        src/game_menu.o(.text.Update__23GameSceneMenuCorePrefix);
        src/game_menu.o(.text.GetUnk298__C27GameSceneMenuOwnedDataState);
        src/game_menu.o(.text.GetUnk27C__C27GameSceneMenuOwnedDataState);
        asm/code_809E804.o(.text.after_menu_owned_data_accessors);
        src/game_menu.o(.text.__23GameSceneMenuCursorDataP23GameSceneMenuCorePrefixUi);
        src/game_menu.o(.text.MoveUp__23GameSceneMenuCursorData);
        src/game_menu.o(.text.MoveDown__23GameSceneMenuCursorData);
        src/game_menu.o(.text.MoveLeft__23GameSceneMenuCursorData);
        asm/code_809E804.o(.text.after_menu_cursor_data_constructor);
        src/game_menu.o(.text.SwitchPanel__23GameSceneMenuCursorData);
        src/game_menu.o(.text.SetSelection__23GameSceneMenuCursorDatai);
        asm/code_809E804.o(.text.after_menu_cursor_navigation);
        src/game_menu.o(.text.GetCursorPosition__C23GameSceneMenuCorePrefixi);
        src/game_menu.o(.text.GetItemIndex__C23GameSceneMenuCorePrefixii);
        src/game_menu.o(.text.__26GameSceneMenuSelectionCoreP18GameStateSaveImage);
        asm/code_809E804.o(.text.after_menu_selection_core_constructor);
        src/game_menu.o(.text.Update__26GameSceneMenuSelectionCore);
        asm/code_809E804.o(.text.after_menu_selection_update);
        src/game_menu.o(.text._._24GameSceneMenuTilemapData);
        asm/code_809E804.o(.text.after_menu_tilemap_data_destructor);
        src/game_menu.o(.text.__23GameSceneMenuSpriteDataP23GameSceneMenuCorePrefix);
        src/game_menu.o(.text.Show__23GameSceneMenuSpriteDataiUi);
        src/game_menu.o(.text.Hide__23GameSceneMenuSpriteData);
        asm/code_809E804.o(.text.after_menu_sprite_data_constructor);
        src/heap.o(.text);
        src/joy_bus.o(.text.InitializeJoyBusContext);
        asm/joy_bus.o(.text.joy_bus_link_reset);
        src/joy_bus.o(.text.StartJoyBusCommunication .text.StopJoyBusCommunication);
        asm/joy_bus.o(.text.joy_bus_update);
        src/joy_bus.o(.text.FinishJoyBusCommand .text.ResetJoyBusCommandResult);
        asm/joy_bus.o(.text.joy_bus_flagged_result);
        src/joy_bus.o(.text.EnableJoyBusInterrupt .text.DisableJoyBusInterrupt);
        asm/joy_bus.o(.text.joy_bus_register_setup);
        src/joy_bus.o(.text.ResetJoyBusCommandQueue .text.EnqueueJoyBusCommand .text.AdvanceJoyBusCommandQueue .text.IsJoyBusCommandQueueEmpty .text.ClearJoyBusCommandQueue);
        src/link_communication_data.o(.text);
        . = 0xD0CD4; /* Shift-JIS glyph-map index converter and renderer. */
        src/font.o(.text);
        . = 0xD0EBC; /* Remaining font support code. */
        asm/code_809E804.o(.text.font_after);
        asm/interrupt.o(.text);
        asm/compression.o(.text.compression_stream);
        asm/random.o(.text);
        asm/compression.o(.text.compression_packets);

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
        src/intro_scene.o(.text.intro_scene_core_cleanup);
        src/resource_handle.o(.text.indexed_resource_provider_cleanup);
        src/new_game_menu.o(.gnu.linkonce.t.CreateScene__27NewGameLoadedSaveTransition);
        src/intro_scene.o(.text.intro_scene_factory);
        src/intro_scene.o(.gnu.linkonce.t._._19MenuIntroTransition);
        src/new_game_menu.o(.gnu.linkonce.t._._27NewGameLoadedSaveTransition);
        src/new_game_menu.o(.text.new_game_menu_core_cleanup);
        src/game_scene.o(
            .text.__30GameSceneControllerActorRecord
            .text.__24GameSceneEventIconRecord);
        asm/code_linkonce.o(.text.new_game_after_controller_records);
        src/game_state.o(.text._._18GameStateSaveImage);
        asm/code_linkonce.o(.text.save_image_after_destructor);
        src/npc_collection.o(.text.__13NpcCollectionRC13NpcCollection);
        src/farm.o(.text.__4FarmRC4Farm);
        src/farm.o(.gnu.linkonce.t.__4BarnRC4Barn);
        src/farm.o(.gnu.linkonce.t.__4CoopRC4Coop);
        src/dog.o(.text.__as__3DogRC3Dog);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        src/farmer.o(.text.__6FarmerRC6Farmer);
        src/rucksack.o(.text.__8RucksackRC8Rucksack);
        src/rucksack.o(.text._._8Rucksack);
        src/money_account.o(.text.__12MoneyAccountRC12MoneyAccount);
        src/money_account.o(.text._._12MoneyAccount);
        src/new_game.o(.text.new_game_fresh_save_callbacks);
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
        src/hardware_bootstrap.o(.text.hardware_dma_command);
        *(.gnu.linkonce.t._._23HardwareDmaQueueCommand);
        *(.gnu.linkonce.t._._27HardwareSpriteBufferCommand);
        *(.gnu.linkonce.t._._22HardwareDisplayCommand);
        src/hardware_interrupt_guard.o(.text.hardware_frame_commands_after);
        src/hardware_manager.o(.text.hardware_manager_vblank_binding);
        asm/hardware_manager.o(.text);
        src/hardware_manager.o(.text.hardware_manager_vblank_append);
        *(.gnu.linkonce.t.__thunk_28__._27HardwareManagerCommandGroup);
        src/hardware_manager.o(.text.hardware_manager_vblank_after);
        *(.gnu.linkonce.t._._29HardwareManagerBindingRestore);
        *(.gnu.linkonce.t._._27HardwareManagerCommandGroup);
        *(.gnu.linkonce.t._._30HardwareManagerPreviousBinding);
        *(.gnu.linkonce.t._._24HardwareSoundMainCommand);
        *(.gnu.linkonce.t._._25HardwareSoundVSyncCommand);
        *(.gnu.linkonce.t._._12HardwareLink);
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
        src/entity_location.o(.text.RelocateEntityToMap__FP14GameSceneStateiUiiiUi);
        asm/code_linkonce.o(.text.game_scene_state_callbacks_after);
        src/game_scene.o(.text._._14GameSceneState);
        asm/code_linkonce.o(.text.scene_calendar_before);
        src/intro_story_scene.o(.text.CreateIntroStoryScene .text.DestroyIntroStoryTransition);
        asm/code_linkonce.o(.text.intro_story_transition_after);
        src/game_scene.o(.text.CreateScene__24SavedNameEntryTransition .gnu.linkonce.t._._24SavedNameEntryTransition);
        asm/code_linkonce.o(.text.after_saved_name_transition);
        src/game_scene.o(.text.CreateScene__18CalendarTransition .gnu.linkonce.t._._18CalendarTransition);
        src/game_scene.o(.text.CreateScene__19ToolChestTransition .gnu.linkonce.t._._19ToolChestTransition);
        src/game_scene.o(.text.CreateScene__22RefrigeratorTransition .gnu.linkonce.t._._22RefrigeratorTransition);
        src/game_scene.o(.text.CreateScene__15ShelfTransition .gnu.linkonce.t._._15ShelfTransition);
        asm/code_linkonce.o(.text.scene_shelf_after);
        src/game_scene.o(.text.CreateScene__17CookingTransition .gnu.linkonce.t._._17CookingTransition);
        src/game_scene.o(.text.CreateScene__23ReferencePageTransition .gnu.linkonce.t._._23ReferencePageTransition);
        src/game_scene.o(.text.CreateScene__29SpecialMerchantShopTransition .gnu.linkonce.t._._29SpecialMerchantShopTransition);
        asm/code_linkonce.o(.text.scene_special_merchant_shop_after);
        src/game_scene.o(.text.CreateScene__22GiftWrappingTransition .gnu.linkonce.t._._22GiftWrappingTransition);
        src/game_scene.o(.text.CreateScene__24YodelRanchShopTransition .gnu.linkonce.t._._24YodelRanchShopTransition);
        src/game_scene.o(.text.CreateScene__25PoultryFarmShopTransition .gnu.linkonce.t._._25PoultryFarmShopTransition);
        src/game_scene.o(.text.CreateScene__20WineryShopTransition .gnu.linkonce.t._._20WineryShopTransition);
        src/game_scene.o(.text.CreateScene__17InnShopTransition .gnu.linkonce.t._._17InnShopTransition);
        src/game_scene.o(.text.CreateScene__23BeachCafeShopTransition .gnu.linkonce.t._._23BeachCafeShopTransition);
        src/game_scene.o(.text.CreateScene__17WonShopTransition .gnu.linkonce.t._._17WonShopTransition);
        src/game_scene.o(.text.CreateScene__23CarpenterShopTransition .gnu.linkonce.t._._23CarpenterShopTransition);
        src/game_scene.o(.text.CreateScene__20ClinicShopTransition .gnu.linkonce.t._._20ClinicShopTransition);
        src/game_scene.o(.text.CreateScene__24BlacksmithShopTransition .gnu.linkonce.t._._24BlacksmithShopTransition);
        src/game_scene.o(.text.CreateScene__29SupermarketPurchaseTransition .gnu.linkonce.t._._29SupermarketPurchaseTransition);
        src/game_scene.o(.text.CreateScene__21SupermarketTransition .gnu.linkonce.t._._21SupermarketTransition);
        asm/code_linkonce.o(.text.scene_supermarket_after);
        src/game_scene.o(.text.CreateScene__15ClockTransition .gnu.linkonce.t._._15ClockTransition);
        src/game_scene.o(.text.CreateScene__17ReturnToGameScene .gnu.linkonce.t._._17ReturnToGameScene);
        asm/code_linkonce.o(.text.scene_return_after);
        src/scene_sprite.o(.gnu.linkonce.t._._20GameSceneGroupSprite);
        asm/code_linkonce.o(.text.scene_group_sprite_cleanup_after);
        src/scene_sprite.o(.gnu.linkonce.t._._22GameSceneIndexedSprite);
        asm/code_linkonce.o(.text.game_scene_indexed_sprite_dtor_after);
        src/npc_entity.o(.text.FindTimedPathPointUpperBound);
        asm/code_linkonce.o(.text.npc_timed_path_search_after);
        src/ui_state.o(.text.Lookup__23ScriptTextVariableStoreUi .text._._23ScriptTextVariableStore);
        asm/code_linkonce.o(.text.script_text_variables_after);
        src/hardware_dma_link.o(.text.Run__19HardwareDmaCopyLink .gnu.linkonce.t._._19HardwareDmaCopyLink);
        src/map_clock_status.o(.gnu.linkonce.t._._21MapClockStatusHudData);
        asm/code_linkonce.o(.text.map_clock_status_lifecycle_after);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        asm/code_linkonce.o(.text.code_080E0EF0);
        src/font.o(.text.font_unsigned_decimal);
        asm/code_linkonce.o(.text.code_080E0F48);
        src/ui_state.o(.text.ui_text_output_upload);
        src/ui_state.o(.gnu.linkonce.t._._24UiTextWindowSetupCommand);
        src/ui_state.o(.gnu.linkonce.t._._25UiTextOutputUploadCommand);
        src/ui_state.o(.gnu.linkonce.t._._20UiDmaTransferCommand);
        src/ui_state.o(.gnu.linkonce.t._._18UiTextInputAdapter);
        src/ui_state.o(.gnu.linkonce.t._._18UnkUiSelectionData);
        src/ui_state.o(.gnu.linkonce.t._._21UiTextTileCopyCommand);
        src/ui_state.o(.text.ui_text_input_defaults);
        src/ui_state.o(.text.ui_text_input_base_destructor);
        src/ui_state.o(.text.ui_text_output_defaults);
        src/ui_state.o(.text.ui_text_output_base_destructor);
        asm/code_linkonce.o(.text.ui_text_output_base_after);
        src/resource_handle.o(.text);
        src/intro_story_scene.o(.text.Lookup__23IntroStoryTextVariablesUi);
        src/intro_story_scene.o(.text.DestroyIntroStorySceneCore);
        src/intro_story_scene.o(.text._._23IntroStoryTextVariables);
        asm/code_linkonce.o(.text.indexed_resource_archive_destructor_after);
        src/new_game.o(.text.new_game_birthday_core_cleanup);
        asm/code_linkonce.o(.text.new_game_birthday_core_cleanup_after);
        src/game_scene.o(.text.CreateScene__30BlacksmithShopResultTransition .gnu.linkonce.t._._30BlacksmithShopResultTransition);
        asm/code_linkonce.o(.text.after_blacksmith_shop_result_transition);
        src/game_menu.o(.gnu.linkonce.t._._26GameSceneMenuSelectionCore);
        asm/code_linkonce.o(.text.after_menu_selection_core_destructor);
        src/harvest_sprite.o(.text.FindHarvestSpriteWorkTarget);
        asm/code_linkonce.o(.text.sprite_work_target_search_after);
        src/game_scene.o(.gnu.linkonce.t._._19SavedNameEntryScene);
        src/world_map.o(.gnu.linkonce.t._._25MapViewportTilemapCommand);
        asm/code_linkonce.o(.text.after_saved_name_scene_destructor);
        src/game_menu.o(.text.ClearNodes__25GameSceneMenuCommandQueue);
        asm/code_linkonce.o(.text.after_menu_command_node_cleanup);
        src/game_menu.o(.gnu.linkonce.t._._23GameSceneMenuCorePrefix);
        asm/code_linkonce.o(.text.after_menu_core_prefix_destructor);

    } > ROM = 0xFF

    .rodata : ALIGN(4)
    {
        *(.gnu.linkonce.d.__vt_6AScene);
        *(.gnu.linkonce.d.__vt_15SceneTransition);
        *(.gnu.linkonce.d.__vt_19IntroMenuTransition);
        *(.gnu.linkonce.d.__vt_24IntroNameEntryTransition);
        . = ALIGN(4); src/intro_scene.o(.rodata);
        src/intro_scene.o(.gnu.linkonce.d.__vt_14GameIntroScene);
        src/resource_handle.o(.gnu.linkonce.d.__vt_23IndexedResourceProvider);
        src/intro_scene.o(.gnu.linkonce.d.__vt_19MenuIntroTransition);
        src/new_game_menu.o(.gnu.linkonce.d.__vt_27NewGameLoadedSaveTransition);
        src/new_game_menu.o(.rodata .gnu.linkonce.d.__vt_16NewGameMenuScene);
        src/new_game.o(.rodata);
        src/new_game_identity.o(.rodata);
        src/new_game_name_input.o(.rodata .gnu.linkonce.d.__vt_21NewGameNameInputScene);
        *(.gnu.linkonce.d.__vt_23HardwareDmaQueueCommand);
        *(.gnu.linkonce.d.__vt_27HardwareSpriteBufferCommand);
        *(.gnu.linkonce.d.__vt_22HardwareDisplayCommand);
        src/hardware_bootstrap.o(.rodata);
        *(.gnu.linkonce.d.__vt_27HardwareManagerCommandGroup.28HardwareManagerVBlankBinding);
        *(.gnu.linkonce.d.__vt_27HardwareManagerCommandGroup);
        *(.gnu.linkonce.d.__vt_28HardwareManagerVBlankBinding);
        *(.gnu.linkonce.d.__vt_30HardwareManagerPreviousBinding);
        *(.gnu.linkonce.d.__vt_29HardwareManagerBindingRestore);
        *(.gnu.linkonce.d.__vt_24HardwareSoundMainCommand);
        *(.gnu.linkonce.d.__vt_25HardwareSoundVSyncCommand);
        *(.gnu.linkonce.d.__vt_19HardwareBlendObject);
        src/hardware_interrupt_guard.o(.rodata);
        *(.gnu.linkonce.d.__vt_18HardwareLinkedList);
        *(.gnu.linkonce.d.__vt_12HardwareLink);
        *(.gnu.linkonce.d.__vt_16HardwareLinkBase);
        src/game_scene.o(.gnu.linkonce.d.__vt_25GameSceneScriptController);
        src/game_scene.o(.gnu.linkonce.d.__vt_14GameSceneState);
        src/vtables.o(.rodata);
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
        . = ALIGN(4); src/scene_sprite.o(.gnu.linkonce.d.__vt_22GameSceneIndexedSprite);
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
        . = ALIGN(4); src/ui_state.o(.gnu.linkonce.d.__vt_23ScriptTextVariableStore);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7708);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7714);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7728);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7738);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7748);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7758);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7768);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_7778);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_77a4);
        . = ALIGN(4); src/hardware_dma_link.o(.gnu.linkonce.d.__vt_19HardwareDmaCopyLink);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_77e0);
        *(.gnu.linkonce.d.__vt_13AScriptEngine);
        . = ALIGN(4); src/vtables.o(.rodata.vtable_script_engine);
        . = ALIGN(4); src/font.o(.gnu.linkonce.d.__vt_*FontTilemap*DecimalCommand);
        src/font_draw.o(.gnu.linkonce.d.__vt_22FontTilemapRectCommand);
        src/ui_state.o(.gnu.linkonce.d.__vt_24UiTextWindowSetupCommand);
        src/ui_state.o(.gnu.linkonce.d.__vt_25UiTextOutputUploadCommand);
        src/ui_state.o(.gnu.linkonce.d.__vt_20UiDmaTransferCommand);
        src/ui_state.o(.gnu.linkonce.d.__vt_18UiTextInputAdapter);
        src/ui_state.o(.gnu.linkonce.d.__vt_18UnkUiSelectionData);
        src/ui_state.o(.gnu.linkonce.d.__vt_21UiTextTileCopyCommand);
        src/ui_state.o(.gnu.linkonce.d.__vt_11UiTextInput);
        src/ui_state.o(.gnu.linkonce.d.__vt_12UiTextOutput);
        src/vtables.o(.rodata.ui_output_base_after);
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
        . = ALIGN(4); src/resource_handle.o(.gnu.linkonce.d.__vt_22IndexedResourceArchive);
        . = ALIGN(4); src/intro_story_scene.o(.rodata);
        src/intro_story_scene.o(.gnu.linkonce.d.__vt_23IntroStoryTextVariables);
        src/intro_story_scene.o(.gnu.linkonce.d.__vt_15IntroStoryScene);
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
. = ALIGN(4); src/new_game.o(.gnu.linkonce.d.__vt_25NewGameBirthdayInputScene);
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
. = ALIGN(4); src/game_scene.o(.gnu.linkonce.d.__vt_30BlacksmithShopResultTransition);
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
. = ALIGN(4); src/game_scene.o(.gnu.linkonce.d.__vt_25BlacksmithShopResultScene);
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
. = ALIGN(4); src/game_scene.o(.gnu.linkonce.d.__vt_19SavedNameEntryScene);
. = ALIGN(4); src/scene_sprite.o(.gnu.linkonce.d.__vt_19GameSceneSpriteBase);
. = ALIGN(4); src/world_map.o(.gnu.linkonce.d.__vt_17GameSceneWorldMap);
. = ALIGN(4); src/world_map.o(.gnu.linkonce.d.__vt_25MapViewportTilemapCommand);
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
. = ALIGN(4); src/game_menu.o(.gnu.linkonce.d.__vt_23GameSceneMenuCorePrefix);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85ac);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85bc);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85cc);
. = ALIGN(4); src/game_menu.o(.gnu.linkonce.d.__vt_26GameSceneMenuSelectionCore);
. = ALIGN(4); src/vtables.o(.rodata.vtable_85e8);

        /* Start of the source-owned localization islands. */
        . = ABSOLUTE(0x080E8610); src/crt0_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/sram_proxy_1.o(.rodata);
        src/intro_scene_startup.o(.rodata);
        . = ABSOLUTE(0x080E86A8); src/new_game_data.o(.rodata);
        . = ABSOLUTE(0x080E8CC4); src/field_data.o(.rodata);
        src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        /* Item text, catalogs, products, and trailer. */
        . = ABSOLUTE(0x080E9614); src/item.o(.rodata);
        /* Calendar rows, labels, and state data. */
        . = ABSOLUTE(0x080F04EE); src/game_state.o(.rodata);
        FILL(0x00);
        /* Help-menu text and byte table. */
        . = ABSOLUTE(0x080F058C); src/help_menu.o(.rodata);
        FILL(0x00);
        /* Animal memorial text and animal data. */
        . = ALIGN(4); src/animal_data.o(.rodata);
        FILL(0x00);
        /* Entity UI labels and native UI data. */
        . = ABSOLUTE(0x080F0E80); src/entity_ui.o(.rodata);
        FILL(0x00);
        /* Common UI labels, fallback text, menu data, and pointer table. */
        . = ABSOLUTE(0x080F1974); src/common_ui.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x080F1A80); src/data_schedules.o(.rodata);
        /* Other NPC schedule records follow the individually declared schedules. */
        . = ALIGN(4); src/npc_schedule_data.o(.rodata);
        . = ABSOLUTE(0x080F89D4); data/scripts/script_table.o(.rodata.mary_script_table);
        /* The ordinary source block bounds the preceding Mary script table. */
        . = ABSOLUTE(0x080F9E98); src/script_engine.o(.rodata);
        . = ABSOLUTE(0x080F9EC5); src/cooking_festival.o(.rodata);
        src/thomas_stocking.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/spouse_gift.o(.rodata);
        . = ABSOLUTE(0x080F9EF4); src/farm_house.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/ui_state.o(.rodata);
        /* Bounded New Game preset localization island: names and UI glyphs. */
        . = ABSOLUTE(0x080F9F7C); src/new_game_name_entry_ui_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x080FA158); src/frisbee_scoreboard.o(.rodata);
        . = ABSOLUTE(0x080FA174); src/animal_festival_ranking_score_data.o(.rodata);
        . = ABSOLUTE(0x080FA39C); src/frisbee.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x080FAA40); src/horse_race_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Intro-scene resource table, dialogue, and runtime tail. */
        . = ABSOLUTE(0x080FB1D8); src/intro_scene_data.o(.rodata);
        FILL(0x00);
        /* Farm Status screen data. */
        . = ABSOLUTE(0x080FB824); src/farm_status_screen_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x080FBE7C); src/records_screen_data.o(.rodata);
        . = ALIGN(4); src/staff_credits.o(.rodata);
        /* Bounded Town Map localization island: labels, hotspots, and lookup. */
        . = ABSOLUTE(0x080FC6C2); src/town_map_data.o(.rodata);
        . = ABSOLUTE(0x080FD550); src/library_opening_hours_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4); src/town_map_area_data.o(.rodata);
        src/library_data.o(.rodata);
        . = ABSOLUTE(0x080FD964); src/poultry_shop_data.o(.rodata);
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
        . = ABSOLUTE(0x080FEAF4); src/beach_cafe_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x080FEC7C); src/blacksmith_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x080FF35C); src/carpenter_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0x00);
        . = ABSOLUTE(0x080FFB60); src/livestock_shop.o(.rodata);
        . = ABSOLUTE(0x08100024); src/home_storage.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x08100168); src/blacksmith_upgrade_data.o(.rodata);
        . = ABSOLUTE(0x081003E4); src/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Link-communication regional data: text, tables, codes. */
        FILL(0x00);
        . = ABSOLUTE(0x081004E0); src/link_communication_data.o(.rodata);
        . = ABSOLUTE(0x08100AC0); src/cooking_recipe_inventory_page_data.o(.rodata);
        . = ABSOLUTE(0x08100AD2); src/recovery_status.o(.rodata);
        . = ABSOLUTE(0x08100DE4); src/cooking.o(.rodata);
        . = ABSOLUTE(0x081010E8); src/cooking_recipe_inventory.o(.rodata);
        src/animal.o(.rodata);
        . = ABSOLUTE(0x08103660); src/livestock_day_update_data.o(.rodata);
        . = ABSOLUTE(0x081036C0); src/actor_state.o(.rodata);
        /* Fishing-record regional data: names, lookup, trailer. */
        . = ABSOLUTE(0x08103788); src/fishing_results_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x08103B10); src/actor_runtime_data.o(.rodata);
        . = ABSOLUTE(0x08104108); src/character_names_empty.o(.rodata);
        . = ABSOLUTE(0x08104109); src/bachelorette.o(.rodata);
        /* Character-name text, lookup table, and runtime trailer. */
        . = ABSOLUTE(0x08104128); src/character_names_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x081043BC); src/field_item_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = ABSOLUTE(0x08104938); src/calendar_events.o(.rodata);
        . = ABSOLUTE(0x08104E0C); src/possessive_labels.o(.rodata);
        . = ABSOLUTE(0x08104E4C); src/random_item_unavailable.o(.rodata);
        . = ABSOLUTE(0x08104E54); src/fishing_record_article_ids.o(.rodata);
        . = ABSOLUTE(0x08104E74); src/field_plot_position_values.o(.rodata);
        . = ABSOLUTE(0x08104EAC); src/random_item_selection.o(.rodata);
        . = ABSOLUTE(0x0810563C); src/field_plot_position_rules.o(.rodata);
        . = ABSOLUTE(0x08105708); src/time_of_day.o(.rodata);
        . = ABSOLUTE(0x08105EDC); src/map_data.o(.rodata);
        . = ABSOLUTE(0x0810692C); src/field_render_rect_descriptors.o(.rodata);
        . = ABSOLUTE(0x081070DC); src/field_render_farm_house_data.o(.rodata);
        . = ABSOLUTE(0x08107350); src/field_render_resource_data.o(.rodata);
        FILL(0x00);
        . = ABSOLUTE(0x08107438); src/bachelorette_marriage_candidate_data.o(.rodata);
        . = ABSOLUTE(0x08107450); src/field_render_runtime_data.o(.rodata);
        . = ABSOLUTE(0x081075B0); src/harvest_sprite.o(.rodata);
        . = ABSOLUTE(0x0810828C); src/reference_guide.o(.rodata.reference_guide);
        . = ABSOLUTE(0x081177EC); src/shop_common.o(.rodata);
        . = ABSOLUTE(0x08117B14); src/font.o(.rodata);
        . = ABSOLUTE(0x08117BD4); asm/data/static_resources.o(.rodata);
        . = ABSOLUTE(0x08139A88); src/m4a.o(.rodata);
        . = ABSOLUTE(0x08139D60); src/m4a.o(.rodata.gM4aVoiceGroups);
        . = ABSOLUTE(0x0813ABB4); src/m4a.o(.rodata.gMusicPlayerTable);
        . = ALIGN(4); src/m4a.o(.rodata.gSongTable);
        /* SongEnt is eight bytes; use the actual table length, including unused slots. */
        _M4aNumSongs = ABSOLUTE((. - gSongTable) / 8);
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
        . = ABSOLUTE(0x082AC0B0); data/scripts/scripts.o(.rodata.mary_scripts);
        . = ABSOLUTE(0x084F90CC); asm/data/data_0813B288.o(.rodata.mary_scripts_tail);
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

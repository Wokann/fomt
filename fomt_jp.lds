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
        . = 0x0; /* JP ROM 0x08000000, independently matched */
        src/crt0.o(.rom_header);
        . = 0x18C; /* JP ROM 0x0800018C, independently matched */
        asm/main.o(.text);
        src/main.o(.text);
        . = 0x2E0; /* JP ROM 0x080002E0, independently matched */
        src/sram_proxy_1.o(.text);
        . = 0x4C4; /* JP ROM 0x080004C4, independently matched */
        asm/interrupt.o(.text);
        . = 0x59C; /* JP ROM 0x0800059C, independently matched */
        src/new.o(.text);
        src/pure_virtual.o(.text);
        . = 0x63C; /* JP ROM 0x0800063C, independently matched */
        asm/sram_proxy_2.o(.text);
        src/sram_proxy_2.o(.text);
        asm/sram_proxy_2.o(.text.sram_proxy_2_after_006e4);
        . = 0x7EC; /* JP ROM 0x080007EC, independently matched */
        src/scene.o(.text);
        . = 0x82C; /* JP ROM 0x0800082C, independently matched */
        asm/scene.o(.text);
        . = 0x914; /* JP ROM 0x08000914, independently matched */
        asm/intro_scene.o(.text);
        . = 0x37A0; /* JP ROM 0x080037A0, independently matched */
        asm/new_game.o(.text);
        . = 0x7130; /* JP ROM 0x08007130, independently matched */
        src/hardware.o(.text);
        . = 0x7374; /* JP ROM 0x08007374, independently matched */
        asm/hardware.o(.text);
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
        src/code_0800E2E4.o(.text);
        . = 0xE334; /* JP ROM 0x0800E334, independently matched */
        src/farmer.o(.text);
        . = 0xEFCC; /* JP ROM 0x0800EFCC, independently matched */
        src/rucksack_item.o(.text);
        . = 0xF150; /* JP ROM 0x0800F150, independently matched */
        src/held_item.o(.text);
        . = 0xF554; /* JP ROM 0x0800F554, independently matched */
        src/rucksack.o(.text);
        . = 0xFF6C; /* JP ROM 0x0800FF6C, independently matched */
        asm/more_items.o(.text);
        . = 0x1002C; /* JP ROM 0x0801002C, independently matched */
        asm/game_scene.o(.text);
        . = 0x10328; /* JP ROM 0x08010328, bounded by game_scene and entity */
        asm/game_state.o(.text);
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
        . = 0x349F8; /* Continue the surrounding entity-UI ROM block. */
        asm/code_entities_080320DC.o(.text.entity_ui_resource_setup_after);
        . = 0x34A80; /* JP ROM 0x08034A80, independently matched */
        src/npc_entity.o(.text);
        . = 0x35114; /* JP ROM 0x08035114, independently matched */
        asm/code_entities_08034CEC.o(.text);

        . = 0x3A518; /* JP ROM 0x0803A518, independently matched */

        asm/code_0803A8A4.o(.text);
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
        . = 0x3E080; /* JP counterpart of shared schedule gate func_0803E40C. */
        src/code_0803E40C.o(.text);
        . = 0x3E0BC; /* JP ROM 0x0803E448, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803E448);
        . = 0x3EB08; /* JP ROM 0x0803EB08, independently matched */
        src/script_engine.o(.text);
        . = 0x3F704; /* JP ROM 0x0803F704, independently matched */
        asm/code_0803EE94.o(.text);
        . = 0x4E2D4; /* JP ordinary 2D glyph compositor. */
        src/font_draw.o(.text.font_draw_normal);
        . = 0x4E3D4; /* JP extended palette glyph compositor. */
        src/font_draw_ext.o(.text);
        . = 0x4E5C8; /* Shared 2D tile-buffer fillers and Shift-JIS renderers. */
        src/font_draw.o(.text);
        . = 0x4E7F8; src/font_draw.o(.text.font_draw_after);
        asm/code_0803EE94.o(.text.font_draw_after);
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
        . = 0x50AE8; /* JP ROM contiguous UI-state adapter block. */
        src/ui_state.o(.text.ui_state_adapters);
        . = 0x50C70; /* JP ROM 0x08050C70, remaining raw UI-adjacent code. */
        asm/code_0803EE94.o(.text.code_08050E50);
        . = 0x52068; /* JP/US-shared animal-festival ranking entry copy. */
        src/animal_festival_ranking.o(.text.copy_animal_festival_ranking_entry);
        . = 0x52078; /* JP/US-shared animal-festival ranking entry setter. */
        src/animal_festival_ranking.o(.text.set_animal_festival_ranking_entry);
        . = 0x52088; asm/code_0803EE94.o(.text.animal_festival_ranking_after);
        . = 0x5E410; /* JP/US-shared indexed resource-archive constructor. */
        src/resource_handle.o(.text.indexed_resource_archive_constructor);
        . = 0x5E4A4; /* JP/US-shared indexed resource-archive resolver. */
        src/resource_handle.o(.text.indexed_resource_archive_resolve);
        . = 0x5E4D4; asm/code_0803EE94.o(.text.indexed_resource_archive_resolve_after);
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
        . = 0x5E5D8; asm/code_0803EE94.o(.text.indexed_resource_handle_constructor_after);
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
        src/code_actor_0809BFE8.o(.text);
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
        src/code_actor_0809C3E0.o(.text);
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
        . = 0x9BFEC; /* JP ROM 0x0809BFEC, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C008; /* JP ROM 0x0809C008, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C024; /* JP ROM 0x0809C024, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C02C; /* JP ROM 0x0809C02C, test flag word */
        src/code_actor_0809C5F4.o(.text);
        . = 0x9C038; /* JP ROM 0x0809C038, register event-state variable */
        src/code_actor_0809C600.o(.text);
        . = 0x9C07C; /* JP ROM 0x0809C07C, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C644);
        . = 0x9C0CC; /* JP ROM 0x0809C0CC, compare selected u16 */
        src/code_actor_0809C694.o(.text);
        . = 0x9C0E4; /* JP ROM 0x0809C0E4, set selected u16 */
        src/code_actor_0809C6AC.o(.text);
        . = 0x9C0E8; /* JP ROM 0x0809C0E8, reset selected u16 */
        src/code_actor_0809C6B0.o(.text);
        . = 0x9C0F4; /* JP ROM 0x0809C0F4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C6BC);
        . = 0x9C7B0; /* JP ROM 0x0809CD78, clear tracked counters */
        src/code_actor_0809CD78.o(.text);
        . = 0x9C7D0; /* JP ROM 0x0809C7D0, update count and maximum */
        src/code_actor_0809CD98.o(.text);
        . = 0x9C804; /* JP ROM 0x0809C804, test tracked counts */
        src/code_actor_0809CDCC.o(.text);
        . = 0x9C824; /* JP ROM 0x0809C824, sum tracked counts */
        src/code_actor_0809CDEC.o(.text);
        . = 0x9C854; /* JP ROM 0x0809C854, get record count */
        src/code_actor_0809CE1C.o(.text);
        . = 0x9C85C; /* JP ROM 0x0809C85C, get record maximum */
        src/code_actor_0809CE24.o(.text);
        . = 0x9C868; /* JP ROM 0x0809C868, map six input codes */
        src/code_actor_0809CE30.o(.text);
        . = 0x9C8B4; /* JP ROM 0x0809C8B4, get fishing-record name */
        src/code_actor_0809CE7C.o(.text);
        . = 0x9C8C4; /* JP ROM 0x0809C8C4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CE8C);
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
        src/code_actor_0809D8D4.o(.text);
        . = 0x9D320; /* JP ROM 0x0809D8E8, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9D964; /* JP counterpart of US function 0x0809DF2C. */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9D9E4; /* JP ROM 0x0809DFAC, count actor-state flag bits */
        src/code_actor_0809DFAC.o(.text);
        . = 0x9DA64; /* JP ROM 0x0809E02C, count actor-state flag bits */
        src/code_actor_0809E02C.o(.text);
        . = 0x9DAE4; /* JP ROM 0x0809E0AC, select actor-state cell-type data */
        src/code_actor_0809E0AC.o(.text);
        . = 0x9DB50; /* JP ROM 0x0809E118, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9DBAC; /* JP ROM 0x0809E174, read actor-state bit 0 */
        src/code_actor_0809E174.o(.text);
        . = 0x9DBBC; /* JP ROM 0x0809E184, read actor-state bit 2 */
        src/code_actor_0809E184.o(.text);
        . = 0x9DBCC; /* JP ROM 0x0809E194, read actor-state bit 3 */
        src/code_actor_0809E194.o(.text);
        . = 0x9DBDC; /* JP ROM 0x0809E1A4, read actor-state bit 4 */
        src/code_actor_0809E1A4.o(.text);
        . = 0x9DBEC; /* JP ROM 0x0809E1B4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        . = 0x9DD0C; /* JP ROM 0x0809DD0C, independently matched */
        src/npc.o(.text);
        . = 0x9DE90; /* JP ROM 0x0809DE90, independently matched */
        src/bachelorette.o(.text);
        . = 0x9E060; /* JP ROM 0x0809E060, independently matched */
        src/harvest_sprite.o(.text);

        . = 0x9E23C; /* JP ROM 0x0809E23C, independently matched */

        asm/code_809E804.o(.text);
        . = 0x9E504; /* JP counterpart of shared NPC runtime fields. */
        src/npc_runtime_data.o(.text);
        . = 0x9E530; /* JP ROM 0x0809E530, remaining raw NPC runtime code. */
        asm/code_809E804.o(.text.npc_runtime_data_after);
        . = 0xA40D0;
        src/map_data.o(.text.get_map_data);
        . = 0xA40E4;
        asm/code_809E804.o(.text.get_map_data_after);
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
        . = 0xD3100; /* JP ROM 0x080D3100, independently matched */
        asm/code_libc_string.o(.text);

        . = 0xD3378; /* JP ROM 0x080D3378, independently matched */

        asm/code_linkonce.o(.text.code_080D3BC0);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        . = 0xD6078; /* JP ROM 0x080D6078, independently matched */
        asm/code_linkonce.o(.text.code_080D68C0);
        *(.gnu.linkonce.t.__as__5SheepRC5Sheep);
        *(.gnu.linkonce.t.__as__3CowRC3Cow);
        *(.gnu.linkonce.t.__as__9LivestockRC9Livestock);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        . = 0xD761C; /* JP ROM 0x080D761C, direct function match */
        asm/code_linkonce.o(.text.code_080D7CFC);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        . = 0xE0690; /* JP ROM 0x080E0690, independently matched */
        asm/code_linkonce.o(.text.code_080E0EF0);

        . = 0xE4E0C; /* JP C++ table region begins after code_linkonce. */
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
        . = ALIGN(4); src/vtables.o(.rodata.vtable_ascript_engine);
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

        . = 0xE7A40; /* JP data_080E8610 begins after the C++ table region. */
        src/crt0_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/sram_proxy_1.o(.rodata);
        src/intro_scene_data.o(.rodata.intro_scene_startup_resources);
        /* Bounded New Game localization island: menu, text, and name-entry data. */
        . = 0xE7AC8; src/new_game_menu_data.o(.rodata);
        ASSERT(. <= 0xE8164, "JP New Game localization island overflow");
        FILL(0x00);
        . = 0xE8164; src/field_data.o(.rodata.field_plot_weather_ordinary);
        src/field_data.o(.rodata.field_plot_weather_special_3);
        src/field_data.o(.rodata.field_plot_weather_special_4);
        src/field_data.o(.rodata.field_plot_growth_transitions);
        src/field_data.o(.rodata.field_plot_definitions);
        . = 0xE8A6C; /* JP ROM 0x080E8A6C, independently matched */
        src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        /* Bounded item localization island: text, catalogs, products, trailer. */
        . = 0xE8AB4; src/item.o(.rodata);
        ASSERT(. <= 0xEFD52, "JP item localization island overflow");
        FILL(0x00);
        . = 0xEFD52; data/text/calendar.o(.rodata.calendar_season);
        data/text/calendar.o(.rodata);
        . = 0xEFDAA; src/game_state.o(.rodata);
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
        . = 0xF12DC; /* JP schedule table block. */
        src/data_schedules.o(.rodata);
        . = ALIGN(4); src/entity_ui.o(.rodata.entity_ui_resource_selector);
        FILL(0x00);
        . = ALIGN(4); asm/data/data_080F1A80.o(.rodata.data_080f1a80_suffix);
        . = 0xF96F4; /* JP ScriptEngine string-object prefix. */
        src/script_engine.o(.rodata.script_engine_string_error_prefix);
        . = 0xF9700; data/text/common/script_engine.o(.rodata);
        . = 0xF9721; src/cooking_festival_data.o(.rodata);
        src/thomas_stocking_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/spouse_gift_data.o(.rodata);
        . = 0xF9750; src/farm_house.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/ui_state.o(.rodata.ui_state_adapters);
        src/ui_state.o(.rodata);
        . = 0xF97D8; data/text/new_game_name_entry_preset.o(.rodata);
        . = 0xF996C; src/new_game_name_entry_ui_data.o(.rodata);
        . = 0xF9994; data/text/frisbee_scoreboard.o(.rodata);
        FILL(0x00);
        . = 0xF99AC; src/animal_festival_ranking.o(.rodata.animal_festival_ranking_score_table);
        . = 0xF9A74; src/animal_festival_ranking.o(.rodata.animal_festival_ranking_scoreboard_trailer);
        . = 0xF9A7E; src/animal_festival_ranking.o(.rodata.animal_festival_ranking_data);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_reward_article_ids);
        . = 0xF9BD4; data/text/frisbee.o(.rodata);
        FILL(0x00);
        FILL(0x00);
        . = ALIGN(4); src/animal_festival_ranking.o(.rodata.animal_festival_ranking_random_range_pairs);
        . = 0xF9FCC; data/text/animal_festival.o(.rodata);
        . = 0xFA1DE; src/animal_festival_ranking.o(.rodata.animal_festival_livestock_contestant_values);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFA280; src/horse_race_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFAA60; src/intro_scene_data.o(.rodata.intro_scene_prefix);
        FILL(0x00);
        /* Bounded intro-scene localization island: resource table and dialogue. */
        . = 0xFAA6C; src/intro_scene_data.o(.rodata);
        ASSERT(. <= 0xFB110, "JP intro-scene localization island overflow");
        FILL(0x00);
        . = 0xFB110; src/intro_scene_data.o(.rodata.intro_scene_trailer);
        /* Bounded Farm Status localization island: two text groups and UI data. */
        . = 0xFB11C; src/farm_status_screen_data.o(.rodata);
        ASSERT(. <= 0xFB764, "JP Farm Status localization island overflow");
        FILL(0x00);
        . = 0xFB764; src/records_screen_data.o(.rodata);
        . = ALIGN(4); data/text/staff_credits.o(.rodata);
        . = 0xFBE88; src/town_map_data.o(.rodata.staff_credits_trailer);
        src/town_map_data.o(.rodata.town_map_resource_ids);
        /* Bounded Town Map localization island: labels, hotspots, and lookup. */
        FILL(0x00);
        . = 0xFBE9C; src/town_map_data.o(.rodata);
        ASSERT(. <= 0xFCCB8, "JP Town Map localization island overflow");
        . = 0xFCCB8; src/library_data.o(.rodata.library_opening_hours);
        FILL(0x00);
        . = ALIGN(4); src/town_map_data.o(.rodata.town_map_area_bounds);
        src/library_data.o(.rodata.library_info);
        FILL(0x00);
        . = ALIGN(4); src/library_data.o(.rodata.library_initial_entry_ids);
        . = 0xFD0B0; src/library_data.o(.rodata.library_menu);
        . = 0xFD0D0; src/poultry_shop_data.o(.rodata);
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
        . = 0xFE3A0; src/beach_cafe_shop_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFE53C; src/blacksmith_menu_data.o(.rodata);
        FILL(0x00);
        . = 0xFE6A4; src/blacksmith_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        . = 0xFEC90; src/carpenter_data.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        FILL(0xFF);
        . = 0xFF508; src/livestock_shop.o(.rodata);
        FILL(0x00);
        . = 0xFF9A4; data/text/home_storage.o(.rodata);
        FILL(0x00);
        . = 0xFFAE0; src/blacksmith_upgrade_data.o(.rodata);
        . = 0xFFD54; data/text/gift_wrap.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        /* Bounded link-communication localization island: text, tables, codes. */
        FILL(0x00);
        . = 0xFFE70; src/link_communication_data.o(.rodata);
        ASSERT(. <= 0x1005D8, "JP link-communication localization island overflow");
        . = 0x1005D8; src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break);
        . = 0x1005DA; src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_utensil_values);
        . = 0x1005EA; data/text/recovery_status.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        data/text/cooking.o(.rodata);
        . = 0x100C24; src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_mask_entries);
        . = 0x100C48; src/cooking_recipe_inventory_data.o(.rodata);
        src/animal.o(.rodata.animal_unnamed);
        . = 0x10319C; src/livestock.o(.rodata.livestock_day_update);
        . = 0x1031FC; src/code_actor_0809C3E0.o(.rodata.actor_state_max_values);
        . = 0x103204; src/code_actor_0809C3E0.o(.rodata);
        /* Bounded fishing-record localization island: names, lookup, trailer. */
        . = 0x1032C4; src/fishing_results_data.o(.rodata);
        ASSERT(. <= 0x103604, "JP fishing-record localization island overflow");
        FILL(0x00);
        . = 0x103604; src/code_actor_0809BFE8.o(.rodata);
        . = 0x103BFC; src/character_names_data.o(.rodata.character_names_empty);
        . = 0x103BFD; src/bachelorette.o(.rodata);
        /* Bounded character-name localization island: names, lookup, trailer. */
        . = 0x103C1C; src/character_names_data.o(.rodata);
        ASSERT(. <= 0x103F00, "JP character-name localization island overflow");
        FILL(0x00);
        . = 0x103F00; src/field_data.o(.rodata.field_item_records);
        FILL(0x00);
        . = ALIGN(4);
        . = 0x10447C; data/text/calendar_events.o(.rodata);
        . = 0x104958; data/text/possessive_labels.o(.rodata);
        . = 0x104994; data/text/random_item.o(.rodata);
        . = 0x10499C; src/fishing_results_data.o(.rodata.fishing_record_article_ids);
        . = 0x1049BC; src/field_data.o(.rodata.field_plot_position_values);
        . = 0x1049F4; src/random_item.o(.rodata.random_item_selection_weights);
        . = 0x104A18; src/random_item.o(.rodata.random_item_candidate_configurations);
        . = 0x105178; src/random_item.o(.rodata);
        . = 0x105184; src/field_data.o(.rodata.field_plot_position_rules);
        . = 0x105244; src/field_data.o(.rodata);
        . = 0x105250; src/code_0800E2E4.o(.rodata.time_of_day_transition_table);
        . = 0x105290; src/code_0800E2E4.o(.rodata.time_of_day_transition_records);
        . = 0x105A24; src/map_data.o(.rodata.map_data);
        . = 0x106474; src/field_data.o(.rodata.field_render_rect_descriptors);
        . = 0x106C24; src/farm_house.o(.rodata.farm_house_tile_patches);
        . = 0x106D4C; src/farm_house.o(.rodata.farm_house_visual_descriptors);
        . = 0x106E80; src/farm_house.o(.rodata.farm_house_tile_patch_animations);
        . = 0x106E98; src/field_data.o(.rodata.field_render_resource_first_values);
        . = 0x106EA4; src/field_data.o(.rodata.field_render_resource_second_values);
        . = 0x106EB8; src/field_data.o(.rodata.field_render_resource_runtime_strings);
        . = 0x106ED0; src/field_data.o(.rodata.field_render_parallel_tables);
        . = 0x106F0C; src/field_data.o(.rodata.field_render_patch_arguments);
        . = 0x106F6C; src/field_data.o(.rodata.field_render_patch_arguments_after);
        . = 0x106F76; src/farm_house.o(.rodata.farm_house_style_nibble_lookup);
        FILL(0x00);
        . = 0x106F80; src/bachelorette.o(.rodata.bachelorette_marriage_candidate_character_ids);
        . = 0x106F98; src/field_data.o(.rodata.field_render_seasonal_record_ranges);
        . = 0x106FA0; src/field_data.o(.rodata.field_render_lookup_values);
        . = 0x106FE8; src/field_data.o(.rodata.field_render_runtime_strings);
        . = 0x10703E; src/field_data.o(.rodata.field_render_sorted_values);
        . = 0x107058; src/field_data.o(.rodata.field_render_sorted_values_runtime_strings);
        . = 0x107070; src/field_data.o(.rodata.unk_080AE894_values);
        . = 0x1070AC; src/field_data.o(.rodata.unk_080B0708_default_glyph);
        . = 0x1070B0; src/field_data.o(.rodata.unk_080B09B0_index_values);
        . = 0x1070CC; src/field_data.o(.rodata.unk_080B0BB8_values);
        . = 0x1070F4; data/text/harvest_sprite_minigames.o(.rodata);
        . = 0x10737B; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_match_values);
        . = 0x107380; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_u16_tables);
        . = 0x1073AC; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime);
        . = 0x1073B9; data/text/chicken_festival.o(.rodata);
        . = 0x1074C0; data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata);
        . = 0x1075EA; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_values);
        . = 0x10761A; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_offsets);
        . = 0x107620; data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata);
        . = 0x107804; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data);
        . = 0x1078E0; data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata);
        . = 0x107A5C; data/text/harvest_sprite_minigames_harvest_results.o(.rodata);
        . = 0x107AA9; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_first_values);
        . = 0x107AC0; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_second_values);
        . = 0x107AD0; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values);
        . = 0x107B1C; data/text/harvest_sprite_minigames_watering_instructions.o(.rodata);
        . = 0x107D38; data/text/harvest_sprite_minigames_watering_results.o(.rodata);
        . = 0x107D8A; src/harvest_sprite.o(.rodata.harvest_sprite_minigames_watering_results_values);
        . = 0x107DAC; src/reference_guide.o(.rodata.reference_guide);
        . = 0x1189D4; src/shop_common.o(.rodata.shop_common_digit_glyphs);
        . = 0x1189F4; data/text/shop_common.o(.rodata);
        . = 0x118A14; src/shop_common.o(.rodata);
        . = 0x118B94; data/text/status_ui.o(.rodata);
        . = 0x118CF4; src/font.o(.rodata);
        . = 0x118D18; /* Static resources after font-owned data. */
        asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard);
        . = 0x13ABCC; src/m4a.o(.rodata);
        . = 0x13AEA4; src/m4a.o(.rodata.gM4aVoiceGroups);
        . = 0x13BCF8; src/m4a.o(.rodata.gMusicPlayerTable);
        src/m4a.o(.rodata.gSongTable);
        . = 0x13C3CC; /* JP asset container, independently matched. */
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

#include "game_scene.hh"
#include FOMT_TEXT_INCLUDE(game_scene.cc)
#include "obj_palette_collection.hh"
#include "scene_menu_transitions.hh"
#include "prelude.h"
#include "new_game_name_input.hh"
#include <new>
#include <string.h>
#include "hardware_blend.hh"
#include "hardware_manager.hh"
#include "hardware_dma.hh"
#include "hardware_context.hh"
#include "game_state.hh"
#include "field_item_data.hh"
#include "field_render_rect_descriptors.hh"
#include "field_render_farm_house_data.hh"
#include "field_render_resource_data.hh"
#include "map_patch_flags.hh"
#include "entity_actor.hh"
#include "npc_entity.hh"
#include "entity_ui.hh"
#include "harvest_sprite_actor.hh"
#include "world_prop_entities.hh"
#include "fomt_constants.hh"
#include "data/scripts/fomt_scripts.mary.h"
#include "hardware_sound.hh"
#include "font.hh"
#include "font_decimal.hh"
#include "gbasvc.h"
#include "gbaio.h"

#include "game_scene.hh"
#include "game_scene_return.hh"
#include "game_scene_state.hh"
#include "game_scene_actions.hh"
#include "game_scene_controller.hh"
#include "scene_supermarket.hh"
#include "scene_won_shop.hh"
#include "scene_carpenter_shop.hh"
#include "scene_blacksmith_shop.hh"
#include "scene_clinic_shop.hh"
#include "scene_beach_cafe_shop.hh"
#include "name_entry.hh"
#include "scene_yodel_ranch_shop.hh"
#include "scene_winery_shop.hh"
#include "scene_inn_shop.hh"
#include "scene_poultry_farm_shop.hh"
#include "scene_special_merchant_shop.hh"
#include "scene_gift_wrapping.hh"
#include "scene_reference_page.hh"
#include "scene_calendar.hh"
#include "scene_tool_chest.hh"
#include "scene_refrigerator.hh"
#include "scene_shelf.hh"
#include "scene.hh"
#include "map_clock_status.hh"
#include "new_game_menu.hh"
#include "world_map.hh"
#include "scene_clock.hh"
#include "scene_cooking.hh"
#include "scene_gamecube_link.hh"
#include "scene_minigames.hh"
#include "intro_story_scene.hh"
#include "hardware_input.hh"
#include "scene_rucksack.hh"
#include "town_map.hh"
#include "animal_festival_selection.hh"
#include "staff_credits.hh"
#include "farming_tutorial_transition.hh"
#include "hardware_display_state.hh"
#include "scene_chicken_festival.hh"
#include "harvest_sprite.hh"
#include "horse_race.hh"
#include "frisbee.hh"
#include "frisbee_scoreboard.hh"
#include "calendar.hh"
#include "game_world.hh"
#include "world_sprite_effects.hh"
#include "entity_auxiliary_sprites.hh"
#include "farm_terrain.hh"
#include "npc_collection.hh"
template <u32 Capacity>
inline void GameSceneScriptQueue<Capacity>::Push(GameSceneScriptRequest const & request)
{
    if (count < Capacity) {
        new (End()) GameSceneScriptRequest(request);
        ++count;
    }
}

static inline void StartSceneSong(HardwareMusicPlayerSlot * player, i32 mode, u16 song_id)
{
    switch (mode) {
    case AUDIO_START:
        player->Start(song_id);
        break;
    case AUDIO_START_WEAK:
        player->StartIfChangedOrPaused(song_id);
        break;
    case AUDIO_START_OR_CONTINUE:
        player->StartOrContinue(song_id);
        break;
    }
}

static inline HardwareMusicPlayerSlot * FindAvailableSceneSongPlayer(GameSceneSongPlayerPool & pool)
{
    HardwareMusicPlayerSlot ** it = pool.begin;
    HardwareMusicPlayerSlot ** end = pool.end;
    for (; it != end; ++it) {
        if (static_cast<u8>((*it)->IsUnpaused()) == 0)
            return *it;
    }
    // The native path assumes a nonempty pool and reuses its final entry.
    return *(end - 1);
}

static inline void ApplySceneBgmSettings(GameSceneBgmSettings const & settings, HardwareMusicPlayerSlot * player)
{
    player->InitializeImmediately();
    player->SetTempo(settings.tempo);
    player->SetVolume(settings.volume, 0xFFFF);
    player->SetPitch(settings.pitch, 0xFFFF);
    player->SetPan(settings.pan, 0xFFFF);
    player->SetModulationDepth(settings.modulation_depth, 0xFFFF);
    player->SetLfoSpeed(settings.lfo_speed, 0xFFFF);
}

void UpdateGameSceneHardwareFrame(GameSceneState * state, HardwareSpriteBufferState * buffer)
{
    HardwareDisplayCommand display(&state->display);
    HardwareSpriteBufferCommand sprite(buffer);
    HardwareDmaQueueCommand dma(&state->dma_queue);
    HardwareLinkedList commands;

    func_08009940(&commands, &state->links);
    func_08009940(&commands, &display);
    func_08009940(&commands, &dma);
    func_08009940(&commands, &sprite);

    HardwareManagerOwner * manager = &state->manager;
    GetHardwareManagerFrameCommands(manager)->Append(&commands);
    WaitForHardwareVBlank(manager);
    GetHardwareManagerFrameCommands(manager)->Remove(&commands);

    // The temporary list and commands unlink in reverse construction order.
}

GameScene::GameScene(GameStateSaveImage * image, GameSceneResumeRequest const & request)
{
    GameSceneState * core = new GameSceneState(this, image, request);
    u16 status = core->display.status;
    status |= 8;
    core->display.status = status;
    REG_DISPSTAT = status;
    state = core;
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    controller->script_engine.SetUnk(this);
}


#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
GameScene::GameScene(GameStateSaveImage * image)
{
    GameSceneState * core = new GameSceneState(this, image, GameSceneResumeRequest(2));
    u16 status = core->display.status;
    status |= 8;
    core->display.status = status;
    REG_DISPSTAT = status;
    state = core;
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    controller->script_engine.SetUnk(this);
}
#endif

GameScene::~GameScene()
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    controller->script_engine.ClearUnk();
    delete state;
}

SceneTransitionOwner GameScene::Run()
{
    return sub_080D8178(state);
}

void GameScene::SetEntityPosition(u32 id, i32 x, i32 y, u32 facing)
{
    GameSceneState * current = state;
    u32 map = current->game_object.value->vfunc_14();
    ::RelocateEntityToMap(current, id, map, x, y, facing);
}

i32 GameScene::GetEntityX(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16X();
    return value >> 16;
}

i32 GameScene::GetEntityY(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16Y();
    return value >> 16;
}

void GameScene::SetEntityFacing(u32 id, u32 facing)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr && entity->facing != facing)
        entity->SetAnimFacing(facing);
}

u32 GameScene::GetEntityFacing(u32 id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    return entity != nullptr ? entity->facing : 0;
}

u32 GameScene::GetEntityMap(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    u32 map = MAP_NONE;
    if (entity != nullptr)
        map = entity->GetMap();
    return map;
}

void GameScene::SetEntitySpritePriority(u32 id, u32 priority)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        entity->unk_21 = priority;
}

void GameScene::MoveEntityXTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StartActorXMotion(*entity, target, speed_q16);
}

void GameScene::MoveEntityYTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StartActorYMotion(*entity, target, speed_q16);
}

void GameScene::WaitForEntityMovement(u32 id)
{
    GameSceneState * current = state;
    AActorEntity * entity = static_cast<AActorEntity *>(current->game_object.value->GetEntity(id));
    current->waiting_entity = entity;
    if (entity != nullptr)
        current->script_state = 0x16;
}

void GameScene::SetEntityAnim(u32 id, u32 animation)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr && entity->anim_id != animation)
        entity->SetAnim(animation);
}

void GameScene::NoOp014(i32)
{
}

void GameScene::HideEntity(u32 id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        entity->PutOutOfTown();
}

void GameScene::OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr) {
        // This native callback uses the extended +0x30 selector, not the
        // actor's +0x20 facing. It does not write the actor's coordinates.
        HarvestSpriteActor * callback = static_cast<HarvestSpriteActor *>(entity);
        i32 x = entity->GetQ16X() >> 16;
        i32 y = entity->GetQ16Y() >> 16;
        x += delta_x;
        y += delta_y;
        SetEntityUiResource(callback, callback->entry_index, x, y);
    }
}

void GameScene::StartEntityEffect(u32 id, u32 effect, u32 persistent)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StartActorSpriteEffect(*entity, effect, persistent != 0);
}

void GameScene::StopEntityEffect(u32 id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StopActorSpriteEffect(*entity);
}

void GameScene::SetEntityAuxRenderProfile(u32 id, u32 profile)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        SetActorAuxRenderProfile(*entity, profile);
}

void GameScene::ChangeMap(u32 map, i32 x, i32 y)
{
    GameSceneState * current = state;
    current->game_object.value->ChangeMap(Location(map, x, y), true);
    RefreshSceneNpcSchedules(current);
}

void GameScene::PanCameraTo(i32 x, i32 y, u32 speed)
{
    state->game_object.value->PanCameraTo(x, y, speed);
}

void GameScene::WaitForCameraMovement()
{
    GameSceneState * current = state;
    if (!current->game_object.value->IsCameraMovementComplete())
        current->script_state = 0x17;
}

void GameScene::PlayBGM(i32 mode, u32 sequence, GameSceneBgmSettings const & settings)
{
    GameSceneState * current = state;
    StartSceneSong(&current->bgm_player, mode, static_cast<u16>(sequence));
    ApplySceneBgmSettings(settings, &current->bgm_player);
}

void GameScene::StopBGM()
{
    state->bgm_player.Stop();
}

void GameScene::PlaySong(i32 mode, u32 sequence)
{
    HardwareMusicPlayerSlot * player = FindAvailableSceneSongPlayer(state->song_players);
    StartSceneSong(player, mode, static_cast<u16>(sequence));
}

void GameScene::StopAllSongs()
{
    StopAllHardwareMusicPlayers();
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
    "\n"
    "    @ Existing native opening lifecycle, shared by all four regions.\n"
    "    @ C++ matching is pending; do not count this entry as recovered C++.\n"
    "    thumb_func_start TalkOpen__9GameScene\n"
    "TalkOpen__9GameScene: @ 0x080124D0\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    sub sp, #0x14\n"
    "    ldr r7, [r0, #4]\n"
    "    adds r4, r7, #0\n"
    "    adds r4, #0xb4\n"
    "    movs r5, #0\n"
    "    ldr r1, [r4]\n"
    "    cmp r5, r1\n"
    "    beq .L080124F2\n"
    "    cmp r1, #0\n"
    "    beq .L080124F2\n"
    "    ldr r0, [r1, #4]\n"
    "    ldr r2, [r0, #8]\n"
    "    adds r0, r1, #0\n"
    "    movs r1, #3\n"
    "    bl _call_via_r2\n"
    ".L080124F2:\n"
    "    str r5, [r4]\n"
    "    adds r4, r7, #0\n"
    "    adds r4, #0xb8\n"
    "    movs r5, #0\n"
    "    ldr r1, [r4]\n"
    "    cmp r5, r1\n"
    "    beq .L08012510\n"
    "    cmp r1, #0\n"
    "    beq .L08012510\n"
    "    ldr r0, [r1, #4]\n"
    "    ldr r2, [r0, #8]\n"
    "    adds r0, r1, #0\n"
    "    movs r1, #3\n"
    "    bl _call_via_r2\n"
    ".L08012510:\n"
    "    str r5, [r4]\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #0xac\n"
    "    ldr r5, [r0]\n"
    "    adds r6, r0, #0\n"
    "    cmp r5, #0\n"
    "    bne .L080125CA\n"
    "    adds r0, #0x3c\n"
    "    ldrb r0, [r0]\n"
    "    cmp r0, #0\n"
    "    bne .L0801257A\n"
    "    movs r0, #4\n"
    "    bl __builtin_new\n"
    "    adds r4, r0, #0\n"
    "    add r0, sp, #0xc\n"
    "    bl __17ObjTileCollection\n"
    "    add r0, sp, #0x10\n"
    "    bl __20ObjPaletteCollection\n"
    "    add r1, sp, #0x10\n"
    "    movs r0, #1\n"
    "    str r0, [sp]\n"
    "    add r0, sp, #0xc\n"
    "    str r0, [sp, #4]\n"
    "    str r1, [sp, #8]\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #0\n"
    "    movs r2, #0x1f\n"
    "    movs r3, #0\n"
    "    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "    adds r5, r6, #0\n"
    "    adds r4, r0, #0\n"
    "    ldr r0, [r6]\n"
    "    cmp r4, r0\n"
    "    beq .L08012566\n"
    "    cmp r0, #0\n"
    "    beq .L08012566\n"
    "    movs r1, #3\n"
    "    bl _._12UiStateOwner\n"
    ".L08012566:\n"
    "    str r4, [r5]\n"
    "    add r0, sp, #0x10\n"
    "    movs r1, #2\n"
    "    bl _._20ObjPaletteCollection\n"
    "    add r0, sp, #0xc\n"
    "    movs r1, #2\n"
    "    bl _._17ObjTileCollection\n"
    "    b .L080125CA\n"
    ".L0801257A:\n"
    "    movs r0, #4\n"
    "    bl __builtin_new\n"
    "    adds r4, r0, #0\n"
    "    add r0, sp, #0xc\n"
    "    bl __17ObjTileCollection\n"
    "    add r0, sp, #0x10\n"
    "    bl __20ObjPaletteCollection\n"
    "    add r0, sp, #0x10\n"
    "    str r5, [sp]\n"
    "    add r1, sp, #0xc\n"
    "    str r1, [sp, #4]\n"
    "    str r0, [sp, #8]\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #0\n"
    "    movs r2, #0x1f\n"
    "    movs r3, #0\n"
    "    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "    adds r5, r6, #0\n"
    "    adds r4, r0, #0\n"
    "    ldr r0, [r6]\n"
    "    cmp r4, r0\n"
    "    beq .L080125B8\n"
    "    cmp r0, #0\n"
    "    beq .L080125B8\n"
    "    movs r1, #3\n"
    "    bl _._12UiStateOwner\n"
    ".L080125B8:\n"
    "    str r4, [r5]\n"
    "    add r0, sp, #0x10\n"
    "    movs r1, #2\n"
    "    bl _._20ObjPaletteCollection\n"
    "    add r0, sp, #0xc\n"
    "    movs r1, #2\n"
    "    bl _._17ObjTileCollection\n"
    ".L080125CA:\n"
    "    ldr r0, [r6]\n"
    "    bl GetState__C12UiStateOwner\n"
    "    cmp r0, #3\n"
    "    beq .L080125E2\n"
    "    ldr r0, [r6]\n"
    "    bl func_08050D5C\n"
    "    adds r1, r7, #0\n"
    "    adds r1, #0x9c\n"
    "    movs r0, #0xe\n"
    "    str r0, [r1]\n"
    ".L080125E2:\n"
    "    add sp, #0x14\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);



void GameScene::TalkResetUi()
{
    GameSceneState * current = state;
    current->time_window = nullptr;
    current->pause_menu_selector = nullptr;
    current->talk_window = nullptr;
    current->display.control.dispcnt &= ~DISPCNT_BG0_ON;
}

void GameScene::TalkClose()
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050D74(reinterpret_cast<void * const *>(current->talk_window.Get()));
        ClearSceneDialogueNameplate(current);
        ClearSceneDialoguePortrait(current);
        HideSceneDialogueHeartIndicator(current);
        current->script_state = 0x0F;
    }
}

void GameScene::TalkMessage(char const * text, u32 rate)
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050DC8(reinterpret_cast<void * const *>(current->talk_window.Get()),
            reinterpret_cast<u32>(text), static_cast<u16>(rate), reinterpret_cast<u32>(current->text_variables.value));
        current->script_state = 0x10;
    }
}

void GameScene::TalkTelevisionMessage(char const * text)
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050DC8(reinterpret_cast<void * const *>(current->talk_window.Get()),
            reinterpret_cast<u32>(text), 0x40, reinterpret_cast<u32>(current->text_variables.value));
        // Television uses a separate completion state, not slow dialogue.
        current->script_state = 0x11;
    }
}

void GameScene::TalkSetNameplateCharacter(u32 id)
{
    GameSceneState * current = state;
    UiStateOwner * window = current->talk_window.Get();
    if (window != nullptr && current->save->display_options.show_nameplate) {
        char const * name = current->save->npcs.GetCharacterName(id);
        func_08050E68(reinterpret_cast<void * const *>(window), name);
    }
}

void GameScene::TalkSetNameplateText(char const * text)
{
    GameSceneState * current = state;
    UiStateOwner * window = current->talk_window.Get();
    if (window != nullptr && current->save->display_options.show_nameplate)
        func_08050E68(reinterpret_cast<void * const *>(window), text);
}

void GameScene::TalkClearNameplate()
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E74(reinterpret_cast<void * const *>(window));
}

void GameScene::TalkSetPortrait(u32 id)
{
    GameSceneState * current = state;
    UiStateOwner * window = current->talk_window.Get();
    if (window != nullptr && current->save->display_options.show_portrait)
        window->ShowPortrait(id);
}

void GameScene::TalkClearPortrait()
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E5C(reinterpret_cast<void * const *>(window));
}

void GameScene::TalkShowHeartIndicator(u32 id)
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr &&
        current->save->display_options.show_portrait &&
        id != CHARACTER_HARVEST_GODDESS) {
        Bachelorette * girl = current->save->npcs.GetBachelorette(id);
        if (girl != nullptr) {
            u32 love = girl->GetLove();
            u32 heart;
            if (love >= LOVE_HEART_RED_MIN) heart = 6;
            else if (love >= LOVE_HEART_ORANGE_MIN) heart = 5;
            else if (love >= LOVE_HEART_YELLOW_MIN) heart = 4;
            else if (love >= LOVE_HEART_GREEN_MIN) heart = 3;
            else if (love >= LOVE_HEART_BLUE_MIN) heart = 2;
            else if (love >= LOVE_HEART_PURPLE_MIN) heart = 1;
            else heart = 0;
            current->talk_window.Get()->ShowHeartIndicator(heart);
        }
    }
}

void GameScene::TalkHideHeartIndicator()
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        window->HideHeartIndicator();
}

void GameScene::TalkPromptChoices(char const * prompt, char const * first, char const * second,
    char const * third, char const * fourth)
{
    GameSceneState * current = state;
    // A missing optional row terminates the list, even if later rows exist.
    if (current->talk_window.Get() != nullptr && first != nullptr && second != nullptr) {
        if (third == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E30(current->talk_window.Get(),
                prompt, first, second,
                0, 0, variables);
        } else if (fourth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E30(current->talk_window.Get(),
                prompt, first, second,
                third, 0, variables);
        } else {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E30(current->talk_window.Get(),
                prompt, first, second,
                third, fourth, variables);
        }
        current->script_state = 0x14;
    }
}

void GameScene::TalkChoices(char const * first, char const * second, char const * third,
    char const * fourth, char const * fifth, char const * sixth)
{
    GameSceneState * current = state;
    // A missing optional row terminates the list, even if later rows exist.
    if (current->talk_window.Get() != nullptr && first != nullptr && second != nullptr) {
        if (third == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E0C(current->talk_window.Get(), first,
                second, 0, 0, 0, 0, variables);
        } else if (fourth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, 0, 0, 0, variables);
        } else if (fifth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, fourth,
                0, 0, variables);
        } else if (sixth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, fourth,
                fifth, 0, variables);
        } else {
            ScriptTextVariableStore * variables = current->text_variables.value;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, fourth,
                fifth, sixth, variables);
        }
        current->script_state = 0x14;
    }
}

void GameScene::FadeScreen(u32 style, i32 speed, bool fade_out, bool call_scene_hook)
{
    GameSceneState * current = state;
    u32 mode, mosaic;
    switch (style) {
    case SCREEN_FADE_STYLE_BLACK: mode = 2; mosaic = 0; break;
    case SCREEN_FADE_STYLE_WHITE: mode = 1; mosaic = 0; break;
    case SCREEN_FADE_STYLE_BLACK_MOSAIC: mode = 2; mosaic = 1; break;
    case SCREEN_FADE_STYLE_WHITE_MOSAIC: mode = 1; mosaic = 1; break;
    case SCREEN_FADE_STYLE_MOSAIC: mode = 0; mosaic = 1; break;
    default: return;
    }
    i16 step;
    switch (speed) {
    case SCREEN_FADE_SPEED_FAST: step = 0x1112; break;
    case SCREEN_FADE_SPEED_NORMAL: step = 0x0889; break;
    case SCREEN_FADE_SPEED_SLOW: step = 0x0444; break;
    default: return;
    }
    // Start the original direction-specific controller and wait state.
    if (fade_out != 0) {
        EndHardwareBlend(current->screen_blend.value, step, mode, mosaic);
        current->script_state = 0x12;
        current->unk_E8 = 0;
        current->unk_E9 = mode == 2;
    } else {
        // The third callable uses this same path but suppresses the hook.
        if (call_scene_hook != 0)
            current->game_object.value->RefreshMapTimeOfDayPalette();
        BeginHardwareBlend(current->screen_blend.value, step, mode, mosaic);
        current->script_state = 0x13;
        current->unk_E8 = fade_out;
        current->unk_E9 = mode == 2;
        // Keep native halfword writes: these are the DISPCNT and BLDCNT
        // shadows, not an unrelated scene flag word or a 32-bit update.
        WriteHardwareDisplayHalfword(current->display.control.dispcnt,
            ReadHardwareDisplayHalfword(current->display.control.dispcnt)
                | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
        if (mode == 1)
            WriteHardwareDisplayHalfword(current->display.blend_control,
                ReadHardwareDisplayHalfword(current->display.blend_control) | BLDCNT_EFFECT_LIGHTEN);
        else
            WriteHardwareDisplayHalfword(current->display.blend_control,
                ReadHardwareDisplayHalfword(current->display.blend_control) | BLDCNT_EFFECT_DARKEN);
    }
}

void GameScene::TextVariableSetNumber(u32 slot, i32 value)
{
    GameSceneState * current = state;
    // Preserve the native temporary and regional formatter, without a new clamp.
    char text[52];
#if defined(REGION_JP)
    FormatFullWidthDecimal(value, text, 0);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    FormatSignedDecimal(value, text, 0);
#endif
    current->text_variables.value->Set(slot, text);
}

void GameScene::TextVariableSetString(u32 slot, char const * text)
{
    state->text_variables.value->Set(slot, text);
}

void GameScene::TextVariableSetNumberFieldWidth(u32 slot, i32 value, u32 width)
{
    GameSceneState * current = state;
    // Preserve the native temporary and regional formatter, without a new clamp.
    char text[52];
#if defined(REGION_JP)
    FormatFullWidthDecimal(value, text, width);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    FormatSignedDecimal(value, text, width);
#endif
    current->text_variables.value->Set(slot, text);
}

void GameScene::CallScript(i32 script_id, i32 context_value)
{
    GameSceneState * current = state;
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    controller->script_engine.LoadById(script_id, context_value);
    SuspendSceneWorldForScript(current);
}

void GameScene::QueueScript(GameSceneScriptRequest const & request, i32 queue_kind)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    GameSceneScriptQueue<2> & first = controller->queues.queue_0;
    switch (queue_kind) {
    case 0: first.Push(request); break;
    case 1: controller->queues.queue_1.Push(request); break;
    case 2: controller->queues.queue_2.Push(request); break;
    }
}

void GameScene::WaitFrames(i32 frames)
{
    GameSceneState * current = state;
    // Retain only the low halfword. Zero is not an immediate completion.
    current->wait_frames = frames;
    current->script_state = 0x15;
}

void GameScene::OpenSupermarketShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SUPERMARKET_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SupermarketTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenSupermarketPurchase(MarySupermarketItemId item)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SUPERMARKET_PURCHASE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SupermarketPurchaseTransition(continuation, current->save, item);
    current->script_state = 0x18;
}

void GameScene::OpenWonShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_WON_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new WonShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenCarpenterShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CARPENTER_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CarpenterShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenBlacksmithShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_BLACKSMITH_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new BlacksmithShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenClinicShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CLINIC_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ClinicShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenBeachCafeShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_BEACH_CAFE_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new BeachCafeShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenYodelRanchShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_YODEL_RANCH_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new YodelRanchShopTransition(continuation, current->save, 0);
    current->script_state = 0x18;
}

void GameScene::OpenWineryShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_WINERY_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new WineryShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenInnShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_INN_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new InnShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenPoultryFarmShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_POULTRY_FARM_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new PoultryFarmShopTransition(continuation, current->save, 0);
    current->script_state = 0x18;
}

void GameScene::OpenSpecialMerchantShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SPECIAL_MERCHANT_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SpecialMerchantShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenGiftWrappingMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_GIFT_WRAPPING);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new GiftWrappingTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::ShowReferencePage(i32 page_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(continuation, current->save, page_id);
    current->script_state = 0x18;
}

void GameScene::OpenBookList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(
        continuation, current->save, ReferencePageScene::BOOK_LIST);
    current->script_state = 0x18;
}

void GameScene::OpenLetterList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(
        continuation, current->save, ReferencePageScene::LETTER_LIST);
    current->script_state = 0x18;
}

void GameScene::OpenCalendar()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CALENDAR);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CalendarTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenToolChest()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_TOOL_CHEST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ToolChestTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenRefrigerator()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFRIGERATOR);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new RefrigeratorTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenShelf()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SHELF);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ShelfTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenClock()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CLOCK);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ClockTransition(current->save, continuation);
    current->script_state = 0x18;
}

void GameScene::OpenCookingMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_COOKING_MENU);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CookingTransition(continuation, current->save, false);
    current->script_state = 0x18;
}

void GameScene::OpenRecipeList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_RECIPE_LIST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CookingTransition(continuation, current->save, true);
    current->script_state = 0x18;
}

void GameScene::RunGameCubeLink()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_GAMECUBE_LINK);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new GameCubeLinkTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::RunHarvestSpriteAnimalCareMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_ANIMALCARE_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteAnimalCareTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

void GameScene::RunHarvestSpriteHarvestingMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_HARVESTING_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteHarvestingTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

void GameScene::RunHarvestSpriteWateringMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_WATERING_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteWateringTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

void GameScene::StartFarmInheritanceFlashback()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FARM_INHERITANCE_FLASHBACK);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new IntroStoryTransition(next, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenRucksackMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_RUCKSACK_MENU);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new RucksackMenuTransition(next, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenTownMap(u8 allow_teleport)
{
    GameSceneState * current = state;
    current->pending_transition = new TownMapTransition(allow_teleport ? 2 : 0, current->GetSave());
    current->script_state = 0x18;
}

void GameScene::SelectFestivalAnimal(MaryFestivalAnimalKind kind)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FESTIVAL_ANIMAL_SELECTION);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FestivalAnimalSelectionTransition(next, current->save, kind);
    current->script_state = 0x18;
}

void GameScene::RunStaffCredits()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_STAFF_CREDITS);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new StaffCreditsTransition(next);
    current->script_state = 0x18;
}

void GameScene::OpenFarmingTutorial(MaryFarmingTutorialKind kind)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FARMING_TUTORIAL);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FarmingTutorialTransition(next, kind);
    current->script_state = 0x18;
}

void GameScene::OpenNameEntry(MaryNameEntryKind kind, MaryNameEntryTargetIndex target_index)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_NAME_ENTRY);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SavedNameEntryTransition(next, current->save, kind, target_index);
    current->script_state = 0x18;
}

void GameScene::PrepareClockMenuTransition()
{
    state->game_object.value->PrepareClockMenuTransition();
}

void GameScene::RestoreAfterClockMenu()
{
    state->game_object.value->RestoreAfterClockMenu();
}

void GameScene::PrepareCookingMenuTransition()
{
    state->game_object.value->PrepareCookingMenuTransition();
}

void GameScene::RestoreAfterCookingMenu()
{
    state->game_object.value->RestoreAfterCookingMenu();
}

void GameScene::PrepareRecipeMenuTransition()
{
    state->game_object.value->PrepareRecipeMenuTransition();
}

void GameScene::RestoreAfterRecipeMenu()
{
    state->game_object.value->RestoreAfterRecipeMenu();
}

void GameScene::RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough)
{
    state->game_object.value->RefreshBarnFeedTrough(trough);
}

void GameScene::RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough)
{
    state->game_object.value->RefreshChickenFeedTrough(trough);
}

void GameScene::StartShipmentBoxDepositAnimation()
{
    state->game_object.value->StartShipmentBoxDepositAnimation();
}

bool GameScene::IsPlayerRidingHorse()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))->IsRidingHorse();
}

bool GameScene::TryShipPlayerHeldItem()
{
    GameSceneState * current = state;
    bool result;
    if (static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))->TryShipHeldItem()) {
        current->script_state = 0x19;
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool GameScene::SetPlayerHeldItem(RucksackItem const & item, bool wrapped)
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))->SetHeldItem(item, wrapped);
    current->script_state = 0x19;
    return true;
}

bool GameScene::GivePlayerBasket()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))->GiveBasket();
    current->script_state = 0x19;
    return true;
}

void GameScene::ThrowPlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))->ThrowHeldItem();
    current->script_state = 0x19;
}

void GameScene::UsePlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))->UseHeldItem();
    current->script_state = 0x19;
}

void GameScene::ClearPlayerHeldItem()
{
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))->ClearHeldItem();
}

MaryItemArticleId GameScene::RemoveRecordPlayerAlbum()
{
    return state->game_object.value->RemoveRecordPlayerAlbum();
}

MaryItemArticleId GameScene::SwapRecordPlayerAlbum(MaryItemArticleId article)
{
    return state->game_object.value->SwapRecordPlayerAlbum(article);
}

void GameScene::SetEntityEventScript(u32 entity_id, MaryScriptId script_id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(entity_id));
    if (entity != nullptr)
        entity->SetEventScript(script_id);
}

void GameScene::ClearEntityEventScript(u32 entity_id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(entity_id));
    if (entity != nullptr)
        entity->SetEventScript(0);
}

void GameScene::SetTelevisionProgram(MaryTelevisionProgramId program)
{
    state->game_object.value->SetTelevisionProgram(program);
}

void GameScene::EndTelevisionProgram()
{
    state->game_object.value->EndTelevisionProgram();
}

void GameScene::EnableScriptedNpcControl()
{
    state->save->scripted_npc_control = 1;
}

void GameScene::DisableScriptedNpcControl()
{
    state->save->scripted_npc_control = 0;
}

static inline bool IsSceneClockColonVisible(GameSceneState * current)
{
    bool visible = false;
    if (current->game_object.value->IsTimePaused()
        || (current->save->clock.calendar.time.clock_minute & 1) != 0)
        visible = true;
    return visible;
}

void GameScene::SetGameTime(GameTime const & time)
{
    GameSceneState * current = state;
    current->game_object.value->vfunc_BC(time);
    if (current->time_window.value != nullptr)
    {
        MapClockStatusHudWidget * clock = current->time_window.value;
        bool show_colon = IsSceneClockColonVisible(current);
        clock->UpdateCalendar(current->save->clock.calendar, show_colon);
    }
    RefreshSceneNpcSchedules(current);
}

void GameScene::RunChickenFestivalContest()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CHICKEN_FESTIVAL_CONTEST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ChickenFestivalContestTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::RunHorseRace(MaryFestivalHorseRaceMode mode)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HORSE_RACE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HorseRaceTransition(continuation, current->save,
        mode != FESTIVAL_HORSE_RACE_MODE_BETTING);
    current->script_state = 0x18;
}

void GameScene::OpenHorseRaceMedalExchange()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HORSE_RACE_MEDAL_EXCHANGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HorseRaceMedalExchangeTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::RunFrisbeeGame(bool contest)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FRISBEE_GAME);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FrisbeeTransition(continuation, current->save, contest);
    current->script_state = 0x18;
}

void GameScene::ShowFrisbeeScoreboard()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FRISBEE_SCOREBOARD);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FrisbeeScoreboardTransition(continuation, current->save);
    current->script_state = 0x18;
}

EC GameSceneSongPlayerPool & GetSceneSongPlayerPool(GameScene & scene)
{
    return scene.state->song_players;
}

void GameScene::LightFireplaceAtLocation(MaryMapId map)
{
    static_cast<GameSceneWorld *>(state->game_object.value)->LightFireplaceAtLocation(map);
}

void GameScene::SetVaseArticleId(MaryItemArticleId article)
{
    static_cast<GameSceneWorld *>(state->game_object.value)->SetVaseArticleId(article);
}

void GameScene::BeginEggIncubation(MaryChickenCoopIncubatorIndex incubator)
{
    GameSceneState * current = state;
    // Storage checks capacity, but the native refresh still receives the
    // original full-width index even when that storage operation rejects it.
    current->save->farm.coop.BeginIncubation(incubator);
    current->game_object.value->RefreshChickenCoopIncubator(incubator);
}

asm_unified(
    ".text\n"
    "\n"
    "    @ Packed RGB flash setup; the three channels are packed by VM 0x127.\n"
    "    @ This verified common native body remains assembly, not recovered C++.\n"
    "    thumb_func_start FlashScreenColor__9GameSceneUi\n"
    "FlashScreenColor__9GameSceneUi:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0x54\n"
    "    ldr r5, [r0, #4]\n"
    "    adds r0, r5, #0\n"
    "    adds r0, #0xea\n"
    "    movs r4, #1\n"
    "    strb r4, [r0]\n"
    "    adds r3, r5, #0\n"
    "    adds r3, #0xec\n"
    "    strh r1, [r3]\n"
    "    adds r2, r5, #0\n"
    "    adds r2, #0x10\n"
    "    ldrh r0, [r5, #0x10]\n"
    "    movs r6, #0x80\n"
    "    lsls r6, r6, #1\n"
    "    adds r1, r6, #0\n"
    "    orrs r0, r1\n"
    "    strh r0, [r5, #0x10]\n"
    "    mov r1, sp\n"
    "    ldr r0, .L080147A4 @ =0x00001F0C\n"
    "    strh r0, [r1]\n"
    "    strh r0, [r5, #0x18]\n"
    "    mov r0, sp\n"
    "    movs r7, #0\n"
    "    strh r7, [r0]\n"
    "    movs r0, #0\n"
    "    strh r0, [r2, #0x10]\n"
    "    mov r0, sp\n"
    "    movs r1, #0\n"
    "    strh r1, [r0]\n"
    "    strh r1, [r5, #0x22]\n"
    "    ldrh r1, [r3]\n"
    "    mov r8, r5\n"
    "    add r0, sp, #4\n"
    "    ldr r2, .L080147A8\n"
    "    movs r3, #2\n"
    "    bl __21DmaTransferDescriptorUiPvUi\n"
    "    add r2, sp, #4\n"
    "    mov sb, r2\n"
    "    ldr r1, [r5, #4]\n"
    "    ldr r0, [r5, #0xc]\n"
    "    cmp r1, r0\n"
    "    beq .L080147AC\n"
    "    cmp r1, #0\n"
    "    beq .L0801476C\n"
    "    adds r0, r1, #0\n"
    "    mov r1, sb\n"
    "    ldm r1!, {r3, r4, r6}\n"
    "    stm r0!, {r3, r4, r6}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L0801476C:\n"
    "    ldr r0, [r5, #4]\n"
    "    adds r0, #0x10\n"
    "    str r0, [r5, #4]\n"
    "    movs r7, #3\n"
    "    lsls r7, r7, #9\n"
    "    str r7, [sp, #0x38]\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #0x3c]\n"
    "    movs r1, #0x1f\n"
    "    lsls r1, r1, #0xb\n"
    "    str r1, [sp, #0x40]\n"
    "    adds r2, r5, #0\n"
    "    adds r2, #0x60\n"
    "    str r2, [sp, #0x44]\n"
    "    adds r3, r5, #0\n"
    "    adds r3, #0xee\n"
    "    str r3, [sp, #0x30]\n"
    "    adds r4, r5, #0\n"
    "    adds r4, #0x62\n"
    "    str r4, [sp, #0x48]\n"
    "    adds r6, r5, #0\n"
    "    adds r6, #0xef\n"
    "    str r6, [sp, #0x34]\n"
    "    adds r7, r5, #0\n"
    "    adds r7, #0x9c\n"
    "    str r7, [sp, #0x2c]\n"
    "    b .L080148A0\n"
    "    .align 2, 0\n"
    ".L080147A4: .word 0x00001F0C\n"
    ".L080147A8: .word BG_PLTT + 2\n"
    ".L080147AC:\n"
    "    str r1, [sp, #0x4c]\n"
    "    str r4, [sp, #0x18]\n"
    "    ldr r0, [r5]\n"
    "    subs r0, r1, r0\n"
    "    asrs r4, r0, #4\n"
    "    str r4, [sp, #0x14]\n"
    "    add r1, sp, #0x18\n"
    "    add r0, sp, #0x14\n"
    "    cmp r4, #1\n"
    "    bhs .L080147C2\n"
    "    adds r0, r1, #0\n"
    ".L080147C2:\n"
    "    ldr r0, [r0]\n"
    "    adds r0, r4, r0\n"
    "    cmp r0, #0\n"
    "    beq .L080147E0\n"
    "    lsls r4, r0, #4\n"
    "    adds r0, r4, #0\n"
    "    bl malloc\n"
    "    mov sl, r4\n"
    "    cmp r0, #0\n"
    "    bne .L080147E4\n"
    "    mov r0, sl\n"
    "    bl RetryMemoryAllocation\n"
    "    b .L080147E4\n"
    ".L080147E0:\n"
    "    movs r0, #0\n"
    "    mov sl, r0\n"
    ".L080147E4:\n"
    "    adds r4, r0, #0\n"
    "    str r4, [sp, #0x50]\n"
    "    mov r3, r8\n"
    "    ldr r2, [r3]\n"
    "    adds r3, r4, #0\n"
    "    movs r4, #3\n"
    "    lsls r4, r4, #9\n"
    "    str r4, [sp, #0x38]\n"
    "    movs r6, #0\n"
    "    lsls r6, r6, #0xc\n"
    "    str r6, [sp, #0x3c]\n"
    "    movs r7, #0x1f\n"
    "    lsls r7, r7, #0xb\n"
    "    str r7, [sp, #0x40]\n"
    "    adds r0, r5, #0\n"
    "    adds r0, #0x60\n"
    "    str r0, [sp, #0x44]\n"
    "    adds r1, r5, #0\n"
    "    adds r1, #0xee\n"
    "    str r1, [sp, #0x30]\n"
    "    adds r4, r5, #0\n"
    "    adds r4, #0x62\n"
    "    str r4, [sp, #0x48]\n"
    "    adds r6, r5, #0\n"
    "    adds r6, #0xef\n"
    "    str r6, [sp, #0x34]\n"
    "    adds r7, r5, #0\n"
    "    adds r7, #0x9c\n"
    "    str r7, [sp, #0x2c]\n"
    "    b .L08014834\n"
    ".L08014820:\n"
    "    cmp r3, #0\n"
    "    beq .L08014830\n"
    "    adds r0, r3, #0\n"
    "    adds r1, r2, #0\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014830:\n"
    "    adds r2, #0x10\n"
    "    adds r3, #0x10\n"
    ".L08014834:\n"
    "    ldr r0, [sp, #0x4c]\n"
    "    cmp r2, r0\n"
    "    bne .L08014820\n"
    "    adds r4, r3, #0\n"
    "    ldr r0, [sp, #0x18]\n"
    "    cmp r0, #1\n"
    "    bne .L08014856\n"
    "    cmp r4, #0\n"
    "    beq .L08014852\n"
    "    adds r0, r4, #0\n"
    "    mov r1, sb\n"
    "    ldm r1!, {r2, r3, r6}\n"
    "    stm r0!, {r2, r3, r6}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014852:\n"
    "    adds r4, #0x10\n"
    "    b .L08014878\n"
    ".L08014856:\n"
    "    adds r3, r0, #0\n"
    "    adds r2, r4, #0\n"
    "    cmp r3, #0\n"
    "    beq .L08014876\n"
    ".L0801485E:\n"
    "    cmp r2, #0\n"
    "    beq .L0801486E\n"
    "    adds r0, r2, #0\n"
    "    mov r1, sb\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L0801486E:\n"
    "    subs r3, #1\n"
    "    adds r2, #0x10\n"
    "    cmp r3, #0\n"
    "    bne .L0801485E\n"
    ".L08014876:\n"
    "    adds r4, r2, #0\n"
    ".L08014878:\n"
    "    mov r7, r8\n"
    "    ldr r2, [r7, #4]\n"
    "    ldr r0, [r7]\n"
    "    adds r1, r0, #0\n"
    "    cmp r0, r2\n"
    "    beq .L0801488A\n"
    ".L08014884:\n"
    "    adds r1, #0x10\n"
    "    cmp r1, r2\n"
    "    bne .L08014884\n"
    ".L0801488A:\n"
    "    cmp r0, #0\n"
    "    beq .L08014892\n"
    "    bl free\n"
    ".L08014892:\n"
    "    ldr r0, [sp, #0x50]\n"
    "    add r0, sl\n"
    "    ldr r1, [sp, #0x50]\n"
    "    mov r2, r8\n"
    "    str r1, [r2]\n"
    "    str r4, [r2, #4]\n"
    "    str r0, [r2, #0xc]\n"
    ".L080148A0:\n"
    "    ldr r1, .L080148E0 @ =0x11111111\n"
    "    ldr r3, [sp, #0x38]\n"
    "    movs r4, #0xf4\n"
    "    lsls r4, r4, #1\n"
    "    adds r2, r3, r4\n"
    "    mov r8, r5\n"
    "    lsls r2, r2, #5\n"
    "    movs r6, #0xc0\n"
    "    lsls r6, r6, #0x13\n"
    "    adds r2, r2, r6\n"
    "    mov r0, sp\n"
    "    movs r3, #0x20\n"
    "    bl __21DmaTransferDescriptorUiPvUi\n"
    "    mov sl, sp\n"
    "    ldr r1, [r5, #4]\n"
    "    ldr r0, [r5, #0xc]\n"
    "    cmp r1, r0\n"
    "    beq .L080148E4\n"
    "    cmp r1, #0\n"
    "    beq .L080148D6\n"
    "    adds r0, r1, #0\n"
    "    mov r1, sp\n"
    "    ldm r1!, {r2, r3, r7}\n"
    "    stm r0!, {r2, r3, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L080148D6:\n"
    "    ldr r0, [r5, #4]\n"
    "    adds r0, #0x10\n"
    "    str r0, [r5, #4]\n"
    "    b .L080149B0\n"
    "    .align 2, 0\n"
    ".L080148E0: .word 0x11111111\n"
    ".L080148E4:\n"
    "    str r1, [sp, #0x4c]\n"
    "    movs r0, #1\n"
    "    str r0, [sp, #0x20]\n"
    "    ldr r0, [r5]\n"
    "    adds r4, r1, #0\n"
    "    subs r0, r4, r0\n"
    "    asrs r4, r0, #4\n"
    "    str r4, [sp, #0x1c]\n"
    "    add r1, sp, #0x20\n"
    "    add r0, sp, #0x1c\n"
    "    cmp r4, #1\n"
    "    bhs .L080148FE\n"
    "    adds r0, r1, #0\n"
    ".L080148FE:\n"
    "    ldr r0, [r0]\n"
    "    adds r0, r4, r0\n"
    "    cmp r0, #0\n"
    "    beq .L0801491C\n"
    "    lsls r4, r0, #4\n"
    "    adds r0, r4, #0\n"
    "    bl malloc\n"
    "    mov sb, r4\n"
    "    cmp r0, #0\n"
    "    bne .L08014920\n"
    "    mov r0, sb\n"
    "    bl RetryMemoryAllocation\n"
    "    b .L08014920\n"
    ".L0801491C:\n"
    "    movs r0, #0\n"
    "    mov sb, r0\n"
    ".L08014920:\n"
    "    adds r4, r0, #0\n"
    "    str r4, [sp, #0x50]\n"
    "    mov r6, r8\n"
    "    ldr r2, [r6]\n"
    "    adds r3, r4, #0\n"
    "    ldr r7, [sp, #0x4c]\n"
    "    cmp r2, r7\n"
    "    beq .L0801494A\n"
    ".L08014930:\n"
    "    cmp r3, #0\n"
    "    beq .L08014940\n"
    "    adds r0, r3, #0\n"
    "    adds r1, r2, #0\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014940:\n"
    "    adds r2, #0x10\n"
    "    adds r3, #0x10\n"
    "    ldr r0, [sp, #0x4c]\n"
    "    cmp r2, r0\n"
    "    bne .L08014930\n"
    ".L0801494A:\n"
    "    adds r4, r3, #0\n"
    "    ldr r0, [sp, #0x20]\n"
    "    cmp r0, #1\n"
    "    bne .L08014966\n"
    "    cmp r4, #0\n"
    "    beq .L08014962\n"
    "    adds r0, r4, #0\n"
    "    mov r1, sl\n"
    "    ldm r1!, {r2, r3, r6}\n"
    "    stm r0!, {r2, r3, r6}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014962:\n"
    "    adds r4, #0x10\n"
    "    b .L08014988\n"
    ".L08014966:\n"
    "    adds r3, r0, #0\n"
    "    adds r2, r4, #0\n"
    "    cmp r3, #0\n"
    "    beq .L08014986\n"
    ".L0801496E:\n"
    "    cmp r2, #0\n"
    "    beq .L0801497E\n"
    "    adds r0, r2, #0\n"
    "    mov r1, sl\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L0801497E:\n"
    "    subs r3, #1\n"
    "    adds r2, #0x10\n"
    "    cmp r3, #0\n"
    "    bne .L0801496E\n"
    ".L08014986:\n"
    "    adds r4, r2, #0\n"
    ".L08014988:\n"
    "    mov r7, r8\n"
    "    ldr r2, [r7, #4]\n"
    "    ldr r0, [r7]\n"
    "    adds r1, r0, #0\n"
    "    cmp r0, r2\n"
    "    beq .L0801499A\n"
    ".L08014994:\n"
    "    adds r1, #0x10\n"
    "    cmp r1, r2\n"
    "    bne .L08014994\n"
    ".L0801499A:\n"
    "    cmp r0, #0\n"
    "    beq .L080149A2\n"
    "    bl free\n"
    ".L080149A2:\n"
    "    ldr r0, [sp, #0x50]\n"
    "    add r0, sb\n"
    "    ldr r1, [sp, #0x50]\n"
    "    mov r2, r8\n"
    "    str r1, [r2]\n"
    "    str r4, [r2, #4]\n"
    "    str r0, [r2, #0xc]\n"
    ".L080149B0:\n"
    "    movs r3, #0xf0\n"
    "    lsls r3, r3, #8\n"
    "    adds r0, r3, #0\n"
    "    ldr r1, [sp, #0x3c]\n"
    "    ands r1, r0\n"
    "    movs r4, #0xf4\n"
    "    lsls r4, r4, #1\n"
    "    orrs r1, r4\n"
    "    lsls r0, r1, #0x10\n"
    "    orrs r1, r0\n"
    "    ldr r6, [sp, #0x40]\n"
    "    movs r7, #0xc0\n"
    "    lsls r7, r7, #0x13\n"
    "    adds r2, r6, r7\n"
    "    mov r0, sp\n"
    "    movs r3, #0xa0\n"
    "    lsls r3, r3, #3\n"
    "    bl __21DmaTransferDescriptorUiPvUi\n"
    "    mov sb, sp\n"
    "    ldr r1, [r5, #4]\n"
    "    ldr r0, [r5, #0xc]\n"
    "    cmp r1, r0\n"
    "    beq .L080149F8\n"
    "    cmp r1, #0\n"
    "    beq .L080149F0\n"
    "    adds r0, r1, #0\n"
    "    mov r1, sp\n"
    "    ldm r1!, {r2, r3, r4}\n"
    "    stm r0!, {r2, r3, r4}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L080149F0:\n"
    "    ldr r0, [r5, #4]\n"
    "    adds r0, #0x10\n"
    "    str r0, [r5, #4]\n"
    "    b .L08014AB8\n"
    ".L080149F8:\n"
    "    mov sl, r1\n"
    "    movs r0, #1\n"
    "    str r0, [sp, #0x28]\n"
    "    ldr r0, [r5]\n"
    "    subs r0, r1, r0\n"
    "    asrs r4, r0, #4\n"
    "    str r4, [sp, #0x24]\n"
    "    add r1, sp, #0x28\n"
    "    add r0, sp, #0x24\n"
    "    cmp r4, #1\n"
    "    bhs .L08014A10\n"
    "    adds r0, r1, #0\n"
    ".L08014A10:\n"
    "    ldr r0, [r0]\n"
    "    adds r0, r4, r0\n"
    "    cmp r0, #0\n"
    "    beq .L08014A2E\n"
    "    lsls r4, r0, #4\n"
    "    adds r0, r4, #0\n"
    "    bl malloc\n"
    "    mov r8, r4\n"
    "    cmp r0, #0\n"
    "    bne .L08014A32\n"
    "    mov r0, r8\n"
    "    bl RetryMemoryAllocation\n"
    "    b .L08014A32\n"
    ".L08014A2E:\n"
    "    movs r0, #0\n"
    "    mov r8, r0\n"
    ".L08014A32:\n"
    "    adds r4, r0, #0\n"
    "    str r4, [sp, #0x50]\n"
    "    ldr r2, [r5]\n"
    "    adds r3, r4, #0\n"
    "    cmp r2, sl\n"
    "    beq .L08014A56\n"
    ".L08014A3E:\n"
    "    cmp r3, #0\n"
    "    beq .L08014A4E\n"
    "    adds r0, r3, #0\n"
    "    adds r1, r2, #0\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014A4E:\n"
    "    adds r2, #0x10\n"
    "    adds r3, #0x10\n"
    "    cmp r2, sl\n"
    "    bne .L08014A3E\n"
    ".L08014A56:\n"
    "    adds r4, r3, #0\n"
    "    ldr r0, [sp, #0x28]\n"
    "    cmp r0, #1\n"
    "    bne .L08014A72\n"
    "    cmp r4, #0\n"
    "    beq .L08014A6E\n"
    "    adds r0, r4, #0\n"
    "    mov r1, sb\n"
    "    ldm r1!, {r2, r6, r7}\n"
    "    stm r0!, {r2, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014A6E:\n"
    "    adds r4, #0x10\n"
    "    b .L08014A94\n"
    ".L08014A72:\n"
    "    adds r3, r0, #0\n"
    "    adds r2, r4, #0\n"
    "    cmp r3, #0\n"
    "    beq .L08014A92\n"
    ".L08014A7A:\n"
    "    cmp r2, #0\n"
    "    beq .L08014A8A\n"
    "    adds r0, r2, #0\n"
    "    mov r1, sb\n"
    "    ldm r1!, {r4, r6, r7}\n"
    "    stm r0!, {r4, r6, r7}\n"
    "    ldr r1, [r1]\n"
    "    str r1, [r0]\n"
    ".L08014A8A:\n"
    "    subs r3, #1\n"
    "    adds r2, #0x10\n"
    "    cmp r3, #0\n"
    "    bne .L08014A7A\n"
    ".L08014A92:\n"
    "    adds r4, r2, #0\n"
    ".L08014A94:\n"
    "    ldr r2, [r5, #4]\n"
    "    ldr r0, [r5]\n"
    "    adds r1, r0, #0\n"
    "    cmp r0, r2\n"
    "    beq .L08014AA4\n"
    ".L08014A9E:\n"
    "    adds r1, #0x10\n"
    "    cmp r1, r2\n"
    "    bne .L08014A9E\n"
    ".L08014AA4:\n"
    "    cmp r0, #0\n"
    "    beq .L08014AAC\n"
    "    bl free\n"
    ".L08014AAC:\n"
    "    ldr r0, [sp, #0x50]\n"
    "    add r0, r8\n"
    "    ldr r1, [sp, #0x50]\n"
    "    str r1, [r5]\n"
    "    str r4, [r5, #4]\n"
    "    str r0, [r5, #0xc]\n"
    ".L08014AB8:\n"
    "    mov r1, sp\n"
    "    ldr r2, .L08014AF0 @ =0x00003E41\n"
    "    adds r0, r2, #0\n"
    "    strh r0, [r1]\n"
    "    ldr r3, [sp, #0x44]\n"
    "    strh r0, [r3]\n"
    "    movs r2, #0\n"
    "    movs r0, #0x10\n"
    "    ldr r4, [sp, #0x30]\n"
    "    strb r0, [r4]\n"
    "    ldr r0, .L08014AF4 @ =0x00001010\n"
    "    strh r0, [r1]\n"
    "    ldr r6, [sp, #0x48]\n"
    "    strh r0, [r6]\n"
    "    ldr r7, [sp, #0x34]\n"
    "    strb r2, [r7]\n"
    "    movs r0, #0x1a\n"
    "    ldr r1, [sp, #0x2c]\n"
    "    str r0, [r1]\n"
    "    add sp, #0x54\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".L08014AF0: .word 0x00003E41\n"
    ".L08014AF4: .word 0x00001010\n"
);



void GameScene::RebuildMapEntitiesForNewDay()
{
    GameSceneState * current = state;
    current->game_object = nullptr;
    current->save->DayUpdate();
    current->game_object = CreateGameWorld(current->save, current->scene, false);
    current->game_object.value->vfunc_138();
    PlayerActor * player = static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER));
    GameScenePreservedPlayerLocation & preserved =
        gCurrentGameSceneScriptController->preserved_player_location;
    if (preserved.active != 0) {
        u32 hour = preserved.time.GetHour();
        i32 elapsed = (hour <= 5 ? 6 : 30) - hour;
        player->ChangeStaminaAndFatigue(7 * elapsed, -2 * elapsed);
    }
}

void GameScene::RefreshAllNpcSchedules()
{
    // Re-read the current world for each slot: a refresh can change it.
    GameSceneState * current = state;
    for (u32 id = ENTITY_LILLIA; id <= ENTITY_CHILD; ++id) {
        GameObject * & world = current->game_object.value;
        ANpcEntity * npc = static_cast<ANpcEntity *>(
            world->GetEntity(id));
        if (npc != nullptr)
            npc->UpdateSchedule(3);
    }
}

void GameScene::ChangePlayerStaminaAndFatigue(MaryStaminaDelta stamina_delta,
    MaryFatigueDelta fatigue_delta)
{
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->ChangeStaminaAndFatigue(stamina_delta, fatigue_delta);
}

void GameScene::CreateFarmHorse(MaryBool skip_creation, MaryAnimalHorseAgeStage age_stage,
    MaryMapId map, MaryMapSpaceX x, MaryMapSpaceY y)
{
    GameSceneState * current = state;
    // The same native guard is also the only reachable facing value (zero).
    if (skip_creation == FALSE) {
        Farm & farm = current->save->farm;
        farm.SetHorse(Horse(ActorLocation(Location(map, x, y), skip_creation),
            static_cast<u32>(age_stage) * 120));
        GameObject * & world = current->game_object.value;
        world->vfunc_38(ENTITY_FARM_HORSE);
        AActorEntity * horse = static_cast<AActorEntity *>(world->GetEntity(ENTITY_FARM_HORSE));
        if (horse != nullptr && !horse->IsNormalUpdateSuspended())
            horse->SuspendNormalUpdates();
    }
}

void GameScene::RemoveFarmHorse(MaryBool skip_removal, i32 unused_value)
{
    GameSceneState * current = state;
    // The VM consumes unused_value, but the native operation never reads it.
    if (skip_removal == FALSE) {
        current->game_object.value->RemoveEntity(ENTITY_FARM_HORSE);
        current->save->farm.RemoveHorse();
    }
}

MaryAnimalSlotIndex GameScene::GetInteractingAnimalIndex()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->GetInteractingAnimalIndex();
}

bool GameScene::IsPlayerHoldingTool()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->IsHoldingTool();
}

static inline void RemoveDeadLivestock(GameSceneState * state, MaryLivestockLifeState life_state)
{
    u32 coop_capacity = state->save->farm.coop.GetCapacity();
    for (u32 slot = 0; slot < coop_capacity; ++slot) {
        Chicken * chicken = state->save->farm.coop.GetChicken(slot);
        if (chicken != nullptr && chicken->GetLifeState() == life_state) {
            state->game_object->RemoveEntity(ENTITY_ANIMAL_CHICKEN_SLOT_1 + slot);
            state->save->farm.coop.RemoveAndRememberUnk(slot);
        }
    }

    HeldItem * held = &state->save->farmer.held_item;
    if (!IsHeldItemEmpty(held) && held->GetKind() == HeldItem::KIND_CHICKEN) {
        if (state->save->farm.coop.GetChicken(GetHeldChickenSlot(held)) == nullptr)
            ClearHeldItem(&state->save->farmer.held_item);
    }

    u32 barn_capacity = state->save->farm.barn.GetCapacity();
    for (u32 slot = 0; slot < barn_capacity; ++slot) {
        BarnAnimal * animal = state->save->farm.barn.GetBarnAnimal(slot);
        if (animal != nullptr && animal->GetLifeState() == life_state) {
            state->game_object->RemoveEntity(ENTITY_BARN_ANIMAL_SLOT_1 + slot);
            state->save->farm.barn.RemoveAndRememberUnk(slot);
        }
    }
}

asm_unified(
    ".text\n"
#if defined(REGION_JP)
    "    .align 2, 0\n"
    "    .global ShowLivestockNeglectDeathSummary\n"
    "    .thumb_func\n"
    "ShowLivestockNeglectDeathSummary:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, r9\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    ldr r4, .Ljp_08014FE4\n"
    "    add sp, r4\n"
    "    ldr r0, [r0, #4]\n"
    "    mov sl, r0\n"
    "    mov r4, sl\n"
    "    adds r4, #240\n"
    "    movs r7, #0\n"
    "    ldr r0, [r4, #0]\n"
    "    cmp r7, r0\n"
    "    beq .Ljp_08014C92\n"
    "    bl __builtin_delete\n"
    ".Ljp_08014C92:\n"
    "    str r7, [r4, #0]\n"
    "    mov r0, sp\n"
    "    strb r7, [r0, #0]\n"
    "    ldr r1, .Ljp_08014FE8\n"
    "    add r0, sp, #900\n"
    "    movs r2, #3\n"
    "    bl memcpy\n"
    "    ldr r1, .Ljp_08014FEC\n"
    "    add r0, sp, #904\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    ldr r1, .Ljp_08014FF0\n"
    "    add r0, sp, #908\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    mov r9, sp\n"
    "    ldr r0, .Ljp_08014FF4\n"
    "    mov r8, r0\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014CEA\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014CDC\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014CDC:\n"
    "    adds r0, r6, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r0, r6, r4\n"
    "    strb r7, [r0, #0]\n"
    ".Ljp_08014CEA:\n"
    "    mov r0, sl\n"
    "    adds r0, #140\n"
    "    ldr r0, [r0, #0]\n"
    "    adds r0, #20\n"
    "    bl GetName__C4Farm\n"
    "    mov r8, r0\n"
    "    mov r6, r9\n"
    "    mov r4, r8\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014D2A\n"
    "    adds r0, r4, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014D1A\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014D1A:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014D2A:\n"
    "    ldr r0, .Ljp_08014FFC\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014D5C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014D4C\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014D4C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014D5C:\n"
    "    ldr r1, .Ljp_08014FE8\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014D8E\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014D7E\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014D7E:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014D8E:\n"
    "    ldr r0, .Ljp_08015000\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014DC0\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014DB0\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014DB0:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014DC0:\n"
    "    ldr r1, .Ljp_08014FE8\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014DF2\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014DE2\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014DE2:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014DF2:\n"
    "    ldr r0, .Ljp_08015004\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014E24\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014E14\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014E14:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014E24:\n"
    "    ldr r1, .Ljp_08014FEC\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014E56\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014E46\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014E46:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014E56:\n"
    "    ldr r0, .Ljp_08014FE8\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014E88\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014E78\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014E78:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014E88:\n"
    "    ldr r7, .Ljp_08014FF0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014EB8\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014EA8\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014EA8:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014EB8:\n"
    "    mov r0, sl\n"
    "    movs r1, #2\n"
    "    mov r2, sp\n"
    "    bl AppendAnimalMemorialNames\n"
    "    mov r8, sp\n"
    "    ldr r7, .Ljp_08014FF0\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014EF6\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014EE6\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014EE6:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014EF6:\n"
    "    mov r6, r8\n"
    "    ldr r0, .Ljp_08015008\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014F2A\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014F1A\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014F1A:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014F2A:\n"
    "    ldr r1, .Ljp_08014FE8\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014F5C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014F4C\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014F4C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014F5C:\n"
    "    ldr r0, .Ljp_0801500C\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014F8E\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014F7E\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014F7E:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014F8E:\n"
    "    ldr r7, .Ljp_08014FEC\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
    "    ldr r1, .Ljp_08014FF8\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_08014FBE\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .Ljp_08014FAE\n"
    "    adds r4, r5, #0\n"
    ".Ljp_08014FAE:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    ".Ljp_08014FBE:\n"
    "    movs r0, #225\n"
    "    lsls r0, r0, #2\n"
    "    bl __builtin_new\n"
    "    adds r4, r0, #0\n"
    "    mov r1, sp\n"
    "    bl strcpy\n"
    "    mov r5, sl\n"
    "    adds r5, #240\n"
    "    ldr r0, [r5, #0]\n"
    "    cmp r4, r0\n"
    "    beq .Ljp_08014FDC\n"
    "    bl __builtin_delete\n"
    ".Ljp_08014FDC:\n"
    "    str r4, [r5, #0]\n"
    "    mov r0, sl\n"
    "    adds r0, #172\n"
    "    b .Ljp_08015010\n"
    ".Ljp_08014FE4: .word 0xFFFFFC70\n"
    ".Ljp_08014FE8: .word gText_AnimalMemorial_LineBreak\n"
    ".Ljp_08014FEC: .word gText_AnimalMemorial_Continue\n"
    ".Ljp_08014FF0: .word gText_AnimalMemorial_PageBreak\n"
    ".Ljp_08014FF4: .word gText_AnimalMemorial_Header\n"
    ".Ljp_08014FF8: .word 0x00000383\n"
    ".Ljp_08014FFC: .word gText_AnimalMemorial_FarmPrefix\n"
    ".Ljp_08015000: .word gText_AnimalMemorial_PassedAway\n"
    ".Ljp_08015004: .word gText_AnimalMemorial_NamesIntro\n"
    ".Ljp_08015008: .word gText_AnimalMemorial_PrayerIntro\n"
    ".Ljp_0801500C: .word gText_AnimalMemorial_PrayerEnding\n"
    ".Ljp_08015010:\n"
    "    ldr r1, [r0, #0]\n"
    "    cmp r1, #0\n"
    "    beq .Ljp_0801502E\n"
    "    adds r0, #4\n"
    "    ldr r3, [r0, #0]\n"
    "    adds r0, r1, #0\n"
    "    adds r1, r4, #0\n"
    "    movs r2, #128\n"
    "    lsls r2, r2, #1\n"
    "    bl func_08050DC8\n"
    "    mov r1, sl\n"
    "    adds r1, #156\n"
    "    movs r0, #16\n"
    "    str r0, [r1, #0]\n"
    ".Ljp_0801502E:\n"
    "    movs r3, #228\n"
    "    lsls r3, r3, #2\n"
    "    add sp, r3\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov r9, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "\n"
    "    thumb_func_start ShowLivestockNeglectDeathSummary\n"
    "ShowLivestockNeglectDeathSummary: @ 0x08014D9C\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    ldr r4, .L0801510C @ =0xFFFFFC70\n"
    "    add sp, r4\n"
    "    ldr r0, [r0, #4]\n"
    "    mov sl, r0\n"
    "    mov r4, sl\n"
    "    adds r4, #0xf0\n"
    "    movs r7, #0\n"
    "    ldr r0, [r4]\n"
    "    cmp r7, r0\n"
    "    beq .L08014DBE\n"
    "    bl __builtin_delete\n"
    ".L08014DBE:\n"
    "    str r7, [r4]\n"
    "    mov r0, sp\n"
    "    strb r7, [r0]\n"
    "    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
    "    add r0, sp, #0x384\n"
    "    movs r2, #3\n"
    "    bl memcpy\n"
    "    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue\n"
    "    add r0, sp, #0x388\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    ldr r1, .L08015118 @ =gText_AnimalMemorial_PageBreak\n"
    "    add r0, sp, #0x38c\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    mov sb, sp\n"
    "    ldr r0, .L0801511C @ =gText_AnimalMemorial_Header\n"
    "    mov r8, r0\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014E16\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014E08\n"
    "    adds r4, r5, #0\n"
    ".L08014E08:\n"
    "    adds r0, r6, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r0, r6, r4\n"
    "    strb r7, [r0]\n"
    ".L08014E16:\n"
    "    mov r6, sb\n"
    "    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014E4A\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014E3A\n"
    "    adds r4, r5, #0\n"
    ".L08014E3A:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014E4A:\n"
    "    ldr r1, .L08015124 @ =gText_AnimalMemorial_FarmPrefix\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014E7C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014E6C\n"
    "    adds r4, r5, #0\n"
    ".L08014E6C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014E7C:\n"
    "    mov r0, sl\n"
    "    adds r0, #0x8c\n"
    "    ldr r0, [r0]\n"
    "    adds r0, #0x14\n"
    "    bl GetName__C4Farm\n"
    "    mov r8, r0\n"
    "    mov r4, r8\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014EBA\n"
    "    adds r0, r4, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014EAA\n"
    "    adds r4, r5, #0\n"
    ".L08014EAA:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014EBA:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015128 @ =gText_AnimalMemorial_FarmSuffix\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014EEC\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014EDC\n"
    "    adds r4, r5, #0\n"
    ".L08014EDC:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014EEC:\n"
#if defined(REGION_DE)
    "    ldr r1, .L08015128 @ =gText_AnimalMemorial_PassedAway\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
#endif
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014F1E\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014F0E\n"
    "    adds r4, r5, #0\n"
    ".L08014F0E:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014F1E:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015114 @ =gText_AnimalMemorial_Continue\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L0801512C @ =gText_AnimalMemorial_PassedAway\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014F50\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014F40\n"
    "    adds r4, r5, #0\n"
    ".L08014F40:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014F50:\n"
#if defined(REGION_DE)
    "    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue\n"
#endif
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014F82\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014F72\n"
    "    adds r4, r5, #0\n"
    ".L08014F72:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014F82:\n"
#if defined(REGION_DE)
    "    ldr r0, .L0801512C @ =gText_AnimalMemorial_NamesIntro\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014FB4\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014FA4\n"
    "    adds r4, r5, #0\n"
    ".L08014FA4:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014FB4:\n"
#if defined(REGION_DE)
    "    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015130 @ =gText_AnimalMemorial_NamesIntro\n"
#endif
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08014FE6\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08014FD6\n"
    "    adds r4, r5, #0\n"
    ".L08014FD6:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08014FE6:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015114 @ =gText_AnimalMemorial_Continue\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
#if defined(REGION_DE)
    "    beq .L0801504A\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    beq .L08015018\n"
#endif
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015008\n"
    "    adds r4, r5, #0\n"
    ".L08015008:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    ".L08015018:\n"
    "    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801504A\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801503A\n"
    "    adds r4, r5, #0\n"
    ".L0801503A:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#endif
    ".L0801504A:\n"
    "    ldr r7, .L08015118 @ =gText_AnimalMemorial_PageBreak\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801507A\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801506A\n"
    "    adds r4, r5, #0\n"
    ".L0801506A:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801507A:\n"
    "    mov r0, sl\n"
    "    movs r1, #2\n"
    "    mov r2, sp\n"
    "    bl AppendAnimalMemorialNames\n"
    "    mov r8, sp\n"
    "    ldr r7, .L08015118 @ =gText_AnimalMemorial_PageBreak\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080150B8\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080150A8\n"
    "    adds r4, r5, #0\n"
    ".L080150A8:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080150B8:\n"
    "    mov r6, r8\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015130 @ =gText_AnimalMemorial_PrayerIntro\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015134 @ =gText_AnimalMemorial_PrayerIntro\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080150EC\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080150DC\n"
    "    adds r4, r5, #0\n"
    ".L080150DC:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080150EC:\n"
    "    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L08015120 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801514C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
#if defined(REGION_DE)
    ".L08015138:\n"
    "    bls .L0801513C\n"
    "    adds r4, r5, #0\n"
    ".L0801513C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    b .L08015138\n"
    "    .align 2, 0\n"
    ".L0801510C: .word 0xFFFFFC70\n"
    ".L08015110: .word gText_AnimalMemorial_LineBreak\n"
    ".L08015114: .word gText_AnimalMemorial_Continue\n"
    ".L08015118: .word gText_AnimalMemorial_PageBreak\n"
    ".L0801511C: .word gText_AnimalMemorial_Header\n"
    ".L08015120: .word 0x00000383\n"
    ".L08015124: .word gText_AnimalMemorial_FarmPrefix\n"
    ".L08015128: .word gText_AnimalMemorial_FarmSuffix\n"
    ".L0801512C: .word gText_AnimalMemorial_PassedAway\n"
    ".L08015130: .word gText_AnimalMemorial_NamesIntro\n"
    ".L08015134: .word gText_AnimalMemorial_PrayerIntro\n"
    ".L08015138:\n"
    "    bls .L0801513C\n"
    "    adds r4, r5, #0\n"
    ".L0801513C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#endif
    ".L0801514C:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015134 @ =gText_AnimalMemorial_PrayerEnding\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015204 @ =gText_AnimalMemorial_PrayerEnding\n"
#endif
    "\tmov r8, r0\n"
    "\tadds r0, r6, #0\n"
    "\tbl strlen\n"
    "\tadds r7, r6, r0\n"
    "\t.ifdef REGION_DE\n"
    "\tldr r1, .L08015120 @ =0x00000383\n"
    "\t.else\n"
    "\tldr r1, .L08015208 @ =0x00000383\n"
    "\t.endif\n"
    "\tsubs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801517E\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
#if defined(REGION_DE)
    "    b .L0801516E_de\n"
    "    .align 2, 0\n"
    ".L0801510C: .word 0xFFFFFC70\n"
    ".L08015110: .word gText_AnimalMemorial_LineBreak\n"
    ".L08015114: .word gText_AnimalMemorial_Continue\n"
    ".L08015118: .word gText_AnimalMemorial_PageBreak\n"
    ".L0801511C: .word gText_AnimalMemorial_Header\n"
    ".L08015120: .word 0x00000383\n"
    ".L08015124: .word gText_AnimalMemorial_FarmPrefix\n"
    ".L08015128: .word gText_AnimalMemorial_PassedAway\n"
    ".L0801512C: .word gText_AnimalMemorial_NamesIntro\n"
    ".L08015130: .word gText_AnimalMemorial_PrayerIntro\n"
    ".L08015134: .word gText_AnimalMemorial_PrayerEnding\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    bls .L0801516E\n"
    "    adds r4, r5, #0\n"
#endif
    ".L0801516E_de:\n"
#if defined(REGION_DE)
    "    bls .L0801516E\n"
    "    adds r4, r5, #0\n"
#endif
    ".L0801516E:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801517E:\n"
    "    ldr r7, .L0801520C @ =gText_AnimalMemorial_Continue\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
    "    ldr r1, .L08015208 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080151AE\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801519E\n"
    "    adds r4, r5, #0\n"
    ".L0801519E:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080151AE:\n"
    "    movs r0, #0xe1\n"
    "    lsls r0, r0, #2\n"
    "    bl __builtin_new\n"
    "    adds r4, r0, #0\n"
    "    mov r1, sp\n"
    "    bl strcpy\n"
    "    mov r5, sl\n"
    "    adds r5, #0xf0\n"
    "    ldr r0, [r5]\n"
    "    cmp r4, r0\n"
    "    beq .L080151CC\n"
    "    bl __builtin_delete\n"
    ".L080151CC:\n"
    "    str r4, [r5]\n"
    "    mov r0, sl\n"
    "    adds r0, #0xac\n"
    "    ldr r1, [r0]\n"
    "    cmp r1, #0\n"
    "    beq .L080151F0\n"
    "    adds r0, #4\n"
    "    ldr r3, [r0]\n"
    "    adds r0, r1, #0\n"
    "    adds r1, r4, #0\n"
    "    movs r2, #0x80\n"
    "    lsls r2, r2, #1\n"
    "    bl func_08050DC8\n"
    "    mov r1, sl\n"
    "    adds r1, #0x9c\n"
    "    movs r0, #0x10\n"
    "    str r0, [r1]\n"
    ".L080151F0:\n"
    "    movs r3, #0xe4\n"
    "    lsls r3, r3, #2\n"
    "    add sp, r3\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
#if defined(REGION_DE)
    ".L0801520C: .word gText_AnimalMemorial_Continue\n"
    ".L08015208: .word 0x00000383\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    ".L08015204: .word gText_AnimalMemorial_PrayerEnding\n"
    ".L08015208: .word 0x00000383\n"
    ".L0801520C: .word gText_AnimalMemorial_Continue\n"
#endif
    "\n"
#endif
);

void RemoveLivestockDeadFromNeglect(GameScene * scene)
{
    RemoveDeadLivestock(scene->state, LIVESTOCK_LIFE_STATE_DIED_FROM_NEGLECT);
}

asm_unified(
    ".text\n"
#if defined(REGION_JP)
    "    .global ShowNaturalLivestockDeathSummary\n"
    "    .thumb_func\n"
    "ShowNaturalLivestockDeathSummary:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    ldr\tr4, .Ljp_080154C4\n"
    "    add\tsp, r4\n"
    "    ldr\tr0, [r0, #4]\n"
    "    mov\tsl, r0\n"
    "    mov\tr4, sl\n"
    "    adds\tr4, #240\n"
    "    movs\tr7, #0\n"
    "    ldr\tr0, [r4, #0]\n"
    "    cmp\tr7, r0\n"
    "    beq .Ljp_08015172\n"
    "    bl __builtin_delete\n"
    ".Ljp_08015172:\n"
    "    str\tr7, [r4, #0]\n"
    "    mov\tr0, sp\n"
    "    strb\tr7, [r0, #0]\n"
    "    ldr\tr1, .Ljp_080154C8\n"
    "    add\tr0, sp, #900\n"
    "    movs\tr2, #3\n"
    "    bl memcpy\n"
    "    ldr\tr1, .Ljp_080154CC\n"
    "    add\tr0, sp, #904\n"
    "    movs\tr2, #2\n"
    "    bl memcpy\n"
    "    ldr\tr1, .Ljp_080154D0\n"
    "    add\tr0, sp, #908\n"
    "    movs\tr2, #2\n"
    "    bl memcpy\n"
    "    mov\tr9, sp\n"
    "    ldr\tr0, .Ljp_080154D4\n"
    "    mov\tr8, r0\n"
    "    mov\tr0, sp\n"
    "    bl strlen\n"
    "    mov\tr1, sp\n"
    "    adds\tr6, r1, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080151CA\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080151BC\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080151BC:\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr0, r6, r4\n"
    "    strb\tr7, [r0, #0]\n"
    ".Ljp_080151CA:\n"
    "    mov\tr0, sl\n"
    "    adds\tr0, #140\n"
    "    ldr\tr0, [r0, #0]\n"
    "    adds\tr0, #20\n"
    "    bl GetName__C4Farm\n"
    "    mov\tr8, r0\n"
    "    mov\tr6, r9\n"
    "    mov\tr4, r8\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801520A\n"
    "    adds\tr0, r4, #0\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080151FA\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080151FA:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801520A:\n"
    "    ldr\tr0, .Ljp_080154DC\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801523C\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_0801522C\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_0801522C:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801523C:\n"
    "    ldr\tr1, .Ljp_080154C8\n"
    "    mov\tr8, r1\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801526E\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_0801525E\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_0801525E:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801526E:\n"
    "    ldr\tr0, .Ljp_080154E0\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080152A0\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_08015290\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_08015290:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_080152A0:\n"
    "    ldr\tr1, .Ljp_080154C8\n"
    "    mov\tr8, r1\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080152D2\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080152C2\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080152C2:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_080152D2:\n"
    "    ldr\tr0, .Ljp_080154E4\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_08015304\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080152F4\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080152F4:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_08015304:\n"
    "    ldr\tr1, .Ljp_080154CC\n"
    "    mov\tr8, r1\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_08015336\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_08015326\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_08015326:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_08015336:\n"
    "    ldr\tr0, .Ljp_080154C8\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_08015368\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_08015358\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_08015358:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_08015368:\n"
    "    ldr\tr7, .Ljp_080154D0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr6, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_08015398\n"
    "    adds\tr0, r7, #0\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_08015388\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_08015388:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r6, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_08015398:\n"
    "    mov\tr0, sl\n"
    "    movs\tr1, #1\n"
    "    mov\tr2, sp\n"
    "    bl AppendAnimalMemorialNames\n"
    "    mov\tr8, sp\n"
    "    ldr\tr7, .Ljp_080154D0\n"
    "    mov\tr0, sp\n"
    "    bl strlen\n"
    "    mov\tr1, sp\n"
    "    adds\tr6, r1, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080153D6\n"
    "    adds\tr0, r7, #0\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080153C6\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080153C6:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r6, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_080153D6:\n"
    "    mov\tr6, r8\n"
    "    ldr\tr0, .Ljp_080154E8\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801540A\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_080153FA\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_080153FA:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801540A:\n"
    "    ldr\tr1, .Ljp_080154C8\n"
    "    mov\tr8, r1\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801543C\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_0801542C\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_0801542C:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801543C:\n"
    "    ldr\tr0, .Ljp_080154EC\n"
    "    mov\tr8, r0\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr7, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801546E\n"
    "    mov\tr0, r8\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_0801545E\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_0801545E:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r7, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801546E:\n"
    "    ldr\tr7, .Ljp_080154CC\n"
    "    adds\tr0, r6, #0\n"
    "    bl strlen\n"
    "    adds\tr6, r6, r0\n"
    "    ldr\tr1, .Ljp_080154D8\n"
    "    subs\tr5, r1, r0\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_0801549E\n"
    "    adds\tr0, r7, #0\n"
    "    bl strlen\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, r5\n"
    "    bls .Ljp_0801548E\n"
    "    adds\tr4, r5, #0\n"
    ".Ljp_0801548E:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr2, r4, #0\n"
    "    bl memcpy\n"
    "    adds\tr1, r6, r4\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0801549E:\n"
    "    movs\tr0, #225\n"
    "    lsls\tr0, r0, #2\n"
    "    bl __builtin_new\n"
    "    adds\tr4, r0, #0\n"
    "    mov\tr1, sp\n"
    "    bl strcpy\n"
    "    mov\tr5, sl\n"
    "    adds\tr5, #240\n"
    "    ldr\tr0, [r5, #0]\n"
    "    cmp\tr4, r0\n"
    "    beq .Ljp_080154BC\n"
    "    bl __builtin_delete\n"
    ".Ljp_080154BC:\n"
    "    str\tr4, [r5, #0]\n"
    "    mov\tr0, sl\n"
    "    adds\tr0, #172\n"
    "    b .Ljp_080154F0\n"
    ".Ljp_080154C4: .word 0xFFFFFC70\n"
    ".Ljp_080154C8: .word gText_AnimalMemorial_LineBreak\n"
    ".Ljp_080154CC: .word gText_AnimalMemorial_Continue\n"
    ".Ljp_080154D0: .word gText_AnimalMemorial_PageBreak\n"
    ".Ljp_080154D4: .word gText_AnimalMemorial_Header\n"
    ".Ljp_080154D8: .word 0x00000383\n"
    ".Ljp_080154DC: .word gText_AnimalMemorial_FarmPrefix\n"
    ".Ljp_080154E0: .word gText_AnimalMemorial_PassedNaturalLife\n"
    ".Ljp_080154E4: .word gText_AnimalMemorial_NamesIntro\n"
    ".Ljp_080154E8: .word gText_AnimalMemorial_PrayerIntro\n"
    ".Ljp_080154EC: .word gText_AnimalMemorial_PrayerEnding\n"
    ".Ljp_080154F0:\n"
    "    ldr\tr1, [r0, #0]\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_0801550E\n"
    "    adds\tr0, #4\n"
    "    ldr\tr3, [r0, #0]\n"
    "    adds\tr0, r1, #0\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #128\n"
    "    lsls\tr2, r2, #1\n"
    "    bl func_08050DC8\n"
    "    mov\tr1, sl\n"
    "    adds\tr1, #156\n"
    "    movs\tr0, #16\n"
    "    str\tr0, [r1, #0]\n"
    ".Ljp_0801550E:\n"
    "    movs\tr3, #228\n"
    "    lsls\tr3, r3, #2\n"
    "    add\tsp, r3\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    thumb_func_start ShowNaturalLivestockDeathSummary\n"
    "ShowNaturalLivestockDeathSummary: @ 0x0801531C\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    ldr r4, .L0801568C @ =0xFFFFFC70\n"
    "    add sp, r4\n"
    "    ldr r0, [r0, #4]\n"
    "    mov sl, r0\n"
    "    mov r4, sl\n"
    "    adds r4, #0xf0\n"
    "    movs r7, #0\n"
    "    ldr r0, [r4]\n"
    "    cmp r7, r0\n"
    "    beq .L0801533E\n"
    "    bl __builtin_delete\n"
    ".L0801533E:\n"
    "    str r7, [r4]\n"
    "    mov r0, sp\n"
    "    strb r7, [r0]\n"
    "    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
    "    add r0, sp, #0x384\n"
    "    movs r2, #3\n"
    "    bl memcpy\n"
    "    ldr r1, .L08015694 @ =gText_AnimalMemorial_Continue\n"
    "    add r0, sp, #0x388\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    ldr r1, .L08015698 @ =gText_AnimalMemorial_PageBreak\n"
    "    add r0, sp, #0x38c\n"
    "    movs r2, #2\n"
    "    bl memcpy\n"
    "    mov sb, sp\n"
    "    ldr r0, .L0801569C @ =gText_AnimalMemorial_Header\n"
    "    mov r8, r0\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08015396\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015388\n"
    "    adds r4, r5, #0\n"
    ".L08015388:\n"
    "    adds r0, r6, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r0, r6, r4\n"
    "    strb r7, [r0]\n"
    ".L08015396:\n"
    "    mov r6, sb\n"
    "    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080153CA\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080153BA\n"
    "    adds r4, r5, #0\n"
    ".L080153BA:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080153CA:\n"
    "    ldr r1, .L080156A4 @ =gText_AnimalMemorial_FarmPrefix\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080153FC\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080153EC\n"
    "    adds r4, r5, #0\n"
    ".L080153EC:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080153FC:\n"
    "    mov r0, sl\n"
    "    adds r0, #0x8c\n"
    "    ldr r0, [r0]\n"
    "    adds r0, #0x14\n"
    "    bl GetName__C4Farm\n"
    "    mov r8, r0\n"
    "    mov r4, r8\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801543A\n"
    "    adds r0, r4, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801542A\n"
    "    adds r4, r5, #0\n"
    ".L0801542A:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801543A:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L080156A8 @ =gText_AnimalMemorial_FarmSuffix\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801546C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801545C\n"
    "    adds r4, r5, #0\n"
    ".L0801545C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801546C:\n"
#if defined(REGION_DE)
    "    ldr r1, .L080156A8 @ =gText_AnimalMemorial_NamesIntro\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
#endif
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801549E\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801548E\n"
    "    adds r4, r5, #0\n"
    ".L0801548E:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801549E:\n"
#if defined(REGION_DE)
    "    ldr r0, .L08015694 @ =gText_AnimalMemorial_Continue\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L080156AC @ =gText_AnimalMemorial_PassedAway\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080154D0\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080154C0\n"
    "    adds r4, r5, #0\n"
    ".L080154C0:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080154D0:\n"
#if defined(REGION_DE)
    "    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015694 @ =gText_AnimalMemorial_Continue\n"
#endif
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
#if defined(REGION_DE)
    "    beq .L080155CA\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    beq .L08015502\n"
#endif
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080154F2\n"
    "    adds r4, r5, #0\n"
    ".L080154F2:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    ".L08015502:\n"
    "    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08015534\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015524\n"
    "    adds r4, r5, #0\n"
    ".L08015524:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08015534:\n"
    "    ldr r1, .L080156B0 @ =gText_AnimalMemorial_NamesIntro\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08015566\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015556\n"
    "    adds r4, r5, #0\n"
    ".L08015556:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08015566:\n"
    "    ldr r0, .L08015694 @ =gText_AnimalMemorial_Continue\n"
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08015598\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015588\n"
    "    adds r4, r5, #0\n"
    ".L08015588:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08015598:\n"
    "    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080155CA\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080155BA\n"
    "    adds r4, r5, #0\n"
    ".L080155BA:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
#endif
    ".L080155CA:\n"
    "    ldr r7, .L08015698 @ =gText_AnimalMemorial_PageBreak\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080155FA\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080155EA\n"
    "    adds r4, r5, #0\n"
    ".L080155EA:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080155FA:\n"
    "    mov r0, sl\n"
    "    movs r1, #1\n"
    "    mov r2, sp\n"
    "    bl AppendAnimalMemorialNames\n"
    "    mov r8, sp\n"
    "    ldr r7, .L08015698 @ =gText_AnimalMemorial_PageBreak\n"
    "    mov r0, sp\n"
    "    bl strlen\n"
    "    mov r1, sp\n"
    "    adds r6, r1, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L08015638\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L08015628\n"
    "    adds r4, r5, #0\n"
    ".L08015628:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L08015638:\n"
    "    mov r6, r8\n"
#if defined(REGION_DE)
    "    ldr r0, .L080156AC @ =gText_AnimalMemorial_PrayerIntro\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L080156B4 @ =gText_AnimalMemorial_PrayerIntro\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801566C\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801565C\n"
    "    adds r4, r5, #0\n"
    ".L0801565C:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801566C:\n"
    "    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak\n"
    "    mov r8, r1\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
    "    ldr r1, .L080156A0 @ =0x00000383\n"
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080156CC\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    b .L080156B8\n"
    "    .align 2, 0\n"
    ".L0801568C: .word 0xFFFFFC70\n"
    ".L08015690: .word gText_AnimalMemorial_LineBreak\n"
    ".L08015694: .word gText_AnimalMemorial_Continue\n"
    ".L08015698: .word gText_AnimalMemorial_PageBreak\n"
    ".L0801569C: .word gText_AnimalMemorial_Header\n"
    ".L080156A0: .word 0x00000383\n"
    ".L080156A4: .word gText_AnimalMemorial_FarmPrefix\n"
    ".L080156A8: .word gText_AnimalMemorial_FarmSuffix\n"
    ".L080156AC: .word gText_AnimalMemorial_PassedAway\n"
    ".L080156B0: .word gText_AnimalMemorial_NamesIntro\n"
    ".L080156B4: .word gText_AnimalMemorial_PrayerIntro\n"
#endif
    ".L080156B8:\n"
    "    bls .L080156BC\n"
    "    adds r4, r5, #0\n"
    ".L080156BC:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080156CC:\n"
#if defined(REGION_DE)
    "    ldr r0, .L080156B4 @ =gText_AnimalMemorial_PrayerEnding\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r0, .L08015784 @ =gText_AnimalMemorial_PrayerEnding\n"
#endif
    "    mov r8, r0\n"
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r7, r6, r0\n"
#if defined(REGION_DE)
    "    ldr r1, .L080156A0 @ =0x00000383\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015788 @ =0x00000383\n"
#endif
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L080156FE\n"
    "    mov r0, r8\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L080156EE\n"
    "    adds r4, r5, #0\n"
    ".L080156EE:\n"
    "    adds r0, r7, #0\n"
    "    mov r1, r8\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r7, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L080156FE:\n"
#if defined(REGION_DE)
    "    ldr r7, .L08015694 @ =gText_AnimalMemorial_Continue\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r7, .L0801578C @ =gText_AnimalMemorial_Continue\n"
#endif
    "    adds r0, r6, #0\n"
    "    bl strlen\n"
    "    adds r6, r6, r0\n"
#if defined(REGION_DE)
    "    ldr r1, .L080156A0 @ =0x00000383\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    ldr r1, .L08015788 @ =0x00000383\n"
#endif
    "    subs r5, r1, r0\n"
    "    cmp r5, #0\n"
    "    beq .L0801572E\n"
    "    adds r0, r7, #0\n"
    "    bl strlen\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, r5\n"
    "    bls .L0801571E\n"
    "    adds r4, r5, #0\n"
    ".L0801571E:\n"
    "    adds r0, r6, #0\n"
    "    adds r1, r7, #0\n"
    "    adds r2, r4, #0\n"
    "    bl memcpy\n"
    "    adds r1, r6, r4\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    ".L0801572E:\n"
    "    movs r0, #0xe1\n"
    "    lsls r0, r0, #2\n"
    "    bl __builtin_new\n"
    "    adds r4, r0, #0\n"
    "    mov r1, sp\n"
    "    bl strcpy\n"
    "    mov r5, sl\n"
    "    adds r5, #0xf0\n"
    "    ldr r0, [r5]\n"
    "    cmp r4, r0\n"
    "    beq .L0801574C\n"
    "    bl __builtin_delete\n"
    ".L0801574C:\n"
    "    str r4, [r5]\n"
    "    mov r0, sl\n"
    "    adds r0, #0xac\n"
    "    ldr r1, [r0]\n"
    "    cmp r1, #0\n"
    "    beq .L08015770\n"
    "    adds r0, #4\n"
    "    ldr r3, [r0]\n"
    "    adds r0, r1, #0\n"
    "    adds r1, r4, #0\n"
    "    movs r2, #0x80\n"
    "    lsls r2, r2, #1\n"
    "    bl func_08050DC8\n"
    "    mov r1, sl\n"
    "    adds r1, #0x9c\n"
    "    movs r0, #0x10\n"
    "    str r0, [r1]\n"
    ".L08015770:\n"
    "    movs r3, #0xe4\n"
    "    lsls r3, r3, #2\n"
    "    add sp, r3\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
#if defined(REGION_DE)
    "    b RemoveNaturallyDeadLivestock\n"
    "    .align 2, 0\n"
    ".L0801568C: .word 0xFFFFFC70\n"
    ".L08015690: .word gText_AnimalMemorial_LineBreak\n"
    ".L08015694: .word gText_AnimalMemorial_Continue\n"
    ".L08015698: .word gText_AnimalMemorial_PageBreak\n"
    ".L0801569C: .word gText_AnimalMemorial_DeathHeader\n"
    ".L080156A0: .word 0x00000383\n"
    ".L080156A4: .word gText_AnimalMemorial_DeathFarmPrefix\n"
    ".L080156A8: .word gText_AnimalMemorial_NamesIntro\n"
    ".L080156AC: .word gText_AnimalMemorial_PrayerIntro\n"
    ".L080156B4: .word gText_AnimalMemorial_PrayerEnding\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    .align 2, 0\n"
    ".L08015784: .word gText_AnimalMemorial_PrayerEnding\n"
    ".L08015788: .word 0x00000383\n"
    ".L0801578C: .word gText_AnimalMemorial_Continue\n"
#endif
    "\n"
#endif
);

void RemoveNaturallyDeadLivestock(GameScene * scene)
{
    RemoveDeadLivestock(scene->state, LIVESTOCK_LIFE_STATE_DIED_NATURALLY);
}





void GameScene::BeginHoldingActorGraphic(MaryAnimationId animation_id)
{
    // The native player action consumes only the low 16 animation-ID bits.
    u16 animation = animation_id;
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(
        ENTITY_PLAYER))->BeginHoldingActorGraphic(animation);
    current->script_state = 0x19;
}

void GameScene::ObtainPowerBerry()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(
        ENTITY_PLAYER))->ObtainPowerBerry();
    current->script_state = 0x19;
}

void GameScene::ObtainMysticBerry()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(
        ENTITY_PLAYER))->ObtainMysticBerry();
    current->script_state = 0x19;
}

bool GameScene::IsHarvestSpriteDailyWorkComplete(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    // These seven character IDs are also their runtime entity IDs.
    if (static_cast<u32>(sprite_id) - CHARACTER_STAID <= CHARACTER_TIMID - CHARACTER_STAID) {
        AEntity * entity = current->game_object.value->GetEntity(sprite_id);
        if (entity != nullptr)
            return func_08033B24(static_cast<HarvestSpriteActor *>(entity));
    }
    return false;
}

MaryHeldItemKind GameScene::GetPresentedItemKind()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->GetPresentedItemKind();
}

i32 GameScene::GetPresentedItemId()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->GetPresentedItemId();
}

bool GameScene::IsPresentedItemGiftWrapped()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->IsPresentedItemGiftWrapped();
}

asm_unified(
    ".text\n"
    "\n"
    "    thumb_func_start GenerateMineFloorLayout\n"
    "GenerateMineFloorLayout:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, r8\n"
    "    push {r7}\n"
    "    sub sp, #0x88\n"
    "    adds r5, r1, #0\n"
    "    adds r6, r2, #0\n"
    "    ldr r7, [r0, #4]\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #8]\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #0xa8\n"
    "    ldr r0, [r0]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4a\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L080159DA\n"
    "    b .L08015B1A\n"
    ".L080159DA:\n"
    "    ldrh r1, [r3, #4]\n"
    "    cmp r5, #0\n"
    "    bne .L080159FC\n"
    "    cmp r1, #0x33\n"
    "    ble .L080159FC\n"
    "    ldr r0, .L080159F8 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L080159FC\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L08015A16\n"
    "    movs r1, #1\n"
    "    b .L08015A18\n"
    "    .align 2, 0\n"
    ".L080159F8: .word 0x00000133\n"
    ".L080159FC:\n"
    "    cmp r5, #1\n"
    "    bne .L08015A16\n"
    "    ldr r0, .L08015B50 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    ble .L08015A16\n"
    "    ldr r0, .L08015B54 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L08015A16\n"
    "    ldr r2, .L08015B58 @ =0xFFFFFECC\n"
    "    adds r0, r1, r2\n"
    "    movs r1, #1\n"
    "    cmp r6, r0\n"
    "    beq .L08015A18\n"
    ".L08015A16:\n"
    "    movs r1, #0\n"
    ".L08015A18:\n"
    "    cmp r1, #0\n"
    "    beq .L08015B1A\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x3c\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015A34\n"
    "    adds r0, #7\n"
    ".L08015A34:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015A40\n"
    "    adds r1, #7\n"
    ".L08015A40:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x44\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015A66\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015A60\n"
    "    ldr r0, [sp, #0x44]\n"
    "    str r0, [r1]\n"
    ".L08015A60:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015A66:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015A70\n"
    "    adds r0, #7\n"
    ".L08015A70:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015A7C\n"
    "    adds r1, #7\n"
    ".L08015A7C:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x48\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015AA2\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015A9C\n"
    "    ldr r0, [sp, #0x48]\n"
    "    str r0, [r1]\n"
    ".L08015A9C:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015AA2:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015AAC\n"
    "    adds r0, #7\n"
    ".L08015AAC:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015AB8\n"
    "    adds r1, #7\n"
    ".L08015AB8:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x4c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015ADE\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015AD8\n"
    "    ldr r0, [sp, #0x4c]\n"
    "    str r0, [r1]\n"
    ".L08015AD8:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015ADE:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015AE8\n"
    "    adds r0, #7\n"
    ".L08015AE8:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015AF4\n"
    "    adds r1, #7\n"
    ".L08015AF4:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x50\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015B1A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015B14\n"
    "    ldr r0, [sp, #0x50]\n"
    "    str r0, [r1]\n"
    ".L08015B14:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015B1A:\n"
    "    adds r4, r7, #0\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    mov r8, r4\n"
    "    cmp r3, #0\n"
    "    bne .L08015B34\n"
    "    b .L08015C7A\n"
    ".L08015B34:\n"
    "    ldrh r1, [r3, #4]\n"
    "    cmp r5, #0\n"
    "    bne .L08015B5C\n"
    "    cmp r1, #0x33\n"
    "    ble .L08015B5C\n"
    "    ldr r0, .L08015B50 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L08015B5C\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L08015B76\n"
    "    movs r1, #1\n"
    "    b .L08015B78\n"
    "    .align 2, 0\n"
    ".L08015B50: .word 0x00000133\n"
    ".L08015B54: .word 0x00000233\n"
    ".L08015B58: .word 0xFFFFFECC\n"
    ".L08015B5C:\n"
    "    cmp r5, #1\n"
    "    bne .L08015B76\n"
    "    ldr r0, .L08015CAC @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    ble .L08015B76\n"
    "    ldr r0, .L08015CB0 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L08015B76\n"
    "    ldr r2, .L08015CB4 @ =0xFFFFFECC\n"
    "    adds r0, r1, r2\n"
    "    movs r1, #1\n"
    "    cmp r6, r0\n"
    "    beq .L08015B78\n"
    ".L08015B76:\n"
    "    movs r1, #0\n"
    ".L08015B78:\n"
    "    cmp r1, #0\n"
    "    beq .L08015C7A\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x54\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015B94\n"
    "    adds r0, #7\n"
    ".L08015B94:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015BA0\n"
    "    adds r1, #7\n"
    ".L08015BA0:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x5c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015BC6\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015BC0\n"
    "    ldr r0, [sp, #0x5c]\n"
    "    str r0, [r1]\n"
    ".L08015BC0:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015BC6:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015BD0\n"
    "    adds r0, #7\n"
    ".L08015BD0:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015BDC\n"
    "    adds r1, #7\n"
    ".L08015BDC:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x60\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015C02\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015BFC\n"
    "    ldr r0, [sp, #0x60]\n"
    "    str r0, [r1]\n"
    ".L08015BFC:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015C02:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015C0C\n"
    "    adds r0, #7\n"
    ".L08015C0C:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015C18\n"
    "    adds r1, #7\n"
    ".L08015C18:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x64\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015C3E\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015C38\n"
    "    ldr r0, [sp, #0x64]\n"
    "    str r0, [r1]\n"
    ".L08015C38:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015C3E:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015C48\n"
    "    adds r0, #7\n"
    ".L08015C48:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015C54\n"
    "    adds r1, #7\n"
    ".L08015C54:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x68\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015C7A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015C74\n"
    "    ldr r0, [sp, #0x68]\n"
    "    str r0, [r1]\n"
    ".L08015C74:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015C7A:\n"
    "    mov r1, r8\n"
    "    ldr r0, [r1]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L08015C90\n"
    "    b .L08015DD6\n"
    ".L08015C90:\n"
    "    ldrh r1, [r3, #4]\n"
    "    cmp r5, #0\n"
    "    bne .L08015CB8\n"
    "    cmp r1, #0x33\n"
    "    ble .L08015CB8\n"
    "    ldr r0, .L08015CAC @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L08015CB8\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L08015CD2\n"
    "    movs r1, #1\n"
    "    b .L08015CD4\n"
    "    .align 2, 0\n"
    ".L08015CAC: .word 0x00000133\n"
    ".L08015CB0: .word 0x00000233\n"
    ".L08015CB4: .word 0xFFFFFECC\n"
    ".L08015CB8:\n"
    "    cmp r5, #1\n"
    "    bne .L08015CD2\n"
    "    ldr r0, .L08015E20 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    ble .L08015CD2\n"
    "    ldr r0, .L08015E24 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L08015CD2\n"
    "    ldr r2, .L08015E28 @ =0xFFFFFECC\n"
    "    adds r0, r1, r2\n"
    "    movs r1, #1\n"
    "    cmp r6, r0\n"
    "    beq .L08015CD4\n"
    ".L08015CD2:\n"
    "    movs r1, #0\n"
    ".L08015CD4:\n"
    "    cmp r1, #0\n"
    "    beq .L08015DD6\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x6c\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015CF0\n"
    "    adds r0, #7\n"
    ".L08015CF0:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015CFC\n"
    "    adds r1, #7\n"
    ".L08015CFC:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x74\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015D22\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015D1C\n"
    "    ldr r0, [sp, #0x74]\n"
    "    str r0, [r1]\n"
    ".L08015D1C:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015D22:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015D2C\n"
    "    adds r0, #7\n"
    ".L08015D2C:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #2\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015D38\n"
    "    adds r1, #7\n"
    ".L08015D38:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x78\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015D5E\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015D58\n"
    "    ldr r0, [sp, #0x78]\n"
    "    str r0, [r1]\n"
    ".L08015D58:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015D5E:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015D68\n"
    "    adds r0, #7\n"
    ".L08015D68:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015D74\n"
    "    adds r1, #7\n"
    ".L08015D74:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x7c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015D9A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015D94\n"
    "    ldr r0, [sp, #0x7c]\n"
    "    str r0, [r1]\n"
    ".L08015D94:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015D9A:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015DA4\n"
    "    adds r0, #7\n"
    ".L08015DA4:\n"
    "    asrs r2, r0, #3\n"
    "    movs r0, #6\n"
    "    ldrsh r1, [r4, r0]\n"
    "    cmp r1, #0\n"
    "    bge .L08015DB0\n"
    "    adds r1, #7\n"
    ".L08015DB0:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x80\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015DD6\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015DD0\n"
    "    ldr r0, [sp, #0x80]\n"
    "    str r0, [r1]\n"
    ".L08015DD0:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015DD6:\n"
    "    ldr r2, [sp, #8]\n"
    "    movs r3, #0\n"
    "    add r4, sp, #0xc\n"
    "    cmp r2, #0\n"
    "    beq .L08015DE2\n"
    "    adds r3, r4, #0\n"
    ".L08015DE2:\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #0x8c\n"
    "    ldr r1, [r0]\n"
    "    ldr r0, .L08015E2C @ =0x00002E58\n"
    "    adds r1, r1, r0\n"
    "    str r3, [sp]\n"
    "    str r2, [sp, #4]\n"
    "    add r0, sp, #0x84\n"
    "    adds r2, r5, #0\n"
    "    adds r3, r6, #0\n"
    "    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi\n"
    "    ldr r0, [sp, #8]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    adds r0, r4, #0\n"
    "    cmp r0, r1\n"
    "    beq .L08015E12\n"
    ".L08015E0C:\n"
    "    adds r0, #4\n"
    "    cmp r0, r1\n"
    "    bne .L08015E0C\n"
    ".L08015E12:\n"
    "    add sp, #0x88\n"
    "    pop {r3}\n"
    "    mov r8, r3\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".L08015E20: .word 0x00000133\n"
    ".L08015E24: .word 0x00000233\n"
    ".L08015E28: .word 0xFFFFFECC\n"
    ".L08015E2C: .word 0x00002E58\n"
    "\n"
    "    thumb_func_start DescendMineFloor\n"
    "DescendMineFloor:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0xe8\n"
    "    ldr r0, [r0, #4]\n"
    "    str r0, [sp, #0xd8]\n"
    "    adds r4, r0, #0\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r1, [r1, #0x14]\n"
    "    bl _call_via_r1\n"
    "    adds r2, r0, #0\n"
    "    add r0, sp, #0x3c\n"
    "    movs r3, #0\n"
    "    strb r3, [r0]\n"
    "    strb r3, [r0, #1]\n"
    "    adds r1, r2, #0\n"
    "    subs r1, #0x34\n"
    "    adds r7, r0, #0\n"
    "    cmp r1, #0xff\n"
    "    bls .L08015E64\n"
    "    b .L08016250\n"
    ".L08015E64:\n"
    "    adds r0, r2, #1\n"
    "    mov r8, r0\n"
    "    adds r6, r2, #0\n"
    "    subs r6, #0x33\n"
    "    str r3, [sp, #8]\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4a\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L08015E82\n"
    "    b .L08015F9C\n"
    ".L08015E82:\n"
    "    ldrh r1, [r3, #4]\n"
    "    movs r2, #0\n"
    "    cmp r1, #0x33\n"
    "    ble .L08015E9A\n"
    "    ldr r0, .L080161A0 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L08015E9A\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L08015E9A\n"
    "    movs r2, #1\n"
    ".L08015E9A:\n"
    "    cmp r2, #0\n"
    "    beq .L08015F9C\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x40\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015EB6\n"
    "    adds r0, #7\n"
    ".L08015EB6:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08015EC2\n"
    "    adds r1, #7\n"
    ".L08015EC2:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x48\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015EE8\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015EE2\n"
    "    ldr r0, [sp, #0x48]\n"
    "    str r0, [r1]\n"
    ".L08015EE2:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015EE8:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015EF2\n"
    "    adds r0, #7\n"
    ".L08015EF2:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08015EFE\n"
    "    adds r1, #7\n"
    ".L08015EFE:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x4c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015F24\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015F1E\n"
    "    ldr r0, [sp, #0x4c]\n"
    "    str r0, [r1]\n"
    ".L08015F1E:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015F24:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015F2E\n"
    "    adds r0, #7\n"
    ".L08015F2E:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08015F3A\n"
    "    adds r1, #7\n"
    ".L08015F3A:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x50\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015F60\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015F5A\n"
    "    ldr r0, [sp, #0x50]\n"
    "    str r0, [r1]\n"
    ".L08015F5A:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015F60:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015F6A\n"
    "    adds r0, #7\n"
    ".L08015F6A:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08015F76\n"
    "    adds r1, #7\n"
    ".L08015F76:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x54\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08015F9C\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08015F96\n"
    "    ldr r0, [sp, #0x54]\n"
    "    str r0, [r1]\n"
    ".L08015F96:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08015F9C:\n"
    "    ldr r4, [sp, #0xd8]\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    str r4, [sp, #0xe0]\n"
    "    cmp r3, #0\n"
    "    bne .L08015FB6\n"
    "    b .L080160D0\n"
    ".L08015FB6:\n"
    "    ldrh r1, [r3, #4]\n"
    "    movs r2, #0\n"
    "    cmp r1, #0x33\n"
    "    ble .L08015FCE\n"
    "    ldr r0, .L080161A0 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L08015FCE\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L08015FCE\n"
    "    movs r2, #1\n"
    ".L08015FCE:\n"
    "    cmp r2, #0\n"
    "    beq .L080160D0\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x58\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08015FEA\n"
    "    adds r0, #7\n"
    ".L08015FEA:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08015FF6\n"
    "    adds r1, #7\n"
    ".L08015FF6:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x60\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801601C\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08016016\n"
    "    ldr r0, [sp, #0x60]\n"
    "    str r0, [r1]\n"
    ".L08016016:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801601C:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016026\n"
    "    adds r0, #7\n"
    ".L08016026:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08016032\n"
    "    adds r1, #7\n"
    ".L08016032:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x64\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016058\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08016052\n"
    "    ldr r0, [sp, #0x64]\n"
    "    str r0, [r1]\n"
    ".L08016052:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016058:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016062\n"
    "    adds r0, #7\n"
    ".L08016062:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L0801606E\n"
    "    adds r1, #7\n"
    ".L0801606E:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x68\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016094\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L0801608E\n"
    "    ldr r0, [sp, #0x68]\n"
    "    str r0, [r1]\n"
    ".L0801608E:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016094:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L0801609E\n"
    "    adds r0, #7\n"
    ".L0801609E:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L080160AA\n"
    "    adds r1, #7\n"
    ".L080160AA:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x6c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L080160D0\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L080160CA\n"
    "    ldr r0, [sp, #0x6c]\n"
    "    str r0, [r1]\n"
    ".L080160CA:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L080160D0:\n"
    "    ldr r4, [sp, #0xe0]\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L080160E6\n"
    "    b .L0801620A\n"
    ".L080160E6:\n"
    "    ldrh r1, [r3, #4]\n"
    "    movs r2, #0\n"
    "    cmp r1, #0x33\n"
    "    ble .L080160FE\n"
    "    ldr r0, .L080161A0 @ =0x00000133\n"
    "    cmp r1, r0\n"
    "    bgt .L080160FE\n"
    "    adds r0, r1, #0\n"
    "    subs r0, #0x34\n"
    "    cmp r6, r0\n"
    "    bne .L080160FE\n"
    "    movs r2, #1\n"
    ".L080160FE:\n"
    "    cmp r2, #0\n"
    "    bne .L08016104\n"
    "    b .L0801620A\n"
    ".L08016104:\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x70\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L0801611C\n"
    "    adds r0, #7\n"
    ".L0801611C:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08016128\n"
    "    adds r1, #7\n"
    ".L08016128:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x78\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801614E\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08016148\n"
    "    ldr r0, [sp, #0x78]\n"
    "    str r0, [r1]\n"
    ".L08016148:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801614E:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016158\n"
    "    adds r0, #7\n"
    ".L08016158:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L08016164\n"
    "    adds r1, #7\n"
    ".L08016164:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x7c\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801618A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08016184\n"
    "    ldr r0, [sp, #0x7c]\n"
    "    str r0, [r1]\n"
    ".L08016184:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801618A:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016194\n"
    "    adds r0, #7\n"
    ".L08016194:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    b .L080161A4\n"
    "    .align 2, 0\n"
    ".L080161A0: .word 0x00000133\n"
    ".L080161A4:\n"
    "    bge .L080161A8\n"
    "    adds r1, #7\n"
    ".L080161A8:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x80\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L080161CE\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L080161C8\n"
    "    ldr r0, [sp, #0x80]\n"
    "    str r0, [r1]\n"
    ".L080161C8:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L080161CE:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L080161D8\n"
    "    adds r0, #7\n"
    ".L080161D8:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r1, [r4, r3]\n"
    "    cmp r1, #0\n"
    "    bge .L080161E4\n"
    "    adds r1, #7\n"
    ".L080161E4:\n"
    "    asrs r1, r1, #3\n"
    "    add r0, sp, #0x84\n"
    "    strb r2, [r0]\n"
    "    strb r1, [r0, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801620A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r1, sp\n"
    "    adds r1, r1, r0\n"
    "    adds r1, #8\n"
    "    cmp r1, #0\n"
    "    beq .L08016204\n"
    "    ldr r0, [sp, #0x84]\n"
    "    str r0, [r1]\n"
    ".L08016204:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801620A:\n"
    "    movs r2, #0\n"
    "    ldr r0, [sp, #8]\n"
    "    add r5, sp, #0xc\n"
    "    cmp r0, #0\n"
    "    beq .L08016216\n"
    "    adds r2, r5, #0\n"
    ".L08016216:\n"
    "    ldr r4, [sp, #0xd8]\n"
    "    adds r4, #0x8c\n"
    "    ldr r1, [r4]\n"
    "    ldr r3, .L0801624C @ =0x00002E58\n"
    "    adds r1, r1, r3\n"
    "    str r2, [sp]\n"
    "    str r0, [sp, #4]\n"
    "    add r0, sp, #0x88\n"
    "    movs r2, #0\n"
    "    adds r3, r6, #0\n"
    "    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi\n"
    "    ldr r0, [sp, #8]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    adds r1, r5, #0\n"
    "    add r0, sp, #0x88\n"
    "    cmp r1, r2\n"
    "    bne .L08016244\n"
    "    b .L0801664A\n"
    ".L08016244:\n"
    "    adds r1, #4\n"
    "    cmp r1, r2\n"
    "    bne .L08016244\n"
    "    b .L0801664A\n"
    "    .align 2, 0\n"
    ".L0801624C: .word 0x00002E58\n"
    ".L08016250:\n"
    "    ldr r1, .L0801656C @ =0xFFFFFECC\n"
    "    adds r0, r2, r1\n"
    "    cmp r0, #0xff\n"
    "    bls .L0801625A\n"
    "    b .L08016740\n"
    ".L0801625A:\n"
    "    adds r0, r2, #1\n"
    "    mov r8, r0\n"
    "    adds r1, #1\n"
    "    adds r6, r2, r1\n"
    "    str r3, [sp, #8]\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4a\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L08016278\n"
    "    b .L08016394\n"
    ".L08016278:\n"
    "    ldrh r1, [r3, #4]\n"
    "    ldr r0, .L08016570 @ =0x00000133\n"
    "    movs r2, #0\n"
    "    cmp r1, r0\n"
    "    ble .L08016292\n"
    "    ldr r0, .L08016574 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L08016292\n"
    "    ldr r4, .L0801656C @ =0xFFFFFECC\n"
    "    adds r0, r1, r4\n"
    "    cmp r6, r0\n"
    "    bne .L08016292\n"
    "    movs r2, #1\n"
    ".L08016292:\n"
    "    cmp r2, #0\n"
    "    beq .L08016394\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0x8c\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L080162AE\n"
    "    adds r0, #7\n"
    ".L080162AE:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080162BA\n"
    "    adds r0, #7\n"
    ".L080162BA:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0x94\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L080162E0\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L080162DA\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L080162DA:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L080162E0:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L080162EA\n"
    "    adds r0, #7\n"
    ".L080162EA:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080162F6\n"
    "    adds r0, #7\n"
    ".L080162F6:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0x98\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801631C\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016316\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016316:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801631C:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016326\n"
    "    adds r0, #7\n"
    ".L08016326:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L08016332\n"
    "    adds r0, #7\n"
    ".L08016332:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0x9c\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016358\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016352\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016352:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016358:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016362\n"
    "    adds r0, #7\n"
    ".L08016362:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L0801636E\n"
    "    adds r0, #7\n"
    ".L0801636E:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xa0\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016394\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L0801638E\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L0801638E:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016394:\n"
    "    ldr r4, [sp, #0xd8]\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    str r4, [sp, #0xe0]\n"
    "    cmp r3, #0\n"
    "    bne .L080163AE\n"
    "    b .L080164CA\n"
    ".L080163AE:\n"
    "    ldrh r1, [r3, #4]\n"
    "    ldr r0, .L08016570 @ =0x00000133\n"
    "    movs r2, #0\n"
    "    cmp r1, r0\n"
    "    ble .L080163C8\n"
    "    ldr r0, .L08016574 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L080163C8\n"
    "    ldr r4, .L0801656C @ =0xFFFFFECC\n"
    "    adds r0, r1, r4\n"
    "    cmp r6, r0\n"
    "    bne .L080163C8\n"
    "    movs r2, #1\n"
    ".L080163C8:\n"
    "    cmp r2, #0\n"
    "    beq .L080164CA\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0xa4\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L080163E4\n"
    "    adds r0, #7\n"
    ".L080163E4:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080163F0\n"
    "    adds r0, #7\n"
    ".L080163F0:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xac\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016416\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016410\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016410:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016416:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016420\n"
    "    adds r0, #7\n"
    ".L08016420:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L0801642C\n"
    "    adds r0, #7\n"
    ".L0801642C:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xb0\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016452\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L0801644C\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L0801644C:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016452:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L0801645C\n"
    "    adds r0, #7\n"
    ".L0801645C:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L08016468\n"
    "    adds r0, #7\n"
    ".L08016468:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xb4\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801648E\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016488\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016488:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801648E:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016498\n"
    "    adds r0, #7\n"
    ".L08016498:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080164A4\n"
    "    adds r0, #7\n"
    ".L080164A4:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xb8\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L080164CA\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L080164C4\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L080164C4:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L080164CA:\n"
    "    ldr r4, [sp, #0xe0]\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x4b\n"
    "    bl _call_via_r2\n"
    "    adds r3, r0, #0\n"
    "    cmp r3, #0\n"
    "    bne .L080164E0\n"
    "    b .L0801660C\n"
    ".L080164E0:\n"
    "    ldrh r1, [r3, #4]\n"
    "    ldr r0, .L08016570 @ =0x00000133\n"
    "    movs r2, #0\n"
    "    cmp r1, r0\n"
    "    ble .L080164FA\n"
    "    ldr r0, .L08016574 @ =0x00000233\n"
    "    cmp r1, r0\n"
    "    bgt .L080164FA\n"
    "    ldr r4, .L0801656C @ =0xFFFFFECC\n"
    "    adds r0, r1, r4\n"
    "    cmp r6, r0\n"
    "    bne .L080164FA\n"
    "    movs r2, #1\n"
    ".L080164FA:\n"
    "    cmp r2, #0\n"
    "    bne .L08016500\n"
    "    b .L0801660C\n"
    ".L08016500:\n"
    "    ldr r1, [r3, #0x14]\n"
    "    add r4, sp, #0xbc\n"
    "    adds r0, r4, #0\n"
    "    ldr r2, [r1, #0xc]\n"
    "    adds r1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016518\n"
    "    adds r0, #7\n"
    ".L08016518:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L08016524\n"
    "    adds r0, #7\n"
    ".L08016524:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xc4\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801654A\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016544\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016544:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801654A:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L08016554\n"
    "    adds r0, #7\n"
    ".L08016554:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #2\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L08016560\n"
    "    adds r0, #7\n"
    ".L08016560:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xc8\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    b .L08016578\n"
    "    .align 2, 0\n"
    ".L0801656C: .word 0xFFFFFECC\n"
    ".L08016570: .word 0x00000133\n"
    ".L08016574: .word 0x00000233\n"
    ".L08016578:\n"
    "    cmp r0, #0xb\n"
    "    bhi .L08016594\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L0801658E\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L0801658E:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L08016594:\n"
    "    movs r1, #0\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L0801659E\n"
    "    adds r0, #7\n"
    ".L0801659E:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080165AA\n"
    "    adds r0, #7\n"
    ".L080165AA:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xcc\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L080165D0\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L080165CA\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L080165CA:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L080165D0:\n"
    "    movs r1, #4\n"
    "    ldrsh r0, [r4, r1]\n"
    "    cmp r0, #0\n"
    "    bge .L080165DA\n"
    "    adds r0, #7\n"
    ".L080165DA:\n"
    "    asrs r2, r0, #3\n"
    "    movs r3, #6\n"
    "    ldrsh r0, [r4, r3]\n"
    "    cmp r0, #0\n"
    "    bge .L080165E6\n"
    "    adds r0, #7\n"
    ".L080165E6:\n"
    "    asrs r0, r0, #3\n"
    "    add r1, sp, #0xd0\n"
    "    strb r2, [r1]\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r0, #0xb\n"
    "    bhi .L0801660C\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    cmp r2, #0\n"
    "    beq .L08016606\n"
    "    ldr r0, [r1]\n"
    "    str r0, [r2]\n"
    ".L08016606:\n"
    "    ldr r0, [sp, #8]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #8]\n"
    ".L0801660C:\n"
    "    movs r2, #0\n"
    "    ldr r0, [sp, #8]\n"
    "    add r5, sp, #0xc\n"
    "    cmp r0, #0\n"
    "    beq .L08016618\n"
    "    adds r2, r5, #0\n"
    ".L08016618:\n"
    "    ldr r4, [sp, #0xd8]\n"
    "    adds r4, #0x8c\n"
    "    ldr r1, [r4]\n"
    "    ldr r3, .L08016668 @ =0x00002E58\n"
    "    adds r1, r1, r3\n"
    "    str r2, [sp]\n"
    "    str r0, [sp, #4]\n"
    "    add r0, sp, #0xd4\n"
    "    movs r2, #1\n"
    "    adds r3, r6, #0\n"
    "    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi\n"
    "    ldr r0, [sp, #8]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, #4\n"
    "    mov r2, sp\n"
    "    adds r2, r2, r0\n"
    "    adds r2, #8\n"
    "    adds r1, r5, #0\n"
    "    add r0, sp, #0xd4\n"
    "    cmp r1, r2\n"
    "    beq .L0801664A\n"
    ".L08016644:\n"
    "    adds r1, #4\n"
    "    cmp r1, r2\n"
    "    bne .L08016644\n"
    ".L0801664A:\n"
    "    ldr r0, [r0]\n"
    "    str r0, [sp, #0x3c]\n"
    "    ldr r0, [r4]\n"
    "    ldr r4, .L08016668 @ =0x00002E58\n"
    "    adds r0, r0, r4\n"
    "    bl GetLayoutKind__C14MineFloorState\n"
    "    cmp r0, #4\n"
    "    bhi .L08016740\n"
    "    lsls r0, r0, #2\n"
    "    ldr r1, .L0801666C @ =.LmineLayoutDestinations\n"
    "    adds r0, r0, r1\n"
    "    ldr r0, [r0]\n"
    "    mov pc, r0\n"
    "    .align 2, 0\n"
    ".L08016668: .word 0x00002E58\n"
    ".L0801666C: .word .LmineLayoutDestinations\n"
    ".LmineLayoutDestinations: @ GetLayoutKind values 0 through 4\n"
    "    .word .LenterNextMineFloor @ case 0\n"
    "    .word .LenterNextMineFloor @ case 1\n"
    "    .word .LenterNextMineFloor @ case 2\n"
    "    .word .LenterNextMineFloor @ case 3\n"
    "    .word .LenterNextMineFloor @ case 4\n"
    ".LenterNextMineFloor:\n"
    "    ldrb r0, [r7]\n"
    "    lsls r0, r0, #4\n"
    "    adds r0, #0x10\n"
    "    mov sl, r0\n"
    "    add r0, sp, #0x3c\n"
    "    ldrb r0, [r0, #1]\n"
    "    lsls r0, r0, #4\n"
    "    adds r7, r0, #0\n"
    "    adds r7, #0x38\n"
    "    movs r0, #8\n"
    "    add sl, r0\n"
    "    adds r7, #8\n"
    "    ldr r1, [sp, #0xe0]\n"
    "    ldr r0, [r1]\n"
    "    ldr r2, [r0]\n"
    "    adds r2, #0xb4\n"
    "    str r2, [sp, #0xdc]\n"
    "    add r6, sp, #8\n"
    "    ldr r3, .L08016750 @ =0x000003FF\n"
    "    mov sb, r3\n"
    "    mov r4, r8\n"
    "    mov r1, sb\n"
    "    ands r4, r1\n"
    "    ldrh r2, [r6]\n"
    "    ldr r5, .L08016754 @ =0xFFFFFC00\n"
    "    adds r1, r5, #0\n"
    "    ands r1, r2\n"
    "    orrs r1, r4\n"
    "    strh r1, [r6]\n"
    "    mov r2, sl\n"
    "    lsls r4, r2, #0x10\n"
    "    lsrs r2, r4, #0x10\n"
    "    movs r3, #0x3f\n"
    "    mov ip, r3\n"
    "    ands r2, r3\n"
    "    lsls r2, r2, #2\n"
    "    str r2, [sp, #0xe4]\n"
    "    ldrb r1, [r6, #1]\n"
    "    mov r8, r1\n"
    "    movs r3, #3\n"
    "    adds r1, r3, #0\n"
    "    mov r2, r8\n"
    "    ands r1, r2\n"
    "    ldr r2, [sp, #0xe4]\n"
    "    orrs r1, r2\n"
    "    strb r1, [r6, #1]\n"
    "    lsrs r4, r4, #0x16\n"
    "    mov r1, sb\n"
    "    ands r4, r1\n"
    "    ldrh r2, [r6, #2]\n"
    "    adds r1, r5, #0\n"
    "    ands r1, r2\n"
    "    orrs r1, r4\n"
    "    strh r1, [r6, #2]\n"
    "    lsls r2, r7, #0x10\n"
    "    lsrs r1, r2, #0x10\n"
    "    mov r4, ip\n"
    "    ands r1, r4\n"
    "    lsls r1, r1, #2\n"
    "    ldrb r4, [r6, #3]\n"
    "    ands r3, r4\n"
    "    orrs r3, r1\n"
    "    strb r3, [r6, #3]\n"
    "    lsrs r2, r2, #0x16\n"
    "    mov r1, sb\n"
    "    ands r2, r1\n"
    "    ldrh r1, [r6, #4]\n"
    "    ands r5, r1\n"
    "    orrs r5, r2\n"
    "    strh r5, [r6, #4]\n"
    "    ldr r2, [sp, #0xdc]\n"
    "    ldr r3, [r2]\n"
    "    adds r1, r6, #0\n"
    "    movs r2, #1\n"
    "    bl _call_via_r3\n"
    "    ldr r0, [sp, #0xd8]\n"
    "    bl RefreshSceneNpcSchedules\n"
    "    movs r4, #0\n"
    "    ldr r3, [sp, #0xe0]\n"
    "    ldr r0, [r3]\n"
    "    ldr r1, [r0]\n"
    "    ldr r1, [r1, #0x14]\n"
    "    bl _call_via_r1\n"
    "    adds r2, r0, #0\n"
    "    str r7, [sp]\n"
    "    str r4, [sp, #4]\n"
    "    ldr r0, [sp, #0xd8]\n"
    "    movs r1, #0\n"
    "    mov r3, sl\n"
    "    bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi\n"
    ".L08016740:\n"
    "    add sp, #0xe8\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".L08016750: .word 0x000003FF\n"
    ".L08016754: .word 0xFFFFFC00\n"
);



void GameScene::StartWorldBackgroundMusic()
{
    GameSceneState * current = state;
    HardwareMusicPlayerSlot & player = current->bgm_player;
    u32 sequence = static_cast<GameSceneWorld *>(current->game_object.value)->GetDefaultAudioSequence();
    player.StartIfChangedOrPaused(static_cast<u16>(sequence));
}

bool GameScene::FadeOutBackgroundMusic()
{
    HardwareMusicPlayerSlot & player = state->bgm_player;
    bool requested;
    if (static_cast<u8>(player.IsUnpaused()) != 0) {
        player.FadeOut(5);
        requested = true;
    } else {
        requested = false;
    }
    return requested;
}

FishingCatchResult const * GameScene::GetCaughtFish()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->GetCaughtFish();
}

bool GameScene::IsBackgroundMusicActive()
{
    return state->bgm_player.IsUnpaused();
}

void GameScene::CreatePlayerChildEntity()
{
    GameSceneState * current = state;
    GameStateSaveImage * save = current->save;
    save->npcs.CreateChild(save->clock.calendar.date);
    // Refresh may replace the world; resolve the child from the current slot.
    GameObject * & world = current->game_object.value;
    world->vfunc_38(ENTITY_CHILD);
    AActorEntity * child = static_cast<AActorEntity *>(world->GetEntity(ENTITY_CHILD));
    if (child != nullptr && !child->IsNormalUpdateSuspended())
        child->SuspendNormalUpdates();
}

void GameScene::SetContestAnimal(MaryAnimalKind animal_kind, MaryAnimalSlotIndex animal_index)
{
    GameSceneState * current = state;
    switch (animal_kind) {
    case ANIMAL_KIND_HORSE:
        current->game_object.value->RemoveEntity(ENTITY_FARM_HORSE);
        break;
    case ANIMAL_KIND_DOG:
        current->game_object.value->RemoveEntity(ENTITY_FARM_DOG);
        break;
    case ANIMAL_KIND_COW:
    case ANIMAL_KIND_SHEEP:
        current->save->farm.barn.method_0800D80C(animal_index);
        current->game_object.value->RemoveEntity(ENTITY_BARN_ANIMAL_SLOT_1 + static_cast<u32>(animal_index));
        break;
    case ANIMAL_KIND_CHICKEN:
        current->save->farm.coop.method_0800CB7C(animal_index);
        current->game_object.value->RemoveEntity(ENTITY_ANIMAL_CHICKEN_SLOT_1 + static_cast<u32>(animal_index));
        break;
    }
}

asm_unified(
    ".text\n"
    "\n"
    "    thumb_func_start ClearContestAnimal__9GameScene14MaryAnimalKind\n"
    "ClearContestAnimal__9GameScene14MaryAnimalKind:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, r8\n"
    "    push {r7}\n"
    "    sub sp, #8\n"
    "    ldr r6, [r0, #4]\n"
    "    cmp r1, #(.LclearContestHorse - .LclearContestHandlers) / 4 - 1\n"
    "    bls .L080168E4\n"
    "    b .LclearContestDone\n"
    ".L080168E4:\n"
    "    lsls r0, r1, #2\n"
    "    ldr r1, .L080168F0 @ =.LclearContestHandlers\n"
    "    adds r0, r0, r1\n"
    "    ldr r0, [r0]\n"
    "    mov pc, r0\n"
    "    .align 2, 0\n"
    ".L080168F0: .word .LclearContestHandlers\n"
    ".LclearContestHandlers: @ jump table\n"
    "    .word .LclearContestHorse @ ANIMAL_KIND_HORSE\n"
    "    .word .LclearContestBarn @ ANIMAL_KIND_COW\n"
    "    .word .LclearContestBarn @ ANIMAL_KIND_SHEEP\n"
    "    .word .LclearContestChicken @ ANIMAL_KIND_CHICKEN\n"
    "    .word .LclearContestDog @ ANIMAL_KIND_DOG\n"
    ".LclearContestHorse:\n"
    "    adds r4, r6, #0\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2c\n"
    "    bl _call_via_r2\n"
    "    cmp r0, #0\n"
    "    beq .L0801691E\n"
    "    b .LclearContestDone\n"
    ".L0801691E:\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x38]\n"
    "    movs r1, #0x2c\n"
    "    bl _call_via_r2\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2c\n"
    "    bl _call_via_r2\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, #0\n"
    "    beq .L08016956\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x28]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls r0, r0, #0x18\n"
    "    cmp r0, #0\n"
    "    bne .L08016956\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x20]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    ".L08016956:\n"
    "    cmp r4, #0\n"
    "    bne .L0801695C\n"
    "    b .LclearContestDone\n"
    ".L0801695C:\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #2\n"
    "    movs r2, #0xbc\n"
    "    lsls r2, r2, #2\n"
    "    movs r3, #0x84\n"
    "    bl SetLocation__7AEntityUiii\n"
    "    b .LclearContestDone\n"
    ".LclearContestBarn:\n"
    "    adds r4, r6, #0\n"
    "    adds r4, #0x8c\n"
    "    ldr r0, [r4]\n"
    "    movs r1, #0xbe\n"
    "    lsls r1, r1, #3\n"
    "    adds r0, r0, r1\n"
    "    bl method_0800D058__C4Barn\n"
    "    adds r7, r0, #0\n"
    "    movs r0, #1\n"
    "    rsbs r0, r0, #0\n"
    "    mov r8, r4\n"
    "    cmp r7, r0\n"
    "    bne .L0801698A\n"
    "    b .LclearContestDone\n"
    ".L0801698A:\n"
    "    ldr r0, [r4]\n"
    "    movs r1, #0xbe\n"
    "    lsls r1, r1, #3\n"
    "    adds r0, r0, r1\n"
    "    bl method_0800D858__4Barn\n"
    "    adds r5, r7, #0\n"
    "    adds r5, #0x36\n"
    "    adds r4, #0x1c\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x38]\n"
    "    adds r1, r5, #0\n"
    "    bl _call_via_r2\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    adds r1, r5, #0\n"
    "    bl _call_via_r2\n"
    "    adds r5, r0, #0\n"
    "    cmp r5, #0\n"
    "    beq .L080169D4\n"
    "    ldr r0, [r5, #0x14]\n"
    "    ldr r1, [r0, #0x28]\n"
    "    adds r0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    lsls r0, r0, #0x18\n"
    "    cmp r0, #0\n"
    "    bne .L080169D4\n"
    "    ldr r0, [r5, #0x14]\n"
    "    ldr r1, [r0, #0x20]\n"
    "    adds r0, r5, #0\n"
    "    bl _call_via_r1\n"
    ".L080169D4:\n"
    "    mov r0, r8\n"
    "    ldr r1, [r0]\n"
    "    movs r0, #0xbe\n"
    "    lsls r0, r0, #3\n"
    "    adds r1, r1, r0\n"
    "    mov r4, sp\n"
    "    mov r0, sp\n"
    "    adds r2, r7, #0\n"
    "    bl method_0800D074__C4BarnUi\n"
    "    cmp r5, #0\n"
    "    bne .L080169EE\n"
    "    b .LclearContestDone\n"
    ".L080169EE:\n"
    "    mov r0, sp\n"
    "    movs r1, #0\n"
    "    ldrsh r2, [r0, r1]\n"
    "    movs r0, #2\n"
    "    ldrsh r3, [r4, r0]\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #0x25\n"
    "    bl SetLocation__7AEntityUiii\n"
    "    b .LclearContestDone\n"
    ".LclearContestChicken:\n"
    "    adds r4, r6, #0\n"
    "    adds r4, #0x8c\n"
    "    ldr r0, [r4]\n"
    "    movs r1, #0x82\n"
    "    lsls r1, r1, #3\n"
    "    adds r0, r0, r1\n"
    "    bl GetUnkEnt__C4Coop\n"
    "    adds r7, r0, #0\n"
    "    movs r0, #1\n"
    "    rsbs r0, r0, #0\n"
    "    mov r8, r4\n"
    "    cmp r7, r0\n"
    "    beq .LclearContestDone\n"
    "    ldr r0, [r4]\n"
    "    movs r1, #0x82\n"
    "    lsls r1, r1, #3\n"
    "    adds r0, r0, r1\n"
    "    bl method_0800CBC0__4Coop\n"
    "    adds r5, r7, #0\n"
    "    adds r5, #0x2e\n"
    "    adds r4, #0x1c\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x38]\n"
    "    adds r1, r5, #0\n"
    "    bl _call_via_r2\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    adds r1, r5, #0\n"
    "    bl _call_via_r2\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, #0\n"
    "    beq .L08016A68\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x28]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls r0, r0, #0x18\n"
    "    cmp r0, #0\n"
    "    bne .L08016A68\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x20]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    ".L08016A68:\n"
    "    mov r0, r8\n"
    "    ldr r1, [r0]\n"
    "    movs r0, #0x82\n"
    "    lsls r0, r0, #3\n"
    "    adds r1, r1, r0\n"
    "    add r5, sp, #4\n"
    "    adds r0, r5, #0\n"
    "    adds r2, r7, #0\n"
    "    bl method_0800C6F0__C4CoopUi\n"
    "    cmp r4, #0\n"
    "    beq .LclearContestDone\n"
    "    movs r1, #0\n"
    "    ldrsh r2, [r5, r1]\n"
    "    movs r0, #2\n"
    "    ldrsh r3, [r5, r0]\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #0x11\n"
    "    bl SetLocation__7AEntityUiii\n"
    "    b .LclearContestDone\n"
    ".LclearContestDog:\n"
    "    adds r4, r6, #0\n"
    "    adds r4, #0xa8\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    cmp r0, #0\n"
    "    bne .LclearContestDone\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x38]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    ldr r0, [r4]\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, [r1, #0x40]\n"
    "    movs r1, #0x2b\n"
    "    bl _call_via_r2\n"
    "    adds r4, r0, #0\n"
    "    cmp r4, #0\n"
    "    beq .L08016ADE\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x28]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls r0, r0, #0x18\n"
    "    cmp r0, #0\n"
    "    bne .L08016ADE\n"
    "    ldr r0, [r4, #0x14]\n"
    "    ldr r1, [r0, #0x20]\n"
    "    adds r0, r4, #0\n"
    "    bl _call_via_r1\n"
    ".L08016ADE:\n"
    "    cmp r4, #0\n"
    "    beq .LclearContestDone\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #2\n"
    "    movs r2, #0xbf\n"
    "    lsls r2, r2, #1\n"
    "    movs r3, #0x52\n"
    "    bl SetLocation__7AEntityUiii\n"
    ".LclearContestDone:\n"
    "    add sp, #8\n"
    "    pop {r3}\n"
    "    mov r8, r3\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "\n"
);

MaryAnimalSlotIndex GameScene::GetContestAnimalIndex(MaryAnimalKind animal_kind)
{
    GameSceneState * current = state;
    MaryAnimalSlotIndex result;
    switch (animal_kind) {
    case ANIMAL_KIND_HORSE:
        if (current->save->event_state.festival_horse_race_player_entry_selected
            || current->save->event_state.fall_festival_horse_race_player_entry_selected)
            result = ANIMAL_SLOT_1;
        else
            result = ANIMAL_SLOT_NOT_SELECTED;
        break;
    default:
        result = ANIMAL_SLOT_NOT_SELECTED;
        break;
    case ANIMAL_KIND_DOG:
        if (current->save->event_state.frisbee_tournament_player_dog_entry_selected)
            result = ANIMAL_SLOT_1;
        else
            result = ANIMAL_SLOT_NOT_SELECTED;
        break;
    case ANIMAL_KIND_COW:
    case ANIMAL_KIND_SHEEP:
        result = static_cast<MaryAnimalSlotIndex>(current->save->farm.barn.method_0800D058());
        break;
    case ANIMAL_KIND_CHICKEN:
        result = static_cast<MaryAnimalSlotIndex>(current->save->farm.coop.GetUnkEnt());
        break;
    }
    return result;
}



void GameScene::OpenDoor(MaryDoorIndex door_index)
{
    state->game_object.value->OpenDoor(door_index);
}

void GameScene::CloseDoor(MaryDoorIndex door_index)
{
    state->game_object.value->CloseDoor(door_index);
}

void GameScene::RedrawRucksackShelfAfterPurchase()
{
    state->game_object.value->RedrawRucksackShelfAfterPurchase();
}

void GameScene::RedrawBlueFeatherShelfAfterPurchase()
{
    state->game_object.value->RedrawBlueFeatherShelfAfterPurchase();
}

void GameScene::func_08016C10()
{
    state->game_object.value->vfunc_104();
}

void GameScene::CreateNewYearSunriseEffect()
{
    CreateEntityNewYearSunriseEffect(state->game_object.value->GetEntity(0x5D));
}

void GameScene::PlayNewYearSunriseEffect()
{
    GameSceneState * current = state;
    PlayEntityNewYearSunriseEffect(current->game_object.value->GetEntity(0x5D));
    // The callback may change scene.state; the native write uses this state.
    current->script_state = 0x1C;
}

void GameScene::DestroyNewYearSunriseEffect()
{
    DestroyEntityNewYearSunriseEffect(state->game_object.value->GetEntity(0x5D));
}

void GameScene::PlayStarSparkleEffect()
{
    GameSceneState * current = state;
    PlayEntityStarSparkleEffect(current->game_object.value->GetEntity(0x5D));
    current->script_state = 0x1B;
}

void GameScene::EnterHotSpringBathingState()
{
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))
        ->EnterHotSpringBathingState();
}

void GameScene::ExitHotSpringBathingState()
{
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))
        ->ExitHotSpringBathingState();
}

void GameScene::RefreshEntity(MaryEntityId entity_id)
{
    // Refresh may replace the world; re-read its current slot afterwards.
    GameObject * & world = state->game_object.value;
    world->vfunc_38(entity_id);
    AActorEntity * actor = static_cast<AActorEntity *>(world->GetEntity(entity_id));
    if (actor != nullptr && !actor->IsNormalUpdateSuspended())
        actor->SuspendNormalUpdates();
}

void GameScene::RemoveEntity(MaryEntityId entity_id)
{
    state->game_object.value->RemoveEntity(entity_id);
}

void GameScene::PreservePlayerLocationForNextDay()
{
    GameSceneState * current = state;
    AActorEntity * player = static_cast<AActorEntity *>(current->game_object.value->GetEntity(ENTITY_PLAYER));
    // Lookup can replace the global controller; resolve it after the call.
    GameScenePreservedPlayerLocation & saved =
        gCurrentGameSceneScriptController->preserved_player_location;
    u32 map = player->GetMap();
    GameStateSaveImage * save = current->save;
    saved.active = 1;
    saved.map = static_cast<MaryMapId>(map);
    // The native operation copies all 16 encoded clock bits, not the slot's
    // remaining padding. Preserve unknown bits instead of rebuilding the time.
    memcpy(&saved.time, &save->clock.calendar.time, sizeof(GameTime));
}

void GameScene::ClearPreservedPlayerLocation()
{
    GameScenePreservedPlayerLocation & saved =
        gCurrentGameSceneScriptController->preserved_player_location;
    saved.active = 0;
    saved.map = MAP_NONE;
}

MaryMapId GameScene::GetPreservedPlayerMapId()
{
    // This native query returns the stored map even when active is zero.
    return gCurrentGameSceneScriptController
        ->preserved_player_location.GetMapId();
}

static inline Food ChooseRandomMeal(GameSceneState const & current)
{
    // Rice ball and bread are always candidates in addition to learned food.
    u32 choices = current.save->cooking_recipes.CountLearnedFoodRecipes() + 2;
    u32 selection = rand() % choices;
    switch (selection) {
    case 0:
        return Food(ITEM_FOOD_RICE_BALL);
    case 1:
        return Food(ITEM_FOOD_BREAD);
    default:
        selection -= 2;
        return current.save->cooking_recipes.GetLearnedFoodRecipe(selection).ToFood();
    }
}

void GameScene::EatRandomMeal()
{
    GameSceneState * current = state;
    // Native order obtains the player/vtable before selecting the meal.
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))
        ->EatFood(ChooseRandomMeal(*current));
    current->script_state = 0x19;
}

void GameScene::PreparePlayerForScriptedAnimation()
{
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))
        ->PrepareForScriptedAnimation();
}

void GameScene::RestorePlayerAfterScriptedAnimation()
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))
        ->RestoreAfterScriptedAnimation();
    current->script_state = 0x19;
}

void GameScene::CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x,
    MaryMapSpaceY y, MaryEventIconLayer layer, MaryEventIconId icon_id)
{
    // Preserve native narrowing before obtaining the world dispatch target.
    u16 id = icon_id;
    static_cast<GameSceneWorld *>(state->game_object.value)
        ->CreateEventIcon(slot, x, y, layer, id);
}

void GameScene::RemoveEventIcon(MaryEventIconSlot slot)
{
    static_cast<GameSceneWorld *>(state->game_object.value)->RemoveEventIcon(slot);
}

void GameScene::SetPlayerActorUpdateSuspended(MaryBool suspended)
{
    // Native entry keeps the low byte; do not replace it with bool normalization.
    u8 value = suspended;
    static_cast<PlayerActor *>(state->game_object.value->GetEntity(ENTITY_PLAYER))
        ->SetUpdateSuspended(value);
}

void GameScene::ShowPlayerHoldingTool(MaryItemToolId tool_id)
{
    GameSceneState * current = state;
    static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER))
        ->ShowHoldingTool(tool_id);
    current->script_state = 0x19;
}

void GameScene::CureAllSickLivestock()
{
    GameSceneState * current = state;
    u32 id = ENTITY_ANIMAL_CHICKEN_SLOT_1;
    // Borrow the slot, not its value: callbacks may replace the current world.
    GameObject * & world = current->game_object.value;
    for (; id <= ENTITY_BARN_ANIMAL_SLOT_16; ++id) {
        AnimalActor * actor = static_cast<AnimalActor *>(
            world->GetEntity(id));
        if (actor != nullptr && actor->IsSick())
            actor->CureSickness();
    }
}

void GameScene::RelocateEntityToMap(i32 entity_id, u32 map,
    i32 x, i32 y, u32 facing)
{
    i32 target_x = x;
    GameSceneState * current = state;
    u32 target_map = map;
    ApplyEntityLocation(current, entity_id, target_map, target_x, y, facing);
}

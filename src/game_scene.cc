#include "game_scene.hh"
#include "new_game.hh"
#include <new>
#include "hardware_blend.hh"
#include "game_state.hh"
#include "entity_actor.hh"
#include "npc_entity.hh"
#include "entity_ui.hh"
#include "fomt_constants.hh"
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "font.hh"
#include "gbasvc.h"
#include <iterator>

static inline void StartSceneSong(MusicPlayer ** player, i32 mode, u16 song_id)
{
    switch (mode) {
    case AUDIO_START:
        func_08008B6C(player, song_id);
        break;
    case AUDIO_START_WEAK:
        func_08008B88(player, song_id);
        break;
    case AUDIO_START_OR_CONTINUE:
        func_08008BB0(player, song_id);
        break;
    }
}

static inline MusicPlayer ** FindAvailableSceneSongPlayer(GameSceneSongPlayerPool & pool)
{
    MusicPlayer *** it = pool.begin;
    MusicPlayer *** end = pool.end;
    for (; it != end; ++it) {
        if (static_cast<u8>(func_08008CD0(*it)) == 0)
            return *it;
    }
    // The native path assumes a nonempty pool and reuses its final entry.
    return *(end - 1);
}

static inline void ApplySceneBgmSettings(GameSceneBgmSettings const & settings, MusicPlayer ** player)
{
    func_08008CC4(player);
    func_08008C28(player, settings.tempo);
    func_08008C38(player, settings.volume, 0xFFFF);
    func_08008C54(player, settings.pitch, 0xFFFF);
    func_08008C70(player, settings.pan, 0xFFFF);
    func_08008C8C(player, settings.modulation_depth, 0xFFFF);
    func_08008CA8(player, settings.lfo_speed, 0xFFFF);
}

u8 * func_080100F0(void)
{
    return gUnk_0300040C + 0x524;
}

u8 * func_08010104(void)
{
    return gUnk_0300040C + 0x4DC;
}

GameSceneScriptQueue<2> * func_08010118(void)
{
    GameSceneScriptControllerPrefix * controller =
        reinterpret_cast<GameSceneScriptControllerPrefix *>(gUnk_0300040C);
    return &controller->queue_0;
}

u8 * func_08010128(void)
{
    return gUnk_0300040C + 0x36C;
}

u8 * func_08010138(void)
{
    return gUnk_0300040C + 0x368;
}

u32 func_08010148(void)
{
    return 25;
}

ScriptEngine * func_0801014C(void)
{
    GameSceneScriptControllerPrefix * controller =
        reinterpret_cast<GameSceneScriptControllerPrefix *>(gUnk_0300040C);
    return &controller->script_engine;
}

GameScene::~GameScene()
{
    GameSceneScriptControllerPrefix * controller =
        reinterpret_cast<GameSceneScriptControllerPrefix *>(gUnk_0300040C);
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
    u32 map = current->game_object->vfunc_14();
    func_080D7F9C(current, id, map, x, y, facing);
}

i32 GameScene::GetEntityX(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16X();
    return value >> 16;
}

i32 GameScene::GetEntityY(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16Y();
    return value >> 16;
}

void GameScene::SetEntityFacing(u32 id, u32 facing)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr && entity->facing != facing)
        entity->SetAnimFacing(facing);
}

u32 GameScene::GetEntityFacing(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    return entity != nullptr ? entity->facing : 0;
}

u32 GameScene::GetEntityMap(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    u32 map = MAP_NONE;
    if (entity != nullptr)
        map = entity->GetMap();
    return map;
}

void GameScene::SetEntitySpritePriority(u32 id, u32 priority)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        entity->unk_21 = priority;
}

void GameScene::MoveEntityXTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_08032308(*entity, target, speed_q16);
}

void GameScene::MoveEntityYTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_0803233C(*entity, target, speed_q16);
}

void GameScene::WaitForEntityMovement(u32 id)
{
    GameSceneState * current = state;
    AActorEntity * entity = current->game_object->GetActorEntity(id);
    current->waiting_entity = entity;
    if (entity != nullptr)
        current->script_state = 0x16;
}

void GameScene::SetEntityAnim(u32 id, u32 animation)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr && entity->anim_id != animation)
        entity->SetAnim(animation);
}

void GameScene::NoOp014(i32)
{
}

void GameScene::HideEntity(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        entity->PutOutOfTown();
}

void GameScene::OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr) {
        // This native callback uses the extended +0x30 selector, not the
        // actor's +0x20 facing. It does not write the actor's coordinates.
        EntityUiCallbackState * callback = reinterpret_cast<EntityUiCallbackState *>(entity);
        i32 x = entity->GetQ16X() >> 16;
        i32 y = entity->GetQ16Y() >> 16;
        x += delta_x;
        y += delta_y;
        func_08033B84(callback, callback->value_30, x, y);
    }
}

void GameScene::StartEntityEffect(u32 id, u32 effect, u32 persistent)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_08032384(*entity, effect, persistent != 0);
}

void GameScene::StopEntityEffect(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_080323C8(*entity);
}

void GameScene::SetEntityAuxRenderProfile(u32 id, u32 profile)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_080323E0(*entity, profile);
}

void GameScene::ChangeMap(u32 map, i32 x, i32 y)
{
    GameSceneState * current = state;
    current->game_object->ChangeMap(Location(map, x, y), true);
    func_080D7F08(current);
}

void GameScene::PanCameraTo(i32 x, i32 y, u32 speed)
{
    state->game_object->PanCameraTo(x, y, speed);
}

void GameScene::WaitForCameraMovement()
{
    GameSceneState * current = state;
    if (!current->game_object->IsCameraMovementComplete())
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
    func_08008BE0(&state->bgm_player);
}

void GameScene::PlaySong(i32 mode, u32 sequence)
{
    MusicPlayer ** player = FindAvailableSceneSongPlayer(state->song_players);
    StartSceneSong(player, mode, static_cast<u16>(sequence));
}

void GameScene::StopAllSongs()
{
    func_08008DE8();
}

void GameScene::TalkResetUi()
{
    GameSceneState * current = state;
    current->time_window = nullptr;
    current->pause_menu_selector = nullptr;
    current->talk_window = nullptr;
    current->display.control.dispcnt &= ~0x0100;
}

void GameScene::TalkClose()
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050D74(reinterpret_cast<void * const *>(current->talk_window.Get()));
        func_080D7F88(current);
        func_080D7F74(current);
        func_080D7F60(current);
        current->script_state = 0x0F;
    }
}

void GameScene::TalkMessage(char const * text, u32 rate)
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050DC8(reinterpret_cast<void * const *>(current->talk_window.Get()),
            reinterpret_cast<u32>(text), static_cast<u16>(rate), reinterpret_cast<u32>(current->text_variables));
        current->script_state = 0x10;
    }
}

void GameScene::TalkTelevisionMessage(char const * text)
{
    GameSceneState * current = state;
    if (current->talk_window.Get() != nullptr) {
        func_08050DC8(reinterpret_cast<void * const *>(current->talk_window.Get()),
            reinterpret_cast<u32>(text), 0x40, reinterpret_cast<u32>(current->text_variables));
        // Television uses a separate completion state, not slow dialogue.
        current->script_state = 0x11;
    }
}

void GameScene::TalkSetNameplateCharacter(u32 id)
{
    GameSceneState * current = state;
    UiStateOwner * window = current->talk_window.Get();
    if (window != nullptr && current->save->display_options.show_nameplate) {
        char const * name = func_0809FE3C(&current->save->npcs, id);
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
        func_08050E50(reinterpret_cast<void * const *>(window), id);
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
            func_08050E80(reinterpret_cast<void * const *>(current->talk_window.Get()), heart);
        }
    }
}

void GameScene::TalkHideHeartIndicator()
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E8C(reinterpret_cast<void * const *>(window));
}

void GameScene::TalkPromptChoices(char const * prompt, char const * first, char const * second,
    char const * third, char const * fourth)
{
    GameSceneState * current = state;
    // A missing optional row terminates the list, even if later rows exist.
    if (current->talk_window.Get() != nullptr && first != nullptr && second != nullptr) {
        if (third == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E30(current->talk_window.Get(),
                prompt, first, second,
                0, 0, variables);
        } else if (fourth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E30(current->talk_window.Get(),
                prompt, first, second,
                third, 0, variables);
        } else {
            ScriptTextVariableStore * variables = current->text_variables;
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
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E0C(current->talk_window.Get(), first,
                second, 0, 0, 0, 0, variables);
        } else if (fourth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, 0, 0, 0, variables);
        } else if (fifth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, fourth,
                0, 0, variables);
        } else if (sixth == nullptr) {
            ScriptTextVariableStore * variables = current->text_variables;
            func_08050E0C(current->talk_window.Get(), first,
                second, third, fourth,
                fifth, 0, variables);
        } else {
            ScriptTextVariableStore * variables = current->text_variables;
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
        func_08009378(current->screen_blend, step, mode, mosaic);
        current->script_state = 0x12;
        current->unk_E8 = 0;
        current->unk_E9 = mode == 2;
    } else {
        // The third callable uses this same path but suppresses the hook.
        if (call_scene_hook != 0)
            current->game_object->vfunc_B8();
        func_0800934C(current->screen_blend, step, mode, mosaic);
        current->script_state = 0x13;
        current->unk_E8 = fade_out;
        current->unk_E9 = mode == 2;
        // Keep native halfword writes: these are the DISPCNT and BLDCNT
        // shadows, not an unrelated scene flag word or a 32-bit update.
        WriteHardwareDisplayHalfword(current->display.control.dispcnt,
            ReadHardwareDisplayHalfword(current->display.control.dispcnt) | 0x0E00);
        if (mode == 1)
            WriteHardwareDisplayHalfword(current->display.blend_control,
                ReadHardwareDisplayHalfword(current->display.blend_control) | 0x0080);
        else
            WriteHardwareDisplayHalfword(current->display.blend_control,
                ReadHardwareDisplayHalfword(current->display.blend_control) | 0x00C0);
    }
}

void GameScene::TextVariableSetNumber(u32 slot, i32 value)
{
    GameSceneState * current = state;
    // Preserve the native temporary and regional formatter, without a new clamp.
    char text[52];
#if defined(REGION_JP)
    FormatFullWidthDecimal(value, text, 0);
#else
    FormatSignedDecimal(value, text, 0);
#endif
    func_0803B6B8(current->text_variables, slot, text);
}

void GameScene::TextVariableSetString(u32 slot, char const * text)
{
    func_0803B6B8(state->text_variables, slot, text);
}

void GameScene::TextVariableSetNumberFieldWidth(u32 slot, i32 value, u32 width)
{
    GameSceneState * current = state;
    // Preserve the native temporary and regional formatter, without a new clamp.
    char text[52];
#if defined(REGION_JP)
    FormatFullWidthDecimal(value, text, width);
#else
    FormatSignedDecimal(value, text, width);
#endif
    func_0803B6B8(current->text_variables, slot, text);
}

void GameScene::CallScript(i32 script_id, i32 context_value)
{
    GameSceneState * current = state;
    GameSceneScriptControllerPrefix * controller =
        reinterpret_cast<GameSceneScriptControllerPrefix *>(gUnk_0300040C);
    controller->script_engine.LoadById(script_id, context_value);
    func_080D7F3C(current);
}

void GameScene::QueueScript(GameSceneScriptRequest const & request, i32 queue_kind)
{
    GameSceneScriptControllerPrefix * controller =
        reinterpret_cast<GameSceneScriptControllerPrefix *>(gUnk_0300040C);
    GameSceneScriptQueue<2> & first = controller->queue_0;
    switch (queue_kind) {
    case 0: first.Push(request); break;
    case 1: controller->queue_1.Push(request); break;
    case 2: controller->queue_2.Push(request); break;
    }
}

void GameScene::WaitFrames(i32 frames)
{
    GameSceneState * current = state;
    // Retain only the low halfword. Zero is not an immediate completion.
    current->wait_frames = frames;
    current->script_state = 0x15;
}

void GameScene::PrepareClockMenuTransition()
{
    state->game_object->PrepareClockMenuTransition();
}

void GameScene::RestoreAfterClockMenu()
{
    state->game_object->RestoreAfterClockMenu();
}

void GameScene::PrepareCookingMenuTransition()
{
    state->game_object->PrepareCookingMenuTransition();
}

void GameScene::RestoreAfterCookingMenu()
{
    state->game_object->RestoreAfterCookingMenu();
}

void GameScene::PrepareRecipeMenuTransition()
{
    state->game_object->PrepareRecipeMenuTransition();
}

void GameScene::RestoreAfterRecipeMenu()
{
    state->game_object->RestoreAfterRecipeMenu();
}

// These calls refresh map tiles after the caller updates feed storage.
// The native path forwards the original index without another bounds check.
void GameScene::RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough)
{
    state->game_object->RefreshBarnFeedTrough(trough);
}

void GameScene::RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough)
{
    state->game_object->RefreshChickenFeedTrough(trough);
}

void GameScene::StartShipmentBoxDepositAnimation()
{
    state->game_object->StartShipmentBoxDepositAnimation();
}

// ENTITY_PLAYER is required here, unlike the nullable arbitrary-entity calls.
bool GameScene::IsPlayerRidingHorse()
{
    return static_cast<GameScenePlayerActor *>(state->game_object->GetActorEntity(ENTITY_PLAYER))->IsRidingHorse();
}

bool GameScene::TryShipPlayerHeldItem()
{
    GameSceneState * current = state;
    bool result;
    if (static_cast<GameScenePlayerActor *>(current->game_object->GetActorEntity(ENTITY_PLAYER))->TryShipHeldItem()) {
        current->script_state = 0x19;
        result = true;
    } else {
        result = false;
    }
    return result;
}

// All four food/article VM paths pass a real RucksackItem by reference;
// wrapped selects the common action path, not a second inventory object.
bool GameScene::SetPlayerHeldItem(RucksackItem const & item, bool wrapped)
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object->GetActorEntity(ENTITY_PLAYER))->SetHeldItem(item, wrapped);
    current->script_state = 0x19;
    return true;
}

bool GameScene::GivePlayerBasket()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object->GetActorEntity(ENTITY_PLAYER))->GiveBasket();
    current->script_state = 0x19;
    return true;
}

void GameScene::ThrowPlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object->GetActorEntity(ENTITY_PLAYER))->ThrowHeldItem();
    current->script_state = 0x19;
}

void GameScene::UsePlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object->GetActorEntity(ENTITY_PLAYER))->UseHeldItem();
    current->script_state = 0x19;
}

void GameScene::ClearPlayerHeldItem()
{
    static_cast<GameScenePlayerActor *>(state->game_object->GetActorEntity(ENTITY_PLAYER))->ClearHeldItem();
}

MaryItemArticleId GameScene::RemoveRecordPlayerAlbum()
{
    return state->game_object->RemoveRecordPlayerAlbum();
}

MaryItemArticleId GameScene::SwapRecordPlayerAlbum(MaryItemArticleId article)
{
    return state->game_object->SwapRecordPlayerAlbum(article);
}

void GameScene::SetEntityEventScript(u32 entity_id, MaryScriptId script_id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(entity_id);
    if (entity != nullptr)
        entity->SetEventScript(script_id);
}

void GameScene::ClearEntityEventScript(u32 entity_id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(entity_id);
    if (entity != nullptr)
        entity->SetEventScript(0);
}

void GameScene::SetTelevisionProgram(MaryTelevisionProgramId program)
{
    state->game_object->SetTelevisionProgram(program);
}

void GameScene::EndTelevisionProgram()
{
    state->game_object->EndTelevisionProgram();
}

void GameScene::EnableScriptedNpcControl()
{
    state->save->scripted_npc_control = 1;
}

void GameScene::DisableScriptedNpcControl()
{
    state->save->scripted_npc_control = 0;
}

GameSceneWorldUnk1020::~GameSceneWorldUnk1020()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->vfunc_4C(indices[0]);
}

EC IndexedResourceArchive * func_0801FBDC(GameSceneWorldPrefix & world)
{
    return &world.data.unk_FF0;
}

EC IndexedResourceArchive * func_0801FBE8(GameSceneWorldPrefix & world)
{
    return &world.data.unk_FC0;
}

EC IndexedResourceArchive * func_0801FBF4(GameSceneWorldPrefix & world)
{
    return &world.data.unk_F90;
}

EC IndexedResourceArchive * func_0801FC00(GameSceneWorldPrefix & world)
{
    return &world.data.unk_F60;
}

EC IndexedResourceArchive * func_0801FC0C(GameSceneWorldPrefix & world)
{
    return &world.data.unk_F30;
}

EC IndexedResourceArchive * func_0801FC18(GameSceneWorldPrefix & world)
{
    return &world.data.unk_F00;
}

EC IndexedResourceArchive * func_0801FC24(GameSceneWorldPrefix & world)
{
    return &world.data.unk_ED0;
}

EC IndexedResourceArchive * func_0801FC30(GameSceneWorldPrefix & world)
{
    return &world.data.unk_EA0;
}

EC IndexedResourceArchive * func_0801FC3C(GameSceneWorldPrefix & world)
{
    return &world.data.unk_E70;
}

EC IndexedResourceArchive * func_0801FC48(GameSceneWorldPrefix & world)
{
    return &world.data.unk_E40;
}

EC IndexedResourceArchive * func_0801FC54(GameSceneWorldPrefix & world)
{
    return &world.data.unk_E10;
}

EC IndexedResourceArchive * func_0801FC60(GameSceneWorldPrefix & world)
{
    return &world.data.unk_DE0;
}

EC IndexedResourceArchive * func_0801FC6C(GameSceneWorldPrefix & world)
{
    return &world.data.actor_archive;
}

EC void func_0801FC78(GameSceneWorldPrefix & world)
{
    world.unk_107C = nullptr;
}

EC GameSceneWorldMapPrefix * func_0801FC9C(GameSceneWorldPrefix & world)
{
    return world.data.map.value;
}

EC GameSceneWorldMapPrefix * func_0801FCA0(GameSceneWorldPrefix & world)
{
    return world.data.map.value;
}

EC GameStateClock const * func_0801FCA4(GameSceneWorldPrefix const & world)
{
    return &world.save->clock;
}

EC i32 func_0801FCB4(GameSceneWorldPrefix & world, u32 index)
{
    GameScenePaletteCache & cache = world.data.palette_cache;
    u8 & encoded = cache.encoded_palette_banks[index];
    i32 bank = encoded - 16;
    if (bank < 0) {
        bank = func_080AC96C(&cache, index);
        encoded = bank + 16;
    }
    return bank;
}

EC void func_0801FCDC(GameSceneWorldPrefix & world, u32 index)
{
    world.data.palette_cache.resources[index].unk_81 = 0;
}

EC AActorEntity * func_0801FCF4(GameSceneWorldPrefix const & world, u32 index)
{
    AActorEntity * const * first = world.data.entities;
    std::advance(first, index);
    return *first;
}

EC AActorEntity * func_0801FD00(GameSceneWorldPrefix & world, u32 index)
{
    AActorEntity ** first = world.data.entities;
    std::advance(first, index);
    return *first;
}

EC void func_0801FD0C(GameSceneWorldPrefix & world, u32 index)
{
    AActorEntity ** entity = world.data.entities;
    std::advance(entity, index);
    if (*entity != nullptr) {
        delete *entity;
        *entity = nullptr;
    }
}

EC void * func_0801FD30(GameSceneWorldPrefix & world)
{
    return world.data.unk_1020;
}

EC bool func_0801FD3C(GameSceneWorldPrefix const & world)
{
    return func_080A5A9C(world.data.map.value);
}

EC i32 func_0801FD48(GameSceneWorldPrefix const & world)
{
    return world.data.map.value->y.parts.integer;
}

EC i32 func_0801FD50(GameSceneWorldPrefix const & world)
{
    return world.data.map.value->x.parts.integer;
}

EC u32 func_0801FD58(GameSceneWorldPrefix const & world)
{
    return world.data.map.value->map;
}

EC void func_0801FD60(GameSceneWorldPrefix & world, i32 x, i32 y, u32 speed)
{
    func_080A59BC(world.data.map.value, x, y, speed);
}

EC void func_0801FD6C(GameSceneWorldPrefix & world, i32 x, i32 y)
{
    func_080A5960(world.data.map.value, x, y);
}

EC Vec2 func_080A58EC(GameSceneWorldMapPrefix const * map, i32 x, i32 y)
{
    i32 old_x = map->x.parts.integer;
    i32 old_y = map->y.parts.integer;
    i32 center_x = old_x + 120;
    i32 center_y = old_y + 80;
    MapData const * data = GetMapData(map->map_data_id);
    i32 width = data->width * 8;
    i32 height = data->height * 8;
    i32 dx = x - center_x;
    i32 dy = y - center_y;
    i32 next_x = old_x + dx;
    if (next_x < 0)
        next_x = 0;
    else if (next_x > width - 240)
        next_x = width - 240;
    i32 next_y = old_y + dy;
    if (next_y < 0)
        next_y = 0;
    else if (next_y > height - 160)
        next_y = height - 160;
    return Vec2(next_x, next_y);
}

EC void func_080A5960(GameSceneWorldMapPrefix * map, i32 x, i32 y)
{
    Vec2 target;
    target = func_080A58EC(map, x, y);
    Vec2 const & position = target;
    if (map->x.parts.integer != position.x) {
        map->camera_changed = true;
        map->x.q16 = position.x << 16;
    }
    i32 current_y = map->y.parts.integer;
    if (current_y != position.y) {
        map->camera_changed = true;
        map->y.q16 = position.y << 16;
    }
}

EC void func_080A59BC(GameSceneWorldMapPrefix * map, i32 x, i32 y, u32 speed)
{
    Vec2 target;
    target = func_080A58EC(map, x, y);
    Vec2 const & position = target;
    if (speed == 0)
        speed = 1;
    i32 old_x = map->x.parts.integer;
    i32 dx = position.x - old_x;
    i32 old_y = map->y.parts.integer;
    i32 dy = position.y - old_y;
    if (dx != 0 || dy != 0) {
        u32 squared = dx * dx + dy * dy;
        i32 shift = 0;
        while ((squared << (shift * 2)) <= 0x3FFFFFFF)
            ++shift;
        squared <<= shift * 2;
        i32 distance = Sqrt(squared) >> shift;
        i32 frames = static_cast<u32>(distance) / speed;
        if (frames == 0)
            frames = 1;
        map->step_x_q16 = ((position.x << 16) - map->x.q16) / frames;
        map->step_y_q16 = ((position.y << 16) - map->y.q16) / frames;
        map->movement_frames = frames;
    } else {
        map->movement_frames = 0;
    }
}

EC bool func_080A5A9C(GameSceneWorldMapPrefix const * map)
{
    return map->movement_frames == 0;
}

EC void func_080D7F08(GameSceneState * state)
{
    for (u32 id = ENTITY_LILLIA; id <= ENTITY_CHILD; ++id) {
        GameObject * & game_object = state->game_object;
        ANpcEntity * entity = static_cast<ANpcEntity *>(game_object->GetActorEntity(id));
        if (entity != nullptr)
            entity->vfunc_3C(3);
    }
}

EC void func_080D7F3C(GameSceneState * state)
{
    state->game_object->vfunc_124();
    state->script_state = 2;
}

EC void func_080D7F60(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E8C(reinterpret_cast<void * const *>(window));
}

EC void func_080D7F74(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E5C(reinterpret_cast<void * const *>(window));
}

EC void func_080D7F88(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E74(reinterpret_cast<void * const *>(window));
}

SceneOwner CalendarTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(func_080A3744(::operator new(sizeof(CalendarScene)), &next, save));
}

SceneOwner ToolChestTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_0808A678(::operator new(sizeof(ToolChestScene)), &next, save));
#else
    return SceneOwner(func_0808AB38(::operator new(sizeof(ToolChestScene)), &next, save));
#endif
}

SceneOwner RefrigeratorTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_0808E818(::operator new(sizeof(RefrigeratorScene)), &next, save));
#else
    return SceneOwner(func_0808ECD8(::operator new(sizeof(RefrigeratorScene)), &next, save));
#endif
}

SceneOwner ShelfTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(func_08090E54(::operator new(sizeof(ShelfScene)), &next, save));
}

SceneOwner CookingTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_08099F0C(::operator new(sizeof(CookingScene)), &next, save, recipe_list));
#else
    return SceneOwner(func_0809A4D4(::operator new(sizeof(CookingScene)), &next, save, recipe_list));
#endif
}

SceneOwner ReferencePageTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(func_0807B038(::operator new(sizeof(ReferencePageScene)), &next, save, page_id));
}

SceneOwner SpecialMerchantShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_080815B8(::operator new(sizeof(SpecialMerchantShopScene)), &next, save));
#else
    return SceneOwner(func_08081A40(::operator new(sizeof(SpecialMerchantShopScene)), &next, save));
#endif
}

SceneOwner GiftWrappingTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_08092C7C(::operator new(sizeof(GiftWrappingScene)), &next, save));
#else
    return SceneOwner(func_080931B0(::operator new(sizeof(GiftWrappingScene)), &next, save));
#endif
}

SceneOwner YodelRanchShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_08087CA8(::operator new(sizeof(YodelRanchShopScene)), &next, save, unk_0C));
#else
    return SceneOwner(func_08088168(::operator new(sizeof(YodelRanchShopScene)), &next, save, unk_0C));
#endif
}

SceneOwner PoultryFarmShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0807CBD8(::operator new(sizeof(PoultryFarmShopScene)), &next, save, unk_0C));
#else
    return SceneOwner(func_0807D070(::operator new(sizeof(PoultryFarmShopScene)), &next, save, unk_0C));
#endif
}

SceneOwner WineryShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0808090C(::operator new(sizeof(WineryShopScene)), &next, save));
#else
    return SceneOwner(func_08080D94(::operator new(sizeof(WineryShopScene)), &next, save));
#endif
}

SceneOwner InnShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0807F0E8(::operator new(sizeof(InnShopScene)), &next, save));
#else
    return SceneOwner(func_0807F580(::operator new(sizeof(InnShopScene)), &next, save));
#endif
}

SceneOwner BeachCafeShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_08081C8C(::operator new(sizeof(BeachCafeShopScene)), &next, save));
#else
    return SceneOwner(func_08082114(::operator new(sizeof(BeachCafeShopScene)), &next, save));
#endif
}

SceneOwner WonShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_0807FFC4(::operator new(sizeof(WonShopScene)), &next, save));
#else
    return SceneOwner(func_0808045C(::operator new(sizeof(WonShopScene)), &next, save));
#endif
}

SceneOwner CarpenterShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(loc_0808506C(::operator new(sizeof(CarpenterShopScene)), &next, save));
#else
    return SceneOwner(func_080854F4(::operator new(sizeof(CarpenterShopScene)), &next, save));
#endif
}

SceneOwner ClinicShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0807E97C(::operator new(sizeof(ClinicShopScene)), &next, save));
#else
    return SceneOwner(func_0807EE14(::operator new(sizeof(ClinicShopScene)), &next, save));
#endif
}

// These late scene factories stay in native ROM order. Returning a temporary
// owner preserves the original two-word ownership-transfer ABI.
SceneOwner BlacksmithShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(func_08083A7C(::operator new(sizeof(BlacksmithShopScene)), &next, save, unk_1C, unk_0C, unk_10, unk_14, unk_18));
}

SceneOwner SupermarketPurchaseTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0807DFA0(::operator new(sizeof(SupermarketPurchaseScene)),
        &next, save, item_id));
#else
    return SceneOwner(func_0807E438(::operator new(sizeof(SupermarketPurchaseScene)),
        &next, save, item_id));
#endif
}

SceneOwner SupermarketTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
#if defined(REGION_JP)
    return SceneOwner(func_0807D8A0(::operator new(sizeof(SupermarketScene)), &next, save));
#else
    return SceneOwner(func_0807DD38(::operator new(sizeof(SupermarketScene)), &next, save));
#endif
}

SceneOwner ClockTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(func_08004B94(::operator new(sizeof(NewGameMenuScene)), save,
        next));
}

SceneOwner ReturnToGameScene::CreateScene()
{
    return SceneOwner(new GameScene(save, request));
}

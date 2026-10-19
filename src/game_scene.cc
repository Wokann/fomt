#include "prelude.h"
#include "new_game.hh"
#include <new>
#include "hardware_blend.hh"
#include "hardware_manager.hh"
#include "hardware_dma.hh"
#include "hardware_bootstrap.hh"
#include "hardware_nested_accessors.hh"
#include "game_state.hh"
#include "field_item_data.hh"
#include "field_render_rect_descriptors.hh"
#include "field_render_farm_house_data.hh"
#include "field_render_resource_data.hh"
#include "actor_state.hh"
#include "entity_actor.hh"
#include "npc_entity.hh"
#include "entity_ui.hh"
#include "fomt_constants.hh"
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_US)
#include "data/scripts/us/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#else
#include "data/scripts/de/fomt_scripts.mary.h"
#endif
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "font.hh"
#include "gbasvc.h"
#include "gbaio.h"
#include <iterator>

#pragma implementation "game_scene.hh"
#include "game_scene.hh"

template <u32 Capacity>
inline void GameSceneScriptQueue<Capacity>::Push(GameSceneScriptRequest const & request)
{
    if (count < Capacity) {
        new (End()) GameSceneScriptRequest(request);
        ++count;
    }
}

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

SceneTransitionOwner GameSceneScriptController::Run()
{
    HardwareManagerOwner hardware;
    SceneOwner scene;
    if (unk_364 != 0)
    {
        GameSceneResumeRequest request(0);
        scene = new GameScene(save.get(), request);
    }
    else
    {
        GameSceneResumeRequest request(1);
        scene = new GameScene(save.get(), request);
    }
    SceneMain(scene);
    return SceneTransitionOwner();
}

GameSceneControllerActorRecord * func_080100F0(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return controller->actor_records;
}

GameSceneControllerLocationRecord * func_08010104(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return controller->location_records;
}

GameSceneScriptQueue<2> * func_08010118(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return &controller->queues.queue_0;
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
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return &controller->script_engine;
}

GameSceneScriptController::~GameSceneScriptController()
{
    gUnk_0300040C = nullptr;
}

inline GameSceneState::GameSceneState(GameScene * owner, GameStateSaveImage * image,
    GameSceneResumeRequest const & request)
    : scene(owner), save(image), resume_request(request), screen_blend(nullptr),
      game_object(nullptr), text_variables(nullptr), bgm_player(0), music_player_1(1),
      music_player_2(2), music_player_3(3), music_player_4(4)
{
    unk_E8 = 0;
    unk_EA[0] = 0;
    unk_F0 = nullptr;
}

GameSceneState::~GameSceneState()
{
    ::operator delete(unk_F0);
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
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    controller->script_engine.SetUnk(this);
}

#if !defined(REGION_JP)
GameScene::GameScene(GameStateSaveImage * image)
{
    GameSceneState * core = new GameSceneState(this, image, GameSceneResumeRequest(2));
    u16 status = core->display.status;
    status |= 8;
    core->display.status = status;
    REG_DISPSTAT = status;
    state = core;
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    controller->script_engine.SetUnk(this);
}
#endif

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
    func_08008AE0(manager)->Append(&commands);
    func_08008AF0(manager);
    func_08008AE0(manager)->Remove(&commands);

    // The temporary list and commands unlink in reverse construction order.
}

GameScene::~GameScene()
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
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
    func_080D7F9C(current, id, map, x, y, facing);
}

i32 GameScene::GetEntityX(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16X();
    return value >> 16;
}

i32 GameScene::GetEntityY(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16Y();
    return value >> 16;
}

void GameScene::SetEntityFacing(u32 id, u32 facing)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr && entity->facing != facing)
        entity->SetAnimFacing(facing);
}

u32 GameScene::GetEntityFacing(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    return entity != nullptr ? entity->facing : 0;
}

u32 GameScene::GetEntityMap(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    u32 map = MAP_NONE;
    if (entity != nullptr)
        map = entity->GetMap();
    return map;
}

void GameScene::SetEntitySpritePriority(u32 id, u32 priority)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        entity->unk_21 = priority;
}

void GameScene::MoveEntityXTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        func_08032308(*entity, target, speed_q16);
}

void GameScene::MoveEntityYTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        func_0803233C(*entity, target, speed_q16);
}

void GameScene::WaitForEntityMovement(u32 id)
{
    GameSceneState * current = state;
    AActorEntity * entity = current->game_object.value->GetActorEntity(id);
    current->waiting_entity = entity;
    if (entity != nullptr)
        current->script_state = 0x16;
}

void GameScene::SetEntityAnim(u32 id, u32 animation)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr && entity->anim_id != animation)
        entity->SetAnim(animation);
}

void GameScene::NoOp014(i32)
{
}

void GameScene::HideEntity(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        entity->PutOutOfTown();
}

void GameScene::OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
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
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        func_08032384(*entity, effect, persistent != 0);
}

void GameScene::StopEntityEffect(u32 id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        func_080323C8(*entity);
}

void GameScene::SetEntityAuxRenderProfile(u32 id, u32 profile)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(id);
    if (entity != nullptr)
        func_080323E0(*entity, profile);
}

void GameScene::ChangeMap(u32 map, i32 x, i32 y)
{
    GameSceneState * current = state;
    current->game_object.value->ChangeMap(Location(map, x, y), true);
    func_080D7F08(current);
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
    StartSceneSong(&current->bgm_player.value, mode, static_cast<u16>(sequence));
    ApplySceneBgmSettings(settings, &current->bgm_player.value);
}

void GameScene::StopBGM()
{
    func_08008BE0(&state->bgm_player.value);
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
        func_08009378(current->screen_blend.value, step, mode, mosaic);
        current->script_state = 0x12;
        current->unk_E8 = 0;
        current->unk_E9 = mode == 2;
    } else {
        // The third callable uses this same path but suppresses the hook.
        if (call_scene_hook != 0)
            current->game_object.value->vfunc_B8();
        func_0800934C(current->screen_blend.value, step, mode, mosaic);
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
    func_0803B6B8(current->text_variables.value, slot, text);
}

void GameScene::TextVariableSetString(u32 slot, char const * text)
{
    func_0803B6B8(state->text_variables.value, slot, text);
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
    func_0803B6B8(current->text_variables.value, slot, text);
}

void GameScene::CallScript(i32 script_id, i32 context_value)
{
    GameSceneState * current = state;
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    controller->script_engine.LoadById(script_id, context_value);
    func_080D7F3C(current);
}

void GameScene::QueueScript(GameSceneScriptRequest const & request, i32 queue_kind)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
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

// These calls refresh map tiles after the caller updates feed storage.
// The native path forwards the original index without another bounds check.
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

// ENTITY_PLAYER is required here, unlike the nullable arbitrary-entity calls.
bool GameScene::IsPlayerRidingHorse()
{
    return static_cast<GameScenePlayerActor *>(state->game_object.value->GetActorEntity(ENTITY_PLAYER))->IsRidingHorse();
}

bool GameScene::TryShipPlayerHeldItem()
{
    GameSceneState * current = state;
    bool result;
    if (static_cast<GameScenePlayerActor *>(current->game_object.value->GetActorEntity(ENTITY_PLAYER))->TryShipHeldItem()) {
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
    static_cast<GameScenePlayerActor *>(current->game_object.value->GetActorEntity(ENTITY_PLAYER))->SetHeldItem(item, wrapped);
    current->script_state = 0x19;
    return true;
}

bool GameScene::GivePlayerBasket()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object.value->GetActorEntity(ENTITY_PLAYER))->GiveBasket();
    current->script_state = 0x19;
    return true;
}

void GameScene::ThrowPlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object.value->GetActorEntity(ENTITY_PLAYER))->ThrowHeldItem();
    current->script_state = 0x19;
}

void GameScene::UsePlayerHeldItem()
{
    GameSceneState * current = state;
    static_cast<GameScenePlayerActor *>(current->game_object.value->GetActorEntity(ENTITY_PLAYER))->UseHeldItem();
    current->script_state = 0x19;
}

void GameScene::ClearPlayerHeldItem()
{
    static_cast<GameScenePlayerActor *>(state->game_object.value->GetActorEntity(ENTITY_PLAYER))->ClearHeldItem();
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
    AActorEntity * entity = state->game_object.value->GetActorEntity(entity_id);
    if (entity != nullptr)
        entity->SetEventScript(script_id);
}

void GameScene::ClearEntityEventScript(u32 entity_id)
{
    AActorEntity * entity = state->game_object.value->GetActorEntity(entity_id);
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

EC GameSceneSongPlayerPool & func_0801468C(GameScene & scene)
{
    return scene.state->song_players;
}

EC u32 func_0801740C(FieldPlot const & plot)
{
    switch (plot.GetUnk2()) {
    case 0x1B:
    case 0x1F:
    case 0x23:
    default:
        return 0;
    case 0x1C:
    case 0x20:
    case 0x24:
        return 1;
    case 0x1D:
    case 0x21:
    case 0x25:
        return 2;
    case 0x1E:
    case 0x22:
    case 0x26:
        return 3;
    }
}

EC u32 func_0801746C(FieldPlot const & plot)
{
    switch (plot.GetUnk2()) {
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    default:
        return 0;
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
        return 1;
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
        return 2;
    }
}

EC bool func_080174C8(Farm & farm, FieldItemState & items, u32 index, i32 season,
    i32 power, bool hammer, GameSceneFieldItemToolResult & result)
{
    FieldItemInstance const & record = items.GetRecord(index);
    i32 minimum = 0;
    i32 remaining;
    if (hammer) {
        switch (record.kind) {
        case 0x13: minimum = 2; break;
        case 0x14: minimum = 7; break;
        default: goto failure;
        }
    } else {
        switch (record.kind) {
        case 0x12: break;
        case 0x15: minimum = 1; break;
        default: goto failure;
        }
    }

    // A valid target is accepted even if this hit does not remove it.
    result.rejected = false;
    remaining = power - minimum;
    if (remaining <= 0)
        goto failure;
    if (record.kind != 0x12)
        items.DecreaseResourceValue(index, remaining);
    if (record.kind != 0x12 && items.GetResourceValue(index) != 0)
        goto failure;

    items.ClearAvailability(index, season);
    result.removed = true;
    result.x = record.x;
    result.y = record.y;
    switch (record.kind) {
    case 0x15:
        farm.method_08009B68(6);
        result.kind = 7;
        break;
    case 0x12:
        farm.method_08009B68(1);
        result.kind = 4;
        break;
    case 0x13:
        result.kind = 6;
        break;
    case 0x14:
        result.kind = 9;
        break;
    }
    return true;
failure:
    return false;
}

EC bool func_08019F38(GameSceneWorldPrefix & world, Location const & location)
{
    if (GetMapData(world.data.map.value->map_data_id)->flags != 0
        || (func_0800E324(world.save->clock.calendar) != SEASON_WINTER
            && !func_080A5EB8(world.data.map.value, location)))
        return false;
    return true;
}

EC i32 GetWorldMapPixelWidth(GameSceneWorldPrefix & world, u32 map)
{
    u32 season = func_0800E324(world.save->clock.calendar);
    u32 house = world.save->farm.farm_house.GetUpgradeLevel();
    u32 coop = world.save->farm.coop.GetUpgradeLevel();
    u32 barn = world.save->farm.barn.GetUpgradeLevel();
    u32 data_id = SelectMapDataId(map, season, house, coop, barn);
    return GetMapData(data_id)->width * 8;
}

EC i32 GetWorldMapPixelHeight(GameSceneWorldPrefix & world, u32 map)
{
    u32 season = func_0800E324(world.save->clock.calendar);
    u32 house = world.save->farm.farm_house.GetUpgradeLevel();
    u32 coop = world.save->farm.coop.GetUpgradeLevel();
    u32 barn = world.save->farm.barn.GetUpgradeLevel();
    u32 data_id = SelectMapDataId(map, season, house, coop, barn);
    return GetMapData(data_id)->height * 8;
}

EC MapTerrainView GetWorldMapTerrain(GameSceneWorldPrefix & world, u32 map_id)
{
    if (map_id > MAP_LAKE_MINE_FLOOR_255)
        return MapTerrainView(nullptr, 0, 0);
    u32 current_map = world.data.map.value->map;
    if (map_id == MAP_FARM && current_map != MAP_FARM)
        return MapTerrainView(world.farm_tile_attributes, 128, 88);

    u32 data_id;
    if (current_map == map_id) {
        data_id = world.data.map.value->map_data_id;
    } else {
        u32 season = func_0800E324(world.save->clock.calendar);
        u32 house = world.save->farm.farm_house.GetUpgradeLevel();
        u32 coop = world.save->farm.coop.GetUpgradeLevel();
        u32 barn = world.save->farm.barn.GetUpgradeLevel();
        data_id = SelectMapDataId(map_id, season, house, coop, barn);
    }
    MapData const * data = GetMapData(data_id);
    u32 width = data->width;
    u32 height = data->height;
    FieldRenderTileAttributes const * attributes;
    u8 const * indices;
    if (current_map == map_id) {
        GameSceneWorldMapPrefix * active = world.data.map.value;
        // The native branch performs this lookup even though its result is unused.
        GetMapData(active->map_data_id);
        indices = nullptr;
        attributes = active->tile_attributes;
    } else {
        indices = static_cast<u8 const *>(data->terrain_map);
        attributes = static_cast<FieldRenderTileAttributes const *>(data->terrain_data);
    }
    return MapTerrainView(attributes, indices, width, height);
}

EC TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorldPrefix &, u32 hour)
{
    if (hour <= 5)
        return TIME_OF_DAY_PERIOD_NIGHT;
    else if (hour <= 11)
        return TIME_OF_DAY_PERIOD_MORNING;
    else if (hour > 17)
        return TIME_OF_DAY_PERIOD_EVENING;
    else
        return TIME_OF_DAY_PERIOD_AFTERNOON;
}

EC u32 func_0801B5C0(GameSceneWorldPrefix & world, i32 kind)
{
    switch (kind) {
    case 0: return 0;
    case 1:
    case 2:
    case 4: return 1;
    case 3:
    case 5: return 2;
    case 14: return 3;
    case 15:
    case 16:
    case 17:
    case 18: return 4;
    case 6:
    case 7:
    case 8:
    case 26: return 5;
    }

    u32 first = 6;
    switch (world.vfunc_14()) {
    case MAP_FARM:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 10;
        case 13: return 11;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 12;
        }
        break;
    case MAP_HARVEST_SPRITES_HUT:
        switch (kind) {
        case 19:
        case 21:
        case 22: return 6;
        case 20:
        case 23:
        case 25: return 7;
        case 24: return 8;
        default: first = 9;
        }
        break;
    case MAP_BARN:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 10;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 11;
        }
        break;
    case MAP_CHICKEN_COOP:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 10;
        }
        break;
    case MAP_HORSE_STABLE:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 13: return 7;
        default: first = 8;
        }
        break;
    case MAP_FARMHOUSE:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        default: first = 7;
        }
        break;
    case MAP_SOUTH_SIDE_TOWN:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 7;
        case 31: return 8;
        default: first = 9;
        }
        break;
    case MAP_MOTHERS_HILL_SUMMIT: {
        if (kind == 29)
            return 6;
        first = 7;
        u32 wish_state = world.save->event_state.shooting_star_wish_event_state;
        if (wish_state == 1) {
            if (kind == 28)
                return 7;
            first = 8;
        }
        break;
    }
    case MAP_CHURCH:
        if (world.save->event_state.IsActiveRomanceEvent(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE)) {
            switch (kind) {
            case 19:
            case 21:
            case 22: return 6;
            case 20:
            case 23:
            case 25: return 7;
            case 24: return 8;
            default: first = 9;
            }
        }
        break;
    case MAP_MOTHERS_HILL_MIDDLE:
        if (kind == 30)
            return 6;
        first = 7;
        break;
    case MAP_KAI_RESTAURANT: {
        GameEventState const & events = world.save->event_state;
        u32 cafe_state = events.popuri_brings_customers_to_kais_beach_cafe_event_state;
        if (cafe_state == 1) {
            switch (kind) {
            case 19:
            case 21:
            case 22: return 6;
            case 20:
            case 23:
            case 25: return 7;
            case 24: return 8;
            default: first = 9;
            }
        }
        break;
    }
    case MAP_ROSE_SQUARE:
        if (kind == 32)
            return 6;
        first = 7;
        break;
    case MAP_MINERAL_BEACH:
    case MAP_FOREST:
    case MAP_BEHIND_CHURCH:
    case MAP_NORTH_SIDE_TOWN:
    case MAP_POULTRY_FARM_HOUSE_1F:
    case MAP_POULTRY_FARM_HOUSE_2F:
    case MAP_ZACK_HOUSE:
    case MAP_ELLEN_HOUSE:
    case MAP_SUPERMARKET:
    case MAP_SUPERMARKET_BACK_ROOM:
    case MAP_MOUNTAIN_COTTAGE:
    case MAP_MINERAL_CLINIC_1F:
    case MAP_MINERAL_CLINIC_2F:
    case MAP_INN_1F:
    case MAP_INN_BACK_ROOM:
    case MAP_INN_2F:
    case MAP_LIBRARY_1F:
    case MAP_LIBRARY_2F:
    case MAP_BASIL_HOUSE_1F:
    case MAP_BASIL_HOUSE_2F:
    case MAP_MAYOR_HOUSE:
    case MAP_AJA_WINERY_1F:
    case MAP_AJA_WINERY_2F:
    case MAP_AJA_WINERY_STORAGE_1F:
    case MAP_AJA_WINERY_STORAGE_B1F:
    case MAP_BEACH_HOUSE:
    case MAP_BLACKSMITH:
    case MAP_TOWN_COTTAGE:
    case MAP_GOTZ_HOUSE:
    case MAP_YODEL_RANCH_HOUSE_1F:
    case MAP_YODEL_RANCH_HOUSE_2F:
    case MAP_LAKE_MINE_ENTRANCE:
    case MAP_MOTHERS_HILL_SUMMIT_CLEAR:
    case MAP_MOTHERS_HILL_SUMMIT_RAIN:
    case MAP_MOTHERS_HILL_SUMMIT_SNOW:
    case MAP_TUTORIAL_FIELD:
        break;
    }
    GameScenePaletteCache & cache = world.data.palette_cache;
    for (u32 index = first; index < cache.ResourceCount(); ++index) {
        GameScenePaletteResource & resource = cache.resources[index];
        if (resource.unk_81 == 0) {
            resource.unk_81 = 1;
            return index;
        }
    }
    return ARRAY_COUNT(cache.resources) - 1;
}

EC bool TryGetFarmPlotAtLocation(GameSceneWorldPrefix & world, Location const & location,
    GameSceneFarmPlotLocation & output)
{
    // Each farm plot spans two 8-pixel tiles from the field origin.
    u32 first_x = 34;
    u32 first_y = 22;
    bool found = false;
    if (location.GetMap() == MAP_FARM) {
        u32 x = location.GetX() / 8;
        u32 y = location.GetY() / 8;
        if (x >= first_x && y >= first_y &&
            x <= first_x + Farm::FIELD_WIDTH * 2 - 1 &&
            y <= first_y + Farm::FIELD_HEIGHT * 2 - 1) {
            u32 column = (x - first_x) / 2;
            u32 row = (y - first_y) / 2;
            output.plot = &world.save->farm.field.PlotAt(column, row);
            output.tile_x = column * 2 + first_x;
            output.tile_y = row * 2 + first_y;
            output.column = column;
            output.row = row;
            found = true;
        }
    }
    return found;
}

EC u32 func_0801C29C(GameSceneWorldPrefix & world, Location const & location)
{
    u32 result = 0;
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        result = hit.plot->method_0800A190(world.save->clock.unk_00 == WEATHER_SUNNY);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMapPrefix * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
        if (result == 3) {
            for (u32 index = 0; index < ARRAY_COUNT(world.unk_1080); ++index) {
                if (world.unk_1080[index].state == 0) {
                    world.unk_1080[index].state = 2;
                    world.unk_1080[index].tile_x = hit.tile_x;
                    world.unk_1080[index].tile_y = hit.tile_y;
                    break;
                }
            }
        }
    }
    return result;
}

EC u32 func_0801D3FC(GameSceneWorldPrefix & world, Location const & location)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        u32 result = hit.plot->method_0800A438();
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMapPrefix * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
        if (result == 1)
            return 1;
    }
    return 0;
}

EC void func_0801D4E0(GameSceneWorldPrefix & world, Location const & location, i32 id)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        hit.plot->method_0800A460(id);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMapPrefix * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    }
}

EC void func_0801D5BC(GameSceneWorldPrefix & world, Location const & location,
    RucksackItem & output)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        output = hit.plot->method_0800A4A4();
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMapPrefix * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    } else {
        output = PickUpFieldItemAtLocation(world, location);
    }
}

EC RucksackItem PickUpFieldItemAtLocation(GameSceneWorldPrefix & world, Location const & location)
{
    FieldItemState & items = world.save->field_items;
    i32 season = func_0800E324(world.save->clock.calendar);
    Box area(location.GetX(), location.GetY(), 1, 1);
    i32 index = items.Find(location.GetMap(), area, season);
    RucksackItem item;
    if (index != -1) {
        item = items.PickUp(location.GetMap(), area, season);
        if (!item.IsEmpty() && location.GetMap() == world.data.map.value->map) {
            FieldItemInstance record = items.GetRecord(index);
            GameSceneWorldMapPrefix * map = world.data.map.value;
            Vec2 position(record.x / 8, record.y / 8);
            func_080A5F78(map, 1, position, 2, 2);
        }
    }
    return item;
}

EC void func_0801D7B0(GameSceneWorldPrefix & world, Location const & location,
    Article const & article)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        hit.plot->method_0800A6F4(article);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMapPrefix * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    }
}

EC u32 func_0801D88C(GameSceneWorldPrefix & world, Location const & location,
    Article const & article)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        if (hit.plot->method_0800A6C8(article))
            return 0;
        return 1;
    }
    return 2;
}

EC void func_0801D8CC(GameSceneWorldPrefix & world)
{
    world.unk_103C[0] = 1;
    if (world.save->scripted_npc_control) {
        // The original control path still notifies every actor here.
        AActorEntity ** it = world.data.entities;
        AActorEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_20();
        }
    } else {
        AActorEntity ** it = world.data.entities;
        AActorEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_20();
        }
    }
}

EC void func_0801D948(GameSceneWorldPrefix & world)
{
    world.unk_103C[0] = 0;
    if (world.save->scripted_npc_control) {
        world.data.entities[0]->vfunc_24();
    } else {
        AActorEntity ** it = world.data.entities;
        AActorEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_24();
        }
    }
}

EC void func_0801D9A8(GameSceneWorldPrefix & world,
    GameSceneScriptRequest const & request, i32 queue_kind)
{
    world.scene->QueueScript(request, queue_kind);
}

EC u32 func_0801D9BC(GameSceneWorldPrefix & world)
{
    GameStateClock const & clock = world.save->clock;
    if (clock.unk_00 == WEATHER_RAIN)
        return AUDIO_AMBIENCE_RAIN;
    if (clock.unk_00 == WEATHER_TYPHOON || clock.unk_00 == WEATHER_SNOWSTORM)
        return AUDIO_AMBIENCE_STORM;

    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    u32 map = world.vfunc_14();
    if (map >= MAP_SPRING_MINE_FLOOR_0 && map <= MAP_LAKE_MINE_FLOOR_255)
        map = MAP_FARM;
    switch (map) {
    case MAP_MOTHERS_HILL_MIDDLE:
    case MAP_FARM:
    case MAP_FOREST:
    case MAP_MOTHERS_HILL_SUMMIT:
    case MAP_HORSE_STABLE:
    case MAP_CHICKEN_COOP:
    case MAP_MOUNTAIN_COTTAGE:
    case MAP_FARMHOUSE:
    case MAP_BARN:
    case MAP_LAKE_MINE_ENTRANCE:
    {
        u8 hour = clock.calendar.time.clock_hour;
        if (static_cast<u8>(hour - 6) <= 13) {
            if (record_player != nullptr && record_player->HasAlbum())
                return record_player->GetUnknown();
            switch (static_cast<i32>(func_0800E324(clock.calendar))) {
            case SEASON_SPRING:
            default:
                return AUDIO_BGM_SPRING;
            case SEASON_SUMMER:
                return AUDIO_BGM_SUMMER;
            case SEASON_FALL:
                return AUDIO_BGM_AUTUMN;
            case SEASON_WINTER:
                return AUDIO_BGM_WINTER;
            }
        }
        goto night;
    }
    case MAP_MINERAL_BEACH:
    case MAP_ZACK_HOUSE:
    case MAP_BEACH_HOUSE:
    case MAP_KAI_RESTAURANT:
        return AUDIO_AMBIENCE_BEACH;
    }
    {
        u8 hour = clock.calendar.time.clock_hour;
        if (static_cast<u8>(hour - 6) <= 13)
            return AUDIO_BGM_MINERAL_TOWN;
    }
night:
    return AUDIO_AMBIENCE_NIGHT;
}

EC GameSceneSongPlayerPool & func_0801DB44(GameSceneWorldPrefix & world)
{
    return func_0801468C(*world.scene);
}

EC void func_0801DB58(GameSceneWorldPrefix & world)
{
    GameSceneBgmSettings settings;
    i32 map = world.vfunc_14();
    if ((map >= MAP_SPRING_MINE_FLOOR_0 && map <= MAP_LAKE_MINE_FLOOR_255)
        || map == MAP_LAKE_MINE_ENTRANCE) {
        i32 floor;
        if (map != MAP_LAKE_MINE_ENTRANCE) {
            if (map > MAP_SPRING_MINE_FLOOR_255)
                floor = map - MAP_LAKE_MINE_FLOOR_0;
            else
                floor = map - MAP_SPRING_MINE_FLOOR_0;
        } else {
            floor = 9;
        }
        i32 pitch = settings.pitch;
        settings.pitch = pitch + (-0xA00 - pitch) * (floor + 1) / 0x100;
    }
    i32 fatigue = func_0800E4FC(world.save->farmer);
    if (fatigue > 79) {
        settings.modulation_depth = fatigue - 79;
        settings.lfo_speed = 3;
    }
    GameScene * scene = world.scene;
    u32 sequence = world.GetDefaultAudioSequence();
    scene->PlayBGM(AUDIO_START_WEAK, sequence, settings);
}

EC void func_0801DC24(GameSceneWorldPrefix & world, u32 index)
{
    GameSceneIndexedSprite * sprite = world.unk_1058.Get();
    if (sprite != nullptr) {
        ResolveIndexedResourceHandle(&sprite->handle, index);
        sprite->unk_3C = 1;
        sprite->unk_3E = 0;
        sprite->unk_3F = 1;
    } else {
        world.unk_1058 = new GameSceneIndexedSprite(
            reinterpret_cast<IndexedResourceProvider *>(world.vfunc_5C()),
            index, &world, 3, 0x1B, true);
    }
}

EC void func_0801DCA8(GameSceneWorldPrefix & world)
{
    world.unk_1058 = nullptr;
}

EC void CollectDailyShippingRevenue(GameSceneWorldPrefix & world)
{
    i32 value = world.save->farm.shipping_bin.GetValueShipped();
    world.save->CollectShippingRevenue();
    world.QueueScript(GameSceneScriptRequest(
        EventScript_FarmEvent_Zack_DailyShippingPickup, value), 1);
}

EC void func_0801DD18(GameSceneWorldPrefix & world)
{
    func_080A6138(world.data.map.value);
}

EC void func_0801DD24(GameSceneWorldPrefix & world)
{
    func_080A6194(world.data.map.value);
}

EC void func_0801DD30(GameSceneWorldPrefix & world)
{
    func_080A61F0(world.data.map.value);
}

EC void func_0801DD3C(GameSceneWorldPrefix & world)
{
    func_080A6234(world.data.map.value);
}

EC void func_0801DD48(GameSceneWorldPrefix & world)
{
    func_080A6278(world.data.map.value);
}

EC void func_0801DD54(GameSceneWorldPrefix & world)
{
    func_080A62BC(world.data.map.value);
}

EC void func_0801DD60(GameSceneWorldPrefix & world, u32 index)
{
    func_080A607C(world.data.map.value, index);
}

EC void func_0801DD6C(GameSceneWorldPrefix & world, u32 index)
{
    RefreshCoopFeedTrough(world.data.map.value, index);
}

EC void func_0801DD78(GameSceneWorldPrefix & world)
{
    func_080A601C(world.data.map.value);
}

EC MaryItemArticleId RemoveRecordPlayerAlbum(GameSceneWorldPrefix & world)
{
    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    func_080A6300(world.data.map.value);
    ArticleStack album = record_player->RemoveAlbum();
    func_0801DB58(world);
    return static_cast<MaryItemArticleId>(album.GetArticle().GetId());
}

EC void func_0801DDCC(GameSceneWorldPrefix & world, u32 index)
{
    func_0809C5B4(world.save->unk_34D8.value, index);
    func_080AA850(static_cast<GameSceneSavedMapPrefix *>(world.data.map.value), index);
}

EC void func_0801DDF8(GameSceneWorldPrefix & world, u32 index)
{
    func_0809C5D0(world.save->unk_34D8.value, index);
    func_080AA850(static_cast<GameSceneSavedMapPrefix *>(world.data.map.value), index);
}

EC void func_0801DE24(GameSceneWorldPrefix & world, u32 unk)
{
    func_080A63B8(world.data.map.value, unk);
}

EC void func_0801DE30(GameSceneWorldPrefix & world)
{
    func_080AA89C(world.data.map.value);
}

EC void func_0801DE3C(GameSceneWorldPrefix & world)
{
    func_080AA8BC(world.data.map.value);
}

EC void func_0801DE48(GameSceneWorldPrefix & world)
{
    func_080AA8DC(static_cast<GameSceneSavedMapPrefix *>(world.data.map.value));
}

EC MaryItemArticleId SwapRecordPlayerAlbum(GameSceneWorldPrefix & world, MaryItemArticleId article_id)
{
    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    func_080A635C(world.data.map.value);
    ArticleStack album = record_player->SetAlbum(Article(article_id));
    func_0801DB58(world);
    return static_cast<MaryItemArticleId>(album.GetArticle().GetId());
}

GameSceneWorldUnk1020::~GameSceneWorldUnk1020()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->vfunc_4C(indices[0]);
}

GameSceneSpriteBase::~GameSceneSpriteBase()
{
    for (u32 index = 0; index < palettes.count; ++index)
        world->vfunc_4C(palettes[index]);
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kind),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
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

EC void UpdateWorldMap(GameSceneWorldMapPrefix * map)
{
    if (map->movement_frames != 0) {
        map->x.q16 += map->step_x_q16;
        map->y.q16 += map->step_y_q16;
        --map->movement_frames;
        map->view_changed = true;
    }
    // These are layout indices, not the logical MAP_* identifiers.
    switch (map->map_data_id) {
    case 14:
        map->layout_animations[4].Tick(gMapLayoutTileAnimation8);
        map->layout_animations[5].Tick(gMapLayoutTileAnimation9);
        map->layout_animations[6].Tick(gMapLayoutTileAnimation10);
        break;
    case 15:
        map->layout_animations[4].Tick(gMapLayoutTileAnimation11);
        map->layout_animations[5].Tick(gMapLayoutTileAnimation12);
        map->layout_animations[6].Tick(gMapLayoutTileAnimation13);
        break;
    case 60:
        map->layout_animations[8].Tick(gMapLayoutTileAnimation17);
        break;
    case 31:
        map->layout_animations[9].Tick(gMapLayoutTileAnimation15);
        break;
    case 8:
        map->layout_animations[7].Tick(gMapLayoutTileAnimation14);
        break;
    case 9:
        map->layout_animations[7].Tick(gMapLayoutTileAnimation16);
        break;
    case 6:
        map->layout_animations[2].Tick(gMapLayoutTileAnimation4);
        map->layout_animations[3].Tick(gMapLayoutTileAnimation5);
        break;
    case 7:
        map->layout_animations[2].Tick(gMapLayoutTileAnimation6);
        map->layout_animations[3].Tick(gMapLayoutTileAnimation7);
        break;
    case 0:
    case 62:
    case 63:
        map->layout_animations[0].Tick(gMapLayoutTileAnimation0);
        map->layout_animations[1].Tick(gMapLayoutTileAnimation2);
        break;
    case 1:
        map->layout_animations[0].Tick(gMapLayoutTileAnimation1);
        map->layout_animations[1].Tick(gMapLayoutTileAnimation3);
        break;
    }
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
        map->view_changed = true;
        map->x.q16 = position.x << 16;
    }
    i32 current_y = map->y.parts.integer;
    if (current_y != position.y) {
        map->view_changed = true;
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

EC void ApplyMapTilePatch(GameSceneWorldMapPrefix * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y)
{
    u32 map_width = GetMapData(map->map_data_id)->width;
    u32 width = patch.width;
    u32 height = patch.height;
    void const * const * buffers = patch.source_buffers;
    for (u32 layer = 0; layer < 3; ++layer) {
        if (buffers[layer] != nullptr) {
            for (u32 row = 0; row < height; ++row) {
                memcpy(map->tile_layers[layer] + x + (y + row) * map_width,
                    static_cast<u16 const *>(buffers[layer]) + row * width,
                    width * sizeof(u16));
            }
        }
    }
    if (patch.lookup_indices != nullptr && patch.lookup_values != nullptr) {
        for (u32 row = 0; row < height; ++row) {
            u8 const * source = static_cast<u8 const *>(patch.lookup_indices) + row * width;
            FieldRenderTileAttributes * destination = map->tile_attributes + x + (y + row) * map_width;
            for (u32 column = 0; column < width; ++column) {
                *destination++ = static_cast<FieldRenderTileAttributes const *>(patch.lookup_values)[*source++];
            }
        }
    }
}

EC void LoadWorldMapTilemaps(GameSceneWorldMapPrefix & map)
{
    MapData const * data = GetMapData(map.map_data_id);
    u32 layer = 0;
    u16 ** destination = map.tile_layers;
    for (; layer < 3; ++destination, ++layer) {
        u8 const * source = data->tilemaps[layer];
        if (source != nullptr)
            Unpack(source, *destination);
        else
            func_08008EB8(0x03FF03FF, *destination, static_cast<u32>(data->width) * (data->height << 1));
    }
    map.view_changed = true;
}

EC void SetWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period)
{
    switch (period) {
    case TIME_OF_DAY_PERIOD_NIGHT:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 1);
        break;
    case TIME_OF_DAY_PERIOD_MORNING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 1);
        break;
    case TIME_OF_DAY_PERIOD_AFTERNOON:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 1);
        break;
    case TIME_OF_DAY_PERIOD_EVENING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 1);
        break;
    }
    map.time_palette_changed = true;
}

EC void LoadWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period,
    u32 buffer_index)
{
    MapData const * data = GetMapData(map.map_data_id);
    // The native loader first decodes the default palette even when the
    // selected period will decode that same resource again below.
    Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
    switch (period) {
    case TIME_OF_DAY_PERIOD_MORNING:
    case TIME_OF_DAY_PERIOD_AFTERNOON:
    case TIME_OF_DAY_PERIOD_EVENING:
        Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
        break;
    case TIME_OF_DAY_PERIOD_NIGHT:
        Unpack(data->palettes[1], map.time_palette_buffers[buffer_index]);
        break;
    }
}

EC void LoadWorldMapTiles(GameSceneWorldMapPrefix & map)
{
    MapData const * data = GetMapData(map.map_data_id);
    Unpack(data->tiles, reinterpret_cast<void *>(0x06000000));
}

EC bool func_080A5EB8(GameSceneWorldMapPrefix * map, Location const & location)
{
    if (location.GetMap() != MAP_MINERAL_BEACH || map->map != MAP_MINERAL_BEACH
        || map->map_data_id != 8)
        return false;

    Vec2 position(location.GetX() / 8, location.GetY() / 8);
    u32 width = GetMapData(8)->width;
    for (u32 layer = 0; layer < 3; ++layer) {
        u16 const * column = map->tile_layers[2 - layer] + position.x;
        column += position.y * width;
        u32 tile = *column & 0x3FF;
        if (tile != 0x3FF) {
            if (tile - 0x58 <= 0x3C || tile <= 0x33)
                return true;
            return false;
        }
    }
    return false;
}

EC void func_080A601C(GameSceneWorldMapPrefix * map)
{
    map->unk_58 = 0x14;
}

EC void RefreshCoopFeedTrough(GameSceneWorldMapPrefix * map, u32 index)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x24:
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[36],
            gFieldRenderPatchArgumentData.values_00[index], 8);
        break;
    case 0x40:
    {
        FieldRenderRectDescriptor const & patch = gFieldRenderRectDescriptors[36];
        u8 const * coordinates = gFieldRenderPatchArgumentData.values_08;
        ApplyMapTilePatch(map, patch,
            coordinates[index], 4);
        break;
    }
    }
    map->view_changed = true;
}

EC void func_080A6138(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6194(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A61F0(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[16], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[16], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6234(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[17], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[17], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6278(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[18], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[18], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A62BC(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[19], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[19], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6300(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A635C(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A63B8(GameSceneWorldMapPrefix * map, u32 unk)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x40:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, 0xD);
        break;
    case 0x24:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, 0x11);
        break;
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, unk == 0 ? 0x11 : 0xD);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC u32 SelectDefaultWorldMapData(GameSceneWorldMapPrefix const * map)
{
    return SelectMapDataId(map->map, SEASON_SUMMER, 0, 0, 0);
}

EC FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMapPrefix * map,
    u32 x, u32 y)
{
    u32 width = GetMapData(map->map_data_id)->width;
    return &map->tile_attributes[x + y * width];
}

EC u32 GetWorldMapDataId(GameSceneWorldMapPrefix const * map)
{
    return map->map_data_id;
}

EC u32 GetWorldMapId(GameSceneWorldMapPrefix const * map)
{
    return map->map;
}

EC i32 GetWorldMapViewY(GameSceneWorldMapPrefix const * map)
{
    return map->y.parts.integer;
}

EC i32 GetWorldMapViewX(GameSceneWorldMapPrefix const * map)
{
    return map->x.parts.integer;
}

EC void UpdateSavedMapTileAnimationTimers(GameSceneSavedMapPrefix * map)
{
    UpdateWorldMap(map);
    GameStateSaveImage * save = map->save;
    if (map->map == MAP_ROSE_SQUARE
        && save->event_state.harvest_festival_active == FESTIVAL_PHASE_INITIAL) {
        map->tile_animations[0].Tick(gMapTilePatchAnimation0);
        map->tile_animations[1].Tick(gMapTilePatchAnimation1);
    }
}

static inline bool AdvanceMapAnimationFrame(MapTilePatchAnimationState & state, u32 count)
{
    return ++state.frame == count;
}

static inline void QueueMapAnimationFrame(MapTilePatchAnimationState & state,
    GameSceneWorldMapPrefix * map, FarmHouseTilePatchAnimationDescriptor const & animation,
    HardwareDmaQueue & queue)
{
    if (state.update_pending) {
        state.update_pending = false;
        QueueMapTilePatch(map, animation.patch, state.frame, queue);
        MapTilePatchFrameHeader const * frames =
            reinterpret_cast<MapTilePatchFrameHeader const *>(animation.patch.frame_data);
        if (AdvanceMapAnimationFrame(state, frames->frame_count))
            state.frame = 0;
    }
}

EC void DrawSavedWorldMap(GameSceneSavedMapPrefix * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, void * unk)
{
    func_080A4F50(map, queue, display, unk);
    GameStateSaveImage * save = map->save;
    switch (map->map) {
    case MAP_FARMHOUSE:
        if (map->unk_98) {
            map->unk_98 = false;
            if (map->save->farm.farm_house.HasStocking()) {
                if (map->save->farm.farm_house.GetStockingArticleId() == ITEM_ARTICLE_NONE)
                    QueueMapTilePatch(map, gMapTilePatch6, 1, queue);
                else
                    QueueMapTilePatch(map, gMapTilePatch6, 2, queue);
            } else {
                QueueMapTilePatch(map, gMapTilePatch6, 0, queue);
            }
        }
        break;
    case MAP_ROSE_SQUARE:
        if (save->event_state.harvest_festival_active == FESTIVAL_PHASE_INITIAL) {
            QueueMapAnimationFrame(map->tile_animations[0], map, gMapTilePatchAnimation0, queue);
            QueueMapAnimationFrame(map->tile_animations[1], map, gMapTilePatchAnimation1, queue);
        }
        break;
    }
}

EC void ResetSavedMapTileAnimationFrames(GameSceneSavedMapPrefix * map)
{
#if defined(REGION_JP)
    func_080A5198(map);
#else
    func_080A5760(map);
#endif
    map->tile_animations[0].ResetFrame();
    map->tile_animations[1].ResetFrame();
}

EC void RefreshFieldPlotTiles(GameSceneWorldMapPrefix * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data)
{
    u32 width = GetMapData(map->map_data_id)->width;
    u16 const * ground = static_cast<u16 const *>(plot->method_0800AF20());
    if (ground != nullptr) {
        memcpy(map->tile_layers[0] + x + y * width, ground, 4);
        memcpy(map->tile_layers[0] + x + (y + 1) * width, ground + 2, 4);
        map->view_changed = true;
    }
    if (render_data != nullptr) {
        memcpy(map->tile_layers[2] + x + (y - 1) * width, render_data->tiles[0], 4);
        memcpy(map->tile_layers[1] + x + y * width, render_data->tiles[1], 4);
        memcpy(map->tile_layers[1] + x + (y + 1) * width, render_data->tiles[2], 4);
        map->view_changed = true;
    }
    map->tile_attributes[x + y * width].unk_00_00 =
        map->tile_attributes[x + 1 + y * width].unk_00_00 =
        map->tile_attributes[x + (y + 1) * width].unk_00_00 =
        map->tile_attributes[x + 1 + (y + 1) * width].unk_00_00 = plot->method_0800A07C();
    map->tile_attributes[x + y * width].unk_02_01 =
        map->tile_attributes[x + 1 + y * width].unk_02_01 =
        map->tile_attributes[x + (y + 1) * width].unk_02_01 =
        map->tile_attributes[x + 1 + (y + 1) * width].unk_02_01 = plot->method_0800A0A4();
}

EC void func_080AA850(GameSceneSavedMapPrefix * map, u32 index)
{
    Season season = static_cast<Season>(func_0800E324(map->save->clock.calendar));
    FieldRenderPatchPlacement placement = SelectMapFlagPatch(
        map->save->unk_34D8.value, index, season == SEASON_WINTER);
    ApplyMapTilePatch(map, *placement.patch, placement.x, placement.y);
    map->view_changed = true;
}

EC void func_080AA89C(GameSceneWorldMapPrefix * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[48], 0x21, 0x14);
    map->view_changed = true;
}

EC void func_080AA8BC(GameSceneWorldMapPrefix * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[48], 0x21, 0x17);
    map->view_changed = true;
}

EC void func_080AA8DC(GameSceneSavedMapPrefix * map)
{
    if (map->map == MAP_FARMHOUSE)
        map->unk_98 = true;
}

GameSceneControllerActorRecord::GameSceneControllerActorRecord()
    : location(Location(MAP_NONE, 0, 0), 0), animation(0), event_script(0)
{
}

GameSceneControllerLocationRecord::GameSceneControllerLocationRecord()
    : unk_00_00(0), location(MAP_NONE, 0, 0)
{
}

EC void func_080D7F08(GameSceneState * state)
{
    for (u32 id = ENTITY_LILLIA; id <= ENTITY_CHILD; ++id) {
        GameObject * & game_object = state->game_object.value;
        ANpcEntity * entity = static_cast<ANpcEntity *>(game_object->GetActorEntity(id));
        if (entity != nullptr)
            entity->vfunc_3C(3);
    }
}

EC void func_080D7F3C(GameSceneState * state)
{
    state->game_object.value->vfunc_124();
    state->script_state = 2;
}

EC void func_080D7F60(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        window->HideHeartIndicator();
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

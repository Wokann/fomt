#include "prelude.h"
#include "new_game.hh"
#include <new>
#include <string.h>
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
#include "possessive_labels.hh"
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

GameSceneControllerActorRecord * GetSceneActorRecords(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return controller->actor_records;
}

GameSceneEventIconRecord * GetSceneEventIconRecords(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return controller->event_icon_records;
}

GameSceneScriptQueue<2> * GetSceneScriptQueue0(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return &controller->queues.queue_0;
}

GameScenePreservedPlayerLocation * GetScenePreservedPlayerLocation(void)
{
    GameSceneScriptController * controller =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    return &controller->preserved_player_location;
}

u8 * func_08010138(void)
{
    return gUnk_0300040C + 0x368;
}

u32 func_08010148(void)
{
    return 25;
}

ScriptEngine * GetSceneScriptEngine(void)
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

void GameScene::SetEntitySpritePriority(u32 id, u32 priority)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        entity->unk_21 = priority;
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
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        func_08032384(*entity, effect, persistent != 0);
}

void GameScene::StopEntityEffect(u32 id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        func_080323C8(*entity);
}

void GameScene::SetEntityAuxRenderProfile(u32 id, u32 profile)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
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
            current->game_object.value->RefreshMapTimeOfDayPalette();
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

// All four food/article VM paths pass a real RucksackItem by reference;
// wrapped selects the common action path, not a second inventory object.
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

void GameScene::LightFireplaceAtLocation(MaryMapId map)
{
    static_cast<GameSceneWorldPrefix *>(state->game_object.value)->LightFireplaceAtLocation(map);
}

void GameScene::SetVaseArticleId(MaryItemArticleId article)
{
    static_cast<GameSceneWorldPrefix *>(state->game_object.value)->SetVaseArticleId(article);
}

void GameScene::BeginEggIncubation(MaryChickenCoopIncubatorIndex incubator)
{
    GameSceneState * current = state;
    // Storage checks capacity, but the native refresh still receives the
    // original full-width index even when that storage operation rejects it.
    current->save->farm.coop.BeginIncubation(incubator);
    current->game_object.value->RefreshChickenCoopIncubator(incubator);
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
            npc->vfunc_3C(3);
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
        if (horse != nullptr && !horse->vfunc_28())
            horse->vfunc_20();
    }
}

void GameScene::RemoveFarmHorse(MaryBool skip_removal, i32 unused_value)
{
    GameSceneState * current = state;
    // The VM consumes unused_value, but the native operation never reads it.
    if (skip_removal == FALSE) {
        current->game_object.value->vfunc_3C(ENTITY_FARM_HORSE);
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
            return func_08033B24(static_cast<EntityUiHarvestSpriteState *>(entity));
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

GameSceneCaughtFish const * GameScene::GetCaughtFish()
{
    return static_cast<PlayerActor *>(state->game_object.value->GetEntity(
        ENTITY_PLAYER))->GetCaughtFish();
}

void GameScene::CreatePlayerChildEntity()
{
    GameSceneState * current = state;
    GameStateSaveImage * save = current->save;
    func_080A05E8(save->npcs, save->clock.calendar.date);
    // Refresh may replace the world; resolve the child from the current slot.
    GameObject * & world = current->game_object.value;
    world->vfunc_38(ENTITY_CHILD);
    AActorEntity * child = static_cast<AActorEntity *>(world->GetEntity(ENTITY_CHILD));
    if (child != nullptr && !child->vfunc_28())
        child->vfunc_20();
}

void GameScene::SetContestAnimal(MaryAnimalKind animal_kind, MaryAnimalSlotIndex animal_index)
{
    GameSceneState * current = state;
    switch (animal_kind) {
    case ANIMAL_KIND_HORSE:
        current->game_object.value->vfunc_3C(ENTITY_FARM_HORSE);
        break;
    case ANIMAL_KIND_DOG:
        current->game_object.value->vfunc_3C(ENTITY_FARM_DOG);
        break;
    case ANIMAL_KIND_COW:
    case ANIMAL_KIND_SHEEP:
        current->save->farm.barn.method_0800D80C(animal_index);
        current->game_object.value->vfunc_3C(ENTITY_BARN_ANIMAL_SLOT_1 + static_cast<u32>(animal_index));
        break;
    case ANIMAL_KIND_CHICKEN:
        current->save->farm.coop.method_0800CB7C(animal_index);
        current->game_object.value->vfunc_3C(ENTITY_ANIMAL_CHICKEN_SLOT_1 + static_cast<u32>(animal_index));
        break;
    }
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

// Entity 0x5D is the existing event-effect host, not the effect itself.
// These commands forward to its owned controller without creating a host.
void GameScene::CreateNewYearSunriseEffect()
{
    func_080387B8(state->game_object.value->GetEntity(0x5D));
}

void GameScene::PlayNewYearSunriseEffect()
{
    GameSceneState * current = state;
    func_080387C8(current->game_object.value->GetEntity(0x5D));
    // The callback may change scene.state; the native write uses this state.
    current->script_state = 0x1C;
}

void GameScene::DestroyNewYearSunriseEffect()
{
    func_080387EC(state->game_object.value->GetEntity(0x5D));
}

void GameScene::PlayStarSparkleEffect()
{
    GameSceneState * current = state;
    func_080387FC(current->game_object.value->GetEntity(0x5D));
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
    if (actor != nullptr && !actor->vfunc_28())
        actor->vfunc_20();
}

void GameScene::RemoveEntity(MaryEntityId entity_id)
{
    state->game_object.value->vfunc_3C(entity_id);
}

void GameScene::PreservePlayerLocationForNextDay()
{
    GameSceneState * current = state;
    AActorEntity * player = static_cast<AActorEntity *>(current->game_object.value->GetEntity(ENTITY_PLAYER));
    // Lookup can replace the global controller; resolve it after the call.
    GameScenePreservedPlayerLocation & saved =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C)->preserved_player_location;
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
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C)->preserved_player_location;
    saved.active = 0;
    saved.map = MAP_NONE;
}

MaryMapId GameScene::GetPreservedPlayerMapId()
{
    // This native query returns the stored map even when active is zero.
    return reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C)
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
    static_cast<GameSceneWorldPrefix *>(state->game_object.value)
        ->CreateEventIcon(slot, x, y, layer, id);
}

void GameScene::RemoveEventIcon(MaryEventIconSlot slot)
{
    static_cast<GameSceneWorldPrefix *>(state->game_object.value)->RemoveEventIcon(slot);
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
        LivestockActor * actor = static_cast<LivestockActor *>(
            world->GetEntity(id));
        if (actor != nullptr && actor->IsSick())
            actor->CureSickness();
    }
}

GameSceneControllerActorRecord::GameSceneControllerActorRecord()
    : location(Location(MAP_NONE, 0, 0), 0), animation(0), event_script(0)
{
}

GameSceneEventIconRecord::GameSceneEventIconRecord()
    : state(0), location(MAP_NONE, 0, 0)
{
}

EC void func_080D7F08(GameSceneState * state)
{
    for (u32 id = ENTITY_LILLIA; id <= ENTITY_CHILD; ++id) {
        GameObject * & game_object = state->game_object.value;
        ANpcEntity * entity = static_cast<ANpcEntity *>(game_object->GetEntity(id));
        if (entity != nullptr)
            entity->vfunc_3C(3);
    }
}

EC void func_080D7F3C(GameSceneState * state)
{
    state->game_object.value->SuspendUpdates();
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

// Modal run methods follow their native ROM order. Returning the member
// transfers its pointer and clears the source; it does not run the next scene.
SceneTransitionOwner ReferencePageScene::Run()
{
    func_080790E4(core);
    return continuation;
}

SceneTransitionOwner PoultryFarmShopScene::Run()
{
#if defined(REGION_JP)
    i32 result = func_0807BA6C(core);
#else
    i32 result = func_0807BEC8(core);
#endif
    if (result != -1) {
        SceneTransitionOwner next(new PoultryFarmShopTransition(continuation, save, 1));
        return SceneTransitionOwner(new SavedNameEntryTransition(next, save, NAME_ENTRY_CHICKEN, result));
    }
    return continuation;
}

SceneTransitionOwner SupermarketScene::Run()
{
#if defined(REGION_JP)
    func_0807CD80(core);
#else
    func_0807D218(core);
#endif
    return continuation;
}

SceneTransitionOwner SupermarketPurchaseScene::Run()
{
    func_0807DE3C(core);
    return continuation;
}

SceneTransitionOwner ClinicShopScene::Run()
{
#if defined(REGION_JP)
    func_0807E0C0(core);
#else
    func_0807E558(core);
#endif
    return continuation;
}

SceneTransitionOwner InnShopScene::Run()
{
#if defined(REGION_JP)
    func_0807EAF8(core);
#else
    func_0807EF90(core);
#endif
    return continuation;
}

SceneTransitionOwner WonShopScene::Run()
{
#if defined(REGION_JP)
    func_0807F430(core);
#else
    func_0807F8C8(core);
#endif
    return continuation;
}

SceneTransitionOwner WineryShopScene::Run()
{
#if defined(REGION_JP)
    func_080800A8(core);
#else
    func_08080540(core);
#endif
    return continuation;
}

SceneTransitionOwner SpecialMerchantShopScene::Run()
{
#if defined(REGION_JP)
    func_08080CC4(core);
#else
    func_0808114C(core);
#endif
    return continuation;
}

SceneTransitionOwner BeachCafeShopScene::Run()
{
#if defined(REGION_JP)
    func_08081734(core);
#else
    func_08081BBC(core);
#endif
    return continuation;
}

SceneTransitionOwner BlacksmithShopScene::Run()
{
    u32 result = func_08082CEC(core);
    if (result == 0)
        return continuation;
    if (result == 1)
        return SceneTransitionOwner(new BlacksmithShopResultTransition(continuation, save, 0));
    return SceneTransitionOwner(new BlacksmithShopResultTransition(continuation, save, 1));
}

SceneTransitionOwner CarpenterShopScene::Run()
{
    func_08084228(core);
    return continuation;
}

SceneTransitionOwner YodelRanchShopScene::Run()
{
    i32 result = func_08086A08(core);
    if (result != -1) {
        u32 selection = func_08085EEC(core);
        MaryNameEntryKind kind = selection != 0 ? NAME_ENTRY_SHEEP : NAME_ENTRY_COW;
        SceneTransitionOwner next(new YodelRanchShopTransition(continuation, save,
            selection != 0 ? 2 : 1));
        return SceneTransitionOwner(new SavedNameEntryTransition(next, save, kind, result));
    }
    return continuation;
}

SceneTransitionOwner ToolChestScene::Run()
{
#if defined(REGION_JP)
    func_0808A09C(core);
#else
    func_0808A55C(core);
#endif
    return continuation;
}

SceneTransitionOwner RefrigeratorScene::Run()
{
#if defined(REGION_JP)
    func_0808E23C(core);
#else
    func_0808E6FC(core);
#endif
    return continuation;
}

SceneTransitionOwner ShelfScene::Run()
{
    func_08090960(core);
    return continuation;
}

BlacksmithShopResultScene::BlacksmithShopResultScene(SceneTransitionOwner next,
    GameStateSaveImage * image, u8 input)
    : core(func_08090EE0(::operator new(sizeof(BlacksmithShopResultSceneCore)), next, image, input)),
      continuation(next)
{
}

BlacksmithShopResultScene::~BlacksmithShopResultScene()
{
}

SceneTransitionOwner BlacksmithShopResultScene::Run()
{
#if defined(REGION_JP)
    return func_0809106C(static_cast<BlacksmithShopResultSceneCore *>(core.value));
#else
    return func_0809152C(static_cast<BlacksmithShopResultSceneCore *>(core.value));
#endif
}

SceneTransitionOwner GiftWrappingScene::Run()
{
    func_08092D64(core);
    return continuation;
}

SceneTransitionOwner CookingScene::Run()
{
#if defined(REGION_JP)
    func_08094A40(core);
#else
    func_08094F6C(core);
#endif
    return continuation;
}

SceneTransitionOwner CalendarScene::Run()
{
    func_080A25B0(core);
    return continuation;
}

SceneTransitionOwner SavedNameEntryScene::Run()
{
    char const * prompt = nullptr;
    switch (kind) {
    case NAME_ENTRY_HORSE: prompt = gText_Possessive_Horse; break;
    case NAME_ENTRY_COW: prompt = gText_Possessive_Cow; break;
    case NAME_ENTRY_SHEEP: prompt = gText_Possessive_Sheep; break;
    case NAME_ENTRY_CHICKEN: prompt = gText_Possessive_Chicken; break;
    case NAME_ENTRY_CHILD: prompt = gText_Possessive_Child; break;
    case NAME_ENTRY_SPOUSE_NICKNAME: prompt = gText_Possessive_Player; break;
    default: return continuation;
    }
    NewGameNameInputScene keyboard(prompt, nullptr);
    keyboard.Run();
    Animal * animal;
    switch (kind) {
    case NAME_ENTRY_HORSE:
        animal = save->farm.GetHorse();
        goto set_animal_name;
    case NAME_ENTRY_COW:
        animal = save->farm.barn.GetCow(target_index);
        goto set_animal_name;
    case NAME_ENTRY_SHEEP:
        animal = save->farm.barn.GetSheep(target_index);
        goto set_animal_name;
    case NAME_ENTRY_CHICKEN:
        animal = save->farm.coop.GetChicken(target_index);
    set_animal_name:
        if (animal != nullptr)
            animal->SetName(keyboard.GetName());
        break;
    case NAME_ENTRY_CHILD: {
        Child * child = save->npcs.GetChild();
        if (child != nullptr)
            child->SetName(keyboard.GetName());
        break;
    }
    case NAME_ENTRY_SPOUSE_NICKNAME:
        func_0800E9A8(save->farmer, keyboard.GetName());
        break;
    default:
        return continuation;
    }
    return continuation;
}

SceneOwner SavedNameEntryTransition::CreateScene()
{
    return SceneOwner(new SavedNameEntryScene(continuation, save, kind, target_index));
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

SceneOwner BlacksmithShopResultTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new BlacksmithShopResultScene(SceneTransitionOwner(next), save, unk_0C));
}

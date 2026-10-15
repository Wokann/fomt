#include "game_scene.hh"
#include "game_state.hh"
#include "entity_actor.hh"
#include "entity_ui.hh"
#include "fomt_constants.hh"
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "font.hh"

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

u8 * func_08010118(void)
{
    return gUnk_0300040C + 0x378;
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

u8 * func_0801014C(void)
{
    return gUnk_0300040C + 8;
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
    current->flags_10 &= ~0x0100;
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

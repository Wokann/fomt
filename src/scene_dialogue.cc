#include "scene_dialogue.hh"
#include "game_scene.hh"
#include "font.hh"
#include "gbaio.h"

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
#else
    FormatSignedDecimal(value, text, width);
#endif
    current->text_variables.value->Set(slot, text);
}

EC void HideSceneDialogueHeartIndicator(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        window->HideHeartIndicator();
}

EC void ClearSceneDialoguePortrait(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E5C(reinterpret_cast<void * const *>(window));
}

EC void ClearSceneDialogueNameplate(GameSceneState * state)
{
    UiStateOwner * window = state->talk_window.Get();
    if (window != nullptr)
        func_08050E74(reinterpret_cast<void * const *>(window));
}

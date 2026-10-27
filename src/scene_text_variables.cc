#include "prelude.h"
#include "game_state.hh"
#include "common_ui.hh"
#pragma implementation "scene_text_variables.hh"
#include "scene_text_variables.hh"

GameSceneTextVariables::GameSceneTextVariables(GameStateSaveImage * image)
    : save(image) {}

void GameSceneTextVariables::Set(u32 slot, char const * text)
{
    FixedStr<MAX_VALUE_BYTES> value(text);
    values[slot] = value;
}

GameSceneTextVariables::~GameSceneTextVariables() {}

static inline UiTextSubstitution MakeSceneTextSubstitution(char const * source)
{
    return UiTextSubstitution(true, FixedStr<31>(source));
}

UiTextSubstitution GameSceneTextVariables::Lookup(u32 code)
{
    switch (code) {
    case PLAYER:
        if (save->farm.method_08009B20() &&
            save->event_state.golden_lumber_was_on_farm_at_day_start)
            return MakeSceneTextSubstitution(gText_Moneybags);
        return MakeSceneTextSubstitution(save->farmer.GetName());
    case HORSE: {
        Horse const * horse = save->farm.GetHorse();
        return UiTextSubstitution(true,
            FixedStr<31>(horse != nullptr ? horse->GetName() : gText_EmptyUiLabel));
    }
    case DOG:
        return MakeSceneTextSubstitution(save->dog.GetName());
    case NICKNAME:
        return MakeSceneTextSubstitution(save->farmer.GetSpouseNickname());
    case BABY:
        if (save->npcs.GetChild() != nullptr)
            return MakeSceneTextSubstitution(save->npcs.GetChild()->GetName());
        return MakeSceneTextSubstitution(gText_UnnamedSetting);
    case PLACE1:
        return MakeSceneTextSubstitution(save->farm.GetName());
    case VAR1:
    case VAR2:
    case VAR3:
    case VAR4:
        return UiTextSubstitution(true, FixedStr<31>(values[code - VAR1]));
    case PLACE2:
        return MakeSceneTextSubstitution(save->link_record.name_14);
    case PASSERBY1:
        return MakeSceneTextSubstitution(save->link_record.name_24);
    case PASSERBY2:
        return MakeSceneTextSubstitution(save->link_record.name_34);
    }
    return UiTextSubstitution(false, FixedStr<31>());
}

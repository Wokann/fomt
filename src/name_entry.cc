#include "prelude.h"
#include "new_game_name_input.hh"
#pragma implementation "name_entry.hh"
#include "game_scene.hh"
#include "name_entry.hh"

#include FOMT_TEXT_INCLUDE(name_entry.cc)

void GameScene::OpenNameEntry(MaryNameEntryKind kind, MaryNameEntryTargetIndex target_index)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_NAME_ENTRY);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SavedNameEntryTransition(next, current->save, kind, target_index);
    current->script_state = 0x18;
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
        save->farmer.SetSpouseNickname(keyboard.GetName());
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

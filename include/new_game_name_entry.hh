#ifndef NEW_GAME_NAME_ENTRY_HH
#define NEW_GAME_NAME_ENTRY_HH

#include "prelude.h"
#include "scene.hh"
#include "game_state.hh"
#include "utility/fixed_str.hh"

#pragma interface "new_game_name_entry.hh"
// The complete form workflow is this scene's native virtual Run method.
struct NewGameNameEntryScene : AScene {
    NewGameNameEntryScene();
    virtual ~NewGameNameEntryScene();
    virtual SceneTransitionOwner Run();
};

typedef char NewGameNameEntrySceneSizeCheck[sizeof(NewGameNameEntryScene) == 4 ? 1 : -1];

// The workflow creates this transition after all four fields are confirmed.
// Each name is limited to twelve encoded bytes, with word-aligned members.
struct NewGameFreshSaveTransition : SceneTransition {
    NewGameFreshSaveTransition(char const * farm, char const * player,
        GameDate date, char const * dog)
        : farm_name(farm), player_name(player), birthday(date), dog_name(dog) {}
    virtual SceneOwner CreateScene();

    FixedStr<12> farm_name ALIGN(4);
    FixedStr<12> player_name ALIGN(4);
    GameDate birthday ALIGN(4);
    FixedStr<12> dog_name ALIGN(4);
};

typedef char NewGameFreshSaveTransitionSizeCheck[sizeof(NewGameFreshSaveTransition) == 0x38 ? 1 : -1];
typedef char NewGameFreshSaveFarmCheck[offsetof(NewGameFreshSaveTransition, farm_name) == 4 ? 1 : -1];
typedef char NewGameFreshSavePlayerCheck[offsetof(NewGameFreshSaveTransition, player_name) == 0x14 ? 1 : -1];
typedef char NewGameFreshSaveBirthdayCheck[offsetof(NewGameFreshSaveTransition, birthday) == 0x24 ? 1 : -1];
typedef char NewGameFreshSaveDogCheck[offsetof(NewGameFreshSaveTransition, dog_name) == 0x28 ? 1 : -1];

#pragma implementation

#endif // NEW_GAME_NAME_ENTRY_HH

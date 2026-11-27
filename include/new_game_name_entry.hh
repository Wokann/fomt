#ifndef NEW_GAME_NAME_ENTRY_HH
#define NEW_GAME_NAME_ENTRY_HH

#include "prelude.h"
#include "scene.hh"
#include "unknown_types.hh"
#include "utility/fixed_str.hh"

#pragma interface "new_game_name_entry.hh"
// The complete form workflow is this scene's native virtual Run method.
struct NewGameNameEntryScene : AScene {
    NewGameNameEntryScene();
    virtual ~NewGameNameEntryScene();
    virtual SceneTransitionOwner Run();
};


// The workflow creates this transition after all four fields are confirmed.
// Each name is limited to twelve encoded bytes, with word-aligned members.
struct NewGameFreshSaveTransition : SceneTransition {
    NewGameFreshSaveTransition(char const * farm, char const * player,
        GameDate date, char const * dog);
    virtual SceneOwner CreateScene();

    FixedStr<12> farm_name ALIGN(4);
    FixedStr<12> player_name ALIGN(4);
    GameDate birthday ALIGN(4);
    FixedStr<12> dog_name ALIGN(4);
};



extern char const gText_NewGameIdentity_PlayerPrefix[];
extern char const gText_NewGameIdentity_FarmPrefix[];
extern char const gText_NewGameIdentity_DogPrefix[];

#endif // NEW_GAME_NAME_ENTRY_HH

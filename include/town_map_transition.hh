#ifndef TOWN_MAP_TRANSITION_HH
#define TOWN_MAP_TRANSITION_HH

#include "town_map_selection.hh"

struct GameStateSaveImage;

#pragma interface "town_map_transition.hh"


struct TownMapReturnTransition : TownMapSelectionTransition {
    TownMapReturnTransition(GameStateSaveImage * image, i32 input_mode);
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    i32 mode;
};

struct TownMapTransition : SceneTransition {
    TownMapTransition(i32 input_mode, GameStateSaveImage * image);
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner result;
    i32 mode;
};


#pragma interface "game_scene.hh"

inline TownMapSelectionTransition::TownMapSelectionTransition()
    : has_selection(false), location(MAP_NONE, 0, 0) {}

inline TownMapReturnTransition::TownMapReturnTransition(GameStateSaveImage * image, i32 input_mode)
    : save(image), mode(input_mode) {}

inline TownMapTransition::TownMapTransition(i32 input_mode, GameStateSaveImage * image)
    : save(image), result(new TownMapReturnTransition(image, input_mode)), mode(input_mode) {}


#endif // TOWN_MAP_TRANSITION_HH

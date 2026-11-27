#ifndef SCENE_CLOCK_TRANSITION_HH
#define SCENE_CLOCK_TRANSITION_HH

#include "scene.hh"

struct GameStateSaveImage;

#pragma interface "scene_clock_transition.hh"

struct ClockTransition : SceneTransition {
    ClockTransition(GameStateSaveImage * image, SceneTransitionOwner next);
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
};


#pragma interface "game_scene.hh"

inline ClockTransition::ClockTransition(GameStateSaveImage * image, SceneTransitionOwner next)
    : save(image), continuation(next) {}


#endif // SCENE_CLOCK_TRANSITION_HH

#include "scene_clock_transition.hh"
#include "new_game_menu.hh"

SceneOwner ClockTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new NewGameMenuScene(save, next));
}

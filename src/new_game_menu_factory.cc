#include "new_game_menu.hh"
#include "game_scene.hh"
#include "game_scene_controller.hh"
#include "game_scene_controller_lifetimes.hh"
#include "intro_scene.hh"

void * operator new(unsigned long);
void operator delete(void *);

SceneOwner NewGameLoadedSaveTransition::CreateScene()
{
    return SceneOwner(new GameSceneScriptController(state));
}

SceneOwner MenuIntroTransition::CreateScene()
{
    return SceneOwner(new GameIntroScene);
}

#include "new_game_name_entry.hh"
#include "game_scene.hh"
#include "game_scene_controller.hh"
#include "game_scene_controller_lifetimes.hh"

void * operator new(unsigned long);
void operator delete(void *);

SceneOwner NewGameFreshSaveTransition::CreateScene()
{
    return SceneOwner(new GameSceneScriptController(farm_name,
        player_name, birthday, dog_name));
}

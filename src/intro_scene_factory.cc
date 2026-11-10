#include "intro_scene.hh"
#include "new_game_name_entry.hh"
#include "new_game_menu.hh"

#if !defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(intro_scene_factory.cc)
#endif

void * operator new(unsigned long);
void operator delete(void *);

SceneOwner IntroNameEntryTransition::CreateScene()
{
    return SceneOwner(new NewGameNameEntryScene);
}

SceneOwner IntroMenuTransition::CreateScene()
{
    return SceneOwner(new NewGameMenuScene);
}

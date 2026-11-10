#pragma implementation "scene_menu_transitions.hh"
#include "gamecube_link_scene.hh"

#pragma interface "gamecube_link_scene.hh"
inline GameCubeLinkScene::GameCubeLinkScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

#include "scene_menu_transitions.hh"

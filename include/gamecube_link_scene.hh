#ifndef GAMECUBE_LINK_SCENE_HH
#define GAMECUBE_LINK_SCENE_HH

#include "scene.hh"

struct GameStateSaveImage;

#pragma interface "gamecube_link_scene.hh"

struct GameCubeLinkScene : AScene {
    GameCubeLinkScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneTransitionOwner Run();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GameCubeLinkSceneSizeCheck[sizeof(GameCubeLinkScene) == 12 ? 1 : -1];
typedef char GameCubeLinkSceneSaveCheck[offsetof(GameCubeLinkScene, save) == 8 ? 1 : -1];


#endif // GAMECUBE_LINK_SCENE_HH

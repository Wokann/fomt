#ifndef SCENE_GAMECUBE_LINK_HH
#define SCENE_GAMECUBE_LINK_HH

#include "game_scene.hh"
#pragma interface "scene_gamecube_link.hh"

// Only this leading portion is recovered. Native core storage extends to 0x3F0.
// The unknown bytes are not a reconstruction of its remaining UI members.
struct GameCubeLinkUiCore {
    u32 unk_00;
    void const * unk_04;
    u8 unk_08[0x1BC];
    MaryGameCubeLinkResult result;
};

struct GameCubeLinkUiScene : AScene {
    GameCubeLinkUiScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~GameCubeLinkUiScene();
    MaryGameCubeLinkResult GetResult();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct GameCubeLinkScene : AScene {
    GameCubeLinkScene(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneTransitionOwner Run();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct GameCubeLinkTransition : SceneTransition {
    GameCubeLinkTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GameCubeLinkUiCoreResultCheck[offsetof(GameCubeLinkUiCore, result) == 0x1C4 ? 1 : -1];
typedef char GameCubeLinkUiSceneSizeCheck[sizeof(GameCubeLinkUiScene) == 12 ? 1 : -1];
typedef char GameCubeLinkUiSceneCoreCheck[offsetof(GameCubeLinkUiScene, core) == 4 ? 1 : -1];
typedef char GameCubeLinkUiSceneContinuationCheck[offsetof(GameCubeLinkUiScene, continuation) == 8 ? 1 : -1];
typedef char GameCubeLinkSceneSizeCheck[sizeof(GameCubeLinkScene) == 12 ? 1 : -1];
typedef char GameCubeLinkSceneSaveCheck[offsetof(GameCubeLinkScene, save) == 8 ? 1 : -1];
typedef char GameCubeLinkTransitionSizeCheck[sizeof(GameCubeLinkTransition) == 12 ? 1 : -1];

EXTERN_C

GameCubeLinkUiCore * ConstructGameCubeLinkUiCore(void * object, GameStateSaveImage * image);
void RunGameCubeLinkUiCore(GameCubeLinkUiCore * core);

EXTERN_C_END

#endif // SCENE_GAMECUBE_LINK_HH

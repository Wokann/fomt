#ifndef SCENE_TOOL_CHEST_HH
#define SCENE_TOOL_CHEST_HH

#include "game_scene.hh"
#pragma interface "scene_tool_chest.hh"

struct ToolChestSceneCore;
struct ToolChestScene : AScene {
    ToolChestScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ToolChestScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct ToolChestTransition : SceneTransition {
    ToolChestTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ToolChestSceneSizeCheck[sizeof(ToolChestScene) == 12 ? 1 : -1];
typedef char ToolChestSceneCoreCheck[offsetof(ToolChestScene, core) == 4 ? 1 : -1];
typedef char ToolChestSceneContinuationCheck[offsetof(ToolChestScene, continuation) == 8 ? 1 : -1];
typedef char ToolChestTransitionSizeCheck[sizeof(ToolChestTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core keeps its verified UI base prefix and opaque remaining layout.
ToolChestSceneCore * ConstructToolChestSceneCore(void * object, GameStateSaveImage * image);
void RunToolChestSceneCore(ToolChestSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ToolChestScene * __14ToolChestSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_TOOL_CHEST_HH

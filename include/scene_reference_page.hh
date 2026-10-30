#ifndef SCENE_REFERENCE_PAGE_HH
#define SCENE_REFERENCE_PAGE_HH

#include "game_scene.hh"
#pragma interface "scene_reference_page.hh"

struct ReferencePageSceneCore;
struct ReferencePageScene : AScene {
    enum SpecialPage {
        BOOK_LIST = 0x1000,
        LETTER_LIST = 0x1001,
    };

    ReferencePageScene(SceneTransitionOwner next, GameStateSaveImage * image, i32 page);
    virtual ~ReferencePageScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct ReferencePageTransition : SceneTransition {
    ReferencePageTransition(SceneTransitionOwner next, GameStateSaveImage * image, i32 page)
        : continuation(next), save(image), page_id(page) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    i32 page_id;
};

typedef char ReferencePageSceneSizeCheck[sizeof(ReferencePageScene) == 12 ? 1 : -1];
typedef char ReferencePageSceneCoreCheck[offsetof(ReferencePageScene, core) == 4 ? 1 : -1];
typedef char ReferencePageSceneContinuationCheck[offsetof(ReferencePageScene, continuation) == 8 ? 1 : -1];
typedef char ReferencePageTransitionSizeCheck[sizeof(ReferencePageTransition) == 16 ? 1 : -1];

EXTERN_C

// The native core retains its verified UI base prefix and opaque remaining layout.
ReferencePageSceneCore * ConstructReferencePageSceneCore(
    void * object, GameStateSaveImage * image, i32 page);
// Native Run returns an owned transition; the wrapper destroys that temporary.
SceneTransitionOwner RunReferencePageSceneCore(ReferencePageSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ReferencePageScene * __18ReferencePageSceneG20SceneTransitionOwnerP18GameStateSaveImagei(
    void * object, SceneTransition ** next, GameStateSaveImage * image, i32 page);

EXTERN_C_END

#endif // SCENE_REFERENCE_PAGE_HH

#ifndef SCENE_FRISBEE_HH
#define SCENE_FRISBEE_HH

#include "scene.hh"
struct GameStateSaveImage;
#pragma interface "scene_frisbee.hh"

// The scene shell and native constructor establish these pointer/owner fields.
// Constructor, destructor, Run and the core body remain native assembly.
struct FrisbeeCore;
struct FrisbeeScene : AScene {
    FrisbeeScene(SceneTransitionOwner next, GameStateSaveImage * image, bool contest);
    virtual ~FrisbeeScene();
    virtual SceneTransitionOwner Run();
    FrisbeeCore * core;
    SceneTransitionOwner continuation;
};

struct FrisbeeTransition : SceneTransition {
    FrisbeeTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool contest)
        : continuation(next), save(image), contest_mode(contest) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool contest_mode;
};

typedef char FrisbeeSceneSizeCheck[sizeof(FrisbeeScene) == 12 ? 1 : -1];
typedef char FrisbeeSceneCoreCheck[offsetof(FrisbeeScene, core) == 4 ? 1 : -1];
typedef char FrisbeeSceneContinuationCheck[offsetof(FrisbeeScene, continuation) == 8 ? 1 : -1];
typedef char FrisbeeTransitionSizeCheck[sizeof(FrisbeeTransition) == 16 ? 1 : -1];
typedef char FrisbeeTransitionContinuationCheck[offsetof(FrisbeeTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeTransitionSaveCheck[offsetof(FrisbeeTransition, save) == 8 ? 1 : -1];
typedef char FrisbeeTransitionModeCheck[offsetof(FrisbeeTransition, contest_mode) == 12 ? 1 : -1];

// The scene shell and native constructor establish these pointer/owner fields.
// Constructor, destructor, Run and the core body remain native assembly.
struct FrisbeeTournamentCore;
struct FrisbeeTournamentScene : AScene {
    FrisbeeTournamentScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~FrisbeeTournamentScene();
    virtual SceneTransitionOwner Run();
    FrisbeeTournamentCore * core;
    SceneTransitionOwner continuation;
};

struct FrisbeeTournamentTransition : SceneTransition {
    FrisbeeTournamentTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char FrisbeeTournamentSceneSizeCheck[sizeof(FrisbeeTournamentScene) == 12 ? 1 : -1];
typedef char FrisbeeTournamentSceneCoreCheck[offsetof(FrisbeeTournamentScene, core) == 4 ? 1 : -1];
typedef char FrisbeeTournamentSceneContinuationCheck[offsetof(FrisbeeTournamentScene, continuation) == 8 ? 1 : -1];
typedef char FrisbeeTournamentTransitionSizeCheck[sizeof(FrisbeeTournamentTransition) == 12 ? 1 : -1];
typedef char FrisbeeTournamentTransitionContinuationCheck[offsetof(FrisbeeTournamentTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeTournamentTransitionSaveCheck[offsetof(FrisbeeTournamentTransition, save) == 8 ? 1 : -1];

// Direct ABI declaration of this still-native constructor, not a wrapper.
// The second argument is the actual single-word continuation transfer slot.
extern "C" FrisbeeTournamentScene * __22FrisbeeTournamentSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif

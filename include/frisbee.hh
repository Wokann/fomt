#ifndef FRISBEE_HH
#define FRISBEE_HH

#include "scene.hh"

struct GameStateSaveImage;

struct FrisbeeCore;

// The scene destroys its continuation first, then this owned core.
struct FrisbeeCoreOwner {
    explicit FrisbeeCoreOwner(FrisbeeCore * core) : value(core) {}
    ~FrisbeeCoreOwner();
    FrisbeeCore * operator->() const { return value; }
    FrisbeeCore * value;
private:
    FrisbeeCoreOwner(FrisbeeCoreOwner const &);
    FrisbeeCoreOwner & operator=(FrisbeeCoreOwner const &);
};

#pragma interface "frisbee.hh"
struct FrisbeeScene : AScene {
    FrisbeeScene(SceneTransitionOwner next, GameStateSaveImage * image, bool contest);
    virtual ~FrisbeeScene();
    virtual SceneTransitionOwner Run();
    FrisbeeCoreOwner core;
    SceneTransitionOwner continuation;
};

typedef char FrisbeeCoreOwnerSizeCheck[sizeof(FrisbeeCoreOwner) == 4 ? 1 : -1];

#pragma interface "frisbee.hh"

typedef char FrisbeeSceneSizeCheck[sizeof(FrisbeeScene) == 12 ? 1 : -1];
typedef char FrisbeeSceneCoreCheck[offsetof(FrisbeeScene, core) == 4 ? 1 : -1];
typedef char FrisbeeSceneContinuationCheck[offsetof(FrisbeeScene, continuation) == 8 ? 1 : -1];


#endif // FRISBEE_HH

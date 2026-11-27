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


#pragma interface "frisbee.hh"



#endif // FRISBEE_HH

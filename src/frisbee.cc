#include "frisbee.hh"
#include "frisbee_core.hh"
#include <new>

inline FrisbeeCoreOwner::~FrisbeeCoreOwner() { delete value; }

FrisbeeScene::FrisbeeScene(SceneTransitionOwner next, GameStateSaveImage * image, bool contest)
    : core(new FrisbeeCore(image, contest)), continuation(next)
{
}

FrisbeeScene::~FrisbeeScene()
{
}

SceneTransitionOwner FrisbeeScene::Run()
{
    core->Run();
    return continuation;
}

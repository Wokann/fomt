#ifndef SCENE_HH
#define SCENE_HH

#include "prelude.h"

#include "smart_ptr.hh"

struct AScene;
struct SceneTransition;

struct AScene
{
    virtual ~AScene();
    virtual SmartPtr<SceneTransition> Run() = 0;
};

// The second-stage object chooses the next scene through virtual slot +0x0C.
struct SceneTransition
{
    virtual ~SceneTransition();
    virtual SmartPtr<AScene> CreateScene() = 0;
};

void SceneMain(SmartPtr<AScene> scene_ptr);

#endif // SCENE_HH

#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "prelude.h"

typedef void (*IntroSceneVTableFunction)(void);

struct IntroSceneCorePrefix;

typedef void (*IntroSceneCoreDestroyFunction)(IntroSceneCorePrefix *, int);

struct IntroSceneCoreVTable
{
    void * unk_00;
    void * unk_04;
    IntroSceneCoreDestroyFunction destroy;
};

// Only the fields used by the scene destructor are known. The full core
// allocation is larger and remains in asm/intro_scene.s.
struct IntroSceneCorePrefix
{
    void * unk_00;
    IntroSceneCoreVTable const * vtable;
};

struct GameIntroScene
{
    IntroSceneVTableFunction const * vtable;
    IntroSceneCorePrefix * core;
};

EXTERN_C

extern IntroSceneVTableFunction const vtable_unk_080E5A18[];
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);

EXTERN_C_END

#endif // INTRO_SCENE_HH

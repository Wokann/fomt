#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "prelude.h"
#include "scene.hh"

typedef void (*IntroSceneVTableFunction)(void);

struct IntroSceneCore;

typedef void (*IntroSceneCoreDestroyFunction)(IntroSceneCore *, int);

struct IntroSceneCoreVTable
{
    void * unk_00;
    void * unk_04;
    IntroSceneCoreDestroyFunction destroy;
};

// The unknown runs preserve fields still used by the assembly core. Only
// the vtable, selected continuation and run-state fields are decoded here.
struct IntroSceneCore
{
    void * unk_00;
    IntroSceneCoreVTable const * vtable;
    u8 unk_0008[0x6C66];
    i8 continuation;
    u8 unk_6C6F[0xB9];
    u32 run_state;
    u8 unk_6D2C[8];
};

typedef char IntroSceneCoreSizeCheck[(sizeof(IntroSceneCore) == 0x6D34) ? 1 : -1];
typedef char IntroSceneCoreContinuationOffsetCheck[(offsetof(IntroSceneCore, continuation) == 0x6C6E) ? 1 : -1];
typedef char IntroSceneCoreRunStateOffsetCheck[(offsetof(IntroSceneCore, run_state) == 0x6D28) ? 1 : -1];

struct GameIntroScene
{
    IntroSceneVTableFunction const * vtable;
    IntroSceneCore * core;
};

struct IntroNameEntryTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

struct IntroMenuTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

EXTERN_C

extern IntroSceneVTableFunction const vtable_unk_080E5A18[];
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);
SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene);
SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_run");

EXTERN_C_END

#endif // INTRO_SCENE_HH

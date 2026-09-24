#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "prelude.h"

typedef void (*IntroSceneVTableFunction)(void);

// The scene owns an allocation whose internal layout is not yet decompiled.
struct GameIntroScene
{
    IntroSceneVTableFunction const * vtable;
    void * core;
};

EXTERN_C

extern IntroSceneVTableFunction const vtable_unk_080E5A18[];
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);

EXTERN_C_END

#endif // INTRO_SCENE_HH

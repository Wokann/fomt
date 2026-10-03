#include "intro_scene.hh"

EXTERN_C

IntroSceneCorePrefix * func_08000914(void * core);

EXTERN_C_END

void * operator new(unsigned long);

GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene)
{
    enum { CORE_SIZE = 0x6D34 };

    scene->vtable = vtable_unk_080E5A18;
    scene->core = func_08000914(::operator new(CORE_SIZE));
    return scene;
}

void DestroyGameIntroScene(GameIntroScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A18;
    IntroSceneCorePrefix * core = scene->core;
    if (core != nullptr)
        core->vtable->destroy(core, 3);
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}

SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene)
{
    return func_08000D64(scene->core);
}

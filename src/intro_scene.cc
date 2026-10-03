#include "intro_scene.hh"

EXTERN_C

IntroSceneCore * func_08000914(void * core);
void func_08000E1C(IntroSceneCore * core);
int func_08000FF8(IntroSceneCore * core);
AScene * func_08004C48(void * scene);
AScene * func_08004B58(void * scene);

EXTERN_C_END

void * operator new(unsigned long);

GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene)
{
    scene->vtable = vtable_unk_080E5A18;
    scene->core = func_08000914(::operator new(sizeof(IntroSceneCore)));
    return scene;
}

void DestroyGameIntroScene(GameIntroScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A18;
    IntroSceneCore * core = scene->core;
    if (core != nullptr)
        core->vtable->destroy(core, 3);
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}

SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene)
{
    return RunIntroSceneCore(scene->core);
}

SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core)
{
    bool finished = false;
    do
    {
        switch (core->run_state)
        {
        case 0:
            func_08000E1C(core);
            core->run_state = 1;
            break;
        case 1:
            if (func_08000FF8(core) == 1)
                goto choose_continuation;
            core->run_state = 0;
            break;
        }
    } while (!finished);

choose_continuation:
    if (core->continuation == 0)
        return SceneTransitionOwner(new IntroNameEntryTransition);
    else
        return SceneTransitionOwner(new IntroMenuTransition);
}

SceneOwner IntroNameEntryTransition::CreateScene()
{
    // The existing constructor installs the name-entry scene's vtable.
    return SceneOwner(func_08004C48(::operator new(4)));
}

SceneOwner IntroMenuTransition::CreateScene()
{
    // The existing menu scene contains a vtable and an owned menu core.
    return SceneOwner(func_08004B58(::operator new(8)));
}

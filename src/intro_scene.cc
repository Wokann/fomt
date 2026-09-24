#include "intro_scene.hh"

EXTERN_C

void * func_08000914(void * core);
void func_080007EC(GameIntroScene * scene, int flags);

EXTERN_C_END

void * operator new(unsigned long);

GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene)
{
    enum { CORE_SIZE = 0x6D34 };

    scene->vtable = vtable_unk_080E5A18;
    scene->core = func_08000914(::operator new(CORE_SIZE));
    return scene;
}

typedef void (*CoreDestroyFunction)(void *, int);

struct IntroSceneCoreVTable
{
    void * unk_00;
    void * unk_04;
    CoreDestroyFunction destroy;
};

struct IntroSceneCoreBase
{
    void * unk_00;
    IntroSceneCoreVTable const * vtable;
};

void DestroyGameIntroScene(GameIntroScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A18;
    IntroSceneCoreBase * core = static_cast<IntroSceneCoreBase *>(scene->core);
    if (core != nullptr)
        core->vtable->destroy(core, 3);
    func_080007EC(scene, flags);
}

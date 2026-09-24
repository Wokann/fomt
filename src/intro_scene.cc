#include "intro_scene.hh"

EXTERN_C

void * func_08000914(void * core);

EXTERN_C_END

void * operator new(unsigned long);

GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene)
{
    enum { CORE_SIZE = 0x6D34 };

    scene->vtable = vtable_unk_080E5A18;
    scene->core = func_08000914(::operator new(CORE_SIZE));
    return scene;
}

#include "hardware_sound.hh"

#include "interrupt.hh"
#include "m4a.h"

void func_08008AF0(void)
{
    func_08000568(1);
}

void func_08008AFC(void)
{
    m4aSoundInit();
    m4aSoundVSyncOff();
}

u32 func_08008B0C(void)
{
    m4aSoundVSync();
    return 1;
}

u32 func_08008B18(void)
{
    m4aSoundMain();
    return 1;
}

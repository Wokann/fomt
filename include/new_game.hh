#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"

struct HardwareBootstrap;

EXTERN_C

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void func_08003B40(struct HardwareBootstrap * core);
void func_08003BB4(struct HardwareBootstrap * core);

EXTERN_C_END

#endif // NEW_GAME_HH

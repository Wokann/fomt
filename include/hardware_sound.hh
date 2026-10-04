#ifndef HARDWARE_SOUND_HH
#define HARDWARE_SOUND_HH

#include "prelude.h"

struct MusicPlayer;

EXTERN_C

void func_08008AF0(void);
void func_08008AFC(void);
u32 func_08008B0C(void);
u32 func_08008B18(void);
struct MusicPlayer * GetHardwareMusicPlayer(u32 index);

EXTERN_C_END

#endif // HARDWARE_SOUND_HH

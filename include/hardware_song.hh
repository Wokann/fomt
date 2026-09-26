#ifndef HARDWARE_SONG_HH
#define HARDWARE_SONG_HH

#include "prelude.h"

struct MusicPlayer;

EXTERN_C

struct MusicPlayer * func_08008D3C(u16 song_id);
u8 func_08008D5C(u16 song_id);
u8 func_08008D70(u16 song_id);
void func_08008D84(void);
void func_08008D90(void);
u32 func_08008D9C(void);
void func_08008DA8(u16 song_id);
void func_08008DB8(u16 song_id);
void func_08008DC8(u16 song_id);
void func_08008DD8(u16 song_id);
void func_08008DE8(void);
void func_08008DF4(u16 song_id);
void func_08008E04(void);

EXTERN_C_END

#endif // HARDWARE_SONG_HH

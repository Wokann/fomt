#ifndef HARDWARE_MUSIC_PLAYER_HH
#define HARDWARE_MUSIC_PLAYER_HH

#include "prelude.h"

struct MusicPlayer;

EXTERN_C

struct MusicPlayer ** func_08008B54(struct MusicPlayer ** holder, u8 index);
void func_08008B6C(struct MusicPlayer ** holder, u16 song_id);
void func_08008B88(struct MusicPlayer ** holder, u16 song_id);
void func_08008BB0(struct MusicPlayer ** holder, u16 song_id);
void func_08008BE0(struct MusicPlayer ** holder);
void func_08008BEC(struct MusicPlayer ** holder);
void func_08008BF8(struct MusicPlayer ** holder, u16 speed);
void func_08008C08(struct MusicPlayer ** holder, u16 speed);
void func_08008C18(struct MusicPlayer ** holder, u16 speed);
void func_08008C28(struct MusicPlayer ** holder, u16 tempo);
void func_08008C38(struct MusicPlayer ** holder, u16 volume, u16 track_bits);
void func_08008C54(struct MusicPlayer ** holder, i16 pitch, u16 track_bits);
void func_08008C70(struct MusicPlayer ** holder, i8 pan, u16 track_bits);
void func_08008C8C(struct MusicPlayer ** holder, u8 depth, u16 track_bits);
void func_08008CA8(struct MusicPlayer ** holder, u8 speed, u16 track_bits);
void func_08008CC4(struct MusicPlayer ** holder);
u32 func_08008CD0(struct MusicPlayer ** holder);
u16 func_08008CDC(struct MusicPlayer ** holder);
u8 func_08008CE4(struct MusicPlayer ** holder);
u8 func_08008CEC(struct MusicPlayer ** holder);
u32 func_08008CF4(struct MusicPlayer ** holder);
struct MusicPlayer * func_08008CFC(void);

EXTERN_C_END

#endif // HARDWARE_MUSIC_PLAYER_HH

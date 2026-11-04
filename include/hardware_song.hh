#ifndef HARDWARE_SONG_HH
#define HARDWARE_SONG_HH

#include "prelude.h"

struct MusicPlayer;

#ifdef __cplusplus
struct HardwareMusicPlayerSlot;
// The native four-byte value return is the borrowed slot itself.
HardwareMusicPlayerSlot GetHardwareSongPlayerSlot(u16 song_id);
#endif

EXTERN_C

void func_08008D2C(u32 * value);
void func_08008D34(u32 * value);

u8 GetHardwareSongTrackCount(u16 song_id);
u8 GetHardwareSongPriority(u16 song_id);
void EnableHardwareSoundVSync(void);
void DisableHardwareSoundVSync(void);
u32 IsHardwareSoundDmaEnabled(void);
void StartHardwareSong(u16 song_id);
void StartOrChangeHardwareSong(u16 song_id);
void StartOrContinueHardwareSong(u16 song_id);
void StopHardwareSong(u16 song_id);
void StopAllHardwareMusicPlayers(void);
void ContinueHardwareSong(u16 song_id);
void ContinueAllHardwareMusicPlayers(void);
// Both native queries return the low byte of the linked table count.
u8 GetHardwareMusicPlayerCount(void);
u8 GetHardwareSongCount(void);

EXTERN_C_END

#endif // HARDWARE_SONG_HH

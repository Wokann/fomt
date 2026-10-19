#ifndef HARDWARE_MUSIC_PLAYER_HH
#define HARDWARE_MUSIC_PLAYER_HH

#include "prelude.h"

struct MusicPlayer;

#ifdef __cplusplus
// This slot borrows an m4a player; it does not own or destroy the player.
struct HardwareMusicPlayerSlot {
    explicit HardwareMusicPlayerSlot(u8 index) asm("func_08008B54");
    void Start(u16 song_id) asm("func_08008B6C");
    void StartIfChangedOrInactive(u16 song_id) asm("func_08008B88");
    void StartOrContinue(u16 song_id) asm("func_08008BB0");
    void Stop() asm("func_08008BE0");
    void Continue() asm("func_08008BEC");
    void FadeOut(u16 speed) asm("func_08008BF8");
    void FadeOutTemporarily(u16 speed) asm("func_08008C08");
    void FadeIn(u16 speed) asm("func_08008C18");
    void SetTempo(u16 tempo) asm("func_08008C28");
    void SetVolume(u16 volume, u16 track_bits) asm("func_08008C38");
    void SetPitch(i16 pitch, u16 track_bits) asm("func_08008C54");
    void SetPan(i8 pan, u16 track_bits) asm("func_08008C70");
    void SetModulationDepth(u8 depth, u16 track_bits) asm("func_08008C8C");
    void SetLfoSpeed(u8 speed, u16 track_bits) asm("func_08008CA8");
    void InitializeImmediately() asm("func_08008CC4");
    u32 IsActive() const asm("func_08008CD0");
    u16 GetStatus() const asm("func_08008CDC");
    u8 GetTrackCount() const asm("func_08008CE4");
    u8 GetPriority() const asm("func_08008CEC");
    u32 GetClock() const asm("func_08008CF4");

    MusicPlayer * value;
};

typedef char HardwareMusicPlayerSlotSizeCheck[sizeof(HardwareMusicPlayerSlot) == 4 ? 1 : -1];
typedef char HardwareMusicPlayerSlotValueCheck[offsetof(HardwareMusicPlayerSlot, value) == 0 ? 1 : -1];
#endif

EXTERN_C

// Native member ABI entries for C and partially recovered enclosing classes.
// These declarations do not introduce wrapper functions or symbol aliases.
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
struct MusicPlayer * func_08008D10(void);

EXTERN_C_END

#endif // HARDWARE_MUSIC_PLAYER_HH

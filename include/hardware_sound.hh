#ifndef HARDWARE_SOUND_HH
#define HARDWARE_SOUND_HH

#include "prelude.h"
#include "hardware_linked_list.hh"

struct MusicPlayer;

#ifdef __cplusplus
#pragma interface "hardware_sound_command_lifetimes.hh"
#endif

struct HardwareSoundVSyncCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifdef __cplusplus
    virtual bool Run();
#else
    struct HardwareLinkBase base;
#endif
};

struct HardwareSoundMainCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifdef __cplusplus
    virtual bool Run();
#else
    struct HardwareLinkBase base;
#endif
};


#ifdef __cplusplus
// This slot borrows an m4a player; it does not own or destroy the player.
struct HardwareMusicPlayerSlot {
    explicit HardwareMusicPlayerSlot(u8 index);
    void Start(u16 song_id);
    void StartIfChangedOrPaused(u16 song_id);
    void StartOrContinue(u16 song_id);
    void Stop();
    void Continue();
    void FadeOut(u16 speed);
    void FadeOutTemporarily(u16 speed);
    void FadeIn(u16 speed);
    void SetTempo(u16 tempo);
    void SetVolume(u16 volume, u16 track_bits);
    void SetPitch(i16 pitch, u16 track_bits);
    void SetPan(i8 pan, u16 track_bits);
    void SetModulationDepth(u8 depth, u16 track_bits);
    void SetLfoSpeed(u8 speed, u16 track_bits);
    void InitializeImmediately();
    bool IsUnpaused() const;
    u16 GetActiveTrackMask() const;
    u8 GetTrackCount() const;
    u8 GetPriority() const;
    u32 GetClock() const;

    MusicPlayer * value;
};

#endif

#ifdef __cplusplus
// The native four-byte value return is the borrowed slot itself.
HardwareMusicPlayerSlot GetHardwareSongPlayerSlot(u16 song_id);
// Direct ABI declaration for native owners whose full constructor is still
// represented as a procedural initializer. This names the real constructor;
// it does not add a wrapper or a second symbol.
extern "C" HardwareMusicPlayerSlot * ConstructHardwareMusicPlayerSlot(
    HardwareMusicPlayerSlot * slot, u8 index) asm("__23HardwareMusicPlayerSlotUc");
#endif

EXTERN_C

// Callers pass their manager; the wait itself only uses IRQ bit zero.
void WaitForHardwareVBlank(void * manager);
void InitializeHardwareSound(void);
struct MusicPlayer * GetHardwareMusicPlayer(u32 index);

// The two player lookup entries retain their own ABI.
// Their different index arguments are not assigned unverified audio roles.
struct MusicPlayer * GetFirstHardwareMusicPlayer(void);
struct MusicPlayer * func_08008D10(void);

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

#ifdef __cplusplus
#include "hardware_sound_command_lifetimes.hh"
#endif

#endif // HARDWARE_SOUND_HH

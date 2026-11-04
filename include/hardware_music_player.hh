#ifndef HARDWARE_MUSIC_PLAYER_HH
#define HARDWARE_MUSIC_PLAYER_HH

#include "prelude.h"

struct MusicPlayer;

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

typedef char HardwareMusicPlayerSlotSizeCheck[sizeof(HardwareMusicPlayerSlot) == 4 ? 1 : -1];
typedef char HardwareMusicPlayerSlotValueCheck[offsetof(HardwareMusicPlayerSlot, value) == 0 ? 1 : -1];
#endif

EXTERN_C

// The two remaining native player lookup entries retain their own ABI.
// Their different index arguments are not assigned unverified audio roles.
struct MusicPlayer * GetFirstHardwareMusicPlayer(void);
struct MusicPlayer * func_08008D10(void);

EXTERN_C_END

#endif // HARDWARE_MUSIC_PLAYER_HH

#include "hardware_music_player.hh"

#include "hardware_sound.hh"
#include "m4a.h"

HardwareMusicPlayerSlot::HardwareMusicPlayerSlot(u8 index)
{
    value = GetHardwareMusicPlayer(index);
}

void HardwareMusicPlayerSlot::Start(u16 song_id)
{
    m4aMPlayStart(value, gSongTable[song_id].song);
}

void HardwareMusicPlayerSlot::StartIfChangedOrInactive(u16 song_id)
{
    struct Song * song = gSongTable[song_id].song;
    struct MusicPlayer * player = value;
    if (player->song != song || (i32)player->status < 0)
        m4aMPlayStart(player, song);
}

void HardwareMusicPlayerSlot::StartOrContinue(u16 song_id)
{
    struct Song * song = gSongTable[song_id].song;
    struct MusicPlayer * player = value;
    if (player->song != song)
        m4aMPlayStart(player, song);
    else if ((i32)player->status < 0)
        m4aMPlayContinue(player);
}

void HardwareMusicPlayerSlot::Stop()
{
    m4aMPlayStop(value);
}

void HardwareMusicPlayerSlot::Continue()
{
    m4aMPlayContinue(value);
}

void HardwareMusicPlayerSlot::FadeOut(u16 speed)
{
    m4aMPlayFadeOut(value, speed);
}

void HardwareMusicPlayerSlot::FadeOutTemporarily(u16 speed)
{
    m4aMPlayFadeOutTemporarily(value, speed);
}

void HardwareMusicPlayerSlot::FadeIn(u16 speed)
{
    m4aMPlayFadeIn(value, speed);
}

void HardwareMusicPlayerSlot::SetTempo(u16 tempo)
{
    m4aMPlayTempoControl(value, tempo);
}

void HardwareMusicPlayerSlot::SetVolume(u16 volume, u16 track_bits)
{
    m4aMPlayVolumeControl(value, track_bits, volume);
}

void HardwareMusicPlayerSlot::SetPitch(i16 pitch, u16 track_bits)
{
    m4aMPlayPitchControl(value, track_bits, pitch);
}

void HardwareMusicPlayerSlot::SetPan(i8 pan, u16 track_bits)
{
    m4aMPlayPanpotControl(value, track_bits, pan);
}

void HardwareMusicPlayerSlot::SetModulationDepth(u8 depth, u16 track_bits)
{
    m4aMPlayModDepthSet(value, track_bits, depth);
}

void HardwareMusicPlayerSlot::SetLfoSpeed(u8 speed, u16 track_bits)
{
    m4aMPlayLFOSpeedSet(value, track_bits, speed);
}

void HardwareMusicPlayerSlot::InitializeImmediately()
{
    m4aMPlayImmInit(value);
}

u32 HardwareMusicPlayerSlot::IsActive() const
{
    return (value->status >> 31) ^ 1;
}

u16 HardwareMusicPlayerSlot::GetStatus() const
{
    return (u16)value->status;
}

u8 HardwareMusicPlayerSlot::GetTrackCount() const
{
    return value->track_count;
}

u8 HardwareMusicPlayerSlot::GetPriority() const
{
    return value->priority;
}

u32 HardwareMusicPlayerSlot::GetClock() const
{
    return value->clock;
}

struct MusicPlayer * func_08008CFC(void)
{
    HardwareMusicPlayerSlot player(0);
    return player.value;
}

struct MusicPlayer * func_08008D10(void)
{
    // The original entry passes the count, whose modulo lookup selects 0.
    // Keep this distinct from the preceding entry's direct zero index.
    HardwareMusicPlayerSlot player(NUM_MUSIC_PLAYERS);
    return player.value;
}

#include "hardware_music_player.hh"

#include "m4a.h"

extern struct MusicPlayer * func_08008B24(u32 index);

struct MusicPlayer ** func_08008B54(struct MusicPlayer ** holder, u8 index)
{
    *holder = func_08008B24(index);
    return holder;
}

void func_08008B6C(struct MusicPlayer ** holder, u16 song_id)
{
    m4aMPlayStart(*holder, gSongTable[song_id].song);
}

void func_08008B88(struct MusicPlayer ** holder, u16 song_id)
{
    struct Song * song = gSongTable[song_id].song;
    struct MusicPlayer * player = *holder;
    if (player->song != song || (i32)player->status < 0)
        m4aMPlayStart(player, song);
}

void func_08008BB0(struct MusicPlayer ** holder, u16 song_id)
{
    struct Song * song = gSongTable[song_id].song;
    struct MusicPlayer * player = *holder;
    if (player->song != song)
        m4aMPlayStart(player, song);
    else if ((i32)player->status < 0)
        m4aMPlayContinue(player);
}

void func_08008BE0(struct MusicPlayer ** holder)
{
    m4aMPlayStop(*holder);
}

void func_08008BEC(struct MusicPlayer ** holder)
{
    m4aMPlayContinue(*holder);
}

void func_08008BF8(struct MusicPlayer ** holder, u16 speed)
{
    m4aMPlayFadeOut(*holder, speed);
}

void func_08008C08(struct MusicPlayer ** holder, u16 speed)
{
    m4aMPlayFadeOutTemporarily(*holder, speed);
}

void func_08008C18(struct MusicPlayer ** holder, u16 speed)
{
    m4aMPlayFadeIn(*holder, speed);
}

void func_08008C28(struct MusicPlayer ** holder, u16 tempo)
{
    m4aMPlayTempoControl(*holder, tempo);
}

void func_08008C38(struct MusicPlayer ** holder, u16 volume, u16 track_bits)
{
    m4aMPlayVolumeControl(*holder, track_bits, volume);
}

void func_08008C54(struct MusicPlayer ** holder, i16 pitch, u16 track_bits)
{
    m4aMPlayPitchControl(*holder, track_bits, pitch);
}

void func_08008C70(struct MusicPlayer ** holder, i8 pan, u16 track_bits)
{
    m4aMPlayPanpotControl(*holder, track_bits, pan);
}

void func_08008C8C(struct MusicPlayer ** holder, u8 depth, u16 track_bits)
{
    m4aMPlayModDepthSet(*holder, track_bits, depth);
}

void func_08008CA8(struct MusicPlayer ** holder, u8 speed, u16 track_bits)
{
    m4aMPlayLFOSpeedSet(*holder, track_bits, speed);
}

void func_08008CC4(struct MusicPlayer ** holder)
{
    m4aMPlayImmInit(*holder);
}

u32 func_08008CD0(struct MusicPlayer ** holder)
{
    return ((*holder)->status >> 31) ^ 1;
}

u16 func_08008CDC(struct MusicPlayer ** holder)
{
    return (u16)(*holder)->status;
}

u8 func_08008CE4(struct MusicPlayer ** holder)
{
    return (*holder)->track_count;
}

u8 func_08008CEC(struct MusicPlayer ** holder)
{
    return (*holder)->priority;
}

u32 func_08008CF4(struct MusicPlayer ** holder)
{
    return (*holder)->clock;
}

struct MusicPlayer * func_08008CFC(void)
{
    struct MusicPlayer * player;
    func_08008B54(&player, 0);
    return player;
}

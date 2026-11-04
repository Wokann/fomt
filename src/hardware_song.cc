#include "hardware_song.hh"

#include "gbaio.h"
#include "hardware_music_player.hh"
#include "m4a.h"

void func_08008D2C(u32 * value)
{
    *value += 0x40;
}

void func_08008D34(u32 * value)
{
    *value -= 0x40;
}

HardwareMusicPlayerSlot GetHardwareSongPlayerSlot(u16 song_id)
{
    return HardwareMusicPlayerSlot(static_cast<u8>(gSongTable[song_id].ms));
}

u8 func_08008D5C(u16 song_id)
{
    return gSongTable[song_id].song->track_count;
}

u8 func_08008D70(u16 song_id)
{
    return gSongTable[song_id].song->priority;
}

void EnableHardwareSoundVSync(void)
{
    m4aSoundVSyncOn();
}

void DisableHardwareSoundVSync(void)
{
    m4aSoundVSyncOff();
}

u32 IsHardwareSoundDmaEnabled(void)
{
    return (REG_DMA1CNT & ((u32)DMA_ENABLE << 16)) != 0;
}

void func_08008DA8(u16 song_id)
{
    m4aSongNumStart(song_id);
}

void func_08008DB8(u16 song_id)
{
    m4aSongNumStartOrChange(song_id);
}

void func_08008DC8(u16 song_id)
{
    m4aSongNumStartOrContinue(song_id);
}

void func_08008DD8(u16 song_id)
{
    m4aSongNumStop(song_id);
}

void func_08008DE8(void)
{
    m4aMPlayAllStop();
}

void func_08008DF4(u16 song_id)
{
    m4aSongNumContinue(song_id);
}

void func_08008E04(void)
{
    m4aMPlayAllContinue();
}

u8 GetHardwareMusicPlayerCount(void)
{
    return NUM_MUSIC_PLAYERS;
}

u8 GetHardwareSongCount(void)
{
    return (u16)_M4aNumSongs;
}

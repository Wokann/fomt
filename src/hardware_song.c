#include "hardware_song.hh"

#include "gbaio.h"
#include "hardware_music_player.hh"
#include "m4a.h"

struct MusicPlayer * func_08008D3C(u16 song_id)
{
    struct MusicPlayer * player;
    func_08008B54(&player, (u8)gSongTable[song_id].ms);
    return player;
}

u8 func_08008D5C(u16 song_id)
{
    return gSongTable[song_id].song->track_count;
}

u8 func_08008D70(u16 song_id)
{
    return gSongTable[song_id].song->priority;
}

void func_08008D84(void)
{
    m4aSoundVSyncOn();
}

void func_08008D90(void)
{
    m4aSoundVSyncOff();
}

u32 func_08008D9C(void)
{
    return REG_DMA1CNT >> 31;
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

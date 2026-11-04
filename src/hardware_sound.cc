#include "prelude.h"
#include "hardware_sound.hh"

#include "interrupt.hh"
#include "gbaio.h"
#include "m4a.h"

void func_08008AF0(void * manager)
{
    (void)manager;
    WaitForNextInterrupt(INTR_FLAG_VBLANK);
}

void func_08008AFC(void)
{
    m4aSoundInit();
    m4aSoundVSyncOff();
}

bool HardwareSoundVSyncCommand::Run()
{
    m4aSoundVSync();
    return 1;
}

bool HardwareSoundMainCommand::Run()
{
    m4aSoundMain();
    return 1;
}

struct MusicPlayer * GetHardwareMusicPlayer(u32 index)
{
    u32 count = NUM_MUSIC_PLAYERS;
    if (index >= count)
        index %= count;
    return gMusicPlayerTable[index].music_player;
}

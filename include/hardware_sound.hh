#ifndef HARDWARE_SOUND_HH
#define HARDWARE_SOUND_HH

#include "prelude.h"
#include "hardware_linked_list.hh"

struct MusicPlayer;

struct HardwareSoundVSyncCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifdef __cplusplus
    virtual bool Run() asm("func_08008B0C");
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
    virtual bool Run() asm("func_08008B18");
#else
    struct HardwareLinkBase base;
#endif
};

typedef char HardwareSoundVSyncCommand_size_check[sizeof(struct HardwareSoundVSyncCommand) == 0x0C ? 1 : -1];
typedef char HardwareSoundMainCommand_size_check[sizeof(struct HardwareSoundMainCommand) == 0x0C ? 1 : -1];

EXTERN_C

// Callers pass their manager; the wait itself only uses IRQ bit zero.
void WaitForHardwareVBlank(void * manager);
void func_08008AFC(void);
u32 func_08008B0C(void);
u32 func_08008B18(void);
struct MusicPlayer * GetHardwareMusicPlayer(u32 index);

EXTERN_C_END

#endif // HARDWARE_SOUND_HH

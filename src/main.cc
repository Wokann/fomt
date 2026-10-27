#include "main.hh"
#include "interrupt.hh"
#include "sram_image.hh"
#include "sram_access.hh"
#include "hardware_manager.hh"
#include "intro_scene.hh"
#include "scene.hh"
#include "gbaio.h"
#include "gbasvc.h"

extern "C" void func_03000490(void);
extern "C" void func_08008AFC(void);

void AgbMain(void)
{
    REG_WAITCNT = 0x4014;
    InitializeInterrupts();
    ExchangeInterruptHandler(13, func_03000490);
    AcknowledgeAndEnableInterrupts(0x2000);

    SramAccess save;
    if (!IsValidSramImage(&save))
        InitializeSramImageHeader(&save);

    ExchangeInterruptHandler(12, func_08000240);
    REG_KEYCNT = 0xC00F;
    AcknowledgeAndEnableInterrupts(0x1000);
#if defined(REGION_EU) || defined(REGION_DE)
    REG_SIOCNT = 0x6000;
    REG_RCNT = 0;
#endif

    func_08008AFC();
    HardwareManagerOwner manager;
    SceneMain(SceneOwner(new GameIntroScene));
}

void func_08000240(void)
{
    volatile u16 *dma;

    DisableInterrupts(0xFFFF);
    REG_DISPCNT = 0x80;
    *((volatile u8 *)&REG_SOUNDCNT_X) = 0;

    while ((~REG_KEYINPUT & 0xF) != 0)
    {
    }

    dma = (volatile u16 *)&REG_DMA0SAD;
    dma[5] &= 0xC5FF;
    dma[5] &= 0x7FFF;
    (void)dma[5];
    dma += 6;
    dma[5] &= 0xC5FF;
    dma[5] &= 0x7FFF;
    (void)dma[5];
    dma += 6;
    dma[5] &= 0xC5FF;
    dma[5] &= 0x7FFF;
    (void)dma[5];

    {
        volatile u16 *dma3;

        dma3 = (volatile u16 *)&REG_DMA3SAD;
        dma3[5] &= 0xC5FF;
        dma3[5] &= 0x7FFF;
        (void)dma3[5];
    }

    SoftReset(0xFF);
    while (1)
    {
    }
}

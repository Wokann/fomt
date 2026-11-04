#include "main.hh"
#include "interrupt.hh"
#include "sram_image.hh"
#include "sram_access.hh"
#include "hardware_manager.hh"
#include "hardware_sound.hh"
#include "intro_scene.hh"
#include "scene.hh"
#include "gbaio.h"
#include "gbasvc.h"

void AgbMain(void)
{
    REG_WAITCNT = WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    InitializeInterrupts();
    ExchangeInterruptHandler(13, HandleGamePakInterrupt);
    AcknowledgeAndEnableInterrupts(INTR_FLAG_GAMEPAK);

    SramAccess save;
    if (!IsValidSramImage(&save))
        InitializeSramImageHeader(&save);

    ExchangeInterruptHandler(12, HandleSoftResetKeyInterrupt);
    REG_KEYCNT = KEY_INTR_ENABLE | KEY_AND_INTR | A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON;
    AcknowledgeAndEnableInterrupts(INTR_FLAG_KEYPAD);
#if defined(REGION_EU) || defined(REGION_DE)
    REG_SIOCNT = SIO_MULTI_MODE | SIO_INTR_ENABLE;
    REG_RCNT = 0;
#endif

    func_08008AFC();
    HardwareManagerOwner manager;
    SceneMain(SceneOwner(new GameIntroScene));
}

void HandleSoftResetKeyInterrupt(void)
{
    volatile u16 *dma;

    DisableInterrupts(0xFFFF);
    REG_DISPCNT = DISPCNT_FORCED_BLANK;
    *((volatile u8 *)&REG_SOUNDCNT_X) = 0;

    while ((~REG_KEYINPUT & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) != 0)
    {
    }

    dma = (volatile u16 *)&REG_DMA0SAD;
    dma[5] &= (u16)~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
    dma[5] &= (u16)~DMA_ENABLE;
    (void)dma[5];
    dma += 6;
    dma[5] &= (u16)~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
    dma[5] &= (u16)~DMA_ENABLE;
    (void)dma[5];
    dma += 6;
    dma[5] &= (u16)~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
    dma[5] &= (u16)~DMA_ENABLE;
    (void)dma[5];

    {
        volatile u16 *dma3;

        dma3 = (volatile u16 *)&REG_DMA3SAD;
        dma3[5] &= (u16)~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT);
        dma3[5] &= (u16)~DMA_ENABLE;
        (void)dma3[5];
    }

    SoftReset(GBA_RESET_ALL);
    while (1)
    {
    }
}

#include "main.hh"
#include "interrupt.h"
#include "sram_image.hh"
#include "sram_access.hh"
#include "hardware_manager.hh"
#include "hardware_sound.hh"
#include "intro_scene.hh"
#include "scene.hh"
#include "gbaio.h"
#include "gbasvc.h"

#include <new>

void AgbMain(void)
{
    REG_WAITCNT = WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    InitializeInterrupts();
    ExchangeInterruptHandler(IRQ_INDEX_CARTRIDGE, HandleGamePakInterrupt);
    AcknowledgeAndEnableInterrupts(INTR_FLAG_GAMEPAK);

    SramAccess save;
    if (!IsValidSramImage(&save))
        InitializeSramImageHeader(&save);

    ExchangeInterruptHandler(IRQ_INDEX_KEYPAD, HandleSoftResetKeyInterrupt);
    REG_KEYCNT = KEY_INTR_ENABLE | KEY_AND_INTR | A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON;
    AcknowledgeAndEnableInterrupts(INTR_FLAG_KEYPAD);
#if defined(REGION_EU) || defined(REGION_DE)
    REG_SIOCNT = SIO_MULTI_MODE | SIO_INTR_ENABLE;
    REG_RCNT = 0;
#endif

    InitializeHardwareSound();
    HardwareManagerOwner manager;
    SceneMain(SceneOwner(new GameIntroScene));
}

void HandleSoftResetKeyInterrupt(void)
{
    volatile u16 *dma;

    DisableInterrupts(0xFFFF);
    REG_DISPCNT = DISPCNT_FORCED_BLANK;
    REG_NR52 = 0;

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

asm_unified(
    ".pushsection .iwram, \"ax\", %progbits\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"six/asm/prelude.s\"\n"
    ".include \"six/asm/hw/video.s\"\n"
    ".include \"six/asm/hw/sound.s\"\n"
    "thumb_func_start HandleGamePakInterrupt\n"
    "HandleGamePakInterrupt:\n"
    "    push {lr}\n"
    "    ldr r1, .LGamePakInterruptIme\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    "    ldr r0, .LGamePakInterruptIe\n"
    "    movs r2, #0\n"
    "    strh r2, [r0]\n"
    "    movs r1, #(REG_DISPCNT >> 19)\n"
    "    lsls r1, r1, #19\n"
    "    movs r0, #LCD_FORCE_BLANK\n"
    "    strh r0, [r1]\n"
    "    ldr r0, .LGamePakInterruptSound\n"
    "    strb r2, [r0]\n"
    "    movs r0, #0\n"
    "    svc #SVC_SOUNDBIAS\n"
    "    .LGamePakInterruptStop:\n"
    "    svc #SVC_STOP\n"
    "    b .LGamePakInterruptStop\n"
    "    .align 2, 0\n"
    ".LGamePakInterruptIme: .word REG_IME\n"
    ".LGamePakInterruptIe: .word REG_IE\n"
    ".LGamePakInterruptSound: .word REG_SOUNDCNT_X\n"
    ".popsection\n"
    ".thumb\n"
);

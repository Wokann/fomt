#include "gbaio.h"
#include "gbasvc.h"

extern void func_08000528(u32 value);

void func_08000240(void)
{
    register volatile u16 *dma asm("r1");

    func_08000528(0xFFFF);
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
        register volatile u16 *dma3 asm("r0");

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

#include "main.hh"
#include "interrupt.hh"
#include "sram_proxy_1.hh"
#include "sram_proxy_2.hh"
#include "gbaio.h"
#include "gbasvc.h"

struct GameIntroScene;

extern void func_080D100C(u32 index, void (*handler)(void));
extern void func_03000490(void);
extern void func_08008AFC(void);
extern void func_08008980(void *manager);
extern void func_0800082C(void *scene_argument);
extern void func_08008A68(void *manager, u32 mode);
extern void *__builtin_new(u32 size);
extern struct GameIntroScene *ConstructGameIntroScene(struct GameIntroScene *scene);

// The original C++ ownership transfer leaves a two-word transfer record on
// the stack before moving the scene into SceneMain's by-value argument.
// Express that record explicitly here because this entry point is compiled
// as C alongside the reset handler. The temporary slot is released before
// SceneMain and checked again after it returns.
struct MainBootFrame {
    u32 manager;
    u32 scene_argument;
    u32 temporary;
    u32 save[2];
    volatile u32 transfer_owner;
    volatile u32 transfer_value;
};

void AgbMain(void)
{
    struct MainBootFrame frame;
    struct GameIntroScene *scene;

    REG_WAITCNT = 0x4014;
    func_080004C4();
    func_080D100C(13, func_03000490);
    func_0800050C(0x2000);

    func_08000640(frame.save);
    if (!func_080002E0(frame.save))
        func_08000358(frame.save);

    func_080D100C(12, func_08000240);
    REG_KEYCNT = 0xC00F;
    func_0800050C(0x1000);
#if defined(REGION_EU) || defined(REGION_DE)
    REG_SIOCNT = 0x6000;
    REG_RCNT = 0;
#endif

    func_08008AFC();
    func_08008980(&frame.manager);
    scene = ConstructGameIntroScene(__builtin_new(8));
    frame.transfer_owner = (u32)&frame.temporary;
    frame.transfer_value = (u32)scene;
    frame.temporary = 0;
    frame.scene_argument = (u32)scene;
    func_0800082C(&frame.scene_argument);

    if (frame.temporary != 0)
    {
        void (*destroy)(void *, int);
        destroy = *(void (**)(void *, int))(*(u32 *)frame.temporary + 8);
        destroy((void *)frame.temporary, 3);
    }
    func_08008A68(&frame.manager, 2);
}

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

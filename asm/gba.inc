    .ifndef GBA_ASM_CONSTANTS
    .equ GBA_ASM_CONSTANTS, 1

    @ Shared names follow the C definitions in gbaio.h and gbasvc.h.

    @ Memory and BIOS state.
    .equ EWRAM_END,                  0x02040000
    .equ IWRAM_END,                  0x03008000
    .equ MEM_ROM,                    0x08000000
    .equ VRAM,                       0x06000000
    .equ BG_PLTT,                    0x05000000
    .equ BG_PLTT_SIZE,               0x200
    .equ OBJ_PLTT,                   BG_PLTT + BG_PLTT_SIZE
    .equ OBJ_VRAM0,                  VRAM + 0x10000
    .equ INTR_CHECK,                 0x03007FF8

    @ ARM processor status.
    .equ PSR_IRQ_MODE,               0x12
    .equ PSR_SYS_MODE,               0x1F
    .equ PSR_MODE_MASK,              0x1F
    .equ PSR_F_BIT,                  0x40
    .equ PSR_I_BIT,                  0x80

    @ Register addresses.
    .equ REG_BASE,                   0x04000000
    .equ REG_DISPCNT,                REG_BASE + REG_OFFSET_DISPCNT
    .equ REG_DISPSTAT,               0x04000004
    .equ REG_VCOUNT,                 0x04000006
    .equ REG_BG1VOFS,                REG_BASE + REG_OFFSET_BG1VOFS
    .equ REG_MOSAIC,                 REG_BASE + REG_OFFSET_MOSAIC
    .equ REG_BLDCNT,                 REG_BASE + REG_OFFSET_BLDCNT
    .equ REG_BLDY,                   REG_BASE + REG_OFFSET_BLDY
    .equ REG_SOUND1CNT_L,            0x04000060
    .equ REG_SOUNDCNT_X,             0x04000084
    .equ REG_DMA1SAD,                0x040000BC
    .equ REG_DMA1CNT_L,              0x040000C4
    .equ REG_DMA1CNT_H,              0x040000C6
    .equ REG_DMA2CNT_L,              0x040000D0
    .equ REG_DMA2CNT_H,              0x040000D2
    .equ REG_SIOCNT,                 0x04000128
    .equ REG_RCNT,                   0x04000134
    .equ REG_JOYCNT,                 0x04000140
    .equ REG_JOY_RECV,               0x04000150
    .equ REG_JOY_TRANS,              0x04000154
    .equ REG_JOYSTAT,                0x04000158
    .equ REG_IE,                     REG_BASE + REG_OFFSET_IE
    .equ REG_IF,                     0x04000202
    .equ REG_IME,                    0x04000208

    @ Register offsets from REG_BASE.
    .equ REG_OFFSET_DISPCNT,         0x0
    .equ REG_OFFSET_BG0CNT,          0x8
    .equ REG_OFFSET_BG1CNT,          0xA
    .equ REG_OFFSET_BG2CNT,          0xC
    .equ REG_OFFSET_BG3CNT,          0xE
    .equ REG_OFFSET_BG0HOFS,         0x10
    .equ REG_OFFSET_BG0VOFS,         0x12
    .equ REG_OFFSET_BG1HOFS,         0x14
    .equ REG_OFFSET_BG1VOFS,         0x16
    .equ REG_OFFSET_BG2HOFS,         0x18
    .equ REG_OFFSET_BG2VOFS,         0x1A
    .equ REG_OFFSET_BG3HOFS,         0x1C
    .equ REG_OFFSET_BG3VOFS,         0x1E
    .equ REG_OFFSET_MOSAIC,          0x4C
    .equ REG_OFFSET_BLDCNT,          0x50
    .equ REG_OFFSET_BLDY,            0x54
    .equ REG_OFFSET_DMA3SAD,         0xD4
    .equ REG_OFFSET_DMA3DAD,         0xD8
    .equ REG_OFFSET_DMA3CNT,         0xDC
    .equ REG_OFFSET_IE,              0x200

    @ Display control and background layout.
    .equ DISPCNT_OBJ_1D_MAP,         0x40
    .equ DISPCNT_FORCED_BLANK,       0x80
    .equ DISPCNT_BG0_ON,             0x100
    .equ DISPCNT_BG1_ON,             0x200
    .equ DISPCNT_BG2_ON,             0x400
    .equ DISPCNT_BG3_ON,             0x800
    .equ DISPCNT_OBJ_ON,             0x1000
    .equ BG_CHAR_SIZE,               0x4000
    .equ BG_SCREEN_SIZE,             0x800
    .equ TILE_SIZE_4BPP,             0x20
    .equ PLTT_SIZE_4BPP,             0x20
    .equ BG_PRIO_0,                  0x0
    .equ BG_PRIO_1,                  0x1
    .equ BG_PRIO_2,                  0x2
    .equ BG_PRIO_3,                  0x3
    .equ BF_BG_GFX_BASE_OFFSET,      0x2
    .equ BF_BG_MAP_BASE_OFFSET,      0x8
    .equ BGCNT_MOSAIC,               0x40
    .equ BG_SIZE_256x256,            0x0
    .equ BG_SIZE_512x256,            0x4000
    .equ VCOUNT_VBLANK_START,        0xA0
    .equ VCOUNT_TOTAL_SCANLINES,     0xE4

    @ Mosaic and color effects.
    .equ BF_MOSAIC_BG_H_LENGTH,      0x4
    .equ BF_MOSAIC_BG_V_OFFSET,      0x4
    .equ BF_MOSAIC_OBJ_H_OFFSET,     0x8
    .equ BF_BLD_MODE_OFFSET,         0x6
    .equ BF_BLD_MODE_LENGTH,         0x2
    .equ BLD_MODE_ALPHA,             0x40
    .equ BLDCNT_EFFECT_LIGHTEN,      0x80
    .equ BLDCNT_EFFECT_DARKEN,       0xC0
    .equ BLD_TARGET2_BG0,            0x100
    .equ BLD_TARGET2_BG1,            0x200
    .equ BLD_TARGET2_BG2,            0x400
    .equ BLD_TARGET2_BG3,            0x800
    .equ BLD_TARGET2_OBJ,            0x1000
    .equ BLD_TARGET2_BD,             0x2000

    @ DMA control (upper halfword).
    .equ DMA_DST_FIXED,              0x40
    .equ DMA_SRC_INC,                0x0
    .equ DMA_REPEAT,                 0x200
    .equ DMA_32BIT,                  0x400
    .equ DMA_START_NOW,              0x0
    .equ DMA_START_SPECIAL,          0x3000
    .equ DMA_ENABLE,                 0x8000

    @ Interrupts and keypad.
    .equ IRQ_INDEX_VBLANK,           0x0
    .equ INTR_FLAG_VBLANK,           0x1
    .equ INTR_FLAG_SERIAL,           0x80
    .equ INTR_FLAG_GAMEPAK,          0x2000
    .equ KEY_INDEX_RIGHT,            0x4
    .equ KEY_INDEX_LEFT,             0x5
    .equ KEY_INDEX_UP,               0x6
    .equ KEY_INDEX_DOWN,             0x7
    .equ DPAD_DOWN,                  0x80

    @ BIOS software interrupts and RegisterRamReset flags.
    .equ SVC_SOFTRESET,              0
    .equ SVC_REGISTERRAMRESET,       1
    .equ SVC_STOP,                   3
    .equ SVC_INTRWAIT,               4
    .equ SVC_DIV,                    6
    .equ SVC_SQRT,                   8
    .equ SVC_ARCTAN2,                10
    .equ SVC_CPUSET,                 11
    .equ SVC_CPUFASTSET,             12
    .equ SVC_SOUNDBIAS,              25
    .equ GBA_RESET_EWRAM,            0x1
    .equ GBA_RESET_IWRAM,            0x2
    .equ GBA_RESET_SIO_IO,           0x20
    .equ GBA_RESET_SOUND_IO,         0x40
    .equ GBA_RESET_IO,               0x80

    .endif

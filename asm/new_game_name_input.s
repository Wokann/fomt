#include "new_game_name_input.hh"
#include "ui_graphics_sizes.hh"
    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"
    .syntax unified
    .thumb

    @ Keyboard rows are indexed from one in the native renderer.

#if defined(REGION_JP)
    .section .text.new_game_name_input_after_core_run
    thumb_func_start InitializeNameInputScreen
InitializeNameInputScreen:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #84	@ 0x54
    mov	sl, r0
    ldr r0, .Ljp_00005D9C
    ldr	r0, [r0, #0]
    ldr r1, .Ljp_00005DA0
    ldr r2, .Ljp_00005DA4
    ldr	r2, [r2, #0]
    bl CopyHardwareDma3
    ldr r0, .Ljp_00005DA8
    ldr	r0, [r0, #0]
    movs	r1, #(BG_PALETTE >> 19)
    lsls	r1, r1, #19
    movs	r2, #UI_SHARED_PALETTE_BYTES
    bl CopyHardwareDma3
    mov	r0, sl
    bl GetHardwareDisplayState
    add	r1, sp, #12
    movs	r3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)
    lsls	r3, r3, #5
    adds	r2, r3, #0
    strh	r2, [r1, #0]
    movs	r4, #0
    strh	r2, [r0, #0]
    mov	r0, sl
    bl GetHardwareDisplayState
    add	r2, sp, #12
    ldr r5, .Ljp_00005DAC
    adds	r1, r5, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #10]
    mov	r0, sl
    bl GetHardwareDisplayState
    add	r2, sp, #12
    ldr r7, .Ljp_00005DB0
    adds	r1, r7, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #12]
    ldr r0, .Ljp_00005DB4
    movs	r1, #20
    str	r1, [sp, #0]
    movs	r1, #150	@ 0x96
    lsls	r1, r1, #2
    str	r1, [sp, #4]
    str	r4, [sp, #8]
    movs	r1, #0
    movs	r2, #0
    movs	r3, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    bl DrawUiTextWindowBorder
    movs	r0, #1
    negs	r0, r0
    ldr r4, .Ljp_00005DB8
    movs	r2, #(BG_SCREEN_SIZE >> 4)
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl FillHardwareDma3
    movs	r1, #0
    add	r0, sp, #32
    mov	r8, r0
    add	r2, sp, #36	@ 0x24
    mov	r9, r2
    mov	r3, sp
    adds	r3, #16
    str	r3, [sp, #68]	@ 0x44
    mov	r5, sp
    adds	r5, #48	@ 0x30
    str	r5, [sp, #72]	@ 0x48
    mov	r7, sl
    adds	r7, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    ldr r0, .Ljp_00005DBC
    add	r0, sl
    str	r0, [sp, #64]	@ 0x40
    @ Blank tile from the cleared tail of the final character row.
#if ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255
    movs	r2, #((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1)
    lsls	r2, r2, #1
#else
    ldr r2, .Lname_input_jp_screen_blank_tile
#endif
    adds	r6, r2, #0
.Ljp_00005C5C:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    adds	r0, r2, r4
.Ljp_00005C64:
    strh	r6, [r0, #0]
    adds	r0, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005C64
    adds	r1, r5, #0
    cmp	r1, #19
    bls .Ljp_00005C5C
    movs	r3, #10
    ldr r2, .Ljp_00005DC0
    ldr r1, .Ljp_00005DC4
.Ljp_00005C7A:
    strh	r3, [r1, #0]
    adds	r0, r3, #0
    adds	r0, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #15
    bls .Ljp_00005C7A
    movs	r3, #3
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
    movs r4, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1)
    lsls r4, r4, #1
#else
    ldr r4, .Lname_input_map_jp_1
#endif

    adds	r5, r4, #0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
    movs r0, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1)
    lsls r0, r0, #1
#else
    ldr r0, .Lname_input_map_jp_2
#endif

    adds	r4, r0, #0
    ldr r2, .Ljp_00005DC8
    ldr r1, .Ljp_00005DCC
.Ljp_00005C9E:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #26
    bls .Ljp_00005C9E
    movs	r1, #4
    ldr r4, .Ljp_00005DB8
.Ljp_00005CB4:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    subs	r1, #2
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
    lsls	r0, r1, #4
    subs	r0, r0, r1
    lsls	r1, r0, #1
#else
    ldr r0, .Lname_input_map_jp_row_width
    muls r1, r0
#endif
    adds	r2, r2, r4
.Ljp_00005CC4:
    adds	r0, r1, r3
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005CC4
    adds	r1, r5, #0
    cmp	r1, #(4 + NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 1)
    bls .Ljp_00005CB4
    movs	r3, #18
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1)
    lsls r1, r1, #1
#else
    ldr r1, .Lname_input_map_jp_3
#endif

    adds	r5, r1, #0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
    movs r2, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1)
    lsls r2, r2, #1
#else
    ldr r2, .Lname_input_map_jp_4
#endif

    adds	r4, r2, #0
    ldr r2, .Ljp_00005DD0
    ldr r1, .Ljp_00005DD4
.Ljp_00005CE8:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005CE8
    ldr r0, .Ljp_00005DD8
    add	r0, sl
    ldr	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_00005D26
    movs	r3, #4
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) >> 2) <= 255
    movs r4, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) >> 2)
    lsls r4, r4, #2
#else
    ldr r4, .Lname_input_map_jp_5
#endif

    adds	r5, r4, #0
    ldr r0, .Ljp_00005DDC
    adds	r4, r0, #0
    ldr r2, .Ljp_00005DE0
    ldr r1, .Ljp_00005DE4
.Ljp_00005D14:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #(4 + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1)
    bls .Ljp_00005D14
.Ljp_00005D26:
    ldr r1, .Ljp_00005DE8
    movs	r0, #0
    movs	r2, #32
    bl FillHardwareDma3
    movs	r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs	r5, #2
    add	r0, sp, #32
    strh	r4, [r0, #0]
    mov	r1, r8
    strh	r5, [r1, #2]
    ldr	r0, [sp, #32]
    adds	r1, r7, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .Ljp_00005DEC
    add	r0, sp, #36	@ 0x24
    strh	r4, [r0, #0]
    mov	r2, r9
    strh	r5, [r2, #2]
    ldr	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #0]
    adds	r1, r7, #0
    movs	r2, #80	@ 0x50
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
    mov	r0, sl
    bl GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_jp_screen_2
#endif

    adds	r6, r0, #0
    add	r0, sp, #16
    adds	r1, r7, #0
    movs	r2, #(MEM_VRAM >> 19)
    lsls	r2, r2, #19
    bl __21DmaTransferDescriptorPCvPvUi
    ldr	r3, [sp, #68]	@ 0x44
    mov	r8, r3
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq .Ljp_00005DF0
    cmp	r1, #0
    beq .Ljp_00005D92
    adds	r0, r1, #0
    mov	r1, r8
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005D92:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b .Ljp_00005EB4
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_jp_screen_2: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255)
.Lname_input_jp_screen_blank_tile: .word (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
.Lname_input_map_jp_1: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
.Lname_input_map_jp_2: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
.Lname_input_map_jp_3: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
.Lname_input_map_jp_4: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) >> 2) <= 255)
.Lname_input_map_jp_5: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4)
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
.Lname_input_map_jp_row_width: .word (NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
.Ljp_00005D9C: .word gUiSharedTiles
.Ljp_00005DA0: .word (MEM_VRAM + 0x4B00)
.Ljp_00005DA4: .word gUiSharedTileByteCount
.Ljp_00005DA8: .word gUiSharedPalette
.Ljp_00005DAC: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.Ljp_00005DB0: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.Ljp_00005DB4: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)
.Ljp_00005DB8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)
.Ljp_00005DBC: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET)
.Ljp_00005DC0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)
.Ljp_00005DC4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)
.Ljp_00005DC8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)
.Ljp_00005DCC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x446)
.Ljp_00005DD0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)
.Ljp_00005DD4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)
.Ljp_00005DD8: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
.Ljp_00005DDC: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 4)
.Ljp_00005DE0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x88)
.Ljp_00005DE4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x48)
.Ljp_00005DE8: .word (MEM_VRAM + 0xFFC000)
.Ljp_00005DEC: .word gText_NewGameNameEntry_NameLabel
.Ljp_00005DF0:
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #1
    str	r0, [sp, #44]	@ 0x2c
    ldr	r0, [r6, #0]
    subs	r0, r1, r0
    asrs	r4, r0, #4
    str	r4, [sp, #40]	@ 0x28
    add	r1, sp, #44	@ 0x2c
    add	r0, sp, #40	@ 0x28
    cmp	r4, #1
    bcs .Ljp_00005E08
    adds	r0, r1, #0
.Ljp_00005E08:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq .Ljp_00005E26
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl malloc
    mov	r9, r4
    cmp	r0, #0
    bne .Ljp_00005E2A
    mov	r0, r9
    bl RetryMemoryAllocation
    b .Ljp_00005E2A
.Ljp_00005E26:
    movs	r0, #0
    mov	r9, r0
.Ljp_00005E2A:
    adds	r5, r0, #0
    str	r5, [sp, #80]	@ 0x50
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r2, r4
    beq .Ljp_00005E52
.Ljp_00005E38:
    cmp	r3, #0
    beq .Ljp_00005E48
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E48:
    adds	r2, #16
    adds	r3, #16
    ldr	r5, [sp, #76]	@ 0x4c
    cmp	r2, r5
    bne .Ljp_00005E38
.Ljp_00005E52:
    adds	r5, r3, #0
    ldr	r0, [sp, #44]	@ 0x2c
    cmp	r0, #1
    bne .Ljp_00005E6E
    cmp	r5, #0
    beq .Ljp_00005E6A
    adds	r0, r5, #0
    mov	r1, r8
    ldmia	r1!, {r2, r3, r7}
    stmia	r0!, {r2, r3, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E6A:
    adds	r5, #16
    b .Ljp_00005E90
.Ljp_00005E6E:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq .Ljp_00005E8E
.Ljp_00005E76:
    cmp	r2, #0
    beq .Ljp_00005E86
    adds	r0, r2, #0
    mov	r1, r8
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E86:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne .Ljp_00005E76
.Ljp_00005E8E:
    adds	r5, r2, #0
.Ljp_00005E90:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq .Ljp_00005EA0
.Ljp_00005E9A:
    adds	r1, #16
    cmp	r1, r2
    bne .Ljp_00005E9A
.Ljp_00005EA0:
    cmp	r0, #0
    beq .Ljp_00005EA8
    bl free
.Ljp_00005EA8:
    ldr	r0, [sp, #80]	@ 0x50
    add	r0, r9
    ldr	r1, [sp, #80]	@ 0x50
    str	r1, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.Ljp_00005EB4:
    ldr r1, .Ljp_00005F48
    add	r1, sl
    movs	r0, #0
    str	r0, [r1, #0]
    ldr r0, .Ljp_00005F4C
    add	r0, sl
    movs	r2, #1
    mov	r8, r2
    mov	r3, r8
    strb	r3, [r0, #0]
    mov	r0, sl
    bl RenderNameInputKeyboard
    movs r5, #NEW_GAME_NAME_INPUT_PROMPT_WIDTH
    movs r6, #NEW_GAME_NAME_INPUT_TILE_HEIGHT
    add	r0, sp, #48	@ 0x30
    strh	r5, [r0, #0]
    ldr	r4, [sp, #72]	@ 0x48
    strh	r6, [r4, #2]
    ldr	r0, [sp, #48]	@ 0x30
    ldr	r4, [sp, #64]	@ 0x40
    adds	r1, r4, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_00005F50
    add	r0, sl
    ldr	r1, [r0, #0]
    cmp	r1, #0
    beq .Ljp_00005F04
    add	r0, sp, #52	@ 0x34
    strh	r5, [r0, #0]
    strh	r6, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #0]
    adds	r1, r4, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Ljp_00005F04:
    mov	r0, sl
    bl GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 1) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 1) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 1)
    lsls r3, r3, #1
#else
    ldr r3, .Lname_input_jp_screen_3
#endif

    adds	r6, r0, #0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r2, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r2, r2, #3
    lsls r2, r2, #3
#else
    ldr r2, .Lname_input_jp_screen_1
#endif

    ldr r5, .Ljp_00005F54
    adds	r2, r2, r5
    add	r0, sp, #12
    ldr	r1, [sp, #64]	@ 0x40
    bl __21DmaTransferDescriptorPCvPvUi
    add	r7, sp, #12
    mov	r9, r7
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq .Ljp_00005F58
    cmp	r1, #0
    beq .Ljp_00005F3E
    adds	r0, r1, #0
    add	r1, sp, #12
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005F3E:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b .Ljp_0000601A
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_jp_screen_1: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 1) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 1) <= 255)
.Lname_input_jp_screen_3: .word (NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES)
#endif
.Ljp_00005F48: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
.Ljp_00005F4C: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.Ljp_00005F50: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
.Ljp_00005F54: .word (MEM_VRAM + NEW_GAME_NAME_INPUT_TILE_BYTES)
.Ljp_00005F58:
    str	r1, [sp, #76]	@ 0x4c
    mov	r5, r8
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #0]
    adds	r7, r1, #0
    subs	r0, r7, r0
    asrs	r4, r0, #4
    str	r4, [sp, #56]	@ 0x38
    add	r1, sp, #60	@ 0x3c
    add	r0, sp, #56	@ 0x38
    cmp	r4, #1
    bcs .Ljp_00005F72
    adds	r0, r1, #0
.Ljp_00005F72:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq .Ljp_00005F90
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl malloc
    mov	r8, r4
    cmp	r0, #0
    bne .Ljp_00005F94
    mov	r0, r8
    bl RetryMemoryAllocation
    b .Ljp_00005F94
.Ljp_00005F90:
    movs	r0, #0
    mov	r8, r0
.Ljp_00005F94:
    adds	r5, r0, #0
    str	r5, [sp, #80]	@ 0x50
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    b .Ljp_00005FB2
.Ljp_00005F9E:
    cmp	r3, #0
    beq .Ljp_00005FAE
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FAE:
    adds	r2, #16
    adds	r3, #16
.Ljp_00005FB2:
    ldr	r0, [sp, #76]	@ 0x4c
    cmp	r2, r0
    bne .Ljp_00005F9E
    adds	r5, r3, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Ljp_00005FD4
    cmp	r5, #0
    beq .Ljp_00005FD0
    adds	r0, r5, #0
    mov	r1, r9
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FD0:
    adds	r5, #16
    b .Ljp_00005FF6
.Ljp_00005FD4:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq .Ljp_00005FF4
.Ljp_00005FDC:
    cmp	r2, #0
    beq .Ljp_00005FEC
    adds	r0, r2, #0
    mov	r1, r9
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FEC:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne .Ljp_00005FDC
.Ljp_00005FF4:
    adds	r5, r2, #0
.Ljp_00005FF6:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq .Ljp_00006006
.Ljp_00006000:
    adds	r1, #16
    cmp	r1, r2
    bne .Ljp_00006000
.Ljp_00006006:
    cmp	r0, #0
    beq .Ljp_0000600E
    bl free
.Ljp_0000600E:
    ldr	r0, [sp, #80]	@ 0x50
    add	r0, r8
    ldr	r7, [sp, #80]	@ 0x50
    str	r7, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.Ljp_0000601A:
    ldr r0, .Ljp_00006070
    add	r0, sl
    ldr	r0, [r0, #0]
    mov	r9, r0
    mov	r0, sl
    bl GetHardwareCoreState
    mov	r8, r0
    mov	r0, sl
    bl GetHardwareSpriteBuffer
    adds	r6, r0, #0
    mov	r0, sl
    bl GetHardwareDisplayState
    adds	r5, r0, #0
    mov	r0, sl
    bl GetHardwareCommandList
    adds	r4, r0, #0
    mov	r0, sl
    bl GetHardwareInterruptList
    ldr r1, .Ljp_00006074
    add	r1, sl
    str	r4, [sp, #0]
    str	r0, [sp, #4]
    str	r1, [sp, #8]
    mov	r0, r9
    mov	r1, r8
    adds	r2, r6, #0
    adds	r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    add	sp, #84	@ 0x54
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_00006070: .word (NEW_GAME_NAME_INPUT_CORE_UI_OFFSET)
.Ljp_00006074: .word (NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET)

    .section .text.new_game_name_input_keyboard_raster
    thumb_func_start RenderNameInputKeyboard
RenderNameInputKeyboard:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    mov sl, r0
    ldr r0, .Ljp_080064A4
    add r0, sl
    ldrb r0, [r0]
    cmp r0, #0
    bne .Ljp_080063D6
    b .Ljp_0800671E
.Ljp_080063D6:
    movs r0, #1
    mov r8, r0
    mov r1, sp
    adds r1, #0x14
    str r1, [sp, #0x40]
    mov r2, sp
    adds r2, #0x18
    str r2, [sp, #0x44]
    mov r3, sp
    adds r3, #0x24
    str r3, [sp, #0x48]
    ldr r4, .Ljp_080064A8
    add r4, sl
    str r4, [sp, #0x50]
    mov r6, sp
    adds r6, #4
    str r6, [sp, #0x3c]
.Ljp_080063F8:
    mov r7, r8
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
#else
    ldr r4, .Lname_input_jp_keyboard_8
    muls r4, r7
#endif
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_080064AC
    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
    lsls r2, r0, #5
    subs r2, r2, r0
#else
    ldr r2, .Lname_input_jp_keyboard_9
    muls r2, r0
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255
    movs r0, #(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#else
    ldr r0, .Lname_input_jp_keyboard_10
#endif

    muls r0, r3
    adds r2, r2, r0
    ldr r0, .Ljp_080064B0
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl GetHardwareDmaQueue
    add r4, sl
    adds r4, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_jp_keyboard_6
#endif

    mov r2, r8
    muls r2, r1
    adds r5, r0, #0
    movs r3, #(MEM_VRAM >> 19)
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_jp_keyboard_6
#endif

    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .Ljp_080064B4
    cmp r1, #0
    beq .Ljp_0800648E
    adds r0, r1, #0
    add r1, sp, #4
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800648E:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    movs r0, #1
    add r8, r0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r1, r1, #3
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_jp_keyboard_4
#endif

    str r1, [sp, #0x4c]
    b .Ljp_08006586
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_jp_keyboard_4: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_jp_keyboard_6: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
.Lname_input_jp_keyboard_8: .word (NEW_GAME_NAME_INPUT_BUFFER_BYTES)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
.Lname_input_jp_keyboard_9: .word (NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255)
.Lname_input_jp_keyboard_10: .word (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
.Ljp_080064A4: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.Ljp_080064A8: .word (NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET + (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_BUFFER_BYTES)
.Ljp_080064AC: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
    @ This is the one-row-before base consumed by the keyboard-row renderer,
    @ not an interior pointer into the confirmation text.
.Ljp_080064B0: .word gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.Ljp_080064B4:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x20]
    ldr r0, [r5]
    adds r2, r1, #0
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x1c]
    add r1, sp, #0x20
    add r0, sp, #0x1c
    cmp r4, #1
    bcs .Ljp_080064CE
    adds r0, r1, #0
.Ljp_080064CE:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_080064EC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r9, r4
    cmp r0, #0
    bne .Ljp_080064F0
    mov r0, r9
    bl RetryMemoryAllocation
    b .Ljp_080064F0
.Ljp_080064EC:
    movs r0, #0
    mov r9, r0
.Ljp_080064F0:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    movs r4, #1
    add r8, r4
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r6, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r6, r6, #3
    lsls r6, r6, #3
#else
    ldr r6, .Lname_input_jp_keyboard_5
#endif

    str r6, [sp, #0x4c]
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .Ljp_08006524
.Ljp_0800650A:
    cmp r3, #0
    beq .Ljp_0800651A
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800651A:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .Ljp_0800650A
.Ljp_08006524:
    adds r4, r3, #0
    ldr r0, [sp, #0x20]
    cmp r0, #1
    bne .Ljp_08006540
    cmp r4, #0
    beq .Ljp_0800653C
    adds r0, r4, #0
    ldr r1, [sp, #0x3c]
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800653C:
    adds r4, #0x10
    b .Ljp_08006562
.Ljp_08006540:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .Ljp_08006560
.Ljp_08006548:
    cmp r2, #0
    beq .Ljp_08006558
    adds r0, r2, #0
    ldr r1, [sp, #0x3c]
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006558:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_08006548
.Ljp_08006560:
    adds r4, r2, #0
.Ljp_08006562:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006572
.Ljp_0800656C:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_0800656C
.Ljp_08006572:
    cmp r0, #0
    beq .Ljp_0800657A
    bl free
.Ljp_0800657A:
    ldr r0, [sp, #0x58]
    add r0, r9
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.Ljp_08006586:
    mov r0, r8
    cmp r0, #NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE
    bhi .Ljp_0800658E
    b .Ljp_080063F8
.Ljp_0800658E:
    movs r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs r5, #2
    add r0, sp, #0x24
    strh r4, [r0]
    ldr r1, [sp, #0x48]
    strh r5, [r1, #2]
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x50]
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_080065B8
    add r0, sl
    ldr r2, [r0]
    cmp r2, #1
    beq .Ljp_080065D4
    cmp r2, #1
    bgt .Ljp_080065BC
    cmp r2, #0
    beq .Ljp_080065C2
    b .Ljp_08006606
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_jp_keyboard_5: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.Ljp_080065B8: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
.Ljp_080065BC:
    cmp r2, #2
    beq .Ljp_080065F0
    b .Ljp_08006606
.Ljp_080065C2:
    ldr r1, .Ljp_080065D0
    add r0, sp, #0x28
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x28]
    b .Ljp_080065DE
    .align 2, 0
.Ljp_080065D0: .word gText_NewGameNameEntry_ModeKatakana
.Ljp_080065D4:
    ldr r1, .Ljp_080065EC
    add r0, sp, #0x2c
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x2c]
.Ljp_080065DE:
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    b .Ljp_08006606
.Ljp_080065EC: .word gText_NewGameNameEntry_ModeSymbols
.Ljp_080065F0:
    ldr r1, .Ljp_0800664C
    add r0, sp, #0x30
    strh r4, [r0]
    strh r2, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.Ljp_08006606:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r5, r0, #0
    ldr r3, [sp, #0x4c]
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r4, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r4, r4, #3
#else
    ldr r4, .Lname_input_jp_keyboard_7
#endif

    subs r2, r3, r4
    movs r6, #(MEM_VRAM >> 19)
    lsls r6, r6, #0x13
    adds r2, r2, r6
    add r0, sp, #4
    ldr r1, [sp, #0x50]
    adds r3, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #4
    mov r9, r7
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .Ljp_08006650
    cmp r1, #0
    beq .Ljp_08006642
    adds r0, r1, #0
    add r1, sp, #4
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006642:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .Ljp_08006716
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_jp_keyboard_7: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.Ljp_0800664C: .word gText_NewGameNameEntry_ModeHiragana
.Ljp_08006650:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x38]
    ldr r0, [r5]
    adds r6, r1, #0
    subs r0, r6, r0
    asrs r4, r0, #4
    str r4, [sp, #0x34]
    add r1, sp, #0x38
    add r0, sp, #0x34
    cmp r4, #1
    bcs .Ljp_0800666A
    adds r0, r1, #0
.Ljp_0800666A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08006688
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Ljp_0800668C
    mov r0, r8
    bl RetryMemoryAllocation
    b .Ljp_0800668C
.Ljp_08006688:
    movs r0, #0
    mov r8, r0
.Ljp_0800668C:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .Ljp_080066B4
.Ljp_0800669A:
    cmp r3, #0
    beq .Ljp_080066AA
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066AA:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .Ljp_0800669A
.Ljp_080066B4:
    adds r4, r3, #0
    ldr r0, [sp, #0x38]
    cmp r0, #1
    bne .Ljp_080066D0
    cmp r4, #0
    beq .Ljp_080066CC
    adds r0, r4, #0
    mov r1, r9
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066CC:
    adds r4, #0x10
    b .Ljp_080066F2
.Ljp_080066D0:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .Ljp_080066F0
.Ljp_080066D8:
    cmp r2, #0
    beq .Ljp_080066E8
    adds r0, r2, #0
    mov r1, r9
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066E8:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_080066D8
.Ljp_080066F0:
    adds r4, r2, #0
.Ljp_080066F2:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006702
.Ljp_080066FC:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_080066FC
.Ljp_08006702:
    cmp r0, #0
    beq .Ljp_0800670A
    bl free
.Ljp_0800670A:
    ldr r0, [sp, #0x58]
    add r0, r8
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.Ljp_08006716:
    ldr r1, .Ljp_08006730
    add r1, sl
    movs r0, #0
    strb r0, [r1]
.Ljp_0800671E:
    add sp, #0x5c
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Ljp_08006730: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)


#else
    .section .text.new_game_name_input_after_core_run
    thumb_func_start InitializeNameInputScreen
InitializeNameInputScreen: @ 0x08005CDC
#if defined(REGION_DE)
.LNewGameDE_08005CEC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #84
    mov	sl, r0
    ldr	r0, .LNewGameDE_08005ED4
    ldr	r0, [r0, #0]
    ldr	r1, .LNewGameDE_08005ED8
    ldr	r2, .LNewGameDE_08005EDC
    ldr	r2, [r2, #0]
    bl	CopyHardwareDma3
    ldr	r0, .LNewGameDE_08005EE0
    ldr	r0, [r0, #0]
    movs	r1, #(BG_PALETTE >> 19)
    lsls	r1, r1, #19
    movs	r2, #UI_SHARED_PALETTE_BYTES
    bl	CopyHardwareDma3
    mov	r0, sl
    bl	GetHardwareDisplayState
.LNewGameDE_08005D1C:
    add	r1, sp, #12
    movs	r3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)
    lsls	r3, r3, #5
    adds	r2, r3, #0
    strh	r2, [r1, #0]
    movs	r4, #0
    strh	r2, [r0, #0]
    mov	r0, sl
    bl	GetHardwareDisplayState
.LNewGameDE_08005D30:
    add	r2, sp, #12
    ldr	r5, .LNewGameDE_08005EE4
    adds	r1, r5, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #10]
    mov	r0, sl
    bl	GetHardwareDisplayState
    add	r2, sp, #12
    ldr	r7, .LNewGameDE_08005EE8
    adds	r1, r7, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #12]
    ldr	r0, .LNewGameDE_08005EEC
    movs	r1, #20
    str	r1, [sp, #0]
    movs	r1, #155
    lsls	r1, r1, #2
    str	r1, [sp, #4]
    str	r4, [sp, #8]
    movs	r1, #0
    movs	r2, #0
    movs	r3, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    bl	DrawUiTextWindowBorder
    movs	r0, #1
    negs	r0, r0
    ldr	r4, .LNewGameDE_08005EF0
    movs	r2, #(BG_SCREEN_SIZE >> 4)
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl	FillHardwareDma3
    movs	r1, #0
    add	r0, sp, #32
    mov	r8, r0
    add	r2, sp, #36
    mov	r9, r2
    mov	r3, sp
    adds	r3, #16
    str	r3, [sp, #64]
    mov	r5, sp
    adds	r5, #48
    str	r5, [sp, #68]
    mov	r7, sl
    adds	r7, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    ldr	r0, .LNewGameDE_08005EF4
    add	r0, sl
    str	r0, [sp, #72]
    @ DE uses cleared tile 28 of buffer 0, after the Name label.
    movs	r6, #28
.LNewGameDE_08005D94:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    adds	r0, r2, r4
.LNewGameDE_08005D9C:
    strh	r6, [r0, #0]
    adds	r0, #2
    adds	r3, #1
    cmp	r3, #29
    bls.n	.LNewGameDE_08005D9C
    adds	r1, r5, #0
    cmp	r1, #19
    bls.n	.LNewGameDE_08005D94
    movs	r3, #10
    ldr	r2, .LNewGameDE_08005EF8
    ldr	r1, .LNewGameDE_08005EFC
.LNewGameDE_08005DB2:
    strh	r3, [r1, #0]
    adds	r0, r3, #0
    adds	r0, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #15
    bls.n	.LNewGameDE_08005DB2
.LNewGameDE_08005DC4:
    movs	r3, #3
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
    movs r1, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1)
    lsls r1, r1, #1
#else
    ldr r1, .Lname_input_map_de_7
#endif

    adds	r5, r1, #0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
    movs r2, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1)
    lsls r2, r2, #1
#else
    ldr r2, .Lname_input_map_de_8
#endif

    adds	r4, r2, #0
    ldr	r2, .LNewGameDE_08005F00
    ldr	r1, .LNewGameDE_08005F04
.LNewGameDE_08005DD6:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #26
    bls.n	.LNewGameDE_08005DD6
    movs	r1, #4
    ldr	r4, .LNewGameDE_08005EF0
.LNewGameDE_08005DEC:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    subs	r1, #2
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
    lsls	r0, r1, #4
    subs	r0, r0, r1
    lsls	r1, r0, #1
#else
    ldr r0, .Lname_input_map_de_row_width
    muls r1, r0
#endif
    adds	r2, r2, r4
.LNewGameDE_08005DFC:
    adds	r0, r1, r3
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #29
    bls.n	.LNewGameDE_08005DFC
    adds	r1, r5, #0
    cmp	r1, #(4 + NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 1)
    bls.n	.LNewGameDE_08005DEC
    movs	r3, #18
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 3) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 2) <= 255
    movs r4, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 2)
    lsls r4, r4, #2
#else
    ldr r4, .Lname_input_map_de_9
#endif

    adds	r5, r4, #0
    ldr	r0, .LNewGameDE_08005F08
    adds	r4, r0, #0
    ldr	r2, .LNewGameDE_08005F0C
    ldr	r1, .LNewGameDE_08005F10
.LNewGameDE_08005E1E:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #29
    bls.n	.LNewGameDE_08005E1E
#if ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255
    movs r0, #((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7)
    lsls r0, r0, #7
#else
    ldr r0, .Lname_input_de_screen_11
#endif

    add	r0, sl
    ldr	r0, [r0, #0]
    cmp	r0, #0
    beq.n	.LNewGameDE_08005E5E
    movs	r3, #1
    ldr	r1, .LNewGameDE_08005F14
    adds	r5, r1, #0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255
    movs r2, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2)
    lsls r2, r2, #2
#else
    ldr r2, .Lname_input_map_de_10
#endif

    adds	r4, r2, #0
    ldr	r2, .LNewGameDE_08005F18
    ldr	r1, .LNewGameDE_08005F1C
.LNewGameDE_08005E4C:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #(1 + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1)
    bls.n	.LNewGameDE_08005E4C
.LNewGameDE_08005E5E:
    ldr	r1, .LNewGameDE_08005F20
    movs	r0, #0
    movs	r2, #32
    bl	FillHardwareDma3
    movs	r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs	r5, #2
    add	r0, sp, #32
    strh	r4, [r0, #0]
    mov	r3, r8
    strh	r5, [r3, #2]
    ldr	r0, [sp, #32]
    adds	r1, r7, #0
    movs	r2, #0
    bl	Clear2DGfxBuffer
    ldr	r1, .LNewGameDE_08005F24
    add	r0, sp, #36
    strh	r4, [r0, #0]
    mov	r4, r9
    strh	r5, [r4, #2]
    ldr	r0, [sp, #36]
    str	r1, [sp, #0]
    adds	r1, r7, #0
    movs	r2, #88
    movs	r3, #0
    bl	DrawStringTo2DGfxBuffer
    mov	r0, sl
    bl	GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_de_screen_13
#endif

    adds	r6, r0, #0
    add	r0, sp, #16
    adds	r1, r7, #0
    movs	r2, #(MEM_VRAM >> 19)
    lsls	r2, r2, #19
    bl	__21DmaTransferDescriptorPCvPvUi
    ldr	r5, [sp, #64]
    mov	r8, r5
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq.n	.LNewGameDE_08005F28
    cmp	r1, #0
    beq.n	.LNewGameDE_08005ECA
    adds	r0, r1, #0
    mov	r1, r8
    ldmia	r1!, {r2, r3, r7}
    stmia	r0!, {r2, r3, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08005ECA:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b.n	.LNewGameDE_08005FEE
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255)
.Lname_input_de_screen_11: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_de_screen_13: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
.Lname_input_map_de_7: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
.Lname_input_map_de_8: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 3) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 2) <= 255)
.Lname_input_map_de_9: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255)
.Lname_input_map_de_10: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1)
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
.Lname_input_map_de_row_width: .word (NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
.LNewGameDE_08005ED4: .word gUiSharedTiles
.LNewGameDE_08005ED8: .word (MEM_VRAM + 0x4D80)
.LNewGameDE_08005EDC: .word gUiSharedTileByteCount
.LNewGameDE_08005EE0: .word gUiSharedPalette
.LNewGameDE_08005EE4: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.LNewGameDE_08005EE8: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.LNewGameDE_08005EEC: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)
.LNewGameDE_08005EF0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)
.LNewGameDE_08005EF4: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET)
.LNewGameDE_08005EF8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)
.LNewGameDE_08005EFC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)
.LNewGameDE_08005F00: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x4C6)
.LNewGameDE_08005F04: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)
.LNewGameDE_08005F08: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
.LNewGameDE_08005F0C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)
.LNewGameDE_08005F10: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)
.LNewGameDE_08005F14: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 1)
.LNewGameDE_08005F18: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x82)
.LNewGameDE_08005F1C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x42)
.LNewGameDE_08005F20: .word (MEM_VRAM + 0xFFC000)
.LNewGameDE_08005F24: .word gText_NewGameNameEntry_NameLabel
.LNewGameDE_08005F28:
    str	r1, [sp, #76]
    movs	r0, #1
    str	r0, [sp, #44]
    ldr	r0, [r6, #0]
    adds	r4, r1, #0
    subs	r0, r4, r0
    asrs	r4, r0, #4
    str	r4, [sp, #40]
    add	r1, sp, #44
    add	r0, sp, #40
    cmp	r4, #1
    bcs.n	.LNewGameDE_08005F42
    adds	r0, r1, #0
.LNewGameDE_08005F42:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq.n	.LNewGameDE_08005F60
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl	malloc
    mov	r9, r4
    cmp	r0, #0
    bne.n	.LNewGameDE_08005F64
    mov	r0, r9
    bl	RetryMemoryAllocation
    b.n	.LNewGameDE_08005F64
.LNewGameDE_08005F60:
    movs	r0, #0
    mov	r9, r0
.LNewGameDE_08005F64:
    adds	r5, r0, #0
    str	r5, [sp, #80]
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    ldr	r5, [sp, #76]
    cmp	r2, r5
    beq.n	.LNewGameDE_08005F8C
.LNewGameDE_08005F72:
    cmp	r3, #0
    beq.n	.LNewGameDE_08005F82
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08005F82:
    adds	r2, #16
    adds	r3, #16
    ldr	r7, [sp, #76]
    cmp	r2, r7
    bne.n	.LNewGameDE_08005F72
.LNewGameDE_08005F8C:
    adds	r5, r3, #0
    ldr	r0, [sp, #44]
    cmp	r0, #1
    bne.n	.LNewGameDE_08005FA8
    cmp	r5, #0
    beq.n	.LNewGameDE_08005FA4
    adds	r0, r5, #0
    mov	r1, r8
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08005FA4:
    adds	r5, #16
    b.n	.LNewGameDE_08005FCA
.LNewGameDE_08005FA8:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq.n	.LNewGameDE_08005FC8
.LNewGameDE_08005FB0:
    cmp	r2, #0
    beq.n	.LNewGameDE_08005FC0
    adds	r0, r2, #0
    mov	r1, r8
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08005FC0:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne.n	.LNewGameDE_08005FB0
.LNewGameDE_08005FC8:
    adds	r5, r2, #0
.LNewGameDE_08005FCA:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq.n	.LNewGameDE_08005FDA
.LNewGameDE_08005FD4:
    adds	r1, #16
    cmp	r1, r2
    bne.n	.LNewGameDE_08005FD4
.LNewGameDE_08005FDA:
    cmp	r0, #0
    beq.n	.LNewGameDE_08005FE2
    bl	free
.LNewGameDE_08005FE2:
    ldr	r0, [sp, #80]
    add	r0, r9
    ldr	r7, [sp, #80]
    str	r7, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.LNewGameDE_08005FEE:
    ldr	r1, .LNewGameDE_08006088
    add	r1, sl
    movs	r0, #0
    str	r0, [r1, #0]
    ldr	r0, .LNewGameDE_0800608C
    add	r0, sl
    movs	r1, #1
    mov	r8, r1
    mov	r2, r8
    strb	r2, [r0, #0]
    mov	r0, sl
    bl	RenderNameInputKeyboard
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r7, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r7, r7, #3
#else
    ldr r7, .Lname_input_de_screen_14
#endif
    movs r5, #NEW_GAME_NAME_INPUT_PROMPT_WIDTH
    movs r6, #NEW_GAME_NAME_INPUT_TILE_HEIGHT
    add	r0, sp, #48
    strh	r5, [r0, #0]
    ldr	r3, [sp, #68]
    strh	r6, [r3, #2]
    ldr	r0, [sp, #48]
    ldr	r4, [sp, #72]
    adds	r1, r4, #0
    movs	r2, #0
    bl	Clear2DGfxBuffer
#if ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255
    movs r0, #((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7)
    lsls r0, r0, #7
#else
    ldr r0, .Lname_input_de_screen_12
#endif

    add	r0, sl
    ldr	r1, [r0, #0]
    cmp	r1, #0
    beq.n	.LNewGameDE_08006044
    add	r0, sp, #52
    strh	r5, [r0, #0]
    strh	r6, [r0, #2]
    ldr	r0, [sp, #52]
    str	r1, [sp, #0]
    adds	r1, r4, #0
    movs	r2, #0
    movs	r3, #0
    bl	DrawStringTo2DGfxBuffer
.LNewGameDE_08006044:
    mov	r0, sl
    bl	GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lname_input_de_screen_15
#endif

    adds	r6, r0, #0
#if (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) == (((1 << 2) + 1) * (1 << 1))
    lsls	r2, r7, #2
    adds	r2, r7, r2
    lsls	r2, r2, #1
#else
    ldr r2, .Lname_input_de_screen_16
#endif
    movs	r0, #(MEM_VRAM >> 19)
    lsls	r0, r0, #19
    adds	r2, r2, r0
    add	r0, sp, #12
    ldr	r1, [sp, #72]
    bl	__21DmaTransferDescriptorPCvPvUi
    add	r4, sp, #12
    mov	r9, r4
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq.n	.LNewGameDE_08006090
    cmp	r1, #0
    beq.n	.LNewGameDE_08006080
    adds	r0, r1, #0
    add	r1, sp, #12
    ldmia	r1!, {r2, r5, r7}
    stmia	r0!, {r2, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08006080:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b.n	.LNewGameDE_08006156
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255)
.Lname_input_de_screen_12: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_de_screen_14: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255)
.Lname_input_de_screen_15: .word (NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES)
#endif
#if !((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) == (((1 << 2) + 1) * (1 << 1)))
.Lname_input_de_screen_16: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.LNewGameDE_08006088: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
.LNewGameDE_0800608C: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.LNewGameDE_08006090:
    str	r1, [sp, #76]
    mov	r3, r8
    str	r3, [sp, #60]
    ldr	r0, [r6, #0]
    adds	r4, r1, #0
    subs	r0, r4, r0
    asrs	r4, r0, #4
    str	r4, [sp, #56]
    add	r1, sp, #60
    add	r0, sp, #56
    cmp	r4, #1
    bcs.n	.LNewGameDE_080060AA
    adds	r0, r1, #0
.LNewGameDE_080060AA:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq.n	.LNewGameDE_080060C8
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl	malloc
    mov	r8, r4
    cmp	r0, #0
    bne.n	.LNewGameDE_080060CC
    mov	r0, r8
    bl	RetryMemoryAllocation
    b.n	.LNewGameDE_080060CC
.LNewGameDE_080060C8:
    movs	r0, #0
    mov	r8, r0
.LNewGameDE_080060CC:
    adds	r5, r0, #0
    str	r5, [sp, #80]
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    ldr	r5, [sp, #76]
    cmp	r2, r5
    beq.n	.LNewGameDE_080060F4
.LNewGameDE_080060DA:
    cmp	r3, #0
    beq.n	.LNewGameDE_080060EA
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_080060EA:
    adds	r2, #16
    adds	r3, #16
    ldr	r7, [sp, #76]
    cmp	r2, r7
    bne.n	.LNewGameDE_080060DA
.LNewGameDE_080060F4:
    adds	r5, r3, #0
    ldr	r0, [sp, #60]
    cmp	r0, #1
    bne.n	.LNewGameDE_08006110
    cmp	r5, #0
    beq.n	.LNewGameDE_0800610C
    adds	r0, r5, #0
    mov	r1, r9
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_0800610C:
    adds	r5, #16
    b.n	.LNewGameDE_08006132
.LNewGameDE_08006110:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq.n	.LNewGameDE_08006130
.LNewGameDE_08006118:
    cmp	r2, #0
    beq.n	.LNewGameDE_08006128
    adds	r0, r2, #0
    mov	r1, r9
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08006128:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne.n	.LNewGameDE_08006118
.LNewGameDE_08006130:
    adds	r5, r2, #0
.LNewGameDE_08006132:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq.n	.LNewGameDE_08006142
.LNewGameDE_0800613C:
    adds	r1, #16
    cmp	r1, r2
    bne.n	.LNewGameDE_0800613C
.LNewGameDE_08006142:
    cmp	r0, #0
    beq.n	.LNewGameDE_0800614A
    bl	free
.LNewGameDE_0800614A:
    ldr	r0, [sp, #80]
    add	r0, r8
    ldr	r7, [sp, #80]
    str	r7, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.LNewGameDE_08006156:
    ldr	r0, .LNewGameDE_080061AC
    add	r0, sl
    ldr	r0, [r0, #0]
    mov	r9, r0
    mov	r0, sl
    bl	GetHardwareCoreState
    mov	r8, r0
    mov	r0, sl
    bl	GetHardwareSpriteBuffer
    adds	r6, r0, #0
    mov	r0, sl
    bl	GetHardwareDisplayState
    adds	r5, r0, #0
    mov	r0, sl
    bl	GetHardwareCommandList
    adds	r4, r0, #0
    mov	r0, sl
    bl	GetHardwareInterruptList
    ldr	r1, .LNewGameDE_080061B0
    add	r1, sl
    str	r4, [sp, #0]
    str	r0, [sp, #4]
    str	r1, [sp, #8]
    mov	r0, r9
    mov	r1, r8
    adds	r2, r6, #0
    adds	r3, r5, #0
    bl	Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    add	sp, #84
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.LNewGameDE_080061AC: .word (NEW_GAME_NAME_INPUT_CORE_UI_OFFSET)
.LNewGameDE_080061B0: .word (NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET)

#else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x54
    mov sl, r0
    ldr r0, .L08005EC8 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L08005ECC
    ldr r2, .L08005ED0 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L08005ED4 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #(BG_PALETTE >> 19)
    lsls r1, r1, #0x13
    movs r2, #UI_SHARED_PALETTE_BYTES
    bl CopyHardwareDma3
    mov r0, sl
    bl GetHardwareDisplayState
    add r1, sp, #0xc
    movs r3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r5, .L08005ED8 @ =0x00001841
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r7, .L08005EDC @ =0x00001F02
    adds r1, r7, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .L08005EE0
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    bl DrawUiTextWindowBorder
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L08005EE4
    movs r2, #(BG_SCREEN_SIZE >> 4)
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r1, #0
    add r0, sp, #0x20
    mov r8, r0
    add r2, sp, #0x24
    mov sb, r2
    mov r3, sp
    adds r3, #0x10
    str r3, [sp, #0x44]
    mov r5, sp
    adds r5, #0x30
    str r5, [sp, #0x48]
    mov r7, sl
    adds r7, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    ldr r0, .L08005EE8
    add r0, sl
    str r0, [sp, #0x40]
    @ Blank tile from the cleared tail of the final character row.
#if ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255
    movs r2, #((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1)
    lsls r2, r2, #1
#else
    ldr r2, .Lname_input_overseas_screen_blank_tile
#endif
    adds r6, r2, #0
.L08005D88:
    movs r3, #0
    lsls r2, r1, #6
    adds r5, r1, #1
    adds r0, r2, r4
.L08005D90:
    strh r6, [r0]
    adds r0, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005D90
    adds r1, r5, #0
    cmp r1, #0x13
    bls .L08005D88
    movs r3, #0xa
    ldr r2, .L08005EEC
    ldr r1, .L08005EF0
.L08005DA6:
    strh r3, [r1]
    adds r0, r3, #0
    adds r0, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0xf
    bls .L08005DA6
    movs r3, #3
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
    movs r4, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1)
    lsls r4, r4, #1
#else
    ldr r4, .Lname_input_map_overseas_12
#endif

    adds r5, r4, #0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
    movs r0, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1)
    lsls r0, r0, #1
#else
    ldr r0, .Lname_input_map_overseas_13
#endif

    adds r4, r0, #0
    ldr r2, .L08005EF4
    ldr r1, .L08005EF8
.L08005DCA:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0x1a
    bls .L08005DCA
    movs r1, #4
    ldr r4, .L08005EE4
.L08005DE0:
    movs r3, #0
    lsls r2, r1, #6
    adds r5, r1, #1
    subs r1, #2
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r1, r0, #1
#else
    ldr r0, .Lname_input_map_overseas_row_width
    muls r1, r0
#endif
    adds r2, r2, r4
.L08005DF0:
    adds r0, r1, r3
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005DF0
    adds r1, r5, #0
    cmp r1, #(4 + NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 1)
    bls .L08005DE0
    movs r3, #0x12
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1)
    lsls r1, r1, #1
#else
    ldr r1, .Lname_input_map_overseas_14
#endif

    adds r5, r1, #0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
    movs r2, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1)
    lsls r2, r2, #1
#else
    ldr r2, .Lname_input_map_overseas_15
#endif

    adds r4, r2, #0
    ldr r2, .L08005EFC
    ldr r1, .L08005F00
.L08005E14:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005E14
    ldr r0, .L08005F04
    add r0, sl
    ldr r0, [r0]
    cmp r0, #0
    beq .L08005E52
    movs r3, #1
    ldr r4, .L08005F08 @ =0x0000021B
    adds r5, r4, #0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255
    movs r0, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2)
    lsls r0, r0, #2
#else
    ldr r0, .Lname_input_map_overseas_16
#endif

    adds r4, r0, #0
    ldr r2, .L08005F0C
    ldr r1, .L08005F10
.L08005E40:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #(1 + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1)
    bls .L08005E40
.L08005E52:
    ldr r1, .L08005F14
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs r5, #2
    add r0, sp, #0x20
    strh r4, [r0]
    mov r1, r8
    strh r5, [r1, #2]
    ldr r0, [sp, #0x20]
    adds r1, r7, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .L08005F18 @ =gText_NewGameNameEntry_NameLabel
    add r0, sp, #0x24
    strh r4, [r0]
    mov r2, sb
    strh r5, [r2, #2]
    ldr r0, [sp, #0x24]
    str r1, [sp]
    adds r1, r7, #0
    movs r2, #0x58
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_overseas_screen_19
#endif

    adds r6, r0, #0
    add r0, sp, #0x10
    adds r1, r7, #0
    movs r2, #(MEM_VRAM >> 19)
    lsls r2, r2, #0x13
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r3, [sp, #0x44]
    mov r8, r3
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08005F1C
    cmp r1, #0
    beq .L08005EBE
    adds r0, r1, #0
    mov r1, r8
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005EBE:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L08005FE0
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_overseas_screen_19: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255)
.Lname_input_overseas_screen_blank_tile: .word (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
.Lname_input_map_overseas_12: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
.Lname_input_map_overseas_13: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
.Lname_input_map_overseas_14: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
.Lname_input_map_overseas_15: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255)
.Lname_input_map_overseas_16: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1)
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
.Lname_input_map_overseas_row_width: .word (NEW_GAME_NAME_INPUT_TILE_WIDTH)
#endif
.L08005EC8: .word gUiSharedTiles
.L08005ECC: .word (MEM_VRAM + 0x4B00)
.L08005ED0: .word gUiSharedTileByteCount
.L08005ED4: .word gUiSharedPalette
.L08005ED8: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.L08005EDC: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.L08005EE0: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)
.L08005EE4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)
.L08005EE8: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET)
.L08005EEC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)
.L08005EF0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)
.L08005EF4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)
.L08005EF8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x446)
.L08005EFC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)
.L08005F00: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)
.L08005F04: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
.L08005F08: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 1)
.L08005F0C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x82)
.L08005F10: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x42)
.L08005F14: .word (MEM_VRAM + 0xFFC000)
.L08005F18: .word gText_NewGameNameEntry_NameLabel
.L08005F1C:
    str r1, [sp, #0x4c]
    movs r0, #1
    str r0, [sp, #0x2c]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x28]
    add r1, sp, #0x2c
    add r0, sp, #0x28
    cmp r4, #1
    bhs .L08005F34
    adds r0, r1, #0
.L08005F34:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005F52
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005F56
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005F56
.L08005F52:
    movs r0, #0
    mov sb, r0
.L08005F56:
    adds r5, r0, #0
    str r5, [sp, #0x50]
    ldr r2, [r6]
    adds r3, r5, #0
    ldr r4, [sp, #0x4c]
    cmp r2, r4
    beq .L08005F7E
.L08005F64:
    cmp r3, #0
    beq .L08005F74
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005F74:
    adds r2, #0x10
    adds r3, #0x10
    ldr r5, [sp, #0x4c]
    cmp r2, r5
    bne .L08005F64
.L08005F7E:
    adds r5, r3, #0
    ldr r0, [sp, #0x2c]
    cmp r0, #1
    bne .L08005F9A
    cmp r5, #0
    beq .L08005F96
    adds r0, r5, #0
    mov r1, r8
    ldm r1!, {r2, r3, r7}
    stm r0!, {r2, r3, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005F96:
    adds r5, #0x10
    b .L08005FBC
.L08005F9A:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08005FBA
.L08005FA2:
    cmp r2, #0
    beq .L08005FB2
    adds r0, r2, #0
    mov r1, r8
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005FB2:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005FA2
.L08005FBA:
    adds r5, r2, #0
.L08005FBC:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08005FCC
.L08005FC6:
    adds r1, #0x10
    cmp r1, r2
    bne .L08005FC6
.L08005FCC:
    cmp r0, #0
    beq .L08005FD4
    bl free
.L08005FD4:
    ldr r0, [sp, #0x50]
    add r0, sb
    ldr r1, [sp, #0x50]
    str r1, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08005FE0:
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7)
    lsls r1, r1, #7
#else
    ldr r1, .Lname_input_overseas_screen_17
#endif

    add r1, sl
    movs r0, #0
    str r0, [r1]
    ldr r0, .L08006074
    add r0, sl
    movs r2, #1
    mov r8, r2
    mov r3, r8
    strb r3, [r0]
    mov r0, sl
    bl RenderNameInputKeyboard
    movs r5, #NEW_GAME_NAME_INPUT_PROMPT_WIDTH
    movs r6, #NEW_GAME_NAME_INPUT_TILE_HEIGHT
    add r0, sp, #0x30
    strh r5, [r0]
    ldr r4, [sp, #0x48]
    strh r6, [r4, #2]
    ldr r0, [sp, #0x30]
    ldr r4, [sp, #0x40]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .L08006078
    add r0, sl
    ldr r1, [r0]
    cmp r1, #0
    beq .L08006032
    add r0, sp, #0x34
    strh r5, [r0]
    strh r6, [r0, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.L08006032:
    mov r0, sl
    bl GetHardwareDmaQueue
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lname_input_overseas_screen_20
#endif

    adds r6, r0, #0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r2, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r2, r2, #3
    lsls r2, r2, #3
#else
    ldr r2, .Lname_input_overseas_screen_18
#endif

    ldr r5, .L0800607C
    adds r2, r2, r5
    add r0, sp, #0xc
    ldr r1, [sp, #0x40]
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #0xc
    mov sb, r7
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08006080
    cmp r1, #0
    beq .L0800606C
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800606C:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L08006142
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
.Lname_input_overseas_screen_17: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_overseas_screen_18: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255)
.Lname_input_overseas_screen_20: .word (NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES)
#endif
.L08006074: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.L08006078: .word (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET)
.L0800607C: .word (MEM_VRAM + NEW_GAME_NAME_INPUT_TILE_BYTES)
.L08006080:
    str r1, [sp, #0x4c]
    mov r5, r8
    str r5, [sp, #0x3c]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x38]
    add r1, sp, #0x3c
    add r0, sp, #0x38
    cmp r4, #1
    bhs .L0800609A
    adds r0, r1, #0
.L0800609A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080060B8
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L080060BC
    mov r0, r8
    bl RetryMemoryAllocation
    b .L080060BC
.L080060B8:
    movs r0, #0
    mov r8, r0
.L080060BC:
    adds r5, r0, #0
    str r5, [sp, #0x50]
    ldr r2, [r6]
    adds r3, r5, #0
    b .L080060DA
.L080060C6:
    cmp r3, #0
    beq .L080060D6
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080060D6:
    adds r2, #0x10
    adds r3, #0x10
.L080060DA:
    ldr r0, [sp, #0x4c]
    cmp r2, r0
    bne .L080060C6
    adds r5, r3, #0
    ldr r0, [sp, #0x3c]
    cmp r0, #1
    bne .L080060FC
    cmp r5, #0
    beq .L080060F8
    adds r0, r5, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L080060F8:
    adds r5, #0x10
    b .L0800611E
.L080060FC:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L0800611C
.L08006104:
    cmp r2, #0
    beq .L08006114
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006114:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08006104
.L0800611C:
    adds r5, r2, #0
.L0800611E:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0800612E
.L08006128:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006128
.L0800612E:
    cmp r0, #0
    beq .L08006136
    bl free
.L08006136:
    ldr r0, [sp, #0x50]
    add r0, r8
    ldr r7, [sp, #0x50]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08006142:
    ldr r0, .L08006198
    add r0, sl
    ldr r0, [r0]
    mov sb, r0
    mov r0, sl
    bl GetHardwareCoreState
    mov r8, r0
    mov r0, sl
    bl GetHardwareSpriteBuffer
    adds r6, r0, #0
    mov r0, sl
    bl GetHardwareDisplayState
    adds r5, r0, #0
    mov r0, sl
    bl GetHardwareCommandList
    adds r4, r0, #0
    mov r0, sl
    bl GetHardwareInterruptList
    ldr r1, .L0800619C
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    add sp, #0x54
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08006198: .word (NEW_GAME_NAME_INPUT_CORE_UI_OFFSET)
.L0800619C: .word (NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET)
#endif

    .section .text.new_game_name_input_keyboard_raster
    thumb_func_start RenderNameInputKeyboard
RenderNameInputKeyboard: @ 0x080064E8
#if defined(REGION_DE)
.LNewGameDE_080064F8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #92
    mov	sl, r0
    ldr r0, .LNewGameDE_080065E4
    add	r0, sl
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne.n	.LNewGameDE_08006512
    b.n	.LNewGameDE_0800685A
.LNewGameDE_08006512:
    movs	r0, #1
    mov	r8, r0
    mov	r1, sp
    adds	r1, #20
    str	r1, [sp, #64]
    mov	r2, sp
    adds	r2, #24
    str	r2, [sp, #68]
    mov	r3, sp
    adds	r3, #36
    str	r3, [sp, #72]
    ldr r4, .LNewGameDE_080065E8
    add	r4, sl
    str	r4, [sp, #80]
    mov	r6, sp
    adds	r6, #4
    str	r6, [sp, #60]
.LNewGameDE_08006534:
    mov	r7, r8
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
    lsls	r4, r7, #4
    subs	r4, r4, r7
    lsls	r4, r4, #5
    add	r4, r8
    lsls	r4, r4, #2
#else
    ldr r4, .Lname_input_de_keyboard_25
    muls r4, r7
#endif
    mov	r0, sl
    adds	r1, r4, r0
    add	r0, sp, #20
    movs	r2, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh	r2, [r0, #0]
    movs	r6, #2
    ldr	r3, [sp, #64]
    strh	r6, [r3, #2]
    ldr	r0, [sp, #20]
    adds	r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    movs	r2, #0
    bl	Clear2DGfxBuffer
    ldr r0, .LNewGameDE_080065EC
    add	r0, sl
    ldr	r0, [r0, #0]
    mov	r7, sl
    adds	r1, r4, r7
    mov	r2, r8
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
    lsls	r3, r2, #5
    subs	r3, r3, r2
#else
    ldr r3, .Lname_input_de_keyboard_26
    muls r3, r2
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
    lsls	r2, r0, #3
    subs	r2, r2, r0
    lsls	r0, r2, #5
    subs	r0, r0, r2
#else
    ldr r2, .Lname_input_de_keyboard_27
    muls r2, r0
    ldr r0, .Lname_input_de_keyboard_28
    muls r0, r2
#endif
    adds	r3, r3, r0
    ldr r0, .LNewGameDE_080065F0
    adds	r3, r3, r0
    add	r0, sp, #24
    movs	r6, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh	r6, [r0, #0]
    movs	r0, #2
.LNewGameDE_08006580:
    ldr	r7, [sp, #68]
    strh	r0, [r7, #2]
    ldr	r0, [sp, #24]
    adds	r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    str	r3, [sp, #0]
    movs	r2, #0
    movs	r3, #0
    bl	DrawStringTo2DGfxBuffer
    mov	r0, sl
    bl	GetHardwareDmaQueue
    add	r4, sl
    adds	r4, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_de_keyboard_23
#endif

    mov	r2, r8
    muls	r2, r1
    adds	r5, r0, #0
    movs	r3, #192
.LNewGameDE_080065A8:
    lsls	r3, r3, #19
    adds	r2, r2, r3
    add	r0, sp, #4
    adds	r1, r4, #0
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_de_keyboard_23
#endif

    bl	__21DmaTransferDescriptorPCvPvUi
    ldr	r1, [r5, #4]
    ldr	r0, [r5, #12]
    cmp	r1, r0
    beq.n	.LNewGameDE_080065F4
    cmp	r1, #0
    beq.n	.LNewGameDE_080065D0
    adds	r0, r1, #0
    add	r1, sp, #4
    ldmia	r1!, {r4, r6, r7}
    stmia	r0!, {r4, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_080065D0:
    ldr	r0, [r5, #4]
    adds	r0, #16
    str	r0, [r5, #4]
    movs	r0, #1
    add	r8, r0
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r1, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r1, r1, #3
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_de_keyboard_21
#endif

    str	r1, [sp, #76]
    b.n	.LNewGameDE_080066C6
    .align 2, 0
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_de_keyboard_21: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_de_keyboard_23: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
.Lname_input_de_keyboard_25: .word (NEW_GAME_NAME_INPUT_BUFFER_BYTES)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
.Lname_input_de_keyboard_26: .word (NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
.Lname_input_de_keyboard_27: .word (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
.Lname_input_de_keyboard_28: .word (NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
.LNewGameDE_080065E4: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.LNewGameDE_080065E8: .word (NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET + (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_BUFFER_BYTES)
.LNewGameDE_080065EC: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
.LNewGameDE_080065F0: .word gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.LNewGameDE_080065F4:
    str	r1, [sp, #84]
    movs	r0, #1
    str	r0, [sp, #32]
    ldr	r0, [r5, #0]
    adds	r2, r1, #0
    subs	r0, r2, r0
    asrs	r4, r0, #4
    str	r4, [sp, #28]
    add	r1, sp, #32
    add	r0, sp, #28
    cmp	r4, #1
    bcs.n	.LNewGameDE_0800660E
    adds	r0, r1, #0
.LNewGameDE_0800660E:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq.n	.LNewGameDE_0800662C
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl	malloc
    mov	r9, r4
    cmp	r0, #0
    bne.n	.LNewGameDE_08006630
    mov	r0, r9
    bl	RetryMemoryAllocation
    b.n	.LNewGameDE_08006630
.LNewGameDE_0800662C:
    movs	r0, #0
    mov	r9, r0
.LNewGameDE_08006630:
    adds	r4, r0, #0
    str	r4, [sp, #88]
    ldr	r2, [r5, #0]
    adds	r3, r4, #0
    movs	r4, #1
    add	r8, r4
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r6, #(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r6, r6, #3
    lsls r6, r6, #3
#else
    ldr r6, .Lname_input_de_keyboard_22
#endif

    str	r6, [sp, #76]
    ldr	r7, [sp, #84]
    cmp	r2, r7
    beq.n	.LNewGameDE_08006664
.LNewGameDE_0800664A:
    cmp	r3, #0
    beq.n	.LNewGameDE_0800665A
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r6, r7}
    stmia	r0!, {r4, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_0800665A:
    adds	r2, #16
    adds	r3, #16
    ldr	r0, [sp, #84]
    cmp	r2, r0
    bne.n	.LNewGameDE_0800664A
.LNewGameDE_08006664:
    adds	r4, r3, #0
    ldr	r0, [sp, #32]
    cmp	r0, #1
    bne.n	.LNewGameDE_08006680
    cmp	r4, #0
    beq.n	.LNewGameDE_0800667C
    adds	r0, r4, #0
    ldr	r1, [sp, #60]
    ldmia	r1!, {r2, r3, r6}
    stmia	r0!, {r2, r3, r6}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_0800667C:
    adds	r4, #16
    b.n	.LNewGameDE_080066A2
.LNewGameDE_08006680:
    adds	r3, r0, #0
    adds	r2, r4, #0
    cmp	r3, #0
    beq.n	.LNewGameDE_080066A0
.LNewGameDE_08006688:
    cmp	r2, #0
    beq.n	.LNewGameDE_08006698
    adds	r0, r2, #0
    ldr	r1, [sp, #60]
    ldmia	r1!, {r4, r6, r7}
    stmia	r0!, {r4, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08006698:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne.n	.LNewGameDE_08006688
.LNewGameDE_080066A0:
    adds	r4, r2, #0
.LNewGameDE_080066A2:
    ldr	r2, [r5, #4]
    ldr	r0, [r5, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq.n	.LNewGameDE_080066B2
.LNewGameDE_080066AC:
    adds	r1, #16
    cmp	r1, r2
    bne.n	.LNewGameDE_080066AC
.LNewGameDE_080066B2:
    cmp	r0, #0
    beq.n	.LNewGameDE_080066BA
    bl	free
.LNewGameDE_080066BA:
    ldr	r0, [sp, #88]
    add	r0, r9
    ldr	r7, [sp, #88]
    str	r7, [r5, #0]
    str	r4, [r5, #4]
    str	r0, [r5, #12]
.LNewGameDE_080066C6:
    mov	r0, r8
    cmp	r0, #NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE
    bhi.n	.LNewGameDE_080066CE
    b.n	.LNewGameDE_08006534
.LNewGameDE_080066CE:
    movs	r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs	r5, #2
    add	r0, sp, #36
    strh	r4, [r0, #0]
    ldr	r1, [sp, #72]
    strh	r5, [r1, #2]
    ldr	r0, [sp, #36]
    ldr	r1, [sp, #80]
    movs	r2, #0
    bl	Clear2DGfxBuffer
    ldr r0, .LNewGameDE_080066F8
    add	r0, sl
    ldr	r2, [r0, #0]
    cmp	r2, #1
    beq.n	.LNewGameDE_08006714
    cmp	r2, #1
    bgt.n	.LNewGameDE_080066FC
    cmp	r2, #0
    beq.n	.LNewGameDE_08006702
    b.n	.LNewGameDE_08006746
    .align 2, 0
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_de_keyboard_22: .word ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.LNewGameDE_080066F8: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
.LNewGameDE_080066FC:
    cmp	r2, #2
    beq.n	.LNewGameDE_08006730
    b.n	.LNewGameDE_08006746
.LNewGameDE_08006702:
    ldr r1, .LNewGameDE_08006710
    add	r0, sp, #40
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #40]
    b.n	.LNewGameDE_0800671E
    .align 2, 0
.LNewGameDE_08006710: .word gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006714:
    ldr r1, .LNewGameDE_0800672C
    add	r0, sp, #44
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #44]
.LNewGameDE_0800671E:
    str	r1, [sp, #0]
    ldr	r1, [sp, #80]
    movs	r2, #24
    movs	r3, #0
    bl	DrawStringTo2DGfxBuffer
    b.n	.LNewGameDE_08006746
.LNewGameDE_0800672C: .word gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006730:
    ldr r1, .LNewGameDE_08006788
    add	r0, sp, #48
    strh	r4, [r0, #0]
    strh	r2, [r0, #2]
    ldr	r0, [sp, #48]
    str	r1, [sp, #0]
    ldr	r1, [sp, #80]
    movs	r2, #24
    movs	r3, #0
    bl	DrawStringTo2DGfxBuffer
.LNewGameDE_08006746:
    mov	r0, sl
    bl	GetHardwareDmaQueue
    adds	r5, r0, #0
    movs	r2, #(MEM_VRAM >> 19)
    lsls	r2, r2, #19
    ldr	r3, [sp, #76]
    adds	r2, r3, r2
    add	r0, sp, #4
    ldr	r1, [sp, #80]
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_de_keyboard_24
#endif

    bl	__21DmaTransferDescriptorPCvPvUi
    add	r4, sp, #4
    mov	r9, r4
    ldr	r1, [r5, #4]
    ldr	r0, [r5, #12]
    cmp	r1, r0
    beq.n	.LNewGameDE_0800678C
    cmp	r1, #0
    beq.n	.LNewGameDE_0800677E
    adds	r0, r1, #0
    add	r1, sp, #4
    ldmia	r1!, {r2, r6, r7}
    stmia	r0!, {r2, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_0800677E:
    ldr	r0, [r5, #4]
    adds	r0, #16
    str	r0, [r5, #4]
    b.n	.LNewGameDE_08006852
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_de_keyboard_24: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.LNewGameDE_08006788: .word gText_NewGameNameEntry_EndLatin
.LNewGameDE_0800678C:
    str	r1, [sp, #84]
    movs	r0, #1
    str	r0, [sp, #56]
    ldr	r0, [r5, #0]
    adds	r3, r1, #0
    subs	r0, r3, r0
    asrs	r4, r0, #4
    str	r4, [sp, #52]
    add	r1, sp, #56
    add	r0, sp, #52
    cmp	r4, #1
    bcs.n	.LNewGameDE_080067A6
    adds	r0, r1, #0
.LNewGameDE_080067A6:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq.n	.LNewGameDE_080067C4
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl	malloc
    mov	r8, r4
    cmp	r0, #0
    bne.n	.LNewGameDE_080067C8
    mov	r0, r8
    bl	RetryMemoryAllocation
    b.n	.LNewGameDE_080067C8
.LNewGameDE_080067C4:
    movs	r0, #0
    mov	r8, r0
.LNewGameDE_080067C8:
    adds	r4, r0, #0
    str	r4, [sp, #88]
    ldr	r2, [r5, #0]
    adds	r3, r4, #0
    ldr	r4, [sp, #84]
    cmp	r2, r4
    beq.n	.LNewGameDE_080067F0
.LNewGameDE_080067D6:
    cmp	r3, #0
    beq.n	.LNewGameDE_080067E6
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r6, r7}
    stmia	r0!, {r4, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_080067E6:
    adds	r2, #16
    adds	r3, #16
    ldr	r6, [sp, #84]
    cmp	r2, r6
    bne.n	.LNewGameDE_080067D6
.LNewGameDE_080067F0:
    adds	r4, r3, #0
    ldr	r0, [sp, #56]
    cmp	r0, #1
    bne.n	.LNewGameDE_0800680C
    cmp	r4, #0
    beq.n	.LNewGameDE_08006808
    adds	r0, r4, #0
    mov	r1, r9
    ldmia	r1!, {r2, r3, r7}
    stmia	r0!, {r2, r3, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08006808:
    adds	r4, #16
    b.n	.LNewGameDE_0800682E
.LNewGameDE_0800680C:
    adds	r3, r0, #0
    adds	r2, r4, #0
    cmp	r3, #0
    beq.n	.LNewGameDE_0800682C
.LNewGameDE_08006814:
    cmp	r2, #0
    beq.n	.LNewGameDE_08006824
    adds	r0, r2, #0
    mov	r1, r9
    ldmia	r1!, {r4, r6, r7}
    stmia	r0!, {r4, r6, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.LNewGameDE_08006824:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne.n	.LNewGameDE_08006814
.LNewGameDE_0800682C:
    adds	r4, r2, #0
.LNewGameDE_0800682E:
    ldr	r2, [r5, #4]
    ldr	r0, [r5, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq.n	.LNewGameDE_0800683E
.LNewGameDE_08006838:
    adds	r1, #16
    cmp	r1, r2
    bne.n	.LNewGameDE_08006838
.LNewGameDE_0800683E:
    cmp	r0, #0
    beq.n	.LNewGameDE_08006846
    bl	free
.LNewGameDE_08006846:
    ldr	r0, [sp, #88]
    add	r0, r8
    ldr	r1, [sp, #88]
    str	r1, [r5, #0]
    str	r4, [r5, #4]
    str	r0, [r5, #12]
.LNewGameDE_08006852:
    ldr r1, .LNewGameDE_0800686C
    add	r1, sl
    movs	r0, #0
    strb	r0, [r1, #0]
.LNewGameDE_0800685A:
    add	sp, #92
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.LNewGameDE_0800686C: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)

#else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    mov sl, r0
    ldr r0, .L080065D0
    add r0, sl
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08006502
    b .L08006842
.L08006502:
    movs r0, #1
    mov r8, r0
    mov r1, sp
    adds r1, #0x14
    str r1, [sp, #0x40]
    mov r2, sp
    adds r2, #0x18
    str r2, [sp, #0x44]
    mov r3, sp
    adds r3, #0x24
    str r3, [sp, #0x48]
    ldr r4, .L080065D4
    add r4, sl
    str r4, [sp, #0x50]
    mov r6, sp
    adds r6, #4
    str r6, [sp, #0x3c]
.L08006524:
    mov r7, r8
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
#else
    ldr r4, .Lname_input_overseas_keyboard_35
    muls r4, r7
#endif
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    movs r2, #0
    bl Clear2DGfxBuffer
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
    movs r0, #((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7)
    lsls r0, r0, #7
#else
    ldr r0, .Lname_input_overseas_keyboard_29
#endif

    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
    lsls r2, r0, #5
    subs r2, r2, r0
#else
    ldr r2, .Lname_input_overseas_keyboard_36
    muls r2, r0
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255
    movs r0, #(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#else
    ldr r0, .Lname_input_overseas_keyboard_37
#endif

    muls r0, r3, r0
    adds r2, r2, r0
    ldr r0, .L080065D8 @ =gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl GetHardwareDmaQueue
    add r4, sl
    adds r4, #NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_overseas_keyboard_33
#endif

    mov r2, r8
    muls r2, r1, r2
    adds r5, r0, #0
    movs r3, #(MEM_VRAM >> 19)
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r3, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r3, r3, #3
#else
    ldr r3, .Lname_input_overseas_keyboard_33
#endif

    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080065DC
    cmp r1, #0
    beq .L080065BC
    adds r0, r1, #0
    add r1, sp, #4
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080065BC:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    movs r0, #1
    add r8, r0
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r1, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r1, r1, #3
    lsls r1, r1, #3
#else
    ldr r1, .Lname_input_overseas_keyboard_31
#endif

    str r1, [sp, #0x4c]
    b .L080066AE
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
.Lname_input_overseas_keyboard_29: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_overseas_keyboard_31: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_overseas_keyboard_33: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
.Lname_input_overseas_keyboard_35: .word (NEW_GAME_NAME_INPUT_BUFFER_BYTES)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
.Lname_input_overseas_keyboard_36: .word (NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255)
.Lname_input_overseas_keyboard_37: .word (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)
#endif
.L080065D0: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
.L080065D4: .word (NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET + (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_BUFFER_BYTES)
@ r8 is one-based here, so this is the keyboard table address minus exactly
@ one fixed-width row.  It is not a pointer into DogName.
.L080065D8: .word gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.L080065DC:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x20]
    ldr r0, [r5]
    adds r2, r1, #0
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x1c]
    add r1, sp, #0x20
    add r0, sp, #0x1c
    cmp r4, #1
    bhs .L080065F6
    adds r0, r1, #0
.L080065F6:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08006614
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08006618
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08006618
.L08006614:
    movs r0, #0
    mov sb, r0
.L08006618:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    movs r4, #1
    add r8, r4
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
    movs r6, #((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6)
    lsls r6, r6, #3
    lsls r6, r6, #3
#else
    ldr r6, .Lname_input_overseas_keyboard_32
#endif

    str r6, [sp, #0x4c]
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .L0800664C
.L08006632:
    cmp r3, #0
    beq .L08006642
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006642:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .L08006632
.L0800664C:
    adds r4, r3, #0
    ldr r0, [sp, #0x20]
    cmp r0, #1
    bne .L08006668
    cmp r4, #0
    beq .L08006664
    adds r0, r4, #0
    ldr r1, [sp, #0x3c]
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08006664:
    adds r4, #0x10
    b .L0800668A
.L08006668:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08006688
.L08006670:
    cmp r2, #0
    beq .L08006680
    adds r0, r2, #0
    ldr r1, [sp, #0x3c]
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006680:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08006670
.L08006688:
    adds r4, r2, #0
.L0800668A:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0800669A
.L08006694:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006694
.L0800669A:
    cmp r0, #0
    beq .L080066A2
    bl free
.L080066A2:
    ldr r0, [sp, #0x58]
    add r0, sb
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.L080066AE:
    mov r0, r8
    cmp r0, #NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE
    bhi .L080066B6
    b .L08006524
.L080066B6:
    movs r4, #NEW_GAME_NAME_INPUT_TILE_WIDTH
    movs r5, #2
    add r0, sp, #0x24
    strh r4, [r0]
    ldr r1, [sp, #0x48]
    strh r5, [r1, #2]
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x50]
    movs r2, #0
    bl Clear2DGfxBuffer
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
    movs r0, #((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7)
    lsls r0, r0, #7
#else
    ldr r0, .Lname_input_overseas_keyboard_30
#endif

    add r0, sl
    ldr r2, [r0]
    cmp r2, #1
    beq .L080066F8
    cmp r2, #1
    bgt .L080066E2
    cmp r2, #0
    beq .L080066E8
    b .L0800672A
.L080066E2:
    cmp r2, #2
    beq .L08006714
    b .L0800672A
.L080066E8:
    ldr r1, .L080066F4 @ =gText_NewGameNameEntry_EndLatin
    add r0, sp, #0x28
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x28]
    b .L08006702
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
.Lname_input_overseas_keyboard_30: .word (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET)
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
.Lname_input_overseas_keyboard_32: .word (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.L080066F4: .word gText_NewGameNameEntry_EndLatin
.L080066F8:
    ldr r1, .L08006710 @ =gText_NewGameNameEntry_EndFullWidth
    add r0, sp, #0x2c
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x2c]
.L08006702:
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    b .L0800672A
    .align 2, 0
.L08006710: .word gText_NewGameNameEntry_EndFullWidth
.L08006714:
    ldr r1, .L08006770 @ =gText_NewGameNameEntry_EndFullWidth
    add r0, sp, #0x30
    strh r4, [r0]
    strh r2, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.L0800672A:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r5, r0, #0
    ldr r3, [sp, #0x4c]
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
    movs r4, #((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3)
    lsls r4, r4, #3
#else
    ldr r4, .Lname_input_overseas_keyboard_34
#endif

    subs r2, r3, r4
    movs r6, #(MEM_VRAM >> 19)
    lsls r6, r6, #0x13
    adds r2, r2, r6
    add r0, sp, #4
    ldr r1, [sp, #0x50]
    adds r3, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #4
    mov sb, r7
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L08006774
    cmp r1, #0
    beq .L08006766
    adds r0, r1, #0
    add r1, sp, #4
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08006766:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L0800683A
    .align 2, 0
    .align 2, 0
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
.Lname_input_overseas_keyboard_34: .word (NEW_GAME_NAME_INPUT_TILE_BYTES)
#endif
.L08006770: .word gText_NewGameNameEntry_EndFullWidth
.L08006774:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x38]
    ldr r0, [r5]
    adds r6, r1, #0
    subs r0, r6, r0
    asrs r4, r0, #4
    str r4, [sp, #0x34]
    add r1, sp, #0x38
    add r0, sp, #0x34
    cmp r4, #1
    bhs .L0800678E
    adds r0, r1, #0
.L0800678E:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080067AC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L080067B0
    mov r0, r8
    bl RetryMemoryAllocation
    b .L080067B0
.L080067AC:
    movs r0, #0
    mov r8, r0
.L080067B0:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .L080067D8
.L080067BE:
    cmp r3, #0
    beq .L080067CE
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080067CE:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .L080067BE
.L080067D8:
    adds r4, r3, #0
    ldr r0, [sp, #0x38]
    cmp r0, #1
    bne .L080067F4
    cmp r4, #0
    beq .L080067F0
    adds r0, r4, #0
    mov r1, sb
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L080067F0:
    adds r4, #0x10
    b .L08006816
.L080067F4:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08006814
.L080067FC:
    cmp r2, #0
    beq .L0800680C
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800680C:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L080067FC
.L08006814:
    adds r4, r2, #0
.L08006816:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08006826
.L08006820:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006820
.L08006826:
    cmp r0, #0
    beq .L0800682E
    bl free
.L0800682E:
    ldr r0, [sp, #0x58]
    add r0, r8
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.L0800683A:
    ldr r1, .L08006854
    add r1, sl
    movs r0, #0
    strb r0, [r1]
.L08006842:
    add sp, #0x5c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08006854: .word (NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET)
#endif


#endif

#include "new_game_identity.hh"
    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"
    .syntax unified
    .thumb

#if defined(REGION_JP)
    .text
    .align 2, 0

    thumb_func_start InitializeNewGameIdentityScreen
InitializeNewGameIdentityScreen:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x70
    mov sl, r0
    ldr r0, .Ljp_080054B0
    ldr r0, [r0]
    ldr r1, .Ljp_080054B4
    ldr r2, .Ljp_080054B8
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .Ljp_080054BC
    ldr r0, [r0]
    movs r1, #(BG_PALETTE >> 19)
    lsls r1, r1, #0x13
    movs r2, #PLTT_SIZE_4BPP
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
    ldr r5, .Ljp_080054C0
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r3, .Ljp_080054C4
    adds r1, r3, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .Ljp_080054C8
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    ldr r1, .Ljp_080054CC
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r7, #0
    add r5, sp, #0x20
    add r4, sp, #0x24
    mov sb, r4
    mov r0, sp
    adds r0, #0x28
    str r0, [sp, #0x44]
    mov r1, sp
    adds r1, #0x2c
    str r1, [sp, #0x4c]
    mov r2, sp
    adds r2, #0x30
    str r2, [sp, #0x50]
    mov r3, sp
    adds r3, #0x34
    str r3, [sp, #0x54]
    mov r4, sp
    adds r4, #0x10
    str r4, [sp, #0x60]
    movs r0, #NEW_GAME_IDENTITY_VALUE_WIDTH
    mov r8, r0
    movs r6, #NEW_GAME_IDENTITY_TILE_HEIGHT
    mov r4, sl
    adds r4, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
.Ljp_08005398:
    add r0, sp, #0x20
    mov r1, r8
    strh r1, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r2, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r2, r2, #2
#else
    ldr r2, .Lidentity_jp_first_value_stride
#endif
    adds r4, r4, r2
    adds r7, #1
    cmp r7, #(2 * NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .Ljp_08005398
    movs r7, #0
    ldr r3, .Ljp_080054D0
    add r3, sl
    mov r8, r3
#if ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255
    movs r4, #((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4)
    lsls r4, r4, #4
#else
    ldr r4, .Lidentity_jp_first_label1
#endif
    add r4, sl
    str r4, [sp, #0x48]
    ldr r5, .Ljp_080054D4
    add r5, sl
    str r5, [sp, #0x5c]
    ldr r0, .Ljp_080054D8
    add r0, sl
    str r0, [sp, #0x58]
    movs r6, #NEW_GAME_IDENTITY_VALUE_WIDTH
    movs r5, #NEW_GAME_IDENTITY_TILE_HEIGHT
    mov r4, sl
    adds r4, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
.Ljp_080053DA:
    lsls r1, r7, #4
    add r1, sl
    ldr r2, .Ljp_080054DC
    adds r1, r1, r2
    add r0, sp, #0x24
    strh r6, [r0]
    mov r3, sb
    strh r5, [r3, #2]
    ldr r0, [sp, #0x24]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r0, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r0, r0, #2
#else
    ldr r0, .Lidentity_jp_first_value_stride
#endif
    adds r4, r4, r0
    adds r7, #1
    cmp r7, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .Ljp_080053DA
    ldr r1, .Ljp_080054E0
    movs r4, #NEW_GAME_IDENTITY_LABEL_WIDTH
    movs r5, #NEW_GAME_IDENTITY_TILE_HEIGHT
    add r0, sp, #0x28
    strh r4, [r0]
    ldr r2, [sp, #0x44]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x28]
    str r1, [sp]
    mov r1, r8
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054E4
    add r0, sp, #0x2c
    strh r4, [r0]
    ldr r3, [sp, #0x4c]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x2c]
    str r1, [sp]
    ldr r1, [sp, #0x48]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054E8
    add r0, sp, #0x30
    strh r4, [r0]
    ldr r0, [sp, #0x50]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x5c]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054EC
    add r0, sp, #0x34
    strh r4, [r0]
    ldr r2, [sp, #0x54]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    ldr r1, [sp, #0x58]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r7, #0
    ldr r3, [sp, #0x60]
    str r3, [sp, #0x40]
    movs r4, #(MEM_VRAM >> 19)
    lsls r4, r4, #0x13
    str r4, [sp, #0x64]
    mov r5, sl
    adds r5, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
    str r5, [sp, #0x68]
.Ljp_0800547A:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x68]
    ldr r2, [sp, #0x64]
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_jp_first_value_bytes
#endif
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .Ljp_080054F0
    cmp r1, #0
    beq .Ljp_080054A8
    adds r0, r1, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080054A8:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .Ljp_080055BA
    .align 2, 0
#if !(((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255)
.Lidentity_jp_first_label1: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_jp_first_value_stride: .word (NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
.Lidentity_jp_first_value_bytes: .word (NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
.Ljp_080054B0: .word gUiSharedTiles
.Ljp_080054B4: .word (MEM_VRAM + 0x4B00)
.Ljp_080054B8: .word gUiSharedTileByteCount
.Ljp_080054BC: .word gUiSharedPalette
.Ljp_080054C0: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.Ljp_080054C4: .word (BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.Ljp_080054C8: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)
@ Preserve the native mirrored VRAM destination; this is not BG screen block 24.
.Ljp_080054CC: .word (MEM_VRAM + 0xFFC000)
.Ljp_080054D0: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET)
.Ljp_080054D4: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + 2 * NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
.Ljp_080054D8: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + 3 * NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
.Ljp_080054DC: .word (NEW_GAME_IDENTITY_CORE_FIELDS_OFFSET)
.Ljp_080054E0: .word gText_NewGameIdentity_PlayerName
.Ljp_080054E4: .word gText_NewGameIdentity_PlayerBirthday
.Ljp_080054E8: .word gText_NewGameIdentity_FarmName
.Ljp_080054EC: .word gText_NewGameIdentity_DogName
.Ljp_080054F0:
    mov r8, r1
    movs r0, #1
    str r0, [sp, #0x3c]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x38]
    add r1, sp, #0x3c
    add r0, sp, #0x38
    cmp r4, #1
    bhs .Ljp_08005508
    adds r0, r1, #0
.Ljp_08005508:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08005526
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Ljp_0800552A
    mov r0, sb
    bl RetryMemoryAllocation
    b .Ljp_0800552A
.Ljp_08005526:
    movs r0, #0
    mov sb, r0
.Ljp_0800552A:
    adds r5, r0, #0
    str r5, [sp, #0x6c]
    ldr r2, [r6]
    mov ip, r5
    cmp r2, r8
    beq .Ljp_08005552
.Ljp_08005536:
    mov r5, ip
    cmp r5, #0
    beq .Ljp_08005548
    mov r0, ip
    adds r1, r2, #0
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08005548:
    adds r2, #0x10
    movs r0, #0x10
    add ip, r0
    cmp r2, r8
    bne .Ljp_08005536
.Ljp_08005552:
    mov r5, ip
    ldr r0, [sp, #0x3c]
    cmp r0, #1
    bne .Ljp_0800556E
    cmp r5, #0
    beq .Ljp_0800556A
    adds r0, r5, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800556A:
    adds r5, #0x10
    b .Ljp_08005596
.Ljp_0800556E:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .Ljp_08005594
.Ljp_08005576:
    cmp r2, #0
    beq .Ljp_08005586
    adds r0, r2, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08005586:
    movs r5, #1
    rsbs r5, r5, #0
    add r8, r5
    adds r2, #0x10
    mov r0, r8
    cmp r0, #0
    bne .Ljp_08005576
.Ljp_08005594:
    adds r5, r2, #0
.Ljp_08005596:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_080055A6
.Ljp_080055A0:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_080055A0
.Ljp_080055A6:
    cmp r0, #0
    beq .Ljp_080055AE
    bl free
.Ljp_080055AE:
    ldr r0, [sp, #0x6c]
    add r0, sb
    ldr r1, [sp, #0x6c]
    str r1, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.Ljp_080055BA:
    ldr r2, [sp, #0x64]
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_jp_last_value_bytes
#endif
    adds r2, r2, r3
    str r2, [sp, #0x64]
    ldr r4, [sp, #0x68]
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r5, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r5, r5, #2
#else
    ldr r5, .Lidentity_jp_last_value_stride
#endif
    adds r4, r4, r5
    str r4, [sp, #0x68]
    adds r7, #1
    cmp r7, #(2 * NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bhi .Ljp_080055D6
    b .Ljp_0800547A
.Ljp_080055D6:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .Ljp_080056BC
    movs r2, #(BG_SCREEN_SIZE >> 4)
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r7, #0
    @ Blank tile from the second (full-width space) DogName label glyph.
    @ Keep that label space: the map reuses its empty upper-left tile.
    movs r1, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT + 3 * NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT + 2)
.Ljp_080055EA:
    movs r5, #0
    lsls r0, r7, #6
    adds r0, r0, r4
.Ljp_080055F0:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r5, #0x1d
    bls .Ljp_080055F0
    adds r7, #1
    cmp r7, #0x13
    bls .Ljp_080055EA
    movs r5, #2
    ldr r6, .Ljp_080056C0
.Ljp_08005604:
    movs r7, #0
    lsls r1, r5, #1
    adds r4, r5, #0
    adds r4, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT + NEW_GAME_IDENTITY_LABEL_WIDTH - 2)
    adds r3, r5, #0
    adds r3, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT - 2)
    ldr r0, .Ljp_080056C4
    adds r2, r1, r0
.Ljp_08005614:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #(NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r3, #(NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r2, #(3 * 32 * 2)
    adds r1, #(3 * 32 * 2)
    adds r7, #1
    cmp r7, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .Ljp_08005614
    adds r5, #1
    cmp r5, #(2 + NEW_GAME_IDENTITY_LABEL_WIDTH - 1)
    bls .Ljp_08005604
    movs r5, #0x10
    ldr r1, .Ljp_080056C8
    mov r8, r1
    ldr r2, .Ljp_080056C0
    mov sb, r2
.Ljp_08005638:
    movs r7, #0
    lsls r1, r5, #1
    adds r6, r5, #1
    adds r0, r5, #0
    adds r0, #NEW_GAME_IDENTITY_VALUE_WIDTH
    mov r3, r8
    adds r4, r0, r3
    adds r3, r5, r3
    ldr r5, .Ljp_080056C4
    adds r2, r1, r5
.Ljp_0800564C:
    strh r3, [r2]
    mov r5, sb
    adds r0, r1, r5
    strh r4, [r0]
    adds r4, #(NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r3, #(NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r2, #(3 * 32 * 2)
    adds r1, #(3 * 32 * 2)
    adds r7, #1
    cmp r7, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .Ljp_0800564C
    adds r5, r6, #0
    cmp r5, #(16 + NEW_GAME_IDENTITY_VALUE_WIDTH - 1)
    bls .Ljp_08005638
    ldr r0, .Ljp_080056CC
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
    ldr r1, .Ljp_080056D0
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    add sp, #0x70
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_jp_last_value_stride: .word (NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
.Lidentity_jp_last_value_bytes: .word (NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
.Ljp_080056BC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)
.Ljp_080056C0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 2 * 32 * 2)
.Ljp_080056C4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 32 * 2)
.Ljp_080056C8: .word (0x10000 - 16)
.Ljp_080056CC: .word (NEW_GAME_IDENTITY_CORE_UI_OFFSET)
.Ljp_080056D0: .word (NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET)

#else
    .text
    .align 2, 0

    thumb_func_start InitializeNewGameIdentityScreen
InitializeNewGameIdentityScreen: @ US 0x08005278
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x94
    mov sl, r0
    ldr r0, .L08005488 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L0800548C @ =(MEM_VRAM + 0x4B00)
    ldr r2, .L08005490 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L08005494 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #(BG_PALETTE >> 19)
    lsls r1, r1, #0x13
    movs r2, #PLTT_SIZE_4BPP
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
    ldr r5, .L08005498 @ =(BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r7, .L0800549C @ =(BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
    adds r1, r7, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .L080054A0 @ =(MEM_VRAM + 31 * BG_SCREEN_SIZE)
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    ldr r1, .L080054A4 @ =(MEM_VRAM + 0xFFC000)
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r0, #0
    mov r8, r0
    add r5, sp, #0x20
    add r1, sp, #0x24
    mov sb, r1
    mov r2, sp
    adds r2, #0x28
    str r2, [sp, #0x64]
    mov r3, sp
    adds r3, #0x2c
    str r3, [sp, #0x68]
    mov r4, sp
    adds r4, #0x30
    str r4, [sp, #0x70]
    mov r7, sp
    adds r7, #0x34
    str r7, [sp, #0x74]
    mov r0, sp
    adds r0, #0x38
    str r0, [sp, #0x78]
    mov r1, sp
    adds r1, #0x10
    str r1, [sp, #0x5c]
    movs r7, #NEW_GAME_IDENTITY_VALUE_WIDTH
    movs r6, #NEW_GAME_IDENTITY_TILE_HEIGHT
    mov r4, sl
    adds r4, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
.L0800532E:
    add r0, sp, #0x20
    strh r7, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r2, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r2, r2, #2
#else
    ldr r2, .Lidentity_overseas_first_value_stride
#endif
    adds r4, r4, r2
    movs r3, #1
    add r8, r3
    mov r0, r8
    cmp r0, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .L0800532E
    movs r1, #0
    mov r8, r1
    ldr r7, .L080054A8
    add r7, sl
#if ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255
    movs r2, #((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4)
    lsls r2, r2, #4
#else
    ldr r2, .Lidentity_overseas_first_label1
#endif
    add r2, sl
    str r2, [sp, #0x54]
    ldr r3, .L080054AC
    add r3, sl
    str r3, [sp, #0x58]
    ldr r4, .L080054B0
    add r4, sl
    str r4, [sp, #0x6c]
    movs r6, #NEW_GAME_IDENTITY_LABEL_WIDTH
    movs r5, #NEW_GAME_IDENTITY_TILE_HEIGHT
    ldr r4, .L080054A8
    add r4, sl
.L08005372:
    add r0, sp, #0x24
    strh r6, [r0]
    mov r0, sb
    strh r5, [r0, #2]
    ldr r0, [sp, #0x24]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
#if ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255
    movs r1, #((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2)
    lsls r1, r1, #2
#else
    ldr r1, .Lidentity_overseas_first_label_stride
#endif
    adds r4, r4, r1
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .L08005372
    movs r4, #0
    mov r8, r4
    movs r6, #NEW_GAME_IDENTITY_VALUE_WIDTH
    movs r5, #NEW_GAME_IDENTITY_TILE_HEIGHT
    mov r4, sl
    adds r4, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
.L080053A0:
    mov r0, r8
    lsls r1, r0, #4
    add r1, sl
    ldr r2, .L080054B4
    adds r1, r1, r2
    add r0, sp, #0x28
    strh r6, [r0]
    ldr r3, [sp, #0x64]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x28]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r0, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r0, r0, #2
#else
    ldr r0, .Lidentity_overseas_first_value_stride
#endif
    adds r4, r4, r0
    movs r1, #1
    add r8, r1
    mov r2, r8
    cmp r2, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .L080053A0
    ldr r1, .L080054B8 @ =gText_NewGameIdentity_PlayerName
    movs r4, #NEW_GAME_IDENTITY_LABEL_WIDTH
    movs r5, #NEW_GAME_IDENTITY_TILE_HEIGHT
    add r0, sp, #0x2c
    strh r4, [r0]
    ldr r3, [sp, #0x68]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x2c]
    str r1, [sp]
    adds r1, r7, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054BC @ =gText_NewGameIdentity_PlayerBirthday
    add r0, sp, #0x30
    strh r4, [r0]
    ldr r7, [sp, #0x70]
    strh r5, [r7, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x54]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054C0 @ =gText_NewGameIdentity_FarmName
    add r0, sp, #0x34
    strh r4, [r0]
    ldr r0, [sp, #0x74]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    ldr r1, [sp, #0x58]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054C4 @ =gText_NewGameIdentity_DogName
    add r0, sp, #0x38
    strh r4, [r0]
    ldr r2, [sp, #0x78]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x38]
    str r1, [sp]
    ldr r1, [sp, #0x6c]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r3, #0
    mov r8, r3
    ldr r4, [sp, #0x5c]
    str r4, [sp, #0x4c]
    movs r5, #(MEM_VRAM >> 19)
    lsls r5, r5, #0x13
    str r5, [sp, #0x84]
    mov r7, sl
    adds r7, #NEW_GAME_IDENTITY_VALUE_TILES_OFFSET
    str r7, [sp, #0x88]
.L08005448:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x88]
    ldr r2, [sp, #0x84]
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_overseas_first_value_bytes
#endif
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L080054C8
    cmp r1, #0
    beq .L08005476
    adds r0, r1, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08005476:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
#if ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255
    movs r5, #((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4)
    lsls r5, r5, #2
    lsls r5, r5, #2
#else
    ldr r5, .Lidentity_overseas_first_value_span
#endif
    str r5, [sp, #0x60]
    b .L08005596
    .align 2, 0
#if !(((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255)
.Lidentity_overseas_first_label1: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_overseas_first_value_stride: .word (NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_overseas_first_label_stride: .word (NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
.Lidentity_overseas_first_value_bytes: .word (NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255)
.Lidentity_overseas_first_value_span: .word (NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
.L08005488: .word gUiSharedTiles
.L0800548C: .word (MEM_VRAM + 0x4B00)
.L08005490: .word gUiSharedTileByteCount
.L08005494: .word gUiSharedPalette
.L08005498: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.L0800549C: .word (BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.L080054A0: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)
@ Preserve the native mirrored VRAM destination; this is not BG screen block 24.
.L080054A4: .word (MEM_VRAM + 0xFFC000)
.L080054A8: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET)
.L080054AC: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + 2 * NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
.L080054B0: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + 3 * NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
.L080054B4: .word (NEW_GAME_IDENTITY_CORE_FIELDS_OFFSET)
.L080054B8: .word gText_NewGameIdentity_PlayerName
.L080054BC: .word gText_NewGameIdentity_PlayerBirthday
.L080054C0: .word gText_NewGameIdentity_FarmName
.L080054C4: .word gText_NewGameIdentity_DogName
.L080054C8:
    str r1, [sp, #0x8c]
    movs r0, #1
    str r0, [sp, #0x40]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x3c]
    add r1, sp, #0x40
    add r0, sp, #0x3c
    cmp r4, #1
    bhs .L080054E2
    adds r0, r1, #0
.L080054E2:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005500
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005504
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005504
.L08005500:
    movs r0, #0
    mov sb, r0
.L08005504:
    adds r5, r0, #0
    str r5, [sp, #0x90]
    ldr r2, [r6]
    adds r3, r5, #0
#if ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255
    movs r0, #((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4)
    lsls r0, r0, #2
    lsls r0, r0, #2
#else
    ldr r0, .Lidentity_overseas_middle_value_span
#endif
    str r0, [sp, #0x60]
    ldr r1, [sp, #0x8c]
    cmp r2, r1
    beq .L08005534
.L0800551A:
    cmp r3, #0
    beq .L0800552A
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800552A:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x8c]
    cmp r2, r0
    bne .L0800551A
.L08005534:
    adds r5, r3, #0
    ldr r0, [sp, #0x40]
    cmp r0, #1
    bne .L08005550
    cmp r5, #0
    beq .L0800554C
    adds r0, r5, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800554C:
    adds r5, #0x10
    b .L08005572
.L08005550:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08005570
.L08005558:
    cmp r2, #0
    beq .L08005568
    adds r0, r2, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005568:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005558
.L08005570:
    adds r5, r2, #0
.L08005572:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08005582
.L0800557C:
    adds r1, #0x10
    cmp r1, r2
    bne .L0800557C
.L08005582:
    cmp r0, #0
    beq .L0800558A
    bl free
.L0800558A:
    ldr r0, [sp, #0x90]
    add r0, sb
    ldr r7, [sp, #0x90]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08005596:
    ldr r0, [sp, #0x84]
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
    movs r1, #((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2)
    lsls r1, r1, #2
#else
    ldr r1, .Lidentity_overseas_middle_value_bytes
#endif
    adds r0, r0, r1
    str r0, [sp, #0x84]
    ldr r2, [sp, #0x88]
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_overseas_middle_value_stride
#endif
    adds r2, r2, r3
    str r2, [sp, #0x88]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bhi .L080055B6
    b .L08005448
.L080055B6:
    movs r7, #0
    mov r8, r7
    mov r0, sp
    adds r0, #0xc
    str r0, [sp, #0x50]
    movs r0, #(MEM_VRAM >> 19)
    lsls r0, r0, #0x13
    ldr r1, [sp, #0x60]
    adds r0, r1, r0
    str r0, [sp, #0x7c]
    ldr r2, .L08005608
    add r2, sl
    str r2, [sp, #0x80]
.L080055D0:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0xc
    ldr r1, [sp, #0x80]
    ldr r2, [sp, #0x7c]
#if ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_overseas_middle_label_bytes
#endif
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L0800560C
    cmp r1, #0
    beq .L080055FE
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.L080055FE:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L080056CE
    .align 2, 0
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_overseas_middle_value_stride: .word (NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
.Lidentity_overseas_middle_value_bytes: .word (NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255)
.Lidentity_overseas_middle_label_bytes: .word (NEW_GAME_IDENTITY_LABEL_TILE_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255)
.Lidentity_overseas_middle_value_span: .word (NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#endif
.L08005608: .word (NEW_GAME_IDENTITY_LABEL_TILES_OFFSET)
.L0800560C:
    str r1, [sp, #0x8c]
    movs r0, #1
    str r0, [sp, #0x48]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x44]
    add r1, sp, #0x48
    add r0, sp, #0x44
    cmp r4, #1
    bhs .L08005626
    adds r0, r1, #0
.L08005626:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005644
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005648
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005648
.L08005644:
    movs r0, #0
    mov sb, r0
.L08005648:
    adds r5, r0, #0
    str r5, [sp, #0x90]
    ldr r2, [r6]
    adds r3, r5, #0
    b .L08005666
.L08005652:
    cmp r3, #0
    beq .L08005662
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005662:
    adds r2, #0x10
    adds r3, #0x10
.L08005666:
    ldr r0, [sp, #0x8c]
    cmp r2, r0
    bne .L08005652
    adds r5, r3, #0
    ldr r0, [sp, #0x48]
    cmp r0, #1
    bne .L08005688
    cmp r5, #0
    beq .L08005684
    adds r0, r5, #0
    ldr r1, [sp, #0x50]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08005684:
    adds r5, #0x10
    b .L080056AA
.L08005688:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L080056A8
.L08005690:
    cmp r2, #0
    beq .L080056A0
    adds r0, r2, #0
    ldr r1, [sp, #0x50]
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080056A0:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005690
.L080056A8:
    adds r5, r2, #0
.L080056AA:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L080056BA
.L080056B4:
    adds r1, #0x10
    cmp r1, r2
    bne .L080056B4
.L080056BA:
    cmp r0, #0
    beq .L080056C2
    bl free
.L080056C2:
    ldr r0, [sp, #0x90]
    add r0, sb
    ldr r7, [sp, #0x90]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L080056CE:
    ldr r0, [sp, #0x7c]
#if ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255
    movs r1, #((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2)
    lsls r1, r1, #2
#else
    ldr r1, .Lidentity_overseas_last_label_bytes
#endif
    adds r0, r0, r1
    str r0, [sp, #0x7c]
    ldr r2, [sp, #0x80]
#if ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255
    movs r3, #((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2)
    lsls r3, r3, #2
#else
    ldr r3, .Lidentity_overseas_last_label_stride
#endif
    adds r2, r2, r3
    str r2, [sp, #0x80]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bhi .L080056EE
    b .L080055D0
.L080056EE:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L080057E8 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE)
    movs r2, #(BG_SCREEN_SIZE >> 4)
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r7, #0
    mov r8, r7
    @ Blank tile from the fifth (ASCII space) PlayerName label glyph.
    @ Keep that label space: the map reuses this empty tile.
    movs r1, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT + 4)
.L08005704:
    movs r5, #0
    mov r2, r8
    lsls r0, r2, #6
    adds r0, r0, r4
.L0800570C:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r5, #0x1d
    bls .L0800570C
    movs r3, #1
    add r8, r3
    mov r5, r8
    cmp r5, #0x13
    bls .L08005704
    movs r5, #2
    ldr r6, .L080057EC @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x80)
.L08005724:
    movs r7, #0
    mov r8, r7
    lsls r1, r5, #1
    adds r4, r5, #0
    adds r4, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT + NEW_GAME_IDENTITY_LABEL_WIDTH - 2)
    adds r3, r5, #0
    adds r3, #(NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT - 2)
    ldr r0, .L080057F0 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x40)
    adds r2, r1, r0
.L08005736:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #(NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r3, #(NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r2, #(3 * 32 * 2)
    adds r1, #(3 * 32 * 2)
    movs r7, #1
    add r8, r7
    mov r0, r8
    cmp r0, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .L08005736
    adds r5, #1
    cmp r5, #(2 + NEW_GAME_IDENTITY_LABEL_WIDTH - 1)
    bls .L08005724
    movs r5, #0x10
    ldr r1, .L080057F4 @ =0x0000FFF0
    adds r7, r1, #0
    ldr r2, .L080057EC @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x80)
    mov sb, r2
.L0800575E:
    movs r3, #0
    mov r8, r3
    lsls r1, r5, #1
    adds r6, r5, #1
    adds r0, r5, #0
    adds r0, #NEW_GAME_IDENTITY_VALUE_WIDTH
    adds r4, r0, r7
    adds r3, r5, r7
    ldr r5, .L080057F0 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x40)
    adds r2, r1, r5
.L08005772:
    strh r3, [r2]
    mov r5, sb
    adds r0, r1, r5
    strh r4, [r0]
    adds r4, #(NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r3, #(NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT)
    adds r2, #(3 * 32 * 2)
    adds r1, #(3 * 32 * 2)
    movs r0, #1
    add r8, r0
    mov r5, r8
    cmp r5, #(NEW_GAME_IDENTITY_FIELD_COUNT - 1)
    bls .L08005772
    adds r5, r6, #0
    cmp r5, #(16 + NEW_GAME_IDENTITY_VALUE_WIDTH - 1)
    bls .L0800575E
    ldr r0, .L080057F8
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
    ldr r1, .L080057FC
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    add sp, #0x94
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
#if !(((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255)
.Lidentity_overseas_last_label_stride: .word (NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES)
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255)
.Lidentity_overseas_last_label_bytes: .word (NEW_GAME_IDENTITY_LABEL_TILE_BYTES)
#endif
.L080057E8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)
.L080057EC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 2 * 32 * 2)
.L080057F0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 32 * 2)
.L080057F4: .word (0x10000 - 16)
.L080057F8: .word (NEW_GAME_IDENTITY_CORE_UI_OFFSET)
.L080057FC: .word (NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET)

#endif

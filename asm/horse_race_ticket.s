    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"

    .syntax unified
    .thumb
    .text

    thumb_func_start RenderHorseRaceTicketPurchaseScreen
RenderHorseRaceTicketPurchaseScreen:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L0805A090 @ =0xFFFFF490
    add sp, r4
    mov r8, r0
    ldr r0, .L0805A094 @ =0x00000B54
    add r0, sp
    str r1, [r0]
    cmp r1, #0
    bne .L0805A0AC
    movs r1, #0xb8
    lsls r1, r1, #1
    add r1, r8
    add r0, sp, #0xc
    movs r2, #0
    bl GetGroupData__C22IndexedResourceArchiveUi
    add r5, sp, #0x1c
    ldr r4, [sp, #0x1c]
    movs r0, #0xc9
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    lsls r0, r0, #5
    ldr r6, .L0805A098 @ =OBJ_PALETTE
    adds r1, r0, r6
    ldr r0, [sp, #0x1c]
    movs r2, #0
    cmp r0, #0
    beq .L0805A028
    ldrh r2, [r5, #4]
.L0805A028:
    adds r0, r4, #0
    bl CopyHardwareDma3
    add r4, sp, #0x14
    ldr r5, [sp, #0x14]
    movs r0, #0xc8
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    lsls r0, r0, #5
    ldr r2, .L0805A09C @ =OBJ_VRAM0
    adds r1, r0, r2
    ldr r0, [sp, #0x14]
    movs r2, #0
    cmp r0, #0
    beq .L0805A04E
    ldrh r2, [r4, #4]
.L0805A04E:
    adds r0, r5, #0
    bl CopyHardwareDma3
    ldr r4, .L0805A0A0 @ =gFarmStatusCreatureIcon11Tiles
    movs r0, #0xc2
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r3, .L0805A0A4
    adds r1, r1, r3
    adds r0, r4, #0
    movs r2, #0x80
    bl CopyHardwareDma3
    ldr r4, .L0805A0A8 @ =gFarmStatusCreatureIcon11Palette
    movs r0, #0xc4
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r1, r0, #0
    lsls r1, r1, #5
    adds r1, r1, r6
    adds r0, r4, #0
    movs r2, #0x20
    bl CopyHardwareDma3
    b .L0805A0E8
    .align 2, 0
.L0805A090: .word 0xFFFFF490
.L0805A094: .word 0x00000B54
.L0805A098: .word OBJ_PALETTE
.L0805A09C: .word OBJ_VRAM0
.L0805A0A0: .word gFarmStatusCreatureIcon11Tiles
.L0805A0A4:
    .ifdef REGION_JP
    .word OBJ_VRAM0 + 0xA00
    .else
    .word OBJ_VRAM0 + 0x600
    .endif
.L0805A0A8: .word gFarmStatusCreatureIcon11Palette
.L0805A0AC:
    ldr r4, .L0805A18C @ =gAnimalFestivalIcon01Tiles
    movs r0, #0xc2
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r7, .L0805A190
    adds r1, r1, r7
    adds r0, r4, #0
    movs r2, #0x80
    bl CopyHardwareDma3
    ldr r4, .L0805A194 @ =gAnimalFestivalIcon01Palette
    movs r0, #0xc4
    lsls r0, r0, #3
    add r0, r8
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r0, .L0805A198 @ =OBJ_PALETTE
    adds r1, r1, r0
    adds r0, r4, #0
    movs r2, #0x20
    bl CopyHardwareDma3
.L0805A0E8:
    ldr r4, .L0805A19C
    add r4, r8
    ldr r1, .L0805A1A0 @ =0x00000B34
    add r1, sp
    ldr r2, .L0805A1A4 @ =0x00000B6C
    add r2, sp
    str r1, [r2]
    mov r3, sp
    adds r3, #0x30
    ldr r7, .L0805A1A8 @ =0x00000B68
    add r7, sp
    str r3, [r7]
    movs r0, #0xb4
    lsls r0, r0, #4
    add r0, sp
    ldr r1, .L0805A1AC @ =0x00000B5C
    add r1, sp
    str r0, [r1]
    ldr r2, .L0805A1B0 @ =0x00000B44
    add r2, sp
    movs r3, #0xb6
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r7, #0xcd
    lsls r7, r7, #2
    add r7, sp
    ldr r0, .L0805A1B4 @ =0x00000B58
    add r0, sp
    str r7, [r0]
    ldr r1, .L0805A1B8 @ =0x00000B48
    add r1, sp
    ldr r2, .L0805A1BC @ =0x00000B64
    add r2, sp
    str r1, [r2]
    movs r3, #2
    mov sl, r3
    ldr r7, .L0805A1C0 @ =MEM_VRAM + 0x2800
    mov sb, r7
    ldr r6, .L0805A1C4 @ =0x00000B38
    add r6, sp
    ldr r5, .L0805A1C8 @ =0x00000B3C
    add r5, sp
    movs r7, #3
.L0805A140:
    ldr r0, .L0805A1A0 @ =0x00000B34
    add r0, sp
    movs r1, #0xc
    strh r1, [r0]
    mov r3, sl
    ldr r2, .L0805A1A4 @ =0x00000B6C
    add r2, sp
    ldr r2, [r2]
    strh r3, [r2, #2]
    ldr r0, [r0]
    add r1, sp, #0x30
    movs r2, #0
    bl Clear2DGfxBuffer
    ldrh r0, [r4, #0x20]
    cmp r0, #0x27
    bhi .L0805A1D0
    adds r1, r0, #0
    movs r0, #0xd
    muls r1, r0, r1
    ldr r0, .L0805A1CC @ =gText_AnimalFestival_LivestockContestantNames
    adds r1, r1, r0
    movs r3, #0xc
    strh r3, [r6]
    mov r0, sl
    strh r0, [r6, #2]
    ldr r0, [r6]
    str r1, [sp]
    movs r1, #0
    str r1, [sp, #4]
    movs r2, #1
    str r2, [sp, #8]
    add r1, sp, #0x30
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
    b .L0805A1F8
    .align 2, 0
.L0805A18C: .word gAnimalFestivalIcon01Tiles
.L0805A190:
    .ifdef REGION_JP
    .word OBJ_VRAM0 + 0xA00
    .else
    .word OBJ_VRAM0 + 0x600
    .endif
.L0805A194: .word gAnimalFestivalIcon01Palette
.L0805A198: .word OBJ_PALETTE
.L0805A19C:
    .ifdef REGION_JP
    .word 0x110C
    .else
    .word 0x142C
    .endif
.L0805A1A0: .word 0x00000B34
.L0805A1A4: .word 0x00000B6C
.L0805A1A8: .word 0x00000B68
.L0805A1AC: .word 0x00000B5C
.L0805A1B0: .word 0x00000B44
.L0805A1B4: .word 0x00000B58
.L0805A1B8: .word 0x00000B48
.L0805A1BC: .word 0x00000B64
.L0805A1C0: .word MEM_VRAM + 0x2800
.L0805A1C4: .word 0x00000B38
.L0805A1C8: .word 0x00000B3C
.L0805A1CC: .word gText_AnimalFestival_LivestockContestantNames
.L0805A1D0:
    ldr r0, .L0805A2B8
    add r0, r8
    ldr r0, [r0]
    bl GetName__C6Animal
    movs r3, #0xc
    strh r3, [r5]
    mov r1, sl
    strh r1, [r5, #2]
    ldr r1, [r5]
    str r0, [sp]
    movs r2, #0
    str r2, [sp, #4]
    movs r3, #1
    str r3, [sp, #8]
    adds r0, r1, #0
    add r1, sp, #0x30
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
.L0805A1F8:
    ldr r1, .L0805A2BC @ =0x00000B68
    add r1, sp
    ldr r0, [r1]
    mov r1, sb
    movs r2, #0xc0
    lsls r2, r2, #2
    bl CopyHardwareDma3
    movs r2, #0xc0
    lsls r2, r2, #2
    add sb, r2
    subs r7, #1
    adds r4, #0x2c
    cmp r7, #0
    bge .L0805A140
    movs r4, #0x20
    movs r5, #2
    movs r7, #0
    movs r0, #0xb4
    lsls r0, r0, #4
    add r0, sp
    strh r4, [r0]
    ldr r3, .L0805A2C0 @ =0x00000B5C
    add r3, sp
    ldr r3, [r3]
    strh r5, [r3, #2]
    ldr r0, [r0]
    add r1, sp, #0x334
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .L0805A2C4 @ =gText_HorseRace_TicketPurchaseTitle
    movs r6, #1
    ldr r0, .L0805A2C8 @ =0x00000B44
    add r0, sp
    strh r4, [r0]
    movs r2, #0xb6
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    strh r5, [r2, #2]
    ldr r0, [r0]
    str r1, [sp]
    str r7, [sp, #4]
    str r6, [sp, #8]
    add r1, sp, #0x334
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
    ldr r1, .L0805A2CC @ =MEM_VRAM + 0x4000
    movs r2, #0x80
    lsls r2, r2, #4
    ldr r3, .L0805A2D0 @ =0x00000B58
    add r3, sp
    ldr r0, [r3]
    bl CopyHardwareDma3
    ldr r0, .L0805A2D4 @ =0x00000B48
    add r0, sp
    strh r4, [r0]
    ldr r1, .L0805A2D8 @ =0x00000B64
    add r1, sp
    ldr r1, [r1]
    strh r5, [r1, #2]
    ldr r0, [r0]
    ldr r2, .L0805A2D0 @ =0x00000B58
    add r2, sp
    ldr r1, [r2]
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r3, .L0805A2DC @ =0x00000B54
    add r3, sp
    ldr r3, [r3]
    cmp r3, #0
    bne .L0805A2E8
    ldr r2, .L0805A2E0 @ =gText_HorseRace_TicketPurchaseConfirm
    ldr r1, .L0805A2E4 @ =0x00000B4C
    add r1, sp
    ldr r0, .L0805A2E4 @ =0x00000B4C
    add r0, sp
    strh r4, [r0]
    strh r5, [r1, #2]
    ldr r0, [r0]
    str r2, [sp]
    str r7, [sp, #4]
    str r6, [sp, #8]
    ldr r7, .L0805A2D0 @ =0x00000B58
    add r7, sp
    ldr r1, [r7]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
    b .L0805A310
    .align 2, 0
.L0805A2B8:
    .ifdef REGION_JP
    .word 0x11BC
    .else
    .word 0x14DC
    .endif
.L0805A2BC: .word 0x00000B68
.L0805A2C0: .word 0x00000B5C
.L0805A2C4: .word gText_HorseRace_TicketPurchaseTitle
.L0805A2C8: .word 0x00000B44
.L0805A2CC: .word MEM_VRAM + 0x4000
.L0805A2D0: .word 0x00000B58
.L0805A2D4: .word 0x00000B48
.L0805A2D8: .word 0x00000B64
.L0805A2DC: .word 0x00000B54
.L0805A2E0: .word gText_HorseRace_TicketPurchaseConfirm
.L0805A2E4: .word 0x00000B4C
.L0805A2E8:
    ldr r2, .L0805A3D8 @ =gText_HorseRace_TicketPurchaseMedalsToWin
    movs r1, #0xb5
    lsls r1, r1, #4
    add r1, sp
    movs r0, #0xb5
    lsls r0, r0, #4
    add r0, sp
    strh r4, [r0]
    strh r5, [r1, #2]
    ldr r0, [r0]
    str r2, [sp]
    str r7, [sp, #4]
    str r6, [sp, #8]
    ldr r2, .L0805A3DC @ =0x00000B58
    add r2, sp
    ldr r1, [r2]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
.L0805A310:
    ldr r1, .L0805A3E0 @ =MEM_VRAM + 0x4800
    movs r4, #0x80
    lsls r4, r4, #4
    ldr r3, .L0805A3DC @ =0x00000B58
    add r3, sp
    ldr r0, [r3]
    adds r2, r4, #0
    bl CopyHardwareDma3
    movs r0, #1
    rsbs r0, r0, #0
    ldr r1, .L0805A3E4
    add r1, r8
    adds r2, r4, #0
    bl FillHardwareDma3
    movs r5, #0x85
    lsls r5, r5, #6
    movs r1, #0
    ldr r7, .L0805A3E8
    add r7, r8
    mov ip, r7
.L0805A33C:
    movs r4, #0
    lsls r0, r1, #1
    adds r6, r5, #0
    adds r6, #0x18
    adds r1, #1
    mov sb, r1
    adds r1, r0, #6
    lsls r1, r1, #6
    adds r0, #7
    lsls r0, r0, #6
    adds r3, r5, #0
    adds r3, #0xc
    mov r7, ip
    adds r2, r0, r7
    add r1, ip
.L0805A35A:
    adds r0, r5, r4
    strh r0, [r1]
    strh r3, [r2]
    adds r3, #1
    adds r2, #2
    adds r1, #2
    adds r4, #1
    cmp r4, #0xb
    ble .L0805A35A
    lsls r0, r6, #0x10
    lsrs r5, r0, #0x10
    mov r1, sb
    cmp r1, #3
    ble .L0805A33C
    movs r4, #0
    ldr r5, .L0805A3E4
    add r5, r8
    movs r0, #0x88
    lsls r0, r0, #6
    adds r6, r0, #0
.L0805A382:
    adds r3, r4, #0
    cmp r4, #0
    bge .L0805A38A
    adds r3, #0x1f
.L0805A38A:
    asrs r3, r3, #5
    lsls r2, r3, #5
    subs r2, r4, r2
    lsls r2, r2, #1
    adds r0, r3, #4
    lsls r0, r0, #6
    adds r0, r2, r0
    adds r0, r5, r0
    adds r1, r4, r6
    strh r1, [r0]
    adds r3, #0xf
    lsls r3, r3, #6
    adds r2, r2, r3
    adds r2, r5, r2
    movs r1, #0x89
    lsls r1, r1, #6
    adds r0, r4, r1
    strh r0, [r2]
    adds r4, #1
    cmp r4, #0x3f
    ble .L0805A382
    ldr r0, .L0805A3E4
    add r0, r8
    ldr r1, .L0805A3EC @ =MEM_VRAM + 0xF000
    movs r2, #0x80
    lsls r2, r2, #4
    bl CopyHardwareDma3
    movs r3, #0xb7
    lsls r3, r3, #4
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0805A3D8: .word gText_HorseRace_TicketPurchaseMedalsToWin
.L0805A3DC: .word 0x00000B58
.L0805A3E0: .word MEM_VRAM + 0x4800
    .ifdef REGION_JP
.L0805A3E4: .word 0x8CA
.L0805A3E8: .word 0x8D2
    .else
.L0805A3E4: .word 0xBEA
.L0805A3E8: .word 0xBF2
    .endif
.L0805A3EC: .word MEM_VRAM + 0xF000

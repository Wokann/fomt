    .include "asm/macro.inc"
    .syntax unified
    .thumb

    .ifdef REGION_JP
    .section .text.new_game_identity_core_constructor
    .align 2, 0

    .global InitializeNewGameIdentityCore
    .thumb_func
InitializeNewGameIdentityCore:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov r8, r0
    adds r6, r1, #0
    adds r7, r2, #0
    str r3, [sp, #0x24]
    bl __17HardwareBootstrap
    ldr r0, .Ljp_0800510C
    mov r1, r8
    str r0, [r1, #4]
    movs r0, #7
    add r5, sp, #0x10
    add r1, sp, #0x14
    mov sb, r1
    movs r1, #1
    rsbs r1, r1, #0
.Ljp_08004F3E:
    subs r0, #1
    cmp r0, r1
    bne .Ljp_08004F3E
    ldr r1, .Ljp_08005110
    add r1, r8
    movs r0, #2
    str r0, [r1]
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    adds r0, r5, #0
    bl __16HardwareResource
    movs r0, #0
    str r0, [sp]
    add r0, sp, #0xc
    str r0, [sp, #4]
    str r5, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1c
    movs r3, #4
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    ldr r1, .Ljp_08005114
    add r1, r8
    str r0, [r1]
    adds r0, r5, #0
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
    ldr r4, .Ljp_08005118
    add r4, r8
    movs r0, #0xc8
    bl func_08008D3C
    str r0, [r4]
    ldr r0, .Ljp_0800511C
    add r0, r8
    movs r1, #3
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.Ljp_08004FA4:
    strb r3, [r0]
    adds r0, #0x10
    subs r1, #1
    cmp r1, r2
    bne .Ljp_08004FA4
    ldr r0, .Ljp_08005120
    add r0, r8
    movs r1, #0
    mov sl, r1
    mov r1, sl
    strb r1, [r0]
    ldr r5, .Ljp_0800511C
    add r5, r8
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_08004FCC
    movs r4, #0xf
.Ljp_08004FCC:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    mov r1, sl
    strb r1, [r0]
    lsls r0, r7, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    mov r1, sb
    movs r2, #2
    bl FormatFullWidthDecimal
    lsls r0, r7, #0x1e
    lsrs r0, r0, #0x1e
    bl func_0800E2E4
    mov sb, r0
    ldr r6, .Ljp_08005124
    add r6, r8
    mov r4, sb
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08005028
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08005018
    adds r4, r5, #0
.Ljp_08005018:
    adds r0, r7, #0
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    adds r0, r7, r4
    mov r1, sl
    strb r1, [r0]
.Ljp_08005028:
    ldr r0, .Ljp_08005128
    mov sb, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_0800505A
    mov r0, sb
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_0800504A
    adds r4, r5, #0
.Ljp_0800504A:
    adds r0, r7, #0
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_0800505A:
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08005088
    add r0, sp, #0x14
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08005078
    adds r4, r5, #0
.Ljp_08005078:
    adds r0, r7, #0
    add r1, sp, #0x14
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_08005088:
    ldr r7, .Ljp_0800512C
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_080050B8
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_080050A8
    adds r4, r5, #0
.Ljp_080050A8:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_080050B8:
    ldr r5, .Ljp_08005130
    add r5, r8
    ldr r0, [sp, #0x24]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_080050CA
    movs r4, #0xf
.Ljp_080050CA:
    adds r0, r5, #0
    ldr r1, [sp, #0x24]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    movs r6, #0
    strb r6, [r0]
    ldr r5, .Ljp_08005134
    add r5, r8
    ldr r0, [sp, #0x48]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_080050EC
    movs r4, #0xf
.Ljp_080050EC:
    adds r0, r5, #0
    ldr r1, [sp, #0x48]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    strb r6, [r0]
    mov r0, r8
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Ljp_0800510C: .4byte gNewGameIdentityCoreVTable
.Ljp_08005110: .4byte 0x00001828
.Ljp_08005114: .4byte 0x0000182C
.Ljp_08005118: .4byte 0x00001830
.Ljp_0800511C: .4byte 0x00001834
.Ljp_08005120: .4byte 0x00001876
.Ljp_08005124: .4byte 0x00001844
.Ljp_08005128: .4byte gText_NewGameIdentity_BirthMonthSuffix
.Ljp_0800512C: .4byte gText_NewGameIdentity_BirthDaySuffix
.Ljp_08005130: .4byte 0x00001854
.Ljp_08005134: .4byte 0x00001864

    .section .text.new_game_identity_screen
    .align 2, 0

    .global InitializeNewGameIdentityScreen
    .thumb_func
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
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x20
    bl CopyHardwareDma3
    mov r0, sl
    bl GetHardwareDisplayState
    add r1, sp, #0xc
    movs r3, #0xba
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
    movs r0, #0xc
    mov r8, r0
    movs r6, #2
    mov r4, sl
    adds r4, #0xc
.Ljp_08005398:
    add r0, sp, #0x20
    mov r1, r8
    strh r1, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r2, #0xc1
    lsls r2, r2, #2
    adds r4, r4, r2
    adds r7, #1
    cmp r7, #7
    bls .Ljp_08005398
    movs r7, #0
    ldr r3, .Ljp_080054D0
    add r3, sl
    mov r8, r3
    movs r4, #0xf2
    lsls r4, r4, #4
    add r4, sl
    str r4, [sp, #0x48]
    ldr r5, .Ljp_080054D4
    add r5, sl
    str r5, [sp, #0x5c]
    ldr r0, .Ljp_080054D8
    add r0, sl
    str r0, [sp, #0x58]
    movs r6, #0xc
    movs r5, #2
    mov r4, sl
    adds r4, #0xc
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
    movs r0, #0xc1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_080053DA
    ldr r1, .Ljp_080054E0
    movs r4, #0xc
    movs r5, #2
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
    movs r4, #0xc0
    lsls r4, r4, #0x13
    str r4, [sp, #0x64]
    mov r5, sl
    adds r5, #0xc
    str r5, [sp, #0x68]
.Ljp_0800547A:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x68]
    ldr r2, [sp, #0x64]
    movs r3, #0xc0
    lsls r3, r3, #2
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
.Ljp_080054B0:
    .4byte gUiSharedTiles
.Ljp_080054B4:
    .4byte 0x06004B00
.Ljp_080054B8:
    .4byte gUiSharedTileByteCount
.Ljp_080054BC:
    .4byte gUiSharedPalette
.Ljp_080054C0:
    .4byte 0x00001841
.Ljp_080054C4:
    .4byte 0x00001F01
.Ljp_080054C8:
    .4byte 0x0600F800
.Ljp_080054CC:
    .4byte 0x06FFC000
.Ljp_080054D0:
    .4byte 0x00000C1C
.Ljp_080054D4:
    .4byte 0x00001224
.Ljp_080054D8:
    .4byte 0x00001528
.Ljp_080054DC:
    .4byte 0x00001834
.Ljp_080054E0:
    .4byte gText_NewGameIdentity_PlayerName
.Ljp_080054E4:
    .4byte gText_NewGameIdentity_PlayerBirthday
.Ljp_080054E8:
    .4byte gText_NewGameIdentity_FarmName
.Ljp_080054EC:
    .4byte gText_NewGameIdentity_DogName
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
    movs r3, #0xc0
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x64]
    ldr r4, [sp, #0x68]
    movs r5, #0xc1
    lsls r5, r5, #2
    adds r4, r4, r5
    str r4, [sp, #0x68]
    adds r7, #1
    cmp r7, #7
    bhi .Ljp_080055D6
    b .Ljp_0800547A
.Ljp_080055D6:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .Ljp_080056BC
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r7, #0
    movs r1, #0xaa
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
    adds r4, #0x6a
    adds r3, r5, #0
    adds r3, #0x5e
    ldr r0, .Ljp_080056C4
    adds r2, r1, r0
.Ljp_08005614:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_08005614
    adds r5, #1
    cmp r5, #0xd
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
    adds r0, #0xc
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
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_0800564C
    adds r5, r6, #0
    cmp r5, #0x1b
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
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x70
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Ljp_080056BC:
    .4byte 0x0600C000
.Ljp_080056C0:
    .4byte 0x0600C080
.Ljp_080056C4:
    .4byte 0x0600C040
.Ljp_080056C8:
    .4byte 0x0000FFF0
.Ljp_080056CC:
    .4byte 0x0000182C
.Ljp_080056D0:
    .4byte 0x00001830

    .else
    .section .text.new_game_identity_core_constructor
    .align 2, 0

    thumb_func_start InitializeNewGameIdentityCore
InitializeNewGameIdentityCore: @ US 0x08004EFC; body remains native.
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    adds r7, r0, #0
    adds r6, r1, #0
    mov r8, r2
    str r3, [sp, #0x24]
    bl __17HardwareBootstrap
    ldr r0, .L080050A4 @ =gNewGameIdentityCoreVTable
    str r0, [r7, #4]
    movs r0, #3
    add r5, sp, #0x10
    add r1, sp, #0x14
    mov sb, r1
    movs r1, #1
    rsbs r1, r1, #0
.L08004F24:
    subs r0, #1
    cmp r0, r1
    bne .L08004F24
    movs r0, #3
    movs r1, #1
    rsbs r1, r1, #0
.L08004F30:
    subs r0, #1
    cmp r0, r1
    bne .L08004F30
    ldr r2, .L080050A8 @ =0x00001A28
    adds r1, r7, r2
    movs r0, #2
    str r0, [r1]
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    adds r0, r5, #0
    bl __16HardwareResource
    movs r0, #0
    str r0, [sp]
    add r0, sp, #0xc
    str r0, [sp, #4]
    str r5, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1c
    movs r3, #4
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    ldr r2, .L080050AC @ =0x00001A2C
    adds r1, r7, r2
    str r0, [r1]
    adds r0, r5, #0
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
    ldr r0, .L080050B0 @ =0x00001A30
    adds r4, r7, r0
    movs r0, #0xc8
    bl func_08008D3C
    str r0, [r4]
    ldr r1, .L080050B4 @ =0x00001A34
    adds r0, r7, r1
    movs r1, #3
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L08004F96:
    strb r3, [r0]
    adds r0, #0x10
    subs r1, #1
    cmp r1, r2
    bne .L08004F96
    ldr r2, .L080050B8 @ =0x00001A76
    adds r0, r7, r2
    movs r1, #0
    mov sl, r1
    mov r2, sl
    strb r2, [r0]
    ldr r0, .L080050B4 @ =0x00001A34
    adds r5, r7, r0
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08004FBE
    movs r4, #0xf
.L08004FBE:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    mov r1, sl
    strb r1, [r0]
    mov r2, r8
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    mov r1, sb
    movs r2, #2
    bl FormatSignedDecimal
    mov r1, r8
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    bl func_0800E2E4
    mov sb, r0
    ldr r2, .L080050BC @ =0x00001A44
    adds r6, r7, r2
    mov r4, sb
    adds r0, r6, #0
    bl strlen
    adds r1, r6, r0
    mov r8, r1
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .L08005022
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08005010
    adds r4, r5, #0
.L08005010:
    mov r0, r8
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    mov r2, r8
    adds r0, r2, r4
    mov r1, sl
    strb r1, [r0]
.L08005022:
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .L08005050
    add r0, sp, #0x14
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08005040
    adds r4, r5, #0
.L08005040:
    adds r0, r6, #0
    add r1, sp, #0x14
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L08005050:
    ldr r2, .L080050C0 @ =0x00001A54
    adds r5, r7, r2
    ldr r0, [sp, #0x24]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08005062
    movs r4, #0xf
.L08005062:
    adds r0, r5, #0
    ldr r1, [sp, #0x24]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    movs r6, #0
    strb r6, [r0]
    ldr r0, .L080050C4 @ =0x00001A64
    adds r5, r7, r0
    ldr r0, [sp, #0x48]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08005084
    movs r4, #0xf
.L08005084:
    adds r0, r5, #0
    ldr r1, [sp, #0x48]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    strb r6, [r0]
    adds r0, r7, #0
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080050A4: .4byte gNewGameIdentityCoreVTable
.L080050A8: .4byte 0x00001A28
.L080050AC: .4byte 0x00001A2C
.L080050B0: .4byte 0x00001A30
.L080050B4: .4byte 0x00001A34
.L080050B8: .4byte 0x00001A76
.L080050BC: .4byte 0x00001A44
.L080050C0: .4byte 0x00001A54
.L080050C4: .4byte 0x00001A64

    .section .text.new_game_identity_screen
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
    ldr r1, .L0800548C @ =0x06004B00
    ldr r2, .L08005490 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L08005494 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x20
    bl CopyHardwareDma3
    mov r0, sl
    bl GetHardwareDisplayState
    add r1, sp, #0xc
    movs r3, #0xba
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r5, .L08005498 @ =0x00001841
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    ldr r7, .L0800549C @ =0x00001F01
    adds r1, r7, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .L080054A0 @ =0x0600F800
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
    ldr r1, .L080054A4 @ =0x06FFC000
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
    movs r7, #0xc
    movs r6, #2
    mov r4, sl
    adds r4, #0xc
.L0800532E:
    add r0, sp, #0x20
    strh r7, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r2, #0xc1
    lsls r2, r2, #2
    adds r4, r4, r2
    movs r3, #1
    add r8, r3
    mov r0, r8
    cmp r0, #3
    bls .L0800532E
    movs r1, #0
    mov r8, r1
    ldr r7, .L080054A8 @ =0x00000C1C
    add r7, sl
    movs r2, #0xfa
    lsls r2, r2, #4
    add r2, sl
    str r2, [sp, #0x54]
    ldr r3, .L080054AC @ =0x00001324
    add r3, sl
    str r3, [sp, #0x58]
    ldr r4, .L080054B0 @ =0x000016A8
    add r4, sl
    str r4, [sp, #0x6c]
    movs r6, #0xe
    movs r5, #2
    ldr r4, .L080054A8 @ =0x00000C1C
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
    movs r1, #0xe1
    lsls r1, r1, #2
    adds r4, r4, r1
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #3
    bls .L08005372
    movs r4, #0
    mov r8, r4
    movs r6, #0xc
    movs r5, #2
    mov r4, sl
    adds r4, #0xc
.L080053A0:
    mov r0, r8
    lsls r1, r0, #4
    add r1, sl
    ldr r2, .L080054B4 @ =0x00001A34
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
    movs r0, #0xc1
    lsls r0, r0, #2
    adds r4, r4, r0
    movs r1, #1
    add r8, r1
    mov r2, r8
    cmp r2, #3
    bls .L080053A0
    ldr r1, .L080054B8 @ =gText_NewGameIdentity_PlayerName
    movs r4, #0xe
    movs r5, #2
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
    movs r5, #0xc0
    lsls r5, r5, #0x13
    str r5, [sp, #0x84]
    mov r7, sl
    adds r7, #0xc
    str r7, [sp, #0x88]
.L08005448:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x88]
    ldr r2, [sp, #0x84]
    movs r3, #0xc0
    lsls r3, r3, #2
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
    movs r5, #0xc0
    lsls r5, r5, #2
    lsls r5, r5, #2
    str r5, [sp, #0x60]
    b .L08005596
    .align 2, 0
.L08005488: .4byte gUiSharedTiles
.L0800548C: .4byte 0x06004B00
.L08005490: .4byte gUiSharedTileByteCount
.L08005494: .4byte gUiSharedPalette
.L08005498: .4byte 0x00001841
.L0800549C: .4byte 0x00001F01
.L080054A0: .4byte 0x0600F800
.L080054A4: .4byte 0x06FFC000
.L080054A8: .4byte 0x00000C1C
.L080054AC: .4byte 0x00001324
.L080054B0: .4byte 0x000016A8
.L080054B4: .4byte 0x00001A34
.L080054B8: .4byte gText_NewGameIdentity_PlayerName
.L080054BC: .4byte gText_NewGameIdentity_PlayerBirthday
.L080054C0: .4byte gText_NewGameIdentity_FarmName
.L080054C4: .4byte gText_NewGameIdentity_DogName
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
    movs r0, #0xc0
    lsls r0, r0, #2
    lsls r0, r0, #2
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
    movs r1, #0xc0
    lsls r1, r1, #2
    adds r0, r0, r1
    str r0, [sp, #0x84]
    ldr r2, [sp, #0x88]
    movs r3, #0xc1
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x88]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #3
    bhi .L080055B6
    b .L08005448
.L080055B6:
    movs r7, #0
    mov r8, r7
    mov r0, sp
    adds r0, #0xc
    str r0, [sp, #0x50]
    movs r0, #0xc0
    lsls r0, r0, #0x13
    ldr r1, [sp, #0x60]
    adds r0, r1, r0
    str r0, [sp, #0x7c]
    ldr r2, .L08005608 @ =0x00000C1C
    add r2, sl
    str r2, [sp, #0x80]
.L080055D0:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #0xc
    ldr r1, [sp, #0x80]
    ldr r2, [sp, #0x7c]
    movs r3, #0xe0
    lsls r3, r3, #2
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
.L08005608: .4byte 0x00000C1C
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
    movs r1, #0xe0
    lsls r1, r1, #2
    adds r0, r0, r1
    str r0, [sp, #0x7c]
    ldr r2, [sp, #0x80]
    movs r3, #0xe1
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x80]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #3
    bhi .L080056EE
    b .L080055D0
.L080056EE:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L080057E8 @ =0x0600C000
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r7, #0
    mov r8, r7
    movs r1, #0x64
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
    ldr r6, .L080057EC @ =0x0600C080
.L08005724:
    movs r7, #0
    mov r8, r7
    lsls r1, r5, #1
    adds r4, r5, #0
    adds r4, #0x6c
    adds r3, r5, #0
    adds r3, #0x5e
    ldr r0, .L080057F0 @ =0x0600C040
    adds r2, r1, r0
.L08005736:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #0x1c
    adds r3, #0x1c
    adds r2, #0xc0
    adds r1, #0xc0
    movs r7, #1
    add r8, r7
    mov r0, r8
    cmp r0, #3
    bls .L08005736
    adds r5, #1
    cmp r5, #0xf
    bls .L08005724
    movs r5, #0x10
    ldr r1, .L080057F4 @ =0x0000FFF0
    adds r7, r1, #0
    ldr r2, .L080057EC @ =0x0600C080
    mov sb, r2
.L0800575E:
    movs r3, #0
    mov r8, r3
    lsls r1, r5, #1
    adds r6, r5, #1
    adds r0, r5, #0
    adds r0, #0xc
    adds r4, r0, r7
    adds r3, r5, r7
    ldr r5, .L080057F0 @ =0x0600C040
    adds r2, r1, r5
.L08005772:
    strh r3, [r2]
    mov r5, sb
    adds r0, r1, r5
    strh r4, [r0]
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    movs r0, #1
    add r8, r0
    mov r5, r8
    cmp r5, #3
    bls .L08005772
    adds r5, r6, #0
    cmp r5, #0x1b
    bls .L0800575E
    ldr r0, .L080057F8 @ =0x00001A2C
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
    ldr r1, .L080057FC @ =0x00001A30
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x94
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L080057E8: .4byte 0x0600C000
.L080057EC: .4byte 0x0600C080
.L080057F0: .4byte 0x0600C040
.L080057F4: .4byte 0x0000FFF0
.L080057F8: .4byte 0x00001A2C
.L080057FC: .4byte 0x00001A30

    .endif

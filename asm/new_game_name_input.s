    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Keyboard rows are indexed from one in the native renderer.
    .equ NEW_GAME_NAME_ENTRY_ROW_WIDTH, 31

    .ifdef REGION_JP
    .section .text.new_game_name_input_after_core_run
    .global InitializeNameInputScreen
    .thumb_func
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
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #19
    movs	r2, #32
    bl CopyHardwareDma3
    mov	r0, sl
    bl GetHardwareDisplayState
    add	r1, sp, #12
    movs	r3, #186	@ 0xba
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
    movs	r3, #30
    bl DrawUiTextWindowBorder
    movs	r0, #1
    negs	r0, r0
    ldr r4, .Ljp_00005DB8
    movs	r2, #128	@ 0x80
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
    adds	r7, #12
    ldr r0, .Ljp_00005DBC
    add	r0, sl
    str	r0, [sp, #64]	@ 0x40
    movs	r2, #209	@ 0xd1
    lsls	r2, r2, #1
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
    adds	r0, #30
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #15
    bls .Ljp_00005C7A
    movs	r3, #3
    movs	r4, #210	@ 0xd2
    lsls	r4, r4, #1
    adds	r5, r4, #0
    movs	r0, #225	@ 0xe1
    lsls	r0, r0, #1
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
    lsls	r0, r1, #4
    subs	r0, r0, r1
    lsls	r1, r0, #1
    adds	r2, r2, r4
.Ljp_00005CC4:
    adds	r0, r1, r3
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005CC4
    adds	r1, r5, #0
    cmp	r1, #15
    bls .Ljp_00005CB4
    movs	r3, #18
    movs	r1, #240	@ 0xf0
    lsls	r1, r1, #1
    adds	r5, r1, #0
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #1
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
    movs	r4, #134	@ 0x86
    lsls	r4, r4, #2
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
    cmp	r3, #9
    bls .Ljp_00005D14
.Ljp_00005D26:
    ldr r1, .Ljp_00005DE8
    movs	r0, #0
    movs	r2, #32
    bl FillHardwareDma3
    movs	r4, #30
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
    movs	r3, #240	@ 0xf0
    lsls	r3, r3, #3
    adds	r6, r0, #0
    add	r0, sp, #16
    adds	r1, r7, #0
    movs	r2, #192	@ 0xc0
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
.Ljp_00005D9C: .4byte gUiSharedTiles
.Ljp_00005DA0: .4byte 0x06004B00
.Ljp_00005DA4: .4byte gUiSharedTileByteCount
.Ljp_00005DA8: .4byte gUiSharedPalette
.Ljp_00005DAC: .4byte 0x00001841
.Ljp_00005DB0: .4byte 0x00001F02
.Ljp_00005DB4: .4byte 0x0600F800
.Ljp_00005DB8: .4byte 0x0600C000
.Ljp_00005DBC: .4byte 0x000043B0
.Ljp_00005DC0: .4byte 0x0600C094
.Ljp_00005DC4: .4byte 0x0600C054
.Ljp_00005DC8: .4byte 0x0600C486
.Ljp_00005DCC: .4byte 0x0600C446
.Ljp_00005DD0: .4byte 0x0600C0A4
.Ljp_00005DD4: .4byte 0x0600C064
.Ljp_00005DD8: .4byte 0x0000453C
.Ljp_00005DDC: .4byte 0x0000021E
.Ljp_00005DE0: .4byte 0x0600C088
.Ljp_00005DE4: .4byte 0x0600C048
.Ljp_00005DE8: .4byte 0x06FFC000
.Ljp_00005DEC: .4byte gText_NewGameNameEntry_NameLabel
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
    movs	r5, #6
    movs	r6, #2
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
    movs	r3, #192	@ 0xc0
    lsls	r3, r3, #1
    adds	r6, r0, #0
    movs	r2, #240	@ 0xf0
    lsls	r2, r2, #3
    lsls	r2, r2, #3
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
.Ljp_00005F48: .4byte 0x00004540
.Ljp_00005F4C: .4byte 0x00004577
.Ljp_00005F50: .4byte 0x0000453C
.Ljp_00005F54: .4byte 0x06000780
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
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add	sp, #84	@ 0x54
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_00006070: .4byte 0x00004538
.Ljp_00006074: .4byte 0x00004530

    .section .text.new_game_name_input_after_reset
    .global RenderNameInputName
    .thumb_func
RenderNameInputName:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r5, r0, #0
    movs r0, #0xf0
    lsls r0, r0, #3
    mov r9, r0
    movs r1, #0x60
    movs r2, #0x10
    movs r3, #0
    add r0, sp, #0x1c
    movs r6, #0x1e
    movs r4, #2
    mov r8, r4
    strh r6, [r0]
    mov r7, r8
    strh r7, [r0, #2]
    ldr r0, [sp, #0x1c]
    ldr r7, .Ljp_080062E4 @ =0x00003C2C
    adds r4, r5, r7
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBufferRect
    ldr r0, .Ljp_080062E8 @ =0x0000455C
    adds r1, r5, r0
    add r0, sp, #0x20
    strh r6, [r0]
    mov r2, r8
    strh r2, [r0, #2]
    ldr r0, [sp, #0x20]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0x90
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    adds r0, r5, #0
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    mov r3, r9
    lsls r2, r3, #3
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    add r0, sp, #0xc
    adds r1, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r4, sp, #0xc
    mov r9, r4
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .Ljp_080062EC
    cmp r1, #0
    beq .Ljp_080062DC
    adds r0, r1, #0
    add r1, sp, #0xc
    ldmia r1!, {r2, r5, r7}
    stmia r0!, {r2, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080062DC:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .Ljp_080063AC
    .align 2, 0
.Ljp_080062E4: .4byte 0x00003C2C
.Ljp_080062E8: .4byte 0x0000455C
.Ljp_080062EC:
    mov sl, r1
    movs r0, #1
    str r0, [sp, #0x28]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x24]
    add r1, sp, #0x28
    add r0, sp, #0x24
    cmp r4, #1
    bcs .Ljp_08006304
    adds r0, r1, #0
.Ljp_08006304:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08006322
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Ljp_08006326
    mov r0, r8
    bl RetryMemoryAllocation
    b .Ljp_08006326
.Ljp_08006322:
    movs r0, #0
    mov r8, r0
.Ljp_08006326:
    adds r5, r0, #0
    str r5, [sp, #0x2c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, sl
    beq .Ljp_0800634A
.Ljp_08006332:
    cmp r3, #0
    beq .Ljp_08006342
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006342:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, sl
    bne .Ljp_08006332
.Ljp_0800634A:
    adds r5, r3, #0
    ldr r0, [sp, #0x28]
    cmp r0, #1
    bne .Ljp_08006366
    cmp r5, #0
    beq .Ljp_08006362
    adds r0, r5, #0
    mov r1, r9
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006362:
    adds r5, #0x10
    b .Ljp_08006388
.Ljp_08006366:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Ljp_08006386
.Ljp_0800636E:
    cmp r2, #0
    beq .Ljp_0800637E
    adds r0, r2, #0
    mov r1, r9
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800637E:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_0800636E
.Ljp_08006386:
    adds r5, r2, #0
.Ljp_08006388:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006398
.Ljp_08006392:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_08006392
.Ljp_08006398:
    cmp r0, #0
    beq .Ljp_080063A0
    bl free
.Ljp_080063A0:
    ldr r0, [sp, #0x2c]
    add r0, r8
    ldr r7, [sp, #0x2c]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.Ljp_080063AC:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    .global RenderNameInputKeyboard
    .thumb_func
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
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #0x1e
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #0xc
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_080064AC
    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
    lsls r2, r0, #5
    subs r2, r2, r0
    movs r0, #0xba
    muls r0, r3
    adds r2, r2, r0
    ldr r0, .Ljp_080064B0
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #0x1e
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #0xc
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl GetHardwareDmaQueue
    add r4, sl
    adds r4, #0xc
    movs r1, #0xf0
    lsls r1, r1, #3
    mov r2, r8
    muls r2, r1
    adds r5, r0, #0
    movs r3, #0xc0
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
    movs r3, #0xf0
    lsls r3, r3, #3
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
    movs r1, #0xf0
    lsls r1, r1, #3
    lsls r1, r1, #3
    str r1, [sp, #0x4c]
    b .Ljp_08006586
    .align 2, 0
.Ljp_080064A4: .4byte 0x00004577
.Ljp_080064A8: .4byte 0x000034A8
.Ljp_080064AC: .4byte 0x00004540
    @ This is the one-row-before base consumed by the keyboard-row renderer,
    @ not an interior pointer into the confirmation text.
.Ljp_080064B0:
    .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
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
    movs r6, #0xf0
    lsls r6, r6, #3
    lsls r6, r6, #3
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
    cmp r0, #6
    bhi .Ljp_0800658E
    b .Ljp_080063F8
.Ljp_0800658E:
    movs r4, #0x1e
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
.Ljp_080065B8: .4byte 0x00004540
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
.Ljp_080065D0:
    .4byte gText_NewGameNameEntry_ModeKatakana
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
.Ljp_080065EC:
    .4byte gText_NewGameNameEntry_ModeSymbols
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
    movs r4, #0xf0
    lsls r4, r4, #3
    subs r2, r3, r4
    movs r6, #0xc0
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
.Ljp_0800664C:
    .4byte gText_NewGameNameEntry_ModeHiragana
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
.Ljp_08006730: .4byte 0x00004577


    .else
    .section .text.new_game_name_input_after_core_run
    thumb_func_start InitializeNameInputScreen
InitializeNameInputScreen: @ 0x08005CDC
    .ifdef REGION_DE
.LNewGameDE_08005CEC:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #84
mov	sl, r0
ldr	r0, [pc, #472]
ldr	r0, [r0, #0]
ldr	r1, [pc, #472]
ldr	r2, [pc, #472]
ldr	r2, [r2, #0]
bl	CopyHardwareDma3
ldr	r0, [pc, #468]
ldr	r0, [r0, #0]
movs	r1, #160
lsls	r1, r1, #19
movs	r2, #32
bl	CopyHardwareDma3
mov	r0, sl
bl	GetHardwareDisplayState
.LNewGameDE_08005D1C:
add	r1, sp, #12
movs	r3, #186
lsls	r3, r3, #5
adds	r2, r3, #0
strh	r2, [r1, #0]
movs	r4, #0
strh	r2, [r0, #0]
mov	r0, sl
bl	GetHardwareDisplayState
.LNewGameDE_08005D30:
add	r2, sp, #12
ldr	r5, [pc, #432]
adds	r1, r5, #0
strh	r1, [r2, #0]
strh	r1, [r0, #10]
mov	r0, sl
bl	GetHardwareDisplayState
add	r2, sp, #12
ldr	r7, [pc, #420]
adds	r1, r7, #0
strh	r1, [r2, #0]
strh	r1, [r0, #12]
ldr	r0, [pc, #416]
movs	r1, #20
str	r1, [sp, #0]
movs	r1, #155
lsls	r1, r1, #2
str	r1, [sp, #4]
str	r4, [sp, #8]
movs	r1, #0
movs	r2, #0
movs	r3, #30
bl	DrawUiTextWindowBorder
movs	r0, #1
negs	r0, r0
ldr	r4, [pc, #392]
movs	r2, #128
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
adds	r7, #12
ldr	r0, [pc, #356]
add	r0, sl
str	r0, [sp, #72]
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
ldr	r2, [pc, #328]
ldr	r1, [pc, #328]
.LNewGameDE_08005DB2:
strh	r3, [r1, #0]
adds	r0, r3, #0
adds	r0, #30
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #15
bls.n	.LNewGameDE_08005DB2
.LNewGameDE_08005DC4:
movs	r3, #3
movs	r1, #240
lsls	r1, r1, #1
adds	r5, r1, #0
movs	r2, #255
lsls	r2, r2, #1
adds	r4, r2, #0
ldr	r2, [pc, #300]
ldr	r1, [pc, #300]
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
ldr	r4, [pc, #260]
.LNewGameDE_08005DEC:
movs	r3, #0
lsls	r2, r1, #6
adds	r5, r1, #1
subs	r1, #2
lsls	r0, r1, #4
subs	r0, r0, r1
lsls	r1, r0, #1
adds	r2, r2, r4
.LNewGameDE_08005DFC:
adds	r0, r1, r3
strh	r0, [r2, #0]
adds	r2, #2
adds	r3, #1
cmp	r3, #29
bls.n	.LNewGameDE_08005DFC
adds	r1, r5, #0
cmp	r1, #17
bls.n	.LNewGameDE_08005DEC
movs	r3, #18
movs	r4, #135
lsls	r4, r4, #2
adds	r5, r4, #0
ldr	r0, [pc, #240]
adds	r4, r0, #0
ldr	r2, [pc, #240]
ldr	r1, [pc, #240]
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
movs	r0, #155
lsls	r0, r0, #7
add	r0, sl
ldr	r0, [r0, #0]
cmp	r0, #0
beq.n	.LNewGameDE_08005E5E
movs	r3, #1
ldr	r1, [pc, #212]
adds	r5, r1, #0
movs	r2, #152
lsls	r2, r2, #2
adds	r4, r2, #0
ldr	r2, [pc, #204]
ldr	r1, [pc, #208]
.LNewGameDE_08005E4C:
adds	r0, r3, r5
strh	r0, [r1, #0]
adds	r0, r3, r4
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #9
bls.n	.LNewGameDE_08005E4C
.LNewGameDE_08005E5E:
ldr	r1, [pc, #192]
movs	r0, #0
movs	r2, #32
bl	FillHardwareDma3
movs	r4, #30
movs	r5, #2
add	r0, sp, #32
strh	r4, [r0, #0]
mov	r3, r8
strh	r5, [r3, #2]
ldr	r0, [sp, #32]
adds	r1, r7, #0
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r1, [pc, #164]
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
movs	r3, #240
lsls	r3, r3, #3
adds	r6, r0, #0
add	r0, sp, #16
adds	r1, r7, #0
movs	r2, #192
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
.LNewGameDE_08005ED4: .4byte gUiSharedTiles
.LNewGameDE_08005ED8: .4byte 0x06004D80
.LNewGameDE_08005EDC: .4byte gUiSharedTileByteCount
.LNewGameDE_08005EE0: .4byte gUiSharedPalette
.LNewGameDE_08005EE4: .4byte 0x00001841
.LNewGameDE_08005EE8: .4byte 0x00001F02
.LNewGameDE_08005EEC: .4byte 0x0600F800
.LNewGameDE_08005EF0: .4byte 0x0600C000
.LNewGameDE_08005EF4: .4byte 0x00004B34
.LNewGameDE_08005EF8: .4byte 0x0600C094
.LNewGameDE_08005EFC: .4byte 0x0600C054
.LNewGameDE_08005F00: .4byte 0x0600C4C6
.LNewGameDE_08005F04: .4byte 0x0600C486
.LNewGameDE_08005F08: .4byte 0x0000023A
.LNewGameDE_08005F0C: .4byte 0x0600C0A4
.LNewGameDE_08005F10: .4byte 0x0600C064
.LNewGameDE_08005F14: .4byte 0x00000257
.LNewGameDE_08005F18: .4byte 0x0600C082
.LNewGameDE_08005F1C: .4byte 0x0600C042
.LNewGameDE_08005F20: .4byte 0x06FFC000
.LNewGameDE_08005F24: .4byte gText_NewGameNameEntry_NameLabel
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
ldr	r1, [pc, #152]
add	r1, sl
movs	r0, #0
str	r0, [r1, #0]
ldr	r0, [pc, #148]
add	r0, sl
movs	r1, #1
mov	r8, r1
mov	r2, r8
strb	r2, [r0, #0]
mov	r0, sl
bl	RenderNameInputKeyboard
movs	r7, #240
lsls	r7, r7, #3
movs	r5, #9
movs	r6, #2
add	r0, sp, #48
strh	r5, [r0, #0]
ldr	r3, [sp, #68]
strh	r6, [r3, #2]
ldr	r0, [sp, #48]
ldr	r4, [sp, #72]
adds	r1, r4, #0
movs	r2, #0
bl	Clear2DGfxBuffer
movs	r0, #155
lsls	r0, r0, #7
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
movs	r3, #144
lsls	r3, r3, #2
adds	r6, r0, #0
lsls	r2, r7, #2
adds	r2, r7, r2
lsls	r2, r2, #1
movs	r0, #192
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
.LNewGameDE_08006088: .4byte 0x00004D84
.LNewGameDE_0800608C: .4byte 0x00004DBB
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
ldr	r0, [pc, #84]
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
ldr	r1, [pc, #40]
add	r1, sl
str	r4, [sp, #0]
str	r0, [sp, #4]
str	r1, [sp, #8]
mov	r0, r9
mov	r1, r8
adds	r2, r6, #0
adds	r3, r5, #0
bl	Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
add	sp, #84
pop	{r3, r4, r5}
mov	r8, r3
mov	r9, r4
mov	sl, r5
pop	{r4, r5, r6, r7}
pop	{r0}
bx	r0
    .align 2, 0
.LNewGameDE_080061AC: .4byte 0x00004D7C
.LNewGameDE_080061B0: .4byte 0x00004D74

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x54
    mov sl, r0
    ldr r0, .L08005EC8 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L08005ECC @ =0x06004B00
    ldr r2, .L08005ED0 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L08005ED4 @ =gUiSharedPalette
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
    ldr r0, .L08005EE0 @ =0x0600F800
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
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L08005EE4 @ =0x0600C000
    movs r2, #0x80
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
    adds r7, #0xc
    ldr r0, .L08005EE8 @ =0x000043B0
    add r0, sl
    str r0, [sp, #0x40]
    movs r2, #0xd1
    lsls r2, r2, #1
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
    ldr r2, .L08005EEC @ =0x0600C094
    ldr r1, .L08005EF0 @ =0x0600C054
.L08005DA6:
    strh r3, [r1]
    adds r0, r3, #0
    adds r0, #0x1e
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0xf
    bls .L08005DA6
    movs r3, #3
    movs r4, #0xd2
    lsls r4, r4, #1
    adds r5, r4, #0
    movs r0, #0xe1
    lsls r0, r0, #1
    adds r4, r0, #0
    ldr r2, .L08005EF4 @ =0x0600C486
    ldr r1, .L08005EF8 @ =0x0600C446
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
    ldr r4, .L08005EE4 @ =0x0600C000
.L08005DE0:
    movs r3, #0
    lsls r2, r1, #6
    adds r5, r1, #1
    subs r1, #2
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r1, r0, #1
    adds r2, r2, r4
.L08005DF0:
    adds r0, r1, r3
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005DF0
    adds r1, r5, #0
    cmp r1, #0xf
    bls .L08005DE0
    movs r3, #0x12
    movs r1, #0xf0
    lsls r1, r1, #1
    adds r5, r1, #0
    movs r2, #0xff
    lsls r2, r2, #1
    adds r4, r2, #0
    ldr r2, .L08005EFC @ =0x0600C0A4
    ldr r1, .L08005F00 @ =0x0600C064
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
    ldr r0, .L08005F04 @ =0x000045FC
    add r0, sl
    ldr r0, [r0]
    cmp r0, #0
    beq .L08005E52
    movs r3, #1
    ldr r4, .L08005F08 @ =0x0000021B
    adds r5, r4, #0
    movs r0, #0x89
    lsls r0, r0, #2
    adds r4, r0, #0
    ldr r2, .L08005F0C @ =0x0600C082
    ldr r1, .L08005F10 @ =0x0600C042
.L08005E40:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #9
    bls .L08005E40
.L08005E52:
    ldr r1, .L08005F14 @ =0x06FFC000
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r4, #0x1e
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
    movs r3, #0xf0
    lsls r3, r3, #3
    adds r6, r0, #0
    add r0, sp, #0x10
    adds r1, r7, #0
    movs r2, #0xc0
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
.L08005EC8: .4byte gUiSharedTiles
.L08005ECC: .4byte 0x06004B00
.L08005ED0: .4byte gUiSharedTileByteCount
.L08005ED4: .4byte gUiSharedPalette
.L08005ED8: .4byte 0x00001841
.L08005EDC: .4byte 0x00001F02
.L08005EE0: .4byte 0x0600F800
.L08005EE4: .4byte 0x0600C000
.L08005EE8: .4byte 0x000043B0
.L08005EEC: .4byte 0x0600C094
.L08005EF0: .4byte 0x0600C054
.L08005EF4: .4byte 0x0600C486
.L08005EF8: .4byte 0x0600C446
.L08005EFC: .4byte 0x0600C0A4
.L08005F00: .4byte 0x0600C064
.L08005F04: .4byte 0x000045FC
.L08005F08: .4byte 0x0000021B
.L08005F0C: .4byte 0x0600C082
.L08005F10: .4byte 0x0600C042
.L08005F14: .4byte 0x06FFC000
.L08005F18: .4byte gText_NewGameNameEntry_NameLabel
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
    movs r1, #0x8c
    lsls r1, r1, #7
    add r1, sl
    movs r0, #0
    str r0, [r1]
    ldr r0, .L08006074 @ =0x00004637
    add r0, sl
    movs r2, #1
    mov r8, r2
    mov r3, r8
    strb r3, [r0]
    mov r0, sl
    bl RenderNameInputKeyboard
    movs r5, #9
    movs r6, #2
    add r0, sp, #0x30
    strh r5, [r0]
    ldr r4, [sp, #0x48]
    strh r6, [r4, #2]
    ldr r0, [sp, #0x30]
    ldr r4, [sp, #0x40]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .L08006078 @ =0x000045FC
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
    movs r3, #0x90
    lsls r3, r3, #2
    adds r6, r0, #0
    movs r2, #0xf0
    lsls r2, r2, #3
    lsls r2, r2, #3
    ldr r5, .L0800607C @ =0x06000780
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
.L08006074: .4byte 0x00004637
.L08006078: .4byte 0x000045FC
.L0800607C: .4byte 0x06000780
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
    ldr r0, .L08006198 @ =0x000045F8
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
    ldr r1, .L0800619C @ =0x000045F0
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x54
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08006198: .4byte 0x000045F8
.L0800619C: .4byte 0x000045F0
    .endif

    .section .text.new_game_name_input_after_reset
    thumb_func_start RenderNameInputName
RenderNameInputName: @ 0x0800637C
    .ifdef REGION_DE
.LNewGameDE_08006390:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #48
adds	r4, r0, #0
movs	r1, #96
movs	r2, #16
movs	r3, #0
add	r0, sp, #28
movs	r6, #30
movs	r5, #2
mov	r8, r5
strh	r6, [r0, #0]
mov	r7, r8
strh	r7, [r0, #2]
ldr	r0, [sp, #28]
ldr	r7, [pc, #100]
adds	r5, r4, r7
str	r1, [sp, #0]
str	r2, [sp, #4]
str	r3, [sp, #8]
adds	r1, r5, #0
movs	r2, #0
bl	Clear2DGfxBufferRect
ldr	r0, [pc, #88]
adds	r1, r4, r0
add	r0, sp, #32
strh	r6, [r0, #0]
mov	r2, r8
strh	r2, [r0, #2]
ldr	r0, [sp, #32]
str	r1, [sp, #0]
adds	r1, r5, #0
movs	r2, #144
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
adds	r0, r4, #0
bl	GetHardwareDmaQueue
adds	r6, r0, #0
movs	r4, #240
lsls	r4, r4, #3
ldr	r2, [pc, #52]
add	r0, sp, #12
adds	r1, r5, #0
adds	r3, r4, #0
bl	__21DmaTransferDescriptorPCvPvUi
add	r3, sp, #12
mov	r9, r3
ldr	r1, [r6, #4]
ldr	r0, [r6, #12]
cmp	r1, r0
beq.n	.LNewGameDE_08006428
cmp	r1, #0
beq.n	.LNewGameDE_08006414
adds	r0, r1, #0
add	r1, sp, #12
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006414:
ldr	r0, [r6, #4]
adds	r0, #16
str	r0, [r6, #4]
b.n	.LNewGameDE_080064E8
.LNewGameDE_0800641C: .4byte 0x000043B0
.LNewGameDE_08006420: .4byte 0x00004DA0
.LNewGameDE_08006424: .4byte 0x06004380
.LNewGameDE_08006428:
mov	sl, r1
movs	r0, #1
str	r0, [sp, #40]
ldr	r0, [r6, #0]
subs	r0, r1, r0
asrs	r4, r0, #4
str	r4, [sp, #36]
add	r1, sp, #40
add	r0, sp, #36
cmp	r4, #1
bcs.n	.LNewGameDE_08006440
adds	r0, r1, #0
.LNewGameDE_08006440:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_0800645E
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r8, r4
cmp	r0, #0
bne.n	.LNewGameDE_08006462
mov	r0, r8
bl	RetryMemoryAllocation
b.n	.LNewGameDE_08006462
.LNewGameDE_0800645E:
movs	r0, #0
mov	r8, r0
.LNewGameDE_08006462:
adds	r5, r0, #0
str	r5, [sp, #44]
ldr	r2, [r6, #0]
adds	r3, r5, #0
cmp	r2, sl
beq.n	.LNewGameDE_08006486
.LNewGameDE_0800646E:
cmp	r3, #0
beq.n	.LNewGameDE_0800647E
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800647E:
adds	r2, #16
adds	r3, #16
cmp	r2, sl
bne.n	.LNewGameDE_0800646E
.LNewGameDE_08006486:
adds	r5, r3, #0
ldr	r0, [sp, #40]
cmp	r0, #1
bne.n	.LNewGameDE_080064A2
cmp	r5, #0
beq.n	.LNewGameDE_0800649E
adds	r0, r5, #0
mov	r1, r9
ldmia	r1!, {r2, r3, r4}
stmia	r0!, {r2, r3, r4}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800649E:
adds	r5, #16
b.n	.LNewGameDE_080064C4
.LNewGameDE_080064A2:
adds	r3, r0, #0
adds	r2, r5, #0
cmp	r3, #0
beq.n	.LNewGameDE_080064C2
.LNewGameDE_080064AA:
cmp	r2, #0
beq.n	.LNewGameDE_080064BA
adds	r0, r2, #0
mov	r1, r9
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_080064BA:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_080064AA
.LNewGameDE_080064C2:
adds	r5, r2, #0
.LNewGameDE_080064C4:
ldr	r2, [r6, #4]
ldr	r0, [r6, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_080064D4
.LNewGameDE_080064CE:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_080064CE
.LNewGameDE_080064D4:
cmp	r0, #0
beq.n	.LNewGameDE_080064DC
bl	free
.LNewGameDE_080064DC:
ldr	r0, [sp, #44]
add	r0, r8
ldr	r7, [sp, #44]
str	r7, [r6, #0]
str	r5, [r6, #4]
str	r0, [r6, #12]
.LNewGameDE_080064E8:
add	sp, #48
pop	{r3, r4, r5}
mov	r8, r3
mov	r9, r4
mov	sl, r5
pop	{r4, r5, r6, r7}
pop	{r0}
bx	r0

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r5, r0, #0
    movs r0, #0xf0
    lsls r0, r0, #3
    mov sb, r0
    movs r1, #0x60
    movs r2, #0x10
    movs r3, #0
    add r0, sp, #0x1c
    movs r6, #0x1e
    movs r4, #2
    mov r8, r4
    strh r6, [r0]
    mov r7, r8
    strh r7, [r0, #2]
    ldr r0, [sp, #0x1c]
    ldr r7, .L08006410 @ =0x00003C2C
    adds r4, r5, r7
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBufferRect
    ldr r0, .L08006414 @ =0x0000461C
    adds r1, r5, r0
    add r0, sp, #0x20
    strh r6, [r0]
    mov r2, r8
    strh r2, [r0, #2]
    ldr r0, [sp, #0x20]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0x90
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    adds r0, r5, #0
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    mov r3, sb
    lsls r2, r3, #3
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    add r0, sp, #0xc
    adds r1, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r4, sp, #0xc
    mov sb, r4
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08006418
    cmp r1, #0
    beq .L08006408
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r2, r5, r7}
    stm r0!, {r2, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006408:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L080064D8
    .align 2, 0
.L08006410: .4byte 0x00003C2C
.L08006414: .4byte 0x0000461C
.L08006418:
    mov sl, r1
    movs r0, #1
    str r0, [sp, #0x28]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x24]
    add r1, sp, #0x28
    add r0, sp, #0x24
    cmp r4, #1
    bhs .L08006430
    adds r0, r1, #0
.L08006430:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0800644E
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L08006452
    mov r0, r8
    bl RetryMemoryAllocation
    b .L08006452
.L0800644E:
    movs r0, #0
    mov r8, r0
.L08006452:
    adds r5, r0, #0
    str r5, [sp, #0x2c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, sl
    beq .L08006476
.L0800645E:
    cmp r3, #0
    beq .L0800646E
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800646E:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, sl
    bne .L0800645E
.L08006476:
    adds r5, r3, #0
    ldr r0, [sp, #0x28]
    cmp r0, #1
    bne .L08006492
    cmp r5, #0
    beq .L0800648E
    adds r0, r5, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800648E:
    adds r5, #0x10
    b .L080064B4
.L08006492:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L080064B2
.L0800649A:
    cmp r2, #0
    beq .L080064AA
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080064AA:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L0800649A
.L080064B2:
    adds r5, r2, #0
.L080064B4:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L080064C4
.L080064BE:
    adds r1, #0x10
    cmp r1, r2
    bne .L080064BE
.L080064C4:
    cmp r0, #0
    beq .L080064CC
    bl free
.L080064CC:
    ldr r0, [sp, #0x2c]
    add r0, r8
    ldr r7, [sp, #0x2c]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L080064D8:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .endif

    thumb_func_start RenderNameInputKeyboard
RenderNameInputKeyboard: @ 0x080064E8
    .ifdef REGION_DE
.LNewGameDE_080064F8:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #92
mov	sl, r0
ldr	r0, [pc, #220]
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
ldr	r4, [pc, #188]
add	r4, sl
str	r4, [sp, #80]
mov	r6, sp
adds	r6, #4
str	r6, [sp, #60]
.LNewGameDE_08006534:
mov	r7, r8
lsls	r4, r7, #4
subs	r4, r4, r7
lsls	r4, r4, #5
add	r4, r8
lsls	r4, r4, #2
mov	r0, sl
adds	r1, r4, r0
add	r0, sp, #20
movs	r2, #30
strh	r2, [r0, #0]
movs	r6, #2
ldr	r3, [sp, #64]
strh	r6, [r3, #2]
ldr	r0, [sp, #20]
adds	r1, #12
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r0, [pc, #144]
add	r0, sl
ldr	r0, [r0, #0]
mov	r7, sl
adds	r1, r4, r7
mov	r2, r8
lsls	r3, r2, #5
subs	r3, r3, r2
lsls	r2, r0, #3
subs	r2, r2, r0
lsls	r0, r2, #5
subs	r0, r0, r2
adds	r3, r3, r0
ldr	r0, [pc, #120]
adds	r3, r3, r0
add	r0, sp, #24
movs	r6, #30
strh	r6, [r0, #0]
movs	r0, #2
.LNewGameDE_08006580:
ldr	r7, [sp, #68]
strh	r0, [r7, #2]
ldr	r0, [sp, #24]
adds	r1, #12
str	r3, [sp, #0]
movs	r2, #0
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
mov	r0, sl
bl	GetHardwareDmaQueue
add	r4, sl
adds	r4, #12
movs	r1, #240
lsls	r1, r1, #3
mov	r2, r8
muls	r2, r1
adds	r5, r0, #0
movs	r3, #192
.LNewGameDE_080065A8:
lsls	r3, r3, #19
adds	r2, r2, r3
add	r0, sp, #4
adds	r1, r4, #0
movs	r3, #240
lsls	r3, r3, #3
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
movs	r1, #240
lsls	r1, r1, #3
lsls	r1, r1, #3
str	r1, [sp, #76]
b.n	.LNewGameDE_080066C6
.LNewGameDE_080065E4: .4byte 0x00004DBB
.LNewGameDE_080065E8: .4byte 0x00003C2C
.LNewGameDE_080065EC: .4byte 0x00004D84
.LNewGameDE_080065F0: .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
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
movs	r6, #240
lsls	r6, r6, #3
lsls	r6, r6, #3
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
cmp	r0, #7
bhi.n	.LNewGameDE_080066CE
b.n	.LNewGameDE_08006534
.LNewGameDE_080066CE:
movs	r4, #30
movs	r5, #2
add	r0, sp, #36
strh	r4, [r0, #0]
ldr	r1, [sp, #72]
strh	r5, [r1, #2]
ldr	r0, [sp, #36]
ldr	r1, [sp, #80]
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r0, [pc, #16]
add	r0, sl
ldr	r2, [r0, #0]
cmp	r2, #1
beq.n	.LNewGameDE_08006714
cmp	r2, #1
bgt.n	.LNewGameDE_080066FC
cmp	r2, #0
beq.n	.LNewGameDE_08006702
b.n	.LNewGameDE_08006746
.LNewGameDE_080066F8: .4byte 0x00004D84
.LNewGameDE_080066FC:
cmp	r2, #2
beq.n	.LNewGameDE_08006730
b.n	.LNewGameDE_08006746
.LNewGameDE_08006702:
ldr	r1, [pc, #12]
add	r0, sp, #40
strh	r4, [r0, #0]
strh	r5, [r0, #2]
ldr	r0, [sp, #40]
b.n	.LNewGameDE_0800671E
    .align 2, 0
.LNewGameDE_08006710: .4byte gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006714:
ldr	r1, [pc, #20]
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
.LNewGameDE_0800672C: .4byte gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006730:
ldr	r1, [pc, #84]
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
movs	r2, #192
lsls	r2, r2, #19
ldr	r3, [sp, #76]
adds	r2, r3, r2
add	r0, sp, #4
ldr	r1, [sp, #80]
movs	r3, #240
lsls	r3, r3, #3
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
.LNewGameDE_08006788: .4byte gText_NewGameNameEntry_EndLatin
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
ldr	r1, [pc, #24]
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
.LNewGameDE_0800686C: .4byte 0x00004DBB

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    mov sl, r0
    ldr r0, .L080065D0 @ =0x00004637
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
    ldr r4, .L080065D4 @ =0x000034A8
    add r4, sl
    str r4, [sp, #0x50]
    mov r6, sp
    adds r6, #4
    str r6, [sp, #0x3c]
.L08006524:
    mov r7, r8
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #0x1e
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #0xc
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r0, #0x8c
    lsls r0, r0, #7
    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
    lsls r2, r0, #5
    subs r2, r2, r0
    movs r0, #0xba
    muls r0, r3, r0
    adds r2, r2, r0
    ldr r0, .L080065D8 @ =gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #0x1e
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #0xc
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl GetHardwareDmaQueue
    add r4, sl
    adds r4, #0xc
    movs r1, #0xf0
    lsls r1, r1, #3
    mov r2, r8
    muls r2, r1, r2
    adds r5, r0, #0
    movs r3, #0xc0
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
    movs r3, #0xf0
    lsls r3, r3, #3
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
    movs r1, #0xf0
    lsls r1, r1, #3
    lsls r1, r1, #3
    str r1, [sp, #0x4c]
    b .L080066AE
    .align 2, 0
.L080065D0: .4byte 0x00004637
.L080065D4: .4byte 0x000034A8
@ r8 is one-based here, so this is the keyboard table address minus exactly
@ one fixed-width row.  It is not a pointer into DogName.
.L080065D8: .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
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
    movs r6, #0xf0
    lsls r6, r6, #3
    lsls r6, r6, #3
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
    cmp r0, #6
    bhi .L080066B6
    b .L08006524
.L080066B6:
    movs r4, #0x1e
    movs r5, #2
    add r0, sp, #0x24
    strh r4, [r0]
    ldr r1, [sp, #0x48]
    strh r5, [r1, #2]
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x50]
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r0, #0x8c
    lsls r0, r0, #7
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
.L080066F4: .4byte gText_NewGameNameEntry_EndLatin
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
.L08006710: .4byte gText_NewGameNameEntry_EndFullWidth
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
    movs r4, #0xf0
    lsls r4, r4, #3
    subs r2, r3, r4
    movs r6, #0xc0
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
.L08006770: .4byte gText_NewGameNameEntry_EndFullWidth
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
    ldr r1, .L08006854 @ =0x00004637
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
.L08006854: .4byte 0x00004637
    .endif


    .endif

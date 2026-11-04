    .include "six/asm/hw/video.s"
    .INCLUDE "asm/macro.inc"
    .syntax unified
    .thumb
    .section .text

    @ Complete native world draw. The C++ body is still being matched.
    .ifdef REGION_JP
    .align 2, 0

    .global Draw__14GameSceneWorldRC21GameObjectDrawContext
    .thumb_func
Draw__14GameSceneWorldRC21GameObjectDrawContext:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [pc, #0x210]
    add sp, r4
    mov sb, r0
    ldr r0, [pc, #0x20c]
    add r0, sp
    str r1, [r0]
    movs r0, #0
    ldr r1, [pc, #0x208]
    add r1, sp
    str r0, [r1]
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    movs r2, #0x20
    ldr r0, [pc, #0x1fc]
    add r0, sp
    ldr r0, [r0]
    .Lauto_08018088:
    strb r0, [r1]
    subs r2, #1
    adds r1, #1
    cmp r2, #0
    bgt .Lauto_08018088
    ldr r0, [pc, #0x1f0]
    add r0, sb
    ldr r2, [r0]
    ldr r3, [pc, #0x1e0]
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r4, r2, #0
    adds r4, #0x9c
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_080180B4
    adds r0, r2, #0
    bl PrepareResources__22EntityAuxiliarySpritesR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
    .Lauto_080180B4:
    ldr r0, [pc, #0x1d0]
    add r0, sb
    ldr r2, [r0]
    cmp r2, #0
    beq .Lauto_080180DA
    ldr r4, [pc, #0x1bc]
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4]
    adds r4, r2, #0
    adds r4, #0xe5
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_080180DA
    adds r0, r2, #0
    bl PrepareResources__22GameSceneWeatherEffectR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
    .Lauto_080180DA:
    mov r5, sb
    ldr r0, [r5, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r4, [r1]
    ldr r6, [pc, #0x194]
    add r6, sp
    ldr r6, [r6]
    ldr r1, [r6]
    ldr r2, [r6, #4]
    ldr r3, [r6, #0xc]
    ldr r4, [r4, #0x10]
    bl _call_via_r4
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    movs r2, #0xdb
    lsls r2, r2, #4
    add r2, sb
    ldrb r0, [r2]
    ldr r1, [pc, #0x184]
    add r1, sb
    strb r0, [r1]
    movs r3, #0
    ldr r6, [pc, #0x180]
    add r6, sp
    str r2, [r6]
    movs r0, #0xcc
    lsls r0, r0, #4
    add r0, sp
    str r1, [r0]
    ldrb r1, [r1]
    cmp r3, r1
    bhs .Lauto_08018152
    movs r5, #0xde
    lsls r5, r5, #1
    add r5, sb
    ldr r2, [pc, #0x16c]
    add r2, sb
    .Lauto_0801812A:
    ldrb r0, [r2]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .Lauto_08018144
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r1, r0, #5
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r1, r5, r1
    adds r1, #0x80
    movs r0, #0xff
    strb r0, [r1]
    .Lauto_08018144:
    adds r2, #0xc
    adds r3, #1
    ldr r6, [pc, #0x14c]
    adds r0, r4, r6
    ldrb r0, [r0]
    cmp r3, r0
    blo .Lauto_0801812A
    .Lauto_08018152:
    ldr r1, [pc, #0x148]
    adds r0, r4, r1
    movs r2, #0
    strb r2, [r0]
    ldr r3, [pc, #0x120]
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3, #8]
    ldrb r1, [r0]
    movs r0, #0x7c
    subs r0, r0, r1
    movs r4, #0xc7
    lsls r4, r4, #4
    add r4, sp
    str r0, [r4]
    cmp r0, #0x80
    bls .Lauto_08018178
    bl loc_08019604
    .Lauto_08018178:
    add r0, sp, #0x14
    strb r2, [r0]
    add r0, sp, #0x18
    movs r1, #3
    mov r5, sb
    ldr r4, [r5]
    mov r6, sb
    adds r6, #8
    ldr r2, [pc, #0x114]
    add r2, sp
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r5, #0xcc
    lsls r5, r5, #1
    add r5, sb
    ldr r2, [pc, #0x108]
    add r2, sp
    str r5, [r2]
    ldr r3, [pc, #0x104]
    add r3, sp
    ldr r5, [pc, #0x104]
    add r5, sp
    str r3, [r5]
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
    .Lauto_080181B0:
    str r3, [r0]
    movs r5, #0x81
    lsls r5, r5, #2
    adds r0, r0, r5
    subs r1, #1
    cmp r1, r2
    bne .Lauto_080181B0
    ldr r1, [r4, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldr r5, [pc, #0xd8]
    add r5, sp
    ldr r2, [pc, #0xa0]
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    ldr r2, [r2, #4]
    str r1, [r5]
    str r2, [r5, #4]
    add r1, sp, #0x14
    str r1, [r5, #8]
    strh r4, [r5, #0xc]
    strh r0, [r5, #0xe]
    ldr r2, [pc, #0xc4]
    add r2, sp
    str r6, [r2]
    ldr r3, [pc, #0xc0]
    add r3, sp
    str r6, [r3]
    ldr r4, [r2]
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_0801820E
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #0x1c]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r2
    .Lauto_0801820E:
    ldr r0, [pc, #0x78]
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_0801821E
    add r1, sp, #0x14
    bl Draw__22GameSceneWeatherEffectP21WorldSpriteDrawBuffer
    .Lauto_0801821E:
    ldr r0, [pc, #0x9c]
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_08018230
    ldr r2, [r5]
    add r1, sp, #0x14
    bl Draw__18WorldSpriteEffectsP21WorldSpriteDrawBufferR16HardwareDmaQueue
    .Lauto_08018230:
    ldr r1, [r5]
    ldr r2, [r5, #8]
    ldr r0, [pc, #0x68]
    add r0, sp
    str r1, [r0]
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    str r2, [r5, #4]
    ldr r0, [pc, #0x78]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_08018250
    b .Lauto_08018612
    .Lauto_08018250:
    movs r5, #0
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_080182C4
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    .byte 0x02, 0x1C, 0x90, 0x07, 0x00, 0x28, 0x03, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70
    .byte 0x10, 0x1C, 0x28, 0xE0, 0x20, 0xF3, 0xFF, 0xFF, 0x6C, 0x0C, 0x00, 0x00, 0x58, 0x0C, 0x00, 0x00
    .byte 0x24, 0x10, 0x00, 0x00, 0x7C, 0x10, 0x00, 0x00, 0xB1, 0x0D, 0x00, 0x00, 0xBC, 0x0C, 0x00, 0x00
    .byte 0x1D, 0x0D, 0x00, 0x00, 0x15, 0x0C, 0x00, 0x00, 0x14, 0x0C, 0x00, 0x00, 0x5C, 0x0C, 0x00, 0x00
    .byte 0xC4, 0x0C, 0x00, 0x00, 0x28, 0x08, 0x00, 0x00, 0xC8, 0x0C, 0x00, 0x00, 0x28, 0x0C, 0x00, 0x00
    .byte 0x98, 0x0C, 0x00, 0x00, 0x74, 0x0C, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .Lauto_080182C4:
    movs r0, #0
    strb r0, [r1]
    .byte 0x02, 0x20, 0x40, 0x07, 0x00, 0x28, 0x06, 0xDA, 0x83, 0x20, 0x40, 0x01, 0x48, 0x44, 0x00, 0x78
    .byte 0x00, 0x28, 0x00, 0xD0, 0x01, 0x25, 0x00, 0x2D, 0x14, 0xD0, 0x83, 0x20, 0x40, 0x01, 0x48, 0x44
    .byte 0x00, 0x24, 0x04, 0x70, 0x0F, 0x48, 0x48, 0x44, 0x05, 0x68, 0x28, 0x1C, 0x28, 0x30, 0x01, 0x21
    bl ResolveIndexedResourceHandle
    .byte 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x04, 0x70
    .byte 0x01, 0x30, 0x01, 0x70, 0x4E, 0x46, 0x30, 0x68, 0x41, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xD8, 0xFE
    .byte 0x0A, 0x38, 0x1D, 0x28, 0x00, 0xD9, 0x78, 0xE1, 0x80, 0x00, 0x03, 0x49, 0x40, 0x18, 0x00, 0x68
    .byte 0x87, 0x46, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x34, 0x83, 0x01, 0x08, 0x04, 0x85, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x76, 0x84, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x20, 0x85, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0xAC, 0x83, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0xE8, 0x84, 0x01, 0x08, 0x21, 0x48, 0x48, 0x44, 0x05, 0x68, 0x49, 0x46, 0x08, 0x68, 0x81, 0x69
    .byte 0x48, 0x46, 0xBA, 0xF0, 0x85, 0xFE, 0x30, 0x24, 0x20, 0x1A, 0x80, 0x46, 0x4A, 0x46, 0x10, 0x68
    .byte 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0x7C, 0xFE, 0x27, 0x1A, 0xCB, 0x23, 0x1B, 0x01, 0x6B, 0x44
    .byte 0x1B, 0x68, 0x9A, 0x46, 0x16, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00
    .byte 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xBA, 0xF0, 0x6D, 0xFE, 0x26, 0x1C
    .byte 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68
    .byte 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x19, 0xDA, 0xA9, 0x89, 0x2A, 0x1C, 0x10, 0x32, 0x09, 0x48
    .byte 0x00, 0x90, 0x01, 0x96, 0x02, 0x93, 0x03, 0x91, 0x04, 0x92, 0x20, 0x1C, 0x41, 0x46, 0x3A, 0x1C
    .byte 0xFF, 0x23, 0x05, 0x4C, 0xBA, 0xF0, 0x52, 0xFE, 0x09, 0xE0, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28
    .byte 0x00, 0xD1, 0xE2, 0xE0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x07, 0x1C, 0x00, 0x29, 0x00, 0xD1
    .byte 0xDB, 0xE0, 0x52, 0x46, 0x11, 0x68, 0x32, 0x1C, 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x00, 0xD0, 0xB8, 0xE0, 0xBE, 0xE0, 0x1A, 0x48
    .byte 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0x20, 0xFE
    .byte 0x68, 0x21, 0x09, 0x1A, 0x88, 0x46, 0x4D, 0x46, 0x28, 0x68, 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0
    .byte 0x17, 0xFE, 0x30, 0x21, 0x0F, 0x1A, 0x25, 0x1C, 0xCB, 0x26, 0x36, 0x01, 0x6E, 0x44, 0x36, 0x68
    .byte 0xB2, 0x46, 0x0E, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A
    .byte 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xBA, 0xF0, 0x06, 0xFE, 0x26, 0x1C, 0xCB, 0x20
    .byte 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68, 0x48, 0x42
    .byte 0x08, 0x43, 0x00, 0x28, 0x98, 0xDB, 0xB1, 0xE7, 0x5C, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .byte 0x05, 0x48, 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0
    .byte 0xE7, 0xFD, 0x18, 0x21, 0xC5, 0xE7, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x05, 0x48, 0x48, 0x44
    .byte 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xD9, 0xFD, 0x38, 0x21
    .byte 0xB7, 0xE7, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x22, 0x48, 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46
    .byte 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xCB, 0xFD, 0x68, 0x21, 0x09, 0x1A, 0x88, 0x46
    .byte 0x4D, 0x46, 0x28, 0x68, 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xC2, 0xFD, 0x30, 0x21, 0x0F, 0x1A
    .byte 0x25, 0x1C, 0xCB, 0x26, 0x36, 0x01, 0x6E, 0x44, 0x36, 0x68, 0xB2, 0x46, 0x16, 0x4C, 0x6C, 0x44
    .byte 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C
    .byte 0x1B, 0x69, 0xBA, 0xF0, 0xB1, 0xFD, 0x26, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68
    .byte 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x19, 0xDA
    .byte 0xA9, 0x89, 0x2A, 0x1C, 0x10, 0x32, 0x09, 0x48, 0x00, 0x90, 0x01, 0x96, 0x02, 0x93, 0x03, 0x91
    .byte 0x04, 0x92, 0x20, 0x1C, 0x41, 0x46, 0x3A, 0x1C, 0xFF, 0x23, 0x05, 0x4C, 0xBA, 0xF0, 0x96, 0xFD
    .byte 0x09, 0xE0, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x27, 0xD0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78
    .byte 0x07, 0x1C, 0x00, 0x29, 0x21, 0xD0, 0x52, 0x46, 0x11, 0x68, 0x32, 0x1C, 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x06, 0xD0, 0x31, 0x1C
    .byte 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0C, 0xE0, 0x2C, 0x1C, 0x3E, 0x34
    .byte 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x31, 0x1C, 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x38, 0x70
    .Lauto_08018612:
    ldr r0, [pc, #0x2c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_0801861E
    b .Lauto_0801873A
    .Lauto_0801861E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08018644
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08018648
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08018646
    .byte 0x00, 0x00, 0x64, 0x10, 0x00, 0x00
    .Lauto_08018644:
    movs r0, #0
    .Lauto_08018646:
    strb r0, [r1]
    .Lauto_08018648:
    ldr r0, [pc, #0x88]
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x58
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x10
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x58]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_080186E4
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b .Lauto_080186E6
    .byte 0x00, 0x00, 0x64, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_080186E4:
    movs r0, #0
    .Lauto_080186E6:
    cmp r0, #0
    beq .Lauto_0801873A
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_0801873A
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_0801871C
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018736
    .Lauto_0801871C:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018736
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018736:
    movs r0, #0
    strb r0, [r7]
    .Lauto_0801873A:
    movs r3, #0
    ldr r4, [pc, #0xb0]
    add r4, sp
    str r3, [r4]
    movs r5, #0xde
    lsls r5, r5, #2
    movs r6, #0xcd
    lsls r6, r6, #4
    add r6, sp
    str r5, [r6]
    ldr r0, [pc, #0xa4]
    add r0, sb
    ldr r1, [pc, #0xa4]
    add r1, sp
    str r0, [r1]
    .Lauto_08018758:
    ldr r2, [pc, #0x9c]
    add r2, sp
    ldr r2, [r2]
    ldr r4, [r2]
    cmp r4, #0
    beq .Lauto_0801885E
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r5, #0xcd
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    subs r0, r5, r0
    mov r8, r0
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xf0
    lsls r1, r1, #1
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, [pc, #0x60]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018808
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    ldr r4, [pc, #0x28]
    str r4, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x18]
    bl _call_via_r4
    b .Lauto_0801880A
    .byte 0x78, 0x0C, 0x00, 0x00, 0x6C, 0x10, 0x00, 0x00, 0xD4, 0x0C, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .byte 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018808:
    movs r0, #0
    .Lauto_0801880A:
    cmp r0, #0
    beq .Lauto_0801885E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_0801885E
    mov r0, sl
    ldr r1, [r0]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018840
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_0801885A
    .Lauto_08018840:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_0801885A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_0801885A:
    movs r0, #0
    strb r0, [r7]
    .Lauto_0801885E:
    movs r2, #0xcd
    lsls r2, r2, #4
    add r2, sp
    ldr r1, [r2]
    adds r1, #0x28
    str r1, [r2]
    ldr r4, [pc, #0x44]
    add r4, sp
    ldr r3, [r4]
    adds r3, #4
    str r3, [r4]
    ldr r6, [pc, #0x3c]
    add r6, sp
    ldr r5, [r6]
    adds r5, #1
    str r5, [r6]
    cmp r5, #1
    bhi .Lauto_08018884
    b .Lauto_08018758
    .Lauto_08018884:
    ldr r4, [pc, #0x30]
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .Lauto_08018890
    b .Lauto_08018B0A
    .Lauto_08018890:
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_080188A2
    b .Lauto_08018A22
    .Lauto_080188A2:
    cmp r0, #2
    bgt .Lauto_080188BC
    cmp r0, #0
    bne .Lauto_080188AC
    b .Lauto_080189FC
    .Lauto_080188AC:
    b .Lauto_08018B0A
    .byte 0x00, 0x00, 0xD4, 0x0C, 0x00, 0x00, 0x78, 0x0C, 0x00, 0x00, 0x74, 0x10, 0x00, 0x00
    .Lauto_080188BC:
    cmp r0, #3
    beq .Lauto_0801898E
    cmp r0, #7
    beq .Lauto_080188C6
    b .Lauto_08018B0A
    .Lauto_080188C6:
    ldr r4, [r4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x86
    subs r7, r1, r0
    adds r5, r4, #0
    movs r4, #0xcb
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    mov sl, r4
    ldr r4, [pc, #0x54]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_0801895C
    .Lauto_0801892C:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x20]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x10]
    bl _call_via_r4
    b .Lauto_0801895E
    .byte 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_0801895C:
    movs r0, #0
    .Lauto_0801895E:
    cmp r0, #0
    bne .Lauto_08018964
    b .Lauto_08018B0A
    .Lauto_08018964:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .Lauto_08018972
    b .Lauto_08018B0A
    .Lauto_08018972:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_0801898C
    b .Lauto_08018ADE
    .Lauto_0801898C:
    b .Lauto_08018AEC
    .Lauto_0801898E:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x9b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x76
    .Lauto_080189B2:
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x34]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .Lauto_0801892C
    b .Lauto_0801895C
    .byte 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .Lauto_080189FC:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xb0
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    b .Lauto_080189B2
    .Lauto_08018A22:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x88
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x54]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018AB4
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x1c]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0xc]
    bl _call_via_r4
    b .Lauto_08018AB6
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018AB4:
    movs r0, #0
    .Lauto_08018AB6:
    cmp r0, #0
    beq .Lauto_08018B0A
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018B0A
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018AEC
    .Lauto_08018ADE:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018B06
    .Lauto_08018AEC:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018B06
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018B06:
    movs r0, #0
    strb r0, [r7]
    .Lauto_08018B0A:
    ldr r0, [pc, #0x8c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    beq .Lauto_08018C02
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r1, [pc, #0x78]
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x13
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018BAC
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b .Lauto_08018BAE
    .byte 0x78, 0x10, 0x00, 0x00, 0x35, 0x02, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018BAC:
    movs r0, #0
    .Lauto_08018BAE:
    cmp r0, #0
    beq .Lauto_08018C02
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018C02
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018BE4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018BFE
    .Lauto_08018BE4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018BFE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018BFE:
    movs r0, #0
    strb r0, [r7]
    .Lauto_08018C02:
    ldr r0, [pc, #0x2c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_08018C0E
    b loc_08018E56
    .Lauto_08018C0E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08018C34
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08018C38
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08018C36
    .byte 0x00, 0x00, 0x58, 0x10, 0x00, 0x00
    .Lauto_08018C34:
    movs r0, #0
    .Lauto_08018C36:
    strb r0, [r1]
    .Lauto_08018C38:
    ldr r0, [pc, #0x28]
    add r0, sb
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl GetUpgradeLevel__C9FarmHouse
    adds r5, r0, #0
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .Lauto_08018C68
    cmp r0, #0x27
    bne .Lauto_08018C60
    b loc_08018D5E
    .Lauto_08018C60:
    b loc_08018E56
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_08018C68:
    ldr r0, [pc, #0x94]
    add r0, sb
    ldr r6, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, [pc, #0x88]
    lsls r5, r5, #1
    adds r1, r5, r4
    ldrb r1, [r1]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r4, #1
    adds r5, r5, r4
    ldrb r1, [r5]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge loc_08018D14
    ldrh r1, [r6, #0xc]
    adds r2, r6, #0
    adds r2, #0x10
    ldr r0, [pc, #0x28]
    str r0, [sp]
    str r5, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x18]
    bl _call_via_r4
    b loc_08018D16
    .byte 0x00, 0x00, 0x58, 0x10, 0x00, 0x00
    .4byte gUnk_080F06FD
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .global loc_08018D14
    .thumb_func
    loc_08018D14:
    movs r0, #0
    .global loc_08018D16
    .thumb_func
    loc_08018D16:
    cmp r0, #0
    bne .Lauto_08018D1C
    b loc_08018E56
    .Lauto_08018D1C:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .Lauto_08018D2A
    b loc_08018E56
    .Lauto_08018D2A:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018D4A
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b loc_08018E30
    .Lauto_08018D4A:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_08018D56
    b loc_08018E52
    .Lauto_08018D56:
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b loc_08018E48
    .global loc_08018D5E
    .thumb_func
    loc_08018D5E:
    ldr r0, [pc, #0x8c]
    add r0, sb
    ldr r5, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, [pc, #0x7c]
    ldrb r1, [r4]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldrb r1, [r4, #1]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r4, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge loc_08018E00
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b loc_08018E02
    .byte 0x58, 0x10, 0x00, 0x00
    .4byte gUnk_080F06FD
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .global loc_08018E00
    .thumb_func
    loc_08018E00:
    movs r0, #0
    .global loc_08018E02
    .thumb_func
    loc_08018E02:
    cmp r0, #0
    beq .Lauto_08018E56
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018E56
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018E38
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    .global loc_08018E30
    .thumb_func
    loc_08018E30:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018E52
    .Lauto_08018E38:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018E52
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    .global loc_08018E48
    .thumb_func
    loc_08018E48:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .global loc_08018E52
    .thumb_func
    loc_08018E52:
    .Lauto_08018E52:
    movs r0, #0
    strb r0, [r7]
    .global loc_08018E56
    .thumb_func
    loc_08018E56:
    .Lauto_08018E56:
    ldr r4, [pc, #0x3c]
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .Lauto_08018E62
    b .Lauto_08018FC6
    .Lauto_08018E62:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .Lauto_08018E74
    b .Lauto_08018FC6
    .Lauto_08018E74:
    ldr r0, [pc, #0x20]
    add r0, sb
    ldr r0, [r0]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    beq .Lauto_08018EE0
    cmp r0, #1
    blo .Lauto_08018E9C
    cmp r0, #2
    beq .Lauto_08018F20
    b .Lauto_08018FC6
    .byte 0x00, 0x00, 0x68, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_08018E9C:
    ldr r4, [r4]
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xa0
    subs r1, r1, r0
    mov r8, r1
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    adds r6, r5, #0
    adds r6, #0x28
    .Lauto_08018ECE:
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .Lauto_08018F6E
    b .Lauto_08018F98
    .Lauto_08018EE0:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8c
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    b .Lauto_08018ECE
    .Lauto_08018F20:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xac
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018F98
    .Lauto_08018F6E:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x18]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #8]
    bl _call_via_r4
    b .Lauto_08018F9A
    .byte 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018F98:
    movs r0, #0
    .Lauto_08018F9A:
    cmp r0, #0
    beq .Lauto_08018FC6
    adds r4, r5, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_08018FC6
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
    .Lauto_08018FC6:
    ldr r1, [pc, #0x40]
    add r1, sb
    ldr r4, [r1]
    rsbs r0, r4, #0
    orrs r0, r4
    cmp r0, #0
    blt .Lauto_08018FD6
    b .Lauto_08019296
    .Lauto_08018FD6:
    adds r5, r1, #0
    ldrb r2, [r5, #8]
    cmp r2, #0
    beq .Lauto_0801903E
    ldrb r0, [r5, #9]
    subs r0, #1
    movs r2, #0
    .byte 0x68, 0x72, 0x00, 0x06, 0x00, 0x28, 0x0F, 0xD1, 0x29, 0x68, 0x8A, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xBA, 0xF0, 0x65, 0xF8, 0x00, 0x20
    .byte 0x28, 0x60, 0x14, 0xE0, 0x2C, 0x10, 0x00, 0x00, 0x2C, 0x68, 0x21, 0x1C, 0x3F, 0x31, 0x08, 0x78
    .byte 0x00, 0x28, 0x0B, 0xD1, 0x20, 0x1C, 0x28, 0x30
    bl UpdateIndexedResourceHandle
    .byte 0x80, 0x07, 0x00, 0x28
    .byte 0x05, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70, 0x00, 0xE0, 0x0A, 0x70, 0xA8, 0x7A
    .byte 0x01, 0x30, 0x07, 0x21, 0x08, 0x40, 0xA8, 0x72, 0x24, 0xE0
    .Lauto_0801903E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08019064
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    .byte 0x02, 0x1C, 0x90, 0x07, 0x00, 0x28, 0x03, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70
    .byte 0x10, 0x1C, 0x01, 0xE0
    .Lauto_08019064:
    strb r2, [r1]
    movs r0, #2
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .Lauto_08019088
    movs r4, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lauto_08019086
    cmp r1, #0
    beq .Lauto_08019086
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_08019086:
    str r4, [r5]
    .Lauto_08019088:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r2, r0, #0
    ldr r1, [pc, #0xa8]
    add r1, sb
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    ldr r0, [pc, #0xa0]
    add r0, sp
    str r6, [r0]
    ldr r5, [r1]
    rsbs r0, r5, #0
    orrs r0, r5
    cmp r0, #0
    blt .Lauto_080190C2
    b .Lauto_08019296
    .Lauto_080190C2:
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne .Lauto_080190CA
    b .Lauto_080191C4
    .Lauto_080190CA:
    ldrb r0, [r1, #0xa]
    cmp r0, #2
    bhi .Lauto_080190D2
    b .Lauto_08019296
    .Lauto_080190D2:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    movs r6, #0xc8
    lsls r6, r6, #4
    add r6, sp
    str r0, [r6]
    movs r0, #6
    ldrsh r1, [r1, r0]
    subs r2, r1, r2
    mov sl, r2
    .byte 0x80, 0x20, 0x00, 0x02, 0x40, 0x1A, 0x80, 0x46, 0x2E, 0x1C, 0x19, 0x4C, 0x6C, 0x44, 0xA9, 0x6A
    .byte 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69
    .byte 0xB9, 0xF0, 0xE2, 0xFF, 0x27, 0x1C, 0xCB, 0x21, 0x09, 0x01, 0x69, 0x44, 0x09, 0x68, 0x4B, 0x68
    .byte 0x28, 0x1C, 0x04, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x1C, 0xDA, 0xA8, 0x89
    .byte 0x29, 0x1C, 0x10, 0x31, 0x44, 0x46, 0x00, 0x94, 0x01, 0x97, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91
    .byte 0x18, 0x1C, 0xC8, 0x25, 0x2D, 0x01, 0x6D, 0x44, 0x29, 0x68, 0x52, 0x46, 0xAA, 0x23, 0x05, 0x4C
    .byte 0xB9, 0xF0, 0xC4, 0xFF, 0x09, 0xE0, 0x00, 0x00, 0x2C, 0x10, 0x00, 0x00, 0x7C, 0x0C, 0x00, 0x00
    .byte 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x00, 0xD1, 0x96, 0xE0
    .byte 0x30, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x05, 0x1C, 0x00, 0x29, 0x00, 0xD1, 0x8F, 0xE0, 0x0A, 0x48
    .byte 0x68, 0x44, 0x00, 0x68, 0x01, 0x68, 0x3A, 0x1C, 0x08, 0x32, 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x30, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x08, 0xD0, 0x39, 0x1C, 0x10, 0x31, 0x30, 0x1C
    .byte 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0, 0x7C, 0x0C, 0x00, 0x00, 0x34, 0x1C, 0x3E, 0x34
    .byte 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x39, 0x1C, 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x28, 0x70, 0x68, 0xE0
    .Lauto_080191C4:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    mov sl, r0
    movs r4, #6
    ldrsh r1, [r1, r4]
    subs r2, r1, r2
    mov r8, r2
    .byte 0x80, 0x20, 0x00, 0x02, 0x47, 0x1A, 0x15, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E
    .byte 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xB9, 0xF0, 0x6E, 0xFF
    .byte 0x26, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x43, 0x68, 0x28, 0x1C, 0x04, 0xC8
    .byte 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x14, 0xDA, 0xA8, 0x89, 0x29, 0x1C, 0x10, 0x31
    .byte 0x00, 0x97, 0x01, 0x96, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x18, 0x1C, 0x51, 0x46, 0x42, 0x46
    .byte 0xAA, 0x23, 0x03, 0x4C, 0xB9, 0xF0, 0x54, 0xFF, 0x05, 0xE0, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x2B, 0xD0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78
    .byte 0x07, 0x1C, 0x00, 0x29, 0x25, 0xD0, 0x0A, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x32, 0x1C
    .byte 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28
    .byte 0x08, 0xD0, 0x31, 0x1C, 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0
    .byte 0x7C, 0x0C, 0x00, 0x00, 0x2C, 0x1C, 0x3E, 0x34, 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x31, 0x1C
    .byte 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20
    .byte 0x38, 0x70
    .Lauto_08019296:
    movs r3, #0
    ldr r4, [pc, #0xc4]
    add r4, sp
    str r3, [r4]
    ldr r7, [pc, #0xc4]
    add r7, sb
    ldr r5, [pc, #0xc4]
    add r5, sb
    ldr r6, [pc, #0xc4]
    add r6, sp
    str r5, [r6]
    .Lauto_080192AC:
    ldr r1, [pc, #0xbc]
    add r1, sp
    ldr r1, [r1]
    ldrb r0, [r1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .Lauto_080192BE
    b .Lauto_080193E0
    .Lauto_080192BE:
    ldrh r4, [r7]
    lsls r4, r4, #3
    adds r4, #8
    ldrh r5, [r7, #2]
    lsls r5, r5, #3
    adds r5, #8
    ldr r6, [r7, #4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r3, [pc, #0x94]
    add r3, sp
    str r4, [r3]
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r5, r0
    mov sl, r0
    .byte 0x80, 0x20, 0x00, 0x02, 0x40, 0x1B, 0x80, 0x46, 0xCB, 0x25, 0x2D, 0x01, 0x6D, 0x44, 0x2D, 0x68
    .byte 0x1C, 0x48, 0x68, 0x44, 0x05, 0x60, 0x1C, 0x4C, 0x6C, 0x44, 0xB1, 0x6A, 0x0B, 0x68, 0xB2, 0x8E
    .byte 0x92, 0x00, 0xF0, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xB9, 0xF0, 0xD8, 0xFE
    .byte 0x25, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x43, 0x68, 0x30, 0x1C, 0x04, 0xC8
    .byte 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x22, 0xDA, 0xB0, 0x89, 0x31, 0x1C, 0x10, 0x31
    .byte 0x44, 0x46, 0x00, 0x94, 0x01, 0x95, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x18, 0x1C, 0x08, 0x4A
    .byte 0x6A, 0x44, 0x11, 0x68, 0x52, 0x46, 0xAA, 0x23, 0x08, 0x4C, 0xB9, 0xF0, 0xBB, 0xFE, 0x10, 0xE0
    .byte 0x84, 0x0C, 0x00, 0x00, 0x84, 0x10, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0xCC, 0x0C, 0x00, 0x00
    .byte 0x88, 0x0C, 0x00, 0x00, 0x8C, 0x0C, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x2C, 0xD0, 0x30, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x80, 0x46, 0x00, 0x29
    .byte 0x26, 0xD0, 0x0A, 0x4B, 0x6B, 0x44, 0x1B, 0x68, 0x19, 0x68, 0x2A, 0x1C, 0x08, 0x32, 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x30, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x08, 0xD0, 0x29, 0x1C
    .byte 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0, 0x8C, 0x0C, 0x00, 0x00
    .byte 0x34, 0x1C, 0x3E, 0x34, 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x29, 0x1C, 0x10, 0x31, 0x30, 0x1C
    .byte 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x44, 0x46, 0x20, 0x70
    .Lauto_080193E0:
    adds r7, #0xc
    ldr r6, [pc, #0x108]
    add r6, sp
    ldr r5, [r6]
    adds r5, #0xc
    str r5, [r6]
    ldr r1, [pc, #0x100]
    add r1, sp
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    cmp r0, #3
    bhi .Lauto_080193FC
    b .Lauto_080192AC
    .Lauto_080193FC:
    ldr r0, [pc, #0xf4]
    ldr r0, [r0]
    movs r2, #0
    movs r3, #0xc9
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    ldr r4, [pc, #0xec]
    adds r7, r0, r4
    .Lauto_0801940E:
    ldrb r0, [r7]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .Lauto_0801941A
    b .Lauto_0801953E
    .Lauto_0801941A:
    ldrh r4, [r7, #2]
    lsls r4, r4, #0x16
    lsrs r4, r4, #0x16
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r4, r0
    beq .Lauto_08019432
    b .Lauto_0801953E
    .Lauto_08019432:
    ldrb r1, [r7, #3]
    lsrs r1, r1, #2
    ldrh r4, [r7, #4]
    ldr r0, [pc, #0xc0]
    ands r4, r0
    lsls r4, r4, #6
    orrs r4, r1
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r6, [r7, #4]
    lsls r6, r6, #6
    asrs r6, r6, #0x10
    ldrb r5, [r7]
    lsls r5, r5, #0x1c
    lsrs r5, r5, #0x1e
    ldr r0, [pc, #0xac]
    add r0, sb
    movs r2, #0xc9
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #2
    adds r0, r0, r1
    ldr r0, [r0]
    mov r8, r0
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r1, [pc, #0x90]
    add r1, sp
    str r4, [r1]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r6, r0
    mov ip, r0
    .byte 0x80, 0x20, 0x00, 0x02, 0x80, 0x1B, 0x82, 0x46, 0x46, 0x46, 0xCB, 0x23, 0x1B, 0x01, 0x6B, 0x44
    .byte 0x1B, 0x68, 0x98, 0x46, 0xAB, 0x00, 0x2B, 0x43, 0x28, 0x01, 0x03, 0x43, 0xAD, 0x01, 0x2B, 0x43
    .byte 0x35, 0x1C, 0x28, 0x35, 0x44, 0x46, 0x64, 0x68, 0x15, 0x48, 0x68, 0x44, 0x04, 0x60, 0x30, 0x1C
    .byte 0x04, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x25, 0xDA, 0xB0, 0x89, 0x31, 0x1C
    .byte 0x10, 0x31, 0x54, 0x46, 0x00, 0x94, 0x01, 0x95, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x0C, 0x49
    .byte 0x69, 0x44, 0x08, 0x68, 0x09, 0x4A, 0x6A, 0x44, 0x11, 0x68, 0x62, 0x46, 0x09, 0x4C, 0xB9, 0xF0
    .byte 0xF5, 0xFD, 0x12, 0xE0, 0xCC, 0x0C, 0x00, 0x00, 0x84, 0x0C, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0xDC, 0x04, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00, 0x94, 0x0C, 0x00, 0x00
    .byte 0xD8, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x13, 0xD0, 0x34, 0x1C
    .byte 0x48, 0x34, 0x20, 0x78, 0x00, 0x28, 0x0E, 0xD0, 0x43, 0x46, 0x19, 0x68, 0x2A, 0x1C, 0x08, 0x32
    .byte 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x29, 0x1C, 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x00, 0x20, 0x20, 0x70
    .Lauto_0801953E:
    adds r7, #0xc
    movs r5, #0xc9
    lsls r5, r5, #4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    str r4, [r5]
    cmp r4, #6
    bhs .Lauto_08019552
    b .Lauto_0801940E
    .Lauto_08019552:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    ldr r5, [r0]
    cmp r5, #0x64
    blo .Lauto_08019560
    movs r5, #0
    .Lauto_08019560:
    lsls r0, r5, #2
    ldr r1, [pc, #0x24]
    add r1, sp
    ldr r1, [r1]
    adds r6, r1, r0
    ldr r2, [pc, #0x20]
    add r2, sp
    ldr r7, [r2]
    adds r4, r6, #0
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r3, #0xc7
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    cmp r0, r3
    blo .Lauto_08019590
    subs r0, r4, r1
    b .Lauto_080195D6
    .byte 0x00, 0x00, 0x98, 0x0C, 0x00, 0x00, 0xC4, 0x0C, 0x00, 0x00
    .Lauto_08019590:
    ldr r0, [pc, #0x170]
    add r0, sp
    ldr r0, [r0]
    cmp r4, r0
    beq .Lauto_080195AE
    ldr r3, [r4]
    cmp r3, #0
    beq .Lauto_080195AE
    ldr r0, [r3, #0x14]
    ldr r1, [pc, #0x164]
    add r1, sp
    ldr r2, [r0, #0x1c]
    adds r0, r3, #0
    bl _call_via_r2
    .Lauto_080195AE:
    adds r4, #4
    cmp r4, r7
    bne .Lauto_080195BA
    ldr r1, [pc, #0x154]
    add r1, sp
    ldr r4, [r1]
    .Lauto_080195BA:
    cmp r4, r6
    beq .Lauto_080195D8
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r2, #0xc7
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    cmp r0, r2
    blo .Lauto_08019590
    ldr r3, [pc, #0x13c]
    add r3, sp
    ldr r3, [r3]
    subs r0, r4, r3
    .Lauto_080195D6:
    asrs r5, r0, #2
    .Lauto_080195D8:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    str r5, [r0]
    ldr r4, [pc, #0x12c]
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4, #8]
    add r0, sp, #0x14
    bl WriteSprites__21WorldSpriteDrawBufferR25HardwareSpriteBufferState
    ldr r5, [pc, #0x124]
    add r5, sp
    ldr r0, [r5]
    add r6, sp, #0x18
    cmp r6, r0
    beq .Lauto_08019604
    adds r1, r6, #0
    .Lauto_080195FC:
    ldr r2, [pc, #0x118]
    adds r0, r0, r2
    cmp r1, r0
    bne .Lauto_080195FC
    .global loc_08019604
    .thumb_func
    loc_08019604:
    .Lauto_08019604:
    mov r3, sb
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #1
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    ldr r5, [pc, #0x100]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0xec]
    add r6, sp
    ldr r6, [r6]
    ldr r7, [r6]
    adds r2, r1, #0
    eors r2, r0
    movs r3, #0xca
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r4, #0
    ldr r5, [pc, #0xe8]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0xe4]
    add r6, sp
    ldr r6, [r6]
    ldrb r6, [r6]
    ldr r0, [pc, #0xe0]
    add r0, sp
    str r6, [r0]
    cmp r4, r6
    blo .Lauto_08019650
    b .Lauto_080198A4
    .Lauto_08019650:
    ldr r1, [pc, #0xc8]
    add r1, sp
    ldr r1, [r1]
    ldr r2, [pc, #0xd4]
    adds r0, r1, r2
    ldr r2, [pc, #0xc4]
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov sl, r0
    ldrb r0, [r0, #9]
    lsrs r0, r0, #7
    adds r2, #1
    ldr r4, [pc, #0xbc]
    add r4, sp
    str r2, [r4]
    cmp r0, #0
    beq .Lauto_0801967C
    b .Lauto_0801988C
    .Lauto_0801967C:
    mov r5, sl
    movs r1, #9
    ldrsb r1, [r5, r1]
    ldr r6, [pc, #0x98]
    add r6, sp
    ldr r2, [r6]
    adds r2, #0x20
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    mov r8, r2
    mov r4, r8
    adds r4, #0x82
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_080196A6
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    beq .Lauto_080196A6
    b .Lauto_0801988C
    .Lauto_080196A6:
    mov r1, r8
    adds r1, #0x60
    movs r0, #0xca
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    cmp r0, #0
    bne .Lauto_080196B8
    mov r1, r8
    .Lauto_080196B8:
    mov r3, sl
    ldrb r2, [r3, #8]
    lsls r2, r2, #5
    ldr r5, [pc, #0x74]
    adds r2, r2, r5
    add r0, sp, #0x14
    movs r3, #0x20
    bl __21DmaTransferDescriptorPCvPvUi
    mov r6, sp
    adds r6, #0x14
    ldr r0, [pc, #0x68]
    add r0, sp
    str r6, [r0]
    ldr r1, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r1, r0
    beq .Lauto_0801973C
    cmp r1, #0
    beq .Lauto_080196EC
    adds r0, r1, #0
    add r1, sp, #0x14
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080196EC:
    ldr r0, [r7, #4]
    adds r0, #0x10
    str r0, [r7, #4]
    mov r8, r4
    ldr r0, [pc, #0x28]
    add r0, sp
    ldr r6, [r0]
    adds r6, #1
    ldr r0, [pc, #0x30]
    add r0, sp
    str r6, [r0]
    b .Lauto_08019872
    .byte 0x74, 0x0C, 0x00, 0x00, 0x28, 0x0C, 0x00, 0x00, 0x98, 0x0C, 0x00, 0x00, 0x6C, 0x0C, 0x00, 0x00
    .byte 0xC8, 0x0C, 0x00, 0x00, 0xFC, 0xFD, 0xFF, 0xFF, 0x9C, 0x0C, 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00
    .byte 0xBC, 0x0C, 0x00, 0x00, 0xA8, 0x0C, 0x00, 0x00, 0x78, 0x0B, 0x00, 0x00, 0xB4, 0x0C, 0x00, 0x00
    .byte 0x00, 0x02, 0x00, 0x05, 0xAC, 0x0C, 0x00, 0x00
    .Lauto_0801973C:
    ldr r2, [pc, #0x40]
    add r2, sp
    str r1, [r2]
    movs r0, #1
    ldr r2, [pc, #0x3c]
    add r2, sp
    str r0, [r2]
    ldr r0, [r7]
    subs r0, r1, r0
    asrs r4, r0, #4
    ldr r0, [pc, #0x34]
    add r0, sp
    str r4, [r0]
    ldr r1, [r2]
    cmp r4, r1
    bhs .Lauto_0801975E
    adds r0, r2, #0
    .Lauto_0801975E:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_08019790
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    ldr r5, [pc, #0x1c]
    add r5, sp
    str r4, [r5]
    cmp r0, #0
    bne .Lauto_08019798
    adds r0, r4, #0
    bl RetryMemoryAllocation
    b .Lauto_08019798
    .byte 0xDC, 0x0C, 0x00, 0x00, 0x68, 0x0C, 0x00, 0x00, 0x64, 0x0C, 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00
    .Lauto_08019790:
    movs r0, #0
    ldr r6, [pc, #0x70]
    add r6, sp
    str r0, [r6]
    .Lauto_08019798:
    adds r5, r0, #0
    ldr r0, [pc, #0x6c]
    add r0, sp
    str r5, [r0]
    ldr r2, [r7]
    adds r3, r5, #0
    movs r1, #0x82
    add r8, r1
    ldr r5, [pc, #0x60]
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    ldr r5, [pc, #0x5c]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0x5c]
    add r6, sp
    ldr r6, [r6]
    cmp r2, r6
    beq .Lauto_080197DE
    .Lauto_080197C0:
    cmp r3, #0
    beq .Lauto_080197D0
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080197D0:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [pc, #0x3c]
    add r0, sp
    ldr r0, [r0]
    cmp r2, r0
    bne .Lauto_080197C0
    .Lauto_080197DE:
    adds r5, r3, #0
    ldr r0, [pc, #0x34]
    add r0, sp
    ldr r0, [r0]
    cmp r0, #1
    bne .Lauto_08019820
    cmp r5, #0
    beq .Lauto_080197FE
    adds r0, r5, #0
    ldr r2, [pc, #0x28]
    add r2, sp
    ldr r1, [r2]
    ldm r1!, {r3, r4, r6}
    stm r0!, {r3, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080197FE:
    adds r5, #0x10
    b .Lauto_08019846
    .byte 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00, 0xD8, 0x0C, 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00, 0xB4, 0x0C
    .byte 0x00, 0x00, 0xDC, 0x0C, 0x00, 0x00, 0x68, 0x0C, 0x00, 0x00, 0xAC, 0x0C, 0x00, 0x00
    .Lauto_08019820:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lauto_08019844
    .Lauto_08019828:
    cmp r2, #0
    beq .Lauto_0801983C
    adds r0, r2, #0
    ldr r4, [pc, #0xd0]
    add r4, sp
    ldr r1, [r4]
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_0801983C:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Lauto_08019828
    .Lauto_08019844:
    adds r5, r2, #0
    .Lauto_08019846:
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .Lauto_08019856
    .Lauto_08019850:
    adds r1, #0x10
    cmp r1, r2
    bne .Lauto_08019850
    .Lauto_08019856:
    cmp r0, #0
    beq .Lauto_0801985E
    bl free
    .Lauto_0801985E:
    ldr r6, [pc, #0xa4]
    add r6, sp
    ldr r6, [r6]
    ldr r1, [pc, #0xa0]
    add r1, sp
    ldr r1, [r1]
    adds r0, r6, r1
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
    .Lauto_08019872:
    movs r0, #0
    mov r3, r8
    strb r0, [r3]
    mov r4, sl
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    bne .Lauto_0801988C
    .byte 0x60, 0x7A, 0xC0, 0x09, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0xA0, 0x72
    .Lauto_0801988C:
    ldr r5, [pc, #0x7c]
    add r5, sp
    ldr r5, [r5]
    ldr r6, [pc, #0x7c]
    add r6, sp
    str r5, [r6]
    ldr r0, [pc, #0x78]
    add r0, sp
    ldr r6, [r0]
    cmp r5, r6
    bhs .Lauto_080198A4
    b .Lauto_08019650
    .Lauto_080198A4:
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    ldr r3, [pc, #0x6c]
    add r3, sp
    ldr r3, [r3]
    ldrb r2, [r3]
    movs r4, #0xcc
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    ldrb r4, [r4]
    cmp r2, r4
    bhs .Lauto_080198EA
    movs r5, #0xff
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r6, [pc, #0x50]
    adds r0, r0, r6
    adds r3, r0, r1
    ldr r1, [pc, #0x50]
    add r1, sb
    .Lauto_080198D2:
    ldrb r4, [r3]
    lsrs r0, r4, #7
    cmp r0, #0
    bne .Lauto_080198E0
    adds r0, r4, #0
    orrs r0, r5
    strb r0, [r3]
    .Lauto_080198E0:
    adds r3, #0xc
    adds r2, #1
    ldrb r0, [r1]
    cmp r2, r0
    blo .Lauto_080198D2
    .Lauto_080198EA:
    movs r3, #0xce
    lsls r3, r3, #4
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xAC, 0x0C, 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00, 0xD8, 0x0C, 0x00, 0x00, 0xB4, 0x0C
    .byte 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00, 0xA8, 0x0C, 0x00, 0x00, 0xBC, 0x0C, 0x00, 0x00, 0x81, 0x0B
    .byte 0x00, 0x00, 0xB1, 0x0D, 0x00, 0x00
    .else
    .align 2, 0

    thumb_func_start Draw__14GameSceneWorldRC21GameObjectDrawContext
Draw__14GameSceneWorldRC21GameObjectDrawContext: @ 0x080182C8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L080184E4 @ =0xFFFFF320
    add sp, r4
    mov sb, r0
    ldr r0, .L080184E8 @ =0x00000C6C
    add r0, sp
    str r1, [r0]
    movs r0, #0
    ldr r1, .L080184EC @ =0x00000C58
    add r1, sp
    str r0, [r1]
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    movs r2, #0x20
    ldr r0, .L080184EC @ =0x00000C58
    add r0, sp
    ldr r0, [r0]
.L080182F4:
    strb r0, [r1]
    subs r2, #1
    adds r1, #1
    cmp r2, #0
    bgt .L080182F4
    ldr r0, .L080184F0 @ =0x00001024
    add r0, sb
    ldr r2, [r0]
    ldr r3, .L080184E8 @ =0x00000C6C
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r4, r2, #0
    adds r4, #0x9c
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018320
    adds r0, r2, #0
    bl PrepareResources__22EntityAuxiliarySpritesR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
.L08018320:
    ldr r0, .L080184F4 @ =0x0000107C
    add r0, sb
    ldr r2, [r0]
    cmp r2, #0
    beq .L08018346
    ldr r4, .L080184E8 @ =0x00000C6C
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4]
    adds r4, r2, #0
    adds r4, #0xe5
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018346
    adds r0, r2, #0
    bl PrepareResources__22GameSceneWeatherEffectR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
.L08018346:
    mov r5, sb
    ldr r0, [r5, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r4, [r1]
    ldr r6, .L080184E8 @ =0x00000C6C
    add r6, sp
    ldr r6, [r6]
    ldr r1, [r6]
    ldr r2, [r6, #4]
    ldr r3, [r6, #0xc]
    ldr r4, [r4, #0x10]
    bl _call_via_r4
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    movs r2, #0xdb
    lsls r2, r2, #4
    add r2, sb
    ldrb r0, [r2]
    ldr r1, .L080184F8 @ =0x00000DB1
    add r1, sb
    strb r0, [r1]
    movs r3, #0
    ldr r6, .L080184FC @ =0x00000CBC
    add r6, sp
    str r2, [r6]
    movs r0, #0xcc
    lsls r0, r0, #4
    add r0, sp
    str r1, [r0]
    ldrb r1, [r1]
    cmp r3, r1
    bhs .L080183BE
    movs r5, #0xde
    lsls r5, r5, #1
    add r5, sb
    ldr r2, .L08018500 @ =0x00000D1D
    add r2, sb
.L08018396:
    ldrb r0, [r2]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .L080183B0
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r1, r0, #5
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r1, r5, r1
    adds r1, #0x80
    movs r0, #0xff
    strb r0, [r1]
.L080183B0:
    adds r2, #0xc
    adds r3, #1
    ldr r6, .L08018504 @ =0x00000C15
    adds r0, r4, r6
    ldrb r0, [r0]
    cmp r3, r0
    blo .L08018396
.L080183BE:
    ldr r1, .L08018508 @ =0x00000C14
    adds r0, r4, r1
    movs r2, #0
    strb r2, [r0]
    ldr r3, .L080184E8 @ =0x00000C6C
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3, #8]
    ldrb r1, [r0]
    movs r0, #0x7c
    subs r0, r0, r1
    movs r4, #0xc7
    lsls r4, r4, #4
    add r4, sp
    str r0, [r4]
    cmp r0, #0x80
    bls .L080183E4
    bl .L08019870
.L080183E4:
    add r0, sp, #0x14
    strb r2, [r0]
    add r0, sp, #0x18
    movs r1, #3
    mov r5, sb
    ldr r4, [r5]
    mov r6, sb
    adds r6, #8
    ldr r2, .L0801850C @ =0x00000C5C
    add r2, sp
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r5, #0xcc
    lsls r5, r5, #1
    add r5, sb
    ldr r2, .L08018510 @ =0x00000CC4
    add r2, sp
    str r5, [r2]
    ldr r3, .L08018514 @ =0x00000828
    add r3, sp
    ldr r5, .L08018518 @ =0x00000CC8
    add r5, sp
    str r3, [r5]
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L0801841C:
    str r3, [r0]
    movs r5, #0x81
    lsls r5, r5, #2
    adds r0, r0, r5
    subs r1, #1
    cmp r1, r2
    bne .L0801841C
    ldr r1, [r4, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldr r5, .L0801851C @ =0x00000C28
    add r5, sp
    ldr r2, .L080184E8 @ =0x00000C6C
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    ldr r2, [r2, #4]
    str r1, [r5]
    str r2, [r5, #4]
    add r1, sp, #0x14
    str r1, [r5, #8]
    strh r4, [r5, #0xc]
    strh r0, [r5, #0xe]
    ldr r2, .L08018520 @ =0x00000C98
    add r2, sp
    str r6, [r2]
    ldr r3, .L08018524 @ =0x00000C74
    add r3, sp
    str r6, [r3]
    ldr r4, [r2]
    ldr r1, [r4]
    cmp r1, #0
    beq .L0801847A
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #0x1c]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r2
.L0801847A:
    ldr r0, .L080184F4 @ =0x0000107C
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .L0801848A
    add r1, sp, #0x14
    bl Draw__22GameSceneWeatherEffectP21WorldSpriteDrawBuffer
.L0801848A:
    ldr r0, .L08018528 @ =0x00001028
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .L0801849C
    ldr r2, [r5]
    add r1, sp, #0x14
    bl Draw__18WorldSpriteEffectsP21WorldSpriteDrawBufferR16HardwareDmaQueue
.L0801849C:
    ldr r1, [r5]
    ldr r2, [r5, #8]
    ldr r0, .L0801850C @ =0x00000C5C
    add r0, sp
    str r1, [r0]
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    str r2, [r5, #4]
    ldr r0, .L0801852C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L080184BC
    b .L0801887E
.L080184BC:
    movs r5, #0
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018530
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r2, r0, #0
    lsls r0, r2, #0x1e
    cmp r0, #0
    bge .L080184E0
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
.L080184E0:
    adds r0, r2, #0
    b .L08018536
    .align 2, 0
.L080184E4: .4byte 0xFFFFF320
.L080184E8: .4byte 0x00000C6C
.L080184EC: .4byte 0x00000C58
.L080184F0: .4byte 0x00001024
.L080184F4: .4byte 0x0000107C
.L080184F8: .4byte 0x00000DB1
.L080184FC: .4byte 0x00000CBC
.L08018500: .4byte 0x00000D1D
.L08018504: .4byte 0x00000C15
.L08018508: .4byte 0x00000C14
.L0801850C: .4byte 0x00000C5C
.L08018510: .4byte 0x00000CC4
.L08018514: .4byte 0x00000828
.L08018518: .4byte 0x00000CC8
.L0801851C: .4byte 0x00000C28
.L08018520: .4byte 0x00000C98
.L08018524: .4byte 0x00000C74
.L08018528: .4byte 0x00001028
.L0801852C: .4byte 0x0000105C
.L08018530:
    movs r0, #0
    strb r0, [r1]
    movs r0, #2
.L08018536:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L0801854A
    movs r0, #0x83
    lsls r0, r0, #5
    add r0, sb
    ldrb r0, [r0]
    cmp r0, #0
    beq .L0801854A
    movs r5, #1
.L0801854A:
    cmp r5, #0
    beq .L08018578
    movs r0, #0x83
    lsls r0, r0, #5
    add r0, sb
    movs r4, #0
    strb r4, [r0]
    ldr r0, .L08018598 @ =0x0000105C
    add r0, sb
    ldr r5, [r0]
    adds r0, r5, #0
    adds r0, #0x28
    movs r1, #1
    bl ResolveIndexedResourceHandle
    adds r0, r5, #0
    adds r0, #0x3c
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r4, [r0]
    adds r0, #1
    strb r1, [r0]
.L08018578:
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    subs r0, #0xa
    cmp r0, #0x1d
    bls .L0801858C
    b .L0801887E
.L0801858C:
    lsls r0, r0, #2
    ldr r1, .L0801859C @ =.L080185A0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08018598: .4byte 0x0000105C
.L0801859C: .4byte .L080185A0
.L080185A0: @ jump table
    .4byte .L08018770 @ case 0
    .4byte .L0801887E @ case 1
    .4byte .L0801887E @ case 2
    .4byte .L0801887E @ case 3
    .4byte .L0801887E @ case 4
    .4byte .L0801887E @ case 5
    .4byte .L0801887E @ case 6
    .4byte .L0801887E @ case 7
    .4byte .L080186E2 @ case 8
    .4byte .L0801887E @ case 9
    .4byte .L0801887E @ case 10
    .4byte .L0801887E @ case 11
    .4byte .L0801887E @ case 12
    .4byte .L0801887E @ case 13
    .4byte .L0801887E @ case 14
    .4byte .L0801887E @ case 15
    .4byte .L0801887E @ case 16
    .4byte .L0801878C @ case 17
    .4byte .L0801887E @ case 18
    .4byte .L08018618 @ case 19
    .4byte .L0801887E @ case 20
    .4byte .L0801887E @ case 21
    .4byte .L0801887E @ case 22
    .4byte .L0801887E @ case 23
    .4byte .L0801887E @ case 24
    .4byte .L0801887E @ case 25
    .4byte .L0801887E @ case 26
    .4byte .L0801887E @ case 27
    .4byte .L0801887E @ case 28
    .4byte .L08018754 @ case 29
.L08018618:
    ldr r0, .L080186A0 @ =0x0000105C
    add r0, sb
    ldr r5, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r4, #0x30
    subs r0, r4, r0
    mov r8, r0
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r7, r4, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, .L080186A4 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080186B0
.L0801867C:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L080186A8 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xff
    ldr r4, .L080186AC @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080186B2
    .align 2, 0
.L080186A0: .4byte 0x0000105C
.L080186A4: .4byte 0x00000C38
.L080186A8: .4byte 0x01FFFFFF
.L080186AC: .4byte SubmitWorldSpriteRecords
.L080186B0:
    movs r0, #0
.L080186B2:
    cmp r0, #0
    bne .L080186B8
    b .L0801887E
.L080186B8:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L080186C6
    b .L0801887E
.L080186C6:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080186E0
    b .L08018852
.L080186E0:
    b .L08018860
.L080186E2:
    ldr r0, .L0801874C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x68
.L080186F6:
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018750 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L0801867C
    b .L080186B0
    .align 2, 0
.L0801874C: .4byte 0x0000105C
.L08018750: .4byte 0x00000C38
.L08018754:
    ldr r0, .L0801876C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x18
    b .L080186F6
    .align 2, 0
.L0801876C: .4byte 0x0000105C
.L08018770:
    ldr r0, .L08018788 @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x38
    b .L080186F6
    .align 2, 0
.L08018788: .4byte 0x0000105C
.L0801878C:
    ldr r0, .L08018818 @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x68
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L0801881C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018828
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018820 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xff
    ldr r4, .L08018824 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801882A
    .align 2, 0
.L08018818: .4byte 0x0000105C
.L0801881C: .4byte 0x00000C38
.L08018820: .4byte 0x01FFFFFF
.L08018824: .4byte SubmitWorldSpriteRecords
.L08018828:
    movs r0, #0
.L0801882A:
    cmp r0, #0
    beq .L0801887E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L0801887E
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018860
.L08018852:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L0801887A
.L08018860:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L0801887A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L0801887A:
    movs r0, #0
    strb r0, [r7]
.L0801887E:
    ldr r0, .L080188AC @ =0x00001064
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L0801888A
    b .L080189A6
.L0801888A:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080188B0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L080188B4
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L080188B2
    .align 2, 0
.L080188AC: .4byte 0x00001064
.L080188B0:
    movs r0, #0
.L080188B2:
    strb r0, [r1]
.L080188B4:
    ldr r0, .L08018940 @ =0x00001064
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x58
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x10
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018944 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018950
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018948 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L0801894C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018952
    .align 2, 0
.L08018940: .4byte 0x00001064
.L08018944: .4byte 0x00000C38
.L08018948: .4byte 0x01FFFFFF
.L0801894C: .4byte SubmitWorldSpriteRecords
.L08018950:
    movs r0, #0
.L08018952:
    cmp r0, #0
    beq .L080189A6
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L080189A6
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018988
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080189A2
.L08018988:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080189A2
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080189A2:
    movs r0, #0
    strb r0, [r7]
.L080189A6:
    movs r3, #0
    ldr r4, .L08018A5C @ =0x00000C78
    add r4, sp
    str r3, [r4]
    movs r5, #0xde
    lsls r5, r5, #2
    movs r6, #0xcd
    lsls r6, r6, #4
    add r6, sp
    str r5, [r6]
    ldr r0, .L08018A60 @ =0x0000106C
    add r0, sb
    ldr r1, .L08018A64 @ =0x00000CD4
    add r1, sp
    str r0, [r1]
.L080189C4:
    ldr r2, .L08018A64 @ =0x00000CD4
    add r2, sp
    ldr r2, [r2]
    ldr r4, [r2]
    cmp r4, #0
    beq .L08018ACA
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r5, #0xcd
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    subs r0, r5, r0
    mov r8, r0
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xf0
    lsls r1, r1, #1
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, .L08018A68 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018A74
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    ldr r4, .L08018A6C @ =0x01FFFFFF
    str r4, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018A70 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018A76
    .align 2, 0
.L08018A5C: .4byte 0x00000C78
.L08018A60: .4byte 0x0000106C
.L08018A64: .4byte 0x00000CD4
.L08018A68: .4byte 0x00000C38
.L08018A6C: .4byte 0x01FFFFFF
.L08018A70: .4byte SubmitWorldSpriteRecords
.L08018A74:
    movs r0, #0
.L08018A76:
    cmp r0, #0
    beq .L08018ACA
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018ACA
    mov r0, sl
    ldr r1, [r0]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018AAC
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018AC6
.L08018AAC:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018AC6
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018AC6:
    movs r0, #0
    strb r0, [r7]
.L08018ACA:
    movs r2, #0xcd
    lsls r2, r2, #4
    add r2, sp
    ldr r1, [r2]
    adds r1, #0x28
    str r1, [r2]
    ldr r4, .L08018B1C @ =0x00000CD4
    add r4, sp
    ldr r3, [r4]
    adds r3, #4
    str r3, [r4]
    ldr r6, .L08018B20 @ =0x00000C78
    add r6, sp
    ldr r5, [r6]
    adds r5, #1
    str r5, [r6]
    cmp r5, #1
    bhi .L08018AF0
    b .L080189C4
.L08018AF0:
    ldr r4, .L08018B24 @ =0x00001074
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .L08018AFC
    b .L08018D76
.L08018AFC:
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #2
    bne .L08018B0E
    b .L08018C8E
.L08018B0E:
    cmp r0, #2
    bgt .L08018B28
    cmp r0, #0
    bne .L08018B18
    b .L08018C68
.L08018B18:
    b .L08018D76
    .align 2, 0
.L08018B1C: .4byte 0x00000CD4
.L08018B20: .4byte 0x00000C78
.L08018B24: .4byte 0x00001074
.L08018B28:
    cmp r0, #3
    beq .L08018BFA
    cmp r0, #7
    beq .L08018B32
    b .L08018D76
.L08018B32:
    ldr r4, [r4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x86
    subs r7, r1, r0
    adds r5, r4, #0
    movs r4, #0xcb
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    mov sl, r4
    ldr r4, .L08018BBC @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018BC8
.L08018B98:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018BC0 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018BC4 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018BCA
    .align 2, 0
.L08018BBC: .4byte 0x00000C38
.L08018BC0: .4byte 0x01FFFFFF
.L08018BC4: .4byte SubmitWorldSpriteRecords
.L08018BC8:
    movs r0, #0
.L08018BCA:
    cmp r0, #0
    bne .L08018BD0
    b .L08018D76
.L08018BD0:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L08018BDE
    b .L08018D76
.L08018BDE:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018BF8
    b .L08018D4A
.L08018BF8:
    b .L08018D58
.L08018BFA:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x9b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x76
.L08018C1E:
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018C64 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L08018B98
    b .L08018BC8
    .align 2, 0
.L08018C64: .4byte 0x00000C38
.L08018C68:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xb0
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    b .L08018C1E
.L08018C8E:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x88
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018D14 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018D20
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018D18 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018D1C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018D22
    .align 2, 0
.L08018D14: .4byte 0x00000C38
.L08018D18: .4byte 0x01FFFFFF
.L08018D1C: .4byte SubmitWorldSpriteRecords
.L08018D20:
    movs r0, #0
.L08018D22:
    cmp r0, #0
    beq .L08018D76
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018D76
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018D58
.L08018D4A:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018D72
.L08018D58:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018D72
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018D72:
    movs r0, #0
    strb r0, [r7]
.L08018D76:
    ldr r0, .L08018E04 @ =0x00001078
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    beq .L08018E6E
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r1, .L08018E08 @ =0x00000235
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x13
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018E0C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018E18
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018E10 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018E14 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018E1A
    .align 2, 0
.L08018E04: .4byte 0x00001078
.L08018E08: .4byte 0x00000235
.L08018E0C: .4byte 0x00000C38
.L08018E10: .4byte 0x01FFFFFF
.L08018E14: .4byte SubmitWorldSpriteRecords
.L08018E18:
    movs r0, #0
.L08018E1A:
    cmp r0, #0
    beq .L08018E6E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018E6E
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018E50
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018E6A
.L08018E50:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018E6A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018E6A:
    movs r0, #0
    strb r0, [r7]
.L08018E6E:
    ldr r0, .L08018E9C @ =0x00001058
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L08018E7A
    b .L080190C2
.L08018E7A:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018EA0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L08018EA4
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L08018EA2
    .align 2, 0
.L08018E9C: .4byte 0x00001058
.L08018EA0:
    movs r0, #0
.L08018EA2:
    strb r0, [r1]
.L08018EA4:
    ldr r0, .L08018ED0 @ =0x00001038
    add r0, sb
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl GetUpgradeLevel__C9FarmHouse
    adds r5, r0, #0
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .L08018ED4
    cmp r0, #0x27
    bne .L08018ECC
    b .L08018FCA
.L08018ECC:
    b .L080190C2
    .align 2, 0
.L08018ED0: .4byte 0x00001038
.L08018ED4:
    ldr r0, .L08018F6C @ =0x00001058
    add r0, sb
    ldr r6, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, .L08018F70 @ =gUnk_080F06FD
    lsls r5, r5, #1
    adds r1, r5, r4
    ldrb r1, [r1]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r4, #1
    adds r5, r5, r4
    ldrb r1, [r5]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, .L08018F74 @ =0x00000C38
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018F80
    ldrh r1, [r6, #0xc]
    adds r2, r6, #0
    adds r2, #0x10
    ldr r0, .L08018F78 @ =0x01FFFFFF
    str r0, [sp]
    str r5, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08018F7C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018F82
    .align 2, 0
.L08018F6C: .4byte 0x00001058
.L08018F70: .4byte gUnk_080F06FD
.L08018F74: .4byte 0x00000C38
.L08018F78: .4byte 0x01FFFFFF
.L08018F7C: .4byte SubmitWorldSpriteRecords
.L08018F80:
    movs r0, #0
.L08018F82:
    cmp r0, #0
    bne .L08018F88
    b .L080190C2
.L08018F88:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L08018F96
    b .L080190C2
.L08018F96:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018FB6
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b .L0801909C
.L08018FB6:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018FC2
    b .L080190BE
.L08018FC2:
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b .L080190B4
.L08018FCA:
    ldr r0, .L08019058 @ =0x00001058
    add r0, sb
    ldr r5, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, .L0801905C @ =gUnk_080F06FD
    ldrb r1, [r4]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldrb r1, [r4, #1]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, .L08019060 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r4, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L0801906C
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08019064 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08019068 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801906E
    .align 2, 0
.L08019058: .4byte 0x00001058
.L0801905C: .4byte gUnk_080F06FD
.L08019060: .4byte 0x00000C38
.L08019064: .4byte 0x01FFFFFF
.L08019068: .4byte SubmitWorldSpriteRecords
.L0801906C:
    movs r0, #0
.L0801906E:
    cmp r0, #0
    beq .L080190C2
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L080190C2
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080190A4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
.L0801909C:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080190BE
.L080190A4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080190BE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
.L080190B4:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080190BE:
    movs r0, #0
    strb r0, [r7]
.L080190C2:
    ldr r4, .L08019100 @ =0x00001068
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .L080190CE
    b .L08019232
.L080190CE:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .L080190E0
    b .L08019232
.L080190E0:
    ldr r0, .L08019104 @ =0x00001038
    add r0, sb
    ldr r0, [r0]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    beq .L0801914C
    cmp r0, #1
    blo .L08019108
    cmp r0, #2
    beq .L0801918C
    b .L08019232
    .align 2, 0
.L08019100: .4byte 0x00001068
.L08019104: .4byte 0x00001038
.L08019108:
    ldr r4, [r4]
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xa0
    subs r1, r1, r0
    mov r8, r1
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    adds r6, r5, #0
    adds r6, #0x28
.L0801913A:
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L080191DA
    b .L08019204
.L0801914C:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8c
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    b .L0801913A
.L0801918C:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xac
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08019204
.L080191DA:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L080191FC @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08019200 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08019206
    .align 2, 0
.L080191FC: .4byte 0x01FFFFFF
.L08019200: .4byte SubmitWorldSpriteRecords
.L08019204:
    movs r0, #0
.L08019206:
    cmp r0, #0
    beq .L08019232
    adds r4, r5, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08019232
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
.L08019232:
    ldr r1, .L08019274 @ =0x0000102C
    add r1, sb
    ldr r4, [r1]
    rsbs r0, r4, #0
    orrs r0, r4
    cmp r0, #0
    blt .L08019242
    b .L08019502
.L08019242:
    adds r5, r1, #0
    ldrb r2, [r5, #8]
    cmp r2, #0
    beq .L080192AA
    ldrb r0, [r5, #9]
    subs r0, #1
    movs r2, #0
    strb r0, [r5, #9]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08019278
    ldr r1, [r5]
    cmp r2, r1
    beq .L0801926E
    cmp r1, #0
    beq .L0801926E
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801926E:
    movs r0, #0
    str r0, [r5]
    b .L0801929E
    .align 2, 0
.L08019274: .4byte 0x0000102C
.L08019278:
    ldr r4, [r5]
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L0801929C
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L0801929E
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
    b .L0801929E
.L0801929C:
    strb r2, [r1]
.L0801929E:
    ldrb r0, [r5, #0xa]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r5, #0xa]
    b .L080192F4
.L080192AA:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080192D0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r2, r0, #0
    lsls r0, r2, #0x1e
    cmp r0, #0
    bge .L080192CC
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
.L080192CC:
    adds r0, r2, #0
    b .L080192D4
.L080192D0:
    strb r2, [r1]
    movs r0, #2
.L080192D4:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L080192F4
    movs r4, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L080192F2
    cmp r1, #0
    beq .L080192F2
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080192F2:
    str r4, [r5]
.L080192F4:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r2, r0, #0
    ldr r1, .L080193BC @ =0x0000102C
    add r1, sb
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    ldr r0, .L080193C0 @ =0x00000C7C
    add r0, sp
    str r6, [r0]
    ldr r5, [r1]
    rsbs r0, r5, #0
    orrs r0, r5
    cmp r0, #0
    blt .L0801932E
    b .L08019502
.L0801932E:
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne .L08019336
    b .L08019430
.L08019336:
    ldrb r0, [r1, #0xa]
    cmp r0, #2
    bhi .L0801933E
    b .L08019502
.L0801933E:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    movs r6, #0xc8
    lsls r6, r6, #4
    add r6, sp
    str r0, [r6]
    movs r0, #6
    ldrsh r1, [r1, r0]
    subs r2, r1, r2
    mov sl, r2
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r1
    mov r8, r0
    adds r6, r5, #0
    ldr r4, .L080193C4 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r7, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080193CC
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    mov r4, r8
    str r4, [sp]
    str r7, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    movs r5, #0xc8
    lsls r5, r5, #4
    add r5, sp
    ldr r1, [r5]
    mov r2, sl
    movs r3, #0xaa
    ldr r4, .L080193C8 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080193CE
    .align 2, 0
.L080193BC: .4byte 0x0000102C
.L080193C0: .4byte 0x00000C7C
.L080193C4: .4byte 0x00000C38
.L080193C8: .4byte SubmitWorldSpriteRecords
.L080193CC:
    movs r0, #0
.L080193CE:
    cmp r0, #0
    bne .L080193D4
    b .L08019502
.L080193D4:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r5, r0, #0
    cmp r1, #0
    bne .L080193E2
    b .L08019502
.L080193E2:
    ldr r0, .L0801940C @ =0x00000C7C
    add r0, sp
    ldr r0, [r0]
    ldr r1, [r0]
    adds r2, r7, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08019410
    adds r1, r7, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L0801942A
    .align 2, 0
.L0801940C: .4byte 0x00000C7C
.L08019410:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L0801942A
    adds r1, r7, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L0801942A:
    movs r0, #0
    strb r0, [r5]
    b .L08019502
.L08019430:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    mov sl, r0
    movs r4, #6
    ldrsh r1, [r1, r4]
    subs r2, r1, r2
    mov r8, r2
    movs r0, #0x80
    lsls r0, r0, #8
    subs r7, r0, r1
    ldr r4, .L0801949C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r3, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080194A4
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    str r7, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, sl
    mov r2, r8
    movs r3, #0xaa
    ldr r4, .L080194A0 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080194A6
    .align 2, 0
.L0801949C: .4byte 0x00000C38
.L080194A0: .4byte SubmitWorldSpriteRecords
.L080194A4:
    movs r0, #0
.L080194A6:
    cmp r0, #0
    beq .L08019502
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08019502
    ldr r2, .L080194E0 @ =0x00000C7C
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080194E4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080194FE
    .align 2, 0
.L080194E0: .4byte 0x00000C7C
.L080194E4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080194FE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080194FE:
    movs r0, #0
    strb r0, [r7]
.L08019502:
    movs r3, #0
    ldr r4, .L080195CC @ =0x00000C84
    add r4, sp
    str r3, [r4]
    ldr r7, .L080195D0 @ =0x00001084
    add r7, sb
    ldr r5, .L080195D4 @ =0x00001081
    add r5, sb
    ldr r6, .L080195D8 @ =0x00000CCC
    add r6, sp
    str r5, [r6]
.L08019518:
    ldr r1, .L080195D8 @ =0x00000CCC
    add r1, sp
    ldr r1, [r1]
    ldrb r0, [r1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .L0801952A
    b .L0801964C
.L0801952A:
    ldrh r4, [r7]
    lsls r4, r4, #3
    adds r4, #8
    ldrh r5, [r7, #2]
    lsls r5, r5, #3
    adds r5, #8
    ldr r6, [r7, #4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r3, .L080195DC @ =0x00000C88
    add r3, sp
    str r4, [r3]
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r5, r0
    mov sl, r0
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r5
    mov r8, r0
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    ldr r0, .L080195E0 @ =0x00000C8C
    add r0, sp
    str r5, [r0]
    ldr r4, .L080195E4 @ =0x00000C38
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r3, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080195EC
    ldrh r0, [r6, #0xc]
    adds r1, r6, #0
    adds r1, #0x10
    mov r4, r8
    str r4, [sp]
    str r5, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    ldr r2, .L080195DC @ =0x00000C88
    add r2, sp
    ldr r1, [r2]
    mov r2, sl
    movs r3, #0xaa
    ldr r4, .L080195E8 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080195EE
    .align 2, 0
.L080195CC: .4byte 0x00000C84
.L080195D0: .4byte 0x00001084
.L080195D4: .4byte 0x00001081
.L080195D8: .4byte 0x00000CCC
.L080195DC: .4byte 0x00000C88
.L080195E0: .4byte 0x00000C8C
.L080195E4: .4byte 0x00000C38
.L080195E8: .4byte SubmitWorldSpriteRecords
.L080195EC:
    movs r0, #0
.L080195EE:
    cmp r0, #0
    beq .L0801964C
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    mov r8, r0
    cmp r1, #0
    beq .L0801964C
    ldr r3, .L08019628 @ =0x00000C8C
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L0801962C
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08019646
    .align 2, 0
.L08019628: .4byte 0x00000C8C
.L0801962C:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08019646
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08019646:
    movs r0, #0
    mov r4, r8
    strb r0, [r4]
.L0801964C:
    adds r7, #0xc
    ldr r6, .L08019758 @ =0x00000CCC
    add r6, sp
    ldr r5, [r6]
    adds r5, #0xc
    str r5, [r6]
    ldr r1, .L0801975C @ =0x00000C84
    add r1, sp
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    cmp r0, #3
    bhi .L08019668
    b .L08019518
.L08019668:
    ldr r0, .L08019760 @ =gUnk_0300040C
    ldr r0, [r0]
    movs r2, #0
    movs r3, #0xc9
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    ldr r4, .L08019764 @ =0x000004DC
    adds r7, r0, r4
.L0801967A:
    ldrb r0, [r7]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .L08019686
    b .L080197AA
.L08019686:
    ldrh r4, [r7, #2]
    lsls r4, r4, #0x16
    lsrs r4, r4, #0x16
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r4, r0
    beq .L0801969E
    b .L080197AA
.L0801969E:
    ldrb r1, [r7, #3]
    lsrs r1, r1, #2
    ldrh r4, [r7, #4]
    ldr r0, .L08019768 @ =0x000003FF
    ands r4, r0
    lsls r4, r4, #6
    orrs r4, r1
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r6, [r7, #4]
    lsls r6, r6, #6
    asrs r6, r6, #0x10
    ldrb r5, [r7]
    lsls r5, r5, #0x1c
    lsrs r5, r5, #0x1e
    ldr r0, .L0801976C @ =0x000010B0
    add r0, sb
    movs r2, #0xc9
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #2
    adds r0, r0, r1
    ldr r0, [r0]
    mov r8, r0
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r1, .L08019770 @ =0x00000C94
    add r1, sp
    str r4, [r1]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r6, r0
    mov ip, r0
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r6
    mov sl, r0
    mov r6, r8
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov r8, r3
    lsls r3, r5, #2
    orrs r3, r5
    lsls r0, r5, #4
    orrs r3, r0
    lsls r5, r5, #6
    orrs r3, r5
    adds r5, r6, #0
    adds r5, #0x28
    mov r4, r8
    ldr r4, [r4, #4]
    ldr r0, .L08019774 @ =0x00000CD8
    add r0, sp
    str r4, [r0]
    adds r0, r6, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L0801977C
    ldrh r0, [r6, #0xc]
    adds r1, r6, #0
    adds r1, #0x10
    mov r4, sl
    str r4, [sp]
    str r5, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    ldr r1, .L08019774 @ =0x00000CD8
    add r1, sp
    ldr r0, [r1]
    ldr r2, .L08019770 @ =0x00000C94
    add r2, sp
    ldr r1, [r2]
    mov r2, ip
    ldr r4, .L08019778 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801977E
    .align 2, 0
.L08019758: .4byte 0x00000CCC
.L0801975C: .4byte 0x00000C84
.L08019760: .4byte gUnk_0300040C
.L08019764: .4byte 0x000004DC
.L08019768: .4byte 0x000003FF
.L0801976C: .4byte 0x000010B0
.L08019770: .4byte 0x00000C94
.L08019774: .4byte 0x00000CD8
.L08019778: .4byte SubmitWorldSpriteRecords
.L0801977C:
    movs r0, #0
.L0801977E:
    cmp r0, #0
    beq .L080197AA
    adds r4, r6, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .L080197AA
    mov r3, r8
    ldr r1, [r3]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
.L080197AA:
    adds r7, #0xc
    movs r5, #0xc9
    lsls r5, r5, #4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    str r4, [r5]
    cmp r4, #6
    bhs .L080197BE
    b .L0801967A
.L080197BE:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    ldr r5, [r0]
    cmp r5, #0x64
    blo .L080197CC
    movs r5, #0
.L080197CC:
    lsls r0, r5, #2
    ldr r1, .L080197F4 @ =0x00000C98
    add r1, sp
    ldr r1, [r1]
    adds r6, r1, r0
    ldr r2, .L080197F8 @ =0x00000CC4
    add r2, sp
    ldr r7, [r2]
    adds r4, r6, #0
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r3, #0xc7
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    cmp r0, r3
    blo .L080197FC
    subs r0, r4, r1
    b .L08019842
    .align 2, 0
.L080197F4: .4byte 0x00000C98
.L080197F8: .4byte 0x00000CC4
.L080197FC:
    ldr r0, .L08019970 @ =0x00000C74
    add r0, sp
    ldr r0, [r0]
    cmp r4, r0
    beq .L0801981A
    ldr r3, [r4]
    cmp r3, #0
    beq .L0801981A
    ldr r0, [r3, #0x14]
    ldr r1, .L08019974 @ =0x00000C28
    add r1, sp
    ldr r2, [r0, #0x1c]
    adds r0, r3, #0
    bl _call_via_r2
.L0801981A:
    adds r4, #4
    cmp r4, r7
    bne .L08019826
    ldr r1, .L08019978 @ =0x00000C98
    add r1, sp
    ldr r4, [r1]
.L08019826:
    cmp r4, r6
    beq .L08019844
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r2, #0xc7
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    cmp r0, r2
    blo .L080197FC
    ldr r3, .L08019978 @ =0x00000C98
    add r3, sp
    ldr r3, [r3]
    subs r0, r4, r3
.L08019842:
    asrs r5, r0, #2
.L08019844:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    str r5, [r0]
    ldr r4, .L0801997C @ =0x00000C6C
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4, #8]
    add r0, sp, #0x14
    bl WriteSprites__21WorldSpriteDrawBufferR25HardwareSpriteBufferState
    ldr r5, .L08019980 @ =0x00000CC8
    add r5, sp
    ldr r0, [r5]
    add r6, sp, #0x18
    cmp r6, r0
    beq .L08019870
    adds r1, r6, #0
.L08019868:
    ldr r2, .L08019984 @ =0xFFFFFDFC
    adds r0, r0, r2
    cmp r1, r0
    bne .L08019868
.L08019870:
    mov r3, sb
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #1
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    ldr r5, .L08019988 @ =0x00000C9C
    add r5, sp
    str r4, [r5]
    ldr r6, .L0801997C @ =0x00000C6C
    add r6, sp
    ldr r6, [r6]
    ldr r7, [r6]
    adds r2, r1, #0
    eors r2, r0
    movs r3, #0xca
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r4, #0
    ldr r5, .L0801998C @ =0x00000CA4
    add r5, sp
    str r4, [r5]
    ldr r6, .L08019990 @ =0x00000CBC
    add r6, sp
    ldr r6, [r6]
    ldrb r6, [r6]
    ldr r0, .L08019994 @ =0x00000CA8
    add r0, sp
    str r6, [r0]
    cmp r4, r6
    blo .L080198BC
    b .L08019B10
.L080198BC:
    ldr r1, .L08019988 @ =0x00000C9C
    add r1, sp
    ldr r1, [r1]
    ldr r2, .L08019998 @ =0x00000B78
    adds r0, r1, r2
    ldr r2, .L0801998C @ =0x00000CA4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov sl, r0
    ldrb r0, [r0, #9]
    lsrs r0, r0, #7
    adds r2, #1
    ldr r4, .L0801999C @ =0x00000CB4
    add r4, sp
    str r2, [r4]
    cmp r0, #0
    beq .L080198E8
    b .L08019AF8
.L080198E8:
    mov r5, sl
    movs r1, #9
    ldrsb r1, [r5, r1]
    ldr r6, .L08019988 @ =0x00000C9C
    add r6, sp
    ldr r2, [r6]
    adds r2, #0x20
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    mov r8, r2
    mov r4, r8
    adds r4, #0x82
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08019912
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    beq .L08019912
    b .L08019AF8
.L08019912:
    mov r1, r8
    adds r1, #0x60
    movs r0, #0xca
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    cmp r0, #0
    bne .L08019924
    mov r1, r8
.L08019924:
    mov r3, sl
    ldrb r2, [r3, #8]
    lsls r2, r2, #5
    ldr r5, .L080199A0 @ =OBJ_PALETTE
    adds r2, r2, r5
    add r0, sp, #0x14
    movs r3, #0x20
    bl __21DmaTransferDescriptorPCvPvUi
    mov r6, sp
    adds r6, #0x14
    ldr r0, .L080199A4 @ =0x00000CAC
    add r0, sp
    str r6, [r0]
    ldr r1, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r1, r0
    beq .L080199A8
    cmp r1, #0
    beq .L08019958
    adds r0, r1, #0
    add r1, sp, #0x14
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, [r1]
    str r1, [r0]
.L08019958:
    ldr r0, [r7, #4]
    adds r0, #0x10
    str r0, [r7, #4]
    mov r8, r4
    ldr r0, .L0801998C @ =0x00000CA4
    add r0, sp
    ldr r6, [r0]
    adds r6, #1
    ldr r0, .L0801999C @ =0x00000CB4
    add r0, sp
    str r6, [r0]
    b .L08019ADE
    .align 2, 0
.L08019970: .4byte 0x00000C74
.L08019974: .4byte 0x00000C28
.L08019978: .4byte 0x00000C98
.L0801997C: .4byte 0x00000C6C
.L08019980: .4byte 0x00000CC8
.L08019984: .4byte 0xFFFFFDFC
.L08019988: .4byte 0x00000C9C
.L0801998C: .4byte 0x00000CA4
.L08019990: .4byte 0x00000CBC
.L08019994: .4byte 0x00000CA8
.L08019998: .4byte 0x00000B78
.L0801999C: .4byte 0x00000CB4
.L080199A0: .word OBJ_PALETTE
.L080199A4: .4byte 0x00000CAC
.L080199A8:
    ldr r2, .L080199EC @ =0x00000CDC
    add r2, sp
    str r1, [r2]
    movs r0, #1
    ldr r2, .L080199F0 @ =0x00000C68
    add r2, sp
    str r0, [r2]
    ldr r0, [r7]
    subs r0, r1, r0
    asrs r4, r0, #4
    ldr r0, .L080199F4 @ =0x00000C64
    add r0, sp
    str r4, [r0]
    ldr r1, [r2]
    cmp r4, r1
    bhs .L080199CA
    adds r0, r2, #0
.L080199CA:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080199FC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    ldr r5, .L080199F8 @ =0x00000CB8
    add r5, sp
    str r4, [r5]
    cmp r0, #0
    bne .L08019A04
    adds r0, r4, #0
    bl RetryMemoryAllocation
    b .L08019A04
    .align 2, 0
.L080199EC: .4byte 0x00000CDC
.L080199F0: .4byte 0x00000C68
.L080199F4: .4byte 0x00000C64
.L080199F8: .4byte 0x00000CB8
.L080199FC:
    movs r0, #0
    ldr r6, .L08019A70 @ =0x00000CB8
    add r6, sp
    str r0, [r6]
.L08019A04:
    adds r5, r0, #0
    ldr r0, .L08019A74 @ =0x00000CD8
    add r0, sp
    str r5, [r0]
    ldr r2, [r7]
    adds r3, r5, #0
    movs r1, #0x82
    add r8, r1
    ldr r5, .L08019A78 @ =0x00000CA4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    ldr r5, .L08019A7C @ =0x00000CB4
    add r5, sp
    str r4, [r5]
    ldr r6, .L08019A80 @ =0x00000CDC
    add r6, sp
    ldr r6, [r6]
    cmp r2, r6
    beq .L08019A4A
.L08019A2C:
    cmp r3, #0
    beq .L08019A3C
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019A3C:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, .L08019A80 @ =0x00000CDC
    add r0, sp
    ldr r0, [r0]
    cmp r2, r0
    bne .L08019A2C
.L08019A4A:
    adds r5, r3, #0
    ldr r0, .L08019A84 @ =0x00000C68
    add r0, sp
    ldr r0, [r0]
    cmp r0, #1
    bne .L08019A8C
    cmp r5, #0
    beq .L08019A6A
    adds r0, r5, #0
    ldr r2, .L08019A88 @ =0x00000CAC
    add r2, sp
    ldr r1, [r2]
    ldm r1!, {r3, r4, r6}
    stm r0!, {r3, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019A6A:
    adds r5, #0x10
    b .L08019AB2
    .align 2, 0
.L08019A70: .4byte 0x00000CB8
.L08019A74: .4byte 0x00000CD8
.L08019A78: .4byte 0x00000CA4
.L08019A7C: .4byte 0x00000CB4
.L08019A80: .4byte 0x00000CDC
.L08019A84: .4byte 0x00000C68
.L08019A88: .4byte 0x00000CAC
.L08019A8C:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08019AB0
.L08019A94:
    cmp r2, #0
    beq .L08019AA8
    adds r0, r2, #0
    ldr r4, .L08019B6C @ =0x00000CAC
    add r4, sp
    ldr r1, [r4]
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019AA8:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08019A94
.L08019AB0:
    adds r5, r2, #0
.L08019AB2:
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08019AC2
.L08019ABC:
    adds r1, #0x10
    cmp r1, r2
    bne .L08019ABC
.L08019AC2:
    cmp r0, #0
    beq .L08019ACA
    bl free
.L08019ACA:
    ldr r6, .L08019B70 @ =0x00000CB8
    add r6, sp
    ldr r6, [r6]
    ldr r1, .L08019B74 @ =0x00000CD8
    add r1, sp
    ldr r1, [r1]
    adds r0, r6, r1
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
.L08019ADE:
    movs r0, #0
    mov r3, r8
    strb r0, [r3]
    mov r4, sl
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    bne .L08019AF8
    ldrb r0, [r4, #9]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .L08019AF8
    movs r0, #1
    strb r0, [r4, #0xa]
.L08019AF8:
    ldr r5, .L08019B78 @ =0x00000CB4
    add r5, sp
    ldr r5, [r5]
    ldr r6, .L08019B7C @ =0x00000CA4
    add r6, sp
    str r5, [r6]
    ldr r0, .L08019B80 @ =0x00000CA8
    add r0, sp
    ldr r6, [r0]
    cmp r5, r6
    bhs .L08019B10
    b .L080198BC
.L08019B10:
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    ldr r3, .L08019B84 @ =0x00000CBC
    add r3, sp
    ldr r3, [r3]
    ldrb r2, [r3]
    movs r4, #0xcc
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    ldrb r4, [r4]
    cmp r2, r4
    bhs .L08019B56
    movs r5, #0xff
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r6, .L08019B88 @ =0x00000B81
    adds r0, r0, r6
    adds r3, r0, r1
    ldr r1, .L08019B8C @ =0x00000DB1
    add r1, sb
.L08019B3E:
    ldrb r4, [r3]
    lsrs r0, r4, #7
    cmp r0, #0
    bne .L08019B4C
    adds r0, r4, #0
    orrs r0, r5
    strb r0, [r3]
.L08019B4C:
    adds r3, #0xc
    adds r2, #1
    ldrb r0, [r1]
    cmp r2, r0
    blo .L08019B3E
.L08019B56:
    movs r3, #0xce
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
.L08019B6C: .4byte 0x00000CAC
.L08019B70: .4byte 0x00000CB8
.L08019B74: .4byte 0x00000CD8
.L08019B78: .4byte 0x00000CB4
.L08019B7C: .4byte 0x00000CA4
.L08019B80: .4byte 0x00000CA8
.L08019B84: .4byte 0x00000CBC
.L08019B88: .4byte 0x00000B81
.L08019B8C: .4byte 0x00000DB1

    .endif

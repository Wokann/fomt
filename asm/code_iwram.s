    .section .iwram, "awx"
    .syntax unified

    .global func_03000490
    .type func_03000490, function
    .thumb
func_03000490:
    push {lr}
    ldr r1, [pc, #0x20]
    movs r0, #0
    strb r0, [r1]
    ldr r0, [pc, #0x1c]
    movs r2, #0
    strh r2, [r0]
    movs r1, #0x80
    lsls r1, r1, #0x13
    movs r0, #0x80
    strh r0, [r1]
    ldr r0, [pc, #0x14]
    strb r2, [r0]
    movs r0, #0
    svc #0x19
    .Lauto_030004AE:
    svc #3
    b .Lauto_030004AE
    .byte 0x00, 0x00, 0x08, 0x02, 0x00, 0x04, 0x00, 0x02, 0x00, 0x04, 0x84, 0x00, 0x00, 0x04

    .global __new_handler
    .type __new_handler, object
__new_handler:
    .4byte 0
    .size __new_handler, . - __new_handler

    .section .iwram.after_dimensions, "awx"
    .align 2, 0

    .global SubmitWorldSpriteRecords
    .type SubmitWorldSpriteRecords, function
    .arm
SubmitWorldSpriteRecords:
    push {r4, r5, r6, r7, r8, sb, sl, lr}
    mov ip, #0
    sub sp, sp, #0x34
    str ip, [sp, #0x24]
    str ip, [sp, #0x28]
    str ip, [sp, #0x2c]
    ldr r4, [sp, #0x58]
    str ip, [sp, #8]
    ldr r6, [r4]
    str ip, [sp, #0x30]
    str r1, [sp, #0x18]
    mov r7, r0
    str r2, [sp, #0x14]
    add r0, sp, #0x24
    str r3, [sp, #0x10]
    mov lr, ip
    str r0, [sp, #0xc]
    cmp r6, ip
    ldrhne lr, [r4, #4]
    add lr, r6, lr, lsl #3
    str lr, [sp, #4]
    cmp r6, lr
    beq .Lauto_030006FC
    .Lauto_03000538:
    add r1, sp, #0x1c
    str r1, [sp]
    ldm r6, {r2, r3}
    mov r0, r1
    stm r0, {r2, r3}
    add r1, sp, #0x18
    ldm r1, {r1, r2}
    mov r8, r2
    lsl r3, r2, #7
    add ip, r1, r3, asr #23
    cmp ip, #0xef
    mov sb, ip
    bgt .Lauto_030006EC
    ldr r1, [sp, #0x14]
    lsl r3, r2, #0x18
    add r0, r1, r3, asr #24
    cmp r0, #0x9f
    mov sl, r0
    bgt .Lauto_030006EC
    lsr r3, r2, #0x1e
    and r2, r2, #0xc000
    lsr r2, r2, #0xb
    ldr r1, .LIwramSpriteDimensions
    orr r2, r2, r3, lsl #1
    ldrh r2, [r1, r2]
    and r3, r2, #0xff
    add r3, ip, r3
    cmp r3, #0
    ble .Lauto_030006EC
    add r3, r0, r2, lsr #8
    cmp r3, #0
    ble .Lauto_030006EC
    ldr r3, [sp, #0x20]
    mov r5, r3
    and r2, r5, #0xf000
    lsr r4, r2, #0xc
    ldr r2, [sp, #0xc]
    ldrb r3, [r2, r4]
    subs ip, r3, #0x10
    bpl .Lauto_0300060C
    ldr r0, [sp, #0x5c]
    ldr r3, [r0]
    ldr r0, [sp, #0x64]
    add r2, r4, #4
    ldrb r1, [r0, r2]
    ldr r0, [sp, #0x5c]
    ldr ip, [r3, #0x50]
    mov lr, pc
    bx ip
    mov ip, r0
    ldr r1, [sp, #0xc]
    add r3, ip, #0x10
    strb r3, [r1, r4]
.Lauto_0300060C:
    bic r2, r8, #0xff00000
    bic r2, r2, #0xf3000
    bic r2, r2, #0xff0
    bic r2, r2, #0xf
    lsl r1, r5, #0x16
    orr r2, r2, #0x1000
    lsl r0, sl, #0x18
    lsl r3, sb, #0x17
    lsr r3, r3, #7
    orr r3, r3, r0, lsr #24
    orr r2, r2, r3
    str r2, [sp, #0x1c]
    lsr r1, r1, #0x16
    ldr r2, [sp, #0x60]
    and r3, r5, #0xc00
    ldr r0, [sp, #0x10]
    lsr r3, r3, #9
    ldr lr, [sp]
    add r1, r1, r2
    orr r1, r1, ip, lsl #12
    lsr r3, r0, r3
    lsl r3, r3, #0xa
    and r3, r3, #0xc00
    ldrb r0, [r7]
    orr r1, r1, r3
    str r1, [sp, #0x20]
    cmp r0, #0x7f
    bhi .Lauto_030006E0
    ldrb r3, [lr, #5]
    ldr r2, [sp, #0x54]
    lsr r3, r3, #2
    and r3, r3, #3
    orr r3, r3, r3, lsl #7
    add r1, r7, r3, lsl #2
    ldr r3, [r1, #4]!
    orr ip, r0, r2, lsl #7
    cmp r3, #0x7f
    bhi .Lauto_030006C4
    lsl r3, r3, #2
    add r3, r3, #4
    add r2, r1, r3
    cmp r2, #0
    strne ip, [r1, r3]
    ldr r3, [r1]
    add r3, r3, #1
    str r3, [r1]
    .Lauto_030006C4:
    add r3, r7, r0, lsl #3
    add r3, r3, #0x810
    ldm lr, {r1, r2}
    add r3, r3, #4
    stm r3, {r1, r2}
    add r2, r0, #1
    strb r2, [r7]
    .Lauto_030006E0:
    ldr r2, [sp, #8]
    add r2, r2, #1
    str r2, [sp, #8]
    .Lauto_030006EC:
    ldr r3, [sp, #4]
    add r6, r6, #8
    cmp r6, r3
    bne .Lauto_03000538
    .Lauto_030006FC:
    ldr r0, [sp, #8]
    b .Lauto_03000708
.LIwramSpriteDimensions:
    .4byte gHardwareSpriteDimensions
    .Lauto_03000708:
    add sp, sp, #0x34
    pop {r4, r5, r6, r7, r8, sb, sl, lr}
    bx lr

    .global DrawGlyph2Tile
    .type DrawGlyph2Tile, function
    .arm
DrawGlyph2Tile:
    @ r0 is a 24-byte, 16-pixel-wide 1bpp glyph; r1 is the 16x16-tile
    @ scratch buffer. Each source row becomes 4bpp pixels plus its shadow.
    push {r4, r5, r6, r7, r8, r9, sl, lr}
    sub sp, sp, #4
    mov sl, r0
    mov lr, r1
    mov r9, #0
    mov r2, r9
    mov r5, r9
    mov r3, r5
.LDrawGlyph2TileClear:
    str r3, [lr, #32]
    add r5, r5, #1
    str r3, [lr], #4
    cmp r5, #1
    bls .LDrawGlyph2TileClear
.LDrawGlyph2TileLine:
    mov r1, #1
    mov r4, #128
    mov ip, #0
    mov r0, ip
    tst sl, #3
    ldreq r6, [sl]
    lsrne r6, r6, #16
    add sl, sl, #2
    mov r7, r2, lsr #28
    mov r9, r9, lsl #4
    mov r2, r2, lsl #4
    str r2, [sp]
.LDrawGlyph2TilePixel:
    tst r6, r4
    orr r3, ip, r1
    movne ip, r3
    ands r2, r6, r4, lsl #8
    orr r3, r0, r1
    movne r0, r3
    mov r1, r1, lsl #4
    movs r4, r4, lsr #1
    bne .LDrawGlyph2TilePixel
    mov r3, ip, lsr #28
    orr r0, r3, r0, lsl #4
    mov ip, ip, lsl #4
    mov r8, r0, lsl #4
    orr r2, r8, r7
    mov r7, ip, lsr #28
    orr r3, r7, r9
    orr r3, r2, r3
    bic r3, r3, r0
    orr r1, r0, r3, lsl #1
    mov r9, r0
    add r5, r5, #1
    ldr r2, [sp]
    cmp r5, #8
    orr r3, r2, ip, lsl #4
    bic r3, r3, ip
    str r1, [lr, #32]
    orr r3, ip, r3, lsl #1
    str r3, [lr], #4
    mov r2, ip
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #13
    bls .LDrawGlyph2TileLine
    orr r3, r8, r7
    mov r9, r4
    mov r3, r3, lsl #1
    mov r2, r2, lsl #5
    str r3, [lr, #32]
    add r5, r5, #1
    str r2, [lr], #4
    cmp r5, #8
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #15
    bhi .LDrawGlyph2TileDone
    mov r2, r9
.LDrawGlyph2TileBottomPadding:
    str r2, [lr, #32]
    add r5, r5, #1
    str r2, [lr], #4
    cmp r5, #8
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #15
    bls .LDrawGlyph2TileBottomPadding
.LDrawGlyph2TileDone:
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, r9, sl, lr}
    bx lr

    .global DrawGlyph1Tile
    .type DrawGlyph1Tile, function
    .arm
DrawGlyph1Tile:
    @ r0 is a 12-byte, 8-pixel-wide 1bpp glyph; r1 is the same scratch
    @ buffer. The right-hand tile receives the generated shadow pixels.
    push {r4, r5, r6, r7, r8, lr}
    mov r4, r0
    mov r0, #0
    mov r8, r0
    mov r3, r0
.LDrawGlyph1TileClear:
    str r3, [r1, #32]
    add r0, r0, #1
    str r3, [r1], #4
    cmp r0, #1
    bls .LDrawGlyph1TileClear
.LDrawGlyph1TileLine:
    mov lr, #1
    mov r6, #128
    mov ip, #0
    tst r4, #3
    ldreq r5, [r4]
    lsrne r5, r5, #8
    add r4, r4, #1
    mov r7, r8, lsr #28
    mov r2, r8, lsl #4
.LDrawGlyph1TilePixel:
    tst r5, r6
    orr r3, ip, lr
    movne ip, r3
    mov lr, lr, lsl #4
    movs r6, r6, lsr #1
    bne .LDrawGlyph1TilePixel
    mov ip, ip, lsl #4
    orr r3, r2, ip, lsl #4
    bic r3, r3, ip
    mov r8, ip
    mov lr, ip, lsr #28
    orr r2, lr, r7
    mov r2, r2, lsl #1
    orr r3, ip, r3, lsl #1
    str r2, [r1, #32]
    add r0, r0, #1
    str r3, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #13
    bls .LDrawGlyph1TileLine
    mov r3, lr, lsl #1
    mov r2, r8, lsl #5
    mov r8, r6
    str r3, [r1, #32]
    add r0, r0, #1
    str r2, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #15
    bhi .LDrawGlyph1TileDone
    mov r2, r8
.LDrawGlyph1TileBottomPadding:
    str r2, [r1, #32]
    add r0, r0, #1
    str r2, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #15
    bls .LDrawGlyph1TileBottomPadding
.LDrawGlyph1TileDone:
    pop {r4, r5, r6, r7, r8, lr}
    bx lr

    .global func_03000958
    .type func_03000958, function
    .arm
func_03000958:
    mov r2, #0x4000000
    add r2, r2, #0x200
    ldrb r1, [r2, #8]
    mrs r0, spsr
    ldr r3, [r2]
    push {r0, r1, r2, r3, lr}
    mov ip, #0
    mov r0, #1
    and r1, r3, r3, lsr #16
    .Lauto_0300097C:
    tst r1, r0
    bne .Lauto_03000994
    add ip, ip, #2
    adds r0, r0, r0
    bne .Lauto_0300097C
    b .Lauto_030009FC
    .Lauto_03000994:
    ldr r1, .LInterruptEnableMasks
    ldrh r1, [r1, ip]
    and r1, r1, r3
    orr r1, r1, r0, lsl #16
    ldr r3, .LInterruptHandlers
    ldr r3, [r3, ip, lsl #1]
    cmp r3, #0x8000000
    orrhs r1, r1, #0x2000
    str r1, [r2]
    mov r1, #1
    strb r1, [r2, #8]
    ldr r2, [pc, #0x50]
    ldrh r1, [r2]
    orr r1, r1, r0
    strh r1, [r2]
    mrs r0, apsr
    mov r1, r0
    bic r1, r1, #0xdf
    orr r1, r1, #0x1f
    msr cpsr_fc, r1
    push {r0, lr}
    cmp r3, #0
    mov lr, pc
    bxne r3
    pop {r0, lr}
    msr cpsr_fc, r0
    .Lauto_030009FC:
    pop {r0, r1, r2, r3, lr}
    strh r3, [r2]
    msr spsr_fc, r0
    strb r1, [r2, #8]
    bx lr
.LInterruptEnableMasks:
    .4byte gInterruptNestingMasks
.LInterruptHandlers:
    .4byte gInterruptHandlers
    .4byte 0x03007FF8

    .global ApplyInterruptEnableMask
    .type ApplyInterruptEnableMask, function
    .arm
ApplyInterruptEnableMask:
    cmp lr, #0x8000000
    ldr r3, .LInterruptEnableRegister
    ldrblo r2, [r3, #8]
    movhs r2, #1
    orrhs ip, r0, #0x20000000
    strb r3, [r3, #8]
    ldrh r0, [r3]
    bic r1, r0, ip
    orr r1, r1, ip, lsr #16
    strh r1, [r3]
    strb r2, [r3, #8]
    bx lr
.LInterruptEnableRegister:
    .4byte 0x04000200

    @ The ROM image initializes rand's writable IWRAM seed to one.
    .global gRandomSeed
    .type gRandomSeed, object
gRandomSeed:
    .4byte 1
    .size gRandomSeed, . - gRandomSeed

    .section .iwram.after_sort, "awx"
    .arm
    .align 2, 0

    .global BlendRgb5PaletteBank
    .type BlendRgb5PaletteBank, function
    .arm
BlendRgb5PaletteBank:
    push {r4, r5, r6, r7, r8, sb, sl, fp, lr}
    and sb, r3, #0x1f
    add r8, sb, #1
    lsr r3, r3, #5
    and r3, r3, #0x1f
    add r6, r3, #1
    add sl, r0, #0x20
    mov r5, #0x7c000000
    add r5, r5, #0x1f0000
    lsr r4, r5, #0x10
    .Lauto_03000C54:
    ldr r7, [r2], #4
    and sb, r7, r5
    and r3, r7, #0x3e00000
    orr r3, r3, sb, lsr #16
    mul ip, r6, r3
    ldr fp, [r1], #4
    and sb, fp, r5
    and r3, fp, #0x3e00000
    orr lr, r3, sb, lsr #16
    and r3, r7, r4
    and r7, r7, #0x3e0
    orr r3, r3, r7, lsl #16
    mul sb, r6, r3
    mla ip, r8, lr, ip
    and r3, fp, r4
    and fp, fp, #0x3e0
    orr lr, r3, fp, lsl #16
    and r7, r5, ip, lsl #11
    lsr r3, ip, #5
    mla ip, r8, lr, sb
    and r3, r3, #0x3e00000
    orr r7, r7, r3
    and sb, r4, ip, lsr #5
    lsr r3, ip, #0x15
    and r3, r3, #0x3e0
    orr sb, sb, r3
    orr r7, r7, sb
    str r7, [r0], #4
    cmp r0, sl
    bne .Lauto_03000C54
    pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}
    bx lr

    .global gUnk_03000CD4
    .type gUnk_03000CD4, object
gUnk_03000CD4: @ new handler
    .byte 0x00, 0x00, 0x00, 0x00

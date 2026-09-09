    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

    thumb_func_start func_080002E0
func_080002E0: @ 0x080002E0
    push {r4, r5, lr}
    sub sp, #0x28
    adds r4, r0, #0
    mov r1, sp
    movs r2, #0
    movs r3, #0x20
    bl func_080006E4
    ldr r5, .L08000324 @ =gUnk_03000400
    ldrh r0, [r5]
    cmp r0, #0
    bne .L08000320
    str r0, [sp, #0x20]
    add r1, sp, #0x20
    adds r0, r4, #0
    movs r2, #0x20
    movs r3, #4
    bl func_080006E4
    ldrh r0, [r5]
    cmp r0, #0
    bne .L08000320
    str r0, [sp, #0x24]
    add r1, sp, #0x24
    adds r0, r4, #0
    movs r2, #0x24
    movs r3, #4
    bl func_080006E4
    ldrh r0, [r5]
    cmp r0, #0
    beq .L08000328
.L08000320:
    movs r0, #0
    b .L0800034C
    .align 2, 0
.L08000324: .4byte gUnk_03000400
.L08000328:
    movs r4, #0
    ldr r1, .L08000354 @ =gSramImageSignature
    mov r0, sp
    movs r2, #0x20
    bl memcmp
    cmp r0, #0
    bne .L0800034A
    ldr r1, [sp, #0x20]
    movs r0, #3
    ands r0, r1
    cmp r0, r1
    bne .L0800034A
    ldr r0, [sp, #0x24]
    cmp r0, #1
    bhi .L0800034A
    movs r4, #1
.L0800034A:
    adds r0, r4, #0
.L0800034C:
    add sp, #0x28
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
.L08000354: .4byte gSramImageSignature

    thumb_func_start func_08000358
func_08000358: @ 0x08000358
    push {r4, r5, lr}
    sub sp, #4
    adds r4, r0, #0
    ldr r2, .L08000398 @ =gSramImageSignature
    movs r1, #0
    movs r3, #0x20
    bl func_080006A4
    ldr r5, .L0800039C @ =gUnk_03000400
    ldrh r0, [r5]
    cmp r0, #0
    bne .L08000390
    str r0, [sp]
    adds r0, r4, #0
    movs r1, #0x20
    mov r2, sp
    movs r3, #4
    bl func_080006A4
    ldrh r0, [r5]
    cmp r0, #0
    bne .L08000390
    adds r0, r4, #0
    movs r1, #0x24
    mov r2, sp
    movs r3, #4
    bl func_080006A4
.L08000390:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.L08000398: .4byte gSramImageSignature
.L0800039C: .4byte gUnk_03000400

    .section .text.sram_proxy_1_after_address
    thumb_func_start func_080003E8
func_080003E8: @ 0x080003E8
    push {r4, r5, lr}
    sub sp, #4
    adds r4, r0, #0
    adds r5, r1, #0
    movs r0, #0
    str r0, [sp]
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x20
    movs r3, #4
    bl func_080006E4
    ldr r0, .L08000428 @ =gUnk_03000400
    ldrh r0, [r0]
    cmp r0, #0
    bne .L0800041E
    movs r1, #1
    lsls r1, r5
    ldr r0, [sp]
    orrs r0, r1
    str r0, [sp]
    adds r0, r4, #0
    movs r1, #0x20
    mov r2, sp
    movs r3, #4
    bl func_080006A4
.L0800041E:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.L08000428: .4byte gUnk_03000400

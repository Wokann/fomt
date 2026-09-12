    .ifdef REGION_JP
    @ JP revision 0 SRAM proxy implementation.
    .section .text
    .syntax unified
    .thumb
jp_sram_proxy_2_start:
    .incbin "baserom_jp.gba", 0x63C, 0xA8

    .global func_0800063C
    .thumb_set func_0800063C, jp_sram_proxy_2_start
    .global func_08000640
    .thumb_set func_08000640, jp_sram_proxy_2_start + 0x4
    .global func_080006A4
    .thumb_set func_080006A4, jp_sram_proxy_2_start + 0x68

    .section .text.sram_proxy_2_after_006e4
jp_sram_proxy_2_after_006e4:
    .incbin "baserom_jp.gba", 0x714, 0xD8

    .global func_08000728
    .thumb_set func_08000728, jp_sram_proxy_2_after_006e4 + 0x14
    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

    thumb_func_start func_0800063C
func_0800063C: @ 0x0800063C
    bx lr
    .align 2, 0

    thumb_func_start func_08000640
func_08000640: @ 0x08000640
    push {lr}
    adds r3, r0, #0
    ldr r2, .L0800065C @ =gUnk_03000402
    ldrb r1, [r2]
    cmp r1, #0
    bne .L08000654
    movs r0, #1
    strb r0, [r2]
    ldr r0, .L08000660 @ =gUnk_03000400
    strh r1, [r0]
.L08000654:
    adds r0, r3, #0
    pop {r1}
    bx r1
    .align 2, 0
.L0800065C: .4byte gUnk_03000402
.L08000660: .4byte gUnk_03000400

    thumb_func_start func_08000664
func_08000664:
    push {r4, r5, r6, lr}
    sub sp, #8
    adds r6, r0, #0
    movs r2, #0
    movs r3, #0xff
.L0800066E:
    mov r1, sp
    adds r0, r1, r2
    ldrb r1, [r0]
    orrs r1, r3
    strb r1, [r0]
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #7
    bls .L0800066E
.L08000682:
    movs r4, #0
    movs r5, #0x80
    lsls r5, r5, #8
.L08000688:
    adds r0, r6, #0
    adds r1, r4, #0
    mov r2, sp
    movs r3, #8
    bl func_080006A4
    adds r4, #8
    cmp r4, r5
    bcc .L08000688
    movs r0, #1
    add sp, #8
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start func_080006A4
func_080006A4: @ 0x080006A4
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r4, r1, #0
    adds r5, r2, #0
    adds r2, r3, #0
    ldr r1, .L080006E0 @ =gUnk_03000400
    movs r0, #0
    strh r0, [r1]
    cmp r2, #0
    beq .L080006D8
    movs r6, #1
    movs r1, #0xe0
    lsls r1, r1, #0x14
    orrs r1, r4
    adds r0, r5, #0
    bl func_080D38D4
    cmp r0, #0
    beq .L080006D6
    movs r1, #0x80
    lsls r1, r1, #1
    adds r0, r7, #0
    bl func_08000728
    movs r6, #0
.L080006D6:
    adds r0, r6, #0
.L080006D8:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080006E0: .4byte gUnk_03000400

    .section .text.sram_proxy_2_after_006e4
    thumb_func_start func_08000714
func_08000714:
    push {lr}
    ldrb r0, [r0, #4]
    movs r2, #3
    ands r0, r2
    adds r0, #3
    bl func_080D100C
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start func_08000728
func_08000728: @ 0x08000728
    push {lr}
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    cmp r3, #0x10
    beq .L080007C0
    cmp r3, #0x10
    bgt .L0800074E
    cmp r3, #2
    beq .L08000780
    cmp r3, #2
    bgt .L08000744
    cmp r3, #1
    beq .L08000772
    b .L080007E2
.L08000744:
    cmp r3, #4
    beq .L0800079C
    cmp r3, #8
    beq .L080007B4
    b .L080007E2
.L0800074E:
    cmp r3, #0x80
    beq .L080007D8
    cmp r3, #0x80
    bgt .L08000760
    cmp r3, #0x20
    beq .L080007A8
    cmp r3, #0x40
    beq .L080007CC
    b .L080007E2
.L08000760:
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r3, r0
    beq .L0800078C
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r3, r0
    beq .L0800078C
    b .L080007E2
.L08000772:
    ldr r0, .L0800077C @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #1
    b .L080007DE
    .align 2, 0
.L0800077C: .4byte gUnk_03000400
.L08000780:
    ldr r0, .L08000788 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #2
    b .L080007DE
    .align 2, 0
.L08000788: .4byte gUnk_03000400
.L0800078C:
    ldr r2, .L08000798 @ =gUnk_03000400
    ldrh r1, [r2]
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    b .L080007E2
    .align 2, 0
.L08000798: .4byte gUnk_03000400
.L0800079C:
    ldr r0, .L080007A4 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #4
    b .L080007DE
    .align 2, 0
.L080007A4: .4byte gUnk_03000400
.L080007A8:
    ldr r0, .L080007B0 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #0x20
    b .L080007DE
    .align 2, 0
.L080007B0: .4byte gUnk_03000400
.L080007B4:
    ldr r0, .L080007BC @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #8
    b .L080007DE
    .align 2, 0
.L080007BC: .4byte gUnk_03000400
.L080007C0:
    ldr r0, .L080007C8 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #0x10
    b .L080007DE
    .align 2, 0
.L080007C8: .4byte gUnk_03000400
.L080007CC:
    ldr r0, .L080007D4 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #0x40
    b .L080007DE
    .align 2, 0
.L080007D4: .4byte gUnk_03000400
.L080007D8:
    ldr r0, .L080007E8 @ =gUnk_03000400
    ldrh r1, [r0]
    movs r2, #0x80
.L080007DE:
    orrs r1, r2
    strh r1, [r0]
.L080007E2:
    pop {r0}
    bx r0
    .align 2, 0
.L080007E8: .4byte gUnk_03000400
    .endif

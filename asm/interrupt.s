    .ifdef REGION_JP
    @ JP revision 0 interrupt implementation.
    .section .text
    .syntax unified
    .thumb
jp_interrupt_start:
    .incbin "baserom_jp.gba", 0x4C4, 0xD8

    .global func_080004C4
    .thumb_set func_080004C4, jp_interrupt_start
    .global func_080004F4
    .thumb_set func_080004F4, jp_interrupt_start + 0x30
    .global func_0800050C
    .thumb_set func_0800050C, jp_interrupt_start + 0x48
    .global func_08000528
    .thumb_set func_08000528, jp_interrupt_start + 0x64
    .global func_08000540
    .thumb_set func_08000540, jp_interrupt_start + 0x7C
    .global func_08000568
    .thumb_set func_08000568, jp_interrupt_start + 0xA4
    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

    thumb_func_start func_080004C4
func_080004C4: @ 0x080004C4
    push {r4, lr}
    ldr r0, .L080004E8 @ =0x0000FFFF
    bl func_08000528
    ldr r1, .L080004EC @ =0x03007FFC
    ldr r0, .L080004F0 @ =func_03000958
    str r0, [r1]
    movs r4, #0
.L080004D4:
    adds r0, r4, #0
    movs r1, #0
    bl func_080D100C
    adds r4, #1
    cmp r4, #0xd
    bls .L080004D4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
.L080004E8: .4byte 0x0000FFFF
.L080004EC: .4byte 0x03007FFC
.L080004F0: .4byte func_03000958

    thumb_func_start func_080004F4
func_080004F4: @ 0x080004F4
    push {lr}
    lsls r0, r0, #0x10
    ldr r1, .L08000508 @ =func_03000A1C
    bl _call_via_r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    pop {r1}
    bx r1
    .align 2, 0
.L08000508: .4byte func_03000A1C

    thumb_func_start func_0800050C
func_0800050C: @ 0x0800050C
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r1, .L08000524 @ =0x04000202
    strh r0, [r1]
    bl func_080004F4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    pop {r1}
    bx r1
    .align 2, 0
.L08000524: .4byte 0x04000202

    thumb_func_start func_08000528
func_08000528: @ 0x08000528
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r1, .L0800053C @ =func_03000A1C
    bl _call_via_r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    pop {r1}
    bx r1
    .align 2, 0
.L0800053C: .4byte func_03000A1C

    thumb_func_start func_08000540
func_08000540: @ 0x08000540
    push {lr}
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl func_080D101C
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start func_08000554
func_08000554:
    push {lr}
    adds r1, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r0, #0
    bl IntrWait
    pop {r0}
    bx r0

    thumb_func_start func_08000568
func_08000568: @ 0x08000568
    push {lr}
    adds r1, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r0, #1
    bl IntrWait
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start func_0800057C
func_0800057C:
    adds r0, r1, #0
    bx lr

    thumb_func_start func_08000580
func_08000580:
    adds r0, r1, #0
    bx lr

    thumb_func_start func_08000584
func_08000584:
    push {lr}
    bl __builtin_new
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start func_08000590
func_08000590:
    push {lr}
    bl __builtin_delete
    pop {r0}
    bx r0
    .align 2, 0
    .endif

.include "asm/macro.inc"

.syntax unified
.section .text
.thumb

@ The unconstrained C candidate is not yet byte-matched. Keep the original
@ write wrapper as instructions, with relocations to both callees and status.
thumb_func_start func_080006A4
func_080006A4:
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r4, r1, #0
    adds r5, r2, #0
    adds r2, r3, #0
    ldr r1, .Lstatus
    movs r0, #0
    strh r0, [r1]
    cmp r2, #0
    beq .Lreturn
    movs r6, #1
    movs r1, #0xE0
    lsls r1, r1, #20
    orrs r1, r4
    adds r0, r5, #0
    bl WriteSramFastAndVerify
    cmp r0, #0
    beq .Lresult
    movs r1, #0x80
    lsls r1, r1, #1
    adds r0, r7, #0
    bl func_08000728
    movs r6, #0
.Lresult:
    adds r0, r6, #0
.Lreturn:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lstatus:
    .word gUnk_03000400
thumb_func_end func_080006A4

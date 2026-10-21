    .include "asm/macro.inc"
    .syntax unified
    .section .text, "ax", %progbits
    .thumb

    @ Seed storage is the existing writable IWRAM object, not a second state.
    @ srand stores all 32 bits; rand advances modulo 2^32 and returns 31 bits.
    thumb_func_start srand
srand:
    ldr r1, .LRandomConstants
    str r0, [r1, #0]
    bx lr
    .align 2, 0

    thumb_func_start rand
rand:
    adr r0, .LRandomConstants
    ldm r0!, {r1, r2, r3}
    ldr r0, [r1]
    muls r0, r2, r0
    adds r0, r0, r3
    str r0, [r1]
    lsls r0, r0, #1
    lsrs r0, r0, #1
    bx lr
    .align 2, 0
.LRandomConstants:
    .4byte gRandomSeed
    .4byte 0x41C64E6D
    .4byte 12345

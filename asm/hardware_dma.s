    .include "asm/macro.inc"

    .syntax unified
    .text

    thumb_func_start WriteHardwareDmaRegisters
WriteHardwareDmaRegisters:
    stm r3!, {r0, r1, r2}
    bx lr

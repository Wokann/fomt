#include "interrupt_table.h"

u16 gInterruptNestingMasks[16];
InterruptHandler gInterruptHandlers[16];

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start ExchangeInterruptHandler\n"
    "ExchangeInterruptHandler:\n"
    "    ldr r2, .Lcleanup_3_0\n"
    "    lsls r0, r0, #2\n"
    "    adds r2, r2, r0\n"
    "    ldr r0, [r2, #0]\n"
    "    str r1, [r2, #0]\n"
    "    bx lr\n"
    ".Lcleanup_3_0: .word gInterruptHandlers\n"
);

asm_unified(
    ".text\n"
    "thumb_func_start ExchangeInterruptNestingMask\n"
    "ExchangeInterruptNestingMask:\n"
    "    ldr r2, .Lcleanup_4_0\n"
    "    lsls r0, r0, #1\n"
    "    adds r2, r2, r0\n"
    "    ldrh r0, [r2, #0]\n"
    "    strh r1, [r2, #0]\n"
    "    bx lr\n"
    ".Lcleanup_4_0: .word gInterruptNestingMasks\n"
);

    .include "asm/macro.inc"
    .syntax unified
    .section .text, "ax", %progbits
    .thumb

    @ Shared native table exchanges. Only the owning symbol names change;
    @ the Thumb instructions, actual tables and unchecked index behavior do not.
	thumb_func_start ExchangeInterruptHandler
ExchangeInterruptHandler:
	ldr r2, .LInterruptHandlerTable @ =gInterruptHandlers
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, [r2]
	str r1, [r2]
	bx lr
	.align 2, 0
.LInterruptHandlerTable: .word gInterruptHandlers

	thumb_func_start ExchangeInterruptNestingMask
ExchangeInterruptNestingMask:
	ldr r2, .LInterruptNestingMaskTable @ =gInterruptNestingMasks
	lsls r0, r0, #1
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r1, [r2]
	bx lr
	.align 2, 0
.LInterruptNestingMaskTable: .word gInterruptNestingMasks

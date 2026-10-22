    .include "asm/macro.inc"
    .syntax unified
    .section .text, "ax", %progbits
    .thumb
    .align 2, 0

    @ Select an index by first-byte weight on a 0..99 roll; fall back to zero.

	thumb_func_start SelectActorBehaviorTimingIndex
SelectActorBehaviorTimingIndex:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x64
	bl RandomBelow
	adds r3, r0, #0
	movs r1, #0
	ldrb r2, [r4]
.L080AB83E:
	cmp r3, r2
	blo .L080AB854
	adds r1, #1
	cmp r1, r5
	bhs .L080AB852
	lsls r0, r1, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r2, r2, r0
	b .L080AB83E
.L080AB852:
	movs r1, #0
.L080AB854:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1

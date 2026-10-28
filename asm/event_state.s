    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Copy construction starts a fresh registered-event list, then copies
    @ its active IDs and the remaining saved fields. The +0x0A halfword and
    @ unused packed bits are preserved. C++ matching of this body is pending.

    .section .text.event_state_copy, "ax", %progbits

	thumb_func_start __14GameEventStateRC14GameEventState
__14GameEventStateRC14GameEventState: @ 0x080D44D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	adds r3, r7, #0
	stm r3!, {r0}
	ldm r1!, {r4}
	lsls r0, r4, #1
	adds r0, r0, r1
	cmp r0, r1
	beq .L080D44FC
	subs r2, r0, r1
	adds r0, r3, #0
	bl memmove
.L080D44FC:
	str r4, [r7]
	mov r1, sl
	ldrh r0, [r1, #0xc]
	strh r0, [r7, #0xc]
	ldrb r2, [r1, #0xe]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	ldrb r3, [r7, #0xe]
	movs r4, #2
	rsbs r4, r4, #0
	mov ip, r4
	mov r0, ip
	ands r0, r3
	orrs r0, r1
	movs r1, #6
	ands r1, r2
	subs r4, #5
	ands r0, r4
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	movs r5, #9
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r6, #0x31
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r7, #0xe]
	mov r3, sl
	ldrb r2, [r3, #0xf]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	ldrb r3, [r7, #0xf]
	mov r0, ip
	ands r0, r3
	orrs r1, r0
	movs r0, #2
	ands r0, r2
	adds r6, #0x2e
	ands r1, r6
	orrs r1, r0
	movs r0, #4
	ands r0, r2
	movs r3, #5
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r0
	movs r0, #0x18
	ands r0, r2
	subs r6, #0x16
	mov r8, r6
	ands r1, r6
	orrs r1, r0
	movs r0, #0x20
	ands r0, r2
	subs r3, #0x1c
	ands r1, r3
	orrs r1, r0
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r1, r6
	orrs r1, r2
	strb r1, [r7, #0xf]
	mov r0, sl
	ldrb r2, [r0, #0x10]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	ldrb r3, [r7, #0x10]
	mov r0, ip
	ands r0, r3
	orrs r1, r0
	movs r0, #6
	ands r0, r2
	ands r1, r4
	orrs r1, r0
	movs r0, #8
	ands r0, r2
	ands r1, r5
	orrs r1, r0
	movs r0, #0x10
	ands r0, r2
	movs r3, #0x11
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r0
	movs r0, #0x20
	ands r0, r2
	subs r6, #0x60
	ands r1, r6
	orrs r1, r0
	movs r0, #0x40
	ands r0, r2
	subs r3, #0x30
	ands r1, r3
	orrs r1, r0
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r1, r6
	orrs r1, r2
	strb r1, [r7, #0x10]
	mov r0, sl
	ldrb r3, [r0, #0x11]
	lsls r1, r3, #0x1f
	lsrs r1, r1, #0x1f
	ldrb r2, [r7, #0x11]
	mov r0, ip
	ands r0, r2
	orrs r1, r0
	movs r0, #2
	ands r0, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #4
	ands r0, r3
	subs r6, #0x84
	ands r1, r6
	orrs r1, r0
	movs r0, #8
	ands r0, r3
	ands r1, r5
	orrs r1, r0
	movs r0, #0x10
	ands r0, r3
	subs r2, #0xe
	ands r1, r2
	orrs r1, r0
	movs r0, #0x60
	ands r0, r3
	movs r3, #0x61
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r7, #0x11]
	mov r5, sl
	ldr r1, [r5, #0x10]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r1, r0
	ldr r0, [r7, #0x10]
	ldr r6, .L080D4A18 @ =0xFFFE7FFF
	ands r0, r6
	orrs r0, r1
	str r0, [r7, #0x10]
	ldrb r3, [r5, #0x12]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x12]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r3, #0x61
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r7, #0x12]
	ldrh r0, [r5, #0x12]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x12]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x12]
	ldrb r3, [r5, #0x13]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x13]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r6, #0x61
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r3, r3, #7
	mov r1, sl
	ldrb r2, [r1, #0x14]
	movs r5, #1
	ands r2, r5
	lsls r2, r2, #1
	orrs r2, r3
	adds r1, r2, #0
	ands r1, r5
	lsls r1, r1, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r1
	strb r0, [r7, #0x13]
	lsrs r2, r2, #1
	ands r2, r5
	ldrb r1, [r7, #0x14]
	mov r0, ip
	ands r0, r1
	orrs r0, r2
	mov r1, sl
	ldrb r2, [r1, #0x14]
	movs r1, #6
	ands r1, r2
	ands r0, r4
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	subs r5, #0x62
	ands r0, r5
	orrs r0, r1
	strb r0, [r7, #0x14]
	mov r6, sl
	ldrh r0, [r6, #0x14]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x14]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x14]
	ldrb r3, [r6, #0x15]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x15]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	ands r0, r5
	orrs r0, r1
	strb r0, [r7, #0x15]
	ldr r1, [r6, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r1, r0
	ldr r0, [r7, #0x14]
	ldr r3, .L080D4A18 @ =0xFFFE7FFF
	ands r0, r3
	orrs r0, r1
	str r0, [r7, #0x14]
	ldrb r3, [r6, #0x16]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x16]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r6, #0x61
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	strb r0, [r7, #0x16]
	mov r1, sl
	ldrh r0, [r1, #0x16]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x16]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x16]
	mov r2, sl
	ldrb r3, [r2, #0x17]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x17]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	lsrs r3, r3, #7
	mov r5, sl
	ldrb r1, [r5, #0x18]
	movs r6, #1
	ands r1, r6
	lsls r1, r1, #1
	orrs r1, r3
	adds r2, r1, #0
	ands r2, r6
	lsls r2, r2, #7
	movs r3, #0x7f
	ands r0, r3
	orrs r0, r2
	strb r0, [r7, #0x17]
	lsrs r1, r1, #1
	ands r1, r6
	ldrb r2, [r7, #0x18]
	mov r0, ip
	ands r0, r2
	orrs r1, r0
	ldrb r2, [r5, #0x18]
	movs r0, #6
	ands r0, r2
	ands r1, r4
	orrs r1, r0
	movs r0, #0x18
	ands r0, r2
	mov r5, r8
	ands r1, r5
	orrs r1, r0
	movs r0, #0x60
	ands r0, r2
	subs r6, #0x62
	ands r1, r6
	orrs r1, r0
	strb r1, [r7, #0x18]
	mov r1, sl
	ldrh r0, [r1, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x18]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x18]
	mov r2, sl
	ldrb r3, [r2, #0x19]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x19]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	strb r0, [r7, #0x19]
	mov r3, sl
	ldr r1, [r3, #0x18]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r1, r0
	ldr r0, [r7, #0x18]
	ldr r5, .L080D4A18 @ =0xFFFE7FFF
	ands r0, r5
	orrs r0, r1
	str r0, [r7, #0x18]
	ldrb r3, [r3, #0x1a]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x1a]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r6, r8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, #0x1a]
	mov r3, sl
	ldrh r0, [r3, #0x1a]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x1a]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x1a]
	ldrb r3, [r3, #0x1b]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x1b]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r5, #0x61
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r1
	lsrs r3, r3, #7
	mov r6, sl
	ldrb r1, [r6, #0x1c]
	movs r2, #1
	ands r1, r2
	lsls r1, r1, #1
	orrs r1, r3
	adds r2, r1, #0
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #7
	movs r5, #0x7f
	ands r0, r5
	orrs r0, r2
	strb r0, [r7, #0x1b]
	lsrs r1, r1, #1
	ands r1, r3
	ldrb r2, [r7, #0x1c]
	mov r0, ip
	ands r0, r2
	orrs r1, r0
	ldrb r2, [r6, #0x1c]
	movs r0, #6
	ands r0, r2
	ands r1, r4
	orrs r1, r0
	movs r0, #0x18
	ands r0, r2
	mov r6, r8
	ands r1, r6
	orrs r1, r0
	movs r0, #0x60
	ands r0, r2
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #0x1c]
	mov r3, sl
	ldrh r0, [r3, #0x1c]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x1c]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x1c]
	ldrb r3, [r3, #0x1d]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x1d]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r5, #0xe0
	ands r0, r5
	orrs r0, r1
	strb r0, [r7, #0x1d]
	mov r6, sl
	ldr r1, [r6, #0x1c]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r1, r0
	ldr r0, [r7, #0x1c]
	ldr r2, .L080D4A18 @ =0xFFFE7FFF
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x1c]
	ldrb r3, [r6, #0x1e]
	movs r1, #6
	ands r1, r3
	ldrb r2, [r7, #0x1e]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r6, #0x61
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	strb r0, [r7, #0x1e]
	mov r1, sl
	ldrh r0, [r1, #0x1e]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x1e]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x1e]
	mov r2, sl
	ldrb r3, [r2, #0x1f]
	movs r0, #6
	ands r0, r3
	ldrb r2, [r7, #0x1f]
	adds r1, r4, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0x18
	ands r0, r3
	ands r1, r5
	orrs r1, r0
	movs r0, #0x60
	ands r0, r3
	ands r1, r6
	orrs r1, r0
	lsrs r3, r3, #7
	mov r5, sl
	adds r5, #0x20
	ldrb r0, [r5]
	movs r6, #1
	ands r0, r6
	lsls r0, r0, #1
	orrs r0, r3
	adds r2, r0, #0
	ands r2, r6
	lsls r2, r2, #7
	movs r3, #0x7f
	ands r1, r3
	orrs r1, r2
	strb r1, [r7, #0x1f]
	lsrs r0, r0, #1
	ands r0, r6
	adds r3, r7, #0
	adds r3, #0x20
	ldrb r1, [r3]
	mov r6, ip
	ands r6, r1
	orrs r0, r6
	ldrb r2, [r5]
	movs r1, #6
	ands r1, r2
	ands r0, r4
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	movs r6, #0x61
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	strb r0, [r3]
	mov r1, sl
	ldrh r0, [r1, #0x20]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x20]
	ldr r0, .L080D4A1C @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x20]
	mov r0, sl
	adds r0, #0x21
	ldrb r3, [r0]
	adds r5, r7, #0
	adds r5, #0x21
	movs r1, #6
	ands r1, r3
	ldrb r2, [r5]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	strb r0, [r5]
	mov r3, sl
	ldr r1, [r3, #0x20]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r1, r0
	ldr r0, [r7, #0x20]
	ldr r5, .L080D4A18 @ =0xFFFE7FFF
	ands r0, r5
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, sl
	adds r0, #0x22
	ldrb r3, [r0]
	adds r5, r7, #0
	adds r5, #0x22
	movs r1, #6
	ands r1, r3
	ldrb r2, [r5]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	b .L080D4A20
	.align 2, 0
.L080D4A18: .4byte 0xFFFE7FFF
.L080D4A1C: .4byte 0xFFFFFE7F
.L080D4A20:
	ands r1, r3
	mov r6, r8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	movs r3, #0x41
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x23
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r5, sl
	adds r5, #0x24
	str r5, [sp, #0x14]
	ldrb r1, [r5]
	movs r5, #7
	ands r1, r5
	lsls r1, r1, #4
	orrs r1, r0
	movs r0, #0xf
	adds r2, r1, #0
	ands r2, r0
	movs r6, #0x23
	lsls r2, r2, #4
	ldrb r3, [r6, r7]
	ands r0, r3
	orrs r0, r2
	strb r0, [r6, r7]
	lsrs r1, r1, #4
	adds r3, r7, #0
	adds r3, #0x24
	ands r1, r5
	ldrb r2, [r3]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	ldr r5, [sp, #0x14]
	ldrb r2, [r5]
	movs r1, #0x18
	ands r1, r2
	mov r6, r8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r3, sl
	ldrh r1, [r3, #0x24]
	movs r0, #0xc0
	lsls r0, r0, #1
	ands r0, r1
	ldrh r1, [r7, #0x24]
	ldr r5, .L080D4E90 @ =0xFFFFFE7F
	ands r5, r1
	orrs r5, r0
	strh r5, [r7, #0x24]
	mov r0, sl
	adds r0, #0x25
	ldrb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x25
	movs r0, #6
	ands r0, r1
	ldrb r2, [r3]
	ands r4, r2
	orrs r4, r0
	movs r0, #0x18
	ands r0, r1
	ands r4, r6
	orrs r4, r0
	movs r0, #0x60
	ands r0, r1
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r4, r2
	orrs r4, r0
	lsrs r1, r1, #7
	lsls r1, r1, #7
	movs r5, #0x7f
	ands r4, r5
	orrs r4, r1
	strb r4, [r3]
	mov r0, sl
	adds r0, #0x26
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r5, r7, #0
	adds r5, #0x26
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	movs r4, #4
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r6, #0xd
	rsbs r6, r6, #0
	mov r8, r6
	ands r0, r6
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r3, #0x31
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x27
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r5, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	subs r6, #0x70
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x28
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r5, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x29
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r5, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r5]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0xc
	ands r1, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	subs r6, #0x60
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	subs r2, #0x30
	ands r0, r2
	orrs r0, r1
	lsrs r3, r3, #7
	lsls r3, r3, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x2a
	ldrb r3, [r0]
	lsls r1, r3, #0x1f
	lsrs r1, r1, #0x1f
	adds r5, #1
	ldrb r2, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	orrs r1, r0
	movs r0, #6
	ands r0, r3
	movs r2, #7
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0x18
	ands r0, r3
	adds r6, #8
	ands r1, r6
	orrs r1, r0
	movs r0, #0x60
	ands r0, r3
	subs r2, #0x5a
	ands r1, r2
	orrs r1, r0
	strb r1, [r5]
	mov r3, sl
	ldrh r0, [r3, #0x2a]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x2a]
	ldr r0, .L080D4E90 @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x2a]
	mov r0, sl
	adds r0, #0x2b
	ldrb r3, [r0]
	adds r5, #1
	movs r1, #6
	ands r1, r3
	ldrb r2, [r5]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #8
	ands r1, r3
	movs r2, #9
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x30
	ands r1, r3
	subs r6, #0x18
	ands r0, r6
	orrs r0, r1
	lsrs r3, r3, #6
	lsls r3, r3, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x2c
	ldrb r3, [r0]
	lsls r1, r3, #0x1f
	lsrs r1, r1, #0x1f
	adds r5, #1
	ldrb r2, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	orrs r1, r0
	movs r0, #6
	ands r0, r3
	movs r2, #7
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0x38
	ands r0, r3
	subs r2, #0x32
	ands r1, r2
	orrs r1, r0
	lsrs r3, r3, #6
	lsls r3, r3, #6
	movs r6, #0x3f
	ands r1, r6
	orrs r1, r3
	strb r1, [r5]
	mov r0, sl
	adds r0, #0x2d
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r5, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r5]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0xc
	ands r1, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	movs r1, #0x30
	ands r1, r3
	movs r3, #0x31
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r5]
	mov r5, sl
	ldr r1, [r5, #0x2c]
	movs r0, #0xf0
	lsls r0, r0, #0xa
	ands r1, r0
	ldr r0, [r7, #0x2c]
	ldr r6, .L080D4E94 @ =0xFFFC3FFF
	ands r0, r6
	orrs r0, r1
	str r0, [r7, #0x2c]
	mov r0, sl
	adds r0, #0x2e
	ldrb r2, [r0]
	adds r5, r7, #0
	adds r5, #0x2e
	movs r1, #4
	ands r1, r2
	ldrb r3, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	movs r3, #0x19
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	movs r6, #0x61
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x2f
	ldrb r3, [r0]
	lsls r0, r3, #0x1b
	movs r2, #0x2f
	adds r2, r2, r7
	mov ip, r2
	lsrs r0, r0, #0x1b
	ldrb r1, [r2]
	movs r2, #0x20
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	movs r0, #0x60
	ands r0, r3
	ands r2, r6
	orrs r2, r0
	lsrs r3, r3, #7
	mov r5, sl
	adds r5, #0x30
	ldrb r1, [r5]
	movs r6, #1
	ands r1, r6
	lsls r1, r1, #1
	orrs r1, r3
	adds r0, r1, #0
	ands r0, r6
	lsls r0, r0, #7
	movs r3, #0x7f
	ands r2, r3
	orrs r2, r0
	mov r6, ip
	strb r2, [r6]
	lsrs r1, r1, #1
	adds r3, r7, #0
	adds r3, #0x30
	movs r0, #1
	ands r1, r0
	ldrb r2, [r3]
	subs r0, #3
	ands r0, r2
	orrs r0, r1
	ldrb r2, [r5]
	movs r1, #6
	ands r1, r2
	movs r5, #7
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	movs r6, #0x19
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	subs r5, #0x5a
	ands r0, r5
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x31
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r5, r7, #0
	adds r5, #0x31
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	subs r6, #0xb0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x32
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r5, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r5]
	mov r0, sl
	adds r0, #0x33
	ldrb r1, [r0]
	lsls r0, r1, #0x1e
	adds r3, r7, #0
	adds r3, #0x33
	lsrs r0, r0, #0x1e
	ldrb r2, [r3]
	ands r4, r2
	orrs r4, r0
	movs r0, #0xc
	ands r0, r1
	mov r2, r8
	ands r4, r2
	orrs r4, r0
	movs r0, #0x30
	ands r0, r1
	movs r5, #0x31
	rsbs r5, r5, #0
	mov ip, r5
	ands r4, r5
	orrs r4, r0
	lsrs r1, r1, #6
	lsls r1, r1, #6
	ands r4, r6
	orrs r4, r1
	strb r4, [r3]
	mov r0, sl
	adds r0, #0x34
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x34
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r5, #0x2d
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	subs r6, #0x4c
	ands r0, r6
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r3, ip
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x35
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	b .L080D4E98
	.align 2, 0
.L080D4E90: .4byte 0xFFFFFE7F
.L080D4E94: .4byte 0xFFFC3FFF
.L080D4E98:
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x36
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r4]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #4
	ands r1, r3
	movs r2, #5
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	movs r6, #0x19
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r2, #0x5c
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldrh r0, [r3, #0x36]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x36]
	ldr r0, .L080D52D4 @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x36]
	mov r0, sl
	adds r0, #0x37
	ldrb r3, [r0]
	movs r4, #0x37
	adds r4, r4, r7
	mov r8, r4
	movs r1, #6
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r6, #0x48
	ands r0, r6
	orrs r0, r1
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x38
	ldrb r1, [r4]
	movs r2, #1
	ands r1, r2
	lsls r1, r1, #1
	orrs r1, r3
	adds r2, r1, #0
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r2
	mov r2, r8
	strb r0, [r2]
	lsrs r1, r1, #1
	ands r1, r3
	movs r3, #0x38
	adds r3, r3, r7
	mov r8, r3
	ldrb r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	orrs r1, r0
	ldrb r3, [r4]
	movs r0, #2
	ands r0, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0xc
	ands r0, r3
	movs r4, #0xd
	rsbs r4, r4, #0
	ands r1, r4
	orrs r1, r0
	movs r0, #0x30
	ands r0, r3
	mov r6, ip
	ands r1, r6
	orrs r1, r0
	lsrs r3, r3, #6
	lsls r3, r3, #6
	movs r0, #0x3f
	ands r1, r0
	orrs r1, r3
	mov r2, r8
	strb r1, [r2]
	mov r0, sl
	adds r0, #0x39
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x39
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x3a
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r4]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x1c
	ands r1, r3
	movs r2, #0x1d
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r2, #0x44
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldrh r0, [r3, #0x3a]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r7, #0x3a]
	ldr r0, .L080D52D4 @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x3a]
	mov r0, sl
	adds r0, #0x3b
	ldrb r3, [r0]
	movs r4, #0x3b
	adds r4, r4, r7
	mov r8, r4
	movs r1, #6
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	subs r6, #0x58
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x3c
	ldrb r1, [r4]
	movs r6, #1
	ands r1, r6
	lsls r1, r1, #1
	orrs r1, r3
	adds r2, r1, #0
	ands r2, r6
	lsls r2, r2, #7
	movs r3, #0x7f
	ands r0, r3
	orrs r0, r2
	mov r6, r8
	strb r0, [r6]
	lsrs r1, r1, #1
	movs r0, #1
	ands r1, r0
	adds r3, r7, #0
	adds r3, #0x3c
	ldrb r2, [r3]
	subs r0, #3
	ands r0, r2
	orrs r1, r0
	ldrb r2, [r4]
	movs r0, #6
	ands r0, r2
	movs r4, #7
	rsbs r4, r4, #0
	ands r1, r4
	orrs r1, r0
	movs r0, #0x18
	ands r0, r2
	movs r6, #0x19
	rsbs r6, r6, #0
	ands r1, r6
	orrs r1, r0
	movs r0, #0x60
	ands r0, r2
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	mov r3, sl
	ldrh r0, [r3, #0x3c]
	movs r1, #0xe0
	lsls r1, r1, #2
	ands r1, r0
	ldrh r2, [r7, #0x3c]
	ldr r0, .L080D52D8 @ =0xFFFFFC7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x3c]
	mov r0, sl
	adds r0, #0x3d
	ldrb r3, [r0]
	adds r4, r7, #0
	adds r4, #0x3d
	movs r1, #0xc
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x30
	ands r1, r3
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	strb r0, [r4]
	mov r0, sl
	ldr r1, [r0, #0x3c]
	movs r0, #0xf0
	lsls r0, r0, #0xa
	ands r1, r0
	ldr r0, [r7, #0x3c]
	ldr r2, .L080D52DC @ =0xFFFC3FFF
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x3c]
	mov r0, sl
	adds r0, #0x3e
	ldrb r2, [r0]
	adds r4, #1
	movs r1, #0xc
	ands r1, r2
	ldrb r3, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r3, #0x3f
	ands r0, r3
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x3f
	ldrb r3, [r0]
	lsls r0, r3, #0x1e
	movs r4, #0x3f
	adds r4, r4, r7
	mov r8, r4
	lsrs r0, r0, #0x1e
	ldrb r2, [r4]
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #4
	ands r0, r3
	movs r6, #5
	rsbs r6, r6, #0
	ands r1, r6
	orrs r1, r0
	movs r0, #0x18
	ands r0, r3
	movs r2, #0x19
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	lsrs r3, r3, #5
	mov r4, sl
	adds r4, #0x40
	ldrb r0, [r4]
	movs r6, #1
	ands r0, r6
	lsls r0, r0, #3
	orrs r0, r3
	lsls r3, r3, #5
	movs r2, #0x1f
	ands r1, r2
	orrs r1, r3
	mov r2, r8
	strb r1, [r2]
	lsrs r0, r0, #3
	ands r0, r6
	adds r3, r7, #0
	adds r3, #0x40
	ldrb r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r1
	orrs r0, r2
	ldrb r2, [r4]
	movs r1, #6
	ands r1, r2
	subs r6, #8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	subs r6, #0x12
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r1, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	ands r0, r1
	ldrh r1, [r3]
	ldr r2, .L080D52D4 @ =0xFFFFFE7F
	ands r2, r1
	orrs r2, r0
	strh r2, [r3]
	mov r0, sl
	adds r0, #0x41
	ldrb r3, [r0]
	adds r4, r7, #0
	adds r4, #0x41
	movs r1, #6
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	ands r0, r6
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldr r2, [r3, #0x40]
	movs r0, #0xf0
	lsls r0, r0, #9
	ands r2, r0
	ldr r0, [r7, #0x40]
	ldr r1, .L080D52E0 @ =0xFFFE1FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r7, #0x40]
	mov r0, sl
	adds r0, #0x42
	ldrb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x42
	movs r0, #6
	ands r0, r1
	ldrb r2, [r3]
	movs r4, #7
	rsbs r4, r4, #0
	ands r4, r2
	orrs r4, r0
	movs r0, #0x18
	ands r0, r1
	ands r4, r6
	orrs r4, r0
	movs r0, #0x20
	ands r0, r1
	subs r6, #8
	ands r4, r6
	orrs r4, r0
	lsrs r1, r1, #6
	lsls r1, r1, #6
	movs r0, #0x3f
	mov r8, r0
	ands r4, r0
	orrs r4, r1
	strb r4, [r3]
	mov r0, sl
	adds r0, #0x43
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x43
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	subs r6, #0x10
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, r8
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x44
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, r8
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x45
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r6, #0x31
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, r8
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x46
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, r8
	ands r0, r6
	b .L080D52E4
	.align 2, 0
.L080D52D4: .4byte 0xFFFFFE7F
.L080D52D8: .4byte 0xFFFFFC7F
.L080D52DC: .4byte 0xFFFC3FFF
.L080D52E0: .4byte 0xFFFE1FFF
.L080D52E4:
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x47
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r6, #0x31
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, r8
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x48
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, r8
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x49
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r6, #0x31
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, r8
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x4a
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, r8
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x4b
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	movs r6, #0x31
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, r8
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x4c
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, r8
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x4d
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r4]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #4
	ands r1, r3
	movs r2, #5
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #8
	ands r1, r3
	movs r6, #9
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	subs r2, #0xc
	ands r0, r2
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	subs r6, #0x18
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	subs r2, #0x30
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldr r2, [r3, #0x4c]
	movs r4, #3
	mov r8, r4
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r2, r0
	ldr r0, [r7, #0x4c]
	ldr r1, .L080D5874 @ =0xFFFE7FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r7, #0x4c]
	movs r6, #0x4e
	add r6, sl
	mov sb, r6
	ldrb r3, [r6]
	adds r4, r7, #0
	adds r4, #0x4e
	movs r1, #2
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0xc
	ands r1, r3
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	movs r6, #0x11
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r2, #0x54
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r4]
	ldr r0, .L080D5878 @ =0xFFFFFE7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r4]
	mov r0, sl
	adds r0, #0x4f
	ldrb r3, [r0]
	movs r4, #0x4f
	adds r4, r4, r7
	mov ip, r4
	movs r1, #0xe
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x30
	ands r1, r3
	subs r6, #0x20
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	movs r2, #0x41
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x50
	ldrb r2, [r4]
	mov r6, r8
	ands r2, r6
	lsls r2, r2, #1
	orrs r2, r3
	adds r1, r2, #0
	movs r3, #1
	ands r1, r3
	lsls r1, r1, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	lsrs r2, r2, #1
	adds r3, r7, #0
	adds r3, #0x50
	mov r6, r8
	ands r2, r6
	ldrb r1, [r3]
	adds r0, r5, #0
	ands r0, r1
	orrs r0, r2
	ldrb r2, [r4]
	movs r1, #0xc
	ands r1, r2
	movs r4, #0xd
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	movs r6, #0x11
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	subs r4, #0x54
	ands r0, r4
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x51
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x51
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	movs r3, #5
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	subs r6, #0x98
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	subs r3, #0x1c
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	mov ip, r6
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x52
	str r0, [sp, #8]
	ldrb r3, [r0]
	lsls r1, r3, #0x1f
	lsrs r1, r1, #0x1f
	adds r4, #1
	ldrb r2, [r4]
	subs r6, #0x41
	mov r8, r6
	mov r0, r8
	ands r0, r2
	orrs r1, r0
	movs r0, #6
	ands r0, r3
	movs r2, #7
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #8
	ands r0, r3
	subs r6, #7
	ands r1, r6
	orrs r1, r0
	movs r0, #0x30
	ands r0, r3
	subs r2, #0x2a
	ands r1, r2
	orrs r1, r0
	strb r1, [r4]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r4]
	ldr r0, .L080D587C @ =0xFFFFFE3F
	ands r0, r2
	orrs r0, r1
	strh r0, [r4]
	mov r0, sl
	adds r0, #0x53
	ldrb r2, [r0]
	adds r4, #1
	movs r1, #6
	ands r1, r2
	ldrb r3, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	subs r6, #0x28
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r1, ip
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x54
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	movs r3, #5
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	adds r6, #0x28
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r3, #0xc
	ands r0, r3
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	subs r6, #0x58
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x55
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	movs r3, #5
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	adds r6, #0x48
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	subs r3, #0x1c
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, ip
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x56
	ldrb r2, [r0]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	adds r4, #1
	ldrb r3, [r4]
	mov r0, r8
	ands r0, r3
	orrs r1, r0
	movs r0, #6
	ands r0, r2
	movs r3, #7
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r0
	movs r0, #8
	ands r0, r2
	movs r6, #9
	rsbs r6, r6, #0
	ands r1, r6
	orrs r1, r0
	movs r0, #0x30
	ands r0, r2
	subs r3, #0x2a
	ands r1, r3
	orrs r1, r0
	lsrs r2, r2, #6
	lsls r2, r2, #6
	mov r6, ip
	ands r1, r6
	orrs r1, r2
	strb r1, [r4]
	mov r0, sl
	adds r0, #0x57
	ldrb r3, [r0]
	lsls r0, r3, #0x1e
	movs r1, #0x57
	adds r1, r1, r7
	mov ip, r1
	lsrs r0, r0, #0x1e
	ldrb r2, [r1]
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0xc
	ands r0, r3
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0x30
	ands r0, r3
	movs r4, #0x31
	rsbs r4, r4, #0
	ands r1, r4
	orrs r1, r0
	movs r0, #0x40
	ands r0, r3
	movs r6, #0x41
	rsbs r6, r6, #0
	ands r1, r6
	orrs r1, r0
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x58
	ldrb r0, [r4]
	movs r2, #1
	ands r0, r2
	lsls r0, r0, #1
	orrs r0, r3
	adds r2, r0, #0
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r1, r6
	orrs r1, r2
	mov r2, ip
	strb r1, [r2]
	lsrs r0, r0, #1
	ands r0, r3
	adds r3, r7, #0
	adds r3, #0x58
	ldrb r2, [r3]
	mov r1, r8
	ands r1, r2
	orrs r0, r1
	ldrb r2, [r4]
	movs r1, #2
	ands r1, r2
	movs r4, #3
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	subs r6, #0x8c
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r4, #0xe
	ands r0, r4
	orrs r0, r1
	movs r1, #0x60
	ands r1, r2
	subs r6, #0x54
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x59
	ldrb r3, [r0]
	lsls r1, r3, #0x1e
	adds r4, r7, #0
	adds r4, #0x59
	lsrs r1, r1, #0x1e
	ldrb r2, [r4]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #4
	ands r1, r3
	movs r2, #5
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	adds r6, #0x48
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	subs r2, #0x5c
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, sl
	ldr r2, [r3, #0x58]
	movs r0, #0xe0
	lsls r0, r0, #0xa
	ands r2, r0
	ldr r0, [r7, #0x58]
	ldr r1, .L080D5880 @ =0xFFFC7FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r7, #0x58]
	movs r4, #0x5a
	add r4, sl
	mov ip, r4
	ldrb r3, [r4]
	adds r4, r7, #0
	adds r4, #0x5a
	movs r1, #4
	ands r1, r3
	ldrb r2, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #8
	ands r1, r3
	adds r6, #0x10
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	subs r6, #0x18
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	subs r2, #0x30
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r3, ip
	ldrh r1, [r3]
	movs r0, #0xc0
	lsls r0, r0, #1
	ands r0, r1
	ldrh r1, [r4]
	ldr r6, .L080D5878 @ =0xFFFFFE7F
	ands r6, r1
	orrs r6, r0
	strh r6, [r4]
	mov r0, sl
	adds r0, #0x5b
	ldrb r3, [r0]
	movs r1, #0x5b
	adds r1, r1, r7
	mov sb, r1
	movs r1, #6
	ands r1, r3
	mov r4, sb
	ldrb r2, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r2
	b .L080D5884
	.align 2, 0
.L080D5874: .4byte 0xFFFE7FFF
.L080D5878: .4byte 0xFFFFFE7F
.L080D587C: .4byte 0xFFFFFE3F
.L080D5880: .4byte 0xFFFC7FFF
.L080D5884:
	orrs r0, r1
	movs r1, #0x18
	ands r1, r3
	movs r6, #0x19
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	movs r1, #0x60
	ands r1, r3
	movs r2, #0x61
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x5c
	ldrb r2, [r4]
	movs r6, #1
	ands r2, r6
	lsls r2, r2, #1
	orrs r2, r3
	adds r1, r2, #0
	ands r1, r6
	lsls r1, r1, #7
	movs r3, #0x7f
	ands r0, r3
	orrs r0, r1
	mov r6, sb
	strb r0, [r6]
	lsrs r2, r2, #1
	adds r3, r7, #0
	adds r3, #0x5c
	movs r0, #1
	ands r2, r0
	ldrb r1, [r3]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	ldrb r2, [r4]
	movs r1, #6
	ands r1, r2
	movs r4, #7
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #0x18
	ands r1, r2
	movs r6, #0x19
	rsbs r6, r6, #0
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #5
	lsls r2, r2, #5
	movs r1, #0x1f
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x5d
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x5d
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	adds r6, #8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	subs r3, #0x14
	ands r0, r3
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r6, #0x30
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x5e
	ldrb r2, [r0]
	lsls r0, r2, #0x1f
	lsrs r0, r0, #0x1f
	adds r4, #1
	ldrb r3, [r4]
	mov r1, r8
	ands r1, r3
	orrs r0, r1
	movs r1, #2
	ands r1, r2
	movs r3, #3
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	adds r6, #0x3c
	ands r0, r6
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	subs r3, #6
	ands r0, r3
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r6, #0xc
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	subs r3, #0x18
	ands r0, r3
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r6, #0x30
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x5f
	ldrb r2, [r0]
	lsls r0, r2, #0x1f
	lsrs r0, r0, #0x1f
	adds r3, r7, #0
	adds r3, #0x5f
	ldrb r1, [r3]
	mov r4, r8
	ands r4, r1
	orrs r0, r4
	movs r1, #2
	ands r1, r2
	adds r6, #0x3e
	ands r0, r6
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	movs r4, #5
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	subs r6, #6
	ands r0, r6
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	subs r4, #0x2c
	mov ip, r4
	ands r0, r4
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x60
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	adds r4, r7, #0
	adds r4, #0x60
	lsrs r1, r1, #0x1e
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x61
	ldrb r1, [r0]
	lsls r0, r1, #0x1e
	adds r3, r7, #0
	adds r3, #0x61
	lsrs r0, r0, #0x1e
	ldrb r2, [r3]
	ands r5, r2
	orrs r5, r0
	movs r0, #0xc
	ands r0, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r5, r2
	orrs r5, r0
	movs r0, #0x30
	ands r0, r1
	ands r5, r6
	orrs r5, r0
	lsrs r1, r1, #6
	lsls r1, r1, #6
	movs r4, #0x3f
	ands r5, r4
	orrs r5, r1
	strb r5, [r3]
	mov r0, sl
	adds r0, #0x62
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r5, #0x62
	adds r5, r5, r7
	mov r8, r5
	lsrs r1, r1, #0x1e
	ldrb r3, [r5]
	subs r4, #0x43
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	movs r5, #0xd
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	mov r1, r8
	strb r0, [r1]
	mov r0, sl
	adds r0, #0x63
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r3, #0x63
	adds r3, r3, r7
	mov r8, r3
	lsrs r1, r1, #0x1e
	ldrb r3, [r3]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	mov r2, r8
	strb r0, [r2]
	mov r0, sl
	adds r0, #0x64
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r3, #0x64
	adds r3, r3, r7
	mov r8, r3
	lsrs r1, r1, #0x1e
	ldrb r3, [r3]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	mov r1, r8
	strb r0, [r1]
	mov r0, sl
	adds r0, #0x65
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r3, #0x65
	adds r3, r3, r7
	mov r8, r3
	lsrs r1, r1, #0x1e
	ldrb r3, [r3]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	mov r2, r8
	strb r0, [r2]
	mov r0, sl
	adds r0, #0x66
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r3, #0x66
	adds r3, r3, r7
	mov r8, r3
	lsrs r1, r1, #0x1e
	ldrb r3, [r3]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r6, #0x3f
	ands r0, r6
	orrs r0, r2
	mov r1, r8
	strb r0, [r1]
	mov r0, sl
	adds r0, #0x67
	ldrb r2, [r0]
	lsls r1, r2, #0x1e
	movs r3, #0x67
	adds r3, r3, r7
	mov r8, r3
	lsrs r1, r1, #0x1e
	ldrb r3, [r3]
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0xc
	ands r1, r2
	ands r0, r5
	orrs r0, r1
	movs r1, #0x30
	ands r1, r2
	mov r6, ip
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	mov r2, r8
	strb r0, [r2]
	movs r3, #0x68
	add r3, sl
	mov r8, r3
	ldrb r2, [r3]
	lsls r0, r2, #0x1e
	adds r3, r7, #0
	adds r3, #0x68
	lsrs r0, r0, #0x1e
	ldrb r1, [r3]
	ands r4, r1
	orrs r4, r0
	movs r0, #0xc
	ands r0, r2
	ands r4, r5
	orrs r4, r0
	movs r0, #0x30
	ands r0, r2
	ands r4, r6
	orrs r4, r0
	strb r4, [r3]
	mov r4, r8
	ldrh r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #6
	ands r1, r0
	ldrh r2, [r3]
	ldr r4, .L080D5FC8 @ =0xFFFFC03F
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r5, sl
	ldr r1, [r5, #0x68]
	movs r0, #0xff
	lsls r0, r0, #0xe
	ands r1, r0
	ldr r0, [r7, #0x68]
	ldr r6, .L080D5FCC @ =0xFFC03FFF
	ands r0, r6
	orrs r0, r1
	str r0, [r7, #0x68]
	mov r0, sl
	adds r0, #0x6a
	ldrh r0, [r0]
	adds r3, #2
	movs r1, #0xff
	lsls r1, r1, #6
	ands r1, r0
	ldrh r2, [r3]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r0, sl
	adds r0, #0x6b
	ldrb r0, [r0]
	lsrs r0, r0, #6
	movs r1, #0x6c
	add r1, sl
	mov r8, r1
	ldrb r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	lsls r1, r1, #2
	orrs r1, r0
	adds r2, r1, #0
	movs r3, #3
	ands r2, r3
	adds r5, r7, #0
	adds r5, #0x6b
	lsls r2, r2, #6
	ldrb r3, [r5]
	movs r0, #0x3f
	ands r0, r3
	orrs r0, r2
	strb r0, [r5]
	lsrs r1, r1, #2
	adds r3, r7, #0
	adds r3, #0x6c
	movs r5, #0x3f
	ands r1, r5
	ldrb r2, [r3]
	subs r5, #0x7f
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r6, r8
	ldrh r0, [r6]
	movs r1, #0xff
	lsls r1, r1, #6
	ands r1, r0
	ldrh r2, [r3]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r0, sl
	ldr r1, [r0, #0x6c]
	movs r0, #0xff
	lsls r0, r0, #0xe
	ands r1, r0
	ldr r0, [r7, #0x6c]
	ldr r2, .L080D5FCC @ =0xFFC03FFF
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x6c]
	mov r0, sl
	adds r0, #0x6e
	ldrh r0, [r0]
	adds r3, #2
	movs r1, #0xff
	lsls r1, r1, #6
	ands r1, r0
	ldrh r2, [r3]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r0, sl
	adds r0, #0x6f
	ldrb r0, [r0]
	lsrs r0, r0, #6
	movs r3, #0x70
	add r3, sl
	mov r8, r3
	ldrb r1, [r3]
	movs r6, #0x3f
	ands r1, r6
	lsls r1, r1, #2
	orrs r1, r0
	adds r2, r1, #0
	movs r0, #3
	ands r2, r0
	movs r3, #0x6f
	adds r3, r3, r7
	mov ip, r3
	lsls r2, r2, #6
	ldrb r3, [r3]
	movs r0, #0x3f
	ands r0, r3
	orrs r0, r2
	mov r6, ip
	strb r0, [r6]
	lsrs r1, r1, #2
	adds r3, r7, #0
	adds r3, #0x70
	movs r0, #0x3f
	ands r1, r0
	ldrb r2, [r3]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0xff
	lsls r1, r1, #6
	ands r1, r0
	ldrh r2, [r3]
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r2, sl
	ldr r1, [r2, #0x70]
	movs r0, #0xff
	lsls r0, r0, #0xe
	ands r1, r0
	ldr r0, [r7, #0x70]
	ldr r3, .L080D5FCC @ =0xFFC03FFF
	ands r0, r3
	orrs r0, r1
	str r0, [r7, #0x70]
	mov r0, sl
	adds r0, #0x72
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x72
	movs r0, #0xff
	lsls r0, r0, #6
	ands r0, r1
	ldrh r1, [r2]
	ands r4, r1
	orrs r4, r0
	strh r4, [r2]
	mov r0, sl
	adds r0, #0x73
	ldrb r0, [r0]
	lsrs r0, r0, #6
	mov r4, sl
	adds r4, #0x74
	ldrb r1, [r4]
	movs r6, #0x3f
	ands r1, r6
	lsls r1, r1, #2
	orrs r1, r0
	adds r2, r1, #0
	movs r0, #3
	ands r2, r0
	movs r3, #0x73
	adds r3, r3, r7
	mov r8, r3
	lsls r2, r2, #6
	ldrb r3, [r3]
	movs r0, #0x3f
	ands r0, r3
	orrs r0, r2
	mov r6, r8
	strb r0, [r6]
	lsrs r1, r1, #2
	adds r3, r7, #0
	adds r3, #0x74
	movs r0, #0x3f
	ands r1, r0
	ldrb r0, [r3]
	ands r5, r0
	orrs r5, r1
	strb r5, [r3]
	ldrh r0, [r4]
	movs r1, #0xe0
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r3]
	ldr r0, .L080D5FD0 @ =0xFFFFFE3F
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r0, sl
	adds r0, #0x75
	ldrb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x75
	movs r1, #6
	ands r1, r2
	ldrb r3, [r4]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	movs r3, #9
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	movs r5, #0x11
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	movs r6, #0x21
	rsbs r6, r6, #0
	mov r8, r6
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r3, #0x38
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r5, #0x7f
	ands r0, r5
	orrs r0, r2
	strb r0, [r4]
	mov r6, sl
	adds r6, #0x76
	str r6, [sp, #0x10]
	ldrb r2, [r6]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	adds r4, #1
	ldrb r3, [r4]
	subs r5, #0x81
	adds r0, r5, #0
	ands r0, r3
	orrs r1, r0
	movs r0, #2
	ands r0, r2
	movs r3, #3
	rsbs r3, r3, #0
	mov ip, r3
	ands r1, r3
	orrs r1, r0
	movs r0, #4
	ands r0, r2
	movs r6, #5
	rsbs r6, r6, #0
	ands r1, r6
	orrs r1, r0
	movs r0, #8
	ands r0, r2
	subs r3, #6
	ands r1, r3
	orrs r1, r0
	movs r0, #0x10
	ands r0, r2
	subs r6, #0xc
	ands r1, r6
	orrs r1, r0
	movs r0, #0x20
	ands r0, r2
	mov r3, r8
	ands r1, r3
	orrs r1, r0
	movs r0, #0x40
	ands r0, r2
	subs r6, #0x30
	ands r1, r6
	orrs r1, r0
	strb r1, [r4]
	ldr r1, [sp, #0x10]
	ldrh r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #3
	ands r1, r0
	ldrh r2, [r4]
	ldr r0, .L080D5FD4 @ =0xFFFFF87F
	ands r0, r2
	orrs r0, r1
	strh r0, [r4]
	mov r0, sl
	adds r0, #0x77
	ldrb r3, [r0]
	movs r2, #0x77
	adds r2, r2, r7
	mov sb, r2
	movs r1, #0x78
	ands r1, r3
	ldrb r2, [r2]
	movs r0, #0x79
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	lsrs r3, r3, #7
	mov r4, sl
	adds r4, #0x78
	ldrb r2, [r4]
	movs r1, #7
	lsls r3, r3, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r3
	mov r3, sb
	strb r0, [r3]
	adds r3, r7, #0
	adds r3, #0x78
	ands r2, r1
	ldrb r1, [r3]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	ldrb r2, [r4]
	movs r1, #8
	ands r1, r2
	movs r4, #9
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r6, #0x90
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	mov r4, r8
	ands r0, r4
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r6, #0x30
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	mov r0, sl
	adds r0, #0x79
	ldrb r2, [r0]
	lsls r0, r2, #0x1f
	lsrs r0, r0, #0x1f
	adds r4, r7, #0
	adds r4, #0x79
	ldrb r3, [r4]
	adds r1, r5, #0
	ands r1, r3
	orrs r0, r1
	movs r1, #2
	ands r1, r2
	mov r3, ip
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	adds r6, #0x3c
	ands r0, r6
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	movs r3, #9
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r6, #0xc
	ands r0, r6
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r6, #0x30
	ands r0, r6
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	mov r4, sl
	adds r4, #0x7a
	ldrb r1, [r4]
	lsls r1, r1, #0x1f
	lsrs r1, r1, #0x1f
	adds r3, r7, #0
	adds r3, #0x7a
	ldrb r2, [r3]
	adds r0, r5, #0
	ands r0, r2
	orrs r1, r0
	strb r1, [r3]
	ldrh r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r3]
	ldr r0, .L080D5FD8 @ =0xFFFFFE01
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	mov r0, sl
	adds r0, #0x7b
	ldrb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x7b
	movs r1, #2
	ands r1, r2
	ldrb r3, [r4]
	mov r0, ip
	ands r0, r3
	orrs r0, r1
	movs r1, #4
	ands r1, r2
	movs r3, #5
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r1
	movs r1, #8
	ands r1, r2
	adds r6, #0x38
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r2
	subs r3, #0xc
	ands r0, r3
	orrs r0, r1
	movs r1, #0x20
	ands r1, r2
	mov r6, r8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r2
	subs r3, #0x30
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r6, #0x7f
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	mov r0, sl
	adds r0, #0x7c
	ldrb r2, [r0]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	adds r4, #1
	ldrb r3, [r4]
	adds r0, r5, #0
	ands r0, r3
	orrs r1, r0
	movs r0, #2
	ands r0, r2
	mov r3, ip
	ands r1, r3
	orrs r1, r0
	movs r0, #4
	ands r0, r2
	subs r6, #0x84
	ands r1, r6
	orrs r1, r0
	movs r0, #8
	ands r0, r2
	movs r3, #9
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r0
	lsrs r2, r2, #4
	lsls r2, r2, #4
	b .L080D5FDC
	.align 2, 0
.L080D5FC8: .4byte 0xFFFFC03F
.L080D5FCC: .4byte 0xFFC03FFF
.L080D5FD0: .4byte 0xFFFFFE3F
.L080D5FD4: .4byte 0xFFFFF87F
.L080D5FD8: .4byte 0xFFFFFE01
.L080D5FDC:
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r4]
	mov r0, sl
	adds r0, #0x7d
	ldrb r3, [r0]
	lsls r0, r3, #0x1f
	lsrs r0, r0, #0x1f
	adds r4, #1
	ldrb r1, [r4]
	ands r5, r1
	orrs r0, r5
	movs r1, #0x1e
	ands r1, r3
	movs r2, #0x1f
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	subs r6, #0x3c
	ands r0, r6
	orrs r0, r1
	lsrs r3, r3, #7
	lsls r3, r3, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r3
	strb r0, [r4]
	mov r5, sl
	adds r5, #0x7e
	ldrb r3, [r5]
	lsls r1, r3, #0x1e
	adds r4, #1
	lsrs r1, r1, #0x1e
	ldrb r2, [r4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #4
	ands r1, r3
	movs r2, #5
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #8
	ands r1, r3
	adds r6, #0x38
	ands r0, r6
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	subs r2, #0xc
	ands r0, r2
	orrs r0, r1
	movs r1, #0x20
	ands r1, r3
	mov r6, r8
	ands r0, r6
	orrs r0, r1
	movs r1, #0x40
	ands r1, r3
	subs r2, #0x30
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrh r0, [r5]
	movs r1, #0xe0
	lsls r1, r1, #2
	ands r1, r0
	ldrh r2, [r4]
	ldr r0, .L080D60AC @ =0xFFFFFC7F
	ands r0, r2
	orrs r0, r1
	strh r0, [r4]
	mov r0, sl
	adds r0, #0x7f
	ldrb r1, [r0]
	lsrs r1, r1, #2
	adds r3, r7, #0
	adds r3, #0x7f
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #3
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080D60AC: .4byte 0xFFFFFC7F

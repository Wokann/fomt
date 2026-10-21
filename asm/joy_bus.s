    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Native protocol bodies share ownership with src/joy_bus.c.
    @ Only already recovered operations have been replaced by ordinary C.
    .ifdef REGION_JP
    .section .text.joy_bus_link_reset, "ax", %progbits
    .align 2, 0

    .global ResetJoyBusLinkRegisters
    .thumb_func
ResetJoyBusLinkRegisters:
    bx lr
    .byte 0x00, 0x00
    .section .text.joy_bus_update, "ax", %progbits
    .align 2, 0

    .global UpdateJoyBusCommunication
    .thumb_func
UpdateJoyBusCommunication: @ 0x080CFBE0
	push {r4, r5, lr}
	ldr r5, .L080CFC20 @ =gJoyBusContext
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, #0
	beq .L080CFCBA
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, #0x1c]
	ldr r0, .L080CFC24 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	bne .L080CFC46
	bl IsJoyBusCommandQueueEmpty
	cmp r0, #0
	bne .L080CFC28
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne .L080CFC28
	bl AdvanceJoyBusCommandQueue
	ldr r0, [r5]
	str r4, [r0, #0x10]
	b .L080CFC46
	.align 2, 0
.L080CFC20: .4byte gJoyBusContext
.L080CFC24: .4byte gCurrentJoyBusCommand
.L080CFC28:
	ldr r0, .L080CFC74 @ =gJoyBusContext
	ldr r3, [r0]
	ldr r0, [r3, #0x14]
	cmp r0, #0
	beq .L080CFC46
	movs r2, #0
	str r2, [r3, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	str r0, [r3, #0x18]
	str r2, [r1]
	bl ClearJoyBusCommandQueue
.L080CFC46:
	ldr r0, .L080CFC74 @ =gJoyBusContext
	ldr r1, [r0]
	ldr r0, [r1, #0xc]
	adds r0, #1
	str r0, [r1, #0xc]
	ldr r0, [r1, #0xc]
	cmp r0, #0xa
	bls .L080CFC84
	movs r0, #0
	str r0, [r1, #0xc]
	ldr r0, .L080CFC78 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	beq .L080CFC84
	cmp r0, #1
	bne .L080CFC7C
	movs r0, #1
	movs r1, #0
	bl ConfigureJoyBusRegisters
	b .L080CFC84
	.align 2, 0
.L080CFC74: .4byte gJoyBusContext
.L080CFC78: .4byte gCurrentJoyBusCommand
.L080CFC7C:
	movs r0, #1
	movs r1, #1
	bl ConfigureJoyBusRegisters
.L080CFC84:
	ldr r4, .L080CFCC0 @ =gJoyBusContext
	ldr r1, [r4]
	ldr r0, [r1, #0x10]
	adds r0, #1
	str r0, [r1, #0x10]
	ldr r0, .L080CFCC4 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #1
	bls .L080CFCBA
	ldr r0, [r1, #0x10]
	cmp r0, #0xb4
	bls .L080CFCBA
	movs r0, #0xb
	bl func_080D0A94
	ldr r0, [r4]
	movs r2, #0
	str r2, [r0, #0x14]
	movs r1, #0xa
	str r1, [r0, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r2, [r0]
	bl ClearJoyBusCommandQueue
.L080CFCBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFCC0: .4byte gJoyBusContext
.L080CFCC4: .4byte gCurrentJoyBusCommand
    .global func_080D0444
    .thumb_func
func_080D0444: @ 0x080CFCC8
	ldr r2, .L080CFCD4 @ =gJoyBusContext
	ldr r2, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	bx lr
	.align 2, 0
.L080CFCD4: .4byte gJoyBusContext
    .global func_080D0454
    .thumb_func
func_080D0454: @ 0x080CFCD8
	push {r4, lr}
	sub sp, #0x20
	ldr r4, .L080CFD10 @ =gJoyBusContext
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1, #0x14]
	str r0, [sp]
	mov r0, sp
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x18]
	mov r1, sp
	movs r0, #0
	strh r0, [r1, #0x1c]
	mov r0, sp
	bl EnqueueJoyBusCommand
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFD10: .4byte gJoyBusContext
func_080CFD14: @ 0x080CFD14
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	sub sp, #0x20
	mov r9, r0
	adds r6, r1, #0
	ldr r0, .L080CFD74 @ =gJoyBusContext
	mov r8, r0
	ldr r1, [r0]
	movs r4, #2
	str r4, [r1, #0x14]
	movs r0, #4
	str r0, [sp]
	adds r1, #0x24
	str r1, [sp, #0x10]
	str r4, [sp, #0x18]
	mov r0, sp
	movs r5, #0
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	str r4, [sp]
	mov r1, r9
	str r1, [sp, #0x10]
	adds r6, #1
	lsrs r6, r6, #1
	str r6, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, r8
	ldr r0, [r1]
	str r5, [r0, #0x1c]
	str r6, [r0, #0x20]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	str r5, [r0]
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFD74: .4byte gJoyBusContext
func_080CFD78: @ 0x080CFD78
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	sub sp, #0x20
	mov r9, r0
	adds r5, r1, #0
	ldr r0, .L080CFDD8 @ =gJoyBusContext
	mov r8, r0
	ldr r1, [r0]
	movs r6, #3
	str r6, [r1, #0x14]
	movs r0, #4
	str r0, [sp]
	adds r1, #0x24
	str r1, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x18]
	mov r0, sp
	movs r4, #0
	strh r4, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	str r6, [sp]
	mov r1, r9
	str r1, [sp, #0x10]
	adds r5, #1
	lsrs r5, r5, #1
	str r5, [sp, #0x18]
	mov r0, sp
	strh r4, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, r8
	ldr r0, [r1]
	str r4, [r0, #0x1c]
	str r5, [r0, #0x20]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	str r4, [r0]
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFDD8: .4byte gJoyBusContext
    .global func_080D0558
    .thumb_func
func_080D0558: @ 0x080CFDDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r3, #0
	ldr r0, .L080CFE5C @ =gJoyBusContext
	mov sl, r0
	ldr r0, [r0]
	movs r1, #4
	str r1, [r0, #0x14]
	str r1, [sp]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r1, #2
	mov r8, r1
	str r1, [sp, #0x18]
	mov r0, sp
	movs r5, #0
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #0x10]
	adds r6, #1
	lsrs r6, r6, #1
	str r6, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, r8
	str r1, [sp]
	str r7, [sp, #0x10]
	adds r4, #1
	lsrs r4, r4, #1
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, sl
	ldr r0, [r1]
	str r5, [r0, #0x1c]
	adds r4, r4, r6
	str r4, [r0, #0x20]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	str r5, [r0]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFE5C: .4byte gJoyBusContext
    .global func_080D05DC
    .thumb_func
func_080D05DC: @ 0x080CFE60
	push {r4, r5, r6, lr}
	sub sp, #0x20
	ldr r6, .L080CFEC4 @ =gJoyBusContext
	ldr r0, [r6]
	movs r1, #5
	str r1, [r0, #0x14]
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq .L080CFE7C
	movs r0, #1
	str r0, [sp]
	mov r0, sp
	bl EnqueueJoyBusCommand
.L080CFE7C:
	movs r0, #4
	str r0, [sp]
	ldr r0, [r6]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r4, #2
	str r4, [sp, #0x18]
	mov r0, sp
	movs r5, #0
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	ldr r0, [r6]
	adds r0, #0x2c
	str r0, [sp, #0x10]
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	str r4, [sp]
	ldr r0, [r6]
	adds r0, #0x28
	str r0, [sp, #0x10]
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFEC4: .4byte gJoyBusContext
    .global func_080D0644
    .thumb_func
func_080D0644: @ 0x080CFEC8
	push {r4, lr}
	ldr r4, .L080CFEF8 @ =gJoyBusContext
	ldr r2, [r4]
	adds r2, #0x28
	strb r0, [r2]
	ldr r2, [r4]
	lsrs r3, r0, #8
	adds r2, #0x29
	strb r3, [r2]
	ldr r2, [r4]
	lsrs r3, r0, #0x10
	adds r2, #0x2a
	strb r3, [r2]
	ldr r2, [r4]
	lsrs r0, r0, #0x18
	adds r2, #0x2b
	strb r0, [r2]
	ldr r0, [r4]
	str r1, [r0, #0x30]
	bl func_080D05DC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080CFEF8: .4byte gJoyBusContext
    .global func_080D0678
    .thumb_func
func_080D0678: @ 0x080CFEFC
	ldr r0, .L080CFF28 @ =gJoyBusContext
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	lsls r1, r1, #8
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	orrs r0, r1
	bx lr
	.align 2, 0
.L080CFF28: .4byte gJoyBusContext
    .global func_080D06A8
    .thumb_func
func_080D06A8: @ 0x080CFF2C
	push {lr}
	movs r0, #0xb
	bl func_080D0A94
	pop {r0}
	bx r0
    .global func_080D06B4
    .thumb_func
func_080D06B4: @ 0x080CFF38
	push {lr}
	movs r1, #0
	ldr r0, .L080CFF50 @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne .L080CFF48
	movs r1, #1
.L080CFF48:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
.L080CFF50: .4byte gJoyBusContext
    .global func_080D06D0
    .thumb_func
func_080D06D0: @ 0x080CFF54
	ldr r0, .L080CFF5C @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	bx lr
	.align 2, 0
.L080CFF5C: .4byte gJoyBusContext
func_080CFF60: @ 0x080CFF60
	push {lr}
	ldr r0, .L080CFF7C @ =gJoyBusContext
	ldr r0, [r0]
	ldr r2, [r0, #0x20]
	cmp r2, #0
	beq .L080CFF80
	ldr r1, [r0, #0x1c]
	movs r0, #0x64
	muls r0, r1
	adds r1, r2, #0
	bl __udivsi3
	b .L080CFF82
	.align 2, 0
.L080CFF7C: .4byte gJoyBusContext
.L080CFF80:
	movs r0, #0
.L080CFF82:
	pop {r1}
	bx r1
	.align 2, 0
    .global func_080D0704
    .thumb_func
func_080D0704: @ 0x080CFF88
	push {r4, r5, lr}
	sub sp, #4
	movs r5, #0
	ldr r0, .L080D0000 @ =0x04000140
	ldrh r0, [r0]
	adds r4, r0, #0
	ldr r0, .L080D0004 @ =gJoyBusContext
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne .L080CFFD8
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080CFFBA
	ldr r0, .L080D0008 @ =0x04000150
	ldr r0, [r0]
	str r0, [sp]
	mov r0, sp
	bl func_080D078C
	adds r5, r0, #0
.L080CFFBA:
	cmp r5, #0
	bne .L080CFFCC
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq .L080CFFCC
	bl func_080D091C
	adds r5, r0, #0
.L080CFFCC:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080CFFD8
	bl func_080D0A14
.L080CFFD8:
	cmp r5, #0
	beq .L080CFFE8
	ldr r1, .L080D000C @ =0x04000158
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FinishJoyBusCommand
.L080CFFE8:
	ldr r0, .L080D0000 @ =0x04000140
	strh r4, [r0]
	ldr r0, .L080D0004 @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0xc]
	str r0, [r1, #0x10]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0000: .4byte 0x04000140
.L080D0004: .4byte gJoyBusContext
.L080D0008: .4byte 0x04000150
.L080D000C: .4byte 0x04000158
    .global func_080D078C
    .thumb_func
func_080D078C: @ 0x080D0010
	push {r4, r5, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r0, .L080D0030 @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r1, [r2]
	adds r5, r0, #0
	cmp r1, #4
	bls .L080D0024
	b .L080D0190
.L080D0024:
	ldr r0, [r2]
	lsls r0, r0, #2
	ldr r1, .L080D0034 @ =.L080D0038
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D0030: .4byte gCurrentJoyBusCommand
.L080D0034: .4byte .L080D0038
.L080D0038: @ jump table
	.4byte .L080D0194 @ case 0
	.4byte .L080D004C @ case 1
	.4byte .L080D0080 @ case 2
	.4byte .L080D00BE @ case 3
	.4byte .L080D0080 @ case 4
.L080D004C:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	cmp r0, #1
	bhi .L080D0056
	b .L080D0194
.L080D0056:
	cmp r0, #2
	beq .L080D005C
	b .L080D0194
.L080D005C:
	ldr r0, .L080D006C @ =gJoyBusContext
	ldr r0, [r0]
	ldr r1, [r3]
	ldr r0, [r0, #8]
	cmp r1, r0
	beq .L080D0070
	movs r0, #1
	b .L080D0196
	.align 2, 0
.L080D006C: .4byte gJoyBusContext
.L080D0070:
	ldr r1, .L080D007C @ =0x04000158
	movs r0, #0x30
	strh r0, [r1]
.L080D0076:
	bl ResetJoyBusCommandResult
	b .L080D0194
	.align 2, 0
.L080D007C: .4byte 0x04000158
.L080D0080:
	ldr r4, [r5]
	ldr r0, [r4, #4]
	cmp r0, #1
	beq .L080D00BA
	cmp r0, #1
	blo .L080D0092
	cmp r0, #2
	beq .L080D00B4
	b .L080D0194
.L080D0092:
	ldrb r0, [r3]
	cmp r0, #0x42
	bne .L080D00AC
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldr r1, [r4, #0x18]
	cmp r0, r1
	bne .L080D00E4
	mov r1, sp
	movs r2, #0x43
	b .L080D0170
.L080D00AC:
	cmp r0, #0x41
	bne .L080D0194
	movs r0, #5
	b .L080D0196
.L080D00B4:
	ldrb r0, [r3]
	cmp r0, #0x46
	beq .L080D0076
.L080D00BA:
	movs r0, #7
	b .L080D0196
.L080D00BE:
	ldr r4, [r5]
	ldr r0, [r4, #4]
	cmp r0, #1
	beq .L080D00F6
	cmp r0, #1
	blo .L080D00D0
	cmp r0, #2
	beq .L080D018C
	b .L080D0194
.L080D00D0:
	ldrb r0, [r3]
	cmp r0, #0x41
	bne .L080D00EE
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldr r1, [r4, #0x18]
	cmp r0, r1
	beq .L080D00E8
.L080D00E4:
	movs r0, #4
	b .L080D0196
.L080D00E8:
	mov r1, sp
	movs r2, #0x43
	b .L080D0170
.L080D00EE:
	cmp r0, #0x42
	bne .L080D0194
	movs r0, #6
	b .L080D0196
.L080D00F6:
	ldr r1, [r4, #8]
	ldr r0, [r4, #0x18]
	cmp r1, r0
	bhs .L080D0154
	ldrb r0, [r3]
	cmp r0, #0x44
	bne .L080D018C
	ldrb r0, [r3, #1]
	ldr r1, [r4, #8]
	movs r2, #0xff
	ands r1, r2
	cmp r0, r1
	bne .L080D018C
	ldr r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x10]
	adds r0, r0, r1
	ldrb r1, [r3, #2]
	strb r1, [r0]
	ldrb r1, [r3, #3]
	strb r1, [r0, #1]
	ldr r2, [r5]
	ldr r0, [r2, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x10]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r2, #0x1c]
	adds r1, r1, r0
	strh r1, [r2, #0x1c]
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	ldr r0, .L080D0150 @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b .L080D0194
	.align 2, 0
.L080D0150: .4byte gJoyBusContext
.L080D0154:
	ldrb r0, [r3]
	cmp r0, #0x45
	bne .L080D018C
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldrh r1, [r4, #0x1c]
	cmp r1, r0
	beq .L080D016C
	movs r0, #3
	b .L080D0196
.L080D016C:
	mov r1, sp
	movs r2, #0x46
.L080D0170:
	movs r0, #0
	strb r2, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	ldr r1, .L080D0188 @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	b .L080D0194
	.align 2, 0
.L080D0188: .4byte 0x04000154
.L080D018C:
	movs r0, #8
	b .L080D0196
.L080D0190:
	movs r0, #9
	b .L080D0196
.L080D0194:
	movs r0, #0
.L080D0196:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
    .global func_080D091C
    .thumb_func
func_080D091C: @ 0x080D01A0
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080D01BC @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r1, [r2]
	adds r3, r0, #0
	cmp r1, #4
	bhi .L080D028A
	ldr r0, [r2]
	lsls r0, r0, #2
	ldr r1, .L080D01C0 @ =.L080D01C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D01BC: .4byte gCurrentJoyBusCommand
.L080D01C0: .4byte .L080D01C4
.L080D01C4: @ jump table
	.4byte .L080D028E @ case 0
	.4byte .L080D01D8 @ case 1
	.4byte .L080D01E8 @ case 2
	.4byte .L080D0278 @ case 3
	.4byte .L080D01E8 @ case 4
.L080D01D8:
	ldr r1, [r3]
	ldr r0, [r1, #4]
	cmp r0, #1
	bne .L080D028E
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	b .L080D028E
.L080D01E8:
	ldr r5, [r3]
	ldr r0, [r5, #4]
	cmp r0, #1
	bne .L080D028E
	ldr r1, [r5, #8]
	ldr r0, [r5, #0x18]
	cmp r1, r0
	bhs .L080D0254
	ldr r1, [r5, #8]
	mov r2, sp
	movs r3, #0x44
	ldr r4, [r5, #8]
	lsls r1, r1, #1
	ldr r0, [r5, #0x10]
	adds r1, r1, r0
	strb r3, [r2]
	strb r4, [r2, #1]
	ldrb r0, [r1]
	strb r0, [r2, #2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #3]
	ldr r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x10]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	ldr r1, .L080D024C @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	ldr r0, [r5]
	cmp r0, #4
	beq .L080D028E
	ldr r0, .L080D0250 @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b .L080D028E
	.align 2, 0
.L080D024C: .4byte 0x04000154
.L080D0250: .4byte gJoyBusContext
.L080D0254:
	ldrh r2, [r5, #0x1c]
	mov r1, sp
	movs r0, #0x45
	strb r0, [r1]
	movs r0, #0
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	lsrs r2, r2, #8
	strb r2, [r1, #3]
	ldr r1, .L080D0274 @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	b .L080D028E
	.align 2, 0
.L080D0274: .4byte 0x04000154
.L080D0278:
	ldr r0, [r3]
	ldr r0, [r0, #4]
	cmp r0, #1
	bls .L080D028E
	cmp r0, #2
	bne .L080D028E
	bl ResetJoyBusCommandResult
	b .L080D028E
.L080D028A:
	movs r0, #9
	b .L080D0290
.L080D028E:
	movs r0, #0
.L080D0290:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
    .global func_080D0A14
    .thumb_func
func_080D0A14: @ 0x080D0298
	push {lr}
	ldr r0, .L080D02C8 @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r0, [r2]
	cmp r0, #1
	bne .L080D02C4
	ldr r0, [r2, #4]
	cmp r0, #2
	bhi .L080D02C4
	ldr r0, .L080D02CC @ =0x04000150
	ldr r0, [r0]
	ldr r1, .L080D02D0 @ =0x04000154
	ldr r0, .L080D02D4 @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r1]
	adds r1, #4
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
.L080D02C4:
	pop {r0}
	bx r0
	.align 2, 0
.L080D02C8: .4byte gCurrentJoyBusCommand
.L080D02CC: .4byte 0x04000150
.L080D02D0: .4byte 0x04000154
.L080D02D4: .4byte gJoyBusContext
    .section .text.joy_bus_flagged_result, "ax", %progbits
    .align 2, 0

    .global func_080D0A94
    .thumb_func
func_080D0A94: @ 0x080D0318
	push {r4, r5, lr}
	ldr r5, .L080D033C @ =gJoyBusContext
	ldr r1, [r5]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r1, r4
	movs r2, #1
	str r2, [r1]
	bl FinishJoyBusCommand
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D033C: .4byte gJoyBusContext
    .section .text.joy_bus_register_setup, "ax", %progbits
    .align 2, 0

    .global ConfigureJoyBusRegisters
    .thumb_func
ConfigureJoyBusRegisters:
    push {r4, lr}
    adds r3, r1, #0
    ldr r2, [pc, #0x28]
    ldrh r1, [r2]
    adds r4, r1, #0
    movs r1, #0
    strh r1, [r2]
    cmp r0, #0
    beq .Lauto_080D03B4
    ldr r1, [pc, #0x20]
    .byte 0x80, 0x22, 0x12, 0x02, 0x10, 0x1C, 0x08, 0x80
    .Lauto_080D03B4:
    ldr r1, [pc, #0x14]
    movs r2, #0xc0
    lsls r2, r2, #8
    adds r0, r2, #0
    strh r0, [r1]
    cmp r3, #0
    bne .Lauto_080D03D4
    ldr r0, [pc, #0xc]
    strh r3, [r0]
    b .Lauto_080D03DA
    .byte 0x08, 0x02, 0x00, 0x04, 0x34, 0x01, 0x00, 0x04, 0x58, 0x01, 0x00, 0x04
    .Lauto_080D03D4:
    ldr r1, [pc, #0x24]
    movs r0, #0x30
    strh r0, [r1]
    .Lauto_080D03DA:
    ldr r0, [pc, #0x24]
    ldr r0, [r0]
    ldr r1, [pc, #0x24]
    movs r0, #0
    str r0, [r1]
    subs r1, #0x14
    movs r0, #0x47
    strh r0, [r1]
    adds r1, #0xc2
    movs r0, #0x80
    strh r0, [r1]
    ldr r0, [pc, #0x14]
    strh r4, [r0]
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x58, 0x01, 0x00, 0x04, 0x50, 0x01, 0x00, 0x04, 0x54, 0x01, 0x00, 0x04, 0x08, 0x02
    .byte 0x00, 0x04
    .else
    .section .text.joy_bus_link_reset, "ax", %progbits
    .align 2, 0

	thumb_func_start ResetJoyBusLinkRegisters
ResetJoyBusLinkRegisters: @ 0x080D02EC
	.ifdef REGION_DE
	@ DE shares the extended link-register reset used by the EU build.
	ldr r1, .L080D02EC_DE
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
.L080D02EC_DE: .4byte 0x04000128
	.else
	.ifdef REGION_EU
	@ EU places a small link-register reset here before the common runtime
	@ initializer.  It occupies 0x18 bytes in the original regional layout.
	ldr r1, .L080D02EC_EU
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
.L080D02EC_EU: .4byte 0x04000128
	.else
	bx lr
	.align 2, 0
	.endif
	.endif

    .section .text.joy_bus_update, "ax", %progbits
    .align 2, 0

	thumb_func_start UpdateJoyBusCommunication
UpdateJoyBusCommunication: @ 0x080D035C
	push {r4, r5, lr}
	ldr r5, .L080D039C @ =gJoyBusContext
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, #0
	beq .L080D0436
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, #0x1c]
	ldr r0, .L080D03A0 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D03C2
	bl IsJoyBusCommandQueueEmpty
	cmp r0, #0
	bne .L080D03A4
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne .L080D03A4
	bl AdvanceJoyBusCommandQueue
	ldr r0, [r5]
	str r4, [r0, #0x10]
	b .L080D03C2
	.align 2, 0
.L080D039C: .4byte gJoyBusContext
.L080D03A0: .4byte gCurrentJoyBusCommand
.L080D03A4:
	ldr r0, .L080D03F0 @ =gJoyBusContext
	ldr r3, [r0]
	ldr r0, [r3, #0x14]
	cmp r0, #0
	beq .L080D03C2
	movs r2, #0
	str r2, [r3, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	str r0, [r3, #0x18]
	str r2, [r1]
	bl ClearJoyBusCommandQueue
.L080D03C2:
	ldr r0, .L080D03F0 @ =gJoyBusContext
	ldr r1, [r0]
	ldr r0, [r1, #0xc]
	adds r0, #1
	str r0, [r1, #0xc]
	ldr r0, [r1, #0xc]
	cmp r0, #0xa
	bls .L080D0400
	movs r0, #0
	str r0, [r1, #0xc]
	ldr r0, .L080D03F4 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	beq .L080D0400
	cmp r0, #1
	bne .L080D03F8
	movs r0, #1
	movs r1, #0
	bl ConfigureJoyBusRegisters
	b .L080D0400
	.align 2, 0
.L080D03F0: .4byte gJoyBusContext
.L080D03F4: .4byte gCurrentJoyBusCommand
.L080D03F8:
	movs r0, #1
	movs r1, #1
	bl ConfigureJoyBusRegisters
.L080D0400:
	ldr r4, .L080D043C @ =gJoyBusContext
	ldr r1, [r4]
	ldr r0, [r1, #0x10]
	adds r0, #1
	str r0, [r1, #0x10]
	ldr r0, .L080D0440 @ =gCurrentJoyBusCommand
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #1
	bls .L080D0436
	ldr r0, [r1, #0x10]
	cmp r0, #0xb4
	bls .L080D0436
	movs r0, #0xb
	bl func_080D0A94
	ldr r0, [r4]
	movs r2, #0
	str r2, [r0, #0x14]
	movs r1, #0xa
	str r1, [r0, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r2, [r0]
	bl ClearJoyBusCommandQueue
.L080D0436:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D043C: .4byte gJoyBusContext
.L080D0440: .4byte gCurrentJoyBusCommand

	thumb_func_start func_080D0444
func_080D0444: @ 0x080D0444
	ldr r2, .L080D0450 @ =gJoyBusContext
	ldr r2, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	bx lr
	.align 2, 0
.L080D0450: .4byte gJoyBusContext

	thumb_func_start func_080D0454
func_080D0454: @ 0x080D0454
	push {r4, lr}
	sub sp, #0x20
	ldr r4, .L080D048C @ =gJoyBusContext
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1, #0x14]
	str r0, [sp]
	mov r0, sp
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x18]
	mov r1, sp
	movs r0, #0
	strh r0, [r1, #0x1c]
	mov r0, sp
	bl EnqueueJoyBusCommand
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080D048C: .4byte gJoyBusContext
.L080D0490:
	.byte 0x70, 0xB5, 0x4E, 0x46, 0x45, 0x46, 0x60, 0xB4, 0x88, 0xB0, 0x81, 0x46, 0x0E, 0x1C, 0x14, 0x48
	.byte 0x80, 0x46, 0x01, 0x68, 0x02, 0x24, 0x4C, 0x61, 0x04, 0x20, 0x00, 0x90, 0x24, 0x31, 0x04, 0x91
	.byte 0x06, 0x94, 0x68, 0x46, 0x00, 0x25, 0x85, 0x83
	bl EnqueueJoyBusCommand
	.byte 0x00, 0x94, 0x49, 0x46
	.byte 0x04, 0x91, 0x01, 0x36, 0x76, 0x08, 0x06, 0x96, 0x68, 0x46, 0x85, 0x83
	bl EnqueueJoyBusCommand
	.byte 0x41, 0x46, 0x08, 0x68, 0xC5, 0x61, 0x06, 0x62, 0xC2, 0x21, 0x49, 0x00, 0x40, 0x18, 0x05, 0x60
	.byte 0x08, 0xB0, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
.L080D04F0: .4byte gJoyBusContext
	.byte 0x70, 0xB5, 0x4E, 0x46, 0x45, 0x46, 0x60, 0xB4, 0x88, 0xB0, 0x81, 0x46
	.byte 0x0D, 0x1C, 0x14, 0x48, 0x80, 0x46, 0x01, 0x68, 0x03, 0x26, 0x4E, 0x61, 0x04, 0x20, 0x00, 0x90
	.byte 0x24, 0x31, 0x04, 0x91, 0x02, 0x20, 0x06, 0x90, 0x68, 0x46, 0x00, 0x24, 0x84, 0x83
	bl EnqueueJoyBusCommand
	.byte 0x00, 0x96, 0x49, 0x46, 0x04, 0x91, 0x01, 0x35, 0x6D, 0x08, 0x06, 0x95, 0x68, 0x46
	.byte 0x84, 0x83
	bl EnqueueJoyBusCommand
	.byte 0x41, 0x46, 0x08, 0x68, 0xC4, 0x61, 0x05, 0x62, 0xC2, 0x21
	.byte 0x49, 0x00, 0x40, 0x18, 0x04, 0x60, 0x08, 0xB0, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0x70, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47
.L080D0554: .4byte gJoyBusContext

	thumb_func_start func_080D0558
func_080D0558: @ 0x080D0558
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r3, #0
	ldr r0, .L080D05D8 @ =gJoyBusContext
	mov sl, r0
	ldr r0, [r0]
	movs r1, #4
	str r1, [r0, #0x14]
	str r1, [sp]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r1, #2
	mov r8, r1
	str r1, [sp, #0x18]
	mov r0, sp
	movs r5, #0
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #0x10]
	adds r6, #1
	lsrs r6, r6, #1
	str r6, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, r8
	str r1, [sp]
	str r7, [sp, #0x10]
	adds r4, #1
	lsrs r4, r4, #1
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	mov r1, sl
	ldr r0, [r1]
	str r5, [r0, #0x1c]
	adds r4, r4, r6
	str r4, [r0, #0x20]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	str r5, [r0]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080D05D8: .4byte gJoyBusContext

	thumb_func_start func_080D05DC
func_080D05DC: @ 0x080D05DC
	push {r4, r5, r6, lr}
	sub sp, #0x20
	ldr r6, .L080D0640 @ =gJoyBusContext
	ldr r0, [r6]
	movs r1, #5
	str r1, [r0, #0x14]
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq .L080D05F8
	movs r0, #1
	str r0, [sp]
	mov r0, sp
	bl EnqueueJoyBusCommand
.L080D05F8:
	movs r0, #4
	str r0, [sp]
	ldr r0, [r6]
	adds r0, #0x24
	str r0, [sp, #0x10]
	movs r4, #2
	str r4, [sp, #0x18]
	mov r0, sp
	movs r5, #0
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	movs r0, #3
	str r0, [sp]
	ldr r0, [r6]
	adds r0, #0x2c
	str r0, [sp, #0x10]
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	str r4, [sp]
	ldr r0, [r6]
	adds r0, #0x28
	str r0, [sp, #0x10]
	str r4, [sp, #0x18]
	mov r0, sp
	strh r5, [r0, #0x1c]
	bl EnqueueJoyBusCommand
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0640: .4byte gJoyBusContext

	thumb_func_start func_080D0644
func_080D0644: @ 0x080D0644
	push {r4, lr}
	ldr r4, .L080D0674 @ =gJoyBusContext
	ldr r2, [r4]
	adds r2, #0x28
	strb r0, [r2]
	ldr r2, [r4]
	lsrs r3, r0, #8
	adds r2, #0x29
	strb r3, [r2]
	ldr r2, [r4]
	lsrs r3, r0, #0x10
	adds r2, #0x2a
	strb r3, [r2]
	ldr r2, [r4]
	lsrs r0, r0, #0x18
	adds r2, #0x2b
	strb r0, [r2]
	ldr r0, [r4]
	str r1, [r0, #0x30]
	bl func_080D05DC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0674: .4byte gJoyBusContext

	thumb_func_start func_080D0678
func_080D0678: @ 0x080D0678
	ldr r0, .L080D06A4 @ =gJoyBusContext
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	lsls r1, r1, #8
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	orrs r0, r1
	bx lr
	.align 2, 0
.L080D06A4: .4byte gJoyBusContext

	thumb_func_start func_080D06A8
func_080D06A8: @ 0x080D06A8
	push {lr}
	movs r0, #0xb
	bl func_080D0A94
	pop {r0}
	bx r0

	thumb_func_start func_080D06B4
func_080D06B4: @ 0x080D06B4
	push {lr}
	movs r1, #0
	ldr r0, .L080D06CC @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne .L080D06C4
	movs r1, #1
.L080D06C4:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
.L080D06CC: .4byte gJoyBusContext

	thumb_func_start func_080D06D0
func_080D06D0: @ 0x080D06D0
	ldr r0, .L080D06D8 @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	bx lr
	.align 2, 0
.L080D06D8: .4byte gJoyBusContext
.L080D06DC:
	.byte 0x00, 0xB5, 0x06, 0x48
	.byte 0x00, 0x68, 0x02, 0x6A, 0x00, 0x2A, 0x09, 0xD0, 0xC1, 0x69, 0x64, 0x20, 0x48, 0x43, 0x11, 0x1C
	bl __udivsi3
	.byte 0x03, 0xE0, 0x00, 0x00
.L080D06F8: .4byte gJoyBusContext
	.byte 0x00, 0x20, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start func_080D0704
func_080D0704: @ 0x080D0704
	push {r4, r5, lr}
	sub sp, #4
	movs r5, #0
	ldr r0, .L080D077C @ =0x04000140
	ldrh r0, [r0]
	adds r4, r0, #0
	ldr r0, .L080D0780 @ =gJoyBusContext
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D0754
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080D0736
	ldr r0, .L080D0784 @ =0x04000150
	ldr r0, [r0]
	str r0, [sp]
	mov r0, sp
	bl func_080D078C
	adds r5, r0, #0
.L080D0736:
	cmp r5, #0
	bne .L080D0748
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq .L080D0748
	bl func_080D091C
	adds r5, r0, #0
.L080D0748:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080D0754
	bl func_080D0A14
.L080D0754:
	cmp r5, #0
	beq .L080D0764
	ldr r1, .L080D0788 @ =0x04000158
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FinishJoyBusCommand
.L080D0764:
	ldr r0, .L080D077C @ =0x04000140
	strh r4, [r0]
	ldr r0, .L080D0780 @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0xc]
	str r0, [r1, #0x10]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D077C: .4byte 0x04000140
.L080D0780: .4byte gJoyBusContext
.L080D0784: .4byte 0x04000150
.L080D0788: .4byte 0x04000158

	thumb_func_start func_080D078C
func_080D078C: @ 0x080D078C
	push {r4, r5, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r0, .L080D07AC @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r1, [r2]
	adds r5, r0, #0
	cmp r1, #4
	bls .L080D07A0
	b .L080D090C
.L080D07A0:
	ldr r0, [r2]
	lsls r0, r0, #2
	ldr r1, .L080D07B0 @ =.L080D07B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D07AC: .4byte gCurrentJoyBusCommand
.L080D07B0: .4byte .L080D07B4
.L080D07B4: @ jump table
	.4byte .L080D0910 @ case 0
	.4byte .L080D07C8 @ case 1
	.4byte .L080D07FC @ case 2
	.4byte .L080D083A @ case 3
	.4byte .L080D07FC @ case 4
.L080D07C8:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	cmp r0, #1
	bhi .L080D07D2
	b .L080D0910
.L080D07D2:
	cmp r0, #2
	beq .L080D07D8
	b .L080D0910
.L080D07D8:
	ldr r0, .L080D07E8 @ =gJoyBusContext
	ldr r0, [r0]
	ldr r1, [r3]
	ldr r0, [r0, #8]
	cmp r1, r0
	beq .L080D07EC
	movs r0, #1
	b .L080D0912
	.align 2, 0
.L080D07E8: .4byte gJoyBusContext
.L080D07EC:
	ldr r1, .L080D07F8 @ =0x04000158
	movs r0, #0x30
	strh r0, [r1]
.L080D07F2:
	bl ResetJoyBusCommandResult
	b .L080D0910
	.align 2, 0
.L080D07F8: .4byte 0x04000158
.L080D07FC:
	ldr r4, [r5]
	ldr r0, [r4, #4]
	cmp r0, #1
	beq .L080D0836
	cmp r0, #1
	blo .L080D080E
	cmp r0, #2
	beq .L080D0830
	b .L080D0910
.L080D080E:
	ldrb r0, [r3]
	cmp r0, #0x42
	bne .L080D0828
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldr r1, [r4, #0x18]
	cmp r0, r1
	bne .L080D0860
	mov r1, sp
	movs r2, #0x43
	b .L080D08EC
.L080D0828:
	cmp r0, #0x41
	bne .L080D0910
	movs r0, #5
	b .L080D0912
.L080D0830:
	ldrb r0, [r3]
	cmp r0, #0x46
	beq .L080D07F2
.L080D0836:
	movs r0, #7
	b .L080D0912
.L080D083A:
	ldr r4, [r5]
	ldr r0, [r4, #4]
	cmp r0, #1
	beq .L080D0872
	cmp r0, #1
	blo .L080D084C
	cmp r0, #2
	beq .L080D0908
	b .L080D0910
.L080D084C:
	ldrb r0, [r3]
	cmp r0, #0x41
	bne .L080D086A
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldr r1, [r4, #0x18]
	cmp r0, r1
	beq .L080D0864
.L080D0860:
	movs r0, #4
	b .L080D0912
.L080D0864:
	mov r1, sp
	movs r2, #0x43
	b .L080D08EC
.L080D086A:
	cmp r0, #0x42
	bne .L080D0910
	movs r0, #6
	b .L080D0912
.L080D0872:
	ldr r1, [r4, #8]
	ldr r0, [r4, #0x18]
	cmp r1, r0
	bhs .L080D08D0
	ldrb r0, [r3]
	cmp r0, #0x44
	bne .L080D0908
	ldrb r0, [r3, #1]
	ldr r1, [r4, #8]
	movs r2, #0xff
	ands r1, r2
	cmp r0, r1
	bne .L080D0908
	ldr r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x10]
	adds r0, r0, r1
	ldrb r1, [r3, #2]
	strb r1, [r0]
	ldrb r1, [r3, #3]
	strb r1, [r0, #1]
	ldr r2, [r5]
	ldr r0, [r2, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x10]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r2, #0x1c]
	adds r1, r1, r0
	strh r1, [r2, #0x1c]
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	ldr r0, .L080D08CC @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b .L080D0910
	.align 2, 0
.L080D08CC: .4byte gJoyBusContext
.L080D08D0:
	ldrb r0, [r3]
	cmp r0, #0x45
	bne .L080D0908
	ldrb r0, [r3, #2]
	ldrb r1, [r3, #3]
	lsls r1, r1, #8
	orrs r0, r1
	ldrh r1, [r4, #0x1c]
	cmp r1, r0
	beq .L080D08E8
	movs r0, #3
	b .L080D0912
.L080D08E8:
	mov r1, sp
	movs r2, #0x46
.L080D08EC:
	movs r0, #0
	strb r2, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	ldr r1, .L080D0904 @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	b .L080D0910
	.align 2, 0
.L080D0904: .4byte 0x04000154
.L080D0908:
	movs r0, #8
	b .L080D0912
.L080D090C:
	movs r0, #9
	b .L080D0912
.L080D0910:
	movs r0, #0
.L080D0912:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080D091C
func_080D091C: @ 0x080D091C
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080D0938 @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r1, [r2]
	adds r3, r0, #0
	cmp r1, #4
	bhi .L080D0A06
	ldr r0, [r2]
	lsls r0, r0, #2
	ldr r1, .L080D093C @ =.L080D0940
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D0938: .4byte gCurrentJoyBusCommand
.L080D093C: .4byte .L080D0940
.L080D0940: @ jump table
	.4byte .L080D0A0A @ case 0
	.4byte .L080D0954 @ case 1
	.4byte .L080D0964 @ case 2
	.4byte .L080D09F4 @ case 3
	.4byte .L080D0964 @ case 4
.L080D0954:
	ldr r1, [r3]
	ldr r0, [r1, #4]
	cmp r0, #1
	bne .L080D0A0A
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	b .L080D0A0A
.L080D0964:
	ldr r5, [r3]
	ldr r0, [r5, #4]
	cmp r0, #1
	bne .L080D0A0A
	ldr r1, [r5, #8]
	ldr r0, [r5, #0x18]
	cmp r1, r0
	bhs .L080D09D0
	ldr r1, [r5, #8]
	mov r2, sp
	movs r3, #0x44
	ldr r4, [r5, #8]
	lsls r1, r1, #1
	ldr r0, [r5, #0x10]
	adds r1, r1, r0
	strb r3, [r2]
	strb r4, [r2, #1]
	ldrb r0, [r1]
	strb r0, [r2, #2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #3]
	ldr r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x10]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r5, #0x1c]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	ldr r1, .L080D09C8 @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	ldr r0, [r5]
	cmp r0, #4
	beq .L080D0A0A
	ldr r0, .L080D09CC @ =gJoyBusContext
	ldr r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b .L080D0A0A
	.align 2, 0
.L080D09C8: .4byte 0x04000154
.L080D09CC: .4byte gJoyBusContext
.L080D09D0:
	ldrh r2, [r5, #0x1c]
	mov r1, sp
	movs r0, #0x45
	strb r0, [r1]
	movs r0, #0
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	lsrs r2, r2, #8
	strb r2, [r1, #3]
	ldr r1, .L080D09F0 @ =0x04000154
	ldr r0, [sp]
	str r0, [r1]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	b .L080D0A0A
	.align 2, 0
.L080D09F0: .4byte 0x04000154
.L080D09F4:
	ldr r0, [r3]
	ldr r0, [r0, #4]
	cmp r0, #1
	bls .L080D0A0A
	cmp r0, #2
	bne .L080D0A0A
	bl ResetJoyBusCommandResult
	b .L080D0A0A
.L080D0A06:
	movs r0, #9
	b .L080D0A0C
.L080D0A0A:
	movs r0, #0
.L080D0A0C:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_080D0A14
func_080D0A14: @ 0x080D0A14
	push {lr}
	ldr r0, .L080D0A44 @ =gCurrentJoyBusCommand
	ldr r2, [r0]
	ldr r0, [r2]
	cmp r0, #1
	bne .L080D0A40
	ldr r0, [r2, #4]
	cmp r0, #2
	bhi .L080D0A40
	ldr r0, .L080D0A48 @ =0x04000150
	ldr r0, [r0]
	ldr r1, .L080D0A4C @ =0x04000154
	ldr r0, .L080D0A50 @ =gJoyBusContext
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r1]
	adds r1, #4
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
.L080D0A40:
	pop {r0}
	bx r0
	.align 2, 0
.L080D0A44: .4byte gCurrentJoyBusCommand
.L080D0A48: .4byte 0x04000150
.L080D0A4C: .4byte 0x04000154
.L080D0A50: .4byte gJoyBusContext

    .section .text.joy_bus_flagged_result, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080D0A94
func_080D0A94: @ 0x080D0A94
	push {r4, r5, lr}
	ldr r5, .L080D0AB8 @ =gJoyBusContext
	ldr r1, [r5]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r1, r4
	movs r2, #1
	str r2, [r1]
	bl FinishJoyBusCommand
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0AB8: .4byte gJoyBusContext

    .section .text.joy_bus_register_setup, "ax", %progbits
    .align 2, 0

	thumb_func_start ConfigureJoyBusRegisters
ConfigureJoyBusRegisters: @ 0x080D0B14
	.ifdef REGION_DE
	@ DE uses the same expanded hardware-reset routine as EU.
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, .L080D0B14_DE_0208
	ldrh r1, [r2]
	adds r5, r1, #0
	movs r3, #0
	strh r3, [r2]
	cmp r0, #0
	beq .L080D0B14_DE_0134
	ldr r0, .L080D0B14_DE_0128
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #0xc
	strh r3, [r0]
.L080D0B14_DE_0134:
	ldr r1, .L080D0B14_DE_0134_VALUE
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	cmp r4, #0
	bne .L080D0B14_DE_0158_SET
	ldr r0, .L080D0B14_DE_0158
	strh r4, [r0]
	b .L080D0B14_DE_0150_RESET
	.align 2, 0
.L080D0B14_DE_0208: .4byte 0x04000208
.L080D0B14_DE_0128: .4byte 0x04000128
.L080D0B14_DE_0134_VALUE: .4byte 0x04000134
.L080D0B14_DE_0158: .4byte 0x04000158
.L080D0B14_DE_0158_SET:
	ldr r1, .L080D0B14_DE_0158_SET_VALUE
	movs r0, #0x30
	strh r0, [r1]
.L080D0B14_DE_0150_RESET:
	ldr r0, .L080D0B14_DE_0150
	ldr r0, [r0]
	ldr r1, .L080D0B14_DE_0154
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	movs r0, #0x47
	strh r0, [r1]
	adds r1, #0xc2
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, .L080D0B14_DE_0208_END
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0B14_DE_0158_SET_VALUE: .4byte 0x04000158
.L080D0B14_DE_0150: .4byte 0x04000150
.L080D0B14_DE_0154: .4byte 0x04000154
.L080D0B14_DE_0208_END: .4byte 0x04000208
	.else
	.ifdef REGION_EU
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, .L080D0B14_EU_0208
	ldrh r1, [r2]
	adds r5, r1, #0
	movs r3, #0
	strh r3, [r2]
	cmp r0, #0
	beq .L080D0B14_EU_0134
	ldr r0, .L080D0B14_EU_0128
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #0xc
	strh r3, [r0]
.L080D0B14_EU_0134:
	ldr r1, .L080D0B14_EU_0134_VALUE
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	cmp r4, #0
	bne .L080D0B14_EU_0158_SET
	ldr r0, .L080D0B14_EU_0158
	strh r4, [r0]
	b .L080D0B14_EU_0150_RESET
	.align 2, 0
.L080D0B14_EU_0208: .4byte 0x04000208
.L080D0B14_EU_0128: .4byte 0x04000128
.L080D0B14_EU_0134_VALUE: .4byte 0x04000134
.L080D0B14_EU_0158: .4byte 0x04000158
.L080D0B14_EU_0158_SET:
	ldr r1, .L080D0B14_EU_0158_SET_VALUE
	movs r0, #0x30
	strh r0, [r1]
.L080D0B14_EU_0150_RESET:
	ldr r0, .L080D0B14_EU_0150
	ldr r0, [r0]
	ldr r1, .L080D0B14_EU_0154
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	movs r0, #0x47
	strh r0, [r1]
	adds r1, #0xc2
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, .L080D0B14_EU_0208_END
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0B14_EU_0158_SET_VALUE: .4byte 0x04000158
.L080D0B14_EU_0150: .4byte 0x04000150
.L080D0B14_EU_0154: .4byte 0x04000154
.L080D0B14_EU_0208_END: .4byte 0x04000208
	.else
	push {r4, lr}
	adds r3, r1, #0
	ldr r2, .L080D0B44 @ =0x04000208
	ldrh r1, [r2]
	adds r4, r1, #0
	movs r1, #0
	strh r1, [r2]
	cmp r0, #0
	beq .L080D0B30
	ldr r1, .L080D0B48 @ =0x04000134
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
.L080D0B30:
	ldr r1, .L080D0B48 @ =0x04000134
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	cmp r3, #0
	bne .L080D0B50
	ldr r0, .L080D0B4C @ =0x04000158
	strh r3, [r0]
	b .L080D0B56
	.align 2, 0
.L080D0B44: .4byte 0x04000208
.L080D0B48: .4byte 0x04000134
.L080D0B4C: .4byte 0x04000158
.L080D0B50:
	ldr r1, .L080D0B78 @ =0x04000158
	movs r0, #0x30
	strh r0, [r1]
.L080D0B56:
	ldr r0, .L080D0B7C @ =0x04000150
	ldr r0, [r0]
	ldr r1, .L080D0B80 @ =0x04000154
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	movs r0, #0x47
	strh r0, [r1]
	adds r1, #0xc2
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, .L080D0B84 @ =0x04000208
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080D0B78: .4byte 0x04000158
.L080D0B7C: .4byte 0x04000150
.L080D0B80: .4byte 0x04000154
.L080D0B84: .4byte 0x04000208
	.endif
	.endif
    .endif

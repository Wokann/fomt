    .include "asm/macro.inc"
    .syntax unified
    .section .text, "ax", %progbits
    .thumb
    .align 2, 0

    @ Score approach/retreat facings against movement limits and break ties randomly.
    @ Local-label numbers are US disassembly references, not linked addresses.


	thumb_func_start SelectApproachFacing
SelectApproachFacing:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r4, [sp, #0x44]
	subs r2, r2, r0
	str r2, [sp, #0x10]
	subs r3, r3, r1
	mov sl, r3
	adds r1, r2, #0
	cmp r2, #0
	bge .L080ABC5E
	rsbs r1, r2, #0
.L080ABC5E:
	mov r0, sl
	cmp r0, #0
	bge .L080ABC66
	rsbs r0, r0, #0
.L080ABC66:
	movs r2, #0
	str r2, [sp, #0x14]
	lsls r2, r1, #1
	lsls r3, r0, #1
	adds r0, r3, r0
	cmp r2, r0
	ble .L080ABC7A
	movs r5, #1
	str r5, [sp, #0x14]
	b .L080ABC86
.L080ABC7A:
	adds r0, r2, r1
	cmp r0, r3
	bge .L080ABC86
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x14]
.L080ABC86:
	ldr r1, .L080ABCB8 @ =0x7FFFFFFF
	str r1, [sp, #0x18]
	movs r2, #0
	str r2, [sp, #0x1c]
	movs r5, #0
	str r5, [sp, #0x20]
.L080ABC92:
	ldr r7, [sp, #0x20]
	ldr r0, [sp, #0x48]
	adds r1, r7, #0
	bl GetRelativeFacing
	adds r5, r0, #0
	movs r0, #1
	mov r8, r0
	movs r1, #0
	mov sb, r1
	movs r1, #1
	cmp r5, #1
	beq .L080ABD04
	cmp r5, #1
	bgt .L080ABCBC
	cmp r5, #0
	beq .L080ABCC6
	b .L080ABDC8
	.align 2, 0
.L080ABCB8: .4byte 0x7FFFFFFF
.L080ABCBC:
	cmp r5, #2
	beq .L080ABD3E
	cmp r5, #3
	beq .L080ABD7E
	b .L080ABDC8
.L080ABCC6:
	movs r0, #0
	mov r2, sl
	cmp r2, #0
	bgt .L080ABCD0
	movs r0, #1
.L080ABCD0:
	mov r8, r0
	ldr r0, [sp, #0x14]
	lsrs r0, r0, #0x1f
	mov sb, r0
	movs r6, #0
	ldr r1, [r4]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABCEC
	adds r0, r4, #0
	bl RefreshDown__19ActorMovementBounds
	ldr r0, [r4]
	b .L080ABCEE
.L080ABCEC:
	adds r0, r1, #0
.L080ABCEE:
	cmp r0, #0
	bne .L080ABDC6
	ldr r1, [r4]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABD00
	adds r0, r4, #0
	bl RefreshDown__19ActorMovementBounds
.L080ABD00:
	ldrb r0, [r4, #0x10]
	b .L080ABDC0
.L080ABD04:
	mov r1, sl
	mvns r0, r1
	lsrs r0, r0, #0x1f
	mov r8, r0
	ldr r2, [sp, #0x14]
	lsrs r2, r2, #0x1f
	mov sb, r2
	movs r6, #0
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x28]
	cmn r1, r0
	bge .L080ABD26
	adds r0, r4, #0
	bl RefreshUp__19ActorMovementBounds
	ldr r0, [r4, #4]
	b .L080ABD28
.L080ABD26:
	adds r0, r1, #0
.L080ABD28:
	cmp r0, #0
	bne .L080ABDC6
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #4]
	cmn r0, r1
	bge .L080ABD3A
	adds r0, r4, #0
	bl RefreshUp__19ActorMovementBounds
.L080ABD3A:
	ldrb r0, [r4, #0x11]
	b .L080ABDC0
.L080ABD3E:
	ldr r1, [sp, #0x10]
	mvns r0, r1
	lsrs r0, r0, #0x1f
	mov r8, r0
	movs r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, #0
	ble .L080ABD50
	movs r0, #1
.L080ABD50:
	mov sb, r0
	movs r6, #0
	ldr r1, [r4, #8]
	ldr r0, [r4, #0x28]
	cmn r1, r0
	bge .L080ABD66
	adds r0, r4, #0
	bl RefreshLeft__19ActorMovementBounds
	ldr r0, [r4, #8]
	b .L080ABD68
.L080ABD66:
	adds r0, r1, #0
.L080ABD68:
	cmp r0, #0
	bne .L080ABDC6
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #8]
	cmn r0, r1
	bge .L080ABD7A
	adds r0, r4, #0
	bl RefreshLeft__19ActorMovementBounds
.L080ABD7A:
	ldrb r0, [r4, #0x12]
	b .L080ABDC0
.L080ABD7E:
	movs r0, #0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bgt .L080ABD88
	movs r0, #1
.L080ABD88:
	mov r8, r0
	movs r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, #0
	ble .L080ABD94
	movs r0, #1
.L080ABD94:
	mov sb, r0
	movs r6, #0
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABDAA
	adds r0, r4, #0
	bl RefreshRight__19ActorMovementBounds
	ldr r0, [r4, #0xc]
	b .L080ABDAC
.L080ABDAA:
	adds r0, r1, #0
.L080ABDAC:
	cmp r0, #0
	bne .L080ABDC6
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABDBE
	adds r0, r4, #0
	bl RefreshRight__19ActorMovementBounds
.L080ABDBE:
	ldrb r0, [r4, #0x13]
.L080ABDC0:
	cmp r0, #0
	bne .L080ABDC6
	movs r6, #1
.L080ABDC6:
	adds r1, r6, #0
.L080ABDC8:
	movs r3, #1
	rsbs r3, r3, #0
	mov r0, r8
	cmp r0, #0
	beq .L080ABDD4
	movs r3, #1
.L080ABDD4:
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r1, r0, #0x1f
	movs r0, #8
	ands r1, r0
	cmp r7, #2
	bgt .L080ABDF2
	cmp r7, #1
	bge .L080ABDEE
	cmp r7, #0
	bne .L080ABDF2
	movs r2, #0
	b .L080ABDF4
.L080ABDEE:
	movs r2, #1
	b .L080ABDF4
.L080ABDF2:
	movs r2, #2
.L080ABDF4:
	mov r0, sb
	cmp r0, #0
	beq .L080ABE00
	lsls r0, r3, #1
	adds r0, r1, r0
	b .L080ABE02
.L080ABE00:
	adds r0, r1, r3
.L080ABE02:
	adds r0, r0, r2
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bne .L080ABE18
	ldr r2, [sp, #0x1c]
	lsls r0, r2, #2
	add r0, sp
	str r5, [r0]
	adds r2, #1
	str r2, [sp, #0x1c]
	b .L080ABE26
.L080ABE18:
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bge .L080ABE26
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #0x1c]
	str r0, [sp, #0x18]
.L080ABE26:
	ldr r5, [sp, #0x20]
	adds r5, #1
	str r5, [sp, #0x20]
	cmp r5, #3
	bgt .L080ABE32
	b .L080ABC92
.L080ABE32:
	mov r4, sp
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bls .L080ABE42
	bl RandomBelow
	lsls r0, r0, #2
	b .L080ABE44
.L080ABE42:
	movs r0, #0
.L080ABE44:
	adds r0, r4, r0
	ldr r0, [r0]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start SelectRetreatFacing
SelectRetreatFacing:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r4, [sp, #0x44]
	subs r2, r2, r0
	str r2, [sp, #0x10]
	subs r3, r3, r1
	mov sl, r3
	adds r1, r2, #0
	cmp r2, #0
	bge .L080ABE76
	rsbs r1, r2, #0
.L080ABE76:
	mov r0, sl
	cmp r0, #0
	bge .L080ABE7E
	rsbs r0, r0, #0
.L080ABE7E:
	movs r2, #0
	str r2, [sp, #0x14]
	lsls r2, r1, #1
	lsls r3, r0, #1
	adds r0, r3, r0
	cmp r2, r0
	ble .L080ABE92
	movs r5, #1
	str r5, [sp, #0x14]
	b .L080ABE9E
.L080ABE92:
	adds r0, r2, r1
	cmp r0, r3
	bge .L080ABE9E
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x14]
.L080ABE9E:
	ldr r1, .L080ABED0 @ =0x7FFFFFFF
	str r1, [sp, #0x18]
	movs r2, #0
	str r2, [sp, #0x1c]
	movs r5, #0
	str r5, [sp, #0x20]
.L080ABEAA:
	ldr r7, [sp, #0x20]
	ldr r0, [sp, #0x48]
	adds r1, r7, #0
	bl GetRelativeFacing
	adds r5, r0, #0
	movs r0, #1
	mov r8, r0
	movs r1, #0
	mov sb, r1
	movs r1, #1
	cmp r5, #1
	beq .L080ABF1C
	cmp r5, #1
	bgt .L080ABED4
	cmp r5, #0
	beq .L080ABEDE
	b .L080ABFE0
	.align 2, 0
.L080ABED0: .4byte 0x7FFFFFFF
.L080ABED4:
	cmp r5, #2
	beq .L080ABF56
	cmp r5, #3
	beq .L080ABF96
	b .L080ABFE0
.L080ABEDE:
	movs r0, #0
	mov r2, sl
	cmp r2, #0
	bgt .L080ABEE8
	movs r0, #1
.L080ABEE8:
	mov r8, r0
	ldr r0, [sp, #0x14]
	lsrs r0, r0, #0x1f
	mov sb, r0
	movs r6, #0
	ldr r1, [r4]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABF04
	adds r0, r4, #0
	bl RefreshDown__19ActorMovementBounds
	ldr r0, [r4]
	b .L080ABF06
.L080ABF04:
	adds r0, r1, #0
.L080ABF06:
	cmp r0, #0
	bne .L080ABFDE
	ldr r1, [r4]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABF18
	adds r0, r4, #0
	bl RefreshDown__19ActorMovementBounds
.L080ABF18:
	ldrb r0, [r4, #0x10]
	b .L080ABFD8
.L080ABF1C:
	mov r1, sl
	mvns r0, r1
	lsrs r0, r0, #0x1f
	mov r8, r0
	ldr r2, [sp, #0x14]
	lsrs r2, r2, #0x1f
	mov sb, r2
	movs r6, #0
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x28]
	cmn r1, r0
	bge .L080ABF3E
	adds r0, r4, #0
	bl RefreshUp__19ActorMovementBounds
	ldr r0, [r4, #4]
	b .L080ABF40
.L080ABF3E:
	adds r0, r1, #0
.L080ABF40:
	cmp r0, #0
	bne .L080ABFDE
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #4]
	cmn r0, r1
	bge .L080ABF52
	adds r0, r4, #0
	bl RefreshUp__19ActorMovementBounds
.L080ABF52:
	ldrb r0, [r4, #0x11]
	b .L080ABFD8
.L080ABF56:
	ldr r1, [sp, #0x10]
	mvns r0, r1
	lsrs r0, r0, #0x1f
	mov r8, r0
	movs r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, #0
	ble .L080ABF68
	movs r0, #1
.L080ABF68:
	mov sb, r0
	movs r6, #0
	ldr r1, [r4, #8]
	ldr r0, [r4, #0x28]
	cmn r1, r0
	bge .L080ABF7E
	adds r0, r4, #0
	bl RefreshLeft__19ActorMovementBounds
	ldr r0, [r4, #8]
	b .L080ABF80
.L080ABF7E:
	adds r0, r1, #0
.L080ABF80:
	cmp r0, #0
	bne .L080ABFDE
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #8]
	cmn r0, r1
	bge .L080ABF92
	adds r0, r4, #0
	bl RefreshLeft__19ActorMovementBounds
.L080ABF92:
	ldrb r0, [r4, #0x12]
	b .L080ABFD8
.L080ABF96:
	movs r0, #0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bgt .L080ABFA0
	movs r0, #1
.L080ABFA0:
	mov r8, r0
	movs r0, #0
	ldr r2, [sp, #0x14]
	cmp r2, #0
	ble .L080ABFAC
	movs r0, #1
.L080ABFAC:
	mov sb, r0
	movs r6, #0
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABFC2
	adds r0, r4, #0
	bl RefreshRight__19ActorMovementBounds
	ldr r0, [r4, #0xc]
	b .L080ABFC4
.L080ABFC2:
	adds r0, r1, #0
.L080ABFC4:
	cmp r0, #0
	bne .L080ABFDE
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble .L080ABFD6
	adds r0, r4, #0
	bl RefreshRight__19ActorMovementBounds
.L080ABFD6:
	ldrb r0, [r4, #0x13]
.L080ABFD8:
	cmp r0, #0
	bne .L080ABFDE
	movs r6, #1
.L080ABFDE:
	adds r1, r6, #0
.L080ABFE0:
	movs r3, #1
	mov r0, r8
	cmp r0, #0
	beq .L080ABFEA
	subs r3, #2
.L080ABFEA:
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r1, r0, #0x1f
	movs r0, #8
	ands r1, r0
	cmp r7, #2
	bgt .L080AC008
	cmp r7, #1
	bge .L080AC004
	cmp r7, #0
	bne .L080AC008
	movs r2, #0
	b .L080AC00A
.L080AC004:
	movs r2, #1
	b .L080AC00A
.L080AC008:
	movs r2, #2
.L080AC00A:
	mov r0, sb
	cmp r0, #0
	beq .L080AC016
	lsls r0, r3, #1
	adds r0, r1, r0
	b .L080AC018
.L080AC016:
	adds r0, r1, r3
.L080AC018:
	adds r0, r0, r2
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bne .L080AC02E
	ldr r2, [sp, #0x1c]
	lsls r0, r2, #2
	add r0, sp
	str r5, [r0]
	adds r2, #1
	str r2, [sp, #0x1c]
	b .L080AC03C
.L080AC02E:
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bge .L080AC03C
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #0x1c]
	str r0, [sp, #0x18]
.L080AC03C:
	ldr r5, [sp, #0x20]
	adds r5, #1
	str r5, [sp, #0x20]
	cmp r5, #3
	bgt .L080AC048
	b .L080ABEAA
.L080AC048:
	mov r4, sp
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bls .L080AC058
	bl RandomBelow
	lsls r0, r0, #2
	b .L080AC05A
.L080AC058:
	movs r0, #0
.L080AC05A:
	adds r0, r4, r0
	ldr r0, [r0]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0


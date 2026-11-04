    .syntax unified
    .cpu arm7tdmi
    .thumb

    @ Native retained OBJ palette-bank acquisition.

    .section .text.world_runtime_after_data_destruction, "ax", %progbits

    .global AcquirePaletteBank__21GameScenePaletteCacheUi
    .type AcquirePaletteBank__21GameScenePaletteCacheUi, %function
    .thumb_func
AcquirePaletteBank__21GameScenePaletteCacheUi:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r0, r5, #5
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r4, r0
	adds r6, r0, #0
	adds r6, #0xa0
	ldrb r0, [r6]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x1f
	cmp r7, #0
	beq .L080AC9A4
	movs r2, #0
	ldrsb r2, [r6, r2]
	ldr r0, .L080AC9A0 @ =0x00000B78
	adds r1, r4, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
.L080AC99A:
	ldrb r0, [r1, #8]
	b .L080AC9E4
	.align 2, 0
.L080AC9A0: .4byte 0x00000B78
.L080AC9A4:
	ldr r0, .L080AC9D8 @ =0x00000C14
	adds r2, r4, r0
	ldrb r3, [r2]
	cmp r3, #0xd
	bhs .L080AC9E0
	adds r1, r3, #0
	adds r0, r1, #1
	strb r0, [r2]
	ldr r0, .L080AC9DC @ =0x00000B78
	adds r2, r4, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #9
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq .L080AC9CC
	strb r5, [r1, #9]
	strb r7, [r1, #0xa]
.L080AC9CC:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, r3
	beq .L080AC99A
	strb r3, [r6]
	b .L080AC99A
	.align 2, 0
.L080AC9D8: .4byte 0x00000C14
.L080AC9DC: .4byte 0x00000B78
.L080AC9E0:
	movs r0, #1
	rsbs r0, r0, #0
.L080AC9E4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
    .size AcquirePaletteBank__21GameScenePaletteCacheUi, . - AcquirePaletteBank__21GameScenePaletteCacheUi

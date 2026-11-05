    .include "asm/macro.inc"
    .include "six/asm/hw/video.s"
    .syntax unified
    .thumb
    .section .text, "ax", %progbits
    .align 2, 0

    @ Core animation and graphics still retain their real native code.
    @ All regions use these instructions with their actual symbolic resources.
	thumb_func_start RunIntroStorySceneCore
RunIntroStorySceneCore: @ 0x0805EE44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp, #0x30]
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp, #0x34]
	movs r1, #0
	str r1, [sp, #0x38]
	adds r0, r5, #0
	bl EnableHardwareForcedBlank
	adds r0, r5, #0
	bl GetHardwareDisplayState
	mov r1, sp
	movs r2, #0x3f
	strh r2, [r1]
	adds r0, #0x50
	strh r2, [r0]
	movs r0, #0x10
	bl __builtin_new
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r1, r0, #0
	ldr r2, [sp, #0x38]
	str r2, [r4]
	str r2, [r4, #4]
	ldr r0, .L0805EF00 @ =__vt_19HardwareBlendObject
	str r0, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xc
	bl __23HardwareBlendControllerP20HardwareDisplayState
	str r4, [sp, #4]
	adds r0, r5, #0
	bl InitializeIntroStoryGraphics
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0x25
	bl Start__23HardwareMusicPlayerSlotUs
	ldr r0, [sp, #4]
	ldr r1, .L0805EF04 @ =0x00000889
	adds r0, #0xc
	movs r2, #1
	movs r3, #0
	bl BeginHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	ldr r3, .L0805EF08 @ =0x00006422
	adds r1, r5, r3
	movs r0, #4
	strh r0, [r1]
	mov r4, sp
	adds r4, #8
	str r4, [sp, #0x40]
	mov r7, sp
	adds r7, #0x28
	str r7, [sp, #0x44]
.L0805EED8:
	adds r0, r5, #0
	bl UpdateHardwareFrame
	adds r0, r5, #0
	bl UpdateHardwareInput
	ldr r1, .L0805EF08 @ =0x00006422
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bls .L0805EEF6
	b .L0805F59E
.L0805EEF6:
	lsls r0, r0, #2
	ldr r1, .L0805EF0C @ =.L0805EF10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805EF00: .4byte __vt_19HardwareBlendObject
.L0805EF04: .4byte 0x00000889
.L0805EF08: .4byte 0x00006422
.L0805EF0C: .4byte .L0805EF10
.L0805EF10: @ jump table
	.4byte .L0805EF38 @ case 0
	.4byte .L0805EF64 @ case 1
	.4byte .L0805EF88 @ case 2
	.4byte .L0805EFB4 @ case 3
	.4byte .L0805EFF6 @ case 4
	.4byte .L0805F11C @ case 5
	.4byte .L0805F138 @ case 6
	.4byte .L0805F15C @ case 7
	.4byte .L0805F1FA @ case 8
	.4byte .L0805F58E @ case 9
.L0805EF38:
	ldr r0, [sp, #4]
	ldr r1, .L0805EF5C @ =0x00000889
	adds r0, #0xc
	movs r2, #2
	movs r3, #0
	bl BeginHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	ldr r2, .L0805EF60 @ =0x00006422
	adds r1, r5, r2
	b .L0805F090
	.align 2, 0
.L0805EF5C: .4byte 0x00000889
.L0805EF60: .4byte 0x00006422
.L0805EF64:
	ldr r3, [sp, #0x34]
	lsls r0, r3, #0x10
	ldr r4, .L0805EF80 @ =0xFFFF0000
	adds r0, r0, r4
	lsrs r7, r0, #0x10
	str r7, [sp, #0x34]
	cmp r0, #0
	blt .L0805EF76
	b .L0805F59E
.L0805EF76:
	ldr r0, .L0805EF84 @ =0x00006422
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805EF80: .4byte 0xFFFF0000
.L0805EF84: .4byte 0x00006422
.L0805EF88:
	ldr r0, [sp, #4]
	ldr r1, .L0805EFAC @ =0x00000889
	adds r0, #0xc
	movs r2, #1
	movs r3, #0
	bl BeginHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	ldr r2, .L0805EFB0 @ =0x00006422
	adds r1, r5, r2
	b .L0805F090
	.align 2, 0
.L0805EFAC: .4byte 0x00000889
.L0805EFB0: .4byte 0x00006422
.L0805EFB4:
	ldr r0, [sp, #4]
	ldr r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	cmp r0, #0
	bge .L0805EFC2
	b .L0805F59E
.L0805EFC2:
	ldr r3, .L0805EFE8 @ =0x00006422
	adds r0, r5, r3
	movs r1, #5
	strh r1, [r0]
	ldr r4, .L0805EFEC @ =0x00006420
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #1
	beq .L0805EFE2
	cmp r0, #1
	blt .L0805EFF0
	cmp r0, #0xc
	bgt .L0805EFF0
	cmp r0, #0xb
	blt .L0805EFF0
.L0805EFE2:
	movs r0, #0x3c
	str r0, [sp, #0x34]
	b .L0805F59E
	.align 2, 0
.L0805EFE8: .4byte 0x00006422
.L0805EFEC: .4byte 0x00006420
.L0805EFF0:
	movs r1, #0
	str r1, [sp, #0x34]
	b .L0805F59E
.L0805EFF6:
	ldr r2, [sp, #0x34]
	lsls r0, r2, #0x10
	ldr r3, .L0805F030 @ =0xFFFF0000
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	str r4, [sp, #0x34]
	cmp r0, #0
	blt .L0805F008
	b .L0805F59E
.L0805F008:
	ldr r7, .L0805F034 @ =0x00006422
	adds r1, r5, r7
	movs r2, #0
	movs r0, #6
	strh r0, [r1]
	ldr r1, .L0805F038 @ =0x00006426
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, .L0805F03C @ =0x00006420
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xd
	bhi .L0805F0FC
	lsls r0, r0, #2
	ldr r1, .L0805F040 @ =.L0805F044
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805F030: .4byte 0xFFFF0000
.L0805F034: .4byte 0x00006422
.L0805F038: .4byte 0x00006426
.L0805F03C: .4byte 0x00006420
.L0805F040: .4byte .L0805F044
.L0805F044: @ jump table
	.4byte .L0805F07C @ case 0
	.4byte .L0805F08C @ case 1
	.4byte .L0805F09C @ case 2
	.4byte .L0805F0FC @ case 3
	.4byte .L0805F0FC @ case 4
	.4byte .L0805F0FC @ case 5
	.4byte .L0805F0FC @ case 6
	.4byte .L0805F0FC @ case 7
	.4byte .L0805F0FC @ case 8
	.4byte .L0805F0AC @ case 9
	.4byte .L0805F0BC @ case 10
	.4byte .L0805F0CC @ case 11
	.4byte .L0805F0DC @ case 12
	.4byte .L0805F0EC @ case 13
.L0805F07C:
	ldr r4, .L0805F088 @ =0x00006424
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F088: .4byte 0x00006424
.L0805F08C:
	ldr r7, .L0805F098 @ =0x00006424
	adds r1, r5, r7
.L0805F090:
	movs r0, #4
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F098: .4byte 0x00006424
.L0805F09C:
	ldr r0, .L0805F0A8 @ =0x00006424
	adds r1, r5, r0
	movs r0, #5
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0A8: .4byte 0x00006424
.L0805F0AC:
	ldr r2, .L0805F0B8 @ =0x00006424
	adds r1, r5, r2
	movs r0, #0xe
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0B8: .4byte 0x00006424
.L0805F0BC:
	ldr r3, .L0805F0C8 @ =0x00006424
	adds r1, r5, r3
	movs r0, #0x10
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0C8: .4byte 0x00006424
.L0805F0CC:
	ldr r4, .L0805F0D8 @ =0x00006424
	adds r1, r5, r4
	movs r0, #0x13
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0D8: .4byte 0x00006424
.L0805F0DC:
	ldr r7, .L0805F0E8 @ =0x00006424
	adds r1, r5, r7
	movs r0, #0x16
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0E8: .4byte 0x00006424
.L0805F0EC:
	ldr r0, .L0805F0F8 @ =0x00006424
	adds r1, r5, r0
	movs r0, #0x19
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F0F8: .4byte 0x00006424
.L0805F0FC:
	movs r1, #0xb4
	str r1, [sp, #0x34]
	ldr r2, .L0805F114 @ =0x00006426
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, .L0805F118 @ =0x00006422
	adds r1, r5, r3
	movs r0, #7
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F114: .4byte 0x00006426
.L0805F118: .4byte 0x00006422
.L0805F11C:
	ldr r4, .L0805F130 @ =0x00006426
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #2
	beq .L0805F12A
	b .L0805F59E
.L0805F12A:
	ldr r0, .L0805F134 @ =0x00006422
	adds r1, r5, r0
	b .L0805F14E
	.align 2, 0
.L0805F130: .4byte 0x00006426
.L0805F134: .4byte 0x00006422
.L0805F138:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #0x10
	ldr r2, .L0805F154 @ =0xFFFF0000
	adds r0, r0, r2
	lsrs r3, r0, #0x10
	str r3, [sp, #0x34]
	cmp r0, #0
	blt .L0805F14A
	b .L0805F59E
.L0805F14A:
	ldr r4, .L0805F158 @ =0x00006422
	adds r1, r5, r4
.L0805F14E:
	movs r0, #8
	strh r0, [r1]
	b .L0805F59E
	.align 2, 0
.L0805F154: .4byte 0xFFFF0000
.L0805F158: .4byte 0x00006422
.L0805F15C:
	ldr r7, .L0805F19C @ =0x00006420
	adds r1, r5, r7
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	bgt .L0805F1D4
	adds r0, r2, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0805F1A4
	ldr r0, [sp, #4]
	ldr r1, .L0805F1A0 @ =0x00000889
	adds r0, #0xc
	movs r2, #1
	movs r3, #0
	bl EndHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	b .L0805F1C2
	.align 2, 0
.L0805F19C: .4byte 0x00006420
.L0805F1A0: .4byte 0x00000889
.L0805F1A4:
	ldr r0, [sp, #4]
	ldr r1, .L0805F1CC @ =0x00000889
	adds r0, #0xc
	movs r2, #2
	movs r3, #0
	bl EndHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
.L0805F1C2:
	ldr r0, .L0805F1D0 @ =0x00006422
	adds r1, r5, r0
	movs r0, #9
	b .L0805F1F8
	.align 2, 0
.L0805F1CC: .4byte 0x00000889
.L0805F1D0: .4byte 0x00006422
.L0805F1D4:
	ldr r0, [sp, #4]
	ldr r1, .L0805F22C @ =0x00000889
	adds r0, #0xc
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	adds r0, r5, #0
	bl GetHardwareCommandList
	ldr r2, [r0, #8]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	ldr r2, .L0805F230 @ =0x00006422
	adds r1, r5, r2
	movs r0, #0xa
.L0805F1F8:
	strh r0, [r1]
.L0805F1FA:
	ldr r0, [sp, #4]
	ldr r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	cmp r0, #0
	bge .L0805F208
	b .L0805F59E
.L0805F208:
	movs r3, #1
	rsbs r3, r3, #0
	mov sl, r3
	ldr r4, .L0805F234 @ =0x00006420
	adds r0, r5, r4
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bls .L0805F220
	b .L0805F32E
.L0805F220:
	lsls r0, r0, #2
	ldr r1, .L0805F238 @ =.L0805F23C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805F22C: .4byte 0x00000889
.L0805F230: .4byte 0x00006422
.L0805F234: .4byte 0x00006420
.L0805F238: .4byte .L0805F23C
.L0805F23C: @ jump table
	.4byte .L0805F270 @ case 0
	.4byte .L0805F280 @ case 1
	.4byte .L0805F2BC @ case 2
	.4byte .L0805F2BC @ case 3
	.4byte .L0805F2BC @ case 4
	.4byte .L0805F2BC @ case 5
	.4byte .L0805F2BC @ case 6
	.4byte .L0805F2BC @ case 7
	.4byte .L0805F29C @ case 8
	.4byte .L0805F2DC @ case 9
	.4byte .L0805F2F8 @ case 10
	.4byte .L0805F318 @ case 11
	.4byte .L0805F280 @ case 12
.L0805F270:
	movs r7, #0
	mov sl, r7
	ldr r0, .L0805F27C @ =0x00006422
	adds r1, r5, r0
	b .L0805F2CE
	.align 2, 0
.L0805F27C: .4byte 0x00006422
.L0805F280:
	adds r0, r5, #0
	bl GetHardwareDisplayState
	mov r2, sp
	movs r3, #0x92
	lsls r3, r3, #5
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	ldr r4, .L0805F298 @ =0x00006422
	adds r1, r5, r4
	b .L0805F2CE
	.align 2, 0
.L0805F298: .4byte 0x00006422
.L0805F29C:
	adds r0, r5, #0
	bl GetHardwareDisplayState
	mov r2, sp
	movs r7, #0x82
	lsls r7, r7, #5
	adds r1, r7, #0
	strh r1, [r2]
	strh r1, [r0]
	ldr r0, .L0805F2B8 @ =0x00006422
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	b .L0805F32E
	.align 2, 0
.L0805F2B8: .4byte 0x00006422
.L0805F2BC:
	ldr r1, .L0805F2D4 @ =0x00006420
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #2
	lsls r0, r0, #1
	mov sl, r0
	ldr r3, .L0805F2D8 @ =0x00006422
	adds r1, r5, r3
.L0805F2CE:
	movs r0, #1
	strh r0, [r1]
	b .L0805F32E
	.align 2, 0
.L0805F2D4: .4byte 0x00006420
.L0805F2D8: .4byte 0x00006422
.L0805F2DC:
	ldr r4, .L0805F2F0 @ =0x00006422
	adds r1, r5, r4
	movs r0, #3
	strh r0, [r1]
	ldr r7, .L0805F2F4 @ =0x00006420
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L0805F328
	.align 2, 0
.L0805F2F0: .4byte 0x00006422
.L0805F2F4: .4byte 0x00006420
.L0805F2F8:
	movs r2, #0x78
	str r2, [sp, #0x34]
	ldr r3, .L0805F310 @ =0x00006422
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r4, .L0805F314 @ =0x00006420
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	b .L0805F328
	.align 2, 0
.L0805F310: .4byte 0x00006422
.L0805F314: .4byte 0x00006420
.L0805F318:
	ldr r0, .L0805F380 @ =0x00006422
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L0805F384 @ =0x00006420
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
.L0805F328:
	subs r0, #3
	lsls r0, r0, #1
	mov sl, r0
.L0805F32E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp sl, r0
	bne .L0805F338
	b .L0805F59E
.L0805F338:
	adds r0, r5, #0
	bl GetHardwareDmaQueue
	adds r6, r0, #0
	mov r3, sl
	lsls r4, r3, #2
	adds r1, r4, r3
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0x20
	add r0, sp, #8
	ldr r2, .L0805F388
	movs r3, #0xa0
	lsls r3, r3, #3
	bl __21DmaTransferDescriptorPCvPvUi
	ldr r7, [sp, #0x40]
	str r7, [sp, #0x3c]
	ldr r1, [r6, #4]
	ldr r0, [r6, #0xc]
	str r4, [sp, #0x48]
	cmp r1, r0
	beq .L0805F38C
	cmp r1, #0
	beq .L0805F376
	adds r0, r1, #0
	adds r1, r7, #0
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
.L0805F376:
	ldr r0, [r6, #4]
	adds r0, #0x10
	str r0, [r6, #4]
	b .L0805F460
	.align 2, 0
.L0805F380: .4byte 0x00006422
.L0805F384: .4byte 0x00006420
.L0805F388: .word MEM_VRAM + 30 * BG_SCREEN_SIZE
.L0805F38C:
	str r1, [sp, #0x4c]
	movs r0, #1
	str r0, [sp, #0x1c]
	ldr r1, [r6]
	ldr r7, [sp, #0x4c]
	subs r0, r7, r1
	asrs r4, r0, #4
	str r4, [sp, #0x18]
	add r2, sp, #0x1c
	add r0, sp, #0x18
	cmp r4, #1
	bhs .L0805F3A6
	adds r0, r2, #0
.L0805F3A6:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L0805F3C6
	lsls r4, r0, #4
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L0805F3C2
	mov r0, sb
	bl RetryMemoryAllocation
.L0805F3C2:
	ldr r1, [r6]
	b .L0805F3CA
.L0805F3C6:
	movs r0, #0
	mov sb, r0
.L0805F3CA:
	adds r4, r0, #0
	mov r8, r4
	adds r2, r1, #0
	mov ip, r8
	ldr r0, [sp, #0x4c]
	cmp r2, r0
	beq .L0805F3F6
.L0805F3D8:
	mov r1, ip
	cmp r1, #0
	beq .L0805F3EA
	mov r0, ip
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F3EA:
	adds r2, #0x10
	movs r0, #0x10
	add ip, r0
	ldr r1, [sp, #0x4c]
	cmp r2, r1
	bne .L0805F3D8
.L0805F3F6:
	mov r4, ip
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bne .L0805F412
	cmp r4, #0
	beq .L0805F40E
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F40E:
	adds r4, #0x10
	b .L0805F43A
.L0805F412:
	mov ip, r0
	adds r2, r4, #0
	cmp r0, #0
	beq .L0805F438
.L0805F41A:
	cmp r2, #0
	beq .L0805F42A
	adds r0, r2, #0
	ldr r1, [sp, #0x3c]
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F42A:
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	adds r2, #0x10
	mov r1, ip
	cmp r1, #0
	bne .L0805F41A
.L0805F438:
	adds r4, r2, #0
.L0805F43A:
	ldr r2, [r6, #4]
	ldr r1, [r6]
	adds r0, r1, #0
	cmp r1, r2
	beq .L0805F44A
.L0805F444:
	adds r0, #0x10
	cmp r0, r2
	bne .L0805F444
.L0805F44A:
	cmp r1, #0
	beq .L0805F454
	adds r0, r1, #0
	bl free
.L0805F454:
	mov r0, sb
	add r0, r8
	mov r2, r8
	str r2, [r6]
	str r4, [r6, #4]
	str r0, [r6, #0xc]
.L0805F460:
	adds r0, r5, #0
	bl GetHardwareDmaQueue
	adds r6, r0, #0
	ldr r1, [sp, #0x48]
	add r1, sl
	lsls r1, r1, #8
	adds r1, r1, r5
	movs r3, #0xa4
	lsls r3, r3, #3
	adds r1, r1, r3
	add r0, sp, #8
	ldr r2, .L0805F4A4
	subs r3, #0x20
	bl __21DmaTransferDescriptorPCvPvUi
	ldr r4, [sp, #0x40]
	mov sl, r4
	ldr r1, [r6, #4]
	ldr r0, [r6, #0xc]
	cmp r1, r0
	beq .L0805F4A8
	cmp r1, #0
	beq .L0805F49C
	adds r0, r1, #0
	adds r1, r4, #0
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F49C:
	ldr r0, [r6, #4]
	adds r0, #0x10
	str r0, [r6, #4]
	b .L0805F57A
	.align 2, 0
.L0805F4A4: .word MEM_VRAM + 29 * BG_SCREEN_SIZE
.L0805F4A8:
	str r1, [sp, #0x4c]
	movs r0, #1
	str r0, [sp, #0x24]
	ldr r1, [r6]
	ldr r4, [sp, #0x4c]
	subs r0, r4, r1
	asrs r4, r0, #4
	str r4, [sp, #0x20]
	add r2, sp, #0x24
	add r0, sp, #0x20
	cmp r4, #1
	bhs .L0805F4C2
	adds r0, r2, #0
.L0805F4C2:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L0805F4E2
	lsls r4, r0, #4
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L0805F4DE
	mov r0, sb
	bl RetryMemoryAllocation
.L0805F4DE:
	ldr r1, [r6]
	b .L0805F4E6
.L0805F4E2:
	movs r0, #0
	mov sb, r0
.L0805F4E6:
	adds r4, r0, #0
	mov r8, r4
	adds r2, r1, #0
	mov ip, r8
	ldr r7, [sp, #0x4c]
	cmp r2, r7
	beq .L0805F510
.L0805F4F4:
	mov r0, ip
	cmp r0, #0
	beq .L0805F504
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F504:
	adds r2, #0x10
	movs r0, #0x10
	add ip, r0
	ldr r1, [sp, #0x4c]
	cmp r2, r1
	bne .L0805F4F4
.L0805F510:
	mov r4, ip
	ldr r0, [sp, #0x24]
	cmp r0, #1
	bne .L0805F52C
	cmp r4, #0
	beq .L0805F528
	adds r0, r4, #0
	mov r1, sl
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F528:
	adds r4, #0x10
	b .L0805F554
.L0805F52C:
	mov ip, r0
	adds r2, r4, #0
	cmp r0, #0
	beq .L0805F552
.L0805F534:
	cmp r2, #0
	beq .L0805F544
	adds r0, r2, #0
	mov r1, sl
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldr r1, [r1]
	str r1, [r0]
.L0805F544:
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	adds r2, #0x10
	mov r1, ip
	cmp r1, #0
	bne .L0805F534
.L0805F552:
	adds r4, r2, #0
.L0805F554:
	ldr r2, [r6, #4]
	ldr r1, [r6]
	adds r0, r1, #0
	cmp r1, r2
	beq .L0805F564
.L0805F55E:
	adds r0, #0x10
	cmp r0, r2
	bne .L0805F55E
.L0805F564:
	cmp r1, #0
	beq .L0805F56E
	adds r0, r1, #0
	bl free
.L0805F56E:
	mov r0, sb
	add r0, r8
	mov r2, r8
	str r2, [r6]
	str r4, [r6, #4]
	str r0, [r6, #0xc]
.L0805F57A:
	adds r0, r5, #0
	bl GetHardwareDisplayState
	mov r2, sp
	movs r3, #0xe2
	lsls r3, r3, #5
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	b .L0805F59E
.L0805F58E:
	ldr r0, [sp, #4]
	ldr r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	cmp r0, #0
	blt .L0805F59E
	movs r4, #1
	str r4, [sp, #0x38]
.L0805F59E:
	adds r0, r5, #0
	bl UpdateIntroStoryUi
	ldr r7, [sp, #0x38]
	cmp r7, #0
	bne .L0805F5AC
	b .L0805EED8
.L0805F5AC:
	movs r0, #0
	str r0, [sp, #8]
	ldr r1, [sp, #0x40]
	str r1, [sp, #0x28]
	ldr r2, [sp, #0x44]
	str r0, [r2, #4]
	str r0, [r1]
	ldr r3, [sp, #0x30]
	str r0, [r3]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq .L0805F5D0
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L0805F5D0:
	ldr r1, [sp, #4]
	cmp r1, #0
	beq .L0805F5E2
	ldr r0, [r1, #8]
	ldr r2, [r0, #0xc]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L0805F5E2:
	ldr r0, [sp, #0x30]
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

    .section .text.intro_story_graphics, "ax", %progbits
    .align 2, 0

	thumb_func_start InitializeIntroStoryGraphics
InitializeIntroStoryGraphics: @ 0x0805FBB8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, .L0805FCA0
	movs r0, #0
	movs r2, #TILE_SIZE_4BPP
	bl FillHardwareDma3
	ldr r4, .L0805FCA4 @ =0x10661066
	ldr r1, .L0805FCA8
	movs r5, #(BG_SCREEN_SIZE >> 4)
	lsls r5, r5, #4
	adds r0, r4, #0
	adds r2, r5, #0
	bl FillHardwareDma3
	ldr r1, .L0805FCAC
	adds r0, r4, #0
	adds r2, r5, #0
	bl FillHardwareDma3
	ldr r1, .L0805FCB0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FillHardwareDma3
	ldr r0, .L0805FCB4 @ =gUnk_08743058
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl Unpack
	ldr r0, .L0805FCB8 @ =gUnk_08747A14
	movs r4, #0xa0
	lsls r4, r4, #0x13
	adds r1, r4, #0
	movs r2, #0x40
	bl CopyHardwareDma3
	ldr r1, .L0805FCBC @ =0x00007FFF
	adds r0, r1, #0
	strh r0, [r4]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r1, sp
	movs r3, #0xe2
	lsls r3, r3, #5
	adds r2, r3, #0
	strh r2, [r1]
	movs r4, #0
	strh r2, [r0]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r2, sp
	ldr r3, .L0805FCC0 @ =0x00001E43
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0, #0xe]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r2, sp
	ldr r3, .L0805FCC4 @ =0x00001D42
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0, #0xc]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r2, sp
	ldr r3, .L0805FCC8 @ =0x00001C41
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0, #0xa]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r1, sp
	strh r4, [r1]
	strh r4, [r0, #0x18]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r1, sp
	strh r4, [r1]
	strh r4, [r0, #0x1a]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r1, sp
	strh r4, [r1]
	strh r4, [r0, #0x1c]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	mov r1, sp
	strh r4, [r1]
	strh r4, [r0, #0x1e]
	adds r6, #0x20
	ldr r5, .L0805FCCC @ =gIntroStoryTilemapSources
	movs r4, #0x13
.L0805FC84:
	ldm r5!, {r0}
	adds r1, r6, #0
	bl Unpack
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r6, r6, r0
	subs r4, #1
	cmp r4, #0
	bge .L0805FC84
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805FCA0: .word MEM_VRAM + 1023 * TILE_SIZE_4BPP
.L0805FCA4: .4byte 0x10661066
.L0805FCA8: .word MEM_VRAM + 28 * BG_SCREEN_SIZE
.L0805FCAC: .word MEM_VRAM + 29 * BG_SCREEN_SIZE
.L0805FCB0: .word MEM_VRAM + 30 * BG_SCREEN_SIZE
.L0805FCB4: .4byte gUnk_08743058
.L0805FCB8: .4byte gUnk_08747A14
.L0805FCBC: .4byte 0x00007FFF
.L0805FCC0: .4byte 0x00001E43
.L0805FCC4: .4byte 0x00001D42
.L0805FCC8: .4byte 0x00001C41
.L0805FCCC: .4byte gIntroStoryTilemapSources

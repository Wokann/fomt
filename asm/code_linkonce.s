
	.INCLUDE "asm/macro.inc"
	.SYNTAX UNIFIED

	.section ".text.code_080D7CFC"

    @ Contiguous fixed script-queue aggregate; reverse-order destruction.
    @ This body remains native, with the ordinary C++ destructor ABI.
	thumb_func_start _._21GameSceneScriptQueues
_._21GameSceneScriptQueues:
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r1, r0
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r3, r2
	cmp r0, r1
	beq .L080D7E88
.L080D7E82:
	adds r0, #8
	cmp r0, r1
	bne .L080D7E82
.L080D7E88:
	adds r1, r3, #0
	adds r1, #0x14
	ldr r0, [r3, #0x14]
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r1, r0
	adds r2, r3, #0
	adds r2, #0x18
	adds r4, r3, #4
	ldr r0, [r3]
	cmp r2, r1
	beq .L080D7EA6
.L080D7EA0:
	adds r2, #8
	cmp r2, r1
	bne .L080D7EA0
.L080D7EA6:
	lsls r0, r0, #3
	adds r0, #4
	adds r0, r3, r0
	adds r1, r4, #0
	cmp r1, r0
	beq .L080D7EB8
.L080D7EB2:
	adds r1, #8
	cmp r1, r0
	bne .L080D7EB2
.L080D7EB8:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080D7EC6
	adds r0, r3, #0
	bl __builtin_delete
.L080D7EC6:
	pop {r4, r5}
	pop {r0}
	bx r0

    .ifdef REGION_JP
    @ JP revision 0 counterpart of .text.code_080D7CFC.
    @
    @ Each range ends at a statically verified JP function entry.  The
    @ anchors preserve original public names where their US prefix has a
    @ unique, ordered match in the JP ROM.  This is checked source data, not
    @ a build-time ROM splitter.

    .syntax unified
    .thumb

    .section .text.game_scene_state_callbacks_after, "ax", %progbits

    .global sub_080D8178
    .thumb_func
sub_080D8178:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [pc, #0x154]
    add sp, r4
    ldr r2, [pc, #0x154]
    add r2, sp
    str r0, [r2]
    mov sl, r1
    add r0, sp, #0x10
    movs r1, #0x1e
    movs r2, #4
    bl __18HardwareInputStateUsUs
    add r6, sp, #0x34
    adds r0, r6, #0
    movs r1, #0
    movs r2, #0x20
    bl __25HardwareSpriteBufferStateUcUc
    mov r7, sl
    adds r7, #0x10
    movs r2, #0
    mov r3, sl
    ldrh r0, [r3, #0x10]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r3, #0x10]
    movs r4, #0x87
    lsls r4, r4, #3
    add r4, sp
    str r2, [r4]
    str r2, [r4, #4]
    ldr r0, .LHardwareDisplayCommandVTable
    str r0, [r4, #8]
    str r7, [r4, #0xc]
    mov r5, sl
    adds r5, #0x68
    adds r0, r5, #0
    bl func_08008AE0
    ldr r1, [r0, #8]
    ldr r2, [r1, #0x10]
    adds r1, r4, #0
    bl _call_via_r2
    adds r0, r5, #0
    bl WaitForHardwareVBlank
    adds r0, r4, #0
    movs r1, #2
    bl func_080098AC
    movs r1, #0x87
    lsls r1, r1, #3
    add r1, sp
    movs r5, #0xf2
    lsls r5, r5, #5
    adds r0, r5, #0
    strh r0, [r1]
    ldrh r0, [r4]
    mov r2, sl
    strh r0, [r2, #0x10]
    movs r0, #0x3f
    strh r0, [r1]
    mov r1, sl
    adds r1, #0x60
    ldrh r0, [r4]
    strh r0, [r1]
    mov r5, sl
    adds r5, #0xd0
    adds r2, #0xc0
    ldr r0, [pc, #0xd4]
    add r0, sp
    str r2, [r0]
    ldr r3, [pc, #0xd0]
    add r3, sp
    movs r0, #0x9c
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .Lauto_080D7AC0
    cmp r1, #0
    beq .Lauto_080D79E4
    str r2, [r1]
    .Lauto_080D79E4:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    ldr r1, [pc, #0xb4]
    add r1, sp
    str r7, [r1]
    adds r6, r5, #0
    movs r2, #0xc4
    add r2, sl
    mov r8, r2
    movs r3, #0x8f
    lsls r3, r3, #3
    add r3, sp
    movs r4, #0xa7
    lsls r4, r4, #3
    add r4, sp
    str r3, [r4]
    mov r5, sl
    adds r5, #0xc8
    ldr r7, [pc, #0x98]
    add r7, sp
    str r5, [r7]
    ldr r0, [pc, #0x94]
    add r0, sp
    ldr r1, [pc, #0x94]
    add r1, sp
    str r0, [r1]
    mov r2, sl
    adds r2, #0xcc
    movs r3, #0xae
    lsls r3, r3, #3
    add r3, sp
    str r2, [r3]
    movs r4, #0x92
    lsls r4, r4, #3
    add r4, sp
    movs r5, #0xa8
    lsls r5, r5, #3
    add r5, sp
    str r4, [r5]
    mov r7, sl
    adds r7, #0xa0
    ldr r0, [pc, #0x74]
    add r0, sp
    str r7, [r0]
    mov r1, sl
    adds r1, #0x8c
    movs r2, #0xaa
    lsls r2, r2, #3
    add r2, sp
    str r1, [r2]
    mov r3, sl
    adds r3, #0xb0
    movs r4, #0xad
    lsls r4, r4, #3
    add r4, sp
    str r3, [r4]
    mov r5, sl
    adds r5, #0x90
    ldr r7, [pc, #0x58]
    add r7, sp
    str r5, [r7]
    mov r0, sl
    adds r0, #0xa8
    ldr r1, [pc, #0x50]
    add r1, sp
    str r0, [r1]
    mov r2, sl
    adds r2, #0x88
    ldr r3, [pc, #0x4c]
    add r3, sp
    str r2, [r3]
    mov r4, sl
    adds r4, #0x9c
    movs r5, #0xab
    lsls r5, r5, #3
    add r5, sp
    str r4, [r5]
    mov r7, sl
    adds r7, #0xa4
    movs r0, #0xac
    lsls r0, r0, #3
    add r0, sp
    str r7, [r0]
    b .Lauto_080D7BF2
    .byte 0x00, 0x00, 0x70, 0xFA, 0xFF, 0xFF, 0xDC, 0x04, 0x00, 0x00
.LHardwareDisplayCommandVTable: .word __vt_22HardwareDisplayCommand
    .byte 0x6C, 0x04
    .byte 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x6C, 0x05, 0x00, 0x00, 0x84, 0x04, 0x00, 0x00, 0x3C, 0x05
    .byte 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x4C, 0x05
    .byte 0x00, 0x00
    .Lauto_080D7AC0:
    adds r6, r1, #0
    movs r0, #1
    ldr r1, [pc, #0x40]
    add r1, sp
    str r0, [r1]
    ldr r0, [r5]
    subs r0, r6, r0
    asrs r4, r0, #2
    movs r0, #0x8e
    lsls r0, r0, #3
    add r0, sp
    str r4, [r0]
    ldr r2, [pc, #0x2c]
    add r2, sp
    ldr r0, [r1]
    movs r1, #0x8e
    lsls r1, r1, #3
    add r1, sp
    cmp r4, r0
    bhs .Lauto_080D7AEA
    adds r1, r2, #0
    .Lauto_080D7AEA:
    ldr r0, [r1]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080D7B0C
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lauto_080D7B10
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lauto_080D7B10
    .byte 0x74, 0x04, 0x00, 0x00
    .Lauto_080D7B0C:
    movs r0, #0
    mov sb, r0
    .Lauto_080D7B10:
    adds r7, r0, #0
    ldr r1, [r5]
    cmp r6, r1
    beq .Lauto_080D7B24
    subs r4, r6, r1
    adds r2, r4, #0
    bl memmove
    adds r4, r0, r4
    b .Lauto_080D7B26
    .Lauto_080D7B24:
    adds r4, r7, #0
    .Lauto_080D7B26:
    ldr r0, [pc, #0xfc]
    add r0, sp
    ldr r1, [r0]
    mov r2, sl
    adds r2, #0x10
    ldr r3, [pc, #0xf4]
    add r3, sp
    str r2, [r3]
    mov r6, sl
    adds r6, #0xd0
    ldr r2, [r5]
    movs r0, #0xc4
    add r0, sl
    mov r8, r0
    movs r3, #0x8f
    lsls r3, r3, #3
    add r3, sp
    movs r0, #0xa7
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    mov r3, sl
    adds r3, #0xc8
    ldr r0, [pc, #0xd4]
    add r0, sp
    str r3, [r0]
    ldr r3, [pc, #0xd4]
    add r3, sp
    ldr r0, [pc, #0xd4]
    add r0, sp
    str r3, [r0]
    mov r3, sl
    adds r3, #0xcc
    movs r0, #0xae
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    movs r3, #0x92
    lsls r3, r3, #3
    add r3, sp
    movs r0, #0xa8
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    mov r3, sl
    adds r3, #0xa0
    ldr r0, [pc, #0xb4]
    add r0, sp
    str r3, [r0]
    subs r3, #0x14
    movs r0, #0xaa
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    adds r3, #0x24
    movs r0, #0xad
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    subs r3, #0x20
    ldr r0, [pc, #0x9c]
    add r0, sp
    str r3, [r0]
    adds r3, #0x18
    ldr r0, [pc, #0x98]
    add r0, sp
    str r3, [r0]
    subs r3, #0x20
    ldr r0, [pc, #0x94]
    add r0, sp
    str r3, [r0]
    adds r3, #0x14
    movs r0, #0xab
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    adds r3, #8
    movs r0, #0xac
    lsls r0, r0, #3
    add r0, sp
    str r3, [r0]
    cmp r1, #0
    beq .Lauto_080D7BDE
    .Lauto_080D7BCC:
    movs r3, #0x9c
    lsls r3, r3, #3
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080D7BCC
    .Lauto_080D7BDE:
    cmp r2, #0
    beq .Lauto_080D7BE8
    adds r0, r2, #0
    bl free
    .Lauto_080D7BE8:
    mov r1, sb
    adds r0, r1, r7
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080D7BF2:
    mov sb, r6
    movs r0, #0x8f
    lsls r0, r0, #3
    add r0, sp
    mov r2, r8
    str r2, [r0]
    movs r3, #0xa7
    lsls r3, r3, #3
    add r3, sp
    ldr r3, [r3]
    ldr r4, [pc, #0x40]
    add r4, sp
    str r3, [r4]
    ldr r4, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r4, r0
    beq .Lauto_080D7C4C
    cmp r4, #0
    beq .Lauto_080D7C1A
    str r2, [r4]
    .Lauto_080D7C1A:
    ldr r0, [r6, #4]
    adds r0, #4
    str r0, [r6, #4]
    b .Lauto_080D7CEA
    .byte 0x00, 0x00, 0x74, 0x04, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x6C, 0x05, 0x00, 0x00, 0x84, 0x04
    .byte 0x00, 0x00, 0x3C, 0x05, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00, 0x64, 0x05
    .byte 0x00, 0x00, 0x4C, 0x05, 0x00, 0x00, 0xE4, 0x04, 0x00, 0x00
    .Lauto_080D7C4C:
    adds r7, r4, #0
    movs r0, #1
    movs r1, #0x90
    lsls r1, r1, #3
    add r1, sp
    str r0, [r1]
    ldr r0, [r6]
    subs r0, r7, r0
    asrs r4, r0, #2
    ldr r0, [pc, #0x34]
    add r0, sp
    str r4, [r0]
    movs r2, #0x90
    lsls r2, r2, #3
    add r2, sp
    ldr r0, [r1]
    ldr r1, [pc, #0x24]
    add r1, sp
    cmp r4, r0
    bhs .Lauto_080D7C76
    adds r1, r2, #0
    .Lauto_080D7C76:
    ldr r0, [r1]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080D7C98
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lauto_080D7C9C
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lauto_080D7C9C
    .byte 0x7C, 0x04, 0x00, 0x00
    .Lauto_080D7C98:
    movs r0, #0
    mov r8, r0
    .Lauto_080D7C9C:
    adds r5, r0, #0
    mov r4, sb
    ldr r1, [r4]
    cmp r7, r1
    beq .Lauto_080D7CB2
    subs r4, r7, r1
    adds r2, r4, #0
    bl memmove
    adds r4, r0, r4
    b .Lauto_080D7CB4
    .Lauto_080D7CB2:
    adds r4, r5, #0
    .Lauto_080D7CB4:
    movs r0, #0x90
    lsls r0, r0, #3
    add r0, sp
    ldr r1, [r0]
    mov r7, sb
    ldr r2, [r7]
    cmp r1, #0
    beq .Lauto_080D7CD4
    .Lauto_080D7CC4:
    ldr r3, [pc, #0x54]
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080D7CC4
    .Lauto_080D7CD4:
    cmp r2, #0
    beq .Lauto_080D7CDE
    adds r0, r2, #0
    bl free
    .Lauto_080D7CDE:
    mov r7, r8
    adds r0, r7, r5
    mov r1, sb
    str r5, [r1]
    str r4, [r1, #4]
    str r0, [r1, #0xc]
    .Lauto_080D7CEA:
    mov sb, r6
    ldr r0, [pc, #0x30]
    add r0, sp
    ldr r2, [pc, #0x30]
    add r2, sp
    ldr r2, [r2]
    str r2, [r0]
    ldr r3, [pc, #0x2c]
    add r3, sp
    ldr r3, [r3]
    movs r4, #0x9d
    lsls r4, r4, #3
    add r4, sp
    str r3, [r4]
    ldr r4, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r4, r0
    beq .Lauto_080D7D2C
    cmp r4, #0
    beq .Lauto_080D7D14
    str r2, [r4]
    .Lauto_080D7D14:
    ldr r0, [r6, #4]
    adds r0, #4
    str r0, [r6, #4]
    b .Lauto_080D7DCC
    .byte 0xE4, 0x04, 0x00, 0x00, 0x84, 0x04, 0x00, 0x00, 0x6C, 0x05, 0x00, 0x00, 0x3C, 0x05, 0x00, 0x00
    .Lauto_080D7D2C:
    adds r7, r4, #0
    movs r0, #1
    ldr r1, [pc, #0x40]
    add r1, sp
    str r0, [r1]
    ldr r0, [r6]
    subs r0, r7, r0
    asrs r4, r0, #2
    movs r0, #0x91
    lsls r0, r0, #3
    add r0, sp
    str r4, [r0]
    ldr r2, [pc, #0x2c]
    add r2, sp
    ldr r0, [r1]
    movs r1, #0x91
    lsls r1, r1, #3
    add r1, sp
    cmp r4, r0
    bhs .Lauto_080D7D56
    adds r1, r2, #0
    .Lauto_080D7D56:
    ldr r0, [r1]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080D7D78
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lauto_080D7D7C
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lauto_080D7D7C
    .byte 0x8C, 0x04, 0x00, 0x00
    .Lauto_080D7D78:
    movs r0, #0
    mov r8, r0
    .Lauto_080D7D7C:
    adds r5, r0, #0
    mov r0, sb
    ldr r1, [r0]
    cmp r7, r1
    beq .Lauto_080D7D94
    subs r4, r7, r1
    adds r0, r5, #0
    adds r2, r4, #0
    bl memmove
    adds r4, r0, r4
    b .Lauto_080D7D96
    .Lauto_080D7D94:
    adds r4, r5, #0
    .Lauto_080D7D96:
    ldr r0, [pc, #0x68]
    add r0, sp
    ldr r1, [r0]
    mov r3, sb
    ldr r2, [r3]
    cmp r1, #0
    beq .Lauto_080D7DB6
    .Lauto_080D7DA4:
    movs r7, #0x9d
    lsls r7, r7, #3
    add r7, sp
    ldr r7, [r7]
    ldr r0, [r7]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080D7DA4
    .Lauto_080D7DB6:
    cmp r2, #0
    beq .Lauto_080D7DC0
    adds r0, r2, #0
    bl free
    .Lauto_080D7DC0:
    mov r1, r8
    adds r0, r1, r5
    mov r2, sb
    str r5, [r2]
    str r4, [r2, #4]
    str r0, [r2, #0xc]
    .Lauto_080D7DCC:
    adds r5, r6, #0
    movs r0, #0x92
    lsls r0, r0, #3
    add r0, sp
    movs r3, #0xae
    lsls r3, r3, #3
    add r3, sp
    ldr r3, [r3]
    str r3, [r0]
    movs r4, #0xa8
    lsls r4, r4, #3
    add r4, sp
    ldr r4, [r4]
    mov sb, r4
    ldr r4, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r4, r0
    beq .Lauto_080D7E04
    cmp r4, #0
    beq .Lauto_080D7DF6
    str r3, [r4]
    .Lauto_080D7DF6:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    b .Lauto_080D7E98
    .byte 0x00, 0x00, 0x8C, 0x04, 0x00, 0x00
    .Lauto_080D7E04:
    adds r7, r4, #0
    movs r0, #1
    movs r1, #0x93
    lsls r1, r1, #3
    add r1, sp
    str r0, [r1]
    ldr r0, [r5]
    subs r0, r7, r0
    asrs r4, r0, #2
    ldr r0, [pc, #0x34]
    add r0, sp
    str r4, [r0]
    movs r2, #0x93
    lsls r2, r2, #3
    add r2, sp
    ldr r0, [r1]
    ldr r1, [pc, #0x24]
    add r1, sp
    cmp r4, r0
    bhs .Lauto_080D7E2E
    adds r1, r2, #0
    .Lauto_080D7E2E:
    ldr r0, [r1]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080D7E50
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lauto_080D7E54
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lauto_080D7E54
    .byte 0x94, 0x04, 0x00, 0x00
    .Lauto_080D7E50:
    movs r0, #0
    mov r8, r0
    .Lauto_080D7E54:
    adds r6, r0, #0
    ldr r1, [r5]
    cmp r7, r1
    beq .Lauto_080D7E68
    subs r4, r7, r1
    adds r2, r4, #0
    bl memmove
    adds r4, r0, r4
    b .Lauto_080D7E6A
    .Lauto_080D7E68:
    adds r4, r6, #0
    .Lauto_080D7E6A:
    movs r0, #0x93
    lsls r0, r0, #3
    add r0, sp
    ldr r1, [r0]
    ldr r2, [r5]
    cmp r1, #0
    beq .Lauto_080D7E84
    .Lauto_080D7E78:
    mov r7, sb
    ldr r0, [r7]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080D7E78
    .Lauto_080D7E84:
    cmp r2, #0
    beq .Lauto_080D7E8E
    adds r0, r2, #0
    bl free
    .Lauto_080D7E8E:
    mov r1, r8
    adds r0, r1, r6
    str r6, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080D7E98:
    movs r0, #4
    bl __builtin_new
    ldr r2, [pc, #0x114]
    add r2, sp
    ldr r1, [r2]
    bl __23HardwareBlendControllerP20HardwareDisplayState
    ldr r3, [pc, #0x10c]
    add r3, sp
    ldr r5, [r3]
    adds r4, r0, #0
    adds r6, r5, #0
    ldr r0, [r6]
    cmp r4, r0
    beq .Lauto_080D7EC2
    cmp r0, #0
    beq .Lauto_080D7EC2
    movs r1, #3
    bl _._23HardwareBlendController
    .Lauto_080D7EC2:
    str r4, [r5]
    movs r0, #0x68
    bl __builtin_new
    movs r7, #0xaa
    lsls r7, r7, #3
    add r7, sp
    ldr r7, [r7]
    ldr r1, [r7]
    bl __22GameSceneTextVariablesP18GameStateSaveImage
    movs r1, #0xad
    lsls r1, r1, #3
    add r1, sp
    ldr r5, [r1]
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lauto_080D7EF8
    cmp r1, #0
    beq .Lauto_080D7EF8
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080D7EF8:
    str r4, [r5]
    ldr r2, [pc, #0xc0]
    add r2, sp
    ldr r2, [r2]
    ldr r0, [r2]
    cmp r0, #0x29
    bne .Lauto_080D7FCC
    mov r0, sl
    adds r0, #0x94
    ldrb r1, [r0]
    adds r6, r0, #0
    cmp r1, #0
    beq .Lauto_080D7FCC
    ldr r3, [pc, #0xac]
    add r3, sp
    ldr r5, [r3]
    movs r4, #0xaa
    lsls r4, r4, #3
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4]
    ldr r7, [pc, #0xa0]
    add r7, sp
    ldr r7, [r7]
    ldr r2, [r7]
    movs r4, #0x87
    lsls r4, r4, #3
    add r4, sp
    adds r0, r4, #0
    movs r3, #0
    bl CreateGameWorld
    ldr r2, [r4]
    ldr r1, [pc, #0x8c]
    add r1, sp
    ldr r0, [pc, #0x88]
    add r0, sp
    str r4, [r0]
    str r2, [r1, #4]
    movs r0, #0
    str r0, [r4]
    adds r4, r2, #0
    ldr r0, [pc, #0x70]
    add r0, sp
    ldr r0, [r0]
    ldr r1, [r0]
    cmp r4, r1
    beq .Lauto_080D7F68
    cmp r1, #0
    beq .Lauto_080D7F68
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080D7F68:
    str r4, [r5]
    movs r0, #0x87
    lsls r0, r0, #3
    add r0, sp
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080D7F82
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080D7F82:
    ldr r1, [r6]
    lsls r1, r1, #8
    lsrs r1, r1, #0x10
    mov r0, sl
    adds r0, #0x98
    movs r2, #0
    ldrsh r5, [r0, r2]
    adds r0, #2
    movs r3, #0
    ldrsh r4, [r0, r3]
    mov r0, sl
    adds r2, r5, #0
    adds r3, r4, #0
    bl func_080DC2B4
    movs r0, #0
    str r0, [sp]
    mov r0, sl
    movs r1, #0
    adds r2, r5, #0
    adds r3, r4, #0
    bl func_080DC360
    b .Lauto_080D803C
    .byte 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00, 0x64, 0x05
    .byte 0x00, 0x00, 0x4C, 0x05, 0x00, 0x00, 0x9C, 0x04, 0x00, 0x00
    .Lauto_080D7FCC:
    ldr r4, [pc, #0x90]
    add r4, sp
    ldr r5, [r4]
    movs r6, #0xaa
    lsls r6, r6, #3
    add r6, sp
    ldr r6, [r6]
    ldr r1, [r6]
    ldr r7, [pc, #0x84]
    add r7, sp
    ldr r7, [r7]
    ldr r2, [r7]
    movs r4, #0x87
    lsls r4, r4, #3
    add r4, sp
    adds r0, r4, #0
    movs r3, #1
    bl CreateGameWorld
    ldr r2, [r4]
    ldr r1, [pc, #0x70]
    add r1, sp
    ldr r0, [pc, #0x6c]
    add r0, sp
    str r4, [r0]
    str r2, [r1, #4]
    movs r0, #0
    str r0, [r4]
    adds r4, r2, #0
    ldr r0, [pc, #0x58]
    add r0, sp
    ldr r0, [r0]
    ldr r1, [r0]
    cmp r4, r1
    beq .Lauto_080D8022
    cmp r1, #0
    beq .Lauto_080D8022
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080D8022:
    str r4, [r5]
    movs r0, #0x87
    lsls r0, r0, #3
    add r0, sp
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080D803C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080D803C:
    movs r0, #0
    movs r1, #0xab
    lsls r1, r1, #3
    add r1, sp
    ldr r1, [r1]
    str r0, [r1]
    ldr r2, [pc, #0x20]
    add r2, sp
    ldr r2, [r2]
    ldr r0, [r2]
    cmp r0, #0x2e
    bls .Lauto_080D8056
    b .Lauto_080D879C
    .Lauto_080D8056:
    lsls r0, r0, #2
    ldr r1, [pc, #0x14]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x64, 0x05, 0x00, 0x00, 0x4C, 0x05, 0x00, 0x00, 0xA4, 0x04, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00
    .byte 0x74, 0x80, 0x0D, 0x08, 0x30, 0x81, 0x0D, 0x08, 0x88, 0x81, 0x0D, 0x08, 0x7C, 0x83, 0x0D, 0x08
    .byte 0x22, 0x83, 0x0D, 0x08, 0xE4, 0x83, 0x0D, 0x08, 0x40, 0x84, 0x0D, 0x08, 0x78, 0x82, 0x0D, 0x08
    .byte 0xD4, 0x82, 0x0D, 0x08, 0x9C, 0x84, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0xD8, 0x85, 0x0D, 0x08, 0x5C, 0x87, 0x0D, 0x08, 0x5C, 0x87, 0x0D, 0x08, 0x5C, 0x87, 0x0D, 0x08
    .byte 0x5C, 0x87, 0x0D, 0x08, 0x20, 0x86, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0xF0, 0x86, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0x58, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x94, 0x85, 0x0D, 0x08, 0xA8, 0x86, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08, 0x94, 0x85, 0x0D, 0x08
    .byte 0x10, 0x49, 0x50, 0x46, 0x00, 0x22, 0x03, 0xF0, 0x87, 0xFC, 0x0F, 0x48, 0x02, 0x68, 0xDB, 0x23
    .byte 0x9B, 0x00, 0xD2, 0x18, 0x20, 0x20, 0x40, 0x42, 0x0C, 0x4C, 0x6C, 0x44, 0x24, 0x88, 0x20, 0x40
    .byte 0x06, 0x21, 0x08, 0x43, 0x00, 0x06, 0x00, 0x0E, 0x09, 0x49, 0x08, 0x4D, 0x6D, 0x44, 0x2D, 0x88
    .byte 0x29, 0x40, 0x01, 0x43, 0x07, 0x48, 0x01, 0x40, 0x1D, 0x23, 0x01, 0x20, 0x10, 0x70, 0x53, 0x60
    .byte 0x11, 0x81, 0x13, 0xE3, 0x63, 0x03, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0xEC, 0x04, 0x00, 0x00
    .byte 0x00, 0xFF, 0xFF, 0xFF, 0x1F, 0xF8, 0xFF, 0xFF, 0x37, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x68
    .byte 0x01, 0x68, 0x94, 0x27, 0x7F, 0x00, 0xC9, 0x19, 0x09, 0x68, 0xFA, 0xF7, 0x95, 0xFF, 0x0C, 0x20
    bl __builtin_new
    .byte 0x01, 0x21, 0x00, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __23MapClockStatusHudWidgetUiUiUiUi
    .byte 0x54, 0x46, 0xB4, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x26, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x7E, 0xFF, 0x25, 0x60, 0xAA, 0x20, 0xC0, 0x00
    .byte 0x68, 0x44, 0x00, 0x68, 0x01, 0x68, 0x23, 0x4A, 0x88, 0x18, 0x00, 0x78
    .byte 0x80, 0x07, 0x00, 0x28, 0x09, 0xDA, 0x21, 0x4B, 0xC8, 0x18, 0x00, 0x78
    .byte 0x00, 0x28, 0x04, 0xD1, 0x30, 0x68, 0x41, 0x68, 0xC9, 0x68, 0xFA, 0xF7
    .byte 0x66, 0xFF, 0x34, 0x68, 0x00, 0x25, 0x19, 0x4F, 0x6F, 0x44, 0x3F, 0x68
    .byte 0x38, 0x68, 0x01, 0x68, 0xB0, 0x31, 0x09, 0x68, 0xFA, 0xF7, 0x5B, 0xFF
    .byte 0x00, 0x06, 0x00, 0x28, 0x0B, 0xD1, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x09, 0x68, 0x08, 0x68, 0x41, 0x8A, 0x49, 0x05, 0x89, 0x0E, 0x01, 0x20
    .byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x01, 0x25, 0x2A, 0x1C, 0xAA, 0x23
    .byte 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68, 0x19, 0x68, 0x10, 0x31, 0x20, 0x1C
    .byte 0x08, 0x30
    bl UpdateMapClockStatusHudCalendar
    .byte 0x30, 0x68, 0xAA, 0x24, 0xE4, 0x00, 0x6C, 0x44
    .byte 0x24, 0x68, 0x21, 0x68, 0x89, 0x68, 0x08, 0x30
    bl SetMapClockStatusHudUnkSelector
    .byte 0x05, 0x4D, 0x6D, 0x44
    .byte 0x2D, 0x68, 0x28, 0x68, 0x64, 0xE1, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x10, 0x22, 0x00, 0x00
    .byte 0xC4, 0x34, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x01, 0x24, 0xAB, 0x26, 0xF6, 0x00, 0x6E, 0x44
    .byte 0x36, 0x68, 0x34, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x04, 0x21, 0x01, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x0A, 0xFF, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0x02, 0xFF, 0x02, 0x4F, 0x6F, 0x44, 0x3F, 0x68
    .byte 0x38, 0x68, 0x30, 0xE1, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x01, 0x24
    .byte 0xAB, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x00, 0x68, 0x04, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x05, 0x21, 0x01, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0xDC, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0xD4, 0xFE, 0x02, 0xE1, 0x01, 0x24, 0xAB, 0x22
    .byte 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x14, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x01, 0x94, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0xB6, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0xAE, 0xFE, 0x02, 0x4B, 0x6B, 0x44, 0x1B, 0x68
    .byte 0x18, 0x68, 0xDC, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x01, 0x24
    .byte 0xAB, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2C, 0x60, 0x15, 0x4E
    .byte 0x6E, 0x44, 0x36, 0x68, 0x30, 0x68, 0x01, 0x68, 0x94, 0x27, 0x7F, 0x00
    .byte 0xC9, 0x19, 0x09, 0x68, 0xFA, 0xF7, 0x95, 0xFE, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x00, 0x21, 0x01, 0x91, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x7E, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0x76, 0xFE, 0xA4, 0xE0, 0x00, 0x00, 0x64, 0x05
    .byte 0x00, 0x00, 0x01, 0x24, 0xAB, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68
    .byte 0x14, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x02, 0x21, 0x01, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x54, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0x4C, 0xFE, 0x02, 0x4B, 0x6B, 0x44, 0x1B, 0x68
    .byte 0x18, 0x68, 0x7A, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x01, 0x24
    .byte 0xAB, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2C, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x00, 0x94, 0x03, 0x21, 0x01, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x26, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xFA, 0xF7, 0x1E, 0xFE, 0x02, 0x4E, 0x6E, 0x44, 0x36, 0x68
    .byte 0x30, 0x68, 0x4C, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x06, 0x20
    .byte 0xAB, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x60, 0x04, 0x20
    bl __builtin_new
    .byte 0x06, 0x1C
    .byte 0x87, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x28, 0x1C
    bl __17ObjTileCollection
    .byte 0x1F, 0x4C, 0x6C, 0x44
    .byte 0x20, 0x1C
    bl __20ObjPaletteCollection
    .byte 0x01, 0x20, 0x00, 0x90, 0x01, 0x95, 0x02, 0x94, 0x30, 0x1C
    .byte 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
    .byte 0x54, 0x46, 0xAC, 0x34, 0x05, 0x1C
    .byte 0x20, 0x68, 0x26, 0x1C, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0x11, 0x48, 0x68, 0x44, 0x02, 0x21
    bl _._20ObjPaletteCollection
    .byte 0x87, 0x20
    .byte 0xC0, 0x00, 0x68, 0x44, 0x02, 0x21
    bl _._17ObjTileCollection
    .byte 0x30, 0x68, 0x78, 0xF7, 0xF2, 0xFA
    .byte 0x30, 0x68, 0x0B, 0x49, 0x0B, 0x4A, 0x0C, 0x4B, 0x0C, 0x4D, 0x00, 0x24, 0x00, 0x95, 0x01, 0x94
    .byte 0x02, 0x94, 0x03, 0x94, 0x78, 0xF7, 0x38, 0xFB, 0x09, 0x49, 0x69, 0x44, 0x09, 0x68, 0x08, 0x68
    .byte 0x08, 0x49, 0x01, 0x22, 0x01, 0x23
    bl BeginHardwareBlend
    .byte 0x2F, 0xE1, 0x3C, 0x04, 0x00, 0x00
    .word gText_HelpMenu_Crops
    .word gText_HelpMenu_Animals
    .word gText_HelpMenu_UsefulTips
    .word gText_HelpMenu_Exit
    .byte 0x5C, 0x05, 0x00, 0x00, 0x89, 0x08, 0x00, 0x00, 0x1A, 0x48, 0x02, 0x68, 0xDB, 0x23, 0x9B, 0x00
    .byte 0xD2, 0x18, 0x20, 0x20, 0x40, 0x42, 0x9E, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x88, 0x20, 0x40
    .byte 0x06, 0x21, 0x08, 0x43, 0x00, 0x06, 0x00, 0x0E, 0x13, 0x49, 0x9E, 0x25, 0xED, 0x00, 0x6D, 0x44
    .byte 0x2D, 0x88, 0x29, 0x40, 0x01, 0x43, 0x11, 0x48, 0x01, 0x40, 0x1D, 0x23, 0x01, 0x20, 0x10, 0x70
    .byte 0x53, 0x60, 0x11, 0x81, 0x51, 0x46, 0xE8, 0x31, 0x00, 0x23, 0x01, 0x20, 0x08, 0x70, 0x50, 0x46
    .byte 0xE9, 0x30, 0x03, 0x70, 0x56, 0x46, 0x31, 0x8A, 0x09, 0x48, 0x08, 0x40, 0x30, 0x82, 0x52, 0x46
    .byte 0x60, 0x32, 0x11, 0x88, 0x07, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46, 0x5C, 0x30, 0x03, 0x80
    .byte 0xBF, 0xE0, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0x1F, 0xF8, 0xFF, 0xFF
    .byte 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x51, 0x46, 0xE8, 0x31, 0x00, 0x23, 0x01, 0x20
    .byte 0x08, 0x70, 0x50, 0x46, 0xE9, 0x30, 0x03, 0x70, 0x57, 0x46, 0x39, 0x8A, 0x09, 0x48, 0x08, 0x40
    .byte 0x38, 0x82, 0x52, 0x46, 0x60, 0x32, 0x11, 0x88, 0x07, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46
    .byte 0x5C, 0x30, 0x03, 0x80, 0x05, 0x48, 0x00, 0x68, 0x08, 0x30, 0x51, 0x46, 0x94, 0x31, 0x09, 0x68
    .byte 0x95, 0xE0, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0x51, 0x46, 0xE8, 0x31, 0x00, 0x23, 0x01, 0x20, 0x08, 0x70, 0x50, 0x46, 0xE9, 0x30, 0x03, 0x70
    .byte 0x50, 0x46, 0x01, 0x8A, 0x0D, 0x48, 0x08, 0x40, 0x51, 0x46, 0x08, 0x82, 0x52, 0x46, 0x60, 0x32
    .byte 0x11, 0x88, 0x0B, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46, 0x5C, 0x30, 0x03, 0x80, 0xAA, 0x22
    .byte 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x06, 0x4B, 0xC8, 0x18, 0x02, 0x78, 0x50, 0x06
    .byte 0x00, 0x28, 0x09, 0xDA, 0x01, 0x21, 0x49, 0x42, 0x17, 0xE0, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00
    .byte 0x3F, 0xFF, 0x00, 0x00, 0x4A, 0x2C, 0x00, 0x00, 0x06, 0x4C, 0x08, 0x19, 0x01, 0x78, 0x03, 0x20
    .byte 0x08, 0x40, 0x03, 0x28, 0x08, 0xD1, 0xD0, 0x09, 0x02, 0x21, 0x00, 0x28, 0x05, 0xD0, 0x01, 0x21
    .byte 0x03, 0xE0, 0x00, 0x00, 0x48, 0x2C, 0x00, 0x00, 0x00, 0x21, 0x02, 0x48, 0x00, 0x68, 0x08, 0x30
    .byte 0x4D, 0xE0, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0x51, 0x46, 0xE8, 0x31, 0x00, 0x23, 0x01, 0x20
    .byte 0x08, 0x70, 0x50, 0x46, 0xE9, 0x30, 0x03, 0x70, 0x55, 0x46, 0x29, 0x8A, 0x09, 0x48, 0x08, 0x40
    .byte 0x28, 0x82, 0x52, 0x46, 0x60, 0x32, 0x11, 0x88, 0x07, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46
    .byte 0x5C, 0x30, 0x03, 0x80, 0x05, 0x48, 0x00, 0x68, 0x08, 0x30, 0x51, 0x46, 0x94, 0x31, 0x09, 0x68
    .byte 0x2D, 0xE0, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0x51, 0x46, 0xE8, 0x31, 0x00, 0x23, 0x01, 0x20, 0x08, 0x70, 0x50, 0x46, 0xE9, 0x30, 0x03, 0x70
    .byte 0x56, 0x46, 0x31, 0x8A, 0x11, 0x48, 0x08, 0x40, 0x30, 0x82, 0x52, 0x46, 0x60, 0x32, 0x11, 0x88
    .byte 0x0F, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46, 0x5C, 0x30, 0x03, 0x80, 0x0D, 0x48, 0x00, 0x68
    .byte 0x02, 0x1C, 0x08, 0x32, 0xAA, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68, 0x0A, 0x49
    .byte 0x40, 0x18, 0x00, 0x21, 0x00, 0x78, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x10, 0x1C, 0x66, 0xF7
    .byte 0xF5, 0xFE, 0x50, 0x46
    bl func_080D7F3C
    .byte 0x28, 0xE0, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00
    .byte 0x3F, 0xFF, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0x4C, 0x2C, 0x00, 0x00, 0x51, 0x46, 0xE8, 0x31
    .byte 0x00, 0x23, 0x01, 0x20, 0x08, 0x70, 0x50, 0x46, 0xE9, 0x30, 0x03, 0x70, 0x52, 0x46, 0x11, 0x8A
    .byte 0x19, 0x48, 0x08, 0x40, 0x10, 0x82, 0x60, 0x32, 0x11, 0x88, 0x18, 0x48, 0x08, 0x40, 0x10, 0x80
    .byte 0x50, 0x46, 0x5C, 0x30, 0x03, 0x80, 0x16, 0x48, 0x00, 0x68, 0x08, 0x30, 0x51, 0x46, 0x94, 0x31
    .byte 0x09, 0x78, 0x66, 0xF7, 0xCB, 0xFE, 0x50, 0x46
    bl func_080D7F3C
    .Lauto_080D879C:
    add r0, sp, #0x10
    bl UpdateHardwareKeyRepeat
    movs r3, #0xaa
    lsls r3, r3, #3
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3]
    ldr r1, [r0, #0x10]
    ldr r0, [pc, #0x34]
    add r0, sp
    str r1, [r0]
    bl rand
    movs r4, #0
    ldr r5, [pc, #0x2c]
    add r5, sp
    str r4, [r5]
    movs r6, #0xab
    lsls r6, r6, #3
    add r6, sp
    ldr r6, [r6]
    ldr r0, [r6]
    cmp r0, #0x1d
    bhi .Lauto_080D88A8
    lsls r0, r0, #2
    ldr r1, [pc, #0x18]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0xCC, 0x04, 0x00, 0x00
    .byte 0xF4, 0x04, 0x00, 0x00, 0xF0, 0x87, 0x0D, 0x08, 0x68, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08
    .byte 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08
    .byte 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08
    .byte 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08
    .byte 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08
    .byte 0xA0, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08
    .byte 0xA0, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08, 0x90, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08
    .byte 0xA0, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08, 0xA0, 0x88, 0x0D, 0x08
    .byte 0x07, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14
    .byte 0x41, 0x42, 0x01, 0x43, 0xC9, 0x0F, 0x03, 0x48, 0x68, 0x44, 0x01, 0x60, 0x10, 0xE0, 0x00, 0x00
    .byte 0x5C, 0x05, 0x00, 0x00, 0xF4, 0x04, 0x00, 0x00, 0x01, 0x21, 0x02, 0x4A, 0x6A, 0x44, 0x11, 0x60
    .byte 0x06, 0xE0, 0x00, 0x00, 0xF4, 0x04, 0x00, 0x00, 0x00, 0x23, 0x08, 0x4C, 0x6C, 0x44, 0x23, 0x60
    .Lauto_080D88A8:
    movs r5, #0xab
    lsls r5, r5, #3
    add r5, sp
    ldr r5, [r5]
    ldr r0, [r5]
    cmp r0, #0x1d
    bls .Lauto_080D88B8
    b .Lauto_080D8B9C
    .Lauto_080D88B8:
    lsls r0, r0, #2
    ldr r1, [pc, #0xc]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0xF4, 0x04, 0x00, 0x00, 0xCC, 0x88, 0x0D, 0x08, 0x44, 0x89, 0x0D, 0x08, 0x70, 0x89
    .byte 0x0D, 0x08, 0xD0, 0x89, 0x0D, 0x08, 0x44, 0x89, 0x0D, 0x08, 0x44, 0x89, 0x0D, 0x08, 0x44, 0x89
    .byte 0x0D, 0x08, 0xA8, 0x89, 0x0D, 0x08, 0x44, 0x89, 0x0D, 0x08, 0x70, 0x89, 0x0D, 0x08, 0x70, 0x89
    .byte 0x0D, 0x08, 0xA8, 0x89, 0x0D, 0x08, 0xA8, 0x89, 0x0D, 0x08, 0xA8, 0x89, 0x0D, 0x08, 0x70, 0x89
    .byte 0x0D, 0x08, 0x3C, 0x8A, 0x0D, 0x08, 0x3C, 0x8A, 0x0D, 0x08, 0x3C, 0x8A, 0x0D, 0x08, 0x78, 0x8A
    .byte 0x0D, 0x08, 0x10, 0x8B, 0x0D, 0x08, 0x68, 0x8B, 0x0D, 0x08, 0x3C, 0x8A, 0x0D, 0x08, 0x00, 0x8A
    .byte 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A
    .byte 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A, 0x0D, 0x08, 0x00, 0x8A
    .byte 0x0D, 0x08, 0x50, 0x46, 0xB4, 0x30, 0x05, 0x68, 0x56, 0x46, 0x6C, 0x36, 0x4C, 0x38
    bl func_08008AE0
    .byte 0x69, 0x68, 0x00, 0x90, 0xCC, 0x6A, 0x28, 0x1C, 0x0D, 0xA9, 0x03, 0x4F, 0x6F, 0x44
    .byte 0x3A, 0x68, 0x33, 0x1C, 0xFA, 0xF7, 0xB5, 0xFB, 0x17, 0xE1, 0x44, 0x05, 0x00, 0x00, 0x50, 0x46
    .byte 0xB8, 0x30, 0x05, 0x68, 0x54, 0x46, 0x6C, 0x34, 0x50, 0x38
    bl func_08008AE0
    .byte 0x00, 0x94, 0x01, 0x90, 0x06, 0x48, 0x68, 0x44, 0x00, 0x68, 0x02, 0x90
    .byte 0x28, 0x1C, 0x04, 0xA9, 0x0D, 0xAA, 0x04, 0x4C, 0x6C, 0x44, 0x23, 0x68
    bl Update__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
    .byte 0xFE, 0xE0, 0x00, 0x00, 0x6C, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00
    .byte 0x50, 0x46, 0xAC, 0x30, 0x05, 0x68, 0x54, 0x46, 0x6C, 0x34, 0x44, 0x38
    bl func_08008AE0
    .byte 0x00, 0x94, 0x01, 0x90, 0x03, 0x4E, 0x6E, 0x44, 0x36, 0x68
    .byte 0x02, 0x96, 0x28, 0x1C, 0x04, 0xA9, 0x95, 0xE0, 0x00, 0x00, 0x6C, 0x05, 0x00, 0x00, 0x50, 0x46
    .byte 0xAC, 0x30, 0x05, 0x68, 0x00, 0x2D, 0x12, 0xD0, 0x54, 0x46, 0x6C, 0x34, 0x44, 0x38
    bl func_08008AE0
    .byte 0x00, 0x94, 0x01, 0x90, 0x12, 0x48, 0x68, 0x44, 0x00, 0x68, 0x02, 0x90, 0x28, 0x1C
    .byte 0x04, 0xA9, 0x0D, 0xAA, 0x10, 0x4C, 0x6C, 0x44, 0x23, 0x68
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    .byte 0x50, 0x46
    .byte 0xE8, 0x30, 0x00, 0x78, 0x00, 0x28, 0x00, 0xD0, 0xC7, 0xE0, 0x50, 0x46, 0xB4, 0x30, 0x06, 0x68
    .byte 0x00, 0x2E, 0x00, 0xD1, 0xC1, 0xE0, 0x55, 0x46, 0x6C, 0x35, 0x4C, 0x38
    bl func_08008AE0
    .byte 0x71, 0x68, 0x00, 0x90, 0xCC, 0x6A, 0x30, 0x1C, 0x0D, 0xA9, 0x02, 0x4E, 0x6E, 0x44, 0x32, 0x68
    .byte 0x90, 0xE0, 0x6C, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x50, 0x46, 0xAC, 0x30, 0x05, 0x68
    .byte 0x00, 0x2D, 0x00, 0xD1, 0xA9, 0xE0, 0x54, 0x46, 0x6C, 0x34, 0x44, 0x38
    bl func_08008AE0
    .byte 0x00, 0x94, 0x01, 0x90, 0x06, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x02, 0x97, 0x28, 0x1C, 0x04, 0xA9
    .byte 0x0D, 0xAA, 0x03, 0x4C, 0x6C, 0x44, 0x23, 0x68
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    .byte 0x95, 0xE0, 0x6C, 0x05
    .byte 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x50, 0x46, 0xAC, 0x30, 0x05, 0x68, 0x00, 0x2D, 0x00, 0xD1
    .byte 0x8B, 0xE0, 0x04, 0xA8, 0x02, 0x89, 0x03, 0x20, 0x40, 0x42, 0x10, 0x40, 0x00, 0x06, 0x00, 0x0E
    .byte 0x1C, 0x4B, 0x19, 0x1C, 0x11, 0x40, 0x01, 0x43, 0x41, 0x20, 0x40, 0x42, 0x08, 0x40, 0x00, 0x06
    .byte 0x00, 0x0E, 0x19, 0x40, 0x01, 0x43, 0x7F, 0x20, 0x08, 0x40, 0x19, 0x40, 0x01, 0x43, 0x21, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x00, 0x06, 0x00, 0x0E, 0x19, 0x40, 0x01, 0x43, 0x11, 0x20, 0x40, 0x42
    .byte 0x08, 0x40, 0x00, 0x06, 0x00, 0x0E, 0x19, 0x40, 0x01, 0x43, 0x89, 0x20, 0xC0, 0x00, 0x68, 0x44
    bl __18HardwareInputStateUi
    .byte 0x54, 0x46, 0x6C, 0x34, 0x50, 0x46, 0x68, 0x30
    bl func_08008AE0
    .byte 0x00, 0x94, 0x01, 0x90, 0x08, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x02, 0x96, 0x28, 0x1C, 0x89, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x0D, 0xAA, 0x04, 0x4F, 0x6F, 0x44, 0x3B, 0x68
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    .byte 0x4B, 0xE0, 0x00, 0xFF, 0xFF, 0xFF, 0x6C, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x13, 0x49
    .byte 0x69, 0x44, 0x09, 0x68, 0x08, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42
    .byte 0x01, 0x43, 0x00, 0x29, 0x39, 0xDA, 0x50, 0x46, 0xE8, 0x30, 0x00, 0x78, 0x00, 0x28, 0x34, 0xD1
    .byte 0x50, 0x46, 0xB4, 0x30, 0x06, 0x68, 0x00, 0x2E, 0x2F, 0xD0, 0x55, 0x46, 0x6C, 0x35, 0x4C, 0x38
    bl func_08008AE0
    .byte 0x71, 0x68, 0x00, 0x90, 0xCC, 0x6A, 0x30, 0x1C, 0x0D, 0xA9, 0x04, 0x4B
    .byte 0x6B, 0x44, 0x1A, 0x68, 0x2B, 0x1C, 0xFA, 0xF7, 0xBC, 0xFA, 0x1E, 0xE0, 0x00, 0x00, 0x5C, 0x05
    .byte 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x50, 0x46, 0xE8, 0x30, 0x00, 0x78, 0x00, 0x28, 0x14, 0xD1
    .byte 0x50, 0x46, 0xB4, 0x30, 0x06, 0x68, 0x00, 0x2E, 0x0F, 0xD0, 0x55, 0x46, 0x6C, 0x35, 0x4C, 0x38
    bl func_08008AE0
    .byte 0x71, 0x68, 0x00, 0x90, 0xCC, 0x6A, 0x30, 0x1C, 0x0D, 0xA9, 0x09, 0x4E
    .byte 0x6E, 0x44, 0x32, 0x68, 0x2B, 0x1C, 0xFA, 0xF7, 0x9C, 0xFA
    .Lauto_080D8B9C:
    movs r7, #0xab
    lsls r7, r7, #3
    add r7, sp
    ldr r7, [r7]
    ldr r0, [r7]
    cmp r0, #0x1d
    bls .Lauto_080D8BAE
    bl .Lauto_080DA29A
    .Lauto_080D8BAE:
    lsls r0, r0, #2
    ldr r1, [pc, #8]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x44, 0x05, 0x00, 0x00, 0xC0, 0x8B, 0x0D, 0x08, 0x38, 0x8C, 0x0D, 0x08
    .byte 0xFA, 0x94, 0x0D, 0x08, 0x2C, 0x9A, 0x0D, 0x08, 0xE4, 0x8D, 0x0D, 0x08
    .byte 0xBC, 0x8E, 0x0D, 0x08, 0x98, 0x8F, 0x0D, 0x08, 0x68, 0x91, 0x0D, 0x08
    .byte 0x88, 0x94, 0x0D, 0x08, 0xEE, 0x98, 0x0D, 0x08, 0xEC, 0x99, 0x0D, 0x08
    .byte 0xDC, 0x93, 0x0D, 0x08, 0x4A, 0x94, 0x0D, 0x08, 0x28, 0x91, 0x0D, 0x08
    .byte 0x88, 0x90, 0x0D, 0x08, 0x38, 0x9D, 0x0D, 0x08, 0x4A, 0x9D, 0x0D, 0x08
    .byte 0x70, 0x9D, 0x0D, 0x08, 0x82, 0x9D, 0x0D, 0x08, 0x9C, 0x9E, 0x0D, 0x08
    .byte 0xEC, 0x9E, 0x0D, 0x08, 0x50, 0x9F, 0x0D, 0x08, 0x0C, 0x9F, 0x0D, 0x08
    .byte 0x2C, 0x9F, 0x0D, 0x08, 0x7C, 0x9F, 0x0D, 0x08, 0x04, 0xA2, 0x0D, 0x08
    .byte 0x94, 0x9F, 0x0D, 0x08, 0xC8, 0x9F, 0x0D, 0x08, 0x20, 0xA2, 0x0D, 0x08
    .byte 0x50, 0xA2, 0x0D, 0x08, 0x80, 0xA2, 0x0D, 0x08, 0x04, 0xA8, 0x85, 0x88
    .byte 0x01, 0x88, 0x40, 0x48, 0x68, 0x44, 0x01, 0x60, 0x0C, 0x20, 0x28, 0x40
    .byte 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0x25, 0xFB, 0x50, 0x46, 0xB4, 0x30
    .byte 0x00, 0x68
    bl GetPhase__C13ControlWidget
    .byte 0x06, 0x1C, 0x39, 0x49, 0x69, 0x44, 0x09, 0x68, 0x08, 0x68, 0x01, 0x68
    .byte 0x0A, 0x6C, 0x4B, 0x21, 0xFA, 0xF7, 0x2F, 0xFA, 0x03, 0x1C, 0x35, 0x48
    .byte 0x04, 0x68, 0xDE, 0x22, 0x92, 0x00, 0x12, 0x19, 0x90, 0x46, 0x31, 0x4F
    .byte 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x00, 0x21
    .byte 0xB0, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3B, 0x60, 0xFA, 0xF7, 0x1B, 0xFA
    .byte 0x02, 0x1C, 0xB0, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x03, 0x68, 0x03, 0x2E
    .byte 0x03, 0xD0, 0x00, 0x2E, 0x01, 0xD0, 0x01, 0xF0, 0xF7, 0xFA, 0x00, 0x26
    .byte 0x00, 0x21, 0x47, 0x46, 0x38, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21
    .byte 0x00, 0x29, 0x14, 0xD0, 0xE3, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x21
    .byte 0x00, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x0A, 0xD0
    .byte 0x9A, 0x27, 0xFF, 0x00, 0xE0, 0x19, 0x00, 0x21, 0x00, 0x68, 0x00, 0x28
    .byte 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x00, 0xD0, 0x01, 0x26, 0x00, 0x2E
    .byte 0x01, 0xD1, 0x01, 0xF0, 0xD5, 0xFA, 0x00, 0x2B, 0x0D, 0xD0, 0x18, 0x1C
    .byte 0x15, 0x49, 0x69, 0x44, 0x0A, 0x60, 0x5F, 0xF7, 0xCE, 0xF8, 0x00, 0x06
    .byte 0x12, 0x4B, 0x6B, 0x44, 0x1A, 0x68, 0x00, 0x28, 0x01, 0xD0, 0x01, 0xF0
    .byte 0xC5, 0xFA, 0x50, 0x69, 0x94, 0x30, 0x01, 0x68, 0x10, 0x1C, 0xFA, 0xF7
    .byte 0xD6, 0xF9, 0x00, 0x06, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0xBA, 0xFA
    .byte 0x06, 0x48, 0x68, 0x44, 0x41, 0x78, 0x02, 0x20, 0x08, 0x40, 0x00, 0x28
    .byte 0x21, 0xD0, 0x08, 0x20, 0x28, 0x40, 0x00, 0x28, 0x09, 0xD0, 0x04, 0x20
    .byte 0x3C, 0xE0, 0xAC, 0x04, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x0C, 0x04
    .byte 0x00, 0x03, 0x7C, 0x05, 0x00, 0x00, 0x04, 0x20, 0x05, 0x40, 0x00, 0x2D
    .byte 0x01, 0xD1, 0x01, 0xF0, 0x9F, 0xFA, 0x05, 0x20, 0xAB, 0x26, 0xF6, 0x00
    .byte 0x6E, 0x44, 0x36, 0x68, 0x30, 0x60, 0x02, 0x4F, 0x6F, 0x44, 0x3F, 0x68
    .byte 0x38, 0x68, 0x2C, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0xAA, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x08, 0x68, 0x09, 0x4A, 0x80, 0x18
    .byte 0x00, 0x78, 0x00, 0x28, 0x0F, 0xD1, 0x08, 0x20, 0x28, 0x40, 0x00, 0x28
    .byte 0x0B, 0xD0, 0x50, 0x46, 0xB4, 0x30, 0x00, 0x68, 0x41, 0x68, 0x49, 0x69
    .byte 0xFA, 0xF7, 0x93, 0xF9, 0x07, 0x20, 0x01, 0xF0, 0x08, 0xF9, 0xC4, 0x34
    .byte 0x00, 0x00, 0x04, 0x20, 0x05, 0x40, 0x00, 0x2D, 0x01, 0xD1, 0x01, 0xF0
    .byte 0x71, 0xFA, 0x03, 0x20, 0xAB, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68
    .byte 0x20, 0x60, 0x05, 0x4D, 0x6D, 0x44, 0x2D, 0x68, 0x28, 0x68, 0x04, 0x49
    .byte 0x01, 0x22, 0x01, 0x23
    bl EndHardwareBlend
    .byte 0x01, 0xF0
    .byte 0x60, 0xFA, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x89, 0x08, 0x00, 0x00, 0x30, 0x4E, 0x6E, 0x44
    .byte 0x36, 0x68, 0x30, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43
    .byte 0xCF, 0x0F, 0x00, 0x2F, 0x01, 0xD0, 0x01, 0xF0, 0x4C, 0xFA, 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44
    .byte 0x01, 0x20, 0x80, 0x46, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x21, 0xC9, 0x00
    .byte 0x69, 0x44, 0x09, 0x68, 0x09, 0x68, 0x89, 0x46, 0x89, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x29, 0x1C
    .byte 0x4C, 0xCC, 0x4C, 0xC1, 0x1F, 0x49, 0x01, 0x60, 0x49, 0x46, 0x41, 0x60, 0x02, 0x1C, 0x08, 0x32
    .byte 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x58, 0xC9, 0x58, 0xC2, 0x1B, 0x4C, 0x6C, 0x44, 0x20, 0x60
    .byte 0x10, 0x20
    bl __builtin_new
    .byte 0x22, 0x68, 0x27, 0x60, 0x2A, 0x60, 0xAA, 0x21, 0xC9, 0x00
    .byte 0x69, 0x44, 0x09, 0x68, 0x0B, 0x68, 0x15, 0x49, 0x01, 0x60, 0x2F, 0x60, 0x42, 0x60, 0x83, 0x60
    .byte 0x42, 0x46, 0x02, 0x73, 0xAC, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1D, 0x68, 0x04, 0x1C, 0x2E, 0x1C
    .byte 0x31, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xFA, 0xF7, 0x1F, 0xF9, 0x2C, 0x60, 0xAC, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68
    .byte 0x38, 0x68, 0x00, 0x21, 0x39, 0x60, 0x06, 0x4B, 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x60, 0xD5, 0xE0
    .byte 0x5C, 0x05, 0x00, 0x00, 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0xF4, 0x52, 0x0E, 0x08
    .byte 0xDC, 0x04, 0x00, 0x00, 0x30, 0x4C, 0x6C, 0x44, 0x24, 0x68, 0x20, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43, 0xC9, 0x0F, 0x0C, 0x06, 0x27, 0x0E, 0x00, 0x2F
    .byte 0x01, 0xD0, 0x01, 0xF0, 0xDE, 0xF9, 0x10, 0x20
    bl __builtin_new
    .byte 0x06, 0x1C, 0xAA, 0x25
    .byte 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2D, 0x68, 0xA8, 0x46, 0x24, 0x48, 0x30, 0x60, 0x75, 0x60
    .byte 0x14, 0x20
    bl __builtin_new
    .byte 0x22, 0x49, 0x01, 0x60, 0x07, 0x71, 0x85, 0x1D, 0x8D, 0x23, 0x9B, 0x00, 0xC2, 0x88, 0x1F, 0x4C
    .byte 0x21, 0x1C, 0x11, 0x40, 0x19, 0x43, 0xC1, 0x80, 0x6A, 0x78, 0x03, 0x23, 0x19, 0x1C, 0x11, 0x40
    .byte 0x69, 0x70, 0x6A, 0x88, 0x21, 0x1C, 0x11, 0x40, 0x69, 0x80, 0xE9, 0x78, 0x0B, 0x40, 0xEB, 0x70
    .byte 0xA9, 0x88, 0x0C, 0x40, 0xAC, 0x80, 0x16, 0x49, 0x01, 0x60, 0x41, 0x46, 0xC1, 0x60, 0x07, 0x61
    .byte 0xB0, 0x60, 0xF7, 0x60, 0xAC, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x14, 0x68, 0x23, 0x1C, 0x19, 0x68
    .byte 0x8E, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
    .byte 0xFA, 0xF7, 0xB5, 0xF8, 0x26, 0x60, 0xAC, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0x21, 0x68
    .byte 0x00, 0x20, 0x20, 0x60, 0x08, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x31, 0x60, 0x01, 0xF0, 0x81, 0xFC
    .byte 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00
    .4byte __vt_17TownMapTransition
    .4byte __vt_26TownMapSelectionTransition
    .byte 0x00, 0xFC, 0xFF, 0xFF
    .4byte __vt_23TownMapReturnTransition
    .byte 0xDC, 0x04, 0x00, 0x00, 0x36, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14
    .byte 0x41, 0x42, 0x01, 0x43, 0xCE, 0x0F, 0x00, 0x2E, 0x01, 0xD0, 0x01, 0xF0, 0x72, 0xF9, 0x87, 0x24
    .byte 0xE4, 0x00, 0x6C, 0x44, 0x01, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x09, 0x68, 0x88, 0x46, 0x89, 0x25, 0xED, 0x00, 0x6D, 0x44
    .byte 0x29, 0x1C, 0x8C, 0xCC, 0x8C, 0xC1, 0x26, 0x49, 0x01, 0x60, 0x41, 0x46, 0x41, 0x60, 0x02, 0x1C
    .byte 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x98, 0xC9, 0x98, 0xC2, 0x21, 0x4C, 0x6C, 0x44
    .byte 0x20, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x23, 0x68, 0x26, 0x60, 0x2B, 0x60, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x09, 0x68, 0x0A, 0x68, 0x1B, 0x49, 0x01, 0x60, 0x42, 0x60, 0x2E, 0x60
    .byte 0x83, 0x60, 0xAC, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x15, 0x68, 0x04, 0x1C
    .byte 0x2B, 0x1C, 0x19, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0
    .byte 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xFA, 0xF7, 0x48, 0xF8
    .byte 0x2C, 0x60, 0xAC, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0x20, 0x68
    .byte 0x00, 0x21, 0x21, 0x60, 0x0D, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x60
    .byte 0x09, 0x48, 0x68, 0x44, 0x01, 0x68, 0x00, 0x29, 0x01, 0xD1, 0x01, 0xF0
    .byte 0x0F, 0xFC, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xFA, 0xF7
    .byte 0x2F, 0xF8, 0x01, 0xF0, 0x07, 0xFC, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00
    .byte 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0xD4, 0x52, 0x0E, 0x08
    .byte 0xDC, 0x04, 0x00, 0x00, 0x54, 0x46, 0xB8, 0x34, 0x20, 0x68
    bl GetPhase__C13ControlWidget
    .byte 0x00, 0x28, 0x01, 0xD0, 0x01, 0xF0, 0x00, 0xF9, 0x00, 0x25, 0x21, 0x68
    .byte 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xFA, 0xF7, 0x0D, 0xF8, 0x25, 0x60, 0x04, 0x20
    bl __builtin_new
    .byte 0x06, 0x1C, 0x87, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x28, 0x1C
    bl __17ObjTileCollection
    .byte 0x16, 0x4C, 0x6C, 0x44, 0x20, 0x1C
    bl __20ObjPaletteCollection
    .byte 0x01, 0x20, 0x00, 0x90, 0x01, 0x95
    .byte 0x02, 0x94, 0x30, 0x1C, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
    .byte 0x54, 0x46
    .byte 0xAC, 0x34, 0x05, 0x1C, 0x20, 0x68, 0x26, 0x1C, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0
    .byte 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0x08, 0x48, 0x68, 0x44, 0x02, 0x21
    bl _._20ObjPaletteCollection
    .byte 0x87, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x02, 0x21
    bl _._17ObjTileCollection
    .byte 0x30, 0x68
    .byte 0x77, 0xF7, 0xE6, 0xFC, 0x0C, 0x20, 0x00, 0xF0, 0x75, 0xFF, 0x00, 0x00, 0x3C, 0x04, 0x00, 0x00
    .byte 0x54, 0x46, 0xAC, 0x34, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x01, 0xD0, 0x01, 0xF0
    .byte 0xB0, 0xF8, 0x20, 0x68, 0x06, 0x49, 0x07, 0x4A, 0x07, 0x4B, 0x08, 0x4D, 0x00, 0x24, 0x00, 0x95
    .byte 0x01, 0x94, 0x02, 0x94, 0x03, 0x94, 0x77, 0xF7, 0x23, 0xFD, 0x06, 0x20, 0x01, 0xF0, 0x8B, 0xF8
    .word gText_HelpMenu_Crops
    .word gText_HelpMenu_Animals
    .word gText_HelpMenu_UsefulTips
    .word gText_HelpMenu_Exit
    .byte 0x11, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14
    .byte 0x41, 0x42, 0x01, 0x43, 0xCE, 0x0F, 0x00, 0x2E, 0x01, 0xD0, 0x01, 0xF0, 0x8A, 0xF8, 0x54, 0x46
    .byte 0xAC, 0x34, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x06, 0x28, 0x0F, 0xD1, 0x04, 0xA8, 0x80, 0x88
    .byte 0x02, 0x21, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0x7B, 0xF8, 0x20, 0x68, 0x77, 0xF7
    .byte 0xAB, 0xFC, 0x0A, 0x20, 0x00, 0xF0, 0x04, 0xFF, 0x5C, 0x05, 0x00, 0x00, 0x20, 0x68
    bl GetChoiceResult__C12UiStateOwner
    .byte 0x02, 0x28, 0x50, 0xD0, 0x02, 0x28, 0x03, 0xDC, 0x01, 0x28, 0x09, 0xD0, 0x01, 0xF0
    .byte 0x68, 0xF8, 0x03, 0x28, 0x00, 0xD1, 0x91, 0xE0, 0x04, 0x28, 0x00, 0xD1, 0xFC, 0xE0, 0x01, 0xF0
    .byte 0x60, 0xF8, 0x1D, 0x4C, 0x6C, 0x44, 0x24, 0x68, 0x20, 0x68, 0x1C, 0x49, 0x01, 0x22, 0x01, 0x23
    bl EndHardwareBlend
    .byte 0x0B, 0x20, 0xAB, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x28, 0x60
    .byte 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x08, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x3F, 0x68, 0xB8, 0x46, 0x89, 0x25, 0xED, 0x00
    .byte 0x6D, 0x44, 0x29, 0x1C, 0x8C, 0xCC, 0x8C, 0xC1, 0x0D, 0x49, 0x01, 0x60, 0x41, 0x46, 0x41, 0x60
    .byte 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x98, 0xC9, 0x98, 0xC2, 0x09, 0x49
    .byte 0x69, 0x44, 0x0E, 0x60, 0x28, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x29, 0x1C, 0x00, 0x22
    bl __25FarmingTutorialTransitionG20SceneTransitionOwner23MaryFarmingTutorialKind
    .byte 0x95, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x89, 0x08, 0x00, 0x00
    .byte 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0x20, 0x4B, 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x68
    .byte 0x1F, 0x49, 0x01, 0x22, 0x01, 0x23
    bl EndHardwareBlend
    .byte 0x0B, 0x20, 0xAB, 0x24, 0xE4, 0x00
    .byte 0x6C, 0x44, 0x24, 0x68, 0x20, 0x60, 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x08, 0x20, 0x20, 0x60
    .byte 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2D, 0x68
    .byte 0xA8, 0x46, 0x89, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x29, 0x1C, 0x8C, 0xCC, 0x8C, 0xC1, 0x11, 0x49
    .byte 0x01, 0x60, 0x44, 0x46, 0x44, 0x60, 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x98, 0xC9, 0x98, 0xC2, 0x0C, 0x49, 0x69, 0x44, 0x0E, 0x60, 0x28, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x29, 0x1C, 0x01, 0x22
    bl __25FarmingTutorialTransitionG20SceneTransitionOwner23MaryFarmingTutorialKind
    .byte 0xAC, 0x26, 0xF6, 0x00, 0x6E, 0x44
    .byte 0x35, 0x68, 0x04, 0x1C, 0x2F, 0x1C, 0x39, 0x68, 0x52, 0xE0, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00
    .byte 0x89, 0x08, 0x00, 0x00, 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0x31, 0x49, 0x69, 0x44
    .byte 0x09, 0x68, 0x08, 0x68, 0x30, 0x49, 0x01, 0x22, 0x01, 0x23
    bl EndHardwareBlend
    .byte 0x0B, 0x20
    .byte 0xAB, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x60, 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44
    .byte 0x08, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x23, 0xDB, 0x00, 0x6B, 0x44
    .byte 0x1B, 0x68, 0x1B, 0x68, 0x98, 0x46, 0x89, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x29, 0x1C, 0x8C, 0xCC
    .byte 0x8C, 0xC1, 0x22, 0x49, 0x01, 0x60, 0x44, 0x46, 0x44, 0x60, 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x98, 0xC9, 0x98, 0xC2, 0x1D, 0x4C, 0x6C, 0x44, 0x20, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x22, 0x68, 0x26, 0x60, 0x2A, 0x60, 0xAA, 0x27, 0xFF, 0x00, 0x6F, 0x44
    .byte 0x3F, 0x68, 0x3B, 0x68, 0x88, 0x24, 0x17, 0x49, 0x01, 0x60, 0x2E, 0x60, 0x42, 0x60, 0x83, 0x60
    .byte 0xC4, 0x60, 0xAC, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x0D, 0x68, 0x04, 0x1C, 0x2A, 0x1C, 0x11, 0x68
    .byte 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
    .byte 0xF9, 0xF7, 0x98, 0xFE, 0x2C, 0x60, 0x0A, 0x48, 0x68, 0x44, 0x01, 0x68, 0x00, 0x29, 0x01, 0xD1
    .byte 0x00, 0xF0, 0x77, 0xFF, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7, 0x8A, 0xFE
    .byte 0x00, 0xF0, 0x6F, 0xFF, 0x5C, 0x05, 0x00, 0x00, 0x89, 0x08, 0x00, 0x00, 0xB4, 0x52, 0x0E, 0x08
    .byte 0x44, 0x04, 0x00, 0x00
    .4byte __vt_23ReferencePageTransition
    .byte 0x20, 0x68, 0x77, 0xF7, 0x95, 0xFB, 0x0A, 0x20
    .byte 0x00, 0xF0, 0xEE, 0xFD, 0x54, 0x46, 0xAC, 0x34, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x00, 0x28
    .byte 0x01, 0xD0, 0x00, 0xF0, 0x56, 0xFF, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28
    .byte 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x01, 0x21, 0x00, 0x91, 0x06, 0x21, 0x01, 0x91, 0x00, 0x21, 0x1F, 0x22
    .byte 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xF9, 0xF7, 0x4A, 0xFE, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xF9, 0xF7, 0x42, 0xFE, 0x01, 0x20, 0x00, 0xF0, 0x6B, 0xFD
    .byte 0x0D, 0x4D, 0x6D, 0x44, 0x2D, 0x68, 0x28, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43, 0xC9, 0x0F, 0x00, 0x29
    .byte 0x01, 0xD0, 0x00, 0xF0, 0x19, 0xFF, 0xAC, 0x26, 0xF6, 0x00, 0x6E, 0x44
    .byte 0x36, 0x68, 0x30, 0x68, 0x31, 0x60, 0x03, 0x49, 0x69, 0x44, 0x09, 0x68
    .byte 0x08, 0x60, 0x01, 0xF0, 0x00, 0xFA, 0x5C, 0x05, 0x00, 0x00, 0xDC, 0x04
    .byte 0x00, 0x00, 0x54, 0x46, 0xB4, 0x34, 0x20, 0x68
    bl GetPhase__C13ControlWidget
    .byte 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0x00, 0xFF, 0x00, 0x25, 0x21, 0x68
    .byte 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7, 0x0D, 0xFE, 0x25, 0x60, 0x10, 0x20
    bl __builtin_new
    .byte 0x01, 0x21, 0x00, 0x91, 0x00, 0x21, 0x01, 0x91, 0x1F, 0x22, 0x00, 0x23
    bl __14MainMenuWidgetUiUiUiUiUi
    .byte 0x54, 0x46, 0xB8, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x27, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xF9, 0xF7, 0xF2, 0xFD, 0x25, 0x60, 0x38, 0x68, 0x41, 0x68
    .byte 0xC9, 0x68, 0xF9, 0xF7, 0xEA, 0xFD, 0x01, 0x20, 0x00, 0xF0, 0xCB, 0xFE
    .byte 0x54, 0x46, 0xB8, 0x34, 0x20, 0x68
    bl GetPhase__C13ControlWidget
    .byte 0x27, 0x1C, 0x03, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0xC6, 0xFE, 0x04, 0xA8
    .byte 0x82, 0x88, 0x01, 0x20, 0x10, 0x40, 0x00, 0x28, 0x00, 0xD1, 0xD9, 0xE1
    .byte 0x00, 0x23, 0x9F, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2B, 0x60, 0x20, 0x68
    bl GetSelection__C14MainMenuWidget
    .byte 0x06, 0x28, 0x00, 0xD9, 0xB2, 0xE1, 0x80, 0x00, 0x01, 0x49, 0x40, 0x18
    .byte 0x00, 0x68, 0x87, 0x46, 0x40, 0x95, 0x0D, 0x08, 0x5C, 0x95, 0x0D, 0x08
    .byte 0xC8, 0x97, 0x0D, 0x08, 0xD0, 0x95, 0x0D, 0x08, 0x70, 0x96, 0x0D, 0x08
    .byte 0xE4, 0x96, 0x0D, 0x08, 0x5C, 0x97, 0x0D, 0x08, 0x78, 0x98, 0x0D, 0x08
    .byte 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x02, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x36, 0x68, 0x36, 0x68, 0xB0, 0x46
    .byte 0x89, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x31, 0x1C, 0x2C, 0xCC, 0x2C, 0xC1, 0x0F, 0x49, 0x01, 0x60
    .byte 0x41, 0x46, 0x41, 0x60, 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x38, 0xC9
    .byte 0x38, 0xC2, 0x0B, 0x4C, 0x6C, 0x44, 0x20, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x25, 0x68
    .byte 0x00, 0x23, 0x23, 0x60, 0x35, 0x60, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x0A, 0x68
    .byte 0x04, 0x49, 0x01, 0x60, 0x42, 0x60, 0x33, 0x60, 0x85, 0x60, 0x34, 0xE1, 0xB4, 0x52, 0x0E, 0x08
    .byte 0x44, 0x04, 0x00, 0x00
    .4byte __vt_15ClockTransition
    .byte 0x10, 0x20
    bl __builtin_new
    .byte 0x06, 0x1C
    .byte 0xAA, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0x24, 0x68, 0xA0, 0x46, 0x01, 0x25, 0xA9, 0x46
    .byte 0x1D, 0x48, 0x30, 0x60, 0x74, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0x1B, 0x49, 0x01, 0x60, 0x00, 0x21, 0x01, 0x71, 0x85, 0x1D, 0x8D, 0x23, 0x9B, 0x00, 0xC2, 0x88
    .byte 0x18, 0x4C, 0x21, 0x1C, 0x11, 0x40, 0x19, 0x43, 0xC1, 0x80, 0x6A, 0x78, 0x03, 0x23, 0x19, 0x1C
    .byte 0x11, 0x40, 0x69, 0x70, 0x6A, 0x88, 0x21, 0x1C, 0x11, 0x40, 0x69, 0x80, 0xE9, 0x78, 0x0B, 0x40
    .byte 0xEB, 0x70, 0xA9, 0x88, 0x0C, 0x40, 0xAC, 0x80, 0x0F, 0x49, 0x01, 0x60, 0x41, 0x46, 0xC1, 0x60
    .byte 0x4A, 0x46, 0x02, 0x61, 0xB0, 0x60, 0xF2, 0x60, 0xAC, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1C, 0x68
    .byte 0x25, 0x1C, 0x29, 0x68, 0x8E, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7, 0x38, 0xFD, 0x26, 0x60, 0x1B, 0xE1
    .4byte __vt_17TownMapTransition
    .4byte __vt_26TownMapSelectionTransition
    .byte 0x00, 0xFC, 0xFF, 0xFF
    .4byte __vt_23TownMapReturnTransition
    .byte 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x05, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x36, 0x68
    .byte 0x36, 0x68, 0xB0, 0x46, 0x89, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x31, 0x1C, 0x2C, 0xCC, 0x2C, 0xC1
    .byte 0x0F, 0x49, 0x01, 0x60, 0x41, 0x46, 0x41, 0x60, 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00
    .byte 0x69, 0x44, 0x38, 0xC9, 0x38, 0xC2, 0x0B, 0x4C, 0x6C, 0x44, 0x20, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x25, 0x68, 0x00, 0x23, 0x23, 0x60, 0x35, 0x60, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x09, 0x68, 0x0A, 0x68, 0x04, 0x49, 0x01, 0x60, 0x42, 0x60, 0x33, 0x60, 0x85, 0x60, 0xAA, 0xE0
    .byte 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0xD4, 0x52, 0x0E, 0x08, 0x87, 0x24, 0xE4, 0x00
    .byte 0x6C, 0x44, 0x06, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x25, 0xED, 0x00
    .byte 0x6D, 0x44, 0x2D, 0x68, 0x2D, 0x68, 0xA8, 0x46, 0x89, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x31, 0x1C
    .byte 0x2C, 0xCC, 0x2C, 0xC1, 0x10, 0x49, 0x01, 0x60, 0x41, 0x46, 0x41, 0x60, 0x02, 0x1C, 0x08, 0x32
    .byte 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x38, 0xC9, 0x38, 0xC2, 0x0C, 0x4C, 0x6C, 0x44, 0x20, 0x60
    .byte 0x10, 0x20
    bl __builtin_new
    .byte 0x25, 0x68, 0x00, 0x22, 0x22, 0x60, 0x35, 0x60, 0xAA, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x0B, 0x68, 0x05, 0x49, 0x01, 0x60, 0x32, 0x60, 0x45, 0x60
    .byte 0x83, 0x60, 0x02, 0x73, 0x6F, 0xE0, 0x00, 0x00, 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00
    .byte 0xF4, 0x52, 0x0E, 0x08, 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x07, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2D, 0x68, 0xA8, 0x46
    .byte 0x89, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x31, 0x1C, 0x2C, 0xCC, 0x2C, 0xC1, 0x0D, 0x49, 0x01, 0x60
    .byte 0x41, 0x46, 0x41, 0x60, 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x38, 0xC9
    .byte 0x38, 0xC2, 0x09, 0x4C, 0x6C, 0x44, 0x20, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x25, 0x68
    .byte 0x00, 0x22, 0x22, 0x60, 0x35, 0x60, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x0B, 0x68
    .byte 0x02, 0x49, 0x34, 0xE0, 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04, 0x00, 0x00, 0xE4, 0x52, 0x0E, 0x08
    .byte 0x87, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x03, 0x20, 0x20, 0x60, 0x14, 0x20
    bl __builtin_new
    .byte 0xAA, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x2D, 0x68, 0xA8, 0x46, 0x89, 0x26, 0xF6, 0x00
    .byte 0x6E, 0x44, 0x31, 0x1C, 0x2C, 0xCC, 0x2C, 0xC1, 0x1E, 0x49, 0x01, 0x60, 0x41, 0x46, 0x41, 0x60
    .byte 0x02, 0x1C, 0x08, 0x32, 0x89, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x38, 0xC9, 0x38, 0xC2, 0x1A, 0x4C
    .byte 0x6C, 0x44, 0x20, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x25, 0x68, 0x00, 0x22, 0x22, 0x60, 0x35, 0x60, 0xAA, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68
    .byte 0x0B, 0x68, 0x13, 0x49, 0x01, 0x60, 0x32, 0x60, 0x45, 0x60, 0x83, 0x60, 0xAC, 0x22, 0xD2, 0x00
    .byte 0x6A, 0x44, 0x15, 0x68, 0x04, 0x1C, 0x2B, 0x1C, 0x19, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7, 0x3E, 0xFC, 0x2C, 0x60
    .byte 0x07, 0x48, 0x68, 0x44, 0x01, 0x68, 0x00, 0x29, 0x1D, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xF9, 0xF7, 0x32, 0xFC, 0x16, 0xE0, 0x00, 0x00, 0xB4, 0x52, 0x0E, 0x08, 0x44, 0x04
    .byte 0x00, 0x00
    .4byte __vt_22RucksackMenuTransition
    .byte 0x01, 0x24, 0x9F, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2C, 0x60, 0x38, 0x68, 0x41, 0x68, 0x49, 0x69
    .byte 0xF9, 0xF7, 0x1E, 0xFC, 0x0D, 0x20, 0xAB, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x60
    .byte 0x9F, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0xF9, 0xFC
    .byte 0x38, 0x68
    bl DisableInput__14MainMenuWidget
    .byte 0x06, 0x49, 0x69, 0x44, 0x09, 0x68, 0x08, 0x68, 0x05, 0x49, 0x01, 0x22
    .byte 0x01, 0x23
    bl EndHardwareBlend
    .byte 0x09, 0x20, 0x00, 0xF0, 0xE5, 0xFC, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00
    .byte 0x89, 0x08, 0x00, 0x00, 0x11, 0x07, 0xC9, 0x0F, 0x90, 0x07, 0xC0, 0x0F
    .byte 0xC1, 0x42, 0x01, 0xD1, 0x00, 0xF0, 0xDD, 0xFC, 0x20, 0x68, 0x41, 0x68
    .byte 0x49, 0x69, 0xF9, 0xF7, 0xEF, 0xFB, 0x08, 0x20, 0x64, 0xE3, 0x54, 0x46
    .byte 0xB8, 0x34, 0x20, 0x68
    bl GetPhase__C13ControlWidget
    .byte 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0xCD, 0xFC, 0x00, 0x25, 0x21, 0x68
    .byte 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7, 0xDA, 0xFB, 0x25, 0x60, 0x0C, 0x20
    bl __builtin_new
    .byte 0x01, 0x21, 0x00, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __23MapClockStatusHudWidgetUiUiUiUi
    .byte 0x54, 0x46, 0xB4, 0x34, 0x05, 0x1C, 0x21, 0x68, 0x26, 0x1C, 0x8D, 0x42
    .byte 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xF9, 0xF7, 0xC0, 0xFB, 0x25, 0x60, 0xAA, 0x24, 0xE4, 0x00
    .byte 0x6C, 0x44, 0x24, 0x68, 0x21, 0x68, 0x21, 0x4D, 0x48, 0x19, 0x00, 0x78
    .byte 0x80, 0x07, 0x00, 0x28, 0x09, 0xDA, 0x1F, 0x4F, 0xC8, 0x19, 0x00, 0x78
    .byte 0x00, 0x28, 0x04, 0xD1, 0x30, 0x68, 0x41, 0x68, 0xC9, 0x68, 0xF9, 0xF7
    .byte 0xA8, 0xFB, 0x34, 0x68, 0x00, 0x25, 0x1A, 0x49, 0x69, 0x44, 0x09, 0x68
    .byte 0x08, 0x68, 0x01, 0x68, 0xB0, 0x31, 0x09, 0x68, 0xF9, 0xF7, 0x9D, 0xFB
    .byte 0x00, 0x06, 0x00, 0x28, 0x0B, 0xD1, 0xAA, 0x22, 0xD2, 0x00, 0x6A, 0x44
    .byte 0x12, 0x68, 0x10, 0x68, 0x41, 0x8A, 0x49, 0x05, 0x89, 0x0E, 0x01, 0x20
    .byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x01, 0x25, 0x2A, 0x1C, 0xAA, 0x23
    .byte 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68, 0x19, 0x68, 0x10, 0x31, 0x20, 0x1C
    .byte 0x08, 0x30
    bl UpdateMapClockStatusHudCalendar
    .byte 0x50, 0x46, 0xB4, 0x30
    .byte 0x00, 0x68, 0xAA, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0x21, 0x68, 0x89, 0x68, 0x08, 0x30
    bl SetMapClockStatusHudUnkSelector
    .byte 0x00, 0x20, 0xB1, 0xE2, 0x10, 0x22, 0x00, 0x00, 0xC4, 0x34, 0x00, 0x00
    .byte 0x64, 0x05, 0x00, 0x00, 0x0D, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43, 0xC9, 0x0F, 0x00, 0x29, 0x01, 0xD0, 0x00, 0xF0
    .byte 0x48, 0xFC, 0xAC, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68, 0x39, 0x60, 0x04, 0x4B
    .byte 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x60, 0x00, 0xF0, 0x2F, 0xFF, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00
    .byte 0xDC, 0x04, 0x00, 0x00, 0x30, 0x4C, 0x21, 0x68, 0x08, 0x1C, 0x08, 0x30, 0xD5, 0x25, 0xAD, 0x00
    .byte 0x49, 0x19, 0x09, 0x68, 0xC9, 0x68, 0xF9, 0xF7, 0x43, 0xFB, 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0
    .byte 0x28, 0xFC, 0x24, 0x68, 0xDE, 0x26, 0xB6, 0x00, 0xA5, 0x19, 0x00, 0x22, 0x00, 0x21, 0x28, 0x68
    .byte 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x14, 0xD0, 0xE3, 0x27, 0xBF, 0x00, 0xE0, 0x19
    .byte 0x00, 0x21, 0x00, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x0A, 0xD0, 0x9A, 0x21
    .byte 0xC9, 0x00, 0x60, 0x18, 0x00, 0x21, 0x00, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29
    .byte 0x00, 0xD0, 0x01, 0x22, 0x13, 0x1C, 0x00, 0x2B, 0x00, 0xD0, 0xC3, 0xE0, 0x00, 0x21, 0x28, 0x68
    .byte 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x2A, 0xD1, 0x2F, 0x1D, 0x69, 0x68, 0xAA, 0x68
    .byte 0x12, 0x4B, 0x6B, 0x44, 0x19, 0x60, 0x5A, 0x60, 0x0F, 0x4C, 0xA0, 0x46, 0x96, 0x23, 0xDB, 0x00
    .byte 0x6B, 0x44, 0x00, 0x28, 0x13, 0xD0, 0xC0, 0x00, 0x04, 0x30, 0x28, 0x18, 0x29, 0x1C, 0x0C, 0x31
    .byte 0x81, 0x42, 0x09, 0xD0, 0x0E, 0x1C, 0x80, 0x1B, 0xC2, 0x10, 0x00, 0x2A, 0x04, 0xDD, 0x03, 0xCE
    .byte 0x03, 0xC7, 0x01, 0x3A, 0x00, 0x2A, 0xFA, 0xDC, 0x28, 0x68, 0x01, 0x38, 0x28, 0x60, 0x96, 0x20
    .byte 0xC0, 0x00, 0x68, 0x44, 0x01, 0x4E, 0x34, 0xE0, 0x0C, 0x04, 0x00, 0x03, 0xFC, 0x04, 0x00, 0x00
    .byte 0x2C, 0x1C, 0x14, 0x34, 0x00, 0x21, 0x68, 0x69, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29
    .byte 0x32, 0xD1, 0x2F, 0x1C, 0x18, 0x37, 0xA9, 0x69, 0xEA, 0x69, 0x15, 0x4B, 0x6B, 0x44, 0x19, 0x60
    .byte 0x5A, 0x60, 0x26, 0x1C, 0x13, 0x4C, 0xA0, 0x46, 0x96, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x00, 0x28
    .byte 0x13, 0xD0, 0xC0, 0x00, 0x04, 0x30, 0x31, 0x18, 0x28, 0x1C, 0x20, 0x30, 0x88, 0x42, 0x09, 0xD0
    .byte 0x05, 0x1C, 0x48, 0x1B, 0xC2, 0x10, 0x00, 0x2A, 0x04, 0xDD, 0x03, 0xCD, 0x03, 0xC7, 0x01, 0x3A
    .byte 0x00, 0x2A, 0xFA, 0xDC, 0x30, 0x68, 0x01, 0x38, 0x30, 0x60, 0x96, 0x20, 0xC0, 0x00, 0x68, 0x44
    .byte 0x03, 0x4E, 0x6E, 0x44, 0x35, 0x68, 0x76, 0x68, 0x05, 0x60, 0x46, 0x60, 0x4D, 0xE0, 0x00, 0x00
    .byte 0x04, 0x05, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0xAC, 0x27, 0x7F, 0x00, 0xEE, 0x19, 0x00, 0x21
    .byte 0x30, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x33, 0xD1, 0xAE, 0x21, 0x49, 0x00
    .byte 0x6C, 0x18, 0x21, 0x68, 0x62, 0x68, 0x15, 0x4B, 0x6B, 0x44, 0x19, 0x60, 0x5A, 0x60, 0x14, 0x4F
    .byte 0xB8, 0x46, 0x96, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x00, 0x28, 0x15, 0xD0, 0xC0, 0x00, 0x04, 0x30
    .byte 0x31, 0x18, 0xB2, 0x22, 0x52, 0x00, 0xA8, 0x18, 0x88, 0x42, 0x0A, 0xD0, 0x05, 0x1C, 0x27, 0x1C
    .byte 0x48, 0x1B, 0xC2, 0x10, 0x00, 0x2A, 0x04, 0xDD, 0x03, 0xCD, 0x03, 0xC7, 0x01, 0x3A, 0x00, 0x2A
    .byte 0xFA, 0xDC, 0x30, 0x68, 0x01, 0x38, 0x30, 0x60, 0x96, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x03, 0x4D
    .byte 0x6D, 0x44, 0x2C, 0x68, 0x6D, 0x68, 0x04, 0x60, 0x45, 0x60, 0x0E, 0xE0, 0x0C, 0x05, 0x00, 0x00
    .byte 0x0C, 0x04, 0x00, 0x03, 0x96, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x96, 0x20, 0xC0, 0x00, 0x68, 0x44
    .byte 0x03, 0x60, 0x4B, 0x60, 0x06, 0x4E, 0xB0, 0x46, 0x0B, 0x1C, 0x47, 0x46, 0x38, 0x68, 0x08, 0x30
    .byte 0x96, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x5A, 0x68, 0x65, 0xF7, 0x6B, 0xFC, 0x40, 0xE3
    .byte 0x0C, 0x04, 0x00, 0x03, 0x54, 0x46, 0xAC, 0x34, 0x20, 0x68, 0x00, 0x28, 0x06, 0xD0, 0x00, 0x25
    .byte 0x85, 0x42, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0x54, 0x46, 0xF0, 0x34
    .byte 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x01, 0xD0
    bl __builtin_delete
    .byte 0x25, 0x60, 0x39, 0x49
    .byte 0x69, 0x44, 0x09, 0x68, 0x08, 0x68, 0x01, 0x68, 0x94, 0x22, 0x52, 0x00, 0x89, 0x18, 0x09, 0x68
    .byte 0xF9, 0xF7, 0x36, 0xFA, 0x50, 0x46, 0xB4, 0x30, 0x01, 0x68, 0x06, 0x1C, 0x00, 0x29, 0x17, 0xD1
    .byte 0x0C, 0x20
    bl __builtin_new
    .byte 0x01, 0x21, 0x00, 0x91, 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __23MapClockStatusHudWidgetUiUiUiUi
    .byte 0x35, 0x1C, 0x04, 0x1C, 0x31, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF9, 0xF7
    .byte 0x1B, 0xFA, 0x2C, 0x60, 0xAA, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68
    .byte 0x19, 0x68, 0x23, 0x4C, 0x08, 0x19, 0x00, 0x78, 0x80, 0x07, 0x00, 0x28
    .byte 0x09, 0xDA, 0x21, 0x4D, 0x48, 0x19, 0x00, 0x78, 0x00, 0x28, 0x04, 0xD1
    .byte 0x30, 0x68, 0x41, 0x68, 0x09, 0x69, 0xF9, 0xF7, 0x03, 0xFA, 0x34, 0x68
    .byte 0x00, 0x25, 0x19, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x68, 0x01, 0x68
    .byte 0xB0, 0x31, 0x09, 0x68, 0xF9, 0xF7, 0xF8, 0xF9, 0x00, 0x06, 0x00, 0x28
    .byte 0x0B, 0xD1, 0xAA, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68
    .byte 0x41, 0x8A, 0x49, 0x05, 0x89, 0x0E, 0x01, 0x20, 0x08, 0x40, 0x00, 0x28
    .byte 0x00, 0xD0, 0x01, 0x25, 0x2A, 0x1C, 0xAA, 0x20, 0xC0, 0x00, 0x68, 0x44
    .byte 0x00, 0x68, 0x01, 0x68, 0x10, 0x31, 0x20, 0x1C, 0x08, 0x30
    bl UpdateMapClockStatusHudCalendar
    .byte 0x50, 0x46, 0xB4, 0x30, 0x00, 0x68, 0xAA, 0x22, 0xD2, 0x00
    .byte 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x89, 0x68, 0x08, 0x30
    bl SetMapClockStatusHudUnkSelector
    .byte 0x00, 0x20
    .byte 0x46, 0xE1, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x10, 0x22, 0x00, 0x00, 0xC4, 0x34, 0x00, 0x00
    .byte 0x50, 0x46, 0xAC, 0x30, 0x00, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x00, 0xD0, 0xA8, 0xE2
    .byte 0xE9, 0xE0, 0x54, 0x46, 0xAC, 0x34, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x00, 0x28, 0x00, 0xD0
    .byte 0x9F, 0xE2, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0xE8, 0xE0, 0x50, 0x46, 0xAC, 0x30, 0x00, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x00, 0xD0, 0x8C, 0xE2, 0x5C, 0xE2, 0x04, 0xA8, 0x04, 0x89, 0x50, 0x46
    .byte 0xAC, 0x30, 0x00, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x06, 0x28, 0x00, 0xD9, 0x81, 0xE2, 0x80, 0x00
    .byte 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0xA4, 0x9D, 0x0D, 0x08, 0xC0, 0x9D, 0x0D, 0x08
    .byte 0xC0, 0x9D, 0x0D, 0x08, 0xC0, 0x9D, 0x0D, 0x08, 0xC0, 0x9D, 0x0D, 0x08, 0xE0, 0x9D, 0x0D, 0x08
    .byte 0xE0, 0x9D, 0x0D, 0x08, 0xC0, 0x9D, 0x0D, 0x08, 0x02, 0x20, 0xAB, 0x27, 0xFF, 0x00, 0x6F, 0x44
    .byte 0x3F, 0x68, 0x38, 0x60, 0x03, 0x48, 0x00, 0x68, 0x08, 0x30, 0x04, 0x21, 0x65, 0xF7, 0xAA, 0xFB
    .byte 0x5F, 0xE2, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0x02, 0x21, 0x20, 0x1C, 0x08, 0x40, 0x00, 0x28
    .byte 0x0E, 0xD0, 0xAB, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x00, 0x68, 0x01, 0x60, 0x03, 0x48, 0x00, 0x68
    .byte 0x08, 0x30, 0x05, 0x21, 0x65, 0xF7, 0x96, 0xFB, 0x4B, 0xE2, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0x40, 0x20, 0x20, 0x40, 0x00, 0x28, 0x0D, 0xD0, 0xAB, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68
    .byte 0x11, 0x60, 0x03, 0x48, 0x00, 0x68, 0x08, 0x30, 0x00, 0x21, 0x65, 0xF7, 0x83, 0xFB, 0x38, 0xE2
    .byte 0x0C, 0x04, 0x00, 0x03, 0x80, 0x20, 0x20, 0x40, 0x00, 0x28, 0x0D, 0xD0, 0xAB, 0x23, 0xDB, 0x00
    .byte 0x6B, 0x44, 0x1B, 0x68, 0x19, 0x60, 0x03, 0x48, 0x00, 0x68, 0x08, 0x30, 0x01, 0x21, 0x65, 0xF7
    .byte 0x71, 0xFB, 0x26, 0xE2, 0x0C, 0x04, 0x00, 0x03, 0x20, 0x20, 0x20, 0x40, 0x00, 0x28, 0x0D, 0xD0
    .byte 0xAB, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0x21, 0x60, 0x03, 0x48, 0x00, 0x68, 0x08, 0x30
    .byte 0x02, 0x21, 0x65, 0xF7, 0x5F, 0xFB, 0x14, 0xE2, 0x0C, 0x04, 0x00, 0x03, 0x10, 0x20, 0x04, 0x40
    .byte 0x00, 0x2C, 0x00, 0xD1, 0x0D, 0xE2, 0xAB, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0x29, 0x60
    .byte 0x03, 0x48, 0x00, 0x68, 0x08, 0x30, 0x03, 0x21, 0x65, 0xF7, 0x4C, 0xFB, 0x01, 0xE2, 0x00, 0x00
    .byte 0x0C, 0x04, 0x00, 0x03, 0x10, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43, 0xCB, 0x0F, 0x00, 0x2B, 0x00, 0xD0, 0xF0, 0xE1
    .byte 0x51, 0x46, 0xE8, 0x31, 0x01, 0x20, 0x08, 0x70, 0x57, 0x46, 0x39, 0x8A, 0x07, 0x48, 0x08, 0x40
    .byte 0x38, 0x82, 0x52, 0x46, 0x60, 0x32, 0x11, 0x88, 0x05, 0x48, 0x08, 0x40, 0x10, 0x80, 0x50, 0x46
    .byte 0x5C, 0x30, 0x03, 0x80, 0xC6, 0xE1, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00
    .byte 0x3F, 0xFF, 0x00, 0x00, 0x06, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43, 0x00, 0x29, 0x00, 0xDA, 0xC9, 0xE1, 0x56, 0xE0
    .byte 0x5C, 0x05, 0x00, 0x00, 0x51, 0x46, 0xE0, 0x31, 0x08, 0x88, 0x01, 0x38, 0x08, 0x80, 0x00, 0x04
    .byte 0x00, 0x28, 0x00, 0xD0, 0xBD, 0xE1, 0x02, 0x20, 0xAB, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68
    .byte 0x20, 0x60, 0xB6, 0xE1, 0x54, 0x46, 0xE4, 0x34, 0x20, 0x68
    bl IsActorAxisMotionComplete
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x00, 0xD1, 0xAD, 0xE1, 0x00, 0x20, 0x20, 0x60, 0x02, 0x20, 0xAB, 0x25, 0xED, 0x00
    .byte 0x6D, 0x44, 0x2D, 0x68, 0x28, 0x60, 0xA4, 0xE1, 0x55, 0x46, 0xAC, 0x35, 0x28, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x06, 0x28, 0x00, 0xD1, 0x9C, 0xE1, 0x05, 0x48, 0x04, 0x68, 0x08, 0x34, 0x28, 0x68
    bl GetChoiceResult__C12UiStateOwner
    .byte 0x01, 0x1C, 0x20, 0x1C, 0x65, 0xF7, 0xDC, 0xFA, 0x62, 0xE1, 0x00, 0x00
    .byte 0x0C, 0x04, 0x00, 0x03, 0x04, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68, 0x01, 0x68, 0x89, 0x6A
    .byte 0xF9, 0xF7, 0x9E, 0xF8, 0x6B, 0xE1, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x0B, 0x4A, 0x6A, 0x44
    .byte 0x12, 0x68, 0x10, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x00, 0x21, 0xF9, 0xF7, 0x93, 0xF8, 0x41, 0x69
    .byte 0xC9, 0x6B, 0xF9, 0xF7, 0x8D, 0xF8, 0x00, 0x06, 0x00, 0x28, 0x00, 0xD0, 0x71, 0xE1, 0x02, 0x20
    .byte 0xAB, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x60, 0x6A, 0xE1, 0x64, 0x05, 0x00, 0x00
    .byte 0x50, 0x46, 0xEF, 0x30, 0x01, 0x78, 0xAF, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x20, 0x60, 0x78, 0x29
    .byte 0x20, 0xD1, 0x05, 0x38, 0x00, 0x23, 0x03, 0x70, 0x55, 0x46, 0x29, 0x8A, 0x0C, 0x48, 0x08, 0x40
    .byte 0x28, 0x82, 0x87, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x3F, 0x20, 0x10, 0x80, 0x51, 0x46, 0x60, 0x31
    .byte 0x87, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x30, 0x88, 0x08, 0x80, 0x13, 0x80, 0x02, 0x31, 0x30, 0x88
    .byte 0x08, 0x80, 0x02, 0x20, 0xAB, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x60, 0x40, 0xE1
    .byte 0xFF, 0xFE, 0x00, 0x00, 0x50, 0x46, 0xEC, 0x30, 0x01, 0x88, 0xD0, 0x46, 0x87, 0x20, 0xC0, 0x00
    .byte 0x68, 0x44, 0x13, 0x4A, 0x02, 0x23
    bl __21DmaTransferDescriptorUiPvUi
    .byte 0x87, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x10, 0x49, 0x69, 0x44, 0x08, 0x60, 0x52, 0x46, 0x51, 0x68
    .byte 0xD0, 0x68, 0x81, 0x42, 0x1B, 0xD0, 0x00, 0x29, 0x07, 0xD0, 0x08, 0x1C, 0x87, 0x21, 0xC9, 0x00
    .byte 0x69, 0x44, 0x38, 0xC9, 0x38, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x56, 0x46, 0x70, 0x68, 0x10, 0x30
    .byte 0x70, 0x60, 0x62, 0x36, 0xA9, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3E, 0x60, 0xEE, 0x20, 0x50, 0x44
    .byte 0x81, 0x46, 0x9D, 0xE0, 0x00, 0x00, 0x02, 0x00, 0x00, 0x05, 0x14, 0x05, 0x00, 0x00, 0x15, 0x4A
    .byte 0x6A, 0x44, 0x11, 0x60, 0x01, 0x20, 0x14, 0x49, 0x69, 0x44, 0x08, 0x60, 0x53, 0x46, 0x18, 0x68
    .byte 0x14, 0x68, 0x20, 0x1A, 0x04, 0x11, 0x97, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x04, 0x60, 0x0E, 0x4A
    .byte 0x6A, 0x44, 0x08, 0x68, 0x97, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x84, 0x42, 0x00, 0xD2, 0x11, 0x1C
    .byte 0x08, 0x68, 0x20, 0x18, 0x00, 0x28, 0x12, 0xD0, 0x04, 0x01, 0x20, 0x1C, 0xF5, 0xF7, 0xDD, 0xFC
    .byte 0xB1, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2C, 0x60, 0x00, 0x28, 0x0D, 0xD1, 0x20, 0x1C, 0xF9, 0xF7
    .byte 0x52, 0xF9, 0x09, 0xE0, 0x00, 0x00, 0x84, 0x05, 0x00, 0x00, 0xBC, 0x04, 0x00, 0x00, 0x00, 0x20
    .byte 0xB1, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x30, 0x60, 0x05, 0x1C, 0x2C, 0x1C, 0x47, 0x46, 0x3A, 0x68
    .byte 0x23, 0x1C, 0x50, 0x46, 0x62, 0x30, 0xA9, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x08, 0x60, 0xEE, 0x25
    .byte 0x55, 0x44, 0xA9, 0x46, 0x13, 0x4E, 0x6E, 0x44, 0x36, 0x68, 0xB2, 0x42, 0x0E, 0xD0, 0x00, 0x2B
    .byte 0x05, 0xD0, 0x18, 0x1C, 0x11, 0x1C, 0xE0, 0xC9, 0xE0, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x10, 0x32
    .byte 0x10, 0x33, 0x0B, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0xBA, 0x42, 0xF0, 0xD1, 0x1D, 0x1C, 0x09, 0x48
    .byte 0x68, 0x44, 0x00, 0x68, 0x01, 0x28, 0x12, 0xD1, 0x00, 0x2D, 0x07, 0xD0, 0x28, 0x1C, 0x06, 0x4A
    .byte 0x6A, 0x44, 0x11, 0x68, 0xC8, 0xC9, 0xC8, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x10, 0x35, 0x19, 0xE0
    .byte 0x00, 0x00, 0x84, 0x05, 0x00, 0x00, 0xBC, 0x04, 0x00, 0x00, 0x14, 0x05, 0x00, 0x00, 0x03, 0x1C
    .byte 0x2A, 0x1C, 0x00, 0x2B, 0x0D, 0xD0, 0x00, 0x2A, 0x07, 0xD0, 0x10, 0x1C, 0x23, 0x4D, 0x6D, 0x44
    .byte 0x29, 0x68, 0xE0, 0xC9, 0xE0, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x01, 0x3B, 0x10, 0x32, 0x00, 0x2B
    .byte 0xF1, 0xD1, 0x15, 0x1C, 0x46, 0x46, 0x72, 0x68, 0x30, 0x68, 0x01, 0x1C, 0x90, 0x42, 0x02, 0xD0
    .byte 0x10, 0x31, 0x91, 0x42, 0xFC, 0xD1, 0x00, 0x28, 0x01, 0xD0, 0xF5, 0xF7, 0xA2, 0xFC, 0xB1, 0x27
    .byte 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x19, 0x41, 0x46, 0x0C, 0x60, 0x4D, 0x60, 0xC8, 0x60
    .byte 0x13, 0x49, 0xAF, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x78, 0x40, 0x18, 0x00, 0x78
    .byte 0x4B, 0x46, 0x18, 0x70, 0x87, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x18, 0x78, 0x80, 0x24, 0x64, 0x01
    .byte 0x21, 0x1C, 0x40, 0x18, 0x10, 0x80, 0x87, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x28, 0x88, 0xA9, 0x26
    .byte 0xF6, 0x00, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x80, 0xAF, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68
    .byte 0x38, 0x78, 0x01, 0x30, 0x38, 0x70, 0x4F, 0xE0, 0x00, 0x00, 0x14, 0x05, 0x00, 0x00
    .4byte gScreenFlashBlendStrengths
    .byte 0xAC, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x00, 0x20, 0x10, 0x60, 0x02, 0x4C
    .byte 0x6C, 0x44, 0x24, 0x68, 0x21, 0x60, 0x31, 0xE3, 0xDC, 0x04, 0x00, 0x00, 0x0A, 0x4D, 0x6D, 0x44
    .byte 0x2D, 0x68, 0x28, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5D, 0x21, 0xF8, 0xF7, 0x4D, 0xFF
    bl HasEntityStarSparkleEffect
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x2E, 0xD1, 0x02, 0x20, 0xAB, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0x36, 0x68, 0x30, 0x60
    .byte 0x27, 0xE0, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x0A, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68
    .byte 0x01, 0x68, 0x0A, 0x6C, 0x5D, 0x21, 0xF8, 0xF7, 0x35, 0xFF
    bl IsEntityNewYearSunriseEffectComplete
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x16, 0xD0, 0x02, 0x20, 0xAB, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x09, 0x68, 0x08, 0x60
    .byte 0x0F, 0xE0, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x50, 0x46, 0xBC, 0x30
    bl IsActive__C23HardwareMusicPlayerSlot
    .byte 0x00, 0x06, 0x00, 0x28, 0x05, 0xD1, 0x02, 0x20, 0xAB, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68
    .byte 0x10, 0x60
    .Lauto_080DA29A:
    .byte 0x26, 0x4B, 0x6B, 0x44, 0x1B, 0x68, 0x00, 0x2B, 0x0F, 0xD1, 0x98, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x98, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x04, 0xAC, 0x04, 0x60, 0x20, 0x4D, 0x6D, 0x44, 0x2D, 0x68
    .byte 0x28, 0x68, 0x02, 0x68, 0xD2, 0x68, 0xF8, 0xF7, 0x04, 0xFF, 0x50, 0x46, 0xE8, 0x30, 0x00, 0x78
    .byte 0x00, 0x28, 0x00, 0xD1, 0xD1, 0xE0, 0x50, 0x46, 0xE9, 0x30, 0x00, 0x78, 0x19, 0x49, 0x00, 0x28
    .byte 0x00, 0xD0, 0x00, 0x21, 0xD0, 0x46, 0x87, 0x20, 0xC0, 0x00, 0x68, 0x44, 0xA0, 0x22, 0xD2, 0x04
    .byte 0x02, 0x23
    bl __21DmaTransferDescriptorUiPvUi
    .byte 0x87, 0x26, 0xF6, 0x00, 0x6E, 0x44, 0xA3, 0x27, 0xFF, 0x00
    .byte 0x6F, 0x44, 0x3E, 0x60, 0x50, 0x46, 0x41, 0x68, 0xC0, 0x68, 0x81, 0x42, 0x1D, 0xD0, 0x00, 0x29
    .byte 0x08, 0xD0, 0x08, 0x1C, 0xA3, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x11, 0x68, 0x38, 0xC9, 0x38, 0xC0
    .byte 0x09, 0x68, 0x01, 0x60, 0x56, 0x46, 0x70, 0x68, 0x10, 0x30, 0x70, 0x60, 0xB4, 0x36, 0x57, 0x46
    .byte 0xEA, 0x37, 0x04, 0x48, 0x68, 0x44, 0x07, 0x60, 0xBB, 0xE0, 0xF4, 0x04, 0x00, 0x00, 0x64, 0x05
    .byte 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x74, 0x05, 0x00, 0x00, 0xB1, 0x22, 0xD2, 0x00, 0x6A, 0x44
    .byte 0x11, 0x60, 0x01, 0x20, 0x99, 0x21, 0xC9, 0x00, 0x69, 0x44, 0x08, 0x60, 0x53, 0x46, 0x18, 0x68
    .byte 0x14, 0x68, 0x20, 0x1A, 0x04, 0x11, 0x0D, 0x48, 0x68, 0x44, 0x04, 0x60, 0x99, 0x22, 0xD2, 0x00
    .byte 0x6A, 0x44, 0x08, 0x68, 0x0A, 0x49, 0x69, 0x44, 0x84, 0x42, 0x00, 0xD2, 0x11, 0x1C, 0x08, 0x68
    .byte 0x20, 0x18, 0x00, 0x28, 0x0D, 0xD0, 0x04, 0x01, 0x20, 0x1C, 0xF5, 0xF7, 0x7A, 0xFB, 0xA1, 0x46
    .byte 0x00, 0x28, 0x08, 0xD1, 0x48, 0x46, 0xF8, 0xF7, 0xF2, 0xFF, 0x04, 0xE0, 0x00, 0x00, 0xC4, 0x04
    .byte 0x00, 0x00, 0x00, 0x20, 0x81, 0x46, 0x05, 0x1C, 0x1B, 0x4E, 0x6E, 0x44, 0x35, 0x60, 0x47, 0x46
    .byte 0x3A, 0x68, 0x2B, 0x1C, 0x56, 0x46, 0xB4, 0x36, 0x50, 0x46, 0xEA, 0x30, 0x17, 0x49, 0x69, 0x44
    .byte 0x08, 0x60, 0xB1, 0x24, 0xE4, 0x00, 0x6C, 0x44, 0x24, 0x68, 0xA2, 0x42, 0x0F, 0xD0, 0x00, 0x2B
    .byte 0x05, 0xD0, 0x18, 0x1C, 0x11, 0x1C, 0xB0, 0xC9, 0xB0, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x10, 0x32
    .byte 0x10, 0x33, 0xB1, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2D, 0x68, 0xAA, 0x42, 0xEF, 0xD1, 0x1D, 0x1C
    .byte 0x99, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x00, 0x68, 0x01, 0x28, 0x10, 0xD1, 0x00, 0x2D, 0x08, 0xD0
    .byte 0x28, 0x1C, 0xA3, 0x27, 0xFF, 0x00, 0x6F, 0x44, 0x39, 0x68, 0x1C, 0xC9, 0x1C, 0xC0, 0x09, 0x68
    .byte 0x01, 0x60, 0x10, 0x35, 0x17, 0xE0, 0x8C, 0x05, 0x00, 0x00, 0x74, 0x05, 0x00, 0x00, 0x03, 0x1C
    .byte 0x2A, 0x1C, 0x00, 0x2B, 0x0E, 0xD0, 0x00, 0x2A, 0x08, 0xD0, 0x10, 0x1C, 0xA3, 0x25, 0xED, 0x00
    .byte 0x6D, 0x44, 0x29, 0x68, 0xB0, 0xC9, 0xB0, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x01, 0x3B, 0x10, 0x32
    .byte 0x00, 0x2B, 0xF0, 0xD1, 0x15, 0x1C, 0x47, 0x46, 0x7A, 0x68, 0x38, 0x68, 0x01, 0x1C, 0x90, 0x42
    .byte 0x02, 0xD0, 0x10, 0x31, 0x91, 0x42, 0xFC, 0xD1, 0x00, 0x28, 0x01, 0xD0, 0xF5, 0xF7, 0x45, 0xFB
    .byte 0x05, 0x49, 0x69, 0x44, 0x08, 0x68, 0x48, 0x44, 0x0A, 0x68, 0x43, 0x46, 0x1A, 0x60, 0x5D, 0x60
    .byte 0xD8, 0x60, 0x1E, 0xE0, 0x00, 0x00, 0x8C, 0x05, 0x00, 0x00, 0x50, 0x46, 0x6C, 0x30, 0x87, 0x21
    .byte 0xC9, 0x00, 0x69, 0x44, 0x54, 0x46, 0x0C, 0x60, 0x5B, 0x4D, 0x6D, 0x44, 0x2D, 0x68, 0x4D, 0x60
    .byte 0x0D, 0xAE, 0x8E, 0x60, 0xC8, 0x60, 0x58, 0x4F, 0x6F, 0x44, 0x3F, 0x68, 0x38, 0x68, 0x02, 0x68
    .byte 0x12, 0x69, 0xF8, 0xF7, 0x16, 0xFE, 0x56, 0x46, 0xB4, 0x36, 0xEA, 0x34, 0x54, 0x48, 0x68, 0x44
    .byte 0x04, 0x60, 0x31, 0x68, 0x88, 0x46, 0x00, 0x29, 0x00, 0xD1, 0xC6, 0xE0, 0xAA, 0x22, 0xD2, 0x00
    .byte 0x6A, 0x44, 0x12, 0x68, 0x15, 0x68, 0x10, 0x23, 0x5B, 0x19, 0x99, 0x46, 0x4D, 0x4F, 0x6F, 0x44
    .byte 0x38, 0x68, 0x40, 0x01, 0x29, 0x69, 0x4C, 0x01, 0x80, 0x0E, 0xA1, 0x0E, 0x88, 0x42, 0x6D, 0xD0
    .byte 0x08, 0x1C, 0x0A, 0x21, 0xF6, 0xF7, 0x12, 0xF9, 0x00, 0x06, 0x00, 0x28, 0x5C, 0xD1, 0xA0, 0x0E
    .byte 0x0A, 0x21, 0xF6, 0xF7, 0xD1, 0xF8, 0x00, 0x06, 0x00, 0x0E, 0x81, 0x00, 0x09, 0x18, 0x49, 0x00
    .byte 0x40, 0x46, 0x08, 0x30
    bl SetMapClockStatusHudMinuteDigits
    .byte 0x39, 0x68, 0xC9, 0x02, 0x28, 0x69, 0xC2, 0x02
    .byte 0xC9, 0x0E, 0xD0, 0x0E, 0x81, 0x42, 0x47, 0xD0, 0x30, 0x68, 0xD1, 0x0E, 0x08, 0x30
    bl SetMapClockStatusHudHour
    .byte 0x37, 0x4F, 0x6F, 0x44, 0x79, 0x78, 0x49, 0x06, 0xC9, 0x0E, 0x01, 0x31, 0x6B, 0x7C
    .byte 0x58, 0x06, 0xC0, 0x0E, 0x44, 0x1C, 0xA1, 0x42, 0x36, 0xD0, 0x30, 0x68, 0x80, 0x46, 0x2A, 0x7C
    .byte 0x52, 0x07, 0x52, 0x0F, 0x98, 0x07, 0x80, 0x0F, 0x06, 0x32, 0x01, 0x01, 0x09, 0x1A, 0x49, 0x00
    .byte 0x10, 0x01, 0x80, 0x1A, 0xC0, 0x00, 0x09, 0x18, 0x09, 0x19, 0x01, 0x39, 0x06, 0x29, 0x04, 0xD9
    .byte 0x08, 0x1C, 0x07, 0x21, 0xF6, 0xF7, 0xD2, 0xF8, 0x01, 0x1C, 0x07, 0x20, 0x01, 0x40, 0x08, 0x22
    .byte 0x52, 0x42, 0x24, 0x4B, 0x6B, 0x44, 0x1B, 0x78, 0x1A, 0x40, 0x0A, 0x43, 0x22, 0x48, 0x68, 0x44
    .byte 0x02, 0x70, 0x52, 0x07, 0x52, 0x0F, 0x40, 0x46, 0x08, 0x30, 0x21, 0x1C
    bl SetMapClockStatusHudDayAndWeekday
    .byte 0x79, 0x78, 0x89, 0x07, 0x68, 0x7C, 0x80, 0x07, 0x82, 0x0F, 0x81, 0x42, 0x04, 0xD0, 0x30, 0x68
    .byte 0x08, 0x30, 0x11, 0x1C
    bl SetMapClockStatusHudSeason
    .byte 0x30, 0x68, 0x49, 0x46, 0x0A, 0x68, 0x52, 0x01
    .byte 0x92, 0x0E, 0x01, 0x21, 0x11, 0x40, 0x08, 0x30
    bl SetMapClockStatusHudColonVisible
    .byte 0x30, 0x68, 0xAA, 0x22
    .byte 0xD2, 0x00, 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x89, 0x68, 0x08, 0x30
    bl SetMapClockStatusHudUnkSelector
    .byte 0xAA, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x68, 0x0B, 0x4C, 0x05, 0x19, 0x28, 0x1C
    .byte 0x33, 0xF7, 0x1B, 0xFB, 0x00, 0x06, 0x00, 0x28, 0x11, 0xD0, 0x30, 0x68, 0x08, 0x30
    bl ClearMapClockStatusHudUnkValue
    .byte 0x2A, 0xE0, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x74, 0x05
    .byte 0x00, 0x00, 0xCC, 0x04, 0x00, 0x00, 0x1C, 0x05, 0x00, 0x00, 0x34, 0x1C, 0x00, 0x00, 0xAA, 0x27
    .byte 0xFF, 0x00, 0x6F, 0x44, 0x3F, 0x68, 0x3C, 0x68, 0x51, 0x48, 0x24, 0x18, 0x28, 0x1C, 0x33, 0xF7
    .byte 0xEA, 0xFA, 0x01, 0x1C, 0x20, 0x1C
    bl GetUpgradedTool__C6FarmerG4Tool
    .byte 0x9A, 0x21, 0xC9, 0x00, 0x69, 0x44
    .byte 0x08, 0x70, 0x9A, 0x20, 0xC0, 0x00, 0x68, 0x44, 0x33, 0xF7, 0x85, 0xFA, 0x01, 0x1C, 0x09, 0x04
    .byte 0x09, 0x0C, 0x30, 0x68, 0x08, 0x30
    bl SetMapClockStatusHudUnkValue
    .byte 0x45, 0x49, 0x69, 0x44, 0x09, 0x68
    .byte 0x08, 0x78, 0x00, 0x28, 0x05, 0xD1, 0x43, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x68
    bl Update__23HardwareBlendController
    .byte 0xAB, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x1B, 0x68, 0x18, 0x68, 0x00, 0x28, 0x00, 0xD0
    .byte 0x01, 0xE1, 0x3D, 0x48, 0x01, 0x68, 0xDE, 0x25, 0xAD, 0x00, 0x4C, 0x19, 0x00, 0x23, 0x00, 0x22
    .byte 0x20, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x22, 0x00, 0x2A, 0x14, 0xD0, 0xE3, 0x26, 0xB6, 0x00
    .byte 0x88, 0x19, 0x00, 0x22, 0x00, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x22, 0x00, 0x2A, 0x0A, 0xD0
    .byte 0x9A, 0x27, 0xFF, 0x00, 0xC8, 0x19, 0x00, 0x21, 0x00, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21
    .byte 0x00, 0x29, 0x00, 0xD0, 0x01, 0x23, 0x00, 0x2B, 0x00, 0xD0, 0xDC, 0xE0, 0x2A, 0x49, 0x69, 0x44
    .byte 0x09, 0x68, 0x08, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43
    .byte 0xCD, 0x0F, 0x00, 0x2D, 0x00, 0xD0, 0xCE, 0xE0, 0x25, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x10, 0x68
    .byte 0x01, 0x68, 0x0A, 0x6C, 0x00, 0x21, 0xF8, 0xF7, 0xF4, 0xFC, 0x02, 0x1C, 0x00, 0x2A, 0x09, 0xD0
    .byte 0x50, 0x69, 0x98, 0x30, 0x01, 0x68, 0x10, 0x1C, 0xF8, 0xF7, 0xE9, 0xFC, 0x00, 0x06, 0x00, 0x28
    .byte 0x00, 0xD0, 0xB8, 0xE0, 0x00, 0x21, 0x20, 0x68, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29
    .byte 0x31, 0xD1, 0x26, 0x1D, 0x61, 0x68, 0xA2, 0x68, 0xA4, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x19, 0x60
    .byte 0x5A, 0x60, 0x13, 0x4B, 0x6B, 0x44, 0x00, 0x28, 0x13, 0xD0, 0xC0, 0x00, 0x04, 0x30, 0x20, 0x18
    .byte 0x21, 0x1C, 0x0C, 0x31, 0x81, 0x42, 0x09, 0xD0, 0x0D, 0x1C, 0x40, 0x1B, 0xC2, 0x10, 0x00, 0x2A
    .byte 0x04, 0xDD, 0x03, 0xCD, 0x03, 0xC6, 0x01, 0x3A, 0x00, 0x2A, 0xFA, 0xDC, 0x20, 0x68, 0x01, 0x38
    .byte 0x20, 0x60, 0x07, 0x48, 0x68, 0x44, 0xA4, 0x25, 0xED, 0x00, 0x3B, 0xE0, 0x00, 0x00, 0xD8, 0x1B
    .byte 0x00, 0x00, 0x74, 0x05, 0x00, 0x00, 0x5C, 0x05, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03, 0x64, 0x05
    .byte 0x00, 0x00, 0xD4, 0x04, 0x00, 0x00, 0x27, 0x1C, 0x14, 0x37, 0x00, 0x21, 0x60, 0x69, 0x00, 0x28
    .byte 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x2E, 0xD1, 0x26, 0x1C, 0x18, 0x36, 0xA1, 0x69, 0xE2, 0x69
    .byte 0xA5, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x19, 0x60, 0x5A, 0x60, 0x3D, 0x1C, 0x11, 0x4B, 0x6B, 0x44
    .byte 0x00, 0x28, 0x13, 0xD0, 0xC0, 0x00, 0x04, 0x30, 0x29, 0x18, 0x20, 0x1C, 0x20, 0x30, 0x88, 0x42
    .byte 0x09, 0xD0, 0x04, 0x1C, 0x08, 0x1B, 0xC2, 0x10, 0x00, 0x2A, 0x04, 0xDD, 0x03, 0xCC, 0x03, 0xC6
    .byte 0x01, 0x3A, 0x00, 0x2A, 0xFA, 0xDC, 0x28, 0x68, 0x01, 0x38, 0x28, 0x60, 0x05, 0x48, 0x68, 0x44
    .byte 0xA5, 0x25, 0xED, 0x00, 0x6D, 0x44, 0x2C, 0x68, 0x6D, 0x68, 0x04, 0x60, 0x45, 0x60, 0x43, 0xE0
    .byte 0x00, 0x00, 0xD4, 0x04, 0x00, 0x00, 0xAC, 0x26, 0x76, 0x00, 0xA7, 0x19, 0x00, 0x21, 0x38, 0x68
    .byte 0x00, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x2F, 0xD1, 0xAE, 0x21, 0x49, 0x00, 0x66, 0x18
    .byte 0x31, 0x68, 0x72, 0x68, 0xA6, 0x23, 0xDB, 0x00, 0x6B, 0x44, 0x19, 0x60, 0x5A, 0x60, 0x3D, 0x1C
    .byte 0x11, 0x4B, 0x6B, 0x44, 0x00, 0x28, 0x14, 0xD0, 0xC0, 0x00, 0x04, 0x30, 0x29, 0x18, 0xB2, 0x27
    .byte 0x7F, 0x00, 0xE0, 0x19, 0x88, 0x42, 0x09, 0xD0, 0x04, 0x1C, 0x08, 0x1B, 0xC2, 0x10, 0x00, 0x2A
    .byte 0x04, 0xDD, 0x03, 0xCC, 0x03, 0xC6, 0x01, 0x3A, 0x00, 0x2A, 0xFA, 0xDC, 0x28, 0x68, 0x01, 0x38
    .byte 0x28, 0x60, 0x04, 0x48, 0x68, 0x44, 0xA6, 0x22, 0xD2, 0x00, 0x6A, 0x44, 0x11, 0x68, 0x52, 0x68
    .byte 0x01, 0x60, 0x42, 0x60, 0x08, 0xE0, 0xD4, 0x04, 0x00, 0x00, 0x09, 0x49, 0x69, 0x44, 0x08, 0x48
    .byte 0x68, 0x44, 0x05, 0x60, 0x4D, 0x60, 0x0B, 0x1C, 0x06, 0x48, 0x68, 0x44, 0x01, 0x68, 0x5A, 0x68
    .byte 0x50, 0x46, 0x01, 0xF0, 0xEC, 0xF8, 0x50, 0x46, 0x0D, 0xA9
    bl UpdateGameSceneHardwareFrame
    .byte 0xFD, 0xF7
    .byte 0x90, 0xFF, 0xD4, 0x04, 0x00, 0x00, 0x06, 0x4B, 0x6B, 0x44, 0x18, 0x68, 0xB2, 0x23, 0xDB, 0x00
    .byte 0x9D, 0x44, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
    .byte 0x00, 0x00, 0xDC, 0x04, 0x00, 0x00

    .section .text.scene_calendar_after, "ax", %progbits

    .section .text.scene_tool_chest_after, "ax", %progbits

    .section .text.scene_refrigerator_after, "ax", %progbits

    .section .text.rucksack_menu_transition_factory, "ax", %progbits

    .global CreateScene__22RucksackMenuTransition
    .thumb_func
CreateScene__22RucksackMenuTransition:
    push {r4, r5, r6, lr}
    sub sp, #0x10
    adds r6, r0, #0
    adds r4, r1, #0
    ldr r0, [r4, #4]
    movs r5, #0
    str r5, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0xc
    bl __builtin_new
    add r1, sp, #4
    ldr r2, [r4, #8]
    bl __17RucksackMenuSceneG20SceneTransitionOwnerP18GameStateSaveImage
    str r0, [sp]
    mov r1, sp
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    str r5, [r1]
    str r0, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .Lauto_080DB07C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DB07C:
    adds r0, r6, #0
    add sp, #0x10
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .section .text.scene_cooking_after, "ax", %progbits

    .section .text.scene_reference_page_after, "ax", %progbits

    .section .text.scene_gift_wrapping_after, "ax", %progbits

    .section .text.scene_poultry_farm_shop_after, "ax", %progbits

    .section .text.scene_winery_shop_after, "ax", %progbits

    .section .text.scene_inn_shop_after, "ax", %progbits

    .section .text.scene_beach_cafe_shop_after, "ax", %progbits

    .section .text.scene_won_shop_after, "ax", %progbits

    .section .text.scene_carpenter_shop_after, "ax", %progbits

    .section .text.scene_clinic_shop_after, "ax", %progbits

    .section .text.scene_blacksmith_shop_after, "ax", %progbits

    .section .text.scene_supermarket_purchase_after, "ax", %progbits

    .section .text.scene_clock_after, "ax", %progbits

    .section .text.scene_return_after, "ax", %progbits

    .byte 0x10, 0xB5, 0x04, 0x1C, 0x05, 0x48, 0x00, 0x68, 0x08, 0x30, 0x63, 0xF7, 0x4B, 0xFD
    .byte 0x20, 0x1C
    bl func_080D7F3C
    .byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x0C, 0x04
    .byte 0x00, 0x03
    .global func_080DC2B4
    .thumb_func
func_080DC2B4:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    str r0, [sp, #8]
    adds r0, #0xa8
    ldr r0, [r0]
    ldr r4, [r0]
    mov ip, r4
    movs r5, #0xb4
    add ip, r5
    mov r8, sp
    ldr r7, [pc, #0x84]
    mov sl, r7
    mov r4, sl
    ands r1, r4
    mov r7, r8
    ldrh r5, [r7]
    ldr r6, [pc, #0x7c]
    adds r4, r6, #0
    ands r4, r5
    orrs r4, r1
    .byte 0x3C, 0x80, 0x12, 0x04, 0x14, 0x0C, 0x3F, 0x21, 0x0C, 0x40, 0xA4, 0x00, 0x7D, 0x78, 0xA9, 0x46
    .byte 0x03, 0x25, 0x29, 0x1C, 0x4F, 0x46, 0x39, 0x40, 0x21, 0x43, 0x44, 0x46, 0x61, 0x70, 0x92, 0x0D
    .byte 0x57, 0x46, 0x3A, 0x40, 0x64, 0x88, 0x31, 0x1C, 0x21, 0x40, 0x11, 0x43, 0x42, 0x46, 0x51, 0x80
    .byte 0x1B, 0x04, 0x19, 0x0C, 0x3F, 0x24, 0x21, 0x40, 0x89, 0x00, 0xD2, 0x78, 0x15, 0x40, 0x0D, 0x43
    .byte 0x47, 0x46, 0xFD, 0x70, 0x9B, 0x0D, 0x51, 0x46, 0x0B, 0x40, 0xB9, 0x88, 0x0E, 0x40, 0x1E, 0x43
    .byte 0xBE, 0x80, 0x62, 0x46, 0x13, 0x68, 0x69, 0x46, 0x01, 0x22, 0xF7, 0xF7, 0xED, 0xFA, 0x02, 0x98
    bl func_080D7F08
    .byte 0x03, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC
    .byte 0x01, 0xBC, 0x00, 0x47, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF
    .global func_080DC360
    .thumb_func
func_080DC360:
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #8
    adds r6, r0, #0
    mov r8, r1
    mov sb, r2
    adds r4, r3, #0
    ldr r5, [sp, #0x20]
    adds r0, #0xa8
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    str r4, [sp]
    str r5, [sp, #4]
    adds r0, r6, #0
    mov r1, r8
    mov r3, sb
    bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .section .text.after_gamecube_link_scene, "ax", %progbits
    .align 2, 0

    .global func_080DC42C
    .thumb_func
func_080DC42C:
    push {r4, r5, r6, lr}
    sub sp, #0x10
    adds r6, r0, #0
    adds r4, r1, #0
    ldr r0, [r4, #8]
    movs r5, #0
    str r5, [r4, #8]
    str r0, [sp, #4]
    movs r0, #8
    bl __builtin_new
    ldr r1, [r4, #4]
    add r2, sp, #4
    bl func_080701BC
    str r0, [sp]
    mov r1, sp
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    str r5, [r1]
    str r0, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .Lauto_080DBC1C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBC1C:
    adds r0, r6, #0
    add sp, #0x10
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080DC474
    .thumb_func
func_080DC474:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .Lauto_080DBC40
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBC40:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15SceneTransition
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC49C
    .thumb_func
func_080DC49C:
    push {r4, r5, r6, lr}
    sub sp, #0x10
    adds r6, r0, #0
    adds r4, r1, #0
    ldr r0, [r4, #4]
    movs r5, #0
    str r5, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0xc
    bl __builtin_new
    add r1, sp, #4
    ldr r2, [r4, #8]
    bl func_080755EC
    str r0, [sp]
    mov r1, sp
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    str r5, [r1]
    str r0, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .Lauto_080DBC8C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBC8C:
    adds r0, r6, #0
    add sp, #0x10
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080DC4E4
    .thumb_func
func_080DC4E4:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r1, [r4, #4]
    cmp r1, #0
    beq .Lauto_080DBCB0
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBCB0:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15SceneTransition
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC50C
    .thumb_func
func_080DC50C:
    push {r4, r5, r6, lr}
    sub sp, #0x10
    adds r6, r0, #0
    adds r4, r1, #0
    ldr r0, [r4, #4]
    movs r5, #0
    str r5, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0xc
    bl __builtin_new
    add r1, sp, #4
    ldr r2, [r4, #8]
    ldrb r3, [r4, #0xc]
    bl func_08069E14
    str r0, [sp]
    mov r1, sp
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    str r5, [r1]
    str r0, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .Lauto_080DBCFE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBCFE:
    adds r0, r6, #0
    add sp, #0x10
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .global func_080DC554
    .thumb_func
func_080DC554:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r1, [r4, #4]
    cmp r1, #0
    beq .Lauto_080DBD20
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBD20:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15SceneTransition
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .section .text.scene_group_sprite_cleanup_after, "ax", %progbits
    .align 2, 0

    .global _._10GameObject
    .thumb_func
_._10GameObject:
    push {lr}
    adds r2, r0, #0
    ldr r0, .Ldestroy_world_interface_jp_table
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Ldestroy_world_interface_jp_done
    adds r0, r2, #0
    bl __builtin_delete
.Ldestroy_world_interface_jp_done:
    pop {r0}
    bx r0
    .align 2, 0
.Ldestroy_world_interface_jp_table: .4byte __vt_14GameObjectBase

    .global _._14GameObjectBase
    .thumb_func
_._14GameObjectBase:
    push {lr}
    adds r2, r0, #0
    ldr r0, .Ldestroy_common_interface_jp_table
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Ldestroy_common_interface_jp_done
    adds r0, r2, #0
    bl __builtin_delete
.Ldestroy_common_interface_jp_done:
    pop {r0}
    bx r0
    .align 2, 0
.Ldestroy_common_interface_jp_table: .4byte __vt_14GameObjectBase

    .global func_080DC5F4
    .thumb_func
func_080DC5F4:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #0x48
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r5, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x14]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DBDD2
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DBDD2:
    pop {r4, r5}
    pop {r0}
    bx r0
    .4byte __vt_22EntityVisualController
    .global DestroyAudioActorEntity
    .thumb_func
DestroyAudioActorEntity:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DBDF8
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBDF8:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DBE06
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DBE06:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .section .text.entity_visual_controller_cleanup_after, "ax", %progbits
    .align 2, 0
    .global func_080DC67C
    .thumb_func
func_080DC67C:
    push {r4, r5, lr}
    adds r5, r1, #0
    adds r4, r2, #0
    adds r3, r0, #0
    subs r0, r5, r3
    asrs r2, r0, #2
    cmp r2, #0
    ble .Lauto_080DBE68
    ldrb r1, [r4]
    .Lauto_080DBE42:
    ldrb r0, [r3]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    ldrb r0, [r3]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    ldrb r0, [r3]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    ldrb r0, [r3]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    subs r2, #1
    cmp r2, #0
    bgt .Lauto_080DBE42
    .Lauto_080DBE68:
    subs r0, r5, r3
    cmp r0, #1
    beq .Lauto_080DBE8E
    cmp r0, #1
    ble .Lauto_080DBE9A
    cmp r0, #2
    beq .Lauto_080DBE84
    cmp r0, #3
    bne .Lauto_080DBE9A
    ldrb r0, [r3]
    ldrb r1, [r4]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    .Lauto_080DBE84:
    ldrb r0, [r3]
    ldrb r1, [r4]
    cmp r0, r1
    beq .Lauto_080DBE96
    adds r3, #1
    .Lauto_080DBE8E:
    ldrb r0, [r3]
    ldrb r4, [r4]
    cmp r0, r4
    bne .Lauto_080DBE9A
    .Lauto_080DBE96:
    adds r0, r3, #0
    b .Lauto_080DBE9C
    .Lauto_080DBE9A:
    adds r0, r5, #0
    .Lauto_080DBE9C:
    pop {r4, r5}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080DC6F0
    .thumb_func
func_080DC6F0:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DBEC0
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBEC0:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DBECE
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DBECE:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .global func_080DC724
    .thumb_func
func_080DC724:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #0x8c
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r5, #0
    adds r0, #0x48
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r5, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x18]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DBF0C
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DBF0C:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_22EntityVisualController
    .section .text.player_sprite_cleanup_after, "ax", %progbits
    .align 2, 0
    .global func_080DBF80
    .thumb_func
func_080DBF80:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DBF9C
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBF9C:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DBFAA
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DBFAA:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .global func_080DBFB4
    .thumb_func
func_080DBFB4:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DBFD0
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DBFD0:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DBFDE
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DBFDE:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .section .text.entity_sprite_cleanup_after, "ax", %progbits
    .align 2, 0
    .global func_080DC0E0
    .thumb_func
func_080DC0E0:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #0x8c
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r5, #0
    adds r0, #0x48
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r5, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x18]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DC114
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DC114:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_22EntityVisualController
    .section .text.npc_timed_path_search_after, "ax", %progbits

    .global func_080DC9A8
    .thumb_func
func_080DC9A8:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9B4
    .thumb_func
func_080DC9B4:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9C0
    .thumb_func
func_080DC9C0:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9CC
    .thumb_func
func_080DC9CC:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9D8
    .thumb_func
func_080DC9D8:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9E4
    .thumb_func
func_080DC9E4:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9F0
    .thumb_func
func_080DC9F0:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DC9FC
    .thumb_func
func_080DC9FC:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA08
    .thumb_func
func_080DCA08:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA14
    .thumb_func
func_080DCA14:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA20
    .thumb_func
func_080DCA20:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA2C
    .thumb_func
func_080DCA2C:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA38
    .thumb_func
func_080DCA38:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA44
    .thumb_func
func_080DCA44:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA50
    .thumb_func
func_080DCA50:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA5C
    .thumb_func
func_080DCA5C:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA68
    .thumb_func
func_080DCA68:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA74
    .thumb_func
func_080DCA74:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA80
    .thumb_func
func_080DCA80:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA8C
    .thumb_func
func_080DCA8C:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCA98
    .thumb_func
func_080DCA98:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAA4
    .thumb_func
func_080DCAA4:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAB0
    .thumb_func
func_080DCAB0:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCABC
    .thumb_func
func_080DCABC:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAC8
    .thumb_func
func_080DCAC8:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAD4
    .thumb_func
func_080DCAD4:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAE0
    .thumb_func
func_080DCAE0:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAEC
    .thumb_func
func_080DCAEC:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCAF8
    .thumb_func
func_080DCAF8:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB04
    .thumb_func
func_080DCB04:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB10
    .thumb_func
func_080DCB10:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB1C
    .thumb_func
func_080DCB1C:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB28
    .thumb_func
func_080DCB28:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB34
    .thumb_func
func_080DCB34:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB40
    .thumb_func
func_080DCB40:
    push {lr}
    bl _._10ANpcEntity
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB4C
    .thumb_func
func_080DCB4C:
    push {lr}
    bl func_08037048
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB58
    .thumb_func
func_080DCB58:
    push {lr}
    bl func_08037048
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB64
    .thumb_func
func_080DCB64:
    push {lr}
    bl func_08037048
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB70
    .thumb_func
func_080DCB70:
    push {lr}
    bl func_08037048
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCB7C
    .thumb_func
func_080DCB7C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x6c
    mov r8, r0
    mov sl, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    str r2, [sp, #0x5c]
    movs r0, #0
    mov r1, r8
    str r0, [r1]
    add r5, sp, #0xc
    mov r2, sl
    ldr r0, [r2]
    ldr r1, [r0, #0x7c]
    mov r0, sl
    bl _call_via_r1
    adds r1, r0, #0
    ldr r3, [sp, #0x5c]
    cmp r3, #0
    beq .Lauto_080DC36C
    ldr r0, [pc, #4]
    ldrh r2, [r0, #2]
    b .Lauto_080DC370
    .word gUnk_080F1684
    .Lauto_080DC36C:
    ldr r0, [pc, #0xd4]
    ldrh r2, [r0]
    .Lauto_080DC370:
    movs r0, #6
    str r0, [sp]
    movs r0, #0x1d
    str r0, [sp, #4]
    add r4, sp, #8
    movs r0, #0
    strb r0, [r4]
    adds r0, r5, #0
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    movs r0, #0xc8
    lsls r0, r0, #0xf
    str r0, [r5, #0x40]
    adds r1, r5, #0
    adds r1, #0x44
    movs r0, #0x96
    lsls r0, r0, #1
    strh r0, [r1]
    ldr r0, [pc, #0xb0]
    str r0, [r5, #0x48]
    ldr r0, [pc, #0xa8]
    ldrb r1, [r0, #4]
    adds r0, r5, #0
    adds r0, #0x4c
    strb r1, [r0]
    adds r1, r5, #0
    adds r1, #0x4d
    movs r0, #1
    strb r0, [r1]
    mov r0, r8
    ldr r1, [r0]
    str r4, [sp, #0x68]
    cmp r1, #4
    bhi .Lauto_080DC3D2
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, #4
    add r0, r8
    cmp r0, #0
    beq .Lauto_080DC3CA
    add r1, sp, #0xc
    bl func_080DCD2C
    .Lauto_080DC3CA:
    mov r1, r8
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    .Lauto_080DC3D2:
    add r0, sp, #0xc
    movs r1, #2
    bl _._19GameSceneSpriteBase
    movs r2, #0
    str r2, [sp, #0x60]
    add r7, sp, #0xc
    mov r3, sp
    adds r3, #0x59
    str r3, [sp, #0x64]
    .Lauto_080DC3E6:
    bl rand
    movs r1, #3
    bl __modsi3
    adds r6, r0, #0
    bl rand
    movs r1, #0xf0
    lsls r1, r1, #1
    bl __umodsi3
    adds r5, r0, #0
    ldr r4, [pc, #0x48]
    bl rand
    movs r1, #3
    bl __modsi3
    adds r0, r0, r4
    ldrb r4, [r0]
    bl rand
    movs r1, #3
    bl __modsi3
    lsls r0, r0, #2
    ldr r1, [pc, #0x30]
    adds r0, r0, r1
    ldr r0, [r0]
    mov sb, r0
    mov r2, sl
    ldr r0, [r2]
    ldr r1, [r0, #0x7c]
    mov r0, sl
    bl _call_via_r1
    adds r1, r0, #0
    ldr r3, [sp, #0x5c]
    cmp r3, #0
    beq .Lauto_080DC454
    lsls r0, r6, #3
    ldr r2, [pc, #8]
    adds r0, r0, r2
    ldrh r2, [r0, #2]
    b .Lauto_080DC45C
    .byte 0x00, 0x00
    .word gUnk_080F1684
    .byte 0x66, 0x26, 0x00, 0x00
    .word gUnk_080F1672
    .word gUnk_080F1678
    .Lauto_080DC454:
    lsls r0, r6, #3
    ldr r3, [pc, #0x84]
    adds r0, r0, r3
    ldrh r2, [r0]
    .Lauto_080DC45C:
    movs r0, #6
    str r0, [sp]
    movs r0, #0x1d
    str r0, [sp, #4]
    movs r0, #0
    ldr r3, [sp, #0x68]
    strb r0, [r3]
    adds r0, r7, #0
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    lsls r0, r5, #0x10
    str r0, [r7, #0x40]
    adds r0, r7, #0
    adds r0, #0x44
    strh r4, [r0]
    mov r0, sb
    str r0, [r7, #0x48]
    lsls r0, r6, #3
    ldr r1, [pc, #0x58]
    adds r0, r0, r1
    ldrb r1, [r0, #4]
    adds r0, r7, #0
    adds r0, #0x4c
    strb r1, [r0]
    movs r0, #1
    ldr r2, [sp, #0x64]
    strb r0, [r2]
    mov r3, r8
    ldr r1, [r3]
    cmp r1, #4
    bhi .Lauto_080DC4B8
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, #4
    add r0, r8
    cmp r0, #0
    beq .Lauto_080DC4B0
    add r1, sp, #0xc
    bl func_080DCD2C
    .Lauto_080DC4B0:
    mov r1, r8
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    .Lauto_080DC4B8:
    add r0, sp, #0xc
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r2, [sp, #0x60]
    adds r2, #1
    str r2, [sp, #0x60]
    cmp r2, #3
    bls .Lauto_080DC3E6
    mov r0, r8
    add sp, #0x6c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .word gUnk_080F1684
    .global func_080DCD2C
    .thumb_func
func_080DCD2C:
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    bl __19GameSceneSpriteBaseRC19GameSceneSpriteBase
    ldr r0, [pc, #0x74]
    str r0, [r4, #0x24]
    adds r1, r4, #0
    adds r1, #0x28
    adds r0, r5, #0
    adds r0, #0x28
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3d
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    adds r1, #1
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    adds r1, #1
    strb r0, [r1]
    ldr r0, [r5, #0x40]
    str r0, [r4, #0x40]
    adds r0, r5, #0
    adds r0, #0x44
    ldrh r1, [r0]
    adds r0, r4, #0
    adds r0, #0x44
    strh r1, [r0]
    ldr r0, [r5, #0x48]
    str r0, [r4, #0x48]
    adds r0, r5, #0
    adds r0, #0x4c
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x4c
    strb r1, [r0]
    adds r0, r5, #0
    adds r0, #0x4d
    ldrb r0, [r0]
    adds r2, r4, #0
    adds r2, #0x4d
    strb r0, [r2]
    adds r0, r4, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .4byte __vt_22GameSceneIndexedSprite
    .global func_080DCDB0
    .thumb_func
func_080DCDB0:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r7, r0, #0
    mov r8, r1
    ldr r0, [r7, #0x14]
    cmp r0, #0
    beq .Lauto_080DC59C
    adds r6, r0, #0
    ldr r1, [r6]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, #4
    adds r5, r6, r0
    adds r4, r6, #4
    cmp r4, r5
    beq .Lauto_080DC596
    .Lauto_080DC588:
    adds r0, r4, #0
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r4, #0x50
    cmp r4, r5
    bne .Lauto_080DC588
    .Lauto_080DC596:
    adds r0, r6, #0
    bl __builtin_delete
    .Lauto_080DC59C:
    ldr r0, [r7, #0x10]
    cmp r0, #0
    beq .Lauto_080DC5CA
    adds r6, r0, #0
    ldr r0, [r6]
    lsls r0, r0, #6
    adds r0, #4
    adds r5, r6, r0
    adds r4, r6, #4
    cmp r4, r5
    beq .Lauto_080DC5C4
    .Lauto_080DC5B2:
    ldr r0, [r4, #0x24]
    ldr r2, [r0, #8]
    adds r0, r4, #0
    movs r1, #2
    bl _call_via_r2
    adds r4, #0x40
    cmp r4, r5
    bne .Lauto_080DC5B2
    .Lauto_080DC5C4:
    adds r0, r6, #0
    bl __builtin_delete
    .Lauto_080DC5CA:
    ldr r4, [r7, #0xc]
    cmp r4, #0
    beq .Lauto_080DC5DE
    adds r0, r4, #0
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DC5DE:
    ldr r4, [r7, #8]
    cmp r4, #0
    beq .Lauto_080DC5F2
    adds r0, r4, #0
    movs r1, #2
    bl _._19GameSceneSpriteBase
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DC5F2:
    ldr r0, [pc, #0x1c]
    str r0, [r7, #4]
    movs r0, #1
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080DC606
    adds r0, r7, #0
    bl __builtin_delete
    .Lauto_080DC606:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .4byte __vt_22EntityVisualController
    .global func_080DCE60
    .thumb_func
func_080DCE60:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DC630
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DC630:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DC63E
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DC63E:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .global func_080DCE94
    .thumb_func
func_080DCE94:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x18]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DC668
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DC668:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_22EntityVisualController
    .global func_080DCEC0
    .thumb_func
func_080DCEC0:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x18]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DC694
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DC694:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_22EntityVisualController
    .global func_080DCEEC
    .thumb_func
func_080DCEEC:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080DC6BC
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DC6BC:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DC6CA
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DC6CA:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .global func_080DCF20
    .thumb_func
func_080DCF20:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, #8
    movs r1, #2
    bl _._19GameSceneSpriteBase
    ldr r0, [pc, #0x18]
    str r0, [r5, #4]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080DC6F4
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080DC6F4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_22EntityVisualController
    .global func_080DCF4C
    .thumb_func
func_080DCF4C:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    mov r8, r0
    mov sb, r1
    ldr r0, [pc, #0x68]
    mov r1, r8
    str r0, [r1, #0x14]
    ldr r0, [r1, #0x10]
    cmp r0, #0
    beq .Lauto_080DC744
    ldr r1, [r1, #0x18]
    movs r6, #0
    ldr r7, [r0, #8]
    cmp r6, r7
    bhs .Lauto_080DC744
    adds r5, r1, #0
    adds r4, r0, #0
    adds r4, #0xc
    .Lauto_080DC728:
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_080DC73A
    ldr r0, [r1, #0x4c]
    ldr r2, [r0, #0x14]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r2
    .Lauto_080DC73A:
    adds r5, #0x10
    adds r4, #4
    adds r6, #1
    cmp r6, r7
    blo .Lauto_080DC728
    .Lauto_080DC744:
    ldr r0, [pc, #0x34]
    mov r2, r8
    str r0, [r2, #0x14]
    ldr r1, [r2, #0x10]
    cmp r1, #0
    beq .Lauto_080DC75C
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DC75C:
    movs r0, #1
    mov r1, sb
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080DC76C
    mov r0, r8
    bl __builtin_delete
    .Lauto_080DC76C:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0xA8, 0x69, 0x0E, 0x08, 0x90, 0x56, 0x0E, 0x08
    .global func_080DCFCC
    .thumb_func
func_080DCFCC:
    push {r4, lr}
    adds r4, r0, #0
    bl vfunc_14__7AEntity
    movs r0, #0
    strb r0, [r4, #0x1c]
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DCFE0
    .thumb_func
func_080DCFE0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r4, r0, #0
    movs r7, #0
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne .Lauto_080DC7AA
    b .Lauto_080DCACC
    .Lauto_080DC7AA:
    movs r0, #0x18
    bl __builtin_new
    adds r6, r0, #0
    ldr r0, [r4, #0x18]
    mov sl, r0
    str r4, [r6]
    ldr r0, [pc, #0x2c]
    str r0, [r6, #4]
    str r7, [r6, #8]
    ldr r4, [r4]
    mov r8, r4
    movs r1, #0
    mov sb, r1
    .Lauto_080DC7C6:
    mov r2, sb
    lsls r0, r2, #4
    mov r1, sl
    adds r7, r1, r0
    ldrb r0, [r7]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    subs r0, #1
    cmp r0, #0xb
    bls .Lauto_080DC7DC
    b .Lauto_080DCAAE
    .Lauto_080DC7DC:
    lsls r0, r0, #2
    ldr r1, [pc, #0xc]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0x14, 0x6B, 0x0E, 0x08, 0xF0, 0xC7, 0x0D, 0x08, 0x20, 0xC8, 0x0D, 0x08, 0x48, 0xC8
    .byte 0x0D, 0x08, 0x68, 0xC8, 0x0D, 0x08, 0x90, 0xC8, 0x0D, 0x08, 0xB8, 0xC8, 0x0D, 0x08, 0x14, 0xC9
    .byte 0x0D, 0x08, 0x88, 0xC9, 0x0D, 0x08, 0xB0, 0xC9, 0x0D, 0x08, 0xD8, 0xC9, 0x0D, 0x08, 0x00, 0xCA
    .byte 0x0D, 0x08, 0x28, 0xCA, 0x0D, 0x08, 0x48, 0xCA, 0x0D, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48, 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23
    .byte 0x5D, 0xF7, 0xF9, 0xF9, 0x02, 0x48, 0x0F, 0xE1, 0x00, 0x00, 0xB6, 0x09, 0x00, 0x00, 0xE4, 0x6A
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x10, 0x32
    .byte 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0xE7, 0xF9, 0x01, 0x48, 0xFD, 0xE0, 0x00, 0x00, 0xCC, 0x6A
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48
    .byte 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0xD5, 0xF9, 0x02, 0x48, 0xEB, 0xE0
    .byte 0x00, 0x00, 0xDB, 0x03, 0x00, 0x00, 0xB4, 0x6A, 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48, 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23
    .byte 0x5D, 0xF7, 0xC1, 0xF9, 0x02, 0x48, 0xD7, 0xE0, 0x00, 0x00, 0x06, 0x08, 0x00, 0x00, 0x9C, 0x6A
    .byte 0x0E, 0x08, 0x6C, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x11, 0x48
    .byte 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0xAD, 0xF9, 0x0F, 0x48, 0xE8, 0x64
    .byte 0x78, 0x68, 0x28, 0x65, 0xA0, 0x88, 0x29, 0x1C, 0x54, 0x31, 0x00, 0x22, 0x00, 0x23, 0x08, 0x80
    .byte 0xE0, 0x88, 0x2C, 0x1C, 0x56, 0x34, 0x20, 0x80, 0x28, 0x1C, 0x60, 0x30, 0x03, 0x80, 0x02, 0x30
    .byte 0x02, 0x70, 0x00, 0x22, 0x88, 0x5E, 0x00, 0x04, 0xA8, 0x65, 0x00, 0x21, 0x60, 0x5E, 0x00, 0x04
    .byte 0xE8, 0x65, 0xAB, 0x66, 0xC2, 0xE0, 0x02, 0x02, 0x00, 0x00, 0x84, 0x6A, 0x0E, 0x08, 0x88, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x17, 0x48, 0x12, 0x18, 0x28, 0x1C
    .byte 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0x7F, 0xF9, 0x15, 0x48, 0xE8, 0x64, 0x78, 0x68, 0x28, 0x65
    .byte 0x29, 0x1C, 0x79, 0x31, 0xFF, 0x20, 0x08, 0x70, 0x29, 0x39, 0x22, 0x7A, 0x12, 0x07, 0x12, 0x17
    .byte 0x28, 0x1C, 0x5D, 0xF7, 0xC6, 0xFA, 0x29, 0x1C, 0x78, 0x31, 0x00, 0x22, 0x08, 0x70, 0x28, 0x1C
    .byte 0x60, 0x30, 0x00, 0x21, 0x02, 0x80, 0x02, 0x30, 0x01, 0x70, 0x0E, 0x38, 0x00, 0x21, 0x40, 0x5E
    .byte 0x00, 0x04, 0xA8, 0x65, 0x28, 0x1C, 0x56, 0x30, 0x00, 0x22, 0x80, 0x5E, 0x00, 0x04, 0xE8, 0x65
    .byte 0x29, 0x1C, 0x84, 0x31, 0xF8, 0x20, 0x08, 0x70, 0x88, 0xE0, 0xA3, 0x02, 0x00, 0x00, 0x6C, 0x6A
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48
    .byte 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0x45, 0xF9, 0x02, 0x48, 0x5B, 0xE0
    .byte 0x00, 0x00, 0x7B, 0x08, 0x00, 0x00, 0x54, 0x6A, 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48, 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23
    .byte 0x5D, 0xF7, 0x31, 0xF9, 0x02, 0x48, 0x47, 0xE0, 0x00, 0x00, 0x5C, 0x06, 0x00, 0x00, 0x3C, 0x6A
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48
    .byte 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23, 0x5D, 0xF7, 0x1D, 0xF9, 0x02, 0x48, 0x33, 0xE0
    .byte 0x00, 0x00, 0xF9, 0x08, 0x00, 0x00, 0x24, 0x6A, 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x7A, 0x68, 0x04, 0x48, 0x12, 0x18, 0x28, 0x1C, 0x41, 0x46, 0x01, 0x23
    .byte 0x5D, 0xF7, 0x09, 0xF9, 0x02, 0x48, 0x1F, 0xE0, 0x00, 0x00, 0xA9, 0x09, 0x00, 0x00, 0x0C, 0x6A
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x41, 0x46, 0x02, 0x4A
    .byte 0x01, 0x23, 0x5D, 0xF7, 0xF8, 0xF8, 0x01, 0x48, 0x0E, 0xE0, 0xFD, 0x08, 0x00, 0x00, 0xF4, 0x69
    .byte 0x0E, 0x08, 0x64, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x3C, 0x1D, 0x41, 0x46, 0x15, 0x22
    .byte 0x00, 0x23, 0x5D, 0xF7, 0xE8, 0xF8, 0x1A, 0x48, 0xE8, 0x64, 0x78, 0x68, 0x28, 0x65, 0xA0, 0x88
    .byte 0x2A, 0x1C, 0x54, 0x32, 0x00, 0x23, 0x00, 0x21, 0x10, 0x80, 0xE0, 0x88, 0x2C, 0x1C, 0x56, 0x34
    .byte 0x20, 0x80, 0x28, 0x1C, 0x60, 0x30, 0x01, 0x80, 0x02, 0x30, 0x03, 0x70, 0x00, 0x21, 0x50, 0x5E
    .byte 0x00, 0x04, 0xA8, 0x65, 0x00, 0x22, 0xA0, 0x5E, 0x00, 0x04, 0xE8, 0x65, 0x31, 0x1C, 0x08, 0x31
    .byte 0xB0, 0x68, 0x02, 0x28, 0x08, 0xD8, 0x80, 0x00, 0x04, 0x30, 0x08, 0x18, 0x00, 0x28, 0x00, 0xD0
    .byte 0x05, 0x60, 0xB0, 0x68, 0x01, 0x30, 0xB0, 0x60
    .Lauto_080DCAAE:
    ldrb r1, [r7]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r7]
    movs r0, #1
    add sb, r0
    mov r1, sb
    cmp r1, #2
    bhi .Lauto_080DCAC4
    b .Lauto_080DC7C6
    .Lauto_080DCAC4:
    adds r7, r6, #0
    b .Lauto_080DCB22
    .byte 0xDC, 0x69, 0x0E, 0x08
    .Lauto_080DCACC:
    movs r0, #0x18
    bl __builtin_new
    adds r5, r0, #0
    str r4, [r5]
    ldr r0, [pc, #0x5c]
    str r0, [r5, #4]
    str r7, [r5, #8]
    ldr r4, [r4]
    ldr r0, [r4]
    movs r2, #0xa2
    lsls r2, r2, #1
    adds r0, r0, r2
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    ldrb r0, [r0, #0xa]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1b
    movs r6, #0
    subs r0, #6
    cmp r0, #0xb
    bls .Lauto_080DCAFE
    movs r6, #1
    .Lauto_080DCAFE:
    ldr r0, [r4]
    movs r1, #0xa2
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    adds r0, #8
    bl GetCalendarEffectiveSeason
    adds r2, r0, #0
    adds r0, r5, #0
    adds r1, r4, #0
    adds r3, r6, #0
    bl func_0803A394
    adds r7, r5, #0
    .Lauto_080DCB22:
    adds r0, r7, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00, 0x14, 0x6B, 0x0E, 0x08
    .global func_080DD384
    .thumb_func
func_080DD384:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #0xc
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD3A8
    .thumb_func
func_080DD3A8:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD3D4
    .thumb_func
func_080DD3D4:
    push {r4, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x47
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_080DCBAC
    adds r0, r4, #0
    adds r0, #0x30
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_080DCBB0
    adds r1, r4, #0
    adds r1, #0x44
    movs r0, #1
    b .Lauto_080DCBAE
    .Lauto_080DCBAC:
    movs r0, #0
    .Lauto_080DCBAE:
    strb r0, [r1]
    .Lauto_080DCBB0:
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD404
    .thumb_func
func_080DD404:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD410
    .thumb_func
func_080DD410:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #0xb
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD434
    .thumb_func
func_080DD434:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD460
    .thumb_func
func_080DD460:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r4, #0
    adds r5, #0x62
    movs r0, #0
    ldrsb r0, [r5, r0]
    cmp r0, #0
    beq .Lauto_080DCC2A
    cmp r0, #1
    beq .Lauto_080DCC58
    b .Lauto_080DCC6C
    .Lauto_080DCC2A:
    bl rand
    asrs r0, r0, #4
    movs r1, #3
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080DCC40
    adds r0, r4, #0
    movs r1, #0xcf
    bl func_0803A350
    .Lauto_080DCC40:
    movs r0, #2
    bl RandomBelow
    adds r0, #6
    lsls r1, r0, #4
    subs r1, r1, r0
    lsls r1, r1, #2
    adds r0, r4, #0
    adds r0, #0x60
    strh r1, [r0]
    movs r0, #1
    b .Lauto_080DCC6A
    .Lauto_080DCC58:
    adds r1, r4, #0
    adds r1, #0x60
    ldrh r0, [r1]
    subs r0, #1
    .byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x28, 0x01, 0xDA, 0x00, 0x20
    .Lauto_080DCC6A:
    strb r0, [r5]
    .Lauto_080DCC6C:
    adds r1, r4, #0
    adds r1, #0x47
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_080DCC8C
    adds r0, r4, #0
    adds r0, #0x30
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_080DCC90
    adds r1, r4, #0
    adds r1, #0x44
    movs r0, #1
    b .Lauto_080DCC8E
    .Lauto_080DCC8C:
    movs r0, #0
    .Lauto_080DCC8E:
    strb r0, [r1]
    .Lauto_080DCC90:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD4E4
    .thumb_func
func_080DD4E4:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD4F0
    .thumb_func
func_080DD4F0:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #0xa
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD514
    .thumb_func
func_080DD514:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD540
    .thumb_func
func_080DD540:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    .byte 0x80, 0x22, 0x52, 0x02, 0x5D, 0xF7, 0x08, 0xF9, 0x00, 0x28, 0x14, 0xD0, 0x20, 0x6D, 0x0B, 0x49
    .byte 0x45, 0x18, 0xA0, 0x88, 0xA8, 0x42, 0x0E, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x02, 0x70
    .byte 0x01, 0x30, 0x01, 0x70, 0xA5, 0x80, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xA9, 0x09, 0x00, 0x00
    .global func_080DD588
    .thumb_func
func_080DD588:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD594
    .thumb_func
func_080DD594:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #9
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD5B8
    .thumb_func
func_080DD5B8:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD5E4
    .thumb_func
func_080DD5E4:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x50
    adds r5, r0, #0
    ldr r4, [r5]
    ldr r0, [r4]
    ldr r2, [r0, #0x40]
    adds r0, r4, #0
    movs r1, #0
    bl _call_via_r2
    cmp r0, #0
    beq .Lauto_080DCEB2
    movs r2, #0xa
    ldrsh r1, [r0, r2]
    mov sb, r1
    movs r7, #0xe
    ldrsh r3, [r0, r7]
    mov r8, r3
    movs r0, #0x54
    adds r0, r0, r5
    mov sl, r0
    movs r1, #0
    ldrsh r0, [r0, r1]
    mov r2, sb
    subs r0, r2, r0
    cmp r0, #0
    bge .Lauto_080DCDD8
    rsbs r0, r0, #0
    .Lauto_080DCDD8:
    cmp r0, #0xf
    bgt .Lauto_080DCEB2
    adds r6, r5, #0
    adds r6, #0x56
    movs r3, #0
    ldrsh r0, [r6, r3]
    mov r7, r8
    subs r0, r7, r0
    cmp r0, #0
    bge .Lauto_080DCDEE
    rsbs r0, r0, #0
    .Lauto_080DCDEE:
    cmp r0, #0xf
    bgt .Lauto_080DCEB2
    ldr r1, [r4]
    add r0, sp, #8
    ldr r3, [r1, #0x34]
    adds r1, r4, #0
    movs r2, #0
    bl _call_via_r3
    mov r0, sl
    movs r2, #0
    ldrsh r1, [r0, r2]
    movs r4, #0
    ldrsh r3, [r6, r4]
    add r2, sp, #0x48
    adds r0, r1, #0
    subs r0, #8
    movs r7, #0
    mov ip, r7
    strh r0, [r2]
    adds r0, r3, #0
    subs r0, #8
    strh r0, [r2, #2]
    adds r1, #8
    strh r1, [r2, #4]
    adds r3, #8
    strh r3, [r2, #6]
    add r2, sp, #0x14
    movs r1, #0x21
    str r1, [sp, #0x14]
    movs r0, #0x21
    rsbs r0, r0, #0
    str r0, [r2, #4]
    str r0, [r2, #8]
    str r1, [r2, #0xc]
    add r1, sp, #0x28
    add r0, sp, #8
    ldm r0!, {r3, r4, r7}
    stm r1!, {r3, r4, r7}
    ldr r0, [sp, #0x48]
    ldr r1, [sp, #0x4c]
    str r0, [sp, #0x34]
    str r1, [sp, #0x38]
    movs r0, #0x20
    str r0, [r2, #0x28]
    mov r1, ip
    str r1, [r2, #0x2c]
    str r1, [r2, #0x30]
    ldr r4, [r5, #0x50]
    mov r3, sl
    movs r7, #0
    ldrsh r0, [r3, r7]
    movs r3, #0
    ldrsh r1, [r6, r3]
    str r2, [sp]
    str r4, [sp, #4]
    mov r2, sb
    mov r3, r8
    bl SelectRetreatFacing
    adds r1, r0, #0
    str r1, [r5, #0x50]
    adds r6, r5, #0
    adds r6, #0x62
    cmp r4, r1
    bne .Lauto_080DCE7A
    movs r0, #0
    ldrsb r0, [r6, r0]
    cmp r0, #0
    bne .Lauto_080DCEA6
    .Lauto_080DCE7A:
    ldr r7, [pc, #0x78]
    adds r4, r1, r7
    ldrh r0, [r5, #4]
    cmp r0, r4
    beq .Lauto_080DCEA6
    adds r0, r5, #0
    adds r0, #0x30
    adds r1, r4, #0
    bl ResolveIndexedResourceHandle
    adds r0, r5, #0
    adds r0, #0x44
    movs r1, #1
    strb r1, [r0]
    adds r2, r5, #0
    adds r2, #0x46
    movs r0, #0
    strb r0, [r2]
    adds r0, r5, #0
    adds r0, #0x47
    strb r1, [r0]
    strh r4, [r5, #4]
    .Lauto_080DCEA6:
    movs r0, #1
    strb r0, [r6]
    adds r1, r5, #0
    adds r1, #0x60
    movs r0, #0x3c
    strh r0, [r1]
    .Lauto_080DCEB2:
    adds r1, r5, #0
    adds r1, #0x50
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r5, #0
    bl func_0803A180
    cmp r0, #0
    beq .Lauto_080DCF26
    adds r0, r5, #0
    adds r0, #0x62
    movs r6, #0
    ldrsb r6, [r0, r6]
    cmp r6, #0
    bne .Lauto_080DCEFC
    ldr r0, [r5, #0x50]
    ldr r1, [pc, #0x24]
    adds r4, r0, r1
    ldrh r0, [r5, #4]
    cmp r0, r4
    beq .Lauto_080DCF26
    adds r0, r5, #0
    adds r0, #0x30
    adds r1, r4, #0
    bl ResolveIndexedResourceHandle
    adds r0, r5, #0
    adds r0, #0x44
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r6, [r0]
    b .Lauto_080DCF20
    .byte 0xF9, 0x08, 0x00, 0x00, 0xF5, 0x08, 0x00, 0x00
    .Lauto_080DCEFC:
    ldr r0, [r5, #0x50]
    ldr r2, [pc, #0x38]
    adds r4, r0, r2
    ldrh r0, [r5, #4]
    cmp r0, r4
    beq .Lauto_080DCF26
    adds r0, r5, #0
    adds r0, #0x30
    adds r1, r4, #0
    bl ResolveIndexedResourceHandle
    adds r0, r5, #0
    adds r0, #0x44
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r2, [r0]
    .Lauto_080DCF20:
    adds r0, #1
    strb r1, [r0]
    strh r4, [r5, #4]
    .Lauto_080DCF26:
    add sp, #0x50
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xF9, 0x08, 0x00, 0x00
    .global func_080DD788
    .thumb_func
func_080DD788:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD794
    .thumb_func
func_080DD794:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #8
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD7B8
    .thumb_func
func_080DD7B8:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD7E4
    .thumb_func
func_080DD7E4:
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    .byte 0x80, 0x22, 0x12, 0x02, 0x5C, 0xF7, 0xB6, 0xFF, 0x00, 0x28, 0x2D, 0xD0, 0x20, 0x1C, 0x62, 0x30
    .byte 0x00, 0x26, 0x86, 0x57, 0x00, 0x2E, 0x12, 0xD1, 0x20, 0x6D, 0xCB, 0x21, 0xC9, 0x00, 0x45, 0x18
    .byte 0xA0, 0x88, 0xA8, 0x42, 0x20, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x06, 0x70, 0x11, 0xE0, 0x20, 0x6D
    .byte 0x0B, 0x49, 0x45, 0x18, 0xA0, 0x88, 0xA8, 0x42, 0x0E, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30
    .byte 0x02, 0x70, 0x01, 0x30, 0x01, 0x70, 0xA5, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
    .byte 0x5C, 0x06, 0x00, 0x00
    .global func_080DD860
    .thumb_func
func_080DD860:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD86C
    .thumb_func
func_080DD86C:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #7
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DD890
    .thumb_func
func_080DD890:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DD8BC
    .thumb_func
func_080DD8BC:
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    .byte 0x80, 0x22, 0x12, 0x02, 0x5C, 0xF7, 0x4A, 0xFF, 0x00, 0x28, 0x2E, 0xD0, 0x20, 0x1C, 0x62, 0x30
    .byte 0x00, 0x26, 0x86, 0x57, 0x00, 0x2E, 0x13, 0xD1, 0x20, 0x6D, 0x08, 0x49, 0x45, 0x18, 0xA0, 0x88
    .byte 0xA8, 0x42, 0x22, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C
    .byte 0x44, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x06, 0x70, 0x13, 0xE0, 0x77, 0x08, 0x00, 0x00
    .byte 0x20, 0x6D, 0x0B, 0x49, 0x45, 0x18, 0xA0, 0x88, 0xA8, 0x42, 0x0E, 0xD0, 0x20, 0x1C, 0x30, 0x30
    .byte 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70
    .byte 0x02, 0x30, 0x02, 0x70, 0x01, 0x30, 0x01, 0x70, 0xA5, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .byte 0x7B, 0x08, 0x00, 0x00
    .global func_080DD938
    .thumb_func
func_080DD938:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DD944
    .thumb_func
func_080DD944:
    push {r4, lr}
    mov ip, r0
    ldrb r2, [r1]
    movs r3, #0x10
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r2
    movs r2, #6
    orrs r0, r2
    strb r0, [r1]
    mov r2, ip
    ldr r0, [r2, #0x50]
    str r0, [r1, #4]
    mov r0, ip
    adds r0, #0x54
    ldrh r0, [r0]
    strh r0, [r1, #8]
    mov r0, ip
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    mov r0, ip
    adds r0, #0x78
    ldrb r2, [r0]
    movs r4, #0xf
    adds r0, r4, #0
    ands r0, r2
    ldrb r2, [r1, #0xc]
    ands r3, r2
    orrs r3, r0
    mov r0, ip
    adds r0, #0x79
    ldrb r0, [r0]
    lsls r0, r0, #4
    ands r3, r4
    orrs r3, r0
    strb r3, [r1, #0xc]
    pop {r4}
    pop {r0}
    bx r0
    .global func_080DD994
    .thumb_func
func_080DD994:
    push {r4, lr}
    sub sp, #0x10
    mov ip, r0
    adds r0, #0x54
    movs r4, #0
    ldrsh r0, [r0, r4]
    str r0, [sp]
    mov r0, ip
    adds r0, #0x56
    movs r4, #0
    ldrsh r0, [r0, r4]
    str r0, [sp, #4]
    mov r0, ip
    adds r0, #0x84
    .byte 0x00, 0x78, 0x00, 0x06, 0x00, 0x16, 0x02, 0x90, 0x01, 0x20, 0x03, 0x90, 0x60, 0x46, 0x5C, 0xF7
    .byte 0xD7, 0xFD, 0x04, 0xB0, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
    .global func_080DD9CC
    .thumb_func
func_080DD9CC:
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r6, r5, #0
    adds r6, #0x62
    movs r4, #0
    ldrsb r4, [r6, r4]
    cmp r4, #1
    beq .Lauto_080DD1C8
    cmp r4, #1
    bgt .Lauto_080DD19C
    cmp r4, #0
    beq .Lauto_080DD1AC
    subs r6, #0x1b
    b .Lauto_080DD38A
    .Lauto_080DD19C:
    cmp r4, #2
    beq .Lauto_080DD220
    adds r6, r5, #0
    adds r6, #0x47
    cmp r4, #3
    bne .Lauto_080DD1AA
    b .Lauto_080DD31A
    .Lauto_080DD1AA:
    b .Lauto_080DD38A
    .Lauto_080DD1AC:
    movs r0, #2
    bl RandomBelow
    adds r0, #0x1e
    lsls r1, r0, #4
    subs r1, r1, r0
    lsls r1, r1, #2
    adds r0, r5, #0
    adds r0, #0x60
    strh r1, [r0]
    adds r0, #0x26
    strh r4, [r0]
    movs r0, #1
    b .Lauto_080DD1DC
    .Lauto_080DD1C8:
    adds r1, r5, #0
    adds r1, #0x60
    ldrh r0, [r1]
    subs r0, #1
    .byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x14, 0x00, 0x28, 0x04, 0xDA, 0x02, 0x20
    .Lauto_080DD1DC:
    strb r0, [r6]
    adds r6, r5, #0
    adds r6, #0x47
    b .Lauto_080DD38A
    .byte 0xB4, 0x22, 0x52, 0x00, 0x2E, 0x1C, 0x47, 0x36, 0x90, 0x42, 0x00, 0xDC, 0xCB, 0xE0, 0x29, 0x1C
    .byte 0x86, 0x31, 0x08, 0x88, 0x01, 0x38, 0x08, 0x80, 0x00, 0x04, 0x00, 0x28, 0x00, 0xDD, 0xC2, 0xE0
    .byte 0x0A, 0x80, 0xF3, 0xF7, 0xC9, 0xFB, 0x00, 0x11, 0x03, 0x21, 0x08, 0x40, 0x00, 0x28, 0x00, 0xD1
    .byte 0xB9, 0xE0, 0x28, 0x1C, 0xCE, 0x21, 0x5C, 0xF7, 0x63, 0xFF, 0xB4, 0xE0
    .Lauto_080DD220:
    adds r2, r5, #0
    adds r2, #0x79
    movs r1, #0
    ldrsb r1, [r2, r1]
    movs r0, #1
    rsbs r0, r0, #0
    cmp r1, r0
    bne .Lauto_080DD23E
    adds r0, r5, #0
    adds r0, #0x78
    ldrb r0, [r0]
    adds r0, #1
    movs r1, #3
    ands r0, r1
    strb r0, [r2]
    .Lauto_080DD23E:
    adds r1, r5, #0
    adds r1, #0x64
    ldrb r2, [r2]
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    adds r0, r5, #0
    bl func_0803A144
    adds r0, r5, #0
    adds r0, #0x68
    movs r2, #0
    .byte 0x81, 0x5E, 0x09, 0x04, 0xE9, 0x66, 0x02, 0x30, 0x00, 0x23, 0xC2, 0x5E, 0x12, 0x04, 0x2A, 0x67
    .byte 0xA8, 0x6D, 0x09, 0x1A, 0xE9, 0x67, 0x29, 0x1C, 0x80, 0x31, 0xE8, 0x6D, 0x12, 0x1A, 0x0A, 0x60
    .byte 0xE8, 0x6F, 0x01, 0x1C, 0x00, 0x28, 0x00, 0xDA, 0x41, 0x42, 0x4F, 0x14, 0x11, 0x1C, 0x00, 0x2A
    .byte 0x00, 0xDA, 0x51, 0x42, 0x4E, 0x14, 0xB7, 0x42, 0x15, 0xDD, 0x00, 0x28, 0x01, 0xDA, 0x2C, 0x65
    .byte 0x01, 0xE0, 0x03, 0x20, 0x28, 0x65, 0xE8, 0x6F, 0x39, 0x1C, 0xF3, 0xF7, 0xEF, 0xF9, 0xE8, 0x67
    .byte 0x2C, 0x1C, 0x80, 0x34, 0x20, 0x68, 0x39, 0x1C, 0xF3, 0xF7, 0xE8, 0xF9, 0x20, 0x60, 0x28, 0x1C
    .byte 0x60, 0x30, 0x07, 0x80, 0x14, 0xE0, 0x00, 0x2A, 0x01, 0xDA, 0x01, 0x20, 0x00, 0xE0, 0x00, 0x20
    .byte 0x28, 0x65, 0xE8, 0x6F, 0x31, 0x1C, 0xF3, 0xF7, 0xD9, 0xF9, 0xE8, 0x67, 0x2C, 0x1C, 0x80, 0x34
    .byte 0x20, 0x68, 0x31, 0x1C, 0xF3, 0xF7, 0xD2, 0xF9, 0x20, 0x60, 0x28, 0x1C, 0x60, 0x30, 0x06, 0x80
    .byte 0x35, 0x4C, 0xA8, 0x88, 0x2E, 0x1C, 0x47, 0x36, 0xA0, 0x42, 0x0D, 0xD0, 0x28, 0x1C, 0x30, 0x30
    .byte 0x21, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x29, 0x1C, 0x44, 0x31, 0x00, 0x22, 0x01, 0x20, 0x08, 0x70
    .byte 0x02, 0x31, 0x0A, 0x70, 0x30, 0x70, 0xAC, 0x80, 0x29, 0x1C, 0x62, 0x31, 0x03, 0x20, 0x08, 0x70
    .byte 0x22, 0x31, 0x08, 0x20, 0x08, 0x70
    .Lauto_080DD31A:
    ldr r0, [r5, #0x58]
    ldr r1, [r5, #0x7c]
    adds r0, r0, r1
    str r0, [r5, #0x58]
    adds r1, r5, #0
    adds r1, #0x80
    ldr r0, [r5, #0x5c]
    ldr r1, [r1]
    adds r0, r0, r1
    str r0, [r5, #0x5c]
    adds r1, r5, #0
    adds r1, #0x60
    ldrh r0, [r1]
    subs r0, #1
    movs r7, #0
    .byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x28, 0x24, 0xDC, 0x2A, 0x1C, 0x79, 0x32, 0x11, 0x78, 0x28, 0x1C
    .byte 0x78, 0x30, 0x01, 0x70, 0xFF, 0x20, 0x10, 0x70, 0xE8, 0x6E, 0xA8, 0x65, 0x28, 0x6F, 0xE8, 0x65
    .byte 0x28, 0x1C, 0x62, 0x30, 0x07, 0x70, 0x29, 0x1C, 0x84, 0x31, 0xF8, 0x20, 0x08, 0x70, 0xA9, 0x24
    .byte 0xA4, 0x00, 0xA8, 0x88, 0xA0, 0x42, 0x0C, 0xD0, 0x28, 0x1C, 0x30, 0x30, 0x21, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x28, 0x1C, 0x44, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x07, 0x70, 0x31, 0x70
    .byte 0xAC, 0x80
    .Lauto_080DD38A:
    ldr r0, [r5, #0x58]
    asrs r0, r0, #0x10
    adds r1, r5, #0
    adds r1, #0x54
    strh r0, [r1]
    ldr r0, [r5, #0x5c]
    asrs r0, r0, #0x10
    adds r1, #2
    strh r0, [r1]
    ldrb r0, [r6]
    cmp r0, #0
    bne .Lauto_080DD3C0
    adds r0, r5, #0
    adds r0, #0x30
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_080DD3C4
    adds r1, r5, #0
    adds r1, #0x44
    movs r0, #1
    strb r0, [r1]
    b .Lauto_080DD3C4
    .byte 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00
    .Lauto_080DD3C0:
    movs r0, #0
    strb r0, [r6]
    .Lauto_080DD3C4:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDC18
    .thumb_func
func_080DDC18:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDC24
    .thumb_func
func_080DDC24:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #5
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DDC48
    .thumb_func
func_080DDC48:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    ldr r4, [r0, #0x68]
    asrs r4, r4, #0x10
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDC78
    .thumb_func
func_080DDC78:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r6, r0, #0
    adds r5, r6, #0
    adds r5, #0x62
    movs r4, #0
    ldrsb r4, [r5, r4]
    cmp r4, #1
    beq .Lauto_080DD4D0
    cmp r4, #1
    bgt .Lauto_080DD456
    cmp r4, #0
    beq .Lauto_080DD468
    adds r4, r6, #0
    adds r4, #0x60
    movs r0, #0x47
    adds r0, r0, r6
    mov r8, r0
    b .Lauto_080DD5D2
    .Lauto_080DD456:
    cmp r4, #2
    bne .Lauto_080DD45C
    b .Lauto_080DD5BC
    .Lauto_080DD45C:
    adds r4, r6, #0
    adds r4, #0x60
    movs r1, #0x47
    adds r1, r1, r6
    mov r8, r1
    b .Lauto_080DD5D2
    .Lauto_080DD468:
    bl rand
    asrs r0, r0, #8
    movs r1, #1
    ands r0, r1
    adds r0, #1
    strb r0, [r5]
    adds r5, r0, #0
    cmp r5, #1
    bne .Lauto_080DD4A2
    movs r0, #4
    bl RandomBelow
    lsls r0, r0, #8
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r0, r2
    adds r4, r6, #0
    adds r4, #0x60
    strh r0, [r4]
    bl rand
    asrs r0, r0, #8
    ands r0, r5
    lsls r0, r0, #0xb
    adds r1, r6, #0
    adds r1, #0x64
    strh r0, [r1]
    b .Lauto_080DD4B8
    .Lauto_080DD4A2:
    movs r0, #2
    bl RandomBelow
    lsls r1, r0, #4
    subs r1, r1, r0
    lsls r1, r1, #2
    adds r1, #0xb4
    adds r0, r6, #0
    adds r0, #0x60
    strh r1, [r0]
    adds r4, r0, #0
    .Lauto_080DD4B8:
    movs r0, #2
    bl RandomBelow
    lsls r0, r0, #2
    adds r0, #0xc
    adds r1, r6, #0
    adds r1, #0x66
    strh r0, [r1]
    movs r3, #0x47
    adds r3, r3, r6
    mov r8, r3
    b .Lauto_080DD5D2
    .Lauto_080DD4D0:
    adds r1, r6, #0
    adds r1, #0x64
    ldrh r0, [r1]
    movs r7, #0xff
    lsls r7, r7, #4
    ands r7, r0
    mov sb, r1
    cmp r7, #0
    bne .Lauto_080DD510
    ldr r5, [pc, #0x28]
    ldrh r0, [r6, #4]
    movs r1, #0x47
    adds r1, r1, r6
    mov r8, r1
    cmp r0, r5
    beq .Lauto_080DD544
    adds r0, r6, #0
    adds r0, #0x30
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    adds r0, r6, #0
    adds r0, #0x44
    strb r4, [r0]
    adds r0, #2
    strb r7, [r0]
    mov r2, r8
    strb r4, [r2]
    b .Lauto_080DD542
    .byte 0x00, 0x00, 0x05, 0x02, 0x00, 0x00
    .Lauto_080DD510:
    movs r0, #0x80
    lsls r0, r0, #4
    movs r3, #0x47
    adds r3, r3, r6
    mov r8, r3
    cmp r7, r0
    bne .Lauto_080DD544
    movs r5, #0x81
    lsls r5, r5, #2
    ldrh r0, [r6, #4]
    cmp r0, r5
    beq .Lauto_080DD544
    adds r0, r6, #0
    adds r0, #0x30
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    adds r0, r6, #0
    adds r0, #0x44
    movs r1, #0
    strb r4, [r0]
    adds r0, #2
    strb r1, [r0]
    mov r0, r8
    strb r4, [r0]
    .Lauto_080DD542:
    strh r5, [r6, #4]
    .Lauto_080DD544:
    mov r2, sb
    ldrh r1, [r2]
    lsls r1, r1, #0x10
    asrs r1, r1, #0x14
    movs r5, #0xff
    ands r1, r5
    adds r0, r6, #0
    bl func_0803A320
    adds r4, r0, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    mov r3, sb
    ldrh r1, [r3]
    lsls r1, r1, #0x10
    asrs r1, r1, #0x14
    lsls r1, r1, #1
    ands r1, r5
    adds r0, r6, #0
    bl func_0803A334
    lsls r0, r0, #0x10
    adds r1, r6, #0
    adds r1, #0x66
    ldrh r1, [r1]
    mov r2, sb
    ldrh r2, [r2]
    adds r1, r1, r2
    mov r3, sb
    strh r1, [r3]
    lsls r4, r4, #6
    ldr r2, [r6, #0x58]
    adds r2, r2, r4
    str r2, [r6, #0x58]
    asrs r0, r0, #0xa
    ldr r1, [r6, #0x5c]
    adds r1, r1, r0
    str r1, [r6, #0x5c]
    asrs r2, r2, #0x10
    adds r0, r6, #0
    adds r0, #0x54
    strh r2, [r0]
    ldr r0, [r6, #0x5c]
    asrs r0, r0, #0x10
    adds r1, r6, #0
    adds r1, #0x56
    strh r0, [r1]
    ldr r1, [r6, #0x68]
    ldr r0, [pc, #0x10]
    adds r4, r6, #0
    adds r4, #0x60
    cmp r1, r0
    bgt .Lauto_080DD5D2
    movs r2, #0x80
    lsls r2, r2, #6
    adds r0, r1, r2
    b .Lauto_080DD5D0
    .byte 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x00
    .Lauto_080DD5BC:
    ldr r0, [r6, #0x68]
    adds r4, r6, #0
    adds r4, #0x60
    movs r3, #0x47
    adds r3, r3, r6
    mov r8, r3
    cmp r0, #0
    ble .Lauto_080DD5D2
    ldr r1, [pc, #0x38]
    adds r0, r0, r1
    .Lauto_080DD5D0:
    str r0, [r6, #0x68]
    .Lauto_080DD5D2:
    ldrh r0, [r4]
    subs r0, #1
    movs r1, #0
    .byte 0x20, 0x80, 0x00, 0x04, 0x00, 0x28, 0x02, 0xDA, 0x30, 0x1C, 0x62, 0x30, 0x01, 0x70, 0x42, 0x46
    .byte 0x10, 0x78, 0x00, 0x28, 0x0E, 0xD1, 0x30, 0x1C, 0x30, 0x30
    bl UpdateIndexedResourceHandle
    .byte 0x80, 0x07
    .byte 0x00, 0x28, 0x09, 0xDA, 0x31, 0x1C, 0x44, 0x31, 0x01, 0x20, 0x08, 0x70, 0x04, 0xE0, 0x00, 0x00
    .byte 0x00, 0xE0, 0xFF, 0xFF, 0x43, 0x46, 0x19, 0x70, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC
    .byte 0x01, 0xBC, 0x00, 0x47
    .global func_080DDE68
    .thumb_func
func_080DDE68:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDE74
    .thumb_func
func_080DDE74:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #4
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DDE98
    .thumb_func
func_080DDE98:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DDEC4
    .thumb_func
func_080DDEC4:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    movs r2, #0x80
    lsls r2, r2, #6
    bl func_0803A180
    cmp r0, #0
    beq .Lauto_080DD6B6
    ldr r0, [r4, #0x50]
    ldr r1, [pc, #0x2c]
    adds r5, r0, r1
    ldrh r0, [r4, #4]
    cmp r0, r5
    beq .Lauto_080DD6B6
    adds r0, r4, #0
    adds r0, #0x30
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x44
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r2, [r0]
    adds r0, #1
    strb r1, [r0]
    strh r5, [r4, #4]
    .Lauto_080DD6B6:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x06, 0x08, 0x00, 0x00
    .global func_080DDF0C
    .thumb_func
func_080DDF0C:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDF18
    .thumb_func
func_080DDF18:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #3
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DDF3C
    .thumb_func
func_080DDF3C:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #8
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DDF68
    .thumb_func
func_080DDF68:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    movs r2, #0x80
    lsls r2, r2, #7
    bl func_0803A180
    cmp r0, #0
    beq .Lauto_080DD75A
    ldr r0, [r4, #0x50]
    ldr r1, [pc, #0x2c]
    adds r5, r0, r1
    ldrh r0, [r4, #4]
    cmp r0, r5
    beq .Lauto_080DD75A
    adds r0, r4, #0
    adds r0, #0x30
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x44
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r2, [r0]
    adds r0, #1
    strb r1, [r0]
    strh r5, [r4, #4]
    .Lauto_080DD75A:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0xDB, 0x03, 0x00, 0x00
    .global func_080DDFB0
    .thumb_func
func_080DDFB0:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DDFBC
    .thumb_func
func_080DDFBC:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #2
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DDFE0
    .thumb_func
func_080DDFE0:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #8
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DE00C
    .thumb_func
func_080DE00C:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    .byte 0x80, 0x22, 0x12, 0x02, 0x5C, 0xF7, 0xA2, 0xFB, 0x00, 0x28, 0x14, 0xD0, 0x20, 0x6D, 0x05, 0x1C
    .byte 0x10, 0x35, 0xA0, 0x88, 0xA8, 0x42, 0x0E, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x02, 0x70
    .byte 0x01, 0x30, 0x01, 0x70, 0xA5, 0x80, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .global func_080DE050
    .thumb_func
func_080DE050:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DE05C
    .thumb_func
func_080DE05C:
    ldrb r3, [r1]
    movs r2, #0x10
    rsbs r2, r2, #0
    ands r2, r3
    movs r3, #1
    orrs r2, r3
    strb r2, [r1]
    ldr r2, [r0, #0x50]
    str r2, [r1, #4]
    adds r2, r0, #0
    adds r2, #0x54
    ldrh r2, [r2]
    strh r2, [r1, #8]
    adds r0, #0x56
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    bx lr
    .byte 0x00, 0x00
    .global func_080DE080
    .thumb_func
func_080DE080:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r4, #0x54
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp]
    adds r4, r0, #0
    adds r4, #0x56
    movs r5, #0
    ldrsh r4, [r4, r5]
    str r4, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r4, #2
    str r4, [sp, #0xc]
    bl func_08039F90
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DE0AC
    .thumb_func
func_080DE0AC:
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x50
    .byte 0x80, 0x22, 0x12, 0x02, 0x5C, 0xF7, 0x52, 0xFB, 0x00, 0x28, 0x2E, 0xD0, 0x20, 0x1C, 0x62, 0x30
    .byte 0x00, 0x26, 0x86, 0x57, 0x00, 0x2E, 0x13, 0xD1, 0x20, 0x6D, 0x08, 0x49, 0x45, 0x18, 0xA0, 0x88
    .byte 0xA8, 0x42, 0x22, 0xD0, 0x20, 0x1C, 0x30, 0x30, 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C
    .byte 0x44, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x06, 0x70, 0x13, 0xE0, 0xB6, 0x09, 0x00, 0x00
    .byte 0x20, 0x6D, 0x0B, 0x49, 0x45, 0x18, 0xA0, 0x88, 0xA8, 0x42, 0x0E, 0xD0, 0x20, 0x1C, 0x30, 0x30
    .byte 0x29, 0x1C
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x44, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70
    .byte 0x02, 0x30, 0x02, 0x70, 0x01, 0x30, 0x01, 0x70, 0xA5, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .byte 0xBA, 0x09, 0x00, 0x00
    .global func_080DE128
    .thumb_func
func_080DE128:
    push {lr}
    bl func_08039F50
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DE134
    .thumb_func
func_080DE134:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r2, [r0]
    ldr r2, [r2]
    mov sb, r2
    ldr r2, [r1, #8]
    mov r8, r2
    ldr r7, [r1]
    adds r5, r0, #0
    adds r5, #0xc
    ldr r1, [r0, #8]
    lsls r1, r1, #2
    adds r1, r1, r0
    adds r6, r1, #0
    adds r6, #0xc
    cmp r5, r6
    beq .Lauto_080DD92A
    .Lauto_080DD90E:
    ldr r1, [r5]
    cmp r1, #0
    beq .Lauto_080DD924
    ldr r0, [r1, #0x4c]
    ldr r4, [r0, #0x10]
    adds r0, r1, #0
    mov r1, sb
    mov r2, r8
    adds r3, r7, #0
    bl _call_via_r4
    .Lauto_080DD924:
    adds r5, #4
    cmp r5, r6
    bne .Lauto_080DD90E
    .Lauto_080DD92A:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080DE184
    .thumb_func
func_080DE184:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r4, #0xc
    ldr r1, [r0, #8]
    lsls r1, r1, #2
    adds r1, r1, r0
    adds r5, r1, #0
    adds r5, #0xc
    cmp r4, r5
    beq .Lauto_080DD962
    .Lauto_080DD94C:
    ldr r2, [r4]
    cmp r2, #0
    beq .Lauto_080DD95C
    ldr r0, [r2, #0x4c]
    ldr r1, [r0, #0xc]
    adds r0, r2, #0
    bl _call_via_r1
    .Lauto_080DD95C:
    adds r4, #4
    cmp r4, r5
    bne .Lauto_080DD94C
    .Lauto_080DD962:
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080DE1B4
    .thumb_func
func_080DE1B4:
    push {r4, r5, lr}
    sub sp, #0x10
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x14]
    str r0, [r4, #4]
    ldr r0, [r4, #8]
    lsls r0, r0, #2
    adds r0, r0, r4
    adds r0, #0xc
    str r0, [sp, #4]
    adds r0, r4, #0
    adds r0, #0xc
    str r0, [sp, #0xc]
    b .Lauto_080DD9A6
    .byte 0x00, 0x00, 0x14, 0x6B, 0x0E, 0x08
    .Lauto_080DD98C:
    subs r0, r2, #4
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080DD9A0
    ldr r0, [r1, #0x4c]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DD9A0:
    ldr r0, [sp, #4]
    subs r0, #4
    str r0, [sp, #4]
    .Lauto_080DD9A6:
    ldr r2, [sp, #4]
    ldr r0, [sp, #0xc]
    movs r1, #0
    cmp r2, r0
    bne .Lauto_080DD9B2
    movs r1, #1
    .Lauto_080DD9B2:
    cmp r1, #0
    beq .Lauto_080DD98C
    ldr r0, [pc, #0x18]
    str r0, [r4, #4]
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080DD9C8
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080DD9C8:
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .4byte __vt_22EntityVisualController
    .section .text.farming_tutorial_runtime, "ax", %progbits
    .align 2, 0
    .global __thunk_12_OnCall__20FarmingTutorialScenei
    .thumb_func
__thunk_12_OnCall__20FarmingTutorialScenei:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    subs r0, #0xc
    mov r8, r0
    subs r1, #2
    ldr r0, [pc, #0x14]
    cmp r1, r0
    bls .Lauto_080DDA68
    bl loc_080DF834
    .Lauto_080DDA68:
    lsls r0, r1, #2
    ldr r1, [pc, #0xc]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0x41, 0x01, 0x00, 0x00, 0x7C, 0xDA, 0x0D, 0x08, 0x04, 0xEF, 0x0D, 0x08, 0x7A, 0xF0
    .byte 0x0D, 0x08, 0xB8, 0xF0, 0x0D, 0x08, 0xF4, 0xF0, 0x0D, 0x08, 0x50, 0xF1, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0xA2, 0xF1, 0x0D, 0x08, 0x66, 0xF2, 0x0D, 0x08, 0x04, 0xF2, 0x0D, 0x08, 0xC8, 0xF2
    .byte 0x0D, 0x08, 0x2A, 0xF3, 0x0D, 0x08, 0x6A, 0xF3, 0x0D, 0x08, 0xC4, 0xF3, 0x0D, 0x08, 0xD8, 0xF3
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x10, 0xF4, 0x0D, 0x08, 0x76, 0xF4, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xCE, 0xEC, 0x0D, 0x08, 0x9C, 0xED
    .byte 0x0D, 0x08, 0xEC, 0xED, 0x0D, 0x08, 0x12, 0xEE, 0x0D, 0x08, 0x64, 0xEE, 0x0D, 0x08, 0x76, 0xEE
    .byte 0x0D, 0x08, 0xFC, 0xEE, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x84, 0xDF
    .byte 0x0D, 0x08, 0x62, 0xE0, 0x0D, 0x08, 0x30, 0xE1, 0x0D, 0x08, 0x82, 0xE0, 0x0D, 0x08, 0xD8, 0xE0
    .byte 0x0D, 0x08, 0x88, 0xE1, 0x0D, 0x08, 0x58, 0xE2, 0x0D, 0x08, 0x6C, 0xE3, 0x0D, 0x08, 0xC0, 0xE4
    .byte 0x0D, 0x08, 0x68, 0xE5, 0x0D, 0x08, 0x52, 0xE6, 0x0D, 0x08, 0x82, 0xE7, 0x0D, 0x08, 0xEA, 0xE8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xCC, 0xEA
    .byte 0x0D, 0x08, 0xA4, 0xEB, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xA0, 0xEA, 0x0D, 0x08, 0xAA, 0xF4
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xF4, 0xF7, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x22, 0xF7
    .byte 0x0D, 0x08, 0xA6, 0xF7, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x0C, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xEE, 0xF6, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x10, 0xF5, 0x0D, 0x08, 0x34, 0xF5, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0xEC, 0xF4
    .byte 0x0D, 0x08, 0xD8, 0xF4, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8
    .byte 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x34, 0xF8, 0x0D, 0x08, 0x60, 0xF5, 0x0D, 0x08, 0xEA, 0xF5
    .byte 0x0D, 0x08, 0x40, 0xF6, 0x0D, 0x08, 0xB2, 0xF6, 0x0D, 0x08, 0x6E, 0xF7, 0x0D, 0x08, 0x10, 0xF0
    .byte 0x0D, 0x08, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x05, 0x68, 0x06, 0x1C, 0x00, 0x2D, 0x57, 0xD1
    .byte 0xE8, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x78, 0x00, 0x28, 0x29, 0xD1, 0x04, 0x20
    bl __builtin_new
    .byte 0x04, 0x1C, 0x04, 0xA8
    bl __17ObjTileCollection
    .byte 0x05, 0xA8
    bl __20ObjPaletteCollection
    .byte 0x05, 0xA9, 0x01, 0x20, 0x00, 0x90, 0x04, 0xA8, 0x01, 0x90, 0x02, 0x91, 0x20, 0x1C, 0x00, 0x21
    .byte 0x1F, 0x22, 0x00, 0x23
    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
    .byte 0x35, 0x1C, 0x04, 0x1C, 0x30, 0x68, 0x84, 0x42
    .byte 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x2C, 0x60, 0x05, 0xA8
    .byte 0x02, 0x21
    bl _._20ObjPaletteCollection
    .byte 0x04, 0xA8, 0x02, 0x21
    bl _._17ObjTileCollection
    .byte 0x27, 0xE0
    .byte 0x04, 0x20
    bl __builtin_new
    .byte 0x04, 0x1C, 0x04, 0xA8
    bl __17ObjTileCollection
    .byte 0x05, 0xA8
    bl __20ObjPaletteCollection
    .byte 0x05, 0xA8, 0x00, 0x95, 0x04, 0xA9, 0x01, 0x91, 0x02, 0x90, 0x20, 0x1C
    .byte 0x00, 0x21, 0x1F, 0x22, 0x00, 0x23
    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
    .byte 0x35, 0x1C, 0x04, 0x1C, 0x30, 0x68
    .byte 0x84, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x2C, 0x60
    .byte 0x05, 0xA8, 0x02, 0x21
    bl _._20ObjPaletteCollection
    .byte 0x04, 0xA8, 0x02, 0x21
    bl _._17ObjTileCollection
    .byte 0x30, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0xF0, 0xFB, 0x30, 0x68
    .byte 0x72, 0xF7, 0x49, 0xFD, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x02, 0x20, 0x01, 0xF0, 0xE6, 0xFB
    .byte 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0xDF, 0xFB
    .byte 0x72, 0xF7, 0x45, 0xFD, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x03, 0x20, 0x01, 0xF0, 0xD6, 0xFB
    .byte 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x42, 0x46, 0x0C, 0x32, 0x10, 0x69, 0x83, 0x42, 0x06, 0xD8
    .byte 0x51, 0x69, 0x98, 0x00, 0x40, 0x18, 0x91, 0x69, 0x00, 0x68, 0x09, 0x18, 0x00, 0xE0, 0x08, 0x49
    .byte 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0xB7, 0xFB
    .byte 0x40, 0x22, 0x72, 0xF7, 0x3C, 0xFD, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x04, 0x20, 0x01, 0xF0
    .byte 0xAD, 0xFB
    .4byte gText_Fallback_Error
    .byte 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x42, 0x46, 0x0C, 0x32, 0x10, 0x69, 0x83, 0x42, 0x06, 0xD8
    .byte 0x51, 0x69, 0x98, 0x00, 0x40, 0x18, 0x91, 0x69, 0x00, 0x68, 0x09, 0x18, 0x00, 0xE0, 0x09, 0x49
    .byte 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0x8C, 0xFB
    .byte 0x00, 0x22, 0x72, 0xF7, 0x11, 0xFD, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x04, 0x20, 0x01, 0xF0
    .byte 0x82, 0xFB, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x42, 0x46, 0x0C, 0x32, 0x10, 0x69, 0x83, 0x42, 0x06, 0xD8
    .byte 0x51, 0x69, 0x98, 0x00, 0x40, 0x18, 0x91, 0x69, 0x00, 0x68, 0x09, 0x18, 0x00, 0xE0, 0x09, 0x49
    .byte 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1, 0x01, 0xF0, 0x60, 0xFB
    .byte 0x80, 0x22, 0x52, 0x00, 0x72, 0xF7, 0xE4, 0xFC, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x04, 0x20
    .byte 0x01, 0xF0, 0x55, 0xFB
    .4byte gText_Fallback_Error
    .byte 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00
    .byte 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0E, 0x18, 0x00, 0xE0, 0x05, 0x4E, 0x20, 0x69, 0x85, 0x42
    .byte 0x08, 0xD8, 0x61, 0x69, 0xA8, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x0E, 0x4B, 0x00, 0x21, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x02, 0xFB, 0x00, 0x2A, 0x01, 0xD1, 0x01, 0xF0, 0xFE, 0xFA, 0x00, 0x2B, 0x01, 0xD1
    .byte 0x01, 0xF0, 0xFA, 0xFA, 0x00, 0x91, 0x01, 0x91, 0x02, 0x91, 0x31, 0x1C, 0x72, 0xF7, 0xBA, 0xFC
    .byte 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0xED, 0xFA
    .4byte gText_Fallback_Error
    .byte 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x00, 0x68, 0x81, 0x46, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x10, 0x60, 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8
    .byte 0x61, 0x69, 0x98, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x00, 0xE0, 0x05, 0x4D
    .byte 0x20, 0x69, 0x86, 0x42, 0x08, 0xD8, 0x61, 0x69, 0xB0, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68
    .byte 0x0A, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4B, 0x20, 0x69, 0x81, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x4E, 0x46, 0xB0, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x09, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x0D, 0x49, 0x00, 0x24, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x82, 0xFA, 0x00, 0x2A, 0x01, 0xD1, 0x01, 0xF0, 0x7E, 0xFA, 0x00, 0x2B, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x7A, 0xFA, 0x00, 0x29, 0x09, 0xD1, 0x00, 0x94, 0x01, 0x94, 0x02, 0x94, 0x29, 0x1C
    .byte 0x72, 0xF7, 0x38, 0xFC, 0x08, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x91, 0x01, 0x94, 0x02, 0x94, 0x29, 0x1C, 0x72, 0xF7, 0x2E, 0xFC, 0xD9, 0x21, 0x89, 0x00
    .byte 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0x61, 0xFA, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00
    .byte 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x00, 0x68, 0x82, 0x46, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x00, 0x68
    .byte 0x81, 0x46, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00
    .byte 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0E, 0x18, 0x00, 0xE0, 0x05, 0x4E, 0x20, 0x69, 0x85, 0x42
    .byte 0x08, 0xD8, 0x61, 0x69, 0xA8, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4B, 0x20, 0x69, 0x81, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x4F, 0x46, 0xB8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4D, 0x20, 0x69, 0x82, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x57, 0x46, 0xB8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x09, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x0B, 0x49, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x04, 0x68, 0x00, 0x2C, 0x01, 0xD1, 0x01, 0xF0
    .byte 0xE1, 0xF9, 0x00, 0x2A, 0x01, 0xD1, 0x01, 0xF0, 0xDD, 0xF9, 0x00, 0x2B, 0x01, 0xD1, 0x01, 0xF0
    .byte 0xD9, 0xF9, 0x00, 0x2D, 0x06, 0xD1, 0x00, 0x95, 0x01, 0x95, 0x02, 0x95, 0x07, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x29, 0x07, 0xD1, 0x00, 0x95, 0x01, 0x91, 0x02, 0x91, 0x20, 0x1C, 0x31, 0x1C, 0x72, 0xF7
    .byte 0x8D, 0xFB, 0x07, 0xE0, 0x00, 0x95, 0x01, 0x91, 0x00, 0x20, 0x02, 0x90, 0x20, 0x1C, 0x31, 0x1C
    .byte 0x72, 0xF7, 0x84, 0xFB, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0xB7, 0xF9
    .byte 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x40, 0x46
    .byte 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0B, 0x18, 0x00, 0xE0, 0x05, 0x4B, 0x20, 0x69, 0x85, 0x42, 0x09, 0xD8
    .byte 0x61, 0x69, 0xA8, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x0F, 0x4A, 0x00, 0x21, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x7C, 0xF9, 0x00, 0x2B, 0x01, 0xD1, 0x01, 0xF0, 0x78, 0xF9, 0x00, 0x2A, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x74, 0xF9, 0x00, 0x91, 0x01, 0x91, 0x02, 0x91, 0x03, 0x91, 0x19, 0x1C, 0x00, 0x23
    .byte 0x72, 0xF7, 0x20, 0xFB, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0x65, 0xF9
    .4byte gText_Fallback_Error
    .byte 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00
    .byte 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x00, 0xE0, 0x05, 0x4D, 0x20, 0x69, 0x86, 0x42
    .byte 0x08, 0xD8, 0x61, 0x69, 0xB0, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x0E, 0x4B, 0x00, 0x21, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x12, 0xF9, 0x00, 0x2D, 0x01, 0xD1, 0x01, 0xF0, 0x0E, 0xF9, 0x00, 0x2A, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x0A, 0xF9, 0x00, 0x2B, 0x0B, 0xD1, 0x00, 0x93, 0x01, 0x93, 0x02, 0x93, 0x03, 0x93
    .byte 0x29, 0x1C, 0x00, 0x23, 0x72, 0xF7, 0xB4, 0xFA, 0x09, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x91, 0x01, 0x91, 0x02, 0x91, 0x03, 0x91, 0x29, 0x1C, 0x72, 0xF7, 0xA9, 0xFA, 0xD9, 0x21
    .byte 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0xEE, 0xF8, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22
    .byte 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x00, 0x68, 0x81, 0x46
    .byte 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18
    .byte 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x40, 0x46
    .byte 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x00, 0xE0, 0x05, 0x4D, 0x20, 0x69, 0x86, 0x42, 0x09, 0xD8
    .byte 0x61, 0x69, 0xB0, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4B, 0x20, 0x69, 0x81, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x4E, 0x46, 0xB0, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x09, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x0E, 0x49, 0x00, 0x24, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x84, 0xF8, 0x00, 0x2D, 0x01, 0xD1, 0x01, 0xF0, 0x80, 0xF8, 0x00, 0x2A, 0x01, 0xD1
    .byte 0x01, 0xF0, 0x7C, 0xF8, 0x00, 0x2B, 0x0B, 0xD1, 0x00, 0x93, 0x01, 0x93, 0x02, 0x93, 0x03, 0x93
    .byte 0x29, 0x1C, 0x00, 0x23, 0x72, 0xF7, 0x26, 0xFA, 0x13, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x29, 0x07, 0xD1, 0x00, 0x94, 0x01, 0x94, 0x02, 0x94, 0x03, 0x94, 0x29, 0x1C, 0x72, 0xF7
    .byte 0x19, 0xFA, 0x06, 0xE0, 0x00, 0x91, 0x01, 0x94, 0x02, 0x94, 0x03, 0x94, 0x29, 0x1C, 0x72, 0xF7
    .byte 0x11, 0xFA, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x01, 0xF0, 0x56, 0xF8, 0x43, 0x46
    .byte 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18
    .byte 0x00, 0x68, 0x82, 0x46, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x00, 0x68, 0x81, 0x46, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42
    .byte 0x06, 0xD8, 0x61, 0x69, 0x98, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0E, 0x18, 0x00, 0xE0
    .byte 0x05, 0x4E, 0x20, 0x69, 0x85, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xA8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0A, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x87, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB8, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4B, 0x20, 0x69, 0x81, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x4F, 0x46, 0xB8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4D, 0x20, 0x69, 0x82, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x57, 0x46, 0xB8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x09, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x0E, 0x49, 0x00, 0x24, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD1
    .byte 0x00, 0xF0, 0xD4, 0xFF, 0x00, 0x2E, 0x01, 0xD1, 0x00, 0xF0, 0xD0, 0xFF, 0x00, 0x2A, 0x01, 0xD1
    .byte 0x00, 0xF0, 0xCC, 0xFF, 0x00, 0x2B, 0x0B, 0xD1, 0x00, 0x93, 0x01, 0x93, 0x02, 0x93, 0x03, 0x93
    .byte 0x31, 0x1C, 0x00, 0x23, 0x72, 0xF7, 0x76, 0xF9, 0x17, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x2D, 0x01, 0xD1, 0x00, 0x94, 0x02, 0xE0, 0x00, 0x29, 0x07, 0xD1, 0x00, 0x95, 0x01, 0x94
    .byte 0x02, 0x94, 0x03, 0x94, 0x31, 0x1C, 0x72, 0xF7, 0x65, 0xF9, 0x06, 0xE0, 0x00, 0x95, 0x01, 0x91
    .byte 0x02, 0x94, 0x03, 0x94, 0x31, 0x1C, 0x72, 0xF7, 0x5D, 0xF9, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44
    .byte 0x07, 0x20, 0x00, 0xF0, 0xA2, 0xFF, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x00, 0x68, 0x84, 0x46, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x00, 0x68, 0x82, 0x46
    .byte 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18
    .byte 0x00, 0x68, 0x81, 0x46, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x10, 0x60, 0x40, 0x46, 0x0C, 0x30, 0x01, 0x69, 0x04, 0x1C, 0x8B, 0x42, 0x06, 0xD8, 0x61, 0x69
    .byte 0x98, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0F, 0x18, 0x00, 0xE0, 0x05, 0x4F, 0x20, 0x69
    .byte 0x85, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xA8, 0x00, 0x40, 0x18, 0xA1, 0x69, 0x00, 0x68, 0x0A, 0x18
    .byte 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4A, 0x20, 0x69, 0x86, 0x42, 0x09, 0xD8, 0x61, 0x69, 0xB0, 0x00, 0x40, 0x18, 0xA1, 0x69
    .byte 0x00, 0x68, 0x0B, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4B, 0x20, 0x69, 0x81, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x4D, 0x46, 0xA8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0E, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x05, 0x4E, 0x20, 0x69, 0x82, 0x45, 0x09, 0xD8, 0x61, 0x69, 0x55, 0x46, 0xA8, 0x00, 0x40, 0x18
    .byte 0xA1, 0x69, 0x00, 0x68, 0x0D, 0x18, 0x02, 0xE0
    .4byte gText_Fallback_Error
    .byte 0x06, 0x4D, 0x20, 0x69, 0x84, 0x45, 0x0B, 0xD8, 0x60, 0x69, 0x81, 0x46, 0x61, 0x46, 0x88, 0x00
    .byte 0x48, 0x44, 0xA1, 0x69, 0x00, 0x68, 0x09, 0x18, 0x03, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x0E, 0x49, 0xDB, 0x20, 0x80, 0x00, 0x40, 0x44, 0x04, 0x68, 0x00, 0x2C, 0x01, 0xD1, 0x00, 0xF0
    .byte 0x07, 0xFF, 0x00, 0x2F, 0x01, 0xD1, 0x00, 0xF0, 0x03, 0xFF, 0x00, 0x2A, 0x01, 0xD1, 0x00, 0xF0
    .byte 0xFF, 0xFE, 0x00, 0x2B, 0x0C, 0xD1, 0x00, 0x93, 0x01, 0x93, 0x02, 0x93, 0x03, 0x93, 0x20, 0x1C
    .byte 0x39, 0x1C, 0x00, 0x23, 0x72, 0xF7, 0xA8, 0xF8, 0x24, 0xE0, 0x00, 0x00
    .4byte gText_Fallback_Error
    .byte 0x00, 0x2E, 0x04, 0xD1, 0x00, 0x96, 0x01, 0x96, 0x02, 0x96, 0x03, 0x96, 0x0C, 0xE0, 0x00, 0x2D
    .byte 0x04, 0xD1, 0x00, 0x96, 0x01, 0x95, 0x02, 0x95, 0x03, 0x95, 0x05, 0xE0, 0x00, 0x29, 0x08, 0xD1
    .byte 0x00, 0x96, 0x01, 0x95, 0x02, 0x91, 0x03, 0x91, 0x20, 0x1C, 0x39, 0x1C, 0x72, 0xF7, 0x8C, 0xF8
    .byte 0x08, 0xE0, 0x00, 0x96, 0x01, 0x95, 0x02, 0x91, 0x00, 0x20, 0x03, 0x90, 0x20, 0x1C, 0x39, 0x1C
    .byte 0x72, 0xF7, 0x82, 0xF8, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x07, 0x20, 0x00, 0xF0, 0xC7, 0xFE
    .byte 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x10, 0x68, 0x80, 0x00, 0x40, 0x44, 0xC1, 0x6A, 0xE6, 0x20
    .byte 0x80, 0x00, 0x40, 0x44, 0x01, 0x80, 0x10, 0x68, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x38, 0x10, 0x60
    .byte 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x08, 0x20, 0x00, 0xF0, 0xB1, 0xFE, 0x43, 0x46, 0x30, 0x33
    .byte 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x04, 0x68
    .byte 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18
    .byte 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x04, 0x2B, 0x01, 0xD9, 0x00, 0xF0
    .byte 0x97, 0xFE, 0x98, 0x00, 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x10, 0xEB, 0x0D, 0x08
    .byte 0x24, 0xEB, 0x0D, 0x08, 0x2A, 0xEB, 0x0D, 0x08, 0x30, 0xEB, 0x0D, 0x08, 0x34, 0xEB, 0x0D, 0x08
    .byte 0x38, 0xEB, 0x0D, 0x08, 0x02, 0x25, 0x00, 0x23, 0x08, 0xE0, 0x01, 0x25, 0x00, 0x23, 0x05, 0xE0
    .byte 0x02, 0x25, 0x02, 0xE0, 0x01, 0x25, 0x00, 0xE0, 0x00, 0x25, 0x01, 0x23, 0x01, 0x2C, 0x0D, 0xD0
    .byte 0x01, 0x2C, 0x03, 0xDC, 0x00, 0x2C, 0x05, 0xD0, 0x00, 0xF0, 0x72, 0xFE, 0x02, 0x2C, 0x09, 0xD0
    .byte 0x00, 0xF0, 0x6E, 0xFE, 0x00, 0x49, 0x06, 0xE0, 0x12, 0x11, 0x00, 0x00, 0x00, 0x49, 0x02, 0xE0
    .byte 0x89, 0x08, 0x00, 0x00, 0x0D, 0x49, 0xDC, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x2A, 0x1C
    bl EndHardwareBlend
    .byte 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x05, 0x20, 0x08, 0x60, 0xE8, 0x21
    .byte 0x89, 0x00, 0x41, 0x44, 0x00, 0x20, 0x08, 0x70, 0x00, 0x21, 0x02, 0x2D, 0x00, 0xD1, 0x01, 0x21
    .byte 0x03, 0x48, 0x40, 0x44, 0x01, 0x70, 0x00, 0xF0, 0x4B, 0xFE, 0x00, 0x00, 0x44, 0x04, 0x00, 0x00
    .byte 0xA1, 0x03, 0x00, 0x00, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x04, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x10, 0x60, 0x04, 0x2B, 0x01, 0xD9, 0x00, 0xF0, 0x2B, 0xFE, 0x98, 0x00, 0x01, 0x49, 0x40, 0x18
    .byte 0x00, 0x68, 0x87, 0x46, 0xE8, 0xEB, 0x0D, 0x08, 0xFC, 0xEB, 0x0D, 0x08, 0x02, 0xEC, 0x0D, 0x08
    .byte 0x08, 0xEC, 0x0D, 0x08, 0x0C, 0xEC, 0x0D, 0x08, 0x10, 0xEC, 0x0D, 0x08, 0x02, 0x26, 0x00, 0x23
    .byte 0x08, 0xE0, 0x01, 0x26, 0x00, 0x23, 0x05, 0xE0, 0x02, 0x26, 0x02, 0xE0, 0x01, 0x26, 0x00, 0xE0
    .byte 0x00, 0x26, 0x01, 0x23, 0x01, 0x2C, 0x0D, 0xD0, 0x01, 0x2C, 0x03, 0xDC, 0x00, 0x2C, 0x05, 0xD0
    .byte 0x00, 0xF0, 0x06, 0xFE, 0x02, 0x2C, 0x09, 0xD0, 0x00, 0xF0, 0x02, 0xFE, 0x00, 0x49, 0x06, 0xE0
    .byte 0x12, 0x11, 0x00, 0x00, 0x00, 0x49, 0x02, 0xE0, 0x89, 0x08, 0x00, 0x00, 0x1A, 0x49, 0xDC, 0x20
    .byte 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x32, 0x1C
    bl BeginHardwareBlend
    .byte 0xD9, 0x21, 0x89, 0x00
    .byte 0x41, 0x44, 0x06, 0x20, 0x08, 0x60, 0xE8, 0x21, 0x89, 0x00, 0x41, 0x44, 0x00, 0x20, 0x08, 0x70
    .byte 0x00, 0x21, 0x02, 0x2E, 0x00, 0xD1, 0x01, 0x21, 0x10, 0x48, 0x40, 0x44, 0x01, 0x70, 0x45, 0x46
    .byte 0x04, 0x35, 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x04, 0x1C, 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x00, 0x88, 0xE0, 0x22, 0x12, 0x01, 0x11, 0x1C, 0x08, 0x43, 0x20, 0x80, 0x01, 0x2E, 0x0F, 0xD1
    .byte 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x04, 0x1C, 0x50, 0x34, 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x50, 0x30, 0x00, 0x88, 0x80, 0x21, 0x0E, 0xE0, 0x44, 0x04, 0x00, 0x00, 0xA1, 0x03, 0x00, 0x00
    .byte 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x04, 0x1C, 0x50, 0x34, 0x28, 0x1C
    bl GetHardwareDisplayState
    .byte 0x50, 0x30, 0x00, 0x88, 0xC0, 0x21, 0x08, 0x43, 0x20, 0x80, 0x00, 0xF0, 0xB1, 0xFD, 0x43, 0x46
    .byte 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18
    .byte 0x00, 0x68, 0x0B, 0x90, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x04, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x05, 0x68, 0xAA, 0x46, 0xB0, 0x26, 0xB2, 0x44
    .byte 0x04, 0xAE, 0x1C, 0x4F, 0xB9, 0x46, 0x49, 0x46, 0x0B, 0x40, 0x32, 0x88, 0x1A, 0x4D, 0x29, 0x1C
    .byte 0x11, 0x40, 0x19, 0x43, 0x31, 0x80, 0x24, 0x04, 0x22, 0x0C, 0x3F, 0x27, 0xBC, 0x46, 0x61, 0x46
    .byte 0x0A, 0x40, 0x92, 0x00, 0x77, 0x78, 0xB8, 0x46, 0x03, 0x23, 0x19, 0x1C, 0x47, 0x46, 0x39, 0x40
    .byte 0x11, 0x43, 0x71, 0x70, 0xA4, 0x0D, 0x49, 0x46, 0x0C, 0x40, 0x72, 0x88, 0x29, 0x1C, 0x11, 0x40
    .byte 0x21, 0x43, 0x71, 0x80, 0x0B, 0x9C, 0x22, 0x04, 0x11, 0x0C, 0x67, 0x46, 0x39, 0x40, 0x89, 0x00
    .byte 0xF4, 0x78, 0x23, 0x40, 0x0B, 0x43, 0xF3, 0x70, 0x92, 0x0D, 0x49, 0x46, 0x0A, 0x40, 0xB1, 0x88
    .byte 0x0D, 0x40, 0x15, 0x43, 0xB5, 0x80, 0x54, 0x46, 0x22, 0x68, 0x31, 0x1C, 0xF4, 0xF7, 0x9E, 0xF9
    .byte 0x00, 0xF0, 0x50, 0xFD, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x46, 0x46, 0x30, 0x36
    .byte 0xE0, 0x25, 0x6D, 0x00, 0x45, 0x44, 0x29, 0x68, 0x88, 0x00, 0x04, 0x38, 0x30, 0x18, 0x03, 0x68
    .byte 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x28, 0x60, 0x29, 0x68, 0x88, 0x00, 0x04, 0x38, 0x30, 0x18
    .byte 0x02, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x28, 0x60, 0x2C, 0x68, 0xA0, 0x00, 0x04, 0x38
    .byte 0x30, 0x18, 0x06, 0x68, 0x00, 0x2C, 0x01, 0xD0, 0x60, 0x1E, 0x28, 0x60, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x4C, 0x6A, 0x00, 0xF0, 0x26, 0xFC, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x89, 0x6A, 0xF4, 0xF7, 0x66, 0xF9, 0x00, 0x06, 0x00, 0x28
    .byte 0x01, 0xD0, 0x00, 0xF0, 0x15, 0xFD, 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x0A, 0x20, 0x00, 0xF0
    .byte 0x0E, 0xFD, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x11, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x04, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60, 0x11, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x10, 0x60
    .byte 0x20, 0x04, 0x01, 0x0C, 0xDD, 0x20, 0x80, 0x00, 0x40, 0x44, 0x01, 0x2B, 0x4E, 0xD0, 0x01, 0x2B
    .byte 0x03, 0xDC, 0x00, 0x2B, 0x46, 0xD0, 0x00, 0xF0, 0xED, 0xFC, 0x02, 0x2B, 0x01, 0xD0, 0x00, 0xF0
    .byte 0xE9, 0xFC, 0x47, 0xE0, 0xDD, 0x20, 0x80, 0x00, 0x40, 0x44
    bl Stop__23HardwareMusicPlayerSlot
    .byte 0x00, 0xF0
    .byte 0xE1, 0xFC, 0x20, 0x68, 0x29, 0xE0, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44
    .byte 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x07, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x10, 0x60, 0x11, 0x68, 0x88, 0x00, 0x04, 0x38, 0x18, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x10, 0x60, 0xE2, 0x20, 0x80, 0x00, 0x40, 0x44, 0x04, 0x68, 0x45, 0x68, 0x3F, 0x04
    .byte 0xAC, 0x42, 0x08, 0xD0, 0x20, 0x68
    bl IsActive__C23HardwareMusicPlayerSlot
    .byte 0x00, 0x06, 0x00, 0x28, 0xD8, 0xD0
    .byte 0x04, 0x34, 0xAC, 0x42, 0xF6, 0xD1, 0x28, 0x1F, 0x00, 0x68, 0x39, 0x0C, 0x01, 0x2E, 0x0D, 0xD0
    .byte 0x01, 0x2E, 0x03, 0xDC, 0x00, 0x2E, 0x05, 0xD0, 0x00, 0xF0, 0xAC, 0xFC, 0x02, 0x2E, 0x09, 0xD0
    .byte 0x00, 0xF0, 0xA8, 0xFC
    bl Start__23HardwareMusicPlayerSlotUs
    .byte 0x00, 0xF0, 0xA4, 0xFC
    bl StartIfChangedOrInactive__23HardwareMusicPlayerSlotUs
    .byte 0x00, 0xF0, 0xA0, 0xFC
    bl StartOrContinue__23HardwareMusicPlayerSlotUs
    .byte 0x00, 0xF0, 0x9C, 0xFC
    bl func_08008DE8
    .byte 0x00, 0xF0, 0x98, 0xFC, 0x45, 0x46, 0x30, 0x35, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44, 0x19, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x28, 0x18, 0x00, 0x68, 0x0A, 0x90, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x18, 0x60, 0x19, 0x68, 0x88, 0x00, 0x04, 0x38, 0x28, 0x18, 0x00, 0x68, 0x82, 0x46, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x18, 0x60, 0x19, 0x68, 0x88, 0x00, 0x04, 0x38, 0x28, 0x18, 0x04, 0x68
    .byte 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x28, 0x18
    .byte 0x06, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60, 0xDA, 0x25, 0xAD, 0x00, 0x45, 0x44
    .byte 0x28, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x31, 0x1C, 0xF4, 0xF7, 0xB0, 0xF8, 0x07, 0x1C, 0x00, 0x2F
    .byte 0x01, 0xD1, 0x00, 0xF0, 0x5F, 0xFC, 0x28, 0x68, 0x01, 0x68, 0x49, 0x69, 0xF4, 0xF7, 0xA4, 0xF8
    .byte 0x06, 0xA9, 0x21, 0x4D, 0xA8, 0x46, 0x46, 0x46, 0x30, 0x40, 0x0B, 0x88, 0x1F, 0x4D, 0x2A, 0x1C
    .byte 0x1A, 0x40, 0x02, 0x43, 0x0A, 0x80, 0x24, 0x04, 0x22, 0x0C, 0x3F, 0x20, 0x81, 0x46, 0x02, 0x40
    .byte 0x92, 0x00, 0x4E, 0x78, 0x03, 0x23, 0x18, 0x1C, 0x30, 0x40, 0x10, 0x43, 0x48, 0x70, 0xA4, 0x0D
    .byte 0x42, 0x46, 0x14, 0x40, 0x4A, 0x88, 0x28, 0x1C, 0x10, 0x40, 0x20, 0x43, 0x48, 0x80, 0x54, 0x46
    .byte 0x22, 0x04, 0x10, 0x0C, 0x4E, 0x46, 0x30, 0x40, 0x80, 0x00, 0xCC, 0x78, 0x23, 0x40, 0x03, 0x43
    .byte 0xCB, 0x70, 0x92, 0x0D, 0x40, 0x46, 0x02, 0x40, 0x88, 0x88, 0x05, 0x40, 0x15, 0x43, 0x8D, 0x80
    .byte 0x04, 0xAC, 0x20, 0x1C, 0x06, 0x22, 0xF4, 0xF7, 0xB1, 0xF8, 0x0A, 0xA9, 0x09, 0x78, 0xA1, 0x71
    .byte 0x38, 0x1C, 0x04, 0xA9, 0x52, 0xF7, 0x5C, 0xFF, 0x78, 0x69, 0x01, 0x6A, 0x38, 0x1C, 0xF4, 0xF7
    .byte 0x63, 0xF8, 0x00, 0xF0, 0x17, 0xFC, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF
    .byte 0x43, 0x46, 0x30, 0x33, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00, 0x04, 0x38
    .byte 0x18, 0x18, 0x06, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0x0A, 0x68, 0x90, 0x00
    .byte 0x04, 0x38, 0x18, 0x18, 0x05, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0x0A, 0x68
    .byte 0x90, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C, 0xF4, 0xF7
    .byte 0x35, 0xF8, 0x04, 0x1C, 0x00, 0x2C, 0x00, 0xD1, 0xE4, 0xE3, 0x29, 0x1C, 0x53, 0xF7, 0x82, 0xF8
    .byte 0x20, 0x1C, 0x31, 0x1C, 0x53, 0xF7, 0x86, 0xF8, 0xDC, 0xE3, 0x40, 0x46, 0x30, 0x30, 0xE0, 0x22
    .byte 0x52, 0x00, 0x42, 0x44, 0x13, 0x68, 0x99, 0x00, 0x04, 0x39, 0x41, 0x18, 0x0E, 0x68, 0x05, 0x1C
    .byte 0x14, 0x1C, 0x00, 0x2B, 0x01, 0xD0, 0x58, 0x1E, 0x20, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44
    .byte 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x31, 0x1C, 0xF4, 0xF7, 0x10, 0xF8, 0x00, 0x21, 0x00, 0x28
    .byte 0x00, 0xD0, 0x81, 0x68, 0x0A, 0x14, 0x6A, 0xE0, 0x40, 0x46, 0x30, 0x30, 0xE0, 0x22, 0x52, 0x00
    .byte 0x42, 0x44, 0x13, 0x68, 0x99, 0x00, 0x04, 0x39, 0x41, 0x18, 0x0E, 0x68, 0x05, 0x1C, 0x14, 0x1C
    .byte 0x00, 0x2B, 0x01, 0xD0, 0x58, 0x1E, 0x20, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68
    .byte 0x01, 0x68, 0x0A, 0x6C, 0x31, 0x1C, 0xF3, 0xF7, 0xF1, 0xFF, 0x00, 0x21, 0x00, 0x28, 0xE1, 0xD0
    .byte 0xC1, 0x68, 0xDF, 0xE7, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68
    .byte 0x90, 0x00, 0x04, 0x38, 0x18, 0x18, 0x04, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60
    .byte 0x0A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E
    .byte 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C
    .byte 0xF3, 0xF7, 0xCC, 0xFF, 0x01, 0x1C, 0x00, 0x29, 0x00, 0xD1, 0x7B, 0xE3, 0x20, 0x30, 0x00, 0x78
    .byte 0xA0, 0x42, 0x00, 0xD1, 0x76, 0xE3, 0x08, 0x1C, 0x21, 0x1C, 0x52, 0xF7, 0xEF, 0xFE, 0x71, 0xE3
    .byte 0x40, 0x46, 0x30, 0x30, 0xE0, 0x22, 0x52, 0x00, 0x42, 0x44, 0x13, 0x68, 0x99, 0x00, 0x04, 0x39
    .byte 0x41, 0x18, 0x0E, 0x68, 0x05, 0x1C, 0x14, 0x1C, 0x00, 0x2B, 0x01, 0xD0, 0x58, 0x1E, 0x20, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x31, 0x1C, 0xF3, 0xF7
    .byte 0xA5, 0xFF, 0x00, 0x28, 0x02, 0xD0, 0x20, 0x30, 0x02, 0x78, 0x00, 0xE0, 0x00, 0x22, 0x21, 0x68
    .byte 0x63, 0x29, 0x00, 0xD9, 0x4E, 0xE3, 0x88, 0x00, 0x28, 0x18, 0x02, 0x60, 0x48, 0x1C, 0x20, 0x60
    .byte 0x48, 0xE3, 0x44, 0x46, 0x30, 0x34, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44, 0x19, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x20, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x18, 0x60, 0x1A, 0x68
    .byte 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x05, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60
    .byte 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x04, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E
    .byte 0x18, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x21, 0x1C
    .byte 0xF3, 0xF7, 0x6C, 0xFF, 0x00, 0x28, 0x00, 0xD1, 0x1C, 0xE3, 0x32, 0x04, 0x29, 0x1C
    bl StartActorXMotion
    .byte 0x17, 0xE3, 0x44, 0x46, 0x30, 0x34, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44, 0x19, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x20, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x18, 0x60
    .byte 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x05, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E
    .byte 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x04, 0x68, 0x00, 0x2A, 0x01, 0xD0
    .byte 0x50, 0x1E, 0x18, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C
    .byte 0x21, 0x1C, 0xF3, 0xF7, 0x3B, 0xFF, 0x00, 0x28, 0x00, 0xD1, 0xEB, 0xE2, 0x32, 0x04, 0x29, 0x1C
    bl StartActorYMotion
    .byte 0xE6, 0xE2, 0x44, 0x46, 0x30, 0x34, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44
    .byte 0x19, 0x68, 0x88, 0x00, 0x04, 0x38, 0x20, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E
    .byte 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x05, 0x68, 0x00, 0x2A, 0x01, 0xD0
    .byte 0x50, 0x1E, 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x04, 0x68, 0x00, 0x2A
    .byte 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68
    .byte 0x0A, 0x6C, 0x21, 0x1C, 0xF3, 0xF7, 0x0A, 0xFF, 0x00, 0x28, 0x00, 0xD1, 0xBA, 0xE2, 0x29, 0x1C
    .byte 0x32, 0x1C
    bl StartActorXMotion
    .byte 0xB5, 0xE2, 0x44, 0x46, 0x30, 0x34, 0xE0, 0x23, 0x5B, 0x00
    .byte 0x43, 0x44, 0x19, 0x68, 0x88, 0x00, 0x04, 0x38, 0x20, 0x18, 0x06, 0x68, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x05, 0x68, 0x00, 0x2A
    .byte 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x04, 0x68
    .byte 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68
    .byte 0x01, 0x68, 0x0A, 0x6C, 0x21, 0x1C, 0xF3, 0xF7, 0xD9, 0xFE, 0x00, 0x28, 0x00, 0xD1, 0x89, 0xE2
    .byte 0x29, 0x1C, 0x32, 0x1C
    bl StartActorYMotion
    .byte 0x84, 0xE2, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44
    .byte 0x0A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C, 0xF3, 0xF7
    .byte 0xBD, 0xFE, 0xE7, 0x21, 0x89, 0x00, 0x41, 0x44, 0x08, 0x60, 0x00, 0x28, 0x00, 0xD1, 0x67, 0xE2
    .byte 0xD9, 0x21, 0x89, 0x00, 0x41, 0x44, 0x09, 0x20, 0x61, 0xE2, 0x43, 0x46, 0x30, 0x33, 0xE0, 0x21
    .byte 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x18, 0x18, 0x04, 0x68, 0x00, 0x2A
    .byte 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0x0A, 0x68, 0x90, 0x00, 0x04, 0x38, 0x18, 0x18, 0x03, 0x68
    .byte 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68
    .byte 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C, 0xF3, 0xF7, 0x91, 0xFE, 0x01, 0x1C, 0x00, 0x29, 0x00, 0xD1
    .byte 0x40, 0xE2, 0x48, 0x8C, 0xA0, 0x42, 0x00, 0xD1, 0x3C, 0xE2, 0x08, 0x1C, 0x21, 0x1C, 0x52, 0xF7
    .byte 0xC1, 0xFD, 0x37, 0xE2, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x08, 0x68, 0x00, 0x28, 0x00, 0xD1
    .byte 0x30, 0xE2, 0x01, 0x38, 0x08, 0x60, 0x2D, 0xE2, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68
    .byte 0x90, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20
    .byte 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C, 0xF3, 0xF7, 0x66, 0xFE
    .byte 0x00, 0x28, 0x00, 0xD1, 0x16, 0xE2, 0x8D, 0x21, 0x89, 0x00, 0x40, 0xF7, 0x5F, 0xFC, 0x11, 0xE2
    .byte 0x44, 0x46, 0x30, 0x34, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44, 0x19, 0x68, 0x88, 0x00, 0x04, 0x38
    .byte 0x20, 0x18, 0x05, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x18, 0x60, 0x1A, 0x68, 0x90, 0x00
    .byte 0x04, 0x38, 0x20, 0x18, 0x06, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60, 0x1A, 0x68
    .byte 0x90, 0x00, 0x04, 0x38, 0x20, 0x18, 0x04, 0x68, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x21, 0x1C, 0xF3, 0xF7
    .byte 0x35, 0xFE, 0x00, 0x28, 0x00, 0xD1, 0xE5, 0xE1, 0x6A, 0x42, 0x2A, 0x43, 0xD2, 0x0F, 0x31, 0x1C
    .byte 0x52, 0xF7, 0x52, 0xFE, 0xDE, 0xE1, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00
    .byte 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x19, 0x1C, 0xF3, 0xF7, 0x17, 0xFE, 0x00, 0x28
    .byte 0x00, 0xD1, 0xC7, 0xE1, 0x52, 0xF7, 0x5A, 0xFE, 0xC4, 0xE1, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44
    .byte 0x1A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC1, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60
    .byte 0x40, 0x46, 0x0C, 0x30, 0x03, 0x4A, 0x89, 0x00, 0x89, 0x18, 0x09, 0x68, 0x5F, 0xF7, 0x48, 0xFB
    .byte 0xB0, 0xE1, 0x00, 0x00
    .4byte gMaryScriptTable
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x80, 0x31, 0x09, 0x68, 0xF3, 0xF7
    .byte 0xEF, 0xFD, 0xA3, 0xE1, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00, 0x40, 0x44
    .byte 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44
    .byte 0x00, 0x68, 0x01, 0x68, 0x9C, 0x31, 0x22, 0xE0, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68
    .byte 0x90, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20
    .byte 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0xA0, 0x31, 0x10, 0xE0, 0xE0, 0x21, 0x49, 0x00
    .byte 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC3, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E
    .byte 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0xAC, 0x31, 0x0A, 0x68
    .byte 0x19, 0x1C, 0xF3, 0xF7, 0xB7, 0xFD, 0x69, 0xE1, 0x46, 0x46, 0x30, 0x36, 0xE0, 0x25, 0x6D, 0x00
    .byte 0x45, 0x44, 0x29, 0x68, 0x88, 0x00, 0x04, 0x38, 0x30, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0
    .byte 0x48, 0x1E, 0x28, 0x60, 0x29, 0x68, 0x88, 0x00, 0x04, 0x38, 0x30, 0x18, 0x02, 0x68, 0x00, 0x29
    .byte 0x01, 0xD0, 0x48, 0x1E, 0x28, 0x60, 0x2C, 0x68, 0xA0, 0x00, 0x04, 0x38, 0x30, 0x18, 0x01, 0x68
    .byte 0x00, 0x2C, 0x01, 0xD0, 0x60, 0x1E, 0x28, 0x60, 0x2C, 0x68, 0xA0, 0x00, 0x04, 0x38, 0x30, 0x18
    .byte 0x00, 0x68, 0x81, 0x46, 0x00, 0x2C, 0x01, 0xD0, 0x60, 0x1E, 0x28, 0x60, 0x2C, 0x68, 0xA0, 0x00
    .byte 0x04, 0x38, 0x30, 0x18, 0x07, 0x68, 0x00, 0x2C, 0x01, 0xD0, 0x60, 0x1E, 0x28, 0x60, 0xDA, 0x20
    .byte 0x80, 0x00, 0x40, 0x44, 0x05, 0x68, 0x2C, 0x68, 0xB4, 0x34, 0x08, 0xAE, 0x30, 0x1C, 0x2A, 0xF7
    .byte 0xFB, 0xFC, 0x24, 0x68, 0x28, 0x1C, 0x39, 0x1C, 0x4A, 0x46, 0x33, 0x1C, 0xF3, 0xF7, 0x76, 0xFD
    .byte 0x24, 0xE1, 0x46, 0x46, 0x30, 0x36, 0xE0, 0x25, 0x6D, 0x00, 0x45, 0x44, 0x29, 0x68, 0x88, 0x00
    .byte 0x04, 0x38, 0x30, 0x18, 0x03, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x28, 0x60, 0x29, 0x68
    .byte 0x88, 0x00, 0x04, 0x38, 0x30, 0x18, 0x02, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x48, 0x1E, 0x28, 0x60
    .byte 0x2C, 0x68, 0xA0, 0x00, 0x04, 0x38, 0x30, 0x18, 0x06, 0x68, 0x00, 0x2C, 0x01, 0xD0, 0x60, 0x1E
    .byte 0x28, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0xB8, 0x31, 0x0C, 0x68
    .byte 0x31, 0x1C, 0xF3, 0xF7, 0x4B, 0xFD, 0xF9, 0xE0, 0x45, 0x46, 0x30, 0x35, 0xE0, 0x24, 0x64, 0x00
    .byte 0x44, 0x44, 0x22, 0x68, 0x90, 0x00, 0x04, 0x38, 0x28, 0x18, 0x01, 0x68, 0x00, 0x2A, 0x01, 0xD0
    .byte 0x50, 0x1E, 0x20, 0x60, 0x22, 0x68, 0x90, 0x00, 0x04, 0x38, 0x28, 0x18, 0x07, 0x68, 0x00, 0x2A
    .byte 0x01, 0xD0, 0x50, 0x1E, 0x20, 0x60, 0x23, 0x68, 0x98, 0x00, 0x04, 0x38, 0x28, 0x18, 0x06, 0x68
    .byte 0x00, 0x2B, 0x01, 0xD0, 0x58, 0x1E, 0x20, 0x60, 0xDA, 0x25, 0xAD, 0x00, 0x45, 0x44, 0x28, 0x68
    .byte 0x02, 0x68, 0x62, 0x31, 0x12, 0x6C, 0xF3, 0xF7, 0x1D, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x00, 0xD1
    .byte 0xCC, 0xE0, 0x28, 0x68, 0x01, 0x68, 0x49, 0x69, 0xF3, 0xF7, 0x12, 0xFD, 0x01, 0x1C, 0x20, 0x1C
    .byte 0x32, 0x1C, 0x3B, 0x1C, 0x40, 0xF7, 0xAE, 0xFA, 0xC0, 0xE0, 0xE0, 0x23, 0x5B, 0x00, 0x43, 0x44
    .byte 0x1A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC1, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x18, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x02, 0x68, 0x62, 0x31, 0x12, 0x6C, 0xF3, 0xF7
    .byte 0xF9, 0xFC, 0x00, 0x28, 0x00, 0xD1, 0xA9, 0xE0, 0x8D, 0x21, 0x89, 0x00, 0x00, 0x22, 0x00, 0x23
    .byte 0x40, 0xF7, 0x90, 0xFA, 0xA2, 0xE0, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00
    .byte 0x40, 0x44, 0xC4, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5E, 0x21, 0xF3, 0xF7, 0xDB, 0xFC, 0x41, 0x69
    .byte 0x0A, 0x6C, 0x21, 0x1C, 0xF3, 0xF7, 0xD6, 0xFC, 0x81, 0xE0, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44
    .byte 0x0A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC6, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60
    .byte 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5E, 0x21, 0xF3, 0xF7
    .byte 0xC1, 0xFC, 0x04, 0x1C, 0x65, 0x69, 0x04, 0xA8, 0x31, 0x1C, 0x2E, 0xF7, 0x99, 0xFA, 0x04, 0xA8
    .byte 0x2E, 0xF7, 0xB2, 0xFA, 0x01, 0x1C, 0x09, 0x04, 0x09, 0x0C, 0x6B, 0x6C, 0x20, 0x1C, 0x00, 0x22
    .byte 0xF3, 0xF7, 0xB2, 0xFC, 0x5B, 0xE0, 0xE0, 0x21, 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00
    .byte 0x40, 0x44, 0xC4, 0x6A, 0x00, 0x2A, 0x01, 0xD0, 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5E, 0x21, 0xF3, 0xF7, 0x9B, 0xFC, 0x42, 0x69
    .byte 0x21, 0x04, 0x09, 0x0C, 0x53, 0x6C, 0x01, 0x22, 0xF3, 0xF7, 0x96, 0xFC, 0x3F, 0xE0, 0xE0, 0x21
    .byte 0x49, 0x00, 0x41, 0x44, 0x0A, 0x68, 0x90, 0x00, 0x40, 0x44, 0xC7, 0x6A, 0x00, 0x2A, 0x01, 0xD0
    .byte 0x50, 0x1E, 0x08, 0x60, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C
    .byte 0x5E, 0x21, 0xF3, 0xF7, 0x7F, 0xFC, 0x05, 0x1C, 0x6E, 0x69, 0x09, 0xAC, 0x20, 0x1C, 0x39, 0x1C
    .byte 0x2E, 0xF7, 0xAA, 0xFB, 0x20, 0x1C, 0x2E, 0xF7, 0xC1, 0xFB, 0x01, 0x1C, 0x09, 0x04, 0x09, 0x0C
    .byte 0x73, 0x6C, 0x28, 0x1C, 0x00, 0x22, 0xF3, 0xF7, 0x6F, 0xFC, 0x18, 0xE0, 0xDA, 0x20, 0x80, 0x00
    .byte 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5E, 0x21, 0xF3, 0xF7, 0x63, 0xFC, 0x41, 0x69
    .byte 0xC9, 0x6C, 0x0A, 0xE0, 0xDA, 0x20, 0x80, 0x00, 0x40, 0x44, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C
    .byte 0x5E, 0x21, 0xF3, 0xF7, 0x57, 0xFC, 0x41, 0x69, 0x89, 0x6C, 0xF3, 0xF7, 0x51, 0xFC, 0xD9, 0x21
    .byte 0x89, 0x00, 0x41, 0x44, 0x0B, 0x20, 0x08, 0x60, 0x01, 0x20, 0x00, 0xE0
    .global loc_080DF834
    .thumb_func
    loc_080DF834:
    movs r0, #0
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00

    .global Run__20FarmingTutorialScene
    .thumb_func
Run__20FarmingTutorialScene:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xac
    str r0, [sp, #0x7c]
    adds r7, r1, #0
    adds r6, r7, #4
    adds r0, r6, #0
    bl EnableHardwareForcedBlank
    adds r0, r6, #0
    bl GetHardwareDisplayState
    add r2, sp, #0xc
    movs r3, #0x82
    lsls r3, r3, #5
    adds r1, r3, #0
    strh r1, [r2]
    strh r1, [r0]
    adds r0, r6, #0
    bl GetHardwareDisplayState
    add r1, sp, #0xc
    movs r2, #0x3f
    strh r2, [r1]
    adds r0, #0x50
    strh r2, [r0]
    movs r4, #0xe2
    lsls r4, r4, #2
    adds r5, r7, r4
    movs r0, #0xde
    lsls r0, r0, #2
    adds r1, r7, r0
    str r1, [sp, #0x38]
    mov r2, sp
    adds r2, #0x38
    str r2, [sp, #0x80]
    ldr r4, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r4, r0
    beq .Lauto_080DF8D0
    cmp r4, #0
    beq .Lauto_080DF8A4
    str r1, [r4]
    .Lauto_080DF8A4:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    mov sl, r6
    add r3, sp, #0x44
    mov r8, r3
    mov r4, sp
    adds r4, #0x50
    str r4, [sp, #0x9c]
    mov r5, sp
    adds r5, #0x5c
    str r5, [sp, #0xa0]
    adds r0, r7, #0
    adds r0, #0xc
    str r0, [sp, #0x98]
    mov r1, sp
    adds r1, #0x10
    str r1, [sp, #0x94]
    mov r2, sp
    adds r2, #0x68
    str r2, [sp, #0xa4]
    b .Lauto_080DF970
    .Lauto_080DF8D0:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x40]
    ldr r0, [r5]
    subs r0, r4, r0
    asrs r4, r0, #2
    str r4, [sp, #0x3c]
    add r1, sp, #0x40
    add r0, sp, #0x3c
    cmp r4, #1
    bhs .Lauto_080DF8E8
    adds r0, r1, #0
    .Lauto_080DF8E8:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080DF906
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lauto_080DF90A
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lauto_080DF90A
    .Lauto_080DF906:
    movs r0, #0
    mov sb, r0
    .Lauto_080DF90A:
    adds r6, r0, #0
    ldr r1, [r5]
    cmp r8, r1
    beq .Lauto_080DF920
    mov r3, r8
    subs r4, r3, r1
    adds r2, r4, #0
    bl memmove
    adds r0, r0, r4
    b .Lauto_080DF922
    .Lauto_080DF920:
    adds r0, r6, #0
    .Lauto_080DF922:
    adds r4, r0, #0
    ldr r1, [sp, #0x40]
    adds r0, r7, #4
    mov sl, r0
    ldr r2, [r5]
    add r3, sp, #0x44
    mov r8, r3
    mov r0, sp
    adds r0, #0x50
    str r0, [sp, #0x9c]
    mov r3, sp
    adds r3, #0x5c
    str r3, [sp, #0xa0]
    adds r0, r7, #0
    adds r0, #0xc
    str r0, [sp, #0x98]
    subs r3, #0x4c
    str r3, [sp, #0x94]
    mov r0, sp
    adds r0, #0x68
    str r0, [sp, #0xa4]
    cmp r1, #0
    beq .Lauto_080DF95C
    .Lauto_080DF950:
    ldr r3, [sp, #0x80]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080DF950
    .Lauto_080DF95C:
    cmp r2, #0
    beq .Lauto_080DF966
    adds r0, r2, #0
    bl free
    .Lauto_080DF966:
    mov r1, sb
    adds r0, r1, r6
    str r6, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080DF970:
    movs r2, #0xe2
    lsls r2, r2, #2
    adds r5, r7, r2
    movs r3, #0xdf
    lsls r3, r3, #2
    adds r1, r7, r3
    str r1, [sp, #0x44]
    mov r4, r8
    str r4, [sp, #0x84]
    ldr r4, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r4, r0
    beq .Lauto_080DF998
    cmp r4, #0
    beq .Lauto_080DF990
    str r1, [r4]
    .Lauto_080DF990:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    b .Lauto_080DFA16
    .Lauto_080DF998:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x4c]
    ldr r0, [r5]
    subs r0, r4, r0
    asrs r4, r0, #2
    str r4, [sp, #0x48]
    add r1, sp, #0x4c
    add r0, sp, #0x48
    cmp r4, #1
    bhs .Lauto_080DF9B0
    adds r0, r1, #0
    .Lauto_080DF9B0:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080DF9CE
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lauto_080DF9D2
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lauto_080DF9D2
    .Lauto_080DF9CE:
    movs r0, #0
    mov sb, r0
    .Lauto_080DF9D2:
    adds r6, r0, #0
    ldr r1, [r5]
    cmp r8, r1
    beq .Lauto_080DF9EA
    mov r0, r8
    subs r4, r0, r1
    adds r0, r6, #0
    adds r2, r4, #0
    bl memmove
    adds r0, r0, r4
    b .Lauto_080DF9EC
    .Lauto_080DF9EA:
    adds r0, r6, #0
    .Lauto_080DF9EC:
    adds r4, r0, #0
    ldr r1, [sp, #0x4c]
    ldr r2, [r5]
    cmp r1, #0
    beq .Lauto_080DFA02
    .Lauto_080DF9F6:
    ldr r3, [sp, #0x84]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080DF9F6
    .Lauto_080DFA02:
    cmp r2, #0
    beq .Lauto_080DFA0C
    adds r0, r2, #0
    bl free
    .Lauto_080DFA0C:
    mov r1, sb
    adds r0, r1, r6
    str r6, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080DFA16:
    movs r2, #0xe2
    lsls r2, r2, #2
    adds r5, r7, r2
    movs r3, #0xe0
    lsls r3, r3, #2
    adds r1, r7, r3
    str r1, [sp, #0x50]
    ldr r4, [sp, #0x9c]
    str r4, [sp, #0x88]
    ldr r4, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r4, r0
    beq .Lauto_080DFA3E
    cmp r4, #0
    beq .Lauto_080DFA36
    str r1, [r4]
    .Lauto_080DFA36:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    b .Lauto_080DFABC
    .Lauto_080DFA3E:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x58]
    ldr r0, [r5]
    subs r0, r4, r0
    asrs r4, r0, #2
    str r4, [sp, #0x54]
    add r1, sp, #0x58
    add r0, sp, #0x54
    cmp r4, #1
    bhs .Lauto_080DFA56
    adds r0, r1, #0
    .Lauto_080DFA56:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080DFA74
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lauto_080DFA78
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lauto_080DFA78
    .Lauto_080DFA74:
    movs r0, #0
    mov sb, r0
    .Lauto_080DFA78:
    adds r6, r0, #0
    ldr r1, [r5]
    cmp r8, r1
    beq .Lauto_080DFA90
    mov r0, r8
    subs r4, r0, r1
    adds r0, r6, #0
    adds r2, r4, #0
    bl memmove
    adds r0, r0, r4
    b .Lauto_080DFA92
    .Lauto_080DFA90:
    adds r0, r6, #0
    .Lauto_080DFA92:
    adds r4, r0, #0
    ldr r1, [sp, #0x58]
    ldr r2, [r5]
    cmp r1, #0
    beq .Lauto_080DFAA8
    .Lauto_080DFA9C:
    ldr r3, [sp, #0x88]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080DFA9C
    .Lauto_080DFAA8:
    cmp r2, #0
    beq .Lauto_080DFAB2
    adds r0, r2, #0
    bl free
    .Lauto_080DFAB2:
    mov r1, sb
    adds r0, r1, r6
    str r6, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080DFABC:
    movs r2, #0xe2
    lsls r2, r2, #2
    adds r5, r7, r2
    movs r3, #0xe1
    lsls r3, r3, #2
    adds r1, r7, r3
    str r1, [sp, #0x5c]
    ldr r4, [sp, #0xa0]
    str r4, [sp, #0x8c]
    ldr r4, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r4, r0
    beq .Lauto_080DFAE4
    cmp r4, #0
    beq .Lauto_080DFADC
    str r1, [r4]
    .Lauto_080DFADC:
    ldr r0, [r5, #4]
    adds r0, #4
    str r0, [r5, #4]
    b .Lauto_080DFB62
    .Lauto_080DFAE4:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x64]
    ldr r0, [r5]
    subs r0, r4, r0
    asrs r4, r0, #2
    str r4, [sp, #0x60]
    add r1, sp, #0x64
    add r0, sp, #0x60
    cmp r4, #1
    bhs .Lauto_080DFAFC
    adds r0, r1, #0
    .Lauto_080DFAFC:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_080DFB1A
    lsls r4, r0, #2
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lauto_080DFB1E
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lauto_080DFB1E
    .Lauto_080DFB1A:
    movs r0, #0
    mov sb, r0
    .Lauto_080DFB1E:
    adds r6, r0, #0
    ldr r1, [r5]
    cmp r8, r1
    beq .Lauto_080DFB36
    mov r0, r8
    subs r4, r0, r1
    adds r0, r6, #0
    adds r2, r4, #0
    bl memmove
    adds r0, r0, r4
    b .Lauto_080DFB38
    .Lauto_080DFB36:
    adds r0, r6, #0
    .Lauto_080DFB38:
    adds r4, r0, #0
    ldr r1, [sp, #0x64]
    ldr r2, [r5]
    cmp r1, #0
    beq .Lauto_080DFB4E
    .Lauto_080DFB42:
    ldr r3, [sp, #0x8c]
    ldr r0, [r3]
    stm r4!, {r0}
    subs r1, #1
    cmp r1, #0
    bne .Lauto_080DFB42
    .Lauto_080DFB4E:
    cmp r2, #0
    beq .Lauto_080DFB58
    adds r0, r2, #0
    bl free
    .Lauto_080DFB58:
    mov r1, sb
    adds r0, r1, r6
    str r6, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
    .Lauto_080DFB62:
    ldr r2, [pc, #0x17c]
    ldr r1, [pc, #0x17c]
    movs r3, #0xd8
    lsls r3, r3, #2
    adds r0, r7, r3
    ldr r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldr r1, [r0]
    ldr r0, [sp, #0x98]
    bl Load__13AScriptEnginePCv
    movs r4, #0xd9
    lsls r4, r4, #2
    adds r0, r7, r4
    movs r4, #0
    str r4, [r0]
    movs r0, #0xda
    lsls r0, r0, #2
    adds r5, r7, r0
    ldr r0, [sp, #0x94]
    bl func_080AD15C
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0x94]
    str r1, [sp, #0x68]
    ldr r2, [sp, #0xa4]
    str r0, [r2, #4]
    str r4, [r1]
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lauto_080DFBBA
    cmp r1, #0
    beq .Lauto_080DFBBA
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DFBBA:
    str r4, [r5]
    ldr r1, [sp, #0x10]
    cmp r1, #0
    beq .Lauto_080DFBCE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080DFBCE:
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    mov r0, sl
    bl GetHardwareDisplayState
    adds r1, r0, #0
    adds r0, r4, #0
    bl __23HardwareBlendControllerP20HardwareDisplayState
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r5, r7, r3
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .Lauto_080DFBFC
    cmp r0, #0
    beq .Lauto_080DFBFC
    movs r1, #3
    bl _._23HardwareBlendController
    .Lauto_080DFBFC:
    str r4, [r5]
    .global loc_080DFBFE
    .thumb_func
    loc_080DFBFE:
    mov r0, sl
    bl UpdateHardwareInput
    mov r0, sl
    bl GetHardwareCoreState
    ldrh r0, [r0, #8]
    movs r1, #8
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080DFC60
    movs r4, #0xdc
    lsls r4, r4, #2
    adds r5, r7, r4
    ldr r0, [r5]
    bl GetStep__C23HardwareBlendController
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    rsbs r1, r0, #0
    orrs r1, r0
    cmp r1, #0
    blt .Lauto_080DFC60
    movs r0, #0xdb
    lsls r0, r0, #2
    adds r4, r7, r0
    ldr r0, [r4]
    cmp r0, #0
    beq .Lauto_080DFC4A
    bl GetState__C12UiStateOwner
    cmp r0, #1
    beq .Lauto_080DFC60
    ldr r0, [r4]
    bl GetState__C12UiStateOwner
    cmp r0, #2
    beq .Lauto_080DFC60
    .Lauto_080DFC4A:
    ldr r0, [r5]
    ldr r1, [pc, #0x98]
    movs r2, #1
    movs r3, #1
    bl EndHardwareBlend
    movs r2, #0xd9
    lsls r2, r2, #2
    adds r1, r7, r2
    movs r0, #1
    str r0, [r1]
    .Lauto_080DFC60:
    movs r3, #0xdb
    lsls r3, r3, #2
    adds r4, r7, r3
    ldr r0, [r4]
    cmp r0, #0
    beq .Lauto_080DFCC6
    mov r0, sl
    bl GetHardwareCoreState
    ldrh r2, [r0, #8]
    movs r0, #9
    rsbs r0, r0, #0
    .byte 0x10, 0x40, 0x00, 0x06, 0x00, 0x0E, 0x1B, 0x49, 0x11, 0x40, 0x01, 0x43, 0x24, 0x68, 0xA1, 0x46
    .byte 0x05, 0xAD, 0x28, 0x1C
    bl __18HardwareInputStateUi
    .byte 0x50, 0x46
    bl GetHardwareSpriteBuffer
    .byte 0x80, 0x46
    .byte 0x50, 0x46
    bl GetHardwareDisplayState
    .byte 0x06, 0x1C, 0x50, 0x46
    bl GetHardwareCommandList
    .byte 0x04, 0x1C
    .byte 0x50, 0x46
    bl GetHardwareInterruptList
    .byte 0xE0, 0x22, 0x92, 0x00, 0xB9, 0x18, 0x00, 0x94, 0x01, 0x90
    .byte 0x02, 0x91, 0x48, 0x46, 0x29, 0x1C, 0x42, 0x46, 0x33, 0x1C
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
    .Lauto_080DFCC6:
    movs r6, #0
    movs r3, #0xd9
    lsls r3, r3, #2
    adds r0, r7, r3
    ldr r0, [r0]
    cmp r0, #0xb
    bls .Lauto_080DFCD6
    b loc_080DFEFE
    .Lauto_080DFCD6:
    lsls r0, r0, #2
    ldr r1, [pc, #0x14]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .4byte gMaryScriptTable
    .4byte gFarmingTutorialScriptIds
    .byte 0x89, 0x08, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF4, 0xFC, 0x0D, 0x08, 0x24, 0xFD, 0x0D, 0x08
    .byte 0x4E, 0xFD, 0x0D, 0x08, 0x7C, 0xFD, 0x0D, 0x08, 0x92, 0xFD, 0x0D, 0x08, 0xC2, 0xFD, 0x0D, 0x08
    .byte 0x02, 0xFE, 0x0D, 0x08, 0x60, 0xFE, 0x0D, 0x08, 0xDE, 0xFD, 0x0D, 0x08, 0x82, 0xFE, 0x0D, 0x08
    .byte 0x94, 0xFE, 0x0D, 0x08, 0xB2, 0xFE, 0x0D, 0x08, 0xD4, 0xFE, 0x0D, 0x08, 0x01, 0x26, 0xD6, 0x24
    .byte 0xA4, 0x00, 0x38, 0x19, 0x00, 0x68, 0xC1, 0x68, 0x26, 0x98, 0xF3, 0xF7, 0xC9, 0xF9, 0x02, 0x1C
    .byte 0x00, 0x2A, 0x00, 0xD0, 0xDF, 0xE0, 0xD7, 0x25, 0xAD, 0x00, 0x78, 0x19, 0x01, 0x68, 0x02, 0x60
    .byte 0x1F, 0x98, 0x01, 0x60, 0xA2, 0xE1, 0x01, 0x26, 0xDC, 0x21, 0x89, 0x00, 0x78, 0x18, 0x00, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43
    .byte 0xCA, 0x0F, 0x00, 0x2A, 0x00, 0xD0, 0xC8, 0xE0, 0xD7, 0x23, 0x9B, 0x00, 0xF8, 0x18, 0x01, 0x68
    .byte 0x02, 0x60, 0x1F, 0x9C, 0x21, 0x60, 0x8B, 0xE1, 0x01, 0x26, 0xDB, 0x25, 0xAD, 0x00, 0x78, 0x19
    .byte 0x00, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x00, 0xD0, 0xB6, 0xE0, 0x9A, 0xE0, 0x01, 0x26
    .byte 0xDB, 0x21, 0x89, 0x00, 0x7C, 0x18, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x00, 0x28, 0x00, 0xD0
    .byte 0xAB, 0xE0, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._12UiStateOwner
    .byte 0x25, 0x60, 0xD9, 0x22, 0x92, 0x00, 0xB9, 0x18, 0x85, 0xE0, 0x01, 0x26
    .byte 0xDB, 0x23, 0x9B, 0x00, 0xF8, 0x18, 0x00, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x03, 0x28, 0x00, 0xD0
    .byte 0x93, 0xE0, 0xD9, 0x24, 0xA4, 0x00, 0x39, 0x19, 0x77, 0xE0, 0x01, 0x26, 0xDB, 0x25, 0xAD, 0x00
    .byte 0x7C, 0x19, 0x20, 0x68
    bl GetState__C12UiStateOwner
    .byte 0x06, 0x28, 0x00, 0xD1, 0x85, 0xE0, 0x20, 0x68
    bl GetChoiceResult__C12UiStateOwner
    .byte 0x01, 0x1C, 0x38, 0x1C
    bl Push__20FarmingTutorialScenei
    .byte 0x62, 0xE0, 0xDC, 0x21, 0x89, 0x00, 0x78, 0x18, 0x00, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42
    .byte 0x01, 0x43, 0xCC, 0x0F, 0x00, 0x2C, 0x70, 0xD1, 0xE8, 0x22, 0x92, 0x00, 0xB9, 0x18, 0x01, 0x20
    .byte 0x08, 0x70, 0x50, 0x46
    bl GetHardwareDisplayState
    .byte 0x02, 0x88, 0x0A, 0x49, 0x11, 0x40, 0x01, 0x80
    .byte 0x50, 0x46
    bl GetHardwareDisplayState
    .byte 0x50, 0x30, 0x02, 0x88, 0x07, 0x49, 0x11, 0x40, 0x01, 0x80
    .byte 0x50, 0x46
    bl GetHardwareDisplayState
    .byte 0x4C, 0x30, 0x04, 0x80, 0xD9, 0x23, 0x9B, 0x00, 0xF8, 0x18
    .byte 0x04, 0x60, 0x52, 0xE0, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0xDC, 0x24, 0xA4, 0x00
    .byte 0x38, 0x19, 0x00, 0x68
    bl GetStep__C23HardwareBlendController
    .byte 0x00, 0x04, 0x00, 0x14, 0x41, 0x42, 0x01, 0x43
    .byte 0xC9, 0x0F, 0x00, 0x29, 0x41, 0xD1, 0xD9, 0x25, 0xAD, 0x00, 0x78, 0x19, 0x3C, 0xE0, 0xE6, 0x20
    .byte 0x80, 0x00, 0x39, 0x18, 0x08, 0x88, 0x01, 0x38, 0x08, 0x80, 0x00, 0x04, 0x01, 0x0C, 0x2E, 0xE0
    .byte 0xE7, 0x23, 0x9B, 0x00, 0xFC, 0x18, 0x20, 0x68
    bl IsActorAxisMotionComplete
    .byte 0x00, 0x06, 0x00, 0x28
    .byte 0x2B, 0xD0, 0x00, 0x21, 0x21, 0x60, 0xD9, 0x24, 0xA4, 0x00, 0x38, 0x19, 0x24, 0xE0, 0xDA, 0x25
    .byte 0xAD, 0x00, 0x78, 0x19, 0x00, 0x68, 0x01, 0x68, 0x89, 0x6A, 0xF3, 0xF7, 0x03, 0xF9, 0x00, 0x06
    .byte 0x00, 0x28, 0x1A, 0xD0, 0xD9, 0x20, 0x80, 0x00, 0x39, 0x18, 0x00, 0x20, 0x08, 0x60, 0x14, 0xE0
    .byte 0xDA, 0x21, 0x89, 0x00, 0x78, 0x18, 0x00, 0x68, 0x01, 0x68, 0x0A, 0x6C, 0x5E, 0x21, 0xF3, 0xF7
    .byte 0xF3, 0xF8, 0x41, 0x69, 0xC9, 0x6B, 0xF3, 0xF7, 0xED, 0xF8, 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29
    .byte 0x03, 0xD1, 0xD9, 0x22, 0x92, 0x00, 0xB8, 0x18, 0x01, 0x60
    .global loc_080DFEFE
    .thumb_func
    loc_080DFEFE:
    cmp r6, #0
    bne .Lauto_080DFF1C
    mov r0, sl
    bl GetHardwareCoreState
    add r1, sp, #0x70
    str r0, [sp, #0x70]
    movs r3, #0xda
    lsls r3, r3, #2
    adds r0, r7, r3
    ldr r0, [r0]
    ldr r2, [r0]
    ldr r2, [r2, #0xc]
    bl _call_via_r2
    .Lauto_080DFF1C:
    movs r4, #0xe8
    lsls r4, r4, #2
    adds r0, r7, r4
    ldrb r0, [r0]
    cmp r0, #0
    bne .Lauto_080DFF2A
    b .Lauto_080E0048
    .Lauto_080DFF2A:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r2, r0, #0
    ldr r5, [pc, #0x40]
    adds r0, r7, r5
    ldrb r0, [r0]
    ldr r1, [pc, #0x3c]
    cmp r0, #0
    beq .Lauto_080DFF40
    movs r1, #0
    .Lauto_080DFF40:
    adds r6, r2, #0
    add r0, sp, #0xc
    .byte 0xA0, 0x22, 0xD2, 0x04, 0x02, 0x23
    bl __21DmaTransferDescriptorUiPvUi
    .byte 0x68, 0x46, 0x0C, 0x30, 0x24, 0x90
    .byte 0x71, 0x68, 0xF0, 0x68, 0x81, 0x42, 0x0F, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x1C, 0x03, 0xA9
    .byte 0x1C, 0xC9, 0x1C, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x70, 0x68, 0x10, 0x30, 0x70, 0x60, 0x85, 0xE0
    .byte 0xA1, 0x03, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x88, 0x46, 0x01, 0x20, 0x1E, 0x90, 0x30, 0x68
    .byte 0x08, 0x1A, 0x04, 0x11, 0x1D, 0x94, 0x1E, 0xA9, 0x1D, 0xA8, 0x01, 0x2C, 0x00, 0xD2, 0x08, 0x1C
    .byte 0x00, 0x68, 0x20, 0x18, 0x00, 0x28, 0x0A, 0xD0, 0x04, 0x01, 0x20, 0x1C, 0xEF, 0xF7, 0x6C, 0xFD
    .byte 0xA1, 0x46, 0x00, 0x28, 0x05, 0xD1, 0x48, 0x46, 0xF3, 0xF7, 0xE4, 0xF9, 0x01, 0xE0, 0x00, 0x20
    .byte 0x81, 0x46, 0x05, 0x1C, 0x2A, 0x95, 0x32, 0x68, 0xAC, 0x46, 0x42, 0x45, 0x0D, 0xD0, 0x65, 0x46
    .byte 0x00, 0x2D, 0x05, 0xD0, 0x60, 0x46, 0x11, 0x1C, 0x38, 0xC9, 0x38, 0xC0, 0x09, 0x68, 0x01, 0x60
    .byte 0x10, 0x32, 0x10, 0x20, 0x84, 0x44, 0x42, 0x45, 0xF1, 0xD1, 0x65, 0x46, 0x1E, 0x98, 0x01, 0x28
    .byte 0x09, 0xD1, 0x00, 0x2D, 0x05, 0xD0, 0x28, 0x1C, 0x24, 0x99, 0x1C, 0xC9, 0x1C, 0xC0, 0x09, 0x68
    .byte 0x01, 0x60, 0x10, 0x35, 0x13, 0xE0, 0x80, 0x46, 0x2A, 0x1C, 0x00, 0x28, 0x0E, 0xD0, 0x00, 0x2A
    .byte 0x05, 0xD0, 0x10, 0x1C, 0x24, 0x99, 0x38, 0xC9, 0x38, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x01, 0x25
    .byte 0x6D, 0x42, 0xA8, 0x44, 0x10, 0x32, 0x40, 0x46, 0x00, 0x28, 0xF0, 0xD1, 0x15, 0x1C, 0x72, 0x68
    .byte 0x30, 0x68, 0x01, 0x1C, 0x90, 0x42, 0x02, 0xD0, 0x10, 0x31, 0x91, 0x42, 0xFC, 0xD1, 0x00, 0x28
    .byte 0x01, 0xD0, 0xEF, 0xF7, 0x55, 0xFD, 0x2A, 0x98, 0x48, 0x44, 0x2A, 0x99, 0x31, 0x60, 0x75, 0x60
    .byte 0xF0, 0x60, 0x1B, 0xE0
    .Lauto_080E0048:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    mov r0, sl
    bl GetHardwareDisplayState
    adds r5, r0, #0
    mov r0, sl
    bl GetHardwareSpriteBuffer
    adds r4, r0, #0
    mov r0, sl
    bl GetHardwareCommandList
    str r6, [sp, #0xc]
    str r5, [sp, #0x10]
    str r4, [sp, #0x14]
    str r0, [sp, #0x18]
    movs r2, #0xda
    lsls r2, r2, #2
    adds r0, r7, r2
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r2, [r1, #0x10]
    add r1, sp, #0xc
    bl _call_via_r2
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r0, r7, r3
    ldr r0, [r0]
    bl Update__23HardwareBlendController
    mov r0, sl
    bl UpdateHardwareFrame
    b loc_080DFBFE
    .byte 0x1F, 0x98, 0x2B, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00
    .section .text.map_clock_status_lifecycle_after, "ax", %progbits
    .align 2, 0
    .global func_080E0E80
    .thumb_func
func_080E0E80:
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    adds r7, r2, #0
    subs r3, r1, r6
    .Lauto_080E0628:
    cmp r3, #0
    ble .Lauto_080E064C
    asrs r2, r3, #1
    adds r5, r6, r2
    ldrb r1, [r5]
    movs r4, #0
    ldr r0, [r7]
    cmp r1, r0
    bhs .Lauto_080E063C
    movs r4, #1
    .Lauto_080E063C:
    cmp r4, #0
    beq .Lauto_080E0648
    adds r6, r5, #1
    subs r0, r3, r2
    subs r3, r0, #1
    b .Lauto_080E0628
    .Lauto_080E0648:
    adds r3, r2, #0
    b .Lauto_080E0628
    .Lauto_080E064C:
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    .else

    .section .text.game_scene_state_callbacks_after, "ax", %progbits

	thumb_func_start sub_080D8178
sub_080D8178: @ 0x080D8178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, .L080D82D8 @ =0xFFFFFA70
	add sp, r4
	ldr r2, .L080D82DC @ =0x000004DC
	add r2, sp
	str r0, [r2]
	mov sl, r1
	add r0, sp, #0x10
	movs r1, #0x1e
	movs r2, #4
	bl __18HardwareInputStateUsUs
	add r6, sp, #0x34
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x20
	bl __25HardwareSpriteBufferStateUcUc
	mov r7, sl
	adds r7, #0x10
	movs r2, #0
	mov r3, sl
	ldrh r0, [r3, #0x10]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r3, #0x10]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	str r2, [r4]
	str r2, [r4, #4]
	ldr r0, .L080D82E0 @ =__vt_22HardwareDisplayCommand
	str r0, [r4, #8]
	str r7, [r4, #0xc]
	mov r5, sl
	adds r5, #0x68
	adds r0, r5, #0
	bl func_08008AE0
	ldr r1, [r0, #8]
	ldr r2, [r1, #0x10]
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r5, #0
	bl WaitForHardwareVBlank
	adds r0, r4, #0
	movs r1, #2
	bl func_080098AC
	movs r1, #0x87
	lsls r1, r1, #3
	add r1, sp
	movs r5, #0xf2
	lsls r5, r5, #5
	adds r0, r5, #0
	strh r0, [r1]
	ldrh r0, [r4]
	mov r2, sl
	strh r0, [r2, #0x10]
	movs r0, #0x3f
	strh r0, [r1]
	mov r1, sl
	adds r1, #0x60
	ldrh r0, [r4]
	strh r0, [r1]
	mov r5, sl
	adds r5, #0xd0
	adds r2, #0xc0
	ldr r0, .L080D82E4 @ =0x0000046C
	add r0, sp
	str r2, [r0]
	ldr r3, .L080D82E4 @ =0x0000046C
	add r3, sp
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	ldr r1, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r1, r0
	beq .L080D8308
	cmp r1, #0
	beq .L080D822C
	str r2, [r1]
.L080D822C:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	ldr r1, .L080D82E8 @ =0x00000544
	add r1, sp
	str r7, [r1]
	adds r6, r5, #0
	movs r2, #0xc4
	add r2, sl
	mov r8, r2
	movs r3, #0x8f
	lsls r3, r3, #3
	add r3, sp
	movs r4, #0xa7
	lsls r4, r4, #3
	add r4, sp
	str r3, [r4]
	mov r5, sl
	adds r5, #0xc8
	ldr r7, .L080D82EC @ =0x0000056C
	add r7, sp
	str r5, [r7]
	ldr r0, .L080D82F0 @ =0x00000484
	add r0, sp
	ldr r1, .L080D82F4 @ =0x0000053C
	add r1, sp
	str r0, [r1]
	mov r2, sl
	adds r2, #0xcc
	movs r3, #0xae
	lsls r3, r3, #3
	add r3, sp
	str r2, [r3]
	movs r4, #0x92
	lsls r4, r4, #3
	add r4, sp
	movs r5, #0xa8
	lsls r5, r5, #3
	add r5, sp
	str r4, [r5]
	mov r7, sl
	adds r7, #0xa0
	ldr r0, .L080D82F8 @ =0x0000055C
	add r0, sp
	str r7, [r0]
	mov r1, sl
	adds r1, #0x8c
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	str r1, [r2]
	mov r3, sl
	adds r3, #0xb0
	movs r4, #0xad
	lsls r4, r4, #3
	add r4, sp
	str r3, [r4]
	mov r5, sl
	adds r5, #0x90
	ldr r7, .L080D82FC @ =0x00000554
	add r7, sp
	str r5, [r7]
	mov r0, sl
	adds r0, #0xa8
	ldr r1, .L080D8300 @ =0x00000564
	add r1, sp
	str r0, [r1]
	mov r2, sl
	adds r2, #0x88
	ldr r3, .L080D8304 @ =0x0000054C
	add r3, sp
	str r2, [r3]
	mov r4, sl
	adds r4, #0x9c
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	str r4, [r5]
	mov r7, sl
	adds r7, #0xa4
	movs r0, #0xac
	lsls r0, r0, #3
	add r0, sp
	str r7, [r0]
	b .L080D843A
	.align 2, 0
.L080D82D8: .4byte 0xFFFFFA70
.L080D82DC: .4byte 0x000004DC
.L080D82E0: .4byte __vt_22HardwareDisplayCommand
.L080D82E4: .4byte 0x0000046C
.L080D82E8: .4byte 0x00000544
.L080D82EC: .4byte 0x0000056C
.L080D82F0: .4byte 0x00000484
.L080D82F4: .4byte 0x0000053C
.L080D82F8: .4byte 0x0000055C
.L080D82FC: .4byte 0x00000554
.L080D8300: .4byte 0x00000564
.L080D8304: .4byte 0x0000054C
.L080D8308:
	adds r6, r1, #0
	movs r0, #1
	ldr r1, .L080D8350 @ =0x00000474
	add r1, sp
	str r0, [r1]
	ldr r0, [r5]
	subs r0, r6, r0
	asrs r4, r0, #2
	movs r0, #0x8e
	lsls r0, r0, #3
	add r0, sp
	str r4, [r0]
	ldr r2, .L080D8350 @ =0x00000474
	add r2, sp
	ldr r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #3
	add r1, sp
	cmp r4, r0
	bhs .L080D8332
	adds r1, r2, #0
.L080D8332:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080D8354
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080D8358
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080D8358
	.align 2, 0
.L080D8350: .4byte 0x00000474
.L080D8354:
	movs r0, #0
	mov sb, r0
.L080D8358:
	adds r7, r0, #0
	ldr r1, [r5]
	cmp r6, r1
	beq .L080D836C
	subs r4, r6, r1
	adds r2, r4, #0
	bl memmove
	adds r4, r0, r4
	b .L080D836E
.L080D836C:
	adds r4, r7, #0
.L080D836E:
	ldr r0, .L080D846C @ =0x00000474
	add r0, sp
	ldr r1, [r0]
	mov r2, sl
	adds r2, #0x10
	ldr r3, .L080D8470 @ =0x00000544
	add r3, sp
	str r2, [r3]
	mov r6, sl
	adds r6, #0xd0
	ldr r2, [r5]
	movs r0, #0xc4
	add r0, sl
	mov r8, r0
	movs r3, #0x8f
	lsls r3, r3, #3
	add r3, sp
	movs r0, #0xa7
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	mov r3, sl
	adds r3, #0xc8
	ldr r0, .L080D8474 @ =0x0000056C
	add r0, sp
	str r3, [r0]
	ldr r3, .L080D8478 @ =0x00000484
	add r3, sp
	ldr r0, .L080D847C @ =0x0000053C
	add r0, sp
	str r3, [r0]
	mov r3, sl
	adds r3, #0xcc
	movs r0, #0xae
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	movs r3, #0x92
	lsls r3, r3, #3
	add r3, sp
	movs r0, #0xa8
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	mov r3, sl
	adds r3, #0xa0
	ldr r0, .L080D8480 @ =0x0000055C
	add r0, sp
	str r3, [r0]
	subs r3, #0x14
	movs r0, #0xaa
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	adds r3, #0x24
	movs r0, #0xad
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	subs r3, #0x20
	ldr r0, .L080D8484 @ =0x00000554
	add r0, sp
	str r3, [r0]
	adds r3, #0x18
	ldr r0, .L080D8488 @ =0x00000564
	add r0, sp
	str r3, [r0]
	subs r3, #0x20
	ldr r0, .L080D848C @ =0x0000054C
	add r0, sp
	str r3, [r0]
	adds r3, #0x14
	movs r0, #0xab
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	adds r3, #8
	movs r0, #0xac
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	cmp r1, #0
	beq .L080D8426
.L080D8414:
	movs r3, #0x9c
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080D8414
.L080D8426:
	cmp r2, #0
	beq .L080D8430
	adds r0, r2, #0
	bl free
.L080D8430:
	mov r1, sb
	adds r0, r1, r7
	str r7, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080D843A:
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #3
	add r0, sp
	mov r2, r8
	str r2, [r0]
	movs r3, #0xa7
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r4, .L080D8490 @ =0x000004E4
	add r4, sp
	str r3, [r4]
	ldr r4, [r6, #4]
	ldr r0, [r6, #0xc]
	cmp r4, r0
	beq .L080D8494
	cmp r4, #0
	beq .L080D8462
	str r2, [r4]
.L080D8462:
	ldr r0, [r6, #4]
	adds r0, #4
	str r0, [r6, #4]
	b .L080D8532
	.align 2, 0
.L080D846C: .4byte 0x00000474
.L080D8470: .4byte 0x00000544
.L080D8474: .4byte 0x0000056C
.L080D8478: .4byte 0x00000484
.L080D847C: .4byte 0x0000053C
.L080D8480: .4byte 0x0000055C
.L080D8484: .4byte 0x00000554
.L080D8488: .4byte 0x00000564
.L080D848C: .4byte 0x0000054C
.L080D8490: .4byte 0x000004E4
.L080D8494:
	adds r7, r4, #0
	movs r0, #1
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sp
	str r0, [r1]
	ldr r0, [r6]
	subs r0, r7, r0
	asrs r4, r0, #2
	ldr r0, .L080D84DC @ =0x0000047C
	add r0, sp
	str r4, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	add r2, sp
	ldr r0, [r1]
	ldr r1, .L080D84DC @ =0x0000047C
	add r1, sp
	cmp r4, r0
	bhs .L080D84BE
	adds r1, r2, #0
.L080D84BE:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080D84E0
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov r8, r4
	cmp r0, #0
	bne .L080D84E4
	mov r0, r8
	bl RetryMemoryAllocation
	b .L080D84E4
	.align 2, 0
.L080D84DC: .4byte 0x0000047C
.L080D84E0:
	movs r0, #0
	mov r8, r0
.L080D84E4:
	adds r5, r0, #0
	mov r4, sb
	ldr r1, [r4]
	cmp r7, r1
	beq .L080D84FA
	subs r4, r7, r1
	adds r2, r4, #0
	bl memmove
	adds r4, r0, r4
	b .L080D84FC
.L080D84FA:
	adds r4, r5, #0
.L080D84FC:
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, sp
	ldr r1, [r0]
	mov r7, sb
	ldr r2, [r7]
	cmp r1, #0
	beq .L080D851C
.L080D850C:
	ldr r3, .L080D8564 @ =0x000004E4
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080D850C
.L080D851C:
	cmp r2, #0
	beq .L080D8526
	adds r0, r2, #0
	bl free
.L080D8526:
	mov r7, r8
	adds r0, r7, r5
	mov r1, sb
	str r5, [r1]
	str r4, [r1, #4]
	str r0, [r1, #0xc]
.L080D8532:
	mov sb, r6
	ldr r0, .L080D8568 @ =0x00000484
	add r0, sp
	ldr r2, .L080D856C @ =0x0000056C
	add r2, sp
	ldr r2, [r2]
	str r2, [r0]
	ldr r3, .L080D8570 @ =0x0000053C
	add r3, sp
	ldr r3, [r3]
	movs r4, #0x9d
	lsls r4, r4, #3
	add r4, sp
	str r3, [r4]
	ldr r4, [r6, #4]
	ldr r0, [r6, #0xc]
	cmp r4, r0
	beq .L080D8574
	cmp r4, #0
	beq .L080D855C
	str r2, [r4]
.L080D855C:
	ldr r0, [r6, #4]
	adds r0, #4
	str r0, [r6, #4]
	b .L080D8614
	.align 2, 0
.L080D8564: .4byte 0x000004E4
.L080D8568: .4byte 0x00000484
.L080D856C: .4byte 0x0000056C
.L080D8570: .4byte 0x0000053C
.L080D8574:
	adds r7, r4, #0
	movs r0, #1
	ldr r1, .L080D85BC @ =0x0000048C
	add r1, sp
	str r0, [r1]
	ldr r0, [r6]
	subs r0, r7, r0
	asrs r4, r0, #2
	movs r0, #0x91
	lsls r0, r0, #3
	add r0, sp
	str r4, [r0]
	ldr r2, .L080D85BC @ =0x0000048C
	add r2, sp
	ldr r0, [r1]
	movs r1, #0x91
	lsls r1, r1, #3
	add r1, sp
	cmp r4, r0
	bhs .L080D859E
	adds r1, r2, #0
.L080D859E:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080D85C0
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov r8, r4
	cmp r0, #0
	bne .L080D85C4
	mov r0, r8
	bl RetryMemoryAllocation
	b .L080D85C4
	.align 2, 0
.L080D85BC: .4byte 0x0000048C
.L080D85C0:
	movs r0, #0
	mov r8, r0
.L080D85C4:
	adds r5, r0, #0
	mov r0, sb
	ldr r1, [r0]
	cmp r7, r1
	beq .L080D85DC
	subs r4, r7, r1
	adds r0, r5, #0
	adds r2, r4, #0
	bl memmove
	adds r4, r0, r4
	b .L080D85DE
.L080D85DC:
	adds r4, r5, #0
.L080D85DE:
	ldr r0, .L080D8648 @ =0x0000048C
	add r0, sp
	ldr r1, [r0]
	mov r3, sb
	ldr r2, [r3]
	cmp r1, #0
	beq .L080D85FE
.L080D85EC:
	movs r7, #0x9d
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080D85EC
.L080D85FE:
	cmp r2, #0
	beq .L080D8608
	adds r0, r2, #0
	bl free
.L080D8608:
	mov r1, r8
	adds r0, r1, r5
	mov r2, sb
	str r5, [r2]
	str r4, [r2, #4]
	str r0, [r2, #0xc]
.L080D8614:
	adds r5, r6, #0
	movs r0, #0x92
	lsls r0, r0, #3
	add r0, sp
	movs r3, #0xae
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	str r3, [r0]
	movs r4, #0xa8
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	mov sb, r4
	ldr r4, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r4, r0
	beq .L080D864C
	cmp r4, #0
	beq .L080D863E
	str r3, [r4]
.L080D863E:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	b .L080D86E0
	.align 2, 0
.L080D8648: .4byte 0x0000048C
.L080D864C:
	adds r7, r4, #0
	movs r0, #1
	movs r1, #0x93
	lsls r1, r1, #3
	add r1, sp
	str r0, [r1]
	ldr r0, [r5]
	subs r0, r7, r0
	asrs r4, r0, #2
	ldr r0, .L080D8694 @ =0x00000494
	add r0, sp
	str r4, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	add r2, sp
	ldr r0, [r1]
	ldr r1, .L080D8694 @ =0x00000494
	add r1, sp
	cmp r4, r0
	bhs .L080D8676
	adds r1, r2, #0
.L080D8676:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080D8698
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov r8, r4
	cmp r0, #0
	bne .L080D869C
	mov r0, r8
	bl RetryMemoryAllocation
	b .L080D869C
	.align 2, 0
.L080D8694: .4byte 0x00000494
.L080D8698:
	movs r0, #0
	mov r8, r0
.L080D869C:
	adds r6, r0, #0
	ldr r1, [r5]
	cmp r7, r1
	beq .L080D86B0
	subs r4, r7, r1
	adds r2, r4, #0
	bl memmove
	adds r4, r0, r4
	b .L080D86B2
.L080D86B0:
	adds r4, r6, #0
.L080D86B2:
	movs r0, #0x93
	lsls r0, r0, #3
	add r0, sp
	ldr r1, [r0]
	ldr r2, [r5]
	cmp r1, #0
	beq .L080D86CC
.L080D86C0:
	mov r7, sb
	ldr r0, [r7]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080D86C0
.L080D86CC:
	cmp r2, #0
	beq .L080D86D6
	adds r0, r2, #0
	bl free
.L080D86D6:
	mov r1, r8
	adds r0, r1, r6
	str r6, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080D86E0:
	movs r0, #4
	bl __builtin_new
	ldr r2, .L080D87FC @ =0x00000544
	add r2, sp
	ldr r1, [r2]
	bl __23HardwareBlendControllerP20HardwareDisplayState
	ldr r3, .L080D8800 @ =0x0000055C
	add r3, sp
	ldr r5, [r3]
	adds r4, r0, #0
	adds r6, r5, #0
	ldr r0, [r6]
	cmp r4, r0
	beq .L080D870A
	cmp r0, #0
	beq .L080D870A
	movs r1, #3
	bl _._23HardwareBlendController
.L080D870A:
	str r4, [r5]
	movs r0, #0x68
	bl __builtin_new
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r1, [r7]
	bl __22GameSceneTextVariablesP18GameStateSaveImage
	movs r1, #0xad
	lsls r1, r1, #3
	add r1, sp
	ldr r5, [r1]
	adds r4, r0, #0
	ldr r1, [r5]
	cmp r4, r1
	beq .L080D8740
	cmp r1, #0
	beq .L080D8740
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8740:
	str r4, [r5]
	ldr r2, .L080D8804 @ =0x00000554
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	cmp r0, #0x2a
	bne .L080D8814
	mov r0, sl
	adds r0, #0x94
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq .L080D8814
	ldr r3, .L080D8808 @ =0x00000564
	add r3, sp
	ldr r5, [r3]
	movs r4, #0xaa
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r1, [r4]
	ldr r7, .L080D880C @ =0x0000054C
	add r7, sp
	ldr r7, [r7]
	ldr r2, [r7]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	adds r0, r4, #0
	movs r3, #0
	bl CreateGameWorld
	ldr r2, [r4]
	ldr r1, .L080D8810 @ =0x0000049C
	add r1, sp
	ldr r0, .L080D8810 @ =0x0000049C
	add r0, sp
	str r4, [r0]
	str r2, [r1, #4]
	movs r0, #0
	str r0, [r4]
	adds r4, r2, #0
	ldr r0, .L080D8808 @ =0x00000564
	add r0, sp
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r4, r1
	beq .L080D87B0
	cmp r1, #0
	beq .L080D87B0
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D87B0:
	str r4, [r5]
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	ldr r1, [r0]
	cmp r1, #0
	beq .L080D87CA
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D87CA:
	ldr r1, [r6]
	lsls r1, r1, #8
	lsrs r1, r1, #0x10
	mov r0, sl
	adds r0, #0x98
	movs r2, #0
	ldrsh r5, [r0, r2]
	adds r0, #2
	movs r3, #0
	ldrsh r4, [r0, r3]
	mov r0, sl
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080DC2B4
	movs r0, #0
	str r0, [sp]
	mov r0, sl
	movs r1, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080DC360
	b .L080D8884
	.align 2, 0
.L080D87FC: .4byte 0x00000544
.L080D8800: .4byte 0x0000055C
.L080D8804: .4byte 0x00000554
.L080D8808: .4byte 0x00000564
.L080D880C: .4byte 0x0000054C
.L080D8810: .4byte 0x0000049C
.L080D8814:
	ldr r4, .L080D88A8 @ =0x00000564
	add r4, sp
	ldr r5, [r4]
	movs r6, #0xaa
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	ldr r1, [r6]
	ldr r7, .L080D88AC @ =0x0000054C
	add r7, sp
	ldr r7, [r7]
	ldr r2, [r7]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	adds r0, r4, #0
	movs r3, #1
	bl CreateGameWorld
	ldr r2, [r4]
	ldr r1, .L080D88B0 @ =0x000004A4
	add r1, sp
	ldr r0, .L080D88B0 @ =0x000004A4
	add r0, sp
	str r4, [r0]
	str r2, [r1, #4]
	movs r0, #0
	str r0, [r4]
	adds r4, r2, #0
	ldr r0, .L080D88A8 @ =0x00000564
	add r0, sp
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r4, r1
	beq .L080D886A
	cmp r1, #0
	beq .L080D886A
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D886A:
	str r4, [r5]
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	ldr r1, [r0]
	cmp r1, #0
	beq .L080D8884
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8884:
	movs r0, #0
	movs r1, #0xab
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	str r0, [r1]
	ldr r2, .L080D88B4 @ =0x00000554
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	cmp r0, #0x2f
	bls .L080D889E
	b .L080D8FE8
.L080D889E:
	lsls r0, r0, #2
	ldr r1, .L080D88B8 @ =.L080D88BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D88A8: .4byte 0x00000564
.L080D88AC: .4byte 0x0000054C
.L080D88B0: .4byte 0x000004A4
.L080D88B4: .4byte 0x00000554
.L080D88B8: .4byte .L080D88BC
.L080D88BC: @ jump table
	.4byte .L080D897C @ case 0
	.4byte .L080D89D4 @ case 1
	.4byte .L080D8FE8 @ case 2
	.4byte .L080D8BC8 @ case 3
	.4byte .L080D8B6E @ case 4
	.4byte .L080D8C30 @ case 5
	.4byte .L080D8C8C @ case 6
	.4byte .L080D8AC4 @ case 7
	.4byte .L080D8B20 @ case 8
	.4byte .L080D8CE8 @ case 9
	.4byte .L080D8DE0 @ case 10
	.4byte .L080D8DE0 @ case 11
	.4byte .L080D8DE0 @ case 12
	.4byte .L080D8DE0 @ case 13
	.4byte .L080D8DE0 @ case 14
	.4byte .L080D8DE0 @ case 15
	.4byte .L080D8DE0 @ case 16
	.4byte .L080D8DE0 @ case 17
	.4byte .L080D8DE0 @ case 18
	.4byte .L080D8DE0 @ case 19
	.4byte .L080D8DE0 @ case 20
	.4byte .L080D8DE0 @ case 21
	.4byte .L080D8DE0 @ case 22
	.4byte .L080D8DE0 @ case 23
	.4byte .L080D8DE0 @ case 24
	.4byte .L080D8DE0 @ case 25
	.4byte .L080D8DE0 @ case 26
	.4byte .L080D8DE0 @ case 27
	.4byte .L080D8DE0 @ case 28
	.4byte .L080D8DE0 @ case 29
	.4byte .L080D8DE0 @ case 30
	.4byte .L080D8DE0 @ case 31
	.4byte .L080D8E24 @ case 32
	.4byte .L080D8FA8 @ case 33
	.4byte .L080D8FA8 @ case 34
	.4byte .L080D8FA8 @ case 35
	.4byte .L080D8FA8 @ case 36
	.4byte .L080D8E6C @ case 37
	.4byte .L080D8DE0 @ case 38
	.4byte .L080D8F3C @ case 39
	.4byte .L080D8DE0 @ case 40
	.4byte .L080D8DA4 @ case 41
	.4byte .L080D8DE0 @ case 42
	.4byte .L080D8DE0 @ case 43
	.4byte .L080D8DE0 @ case 44
	.4byte .L080D8EF4 @ case 45
	.4byte .L080D8DE0 @ case 46
	.4byte .L080D8DE0 @ case 47
.L080D897C:
	ldr r1, .L080D89C0 @ =0x00000363
	mov r0, sl
	movs r2, #0
	bl func_080DC294
	ldr r0, .L080D89C4 @ =gUnk_0300040C
	ldr r2, [r0]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r0, #0x20
	rsbs r0, r0, #0
	ldr r4, .L080D89C8 @ =0x000004EC
	add r4, sp
	ldrh r4, [r4]
	ands r0, r4
	movs r1, #6
	orrs r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080D89CC @ =0xFFFFFF00
	ldr r5, .L080D89C8 @ =0x000004EC
	add r5, sp
	ldrh r5, [r5]
	ands r1, r5
	orrs r1, r0
	ldr r0, .L080D89D0 @ =0xFFFFF81F
	ands r1, r0
	movs r3, #0x1d
	movs r0, #1
	strb r0, [r2]
	str r3, [r2, #4]
	strh r1, [r2, #8]
	b .L080D8FE8
	.align 2, 0
.L080D89C0: .4byte 0x00000363
.L080D89C4: .4byte gUnk_0300040C
.L080D89C8: .4byte 0x000004EC
.L080D89CC: .4byte 0xFFFFFF00
.L080D89D0: .4byte 0xFFFFF81F
.L080D89D4:
	ldr r6, .L080D8AB4 @ =0x00000564
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	ldr r1, [r0]
	movs r7, #0x94
	lsls r7, r7, #1
	adds r1, r1, r7
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0xc
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __23MapClockStatusHudWidgetUiUiUiUi
	mov r4, sl
	adds r4, #0xb4
	adds r5, r0, #0
	ldr r1, [r4]
	adds r6, r4, #0
	cmp r5, r1
	beq .L080D8A1C
	cmp r1, #0
	beq .L080D8A1C
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8A1C:
	str r5, [r4]
	movs r0, #0xaa
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, .L080D8AB8 @ =0x00002210
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080D8A48
	ldr r3, .L080D8ABC @ =0x000034C4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080D8A48
	ldr r0, [r6]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
.L080D8A48:
	ldr r4, [r6]
	movs r5, #0
	ldr r7, .L080D8AB4 @ =0x00000564
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r1, [r0]
	adds r1, #0xb0
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080D8A7C
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldrh r1, [r0, #0x12]
	lsls r1, r1, #0x15
	lsrs r1, r1, #0x1a
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D8A7E
.L080D8A7C:
	movs r5, #1
.L080D8A7E:
	adds r2, r5, #0
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r1, [r3]
	adds r1, #0x10
	adds r0, r4, #0
	adds r0, #8
	bl UpdateMapClockStatusHudCalendar
	ldr r0, [r6]
	movs r4, #0xaa
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r1, [r4]
	ldr r1, [r1, #8]
	adds r0, #8
	bl SetMapClockStatusHudUnkSelector
	ldr r5, .L080D8AC0 @ =0x0000055C
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
	b .L080D8D7C
	.align 2, 0
.L080D8AB4: .4byte 0x00000564
.L080D8AB8: .4byte 0x00002210
.L080D8ABC: .4byte 0x000034C4
.L080D8AC0: .4byte 0x0000055C
.L080D8AC4:
	movs r4, #1
	movs r6, #0xab
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	str r4, [r6]
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8B04
	cmp r1, #0
	beq .L080D8B04
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8B04:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	ldr r7, .L080D8B1C @ =0x0000055C
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	b .L080D8D7C
	.align 2, 0
.L080D8B1C: .4byte 0x0000055C
.L080D8B20:
	movs r4, #1
	movs r0, #0xab
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	str r4, [r0]
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	movs r1, #5
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8B60
	cmp r1, #0
	beq .L080D8B60
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8B60:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	b .L080D8D74
.L080D8B6E:
	movs r4, #1
	movs r2, #0xab
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	str r4, [r2]
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8BAC
	cmp r1, #0
	beq .L080D8BAC
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8BAC:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	ldr r3, .L080D8BC4 @ =0x0000055C
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	b .L080D8D7C
	.align 2, 0
.L080D8BC4: .4byte 0x0000055C
.L080D8BC8:
	movs r4, #1
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	str r4, [r5]
	ldr r6, .L080D8C2C @ =0x00000564
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	ldr r1, [r0]
	movs r7, #0x94
	lsls r7, r7, #1
	adds r1, r1, r7
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8C1C
	cmp r1, #0
	beq .L080D8C1C
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8C1C:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	b .L080D8D74
	.align 2, 0
.L080D8C2C: .4byte 0x00000564
.L080D8C30:
	movs r4, #1
	movs r2, #0xab
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	str r4, [r2]
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8C70
	cmp r1, #0
	beq .L080D8C70
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8C70:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	ldr r3, .L080D8C88 @ =0x0000055C
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	b .L080D8D7C
	.align 2, 0
.L080D8C88: .4byte 0x0000055C
.L080D8C8C:
	movs r4, #1
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	str r4, [r5]
	movs r0, #0x10
	bl __builtin_new
	str r4, [sp]
	movs r1, #3
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D8CCC
	cmp r1, #0
	beq .L080D8CCC
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D8CCC:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	ldr r6, .L080D8CE4 @ =0x0000055C
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	b .L080D8D7C
	.align 2, 0
.L080D8CE4: .4byte 0x0000055C
.L080D8CE8:
	movs r0, #6
	movs r7, #0xab
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	str r0, [r7]
	movs r0, #4
	bl __builtin_new
	adds r6, r0, #0
	movs r5, #0x87
	lsls r5, r5, #3
	add r5, sp
	adds r0, r5, #0
	bl __17ObjTileCollection
	ldr r4, .L080D8D88 @ =0x0000043C
	add r4, sp
	adds r0, r4, #0
	bl __20ObjPaletteCollection
	movs r0, #1
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
	mov r4, sl
	adds r4, #0xac
	adds r5, r0, #0
	ldr r0, [r4]
	adds r6, r4, #0
	cmp r5, r0
	beq .L080D8D3E
	cmp r0, #0
	beq .L080D8D3E
	movs r1, #3
	bl _._12UiStateOwner
.L080D8D3E:
	str r5, [r4]
	ldr r0, .L080D8D88 @ =0x0000043C
	add r0, sp
	movs r1, #2
	bl _._20ObjPaletteCollection
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	movs r1, #2
	bl _._17ObjTileCollection
	ldr r0, [r6]
	bl func_08050D68
	ldr r0, [r6]
	ldr r1, .L080D8D8C @ =gText_HelpMenu_Crops
	ldr r2, .L080D8D90 @ =gText_HelpMenu_Animals
	ldr r3, .L080D8D94 @ =gText_HelpMenu_UsefulTips
	ldr r5, .L080D8D98 @ =gText_HelpMenu_Exit
	movs r4, #0
	str r5, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl func_08050E0C
.L080D8D74:
	ldr r1, .L080D8D9C @ =0x0000055C
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
.L080D8D7C:
	ldr r1, .L080D8DA0 @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl BeginHardwareBlend
	b .L080D8FE8
	.align 2, 0
.L080D8D88: .4byte 0x0000043C
.L080D8D8C: .4byte gText_HelpMenu_Crops
.L080D8D90: .4byte gText_HelpMenu_Animals
.L080D8D94: .4byte gText_HelpMenu_UsefulTips
.L080D8D98: .4byte gText_HelpMenu_Exit
.L080D8D9C: .4byte 0x0000055C
.L080D8DA0: .4byte 0x00000889
.L080D8DA4:
	ldr r0, .L080D8E10 @ =gUnk_0300040C
	ldr r2, [r0]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r0, #0x20
	rsbs r0, r0, #0
	movs r4, #0x9e
	lsls r4, r4, #3
	add r4, sp
	ldrh r4, [r4]
	ands r0, r4
	movs r1, #6
	orrs r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080D8E14 @ =0xFFFFFF00
	movs r5, #0x9e
	lsls r5, r5, #3
	add r5, sp
	ldrh r5, [r5]
	ands r1, r5
	orrs r1, r0
	ldr r0, .L080D8E18 @ =0xFFFFF81F
	ands r1, r0
	movs r3, #0x1d
	movs r0, #1
	strb r0, [r2]
	str r3, [r2, #4]
	strh r1, [r2, #8]
.L080D8DE0:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r6, sl
	ldrh r1, [r6, #0x10]
	ldr r0, .L080D8E1C @ =0x0000F0FF
	ands r0, r1
	strh r0, [r6, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D8E20 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	b .L080D8F8E
	.align 2, 0
.L080D8E10: .4byte gUnk_0300040C
.L080D8E14: .4byte 0xFFFFFF00
.L080D8E18: .4byte 0xFFFFF81F
.L080D8E1C: .4byte 0x0000F0FF
.L080D8E20: .4byte 0x0000FF3F
.L080D8E24:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r7, sl
	ldrh r1, [r7, #0x10]
	ldr r0, .L080D8E60 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r7, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D8E64 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	ldr r0, .L080D8E68 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	mov r1, sl
	adds r1, #0x94
	ldr r1, [r1]
	b .L080D8F8A
	.align 2, 0
.L080D8E60: .4byte 0x0000F0FF
.L080D8E64: .4byte 0x0000FF3F
.L080D8E68: .4byte gUnk_0300040C
.L080D8E6C:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r0, sl
	ldrh r1, [r0, #0x10]
	ldr r0, .L080D8EB8 @ =0x0000F0FF
	ands r0, r1
	mov r1, sl
	strh r0, [r1, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D8EBC @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r1, [r2]
	ldr r3, .L080D8EC0 @ =0x00002C4A
	adds r0, r1, r3
	ldrb r2, [r0]
	lsls r0, r2, #0x19
	cmp r0, #0
	bge .L080D8EC4
	movs r1, #1
	rsbs r1, r1, #0
	b .L080D8EE6
	.align 2, 0
.L080D8EB8: .4byte 0x0000F0FF
.L080D8EBC: .4byte 0x0000FF3F
.L080D8EC0: .4byte 0x00002C4A
.L080D8EC4:
	ldr r4, .L080D8EE0 @ =0x00002C48
	adds r0, r1, r4
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	bne .L080D8EE4
	lsrs r0, r2, #7
	movs r1, #2
	cmp r0, #0
	beq .L080D8EE6
	movs r1, #1
	b .L080D8EE6
	.align 2, 0
.L080D8EE0: .4byte 0x00002C48
.L080D8EE4:
	movs r1, #0
.L080D8EE6:
	ldr r0, .L080D8EF0 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	b .L080D8F8A
	.align 2, 0
.L080D8EF0: .4byte gUnk_0300040C
.L080D8EF4:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r5, sl
	ldrh r1, [r5, #0x10]
	ldr r0, .L080D8F30 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r5, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D8F34 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	ldr r0, .L080D8F38 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	mov r1, sl
	adds r1, #0x94
	ldr r1, [r1]
	b .L080D8F8A
	.align 2, 0
.L080D8F30: .4byte 0x0000F0FF
.L080D8F34: .4byte 0x0000FF3F
.L080D8F38: .4byte gUnk_0300040C
.L080D8F3C:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r6, sl
	ldrh r1, [r6, #0x10]
	ldr r0, .L080D8F98 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r6, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D8F9C @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	ldr r0, .L080D8FA0 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r1, .L080D8FA4 @ =0x00002C4C
	adds r0, r0, r1
	movs r1, #0
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080D8F88
	movs r1, #1
.L080D8F88:
	adds r0, r2, #0
.L080D8F8A:
	bl Push__12ScriptEnginei
.L080D8F8E:
	mov r0, sl
	bl func_080D7F3C
	b .L080D8FE8
	.align 2, 0
.L080D8F98: .4byte 0x0000F0FF
.L080D8F9C: .4byte 0x0000FF3F
.L080D8FA0: .4byte gUnk_0300040C
.L080D8FA4: .4byte 0x00002C4C
.L080D8FA8:
	mov r1, sl
	adds r1, #0xe8
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xe9
	strb r3, [r0]
	mov r2, sl
	ldrh r1, [r2, #0x10]
	ldr r0, .L080D9024 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2, #0x10]
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080D9028 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	ldr r0, .L080D902C @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	mov r1, sl
	adds r1, #0x94
	ldrb r1, [r1]
	bl Push__12ScriptEnginei
	mov r0, sl
	bl func_080D7F3C
.L080D8FE8:
	add r0, sp, #0x10
	bl UpdateHardwareKeyRepeat
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	ldr r1, [r0, #0x10]
	ldr r0, .L080D9030 @ =0x000004CC
	add r0, sp
	str r1, [r0]
	bl rand
	movs r4, #0
	ldr r5, .L080D9034 @ =0x000004F4
	add r5, sp
	str r4, [r5]
	movs r6, #0xab
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	cmp r0, #0x1d
	bhi .L080D90F4
	lsls r0, r0, #2
	ldr r1, .L080D9038 @ =.L080D903C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D9024: .4byte 0x0000F0FF
.L080D9028: .4byte 0x0000FF3F
.L080D902C: .4byte gUnk_0300040C
.L080D9030: .4byte 0x000004CC
.L080D9034: .4byte 0x000004F4
.L080D9038: .4byte .L080D903C
.L080D903C: @ jump table
	.4byte .L080D90B4 @ case 0
	.4byte .L080D90DC @ case 1
	.4byte .L080D90DC @ case 2
	.4byte .L080D90DC @ case 3
	.4byte .L080D90DC @ case 4
	.4byte .L080D90DC @ case 5
	.4byte .L080D90DC @ case 6
	.4byte .L080D90DC @ case 7
	.4byte .L080D90DC @ case 8
	.4byte .L080D90DC @ case 9
	.4byte .L080D90DC @ case 10
	.4byte .L080D90DC @ case 11
	.4byte .L080D90DC @ case 12
	.4byte .L080D90DC @ case 13
	.4byte .L080D90DC @ case 14
	.4byte .L080D90DC @ case 15
	.4byte .L080D90DC @ case 16
	.4byte .L080D90DC @ case 17
	.4byte .L080D90EC @ case 18
	.4byte .L080D90EC @ case 19
	.4byte .L080D90DC @ case 20
	.4byte .L080D90EC @ case 21
	.4byte .L080D90EC @ case 22
	.4byte .L080D90EC @ case 23
	.4byte .L080D90DC @ case 24
	.4byte .L080D90EC @ case 25
	.4byte .L080D90EC @ case 26
	.4byte .L080D90EC @ case 27
	.4byte .L080D90EC @ case 28
	.4byte .L080D90EC @ case 29
.L080D90B4:
	ldr r7, .L080D90D4 @ =0x0000055C
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	ldr r0, .L080D90D8 @ =0x000004F4
	add r0, sp
	str r1, [r0]
	b .L080D90F4
	.align 2, 0
.L080D90D4: .4byte 0x0000055C
.L080D90D8: .4byte 0x000004F4
.L080D90DC:
	movs r1, #1
	ldr r2, .L080D90E8 @ =0x000004F4
	add r2, sp
	str r1, [r2]
	b .L080D90F4
	.align 2, 0
.L080D90E8: .4byte 0x000004F4
.L080D90EC:
	movs r3, #0
	ldr r4, .L080D9110 @ =0x000004F4
	add r4, sp
	str r3, [r4]
.L080D90F4:
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, #0x1d
	bls .L080D9104
	b .L080D93E8
.L080D9104:
	lsls r0, r0, #2
	ldr r1, .L080D9114 @ =.L080D9118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D9110: .4byte 0x000004F4
.L080D9114: .4byte .L080D9118
.L080D9118: @ jump table
	.4byte .L080D9190 @ case 0
	.4byte .L080D91BC @ case 1
	.4byte .L080D921C @ case 2
	.4byte .L080D9190 @ case 3
	.4byte .L080D9190 @ case 4
	.4byte .L080D9190 @ case 5
	.4byte .L080D91F4 @ case 6
	.4byte .L080D9190 @ case 7
	.4byte .L080D91BC @ case 8
	.4byte .L080D91BC @ case 9
	.4byte .L080D91F4 @ case 10
	.4byte .L080D91F4 @ case 11
	.4byte .L080D91F4 @ case 12
	.4byte .L080D91BC @ case 13
	.4byte .L080D9288 @ case 14
	.4byte .L080D9288 @ case 15
	.4byte .L080D9288 @ case 16
	.4byte .L080D92C4 @ case 17
	.4byte .L080D935C @ case 18
	.4byte .L080D93B4 @ case 19
	.4byte .L080D9288 @ case 20
	.4byte .L080D924C @ case 21
	.4byte .L080D924C @ case 22
	.4byte .L080D924C @ case 23
	.4byte .L080D924C @ case 24
	.4byte .L080D924C @ case 25
	.4byte .L080D924C @ case 26
	.4byte .L080D924C @ case 27
	.4byte .L080D924C @ case 28
	.4byte .L080D924C @ case 29
.L080D9190:
	mov r0, sl
	adds r0, #0xb4
	ldr r5, [r0]
	mov r6, sl
	adds r6, #0x6c
	subs r0, #0x4c
	bl func_08008AE0
	ldr r1, [r5, #4]
	str r0, [sp]
	ldr r4, [r1, #0x2c]
	adds r0, r5, #0
	add r1, sp, #0x34
	ldr r7, .L080D91B8 @ =0x00000544
	add r7, sp
	ldr r2, [r7]
	adds r3, r6, #0
	bl _call_via_r4
	b .L080D93E8
	.align 2, 0
.L080D91B8: .4byte 0x00000544
.L080D91BC:
	mov r0, sl
	adds r0, #0xb8
	ldr r5, [r0]
	mov r4, sl
	adds r4, #0x6c
	subs r0, #0x50
	bl func_08008AE0
	str r4, [sp]
	str r0, [sp, #4]
	ldr r0, .L080D91EC @ =0x0000056C
	add r0, sp
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #0x10
	add r2, sp, #0x34
	ldr r4, .L080D91F0 @ =0x00000544
	add r4, sp
	ldr r3, [r4]
	bl Update__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
	b .L080D93E8
	.align 2, 0
.L080D91EC: .4byte 0x0000056C
.L080D91F0: .4byte 0x00000544
.L080D91F4:
	mov r0, sl
	adds r0, #0xac
	ldr r5, [r0]
	mov r4, sl
	adds r4, #0x6c
	subs r0, #0x44
	bl func_08008AE0
	str r4, [sp]
	str r0, [sp, #4]
	ldr r6, .L080D9218 @ =0x0000056C
	add r6, sp
	ldr r6, [r6]
	str r6, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #0x10
	b .L080D9342
	.align 2, 0
.L080D9218: .4byte 0x0000056C
.L080D921C:
	mov r0, sl
	adds r0, #0xac
	ldr r5, [r0]
	cmp r5, #0
	beq .L080D924C
	mov r4, sl
	adds r4, #0x6c
	subs r0, #0x44
	bl func_08008AE0
	str r4, [sp]
	str r0, [sp, #4]
	ldr r0, .L080D9280 @ =0x0000056C
	add r0, sp
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #0x10
	add r2, sp, #0x34
	ldr r4, .L080D9284 @ =0x00000544
	add r4, sp
	ldr r3, [r4]
	bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
.L080D924C:
	mov r0, sl
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080D9258
	b .L080D93E8
.L080D9258:
	mov r0, sl
	adds r0, #0xb4
	ldr r6, [r0]
	cmp r6, #0
	bne .L080D9264
	b .L080D93E8
.L080D9264:
	mov r5, sl
	adds r5, #0x6c
	subs r0, #0x4c
	bl func_08008AE0
	ldr r1, [r6, #4]
	str r0, [sp]
	ldr r4, [r1, #0x2c]
	adds r0, r6, #0
	add r1, sp, #0x34
	ldr r6, .L080D9284 @ =0x00000544
	add r6, sp
	ldr r2, [r6]
	b .L080D93A2
	.align 2, 0
.L080D9280: .4byte 0x0000056C
.L080D9284: .4byte 0x00000544
.L080D9288:
	mov r0, sl
	adds r0, #0xac
	ldr r5, [r0]
	cmp r5, #0
	bne .L080D9294
	b .L080D93E8
.L080D9294:
	mov r4, sl
	adds r4, #0x6c
	subs r0, #0x44
	bl func_08008AE0
	str r4, [sp]
	str r0, [sp, #4]
	ldr r7, .L080D92BC @ =0x0000056C
	add r7, sp
	ldr r7, [r7]
	str r7, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #0x10
	add r2, sp, #0x34
	ldr r4, .L080D92C0 @ =0x00000544
	add r4, sp
	ldr r3, [r4]
	bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
	b .L080D93E8
	.align 2, 0
.L080D92BC: .4byte 0x0000056C
.L080D92C0: .4byte 0x00000544
.L080D92C4:
	mov r0, sl
	adds r0, #0xac
	ldr r5, [r0]
	cmp r5, #0
	bne .L080D92D0
	b .L080D93E8
.L080D92D0:
	add r0, sp, #0x10
	ldrh r2, [r0, #8]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, .L080D9350 @ =0xFFFFFF00
	adds r1, r3, #0
	ands r1, r2
	orrs r1, r0
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ands r1, r3
	orrs r1, r0
	movs r0, #0x7f
	ands r0, r1
	ands r1, r3
	orrs r1, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ands r1, r3
	orrs r1, r0
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ands r1, r3
	orrs r1, r0
	movs r0, #0x89
	lsls r0, r0, #3
	add r0, sp
	bl __18HardwareInputStateUi
	mov r4, sl
	adds r4, #0x6c
	mov r0, sl
	adds r0, #0x68
	bl func_08008AE0
	str r4, [sp]
	str r0, [sp, #4]
	ldr r6, .L080D9354 @ =0x0000056C
	add r6, sp
	ldr r6, [r6]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
.L080D9342:
	add r2, sp, #0x34
	ldr r7, .L080D9358 @ =0x00000544
	add r7, sp
	ldr r3, [r7]
	bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
	b .L080D93E8
	.align 2, 0
.L080D9350: .4byte 0xFFFFFF00
.L080D9354: .4byte 0x0000056C
.L080D9358: .4byte 0x00000544
.L080D935C:
	ldr r1, .L080D93AC @ =0x0000055C
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	bge .L080D93E8
	mov r0, sl
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080D93E8
	mov r0, sl
	adds r0, #0xb4
	ldr r6, [r0]
	cmp r6, #0
	beq .L080D93E8
	mov r5, sl
	adds r5, #0x6c
	subs r0, #0x4c
	bl func_08008AE0
	ldr r1, [r6, #4]
	str r0, [sp]
	ldr r4, [r1, #0x2c]
	adds r0, r6, #0
	add r1, sp, #0x34
	ldr r3, .L080D93B0 @ =0x00000544
	add r3, sp
	ldr r2, [r3]
.L080D93A2:
	adds r3, r5, #0
	bl _call_via_r4
	b .L080D93E8
	.align 2, 0
.L080D93AC: .4byte 0x0000055C
.L080D93B0: .4byte 0x00000544
.L080D93B4:
	mov r0, sl
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080D93E8
	mov r0, sl
	adds r0, #0xb4
	ldr r6, [r0]
	cmp r6, #0
	beq .L080D93E8
	mov r5, sl
	adds r5, #0x6c
	subs r0, #0x4c
	bl func_08008AE0
	ldr r1, [r6, #4]
	str r0, [sp]
	ldr r4, [r1, #0x2c]
	adds r0, r6, #0
	add r1, sp, #0x34
	ldr r6, .L080D9404 @ =0x00000544
	add r6, sp
	ldr r2, [r6]
	adds r3, r5, #0
	bl _call_via_r4
.L080D93E8:
	movs r7, #0xab
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	cmp r0, #0x1d
	bls .L080D93FA
	bl .L080DAAE6
.L080D93FA:
	lsls r0, r0, #2
	ldr r1, .L080D9408 @ =.L080D940C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D9404: .4byte 0x00000544
.L080D9408: .4byte .L080D940C
.L080D940C: @ jump table
	.4byte .L080D9484 @ case 0
	.4byte .L080D9D46 @ case 1
	.4byte .L080DA278 @ case 2
	.4byte .L080D9630 @ case 3
	.4byte .L080D9708 @ case 4
	.4byte .L080D97E4 @ case 5
	.4byte .L080D99B4 @ case 6
	.4byte .L080D9CD4 @ case 7
	.4byte .L080DA13A @ case 8
	.4byte .L080DA238 @ case 9
	.4byte .L080D9C28 @ case 10
	.4byte .L080D9C96 @ case 11
	.4byte .L080D9974 @ case 12
	.4byte .L080D98D4 @ case 13
	.4byte .L080DA584 @ case 14
	.4byte .L080DA596 @ case 15
	.4byte .L080DA5BC @ case 16
	.4byte .L080DA5CE @ case 17
	.4byte .L080DA6E8 @ case 18
	.4byte .L080DA738 @ case 19
	.4byte .L080DA79C @ case 20
	.4byte .L080DA758 @ case 21
	.4byte .L080DA778 @ case 22
	.4byte .L080DA7C8 @ case 23
	.4byte .L080DAA50 @ case 24
	.4byte .L080DA7E0 @ case 25
	.4byte .L080DA814 @ case 26
	.4byte .L080DAA6C @ case 27
	.4byte .L080DAA9C @ case 28
	.4byte .L080DAACC @ case 29
.L080D9484:
	add r0, sp, #0x10
	ldrh r5, [r0, #4]
	ldrh r1, [r0]
	ldr r0, .L080D958C @ =0x000004AC
	add r0, sp
	str r1, [r0]
	movs r0, #0xc
	ands r0, r5
	cmp r0, #0
	bne .L080D949C
	bl .L080DAAE6
.L080D949C:
	mov r0, sl
	adds r0, #0xb4
	ldr r0, [r0]
	bl GetPhase__C13ControlWidget
	adds r6, r0, #0
	ldr r1, .L080D9590 @ =0x00000564
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x4b
	bl _call_via_r2
	adds r3, r0, #0
	ldr r0, .L080D9594 @ =gUnk_0300040C
	ldr r4, [r0]
	movs r2, #0xde
	lsls r2, r2, #2
	adds r2, r2, r4
	mov r8, r2
	ldr r7, .L080D9590 @ =0x00000564
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0
	movs r7, #0xb0
	lsls r7, r7, #3
	add r7, sp
	str r3, [r7]
	bl _call_via_r2
	adds r2, r0, #0
	movs r0, #0xb0
	lsls r0, r0, #3
	add r0, sp
	ldr r3, [r0]
	cmp r6, #3
	beq .L080D94F8
	cmp r6, #0
	beq .L080D94F8
	bl .L080DAAE6
.L080D94F8:
	movs r6, #0
	movs r1, #0
	mov r7, r8
	ldr r0, [r7]
	cmp r0, #0
	bne .L080D9506
	movs r1, #1
.L080D9506:
	cmp r1, #0
	beq .L080D9534
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D951A
	movs r1, #1
.L080D951A:
	cmp r1, #0
	beq .L080D9534
	movs r7, #0x9a
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D952E
	movs r1, #1
.L080D952E:
	cmp r1, #0
	beq .L080D9534
	movs r6, #1
.L080D9534:
	cmp r6, #0
	bne .L080D953C
	bl .L080DAAE6
.L080D953C:
	cmp r3, #0
	beq .L080D955C
	adds r0, r3, #0
	ldr r1, .L080D9598 @ =0x0000057C
	add r1, sp
	str r2, [r1]
	bl func_08038108
	lsls r0, r0, #0x18
	ldr r3, .L080D9598 @ =0x0000057C
	add r3, sp
	ldr r2, [r3]
	cmp r0, #0
	beq .L080D955C
	bl .L080DAAE6
.L080D955C:
	ldr r0, [r2, #0x14]
	adds r0, #0x94
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080D9572
	bl .L080DAAE6
.L080D9572:
	ldr r0, .L080D958C @ =0x000004AC
	add r0, sp
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D95C4
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080D959C
	movs r0, #4
	b .L080D9606
	.align 2, 0
.L080D958C: .4byte 0x000004AC
.L080D9590: .4byte 0x00000564
.L080D9594: .4byte gUnk_0300040C
.L080D9598: .4byte 0x0000057C
.L080D959C:
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne .L080D95A8
	bl .L080DAAE6
.L080D95A8:
	movs r0, #5
	movs r6, #0xab
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	str r0, [r6]
	ldr r7, .L080D95C0 @ =0x0000055C
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	b .L080D9618
	.align 2, 0
.L080D95C0: .4byte 0x0000055C
.L080D95C4:
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r2, .L080D95F4 @ =0x000034C4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080D95F8
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080D95F8
	mov r0, sl
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	movs r0, #7
	bl .L080DA804
	.align 2, 0
.L080D95F4: .4byte 0x000034C4
.L080D95F8:
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne .L080D9604
	bl .L080DAAE6
.L080D9604:
	movs r0, #3
.L080D9606:
	movs r4, #0xab
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	str r0, [r4]
	ldr r5, .L080D9628 @ =0x0000055C
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
.L080D9618:
	ldr r1, .L080D962C @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	bl .L080DAAE6
	.align 2, 0
.L080D9628: .4byte 0x0000055C
.L080D962C: .4byte 0x00000889
.L080D9630:
	ldr r6, .L080D96F4 @ =0x0000055C
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r7, r1, #0x1f
	cmp r7, #0
	beq .L080D964E
	bl .L080DAAE6
.L080D964E:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #1
	mov r8, r0
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r1, [r1]
	mov sb, r1
	movs r5, #0x89
	lsls r5, r5, #3
	add r5, sp
	adds r1, r5, #0
	ldm r4!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r1, .L080D96F8 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, sb
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldr r4, .L080D96FC @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0x10
	bl __builtin_new
	ldr r2, [r4]
	str r7, [r4]
	str r2, [r5]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r1, .L080D9700 @ =vtable_unk_080E5EB4
	str r1, [r0]
	str r7, [r5]
	str r2, [r0, #4]
	str r3, [r0, #8]
	mov r2, r8
	strb r2, [r0, #0xc]
	movs r3, #0xac
	lsls r3, r3, #3
	add r3, sp
	ldr r5, [r3]
	adds r4, r0, #0
	adds r6, r5, #0
	ldr r1, [r6]
	cmp r4, r1
	beq .L080D96DA
	cmp r1, #0
	beq .L080D96DA
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D96DA:
	str r4, [r5]
	movs r7, #0xac
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	movs r1, #0
	str r1, [r7]
	ldr r3, .L080D9704 @ =0x000004DC
	add r3, sp
	ldr r3, [r3]
	str r0, [r3]
	b .L080D98A0
	.align 2, 0
.L080D96F4: .4byte 0x0000055C
.L080D96F8: .4byte __vt_17ReturnToGameScene
.L080D96FC: .4byte 0x00000444
.L080D9700: .4byte vtable_unk_080E5EB4
.L080D9704: .4byte 0x000004DC
.L080D9708:
	ldr r4, .L080D97CC @ =0x0000055C
	add r4, sp
	ldr r4, [r4]
	ldr r0, [r4]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	lsls r4, r1, #0x18
	lsrs r7, r4, #0x18
	cmp r7, #0
	beq .L080D972A
	bl .L080DAAE6
.L080D972A:
	movs r0, #0x10
	bl __builtin_new
	adds r6, r0, #0
	movs r5, #0xaa
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r5, [r5]
	mov r8, r5
	ldr r0, .L080D97D0 @ =__vt_17TownMapTransition
	str r0, [r6]
	str r5, [r6, #4]
	movs r0, #0x14
	bl __builtin_new
	ldr r1, .L080D97D4 @ =__vt_26TownMapSelectionTransition
	str r1, [r0]
	strb r7, [r0, #4]
	adds r5, r0, #6
	movs r3, #0x8d
	lsls r3, r3, #2
	ldrh r2, [r0, #6]
	ldr r4, .L080D97D8 @ =0xFFFFFC00
	adds r1, r4, #0
	ands r1, r2
	orrs r1, r3
	strh r1, [r0, #6]
	ldrb r2, [r5, #1]
	movs r3, #3
	adds r1, r3, #0
	ands r1, r2
	strb r1, [r5, #1]
	ldrh r2, [r5, #2]
	adds r1, r4, #0
	ands r1, r2
	strh r1, [r5, #2]
	ldrb r1, [r5, #3]
	ands r3, r1
	strb r3, [r5, #3]
	ldrh r1, [r5, #4]
	ands r4, r1
	strh r4, [r5, #4]
	ldr r1, .L080D97DC @ =__vt_23TownMapReturnTransition
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #0xc]
	str r7, [r0, #0x10]
	str r0, [r6, #8]
	str r7, [r6, #0xc]
	movs r2, #0xac
	lsls r2, r2, #3
	add r2, sp
	ldr r4, [r2]
	adds r3, r4, #0
	ldr r1, [r3]
	cmp r6, r1
	beq .L080D97AE
	cmp r1, #0
	beq .L080D97AE
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D97AE:
	str r6, [r4]
	movs r4, #0xac
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r1, [r4]
	movs r0, #0
	str r0, [r4]
	ldr r6, .L080D97E0 @ =0x000004DC
	add r6, sp
	ldr r6, [r6]
	str r1, [r6]
	bl func_080DB0CC
	.align 2, 0
.L080D97CC: .4byte 0x0000055C
.L080D97D0: .4byte __vt_17TownMapTransition
.L080D97D4: .4byte __vt_26TownMapSelectionTransition
.L080D97D8: .4byte 0xFFFFFC00
.L080D97DC: .4byte __vt_23TownMapReturnTransition
.L080D97E0: .4byte 0x000004DC
.L080D97E4:
	ldr r7, .L080D98C0 @ =0x0000055C
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r6, r1, #0x1f
	cmp r6, #0
	beq .L080D9802
	bl .L080DAAE6
.L080D9802:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #1
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r1, [r1]
	mov r8, r1
	movs r5, #0x89
	lsls r5, r5, #3
	add r5, sp
	adds r1, r5, #0
	ldm r4!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r1, .L080D98C4 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldr r4, .L080D98C8 @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0xc
	bl __builtin_new
	ldr r3, [r4]
	str r6, [r4]
	str r3, [r5]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r2, [r1]
	ldr r1, .L080D98CC @ =vtable_unk_080E5E94
	str r1, [r0]
	str r2, [r0, #4]
	str r6, [r5]
	str r3, [r0, #8]
	movs r2, #0xac
	lsls r2, r2, #3
	add r2, sp
	ldr r5, [r2]
	adds r4, r0, #0
	adds r3, r5, #0
	ldr r1, [r3]
	cmp r4, r1
	beq .L080D9888
	cmp r1, #0
	beq .L080D9888
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9888:
	str r4, [r5]
	movs r4, #0xac
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r0, [r4]
	movs r1, #0
	str r1, [r4]
	ldr r6, .L080D98D0 @ =0x000004DC
	add r6, sp
	ldr r6, [r6]
	str r0, [r6]
.L080D98A0:
	ldr r0, .L080D98C8 @ =0x00000444
	add r0, sp
	ldr r1, [r0]
	cmp r1, #0
	bne .L080D98AE
	bl func_080DB0CC
.L080D98AE:
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
	bl func_080DB0CC
	.align 2, 0
.L080D98C0: .4byte 0x0000055C
.L080D98C4: .4byte __vt_17ReturnToGameScene
.L080D98C8: .4byte 0x00000444
.L080D98CC: .4byte vtable_unk_080E5E94
.L080D98D0: .4byte 0x000004DC
.L080D98D4:
	mov r4, sl
	adds r4, #0xb8
	ldr r0, [r4]
	bl GetPhase__C13ControlWidget
	cmp r0, #0
	beq .L080D98E6
	bl .L080DAAE6
.L080D98E6:
	movs r5, #0
	ldr r1, [r4]
	cmp r5, r1
	beq .L080D98FE
	cmp r1, #0
	beq .L080D98FE
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D98FE:
	str r5, [r4]
	movs r0, #4
	bl __builtin_new
	adds r6, r0, #0
	movs r5, #0x87
	lsls r5, r5, #3
	add r5, sp
	adds r0, r5, #0
	bl __17ObjTileCollection
	ldr r4, .L080D9970 @ =0x0000043C
	add r4, sp
	adds r0, r4, #0
	bl __20ObjPaletteCollection
	movs r0, #1
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
	mov r4, sl
	adds r4, #0xac
	adds r5, r0, #0
	ldr r0, [r4]
	adds r6, r4, #0
	cmp r5, r0
	beq .L080D994A
	cmp r0, #0
	beq .L080D994A
	movs r1, #3
	bl _._12UiStateOwner
.L080D994A:
	str r5, [r4]
	ldr r0, .L080D9970 @ =0x0000043C
	add r0, sp
	movs r1, #2
	bl _._20ObjPaletteCollection
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	movs r1, #2
	bl _._17ObjTileCollection
	ldr r0, [r6]
	bl func_08050D5C
	movs r0, #0xc
	bl .L080DA858
	.align 2, 0
.L080D9970: .4byte 0x0000043C
.L080D9974:
	mov r4, sl
	adds r4, #0xac
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	beq .L080D9986
	bl .L080DAAE6
.L080D9986:
	ldr r0, [r4]
	ldr r1, .L080D99A4 @ =gText_HelpMenu_Crops
	ldr r2, .L080D99A8 @ =gText_HelpMenu_Animals
	ldr r3, .L080D99AC @ =gText_HelpMenu_UsefulTips
	ldr r5, .L080D99B0 @ =gText_HelpMenu_Exit
	movs r4, #0
	str r5, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl func_08050E0C
	movs r0, #6
	bl .L080DAABA
	.align 2, 0
.L080D99A4: .4byte gText_HelpMenu_Crops
.L080D99A8: .4byte gText_HelpMenu_Animals
.L080D99AC: .4byte gText_HelpMenu_UsefulTips
.L080D99B0: .4byte gText_HelpMenu_Exit
.L080D99B4:
	ldr r2, .L080D99FC @ =0x0000055C
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r6, r1, #0x1f
	cmp r6, #0
	beq .L080D99D2
	bl .L080DAAE6
.L080D99D2:
	mov r4, sl
	adds r4, #0xac
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #6
	bne .L080D9A00
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne .L080D99F0
	bl .L080DAAE6
.L080D99F0:
	ldr r0, [r4]
	bl func_08050D74
	movs r0, #0xa
	bl .L080DA804
	.align 2, 0
.L080D99FC: .4byte 0x0000055C
.L080D9A00:
	ldr r0, [r4]
	bl GetChoiceResult__C12UiStateOwner
	cmp r0, #2
	beq .L080D9AAC
	cmp r0, #2
	bgt .L080D9A16
	cmp r0, #1
	beq .L080D9A26
	bl .L080DAAE6
.L080D9A16:
	cmp r0, #3
	bne .L080D9A1C
	b .L080D9B40
.L080D9A1C:
	cmp r0, #4
	bne .L080D9A22
	b .L080D9C1C
.L080D9A22:
	bl .L080DAAE6
.L080D9A26:
	ldr r4, .L080D9A9C @ =0x0000055C
	add r4, sp
	ldr r4, [r4]
	ldr r0, [r4]
	ldr r1, .L080D9AA0 @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	movs r0, #0xb
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	str r0, [r5]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #9
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r7, [r7]
	mov r8, r7
	movs r5, #0x89
	lsls r5, r5, #3
	add r5, sp
	adds r1, r5, #0
	ldm r4!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r1, .L080D9AA4 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldr r1, .L080D9AA8 @ =0x00000444
	add r1, sp
	str r6, [r1]
	str r0, [r5]
	movs r0, #0xc
	bl __builtin_new
	adds r1, r5, #0
	movs r2, #0
	bl __25FarmingTutorialTransitionG20SceneTransitionOwner23MaryFarmingTutorialKind
	b .L080D9BC6
	.align 2, 0
.L080D9A9C: .4byte 0x0000055C
.L080D9AA0: .4byte 0x00000889
.L080D9AA4: .4byte __vt_17ReturnToGameScene
.L080D9AA8: .4byte 0x00000444
.L080D9AAC:
	ldr r3, .L080D9B30 @ =0x0000055C
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	ldr r1, .L080D9B34 @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	movs r0, #0xb
	movs r4, #0xab
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	str r0, [r4]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #9
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r5, #0xaa
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r5, [r5]
	mov r8, r5
	movs r5, #0x89
	lsls r5, r5, #3
	add r5, sp
	adds r1, r5, #0
	ldm r4!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r1, .L080D9B38 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r4, r8
	str r4, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldr r1, .L080D9B3C @ =0x00000444
	add r1, sp
	str r6, [r1]
	str r0, [r5]
	movs r0, #0xc
	bl __builtin_new
	adds r1, r5, #0
	movs r2, #1
	bl __25FarmingTutorialTransitionG20SceneTransitionOwner23MaryFarmingTutorialKind
	movs r6, #0xac
	lsls r6, r6, #3
	add r6, sp
	ldr r5, [r6]
	adds r4, r0, #0
	adds r7, r5, #0
	ldr r1, [r7]
	b .L080D9BD4
	.align 2, 0
.L080D9B30: .4byte 0x0000055C
.L080D9B34: .4byte 0x00000889
.L080D9B38: .4byte __vt_17ReturnToGameScene
.L080D9B3C: .4byte 0x00000444
.L080D9B40:
	ldr r1, .L080D9C08 @ =0x0000055C
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r1, .L080D9C0C @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	movs r0, #0xb
	movs r2, #0xab
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	str r0, [r2]
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #9
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r3, [r3]
	mov r8, r3
	movs r5, #0x89
	lsls r5, r5, #3
	add r5, sp
	adds r1, r5, #0
	ldm r4!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r1, .L080D9C10 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r4, r8
	str r4, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldr r4, .L080D9C14 @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0x10
	bl __builtin_new
	ldr r2, [r4]
	str r6, [r4]
	str r2, [r5]
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r3, [r7]
	movs r4, #0x88
	ldr r1, .L080D9C18 @ =__vt_23ReferencePageTransition
	str r1, [r0]
	str r6, [r5]
	str r2, [r0, #4]
	str r3, [r0, #8]
	str r4, [r0, #0xc]
.L080D9BC6:
	movs r1, #0xac
	lsls r1, r1, #3
	add r1, sp
	ldr r5, [r1]
	adds r4, r0, #0
	adds r2, r5, #0
	ldr r1, [r2]
.L080D9BD4:
	cmp r4, r1
	beq .L080D9BE8
	cmp r1, #0
	beq .L080D9BE8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9BE8:
	str r4, [r5]
	ldr r0, .L080D9C14 @ =0x00000444
	add r0, sp
	ldr r1, [r0]
	cmp r1, #0
	bne .L080D9BF8
	bl .L080DAAE6
.L080D9BF8:
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
	bl .L080DAAE6
	.align 2, 0
.L080D9C08: .4byte 0x0000055C
.L080D9C0C: .4byte 0x00000889
.L080D9C10: .4byte __vt_17ReturnToGameScene
.L080D9C14: .4byte 0x00000444
.L080D9C18: .4byte __vt_23ReferencePageTransition
.L080D9C1C:
	ldr r0, [r4]
	bl func_08050D74
	movs r0, #0xa
	bl .L080DA804
.L080D9C28:
	mov r4, sl
	adds r4, #0xac
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #0
	beq .L080D9C3A
	bl .L080DAAE6
.L080D9C3A:
	movs r5, #0
	ldr r0, [r4]
	cmp r5, r0
	beq .L080D9C4C
	cmp r0, #0
	beq .L080D9C4C
	movs r1, #3
	bl _._12UiStateOwner
.L080D9C4C:
	str r5, [r4]
	movs r0, #0x10
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #6
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D9C84
	cmp r1, #0
	beq .L080D9C84
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9C84:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	movs r0, #1
	bl sub_080DA76C
.L080D9C96:
	ldr r5, .L080D9CCC @ =0x0000055C
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	cmp r1, #0
	beq .L080D9CB4
	bl .L080DAAE6
.L080D9CB4:
	movs r6, #0xac
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	str r1, [r6]
	ldr r1, .L080D9CD0 @ =0x000004DC
	add r1, sp
	ldr r1, [r1]
	str r0, [r1]
	bl func_080DB0CC
	.align 2, 0
.L080D9CCC: .4byte 0x0000055C
.L080D9CD0: .4byte 0x000004DC
.L080D9CD4:
	mov r4, sl
	adds r4, #0xb4
	ldr r0, [r4]
	bl GetPhase__C13ControlWidget
	cmp r0, #0
	beq .L080D9CE6
	bl .L080DAAE6
.L080D9CE6:
	movs r5, #0
	ldr r1, [r4]
	cmp r5, r1
	beq .L080D9CFE
	cmp r1, #0
	beq .L080D9CFE
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9CFE:
	str r5, [r4]
	movs r0, #0x10
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r2, #0x1f
	movs r3, #0
	bl __14MainMenuWidgetUiUiUiUiUi
	mov r4, sl
	adds r4, #0xb8
	adds r5, r0, #0
	ldr r1, [r4]
	adds r7, r4, #0
	cmp r5, r1
	beq .L080D9D34
	cmp r1, #0
	beq .L080D9D34
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9D34:
	str r5, [r4]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
	movs r0, #1
	bl .L080DAADC
.L080D9D46:
	mov r4, sl
	adds r4, #0xb8
	ldr r0, [r4]
	bl GetPhase__C13ControlWidget
	adds r7, r4, #0
	cmp r0, #3
	beq .L080D9D5A
	bl .L080DAAE6
.L080D9D5A:
	add r0, sp, #0x10
	ldrh r2, [r0, #4]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	bne .L080D9D68
	b .L080DA11C
.L080D9D68:
	movs r3, #0
	movs r5, #0x9f
	lsls r5, r5, #3
	add r5, sp
	str r3, [r5]
	ldr r0, [r4]
	bl GetSelection__C14MainMenuWidget
	cmp r0, #6
	bls .L080D9D7E
	b .L080DA0E4
.L080D9D7E:
	lsls r0, r0, #2
	ldr r1, .L080D9D88 @ =.L080D9D8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080D9D88: .4byte .L080D9D8C
.L080D9D8C: @ jump table
	.4byte .L080D9DA8 @ case 0
	.4byte .L080DA014 @ case 1
	.4byte .L080D9E1C @ case 2
	.4byte .L080D9EBC @ case 3
	.4byte .L080D9F30 @ case 4
	.4byte .L080D9FA8 @ case 5
	.4byte .L080DA0C4 @ case 6
.L080D9DA8:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #3
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r6, #0xaa
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	ldr r6, [r6]
	mov r8, r6
	movs r6, #0x89
	lsls r6, r6, #3
	add r6, sp
	adds r1, r6, #0
	ldm r4!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, .L080D9E10 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r4, .L080D9E14 @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0xc
	bl __builtin_new
	ldr r5, [r4]
	movs r3, #0
	str r3, [r4]
	str r5, [r6]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r2, [r1]
	ldr r1, .L080D9E18 @ =__vt_15ClockTransition
	str r1, [r0]
	str r2, [r0, #4]
	str r3, [r6]
	str r5, [r0, #8]
	b .L080DA07A
	.align 2, 0
.L080D9E10: .4byte __vt_17ReturnToGameScene
.L080D9E14: .4byte 0x00000444
.L080D9E18: .4byte __vt_15ClockTransition
.L080D9E1C:
	movs r0, #0x10
	bl __builtin_new
	adds r6, r0, #0
	movs r4, #0xaa
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r4, [r4]
	mov r8, r4
	movs r5, #1
	mov sb, r5
	ldr r0, .L080D9EAC @ =__vt_17TownMapTransition
	str r0, [r6]
	str r4, [r6, #4]
	movs r0, #0x14
	bl __builtin_new
	ldr r1, .L080D9EB0 @ =__vt_26TownMapSelectionTransition
	str r1, [r0]
	movs r1, #0
	strb r1, [r0, #4]
	adds r5, r0, #6
	movs r3, #0x8d
	lsls r3, r3, #2
	ldrh r2, [r0, #6]
	ldr r4, .L080D9EB4 @ =0xFFFFFC00
	adds r1, r4, #0
	ands r1, r2
	orrs r1, r3
	strh r1, [r0, #6]
	ldrb r2, [r5, #1]
	movs r3, #3
	adds r1, r3, #0
	ands r1, r2
	strb r1, [r5, #1]
	ldrh r2, [r5, #2]
	adds r1, r4, #0
	ands r1, r2
	strh r1, [r5, #2]
	ldrb r1, [r5, #3]
	ands r3, r1
	strb r3, [r5, #3]
	ldrh r1, [r5, #4]
	ands r4, r1
	strh r4, [r5, #4]
	ldr r1, .L080D9EB8 @ =__vt_23TownMapReturnTransition
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #0xc]
	mov r2, sb
	str r2, [r0, #0x10]
	str r0, [r6, #8]
	str r2, [r6, #0xc]
	movs r3, #0xac
	lsls r3, r3, #3
	add r3, sp
	ldr r4, [r3]
	adds r5, r4, #0
	ldr r1, [r5]
	cmp r6, r1
	beq .L080D9EA8
	cmp r1, #0
	beq .L080D9EA8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080D9EA8:
	str r6, [r4]
	b .L080DA0E4
	.align 2, 0
.L080D9EAC: .4byte __vt_17TownMapTransition
.L080D9EB0: .4byte __vt_26TownMapSelectionTransition
.L080D9EB4: .4byte 0xFFFFFC00
.L080D9EB8: .4byte __vt_23TownMapReturnTransition
.L080D9EBC:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #6
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r6, #0xaa
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	ldr r6, [r6]
	mov r8, r6
	movs r6, #0x89
	lsls r6, r6, #3
	add r6, sp
	adds r1, r6, #0
	ldm r4!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, .L080D9F24 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r4, .L080D9F28 @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0xc
	bl __builtin_new
	ldr r5, [r4]
	movs r3, #0
	str r3, [r4]
	str r5, [r6]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r2, [r1]
	ldr r1, .L080D9F2C @ =vtable_unk_080E5E94
	str r1, [r0]
	str r2, [r0, #4]
	str r3, [r6]
	str r5, [r0, #8]
	b .L080DA07A
	.align 2, 0
.L080D9F24: .4byte __vt_17ReturnToGameScene
.L080D9F28: .4byte 0x00000444
.L080D9F2C: .4byte vtable_unk_080E5E94
.L080D9F30:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #7
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r5, #0xaa
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r5, [r5]
	mov r8, r5
	movs r6, #0x89
	lsls r6, r6, #3
	add r6, sp
	adds r1, r6, #0
	ldm r4!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, .L080D9F9C @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r4, .L080D9FA0 @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0x10
	bl __builtin_new
	ldr r5, [r4]
	movs r2, #0
	str r2, [r4]
	str r5, [r6]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r1, .L080D9FA4 @ =vtable_unk_080E5EB4
	str r1, [r0]
	str r2, [r6]
	str r5, [r0, #4]
	str r3, [r0, #8]
	strb r2, [r0, #0xc]
	b .L080DA07A
	.align 2, 0
.L080D9F9C: .4byte __vt_17ReturnToGameScene
.L080D9FA0: .4byte 0x00000444
.L080D9FA4: .4byte vtable_unk_080E5EB4
.L080D9FA8:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #8
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r5, #0xaa
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r5, [r5]
	mov r8, r5
	movs r6, #0x89
	lsls r6, r6, #3
	add r6, sp
	adds r1, r6, #0
	ldm r4!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, .L080DA008 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r4, .L080DA00C @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0xc
	bl __builtin_new
	ldr r5, [r4]
	movs r2, #0
	str r2, [r4]
	str r5, [r6]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r1, .L080DA010 @ =vtable_unk_080E5EA4
	b .L080DA072
	.align 2, 0
.L080DA008: .4byte __vt_17ReturnToGameScene
.L080DA00C: .4byte 0x00000444
.L080DA010: .4byte vtable_unk_080E5EA4
.L080DA014:
	movs r4, #0x87
	lsls r4, r4, #3
	add r4, sp
	movs r0, #4
	str r0, [r4]
	movs r0, #0x14
	bl __builtin_new
	movs r5, #0xaa
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	ldr r5, [r5]
	mov r8, r5
	movs r6, #0x89
	lsls r6, r6, #3
	add r6, sp
	adds r1, r6, #0
	ldm r4!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, .L080DA0B8 @ =__vt_17ReturnToGameScene
	str r1, [r0]
	mov r1, r8
	str r1, [r0, #4]
	adds r2, r0, #0
	adds r2, #8
	movs r1, #0x89
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r4, .L080DA0BC @ =0x00000444
	add r4, sp
	str r0, [r4]
	movs r0, #0xc
	bl __builtin_new
	ldr r5, [r4]
	movs r2, #0
	str r2, [r4]
	str r5, [r6]
	movs r1, #0xaa
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r1, .L080DA0C0 @ =__vt_22RucksackMenuTransition
.L080DA072:
	str r1, [r0]
	str r2, [r6]
	str r5, [r0, #4]
	str r3, [r0, #8]
.L080DA07A:
	movs r2, #0xac
	lsls r2, r2, #3
	add r2, sp
	ldr r5, [r2]
	adds r4, r0, #0
	adds r3, r5, #0
	ldr r1, [r3]
	cmp r4, r1
	beq .L080DA09C
	cmp r1, #0
	beq .L080DA09C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DA09C:
	str r4, [r5]
	ldr r0, .L080DA0BC @ =0x00000444
	add r0, sp
	ldr r1, [r0]
	cmp r1, #0
	beq .L080DA0E4
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
	b .L080DA0E4
	.align 2, 0
.L080DA0B8: .4byte __vt_17ReturnToGameScene
.L080DA0BC: .4byte 0x00000444
.L080DA0C0: .4byte __vt_22RucksackMenuTransition
.L080DA0C4:
	movs r4, #1
	movs r5, #0x9f
	lsls r5, r5, #3
	add r5, sp
	str r4, [r5]
	ldr r0, [r7]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	movs r0, #0xd
	movs r6, #0xab
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	str r0, [r6]
.L080DA0E4:
	movs r0, #0x9f
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	cmp r0, #0
	beq .L080DA0F4
	bl .L080DAAE6
.L080DA0F4:
	ldr r0, [r7]
	bl DisableInput__14MainMenuWidget
	ldr r1, .L080DA114 @ =0x0000055C
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r1, .L080DA118 @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	movs r0, #9
	bl .L080DAADC
	.align 2, 0
.L080DA114: .4byte 0x0000055C
.L080DA118: .4byte 0x00000889
.L080DA11C:
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1f
	lsls r0, r2, #0x1e
	lsrs r0, r0, #0x1f
	cmn r1, r0
	bne .L080DA12C
	bl .L080DAAE6
.L080DA12C:
	ldr r0, [r4]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	movs r0, #8
	b .L080DA804
.L080DA13A:
	mov r4, sl
	adds r4, #0xb8
	ldr r0, [r4]
	bl GetPhase__C13ControlWidget
	cmp r0, #0
	beq .L080DA14C
	bl .L080DAAE6
.L080DA14C:
	movs r5, #0
	ldr r1, [r4]
	cmp r5, r1
	beq .L080DA164
	cmp r1, #0
	beq .L080DA164
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DA164:
	str r5, [r4]
	movs r0, #0xc
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __23MapClockStatusHudWidgetUiUiUiUi
	mov r4, sl
	adds r4, #0xb4
	adds r5, r0, #0
	ldr r1, [r4]
	adds r6, r4, #0
	cmp r5, r1
	beq .L080DA198
	cmp r1, #0
	beq .L080DA198
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DA198:
	str r5, [r4]
	movs r4, #0xaa
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r1, [r4]
	ldr r5, .L080DA22C @ =0x00002210
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DA1C4
	ldr r7, .L080DA230 @ =0x000034C4
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DA1C4
	ldr r0, [r6]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0xc]
	bl _call_via_r1
.L080DA1C4:
	ldr r4, [r6]
	movs r5, #0
	ldr r1, .L080DA234 @ =0x00000564
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r1, [r0]
	adds r1, #0xb0
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DA1F8
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	ldrh r1, [r0, #0x12]
	lsls r1, r1, #0x15
	lsrs r1, r1, #0x1a
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DA1FA
.L080DA1F8:
	movs r5, #1
.L080DA1FA:
	adds r2, r5, #0
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r1, [r3]
	adds r1, #0x10
	adds r0, r4, #0
	adds r0, #8
	bl UpdateMapClockStatusHudCalendar
	mov r0, sl
	adds r0, #0xb4
	ldr r0, [r0]
	movs r4, #0xaa
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	ldr r1, [r4]
	ldr r1, [r1, #8]
	adds r0, #8
	bl SetMapClockStatusHudUnkSelector
	movs r0, #0
	b .L080DA790
	.align 2, 0
.L080DA22C: .4byte 0x00002210
.L080DA230: .4byte 0x000034C4
.L080DA234: .4byte 0x00000564
.L080DA238:
	ldr r6, .L080DA270 @ =0x0000055C
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	cmp r1, #0
	beq .L080DA256
	bl .L080DAAE6
.L080DA256:
	movs r7, #0xac
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	str r1, [r7]
	ldr r3, .L080DA274 @ =0x000004DC
	add r3, sp
	ldr r3, [r3]
	str r0, [r3]
	bl func_080DB0CC
	.align 2, 0
.L080DA270: .4byte 0x0000055C
.L080DA274: .4byte 0x000004DC
.L080DA278:
	ldr r4, .L080DA33C @ =gUnk_0300040C
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #8
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r1, r1, r5
	ldr r1, [r1]
	ldr r1, [r1, #0xc]
	@ 080DA28A bl [method_0803EFD8__13AScriptEngine]
	bl _call_via_r1
	cmp r0, #0
	beq .L080DA296
	bl .L080DAAE6
.L080DA296:
	ldr r4, [r4]
	movs r6, #0xde
	lsls r6, r6, #2
	adds r5, r4, r6
	movs r2, #0
	movs r1, #0
	ldr r0, [r5]
	cmp r0, #0
	bne .L080DA2AA
	movs r1, #1
.L080DA2AA:
	cmp r1, #0
	beq .L080DA2D8
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r0, r4, r7
	movs r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DA2BE
	movs r1, #1
.L080DA2BE:
	cmp r1, #0
	beq .L080DA2D8
	movs r1, #0x9a
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DA2D2
	movs r1, #1
.L080DA2D2:
	cmp r1, #0
	beq .L080DA2D8
	movs r2, #1
.L080DA2D8:
	adds r3, r2, #0
	cmp r3, #0
	beq .L080DA2E0
	b .L080DA468
.L080DA2E0:
	movs r1, #0
	ldr r0, [r5]
	cmp r0, #0
	bne .L080DA2EA
	movs r1, #1
.L080DA2EA:
	cmp r1, #0
	bne .L080DA344
	adds r7, r5, #4
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	ldr r3, .L080DA340 @ =0x000004FC
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	ldr r4, .L080DA33C @ =gUnk_0300040C
	mov r8, r4
	movs r3, #0x96
	lsls r3, r3, #3
	add r3, sp
	cmp r0, #0
	beq .L080DA332
	lsls r0, r0, #3
	adds r0, #4
	adds r0, r5, r0
	adds r1, r5, #0
	adds r1, #0xc
	cmp r1, r0
	beq .L080DA32C
	adds r6, r1, #0
	subs r0, r0, r6
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DA32C
.L080DA322:
	ldm r6!, {r0, r1}
	stm r7!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DA322
.L080DA32C:
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
.L080DA332:
	movs r0, #0x96
	lsls r0, r0, #3
	add r0, sp
	ldr r6, .L080DA340 @ =0x000004FC
	b .L080DA3A6
	.align 2, 0
.L080DA33C: .4byte gUnk_0300040C
.L080DA340: .4byte 0x000004FC
.L080DA344:
	adds r4, r5, #0
	adds r4, #0x14
	movs r1, #0
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne .L080DA352
	movs r1, #1
.L080DA352:
	cmp r1, #0
	bne .L080DA3BC
	adds r7, r5, #0
	adds r7, #0x18
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x1c]
	ldr r3, .L080DA3B4 @ =0x00000504
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	adds r6, r4, #0
	ldr r4, .L080DA3B8 @ =gUnk_0300040C
	mov r8, r4
	movs r3, #0x96
	lsls r3, r3, #3
	add r3, sp
	cmp r0, #0
	beq .L080DA39E
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r6, r0
	adds r0, r5, #0
	adds r0, #0x20
	cmp r0, r1
	beq .L080DA398
	adds r5, r0, #0
	subs r0, r1, r5
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DA398
.L080DA38E:
	ldm r5!, {r0, r1}
	stm r7!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DA38E
.L080DA398:
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
.L080DA39E:
	movs r0, #0x96
	lsls r0, r0, #3
	add r0, sp
	ldr r6, .L080DA3B4 @ =0x00000504
.L080DA3A6:
	add r6, sp
	ldr r5, [r6]
	ldr r6, [r6, #4]
	str r5, [r0]
	str r6, [r0, #4]
	b .L080DA44E
	.align 2, 0
.L080DA3B4: .4byte 0x00000504
.L080DA3B8: .4byte gUnk_0300040C
.L080DA3BC:
	movs r7, #0xac
	lsls r7, r7, #1
	adds r6, r5, r7
	movs r1, #0
	ldr r0, [r6]
	cmp r0, #0
	bne .L080DA3CC
	movs r1, #1
.L080DA3CC:
	cmp r1, #0
	bne .L080DA438
	movs r1, #0xae
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	ldr r2, [r4, #4]
	ldr r3, .L080DA430 @ =0x0000050C
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	ldr r7, .L080DA434 @ =gUnk_0300040C
	mov r8, r7
	movs r3, #0x96
	lsls r3, r3, #3
	add r3, sp
	cmp r0, #0
	beq .L080DA41C
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r6, r0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r5, r2
	cmp r0, r1
	beq .L080DA416
	adds r5, r0, #0
	adds r7, r4, #0
	subs r0, r1, r5
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DA416
.L080DA40C:
	ldm r5!, {r0, r1}
	stm r7!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DA40C
.L080DA416:
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
.L080DA41C:
	movs r0, #0x96
	lsls r0, r0, #3
	add r0, sp
	ldr r5, .L080DA430 @ =0x0000050C
	add r5, sp
	ldr r4, [r5]
	ldr r5, [r5, #4]
	str r4, [r0]
	str r5, [r0, #4]
	b .L080DA44E
	.align 2, 0
.L080DA430: .4byte 0x0000050C
.L080DA434: .4byte gUnk_0300040C
.L080DA438:
	movs r1, #0x96
	lsls r1, r1, #3
	add r1, sp
	movs r0, #0x96
	lsls r0, r0, #3
	add r0, sp
	str r3, [r0]
	str r3, [r1, #4]
	ldr r6, .L080DA464 @ =gUnk_0300040C
	mov r8, r6
	adds r3, r1, #0
.L080DA44E:
	mov r7, r8
	ldr r0, [r7]
	adds r0, #8
	movs r1, #0x96
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	ldr r2, [r3, #4]
	bl LoadById__12ScriptEngineii
	b .L080DAAE6
	.align 2, 0
.L080DA464: .4byte gUnk_0300040C
.L080DA468:
	mov r4, sl
	adds r4, #0xac
	ldr r0, [r4]
	cmp r0, #0
	beq .L080DA480
	movs r5, #0
	cmp r5, r0
	beq .L080DA47E
	movs r1, #3
	bl _._12UiStateOwner
.L080DA47E:
	str r5, [r4]
.L080DA480:
	mov r4, sl
	adds r4, #0xf0
	movs r5, #0
	ldr r0, [r4]
	cmp r5, r0
	beq .L080DA490
	bl __builtin_delete
.L080DA490:
	str r5, [r4]
	ldr r1, .L080DA578 @ =0x00000564
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	ldr r1, [r0]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	mov r0, sl
	adds r0, #0xb4
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne .L080DA4E4
	movs r0, #0xc
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __23MapClockStatusHudWidgetUiUiUiUi
	adds r5, r6, #0
	adds r4, r0, #0
	ldr r1, [r6]
	cmp r4, r1
	beq .L080DA4E2
	cmp r1, #0
	beq .L080DA4E2
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DA4E2:
	str r4, [r5]
.L080DA4E4:
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r1, [r3]
	ldr r4, .L080DA57C @ =0x00002210
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DA50E
	ldr r5, .L080DA580 @ =0x000034C4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DA50E
	ldr r0, [r6]
	ldr r1, [r0, #4]
	ldr r1, [r1, #0x10]
	bl _call_via_r1
.L080DA50E:
	ldr r4, [r6]
	movs r5, #0
	ldr r6, .L080DA578 @ =0x00000564
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	ldr r1, [r0]
	adds r1, #0xb0
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DA542
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldrh r1, [r0, #0x12]
	lsls r1, r1, #0x15
	lsrs r1, r1, #0x1a
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DA544
.L080DA542:
	movs r5, #1
.L080DA544:
	adds r2, r5, #0
	movs r0, #0xaa
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0x10
	adds r0, r4, #0
	adds r0, #8
	bl UpdateMapClockStatusHudCalendar
	mov r0, sl
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r1, [r2]
	ldr r1, [r1, #8]
	adds r0, #8
	bl SetMapClockStatusHudUnkSelector
	movs r0, #0
	b .L080DA804
	.align 2, 0
.L080DA578: .4byte 0x00000564
.L080DA57C: .4byte 0x00002210
.L080DA580: .4byte 0x000034C4
.L080DA584:
	mov r0, sl
	adds r0, #0xac
	ldr r0, [r0]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	beq .L080DA594
	b .L080DAAE6
.L080DA594:
	b .L080DA76A
.L080DA596:
	mov r4, sl
	adds r4, #0xac
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #0
	beq .L080DA5A6
	b .L080DAAE6
.L080DA5A6:
	movs r5, #0
	ldr r0, [r4]
	cmp r5, r0
	beq .L080DA5B8
	cmp r0, #0
	beq .L080DA5B8
	movs r1, #3
	bl _._12UiStateOwner
.L080DA5B8:
	str r5, [r4]
	b .L080DA78E
.L080DA5BC:
	mov r0, sl
	adds r0, #0xac
	ldr r0, [r0]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	beq .L080DA5CC
	b .L080DAAE6
.L080DA5CC:
	b .L080DAA88
.L080DA5CE:
	add r0, sp, #0x10
	ldrh r4, [r0, #8]
	mov r0, sl
	adds r0, #0xac
	ldr r0, [r0]
	bl GetState__C12UiStateOwner
	cmp r0, #6
	bls .L080DA5E2
	b .L080DAAE6
.L080DA5E2:
	lsls r0, r0, #2
	ldr r1, .L080DA5EC @ =.L080DA5F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080DA5EC: .4byte .L080DA5F0
.L080DA5F0: @ jump table
	.4byte .L080DA60C @ case 0
	.4byte .L080DA60C @ case 1
	.4byte .L080DA60C @ case 2
	.4byte .L080DA60C @ case 3
	.4byte .L080DA62C @ case 4
	.4byte .L080DA62C @ case 5
	.4byte .L080DA60C @ case 6
.L080DA60C:
	movs r0, #2
	movs r7, #0xab
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	str r0, [r7]
	ldr r0, .L080DA628 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #4
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA628: .4byte gUnk_0300040C
.L080DA62C:
	movs r1, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DA654
	movs r0, #0xab
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	str r1, [r0]
	ldr r0, .L080DA650 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #5
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA650: .4byte gUnk_0300040C
.L080DA654:
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq .L080DA678
	movs r2, #0xab
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	str r1, [r2]
	ldr r0, .L080DA674 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #0
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA674: .4byte gUnk_0300040C
.L080DA678:
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq .L080DA69C
	movs r3, #0xab
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	str r1, [r3]
	ldr r0, .L080DA698 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #1
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA698: .4byte gUnk_0300040C
.L080DA69C:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq .L080DA6C0
	movs r4, #0xab
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	str r1, [r4]
	ldr r0, .L080DA6BC @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #2
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA6BC: .4byte gUnk_0300040C
.L080DA6C0:
	movs r0, #0x10
	ands r4, r0
	cmp r4, #0
	bne .L080DA6CA
	b .L080DAAE6
.L080DA6CA:
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	str r1, [r5]
	ldr r0, .L080DA6E4 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	movs r1, #3
	bl Push__12ScriptEnginei
	b .L080DAAE6
	.align 2, 0
.L080DA6E4: .4byte gUnk_0300040C
.L080DA6E8:
	ldr r6, .L080DA72C @ =0x0000055C
	add r6, sp
	ldr r6, [r6]
	ldr r0, [r6]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	cmp r3, #0
	beq .L080DA704
	b .L080DAAE6
.L080DA704:
	mov r1, sl
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	mov r7, sl
	ldrh r1, [r7, #0x10]
	ldr r0, .L080DA730 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r7, #0x10]
	mov r2, sl
	adds r2, #0x60
	ldrh r1, [r2]
	ldr r0, .L080DA734 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	mov r0, sl
	adds r0, #0x5c
	strh r3, [r0]
	b .L080DAAB8
	.align 2, 0
.L080DA72C: .4byte 0x0000055C
.L080DA730: .4byte 0x0000F0FF
.L080DA734: .4byte 0x0000FF3F
.L080DA738:
	ldr r2, .L080DA754 @ =0x0000055C
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	bge .L080DA752
	b .L080DAAE6
.L080DA752:
	b .L080DA802
	.align 2, 0
.L080DA754: .4byte 0x0000055C
.L080DA758:
	mov r1, sl
	adds r1, #0xe0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080DA76A
	b .L080DAAE6
.L080DA76A:
	movs r0, #2

	thumb_func_start sub_080DA76C
sub_080DA76C: @ 0x080DA76C
	movs r4, #0xab
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	str r0, [r4]
	b .L080DAAE6
.L080DA778:
	mov r4, sl
	adds r4, #0xe4
	ldr r0, [r4]
	bl IsActorAxisMotionComplete
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DA78A
	b .L080DAAE6
.L080DA78A:
	movs r0, #0
	str r0, [r4]
.L080DA78E:
	movs r0, #2
.L080DA790:
	movs r5, #0xab
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	str r0, [r5]
	b .L080DAAE6
.L080DA79C:
	mov r5, sl
	adds r5, #0xac
	ldr r0, [r5]
	bl GetState__C12UiStateOwner
	cmp r0, #6
	bne .L080DA7AC
	b .L080DAAE6
.L080DA7AC:
	ldr r0, .L080DA7C4 @ =gUnk_0300040C
	ldr r4, [r0]
	adds r4, #8
	ldr r0, [r5]
	bl GetChoiceResult__C12UiStateOwner
	adds r1, r0, #0
	adds r0, r4, #0
	bl Push__12ScriptEnginei
	b .L080DAA88
	.align 2, 0
.L080DA7C4: .4byte gUnk_0300040C
.L080DA7C8:
	ldr r7, .L080DA7DC @ =0x00000564
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r1, [r0]
	ldr r1, [r1, #0x28]
	bl _call_via_r1
	b .L080DAAB2
	.align 2, 0
.L080DA7DC: .4byte 0x00000564
.L080DA7E0:
	ldr r2, .L080DA810 @ =0x00000564
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0
	bl _call_via_r2
	ldr r1, [r0, #0x14]
	ldr r1, [r1, #0x3c]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DA802
	b .L080DAAE6
.L080DA802:
	movs r0, #2
.L080DA804:
	movs r3, #0xab
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	str r0, [r3]
	b .L080DAAE6
	.align 2, 0
.L080DA810: .4byte 0x00000564
.L080DA814:
	mov r0, sl
	adds r0, #0xef
	ldrb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	add r4, sp
	str r0, [r4]
	cmp r1, #0x78
	bne .L080DA868
	subs r0, #5
	movs r3, #0
	strb r3, [r0]
	mov r5, sl
	ldrh r1, [r5, #0x10]
	ldr r0, .L080DA864 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r5, #0x10]
	movs r2, #0x87
	lsls r2, r2, #3
	add r2, sp
	movs r0, #0x3f
	strh r0, [r2]
	mov r1, sl
	adds r1, #0x60
	movs r6, #0x87
	lsls r6, r6, #3
	add r6, sp
	ldrh r0, [r6]
	strh r0, [r1]
	strh r3, [r2]
	adds r1, #2
	ldrh r0, [r6]
	strh r0, [r1]
	movs r0, #2
.L080DA858:
	movs r7, #0xab
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	str r0, [r7]
	b .L080DAAE6
	.align 2, 0
.L080DA864: .4byte 0x0000FEFF
.L080DA868:
	mov r0, sl
	adds r0, #0xec
	ldrh r1, [r0]
	mov r8, sl
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	ldr r2, .L080DA8C4 @ =0x05000002
	movs r3, #2
	bl __21DmaTransferDescriptorUiPvUi
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	ldr r1, .L080DA8C8 @ =0x00000514
	add r1, sp
	str r0, [r1]
	mov r2, sl
	ldr r1, [r2, #4]
	ldr r0, [r2, #0xc]
	cmp r1, r0
	beq .L080DA8CC
	cmp r1, #0
	beq .L080DA8A8
	adds r0, r1, #0
	movs r1, #0x87
	lsls r1, r1, #3
	add r1, sp
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r0]
.L080DA8A8:
	mov r6, sl
	ldr r0, [r6, #4]
	adds r0, #0x10
	str r0, [r6, #4]
	adds r6, #0x62
	movs r7, #0xa9
	lsls r7, r7, #3
	add r7, sp
	str r6, [r7]
	movs r0, #0xee
	add r0, sl
	mov sb, r0
	b .L080DA9FE
	.align 2, 0
.L080DA8C4: .4byte 0x05000002
.L080DA8C8: .4byte 0x00000514
.L080DA8CC:
	ldr r2, .L080DA924 @ =0x00000584
	add r2, sp
	str r1, [r2]
	movs r0, #1
	ldr r1, .L080DA928 @ =0x000004BC
	add r1, sp
	str r0, [r1]
	mov r3, sl
	ldr r0, [r3]
	ldr r4, [r2]
	subs r0, r4, r0
	asrs r4, r0, #4
	movs r0, #0x97
	lsls r0, r0, #3
	add r0, sp
	str r4, [r0]
	ldr r2, .L080DA928 @ =0x000004BC
	add r2, sp
	ldr r0, [r1]
	movs r1, #0x97
	lsls r1, r1, #3
	add r1, sp
	cmp r4, r0
	bhs .L080DA8FE
	adds r1, r2, #0
.L080DA8FE:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080DA92C
	lsls r4, r0, #4
	adds r0, r4, #0
	bl malloc
	movs r5, #0xb1
	lsls r5, r5, #3
	add r5, sp
	str r4, [r5]
	cmp r0, #0
	bne .L080DA936
	adds r0, r4, #0
	bl RetryMemoryAllocation
	b .L080DA936
	.align 2, 0
.L080DA924: .4byte 0x00000584
.L080DA928: .4byte 0x000004BC
.L080DA92C:
	movs r0, #0
	movs r6, #0xb1
	lsls r6, r6, #3
	add r6, sp
	str r0, [r6]
.L080DA936:
	adds r5, r0, #0
	adds r4, r5, #0
	mov r7, r8
	ldr r2, [r7]
	adds r3, r4, #0
	mov r0, sl
	adds r0, #0x62
	movs r1, #0xa9
	lsls r1, r1, #3
	add r1, sp
	str r0, [r1]
	movs r5, #0xee
	add r5, sl
	mov sb, r5
	ldr r6, .L080DA9A0 @ =0x00000584
	add r6, sp
	ldr r6, [r6]
	cmp r2, r6
	beq .L080DA97A
.L080DA95C:
	cmp r3, #0
	beq .L080DA96C
	adds r0, r3, #0
	adds r1, r2, #0
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldr r1, [r1]
	str r1, [r0]
.L080DA96C:
	adds r2, #0x10
	adds r3, #0x10
	ldr r7, .L080DA9A0 @ =0x00000584
	add r7, sp
	ldr r7, [r7]
	cmp r2, r7
	bne .L080DA95C
.L080DA97A:
	adds r5, r3, #0
	ldr r0, .L080DA9A4 @ =0x000004BC
	add r0, sp
	ldr r0, [r0]
	cmp r0, #1
	bne .L080DA9AC
	cmp r5, #0
	beq .L080DA99A
	adds r0, r5, #0
	ldr r2, .L080DA9A8 @ =0x00000514
	add r2, sp
	ldr r1, [r2]
	ldm r1!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldr r1, [r1]
	str r1, [r0]
.L080DA99A:
	adds r5, #0x10
	b .L080DA9D2
	.align 2, 0
.L080DA9A0: .4byte 0x00000584
.L080DA9A4: .4byte 0x000004BC
.L080DA9A8: .4byte 0x00000514
.L080DA9AC:
	adds r3, r0, #0
	adds r2, r5, #0
	cmp r3, #0
	beq .L080DA9D0
.L080DA9B4:
	cmp r2, #0
	beq .L080DA9C8
	adds r0, r2, #0
	ldr r5, .L080DAA48 @ =0x00000514
	add r5, sp
	ldr r1, [r5]
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldr r1, [r1]
	str r1, [r0]
.L080DA9C8:
	subs r3, #1
	adds r2, #0x10
	cmp r3, #0
	bne .L080DA9B4
.L080DA9D0:
	adds r5, r2, #0
.L080DA9D2:
	mov r6, r8
	ldr r2, [r6, #4]
	ldr r0, [r6]
	adds r1, r0, #0
	cmp r0, r2
	beq .L080DA9E4
.L080DA9DE:
	adds r1, #0x10
	cmp r1, r2
	bne .L080DA9DE
.L080DA9E4:
	cmp r0, #0
	beq .L080DA9EC
	bl free
.L080DA9EC:
	movs r7, #0xb1
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	adds r0, r7, r4
	mov r1, r8
	str r4, [r1]
	str r5, [r1, #4]
	str r0, [r1, #0xc]
.L080DA9FE:
	ldr r1, .L080DAA4C @ =gScreenFlashBlendStrengths
	movs r2, #0xaf
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r3, sb
	strb r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #3
	add r2, sp
	ldrb r0, [r3]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2]
	movs r5, #0x87
	lsls r5, r5, #3
	add r5, sp
	ldrh r0, [r5]
	movs r6, #0xa9
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	strh r0, [r6]
	movs r7, #0xaf
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	b .L080DAAE6
	.align 2, 0
.L080DAA48: .4byte 0x00000514
.L080DAA4C: .4byte gScreenFlashBlendStrengths
.L080DAA50:
	movs r2, #0xac
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r1, [r2]
	movs r0, #0
	str r0, [r2]
	ldr r4, .L080DAA68 @ =0x000004DC
	add r4, sp
	ldr r4, [r4]
	str r1, [r4]
	b func_080DB0CC
	.align 2, 0
.L080DAA68: .4byte 0x000004DC
.L080DAA6C:
	ldr r5, .L080DAA98 @ =0x00000564
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5d
	bl _call_via_r2
	bl HasEntityStarSparkleEffect
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DAAE6
.L080DAA88:
	movs r0, #2
	movs r6, #0xab
	lsls r6, r6, #3
	add r6, sp
	ldr r6, [r6]
	str r0, [r6]
	b .L080DAAE6
	.align 2, 0
.L080DAA98: .4byte 0x00000564
.L080DAA9C:
	ldr r7, .L080DAAC8 @ =0x00000564
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5d
	bl _call_via_r2
	bl IsEntityNewYearSunriseEffectComplete
.L080DAAB2:
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DAAE6
.L080DAAB8:
	movs r0, #2
.L080DAABA:
	movs r1, #0xab
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	str r0, [r1]
	b .L080DAAE6
	.align 2, 0
.L080DAAC8: .4byte 0x00000564
.L080DAACC:
	mov r0, sl
	adds r0, #0xbc
	bl IsActive__C23HardwareMusicPlayerSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DAAE6
	movs r0, #2
.L080DAADC:
	movs r2, #0xab
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	str r0, [r2]
.L080DAAE6:
	ldr r3, .L080DAB80 @ =0x000004F4
	add r3, sp
	ldr r3, [r3]
	cmp r3, #0
	bne .L080DAB10
	movs r1, #0x98
	lsls r1, r1, #3
	add r1, sp
	movs r0, #0x98
	lsls r0, r0, #3
	add r0, sp
	add r4, sp, #0x10
	str r4, [r0]
	ldr r5, .L080DAB84 @ =0x00000564
	add r5, sp
	ldr r5, [r5]
	ldr r0, [r5]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	bl _call_via_r2
.L080DAB10:
	mov r0, sl
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DAB1C
	b .L080DACC0
.L080DAB1C:
	mov r0, sl
	adds r0, #0xe9
	ldrb r0, [r0]
	ldr r1, .L080DAB88 @ =0x0000FFFF
	cmp r0, #0
	beq .L080DAB2A
	movs r1, #0
.L080DAB2A:
	mov r8, sl
	movs r0, #0x87
	lsls r0, r0, #3
	add r0, sp
	movs r2, #0xa0
	lsls r2, r2, #0x13
	movs r3, #2
	bl __21DmaTransferDescriptorUiPvUi
	movs r6, #0x87
	lsls r6, r6, #3
	add r6, sp
	movs r7, #0xa3
	lsls r7, r7, #3
	add r7, sp
	str r6, [r7]
	mov r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0, #0xc]
	cmp r1, r0
	beq .L080DAB90
	cmp r1, #0
	beq .L080DAB6A
	adds r0, r1, #0
	movs r2, #0xa3
	lsls r2, r2, #3
	add r2, sp
	ldr r1, [r2]
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r0]
.L080DAB6A:
	mov r6, sl
	ldr r0, [r6, #4]
	adds r0, #0x10
	str r0, [r6, #4]
	adds r6, #0xb4
	mov r7, sl
	adds r7, #0xea
	ldr r0, .L080DAB8C @ =0x00000574
	add r0, sp
	str r7, [r0]
	b .L080DACF8
	.align 2, 0
.L080DAB80: .4byte 0x000004F4
.L080DAB84: .4byte 0x00000564
.L080DAB88: .4byte 0x0000FFFF
.L080DAB8C: .4byte 0x00000574
.L080DAB90:
	movs r2, #0xb1
	lsls r2, r2, #3
	add r2, sp
	str r1, [r2]
	movs r0, #1
	movs r1, #0x99
	lsls r1, r1, #3
	add r1, sp
	str r0, [r1]
	mov r3, sl
	ldr r0, [r3]
	ldr r4, [r2]
	subs r0, r4, r0
	asrs r4, r0, #4
	ldr r0, .L080DABE4 @ =0x000004C4
	add r0, sp
	str r4, [r0]
	movs r2, #0x99
	lsls r2, r2, #3
	add r2, sp
	ldr r0, [r1]
	ldr r1, .L080DABE4 @ =0x000004C4
	add r1, sp
	cmp r4, r0
	bhs .L080DABC4
	adds r1, r2, #0
.L080DABC4:
	ldr r0, [r1]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080DABE8
	lsls r4, r0, #4
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080DABEC
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080DABEC
	.align 2, 0
.L080DABE4: .4byte 0x000004C4
.L080DABE8:
	movs r0, #0
	mov sb, r0
.L080DABEC:
	adds r5, r0, #0
	ldr r6, .L080DAC5C @ =0x0000058C
	add r6, sp
	str r5, [r6]
	mov r7, r8
	ldr r2, [r7]
	adds r3, r5, #0
	mov r6, sl
	adds r6, #0xb4
	mov r0, sl
	adds r0, #0xea
	ldr r1, .L080DAC60 @ =0x00000574
	add r1, sp
	str r0, [r1]
	movs r4, #0xb1
	lsls r4, r4, #3
	add r4, sp
	ldr r4, [r4]
	cmp r2, r4
	beq .L080DAC34
.L080DAC14:
	cmp r3, #0
	beq .L080DAC24
	adds r0, r3, #0
	adds r1, r2, #0
	ldm r1!, {r4, r5, r7}
	stm r0!, {r4, r5, r7}
	ldr r1, [r1]
	str r1, [r0]
.L080DAC24:
	adds r2, #0x10
	adds r3, #0x10
	movs r5, #0xb1
	lsls r5, r5, #3
	add r5, sp
	ldr r5, [r5]
	cmp r2, r5
	bne .L080DAC14
.L080DAC34:
	adds r5, r3, #0
	movs r0, #0x99
	lsls r0, r0, #3
	add r0, sp
	ldr r0, [r0]
	cmp r0, #1
	bne .L080DAC64
	cmp r5, #0
	beq .L080DAC58
	adds r0, r5, #0
	movs r7, #0xa3
	lsls r7, r7, #3
	add r7, sp
	ldr r1, [r7]
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
.L080DAC58:
	adds r5, #0x10
	b .L080DAC8C
	.align 2, 0
.L080DAC5C: .4byte 0x0000058C
.L080DAC60: .4byte 0x00000574
.L080DAC64:
	adds r3, r0, #0
	adds r2, r5, #0
	cmp r3, #0
	beq .L080DAC8A
.L080DAC6C:
	cmp r2, #0
	beq .L080DAC82
	adds r0, r2, #0
	movs r5, #0xa3
	lsls r5, r5, #3
	add r5, sp
	ldr r1, [r5]
	ldm r1!, {r4, r5, r7}
	stm r0!, {r4, r5, r7}
	ldr r1, [r1]
	str r1, [r0]
.L080DAC82:
	subs r3, #1
	adds r2, #0x10
	cmp r3, #0
	bne .L080DAC6C
.L080DAC8A:
	adds r5, r2, #0
.L080DAC8C:
	mov r7, r8
	ldr r2, [r7, #4]
	ldr r0, [r7]
	adds r1, r0, #0
	cmp r0, r2
	beq .L080DAC9E
.L080DAC98:
	adds r1, #0x10
	cmp r1, r2
	bne .L080DAC98
.L080DAC9E:
	cmp r0, #0
	beq .L080DACA6
	bl free
.L080DACA6:
	ldr r1, .L080DACBC @ =0x0000058C
	add r1, sp
	ldr r0, [r1]
	add r0, sb
	ldr r2, [r1]
	mov r3, r8
	str r2, [r3]
	str r5, [r3, #4]
	str r0, [r3, #0xc]
	b .L080DACF8
	.align 2, 0
.L080DACBC: .4byte 0x0000058C
.L080DACC0:
	mov r0, sl
	adds r0, #0x6c
	movs r1, #0x87
	lsls r1, r1, #3
	add r1, sp
	mov r4, sl
	str r4, [r1]
	ldr r5, .L080DAE3C @ =0x00000544
	add r5, sp
	ldr r5, [r5]
	str r5, [r1, #4]
	add r6, sp, #0x34
	str r6, [r1, #8]
	str r0, [r1, #0xc]
	ldr r7, .L080DAE40 @ =0x00000564
	add r7, sp
	ldr r7, [r7]
	ldr r0, [r7]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	bl _call_via_r2
	mov r6, sl
	adds r6, #0xb4
	adds r4, #0xea
	ldr r0, .L080DAE44 @ =0x00000574
	add r0, sp
	str r4, [r0]
.L080DACF8:
	ldr r1, [r6]
	mov r8, r1
	cmp r1, #0
	bne .L080DAD02
	b .L080DAE90
.L080DAD02:
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r5, [r2]
	movs r3, #0x10
	adds r3, r3, r5
	mov sb, r3
	ldr r7, .L080DAE48 @ =0x000004CC
	add r7, sp
	ldr r0, [r7]
	lsls r0, r0, #5
	ldr r1, [r5, #0x10]
	lsls r4, r1, #5
	lsrs r0, r0, #0x1a
	lsrs r1, r4, #0x1a
	cmp r0, r1
	beq .L080DAE02
	adds r0, r1, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DADEE
	lsrs r0, r4, #0x1a
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r0, r8
	adds r0, #8
	bl SetMapClockStatusHudMinuteDigits
	ldr r1, [r7]
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x10]
	lsls r2, r0, #0xb
	lsrs r1, r1, #0x1b
	lsrs r0, r2, #0x1b
	cmp r1, r0
	beq .L080DADEE
	ldr r0, [r6]
	lsrs r1, r2, #0x1b
	adds r0, #8
	bl SetMapClockStatusHudHour
	ldr r7, .L080DAE48 @ =0x000004CC
	add r7, sp
	ldrb r1, [r7, #1]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x1b
	adds r1, #1
	ldrb r3, [r5, #0x11]
	lsls r0, r3, #0x19
	lsrs r0, r0, #0x1b
	adds r4, r0, #1
	cmp r1, r4
	beq .L080DADEE
	ldr r0, [r6]
	mov r8, r0
	ldrb r2, [r5, #0x10]
	lsls r2, r2, #0x1d
	lsrs r2, r2, #0x1d
	lsls r0, r3, #0x1e
	lsrs r0, r0, #0x1e
	adds r2, #6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r4
	subs r1, #1
	cmp r1, #6
	bls .L080DADB0
	adds r0, r1, #0
	movs r1, #7
	bl __umodsi3
	adds r1, r0, #0
.L080DADB0:
	movs r0, #7
	ands r1, r0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r3, .L080DAE4C @ =0x0000051C
	add r3, sp
	ldrb r3, [r3]
	ands r2, r3
	orrs r2, r1
	ldr r0, .L080DAE4C @ =0x0000051C
	add r0, sp
	strb r2, [r0]
	lsls r2, r2, #0x1d
	lsrs r2, r2, #0x1d
	mov r0, r8
	adds r0, #8
	adds r1, r4, #0
	bl SetMapClockStatusHudDayAndWeekday
	ldrb r1, [r7, #1]
	lsls r1, r1, #0x1e
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #0x1e
	lsrs r2, r0, #0x1e
	cmp r1, r0
	beq .L080DADEE
	ldr r0, [r6]
	adds r0, #8
	adds r1, r2, #0
	bl SetMapClockStatusHudSeason
.L080DADEE:
	ldr r0, [r6]
	mov r1, sb
	ldr r2, [r1]
	lsls r2, r2, #5
	lsrs r2, r2, #0x1a
	movs r1, #1
	ands r1, r2
	adds r0, #8
	bl SetMapClockStatusHudColonVisible
.L080DAE02:
	ldr r0, [r6]
	movs r2, #0xaa
	lsls r2, r2, #3
	add r2, sp
	ldr r2, [r2]
	ldr r1, [r2]
	ldr r1, [r1, #8]
	adds r0, #8
	bl SetMapClockStatusHudUnkSelector
	movs r3, #0xaa
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	ldr r4, .L080DAE50 @ =0x00001C34
	adds r5, r0, r4
	adds r0, r5, #0
	bl IsEmpty__C9ToolStack
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DAE54
	ldr r0, [r6]
	adds r0, #8
	bl ClearMapClockStatusHudUnkValue
	b .L080DAE90
	.align 2, 0
.L080DAE3C: .4byte 0x00000544
.L080DAE40: .4byte 0x00000564
.L080DAE44: .4byte 0x00000574
.L080DAE48: .4byte 0x000004CC
.L080DAE4C: .4byte 0x0000051C
.L080DAE50: .4byte 0x00001C34
.L080DAE54:
	movs r7, #0xaa
	lsls r7, r7, #3
	add r7, sp
	ldr r7, [r7]
	ldr r4, [r7]
	ldr r0, .L080DAFA4 @ =0x00001BD8
	adds r4, r4, r0
	adds r0, r5, #0
	bl GetTool__C9ToolStack
	adds r1, r0, #0
	adds r0, r4, #0
	bl GetUpgradedTool__C6FarmerG4Tool
	movs r1, #0x9a
	lsls r1, r1, #3
	add r1, sp
	strb r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #3
	add r0, sp
	bl GetIconId__C4Tool
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6]
	adds r0, #8
	bl SetMapClockStatusHudUnkValue
.L080DAE90:
	ldr r1, .L080DAFA8 @ =0x00000574
	add r1, sp
	ldr r1, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080DAEA8
	ldr r2, .L080DAFAC @ =0x0000055C
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	bl Update__23HardwareBlendController
.L080DAEA8:
	movs r3, #0xab
	lsls r3, r3, #3
	add r3, sp
	ldr r3, [r3]
	ldr r0, [r3]
	cmp r0, #0
	beq .L080DAEB8
	b .L080DB0BC
.L080DAEB8:
	ldr r0, .L080DAFB0 @ =gUnk_0300040C
	ldr r1, [r0]
	movs r5, #0xde
	lsls r5, r5, #2
	adds r4, r1, r5
	movs r3, #0
	movs r2, #0
	ldr r0, [r4]
	cmp r0, #0
	bne .L080DAECE
	movs r2, #1
.L080DAECE:
	cmp r2, #0
	beq .L080DAEFC
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r0, r1, r6
	movs r2, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DAEE2
	movs r2, #1
.L080DAEE2:
	cmp r2, #0
	beq .L080DAEFC
	movs r7, #0x9a
	lsls r7, r7, #3
	adds r0, r1, r7
	movs r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DAEF6
	movs r1, #1
.L080DAEF6:
	cmp r1, #0
	beq .L080DAEFC
	movs r3, #1
.L080DAEFC:
	cmp r3, #0
	beq .L080DAF02
	b .L080DB0BC
.L080DAF02:
	ldr r1, .L080DAFAC @ =0x0000055C
	add r1, sp
	ldr r1, [r1]
	ldr r0, [r1]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r5, r1, #0x1f
	cmp r5, #0
	beq .L080DAF1E
	b .L080DB0BC
.L080DAF1E:
	ldr r2, .L080DAFB4 @ =0x00000564
	add r2, sp
	ldr r2, [r2]
	ldr r0, [r2]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0
	bl _call_via_r2
	adds r2, r0, #0
	cmp r2, #0
	beq .L080DAF4A
	ldr r0, [r2, #0x14]
	adds r0, #0x98
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DAF4A
	b .L080DB0BC
.L080DAF4A:
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #0
	bne .L080DAF54
	movs r1, #1
.L080DAF54:
	cmp r1, #0
	bne .L080DAFBC
	adds r6, r4, #4
	ldr r1, [r4, #4]
	ldr r2, [r4, #8]
	movs r3, #0xa4
	lsls r3, r3, #3
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	ldr r3, .L080DAFB8 @ =0x000004D4
	add r3, sp
	cmp r0, #0
	beq .L080DAF98
	lsls r0, r0, #3
	adds r0, #4
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xc
	cmp r1, r0
	beq .L080DAF92
	adds r5, r1, #0
	subs r0, r0, r5
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DAF92
.L080DAF88:
	ldm r5!, {r0, r1}
	stm r6!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DAF88
.L080DAF92:
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
.L080DAF98:
	ldr r0, .L080DAFB8 @ =0x000004D4
	add r0, sp
	movs r5, #0xa4
	lsls r5, r5, #3
	b .L080DB01A
	.align 2, 0
.L080DAFA4: .4byte 0x00001BD8
.L080DAFA8: .4byte 0x00000574
.L080DAFAC: .4byte 0x0000055C
.L080DAFB0: .4byte gUnk_0300040C
.L080DAFB4: .4byte 0x00000564
.L080DAFB8: .4byte 0x000004D4
.L080DAFBC:
	adds r7, r4, #0
	adds r7, #0x14
	movs r1, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne .L080DAFCA
	movs r1, #1
.L080DAFCA:
	cmp r1, #0
	bne .L080DB02C
	adds r6, r4, #0
	adds r6, #0x18
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x1c]
	movs r3, #0xa5
	lsls r3, r3, #3
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	adds r5, r7, #0
	ldr r3, .L080DB028 @ =0x000004D4
	add r3, sp
	cmp r0, #0
	beq .L080DB012
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r5, r0
	adds r0, r4, #0
	adds r0, #0x20
	cmp r0, r1
	beq .L080DB00C
	adds r4, r0, #0
	subs r0, r1, r4
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DB00C
.L080DB002:
	ldm r4!, {r0, r1}
	stm r6!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DB002
.L080DB00C:
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
.L080DB012:
	ldr r0, .L080DB028 @ =0x000004D4
	add r0, sp
	movs r5, #0xa5
	lsls r5, r5, #3
.L080DB01A:
	add r5, sp
	ldr r4, [r5]
	ldr r5, [r5, #4]
	str r4, [r0]
	str r5, [r0, #4]
	b .L080DB0AE
	.align 2, 0
.L080DB028: .4byte 0x000004D4
.L080DB02C:
	movs r6, #0xac
	lsls r6, r6, #1
	adds r7, r4, r6
	movs r1, #0
	ldr r0, [r7]
	cmp r0, #0
	bne .L080DB03C
	movs r1, #1
.L080DB03C:
	cmp r1, #0
	bne .L080DB0A0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r6, r4, r1
	ldr r1, [r6]
	ldr r2, [r6, #4]
	movs r3, #0xa6
	lsls r3, r3, #3
	add r3, sp
	str r1, [r3]
	str r2, [r3, #4]
	adds r5, r7, #0
	ldr r3, .L080DB09C @ =0x000004D4
	add r3, sp
	cmp r0, #0
	beq .L080DB088
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r5, r0
	movs r7, #0xb2
	lsls r7, r7, #1
	adds r0, r4, r7
	cmp r0, r1
	beq .L080DB082
	adds r4, r0, #0
	subs r0, r1, r4
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080DB082
.L080DB078:
	ldm r4!, {r0, r1}
	stm r6!, {r0, r1}
	subs r2, #1
	cmp r2, #0
	bgt .L080DB078
.L080DB082:
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
.L080DB088:
	ldr r0, .L080DB09C @ =0x000004D4
	add r0, sp
	movs r2, #0xa6
	lsls r2, r2, #3
	add r2, sp
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	b .L080DB0AE
	.align 2, 0
.L080DB09C: .4byte 0x000004D4
.L080DB0A0:
	ldr r1, .L080DB0C8 @ =0x000004D4
	add r1, sp
	ldr r0, .L080DB0C8 @ =0x000004D4
	add r0, sp
	str r5, [r0]
	str r5, [r1, #4]
	adds r3, r1, #0
.L080DB0AE:
	ldr r0, .L080DB0C8 @ =0x000004D4
	add r0, sp
	ldr r1, [r0]
	ldr r2, [r3, #4]
	mov r0, sl
	bl func_080DC294
.L080DB0BC:
	mov r0, sl
	add r1, sp, #0x34
	bl UpdateGameSceneHardwareFrame
	bl .L080D8FE8
	.align 2, 0
.L080DB0C8: .4byte 0x000004D4
func_080DB0CC:
	ldr r3, .L080DB0E8 @ =0x000004DC
	add r3, sp
	ldr r0, [r3]
	movs r3, #0xb2
	lsls r3, r3, #3
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080DB0E8: .4byte 0x000004DC

    .section .text.scene_calendar_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_tool_chest_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_refrigerator_after, "ax", %progbits

	.align 2, 0

    .section .text.rucksack_menu_transition_factory, "ax", %progbits

	.align 2, 0

	thumb_func_start CreateScene__22RucksackMenuTransition
CreateScene__22RucksackMenuTransition: @ 0x080DB88C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #4]
	movs r5, #0
	str r5, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0xc
	bl __builtin_new
	add r1, sp, #4
	ldr r2, [r4, #8]
	bl __17RucksackMenuSceneG20SceneTransitionOwnerP18GameStateSaveImage
	str r0, [sp]
	mov r1, sp
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r5, [r1]
	str r0, [r6]
	ldr r1, [sp]
	cmp r1, #0
	beq .L080DB8C8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DB8C8:
	adds r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.scene_cooking_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_reference_page_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_gift_wrapping_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_poultry_farm_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_winery_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_inn_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_beach_cafe_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_won_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_carpenter_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_clinic_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_blacksmith_shop_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_supermarket_purchase_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_clock_after, "ax", %progbits

	.align 2, 0

    .section .text.scene_return_after, "ax", %progbits

	.align 2, 0

	thumb_func_start func_080DC294
func_080DC294: @ 0x080DC294
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080DC2B0 @ =gUnk_0300040C
	ldr r0, [r0]
	adds r0, #8
	bl LoadById__12ScriptEngineii
	adds r0, r4, #0
	bl func_080D7F3C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080DC2B0: .4byte gUnk_0300040C

	thumb_func_start func_080DC2B4
func_080DC2B4: @ 0x080DC2B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r0, #0xa8
	ldr r0, [r0]
	ldr r4, [r0]
	mov ip, r4
	movs r5, #0xb4
	add ip, r5
	mov r8, sp
	ldr r7, .L080DC358 @ =0x000003FF
	mov sl, r7
	mov r4, sl
	ands r1, r4
	mov r7, r8
	ldrh r5, [r7]
	ldr r6, .L080DC35C @ =0xFFFFFC00
	adds r4, r6, #0
	ands r4, r5
	orrs r4, r1
	strh r4, [r7]
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	movs r1, #0x3f
	ands r4, r1
	lsls r4, r4, #2
	ldrb r5, [r7, #1]
	mov sb, r5
	movs r5, #3
	adds r1, r5, #0
	mov r7, sb
	ands r1, r7
	orrs r1, r4
	mov r4, r8
	strb r1, [r4, #1]
	lsrs r2, r2, #0x16
	mov r7, sl
	ands r2, r7
	ldrh r4, [r4, #2]
	adds r1, r6, #0
	ands r1, r4
	orrs r1, r2
	mov r2, r8
	strh r1, [r2, #2]
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	movs r4, #0x3f
	ands r1, r4
	lsls r1, r1, #2
	ldrb r2, [r2, #3]
	ands r5, r2
	orrs r5, r1
	mov r7, r8
	strb r5, [r7, #3]
	lsrs r3, r3, #0x16
	mov r1, sl
	ands r3, r1
	ldrh r1, [r7, #4]
	ands r6, r1
	orrs r6, r3
	strh r6, [r7, #4]
	mov r2, ip
	ldr r3, [r2]
	mov r1, sp
	movs r2, #1
	bl _call_via_r3
	ldr r0, [sp, #8]
	bl func_080D7F08
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080DC358: .4byte 0x000003FF
.L080DC35C: .4byte 0xFFFFFC00

	thumb_func_start func_080DC360
func_080DC360: @ 0x080DC360
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	adds r4, r3, #0
	ldr r5, [sp, #0x20]
	adds r0, #0xa8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	adds r2, r0, #0
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	mov r3, sb
	bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

    .section .text.after_gamecube_link_scene, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080DC42C
func_080DC42C: @ 0x080DC42C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #8]
	movs r5, #0
	str r5, [r4, #8]
	str r0, [sp, #4]
	movs r0, #8
	bl __builtin_new
	ldr r1, [r4, #4]
	add r2, sp, #4
	bl func_080701BC
	str r0, [sp]
	mov r1, sp
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r5, [r1]
	str r0, [r6]
	ldr r1, [sp]
	cmp r1, #0
	beq .L080DC468
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC468:
	adds r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080DC474
func_080DC474: @ 0x080DC474
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq .L080DC48C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC48C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15SceneTransition
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC49C
func_080DC49C: @ 0x080DC49C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #4]
	movs r5, #0
	str r5, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0xc
	bl __builtin_new
	add r1, sp, #4
	ldr r2, [r4, #8]
	bl func_080755EC
	str r0, [sp]
	mov r1, sp
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r5, [r1]
	str r0, [r6]
	ldr r1, [sp]
	cmp r1, #0
	beq .L080DC4D8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC4D8:
	adds r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080DC4E4
func_080DC4E4: @ 0x080DC4E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [r4, #4]
	cmp r1, #0
	beq .L080DC4FC
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC4FC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15SceneTransition
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC50C
func_080DC50C: @ 0x080DC50C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #4]
	movs r5, #0
	str r5, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0xc
	bl __builtin_new
	add r1, sp, #4
	ldr r2, [r4, #8]
	ldrb r3, [r4, #0xc]
	bl func_08069E14
	str r0, [sp]
	mov r1, sp
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r5, [r1]
	str r0, [r6]
	ldr r1, [sp]
	cmp r1, #0
	beq .L080DC54A
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC54A:
	adds r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_080DC554
func_080DC554: @ 0x080DC554
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [r4, #4]
	cmp r1, #0
	beq .L080DC56C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DC56C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15SceneTransition
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

    .section .text.scene_group_sprite_cleanup_after, "ax", %progbits
    .align 2, 0

    .global _._10GameObject
    .thumb_func
_._10GameObject:
    push {lr}
    adds r2, r0, #0
    ldr r0, .Ldestroy_world_interface_us_table
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Ldestroy_world_interface_us_done
    adds r0, r2, #0
    bl __builtin_delete
.Ldestroy_world_interface_us_done:
    pop {r0}
    bx r0
    .align 2, 0
.Ldestroy_world_interface_us_table: .4byte __vt_14GameObjectBase

    .global _._14GameObjectBase
    .thumb_func
_._14GameObjectBase:
    push {lr}
    adds r2, r0, #0
    ldr r0, .Ldestroy_common_interface_us_table
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Ldestroy_common_interface_us_done
    adds r0, r2, #0
    bl __builtin_delete
.Ldestroy_common_interface_us_done:
    pop {r0}
    bx r0
    .align 2, 0
.Ldestroy_common_interface_us_table: .4byte __vt_14GameObjectBase

	.global func_080DC5F4
	.thumb_func
func_080DC5F4:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x0C, 0x1C
	.byte 0x48, 0x30, 0x02, 0x21
	bl _._19GameSceneSpriteBase
	.byte 0x28, 0x1C, 0x08, 0x30, 0x02, 0x21
	bl _._19GameSceneSpriteBase
	.byte 0x05, 0x48, 0x68, 0x60
	.byte 0x01, 0x20, 0x20, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x28, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_22EntityVisualController
	.global DestroyAudioActorEntity
	.thumb_func
DestroyAudioActorEntity:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C
	.byte 0x0A, 0x48, 0x60, 0x61, 0x21, 0x69, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C
	.byte 0x03, 0x21, 0xF7, 0xF7, 0x68, 0xF9, 0x01, 0x20, 0x28, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x20, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_7AEntity
    .section .text.entity_visual_controller_cleanup_after, "ax", %progbits
    .align 2, 0
	thumb_func_start func_080DC67C
func_080DC67C: @ 0x080DC67C
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r0, #0
	subs r0, r5, r3
	asrs r2, r0, #2
	cmp r2, #0
	ble .L080DC6B4
	ldrb r1, [r4]
.L080DC68E:
	ldrb r0, [r3]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
	subs r2, #1
	cmp r2, #0
	bgt .L080DC68E
.L080DC6B4:
	subs r0, r5, r3
	cmp r0, #1
	beq .L080DC6DA
	cmp r0, #1
	ble .L080DC6E6
	cmp r0, #2
	beq .L080DC6D0
	cmp r0, #3
	bne .L080DC6E6
	ldrb r0, [r3]
	ldrb r1, [r4]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
.L080DC6D0:
	ldrb r0, [r3]
	ldrb r1, [r4]
	cmp r0, r1
	beq .L080DC6E2
	adds r3, #1
.L080DC6DA:
	ldrb r0, [r3]
	ldrb r4, [r4]
	cmp r0, r4
	bne .L080DC6E6
.L080DC6E2:
	adds r0, r3, #0
	b .L080DC6E8
.L080DC6E6:
	adds r0, r5, #0
.L080DC6E8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L080DC6F0:
	.global func_080DC6F0
	.thumb_func
func_080DC6F0:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x0A, 0x48, 0x60, 0x61, 0x21, 0x69, 0x00, 0x29, 0x05, 0xD0
	.byte 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF7, 0xF7, 0x04, 0xF9, 0x01, 0x20, 0x28, 0x40
	.byte 0x00, 0x28, 0x02, 0xD0, 0x20, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_7AEntity

	thumb_func_start func_080DC724
func_080DC724: @ 0x080DC724
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, #0x8c
	movs r1, #2
	bl _._19GameSceneSpriteBase
	adds r0, r5, #0
	adds r0, #0x48
	movs r1, #2
	bl _._19GameSceneSpriteBase
	adds r0, r5, #0
	adds r0, #8
	movs r1, #2
	bl _._19GameSceneSpriteBase
	ldr r0, .L080DC760 @ =__vt_22EntityVisualController
	str r0, [r5, #4]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080DC758
	adds r0, r5, #0
	bl __builtin_delete
.L080DC758:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DC760: .4byte __vt_22EntityVisualController

    .section .text.player_sprite_cleanup_after, "ax", %progbits
    .align 2, 0
	.global func_080DC7CC
	.thumb_func
func_080DC7CC:
	.byte 0x30, 0xB5, 0x04, 0x1C
	.byte 0x0D, 0x1C, 0x0A, 0x48, 0x60, 0x61, 0x21, 0x69, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x68, 0x82, 0x68
	.byte 0x08, 0x1C, 0x03, 0x21, 0xF7, 0xF7, 0x96, 0xF8, 0x01, 0x20, 0x28, 0x40, 0x00, 0x28, 0x02, 0xD0
	.byte 0x20, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_7AEntity
	.global func_080DC800
	.thumb_func
func_080DC800:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x0A, 0x48, 0x60, 0x61, 0x21, 0x69, 0x00, 0x29, 0x05, 0xD0
	.byte 0x48, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF7, 0xF7, 0x7C, 0xF8, 0x01, 0x20, 0x28, 0x40
	.byte 0x00, 0x28, 0x02, 0xD0, 0x20, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_7AEntity
    .section .text.entity_sprite_cleanup_after, "ax", %progbits
    .align 2, 0
	.global func_080DC92C
	.thumb_func
func_080DC92C:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x0C, 0x1C
	.byte 0x8C, 0x30, 0x02, 0x21
	bl _._19GameSceneSpriteBase
	.byte 0x28, 0x1C, 0x48, 0x30, 0x02, 0x21
	bl _._19GameSceneSpriteBase
	.byte 0x28, 0x1C, 0x08, 0x30, 0x02, 0x21
	bl _._19GameSceneSpriteBase
	.byte 0x06, 0x48
	.byte 0x68, 0x60, 0x01, 0x20, 0x20, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x28, 0x1C
	bl __builtin_delete
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.4byte __vt_22EntityVisualController

    .section .text.npc_timed_path_search_after, "ax", %progbits

.L080DC9A8:
	.global func_080DC9A8
	.thumb_func
func_080DC9A8:
	.byte 0x00, 0xB5
	bl _._10ANpcEntity
	.byte 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
	.global func_080DC9B4
	.thumb_func
func_080DC9B4:
	.byte 0x00, 0xB5
	bl _._10ANpcEntity
	.byte 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start func_080DC9C0
func_080DC9C0: @ 0x080DC9C0
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC9CC
func_080DC9CC: @ 0x080DC9CC
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC9D8
func_080DC9D8: @ 0x080DC9D8
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC9E4
func_080DC9E4: @ 0x080DC9E4
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC9F0
func_080DC9F0: @ 0x080DC9F0
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DC9FC
func_080DC9FC: @ 0x080DC9FC
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA08
func_080DCA08: @ 0x080DCA08
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA14
func_080DCA14: @ 0x080DCA14
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA20
func_080DCA20: @ 0x080DCA20
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA2C
func_080DCA2C: @ 0x080DCA2C
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA38
func_080DCA38: @ 0x080DCA38
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA44
func_080DCA44: @ 0x080DCA44
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA50
func_080DCA50: @ 0x080DCA50
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA5C
func_080DCA5C: @ 0x080DCA5C
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA68
func_080DCA68: @ 0x080DCA68
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA74
func_080DCA74: @ 0x080DCA74
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA80
func_080DCA80: @ 0x080DCA80
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA8C
func_080DCA8C: @ 0x080DCA8C
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCA98
func_080DCA98: @ 0x080DCA98
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAA4
func_080DCAA4: @ 0x080DCAA4
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAB0
func_080DCAB0: @ 0x080DCAB0
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCABC
func_080DCABC: @ 0x080DCABC
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAC8
func_080DCAC8: @ 0x080DCAC8
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAD4
func_080DCAD4: @ 0x080DCAD4
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAE0
func_080DCAE0: @ 0x080DCAE0
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAEC
func_080DCAEC: @ 0x080DCAEC
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCAF8
func_080DCAF8: @ 0x080DCAF8
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB04
func_080DCB04: @ 0x080DCB04
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB10
func_080DCB10: @ 0x080DCB10
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB1C
func_080DCB1C: @ 0x080DCB1C
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB28
func_080DCB28: @ 0x080DCB28
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB34
func_080DCB34: @ 0x080DCB34
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB40
func_080DCB40: @ 0x080DCB40
	push {lr}
	bl _._10ANpcEntity
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB4C
func_080DCB4C: @ 0x080DCB4C
	push {lr}
	bl func_08037048
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB58
func_080DCB58: @ 0x080DCB58
	push {lr}
	bl func_08037048
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB64
func_080DCB64: @ 0x080DCB64
	push {lr}
	bl func_08037048
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB70
func_080DCB70: @ 0x080DCB70
	push {lr}
	bl func_08037048
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCB7C
func_080DCB7C: @ 0x080DCB7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	mov r8, r0
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x5c]
	movs r0, #0
	mov r1, r8
	str r0, [r1]
	add r5, sp, #0xc
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r0, #0x7c]
	mov r0, sl
	bl _call_via_r1
	adds r1, r0, #0
	ldr r3, [sp, #0x5c]
	cmp r3, #0
	beq .L080DCBB8
	ldr r0, .L080DCBB4 @ =gUnk_080F1684
	ldrh r2, [r0, #2]
	b .L080DCBBC
	.align 2, 0
.L080DCBB4: .4byte gUnk_080F1684
.L080DCBB8:
	ldr r0, .L080DCC90 @ =gUnk_080F1684
	ldrh r2, [r0]
.L080DCBBC:
	movs r0, #6
	str r0, [sp]
	movs r0, #0x1d
	str r0, [sp, #4]
	add r4, sp, #8
	movs r0, #0
	strb r0, [r4]
	adds r0, r5, #0
	mov r3, sl
	bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
	movs r0, #0xc8
	lsls r0, r0, #0xf
	str r0, [r5, #0x40]
	adds r1, r5, #0
	adds r1, #0x44
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, .L080DCC94 @ =0x00002666
	str r0, [r5, #0x48]
	ldr r0, .L080DCC90 @ =gUnk_080F1684
	ldrb r1, [r0, #4]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x4d
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	ldr r1, [r0]
	str r4, [sp, #0x68]
	cmp r1, #4
	bhi .L080DCC1E
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #4
	add r0, r8
	cmp r0, #0
	beq .L080DCC16
	add r1, sp, #0xc
	bl func_080DCD2C
.L080DCC16:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
.L080DCC1E:
	add r0, sp, #0xc
	movs r1, #2
	bl _._19GameSceneSpriteBase
	movs r2, #0
	str r2, [sp, #0x60]
	add r7, sp, #0xc
	mov r3, sp
	adds r3, #0x59
	str r3, [sp, #0x64]
.L080DCC32:
	bl rand
	movs r1, #3
	bl __modsi3
	adds r6, r0, #0
	bl rand
	movs r1, #0xf0
	lsls r1, r1, #1
	bl __umodsi3
	adds r5, r0, #0
	ldr r4, .L080DCC98 @ =gUnk_080F1672
	bl rand
	movs r1, #3
	bl __modsi3
	adds r0, r0, r4
	ldrb r4, [r0]
	bl rand
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #2
	ldr r1, .L080DCC9C @ =gUnk_080F1678
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r0, #0x7c]
	mov r0, sl
	bl _call_via_r1
	adds r1, r0, #0
	ldr r3, [sp, #0x5c]
	cmp r3, #0
	beq .L080DCCA0
	lsls r0, r6, #3
	ldr r2, .L080DCC90 @ =gUnk_080F1684
	adds r0, r0, r2
	ldrh r2, [r0, #2]
	b .L080DCCA8
	.align 2, 0
.L080DCC90: .4byte gUnk_080F1684
.L080DCC94: .4byte 0x00002666
.L080DCC98: .4byte gUnk_080F1672
.L080DCC9C: .4byte gUnk_080F1678
.L080DCCA0:
	lsls r0, r6, #3
	ldr r3, .L080DCD28 @ =gUnk_080F1684
	adds r0, r0, r3
	ldrh r2, [r0]
.L080DCCA8:
	movs r0, #6
	str r0, [sp]
	movs r0, #0x1d
	str r0, [sp, #4]
	movs r0, #0
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	adds r0, r7, #0
	mov r3, sl
	bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
	lsls r0, r5, #0x10
	str r0, [r7, #0x40]
	adds r0, r7, #0
	adds r0, #0x44
	strh r4, [r0]
	mov r0, sb
	str r0, [r7, #0x48]
	lsls r0, r6, #3
	ldr r1, .L080DCD28 @ =gUnk_080F1684
	adds r0, r0, r1
	ldrb r1, [r0, #4]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x64]
	strb r0, [r2]
	mov r3, r8
	ldr r1, [r3]
	cmp r1, #4
	bhi .L080DCD04
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #4
	add r0, r8
	cmp r0, #0
	beq .L080DCCFC
	add r1, sp, #0xc
	bl func_080DCD2C
.L080DCCFC:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
.L080DCD04:
	add r0, sp, #0xc
	movs r1, #2
	bl _._19GameSceneSpriteBase
	ldr r2, [sp, #0x60]
	adds r2, #1
	str r2, [sp, #0x60]
	cmp r2, #3
	bls .L080DCC32
	mov r0, r8
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080DCD28: .4byte gUnk_080F1684

	thumb_func_start func_080DCD2C
func_080DCD2C: @ 0x080DCD2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl __19GameSceneSpriteBaseRC19GameSceneSpriteBase
	ldr r0, .L080DCDAC @ =__vt_22GameSceneIndexedSprite
	str r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x28
	adds r0, r5, #0
	adds r0, #0x28
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x3c
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x3d
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	ldr r0, [r5, #0x40]
	str r0, [r4, #0x40]
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0]
	ldr r0, [r5, #0x48]
	str r0, [r4, #0x48]
	adds r0, r5, #0
	adds r0, #0x4c
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r2, r4, #0
	adds r2, #0x4d
	strb r0, [r2]
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L080DCDAC: .4byte __vt_22GameSceneIndexedSprite

	thumb_func_start func_080DCDB0
func_080DCDB0: @ 0x080DCDB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, [r7, #0x14]
	cmp r0, #0
	beq .L080DCDE8
	adds r6, r0, #0
	ldr r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #4
	adds r5, r6, r0
	adds r4, r6, #4
	cmp r4, r5
	beq .L080DCDE2
.L080DCDD4:
	adds r0, r4, #0
	movs r1, #2
	bl _._19GameSceneSpriteBase
	adds r4, #0x50
	cmp r4, r5
	bne .L080DCDD4
.L080DCDE2:
	adds r0, r6, #0
	bl __builtin_delete
.L080DCDE8:
	ldr r0, [r7, #0x10]
	cmp r0, #0
	beq .L080DCE16
	adds r6, r0, #0
	ldr r0, [r6]
	lsls r0, r0, #6
	adds r0, #4
	adds r5, r6, r0
	adds r4, r6, #4
	cmp r4, r5
	beq .L080DCE10
.L080DCDFE:
	ldr r0, [r4, #0x24]
	ldr r2, [r0, #8]
	adds r0, r4, #0
	movs r1, #2
	bl _call_via_r2
	adds r4, #0x40
	cmp r4, r5
	bne .L080DCDFE
.L080DCE10:
	adds r0, r6, #0
	bl __builtin_delete
.L080DCE16:
	ldr r4, [r7, #0xc]
	cmp r4, #0
	beq .L080DCE2A
	adds r0, r4, #0
	movs r1, #2
	bl _._19GameSceneSpriteBase
	adds r0, r4, #0
	bl __builtin_delete
.L080DCE2A:
	ldr r4, [r7, #8]
	cmp r4, #0
	beq .L080DCE3E
	adds r0, r4, #0
	movs r1, #2
	bl _._19GameSceneSpriteBase
	adds r0, r4, #0
	bl __builtin_delete
.L080DCE3E:
	ldr r0, .L080DCE5C @ =__vt_22EntityVisualController
	str r0, [r7, #4]
	movs r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq .L080DCE52
	adds r0, r7, #0
	bl __builtin_delete
.L080DCE52:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCE5C: .4byte __vt_22EntityVisualController

	thumb_func_start func_080DCE60
func_080DCE60: @ 0x080DCE60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080DCE90 @ =__vt_7AEntity
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq .L080DCE7C
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DCE7C:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080DCE8A
	adds r0, r4, #0
	bl __builtin_delete
.L080DCE8A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCE90: .4byte __vt_7AEntity

	thumb_func_start func_080DCE94
func_080DCE94: @ 0x080DCE94
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, #8
	movs r1, #2
	bl _._19GameSceneSpriteBase
	ldr r0, .L080DCEBC @ =__vt_22EntityVisualController
	str r0, [r5, #4]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080DCEB4
	adds r0, r5, #0
	bl __builtin_delete
.L080DCEB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCEBC: .4byte __vt_22EntityVisualController

	thumb_func_start func_080DCEC0
func_080DCEC0: @ 0x080DCEC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, #8
	movs r1, #2
	bl _._19GameSceneSpriteBase
	ldr r0, .L080DCEE8 @ =__vt_22EntityVisualController
	str r0, [r5, #4]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080DCEE0
	adds r0, r5, #0
	bl __builtin_delete
.L080DCEE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCEE8: .4byte __vt_22EntityVisualController

	thumb_func_start func_080DCEEC
func_080DCEEC: @ 0x080DCEEC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080DCF1C @ =__vt_7AEntity
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq .L080DCF08
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DCF08:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080DCF16
	adds r0, r4, #0
	bl __builtin_delete
.L080DCF16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCF1C: .4byte __vt_7AEntity

	thumb_func_start func_080DCF20
func_080DCF20: @ 0x080DCF20
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, #8
	movs r1, #2
	bl _._19GameSceneSpriteBase
	ldr r0, .L080DCF48 @ =__vt_22EntityVisualController
	str r0, [r5, #4]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080DCF40
	adds r0, r5, #0
	bl __builtin_delete
.L080DCF40:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCF48: .4byte __vt_22EntityVisualController

	thumb_func_start func_080DCF4C
func_080DCF4C: @ 0x080DCF4C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r0, .L080DCFC4 @ =vtable_unk_080E7568
	mov r1, r8
	str r0, [r1, #0x14]
	ldr r0, [r1, #0x10]
	cmp r0, #0
	beq .L080DCF90
	ldr r1, [r1, #0x18]
	movs r6, #0
	ldr r7, [r0, #8]
	cmp r6, r7
	bhs .L080DCF90
	adds r5, r1, #0
	adds r4, r0, #0
	adds r4, #0xc
.L080DCF74:
	ldr r1, [r4]
	cmp r1, #0
	beq .L080DCF86
	ldr r0, [r1, #0x4c]
	ldr r2, [r0, #0x14]
	adds r0, r1, #0
	adds r1, r5, #0
	bl _call_via_r2
.L080DCF86:
	adds r5, #0x10
	adds r4, #4
	adds r6, #1
	cmp r6, r7
	blo .L080DCF74
.L080DCF90:
	ldr r0, .L080DCFC8 @ =__vt_7AEntity
	mov r2, r8
	str r0, [r2, #0x14]
	ldr r1, [r2, #0x10]
	cmp r1, #0
	beq .L080DCFA8
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DCFA8:
	movs r0, #1
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L080DCFB8
	mov r0, r8
	bl __builtin_delete
.L080DCFB8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080DCFC4: .4byte vtable_unk_080E7568
.L080DCFC8: .4byte __vt_7AEntity

	thumb_func_start func_080DCFCC
func_080DCFCC: @ 0x080DCFCC
	push {r4, lr}
	adds r4, r0, #0
	bl vfunc_14__7AEntity
	movs r0, #0
	strb r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DCFE0
func_080DCFE0: @ 0x080DCFE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r7, #0
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne .L080DCFF6
	b .L080DD318
.L080DCFF6:
	movs r0, #0x18
	bl __builtin_new
	adds r6, r0, #0
	ldr r0, [r4, #0x18]
	mov sl, r0
	str r4, [r6]
	ldr r0, .L080DD034 @ =vtable_unk_080E76D4
	str r0, [r6, #4]
	str r7, [r6, #8]
	ldr r4, [r4]
	mov r8, r4
	movs r1, #0
	mov sb, r1
.L080DD012:
	mov r2, sb
	lsls r0, r2, #4
	mov r1, sl
	adds r7, r1, r0
	ldrb r0, [r7]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	subs r0, #1
	cmp r0, #0xb
	bls .L080DD028
	b .L080DD2FA
.L080DD028:
	lsls r0, r0, #2
	ldr r1, .L080DD038 @ =.L080DD03C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080DD034: .4byte vtable_unk_080E76D4
.L080DD038: .4byte .L080DD03C
.L080DD03C: @ jump table
	.4byte .L080DD06C @ case 0
	.4byte .L080DD094 @ case 1
	.4byte .L080DD0B4 @ case 2
	.4byte .L080DD0DC @ case 3
	.4byte .L080DD104 @ case 4
	.4byte .L080DD160 @ case 5
	.4byte .L080DD1D4 @ case 6
	.4byte .L080DD1FC @ case 7
	.4byte .L080DD224 @ case 8
	.4byte .L080DD24C @ case 9
	.4byte .L080DD274 @ case 10
	.4byte .L080DD294 @ case 11
.L080DD06C:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD08C @ =0x000009B6
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD090 @ =vtable_unk_080E76A4
	b .L080DD2AA
	.align 2, 0
.L080DD08C: .4byte 0x000009B6
.L080DD090: .4byte vtable_unk_080E76A4
.L080DD094:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	adds r2, #0x10
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD0B0 @ =vtable_unk_080E768C
	b .L080DD2AA
	.align 2, 0
.L080DD0B0: .4byte vtable_unk_080E768C
.L080DD0B4:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD0D4 @ =0x000003DB
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD0D8 @ =vtable_unk_080E7674
	b .L080DD2AA
	.align 2, 0
.L080DD0D4: .4byte 0x000003DB
.L080DD0D8: .4byte vtable_unk_080E7674
.L080DD0DC:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD0FC @ =0x00000806
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD100 @ =vtable_unk_080E765C
	b .L080DD2AA
	.align 2, 0
.L080DD0FC: .4byte 0x00000806
.L080DD100: .4byte vtable_unk_080E765C
.L080DD104:
	movs r0, #0x6c
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD158 @ =0x00000202
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD15C @ =vtable_unk_080E7644
	str r0, [r5, #0x4c]
	ldr r0, [r7, #4]
	str r0, [r5, #0x50]
	ldrh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0x54
	movs r2, #0
	movs r3, #0
	strh r0, [r1]
	ldrh r0, [r4, #6]
	adds r4, r5, #0
	adds r4, #0x56
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x60
	strh r3, [r0]
	adds r0, #2
	strb r2, [r0]
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #0x10
	str r0, [r5, #0x58]
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #0x10
	str r0, [r5, #0x5c]
	str r3, [r5, #0x68]
	b .L080DD2DE
	.align 2, 0
.L080DD158: .4byte 0x00000202
.L080DD15C: .4byte vtable_unk_080E7644
.L080DD160:
	movs r0, #0x88
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD1CC @ =0x000002A3
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD1D0 @ =vtable_unk_080E762C
	str r0, [r5, #0x4c]
	ldr r0, [r7, #4]
	str r0, [r5, #0x50]
	adds r1, r5, #0
	adds r1, #0x79
	movs r0, #0xff
	strb r0, [r1]
	subs r1, #0x29
	ldrb r2, [r4, #8]
	lsls r2, r2, #0x1c
	asrs r2, r2, #0x1c
	adds r0, r5, #0
	bl func_0803A144
	adds r1, r5, #0
	adds r1, #0x78
	movs r2, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strb r1, [r0]
	subs r0, #0xe
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #0x10
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x56
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #0x10
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #0xf8
	strb r0, [r1]
	b .L080DD2DE
	.align 2, 0
.L080DD1CC: .4byte 0x000002A3
.L080DD1D0: .4byte vtable_unk_080E762C
.L080DD1D4:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD1F4 @ =0x0000087B
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD1F8 @ =vtable_unk_080E7614
	b .L080DD2AA
	.align 2, 0
.L080DD1F4: .4byte 0x0000087B
.L080DD1F8: .4byte vtable_unk_080E7614
.L080DD1FC:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD21C @ =0x0000065C
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD220 @ =vtable_unk_080E75FC
	b .L080DD2AA
	.align 2, 0
.L080DD21C: .4byte 0x0000065C
.L080DD220: .4byte vtable_unk_080E75FC
.L080DD224:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD244 @ =0x000008F9
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD248 @ =vtable_unk_080E75E4
	b .L080DD2AA
	.align 2, 0
.L080DD244: .4byte 0x000008F9
.L080DD248: .4byte vtable_unk_080E75E4
.L080DD24C:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	ldr r2, [r7, #4]
	ldr r0, .L080DD26C @ =0x000009A9
	adds r2, r2, r0
	adds r0, r5, #0
	mov r1, r8
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD270 @ =vtable_unk_080E75CC
	b .L080DD2AA
	.align 2, 0
.L080DD26C: .4byte 0x000009A9
.L080DD270: .4byte vtable_unk_080E75CC
.L080DD274:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	mov r1, r8
	ldr r2, .L080DD28C @ =0x000008FD
	movs r3, #1
	bl func_08039E98
	ldr r0, .L080DD290 @ =vtable_unk_080E75B4
	b .L080DD2AA
	.align 2, 0
.L080DD28C: .4byte 0x000008FD
.L080DD290: .4byte vtable_unk_080E75B4
.L080DD294:
	movs r0, #0x64
	bl __builtin_new
	adds r5, r0, #0
	adds r4, r7, #4
	mov r1, r8
	movs r2, #0x15
	movs r3, #0
	bl func_08039E98
	ldr r0, .L080DD314 @ =vtable_unk_080E759C
.L080DD2AA:
	str r0, [r5, #0x4c]
	ldr r0, [r7, #4]
	str r0, [r5, #0x50]
	ldrh r0, [r4, #4]
	adds r2, r5, #0
	adds r2, #0x54
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldrh r0, [r4, #6]
	adds r4, r5, #0
	adds r4, #0x56
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, #2
	strb r3, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #0x10
	str r0, [r5, #0x58]
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #0x10
	str r0, [r5, #0x5c]
.L080DD2DE:
	adds r1, r6, #0
	adds r1, #8
	ldr r0, [r6, #8]
	cmp r0, #2
	bhi .L080DD2FA
	lsls r0, r0, #2
	adds r0, #4
	adds r0, r1, r0
	cmp r0, #0
	beq .L080DD2F4
	str r5, [r0]
.L080DD2F4:
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
.L080DD2FA:
	ldrb r1, [r7]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r7]
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	bhi .L080DD310
	b .L080DD012
.L080DD310:
	adds r7, r6, #0
	b .L080DD36E
	.align 2, 0
.L080DD314: .4byte vtable_unk_080E759C
.L080DD318:
	movs r0, #0x18
	bl __builtin_new
	adds r5, r0, #0
	str r4, [r5]
	ldr r0, .L080DD380 @ =vtable_unk_080E76D4
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r4, [r4]
	ldr r0, [r4]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	movs r6, #0
	subs r0, #6
	cmp r0, #0xb
	bls .L080DD34A
	movs r6, #1
.L080DD34A:
	ldr r0, [r4]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, #8
	bl GetCalendarEffectiveSeason
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r3, r6, #0
	bl func_0803A394
	adds r7, r5, #0
.L080DD36E:
	adds r0, r7, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080DD380: .4byte vtable_unk_080E76D4
.L080DD384:
	.global func_080DD384
	.thumb_func
func_080DD384:
	.byte 0x0B, 0x78, 0x10, 0x22, 0x52, 0x42, 0x1A, 0x40, 0x0C, 0x23, 0x1A, 0x43
	.byte 0x0A, 0x70, 0x02, 0x6D, 0x4A, 0x60, 0x02, 0x1C, 0x54, 0x32, 0x12, 0x88, 0x0A, 0x81, 0x56, 0x30
	.byte 0x00, 0x88, 0x48, 0x81, 0x70, 0x47, 0x00, 0x00

	thumb_func_start func_080DD3A8
func_080DD3A8: @ 0x080DD3A8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD3D4
func_080DD3D4: @ 0x080DD3D4
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x47
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080DD3F8
	adds r0, r4, #0
	adds r0, #0x30
	bl UpdateIndexedResourceHandle
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DD3FC
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	b .L080DD3FA
.L080DD3F8:
	movs r0, #0
.L080DD3FA:
	strb r0, [r1]
.L080DD3FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD404
func_080DD404: @ 0x080DD404
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD410
func_080DD410: @ 0x080DD410
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #0xb
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DD434
func_080DD434: @ 0x080DD434
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD460
func_080DD460: @ 0x080DD460
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x62
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq .L080DD476
	cmp r0, #1
	beq .L080DD4A4
	b .L080DD4B8
.L080DD476:
	bl rand
	asrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq .L080DD48C
	adds r0, r4, #0
	movs r1, #0xcf
	bl func_0803A350
.L080DD48C:
	movs r0, #2
	bl RandomBelow
	adds r0, #6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	movs r0, #1
	b .L080DD4B6
.L080DD4A4:
	adds r1, r4, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080DD4B8
	movs r0, #0
.L080DD4B6:
	strb r0, [r5]
.L080DD4B8:
	adds r1, r4, #0
	adds r1, #0x47
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080DD4D8
	adds r0, r4, #0
	adds r0, #0x30
	bl UpdateIndexedResourceHandle
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DD4DC
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	b .L080DD4DA
.L080DD4D8:
	movs r0, #0
.L080DD4DA:
	strb r0, [r1]
.L080DD4DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD4E4
func_080DD4E4: @ 0x080DD4E4
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD4F0
func_080DD4F0: @ 0x080DD4F0
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #0xa
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DD514
func_080DD514: @ 0x080DD514
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD540
func_080DD540: @ 0x080DD540
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #9
	bl func_0803A180
	cmp r0, #0
	beq .L080DD57E
	ldr r0, [r4, #0x50]
	ldr r1, .L080DD584 @ =0x000009A9
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DD57E
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DD57E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DD584: .4byte 0x000009A9

	thumb_func_start func_080DD588
func_080DD588: @ 0x080DD588
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD594
func_080DD594: @ 0x080DD594
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #9
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DD5B8
func_080DD5B8: @ 0x080DD5B8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD5E4
func_080DD5E4: @ 0x080DD5E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r5, r0, #0
	ldr r4, [r5]
	ldr r0, [r4]
	ldr r2, [r0, #0x40]
	adds r0, r4, #0
	movs r1, #0
	bl _call_via_r2
	cmp r0, #0
	beq .L080DD6FE
	movs r2, #0xa
	ldrsh r1, [r0, r2]
	mov sb, r1
	movs r7, #0xe
	ldrsh r3, [r0, r7]
	mov r8, r3
	movs r0, #0x54
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sb
	subs r0, r2, r0
	cmp r0, #0
	bge .L080DD624
	rsbs r0, r0, #0
.L080DD624:
	cmp r0, #0xf
	bgt .L080DD6FE
	adds r6, r5, #0
	adds r6, #0x56
	movs r3, #0
	ldrsh r0, [r6, r3]
	mov r7, r8
	subs r0, r7, r0
	cmp r0, #0
	bge .L080DD63A
	rsbs r0, r0, #0
.L080DD63A:
	cmp r0, #0xf
	bgt .L080DD6FE
	ldr r1, [r4]
	add r0, sp, #8
	ldr r3, [r1, #0x34]
	adds r1, r4, #0
	movs r2, #0
	bl _call_via_r3
	mov r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0
	ldrsh r3, [r6, r4]
	add r2, sp, #0x48
	adds r0, r1, #0
	subs r0, #8
	movs r7, #0
	mov ip, r7
	strh r0, [r2]
	adds r0, r3, #0
	subs r0, #8
	strh r0, [r2, #2]
	adds r1, #8
	strh r1, [r2, #4]
	adds r3, #8
	strh r3, [r2, #6]
	add r2, sp, #0x14
	movs r1, #0x21
	str r1, [sp, #0x14]
	movs r0, #0x21
	rsbs r0, r0, #0
	str r0, [r2, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	add r1, sp, #0x28
	add r0, sp, #8
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	movs r0, #0x20
	str r0, [r2, #0x28]
	mov r1, ip
	str r1, [r2, #0x2c]
	str r1, [r2, #0x30]
	ldr r4, [r5, #0x50]
	mov r3, sl
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r3, #0
	ldrsh r1, [r6, r3]
	str r2, [sp]
	str r4, [sp, #4]
	mov r2, sb
	mov r3, r8
	bl SelectRetreatFacing
	adds r1, r0, #0
	str r1, [r5, #0x50]
	adds r6, r5, #0
	adds r6, #0x62
	cmp r4, r1
	bne .L080DD6C6
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne .L080DD6F2
.L080DD6C6:
	ldr r7, .L080DD740 @ =0x000008F9
	adds r4, r1, r7
	ldrh r0, [r5, #4]
	cmp r0, r4
	beq .L080DD6F2
	adds r0, r5, #0
	adds r0, #0x30
	adds r1, r4, #0
	bl ResolveIndexedResourceHandle
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x46
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x47
	strb r1, [r0]
	strh r4, [r5, #4]
.L080DD6F2:
	movs r0, #1
	strb r0, [r6]
	adds r1, r5, #0
	adds r1, #0x60
	movs r0, #0x3c
	strh r0, [r1]
.L080DD6FE:
	adds r1, r5, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r5, #0
	bl func_0803A180
	cmp r0, #0
	beq .L080DD772
	adds r0, r5, #0
	adds r0, #0x62
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne .L080DD748
	ldr r0, [r5, #0x50]
	ldr r1, .L080DD744 @ =0x000008F5
	adds r4, r0, r1
	ldrh r0, [r5, #4]
	cmp r0, r4
	beq .L080DD772
	adds r0, r5, #0
	adds r0, #0x30
	adds r1, r4, #0
	bl ResolveIndexedResourceHandle
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r6, [r0]
	b .L080DD76C
	.align 2, 0
.L080DD740: .4byte 0x000008F9
.L080DD744: .4byte 0x000008F5
.L080DD748:
	ldr r0, [r5, #0x50]
	ldr r2, .L080DD784 @ =0x000008F9
	adds r4, r0, r2
	ldrh r0, [r5, #4]
	cmp r0, r4
	beq .L080DD772
	adds r0, r5, #0
	adds r0, #0x30
	adds r1, r4, #0
	bl ResolveIndexedResourceHandle
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
.L080DD76C:
	adds r0, #1
	strb r1, [r0]
	strh r4, [r5, #4]
.L080DD772:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080DD784: .4byte 0x000008F9

	thumb_func_start func_080DD788
func_080DD788: @ 0x080DD788
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD794
func_080DD794: @ 0x080DD794
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #8
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DD7B8
func_080DD7B8: @ 0x080DD7B8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD7E4
func_080DD7E4: @ 0x080DD7E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #8
	bl func_0803A180
	cmp r0, #0
	beq .L080DD854
	adds r0, r4, #0
	adds r0, #0x62
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne .L080DD82A
	ldr r0, [r4, #0x50]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DD854
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r6, [r0]
	b .L080DD84E
.L080DD82A:
	ldr r0, [r4, #0x50]
	ldr r1, .L080DD85C @ =0x0000065C
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DD854
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
.L080DD84E:
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DD854:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080DD85C: .4byte 0x0000065C

	thumb_func_start func_080DD860
func_080DD860: @ 0x080DD860
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD86C
func_080DD86C: @ 0x080DD86C
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #7
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DD890
func_080DD890: @ 0x080DD890
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DD8BC
func_080DD8BC: @ 0x080DD8BC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #8
	bl func_0803A180
	cmp r0, #0
	beq .L080DD92E
	adds r0, r4, #0
	adds r0, #0x62
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne .L080DD904
	ldr r0, [r4, #0x50]
	ldr r1, .L080DD900 @ =0x00000877
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DD92E
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r6, [r0]
	b .L080DD928
	.align 2, 0
.L080DD900: .4byte 0x00000877
.L080DD904:
	ldr r0, [r4, #0x50]
	ldr r1, .L080DD934 @ =0x0000087B
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DD92E
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
.L080DD928:
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DD92E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080DD934: .4byte 0x0000087B

	thumb_func_start func_080DD938
func_080DD938: @ 0x080DD938
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD944
func_080DD944: @ 0x080DD944
	push {r4, lr}
	mov ip, r0
	ldrb r2, [r1]
	movs r3, #0x10
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r0, r2
	movs r2, #6
	orrs r0, r2
	strb r0, [r1]
	mov r2, ip
	ldr r0, [r2, #0x50]
	str r0, [r1, #4]
	mov r0, ip
	adds r0, #0x54
	ldrh r0, [r0]
	strh r0, [r1, #8]
	mov r0, ip
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	mov r0, ip
	adds r0, #0x78
	ldrb r2, [r0]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r2
	ldrb r2, [r1, #0xc]
	ands r3, r2
	orrs r3, r0
	mov r0, ip
	adds r0, #0x79
	ldrb r0, [r0]
	lsls r0, r0, #4
	ands r3, r4
	orrs r3, r0
	strb r3, [r1, #0xc]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_080DD994
func_080DD994: @ 0x080DD994
	push {r4, lr}
	sub sp, #0x10
	mov ip, r0
	adds r0, #0x54
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	mov r0, ip
	adds r0, #0x56
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	mov r0, ip
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	mov r0, ip
	bl func_08039F90
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DD9CC
func_080DD9CC: @ 0x080DD9CC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x62
	movs r4, #0
	ldrsb r4, [r6, r4]
	cmp r4, #1
	beq .L080DDA14
	cmp r4, #1
	bgt .L080DD9E8
	cmp r4, #0
	beq .L080DD9F8
	subs r6, #0x1b
	b .L080DDBD6
.L080DD9E8:
	cmp r4, #2
	beq .L080DDA6C
	adds r6, r5, #0
	adds r6, #0x47
	cmp r4, #3
	bne .L080DD9F6
	b .L080DDB66
.L080DD9F6:
	b .L080DDBD6
.L080DD9F8:
	movs r0, #2
	bl RandomBelow
	adds r0, #0x1e
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, #0x26
	strh r4, [r0]
	movs r0, #1
	b .L080DDA28
.L080DDA14:
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080DDA30
	movs r0, #2
.L080DDA28:
	strb r0, [r6]
	adds r6, r5, #0
	adds r6, #0x47
	b .L080DDBD6
.L080DDA30:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r6, r5, #0
	adds r6, #0x47
	cmp r0, r2
	bgt .L080DDA3E
	b .L080DDBD6
.L080DDA3E:
	adds r1, r5, #0
	adds r1, #0x86
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L080DDA50
	b .L080DDBD6
.L080DDA50:
	strh r2, [r1]
	bl rand
	asrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080DDA62
	b .L080DDBD6
.L080DDA62:
	adds r0, r5, #0
	movs r1, #0xce
	bl func_0803A350
	b .L080DDBD6
.L080DDA6C:
	adds r2, r5, #0
	adds r2, #0x79
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080DDA8A
	adds r0, r5, #0
	adds r0, #0x78
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
.L080DDA8A:
	adds r1, r5, #0
	adds r1, #0x64
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r0, r5, #0
	bl func_0803A144
	adds r0, r5, #0
	adds r0, #0x68
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #0x10
	str r1, [r5, #0x6c]
	adds r0, #2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #0x10
	str r2, [r5, #0x70]
	ldr r0, [r5, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x7c]
	adds r1, r5, #0
	adds r1, #0x80
	ldr r0, [r5, #0x5c]
	subs r2, r2, r0
	str r2, [r1]
	ldr r0, [r5, #0x7c]
	adds r1, r0, #0
	cmp r0, #0
	bge .L080DDACA
	rsbs r1, r0, #0
.L080DDACA:
	asrs r7, r1, #0x11
	adds r1, r2, #0
	cmp r2, #0
	bge .L080DDAD4
	rsbs r1, r2, #0
.L080DDAD4:
	asrs r6, r1, #0x11
	cmp r7, r6
	ble .L080DDB06
	cmp r0, #0
	bge .L080DDAE2
	str r4, [r5, #0x50]
	b .L080DDAE6
.L080DDAE2:
	movs r0, #3
	str r0, [r5, #0x50]
.L080DDAE6:
	ldr r0, [r5, #0x7c]
	adds r1, r7, #0
	bl __divsi3
	str r0, [r5, #0x7c]
	adds r4, r5, #0
	adds r4, #0x80
	ldr r0, [r4]
	adds r1, r7, #0
	bl __divsi3
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0x60
	strh r7, [r0]
	b .L080DDB30
.L080DDB06:
	cmp r2, #0
	bge .L080DDB0E
	movs r0, #1
	b .L080DDB10
.L080DDB0E:
	movs r0, #0
.L080DDB10:
	str r0, [r5, #0x50]
	ldr r0, [r5, #0x7c]
	adds r1, r6, #0
	bl __divsi3
	str r0, [r5, #0x7c]
	adds r4, r5, #0
	adds r4, #0x80
	ldr r0, [r4]
	adds r1, r6, #0
	bl __divsi3
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0x60
	strh r6, [r0]
.L080DDB30:
	ldr r4, .L080DDC08 @ =0x000002A9
	ldrh r0, [r5, #4]
	adds r6, r5, #0
	adds r6, #0x47
	cmp r0, r4
	beq .L080DDB58
	adds r0, r5, #0
	adds r0, #0x30
	adds r1, r4, #0
	bl ResolveIndexedResourceHandle
	adds r1, r5, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #2
	strb r2, [r1]
	strb r0, [r6]
	strh r4, [r5, #4]
.L080DDB58:
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #3
	strb r0, [r1]
	adds r1, #0x22
	movs r0, #8
	strb r0, [r1]
.L080DDB66:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x7c]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0x80
	ldr r0, [r5, #0x5c]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, #1
	movs r7, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt .L080DDBD6
	adds r2, r5, #0
	adds r2, #0x79
	ldrb r1, [r2]
	adds r0, r5, #0
	adds r0, #0x78
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, [r5, #0x6c]
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x70]
	str r0, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0x62
	strb r7, [r0]
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #0xf8
	strb r0, [r1]
	movs r4, #0xa9
	lsls r4, r4, #2
	ldrh r0, [r5, #4]
	cmp r0, r4
	beq .L080DDBD6
	adds r0, r5, #0
	adds r0, #0x30
	adds r1, r4, #0
	bl ResolveIndexedResourceHandle
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r7, [r0]
	strb r1, [r6]
	strh r4, [r5, #4]
.L080DDBD6:
	ldr r0, [r5, #0x58]
	asrs r0, r0, #0x10
	adds r1, r5, #0
	adds r1, #0x54
	strh r0, [r1]
	ldr r0, [r5, #0x5c]
	asrs r0, r0, #0x10
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	bne .L080DDC0C
	adds r0, r5, #0
	adds r0, #0x30
	bl UpdateIndexedResourceHandle
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DDC10
	adds r1, r5, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
	b .L080DDC10
	.align 2, 0
.L080DDC08: .4byte 0x000002A9
.L080DDC0C:
	movs r0, #0
	strb r0, [r6]
.L080DDC10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDC18
func_080DDC18: @ 0x080DDC18
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDC24
func_080DDC24: @ 0x080DDC24
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #5
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DDC48
func_080DDC48: @ 0x080DDC48
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	ldr r4, [r0, #0x68]
	asrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDC78
func_080DDC78: @ 0x080DDC78
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x62
	movs r4, #0
	ldrsb r4, [r5, r4]
	cmp r4, #1
	beq .L080DDD1C
	cmp r4, #1
	bgt .L080DDCA2
	cmp r4, #0
	beq .L080DDCB4
	adds r4, r6, #0
	adds r4, #0x60
	movs r0, #0x47
	adds r0, r0, r6
	mov r8, r0
	b .L080DDE1E
.L080DDCA2:
	cmp r4, #2
	bne .L080DDCA8
	b .L080DDE08
.L080DDCA8:
	adds r4, r6, #0
	adds r4, #0x60
	movs r1, #0x47
	adds r1, r1, r6
	mov r8, r1
	b .L080DDE1E
.L080DDCB4:
	bl rand
	asrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	adds r0, #1
	strb r0, [r5]
	adds r5, r0, #0
	cmp r5, #1
	bne .L080DDCEE
	movs r0, #4
	bl RandomBelow
	lsls r0, r0, #8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r4, r6, #0
	adds r4, #0x60
	strh r0, [r4]
	bl rand
	asrs r0, r0, #8
	ands r0, r5
	lsls r0, r0, #0xb
	adds r1, r6, #0
	adds r1, #0x64
	strh r0, [r1]
	b .L080DDD04
.L080DDCEE:
	movs r0, #2
	bl RandomBelow
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0xb4
	adds r0, r6, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r4, r0, #0
.L080DDD04:
	movs r0, #2
	bl RandomBelow
	lsls r0, r0, #2
	adds r0, #0xc
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	movs r3, #0x47
	adds r3, r3, r6
	mov r8, r3
	b .L080DDE1E
.L080DDD1C:
	adds r1, r6, #0
	adds r1, #0x64
	ldrh r0, [r1]
	movs r7, #0xff
	lsls r7, r7, #4
	ands r7, r0
	mov sb, r1
	cmp r7, #0
	bne .L080DDD5C
	ldr r5, .L080DDD58 @ =0x00000205
	ldrh r0, [r6, #4]
	movs r1, #0x47
	adds r1, r1, r6
	mov r8, r1
	cmp r0, r5
	beq .L080DDD90
	adds r0, r6, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r6, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #2
	strb r7, [r0]
	mov r2, r8
	strb r4, [r2]
	b .L080DDD8E
	.align 2, 0
.L080DDD58: .4byte 0x00000205
.L080DDD5C:
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #0x47
	adds r3, r3, r6
	mov r8, r3
	cmp r7, r0
	bne .L080DDD90
	movs r5, #0x81
	lsls r5, r5, #2
	ldrh r0, [r6, #4]
	cmp r0, r5
	beq .L080DDD90
	adds r0, r6, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r6, #0
	adds r0, #0x44
	movs r1, #0
	strb r4, [r0]
	adds r0, #2
	strb r1, [r0]
	mov r0, r8
	strb r4, [r0]
.L080DDD8E:
	strh r5, [r6, #4]
.L080DDD90:
	mov r2, sb
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	movs r5, #0xff
	ands r1, r5
	adds r0, r6, #0
	bl func_0803A320
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r3, sb
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	lsls r1, r1, #1
	ands r1, r5
	adds r0, r6, #0
	bl func_0803A334
	lsls r0, r0, #0x10
	adds r1, r6, #0
	adds r1, #0x66
	ldrh r1, [r1]
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r1, r2
	mov r3, sb
	strh r1, [r3]
	lsls r4, r4, #6
	ldr r2, [r6, #0x58]
	adds r2, r2, r4
	str r2, [r6, #0x58]
	asrs r0, r0, #0xa
	ldr r1, [r6, #0x5c]
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	asrs r2, r2, #0x10
	adds r0, r6, #0
	adds r0, #0x54
	strh r2, [r0]
	ldr r0, [r6, #0x5c]
	asrs r0, r0, #0x10
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldr r1, [r6, #0x68]
	ldr r0, .L080DDE04 @ =0x0007FFFF
	adds r4, r6, #0
	adds r4, #0x60
	cmp r1, r0
	bgt .L080DDE1E
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r1, r2
	b .L080DDE1C
	.align 2, 0
.L080DDE04: .4byte 0x0007FFFF
.L080DDE08:
	ldr r0, [r6, #0x68]
	adds r4, r6, #0
	adds r4, #0x60
	movs r3, #0x47
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	ble .L080DDE1E
	ldr r1, .L080DDE54 @ =0xFFFFE000
	adds r0, r0, r1
.L080DDE1C:
	str r0, [r6, #0x68]
.L080DDE1E:
	ldrh r0, [r4]
	subs r0, #1
	movs r1, #0
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080DDE32
	adds r0, r6, #0
	adds r0, #0x62
	strb r1, [r0]
.L080DDE32:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne .L080DDE58
	adds r0, r6, #0
	adds r0, #0x30
	bl UpdateIndexedResourceHandle
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080DDE5C
	adds r1, r6, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
	b .L080DDE5C
	.align 2, 0
.L080DDE54: .4byte 0xFFFFE000
.L080DDE58:
	mov r3, r8
	strb r1, [r3]
.L080DDE5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_080DDE68
func_080DDE68: @ 0x080DDE68
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDE74
func_080DDE74: @ 0x080DDE74
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #4
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DDE98
func_080DDE98: @ 0x080DDE98
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DDEC4
func_080DDEC4: @ 0x080DDEC4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #6
	bl func_0803A180
	cmp r0, #0
	beq .L080DDF02
	ldr r0, [r4, #0x50]
	ldr r1, .L080DDF08 @ =0x00000806
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DDF02
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DDF02:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DDF08: .4byte 0x00000806

	thumb_func_start func_080DDF0C
func_080DDF0C: @ 0x080DDF0C
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDF18
func_080DDF18: @ 0x080DDF18
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #3
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DDF3C
func_080DDF3C: @ 0x080DDF3C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DDF68
func_080DDF68: @ 0x080DDF68
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #7
	bl func_0803A180
	cmp r0, #0
	beq .L080DDFA6
	ldr r0, [r4, #0x50]
	ldr r1, .L080DDFAC @ =0x000003DB
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DDFA6
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DDFA6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DDFAC: .4byte 0x000003DB

	thumb_func_start func_080DDFB0
func_080DDFB0: @ 0x080DDFB0
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DDFBC
func_080DDFBC: @ 0x080DDFBC
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #2
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DDFE0
func_080DDFE0: @ 0x080DDFE0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DE00C
func_080DE00C: @ 0x080DE00C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #8
	bl func_0803A180
	cmp r0, #0
	beq .L080DE04A
	ldr r0, [r4, #0x50]
	adds r5, r0, #0
	adds r5, #0x10
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DE04A
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DE04A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DE050
func_080DE050: @ 0x080DE050
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DE05C
func_080DE05C: @ 0x080DE05C
	ldrb r3, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #1
	orrs r2, r3
	strb r2, [r1]
	ldr r2, [r0, #0x50]
	str r2, [r1, #4]
	adds r2, r0, #0
	adds r2, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #8]
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r1, #0xa]
	bx lr
	.align 2, 0

	thumb_func_start func_080DE080
func_080DE080: @ 0x080DE080
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x54
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	adds r4, r0, #0
	adds r4, #0x56
	movs r5, #0
	ldrsh r4, [r4, r5]
	str r4, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r4, #2
	str r4, [sp, #0xc]
	bl func_08039F90
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DE0AC
func_080DE0AC: @ 0x080DE0AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #8
	bl func_0803A180
	cmp r0, #0
	beq .L080DE11E
	adds r0, r4, #0
	adds r0, #0x62
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne .L080DE0F4
	ldr r0, [r4, #0x50]
	ldr r1, .L080DE0F0 @ =0x000009B6
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DE11E
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r6, [r0]
	b .L080DE118
	.align 2, 0
.L080DE0F0: .4byte 0x000009B6
.L080DE0F4:
	ldr r0, [r4, #0x50]
	ldr r1, .L080DE124 @ =0x000009BA
	adds r5, r0, r1
	ldrh r0, [r4, #4]
	cmp r0, r5
	beq .L080DE11E
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	bl ResolveIndexedResourceHandle
	adds r0, r4, #0
	adds r0, #0x44
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
.L080DE118:
	adds r0, #1
	strb r1, [r0]
	strh r5, [r4, #4]
.L080DE11E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080DE124: .4byte 0x000009BA

	thumb_func_start func_080DE128
func_080DE128: @ 0x080DE128
	push {lr}
	bl func_08039F50
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DE134
func_080DE134: @ 0x080DE134
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, [r0]
	ldr r2, [r2]
	mov sb, r2
	ldr r2, [r1, #8]
	mov r8, r2
	ldr r7, [r1]
	adds r5, r0, #0
	adds r5, #0xc
	ldr r1, [r0, #8]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r6, r1, #0
	adds r6, #0xc
	cmp r5, r6
	beq .L080DE176
.L080DE15A:
	ldr r1, [r5]
	cmp r1, #0
	beq .L080DE170
	ldr r0, [r1, #0x4c]
	ldr r4, [r0, #0x10]
	adds r0, r1, #0
	mov r1, sb
	mov r2, r8
	adds r3, r7, #0
	bl _call_via_r4
.L080DE170:
	adds r5, #4
	cmp r5, r6
	bne .L080DE15A
.L080DE176:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080DE184
func_080DE184: @ 0x080DE184
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xc
	ldr r1, [r0, #8]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r5, r1, #0
	adds r5, #0xc
	cmp r4, r5
	beq .L080DE1AE
.L080DE198:
	ldr r2, [r4]
	cmp r2, #0
	beq .L080DE1A8
	ldr r0, [r2, #0x4c]
	ldr r1, [r0, #0xc]
	adds r0, r2, #0
	bl _call_via_r1
.L080DE1A8:
	adds r4, #4
	cmp r4, r5
	bne .L080DE198
.L080DE1AE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080DE1B4
func_080DE1B4: @ 0x080DE1B4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080DE1D4 @ =vtable_unk_080E76D4
	str r0, [r4, #4]
	ldr r0, [r4, #8]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0xc
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0xc
	str r0, [sp, #0xc]
	b .L080DE1F2
	.align 2, 0
.L080DE1D4: .4byte vtable_unk_080E76D4
.L080DE1D8:
	subs r0, r2, #4
	ldr r1, [r0]
	cmp r1, #0
	beq .L080DE1EC
	ldr r0, [r1, #0x4c]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080DE1EC:
	ldr r0, [sp, #4]
	subs r0, #4
	str r0, [sp, #4]
.L080DE1F2:
	ldr r2, [sp, #4]
	ldr r0, [sp, #0xc]
	movs r1, #0
	cmp r2, r0
	bne .L080DE1FE
	movs r1, #1
.L080DE1FE:
	cmp r1, #0
	beq .L080DE1D8
	ldr r0, .L080DE21C @ =__vt_22EntityVisualController
	str r0, [r4, #4]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080DE214
	adds r0, r4, #0
	bl __builtin_delete
.L080DE214:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080DE21C: .4byte __vt_22EntityVisualController
    .section .text.farming_tutorial_runtime, "ax", %progbits
    .align 2, 0
	thumb_func_start __thunk_12_OnCall__20FarmingTutorialScenei
__thunk_12_OnCall__20FarmingTutorialScenei: @ 0x080DE298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	subs r0, #0xc
	mov r8, r0
	subs r1, #2
	ldr r0, .L080DE2C0 @ =0x00000141
	cmp r1, r0
	bls .L080DE2B4
	bl .L080E0080
.L080DE2B4:
	lsls r0, r1, #2
	ldr r1, .L080DE2C4 @ =.L080DE2C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080DE2C0: .4byte 0x00000141
.L080DE2C4: .4byte .L080DE2C8
.L080DE2C8: @ jump table
	.4byte .L080DF750 @ case 0
	.4byte .L080DF8C6 @ case 1
	.4byte .L080DF904 @ case 2
	.4byte .L080DF940 @ case 3
	.4byte .L080DF99C @ case 4
	.4byte .L080E0080 @ case 5
	.4byte .L080DF9EE @ case 6
	.4byte .L080DFAB2 @ case 7
	.4byte .L080DFA50 @ case 8
	.4byte .L080DFB14 @ case 9
	.4byte .L080DFB76 @ case 10
	.4byte .L080DFBB6 @ case 11
	.4byte .L080DFC10 @ case 12
	.4byte .L080DFC24 @ case 13
	.4byte .L080E0080 @ case 14
	.4byte .L080DFC5C @ case 15
	.4byte .L080DFCC2 @ case 16
	.4byte .L080E0080 @ case 17
	.4byte .L080E0080 @ case 18
	.4byte .L080E0080 @ case 19
	.4byte .L080DF51A @ case 20
	.4byte .L080DF5E8 @ case 21
	.4byte .L080DF638 @ case 22
	.4byte .L080DF65E @ case 23
	.4byte .L080DF6B0 @ case 24
	.4byte .L080DF6C2 @ case 25
	.4byte .L080DF748 @ case 26
	.4byte .L080E0080 @ case 27
	.4byte .L080E0080 @ case 28
	.4byte .L080DE7D0 @ case 29
	.4byte .L080DE8AE @ case 30
	.4byte .L080DE97C @ case 31
	.4byte .L080DE8CE @ case 32
	.4byte .L080DE924 @ case 33
	.4byte .L080DE9D4 @ case 34
	.4byte .L080DEAA4 @ case 35
	.4byte .L080DEBB8 @ case 36
	.4byte .L080DED0C @ case 37
	.4byte .L080DEDB4 @ case 38
	.4byte .L080DEE9E @ case 39
	.4byte .L080DEFCE @ case 40
	.4byte .L080DF136 @ case 41
	.4byte .L080E0080 @ case 42
	.4byte .L080E0080 @ case 43
	.4byte .L080E0080 @ case 44
	.4byte .L080E0080 @ case 45
	.4byte .L080E0080 @ case 46
	.4byte .L080E0080 @ case 47
	.4byte .L080E0080 @ case 48
	.4byte .L080DF318 @ case 49
	.4byte .L080DF3F0 @ case 50
	.4byte .L080E0080 @ case 51
	.4byte .L080DF2EC @ case 52
	.4byte .L080DFCF6 @ case 53
	.4byte .L080E0080 @ case 54
	.4byte .L080E0080 @ case 55
	.4byte .L080E0080 @ case 56
	.4byte .L080E0080 @ case 57
	.4byte .L080E0080 @ case 58
	.4byte .L080E0080 @ case 59
	.4byte .L080E0080 @ case 60
	.4byte .L080E0080 @ case 61
	.4byte .L080E0080 @ case 62
	.4byte .L080E0080 @ case 63
	.4byte .L080E0080 @ case 64
	.4byte .L080E0080 @ case 65
	.4byte .L080E0080 @ case 66
	.4byte .L080E0040 @ case 67
	.4byte .L080E0080 @ case 68
	.4byte .L080DFF6E @ case 69
	.4byte .L080DFFF2 @ case 70
	.4byte .L080E0080 @ case 71
	.4byte .L080E0080 @ case 72
	.4byte .L080E0080 @ case 73
	.4byte .L080E0080 @ case 74
	.4byte .L080E0058 @ case 75
	.4byte .L080E0080 @ case 76
	.4byte .L080E0080 @ case 77
	.4byte .L080E0080 @ case 78
	.4byte .L080E0080 @ case 79
	.4byte .L080E0080 @ case 80
	.4byte .L080E0080 @ case 81
	.4byte .L080E0080 @ case 82
	.4byte .L080E0080 @ case 83
	.4byte .L080E0080 @ case 84
	.4byte .L080E0080 @ case 85
	.4byte .L080E0080 @ case 86
	.4byte .L080E0080 @ case 87
	.4byte .L080DFF3A @ case 88
	.4byte .L080E0080 @ case 89
	.4byte .L080E0080 @ case 90
	.4byte .L080E0080 @ case 91
	.4byte .L080E0080 @ case 92
	.4byte .L080E0080 @ case 93
	.4byte .L080E0080 @ case 94
	.4byte .L080E0080 @ case 95
	.4byte .L080E0080 @ case 96
	.4byte .L080E0080 @ case 97
	.4byte .L080E0080 @ case 98
	.4byte .L080E0080 @ case 99
	.4byte .L080E0080 @ case 100
	.4byte .L080E0080 @ case 101
	.4byte .L080E0080 @ case 102
	.4byte .L080E0080 @ case 103
	.4byte .L080E0080 @ case 104
	.4byte .L080E0080 @ case 105
	.4byte .L080E0080 @ case 106
	.4byte .L080E0080 @ case 107
	.4byte .L080E0080 @ case 108
	.4byte .L080E0080 @ case 109
	.4byte .L080E0080 @ case 110
	.4byte .L080E0080 @ case 111
	.4byte .L080E0080 @ case 112
	.4byte .L080E0080 @ case 113
	.4byte .L080E0080 @ case 114
	.4byte .L080E0080 @ case 115
	.4byte .L080E0080 @ case 116
	.4byte .L080E0080 @ case 117
	.4byte .L080E0080 @ case 118
	.4byte .L080E0080 @ case 119
	.4byte .L080E0080 @ case 120
	.4byte .L080E0080 @ case 121
	.4byte .L080E0080 @ case 122
	.4byte .L080E0080 @ case 123
	.4byte .L080E0080 @ case 124
	.4byte .L080E0080 @ case 125
	.4byte .L080E0080 @ case 126
	.4byte .L080E0080 @ case 127
	.4byte .L080E0080 @ case 128
	.4byte .L080E0080 @ case 129
	.4byte .L080E0080 @ case 130
	.4byte .L080E0080 @ case 131
	.4byte .L080E0080 @ case 132
	.4byte .L080E0080 @ case 133
	.4byte .L080E0080 @ case 134
	.4byte .L080E0080 @ case 135
	.4byte .L080E0080 @ case 136
	.4byte .L080E0080 @ case 137
	.4byte .L080E0080 @ case 138
	.4byte .L080E0080 @ case 139
	.4byte .L080E0080 @ case 140
	.4byte .L080E0080 @ case 141
	.4byte .L080E0080 @ case 142
	.4byte .L080E0080 @ case 143
	.4byte .L080E0080 @ case 144
	.4byte .L080E0080 @ case 145
	.4byte .L080E0080 @ case 146
	.4byte .L080E0080 @ case 147
	.4byte .L080E0080 @ case 148
	.4byte .L080E0080 @ case 149
	.4byte .L080E0080 @ case 150
	.4byte .L080E0080 @ case 151
	.4byte .L080E0080 @ case 152
	.4byte .L080E0080 @ case 153
	.4byte .L080E0080 @ case 154
	.4byte .L080E0080 @ case 155
	.4byte .L080E0080 @ case 156
	.4byte .L080E0080 @ case 157
	.4byte .L080E0080 @ case 158
	.4byte .L080E0080 @ case 159
	.4byte .L080E0080 @ case 160
	.4byte .L080E0080 @ case 161
	.4byte .L080E0080 @ case 162
	.4byte .L080E0080 @ case 163
	.4byte .L080E0080 @ case 164
	.4byte .L080E0080 @ case 165
	.4byte .L080E0080 @ case 166
	.4byte .L080E0080 @ case 167
	.4byte .L080E0080 @ case 168
	.4byte .L080E0080 @ case 169
	.4byte .L080E0080 @ case 170
	.4byte .L080E0080 @ case 171
	.4byte .L080E0080 @ case 172
	.4byte .L080E0080 @ case 173
	.4byte .L080E0080 @ case 174
	.4byte .L080E0080 @ case 175
	.4byte .L080E0080 @ case 176
	.4byte .L080E0080 @ case 177
	.4byte .L080E0080 @ case 178
	.4byte .L080E0080 @ case 179
	.4byte .L080E0080 @ case 180
	.4byte .L080E0080 @ case 181
	.4byte .L080DFD5C @ case 182
	.4byte .L080DFD80 @ case 183
	.4byte .L080E0080 @ case 184
	.4byte .L080E0080 @ case 185
	.4byte .L080E0080 @ case 186
	.4byte .L080E0080 @ case 187
	.4byte .L080E0080 @ case 188
	.4byte .L080DFD38 @ case 189
	.4byte .L080DFD24 @ case 190
	.4byte .L080E0080 @ case 191
	.4byte .L080E0080 @ case 192
	.4byte .L080E0080 @ case 193
	.4byte .L080E0080 @ case 194
	.4byte .L080E0080 @ case 195
	.4byte .L080E0080 @ case 196
	.4byte .L080E0080 @ case 197
	.4byte .L080E0080 @ case 198
	.4byte .L080E0080 @ case 199
	.4byte .L080E0080 @ case 200
	.4byte .L080E0080 @ case 201
	.4byte .L080E0080 @ case 202
	.4byte .L080E0080 @ case 203
	.4byte .L080E0080 @ case 204
	.4byte .L080E0080 @ case 205
	.4byte .L080E0080 @ case 206
	.4byte .L080E0080 @ case 207
	.4byte .L080E0080 @ case 208
	.4byte .L080E0080 @ case 209
	.4byte .L080E0080 @ case 210
	.4byte .L080E0080 @ case 211
	.4byte .L080E0080 @ case 212
	.4byte .L080E0080 @ case 213
	.4byte .L080E0080 @ case 214
	.4byte .L080E0080 @ case 215
	.4byte .L080E0080 @ case 216
	.4byte .L080E0080 @ case 217
	.4byte .L080E0080 @ case 218
	.4byte .L080E0080 @ case 219
	.4byte .L080E0080 @ case 220
	.4byte .L080E0080 @ case 221
	.4byte .L080E0080 @ case 222
	.4byte .L080E0080 @ case 223
	.4byte .L080E0080 @ case 224
	.4byte .L080E0080 @ case 225
	.4byte .L080E0080 @ case 226
	.4byte .L080E0080 @ case 227
	.4byte .L080E0080 @ case 228
	.4byte .L080E0080 @ case 229
	.4byte .L080E0080 @ case 230
	.4byte .L080E0080 @ case 231
	.4byte .L080E0080 @ case 232
	.4byte .L080E0080 @ case 233
	.4byte .L080E0080 @ case 234
	.4byte .L080E0080 @ case 235
	.4byte .L080E0080 @ case 236
	.4byte .L080E0080 @ case 237
	.4byte .L080E0080 @ case 238
	.4byte .L080E0080 @ case 239
	.4byte .L080E0080 @ case 240
	.4byte .L080E0080 @ case 241
	.4byte .L080E0080 @ case 242
	.4byte .L080E0080 @ case 243
	.4byte .L080E0080 @ case 244
	.4byte .L080E0080 @ case 245
	.4byte .L080E0080 @ case 246
	.4byte .L080E0080 @ case 247
	.4byte .L080E0080 @ case 248
	.4byte .L080E0080 @ case 249
	.4byte .L080E0080 @ case 250
	.4byte .L080E0080 @ case 251
	.4byte .L080E0080 @ case 252
	.4byte .L080E0080 @ case 253
	.4byte .L080E0080 @ case 254
	.4byte .L080E0080 @ case 255
	.4byte .L080E0080 @ case 256
	.4byte .L080E0080 @ case 257
	.4byte .L080E0080 @ case 258
	.4byte .L080E0080 @ case 259
	.4byte .L080E0080 @ case 260
	.4byte .L080E0080 @ case 261
	.4byte .L080E0080 @ case 262
	.4byte .L080E0080 @ case 263
	.4byte .L080E0080 @ case 264
	.4byte .L080E0080 @ case 265
	.4byte .L080E0080 @ case 266
	.4byte .L080E0080 @ case 267
	.4byte .L080E0080 @ case 268
	.4byte .L080E0080 @ case 269
	.4byte .L080E0080 @ case 270
	.4byte .L080E0080 @ case 271
	.4byte .L080E0080 @ case 272
	.4byte .L080E0080 @ case 273
	.4byte .L080E0080 @ case 274
	.4byte .L080E0080 @ case 275
	.4byte .L080E0080 @ case 276
	.4byte .L080E0080 @ case 277
	.4byte .L080E0080 @ case 278
	.4byte .L080E0080 @ case 279
	.4byte .L080E0080 @ case 280
	.4byte .L080E0080 @ case 281
	.4byte .L080E0080 @ case 282
	.4byte .L080E0080 @ case 283
	.4byte .L080E0080 @ case 284
	.4byte .L080E0080 @ case 285
	.4byte .L080E0080 @ case 286
	.4byte .L080E0080 @ case 287
	.4byte .L080E0080 @ case 288
	.4byte .L080E0080 @ case 289
	.4byte .L080E0080 @ case 290
	.4byte .L080E0080 @ case 291
	.4byte .L080E0080 @ case 292
	.4byte .L080E0080 @ case 293
	.4byte .L080E0080 @ case 294
	.4byte .L080E0080 @ case 295
	.4byte .L080E0080 @ case 296
	.4byte .L080E0080 @ case 297
	.4byte .L080E0080 @ case 298
	.4byte .L080E0080 @ case 299
	.4byte .L080E0080 @ case 300
	.4byte .L080E0080 @ case 301
	.4byte .L080E0080 @ case 302
	.4byte .L080E0080 @ case 303
	.4byte .L080E0080 @ case 304
	.4byte .L080E0080 @ case 305
	.4byte .L080E0080 @ case 306
	.4byte .L080E0080 @ case 307
	.4byte .L080E0080 @ case 308
	.4byte .L080E0080 @ case 309
	.4byte .L080E0080 @ case 310
	.4byte .L080E0080 @ case 311
	.4byte .L080E0080 @ case 312
	.4byte .L080E0080 @ case 313
	.4byte .L080E0080 @ case 314
	.4byte .L080E0080 @ case 315
	.4byte .L080DFDAC @ case 316
	.4byte .L080DFE36 @ case 317
	.4byte .L080DFE8C @ case 318
	.4byte .L080DFEFE @ case 319
	.4byte .L080DFFBA @ case 320
	.4byte .L080DF85C @ case 321
.L080DE7D0:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r5, [r0]
	adds r6, r0, #0
	cmp r5, #0
	bne .L080DE88E
	movs r0, #0xe8
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DE83E
	movs r0, #4
	bl __builtin_new
	adds r4, r0, #0
	add r0, sp, #0x10
	bl __17ObjTileCollection
	add r0, sp, #0x14
	bl __20ObjPaletteCollection
	add r1, sp, #0x14
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
	adds r5, r6, #0
	adds r4, r0, #0
	ldr r0, [r6]
	cmp r4, r0
	beq .L080DE82A
	cmp r0, #0
	beq .L080DE82A
	movs r1, #3
	bl _._12UiStateOwner
.L080DE82A:
	str r4, [r5]
	add r0, sp, #0x14
	movs r1, #2
	bl _._20ObjPaletteCollection
	add r0, sp, #0x10
	movs r1, #2
	bl _._17ObjTileCollection
	b .L080DE88E
.L080DE83E:
	movs r0, #4
	bl __builtin_new
	adds r4, r0, #0
	add r0, sp, #0x10
	bl __17ObjTileCollection
	add r0, sp, #0x14
	bl __20ObjPaletteCollection
	add r0, sp, #0x14
	str r5, [sp]
	add r1, sp, #0x10
	str r1, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x1f
	movs r3, #0
	bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection
	adds r5, r6, #0
	adds r4, r0, #0
	ldr r0, [r6]
	cmp r4, r0
	beq .L080DE87C
	cmp r0, #0
	beq .L080DE87C
	movs r1, #3
	bl _._12UiStateOwner
.L080DE87C:
	str r4, [r5]
	add r0, sp, #0x14
	movs r1, #2
	bl _._20ObjPaletteCollection
	add r0, sp, #0x10
	movs r1, #2
	bl _._17ObjTileCollection
.L080DE88E:
	ldr r0, [r6]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	bne .L080DE89C
	bl .L080E007C
.L080DE89C:
	ldr r0, [r6]
	bl func_08050D5C
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #2
	bl .L080E007A
.L080DE8AE:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DE8BE
	bl .L080E007C
.L080DE8BE:
	bl func_08050D74
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #3
	bl .L080E007A
.L080DE8CE:
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r1, #0
	beq .L080DE8E4
	subs r0, r1, #1
	str r0, [r2]
.L080DE8E4:
	mov r2, r8
	adds r2, #0xc
	ldr r0, [r2, #0x10]
	cmp r3, r0
	bhi .L080DE8FC
	ldr r1, [r2, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DE8FE
.L080DE8FC:
	ldr r1, .L080DE920 @ =gText_Fallback_Error
.L080DE8FE:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DE90E
	bl .L080E007C
.L080DE90E:
	movs r2, #0x40
	bl func_08050DB4
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #4
	bl .L080E007A
	.align 2, 0
.L080DE920: .4byte gText_Fallback_Error
.L080DE924:
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r1, #0
	beq .L080DE93A
	subs r0, r1, #1
	str r0, [r2]
.L080DE93A:
	mov r2, r8
	adds r2, #0xc
	ldr r0, [r2, #0x10]
	cmp r3, r0
	bhi .L080DE952
	ldr r1, [r2, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DE954
.L080DE952:
	ldr r1, .L080DE978 @ =gText_Fallback_Error
.L080DE954:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DE964
	bl .L080E007C
.L080DE964:
	movs r2, #0
	bl func_08050DB4
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #4
	bl .L080E007A
	.align 2, 0
.L080DE978: .4byte gText_Fallback_Error
.L080DE97C:
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r1, #0
	beq .L080DE992
	subs r0, r1, #1
	str r0, [r2]
.L080DE992:
	mov r2, r8
	adds r2, #0xc
	ldr r0, [r2, #0x10]
	cmp r3, r0
	bhi .L080DE9AA
	ldr r1, [r2, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DE9AC
.L080DE9AA:
	ldr r1, .L080DE9D0 @ =gText_Fallback_Error
.L080DE9AC:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DE9BC
	bl .L080E007C
.L080DE9BC:
	movs r2, #0x80
	lsls r2, r2, #1
	bl func_08050DB4
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #4
	bl .L080E007A
	.align 2, 0
.L080DE9D0: .4byte gText_Fallback_Error
.L080DE9D4:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DE9F0
	subs r0, r1, #1
	str r0, [r2]
.L080DE9F0:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DEA02
	subs r0, r1, #1
	str r0, [r2]
.L080DEA02:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DEA14
	subs r0, r1, #1
	str r0, [r2]
.L080DEA14:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DEA2E
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r6, r1, r0
	b .L080DEA30
.L080DEA2E:
	ldr r6, .L080DEA44 @ =gText_Fallback_Error
.L080DEA30:
	ldr r0, [r4, #0x10]
	cmp r5, r0
	bhi .L080DEA48
	ldr r1, [r4, #0x14]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DEA4A
	.align 2, 0
.L080DEA44: .4byte gText_Fallback_Error
.L080DEA48:
	ldr r2, .L080DEA60 @ =gText_Fallback_Error
.L080DEA4A:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DEA64
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DEA66
	.align 2, 0
.L080DEA60: .4byte gText_Fallback_Error
.L080DEA64:
	ldr r3, .L080DEAA0 @ =gText_Fallback_Error
.L080DEA66:
	movs r1, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DEA78
	bl .L080E007C
.L080DEA78:
	cmp r2, #0
	bne .L080DEA80
	bl .L080E007C
.L080DEA80:
	cmp r3, #0
	bne .L080DEA88
	bl .L080E007C
.L080DEA88:
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	adds r1, r6, #0
	bl func_08050E30
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
	.align 2, 0
.L080DEAA0: .4byte gText_Fallback_Error
.L080DEAA4:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r1, #0
	beq .L080DEAC2
	subs r0, r1, #1
	str r0, [r2]
.L080DEAC2:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DEAD4
	subs r0, r1, #1
	str r0, [r2]
.L080DEAD4:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DEAE6
	subs r0, r1, #1
	str r0, [r2]
.L080DEAE6:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DEAF8
	subs r0, r1, #1
	str r0, [r2]
.L080DEAF8:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DEB12
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DEB14
.L080DEB12:
	ldr r5, .L080DEB28 @ =gText_Fallback_Error
.L080DEB14:
	ldr r0, [r4, #0x10]
	cmp r6, r0
	bhi .L080DEB2C
	ldr r1, [r4, #0x14]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DEB2E
	.align 2, 0
.L080DEB28: .4byte gText_Fallback_Error
.L080DEB2C:
	ldr r2, .L080DEB44 @ =gText_Fallback_Error
.L080DEB2E:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DEB48
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DEB4A
	.align 2, 0
.L080DEB44: .4byte gText_Fallback_Error
.L080DEB48:
	ldr r3, .L080DEB60 @ =gText_Fallback_Error
.L080DEB4A:
	ldr r0, [r4, #0x10]
	cmp sb, r0
	bhi .L080DEB64
	ldr r1, [r4, #0x14]
	mov r6, sb
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DEB66
	.align 2, 0
.L080DEB60: .4byte gText_Fallback_Error
.L080DEB64:
	ldr r1, .L080DEB9C @ =gText_Fallback_Error
.L080DEB66:
	movs r4, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DEB78
	bl .L080E007C
.L080DEB78:
	cmp r2, #0
	bne .L080DEB80
	bl .L080E007C
.L080DEB80:
	cmp r3, #0
	bne .L080DEB88
	bl .L080E007C
.L080DEB88:
	cmp r1, #0
	bne .L080DEBA0
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	adds r1, r5, #0
	bl func_08050E30
	b .L080DEBAC
	.align 2, 0
.L080DEB9C: .4byte gText_Fallback_Error
.L080DEBA0:
	str r1, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	adds r1, r5, #0
	bl func_08050E30
.L080DEBAC:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DEBB8:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq .L080DEBD6
	subs r0, r1, #1
	str r0, [r2]
.L080DEBD6:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r1, #0
	beq .L080DEBEA
	subs r0, r1, #1
	str r0, [r2]
.L080DEBEA:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DEBFC
	subs r0, r1, #1
	str r0, [r2]
.L080DEBFC:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DEC0E
	subs r0, r1, #1
	str r0, [r2]
.L080DEC0E:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DEC20
	subs r0, r1, #1
	str r0, [r2]
.L080DEC20:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DEC3A
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r6, r1, r0
	b .L080DEC3C
.L080DEC3A:
	ldr r6, .L080DEC50 @ =gText_Fallback_Error
.L080DEC3C:
	ldr r0, [r4, #0x10]
	cmp r5, r0
	bhi .L080DEC54
	ldr r1, [r4, #0x14]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DEC56
	.align 2, 0
.L080DEC50: .4byte gText_Fallback_Error
.L080DEC54:
	ldr r2, .L080DEC6C @ =gText_Fallback_Error
.L080DEC56:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DEC70
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DEC72
	.align 2, 0
.L080DEC6C: .4byte gText_Fallback_Error
.L080DEC70:
	ldr r3, .L080DEC88 @ =gText_Fallback_Error
.L080DEC72:
	ldr r0, [r4, #0x10]
	cmp sb, r0
	bhi .L080DEC8C
	ldr r1, [r4, #0x14]
	mov r7, sb
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DEC8E
	.align 2, 0
.L080DEC88: .4byte gText_Fallback_Error
.L080DEC8C:
	ldr r5, .L080DECA4 @ =gText_Fallback_Error
.L080DEC8E:
	ldr r0, [r4, #0x10]
	cmp sl, r0
	bhi .L080DECA8
	ldr r1, [r4, #0x14]
	mov r7, sl
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DECAA
	.align 2, 0
.L080DECA4: .4byte gText_Fallback_Error
.L080DECA8:
	ldr r1, .L080DECD8 @ =gText_Fallback_Error
.L080DECAA:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne .L080DECBA
	bl .L080E007C
.L080DECBA:
	cmp r2, #0
	bne .L080DECC2
	bl .L080E007C
.L080DECC2:
	cmp r3, #0
	bne .L080DECCA
	bl .L080E007C
.L080DECCA:
	cmp r5, #0
	bne .L080DECDC
	str r5, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	b .L080DECE6
	.align 2, 0
.L080DECD8: .4byte gText_Fallback_Error
.L080DECDC:
	cmp r1, #0
	bne .L080DECF0
	str r5, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
.L080DECE6:
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_08050E30
	b .L080DED00
.L080DECF0:
	str r5, [sp]
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_08050E30
.L080DED00:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DED0C:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DED28
	subs r0, r1, #1
	str r0, [r2]
.L080DED28:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DED3A
	subs r0, r1, #1
	str r0, [r2]
.L080DED3A:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DED54
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DED56
.L080DED54:
	ldr r3, .L080DED6C @ =gText_Fallback_Error
.L080DED56:
	ldr r0, [r4, #0x10]
	cmp r5, r0
	bhi .L080DED70
	ldr r1, [r4, #0x14]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DED72
	.align 2, 0
.L080DED6C: .4byte gText_Fallback_Error
.L080DED70:
	ldr r2, .L080DEDB0 @ =gText_Fallback_Error
.L080DED72:
	movs r1, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DED84
	bl .L080E007C
.L080DED84:
	cmp r3, #0
	bne .L080DED8C
	bl .L080E007C
.L080DED8C:
	cmp r2, #0
	bne .L080DED94
	bl .L080E007C
.L080DED94:
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0
	bl func_08050E0C
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
	.align 2, 0
.L080DEDB0: .4byte gText_Fallback_Error
.L080DEDB4:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DEDD0
	subs r0, r1, #1
	str r0, [r2]
.L080DEDD0:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DEDE2
	subs r0, r1, #1
	str r0, [r2]
.L080DEDE2:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DEDF4
	subs r0, r1, #1
	str r0, [r2]
.L080DEDF4:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DEE0E
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DEE10
.L080DEE0E:
	ldr r5, .L080DEE24 @ =gText_Fallback_Error
.L080DEE10:
	ldr r0, [r4, #0x10]
	cmp r6, r0
	bhi .L080DEE28
	ldr r1, [r4, #0x14]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DEE2A
	.align 2, 0
.L080DEE24: .4byte gText_Fallback_Error
.L080DEE28:
	ldr r2, .L080DEE40 @ =gText_Fallback_Error
.L080DEE2A:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DEE44
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DEE46
	.align 2, 0
.L080DEE40: .4byte gText_Fallback_Error
.L080DEE44:
	ldr r3, .L080DEE80 @ =gText_Fallback_Error
.L080DEE46:
	movs r1, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DEE58
	bl .L080E007C
.L080DEE58:
	cmp r5, #0
	bne .L080DEE60
	bl .L080E007C
.L080DEE60:
	cmp r2, #0
	bne .L080DEE68
	bl .L080E007C
.L080DEE68:
	cmp r3, #0
	bne .L080DEE84
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r1, r5, #0
	movs r3, #0
	bl func_08050E0C
	b .L080DEE92
	.align 2, 0
.L080DEE80: .4byte gText_Fallback_Error
.L080DEE84:
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r5, #0
	bl func_08050E0C
.L080DEE92:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DEE9E:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r1, #0
	beq .L080DEEBC
	subs r0, r1, #1
	str r0, [r2]
.L080DEEBC:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DEECE
	subs r0, r1, #1
	str r0, [r2]
.L080DEECE:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DEEE0
	subs r0, r1, #1
	str r0, [r2]
.L080DEEE0:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DEEF2
	subs r0, r1, #1
	str r0, [r2]
.L080DEEF2:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DEF0C
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DEF0E
.L080DEF0C:
	ldr r5, .L080DEF24 @ =gText_Fallback_Error
.L080DEF0E:
	ldr r0, [r4, #0x10]
	cmp r6, r0
	bhi .L080DEF28
	ldr r1, [r4, #0x14]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DEF2A
	.align 2, 0
.L080DEF24: .4byte gText_Fallback_Error
.L080DEF28:
	ldr r2, .L080DEF40 @ =gText_Fallback_Error
.L080DEF2A:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DEF44
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DEF46
	.align 2, 0
.L080DEF40: .4byte gText_Fallback_Error
.L080DEF44:
	ldr r3, .L080DEF5C @ =gText_Fallback_Error
.L080DEF46:
	ldr r0, [r4, #0x10]
	cmp sb, r0
	bhi .L080DEF60
	ldr r1, [r4, #0x14]
	mov r6, sb
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DEF62
	.align 2, 0
.L080DEF5C: .4byte gText_Fallback_Error
.L080DEF60:
	ldr r1, .L080DEF9C @ =gText_Fallback_Error
.L080DEF62:
	movs r4, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DEF74
	bl .L080E007C
.L080DEF74:
	cmp r5, #0
	bne .L080DEF7C
	bl .L080E007C
.L080DEF7C:
	cmp r2, #0
	bne .L080DEF84
	bl .L080E007C
.L080DEF84:
	cmp r3, #0
	bne .L080DEFA0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r1, r5, #0
	movs r3, #0
	bl func_08050E0C
	b .L080DEFC2
	.align 2, 0
.L080DEF9C: .4byte gText_Fallback_Error
.L080DEFA0:
	cmp r1, #0
	bne .L080DEFB4
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r5, #0
	bl func_08050E0C
	b .L080DEFC2
.L080DEFB4:
	str r1, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r5, #0
	bl func_08050E0C
.L080DEFC2:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DEFCE:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq .L080DEFEC
	subs r0, r1, #1
	str r0, [r2]
.L080DEFEC:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r1, #0
	beq .L080DF000
	subs r0, r1, #1
	str r0, [r2]
.L080DF000:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DF012
	subs r0, r1, #1
	str r0, [r2]
.L080DF012:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DF024
	subs r0, r1, #1
	str r0, [r2]
.L080DF024:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF036
	subs r0, r1, #1
	str r0, [r2]
.L080DF036:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DF050
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r6, r1, r0
	b .L080DF052
.L080DF050:
	ldr r6, .L080DF068 @ =gText_Fallback_Error
.L080DF052:
	ldr r0, [r4, #0x10]
	cmp r5, r0
	bhi .L080DF06C
	ldr r1, [r4, #0x14]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DF06E
	.align 2, 0
.L080DF068: .4byte gText_Fallback_Error
.L080DF06C:
	ldr r2, .L080DF084 @ =gText_Fallback_Error
.L080DF06E:
	ldr r0, [r4, #0x10]
	cmp r7, r0
	bhi .L080DF088
	ldr r1, [r4, #0x14]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DF08A
	.align 2, 0
.L080DF084: .4byte gText_Fallback_Error
.L080DF088:
	ldr r3, .L080DF0A0 @ =gText_Fallback_Error
.L080DF08A:
	ldr r0, [r4, #0x10]
	cmp sb, r0
	bhi .L080DF0A4
	ldr r1, [r4, #0x14]
	mov r7, sb
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DF0A6
	.align 2, 0
.L080DF0A0: .4byte gText_Fallback_Error
.L080DF0A4:
	ldr r5, .L080DF0BC @ =gText_Fallback_Error
.L080DF0A6:
	ldr r0, [r4, #0x10]
	cmp sl, r0
	bhi .L080DF0C0
	ldr r1, [r4, #0x14]
	mov r7, sl
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DF0C2
	.align 2, 0
.L080DF0BC: .4byte gText_Fallback_Error
.L080DF0C0:
	ldr r1, .L080DF0FC @ =gText_Fallback_Error
.L080DF0C2:
	movs r4, #0
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080DF0D4
	bl .L080E007C
.L080DF0D4:
	cmp r6, #0
	bne .L080DF0DC
	bl .L080E007C
.L080DF0DC:
	cmp r2, #0
	bne .L080DF0E4
	bl .L080E007C
.L080DF0E4:
	cmp r3, #0
	bne .L080DF100
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r3, #0
	bl func_08050E0C
	b .L080DF12A
	.align 2, 0
.L080DF0FC: .4byte gText_Fallback_Error
.L080DF100:
	cmp r5, #0
	bne .L080DF108
	str r4, [sp]
	b .L080DF10E
.L080DF108:
	cmp r1, #0
	bne .L080DF11C
	str r5, [sp]
.L080DF10E:
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r6, #0
	bl func_08050E0C
	b .L080DF12A
.L080DF11C:
	str r5, [sp]
	str r1, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r6, #0
	bl func_08050E0C
.L080DF12A:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DF136:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov ip, r0
	cmp r1, #0
	beq .L080DF154
	subs r0, r1, #1
	str r0, [r2]
.L080DF154:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq .L080DF168
	subs r0, r1, #1
	str r0, [r2]
.L080DF168:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r1, #0
	beq .L080DF17C
	subs r0, r1, #1
	str r0, [r2]
.L080DF17C:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DF18E
	subs r0, r1, #1
	str r0, [r2]
.L080DF18E:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DF1A0
	subs r0, r1, #1
	str r0, [r2]
.L080DF1A0:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF1B2
	subs r0, r1, #1
	str r0, [r2]
.L080DF1B2:
	mov r0, r8
	adds r0, #0xc
	ldr r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r3, r1
	bhi .L080DF1CC
	ldr r1, [r4, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r7, r1, r0
	b .L080DF1CE
.L080DF1CC:
	ldr r7, .L080DF1E4 @ =gText_Fallback_Error
.L080DF1CE:
	ldr r0, [r4, #0x10]
	cmp r5, r0
	bhi .L080DF1E8
	ldr r1, [r4, #0x14]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r2, r1, r0
	b .L080DF1EA
	.align 2, 0
.L080DF1E4: .4byte gText_Fallback_Error
.L080DF1E8:
	ldr r2, .L080DF200 @ =gText_Fallback_Error
.L080DF1EA:
	ldr r0, [r4, #0x10]
	cmp r6, r0
	bhi .L080DF204
	ldr r1, [r4, #0x14]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r3, r1, r0
	b .L080DF206
	.align 2, 0
.L080DF200: .4byte gText_Fallback_Error
.L080DF204:
	ldr r3, .L080DF21C @ =gText_Fallback_Error
.L080DF206:
	ldr r0, [r4, #0x10]
	cmp sb, r0
	bhi .L080DF220
	ldr r1, [r4, #0x14]
	mov r5, sb
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r6, r1, r0
	b .L080DF222
	.align 2, 0
.L080DF21C: .4byte gText_Fallback_Error
.L080DF220:
	ldr r6, .L080DF238 @ =gText_Fallback_Error
.L080DF222:
	ldr r0, [r4, #0x10]
	cmp sl, r0
	bhi .L080DF23C
	ldr r1, [r4, #0x14]
	mov r5, sl
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r5, r1, r0
	b .L080DF23E
	.align 2, 0
.L080DF238: .4byte gText_Fallback_Error
.L080DF23C:
	ldr r5, .L080DF258 @ =gText_Fallback_Error
.L080DF23E:
	ldr r0, [r4, #0x10]
	cmp ip, r0
	bhi .L080DF25C
	ldr r0, [r4, #0x14]
	mov sb, r0
	mov r1, ip
	lsls r0, r1, #2
	add r0, sb
	ldr r1, [r4, #0x18]
	ldr r0, [r0]
	adds r1, r1, r0
	b .L080DF25E
	.align 2, 0
.L080DF258: .4byte gText_Fallback_Error
.L080DF25C:
	ldr r1, .L080DF298 @ =gText_Fallback_Error
.L080DF25E:
	movs r0, #0xdb
	lsls r0, r0, #2
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne .L080DF26E
	bl .L080E007C
.L080DF26E:
	cmp r7, #0
	bne .L080DF276
	bl .L080E007C
.L080DF276:
	cmp r2, #0
	bne .L080DF27E
	bl .L080E007C
.L080DF27E:
	cmp r3, #0
	bne .L080DF29C
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #0
	bl func_08050E0C
	b .L080DF2E0
	.align 2, 0
.L080DF298: .4byte gText_Fallback_Error
.L080DF29C:
	cmp r6, #0
	bne .L080DF2AA
	str r6, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	b .L080DF2C4
.L080DF2AA:
	cmp r5, #0
	bne .L080DF2B8
	str r6, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	b .L080DF2C4
.L080DF2B8:
	cmp r1, #0
	bne .L080DF2CE
	str r6, [sp]
	str r5, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
.L080DF2C4:
	adds r0, r4, #0
	adds r1, r7, #0
	bl func_08050E0C
	b .L080DF2E0
.L080DF2CE:
	str r6, [sp]
	str r5, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	bl func_08050E0C
.L080DF2E0:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #7
	bl .L080E007A
.L080DF2EC:
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r0, [r2]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #0x2c]
	movs r0, #0xe6
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	beq .L080DF30C
	subs r0, #1
	str r0, [r2]
.L080DF30C:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #8
	bl .L080E007A
.L080DF318:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r1, #0
	beq .L080DF334
	subs r0, r1, #1
	str r0, [r2]
.L080DF334:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF346
	subs r0, r1, #1
	str r0, [r2]
.L080DF346:
	cmp r3, #4
	bls .L080DF34E
	bl .L080E007C
.L080DF34E:
	lsls r0, r3, #2
	ldr r1, .L080DF358 @ =.L080DF35C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080DF358: .4byte .L080DF35C
.L080DF35C: @ jump table
	.4byte .L080DF370 @ case 0
	.4byte .L080DF376 @ case 1
	.4byte .L080DF37C @ case 2
	.4byte .L080DF380 @ case 3
	.4byte .L080DF384 @ case 4
.L080DF370:
	movs r5, #2
	movs r3, #0
	b .L080DF388
.L080DF376:
	movs r5, #1
	movs r3, #0
	b .L080DF388
.L080DF37C:
	movs r5, #2
	b .L080DF386
.L080DF380:
	movs r5, #1
	b .L080DF386
.L080DF384:
	movs r5, #0
.L080DF386:
	movs r3, #1
.L080DF388:
	cmp r4, #1
	beq .L080DF3A8
	cmp r4, #1
	bgt .L080DF398
	cmp r4, #0
	beq .L080DF3A0
	bl .L080E007C
.L080DF398:
	cmp r4, #2
	beq .L080DF3B0
	bl .L080E007C
.L080DF3A0:
	ldr r1, .L080DF3A4 @ =0x00001112
	b .L080DF3B2
	.align 2, 0
.L080DF3A4: .4byte 0x00001112
.L080DF3A8:
	ldr r1, .L080DF3AC @ =0x00000889
	b .L080DF3B2
	.align 2, 0
.L080DF3AC: .4byte 0x00000889
.L080DF3B0:
	ldr r1, .L080DF3E8 @ =0x00000444
.L080DF3B2:
	movs r0, #0xdc
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	adds r2, r5, #0
	bl EndHardwareBlend
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #5
	str r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r1, #0
	cmp r5, #2
	bne .L080DF3DC
	movs r1, #1
.L080DF3DC:
	ldr r0, .L080DF3EC @ =0x000003A1
	add r0, r8
	strb r1, [r0]
	bl .L080E007C
	.align 2, 0
.L080DF3E8: .4byte 0x00000444
.L080DF3EC: .4byte 0x000003A1
.L080DF3F0:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r1, #0
	beq .L080DF40C
	subs r0, r1, #1
	str r0, [r2]
.L080DF40C:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF41E
	subs r0, r1, #1
	str r0, [r2]
.L080DF41E:
	cmp r3, #4
	bls .L080DF426
	bl .L080E007C
.L080DF426:
	lsls r0, r3, #2
	ldr r1, .L080DF430 @ =.L080DF434
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080DF430: .4byte .L080DF434
.L080DF434: @ jump table
	.4byte .L080DF448 @ case 0
	.4byte .L080DF44E @ case 1
	.4byte .L080DF454 @ case 2
	.4byte .L080DF458 @ case 3
	.4byte .L080DF45C @ case 4
.L080DF448:
	movs r6, #2
	movs r3, #0
	b .L080DF460
.L080DF44E:
	movs r6, #1
	movs r3, #0
	b .L080DF460
.L080DF454:
	movs r6, #2
	b .L080DF45E
.L080DF458:
	movs r6, #1
	b .L080DF45E
.L080DF45C:
	movs r6, #0
.L080DF45E:
	movs r3, #1
.L080DF460:
	cmp r4, #1
	beq .L080DF480
	cmp r4, #1
	bgt .L080DF470
	cmp r4, #0
	beq .L080DF478
	bl .L080E007C
.L080DF470:
	cmp r4, #2
	beq .L080DF488
	bl .L080E007C
.L080DF478:
	ldr r1, .L080DF47C @ =0x00001112
	b .L080DF48A
	.align 2, 0
.L080DF47C: .4byte 0x00001112
.L080DF480:
	ldr r1, .L080DF484 @ =0x00000889
	b .L080DF48A
	.align 2, 0
.L080DF484: .4byte 0x00000889
.L080DF488:
	ldr r1, .L080DF4F4 @ =0x00000444
.L080DF48A:
	movs r0, #0xdc
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	adds r2, r6, #0
	bl BeginHardwareBlend
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #6
	str r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r1, #0
	cmp r6, #2
	bne .L080DF4B4
	movs r1, #1
.L080DF4B4:
	ldr r0, .L080DF4F8 @ =0x000003A1
	add r0, r8
	strb r1, [r0]
	mov r5, r8
	adds r5, #4
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetHardwareDisplayState
	ldrh r0, [r0]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	cmp r6, #1
	bne .L080DF4FC
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r4, r0, #0
	adds r4, #0x50
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r0, #0x50
	ldrh r0, [r0]
	movs r1, #0x80
	b .L080DF512
	.align 2, 0
.L080DF4F4: .4byte 0x00000444
.L080DF4F8: .4byte 0x000003A1
.L080DF4FC:
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r4, r0, #0
	adds r4, #0x50
	adds r0, r5, #0
	bl GetHardwareDisplayState
	adds r0, #0x50
	ldrh r0, [r0]
	movs r1, #0xc0
.L080DF512:
	orrs r0, r1
	strh r0, [r4]
	bl .L080E007C
.L080DF51A:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	cmp r1, #0
	beq .L080DF538
	subs r0, r1, #1
	str r0, [r2]
.L080DF538:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r1, #0
	beq .L080DF54A
	subs r0, r1, #1
	str r0, [r2]
.L080DF54A:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF55C
	subs r0, r1, #1
	str r0, [r2]
.L080DF55C:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r5, [r0]
	mov sl, r5
	movs r6, #0xb0
	add sl, r6
	add r6, sp, #0x10
	ldr r7, .L080DF5E0 @ =0x000003FF
	mov sb, r7
	mov r1, sb
	ands r3, r1
	ldrh r2, [r6]
	ldr r5, .L080DF5E4 @ =0xFFFFFC00
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r3
	strh r1, [r6]
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	movs r7, #0x3f
	mov ip, r7
	mov r1, ip
	ands r2, r1
	lsls r2, r2, #2
	ldrb r7, [r6, #1]
	mov r8, r7
	movs r3, #3
	adds r1, r3, #0
	mov r7, r8
	ands r1, r7
	orrs r1, r2
	strb r1, [r6, #1]
	lsrs r4, r4, #0x16
	mov r1, sb
	ands r4, r1
	ldrh r2, [r6, #2]
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r4
	strh r1, [r6, #2]
	ldr r4, [sp, #0x2c]
	lsls r2, r4, #0x10
	lsrs r1, r2, #0x10
	mov r7, ip
	ands r1, r7
	lsls r1, r1, #2
	ldrb r4, [r6, #3]
	ands r3, r4
	orrs r3, r1
	strb r3, [r6, #3]
	lsrs r2, r2, #0x16
	mov r1, sb
	ands r2, r1
	ldrh r1, [r6, #4]
	ands r5, r1
	orrs r5, r2
	strh r5, [r6, #4]
	mov r4, sl
	ldr r2, [r4]
	adds r1, r6, #0
	bl _call_via_r2
	bl .L080E0080
	.align 2, 0
.L080DF5E0: .4byte 0x000003FF
.L080DF5E4: .4byte 0xFFFFFC00
.L080DF5E8:
	mov r6, r8
	adds r6, #0x30
	movs r5, #0xe0
	lsls r5, r5, #1
	add r5, r8
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF604
	subs r0, r1, #1
	str r0, [r5]
.L080DF604:
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r2, [r0]
	cmp r1, #0
	beq .L080DF616
	subs r0, r1, #1
	str r0, [r5]
.L080DF616:
	ldr r4, [r5]
	lsls r0, r4, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r6, [r0]
	cmp r4, #0
	beq .L080DF628
	subs r0, r4, #1
	str r0, [r5]
.L080DF628:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r4, [r1, #0x24]
	bl sub_080DFE84
.L080DF638:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r1, [r1, #0x28]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DF652
	bl .L080E007C
.L080DF652:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0xa
	bl .L080E007A
.L080DF65E:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r1, #0
	beq .L080DF67A
	subs r0, r1, #1
	str r0, [r2]
.L080DF67A:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DF68C
	subs r0, r1, #1
	str r0, [r2]
.L080DF68C:
	lsls r0, r4, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0xdd
	lsls r0, r0, #2
	add r0, r8
	cmp r3, #1
	beq .L080DF738
	cmp r3, #1
	bgt .L080DF6A6
	cmp r3, #0
	beq .L080DF730
	bl .L080E0080
.L080DF6A6:
	cmp r3, #2
	beq .L080DF6AE
	bl .L080E0080
.L080DF6AE:
	b .L080DF740
.L080DF6B0:
	movs r0, #0xdd
	lsls r0, r0, #2
	add r0, r8
	bl Stop__23HardwareMusicPlayerSlot
	bl .L080E0080
.L080DF6BE:
	ldr r0, [r4]
	b .L080DF716
.L080DF6C2:
	mov r3, r8
	adds r3, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r7, [r0]
	cmp r1, #0
	beq .L080DF6DE
	subs r0, r1, #1
	str r0, [r2]
.L080DF6DE:
	ldr r1, [r2]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DF6F0
	subs r0, r1, #1
	str r0, [r2]
.L080DF6F0:
	movs r0, #0xe2
	lsls r0, r0, #2
	add r0, r8
	ldr r4, [r0]
	ldr r5, [r0, #4]
	lsls r7, r7, #0x10
	cmp r4, r5
	beq .L080DF712
.L080DF700:
	ldr r0, [r4]
	bl IsActive__C23HardwareMusicPlayerSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DF6BE
	adds r4, #4
	cmp r4, r5
	bne .L080DF700
.L080DF712:
	subs r0, r5, #4
	ldr r0, [r0]
.L080DF716:
	lsrs r1, r7, #0x10
	cmp r6, #1
	beq .L080DF738
	cmp r6, #1
	bgt .L080DF728
	cmp r6, #0
	beq .L080DF730
	bl .L080E0080
.L080DF728:
	cmp r6, #2
	beq .L080DF740
	bl .L080E0080
.L080DF730:
	bl Start__23HardwareMusicPlayerSlotUs
	bl .L080E0080
.L080DF738:
	bl StartIfChangedOrInactive__23HardwareMusicPlayerSlotUs
	bl .L080E0080
.L080DF740:
	bl StartOrContinue__23HardwareMusicPlayerSlotUs
	bl .L080E0080
.L080DF748:
	bl func_08008DE8
	bl .L080E0080
.L080DF750:
	mov r5, r8
	adds r5, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, #0x28]
	cmp r1, #0
	beq .L080DF76E
	subs r0, r1, #1
	str r0, [r3]
.L080DF76E:
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq .L080DF782
	subs r0, r1, #1
	str r0, [r3]
.L080DF782:
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r1, #0
	beq .L080DF794
	subs r0, r1, #1
	str r0, [r3]
.L080DF794:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r6, [r0]
	cmp r2, #0
	beq .L080DF7A6
	subs r0, r2, #1
	str r0, [r3]
.L080DF7A6:
	movs r5, #0xda
	lsls r5, r5, #2
	add r5, r8
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r6, #0
	bl _call_via_r2
	adds r7, r0, #0
	cmp r7, #0
	bne .L080DF7C2
	bl .L080E0080
.L080DF7C2:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	add r1, sp, #0x18
	ldr r5, .L080DF854 @ =0x000003FF
	mov r8, r5
	mov r6, r8
	ands r0, r6
	ldrh r3, [r1]
	ldr r5, .L080DF858 @ =0xFFFFFC00
	adds r2, r5, #0
	ands r2, r3
	orrs r2, r0
	strh r2, [r1]
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	movs r0, #0x3f
	mov sb, r0
	ands r2, r0
	lsls r2, r2, #2
	ldrb r6, [r1, #1]
	movs r3, #3
	adds r0, r3, #0
	ands r0, r6
	orrs r0, r2
	strb r0, [r1, #1]
	lsrs r4, r4, #0x16
	mov r2, r8
	ands r4, r2
	ldrh r2, [r1, #2]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r4
	strh r0, [r1, #2]
	mov r4, sl
	lsls r2, r4, #0x10
	lsrs r0, r2, #0x10
	mov r6, sb
	ands r0, r6
	lsls r0, r0, #2
	ldrb r4, [r1, #3]
	ands r3, r4
	orrs r3, r0
	strb r3, [r1, #3]
	lsrs r2, r2, #0x16
	mov r0, r8
	ands r2, r0
	ldrh r0, [r1, #4]
	ands r5, r0
	orrs r5, r2
	strh r5, [r1, #4]
	add r4, sp, #0x10
	adds r0, r4, #0
	movs r2, #6
	bl memcpy
	add r1, sp, #0x28
	ldrb r1, [r1]
	strb r1, [r4, #6]
	adds r0, r7, #0
	add r1, sp, #0x10
	bl SetLocation__12AActorEntityRC13ActorLocation
	ldr r0, [r7, #0x14]
	ldr r1, [r0, #0x20]
	adds r0, r7, #0
	bl _call_via_r1
	bl .L080E0080
	.align 2, 0
.L080DF854: .4byte 0x000003FF
.L080DF858: .4byte 0xFFFFFC00
.L080DF85C:
	mov r3, r8
	adds r3, #0x30
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r6, [r0]
	cmp r2, #0
	beq .L080DF878
	subs r0, r2, #1
	str r0, [r1]
.L080DF878:
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r5, [r0]
	cmp r2, #0
	beq .L080DF88A
	subs r0, r2, #1
	str r0, [r1]
.L080DF88A:
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r2, #0
	beq .L080DF89C
	subs r0, r2, #1
	str r0, [r1]
.L080DF89C:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	adds r4, r0, #0
	cmp r4, #0
	bne .L080DF8B6
	b .L080E0080
.L080DF8B6:
	adds r1, r5, #0
	bl SetActorAuxRenderProfile
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_080323F0
	b .L080E0080
.L080DF8C6:
	mov r0, r8
	adds r0, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r3, [r2]
	lsls r1, r3, #2
	subs r1, #4
	adds r1, r0, r1
	ldr r6, [r1]
	adds r5, r0, #0
	adds r4, r2, #0
	cmp r3, #0
	beq .L080DF8E6
	subs r0, r3, #1
	str r0, [r4]
.L080DF8E6:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r6, #0
	bl _call_via_r2
	movs r1, #0
	cmp r0, #0
	beq .L080DF900
	ldr r1, [r0, #8]
.L080DF900:
	asrs r2, r1, #0x10
	b .L080DF9DA
.L080DF904:
	mov r0, r8
	adds r0, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r3, [r2]
	lsls r1, r3, #2
	subs r1, #4
	adds r1, r0, r1
	ldr r6, [r1]
	adds r5, r0, #0
	adds r4, r2, #0
	cmp r3, #0
	beq .L080DF924
	subs r0, r3, #1
	str r0, [r4]
.L080DF924:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r6, #0
	bl _call_via_r2
	movs r1, #0
	cmp r0, #0
	beq .L080DF900
	ldr r1, [r0, #0xc]
	b .L080DF900
.L080DF940:
	mov r3, r8
	adds r3, #0x30
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DF95C
	subs r0, r2, #1
	str r0, [r1]
.L080DF95C:
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r2, #0
	beq .L080DF96E
	subs r0, r2, #1
	str r0, [r1]
.L080DF96E:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	adds r1, r0, #0
	cmp r1, #0
	bne .L080DF988
	b .L080E0080
.L080DF988:
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r4
	bne .L080DF992
	b .L080E0080
.L080DF992:
	adds r0, r1, #0
	adds r1, r4, #0
	bl SetAnimFacing__12AActorEntityUi
	b .L080E0080
.L080DF99C:
	mov r0, r8
	adds r0, #0x30
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, r8
	ldr r3, [r2]
	lsls r1, r3, #2
	subs r1, #4
	adds r1, r0, r1
	ldr r6, [r1]
	adds r5, r0, #0
	adds r4, r2, #0
	cmp r3, #0
	beq .L080DF9BC
	subs r0, r3, #1
	str r0, [r4]
.L080DF9BC:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r6, #0
	bl _call_via_r2
	cmp r0, #0
	beq .L080DF9D8
	adds r0, #0x20
	ldrb r2, [r0]
	b .L080DF9DA
.L080DF9D8:
	movs r2, #0
.L080DF9DA:
	ldr r1, [r4]
	cmp r1, #0x63
	bls .L080DF9E2
	b .L080E0080
.L080DF9E2:
	lsls r0, r1, #2
	adds r0, r5, r0
	str r2, [r0]
	adds r0, r1, #1
	str r0, [r4]
	b .L080E0080
.L080DF9EE:
	mov r4, r8
	adds r4, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DFA0A
	subs r0, r1, #1
	str r0, [r3]
.L080DFA0A:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r5, [r0]
	cmp r2, #0
	beq .L080DFA1C
	subs r0, r2, #1
	str r0, [r3]
.L080DFA1C:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFA2E
	subs r0, r2, #1
	str r0, [r3]
.L080DFA2E:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFA46
	b .L080E0080
.L080DFA46:
	lsls r2, r6, #0x10
	adds r1, r5, #0
	bl StartActorXMotion
	b .L080E0080
.L080DFA50:
	mov r4, r8
	adds r4, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DFA6C
	subs r0, r1, #1
	str r0, [r3]
.L080DFA6C:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r5, [r0]
	cmp r2, #0
	beq .L080DFA7E
	subs r0, r2, #1
	str r0, [r3]
.L080DFA7E:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFA90
	subs r0, r2, #1
	str r0, [r3]
.L080DFA90:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFAA8
	b .L080E0080
.L080DFAA8:
	lsls r2, r6, #0x10
	adds r1, r5, #0
	bl StartActorYMotion
	b .L080E0080
.L080DFAB2:
	mov r4, r8
	adds r4, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DFACE
	subs r0, r1, #1
	str r0, [r3]
.L080DFACE:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r5, [r0]
	cmp r2, #0
	beq .L080DFAE0
	subs r0, r2, #1
	str r0, [r3]
.L080DFAE0:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFAF2
	subs r0, r2, #1
	str r0, [r3]
.L080DFAF2:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFB0A
	b .L080E0080
.L080DFB0A:
	adds r1, r5, #0
	adds r2, r6, #0
	bl StartActorXMotion
	b .L080E0080
.L080DFB14:
	mov r4, r8
	adds r4, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r6, [r0]
	cmp r1, #0
	beq .L080DFB30
	subs r0, r1, #1
	str r0, [r3]
.L080DFB30:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r5, [r0]
	cmp r2, #0
	beq .L080DFB42
	subs r0, r2, #1
	str r0, [r3]
.L080DFB42:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFB54
	subs r0, r2, #1
	str r0, [r3]
.L080DFB54:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFB6C
	b .L080E0080
.L080DFB6C:
	adds r1, r5, #0
	adds r2, r6, #0
	bl StartActorYMotion
	b .L080E0080
.L080DFB76:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFB8C
	subs r0, r2, #1
	str r0, [r1]
.L080DFB8C:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	movs r1, #0xe7
	lsls r1, r1, #2
	add r1, r8
	str r0, [r1]
	cmp r0, #0
	bne .L080DFBAC
	b .L080E007C
.L080DFBAC:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #9
	b .L080E007A
.L080DFBB6:
	mov r3, r8
	adds r3, #0x30
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFBD2
	subs r0, r2, #1
	str r0, [r1]
.L080DFBD2:
	ldr r2, [r1]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r3, r0
	ldr r3, [r0]
	cmp r2, #0
	beq .L080DFBE4
	subs r0, r2, #1
	str r0, [r1]
.L080DFBE4:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	adds r1, r0, #0
	cmp r1, #0
	bne .L080DFBFE
	b .L080E0080
.L080DFBFE:
	ldrh r0, [r1, #0x22]
	cmp r0, r4
	bne .L080DFC06
	b .L080E0080
.L080DFC06:
	adds r0, r1, #0
	adds r1, r4, #0
	bl SetAnim__12AActorEntityUi
	b .L080E0080
.L080DFC10:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r0, [r1]
	cmp r0, #0
	bne .L080DFC1E
	b .L080E0080
.L080DFC1E:
	subs r0, #1
	str r0, [r1]
	b .L080E0080
.L080DFC24:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFC3A
	subs r0, r2, #1
	str r0, [r1]
.L080DFC3A:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFC52
	b .L080E0080
.L080DFC52:
	movs r1, #0x8d
	lsls r1, r1, #2
	bl SetMap__7AEntityUi
	b .L080E0080
.L080DFC5C:
	mov r4, r8
	adds r4, #0x30
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r1, [r3]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r5, [r0]
	cmp r1, #0
	beq .L080DFC78
	subs r0, r1, #1
	str r0, [r3]
.L080DFC78:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r6, [r0]
	cmp r2, #0
	beq .L080DFC8A
	subs r0, r2, #1
	str r0, [r3]
.L080DFC8A:
	ldr r2, [r3]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r4, r0
	ldr r4, [r0]
	cmp r2, #0
	beq .L080DFC9C
	subs r0, r2, #1
	str r0, [r3]
.L080DFC9C:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFCB4
	b .L080E0080
.L080DFCB4:
	rsbs r2, r5, #0
	orrs r2, r5
	lsrs r2, r2, #0x1f
	adds r1, r6, #0
	bl StartActorSpriteEffect
	b .L080E0080
.L080DFCC2:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFCD8
	subs r0, r2, #1
	str r0, [r1]
.L080DFCD8:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	adds r1, r3, #0
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFCF0
	b .L080E0080
.L080DFCF0:
	bl StopActorSpriteEffect
	b .L080E0080
.L080DFCF6:
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r2, [r3]
	lsls r0, r2, #2
	add r0, r8
	ldr r1, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFD0C
	subs r0, r2, #1
	str r0, [r3]
.L080DFD0C:
	mov r0, r8
	adds r0, #0xc
	ldr r2, .L080DFD20 @ =gMaryScriptTable
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl Load__13AScriptEnginePCv
	b .L080E0080
	.align 2, 0
.L080DFD20: .4byte gMaryScriptTable
.L080DFD24:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0x80
	ldr r1, [r1]
	bl _call_via_r1
	b .L080E0080
.L080DFD38:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFD4E
	subs r0, r2, #1
	str r0, [r1]
.L080DFD4E:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0x9c
	b .L080DFDA2
.L080DFD5C:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFD72
	subs r0, r2, #1
	str r0, [r1]
.L080DFD72:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0xa0
	b .L080DFDA2
.L080DFD80:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r3, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFD96
	subs r0, r2, #1
	str r0, [r1]
.L080DFD96:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0xac
.L080DFDA2:
	ldr r2, [r1]
	adds r1, r3, #0
	bl _call_via_r2
	b .L080E0080
.L080DFDAC:
	mov r6, r8
	adds r6, #0x30
	movs r5, #0xe0
	lsls r5, r5, #1
	add r5, r8
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DFDC8
	subs r0, r1, #1
	str r0, [r5]
.L080DFDC8:
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r2, [r0]
	cmp r1, #0
	beq .L080DFDDA
	subs r0, r1, #1
	str r0, [r5]
.L080DFDDA:
	ldr r4, [r5]
	lsls r0, r4, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r1, [r0]
	cmp r4, #0
	beq .L080DFDEC
	subs r0, r4, #1
	str r0, [r5]
.L080DFDEC:
	ldr r4, [r5]
	lsls r0, r4, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r0, [r0]
	mov sb, r0
	cmp r4, #0
	beq .L080DFE00
	subs r0, r4, #1
	str r0, [r5]
.L080DFE00:
	ldr r4, [r5]
	lsls r0, r4, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r7, [r0]
	cmp r4, #0
	beq .L080DFE12
	subs r0, r4, #1
	str r0, [r5]
.L080DFE12:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r5, [r0]
	ldr r4, [r5]
	adds r4, #0xb4
	add r6, sp, #0x20
	adds r0, r6, #0
	bl __9FieldPlotUiUiUi
	ldr r4, [r4]
	adds r0, r5, #0
	adds r1, r7, #0
	mov r2, sb
	adds r3, r6, #0
	bl _call_via_r4
	b .L080E0080
.L080DFE36:
	mov r6, r8
	adds r6, #0x30
	movs r5, #0xe0
	lsls r5, r5, #1
	add r5, r8
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r3, [r0]
	cmp r1, #0
	beq .L080DFE52
	subs r0, r1, #1
	str r0, [r5]
.L080DFE52:
	ldr r1, [r5]
	lsls r0, r1, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r2, [r0]
	cmp r1, #0
	beq .L080DFE64
	subs r0, r1, #1
	str r0, [r5]
.L080DFE64:
	ldr r4, [r5]
	lsls r0, r4, #2
	subs r0, #4
	adds r0, r6, r0
	ldr r6, [r0]
	cmp r4, #0
	beq .L080DFE76
	subs r0, r4, #1
	str r0, [r5]
.L080DFE76:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	adds r1, #0xb8
	ldr r4, [r1]

	thumb_func_start sub_080DFE84
sub_080DFE84: @ 0x080DFE84
	adds r1, r6, #0
	bl _call_via_r4
	b .L080E0080
.L080DFE8C:
	mov r5, r8
	adds r5, #0x30
	movs r4, #0xe0
	lsls r4, r4, #1
	add r4, r8
	ldr r2, [r4]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r1, [r0]
	cmp r2, #0
	beq .L080DFEA8
	subs r0, r2, #1
	str r0, [r4]
.L080DFEA8:
	ldr r2, [r4]
	lsls r0, r2, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r7, [r0]
	cmp r2, #0
	beq .L080DFEBA
	subs r0, r2, #1
	str r0, [r4]
.L080DFEBA:
	ldr r3, [r4]
	lsls r0, r3, #2
	subs r0, #4
	adds r0, r5, r0
	ldr r6, [r0]
	cmp r3, #0
	beq .L080DFECC
	subs r0, r3, #1
	str r0, [r4]
.L080DFECC:
	movs r5, #0xda
	lsls r5, r5, #2
	add r5, r8
	ldr r0, [r5]
	ldr r2, [r0]
	adds r1, #0x62
	ldr r2, [r2, #0x40]
	bl _call_via_r2
	adds r4, r0, #0
	cmp r4, #0
	bne .L080DFEE6
	b .L080E0080
.L080DFEE6:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	bl _call_via_r1
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl SetLocation__7AEntityUiii
	b .L080E0080
.L080DFEFE:
	movs r3, #0xe0
	lsls r3, r3, #1
	add r3, r8
	ldr r2, [r3]
	lsls r0, r2, #2
	add r0, r8
	ldr r1, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFF14
	subs r0, r2, #1
	str r0, [r3]
.L080DFF14:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r2, [r0]
	adds r1, #0x62
	ldr r2, [r2, #0x40]
	bl _call_via_r2
	cmp r0, #0
	bne .L080DFF2C
	b .L080E0080
.L080DFF2C:
	movs r1, #0x8d
	lsls r1, r1, #2
	movs r2, #0
	movs r3, #0
	bl SetLocation__7AEntityUiii
	b .L080E0080
.L080DFF3A:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r4, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFF50
	subs r0, r2, #1
	str r0, [r1]
.L080DFF50:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	ldr r1, [r0, #0x14]
	ldr r2, [r1, #0x40]
	adds r1, r4, #0
	bl _call_via_r2
	b .L080E0072
.L080DFF6E:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r6, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFF84
	subs r0, r2, #1
	str r0, [r1]
.L080DFF84:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	adds r4, r0, #0
	ldr r5, [r4, #0x14]
	add r0, sp, #0x10
	adds r1, r6, #0
	bl __4FoodUi
	add r0, sp, #0x10
	bl GetIconId__C4Food
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r5, #0x44]
	adds r0, r4, #0
	movs r2, #0
	bl _call_via_r3
	b .L080E0072
.L080DFFBA:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r4, [r0, #0x2c]
	cmp r2, #0
	beq .L080DFFD0
	subs r0, r2, #1
	str r0, [r1]
.L080DFFD0:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	ldr r2, [r0, #0x14]
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x44]
	movs r2, #1
	bl _call_via_r3
	b .L080E0072
.L080DFFF2:
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, r8
	ldr r2, [r1]
	lsls r0, r2, #2
	add r0, r8
	ldr r7, [r0, #0x2c]
	cmp r2, #0
	beq .L080E0008
	subs r0, r2, #1
	str r0, [r1]
.L080E0008:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	adds r5, r0, #0
	ldr r6, [r5, #0x14]
	add r4, sp, #0x24
	adds r0, r4, #0
	adds r1, r7, #0
	bl __7ArticleUi
	adds r0, r4, #0
	bl GetIconId__C7Article
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r6, #0x44]
	adds r0, r5, #0
	movs r2, #0
	bl _call_via_r3
	b .L080E0072
.L080E0040:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	ldr r1, [r0, #0x14]
	ldr r1, [r1, #0x4c]
	b .L080E006E
.L080E0058:
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	ldr r1, [r0, #0x14]
	ldr r1, [r1, #0x48]
.L080E006E:
	bl _call_via_r1
.L080E0072:
	movs r1, #0xd9
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0xb
.L080E007A:
	str r0, [r1]
.L080E007C:
	movs r0, #1
	b .L080E0082
.L080E0080:
	movs r0, #0
.L080E0082:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Run__20FarmingTutorialScene
Run__20FarmingTutorialScene: @ 0x080E0094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xac
	str r0, [sp, #0x7c]
	adds r7, r1, #0
	adds r6, r7, #4
	adds r0, r6, #0
	bl EnableHardwareForcedBlank
	adds r0, r6, #0
	bl GetHardwareDisplayState
	add r2, sp, #0xc
	movs r3, #0x82
	lsls r3, r3, #5
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	adds r0, r6, #0
	bl GetHardwareDisplayState
	add r1, sp, #0xc
	movs r2, #0x3f
	strh r2, [r1]
	adds r0, #0x50
	strh r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r7, r0
	str r1, [sp, #0x38]
	mov r2, sp
	adds r2, #0x38
	str r2, [sp, #0x80]
	ldr r4, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r4, r0
	beq .L080E011C
	cmp r4, #0
	beq .L080E00F0
	str r1, [r4]
.L080E00F0:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	mov sl, r6
	add r3, sp, #0x44
	mov r8, r3
	mov r4, sp
	adds r4, #0x50
	str r4, [sp, #0x9c]
	mov r5, sp
	adds r5, #0x5c
	str r5, [sp, #0xa0]
	adds r0, r7, #0
	adds r0, #0xc
	str r0, [sp, #0x98]
	mov r1, sp
	adds r1, #0x10
	str r1, [sp, #0x94]
	mov r2, sp
	adds r2, #0x68
	str r2, [sp, #0xa4]
	b .L080E01BC
.L080E011C:
	mov r8, r4
	movs r0, #1
	str r0, [sp, #0x40]
	ldr r0, [r5]
	subs r0, r4, r0
	asrs r4, r0, #2
	str r4, [sp, #0x3c]
	add r1, sp, #0x40
	add r0, sp, #0x3c
	cmp r4, #1
	bhs .L080E0134
	adds r0, r1, #0
.L080E0134:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080E0152
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080E0156
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080E0156
.L080E0152:
	movs r0, #0
	mov sb, r0
.L080E0156:
	adds r6, r0, #0
	ldr r1, [r5]
	cmp r8, r1
	beq .L080E016C
	mov r3, r8
	subs r4, r3, r1
	adds r2, r4, #0
	bl memmove
	adds r0, r0, r4
	b .L080E016E
.L080E016C:
	adds r0, r6, #0
.L080E016E:
	adds r4, r0, #0
	ldr r1, [sp, #0x40]
	adds r0, r7, #4
	mov sl, r0
	ldr r2, [r5]
	add r3, sp, #0x44
	mov r8, r3
	mov r0, sp
	adds r0, #0x50
	str r0, [sp, #0x9c]
	mov r3, sp
	adds r3, #0x5c
	str r3, [sp, #0xa0]
	adds r0, r7, #0
	adds r0, #0xc
	str r0, [sp, #0x98]
	subs r3, #0x4c
	str r3, [sp, #0x94]
	mov r0, sp
	adds r0, #0x68
	str r0, [sp, #0xa4]
	cmp r1, #0
	beq .L080E01A8
.L080E019C:
	ldr r3, [sp, #0x80]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080E019C
.L080E01A8:
	cmp r2, #0
	beq .L080E01B2
	adds r0, r2, #0
	bl free
.L080E01B2:
	mov r1, sb
	adds r0, r1, r6
	str r6, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080E01BC:
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r1, r7, r3
	str r1, [sp, #0x44]
	mov r4, r8
	str r4, [sp, #0x84]
	ldr r4, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r4, r0
	beq .L080E01E4
	cmp r4, #0
	beq .L080E01DC
	str r1, [r4]
.L080E01DC:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	b .L080E0262
.L080E01E4:
	mov r8, r4
	movs r0, #1
	str r0, [sp, #0x4c]
	ldr r0, [r5]
	subs r0, r4, r0
	asrs r4, r0, #2
	str r4, [sp, #0x48]
	add r1, sp, #0x4c
	add r0, sp, #0x48
	cmp r4, #1
	bhs .L080E01FC
	adds r0, r1, #0
.L080E01FC:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080E021A
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080E021E
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080E021E
.L080E021A:
	movs r0, #0
	mov sb, r0
.L080E021E:
	adds r6, r0, #0
	ldr r1, [r5]
	cmp r8, r1
	beq .L080E0236
	mov r0, r8
	subs r4, r0, r1
	adds r0, r6, #0
	adds r2, r4, #0
	bl memmove
	adds r0, r0, r4
	b .L080E0238
.L080E0236:
	adds r0, r6, #0
.L080E0238:
	adds r4, r0, #0
	ldr r1, [sp, #0x4c]
	ldr r2, [r5]
	cmp r1, #0
	beq .L080E024E
.L080E0242:
	ldr r3, [sp, #0x84]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080E0242
.L080E024E:
	cmp r2, #0
	beq .L080E0258
	adds r0, r2, #0
	bl free
.L080E0258:
	mov r1, sb
	adds r0, r1, r6
	str r6, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080E0262:
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r1, r7, r3
	str r1, [sp, #0x50]
	ldr r4, [sp, #0x9c]
	str r4, [sp, #0x88]
	ldr r4, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r4, r0
	beq .L080E028A
	cmp r4, #0
	beq .L080E0282
	str r1, [r4]
.L080E0282:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	b .L080E0308
.L080E028A:
	mov r8, r4
	movs r0, #1
	str r0, [sp, #0x58]
	ldr r0, [r5]
	subs r0, r4, r0
	asrs r4, r0, #2
	str r4, [sp, #0x54]
	add r1, sp, #0x58
	add r0, sp, #0x54
	cmp r4, #1
	bhs .L080E02A2
	adds r0, r1, #0
.L080E02A2:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080E02C0
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080E02C4
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080E02C4
.L080E02C0:
	movs r0, #0
	mov sb, r0
.L080E02C4:
	adds r6, r0, #0
	ldr r1, [r5]
	cmp r8, r1
	beq .L080E02DC
	mov r0, r8
	subs r4, r0, r1
	adds r0, r6, #0
	adds r2, r4, #0
	bl memmove
	adds r0, r0, r4
	b .L080E02DE
.L080E02DC:
	adds r0, r6, #0
.L080E02DE:
	adds r4, r0, #0
	ldr r1, [sp, #0x58]
	ldr r2, [r5]
	cmp r1, #0
	beq .L080E02F4
.L080E02E8:
	ldr r3, [sp, #0x88]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080E02E8
.L080E02F4:
	cmp r2, #0
	beq .L080E02FE
	adds r0, r2, #0
	bl free
.L080E02FE:
	mov r1, sb
	adds r0, r1, r6
	str r6, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080E0308:
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r1, r7, r3
	str r1, [sp, #0x5c]
	ldr r4, [sp, #0xa0]
	str r4, [sp, #0x8c]
	ldr r4, [r5, #4]
	ldr r0, [r5, #0xc]
	cmp r4, r0
	beq .L080E0330
	cmp r4, #0
	beq .L080E0328
	str r1, [r4]
.L080E0328:
	ldr r0, [r5, #4]
	adds r0, #4
	str r0, [r5, #4]
	b .L080E03AE
.L080E0330:
	mov r8, r4
	movs r0, #1
	str r0, [sp, #0x64]
	ldr r0, [r5]
	subs r0, r4, r0
	asrs r4, r0, #2
	str r4, [sp, #0x60]
	add r1, sp, #0x64
	add r0, sp, #0x60
	cmp r4, #1
	bhs .L080E0348
	adds r0, r1, #0
.L080E0348:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080E0366
	lsls r4, r0, #2
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080E036A
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080E036A
.L080E0366:
	movs r0, #0
	mov sb, r0
.L080E036A:
	adds r6, r0, #0
	ldr r1, [r5]
	cmp r8, r1
	beq .L080E0382
	mov r0, r8
	subs r4, r0, r1
	adds r0, r6, #0
	adds r2, r4, #0
	bl memmove
	adds r0, r0, r4
	b .L080E0384
.L080E0382:
	adds r0, r6, #0
.L080E0384:
	adds r4, r0, #0
	ldr r1, [sp, #0x64]
	ldr r2, [r5]
	cmp r1, #0
	beq .L080E039A
.L080E038E:
	ldr r3, [sp, #0x8c]
	ldr r0, [r3]
	stm r4!, {r0}
	subs r1, #1
	cmp r1, #0
	bne .L080E038E
.L080E039A:
	cmp r2, #0
	beq .L080E03A4
	adds r0, r2, #0
	bl free
.L080E03A4:
	mov r1, sb
	adds r0, r1, r6
	str r6, [r5]
	str r4, [r5, #4]
	str r0, [r5, #0xc]
.L080E03AE:
	ldr r2, .L080E0534 @ =gMaryScriptTable
	ldr r1, .L080E0538 @ =gFarmingTutorialScriptIds
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, [sp, #0x98]
	bl Load__13AScriptEnginePCv
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r4, #0
	str r4, [r0]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r0, [sp, #0x94]
	bl func_080AD724
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x94]
	str r1, [sp, #0x68]
	ldr r2, [sp, #0xa4]
	str r0, [r2, #4]
	str r4, [r1]
	adds r4, r0, #0
	ldr r1, [r5]
	cmp r4, r1
	beq .L080E0406
	cmp r1, #0
	beq .L080E0406
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E0406:
	str r4, [r5]
	ldr r1, [sp, #0x10]
	cmp r1, #0
	beq .L080E041A
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E041A:
	movs r0, #4
	bl __builtin_new
	adds r4, r0, #0
	mov r0, sl
	bl GetHardwareDisplayState
	adds r1, r0, #0
	adds r0, r4, #0
	bl __23HardwareBlendControllerP20HardwareDisplayState
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r5, r7, r3
	adds r4, r0, #0
	ldr r0, [r5]
	cmp r4, r0
	beq .L080E0448
	cmp r0, #0
	beq .L080E0448
	movs r1, #3
	bl _._23HardwareBlendController
.L080E0448:
	str r4, [r5]
.L080E044A:
	mov r0, sl
	bl UpdateHardwareInput
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r6, r7, r4
	ldr r0, [r6]
	cmp r0, #1
	beq .L080E04B2
	mov r0, sl
	bl GetHardwareCoreState
	ldrh r0, [r0, #8]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080E04B2
	movs r0, #0xdc
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r0, [r5]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	blt .L080E04B2
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	cmp r0, #0
	beq .L080E04A2
	bl GetState__C12UiStateOwner
	cmp r0, #1
	beq .L080E04B2
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #2
	beq .L080E04B2
.L080E04A2:
	ldr r0, [r5]
	ldr r1, .L080E053C @ =0x00000889
	movs r2, #1
	movs r3, #1
	bl EndHardwareBlend
	movs r0, #1
	str r0, [r6]
.L080E04B2:
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r0, [r4]
	cmp r0, #0
	beq .L080E0518
	mov r0, sl
	bl GetHardwareCoreState
	ldrh r2, [r0, #8]
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080E0540 @ =0xFFFFFF00
	ands r1, r2
	orrs r1, r0
	ldr r4, [r4]
	mov sb, r4
	add r5, sp, #0x14
	adds r0, r5, #0
	bl __18HardwareInputStateUi
	mov r0, sl
	bl GetHardwareSpriteBuffer
	mov r8, r0
	mov r0, sl
	bl GetHardwareDisplayState
	adds r6, r0, #0
	mov r0, sl
	bl GetHardwareCommandList
	adds r4, r0, #0
	mov r0, sl
	bl GetHardwareInterruptList
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r1, r7, r3
	str r4, [sp]
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, sb
	adds r1, r5, #0
	mov r2, r8
	adds r3, r6, #0
	bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot
.L080E0518:
	movs r6, #0
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0xb
	bls .L080E0528
	b .L080E075E
.L080E0528:
	lsls r0, r0, #2
	ldr r1, .L080E0544 @ =.L080E0548
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080E0534: .4byte gMaryScriptTable
.L080E0538: .4byte gFarmingTutorialScriptIds
.L080E053C: .4byte 0x00000889
.L080E0540: .4byte 0xFFFFFF00
.L080E0544: .4byte .L080E0548
.L080E0548: @ jump table
	.4byte .L080E0578 @ case 0
	.4byte .L080E05A2 @ case 1
	.4byte .L080E05D0 @ case 2
	.4byte .L080E05EC @ case 3
	.4byte .L080E0616 @ case 4
	.4byte .L080E065C @ case 5
	.4byte .L080E06BC @ case 6
	.4byte .L080E0632 @ case 7
	.4byte .L080E06DE @ case 8
	.4byte .L080E06FA @ case 9
	.4byte .L080E0712 @ case 10
	.4byte .L080E0734 @ case 11
.L080E0578:
	movs r6, #1
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [sp, #0x98]
	bl _call_via_r1
	adds r2, r0, #0
	cmp r2, #0
	beq .L080E0592
	b .L080E075E
.L080E0592:
	movs r1, #0xd7
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	str r2, [r0]
	ldr r2, [sp, #0x7c]
	str r1, [r2]
	b .L080E08F4
.L080E05A2:
	movs r6, #1
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r2, r1, #0x1f
	cmp r2, #0
	beq .L080E05C0
	b .L080E075E
.L080E05C0:
	movs r4, #0xd7
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r1, [r0]
	str r2, [r0]
	ldr r5, [sp, #0x7c]
	str r1, [r5]
	b .L080E08F4
.L080E05D0:
	movs r6, #1
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	beq .L080E05E4
	b .L080E075E
.L080E05E4:
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r7, r2
	b .L080E072E
.L080E05EC:
	movs r6, #1
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r4, r7, r3
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #0
	beq .L080E0600
	b .L080E075E
.L080E0600:
	movs r5, #0
	ldr r0, [r4]
	cmp r5, r0
	beq .L080E0612
	cmp r0, #0
	beq .L080E0612
	movs r1, #3
	bl _._12UiStateOwner
.L080E0612:
	str r5, [r4]
	b .L080E0728
.L080E0616:
	movs r6, #1
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r0, [r0]
	bl GetState__C12UiStateOwner
	cmp r0, #3
	beq .L080E062A
	b .L080E075E
.L080E062A:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r7, r0
	b .L080E072E
.L080E0632:
	movs r6, #1
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	bl GetState__C12UiStateOwner
	cmp r0, #6
	bne .L080E0646
	b .L080E075E
.L080E0646:
	ldr r0, [r4]
	bl GetChoiceResult__C12UiStateOwner
	adds r1, r0, #0
	adds r0, r7, #0
	bl Push__20FarmingTutorialScenei
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r7, r2
	b .L080E072E
.L080E065C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	cmp r4, #0
	bne .L080E075E
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	bl GetHardwareDisplayState
	ldrh r2, [r0]
	ldr r1, .L080E06B4 @ =0x0000F0FF
	ands r1, r2
	strh r1, [r0]
	mov r0, sl
	bl GetHardwareDisplayState
	adds r0, #0x50
	ldrh r2, [r0]
	ldr r1, .L080E06B8 @ =0x0000FF3F
	ands r1, r2
	strh r1, [r0]
	mov r0, sl
	bl GetHardwareDisplayState
	adds r0, #0x4c
	strh r4, [r0]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	b .L080E075E
	.align 2, 0
.L080E06B4: .4byte 0x0000F0FF
.L080E06B8: .4byte 0x0000FF3F
.L080E06BC:
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	bl GetStep__C23HardwareBlendController
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	cmp r1, #0
	bne .L080E075E
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r7, r3
	b .L080E075C
.L080E06DE:
	movs r4, #0xe6
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080E075E
	movs r5, #0xd9
	lsls r5, r5, #2
	adds r0, r7, r5
	b .L080E075C
.L080E06FA:
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	bl IsActorAxisMotionComplete
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E075E
	movs r1, #0
	str r1, [r4]
	b .L080E0756
.L080E0712:
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r1, [r1, #0x28]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E075E
.L080E0728:
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r1, r7, r4
.L080E072E:
	movs r0, #0
	str r0, [r1]
	b .L080E075E
.L080E0734:
	movs r5, #0xda
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x40]
	movs r1, #0x5e
	bl _call_via_r2
	ldr r1, [r0, #0x14]
	ldr r1, [r1, #0x3c]
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne .L080E075E
.L080E0756:
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r7, r2
.L080E075C:
	str r1, [r0]
.L080E075E:
	cmp r6, #0
	bne .L080E077C
	mov r0, sl
	bl GetHardwareCoreState
	add r1, sp, #0x70
	str r0, [sp, #0x70]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	bl _call_via_r2
.L080E077C:
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080E078A
	b .L080E08A8
.L080E078A:
	mov r0, sl
	bl GetHardwareDmaQueue
	adds r2, r0, #0
	ldr r5, .L080E07D4 @ =0x000003A1
	adds r0, r7, r5
	ldrb r0, [r0]
	ldr r1, .L080E07D8 @ =0x0000FFFF
	cmp r0, #0
	beq .L080E07A0
	movs r1, #0
.L080E07A0:
	adds r6, r2, #0
	add r0, sp, #0xc
	movs r2, #0xa0
	lsls r2, r2, #0x13
	movs r3, #2
	bl __21DmaTransferDescriptorUiPvUi
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x90]
	ldr r1, [r6, #4]
	ldr r0, [r6, #0xc]
	cmp r1, r0
	beq .L080E07DC
	cmp r1, #0
	beq .L080E07CC
	adds r0, r1, #0
	add r1, sp, #0xc
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
.L080E07CC:
	ldr r0, [r6, #4]
	adds r0, #0x10
	str r0, [r6, #4]
	b .L080E08E0
	.align 2, 0
.L080E07D4: .4byte 0x000003A1
.L080E07D8: .4byte 0x0000FFFF
.L080E07DC:
	mov r8, r1
	movs r0, #1
	str r0, [sp, #0x78]
	ldr r0, [r6]
	subs r0, r1, r0
	asrs r4, r0, #4
	str r4, [sp, #0x74]
	add r1, sp, #0x78
	add r0, sp, #0x74
	cmp r4, #1
	bhs .L080E07F4
	adds r0, r1, #0
.L080E07F4:
	ldr r0, [r0]
	adds r0, r4, r0
	cmp r0, #0
	beq .L080E0812
	lsls r4, r0, #4
	adds r0, r4, #0
	bl malloc
	mov sb, r4
	cmp r0, #0
	bne .L080E0816
	mov r0, sb
	bl RetryMemoryAllocation
	b .L080E0816
.L080E0812:
	movs r0, #0
	mov sb, r0
.L080E0816:
	adds r5, r0, #0
	str r5, [sp, #0xa8]
	ldr r2, [r6]
	mov ip, r5
	cmp r2, r8
	beq .L080E083E
.L080E0822:
	mov r5, ip
	cmp r5, #0
	beq .L080E0834
	mov r0, ip
	adds r1, r2, #0
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r0]
.L080E0834:
	adds r2, #0x10
	movs r0, #0x10
	add ip, r0
	cmp r2, r8
	bne .L080E0822
.L080E083E:
	mov r5, ip
	ldr r0, [sp, #0x78]
	cmp r0, #1
	bne .L080E085A
	cmp r5, #0
	beq .L080E0856
	adds r0, r5, #0
	ldr r1, [sp, #0x90]
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
.L080E0856:
	adds r5, #0x10
	b .L080E0882
.L080E085A:
	mov r8, r0
	adds r2, r5, #0
	cmp r0, #0
	beq .L080E0880
.L080E0862:
	cmp r2, #0
	beq .L080E0872
	adds r0, r2, #0
	ldr r1, [sp, #0x90]
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r0]
.L080E0872:
	movs r5, #1
	rsbs r5, r5, #0
	add r8, r5
	adds r2, #0x10
	mov r0, r8
	cmp r0, #0
	bne .L080E0862
.L080E0880:
	adds r5, r2, #0
.L080E0882:
	ldr r2, [r6, #4]
	ldr r0, [r6]
	adds r1, r0, #0
	cmp r0, r2
	beq .L080E0892
.L080E088C:
	adds r1, #0x10
	cmp r1, r2
	bne .L080E088C
.L080E0892:
	cmp r0, #0
	beq .L080E089A
	bl free
.L080E089A:
	ldr r0, [sp, #0xa8]
	add r0, sb
	ldr r1, [sp, #0xa8]
	str r1, [r6]
	str r5, [r6, #4]
	str r0, [r6, #0xc]
	b .L080E08E0
.L080E08A8:
	mov r0, sl
	bl GetHardwareDmaQueue
	adds r6, r0, #0
	mov r0, sl
	bl GetHardwareDisplayState
	adds r5, r0, #0
	mov r0, sl
	bl GetHardwareSpriteBuffer
	adds r4, r0, #0
	mov r0, sl
	bl GetHardwareCommandList
	str r6, [sp, #0xc]
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [r1, #0x10]
	add r1, sp, #0xc
	bl _call_via_r2
.L080E08E0:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	bl Update__23HardwareBlendController
	mov r0, sl
	bl UpdateHardwareFrame
	b .L080E044A
.L080E08F4:
	ldr r0, [sp, #0x7c]
	add sp, #0xac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.map_clock_status_lifecycle_after, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E0E80
func_080E0E80: @ 0x080E0E80
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r2, #0
	subs r3, r1, r6
.L080E0E88:
	cmp r3, #0
	ble .L080E0EAC
	asrs r2, r3, #1
	adds r5, r6, r2
	ldrb r1, [r5]
	movs r4, #0
	ldr r0, [r7]
	cmp r1, r0
	bhs .L080E0E9C
	movs r4, #1
.L080E0E9C:
	cmp r4, #0
	beq .L080E0EA8
	adds r6, r5, #1
	subs r0, r3, r2
	subs r3, r0, #1
	b .L080E0E88
.L080E0EA8:
	adds r3, r2, #0
	b .L080E0E88
.L080E0EAC:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

    .endif
	.section ".text.code_080E0EF0"

    .ifdef REGION_JP
    @ JP revision 0 counterpart of .text.code_080E0EF0.
    @
    @ Ranges are bounded by statically verified JP function entries.  The
    @ trailing boundary is the independently matched start of the JP vtable
    @ region.  No build-time splitter generates this source.

    .syntax unified
    .thumb

    .global func_080E0EF0
    .thumb_func
func_080E0EF0:
    push {lr}
    bl _._13AScriptEngine
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .section .text.code_080E0F48, "ax", %progbits
    .align 2, 0

    .global Run__20UiDmaTransferCommand
    .thumb_func
Run__20UiDmaTransferCommand:
    push {r4, r5, lr}
    ldr r5, [r0, #0xc]
    movs r0, #0
    ldr r1, [r5]
    cmp r1, #0
    bne .Lauto_080E06F6
    movs r0, #1
    .Lauto_080E06F6:
    cmp r0, #0
    bne .Lauto_080E0726
    adds r4, r5, #4
    lsls r1, r1, #4
    adds r1, r4, r1
    adds r0, r4, #0
    bl ExecuteBiosTransfers
    ldr r0, [r5]
    lsls r0, r0, #4
    adds r0, #4
    adds r0, r5, r0
    adds r2, r0, #0
    adds r1, r4, #0
    ldr r3, [r5]
    cmp r1, r2
    beq .Lauto_080E071E
    .Lauto_080E0718:
    adds r1, #0x10
    cmp r1, r2
    bne .Lauto_080E0718
    .Lauto_080E071E:
    subs r0, r0, r4
    asrs r0, r0, #4
    subs r0, r3, r0
    str r0, [r5]
    .Lauto_080E0726:
    movs r0, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .section .text.ui_text_output_base_after, "ax", %progbits
    .align 2, 0
    .global func_080E118C
    .thumb_func
func_080E118C:
    push {r4, r5, r6, lr}
    sub sp, #0x24
    adds r6, r0, #0
    cmp r2, #0xff
    bne .Lauto_080E0974
    add r4, sp, #0x20
    ldrh r1, [r1, #4]
    adds r0, r4, #0
    bl __7ArticleUi
    adds r0, r4, #0
    bl GetName__C7Article
    adds r5, r0, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E0954
    movs r4, #0x1f
    .Lauto_080E0954:
    mov r0, sp
    adds r1, r5, #0
    adds r2, r4, #0
    bl memcpy
    mov r0, sp
    adds r1, r0, r4
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r6]
    adds r0, r6, #4
    mov r1, sp
    bl strcpy
    b .Lauto_080E0982
    .Lauto_080E0974:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    strb r0, [r6]
    adds r0, r6, #4
    bl strcpy
    .Lauto_080E0982:
    adds r0, r6, #0
    add sp, #0x24
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .global func_080E11EC
    .thumb_func
func_080E11EC:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r0, #0
    mov sl, r1
    ldr r0, [pc, #0x290]
    adds r1, r6, r0
    ldr r0, [pc, #0x290]
    str r0, [r1]
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r5, r6, r1
    movs r2, #0xa9
    lsls r2, r2, #3
    adds r0, r6, r2
    cmp r0, #0
    beq .Lauto_080E09D2
    adds r1, #0x18
    adds r4, r6, r1
    cmp r0, r4
    beq .Lauto_080E09D2
    adds r7, r0, #0
    .Lauto_080E09BC:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r7, r4
    bne .Lauto_080E09BC
    .Lauto_080E09D2:
    ldr r1, [r5, #4]
    adds r0, r5, #0
    bl ReleaseObjTileHandle
    adds r0, r5, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xa0
    lsls r2, r2, #3
    adds r0, r6, r2
    movs r1, #0xe0
    adds r1, r1, r6
    mov r8, r1
    adds r7, r6, #0
    adds r7, #0xb0
    movs r2, #0x80
    adds r2, r2, r6
    mov sb, r2
    cmp r0, #0
    beq .Lauto_080E0A36
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r5, r6, r1
    cmp r0, r5
    beq .Lauto_080E0A36
    .Lauto_080E0A06:
    subs r5, #0x10
    adds r4, r5, #0
    adds r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    ldr r1, [r5, #4]
    adds r0, r5, #0
    bl ReleaseObjTileHandle
    adds r0, r5, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xa0
    lsls r2, r2, #3
    adds r0, r6, r2
    cmp r0, r5
    bne .Lauto_080E0A06
    .Lauto_080E0A36:
    movs r0, #0x9f
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0x9e
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0x9d
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x9c
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0x9b
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0x9a
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0x99
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0x98
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0x97
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0x96
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0x95
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0x94
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x93
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0x92
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0x91
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0x90
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0x8f
    lsls r1, r1, #3
    adds r4, r6, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0x8e
    lsls r2, r2, #3
    adds r4, r6, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x8d
    lsls r0, r0, #3
    adds r4, r6, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xe8
    lsls r2, r2, #1
    adds r1, r6, r2
    ldr r0, [pc, #0x54]
    str r0, [r1]
    subs r2, #0x30
    adds r1, r6, r2
    str r0, [r1]
    subs r2, #0x30
    adds r1, r6, r2
    str r0, [r1]
    subs r2, #0x30
    adds r1, r6, r2
    str r0, [r1]
    subs r2, #0x30
    adds r1, r6, r2
    str r0, [r1]
    mov r1, r8
    str r0, [r1]
    str r0, [r7]
    mov r2, sb
    str r0, [r2]
    str r0, [r6, #0x50]
    str r0, [r6, #0x20]
    ldr r0, [r6, #0x10]
    cmp r0, #0
    beq .Lauto_080E0C14
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E0C14:
    adds r0, r6, #0
    mov r1, sl
    bl _._15HardwareContext
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xA0, 0x23, 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .4byte __vt_23IndexedResourceProvider
    .global func_080E0C38_vtable_target
    .thumb_func
func_080E0C38_vtable_target:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E0C4E
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E0C4E:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .global func_080E14B8
    .thumb_func
func_080E14B8:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x28
    adds r7, r0, #0
    adds r3, r1, #0
    adds r0, r2, #0
    subs r0, #0xfa
    cmp r0, #5
    bhi .Lauto_080E0D18
    lsls r0, r0, #2
    ldr r1, [pc, #8]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0x78, 0x0C, 0x0E, 0x08
    .Lauto_080E0C78:
    .byte 0x90, 0x0C, 0x0E, 0x08, 0x28, 0x0D, 0x0E, 0x08, 0xC8, 0x0C, 0x0E, 0x08, 0xCC, 0x0C, 0x0E, 0x08
    .byte 0xD0, 0x0C, 0x0E, 0x08, 0xD4, 0x0C, 0x0E, 0x08
    .Lauto_080E0C90:
    .byte 0x58, 0x69, 0x69, 0x46, 0x00, 0x22, 0x6D, 0xF7, 0x79, 0xFE, 0x02, 0xAD, 0x68, 0x46, 0xF2, 0xF7
    .byte 0x47, 0xFB, 0x04, 0x1C, 0x1F, 0x2C, 0x00, 0xD9, 0x1F, 0x24, 0x28, 0x1C, 0x69, 0x46, 0x22, 0x1C
    .byte 0xF2, 0xF7, 0x4C, 0xFA, 0x29, 0x19, 0x00, 0x20, 0x08, 0x70, 0x01, 0x20, 0x38, 0x70, 0x38, 0x1D
    .byte 0x29, 0x1C, 0xF2, 0xF7, 0x0D, 0xFB, 0x46, 0xE0
    .Lauto_080E0CC8:
    .byte 0x59, 0x68, 0x04, 0xE0
    .Lauto_080E0CCC:
    .byte 0x99, 0x68, 0x02, 0xE0
    .Lauto_080E0CD0:
    .byte 0xD9, 0x68, 0x00, 0xE0
    .Lauto_080E0CD4:
    .byte 0x19, 0x69, 0x80, 0x29, 0x26, 0xD0, 0x02, 0xAE, 0x0D, 0x20, 0x0D, 0x1C, 0x45, 0x43, 0x0C, 0x48
    .byte 0x2D, 0x18, 0x28, 0x1C, 0xF2, 0xF7, 0x22, 0xFB, 0x04, 0x1C, 0x1F, 0x2C, 0x00, 0xD9, 0x1F, 0x24
    .byte 0x30, 0x1C, 0x29, 0x1C, 0x22, 0x1C, 0xF2, 0xF7, 0x27, 0xFA, 0x31, 0x19, 0x00, 0x20, 0x08, 0x70
    .byte 0x01, 0x20, 0x38, 0x70, 0x38, 0x1D, 0x31, 0x1C, 0xF2, 0xF7, 0xE8, 0xFA, 0x21, 0xE0, 0x00, 0x00
    .word gText_AnimalFestival_LivestockContestantNames
    .Lauto_080E0D18:
    add r1, sp, #8
    movs r0, #0
    strb r0, [r1]
    strb r0, [r7]
    adds r0, r7, #4
    bl strcpy
    b .Lauto_080E0D56
    .Lauto_080E0D28:
    .byte 0x9D, 0x69, 0x28, 0x1C, 0xF2, 0xF7, 0x00, 0xFB, 0x04, 0x1C, 0x1F, 0x2C, 0x00, 0xD9, 0x1F, 0x24
    .byte 0x68, 0x46, 0x29, 0x1C, 0x22, 0x1C, 0xF2, 0xF7, 0x05, 0xFA, 0x68, 0x46, 0x01, 0x19, 0x00, 0x20
    .byte 0x08, 0x70, 0x01, 0x20, 0x38, 0x70, 0x38, 0x1D, 0x69, 0x46, 0xF2, 0xF7, 0xC5, 0xFA
    .Lauto_080E0D56:
    adds r0, r7, #0
    add sp, #0x28
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .global func_080E0D60
    .thumb_func
func_080E0D60:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r7, r0, #0
    mov r8, r1
    movs r0, #0x8e
    lsls r0, r0, #5
    adds r1, r7, r0
    ldr r0, [pc, #0x248]
    str r0, [r1]
    movs r1, #0xcb
    lsls r1, r1, #3
    adds r0, r7, r1
    cmp r0, #0
    beq .Lauto_080E0DCC
    movs r2, #0xd7
    lsls r2, r2, #3
    adds r5, r7, r2
    cmp r0, r5
    beq .Lauto_080E0DCC
    .Lauto_080E0D88:
    subs r5, #0x18
    adds r0, r5, #0
    adds r0, #8
    cmp r0, #0
    beq .Lauto_080E0DB2
    adds r4, r5, #0
    adds r4, #0x18
    cmp r0, r4
    beq .Lauto_080E0DB2
    adds r6, r0, #0
    .Lauto_080E0D9C:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r6, r4
    bne .Lauto_080E0D9C
    .Lauto_080E0DB2:
    ldr r1, [r5, #4]
    adds r0, r5, #0
    bl ReleaseObjTileHandle
    adds r0, r5, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xcb
    lsls r1, r1, #3
    adds r0, r7, r1
    cmp r0, r5
    bne .Lauto_080E0D88
    .Lauto_080E0DCC:
    movs r2, #0xca
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xc9
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0xc8
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xc7
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc6
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xc5
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xc4
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc3
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0xc2
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xc1
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc0
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xbf
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xbd
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0xbc
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xbb
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xba
    lsls r0, r0, #3
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xb9
    lsls r1, r1, #3
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0xb8
    lsls r2, r2, #3
    adds r4, r7, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xd0
    lsls r0, r0, #1
    adds r1, r7, r0
    ldr r0, [pc, #0x48]
    str r0, [r1]
    movs r2, #0xb8
    lsls r2, r2, #1
    adds r1, r7, r2
    str r0, [r1]
    subs r2, #0x30
    adds r1, r7, r2
    str r0, [r1]
    subs r2, #0x30
    adds r1, r7, r2
    str r0, [r1]
    adds r1, r7, #0
    adds r1, #0xe0
    str r0, [r1]
    subs r1, #0x30
    str r0, [r1]
    subs r1, #0x30
    str r0, [r1]
    str r0, [r7, #0x50]
    str r0, [r7, #0x20]
    ldr r0, [r7, #0x10]
    cmp r0, #0
    beq .Lauto_080E0FAA
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E0FAA:
    adds r0, r7, #0
    mov r1, r8
    bl _._15HardwareContext
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .4byte __vt_23ScriptTextVariableStore
    .4byte __vt_23IndexedResourceProvider
    .global func_080E0FC4
    .thumb_func
func_080E0FC4:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E0FDA
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E0FDA:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .global func_080E1844
    .thumb_func
func_080E1844:
    .global func_080E0FE4
    .thumb_func
func_080E0FE4:
    push {r4, r5, r6, lr}
    sub sp, #0x20
    adds r6, r0, #0
    cmp r2, #0xff
    bne .Lauto_080E102C
    ldr r0, [r1, #4]
    lsls r1, r0, #2
    adds r1, r1, r0
    lsls r1, r1, #2
    ldr r0, [pc, #0x30]
    adds r5, r1, r0
    adds r0, r5, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E1008
    movs r4, #0x1f
    .Lauto_080E1008:
    mov r0, sp
    adds r1, r5, #0
    adds r2, r4, #0
    bl memcpy
    mov r0, sp
    adds r1, r0, r4
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r6]
    adds r0, r6, #4
    mov r1, sp
    bl strcpy
    b .Lauto_080E103A
    .word gHorseRacePrizeCatalog
    .Lauto_080E102C:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    strb r0, [r6]
    adds r0, r6, #4
    bl strcpy
    .Lauto_080E103A:
    adds r0, r6, #0
    add sp, #0x20
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .global func_080E18A4
    .thumb_func
func_080E18A4:
    .global func_080E1044
    .thumb_func
func_080E1044:
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r6, r1, #0
    ldr r0, [pc, #0xac]
    adds r1, r5, r0
    ldr r0, [pc, #0xac]
    str r0, [r1]
    movs r0, #0xa2
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x9e
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0x9a
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x96
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0x92
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x8e
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r0, [pc, #0x28]
    str r0, [r5, #0x50]
    str r0, [r5, #0x20]
    ldr r0, [r5, #0x10]
    cmp r0, #0
    beq .Lauto_080E10E8
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E10E8:
    adds r0, r5, #0
    adds r1, r6, #0
    bl _._15HardwareContext
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xEC, 0x0A, 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .4byte __vt_23IndexedResourceProvider
    .global func_080E1104
    .thumb_func
func_080E1104:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E111A
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E111A:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore

    .section .text.indexed_resource_archive_destructor_after, "ax", %progbits
    .align 2, 0
    .global func_080E11E8
    .thumb_func
func_080E11E8:
    push {lr}
    bl func_08076EA8
    movs r0, #1
    pop {r1}
    bx r1
    .global func_080E11F4
    .thumb_func
func_080E11F4:
    push {lr}
    ldr r2, [pc, #0x10]
    adds r3, r0, r2
    ldr r2, [pc, #0x10]
    str r2, [r3]
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xC4, 0x09, 0x00, 0x00
    .4byte __vt_23IndexedResourceProvider
    .global func_080E1A70
    .thumb_func
func_080E1A70:
    .global func_080E1210
    .thumb_func
func_080E1210:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x24
    adds r7, r0, #0
    bl func_08076EA8
    movs r0, #0
    mov r8, r0
    ldr r1, [pc, #0x184]
    adds r0, r7, r1
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r0, #0x30
    movs r3, #0xb2
    lsls r3, r3, #3
    adds r1, r7, r3
    movs r2, #0
    ldrsh r1, [r1, r2]
    cmp r0, r1
    bge .Lauto_080E1254
    adds r2, r1, #0
    ldr r3, [pc, #0x168]
    adds r1, r7, r3
    .Lauto_080E1244:
    adds r1, #0x10
    movs r0, #1
    add r8, r0
    movs r3, #0
    ldrsh r0, [r1, r3]
    adds r0, #0x30
    cmp r0, r2
    blt .Lauto_080E1244
    .Lauto_080E1254:
    ldr r1, [pc, #0x158]
    adds r0, r7, r1
    ldr r0, [r0]
    movs r2, #0x8e
    lsls r2, r2, #5
    adds r2, r7, r2
    str r2, [sp, #0x20]
    cmp r8, r0
    bhs .Lauto_080E12E2
    adds r3, r1, #0
    adds r3, r3, r7
    mov sl, r3
    movs r0, #0xb2
    lsls r0, r0, #3
    adds r0, r0, r7
    mov sb, r0
    mov r1, r8
    lsls r0, r1, #4
    ldr r2, [pc, #0x130]
    adds r0, r0, r2
    adds r5, r0, r7
    .Lauto_080E127E:
    movs r3, #0
    ldrsh r1, [r5, r3]
    mov r2, sb
    movs r3, #0
    ldrsh r0, [r2, r3]
    adds r0, #0xa0
    cmp r1, r0
    bgt .Lauto_080E12D4
    ldr r0, [r7]
    bl GetHardwareSpriteBuffer
    adds r4, r0, #0
    movs r0, #0
    ldrsh r2, [r5, r0]
    mov r1, sb
    movs r3, #0
    ldrsh r0, [r1, r3]
    subs r2, r2, r0
    ldr r1, [r5, #4]
    movs r0, #2
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    str r0, [sp, #8]
    movs r0, #0
    str r0, [sp, #0xc]
    add r6, sp, #0x10
    adds r0, r6, #0
    movs r3, #0x10
    bl func_0804EA94
    ldrb r2, [r4]
    cmp r2, #0x7f
    bhi .Lauto_080E12D4
    lsls r1, r2, #3
    adds r1, #4
    adds r1, r4, r1
    ldr r0, [sp, #0x10]
    str r0, [r1]
    ldrh r0, [r6, #4]
    strh r0, [r1, #4]
    adds r0, r2, #1
    strb r0, [r4]
    .Lauto_080E12D4:
    adds r5, #0x10
    movs r0, #1
    add r8, r0
    mov r1, sl
    ldr r0, [r1]
    cmp r8, r0
    blo .Lauto_080E127E
    .Lauto_080E12E2:
    movs r2, #0
    mov r8, r2
    ldr r3, [sp, #0x20]
    movs r1, #0
    ldrsh r0, [r3, r1]
    adds r0, #0x30
    movs r2, #0xb2
    lsls r2, r2, #3
    adds r1, r7, r2
    movs r3, #0
    ldrsh r1, [r1, r3]
    cmp r0, r1
    bge .Lauto_080E1314
    adds r2, r1, #0
    movs r0, #0x8e
    lsls r0, r0, #5
    adds r1, r7, r0
    .Lauto_080E1304:
    adds r1, #0x10
    movs r3, #1
    add r8, r3
    movs r3, #0
    ldrsh r0, [r1, r3]
    adds r0, #0x30
    cmp r0, r2
    blt .Lauto_080E1304
    .Lauto_080E1314:
    ldr r1, [pc, #0x9c]
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r8, r0
    bhs .Lauto_080E139A
    adds r2, r1, #0
    adds r2, r2, r7
    mov sl, r2
    movs r3, #0xb2
    lsls r3, r3, #3
    adds r3, r3, r7
    mov sb, r3
    mov r1, r8
    lsls r0, r1, #4
    movs r2, #0x8e
    lsls r2, r2, #5
    adds r0, r0, r2
    adds r6, r0, r7
    .Lauto_080E1338:
    movs r3, #0
    ldrsh r1, [r6, r3]
    mov r2, sb
    movs r3, #0
    ldrsh r0, [r2, r3]
    adds r0, #0xa0
    cmp r1, r0
    bgt .Lauto_080E138C
    ldr r0, [r7]
    bl GetHardwareSpriteBuffer
    adds r4, r0, #0
    movs r0, #0
    ldrsh r2, [r6, r0]
    mov r1, sb
    movs r3, #0
    ldrsh r0, [r1, r3]
    subs r2, r2, r0
    ldr r1, [r6, #4]
    movs r0, #1
    str r0, [sp]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    str r0, [sp, #0xc]
    add r5, sp, #0x18
    adds r0, r5, #0
    movs r3, #5
    bl func_0804EA94
    ldrb r2, [r4]
    cmp r2, #0x7f
    bhi .Lauto_080E138C
    lsls r1, r2, #3
    adds r1, #4
    adds r1, r4, r1
    ldr r0, [sp, #0x18]
    str r0, [r1]
    ldrh r0, [r5, #4]
    strh r0, [r1, #4]
    adds r0, r2, #1
    strb r0, [r4]
    .Lauto_080E138C:
    adds r6, #0x10
    movs r0, #1
    add r8, r0
    mov r1, sl
    ldr r0, [r1]
    cmp r8, r0
    blo .Lauto_080E1338
    .Lauto_080E139A:
    movs r0, #1
    add sp, #0x24
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0xEC, 0x0D, 0x00, 0x00, 0xE8, 0x0D, 0x00, 0x00, 0xBC, 0x11, 0x00, 0x00
    .global func_080E13B8
    .thumb_func
func_080E13B8:
    push {r4, lr}
    adds r2, r0, #0
    adds r3, r1, #0
    ldr r0, [pc, #0x44]
    adds r1, r2, r0
    ldr r0, [r1]
    lsls r0, r0, #4
    adds r0, #4
    adds r1, r1, r0
    movs r4, #0x8e
    lsls r4, r4, #5
    adds r0, r2, r4
    cmp r0, r1
    beq .Lauto_080E13DA
    .Lauto_080E13D4:
    adds r0, #0x10
    cmp r0, r1
    bne .Lauto_080E13D4
    .Lauto_080E13DA:
    ldr r0, [pc, #0x2c]
    adds r1, r2, r0
    ldr r0, [r1]
    lsls r0, r0, #4
    adds r0, #4
    adds r1, r1, r0
    ldr r4, [pc, #0x24]
    adds r0, r2, r4
    cmp r0, r1
    beq .Lauto_080E13F4
    .Lauto_080E13EE:
    adds r0, #0x10
    cmp r0, r1
    bne .Lauto_080E13EE
    .Lauto_080E13F4:
    adds r0, r2, #0
    adds r1, r3, #0
    bl func_08076E0C
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xBC, 0x11, 0x00, 0x00, 0xE8, 0x0D, 0x00, 0x00, 0xEC, 0x0D, 0x00, 0x00
    .global func_080E1C70
    .thumb_func
func_080E1C70:
    .global func_080E1410
    .thumb_func
func_080E1410:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r7, r0, #0
    bl func_08076EA8
    movs r0, #0
    mov r8, r0
    ldr r1, [pc, #0xc4]
    adds r0, r7, r1
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r0, #0x30
    movs r3, #0xb2
    lsls r3, r3, #3
    adds r1, r7, r3
    movs r2, #0
    ldrsh r1, [r1, r2]
    cmp r0, r1
    bge .Lauto_080E1454
    adds r2, r1, #0
    ldr r3, [pc, #0xa8]
    adds r1, r7, r3
    .Lauto_080E1444:
    adds r1, #0x10
    movs r0, #1
    add r8, r0
    movs r3, #0
    ldrsh r0, [r1, r3]
    adds r0, #0x30
    cmp r0, r2
    blt .Lauto_080E1444
    .Lauto_080E1454:
    ldr r1, [pc, #0x98]
    adds r0, r7, r1
    ldr r0, [r0]
    cmp r8, r0
    bhs .Lauto_080E14D8
    adds r2, r1, #0
    adds r2, r2, r7
    mov sl, r2
    movs r3, #0xb2
    lsls r3, r3, #3
    adds r3, r3, r7
    mov sb, r3
    mov r1, r8
    lsls r0, r1, #4
    ldr r2, [pc, #0x78]
    adds r0, r0, r2
    adds r5, r0, r7
    .Lauto_080E1476:
    movs r3, #0
    ldrsh r1, [r5, r3]
    mov r2, sb
    movs r3, #0
    ldrsh r0, [r2, r3]
    adds r0, #0xa0
    cmp r1, r0
    bgt .Lauto_080E14CA
    ldr r0, [r7]
    bl GetHardwareSpriteBuffer
    adds r4, r0, #0
    movs r0, #0
    ldrsh r2, [r5, r0]
    mov r1, sb
    movs r3, #0
    ldrsh r0, [r1, r3]
    subs r2, r2, r0
    ldr r1, [r5, #4]
    movs r0, #1
    str r0, [sp]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    str r0, [sp, #0xc]
    add r6, sp, #0x10
    adds r0, r6, #0
    movs r3, #5
    bl func_0804EA94
    ldrb r2, [r4]
    cmp r2, #0x7f
    bhi .Lauto_080E14CA
    lsls r1, r2, #3
    adds r1, #4
    adds r1, r4, r1
    ldr r0, [sp, #0x10]
    str r0, [r1]
    ldrh r0, [r6, #4]
    strh r0, [r1, #4]
    adds r0, r2, #1
    strb r0, [r4]
    .Lauto_080E14CA:
    adds r5, #0x10
    movs r0, #1
    add r8, r0
    mov r1, sl
    ldr r0, [r1]
    cmp r8, r0
    blo .Lauto_080E1476
    .Lauto_080E14D8:
    movs r0, #1
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00, 0x68, 0x21, 0x00, 0x00, 0x64, 0x21, 0x00, 0x00
    .global func_080E1D54
    .thumb_func
func_080E1D54:
    .global func_080E14F4
    .thumb_func
func_080E14F4:
    push {r4, lr}
    adds r2, r0, #0
    adds r3, r1, #0
    ldr r0, [pc, #0x28]
    adds r1, r2, r0
    ldr r0, [r1]
    lsls r0, r0, #4
    adds r0, #4
    adds r1, r1, r0
    ldr r4, [pc, #0x20]
    adds r0, r2, r4
    cmp r0, r1
    beq .Lauto_080E1514
    .Lauto_080E150E:
    adds r0, #0x10
    cmp r0, r1
    bne .Lauto_080E150E
    .Lauto_080E1514:
    adds r0, r2, #0
    adds r1, r3, #0
    bl func_08076E0C
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x64, 0x21, 0x00, 0x00, 0x68, 0x21, 0x00, 0x00
    .global func_080E152C
    .thumb_func
func_080E152C:
    push {lr}
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E1538
    .thumb_func
func_080E1538:
    push {lr}
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E1544
    .thumb_func
func_080E1544:
    push {lr}
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E1550
    .thumb_func
func_080E1550:
    push {lr}
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E155C
    .thumb_func
func_080E155C:
    push {lr}
    bl func_08076EA8
    movs r0, #1
    pop {r1}
    bx r1
    .global func_080E1568
    .thumb_func
func_080E1568:
    push {lr}
    bl func_08076E0C
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E1574
    .thumb_func
func_080E1574:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r4, r0
    ldr r0, [r1]
    lsls r0, r0, #3
    adds r0, #4
    adds r1, r1, r0
    movs r2, #0x94
    lsls r2, r2, #1
    adds r0, r4, r2
    ldr r2, [pc, #0x30]
    cmp r0, r1
    beq .Lauto_080E159A
    .Lauto_080E1594:
    adds r0, #8
    cmp r0, r1
    bne .Lauto_080E1594
    .Lauto_080E159A:
    str r2, [r4, #0xc]
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .Lauto_080E15B2
    ldr r2, [pc, #0x20]
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E15B2:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15HardwareContext
    pop {r4, r5}
    pop {r0}
    bx r0
    .4byte __vt_23IndexedResourceProvider
    .byte 0xB4, 0x05, 0x00, 0x00
    .global func_080E15C8
    .thumb_func
func_080E15C8:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r5, r0, #0
    mov sb, r1
    ldr r1, [pc, #0x14c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E15FE
    adds r1, #0x50
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E15FE
    ldr r0, [pc, #0x13c]
    adds r6, r5, r0
    .Lauto_080E15E8:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r6, r4
    bne .Lauto_080E15E8
    .Lauto_080E15FE:
    ldr r1, [pc, #0x128]
    adds r0, r5, r1
    ldr r1, [pc, #0x128]
    adds r7, r5, r1
    ldr r1, [pc, #0x128]
    adds r1, r1, r5
    mov r8, r1
    cmp r0, #0
    beq .Lauto_080E1632
    ldr r1, [pc, #0x110]
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E1632
    ldr r0, [pc, #0x10c]
    adds r6, r5, r0
    .Lauto_080E161C:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    cmp r6, r4
    bne .Lauto_080E161C
    .Lauto_080E1632:
    ldr r1, [pc, #0x100]
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xed
    lsls r0, r0, #6
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r1, [pc, #0xd8]
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    ldr r0, [pc, #0xc8]
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r1, [pc, #0xb8]
    adds r2, r5, r1
    ldr r1, [r2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, #4
    adds r2, r2, r0
    adds r0, r7, #0
    cmp r0, r2
    beq .Lauto_080E16A0
    .Lauto_080E169A:
    adds r0, #0xc
    cmp r0, r2
    bne .Lauto_080E169A
    .Lauto_080E16A0:
    ldr r0, [pc, #0xa0]
    adds r1, r5, r0
    ldr r0, [r1]
    lsls r0, r0, #4
    adds r0, #4
    adds r1, r1, r0
    mov r0, r8
    cmp r0, r1
    beq .Lauto_080E16B8
    .Lauto_080E16B2:
    adds r0, #0x10
    cmp r0, r1
    bne .Lauto_080E16B2
    .Lauto_080E16B8:
    movs r1, #0x9a
    lsls r1, r1, #1
    adds r0, r5, r1
    movs r1, #2
    bl _._12UiStateOwner
    ldr r0, [pc, #0x80]
    str r0, [r5, #0x54]
    str r0, [r5, #0x24]
    ldr r0, [r5, #0x1c]
    cmp r0, #0
    beq .Lauto_080E16FC
    adds r4, r0, #0
    adds r0, #0x28
    movs r1, #2
    bl _._25ScrollBufferUploadCommand
    adds r0, r4, #0
    adds r0, #0x18
    ldr r2, [r0, #4]
    ldr r1, [r4, #0x18]
    cmp r1, r2
    beq .Lauto_080E16EC
    .Lauto_080E16E6:
    adds r1, #0x40
    cmp r1, r2
    bne .Lauto_080E16E6
    .Lauto_080E16EC:
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E16F6
    bl free
    .Lauto_080E16F6:
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080E16FC:
    ldr r1, [r5, #8]
    cmp r1, #0
    beq .Lauto_080E170E
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E170E:
    adds r0, r5, #0
    mov r1, sb
    bl _._15HardwareContext
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xA0, 0x3B, 0x00, 0x00, 0x50, 0x3B, 0x00, 0x00, 0x28, 0x3A, 0x00, 0x00, 0x24, 0x39
    .byte 0x00, 0x00, 0x48, 0x3B, 0x00, 0x00, 0x38, 0x3B, 0x00, 0x00, 0x30, 0x3B, 0x00, 0x00, 0x24, 0x3A
    .byte 0x00, 0x00, 0x20, 0x39, 0x00, 0x00
    .4byte __vt_23IndexedResourceProvider
    .section .text.new_game_birthday_core_cleanup_after, "ax", %progbits
    .align 2, 0
    .global func_080E2018
    .thumb_func
func_080E2018:
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    adds r0, #0xe0
    cmp r0, #0
    beq .Lauto_080E17DE
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E17DE
    adds r6, r0, #0
    .Lauto_080E17D0:
    subs r4, #0x30
    adds r0, r4, #0
    movs r1, #0
    bl loc_080E1860
    cmp r6, r4
    bne .Lauto_080E17D0
    .Lauto_080E17DE:
    adds r0, r5, #0
    adds r0, #0xd0
    ldr r2, [r0, #4]
    ldr r1, [r0]
    adds r4, r5, #0
    adds r4, #0xa0
    adds r6, r5, #0
    adds r6, #0x18
    cmp r1, r2
    beq .Lauto_080E17F8
    .Lauto_080E17F2:
    adds r1, #0x1c
    cmp r1, r2
    bne .Lauto_080E17F2
    .Lauto_080E17F8:
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E1802
    bl free
    .Lauto_080E1802:
    ldr r0, [pc, #0x2c]
    str r0, [r4]
    str r0, [r5, #0x20]
    adds r0, r6, #0
    movs r1, #2
    bl func_0807532C
    ldr r1, [r5, #0xc]
    cmp r1, #0
    beq .Lauto_080E1822
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E1822:
    adds r0, r5, #0
    adds r1, r7, #0
    bl _._15HardwareContext
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .4byte __vt_23IndexedResourceProvider
    .global func_080E2094
    .thumb_func
func_080E2094:
    sub sp, #0xc
    adds r2, r0, #0
    movs r0, #0
    str r0, [r2]
    str r0, [r2, #4]
    adds r1, r2, #0
    adds r1, #8
    str r0, [r1, #4]
    adds r1, #8
    str r0, [r2, #0x10]
    str r0, [r1, #4]
    adds r1, #8
    str r0, [r1, #4]
    adds r1, #8
    str r0, [r2, #0x20]
    str r0, [r1, #4]
    adds r1, #8
    str r0, [r1, #4]
    adds r0, r2, #0
    add sp, #0xc
    bx lr
    .byte 0x00, 0x00
    .global loc_080E1860
    .thumb_func
    loc_080E1860:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [r4, #0x20]
    cmp r0, #0
    beq .Lauto_080E1870
    bl free
    .Lauto_080E1870:
    ldr r0, [r4, #0x10]
    cmp r0, #0
    beq .Lauto_080E187A
    bl free
    .Lauto_080E187A:
    ldr r0, [r4]
    cmp r0, #0
    beq .Lauto_080E1884
    bl free
    .Lauto_080E1884:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080E1892
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080E1892:
    pop {r4, r5}
    pop {r0}
    bx r0
    .global func_080E1898
    .thumb_func
func_080E1898:
    push {lr}
    bl func_08070C88
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E18A4_vtable_target
    .thumb_func
func_080E18A4_vtable_target:
    push {lr}
    bl func_08070C88
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E18B0
    .thumb_func
func_080E18B0:
    push {lr}
    bl func_08070C88
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E18BC
    .thumb_func
func_080E18BC:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r4, r0
    ldr r0, [r1]
    lsls r0, r0, #3
    adds r0, #4
    adds r1, r1, r0
    movs r2, #0x94
    lsls r2, r2, #1
    adds r0, r4, r2
    ldr r2, [pc, #0x30]
    cmp r0, r1
    beq .Lauto_080E18E2
    .Lauto_080E18DC:
    adds r0, #8
    cmp r0, r1
    bne .Lauto_080E18DC
    .Lauto_080E18E2:
    str r2, [r4, #0xc]
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .Lauto_080E18FA
    ldr r2, [pc, #0x20]
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E18FA:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15HardwareContext
    pop {r4, r5}
    pop {r0}
    bx r0
    .4byte __vt_23IndexedResourceProvider
    .byte 0xB4, 0x05, 0x00, 0x00




    .global func_080E2170
    .thumb_func
func_080E2170:
    push {lr}
    adds r2, r0, #0
    ldr r3, [r2, #0xc]
    ldr r0, [r3, #8]
    str r0, [r2, #0xc]
    ldr r0, [r3, #8]
    cmp r0, #0
    beq .Lauto_080E1922
    str r2, [r0, #4]
    .Lauto_080E1922:
    ldr r0, [r2, #4]
    str r0, [r3, #4]
    ldr r0, [r1]
    cmp r2, r0
    bne .Lauto_080E1930
    str r3, [r1]
    b .Lauto_080E193E
    .Lauto_080E1930:
    ldr r1, [r2, #4]
    ldr r0, [r1, #8]
    cmp r2, r0
    bne .Lauto_080E193C
    str r3, [r1, #8]
    b .Lauto_080E193E
    .Lauto_080E193C:
    str r3, [r1, #0xc]
    .Lauto_080E193E:
    str r2, [r3, #8]
    str r3, [r2, #4]
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E21A8
    .thumb_func
func_080E21A8:
    push {lr}
    adds r2, r0, #0
    ldr r3, [r2, #8]
    ldr r0, [r3, #0xc]
    str r0, [r2, #8]
    ldr r0, [r3, #0xc]
    cmp r0, #0
    beq .Lauto_080E195A
    str r2, [r0, #4]
    .Lauto_080E195A:
    ldr r0, [r2, #4]
    str r0, [r3, #4]
    ldr r0, [r1]
    cmp r2, r0
    bne .Lauto_080E1968
    str r3, [r1]
    b .Lauto_080E1976
    .Lauto_080E1968:
    ldr r1, [r2, #4]
    ldr r0, [r1, #0xc]
    cmp r2, r0
    bne .Lauto_080E1974
    str r3, [r1, #0xc]
    b .Lauto_080E1976
    .Lauto_080E1974:
    str r3, [r1, #8]
    .Lauto_080E1976:
    str r2, [r3, #0xc]
    str r3, [r2, #4]
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E21E0
    .thumb_func
func_080E21E0:
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r0, #0
    strb r0, [r4]
    ldr r0, [r5]
    cmp r4, r0
    beq .Lauto_080E1A26
    ldr r2, [r4, #4]
    ldrb r0, [r2]
    cmp r0, #0
    bne .Lauto_080E1A26
    movs r6, #1
    movs r7, #0
    .Lauto_080E199C:
    ldr r1, [r2, #4]
    ldr r0, [r1, #8]
    cmp r2, r0
    bne .Lauto_080E19D8
    ldr r0, [r1, #0xc]
    cmp r0, #0
    beq .Lauto_080E19B0
    ldrb r1, [r0]
    cmp r1, #0
    beq .Lauto_080E19E2
    .Lauto_080E19B0:
    ldr r1, [r4, #4]
    ldr r0, [r1, #0xc]
    cmp r4, r0
    bne .Lauto_080E19C2
    adds r4, r1, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl func_080E2170
    .Lauto_080E19C2:
    ldr r0, [r4, #4]
    strb r6, [r0]
    ldr r0, [r4, #4]
    ldr r0, [r0, #4]
    strb r7, [r0]
    ldr r0, [r4, #4]
    ldr r0, [r0, #4]
    adds r1, r5, #0
    bl func_080E21A8
    b .Lauto_080E1A18
    .Lauto_080E19D8:
    cmp r0, #0
    beq .Lauto_080E19F2
    ldrb r1, [r0]
    cmp r1, #0
    bne .Lauto_080E19F2
    .Lauto_080E19E2:
    strb r6, [r2]
    strb r6, [r0]
    ldr r0, [r4, #4]
    ldr r0, [r0, #4]
    strb r1, [r0]
    ldr r0, [r4, #4]
    ldr r4, [r0, #4]
    b .Lauto_080E1A18
    .Lauto_080E19F2:
    ldr r1, [r4, #4]
    ldr r0, [r1, #8]
    cmp r4, r0
    bne .Lauto_080E1A04
    adds r4, r1, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl func_080E21A8
    .Lauto_080E1A04:
    ldr r0, [r4, #4]
    strb r6, [r0]
    ldr r0, [r4, #4]
    ldr r0, [r0, #4]
    strb r7, [r0]
    ldr r0, [r4, #4]
    ldr r0, [r0, #4]
    adds r1, r5, #0
    bl func_080E2170
    .Lauto_080E1A18:
    ldr r0, [r5]
    cmp r4, r0
    beq .Lauto_080E1A26
    ldr r2, [r4, #4]
    ldrb r0, [r2]
    cmp r0, #0
    beq .Lauto_080E199C
    .Lauto_080E1A26:
    ldr r1, [r5]
    movs r0, #1
    strb r0, [r1]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xF0, 0xB5, 0x07, 0x1C, 0x0E, 0x1C, 0x05, 0x9C, 0x1D, 0x1C, 0x70, 0x68, 0x85, 0x42
    .byte 0x0C, 0xD0, 0x06, 0x98, 0x00, 0x28, 0x29, 0xD1, 0x00, 0x2A, 0x07, 0xD1, 0x00, 0x22, 0x21, 0x68
    .byte 0x28, 0x69, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x22, 0x00, 0x2A, 0x1F, 0xD0, 0x18, 0x20, 0xEE, 0xF7
    .byte 0x0C, 0xF8, 0x02, 0x1C, 0x00, 0x2A, 0x03, 0xD1, 0x18, 0x20, 0xF1, 0xF7, 0x84, 0xFC, 0x02, 0x1C
    .byte 0x11, 0x1C, 0x10, 0x31, 0x00, 0x29, 0x03, 0xD0, 0x20, 0x68, 0x10, 0x61, 0x60, 0x68, 0x48, 0x60
    .byte 0x14, 0x1C, 0xAC, 0x60, 0x71, 0x68, 0x8D, 0x42, 0x03, 0xD1, 0x6C, 0x60, 0x70, 0x68, 0xC4, 0x60
    .byte 0x1D, 0xE0, 0x88, 0x68, 0x85, 0x42, 0x1A, 0xD1, 0x8C, 0x60, 0x18, 0xE0, 0x18, 0x20, 0xED, 0xF7
    .byte 0xEC, 0xFF, 0x02, 0x1C, 0x00, 0x2A, 0x03, 0xD1, 0x18, 0x20, 0xF1, 0xF7, 0x64, 0xFC, 0x02, 0x1C
    .byte 0x11, 0x1C, 0x10, 0x31, 0x00, 0x29, 0x03, 0xD0, 0x20, 0x68, 0x10, 0x61, 0x60, 0x68, 0x48, 0x60
    .byte 0x14, 0x1C, 0xEC, 0x60, 0x71, 0x68, 0xC8, 0x68, 0x85, 0x42, 0x00, 0xD1, 0xCC, 0x60, 0x65, 0x60
    .byte 0x00, 0x20, 0xA0, 0x60, 0xE0, 0x60, 0x71, 0x68, 0x04, 0x31, 0x20, 0x1C, 0xFF, 0xF7, 0x4F, 0xFF
    .byte 0xB0, 0x68, 0x01, 0x30, 0xB0, 0x60, 0x3C, 0x60, 0x38, 0x1C, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
    .byte 0x00, 0x00
    .global func_080E2354
    .thumb_func
func_080E2354:
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r0, #0
    bne .Lauto_080E1B0A
    ldr r0, [r2, #4]
    ldr r0, [r0, #4]
    cmp r0, r2
    bne .Lauto_080E1B0A
    ldr r2, [r2, #0xc]
    b .Lauto_080E1B2A
    .Lauto_080E1B0A:
    ldr r0, [r2, #8]
    cmp r0, #0
    beq .Lauto_080E1B20
    adds r1, r0, #0
    b .Lauto_080E1B16
    .Lauto_080E1B14:
    ldr r1, [r1, #0xc]
    .Lauto_080E1B16:
    ldr r0, [r1, #0xc]
    cmp r0, #0
    bne .Lauto_080E1B14
    b .Lauto_080E1B28
    .Lauto_080E1B1E:
    adds r2, r1, #0
    .Lauto_080E1B20:
    ldr r1, [r2, #4]
    ldr r0, [r1, #8]
    cmp r2, r0
    beq .Lauto_080E1B1E
    .Lauto_080E1B28:
    adds r2, r1, #0
    .Lauto_080E1B2A:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x85, 0xB0, 0x06, 0x1C, 0x88, 0x46, 0x17, 0x1C, 0x4C, 0x68
    .byte 0x65, 0x68, 0x01, 0x20, 0x00, 0x2D, 0x0E, 0xD0, 0x3A, 0x68, 0x2C, 0x1C, 0x00, 0x21, 0x20, 0x69
    .byte 0x82, 0x42, 0x00, 0xD2, 0x01, 0x21, 0x08, 0x1C, 0x00, 0x28, 0x01, 0xD0, 0xA5, 0x68, 0x00, 0xE0
    .byte 0xE5, 0x68, 0x00, 0x2D, 0xF1, 0xD1, 0x02, 0x94, 0x00, 0x28, 0x19, 0xD0, 0x41, 0x46, 0x48, 0x68
    .byte 0x80, 0x68, 0x03, 0x90, 0x00, 0x21, 0x84, 0x42, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x0B, 0xD0
    .byte 0x00, 0x97, 0x00, 0x20, 0x01, 0x90, 0x04, 0xA8, 0x41, 0x46, 0x2A, 0x1C, 0x23, 0x1C, 0xFF, 0xF7
    .byte 0x51, 0xFF, 0x01, 0x21, 0x04, 0x98, 0x18, 0xE0, 0x20, 0x1C, 0xFF, 0xF7, 0xAB, 0xFF, 0x02, 0x90
    .byte 0x02, 0x9A, 0x00, 0x23, 0x11, 0x69, 0x38, 0x68, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x18, 0x1C
    .byte 0x00, 0x28, 0x0D, 0xD0, 0x00, 0x97, 0x00, 0x20, 0x01, 0x90, 0x03, 0xA8, 0x41, 0x46, 0x2A, 0x1C
    .byte 0x23, 0x1C, 0xFF, 0xF7, 0x37, 0xFF, 0x01, 0x21, 0x03, 0x98, 0x30, 0x60, 0x31, 0x71, 0x01, 0xE0
    .byte 0x32, 0x60, 0x30, 0x71, 0x30, 0x1C, 0x05, 0xB0, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x86, 0xB0, 0x07, 0x1C
    .byte 0x0E, 0x1C, 0x90, 0x46, 0x1C, 0x1C, 0x71, 0x68, 0x12, 0x68, 0x88, 0x68, 0x82, 0x42, 0x39, 0xD1
    .byte 0xB0, 0x68, 0x00, 0x28, 0x06, 0xD1, 0x02, 0xA8, 0x31, 0x1C, 0x22, 0x1C, 0xFF, 0xF7, 0x90, 0xFF
    .byte 0x02, 0x98, 0xB9, 0xE0, 0x00, 0x20, 0x11, 0x69, 0x13, 0x1C, 0x22, 0x68, 0x8A, 0x42, 0x00, 0xD2
    .byte 0x01, 0x20, 0x81, 0x46, 0x00, 0x28, 0x5F, 0xD1, 0x00, 0x20, 0x91, 0x42, 0x00, 0xD2, 0x01, 0x20
    .byte 0x00, 0x28, 0x01, 0xD1, 0x3B, 0x60, 0xA8, 0xE0, 0x02, 0x93, 0x18, 0x1C, 0x00, 0xF0, 0x44, 0xFB
    .byte 0x02, 0x1C, 0x02, 0x92, 0x70, 0x68, 0x82, 0x42, 0x02, 0xD1, 0x40, 0x46, 0x03, 0x68, 0x7E, 0xE0
    .byte 0x00, 0x23, 0x21, 0x68, 0x10, 0x69, 0x15, 0x1C, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x00, 0x2B
    .byte 0x00, 0xD1, 0x8B, 0xE0, 0x41, 0x46, 0x0B, 0x68, 0xD8, 0x68, 0x00, 0x28, 0x6F, 0xD0, 0x00, 0x94
    .byte 0x48, 0x46, 0x76, 0xE0, 0x8A, 0x42, 0x12, 0xD1, 0xD3, 0x68, 0x00, 0x25, 0x19, 0x69, 0x20, 0x68
    .byte 0x81, 0x42, 0x00, 0xD2, 0x01, 0x25, 0x00, 0x2D, 0x02, 0xD0, 0x00, 0x94, 0x01, 0x92, 0x60, 0xE0
    .byte 0x02, 0xA8, 0x31, 0x1C, 0x22, 0x1C, 0xFF, 0xF7, 0x4B, 0xFF, 0x02, 0x98, 0x74, 0xE0, 0x02, 0x92
    .byte 0x10, 0x1C, 0xFF, 0xF7, 0x27, 0xFF, 0x02, 0x1C, 0x02, 0x92, 0x41, 0x46, 0x0B, 0x68, 0x00, 0x25
    .byte 0x21, 0x68, 0x18, 0x69, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x25, 0xA9, 0x46, 0x00, 0x2D, 0x1C, 0xD0
    .byte 0x00, 0x20, 0x84, 0x46, 0x10, 0x69, 0x15, 0x1C, 0x88, 0x42, 0x01, 0xD2, 0x01, 0x21, 0x8C, 0x46
    .byte 0x60, 0x46, 0x00, 0x28, 0x11, 0xD0, 0xE8, 0x68, 0x00, 0x28, 0x05, 0xD1, 0x00, 0x94, 0x01, 0x95
    .byte 0x38, 0x1C, 0x31, 0x1C, 0x00, 0x22, 0x40, 0xE0, 0x00, 0x94, 0x00, 0x20, 0x01, 0x90, 0x38, 0x1C
    .byte 0x31, 0x1C, 0x1A, 0x1C, 0xFF, 0xF7, 0x9E, 0xFE, 0x47, 0xE0, 0x41, 0x46, 0x08, 0x68, 0x03, 0x90
    .byte 0x00, 0xF0, 0xE2, 0xFA, 0x84, 0x46, 0x03, 0x90, 0x01, 0x20, 0x49, 0x46, 0x41, 0x40, 0x48, 0x46
    .byte 0x00, 0x28, 0x2E, 0xD1, 0x41, 0x46, 0x08, 0x68, 0x00, 0x25, 0x01, 0x69, 0x03, 0x1C, 0x22, 0x68
    .byte 0x91, 0x42, 0x00, 0xD2, 0x01, 0x25, 0x29, 0x1C, 0x00, 0x29, 0x22, 0xD0, 0x70, 0x68, 0x65, 0x46
    .byte 0x85, 0x42, 0x09, 0xD0, 0x00, 0x20, 0x84, 0x46, 0x28, 0x69, 0x82, 0x42, 0x01, 0xD2, 0x01, 0x20
    .byte 0x84, 0x46, 0x60, 0x46, 0x00, 0x28, 0x14, 0xD0, 0xD8, 0x68, 0x00, 0x28, 0x07, 0xD1, 0x00, 0x94
    .byte 0x01, 0x93, 0x38, 0x1C, 0x31, 0x1C, 0x00, 0x22, 0xFF, 0xF7, 0x6C, 0xFE, 0x15, 0xE0, 0x00, 0x94
    .byte 0x00, 0x20, 0x01, 0x90, 0x38, 0x1C, 0x31, 0x1C, 0x2A, 0x1C, 0x2B, 0x1C, 0xFF, 0xF7, 0x62, 0xFE
    .byte 0x0B, 0xE0, 0x89, 0x45, 0x02, 0xD1, 0x41, 0x46, 0x08, 0x68, 0x05, 0xE0, 0x04, 0xA8, 0x31, 0x1C
    .byte 0x22, 0x1C, 0xFF, 0xF7, 0xD5, 0xFE, 0x04, 0x98, 0x38, 0x60, 0x38, 0x1C, 0x06, 0xB0, 0x18, 0xBC
    .byte 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .global func_080E25FC
    .thumb_func
func_080E25FC:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    mov r8, r1
    adds r7, r5, #0
    ldr r1, [r7, #8]
    cmp r1, #0
    beq .Lauto_080E1DC4
    ldr r0, [r7, #0xc]
    cmp r0, #0
    bne .Lauto_080E1DB8
    adds r6, r1, #0
    b .Lauto_080E1DC6
    .Lauto_080E1DB8:
    adds r7, r0, #0
    b .Lauto_080E1DBE
    .Lauto_080E1DBC:
    ldr r7, [r7, #8]
    .Lauto_080E1DBE:
    ldr r0, [r7, #8]
    cmp r0, #0
    bne .Lauto_080E1DBC
    .Lauto_080E1DC4:
    ldr r6, [r7, #0xc]
    .Lauto_080E1DC6:
    cmp r7, r5
    beq .Lauto_080E1E1A
    ldr r0, [r5, #8]
    str r7, [r0, #4]
    ldr r0, [r5, #8]
    str r0, [r7, #8]
    ldr r0, [r5, #0xc]
    cmp r7, r0
    beq .Lauto_080E1DEE
    ldr r4, [r7, #4]
    cmp r6, #0
    beq .Lauto_080E1DE0
    str r4, [r6, #4]
    .Lauto_080E1DE0:
    ldr r0, [r7, #4]
    str r6, [r0, #8]
    ldr r0, [r5, #0xc]
    str r0, [r7, #0xc]
    ldr r0, [r5, #0xc]
    str r7, [r0, #4]
    b .Lauto_080E1DF0
    .Lauto_080E1DEE:
    adds r4, r7, #0
    .Lauto_080E1DF0:
    mov r1, r8
    ldr r0, [r1]
    cmp r0, r5
    bne .Lauto_080E1DFC
    str r7, [r1]
    b .Lauto_080E1E0A
    .Lauto_080E1DFC:
    ldr r1, [r5, #4]
    ldr r0, [r1, #8]
    cmp r0, r5
    bne .Lauto_080E1E08
    str r7, [r1, #8]
    b .Lauto_080E1E0A
    .Lauto_080E1E08:
    str r7, [r1, #0xc]
    .Lauto_080E1E0A:
    ldr r0, [r5, #4]
    str r0, [r7, #4]
    ldrb r1, [r7]
    ldrb r0, [r5]
    strb r0, [r7]
    strb r1, [r5]
    adds r7, r5, #0
    b .Lauto_080E1E84
    .Lauto_080E1E1A:
    ldr r4, [r7, #4]
    cmp r6, #0
    beq .Lauto_080E1E22
    str r4, [r6, #4]
    .Lauto_080E1E22:
    mov r1, r8
    ldr r0, [r1]
    cmp r0, r7
    bne .Lauto_080E1E2E
    str r6, [r1]
    b .Lauto_080E1E3C
    .Lauto_080E1E2E:
    ldr r1, [r7, #4]
    ldr r0, [r1, #8]
    cmp r0, r7
    bne .Lauto_080E1E3A
    str r6, [r1, #8]
    b .Lauto_080E1E3C
    .Lauto_080E1E3A:
    str r6, [r1, #0xc]
    .Lauto_080E1E3C:
    ldr r0, [r2]
    cmp r0, r5
    bne .Lauto_080E1E60
    ldr r0, [r5, #0xc]
    cmp r0, #0
    bne .Lauto_080E1E4E
    ldr r0, [r5, #4]
    str r0, [r2]
    b .Lauto_080E1E60
    .Lauto_080E1E4E:
    adds r1, r6, #0
    ldr r0, [r6, #8]
    cmp r0, #0
    beq .Lauto_080E1E5E
    .Lauto_080E1E56:
    ldr r1, [r1, #8]
    ldr r0, [r1, #8]
    cmp r0, #0
    bne .Lauto_080E1E56
    .Lauto_080E1E5E:
    str r1, [r2]
    .Lauto_080E1E60:
    ldr r0, [r3]
    cmp r0, r5
    bne .Lauto_080E1E84
    ldr r0, [r5, #8]
    cmp r0, #0
    bne .Lauto_080E1E72
    ldr r0, [r5, #4]
    str r0, [r3]
    b .Lauto_080E1E84
    .Lauto_080E1E72:
    adds r1, r6, #0
    ldr r0, [r6, #0xc]
    cmp r0, #0
    beq .Lauto_080E1E82
    .Lauto_080E1E7A:
    ldr r1, [r1, #0xc]
    ldr r0, [r1, #0xc]
    cmp r0, #0
    bne .Lauto_080E1E7A
    .Lauto_080E1E82:
    str r1, [r3]
    .Lauto_080E1E84:
    ldrb r0, [r7]
    cmp r0, #0
    bne .Lauto_080E1E8C
    b .Lauto_080E1F90
    .Lauto_080E1E8C:
    b .Lauto_080E1F76
    .Lauto_080E1E8E:
    ldr r0, [r4, #8]
    cmp r6, r0
    bne .Lauto_080E1F00
    ldr r2, [r4, #0xc]
    ldrb r1, [r2]
    cmp r1, #0
    bne .Lauto_080E1EAC
    movs r0, #1
    strb r0, [r2]
    strb r1, [r4]
    adds r0, r4, #0
    mov r1, r8
    bl func_080E2170
    ldr r2, [r4, #0xc]
    .Lauto_080E1EAC:
    ldr r3, [r2, #8]
    cmp r3, #0
    beq .Lauto_080E1EBA
    ldrb r0, [r3]
    ldr r1, [r2, #0xc]
    cmp r0, #1
    bne .Lauto_080E1EC6
    .Lauto_080E1EBA:
    ldr r1, [r2, #0xc]
    cmp r1, #0
    beq .Lauto_080E1F32
    ldrb r0, [r1]
    cmp r0, #1
    beq .Lauto_080E1F32
    .Lauto_080E1EC6:
    cmp r1, #0
    beq .Lauto_080E1ED0
    ldrb r0, [r1]
    cmp r0, #1
    bne .Lauto_080E1EE6
    .Lauto_080E1ED0:
    cmp r3, #0
    beq .Lauto_080E1ED8
    movs r0, #1
    strb r0, [r3]
    .Lauto_080E1ED8:
    movs r0, #0
    strb r0, [r2]
    adds r0, r2, #0
    mov r1, r8
    bl func_080E21A8
    ldr r2, [r4, #0xc]
    .Lauto_080E1EE6:
    ldrb r0, [r4]
    strb r0, [r2]
    movs r1, #1
    strb r1, [r4]
    ldr r0, [r2, #0xc]
    cmp r0, #0
    beq .Lauto_080E1EF6
    strb r1, [r0]
    .Lauto_080E1EF6:
    adds r0, r4, #0
    mov r1, r8
    bl func_080E2170
    b .Lauto_080E1F88
    .Lauto_080E1F00:
    adds r2, r0, #0
    ldrb r1, [r2]
    cmp r1, #0
    bne .Lauto_080E1F18
    movs r0, #1
    strb r0, [r2]
    strb r1, [r4]
    adds r0, r4, #0
    mov r1, r8
    bl func_080E21A8
    ldr r2, [r4, #8]
    .Lauto_080E1F18:
    ldr r3, [r2, #0xc]
    cmp r3, #0
    beq .Lauto_080E1F26
    ldrb r0, [r3]
    ldr r1, [r2, #8]
    cmp r0, #1
    bne .Lauto_080E1F3C
    .Lauto_080E1F26:
    ldr r1, [r2, #8]
    cmp r1, #0
    beq .Lauto_080E1F32
    ldrb r0, [r1]
    cmp r0, #1
    bne .Lauto_080E1F3C
    .Lauto_080E1F32:
    movs r0, #0
    strb r0, [r2]
    adds r6, r4, #0
    ldr r4, [r6, #4]
    b .Lauto_080E1F76
    .Lauto_080E1F3C:
    cmp r1, #0
    beq .Lauto_080E1F46
    ldrb r0, [r1]
    cmp r0, #1
    bne .Lauto_080E1F5C
    .Lauto_080E1F46:
    cmp r3, #0
    beq .Lauto_080E1F4E
    movs r0, #1
    strb r0, [r3]
    .Lauto_080E1F4E:
    movs r0, #0
    strb r0, [r2]
    adds r0, r2, #0
    mov r1, r8
    bl func_080E2170
    ldr r2, [r4, #8]
    .Lauto_080E1F5C:
    ldrb r0, [r4]
    strb r0, [r2]
    movs r1, #1
    strb r1, [r4]
    ldr r0, [r2, #8]
    cmp r0, #0
    beq .Lauto_080E1F6C
    strb r1, [r0]
    .Lauto_080E1F6C:
    adds r0, r4, #0
    mov r1, r8
    bl func_080E21A8
    b .Lauto_080E1F88
    .Lauto_080E1F76:
    mov r1, r8
    ldr r0, [r1]
    cmp r6, r0
    beq .Lauto_080E1F88
    cmp r6, #0
    beq .Lauto_080E1E8E
    ldrb r0, [r6]
    cmp r0, #1
    beq .Lauto_080E1E8E
    .Lauto_080E1F88:
    cmp r6, #0
    beq .Lauto_080E1F90
    movs r0, #1
    strb r0, [r6]
    .Lauto_080E1F90:
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0xF0, 0xB5, 0x07, 0x1C, 0x0E, 0x1C, 0x05, 0x9C, 0x1D, 0x1C, 0x70, 0x68, 0x85, 0x42, 0x0C, 0xD0
    .byte 0x06, 0x98, 0x00, 0x28, 0x29, 0xD1, 0x00, 0x2A, 0x07, 0xD1, 0x00, 0x22, 0x21, 0x68, 0x28, 0x69
    .byte 0x81, 0x42, 0x00, 0xD2, 0x01, 0x22, 0x00, 0x2A, 0x1F, 0xD0, 0x18, 0x20, 0xED, 0xF7, 0x58, 0xFD
    .byte 0x02, 0x1C, 0x00, 0x2A, 0x03, 0xD1, 0x18, 0x20, 0xF1, 0xF7, 0xD0, 0xF9, 0x02, 0x1C, 0x11, 0x1C
    .byte 0x10, 0x31, 0x00, 0x29, 0x03, 0xD0, 0x20, 0x68, 0x10, 0x61, 0x60, 0x68, 0x48, 0x60, 0x14, 0x1C
    .byte 0xAC, 0x60, 0x71, 0x68, 0x8D, 0x42, 0x03, 0xD1, 0x6C, 0x60, 0x70, 0x68, 0xC4, 0x60, 0x1D, 0xE0
    .byte 0x88, 0x68, 0x85, 0x42, 0x1A, 0xD1, 0x8C, 0x60, 0x18, 0xE0, 0x18, 0x20, 0xED, 0xF7, 0x38, 0xFD
    .byte 0x02, 0x1C, 0x00, 0x2A, 0x03, 0xD1, 0x18, 0x20, 0xF1, 0xF7, 0xB0, 0xF9, 0x02, 0x1C, 0x11, 0x1C
    .byte 0x10, 0x31, 0x00, 0x29, 0x03, 0xD0, 0x20, 0x68, 0x10, 0x61, 0x60, 0x68, 0x48, 0x60, 0x14, 0x1C
    .byte 0xEC, 0x60, 0x71, 0x68, 0xC8, 0x68, 0x85, 0x42, 0x00, 0xD1, 0xCC, 0x60, 0x65, 0x60, 0x00, 0x20
    .byte 0xA0, 0x60, 0xE0, 0x60, 0x71, 0x68, 0x04, 0x31, 0x20, 0x1C, 0xFF, 0xF7, 0x9B, 0xFC, 0xB0, 0x68
    .byte 0x01, 0x30, 0xB0, 0x60, 0x3C, 0x60, 0x38, 0x1C, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x85, 0xB0, 0x06, 0x1C, 0x88, 0x46, 0x17, 0x1C, 0x4C, 0x68
    .byte 0x65, 0x68, 0x01, 0x20, 0x00, 0x2D, 0x0E, 0xD0, 0x3A, 0x68, 0x2C, 0x1C, 0x00, 0x21, 0x20, 0x69
    .byte 0x82, 0x42, 0x00, 0xD2, 0x01, 0x21, 0x08, 0x1C, 0x00, 0x28, 0x01, 0xD0, 0xA5, 0x68, 0x00, 0xE0
    .byte 0xE5, 0x68, 0x00, 0x2D, 0xF1, 0xD1, 0x02, 0x94, 0x00, 0x28, 0x19, 0xD0, 0x41, 0x46, 0x48, 0x68
    .byte 0x80, 0x68, 0x03, 0x90, 0x00, 0x21, 0x84, 0x42, 0x00, 0xD1, 0x01, 0x21, 0x00, 0x29, 0x0B, 0xD0
    .byte 0x00, 0x97, 0x00, 0x20, 0x01, 0x90, 0x04, 0xA8, 0x41, 0x46, 0x2A, 0x1C, 0x23, 0x1C, 0xFF, 0xF7
    .byte 0x6F, 0xFF, 0x01, 0x21, 0x04, 0x98, 0x18, 0xE0, 0x20, 0x1C, 0xFF, 0xF7, 0x15, 0xFD, 0x02, 0x90
    .byte 0x02, 0x9A, 0x00, 0x23, 0x11, 0x69, 0x38, 0x68, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x18, 0x1C
    .byte 0x00, 0x28, 0x0D, 0xD0, 0x00, 0x97, 0x00, 0x20, 0x01, 0x90, 0x03, 0xA8, 0x41, 0x46, 0x2A, 0x1C
    .byte 0x23, 0x1C, 0xFF, 0xF7, 0x55, 0xFF, 0x01, 0x21, 0x03, 0x98, 0x30, 0x60, 0x31, 0x71, 0x01, 0xE0
    .byte 0x32, 0x60, 0x30, 0x71, 0x30, 0x1C, 0x05, 0xB0, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x86, 0xB0, 0x07, 0x1C
    .byte 0x0E, 0x1C, 0x90, 0x46, 0x1C, 0x1C, 0x71, 0x68, 0x12, 0x68, 0x88, 0x68, 0x82, 0x42, 0x39, 0xD1
    .byte 0xB0, 0x68, 0x00, 0x28, 0x06, 0xD1, 0x02, 0xA8, 0x31, 0x1C, 0x22, 0x1C, 0xFF, 0xF7, 0x90, 0xFF
    .byte 0x02, 0x98, 0xB9, 0xE0, 0x00, 0x20, 0x11, 0x69, 0x13, 0x1C, 0x22, 0x68, 0x8A, 0x42, 0x00, 0xD2
    .byte 0x01, 0x20, 0x81, 0x46, 0x00, 0x28, 0x5F, 0xD1, 0x00, 0x20, 0x91, 0x42, 0x00, 0xD2, 0x01, 0x20
    .byte 0x00, 0x28, 0x01, 0xD1, 0x3B, 0x60, 0xA8, 0xE0, 0x02, 0x93, 0x18, 0x1C, 0x00, 0xF0, 0xAE, 0xF8
    .byte 0x02, 0x1C, 0x02, 0x92, 0x70, 0x68, 0x82, 0x42, 0x02, 0xD1, 0x40, 0x46, 0x03, 0x68, 0x7E, 0xE0
    .byte 0x00, 0x23, 0x21, 0x68, 0x10, 0x69, 0x15, 0x1C, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x00, 0x2B
    .byte 0x00, 0xD1, 0x8B, 0xE0, 0x41, 0x46, 0x0B, 0x68, 0xD8, 0x68, 0x00, 0x28, 0x6F, 0xD0, 0x00, 0x94
    .byte 0x48, 0x46, 0x76, 0xE0, 0x8A, 0x42, 0x12, 0xD1, 0xD3, 0x68, 0x00, 0x25, 0x19, 0x69, 0x20, 0x68
    .byte 0x81, 0x42, 0x00, 0xD2, 0x01, 0x25, 0x00, 0x2D, 0x02, 0xD0, 0x00, 0x94, 0x01, 0x92, 0x60, 0xE0
    .byte 0x02, 0xA8, 0x31, 0x1C, 0x22, 0x1C, 0xFF, 0xF7, 0x4B, 0xFF, 0x02, 0x98, 0x74, 0xE0, 0x02, 0x92
    .byte 0x10, 0x1C, 0xFF, 0xF7, 0x91, 0xFC, 0x02, 0x1C, 0x02, 0x92, 0x41, 0x46, 0x0B, 0x68, 0x00, 0x25
    .byte 0x21, 0x68, 0x18, 0x69, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x25, 0xA9, 0x46, 0x00, 0x2D, 0x1C, 0xD0
    .byte 0x00, 0x20, 0x84, 0x46, 0x10, 0x69, 0x15, 0x1C, 0x88, 0x42, 0x01, 0xD2, 0x01, 0x21, 0x8C, 0x46
    .byte 0x60, 0x46, 0x00, 0x28, 0x11, 0xD0, 0xE8, 0x68, 0x00, 0x28, 0x05, 0xD1, 0x00, 0x94, 0x01, 0x95
    .byte 0x38, 0x1C, 0x31, 0x1C, 0x00, 0x22, 0x40, 0xE0, 0x00, 0x94, 0x00, 0x20, 0x01, 0x90, 0x38, 0x1C
    .byte 0x31, 0x1C, 0x1A, 0x1C, 0xFF, 0xF7, 0xBC, 0xFE, 0x47, 0xE0, 0x41, 0x46, 0x08, 0x68, 0x03, 0x90
    .byte 0x00, 0xF0, 0x4C, 0xF8, 0x84, 0x46, 0x03, 0x90, 0x01, 0x20, 0x49, 0x46, 0x41, 0x40, 0x48, 0x46
    .byte 0x00, 0x28, 0x2E, 0xD1, 0x41, 0x46, 0x08, 0x68, 0x00, 0x25, 0x01, 0x69, 0x03, 0x1C, 0x22, 0x68
    .byte 0x91, 0x42, 0x00, 0xD2, 0x01, 0x25, 0x29, 0x1C, 0x00, 0x29, 0x22, 0xD0, 0x70, 0x68, 0x65, 0x46
    .byte 0x85, 0x42, 0x09, 0xD0, 0x00, 0x20, 0x84, 0x46, 0x28, 0x69, 0x82, 0x42, 0x01, 0xD2, 0x01, 0x20
    .byte 0x84, 0x46, 0x60, 0x46, 0x00, 0x28, 0x14, 0xD0, 0xD8, 0x68, 0x00, 0x28, 0x07, 0xD1, 0x00, 0x94
    .byte 0x01, 0x93, 0x38, 0x1C, 0x31, 0x1C, 0x00, 0x22, 0xFF, 0xF7, 0x8A, 0xFE, 0x15, 0xE0, 0x00, 0x94
    .byte 0x00, 0x20, 0x01, 0x90, 0x38, 0x1C, 0x31, 0x1C, 0x2A, 0x1C, 0x2B, 0x1C, 0xFF, 0xF7, 0x80, 0xFE
    .byte 0x0B, 0xE0, 0x89, 0x45, 0x02, 0xD1, 0x41, 0x46, 0x08, 0x68, 0x05, 0xE0, 0x04, 0xA8, 0x31, 0x1C
    .byte 0x22, 0x1C, 0xFF, 0xF7, 0xD5, 0xFE, 0x04, 0x98, 0x38, 0x60, 0x38, 0x1C, 0x06, 0xB0, 0x18, 0xBC
    .byte 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .global func_080E2B28
    .thumb_func
func_080E2B28:
    push {lr}
    adds r1, r0, #0
    ldr r0, [r1, #0xc]
    cmp r0, #0
    beq .Lauto_080E22E6
    adds r1, r0, #0
    ldr r0, [r1, #8]
    cmp r0, #0
    beq .Lauto_080E22F6
    .Lauto_080E22DA:
    ldr r1, [r1, #8]
    ldr r0, [r1, #8]
    cmp r0, #0
    bne .Lauto_080E22DA
    b .Lauto_080E22F6
    .Lauto_080E22E4:
    adds r1, r2, #0
    .Lauto_080E22E6:
    ldr r2, [r1, #4]
    ldr r0, [r2, #0xc]
    cmp r1, r0
    beq .Lauto_080E22E4
    ldr r0, [r1, #0xc]
    cmp r0, r2
    beq .Lauto_080E22F6
    adds r1, r2, #0
    .Lauto_080E22F6:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .global loc_080E22FC
    .thumb_func
    loc_080E22FC:
    .Lauto_080E22FC:
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r4, r1, #0
    cmp r4, #0
    beq .Lauto_080E2320
    .Lauto_080E2306:
    ldr r1, [r4, #0xc]
    adds r0, r6, #0
    bl .Lauto_080E22FC
    ldr r5, [r4, #8]
    cmp r4, #0
    beq .Lauto_080E231A
    adds r0, r4, #0
    bl free
    .Lauto_080E231A:
    adds r4, r5, #0
    cmp r4, #0
    bne .Lauto_080E2306
    .Lauto_080E2320:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global loc_080E2328
    .thumb_func
    loc_080E2328:
    .Lauto_080E2328:
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r4, r1, #0
    cmp r4, #0
    beq .Lauto_080E234C
    .Lauto_080E2332:
    ldr r1, [r4, #0xc]
    adds r0, r6, #0
    bl .Lauto_080E2328
    ldr r5, [r4, #8]
    cmp r4, #0
    beq .Lauto_080E2346
    adds r0, r4, #0
    bl free
    .Lauto_080E2346:
    adds r4, r5, #0
    cmp r4, #0
    bne .Lauto_080E2332
    .Lauto_080E234C:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00

    .global func_080E2BB4
    .thumb_func
func_080E2BB4:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov sl, r0
    str r1, [sp, #0x10]
    str r3, [sp, #0x14]
    ldr r0, [r2, #8]
    str r0, [sp, #0x18]
    ldr r1, [r2, #0x10]
    str r1, [sp, #0x1c]
    ldr r3, [r2]
    movs r0, #0
    cmp r3, #0
    beq .Lauto_080E2378
    ldrh r0, [r2, #4]
    .Lauto_080E2378:
    lsls r0, r0, #3
    adds r0, r3, r0
    str r0, [sp, #0x20]
    cmp r3, r0
    bne .Lauto_080E2384
    b .Lauto_080E2542
    .Lauto_080E2384:
    ldm r3!, {r0, r1}
    str r0, [sp]
    str r1, [sp, #4]
    ldr r2, [sp]
    lsls r0, r2, #7
    asrs r6, r0, #0x17
    ldr r0, [sp, #0x14]
    adds r6, r6, r0
    str r3, [sp, #0x24]
    cmp r6, #0xef
    ble .Lauto_080E239C
    b .Lauto_080E2538
    .Lauto_080E239C:
    mov r0, sp
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov r8, r0
    ldr r1, [sp, #0x48]
    add r8, r1
    mov r0, r8
    cmp r0, #0x9f
    ble .Lauto_080E23B2
    .byte 0xC2, 0xE0
    .Lauto_080E23B2:
    lsls r1, r2, #0x10
    lsrs r1, r1, #0x1e
    lsls r1, r1, #2
    lsrs r0, r2, #0x1e
    adds r1, r1, r0
    .byte 0x19, 0x4A, 0x48, 0x08, 0x80, 0x18, 0x02, 0x78, 0x01, 0x20, 0x01, 0x40, 0x89, 0x00, 0x0A, 0x41
    .byte 0x03, 0x23, 0x11, 0x1C, 0x19, 0x40, 0x08, 0x24, 0x20, 0x1C, 0x88, 0x40, 0x30, 0x18, 0x00, 0x28
    .byte 0x00, 0xDC, 0xAB, 0xE0, 0x91, 0x08, 0x19, 0x40, 0x20, 0x1C, 0x88, 0x40, 0x40, 0x44, 0x00, 0x28
    .byte 0x00, 0xDC, 0xA3, 0xE0, 0x01, 0x98, 0x80, 0x05, 0x40, 0x0C, 0x06, 0x99, 0x08, 0x18, 0x02, 0x90
    .byte 0x51, 0x46, 0x04, 0x31, 0x02, 0xAF, 0x4C, 0x68, 0x62, 0x68, 0x8C, 0x46, 0x00, 0x2A, 0x10, 0xD0
    .byte 0x05, 0x1C, 0x00, 0x23, 0x10, 0x69, 0xA8, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x00, 0x2B, 0x05, 0xD1
    .byte 0x14, 0x1C, 0xA2, 0x68, 0x03, 0xE0, 0x00, 0x00
    .word gCodeLinkoncePackedCellSizeLookup
    .byte 0xD2, 0x68, 0x00, 0x2A
    .byte 0xEF, 0xD1, 0x4B, 0x68, 0x9C, 0x42, 0x07, 0xD0, 0x00, 0x22, 0x39, 0x68, 0x20, 0x69, 0x81, 0x42
    .byte 0x00, 0xD2, 0x01, 0x22, 0x00, 0x2A, 0x00, 0xD0, 0x1C, 0x1C, 0x60, 0x46, 0x41, 0x68, 0x61, 0x40
    .byte 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x04, 0xDA, 0x61, 0x69, 0x50, 0x46
    bl GetObjTileIndex
    .byte 0x01, 0xE0, 0x01, 0x20, 0x40, 0x42, 0x81, 0x46, 0x00, 0x28, 0x67, 0xDB, 0x01, 0x98, 0x00, 0x04
    .byte 0x00, 0x0F, 0x40, 0x01, 0x07, 0x99, 0x08, 0x18, 0x03, 0x90, 0x51, 0x46, 0x18, 0x31, 0x03, 0xAF
    .byte 0x4C, 0x68, 0x62, 0x68, 0x8C, 0x46, 0x00, 0x2A, 0x0D, 0xD0, 0x05, 0x1C, 0x00, 0x23, 0x10, 0x69
    .byte 0xA8, 0x42, 0x00, 0xD2, 0x01, 0x23, 0x00, 0x2B, 0x02, 0xD1, 0x14, 0x1C, 0xA2, 0x68, 0x00, 0xE0
    .byte 0xD2, 0x68, 0x00, 0x2A, 0xF2, 0xD1, 0x4B, 0x68, 0x9C, 0x42, 0x07, 0xD0, 0x00, 0x22, 0x39, 0x68
    .byte 0x20, 0x69, 0x81, 0x42, 0x00, 0xD2, 0x01, 0x22, 0x00, 0x2A, 0x00, 0xD0, 0x1C, 0x1C, 0x60, 0x46
    .byte 0x41, 0x68, 0x61, 0x40, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x06, 0xDA, 0x61, 0x69, 0x50, 0x46
    .byte 0x14, 0x30
    bl GetObjPaletteBank
    .byte 0x04, 0x1C, 0x01, 0xE0, 0x01, 0x24, 0x64, 0x42, 0x00, 0x2C
    .byte 0x2C, 0xDB, 0x41, 0x46, 0x08, 0x06, 0x00, 0x0E, 0x1B, 0x49, 0x00, 0x9B, 0x0B, 0x40, 0x03, 0x43
    .byte 0x1A, 0x48, 0x06, 0x40, 0x31, 0x04, 0x1A, 0x48, 0x03, 0x40, 0x0B, 0x43, 0x00, 0x93, 0x49, 0x46
    .byte 0x88, 0x05, 0x80, 0x0D, 0x17, 0x49, 0x6D, 0x46, 0x01, 0x9A, 0x0A, 0x40, 0x02, 0x43, 0x20, 0x04
    .byte 0x00, 0x0C, 0x0F, 0x21, 0x08, 0x40, 0x00, 0x03, 0x13, 0x49, 0x0A, 0x40, 0x02, 0x43, 0x01, 0x92
    .byte 0x04, 0x98, 0x02, 0x78, 0x7F, 0x2A, 0x09, 0xD8, 0xD0, 0x00, 0x04, 0x30, 0x04, 0x99, 0x08, 0x18
    .byte 0x03, 0x60, 0xA9, 0x88, 0x81, 0x80, 0x50, 0x1C, 0x04, 0x99, 0x08, 0x70
    .Lauto_080E2538:
    ldr r3, [sp, #0x24]
    ldr r0, [sp, #0x20]
    cmp r3, r0
    beq .Lauto_080E2542
    b .Lauto_080E2384
    .Lauto_080E2542:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFE, 0x00, 0xFC
    .byte 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF
    .global func_080E2568
    .thumb_func
func_080E2568:
    push {r4, r5, r6, lr}
    sub sp, #0x10
    adds r6, r0, #0
    bl InitializeObjTilePoolOwner
    adds r4, r6, #4
    movs r5, #0
    str r5, [r4, #4]
    movs r0, #0x18
    bl malloc
    cmp r0, #0
    bne .Lauto_080E2588
    movs r0, #0x18
    bl RetryMemoryAllocation
    .Lauto_080E2588:
    str r0, [r4, #4]
    str r5, [r4, #8]
    str r5, [r4, #0xc]
    strb r5, [r0]
    str r5, [r0, #4]
    ldr r0, [r4, #4]
    str r0, [r0, #8]
    ldr r0, [r4, #4]
    str r0, [r0, #0xc]
    adds r0, r6, #0
    adds r0, #0x14
    bl ConstructObjPalettePoolOwner
    adds r4, r6, #0
    adds r4, #0x18
    str r5, [r4, #4]
    movs r0, #0x18
    bl malloc
    cmp r0, #0
    bne .Lauto_080E25B8
    movs r0, #0x18
    bl RetryMemoryAllocation
    .Lauto_080E25B8:
    str r0, [r4, #4]
    str r5, [r4, #8]
    str r5, [r4, #0xc]
    strb r5, [r0]
    str r5, [r0, #4]
    ldr r0, [r4, #4]
    str r0, [r0, #8]
    ldr r0, [r4, #4]
    str r0, [r0, #0xc]
    adds r0, r6, #0
    add sp, #0x10
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    @ Exact JP entry point referenced by the JP-only raw table at 0x080E6FAC.
    .global func_080E25D4
    .thumb_func
func_080E25D4:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0xc]
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .Lauto_080E25F4
    ldr r2, [pc, #0x20]
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E25F4:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15HardwareContext
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23IndexedResourceProvider
    .byte 0xB4, 0x05, 0x00, 0x00
    .section .text.after_staff_credits_core_destructor, "ax", %progbits
    .align 2, 0

    .global loc_080E2618
    .thumb_func
    loc_080E2618:
    .Lauto_080E2618:
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r4, r1, #0
    cmp r4, #0
    beq .Lauto_080E263C
    .Lauto_080E2622:
    ldr r1, [r4, #0xc]
    adds r0, r6, #0
    bl .Lauto_080E2618
    ldr r5, [r4, #8]
    cmp r4, #0
    beq .Lauto_080E2636
    adds r0, r4, #0
    bl free
    .Lauto_080E2636:
    adds r4, r5, #0
    cmp r4, #0
    bne .Lauto_080E2622
    .Lauto_080E263C:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E2EA4
    .thumb_func
func_080E2EA4:
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r6, r1, #0
    ldr r4, [sp, #0x14]
    adds r5, r3, #0
    ldr r0, [r6, #4]
    cmp r5, r0
    beq .Lauto_080E267E
    ldr r0, [sp, #0x18]
    cmp r0, #0
    bne .Lauto_080E26BE
    cmp r2, #0
    bne .Lauto_080E267E
    adds r2, r5, #0
    adds r2, #0x10
    movs r3, #0
    ldrb r1, [r4]
    ldrb r0, [r5, #0x10]
    cmp r1, r0
    blo .Lauto_080E2678
    cmp r0, r1
    blo .Lauto_080E267A
    ldrb r0, [r4, #1]
    ldrb r2, [r2, #1]
    cmp r0, r2
    bhs .Lauto_080E267A
    .Lauto_080E2678:
    movs r3, #1
    .Lauto_080E267A:
    cmp r3, #0
    beq .Lauto_080E26BE
    .Lauto_080E267E:
    movs r0, #0x18
    bl malloc
    adds r1, r0, #0
    cmp r1, #0
    bne .Lauto_080E2692
    movs r0, #0x18
    bl RetryMemoryAllocation
    adds r1, r0, #0
    .Lauto_080E2692:
    adds r2, r1, #0
    adds r2, #0x10
    cmp r2, #0
    beq .Lauto_080E26A2
    ldr r0, [r4]
    str r0, [r1, #0x10]
    ldrb r0, [r4, #4]
    strb r0, [r2, #4]
    .Lauto_080E26A2:
    adds r4, r1, #0
    str r4, [r5, #8]
    ldr r1, [r6, #4]
    cmp r5, r1
    bne .Lauto_080E26B4
    str r4, [r5, #4]
    ldr r0, [r6, #4]
    str r4, [r0, #0xc]
    b .Lauto_080E26F0
    .Lauto_080E26B4:
    ldr r0, [r1, #8]
    cmp r5, r0
    bne .Lauto_080E26F0
    str r4, [r1, #8]
    b .Lauto_080E26F0
    .Lauto_080E26BE:
    movs r0, #0x18
    bl malloc
    adds r1, r0, #0
    cmp r1, #0
    bne .Lauto_080E26D2
    movs r0, #0x18
    bl RetryMemoryAllocation
    adds r1, r0, #0
    .Lauto_080E26D2:
    adds r2, r1, #0
    adds r2, #0x10
    cmp r2, #0
    beq .Lauto_080E26E2
    ldr r0, [r4]
    str r0, [r1, #0x10]
    ldrb r0, [r4, #4]
    strb r0, [r2, #4]
    .Lauto_080E26E2:
    adds r4, r1, #0
    str r4, [r5, #0xc]
    ldr r1, [r6, #4]
    ldr r0, [r1, #0xc]
    cmp r5, r0
    bne .Lauto_080E26F0
    str r4, [r1, #0xc]
    .Lauto_080E26F0:
    str r5, [r4, #4]
    movs r0, #0
    str r0, [r4, #8]
    str r0, [r4, #0xc]
    ldr r1, [r6, #4]
    adds r1, #4
    adds r0, r4, #0
    bl func_080E21E0
    ldr r0, [r6, #8]
    adds r0, #1
    str r0, [r6, #8]
    str r4, [r7]
    adds r0, r7, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E2F74
    .thumb_func
func_080E2F74:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x14
    adds r7, r0, #0
    mov r8, r1
    adds r6, r2, #0
    ldr r5, [r1, #4]
    ldr r4, [r5, #4]
    movs r0, #1
    cmp r4, #0
    beq .Lauto_080E275C
    ldrb r2, [r6]
    .Lauto_080E2730:
    adds r5, r4, #0
    adds r1, r5, #0
    adds r1, #0x10
    movs r3, #0
    ldrb r0, [r5, #0x10]
    cmp r2, r0
    blo .Lauto_080E274A
    cmp r0, r2
    blo .Lauto_080E274C
    ldrb r0, [r6, #1]
    ldrb r1, [r1, #1]
    cmp r0, r1
    bhs .Lauto_080E274C
    .Lauto_080E274A:
    movs r3, #1
    .Lauto_080E274C:
    adds r0, r3, #0
    cmp r0, #0
    beq .Lauto_080E2756
    ldr r4, [r4, #8]
    b .Lauto_080E2758
    .Lauto_080E2756:
    ldr r4, [r4, #0xc]
    .Lauto_080E2758:
    cmp r4, #0
    bne .Lauto_080E2730
    .Lauto_080E275C:
    str r5, [sp, #8]
    cmp r0, #0
    beq .Lauto_080E2796
    mov r1, r8
    ldr r0, [r1, #4]
    ldr r0, [r0, #8]
    str r0, [sp, #0xc]
    movs r1, #0
    cmp r5, r0
    bne .Lauto_080E2772
    movs r1, #1
    .Lauto_080E2772:
    cmp r1, #0
    beq .Lauto_080E278E
    str r6, [sp]
    movs r0, #0
    str r0, [sp, #4]
    add r0, sp, #0x10
    mov r1, r8
    adds r2, r4, #0
    adds r3, r5, #0
    bl func_080E2EA4
    movs r1, #1
    ldr r0, [sp, #0x10]
    b .Lauto_080E27D6
    .Lauto_080E278E:
    adds r0, r5, #0
    bl func_080E2354
    str r0, [sp, #8]
    .Lauto_080E2796:
    ldr r0, [sp, #8]
    adds r3, r0, #0
    adds r3, #0x10
    movs r1, #0
    mov sb, r1
    ldrb r2, [r0, #0x10]
    ldrb r1, [r6]
    mov ip, r0
    cmp r2, r1
    blo .Lauto_080E27B6
    cmp r1, r2
    blo .Lauto_080E27BA
    ldrb r0, [r3, #1]
    ldrb r1, [r6, #1]
    cmp r0, r1
    bhs .Lauto_080E27BA
    .Lauto_080E27B6:
    movs r0, #1
    mov sb, r0
    .Lauto_080E27BA:
    mov r0, sb
    cmp r0, #0
    beq .Lauto_080E27DC
    str r6, [sp]
    movs r0, #0
    str r0, [sp, #4]
    add r0, sp, #0xc
    mov r1, r8
    adds r2, r4, #0
    adds r3, r5, #0
    bl func_080E2EA4
    movs r1, #1
    ldr r0, [sp, #0xc]
    .Lauto_080E27D6:
    str r0, [r7]
    strb r1, [r7, #4]
    b .Lauto_080E27E2
    .Lauto_080E27DC:
    mov r1, ip
    str r1, [r7]
    strb r0, [r7, #4]
    .Lauto_080E27E2:
    adds r0, r7, #0
    add sp, #0x14
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E3054
    .thumb_func
func_080E3054:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x20
    adds r7, r0, #0
    adds r6, r1, #0
    mov sl, r2
    adds r4, r3, #0
    ldr r1, [r6, #4]
    ldr r2, [r2]
    ldr r0, [r1, #8]
    cmp r2, r0
    bne .Lauto_080E28EC
    ldr r0, [r6, #8]
    cmp r0, #0
    bne .Lauto_080E2826
    add r0, sp, #8
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_080E2F74
    ldr r0, [sp, #8]
    b .Lauto_080E2A72
    .Lauto_080E2826:
    movs r0, #0x10
    adds r0, r0, r2
    mov ip, r0
    movs r1, #0
    mov sb, r1
    ldrb r0, [r4]
    adds r3, r0, #0
    ldrb r1, [r2, #0x10]
    adds r5, r2, #0
    mov r8, r0
    cmp r3, r1
    blo .Lauto_080E284C
    cmp r1, r3
    blo .Lauto_080E2850
    ldrb r0, [r4, #1]
    mov r2, ip
    ldrb r2, [r2, #1]
    cmp r0, r2
    bhs .Lauto_080E2850
    .Lauto_080E284C:
    movs r0, #1
    mov sb, r0
    .Lauto_080E2850:
    mov r1, sb
    cmp r1, #0
    beq .Lauto_080E2864
    str r4, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r7, #0
    adds r1, r6, #0
    adds r2, r5, #0
    b .Lauto_080E2A42
    .Lauto_080E2864:
    adds r3, r5, #0
    adds r3, #0x10
    movs r1, #0
    ldrb r2, [r5, #0x10]
    mov r0, r8
    cmp r2, r0
    blo .Lauto_080E287E
    cmp r0, r2
    blo .Lauto_080E2880
    ldrb r0, [r3, #1]
    ldrb r2, [r4, #1]
    cmp r0, r2
    bhs .Lauto_080E2880
    .Lauto_080E287E:
    movs r1, #1
    .Lauto_080E2880:
    cmp r1, #0
    bne .Lauto_080E2888
    str r5, [r7]
    b .Lauto_080E2A74
    .Lauto_080E2888:
    str r5, [sp, #8]
    adds r0, r5, #0
    bl func_080E2B28
    adds r2, r0, #0
    str r2, [sp, #8]
    ldr r0, [r6, #4]
    cmp r2, r0
    bne .Lauto_080E28A4
    mov r0, sl
    ldr r3, [r0]
    str r4, [sp]
    str r3, [sp, #4]
    b .Lauto_080E291E
    .Lauto_080E28A4:
    adds r3, r2, #0
    adds r3, #0x10
    movs r1, #0
    mov r8, r1
    ldrb r1, [r4]
    ldrb r0, [r2, #0x10]
    adds r5, r2, #0
    cmp r1, r0
    blo .Lauto_080E28C2
    cmp r0, r1
    blo .Lauto_080E28C6
    ldrb r0, [r4, #1]
    ldrb r3, [r3, #1]
    cmp r0, r3
    bhs .Lauto_080E28C6
    .Lauto_080E28C2:
    movs r2, #1
    mov r8, r2
    .Lauto_080E28C6:
    mov r0, r8
    cmp r0, #0
    bne .Lauto_080E28CE
    b .Lauto_080E2A66
    .Lauto_080E28CE:
    mov r1, sl
    ldr r3, [r1]
    ldr r0, [r3, #0xc]
    cmp r0, #0
    bne .Lauto_080E28DE
    str r4, [sp]
    str r3, [sp, #4]
    b .Lauto_080E291E
    .Lauto_080E28DE:
    str r4, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r7, #0
    adds r1, r6, #0
    adds r2, r5, #0
    b .Lauto_080E2A42
    .Lauto_080E28EC:
    cmp r2, r1
    bne .Lauto_080E2938
    ldr r0, [r2, #0xc]
    adds r2, r0, #0
    adds r2, #0x10
    movs r3, #0
    ldrb r0, [r0, #0x10]
    ldrb r1, [r4]
    cmp r0, r1
    blo .Lauto_080E290C
    cmp r1, r0
    blo .Lauto_080E290E
    ldrb r0, [r2, #1]
    ldrb r2, [r4, #1]
    cmp r0, r2
    bhs .Lauto_080E290E
    .Lauto_080E290C:
    movs r3, #1
    .Lauto_080E290E:
    cmp r3, #0
    beq .Lauto_080E292A
    ldr r0, [r6, #4]
    ldr r3, [r0, #0xc]
    str r4, [sp]
    mov r1, sl
    ldr r0, [r1]
    str r0, [sp, #4]
    .Lauto_080E291E:
    adds r0, r7, #0
    adds r1, r6, #0
    movs r2, #0
    bl func_080E2EA4
    b .Lauto_080E2A74
    .Lauto_080E292A:
    add r0, sp, #8
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_080E2F74
    ldr r0, [sp, #8]
    b .Lauto_080E2A72
    .Lauto_080E2938:
    str r2, [sp, #8]
    adds r0, r2, #0
    bl func_080E2354
    str r0, [sp, #8]
    mov r2, sl
    ldr r0, [r2]
    adds r2, r0, #0
    adds r2, #0x10
    movs r3, #0
    ldrb r1, [r4]
    ldrb r0, [r0, #0x10]
    cmp r1, r0
    blo .Lauto_080E2960
    cmp r0, r1
    blo .Lauto_080E2962
    ldrb r0, [r4, #1]
    ldrb r2, [r2, #1]
    cmp r0, r2
    bhs .Lauto_080E2962
    .Lauto_080E2960:
    movs r3, #1
    .Lauto_080E2962:
    mov sb, r3
    cmp r3, #0
    beq .Lauto_080E299E
    ldr r0, [sp, #8]
    adds r3, r0, #0
    adds r3, #0x10
    movs r1, #0
    mov r8, r1
    ldrb r2, [r0, #0x10]
    ldrb r1, [r4]
    adds r5, r0, #0
    cmp r2, r1
    blo .Lauto_080E2988
    cmp r1, r2
    blo .Lauto_080E298C
    ldrb r0, [r3, #1]
    ldrb r2, [r4, #1]
    cmp r0, r2
    bhs .Lauto_080E298C
    .Lauto_080E2988:
    movs r0, #1
    mov r8, r0
    .Lauto_080E298C:
    mov r1, r8
    cmp r1, #0
    beq .Lauto_080E299E
    ldr r0, [r5, #0xc]
    cmp r0, #0
    beq .Lauto_080E2A38
    mov r2, sl
    ldr r3, [r2]
    b .Lauto_080E2A4A
    .Lauto_080E299E:
    mov r1, sl
    ldr r0, [r1]
    str r0, [sp, #0xc]
    bl func_080E2B28
    str r0, [sp, #0xc]
    movs r0, #1
    mov r1, sb
    eors r1, r0
    mov r2, sb
    cmp r2, #0
    bne .Lauto_080E2A5C
    mov r1, sl
    ldr r0, [r1]
    movs r2, #0x10
    adds r2, r2, r0
    mov ip, r2
    movs r2, #0
    mov r1, sp
    strb r2, [r1, #0x18]
    ldrb r1, [r4]
    ldrb r3, [r0, #0x10]
    adds r2, r1, #0
    adds r5, r0, #0
    mov r8, r1
    cmp r3, r2
    blo .Lauto_080E29E2
    cmp r2, r3
    blo .Lauto_080E29E8
    mov r1, ip
    ldrb r0, [r1, #1]
    ldrb r2, [r4, #1]
    cmp r0, r2
    bhs .Lauto_080E29E8
    .Lauto_080E29E2:
    movs r1, #1
    mov r0, sp
    strb r1, [r0, #0x18]
    .Lauto_080E29E8:
    mov r2, sp
    ldrb r2, [r2, #0x18]
    adds r1, r2, #0
    mov r0, sb
    cmp r0, #0
    bne .Lauto_080E2A5C
    cmp r1, #0
    beq .Lauto_080E2A5C
    ldr r0, [r6, #4]
    ldr r3, [sp, #0xc]
    cmp r3, r0
    beq .Lauto_080E2A32
    movs r2, #0x10
    adds r2, r2, r3
    mov ip, r2
    movs r2, #0
    mov r0, sp
    strb r2, [r0, #0x1c]
    mov r0, r8
    ldrb r2, [r3, #0x10]
    cmp r0, r2
    blo .Lauto_080E2A24
    cmp r2, r0
    blo .Lauto_080E2A2A
    ldrb r0, [r4, #1]
    mov r8, r0
    mov r2, ip
    ldrb r2, [r2, #1]
    cmp r8, r2
    bhs .Lauto_080E2A2A
    .Lauto_080E2A24:
    movs r2, #1
    mov r0, sp
    strb r2, [r0, #0x1c]
    .Lauto_080E2A2A:
    mov r0, sp
    ldrb r0, [r0, #0x1c]
    cmp r0, #0
    beq .Lauto_080E2A5C
    .Lauto_080E2A32:
    ldr r0, [r5, #0xc]
    cmp r0, #0
    bne .Lauto_080E2A4A
    .Lauto_080E2A38:
    str r4, [sp]
    str r5, [sp, #4]
    adds r0, r7, #0
    adds r1, r6, #0
    movs r2, #0
    .Lauto_080E2A42:
    adds r3, r5, #0
    bl func_080E2EA4
    b .Lauto_080E2A74
    .Lauto_080E2A4A:
    str r4, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r7, #0
    adds r1, r6, #0
    adds r2, r3, #0
    bl func_080E2EA4
    b .Lauto_080E2A74
    .Lauto_080E2A5C:
    cmp sb, r1
    bne .Lauto_080E2A66
    mov r1, sl
    ldr r0, [r1]
    b .Lauto_080E2A72
    .Lauto_080E2A66:
    add r0, sp, #0x10
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_080E2F74
    ldr r0, [sp, #0x10]
    .Lauto_080E2A72:
    str r0, [r7]
    .Lauto_080E2A74:
    adds r0, r7, #0
    add sp, #0x20
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E2A88
    .thumb_func
func_080E2A88:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    mov r8, r1
    movs r0, #0xee
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r0, [r4, #8]
    cmp r0, #0
    beq .Lauto_080E2AB8
    ldr r0, [r4, #4]
    ldr r1, [r0, #4]
    adds r0, r4, #0
    bl loc_080E2618
    ldr r0, [r4, #4]
    str r0, [r0, #8]
    ldr r0, [r4, #4]
    movs r1, #0
    str r1, [r0, #4]
    ldr r0, [r4, #4]
    str r0, [r0, #0xc]
    str r1, [r4, #8]
    .Lauto_080E2AB8:
    ldr r0, [r4, #4]
    cmp r0, #0
    beq .Lauto_080E2AC2
    bl free
    .Lauto_080E2AC2:
    movs r1, #0xe6
    lsls r1, r1, #1
    adds r0, r5, r1
    ldr r2, [r0, #4]
    ldr r1, [r0]
    adds r4, r5, #0
    adds r4, #0x20
    adds r6, r5, #0
    adds r6, #0x1c
    adds r7, r5, #0
    adds r7, #0x18
    cmp r1, r2
    beq .Lauto_080E2AE2
    .Lauto_080E2ADC:
    adds r1, #0x1c
    cmp r1, r2
    bne .Lauto_080E2ADC
    .Lauto_080E2AE2:
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E2AEC
    bl free
    .Lauto_080E2AEC:
    movs r0, #0xce
    lsls r0, r0, #1
    adds r1, r5, r0
    ldr r0, [pc, #0x40]
    str r0, [r1]
    str r0, [r5, #0x28]
    adds r0, r4, #0
    movs r1, #2
    bl func_0807532C
    adds r0, r6, #0
    movs r1, #2
    bl _._24MapClockStatusHudContent
    adds r0, r7, #0
    movs r1, #2
    bl _._12UiStateOwner
    ldr r1, [r5, #0xc]
    cmp r1, #0
    beq .Lauto_080E2B22
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E2B22:
    adds r0, r5, #0
    mov r1, r8
    bl _._15HardwareContext
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .4byte __vt_23IndexedResourceProvider
    .global func_080E3398
    .thumb_func
func_080E3398:
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    adds r7, r2, #0
    subs r1, r1, r6
    asrs r3, r1, #2
    .Lauto_080E2B42:
    cmp r3, #0
    ble .Lauto_080E2B68
    asrs r2, r3, #1
    lsls r0, r2, #2
    adds r4, r6, r0
    movs r5, #0
    ldr r1, [r4]
    ldr r0, [r7]
    cmp r1, r0
    bhs .Lauto_080E2B58
    movs r5, #1
    .Lauto_080E2B58:
    cmp r5, #0
    beq .Lauto_080E2B64
    adds r6, r4, #4
    subs r0, r3, r2
    subs r3, r0, #1
    b .Lauto_080E2B42
    .Lauto_080E2B64:
    adds r3, r2, #0
    b .Lauto_080E2B42
    .Lauto_080E2B68:
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .global func_080E2B70
    .thumb_func
func_080E2B70:
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r6, r1, #0
    movs r1, #0xa6
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E2B86
    bl free
    .Lauto_080E2B86:
    ldr r2, [pc, #0x98]
    adds r4, r5, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0x83
    lsls r0, r0, #4
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r1, [pc, #0x70]
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0x82
    lsls r2, r2, #4
    adds r4, r5, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r0, [pc, #0x4c]
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0x81
    lsls r1, r1, #4
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r2, [pc, #0x24]
    adds r0, r5, r2
    ldr r1, [pc, #0x24]
    str r1, [r0]
    subs r2, #0x30
    adds r0, r5, r2
    str r1, [r0]
    adds r0, r5, #0
    adds r1, r6, #0
    bl _._15HardwareContext
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x38, 0x08, 0x00, 0x00, 0x28, 0x08, 0x00, 0x00, 0x18, 0x08, 0x00, 0x00, 0x44, 0x07, 0x00, 0x00
    .4byte __vt_23IndexedResourceProvider
    .section .text.after_blacksmith_shop_result_transition, "ax", %progbits
    .align 2, 0

    .section .text.after_menu_selection_core_destructor, "ax", %progbits
    .align 2, 0

    .global func_080E2D7C
    .thumb_func
func_080E2D7C:
    push {lr}
    subs r0, #8
    bl func_08092DD4
    pop {r0}
    bx r0
    .global func_080E2D88
    .thumb_func
func_080E2D88:
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r4, r0
    ldr r1, [pc, #0x18]
    adds r0, r4, #0
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    adds r0, r4, #0
    movs r1, #0x39
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .word gText_LinkCommunication_Waiting
    .global func_080E2DB0
    .thumb_func
func_080E2DB0:
    push {lr}
    subs r0, #8
    bl GetHardwarePressedKeys
    movs r1, #2
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    pop {r1}
    bx r1
    .global func_080E2DC8
    .thumb_func
func_080E2DC8:
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r4, r0
    ldr r1, [pc, #0x18]
    adds r0, r4, #0
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    adds r0, r4, #0
    movs r1, #0x38
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .word gText_LinkCommunication_SendingGameData
    .global func_080E2DF0
    .thumb_func
func_080E2DF0:
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r4, r0
    ldr r1, [pc, #0x18]
    adds r0, r4, #0
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    adds r0, r4, #0
    movs r1, #0x38
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .word gText_LinkCommunication_TestingConnection
    .global func_080E2E18
    .thumb_func
func_080E2E18:
    push {r4, lr}
    adds r2, r0, #0
    movs r1, #0xf6
    lsls r1, r1, #2
    adds r0, r2, r1
    movs r1, #0
    str r1, [r0]
    movs r3, #0xf7
    lsls r3, r3, #2
    adds r0, r2, r3
    str r1, [r0]
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r2, r0
    ldr r1, [pc, #0x18]
    adds r0, r4, #0
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    adds r0, r4, #0
    movs r1, #0x3a
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .word gText_LinkCommunication_CannotResendPreviousData
    .global func_080E36B4
    .thumb_func
func_080E36B4:
    .global func_080E2E54
    .thumb_func
func_080E2E54:
    push {r4, r5, r6, lr}
    sub sp, #0xc
    movs r6, #0
    movs r1, #0xf7
    lsls r1, r1, #2
    adds r4, r0, r1
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_080E2E6C
    cmp r1, #1
    beq .Lauto_080E2EA0
    b .Lauto_080E2EC6
    .Lauto_080E2E6C:
    movs r1, #0xe4
    lsls r1, r1, #1
    adds r5, r0, r1
    adds r0, r5, #0
    bl GetState__C12UiStateOwner
    cmp r0, #3
    bne .Lauto_080E2EC6
    movs r0, #1
    str r0, [r4]
    ldr r1, [pc, #0x10]
    ldr r2, [pc, #0x14]
    ldr r3, [pc, #0x14]
    str r6, [sp]
    str r6, [sp, #4]
    str r6, [sp, #8]
    adds r0, r5, #0
    bl func_08050E30
    b .Lauto_080E2EC6
    .word gText_LinkCommunication_ProceedQuestion
    .word gText_LinkCommunication_Yes
    .word gText_LinkCommunication_No
    .Lauto_080E2EA0:
    movs r1, #0xe4
    lsls r1, r1, #1
    adds r4, r0, r1
    adds r0, r4, #0
    bl GetState__C12UiStateOwner
    cmp r0, #3
    bne .Lauto_080E2EC6
    adds r0, r4, #0
    bl GetChoiceResult__C12UiStateOwner
    cmp r0, #1
    beq .Lauto_080E2EC0
    cmp r0, #2
    beq .Lauto_080E2EC4
    b .Lauto_080E2EC6
    .Lauto_080E2EC0:
    movs r6, #2
    b .Lauto_080E2EC6
    .Lauto_080E2EC4:
    movs r6, #3
    .Lauto_080E2EC6:
    adds r0, r6, #0
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .global func_080E3730
    .thumb_func
func_080E3730:
    .global func_080E2ED0
    .thumb_func
func_080E2ED0:
    bx lr
    .byte 0x00, 0x00
    .global func_080E2ED4
    .thumb_func
func_080E2ED4:
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r4, r0
    ldr r1, [pc, #0x18]
    adds r0, r4, #0
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    adds r0, r4, #0
    movs r1, #0x38
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .word gText_LinkCommunication_WaitingForOtherPlayer
    .global func_080E2EFC
    .thumb_func
func_080E2EFC:
    push {lr}
    subs r0, #8
    bl GetHardwarePressedKeys
    movs r1, #2
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    pop {r1}
    bx r1
    .global func_080E3774
    .thumb_func
func_080E3774:
    .global func_080E2F14
    .thumb_func
func_080E2F14:
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r4, r0
    ldr r1, [pc, #0x14]
    adds r0, r4, #0
    bl func_08050D8C
    adds r0, r4, #0
    movs r1, #0x38
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .word gText_LinkCommunication_NowSendingData
    .global func_080E2F38
    .thumb_func
func_080E2F38:
    bx lr
    .byte 0x00, 0x00
    .global func_080E2F3C
    .thumb_func
func_080E2F3C:
    push {r4, lr}
    adds r2, r0, #0
    movs r1, #0xf6
    lsls r1, r1, #2
    adds r0, r2, r1
    movs r1, #0
    str r1, [r0]
    movs r3, #0xf7
    lsls r3, r3, #2
    adds r0, r2, r3
    str r1, [r0]
    movs r0, #0xe4
    lsls r0, r0, #1
    adds r4, r2, r0
    ldr r1, [pc, #0x14]
    adds r0, r4, #0
    bl func_08050D8C
    adds r0, r4, #0
    movs r1, #0x3a
    bl ShowPortrait__C12UiStateOwnerUi
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .word gText_LinkCommunication_DataExchangeFailed
    .global func_080E37DC
    .thumb_func
func_080E37DC:
    .global func_080E2F74_vtable_target
    .thumb_func
func_080E2F74_vtable_target:
    push {r4, lr}
    sub sp, #0x10
    adds r1, r0, #0
    movs r4, #0
    movs r0, #0xf7
    lsls r0, r0, #2
    adds r2, r1, r0
    ldr r0, [r2]
    cmp r0, #0
    beq .Lauto_080E2F8E
    cmp r0, #1
    beq .Lauto_080E2FC0
    b .Lauto_080E2FE6
    .Lauto_080E2F8E:
    movs r3, #0xea
    lsls r3, r3, #1
    adds r0, r1, r3
    ldr r0, [r0]
    cmp r0, #3
    bne .Lauto_080E2FE6
    movs r0, #1
    str r0, [r2]
    movs r2, #0xe4
    lsls r2, r2, #1
    adds r0, r1, r2
    ldr r1, [pc, #0x10]
    ldr r2, [pc, #0x14]
    str r4, [sp]
    str r4, [sp, #4]
    str r4, [sp, #8]
    str r4, [sp, #0xc]
    movs r3, #0
    bl func_08050E0C
    b .Lauto_080E2FE6
    .word gText_LinkCommunication_Yes
    .word gText_LinkCommunication_No
    .Lauto_080E2FC0:
    movs r3, #0xea
    lsls r3, r3, #1
    adds r0, r1, r3
    ldr r0, [r0]
    cmp r0, #3
    bne .Lauto_080E2FE6
    movs r2, #0xe4
    lsls r2, r2, #1
    adds r0, r1, r2
    bl GetChoiceResult__C12UiStateOwner
    cmp r0, #1
    beq .Lauto_080E2FE0
    cmp r0, #2
    beq .Lauto_080E2FE4
    b .Lauto_080E2FE6
    .Lauto_080E2FE0:
    movs r4, #2
    b .Lauto_080E2FE6
    .Lauto_080E2FE4:
    movs r4, #3
    .Lauto_080E2FE6:
    adds r0, r4, #0
    add sp, #0x10
    pop {r4}
    pop {r1}
    bx r1
    .global func_080E2FF0
    .thumb_func
func_080E2FF0:
    bx lr
    .byte 0x00, 0x00
    .global func_080E2FF4
    .thumb_func
func_080E2FF4:
    push {lr}
    subs r0, #8
    bl GetHardwareHeldKeys
    pop {r1}
    bx r1
    .global func_080E3000
    .thumb_func
func_080E3000:
    push {lr}
    subs r0, #8
    bl GetHardwarePressedKeys
    pop {r1}
    bx r1
    .global func_080E3874
    .thumb_func
func_080E3874:
    .global func_080E300C
    .thumb_func
func_080E300C:
    push {lr}
    adds r2, r0, #0
    movs r1, #0xdc
    lsls r1, r1, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E302E
    adds r1, #3
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E302A
    movs r0, #0
    b .Lauto_080E3042
    .Lauto_080E302A:
    movs r0, #1
    b .Lauto_080E3042
    .Lauto_080E302E:
    ldr r0, [r2]
    ldr r1, [r0, #0x4c]
    adds r0, r2, #0
    bl _call_via_r1
    movs r1, #0
    cmp r0, #0
    bne .Lauto_080E3040
    movs r1, #1
    .Lauto_080E3040:
    adds r0, r1, #0
    .Lauto_080E3042:
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E38B0
    .thumb_func
func_080E38B0:
    .global func_080E3048
    .thumb_func
func_080E3048:
    push {lr}
    adds r1, r0, #0
    movs r2, #0xdc
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E3060
    adds r2, #2
    adds r0, r1, r2
    ldrb r0, [r0]
    b .Lauto_080E3074
    .Lauto_080E3060:
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #4]
    cmp r2, #0
    beq .Lauto_080E3072
    ldr r0, [r1, #0x18]
    cmp r2, r0
    beq .Lauto_080E3072
    movs r0, #1
    b .Lauto_080E3074
    .Lauto_080E3072:
    movs r0, #0
    .Lauto_080E3074:
    pop {r1}
    bx r1
    .global func_080E38E0
    .thumb_func
func_080E38E0:
    .global func_080E3078
    .thumb_func
func_080E3078:
    push {lr}
    adds r2, r0, #0
    movs r1, #0xdc
    lsls r1, r1, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E3090
    adds r1, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    b .Lauto_080E30A4
    .Lauto_080E3090:
    ldr r0, [r2]
    ldr r1, [r0, #0x4c]
    adds r0, r2, #0
    bl _call_via_r1
    cmp r0, #0
    beq .Lauto_080E30A2
    movs r0, #0
    b .Lauto_080E30A4
    .Lauto_080E30A2:
    movs r0, #1
    .Lauto_080E30A4:
    pop {r1}
    bx r1
    .global func_080E30A8
    .thumb_func
func_080E30A8:
    movs r0, #1
    bx lr
    .global func_080E30AC
    .thumb_func
func_080E30AC:
    push {lr}
    bl StopJoyBusCommunication
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E30B8
    .thumb_func
func_080E30B8:
    push {lr}
    bl StartJoyBusCommunication
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E30C4
    .thumb_func
func_080E30C4:
    push {lr}
    bl UpdateJoyBusCommunication
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E30D0
    .thumb_func
func_080E30D0:
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0xdc
    lsls r1, r1, #1
    adds r0, r4, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E3112
    ldr r0, [r4]
    subs r1, #0xb4
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne .Lauto_080E311E
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #2
    ands r1, r0
    cmp r1, #0
    bne .Lauto_080E3122
    .Lauto_080E3112:
    bl func_080D06D0
    cmp r0, #0
    beq .Lauto_080E311E
    cmp r0, #0xb
    bne .Lauto_080E3122
    .Lauto_080E311E:
    movs r0, #0
    b .Lauto_080E3124
    .Lauto_080E3122:
    movs r0, #1
    .Lauto_080E3124:
    pop {r4}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E312C
    .thumb_func
func_080E312C:
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0xdc
    lsls r1, r1, #1
    adds r0, r4, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E316E
    ldr r0, [r4]
    subs r1, #0xb0
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne .Lauto_080E3176
    ldr r0, [r4]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #2
    ands r1, r0
    cmp r1, #0
    bne .Lauto_080E3176
    .Lauto_080E316E:
    bl func_080D06D0
    cmp r0, #0xb
    beq .Lauto_080E317A
    .Lauto_080E3176:
    movs r0, #0
    b .Lauto_080E317C
    .Lauto_080E317A:
    movs r0, #1
    .Lauto_080E317C:
    pop {r4}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E39EC
    .thumb_func
func_080E39EC:
    .global func_080E3184
    .thumb_func
func_080E3184:
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0xdc
    lsls r1, r1, #1
    adds r0, r4, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_080E31CA
    ldr r0, [r4]
    subs r1, #0xb0
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne .Lauto_080E31C6
    ldr r0, [r4]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    lsrs r0, r0, #8
    movs r1, #2
    ands r1, r0
    cmp r1, #0
    beq .Lauto_080E31CA
    .Lauto_080E31C6:
    movs r0, #1
    b .Lauto_080E31D6
    .Lauto_080E31CA:
    bl func_080D06B4
    adds r1, r0, #0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    .Lauto_080E31D6:
    pop {r4}
    pop {r1}
    bx r1
    .global func_080E31DC
    .thumb_func
func_080E31DC:
    push {lr}
    bl func_080D06A8
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E31E8
    .thumb_func
func_080E31E8:
    push {lr}
    bl func_080D0678
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E31F4
    .thumb_func
func_080E31F4:
    push {lr}
    adds r0, r1, #0
    lsls r1, r2, #0x18
    lsrs r1, r1, #0x18
    bl func_080D0644
    pop {r0}
    bx r0
    .global func_080E3204
    .thumb_func
func_080E3204:
    push {lr}
    adds r0, r1, #0
    adds r1, r2, #0
    adds r2, r3, #0
    ldr r3, [sp, #4]
    bl func_080D0558
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E3218
    .thumb_func
func_080E3218:
    push {lr}
    movs r0, #0
    bl func_080D0454
    pop {r0}
    bx r0
    .global func_080E3224
    .thumb_func
func_080E3224:
    push {lr}
    adds r0, r1, #0
    adds r1, r2, #0
    bl func_080D0444
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E3234
    .thumb_func
func_080E3234:
    push {r4, lr}
    adds r3, r0, #0
    cmp r1, #4
    bhi .Lauto_080E32F0
    lsls r0, r1, #2
    ldr r1, [pc, #8]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0x4C, 0x32, 0x0E, 0x08
    .Lauto_080E324C:
    .byte 0x60, 0x32, 0x0E, 0x08, 0x6C, 0x32, 0x0E, 0x08, 0x80, 0x32, 0x0E, 0x08, 0xA8, 0x32, 0x0E, 0x08
    .byte 0xD0, 0x32, 0x0E, 0x08
    .Lauto_080E3260:
    .byte 0xDC, 0x20, 0x40, 0x00, 0x19, 0x18, 0x00, 0x20, 0x08, 0x70, 0x41, 0xE0
    .Lauto_080E326C:
    .byte 0xDC, 0x21, 0x49, 0x00, 0x58, 0x18, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x00, 0x4C, 0x37, 0xE0
    .byte 0xB9, 0x01, 0x00, 0x00
    .Lauto_080E3280:
    .byte 0xDC, 0x21, 0x49, 0x00, 0x58, 0x18, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x04, 0x4C, 0x18, 0x19
    .byte 0x01, 0x70, 0x01, 0x34, 0x18, 0x19, 0x01, 0x70, 0x02, 0x49, 0x58, 0x18, 0x27, 0xE0, 0x00, 0x00
    .byte 0xB9, 0x01, 0x00, 0x00, 0xBB, 0x01, 0x00, 0x00
    .Lauto_080E32A8:
    .byte 0xDC, 0x22, 0x52, 0x00, 0x98, 0x18, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x04, 0x4C, 0x18, 0x19
    .byte 0x01, 0x70, 0x01, 0x34, 0x18, 0x19, 0x02, 0x70, 0x02, 0x4A, 0x98, 0x18, 0x01, 0x70, 0x13, 0xE0
    .byte 0xB9, 0x01, 0x00, 0x00, 0xBB, 0x01, 0x00, 0x00
    .Lauto_080E32D0:
    .byte 0xDC, 0x24, 0x64, 0x00, 0x18, 0x19, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70, 0x01, 0x34, 0x18, 0x19
    .byte 0x01, 0x70, 0xDD, 0x21, 0x49, 0x00, 0x58, 0x18, 0x02, 0x70, 0x02, 0x34, 0x18, 0x19, 0x02, 0x70
    .Lauto_080E32F0:
    pop {r4}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .global func_080E32F8
    .thumb_func
func_080E32F8:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x14]
    str r0, [r4]
    bl ResetJoyBusLinkRegisters
    adds r0, r4, #0
    adds r1, r5, #0
    bl func_08093D2C
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x3C, 0x73, 0x0E, 0x08
    .global func_080E3B80
    .thumb_func
func_080E3B80:
    .global func_080E3318
    .thumb_func
func_080E3318:
    push {r4, r5, r6, lr}
    sub sp, #0x28
    adds r6, r0, #0
    cmp r2, #0xf1
    beq .Lauto_080E3348
    cmp r2, #0xf1
    bgt .Lauto_080E332C
    cmp r2, #0xf0
    beq .Lauto_080E3332
    b .Lauto_080E33BA
    .Lauto_080E332C:
    cmp r2, #0xff
    beq .Lauto_080E3360
    b .Lauto_080E33BA
    .Lauto_080E3332:
    ldrb r0, [r1, #6]
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [pc, #4]
    adds r5, r1, r0
    adds r0, r5, #0
    b .Lauto_080E338E
    .word gText_StaminaRecoveryStatus
    .Lauto_080E3348:
    ldrb r0, [r1, #7]
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [pc, #8]
    adds r5, r1, r0
    adds r0, r5, #0
    b .Lauto_080E338E
    .byte 0x00, 0x00
    .word gText_FatigueRecoveryStatus
    .Lauto_080E3360:
    ldrh r0, [r1, #4]
    cmp r0, #0xab
    bhi .Lauto_080E337A
    add r4, sp, #0x20
    adds r1, r0, #0
    subs r1, #1
    adds r0, r4, #0
    bl __4FoodUi
    adds r0, r4, #0
    bl GetName__C4Food
    b .Lauto_080E338C
    .Lauto_080E337A:
    add r4, sp, #0x24
    ldrh r1, [r1, #4]
    subs r1, #0xac
    adds r0, r4, #0
    bl __7ArticleUi
    adds r0, r4, #0
    bl GetName__C7Article
    .Lauto_080E338C:
    adds r5, r0, #0
    .Lauto_080E338E:
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E339A
    movs r4, #0x1f
    .Lauto_080E339A:
    mov r0, sp
    adds r1, r5, #0
    adds r2, r4, #0
    bl memcpy
    mov r0, sp
    adds r1, r0, r4
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r6]
    adds r0, r6, #4
    mov r1, sp
    bl strcpy
    b .Lauto_080E33C8
    .Lauto_080E33BA:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    strb r0, [r6]
    adds r0, r6, #4
    bl strcpy
    .Lauto_080E33C8:
    adds r0, r6, #0
    add sp, #0x28
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E3C3C
    .thumb_func
func_080E3C3C:
    .global func_080E33D4
    .thumb_func
func_080E33D4:
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r6, r1, #0
    ldr r0, [pc, #0x144]
    adds r1, r5, r0
    ldr r0, [pc, #0x144]
    str r0, [r1]
    movs r1, #0xca
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xc8
    lsls r2, r2, #2
    adds r4, r5, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc6
    lsls r0, r0, #2
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xc4
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0xc2
    lsls r2, r2, #2
    adds r4, r5, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0xbe
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r2, #0xbc
    lsls r2, r2, #2
    adds r4, r5, r2
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xba
    lsls r0, r0, #2
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0xb8
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r2, #0x94
    lsls r2, r2, #1
    adds r0, r5, r2
    ldr r4, [pc, #0x60]
    str r4, [r0]
    adds r0, r5, #0
    adds r0, #0xf8
    str r4, [r0]
    subs r0, #0x30
    str r4, [r0]
    subs r0, #0x30
    str r4, [r0]
    subs r0, #0x18
    movs r1, #2
    bl _._12UiStateOwner
    ldr r1, [r5, #0x7c]
    cmp r1, #0
    beq .Lauto_080E34F6
    movs r2, #0x84
    lsls r2, r2, #2
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E34F6:
    ldr r1, [r5, #0x78]
    cmp r1, #0
    beq .Lauto_080E350E
    movs r2, #0x84
    lsls r2, r2, #2
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E350E:
    str r4, [r5, #0x10]
    adds r0, r5, #0
    adds r1, r6, #0
    bl _._15HardwareContext
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xD8, 0x33, 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .4byte __vt_23IndexedResourceProvider
    .global func_080E352C
    .thumb_func
func_080E352C:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E3542
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E3542:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .global func_080E3DB4
    .thumb_func
func_080E3DB4:
    push {r4, r5, lr}
    adds r5, r1, #0
    adds r4, r2, #0
    adds r3, r0, #0
    subs r0, r5, r3
    asrs r2, r0, #3
    cmp r2, #0
    ble .Lauto_080E3584
    ldrh r1, [r4]
    .Lauto_080E355E:
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bgt .Lauto_080E355E
    .Lauto_080E3584:
    subs r0, r5, r3
    asrs r0, r0, #1
    cmp r0, #1
    beq .Lauto_080E35AC
    cmp r0, #1
    ble .Lauto_080E35B8
    cmp r0, #2
    beq .Lauto_080E35A2
    cmp r0, #3
    bne .Lauto_080E35B8
    ldrh r0, [r3]
    ldrh r1, [r4]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    .Lauto_080E35A2:
    ldrh r0, [r3]
    ldrh r1, [r4]
    cmp r0, r1
    beq .Lauto_080E35B4
    adds r3, #2
    .Lauto_080E35AC:
    ldrh r0, [r3]
    ldrh r4, [r4]
    cmp r0, r4
    bne .Lauto_080E35B8
    .Lauto_080E35B4:
    adds r0, r3, #0
    b .Lauto_080E35BA
    .Lauto_080E35B8:
    adds r0, r5, #0
    .Lauto_080E35BA:
    pop {r4, r5}
    pop {r1}
    bx r1
    .global func_080E3E28
    .thumb_func
func_080E3E28:
    push {r4, r5, lr}
    adds r5, r1, #0
    adds r4, r2, #0
    adds r3, r0, #0
    subs r0, r5, r3
    asrs r2, r0, #3
    cmp r2, #0
    ble .Lauto_080E35F8
    ldrh r1, [r4]
    .Lauto_080E35D2:
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    ldrh r0, [r3]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bgt .Lauto_080E35D2
    .Lauto_080E35F8:
    subs r0, r5, r3
    asrs r0, r0, #1
    cmp r0, #1
    beq .Lauto_080E3620
    cmp r0, #1
    ble .Lauto_080E362C
    cmp r0, #2
    beq .Lauto_080E3616
    cmp r0, #3
    bne .Lauto_080E362C
    ldrh r0, [r3]
    ldrh r1, [r4]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    .Lauto_080E3616:
    ldrh r0, [r3]
    ldrh r1, [r4]
    cmp r0, r1
    beq .Lauto_080E3628
    adds r3, #2
    .Lauto_080E3620:
    ldrh r0, [r3]
    ldrh r4, [r4]
    cmp r0, r4
    bne .Lauto_080E362C
    .Lauto_080E3628:
    adds r0, r3, #0
    b .Lauto_080E362E
    .Lauto_080E362C:
    adds r0, r5, #0
    .Lauto_080E362E:
    pop {r4, r5}
    pop {r1}
    bx r1
    .section .text.sprite_work_target_search_after, "ax", %progbits
    .align 2, 0
    .global func_080E3F40
    .thumb_func
func_080E3F40:
    .global func_080E36D8
    .thumb_func
func_080E36D8:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x40
    adds r6, r0, #0
    adds r3, r1, #0
    cmp r2, #0xf1
    beq .Lauto_080E37AC
    cmp r2, #0xf1
    bgt .Lauto_080E36EE
    cmp r2, #0xf0
    beq .Lauto_080E36F6
    b .Lauto_080E381E
    .Lauto_080E36EE:
    cmp r2, #0xf2
    bne .Lauto_080E36F4
    b .Lauto_080E37EE
    .Lauto_080E36F4:
    b .Lauto_080E381E
    .Lauto_080E36F6:
    movs r5, #5
    ldrsb r5, [r3, r5]
    cmp r5, #1
    beq .Lauto_080E3744
    cmp r5, #1
    bgt .Lauto_080E3708
    cmp r5, #0
    beq .Lauto_080E3712
    b .Lauto_080E381E
    .Lauto_080E3708:
    cmp r5, #2
    beq .Lauto_080E3770
    cmp r5, #3
    beq .Lauto_080E3778
    b .Lauto_080E381E
    .Lauto_080E3712:
    ldr r7, [pc, #0x2c]
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E3722
    movs r4, #0x1f
    .Lauto_080E3722:
    mov r0, sp
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    mov r1, sp
    adds r0, r1, r4
    strb r5, [r0]
    movs r0, #1
    strb r0, [r6]
    adds r0, r6, #4
    bl strcpy
    b .Lauto_080E382C
    .byte 0x00, 0x00
    .word gText_Calendar_DynamicSeasonNames
    .Lauto_080E3744:
    ldr r7, [pc, #0x24]
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E3754
    movs r4, #0x1f
    .Lauto_080E3754:
    mov r0, sp
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    mov r1, sp
    adds r0, r1, r4
    movs r1, #0
    strb r1, [r0]
    strb r5, [r6]
    b .Lauto_080E379E
    .byte 0x00, 0x00
    .word gText_Calendar_DynamicSeasonNames + 4 @ fixed four-byte season field
    .Lauto_080E3770:
    ldr r5, [pc, #0]
    b .Lauto_080E377A
    .word gText_Calendar_DynamicSeasonNames + 8 @ fixed four-byte season field
    .Lauto_080E3778:
    ldr r5, [pc, #0x2c]
    .Lauto_080E377A:
    adds r0, r5, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E3788
    movs r4, #0x1f
    .Lauto_080E3788:
    mov r0, sp
    adds r1, r5, #0
    adds r2, r4, #0
    bl memcpy
    mov r0, sp
    adds r1, r0, r4
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r6]
    .Lauto_080E379E:
    adds r0, r6, #4
    mov r1, sp
    bl strcpy
    b .Lauto_080E382C
    .word gText_Calendar_DynamicSeasonNames + 12 @ fixed four-byte season field
    .Lauto_080E37AC:
    movs r0, #4
    ldrsb r0, [r3, r0]
    cmp r0, #9
    bgt .Lauto_080E37CC
    mov r1, sp
    movs r0, #0x81
    strb r0, [r1]
    movs r0, #0x40
    strb r0, [r1, #1]
    movs r0, #4
    ldrsb r0, [r3, r0]
    adds r1, #2
    movs r2, #0
    bl FormatFullWidthDecimal
    b .Lauto_080E37D8
    .Lauto_080E37CC:
    movs r0, #4
    ldrsb r0, [r3, r0]
    mov r1, sp
    movs r2, #0
    bl FormatFullWidthDecimal
    .Lauto_080E37D8:
    add r5, sp, #0x20
    mov r0, sp
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E37E8
    movs r4, #0x1f
    .Lauto_080E37E8:
    adds r0, r5, #0
    mov r1, sp
    b .Lauto_080E3804
    .Lauto_080E37EE:
    add r5, sp, #8
    ldr r7, [r3, #8]
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0x1f
    bls .Lauto_080E3800
    movs r4, #0x1f
    .Lauto_080E3800:
    adds r0, r5, #0
    adds r1, r7, #0
    .Lauto_080E3804:
    adds r2, r4, #0
    bl memcpy
    adds r1, r5, r4
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r6]
    adds r0, r6, #4
    adds r1, r5, #0
    bl strcpy
    b .Lauto_080E382C
    .Lauto_080E381E:
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    strb r0, [r6]
    adds r0, r6, #4
    bl strcpy
    .Lauto_080E382C:
    adds r0, r6, #0
    add sp, #0x40
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E40A0
    .thumb_func
func_080E40A0:
    .global func_080E3838
    .thumb_func
func_080E3838:
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r6, r1, #0
    movs r0, #0x87
    lsls r0, r0, #2
    adds r1, r5, r0
    ldr r0, [pc, #0xd8]
    str r0, [r1]
    movs r0, #0xd6
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xd2
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xce
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xca
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #0xc6
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xc2
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xbe
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xba
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    adds r1, r5, #0
    adds r1, #0x80
    ldr r0, [pc, #0x24]
    str r0, [r1]
    str r0, [r5, #0x50]
    str r0, [r5, #0x20]
    ldr r0, [r5, #0x10]
    cmp r0, #0
    beq .Lauto_080E3910
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E3910:
    adds r0, r5, #0
    adds r1, r6, #0
    bl _._15HardwareContext
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .4byte __vt_23IndexedResourceProvider
    .global func_080E3928
    .thumb_func
func_080E3928:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E393E
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E393E:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_23ScriptTextVariableStore
    .section .text.after_saved_name_scene_destructor, "ax", %progbits
    .align 2, 0

    .global loc_080E39DC
    .thumb_func
    loc_080E39DC:
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r6, r1, #0
    ldr r4, [sp, #0x14]
    adds r5, r3, #0
    ldr r0, [r6, #4]
    cmp r5, r0
    beq .Lauto_080E3A06
    ldr r0, [sp, #0x18]
    cmp r0, #0
    bne .Lauto_080E3A46
    cmp r2, #0
    bne .Lauto_080E3A06
    movs r2, #0
    ldr r1, [r4]
    ldr r0, [r5, #0x10]
    cmp r1, r0
    bge .Lauto_080E3A02
    movs r2, #1
    .Lauto_080E3A02:
    cmp r2, #0
    beq .Lauto_080E3A46
    .Lauto_080E3A06:
    movs r0, #0x18
    bl malloc
    adds r2, r0, #0
    cmp r2, #0
    bne .Lauto_080E3A1A
    movs r0, #0x18
    bl RetryMemoryAllocation
    adds r2, r0, #0
    .Lauto_080E3A1A:
    adds r1, r2, #0
    adds r1, #0x10
    cmp r1, #0
    beq .Lauto_080E3A2A
    ldr r0, [r4]
    str r0, [r2, #0x10]
    ldr r0, [r4, #4]
    str r0, [r1, #4]
    .Lauto_080E3A2A:
    adds r4, r2, #0
    str r4, [r5, #8]
    ldr r1, [r6, #4]
    cmp r5, r1
    bne .Lauto_080E3A3C
    str r4, [r5, #4]
    ldr r0, [r6, #4]
    str r4, [r0, #0xc]
    b .Lauto_080E3A78
    .Lauto_080E3A3C:
    ldr r0, [r1, #8]
    cmp r5, r0
    bne .Lauto_080E3A78
    str r4, [r1, #8]
    b .Lauto_080E3A78
    .Lauto_080E3A46:
    movs r0, #0x18
    bl malloc
    adds r2, r0, #0
    cmp r2, #0
    bne .Lauto_080E3A5A
    movs r0, #0x18
    bl RetryMemoryAllocation
    adds r2, r0, #0
    .Lauto_080E3A5A:
    adds r1, r2, #0
    adds r1, #0x10
    cmp r1, #0
    beq .Lauto_080E3A6A
    ldr r0, [r4]
    str r0, [r2, #0x10]
    ldr r0, [r4, #4]
    str r0, [r1, #4]
    .Lauto_080E3A6A:
    adds r4, r2, #0
    str r4, [r5, #0xc]
    ldr r1, [r6, #4]
    ldr r0, [r1, #0xc]
    cmp r5, r0
    bne .Lauto_080E3A78
    str r4, [r1, #0xc]
    .Lauto_080E3A78:
    str r5, [r4, #4]
    movs r0, #0
    str r0, [r4, #8]
    str r0, [r4, #0xc]
    ldr r1, [r6, #4]
    adds r1, #4
    adds r0, r4, #0
    bl func_080E21E0
    ldr r0, [r6, #8]
    adds r0, #1
    str r0, [r6, #8]
    str r4, [r7]
    adds r0, r7, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .global func_080E3A9C
    .thumb_func
func_080E3A9C:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x14
    adds r6, r0, #0
    mov r8, r1
    adds r7, r2, #0
    ldr r4, [r1, #4]
    ldr r5, [r4, #4]
    movs r0, #1
    cmp r5, #0
    beq .Lauto_080E3AD2
    ldr r2, [r7]
    .Lauto_080E3AB6:
    adds r4, r5, #0
    movs r1, #0
    ldr r0, [r4, #0x10]
    cmp r2, r0
    bge .Lauto_080E3AC2
    movs r1, #1
    .Lauto_080E3AC2:
    adds r0, r1, #0
    cmp r0, #0
    beq .Lauto_080E3ACC
    ldr r5, [r4, #8]
    b .Lauto_080E3ACE
    .Lauto_080E3ACC:
    ldr r5, [r4, #0xc]
    .Lauto_080E3ACE:
    cmp r5, #0
    bne .Lauto_080E3AB6
    .Lauto_080E3AD2:
    str r4, [sp, #8]
    cmp r0, #0
    beq .Lauto_080E3B0C
    mov r1, r8
    ldr r0, [r1, #4]
    ldr r0, [r0, #8]
    str r0, [sp, #0xc]
    movs r1, #0
    cmp r4, r0
    bne .Lauto_080E3AE8
    movs r1, #1
    .Lauto_080E3AE8:
    cmp r1, #0
    beq .Lauto_080E3B04
    str r7, [sp]
    movs r0, #0
    str r0, [sp, #4]
    add r0, sp, #0x10
    mov r1, r8
    adds r2, r5, #0
    adds r3, r4, #0
    bl loc_080E39DC
    movs r1, #1
    ldr r0, [sp, #0x10]
    b .Lauto_080E3B36
    .Lauto_080E3B04:
    adds r0, r4, #0
    bl func_080E2354
    str r0, [sp, #8]
    .Lauto_080E3B0C:
    ldr r2, [sp, #8]
    movs r3, #0
    ldr r1, [r2, #0x10]
    ldr r0, [r7]
    cmp r1, r0
    bge .Lauto_080E3B1A
    movs r3, #1
    .Lauto_080E3B1A:
    adds r0, r3, #0
    cmp r0, #0
    beq .Lauto_080E3B3C
    str r7, [sp]
    movs r0, #0
    str r0, [sp, #4]
    add r0, sp, #0xc
    mov r1, r8
    adds r2, r5, #0
    adds r3, r4, #0
    bl loc_080E39DC
    movs r1, #1
    ldr r0, [sp, #0xc]
    .Lauto_080E3B36:
    str r0, [r6]
    strb r1, [r6, #4]
    b .Lauto_080E3B40
    .Lauto_080E3B3C:
    str r2, [r6]
    strb r0, [r6, #4]
    .Lauto_080E3B40:
    adds r0, r6, #0
    add sp, #0x14
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .section .text.saved_world_map_destructor_after, "ax", %progbits
    .align 2, 0

    .global __12SavedMapTree
    .thumb_func
__12SavedMapTree:
    push {r4, r5, r6, lr}
    sub sp, #8
    adds r6, r0, #0
    adds r4, r6, #0
    adds r4, #8
    movs r5, #0
    str r5, [r4, #4]
    movs r0, #0x18
    bl malloc
    cmp r0, #0
    bne .Lauto_080E3BB2
    movs r0, #0x18
    bl RetryMemoryAllocation
    .Lauto_080E3BB2:
    str r0, [r4, #4]
    str r5, [r4, #8]
    str r5, [r4, #0xc]
    strb r5, [r0]
    str r5, [r0, #4]
    ldr r0, [r4, #4]
    str r0, [r0, #8]
    ldr r0, [r4, #4]
    str r0, [r0, #0xc]
    adds r0, r6, #0
    add sp, #8
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .section .text.world_sprite_effect_frames_after, "ax", %progbits
    .align 2, 0

    .global func_080E3C50
    .thumb_func
func_080E3C50:
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r0, r5, #4
    movs r1, #2
    bl _._18GameSceneWorldData
    ldr r0, [pc, #0x18]
    str r0, [r5]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq .Lauto_080E3C70
    adds r0, r5, #0
    bl __builtin_delete
    .Lauto_080E3C70:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_14GameObjectBase
    .global func_080E3C7C
    .thumb_func
func_080E3C7C:
    push {r4, lr}
    sub sp, #0x10
    adds r4, r0, #0
    movs r0, #0x8c
    bl __builtin_new
    movs r1, #1
    str r1, [sp]
    movs r1, #0
    str r1, [sp, #4]
    str r1, [sp, #8]
    add r2, sp, #0xc
    strb r1, [r2]
    adds r1, r4, #0
    movs r2, #5
    movs r3, #0x1b
    bl __22EntitySpriteControllerP12AActorEntityUiUiUiUiUib
    add sp, #0x10
    pop {r4}
    pop {r1}
    bx r1
    .global func_080E3CA8
    .thumb_func
func_080E3CA8:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [pc, #0x28]
    str r0, [r4, #0x14]
    ldr r1, [r4, #0x10]
    cmp r1, #0
    beq .Lauto_080E3CC4
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3CC4:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080E3CD2
    adds r0, r4, #0
    bl __builtin_delete
    .Lauto_080E3CD2:
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x90, 0x56, 0x0E, 0x08
    .global func_080E3CDC
    .thumb_func
func_080E3CDC:
    push {lr}
    adds r2, r0, #0
    ldr r0, [pc, #0x14]
    str r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lauto_080E3CF2
    adds r0, r2, #0
    bl __builtin_delete
    .Lauto_080E3CF2:
    pop {r0}
    bx r0
    .byte 0x00, 0x00
    .4byte __vt_14GameObjectBase
    .global func_080E4564
    .thumb_func
func_080E4564:
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    ldr r1, [pc, #0x2ac]
    adds r0, r5, r1
    movs r1, #2
    bl func_080E4860
    ldr r1, [pc, #0x2a4]
    adds r0, r5, r1
    movs r1, #2
    bl func_080098AC
    movs r1, #0x82
    lsls r1, r1, #4
    adds r0, r5, r1
    movs r1, #2
    bl func_080098AC
    movs r1, #0xfd
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x288]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xf8
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x274]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xe1
    lsls r1, r1, #3
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3D72
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3D72
    movs r0, #0xe1
    lsls r0, r0, #3
    adds r6, r5, r0
    .Lauto_080E3D66:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3D66
    .Lauto_080E3D72:
    ldr r1, [pc, #0x24c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3D92
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3D92
    ldr r0, [pc, #0x23c]
    adds r6, r5, r0
    .Lauto_080E3D86:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3D86
    .Lauto_080E3D92:
    movs r1, #0xdc
    lsls r1, r1, #3
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3DB6
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3DB6
    movs r0, #0xdc
    lsls r0, r0, #3
    adds r6, r5, r0
    .Lauto_080E3DAA:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3DAA
    .Lauto_080E3DB6:
    ldr r1, [pc, #0x20c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3DD6
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3DD6
    ldr r0, [pc, #0x1fc]
    adds r6, r5, r0
    .Lauto_080E3DCA:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3DCA
    .Lauto_080E3DD6:
    movs r1, #0xc3
    lsls r1, r1, #3
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3DFA
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3DFA
    movs r0, #0xc3
    lsls r0, r0, #3
    adds r6, r5, r0
    .Lauto_080E3DEE:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3DEE
    .Lauto_080E3DFA:
    ldr r1, [pc, #0x1cc]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3E1A
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3E1A
    ldr r0, [pc, #0x1bc]
    adds r6, r5, r0
    .Lauto_080E3E0E:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3E0E
    .Lauto_080E3E1A:
    movs r1, #0xaa
    lsls r1, r1, #3
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E3E3E
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E3E3E
    movs r0, #0xaa
    lsls r0, r0, #3
    adds r6, r5, r0
    .Lauto_080E3E32:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E3E32
    .Lauto_080E3E3E:
    ldr r1, [pc, #0x18c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xa5
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x178]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xa0
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x168]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x9b
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x154]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x96
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x144]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x91
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x130]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x8c
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x120]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3ED8
    ldr r0, [r1, #8]
    ldr r2, [r0, #0xc]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3ED8:
    movs r1, #0x87
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3EF0
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3EF0:
    ldr r1, [pc, #0xf4]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F06
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F06:
    movs r1, #0x86
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F1E
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F1E:
    ldr r1, [pc, #0xcc]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F34
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F34:
    movs r1, #0x85
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F4C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F4C:
    ldr r1, [pc, #0xa0]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F62
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F62:
    movs r1, #0x84
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F7A
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F7A:
    ldr r1, [pc, #0x78]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E3F90
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E3F90:
    movs r1, #0x83
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E3FA2
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E3FA2:
    adds r0, r5, #0
    adds r1, r7, #0
    bl _._15HardwareContext
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x88, 0x08, 0x00, 0x00, 0x2C, 0x08, 0x00, 0x00, 0xE4, 0x07, 0x00, 0x00, 0xBC, 0x07, 0x00, 0x00
    .byte 0xF4, 0x06, 0x00, 0x00, 0x2C, 0x06, 0x00, 0x00, 0x64, 0x05, 0x00, 0x00, 0x2C, 0x05, 0x00, 0x00
    .byte 0x04, 0x05, 0x00, 0x00, 0xDC, 0x04, 0x00, 0x00, 0xB4, 0x04, 0x00, 0x00, 0x8C, 0x04, 0x00, 0x00
    .byte 0x64, 0x04, 0x00, 0x00, 0x3C, 0x04, 0x00, 0x00, 0x34, 0x04, 0x00, 0x00, 0x2C, 0x04, 0x00, 0x00
    .byte 0x24, 0x04, 0x00, 0x00, 0x1C, 0x04, 0x00, 0x00
    .global func_080E4860
    .thumb_func
func_080E4860:
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r5, r1, #0
    adds r4, r6, #0
    adds r4, #0x50
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r1, [r6, #4]
    adds r0, r6, #0
    bl ReleaseObjTileHandle
    adds r0, r6, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq .Lauto_080E40D2
    adds r0, r6, #0
    bl __builtin_delete
    .Lauto_080E40D2:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .global _._27ChickenFestivalMinigameCore
    .thumb_func
_._27ChickenFestivalMinigameCore:
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    ldr r1, [pc, #0x328]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E40FE
    adds r1, #0x28
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E40FE
    ldr r0, [pc, #0x318]
    adds r6, r5, r0
    .Lauto_080E40F2:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E40F2
    .Lauto_080E40FE:
    ldr r1, [pc, #0x30c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x304]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xa8
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x2f4]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x2ec]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4148
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4148
    ldr r0, [pc, #0x2dc]
    adds r6, r5, r0
    .Lauto_080E413C:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E413C
    .Lauto_080E4148:
    movs r1, #0xa3
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x2c4]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4174
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4174
    ldr r0, [pc, #0x2b4]
    adds r6, r5, r0
    .Lauto_080E4168:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E4168
    .Lauto_080E4174:
    ldr r1, [pc, #0x2a8]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x9c
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x298]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x290]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x28c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x97
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x278]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x274]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E41DE
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E41DE
    ldr r0, [pc, #0x264]
    adds r6, r5, r0
    .Lauto_080E41D2:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E41D2
    .Lauto_080E41DE:
    ldr r1, [pc, #0x258]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E41FE
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E41FE
    ldr r0, [pc, #0x248]
    adds r6, r5, r0
    .Lauto_080E41F2:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E41F2
    .Lauto_080E41FE:
    ldr r1, [pc, #0x23c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x234]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x8d
    lsls r1, r1, #4
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x224]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x21c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4248
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4248
    ldr r0, [pc, #0x20c]
    adds r6, r5, r0
    .Lauto_080E423C:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E423C
    .Lauto_080E4248:
    ldr r1, [pc, #0x200]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4268
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4268
    ldr r0, [pc, #0x1f0]
    adds r6, r5, r0
    .Lauto_080E425C:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E425C
    .Lauto_080E4268:
    movs r1, #0xf9
    lsls r1, r1, #3
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E428C
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E428C
    movs r0, #0xf9
    lsls r0, r0, #3
    adds r6, r5, r0
    .Lauto_080E4280:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E4280
    .Lauto_080E428C:
    ldr r1, [pc, #0x1c0]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E42AC
    adds r1, #0x14
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E42AC
    ldr r0, [pc, #0x1b0]
    adds r6, r5, r0
    .Lauto_080E42A0:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E42A0
    .Lauto_080E42AC:
    ldr r1, [pc, #0x1a4]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E42CC
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E42CC
    ldr r0, [pc, #0x194]
    adds r6, r5, r0
    .Lauto_080E42C0:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E42C0
    .Lauto_080E42CC:
    ldr r1, [pc, #0x188]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E42EC
    adds r1, #8
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E42EC
    ldr r0, [pc, #0x178]
    adds r6, r5, r0
    .Lauto_080E42E0:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E42E0
    .Lauto_080E42EC:
    movs r1, #0xf4
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4304
    ldr r0, [r1, #8]
    ldr r2, [r0, #0xc]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4304:
    ldr r1, [pc, #0x154]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E431A
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E431A:
    movs r1, #0xf3
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4332
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4332:
    ldr r1, [pc, #0x12c]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4348
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4348:
    movs r1, #0xf2
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4360
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4360:
    ldr r1, [pc, #0x100]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4376
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4376:
    movs r1, #0xf1
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E438E
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E438E:
    ldr r1, [pc, #0xd8]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E43A4
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E43A4:
    movs r1, #0xf0
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E43BC
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E43BC:
    ldr r0, [pc, #0xac]
    adds r4, r5, r0
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_080E43D2
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E43D2:
    ldr r1, [pc, #0x9c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E43F6
    cmp r0, r4
    beq .Lauto_080E43F6
    adds r6, r0, #0
    .Lauto_080E43E0:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r6, r4
    bne .Lauto_080E43E0
    .Lauto_080E43F6:
    ldr r1, [pc, #0x7c]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4494
    adds r1, #0x10
    adds r4, r5, r1
    cmp r0, r4
    b .Lauto_080E4478
    .byte 0x00, 0x00, 0xEC, 0x0A, 0x00, 0x00, 0xC8, 0x0A, 0x00, 0x00, 0xA4, 0x0A, 0x00, 0x00, 0x7C, 0x0A
    .byte 0x00, 0x00, 0x34, 0x0A, 0x00, 0x00, 0xE8, 0x09, 0x00, 0x00, 0xE4, 0x09, 0x00, 0x00, 0xBC, 0x09
    .byte 0x00, 0x00, 0x98, 0x09, 0x00, 0x00, 0x94, 0x09, 0x00, 0x00, 0x6C, 0x09, 0x00, 0x00, 0x24, 0x09
    .byte 0x00, 0x00, 0x1C, 0x09, 0x00, 0x00, 0xF8, 0x08, 0x00, 0x00, 0xF4, 0x08, 0x00, 0x00, 0xCC, 0x08
    .byte 0x00, 0x00, 0x84, 0x08, 0x00, 0x00, 0x7C, 0x08, 0x00, 0x00, 0xB4, 0x07, 0x00, 0x00, 0xAC, 0x07
    .byte 0x00, 0x00, 0xA4, 0x07, 0x00, 0x00, 0x9C, 0x07, 0x00, 0x00, 0x94, 0x07, 0x00, 0x00, 0x8C, 0x07
    .byte 0x00, 0x00, 0x84, 0x07, 0x00, 0x00, 0x7C, 0x07, 0x00, 0x00, 0x3C, 0x07, 0x00, 0x00, 0x2C, 0x07
    .byte 0x00, 0x00
    .Lauto_080E4478:
    beq .Lauto_080E4494
    ldr r0, [pc, #0x60]
    adds r6, r5, r0
    .Lauto_080E447E:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r6, r4
    bne .Lauto_080E447E
    .Lauto_080E4494:
    ldr r1, [pc, #0x48]
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    ldr r0, [pc, #0x38]
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r1, #0xe3
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E44CE
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E44CE:
    adds r0, r5, #0
    adds r1, r7, #0
    bl _._15HardwareContext
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x2C, 0x07, 0x00, 0x00, 0x24, 0x07, 0x00, 0x00, 0x1C, 0x07, 0x00, 0x00
    .global func_080E4D50
    .thumb_func
func_080E4D50:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r1, #0xb6
    lsls r1, r1, #3
    adds r0, r4, r1
    movs r1, #2
    bl .Lauto_080E46CC
    ldr r1, [pc, #0x19c]
    adds r0, r4, r1
    movs r1, #2
    bl func_080098AC
    movs r1, #0xb1
    lsls r1, r1, #3
    adds r0, r4, r1
    movs r1, #2
    bl func_080098AC
    ldr r1, [pc, #0x188]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xaa
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x178]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xa5
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x164]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xa0
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x154]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x9b
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x140]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x96
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x130]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x91
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x11c]
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0x8c
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x10c]
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E45C0
    ldr r0, [r1, #8]
    ldr r2, [r0, #0xc]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E45C0:
    movs r1, #0x87
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E45D8
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E45D8:
    ldr r1, [pc, #0xe0]
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E45EE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E45EE:
    movs r1, #0x86
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4606
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4606:
    ldr r1, [pc, #0xb8]
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E461C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E461C:
    movs r1, #0x85
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4634
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4634:
    ldr r1, [pc, #0x8c]
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E464A
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E464A:
    movs r1, #0x84
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4662
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4662:
    ldr r1, [pc, #0x64]
    adds r0, r4, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4678
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4678:
    movs r1, #0x83
    lsls r1, r1, #3
    adds r0, r4, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E468A
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E468A:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._15HardwareContext
    pop {r4, r5}
    pop {r0}
    bx r0
    .byte 0x94, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00, 0x2C, 0x05, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00
    .byte 0xDC, 0x04, 0x00, 0x00, 0xB4, 0x04, 0x00, 0x00, 0x8C, 0x04, 0x00, 0x00, 0x64, 0x04, 0x00, 0x00
    .byte 0x3C, 0x04, 0x00, 0x00, 0x34, 0x04, 0x00, 0x00, 0x2C, 0x04, 0x00, 0x00, 0x24, 0x04, 0x00, 0x00
    .byte 0x1C, 0x04, 0x00, 0x00
    .Lauto_080E46CC:
    .byte 0x70, 0xB5, 0x06, 0x1C, 0x0D, 0x1C, 0x34, 0x1C, 0x40, 0x34, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68
    .byte 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C
    .byte 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C
    .byte 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x71, 0x68, 0x30, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x30, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x01, 0x20, 0x28, 0x40, 0x00, 0x28, 0x02, 0xD0
    .byte 0x30, 0x1C
    bl __builtin_delete
    .byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .global func_080E4FF0
    .thumb_func
func_080E4FF0:
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    ldr r1, [pc, #0x258]
    adds r0, r5, r1
    movs r1, #2
    bl .Lauto_080E4ABC
    movs r1, #0x83
    lsls r1, r1, #4
    adds r0, r5, r1
    movs r1, #2
    bl func_080098AC
    ldr r1, [pc, #0x244]
    adds r0, r5, r1
    movs r1, #2
    bl func_080098AC
    ldr r1, [pc, #0x240]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xfd
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x22c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xf8
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x21c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xf3
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x208]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xea
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x1f8]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xe5
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x1e4]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E483C
    adds r1, #0x64
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E483C
    ldr r0, [pc, #0x1d4]
    adds r6, r5, r0
    .Lauto_080E4830:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E4830
    .Lauto_080E483C:
    movs r1, #0xd4
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x1bc]
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4868
    adds r1, #0x64
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4868
    ldr r0, [pc, #0x1ac]
    adds r6, r5, r0
    .Lauto_080E485C:
    subs r4, #4
    ldr r0, [r4]
    bl __builtin_delete
    cmp r6, r4
    bne .Lauto_080E485C
    .Lauto_080E4868:
    movs r1, #0xc3
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x194]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x184]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xb9
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x170]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xb4
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x160]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xaf
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x14c]
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    movs r1, #0xaa
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r0, [r0]
    bl __builtin_delete
    ldr r1, [pc, #0x13c]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E48F8
    ldr r0, [r1, #8]
    ldr r2, [r0, #0xc]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E48F8:
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4910
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4910:
    ldr r1, [pc, #0x110]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4926
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4926:
    movs r1, #0xa7
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E493E
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E493E:
    ldr r1, [pc, #0xe8]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4954
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4954:
    movs r1, #0xa6
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E496C
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E496C:
    ldr r1, [pc, #0xbc]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E4982
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E4982:
    movs r1, #0xa5
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E499A
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E499A:
    ldr r1, [pc, #0x94]
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E49B0
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E49B0:
    movs r1, #0xa4
    lsls r1, r1, #3
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_080E49C8
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080E49C8:
    ldr r1, [pc, #0x68]
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_080E49D8
    movs r1, #3
    bl _._12UiStateOwner
    .Lauto_080E49D8:
    adds r0, r5, #0
    adds r1, r7, #0
    bl _._15HardwareContext
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x3C, 0x08, 0x00, 0x00, 0x24, 0x08, 0x00, 0x00, 0xEC, 0x07, 0x00, 0x00, 0xC4, 0x07
    .byte 0x00, 0x00, 0x9C, 0x07, 0x00, 0x00, 0x54, 0x07, 0x00, 0x00, 0x2C, 0x07, 0x00, 0x00, 0xA4, 0x06
    .byte 0x00, 0x00, 0x1C, 0x06, 0x00, 0x00, 0xF4, 0x05, 0x00, 0x00, 0xCC, 0x05, 0x00, 0x00, 0xA4, 0x05
    .byte 0x00, 0x00, 0x7C, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x3C, 0x05
    .byte 0x00, 0x00, 0x34, 0x05, 0x00, 0x00, 0x2C, 0x05, 0x00, 0x00, 0x24, 0x05, 0x00, 0x00, 0x1C, 0x05
    .byte 0x00, 0x00
    .global loc_080E4A38
    .thumb_func
    loc_080E4A38:
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    bl InitializeObjTilePoolOwner
    movs r5, #0
    str r5, [r6, #4]
    adds r4, r6, #0
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r4, #8
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    str r5, [r4, #4]
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .Lauto_080E4ABC:
    .byte 0x70, 0xB5, 0x06, 0x1C, 0x0D, 0x1C, 0x34, 0x1C, 0x58, 0x34, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68
    .byte 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C
    .byte 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C
    .byte 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68, 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x08, 0x3C, 0x61, 0x68
    .byte 0x20, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x20, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x71, 0x68
    .byte 0x30, 0x1C
    bl ReleaseObjTileHandle
    .byte 0x30, 0x1C, 0x02, 0x21
    bl _._16ObjTilePoolOwner
    .byte 0x01, 0x20
    .byte 0x28, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x30, 0x1C
    bl __builtin_delete
    .byte 0x70, 0xBC, 0x01, 0xBC
    .byte 0x00, 0x47, 0x00, 0x00
    .section .text.after_menu_command_node_cleanup, "ax", %progbits
    .align 2, 0

    .global func_080E5898
    .thumb_func
func_080E5898:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    mov r8, r1
    movs r0, #0x84
    lsls r0, r0, #2
    adds r1, r5, r0
    ldr r0, [pc, #0xbc]
    str r0, [r1]
    movs r1, #0xbb
    lsls r1, r1, #2
    adds r0, r5, r1
    cmp r0, #0
    beq .Lauto_080E4D1A
    adds r1, #0x40
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4D1A
    movs r0, #0xbb
    lsls r0, r0, #2
    adds r6, r5, r0
    .Lauto_080E4D04:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    cmp r6, r4
    bne .Lauto_080E4D04
    .Lauto_080E4D1A:
    movs r1, #0xab
    lsls r1, r1, #2
    adds r0, r5, r1
    subs r1, #0x94
    adds r7, r5, r1
    cmp r0, #0
    beq .Lauto_080E4D4C
    adds r1, #0xd4
    adds r4, r5, r1
    cmp r0, r4
    beq .Lauto_080E4D4C
    movs r0, #0xab
    lsls r0, r0, #2
    adds r6, r5, r0
    .Lauto_080E4D36:
    subs r4, #8
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    cmp r6, r4
    bne .Lauto_080E4D36
    .Lauto_080E4D4C:
    movs r1, #0xa9
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjPaletteHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._19ObjPalettePoolOwner
    movs r0, #0xa7
    lsls r0, r0, #2
    adds r4, r5, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    movs r1, #0x85
    lsls r1, r1, #2
    adds r2, r5, r1
    ldr r1, [r2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, #4
    adds r2, r2, r0
    adds r0, r7, #0
    cmp r0, r2
    beq .Lauto_080E4D96
    .Lauto_080E4D90:
    adds r0, #0xc
    cmp r0, r2
    bne .Lauto_080E4D90
    .Lauto_080E4D96:
    adds r0, r5, #0
    mov r1, r8
    bl func_080CADF0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0xDC, 0x79, 0x0E, 0x08
    .section .text.after_menu_core_prefix_destructor, "ax", %progbits
    .align 2, 0

    .global func_080E4E00
    .thumb_func
func_080E4E00:
    push {lr}
    bl _._17GameSceneWorldMap
    pop {r0}
    bx r0
    .byte 0x00, 0x00
.else

	thumb_func_start func_080E0EF0
func_080E0EF0: @ 0x080E0EF0
	push {lr}
	bl _._13AScriptEngine
	pop {r0}
	bx r0
	.align 2, 0

    .section .text.code_080E0F48, "ax", %progbits
    .align 2, 0

	thumb_func_start Run__20UiDmaTransferCommand
Run__20UiDmaTransferCommand: @ 0x080E0F48
	push {r4, r5, lr}
	ldr r5, [r0, #0xc]
	movs r0, #0
	ldr r1, [r5]
	cmp r1, #0
	bne .L080E0F56
	movs r0, #1
.L080E0F56:
	cmp r0, #0
	bne .L080E0F86
	adds r4, r5, #4
	lsls r1, r1, #4
	adds r1, r4, r1
	adds r0, r4, #0
	bl ExecuteBiosTransfers
	ldr r0, [r5]
	lsls r0, r0, #4
	adds r0, #4
	adds r0, r5, r0
	adds r2, r0, #0
	adds r1, r4, #0
	ldr r3, [r5]
	cmp r1, r2
	beq .L080E0F7E
.L080E0F78:
	adds r1, #0x10
	cmp r1, r2
	bne .L080E0F78
.L080E0F7E:
	subs r0, r0, r4
	asrs r0, r0, #4
	subs r0, r3, r0
	str r0, [r5]
.L080E0F86:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.ui_text_output_base_after, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E118C
func_080E118C: @ 0x080E118C
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	cmp r2, #0xff
	bne .L080E11D4
	add r4, sp, #0x20
	ldrh r1, [r1, #4]
	adds r0, r4, #0
	bl __7ArticleUi
	adds r0, r4, #0
	bl GetName__C7Article
	adds r5, r0, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E11B4
	movs r4, #0x1f
.L080E11B4:
	mov r0, sp
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	mov r0, sp
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	adds r0, r6, #4
	mov r1, sp
	bl strcpy
	b .L080E11E2
.L080E11D4:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
	adds r0, r6, #4
	bl strcpy
.L080E11E2:
	adds r0, r6, #0
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_080E11EC
func_080E11EC: @ 0x080E11EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sl, r1
	ldr r0, .L080E148C @ =0x000023A0
	adds r1, r6, r0
	ldr r0, .L080E1490 @ =__vt_23ScriptTextVariableStore
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xa9
	lsls r2, r2, #3
	adds r0, r6, r2
	cmp r0, #0
	beq .L080E1232
	adds r1, #0x18
	adds r4, r6, r1
	cmp r0, r4
	beq .L080E1232
	adds r7, r0, #0
.L080E121C:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r7, r4
	bne .L080E121C
.L080E1232:
	ldr r1, [r5, #4]
	adds r0, r5, #0
	bl ReleaseObjTileHandle
	adds r0, r5, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r1, #0xe0
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xb0
	movs r2, #0x80
	adds r2, r2, r6
	mov sb, r2
	cmp r0, #0
	beq .L080E1296
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r5, r6, r1
	cmp r0, r5
	beq .L080E1296
.L080E1266:
	subs r5, #0x10
	adds r4, r5, #0
	adds r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	ldr r1, [r5, #4]
	adds r0, r5, #0
	bl ReleaseObjTileHandle
	adds r0, r5, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r6, r2
	cmp r0, r5
	bne .L080E1266
.L080E1296:
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0x9e
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0x9d
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x9c
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0x9a
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0x99
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0x98
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0x96
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0x94
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0x92
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0x91
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0x90
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0x8f
	lsls r1, r1, #3
	adds r4, r6, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, .L080E1494 @ =__vt_23IndexedResourceProvider
	str r0, [r1]
	subs r2, #0x30
	adds r1, r6, r2
	str r0, [r1]
	subs r2, #0x30
	adds r1, r6, r2
	str r0, [r1]
	subs r2, #0x30
	adds r1, r6, r2
	str r0, [r1]
	subs r2, #0x30
	adds r1, r6, r2
	str r0, [r1]
	mov r1, r8
	str r0, [r1]
	str r0, [r7]
	mov r2, sb
	str r0, [r2]
	str r0, [r6, #0x50]
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x10]
	cmp r0, #0
	beq .L080E1474
	movs r1, #3
	bl _._12UiStateOwner
.L080E1474:
	adds r0, r6, #0
	mov r1, sl
	bl _._15HardwareContext
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E148C: .4byte 0x000023A0
.L080E1490: .4byte __vt_23ScriptTextVariableStore
.L080E1494: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E1498
func_080E1498: @ 0x080E1498
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E14B4 @ =__vt_23ScriptTextVariableStore
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E14AE
	adds r0, r2, #0
	bl __builtin_delete
.L080E14AE:
	pop {r0}
	bx r0
	.align 2, 0
.L080E14B4: .4byte __vt_23ScriptTextVariableStore

	thumb_func_start func_080E14B8
func_080E14B8: @ 0x080E14B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r7, r0, #0
	adds r3, r1, #0
	adds r0, r2, #0
	subs r0, #0xfa
	cmp r0, #5
	bhi .L080E1578
	lsls r0, r0, #2
	ldr r1, .L080E14D4 @ =.L080E14D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080E14D4: .4byte .L080E14D8
.L080E14D8: @ jump table
	.4byte .L080E14F0 @ case 0
	.4byte .L080E1588 @ case 1
	.4byte .L080E1528 @ case 2
	.4byte .L080E152C @ case 3
	.4byte .L080E1530 @ case 4
	.4byte .L080E1534 @ case 5
.L080E14F0:
	ldr r0, [r3, #0x14]
	mov r1, sp
	movs r2, #0
	bl FormatSignedDecimal
	add r5, sp, #8
	mov r0, sp
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E150A
	movs r4, #0x1f
.L080E150A:
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl memcpy
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r7]
	adds r0, r7, #4
	adds r1, r5, #0
	bl strcpy
	b .L080E15B6
.L080E1528:
	ldr r1, [r3, #4]
	b .L080E1536
.L080E152C:
	ldr r1, [r3, #8]
	b .L080E1536
.L080E1530:
	ldr r1, [r3, #0xc]
	b .L080E1536
.L080E1534:
	ldr r1, [r3, #0x10]
.L080E1536:
	cmp r1, #0x80
	beq .L080E1588
	add r6, sp, #8
	movs r0, #0xd
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r0, .L080E1574 @ =gText_AnimalFestival_LivestockContestantNames
	adds r5, r5, r0
	adds r0, r5, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E1554
	movs r4, #0x1f
.L080E1554:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r7]
	adds r0, r7, #4
	adds r1, r6, #0
	bl strcpy
	b .L080E15B6
	.align 2, 0
.L080E1574: .4byte gText_AnimalFestival_LivestockContestantNames
.L080E1578:
	add r1, sp, #8
	movs r0, #0
	strb r0, [r1]
	strb r0, [r7]
	adds r0, r7, #4
	bl strcpy
	b .L080E15B6
.L080E1588:
	ldr r5, [r3, #0x18]
	adds r0, r5, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E1598
	movs r4, #0x1f
.L080E1598:
	mov r0, sp
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	mov r0, sp
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r7]
	adds r0, r7, #4
	mov r1, sp
	bl strcpy
.L080E15B6:
	adds r0, r7, #0
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_080E15C0
func_080E15C0: @ 0x080E15C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	movs r0, #0xa7
	lsls r0, r0, #5
	adds r1, r7, r0
	ldr r0, .L080E181C @ =__vt_23ScriptTextVariableStore
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	cmp r0, #0
	beq .L080E162C
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r5, r7, r2
	cmp r0, r5
	beq .L080E162C
.L080E15E8:
	subs r5, #0x18
	adds r0, r5, #0
	adds r0, #8
	cmp r0, #0
	beq .L080E1612
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, r4
	beq .L080E1612
	adds r6, r0, #0
.L080E15FC:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r6, r4
	bne .L080E15FC
.L080E1612:
	ldr r1, [r5, #4]
	adds r0, r5, #0
	bl ReleaseObjTileHandle
	adds r0, r5, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	cmp r0, r5
	bne .L080E15E8
.L080E162C:
	movs r2, #0xca
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xc9
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xc7
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0xc2
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0xbe
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xbd
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xbb
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xba
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, .L080E1820 @ =__vt_23IndexedResourceProvider
	str r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	subs r2, #0x30
	adds r1, r7, r2
	str r0, [r1]
	subs r2, #0x30
	adds r1, r7, r2
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xe0
	str r0, [r1]
	subs r1, #0x30
	str r0, [r1]
	subs r1, #0x30
	str r0, [r1]
	str r0, [r7, #0x50]
	str r0, [r7, #0x20]
	ldr r0, [r7, #0x10]
	cmp r0, #0
	beq .L080E180A
	movs r1, #3
	bl _._12UiStateOwner
.L080E180A:
	adds r0, r7, #0
	mov r1, r8
	bl _._15HardwareContext
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E181C: .4byte __vt_23ScriptTextVariableStore
.L080E1820: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E1824
func_080E1824: @ 0x080E1824
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E1840 @ =__vt_23ScriptTextVariableStore
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E183A
	adds r0, r2, #0
	bl __builtin_delete
.L080E183A:
	pop {r0}
	bx r0
	.align 2, 0
.L080E1840: .4byte __vt_23ScriptTextVariableStore

	thumb_func_start func_080E1844
func_080E1844: @ 0x080E1844
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r6, r0, #0
	cmp r2, #0xff
	bne .L080E188C
	ldr r0, [r1, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, .L080E1888 @ =gHorseRacePrizeCatalog
	adds r5, r1, r0
	adds r0, r5, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E1868
	movs r4, #0x1f
.L080E1868:
	mov r0, sp
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	mov r0, sp
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	adds r0, r6, #4
	mov r1, sp
	bl strcpy
	b .L080E189A
	.align 2, 0
.L080E1888: .4byte gHorseRacePrizeCatalog
.L080E188C:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
	adds r0, r6, #4
	bl strcpy
.L080E189A:
	adds r0, r6, #0
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_080E18A4
func_080E18A4: @ 0x080E18A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, .L080E1958 @ =0x00000AEC
	adds r1, r5, r0
	ldr r0, .L080E195C @ =__vt_23ScriptTextVariableStore
	str r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r0, .L080E1960 @ =__vt_23IndexedResourceProvider
	str r0, [r5, #0x50]
	str r0, [r5, #0x20]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq .L080E1948
	movs r1, #3
	bl _._12UiStateOwner
.L080E1948:
	adds r0, r5, #0
	adds r1, r6, #0
	bl _._15HardwareContext
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080E1958: .4byte 0x00000AEC
.L080E195C: .4byte __vt_23ScriptTextVariableStore
.L080E1960: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E1964
func_080E1964: @ 0x080E1964
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E1980 @ =__vt_23ScriptTextVariableStore
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E197A
	adds r0, r2, #0
	bl __builtin_delete
.L080E197A:
	pop {r0}
	bx r0
	.align 2, 0
.L080E1980: .4byte __vt_23ScriptTextVariableStore

    .section .text.indexed_resource_archive_destructor_after, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E1A48
func_080E1A48: @ 0x080E1A48
	push {lr}
	bl func_08076EA8
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start func_080E1A54
func_080E1A54: @ 0x080E1A54
	push {lr}
	ldr r2, .L080E1A68 @ =0x000009C4
	adds r3, r0, r2
	ldr r2, .L080E1A6C @ =__vt_23IndexedResourceProvider
	str r2, [r3]
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0
.L080E1A68: .4byte 0x000009C4
.L080E1A6C: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E1A70
func_080E1A70: @ 0x080E1A70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	bl func_08076EA8
	movs r0, #0
	mov r8, r0
	ldr r1, .L080E1C08 @ =0x00001268
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x30
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge .L080E1AB4
	adds r2, r1, #0
	ldr r3, .L080E1C08 @ =0x00001268
	adds r1, r7, r3
.L080E1AA4:
	adds r1, #0x10
	movs r0, #1
	add r8, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #0x30
	cmp r0, r2
	blt .L080E1AA4
.L080E1AB4:
	ldr r1, .L080E1C0C @ =0x00001264
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, .L080E1C10 @ =0x0000163C
	adds r2, r7, r2
	str r2, [sp, #0x20]
	cmp r8, r0
	bhs .L080E1B40
	adds r3, r1, #0
	adds r3, r3, r7
	mov sl, r3
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #4
	ldr r2, .L080E1C08 @ =0x00001268
	adds r0, r0, r2
	adds r5, r0, r7
.L080E1ADC:
	movs r3, #0
	ldrsh r1, [r5, r3]
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #0xa0
	cmp r1, r0
	bgt .L080E1B32
	ldr r0, [r7]
	bl GetHardwareSpriteBuffer
	adds r4, r0, #0
	movs r0, #0
	ldrsh r2, [r5, r0]
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	ldr r1, [r5, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	add r6, sp, #0x10
	adds r0, r6, #0
	movs r3, #0x10
	bl func_0804EA94
	ldrb r2, [r4]
	cmp r2, #0x7f
	bhi .L080E1B32
	lsls r1, r2, #3
	adds r1, #4
	adds r1, r4, r1
	ldr r0, [sp, #0x10]
	str r0, [r1]
	ldrh r0, [r6, #4]
	strh r0, [r1, #4]
	adds r0, r2, #1
	strb r0, [r4]
.L080E1B32:
	adds r5, #0x10
	movs r0, #1
	add r8, r0
	mov r1, sl
	ldr r0, [r1]
	cmp r8, r0
	blo .L080E1ADC
.L080E1B40:
	movs r2, #0
	mov r8, r2
	ldr r3, [sp, #0x20]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, #0x30
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	bge .L080E1B70
	adds r2, r1, #0
	ldr r0, .L080E1C10 @ =0x0000163C
	adds r1, r7, r0
.L080E1B60:
	adds r1, #0x10
	movs r3, #1
	add r8, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #0x30
	cmp r0, r2
	blt .L080E1B60
.L080E1B70:
	ldr r1, .L080E1C14 @ =0x00001638
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r8, r0
	bhs .L080E1BF4
	adds r2, r1, #0
	adds r2, r2, r7
	mov sl, r2
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sb, r3
	mov r1, r8
	lsls r0, r1, #4
	ldr r2, .L080E1C10 @ =0x0000163C
	adds r0, r0, r2
	adds r6, r0, r7
.L080E1B92:
	movs r3, #0
	ldrsh r1, [r6, r3]
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #0xa0
	cmp r1, r0
	bgt .L080E1BE6
	ldr r0, [r7]
	bl GetHardwareSpriteBuffer
	adds r4, r0, #0
	movs r0, #0
	ldrsh r2, [r6, r0]
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	ldr r1, [r6, #4]
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r5, sp, #0x18
	adds r0, r5, #0
	movs r3, #5
	bl func_0804EA94
	ldrb r2, [r4]
	cmp r2, #0x7f
	bhi .L080E1BE6
	lsls r1, r2, #3
	adds r1, #4
	adds r1, r4, r1
	ldr r0, [sp, #0x18]
	str r0, [r1]
	ldrh r0, [r5, #4]
	strh r0, [r1, #4]
	adds r0, r2, #1
	strb r0, [r4]
.L080E1BE6:
	adds r6, #0x10
	movs r0, #1
	add r8, r0
	mov r1, sl
	ldr r0, [r1]
	cmp r8, r0
	blo .L080E1B92
.L080E1BF4:
	movs r0, #1
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080E1C08: .4byte 0x00001268
.L080E1C0C: .4byte 0x00001264
.L080E1C10: .4byte 0x0000163C
.L080E1C14: .4byte 0x00001638

	thumb_func_start func_080E1C18
func_080E1C18: @ 0x080E1C18
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, .L080E1C60 @ =0x00001638
	adds r1, r2, r0
	ldr r0, [r1]
	lsls r0, r0, #4
	adds r0, #4
	adds r1, r1, r0
	ldr r4, .L080E1C64 @ =0x0000163C
	adds r0, r2, r4
	cmp r0, r1
	beq .L080E1C38
.L080E1C32:
	adds r0, #0x10
	cmp r0, r1
	bne .L080E1C32
.L080E1C38:
	ldr r0, .L080E1C68 @ =0x00001264
	adds r1, r2, r0
	ldr r0, [r1]
	lsls r0, r0, #4
	adds r0, #4
	adds r1, r1, r0
	ldr r4, .L080E1C6C @ =0x00001268
	adds r0, r2, r4
	cmp r0, r1
	beq .L080E1C52
.L080E1C4C:
	adds r0, #0x10
	cmp r0, r1
	bne .L080E1C4C
.L080E1C52:
	adds r0, r2, #0
	adds r1, r3, #0
	bl func_08076E0C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E1C60: .4byte 0x00001638
.L080E1C64: .4byte 0x0000163C
.L080E1C68: .4byte 0x00001264
.L080E1C6C: .4byte 0x00001268

	thumb_func_start func_080E1C70
func_080E1C70: @ 0x080E1C70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	bl func_08076EA8
	movs r0, #0
	mov r8, r0
	ldr r1, .L080E1D4C @ =0x00002168
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x30
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge .L080E1CB4
	adds r2, r1, #0
	ldr r3, .L080E1D4C @ =0x00002168
	adds r1, r7, r3
.L080E1CA4:
	adds r1, #0x10
	movs r0, #1
	add r8, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #0x30
	cmp r0, r2
	blt .L080E1CA4
.L080E1CB4:
	ldr r1, .L080E1D50 @ =0x00002164
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r8, r0
	bhs .L080E1D38
	adds r2, r1, #0
	adds r2, r2, r7
	mov sl, r2
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sb, r3
	mov r1, r8
	lsls r0, r1, #4
	ldr r2, .L080E1D4C @ =0x00002168
	adds r0, r0, r2
	adds r5, r0, r7
.L080E1CD6:
	movs r3, #0
	ldrsh r1, [r5, r3]
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #0xa0
	cmp r1, r0
	bgt .L080E1D2A
	ldr r0, [r7]
	bl GetHardwareSpriteBuffer
	adds r4, r0, #0
	movs r0, #0
	ldrsh r2, [r5, r0]
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	ldr r1, [r5, #4]
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r6, sp, #0x10
	adds r0, r6, #0
	movs r3, #5
	bl func_0804EA94
	ldrb r2, [r4]
	cmp r2, #0x7f
	bhi .L080E1D2A
	lsls r1, r2, #3
	adds r1, #4
	adds r1, r4, r1
	ldr r0, [sp, #0x10]
	str r0, [r1]
	ldrh r0, [r6, #4]
	strh r0, [r1, #4]
	adds r0, r2, #1
	strb r0, [r4]
.L080E1D2A:
	adds r5, #0x10
	movs r0, #1
	add r8, r0
	mov r1, sl
	ldr r0, [r1]
	cmp r8, r0
	blo .L080E1CD6
.L080E1D38:
	movs r0, #1
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080E1D4C: .4byte 0x00002168
.L080E1D50: .4byte 0x00002164

	thumb_func_start func_080E1D54
func_080E1D54: @ 0x080E1D54
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, .L080E1D84 @ =0x00002164
	adds r1, r2, r0
	ldr r0, [r1]
	lsls r0, r0, #4
	adds r0, #4
	adds r1, r1, r0
	ldr r4, .L080E1D88 @ =0x00002168
	adds r0, r2, r4
	cmp r0, r1
	beq .L080E1D74
.L080E1D6E:
	adds r0, #0x10
	cmp r0, r1
	bne .L080E1D6E
.L080E1D74:
	adds r0, r2, #0
	adds r1, r3, #0
	bl func_08076E0C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E1D84: .4byte 0x00002164
.L080E1D88: .4byte 0x00002168

	thumb_func_start func_080E1D8C
func_080E1D8C: @ 0x080E1D8C
	push {lr}
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E1D98
func_080E1D98: @ 0x080E1D98
	push {lr}
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E1DA4
func_080E1DA4: @ 0x080E1DA4
	push {lr}
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E1DB0
func_080E1DB0: @ 0x080E1DB0
	push {lr}
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E1DBC
func_080E1DBC: @ 0x080E1DBC
	push {lr}
	bl func_08076EA8
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start func_080E1DC8
func_080E1DC8: @ 0x080E1DC8
	push {lr}
	bl func_08076E0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E1DD4
func_080E1DD4: @ 0x080E1DD4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r1, r0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r2, .L080E1E20 @ =__vt_23IndexedResourceProvider
	cmp r0, r1
	beq .L080E1DFA
.L080E1DF4:
	adds r0, #8
	cmp r0, r1
	bne .L080E1DF4
.L080E1DFA:
	str r2, [r4, #0xc]
	ldr r1, [r4, #8]
	cmp r1, #0
	beq .L080E1E12
	ldr r2, .L080E1E24 @ =0x000005B4
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E1E12:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15HardwareContext
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E1E20: .4byte __vt_23IndexedResourceProvider
.L080E1E24: .4byte 0x000005B4

	thumb_func_start func_080E1E28
func_080E1E28: @ 0x080E1E28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	ldr r1, .L080E1F80 @ =0x00004120
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E1E5E
	adds r1, #0x50
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E1E5E
	ldr r0, .L080E1F80 @ =0x00004120
	adds r6, r5, r0
.L080E1E48:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r6, r4
	bne .L080E1E48
.L080E1E5E:
	ldr r1, .L080E1F84 @ =0x000040D0
	adds r0, r5, r1
	ldr r1, .L080E1F88 @ =0x00003FA8
	adds r7, r5, r1
	ldr r1, .L080E1F8C @ =0x00003EA4
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq .L080E1E92
	ldr r1, .L080E1F80 @ =0x00004120
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E1E92
	ldr r0, .L080E1F84 @ =0x000040D0
	adds r6, r5, r0
.L080E1E7C:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	cmp r6, r4
	bne .L080E1E7C
.L080E1E92:
	ldr r1, .L080E1F90 @ =0x000040C8
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	ldr r0, .L080E1F94 @ =0x000040C0
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, .L080E1F98 @ =0x000040B8
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	ldr r0, .L080E1F9C @ =0x000040B0
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, .L080E1FA0 @ =0x00003FA4
	adds r2, r5, r1
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	adds r2, r2, r0
	adds r0, r7, #0
	cmp r0, r2
	beq .L080E1EFE
.L080E1EF8:
	adds r0, #0xc
	cmp r0, r2
	bne .L080E1EF8
.L080E1EFE:
	ldr r0, .L080E1FA4 @ =0x00003EA0
	adds r1, r5, r0
	ldr r0, [r1]
	lsls r0, r0, #4
	adds r0, #4
	adds r1, r1, r0
	mov r0, r8
	cmp r0, r1
	beq .L080E1F16
.L080E1F10:
	adds r0, #0x10
	cmp r0, r1
	bne .L080E1F10
.L080E1F16:
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #2
	bl _._12UiStateOwner
	ldr r0, .L080E1FA8 @ =__vt_23IndexedResourceProvider
	str r0, [r5, #0x54]
	str r0, [r5, #0x24]
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080E1F5A
	adds r4, r0, #0
	adds r0, #0x28
	movs r1, #2
	bl _._25ScrollBufferUploadCommand
	adds r0, r4, #0
	adds r0, #0x18
	ldr r2, [r0, #4]
	ldr r1, [r4, #0x18]
	cmp r1, r2
	beq .L080E1F4A
.L080E1F44:
	adds r1, #0x40
	cmp r1, r2
	bne .L080E1F44
.L080E1F4A:
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E1F54
	bl free
.L080E1F54:
	adds r0, r4, #0
	bl __builtin_delete
.L080E1F5A:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq .L080E1F6C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E1F6C:
	adds r0, r5, #0
	mov r1, sb
	bl _._15HardwareContext
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E1F80: .4byte 0x00004120
.L080E1F84: .4byte 0x000040D0
.L080E1F88: .4byte 0x00003FA8
.L080E1F8C: .4byte 0x00003EA4
.L080E1F90: .4byte 0x000040C8
.L080E1F94: .4byte 0x000040C0
.L080E1F98: .4byte 0x000040B8
.L080E1F9C: .4byte 0x000040B0
.L080E1FA0: .4byte 0x00003FA4
.L080E1FA4: .4byte 0x00003EA0
.L080E1FA8: .4byte __vt_23IndexedResourceProvider

    .section .text.new_game_birthday_core_cleanup_after, "ax", %progbits

	thumb_func_start func_080E2018
func_080E2018: @ 0x080E2018
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r0, #0xe0
	cmp r0, #0
	beq .L080E203E
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E203E
	adds r6, r0, #0
.L080E2030:
	subs r4, #0x30
	adds r0, r4, #0
	movs r1, #0
	bl func_080E20C0
	cmp r6, r4
	bne .L080E2030
.L080E203E:
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r2, [r0, #4]
	ldr r1, [r0]
	adds r4, r5, #0
	adds r4, #0xa0
	adds r6, r5, #0
	adds r6, #0x18
	cmp r1, r2
	beq .L080E2058
.L080E2052:
	adds r1, #0x1c
	cmp r1, r2
	bne .L080E2052
.L080E2058:
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E2062
	bl free
.L080E2062:
	ldr r0, .L080E2090 @ =__vt_23IndexedResourceProvider
	str r0, [r4]
	str r0, [r5, #0x20]
	adds r0, r6, #0
	movs r1, #2
	bl func_080756D0
	ldr r1, [r5, #0xc]
	cmp r1, #0
	beq .L080E2082
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E2082:
	adds r0, r5, #0
	adds r1, r7, #0
	bl _._15HardwareContext
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E2090: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E2094
func_080E2094: @ 0x080E2094
	sub sp, #0xc
	adds r2, r0, #0
	movs r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	adds r1, r2, #0
	adds r1, #8
	str r0, [r1, #4]
	adds r1, #8
	str r0, [r2, #0x10]
	str r0, [r1, #4]
	adds r1, #8
	str r0, [r1, #4]
	adds r1, #8
	str r0, [r2, #0x20]
	str r0, [r1, #4]
	adds r1, #8
	str r0, [r1, #4]
	adds r0, r2, #0
	add sp, #0xc
	bx lr
	.align 2, 0

	thumb_func_start func_080E20C0
func_080E20C0: @ 0x080E20C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq .L080E20D0
	bl free
.L080E20D0:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq .L080E20DA
	bl free
.L080E20DA:
	ldr r0, [r4]
	cmp r0, #0
	beq .L080E20E4
	bl free
.L080E20E4:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E20F2
	adds r0, r4, #0
	bl __builtin_delete
.L080E20F2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_080E20F8
func_080E20F8: @ 0x080E20F8
	push {lr}
	bl func_08070C88
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2104
func_080E2104: @ 0x080E2104
	push {lr}
	bl func_08070C88
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2110
func_080E2110: @ 0x080E2110
	push {lr}
	bl func_08070C88
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E211C
func_080E211C: @ 0x080E211C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	lsls r0, r0, #3
	adds r0, #4
	adds r1, r1, r0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r2, .L080E2168 @ =__vt_23IndexedResourceProvider
	cmp r0, r1
	beq .L080E2142
.L080E213C:
	adds r0, #8
	cmp r0, r1
	bne .L080E213C
.L080E2142:
	str r2, [r4, #0xc]
	ldr r1, [r4, #8]
	cmp r1, #0
	beq .L080E215A
	ldr r2, .L080E216C @ =0x000005B4
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E215A:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15HardwareContext
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E2168: .4byte __vt_23IndexedResourceProvider
.L080E216C: .4byte 0x000005B4

	thumb_func_start func_080E2170
func_080E2170: @ 0x080E2170
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0xc]
	ldr r0, [r3, #8]
	str r0, [r2, #0xc]
	ldr r0, [r3, #8]
	cmp r0, #0
	beq .L080E2182
	str r2, [r0, #4]
.L080E2182:
	ldr r0, [r2, #4]
	str r0, [r3, #4]
	ldr r0, [r1]
	cmp r2, r0
	bne .L080E2190
	str r3, [r1]
	b .L080E219E
.L080E2190:
	ldr r1, [r2, #4]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E219C
	str r3, [r1, #8]
	b .L080E219E
.L080E219C:
	str r3, [r1, #0xc]
.L080E219E:
	str r2, [r3, #8]
	str r3, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E21A8
func_080E21A8: @ 0x080E21A8
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #8]
	ldr r0, [r3, #0xc]
	str r0, [r2, #8]
	ldr r0, [r3, #0xc]
	cmp r0, #0
	beq .L080E21BA
	str r2, [r0, #4]
.L080E21BA:
	ldr r0, [r2, #4]
	str r0, [r3, #4]
	ldr r0, [r1]
	cmp r2, r0
	bne .L080E21C8
	str r3, [r1]
	b .L080E21D6
.L080E21C8:
	ldr r1, [r2, #4]
	ldr r0, [r1, #0xc]
	cmp r2, r0
	bne .L080E21D4
	str r3, [r1, #0xc]
	b .L080E21D6
.L080E21D4:
	str r3, [r1, #8]
.L080E21D6:
	str r2, [r3, #0xc]
	str r3, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E21E0
func_080E21E0: @ 0x080E21E0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	strb r0, [r4]
	ldr r0, [r5]
	cmp r4, r0
	beq .L080E2286
	ldr r2, [r4, #4]
	ldrb r0, [r2]
	cmp r0, #0
	bne .L080E2286
	movs r6, #1
	movs r7, #0
.L080E21FC:
	ldr r1, [r2, #4]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E2238
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq .L080E2210
	ldrb r1, [r0]
	cmp r1, #0
	beq .L080E2242
.L080E2210:
	ldr r1, [r4, #4]
	ldr r0, [r1, #0xc]
	cmp r4, r0
	bne .L080E2222
	adds r4, r1, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_080E2170
.L080E2222:
	ldr r0, [r4, #4]
	strb r6, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	strb r7, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	adds r1, r5, #0
	bl func_080E21A8
	b .L080E2278
.L080E2238:
	cmp r0, #0
	beq .L080E2252
	ldrb r1, [r0]
	cmp r1, #0
	bne .L080E2252
.L080E2242:
	strb r6, [r2]
	strb r6, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	strb r1, [r0]
	ldr r0, [r4, #4]
	ldr r4, [r0, #4]
	b .L080E2278
.L080E2252:
	ldr r1, [r4, #4]
	ldr r0, [r1, #8]
	cmp r4, r0
	bne .L080E2264
	adds r4, r1, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_080E21A8
.L080E2264:
	ldr r0, [r4, #4]
	strb r6, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	strb r7, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	adds r1, r5, #0
	bl func_080E2170
.L080E2278:
	ldr r0, [r5]
	cmp r4, r0
	beq .L080E2286
	ldr r2, [r4, #4]
	ldrb r0, [r2]
	cmp r0, #0
	beq .L080E21FC
.L080E2286:
	ldr r1, [r5]
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2294
func_080E2294: @ 0x080E2294
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x14]
	adds r5, r3, #0
	ldr r0, [r6, #4]
	cmp r5, r0
	beq .L080E22BE
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080E22FE
	cmp r2, #0
	bne .L080E22BE
	movs r2, #0
	ldr r1, [r4]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bhs .L080E22BA
	movs r2, #1
.L080E22BA:
	cmp r2, #0
	beq .L080E22FE
.L080E22BE:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E22D2
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E22D2:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E22E2
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E22E2:
	adds r4, r2, #0
	str r4, [r5, #8]
	ldr r1, [r6, #4]
	cmp r5, r1
	bne .L080E22F4
	str r4, [r5, #4]
	ldr r0, [r6, #4]
	str r4, [r0, #0xc]
	b .L080E2330
.L080E22F4:
	ldr r0, [r1, #8]
	cmp r5, r0
	bne .L080E2330
	str r4, [r1, #8]
	b .L080E2330
.L080E22FE:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E2312
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E2312:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E2322
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E2322:
	adds r4, r2, #0
	str r4, [r5, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [r1, #0xc]
	cmp r5, r0
	bne .L080E2330
	str r4, [r1, #0xc]
.L080E2330:
	str r5, [r4, #4]
	movs r0, #0
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r6, #4]
	adds r1, #4
	adds r0, r4, #0
	bl func_080E21E0
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	str r4, [r7]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E2354
func_080E2354: @ 0x080E2354
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	bne .L080E236A
	ldr r0, [r2, #4]
	ldr r0, [r0, #4]
	cmp r0, r2
	bne .L080E236A
	ldr r2, [r2, #0xc]
	b .L080E238A
.L080E236A:
	ldr r0, [r2, #8]
	cmp r0, #0
	beq .L080E2380
	adds r1, r0, #0
	b .L080E2376
.L080E2374:
	ldr r1, [r1, #0xc]
.L080E2376:
	ldr r0, [r1, #0xc]
	cmp r0, #0
	bne .L080E2374
	b .L080E2388
.L080E237E:
	adds r2, r1, #0
.L080E2380:
	ldr r1, [r2, #4]
	ldr r0, [r1, #8]
	cmp r2, r0
	beq .L080E237E
.L080E2388:
	adds r2, r1, #0
.L080E238A:
	adds r0, r2, #0
	pop {r1}
	bx r1

	thumb_func_start func_080E2390
func_080E2390: @ 0x080E2390
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	ldr r4, [r1, #4]
	ldr r5, [r4, #4]
	movs r0, #1
	cmp r5, #0
	beq .L080E23C6
	ldr r2, [r7]
.L080E23AA:
	adds r4, r5, #0
	movs r1, #0
	ldr r0, [r4, #0x10]
	cmp r2, r0
	bhs .L080E23B6
	movs r1, #1
.L080E23B6:
	adds r0, r1, #0
	cmp r0, #0
	beq .L080E23C0
	ldr r5, [r4, #8]
	b .L080E23C2
.L080E23C0:
	ldr r5, [r4, #0xc]
.L080E23C2:
	cmp r5, #0
	bne .L080E23AA
.L080E23C6:
	str r4, [sp, #8]
	cmp r0, #0
	beq .L080E2400
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	movs r1, #0
	cmp r4, r0
	bne .L080E23DC
	movs r1, #1
.L080E23DC:
	cmp r1, #0
	beq .L080E23F8
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x10
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E2294
	movs r1, #1
	ldr r0, [sp, #0x10]
	b .L080E242A
.L080E23F8:
	adds r0, r4, #0
	bl func_080E2354
	str r0, [sp, #8]
.L080E2400:
	ldr r2, [sp, #8]
	movs r3, #0
	ldr r1, [r2, #0x10]
	ldr r0, [r7]
	cmp r1, r0
	bhs .L080E240E
	movs r3, #1
.L080E240E:
	adds r0, r3, #0
	cmp r0, #0
	beq .L080E2430
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E2294
	movs r1, #1
	ldr r0, [sp, #0xc]
.L080E242A:
	str r0, [r6]
	strb r1, [r6, #4]
	b .L080E2434
.L080E2430:
	str r2, [r6]
	strb r0, [r6, #4]
.L080E2434:
	adds r0, r6, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E2444
func_080E2444: @ 0x080E2444
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, [r6, #4]
	ldr r2, [r2]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E24D4
	ldr r0, [r6, #8]
	cmp r0, #0
	bne .L080E2474
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2390
	ldr r0, [sp, #8]
	b .L080E25E8
.L080E2474:
	movs r0, #0
	ldr r1, [r2, #0x10]
	adds r3, r2, #0
	ldr r2, [r4]
	cmp r2, r1
	bhs .L080E2482
	movs r0, #1
.L080E2482:
	mov sb, r0
	cmp r0, #0
	bne .L080E2548
	movs r0, #0
	cmp r1, r2
	bhs .L080E2490
	movs r0, #1
.L080E2490:
	cmp r0, #0
	bne .L080E2498
	str r3, [r7]
	b .L080E25EA
.L080E2498:
	str r3, [sp, #8]
	adds r0, r3, #0
	bl func_080E2B28
	adds r2, r0, #0
	str r2, [sp, #8]
	ldr r0, [r6, #4]
	cmp r2, r0
	bne .L080E24B0
	mov r0, r8
	ldr r3, [r0]
	b .L080E25AE
.L080E24B0:
	movs r3, #0
	ldr r1, [r4]
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r1, r0
	bhs .L080E24BE
	movs r3, #1
.L080E24BE:
	cmp r3, #0
	bne .L080E24C4
	b .L080E25DC
.L080E24C4:
	mov r1, r8
	ldr r3, [r1]
	ldr r0, [r3, #0xc]
	cmp r0, #0
	beq .L080E25AE
	str r4, [sp]
	mov r0, sb
	b .L080E25C2
.L080E24D4:
	cmp r2, r1
	bne .L080E24FE
	ldr r3, [r2, #0xc]
	movs r5, #0
	ldr r1, [r3, #0x10]
	ldr r0, [r4]
	cmp r1, r0
	bhs .L080E24E6
	movs r5, #1
.L080E24E6:
	cmp r5, #0
	beq .L080E24F0
	str r4, [sp]
	str r2, [sp, #4]
	b .L080E25B2
.L080E24F0:
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2390
	ldr r0, [sp, #8]
	b .L080E25E8
.L080E24FE:
	str r2, [sp, #8]
	adds r0, r2, #0
	bl func_080E2354
	adds r2, r0, #0
	str r2, [sp, #8]
	mov r1, r8
	ldr r3, [r1]
	movs r5, #0
	ldr r1, [r4]
	ldr r0, [r3, #0x10]
	cmp r1, r0
	bhs .L080E251A
	movs r5, #1
.L080E251A:
	mov sb, r5
	cmp r5, #0
	beq .L080E255A
	movs r0, #0
	mov ip, r0
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r0, r1
	bhs .L080E2530
	movs r1, #1
	mov ip, r1
.L080E2530:
	mov r0, ip
	cmp r0, #0
	beq .L080E255A
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne .L080E2548
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	b .L080E25CA
.L080E2548:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r3, #0
	bl func_080E2294
	b .L080E25EA
.L080E255A:
	mov r1, r8
	ldr r0, [r1]
	str r0, [sp, #0xc]
	bl func_080E2B28
	mov ip, r0
	str r0, [sp, #0xc]
	movs r0, #1
	mov r1, sb
	eors r1, r0
	mov r0, sb
	cmp r0, #0
	bne .L080E25D2
	mov r1, r8
	ldr r0, [r1]
	movs r5, #0
	ldr r1, [r0, #0x10]
	adds r3, r0, #0
	ldr r2, [r4]
	cmp r1, r2
	bhs .L080E2586
	movs r5, #1
.L080E2586:
	adds r1, r5, #0
	cmp r1, #0
	beq .L080E25D2
	ldr r0, [r6, #4]
	mov r5, ip
	cmp r5, r0
	beq .L080E25A8
	movs r0, #0
	mov ip, r0
	ldr r0, [r5, #0x10]
	cmp r2, r0
	bhs .L080E25A2
	movs r0, #1
	mov ip, r0
.L080E25A2:
	mov r0, ip
	cmp r0, #0
	beq .L080E25D2
.L080E25A8:
	ldr r0, [r3, #0xc]
	cmp r0, #0
	bne .L080E25BE
.L080E25AE:
	str r4, [sp]
	str r3, [sp, #4]
.L080E25B2:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl func_080E2294
	b .L080E25EA
.L080E25BE:
	str r4, [sp]
	movs r0, #0
.L080E25C2:
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
.L080E25CA:
	adds r3, r5, #0
	bl func_080E2294
	b .L080E25EA
.L080E25D2:
	cmp sb, r1
	bne .L080E25DC
	mov r1, r8
	ldr r0, [r1]
	b .L080E25E8
.L080E25DC:
	add r0, sp, #0x10
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2390
	ldr r0, [sp, #0x10]
.L080E25E8:
	str r0, [r7]
.L080E25EA:
	adds r0, r7, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E25FC
func_080E25FC: @ 0x080E25FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r1
	adds r7, r5, #0
	ldr r1, [r7, #8]
	cmp r1, #0
	beq .L080E2624
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne .L080E2618
	adds r6, r1, #0
	b .L080E2626
.L080E2618:
	adds r7, r0, #0
	b .L080E261E
.L080E261C:
	ldr r7, [r7, #8]
.L080E261E:
	ldr r0, [r7, #8]
	cmp r0, #0
	bne .L080E261C
.L080E2624:
	ldr r6, [r7, #0xc]
.L080E2626:
	cmp r7, r5
	beq .L080E267A
	ldr r0, [r5, #8]
	str r7, [r0, #4]
	ldr r0, [r5, #8]
	str r0, [r7, #8]
	ldr r0, [r5, #0xc]
	cmp r7, r0
	beq .L080E264E
	ldr r4, [r7, #4]
	cmp r6, #0
	beq .L080E2640
	str r4, [r6, #4]
.L080E2640:
	ldr r0, [r7, #4]
	str r6, [r0, #8]
	ldr r0, [r5, #0xc]
	str r0, [r7, #0xc]
	ldr r0, [r5, #0xc]
	str r7, [r0, #4]
	b .L080E2650
.L080E264E:
	adds r4, r7, #0
.L080E2650:
	mov r1, r8
	ldr r0, [r1]
	cmp r0, r5
	bne .L080E265C
	str r7, [r1]
	b .L080E266A
.L080E265C:
	ldr r1, [r5, #4]
	ldr r0, [r1, #8]
	cmp r0, r5
	bne .L080E2668
	str r7, [r1, #8]
	b .L080E266A
.L080E2668:
	str r7, [r1, #0xc]
.L080E266A:
	ldr r0, [r5, #4]
	str r0, [r7, #4]
	ldrb r1, [r7]
	ldrb r0, [r5]
	strb r0, [r7]
	strb r1, [r5]
	adds r7, r5, #0
	b .L080E26E4
.L080E267A:
	ldr r4, [r7, #4]
	cmp r6, #0
	beq .L080E2682
	str r4, [r6, #4]
.L080E2682:
	mov r1, r8
	ldr r0, [r1]
	cmp r0, r7
	bne .L080E268E
	str r6, [r1]
	b .L080E269C
.L080E268E:
	ldr r1, [r7, #4]
	ldr r0, [r1, #8]
	cmp r0, r7
	bne .L080E269A
	str r6, [r1, #8]
	b .L080E269C
.L080E269A:
	str r6, [r1, #0xc]
.L080E269C:
	ldr r0, [r2]
	cmp r0, r5
	bne .L080E26C0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne .L080E26AE
	ldr r0, [r5, #4]
	str r0, [r2]
	b .L080E26C0
.L080E26AE:
	adds r1, r6, #0
	ldr r0, [r6, #8]
	cmp r0, #0
	beq .L080E26BE
.L080E26B6:
	ldr r1, [r1, #8]
	ldr r0, [r1, #8]
	cmp r0, #0
	bne .L080E26B6
.L080E26BE:
	str r1, [r2]
.L080E26C0:
	ldr r0, [r3]
	cmp r0, r5
	bne .L080E26E4
	ldr r0, [r5, #8]
	cmp r0, #0
	bne .L080E26D2
	ldr r0, [r5, #4]
	str r0, [r3]
	b .L080E26E4
.L080E26D2:
	adds r1, r6, #0
	ldr r0, [r6, #0xc]
	cmp r0, #0
	beq .L080E26E2
.L080E26DA:
	ldr r1, [r1, #0xc]
	ldr r0, [r1, #0xc]
	cmp r0, #0
	bne .L080E26DA
.L080E26E2:
	str r1, [r3]
.L080E26E4:
	ldrb r0, [r7]
	cmp r0, #0
	bne .L080E26EC
	b .L080E27F0
.L080E26EC:
	b .L080E27D6
.L080E26EE:
	ldr r0, [r4, #8]
	cmp r6, r0
	bne .L080E2760
	ldr r2, [r4, #0xc]
	ldrb r1, [r2]
	cmp r1, #0
	bne .L080E270C
	movs r0, #1
	strb r0, [r2]
	strb r1, [r4]
	adds r0, r4, #0
	mov r1, r8
	bl func_080E2170
	ldr r2, [r4, #0xc]
.L080E270C:
	ldr r3, [r2, #8]
	cmp r3, #0
	beq .L080E271A
	ldrb r0, [r3]
	ldr r1, [r2, #0xc]
	cmp r0, #1
	bne .L080E2726
.L080E271A:
	ldr r1, [r2, #0xc]
	cmp r1, #0
	beq .L080E2792
	ldrb r0, [r1]
	cmp r0, #1
	beq .L080E2792
.L080E2726:
	cmp r1, #0
	beq .L080E2730
	ldrb r0, [r1]
	cmp r0, #1
	bne .L080E2746
.L080E2730:
	cmp r3, #0
	beq .L080E2738
	movs r0, #1
	strb r0, [r3]
.L080E2738:
	movs r0, #0
	strb r0, [r2]
	adds r0, r2, #0
	mov r1, r8
	bl func_080E21A8
	ldr r2, [r4, #0xc]
.L080E2746:
	ldrb r0, [r4]
	strb r0, [r2]
	movs r1, #1
	strb r1, [r4]
	ldr r0, [r2, #0xc]
	cmp r0, #0
	beq .L080E2756
	strb r1, [r0]
.L080E2756:
	adds r0, r4, #0
	mov r1, r8
	bl func_080E2170
	b .L080E27E8
.L080E2760:
	adds r2, r0, #0
	ldrb r1, [r2]
	cmp r1, #0
	bne .L080E2778
	movs r0, #1
	strb r0, [r2]
	strb r1, [r4]
	adds r0, r4, #0
	mov r1, r8
	bl func_080E21A8
	ldr r2, [r4, #8]
.L080E2778:
	ldr r3, [r2, #0xc]
	cmp r3, #0
	beq .L080E2786
	ldrb r0, [r3]
	ldr r1, [r2, #8]
	cmp r0, #1
	bne .L080E279C
.L080E2786:
	ldr r1, [r2, #8]
	cmp r1, #0
	beq .L080E2792
	ldrb r0, [r1]
	cmp r0, #1
	bne .L080E279C
.L080E2792:
	movs r0, #0
	strb r0, [r2]
	adds r6, r4, #0
	ldr r4, [r6, #4]
	b .L080E27D6
.L080E279C:
	cmp r1, #0
	beq .L080E27A6
	ldrb r0, [r1]
	cmp r0, #1
	bne .L080E27BC
.L080E27A6:
	cmp r3, #0
	beq .L080E27AE
	movs r0, #1
	strb r0, [r3]
.L080E27AE:
	movs r0, #0
	strb r0, [r2]
	adds r0, r2, #0
	mov r1, r8
	bl func_080E2170
	ldr r2, [r4, #8]
.L080E27BC:
	ldrb r0, [r4]
	strb r0, [r2]
	movs r1, #1
	strb r1, [r4]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq .L080E27CC
	strb r1, [r0]
.L080E27CC:
	adds r0, r4, #0
	mov r1, r8
	bl func_080E21A8
	b .L080E27E8
.L080E27D6:
	mov r1, r8
	ldr r0, [r1]
	cmp r6, r0
	beq .L080E27E8
	cmp r6, #0
	beq .L080E26EE
	ldrb r0, [r6]
	cmp r0, #1
	beq .L080E26EE
.L080E27E8:
	cmp r6, #0
	beq .L080E27F0
	movs r0, #1
	strb r0, [r6]
.L080E27F0:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_080E27FC
func_080E27FC: @ 0x080E27FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x14]
	adds r5, r3, #0
	ldr r0, [r6, #4]
	cmp r5, r0
	beq .L080E2826
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080E2866
	cmp r2, #0
	bne .L080E2826
	movs r2, #0
	ldr r1, [r4]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bhs .L080E2822
	movs r2, #1
.L080E2822:
	cmp r2, #0
	beq .L080E2866
.L080E2826:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E283A
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E283A:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E284A
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E284A:
	adds r4, r2, #0
	str r4, [r5, #8]
	ldr r1, [r6, #4]
	cmp r5, r1
	bne .L080E285C
	str r4, [r5, #4]
	ldr r0, [r6, #4]
	str r4, [r0, #0xc]
	b .L080E2898
.L080E285C:
	ldr r0, [r1, #8]
	cmp r5, r0
	bne .L080E2898
	str r4, [r1, #8]
	b .L080E2898
.L080E2866:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E287A
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E287A:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E288A
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E288A:
	adds r4, r2, #0
	str r4, [r5, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [r1, #0xc]
	cmp r5, r0
	bne .L080E2898
	str r4, [r1, #0xc]
.L080E2898:
	str r5, [r4, #4]
	movs r0, #0
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r6, #4]
	adds r1, #4
	adds r0, r4, #0
	bl func_080E21E0
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	str r4, [r7]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E28BC
func_080E28BC: @ 0x080E28BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	ldr r4, [r1, #4]
	ldr r5, [r4, #4]
	movs r0, #1
	cmp r5, #0
	beq .L080E28F2
	ldr r2, [r7]
.L080E28D6:
	adds r4, r5, #0
	movs r1, #0
	ldr r0, [r4, #0x10]
	cmp r2, r0
	bhs .L080E28E2
	movs r1, #1
.L080E28E2:
	adds r0, r1, #0
	cmp r0, #0
	beq .L080E28EC
	ldr r5, [r4, #8]
	b .L080E28EE
.L080E28EC:
	ldr r5, [r4, #0xc]
.L080E28EE:
	cmp r5, #0
	bne .L080E28D6
.L080E28F2:
	str r4, [sp, #8]
	cmp r0, #0
	beq .L080E292C
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	movs r1, #0
	cmp r4, r0
	bne .L080E2908
	movs r1, #1
.L080E2908:
	cmp r1, #0
	beq .L080E2924
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x10
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E27FC
	movs r1, #1
	ldr r0, [sp, #0x10]
	b .L080E2956
.L080E2924:
	adds r0, r4, #0
	bl func_080E2354
	str r0, [sp, #8]
.L080E292C:
	ldr r2, [sp, #8]
	movs r3, #0
	ldr r1, [r2, #0x10]
	ldr r0, [r7]
	cmp r1, r0
	bhs .L080E293A
	movs r3, #1
.L080E293A:
	adds r0, r3, #0
	cmp r0, #0
	beq .L080E295C
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E27FC
	movs r1, #1
	ldr r0, [sp, #0xc]
.L080E2956:
	str r0, [r6]
	strb r1, [r6, #4]
	b .L080E2960
.L080E295C:
	str r2, [r6]
	strb r0, [r6, #4]
.L080E2960:
	adds r0, r6, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E2970
func_080E2970: @ 0x080E2970
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, [r6, #4]
	ldr r2, [r2]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E2A00
	ldr r0, [r6, #8]
	cmp r0, #0
	bne .L080E29A0
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E28BC
	ldr r0, [sp, #8]
	b .L080E2B14
.L080E29A0:
	movs r0, #0
	ldr r1, [r2, #0x10]
	adds r3, r2, #0
	ldr r2, [r4]
	cmp r2, r1
	bhs .L080E29AE
	movs r0, #1
.L080E29AE:
	mov sb, r0
	cmp r0, #0
	bne .L080E2A74
	movs r0, #0
	cmp r1, r2
	bhs .L080E29BC
	movs r0, #1
.L080E29BC:
	cmp r0, #0
	bne .L080E29C4
	str r3, [r7]
	b .L080E2B16
.L080E29C4:
	str r3, [sp, #8]
	adds r0, r3, #0
	bl func_080E2B28
	adds r2, r0, #0
	str r2, [sp, #8]
	ldr r0, [r6, #4]
	cmp r2, r0
	bne .L080E29DC
	mov r0, r8
	ldr r3, [r0]
	b .L080E2ADA
.L080E29DC:
	movs r3, #0
	ldr r1, [r4]
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r1, r0
	bhs .L080E29EA
	movs r3, #1
.L080E29EA:
	cmp r3, #0
	bne .L080E29F0
	b .L080E2B08
.L080E29F0:
	mov r1, r8
	ldr r3, [r1]
	ldr r0, [r3, #0xc]
	cmp r0, #0
	beq .L080E2ADA
	str r4, [sp]
	mov r0, sb
	b .L080E2AEE
.L080E2A00:
	cmp r2, r1
	bne .L080E2A2A
	ldr r3, [r2, #0xc]
	movs r5, #0
	ldr r1, [r3, #0x10]
	ldr r0, [r4]
	cmp r1, r0
	bhs .L080E2A12
	movs r5, #1
.L080E2A12:
	cmp r5, #0
	beq .L080E2A1C
	str r4, [sp]
	str r2, [sp, #4]
	b .L080E2ADE
.L080E2A1C:
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E28BC
	ldr r0, [sp, #8]
	b .L080E2B14
.L080E2A2A:
	str r2, [sp, #8]
	adds r0, r2, #0
	bl func_080E2354
	adds r2, r0, #0
	str r2, [sp, #8]
	mov r1, r8
	ldr r3, [r1]
	movs r5, #0
	ldr r1, [r4]
	ldr r0, [r3, #0x10]
	cmp r1, r0
	bhs .L080E2A46
	movs r5, #1
.L080E2A46:
	mov sb, r5
	cmp r5, #0
	beq .L080E2A86
	movs r0, #0
	mov ip, r0
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r0, r1
	bhs .L080E2A5C
	movs r1, #1
	mov ip, r1
.L080E2A5C:
	mov r0, ip
	cmp r0, #0
	beq .L080E2A86
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne .L080E2A74
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	b .L080E2AF6
.L080E2A74:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r3, #0
	bl func_080E27FC
	b .L080E2B16
.L080E2A86:
	mov r1, r8
	ldr r0, [r1]
	str r0, [sp, #0xc]
	bl func_080E2B28
	mov ip, r0
	str r0, [sp, #0xc]
	movs r0, #1
	mov r1, sb
	eors r1, r0
	mov r0, sb
	cmp r0, #0
	bne .L080E2AFE
	mov r1, r8
	ldr r0, [r1]
	movs r5, #0
	ldr r1, [r0, #0x10]
	adds r3, r0, #0
	ldr r2, [r4]
	cmp r1, r2
	bhs .L080E2AB2
	movs r5, #1
.L080E2AB2:
	adds r1, r5, #0
	cmp r1, #0
	beq .L080E2AFE
	ldr r0, [r6, #4]
	mov r5, ip
	cmp r5, r0
	beq .L080E2AD4
	movs r0, #0
	mov ip, r0
	ldr r0, [r5, #0x10]
	cmp r2, r0
	bhs .L080E2ACE
	movs r0, #1
	mov ip, r0
.L080E2ACE:
	mov r0, ip
	cmp r0, #0
	beq .L080E2AFE
.L080E2AD4:
	ldr r0, [r3, #0xc]
	cmp r0, #0
	bne .L080E2AEA
.L080E2ADA:
	str r4, [sp]
	str r3, [sp, #4]
.L080E2ADE:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl func_080E27FC
	b .L080E2B16
.L080E2AEA:
	str r4, [sp]
	movs r0, #0
.L080E2AEE:
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
.L080E2AF6:
	adds r3, r5, #0
	bl func_080E27FC
	b .L080E2B16
.L080E2AFE:
	cmp sb, r1
	bne .L080E2B08
	mov r1, r8
	ldr r0, [r1]
	b .L080E2B14
.L080E2B08:
	add r0, sp, #0x10
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E28BC
	ldr r0, [sp, #0x10]
.L080E2B14:
	str r0, [r7]
.L080E2B16:
	adds r0, r7, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E2B28
func_080E2B28: @ 0x080E2B28
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq .L080E2B46
	adds r1, r0, #0
	ldr r0, [r1, #8]
	cmp r0, #0
	beq .L080E2B56
.L080E2B3A:
	ldr r1, [r1, #8]
	ldr r0, [r1, #8]
	cmp r0, #0
	bne .L080E2B3A
	b .L080E2B56
.L080E2B44:
	adds r1, r2, #0
.L080E2B46:
	ldr r2, [r1, #4]
	ldr r0, [r2, #0xc]
	cmp r1, r0
	beq .L080E2B44
	ldr r0, [r1, #0xc]
	cmp r0, r2
	beq .L080E2B56
	adds r1, r2, #0
.L080E2B56:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start func_080E2B5C
func_080E2B5C: @ 0x080E2B5C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	beq .L080E2B80
.L080E2B66:
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	bl func_080E2B5C
	ldr r5, [r4, #8]
	cmp r4, #0
	beq .L080E2B7A
	adds r0, r4, #0
	bl free
.L080E2B7A:
	adds r4, r5, #0
	cmp r4, #0
	bne .L080E2B66
.L080E2B80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2B88
func_080E2B88: @ 0x080E2B88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	beq .L080E2BAC
.L080E2B92:
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	bl func_080E2B88
	ldr r5, [r4, #8]
	cmp r4, #0
	beq .L080E2BA6
	adds r0, r4, #0
	bl free
.L080E2BA6:
	adds r4, r5, #0
	cmp r4, #0
	bne .L080E2B92
.L080E2BAC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2BB4
func_080E2BB4: @ 0x080E2BB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov sl, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r0, [r2, #8]
	str r0, [sp, #0x18]
	ldr r1, [r2, #0x10]
	str r1, [sp, #0x1c]
	ldr r3, [r2]
	movs r0, #0
	cmp r3, #0
	beq .L080E2BD8
	ldrh r0, [r2, #4]
.L080E2BD8:
	lsls r0, r0, #3
	adds r0, r3, r0
	str r0, [sp, #0x20]
	cmp r3, r0
	bne .L080E2BE4
	b .L080E2DA2
.L080E2BE4:
	ldm r3!, {r0, r1}
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	lsls r0, r2, #7
	asrs r6, r0, #0x17
	ldr r0, [sp, #0x14]
	adds r6, r6, r0
	str r3, [sp, #0x24]
	cmp r6, #0xef
	ble .L080E2BFC
	b .L080E2D98
.L080E2BFC:
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r0
	ldr r1, [sp, #0x48]
	add r8, r1
	mov r0, r8
	cmp r0, #0x9f
	ble .L080E2C12
	b .L080E2D98
.L080E2C12:
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x1e
	lsls r1, r1, #2
	lsrs r0, r2, #0x1e
	adds r1, r1, r0
	ldr r2, .L080E2C84 @ =gCodeLinkoncePackedCellSizeLookup
	lsrs r0, r1, #1
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	asrs r2, r1
	movs r3, #3
	adds r1, r2, #0
	ands r1, r3
	movs r4, #8
	adds r0, r4, #0
	lsls r0, r1
	adds r0, r6, r0
	cmp r0, #0
	bgt .L080E2C40
	b .L080E2D98
.L080E2C40:
	lsrs r1, r2, #2
	ands r1, r3
	adds r0, r4, #0
	lsls r0, r1
	add r0, r8
	cmp r0, #0
	bgt .L080E2C50
	b .L080E2D98
.L080E2C50:
	ldr r0, [sp, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x11
	ldr r1, [sp, #0x18]
	adds r0, r1, r0
	str r0, [sp, #8]
	mov r1, sl
	adds r1, #4
	add r7, sp, #8
	ldr r4, [r1, #4]
	ldr r2, [r4, #4]
	mov ip, r1
	cmp r2, #0
	beq .L080E2C8E
	adds r5, r0, #0
.L080E2C6E:
	movs r3, #0
	ldr r0, [r2, #0x10]
	cmp r0, r5
	bhs .L080E2C78
	movs r3, #1
.L080E2C78:
	cmp r3, #0
	bne .L080E2C88
	adds r4, r2, #0
	ldr r2, [r4, #8]
	b .L080E2C8A
	.align 2, 0
.L080E2C84: .4byte gCodeLinkoncePackedCellSizeLookup
.L080E2C88:
	ldr r2, [r2, #0xc]
.L080E2C8A:
	cmp r2, #0
	bne .L080E2C6E
.L080E2C8E:
	ldr r3, [r1, #4]
	cmp r4, r3
	beq .L080E2CA4
	movs r2, #0
	ldr r1, [r7]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	bhs .L080E2CA0
	movs r2, #1
.L080E2CA0:
	cmp r2, #0
	beq .L080E2CA6
.L080E2CA4:
	adds r4, r3, #0
.L080E2CA6:
	mov r0, ip
	ldr r1, [r0, #4]
	eors r1, r4
	rsbs r0, r1, #0
	orrs r0, r1
	cmp r0, #0
	bge .L080E2CBE
	ldr r1, [r4, #0x14]
	mov r0, sl
	bl GetObjTileIndex
	b .L080E2CC2
.L080E2CBE:
	movs r0, #1
	rsbs r0, r0, #0
.L080E2CC2:
	mov sb, r0
	cmp r0, #0
	blt .L080E2D98
	ldr r0, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x1c
	lsls r0, r0, #5
	ldr r1, [sp, #0x1c]
	adds r0, r1, r0
	str r0, [sp, #0xc]
	mov r1, sl
	adds r1, #0x18
	add r7, sp, #0xc
	ldr r4, [r1, #4]
	ldr r2, [r4, #4]
	mov ip, r1
	cmp r2, #0
	beq .L080E2D02
	adds r5, r0, #0
.L080E2CE8:
	movs r3, #0
	ldr r0, [r2, #0x10]
	cmp r0, r5
	bhs .L080E2CF2
	movs r3, #1
.L080E2CF2:
	cmp r3, #0
	bne .L080E2CFC
	adds r4, r2, #0
	ldr r2, [r4, #8]
	b .L080E2CFE
.L080E2CFC:
	ldr r2, [r2, #0xc]
.L080E2CFE:
	cmp r2, #0
	bne .L080E2CE8
.L080E2D02:
	ldr r3, [r1, #4]
	cmp r4, r3
	beq .L080E2D18
	movs r2, #0
	ldr r1, [r7]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	bhs .L080E2D14
	movs r2, #1
.L080E2D14:
	cmp r2, #0
	beq .L080E2D1A
.L080E2D18:
	adds r4, r3, #0
.L080E2D1A:
	mov r0, ip
	ldr r1, [r0, #4]
	eors r1, r4
	rsbs r0, r1, #0
	orrs r0, r1
	cmp r0, #0
	bge .L080E2D36
	ldr r1, [r4, #0x14]
	mov r0, sl
	adds r0, #0x14
	bl GetObjPaletteBank
	adds r4, r0, #0
	b .L080E2D3A
.L080E2D36:
	movs r4, #1
	rsbs r4, r4, #0
.L080E2D3A:
	cmp r4, #0
	blt .L080E2D98
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080E2DB4 @ =0xFFFFFF00
	ldr r3, [sp]
	ands r3, r1
	orrs r3, r0
	ldr r0, .L080E2DB8 @ =0x000001FF
	ands r6, r0
	lsls r1, r6, #0x10
	ldr r0, .L080E2DBC @ =0xFE00FFFF
	ands r3, r0
	orrs r3, r1
	str r3, [sp]
	mov r1, sb
	lsls r0, r1, #0x16
	lsrs r0, r0, #0x16
	ldr r1, .L080E2DC0 @ =0xFFFFFC00
	mov r5, sp
	ldr r2, [sp, #4]
	ands r2, r1
	orrs r2, r0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L080E2DC4 @ =0xFFFF0FFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #4]
	ldr r0, [sp, #0x10]
	ldrb r2, [r0]
	cmp r2, #0x7f
	bhi .L080E2D98
	lsls r0, r2, #3
	adds r0, #4
	ldr r1, [sp, #0x10]
	adds r0, r1, r0
	str r3, [r0]
	ldrh r1, [r5, #4]
	strh r1, [r0, #4]
	adds r0, r2, #1
	ldr r1, [sp, #0x10]
	strb r0, [r1]
.L080E2D98:
	ldr r3, [sp, #0x24]
	ldr r0, [sp, #0x20]
	cmp r3, r0
	beq .L080E2DA2
	b .L080E2BE4
.L080E2DA2:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E2DB4: .4byte 0xFFFFFF00
.L080E2DB8: .4byte 0x000001FF
.L080E2DBC: .4byte 0xFE00FFFF
.L080E2DC0: .4byte 0xFFFFFC00
.L080E2DC4: .4byte 0xFFFF0FFF

	thumb_func_start func_080E2DC8
func_080E2DC8: @ 0x080E2DC8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	bl InitializeObjTilePoolOwner
	adds r4, r6, #4
	movs r5, #0
	str r5, [r4, #4]
	movs r0, #0x18
	bl malloc
	cmp r0, #0
	bne .L080E2DE8
	movs r0, #0x18
	bl RetryMemoryAllocation
.L080E2DE8:
	str r0, [r4, #4]
	str r5, [r4, #8]
	str r5, [r4, #0xc]
	strb r5, [r0]
	str r5, [r0, #4]
	ldr r0, [r4, #4]
	str r0, [r0, #8]
	ldr r0, [r4, #4]
	str r0, [r0, #0xc]
	adds r0, r6, #0
	adds r0, #0x14
	bl ConstructObjPalettePoolOwner
	adds r4, r6, #0
	adds r4, #0x18
	str r5, [r4, #4]
	movs r0, #0x18
	bl malloc
	cmp r0, #0
	bne .L080E2E18
	movs r0, #0x18
	bl RetryMemoryAllocation
.L080E2E18:
	str r0, [r4, #4]
	str r5, [r4, #8]
	str r5, [r4, #0xc]
	strb r5, [r0]
	str r5, [r0, #4]
	ldr r0, [r4, #4]
	str r0, [r0, #8]
	ldr r0, [r4, #4]
	str r0, [r0, #0xc]
	adds r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080E2E34:
	.global func_080E2E34
	.thumb_func
func_080E2E34:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x0A, 0x48, 0xE0, 0x60, 0xA1, 0x68
	.byte 0x00, 0x29, 0x07, 0xD0, 0x08, 0x4A, 0x88, 0x18, 0x00, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
	.byte 0xF0, 0xF7, 0x60, 0xFD, 0x20, 0x1C, 0x29, 0x1C
	bl _._15HardwareContext
	.byte 0x30, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
	.4byte __vt_23IndexedResourceProvider
	.byte 0xB4, 0x05, 0x00, 0x00
    .section .text.after_staff_credits_core_destructor, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E2E78
func_080E2E78: @ 0x080E2E78
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	beq .L080E2E9C
.L080E2E82:
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	bl func_080E2E78
	ldr r5, [r4, #8]
	cmp r4, #0
	beq .L080E2E96
	adds r0, r4, #0
	bl free
.L080E2E96:
	adds r4, r5, #0
	cmp r4, #0
	bne .L080E2E82
.L080E2E9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E2EA4
func_080E2EA4: @ 0x080E2EA4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x14]
	adds r5, r3, #0
	ldr r0, [r6, #4]
	cmp r5, r0
	beq .L080E2EDE
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080E2F1E
	cmp r2, #0
	bne .L080E2EDE
	adds r2, r5, #0
	adds r2, #0x10
	movs r3, #0
	ldrb r1, [r4]
	ldrb r0, [r5, #0x10]
	cmp r1, r0
	blo .L080E2ED8
	cmp r0, r1
	blo .L080E2EDA
	ldrb r0, [r4, #1]
	ldrb r2, [r2, #1]
	cmp r0, r2
	bhs .L080E2EDA
.L080E2ED8:
	movs r3, #1
.L080E2EDA:
	cmp r3, #0
	beq .L080E2F1E
.L080E2EDE:
	movs r0, #0x18
	bl malloc
	adds r1, r0, #0
	cmp r1, #0
	bne .L080E2EF2
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r1, r0, #0
.L080E2EF2:
	adds r2, r1, #0
	adds r2, #0x10
	cmp r2, #0
	beq .L080E2F02
	ldr r0, [r4]
	str r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	strb r0, [r2, #4]
.L080E2F02:
	adds r4, r1, #0
	str r4, [r5, #8]
	ldr r1, [r6, #4]
	cmp r5, r1
	bne .L080E2F14
	str r4, [r5, #4]
	ldr r0, [r6, #4]
	str r4, [r0, #0xc]
	b .L080E2F50
.L080E2F14:
	ldr r0, [r1, #8]
	cmp r5, r0
	bne .L080E2F50
	str r4, [r1, #8]
	b .L080E2F50
.L080E2F1E:
	movs r0, #0x18
	bl malloc
	adds r1, r0, #0
	cmp r1, #0
	bne .L080E2F32
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r1, r0, #0
.L080E2F32:
	adds r2, r1, #0
	adds r2, #0x10
	cmp r2, #0
	beq .L080E2F42
	ldr r0, [r4]
	str r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	strb r0, [r2, #4]
.L080E2F42:
	adds r4, r1, #0
	str r4, [r5, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [r1, #0xc]
	cmp r5, r0
	bne .L080E2F50
	str r4, [r1, #0xc]
.L080E2F50:
	str r5, [r4, #4]
	movs r0, #0
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r6, #4]
	adds r1, #4
	adds r0, r4, #0
	bl func_080E21E0
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	str r4, [r7]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E2F74
func_080E2F74: @ 0x080E2F74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	ldr r5, [r1, #4]
	ldr r4, [r5, #4]
	movs r0, #1
	cmp r4, #0
	beq .L080E2FBC
	ldrb r2, [r6]
.L080E2F90:
	adds r5, r4, #0
	adds r1, r5, #0
	adds r1, #0x10
	movs r3, #0
	ldrb r0, [r5, #0x10]
	cmp r2, r0
	blo .L080E2FAA
	cmp r0, r2
	blo .L080E2FAC
	ldrb r0, [r6, #1]
	ldrb r1, [r1, #1]
	cmp r0, r1
	bhs .L080E2FAC
.L080E2FAA:
	movs r3, #1
.L080E2FAC:
	adds r0, r3, #0
	cmp r0, #0
	beq .L080E2FB6
	ldr r4, [r4, #8]
	b .L080E2FB8
.L080E2FB6:
	ldr r4, [r4, #0xc]
.L080E2FB8:
	cmp r4, #0
	bne .L080E2F90
.L080E2FBC:
	str r5, [sp, #8]
	cmp r0, #0
	beq .L080E2FF6
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	movs r1, #0
	cmp r5, r0
	bne .L080E2FD2
	movs r1, #1
.L080E2FD2:
	cmp r1, #0
	beq .L080E2FEE
	str r6, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x10
	mov r1, r8
	adds r2, r4, #0
	adds r3, r5, #0
	bl func_080E2EA4
	movs r1, #1
	ldr r0, [sp, #0x10]
	b .L080E3036
.L080E2FEE:
	adds r0, r5, #0
	bl func_080E2354
	str r0, [sp, #8]
.L080E2FF6:
	ldr r0, [sp, #8]
	adds r3, r0, #0
	adds r3, #0x10
	movs r1, #0
	mov sb, r1
	ldrb r2, [r0, #0x10]
	ldrb r1, [r6]
	mov ip, r0
	cmp r2, r1
	blo .L080E3016
	cmp r1, r2
	blo .L080E301A
	ldrb r0, [r3, #1]
	ldrb r1, [r6, #1]
	cmp r0, r1
	bhs .L080E301A
.L080E3016:
	movs r0, #1
	mov sb, r0
.L080E301A:
	mov r0, sb
	cmp r0, #0
	beq .L080E303C
	str r6, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r4, #0
	adds r3, r5, #0
	bl func_080E2EA4
	movs r1, #1
	ldr r0, [sp, #0xc]
.L080E3036:
	str r0, [r7]
	strb r1, [r7, #4]
	b .L080E3042
.L080E303C:
	mov r1, ip
	str r1, [r7]
	strb r0, [r7, #4]
.L080E3042:
	adds r0, r7, #0
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E3054
func_080E3054: @ 0x080E3054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r6, r1, #0
	mov sl, r2
	adds r4, r3, #0
	ldr r1, [r6, #4]
	ldr r2, [r2]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E314C
	ldr r0, [r6, #8]
	cmp r0, #0
	bne .L080E3086
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2F74
	ldr r0, [sp, #8]
	b .L080E32D2
.L080E3086:
	movs r0, #0x10
	adds r0, r0, r2
	mov ip, r0
	movs r1, #0
	mov sb, r1
	ldrb r0, [r4]
	adds r3, r0, #0
	ldrb r1, [r2, #0x10]
	adds r5, r2, #0
	mov r8, r0
	cmp r3, r1
	blo .L080E30AC
	cmp r1, r3
	blo .L080E30B0
	ldrb r0, [r4, #1]
	mov r2, ip
	ldrb r2, [r2, #1]
	cmp r0, r2
	bhs .L080E30B0
.L080E30AC:
	movs r0, #1
	mov sb, r0
.L080E30B0:
	mov r1, sb
	cmp r1, #0
	beq .L080E30C4
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	b .L080E32A2
.L080E30C4:
	adds r3, r5, #0
	adds r3, #0x10
	movs r1, #0
	ldrb r2, [r5, #0x10]
	mov r0, r8
	cmp r2, r0
	blo .L080E30DE
	cmp r0, r2
	blo .L080E30E0
	ldrb r0, [r3, #1]
	ldrb r2, [r4, #1]
	cmp r0, r2
	bhs .L080E30E0
.L080E30DE:
	movs r1, #1
.L080E30E0:
	cmp r1, #0
	bne .L080E30E8
	str r5, [r7]
	b .L080E32D4
.L080E30E8:
	str r5, [sp, #8]
	adds r0, r5, #0
	bl func_080E2B28
	adds r2, r0, #0
	str r2, [sp, #8]
	ldr r0, [r6, #4]
	cmp r2, r0
	bne .L080E3104
	mov r0, sl
	ldr r3, [r0]
	str r4, [sp]
	str r3, [sp, #4]
	b .L080E317E
.L080E3104:
	adds r3, r2, #0
	adds r3, #0x10
	movs r1, #0
	mov r8, r1
	ldrb r1, [r4]
	ldrb r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r1, r0
	blo .L080E3122
	cmp r0, r1
	blo .L080E3126
	ldrb r0, [r4, #1]
	ldrb r3, [r3, #1]
	cmp r0, r3
	bhs .L080E3126
.L080E3122:
	movs r2, #1
	mov r8, r2
.L080E3126:
	mov r0, r8
	cmp r0, #0
	bne .L080E312E
	b .L080E32C6
.L080E312E:
	mov r1, sl
	ldr r3, [r1]
	ldr r0, [r3, #0xc]
	cmp r0, #0
	bne .L080E313E
	str r4, [sp]
	str r3, [sp, #4]
	b .L080E317E
.L080E313E:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	b .L080E32A2
.L080E314C:
	cmp r2, r1
	bne .L080E3198
	ldr r0, [r2, #0xc]
	adds r2, r0, #0
	adds r2, #0x10
	movs r3, #0
	ldrb r0, [r0, #0x10]
	ldrb r1, [r4]
	cmp r0, r1
	blo .L080E316C
	cmp r1, r0
	blo .L080E316E
	ldrb r0, [r2, #1]
	ldrb r2, [r4, #1]
	cmp r0, r2
	bhs .L080E316E
.L080E316C:
	movs r3, #1
.L080E316E:
	cmp r3, #0
	beq .L080E318A
	ldr r0, [r6, #4]
	ldr r3, [r0, #0xc]
	str r4, [sp]
	mov r1, sl
	ldr r0, [r1]
	str r0, [sp, #4]
.L080E317E:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl func_080E2EA4
	b .L080E32D4
.L080E318A:
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2F74
	ldr r0, [sp, #8]
	b .L080E32D2
.L080E3198:
	str r2, [sp, #8]
	adds r0, r2, #0
	bl func_080E2354
	str r0, [sp, #8]
	mov r2, sl
	ldr r0, [r2]
	adds r2, r0, #0
	adds r2, #0x10
	movs r3, #0
	ldrb r1, [r4]
	ldrb r0, [r0, #0x10]
	cmp r1, r0
	blo .L080E31C0
	cmp r0, r1
	blo .L080E31C2
	ldrb r0, [r4, #1]
	ldrb r2, [r2, #1]
	cmp r0, r2
	bhs .L080E31C2
.L080E31C0:
	movs r3, #1
.L080E31C2:
	mov sb, r3
	cmp r3, #0
	beq .L080E31FE
	ldr r0, [sp, #8]
	adds r3, r0, #0
	adds r3, #0x10
	movs r1, #0
	mov r8, r1
	ldrb r2, [r0, #0x10]
	ldrb r1, [r4]
	adds r5, r0, #0
	cmp r2, r1
	blo .L080E31E8
	cmp r1, r2
	blo .L080E31EC
	ldrb r0, [r3, #1]
	ldrb r2, [r4, #1]
	cmp r0, r2
	bhs .L080E31EC
.L080E31E8:
	movs r0, #1
	mov r8, r0
.L080E31EC:
	mov r1, r8
	cmp r1, #0
	beq .L080E31FE
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq .L080E3298
	mov r2, sl
	ldr r3, [r2]
	b .L080E32AA
.L080E31FE:
	mov r1, sl
	ldr r0, [r1]
	str r0, [sp, #0xc]
	bl func_080E2B28
	str r0, [sp, #0xc]
	movs r0, #1
	mov r1, sb
	eors r1, r0
	mov r2, sb
	cmp r2, #0
	bne .L080E32BC
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x10
	adds r2, r2, r0
	mov ip, r2
	movs r2, #0
	mov r1, sp
	strb r2, [r1, #0x18]
	ldrb r1, [r4]
	ldrb r3, [r0, #0x10]
	adds r2, r1, #0
	adds r5, r0, #0
	mov r8, r1
	cmp r3, r2
	blo .L080E3242
	cmp r2, r3
	blo .L080E3248
	mov r1, ip
	ldrb r0, [r1, #1]
	ldrb r2, [r4, #1]
	cmp r0, r2
	bhs .L080E3248
.L080E3242:
	movs r1, #1
	mov r0, sp
	strb r1, [r0, #0x18]
.L080E3248:
	mov r2, sp
	ldrb r2, [r2, #0x18]
	adds r1, r2, #0
	mov r0, sb
	cmp r0, #0
	bne .L080E32BC
	cmp r1, #0
	beq .L080E32BC
	ldr r0, [r6, #4]
	ldr r3, [sp, #0xc]
	cmp r3, r0
	beq .L080E3292
	movs r2, #0x10
	adds r2, r2, r3
	mov ip, r2
	movs r2, #0
	mov r0, sp
	strb r2, [r0, #0x1c]
	mov r0, r8
	ldrb r2, [r3, #0x10]
	cmp r0, r2
	blo .L080E3284
	cmp r2, r0
	blo .L080E328A
	ldrb r0, [r4, #1]
	mov r8, r0
	mov r2, ip
	ldrb r2, [r2, #1]
	cmp r8, r2
	bhs .L080E328A
.L080E3284:
	movs r2, #1
	mov r0, sp
	strb r2, [r0, #0x1c]
.L080E328A:
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	cmp r0, #0
	beq .L080E32BC
.L080E3292:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne .L080E32AA
.L080E3298:
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
.L080E32A2:
	adds r3, r5, #0
	bl func_080E2EA4
	b .L080E32D4
.L080E32AA:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r3, #0
	bl func_080E2EA4
	b .L080E32D4
.L080E32BC:
	cmp sb, r1
	bne .L080E32C6
	mov r1, sl
	ldr r0, [r1]
	b .L080E32D2
.L080E32C6:
	add r0, sp, #0x10
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E2F74
	ldr r0, [sp, #0x10]
.L080E32D2:
	str r0, [r7]
.L080E32D4:
	adds r0, r7, #0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080E32E8:
	.global func_080E32E8
	.thumb_func
func_080E32E8:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x05, 0x1C
	.byte 0x88, 0x46, 0xEE, 0x20, 0x40, 0x00, 0x2C, 0x18, 0xA0, 0x68, 0x00, 0x28, 0x0C, 0xD0, 0x60, 0x68
	.byte 0x41, 0x68, 0x20, 0x1C
	bl func_080E2E78
	.byte 0x60, 0x68, 0x80, 0x60, 0x60, 0x68, 0x00, 0x21, 0x41, 0x60, 0x60, 0x68, 0xC0, 0x60, 0xA1, 0x60
	.byte 0x60, 0x68, 0x00, 0x28, 0x01, 0xD0
	bl free
	.byte 0xE6, 0x21, 0x49, 0x00, 0x68, 0x18, 0x42, 0x68, 0x01, 0x68, 0x2C, 0x1C, 0x20, 0x34, 0x2E, 0x1C
	.byte 0x1C, 0x36, 0x2F, 0x1C, 0x18, 0x37, 0x91, 0x42, 0x02, 0xD0, 0x1C, 0x31, 0x91, 0x42, 0xFC, 0xD1
	.byte 0x00, 0x68, 0x00, 0x28, 0x01, 0xD0
	bl free
	.byte 0xCE, 0x20, 0x40, 0x00
	.byte 0x29, 0x18, 0x10, 0x48, 0x08, 0x60, 0xA8, 0x62, 0x20, 0x1C, 0x02, 0x21
	bl func_080756D0
	.byte 0x30, 0x1C, 0x02, 0x21
	bl _._24MapClockStatusHudContent
	.byte 0x38, 0x1C, 0x02, 0x21
	bl _._12UiStateOwner
	.byte 0xE9, 0x68, 0x00, 0x29, 0x05, 0xD0, 0x08, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xF0, 0xF7
	.byte 0xC9, 0xFA, 0x28, 0x1C, 0x41, 0x46
	bl _._15HardwareContext
	.byte 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47
	.4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E3398
func_080E3398: @ 0x080E3398
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r2, #0
	subs r1, r1, r6
	asrs r3, r1, #2
.L080E33A2:
	cmp r3, #0
	ble .L080E33C8
	asrs r2, r3, #1
	lsls r0, r2, #2
	adds r4, r6, r0
	movs r5, #0
	ldr r1, [r4]
	ldr r0, [r7]
	cmp r1, r0
	bhs .L080E33B8
	movs r5, #1
.L080E33B8:
	cmp r5, #0
	beq .L080E33C4
	adds r6, r4, #4
	subs r0, r3, r2
	subs r3, r0, #1
	b .L080E33A2
.L080E33C4:
	adds r3, r2, #0
	b .L080E33A2
.L080E33C8:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080E33D0:
	.global func_080E33D0
	.thumb_func
func_080E33D0:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E33E6
	bl free
.L080E33E6:
	ldr r2, .L080E3480
	adds r4, r5, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0x83
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, .L080E3484
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0x82
	lsls r2, r2, #4
	adds r4, r5, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r0, .L080E3488
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0x81
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r2, .L080E348C
	adds r0, r5, r2
	ldr r1, .L080E3490
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _._15HardwareContext
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3480: .4byte 0x00000838
.L080E3484: .4byte 0x00000828
.L080E3488: .4byte 0x00000818
.L080E348C: .4byte 0x00000744
.L080E3490: .4byte __vt_23IndexedResourceProvider

    .section .text.after_blacksmith_shop_result_transition, "ax", %progbits
    .align 2, 0

    .section .text.after_menu_selection_core_destructor, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E35DC
func_080E35DC: @ 0x080E35DC
	push {lr}
	subs r0, #8
	bl func_08093308
	pop {r0}
	bx r0

	thumb_func_start func_080E35E8
func_080E35E8: @ 0x080E35E8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, .L080E360C @ =gText_LinkCommunication_Waiting
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_08050DC8
	adds r0, r4, #0
	movs r1, #0x39
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E360C: .4byte gText_LinkCommunication_Waiting

	thumb_func_start func_080E3610
func_080E3610: @ 0x080E3610
	push {lr}
	subs r0, #8
	bl GetHardwarePressedKeys
	movs r1, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	pop {r1}
	bx r1

	thumb_func_start func_080E3628
func_080E3628: @ 0x080E3628
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, .L080E364C @ =gText_LinkCommunication_SendingGameData
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_08050DC8
	adds r0, r4, #0
	movs r1, #0x38
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E364C: .4byte gText_LinkCommunication_SendingGameData

	thumb_func_start func_080E3650
func_080E3650: @ 0x080E3650
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, .L080E3674 @ =gText_LinkCommunication_TestingConnection
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_08050DC8
	adds r0, r4, #0
	movs r1, #0x38
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3674: .4byte gText_LinkCommunication_TestingConnection

	thumb_func_start func_080E3678
func_080E3678: @ 0x080E3678
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xf6
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	str r1, [r0]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r2, r0
	ldr r1, .L080E36B0 @ =gText_LinkCommunication_CannotResendPreviousData
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_08050DC8
	adds r0, r4, #0
	movs r1, #0x3a
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E36B0: .4byte gText_LinkCommunication_CannotResendPreviousData

	thumb_func_start func_080E36B4
func_080E36B4: @ 0x080E36B4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r6, #0
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r4, r0, r1
	ldr r1, [r4]
	cmp r1, #0
	beq .L080E36CC
	cmp r1, #1
	beq .L080E3700
	b .L080E3726
.L080E36CC:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r0, r5, #0
	bl GetState__C12UiStateOwner
	cmp r0, #3
	bne .L080E3726
	movs r0, #1
	str r0, [r4]
	ldr r1, .L080E36F4 @ =gText_LinkCommunication_ProceedQuestion
	ldr r2, .L080E36F8 @ =gText_LinkCommunication_Yes
	ldr r3, .L080E36FC @ =gText_LinkCommunication_No
	str r6, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	bl func_08050E30
	b .L080E3726
	.align 2, 0
.L080E36F4: .4byte gText_LinkCommunication_ProceedQuestion
.L080E36F8: .4byte gText_LinkCommunication_Yes
.L080E36FC: .4byte gText_LinkCommunication_No
.L080E3700:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r4, r0, r1
	adds r0, r4, #0
	bl GetState__C12UiStateOwner
	cmp r0, #3
	bne .L080E3726
	adds r0, r4, #0
	bl GetChoiceResult__C12UiStateOwner
	cmp r0, #1
	beq .L080E3720
	cmp r0, #2
	beq .L080E3724
	b .L080E3726
.L080E3720:
	movs r6, #2
	b .L080E3726
.L080E3724:
	movs r6, #3
.L080E3726:
	adds r0, r6, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_080E3730
func_080E3730: @ 0x080E3730
	bx lr
	.align 2, 0

	thumb_func_start func_080E3734
func_080E3734: @ 0x080E3734
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, .L080E3758 @ =gText_LinkCommunication_WaitingForOtherPlayer
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_08050DC8
	adds r0, r4, #0
	movs r1, #0x38
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3758: .4byte gText_LinkCommunication_WaitingForOtherPlayer

	thumb_func_start func_080E375C
func_080E375C: @ 0x080E375C
	push {lr}
	subs r0, #8
	bl GetHardwarePressedKeys
	movs r1, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	pop {r1}
	bx r1

	thumb_func_start func_080E3774
func_080E3774: @ 0x080E3774
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, .L080E3794 @ =gText_LinkCommunication_NowSendingData
	adds r0, r4, #0
	bl func_08050D8C
	adds r0, r4, #0
	movs r1, #0x38
	bl ShowPortrait__C12UiStateOwnerUi
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3794: .4byte gText_LinkCommunication_NowSendingData
.L080E3798:
	.global func_080E3798
	.thumb_func
func_080E3798:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start func_080E379C
func_080E379C: @ 0x080E379C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xf6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, .L080E37D8 @ =gText_LinkCommunication_DataExchangeFailed
	adds r0, r4, #0
	bl func_08050D8C
	adds r0, r4, #0
	movs r1, #0x3a
	bl ShowPortrait__C12UiStateOwnerUi
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #4
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E37D8: .4byte gText_LinkCommunication_DataExchangeFailed

	thumb_func_start func_080E37DC
func_080E37DC: @ 0x080E37DC
	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r4, #0
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r2, r1, r0
	ldr r0, [r2]
	cmp r0, #0
	beq .L080E37F6
	cmp r0, #1
	beq .L080E3828
	b .L080E384E
.L080E37F6:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #3
	bne .L080E384E
	movs r0, #1
	str r0, [r2]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, .L080E3820 @ =gText_LinkCommunication_Yes
	ldr r2, .L080E3824 @ =gText_LinkCommunication_No
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #0
	bl func_08050E0C
	b .L080E384E
	.align 2, 0
.L080E3820: .4byte gText_LinkCommunication_Yes
.L080E3824: .4byte gText_LinkCommunication_No
.L080E3828:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #3
	bne .L080E384E
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r1, r2
	bl GetChoiceResult__C12UiStateOwner
	cmp r0, #1
	beq .L080E3848
	cmp r0, #2
	beq .L080E384C
	b .L080E384E
.L080E3848:
	movs r4, #2
	b .L080E384E
.L080E384C:
	movs r4, #3
.L080E384E:
	adds r0, r4, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_080E3858
func_080E3858: @ 0x080E3858
	bx lr
	.align 2, 0

	thumb_func_start func_080E385C
func_080E385C: @ 0x080E385C
	push {lr}
	subs r0, #8
	bl GetHardwareHeldKeys
	pop {r1}
	bx r1

	thumb_func_start func_080E3868
func_080E3868: @ 0x080E3868
	push {lr}
	subs r0, #8
	bl GetHardwarePressedKeys
	pop {r1}
	bx r1

	thumb_func_start func_080E3874
func_080E3874: @ 0x080E3874
	push {lr}
	adds r2, r0, #0
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E3896
	adds r1, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E3892
	movs r0, #0
	b .L080E38AA
.L080E3892:
	movs r0, #1
	b .L080E38AA
.L080E3896:
	ldr r0, [r2]
	ldr r1, [r0, #0x4c]
	adds r0, r2, #0
	bl _call_via_r1
	movs r1, #0
	cmp r0, #0
	bne .L080E38A8
	movs r1, #1
.L080E38A8:
	adds r0, r1, #0
.L080E38AA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E38B0
func_080E38B0: @ 0x080E38B0
	push {lr}
	adds r1, r0, #0
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E38C8
	adds r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	b .L080E38DC
.L080E38C8:
	ldr r0, [r1, #0x14]
	ldr r2, [r0, #4]
	cmp r2, #0
	beq .L080E38DA
	ldr r0, [r1, #0x18]
	cmp r2, r0
	beq .L080E38DA
	movs r0, #1
	b .L080E38DC
.L080E38DA:
	movs r0, #0
.L080E38DC:
	pop {r1}
	bx r1

	thumb_func_start func_080E38E0
func_080E38E0: @ 0x080E38E0
	push {lr}
	adds r2, r0, #0
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E38F8
	adds r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b .L080E390C
.L080E38F8:
	ldr r0, [r2]
	ldr r1, [r0, #0x4c]
	adds r0, r2, #0
	bl _call_via_r1
	cmp r0, #0
	beq .L080E390A
	movs r0, #0
	b .L080E390C
.L080E390A:
	movs r0, #1
.L080E390C:
	pop {r1}
	bx r1

	thumb_func_start func_080E3910
func_080E3910: @ 0x080E3910
	movs r0, #1
	bx lr

	thumb_func_start func_080E3914
func_080E3914: @ 0x080E3914
	push {lr}
	bl StopJoyBusCommunication
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3920
func_080E3920: @ 0x080E3920
	push {lr}
	bl StartJoyBusCommunication
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E392C
func_080E392C: @ 0x080E392C
	push {lr}
	bl UpdateJoyBusCommunication
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3938
func_080E3938: @ 0x080E3938
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E397A
	ldr r0, [r4]
	subs r1, #0xb4
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080E3986
	ldr r0, [r4]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E398A
.L080E397A:
	bl func_080D06D0
	cmp r0, #0
	beq .L080E3986
	cmp r0, #0xb
	bne .L080E398A
.L080E3986:
	movs r0, #0
	b .L080E398C
.L080E398A:
	movs r0, #1
.L080E398C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E3994
func_080E3994: @ 0x080E3994
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E39D6
	ldr r0, [r4]
	subs r1, #0xb0
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080E39DE
	ldr r0, [r4]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E39DE
.L080E39D6:
	bl func_080D06D0
	cmp r0, #0xb
	beq .L080E39E2
.L080E39DE:
	movs r0, #0
	b .L080E39E4
.L080E39E2:
	movs r0, #1
.L080E39E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E39EC
func_080E39EC: @ 0x080E39EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E3A32
	ldr r0, [r4]
	subs r1, #0xb0
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080E3A2E
	ldr r0, [r4]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsrs r0, r0, #8
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080E3A32
.L080E3A2E:
	movs r0, #1
	b .L080E3A3E
.L080E3A32:
	bl func_080D06B4
	adds r1, r0, #0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
.L080E3A3E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_080E3A44
func_080E3A44: @ 0x080E3A44
	push {lr}
	bl func_080D06A8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3A50
func_080E3A50: @ 0x080E3A50
	push {lr}
	bl func_080D0678
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E3A5C
func_080E3A5C: @ 0x080E3A5C
	push {lr}
	adds r0, r1, #0
	lsls r1, r2, #0x18
	lsrs r1, r1, #0x18
	bl func_080D0644
	pop {r0}
	bx r0

	thumb_func_start func_080E3A6C
func_080E3A6C: @ 0x080E3A6C
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	bl func_080D0558
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3A80
func_080E3A80: @ 0x080E3A80
	push {lr}
	movs r0, #0
	bl func_080D0454
	pop {r0}
	bx r0

	thumb_func_start func_080E3A8C
func_080E3A8C: @ 0x080E3A8C
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	bl func_080D0444
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3A9C
func_080E3A9C: @ 0x080E3A9C
	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #4
	bhi .L080E3B58
	lsls r0, r1, #2
	ldr r1, .L080E3AB0 @ =.L080E3AB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080E3AB0: .4byte .L080E3AB4
.L080E3AB4: @ jump table
	.4byte .L080E3AC8 @ case 0
	.4byte .L080E3AD4 @ case 1
	.4byte .L080E3AE8 @ case 2
	.4byte .L080E3B10 @ case 3
	.4byte .L080E3B38 @ case 4
.L080E3AC8:
	movs r0, #0xdc
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	b .L080E3B58
.L080E3AD4:
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r4, .L080E3AE4 @ =0x000001B9
	b .L080E3B54
	.align 2, 0
.L080E3AE4: .4byte 0x000001B9
.L080E3AE8:
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r4, .L080E3B08 @ =0x000001B9
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, .L080E3B0C @ =0x000001BB
	adds r0, r3, r1
	b .L080E3B56
	.align 2, 0
.L080E3B08: .4byte 0x000001B9
.L080E3B0C: .4byte 0x000001BB
.L080E3B10:
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r4, .L080E3B30 @ =0x000001B9
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, .L080E3B34 @ =0x000001BB
	adds r0, r3, r2
	strb r1, [r0]
	b .L080E3B58
	.align 2, 0
.L080E3B30: .4byte 0x000001B9
.L080E3B34: .4byte 0x000001BB
.L080E3B38:
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #2
.L080E3B54:
	adds r0, r3, r4
.L080E3B56:
	strb r2, [r0]
.L080E3B58:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E3B60
func_080E3B60: @ 0x080E3B60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080E3B7C @ =vtable_unk_080E7F0C
	str r0, [r4]
	bl ResetJoyBusLinkRegisters
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_08094268
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3B7C: .4byte vtable_unk_080E7F0C

	thumb_func_start func_080E3B80
func_080E3B80: @ 0x080E3B80
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r6, r0, #0
	cmp r2, #0xf1
	beq .L080E3BB0
	cmp r2, #0xf1
	bgt .L080E3B94
	cmp r2, #0xf0
	beq .L080E3B9A
	b .L080E3C22
.L080E3B94:
	cmp r2, #0xff
	beq .L080E3BC8
	b .L080E3C22
.L080E3B9A:
	ldrb r0, [r1, #6]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, .L080E3BAC @ =gText_StaminaRecoveryStatus
	adds r5, r1, r0
	adds r0, r5, #0
	b .L080E3BF6
	.align 2, 0
.L080E3BAC: .4byte gText_StaminaRecoveryStatus
.L080E3BB0:
	ldrb r0, [r1, #7]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, .L080E3BC4 @ =gText_FatigueRecoveryStatus
	adds r5, r1, r0
	adds r0, r5, #0
	b .L080E3BF6
	.align 2, 0
.L080E3BC4: .4byte gText_FatigueRecoveryStatus
.L080E3BC8:
	ldrh r0, [r1, #4]
	cmp r0, #0xab
	bhi .L080E3BE2
	add r4, sp, #0x20
	adds r1, r0, #0
	subs r1, #1
	adds r0, r4, #0
	bl __4FoodUi
	adds r0, r4, #0
	bl GetName__C4Food
	b .L080E3BF4
.L080E3BE2:
	add r4, sp, #0x24
	ldrh r1, [r1, #4]
	subs r1, #0xac
	adds r0, r4, #0
	bl __7ArticleUi
	adds r0, r4, #0
	bl GetName__C7Article
.L080E3BF4:
	adds r5, r0, #0
.L080E3BF6:
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E3C02
	movs r4, #0x1f
.L080E3C02:
	mov r0, sp
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	mov r0, sp
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	adds r0, r6, #4
	mov r1, sp
	bl strcpy
	b .L080E3C30
.L080E3C22:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
	adds r0, r6, #4
	bl strcpy
.L080E3C30:
	adds r0, r6, #0
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E3C3C
func_080E3C3C: @ 0x080E3C3C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, .L080E3D88 @ =0x000033D8
	adds r1, r5, r0
	ldr r0, .L080E3D8C @ =__vt_23ScriptTextVariableStore
	str r0, [r1]
	movs r1, #0xca
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xba
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, .L080E3D90 @ =__vt_23IndexedResourceProvider
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0xf8
	str r4, [r0]
	subs r0, #0x30
	str r4, [r0]
	subs r0, #0x30
	str r4, [r0]
	subs r0, #0x18
	movs r1, #2
	bl _._12UiStateOwner
	ldr r1, [r5, #0x7c]
	cmp r1, #0
	beq .L080E3D5E
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E3D5E:
	ldr r1, [r5, #0x78]
	cmp r1, #0
	beq .L080E3D76
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E3D76:
	str r4, [r5, #0x10]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _._15HardwareContext
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080E3D88: .4byte 0x000033D8
.L080E3D8C: .4byte __vt_23ScriptTextVariableStore
.L080E3D90: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E3D94
func_080E3D94: @ 0x080E3D94
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E3DB0 @ =__vt_23ScriptTextVariableStore
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E3DAA
	adds r0, r2, #0
	bl __builtin_delete
.L080E3DAA:
	pop {r0}
	bx r0
	.align 2, 0
.L080E3DB0: .4byte __vt_23ScriptTextVariableStore

	thumb_func_start func_080E3DB4
func_080E3DB4: @ 0x080E3DB4
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r0, #0
	subs r0, r5, r3
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080E3DEC
	ldrh r1, [r4]
.L080E3DC6:
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bgt .L080E3DC6
.L080E3DEC:
	subs r0, r5, r3
	asrs r0, r0, #1
	cmp r0, #1
	beq .L080E3E14
	cmp r0, #1
	ble .L080E3E20
	cmp r0, #2
	beq .L080E3E0A
	cmp r0, #3
	bne .L080E3E20
	ldrh r0, [r3]
	ldrh r1, [r4]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
.L080E3E0A:
	ldrh r0, [r3]
	ldrh r1, [r4]
	cmp r0, r1
	beq .L080E3E1C
	adds r3, #2
.L080E3E14:
	ldrh r0, [r3]
	ldrh r4, [r4]
	cmp r0, r4
	bne .L080E3E20
.L080E3E1C:
	adds r0, r3, #0
	b .L080E3E22
.L080E3E20:
	adds r0, r5, #0
.L080E3E22:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_080E3E28
func_080E3E28: @ 0x080E3E28
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r0, #0
	subs r0, r5, r3
	asrs r2, r0, #3
	cmp r2, #0
	ble .L080E3E60
	ldrh r1, [r4]
.L080E3E3A:
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
	ldrh r0, [r3]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bgt .L080E3E3A
.L080E3E60:
	subs r0, r5, r3
	asrs r0, r0, #1
	cmp r0, #1
	beq .L080E3E88
	cmp r0, #1
	ble .L080E3E94
	cmp r0, #2
	beq .L080E3E7E
	cmp r0, #3
	bne .L080E3E94
	ldrh r0, [r3]
	ldrh r1, [r4]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
.L080E3E7E:
	ldrh r0, [r3]
	ldrh r1, [r4]
	cmp r0, r1
	beq .L080E3E90
	adds r3, #2
.L080E3E88:
	ldrh r0, [r3]
	ldrh r4, [r4]
	cmp r0, r4
	bne .L080E3E94
.L080E3E90:
	adds r0, r3, #0
	b .L080E3E96
.L080E3E94:
	adds r0, r5, #0
.L080E3E96:
	pop {r4, r5}
	pop {r1}
	bx r1

	.section .text.sprite_work_target_search_after, "ax", %progbits
	.align 2, 0

	thumb_func_start func_080E3F40
func_080E3F40: @ 0x080E3F40
	push {r4, r5, r6, r7, lr}
	sub sp, #0x40
	adds r6, r0, #0
	adds r3, r1, #0
	cmp r2, #0xf1
	beq .L080E4014
	cmp r2, #0xf1
	bgt .L080E3F56
	cmp r2, #0xf0
	beq .L080E3F5E
	b .L080E4086
.L080E3F56:
	cmp r2, #0xf2
	bne .L080E3F5C
	b .L080E4056
.L080E3F5C:
	b .L080E4086
.L080E3F5E:
	movs r5, #5
	ldrsb r5, [r3, r5]
	cmp r5, #1
	beq .L080E3FAC
	cmp r5, #1
	bgt .L080E3F70
	cmp r5, #0
	beq .L080E3F7A
	b .L080E4086
.L080E3F70:
	cmp r5, #2
	beq .L080E3FD8
	cmp r5, #3
	beq .L080E3FE0
	b .L080E4086
.L080E3F7A:
	ldr r7, .L080E3FA8 @ =gText_Calendar_DynamicSeasonNames
	adds r0, r7, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E3F8A
	movs r4, #0x1f
.L080E3F8A:
	mov r0, sp
	adds r1, r7, #0
	adds r2, r4, #0
	bl memcpy
	mov r1, sp
	adds r0, r1, r4
	strb r5, [r0]
	movs r0, #1
	strb r0, [r6]
	adds r0, r6, #4
	bl strcpy
	b .L080E4094
	.align 2, 0
.L080E3FA8: .4byte gText_Calendar_DynamicSeasonNames
.L080E3FAC:
	ldr r7, .L080E3FD4 @ =gText_Calendar_DynamicSeasonNames + 8
	adds r0, r7, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E3FBC
	movs r4, #0x1f
.L080E3FBC:
	mov r0, sp
	adds r1, r7, #0
	adds r2, r4, #0
	bl memcpy
	mov r1, sp
	adds r0, r1, r4
	movs r1, #0
	strb r1, [r0]
	strb r5, [r6]
	b .L080E4006
	.align 2, 0
.L080E3FD4:
	.ifdef REGION_DE
	.4byte gText_Calendar_DynamicSeasonNames + 0xC
	.else
	.4byte gText_Calendar_DynamicSeasonNames + 8
	.endif
.L080E3FD8:
	ldr r5, .L080E3FDC @ =gText_Calendar_DynamicSeasonNames + 0x10
	b .L080E3FE2
	.align 2, 0
.L080E3FDC:
	.ifdef REGION_DE
	.4byte gText_Calendar_DynamicSeasonNames + 0x14
	.else
	.4byte gText_Calendar_DynamicSeasonNames + 0x10
	.endif
.L080E3FE0:
	ldr r5, .L080E4010 @ =gText_Calendar_DynamicSeasonNames + 0x18
.L080E3FE2:
	adds r0, r5, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E3FF0
	movs r4, #0x1f
.L080E3FF0:
	mov r0, sp
	adds r1, r5, #0
	adds r2, r4, #0
	bl memcpy
	mov r0, sp
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
.L080E4006:
	adds r0, r6, #4
	mov r1, sp
	bl strcpy
	b .L080E4094
	.align 2, 0
.L080E4010:
	.ifdef REGION_DE
	.4byte gText_Calendar_DynamicSeasonNames + 0x1C
	.else
	.4byte gText_Calendar_DynamicSeasonNames + 0x18
	.endif
.L080E4014:
	movs r0, #4
	ldrsb r0, [r3, r0]
	cmp r0, #9
	bgt .L080E4034
	mov r1, sp
	movs r0, #0x81
	strb r0, [r1]
	movs r0, #0x40
	strb r0, [r1, #1]
	movs r0, #4
	ldrsb r0, [r3, r0]
	adds r1, #2
	movs r2, #0
	bl FormatSignedDecimal
	b .L080E4040
.L080E4034:
	movs r0, #4
	ldrsb r0, [r3, r0]
	mov r1, sp
	movs r2, #0
	bl FormatSignedDecimal
.L080E4040:
	add r5, sp, #0x20
	mov r0, sp
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E4050
	movs r4, #0x1f
.L080E4050:
	adds r0, r5, #0
	mov r1, sp
	b .L080E406C
.L080E4056:
	add r5, sp, #8
	ldr r7, [r3, #8]
	adds r0, r7, #0
	bl strlen
	adds r4, r0, #0
	cmp r4, #0x1f
	bls .L080E4068
	movs r4, #0x1f
.L080E4068:
	adds r0, r5, #0
	adds r1, r7, #0
.L080E406C:
	adds r2, r4, #0
	bl memcpy
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	adds r0, r6, #4
	adds r1, r5, #0
	bl strcpy
	b .L080E4094
.L080E4086:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
	adds r0, r6, #4
	bl strcpy
.L080E4094:
	adds r0, r6, #0
	add sp, #0x40
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E40A0
func_080E40A0: @ 0x080E40A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, .L080E4188 @ =__vt_23ScriptTextVariableStore
	str r0, [r1]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xca
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xba
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	adds r1, r5, #0
	adds r1, #0x80
	ldr r0, .L080E418C @ =__vt_23IndexedResourceProvider
	str r0, [r1]
	str r0, [r5, #0x50]
	str r0, [r5, #0x20]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq .L080E4178
	movs r1, #3
	bl _._12UiStateOwner
.L080E4178:
	adds r0, r5, #0
	adds r1, r6, #0
	bl _._15HardwareContext
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080E4188: .4byte __vt_23ScriptTextVariableStore
.L080E418C: .4byte __vt_23IndexedResourceProvider

	thumb_func_start func_080E4190
func_080E4190: @ 0x080E4190
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E41AC @ =__vt_23ScriptTextVariableStore
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E41A6
	adds r0, r2, #0
	bl __builtin_delete
.L080E41A6:
	pop {r0}
	bx r0
	.align 2, 0
.L080E41AC: .4byte __vt_23ScriptTextVariableStore

    .section .text.after_saved_name_scene_destructor, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E4244
func_080E4244: @ 0x080E4244
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x14]
	adds r5, r3, #0
	ldr r0, [r6, #4]
	cmp r5, r0
	beq .L080E426E
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080E42AE
	cmp r2, #0
	bne .L080E426E
	movs r2, #0
	ldr r1, [r4]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bge .L080E426A
	movs r2, #1
.L080E426A:
	cmp r2, #0
	beq .L080E42AE
.L080E426E:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E4282
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E4282:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E4292
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E4292:
	adds r4, r2, #0
	str r4, [r5, #8]
	ldr r1, [r6, #4]
	cmp r5, r1
	bne .L080E42A4
	str r4, [r5, #4]
	ldr r0, [r6, #4]
	str r4, [r0, #0xc]
	b .L080E42E0
.L080E42A4:
	ldr r0, [r1, #8]
	cmp r5, r0
	bne .L080E42E0
	str r4, [r1, #8]
	b .L080E42E0
.L080E42AE:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E42C2
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E42C2:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E42D2
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E42D2:
	adds r4, r2, #0
	str r4, [r5, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [r1, #0xc]
	cmp r5, r0
	bne .L080E42E0
	str r4, [r1, #0xc]
.L080E42E0:
	str r5, [r4, #4]
	movs r0, #0
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r6, #4]
	adds r1, #4
	adds r0, r4, #0
	bl func_080E21E0
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	str r4, [r7]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E4304
func_080E4304: @ 0x080E4304
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	ldr r4, [r1, #4]
	ldr r5, [r4, #4]
	movs r0, #1
	cmp r5, #0
	beq .L080E433A
	ldr r2, [r7]
.L080E431E:
	adds r4, r5, #0
	movs r1, #0
	ldr r0, [r4, #0x10]
	cmp r2, r0
	bge .L080E432A
	movs r1, #1
.L080E432A:
	adds r0, r1, #0
	cmp r0, #0
	beq .L080E4334
	ldr r5, [r4, #8]
	b .L080E4336
.L080E4334:
	ldr r5, [r4, #0xc]
.L080E4336:
	cmp r5, #0
	bne .L080E431E
.L080E433A:
	str r4, [sp, #8]
	cmp r0, #0
	beq .L080E4374
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	movs r1, #0
	cmp r4, r0
	bne .L080E4350
	movs r1, #1
.L080E4350:
	cmp r1, #0
	beq .L080E436C
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x10
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E4244
	movs r1, #1
	ldr r0, [sp, #0x10]
	b .L080E439E
.L080E436C:
	adds r0, r4, #0
	bl func_080E2354
	str r0, [sp, #8]
.L080E4374:
	ldr r2, [sp, #8]
	movs r3, #0
	ldr r1, [r2, #0x10]
	ldr r0, [r7]
	cmp r1, r0
	bge .L080E4382
	movs r3, #1
.L080E4382:
	adds r0, r3, #0
	cmp r0, #0
	beq .L080E43A4
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E4244
	movs r1, #1
	ldr r0, [sp, #0xc]
.L080E439E:
	str r0, [r6]
	strb r1, [r6, #4]
	b .L080E43A8
.L080E43A4:
	str r2, [r6]
	strb r0, [r6, #4]
.L080E43A8:
	adds r0, r6, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.saved_world_map_destructor_after, "ax", %progbits
    .align 2, 0

	thumb_func_start __12SavedMapTree
__12SavedMapTree: @ 0x080E43FC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #8
	movs r5, #0
	str r5, [r4, #4]
	movs r0, #0x18
	bl malloc
	cmp r0, #0
	bne .L080E441A
	movs r0, #0x18
	bl RetryMemoryAllocation
.L080E441A:
	str r0, [r4, #4]
	str r5, [r4, #8]
	str r5, [r4, #0xc]
	strb r5, [r0]
	str r5, [r0, #4]
	ldr r0, [r4, #4]
	str r0, [r0, #8]
	ldr r0, [r4, #4]
	str r0, [r0, #0xc]
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.world_sprite_effect_frames_after, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E44B8
func_080E44B8: @ 0x080E44B8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r5, #4
	movs r1, #2
	bl _._18GameSceneWorldData
	ldr r0, .L080E44E0 @ =__vt_14GameObjectBase
	str r0, [r5]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080E44D8
	adds r0, r5, #0
	bl __builtin_delete
.L080E44D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E44E0: .4byte __vt_14GameObjectBase

	thumb_func_start func_080E44E4
func_080E44E4: @ 0x080E44E4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x8c
	bl __builtin_new
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	add r2, sp, #0xc
	strb r1, [r2]
	adds r1, r4, #0
	movs r2, #5
	movs r3, #0x1b
	bl __22EntitySpriteControllerP12AActorEntityUiUiUiUiUib
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_080E4510
func_080E4510: @ 0x080E4510
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080E4540 @ =__vt_7AEntity
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq .L080E452C
	ldr r0, [r1, #4]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E452C:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E453A
	adds r0, r4, #0
	bl __builtin_delete
.L080E453A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E4540: .4byte __vt_7AEntity

	thumb_func_start func_080E4544
func_080E4544: @ 0x080E4544
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E4560 @ =__vt_14GameObjectBase
	str r0, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E455A
	adds r0, r2, #0
	bl __builtin_delete
.L080E455A:
	pop {r0}
	bx r0
	.align 2, 0
.L080E4560: .4byte __vt_14GameObjectBase

	thumb_func_start func_080E4564
func_080E4564: @ 0x080E4564
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, .L080E4818 @ =0x00000888
	adds r0, r5, r1
	movs r1, #2
	bl func_080E4860
	ldr r1, .L080E481C @ =0x0000082C
	adds r0, r5, r1
	movs r1, #2
	bl func_080098AC
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #2
	bl func_080098AC
	movs r1, #0xfd
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4820 @ =0x000007E4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xf8
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4824 @ =0x000007BC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E45DA
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E45DA
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r6, r5, r0
.L080E45CE:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E45CE
.L080E45DA:
	ldr r1, .L080E4828 @ =0x000006F4
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E45FA
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E45FA
	ldr r0, .L080E4828 @ =0x000006F4
	adds r6, r5, r0
.L080E45EE:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E45EE
.L080E45FA:
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E461E
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E461E
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r6, r5, r0
.L080E4612:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4612
.L080E461E:
	ldr r1, .L080E482C @ =0x0000062C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E463E
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E463E
	ldr r0, .L080E482C @ =0x0000062C
	adds r6, r5, r0
.L080E4632:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4632
.L080E463E:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4662
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4662
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r6, r5, r0
.L080E4656:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4656
.L080E4662:
	ldr r1, .L080E4830 @ =0x00000564
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4682
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4682
	ldr r0, .L080E4830 @ =0x00000564
	adds r6, r5, r0
.L080E4676:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4676
.L080E4682:
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E46A6
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E46A6
	movs r0, #0xaa
	lsls r0, r0, #3
	adds r6, r5, r0
.L080E469A:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E469A
.L080E46A6:
	ldr r1, .L080E4834 @ =0x0000052C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xa5
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4838 @ =0x00000504
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E483C @ =0x000004DC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4840 @ =0x000004B4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4844 @ =0x0000048C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x91
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4848 @ =0x00000464
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x8c
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E484C @ =0x0000043C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4740
	ldr r0, [r1, #8]
	ldr r2, [r0, #0xc]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4740:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4758
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4758:
	ldr r1, .L080E4850 @ =0x00000434
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E476E
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E476E:
	movs r1, #0x86
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4786
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4786:
	ldr r1, .L080E4854 @ =0x0000042C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E479C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E479C:
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E47B4
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E47B4:
	ldr r1, .L080E4858 @ =0x00000424
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E47CA
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E47CA:
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E47E2
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E47E2:
	ldr r1, .L080E485C @ =0x0000041C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E47F8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E47F8:
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E480A
	movs r1, #3
	bl _._12UiStateOwner
.L080E480A:
	adds r0, r5, #0
	adds r1, r7, #0
	bl _._15HardwareContext
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E4818: .4byte 0x00000888
.L080E481C: .4byte 0x0000082C
.L080E4820: .4byte 0x000007E4
.L080E4824: .4byte 0x000007BC
.L080E4828: .4byte 0x000006F4
.L080E482C: .4byte 0x0000062C
.L080E4830: .4byte 0x00000564
.L080E4834: .4byte 0x0000052C
.L080E4838: .4byte 0x00000504
.L080E483C: .4byte 0x000004DC
.L080E4840: .4byte 0x000004B4
.L080E4844: .4byte 0x0000048C
.L080E4848: .4byte 0x00000464
.L080E484C: .4byte 0x0000043C
.L080E4850: .4byte 0x00000434
.L080E4854: .4byte 0x0000042C
.L080E4858: .4byte 0x00000424
.L080E485C: .4byte 0x0000041C

	thumb_func_start func_080E4860
func_080E4860: @ 0x080E4860
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, [r6, #4]
	adds r0, r6, #0
	bl ReleaseObjTileHandle
	adds r0, r6, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E493A
	adds r0, r6, #0
	bl __builtin_delete
.L080E493A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start _._27ChickenFestivalMinigameCore
_._27ChickenFestivalMinigameCore: @ 0x080E4940
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, .L080E4C70 @ =0x00000AEC
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4966
	adds r1, #0x28
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4966
	ldr r0, .L080E4C70 @ =0x00000AEC
	adds r6, r5, r0
.L080E495A:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E495A
.L080E4966:
	ldr r1, .L080E4C74 @ =0x00000AC8
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C78 @ =0x00000AA4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C7C @ =0x00000A7C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C80 @ =0x00000A34
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E49B0
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E49B0
	ldr r0, .L080E4C80 @ =0x00000A34
	adds r6, r5, r0
.L080E49A4:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E49A4
.L080E49B0:
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C84 @ =0x000009E8
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E49DC
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E49DC
	ldr r0, .L080E4C84 @ =0x000009E8
	adds r6, r5, r0
.L080E49D0:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E49D0
.L080E49DC:
	ldr r1, .L080E4C88 @ =0x000009E4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x9c
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C8C @ =0x000009BC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C90 @ =0x00000998
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C94 @ =0x00000994
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C98 @ =0x0000096C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4C9C @ =0x00000924
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4A46
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4A46
	ldr r0, .L080E4C9C @ =0x00000924
	adds r6, r5, r0
.L080E4A3A:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4A3A
.L080E4A46:
	ldr r1, .L080E4CA0 @ =0x0000091C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4A66
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4A66
	ldr r0, .L080E4CA0 @ =0x0000091C
	adds r6, r5, r0
.L080E4A5A:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4A5A
.L080E4A66:
	ldr r1, .L080E4CA4 @ =0x000008F8
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4CA8 @ =0x000008F4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x8d
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4CAC @ =0x000008CC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4CB0 @ =0x00000884
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4AB0
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4AB0
	ldr r0, .L080E4CB0 @ =0x00000884
	adds r6, r5, r0
.L080E4AA4:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4AA4
.L080E4AB0:
	ldr r1, .L080E4CB4 @ =0x0000087C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4AD0
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4AD0
	ldr r0, .L080E4CB4 @ =0x0000087C
	adds r6, r5, r0
.L080E4AC4:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4AC4
.L080E4AD0:
	movs r1, #0xf9
	lsls r1, r1, #3
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4AF4
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4AF4
	movs r0, #0xf9
	lsls r0, r0, #3
	adds r6, r5, r0
.L080E4AE8:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4AE8
.L080E4AF4:
	ldr r1, .L080E4CB8 @ =0x000007B4
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4B14
	adds r1, #0x14
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4B14
	ldr r0, .L080E4CB8 @ =0x000007B4
	adds r6, r5, r0
.L080E4B08:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4B08
.L080E4B14:
	ldr r1, .L080E4CBC @ =0x000007AC
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4B34
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4B34
	ldr r0, .L080E4CBC @ =0x000007AC
	adds r6, r5, r0
.L080E4B28:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4B28
.L080E4B34:
	ldr r1, .L080E4CC0 @ =0x000007A4
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4B54
	adds r1, #8
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E4B54
	ldr r0, .L080E4CC0 @ =0x000007A4
	adds r6, r5, r0
.L080E4B48:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E4B48
.L080E4B54:
	movs r1, #0xf4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4B6C
	ldr r0, [r1, #8]
	ldr r2, [r0, #0xc]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4B6C:
	ldr r1, .L080E4CC4 @ =0x0000079C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4B82
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4B82:
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4B9A
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4B9A:
	ldr r1, .L080E4CC8 @ =0x00000794
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4BB0
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4BB0:
	movs r1, #0xf2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4BC8
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4BC8:
	ldr r1, .L080E4CCC @ =0x0000078C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4BDE
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4BDE:
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4BF6
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4BF6:
	ldr r1, .L080E4CD0 @ =0x00000784
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4C0C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4C0C:
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4C24
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4C24:
	ldr r0, .L080E4CD4 @ =0x0000077C
	adds r4, r5, r0
	ldr r1, [r4]
	cmp r1, #0
	beq .L080E4C3A
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4C3A:
	ldr r1, .L080E4CD8 @ =0x0000073C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4C5E
	cmp r0, r4
	beq .L080E4C5E
	adds r6, r0, #0
.L080E4C48:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r6, r4
	bne .L080E4C48
.L080E4C5E:
	ldr r1, .L080E4CDC @ =0x0000072C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E4CFC
	adds r1, #0x10
	adds r4, r5, r1
	cmp r0, r4
	b .L080E4CE0
	.align 2, 0
.L080E4C70: .4byte 0x00000AEC
.L080E4C74: .4byte 0x00000AC8
.L080E4C78: .4byte 0x00000AA4
.L080E4C7C: .4byte 0x00000A7C
.L080E4C80: .4byte 0x00000A34
.L080E4C84: .4byte 0x000009E8
.L080E4C88: .4byte 0x000009E4
.L080E4C8C: .4byte 0x000009BC
.L080E4C90: .4byte 0x00000998
.L080E4C94: .4byte 0x00000994
.L080E4C98: .4byte 0x0000096C
.L080E4C9C: .4byte 0x00000924
.L080E4CA0: .4byte 0x0000091C
.L080E4CA4: .4byte 0x000008F8
.L080E4CA8: .4byte 0x000008F4
.L080E4CAC: .4byte 0x000008CC
.L080E4CB0: .4byte 0x00000884
.L080E4CB4: .4byte 0x0000087C
.L080E4CB8: .4byte 0x000007B4
.L080E4CBC: .4byte 0x000007AC
.L080E4CC0: .4byte 0x000007A4
.L080E4CC4: .4byte 0x0000079C
.L080E4CC8: .4byte 0x00000794
.L080E4CCC: .4byte 0x0000078C
.L080E4CD0: .4byte 0x00000784
.L080E4CD4: .4byte 0x0000077C
.L080E4CD8: .4byte 0x0000073C
.L080E4CDC: .4byte 0x0000072C
.L080E4CE0:
	beq .L080E4CFC
	ldr r0, .L080E4D44 @ =0x0000072C
	adds r6, r5, r0
.L080E4CE6:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r6, r4
	bne .L080E4CE6
.L080E4CFC:
	ldr r1, .L080E4D48 @ =0x00000724
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	ldr r0, .L080E4D4C @ =0x0000071C
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E4D36
	movs r1, #3
	bl _._12UiStateOwner
.L080E4D36:
	adds r0, r5, #0
	adds r1, r7, #0
	bl _._15HardwareContext
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E4D44: .4byte 0x0000072C
.L080E4D48: .4byte 0x00000724
.L080E4D4C: .4byte 0x0000071C

	thumb_func_start func_080E4D50
func_080E4D50: @ 0x080E4D50
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xb6
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	bl func_080E4F34
	ldr r1, .L080E4F00 @ =0x00000594
	adds r0, r4, r1
	movs r1, #2
	bl func_080098AC
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	bl func_080098AC
	ldr r1, .L080E4F04 @ =0x00000554
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F08 @ =0x0000052C
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xa5
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F0C @ =0x00000504
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F10 @ =0x000004DC
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F14 @ =0x000004B4
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F18 @ =0x0000048C
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x91
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F1C @ =0x00000464
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0x8c
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E4F20 @ =0x0000043C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E28
	ldr r0, [r1, #8]
	ldr r2, [r0, #0xc]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E28:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E40
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E40:
	ldr r1, .L080E4F24 @ =0x00000434
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E56
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E56:
	movs r1, #0x86
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E6E
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E6E:
	ldr r1, .L080E4F28 @ =0x0000042C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E84
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E84:
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4E9C
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4E9C:
	ldr r1, .L080E4F2C @ =0x00000424
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4EB2
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4EB2:
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4ECA
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4ECA:
	ldr r1, .L080E4F30 @ =0x0000041C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E4EE0
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E4EE0:
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E4EF2
	movs r1, #3
	bl _._12UiStateOwner
.L080E4EF2:
	adds r0, r4, #0
	adds r1, r5, #0
	bl _._15HardwareContext
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080E4F00: .4byte 0x00000594
.L080E4F04: .4byte 0x00000554
.L080E4F08: .4byte 0x0000052C
.L080E4F0C: .4byte 0x00000504
.L080E4F10: .4byte 0x000004DC
.L080E4F14: .4byte 0x000004B4
.L080E4F18: .4byte 0x0000048C
.L080E4F1C: .4byte 0x00000464
.L080E4F20: .4byte 0x0000043C
.L080E4F24: .4byte 0x00000434
.L080E4F28: .4byte 0x0000042C
.L080E4F2C: .4byte 0x00000424
.L080E4F30: .4byte 0x0000041C

	thumb_func_start func_080E4F34
func_080E4F34: @ 0x080E4F34
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r6, #0
	adds r4, #0x40
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, [r6, #4]
	adds r0, r6, #0
	bl ReleaseObjTileHandle
	adds r0, r6, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E4FEA
	adds r0, r6, #0
	bl __builtin_delete
.L080E4FEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_080E4FF0
func_080E4FF0: @ 0x080E4FF0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, .L080E5250 @ =0x0000083C
	adds r0, r5, r1
	movs r1, #2
	bl func_080E5324
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #2
	bl func_080098AC
	ldr r1, .L080E5254 @ =0x00000824
	adds r0, r5, r1
	movs r1, #2
	bl func_080098AC
	ldr r1, .L080E5258 @ =0x000007EC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xfd
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E525C @ =0x000007C4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xf8
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5260 @ =0x0000079C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5264 @ =0x00000754
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xea
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5268 @ =0x0000072C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E526C @ =0x000006A4
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E50A4
	adds r1, #0x64
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E50A4
	ldr r0, .L080E526C @ =0x000006A4
	adds r6, r5, r0
.L080E5098:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E5098
.L080E50A4:
	movs r1, #0xd4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5270 @ =0x0000061C
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E50D0
	adds r1, #0x64
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E50D0
	ldr r0, .L080E5270 @ =0x0000061C
	adds r6, r5, r0
.L080E50C4:
	subs r4, #4
	ldr r0, [r4]
	bl __builtin_delete
	cmp r6, r4
	bne .L080E50C4
.L080E50D0:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5274 @ =0x000005F4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5278 @ =0x000005CC
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E527C @ =0x000005A4
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5280 @ =0x0000057C
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5284 @ =0x00000554
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl __builtin_delete
	ldr r1, .L080E5288 @ =0x00000544
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E5160
	ldr r0, [r1, #8]
	ldr r2, [r0, #0xc]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E5160:
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E5178
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E5178:
	ldr r1, .L080E528C @ =0x0000053C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E518E
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E518E:
	movs r1, #0xa7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E51A6
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E51A6:
	ldr r1, .L080E5290 @ =0x00000534
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E51BC
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E51BC:
	movs r1, #0xa6
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E51D4
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E51D4:
	ldr r1, .L080E5294 @ =0x0000052C
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E51EA
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E51EA:
	movs r1, #0xa5
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E5202
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E5202:
	ldr r1, .L080E5298 @ =0x00000524
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E5218
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E5218:
	movs r1, #0xa4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080E5230
	ldr r0, [r1]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080E5230:
	ldr r1, .L080E529C @ =0x0000051C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080E5240
	movs r1, #3
	bl _._12UiStateOwner
.L080E5240:
	adds r0, r5, #0
	adds r1, r7, #0
	bl _._15HardwareContext
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E5250: .4byte 0x0000083C
.L080E5254: .4byte 0x00000824
.L080E5258: .4byte 0x000007EC
.L080E525C: .4byte 0x000007C4
.L080E5260: .4byte 0x0000079C
.L080E5264: .4byte 0x00000754
.L080E5268: .4byte 0x0000072C
.L080E526C: .4byte 0x000006A4
.L080E5270: .4byte 0x0000061C
.L080E5274: .4byte 0x000005F4
.L080E5278: .4byte 0x000005CC
.L080E527C: .4byte 0x000005A4
.L080E5280: .4byte 0x0000057C
.L080E5284: .4byte 0x00000554
.L080E5288: .4byte 0x00000544
.L080E528C: .4byte 0x0000053C
.L080E5290: .4byte 0x00000534
.L080E5294: .4byte 0x0000052C
.L080E5298: .4byte 0x00000524
.L080E529C: .4byte 0x0000051C

	thumb_func_start func_080E52A0
func_080E52A0: @ 0x080E52A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitializeObjTilePoolOwner
	movs r5, #0
	str r5, [r6, #4]
	adds r4, r6, #0
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r4, #8
	adds r0, r4, #0
	bl InitializeObjTilePoolOwner
	str r5, [r4, #4]
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_080E5324
func_080E5324: @ 0x080E5324
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r6, #0
	adds r4, #0x58
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	ldr r1, [r6, #4]
	adds r0, r6, #0
	bl ReleaseObjTileHandle
	adds r0, r6, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E5410
	adds r0, r6, #0
	bl __builtin_delete
.L080E5410:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

    .section .text.after_ui_vcount_binding, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E54C4
func_080E54C4: @ 0x080E54C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	beq .L080E54E8
.L080E54CE:
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	bl func_080E54C4
	ldr r5, [r4, #8]
	cmp r4, #0
	beq .L080E54E2
	adds r0, r4, #0
	bl free
.L080E54E2:
	adds r4, r5, #0
	cmp r4, #0
	bne .L080E54CE
.L080E54E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_080E54F0
func_080E54F0: @ 0x080E54F0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x14]
	adds r5, r3, #0
	ldr r0, [r6, #4]
	cmp r5, r0
	beq .L080E551A
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080E555A
	cmp r2, #0
	bne .L080E551A
	movs r2, #0
	ldr r1, [r4]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bhs .L080E5516
	movs r2, #1
.L080E5516:
	cmp r2, #0
	beq .L080E555A
.L080E551A:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E552E
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E552E:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E553E
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E553E:
	adds r4, r2, #0
	str r4, [r5, #8]
	ldr r1, [r6, #4]
	cmp r5, r1
	bne .L080E5550
	str r4, [r5, #4]
	ldr r0, [r6, #4]
	str r4, [r0, #0xc]
	b .L080E558C
.L080E5550:
	ldr r0, [r1, #8]
	cmp r5, r0
	bne .L080E558C
	str r4, [r1, #8]
	b .L080E558C
.L080E555A:
	movs r0, #0x18
	bl malloc
	adds r2, r0, #0
	cmp r2, #0
	bne .L080E556E
	movs r0, #0x18
	bl RetryMemoryAllocation
	adds r2, r0, #0
.L080E556E:
	adds r1, r2, #0
	adds r1, #0x10
	cmp r1, #0
	beq .L080E557E
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
.L080E557E:
	adds r4, r2, #0
	str r4, [r5, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [r1, #0xc]
	cmp r5, r0
	bne .L080E558C
	str r4, [r1, #0xc]
.L080E558C:
	str r5, [r4, #4]
	movs r0, #0
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r6, #4]
	adds r1, #4
	adds r0, r4, #0
	bl func_080E21E0
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	str r4, [r7]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E55B0
func_080E55B0: @ 0x080E55B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	ldr r4, [r1, #4]
	ldr r5, [r4, #4]
	movs r0, #1
	cmp r5, #0
	beq .L080E55E6
	ldr r2, [r7]
.L080E55CA:
	adds r4, r5, #0
	movs r1, #0
	ldr r0, [r4, #0x10]
	cmp r2, r0
	bhs .L080E55D6
	movs r1, #1
.L080E55D6:
	adds r0, r1, #0
	cmp r0, #0
	beq .L080E55E0
	ldr r5, [r4, #8]
	b .L080E55E2
.L080E55E0:
	ldr r5, [r4, #0xc]
.L080E55E2:
	cmp r5, #0
	bne .L080E55CA
.L080E55E6:
	str r4, [sp, #8]
	cmp r0, #0
	beq .L080E5620
	mov r1, r8
	ldr r0, [r1, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	movs r1, #0
	cmp r4, r0
	bne .L080E55FC
	movs r1, #1
.L080E55FC:
	cmp r1, #0
	beq .L080E5618
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x10
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E54F0
	movs r1, #1
	ldr r0, [sp, #0x10]
	b .L080E564A
.L080E5618:
	adds r0, r4, #0
	bl func_080E2354
	str r0, [sp, #8]
.L080E5620:
	ldr r2, [sp, #8]
	movs r3, #0
	ldr r1, [r2, #0x10]
	ldr r0, [r7]
	cmp r1, r0
	bhs .L080E562E
	movs r3, #1
.L080E562E:
	adds r0, r3, #0
	cmp r0, #0
	beq .L080E5650
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_080E54F0
	movs r1, #1
	ldr r0, [sp, #0xc]
.L080E564A:
	str r0, [r6]
	strb r1, [r6, #4]
	b .L080E5654
.L080E5650:
	str r2, [r6]
	strb r0, [r6, #4]
.L080E5654:
	adds r0, r6, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_080E5664
func_080E5664: @ 0x080E5664
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, [r6, #4]
	ldr r2, [r2]
	ldr r0, [r1, #8]
	cmp r2, r0
	bne .L080E56F4
	ldr r0, [r6, #8]
	cmp r0, #0
	bne .L080E5694
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E55B0
	ldr r0, [sp, #8]
	b .L080E5808
.L080E5694:
	movs r0, #0
	ldr r1, [r2, #0x10]
	adds r3, r2, #0
	ldr r2, [r4]
	cmp r2, r1
	bhs .L080E56A2
	movs r0, #1
.L080E56A2:
	mov sb, r0
	cmp r0, #0
	bne .L080E5768
	movs r0, #0
	cmp r1, r2
	bhs .L080E56B0
	movs r0, #1
.L080E56B0:
	cmp r0, #0
	bne .L080E56B8
	str r3, [r7]
	b .L080E580A
.L080E56B8:
	str r3, [sp, #8]
	adds r0, r3, #0
	bl func_080E2B28
	adds r2, r0, #0
	str r2, [sp, #8]
	ldr r0, [r6, #4]
	cmp r2, r0
	bne .L080E56D0
	mov r0, r8
	ldr r3, [r0]
	b .L080E57CE
.L080E56D0:
	movs r3, #0
	ldr r1, [r4]
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r1, r0
	bhs .L080E56DE
	movs r3, #1
.L080E56DE:
	cmp r3, #0
	bne .L080E56E4
	b .L080E57FC
.L080E56E4:
	mov r1, r8
	ldr r3, [r1]
	ldr r0, [r3, #0xc]
	cmp r0, #0
	beq .L080E57CE
	str r4, [sp]
	mov r0, sb
	b .L080E57E2
.L080E56F4:
	cmp r2, r1
	bne .L080E571E
	ldr r3, [r2, #0xc]
	movs r5, #0
	ldr r1, [r3, #0x10]
	ldr r0, [r4]
	cmp r1, r0
	bhs .L080E5706
	movs r5, #1
.L080E5706:
	cmp r5, #0
	beq .L080E5710
	str r4, [sp]
	str r2, [sp, #4]
	b .L080E57D2
.L080E5710:
	add r0, sp, #8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E55B0
	ldr r0, [sp, #8]
	b .L080E5808
.L080E571E:
	str r2, [sp, #8]
	adds r0, r2, #0
	bl func_080E2354
	adds r2, r0, #0
	str r2, [sp, #8]
	mov r1, r8
	ldr r3, [r1]
	movs r5, #0
	ldr r1, [r4]
	ldr r0, [r3, #0x10]
	cmp r1, r0
	bhs .L080E573A
	movs r5, #1
.L080E573A:
	mov sb, r5
	cmp r5, #0
	beq .L080E577A
	movs r0, #0
	mov ip, r0
	ldr r0, [r2, #0x10]
	adds r5, r2, #0
	cmp r0, r1
	bhs .L080E5750
	movs r1, #1
	mov ip, r1
.L080E5750:
	mov r0, ip
	cmp r0, #0
	beq .L080E577A
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne .L080E5768
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	b .L080E57EA
.L080E5768:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r3, #0
	bl func_080E54F0
	b .L080E580A
.L080E577A:
	mov r1, r8
	ldr r0, [r1]
	str r0, [sp, #0xc]
	bl func_080E2B28
	mov ip, r0
	str r0, [sp, #0xc]
	movs r0, #1
	mov r1, sb
	eors r1, r0
	mov r0, sb
	cmp r0, #0
	bne .L080E57F2
	mov r1, r8
	ldr r0, [r1]
	movs r5, #0
	ldr r1, [r0, #0x10]
	adds r3, r0, #0
	ldr r2, [r4]
	cmp r1, r2
	bhs .L080E57A6
	movs r5, #1
.L080E57A6:
	adds r1, r5, #0
	cmp r1, #0
	beq .L080E57F2
	ldr r0, [r6, #4]
	mov r5, ip
	cmp r5, r0
	beq .L080E57C8
	movs r0, #0
	mov ip, r0
	ldr r0, [r5, #0x10]
	cmp r2, r0
	bhs .L080E57C2
	movs r0, #1
	mov ip, r0
.L080E57C2:
	mov r0, ip
	cmp r0, #0
	beq .L080E57F2
.L080E57C8:
	ldr r0, [r3, #0xc]
	cmp r0, #0
	bne .L080E57DE
.L080E57CE:
	str r4, [sp]
	str r3, [sp, #4]
.L080E57D2:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl func_080E54F0
	b .L080E580A
.L080E57DE:
	str r4, [sp]
	movs r0, #0
.L080E57E2:
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
.L080E57EA:
	adds r3, r5, #0
	bl func_080E54F0
	b .L080E580A
.L080E57F2:
	cmp sb, r1
	bne .L080E57FC
	mov r1, r8
	ldr r0, [r1]
	b .L080E5808
.L080E57FC:
	add r0, sp, #0x10
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_080E55B0
	ldr r0, [sp, #0x10]
.L080E5808:
	str r0, [r7]
.L080E580A:
	adds r0, r7, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

    .section .text.after_menu_command_node_cleanup, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E5898
func_080E5898: @ 0x080E5898
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r1
	movs r0, #0x84
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, .L080E5968 @ =vtable_unk_080E85AC
	str r0, [r1]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	cmp r0, #0
	beq .L080E58DA
	adds r1, #0x40
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E58DA
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r6, r5, r0
.L080E58C4:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	cmp r6, r4
	bne .L080E58C4
.L080E58DA:
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r5, r1
	subs r1, #0x94
	adds r7, r5, r1
	cmp r0, #0
	beq .L080E590C
	adds r1, #0xd4
	adds r4, r5, r1
	cmp r0, r4
	beq .L080E590C
	movs r0, #0xab
	lsls r0, r0, #2
	adds r6, r5, r0
.L080E58F6:
	subs r4, #8
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	cmp r6, r4
	bne .L080E58F6
.L080E590C:
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjPaletteHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._19ObjPalettePoolOwner
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseObjTileHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._16ObjTilePoolOwner
	movs r1, #0x85
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	adds r2, r2, r0
	adds r0, r7, #0
	cmp r0, r2
	beq .L080E5956
.L080E5950:
	adds r0, #0xc
	cmp r0, r2
	bne .L080E5950
.L080E5956:
	adds r0, r5, #0
	mov r1, r8
	bl func_080CADF0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080E5968: .4byte vtable_unk_080E85AC

    .section .text.after_menu_core_prefix_destructor, "ax", %progbits
    .align 2, 0

	thumb_func_start func_080E59C0
func_080E59C0: @ 0x080E59C0
	push {lr}
	bl _._17GameSceneWorldMap
	pop {r0}
	bx r0
.align 2, 0

    .endif

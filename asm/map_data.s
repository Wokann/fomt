    .include "asm/macro.inc"
    .syntax unified
    .section .text, "ax", %progbits
    .thumb
    .align 2, 0

    @ All tiles intersecting [x-6,x+5] x [y-8,y+3] must have bit 1.
    @ The invalid/null-view paths return false. C++ matching is pending.


	thumb_func_start IsMapTerrainFlag1Footprint
IsMapTerrainFlag1Footprint:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r0, r2, #0
	subs r0, #8
	asrs r3, r0, #3
	subs r0, r1, #6
	asrs r0, r0, #3
	mov sl, r0
	adds r2, #3
	asrs r2, r2, #3
	mov r8, r2
	adds r1, #5
	asrs r7, r1, #3
	cmp r3, r8
	bgt .Lflag1_fail
	cmp sl, r7
	bgt .Lflag1_fail
	ldrh r0, [r4, #8]
	mov sb, r0
	cmp r3, #0
	blt .Lflag1_fail
	mov r1, sl
	cmp r1, #0
	blt .Lflag1_fail
	ldrh r0, [r4, #0xa]
	cmp r8, r0
	bhs .Lflag1_fail
	cmp r7, sb
	bhs .Lflag1_fail
	ldr r6, [r4]
	cmp r6, #0
	bne .Lflag1_scan
.Lflag1_fail:
	movs r0, #0
	b .Lflag1_return
.Lflag1_scan:
	ldr r4, [r4, #4]
	mov ip, r4
	adds r5, r3, #0
	cmp r5, r8
	bgt .Lflag1_success
	mov r4, sb
	muls r4, r5, r4
.Lflag1_row:
	mov r3, sl
	cmp r3, r7
	bgt .Lflag1_next_row
	adds r0, r3, r4
	lsls r2, r0, #2
	mov r1, ip
	adds r0, r4, r1
	adds r1, r3, r0
.Lflag1_column:
	mov r0, ip
	cmp r0, #0
	beq .Lflag1_direct
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r6, r0
	b .Lflag1_test
.Lflag1_direct:
	adds r0, r6, r2
.Lflag1_test:
	ldr r0, [r0]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .Lflag1_fail
	adds r2, #4
	adds r1, #1
	adds r3, #1
	cmp r3, r7
	ble .Lflag1_column
.Lflag1_next_row:
	add r4, sb
	adds r5, #1
	cmp r5, r8
	ble .Lflag1_row
.Lflag1_success:
	movs r0, #1
.Lflag1_return:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

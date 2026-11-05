    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start RepositionBlockedFarmHouseEntities
RepositionBlockedFarmHouseEntities:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r7, r0, #0
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    cmp r0, #0x2a
    beq .L0801E6B0
    cmp r0, #0x2a
    bgt .L0801E69C
    cmp r0, #0x29
    beq .L0801E6A2
    b .L0801E8F6
.L0801E69C:
    cmp r0, #0x2b
    beq .L0801E6B8
    b .L0801E8F6
.L0801E6A2:
    ldr r1, .L0801E6AC @ =gFarmHouseOriginalRelocationPositions
    str r1, [sp, #0x14]
    movs r1, #5
    b .L0801E6BE
    .align 2, 0
.L0801E6AC: .word gFarmHouseOriginalRelocationPositions
.L0801E6B0:
    ldr r1, .L0801E6B4 @ =gFarmHouseFirstExtensionRelocationPositions
    b .L0801E6BA
    .align 2, 0
.L0801E6B4: .word gFarmHouseFirstExtensionRelocationPositions
.L0801E6B8:
    ldr r1, .L0801E70C @ =gFarmHouseSecondExtensionRelocationPositions
.L0801E6BA:
    str r1, [sp, #0x14]
    movs r1, #6
.L0801E6BE:
    mov sl, r1
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r4, [r7, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    movs r2, #0
    ldr r0, [r4, #0x2c]
    mov r1, sp
    str r0, [sp]
    str r2, [sp, #4]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    mov r8, r2
.L0801E6E0:
    mov r6, r8
    ldr r0, [r7]
    ldr r2, [r0, #0x40]
    adds r0, r7, #0
    mov r1, r8
    bl _call_via_r2
    adds r5, r0, #0
    cmp r5, #0
    bne .L0801E6F6
    b .L0801E8EA
.L0801E6F6:
    movs r0, #0
    mov sb, r0
    mov r0, r8
    subs r0, #0x2b
    cmp r0, #(.LcheckFarmHouseCollision - .LfarmHouseCollisionCases) / 4 - 1
    bhi .L0801E7DE
    lsls r0, r0, #2
    ldr r1, .L0801E710 @ =.LfarmHouseCollisionCases
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801E70C: .word gFarmHouseSecondExtensionRelocationPositions
.L0801E710: .word .LfarmHouseCollisionCases
.LfarmHouseCollisionCases: @ jump table
    .word .LcheckFarmHouseCollision @ case 0
    .word .L0801E7DE @ case 1
    .word .L0801E7DE @ case 2
    .word .LcheckFarmHouseCollision @ case 3
    .word .LcheckFarmHouseCollision @ case 4
    .word .LcheckFarmHouseCollision @ case 5
    .word .LcheckFarmHouseCollision @ case 6
    .word .LcheckFarmHouseCollision @ case 7
    .word .LcheckFarmHouseCollision @ case 8
    .word .LcheckFarmHouseCollision @ case 9
    .word .LcheckFarmHouseCollision @ case 10
    .word .L0801E7DE @ case 11
    .word .L0801E7DE @ case 12
    .word .L0801E7DE @ case 13
    .word .L0801E7DE @ case 14
    .word .L0801E7DE @ case 15
    .word .L0801E7DE @ case 16
    .word .L0801E7DE @ case 17
    .word .L0801E7DE @ case 18
    .word .L0801E7DE @ case 19
    .word .L0801E7DE @ case 20
    .word .L0801E7DE @ case 21
    .word .L0801E7DE @ case 22
    .word .L0801E7DE @ case 23
    .word .L0801E7DE @ case 24
    .word .L0801E7DE @ case 25
    .word .L0801E7DE @ case 26
    .word .L0801E7DE @ case 27
    .word .L0801E7DE @ case 28
    .word .L0801E7DE @ case 29
    .word .L0801E7DE @ case 30
    .word .LcheckFarmHouseCollision @ case 31
    .word .LcheckFarmHouseCollision @ case 32
    .word .LcheckFarmHouseCollision @ case 33
    .word .LcheckFarmHouseCollision @ case 34
    .word .LcheckFarmHouseCollision @ case 35
    .word .LcheckFarmHouseCollision @ case 36
    .word .LcheckFarmHouseCollision @ case 37
    .word .LcheckFarmHouseCollision @ case 38
    .word .LcheckFarmHouseCollision @ case 39
    .word .LcheckFarmHouseCollision @ case 40
.LcheckFarmHouseCollision:
    ldrh r0, [r5, #4]
    cmp r0, #0x1d
    bne .L0801E7DE
    ldr r1, [r5, #0x14]
    add r4, sp, #0xc
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r5, #0
    bl _call_via_r2
    mov r0, sp
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801E7DE
    movs r1, #1
    mov sb, r1
.L0801E7DE:
    mov r0, sb
    cmp r0, #0
    bne .L0801E7E6
    b .L0801E8EA
.L0801E7E6:
    adds r0, r6, #0
    subs r0, #0x2b
    cmp r0, #(.LrelocateFarmHouseEntity - .LfarmHouseRelocationCases) / 4 - 1
    bhi .LrelocateFarmHouseEntity
    lsls r0, r0, #2
    ldr r1, .L0801E7F8 @ =.LfarmHouseRelocationCases
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801E7F8: .word .LfarmHouseRelocationCases
.LfarmHouseRelocationCases: @ jump table
    .word .LrelocateFarmHouseEntity @ case 0
    .word .LrelocateFarmHouseEntity @ case 1
    .word .LrelocateFarmHouseEntity @ case 2
    .word .LrelocateFarmHouseEntity @ case 3
    .word .LrelocateFarmHouseEntity @ case 4
    .word .LrelocateFarmHouseEntity @ case 5
    .word .LrelocateFarmHouseEntity @ case 6
    .word .LrelocateFarmHouseEntity @ case 7
    .word .LrelocateFarmHouseEntity @ case 8
    .word .LrelocateFarmHouseEntity @ case 9
    .word .LrelocateFarmHouseEntity @ case 10
    .word .LrelocateFarmHouseEntity @ case 11
    .word .LrelocateFarmHouseEntity @ case 12
    .word .LrelocateFarmHouseEntity @ case 13
    .word .LrelocateFarmHouseEntity @ case 14
    .word .LrelocateFarmHouseEntity @ case 15
    .word .LrelocateFarmHouseEntity @ case 16
    .word .LrelocateFarmHouseEntity @ case 17
    .word .LrelocateFarmHouseEntity @ case 18
    .word .LrelocateFarmHouseEntity @ case 19
    .word .LrelocateFarmHouseEntity @ case 20
    .word .LrelocateFarmHouseEntity @ case 21
    .word .LrelocateFarmHouseEntity @ case 22
    .word .LrelocateFarmHouseEntity @ case 23
    .word .LrelocateFarmHouseEntity @ case 24
    .word .LrelocateFarmHouseEntity @ case 25
    .word .LrelocateFarmHouseEntity @ case 26
    .word .LrelocateFarmHouseEntity @ case 27
    .word .LrelocateFarmHouseEntity @ case 28
    .word .LrelocateFarmHouseEntity @ case 29
    .word .LrelocateFarmHouseEntity @ case 30
    .word .LrelocateFarmHouseEntity @ case 31
    .word .LrelocateFarmHouseEntity @ case 32
    .word .L0801E8C6 @ case 33
    .word .L0801E8C6 @ case 34
    .word .L0801E8C6 @ case 35
    .word .L0801E8C6 @ case 36
    .word .L0801E8C6 @ case 37
    .word .L0801E8C6 @ case 38
    .word .L0801E8C6 @ case 39
    .word .L0801E8C6 @ case 40
.LrelocateFarmHouseEntity:
    cmp r5, #0
    beq .L0801E8EA
    bl rand
    mov r1, sl
    bl __umodsi3
    lsls r0, r0, #2
    ldr r1, [sp, #0x14]
    adds r0, r1, r0
    movs r1, #0
    ldrsh r2, [r0, r1]
    movs r1, #2
    ldrsh r3, [r0, r1]
    adds r0, r5, #0
    movs r1, #0x1d
    bl SetLocation__7AEntityUiii
    b .L0801E8EA
.L0801E8C6:
    cmp r5, #0
    beq .L0801E8EA
    ldr r0, [r7]
    ldr r2, [r0, #0x3c]
    adds r0, r7, #0
    adds r1, r6, #0
    bl _call_via_r2
    ldr r1, .L0801E908 @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r6, #0
    subs r1, #0x4c
    bl method_0800C9B8__4CoopUi
.L0801E8EA:
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #0x63
    bgt .L0801E8F6
    b .L0801E6E0
.L0801E8F6:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801E908: .word 0x00001038

    .syntax unified
    .cpu arm7tdmi
    .thumb
    .section .text, "ax", %progbits
    .align 2, 0

    @ Indexed terrain copying remains native until its C++ matches.
    @ Farm initialization is compiled from src/farm_terrain.cc.
    .global ApplyMapTerrainPatch
    .type ApplyMapTerrainPatch, %function
    .thumb_func
ApplyMapTerrainPatch:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r5, r0, #0
    adds r6, r1, #0
    adds r4, r2, #0
    cmp r5, #0
    beq .L080171EC
    cmp r6, #0
    beq .L080171EC
    ldr r2, [r4, #0x14]
    cmp r2, #0
    beq .L080171EC
    ldr r0, [r4, #0x10]
    mov r8, r0
    cmp r0, #0
    beq .L080171EC
    ldrb r7, [r4]
    adds r0, r3, r7
    cmp r0, r6
    bhi .L080171EC
    lsls r1, r3, #2
    adds r1, r5, r1
    ldr r0, [sp, #0x1c]
    muls r0, r6, r0
    lsls r0, r0, #2
    adds r5, r1, r0
    ldrb r4, [r4, #1]
    mov ip, r4
    movs r0, #0
    cmp r0, ip
    bhs .L080171EC
    lsls r6, r6, #2
    mov sb, r6
.L080171C6:
    movs r1, #0
    adds r6, r0, #1
    cmp r1, r7
    bhs .L080171E4
    mov r3, r8
    adds r4, r5, #0
.L080171D2:
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r0, [r0]
    stm r4!, {r0}
    adds r2, #1
    adds r1, #1
    cmp r1, r7
    blo .L080171D2
.L080171E4:
    add r5, sb
    adds r0, r6, #0
    cmp r0, ip
    blo .L080171C6
.L080171EC:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    .size ApplyMapTerrainPatch, . - ApplyMapTerrainPatch

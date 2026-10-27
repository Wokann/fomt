    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    @ Existing native opening lifecycle, shared by all four regions.
    @ C++ matching is pending; do not count this entry as recovered C++.
    thumb_func_start TalkOpen__9GameScene
TalkOpen__9GameScene: @ 0x080124D0
    push {r4, r5, r6, r7, lr}
    sub sp, #0x14
    ldr r7, [r0, #4]
    adds r4, r7, #0
    adds r4, #0xb4
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L080124F2
    cmp r1, #0
    beq .L080124F2
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080124F2:
    str r5, [r4]
    adds r4, r7, #0
    adds r4, #0xb8
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L08012510
    cmp r1, #0
    beq .L08012510
    ldr r0, [r1, #4]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08012510:
    str r5, [r4]
    adds r0, r7, #0
    adds r0, #0xac
    ldr r5, [r0]
    adds r6, r0, #0
    cmp r5, #0
    bne .L080125CA
    adds r0, #0x3c
    ldrb r0, [r0]
    cmp r0, #0
    bne .L0801257A
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    add r0, sp, #0x10
    bl __16HardwareResource
    add r1, sp, #0x10
    movs r0, #1
    str r0, [sp]
    add r0, sp, #0xc
    str r0, [sp, #4]
    str r1, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1f
    movs r3, #0
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    adds r5, r6, #0
    adds r4, r0, #0
    ldr r0, [r6]
    cmp r4, r0
    beq .L08012566
    cmp r0, #0
    beq .L08012566
    movs r1, #3
    bl _._12UiStateOwner
.L08012566:
    str r4, [r5]
    add r0, sp, #0x10
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
    b .L080125CA
.L0801257A:
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    add r0, sp, #0x10
    bl __16HardwareResource
    add r0, sp, #0x10
    str r5, [sp]
    add r1, sp, #0xc
    str r1, [sp, #4]
    str r0, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1f
    movs r3, #0
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    adds r5, r6, #0
    adds r4, r0, #0
    ldr r0, [r6]
    cmp r4, r0
    beq .L080125B8
    cmp r0, #0
    beq .L080125B8
    movs r1, #3
    bl _._12UiStateOwner
.L080125B8:
    str r4, [r5]
    add r0, sp, #0x10
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
.L080125CA:
    ldr r0, [r6]
    bl GetState__C12UiStateOwner
    cmp r0, #3
    beq .L080125E2
    ldr r0, [r6]
    bl func_08050D5C
    adds r1, r7, #0
    adds r1, #0x9c
    movs r0, #0xe
    str r0, [r1]
.L080125E2:
    add sp, #0x14
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

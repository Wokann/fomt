    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text
    .align 2, 0

    @ Complete native time command; C++ matching is still pending.
    thumb_func_start SetGameTime__9GameSceneRC8GameTime
SetGameTime__9GameSceneRC8GameTime:
    push {r4, r5, r6, r7, lr}
    ldr r4, [r0, #4]
    adds r5, r4, #0
    adds r5, #0xa8
    ldr r0, [r5]
    ldr r2, [r0]
    adds r2, #0xbc
    ldr r2, [r2]
    bl _call_via_r2
    adds r0, r4, #0
    adds r0, #0xb4
    ldr r0, [r0]
    cmp r0, #0
    beq .Lset_game_time_done
    adds r6, r0, #0
    movs r7, #0
    ldr r0, [r5]
    ldr r1, [r0]
    adds r1, #0xb0
    ldr r1, [r1]
    bl _call_via_r1
    lsls r0, r0, #0x18
    adds r3, r4, #0
    adds r3, #0x8c
    cmp r0, #0
    bne .Lset_game_time_show_colon
    ldr r0, [r3]
    ldrh r1, [r0, #0x12]
    lsls r1, r1, #0x15
    lsrs r1, r1, #0x1a
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq .Lset_game_time_update_calendar
.Lset_game_time_show_colon:
    movs r7, #1
.Lset_game_time_update_calendar:
    adds r2, r7, #0
    ldr r1, [r3]
    adds r1, #0x10
    adds r0, r6, #0
    adds r0, #8
    bl UpdateMapClockStatusHudCalendar
.Lset_game_time_done:
    adds r0, r4, #0
    bl func_080D7F08
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

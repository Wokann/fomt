#include "ui_graphics_sizes.hh"

    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"
    .include "six/asm/hw/input.s"
    .syntax unified
    .thumb

    @ Native menu formatting and scene loop. These have not
    @ been recovered as matching C++; their real callers live in the menu module.
#if defined(REGION_JP)
    .section .text
    .syntax unified
    .thumb

    thumb_func_start FormatNewGameSaveSlotSummary
FormatNewGameSaveSlotSummary:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #40
    adds	r6, r1, #0
    mov	sl, r2
    movs	r0, #0
    mov	r8, r0
    mov	r1, r8
    strb	r1, [r6, #0]
    movs	r0, #16
    add	r0, sl
    mov	r9, r0
    movs	r3, #200
    str	r3, [sp, #24]
    ldrb	r0, [r2, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #28]
    add	r2, sp, #28
    add	r0, sp, #24
    cmp	r3, r1
    bls.n .Ljp_080037E4
    adds	r0, r2, #0
.Ljp_080037E4:
    ldr	r0, [r0, #0]
    mov	r1, sp
    movs	r2, #0
    bl FormatFullWidthDecimal
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_0800381C
    mov	r0, sp
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_0800380C
    adds	r4, r5, #0
.Ljp_0800380C:
    adds	r0, r7, #0
    mov	r1, sp
    adds	r2, r4, #0
    bl memcpy
    adds	r0, r7, r4
    mov	r1, r8
    strb	r1, [r0, #0]
.Ljp_0800381C:
    ldr	r0, .Ljp_08003B3C
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_0800384E
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_0800383E
    adds	r4, r5, #0
.Ljp_0800383E:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0800384E:
    mov	r1, r9
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    bl GetCalendarSeasonLabel__F6Season
    mov	r8, r0
    mov	r4, r8
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_0800388C
    adds	r0, r4, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_0800387C
    adds	r4, r5, #0
.Ljp_0800387C:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0800388C:
    ldr	r0, .Ljp_08003B40
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_080038BE
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_080038AE
    adds	r4, r5, #0
.Ljp_080038AE:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080038BE:
    mov	r1, r9
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    mov	r1, sp
    movs	r2, #0
    bl FormatFullWidthDecimal
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_080038FE
    mov	r0, sp
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_080038EE
    adds	r4, r5, #0
.Ljp_080038EE:
    adds	r0, r7, #0
    mov	r1, sp
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080038FE:
    ldr	r0, .Ljp_08003B44
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003930
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_08003920
    adds	r4, r5, #0
.Ljp_08003920:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003930:
    ldr	r1, .Ljp_08003B48
    mov	r8, r1
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003962
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_08003952
    adds	r4, r5, #0
.Ljp_08003952:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003962:
    mov	r0, r9
    ldrb	r2, [r0, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r0, #1]
    lsls	r0, r3, #30
    lsrs	r0, r0, #30
    lsls	r3, r3, #25
    lsrs	r3, r3, #27
    adds	r2, #6
    lsls	r1, r0, #4
    subs	r1, r1, r0
    lsls	r1, r1, #1
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r2, r3, r1
    cmp	r2, #6
    bls.n .Ljp_08003994
    adds	r0, r2, #0
    movs	r1, #7
    bl __umodsi3
    adds	r2, r0, #0
.Ljp_08003994:
    movs	r0, #7
    ands	r2, r0
    adds	r0, r2, #0
    bl GetCalendarWeekdayLabel
    mov	r8, r0
    mov	r9, r6
    mov	r4, r8
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_080039D2
    adds	r0, r4, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_080039C2
    adds	r4, r5, #0
.Ljp_080039C2:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080039D2:
    ldr	r1, .Ljp_08003B4C
    mov	r8, r1
    mov	r0, r9
    bl strlen
    mov	r1, r9
    adds	r7, r1, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003A06
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_080039F6
    adds	r4, r5, #0
.Ljp_080039F6:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003A06:
    movs	r1, #13
    add	r0, sp, #32
    strb	r1, [r0, #0]
    adds	r0, r6, #0
    bl strlen
    adds	r3, r0, #1
    cmp	r3, #127
    bhi.n .Ljp_08003A24
    adds	r1, r6, r0
    movs	r2, #0
    movs	r0, #13
    strb	r0, [r1, #0]
    adds	r0, r6, r3
    strb	r2, [r0, #0]
.Ljp_08003A24:
    movs	r1, #10
    mov	r0, sp
    adds	r0, #33
    strb	r1, [r0, #0]
    adds	r0, r6, #0
    bl strlen
    adds	r3, r0, #1
    cmp	r3, #127
    bhi.n .Ljp_08003A44
    adds	r1, r6, r0
    movs	r2, #0
    movs	r0, #10
    strb	r0, [r1, #0]
    adds	r0, r6, r3
    strb	r2, [r0, #0]
.Ljp_08003A44:
    mov	r0, sl
    adds	r0, #20
    bl GetName__C4Farm
    mov	r8, r0
    mov	r4, r8
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003A7E
    adds	r0, r4, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_08003A6E
    adds	r4, r5, #0
.Ljp_08003A6E:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003A7E:
    ldr	r0, .Ljp_08003B50
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003AB0
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_08003AA0
    adds	r4, r5, #0
.Ljp_08003AA0:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003AB0:
    movs	r1, #13
    mov	r0, sp
    adds	r0, #34
    strb	r1, [r0, #0]
    adds	r0, r6, #0
    bl strlen
    adds	r3, r0, #1
    cmp	r3, #127
    bhi.n .Ljp_08003AD0
    adds	r1, r6, r0
    movs	r2, #0
    movs	r0, #13
    strb	r0, [r1, #0]
    adds	r0, r6, r3
    strb	r2, [r0, #0]
.Ljp_08003AD0:
    movs	r1, #10
    mov	r0, sp
    adds	r0, #35
    strb	r1, [r0, #0]
    adds	r0, r6, #0
    bl strlen
    adds	r3, r0, #1
    cmp	r3, #127
    bhi.n .Ljp_08003AF0
    adds	r1, r6, r0
    movs	r2, #0
    movs	r0, #10
    strb	r0, [r1, #0]
    adds	r0, r6, r3
    strb	r2, [r0, #0]
.Ljp_08003AF0:
    ldr	r0, .Ljp_08003B54
    add	r0, sl
    bl GetName__C6Farmer
    adds	r7, r0, #0
    adds	r4, r7, #0
    adds	r0, r6, #0
    bl strlen
    adds	r6, r6, r0
    movs	r1, #127
    subs	r5, r1, r0
    cmp	r5, #0
    beq.n .Ljp_08003B2A
    adds	r0, r4, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls.n .Ljp_08003B1A
    adds	r4, r5, #0
.Ljp_08003B1A:
    adds	r0, r6, #0
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r6, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08003B2A:
    add	sp, #40
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08003B3C: .word gText_NewGameStatus_YearSuffix
.Ljp_08003B40: .word gText_NewGameStatus_SeasonSeparator
.Ljp_08003B44: .word gText_NewGameStatus_DaySuffix
.Ljp_08003B48: .word gText_NewGameStatus_OpenParen
.Ljp_08003B4C: .word gText_NewGameStatus_CloseParen
.Ljp_08003B50: .word gText_NewGameStatus_FarmSuffix
.Ljp_08003B54: .word 0x00001BD8
#else
    .section .text
    thumb_func_start FormatNewGameSaveSlotSummary
FormatNewGameSaveSlotSummary: @ Original US 0x08003788; body remains native.
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    adds r6, r1, #0
    str r2, [sp, #0x24]
    movs r0, #0
    mov sb, r0
    mov r1, sb
    strb r1, [r6]
    ldr r2, [sp, #0x24]
    adds r2, #0x10
    mov sl, r2
    movs r3, #0xc8
    str r3, [sp, #0x18]
    ldr r1, [sp, #0x24]
    ldrb r0, [r1, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #0x1c]
    add r2, sp, #0x1c
    add r0, sp, #0x18
    cmp r3, r1
    bls .L080037C6
    adds r0, r2, #0
.L080037C6:
    ldr r0, [r0]
    mov r1, sp
    movs r2, #0
    bl FormatSignedDecimal
    ldr r2, .L08003B24 @ =gText_NewGameStatus_YearSuffix
    mov r8, r2
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003802
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080037F2
    adds r4, r5, #0
.L080037F2:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r7, r4
    mov r1, sb
    strb r1, [r0]
.L08003802:
    mov r8, r6
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003832
    mov r0, sp
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003822
    adds r4, r5, #0
.L08003822:
    adds r0, r7, #0
    mov r1, sp
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003832:
    ldr r2, .L08003B28 @ =gText_NewGameStatus_SeasonSeparator
    mov sb, r2
    mov r0, r8
    bl strlen
    mov r1, r8
    adds r7, r1, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003866
    mov r0, sb
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003856
    adds r4, r5, #0
.L08003856:
    adds r0, r7, #0
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003866:
    mov r2, sl
    ldrb r0, [r2, #1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    bl GetCalendarSeasonLabel__F6Season
    mov r8, r0
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L080038A4
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003894
    adds r4, r5, #0
.L08003894:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080038A4:
    mov r1, sl
    ldrb r0, [r1, #1]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    mov r1, sp
    movs r2, #0
    bl FormatSignedDecimal
    ldr r2, .L08003B2C @ =gText_NewGameStatus_DaySuffix
    mov r8, r2
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L080038E8
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080038D8
    adds r4, r5, #0
.L080038D8:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080038E8:
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003916
    mov r0, sp
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003906
    adds r4, r5, #0
.L08003906:
    adds r0, r7, #0
    mov r1, sp
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003916:
    ldr r0, .L08003B30 @ =gText_NewGameStatus_OpenParen
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003948
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003938
    adds r4, r5, #0
.L08003938:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003948:
    mov r1, sl
    ldrb r2, [r1]
    lsls r2, r2, #0x1d
    lsrs r2, r2, #0x1d
    ldrb r3, [r1, #1]
    lsls r0, r3, #0x1e
    lsrs r0, r0, #0x1e
    lsls r3, r3, #0x19
    lsrs r3, r3, #0x1b
    adds r2, #6
    lsls r1, r0, #4
    subs r1, r1, r0
    lsls r1, r1, #1
    lsls r0, r2, #4
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r1, r1, r0
    adds r2, r3, r1
    cmp r2, #6
    bls .L0800397A
    adds r0, r2, #0
    movs r1, #7
    bl __umodsi3
    adds r2, r0, #0
.L0800397A:
    movs r0, #7
    ands r2, r0
    adds r0, r2, #0
    bl GetCalendarWeekdayLabel
    mov r8, r0
    mov sb, r6
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L080039B8
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080039A8
    adds r4, r5, #0
.L080039A8:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080039B8:
    ldr r2, .L08003B34 @ =gText_NewGameStatus_CloseParen
    mov r8, r2
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r7, r1, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L080039EC
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080039DC
    adds r4, r5, #0
.L080039DC:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080039EC:
    movs r1, #0xd
    add r0, sp, #0x20
    strb r1, [r0]
    adds r0, r6, #0
    bl strlen
    adds r3, r0, #1
    cmp r3, #0x7f
    bhi .L08003A0A
    adds r1, r6, r0
    movs r2, #0
    movs r0, #0xd
    strb r0, [r1]
    adds r0, r6, r3
    strb r2, [r0]
.L08003A0A:
    movs r1, #0xa
    mov r0, sp
    adds r0, #0x21
    strb r1, [r0]
    adds r0, r6, #0
    bl strlen
    adds r3, r0, #1
    cmp r3, #0x7f
    bhi .L08003A2A
    adds r1, r6, r0
    movs r2, #0
    movs r0, #0xa
    strb r0, [r1]
    adds r0, r6, r3
    strb r2, [r0]
.L08003A2A:
    ldr r0, [sp, #0x24]
    adds r0, #0x14
    bl GetName__C4Farm
    mov r8, r0
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003A64
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003A54
    adds r4, r5, #0
.L08003A54:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003A64:
    ldr r2, .L08003B38 @ =gText_NewGameStatus_FarmSuffix
    mov r8, r2
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003A96
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003A86
    adds r4, r5, #0
.L08003A86:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08003A96:
    movs r1, #0xd
    mov r0, sp
    adds r0, #0x22
    strb r1, [r0]
    adds r0, r6, #0
    bl strlen
    adds r3, r0, #1
    cmp r3, #0x7f
    bhi .L08003AB6
    adds r1, r6, r0
    movs r2, #0
    movs r0, #0xd
    strb r0, [r1]
    adds r0, r6, r3
    strb r2, [r0]
.L08003AB6:
    movs r1, #0xa
    mov r0, sp
    adds r0, #0x23
    strb r1, [r0]
    adds r0, r6, #0
    bl strlen
    adds r3, r0, #1
    cmp r3, #0x7f
    bhi .L08003AD6
    adds r1, r6, r0
    movs r2, #0
    movs r0, #0xa
    strb r0, [r1]
    adds r0, r6, r3
    strb r2, [r0]
.L08003AD6:
    ldr r1, [sp, #0x24]
    ldr r2, .L08003B3C @ =0x00001BD8
    adds r0, r1, r2
    bl GetName__C6Farmer
    adds r7, r0, #0
    adds r4, r7, #0
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    movs r1, #0x7f
    subs r5, r1, r0
    cmp r5, #0
    beq .L08003B12
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08003B02
    adds r4, r5, #0
.L08003B02:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L08003B12:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08003B24: .word gText_NewGameStatus_YearSuffix
.L08003B28: .word gText_NewGameStatus_SeasonSeparator
.L08003B2C: .word gText_NewGameStatus_DaySuffix
.L08003B30: .word gText_NewGameStatus_OpenParen
.L08003B34: .word gText_NewGameStatus_CloseParen
.L08003B38: .word gText_NewGameStatus_FarmSuffix
.L08003B3C: .word 0x00001BD8

#endif

    .section .text.new_game_menu_core_run

    thumb_func_start RunNewGameMenuCore
RunNewGameMenuCore: @ 0x08004570
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    str r0, [sp, #0x58]
    adds r6, r1, #0
    adds r0, r6, #0
    bl EnableHardwareForcedBlank
    adds r0, r6, #0
    bl GetHardwareDisplayState
    adds r5, r0, #0
    add r0, sp, #0xc
    movs r2, #((LCD_OBJ_MAPPING_1D | LCD_BG2_ENABLE | LCD_BG3_ENABLE | LCD_OBJ_ENABLE) >> 5)
    lsls r2, r2, #5
    adds r1, r2, #0
    strh r1, [r0]
    movs r4, #0
    strh r1, [r5]
    ldr r0, .L080046A4 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #(BG_PALETTE >> 19)
    lsls r1, r1, #0x13
    ldr r2, .L080046A8 @ =gUiSharedPaletteByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    add r1, sp, #0xc
    ldr r2, .L080046AC @ =(BG_PRIO_0 | (3 << BF_BG_GFX_BASE_OFFSET) | BG_MOSAIC_ENABLE | (30 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
    adds r0, r2, #0
    strh r0, [r1]
    strh r0, [r5, #0xe]
    ldr r0, .L080046B0 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L080046B4 @ =(MEM_VRAM + 3 * BG_CHAR_SIZE)
    ldr r2, .L080046B8 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L080046BC @ =(MEM_VRAM + 30 * BG_SCREEN_SIZE)
    movs r1, #0x14
    str r1, [sp]
    str r4, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    add r1, sp, #0xc
    movs r2, #((BG_PRIO_0 | BG_MOSAIC_ENABLE | (29 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256) >> 5)
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    strh r0, [r5, #0xc]
    adds r0, r6, #0
    bl RenderNewGameMenuLabelTiles
    adds r4, r6, #0
    adds r4, #0x10
    adds r0, r4, #0
    movs r1, #0x2c
    bl func_08050E98
    adds r0, r4, #0
    bl func_08050D68
    adds r0, r6, #0
    bl UpdateNewGameMenuUi
    ldrh r0, [r5, #8]
    movs r1, #BG_MOSAIC_ENABLE
    orrs r0, r1
    strh r0, [r5, #8]
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    add r0, sp, #0x10
    adds r1, r6, #0
    adds r1, #0x1c
    movs r2, #0
    bl GetGroupData__C22IndexedResourceArchiveUi
    ldr r4, [sp, #0x18]
    adds r0, r6, #0
    adds r0, #0x4c
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r0, .L080046C0 @ =OBJ_VRAM0
    adds r1, r1, r0
    adds r0, r4, #0
#if UI_HAND_CURSOR_TILE_BYTES <= 255
    movs r2, #UI_HAND_CURSOR_TILE_BYTES
#else
    ldr r2, .Lmenu_cursor_tile_bytes
#endif
    bl CopyHardwareDma3
    ldr r4, [sp, #0x20]
    adds r0, r6, #0
    adds r0, #0x54
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r2, .L080046C4 @ =OBJ_PALETTE
    adds r1, r1, r2
    adds r0, r4, #0
    movs r2, #PLTT_SIZE_4BPP
    bl CopyHardwareDma3
    movs r4, #0
.L08004656:
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    adds r1, r4, #0
    bl SubmitNewGameMenuChoiceSprite
    adds r4, #1
    cmp r4, #5
    bls .L08004656
    adds r0, r6, #0
    bl RunNewGameMenuOpeningBlend
    movs r0, #0x8c
    adds r0, r0, r6
    mov sl, r0
.L08004674:
    adds r0, r6, #0
    bl UpdateHardwareFrame
    adds r0, r6, #0
    bl UpdateHardwareInput
    adds r0, r6, #0
    bl UpdateNewGameMenuUi
    adds r0, r6, #0
    bl GetHardwareRepeatedKeys
    adds r7, r0, #0
    mov r5, sl
    ldr r0, [r5]
    cmp r0, #1
    bne .L08004698
    b .L08004A9E
.L08004698:
    cmp r0, #1
    bgt .L080046C8
    cmp r0, #0
    beq .L080046D6
    b .L08004674
    .align 2, 0
.L080046A4: .word gUiSharedPalette
.L080046A8: .word gUiSharedPaletteByteCount
.L080046AC: .word (BG_PRIO_0 | (3 << BF_BG_GFX_BASE_OFFSET) | BG_MOSAIC_ENABLE | (30 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)
.L080046B0: .word gUiSharedTiles
.L080046B4: .word (MEM_VRAM + 3 * BG_CHAR_SIZE)
.L080046B8: .word gUiSharedTileByteCount
.L080046BC: .word (MEM_VRAM + 30 * BG_SCREEN_SIZE)
.L080046C0: .word OBJ_VRAM0
.L080046C4: .word OBJ_PALETTE
#if UI_HAND_CURSOR_TILE_BYTES > 255
.Lmenu_cursor_tile_bytes: .word UI_HAND_CURSOR_TILE_BYTES
#endif
.L080046C8:
    cmp r0, #2
    bne .L080046CE
    b .L08004AC4
.L080046CE:
    cmp r0, #3
    bne .L080046D4
    b .L08004B1A
.L080046D4:
    b .L08004674
.L080046D6:
    adds r4, r6, #0
    adds r4, #0x64
    adds r0, r4, #0
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L0800474A
    ldr r1, [r6, #0x64]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r0, [r6, #0x68]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x30
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    add r1, sp, #0x30
    adds r0, r1, #0
    movs r2, #0x20
    bl memcpy
    ldr r1, [sp, #0x30]
    ldrb r0, [r1]
    adds r5, r6, #0
    adds r5, #0x78
    strb r0, [r5]
    ldrh r1, [r1, #2]
    lsls r1, r1, #0x17
    adds r3, r6, #0
    adds r3, #0x7a
    lsrs r1, r1, #0x17
    ldrh r2, [r3]
    ldr r0, .L0800479C @ =0xFFFFFE00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3]
    adds r4, #0x1c
    ldr r1, [r4]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr r1, [r4]
    ldr r0, [r6, #8]
    adds r2, r6, #0
    adds r2, #0x5c
    cmp r0, #0
    beq .L08004740
    adds r2, r5, #0
.L08004740:
    ldr r3, [r2, #4]
    ldr r2, [r2]
    adds r0, r6, #0
    bl SubmitNewGameMenuCursorSprite
.L0800474A:
    movs r1, #2
    mov sb, r1
    adds r0, r7, #0
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    beq .L080047AE
    ldr r0, [r6, #8]
    cmp r0, #0
    beq .L080047A0
    adds r4, r6, #0
    adds r4, #0x80
    ldr r0, [r4]
    cmp r0, #1
    beq .L0800476C
    b .L08004B36
.L0800476C:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc6
    bl Start__23HardwareMusicPlayerSlotUs
    movs r0, #0
    str r0, [r4]
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #1
    bl SubmitNewGameMenuChoiceSprite
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    movs r1, #0
    bl SubmitNewGameMenuChoiceSprite
    b .L08004674
    .align 2, 0
.L0800479C: .word 0xFFFFFE00
.L080047A0:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc6
    bl Start__23HardwareMusicPlayerSlotUs
    add r4, sp, #0x50
    b .L08004AF2
.L080047AE:
    movs r2, #1
    mov r8, r2
    movs r1, #1
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq .L080048A0
    adds r0, r6, #0
    adds r0, #0x80
    ldr r7, [r0]
    cmp r7, #0
    bne .L080047F2
    str r1, [r0]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    movs r1, #1
    bl SubmitNewGameMenuChoiceSprite
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc5
    bl Start__23HardwareMusicPlayerSlotUs
    b .L08004674
.L080047F2:
    cmp r7, #1
    beq .L080047F8
    b .L08004674
.L080047F8:
    adds r0, r6, #0
    adds r0, #0x85
    ldrb r1, [r0]
    subs r0, #1
    ldrb r4, [r0]
    cmp r4, #0
    beq .L08004864
    lsls r0, r1, #7
    adds r0, r0, r6
    adds r0, #0x98
    movs r1, #0
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08004816
    movs r1, #1
.L08004816:
    cmp r1, r8
    beq .L08004840
    adds r0, r6, #0
    adds r0, #0x10
    ldr r1, .L08004834 @ =gText_NewGameSave_LoadPrompt
    ldr r2, .L08004838
    ldr r3, .L0800483C
    str r5, [sp]
    str r5, [sp, #4]
    str r5, [sp, #8]
    bl func_08050E30
    mov r0, sb
    b .L08004B30
    .align 2, 0
.L08004834: .word gText_NewGameSave_LoadPrompt
#if defined(REGION_JP)
.L08004838: .word gText_NewGameSave_Affirmative
.L0800483C: .word gText_NewGameSave_Negative
#else
.L08004838: .word gText_NewGameMenu_Yes
.L0800483C: .word gText_NewGameMenu_No
#endif
.L08004840:
    adds r0, r6, #0
    adds r0, #0x10
    ldr r1, .L08004860 @ =gText_NewGameStatus_NoSavedData
    movs r2, #0
    movs r3, #0
    bl func_08050DC8
    movs r0, #3
    mov r2, sl
    str r0, [r2]
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc7
    bl Start__23HardwareMusicPlayerSlotUs
    b .L08004674
    .align 2, 0
.L08004860: .word gText_NewGameStatus_NoSavedData
.L08004864:
    lsls r0, r1, #7
    adds r0, r0, r6
    adds r0, #0x98
    movs r1, #0
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08004874
    movs r1, #1
.L08004874:
    cmp r1, r8
    bne .L0800487A
    b .L08004ABC
.L0800487A:
    adds r0, r6, #0
    adds r0, #0x10
    ldr r1, .L08004894 @ =gText_NewGameSave_OverwritePrompt
    ldr r2, .L08004898
    ldr r3, .L0800489C
    str r4, [sp]
    str r4, [sp, #4]
    str r4, [sp, #8]
    bl func_08050E30
    mov r0, sl
    str r7, [r0]
    b .L08004674
    .align 2, 0
.L08004894: .word gText_NewGameSave_OverwritePrompt
#if defined(REGION_JP)
.L08004898: .word gText_NewGameSave_Affirmative
.L0800489C: .word gText_NewGameSave_Negative
#else
.L08004898: .word gText_NewGameMenu_Yes
.L0800489C: .word gText_NewGameMenu_No
#endif
.L080048A0:
    adds r0, r7, #0
    lsls r1, r0, #(31 - KEY_INDEX_RIGHT)
    lsls r0, r0, #(31 - KEY_INDEX_LEFT)
    lsrs r1, r1, #0x1f
    lsrs r0, r0, #0x1f
    cmp r1, r0
    bne .L080048B0
    b .L08004A16
.L080048B0:
    adds r2, r6, #0
    adds r2, #0x80
    adds r1, r6, #0
    adds r1, #0x84
    ldr r0, [r2]
    adds r1, r1, r0
    ldrb r4, [r1]
    mov r0, r8
    eors r4, r0
    strb r4, [r1]
    ldr r0, [r6, #8]
    adds r5, r2, #0
    cmp r0, #0
    beq .L08004980
    ldr r0, [r5]
    cmp r0, #5
    bls .L080048D4
    b .L08004A08
.L080048D4:
    lsls r0, r0, #2
    ldr r1, .L080048E0 @ =.L080048E4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L080048E0: .word .L080048E4
.L080048E4: @ jump table
    .word .L080048FC @ case 0
    .word .L080048FC @ case 1
    .word .L08004904 @ case 2
    .word .L08004924 @ case 3
    .word .L08004940 @ case 4
    .word .L0800495C @ case 5
.L080048FC:
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    b .L08004A08
.L08004904:
    ldr r3, [r6, #8]
    rsbs r1, r4, #0
    orrs r1, r4
    ldr r2, .L08004920 @ =0x00002210
    adds r3, r3, r2
    lsrs r1, r1, #0x1f
    ldrb r2, [r3]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    b .L08004A08
    .align 2, 0
.L08004920: .word 0x00002210
.L08004924:
    ldr r2, [r6, #8]
    movs r3, #1
    cmp r4, #0
    beq .L0800492E
    movs r3, #0
.L0800492E:
    ldr r0, .L0800493C @ =0x00002210
    adds r2, r2, r0
    lsls r3, r3, #1
    ldrb r1, [r2]
    movs r0, #3
    rsbs r0, r0, #0
    b .L08004972
    .align 2, 0
.L0800493C: .word 0x00002210
.L08004940:
    ldr r2, [r6, #8]
    movs r3, #1
    cmp r4, #0
    beq .L0800494A
    movs r3, #0
.L0800494A:
    ldr r1, .L08004958 @ =0x00002210
    adds r2, r2, r1
    lsls r3, r3, #2
    ldrb r1, [r2]
    movs r0, #5
    rsbs r0, r0, #0
    b .L08004972
    .align 2, 0
.L08004958: .word 0x00002210
.L0800495C:
    ldr r2, [r6, #8]
    movs r3, #1
    cmp r4, #0
    beq .L08004966
    movs r3, #0
.L08004966:
    ldr r0, .L0800497C @ =0x00002210
    adds r2, r2, r0
    lsls r3, r3, #3
    ldrb r1, [r2]
    movs r0, #9
    rsbs r0, r0, #0
.L08004972:
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    b .L08004A08
    .align 2, 0
.L0800497C: .word 0x00002210
.L08004980:
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    adds r0, r6, #0
    adds r0, #0x85
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r4, r0, r6
    movs r1, #0xcc
    lsls r1, r1, #1
    adds r4, r4, r1
    movs r1, #0
    ldr r0, [r4]
    lsls r0, r0, #0x1f
    cmp r0, #0
    beq .L080049A2
    movs r1, #1
.L080049A2:
    adds r0, r6, #0
    adds r0, #0x86
    strb r1, [r0]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #2
    bl SubmitNewGameMenuChoiceSprite
    ldrb r0, [r4]
    lsrs r0, r0, #1
    mov r2, r8
    eors r0, r2
    ands r0, r2
    adds r1, r6, #0
    adds r1, #0x87
    strb r0, [r1]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #3
    bl SubmitNewGameMenuChoiceSprite
    ldrb r0, [r4]
    lsrs r0, r0, #2
    mov r1, r8
    eors r0, r1
    ands r0, r1
    adds r1, r6, #0
    adds r1, #0x88
    strb r0, [r1]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #4
    bl SubmitNewGameMenuChoiceSprite
    ldrb r0, [r4]
    lsrs r0, r0, #3
    mov r2, r8
    eors r0, r2
    ands r0, r2
    adds r1, r6, #0
    adds r1, #0x89
    strb r0, [r1]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #5
    bl SubmitNewGameMenuChoiceSprite
.L08004A08:
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    b .L08004A92
.L08004A16:
    ldr r0, [r6, #8]
    cmp r0, #0
    bne .L08004A1E
    b .L08004674
.L08004A1E:
    lsls r1, r7, #(31 - KEY_INDEX_DOWN)
    lsls r0, r7, #(31 - KEY_INDEX_UP)
    lsrs r1, r1, #0x1f
    lsrs r0, r0, #0x1f
    cmp r1, r0
    bne .L08004A2C
    b .L08004674
.L08004A2C:
    adds r1, r6, #0
    adds r1, #0x80
    ldr r4, [r1]
    movs r0, #KEY_DOWN
    ands r0, r7
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r5, r1, #0
    cmp r0, #0
    beq .L08004A52
    cmp r4, #0
    bne .L08004A48
    mov r0, sb
    b .L08004A66
.L08004A48:
    movs r0, #0
    cmp r4, #5
    beq .L08004A66
    adds r0, r4, #1
    b .L08004A66
.L08004A52:
    cmp r4, #2
    beq .L08004A66
    cmp r4, #1
    bne .L08004A5E
    movs r0, #5
    b .L08004A66
.L08004A5E:
    movs r0, #5
    cmp r4, #0
    beq .L08004A66
    subs r0, r4, #1
.L08004A66:
    str r0, [r5]
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    adds r1, r4, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl SubmitNewGameMenuCursorSprite
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
.L08004A92:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xcb
    bl Start__23HardwareMusicPlayerSlotUs
    b .L08004674
.L08004A9E:
    adds r4, r6, #0
    adds r4, #0x10
    adds r0, r4, #0
    bl GetState__C12UiStateOwner
    cmp r0, #3
    beq .L08004AB2
    cmp r0, #6
    bne .L08004AB2
    b .L08004674
.L08004AB2:
    adds r0, r4, #0
    bl GetChoiceResult__C12UiStateOwner
    cmp r0, #1
    bne .L08004B04
.L08004ABC:
    adds r0, r6, #0
    bl TrySaveNewGameMenuSlot
    b .L08004674
.L08004AC4:
    adds r4, r6, #0
    adds r4, #0x10
    adds r0, r4, #0
    bl GetState__C12UiStateOwner
    cmp r0, #3
    beq .L08004AD8
    cmp r0, #6
    bne .L08004AD8
    b .L08004674
.L08004AD8:
    adds r0, r4, #0
    bl GetChoiceResult__C12UiStateOwner
    cmp r0, #1
    bne .L08004B04
    adds r0, r6, #0
    bl TryLoadNewGameMenuSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08004AF0
    b .L08004674
.L08004AF0:
    add r4, sp, #0x54
.L08004AF2:
    adds r0, r4, #0
    movs r1, #0
    bl __23HardwareMusicPlayerSlotUc
    adds r0, r4, #0
    movs r1, #2
    bl FadeOut__23HardwareMusicPlayerSlotUs
    b .L08004B36
.L08004B04:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc5
    bl Start__23HardwareMusicPlayerSlotUs
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    movs r0, #0
    str r0, [r5]
    b .L08004674
.L08004B1A:
    adds r0, r6, #0
    adds r0, #0x10
    bl GetState__C12UiStateOwner
    cmp r0, #5
    bne .L08004B28
    b .L08004674
.L08004B28:
    adds r0, r6, #0
    bl UpdateNewGameMenuStatusText
    movs r0, #0
.L08004B30:
    mov r1, sl
    str r0, [r1]
    b .L08004674
.L08004B36:
    adds r0, r6, #0
    bl RunNewGameMenuClosingBlend
    ldr r1, [r6, #0xc]
    movs r0, #0
    str r0, [r6, #0xc]
    ldr r2, [sp, #0x58]
    str r1, [r2]
    ldr r0, [sp, #0x58]
    add sp, #0x5c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

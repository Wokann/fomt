    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Native menu formatting, label raster and scene loop. These have not
    @ been recovered as matching C++; their real callers live in the menu module.
    .ifdef REGION_JP
    .section .text
    .syntax unified
    .thumb

    .global FormatNewGameSaveSlotSummary
    .thumb_func
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
    bl func_0800E2E4
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
    bl func_0800E304
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
    bl func_0800E4E0
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
.Ljp_08003B3C: .4byte gText_NewGameStatus_YearSuffix
.Ljp_08003B40: .4byte gText_NewGameStatus_SeasonSeparator
.Ljp_08003B44: .4byte gText_NewGameStatus_DaySuffix
.Ljp_08003B48: .4byte gText_NewGameStatus_OpenParen
.Ljp_08003B4C: .4byte gText_NewGameStatus_CloseParen
.Ljp_08003B50: .4byte gText_NewGameStatus_FarmSuffix
.Ljp_08003B54: .4byte 0x00001BD8
    .section .text.new_game_menu_label_tiles

    .global RenderNewGameMenuLabelTiles
    .thumb_func
RenderNewGameMenuLabelTiles:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    ldr	r4, .Ljp_08003DD4
    add	sp, r4
    ldr	r4, .Ljp_08003DD8
    ldr	r1, .Ljp_08003DDC
    movs	r0, #0
    movs	r2, #32
    bl FillHardwareDma3
    movs	r0, #1
    negs	r0, r0
    movs	r2, #128
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl FillHardwareDma3
    movs	r3, #0
    movs	r2, #0
    ldr	r5, .Ljp_08003DE0
    add	r5, sp
    mov	r0, sp
    adds	r0, #8
    ldr	r1, .Ljp_08003DE4
    add	r1, sp
    str	r0, [r1, #0]
    ldr	r0, .Ljp_08003DE8
    add	r0, sp
    ldr	r1, .Ljp_08003DEC
    add	r1, sp
    str	r0, [r1, #0]
    ldr	r0, .Ljp_08003DF0
    add	r0, sp
    ldr	r1, .Ljp_08003DF4
    add	r1, sp
    str	r0, [r1, #0]
    ldr	r0, .Ljp_08003DF8
    add	r0, sp
    ldr	r1, .Ljp_08003DFC
    add	r1, sp
    str	r0, [r1, #0]
    adds	r4, #64
.Ljp_08003CF2:
    movs	r1, #0
    lsls	r0, r2, #6
    adds	r2, #1
    adds	r0, r0, r4
.Ljp_08003CFA:
    strh	r3, [r0, #0]
    adds	r3, #1
    adds	r0, #2
    adds	r1, #1
    cmp	r1, #29
    bls.n .Ljp_08003CFA
    cmp	r2, #11
    bls.n .Ljp_08003CF2
    movs	r1, #30
    movs	r2, #12
    ldr	r0, .Ljp_08003DE0
    add	r0, sp
    strh	r1, [r0, #0]
    strh	r2, [r5, #2]
    ldr	r0, [r0, #0]
    ldr	r2, .Ljp_08003DE4
    add	r2, sp
    ldr	r1, [r2, #0]
    movs	r2, #0
    bl Clear2DGfxBuffer
    movs	r7, #0
    movs	r3, #12
    mov	sl, r3
    ldr	r0, .Ljp_08003DE4
    add	r0, sp
    ldr	r6, [r0, #0]
    movs	r1, #0
    mov	r9, r1
    ldr	r2, .Ljp_08003DE8
    add	r2, sp
    mov	r8, r2
.Ljp_08003D3A:
    ldr	r4, .Ljp_08003E00
    add	r4, r9
    lsls	r5, r7, #4
    ldr	r1, [r4, #0]
    movs	r0, #30
    mov	r3, r8
    strh	r0, [r3, #0]
    mov	r3, sl
    ldr	r2, .Ljp_08003DEC
    add	r2, sp
    ldr	r2, [r2, #0]
    strh	r3, [r2, #2]
    mov	r3, r8
    ldr	r0, [r3, #0]
    str	r1, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #16
    adds	r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    ldr	r1, [r4, #4]
    ldr	r0, .Ljp_08003DF0
    add	r0, sp
    movs	r2, #30
    strh	r2, [r0, #0]
    mov	r2, sl
    ldr	r3, .Ljp_08003DF4
    add	r3, sp
    ldr	r3, [r3, #0]
    strh	r2, [r3, #2]
    ldr	r0, [r0, #0]
    str	r1, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #128
    adds	r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    ldr	r1, [r4, #8]
    ldr	r0, .Ljp_08003DF8
    add	r0, sp
    movs	r2, #30
    strh	r2, [r0, #0]
    mov	r2, sl
    ldr	r3, .Ljp_08003DFC
    add	r3, sp
    ldr	r3, [r3, #0]
    strh	r2, [r3, #2]
    ldr	r0, [r0, #0]
    str	r1, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #192
    adds	r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    movs	r0, #12
    add	r9, r0
    adds	r7, #1
    cmp	r7, #5
    bls.n .Ljp_08003D3A
    movs	r1, #192
    lsls	r1, r1, #19
    movs	r2, #180
    lsls	r2, r2, #6
    ldr	r3, .Ljp_08003DE4
    add	r3, sp
    ldr	r0, [r3, #0]
    bl CopyHardwareDma3
    ldr	r3, .Ljp_08003E04
    add	sp, r3
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08003DD4: .4byte 0xFFFFD2D8
.Ljp_08003DD8: .4byte 0x0600E800
.Ljp_08003DDC: .4byte 0x06007FE0
.Ljp_08003DE0: .4byte 0x00002D08
.Ljp_08003DE4: .4byte 0x00002D24
.Ljp_08003DE8: .4byte 0x00002D0C
.Ljp_08003DEC: .4byte 0x00002D18
.Ljp_08003DF0: .4byte 0x00002D10
.Ljp_08003DF4: .4byte 0x00002D1C
.Ljp_08003DF8: .4byte 0x00002D14
.Ljp_08003DFC: .4byte 0x00002D20
.Ljp_08003E00: .4byte gNewGameMenuLabels
.Ljp_08003E04: .4byte 0x00002D28
    .section .text.new_game_menu_core_run

    .global RunNewGameMenuCore
    .thumb_func
RunNewGameMenuCore:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #92
    str	r0, [sp, #88]
    adds	r6, r1, #0
    adds	r0, r6, #0
    bl func_08008724
    adds	r0, r6, #0
    bl GetHardwareDisplayState
    adds	r5, r0, #0
    add	r0, sp, #12
    movs	r2, #226
    lsls	r2, r2, #5
    adds	r1, r2, #0
    strh	r1, [r0, #0]
    movs	r4, #0
    strh	r1, [r5, #0]
    ldr r0, .Ljp_080046BC
    ldr	r0, [r0, #0]
    movs	r1, #160
    lsls	r1, r1, #19
    ldr r2, .Ljp_080046C0
    ldr	r2, [r2, #0]
    bl CopyHardwareDma3
    add	r1, sp, #12
    ldr r2, .Ljp_080046C4
    adds	r0, r2, #0
    strh	r0, [r1, #0]
    strh	r0, [r5, #14]
    ldr r0, .Ljp_080046C8
    ldr	r0, [r0, #0]
    ldr r1, .Ljp_080046CC
    ldr r2, .Ljp_080046D0
    ldr	r2, [r2, #0]
    bl CopyHardwareDma3
    ldr r0, .Ljp_080046D4
    movs	r1, #20
    str	r1, [sp, #0]
    str	r4, [sp, #4]
    str	r4, [sp, #8]
    movs	r1, #0
    movs	r2, #0
    movs	r3, #30
    bl DrawUiTextWindowBorder
    add	r1, sp, #12
    movs	r2, #234
    lsls	r2, r2, #5
    adds	r0, r2, #0
    strh	r0, [r1, #0]
    strh	r0, [r5, #12]
    adds	r0, r6, #0
    bl RenderNewGameMenuLabelTiles
    adds	r4, r6, #0
    adds	r4, #16
    adds	r0, r4, #0
    movs	r1, #44
    bl func_08050E98
    adds	r0, r4, #0
    bl func_08050D68
    adds	r0, r6, #0
    bl UpdateNewGameMenuUi
    ldrh	r0, [r5, #8]
    movs	r1, #64
    orrs	r0, r1
    strh	r0, [r5, #8]
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    add	r0, sp, #16
    adds	r1, r6, #0
    adds	r1, #28
    movs	r2, #0
    bl GetGroupData__C22IndexedResourceArchiveUi
    ldr	r4, [sp, #24]
    adds	r0, r6, #0
    adds	r0, #76
    ldr	r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    adds	r1, r0, #0
    lsls	r1, r1, #5
    ldr r0, .Ljp_080046D8
    adds	r1, r1, r0
    adds	r0, r4, #0
    movs	r2, #128
    bl CopyHardwareDma3
    ldr	r4, [sp, #32]
    adds	r0, r6, #0
    adds	r0, #84
    ldr	r1, [r0, #4]
    bl func_080074C0
    adds	r1, r0, #0
    lsls	r1, r1, #5
    ldr r2, .Ljp_080046DC
    adds	r1, r1, r2
    adds	r0, r4, #0
    movs	r2, #32
    bl CopyHardwareDma3
    movs	r4, #0
.Ljp_0800466E:
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl SubmitNewGameMenuChoiceSprite
    adds	r4, #1
    cmp	r4, #5
    bls.n .Ljp_0800466E
    adds	r0, r6, #0
    bl RunNewGameMenuOpeningBlend
    movs	r0, #140
    adds	r0, r0, r6
    mov	sl, r0
.Ljp_0800468C:
    adds	r0, r6, #0
    bl UpdateHardwareFrame
    adds	r0, r6, #0
    bl UpdateHardwareInput
    adds	r0, r6, #0
    bl UpdateNewGameMenuUi
    adds	r0, r6, #0
    bl GetHardwareRepeatedKeys
    adds	r7, r0, #0
    mov	r5, sl
    ldr	r0, [r5, #0]
    cmp	r0, #1
    bne.n .Ljp_080046B0
    b.n .Ljp_08004AB6
.Ljp_080046B0:
    cmp	r0, #1
    bgt.n .Ljp_080046E0
    cmp	r0, #0
    beq.n .Ljp_080046EE
    b.n .Ljp_0800468C
    .align 2, 0
.Ljp_080046BC: .4byte gUiSharedPalette
.Ljp_080046C0: .4byte gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue
.Ljp_080046C4: .4byte 0x00001E4C
.Ljp_080046C8: .4byte gUiSharedTiles
.Ljp_080046CC: .4byte 0x0600C000
.Ljp_080046D0: .4byte gUiSharedTileByteCount
.Ljp_080046D4: .4byte 0x0600F000
.Ljp_080046D8: .4byte 0x06010000
.Ljp_080046DC: .4byte 0x05000200
.Ljp_080046E0:
    cmp	r0, #2
    bne.n .Ljp_080046E6
    b.n .Ljp_08004ADC
.Ljp_080046E6:
    cmp	r0, #3
    bne.n .Ljp_080046EC
    b.n .Ljp_08004B32
.Ljp_080046EC:
    b.n .Ljp_0800468C
.Ljp_080046EE:
    adds	r4, r6, #0
    adds	r4, #100
    adds	r0, r4, #0
    bl UpdateIndexedResourceHandle
    lsls	r0, r0, #30
    cmp	r0, #0
    bge.n .Ljp_08004762
    ldr	r1, [r6, #100]
    ldr	r3, [r1, #0]
    ldrh	r2, [r4, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #104]
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #48
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r1, sp, #48
    adds	r0, r1, #0
    movs	r2, #32
    bl memcpy
    ldr	r1, [sp, #48]
    ldrb	r0, [r1, #0]
    adds	r5, r6, #0
    adds	r5, #120
    strb	r0, [r5, #0]
    ldrh	r1, [r1, #2]
    lsls	r1, r1, #23
    adds	r3, r6, #0
    adds	r3, #122
    lsrs	r1, r1, #23
    ldrh	r2, [r3, #0]
    ldr r0, .Ljp_080047B4
    ands	r0, r2
    orrs	r0, r1
    strh	r0, [r3, #0]
    adds	r4, #28
    ldr	r1, [r4, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr	r1, [r4, #0]
    ldr	r0, [r6, #8]
    adds	r2, r6, #0
    adds	r2, #92
    cmp	r0, #0
    beq.n .Ljp_08004758
    adds	r2, r5, #0
.Ljp_08004758:
    ldr	r3, [r2, #4]
    ldr	r2, [r2, #0]
    adds	r0, r6, #0
    bl SubmitNewGameMenuCursorSprite
.Ljp_08004762:
    movs	r1, #2
    mov	r9, r1
    adds	r0, r7, #0
    ands	r0, r1
    lsls	r0, r0, #24
    lsrs	r5, r0, #24
    cmp	r5, #0
    beq.n .Ljp_080047C6
    ldr	r0, [r6, #8]
    cmp	r0, #0
    beq.n .Ljp_080047B8
    adds	r4, r6, #0
    adds	r4, #128
    ldr	r0, [r4, #0]
    cmp	r0, #1
    beq.n .Ljp_08004784
    b.n .Ljp_08004B4E
.Ljp_08004784:
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #198
    bl func_08008B6C
    movs	r0, #0
    str	r0, [r4, #0]
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #1
    bl SubmitNewGameMenuChoiceSprite
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    movs	r1, #0
    bl SubmitNewGameMenuChoiceSprite
    b.n .Ljp_0800468C
    .align 2, 0
.Ljp_080047B4: .4byte 0xFFFFFE00
.Ljp_080047B8:
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #198
    bl func_08008B6C
    add	r4, sp, #80
    b.n .Ljp_08004B0A
.Ljp_080047C6:
    movs	r2, #1
    mov	r8, r2
    movs	r1, #1
    adds	r0, r7, #0
    ands	r0, r1
    cmp	r0, #0
    beq.n .Ljp_080048B8
    adds	r0, r6, #0
    adds	r0, #128
    ldr	r7, [r0, #0]
    cmp	r7, #0
    bne.n .Ljp_0800480A
    str	r1, [r0, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    movs	r1, #1
    bl SubmitNewGameMenuChoiceSprite
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #197
    bl func_08008B6C
    b.n .Ljp_0800468C
.Ljp_0800480A:
    cmp	r7, #1
    beq.n .Ljp_08004810
    b.n .Ljp_0800468C
.Ljp_08004810:
    adds	r0, r6, #0
    adds	r0, #133
    ldrb	r1, [r0, #0]
    subs	r0, #1
    ldrb	r4, [r0, #0]
    cmp	r4, #0
    beq.n .Ljp_0800487C
    lsls	r0, r1, #7
    adds	r0, r0, r6
    adds	r0, #152
    movs	r1, #0
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne.n .Ljp_0800482E
    movs	r1, #1
.Ljp_0800482E:
    cmp	r1, r8
    beq.n .Ljp_08004858
    adds	r0, r6, #0
    adds	r0, #16
    ldr r1, .Ljp_0800484C
    ldr r2, .Ljp_08004850
    ldr r3, .Ljp_08004854
    str	r5, [sp, #0]
    str	r5, [sp, #4]
    str	r5, [sp, #8]
    bl func_08050E30
    mov	r0, r9
    b.n .Ljp_08004B48
    .align 2, 0
.Ljp_0800484C: .4byte gText_NewGameSave_LoadPrompt
.Ljp_08004850: .4byte gText_NewGameSave_Affirmative
.Ljp_08004854: .4byte gText_NewGameSave_Negative
.Ljp_08004858:
    adds	r0, r6, #0
    adds	r0, #16
    ldr r1, .Ljp_08004878
    movs	r2, #0
    movs	r3, #0
    bl func_08050DC8
    movs	r0, #3
    mov	r2, sl
    str	r0, [r2, #0]
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #199
    bl func_08008B6C
    b.n .Ljp_0800468C
    .align 2, 0
.Ljp_08004878: .4byte gText_NewGameStatus_NoSavedData
.Ljp_0800487C:
    lsls	r0, r1, #7
    adds	r0, r0, r6
    adds	r0, #152
    movs	r1, #0
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne.n .Ljp_0800488C
    movs	r1, #1
.Ljp_0800488C:
    cmp	r1, r8
    bne.n .Ljp_08004892
    b.n .Ljp_08004AD4
.Ljp_08004892:
    adds	r0, r6, #0
    adds	r0, #16
    ldr r1, .Ljp_080048AC
    ldr r2, .Ljp_080048B0
    ldr r3, .Ljp_080048B4
    str	r4, [sp, #0]
    str	r4, [sp, #4]
    str	r4, [sp, #8]
    bl func_08050E30
    mov	r0, sl
    str	r7, [r0, #0]
    b.n .Ljp_0800468C
    .align 2, 0
.Ljp_080048AC: .4byte gText_NewGameSave_OverwritePrompt
.Ljp_080048B0: .4byte gText_NewGameSave_Affirmative
.Ljp_080048B4: .4byte gText_NewGameSave_Negative
.Ljp_080048B8:
    adds	r0, r7, #0
    lsls	r1, r0, #27
    lsls	r0, r0, #26
    lsrs	r1, r1, #31
    lsrs	r0, r0, #31
    cmp	r1, r0
    bne.n .Ljp_080048C8
    b.n .Ljp_08004A2E
.Ljp_080048C8:
    adds	r2, r6, #0
    adds	r2, #128
    adds	r1, r6, #0
    adds	r1, #132
    ldr	r0, [r2, #0]
    adds	r1, r1, r0
    ldrb	r4, [r1, #0]
    mov	r0, r8
    eors	r4, r0
    strb	r4, [r1, #0]
    ldr	r0, [r6, #8]
    adds	r5, r2, #0
    cmp	r0, #0
    beq.n .Ljp_08004998
    ldr	r0, [r5, #0]
    cmp	r0, #5
    bls.n .Ljp_080048EC
    b.n .Ljp_08004A20
.Ljp_080048EC:
    lsls	r0, r0, #2
    ldr r1, .Ljp_080048F8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_080048F8: .4byte .Ljp_080048FC
.Ljp_080048FC:
    .4byte .Ljp_08004914
    .4byte .Ljp_08004914
    .4byte .Ljp_0800491C
    .4byte .Ljp_0800493C
    .4byte .Ljp_08004958
    .4byte .Ljp_08004974
.Ljp_08004914:
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    b.n .Ljp_08004A20
.Ljp_0800491C:
    ldr	r3, [r6, #8]
    negs	r1, r4
    orrs	r1, r4
    ldr r2, .Ljp_08004938
    adds	r3, r3, r2
    lsrs	r1, r1, #31
    ldrb	r2, [r3, #0]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r2
    orrs	r0, r1
    strb	r0, [r3, #0]
    b.n .Ljp_08004A20
    .align 2, 0
.Ljp_08004938: .4byte 0x00002210
.Ljp_0800493C:
    ldr	r2, [r6, #8]
    movs	r3, #1
    cmp	r4, #0
    beq.n .Ljp_08004946
    movs	r3, #0
.Ljp_08004946:
    ldr r0, .Ljp_08004954
    adds	r2, r2, r0
    lsls	r3, r3, #1
    ldrb	r1, [r2, #0]
    movs	r0, #3
    negs	r0, r0
    b.n .Ljp_0800498A
    .align 2, 0
.Ljp_08004954: .4byte 0x00002210
.Ljp_08004958:
    ldr	r2, [r6, #8]
    movs	r3, #1
    cmp	r4, #0
    beq.n .Ljp_08004962
    movs	r3, #0
.Ljp_08004962:
    ldr r1, .Ljp_08004970
    adds	r2, r2, r1
    lsls	r3, r3, #2
    ldrb	r1, [r2, #0]
    movs	r0, #5
    negs	r0, r0
    b.n .Ljp_0800498A
    .align 2, 0
.Ljp_08004970: .4byte 0x00002210
.Ljp_08004974:
    ldr	r2, [r6, #8]
    movs	r3, #1
    cmp	r4, #0
    beq.n .Ljp_0800497E
    movs	r3, #0
.Ljp_0800497E:
    ldr r0, .Ljp_08004994
    adds	r2, r2, r0
    lsls	r3, r3, #3
    ldrb	r1, [r2, #0]
    movs	r0, #9
    negs	r0, r0
.Ljp_0800498A:
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #0]
    b.n .Ljp_08004A20
    .align 2, 0
.Ljp_08004994: .4byte 0x00002210
.Ljp_08004998:
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    adds	r0, r6, #0
    adds	r0, #133
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #2
    adds	r4, r0, r6
    movs	r1, #204
    lsls	r1, r1, #1
    adds	r4, r4, r1
    movs	r1, #0
    ldr	r0, [r4, #0]
    lsls	r0, r0, #31
    cmp	r0, #0
    beq.n .Ljp_080049BA
    movs	r1, #1
.Ljp_080049BA:
    adds	r0, r6, #0
    adds	r0, #134
    strb	r1, [r0, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #2
    bl SubmitNewGameMenuChoiceSprite
    ldrb	r0, [r4, #0]
    lsrs	r0, r0, #1
    mov	r2, r8
    eors	r0, r2
    ands	r0, r2
    adds	r1, r6, #0
    adds	r1, #135
    strb	r0, [r1, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #3
    bl SubmitNewGameMenuChoiceSprite
    ldrb	r0, [r4, #0]
    lsrs	r0, r0, #2
    mov	r1, r8
    eors	r0, r1
    ands	r0, r1
    adds	r1, r6, #0
    adds	r1, #136
    strb	r0, [r1, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #4
    bl SubmitNewGameMenuChoiceSprite
    ldrb	r0, [r4, #0]
    lsrs	r0, r0, #3
    mov	r2, r8
    eors	r0, r2
    ands	r0, r2
    adds	r1, r6, #0
    adds	r1, #137
    strb	r0, [r1, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #5
    bl SubmitNewGameMenuChoiceSprite
.Ljp_08004A20:
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    b.n .Ljp_08004AAA
.Ljp_08004A2E:
    ldr	r0, [r6, #8]
    cmp	r0, #0
    bne.n .Ljp_08004A36
    b.n .Ljp_0800468C
.Ljp_08004A36:
    lsls	r1, r7, #24
    lsls	r0, r7, #25
    lsrs	r1, r1, #31
    lsrs	r0, r0, #31
    cmp	r1, r0
    bne.n .Ljp_08004A44
    b.n .Ljp_0800468C
.Ljp_08004A44:
    adds	r1, r6, #0
    adds	r1, #128
    ldr	r4, [r1, #0]
    movs	r0, #128
    ands	r0, r7
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    adds	r5, r1, #0
    cmp	r0, #0
    beq.n .Ljp_08004A6A
    cmp	r4, #0
    bne.n .Ljp_08004A60
    mov	r0, r9
    b.n .Ljp_08004A7E
.Ljp_08004A60:
    movs	r0, #0
    cmp	r4, #5
    beq.n .Ljp_08004A7E
    adds	r0, r4, #1
    b.n .Ljp_08004A7E
.Ljp_08004A6A:
    cmp	r4, #2
    beq.n .Ljp_08004A7E
    cmp	r4, #1
    bne.n .Ljp_08004A76
    movs	r0, #5
    b.n .Ljp_08004A7E
.Ljp_08004A76:
    movs	r0, #5
    cmp	r4, #0
    beq.n .Ljp_08004A7E
    subs	r0, r4, #1
.Ljp_08004A7E:
    str	r0, [r5, #0]
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl SubmitNewGameMenuChoiceSprite
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl SubmitNewGameMenuCursorSprite
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
.Ljp_08004AAA:
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #203
    bl func_08008B6C
    b.n .Ljp_0800468C
.Ljp_08004AB6:
    adds	r4, r6, #0
    adds	r4, #16
    adds	r0, r4, #0
    bl GetState__C12UiStateOwner
    cmp	r0, #3
    beq.n .Ljp_08004ACA
    cmp	r0, #6
    bne.n .Ljp_08004ACA
    b.n .Ljp_0800468C
.Ljp_08004ACA:
    adds	r0, r4, #0
    bl func_08050DF0
    cmp	r0, #1
    bne.n .Ljp_08004B1C
.Ljp_08004AD4:
    adds	r0, r6, #0
    bl TrySaveNewGameMenuSlot
    b.n .Ljp_0800468C
.Ljp_08004ADC:
    adds	r4, r6, #0
    adds	r4, #16
    adds	r0, r4, #0
    bl GetState__C12UiStateOwner
    cmp	r0, #3
    beq.n .Ljp_08004AF0
    cmp	r0, #6
    bne.n .Ljp_08004AF0
    b.n .Ljp_0800468C
.Ljp_08004AF0:
    adds	r0, r4, #0
    bl func_08050DF0
    cmp	r0, #1
    bne.n .Ljp_08004B1C
    adds	r0, r6, #0
    bl TryLoadNewGameMenuSlot
    lsls	r0, r0, #24
    cmp	r0, #0
    bne.n .Ljp_08004B08
    b.n .Ljp_0800468C
.Ljp_08004B08:
    add	r4, sp, #84
.Ljp_08004B0A:
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08008B54
    adds	r0, r4, #0
    movs	r1, #2
    bl func_08008BF8
    b.n .Ljp_08004B4E
.Ljp_08004B1C:
    adds	r0, r6, #0
    adds	r0, #24
    movs	r1, #197
    bl func_08008B6C
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    movs	r0, #0
    str	r0, [r5, #0]
    b.n .Ljp_0800468C
.Ljp_08004B32:
    adds	r0, r6, #0
    adds	r0, #16
    bl GetState__C12UiStateOwner
    cmp	r0, #5
    bne.n .Ljp_08004B40
    b.n .Ljp_0800468C
.Ljp_08004B40:
    adds	r0, r6, #0
    bl UpdateNewGameMenuStatusText
    movs	r0, #0
.Ljp_08004B48:
    mov	r1, sl
    str	r0, [r1, #0]
    b.n .Ljp_0800468C
.Ljp_08004B4E:
    adds	r0, r6, #0
    bl RunNewGameMenuClosingBlend
    ldr	r1, [r6, #12]
    movs	r0, #0
    str	r0, [r6, #12]
    ldr	r2, [sp, #88]
    str	r1, [r2, #0]
    ldr	r0, [sp, #88]
    add	sp, #92
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .else
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
    bl func_0800E2E4
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
    bl func_0800E304
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
    bl func_0800E4E0
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
.L08003B24: .4byte gText_NewGameStatus_YearSuffix
.L08003B28: .4byte gText_NewGameStatus_SeasonSeparator
.L08003B2C: .4byte gText_NewGameStatus_DaySuffix
.L08003B30: .4byte gText_NewGameStatus_OpenParen
.L08003B34: .4byte gText_NewGameStatus_CloseParen
.L08003B38: .4byte gText_NewGameStatus_FarmSuffix
.L08003B3C: .4byte 0x00001BD8

    .section .text.new_game_menu_label_tiles

    thumb_func_start RenderNewGameMenuLabelTiles
RenderNewGameMenuLabelTiles: @ 0x08003C80
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L08003DBC @ =0xFFFFD2D8
    add sp, r4
    ldr r4, .L08003DC0 @ =0x0600E800
    ldr r1, .L08003DC4 @ =0x06007FE0
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r0, #1
    rsbs r0, r0, #0
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl FillHardwareDma3
    movs r3, #0
    movs r2, #0
    ldr r5, .L08003DC8 @ =0x00002D08
    add r5, sp
    mov r0, sp
    adds r0, #8
    ldr r1, .L08003DCC @ =0x00002D24
    add r1, sp
    str r0, [r1]
    ldr r0, .L08003DD0 @ =0x00002D0C
    add r0, sp
    ldr r1, .L08003DD4 @ =0x00002D18
    add r1, sp
    str r0, [r1]
    ldr r0, .L08003DD8 @ =0x00002D10
    add r0, sp
    ldr r1, .L08003DDC @ =0x00002D1C
    add r1, sp
    str r0, [r1]
    ldr r0, .L08003DE0 @ =0x00002D14
    add r0, sp
    ldr r1, .L08003DE4 @ =0x00002D20
    add r1, sp
    str r0, [r1]
    adds r4, #0x40
.L08003CDA:
    movs r1, #0
    lsls r0, r2, #6
    adds r2, #1
    adds r0, r0, r4
.L08003CE2:
    strh r3, [r0]
    adds r3, #1
    adds r0, #2
    adds r1, #1
    cmp r1, #0x1d
    bls .L08003CE2
    cmp r2, #0xb
    bls .L08003CDA
    movs r1, #0x1e
    movs r2, #0xc
    ldr r0, .L08003DC8 @ =0x00002D08
    add r0, sp
    strh r1, [r0]
    strh r2, [r5, #2]
    ldr r0, [r0]
    ldr r2, .L08003DCC @ =0x00002D24
    add r2, sp
    ldr r1, [r2]
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r7, #0
    movs r3, #0xc
    mov sl, r3
    ldr r0, .L08003DCC @ =0x00002D24
    add r0, sp
    ldr r6, [r0]
    movs r1, #0
    mov sb, r1
    ldr r2, .L08003DD0 @ =0x00002D0C
    add r2, sp
    mov r8, r2
.L08003D22:
    ldr r4, .L08003DE8 @ =gNewGameMenuLabels
    add r4, sb
    lsls r5, r7, #4
    ldr r1, [r4]
    movs r0, #0x1e
    mov r3, r8
    strh r0, [r3]
    mov r3, sl
    ldr r2, .L08003DD4 @ =0x00002D18
    add r2, sp
    ldr r2, [r2]
    strh r3, [r2, #2]
    mov r3, r8
    ldr r0, [r3]
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #0x10
    adds r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, [r4, #4]
    ldr r0, .L08003DD8 @ =0x00002D10
    add r0, sp
    movs r2, #0x1e
    strh r2, [r0]
    mov r2, sl
    ldr r3, .L08003DDC @ =0x00002D1C
    add r3, sp
    ldr r3, [r3]
    strh r2, [r3, #2]
    ldr r0, [r0]
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #0x80
    adds r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, [r4, #8]
    ldr r0, .L08003DE0 @ =0x00002D14
    add r0, sp
    movs r2, #0x1e
    strh r2, [r0]
    mov r2, sl
    ldr r3, .L08003DE4 @ =0x00002D20
    add r3, sp
    ldr r3, [r3]
    strh r2, [r3, #2]
    ldr r0, [r0]
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #0xc0
    adds r3, r5, #0
    bl DrawStringTo2DGfxBuffer
    movs r0, #0xc
    add sb, r0
    adds r7, #1
    cmp r7, #5
    bls .L08003D22
    movs r1, #0xc0
    lsls r1, r1, #0x13
    movs r2, #0xb4
    lsls r2, r2, #6
    ldr r3, .L08003DCC @ =0x00002D24
    add r3, sp
    ldr r0, [r3]
    bl CopyHardwareDma3
    ldr r3, .L08003DEC @ =0x00002D28
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08003DBC: .4byte 0xFFFFD2D8
.L08003DC0: .4byte 0x0600E800
.L08003DC4: .4byte 0x06007FE0
.L08003DC8: .4byte 0x00002D08
.L08003DCC: .4byte 0x00002D24
.L08003DD0: .4byte 0x00002D0C
.L08003DD4: .4byte 0x00002D18
.L08003DD8: .4byte 0x00002D10
.L08003DDC: .4byte 0x00002D1C
.L08003DE0: .4byte 0x00002D14
.L08003DE4: .4byte 0x00002D20
.L08003DE8: .4byte gNewGameMenuLabels
.L08003DEC: .4byte 0x00002D28

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
    bl func_08008724
    adds r0, r6, #0
    bl GetHardwareDisplayState
    adds r5, r0, #0
    add r0, sp, #0xc
    movs r2, #0xe2
    lsls r2, r2, #5
    adds r1, r2, #0
    strh r1, [r0]
    movs r4, #0
    strh r1, [r5]
    ldr r0, .L080046A4 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, .L080046A8 @ =gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue
    ldr r2, [r2]
    bl CopyHardwareDma3
    add r1, sp, #0xc
    ldr r2, .L080046AC @ =0x00001E4C
    adds r0, r2, #0
    strh r0, [r1]
    strh r0, [r5, #0xe]
    ldr r0, .L080046B0 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L080046B4 @ =0x0600C000
    ldr r2, .L080046B8 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl CopyHardwareDma3
    ldr r0, .L080046BC @ =0x0600F000
    movs r1, #0x14
    str r1, [sp]
    str r4, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    add r1, sp, #0xc
    movs r2, #0xea
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
    movs r1, #0x40
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
    bl GetHardwareSharedStateTileIndex
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r0, .L080046C0 @ =0x06010000
    adds r1, r1, r0
    adds r0, r4, #0
    movs r2, #0x80
    bl CopyHardwareDma3
    ldr r4, [sp, #0x20]
    adds r0, r6, #0
    adds r0, #0x54
    ldr r1, [r0, #4]
    bl func_080074C0
    adds r1, r0, #0
    lsls r1, r1, #5
    ldr r2, .L080046C4 @ =0x05000200
    adds r1, r1, r2
    adds r0, r4, #0
    movs r2, #0x20
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
.L080046A4: .4byte gUiSharedPalette
.L080046A8: .4byte gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue
.L080046AC: .4byte 0x00001E4C
.L080046B0: .4byte gUiSharedTiles
.L080046B4: .4byte 0x0600C000
.L080046B8: .4byte gUiSharedTileByteCount
.L080046BC: .4byte 0x0600F000
.L080046C0: .4byte 0x06010000
.L080046C4: .4byte 0x05000200
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
    bl func_08008B6C
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
.L0800479C: .4byte 0xFFFFFE00
.L080047A0:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc6
    bl func_08008B6C
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
    bl func_08008B6C
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
    ldr r2, .L08004838 @ =gText_NewGameMenu_Yes
    ldr r3, .L0800483C @ =gText_NewGameMenu_No
    str r5, [sp]
    str r5, [sp, #4]
    str r5, [sp, #8]
    bl func_08050E30
    mov r0, sb
    b .L08004B30
    .align 2, 0
.L08004834: .4byte gText_NewGameSave_LoadPrompt
.L08004838: .4byte gText_NewGameMenu_Yes
.L0800483C: .4byte gText_NewGameMenu_No
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
    bl func_08008B6C
    b .L08004674
    .align 2, 0
.L08004860: .4byte gText_NewGameStatus_NoSavedData
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
    ldr r2, .L08004898 @ =gText_NewGameMenu_Yes
    ldr r3, .L0800489C @ =gText_NewGameMenu_No
    str r4, [sp]
    str r4, [sp, #4]
    str r4, [sp, #8]
    bl func_08050E30
    mov r0, sl
    str r7, [r0]
    b .L08004674
    .align 2, 0
.L08004894: .4byte gText_NewGameSave_OverwritePrompt
.L08004898: .4byte gText_NewGameMenu_Yes
.L0800489C: .4byte gText_NewGameMenu_No
.L080048A0:
    adds r0, r7, #0
    lsls r1, r0, #0x1b
    lsls r0, r0, #0x1a
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
.L080048E0: .4byte .L080048E4
.L080048E4: @ jump table
    .4byte .L080048FC @ case 0
    .4byte .L080048FC @ case 1
    .4byte .L08004904 @ case 2
    .4byte .L08004924 @ case 3
    .4byte .L08004940 @ case 4
    .4byte .L0800495C @ case 5
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
.L08004920: .4byte 0x00002210
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
.L0800493C: .4byte 0x00002210
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
.L08004958: .4byte 0x00002210
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
.L0800497C: .4byte 0x00002210
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
    lsls r1, r7, #0x18
    lsls r0, r7, #0x19
    lsrs r1, r1, #0x1f
    lsrs r0, r0, #0x1f
    cmp r1, r0
    bne .L08004A2C
    b .L08004674
.L08004A2C:
    adds r1, r6, #0
    adds r1, #0x80
    ldr r4, [r1]
    movs r0, #0x80
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
    bl func_08008B6C
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
    bl func_08050DF0
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
    bl func_08050DF0
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
    bl func_08008B54
    adds r0, r4, #0
    movs r1, #2
    bl func_08008BF8
    b .L08004B36
.L08004B04:
    adds r0, r6, #0
    adds r0, #0x18
    movs r1, #0xc5
    bl func_08008B6C
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

    .endif

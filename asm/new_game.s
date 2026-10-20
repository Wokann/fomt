    @ The keyboard renderer counts rows from one.  Its literal therefore
    @ intentionally precedes the first 31-byte row by one row width.
    .equ NEW_GAME_NAME_ENTRY_ROW_WIDTH, 31

    .ifdef REGION_JP
    @ JP revision 0 counterpart of asm/new_game.s.
    @
    @ The surrounding object is 0x10 bytes shorter than US.  These are static
    @ ROM ranges at verified JP function boundaries; they are deliberately not
    @ generated during the build.  Public labels are retained where another
    @ source object calls into this still-unmatched module.

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
    .section .text.new_game_after_fades

    .global func_08003C80
    .thumb_func
func_08003C80:
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
    bl func_08008EB8
    movs	r0, #1
    negs	r0, r0
    movs	r2, #128
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl func_08008EB8
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
    bl func_08008E64
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
    .section .text.new_game_after_status_update

    .global func_08004570
    .thumb_func
func_08004570:
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
    bl func_08008918
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
    bl func_08008E64
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
    bl func_08008E64
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
    bl func_08003C80
    adds	r4, r6, #0
    adds	r4, #16
    adds	r0, r4, #0
    movs	r1, #44
    bl func_08050E98
    adds	r0, r4, #0
    bl func_08050D68
    adds	r0, r6, #0
    bl func_08003C28
    ldrh	r0, [r5, #8]
    movs	r1, #64
    orrs	r0, r1
    strh	r0, [r5, #8]
    adds	r0, r6, #0
    bl func_08003EEC
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
    bl func_08008E64
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
    bl func_08008E64
    movs	r4, #0
.Ljp_0800466E:
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08003DF0
    adds	r4, #1
    cmp	r4, #5
    bls.n .Ljp_0800466E
    adds	r0, r6, #0
    bl func_08003B40
    movs	r0, #140
    adds	r0, r0, r6
    mov	sl, r0
.Ljp_0800468C:
    adds	r0, r6, #0
    bl UpdateHardwareFrame
    adds	r0, r6, #0
    bl func_080088B8
    adds	r0, r6, #0
    bl func_08003C28
    adds	r0, r6, #0
    bl func_080088D4
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
    bl func_08003DF0
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
    bl func_08003E88
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
    bl func_08003EEC
    ldr	r2, [r6, #92]
    ldr	r3, [r6, #96]
    adds	r0, r6, #0
    movs	r1, #1
    bl func_08003DF0
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    movs	r1, #0
    bl func_08003DF0
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
    bl func_08003DF0
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    movs	r1, #1
    bl func_08003DF0
    adds	r0, r6, #0
    bl func_08003EEC
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
    bl func_08003EEC
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
    bl func_08003EEC
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
    bl func_08003DF0
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
    bl func_08003DF0
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
    bl func_08003DF0
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
    bl func_08003DF0
.Ljp_08004A20:
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl func_08003DF0
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
    bl func_08003DF0
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl func_08003DF0
    ldr	r1, [r5, #0]
    ldr	r2, [r6, #120]
    ldr	r3, [r6, #124]
    adds	r0, r6, #0
    bl func_08003E88
    adds	r0, r6, #0
    bl func_08003EEC
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
    bl func_08003F9C
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
    bl func_080040A0
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
    bl func_08003EEC
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
    bl func_08003EEC
    movs	r0, #0
.Ljp_08004B48:
    mov	r1, sl
    str	r0, [r1, #0]
    b.n .Ljp_0800468C
.Ljp_08004B4E:
    adds	r0, r6, #0
    bl func_08003BB4
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
    .section .text.new_game_after_scene_lifecycle

    .global InitializeNewGameIdentityCore
    .thumb_func
InitializeNewGameIdentityCore:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov r8, r0
    adds r6, r1, #0
    adds r7, r2, #0
    str r3, [sp, #0x24]
    bl func_08008444
    ldr r0, .Ljp_0800510C
    mov r1, r8
    str r0, [r1, #4]
    movs r0, #7
    add r5, sp, #0x10
    add r1, sp, #0x14
    mov sb, r1
    movs r1, #1
    rsbs r1, r1, #0
.Ljp_08004F3E:
    subs r0, #1
    cmp r0, r1
    bne .Ljp_08004F3E
    ldr r1, .Ljp_08005110
    add r1, r8
    movs r0, #2
    str r0, [r1]
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    adds r0, r5, #0
    bl __16HardwareResource
    movs r0, #0
    str r0, [sp]
    add r0, sp, #0xc
    str r0, [sp, #4]
    str r5, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1c
    movs r3, #4
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    ldr r1, .Ljp_08005114
    add r1, r8
    str r0, [r1]
    adds r0, r5, #0
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
    ldr r4, .Ljp_08005118
    add r4, r8
    movs r0, #0xc8
    bl func_08008D3C
    str r0, [r4]
    ldr r0, .Ljp_0800511C
    add r0, r8
    movs r1, #3
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.Ljp_08004FA4:
    strb r3, [r0]
    adds r0, #0x10
    subs r1, #1
    cmp r1, r2
    bne .Ljp_08004FA4
    ldr r0, .Ljp_08005120
    add r0, r8
    movs r1, #0
    mov sl, r1
    mov r1, sl
    strb r1, [r0]
    ldr r5, .Ljp_0800511C
    add r5, r8
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_08004FCC
    movs r4, #0xf
.Ljp_08004FCC:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    mov r1, sl
    strb r1, [r0]
    lsls r0, r7, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    mov r1, sb
    movs r2, #2
    bl FormatFullWidthDecimal
    lsls r0, r7, #0x1e
    lsrs r0, r0, #0x1e
    bl func_0800E2E4
    mov sb, r0
    ldr r6, .Ljp_08005124
    add r6, r8
    mov r4, sb
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08005028
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08005018
    adds r4, r5, #0
.Ljp_08005018:
    adds r0, r7, #0
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    adds r0, r7, r4
    mov r1, sl
    strb r1, [r0]
.Ljp_08005028:
    ldr r0, .Ljp_08005128
    mov sb, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_0800505A
    mov r0, sb
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_0800504A
    adds r4, r5, #0
.Ljp_0800504A:
    adds r0, r7, #0
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_0800505A:
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08005088
    add r0, sp, #0x14
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08005078
    adds r4, r5, #0
.Ljp_08005078:
    adds r0, r7, #0
    add r1, sp, #0x14
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_08005088:
    ldr r7, .Ljp_0800512C
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_080050B8
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_080050A8
    adds r4, r5, #0
.Ljp_080050A8:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Ljp_080050B8:
    ldr r5, .Ljp_08005130
    add r5, r8
    ldr r0, [sp, #0x24]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_080050CA
    movs r4, #0xf
.Ljp_080050CA:
    adds r0, r5, #0
    ldr r1, [sp, #0x24]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    movs r6, #0
    strb r6, [r0]
    ldr r5, .Ljp_08005134
    add r5, r8
    ldr r0, [sp, #0x48]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .Ljp_080050EC
    movs r4, #0xf
.Ljp_080050EC:
    adds r0, r5, #0
    ldr r1, [sp, #0x48]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    strb r6, [r0]
    mov r0, r8
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Ljp_0800510C: .4byte vtable_unk_080E5A98
.Ljp_08005110: .4byte 0x00001828
.Ljp_08005114: .4byte 0x0000182C
.Ljp_08005118: .4byte 0x00001830
.Ljp_0800511C: .4byte 0x00001834
.Ljp_08005120: .4byte 0x00001876
.Ljp_08005124: .4byte 0x00001844
.Ljp_08005128: .4byte gText_NewGameIdentity_BirthMonthSuffix
.Ljp_0800512C: .4byte gText_NewGameIdentity_BirthDaySuffix
.Ljp_08005130: .4byte 0x00001854
.Ljp_08005134: .4byte 0x00001864

    .section .text.new_game_identity_core_after_initialization

    .global InitializeNewGameIdentityScreen
    .thumb_func
InitializeNewGameIdentityScreen:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x70
    mov sl, r0
    ldr r0, .Ljp_080054B0
    ldr r0, [r0]
    ldr r1, .Ljp_080054B4
    ldr r2, .Ljp_080054B8
    ldr r2, [r2]
    bl func_08008E64
    ldr r0, .Ljp_080054BC
    ldr r0, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x20
    bl func_08008E64
    mov r0, sl
    bl func_08008918
    add r1, sp, #0xc
    movs r3, #0xba
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r5, .Ljp_080054C0
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r3, .Ljp_080054C4
    adds r1, r3, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .Ljp_080054C8
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    ldr r1, .Ljp_080054CC
    movs r0, #0
    movs r2, #0x20
    bl func_08008EB8
    movs r7, #0
    add r5, sp, #0x20
    add r4, sp, #0x24
    mov sb, r4
    mov r0, sp
    adds r0, #0x28
    str r0, [sp, #0x44]
    mov r1, sp
    adds r1, #0x2c
    str r1, [sp, #0x4c]
    mov r2, sp
    adds r2, #0x30
    str r2, [sp, #0x50]
    mov r3, sp
    adds r3, #0x34
    str r3, [sp, #0x54]
    mov r4, sp
    adds r4, #0x10
    str r4, [sp, #0x60]
    movs r0, #0xc
    mov r8, r0
    movs r6, #2
    mov r4, sl
    adds r4, #0xc
.Ljp_08005398:
    add r0, sp, #0x20
    mov r1, r8
    strh r1, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r2, #0xc1
    lsls r2, r2, #2
    adds r4, r4, r2
    adds r7, #1
    cmp r7, #7
    bls .Ljp_08005398
    movs r7, #0
    ldr r3, .Ljp_080054D0
    add r3, sl
    mov r8, r3
    movs r4, #0xf2
    lsls r4, r4, #4
    add r4, sl
    str r4, [sp, #0x48]
    ldr r5, .Ljp_080054D4
    add r5, sl
    str r5, [sp, #0x5c]
    ldr r0, .Ljp_080054D8
    add r0, sl
    str r0, [sp, #0x58]
    movs r6, #0xc
    movs r5, #2
    mov r4, sl
    adds r4, #0xc
.Ljp_080053DA:
    lsls r1, r7, #4
    add r1, sl
    ldr r2, .Ljp_080054DC
    adds r1, r1, r2
    add r0, sp, #0x24
    strh r6, [r0]
    mov r3, sb
    strh r5, [r3, #2]
    ldr r0, [sp, #0x24]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r0, #0xc1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_080053DA
    ldr r1, .Ljp_080054E0
    movs r4, #0xc
    movs r5, #2
    add r0, sp, #0x28
    strh r4, [r0]
    ldr r2, [sp, #0x44]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x28]
    str r1, [sp]
    mov r1, r8
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054E4
    add r0, sp, #0x2c
    strh r4, [r0]
    ldr r3, [sp, #0x4c]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x2c]
    str r1, [sp]
    ldr r1, [sp, #0x48]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054E8
    add r0, sp, #0x30
    strh r4, [r0]
    ldr r0, [sp, #0x50]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x5c]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .Ljp_080054EC
    add r0, sp, #0x34
    strh r4, [r0]
    ldr r2, [sp, #0x54]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    ldr r1, [sp, #0x58]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r7, #0
    ldr r3, [sp, #0x60]
    str r3, [sp, #0x40]
    movs r4, #0xc0
    lsls r4, r4, #0x13
    str r4, [sp, #0x64]
    mov r5, sl
    adds r5, #0xc
    str r5, [sp, #0x68]
.Ljp_0800547A:
    mov r0, sl
    bl func_08008910
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x68]
    ldr r2, [sp, #0x64]
    movs r3, #0xc0
    lsls r3, r3, #2
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .Ljp_080054F0
    cmp r1, #0
    beq .Ljp_080054A8
    adds r0, r1, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080054A8:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .Ljp_080055BA
.Ljp_080054B0:
    .4byte gUiSharedTiles
.Ljp_080054B4:
    .4byte 0x06004B00
.Ljp_080054B8:
    .4byte gUiSharedTileByteCount
.Ljp_080054BC:
    .4byte gUiSharedPalette
.Ljp_080054C0:
    .4byte 0x00001841
.Ljp_080054C4:
    .4byte 0x00001F01
.Ljp_080054C8:
    .4byte 0x0600F800
.Ljp_080054CC:
    .4byte 0x06FFC000
.Ljp_080054D0:
    .4byte 0x00000C1C
.Ljp_080054D4:
    .4byte 0x00001224
.Ljp_080054D8:
    .4byte 0x00001528
.Ljp_080054DC:
    .4byte 0x00001834
.Ljp_080054E0:
    .4byte gText_NewGameIdentity_PlayerName
.Ljp_080054E4:
    .4byte gText_NewGameIdentity_PlayerBirthday
.Ljp_080054E8:
    .4byte gText_NewGameIdentity_FarmName
.Ljp_080054EC:
    .4byte gText_NewGameIdentity_DogName
.Ljp_080054F0:
    mov r8, r1
    movs r0, #1
    str r0, [sp, #0x3c]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x38]
    add r1, sp, #0x3c
    add r0, sp, #0x38
    cmp r4, #1
    bhs .Ljp_08005508
    adds r0, r1, #0
.Ljp_08005508:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08005526
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Ljp_0800552A
    mov r0, sb
    bl RetryMemoryAllocation
    b .Ljp_0800552A
.Ljp_08005526:
    movs r0, #0
    mov sb, r0
.Ljp_0800552A:
    adds r5, r0, #0
    str r5, [sp, #0x6c]
    ldr r2, [r6]
    mov ip, r5
    cmp r2, r8
    beq .Ljp_08005552
.Ljp_08005536:
    mov r5, ip
    cmp r5, #0
    beq .Ljp_08005548
    mov r0, ip
    adds r1, r2, #0
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08005548:
    adds r2, #0x10
    movs r0, #0x10
    add ip, r0
    cmp r2, r8
    bne .Ljp_08005536
.Ljp_08005552:
    mov r5, ip
    ldr r0, [sp, #0x3c]
    cmp r0, #1
    bne .Ljp_0800556E
    cmp r5, #0
    beq .Ljp_0800556A
    adds r0, r5, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800556A:
    adds r5, #0x10
    b .Ljp_08005596
.Ljp_0800556E:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .Ljp_08005594
.Ljp_08005576:
    cmp r2, #0
    beq .Ljp_08005586
    adds r0, r2, #0
    ldr r1, [sp, #0x40]
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08005586:
    movs r5, #1
    rsbs r5, r5, #0
    add r8, r5
    adds r2, #0x10
    mov r0, r8
    cmp r0, #0
    bne .Ljp_08005576
.Ljp_08005594:
    adds r5, r2, #0
.Ljp_08005596:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_080055A6
.Ljp_080055A0:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_080055A0
.Ljp_080055A6:
    cmp r0, #0
    beq .Ljp_080055AE
    bl free
.Ljp_080055AE:
    ldr r0, [sp, #0x6c]
    add r0, sb
    ldr r1, [sp, #0x6c]
    str r1, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.Ljp_080055BA:
    ldr r2, [sp, #0x64]
    movs r3, #0xc0
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x64]
    ldr r4, [sp, #0x68]
    movs r5, #0xc1
    lsls r5, r5, #2
    adds r4, r4, r5
    str r4, [sp, #0x68]
    adds r7, #1
    cmp r7, #7
    bhi .Ljp_080055D6
    b .Ljp_0800547A
.Ljp_080055D6:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .Ljp_080056BC
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl func_08008EB8
    movs r7, #0
    movs r1, #0xaa
.Ljp_080055EA:
    movs r5, #0
    lsls r0, r7, #6
    adds r0, r0, r4
.Ljp_080055F0:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r5, #0x1d
    bls .Ljp_080055F0
    adds r7, #1
    cmp r7, #0x13
    bls .Ljp_080055EA
    movs r5, #2
    ldr r6, .Ljp_080056C0
.Ljp_08005604:
    movs r7, #0
    lsls r1, r5, #1
    adds r4, r5, #0
    adds r4, #0x6a
    adds r3, r5, #0
    adds r3, #0x5e
    ldr r0, .Ljp_080056C4
    adds r2, r1, r0
.Ljp_08005614:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_08005614
    adds r5, #1
    cmp r5, #0xd
    bls .Ljp_08005604
    movs r5, #0x10
    ldr r1, .Ljp_080056C8
    mov r8, r1
    ldr r2, .Ljp_080056C0
    mov sb, r2
.Ljp_08005638:
    movs r7, #0
    lsls r1, r5, #1
    adds r6, r5, #1
    adds r0, r5, #0
    adds r0, #0xc
    mov r3, r8
    adds r4, r0, r3
    adds r3, r5, r3
    ldr r5, .Ljp_080056C4
    adds r2, r1, r5
.Ljp_0800564C:
    strh r3, [r2]
    mov r5, sb
    adds r0, r1, r5
    strh r4, [r0]
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    adds r7, #1
    cmp r7, #3
    bls .Ljp_0800564C
    adds r5, r6, #0
    cmp r5, #0x1b
    bls .Ljp_08005638
    ldr r0, .Ljp_080056CC
    add r0, sl
    ldr r0, [r0]
    mov sb, r0
    mov r0, sl
    bl func_080088DC
    mov r8, r0
    mov r0, sl
    bl func_08008920
    adds r6, r0, #0
    mov r0, sl
    bl func_08008918
    adds r5, r0, #0
    mov r0, sl
    bl func_08008940
    adds r4, r0, #0
    mov r0, sl
    bl func_0800894C
    ldr r1, .Ljp_080056D0
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x70
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Ljp_080056BC:
    .4byte 0x0600C000
.Ljp_080056C0:
    .4byte 0x0600C080
.Ljp_080056C4:
    .4byte 0x0600C040
.Ljp_080056C8:
    .4byte 0x0000FFF0
.Ljp_080056CC:
    .4byte 0x0000182C
.Ljp_080056D0:
    .4byte 0x00001830

    .section .text.new_game_name_input_after_core_run
    .global func_08005CDC
    .thumb_func
func_08005CDC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #84	@ 0x54
    mov	sl, r0
    ldr r0, .Ljp_00005D9C
    ldr	r0, [r0, #0]
    ldr r1, .Ljp_00005DA0
    ldr r2, .Ljp_00005DA4
    ldr	r2, [r2, #0]
    bl func_08008E64
    ldr r0, .Ljp_00005DA8
    ldr	r0, [r0, #0]
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #19
    movs	r2, #32
    bl func_08008E64
    mov	r0, sl
    bl func_08008918
    add	r1, sp, #12
    movs	r3, #186	@ 0xba
    lsls	r3, r3, #5
    adds	r2, r3, #0
    strh	r2, [r1, #0]
    movs	r4, #0
    strh	r2, [r0, #0]
    mov	r0, sl
    bl func_08008918
    add	r2, sp, #12
    ldr r5, .Ljp_00005DAC
    adds	r1, r5, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #10]
    mov	r0, sl
    bl func_08008918
    add	r2, sp, #12
    ldr r7, .Ljp_00005DB0
    adds	r1, r7, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #12]
    ldr r0, .Ljp_00005DB4
    movs	r1, #20
    str	r1, [sp, #0]
    movs	r1, #150	@ 0x96
    lsls	r1, r1, #2
    str	r1, [sp, #4]
    str	r4, [sp, #8]
    movs	r1, #0
    movs	r2, #0
    movs	r3, #30
    bl DrawUiTextWindowBorder
    movs	r0, #1
    negs	r0, r0
    ldr r4, .Ljp_00005DB8
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl func_08008EB8
    movs	r1, #0
    add	r0, sp, #32
    mov	r8, r0
    add	r2, sp, #36	@ 0x24
    mov	r9, r2
    mov	r3, sp
    adds	r3, #16
    str	r3, [sp, #68]	@ 0x44
    mov	r5, sp
    adds	r5, #48	@ 0x30
    str	r5, [sp, #72]	@ 0x48
    mov	r7, sl
    adds	r7, #12
    ldr r0, .Ljp_00005DBC
    add	r0, sl
    str	r0, [sp, #64]	@ 0x40
    movs	r2, #209	@ 0xd1
    lsls	r2, r2, #1
    adds	r6, r2, #0
.Ljp_00005C5C:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    adds	r0, r2, r4
.Ljp_00005C64:
    strh	r6, [r0, #0]
    adds	r0, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005C64
    adds	r1, r5, #0
    cmp	r1, #19
    bls .Ljp_00005C5C
    movs	r3, #10
    ldr r2, .Ljp_00005DC0
    ldr r1, .Ljp_00005DC4
.Ljp_00005C7A:
    strh	r3, [r1, #0]
    adds	r0, r3, #0
    adds	r0, #30
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #15
    bls .Ljp_00005C7A
    movs	r3, #3
    movs	r4, #210	@ 0xd2
    lsls	r4, r4, #1
    adds	r5, r4, #0
    movs	r0, #225	@ 0xe1
    lsls	r0, r0, #1
    adds	r4, r0, #0
    ldr r2, .Ljp_00005DC8
    ldr r1, .Ljp_00005DCC
.Ljp_00005C9E:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #26
    bls .Ljp_00005C9E
    movs	r1, #4
    ldr r4, .Ljp_00005DB8
.Ljp_00005CB4:
    movs	r3, #0
    lsls	r2, r1, #6
    adds	r5, r1, #1
    subs	r1, #2
    lsls	r0, r1, #4
    subs	r0, r0, r1
    lsls	r1, r0, #1
    adds	r2, r2, r4
.Ljp_00005CC4:
    adds	r0, r1, r3
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005CC4
    adds	r1, r5, #0
    cmp	r1, #15
    bls .Ljp_00005CB4
    movs	r3, #18
    movs	r1, #240	@ 0xf0
    lsls	r1, r1, #1
    adds	r5, r1, #0
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #1
    adds	r4, r2, #0
    ldr r2, .Ljp_00005DD0
    ldr r1, .Ljp_00005DD4
.Ljp_00005CE8:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #29
    bls .Ljp_00005CE8
    ldr r0, .Ljp_00005DD8
    add	r0, sl
    ldr	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_00005D26
    movs	r3, #4
    movs	r4, #134	@ 0x86
    lsls	r4, r4, #2
    adds	r5, r4, #0
    ldr r0, .Ljp_00005DDC
    adds	r4, r0, #0
    ldr r2, .Ljp_00005DE0
    ldr r1, .Ljp_00005DE4
.Ljp_00005D14:
    adds	r0, r3, r5
    strh	r0, [r1, #0]
    adds	r0, r3, r4
    strh	r0, [r2, #0]
    adds	r2, #2
    adds	r1, #2
    adds	r3, #1
    cmp	r3, #9
    bls .Ljp_00005D14
.Ljp_00005D26:
    ldr r1, .Ljp_00005DE8
    movs	r0, #0
    movs	r2, #32
    bl func_08008EB8
    movs	r4, #30
    movs	r5, #2
    add	r0, sp, #32
    strh	r4, [r0, #0]
    mov	r1, r8
    strh	r5, [r1, #2]
    ldr	r0, [sp, #32]
    adds	r1, r7, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .Ljp_00005DEC
    add	r0, sp, #36	@ 0x24
    strh	r4, [r0, #0]
    mov	r2, r9
    strh	r5, [r2, #2]
    ldr	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #0]
    adds	r1, r7, #0
    movs	r2, #80	@ 0x50
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
    mov	r0, sl
    bl func_08008910
    movs	r3, #240	@ 0xf0
    lsls	r3, r3, #3
    adds	r6, r0, #0
    add	r0, sp, #16
    adds	r1, r7, #0
    movs	r2, #192	@ 0xc0
    lsls	r2, r2, #19
    bl __21DmaTransferDescriptorPCvPvUi
    ldr	r3, [sp, #68]	@ 0x44
    mov	r8, r3
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq .Ljp_00005DF0
    cmp	r1, #0
    beq .Ljp_00005D92
    adds	r0, r1, #0
    mov	r1, r8
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005D92:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b .Ljp_00005EB4
    .align 2, 0
.Ljp_00005D9C: .4byte gUiSharedTiles
.Ljp_00005DA0: .4byte 0x06004B00
.Ljp_00005DA4: .4byte gUiSharedTileByteCount
.Ljp_00005DA8: .4byte gUiSharedPalette
.Ljp_00005DAC: .4byte 0x00001841
.Ljp_00005DB0: .4byte 0x00001F02
.Ljp_00005DB4: .4byte 0x0600F800
.Ljp_00005DB8: .4byte 0x0600C000
.Ljp_00005DBC: .4byte 0x000043B0
.Ljp_00005DC0: .4byte 0x0600C094
.Ljp_00005DC4: .4byte 0x0600C054
.Ljp_00005DC8: .4byte 0x0600C486
.Ljp_00005DCC: .4byte 0x0600C446
.Ljp_00005DD0: .4byte 0x0600C0A4
.Ljp_00005DD4: .4byte 0x0600C064
.Ljp_00005DD8: .4byte 0x0000453C
.Ljp_00005DDC: .4byte 0x0000021E
.Ljp_00005DE0: .4byte 0x0600C088
.Ljp_00005DE4: .4byte 0x0600C048
.Ljp_00005DE8: .4byte 0x06FFC000
.Ljp_00005DEC: .4byte gText_NewGameNameEntry_NameLabel
.Ljp_00005DF0:
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #1
    str	r0, [sp, #44]	@ 0x2c
    ldr	r0, [r6, #0]
    subs	r0, r1, r0
    asrs	r4, r0, #4
    str	r4, [sp, #40]	@ 0x28
    add	r1, sp, #44	@ 0x2c
    add	r0, sp, #40	@ 0x28
    cmp	r4, #1
    bcs .Ljp_00005E08
    adds	r0, r1, #0
.Ljp_00005E08:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq .Ljp_00005E26
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl malloc
    mov	r9, r4
    cmp	r0, #0
    bne .Ljp_00005E2A
    mov	r0, r9
    bl RetryMemoryAllocation
    b .Ljp_00005E2A
.Ljp_00005E26:
    movs	r0, #0
    mov	r9, r0
.Ljp_00005E2A:
    adds	r5, r0, #0
    str	r5, [sp, #80]	@ 0x50
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r2, r4
    beq .Ljp_00005E52
.Ljp_00005E38:
    cmp	r3, #0
    beq .Ljp_00005E48
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E48:
    adds	r2, #16
    adds	r3, #16
    ldr	r5, [sp, #76]	@ 0x4c
    cmp	r2, r5
    bne .Ljp_00005E38
.Ljp_00005E52:
    adds	r5, r3, #0
    ldr	r0, [sp, #44]	@ 0x2c
    cmp	r0, #1
    bne .Ljp_00005E6E
    cmp	r5, #0
    beq .Ljp_00005E6A
    adds	r0, r5, #0
    mov	r1, r8
    ldmia	r1!, {r2, r3, r7}
    stmia	r0!, {r2, r3, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E6A:
    adds	r5, #16
    b .Ljp_00005E90
.Ljp_00005E6E:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq .Ljp_00005E8E
.Ljp_00005E76:
    cmp	r2, #0
    beq .Ljp_00005E86
    adds	r0, r2, #0
    mov	r1, r8
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005E86:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne .Ljp_00005E76
.Ljp_00005E8E:
    adds	r5, r2, #0
.Ljp_00005E90:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq .Ljp_00005EA0
.Ljp_00005E9A:
    adds	r1, #16
    cmp	r1, r2
    bne .Ljp_00005E9A
.Ljp_00005EA0:
    cmp	r0, #0
    beq .Ljp_00005EA8
    bl free
.Ljp_00005EA8:
    ldr	r0, [sp, #80]	@ 0x50
    add	r0, r9
    ldr	r1, [sp, #80]	@ 0x50
    str	r1, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.Ljp_00005EB4:
    ldr r1, .Ljp_00005F48
    add	r1, sl
    movs	r0, #0
    str	r0, [r1, #0]
    ldr r0, .Ljp_00005F4C
    add	r0, sl
    movs	r2, #1
    mov	r8, r2
    mov	r3, r8
    strb	r3, [r0, #0]
    mov	r0, sl
    bl func_080064E8
    movs	r5, #6
    movs	r6, #2
    add	r0, sp, #48	@ 0x30
    strh	r5, [r0, #0]
    ldr	r4, [sp, #72]	@ 0x48
    strh	r6, [r4, #2]
    ldr	r0, [sp, #48]	@ 0x30
    ldr	r4, [sp, #64]	@ 0x40
    adds	r1, r4, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_00005F50
    add	r0, sl
    ldr	r1, [r0, #0]
    cmp	r1, #0
    beq .Ljp_00005F04
    add	r0, sp, #52	@ 0x34
    strh	r5, [r0, #0]
    strh	r6, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #0]
    adds	r1, r4, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Ljp_00005F04:
    mov	r0, sl
    bl func_08008910
    movs	r3, #192	@ 0xc0
    lsls	r3, r3, #1
    adds	r6, r0, #0
    movs	r2, #240	@ 0xf0
    lsls	r2, r2, #3
    lsls	r2, r2, #3
    ldr r5, .Ljp_00005F54
    adds	r2, r2, r5
    add	r0, sp, #12
    ldr	r1, [sp, #64]	@ 0x40
    bl __21DmaTransferDescriptorPCvPvUi
    add	r7, sp, #12
    mov	r9, r7
    ldr	r1, [r6, #4]
    ldr	r0, [r6, #12]
    cmp	r1, r0
    beq .Ljp_00005F58
    cmp	r1, #0
    beq .Ljp_00005F3E
    adds	r0, r1, #0
    add	r1, sp, #12
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005F3E:
    ldr	r0, [r6, #4]
    adds	r0, #16
    str	r0, [r6, #4]
    b .Ljp_0000601A
    .align 2, 0
.Ljp_00005F48: .4byte 0x00004540
.Ljp_00005F4C: .4byte 0x00004577
.Ljp_00005F50: .4byte 0x0000453C
.Ljp_00005F54: .4byte 0x06000780
.Ljp_00005F58:
    str	r1, [sp, #76]	@ 0x4c
    mov	r5, r8
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #0]
    adds	r7, r1, #0
    subs	r0, r7, r0
    asrs	r4, r0, #4
    str	r4, [sp, #56]	@ 0x38
    add	r1, sp, #60	@ 0x3c
    add	r0, sp, #56	@ 0x38
    cmp	r4, #1
    bcs .Ljp_00005F72
    adds	r0, r1, #0
.Ljp_00005F72:
    ldr	r0, [r0, #0]
    adds	r0, r4, r0
    cmp	r0, #0
    beq .Ljp_00005F90
    lsls	r4, r0, #4
    adds	r0, r4, #0
    bl malloc
    mov	r8, r4
    cmp	r0, #0
    bne .Ljp_00005F94
    mov	r0, r8
    bl RetryMemoryAllocation
    b .Ljp_00005F94
.Ljp_00005F90:
    movs	r0, #0
    mov	r8, r0
.Ljp_00005F94:
    adds	r5, r0, #0
    str	r5, [sp, #80]	@ 0x50
    ldr	r2, [r6, #0]
    adds	r3, r5, #0
    b .Ljp_00005FB2
.Ljp_00005F9E:
    cmp	r3, #0
    beq .Ljp_00005FAE
    adds	r0, r3, #0
    adds	r1, r2, #0
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FAE:
    adds	r2, #16
    adds	r3, #16
.Ljp_00005FB2:
    ldr	r0, [sp, #76]	@ 0x4c
    cmp	r2, r0
    bne .Ljp_00005F9E
    adds	r5, r3, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Ljp_00005FD4
    cmp	r5, #0
    beq .Ljp_00005FD0
    adds	r0, r5, #0
    mov	r1, r9
    ldmia	r1!, {r2, r3, r4}
    stmia	r0!, {r2, r3, r4}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FD0:
    adds	r5, #16
    b .Ljp_00005FF6
.Ljp_00005FD4:
    adds	r3, r0, #0
    adds	r2, r5, #0
    cmp	r3, #0
    beq .Ljp_00005FF4
.Ljp_00005FDC:
    cmp	r2, #0
    beq .Ljp_00005FEC
    adds	r0, r2, #0
    mov	r1, r9
    ldmia	r1!, {r4, r5, r7}
    stmia	r0!, {r4, r5, r7}
    ldr	r1, [r1, #0]
    str	r1, [r0, #0]
.Ljp_00005FEC:
    subs	r3, #1
    adds	r2, #16
    cmp	r3, #0
    bne .Ljp_00005FDC
.Ljp_00005FF4:
    adds	r5, r2, #0
.Ljp_00005FF6:
    ldr	r2, [r6, #4]
    ldr	r0, [r6, #0]
    adds	r1, r0, #0
    cmp	r0, r2
    beq .Ljp_00006006
.Ljp_00006000:
    adds	r1, #16
    cmp	r1, r2
    bne .Ljp_00006000
.Ljp_00006006:
    cmp	r0, #0
    beq .Ljp_0000600E
    bl free
.Ljp_0000600E:
    ldr	r0, [sp, #80]	@ 0x50
    add	r0, r8
    ldr	r7, [sp, #80]	@ 0x50
    str	r7, [r6, #0]
    str	r5, [r6, #4]
    str	r0, [r6, #12]
.Ljp_0000601A:
    ldr r0, .Ljp_00006070
    add	r0, sl
    ldr	r0, [r0, #0]
    mov	r9, r0
    mov	r0, sl
    bl func_080088DC
    mov	r8, r0
    mov	r0, sl
    bl func_08008920
    adds	r6, r0, #0
    mov	r0, sl
    bl func_08008918
    adds	r5, r0, #0
    mov	r0, sl
    bl func_08008940
    adds	r4, r0, #0
    mov	r0, sl
    bl func_0800894C
    ldr r1, .Ljp_00006074
    add	r1, sl
    str	r4, [sp, #0]
    str	r0, [sp, #4]
    str	r1, [sp, #8]
    mov	r0, r9
    mov	r1, r8
    adds	r2, r6, #0
    adds	r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add	sp, #84	@ 0x54
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_00006070: .4byte 0x00004538
.Ljp_00006074: .4byte 0x00004530

    .section .text.new_game_name_input_after_reset
    .global func_0800637C
    .thumb_func
func_0800637C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r5, r0, #0
    movs r0, #0xf0
    lsls r0, r0, #3
    mov r9, r0
    movs r1, #0x60
    movs r2, #0x10
    movs r3, #0
    add r0, sp, #0x1c
    movs r6, #0x1e
    movs r4, #2
    mov r8, r4
    strh r6, [r0]
    mov r7, r8
    strh r7, [r0, #2]
    ldr r0, [sp, #0x1c]
    ldr r7, .Ljp_080062E4 @ =0x00003C2C
    adds r4, r5, r7
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBufferRect
    ldr r0, .Ljp_080062E8 @ =0x0000455C
    adds r1, r5, r0
    add r0, sp, #0x20
    strh r6, [r0]
    mov r2, r8
    strh r2, [r0, #2]
    ldr r0, [sp, #0x20]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0x90
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    adds r0, r5, #0
    bl func_08008910
    adds r6, r0, #0
    mov r3, r9
    lsls r2, r3, #3
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    add r0, sp, #0xc
    adds r1, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r4, sp, #0xc
    mov r9, r4
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .Ljp_080062EC
    cmp r1, #0
    beq .Ljp_080062DC
    adds r0, r1, #0
    add r1, sp, #0xc
    ldmia r1!, {r2, r5, r7}
    stmia r0!, {r2, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080062DC:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .Ljp_080063AC
    .align 2, 0
.Ljp_080062E4: .4byte 0x00003C2C
.Ljp_080062E8: .4byte 0x0000455C
.Ljp_080062EC:
    mov sl, r1
    movs r0, #1
    str r0, [sp, #0x28]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x24]
    add r1, sp, #0x28
    add r0, sp, #0x24
    cmp r4, #1
    bcs .Ljp_08006304
    adds r0, r1, #0
.Ljp_08006304:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08006322
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Ljp_08006326
    mov r0, r8
    bl RetryMemoryAllocation
    b .Ljp_08006326
.Ljp_08006322:
    movs r0, #0
    mov r8, r0
.Ljp_08006326:
    adds r5, r0, #0
    str r5, [sp, #0x2c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, sl
    beq .Ljp_0800634A
.Ljp_08006332:
    cmp r3, #0
    beq .Ljp_08006342
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006342:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, sl
    bne .Ljp_08006332
.Ljp_0800634A:
    adds r5, r3, #0
    ldr r0, [sp, #0x28]
    cmp r0, #1
    bne .Ljp_08006366
    cmp r5, #0
    beq .Ljp_08006362
    adds r0, r5, #0
    mov r1, r9
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006362:
    adds r5, #0x10
    b .Ljp_08006388
.Ljp_08006366:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Ljp_08006386
.Ljp_0800636E:
    cmp r2, #0
    beq .Ljp_0800637E
    adds r0, r2, #0
    mov r1, r9
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800637E:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_0800636E
.Ljp_08006386:
    adds r5, r2, #0
.Ljp_08006388:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006398
.Ljp_08006392:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_08006392
.Ljp_08006398:
    cmp r0, #0
    beq .Ljp_080063A0
    bl free
.Ljp_080063A0:
    ldr r0, [sp, #0x2c]
    add r0, r8
    ldr r7, [sp, #0x2c]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.Ljp_080063AC:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    .global func_080064E8
    .thumb_func
func_080064E8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    mov sl, r0
    ldr r0, .Ljp_080064A4
    add r0, sl
    ldrb r0, [r0]
    cmp r0, #0
    bne .Ljp_080063D6
    b .Ljp_0800671E
.Ljp_080063D6:
    movs r0, #1
    mov r8, r0
    mov r1, sp
    adds r1, #0x14
    str r1, [sp, #0x40]
    mov r2, sp
    adds r2, #0x18
    str r2, [sp, #0x44]
    mov r3, sp
    adds r3, #0x24
    str r3, [sp, #0x48]
    ldr r4, .Ljp_080064A8
    add r4, sl
    str r4, [sp, #0x50]
    mov r6, sp
    adds r6, #4
    str r6, [sp, #0x3c]
.Ljp_080063F8:
    mov r7, r8
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #0x1e
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #0xc
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_080064AC
    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
    lsls r2, r0, #5
    subs r2, r2, r0
    movs r0, #0xba
    muls r0, r3
    adds r2, r2, r0
    ldr r0, .Ljp_080064B0
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #0x1e
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #0xc
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl func_08008910
    add r4, sl
    adds r4, #0xc
    movs r1, #0xf0
    lsls r1, r1, #3
    mov r2, r8
    muls r2, r1
    adds r5, r0, #0
    movs r3, #0xc0
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
    movs r3, #0xf0
    lsls r3, r3, #3
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .Ljp_080064B4
    cmp r1, #0
    beq .Ljp_0800648E
    adds r0, r1, #0
    add r1, sp, #4
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800648E:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    movs r0, #1
    add r8, r0
    movs r1, #0xf0
    lsls r1, r1, #3
    lsls r1, r1, #3
    str r1, [sp, #0x4c]
    b .Ljp_08006586
    .align 2, 0
.Ljp_080064A4: .4byte 0x00004577
.Ljp_080064A8: .4byte 0x000034A8
.Ljp_080064AC: .4byte 0x00004540
    @ This is the one-row-before base consumed by the keyboard-row renderer,
    @ not an interior pointer into the confirmation text.
.Ljp_080064B0:
    .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.Ljp_080064B4:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x20]
    ldr r0, [r5]
    adds r2, r1, #0
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x1c]
    add r1, sp, #0x20
    add r0, sp, #0x1c
    cmp r4, #1
    bcs .Ljp_080064CE
    adds r0, r1, #0
.Ljp_080064CE:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_080064EC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r9, r4
    cmp r0, #0
    bne .Ljp_080064F0
    mov r0, r9
    bl RetryMemoryAllocation
    b .Ljp_080064F0
.Ljp_080064EC:
    movs r0, #0
    mov r9, r0
.Ljp_080064F0:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    movs r4, #1
    add r8, r4
    movs r6, #0xf0
    lsls r6, r6, #3
    lsls r6, r6, #3
    str r6, [sp, #0x4c]
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .Ljp_08006524
.Ljp_0800650A:
    cmp r3, #0
    beq .Ljp_0800651A
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800651A:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .Ljp_0800650A
.Ljp_08006524:
    adds r4, r3, #0
    ldr r0, [sp, #0x20]
    cmp r0, #1
    bne .Ljp_08006540
    cmp r4, #0
    beq .Ljp_0800653C
    adds r0, r4, #0
    ldr r1, [sp, #0x3c]
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_0800653C:
    adds r4, #0x10
    b .Ljp_08006562
.Ljp_08006540:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .Ljp_08006560
.Ljp_08006548:
    cmp r2, #0
    beq .Ljp_08006558
    adds r0, r2, #0
    ldr r1, [sp, #0x3c]
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006558:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_08006548
.Ljp_08006560:
    adds r4, r2, #0
.Ljp_08006562:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006572
.Ljp_0800656C:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_0800656C
.Ljp_08006572:
    cmp r0, #0
    beq .Ljp_0800657A
    bl free
.Ljp_0800657A:
    ldr r0, [sp, #0x58]
    add r0, r9
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.Ljp_08006586:
    mov r0, r8
    cmp r0, #6
    bhi .Ljp_0800658E
    b .Ljp_080063F8
.Ljp_0800658E:
    movs r4, #0x1e
    movs r5, #2
    add r0, sp, #0x24
    strh r4, [r0]
    ldr r1, [sp, #0x48]
    strh r5, [r1, #2]
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x50]
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .Ljp_080065B8
    add r0, sl
    ldr r2, [r0]
    cmp r2, #1
    beq .Ljp_080065D4
    cmp r2, #1
    bgt .Ljp_080065BC
    cmp r2, #0
    beq .Ljp_080065C2
    b .Ljp_08006606
    .align 2, 0
.Ljp_080065B8: .4byte 0x00004540
.Ljp_080065BC:
    cmp r2, #2
    beq .Ljp_080065F0
    b .Ljp_08006606
.Ljp_080065C2:
    ldr r1, .Ljp_080065D0
    add r0, sp, #0x28
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x28]
    b .Ljp_080065DE
    .align 2, 0
.Ljp_080065D0:
    .4byte gText_NewGameNameEntry_ModeKatakana
.Ljp_080065D4:
    ldr r1, .Ljp_080065EC
    add r0, sp, #0x2c
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x2c]
.Ljp_080065DE:
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    b .Ljp_08006606
.Ljp_080065EC:
    .4byte gText_NewGameNameEntry_ModeSymbols
.Ljp_080065F0:
    ldr r1, .Ljp_0800664C
    add r0, sp, #0x30
    strh r4, [r0]
    strh r2, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.Ljp_08006606:
    mov r0, sl
    bl func_08008910
    adds r5, r0, #0
    ldr r3, [sp, #0x4c]
    movs r4, #0xf0
    lsls r4, r4, #3
    subs r2, r3, r4
    movs r6, #0xc0
    lsls r6, r6, #0x13
    adds r2, r2, r6
    add r0, sp, #4
    ldr r1, [sp, #0x50]
    adds r3, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #4
    mov r9, r7
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .Ljp_08006650
    cmp r1, #0
    beq .Ljp_08006642
    adds r0, r1, #0
    add r1, sp, #4
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_08006642:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .Ljp_08006716
    .align 2, 0
.Ljp_0800664C:
    .4byte gText_NewGameNameEntry_ModeHiragana
.Ljp_08006650:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x38]
    ldr r0, [r5]
    adds r6, r1, #0
    subs r0, r6, r0
    asrs r4, r0, #4
    str r4, [sp, #0x34]
    add r1, sp, #0x38
    add r0, sp, #0x34
    cmp r4, #1
    bcs .Ljp_0800666A
    adds r0, r1, #0
.Ljp_0800666A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Ljp_08006688
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Ljp_0800668C
    mov r0, r8
    bl RetryMemoryAllocation
    b .Ljp_0800668C
.Ljp_08006688:
    movs r0, #0
    mov r8, r0
.Ljp_0800668C:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .Ljp_080066B4
.Ljp_0800669A:
    cmp r3, #0
    beq .Ljp_080066AA
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066AA:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .Ljp_0800669A
.Ljp_080066B4:
    adds r4, r3, #0
    ldr r0, [sp, #0x38]
    cmp r0, #1
    bne .Ljp_080066D0
    cmp r4, #0
    beq .Ljp_080066CC
    adds r0, r4, #0
    mov r1, r9
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066CC:
    adds r4, #0x10
    b .Ljp_080066F2
.Ljp_080066D0:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .Ljp_080066F0
.Ljp_080066D8:
    cmp r2, #0
    beq .Ljp_080066E8
    adds r0, r2, #0
    mov r1, r9
    ldmia r1!, {r4, r6, r7}
    stmia r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.Ljp_080066E8:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Ljp_080066D8
.Ljp_080066F0:
    adds r4, r2, #0
.Ljp_080066F2:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .Ljp_08006702
.Ljp_080066FC:
    adds r1, #0x10
    cmp r1, r2
    bne .Ljp_080066FC
.Ljp_08006702:
    cmp r0, #0
    beq .Ljp_0800670A
    bl free
.Ljp_0800670A:
    ldr r0, [sp, #0x58]
    add r0, r8
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.Ljp_08006716:
    ldr r1, .Ljp_08006730
    add r1, sl
    movs r0, #0
    strb r0, [r1]
.Ljp_0800671E:
    add sp, #0x5c
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Ljp_08006730: .4byte 0x00004577


    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

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

    .section .text.new_game_after_fades

    thumb_func_start func_08003C80
func_08003C80: @ 0x08003C80
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
    bl func_08008EB8
    movs r0, #1
    rsbs r0, r0, #0
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl func_08008EB8
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
    bl func_08008E64
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

    .section .text.new_game_after_status_update

    thumb_func_start func_08004570
func_08004570: @ 0x08004570
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
    bl func_08008918
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
    bl func_08008E64
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
    bl func_08008E64
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
    bl func_08003C80
    adds r4, r6, #0
    adds r4, #0x10
    adds r0, r4, #0
    movs r1, #0x2c
    bl func_08050E98
    adds r0, r4, #0
    bl func_08050D68
    adds r0, r6, #0
    bl func_08003C28
    ldrh r0, [r5, #8]
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r5, #8]
    adds r0, r6, #0
    bl func_08003EEC
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
    bl func_08008E64
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
    bl func_08008E64
    movs r4, #0
.L08004656:
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    adds r1, r4, #0
    bl func_08003DF0
    adds r4, #1
    cmp r4, #5
    bls .L08004656
    adds r0, r6, #0
    bl func_08003B40
    movs r0, #0x8c
    adds r0, r0, r6
    mov sl, r0
.L08004674:
    adds r0, r6, #0
    bl UpdateHardwareFrame
    adds r0, r6, #0
    bl func_080088B8
    adds r0, r6, #0
    bl func_08003C28
    adds r0, r6, #0
    bl func_080088D4
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
    bl func_08003DF0
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
    bl func_08003E88
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
    bl func_08003EEC
    ldr r2, [r6, #0x5c]
    ldr r3, [r6, #0x60]
    adds r0, r6, #0
    movs r1, #1
    bl func_08003DF0
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    movs r1, #0
    bl func_08003DF0
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
    bl func_08003DF0
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    movs r1, #1
    bl func_08003DF0
    adds r0, r6, #0
    bl func_08003EEC
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
    bl func_08003EEC
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
    bl func_08003EEC
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
    bl func_08003DF0
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
    bl func_08003DF0
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
    bl func_08003DF0
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
    bl func_08003DF0
.L08004A08:
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl func_08003DF0
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
    bl func_08003DF0
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl func_08003DF0
    ldr r1, [r5]
    ldr r2, [r6, #0x78]
    ldr r3, [r6, #0x7c]
    adds r0, r6, #0
    bl func_08003E88
    adds r0, r6, #0
    bl func_08003EEC
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
    bl func_08003F9C
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
    bl func_080040A0
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
    bl func_08003EEC
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
    bl func_08003EEC
    movs r0, #0
.L08004B30:
    mov r1, sl
    str r0, [r1]
    b .L08004674
.L08004B36:
    adds r0, r6, #0
    bl func_08003BB4
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

    .section .text.new_game_after_scene_lifecycle

    thumb_func_start InitializeNewGameIdentityCore
InitializeNewGameIdentityCore: @ US 0x08004EFC; body remains native.
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    adds r7, r0, #0
    adds r6, r1, #0
    mov r8, r2
    str r3, [sp, #0x24]
    bl func_08008444
    ldr r0, .L080050A4 @ =vtable_unk_080E5A98
    str r0, [r7, #4]
    movs r0, #3
    add r5, sp, #0x10
    add r1, sp, #0x14
    mov sb, r1
    movs r1, #1
    rsbs r1, r1, #0
.L08004F24:
    subs r0, #1
    cmp r0, r1
    bne .L08004F24
    movs r0, #3
    movs r1, #1
    rsbs r1, r1, #0
.L08004F30:
    subs r0, #1
    cmp r0, r1
    bne .L08004F30
    ldr r2, .L080050A8 @ =0x00001A28
    adds r1, r7, r2
    movs r0, #2
    str r0, [r1]
    movs r0, #4
    bl __builtin_new
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __18HardwareStateOwner
    adds r0, r5, #0
    bl __16HardwareResource
    movs r0, #0
    str r0, [sp]
    add r0, sp, #0xc
    str r0, [sp, #4]
    str r5, [sp, #8]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x1c
    movs r3, #4
    bl __12UiStateOwnerUiUiUiUiRC18HardwareStateOwnerRC16HardwareResource
    ldr r2, .L080050AC @ =0x00001A2C
    adds r1, r7, r2
    str r0, [r1]
    adds r0, r5, #0
    movs r1, #2
    bl _._16HardwareResource
    add r0, sp, #0xc
    movs r1, #2
    bl _._18HardwareStateOwner
    ldr r0, .L080050B0 @ =0x00001A30
    adds r4, r7, r0
    movs r0, #0xc8
    bl func_08008D3C
    str r0, [r4]
    ldr r1, .L080050B4 @ =0x00001A34
    adds r0, r7, r1
    movs r1, #3
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L08004F96:
    strb r3, [r0]
    adds r0, #0x10
    subs r1, #1
    cmp r1, r2
    bne .L08004F96
    ldr r2, .L080050B8 @ =0x00001A76
    adds r0, r7, r2
    movs r1, #0
    mov sl, r1
    mov r2, sl
    strb r2, [r0]
    ldr r0, .L080050B4 @ =0x00001A34
    adds r5, r7, r0
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08004FBE
    movs r4, #0xf
.L08004FBE:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    mov r1, sl
    strb r1, [r0]
    mov r2, r8
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    mov r1, sb
    movs r2, #2
    bl FormatSignedDecimal
    mov r1, r8
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    bl func_0800E2E4
    mov sb, r0
    ldr r2, .L080050BC @ =0x00001A44
    adds r6, r7, r2
    mov r4, sb
    adds r0, r6, #0
    bl strlen
    adds r1, r6, r0
    mov r8, r1
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .L08005022
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08005010
    adds r4, r5, #0
.L08005010:
    mov r0, r8
    mov r1, sb
    adds r2, r4, #0
    bl memcpy
    mov r2, r8
    adds r0, r2, r4
    mov r1, sl
    strb r1, [r0]
.L08005022:
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    movs r1, #0xf
    subs r5, r1, r0
    cmp r5, #0
    beq .L08005050
    add r0, sp, #0x14
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08005040
    adds r4, r5, #0
.L08005040:
    adds r0, r6, #0
    add r1, sp, #0x14
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L08005050:
    ldr r2, .L080050C0 @ =0x00001A54
    adds r5, r7, r2
    ldr r0, [sp, #0x24]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08005062
    movs r4, #0xf
.L08005062:
    adds r0, r5, #0
    ldr r1, [sp, #0x24]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    movs r6, #0
    strb r6, [r0]
    ldr r0, .L080050C4 @ =0x00001A64
    adds r5, r7, r0
    ldr r0, [sp, #0x48]
    bl strlen
    adds r4, r0, #0
    cmp r4, #0xf
    bls .L08005084
    movs r4, #0xf
.L08005084:
    adds r0, r5, #0
    ldr r1, [sp, #0x48]
    adds r2, r4, #0
    bl memcpy
    adds r0, r5, r4
    strb r6, [r0]
    adds r0, r7, #0
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080050A4: .4byte vtable_unk_080E5A98
.L080050A8: .4byte 0x00001A28
.L080050AC: .4byte 0x00001A2C
.L080050B0: .4byte 0x00001A30
.L080050B4: .4byte 0x00001A34
.L080050B8: .4byte 0x00001A76
.L080050BC: .4byte 0x00001A44
.L080050C0: .4byte 0x00001A54
.L080050C4: .4byte 0x00001A64

    .section .text.new_game_identity_core_after_initialization

    thumb_func_start InitializeNewGameIdentityScreen
InitializeNewGameIdentityScreen: @ US 0x08005278
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x94
    mov sl, r0
    ldr r0, .L08005488 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L0800548C @ =0x06004B00
    ldr r2, .L08005490 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl func_08008E64
    ldr r0, .L08005494 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x20
    bl func_08008E64
    mov r0, sl
    bl func_08008918
    add r1, sp, #0xc
    movs r3, #0xba
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r5, .L08005498 @ =0x00001841
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r7, .L0800549C @ =0x00001F01
    adds r1, r7, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .L080054A0 @ =0x0600F800
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    ldr r1, .L080054A4 @ =0x06FFC000
    movs r0, #0
    movs r2, #0x20
    bl func_08008EB8
    movs r0, #0
    mov r8, r0
    add r5, sp, #0x20
    add r1, sp, #0x24
    mov sb, r1
    mov r2, sp
    adds r2, #0x28
    str r2, [sp, #0x64]
    mov r3, sp
    adds r3, #0x2c
    str r3, [sp, #0x68]
    mov r4, sp
    adds r4, #0x30
    str r4, [sp, #0x70]
    mov r7, sp
    adds r7, #0x34
    str r7, [sp, #0x74]
    mov r0, sp
    adds r0, #0x38
    str r0, [sp, #0x78]
    mov r1, sp
    adds r1, #0x10
    str r1, [sp, #0x5c]
    movs r7, #0xc
    movs r6, #2
    mov r4, sl
    adds r4, #0xc
.L0800532E:
    add r0, sp, #0x20
    strh r7, [r0]
    strh r6, [r5, #2]
    ldr r0, [sp, #0x20]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r2, #0xc1
    lsls r2, r2, #2
    adds r4, r4, r2
    movs r3, #1
    add r8, r3
    mov r0, r8
    cmp r0, #3
    bls .L0800532E
    movs r1, #0
    mov r8, r1
    ldr r7, .L080054A8 @ =0x00000C1C
    add r7, sl
    movs r2, #0xfa
    lsls r2, r2, #4
    add r2, sl
    str r2, [sp, #0x54]
    ldr r3, .L080054AC @ =0x00001324
    add r3, sl
    str r3, [sp, #0x58]
    ldr r4, .L080054B0 @ =0x000016A8
    add r4, sl
    str r4, [sp, #0x6c]
    movs r6, #0xe
    movs r5, #2
    ldr r4, .L080054A8 @ =0x00000C1C
    add r4, sl
.L08005372:
    add r0, sp, #0x24
    strh r6, [r0]
    mov r0, sb
    strh r5, [r0, #2]
    ldr r0, [sp, #0x24]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r1, #0xe1
    lsls r1, r1, #2
    adds r4, r4, r1
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #3
    bls .L08005372
    movs r4, #0
    mov r8, r4
    movs r6, #0xc
    movs r5, #2
    mov r4, sl
    adds r4, #0xc
.L080053A0:
    mov r0, r8
    lsls r1, r0, #4
    add r1, sl
    ldr r2, .L080054B4 @ =0x00001A34
    adds r1, r1, r2
    add r0, sp, #0x28
    strh r6, [r0]
    ldr r3, [sp, #0x64]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x28]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r0, #0xc1
    lsls r0, r0, #2
    adds r4, r4, r0
    movs r1, #1
    add r8, r1
    mov r2, r8
    cmp r2, #3
    bls .L080053A0
    ldr r1, .L080054B8 @ =gText_NewGameIdentity_PlayerName
    movs r4, #0xe
    movs r5, #2
    add r0, sp, #0x2c
    strh r4, [r0]
    ldr r3, [sp, #0x68]
    strh r5, [r3, #2]
    ldr r0, [sp, #0x2c]
    str r1, [sp]
    adds r1, r7, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054BC @ =gText_NewGameIdentity_PlayerBirthday
    add r0, sp, #0x30
    strh r4, [r0]
    ldr r7, [sp, #0x70]
    strh r5, [r7, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x54]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054C0 @ =gText_NewGameIdentity_FarmName
    add r0, sp, #0x34
    strh r4, [r0]
    ldr r0, [sp, #0x74]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    ldr r1, [sp, #0x58]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    ldr r1, .L080054C4 @ =gText_NewGameIdentity_DogName
    add r0, sp, #0x38
    strh r4, [r0]
    ldr r2, [sp, #0x78]
    strh r5, [r2, #2]
    ldr r0, [sp, #0x38]
    str r1, [sp]
    ldr r1, [sp, #0x6c]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    movs r3, #0
    mov r8, r3
    ldr r4, [sp, #0x5c]
    str r4, [sp, #0x4c]
    movs r5, #0xc0
    lsls r5, r5, #0x13
    str r5, [sp, #0x84]
    mov r7, sl
    adds r7, #0xc
    str r7, [sp, #0x88]
.L08005448:
    mov r0, sl
    bl func_08008910
    adds r6, r0, #0
    add r0, sp, #0x10
    ldr r1, [sp, #0x88]
    ldr r2, [sp, #0x84]
    movs r3, #0xc0
    lsls r3, r3, #2
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L080054C8
    cmp r1, #0
    beq .L08005476
    adds r0, r1, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08005476:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    movs r5, #0xc0
    lsls r5, r5, #2
    lsls r5, r5, #2
    str r5, [sp, #0x60]
    b .L08005596
    .align 2, 0
.L08005488: .4byte gUiSharedTiles
.L0800548C: .4byte 0x06004B00
.L08005490: .4byte gUiSharedTileByteCount
.L08005494: .4byte gUiSharedPalette
.L08005498: .4byte 0x00001841
.L0800549C: .4byte 0x00001F01
.L080054A0: .4byte 0x0600F800
.L080054A4: .4byte 0x06FFC000
.L080054A8: .4byte 0x00000C1C
.L080054AC: .4byte 0x00001324
.L080054B0: .4byte 0x000016A8
.L080054B4: .4byte 0x00001A34
.L080054B8: .4byte gText_NewGameIdentity_PlayerName
.L080054BC: .4byte gText_NewGameIdentity_PlayerBirthday
.L080054C0: .4byte gText_NewGameIdentity_FarmName
.L080054C4: .4byte gText_NewGameIdentity_DogName
.L080054C8:
    str r1, [sp, #0x8c]
    movs r0, #1
    str r0, [sp, #0x40]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x3c]
    add r1, sp, #0x40
    add r0, sp, #0x3c
    cmp r4, #1
    bhs .L080054E2
    adds r0, r1, #0
.L080054E2:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005500
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005504
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005504
.L08005500:
    movs r0, #0
    mov sb, r0
.L08005504:
    adds r5, r0, #0
    str r5, [sp, #0x90]
    ldr r2, [r6]
    adds r3, r5, #0
    movs r0, #0xc0
    lsls r0, r0, #2
    lsls r0, r0, #2
    str r0, [sp, #0x60]
    ldr r1, [sp, #0x8c]
    cmp r2, r1
    beq .L08005534
.L0800551A:
    cmp r3, #0
    beq .L0800552A
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800552A:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x8c]
    cmp r2, r0
    bne .L0800551A
.L08005534:
    adds r5, r3, #0
    ldr r0, [sp, #0x40]
    cmp r0, #1
    bne .L08005550
    cmp r5, #0
    beq .L0800554C
    adds r0, r5, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800554C:
    adds r5, #0x10
    b .L08005572
.L08005550:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08005570
.L08005558:
    cmp r2, #0
    beq .L08005568
    adds r0, r2, #0
    ldr r1, [sp, #0x4c]
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005568:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005558
.L08005570:
    adds r5, r2, #0
.L08005572:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08005582
.L0800557C:
    adds r1, #0x10
    cmp r1, r2
    bne .L0800557C
.L08005582:
    cmp r0, #0
    beq .L0800558A
    bl free
.L0800558A:
    ldr r0, [sp, #0x90]
    add r0, sb
    ldr r7, [sp, #0x90]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08005596:
    ldr r0, [sp, #0x84]
    movs r1, #0xc0
    lsls r1, r1, #2
    adds r0, r0, r1
    str r0, [sp, #0x84]
    ldr r2, [sp, #0x88]
    movs r3, #0xc1
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x88]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #3
    bhi .L080055B6
    b .L08005448
.L080055B6:
    movs r7, #0
    mov r8, r7
    mov r0, sp
    adds r0, #0xc
    str r0, [sp, #0x50]
    movs r0, #0xc0
    lsls r0, r0, #0x13
    ldr r1, [sp, #0x60]
    adds r0, r1, r0
    str r0, [sp, #0x7c]
    ldr r2, .L08005608 @ =0x00000C1C
    add r2, sl
    str r2, [sp, #0x80]
.L080055D0:
    mov r0, sl
    bl func_08008910
    adds r6, r0, #0
    add r0, sp, #0xc
    ldr r1, [sp, #0x80]
    ldr r2, [sp, #0x7c]
    movs r3, #0xe0
    lsls r3, r3, #2
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L0800560C
    cmp r1, #0
    beq .L080055FE
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r3, r4, r5}
    stm r0!, {r3, r4, r5}
    ldr r1, [r1]
    str r1, [r0]
.L080055FE:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L080056CE
    .align 2, 0
.L08005608: .4byte 0x00000C1C
.L0800560C:
    str r1, [sp, #0x8c]
    movs r0, #1
    str r0, [sp, #0x48]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x44]
    add r1, sp, #0x48
    add r0, sp, #0x44
    cmp r4, #1
    bhs .L08005626
    adds r0, r1, #0
.L08005626:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005644
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005648
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005648
.L08005644:
    movs r0, #0
    mov sb, r0
.L08005648:
    adds r5, r0, #0
    str r5, [sp, #0x90]
    ldr r2, [r6]
    adds r3, r5, #0
    b .L08005666
.L08005652:
    cmp r3, #0
    beq .L08005662
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005662:
    adds r2, #0x10
    adds r3, #0x10
.L08005666:
    ldr r0, [sp, #0x8c]
    cmp r2, r0
    bne .L08005652
    adds r5, r3, #0
    ldr r0, [sp, #0x48]
    cmp r0, #1
    bne .L08005688
    cmp r5, #0
    beq .L08005684
    adds r0, r5, #0
    ldr r1, [sp, #0x50]
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08005684:
    adds r5, #0x10
    b .L080056AA
.L08005688:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L080056A8
.L08005690:
    cmp r2, #0
    beq .L080056A0
    adds r0, r2, #0
    ldr r1, [sp, #0x50]
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080056A0:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005690
.L080056A8:
    adds r5, r2, #0
.L080056AA:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L080056BA
.L080056B4:
    adds r1, #0x10
    cmp r1, r2
    bne .L080056B4
.L080056BA:
    cmp r0, #0
    beq .L080056C2
    bl free
.L080056C2:
    ldr r0, [sp, #0x90]
    add r0, sb
    ldr r7, [sp, #0x90]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L080056CE:
    ldr r0, [sp, #0x7c]
    movs r1, #0xe0
    lsls r1, r1, #2
    adds r0, r0, r1
    str r0, [sp, #0x7c]
    ldr r2, [sp, #0x80]
    movs r3, #0xe1
    lsls r3, r3, #2
    adds r2, r2, r3
    str r2, [sp, #0x80]
    movs r4, #1
    add r8, r4
    mov r5, r8
    cmp r5, #3
    bhi .L080056EE
    b .L080055D0
.L080056EE:
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L080057E8 @ =0x0600C000
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl func_08008EB8
    movs r7, #0
    mov r8, r7
    movs r1, #0x64
.L08005704:
    movs r5, #0
    mov r2, r8
    lsls r0, r2, #6
    adds r0, r0, r4
.L0800570C:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r5, #0x1d
    bls .L0800570C
    movs r3, #1
    add r8, r3
    mov r5, r8
    cmp r5, #0x13
    bls .L08005704
    movs r5, #2
    ldr r6, .L080057EC @ =0x0600C080
.L08005724:
    movs r7, #0
    mov r8, r7
    lsls r1, r5, #1
    adds r4, r5, #0
    adds r4, #0x6c
    adds r3, r5, #0
    adds r3, #0x5e
    ldr r0, .L080057F0 @ =0x0600C040
    adds r2, r1, r0
.L08005736:
    strh r3, [r2]
    adds r0, r1, r6
    strh r4, [r0]
    adds r4, #0x1c
    adds r3, #0x1c
    adds r2, #0xc0
    adds r1, #0xc0
    movs r7, #1
    add r8, r7
    mov r0, r8
    cmp r0, #3
    bls .L08005736
    adds r5, #1
    cmp r5, #0xf
    bls .L08005724
    movs r5, #0x10
    ldr r1, .L080057F4 @ =0x0000FFF0
    adds r7, r1, #0
    ldr r2, .L080057EC @ =0x0600C080
    mov sb, r2
.L0800575E:
    movs r3, #0
    mov r8, r3
    lsls r1, r5, #1
    adds r6, r5, #1
    adds r0, r5, #0
    adds r0, #0xc
    adds r4, r0, r7
    adds r3, r5, r7
    ldr r5, .L080057F0 @ =0x0600C040
    adds r2, r1, r5
.L08005772:
    strh r3, [r2]
    mov r5, sb
    adds r0, r1, r5
    strh r4, [r0]
    adds r4, #0x18
    adds r3, #0x18
    adds r2, #0xc0
    adds r1, #0xc0
    movs r0, #1
    add r8, r0
    mov r5, r8
    cmp r5, #3
    bls .L08005772
    adds r5, r6, #0
    cmp r5, #0x1b
    bls .L0800575E
    ldr r0, .L080057F8 @ =0x00001A2C
    add r0, sl
    ldr r0, [r0]
    mov sb, r0
    mov r0, sl
    bl func_080088DC
    mov r8, r0
    mov r0, sl
    bl func_08008920
    adds r6, r0, #0
    mov r0, sl
    bl func_08008918
    adds r5, r0, #0
    mov r0, sl
    bl func_08008940
    adds r4, r0, #0
    mov r0, sl
    bl func_0800894C
    ldr r1, .L080057FC @ =0x00001A30
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x94
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L080057E8: .4byte 0x0600C000
.L080057EC: .4byte 0x0600C080
.L080057F0: .4byte 0x0600C040
.L080057F4: .4byte 0x0000FFF0
.L080057F8: .4byte 0x00001A2C
.L080057FC: .4byte 0x00001A30

    .section .text.new_game_name_input_after_core_run
    thumb_func_start func_08005CDC
func_08005CDC: @ 0x08005CDC
    .ifdef REGION_DE
.LNewGameDE_08005CEC:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #84
mov	sl, r0
ldr	r0, [pc, #472]
ldr	r0, [r0, #0]
ldr	r1, [pc, #472]
ldr	r2, [pc, #472]
ldr	r2, [r2, #0]
bl	func_08008E64
ldr	r0, [pc, #468]
ldr	r0, [r0, #0]
movs	r1, #160
lsls	r1, r1, #19
movs	r2, #32
bl	func_08008E64
mov	r0, sl
bl	func_08008918
.LNewGameDE_08005D1C:
add	r1, sp, #12
movs	r3, #186
lsls	r3, r3, #5
adds	r2, r3, #0
strh	r2, [r1, #0]
movs	r4, #0
strh	r2, [r0, #0]
mov	r0, sl
bl	func_08008918
.LNewGameDE_08005D30:
add	r2, sp, #12
ldr	r5, [pc, #432]
adds	r1, r5, #0
strh	r1, [r2, #0]
strh	r1, [r0, #10]
mov	r0, sl
bl	func_08008918
add	r2, sp, #12
ldr	r7, [pc, #420]
adds	r1, r7, #0
strh	r1, [r2, #0]
strh	r1, [r0, #12]
ldr	r0, [pc, #416]
movs	r1, #20
str	r1, [sp, #0]
movs	r1, #155
lsls	r1, r1, #2
str	r1, [sp, #4]
str	r4, [sp, #8]
movs	r1, #0
movs	r2, #0
movs	r3, #30
bl	DrawUiTextWindowBorder
movs	r0, #1
negs	r0, r0
ldr	r4, [pc, #392]
movs	r2, #128
lsls	r2, r2, #4
adds	r1, r4, #0
bl	func_08008EB8
movs	r1, #0
add	r0, sp, #32
mov	r8, r0
add	r2, sp, #36
mov	r9, r2
mov	r3, sp
adds	r3, #16
str	r3, [sp, #64]
mov	r5, sp
adds	r5, #48
str	r5, [sp, #68]
mov	r7, sl
adds	r7, #12
ldr	r0, [pc, #356]
add	r0, sl
str	r0, [sp, #72]
movs	r6, #28
.LNewGameDE_08005D94:
movs	r3, #0
lsls	r2, r1, #6
adds	r5, r1, #1
adds	r0, r2, r4
.LNewGameDE_08005D9C:
strh	r6, [r0, #0]
adds	r0, #2
adds	r3, #1
cmp	r3, #29
bls.n	.LNewGameDE_08005D9C
adds	r1, r5, #0
cmp	r1, #19
bls.n	.LNewGameDE_08005D94
movs	r3, #10
ldr	r2, [pc, #328]
ldr	r1, [pc, #328]
.LNewGameDE_08005DB2:
strh	r3, [r1, #0]
adds	r0, r3, #0
adds	r0, #30
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #15
bls.n	.LNewGameDE_08005DB2
.LNewGameDE_08005DC4:
movs	r3, #3
movs	r1, #240
lsls	r1, r1, #1
adds	r5, r1, #0
movs	r2, #255
lsls	r2, r2, #1
adds	r4, r2, #0
ldr	r2, [pc, #300]
ldr	r1, [pc, #300]
.LNewGameDE_08005DD6:
adds	r0, r3, r5
strh	r0, [r1, #0]
adds	r0, r3, r4
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #26
bls.n	.LNewGameDE_08005DD6
movs	r1, #4
ldr	r4, [pc, #260]
.LNewGameDE_08005DEC:
movs	r3, #0
lsls	r2, r1, #6
adds	r5, r1, #1
subs	r1, #2
lsls	r0, r1, #4
subs	r0, r0, r1
lsls	r1, r0, #1
adds	r2, r2, r4
.LNewGameDE_08005DFC:
adds	r0, r1, r3
strh	r0, [r2, #0]
adds	r2, #2
adds	r3, #1
cmp	r3, #29
bls.n	.LNewGameDE_08005DFC
adds	r1, r5, #0
cmp	r1, #17
bls.n	.LNewGameDE_08005DEC
movs	r3, #18
movs	r4, #135
lsls	r4, r4, #2
adds	r5, r4, #0
ldr	r0, [pc, #240]
adds	r4, r0, #0
ldr	r2, [pc, #240]
ldr	r1, [pc, #240]
.LNewGameDE_08005E1E:
adds	r0, r3, r5
strh	r0, [r1, #0]
adds	r0, r3, r4
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #29
bls.n	.LNewGameDE_08005E1E
movs	r0, #155
lsls	r0, r0, #7
add	r0, sl
ldr	r0, [r0, #0]
cmp	r0, #0
beq.n	.LNewGameDE_08005E5E
movs	r3, #1
ldr	r1, [pc, #212]
adds	r5, r1, #0
movs	r2, #152
lsls	r2, r2, #2
adds	r4, r2, #0
ldr	r2, [pc, #204]
ldr	r1, [pc, #208]
.LNewGameDE_08005E4C:
adds	r0, r3, r5
strh	r0, [r1, #0]
adds	r0, r3, r4
strh	r0, [r2, #0]
adds	r2, #2
adds	r1, #2
adds	r3, #1
cmp	r3, #9
bls.n	.LNewGameDE_08005E4C
.LNewGameDE_08005E5E:
ldr	r1, [pc, #192]
movs	r0, #0
movs	r2, #32
bl	func_08008EB8
movs	r4, #30
movs	r5, #2
add	r0, sp, #32
strh	r4, [r0, #0]
mov	r3, r8
strh	r5, [r3, #2]
ldr	r0, [sp, #32]
adds	r1, r7, #0
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r1, [pc, #164]
add	r0, sp, #36
strh	r4, [r0, #0]
mov	r4, r9
strh	r5, [r4, #2]
ldr	r0, [sp, #36]
str	r1, [sp, #0]
adds	r1, r7, #0
movs	r2, #88
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
mov	r0, sl
bl	func_08008910
movs	r3, #240
lsls	r3, r3, #3
adds	r6, r0, #0
add	r0, sp, #16
adds	r1, r7, #0
movs	r2, #192
lsls	r2, r2, #19
bl	__21DmaTransferDescriptorPCvPvUi
ldr	r5, [sp, #64]
mov	r8, r5
ldr	r1, [r6, #4]
ldr	r0, [r6, #12]
cmp	r1, r0
beq.n	.LNewGameDE_08005F28
cmp	r1, #0
beq.n	.LNewGameDE_08005ECA
adds	r0, r1, #0
mov	r1, r8
ldmia	r1!, {r2, r3, r7}
stmia	r0!, {r2, r3, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08005ECA:
ldr	r0, [r6, #4]
adds	r0, #16
str	r0, [r6, #4]
b.n	.LNewGameDE_08005FEE
    .align 2, 0
.LNewGameDE_08005ED4: .4byte gUiSharedTiles
.LNewGameDE_08005ED8: .4byte 0x06004D80
.LNewGameDE_08005EDC: .4byte gUiSharedTileByteCount
.LNewGameDE_08005EE0: .4byte gUiSharedPalette
.LNewGameDE_08005EE4: .4byte 0x00001841
.LNewGameDE_08005EE8: .4byte 0x00001F02
.LNewGameDE_08005EEC: .4byte 0x0600F800
.LNewGameDE_08005EF0: .4byte 0x0600C000
.LNewGameDE_08005EF4: .4byte 0x00004B34
.LNewGameDE_08005EF8: .4byte 0x0600C094
.LNewGameDE_08005EFC: .4byte 0x0600C054
.LNewGameDE_08005F00: .4byte 0x0600C4C6
.LNewGameDE_08005F04: .4byte 0x0600C486
.LNewGameDE_08005F08: .4byte 0x0000023A
.LNewGameDE_08005F0C: .4byte 0x0600C0A4
.LNewGameDE_08005F10: .4byte 0x0600C064
.LNewGameDE_08005F14: .4byte 0x00000257
.LNewGameDE_08005F18: .4byte 0x0600C082
.LNewGameDE_08005F1C: .4byte 0x0600C042
.LNewGameDE_08005F20: .4byte 0x06FFC000
.LNewGameDE_08005F24: .4byte gText_NewGameNameEntry_NameLabel
.LNewGameDE_08005F28:
str	r1, [sp, #76]
movs	r0, #1
str	r0, [sp, #44]
ldr	r0, [r6, #0]
adds	r4, r1, #0
subs	r0, r4, r0
asrs	r4, r0, #4
str	r4, [sp, #40]
add	r1, sp, #44
add	r0, sp, #40
cmp	r4, #1
bcs.n	.LNewGameDE_08005F42
adds	r0, r1, #0
.LNewGameDE_08005F42:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_08005F60
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r9, r4
cmp	r0, #0
bne.n	.LNewGameDE_08005F64
mov	r0, r9
bl	RetryMemoryAllocation
b.n	.LNewGameDE_08005F64
.LNewGameDE_08005F60:
movs	r0, #0
mov	r9, r0
.LNewGameDE_08005F64:
adds	r5, r0, #0
str	r5, [sp, #80]
ldr	r2, [r6, #0]
adds	r3, r5, #0
ldr	r5, [sp, #76]
cmp	r2, r5
beq.n	.LNewGameDE_08005F8C
.LNewGameDE_08005F72:
cmp	r3, #0
beq.n	.LNewGameDE_08005F82
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08005F82:
adds	r2, #16
adds	r3, #16
ldr	r7, [sp, #76]
cmp	r2, r7
bne.n	.LNewGameDE_08005F72
.LNewGameDE_08005F8C:
adds	r5, r3, #0
ldr	r0, [sp, #44]
cmp	r0, #1
bne.n	.LNewGameDE_08005FA8
cmp	r5, #0
beq.n	.LNewGameDE_08005FA4
adds	r0, r5, #0
mov	r1, r8
ldmia	r1!, {r2, r3, r4}
stmia	r0!, {r2, r3, r4}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08005FA4:
adds	r5, #16
b.n	.LNewGameDE_08005FCA
.LNewGameDE_08005FA8:
adds	r3, r0, #0
adds	r2, r5, #0
cmp	r3, #0
beq.n	.LNewGameDE_08005FC8
.LNewGameDE_08005FB0:
cmp	r2, #0
beq.n	.LNewGameDE_08005FC0
adds	r0, r2, #0
mov	r1, r8
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08005FC0:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_08005FB0
.LNewGameDE_08005FC8:
adds	r5, r2, #0
.LNewGameDE_08005FCA:
ldr	r2, [r6, #4]
ldr	r0, [r6, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_08005FDA
.LNewGameDE_08005FD4:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_08005FD4
.LNewGameDE_08005FDA:
cmp	r0, #0
beq.n	.LNewGameDE_08005FE2
bl	free
.LNewGameDE_08005FE2:
ldr	r0, [sp, #80]
add	r0, r9
ldr	r7, [sp, #80]
str	r7, [r6, #0]
str	r5, [r6, #4]
str	r0, [r6, #12]
.LNewGameDE_08005FEE:
ldr	r1, [pc, #152]
add	r1, sl
movs	r0, #0
str	r0, [r1, #0]
ldr	r0, [pc, #148]
add	r0, sl
movs	r1, #1
mov	r8, r1
mov	r2, r8
strb	r2, [r0, #0]
mov	r0, sl
bl	func_080064E8
movs	r7, #240
lsls	r7, r7, #3
movs	r5, #9
movs	r6, #2
add	r0, sp, #48
strh	r5, [r0, #0]
ldr	r3, [sp, #68]
strh	r6, [r3, #2]
ldr	r0, [sp, #48]
ldr	r4, [sp, #72]
adds	r1, r4, #0
movs	r2, #0
bl	Clear2DGfxBuffer
movs	r0, #155
lsls	r0, r0, #7
add	r0, sl
ldr	r1, [r0, #0]
cmp	r1, #0
beq.n	.LNewGameDE_08006044
add	r0, sp, #52
strh	r5, [r0, #0]
strh	r6, [r0, #2]
ldr	r0, [sp, #52]
str	r1, [sp, #0]
adds	r1, r4, #0
movs	r2, #0
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
.LNewGameDE_08006044:
mov	r0, sl
bl	func_08008910
movs	r3, #144
lsls	r3, r3, #2
adds	r6, r0, #0
lsls	r2, r7, #2
adds	r2, r7, r2
lsls	r2, r2, #1
movs	r0, #192
lsls	r0, r0, #19
adds	r2, r2, r0
add	r0, sp, #12
ldr	r1, [sp, #72]
bl	__21DmaTransferDescriptorPCvPvUi
add	r4, sp, #12
mov	r9, r4
ldr	r1, [r6, #4]
ldr	r0, [r6, #12]
cmp	r1, r0
beq.n	.LNewGameDE_08006090
cmp	r1, #0
beq.n	.LNewGameDE_08006080
adds	r0, r1, #0
add	r1, sp, #12
ldmia	r1!, {r2, r5, r7}
stmia	r0!, {r2, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006080:
ldr	r0, [r6, #4]
adds	r0, #16
str	r0, [r6, #4]
b.n	.LNewGameDE_08006156
.LNewGameDE_08006088: .4byte 0x00004D84
.LNewGameDE_0800608C: .4byte 0x00004DBB
.LNewGameDE_08006090:
str	r1, [sp, #76]
mov	r3, r8
str	r3, [sp, #60]
ldr	r0, [r6, #0]
adds	r4, r1, #0
subs	r0, r4, r0
asrs	r4, r0, #4
str	r4, [sp, #56]
add	r1, sp, #60
add	r0, sp, #56
cmp	r4, #1
bcs.n	.LNewGameDE_080060AA
adds	r0, r1, #0
.LNewGameDE_080060AA:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_080060C8
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r8, r4
cmp	r0, #0
bne.n	.LNewGameDE_080060CC
mov	r0, r8
bl	RetryMemoryAllocation
b.n	.LNewGameDE_080060CC
.LNewGameDE_080060C8:
movs	r0, #0
mov	r8, r0
.LNewGameDE_080060CC:
adds	r5, r0, #0
str	r5, [sp, #80]
ldr	r2, [r6, #0]
adds	r3, r5, #0
ldr	r5, [sp, #76]
cmp	r2, r5
beq.n	.LNewGameDE_080060F4
.LNewGameDE_080060DA:
cmp	r3, #0
beq.n	.LNewGameDE_080060EA
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_080060EA:
adds	r2, #16
adds	r3, #16
ldr	r7, [sp, #76]
cmp	r2, r7
bne.n	.LNewGameDE_080060DA
.LNewGameDE_080060F4:
adds	r5, r3, #0
ldr	r0, [sp, #60]
cmp	r0, #1
bne.n	.LNewGameDE_08006110
cmp	r5, #0
beq.n	.LNewGameDE_0800610C
adds	r0, r5, #0
mov	r1, r9
ldmia	r1!, {r2, r3, r4}
stmia	r0!, {r2, r3, r4}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800610C:
adds	r5, #16
b.n	.LNewGameDE_08006132
.LNewGameDE_08006110:
adds	r3, r0, #0
adds	r2, r5, #0
cmp	r3, #0
beq.n	.LNewGameDE_08006130
.LNewGameDE_08006118:
cmp	r2, #0
beq.n	.LNewGameDE_08006128
adds	r0, r2, #0
mov	r1, r9
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006128:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_08006118
.LNewGameDE_08006130:
adds	r5, r2, #0
.LNewGameDE_08006132:
ldr	r2, [r6, #4]
ldr	r0, [r6, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_08006142
.LNewGameDE_0800613C:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_0800613C
.LNewGameDE_08006142:
cmp	r0, #0
beq.n	.LNewGameDE_0800614A
bl	free
.LNewGameDE_0800614A:
ldr	r0, [sp, #80]
add	r0, r8
ldr	r7, [sp, #80]
str	r7, [r6, #0]
str	r5, [r6, #4]
str	r0, [r6, #12]
.LNewGameDE_08006156:
ldr	r0, [pc, #84]
add	r0, sl
ldr	r0, [r0, #0]
mov	r9, r0
mov	r0, sl
bl	func_080088DC
mov	r8, r0
mov	r0, sl
bl	func_08008920
adds	r6, r0, #0
mov	r0, sl
bl	func_08008918
adds	r5, r0, #0
mov	r0, sl
bl	func_08008940
adds	r4, r0, #0
mov	r0, sl
bl	func_0800894C
ldr	r1, [pc, #40]
add	r1, sl
str	r4, [sp, #0]
str	r0, [sp, #4]
str	r1, [sp, #8]
mov	r0, r9
mov	r1, r8
adds	r2, r6, #0
adds	r3, r5, #0
bl	Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
add	sp, #84
pop	{r3, r4, r5}
mov	r8, r3
mov	r9, r4
mov	sl, r5
pop	{r4, r5, r6, r7}
pop	{r0}
bx	r0
    .align 2, 0
.LNewGameDE_080061AC: .4byte 0x00004D7C
.LNewGameDE_080061B0: .4byte 0x00004D74

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x54
    mov sl, r0
    ldr r0, .L08005EC8 @ =gUiSharedTiles
    ldr r0, [r0]
    ldr r1, .L08005ECC @ =0x06004B00
    ldr r2, .L08005ED0 @ =gUiSharedTileByteCount
    ldr r2, [r2]
    bl func_08008E64
    ldr r0, .L08005ED4 @ =gUiSharedPalette
    ldr r0, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x20
    bl func_08008E64
    mov r0, sl
    bl func_08008918
    add r1, sp, #0xc
    movs r3, #0xba
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r5, .L08005ED8 @ =0x00001841
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    mov r0, sl
    bl func_08008918
    add r2, sp, #0xc
    ldr r7, .L08005EDC @ =0x00001F02
    adds r1, r7, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    ldr r0, .L08005EE0 @ =0x0600F800
    movs r1, #0x14
    str r1, [sp]
    movs r1, #0x96
    lsls r1, r1, #2
    str r1, [sp, #4]
    str r4, [sp, #8]
    movs r1, #0
    movs r2, #0
    movs r3, #0x1e
    bl DrawUiTextWindowBorder
    movs r0, #1
    rsbs r0, r0, #0
    ldr r4, .L08005EE4 @ =0x0600C000
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r4, #0
    bl func_08008EB8
    movs r1, #0
    add r0, sp, #0x20
    mov r8, r0
    add r2, sp, #0x24
    mov sb, r2
    mov r3, sp
    adds r3, #0x10
    str r3, [sp, #0x44]
    mov r5, sp
    adds r5, #0x30
    str r5, [sp, #0x48]
    mov r7, sl
    adds r7, #0xc
    ldr r0, .L08005EE8 @ =0x000043B0
    add r0, sl
    str r0, [sp, #0x40]
    movs r2, #0xd1
    lsls r2, r2, #1
    adds r6, r2, #0
.L08005D88:
    movs r3, #0
    lsls r2, r1, #6
    adds r5, r1, #1
    adds r0, r2, r4
.L08005D90:
    strh r6, [r0]
    adds r0, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005D90
    adds r1, r5, #0
    cmp r1, #0x13
    bls .L08005D88
    movs r3, #0xa
    ldr r2, .L08005EEC @ =0x0600C094
    ldr r1, .L08005EF0 @ =0x0600C054
.L08005DA6:
    strh r3, [r1]
    adds r0, r3, #0
    adds r0, #0x1e
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0xf
    bls .L08005DA6
    movs r3, #3
    movs r4, #0xd2
    lsls r4, r4, #1
    adds r5, r4, #0
    movs r0, #0xe1
    lsls r0, r0, #1
    adds r4, r0, #0
    ldr r2, .L08005EF4 @ =0x0600C486
    ldr r1, .L08005EF8 @ =0x0600C446
.L08005DCA:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0x1a
    bls .L08005DCA
    movs r1, #4
    ldr r4, .L08005EE4 @ =0x0600C000
.L08005DE0:
    movs r3, #0
    lsls r2, r1, #6
    adds r5, r1, #1
    subs r1, #2
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r1, r0, #1
    adds r2, r2, r4
.L08005DF0:
    adds r0, r1, r3
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005DF0
    adds r1, r5, #0
    cmp r1, #0xf
    bls .L08005DE0
    movs r3, #0x12
    movs r1, #0xf0
    lsls r1, r1, #1
    adds r5, r1, #0
    movs r2, #0xff
    lsls r2, r2, #1
    adds r4, r2, #0
    ldr r2, .L08005EFC @ =0x0600C0A4
    ldr r1, .L08005F00 @ =0x0600C064
.L08005E14:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #0x1d
    bls .L08005E14
    ldr r0, .L08005F04 @ =0x000045FC
    add r0, sl
    ldr r0, [r0]
    cmp r0, #0
    beq .L08005E52
    movs r3, #1
    ldr r4, .L08005F08 @ =0x0000021B
    adds r5, r4, #0
    movs r0, #0x89
    lsls r0, r0, #2
    adds r4, r0, #0
    ldr r2, .L08005F0C @ =0x0600C082
    ldr r1, .L08005F10 @ =0x0600C042
.L08005E40:
    adds r0, r3, r5
    strh r0, [r1]
    adds r0, r3, r4
    strh r0, [r2]
    adds r2, #2
    adds r1, #2
    adds r3, #1
    cmp r3, #9
    bls .L08005E40
.L08005E52:
    ldr r1, .L08005F14 @ =0x06FFC000
    movs r0, #0
    movs r2, #0x20
    bl func_08008EB8
    movs r4, #0x1e
    movs r5, #2
    add r0, sp, #0x20
    strh r4, [r0]
    mov r1, r8
    strh r5, [r1, #2]
    ldr r0, [sp, #0x20]
    adds r1, r7, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .L08005F18 @ =gText_NewGameNameEntry_NameLabel
    add r0, sp, #0x24
    strh r4, [r0]
    mov r2, sb
    strh r5, [r2, #2]
    ldr r0, [sp, #0x24]
    str r1, [sp]
    adds r1, r7, #0
    movs r2, #0x58
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl func_08008910
    movs r3, #0xf0
    lsls r3, r3, #3
    adds r6, r0, #0
    add r0, sp, #0x10
    adds r1, r7, #0
    movs r2, #0xc0
    lsls r2, r2, #0x13
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r3, [sp, #0x44]
    mov r8, r3
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08005F1C
    cmp r1, #0
    beq .L08005EBE
    adds r0, r1, #0
    mov r1, r8
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005EBE:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L08005FE0
    .align 2, 0
.L08005EC8: .4byte gUiSharedTiles
.L08005ECC: .4byte 0x06004B00
.L08005ED0: .4byte gUiSharedTileByteCount
.L08005ED4: .4byte gUiSharedPalette
.L08005ED8: .4byte 0x00001841
.L08005EDC: .4byte 0x00001F02
.L08005EE0: .4byte 0x0600F800
.L08005EE4: .4byte 0x0600C000
.L08005EE8: .4byte 0x000043B0
.L08005EEC: .4byte 0x0600C094
.L08005EF0: .4byte 0x0600C054
.L08005EF4: .4byte 0x0600C486
.L08005EF8: .4byte 0x0600C446
.L08005EFC: .4byte 0x0600C0A4
.L08005F00: .4byte 0x0600C064
.L08005F04: .4byte 0x000045FC
.L08005F08: .4byte 0x0000021B
.L08005F0C: .4byte 0x0600C082
.L08005F10: .4byte 0x0600C042
.L08005F14: .4byte 0x06FFC000
.L08005F18: .4byte gText_NewGameNameEntry_NameLabel
.L08005F1C:
    str r1, [sp, #0x4c]
    movs r0, #1
    str r0, [sp, #0x2c]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x28]
    add r1, sp, #0x2c
    add r0, sp, #0x28
    cmp r4, #1
    bhs .L08005F34
    adds r0, r1, #0
.L08005F34:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08005F52
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08005F56
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08005F56
.L08005F52:
    movs r0, #0
    mov sb, r0
.L08005F56:
    adds r5, r0, #0
    str r5, [sp, #0x50]
    ldr r2, [r6]
    adds r3, r5, #0
    ldr r4, [sp, #0x4c]
    cmp r2, r4
    beq .L08005F7E
.L08005F64:
    cmp r3, #0
    beq .L08005F74
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005F74:
    adds r2, #0x10
    adds r3, #0x10
    ldr r5, [sp, #0x4c]
    cmp r2, r5
    bne .L08005F64
.L08005F7E:
    adds r5, r3, #0
    ldr r0, [sp, #0x2c]
    cmp r0, #1
    bne .L08005F9A
    cmp r5, #0
    beq .L08005F96
    adds r0, r5, #0
    mov r1, r8
    ldm r1!, {r2, r3, r7}
    stm r0!, {r2, r3, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005F96:
    adds r5, #0x10
    b .L08005FBC
.L08005F9A:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08005FBA
.L08005FA2:
    cmp r2, #0
    beq .L08005FB2
    adds r0, r2, #0
    mov r1, r8
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08005FB2:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08005FA2
.L08005FBA:
    adds r5, r2, #0
.L08005FBC:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08005FCC
.L08005FC6:
    adds r1, #0x10
    cmp r1, r2
    bne .L08005FC6
.L08005FCC:
    cmp r0, #0
    beq .L08005FD4
    bl free
.L08005FD4:
    ldr r0, [sp, #0x50]
    add r0, sb
    ldr r1, [sp, #0x50]
    str r1, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08005FE0:
    movs r1, #0x8c
    lsls r1, r1, #7
    add r1, sl
    movs r0, #0
    str r0, [r1]
    ldr r0, .L08006074 @ =0x00004637
    add r0, sl
    movs r2, #1
    mov r8, r2
    mov r3, r8
    strb r3, [r0]
    mov r0, sl
    bl func_080064E8
    movs r5, #9
    movs r6, #2
    add r0, sp, #0x30
    strh r5, [r0]
    ldr r4, [sp, #0x48]
    strh r6, [r4, #2]
    ldr r0, [sp, #0x30]
    ldr r4, [sp, #0x40]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r0, .L08006078 @ =0x000045FC
    add r0, sl
    ldr r1, [r0]
    cmp r1, #0
    beq .L08006032
    add r0, sp, #0x34
    strh r5, [r0]
    strh r6, [r0, #2]
    ldr r0, [sp, #0x34]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.L08006032:
    mov r0, sl
    bl func_08008910
    movs r3, #0x90
    lsls r3, r3, #2
    adds r6, r0, #0
    movs r2, #0xf0
    lsls r2, r2, #3
    lsls r2, r2, #3
    ldr r5, .L0800607C @ =0x06000780
    adds r2, r2, r5
    add r0, sp, #0xc
    ldr r1, [sp, #0x40]
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #0xc
    mov sb, r7
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08006080
    cmp r1, #0
    beq .L0800606C
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800606C:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L08006142
    .align 2, 0
.L08006074: .4byte 0x00004637
.L08006078: .4byte 0x000045FC
.L0800607C: .4byte 0x06000780
.L08006080:
    str r1, [sp, #0x4c]
    mov r5, r8
    str r5, [sp, #0x3c]
    ldr r0, [r6]
    adds r7, r1, #0
    subs r0, r7, r0
    asrs r4, r0, #4
    str r4, [sp, #0x38]
    add r1, sp, #0x3c
    add r0, sp, #0x38
    cmp r4, #1
    bhs .L0800609A
    adds r0, r1, #0
.L0800609A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080060B8
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L080060BC
    mov r0, r8
    bl RetryMemoryAllocation
    b .L080060BC
.L080060B8:
    movs r0, #0
    mov r8, r0
.L080060BC:
    adds r5, r0, #0
    str r5, [sp, #0x50]
    ldr r2, [r6]
    adds r3, r5, #0
    b .L080060DA
.L080060C6:
    cmp r3, #0
    beq .L080060D6
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080060D6:
    adds r2, #0x10
    adds r3, #0x10
.L080060DA:
    ldr r0, [sp, #0x4c]
    cmp r2, r0
    bne .L080060C6
    adds r5, r3, #0
    ldr r0, [sp, #0x3c]
    cmp r0, #1
    bne .L080060FC
    cmp r5, #0
    beq .L080060F8
    adds r0, r5, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L080060F8:
    adds r5, #0x10
    b .L0800611E
.L080060FC:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L0800611C
.L08006104:
    cmp r2, #0
    beq .L08006114
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006114:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08006104
.L0800611C:
    adds r5, r2, #0
.L0800611E:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0800612E
.L08006128:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006128
.L0800612E:
    cmp r0, #0
    beq .L08006136
    bl free
.L08006136:
    ldr r0, [sp, #0x50]
    add r0, r8
    ldr r7, [sp, #0x50]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L08006142:
    ldr r0, .L08006198 @ =0x000045F8
    add r0, sl
    ldr r0, [r0]
    mov sb, r0
    mov r0, sl
    bl func_080088DC
    mov r8, r0
    mov r0, sl
    bl func_08008920
    adds r6, r0, #0
    mov r0, sl
    bl func_08008918
    adds r5, r0, #0
    mov r0, sl
    bl func_08008940
    adds r4, r0, #0
    mov r0, sl
    bl func_0800894C
    ldr r1, .L0800619C @ =0x000045F0
    add r1, sl
    str r4, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]
    mov r0, sb
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStatePUcT4PP11MusicPlayer
    add sp, #0x54
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08006198: .4byte 0x000045F8
.L0800619C: .4byte 0x000045F0
    .endif

    .section .text.new_game_name_input_after_reset
    thumb_func_start func_0800637C
func_0800637C: @ 0x0800637C
    .ifdef REGION_DE
.LNewGameDE_08006390:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #48
adds	r4, r0, #0
movs	r1, #96
movs	r2, #16
movs	r3, #0
add	r0, sp, #28
movs	r6, #30
movs	r5, #2
mov	r8, r5
strh	r6, [r0, #0]
mov	r7, r8
strh	r7, [r0, #2]
ldr	r0, [sp, #28]
ldr	r7, [pc, #100]
adds	r5, r4, r7
str	r1, [sp, #0]
str	r2, [sp, #4]
str	r3, [sp, #8]
adds	r1, r5, #0
movs	r2, #0
bl	Clear2DGfxBufferRect
ldr	r0, [pc, #88]
adds	r1, r4, r0
add	r0, sp, #32
strh	r6, [r0, #0]
mov	r2, r8
strh	r2, [r0, #2]
ldr	r0, [sp, #32]
str	r1, [sp, #0]
adds	r1, r5, #0
movs	r2, #144
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
adds	r0, r4, #0
bl	func_08008910
adds	r6, r0, #0
movs	r4, #240
lsls	r4, r4, #3
ldr	r2, [pc, #52]
add	r0, sp, #12
adds	r1, r5, #0
adds	r3, r4, #0
bl	__21DmaTransferDescriptorPCvPvUi
add	r3, sp, #12
mov	r9, r3
ldr	r1, [r6, #4]
ldr	r0, [r6, #12]
cmp	r1, r0
beq.n	.LNewGameDE_08006428
cmp	r1, #0
beq.n	.LNewGameDE_08006414
adds	r0, r1, #0
add	r1, sp, #12
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006414:
ldr	r0, [r6, #4]
adds	r0, #16
str	r0, [r6, #4]
b.n	.LNewGameDE_080064E8
.LNewGameDE_0800641C: .4byte 0x000043B0
.LNewGameDE_08006420: .4byte 0x00004DA0
.LNewGameDE_08006424: .4byte 0x06004380
.LNewGameDE_08006428:
mov	sl, r1
movs	r0, #1
str	r0, [sp, #40]
ldr	r0, [r6, #0]
subs	r0, r1, r0
asrs	r4, r0, #4
str	r4, [sp, #36]
add	r1, sp, #40
add	r0, sp, #36
cmp	r4, #1
bcs.n	.LNewGameDE_08006440
adds	r0, r1, #0
.LNewGameDE_08006440:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_0800645E
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r8, r4
cmp	r0, #0
bne.n	.LNewGameDE_08006462
mov	r0, r8
bl	RetryMemoryAllocation
b.n	.LNewGameDE_08006462
.LNewGameDE_0800645E:
movs	r0, #0
mov	r8, r0
.LNewGameDE_08006462:
adds	r5, r0, #0
str	r5, [sp, #44]
ldr	r2, [r6, #0]
adds	r3, r5, #0
cmp	r2, sl
beq.n	.LNewGameDE_08006486
.LNewGameDE_0800646E:
cmp	r3, #0
beq.n	.LNewGameDE_0800647E
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800647E:
adds	r2, #16
adds	r3, #16
cmp	r2, sl
bne.n	.LNewGameDE_0800646E
.LNewGameDE_08006486:
adds	r5, r3, #0
ldr	r0, [sp, #40]
cmp	r0, #1
bne.n	.LNewGameDE_080064A2
cmp	r5, #0
beq.n	.LNewGameDE_0800649E
adds	r0, r5, #0
mov	r1, r9
ldmia	r1!, {r2, r3, r4}
stmia	r0!, {r2, r3, r4}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800649E:
adds	r5, #16
b.n	.LNewGameDE_080064C4
.LNewGameDE_080064A2:
adds	r3, r0, #0
adds	r2, r5, #0
cmp	r3, #0
beq.n	.LNewGameDE_080064C2
.LNewGameDE_080064AA:
cmp	r2, #0
beq.n	.LNewGameDE_080064BA
adds	r0, r2, #0
mov	r1, r9
ldmia	r1!, {r4, r5, r7}
stmia	r0!, {r4, r5, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_080064BA:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_080064AA
.LNewGameDE_080064C2:
adds	r5, r2, #0
.LNewGameDE_080064C4:
ldr	r2, [r6, #4]
ldr	r0, [r6, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_080064D4
.LNewGameDE_080064CE:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_080064CE
.LNewGameDE_080064D4:
cmp	r0, #0
beq.n	.LNewGameDE_080064DC
bl	free
.LNewGameDE_080064DC:
ldr	r0, [sp, #44]
add	r0, r8
ldr	r7, [sp, #44]
str	r7, [r6, #0]
str	r5, [r6, #4]
str	r0, [r6, #12]
.LNewGameDE_080064E8:
add	sp, #48
pop	{r3, r4, r5}
mov	r8, r3
mov	r9, r4
mov	sl, r5
pop	{r4, r5, r6, r7}
pop	{r0}
bx	r0

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r5, r0, #0
    movs r0, #0xf0
    lsls r0, r0, #3
    mov sb, r0
    movs r1, #0x60
    movs r2, #0x10
    movs r3, #0
    add r0, sp, #0x1c
    movs r6, #0x1e
    movs r4, #2
    mov r8, r4
    strh r6, [r0]
    mov r7, r8
    strh r7, [r0, #2]
    ldr r0, [sp, #0x1c]
    ldr r7, .L08006410 @ =0x00003C2C
    adds r4, r5, r7
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    adds r1, r4, #0
    movs r2, #0
    bl Clear2DGfxBufferRect
    ldr r0, .L08006414 @ =0x0000461C
    adds r1, r5, r0
    add r0, sp, #0x20
    strh r6, [r0]
    mov r2, r8
    strh r2, [r0, #2]
    ldr r0, [sp, #0x20]
    str r1, [sp]
    adds r1, r4, #0
    movs r2, #0x90
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    adds r0, r5, #0
    bl func_08008910
    adds r6, r0, #0
    mov r3, sb
    lsls r2, r3, #3
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    add r0, sp, #0xc
    adds r1, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r4, sp, #0xc
    mov sb, r4
    ldr r1, [r6, #4]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    beq .L08006418
    cmp r1, #0
    beq .L08006408
    adds r0, r1, #0
    add r1, sp, #0xc
    ldm r1!, {r2, r5, r7}
    stm r0!, {r2, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006408:
    ldr r0, [r6, #4]
    adds r0, #0x10
    str r0, [r6, #4]
    b .L080064D8
    .align 2, 0
.L08006410: .4byte 0x00003C2C
.L08006414: .4byte 0x0000461C
.L08006418:
    mov sl, r1
    movs r0, #1
    str r0, [sp, #0x28]
    ldr r0, [r6]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x24]
    add r1, sp, #0x28
    add r0, sp, #0x24
    cmp r4, #1
    bhs .L08006430
    adds r0, r1, #0
.L08006430:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0800644E
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L08006452
    mov r0, r8
    bl RetryMemoryAllocation
    b .L08006452
.L0800644E:
    movs r0, #0
    mov r8, r0
.L08006452:
    adds r5, r0, #0
    str r5, [sp, #0x2c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, sl
    beq .L08006476
.L0800645E:
    cmp r3, #0
    beq .L0800646E
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800646E:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, sl
    bne .L0800645E
.L08006476:
    adds r5, r3, #0
    ldr r0, [sp, #0x28]
    cmp r0, #1
    bne .L08006492
    cmp r5, #0
    beq .L0800648E
    adds r0, r5, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800648E:
    adds r5, #0x10
    b .L080064B4
.L08006492:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L080064B2
.L0800649A:
    cmp r2, #0
    beq .L080064AA
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r5, r7}
    stm r0!, {r4, r5, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080064AA:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L0800649A
.L080064B2:
    adds r5, r2, #0
.L080064B4:
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L080064C4
.L080064BE:
    adds r1, #0x10
    cmp r1, r2
    bne .L080064BE
.L080064C4:
    cmp r0, #0
    beq .L080064CC
    bl free
.L080064CC:
    ldr r0, [sp, #0x2c]
    add r0, r8
    ldr r7, [sp, #0x2c]
    str r7, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L080064D8:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .endif

    thumb_func_start func_080064E8
func_080064E8: @ 0x080064E8
    .ifdef REGION_DE
.LNewGameDE_080064F8:
push	{r4, r5, r6, r7, lr}
mov	r7, sl
mov	r6, r9
mov	r5, r8
push	{r5, r6, r7}
sub	sp, #92
mov	sl, r0
ldr	r0, [pc, #220]
add	r0, sl
ldrb	r0, [r0, #0]
cmp	r0, #0
bne.n	.LNewGameDE_08006512
b.n	.LNewGameDE_0800685A
.LNewGameDE_08006512:
movs	r0, #1
mov	r8, r0
mov	r1, sp
adds	r1, #20
str	r1, [sp, #64]
mov	r2, sp
adds	r2, #24
str	r2, [sp, #68]
mov	r3, sp
adds	r3, #36
str	r3, [sp, #72]
ldr	r4, [pc, #188]
add	r4, sl
str	r4, [sp, #80]
mov	r6, sp
adds	r6, #4
str	r6, [sp, #60]
.LNewGameDE_08006534:
mov	r7, r8
lsls	r4, r7, #4
subs	r4, r4, r7
lsls	r4, r4, #5
add	r4, r8
lsls	r4, r4, #2
mov	r0, sl
adds	r1, r4, r0
add	r0, sp, #20
movs	r2, #30
strh	r2, [r0, #0]
movs	r6, #2
ldr	r3, [sp, #64]
strh	r6, [r3, #2]
ldr	r0, [sp, #20]
adds	r1, #12
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r0, [pc, #144]
add	r0, sl
ldr	r0, [r0, #0]
mov	r7, sl
adds	r1, r4, r7
mov	r2, r8
lsls	r3, r2, #5
subs	r3, r3, r2
lsls	r2, r0, #3
subs	r2, r2, r0
lsls	r0, r2, #5
subs	r0, r0, r2
adds	r3, r3, r0
ldr	r0, [pc, #120]
adds	r3, r3, r0
add	r0, sp, #24
movs	r6, #30
strh	r6, [r0, #0]
movs	r0, #2
.LNewGameDE_08006580:
ldr	r7, [sp, #68]
strh	r0, [r7, #2]
ldr	r0, [sp, #24]
adds	r1, #12
str	r3, [sp, #0]
movs	r2, #0
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
mov	r0, sl
bl	func_08008910
add	r4, sl
adds	r4, #12
movs	r1, #240
lsls	r1, r1, #3
mov	r2, r8
muls	r2, r1
adds	r5, r0, #0
movs	r3, #192
.LNewGameDE_080065A8:
lsls	r3, r3, #19
adds	r2, r2, r3
add	r0, sp, #4
adds	r1, r4, #0
movs	r3, #240
lsls	r3, r3, #3
bl	__21DmaTransferDescriptorPCvPvUi
ldr	r1, [r5, #4]
ldr	r0, [r5, #12]
cmp	r1, r0
beq.n	.LNewGameDE_080065F4
cmp	r1, #0
beq.n	.LNewGameDE_080065D0
adds	r0, r1, #0
add	r1, sp, #4
ldmia	r1!, {r4, r6, r7}
stmia	r0!, {r4, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_080065D0:
ldr	r0, [r5, #4]
adds	r0, #16
str	r0, [r5, #4]
movs	r0, #1
add	r8, r0
movs	r1, #240
lsls	r1, r1, #3
lsls	r1, r1, #3
str	r1, [sp, #76]
b.n	.LNewGameDE_080066C6
.LNewGameDE_080065E4: .4byte 0x00004DBB
.LNewGameDE_080065E8: .4byte 0x00003C2C
.LNewGameDE_080065EC: .4byte 0x00004D84
.LNewGameDE_080065F0: .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.LNewGameDE_080065F4:
str	r1, [sp, #84]
movs	r0, #1
str	r0, [sp, #32]
ldr	r0, [r5, #0]
adds	r2, r1, #0
subs	r0, r2, r0
asrs	r4, r0, #4
str	r4, [sp, #28]
add	r1, sp, #32
add	r0, sp, #28
cmp	r4, #1
bcs.n	.LNewGameDE_0800660E
adds	r0, r1, #0
.LNewGameDE_0800660E:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_0800662C
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r9, r4
cmp	r0, #0
bne.n	.LNewGameDE_08006630
mov	r0, r9
bl	RetryMemoryAllocation
b.n	.LNewGameDE_08006630
.LNewGameDE_0800662C:
movs	r0, #0
mov	r9, r0
.LNewGameDE_08006630:
adds	r4, r0, #0
str	r4, [sp, #88]
ldr	r2, [r5, #0]
adds	r3, r4, #0
movs	r4, #1
add	r8, r4
movs	r6, #240
lsls	r6, r6, #3
lsls	r6, r6, #3
str	r6, [sp, #76]
ldr	r7, [sp, #84]
cmp	r2, r7
beq.n	.LNewGameDE_08006664
.LNewGameDE_0800664A:
cmp	r3, #0
beq.n	.LNewGameDE_0800665A
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r6, r7}
stmia	r0!, {r4, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800665A:
adds	r2, #16
adds	r3, #16
ldr	r0, [sp, #84]
cmp	r2, r0
bne.n	.LNewGameDE_0800664A
.LNewGameDE_08006664:
adds	r4, r3, #0
ldr	r0, [sp, #32]
cmp	r0, #1
bne.n	.LNewGameDE_08006680
cmp	r4, #0
beq.n	.LNewGameDE_0800667C
adds	r0, r4, #0
ldr	r1, [sp, #60]
ldmia	r1!, {r2, r3, r6}
stmia	r0!, {r2, r3, r6}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800667C:
adds	r4, #16
b.n	.LNewGameDE_080066A2
.LNewGameDE_08006680:
adds	r3, r0, #0
adds	r2, r4, #0
cmp	r3, #0
beq.n	.LNewGameDE_080066A0
.LNewGameDE_08006688:
cmp	r2, #0
beq.n	.LNewGameDE_08006698
adds	r0, r2, #0
ldr	r1, [sp, #60]
ldmia	r1!, {r4, r6, r7}
stmia	r0!, {r4, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006698:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_08006688
.LNewGameDE_080066A0:
adds	r4, r2, #0
.LNewGameDE_080066A2:
ldr	r2, [r5, #4]
ldr	r0, [r5, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_080066B2
.LNewGameDE_080066AC:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_080066AC
.LNewGameDE_080066B2:
cmp	r0, #0
beq.n	.LNewGameDE_080066BA
bl	free
.LNewGameDE_080066BA:
ldr	r0, [sp, #88]
add	r0, r9
ldr	r7, [sp, #88]
str	r7, [r5, #0]
str	r4, [r5, #4]
str	r0, [r5, #12]
.LNewGameDE_080066C6:
mov	r0, r8
cmp	r0, #7
bhi.n	.LNewGameDE_080066CE
b.n	.LNewGameDE_08006534
.LNewGameDE_080066CE:
movs	r4, #30
movs	r5, #2
add	r0, sp, #36
strh	r4, [r0, #0]
ldr	r1, [sp, #72]
strh	r5, [r1, #2]
ldr	r0, [sp, #36]
ldr	r1, [sp, #80]
movs	r2, #0
bl	Clear2DGfxBuffer
ldr	r0, [pc, #16]
add	r0, sl
ldr	r2, [r0, #0]
cmp	r2, #1
beq.n	.LNewGameDE_08006714
cmp	r2, #1
bgt.n	.LNewGameDE_080066FC
cmp	r2, #0
beq.n	.LNewGameDE_08006702
b.n	.LNewGameDE_08006746
.LNewGameDE_080066F8: .4byte 0x00004D84
.LNewGameDE_080066FC:
cmp	r2, #2
beq.n	.LNewGameDE_08006730
b.n	.LNewGameDE_08006746
.LNewGameDE_08006702:
ldr	r1, [pc, #12]
add	r0, sp, #40
strh	r4, [r0, #0]
strh	r5, [r0, #2]
ldr	r0, [sp, #40]
b.n	.LNewGameDE_0800671E
    .align 2, 0
.LNewGameDE_08006710: .4byte gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006714:
ldr	r1, [pc, #20]
add	r0, sp, #44
strh	r4, [r0, #0]
strh	r5, [r0, #2]
ldr	r0, [sp, #44]
.LNewGameDE_0800671E:
str	r1, [sp, #0]
ldr	r1, [sp, #80]
movs	r2, #24
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
b.n	.LNewGameDE_08006746
.LNewGameDE_0800672C: .4byte gText_NewGameNameEntry_EndLatin
.LNewGameDE_08006730:
ldr	r1, [pc, #84]
add	r0, sp, #48
strh	r4, [r0, #0]
strh	r2, [r0, #2]
ldr	r0, [sp, #48]
str	r1, [sp, #0]
ldr	r1, [sp, #80]
movs	r2, #24
movs	r3, #0
bl	DrawStringTo2DGfxBuffer
.LNewGameDE_08006746:
mov	r0, sl
bl	func_08008910
adds	r5, r0, #0
movs	r2, #192
lsls	r2, r2, #19
ldr	r3, [sp, #76]
adds	r2, r3, r2
add	r0, sp, #4
ldr	r1, [sp, #80]
movs	r3, #240
lsls	r3, r3, #3
bl	__21DmaTransferDescriptorPCvPvUi
add	r4, sp, #4
mov	r9, r4
ldr	r1, [r5, #4]
ldr	r0, [r5, #12]
cmp	r1, r0
beq.n	.LNewGameDE_0800678C
cmp	r1, #0
beq.n	.LNewGameDE_0800677E
adds	r0, r1, #0
add	r1, sp, #4
ldmia	r1!, {r2, r6, r7}
stmia	r0!, {r2, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_0800677E:
ldr	r0, [r5, #4]
adds	r0, #16
str	r0, [r5, #4]
b.n	.LNewGameDE_08006852
    .align 2, 0
.LNewGameDE_08006788: .4byte gText_NewGameNameEntry_EndLatin
.LNewGameDE_0800678C:
str	r1, [sp, #84]
movs	r0, #1
str	r0, [sp, #56]
ldr	r0, [r5, #0]
adds	r3, r1, #0
subs	r0, r3, r0
asrs	r4, r0, #4
str	r4, [sp, #52]
add	r1, sp, #56
add	r0, sp, #52
cmp	r4, #1
bcs.n	.LNewGameDE_080067A6
adds	r0, r1, #0
.LNewGameDE_080067A6:
ldr	r0, [r0, #0]
adds	r0, r4, r0
cmp	r0, #0
beq.n	.LNewGameDE_080067C4
lsls	r4, r0, #4
adds	r0, r4, #0
bl	malloc
mov	r8, r4
cmp	r0, #0
bne.n	.LNewGameDE_080067C8
mov	r0, r8
bl	RetryMemoryAllocation
b.n	.LNewGameDE_080067C8
.LNewGameDE_080067C4:
movs	r0, #0
mov	r8, r0
.LNewGameDE_080067C8:
adds	r4, r0, #0
str	r4, [sp, #88]
ldr	r2, [r5, #0]
adds	r3, r4, #0
ldr	r4, [sp, #84]
cmp	r2, r4
beq.n	.LNewGameDE_080067F0
.LNewGameDE_080067D6:
cmp	r3, #0
beq.n	.LNewGameDE_080067E6
adds	r0, r3, #0
adds	r1, r2, #0
ldmia	r1!, {r4, r6, r7}
stmia	r0!, {r4, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_080067E6:
adds	r2, #16
adds	r3, #16
ldr	r6, [sp, #84]
cmp	r2, r6
bne.n	.LNewGameDE_080067D6
.LNewGameDE_080067F0:
adds	r4, r3, #0
ldr	r0, [sp, #56]
cmp	r0, #1
bne.n	.LNewGameDE_0800680C
cmp	r4, #0
beq.n	.LNewGameDE_08006808
adds	r0, r4, #0
mov	r1, r9
ldmia	r1!, {r2, r3, r7}
stmia	r0!, {r2, r3, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006808:
adds	r4, #16
b.n	.LNewGameDE_0800682E
.LNewGameDE_0800680C:
adds	r3, r0, #0
adds	r2, r4, #0
cmp	r3, #0
beq.n	.LNewGameDE_0800682C
.LNewGameDE_08006814:
cmp	r2, #0
beq.n	.LNewGameDE_08006824
adds	r0, r2, #0
mov	r1, r9
ldmia	r1!, {r4, r6, r7}
stmia	r0!, {r4, r6, r7}
ldr	r1, [r1, #0]
str	r1, [r0, #0]
.LNewGameDE_08006824:
subs	r3, #1
adds	r2, #16
cmp	r3, #0
bne.n	.LNewGameDE_08006814
.LNewGameDE_0800682C:
adds	r4, r2, #0
.LNewGameDE_0800682E:
ldr	r2, [r5, #4]
ldr	r0, [r5, #0]
adds	r1, r0, #0
cmp	r0, r2
beq.n	.LNewGameDE_0800683E
.LNewGameDE_08006838:
adds	r1, #16
cmp	r1, r2
bne.n	.LNewGameDE_08006838
.LNewGameDE_0800683E:
cmp	r0, #0
beq.n	.LNewGameDE_08006846
bl	free
.LNewGameDE_08006846:
ldr	r0, [sp, #88]
add	r0, r8
ldr	r1, [sp, #88]
str	r1, [r5, #0]
str	r4, [r5, #4]
str	r0, [r5, #12]
.LNewGameDE_08006852:
ldr	r1, [pc, #24]
add	r1, sl
movs	r0, #0
strb	r0, [r1, #0]
.LNewGameDE_0800685A:
add	sp, #92
pop	{r3, r4, r5}
mov	r8, r3
mov	r9, r4
mov	sl, r5
pop	{r4, r5, r6, r7}
pop	{r0}
bx	r0
    .align 2, 0
.LNewGameDE_0800686C: .4byte 0x00004DBB

    .else
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x5c
    mov sl, r0
    ldr r0, .L080065D0 @ =0x00004637
    add r0, sl
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08006502
    b .L08006842
.L08006502:
    movs r0, #1
    mov r8, r0
    mov r1, sp
    adds r1, #0x14
    str r1, [sp, #0x40]
    mov r2, sp
    adds r2, #0x18
    str r2, [sp, #0x44]
    mov r3, sp
    adds r3, #0x24
    str r3, [sp, #0x48]
    ldr r4, .L080065D4 @ =0x000034A8
    add r4, sl
    str r4, [sp, #0x50]
    mov r6, sp
    adds r6, #4
    str r6, [sp, #0x3c]
.L08006524:
    mov r7, r8
    lsls r4, r7, #4
    subs r4, r4, r7
    lsls r4, r4, #5
    add r4, r8
    lsls r4, r4, #2
    mov r0, sl
    adds r1, r4, r0
    add r0, sp, #0x14
    movs r2, #0x1e
    strh r2, [r0]
    movs r6, #2
    ldr r3, [sp, #0x40]
    strh r6, [r3, #2]
    ldr r0, [sp, #0x14]
    adds r1, #0xc
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r0, #0x8c
    lsls r0, r0, #7
    add r0, sl
    ldr r3, [r0]
    mov r7, sl
    adds r1, r4, r7
    mov r0, r8
    lsls r2, r0, #5
    subs r2, r2, r0
    movs r0, #0xba
    muls r0, r3, r0
    adds r2, r2, r0
    ldr r0, .L080065D8 @ =gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
    adds r2, r2, r0
    add r0, sp, #0x18
    movs r3, #0x1e
    strh r3, [r0]
    ldr r7, [sp, #0x44]
    strh r6, [r7, #2]
    ldr r0, [sp, #0x18]
    adds r1, #0xc
    str r2, [sp]
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    mov r0, sl
    bl func_08008910
    add r4, sl
    adds r4, #0xc
    movs r1, #0xf0
    lsls r1, r1, #3
    mov r2, r8
    muls r2, r1, r2
    adds r5, r0, #0
    movs r3, #0xc0
    lsls r3, r3, #0x13
    adds r2, r2, r3
    add r0, sp, #4
    adds r1, r4, #0
    movs r3, #0xf0
    lsls r3, r3, #3
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080065DC
    cmp r1, #0
    beq .L080065BC
    adds r0, r1, #0
    add r1, sp, #4
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080065BC:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    movs r0, #1
    add r8, r0
    movs r1, #0xf0
    lsls r1, r1, #3
    lsls r1, r1, #3
    str r1, [sp, #0x4c]
    b .L080066AE
    .align 2, 0
.L080065D0: .4byte 0x00004637
.L080065D4: .4byte 0x000034A8
@ r8 is one-based here, so this is the keyboard table address minus exactly
@ one fixed-width row.  It is not a pointer into DogName.
.L080065D8: .4byte gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH
.L080065DC:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x20]
    ldr r0, [r5]
    adds r2, r1, #0
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x1c]
    add r1, sp, #0x20
    add r0, sp, #0x1c
    cmp r4, #1
    bhs .L080065F6
    adds r0, r1, #0
.L080065F6:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08006614
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08006618
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08006618
.L08006614:
    movs r0, #0
    mov sb, r0
.L08006618:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    movs r4, #1
    add r8, r4
    movs r6, #0xf0
    lsls r6, r6, #3
    lsls r6, r6, #3
    str r6, [sp, #0x4c]
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .L0800664C
.L08006632:
    cmp r3, #0
    beq .L08006642
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006642:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .L08006632
.L0800664C:
    adds r4, r3, #0
    ldr r0, [sp, #0x20]
    cmp r0, #1
    bne .L08006668
    cmp r4, #0
    beq .L08006664
    adds r0, r4, #0
    ldr r1, [sp, #0x3c]
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08006664:
    adds r4, #0x10
    b .L0800668A
.L08006668:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08006688
.L08006670:
    cmp r2, #0
    beq .L08006680
    adds r0, r2, #0
    ldr r1, [sp, #0x3c]
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08006680:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08006670
.L08006688:
    adds r4, r2, #0
.L0800668A:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0800669A
.L08006694:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006694
.L0800669A:
    cmp r0, #0
    beq .L080066A2
    bl free
.L080066A2:
    ldr r0, [sp, #0x58]
    add r0, sb
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.L080066AE:
    mov r0, r8
    cmp r0, #6
    bhi .L080066B6
    b .L08006524
.L080066B6:
    movs r4, #0x1e
    movs r5, #2
    add r0, sp, #0x24
    strh r4, [r0]
    ldr r1, [sp, #0x48]
    strh r5, [r1, #2]
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x50]
    movs r2, #0
    bl Clear2DGfxBuffer
    movs r0, #0x8c
    lsls r0, r0, #7
    add r0, sl
    ldr r2, [r0]
    cmp r2, #1
    beq .L080066F8
    cmp r2, #1
    bgt .L080066E2
    cmp r2, #0
    beq .L080066E8
    b .L0800672A
.L080066E2:
    cmp r2, #2
    beq .L08006714
    b .L0800672A
.L080066E8:
    ldr r1, .L080066F4 @ =gText_NewGameNameEntry_EndLatin
    add r0, sp, #0x28
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x28]
    b .L08006702
    .align 2, 0
.L080066F4: .4byte gText_NewGameNameEntry_EndLatin
.L080066F8:
    ldr r1, .L08006710 @ =gText_NewGameNameEntry_EndFullWidth
    add r0, sp, #0x2c
    strh r4, [r0]
    strh r5, [r0, #2]
    ldr r0, [sp, #0x2c]
.L08006702:
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
    b .L0800672A
    .align 2, 0
.L08006710: .4byte gText_NewGameNameEntry_EndFullWidth
.L08006714:
    ldr r1, .L08006770 @ =gText_NewGameNameEntry_EndFullWidth
    add r0, sp, #0x30
    strh r4, [r0]
    strh r2, [r0, #2]
    ldr r0, [sp, #0x30]
    str r1, [sp]
    ldr r1, [sp, #0x50]
    movs r2, #0x18
    movs r3, #0
    bl DrawStringTo2DGfxBuffer
.L0800672A:
    mov r0, sl
    bl func_08008910
    adds r5, r0, #0
    ldr r3, [sp, #0x4c]
    movs r4, #0xf0
    lsls r4, r4, #3
    subs r2, r3, r4
    movs r6, #0xc0
    lsls r6, r6, #0x13
    adds r2, r2, r6
    add r0, sp, #4
    ldr r1, [sp, #0x50]
    adds r3, r4, #0
    bl __21DmaTransferDescriptorPCvPvUi
    add r7, sp, #4
    mov sb, r7
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L08006774
    cmp r1, #0
    beq .L08006766
    adds r0, r1, #0
    add r1, sp, #4
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08006766:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L0800683A
    .align 2, 0
.L08006770: .4byte gText_NewGameNameEntry_EndFullWidth
.L08006774:
    str r1, [sp, #0x54]
    movs r0, #1
    str r0, [sp, #0x38]
    ldr r0, [r5]
    adds r6, r1, #0
    subs r0, r6, r0
    asrs r4, r0, #4
    str r4, [sp, #0x34]
    add r1, sp, #0x38
    add r0, sp, #0x34
    cmp r4, #1
    bhs .L0800678E
    adds r0, r1, #0
.L0800678E:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080067AC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L080067B0
    mov r0, r8
    bl RetryMemoryAllocation
    b .L080067B0
.L080067AC:
    movs r0, #0
    mov r8, r0
.L080067B0:
    adds r4, r0, #0
    str r4, [sp, #0x58]
    ldr r2, [r5]
    adds r3, r4, #0
    ldr r7, [sp, #0x54]
    cmp r2, r7
    beq .L080067D8
.L080067BE:
    cmp r3, #0
    beq .L080067CE
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080067CE:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x54]
    cmp r2, r0
    bne .L080067BE
.L080067D8:
    adds r4, r3, #0
    ldr r0, [sp, #0x38]
    cmp r0, #1
    bne .L080067F4
    cmp r4, #0
    beq .L080067F0
    adds r0, r4, #0
    mov r1, sb
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L080067F0:
    adds r4, #0x10
    b .L08006816
.L080067F4:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08006814
.L080067FC:
    cmp r2, #0
    beq .L0800680C
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0800680C:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L080067FC
.L08006814:
    adds r4, r2, #0
.L08006816:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08006826
.L08006820:
    adds r1, #0x10
    cmp r1, r2
    bne .L08006820
.L08006826:
    cmp r0, #0
    beq .L0800682E
    bl free
.L0800682E:
    ldr r0, [sp, #0x58]
    add r0, r8
    ldr r7, [sp, #0x58]
    str r7, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.L0800683A:
    ldr r1, .L08006854 @ =0x00004637
    add r1, sl
    movs r0, #0
    strb r0, [r1]
.L08006842:
    add sp, #0x5c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08006854: .4byte 0x00004637
    .endif


    .endif

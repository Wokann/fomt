    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Native mine generation and cell actions, not yet C++ matched.
    .ifdef REGION_JP
    .section .text.mine_floor_generation
    .align 2, 0
    .global func_0809CF34
    .thumb_func
func_0809CF34:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #60	@ 0x3c
    str	r0, [sp, #52]	@ 0x34
    adds	r6, r1, #0
    str	r2, [sp, #56]	@ 0x38
    mov	r8, r3
    ldr	r0, [sp, #96]	@ 0x60
    mov	r9, r0
    add	r1, sp, #48	@ 0x30
    movs	r0, #0
    strb	r0, [r1, #0]
    strb	r0, [r1, #1]
    mov	r0, sp
    movs	r2, #11
    movs	r1, #0
    movs	r3, #1
    negs	r3, r3
.Ljp_0809C996:
    strb	r1, [r0, #0]
    strb	r1, [r0, #1]
    adds	r0, #4
    subs	r2, #1
    cmp	r2, r3
    bne .Ljp_0809C996
    movs	r0, #0
    movs	r1, #16
    negs	r1, r1
    mov	ip, r1
    ldr r7, .Ljp_0809CA14
    movs	r5, #3
.Ljp_0809C9AE:
    movs	r3, #0
    lsls	r1, r0, #3
    adds	r4, r0, #1
    subs	r1, r1, r0
    lsls	r1, r1, #3
    adds	r0, r6, #4
    adds	r2, r1, r0
.Ljp_0809C9BC:
    ldrb	r1, [r2, #0]
    mov	r0, ip
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    adds	r0, r7, #0
    ands	r0, r1
    strh	r0, [r2, #0]
    ldrb	r1, [r2, #1]
    adds	r0, r5, #0
    ands	r0, r1
    strb	r0, [r2, #1]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #27
    bls .Ljp_0809C9BC
    adds	r0, r4, #0
    cmp	r0, #27
    bls .Ljp_0809C9AE
    ldr	r0, [sp, #92]	@ 0x5c
    cmp	r0, #0
    beq .Ljp_0809C9FC
    movs	r1, #0
    cmp	r1, r9
    bcs .Ljp_0809C9FC
    adds	r3, r0, #0
    mov	r2, sp
.Ljp_0809C9F2:
    ldmia	r3!, {r0}
    stmia	r2!, {r0}
    adds	r1, #1
    cmp	r1, r9
    bcc .Ljp_0809C9F2
.Ljp_0809C9FC:
    movs	r3, #255	@ 0xff
    mov	r1, sp
.Ljp_0809CA00:
    ldrb	r2, [r1, #0]
    subs	r0, r2, #2
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    cmp	r0, #55	@ 0x37
    bls .Ljp_0809CA18
    adds	r0, r2, #0
    orrs	r0, r3
    b .Ljp_0809CA1E
    .align 2, 0
.Ljp_0809CA14:
    .4byte 0xFFFFFC0F
.Ljp_0809CA18:
    ldrb	r0, [r1, #0]
    subs	r0, #2
    asrs	r0, r0, #1
.Ljp_0809CA1E:
    strb	r0, [r1, #0]
    ldrb	r2, [r1, #1]
    subs	r0, r2, #7
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    cmp	r0, #55	@ 0x37
    bls .Ljp_0809CA32
    adds	r0, r2, #0
    orrs	r0, r3
    b .Ljp_0809CA38
.Ljp_0809CA32:
    ldrb	r0, [r1, #1]
    subs	r0, #7
    asrs	r0, r0, #1
.Ljp_0809CA38:
    strb	r0, [r1, #1]
    adds	r1, #4
    add	r0, sp, #44	@ 0x2c
    cmp	r1, r0
    ble .Ljp_0809CA00
    mov	r1, r8
    cmp	r1, #0
    bne .Ljp_0809CA4E
    str	r1, [r6, #0]
    movs	r0, #20
    b .Ljp_0809CA96
.Ljp_0809CA4E:
    mov	r1, r8
    cmp	r1, #9
    bne .Ljp_0809CA64
    ldr	r0, [sp, #56]	@ 0x38
    cmp	r0, #1
    bne .Ljp_0809CA64
    movs	r0, #4
    str	r0, [r6, #0]
    movs	r1, #40	@ 0x28
    mov	sl, r1
    b .Ljp_0809CA98
.Ljp_0809CA64:
    mov	r0, r8
    movs	r1, #5
    bl __umodsi3
    cmp	r0, #0
    bne .Ljp_0809CA7A
    movs	r0, #1
    str	r0, [r6, #0]
    movs	r0, #150	@ 0x96
    lsls	r0, r0, #1
    b .Ljp_0809CA96
.Ljp_0809CA7A:
    mov	r0, r8
    movs	r1, #3
    bl __umodsi3
    cmp	r0, #0
    bne .Ljp_0809CA90
    movs	r0, #2
    str	r0, [r6, #0]
    movs	r1, #100	@ 0x64
    mov	sl, r1
    b .Ljp_0809CA98
.Ljp_0809CA90:
    movs	r0, #3
    str	r0, [r6, #0]
    movs	r0, #30
.Ljp_0809CA96:
    mov	sl, r0
.Ljp_0809CA98:
    mov	r1, r8
    cmp	r1, #0
    beq .Ljp_0809CB46
    bl rand
    adds	r4, r0, #0
    adds	r0, r6, #0
    bl GetWidth__C14MineFloorState
    adds	r1, r0, #0
    asrs	r4, r4, #8
    subs	r1, #2
    adds	r0, r4, #0
    bl __umodsi3
    mov	r9, r0
    mov	r5, r9
    adds	r5, #1
    bl rand
    adds	r4, r0, #0
    adds	r0, r6, #0
    bl GetHeight__C14MineFloorState
    adds	r1, r0, #0
    asrs	r4, r4, #8
    subs	r1, #2
    adds	r0, r4, #0
    bl __umodsi3
    adds	r7, r0, #0
    adds	r4, r7, #1
    lsls	r2, r5, #1
    lsls	r0, r4, #3
    subs	r0, r0, r4
    lsls	r0, r0, #3
    adds	r2, r2, r0
    adds	r2, r6, r2
    ldrb	r1, [r2, #4]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #3
    orrs	r0, r1
    strb	r0, [r2, #4]
    bl rand
    asrs	r1, r0, #8
    movs	r0, #3
    ands	r1, r0
    movs	r0, #2
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0809CB14
    movs	r0, #1
    ands	r1, r0
    cmp	r1, #0
    beq .Ljp_0809CB10
    mov	r5, r9
    b .Ljp_0809CB22
.Ljp_0809CB10:
    adds	r5, #1
    b .Ljp_0809CB22
.Ljp_0809CB14:
    movs	r0, #1
    ands	r1, r0
    cmp	r1, #0
    beq .Ljp_0809CB20
    adds	r4, r7, #0
    b .Ljp_0809CB22
.Ljp_0809CB20:
    adds	r4, #1
.Ljp_0809CB22:
    add	r0, sp, #48	@ 0x30
    strb	r5, [r0, #0]
    strb	r4, [r0, #1]
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #1
    ldrb	r2, [r0, #1]
    lsls	r0, r2, #3
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r6, r1
    ldrb	r2, [r1, #4]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r2
    movs	r2, #1
    orrs	r0, r2
    strb	r0, [r1, #4]
.Ljp_0809CB46:
    ldr	r1, [sp, #56]	@ 0x38
    cmp	r1, #0
    bne .Ljp_0809CB5A
    adds	r0, r6, #0
    mov	r1, r8
    mov	r2, sl
    mov	r3, sp
    bl .Ljp_0809CBA0
    b .Ljp_0809CB66
.Ljp_0809CB5A:
    adds	r0, r6, #0
    mov	r1, r8
    mov	r2, sl
    mov	r3, sp
    bl func_0809D500
.Ljp_0809CB66:
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_0809CB88
    add	r0, sp, #48	@ 0x30
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #1
    ldrb	r2, [r0, #1]
    lsls	r0, r2, #3
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r6, r1
    ldrb	r2, [r1, #4]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r2
    strb	r0, [r1, #4]
.Ljp_0809CB88:
    ldr	r0, [sp, #48]	@ 0x30
    ldr	r1, [sp, #52]	@ 0x34
    str	r0, [r1, #0]
    ldr	r0, [sp, #52]	@ 0x34
    add	sp, #60	@ 0x3c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_0809CBA0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #40	@ 0x28
    mov	sl, r0
    str	r1, [sp, #0]
    str	r2, [sp, #4]
    str	r3, [sp, #8]
    bl GetWidth__C14MineFloorState
    str	r0, [sp, #12]
    mov	r0, sl
    bl GetHeight__C14MineFloorState
    str	r0, [sp, #16]
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl GetSpringBuriedItemTableIndex__C14MineFloorStateUi
    str	r0, [sp, #20]
    bl rand
    asrs	r0, r0, #4
    ldr	r1, [sp, #16]
    ldr	r2, [sp, #12]
    adds	r4, r1, #0
    muls	r4, r2
    adds	r1, r4, #0
    bl __umodsi3
    str	r0, [sp, #24]
    movs	r5, #0
    cmp	r5, r4
    bcc .Ljp_0809CBEA
    b .Ljp_0809CD12
.Ljp_0809CBEA:
    str	r4, [sp, #28]
.Ljp_0809CBEC:
    ldr	r3, [sp, #24]
    adds	r4, r3, r5
    ldr	r0, [sp, #28]
    cmp	r4, r0
    bcc .Ljp_0809CBF8
    subs	r4, r4, r0
.Ljp_0809CBF8:
    adds	r0, r4, #0
    ldr	r1, [sp, #12]
    bl __umodsi3
    mov	r8, r0
    adds	r0, r4, #0
    ldr	r1, [sp, #12]
    bl __udivsi3
    adds	r7, r0, #0
    mov	r1, r8
    lsls	r0, r1, #1
    lsls	r1, r7, #3
    subs	r1, r1, r7
    lsls	r1, r1, #3
    adds	r0, r0, r1
    add	r0, sl
    ldrb	r0, [r0, #4]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    adds	r5, #1
    str	r5, [sp, #36]	@ 0x24
    cmp	r0, #1
    bgt .Ljp_0809CD08
    bl rand
    asrs	r2, r0, #4
    movs	r0, #255	@ 0xff
    ands	r2, r0
    movs	r3, #0
    ldr	r4, [sp, #20]
    lsls	r6, r4, #2
    ldr r4, .Ljp_0809CCA0
.Ljp_0809CC3A:
    ldr	r1, [sp, #20]
    adds	r0, r6, r1
    adds	r0, r3, r0
    adds	r1, r0, r4
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Ljp_0809CD02
    cmp	r2, r0
    bge .Ljp_0809CCFC
    ldr r1, .Ljp_0809CCA4
    lsls	r0, r3, #2
    adds	r0, r0, r1
    ldr	r3, [r0, #0]
    mov	r2, r8
    lsls	r2, r2, #1
    mov	r9, r2
    lsls	r4, r7, #3
    mov	ip, r4
    cmp	r3, #1
    bne .Ljp_0809CCE4
    cmp	r7, #0
    beq .Ljp_0809CCD8
    ldr	r0, [sp, #16]
    subs	r0, #1
    cmp	r7, r0
    bcs .Ljp_0809CCD8
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_0809CCD8
    ldr	r0, [sp, #12]
    subs	r0, #1
    cmp	r8, r0
    bcs .Ljp_0809CCD8
    subs	r4, r7, #1
    adds	r6, r7, #2
    cmp	r4, r6
    bge .Ljp_0809CCE4
    lsls	r0, r4, #3
    subs	r0, r0, r4
    lsls	r5, r0, #3
.Ljp_0809CC8A:
    cmp	r4, #0
    blt .Ljp_0809CCCE
    ldr	r1, [sp, #16]
    cmp	r4, r1
    bge .Ljp_0809CCCE
    mov	r2, r8
    subs	r2, #1
    mov	r1, r8
    adds	r1, #2
    b .Ljp_0809CCAA
    .align 2, 0
.Ljp_0809CCA0:
    .4byte gSpringMineBuriedItemWeights
.Ljp_0809CCA4:
    .4byte gSpringMineBuriedItemCodes
.Ljp_0809CCA8:
    adds	r2, #1
.Ljp_0809CCAA:
    cmp	r2, r1
    bge .Ljp_0809CCCA
    cmp	r2, #0
    bge .Ljp_0809CCB8
    ldr	r0, [sp, #12]
    cmp	r2, r0
    bge .Ljp_0809CCA8
.Ljp_0809CCB8:
    lsls	r0, r2, #1
    adds	r0, r0, r5
    add	r0, sl
    ldrb	r0, [r0, #4]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Ljp_0809CCA8
    movs	r3, #0
.Ljp_0809CCCA:
    cmp	r3, #0
    beq .Ljp_0809CCE4
.Ljp_0809CCCE:
    adds	r5, #56	@ 0x38
    adds	r4, #1
    cmp	r4, r6
    blt .Ljp_0809CC8A
    b .Ljp_0809CCE4
.Ljp_0809CCD8:
    movs	r3, #0
    mov	r1, r8
    lsls	r1, r1, #1
    mov	r9, r1
    lsls	r2, r7, #3
    mov	ip, r2
.Ljp_0809CCE4:
    mov	r4, ip
    subs	r1, r4, r7
    lsls	r1, r1, #3
    add	r1, r9
    add	r1, sl
    lsls	r3, r3, #2
    ldrb	r2, [r1, #5]
    movs	r0, #3
    ands	r0, r2
    orrs	r0, r3
    strb	r0, [r1, #5]
    b .Ljp_0809CD08
.Ljp_0809CCFC:
    subs	r2, r2, r0
    cmp	r2, #0
    blt .Ljp_0809CD08
.Ljp_0809CD02:
    adds	r3, #1
    cmp	r3, #4
    ble .Ljp_0809CC3A
.Ljp_0809CD08:
    ldr	r5, [sp, #36]	@ 0x24
    ldr	r0, [sp, #28]
    cmp	r5, r0
    bcs .Ljp_0809CD12
    b .Ljp_0809CBEC
.Ljp_0809CD12:
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl GetSpringRockTableIndex__C14MineFloorStateUi
    str	r0, [sp, #20]
    ldr	r1, [sp, #4]
    cmp	r1, #0
    bgt .Ljp_0809CD24
    b .Ljp_0809CE3A
.Ljp_0809CD24:
    movs	r2, #0
    mov	r8, r2
    movs	r3, #1
    mov	r9, r3
    ldr	r4, [sp, #4]
    subs	r4, #1
    str	r4, [sp, #32]
.Ljp_0809CD32:
    bl rand
    asrs	r0, r0, #8
    ldr	r1, [sp, #12]
    bl __umodsi3
    adds	r4, r0, #0
    bl rand
    asrs	r0, r0, #8
    ldr	r1, [sp, #16]
    bl __umodsi3
    adds	r7, r0, #0
    lsls	r1, r4, #1
    lsls	r0, r7, #3
    subs	r0, r0, r7
    lsls	r0, r0, #3
    adds	r1, r1, r0
    add	r1, sl
    ldrb	r0, [r1, #4]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_0809CE1E
    movs	r0, #1
    mov	r8, r0
    movs	r2, #0
    ldr	r1, [sp, #8]
    ldrb	r0, [r1, #0]
    cmp	r0, r4
    bne .Ljp_0809CDA8
    ldrb	r0, [r1, #1]
    cmp	r0, r7
    bne .Ljp_0809CDA8
    mov	r8, r2
    b .Ljp_0809CDC4
.Ljp_0809CD7A:
    subs	r3, r5, r7
    lsls	r3, r3, #3
    adds	r3, r4, r3
    add	r3, sl
    ldr r1, .Ljp_0809CDA0
    mov	r2, ip
    lsls	r0, r2, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    movs	r0, #63	@ 0x3f
    ands	r2, r0
    lsls	r2, r2, #4
    ldrh	r0, [r3, #4]
    ldr r4, .Ljp_0809CDA4
    adds	r1, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #4]
    b .Ljp_0809CE1E
.Ljp_0809CDA0:
    .4byte gSpringMineRockItemCodes
.Ljp_0809CDA4:
    .4byte 0xFFFFFC0F
.Ljp_0809CDA8:
    adds	r2, #1
    cmp	r2, #11
    bgt .Ljp_0809CDC4
    lsls	r0, r2, #2
    ldr	r3, [sp, #8]
    adds	r1, r0, r3
    ldrb	r0, [r1, #0]
    cmp	r0, r4
    bne .Ljp_0809CDA8
    ldrb	r0, [r1, #1]
    cmp	r0, r7
    bne .Ljp_0809CDA8
    movs	r0, #0
    mov	r8, r0
.Ljp_0809CDC4:
    mov	r1, r8
    cmp	r1, #1
    bne .Ljp_0809CE1E
    lsls	r4, r4, #1
    lsls	r5, r7, #3
    subs	r1, r5, r7
    lsls	r1, r1, #3
    adds	r1, r4, r1
    add	r1, sl
    ldrb	r0, [r1, #4]
    movs	r3, #16
    negs	r3, r3
    adds	r2, r3, #0
    ands	r0, r2
    movs	r2, #4
    orrs	r0, r2
    strb	r0, [r1, #4]
    bl rand
    asrs	r2, r0, #8
    movs	r0, #255	@ 0xff
    ands	r2, r0
    movs	r0, #0
    mov	ip, r0
    ldr	r1, [sp, #20]
    lsls	r6, r1, #2
    ldr r1, .Ljp_0809CE4C
    ldr	r3, [sp, #20]
    adds	r0, r6, r3
    lsls	r0, r0, #1
    adds	r1, r0, r1
.Ljp_0809CE02:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Ljp_0809CE12
    cmp	r2, r0
    blt .Ljp_0809CD7A
    subs	r2, r2, r0
    cmp	r2, #0
    blt .Ljp_0809CE1E
.Ljp_0809CE12:
    adds	r1, #1
    movs	r0, #1
    add	ip, r0
    mov	r3, ip
    cmp	r3, #9
    ble .Ljp_0809CE02
.Ljp_0809CE1E:
    mov	r4, r8
    cmp	r4, #0
    bne .Ljp_0809CE30
    movs	r0, #1
    add	r9, r0
    mov	r1, r9
    cmp	r1, #9
    bgt .Ljp_0809CE30
    b .Ljp_0809CD32
.Ljp_0809CE30:
    ldr	r2, [sp, #32]
    str	r2, [sp, #4]
    cmp	r2, #0
    ble .Ljp_0809CE3A
    b .Ljp_0809CD24
.Ljp_0809CE3A:
    add	sp, #40	@ 0x28
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_0809CE4C:
    .4byte gSpringMineRockItemWeights

    .section .text.mine_floor_placement
    .align 2, 0
    thumb_func_start func_0809D500
func_0809D500:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #40	@ 0x28
    mov	sl, r0
    str	r1, [sp, #0]
    str	r2, [sp, #4]
    str	r3, [sp, #8]
    bl GetWidth__C14MineFloorState
    str	r0, [sp, #12]
    mov	r0, sl
    bl GetHeight__C14MineFloorState
    str	r0, [sp, #16]
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    str	r0, [sp, #20]
    bl rand
    asrs	r0, r0, #4
    ldr	r1, [sp, #16]
    ldr	r2, [sp, #12]
    adds	r4, r1, #0
    muls	r4, r2
    adds	r1, r4, #0
    bl __umodsi3
    str	r0, [sp, #24]
    movs	r5, #0
    cmp	r5, r4
    bcc .Ljp_0809CF82
    b .Ljp_0809D0A2
.Ljp_0809CF82:
    str	r4, [sp, #28]
.Ljp_0809CF84:
    ldr	r3, [sp, #24]
    adds	r4, r3, r5
    ldr	r0, [sp, #28]
    cmp	r4, r0
    bcc .Ljp_0809CF90
    subs	r4, r4, r0
.Ljp_0809CF90:
    adds	r0, r4, #0
    ldr	r1, [sp, #12]
    bl __umodsi3
    adds	r7, r0, #0
    adds	r0, r4, #0
    ldr	r1, [sp, #12]
    bl __udivsi3
    adds	r6, r0, #0
    lsls	r0, r7, #1
    lsls	r1, r6, #3
    subs	r1, r1, r6
    lsls	r1, r1, #3
    adds	r0, r0, r1
    add	r0, sl
    ldrb	r0, [r0, #4]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    adds	r5, #1
    str	r5, [sp, #36]	@ 0x24
    cmp	r0, #1
    bgt .Ljp_0809D098
    bl rand
    asrs	r2, r0, #4
    movs	r0, #255	@ 0xff
    ands	r2, r0
    movs	r3, #0
    ldr	r1, [sp, #20]
    lsls	r0, r1, #2
    ldr r1, .Ljp_0809D030
    ldr	r4, [sp, #20]
    adds	r0, r0, r4
    lsls	r0, r0, #1
    adds	r1, r0, r1
.Ljp_0809CFD8:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Ljp_0809D090
    cmp	r2, r0
    bge .Ljp_0809D08A
    ldr r1, .Ljp_0809D034
    lsls	r0, r3, #2
    adds	r0, r0, r1
    ldr	r3, [r0, #0]
    lsls	r0, r7, #1
    mov	r9, r0
    lsls	r1, r6, #3
    mov	r8, r1
    cmp	r3, #1
    bne .Ljp_0809D072
    cmp	r6, #0
    beq .Ljp_0809D068
    ldr	r0, [sp, #16]
    subs	r0, #1
    cmp	r6, r0
    bcs .Ljp_0809D068
    cmp	r7, #0
    beq .Ljp_0809D068
    ldr	r0, [sp, #12]
    subs	r0, #1
    cmp	r7, r0
    bcs .Ljp_0809D068
    subs	r4, r6, #1
    adds	r2, r6, #2
    mov	ip, r2
    cmp	r4, ip
    bge .Ljp_0809D072
    lsls	r0, r4, #3
    subs	r0, r0, r4
    lsls	r5, r0, #3
.Ljp_0809D01E:
    cmp	r4, #0
    blt .Ljp_0809D05E
    ldr	r0, [sp, #16]
    cmp	r4, r0
    bge .Ljp_0809D05E
    subs	r2, r7, #1
    adds	r1, r7, #2
    b .Ljp_0809D03A
    .align 2, 0
.Ljp_0809D030:
    .4byte gLakeMineBuriedItemWeights
.Ljp_0809D034:
    .4byte gLakeMineBuriedItemCodes
.Ljp_0809D038:
    adds	r2, #1
.Ljp_0809D03A:
    cmp	r2, r1
    bge .Ljp_0809D05A
    cmp	r2, #0
    bge .Ljp_0809D048
    ldr	r0, [sp, #12]
    cmp	r2, r0
    bge .Ljp_0809D038
.Ljp_0809D048:
    lsls	r0, r2, #1
    adds	r0, r0, r5
    add	r0, sl
    ldrb	r0, [r0, #4]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Ljp_0809D038
    movs	r3, #0
.Ljp_0809D05A:
    cmp	r3, #0
    beq .Ljp_0809D072
.Ljp_0809D05E:
    adds	r5, #56	@ 0x38
    adds	r4, #1
    cmp	r4, ip
    blt .Ljp_0809D01E
    b .Ljp_0809D072
.Ljp_0809D068:
    movs	r3, #0
    lsls	r7, r7, #1
    mov	r9, r7
    lsls	r1, r6, #3
    mov	r8, r1
.Ljp_0809D072:
    mov	r2, r8
    subs	r1, r2, r6
    lsls	r1, r1, #3
    add	r1, r9
    add	r1, sl
    lsls	r3, r3, #2
    ldrb	r2, [r1, #5]
    movs	r0, #3
    ands	r0, r2
    orrs	r0, r3
    strb	r0, [r1, #5]
    b .Ljp_0809D098
.Ljp_0809D08A:
    subs	r2, r2, r0
    cmp	r2, #0
    blt .Ljp_0809D098
.Ljp_0809D090:
    adds	r1, #1
    adds	r3, #1
    cmp	r3, #9
    ble .Ljp_0809CFD8
.Ljp_0809D098:
    ldr	r5, [sp, #36]	@ 0x24
    ldr	r3, [sp, #28]
    cmp	r5, r3
    bcs .Ljp_0809D0A2
    b .Ljp_0809CF84
.Ljp_0809D0A2:
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl GetLakeRockTableIndex__C14MineFloorStateUi
    str	r0, [sp, #20]
    ldr	r4, [sp, #4]
    cmp	r4, #0
    bgt .Ljp_0809D0B4
    b .Ljp_0809D1C0
.Ljp_0809D0B4:
    movs	r0, #0
    mov	r8, r0
    movs	r1, #1
    mov	r9, r1
    ldr	r2, [sp, #4]
    subs	r2, #1
    str	r2, [sp, #32]
.Ljp_0809D0C2:
    bl rand
    asrs	r0, r0, #8
    ldr	r1, [sp, #12]
    bl __umodsi3
    adds	r4, r0, #0
    bl rand
    asrs	r0, r0, #8
    ldr	r1, [sp, #16]
    bl __umodsi3
    adds	r6, r0, #0
    lsls	r1, r4, #1
    lsls	r0, r6, #3
    subs	r0, r0, r6
    lsls	r0, r0, #3
    adds	r1, r1, r0
    add	r1, sl
    ldrb	r0, [r1, #4]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_0809D1A6
    movs	r3, #1
    mov	r8, r3
    movs	r2, #0
    ldr	r1, [sp, #8]
    ldrb	r0, [r1, #0]
    cmp	r0, r4
    bne .Ljp_0809D138
    ldrb	r0, [r1, #1]
    cmp	r0, r6
    bne .Ljp_0809D138
    mov	r8, r2
    b .Ljp_0809D154
.Ljp_0809D10A:
    subs	r3, r5, r6
    lsls	r3, r3, #3
    adds	r3, r4, r3
    add	r3, sl
    ldr r1, .Ljp_0809D130
    lsls	r0, r7, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    movs	r0, #63	@ 0x3f
    ands	r2, r0
    lsls	r2, r2, #4
    ldrh	r0, [r3, #4]
    ldr r4, .Ljp_0809D134
    adds	r1, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #4]
    b .Ljp_0809D1A6
    .align 2, 0
.Ljp_0809D130:
    .4byte gLakeMineRockItemCodes
.Ljp_0809D134:
    .4byte 0xFFFFFC0F
.Ljp_0809D138:
    adds	r2, #1
    cmp	r2, #11
    bgt .Ljp_0809D154
    lsls	r0, r2, #2
    ldr	r3, [sp, #8]
    adds	r1, r0, r3
    ldrb	r0, [r1, #0]
    cmp	r0, r4
    bne .Ljp_0809D138
    ldrb	r0, [r1, #1]
    cmp	r0, r6
    bne .Ljp_0809D138
    movs	r0, #0
    mov	r8, r0
.Ljp_0809D154:
    mov	r1, r8
    cmp	r1, #1
    bne .Ljp_0809D1A6
    lsls	r4, r4, #1
    lsls	r5, r6, #3
    subs	r1, r5, r6
    lsls	r1, r1, #3
    adds	r1, r4, r1
    add	r1, sl
    ldrb	r0, [r1, #4]
    movs	r3, #16
    negs	r3, r3
    adds	r2, r3, #0
    ands	r0, r2
    movs	r2, #4
    orrs	r0, r2
    strb	r0, [r1, #4]
    bl rand
    asrs	r2, r0, #8
    movs	r0, #255	@ 0xff
    ands	r2, r0
    movs	r7, #0
    ldr r1, .Ljp_0809D1D0
    ldr	r3, [sp, #20]
    lsls	r0, r3, #3
    subs	r0, r0, r3
    lsls	r0, r0, #1
    adds	r1, r0, r1
.Ljp_0809D18E:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Ljp_0809D19E
    cmp	r2, r0
    blt .Ljp_0809D10A
    subs	r2, r2, r0
    cmp	r2, #0
    blt .Ljp_0809D1A6
.Ljp_0809D19E:
    adds	r1, #1
    adds	r7, #1
    cmp	r7, #13
    ble .Ljp_0809D18E
.Ljp_0809D1A6:
    mov	r4, r8
    cmp	r4, #0
    bne .Ljp_0809D1B6
    movs	r0, #1
    add	r9, r0
    mov	r1, r9
    cmp	r1, #9
    ble .Ljp_0809D0C2
.Ljp_0809D1B6:
    ldr	r2, [sp, #32]
    str	r2, [sp, #4]
    cmp	r2, #0
    ble .Ljp_0809D1C0
    b .Ljp_0809D0B4
.Ljp_0809D1C0:
    add	sp, #40	@ 0x28
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_0809D1D0:
    .4byte gLakeMineRockItemWeights
    .global GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .thumb_func
GetLakeBuriedItemTableIndex__C14MineFloorStateUi:
    push	{lr}
    adds	r0, r1, #0
    cmp	r0, #9
    bls .Ljp_0809D20A
    movs	r0, #25
    cmp	r1, #255	@ 0xff
    beq .Ljp_0809D20A
    movs	r0, #24
    cmp	r1, #79	@ 0x4f
    bhi .Ljp_0809D20A
    movs	r0, #10
    movs	r2, #19
    cmp	r1, #19
    bcc .Ljp_0809D20A
    cmp	r1, #19
    bne .Ljp_0809D1F8
    movs	r0, #11
    b .Ljp_0809D20A
.Ljp_0809D1F8:
    adds	r0, #2
    adds	r2, #10
    cmp	r2, #79	@ 0x4f
    bhi .Ljp_0809D20A
    cmp	r1, r2
    bcc .Ljp_0809D20A
    cmp	r1, r2
    bne .Ljp_0809D1F8
    adds	r0, #1
.Ljp_0809D20A:
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.mine_floor_item_weights
    .align 2, 0
        thumb_func_start CopyCurrentItemWeights__C14MineFloorStatePUcRC18GameStateSaveImage
CopyCurrentItemWeights__C14MineFloorStatePUcRC18GameStateSaveImage:
.Lcode_actor_0809E1B4:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r7, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_0809DC74
    adds	r5, r2, r0
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C6Farmer
    mov	r0, sp
    ldrh	r0, [r0, #0]
    lsls	r0, r0, #22
    ldr r1, .Ljp_0809DC78
    cmp	r0, r1
    ble .Ljp_0809DC90
    add	r4, sp, #8
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl GetLocation__C6Farmer
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r1, .Ljp_0809DC7C
    adds	r4, r0, r1
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    adds	r2, r0, #0
    ldr r1, .Ljp_0809DC80
    lsls	r0, r2, #2
    adds	r0, r0, r2
    lsls	r0, r0, #1
    adds	r2, r0, r1
    ldr r5, .Ljp_0809DC84
    movs	r3, #4
.Ljp_0809DC38:
    ldmia	r5!, {r0}
    adds	r0, r6, r0
    ldrb	r1, [r2, #0]
    strb	r1, [r0, #0]
    adds	r2, #1
    subs	r3, #1
    cmp	r3, #0
    bge .Ljp_0809DC38
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl GetLakeRockTableIndex__C14MineFloorStateUi
    adds	r2, r0, #0
    ldr r1, .Ljp_0809DC88
    lsls	r0, r2, #3
    subs	r0, r0, r2
    lsls	r0, r0, #1
    adds	r2, r0, r1
    ldr r4, .Ljp_0809DC8C
    movs	r3, #9
.Ljp_0809DC60:
    ldmia	r4!, {r0}
    adds	r0, r6, r0
    ldrb	r1, [r2, #0]
    strb	r1, [r0, #0]
    adds	r2, #1
    subs	r3, #1
    cmp	r3, #0
    bge .Ljp_0809DC60
    b .Ljp_0809DCF2
    .align 2, 0
.Ljp_0809DC74:
    .4byte 0x00001BD8
.Ljp_0809DC78:
    .4byte 0x4CC00000
.Ljp_0809DC7C:
    .4byte 0xFFFFFECC
.Ljp_0809DC80:
    .4byte gLakeMineBuriedItemWeights
.Ljp_0809DC84:
    .4byte gLakeMineBuriedItemCodes
.Ljp_0809DC88:
    .4byte gLakeMineRockItemWeights
.Ljp_0809DC8C:
    .4byte gLakeMineRockItemCodes
.Ljp_0809DC90:
    add	r4, sp, #8
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl GetLocation__C6Farmer
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    adds	r4, r0, #0
    subs	r4, #52	@ 0x34
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl GetSpringBuriedItemTableIndex__C14MineFloorStateUi
    adds	r2, r0, #0
    ldr r1, .Ljp_0809DCFC
    lsls	r0, r2, #2
    adds	r0, r0, r2
    adds	r2, r0, r1
    ldr r5, .Ljp_0809DD00
    movs	r3, #9
.Ljp_0809DCBA:
    ldmia	r5!, {r0}
    adds	r0, r6, r0
    ldrb	r1, [r2, #0]
    strb	r1, [r0, #0]
    adds	r2, #1
    subs	r3, #1
    cmp	r3, #0
    bge .Ljp_0809DCBA
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl GetSpringRockTableIndex__C14MineFloorStateUi
    adds	r2, r0, #0
    ldr r1, .Ljp_0809DD04
    lsls	r0, r2, #2
    adds	r0, r0, r2
    lsls	r0, r0, #1
    adds	r2, r0, r1
    ldr r4, .Ljp_0809DD08
    movs	r3, #13
.Ljp_0809DCE2:
    ldmia	r4!, {r0}
    adds	r0, r6, r0
    ldrb	r1, [r2, #0]
    strb	r1, [r0, #0]
    adds	r2, #1
    subs	r3, #1
    cmp	r3, #0
    bge .Ljp_0809DCE2
.Ljp_0809DCF2:
    add	sp, #16
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_0809DCFC:
    .4byte gSpringMineBuriedItemWeights
.Ljp_0809DD00:
    .4byte gSpringMineBuriedItemCodes
.Ljp_0809DD04:
    .4byte gSpringMineRockItemWeights
.Ljp_0809DD08:
    .4byte gSpringMineRockItemCodes

    .else
    .section .text.mine_floor_generation
    .align 2, 0
    thumb_func_start func_0809CF34
func_0809CF34: @ 0x0809CF34
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r0, [sp, #0x34]
    adds r6, r1, #0
    str r2, [sp, #0x38]
    mov r8, r3
    ldr r0, [sp, #0x60]
    mov sb, r0
    add r1, sp, #0x30
    movs r0, #0
    strb r0, [r1]
    strb r0, [r1, #1]
    mov r0, sp
    movs r2, #0xb
    movs r1, #0
    movs r3, #1
    rsbs r3, r3, #0
.L0809CF5E:
    strb r1, [r0]
    strb r1, [r0, #1]
    adds r0, #4
    subs r2, #1
    cmp r2, r3
    bne .L0809CF5E
    movs r0, #0
    movs r1, #0x10
    rsbs r1, r1, #0
    mov ip, r1
    ldr r7, .L0809CFDC @ =0xFFFFFC0F
    movs r5, #3
.L0809CF76:
    movs r3, #0
    lsls r1, r0, #3
    adds r4, r0, #1
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r0, r6, #4
    adds r2, r1, r0
.L0809CF84:
    ldrb r1, [r2]
    mov r0, ip
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    strh r0, [r2]
    ldrb r1, [r2, #1]
    adds r0, r5, #0
    ands r0, r1
    strb r0, [r2, #1]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x1b
    bls .L0809CF84
    adds r0, r4, #0
    cmp r0, #0x1b
    bls .L0809CF76
    ldr r0, [sp, #0x5c]
    cmp r0, #0
    beq .L0809CFC4
    movs r1, #0
    cmp r1, sb
    bhs .L0809CFC4
    adds r3, r0, #0
    mov r2, sp
.L0809CFBA:
    ldm r3!, {r0}
    stm r2!, {r0}
    adds r1, #1
    cmp r1, sb
    blo .L0809CFBA
.L0809CFC4:
    movs r3, #0xff
    mov r1, sp
.L0809CFC8:
    ldrb r2, [r1]
    subs r0, r2, #2
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x37
    bls .L0809CFE0
    adds r0, r2, #0
    orrs r0, r3
    b .L0809CFE6
    .align 2, 0
.L0809CFDC: .4byte 0xFFFFFC0F
.L0809CFE0:
    ldrb r0, [r1]
    subs r0, #2
    asrs r0, r0, #1
.L0809CFE6:
    strb r0, [r1]
    ldrb r2, [r1, #1]
    subs r0, r2, #7
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x37
    bls .L0809CFFA
    adds r0, r2, #0
    orrs r0, r3
    b .L0809D000
.L0809CFFA:
    ldrb r0, [r1, #1]
    subs r0, #7
    asrs r0, r0, #1
.L0809D000:
    strb r0, [r1, #1]
    adds r1, #4
    add r0, sp, #0x2c
    cmp r1, r0
    ble .L0809CFC8
    mov r1, r8
    cmp r1, #0
    bne .L0809D016
    str r1, [r6]
    movs r0, #0x14
    b .L0809D05E
.L0809D016:
    mov r1, r8
    cmp r1, #9
    bne .L0809D02C
    ldr r0, [sp, #0x38]
    cmp r0, #1
    bne .L0809D02C
    movs r0, #4
    str r0, [r6]
    movs r1, #0x28
    mov sl, r1
    b .L0809D060
.L0809D02C:
    mov r0, r8
    movs r1, #5
    bl __umodsi3
    cmp r0, #0
    bne .L0809D042
    movs r0, #1
    str r0, [r6]
    movs r0, #0x96
    lsls r0, r0, #1
    b .L0809D05E
.L0809D042:
    mov r0, r8
    movs r1, #3
    bl __umodsi3
    cmp r0, #0
    bne .L0809D058
    movs r0, #2
    str r0, [r6]
    movs r1, #0x64
    mov sl, r1
    b .L0809D060
.L0809D058:
    movs r0, #3
    str r0, [r6]
    movs r0, #0x1e
.L0809D05E:
    mov sl, r0
.L0809D060:
    mov r1, r8
    cmp r1, #0
    beq .L0809D10E
    bl rand
    adds r4, r0, #0
    adds r0, r6, #0
    bl GetWidth__C14MineFloorState
    adds r1, r0, #0
    asrs r4, r4, #8
    subs r1, #2
    adds r0, r4, #0
    bl __umodsi3
    mov sb, r0
    mov r5, sb
    adds r5, #1
    bl rand
    adds r4, r0, #0
    adds r0, r6, #0
    bl GetHeight__C14MineFloorState
    adds r1, r0, #0
    asrs r4, r4, #8
    subs r1, #2
    adds r0, r4, #0
    bl __umodsi3
    adds r7, r0, #0
    adds r4, r7, #1
    lsls r2, r5, #1
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r2, r2, r0
    adds r2, r6, r2
    ldrb r1, [r2, #4]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strb r0, [r2, #4]
    bl rand
    asrs r1, r0, #8
    movs r0, #3
    ands r1, r0
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq .L0809D0DC
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq .L0809D0D8
    mov r5, sb
    b .L0809D0EA
.L0809D0D8:
    adds r5, #1
    b .L0809D0EA
.L0809D0DC:
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq .L0809D0E8
    adds r4, r7, #0
    b .L0809D0EA
.L0809D0E8:
    adds r4, #1
.L0809D0EA:
    add r0, sp, #0x30
    strb r5, [r0]
    strb r4, [r0, #1]
    ldrb r1, [r0]
    lsls r1, r1, #1
    ldrb r2, [r0, #1]
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r1, r1, r0
    adds r1, r6, r1
    ldrb r2, [r1, #4]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    movs r2, #1
    orrs r0, r2
    strb r0, [r1, #4]
.L0809D10E:
    ldr r1, [sp, #0x38]
    cmp r1, #0
    bne .L0809D122
    adds r0, r6, #0
    mov r1, r8
    mov r2, sl
    mov r3, sp
    bl func_0809D168
    b .L0809D12E
.L0809D122:
    adds r0, r6, #0
    mov r1, r8
    mov r2, sl
    mov r3, sp
    bl func_0809D500
.L0809D12E:
    mov r0, r8
    cmp r0, #0
    beq .L0809D150
    add r0, sp, #0x30
    ldrb r1, [r0]
    lsls r1, r1, #1
    ldrb r2, [r0, #1]
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r1, r1, r0
    adds r1, r6, r1
    ldrb r2, [r1, #4]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1, #4]
.L0809D150:
    ldr r0, [sp, #0x30]
    ldr r1, [sp, #0x34]
    str r0, [r1]
    ldr r0, [sp, #0x34]
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start func_0809D168
func_0809D168: @ 0x0809D168
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov sl, r0
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    bl GetWidth__C14MineFloorState
    str r0, [sp, #0xc]
    mov r0, sl
    bl GetHeight__C14MineFloorState
    str r0, [sp, #0x10]
    mov r0, sl
    ldr r1, [sp]
    bl GetSpringBuriedItemTableIndex__C14MineFloorStateUi
    str r0, [sp, #0x14]
    bl rand
    asrs r0, r0, #4
    ldr r1, [sp, #0x10]
    ldr r2, [sp, #0xc]
    adds r4, r1, #0
    muls r4, r2, r4
    adds r1, r4, #0
    bl __umodsi3
    str r0, [sp, #0x18]
    movs r5, #0
    cmp r5, r4
    blo .L0809D1B2
    b .L0809D2DA
.L0809D1B2:
    str r4, [sp, #0x1c]
.L0809D1B4:
    ldr r3, [sp, #0x18]
    adds r4, r3, r5
    ldr r0, [sp, #0x1c]
    cmp r4, r0
    blo .L0809D1C0
    subs r4, r4, r0
.L0809D1C0:
    adds r0, r4, #0
    ldr r1, [sp, #0xc]
    bl __umodsi3
    mov r8, r0
    adds r0, r4, #0
    ldr r1, [sp, #0xc]
    bl __udivsi3
    adds r7, r0, #0
    mov r1, r8
    lsls r0, r1, #1
    lsls r1, r7, #3
    subs r1, r1, r7
    lsls r1, r1, #3
    adds r0, r0, r1
    add r0, sl
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    adds r5, #1
    str r5, [sp, #0x24]
    cmp r0, #1
    bgt .L0809D2D0
    bl rand
    asrs r2, r0, #4
    movs r0, #0xff
    ands r2, r0
    movs r3, #0
    ldr r4, [sp, #0x14]
    lsls r6, r4, #2
    ldr r4, .L0809D268 @ =gSpringMineBuriedItemWeights
.L0809D202:
    ldr r1, [sp, #0x14]
    adds r0, r6, r1
    adds r0, r3, r0
    adds r1, r0, r4
    ldrb r0, [r1]
    cmp r0, #0
    beq .L0809D2CA
    cmp r2, r0
    bge .L0809D2C4
    ldr r1, .L0809D26C @ =gSpringMineBuriedItemCodes
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r3, [r0]
    mov r2, r8
    lsls r2, r2, #1
    mov sb, r2
    lsls r4, r7, #3
    mov ip, r4
    cmp r3, #1
    bne .L0809D2AC
    cmp r7, #0
    beq .L0809D2A0
    ldr r0, [sp, #0x10]
    subs r0, #1
    cmp r7, r0
    bhs .L0809D2A0
    mov r0, r8
    cmp r0, #0
    beq .L0809D2A0
    ldr r0, [sp, #0xc]
    subs r0, #1
    cmp r8, r0
    bhs .L0809D2A0
    subs r4, r7, #1
    adds r6, r7, #2
    cmp r4, r6
    bge .L0809D2AC
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r5, r0, #3
.L0809D252:
    cmp r4, #0
    blt .L0809D296
    ldr r1, [sp, #0x10]
    cmp r4, r1
    bge .L0809D296
    mov r2, r8
    subs r2, #1
    mov r1, r8
    adds r1, #2
    b .L0809D272
    .align 2, 0
.L0809D268: .4byte gSpringMineBuriedItemWeights
.L0809D26C: .4byte gSpringMineBuriedItemCodes
.L0809D270:
    adds r2, #1
.L0809D272:
    cmp r2, r1
    bge .L0809D292
    cmp r2, #0
    bge .L0809D280
    ldr r0, [sp, #0xc]
    cmp r2, r0
    bge .L0809D270
.L0809D280:
    lsls r0, r2, #1
    adds r0, r0, r5
    add r0, sl
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    cmp r0, #3
    bne .L0809D270
    movs r3, #0
.L0809D292:
    cmp r3, #0
    beq .L0809D2AC
.L0809D296:
    adds r5, #0x38
    adds r4, #1
    cmp r4, r6
    blt .L0809D252
    b .L0809D2AC
.L0809D2A0:
    movs r3, #0
    mov r1, r8
    lsls r1, r1, #1
    mov sb, r1
    lsls r2, r7, #3
    mov ip, r2
.L0809D2AC:
    mov r4, ip
    subs r1, r4, r7
    lsls r1, r1, #3
    add r1, sb
    add r1, sl
    lsls r3, r3, #2
    ldrb r2, [r1, #5]
    movs r0, #3
    ands r0, r2
    orrs r0, r3
    strb r0, [r1, #5]
    b .L0809D2D0
.L0809D2C4:
    subs r2, r2, r0
    cmp r2, #0
    blt .L0809D2D0
.L0809D2CA:
    adds r3, #1
    cmp r3, #4
    ble .L0809D202
.L0809D2D0:
    ldr r5, [sp, #0x24]
    ldr r0, [sp, #0x1c]
    cmp r5, r0
    bhs .L0809D2DA
    b .L0809D1B4
.L0809D2DA:
    mov r0, sl
    ldr r1, [sp]
    bl GetSpringRockTableIndex__C14MineFloorStateUi
    str r0, [sp, #0x14]
    ldr r1, [sp, #4]
    cmp r1, #0
    bgt .L0809D2EC
    b .L0809D402
.L0809D2EC:
    movs r2, #0
    mov r8, r2
    movs r3, #1
    mov sb, r3
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #0x20]
.L0809D2FA:
    bl rand
    asrs r0, r0, #8
    ldr r1, [sp, #0xc]
    bl __umodsi3
    adds r4, r0, #0
    bl rand
    asrs r0, r0, #8
    ldr r1, [sp, #0x10]
    bl __umodsi3
    adds r7, r0, #0
    lsls r1, r4, #1
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r1, r1, r0
    add r1, sl
    ldrb r0, [r1, #4]
    lsls r0, r0, #0x1c
    cmp r0, #0
    bne .L0809D3E6
    movs r0, #1
    mov r8, r0
    movs r2, #0
    ldr r1, [sp, #8]
    ldrb r0, [r1]
    cmp r0, r4
    bne .L0809D370
    ldrb r0, [r1, #1]
    cmp r0, r7
    bne .L0809D370
    mov r8, r2
    b .L0809D38C
.L0809D342:
    subs r3, r5, r7
    lsls r3, r3, #3
    adds r3, r4, r3
    add r3, sl
    ldr r1, .L0809D368 @ =gSpringMineRockItemCodes
    mov r2, ip
    lsls r0, r2, #2
    adds r0, r0, r1
    ldr r2, [r0]
    movs r0, #0x3f
    ands r2, r0
    lsls r2, r2, #4
    ldrh r0, [r3, #4]
    ldr r4, .L0809D36C @ =0xFFFFFC0F
    adds r1, r4, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r3, #4]
    b .L0809D3E6
    .align 2, 0
.L0809D368: .4byte gSpringMineRockItemCodes
.L0809D36C: .4byte 0xFFFFFC0F
.L0809D370:
    adds r2, #1
    cmp r2, #0xb
    bgt .L0809D38C
    lsls r0, r2, #2
    ldr r3, [sp, #8]
    adds r1, r0, r3
    ldrb r0, [r1]
    cmp r0, r4
    bne .L0809D370
    ldrb r0, [r1, #1]
    cmp r0, r7
    bne .L0809D370
    movs r0, #0
    mov r8, r0
.L0809D38C:
    mov r1, r8
    cmp r1, #1
    bne .L0809D3E6
    lsls r4, r4, #1
    lsls r5, r7, #3
    subs r1, r5, r7
    lsls r1, r1, #3
    adds r1, r4, r1
    add r1, sl
    ldrb r0, [r1, #4]
    movs r3, #0x10
    rsbs r3, r3, #0
    adds r2, r3, #0
    ands r0, r2
    movs r2, #4
    orrs r0, r2
    strb r0, [r1, #4]
    bl rand
    asrs r2, r0, #8
    movs r0, #0xff
    ands r2, r0
    movs r0, #0
    mov ip, r0
    ldr r1, [sp, #0x14]
    lsls r6, r1, #2
    ldr r1, .L0809D414 @ =gSpringMineRockItemWeights
    ldr r3, [sp, #0x14]
    adds r0, r6, r3
    lsls r0, r0, #1
    adds r1, r0, r1
.L0809D3CA:
    ldrb r0, [r1]
    cmp r0, #0
    beq .L0809D3DA
    cmp r2, r0
    blt .L0809D342
    subs r2, r2, r0
    cmp r2, #0
    blt .L0809D3E6
.L0809D3DA:
    adds r1, #1
    movs r0, #1
    add ip, r0
    mov r3, ip
    cmp r3, #9
    ble .L0809D3CA
.L0809D3E6:
    mov r4, r8
    cmp r4, #0
    bne .L0809D3F8
    movs r0, #1
    add sb, r0
    mov r1, sb
    cmp r1, #9
    bgt .L0809D3F8
    b .L0809D2FA
.L0809D3F8:
    ldr r2, [sp, #0x20]
    str r2, [sp, #4]
    cmp r2, #0
    ble .L0809D402
    b .L0809D2EC
.L0809D402:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0809D414: .4byte gSpringMineRockItemWeights

    .section .text.mine_floor_placement
    thumb_func_start func_0809D500
func_0809D500: @ 0x0809D500
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov sl, r0
    str r1, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    bl GetWidth__C14MineFloorState
    str r0, [sp, #0xc]
    mov r0, sl
    bl GetHeight__C14MineFloorState
    str r0, [sp, #0x10]
    mov r0, sl
    ldr r1, [sp]
    bl GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    str r0, [sp, #0x14]
    bl rand
    asrs r0, r0, #4
    ldr r1, [sp, #0x10]
    ldr r2, [sp, #0xc]
    adds r4, r1, #0
    muls r4, r2, r4
    adds r1, r4, #0
    bl __umodsi3
    str r0, [sp, #0x18]
    movs r5, #0
    cmp r5, r4
    blo .L0809D54A
    b .L0809D66A
.L0809D54A:
    str r4, [sp, #0x1c]
.L0809D54C:
    ldr r3, [sp, #0x18]
    adds r4, r3, r5
    ldr r0, [sp, #0x1c]
    cmp r4, r0
    blo .L0809D558
    subs r4, r4, r0
.L0809D558:
    adds r0, r4, #0
    ldr r1, [sp, #0xc]
    bl __umodsi3
    adds r7, r0, #0
    adds r0, r4, #0
    ldr r1, [sp, #0xc]
    bl __udivsi3
    adds r6, r0, #0
    lsls r0, r7, #1
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r0, r0, r1
    add r0, sl
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    adds r5, #1
    str r5, [sp, #0x24]
    cmp r0, #1
    bgt .L0809D660
    bl rand
    asrs r2, r0, #4
    movs r0, #0xff
    ands r2, r0
    movs r3, #0
    ldr r1, [sp, #0x14]
    lsls r0, r1, #2
    ldr r1, .L0809D5F8 @ =gLakeMineBuriedItemWeights
    ldr r4, [sp, #0x14]
    adds r0, r0, r4
    lsls r0, r0, #1
    adds r1, r0, r1
.L0809D5A0:
    ldrb r0, [r1]
    cmp r0, #0
    beq .L0809D658
    cmp r2, r0
    bge .L0809D652
    ldr r1, .L0809D5FC @ =gLakeMineBuriedItemCodes
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r3, [r0]
    lsls r0, r7, #1
    mov sb, r0
    lsls r1, r6, #3
    mov r8, r1
    cmp r3, #1
    bne .L0809D63A
    cmp r6, #0
    beq .L0809D630
    ldr r0, [sp, #0x10]
    subs r0, #1
    cmp r6, r0
    bhs .L0809D630
    cmp r7, #0
    beq .L0809D630
    ldr r0, [sp, #0xc]
    subs r0, #1
    cmp r7, r0
    bhs .L0809D630
    subs r4, r6, #1
    adds r2, r6, #2
    mov ip, r2
    cmp r4, ip
    bge .L0809D63A
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r5, r0, #3
.L0809D5E6:
    cmp r4, #0
    blt .L0809D626
    ldr r0, [sp, #0x10]
    cmp r4, r0
    bge .L0809D626
    subs r2, r7, #1
    adds r1, r7, #2
    b .L0809D602
    .align 2, 0
.L0809D5F8: .4byte gLakeMineBuriedItemWeights
.L0809D5FC: .4byte gLakeMineBuriedItemCodes
.L0809D600:
    adds r2, #1
.L0809D602:
    cmp r2, r1
    bge .L0809D622
    cmp r2, #0
    bge .L0809D610
    ldr r0, [sp, #0xc]
    cmp r2, r0
    bge .L0809D600
.L0809D610:
    lsls r0, r2, #1
    adds r0, r0, r5
    add r0, sl
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    cmp r0, #3
    bne .L0809D600
    movs r3, #0
.L0809D622:
    cmp r3, #0
    beq .L0809D63A
.L0809D626:
    adds r5, #0x38
    adds r4, #1
    cmp r4, ip
    blt .L0809D5E6
    b .L0809D63A
.L0809D630:
    movs r3, #0
    lsls r7, r7, #1
    mov sb, r7
    lsls r1, r6, #3
    mov r8, r1
.L0809D63A:
    mov r2, r8
    subs r1, r2, r6
    lsls r1, r1, #3
    add r1, sb
    add r1, sl
    lsls r3, r3, #2
    ldrb r2, [r1, #5]
    movs r0, #3
    ands r0, r2
    orrs r0, r3
    strb r0, [r1, #5]
    b .L0809D660
.L0809D652:
    subs r2, r2, r0
    cmp r2, #0
    blt .L0809D660
.L0809D658:
    adds r1, #1
    adds r3, #1
    cmp r3, #9
    ble .L0809D5A0
.L0809D660:
    ldr r5, [sp, #0x24]
    ldr r3, [sp, #0x1c]
    cmp r5, r3
    bhs .L0809D66A
    b .L0809D54C
.L0809D66A:
    mov r0, sl
    ldr r1, [sp]
    bl GetLakeRockTableIndex__C14MineFloorStateUi
    str r0, [sp, #0x14]
    ldr r4, [sp, #4]
    cmp r4, #0
    bgt .L0809D67C
    b .L0809D788
.L0809D67C:
    movs r0, #0
    mov r8, r0
    movs r1, #1
    mov sb, r1
    ldr r2, [sp, #4]
    subs r2, #1
    str r2, [sp, #0x20]
.L0809D68A:
    bl rand
    asrs r0, r0, #8
    ldr r1, [sp, #0xc]
    bl __umodsi3
    adds r4, r0, #0
    bl rand
    asrs r0, r0, #8
    ldr r1, [sp, #0x10]
    bl __umodsi3
    adds r6, r0, #0
    lsls r1, r4, #1
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r1, r1, r0
    add r1, sl
    ldrb r0, [r1, #4]
    lsls r0, r0, #0x1c
    cmp r0, #0
    bne .L0809D76E
    movs r3, #1
    mov r8, r3
    movs r2, #0
    ldr r1, [sp, #8]
    ldrb r0, [r1]
    cmp r0, r4
    bne .L0809D700
    ldrb r0, [r1, #1]
    cmp r0, r6
    bne .L0809D700
    mov r8, r2
    b .L0809D71C
.L0809D6D2:
    subs r3, r5, r6
    lsls r3, r3, #3
    adds r3, r4, r3
    add r3, sl
    ldr r1, .L0809D6F8 @ =gLakeMineRockItemCodes
    lsls r0, r7, #2
    adds r0, r0, r1
    ldr r2, [r0]
    movs r0, #0x3f
    ands r2, r0
    lsls r2, r2, #4
    ldrh r0, [r3, #4]
    ldr r4, .L0809D6FC @ =0xFFFFFC0F
    adds r1, r4, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r3, #4]
    b .L0809D76E
    .align 2, 0
.L0809D6F8: .4byte gLakeMineRockItemCodes
.L0809D6FC: .4byte 0xFFFFFC0F
.L0809D700:
    adds r2, #1
    cmp r2, #0xb
    bgt .L0809D71C
    lsls r0, r2, #2
    ldr r3, [sp, #8]
    adds r1, r0, r3
    ldrb r0, [r1]
    cmp r0, r4
    bne .L0809D700
    ldrb r0, [r1, #1]
    cmp r0, r6
    bne .L0809D700
    movs r0, #0
    mov r8, r0
.L0809D71C:
    mov r1, r8
    cmp r1, #1
    bne .L0809D76E
    lsls r4, r4, #1
    lsls r5, r6, #3
    subs r1, r5, r6
    lsls r1, r1, #3
    adds r1, r4, r1
    add r1, sl
    ldrb r0, [r1, #4]
    movs r3, #0x10
    rsbs r3, r3, #0
    adds r2, r3, #0
    ands r0, r2
    movs r2, #4
    orrs r0, r2
    strb r0, [r1, #4]
    bl rand
    asrs r2, r0, #8
    movs r0, #0xff
    ands r2, r0
    movs r7, #0
    ldr r1, .L0809D798 @ =gLakeMineRockItemWeights
    ldr r3, [sp, #0x14]
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #1
    adds r1, r0, r1
.L0809D756:
    ldrb r0, [r1]
    cmp r0, #0
    beq .L0809D766
    cmp r2, r0
    blt .L0809D6D2
    subs r2, r2, r0
    cmp r2, #0
    blt .L0809D76E
.L0809D766:
    adds r1, #1
    adds r7, #1
    cmp r7, #0xd
    ble .L0809D756
.L0809D76E:
    mov r4, r8
    cmp r4, #0
    bne .L0809D77E
    movs r0, #1
    add sb, r0
    mov r1, sb
    cmp r1, #9
    ble .L0809D68A
.L0809D77E:
    ldr r2, [sp, #0x20]
    str r2, [sp, #4]
    cmp r2, #0
    ble .L0809D788
    b .L0809D67C
.L0809D788:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0809D798: .4byte gLakeMineRockItemWeights

    thumb_func_start GetLakeBuriedItemTableIndex__C14MineFloorStateUi
GetLakeBuriedItemTableIndex__C14MineFloorStateUi: @ 0x0809D79C
    push {lr}
    adds r0, r1, #0
    cmp r0, #9
    bls .L0809D7D2
    movs r0, #0x19
    cmp r1, #0xff
    beq .L0809D7D2
    movs r0, #0x18
    cmp r1, #0x4f
    bhi .L0809D7D2
    movs r0, #0xa
    movs r2, #0x13
    cmp r1, #0x13
    blo .L0809D7D2
    cmp r1, #0x13
    bne .L0809D7C0
    movs r0, #0xb
    b .L0809D7D2
.L0809D7C0:
    adds r0, #2
    adds r2, #0xa
    cmp r2, #0x4f
    bhi .L0809D7D2
    cmp r1, r2
    blo .L0809D7D2
    cmp r1, r2
    bne .L0809D7C0
    adds r0, #1
.L0809D7D2:
    pop {r1}
    bx r1
    .align 2, 0

    .section .text.mine_floor_item_weights
    thumb_func_start CopyCurrentItemWeights__C14MineFloorStatePUcRC18GameStateSaveImage
CopyCurrentItemWeights__C14MineFloorStatePUcRC18GameStateSaveImage:
.L0809E1B4:
    .byte 0xF0, 0xB5, 0x84, 0xB0, 0x07, 0x1C, 0x0E, 0x1C, 0x1F, 0x48, 0x15, 0x18
    .byte 0x68, 0x46, 0x29, 0x1C
    bl GetLocation__C6Farmer
    .byte 0x68, 0x46, 0x00, 0x88, 0x80, 0x05, 0x1C, 0x49
    .byte 0x88, 0x42, 0x41, 0xDD, 0x02, 0xAC, 0x20, 0x1C, 0x29, 0x1C
    bl GetLocation__C6Farmer
    .byte 0x20, 0x88
    .byte 0x80, 0x05, 0x80, 0x0D, 0x17, 0x49, 0x44, 0x18, 0x38, 0x1C, 0x21, 0x1C
    bl GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .byte 0x02, 0x1C, 0x15, 0x49, 0x90, 0x00, 0x80, 0x18, 0x40, 0x00, 0x42, 0x18, 0x13, 0x4D, 0x04, 0x23
    .byte 0x01, 0xCD, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA
    .byte 0x38, 0x1C, 0x21, 0x1C
    bl GetLakeRockTableIndex__C14MineFloorStateUi
    .byte 0x02, 0x1C, 0x0D, 0x49, 0xD0, 0x00, 0x80, 0x1A
    .byte 0x40, 0x00, 0x42, 0x18, 0x0B, 0x4C, 0x09, 0x23, 0x01, 0xCC, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70
    .byte 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA, 0x3F, 0xE0, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .byte 0x00, 0x00, 0xC0, 0x4C, 0xCC, 0xFE, 0xFF, 0xFF
    .4byte gLakeMineBuriedItemWeights
    .4byte gLakeMineBuriedItemCodes
    .4byte gLakeMineRockItemWeights
    .4byte gLakeMineRockItemCodes
    .byte 0x02, 0xAC, 0x20, 0x1C, 0x29, 0x1C
    bl GetLocation__C6Farmer
    .byte 0x20, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x04, 0x1C, 0x34, 0x3C, 0x38, 0x1C, 0x21, 0x1C
    bl GetSpringBuriedItemTableIndex__C14MineFloorStateUi
    .byte 0x02, 0x1C, 0x13, 0x49, 0x90, 0x00, 0x80, 0x18, 0x42, 0x18, 0x12, 0x4D
    .byte 0x09, 0x23, 0x01, 0xCD, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B
    .byte 0xF7, 0xDA, 0x38, 0x1C, 0x21, 0x1C
    bl GetSpringRockTableIndex__C14MineFloorStateUi
    .byte 0x02, 0x1C, 0x0B, 0x49, 0x90, 0x00
    .byte 0x80, 0x18, 0x40, 0x00, 0x42, 0x18, 0x0A, 0x4C, 0x0D, 0x23, 0x01, 0xCC, 0x30, 0x18, 0x11, 0x78
    .byte 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA, 0x04, 0xB0, 0xF0, 0xBC, 0x01, 0xBC
    .byte 0x00, 0x47, 0x00, 0x00
    .4byte gSpringMineBuriedItemWeights
    .4byte gSpringMineBuriedItemCodes
    .4byte gSpringMineRockItemWeights
    .4byte gSpringMineRockItemCodes
    .endif

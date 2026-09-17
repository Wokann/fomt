    .ifdef REGION_JP
    @ ROM-verified JP Thumb entity UI code
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08035380
    .thumb_func
func_08035380:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #188	@ 0xbc
    adds	r6, r0, #0
    ldr	r5, [r6, #0]
    ldr	r1, [r6, #56]	@ 0x38
    cmp	r1, #0
    bne .Ljp_0803512C
    b .Ljp_0803568C
.Ljp_0803512C:
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #112]	@ 0x70
    cmp	r0, #0
    bne .Ljp_08035140
    b .Ljp_0803568C
.Ljp_08035140:
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    str	r0, [sp, #176]	@ 0xb0
    ldr	r0, [sp, #112]	@ 0x70
    ldrh	r0, [r0, #0]
    cmp	r1, r0
    bcc .Ljp_08035152
    b .Ljp_0803568C
.Ljp_08035152:
    lsls	r1, r1, #3
    ldr	r2, [sp, #112]	@ 0x70
    ldr	r0, [r2, #4]
    adds	r7, r0, r1
    ldr	r3, [r7, #4]
    str	r3, [sp, #116]	@ 0x74
    cmp	r3, #0
    bne .Ljp_08035164
    b .Ljp_0803568C
.Ljp_08035164:
    ldr	r0, [r5, #0]
    movs	r4, #162	@ 0xa2
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r1, [r0, #0]
    adds	r0, r5, #0
    bl _call_via_r1
    ldrh	r3, [r0, #10]
    lsls	r0, r3, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Ljp_08035182
    adds	r2, #24
.Ljp_08035182:
    lsls	r1, r2, #4
    subs	r1, r1, r2
    lsls	r1, r1, #2
    lsls	r0, r3, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    movs	r0, #0
    str	r0, [sp, #120]	@ 0x78
    ldr	r2, [sp, #116]	@ 0x74
    ldr	r3, [r2, #0]
    cmp	r3, #0
    bne .Ljp_0803519C
    b .Ljp_08035654
.Ljp_0803519C:
    ldrh	r4, [r2, #4]
    cmp	r4, #0
    bne .Ljp_080351A4
    b .Ljp_08035654
.Ljp_080351A4:
    adds	r0, r6, #0
    adds	r0, #62	@ 0x3e
    ldrb	r2, [r0, #0]
    str	r0, [sp, #180]	@ 0xb4
    cmp	r2, r4
    bcc .Ljp_080351B2
    b .Ljp_0803568C
.Ljp_080351B2:
    ldr	r4, [sp, #116]	@ 0x74
    ldrb	r0, [r4, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_080351BE
    b .Ljp_080353CC
.Ljp_080351BE:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #124]	@ 0x7c
    movs	r1, #0
    ldrb	r0, [r3, #4]
    lsls	r0, r0, #31
    cmp	r0, #0
    bne .Ljp_080351D0
    movs	r1, #1
.Ljp_080351D0:
    mov	r8, r1
    ldr	r0, [r6, #8]
    str	r0, [sp, #0]
    ldr	r0, [r6, #12]
    str	r0, [sp, #8]
    ldr	r0, [r6, #24]
    str	r0, [sp, #4]
    ldr	r0, [r6, #28]
    str	r0, [sp, #12]
    cmp	r1, #0
    beq .Ljp_080351F0
    mov	sl, sp
    mov	r7, sp
    adds	r7, #4
    str	r7, [sp, #128]	@ 0x80
    b .Ljp_080351FA
.Ljp_080351F0:
    add	r0, sp, #8
    mov	sl, r0
    mov	r1, sp
    adds	r1, #12
    str	r1, [sp, #128]	@ 0x80
.Ljp_080351FA:
    mov	r2, sl
    ldr	r1, [r2, #0]
    asrs	r3, r1, #16
    str	r3, [sp, #132]	@ 0x84
    ldr	r4, [sp, #128]	@ 0x80
    ldr	r0, [r4, #0]
    adds	r1, r1, r0
    str	r1, [sp, #136]	@ 0x88
    asrs	r7, r1, #16
    str	r7, [sp, #140]	@ 0x8c
    subs	r7, r7, r3
    movs	r3, #0
    adds	r0, r6, #0
    adds	r0, #64	@ 0x40
    ldrh	r2, [r0, #0]
    ldr r1, .Ljp_08035240
    str	r0, [sp, #184]	@ 0xb8
    cmp	r2, r1
    blt .Ljp_08035222
    movs	r3, #1
.Ljp_08035222:
    movs	r0, #1
    str	r0, [sp, #144]	@ 0x90
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Ljp_08035252
    movs	r4, #0
    str	r4, [sp, #144]	@ 0x90
    cmp	r3, #0
    beq .Ljp_08035244
    strb	r4, [r1, #0]
    b .Ljp_08035248
    .align 2, 0
.Ljp_08035240:
    .4byte 0x000002EE
.Ljp_08035244:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Ljp_08035248:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_08035252
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Ljp_08035252:
    cmp	r3, #0
    bne .Ljp_08035334
    cmp	r7, #0
    beq .Ljp_08035334
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08035334
    ldrh	r0, [r4, #4]
    ldrh	r2, [r6, #4]
    cmp	r0, r2
    bne .Ljp_08035334
    ldr	r1, [r6, #20]
    add	r0, sp, #16
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #16]
    ldr	r1, [sp, #20]
    str	r0, [sp, #24]
    str	r1, [sp, #28]
    add	r5, sp, #24
    ldr	r1, [r4, #20]
    add	r0, sp, #32
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #32]
    ldr	r1, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    add	r4, sp, #40	@ 0x28
    mov	r3, r8
    cmp	r3, #0
    beq .Ljp_080352AC
    adds	r2, r7, #0
    movs	r7, #0
    b .Ljp_080352AE
.Ljp_080352AC:
    movs	r2, #0
.Ljp_080352AE:
    mov	r9, r7
    movs	r1, #0
    ldrsh	r0, [r5, r1]
    mov	ip, r0
    movs	r3, #4
    ldrsh	r1, [r4, r3]
    subs	r1, r0, r1
    movs	r7, #0
    ldrsh	r0, [r4, r7]
    movs	r7, #4
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    subs	r0, r0, r3
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Ljp_08035334
    add	r3, sp, #48	@ 0x30
    mov	r1, ip
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, r8
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Ljp_08035334
    movs	r5, #0
    str	r5, [sp, #144]	@ 0x90
.Ljp_08035334:
    ldr	r7, [sp, #144]	@ 0x90
    cmp	r7, #0
    beq .Ljp_080353C2
    ldr	r1, [sp, #124]	@ 0x7c
    movs	r2, #2
    ldrsh	r0, [r1, r2]
    ldr	r3, [sp, #132]	@ 0x84
    cmp	r3, r0
    beq .Ljp_08035364
    ldr	r4, [sp, #140]	@ 0x8c
    cmp	r4, r0
    beq .Ljp_08035364
    movs	r1, #0
    cmp	r0, r3
    bge .Ljp_08035354
    movs	r1, #1
.Ljp_08035354:
    ldr	r5, [sp, #140]	@ 0x8c
    cmp	r0, r5
    bge .Ljp_08035360
    cmp	r1, #0
    beq .Ljp_08035364
    b .Ljp_080353AA
.Ljp_08035360:
    cmp	r1, #0
    beq .Ljp_080353AA
.Ljp_08035364:
    lsls	r0, r0, #16
    mov	r7, sl
    str	r0, [r7, #0]
    movs	r1, #0
    ldr	r0, [sp, #128]	@ 0x80
    str	r1, [r0, #0]
    ldr	r2, [sp, #180]	@ 0xb4
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r3, [sp, #116]	@ 0x74
    ldrh	r3, [r3, #4]
    cmp	r0, r3
    bcs .Ljp_0803538A
    movs	r4, #1
    str	r4, [sp, #120]	@ 0x78
    b .Ljp_080353B0
.Ljp_0803538A:
    ldr	r5, [sp, #176]	@ 0xb0
    ldrb	r0, [r5, #0]
    adds	r0, #1
    ldr	r7, [sp, #112]	@ 0x70
    ldrh	r7, [r7, #0]
    cmp	r0, r7
    blt .Ljp_0803539A
    b .Ljp_0803568C
.Ljp_0803539A:
    ldr	r0, [sp, #180]	@ 0xb4
    strb	r1, [r0, #0]
    ldrb	r0, [r5, #0]
    adds	r0, #1
    strb	r0, [r5, #0]
    movs	r1, #2
    str	r1, [sp, #120]	@ 0x78
    b .Ljp_080353B0
.Ljp_080353AA:
    ldr	r2, [sp, #136]	@ 0x88
    mov	r3, sl
    str	r2, [r3, #0]
.Ljp_080353B0:
    ldr	r0, [sp, #0]
    str	r0, [r6, #8]
    ldr	r0, [sp, #8]
    str	r0, [r6, #12]
    ldr	r0, [sp, #4]
    str	r0, [r6, #24]
    ldr	r0, [sp, #12]
    str	r0, [r6, #28]
    b .Ljp_0803567A
.Ljp_080353C2:
    ldr	r4, [sp, #184]	@ 0xb8
    ldrh	r0, [r4, #0]
    adds	r0, #1
    strh	r0, [r4, #0]
    b .Ljp_0803567A
.Ljp_080353CC:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #148]	@ 0x94
    movs	r2, #0
    ldrb	r0, [r3, #6]
    lsls	r0, r0, #29
    cmp	r0, #0
    blt .Ljp_080353DE
    movs	r2, #1
.Ljp_080353DE:
    mov	r8, r2
    movs	r2, #0
    ldr	r3, [sp, #176]	@ 0xb0
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldr	r4, [sp, #112]	@ 0x70
    ldrh	r4, [r4, #0]
    cmp	r0, r4
    bge .Ljp_080353F8
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Ljp_080353F8
    movs	r2, #1
.Ljp_080353F8:
    mov	sl, r2
    cmp	r2, #0
    beq .Ljp_08035416
    ldrh	r4, [r6, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #20]
    adds	r0, r5, #0
    bl _call_via_r1
    cmp	r4, r0
    beq .Ljp_08035416
    movs	r0, #0
    ldr	r5, [sp, #180]	@ 0xb4
    strb	r0, [r5, #0]
    b .Ljp_08035640
.Ljp_08035416:
    adds	r1, r6, #0
    adds	r1, #64	@ 0x40
    ldrh	r0, [r1, #0]
    str	r1, [sp, #184]	@ 0xb8
    cmp	r0, #0
    beq .Ljp_08035424
    b .Ljp_08035608
.Ljp_08035424:
    ldr	r0, [r6, #8]
    str	r0, [sp, #56]	@ 0x38
    ldr	r0, [r6, #12]
    str	r0, [sp, #64]	@ 0x40
    ldr	r0, [r6, #24]
    str	r0, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #28]
    str	r0, [sp, #68]	@ 0x44
    mov	r1, r8
    cmp	r1, #0
    beq .Ljp_08035448
    mov	r2, sp
    adds	r2, #56	@ 0x38
    str	r2, [sp, #152]	@ 0x98
    mov	r3, sp
    adds	r3, #60	@ 0x3c
    str	r3, [sp, #156]	@ 0x9c
    b .Ljp_08035454
.Ljp_08035448:
    mov	r4, sp
    adds	r4, #64	@ 0x40
    str	r4, [sp, #152]	@ 0x98
    mov	r7, sp
    adds	r7, #68	@ 0x44
    str	r7, [sp, #156]	@ 0x9c
.Ljp_08035454:
    ldr	r1, [sp, #152]	@ 0x98
    ldr	r0, [r1, #0]
    asrs	r2, r0, #16
    str	r2, [sp, #160]	@ 0xa0
    ldr	r3, [sp, #156]	@ 0x9c
    ldr	r1, [r3, #0]
    adds	r0, r0, r1
    str	r0, [sp, #164]	@ 0xa4
    asrs	r4, r0, #16
    str	r4, [sp, #168]	@ 0xa8
    subs	r7, r4, r2
    movs	r0, #1
    str	r0, [sp, #172]	@ 0xac
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Ljp_08035496
    movs	r3, #0
    str	r3, [sp, #172]	@ 0xac
    mov	r4, sl
    cmp	r4, #0
    beq .Ljp_08035488
    strb	r3, [r1, #0]
    b .Ljp_0803548C
.Ljp_08035488:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Ljp_0803548C:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_08035496
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Ljp_08035496:
    mov	r2, sl
    cmp	r2, #0
    bne .Ljp_0803557C
    cmp	r7, #0
    beq .Ljp_0803557C
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_0803557C
    ldrh	r0, [r4, #4]
    ldrh	r3, [r6, #4]
    cmp	r0, r3
    bne .Ljp_0803557C
    ldr	r1, [r6, #20]
    add	r0, sp, #72	@ 0x48
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #72]	@ 0x48
    ldr	r1, [sp, #76]	@ 0x4c
    str	r0, [sp, #80]	@ 0x50
    str	r1, [sp, #84]	@ 0x54
    add	r5, sp, #80	@ 0x50
    ldr	r1, [r4, #20]
    add	r0, sp, #88	@ 0x58
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #96]	@ 0x60
    str	r1, [sp, #100]	@ 0x64
    add	r4, sp, #96	@ 0x60
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_080354F4
    adds	r2, r7, #0
    movs	r1, #0
    mov	r9, r1
    b .Ljp_080354F8
.Ljp_080354F4:
    movs	r2, #0
    mov	r9, r7
.Ljp_080354F8:
    movs	r7, #0
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    movs	r0, #4
    ldrsh	r1, [r4, r0]
    subs	r1, r3, r1
    movs	r3, #0
    ldrsh	r0, [r4, r3]
    movs	r3, #4
    ldrsh	r7, [r5, r3]
    mov	ip, r7
    subs	r0, r0, r7
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Ljp_0803557C
    add	r3, sp, #104	@ 0x68
    mov	r1, r8
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, ip
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Ljp_0803557C
    movs	r5, #0
    str	r5, [sp, #172]	@ 0xac
.Ljp_0803557C:
    ldr	r7, [sp, #172]	@ 0xac
    cmp	r7, #0
    beq .Ljp_0803567A
    ldr	r0, [sp, #148]	@ 0x94
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    ldr	r3, [sp, #168]	@ 0xa8
    cmp	r3, r2
    beq .Ljp_0803559A
    ldr	r4, [sp, #160]	@ 0xa0
    subs	r0, r2, r4
    subs	r1, r2, r3
    eors	r0, r1
    cmp	r0, #0
    bge .Ljp_080355F0
.Ljp_0803559A:
    lsls	r0, r2, #16
    ldr	r5, [sp, #152]	@ 0x98
    str	r0, [r5, #0]
    movs	r1, #0
    ldr	r7, [sp, #156]	@ 0x9c
    str	r1, [r7, #0]
    mov	r0, sl
    cmp	r0, #0
    bne .Ljp_080355B4
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r0, [r2, #4]
    cmp	r0, #0
    bne .Ljp_080355E4
.Ljp_080355B4:
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Ljp_080355DE
    strb	r1, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Ljp_080355D8
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Ljp_080355D8:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Ljp_080355F6
.Ljp_080355DE:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Ljp_080355F6
.Ljp_080355E4:
    movs	r0, #1
    ldr	r2, [sp, #184]	@ 0xb8
    strh	r0, [r2, #0]
    movs	r3, #1
    str	r3, [sp, #120]	@ 0x78
    b .Ljp_080355F6
.Ljp_080355F0:
    ldr	r4, [sp, #164]	@ 0xa4
    ldr	r5, [sp, #152]	@ 0x98
    str	r4, [r5, #0]
.Ljp_080355F6:
    ldr	r0, [sp, #56]	@ 0x38
    str	r0, [r6, #8]
    ldr	r0, [sp, #64]	@ 0x40
    str	r0, [r6, #12]
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [r6, #24]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [r6, #28]
    b .Ljp_0803567A
.Ljp_08035608:
    mov	r7, sl
    cmp	r7, #0
    bne .Ljp_0803561E
    adds	r0, #1
    strh	r0, [r1, #0]
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r2, [r2, #4]
    cmp	r0, r2
    bls .Ljp_0803567A
.Ljp_0803561E:
    movs	r0, #0
    strh	r0, [r1, #0]
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Ljp_0803564E
    movs	r0, #0
    strb	r0, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Ljp_08035648
.Ljp_08035640:
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Ljp_08035648:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Ljp_08035680
.Ljp_0803564E:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Ljp_08035680
.Ljp_08035654:
    ldr	r2, [sp, #176]	@ 0xb0
    ldrb	r0, [r2, #0]
    adds	r0, #1
    ldr	r3, [sp, #112]	@ 0x70
    ldrh	r3, [r3, #0]
    cmp	r0, r3
    bge .Ljp_0803567A
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Ljp_0803567A
    adds	r1, r6, #0
    adds	r1, #62	@ 0x3e
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    movs	r4, #2
    str	r4, [sp, #120]	@ 0x78
.Ljp_0803567A:
    ldr	r5, [sp, #120]	@ 0x78
    cmp	r5, #0
    ble .Ljp_0803568C
.Ljp_08035680:
    ldr	r0, [r6, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r6, #0
    ldr	r1, [sp, #120]	@ 0x78
    bl _call_via_r2
.Ljp_0803568C:
    add	sp, #188	@ 0xbc
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08035908
    .thumb_func
func_08035908:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #68	@ 0x44
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Ljp_080356CE
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080356CE
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Ljp_080356CE
    cmp	r0, r5
    beq .Ljp_080356CE
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Ljp_080356CE:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035940
    .thumb_func
func_08035940:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #70	@ 0x46
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Ljp_08035706
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08035706
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Ljp_08035706
    cmp	r0, r5
    beq .Ljp_08035706
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08035706:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035978
    .thumb_func
func_08035978:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080357CE
    ldr	r1, [r4, #56]	@ 0x38
    cmp	r1, #0
    beq .Ljp_080357CE
    adds	r0, r4, #0
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r6, [r0, #0]
    cmp	r6, #0
    beq .Ljp_080357CE
    adds	r0, r4, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    mov	r8, r0
    ldrh	r0, [r6, #0]
    cmp	r1, r0
    bcs .Ljp_080357CE
    lsls	r1, r1, #3
    ldr	r0, [r6, #4]
    adds	r7, r0, r1
    ldr	r5, [r7, #4]
    cmp	r5, #0
    beq .Ljp_080357CE
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r1, [r0, #10]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Ljp_08035774
    adds	r2, #24
.Ljp_08035774:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r1, r0, r1
    ldr	r0, [r5, #0]
    cmp	r0, #0
    beq .Ljp_080357B4
    ldrh	r2, [r5, #4]
    cmp	r2, #0
    beq .Ljp_080357B4
    adds	r0, r4, #0
    adds	r0, #62	@ 0x3e
    ldrb	r0, [r0, #0]
    cmp	r0, r2
    bcs .Ljp_080357CE
    ldrb	r0, [r5, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Ljp_080357B4
    movs	r2, #0
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    ldrh	r1, [r0, #0]
    ldr r0, .Ljp_080357B0
    cmp	r1, r0
    blt .Ljp_080357CA
    b .Ljp_080357C8
    .align 2, 0
.Ljp_080357B0:
    .4byte 0x000002EE
.Ljp_080357B4:
    movs	r2, #0
    mov	r3, r8
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldrh	r6, [r6, #0]
    cmp	r0, r6
    bge .Ljp_080357CA
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Ljp_080357CA
.Ljp_080357C8:
    movs	r2, #1
.Ljp_080357CA:
    adds	r0, r2, #0
    b .Ljp_080357D0
.Ljp_080357CE:
    movs	r0, #0
.Ljp_080357D0:
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035A48
    .thumb_func
func_08035A48:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r3, r1, #0
    ldrh	r1, [r4, #4]
    ldrh	r0, [r3, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r1, r0
    bne .Ljp_0803586A
    movs	r0, #10
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #2]
    ldr r5, .Ljp_08035870
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Ljp_0803580C
    negs	r0, r0
.Ljp_0803580C:
    cmp	r0, #151	@ 0x97
    bgt .Ljp_0803586A
    movs	r0, #14
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #4]
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Ljp_0803582C
    negs	r0, r0
.Ljp_0803582C:
    cmp	r0, #111	@ 0x6f
    bgt .Ljp_0803586A
    adds	r0, r4, #0
    bl func_08035978
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803586A
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803586A
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r1, r4, #0
    adds	r1, #63	@ 0x3f
    movs	r0, #120	@ 0x78
    strb	r0, [r1, #0]
    ldr	r0, [r4, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    movs	r1, #1
    bl _call_via_r2
.Ljp_0803586A:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Ljp_08035870:
    .4byte 0x000003FF
    .global func_08035AE0
    .thumb_func
func_08035AE0:
    push	{lr}
    adds	r1, r0, #0
    movs	r2, #0
    ldrh	r0, [r1, #4]
    cmp	r0, #29
    bne .Ljp_0803588A
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    cmp	r0, #55	@ 0x37
    bgt .Ljp_0803588A
    movs	r2, #1
.Ljp_0803588A:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .global func_08035AFC
    .thumb_func
func_08035AFC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080358BC
    str	r0, [sp, #0]
    ldr r0, .Ljp_080358C0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_080358C4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080358C8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080358BC:
    .4byte gUnk_080F2068
.Ljp_080358C0:
    .4byte 0x0000025F
.Ljp_080358C4:
    .4byte 0x000003E2
.Ljp_080358C8:
    .4byte vtable_unk_080E7198
    .global func_08035B38
    .thumb_func
func_08035B38:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035B64
    .thumb_func
func_08035B64:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035924
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035928
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #248	@ 0xf8
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_0803592C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08035924:
    .4byte ScheduleInfo_Unk_080F1A80
.Ljp_08035928:
    .4byte 0x00000213
.Ljp_0803592C:
    .4byte vtable_unk_080E7158
    .global func_08035B9C
    .thumb_func
func_08035B9C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035BC8
    .thumb_func
func_08035BC8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035988
    str	r0, [sp, #0]
    ldr r0, .Ljp_0803598C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035990
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035994
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035988:
    .4byte gUnk_080F1FC0
.Ljp_0803598C:
    .4byte 0x0000022F
.Ljp_08035990:
    .4byte 0x000003E1
.Ljp_08035994:
    .4byte vtable_unk_080E7118
    .global func_08035C04
    .thumb_func
func_08035C04:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Ljp_080359DC
    ldr r0, .Ljp_080359E0
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Ljp_080359E4
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #3
    bne .Ljp_08035A28
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Ljp_08035A28
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080359D6
    ldr r2, .Ljp_080359E8
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_080359F0
.Ljp_080359D6:
    ldr r7, .Ljp_080359EC
    b .Ljp_08035A28
    .align 2, 0
.Ljp_080359DC:
    .4byte 0x0000022F
.Ljp_080359E0:
    .4byte 0x00000233
.Ljp_080359E4:
    .4byte 0x00001CD4
.Ljp_080359E8:
    .4byte 0x0000216B
.Ljp_080359EC:
    .4byte 0x0000023F
.Ljp_080359F0:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_08035A28
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08035A28
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08035A28
    ldr r7, .Ljp_08035A44
    ldr r0, .Ljp_08035A48
    mov	r8, r0
.Ljp_08035A28:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08035A44:
    .4byte 0x00000247
.Ljp_08035A48:
    .4byte 0x0000024B
    .global func_08035CB8
    .thumb_func
func_08035CB8:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_08035A60
    adds	r0, r5, #0
    bl func_08035C04
.Ljp_08035A60:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08035CD4
    .thumb_func
func_08035CD4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08035C04
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035D04
    .thumb_func
func_08035D04:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035AC4
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035AC8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035ACC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035AD0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035AC4:
    .4byte gUnk_080F8678
.Ljp_08035AC8:
    .4byte 0x000009EF
.Ljp_08035ACC:
    .4byte 0x00000406
.Ljp_08035AD0:
    .4byte vtable_unk_080E70D8
    .global func_08035D40
    .thumb_func
func_08035D40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #3
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035D70
    .thumb_func
func_08035D70:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035B30
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035B34
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035B38
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035B3C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035B30:
    .4byte gUnk_080F81BC
.Ljp_08035B34:
    .4byte 0x000009E7
.Ljp_08035B38:
    .4byte 0x00000405
.Ljp_08035B3C:
    .4byte vtable_unk_080E7098
    .global func_08035DAC
    .thumb_func
func_08035DAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035DD8
    .thumb_func
func_08035DD8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035B98
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035B9C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035BA0
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035BA4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035B98:
    .4byte gUnk_080F77FC
.Ljp_08035B9C:
    .4byte 0x000009A1
.Ljp_08035BA0:
    .4byte 0x00000403
.Ljp_08035BA4:
    .4byte vtable_unk_080E7058
    .global func_08035E14
    .thumb_func
func_08035E14:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035E40
    .thumb_func
func_08035E40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035C00
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035C04
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035C08
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035C0C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035C00:
    .4byte gUnk_080F7294
.Ljp_08035C04:
    .4byte 0x00000989
.Ljp_08035C08:
    .4byte 0x00000402
.Ljp_08035C0C:
    .4byte vtable_unk_080E7018
    .global func_08035E7C
    .thumb_func
func_08035E7C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035EAC
    .thumb_func
func_08035EAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035C70
    str	r0, [sp, #0]
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035C74
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035C70:
    .4byte gUnk_080F6370
.Ljp_08035C74:
    .4byte vtable_unk_080E6FD8
    .global func_08035EE4
    .thumb_func
func_08035EE4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F10
    .thumb_func
func_08035F10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035CD0
    str	r0, [sp, #0]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035CD4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035CD8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08035CD0:
    .4byte gUnk_080F66C4
.Ljp_08035CD4:
    .4byte 0x000003FD
.Ljp_08035CD8:
    .4byte vtable_unk_080E6F98
    .global func_08035F48
    .thumb_func
func_08035F48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F74
    .thumb_func
func_08035F74:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035D34
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035D38
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035D3C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035D40
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035D34:
    .4byte gUnk_080F49C0
.Ljp_08035D38:
    .4byte 0x0000080B
.Ljp_08035D3C:
    .4byte 0x000003F5
.Ljp_08035D40:
    .4byte vtable_unk_080E6F58
    .global func_08035FB0
    .thumb_func
func_08035FB0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035FE0
    .thumb_func
func_08035FE0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035DA0
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035DA4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035DA8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035DAC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035DA0:
    .4byte gUnk_080F5540
.Ljp_08035DA4:
    .4byte 0x0000084B
.Ljp_08035DA8:
    .4byte 0x000003F7
.Ljp_08035DAC:
    .4byte vtable_unk_080E6F18
    .global func_0803601C
    .thumb_func
func_0803601C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036048
    .thumb_func
func_08036048:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035E08
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035E0C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035E10
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035E14
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035E08:
    .4byte gUnk_080F4D74
.Ljp_08035E0C:
    .4byte 0x00000813
.Ljp_08035E10:
    .4byte 0x000003F6
.Ljp_08035E14:
    .4byte vtable_unk_080E6ED8
    .global func_08036084
    .thumb_func
func_08036084:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Ljp_08035E5C
    ldr r0, .Ljp_08035E60
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Ljp_08035E64
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #12
    bne .Ljp_08035EA8
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Ljp_08035EA8
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08035E56
    ldr r2, .Ljp_08035E68
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_08035E70
.Ljp_08035E56:
    ldr r7, .Ljp_08035E6C
    b .Ljp_08035EA8
    .align 2, 0
.Ljp_08035E5C:
    .4byte 0x00000813
.Ljp_08035E60:
    .4byte 0x00000817
.Ljp_08035E64:
    .4byte 0x00001CD4
.Ljp_08035E68:
    .4byte 0x0000216C
.Ljp_08035E6C:
    .4byte 0x00000827
.Ljp_08035E70:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_08035EA8
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08035EA8
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08035EA8
    ldr r7, .Ljp_08035EC4
    ldr r0, .Ljp_08035EC8
    mov	r8, r0
.Ljp_08035EA8:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08035EC4:
    .4byte 0x0000082F
.Ljp_08035EC8:
    .4byte 0x00000833
    .global func_08036138
    .thumb_func
func_08036138:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_08035EE0
    adds	r0, r5, #0
    bl func_08036084
.Ljp_08035EE0:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036154
    .thumb_func
func_08036154:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036084
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036184
    .thumb_func
func_08036184:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035F44
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035F48
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035F4C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035F50
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035F44:
    .4byte gUnk_080F59CC
.Ljp_08035F48:
    .4byte 0x0000085F
.Ljp_08035F4C:
    .4byte 0x000003F9
.Ljp_08035F50:
    .4byte vtable_unk_080E6E98
    .global func_080361C0
    .thumb_func
func_080361C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080361EC
    .thumb_func
func_080361EC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08035FAC
    str	r0, [sp, #0]
    ldr r0, .Ljp_08035FB0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08035FB4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08035FB8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08035FAC:
    .4byte gUnk_080F6B4C
.Ljp_08035FB0:
    .4byte 0x000008E4
.Ljp_08035FB4:
    .4byte 0x000003FF
.Ljp_08035FB8:
    .4byte vtable_unk_080E6E58
    .global func_08036228
    .thumb_func
func_08036228:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036258
    .thumb_func
func_08036258:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036014
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036018
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    ldr r0, .Ljp_0803601C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036020
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08036014:
    .4byte gUnk_080F33B8
.Ljp_08036018:
    .4byte 0x00000685
.Ljp_0803601C:
    .4byte 0x000003EE
.Ljp_08036020:
    .4byte vtable_unk_080E6E18
    .global func_08036290
    .thumb_func
func_08036290:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080362C0
    .thumb_func
func_080362C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036080
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036084
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036088
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_0803608C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036080:
    .4byte gUnk_080F61FC
.Ljp_08036084:
    .4byte 0x000008B8
.Ljp_08036088:
    .4byte 0x000003FB
.Ljp_0803608C:
    .4byte vtable_unk_080E6DD8
    .global func_080362FC
    .thumb_func
func_080362FC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036328
    .thumb_func
func_08036328:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080360E8
    str	r0, [sp, #0]
    ldr r0, .Ljp_080360EC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_080360F0
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080360F4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080360E8:
    .4byte gUnk_080F3408
.Ljp_080360EC:
    .4byte 0x00000689
.Ljp_080360F0:
    .4byte 0x000003EF
.Ljp_080360F4:
    .4byte vtable_unk_080E6D98
    .global func_08036364
    .thumb_func
func_08036364:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036390
    .thumb_func
func_08036390:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036150
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036154
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036158
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_0803615C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036150:
    .4byte gUnk_080F3FD8
.Ljp_08036154:
    .4byte 0x000006C5
.Ljp_08036158:
    .4byte 0x000003F1
.Ljp_0803615C:
    .4byte vtable_unk_080E6D58
    .global func_080363CC
    .thumb_func
func_080363CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080363F8
    .thumb_func
func_080363F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080361B8
    str	r0, [sp, #0]
    ldr r0, .Ljp_080361BC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #252	@ 0xfc
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080361C0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_080361B8:
    .4byte gUnk_080F35E4
.Ljp_080361BC:
    .4byte 0x00000691
.Ljp_080361C0:
    .4byte vtable_unk_080E6D18
    .global func_08036430
    .thumb_func
func_08036430:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Ljp_08036208
    ldr r0, .Ljp_0803620C
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Ljp_08036210
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #19
    bne .Ljp_08036254
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Ljp_08036254
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08036202
    ldr r2, .Ljp_08036214
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803621C
.Ljp_08036202:
    ldr r7, .Ljp_08036218
    b .Ljp_08036254
    .align 2, 0
.Ljp_08036208:
    .4byte 0x00000691
.Ljp_0803620C:
    .4byte 0x00000695
.Ljp_08036210:
    .4byte 0x00001CD4
.Ljp_08036214:
    .4byte 0x0000216C
.Ljp_08036218:
    .4byte 0x000006A1
.Ljp_0803621C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_08036254
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08036254
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08036254
    ldr r7, .Ljp_08036270
    ldr r0, .Ljp_08036274
    mov	r8, r0
.Ljp_08036254:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08036270:
    .4byte 0x000006AD
.Ljp_08036274:
    .4byte 0x000006B1
    .global func_080364E4
    .thumb_func
func_080364E4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_0803628C
    adds	r0, r5, #0
    bl func_08036430
.Ljp_0803628C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036500
    .thumb_func
func_08036500:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036430
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036530
    .thumb_func
func_08036530:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080362F0
    str	r0, [sp, #0]
    movs	r0, #200	@ 0xc8
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #194	@ 0xc2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080362F4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_080362F0:
    .4byte ScheduleInfo_Unk_080F286C
.Ljp_080362F4:
    .4byte vtable_unk_080E6CD8
    .global func_08036564
    .thumb_func
func_08036564:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036590
    .thumb_func
func_08036590:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036350
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036354
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036358
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_0803635C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036350:
    .4byte gUnk_080F5D94
.Ljp_08036354:
    .4byte 0x00000884
.Ljp_08036358:
    .4byte 0x000003FA
.Ljp_0803635C:
    .4byte vtable_unk_080E6C98
    .global func_080365CC
    .thumb_func
func_080365CC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Ljp_080363A4
    ldr r0, .Ljp_080363A8
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Ljp_080363AC
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #21
    bne .Ljp_080363F0
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Ljp_080363F0
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803639E
    ldr r2, .Ljp_080363B0
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_080363B8
.Ljp_0803639E:
    ldr r7, .Ljp_080363B4
    b .Ljp_080363F0
    .align 2, 0
.Ljp_080363A4:
    .4byte 0x00000884
.Ljp_080363A8:
    .4byte 0x00000888
.Ljp_080363AC:
    .4byte 0x00001CD4
.Ljp_080363B0:
    .4byte 0x0000216C
.Ljp_080363B4:
    .4byte 0x0000089C
.Ljp_080363B8:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_080363F0
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_080363F0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_080363F0
    ldr r7, .Ljp_0803640C
    ldr r0, .Ljp_08036410
    mov	r8, r0
.Ljp_080363F0:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_0803640C:
    .4byte 0x00000894
.Ljp_08036410:
    .4byte 0x00000898
    .global func_08036680
    .thumb_func
func_08036680:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_08036428
    adds	r0, r5, #0
    bl func_080365CC
.Ljp_08036428:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803669C
    .thumb_func
func_0803669C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_080365CC
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080366CC
    .thumb_func
func_080366CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_0803648C
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036490
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #3
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036494
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_0803648C:
    .4byte gUnk_080F6DE8
.Ljp_08036490:
    .4byte 0x000008EC
.Ljp_08036494:
    .4byte vtable_unk_080E6C58
    .global func_08036704
    .thumb_func
func_08036704:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036730
    .thumb_func
func_08036730:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080364F0
    str	r0, [sp, #0]
    ldr r0, .Ljp_080364F4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #249	@ 0xf9
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080364F8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_080364F0:
    .4byte ScheduleInfo_Unk_080F2354
.Ljp_080364F4:
    .4byte 0x0000027B
.Ljp_080364F8:
    .4byte vtable_unk_080E6C18
    .global func_08036768
    .thumb_func
func_08036768:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Ljp_08036534
    movs	r5, #2
    ldr	r0, [r4, #52]	@ 0x34
    ldr r2, .Ljp_08036538
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_08036518
    adds	r1, #24
    movs	r5, #1
.Ljp_08036518:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    ldr r1, .Ljp_0803653C
    bl func_08035940
    adds	r0, r4, #0
    adds	r0, #33	@ 0x21
    strb	r5, [r0, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08036534:
    .4byte 0x0000027B
.Ljp_08036538:
    .4byte 0x00002181
.Ljp_0803653C:
    .4byte 0x0000027F
    .global func_080367AC
    .thumb_func
func_080367AC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_08036554
    adds	r0, r5, #0
    bl func_08036768
.Ljp_08036554:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080367C8
    .thumb_func
func_080367C8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036768
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080367F8
    .thumb_func
func_080367F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080365B8
    str	r0, [sp, #0]
    ldr r0, .Ljp_080365BC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_080365C0
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080365C4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080365B8:
    .4byte gUnk_080F42F0
.Ljp_080365BC:
    .4byte 0x000007B2
.Ljp_080365C0:
    .4byte 0x000003F2
.Ljp_080365C4:
    .4byte vtable_unk_080E6BD8
    .global func_08036834
    .thumb_func
func_08036834:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036860
    .thumb_func
func_08036860:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036620
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036624
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #253	@ 0xfd
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036628
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08036620:
    .4byte gUnk_080F4974
.Ljp_08036624:
    .4byte 0x000007F2
.Ljp_08036628:
    .4byte vtable_unk_080E6B98
    .global func_08036898
    .thumb_func
func_08036898:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080368C4
    .thumb_func
func_080368C4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036684
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036688
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_0803668C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036690
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036684:
    .4byte gUnk_080F43DC
.Ljp_08036688:
    .4byte 0x000007BE
.Ljp_0803668C:
    .4byte 0x000003F3
.Ljp_08036690:
    .4byte vtable_unk_080E6B58
    .global func_08036900
    .thumb_func
func_08036900:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Ljp_080366E4
    ldr r0, .Ljp_080366E8
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Ljp_080366EC
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #25
    bne .Ljp_08036734
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Ljp_08036734
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080366DE
    ldr r2, .Ljp_080366F0
    adds	r0, r5, r2
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    ldr r1, .Ljp_080366F4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Ljp_080366FC
.Ljp_080366DE:
    ldr r7, .Ljp_080366F8
    b .Ljp_08036734
    .align 2, 0
.Ljp_080366E4:
    .4byte 0x000007BE
.Ljp_080366E8:
    .4byte 0x000007C2
.Ljp_080366EC:
    .4byte 0x00001CD4
.Ljp_080366F0:
    .4byte 0x0000216B
.Ljp_080366F4:
    .4byte 0x0000216C
.Ljp_080366F8:
    .4byte 0x000007D2
.Ljp_080366FC:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_08036734
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08036734
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08036734
    ldr r7, .Ljp_08036750
    ldr r0, .Ljp_08036754
    mov	r8, r0
.Ljp_08036734:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08036750:
    .4byte 0x000007CA
.Ljp_08036754:
    .4byte 0x000007CE
    .global func_080369C4
    .thumb_func
func_080369C4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_0803676C
    adds	r0, r5, #0
    bl func_08036900
.Ljp_0803676C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080369E0
    .thumb_func
func_080369E0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036900
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A10
    .thumb_func
func_08036A10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_080367D0
    str	r0, [sp, #0]
    ldr r0, .Ljp_080367D4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_080367D8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_080367DC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080367D0:
    .4byte gUnk_080F6FF8
.Ljp_080367D4:
    .4byte 0x00000902
.Ljp_080367D8:
    .4byte 0x00000401
.Ljp_080367DC:
    .4byte vtable_unk_080E6B18
    .global func_08036A4C
    .thumb_func
func_08036A4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A78
    .thumb_func
func_08036A78:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036838
    str	r0, [sp, #0]
    ldr r0, .Ljp_0803683C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036840
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036844
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036838:
    .4byte gUnk_080F7B40
.Ljp_0803683C:
    .4byte 0x000009D3
.Ljp_08036840:
    .4byte 0x00000404
.Ljp_08036844:
    .4byte vtable_unk_080E6AD8
    .global func_08036AB4
    .thumb_func
func_08036AB4:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Ljp_08036864
    ldr r5, .Ljp_08036868
    ldrh	r0, [r4, #4]
    adds	r2, r0, #0
    cmp	r0, #17
    beq .Ljp_08036874
    cmp	r0, #17
    bgt .Ljp_0803686C
    cmp	r0, #7
    beq .Ljp_08036874
    b .Ljp_08036878
    .align 2, 0
.Ljp_08036864:
    .4byte 0x000009D3
.Ljp_08036868:
    .4byte 0x000009D7
.Ljp_0803686C:
    cmp	r2, #29
    beq .Ljp_08036874
    cmp	r2, #37	@ 0x25
    bne .Ljp_08036878
.Ljp_08036874:
    ldr r1, .Ljp_0803688C
    ldr r5, .Ljp_08036890
.Ljp_08036878:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035940
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Ljp_0803688C:
    .4byte 0x000009DF
.Ljp_08036890:
    .4byte 0x000009E3
    .global func_08036B00
    .thumb_func
func_08036B00:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_080368A8
    adds	r0, r5, #0
    bl func_08036AB4
.Ljp_080368A8:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036B1C
    .thumb_func
func_08036B1C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036AB4
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036B4C
    .thumb_func
func_08036B4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_0803690C
    str	r0, [sp, #0]
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #201	@ 0xc9
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036910
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_0803690C:
    .4byte ScheduleInfo_Unk_080F261C
.Ljp_08036910:
    .4byte vtable_unk_080E6A98
    .global func_08036B80
    .thumb_func
func_08036B80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036BB0
    .thumb_func
func_08036BB0:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    movs	r0, #10
    ldrsh	r5, [r4, r0]
    movs	r2, #14
    ldrsh	r6, [r4, r2]
    adds	r0, r4, #0
    bl func_08034EB4
    ldrh	r0, [r4, #4]
    cmp	r0, #2
    bne .Ljp_08036984
    cmp	r5, #244	@ 0xf4
    bne .Ljp_08036964
    cmp	r6, #171	@ 0xab
    beq .Ljp_08036984
.Ljp_08036964:
    movs	r1, #10
    ldrsh	r0, [r4, r1]
    movs	r2, #14
    ldrsh	r1, [r4, r2]
    cmp	r0, #244	@ 0xf4
    bne .Ljp_08036984
    cmp	r1, #171	@ 0xab
    bne .Ljp_08036984
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Ljp_08036984:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036BF8
    .thumb_func
func_08036BF8:
    push	{r4, r5, r6, r7, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    movs	r0, #10
    ldrsh	r6, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_080369D4
    ldrh	r0, [r5, #4]
    cmp	r0, #2
    bne .Ljp_080369D4
    cmp	r6, #244	@ 0xf4
    bne .Ljp_080369B4
    cmp	r7, #171	@ 0xab
    beq .Ljp_080369D4
.Ljp_080369B4:
    movs	r2, #10
    ldrsh	r0, [r5, r2]
    movs	r2, #14
    ldrsh	r1, [r5, r2]
    cmp	r0, #244	@ 0xf4
    bne .Ljp_080369D4
    cmp	r1, #171	@ 0xab
    bne .Ljp_080369D4
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Ljp_080369D4:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036C48
    .thumb_func
func_08036C48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036A08
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036A0C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #254	@ 0xfe
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036A10
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08036A08:
    .4byte gUnk_080F597C
.Ljp_08036A0C:
    .4byte 0x00000857
.Ljp_08036A10:
    .4byte vtable_unk_080E6A58
    .global func_08036C80
    .thumb_func
func_08036C80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036CAC
    .thumb_func
func_08036CAC:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Ljp_08036A68
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036A6C
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Ljp_08036A68:
    .4byte 0x00000679
.Ljp_08036A6C:
    .4byte vtable_unk_080E6A18
    .global func_08036CDC
    .thumb_func
func_08036CDC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036D0C
    .thumb_func
func_08036D0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Ljp_08036AC8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036ACC
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Ljp_08036AC8:
    .4byte 0x00000669
.Ljp_08036ACC:
    .4byte vtable_unk_080E69D8
    .global func_08036D3C
    .thumb_func
func_08036D3C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036D68
    .thumb_func
func_08036D68:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Ljp_08036B24
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036B28
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036B24:
    .4byte 0x000007FE
.Ljp_08036B28:
    .4byte vtable_unk_080E6998
    .global func_08036D98
    .thumb_func
func_08036D98:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036DC4
    .thumb_func
func_08036DC4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036B84
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036B88
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036B8C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036B90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036B84:
    .4byte gUnk_080F6B10
.Ljp_08036B88:
    .4byte 0x000008D8
.Ljp_08036B8C:
    .4byte 0x000003FE
.Ljp_08036B90:
    .4byte vtable_unk_080E6958
    .global func_08036E00
    .thumb_func
func_08036E00:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036E2C
    .thumb_func
func_08036E2C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Ljp_08036BF4
    str	r0, [sp, #0]
    ldr r0, .Ljp_08036BF8
    str	r0, [sp, #4]
    adds	r0, #8
    str	r0, [sp, #8]
    ldr r0, .Ljp_08036BFC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Ljp_08036C00
    str	r0, [r4, #20]
    adds	r1, r4, #0
    adds	r1, #72	@ 0x48
    movs	r0, #0
    strh	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036BF4:
    .4byte gUnk_080F221C
.Ljp_08036BF8:
    .4byte 0x00000267
.Ljp_08036BFC:
    .4byte 0x000003E3
.Ljp_08036C00:
    .4byte vtable_unk_080E6918
    .global func_08036E70
    .thumb_func
func_08036E70:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Ljp_08036C34
    adds	r0, r0, r1
    bl func_080A0384
    adds	r6, r0, #0
    cmp	r0, #0
    beq .Ljp_08036C74
    ldr r5, .Ljp_08036C38
    ldr r7, .Ljp_08036C3C
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08036C40
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08036C64
    movs	r5, #12
    b .Ljp_08036C64
.Ljp_08036C34:
    .4byte 0x00001CD4
.Ljp_08036C38:
    .4byte 0x00000267
.Ljp_08036C3C:
    .4byte 0x0000026F
.Ljp_08036C40:
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08036C54
    ldr r5, .Ljp_08036C50
    b .Ljp_08036C64
.Ljp_08036C50:
    .4byte 0x00000277
.Ljp_08036C54:
    adds	r0, r6, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08036C64
    ldr r5, .Ljp_08036C7C
    ldr r7, .Ljp_08036C80
.Ljp_08036C64:
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035940
.Ljp_08036C74:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08036C7C:
    .4byte 0x0000026B
.Ljp_08036C80:
    .4byte 0x00000273
    .global func_08036EF0
    .thumb_func
func_08036EF0:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Ljp_08036C98
    adds	r0, r5, #0
    bl func_08036E70
.Ljp_08036C98:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036F0C
    .thumb_func
func_08036F0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    ldr r1, .Ljp_08036CEC
    adds	r0, r0, r1
    bl func_080A0384
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08036CF0
    adds	r0, r5, #0
    bl func_08036E70
    adds	r0, r4, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    movs	r4, #1
    cmp	r0, #0
    beq .Ljp_08036CCC
    movs	r4, #4
.Ljp_08036CCC:
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r5, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    b .Ljp_08036CF2
    .align 2, 0
.Ljp_08036CEC:
    .4byte 0x00001CD4
.Ljp_08036CF0:
    movs	r0, #0
.Ljp_08036CF2:
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036F68
    .thumb_func
func_08036F68:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r6, r1, #0
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Ljp_08036D86
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Ljp_08036D3C
    adds	r0, r0, r1
    bl func_080A0384
    cmp	r0, #0
    beq .Ljp_08036D86
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Ljp_08036D86
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08036D86
    adds	r0, r4, #0
    adds	r0, #72	@ 0x48
    ldrh	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Ljp_08036D40
    subs	r0, r1, #1
    b .Ljp_08036D84
.Ljp_08036D3C:
    .4byte 0x00001CD4
.Ljp_08036D40:
    mov	r1, sp
    ldr r0, .Ljp_08036D5C
    ldmia	r0!, {r2, r3, r7}
    stmia	r1!, {r2, r3, r7}
    ldr	r0, [r0, #0]
    str	r0, [r1, #0]
    bl rand
    movs	r1, #100	@ 0x64
    bl __modsi3
    movs	r3, #0
    mov	r2, sp
    b .Ljp_08036D66
.Ljp_08036D5C:
    .4byte gUnk_080F1514
.Ljp_08036D60:
    subs	r0, r0, r1
    adds	r2, #4
    adds	r3, #1
.Ljp_08036D66:
    cmp	r3, #3
    bhi .Ljp_08036D78
    ldrb	r1, [r2, #0]
    cmp	r0, r1
    bcs .Ljp_08036D60
    ldrh	r1, [r2, #2]
    adds	r0, r4, #0
    bl func_08035908
.Ljp_08036D78:
    bl rand
    movs	r1, #120	@ 0x78
    bl __modsi3
    adds	r0, #120	@ 0x78
.Ljp_08036D84:
    strh	r0, [r5, #0]
.Ljp_08036D86:
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_08034EB4
    add	sp, #16
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x47706B40
    .global func_08037008
    .thumb_func
func_08037008:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r4, r0, #0
    adds	r5, r2, #0
    ldr	r6, [sp, #20]
    str	r3, [sp, #0]
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Ljp_08036DD8
    str	r0, [r4, #20]
    str	r5, [r4, #48]	@ 0x30
    adds	r1, r4, #0
    adds	r1, #52	@ 0x34
    movs	r0, #0
    strh	r0, [r4, #52]	@ 0x34
    strh	r0, [r1, #2]
    strh	r0, [r1, #4]
    strh	r0, [r1, #6]
    strh	r6, [r4, #60]	@ 0x3c
    strh	r0, [r4, #62]	@ 0x3e
    adds	r1, #12
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08036DD8:
    .4byte vtable_unk_080E7328
    .global func_08037048
    .thumb_func
func_08037048:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_08036E24
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldr r0, .Ljp_08036E28
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_08036E0E
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_08036E0E:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Ljp_08036E1C
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_08036E1C:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Ljp_08036E24:
    .4byte vtable_unk_080E7328
.Ljp_08036E28:
    .4byte __vt_7AEntity
    .global func_08037098
    .thumb_func
func_08037098:
    push	{r4, r5, lr}
    adds	r3, r0, #0
    movs	r4, #0
    movs	r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r0, #0
    cmp	r0, #1
    beq .Ljp_08036E56
    cmp	r0, #1
    bgt .Ljp_08036E48
    cmp	r0, #0
    beq .Ljp_08036E52
    b .Ljp_08036E60
.Ljp_08036E48:
    cmp	r2, #2
    beq .Ljp_08036E5A
    cmp	r2, #3
    beq .Ljp_08036E5E
    b .Ljp_08036E60
.Ljp_08036E52:
    adds	r5, r1, #0
    b .Ljp_08036E60
.Ljp_08036E56:
    negs	r5, r1
    b .Ljp_08036E60
.Ljp_08036E5A:
    negs	r4, r1
    b .Ljp_08036E60
.Ljp_08036E5E:
    adds	r4, r1, #0
.Ljp_08036E60:
    str	r4, [r3, #24]
    str	r5, [r3, #28]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x6900B510
    .4byte 0xD0162800
    .4byte 0x1C022400
    .4byte 0x21003230
    .4byte 0x280089D0
    .4byte 0x2010D004
    .4byte 0x42485E11
    .4byte 0x0FC14308
    .4byte 0xD0052900
    .4byte 0xF0271C10
    .4byte 0x0600FBA1
    .4byte 0xD0002800
    .4byte 0x1C202401
    .4byte 0x2001E000
    .4byte 0xBC02BC10
    .4byte 0x00004708
    .global func_08037118
    .thumb_func
func_08037118:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r7, r0, #0
    adds	r4, r1, #0
    ldr	r1, [r7, #8]
    ldr	r2, [r7, #12]
    ldr	r0, [r7, #24]
    adds	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r7, #28]
    adds	r0, r0, r2
    mov	r8, r0
    asrs	r1, r1, #16
    str	r1, [sp, #0]
    asrs	r6, r2, #16
    asrs	r0, r0, #16
    subs	r5, r0, r6
    mov	r1, r9
    asrs	r0, r1, #16
    ldr	r1, [sp, #0]
    subs	r1, r0, r1
    mov	sl, r1
    cmp	r5, #0
    ble .Ljp_08036F16
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Ljp_08036EF6
    adds	r0, r4, #0
    bl func_080AB294
    ldr	r0, [r4, #0]
    b .Ljp_08036EF8
.Ljp_08036EF6:
    adds	r0, r1, #0
.Ljp_08036EF8:
    cmp	r5, r0
    ble .Ljp_08036F16
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Ljp_08036F0E
    adds	r0, r4, #0
    bl func_080AB294
    ldr	r0, [r4, #0]
    b .Ljp_08036F10
.Ljp_08036F0E:
    adds	r0, r1, #0
.Ljp_08036F10:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Ljp_08036F16:
    cmp	r5, #0
    bge .Ljp_08036F4C
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Ljp_08036F2C
    adds	r0, r4, #0
    bl func_080AB308
    ldr	r0, [r4, #4]
    b .Ljp_08036F2E
.Ljp_08036F2C:
    adds	r0, r1, #0
.Ljp_08036F2E:
    cmp	r5, r0
    bge .Ljp_08036F4C
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Ljp_08036F44
    adds	r0, r4, #0
    bl func_080AB308
    ldr	r0, [r4, #4]
    b .Ljp_08036F46
.Ljp_08036F44:
    adds	r0, r1, #0
.Ljp_08036F46:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Ljp_08036F4C:
    mov	r0, sl
    cmp	r0, #0
    bge .Ljp_08036F86
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Ljp_08036F64
    adds	r0, r4, #0
    bl func_080AB380
    ldr	r0, [r4, #8]
    b .Ljp_08036F66
.Ljp_08036F64:
    adds	r0, r1, #0
.Ljp_08036F66:
    cmp	sl, r0
    bge .Ljp_08036F86
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Ljp_08036F7C
    adds	r0, r4, #0
    bl func_080AB380
    ldr	r0, [r4, #8]
    b .Ljp_08036F7E
.Ljp_08036F7C:
    adds	r0, r1, #0
.Ljp_08036F7E:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Ljp_08036F86:
    mov	r0, sl
    cmp	r0, #0
    ble .Ljp_08036FC0
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Ljp_08036F9E
    adds	r0, r4, #0
    bl func_080AB3FC
    ldr	r0, [r4, #12]
    b .Ljp_08036FA0
.Ljp_08036F9E:
    adds	r0, r1, #0
.Ljp_08036FA0:
    cmp	sl, r0
    ble .Ljp_08036FC0
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Ljp_08036FB6
    adds	r0, r4, #0
    bl func_080AB3FC
    ldr	r0, [r4, #12]
    b .Ljp_08036FB8
.Ljp_08036FB6:
    adds	r0, r1, #0
.Ljp_08036FB8:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Ljp_08036FC0:
    mov	r0, r9
    str	r0, [r7, #8]
    mov	r1, r8
    str	r1, [r7, #12]
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037244
    .thumb_func
func_08037244:
    ldr	r2, [r1, #4]
    ldr	r1, [r1, #0]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    bx	lr
    .hword 0x0000
    .4byte 0x466BB082
    .4byte 0x466A2100
    .4byte 0x80598011
    .4byte 0x80D98099
    .4byte 0x9A019900
    .4byte 0x63826341
    .4byte 0x4770B002
    .global func_0803726C
    .thumb_func
func_0803726C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #96	@ 0x60
    adds	r7, r0, #0
    ldr	r4, [r7, #0]
    ldrh	r0, [r7, #4]
    mov	r8, r0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #20]
    adds	r0, r4, #0
    bl _call_via_r1
    cmp	r0, r8
    beq .Ljp_08037022
    b .Ljp_08037196
.Ljp_08037022:
    ldr	r1, [r4, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r4, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #64	@ 0x40
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    str	r1, [sp, #88]	@ 0x58
    str	r2, [sp, #92]	@ 0x5c
    add	r4, sp, #12
    movs	r2, #32
    mov	r9, r2
    movs	r5, #0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r1, r9
    str	r1, [r4, #40]	@ 0x28
    str	r5, [r4, #44]	@ 0x2c
    str	r5, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r9, r4
    cmp	r3, #0
    beq .Ljp_080370A4
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Ljp_080370A4
    ldr	r1, [r3, #20]
    add	r4, sp, #72	@ 0x48
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080AB4C8
.Ljp_080370A4:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Ljp_080370D4
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Ljp_080370D4
    ldr	r1, [r3, #20]
    add	r4, sp, #80	@ 0x50
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080AB4C8
.Ljp_080370D4:
    adds	r2, r7, #0
    adds	r2, #52	@ 0x34
    movs	r3, #4
    ldrsh	r0, [r2, r3]
    movs	r6, #52	@ 0x34
    ldrsh	r1, [r7, r6]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Ljp_080370FE
    movs	r1, #6
    ldrsh	r0, [r2, r1]
    movs	r3, #2
    ldrsh	r1, [r2, r3]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Ljp_080370FE
    mov	r0, r9
    adds	r1, r2, #0
    movs	r2, #0
    bl func_080AB4C8
.Ljp_080370FE:
    ldrh	r4, [r7, #62]	@ 0x3e
    cmp	r4, #0
    beq .Ljp_08037180
    ldr	r5, [r7, #24]
    ldr	r6, [r7, #28]
    cmp	r5, #0
    bge .Ljp_08037124
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Ljp_0803711E
    add	r0, sp, #12
    bl func_080AB380
    ldr	r0, [sp, #20]
    b .Ljp_08037120
.Ljp_0803711E:
    adds	r0, r1, #0
.Ljp_08037120:
    cmp	r0, #0
    bge .Ljp_08037178
.Ljp_08037124:
    cmp	r5, #0
    ble .Ljp_08037140
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Ljp_0803713A
    add	r0, sp, #12
    bl func_080AB3FC
    ldr	r0, [sp, #24]
    b .Ljp_0803713C
.Ljp_0803713A:
    adds	r0, r1, #0
.Ljp_0803713C:
    cmp	r0, #0
    ble .Ljp_08037178
.Ljp_08037140:
    cmp	r6, #0
    bge .Ljp_0803715C
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Ljp_08037156
    add	r0, sp, #12
    bl func_080AB308
    ldr	r0, [sp, #16]
    b .Ljp_08037158
.Ljp_08037156:
    adds	r0, r1, #0
.Ljp_08037158:
    cmp	r0, #0
    bge .Ljp_08037178
.Ljp_0803715C:
    cmp	r6, #0
    ble .Ljp_0803717C
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Ljp_08037172
    add	r0, sp, #12
    bl func_080AB294
    ldr	r0, [sp, #12]
    b .Ljp_08037174
.Ljp_08037172:
    adds	r0, r1, #0
.Ljp_08037174:
    cmp	r0, #0
    bgt .Ljp_0803717C
.Ljp_08037178:
    movs	r4, #0
    b .Ljp_0803718C
.Ljp_0803717C:
    subs	r4, #1
    b .Ljp_0803718C
.Ljp_08037180:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #64]	@ 0x40
    adds	r0, r7, #0
    bl _call_via_r1
    adds	r4, r0, #0
.Ljp_0803718C:
    strh	r4, [r7, #62]	@ 0x3e
    adds	r0, r7, #0
    mov	r1, r9
    bl func_08037118
.Ljp_08037196:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_080371A0
    subs	r0, #1
    b .Ljp_080371A2
.Ljp_080371A0:
    ldrh	r0, [r7, #38]	@ 0x26
.Ljp_080371A2:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Ljp_080371B4
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Ljp_080371B4:
    add	sp, #96	@ 0x60
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037430
    .thumb_func
func_08037430:
    ldrh	r0, [r0, #60]	@ 0x3c
    bx	lr
    .global func_08037434
    .thumb_func
func_08037434:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #64	@ 0x40
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Ljp_080371DE
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    bl _call_via_r1
.Ljp_080371DE:
    movs	r0, #0
    strh	r0, [r4, #62]	@ 0x3e
    adds	r0, r4, #0
    bl vfunc_10__7AEntity
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803745C
    .thumb_func
func_0803745C:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    adds	r4, #64	@ 0x40
    movs	r0, #0
    strb	r0, [r4, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037470
    .thumb_func
func_08037470:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #9
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0
    .global func_08037494
    .thumb_func
func_08037494:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Ljp_0803724C
    movs	r1, #1
.Ljp_0803724C:
    lsls	r4, r1, #2
    adds	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Ljp_080372CC
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #5
    bl func_080AB264
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB1C0
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB1C0
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Ljp_0803729C
    cmp	r1, #3
    beq .Ljp_0803729C
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB1DC
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_0803729C
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_0803729C:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037628
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_080372C2
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Ljp_080372C2:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080372CC:
    .4byte gUnk_080F1538
    .global func_0803753C
    .thumb_func
func_0803753C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #7
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #9
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037568
    .thumb_func
func_08037568:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Ljp_08037394
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Ljp_08037356
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Ljp_08037356:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #0
    beq .Ljp_08037394
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Ljp_08037394
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A17A0
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_0803739E
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Ljp_0803739E
.Ljp_08037394:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Ljp_0803739E:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037618
    .thumb_func
func_08037618:
    ldr r0, .Ljp_080373B8
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Ljp_080373B8:
    .4byte gUnk_080F1560
    .global func_08037628
    .thumb_func
func_08037628:
    push	{lr}
    cmp	r1, #1
    beq .Ljp_080373C6
    movs	r0, #0
    b .Ljp_080373CA
.Ljp_080373C6:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Ljp_080373CA:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803763C
    .thumb_func
func_0803763C:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Ljp_080373F4
    movs	r1, #1
.Ljp_080373F4:
    lsls	r4, r1, #3
    subs	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Ljp_08037474
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #7
    bl func_080AB264
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB1C0
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB1C0
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Ljp_08037444
    cmp	r1, #3
    beq .Ljp_08037444
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB1DC
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_08037444
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_08037444:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377D4
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_0803746A
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Ljp_0803746A:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08037474:
    .4byte gUnk_080F156C
    .global func_080376E4
    .thumb_func
func_080376E4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #2
    str	r1, [sp, #0]
    movs	r1, #12
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #12
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037714
    .thumb_func
func_08037714:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Ljp_08037540
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Ljp_08037502
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Ljp_08037502:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #1
    beq .Ljp_08037540
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Ljp_08037540
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A1890
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_0803754A
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Ljp_0803754A
.Ljp_08037540:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Ljp_0803754A:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080377C4
    .thumb_func
func_080377C4:
    ldr r0, .Ljp_08037564
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Ljp_08037564:
    .4byte gUnk_080F15A4
    .global func_080377D4
    .thumb_func
func_080377D4:
    push	{lr}
    cmp	r1, #1
    beq .Ljp_08037572
    movs	r0, #0
    b .Ljp_08037576
.Ljp_08037572:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Ljp_08037576:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080377E8
    .thumb_func
func_080377E8:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r4, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Ljp_080375A0
    movs	r4, #1
.Ljp_080375A0:
    movs	r0, #52	@ 0x34
    muls	r4, r0
    ldr r0, .Ljp_0803761C
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #13
    bl func_080AB264
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB1C0
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB1C0
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Ljp_080375EE
    cmp	r1, #3
    beq .Ljp_080375EE
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB1DC
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_080375EE
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_080375EE:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378FC
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08037614
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08037614:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_0803761C:
    .4byte gUnk_080F15B4
    .global func_0803788C
    .thumb_func
func_0803788C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080378B8
    .thumb_func
func_080378B8:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A198C
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08037676
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08037676:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080378EC
    .thumb_func
func_080378EC:
    ldr r0, .Ljp_0803768C
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Ljp_0803768C:
    .4byte gUnk_080F161C
    .global func_080378FC
    .thumb_func
func_080378FC:
    push	{lr}
    cmp	r1, #12
    bhi .Ljp_080376D8
    lsls	r0, r1, #2
    ldr r1, .Ljp_080376A0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_080376A0:
    .4byte .Ljp_080376A4
.Ljp_080376A4:
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376DC
    .4byte .Ljp_080376E2
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376D8
    .4byte .Ljp_080376E2
    .4byte .Ljp_080376D8
.Ljp_080376D8:
    movs	r0, #0
    b .Ljp_080376E6
.Ljp_080376DC:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE001
.Ljp_080376E2:
    .hword 0x2080
    .hword 0x0240
.Ljp_080376E6:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037958
    .thumb_func
func_08037958:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr r5, .Ljp_08037768
    adds	r0, r5, #0
    movs	r1, #3
    bl func_080AB264
    lsls	r4, r0, #2
    adds	r4, r4, r5
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB1C0
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB1C0
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Ljp_08037738
    cmp	r1, #3
    beq .Ljp_08037738
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB1DC
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_08037738
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_08037738:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A48
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_0803775E
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Ljp_0803775E:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08037768:
    .4byte gUnk_080F1638
    .global func_080379D8
    .thumb_func
func_080379D8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037A04
    .thumb_func
func_08037A04:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A19EC
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_080377C2
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Ljp_080377C2:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037A38
    .thumb_func
func_08037A38:
    ldr r0, .Ljp_080377D8
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Ljp_080377D8:
    .4byte gUnk_080F1644
    .global func_08037A48
    .thumb_func
func_08037A48:
    push	{lr}
    cmp	r1, #1
    beq .Ljp_080377E6
    movs	r0, #0
    b .Ljp_080377EA
.Ljp_080377E6:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Ljp_080377EA:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037A5C
    .thumb_func
func_08037A5C:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    ldr r3, .Ljp_0803785C
    bl func_08037008
    ldr r0, .Ljp_08037860
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0803785C:
    .4byte 0x0000071C
.Ljp_08037860:
    .4byte vtable_unk_080E72E4
    .global func_08037AD0
    .thumb_func
func_08037AD0:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    bl func_08037008
    ldr r0, .Ljp_080378D8
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080378D8:
    .4byte vtable_unk_080E72A0
    .global func_08037B48
    .thumb_func
func_08037B48:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Ljp_0803790C
    bl func_08037008
    ldr r0, .Ljp_08037910
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0803790C:
    .4byte 0x00000379
.Ljp_08037910:
    .4byte vtable_unk_080E725C
    .global func_08037B80
    .thumb_func
func_08037B80:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Ljp_08037944
    bl func_08037008
    ldr r0, .Ljp_08037948
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08037944:
    .4byte 0x00000207
.Ljp_08037948:
    .4byte vtable_unk_080E7218
    .4byte 0xB081B510
    .4byte 0x4B061C04
    .4byte 0x9000200A
    .4byte 0xF7FF1C20
    .4byte 0x4804FA1F
    .4byte 0x1C206160
    .4byte 0xBC10B001
    .4byte 0x4708BC02
    .4byte 0x00000207
    .4byte vtable_unk_080E7218
    .4byte 0xB081B510
    .4byte 0x4B061C04
    .4byte 0x9000200C
    .4byte 0xF7FF1C20
    .4byte 0x4804FA0B
    .4byte 0x1C206160
    .4byte 0xBC10B001
    .4byte 0x4708BC02
    .4byte 0x00000379
    .4byte vtable_unk_080E725C
    .4byte 0xB083B530
    .4byte 0x1C1C1C05
    .4byte 0x009B23AB
    .4byte 0x9000200B
    .4byte 0xF7FF1C28
    .4byte 0x4811F9F5
    .4byte 0x1C2A6168
    .4byte 0x20033244
    .4byte 0x78114004
    .4byte 0x42402004
    .4byte 0x43204008
    .4byte 0xAB017010
    .4byte 0x008921E6
    .4byte 0x00522290
    .4byte 0x80011C18
    .4byte 0x20A4805A
    .4byte 0x18090040
    .4byte 0x32088099
    .4byte 0x1C2880DA
    .4byte 0xF7FF1C19
    .4byte 0x1C28FAF5
    .4byte 0xBC30B003
    .4byte 0x4708BC02
    .4byte vtable_unk_080E72A0
    .4byte 0xB083B530
    .4byte 0x1C1C1C05
    .4byte 0x20004B12
    .4byte 0x1C289000
    .4byte 0xF9C6F7FF
    .4byte 0x61684810
    .4byte 0x32441C2A
    .4byte 0x40042003
    .4byte 0x20047811
    .4byte 0x40084240
    .4byte 0x70104320
    .4byte 0x21B0AA01
    .4byte 0x23D80049
    .4byte 0x80011C10
    .4byte 0x31388053
    .4byte 0x20E88091
    .4byte 0x1C2880D0
    .4byte 0xF7FF1C11
    .4byte 0x1C28FAC9
    .4byte 0xBC30B003
    .4byte 0x4708BC02
    .4byte 0x0000071C
    .4byte vtable_unk_080E72E4
    .global func_08037CC4
    .thumb_func
func_08037CC4:
    push	{r4, lr}
    adds	r4, r0, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Ljp_08037A6C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_08037A6C:
    .4byte vtable_unk_080E7444
    .global func_08037CDC
    .thumb_func
func_08037CDC:
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r3, #14
    ldrsh	r1, [r1, r3]
    strh	r2, [r0, #0]
    adds	r1, #1
    strh	r1, [r0, #2]
    strh	r2, [r0, #4]
    strh	r1, [r0, #6]
    bx	lr
    .global func_08037CF0
    .thumb_func
func_08037CF0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037D08
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037D08
    .thumb_func
func_08037D08:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Ljp_08037AFC
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #10
    bl func_080A4740
    ldr r0, .Ljp_08037B00
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #125	@ 0x7d
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_08037AFC:
    .4byte vtable_unk_080E7478
.Ljp_08037B00:
    .4byte vtable_unk_080E602C
    .global func_08037D70
    .thumb_func
func_08037D70:
    bx	lr
    .align 2, 0
    .global func_08037D74
    .thumb_func
func_08037D74:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r2, [r3, r0]
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    subs	r0, r2, r0
    mov	ip, r0
    ldr	r0, [r1, #0]
    ldr	r3, [r1, #8]
    str	r0, [sp, #20]
    str	r3, [sp, #24]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r2
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r2, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08037B74
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r8
    mov	r2, ip
    movs	r3, #170	@ 0xaa
    ldr r4, .Ljp_08037B70
    bl _call_via_r4
    b .Ljp_08037B76
    .align 2, 0
.Ljp_08037B70:
    .4byte func_030004DC
.Ljp_08037B74:
    movs	r0, #0
.Ljp_08037B76:
    cmp	r0, #0
    beq .Ljp_08037BA0
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_08037BA0
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08037BA0:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037E18
    .thumb_func
func_08037E18:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    mov	r0, sp
    adds	r1, r6, #0
    bl func_0800FFE0
    adds	r0, r4, #0
    adds	r1, r5, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Ljp_08037BD8
    str	r0, [r4, #20]
    str	r6, [r4, #24]
    adds	r0, r4, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Ljp_08037BD8:
    .4byte vtable_unk_080E73FC
    .global func_08037E48
    .thumb_func
func_08037E48:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_08037C28
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl func_08010014
    ldr r0, .Ljp_08037C2C
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_08037C10
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_08037C10:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Ljp_08037C1E
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_08037C1E:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08037C28:
    .4byte vtable_unk_080E73FC
.Ljp_08037C2C:
    .4byte __vt_7AEntity
    .global func_08037E9C
    .thumb_func
func_08037E9C:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #88	@ 0x58
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037EF0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037EB4
    .thumb_func
func_08037EB4:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #24]
    ldrb	r1, [r1, #0]
    bl func_0800FFF4
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Ljp_08037C5E
    bl func_08037F74
.Ljp_08037C5E:
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037ED0
    .thumb_func
func_08037ED0:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_08037EF0
    .thumb_func
func_08037EF0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Ljp_08037CEC
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #8
    bl func_080A4740
    ldr r0, .Ljp_08037CF0
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #53	@ 0x35
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    adds	r0, #84	@ 0x54
    strb	r2, [r0, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_08037CEC:
    .4byte vtable_unk_080E7430
.Ljp_08037CF0:
    .4byte vtable_unk_080E602C
    .global func_08037F60
    .thumb_func
func_08037F60:
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #84	@ 0x54
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Ljp_08037D04
    subs	r0, #1
    strb	r0, [r1, #0]
.Ljp_08037D04:
    pop	{r0}
    bx	r0
    .global func_08037F74
    .thumb_func
func_08037F74:
    adds	r0, #84	@ 0x54
    movs	r1, #10
    strb	r1, [r0, #0]
    bx	lr
    .global func_08037F7C
    .thumb_func
func_08037F7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r3, [r3, r0]
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    subs	r2, r3, r0
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    mov	ip, r1
    str	r0, [sp, #20]
    str	r1, [sp, #24]
    adds	r0, r4, #0
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08037D48
    subs	r2, #2
.Ljp_08037D48:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r3
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r3, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08037D84
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    mov	r1, r8
    movs	r3, #170	@ 0xaa
    ldr r4, .Ljp_08037D80
    bl _call_via_r4
    b .Ljp_08037D86
.Ljp_08037D80:
    .4byte func_030004DC
.Ljp_08037D84:
    movs	r0, #0
.Ljp_08037D86:
    cmp	r0, #0
    beq .Ljp_08037DB0
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_08037DB0
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08037DB0:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038028
    .thumb_func
func_08038028:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r6, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Ljp_08037E28
    str	r0, [r6, #20]
    str	r4, [r6, #24]
    movs	r0, #0
    str	r0, [r6, #28]
    adds	r1, r6, #0
    adds	r1, #37	@ 0x25
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    movs	r0, #49	@ 0x31
    strh	r0, [r6, #40]	@ 0x28
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08037E1C
    ldrh	r0, [r4, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Ljp_08037E1C
    adds	r0, r4, #0
    bl func_080201F4
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08037E1C
    ldr	r1, [r4, #8]
    ldr	r2, [r4, #12]
    ldrh	r3, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r6, #0
    bl func_08038374
.Ljp_08037E1C:
    adds	r0, r6, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08037E28:
    .4byte vtable_unk_080E73B4
    .global func_08038098
    .thumb_func
func_08038098:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_08037E78
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    ldr r0, .Ljp_08037E7C
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_08037E62
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_08037E62:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Ljp_08037E70
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_08037E70:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Ljp_08037E78:
    .4byte vtable_unk_080E73B4
.Ljp_08037E7C:
    .4byte __vt_7AEntity
    .global func_080380EC
    .thumb_func
func_080380EC:
    adds	r2, r0, #0
    adds	r2, #36	@ 0x24
    strb	r1, [r2, #0]
    movs	r1, #168	@ 0xa8
    lsls	r1, r1, #13
    str	r1, [r0, #28]
    movs	r1, #192	@ 0xc0
    lsls	r1, r1, #10
    str	r1, [r0, #32]
    adds	r0, #37	@ 0x25
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038108
    .thumb_func
func_08038108:
    adds	r0, #37	@ 0x25
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038110
    .thumb_func
func_08038110:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #68	@ 0x44
    adds	r6, r0, #0
    adds	r4, r6, #0
    adds	r4, #37	@ 0x25
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_08037EBA
    b .Ljp_08038088
.Ljp_08037EBA:
    ldr	r7, [r6, #0]
    ldrh	r2, [r6, #4]
    ldr	r1, [r7, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r7, #0
    bl _call_via_r3
    mov	r8, sp
    ldr	r1, [r6, #32]
    ldr r0, .Ljp_08037F34
    adds	r1, r1, r0
    str	r1, [r6, #32]
    ldr	r0, [r6, #28]
    adds	r0, r0, r1
    str	r0, [r6, #28]
    cmp	r0, #0
    bgt .Ljp_08037EE0
    b .Ljp_08037FF0
.Ljp_08037EE0:
    ldr	r1, [r6, #20]
    add	r0, sp, #52	@ 0x34
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r1, [sp, #52]	@ 0x34
    ldr	r2, [sp, #56]	@ 0x38
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    add	r5, sp, #12
    movs	r2, #32
    mov	r8, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r5, #4]
    str	r0, [r5, #8]
    str	r1, [r5, #12]
    add	r1, sp, #28
    mov	r0, sp
    ldmia	r0!, {r2, r3, r4}
    stmia	r1!, {r2, r3, r4}
    ldr	r3, [sp, #60]	@ 0x3c
    ldr	r4, [sp, #64]	@ 0x40
    str	r3, [sp, #40]	@ 0x28
    str	r4, [sp, #44]	@ 0x2c
    mov	r4, r8
    str	r4, [r5, #36]	@ 0x24
    ldr	r4, [r6, #8]
    ldr	r7, [r6, #12]
    adds	r0, r6, #0
    adds	r0, #36	@ 0x24
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Ljp_08037F42
    cmp	r0, #1
    bgt .Ljp_08037F38
    cmp	r0, #0
    beq .Ljp_08037F68
    b .Ljp_08037FE4
.Ljp_08037F34:
    .4byte 0xFFFFB85D
.Ljp_08037F38:
    cmp	r0, #2
    beq .Ljp_08037FC4
    cmp	r0, #3
    beq .Ljp_08037F98
    b .Ljp_08037FE4
.Ljp_08037F42:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Ljp_08037F54
    adds	r0, r5, #0
    bl func_080AB5FC
    ldr	r0, [sp, #16]
    b .Ljp_08037F56
.Ljp_08037F54:
    adds	r0, r1, #0
.Ljp_08037F56:
    lsls	r1, r0, #16
    ldr r0, .Ljp_08037F64
    cmp	r1, r0
    bgt .Ljp_08037F84
    ldr r5, .Ljp_08037F64
    adds	r7, r7, r5
    b .Ljp_08037FE4
.Ljp_08037F64:
    .4byte 0xFFFE38E4
.Ljp_08037F68:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Ljp_08037F7A
    adds	r0, r5, #0
    bl func_080AB5D8
    ldr	r0, [sp, #12]
    b .Ljp_08037F7C
.Ljp_08037F7A:
    adds	r0, r1, #0
.Ljp_08037F7C:
    lsls	r1, r0, #16
    ldr r0, .Ljp_08037F88
    cmp	r1, r0
    bgt .Ljp_08037F8C
.Ljp_08037F84:
    adds	r7, r7, r1
    b .Ljp_08037FE4
.Ljp_08037F88:
    .4byte 0x0001C71B
.Ljp_08037F8C:
    ldr r0, .Ljp_08037F94
    adds	r7, r7, r0
    b .Ljp_08037FE4
    .align 2, 0
.Ljp_08037F94:
    .4byte 0x0001C71C
.Ljp_08037F98:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Ljp_08037FAA
    adds	r0, r5, #0
    bl func_080AB64C
    ldr	r0, [sp, #24]
    b .Ljp_08037FAC
.Ljp_08037FAA:
    adds	r0, r1, #0
.Ljp_08037FAC:
    lsls	r1, r0, #16
    ldr r0, .Ljp_08037FBC
    cmp	r1, r0
    ble .Ljp_08037FB6
    ldr r1, .Ljp_08037FC0
.Ljp_08037FB6:
    adds	r4, r4, r1
    b .Ljp_08037FE4
    .align 2, 0
.Ljp_08037FBC:
    .4byte 0x0001C71B
.Ljp_08037FC0:
    .4byte 0x0001C71C
.Ljp_08037FC4:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Ljp_08037FD6
    adds	r0, r5, #0
    bl func_080AB624
    ldr	r0, [sp, #20]
    b .Ljp_08037FD8
.Ljp_08037FD6:
    adds	r0, r1, #0
.Ljp_08037FD8:
    lsls	r1, r0, #16
    ldr r0, .Ljp_08037FEC
    cmp	r1, r0
    bgt .Ljp_08037FB6
    ldr r2, .Ljp_08037FEC
    adds	r4, r4, r2
.Ljp_08037FE4:
    str	r4, [r6, #8]
    str	r7, [r6, #12]
    b .Ljp_08038088
    .align 2, 0
.Ljp_08037FEC:
    .4byte 0xFFFE38E4
.Ljp_08037FF0:
    movs	r0, #0
    str	r0, [r6, #28]
    strb	r0, [r4, #0]
    add	r4, sp, #12
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #24]
    adds	r1, r4, #0
    movs	r2, #6
    bl memcpy
    ldr	r0, [r6, #8]
    ldr	r1, [r6, #12]
    asrs	r0, r0, #19
    mov	ip, r0
    asrs	r3, r1, #19
    ldr	r1, [sp, #0]
    mov	r5, r8
    ldrh	r0, [r5, #8]
    cmp	r1, #0
    beq .Ljp_0803803C
    cmp	ip, r0
    bhi .Ljp_0803803C
    ldrh	r2, [r5, #10]
    cmp	r3, r2
    bhi .Ljp_0803803C
    ldr	r2, [sp, #4]
    muls	r0, r3
    add	r0, ip
    cmp	r2, #0
    beq .Ljp_08038036
    adds	r0, r2, r0
    ldrb	r0, [r0, #0]
.Ljp_08038036:
    lsls	r0, r0, #2
    adds	r0, r1, r0
    b .Ljp_0803803E
.Ljp_0803803C:
    movs	r0, #0
.Ljp_0803803E:
    cmp	r0, #0
    bne .Ljp_08038056
    ldr	r0, [r7, #0]
    movs	r3, #158	@ 0x9e
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #1
    bl _call_via_r2
    b .Ljp_08038088
.Ljp_08038056:
    ldr	r0, [r0, #0]
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_08038072
    ldr	r0, [r7, #0]
    movs	r4, #158	@ 0x9e
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
    bl _call_via_r2
    b .Ljp_08038088
.Ljp_08038072:
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    cmp	r0, #0
    beq .Ljp_08038088
    adds	r1, r4, #0
    bl func_080212B0
.Ljp_08038088:
    add	sp, #68	@ 0x44
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038300
    .thumb_func
func_08038300:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r2, [r4, #16]
    cmp	r2, #0
    beq .Ljp_080380A8
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Ljp_080380A8:
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038320
    .thumb_func
func_08038320:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_2C__7AEntityUi
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038334
    .thumb_func
func_08038334:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r1, r4, #0
    bl func_0803853C
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803834C
    .thumb_func
func_0803834C:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #4
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #4
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_0803836C
    .thumb_func
func_0803836C:
    movs	r1, #30
    ldrsh	r0, [r0, r1]
    bx	lr
    .align 2, 0
    .global func_08038374
    .thumb_func
func_08038374:
    push	{r4, r5, r6, lr}
    ldr	r5, [sp, #16]
    movs	r4, #38	@ 0x26
    adds	r4, r4, r0
    mov	ip, r4
    movs	r4, #1
    mov	r6, ip
    strb	r4, [r6, #0]
    str	r1, [r0, #8]
    str	r2, [r0, #12]
    adds	r1, r3, #0
    adds	r2, r5, #0
    bl func_08038398
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038398
    .thumb_func
func_08038398:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    movs	r3, #21
    ldr r4, .Ljp_08038148
    adds	r0, r1, r4
    cmp	r0, #61	@ 0x3d
    bls .Ljp_0803813C
    b .Ljp_0803825E
.Ljp_0803813C:
    lsls	r0, r0, #2
    ldr r1, .Ljp_0803814C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08038148:
    .4byte 0xFFFFFCC8
.Ljp_0803814C:
    .4byte .Ljp_08038150
.Ljp_08038150:
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_08038248
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803824C
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_08038250
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_08038254
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_08038258
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825E
    .4byte .Ljp_0803825C
.Ljp_08038248:
    .4byte 0xE0082319
.Ljp_0803824C:
    .4byte 0xE006231D
.Ljp_08038250:
    .4byte 0xE0042321
.Ljp_08038254:
    .4byte 0xE0022325
.Ljp_08038258:
    .4byte 0xE0002329
.Ljp_0803825C:
    .hword 0x232D
.Ljp_0803825E:
    adds	r1, r3, r2
    adds	r6, r1, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r1, r0
    beq .Ljp_0803828A
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Ljp_08038288
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Ljp_08038288:
    strh	r6, [r5, #40]	@ 0x28
.Ljp_0803828A:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_080384FC
    .thumb_func
func_080384FC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r0, #49	@ 0x31
    beq .Ljp_080382C0
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Ljp_080382BC
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    movs	r1, #49	@ 0x31
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Ljp_080382BC:
    movs	r0, #49	@ 0x31
    strh	r0, [r5, #40]	@ 0x28
.Ljp_080382C0:
    adds	r1, r5, #0
    adds	r1, #38	@ 0x26
    movs	r0, #0
    strb	r0, [r1, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803853C
    .thumb_func
func_0803853C:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r6, r0, #0
    adds	r4, r1, #0
    str	r4, [r6, #0]
    ldr r0, .Ljp_08038310
    str	r0, [r6, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r6, #0
    adds	r0, #8
    ldrh	r2, [r4, #40]	@ 0x28
    movs	r4, #2
    str	r4, [sp, #0]
    movs	r4, #7
    str	r4, [sp, #4]
    add	r5, sp, #8
    movs	r4, #0
    strb	r4, [r5, #0]
    bl func_080A4A00
    adds	r0, r6, #0
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08038310:
    .4byte vtable_unk_080E73E8
    .global func_08038580
    .thumb_func
func_08038580:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_08038338
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_0803833C
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Ljp_0803833A
.Ljp_08038338:
    movs	r0, #0
.Ljp_0803833A:
    strb	r0, [r1, #0]
.Ljp_0803833C:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080385B0
    .thumb_func
func_080385B0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r5, r0, #0
    mov	sl, r1
    ldr	r0, [r5, #0]
    mov	r9, r0
    movs	r1, #10
    ldrsh	r6, [r0, r1]
    mov	r2, sl
    movs	r3, #12
    ldrsh	r0, [r2, r3]
    subs	r0, r6, r0
    str	r0, [sp, #60]	@ 0x3c
    mov	r0, r9
    movs	r1, #14
    ldrsh	r4, [r0, r1]
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    subs	r0, r4, r0
    str	r0, [sp, #64]	@ 0x40
    mov	r0, r9
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r4
    mov	r8, r0
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    beq .Ljp_08038390
    movs	r1, #1
    negs	r1, r1
    add	r8, r1
.Ljp_08038390:
    add	r0, sp, #52	@ 0x34
    mov	r2, sl
    ldr	r1, [r2, #0]
    ldr	r2, [r2, #8]
    str	r1, [sp, #52]	@ 0x34
    str	r2, [r0, #4]
    ldr	r3, [sp, #64]	@ 0x40
    str	r3, [sp, #72]	@ 0x48
    movs	r7, #2
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    bne .Ljp_080383DA
    mov	r0, r9
    bl func_0803836C
    ldr	r1, [sp, #64]	@ 0x40
    subs	r1, r1, r0
    str	r1, [sp, #72]	@ 0x48
    cmp	r0, #15
    ble .Ljp_080383DA
    mov	r2, r9
    ldrh	r0, [r2, #4]
    cmp	r0, #8
    bgt .Ljp_080383D8
    cmp	r0, #2
    bne .Ljp_080383DA
    ldr r3, .Ljp_08038440
    adds	r1, r6, r3
    ldr r0, .Ljp_08038444
    cmp	r1, r0
    bhi .Ljp_080383DA
    cmp	r4, #175	@ 0xaf
    ble .Ljp_080383DA
    subs	r0, #96	@ 0x60
    cmp	r4, r0
    bgt .Ljp_080383DA
.Ljp_080383D8:
    movs	r7, #1
.Ljp_080383DA:
    adds	r6, r5, #0
    adds	r6, #8
    mov	r0, sp
    adds	r0, #52	@ 0x34
    str	r0, [sp, #76]	@ 0x4c
    adds	r0, r7, #0
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    ldr	r1, [r5, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r5, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r1, [sp, #76]	@ 0x4c
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #8]
    ldr	r1, [r5, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_0803844C
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #24
    mov	r5, r8
    str	r5, [sp, #0]
    adds	r5, r7, #0
    str	r5, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #72]	@ 0x48
    adds	r3, r4, #0
    ldr r4, .Ljp_08038448
    bl _call_via_r4
    b .Ljp_0803844E
    .align 2, 0
.Ljp_08038440:
    .4byte 0xFFFFFEF0
.Ljp_08038444:
    .4byte 0x000002AF
.Ljp_08038448:
    .4byte func_030004DC
.Ljp_0803844C:
    movs	r0, #0
.Ljp_0803844E:
    cmp	r0, #0
    beq .Ljp_080384A2
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Ljp_080384A2
    ldr	r0, [sp, #76]	@ 0x4c
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08038484
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_0803849E
.Ljp_08038484:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_0803849E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_0803849E:
    movs	r0, #0
    strb	r0, [r5, #0]
.Ljp_080384A2:
    ldr	r1, [sp, #68]	@ 0x44
    cmp	r1, #0
    bne .Ljp_080384C4
    mov	r2, r9
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #88]	@ 0x58
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    ldr	r5, [sp, #68]	@ 0x44
    str	r5, [sp, #0]
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r3, [sp, #64]	@ 0x40
    bl func_0803AE58
.Ljp_080384C4:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038740
    .thumb_func
func_08038740:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r2
    mov	r2, sp
    movs	r5, #8
    ldrh	r3, [r2, #0]
    ldr r4, .Ljp_0803852C
    adds	r0, r4, #0
    ands	r0, r3
    orrs	r0, r5
    strh	r0, [r2, #0]
    ldrb	r5, [r2, #1]
    movs	r3, #3
    adds	r0, r3, #0
    ands	r0, r5
    strb	r0, [r2, #1]
    ldrh	r5, [r2, #2]
    adds	r0, r4, #0
    ands	r0, r5
    strh	r0, [r2, #2]
    ldrb	r0, [r2, #3]
    ands	r3, r0
    strb	r3, [r2, #3]
    ldrh	r0, [r2, #4]
    ands	r4, r0
    strh	r4, [r2, #4]
    adds	r0, r6, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Ljp_08038530
    str	r0, [r6, #20]
    mov	r0, r8
    str	r0, [r6, #24]
    adds	r0, r6, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0803852C:
    .4byte 0xFFFFFC00
.Ljp_08038530:
    .4byte vtable_unk_080E7380
    .global func_080387A0
    .thumb_func
func_080387A0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #24
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08038820
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080387B8
    .thumb_func
func_080387B8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Ljp_08038558
    bl func_08038DF0
.Ljp_08038558:
    pop	{r0}
    bx	r0
    .global func_080387C8
    .thumb_func
func_080387C8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Ljp_08038568
    bl func_08038E90
.Ljp_08038568:
    pop	{r0}
    bx	r0
    .global func_080387D8
    .thumb_func
func_080387D8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Ljp_08038578
    movs	r0, #1
    b .Ljp_0803857C
.Ljp_08038578:
    bl func_08038EA0
.Ljp_0803857C:
    pop	{r1}
    bx	r1
    .global func_080387EC
    .thumb_func
func_080387EC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Ljp_0803858C
    bl func_08038EB8
.Ljp_0803858C:
    pop	{r0}
    bx	r0
    .global func_080387FC
    .thumb_func
func_080387FC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Ljp_0803859C
    bl func_08038EE0
.Ljp_0803859C:
    pop	{r0}
    bx	r0
    .global func_0803880C
    .thumb_func
func_0803880C:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Ljp_080385AC
    movs	r0, #0
    b .Ljp_080385B0
.Ljp_080385AC:
    bl func_080390D0
.Ljp_080385B0:
    pop	{r1}
    bx	r1
    .global func_08038820
    .thumb_func
func_08038820:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    str	r1, [r7, #0]
    ldr r0, .Ljp_08038630
    str	r0, [r7, #4]
    ldr	r0, [r1, #24]
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    mov	sl, r0
    cmp	r0, #1
    bne .Ljp_08038638
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r6, r0, #0
    mov	r0, r9
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #116]	@ 0x74
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Ljp_08038634
    str	r0, [r6, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r6
    mov	r8, r1
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r0, r6, #0
    adds	r0, #72	@ 0x48
    mov	r5, sl
    strb	r5, [r0, #0]
    b .Ljp_0803863A
    .align 2, 0
.Ljp_08038630:
    .4byte vtable_unk_080E736C
.Ljp_08038634:
    .4byte vtable_unk_080E602C
.Ljp_08038638:
    movs	r6, #0
.Ljp_0803863A:
    str	r6, [r7, #8]
    movs	r0, #0
    str	r0, [r7, #12]
    str	r0, [r7, #16]
    adds	r4, r7, #0
    adds	r4, #20
    str	r0, [r7, #20]
    movs	r0, #202	@ 0xca
    lsls	r0, r0, #1
    bl __builtin_new
    adds	r3, r0, #0
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    movs	r2, #0
    mov	r5, r9
    ldr	r0, [r5, #24]
    adds	r0, #93	@ 0x5d
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803866A
    movs	r2, #1
.Ljp_0803866A:
    adds	r0, r3, #0
    bl func_080DCB7C
    mov	r9, r4
    mov	r8, r0
    ldr	r6, [r7, #20]
    cmp	r8, r6
    beq .Ljp_080386A4
    cmp	r6, #0
    beq .Ljp_080386A4
    ldr	r1, [r6, #0]
    lsls	r0, r1, #2
    adds	r0, r0, r1
    lsls	r0, r0, #4
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Ljp_0803869E
.Ljp_08038690:
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r4, #80	@ 0x50
    cmp	r4, r5
    bne .Ljp_08038690
.Ljp_0803869E:
    adds	r0, r6, #0
    bl __builtin_delete
.Ljp_080386A4:
    mov	r0, r8
    mov	r1, r9
    str	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08038928
    .thumb_func
func_08038928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    mov	r8, r0
    ldr	r0, [r0, #20]
    cmp	r0, #0
    beq .Ljp_0803871E
    adds	r6, r0, #0
    movs	r7, #0
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcs .Ljp_0803871E
    adds	r4, r6, #0
    adds	r4, #64	@ 0x40
    adds	r5, r6, #0
    adds	r5, #44	@ 0x2c
.Ljp_080386E0:
    ldrb	r0, [r4, #3]
    cmp	r0, #0
    bne .Ljp_080386F8
    adds	r0, r5, #0
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_080386FC
    movs	r0, #1
    strb	r0, [r4, #0]
    b .Ljp_080386FC
.Ljp_080386F8:
    movs	r0, #0
    strb	r0, [r4, #3]
.Ljp_080386FC:
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #12]
    subs	r1, r1, r0
    str	r1, [r4, #4]
    ldrb	r0, [r4, #16]
    lsls	r0, r0, #16
    cmn	r1, r0
    bge .Ljp_08038712
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #17
    str	r0, [r4, #4]
.Ljp_08038712:
    adds	r4, #80	@ 0x50
    adds	r5, #80	@ 0x50
    adds	r7, #1
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcc .Ljp_080386E0
.Ljp_0803871E:
    mov	r0, r8
    ldr	r1, [r0, #12]
    cmp	r1, #0
    beq .Ljp_08038746
    adds	r3, r1, #0
    adds	r3, #80	@ 0x50
    ldrb	r0, [r3, #0]
    cmp	r0, #0
    beq .Ljp_08038746
    ldr	r0, [r1, #76]	@ 0x4c
    ldr r2, .Ljp_08038788
    adds	r0, r0, r2
    str	r0, [r1, #76]	@ 0x4c
    movs	r2, #168	@ 0xa8
    lsls	r2, r2, #16
    cmp	r0, r2
    bgt .Ljp_08038746
    str	r2, [r1, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r3, #0]
.Ljp_08038746:
    mov	r1, r8
    ldr	r0, [r1, #16]
    cmp	r0, #0
    beq .Ljp_080387F4
    movs	r2, #0
    movs	r7, #0
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r5, r0, r1
    adds	r4, r0, #0
    adds	r4, #44	@ 0x2c
    adds	r6, r0, #0
    adds	r6, #67	@ 0x43
.Ljp_08038760:
    ldrb	r1, [r5, #0]
    cmp	r1, #0
    bne .Ljp_0803879C
    ldrb	r0, [r4, #23]
    cmp	r0, #0
    bne .Ljp_0803878C
    adds	r0, r4, #0
    str	r2, [sp, #0]
    bl func_0805E8F0
    adds	r1, r0, #0
    lsls	r0, r1, #30
    ldr	r2, [sp, #0]
    cmp	r0, #0
    bge .Ljp_08038782
    movs	r0, #1
    strb	r0, [r4, #20]
.Ljp_08038782:
    adds	r0, r1, #0
    b .Ljp_08038790
    .align 2, 0
.Ljp_08038788:
    .4byte 0xFFFF8000
.Ljp_0803878C:
    strb	r1, [r6, #0]
    movs	r0, #2
.Ljp_08038790:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Ljp_0803879E
    movs	r0, #1
    strb	r0, [r5, #0]
    b .Ljp_0803879E
.Ljp_0803879C:
    adds	r2, #1
.Ljp_0803879E:
    adds	r5, #1
    adds	r4, #64	@ 0x40
    adds	r6, #64	@ 0x40
    adds	r7, #1
    cmp	r7, #4
    bls .Ljp_08038760
    movs	r0, #0
    cmp	r2, #5
    bne .Ljp_080387B2
    movs	r0, #1
.Ljp_080387B2:
    cmp	r0, #0
    beq .Ljp_080387F4
    mov	r7, r8
    adds	r7, #16
    movs	r2, #0
    mov	r9, r2
    mov	r0, r8
    ldr	r6, [r0, #16]
    cmp	r9, r6
    beq .Ljp_080387F0
    cmp	r6, #0
    beq .Ljp_080387F0
    ldr	r0, [r6, #0]
    lsls	r0, r0, #6
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Ljp_080387EA
.Ljp_080387D8:
    ldr	r0, [r4, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r4, #0
    movs	r1, #2
    bl _call_via_r2
    adds	r4, #64	@ 0x40
    cmp	r4, r5
    bne .Ljp_080387D8
.Ljp_080387EA:
    adds	r0, r6, #0
    bl __builtin_delete
.Ljp_080387F0:
    mov	r1, r9
    str	r1, [r7, #0]
.Ljp_080387F4:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038A70
    .thumb_func
func_08038A70:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #140	@ 0x8c
    str	r0, [sp, #92]	@ 0x5c
    movs	r2, #12
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #96]	@ 0x60
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #100]	@ 0x64
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #56]	@ 0x38
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #20]
    cmp	r0, #0
    bne .Ljp_08038830
    b .Ljp_08038936
.Ljp_08038830:
    str	r0, [sp, #104]	@ 0x68
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #108]	@ 0x6c
    str	r1, [sp, #112]	@ 0x70
    movs	r1, #0
    str	r1, [sp, #116]	@ 0x74
    ldr	r2, [sp, #104]	@ 0x68
    ldr	r0, [r2, #0]
    cmp	r1, r0
    bcs .Ljp_08038936
    adds	r5, r2, #0
    adds	r5, #64	@ 0x40
    adds	r2, #20
    str	r2, [sp, #136]	@ 0x88
    ldr	r6, [sp, #104]	@ 0x68
    adds	r6, #4
.Ljp_08038852:
    ldr	r0, [sp, #108]	@ 0x6c
    ldr	r1, [sp, #112]	@ 0x70
    str	r0, [sp, #60]	@ 0x3c
    str	r1, [sp, #64]	@ 0x40
    ldrb	r0, [r5, #17]
    cmp	r0, #0
    beq .Ljp_0803891A
    movs	r1, #6
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    movs	r1, #8
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #100]	@ 0x64
    subs	r4, r0, r2
    ldr r0, .Ljp_080388C4
    mov	sl, r0
    add	r1, sp, #60	@ 0x3c
    mov	r8, r1
    ldr	r1, [r6, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r6, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, r8
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    ldr	r1, [r6, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_080388CC
    ldrh	r0, [r6, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #136]	@ 0x88
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Ljp_080388C8
    bl _call_via_r4
    b .Ljp_080388CE
.Ljp_080388C4:
    .4byte 0x00007FFF
.Ljp_080388C8:
    .4byte func_030004DC
.Ljp_080388CC:
    movs	r0, #0
.Ljp_080388CE:
    cmp	r0, #0
    beq .Ljp_08038916
    ldrb	r0, [r5, #0]
    adds	r4, r5, #0
    cmp	r0, #0
    beq .Ljp_08038916
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    ldrb	r0, [r5, #1]
    cmp	r0, #0
    beq .Ljp_080388FC
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_08038912
.Ljp_080388FC:
    ldrb	r0, [r5, #2]
    cmp	r0, #0
    bne .Ljp_08038912
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r5, #2]
.Ljp_08038912:
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08038916:
    movs	r0, #0
    b .Ljp_0803891C
.Ljp_0803891A:
    movs	r0, #1
.Ljp_0803891C:
    strb	r0, [r5, #17]
    adds	r5, #80	@ 0x50
    ldr	r1, [sp, #136]	@ 0x88
    adds	r1, #80	@ 0x50
    str	r1, [sp, #136]	@ 0x88
    adds	r6, #80	@ 0x50
    ldr	r2, [sp, #116]	@ 0x74
    adds	r2, #1
    str	r2, [sp, #116]	@ 0x74
    ldr	r1, [sp, #104]	@ 0x68
    ldr	r0, [r1, #0]
    cmp	r2, r0
    bcc .Ljp_08038852
.Ljp_08038936:
    ldr	r2, [sp, #92]	@ 0x5c
    ldr	r0, [r2, #8]
    cmp	r0, #0
    beq .Ljp_080389C4
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #68]	@ 0x44
    str	r1, [sp, #72]	@ 0x48
    movs	r0, #150	@ 0x96
    lsls	r0, r0, #1
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, r0, r1
    mov	r9, r1
    movs	r0, #100	@ 0x64
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #68	@ 0x44
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08038998
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Ljp_08038994
    bl _call_via_r4
    b .Ljp_0803899A
.Ljp_08038994:
    .4byte func_030004DC
.Ljp_08038998:
    movs	r0, #0
.Ljp_0803899A:
    cmp	r0, #0
    beq .Ljp_080389C4
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_080389C4
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_080389C4:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #12]
    cmp	r0, #0
    beq .Ljp_08038A5C
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #76]	@ 0x4c
    str	r1, [sp, #80]	@ 0x50
    adds	r0, r5, #0
    adds	r0, #81	@ 0x51
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #3
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, #240	@ 0xf0
    subs	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r5, #76]	@ 0x4c
    asrs	r0, r0, #16
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #76	@ 0x4c
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08038A30
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Ljp_08038A2C
    bl _call_via_r4
    b .Ljp_08038A32
    .align 2, 0
.Ljp_08038A2C:
    .4byte func_030004DC
.Ljp_08038A30:
    movs	r0, #0
.Ljp_08038A32:
    cmp	r0, #0
    beq .Ljp_08038A5C
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_08038A5C
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #0
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08038A5C:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #16]
    cmp	r0, #0
    bne .Ljp_08038A66
    b .Ljp_08038B74
.Ljp_08038A66:
    str	r0, [sp, #120]	@ 0x78
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #84]	@ 0x54
    str	r1, [sp, #88]	@ 0x58
    movs	r2, #0
    str	r2, [sp, #124]	@ 0x7c
    ldr	r0, [sp, #120]	@ 0x78
    adds	r0, #20
    str	r0, [sp, #128]	@ 0x80
    ldr r1, .Ljp_08038AFC
    str	r1, [sp, #132]	@ 0x84
    ldr	r5, [sp, #120]	@ 0x78
    adds	r5, #4
.Ljp_08038A82:
    ldr	r2, [sp, #120]	@ 0x78
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r0, r2, r1
    ldr	r2, [sp, #124]	@ 0x7c
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Ljp_08038B5C
    ldr	r1, [sp, #132]	@ 0x84
    ldrh	r0, [r1, #0]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    ldrh	r0, [r1, #2]
    ldr	r1, [sp, #100]	@ 0x64
    subs	r4, r0, r1
    adds	r6, r5, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #8
    mov	sl, r2
    add	r0, sp, #84	@ 0x54
    mov	r8, r0
    ldr	r1, [r5, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r5, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r8
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #0]
    ldr	r1, [r5, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08038B04
    ldrh	r0, [r5, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #128]	@ 0x80
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Ljp_08038B00
    bl _call_via_r4
    b .Ljp_08038B06
    .align 2, 0
.Ljp_08038AFC:
    .4byte gUnk_080F165E
.Ljp_08038B00:
    .4byte func_030004DC
.Ljp_08038B04:
    movs	r0, #0
.Ljp_08038B06:
    cmp	r0, #0
    beq .Ljp_08038B5C
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Ljp_08038B5C
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08038B3C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_08038B56
.Ljp_08038B3C:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_08038B56
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_08038B56:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Ljp_08038B5C:
    ldr	r2, [sp, #128]	@ 0x80
    adds	r2, #64	@ 0x40
    str	r2, [sp, #128]	@ 0x80
    ldr	r0, [sp, #132]	@ 0x84
    adds	r0, #4
    str	r0, [sp, #132]	@ 0x84
    adds	r5, #64	@ 0x40
    ldr	r1, [sp, #124]	@ 0x7c
    adds	r1, #1
    str	r1, [sp, #124]	@ 0x7c
    cmp	r1, #4
    bls .Ljp_08038A82
.Ljp_08038B74:
    add	sp, #140	@ 0x8c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038DF0
    .thumb_func
func_08038DF0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #8
    mov	r8, r0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r7, r0, #0
    mov	r1, r8
    ldr	r0, [r1, #0]
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r7, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Ljp_08038C20
    str	r0, [r7, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #72	@ 0x48
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    movs	r0, #144	@ 0x90
    lsls	r0, r0, #17
    str	r0, [r7, #76]	@ 0x4c
    adds	r0, r7, #0
    adds	r0, #80	@ 0x50
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r2, [r0, #0]
    mov	r5, r8
    adds	r5, #12
    adds	r6, r7, #0
    mov	r0, r8
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Ljp_08038C12
    cmp	r4, #0
    beq .Ljp_08038C12
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Ljp_08038C12:
    str	r6, [r5, #0]
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_08038C20:
    .4byte vtable_unk_080E602C
    .global func_08038E90
    .thumb_func
func_08038E90:
    ldr	r0, [r0, #12]
    movs	r1, #144	@ 0x90
    lsls	r1, r1, #17
    str	r1, [r0, #76]	@ 0x4c
    adds	r0, #80	@ 0x50
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .global func_08038EA0
    .thumb_func
func_08038EA0:
    push	{lr}
    ldr	r0, [r0, #12]
    movs	r1, #0
    adds	r0, #80	@ 0x50
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Ljp_08038C44
    movs	r1, #1
.Ljp_08038C44:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08038EB8
    .thumb_func
func_08038EB8:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    adds	r5, #12
    movs	r6, #0
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Ljp_08038C6C
    cmp	r4, #0
    beq .Ljp_08038C6C
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Ljp_08038C6C:
    str	r6, [r5, #0]
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08038EE0
    .thumb_func
func_08038EE0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #76	@ 0x4c
    mov	r9, r0
    movs	r0, #166	@ 0xa6
    lsls	r0, r0, #1
    bl __builtin_new
    mov	r2, r9
    ldr	r1, [r2, #0]
    adds	r5, r0, #0
    ldr	r6, [r1, #0]
    movs	r0, #0
    str	r0, [r5, #0]
    mov	sl, r0
    add	r3, sp, #8
    mov	r8, r3
    mov	r7, sl
    lsls	r0, r7, #2
    ldr r1, .Ljp_08038CA8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_08038CA8:
    .4byte .Ljp_08038CAC
.Ljp_08038CAC:
    .4byte .Ljp_08038CC0
    .4byte .Ljp_08038CE0
    .4byte .Ljp_08038CE0
    .4byte .Ljp_08038D70
    .4byte .Ljp_08038D70
.Ljp_08038CC0:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01F9FF
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0xE00E2202
.Ljp_08038CE0:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01F9EF
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332201
    .4byte 0xFB9AF06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xF96CF0A3
    .4byte 0x62604813
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFA42F06B
    .4byte 0x0000E046
    .4byte vtable_unk_080E681C
.Ljp_08038D70:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01F9A7
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332200
    .4byte 0xFB52F06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xF924F0A3
    .4byte 0x6260482C
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xF9FAF06B
    .4byte 0x004921A2
    .4byte 0x44501868
    .4byte 0x70012100
    .4byte 0x44922201
    .4byte 0x2B044653
    .4byte 0xE745D800
    .4byte 0x444F2710
    .4byte 0x1C2F46B8
    .4byte 0x69064648
    .4byte 0xD01442B7
    .4byte 0xD0122E00
    .4byte 0x01806830
    .4byte 0x18353004
    .4byte 0x42AC1D34
    .4byte 0x6A60D008
    .4byte 0x1C206882
    .4byte 0xF09A2102
    .4byte 0x3440F947
    .4byte 0xD1F642AC
    .4byte 0xF7C71C30
    .4byte 0x4641FBDF
    .4byte 0xB013600F
    .4byte 0x4698BC38
    .4byte 0x46AA46A1
    .4byte 0xBC01BCF0
    .4byte 0x00004700
    .4byte vtable_unk_080E681C
    .global func_080390D0
    .thumb_func
func_080390D0:
    ldr	r1, [r0, #16]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .hword 0x0000
    .4byte 0x1C04B510
    .4byte 0xF0253030
    .4byte 0x1C20FB95
    .4byte 0x22003044
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0xBC01BC10
    .4byte 0x00004700
    .4byte 0x78003026
    .4byte 0x00004770
    .4byte 0x80031FCB
    .4byte 0x80431F13
    .4byte 0x80813107
    .4byte 0x80C23205
    .4byte 0x00004770
    .4byte 0x6980B500
    .4byte 0xF87CF7D7
    .4byte 0x281E2100
    .4byte 0x2101D100
    .4byte 0xBC021C08
    .4byte 0x00004708
    .global func_08039134
    .thumb_func
func_08039134:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r6, r0, #0
    str	r1, [sp, #0]
    mov	sl, r2
    mov	r9, r3
    movs	r7, #100	@ 0x64
    movs	r0, #0
    mov	r8, r0
    movs	r5, #46	@ 0x2e
.Ljp_08038EE4:
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r6, #0
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08038F3A
    ldrh	r0, [r4, #4]
    ldr	r1, [sp, #0]
    cmp	r0, r1
    bne .Ljp_08038F3A
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08038F3A
    movs	r2, #10
    ldrsh	r1, [r4, r2]
    mov	r0, sl
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    mov	r2, r9
    subs	r0, r0, r2
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r0, r1, r0
    adds	r1, r0, #0
    cmp	r7, #100	@ 0x64
    beq .Ljp_08038F36
    cmp	r8, r0
    ble .Ljp_08038F3A
.Ljp_08038F36:
    adds	r7, r5, #0
    mov	r8, r1
.Ljp_08038F3A:
    adds	r5, #1
    cmp	r5, #69	@ 0x45
    ble .Ljp_08038EE4
    adds	r0, r7, #0
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391C0
    .thumb_func
func_080391C0:
    push	{lr}
    adds	r2, r0, #0
    cmp	r1, #56	@ 0x38
    bgt .Ljp_08038F68
    ldr r0, .Ljp_08038F80
    cmp	r2, r0
    ble .Ljp_08038F68
    adds	r0, #33	@ 0x21
    cmp	r2, r0
    ble .Ljp_08038F7A
.Ljp_08038F68:
    ldr r0, .Ljp_08038F84
    cmp	r1, r0
    ble .Ljp_08038F88
    cmp	r2, #247	@ 0xf7
    ble .Ljp_08038F88
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #1
    cmp	r2, r0
    bgt .Ljp_08038F88
.Ljp_08038F7A:
    movs	r0, #1
    b .Ljp_08038F8A
    .align 2, 0
.Ljp_08038F80:
    .4byte 0x00000143
.Ljp_08038F84:
    .4byte 0x0000027F
.Ljp_08038F88:
    movs	r0, #0
.Ljp_08038F8A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391FC
    .thumb_func
func_080391FC:
    bx	lr
    .align 2, 0
    .global func_08039200
    .thumb_func
func_08039200:
    movs	r0, #0
    bx	lr
    .global func_08039204
    .thumb_func
func_08039204:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r5, r1, #0
    str	r2, [sp, #16]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r1, r8
    adds	r1, #16
    str	r1, [sp, #20]
    mov	r2, r8
    ldrh	r4, [r2, #16]
    cmp	r4, #0
    beq .Ljp_08038FBC
    subs	r4, #1
.Ljp_08038FBC:
    ldrh	r3, [r5, #4]
    mov	ip, r3
    movs	r1, #10
    ldrsh	r0, [r5, r1]
    mov	r9, r0
    movs	r2, #14
    ldrsh	r7, [r5, r2]
    movs	r0, #176	@ 0xb0
    lsls	r0, r0, #1
    cmp	r7, r0
    ble .Ljp_08038FDE
    add	r3, sp, #8
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Ljp_08038FE8
.Ljp_08038FDE:
    add	r3, sp, #8
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Ljp_08038FE8:
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    add	r1, sp, #8
    adds	r0, r1, #0
    movs	r2, #0
    ldrsh	r3, [r0, r2]
    mov	sl, r3
    movs	r3, #2
    ldrsh	r6, [r1, r3]
    mov	r0, ip
    cmp	r0, #2
    bne .Ljp_0803907E
    mov	r1, sl
    mov	r2, r9
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Ljp_0803900E
    negs	r0, r0
.Ljp_0803900E:
    cmp	r0, #15
    bgt .Ljp_0803901E
    subs	r0, r6, r7
    cmp	r0, #0
    bge .Ljp_0803901A
    negs	r0, r0
.Ljp_0803901A:
    cmp	r0, #15
    ble .Ljp_0803907E
.Ljp_0803901E:
    cmp	r4, #0
    bne .Ljp_08039078
    mov	r0, r9
    adds	r1, r7, #0
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803904A
    movs	r1, #0
    cmp	r7, r6
    blt .Ljp_08039038
    movs	r1, #1
.Ljp_08039038:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Ljp_08039070
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Ljp_08039070
.Ljp_0803904A:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r3, [sp, #16]
    str	r3, [sp, #0]
    str	r0, [sp, #4]
    mov	r0, r9
    adds	r1, r7, #0
    mov	r2, sl
    adds	r3, r6, #0
    bl func_080AB678
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_08039070
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_08039070:
    movs	r0, #30
    bl func_080AB1C0
    adds	r4, r0, #1
.Ljp_08039078:
    ldr	r0, [sp, #20]
    strh	r4, [r0, #0]
    b .Ljp_08039090
.Ljp_0803907E:
    adds	r0, r5, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
    add	r1, sp, #12
    mov	r0, r8
    bl func_0809C098
.Ljp_08039090:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803930C
    .thumb_func
func_0803930C:
    movs	r0, #1
    bx	lr
    .global func_08039310
    .thumb_func
func_08039310:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    adds	r5, r1, #0
    str	r2, [sp, #28]
    ldr	r0, [r5, #52]	@ 0x34
    str	r0, [sp, #32]
    adds	r0, #16
    mov	r8, r0
    ldr	r3, [r5, #0]
    ldrb	r1, [r0, #6]
    str	r1, [sp, #36]	@ 0x24
    ldr	r2, [sp, #32]
    ldrh	r6, [r2, #16]
    cmp	r6, #0
    beq .Ljp_080390D8
    subs	r6, #1
    cmp	r6, #0
    bne .Ljp_080390D8
    cmp	r1, #0
    beq .Ljp_080390D8
    subs	r1, #1
    str	r1, [sp, #36]	@ 0x24
.Ljp_080390D8:
    ldr	r0, [r3, #0]
    mov	r2, r8
    ldrb	r1, [r2, #7]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    bne .Ljp_080390EE
    b .Ljp_0803921C
.Ljp_080390EE:
    ldrh	r0, [r4, #4]
    ldrh	r3, [r5, #4]
    cmp	r0, r3
    beq .Ljp_080390F8
    b .Ljp_0803921C
.Ljp_080390F8:
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803910A
    b .Ljp_0803921C
.Ljp_0803910A:
    movs	r0, #10
    ldrsh	r2, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    movs	r0, #10
    ldrsh	r3, [r4, r0]
    mov	sl, r3
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r9, r1
    ldr	r0, [sp, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_080391D8
    mov	r1, sl
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Ljp_0803912E
    negs	r0, r0
.Ljp_0803912E:
    cmp	r0, #15
    bgt .Ljp_08039140
    mov	r3, r9
    subs	r0, r3, r7
    cmp	r0, #0
    bge .Ljp_0803913C
    negs	r0, r0
.Ljp_0803913C:
    cmp	r0, #15
    ble .Ljp_080391D8
.Ljp_08039140:
    cmp	r6, #0
    beq .Ljp_08039168
    mov	r1, r8
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Ljp_08039152
    negs	r0, r0
.Ljp_08039152:
    cmp	r0, #15
    bgt .Ljp_080391CC
    mov	r1, r8
    movs	r3, #4
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r7
    cmp	r0, #0
    bge .Ljp_08039164
    negs	r0, r0
.Ljp_08039164:
    cmp	r0, #15
    bgt .Ljp_080391CC
.Ljp_08039168:
    adds	r0, r2, #0
    adds	r1, r7, #0
    str	r2, [sp, #40]	@ 0x28
    bl func_080391C0
    lsls	r0, r0, #24
    ldr	r2, [sp, #40]	@ 0x28
    cmp	r0, #0
    beq .Ljp_08039194
    movs	r1, #0
    cmp	r7, r9
    blt .Ljp_08039182
    movs	r1, #1
.Ljp_08039182:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Ljp_080391BA
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Ljp_080391BA
.Ljp_08039194:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r6, [sp, #28]
    str	r6, [sp, #0]
    str	r0, [sp, #4]
    adds	r0, r2, #0
    adds	r1, r7, #0
    mov	r2, sl
    mov	r3, r9
    bl func_080AB678
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Ljp_080391BA
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_080391BA:
    movs	r0, #30
    bl func_080AB1C0
    adds	r6, r0, #1
    mov	r1, sl
    mov	r0, r8
    strh	r1, [r0, #2]
    mov	r2, r9
    strh	r2, [r0, #4]
.Ljp_080391CC:
    add	r3, sp, #36	@ 0x24
    ldrb	r0, [r3, #0]
    mov	r3, r8
    strb	r0, [r3, #6]
    strh	r6, [r3, #0]
    b .Ljp_080392DC
.Ljp_080391D8:
    ldr r1, .Ljp_08039210
    ldr	r0, [sp, #8]
    ands	r0, r1
    movs	r1, #36	@ 0x24
    orrs	r0, r1
    ldr r1, .Ljp_08039214
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #9
    orrs	r0, r1
    str	r0, [sp, #8]
    mov	r6, r8
    ldrb	r1, [r6, #7]
    lsls	r1, r1, #24
    ldr r2, .Ljp_08039218
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #8]
    ldr	r0, [sp, #32]
    add	r1, sp, #8
    bl func_0809C0BC
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_0801FE58
    b .Ljp_080392DC
    .align 2, 0
.Ljp_08039210:
    .4byte 0xFFFF0000
.Ljp_08039214:
    .4byte 0xFF00FFFF
.Ljp_08039218:
    .4byte 0x00FFFFFF
.Ljp_0803921C:
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Ljp_0803923E
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Ljp_08039246
.Ljp_0803923E:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_0801FE58
.Ljp_08039246:
    cmp	r6, #100	@ 0x64
    beq .Ljp_080392C8
    movs	r0, #100	@ 0x64
    bl func_080AB1C0
    cmp	r0, #69	@ 0x45
    bhi .Ljp_08039290
    ldr r1, .Ljp_08039284
    ldr	r0, [sp, #12]
    ands	r0, r1
    str	r0, [sp, #12]
    movs	r0, #8
    bl func_080AB1C0
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Ljp_08039288
    add	r1, sp, #12
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    lsls	r3, r6, #24
    ldr r0, .Ljp_0803928C
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    adds	r0, r4, #0
    bl func_0809C0AC
    b .Ljp_080392DC
.Ljp_08039284:
    .4byte 0xFFFF0000
.Ljp_08039288:
    .4byte 0xFF00FFFF
.Ljp_0803928C:
    .4byte 0x00FFFFFF
.Ljp_08039290:
    movs	r0, #60	@ 0x3c
    bl func_080AB1C0
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_080392BC
    ldr	r1, [sp, #20]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_080392C0
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Ljp_080392C4
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Ljp_080392DC
.Ljp_080392BC:
    .4byte 0xFFFF0000
.Ljp_080392C0:
    .4byte 0xFF00FFFF
.Ljp_080392C4:
    .4byte 0x00FFFFFF
.Ljp_080392C8:
    ldr r1, .Ljp_080392EC
    ldr	r0, [sp, #24]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #24]
    add	r1, sp, #24
    adds	r0, r4, #0
    bl func_0809C0A0
.Ljp_080392DC:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_080392EC:
    .4byte 0xFFFF0000
    .global func_0803955C
    .thumb_func
func_0803955C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #16
    adds	r5, r1, #0
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r6, r8
    adds	r6, #16
    mov	r1, r8
    ldrh	r4, [r1, #16]
    cmp	r4, #0
    beq .Ljp_08039316
    subs	r4, #1
    cmp	r4, #0
    beq .Ljp_08039316
    b .Ljp_08039476
.Ljp_08039316:
    ldrb	r0, [r6, #2]
    cmp	r0, #0
    bne .Ljp_0803931E
    b .Ljp_08039468
.Ljp_0803931E:
    ldr	r4, [r5, #0]
    ldrh	r7, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    mov	r9, r2
    movs	r1, #14
    ldrsh	r0, [r5, r1]
    mov	sl, r0
    adds	r0, r4, #0
    adds	r1, r7, #0
    mov	r3, sl
    bl func_08039134
    adds	r1, r0, #0
    cmp	r1, #100	@ 0x64
    bne .Ljp_08039340
    ldrb	r1, [r6, #3]
.Ljp_08039340:
    ldr	r0, [r4, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r4, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08039396
    ldrh	r0, [r4, #4]
    cmp	r0, r7
    bne .Ljp_08039396
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08039396
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r6, r9
    subs	r0, r0, r6
    cmp	r0, #0
    bge .Ljp_08039378
    negs	r0, r0
.Ljp_08039378:
    cmp	r0, #15
    bgt .Ljp_08039396
    mov	r0, sl
    subs	r3, r1, r0
    cmp	r3, #0
    bge .Ljp_08039386
    negs	r3, r3
.Ljp_08039386:
    cmp	r3, #15
    bgt .Ljp_08039396
    ldr	r0, [r4, #20]
    adds	r0, #128	@ 0x80
    ldr	r1, [r0, #0]
    adds	r0, r4, #0
    bl _call_via_r1
.Ljp_08039396:
    mov	r0, r8
    movs	r1, #4
    bl func_0809C068
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Ljp_080393C0
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Ljp_080393C8
.Ljp_080393C0:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_0801FE58
.Ljp_080393C8:
    cmp	r6, #100	@ 0x64
    beq .Ljp_0803944C
    movs	r0, #100	@ 0x64
    bl func_080AB1C0
    cmp	r0, #69	@ 0x45
    bhi .Ljp_08039414
    ldr r1, .Ljp_08039408
    ldr	r0, [sp, #0]
    ands	r0, r1
    str	r0, [sp, #0]
    movs	r0, #8
    bl func_080AB1C0
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Ljp_0803940C
    ldr	r1, [sp, #4]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Ljp_08039410
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #4]
    adds	r0, r4, #0
    mov	r1, sp
    bl func_0809C0AC
    b .Ljp_08039478
    .align 2, 0
.Ljp_08039408:
    .4byte 0xFFFF0000
.Ljp_0803940C:
    .4byte 0xFF00FFFF
.Ljp_08039410:
    .4byte 0x00FFFFFF
.Ljp_08039414:
    movs	r0, #60	@ 0x3c
    bl func_080AB1C0
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_08039440
    ldr	r1, [sp, #8]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_08039444
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Ljp_08039448
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #8]
    add	r1, sp, #8
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Ljp_08039478
.Ljp_08039440:
    .4byte 0xFFFF0000
.Ljp_08039444:
    .4byte 0xFF00FFFF
.Ljp_08039448:
    .4byte 0x00FFFFFF
.Ljp_0803944C:
    ldr r1, .Ljp_08039464
    ldr	r0, [sp, #12]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #12]
    add	r1, sp, #12
    adds	r0, r4, #0
    bl func_0809C0A0
    b .Ljp_08039478
    .align 2, 0
.Ljp_08039464:
    .4byte 0xFFFF0000
.Ljp_08039468:
    movs	r4, #36	@ 0x24
    movs	r0, #1
    strb	r0, [r6, #2]
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_0801FE58
.Ljp_08039476:
    strh	r4, [r6, #0]
.Ljp_08039478:
    add	sp, #16
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_080396F4
    .thumb_func
func_080396F4:
    push	{lr}
    ldr	r0, [r1, #52]	@ 0x34
    ldrb	r0, [r0, #18]
    movs	r1, #0
    cmp	r0, #0
    beq .Ljp_08039496
    movs	r1, #3
.Ljp_08039496:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .global func_08039708
    .thumb_func
func_08039708:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r6, r1, #0
    mov	sl, r2
    ldr	r0, [r6, #52]	@ 0x34
    movs	r1, #16
    adds	r1, r1, r0
    mov	r9, r1
    ldr	r3, [r6, #0]
    ldrh	r2, [r0, #16]
    mov	r8, r2
    cmp	r2, #0
    beq .Ljp_080394C4
    movs	r4, #1
    negs	r4, r4
    add	r8, r4
.Ljp_080394C4:
    ldr	r1, [r0, #16]
    lsls	r0, r1, #9
    lsrs	r7, r0, #25
    cmp	r7, #0
    beq .Ljp_080394D0
    subs	r7, #1
.Ljp_080394D0:
    mov	r5, r9
    ldrb	r4, [r5, #3]
    cmp	r4, #0
    beq .Ljp_080394DA
    subs	r4, #1
.Ljp_080394DA:
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_0803955A
    ldr	r2, [r3, #0]
    lsls	r0, r1, #8
    movs	r1, #0
    cmp	r0, #0
    bge .Ljp_080394EC
    movs	r1, #43	@ 0x2b
.Ljp_080394EC:
    ldr	r2, [r2, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Ljp_0803955A
    ldrh	r0, [r3, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Ljp_0803955A
    cmp	r4, #0
    bne .Ljp_08039540
    movs	r2, #10
    ldrsh	r0, [r6, r2]
    movs	r4, #14
    ldrsh	r1, [r6, r4]
    movs	r5, #10
    ldrsh	r2, [r3, r5]
    movs	r4, #14
    ldrsh	r3, [r3, r4]
    adds	r5, r6, #0
    adds	r5, #32
    ldrb	r4, [r5, #0]
    mov	ip, r4
    mov	r4, sl
    str	r4, [sp, #0]
    mov	r4, ip
    str	r4, [sp, #4]
    bl func_080AB890
    adds	r1, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r0, r1
    beq .Ljp_08039538
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_08039538:
    movs	r0, #30
    bl func_080AB1C0
    adds	r4, r0, #1
.Ljp_08039540:
    mov	r0, r8
    mov	r5, r9
    strh	r0, [r5, #0]
    movs	r0, #127	@ 0x7f
    ands	r7, r0
    ldrb	r1, [r5, #2]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r7
    strb	r0, [r5, #2]
    strb	r4, [r5, #3]
    b .Ljp_08039620
.Ljp_0803955A:
    adds	r0, r6, #0
    bl func_080323C8
    ldr	r4, [r6, #52]	@ 0x34
    movs	r5, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Ljp_08039582
    ldr	r0, [r6, #0]
    ldrh	r1, [r6, #4]
    movs	r3, #10
    ldrsh	r2, [r6, r3]
    movs	r5, #14
    ldrsh	r3, [r6, r5]
    bl func_08039134
    adds	r5, r0, #0
    b .Ljp_0803958A
.Ljp_08039582:
    adds	r0, r6, #0
    movs	r1, #170	@ 0xaa
    bl func_0801FE58
.Ljp_0803958A:
    cmp	r5, #100	@ 0x64
    beq .Ljp_0803960C
    movs	r0, #100	@ 0x64
    bl func_080AB1C0
    cmp	r0, #69	@ 0x45
    bhi .Ljp_080395D4
    ldr r1, .Ljp_080395C8
    ldr	r0, [sp, #8]
    ands	r0, r1
    str	r0, [sp, #8]
    movs	r0, #8
    bl func_080AB1C0
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Ljp_080395CC
    ldr	r1, [sp, #12]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Ljp_080395D0
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #12]
    adds	r0, r4, #0
    add	r1, sp, #8
    bl func_0809C0AC
    b .Ljp_08039620
.Ljp_080395C8:
    .4byte 0xFFFF0000
.Ljp_080395CC:
    .4byte 0xFF00FFFF
.Ljp_080395D0:
    .4byte 0x00FFFFFF
.Ljp_080395D4:
    movs	r0, #60	@ 0x3c
    bl func_080AB1C0
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_08039600
    ldr	r1, [sp, #16]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_08039604
    ands	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Ljp_08039608
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #16]
    add	r1, sp, #16
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Ljp_08039620
.Ljp_08039600:
    .4byte 0xFFFF0000
.Ljp_08039604:
    .4byte 0xFF00FFFF
.Ljp_08039608:
    .4byte 0x00FFFFFF
.Ljp_0803960C:
    ldr r1, .Ljp_08039630
    ldr	r0, [sp, #20]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0A0
.Ljp_08039620:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_08039630:
    .4byte 0xFFFF0000
    .global func_080398A0
    .thumb_func
func_080398A0:
    movs	r0, #2
    bx	lr
    .global func_080398A4
    .thumb_func
func_080398A4:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r0, sp
    adds	r1, r5, #0
    bl __5ActorRC5Actor
    ldr r3, .Ljp_08039738
    adds	r0, r6, #0
    adds	r1, r4, #0
    mov	r2, sp
    bl func_08020038
    ldr r0, .Ljp_0803973C
    str	r0, [r6, #20]
    str	r5, [r6, #52]	@ 0x34
    adds	r1, r6, #0
    adds	r1, #56	@ 0x38
    movs	r0, #4
    movs	r3, #0
    movs	r2, #1
    negs	r2, r2
.Ljp_08039668:
    stmia	r1!, {r3}
    subs	r0, #1
    cmp	r0, r2
    bne .Ljp_08039668
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Ljp_08039740
    str	r0, [r4, #0]
    ldr	r0, [r6, #56]	@ 0x38
    cmp	r4, r0
    beq .Ljp_08039686
    bl __builtin_delete
.Ljp_08039686:
    str	r4, [r6, #56]	@ 0x38
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Ljp_08039744
    str	r0, [r4, #0]
    ldr	r0, [r6, #60]	@ 0x3c
    cmp	r4, r0
    beq .Ljp_0803969E
    bl __builtin_delete
.Ljp_0803969E:
    str	r4, [r6, #60]	@ 0x3c
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Ljp_08039748
    str	r0, [r4, #0]
    ldr	r0, [r6, #64]	@ 0x40
    cmp	r4, r0
    beq .Ljp_080396B6
    bl __builtin_delete
.Ljp_080396B6:
    str	r4, [r6, #64]	@ 0x40
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Ljp_0803974C
    str	r0, [r4, #0]
    ldr	r0, [r6, #68]	@ 0x44
    cmp	r4, r0
    beq .Ljp_080396CE
    bl __builtin_delete
.Ljp_080396CE:
    str	r4, [r6, #68]	@ 0x44
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Ljp_08039750
    str	r0, [r4, #0]
    ldr	r0, [r6, #72]	@ 0x48
    cmp	r4, r0
    beq .Ljp_080396E6
    bl __builtin_delete
.Ljp_080396E6:
    str	r4, [r6, #72]	@ 0x48
    ldr	r0, [r6, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r6
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_0801FE14
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08039724
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08039724:
    str	r4, [r6, #76]	@ 0x4c
    adds	r0, r6, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [r6, #80]	@ 0x50
    adds	r0, r6, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Ljp_08039738:
    .4byte 0x000009C7
.Ljp_0803973C:
    .4byte vtable_unk_080E74DC
.Ljp_08039740:
    .4byte vtable_unk_080E74CC
.Ljp_08039744:
    .4byte vtable_unk_080E74BC
.Ljp_08039748:
    .4byte vtable_unk_080E74AC
.Ljp_0803974C:
    .4byte vtable_unk_080E749C
.Ljp_08039750:
    .4byte vtable_unk_080E748C
    .global func_080399C0
    .thumb_func
func_080399C0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r7, r1, #0
    ldr r0, .Ljp_080397BC
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__5ActorRC13ActorLocation
    adds	r0, r5, #0
    adds	r0, #56	@ 0x38
    cmp	r0, #0
    beq .Ljp_08039790
    adds	r4, r5, #0
    adds	r4, #76	@ 0x4c
    cmp	r0, r4
    beq .Ljp_08039790
    adds	r6, r0, #0
.Ljp_08039784:
    subs	r4, #4
    ldr	r0, [r4, #0]
    bl __builtin_delete
    cmp	r6, r4
    bne .Ljp_08039784
.Ljp_08039790:
    ldr r0, .Ljp_080397C0
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_080397A6
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_080397A6:
    movs	r0, #1
    ands	r0, r7
    cmp	r0, #0
    beq .Ljp_080397B4
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_080397B4:
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_080397BC:
    .4byte vtable_unk_080E74DC
.Ljp_080397C0:
    .4byte __vt_7AEntity
    .global func_08039A30
    .thumb_func
func_08039A30:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08039A5C
    .thumb_func
func_08039A5C:
    bx	lr
    .align 2, 0
    .global func_08039A60
    .thumb_func
func_08039A60:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #112	@ 0x70
    adds	r7, r0, #0
    ldr	r0, [r7, #0]
    mov	sl, r0
    ldrb	r0, [r1, #4]
    cmp	r0, #0
    bne .Ljp_0803980E
    b .Ljp_08039940
.Ljp_0803980E:
    ldrh	r0, [r7, #4]
    cmp	r0, #2
    bne .Ljp_08039816
    b .Ljp_08039940
.Ljp_08039816:
    mov	r1, sl
    ldr	r0, [r1, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r0, r2
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrh	r1, [r2, #10]
    ldr r0, .Ljp_08039854
    ands	r0, r1
    cmp	r0, #20
    beq .Ljp_08039836
    b .Ljp_08039940
.Ljp_08039836:
    ldr	r0, [r2, #0]
    cmp	r0, #0
    beq .Ljp_0803983E
    b .Ljp_08039940
.Ljp_0803983E:
    movs	r0, #2
    bl func_080AB1C0
    cmp	r0, #0
    beq .Ljp_08039858
    add	r0, sp, #68	@ 0x44
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Ljp_08039862
.Ljp_08039854:
    .4byte 0x000007FF
.Ljp_08039858:
    add	r0, sp, #68	@ 0x44
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Ljp_08039862:
    strh	r1, [r0, #0]
    strh	r2, [r0, #2]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [sp, #72]	@ 0x48
    add	r4, sp, #72	@ 0x48
    movs	r3, #0
    ldrsh	r2, [r4, r3]
    movs	r6, #2
    ldrsh	r3, [r4, r6]
    mov	r0, sl
    movs	r1, #2
    bl func_08039134
    str	r0, [sp, #108]	@ 0x6c
    cmp	r0, #100	@ 0x64
    beq .Ljp_08039940
    movs	r0, #100	@ 0x64
    bl func_080AB1C0
    cmp	r0, #14
    bhi .Ljp_08039940
    movs	r0, #0
    ldrsh	r6, [r4, r0]
    movs	r2, #2
    ldrsh	r1, [r4, r2]
    mov	r8, r1
    mov	r3, sp
    movs	r2, #2
    ldrh	r1, [r3, #0]
    ldr r4, .Ljp_08039AAC
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #0]
    lsls	r6, r6, #16
    lsrs	r1, r6, #16
    movs	r0, #63	@ 0x3f
    mov	r9, r0
    ands	r1, r0
    lsls	r1, r1, #2
    ldrb	r5, [r3, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r5
    orrs	r0, r1
    strb	r0, [r3, #1]
    lsrs	r6, r6, #22
    ldrh	r1, [r3, #2]
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r6
    strh	r0, [r3, #2]
    mov	r1, r8
    lsls	r1, r1, #16
    mov	r8, r1
    lsrs	r0, r1, #16
    mov	r6, r9
    ands	r0, r6
    lsls	r0, r0, #2
    ldrb	r1, [r3, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r3, #3]
    mov	r0, r8
    lsrs	r0, r0, #22
    mov	r8, r0
    ldrh	r0, [r3, #4]
    ands	r4, r0
    mov	r1, r8
    orrs	r4, r1
    strh	r4, [r3, #4]
    add	r4, sp, #8
    movs	r5, #1
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    strb	r5, [r4, #6]
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__12AActorEntityRC13ActorLocation
    ldr r1, .Ljp_08039AB0
    ldr	r0, [sp, #76]	@ 0x4c
    ands	r0, r1
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #8
    bl func_080AB1C0
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Ljp_08039AB4
    add	r1, sp, #76	@ 0x4c
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    ldr	r6, [sp, #108]	@ 0x6c
    lsls	r3, r6, #24
    ldr r0, .Ljp_08039AB8
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    ldr	r0, [r7, #52]	@ 0x34
    bl func_0809C0AC
    adds	r0, r7, #0
    movs	r1, #171	@ 0xab
    bl func_0801FE58
.Ljp_08039940:
    ldrh	r5, [r7, #4]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    cmp	r5, r0
    bne .Ljp_0803994C
    b .Ljp_08039A9A
.Ljp_0803994C:
    mov	r0, sl
    ldr	r1, [r0, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    mov	r1, sl
    adds	r2, r5, #0
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #84	@ 0x54
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    add	r4, sp, #16
    movs	r1, #32
    mov	r8, r1
    movs	r2, #0
    mov	r9, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #16]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #36	@ 0x24
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #84]	@ 0x54
    ldr	r1, [sp, #88]	@ 0x58
    str	r0, [sp, #48]	@ 0x30
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r8
    str	r3, [r4, #40]	@ 0x28
    mov	r6, r9
    str	r6, [r4, #44]	@ 0x2c
    str	r6, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r8, r4
    cmp	r3, #0
    beq .Ljp_080399CC
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Ljp_080399CC
    ldr	r1, [r3, #20]
    add	r4, sp, #92	@ 0x5c
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080AB4C8
.Ljp_080399CC:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Ljp_080399FC
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Ljp_080399FC
    ldr	r1, [r3, #20]
    add	r4, sp, #100	@ 0x64
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080AB4C8
.Ljp_080399FC:
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #8]
    adds	r1, r7, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r5, [r0, #0]
    ldr	r1, [r7, #76]	@ 0x4c
    adds	r6, r0, #0
    cmp	r4, r1
    bne .Ljp_08039A3C
    ldr	r0, [r7, #80]	@ 0x50
    cmp	r5, r0
    beq .Ljp_08039A4C
.Ljp_08039A3C:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r7, #0
    bl func_0801FE14
.Ljp_08039A4C:
    ldr	r0, [r7, #76]	@ 0x4c
    cmp	r4, r0
    beq .Ljp_08039A68
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08039A68
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08039A68:
    str	r4, [r7, #76]	@ 0x4c
    str	r5, [r7, #80]	@ 0x50
    mov	r4, r8
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    ldrb	r1, [r6, #0]
    subs	r0, #1
    cmp	r0, #1
    bhi .Ljp_08039A92
    cmp	r1, #1
    bhi .Ljp_08039A92
    movs	r1, #10
    ldrsh	r0, [r7, r1]
    movs	r2, #14
    ldrsh	r1, [r7, r2]
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08039A92
    movs	r4, #0
.Ljp_08039A92:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_0801FF04
.Ljp_08039A9A:
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_08039ABC
    subs	r0, #1
    b .Ljp_08039ABE
.Ljp_08039AAC:
    .4byte 0xFFFFFC00
.Ljp_08039AB0:
    .4byte 0xFFFF0000
.Ljp_08039AB4:
    .4byte 0xFF00FFFF
.Ljp_08039AB8:
    .4byte 0x00FFFFFF
.Ljp_08039ABC:
    ldrh	r0, [r7, #38]	@ 0x26
.Ljp_08039ABE:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Ljp_08039AD0
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Ljp_08039AD0:
    add	sp, #112	@ 0x70
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08039D4C
    .thumb_func
func_08039D4C:
    ldr r0, .Ljp_08039AEC
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Ljp_08039AEC:
    .4byte gUnk_080F16AE
    .global func_08039D5C
    .thumb_func
func_08039D5C:
    push	{lr}
    cmp	r1, #4
    bhi .Ljp_08039B24
    lsls	r0, r1, #2
    ldr r1, .Ljp_08039B00
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_08039B00:
    .4byte .Ljp_08039B04
.Ljp_08039B04:
    .4byte .Ljp_08039B24
    .4byte .Ljp_08039B18
    .4byte .Ljp_08039B1E
    .4byte .Ljp_08039B24
    .4byte .Ljp_08039B24
.Ljp_08039B18:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE003
.Ljp_08039B1E:
    .hword 0x2080
    .4byte 0xE0000240
.Ljp_08039B24:
    movs	r0, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039D98
    .thumb_func
func_08039D98:
    ldr	r0, [r0, #52]	@ 0x34
    ldr	r1, [r0, #12]
    movs	r0, #4
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .global func_08039DA8
    .thumb_func
func_08039DA8:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Ljp_08039B94
    movs	r0, #120	@ 0x78
    bl func_080AB1C0
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_08039B9C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_08039BA0
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    ldr r0, .Ljp_08039BA4
    ands	r1, r0
    ldr r0, .Ljp_08039BA8
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #15
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_0801FE58
.Ljp_08039B94:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
.Ljp_08039B9C:
    .4byte 0xFFFF0000
.Ljp_08039BA0:
    .4byte 0xFF80FFFF
.Ljp_08039BA4:
    .4byte 0xFF7FFFFF
.Ljp_08039BA8:
    .4byte 0x00FFFFFF
    .global func_08039E18
    .thumb_func
func_08039E18:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Ljp_08039C06
    movs	r0, #120	@ 0x78
    bl func_080AB1C0
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_08039C10
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_08039C14
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #16
    orrs	r1, r0
    ldr r0, .Ljp_08039C18
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #4
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_0801FE58
.Ljp_08039C06:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08039C10:
    .4byte 0xFFFF0000
.Ljp_08039C14:
    .4byte 0xFF80FFFF
.Ljp_08039C18:
    .4byte 0x00FFFFFF
    .global func_08039E88
    .thumb_func
func_08039E88:
    movs	r0, #2
    bx	lr
    .4byte 0x68C96B41
    .4byte 0x18090089
    .4byte 0x47706B88
    .global func_08039E98
    .thumb_func
func_08039E98:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r6, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    ldr r0, .Ljp_08039CC4
    str	r0, [r7, #76]	@ 0x4c
    str	r6, [r7, #0]
    movs	r4, #0
    strh	r5, [r7, #4]
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r0, r7, #0
    adds	r0, #8
    movs	r2, #3
    str	r2, [sp, #0]
    movs	r2, #27
    str	r2, [sp, #4]
    add	r2, sp, #8
    strb	r4, [r2, #0]
    adds	r2, r5, #0
    adds	r3, r6, #0
    bl func_080A4A00
    mov	r0, r9
    cmp	r0, #1
    bne .Ljp_08039CD0
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r5, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r4, r0, #0
    adds	r0, r5, #0
    adds	r1, r6, #0
    movs	r2, #2
    movs	r3, #15
    bl func_080A4740
    ldr r0, .Ljp_08039CC8
    str	r0, [r5, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r5
    mov	r8, r1
    ldr	r6, [r4, #0]
    add	r0, sp, #12
    ldr	r3, [r6, #12]
    adds	r1, r4, #0
    ldr r2, .Ljp_08039CCC
    bl _call_via_r3
    ldr	r0, [sp, #12]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r6, #16]
    adds	r1, r4, #0
    bl _call_via_r3
    adds	r0, r5, #0
    adds	r0, #72	@ 0x48
    mov	r1, r9
    strb	r1, [r0, #0]
    b .Ljp_08039CD2
    .align 2, 0
.Ljp_08039CC4:
    .4byte vtable_unk_080E76BC
.Ljp_08039CC8:
    .4byte vtable_unk_080E602C
.Ljp_08039CCC:
    .4byte 0x0000091A
.Ljp_08039CD0:
    movs	r5, #0
.Ljp_08039CD2:
    str	r5, [r7, #72]	@ 0x48
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08039F50
    .thumb_func
func_08039F50:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldr r0, .Ljp_08039D20
    str	r0, [r4, #76]	@ 0x4c
    ldr	r1, [r4, #72]	@ 0x48
    cmp	r1, #0
    beq .Ljp_08039D00
    ldr	r0, [r1, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_08039D00:
    adds	r0, r4, #0
    adds	r0, #8
    movs	r1, #2
    bl func_080A47B4
    movs	r0, #1
    ands	r0, r5
    cmp	r0, #0
    beq .Ljp_08039D18
    adds	r0, r4, #0
    bl __builtin_delete
.Ljp_08039D18:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08039D20:
    .4byte vtable_unk_080E76BC
    .global func_08039F90
    .thumb_func
func_08039F90:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    mov	sl, r0
    adds	r4, r1, #0
    mov	r9, r2
    mov	r8, r3
    ldr	r5, [sp, #104]	@ 0x68
    ldr	r6, [sp, #108]	@ 0x6c
    ldr	r7, [sp, #112]	@ 0x70
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #24]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r5, r5, r0
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #28]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r0, r6, r0
    str	r0, [sp, #64]	@ 0x40
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r6
    str	r0, [sp, #68]	@ 0x44
    add	r0, sp, #52	@ 0x34
    mov	r1, r8
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r9
    str	r3, [r0, #4]
    adds	r5, r7, #0
    mov	r9, r0
    cmp	r5, #0
    bge .Ljp_08039D76
    negs	r7, r5
.Ljp_08039D76:
    ldr	r4, [sp, #64]	@ 0x40
    subs	r4, r4, r7
    mov	r8, r4
    mov	r6, sl
    adds	r6, #8
    movs	r0, #3
    ldr	r7, [sp, #116]	@ 0x74
    ands	r0, r7
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    mov	r0, sl
    ldr	r1, [r0, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r0, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r9
    ldr	r1, [r1, #4]
    mov	ip, r1
    mov	r3, sl
    ldr	r2, [r3, #8]
    ldr	r1, [r3, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08039DE8
    ldrh	r0, [r6, #12]
    mov	r1, sl
    adds	r1, #24
    ldr	r3, [sp, #68]	@ 0x44
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    ldr	r1, [sp, #60]	@ 0x3c
    mov	r2, r8
    adds	r3, r4, #0
    ldr r4, .Ljp_08039DE4
    bl _call_via_r4
    b .Ljp_08039DEA
.Ljp_08039DE4:
    .4byte func_030004DC
.Ljp_08039DE8:
    movs	r0, #0
.Ljp_08039DEA:
    cmp	r0, #0
    beq .Ljp_08039E3E
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r8, r0
    cmp	r1, #0
    beq .Ljp_08039E3E
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08039E1E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_08039E38
.Ljp_08039E1E:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_08039E38
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_08039E38:
    movs	r0, #0
    mov	r4, r8
    strb	r0, [r4, #0]
.Ljp_08039E3E:
    mov	r7, sl
    ldr	r0, [r7, #72]	@ 0x48
    cmp	r0, #0
    beq .Ljp_08039EC8
    cmp	r5, #0
    blt .Ljp_08039EC8
    adds	r6, r0, #0
    mov	r5, r9
    movs	r0, #3
    ldr	r1, [sp, #116]	@ 0x74
    ands	r0, r1
    lsls	r3, r0, #2
    orrs	r3, r0
    lsls	r1, r0, #4
    orrs	r3, r1
    lsls	r0, r0, #6
    orrs	r3, r0
    adds	r7, r6, #0
    adds	r7, #40	@ 0x28
    ldr	r4, [r5, #4]
    mov	r8, r4
    adds	r0, r6, #0
    ldmia	r0!, {r2}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08039E9C
    ldrh	r0, [r6, #12]
    adds	r1, r6, #0
    adds	r1, #16
    ldr	r4, [sp, #68]	@ 0x44
    str	r4, [sp, #0]
    str	r7, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r8
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #64]	@ 0x40
    ldr r4, .Ljp_08039E98
    bl _call_via_r4
    b .Ljp_08039E9E
    .align 2, 0
.Ljp_08039E98:
    .4byte func_030004DC
.Ljp_08039E9C:
    movs	r0, #0
.Ljp_08039E9E:
    cmp	r0, #0
    beq .Ljp_08039EC8
    adds	r4, r6, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_08039EC8
    ldr	r1, [r5, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08039EC8:
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803A144
    .thumb_func
func_0803A144:
    push	{r4, lr}
    adds	r4, r1, #0
    lsls	r2, r2, #24
    lsrs	r0, r2, #24
    cmp	r2, #0
    bge .Ljp_08039EEE
    movs	r0, #3
    bl func_080AB1C0
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
.Ljp_08039EEE:
    ldr r2, .Ljp_08039F10
    lsls	r0, r0, #24
    asrs	r0, r0, #24
    lsls	r1, r0, #2
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #4]
    lsls	r1, r0, #1
    adds	r1, #1
    lsls	r1, r1, #1
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #6]
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08039F10:
    .4byte gUnk_080F16C2
    .global func_0803A180
    .thumb_func
func_0803A180:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #72	@ 0x48
    mov	r8, r0
    adds	r4, r1, #0
    adds	r5, r2, #0
    movs	r0, #0
    mov	r9, r0
    mov	r2, r8
    ldr	r1, [r2, #0]
    ldr	r2, [r1, #0]
    mov	r0, sp
    ldr	r3, [r2, #52]	@ 0x34
    movs	r2, #0
    bl _call_via_r3
    movs	r6, #4
    ldrsh	r1, [r4, r6]
    movs	r7, #6
    ldrsh	r3, [r4, r7]
    add	r2, sp, #64	@ 0x40
    adds	r0, r1, #0
    subs	r0, #8
    strh	r0, [r2, #0]
    adds	r0, r3, #0
    subs	r0, #8
    strh	r0, [r2, #2]
    adds	r1, #8
    strh	r1, [r2, #4]
    adds	r3, #8
    strh	r3, [r2, #6]
    add	r3, sp, #12
    movs	r0, #32
    mov	ip, r0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    subs	r0, #65	@ 0x41
    str	r0, [r3, #4]
    str	r0, [r3, #8]
    str	r1, [r3, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r6, r7}
    stmia	r1!, {r2, r6, r7}
    ldr	r0, [sp, #64]	@ 0x40
    ldr	r1, [sp, #68]	@ 0x44
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r0, ip
    str	r0, [r3, #40]	@ 0x28
    mov	r1, r9
    str	r1, [r3, #44]	@ 0x2c
    str	r1, [r3, #48]	@ 0x30
    movs	r0, #18
    ldrsb	r0, [r4, r0]
    cmp	r0, #0
    beq .Ljp_0803A03A
    cmp	r0, #1
    bne .Ljp_0803A03A
    ldr	r0, [r4, #0]
    cmp	r0, #1
    beq .Ljp_08039FC8
    cmp	r0, #1
    bgt .Ljp_08039F9E
    cmp	r0, #0
    beq .Ljp_08039FA8
    b .Ljp_0803A036
.Ljp_08039F9E:
    cmp	r0, #2
    beq .Ljp_08039FE8
    cmp	r0, #3
    beq .Ljp_0803A008
    b .Ljp_0803A036
.Ljp_08039FA8:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Ljp_08039FBA
    adds	r0, r3, #0
    bl func_080AB294
    ldr	r0, [sp, #12]
    b .Ljp_08039FBC
.Ljp_08039FBA:
    adds	r0, r1, #0
.Ljp_08039FBC:
    cmp	r0, #1
    ble .Ljp_0803A036
    ldr	r0, [r4, #12]
    adds	r0, r0, r5
    str	r0, [r4, #12]
    b .Ljp_0803A03A
.Ljp_08039FC8:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Ljp_08039FD8
    adds	r0, r3, #0
    bl func_080AB308
    ldr	r1, [sp, #16]
.Ljp_08039FD8:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Ljp_0803A036
    ldr	r0, [r4, #12]
    subs	r0, r0, r5
    str	r0, [r4, #12]
    b .Ljp_0803A03A
.Ljp_08039FE8:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Ljp_08039FF8
    adds	r0, r3, #0
    bl func_080AB380
    ldr	r1, [sp, #20]
.Ljp_08039FF8:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Ljp_0803A036
    ldr	r0, [r4, #8]
    subs	r0, r0, r5
    str	r0, [r4, #8]
    b .Ljp_0803A03A
.Ljp_0803A008:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Ljp_0803A01A
    adds	r0, r3, #0
    bl func_080AB3FC
    ldr	r0, [sp, #24]
    b .Ljp_0803A01C
.Ljp_0803A01A:
    adds	r0, r1, #0
.Ljp_0803A01C:
    cmp	r0, #1
    ble .Ljp_0803A036
    ldr	r0, [r4, #8]
    adds	r0, r0, r5
    str	r0, [r4, #8]
    asrs	r0, r0, #16
    movs	r1, #145	@ 0x91
    lsls	r1, r1, #2
    cmp	r0, r1
    ble .Ljp_0803A03A
    movs	r0, #145	@ 0x91
    lsls	r0, r0, #18
    str	r0, [r4, #8]
.Ljp_0803A036:
    movs	r0, #0
    strh	r0, [r4, #16]
.Ljp_0803A03A:
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    strh	r0, [r4, #4]
    movs	r6, #14
    ldrsh	r0, [r4, r6]
    strh	r0, [r4, #6]
    mov	r1, r8
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_0803A066
    mov	r0, r8
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_0803A06A
    mov	r1, r8
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Ljp_0803A068
.Ljp_0803A066:
    movs	r0, #0
.Ljp_0803A068:
    strb	r0, [r1, #0]
.Ljp_0803A06A:
    ldrh	r0, [r4, #16]
    subs	r0, #1
    strh	r0, [r4, #16]
    lsls	r0, r0, #16
    cmp	r0, #0
    bge .Ljp_0803A0A4
    movs	r0, #3
    bl func_080AB1C0
    lsls	r0, r0, #16
    asrs	r1, r0, #16
    cmp	r1, #3
    bne .Ljp_0803A08A
    movs	r0, #0
    strb	r0, [r4, #18]
    b .Ljp_0803A096
.Ljp_0803A08A:
    movs	r0, #1
    strb	r0, [r4, #18]
    ldr	r0, [r4, #0]
    bl func_080AB1DC
    str	r0, [r4, #0]
.Ljp_0803A096:
    movs	r0, #31
    bl func_080AB1C0
    adds	r0, #16
    strh	r0, [r4, #16]
    movs	r7, #1
    mov	r9, r7
.Ljp_0803A0A4:
    mov	r0, r9
    add	sp, #72	@ 0x48
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803A320
    .thumb_func
func_0803A320:
    ldr r0, .Ljp_0803A0C4
    lsls	r1, r1, #16
    asrs	r1, r1, #15
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Ljp_0803A0C4:
    .4byte gUnk_080F16D2
    .global func_0803A334
    .thumb_func
func_0803A334:
    ldr r2, .Ljp_0803A0E0
    lsls	r1, r1, #16
    asrs	r1, r1, #16
    adds	r1, #64	@ 0x40
    movs	r0, #255	@ 0xff
    ands	r1, r0
    lsls	r1, r1, #1
    adds	r1, r1, r2
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Ljp_0803A0E0:
    .4byte gUnk_080F16D2
    .global func_0803A350
    .thumb_func
func_0803A350:
    push	{r4, r5, r6, lr}
    adds	r6, r1, #0
    ldr	r0, [r0, #0]
    ldr	r1, [r0, #0]
    movs	r2, #166	@ 0xa6
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldr	r4, [r0, #0]
    ldr	r5, [r0, #4]
    cmp	r4, r5
    beq .Ljp_0803A116
.Ljp_0803A100:
    ldr	r0, [r4, #0]
    bl func_08008CD0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803A110
    ldr	r0, [r4, #0]
    b .Ljp_0803A11A
.Ljp_0803A110:
    adds	r4, #4
    cmp	r4, r5
    bne .Ljp_0803A100
.Ljp_0803A116:
    subs	r0, r5, #4
    ldr	r0, [r0, #0]
.Ljp_0803A11A:
    lsls	r1, r6, #16
    lsrs	r1, r1, #16
    bl func_08008B6C
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_0803A394
    .thumb_func
func_0803A394:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    adds	r5, r2, #0
    lsls	r3, r3, #24
    lsrs	r3, r3, #24
    mov	r9, r3
    ldr r7, .Ljp_0803A178
    cmp	r3, #0
    bne .Ljp_0803A148
    ldr r7, .Ljp_0803A17C
.Ljp_0803A148:
    movs	r0, #4
    mov	sl, r0
    mov	r1, r9
    cmp	r1, #0
    bne .Ljp_0803A156
    movs	r2, #10
    mov	sl, r2
.Ljp_0803A156:
    movs	r0, #99	@ 0x63
    bl func_080AB1C0
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    movs	r3, #0
    str	r3, [sp, #0]
    movs	r0, #0
    str	r0, [sp, #4]
    mov	ip, r0
    cmp	r5, #1
    beq .Ljp_0803A190
    cmp	r5, #1
    bgt .Ljp_0803A180
    cmp	r5, #0
    beq .Ljp_0803A18A
    b .Ljp_0803A1A0
.Ljp_0803A178:
    .4byte gUnk_080F1904
.Ljp_0803A17C:
    .4byte gUnk_080F18D2
.Ljp_0803A180:
    cmp	r5, #2
    beq .Ljp_0803A196
    cmp	r5, #3
    beq .Ljp_0803A19C
    b .Ljp_0803A1A0
.Ljp_0803A18A:
    movs	r1, #0
    mov	ip, r1
    b .Ljp_0803A1A0
.Ljp_0803A190:
    movs	r2, #1
    mov	ip, r2
    b .Ljp_0803A1A0
.Ljp_0803A196:
    movs	r3, #2
    mov	ip, r3
    b .Ljp_0803A1A0
.Ljp_0803A19C:
    movs	r5, #3
    mov	ip, r5
.Ljp_0803A1A0:
    movs	r3, #0
    cmp	r3, sl
    bge .Ljp_0803A1EC
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    mov	r2, ip
    adds	r1, r7, r2
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Ljp_0803A1BC
    str	r3, [sp, #0]
    ldrb	r5, [r7, #4]
    str	r5, [sp, #4]
    b .Ljp_0803A1EC
.Ljp_0803A1BC:
    lsls	r0, r3, #2
    adds	r0, r0, r3
    adds	r0, r0, r7
    add	r0, ip
    ldrb	r0, [r0, #0]
    subs	r0, r4, r0
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    adds	r3, #1
    cmp	r3, sl
    bge .Ljp_0803A1EC
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    lsls	r1, r3, #2
    adds	r1, r1, r3
    adds	r2, r1, r7
    mov	r5, ip
    adds	r1, r2, r5
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Ljp_0803A1BC
    str	r3, [sp, #0]
    ldrb	r2, [r2, #4]
    str	r2, [sp, #4]
.Ljp_0803A1EC:
    ldr	r0, [sp, #0]
    cmp	r0, #0
    beq .Ljp_0803A1FC
    mov	r1, r9
    cmp	r1, #0
    beq .Ljp_0803A1FC
    adds	r0, #9
    str	r0, [sp, #0]
.Ljp_0803A1FC:
    ldr	r2, [sp, #4]
    cmp	r2, #1
    ble .Ljp_0803A20E
    adds	r0, r2, #0
    subs	r0, #1
    bl func_080AB1C0
    adds	r0, #1
    str	r0, [sp, #4]
.Ljp_0803A20E:
    ldr	r3, [sp, #4]
    cmp	r3, #0
    bgt .Ljp_0803A216
    b .Ljp_0803A516
.Ljp_0803A216:
    movs	r0, #196	@ 0xc4
    lsls	r0, r0, #1
    bl func_080AB1C0
    adds	r5, r0, #0
    adds	r5, #184	@ 0xb8
    cmp	r5, #239	@ 0xef
    bgt .Ljp_0803A234
    movs	r0, #56	@ 0x38
    bl func_080AB1C0
    movs	r1, #248	@ 0xf8
    lsls	r1, r1, #1
    adds	r7, r0, r1
    b .Ljp_0803A240
.Ljp_0803A234:
    movs	r0, #48	@ 0x30
    bl func_080AB1C0
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r7, r0, r2
.Ljp_0803A240:
    ldr	r0, [sp, #0]
    subs	r0, #1
    cmp	r0, #11
    bls .Ljp_0803A24A
    b .Ljp_0803A50A
.Ljp_0803A24A:
    lsls	r0, r0, #2
    ldr r1, .Ljp_0803A254
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0803A254:
    .4byte .Ljp_0803A258
.Ljp_0803A258:
    .4byte .Ljp_0803A288
    .4byte .Ljp_0803A2F0
    .4byte .Ljp_0803A30C
    .4byte .Ljp_0803A32C
    .4byte .Ljp_0803A34C
    .4byte .Ljp_0803A39C
    .4byte .Ljp_0803A404
    .4byte .Ljp_0803A424
    .4byte .Ljp_0803A444
    .4byte .Ljp_0803A464
    .4byte .Ljp_0803A484
    .4byte .Ljp_0803A4A4
.Ljp_0803A288:
    .4byte 0xF7C62064
    .4byte 0x1C04F9A3
    .4byte 0x4A154641
    .4byte 0xF7FF2301
    .4byte 0x4814FCC9
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x210065A0
    .4byte 0x04005E68
    .4byte 0x1C3165E0
    .4byte 0x68B03108
    .4byte 0xD9002802
    .4byte 0x0080E119
    .4byte 0x18083004
    .4byte 0xD1002800
    .4byte 0x6004E110
    .4byte 0x0000E10E
    .4byte 0x000009B6
    .4byte vtable_unk_080E76A4
.Ljp_0803A2F0:
    .4byte 0xF7C62064
    .4byte 0x1C04F96F
    .4byte 0x22104641
    .4byte 0xF7FF2301
    .4byte 0x4801FC95
    .4byte 0x0000E7CA
    .4byte vtable_unk_080E768C
.Ljp_0803A30C:
    .4byte 0xF7C62064
    .4byte 0x1C04F961
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC87
    .4byte 0x0000E7BC
    .4byte 0x000003DB
    .4byte vtable_unk_080E7674
.Ljp_0803A32C:
    .4byte 0xF7C62064
    .4byte 0x1C04F951
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC77
    .4byte 0x0000E7AC
    .4byte 0x00000806
    .4byte vtable_unk_080E765C
.Ljp_0803A34C:
    .4byte 0xF7C6206C
    .4byte 0x1C04F941
    .4byte 0x4A0F4641
    .4byte 0xF7FF2301
    .4byte 0x480EFC67
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x220065A0
    .4byte 0x04005EA8
    .4byte 0x66A165E0
    .4byte 0x0000E79B
    .4byte 0x00000202
    .4byte vtable_unk_080E7644
.Ljp_0803A39C:
    .4byte 0xF7C62088
    .4byte 0x1C05F919
    .4byte 0x22A94641
    .4byte 0x23010092
    .4byte 0xFC3EF7FF
    .4byte 0x64E84813
    .4byte 0x652C2400
    .4byte 0x31501C29
    .4byte 0x22011C28
    .4byte 0xF7FF4252
    .4byte 0x1C29FD89
    .4byte 0x70083178
    .4byte 0x20FF3101
    .4byte 0x1C287008
    .4byte 0x21003060
    .4byte 0x30028004
    .4byte 0x380E7001
    .4byte 0x5EC02300
    .4byte 0x65A80400
    .4byte 0x30561C28
    .4byte 0x5E402100
    .4byte 0x65E80400
    .4byte 0x31841C29
    .4byte 0x700820F8
    .4byte 0x0000E077
    .4byte vtable_unk_080E762C
.Ljp_0803A404:
    .4byte 0xF7C62064
    .4byte 0x1C04F8E5
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC0B
    .4byte 0x0000E740
    .4byte 0x0000087B
    .4byte vtable_unk_080E7614
.Ljp_0803A424:
    .4byte 0xF7C62064
    .4byte 0x1C04F8D5
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBFB
    .4byte 0x0000E730
    .4byte 0x0000065C
    .4byte vtable_unk_080E75FC
.Ljp_0803A444:
    .4byte 0xF7C62064
    .4byte 0x1C04F8C5
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBEB
    .4byte 0x0000E720
    .4byte 0x000008F9
    .4byte vtable_unk_080E75E4
.Ljp_0803A464:
    .4byte 0xF7C62064
    .4byte 0x1C04F8B5
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBDB
    .4byte 0x0000E710
    .4byte 0x000009A9
    .4byte vtable_unk_080E75CC
.Ljp_0803A484:
    .4byte 0xF7C62064
    .4byte 0x1C04F8A5
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBCB
    .4byte 0x0000E700
    .4byte 0x000008FD
    .4byte vtable_unk_080E75B4
.Ljp_0803A4A4:
    .4byte 0xF7C62064
    .4byte 0x1C05F895
    .4byte 0x22154641
    .4byte 0xF7FF2300
    .4byte 0x481CFBBB
    .4byte 0x240064E8
    .4byte 0x1C29652C
    .4byte 0x1C283150
    .4byte 0x42522201
    .4byte 0xFD06F7FF
    .4byte 0x30601C28
    .4byte 0x80042100
    .4byte 0x70013002
    .4byte 0x2200380E
    .4byte 0x04005E80
    .4byte 0x1C2865A8
    .4byte 0x23003056
    .4byte 0x04005EC0
    .4byte 0x1C3165E8
    .4byte 0x68B03108
    .4byte 0xD8082802
    .4byte 0x30040080
    .4byte 0x28001808
    .4byte 0x6005D000
    .4byte 0x300168B0
    .hword 0x60B0
.Ljp_0803A50A:
    ldr	r5, [sp, #4]
    subs	r5, #1
    str	r5, [sp, #4]
    cmp	r5, #0
    ble .Ljp_0803A516
    b .Ljp_0803A216
.Ljp_0803A516:
    add	sp, #8

    .else
    .ifdef REGION_EU
    @ ROM-verified EU Thumb entity UI code
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08035380
    .thumb_func
func_08035380:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #188	@ 0xbc
    adds	r6, r0, #0
    ldr	r5, [r6, #0]
    ldr	r1, [r6, #56]	@ 0x38
    cmp	r1, #0
    bne .Leu_080353AC
    b .Leu_0803590C
.Leu_080353AC:
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #112]	@ 0x70
    cmp	r0, #0
    bne .Leu_080353C0
    b .Leu_0803590C
.Leu_080353C0:
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    str	r0, [sp, #176]	@ 0xb0
    ldr	r0, [sp, #112]	@ 0x70
    ldrh	r0, [r0, #0]
    cmp	r1, r0
    bcc .Leu_080353D2
    b .Leu_0803590C
.Leu_080353D2:
    lsls	r1, r1, #3
    ldr	r2, [sp, #112]	@ 0x70
    ldr	r0, [r2, #4]
    adds	r7, r0, r1
    ldr	r3, [r7, #4]
    str	r3, [sp, #116]	@ 0x74
    cmp	r3, #0
    bne .Leu_080353E4
    b .Leu_0803590C
.Leu_080353E4:
    ldr	r0, [r5, #0]
    movs	r4, #162	@ 0xa2
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r1, [r0, #0]
    adds	r0, r5, #0
    bl _call_via_r1
    ldrh	r3, [r0, #10]
    lsls	r0, r3, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Leu_08035402
    adds	r2, #24
.Leu_08035402:
    lsls	r1, r2, #4
    subs	r1, r1, r2
    lsls	r1, r1, #2
    lsls	r0, r3, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    movs	r0, #0
    str	r0, [sp, #120]	@ 0x78
    ldr	r2, [sp, #116]	@ 0x74
    ldr	r3, [r2, #0]
    cmp	r3, #0
    bne .Leu_0803541C
    b .Leu_080358D4
.Leu_0803541C:
    ldrh	r4, [r2, #4]
    cmp	r4, #0
    bne .Leu_08035424
    b .Leu_080358D4
.Leu_08035424:
    adds	r0, r6, #0
    adds	r0, #62	@ 0x3e
    ldrb	r2, [r0, #0]
    str	r0, [sp, #180]	@ 0xb4
    cmp	r2, r4
    bcc .Leu_08035432
    b .Leu_0803590C
.Leu_08035432:
    ldr	r4, [sp, #116]	@ 0x74
    ldrb	r0, [r4, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803543E
    b .Leu_0803564C
.Leu_0803543E:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #124]	@ 0x7c
    movs	r1, #0
    ldrb	r0, [r3, #4]
    lsls	r0, r0, #31
    cmp	r0, #0
    bne .Leu_08035450
    movs	r1, #1
.Leu_08035450:
    mov	r8, r1
    ldr	r0, [r6, #8]
    str	r0, [sp, #0]
    ldr	r0, [r6, #12]
    str	r0, [sp, #8]
    ldr	r0, [r6, #24]
    str	r0, [sp, #4]
    ldr	r0, [r6, #28]
    str	r0, [sp, #12]
    cmp	r1, #0
    beq .Leu_08035470
    mov	sl, sp
    mov	r7, sp
    adds	r7, #4
    str	r7, [sp, #128]	@ 0x80
    b .Leu_0803547A
.Leu_08035470:
    add	r0, sp, #8
    mov	sl, r0
    mov	r1, sp
    adds	r1, #12
    str	r1, [sp, #128]	@ 0x80
.Leu_0803547A:
    mov	r2, sl
    ldr	r1, [r2, #0]
    asrs	r3, r1, #16
    str	r3, [sp, #132]	@ 0x84
    ldr	r4, [sp, #128]	@ 0x80
    ldr	r0, [r4, #0]
    adds	r1, r1, r0
    str	r1, [sp, #136]	@ 0x88
    asrs	r7, r1, #16
    str	r7, [sp, #140]	@ 0x8c
    subs	r7, r7, r3
    movs	r3, #0
    adds	r0, r6, #0
    adds	r0, #64	@ 0x40
    ldrh	r2, [r0, #0]
    ldr r1, .Leu_080354C0
    str	r0, [sp, #184]	@ 0xb8
    cmp	r2, r1
    blt .Leu_080354A2
    movs	r3, #1
.Leu_080354A2:
    movs	r0, #1
    str	r0, [sp, #144]	@ 0x90
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Leu_080354D2
    movs	r4, #0
    str	r4, [sp, #144]	@ 0x90
    cmp	r3, #0
    beq .Leu_080354C4
    strb	r4, [r1, #0]
    b .Leu_080354C8
    .align 2, 0
.Leu_080354C0:
    .4byte 0x000002EE
.Leu_080354C4:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Leu_080354C8:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_080354D2
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Leu_080354D2:
    cmp	r3, #0
    bne .Leu_080355B4
    cmp	r7, #0
    beq .Leu_080355B4
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_080355B4
    ldrh	r0, [r4, #4]
    ldrh	r2, [r6, #4]
    cmp	r0, r2
    bne .Leu_080355B4
    ldr	r1, [r6, #20]
    add	r0, sp, #16
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #16]
    ldr	r1, [sp, #20]
    str	r0, [sp, #24]
    str	r1, [sp, #28]
    add	r5, sp, #24
    ldr	r1, [r4, #20]
    add	r0, sp, #32
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #32]
    ldr	r1, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    add	r4, sp, #40	@ 0x28
    mov	r3, r8
    cmp	r3, #0
    beq .Leu_0803552C
    adds	r2, r7, #0
    movs	r7, #0
    b .Leu_0803552E
.Leu_0803552C:
    movs	r2, #0
.Leu_0803552E:
    mov	r9, r7
    movs	r1, #0
    ldrsh	r0, [r5, r1]
    mov	ip, r0
    movs	r3, #4
    ldrsh	r1, [r4, r3]
    subs	r1, r0, r1
    movs	r7, #0
    ldrsh	r0, [r4, r7]
    movs	r7, #4
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    subs	r0, r0, r3
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Leu_080355B4
    add	r3, sp, #48	@ 0x30
    mov	r1, ip
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, r8
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Leu_080355B4
    movs	r5, #0
    str	r5, [sp, #144]	@ 0x90
.Leu_080355B4:
    ldr	r7, [sp, #144]	@ 0x90
    cmp	r7, #0
    beq .Leu_08035642
    ldr	r1, [sp, #124]	@ 0x7c
    movs	r2, #2
    ldrsh	r0, [r1, r2]
    ldr	r3, [sp, #132]	@ 0x84
    cmp	r3, r0
    beq .Leu_080355E4
    ldr	r4, [sp, #140]	@ 0x8c
    cmp	r4, r0
    beq .Leu_080355E4
    movs	r1, #0
    cmp	r0, r3
    bge .Leu_080355D4
    movs	r1, #1
.Leu_080355D4:
    ldr	r5, [sp, #140]	@ 0x8c
    cmp	r0, r5
    bge .Leu_080355E0
    cmp	r1, #0
    beq .Leu_080355E4
    b .Leu_0803562A
.Leu_080355E0:
    cmp	r1, #0
    beq .Leu_0803562A
.Leu_080355E4:
    lsls	r0, r0, #16
    mov	r7, sl
    str	r0, [r7, #0]
    movs	r1, #0
    ldr	r0, [sp, #128]	@ 0x80
    str	r1, [r0, #0]
    ldr	r2, [sp, #180]	@ 0xb4
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r3, [sp, #116]	@ 0x74
    ldrh	r3, [r3, #4]
    cmp	r0, r3
    bcs .Leu_0803560A
    movs	r4, #1
    str	r4, [sp, #120]	@ 0x78
    b .Leu_08035630
.Leu_0803560A:
    ldr	r5, [sp, #176]	@ 0xb0
    ldrb	r0, [r5, #0]
    adds	r0, #1
    ldr	r7, [sp, #112]	@ 0x70
    ldrh	r7, [r7, #0]
    cmp	r0, r7
    blt .Leu_0803561A
    b .Leu_0803590C
.Leu_0803561A:
    ldr	r0, [sp, #180]	@ 0xb4
    strb	r1, [r0, #0]
    ldrb	r0, [r5, #0]
    adds	r0, #1
    strb	r0, [r5, #0]
    movs	r1, #2
    str	r1, [sp, #120]	@ 0x78
    b .Leu_08035630
.Leu_0803562A:
    ldr	r2, [sp, #136]	@ 0x88
    mov	r3, sl
    str	r2, [r3, #0]
.Leu_08035630:
    ldr	r0, [sp, #0]
    str	r0, [r6, #8]
    ldr	r0, [sp, #8]
    str	r0, [r6, #12]
    ldr	r0, [sp, #4]
    str	r0, [r6, #24]
    ldr	r0, [sp, #12]
    str	r0, [r6, #28]
    b .Leu_080358FA
.Leu_08035642:
    ldr	r4, [sp, #184]	@ 0xb8
    ldrh	r0, [r4, #0]
    adds	r0, #1
    strh	r0, [r4, #0]
    b .Leu_080358FA
.Leu_0803564C:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #148]	@ 0x94
    movs	r2, #0
    ldrb	r0, [r3, #6]
    lsls	r0, r0, #29
    cmp	r0, #0
    blt .Leu_0803565E
    movs	r2, #1
.Leu_0803565E:
    mov	r8, r2
    movs	r2, #0
    ldr	r3, [sp, #176]	@ 0xb0
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldr	r4, [sp, #112]	@ 0x70
    ldrh	r4, [r4, #0]
    cmp	r0, r4
    bge .Leu_08035678
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Leu_08035678
    movs	r2, #1
.Leu_08035678:
    mov	sl, r2
    cmp	r2, #0
    beq .Leu_08035696
    ldrh	r4, [r6, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #20]
    adds	r0, r5, #0
    bl _call_via_r1
    cmp	r4, r0
    beq .Leu_08035696
    movs	r0, #0
    ldr	r5, [sp, #180]	@ 0xb4
    strb	r0, [r5, #0]
    b .Leu_080358C0
.Leu_08035696:
    adds	r1, r6, #0
    adds	r1, #64	@ 0x40
    ldrh	r0, [r1, #0]
    str	r1, [sp, #184]	@ 0xb8
    cmp	r0, #0
    beq .Leu_080356A4
    b .Leu_08035888
.Leu_080356A4:
    ldr	r0, [r6, #8]
    str	r0, [sp, #56]	@ 0x38
    ldr	r0, [r6, #12]
    str	r0, [sp, #64]	@ 0x40
    ldr	r0, [r6, #24]
    str	r0, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #28]
    str	r0, [sp, #68]	@ 0x44
    mov	r1, r8
    cmp	r1, #0
    beq .Leu_080356C8
    mov	r2, sp
    adds	r2, #56	@ 0x38
    str	r2, [sp, #152]	@ 0x98
    mov	r3, sp
    adds	r3, #60	@ 0x3c
    str	r3, [sp, #156]	@ 0x9c
    b .Leu_080356D4
.Leu_080356C8:
    mov	r4, sp
    adds	r4, #64	@ 0x40
    str	r4, [sp, #152]	@ 0x98
    mov	r7, sp
    adds	r7, #68	@ 0x44
    str	r7, [sp, #156]	@ 0x9c
.Leu_080356D4:
    ldr	r1, [sp, #152]	@ 0x98
    ldr	r0, [r1, #0]
    asrs	r2, r0, #16
    str	r2, [sp, #160]	@ 0xa0
    ldr	r3, [sp, #156]	@ 0x9c
    ldr	r1, [r3, #0]
    adds	r0, r0, r1
    str	r0, [sp, #164]	@ 0xa4
    asrs	r4, r0, #16
    str	r4, [sp, #168]	@ 0xa8
    subs	r7, r4, r2
    movs	r0, #1
    str	r0, [sp, #172]	@ 0xac
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Leu_08035716
    movs	r3, #0
    str	r3, [sp, #172]	@ 0xac
    mov	r4, sl
    cmp	r4, #0
    beq .Leu_08035708
    strb	r3, [r1, #0]
    b .Leu_0803570C
.Leu_08035708:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Leu_0803570C:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_08035716
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Leu_08035716:
    mov	r2, sl
    cmp	r2, #0
    bne .Leu_080357FC
    cmp	r7, #0
    beq .Leu_080357FC
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_080357FC
    ldrh	r0, [r4, #4]
    ldrh	r3, [r6, #4]
    cmp	r0, r3
    bne .Leu_080357FC
    ldr	r1, [r6, #20]
    add	r0, sp, #72	@ 0x48
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #72]	@ 0x48
    ldr	r1, [sp, #76]	@ 0x4c
    str	r0, [sp, #80]	@ 0x50
    str	r1, [sp, #84]	@ 0x54
    add	r5, sp, #80	@ 0x50
    ldr	r1, [r4, #20]
    add	r0, sp, #88	@ 0x58
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #96]	@ 0x60
    str	r1, [sp, #100]	@ 0x64
    add	r4, sp, #96	@ 0x60
    mov	r0, r8
    cmp	r0, #0
    beq .Leu_08035774
    adds	r2, r7, #0
    movs	r1, #0
    mov	r9, r1
    b .Leu_08035778
.Leu_08035774:
    movs	r2, #0
    mov	r9, r7
.Leu_08035778:
    movs	r7, #0
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    movs	r0, #4
    ldrsh	r1, [r4, r0]
    subs	r1, r3, r1
    movs	r3, #0
    ldrsh	r0, [r4, r3]
    movs	r3, #4
    ldrsh	r7, [r5, r3]
    mov	ip, r7
    subs	r0, r0, r7
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Leu_080357FC
    add	r3, sp, #104	@ 0x68
    mov	r1, r8
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, ip
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Leu_080357FC
    movs	r5, #0
    str	r5, [sp, #172]	@ 0xac
.Leu_080357FC:
    ldr	r7, [sp, #172]	@ 0xac
    cmp	r7, #0
    beq .Leu_080358FA
    ldr	r0, [sp, #148]	@ 0x94
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    ldr	r3, [sp, #168]	@ 0xa8
    cmp	r3, r2
    beq .Leu_0803581A
    ldr	r4, [sp, #160]	@ 0xa0
    subs	r0, r2, r4
    subs	r1, r2, r3
    eors	r0, r1
    cmp	r0, #0
    bge .Leu_08035870
.Leu_0803581A:
    lsls	r0, r2, #16
    ldr	r5, [sp, #152]	@ 0x98
    str	r0, [r5, #0]
    movs	r1, #0
    ldr	r7, [sp, #156]	@ 0x9c
    str	r1, [r7, #0]
    mov	r0, sl
    cmp	r0, #0
    bne .Leu_08035834
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r0, [r2, #4]
    cmp	r0, #0
    bne .Leu_08035864
.Leu_08035834:
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Leu_0803585E
    strb	r1, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Leu_08035858
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Leu_08035858:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Leu_08035876
.Leu_0803585E:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Leu_08035876
.Leu_08035864:
    movs	r0, #1
    ldr	r2, [sp, #184]	@ 0xb8
    strh	r0, [r2, #0]
    movs	r3, #1
    str	r3, [sp, #120]	@ 0x78
    b .Leu_08035876
.Leu_08035870:
    ldr	r4, [sp, #164]	@ 0xa4
    ldr	r5, [sp, #152]	@ 0x98
    str	r4, [r5, #0]
.Leu_08035876:
    ldr	r0, [sp, #56]	@ 0x38
    str	r0, [r6, #8]
    ldr	r0, [sp, #64]	@ 0x40
    str	r0, [r6, #12]
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [r6, #24]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [r6, #28]
    b .Leu_080358FA
.Leu_08035888:
    mov	r7, sl
    cmp	r7, #0
    bne .Leu_0803589E
    adds	r0, #1
    strh	r0, [r1, #0]
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r2, [r2, #4]
    cmp	r0, r2
    bls .Leu_080358FA
.Leu_0803589E:
    movs	r0, #0
    strh	r0, [r1, #0]
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Leu_080358CE
    movs	r0, #0
    strb	r0, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Leu_080358C8
.Leu_080358C0:
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Leu_080358C8:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Leu_08035900
.Leu_080358CE:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Leu_08035900
.Leu_080358D4:
    ldr	r2, [sp, #176]	@ 0xb0
    ldrb	r0, [r2, #0]
    adds	r0, #1
    ldr	r3, [sp, #112]	@ 0x70
    ldrh	r3, [r3, #0]
    cmp	r0, r3
    bge .Leu_080358FA
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Leu_080358FA
    adds	r1, r6, #0
    adds	r1, #62	@ 0x3e
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    movs	r4, #2
    str	r4, [sp, #120]	@ 0x78
.Leu_080358FA:
    ldr	r5, [sp, #120]	@ 0x78
    cmp	r5, #0
    ble .Leu_0803590C
.Leu_08035900:
    ldr	r0, [r6, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r6, #0
    ldr	r1, [sp, #120]	@ 0x78
    bl _call_via_r2
.Leu_0803590C:
    add	sp, #188	@ 0xbc
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08035908
    .thumb_func
func_08035908:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #68	@ 0x44
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Leu_0803594E
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803594E
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Leu_0803594E
    cmp	r0, r5
    beq .Leu_0803594E
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Leu_0803594E:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035940
    .thumb_func
func_08035940:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #70	@ 0x46
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Leu_08035986
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08035986
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Leu_08035986
    cmp	r0, r5
    beq .Leu_08035986
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Leu_08035986:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035978
    .thumb_func
func_08035978:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08035A4E
    ldr	r1, [r4, #56]	@ 0x38
    cmp	r1, #0
    beq .Leu_08035A4E
    adds	r0, r4, #0
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r6, [r0, #0]
    cmp	r6, #0
    beq .Leu_08035A4E
    adds	r0, r4, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    mov	r8, r0
    ldrh	r0, [r6, #0]
    cmp	r1, r0
    bcs .Leu_08035A4E
    lsls	r1, r1, #3
    ldr	r0, [r6, #4]
    adds	r7, r0, r1
    ldr	r5, [r7, #4]
    cmp	r5, #0
    beq .Leu_08035A4E
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r1, [r0, #10]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Leu_080359F4
    adds	r2, #24
.Leu_080359F4:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r1, r0, r1
    ldr	r0, [r5, #0]
    cmp	r0, #0
    beq .Leu_08035A34
    ldrh	r2, [r5, #4]
    cmp	r2, #0
    beq .Leu_08035A34
    adds	r0, r4, #0
    adds	r0, #62	@ 0x3e
    ldrb	r0, [r0, #0]
    cmp	r0, r2
    bcs .Leu_08035A4E
    ldrb	r0, [r5, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Leu_08035A34
    movs	r2, #0
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    ldrh	r1, [r0, #0]
    ldr r0, .Leu_08035A30
    cmp	r1, r0
    blt .Leu_08035A4A
    b .Leu_08035A48
    .align 2, 0
.Leu_08035A30:
    .4byte 0x000002EE
.Leu_08035A34:
    movs	r2, #0
    mov	r3, r8
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldrh	r6, [r6, #0]
    cmp	r0, r6
    bge .Leu_08035A4A
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Leu_08035A4A
.Leu_08035A48:
    movs	r2, #1
.Leu_08035A4A:
    adds	r0, r2, #0
    b .Leu_08035A50
.Leu_08035A4E:
    movs	r0, #0
.Leu_08035A50:
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    movs	r0, r0
    .global func_08035A48
    .thumb_func
func_08035A48:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r3, r1, #0
    ldrh	r1, [r4, #4]
    ldrh	r0, [r3, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r1, r0
    bne .Leu_08035AEA
    movs	r0, #10
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #2]
    ldr r5, .Leu_08035AF0
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Leu_08035A8C
    negs	r0, r0
.Leu_08035A8C:
    cmp	r0, #151	@ 0x97
    bgt .Leu_08035AEA
    movs	r0, #14
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #4]
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Leu_08035AAC
    negs	r0, r0
.Leu_08035AAC:
    cmp	r0, #111	@ 0x6f
    bgt .Leu_08035AEA
    adds	r0, r4, #0
    bl func_08035978
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08035AEA
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08035AEA
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r1, r4, #0
    adds	r1, #63	@ 0x3f
    movs	r0, #120	@ 0x78
    strb	r0, [r1, #0]
    ldr	r0, [r4, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    movs	r1, #1
    bl _call_via_r2
.Leu_08035AEA:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Leu_08035AF0:
    .4byte 0x000003FF
    .global func_08035AE0
    .thumb_func
func_08035AE0:
    push	{lr}
    adds	r1, r0, #0
    movs	r2, #0
    ldrh	r0, [r1, #4]
    cmp	r0, #29
    bne .Leu_08035B0A
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    cmp	r0, #55	@ 0x37
    bgt .Leu_08035B0A
    movs	r2, #1
.Leu_08035B0A:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .global func_08035AFC
    .thumb_func
func_08035AFC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035B3C
    str	r0, [sp, #0]
    ldr r0, .Leu_08035B40
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035B44
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035B48
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035B3C:
    .4byte gUnk_080F280C
.Leu_08035B40:
    .4byte 0x0000025F
.Leu_08035B44:
    .4byte 0x000003E2
.Leu_08035B48:
    .4byte vtable_unk_080E7198
    .global func_08035B38
    .thumb_func
func_08035B38:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035B64
    .thumb_func
func_08035B64:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035BA4
    str	r0, [sp, #0]
    ldr r0, .Leu_08035BA8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #248	@ 0xf8
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035BAC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08035BA4:
    .4byte ScheduleInfo_Unk_080F1A80
.Leu_08035BA8:
    .4byte 0x00000213
.Leu_08035BAC:
    .4byte vtable_unk_080E7158
    .global func_08035B9C
    .thumb_func
func_08035B9C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035BC8
    .thumb_func
func_08035BC8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035C08
    str	r0, [sp, #0]
    ldr r0, .Leu_08035C0C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035C10
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035C14
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035C08:
    .4byte gUnk_080F1FC0
.Leu_08035C0C:
    .4byte 0x0000022F
.Leu_08035C10:
    .4byte 0x000003E1
.Leu_08035C14:
    .4byte vtable_unk_080E7118
    .global func_08035C04
    .thumb_func
func_08035C04:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Leu_08035C5C
    ldr r0, .Leu_08035C60
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Leu_08035C64
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #3
    bne .Leu_08035CA8
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Leu_08035CA8
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08035C56
    ldr r2, .Leu_08035C68
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_08035C70
.Leu_08035C56:
    ldr r7, .Leu_08035C6C
    b .Leu_08035CA8
    .align 2, 0
.Leu_08035C5C:
    .4byte 0x0000022F
.Leu_08035C60:
    .4byte 0x00000233
.Leu_08035C64:
    .4byte 0x00001CD4
.Leu_08035C68:
    .4byte 0x0000216B
.Leu_08035C6C:
    .4byte 0x0000023F
.Leu_08035C70:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_08035CA8
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_08035CA8
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08035CA8
    ldr r7, .Leu_08035CC4
    ldr r0, .Leu_08035CC8
    mov	r8, r0
.Leu_08035CA8:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08035CC4:
    .4byte 0x00000247
.Leu_08035CC8:
    .4byte 0x0000024B
    .global func_08035CB8
    .thumb_func
func_08035CB8:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_08035CE0
    adds	r0, r5, #0
    bl func_08035C04
.Leu_08035CE0:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08035CD4
    .thumb_func
func_08035CD4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08035C04
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035D04
    .thumb_func
func_08035D04:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035D44
    str	r0, [sp, #0]
    ldr r0, .Leu_08035D48
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035D4C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035D50
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035D44:
    .4byte gUnk_080F8678
.Leu_08035D48:
    .4byte 0x000009EF
.Leu_08035D4C:
    .4byte 0x00000406
.Leu_08035D50:
    .4byte vtable_unk_080E70D8
    .global func_08035D40
    .thumb_func
func_08035D40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #3
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035D70
    .thumb_func
func_08035D70:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035DB0
    str	r0, [sp, #0]
    ldr r0, .Leu_08035DB4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035DB8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035DBC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035DB0:
    .4byte gUnk_080F81BC
.Leu_08035DB4:
    .4byte 0x000009E7
.Leu_08035DB8:
    .4byte 0x00000405
.Leu_08035DBC:
    .4byte vtable_unk_080E7098
    .global func_08035DAC
    .thumb_func
func_08035DAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035DD8
    .thumb_func
func_08035DD8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035E18
    str	r0, [sp, #0]
    ldr r0, .Leu_08035E1C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035E20
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035E24
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035E18:
    .4byte gUnk_080F77FC
.Leu_08035E1C:
    .4byte 0x000009A1
.Leu_08035E20:
    .4byte 0x00000403
.Leu_08035E24:
    .4byte vtable_unk_080E7058
    .global func_08035E14
    .thumb_func
func_08035E14:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035E40
    .thumb_func
func_08035E40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035E80
    str	r0, [sp, #0]
    ldr r0, .Leu_08035E84
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035E88
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035E8C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035E80:
    .4byte gUnk_080F7294
.Leu_08035E84:
    .4byte 0x00000989
.Leu_08035E88:
    .4byte 0x00000402
.Leu_08035E8C:
    .4byte vtable_unk_080E7018
    .global func_08035E7C
    .thumb_func
func_08035E7C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035EAC
    .thumb_func
func_08035EAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035EF0
    str	r0, [sp, #0]
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035EF4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035EF0:
    .4byte gUnk_080F6370
.Leu_08035EF4:
    .4byte vtable_unk_080E6FD8
    .global func_08035EE4
    .thumb_func
func_08035EE4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F10
    .thumb_func
func_08035F10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035F50
    str	r0, [sp, #0]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035F54
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035F58
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08035F50:
    .4byte gUnk_080F66C4
.Leu_08035F54:
    .4byte 0x000003FD
.Leu_08035F58:
    .4byte vtable_unk_080E6F98
    .global func_08035F48
    .thumb_func
func_08035F48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F74
    .thumb_func
func_08035F74:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08035FB4
    str	r0, [sp, #0]
    ldr r0, .Leu_08035FB8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08035FBC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08035FC0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08035FB4:
    .4byte gUnk_080F49C0
.Leu_08035FB8:
    .4byte 0x0000080B
.Leu_08035FBC:
    .4byte 0x000003F5
.Leu_08035FC0:
    .4byte vtable_unk_080E6F58
    .global func_08035FB0
    .thumb_func
func_08035FB0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035FE0
    .thumb_func
func_08035FE0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036020
    str	r0, [sp, #0]
    ldr r0, .Leu_08036024
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036028
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_0803602C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036020:
    .4byte gUnk_080F5540
.Leu_08036024:
    .4byte 0x0000084B
.Leu_08036028:
    .4byte 0x000003F7
.Leu_0803602C:
    .4byte vtable_unk_080E6F18
    .global func_0803601C
    .thumb_func
func_0803601C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036048
    .thumb_func
func_08036048:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036088
    str	r0, [sp, #0]
    ldr r0, .Leu_0803608C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036090
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036094
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036088:
    .4byte gUnk_080F4D74
.Leu_0803608C:
    .4byte 0x00000813
.Leu_08036090:
    .4byte 0x000003F6
.Leu_08036094:
    .4byte vtable_unk_080E6ED8
    .global func_08036084
    .thumb_func
func_08036084:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Leu_080360DC
    ldr r0, .Leu_080360E0
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Leu_080360E4
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #12
    bne .Leu_08036128
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Leu_08036128
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_080360D6
    ldr r2, .Leu_080360E8
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_080360F0
.Leu_080360D6:
    ldr r7, .Leu_080360EC
    b .Leu_08036128
    .align 2, 0
.Leu_080360DC:
    .4byte 0x00000813
.Leu_080360E0:
    .4byte 0x00000817
.Leu_080360E4:
    .4byte 0x00001CD4
.Leu_080360E8:
    .4byte 0x0000216C
.Leu_080360EC:
    .4byte 0x00000827
.Leu_080360F0:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_08036128
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_08036128
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08036128
    ldr r7, .Leu_08036144
    ldr r0, .Leu_08036148
    mov	r8, r0
.Leu_08036128:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08036144:
    .4byte 0x0000082F
.Leu_08036148:
    .4byte 0x00000833
    .global func_08036138
    .thumb_func
func_08036138:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_08036160
    adds	r0, r5, #0
    bl func_08036084
.Leu_08036160:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036154
    .thumb_func
func_08036154:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036084
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036184
    .thumb_func
func_08036184:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_080361C4
    str	r0, [sp, #0]
    ldr r0, .Leu_080361C8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_080361CC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_080361D0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080361C4:
    .4byte gUnk_080F59CC
.Leu_080361C8:
    .4byte 0x0000085F
.Leu_080361CC:
    .4byte 0x000003F9
.Leu_080361D0:
    .4byte vtable_unk_080E6E98
    .global func_080361C0
    .thumb_func
func_080361C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080361EC
    .thumb_func
func_080361EC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_0803622C
    str	r0, [sp, #0]
    ldr r0, .Leu_08036230
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036234
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036238
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803622C:
    .4byte gUnk_080F6B4C
.Leu_08036230:
    .4byte 0x000008E4
.Leu_08036234:
    .4byte 0x000003FF
.Leu_08036238:
    .4byte vtable_unk_080E6E58
    .global func_08036228
    .thumb_func
func_08036228:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036258
    .thumb_func
func_08036258:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036294
    str	r0, [sp, #0]
    ldr r0, .Leu_08036298
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    ldr r0, .Leu_0803629C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_080362A0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036294:
    .4byte gUnk_080F33B8
.Leu_08036298:
    .4byte 0x00000685
.Leu_0803629C:
    .4byte 0x000003EE
.Leu_080362A0:
    .4byte vtable_unk_080E6E18
    .global func_08036290
    .thumb_func
func_08036290:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080362C0
    .thumb_func
func_080362C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036300
    str	r0, [sp, #0]
    ldr r0, .Leu_08036304
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036308
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_0803630C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036300:
    .4byte gUnk_080F61FC
.Leu_08036304:
    .4byte 0x000008B8
.Leu_08036308:
    .4byte 0x000003FB
.Leu_0803630C:
    .4byte vtable_unk_080E6DD8
    .global func_080362FC
    .thumb_func
func_080362FC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036328
    .thumb_func
func_08036328:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036368
    str	r0, [sp, #0]
    ldr r0, .Leu_0803636C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036370
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036374
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036368:
    .4byte gUnk_080F3408
.Leu_0803636C:
    .4byte 0x00000689
.Leu_08036370:
    .4byte 0x000003EF
.Leu_08036374:
    .4byte vtable_unk_080E6D98
    .global func_08036364
    .thumb_func
func_08036364:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036390
    .thumb_func
func_08036390:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_080363D0
    str	r0, [sp, #0]
    ldr r0, .Leu_080363D4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_080363D8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_080363DC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080363D0:
    .4byte gUnk_080F3FD8
.Leu_080363D4:
    .4byte 0x000006C5
.Leu_080363D8:
    .4byte 0x000003F1
.Leu_080363DC:
    .4byte vtable_unk_080E6D58
    .global func_080363CC
    .thumb_func
func_080363CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080363F8
    .thumb_func
func_080363F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036438
    str	r0, [sp, #0]
    ldr r0, .Leu_0803643C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #252	@ 0xfc
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036440
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036438:
    .4byte gUnk_080F35E4
.Leu_0803643C:
    .4byte 0x00000691
.Leu_08036440:
    .4byte vtable_unk_080E6D18
    .global func_08036430
    .thumb_func
func_08036430:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Leu_08036488
    ldr r0, .Leu_0803648C
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Leu_08036490
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #19
    bne .Leu_080364D4
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Leu_080364D4
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08036482
    ldr r2, .Leu_08036494
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803649C
.Leu_08036482:
    ldr r7, .Leu_08036498
    b .Leu_080364D4
    .align 2, 0
.Leu_08036488:
    .4byte 0x00000691
.Leu_0803648C:
    .4byte 0x00000695
.Leu_08036490:
    .4byte 0x00001CD4
.Leu_08036494:
    .4byte 0x0000216C
.Leu_08036498:
    .4byte 0x000006A1
.Leu_0803649C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_080364D4
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_080364D4
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_080364D4
    ldr r7, .Leu_080364F0
    ldr r0, .Leu_080364F4
    mov	r8, r0
.Leu_080364D4:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_080364F0:
    .4byte 0x000006AD
.Leu_080364F4:
    .4byte 0x000006B1
    .global func_080364E4
    .thumb_func
func_080364E4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_0803650C
    adds	r0, r5, #0
    bl func_08036430
.Leu_0803650C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036500
    .thumb_func
func_08036500:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036430
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036530
    .thumb_func
func_08036530:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036570
    str	r0, [sp, #0]
    movs	r0, #200	@ 0xc8
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #194	@ 0xc2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036574
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036570:
    .4byte gUnk_080F3010
.Leu_08036574:
    .4byte vtable_unk_080E6CD8
    .global func_08036564
    .thumb_func
func_08036564:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036590
    .thumb_func
func_08036590:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_080365D0
    str	r0, [sp, #0]
    ldr r0, .Leu_080365D4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_080365D8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_080365DC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080365D0:
    .4byte gUnk_080F5D94
.Leu_080365D4:
    .4byte 0x00000884
.Leu_080365D8:
    .4byte 0x000003FA
.Leu_080365DC:
    .4byte vtable_unk_080E6C98
    .global func_080365CC
    .thumb_func
func_080365CC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Leu_08036624
    ldr r0, .Leu_08036628
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Leu_0803662C
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #21
    bne .Leu_08036670
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Leu_08036670
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803661E
    ldr r2, .Leu_08036630
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_08036638
.Leu_0803661E:
    ldr r7, .Leu_08036634
    b .Leu_08036670
    .align 2, 0
.Leu_08036624:
    .4byte 0x00000884
.Leu_08036628:
    .4byte 0x00000888
.Leu_0803662C:
    .4byte 0x00001CD4
.Leu_08036630:
    .4byte 0x0000216C
.Leu_08036634:
    .4byte 0x0000089C
.Leu_08036638:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_08036670
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_08036670
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08036670
    ldr r7, .Leu_0803668C
    ldr r0, .Leu_08036690
    mov	r8, r0
.Leu_08036670:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_0803668C:
    .4byte 0x00000894
.Leu_08036690:
    .4byte 0x00000898
    .global func_08036680
    .thumb_func
func_08036680:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_080366A8
    adds	r0, r5, #0
    bl func_080365CC
.Leu_080366A8:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803669C
    .thumb_func
func_0803669C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_080365CC
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080366CC
    .thumb_func
func_080366CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_0803670C
    str	r0, [sp, #0]
    ldr r0, .Leu_08036710
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #3
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036714
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_0803670C:
    .4byte gUnk_080F6DE8
.Leu_08036710:
    .4byte 0x000008EC
.Leu_08036714:
    .4byte vtable_unk_080E6C58
    .global func_08036704
    .thumb_func
func_08036704:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036730
    .thumb_func
func_08036730:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036770
    str	r0, [sp, #0]
    ldr r0, .Leu_08036774
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #249	@ 0xf9
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036778
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036770:
    .4byte gUnk_080F2AF8
.Leu_08036774:
    .4byte 0x0000027B
.Leu_08036778:
    .4byte vtable_unk_080E6C18
    .global func_08036768
    .thumb_func
func_08036768:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Leu_080367B4
    movs	r5, #2
    ldr	r0, [r4, #52]	@ 0x34
    ldr r2, .Leu_080367B8
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_08036798
    adds	r1, #24
    movs	r5, #1
.Leu_08036798:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    ldr r1, .Leu_080367BC
    bl func_08035940
    adds	r0, r4, #0
    adds	r0, #33	@ 0x21
    strb	r5, [r0, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_080367B4:
    .4byte 0x0000027B
.Leu_080367B8:
    .4byte 0x00002181
.Leu_080367BC:
    .4byte 0x0000027F
    .global func_080367AC
    .thumb_func
func_080367AC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_080367D4
    adds	r0, r5, #0
    bl func_08036768
.Leu_080367D4:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080367C8
    .thumb_func
func_080367C8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036768
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080367F8
    .thumb_func
func_080367F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036838
    str	r0, [sp, #0]
    ldr r0, .Leu_0803683C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036840
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036844
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036838:
    .4byte gUnk_080F42F0
.Leu_0803683C:
    .4byte 0x000007B2
.Leu_08036840:
    .4byte 0x000003F2
.Leu_08036844:
    .4byte vtable_unk_080E6BD8
    .global func_08036834
    .thumb_func
func_08036834:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036860
    .thumb_func
func_08036860:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_080368A0
    str	r0, [sp, #0]
    ldr r0, .Leu_080368A4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #253	@ 0xfd
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_080368A8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_080368A0:
    .4byte gUnk_080F4974
.Leu_080368A4:
    .4byte 0x000007F2
.Leu_080368A8:
    .4byte vtable_unk_080E6B98
    .global func_08036898
    .thumb_func
func_08036898:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080368C4
    .thumb_func
func_080368C4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036904
    str	r0, [sp, #0]
    ldr r0, .Leu_08036908
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_0803690C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036910
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036904:
    .4byte gUnk_080F43DC
.Leu_08036908:
    .4byte 0x000007BE
.Leu_0803690C:
    .4byte 0x000003F3
.Leu_08036910:
    .4byte vtable_unk_080E6B58
    .global func_08036900
    .thumb_func
func_08036900:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Leu_08036964
    ldr r0, .Leu_08036968
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Leu_0803696C
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #25
    bne .Leu_080369B4
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Leu_080369B4
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803695E
    ldr r2, .Leu_08036970
    adds	r0, r5, r2
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    ldr r1, .Leu_08036974
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Leu_0803697C
.Leu_0803695E:
    ldr r7, .Leu_08036978
    b .Leu_080369B4
    .align 2, 0
.Leu_08036964:
    .4byte 0x000007BE
.Leu_08036968:
    .4byte 0x000007C2
.Leu_0803696C:
    .4byte 0x00001CD4
.Leu_08036970:
    .4byte 0x0000216B
.Leu_08036974:
    .4byte 0x0000216C
.Leu_08036978:
    .4byte 0x000007D2
.Leu_0803697C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_080369B4
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_080369B4
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_080369B4
    ldr r7, .Leu_080369D0
    ldr r0, .Leu_080369D4
    mov	r8, r0
.Leu_080369B4:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_080369D0:
    .4byte 0x000007CA
.Leu_080369D4:
    .4byte 0x000007CE
    .global func_080369C4
    .thumb_func
func_080369C4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_080369EC
    adds	r0, r5, #0
    bl func_08036900
.Leu_080369EC:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080369E0
    .thumb_func
func_080369E0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036900
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A10
    .thumb_func
func_08036A10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036A50
    str	r0, [sp, #0]
    ldr r0, .Leu_08036A54
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036A58
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036A5C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036A50:
    .4byte gUnk_080F6FF8
.Leu_08036A54:
    .4byte 0x00000902
.Leu_08036A58:
    .4byte 0x00000401
.Leu_08036A5C:
    .4byte vtable_unk_080E6B18
    .global func_08036A4C
    .thumb_func
func_08036A4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A78
    .thumb_func
func_08036A78:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036AB8
    str	r0, [sp, #0]
    ldr r0, .Leu_08036ABC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036AC0
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036AC4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036AB8:
    .4byte gUnk_080F7B40
.Leu_08036ABC:
    .4byte 0x000009D3
.Leu_08036AC0:
    .4byte 0x00000404
.Leu_08036AC4:
    .4byte vtable_unk_080E6AD8
    .global func_08036AB4
    .thumb_func
func_08036AB4:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Leu_08036AE4
    ldr r5, .Leu_08036AE8
    ldrh	r0, [r4, #4]
    adds	r2, r0, #0
    cmp	r0, #17
    beq .Leu_08036AF4
    cmp	r0, #17
    bgt .Leu_08036AEC
    cmp	r0, #7
    beq .Leu_08036AF4
    b .Leu_08036AF8
    .align 2, 0
.Leu_08036AE4:
    .4byte 0x000009D3
.Leu_08036AE8:
    .4byte 0x000009D7
.Leu_08036AEC:
    cmp	r2, #29
    beq .Leu_08036AF4
    cmp	r2, #37	@ 0x25
    bne .Leu_08036AF8
.Leu_08036AF4:
    ldr r1, .Leu_08036B0C
    ldr r5, .Leu_08036B10
.Leu_08036AF8:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035940
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Leu_08036B0C:
    .4byte 0x000009DF
.Leu_08036B10:
    .4byte 0x000009E3
    .global func_08036B00
    .thumb_func
func_08036B00:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_08036B28
    adds	r0, r5, #0
    bl func_08036AB4
.Leu_08036B28:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036B1C
    .thumb_func
func_08036B1C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036AB4
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036B4C
    .thumb_func
func_08036B4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036B8C
    str	r0, [sp, #0]
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #201	@ 0xc9
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036B90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036B8C:
    .4byte gUnk_080F2DC0
.Leu_08036B90:
    .4byte vtable_unk_080E6A98
    .global func_08036B80
    .thumb_func
func_08036B80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036BB0
    .thumb_func
func_08036BB0:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    movs	r0, #10
    ldrsh	r5, [r4, r0]
    movs	r2, #14
    ldrsh	r6, [r4, r2]
    adds	r0, r4, #0
    bl func_08034EB4
    ldrh	r0, [r4, #4]
    cmp	r0, #2
    bne .Leu_08036C04
    cmp	r5, #244	@ 0xf4
    bne .Leu_08036BE4
    cmp	r6, #171	@ 0xab
    beq .Leu_08036C04
.Leu_08036BE4:
    movs	r1, #10
    ldrsh	r0, [r4, r1]
    movs	r2, #14
    ldrsh	r1, [r4, r2]
    cmp	r0, #244	@ 0xf4
    bne .Leu_08036C04
    cmp	r1, #171	@ 0xab
    bne .Leu_08036C04
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Leu_08036C04:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036BF8
    .thumb_func
func_08036BF8:
    push	{r4, r5, r6, r7, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    movs	r0, #10
    ldrsh	r6, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_08036C54
    ldrh	r0, [r5, #4]
    cmp	r0, #2
    bne .Leu_08036C54
    cmp	r6, #244	@ 0xf4
    bne .Leu_08036C34
    cmp	r7, #171	@ 0xab
    beq .Leu_08036C54
.Leu_08036C34:
    movs	r2, #10
    ldrsh	r0, [r5, r2]
    movs	r2, #14
    ldrsh	r1, [r5, r2]
    cmp	r0, #244	@ 0xf4
    bne .Leu_08036C54
    cmp	r1, #171	@ 0xab
    bne .Leu_08036C54
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Leu_08036C54:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036C48
    .thumb_func
func_08036C48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036C88
    str	r0, [sp, #0]
    ldr r0, .Leu_08036C8C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #254	@ 0xfe
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036C90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08036C88:
    .4byte gUnk_080F597C
.Leu_08036C8C:
    .4byte 0x00000857
.Leu_08036C90:
    .4byte vtable_unk_080E6A58
    .global func_08036C80
    .thumb_func
func_08036C80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036CAC
    .thumb_func
func_08036CAC:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Leu_08036CE8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036CEC
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Leu_08036CE8:
    .4byte 0x00000679
.Leu_08036CEC:
    .4byte vtable_unk_080E6A18
    .global func_08036CDC
    .thumb_func
func_08036CDC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036D0C
    .thumb_func
func_08036D0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Leu_08036D48
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036D4C
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Leu_08036D48:
    .4byte 0x00000669
.Leu_08036D4C:
    .4byte vtable_unk_080E69D8
    .global func_08036D3C
    .thumb_func
func_08036D3C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036D68
    .thumb_func
func_08036D68:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Leu_08036DA4
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036DA8
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036DA4:
    .4byte 0x000007FE
.Leu_08036DA8:
    .4byte vtable_unk_080E6998
    .global func_08036D98
    .thumb_func
func_08036D98:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036DC4
    .thumb_func
func_08036DC4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036E04
    str	r0, [sp, #0]
    ldr r0, .Leu_08036E08
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Leu_08036E0C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036E10
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036E04:
    .4byte gUnk_080F6B10
.Leu_08036E08:
    .4byte 0x000008D8
.Leu_08036E0C:
    .4byte 0x000003FE
.Leu_08036E10:
    .4byte vtable_unk_080E6958
    .global func_08036E00
    .thumb_func
func_08036E00:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036E2C
    .thumb_func
func_08036E2C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Leu_08036E74
    str	r0, [sp, #0]
    ldr r0, .Leu_08036E78
    str	r0, [sp, #4]
    adds	r0, #8
    str	r0, [sp, #8]
    ldr r0, .Leu_08036E7C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Leu_08036E80
    str	r0, [r4, #20]
    adds	r1, r4, #0
    adds	r1, #72	@ 0x48
    movs	r0, #0
    strh	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08036E74:
    .4byte gUnk_080F29C0
.Leu_08036E78:
    .4byte 0x00000267
.Leu_08036E7C:
    .4byte 0x000003E3
.Leu_08036E80:
    .4byte vtable_unk_080E6918
    .global func_08036E70
    .thumb_func
func_08036E70:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Leu_08036EB4
    adds	r0, r0, r1
    bl func_080A0384
    adds	r6, r0, #0
    cmp	r0, #0
    beq .Leu_08036EF4
    ldr r5, .Leu_08036EB8
    ldr r7, .Leu_08036EBC
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_08036EC0
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08036EE4
    movs	r5, #12
    b .Leu_08036EE4
.Leu_08036EB4:
    .4byte 0x00001CD4
.Leu_08036EB8:
    .4byte 0x00000267
.Leu_08036EBC:
    .4byte 0x0000026F
.Leu_08036EC0:
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08036ED4
    ldr r5, .Leu_08036ED0
    b .Leu_08036EE4
.Leu_08036ED0:
    .4byte 0x00000277
.Leu_08036ED4:
    adds	r0, r6, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08036EE4
    ldr r5, .Leu_08036EFC
    ldr r7, .Leu_08036F00
.Leu_08036EE4:
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035940
.Leu_08036EF4:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08036EFC:
    .4byte 0x0000026B
.Leu_08036F00:
    .4byte 0x00000273
    .global func_08036EF0
    .thumb_func
func_08036EF0:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Leu_08036F18
    adds	r0, r5, #0
    bl func_08036E70
.Leu_08036F18:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036F0C
    .thumb_func
func_08036F0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    ldr r1, .Leu_08036F6C
    adds	r0, r0, r1
    bl func_080A0384
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_08036F70
    adds	r0, r5, #0
    bl func_08036E70
    adds	r0, r4, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    movs	r4, #1
    cmp	r0, #0
    beq .Leu_08036F4C
    movs	r4, #4
.Leu_08036F4C:
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r5, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    b .Leu_08036F72
    .align 2, 0
.Leu_08036F6C:
    .4byte 0x00001CD4
.Leu_08036F70:
    movs	r0, #0
.Leu_08036F72:
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036F68
    .thumb_func
func_08036F68:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r6, r1, #0
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Leu_08037006
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Leu_08036FBC
    adds	r0, r0, r1
    bl func_080A0384
    cmp	r0, #0
    beq .Leu_08037006
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Leu_08037006
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08037006
    adds	r0, r4, #0
    adds	r0, #72	@ 0x48
    ldrh	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Leu_08036FC0
    subs	r0, r1, #1
    b .Leu_08037004
.Leu_08036FBC:
    .4byte 0x00001CD4
.Leu_08036FC0:
    mov	r1, sp
    ldr r0, .Leu_08036FDC
    ldmia	r0!, {r2, r3, r7}
    stmia	r1!, {r2, r3, r7}
    ldr	r0, [r0, #0]
    str	r0, [r1, #0]
    bl rand
    movs	r1, #100	@ 0x64
    bl __modsi3
    movs	r3, #0
    mov	r2, sp
    b .Leu_08036FE6
.Leu_08036FDC:
    .4byte gUnk_080F1514
.Leu_08036FE0:
    subs	r0, r0, r1
    adds	r2, #4
    adds	r3, #1
.Leu_08036FE6:
    cmp	r3, #3
    bhi .Leu_08036FF8
    ldrb	r1, [r2, #0]
    cmp	r0, r1
    bcs .Leu_08036FE0
    ldrh	r1, [r2, #2]
    adds	r0, r4, #0
    bl func_08035908
.Leu_08036FF8:
    bl rand
    movs	r1, #120	@ 0x78
    bl __modsi3
    adds	r0, #120	@ 0x78
.Leu_08037004:
    strh	r0, [r5, #0]
.Leu_08037006:
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_08034EB4
    add	sp, #16
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x47706B40
    .global func_08037008
    .thumb_func
func_08037008:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r4, r0, #0
    adds	r5, r2, #0
    ldr	r6, [sp, #20]
    str	r3, [sp, #0]
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Leu_08037058
    str	r0, [r4, #20]
    str	r5, [r4, #48]	@ 0x30
    adds	r1, r4, #0
    adds	r1, #52	@ 0x34
    movs	r0, #0
    strh	r0, [r4, #52]	@ 0x34
    strh	r0, [r1, #2]
    strh	r0, [r1, #4]
    strh	r0, [r1, #6]
    strh	r6, [r4, #60]	@ 0x3c
    strh	r0, [r4, #62]	@ 0x3e
    adds	r1, #12
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08037058:
    .4byte vtable_unk_080E7328
    .global func_08037048
    .thumb_func
func_08037048:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Leu_080370A4
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldr r0, .Leu_080370A8
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_0803708E
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_0803708E:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Leu_0803709C
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_0803709C:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Leu_080370A4:
    .4byte vtable_unk_080E7328
.Leu_080370A8:
    .4byte __vt_7AEntity
    .global func_08037098
    .thumb_func
func_08037098:
    push	{r4, r5, lr}
    adds	r3, r0, #0
    movs	r4, #0
    movs	r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r0, #0
    cmp	r0, #1
    beq .Leu_080370D6
    cmp	r0, #1
    bgt .Leu_080370C8
    cmp	r0, #0
    beq .Leu_080370D2
    b .Leu_080370E0
.Leu_080370C8:
    cmp	r2, #2
    beq .Leu_080370DA
    cmp	r2, #3
    beq .Leu_080370DE
    b .Leu_080370E0
.Leu_080370D2:
    adds	r5, r1, #0
    b .Leu_080370E0
.Leu_080370D6:
    negs	r5, r1
    b .Leu_080370E0
.Leu_080370DA:
    negs	r4, r1
    b .Leu_080370E0
.Leu_080370DE:
    adds	r4, r1, #0
.Leu_080370E0:
    str	r4, [r3, #24]
    str	r5, [r3, #28]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_08037122
    movs	r4, #0
    adds	r2, r0, #0
    adds	r2, #48	@ 0x30
    movs	r1, #0
    ldrh	r0, [r2, #14]
    cmp	r0, #0
    beq .Leu_0803710C
    movs	r0, #16
    ldrsh	r1, [r2, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r1, r0, #31
.Leu_0803710C:
    cmp	r1, #0
    beq .Leu_0803711C
    adds	r0, r2, #0
    bl func_0805E894
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803711E
.Leu_0803711C:
    movs	r4, #1
.Leu_0803711E:
    adds	r0, r4, #0
    b .Leu_08037124
.Leu_08037122:
    movs	r0, #1
.Leu_08037124:
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037118
    .thumb_func
func_08037118:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r7, r0, #0
    adds	r4, r1, #0
    ldr	r1, [r7, #8]
    ldr	r2, [r7, #12]
    ldr	r0, [r7, #24]
    adds	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r7, #28]
    adds	r0, r0, r2
    mov	r8, r0
    asrs	r1, r1, #16
    str	r1, [sp, #0]
    asrs	r6, r2, #16
    asrs	r0, r0, #16
    subs	r5, r0, r6
    mov	r1, r9
    asrs	r0, r1, #16
    ldr	r1, [sp, #0]
    subs	r1, r0, r1
    mov	sl, r1
    cmp	r5, #0
    ble .Leu_08037196
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Leu_08037176
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Leu_08037178
.Leu_08037176:
    adds	r0, r1, #0
.Leu_08037178:
    cmp	r5, r0
    ble .Leu_08037196
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Leu_0803718E
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Leu_08037190
.Leu_0803718E:
    adds	r0, r1, #0
.Leu_08037190:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Leu_08037196:
    cmp	r5, #0
    bge .Leu_080371CC
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Leu_080371AC
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Leu_080371AE
.Leu_080371AC:
    adds	r0, r1, #0
.Leu_080371AE:
    cmp	r5, r0
    bge .Leu_080371CC
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Leu_080371C4
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Leu_080371C6
.Leu_080371C4:
    adds	r0, r1, #0
.Leu_080371C6:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Leu_080371CC:
    mov	r0, sl
    cmp	r0, #0
    bge .Leu_08037206
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Leu_080371E4
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Leu_080371E6
.Leu_080371E4:
    adds	r0, r1, #0
.Leu_080371E6:
    cmp	sl, r0
    bge .Leu_08037206
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Leu_080371FC
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Leu_080371FE
.Leu_080371FC:
    adds	r0, r1, #0
.Leu_080371FE:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Leu_08037206:
    mov	r0, sl
    cmp	r0, #0
    ble .Leu_08037240
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Leu_0803721E
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Leu_08037220
.Leu_0803721E:
    adds	r0, r1, #0
.Leu_08037220:
    cmp	sl, r0
    ble .Leu_08037240
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Leu_08037236
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Leu_08037238
.Leu_08037236:
    adds	r0, r1, #0
.Leu_08037238:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Leu_08037240:
    mov	r0, r9
    str	r0, [r7, #8]
    mov	r1, r8
    str	r1, [r7, #12]
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037244
    .thumb_func
func_08037244:
    ldr	r2, [r1, #4]
    ldr	r1, [r1, #0]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    bx	lr
    .align 2, 0
    sub	sp, #8
    mov	r3, sp
    movs	r1, #0
    mov	r2, sp
    strh	r1, [r2, #0]
    strh	r1, [r3, #2]
    strh	r1, [r3, #4]
    strh	r1, [r3, #6]
    ldr	r1, [sp, #0]
    ldr	r2, [sp, #4]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    add	sp, #8
    bx	lr
    .global func_0803726C
    .thumb_func
func_0803726C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #96	@ 0x60
    adds	r7, r0, #0
    ldr	r4, [r7, #0]
    ldrh	r0, [r7, #4]
    mov	r8, r0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #20]
    adds	r0, r4, #0
    bl _call_via_r1
    cmp	r0, r8
    beq .Leu_080372A2
    b .Leu_08037416
.Leu_080372A2:
    ldr	r1, [r4, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r4, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #64	@ 0x40
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    str	r1, [sp, #88]	@ 0x58
    str	r2, [sp, #92]	@ 0x5c
    add	r4, sp, #12
    movs	r2, #32
    mov	r9, r2
    movs	r5, #0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r1, r9
    str	r1, [r4, #40]	@ 0x28
    str	r5, [r4, #44]	@ 0x2c
    str	r5, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r9, r4
    cmp	r3, #0
    beq .Leu_08037324
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Leu_08037324
    ldr	r1, [r3, #20]
    add	r4, sp, #72	@ 0x48
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Leu_08037324:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Leu_08037354
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Leu_08037354
    ldr	r1, [r3, #20]
    add	r4, sp, #80	@ 0x50
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Leu_08037354:
    adds	r2, r7, #0
    adds	r2, #52	@ 0x34
    movs	r3, #4
    ldrsh	r0, [r2, r3]
    movs	r6, #52	@ 0x34
    ldrsh	r1, [r7, r6]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Leu_0803737E
    movs	r1, #6
    ldrsh	r0, [r2, r1]
    movs	r3, #2
    ldrsh	r1, [r2, r3]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Leu_0803737E
    mov	r0, r9
    adds	r1, r2, #0
    movs	r2, #0
    bl func_080ABA90
.Leu_0803737E:
    ldrh	r4, [r7, #62]	@ 0x3e
    cmp	r4, #0
    beq .Leu_08037400
    ldr	r5, [r7, #24]
    ldr	r6, [r7, #28]
    cmp	r5, #0
    bge .Leu_080373A4
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Leu_0803739E
    add	r0, sp, #12
    bl func_080AB948
    ldr	r0, [sp, #20]
    b .Leu_080373A0
.Leu_0803739E:
    adds	r0, r1, #0
.Leu_080373A0:
    cmp	r0, #0
    bge .Leu_080373F8
.Leu_080373A4:
    cmp	r5, #0
    ble .Leu_080373C0
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Leu_080373BA
    add	r0, sp, #12
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Leu_080373BC
.Leu_080373BA:
    adds	r0, r1, #0
.Leu_080373BC:
    cmp	r0, #0
    ble .Leu_080373F8
.Leu_080373C0:
    cmp	r6, #0
    bge .Leu_080373DC
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Leu_080373D6
    add	r0, sp, #12
    bl func_080AB8D0
    ldr	r0, [sp, #16]
    b .Leu_080373D8
.Leu_080373D6:
    adds	r0, r1, #0
.Leu_080373D8:
    cmp	r0, #0
    bge .Leu_080373F8
.Leu_080373DC:
    cmp	r6, #0
    ble .Leu_080373FC
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Leu_080373F2
    add	r0, sp, #12
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Leu_080373F4
.Leu_080373F2:
    adds	r0, r1, #0
.Leu_080373F4:
    cmp	r0, #0
    bgt .Leu_080373FC
.Leu_080373F8:
    movs	r4, #0
    b .Leu_0803740C
.Leu_080373FC:
    subs	r4, #1
    b .Leu_0803740C
.Leu_08037400:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #64]	@ 0x40
    adds	r0, r7, #0
    bl _call_via_r1
    adds	r4, r0, #0
.Leu_0803740C:
    strh	r4, [r7, #62]	@ 0x3e
    adds	r0, r7, #0
    mov	r1, r9
    bl func_08037118
.Leu_08037416:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_08037420
    subs	r0, #1
    b .Leu_08037422
.Leu_08037420:
    ldrh	r0, [r7, #38]	@ 0x26
.Leu_08037422:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Leu_08037434
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Leu_08037434:
    add	sp, #96	@ 0x60
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037430
    .thumb_func
func_08037430:
    ldrh	r0, [r0, #60]	@ 0x3c
    bx	lr
    .global func_08037434
    .thumb_func
func_08037434:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #64	@ 0x40
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Leu_0803745E
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    bl _call_via_r1
.Leu_0803745E:
    movs	r0, #0
    strh	r0, [r4, #62]	@ 0x3e
    adds	r0, r4, #0
    bl vfunc_10__7AEntity
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803745C
    .thumb_func
func_0803745C:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    adds	r4, #64	@ 0x40
    movs	r0, #0
    strb	r0, [r4, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037470
    .thumb_func
func_08037470:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #9
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0
    .global func_08037494
    .thumb_func
func_08037494:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Leu_080374CC
    movs	r1, #1
.Leu_080374CC:
    lsls	r4, r1, #2
    adds	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Leu_0803754C
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #5
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Leu_0803751C
    cmp	r1, #3
    beq .Leu_0803751C
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_0803751C
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_0803751C:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037628
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_08037542
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Leu_08037542:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803754C:
    .4byte gUnk_080F1538
    .global func_0803753C
    .thumb_func
func_0803753C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #7
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #9
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037568
    .thumb_func
func_08037568:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Leu_08037614
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Leu_080375D6
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Leu_080375D6:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #0
    beq .Leu_08037614
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Leu_08037614
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A17A0
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_0803761E
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Leu_0803761E
.Leu_08037614:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Leu_0803761E:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037618
    .thumb_func
func_08037618:
    ldr r0, .Leu_08037638
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Leu_08037638:
    .4byte gUnk_080F1560
    .global func_08037628
    .thumb_func
func_08037628:
    push	{lr}
    cmp	r1, #1
    beq .Leu_08037646
    movs	r0, #0
    b .Leu_0803764A
.Leu_08037646:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Leu_0803764A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803763C
    .thumb_func
func_0803763C:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Leu_08037674
    movs	r1, #1
.Leu_08037674:
    lsls	r4, r1, #3
    subs	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Leu_080376F4
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #7
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Leu_080376C4
    cmp	r1, #3
    beq .Leu_080376C4
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_080376C4
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_080376C4:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377D4
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080376EA
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Leu_080376EA:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080376F4:
    .4byte gUnk_080F156C
    .global func_080376E4
    .thumb_func
func_080376E4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #2
    str	r1, [sp, #0]
    movs	r1, #12
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #12
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037714
    .thumb_func
func_08037714:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Leu_080377C0
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Leu_08037782
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Leu_08037782:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #1
    beq .Leu_080377C0
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Leu_080377C0
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A1890
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080377CA
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Leu_080377CA
.Leu_080377C0:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Leu_080377CA:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080377C4
    .thumb_func
func_080377C4:
    ldr r0, .Leu_080377E4
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Leu_080377E4:
    .4byte gUnk_080F15A4
    .global func_080377D4
    .thumb_func
func_080377D4:
    push	{lr}
    cmp	r1, #1
    beq .Leu_080377F2
    movs	r0, #0
    b .Leu_080377F6
.Leu_080377F2:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Leu_080377F6:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080377E8
    .thumb_func
func_080377E8:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r4, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Leu_08037820
    movs	r4, #1
.Leu_08037820:
    movs	r0, #52	@ 0x34
    muls	r4, r0
    ldr r0, .Leu_0803789C
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #13
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Leu_0803786E
    cmp	r1, #3
    beq .Leu_0803786E
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_0803786E
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_0803786E:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378FC
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_08037894
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Leu_08037894:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Leu_0803789C:
    .4byte gUnk_080F15B4
    .global func_0803788C
    .thumb_func
func_0803788C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080378B8
    .thumb_func
func_080378B8:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A198C
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080378F6
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Leu_080378F6:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080378EC
    .thumb_func
func_080378EC:
    ldr r0, .Leu_0803790C
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Leu_0803790C:
    .4byte gUnk_080F161C
    .global func_080378FC
    .thumb_func
func_080378FC:
    push	{lr}
    cmp	r1, #12
    bhi .Leu_08037958
    lsls	r0, r1, #2
    ldr r1, .Leu_08037920
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_08037920:
    .4byte .Leu_08037924
.Leu_08037924:
    .4byte .Leu_08037958
    .4byte .Leu_0803795C
    .4byte .Leu_08037962
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037958
    .4byte .Leu_08037962
    .4byte .Leu_08037958
.Leu_08037958:
    movs	r0, #0
    b .Leu_08037966
.Leu_0803795C:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE001
.Leu_08037962:
    .hword 0x2080
    .hword 0x0240
.Leu_08037966:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037958
    .thumb_func
func_08037958:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr r5, .Leu_080379E8
    adds	r0, r5, #0
    movs	r1, #3
    bl func_080AB82C
    lsls	r4, r0, #2
    adds	r4, r4, r5
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Leu_080379B8
    cmp	r1, #3
    beq .Leu_080379B8
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_080379B8
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_080379B8:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A48
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080379DE
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Leu_080379DE:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080379E8:
    .4byte gUnk_080F1638
    .global func_080379D8
    .thumb_func
func_080379D8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037A04
    .thumb_func
func_08037A04:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A19EC
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_08037A42
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Leu_08037A42:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037A38
    .thumb_func
func_08037A38:
    ldr r0, .Leu_08037A58
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Leu_08037A58:
    .4byte gUnk_080F1644
    .global func_08037A48
    .thumb_func
func_08037A48:
    push	{lr}
    cmp	r1, #1
    beq .Leu_08037A66
    movs	r0, #0
    b .Leu_08037A6A
.Leu_08037A66:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Leu_08037A6A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037A5C
    .thumb_func
func_08037A5C:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    ldr r3, .Leu_08037ADC
    bl func_08037008
    ldr r0, .Leu_08037AE0
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08037ADC:
    .4byte 0x0000071C
.Leu_08037AE0:
    .4byte vtable_unk_080E72E4
    .global func_08037AD0
    .thumb_func
func_08037AD0:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    bl func_08037008
    ldr r0, .Leu_08037B58
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08037B58:
    .4byte vtable_unk_080E72A0
    .global func_08037B48
    .thumb_func
func_08037B48:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Leu_08037B8C
    bl func_08037008
    ldr r0, .Leu_08037B90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08037B8C:
    .4byte 0x00000379
.Leu_08037B90:
    .4byte vtable_unk_080E725C
    .global func_08037B80
    .thumb_func
func_08037B80:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Leu_08037BC4
    bl func_08037008
    ldr r0, .Leu_08037BC8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08037BC4:
    .4byte 0x00000207
.Leu_08037BC8:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Leu_08037BEC
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Leu_08037BF0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08037BEC:
    .4byte 0x00000207
.Leu_08037BF0:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Leu_08037C14
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Leu_08037C18
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08037C14:
    .4byte 0x00000379
.Leu_08037C18:
    .4byte vtable_unk_080E725C
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Leu_08037C78
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Leu_08037C78:
    .4byte vtable_unk_080E72A0
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    ldr r3, .Leu_08037CD0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Leu_08037CD4
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Leu_08037CD0:
    .4byte 0x0000071C
.Leu_08037CD4:
    .4byte vtable_unk_080E72E4
    .global func_08037CC4
    .thumb_func
func_08037CC4:
    push	{r4, lr}
    adds	r4, r0, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Leu_08037CEC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_08037CEC:
    .4byte vtable_unk_080E7444
    .global func_08037CDC
    .thumb_func
func_08037CDC:
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r3, #14
    ldrsh	r1, [r1, r3]
    strh	r2, [r0, #0]
    adds	r1, #1
    strh	r1, [r0, #2]
    strh	r2, [r0, #4]
    strh	r1, [r0, #6]
    bx	lr
    .global func_08037CF0
    .thumb_func
func_08037CF0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037D08
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037D08
    .thumb_func
func_08037D08:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Leu_08037D7C
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #10
    bl func_080A4740
    ldr r0, .Leu_08037D80
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #125	@ 0x7d
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Leu_08037D7C:
    .4byte vtable_unk_080E7478
.Leu_08037D80:
    .4byte vtable_unk_080E602C
    .global func_08037D70
    .thumb_func
func_08037D70:
    bx	lr
    .align 2, 0
    .global func_08037D74
    .thumb_func
func_08037D74:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r2, [r3, r0]
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    subs	r0, r2, r0
    mov	ip, r0
    ldr	r0, [r1, #0]
    ldr	r3, [r1, #8]
    str	r0, [sp, #20]
    str	r3, [sp, #24]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r2
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r2, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08037DF4
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r8
    mov	r2, ip
    movs	r3, #170	@ 0xaa
    ldr r4, .Leu_08037DF0
    bl _call_via_r4
    b .Leu_08037DF6
    .align 2, 0
.Leu_08037DF0:
    .4byte func_030004DC
.Leu_08037DF4:
    movs	r0, #0
.Leu_08037DF6:
    cmp	r0, #0
    beq .Leu_08037E20
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_08037E20
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_08037E20:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037E18
    .thumb_func
func_08037E18:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    mov	r0, sp
    adds	r1, r6, #0
    bl func_0800FFE0
    adds	r0, r4, #0
    adds	r1, r5, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Leu_08037E58
    str	r0, [r4, #20]
    str	r6, [r4, #24]
    adds	r0, r4, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Leu_08037E58:
    .4byte vtable_unk_080E73FC
    .global func_08037E48
    .thumb_func
func_08037E48:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Leu_08037EA8
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl func_08010014
    ldr r0, .Leu_08037EAC
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_08037E90
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_08037E90:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Leu_08037E9E
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_08037E9E:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08037EA8:
    .4byte vtable_unk_080E73FC
.Leu_08037EAC:
    .4byte __vt_7AEntity
    .global func_08037E9C
    .thumb_func
func_08037E9C:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #88	@ 0x58
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037EF0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037EB4
    .thumb_func
func_08037EB4:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #24]
    ldrb	r1, [r1, #0]
    bl func_0800FFF4
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Leu_08037EDE
    bl func_08037F74
.Leu_08037EDE:
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037ED0
    .thumb_func
func_08037ED0:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_08037EF0
    .thumb_func
func_08037EF0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Leu_08037F6C
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #8
    bl func_080A4740
    ldr r0, .Leu_08037F70
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #53	@ 0x35
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    adds	r0, #84	@ 0x54
    strb	r2, [r0, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Leu_08037F6C:
    .4byte vtable_unk_080E7430
.Leu_08037F70:
    .4byte vtable_unk_080E602C
    .global func_08037F60
    .thumb_func
func_08037F60:
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #84	@ 0x54
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Leu_08037F84
    subs	r0, #1
    strb	r0, [r1, #0]
.Leu_08037F84:
    pop	{r0}
    bx	r0
    .global func_08037F74
    .thumb_func
func_08037F74:
    adds	r0, #84	@ 0x54
    movs	r1, #10
    strb	r1, [r0, #0]
    bx	lr
    .global func_08037F7C
    .thumb_func
func_08037F7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r3, [r3, r0]
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    subs	r2, r3, r0
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    mov	ip, r1
    str	r0, [sp, #20]
    str	r1, [sp, #24]
    adds	r0, r4, #0
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08037FC8
    subs	r2, #2
.Leu_08037FC8:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r3
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r3, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08038004
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    mov	r1, r8
    movs	r3, #170	@ 0xaa
    ldr r4, .Leu_08038000
    bl _call_via_r4
    b .Leu_08038006
.Leu_08038000:
    .4byte func_030004DC
.Leu_08038004:
    movs	r0, #0
.Leu_08038006:
    cmp	r0, #0
    beq .Leu_08038030
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_08038030
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_08038030:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038028
    .thumb_func
func_08038028:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r6, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Leu_080380A8
    str	r0, [r6, #20]
    str	r4, [r6, #24]
    movs	r0, #0
    str	r0, [r6, #28]
    adds	r1, r6, #0
    adds	r1, #37	@ 0x25
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    movs	r0, #49	@ 0x31
    strh	r0, [r6, #40]	@ 0x28
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_0803809C
    ldrh	r0, [r4, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Leu_0803809C
    adds	r0, r4, #0
    bl func_08020460
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803809C
    ldr	r1, [r4, #8]
    ldr	r2, [r4, #12]
    ldrh	r3, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r6, #0
    bl func_08038374
.Leu_0803809C:
    adds	r0, r6, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080380A8:
    .4byte vtable_unk_080E73B4
    .global func_08038098
    .thumb_func
func_08038098:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Leu_080380F8
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    ldr r0, .Leu_080380FC
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_080380E2
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_080380E2:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Leu_080380F0
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_080380F0:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Leu_080380F8:
    .4byte vtable_unk_080E73B4
.Leu_080380FC:
    .4byte __vt_7AEntity
    .global func_080380EC
    .thumb_func
func_080380EC:
    adds	r2, r0, #0
    adds	r2, #36	@ 0x24
    strb	r1, [r2, #0]
    movs	r1, #168	@ 0xa8
    lsls	r1, r1, #13
    str	r1, [r0, #28]
    movs	r1, #192	@ 0xc0
    lsls	r1, r1, #10
    str	r1, [r0, #32]
    adds	r0, #37	@ 0x25
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038108
    .thumb_func
func_08038108:
    adds	r0, #37	@ 0x25
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038110
    .thumb_func
func_08038110:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #68	@ 0x44
    adds	r6, r0, #0
    adds	r4, r6, #0
    adds	r4, #37	@ 0x25
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_0803813A
    b .Leu_08038308
.Leu_0803813A:
    ldr	r7, [r6, #0]
    ldrh	r2, [r6, #4]
    ldr	r1, [r7, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r7, #0
    bl _call_via_r3
    mov	r8, sp
    ldr	r1, [r6, #32]
    ldr r0, .Leu_080381B4
    adds	r1, r1, r0
    str	r1, [r6, #32]
    ldr	r0, [r6, #28]
    adds	r0, r0, r1
    str	r0, [r6, #28]
    cmp	r0, #0
    bgt .Leu_08038160
    b .Leu_08038270
.Leu_08038160:
    ldr	r1, [r6, #20]
    add	r0, sp, #52	@ 0x34
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r1, [sp, #52]	@ 0x34
    ldr	r2, [sp, #56]	@ 0x38
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    add	r5, sp, #12
    movs	r2, #32
    mov	r8, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r5, #4]
    str	r0, [r5, #8]
    str	r1, [r5, #12]
    add	r1, sp, #28
    mov	r0, sp
    ldmia	r0!, {r2, r3, r4}
    stmia	r1!, {r2, r3, r4}
    ldr	r3, [sp, #60]	@ 0x3c
    ldr	r4, [sp, #64]	@ 0x40
    str	r3, [sp, #40]	@ 0x28
    str	r4, [sp, #44]	@ 0x2c
    mov	r4, r8
    str	r4, [r5, #36]	@ 0x24
    ldr	r4, [r6, #8]
    ldr	r7, [r6, #12]
    adds	r0, r6, #0
    adds	r0, #36	@ 0x24
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Leu_080381C2
    cmp	r0, #1
    bgt .Leu_080381B8
    cmp	r0, #0
    beq .Leu_080381E8
    b .Leu_08038264
.Leu_080381B4:
    .4byte 0xFFFFB85D
.Leu_080381B8:
    cmp	r0, #2
    beq .Leu_08038244
    cmp	r0, #3
    beq .Leu_08038218
    b .Leu_08038264
.Leu_080381C2:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Leu_080381D4
    adds	r0, r5, #0
    bl func_080ABBC4
    ldr	r0, [sp, #16]
    b .Leu_080381D6
.Leu_080381D4:
    adds	r0, r1, #0
.Leu_080381D6:
    lsls	r1, r0, #16
    ldr r0, .Leu_080381E4
    cmp	r1, r0
    bgt .Leu_08038204
    ldr r5, .Leu_080381E4
    adds	r7, r7, r5
    b .Leu_08038264
.Leu_080381E4:
    .4byte 0xFFFE38E4
.Leu_080381E8:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Leu_080381FA
    adds	r0, r5, #0
    bl func_080ABBA0
    ldr	r0, [sp, #12]
    b .Leu_080381FC
.Leu_080381FA:
    adds	r0, r1, #0
.Leu_080381FC:
    lsls	r1, r0, #16
    ldr r0, .Leu_08038208
    cmp	r1, r0
    bgt .Leu_0803820C
.Leu_08038204:
    adds	r7, r7, r1
    b .Leu_08038264
.Leu_08038208:
    .4byte 0x0001C71B
.Leu_0803820C:
    ldr r0, .Leu_08038214
    adds	r7, r7, r0
    b .Leu_08038264
    .align 2, 0
.Leu_08038214:
    .4byte 0x0001C71C
.Leu_08038218:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Leu_0803822A
    adds	r0, r5, #0
    bl func_080ABC14
    ldr	r0, [sp, #24]
    b .Leu_0803822C
.Leu_0803822A:
    adds	r0, r1, #0
.Leu_0803822C:
    lsls	r1, r0, #16
    ldr r0, .Leu_0803823C
    cmp	r1, r0
    ble .Leu_08038236
    ldr r1, .Leu_08038240
.Leu_08038236:
    adds	r4, r4, r1
    b .Leu_08038264
    .align 2, 0
.Leu_0803823C:
    .4byte 0x0001C71B
.Leu_08038240:
    .4byte 0x0001C71C
.Leu_08038244:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Leu_08038256
    adds	r0, r5, #0
    bl func_080ABBEC
    ldr	r0, [sp, #20]
    b .Leu_08038258
.Leu_08038256:
    adds	r0, r1, #0
.Leu_08038258:
    lsls	r1, r0, #16
    ldr r0, .Leu_0803826C
    cmp	r1, r0
    bgt .Leu_08038236
    ldr r2, .Leu_0803826C
    adds	r4, r4, r2
.Leu_08038264:
    str	r4, [r6, #8]
    str	r7, [r6, #12]
    b .Leu_08038308
    .align 2, 0
.Leu_0803826C:
    .4byte 0xFFFE38E4
.Leu_08038270:
    movs	r0, #0
    str	r0, [r6, #28]
    strb	r0, [r4, #0]
    add	r4, sp, #12
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #24]
    adds	r1, r4, #0
    movs	r2, #6
    bl memcpy
    ldr	r0, [r6, #8]
    ldr	r1, [r6, #12]
    asrs	r0, r0, #19
    mov	ip, r0
    asrs	r3, r1, #19
    ldr	r1, [sp, #0]
    mov	r5, r8
    ldrh	r0, [r5, #8]
    cmp	r1, #0
    beq .Leu_080382BC
    cmp	ip, r0
    bhi .Leu_080382BC
    ldrh	r2, [r5, #10]
    cmp	r3, r2
    bhi .Leu_080382BC
    ldr	r2, [sp, #4]
    muls	r0, r3
    add	r0, ip
    cmp	r2, #0
    beq .Leu_080382B6
    adds	r0, r2, r0
    ldrb	r0, [r0, #0]
.Leu_080382B6:
    lsls	r0, r0, #2
    adds	r0, r1, r0
    b .Leu_080382BE
.Leu_080382BC:
    movs	r0, #0
.Leu_080382BE:
    cmp	r0, #0
    bne .Leu_080382D6
    ldr	r0, [r7, #0]
    movs	r3, #158	@ 0x9e
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #1
    bl _call_via_r2
    b .Leu_08038308
.Leu_080382D6:
    ldr	r0, [r0, #0]
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_080382F2
    ldr	r0, [r7, #0]
    movs	r4, #158	@ 0x9e
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
    bl _call_via_r2
    b .Leu_08038308
.Leu_080382F2:
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    cmp	r0, #0
    beq .Leu_08038308
    adds	r1, r4, #0
    bl func_0802151C
.Leu_08038308:
    add	sp, #68	@ 0x44
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038300
    .thumb_func
func_08038300:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r2, [r4, #16]
    cmp	r2, #0
    beq .Leu_08038328
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Leu_08038328:
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038320
    .thumb_func
func_08038320:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_2C__7AEntityUi
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038334
    .thumb_func
func_08038334:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r1, r4, #0
    bl func_0803853C
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803834C
    .thumb_func
func_0803834C:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #4
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #4
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_0803836C
    .thumb_func
func_0803836C:
    movs	r1, #30
    ldrsh	r0, [r0, r1]
    bx	lr
    .align 2, 0
    .global func_08038374
    .thumb_func
func_08038374:
    push	{r4, r5, r6, lr}
    ldr	r5, [sp, #16]
    movs	r4, #38	@ 0x26
    adds	r4, r4, r0
    mov	ip, r4
    movs	r4, #1
    mov	r6, ip
    strb	r4, [r6, #0]
    str	r1, [r0, #8]
    str	r2, [r0, #12]
    adds	r1, r3, #0
    adds	r2, r5, #0
    bl func_08038398
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038398
    .thumb_func
func_08038398:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    movs	r3, #21
    ldr r4, .Leu_080383C8
    adds	r0, r1, r4
    cmp	r0, #61	@ 0x3d
    bls .Leu_080383BC
    b .Leu_080384DE
.Leu_080383BC:
    lsls	r0, r0, #2
    ldr r1, .Leu_080383CC
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_080383C8:
    .4byte 0xFFFFFCC8
.Leu_080383CC:
    .4byte .Leu_080383D0
.Leu_080383D0:
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384C8
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384CC
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384D0
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384D4
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384D8
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DE
    .4byte .Leu_080384DC
.Leu_080384C8:
    .4byte 0xE0082319
.Leu_080384CC:
    .4byte 0xE006231D
.Leu_080384D0:
    .4byte 0xE0042321
.Leu_080384D4:
    .4byte 0xE0022325
.Leu_080384D8:
    .4byte 0xE0002329
.Leu_080384DC:
    .hword 0x232D
.Leu_080384DE:
    adds	r1, r3, r2
    adds	r6, r1, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r1, r0
    beq .Leu_0803850A
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Leu_08038508
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Leu_08038508:
    strh	r6, [r5, #40]	@ 0x28
.Leu_0803850A:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_080384FC
    .thumb_func
func_080384FC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r0, #49	@ 0x31
    beq .Leu_08038540
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Leu_0803853C
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    movs	r1, #49	@ 0x31
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Leu_0803853C:
    movs	r0, #49	@ 0x31
    strh	r0, [r5, #40]	@ 0x28
.Leu_08038540:
    adds	r1, r5, #0
    adds	r1, #38	@ 0x26
    movs	r0, #0
    strb	r0, [r1, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803853C
    .thumb_func
func_0803853C:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r6, r0, #0
    adds	r4, r1, #0
    str	r4, [r6, #0]
    ldr r0, .Leu_08038590
    str	r0, [r6, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r6, #0
    adds	r0, #8
    ldrh	r2, [r4, #40]	@ 0x28
    movs	r4, #2
    str	r4, [sp, #0]
    movs	r4, #7
    str	r4, [sp, #4]
    add	r5, sp, #8
    movs	r4, #0
    strb	r4, [r5, #0]
    bl func_080A4A00
    adds	r0, r6, #0
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08038590:
    .4byte vtable_unk_080E73E8
    .global func_08038580
    .thumb_func
func_08038580:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_080385B8
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_080385BC
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Leu_080385BA
.Leu_080385B8:
    movs	r0, #0
.Leu_080385BA:
    strb	r0, [r1, #0]
.Leu_080385BC:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080385B0
    .thumb_func
func_080385B0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r5, r0, #0
    mov	sl, r1
    ldr	r0, [r5, #0]
    mov	r9, r0
    movs	r1, #10
    ldrsh	r6, [r0, r1]
    mov	r2, sl
    movs	r3, #12
    ldrsh	r0, [r2, r3]
    subs	r0, r6, r0
    str	r0, [sp, #60]	@ 0x3c
    mov	r0, r9
    movs	r1, #14
    ldrsh	r4, [r0, r1]
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    subs	r0, r4, r0
    str	r0, [sp, #64]	@ 0x40
    mov	r0, r9
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r4
    mov	r8, r0
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    beq .Leu_08038610
    movs	r1, #1
    negs	r1, r1
    add	r8, r1
.Leu_08038610:
    add	r0, sp, #52	@ 0x34
    mov	r2, sl
    ldr	r1, [r2, #0]
    ldr	r2, [r2, #8]
    str	r1, [sp, #52]	@ 0x34
    str	r2, [r0, #4]
    ldr	r3, [sp, #64]	@ 0x40
    str	r3, [sp, #72]	@ 0x48
    movs	r7, #2
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    bne .Leu_0803865A
    mov	r0, r9
    bl func_0803836C
    ldr	r1, [sp, #64]	@ 0x40
    subs	r1, r1, r0
    str	r1, [sp, #72]	@ 0x48
    cmp	r0, #15
    ble .Leu_0803865A
    mov	r2, r9
    ldrh	r0, [r2, #4]
    cmp	r0, #8
    bgt .Leu_08038658
    cmp	r0, #2
    bne .Leu_0803865A
    ldr r3, .Leu_080386C0
    adds	r1, r6, r3
    ldr r0, .Leu_080386C4
    cmp	r1, r0
    bhi .Leu_0803865A
    cmp	r4, #175	@ 0xaf
    ble .Leu_0803865A
    subs	r0, #96	@ 0x60
    cmp	r4, r0
    bgt .Leu_0803865A
.Leu_08038658:
    movs	r7, #1
.Leu_0803865A:
    adds	r6, r5, #0
    adds	r6, #8
    mov	r0, sp
    adds	r0, #52	@ 0x34
    str	r0, [sp, #76]	@ 0x4c
    adds	r0, r7, #0
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    ldr	r1, [r5, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r5, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r1, [sp, #76]	@ 0x4c
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #8]
    ldr	r1, [r5, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_080386CC
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #24
    mov	r5, r8
    str	r5, [sp, #0]
    adds	r5, r7, #0
    str	r5, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #72]	@ 0x48
    adds	r3, r4, #0
    ldr r4, .Leu_080386C8
    bl _call_via_r4
    b .Leu_080386CE
    .align 2, 0
.Leu_080386C0:
    .4byte 0xFFFFFEF0
.Leu_080386C4:
    .4byte 0x000002AF
.Leu_080386C8:
    .4byte func_030004DC
.Leu_080386CC:
    movs	r0, #0
.Leu_080386CE:
    cmp	r0, #0
    beq .Leu_08038722
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Leu_08038722
    ldr	r0, [sp, #76]	@ 0x4c
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08038704
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_0803871E
.Leu_08038704:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_0803871E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_0803871E:
    movs	r0, #0
    strb	r0, [r5, #0]
.Leu_08038722:
    ldr	r1, [sp, #68]	@ 0x44
    cmp	r1, #0
    bne .Leu_08038744
    mov	r2, r9
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #88]	@ 0x58
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    ldr	r5, [sp, #68]	@ 0x44
    str	r5, [sp, #0]
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r3, [sp, #64]	@ 0x40
    bl func_0803AE58
.Leu_08038744:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038740
    .thumb_func
func_08038740:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r2
    mov	r2, sp
    movs	r5, #8
    ldrh	r3, [r2, #0]
    ldr r4, .Leu_080387AC
    adds	r0, r4, #0
    ands	r0, r3
    orrs	r0, r5
    strh	r0, [r2, #0]
    ldrb	r5, [r2, #1]
    movs	r3, #3
    adds	r0, r3, #0
    ands	r0, r5
    strb	r0, [r2, #1]
    ldrh	r5, [r2, #2]
    adds	r0, r4, #0
    ands	r0, r5
    strh	r0, [r2, #2]
    ldrb	r0, [r2, #3]
    ands	r3, r0
    strb	r3, [r2, #3]
    ldrh	r0, [r2, #4]
    ands	r4, r0
    strh	r4, [r2, #4]
    adds	r0, r6, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Leu_080387B0
    str	r0, [r6, #20]
    mov	r0, r8
    str	r0, [r6, #24]
    adds	r0, r6, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080387AC:
    .4byte 0xFFFFFC00
.Leu_080387B0:
    .4byte vtable_unk_080E7380
    .global func_080387A0
    .thumb_func
func_080387A0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #24
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08038820
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080387B8
    .thumb_func
func_080387B8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_080387D8
    bl func_08038DF0
.Leu_080387D8:
    pop	{r0}
    bx	r0
    .global func_080387C8
    .thumb_func
func_080387C8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_080387E8
    bl func_08038E90
.Leu_080387E8:
    pop	{r0}
    bx	r0
    .global func_080387D8
    .thumb_func
func_080387D8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Leu_080387F8
    movs	r0, #1
    b .Leu_080387FC
.Leu_080387F8:
    bl func_08038EA0
.Leu_080387FC:
    pop	{r1}
    bx	r1
    .global func_080387EC
    .thumb_func
func_080387EC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_0803880C
    bl func_08038EB8
.Leu_0803880C:
    pop	{r0}
    bx	r0
    .global func_080387FC
    .thumb_func
func_080387FC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_0803881C
    bl func_08038EE0
.Leu_0803881C:
    pop	{r0}
    bx	r0
    .global func_0803880C
    .thumb_func
func_0803880C:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Leu_0803882C
    movs	r0, #0
    b .Leu_08038830
.Leu_0803882C:
    bl func_080390D0
.Leu_08038830:
    pop	{r1}
    bx	r1
    .global func_08038820
    .thumb_func
func_08038820:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    str	r1, [r7, #0]
    ldr r0, .Leu_080388B0
    str	r0, [r7, #4]
    ldr	r0, [r1, #24]
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    mov	sl, r0
    cmp	r0, #1
    bne .Leu_080388B8
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r6, r0, #0
    mov	r0, r9
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #116]	@ 0x74
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Leu_080388B4
    str	r0, [r6, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r6
    mov	r8, r1
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r0, r6, #0
    adds	r0, #72	@ 0x48
    mov	r5, sl
    strb	r5, [r0, #0]
    b .Leu_080388BA
    .align 2, 0
.Leu_080388B0:
    .4byte vtable_unk_080E736C
.Leu_080388B4:
    .4byte vtable_unk_080E602C
.Leu_080388B8:
    movs	r6, #0
.Leu_080388BA:
    str	r6, [r7, #8]
    movs	r0, #0
    str	r0, [r7, #12]
    str	r0, [r7, #16]
    adds	r4, r7, #0
    adds	r4, #20
    str	r0, [r7, #20]
    movs	r0, #202	@ 0xca
    lsls	r0, r0, #1
    bl __builtin_new
    adds	r3, r0, #0
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    movs	r2, #0
    mov	r5, r9
    ldr	r0, [r5, #24]
    adds	r0, #93	@ 0x5d
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_080388EA
    movs	r2, #1
.Leu_080388EA:
    adds	r0, r3, #0
    bl func_080DCB7C
    mov	r9, r4
    mov	r8, r0
    ldr	r6, [r7, #20]
    cmp	r8, r6
    beq .Leu_08038924
    cmp	r6, #0
    beq .Leu_08038924
    ldr	r1, [r6, #0]
    lsls	r0, r1, #2
    adds	r0, r0, r1
    lsls	r0, r0, #4
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Leu_0803891E
.Leu_08038910:
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r4, #80	@ 0x50
    cmp	r4, r5
    bne .Leu_08038910
.Leu_0803891E:
    adds	r0, r6, #0
    bl __builtin_delete
.Leu_08038924:
    mov	r0, r8
    mov	r1, r9
    str	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08038928
    .thumb_func
func_08038928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    mov	r8, r0
    ldr	r0, [r0, #20]
    cmp	r0, #0
    beq .Leu_0803899E
    adds	r6, r0, #0
    movs	r7, #0
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcs .Leu_0803899E
    adds	r4, r6, #0
    adds	r4, #64	@ 0x40
    adds	r5, r6, #0
    adds	r5, #44	@ 0x2c
.Leu_08038960:
    ldrb	r0, [r4, #3]
    cmp	r0, #0
    bne .Leu_08038978
    adds	r0, r5, #0
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_0803897C
    movs	r0, #1
    strb	r0, [r4, #0]
    b .Leu_0803897C
.Leu_08038978:
    movs	r0, #0
    strb	r0, [r4, #3]
.Leu_0803897C:
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #12]
    subs	r1, r1, r0
    str	r1, [r4, #4]
    ldrb	r0, [r4, #16]
    lsls	r0, r0, #16
    cmn	r1, r0
    bge .Leu_08038992
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #17
    str	r0, [r4, #4]
.Leu_08038992:
    adds	r4, #80	@ 0x50
    adds	r5, #80	@ 0x50
    adds	r7, #1
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcc .Leu_08038960
.Leu_0803899E:
    mov	r0, r8
    ldr	r1, [r0, #12]
    cmp	r1, #0
    beq .Leu_080389C6
    adds	r3, r1, #0
    adds	r3, #80	@ 0x50
    ldrb	r0, [r3, #0]
    cmp	r0, #0
    beq .Leu_080389C6
    ldr	r0, [r1, #76]	@ 0x4c
    ldr r2, .Leu_08038A08
    adds	r0, r0, r2
    str	r0, [r1, #76]	@ 0x4c
    movs	r2, #168	@ 0xa8
    lsls	r2, r2, #16
    cmp	r0, r2
    bgt .Leu_080389C6
    str	r2, [r1, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r3, #0]
.Leu_080389C6:
    mov	r1, r8
    ldr	r0, [r1, #16]
    cmp	r0, #0
    beq .Leu_08038A74
    movs	r2, #0
    movs	r7, #0
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r5, r0, r1
    adds	r4, r0, #0
    adds	r4, #44	@ 0x2c
    adds	r6, r0, #0
    adds	r6, #67	@ 0x43
.Leu_080389E0:
    ldrb	r1, [r5, #0]
    cmp	r1, #0
    bne .Leu_08038A1C
    ldrb	r0, [r4, #23]
    cmp	r0, #0
    bne .Leu_08038A0C
    adds	r0, r4, #0
    str	r2, [sp, #0]
    bl func_0805E8F0
    adds	r1, r0, #0
    lsls	r0, r1, #30
    ldr	r2, [sp, #0]
    cmp	r0, #0
    bge .Leu_08038A02
    movs	r0, #1
    strb	r0, [r4, #20]
.Leu_08038A02:
    adds	r0, r1, #0
    b .Leu_08038A10
    .align 2, 0
.Leu_08038A08:
    .4byte 0xFFFF8000
.Leu_08038A0C:
    strb	r1, [r6, #0]
    movs	r0, #2
.Leu_08038A10:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Leu_08038A1E
    movs	r0, #1
    strb	r0, [r5, #0]
    b .Leu_08038A1E
.Leu_08038A1C:
    adds	r2, #1
.Leu_08038A1E:
    adds	r5, #1
    adds	r4, #64	@ 0x40
    adds	r6, #64	@ 0x40
    adds	r7, #1
    cmp	r7, #4
    bls .Leu_080389E0
    movs	r0, #0
    cmp	r2, #5
    bne .Leu_08038A32
    movs	r0, #1
.Leu_08038A32:
    cmp	r0, #0
    beq .Leu_08038A74
    mov	r7, r8
    adds	r7, #16
    movs	r2, #0
    mov	r9, r2
    mov	r0, r8
    ldr	r6, [r0, #16]
    cmp	r9, r6
    beq .Leu_08038A70
    cmp	r6, #0
    beq .Leu_08038A70
    ldr	r0, [r6, #0]
    lsls	r0, r0, #6
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Leu_08038A6A
.Leu_08038A58:
    ldr	r0, [r4, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r4, #0
    movs	r1, #2
    bl _call_via_r2
    adds	r4, #64	@ 0x40
    cmp	r4, r5
    bne .Leu_08038A58
.Leu_08038A6A:
    adds	r0, r6, #0
    bl __builtin_delete
.Leu_08038A70:
    mov	r1, r9
    str	r1, [r7, #0]
.Leu_08038A74:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038A70
    .thumb_func
func_08038A70:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #140	@ 0x8c
    str	r0, [sp, #92]	@ 0x5c
    movs	r2, #12
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #96]	@ 0x60
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #100]	@ 0x64
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #56]	@ 0x38
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #20]
    cmp	r0, #0
    bne .Leu_08038AB0
    b .Leu_08038BB6
.Leu_08038AB0:
    str	r0, [sp, #104]	@ 0x68
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #108]	@ 0x6c
    str	r1, [sp, #112]	@ 0x70
    movs	r1, #0
    str	r1, [sp, #116]	@ 0x74
    ldr	r2, [sp, #104]	@ 0x68
    ldr	r0, [r2, #0]
    cmp	r1, r0
    bcs .Leu_08038BB6
    adds	r5, r2, #0
    adds	r5, #64	@ 0x40
    adds	r2, #20
    str	r2, [sp, #136]	@ 0x88
    ldr	r6, [sp, #104]	@ 0x68
    adds	r6, #4
.Leu_08038AD2:
    ldr	r0, [sp, #108]	@ 0x6c
    ldr	r1, [sp, #112]	@ 0x70
    str	r0, [sp, #60]	@ 0x3c
    str	r1, [sp, #64]	@ 0x40
    ldrb	r0, [r5, #17]
    cmp	r0, #0
    beq .Leu_08038B9A
    movs	r1, #6
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    movs	r1, #8
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #100]	@ 0x64
    subs	r4, r0, r2
    ldr r0, .Leu_08038B44
    mov	sl, r0
    add	r1, sp, #60	@ 0x3c
    mov	r8, r1
    ldr	r1, [r6, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r6, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, r8
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    ldr	r1, [r6, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08038B4C
    ldrh	r0, [r6, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #136]	@ 0x88
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Leu_08038B48
    bl _call_via_r4
    b .Leu_08038B4E
.Leu_08038B44:
    .4byte 0x00007FFF
.Leu_08038B48:
    .4byte func_030004DC
.Leu_08038B4C:
    movs	r0, #0
.Leu_08038B4E:
    cmp	r0, #0
    beq .Leu_08038B96
    ldrb	r0, [r5, #0]
    adds	r4, r5, #0
    cmp	r0, #0
    beq .Leu_08038B96
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    ldrb	r0, [r5, #1]
    cmp	r0, #0
    beq .Leu_08038B7C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_08038B92
.Leu_08038B7C:
    ldrb	r0, [r5, #2]
    cmp	r0, #0
    bne .Leu_08038B92
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r5, #2]
.Leu_08038B92:
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_08038B96:
    movs	r0, #0
    b .Leu_08038B9C
.Leu_08038B9A:
    movs	r0, #1
.Leu_08038B9C:
    strb	r0, [r5, #17]
    adds	r5, #80	@ 0x50
    ldr	r1, [sp, #136]	@ 0x88
    adds	r1, #80	@ 0x50
    str	r1, [sp, #136]	@ 0x88
    adds	r6, #80	@ 0x50
    ldr	r2, [sp, #116]	@ 0x74
    adds	r2, #1
    str	r2, [sp, #116]	@ 0x74
    ldr	r1, [sp, #104]	@ 0x68
    ldr	r0, [r1, #0]
    cmp	r2, r0
    bcc .Leu_08038AD2
.Leu_08038BB6:
    ldr	r2, [sp, #92]	@ 0x5c
    ldr	r0, [r2, #8]
    cmp	r0, #0
    beq .Leu_08038C44
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #68]	@ 0x44
    str	r1, [sp, #72]	@ 0x48
    movs	r0, #150	@ 0x96
    lsls	r0, r0, #1
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, r0, r1
    mov	r9, r1
    movs	r0, #100	@ 0x64
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #68	@ 0x44
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08038C18
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Leu_08038C14
    bl _call_via_r4
    b .Leu_08038C1A
.Leu_08038C14:
    .4byte func_030004DC
.Leu_08038C18:
    movs	r0, #0
.Leu_08038C1A:
    cmp	r0, #0
    beq .Leu_08038C44
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_08038C44
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_08038C44:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #12]
    cmp	r0, #0
    beq .Leu_08038CDC
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #76]	@ 0x4c
    str	r1, [sp, #80]	@ 0x50
    adds	r0, r5, #0
    adds	r0, #81	@ 0x51
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #3
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, #240	@ 0xf0
    subs	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r5, #76]	@ 0x4c
    asrs	r0, r0, #16
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #76	@ 0x4c
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08038CB0
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Leu_08038CAC
    bl _call_via_r4
    b .Leu_08038CB2
    .align 2, 0
.Leu_08038CAC:
    .4byte func_030004DC
.Leu_08038CB0:
    movs	r0, #0
.Leu_08038CB2:
    cmp	r0, #0
    beq .Leu_08038CDC
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_08038CDC
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #0
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_08038CDC:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #16]
    cmp	r0, #0
    bne .Leu_08038CE6
    b .Leu_08038DF4
.Leu_08038CE6:
    str	r0, [sp, #120]	@ 0x78
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #84]	@ 0x54
    str	r1, [sp, #88]	@ 0x58
    movs	r2, #0
    str	r2, [sp, #124]	@ 0x7c
    ldr	r0, [sp, #120]	@ 0x78
    adds	r0, #20
    str	r0, [sp, #128]	@ 0x80
    ldr r1, .Leu_08038D7C
    str	r1, [sp, #132]	@ 0x84
    ldr	r5, [sp, #120]	@ 0x78
    adds	r5, #4
.Leu_08038D02:
    ldr	r2, [sp, #120]	@ 0x78
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r0, r2, r1
    ldr	r2, [sp, #124]	@ 0x7c
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Leu_08038DDC
    ldr	r1, [sp, #132]	@ 0x84
    ldrh	r0, [r1, #0]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    ldrh	r0, [r1, #2]
    ldr	r1, [sp, #100]	@ 0x64
    subs	r4, r0, r1
    adds	r6, r5, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #8
    mov	sl, r2
    add	r0, sp, #84	@ 0x54
    mov	r8, r0
    ldr	r1, [r5, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r5, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r8
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #0]
    ldr	r1, [r5, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08038D84
    ldrh	r0, [r5, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #128]	@ 0x80
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Leu_08038D80
    bl _call_via_r4
    b .Leu_08038D86
    .align 2, 0
.Leu_08038D7C:
    .4byte gUnk_080F165E
.Leu_08038D80:
    .4byte func_030004DC
.Leu_08038D84:
    movs	r0, #0
.Leu_08038D86:
    cmp	r0, #0
    beq .Leu_08038DDC
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Leu_08038DDC
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08038DBC
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_08038DD6
.Leu_08038DBC:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_08038DD6
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_08038DD6:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Leu_08038DDC:
    ldr	r2, [sp, #128]	@ 0x80
    adds	r2, #64	@ 0x40
    str	r2, [sp, #128]	@ 0x80
    ldr	r0, [sp, #132]	@ 0x84
    adds	r0, #4
    str	r0, [sp, #132]	@ 0x84
    adds	r5, #64	@ 0x40
    ldr	r1, [sp, #124]	@ 0x7c
    adds	r1, #1
    str	r1, [sp, #124]	@ 0x7c
    cmp	r1, #4
    bls .Leu_08038D02
.Leu_08038DF4:
    add	sp, #140	@ 0x8c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038DF0
    .thumb_func
func_08038DF0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #8
    mov	r8, r0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r7, r0, #0
    mov	r1, r8
    ldr	r0, [r1, #0]
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r7, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Leu_08038EA0
    str	r0, [r7, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #72	@ 0x48
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    movs	r0, #144	@ 0x90
    lsls	r0, r0, #17
    str	r0, [r7, #76]	@ 0x4c
    adds	r0, r7, #0
    adds	r0, #80	@ 0x50
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r2, [r0, #0]
    mov	r5, r8
    adds	r5, #12
    adds	r6, r7, #0
    mov	r0, r8
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Leu_08038E92
    cmp	r4, #0
    beq .Leu_08038E92
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Leu_08038E92:
    str	r6, [r5, #0]
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Leu_08038EA0:
    .4byte vtable_unk_080E602C
    .global func_08038E90
    .thumb_func
func_08038E90:
    ldr	r0, [r0, #12]
    movs	r1, #144	@ 0x90
    lsls	r1, r1, #17
    str	r1, [r0, #76]	@ 0x4c
    adds	r0, #80	@ 0x50
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .global func_08038EA0
    .thumb_func
func_08038EA0:
    push	{lr}
    ldr	r0, [r0, #12]
    movs	r1, #0
    adds	r0, #80	@ 0x50
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Leu_08038EC4
    movs	r1, #1
.Leu_08038EC4:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08038EB8
    .thumb_func
func_08038EB8:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    adds	r5, #12
    movs	r6, #0
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Leu_08038EEC
    cmp	r4, #0
    beq .Leu_08038EEC
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Leu_08038EEC:
    str	r6, [r5, #0]
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08038EE0
    .thumb_func
func_08038EE0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #76	@ 0x4c
    mov	r9, r0
    movs	r0, #166	@ 0xa6
    lsls	r0, r0, #1
    bl __builtin_new
    mov	r2, r9
    ldr	r1, [r2, #0]
    adds	r5, r0, #0
    ldr	r6, [r1, #0]
    movs	r0, #0
    str	r0, [r5, #0]
    mov	sl, r0
    add	r3, sp, #8
    mov	r8, r3
    mov	r7, sl
    lsls	r0, r7, #2
    ldr r1, .Leu_08038F28
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_08038F28:
    .4byte .Leu_08038F2C
.Leu_08038F2C:
    .4byte .Leu_08038F40
    .4byte .Leu_08038F60
    .4byte .Leu_08038F60
    .4byte .Leu_08038FF0
    .4byte .Leu_08038FF0
.Leu_08038F40:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FD09
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0xE00E2202
.Leu_08038F60:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FCF9
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332201
    .4byte 0xFD56F06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC78F0A3
    .4byte 0x62604813
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFBFEF06B
    .4byte 0x0000E046
    .4byte vtable_unk_080E681C
.Leu_08038FF0:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FCB1
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332200
    .4byte 0xFD0EF06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC30F0A3
    .4byte 0x6260482C
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFBB6F06B
    .4byte 0x004921A2
    .4byte 0x44501868
    .4byte 0x70012100
    .4byte 0x44922201
    .4byte 0x2B044653
    .4byte 0xE745D800
    .4byte 0x444F2710
    .4byte 0x1C2F46B8
    .4byte 0x69064648
    .4byte 0xD01442B7
    .4byte 0xD0122E00
    .4byte 0x01806830
    .4byte 0x18353004
    .4byte 0x42AC1D34
    .4byte 0x6A60D008
    .4byte 0x1C206882
    .4byte 0xF09A2102
    .4byte 0x3440FC51
    .4byte 0xD1F642AC
    .4byte 0xF7C71C30
    .4byte 0x4641FAA9
    .4byte 0xB013600F
    .4byte 0x4698BC38
    .4byte 0x46AA46A1
    .4byte 0xBC01BCF0
    .4byte 0x00004700
    .4byte vtable_unk_080E681C
    .global func_080390D0
    .thumb_func
func_080390D0:
    ldr	r1, [r0, #16]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    subs	r3, r1, #7
    strh	r3, [r0, #0]
    subs	r3, r2, #4
    strh	r3, [r0, #2]
    adds	r1, #7
    strh	r1, [r0, #4]
    adds	r2, #5
    strh	r2, [r0, #6]
    bx	lr
    .align 2, 0
    push	{lr}
    ldr	r0, [r0, #24]
    bl func_0800FFD0
    movs	r1, #0
    cmp	r0, #30
    bne .Leu_08039140
    movs	r1, #1
.Leu_08039140:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039134
    .thumb_func
func_08039134:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r6, r0, #0
    str	r1, [sp, #0]
    mov	sl, r2
    mov	r9, r3
    movs	r7, #100	@ 0x64
    movs	r0, #0
    mov	r8, r0
    movs	r5, #46	@ 0x2e
.Leu_08039164:
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r6, #0
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_080391BA
    ldrh	r0, [r4, #4]
    ldr	r1, [sp, #0]
    cmp	r0, r1
    bne .Leu_080391BA
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_080391BA
    movs	r2, #10
    ldrsh	r1, [r4, r2]
    mov	r0, sl
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    mov	r2, r9
    subs	r0, r0, r2
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r0, r1, r0
    adds	r1, r0, #0
    cmp	r7, #100	@ 0x64
    beq .Leu_080391B6
    cmp	r8, r0
    ble .Leu_080391BA
.Leu_080391B6:
    adds	r7, r5, #0
    mov	r8, r1
.Leu_080391BA:
    adds	r5, #1
    cmp	r5, #69	@ 0x45
    ble .Leu_08039164
    adds	r0, r7, #0
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391C0
    .thumb_func
func_080391C0:
    push	{lr}
    adds	r2, r0, #0
    cmp	r1, #56	@ 0x38
    bgt .Leu_080391E8
    ldr r0, .Leu_08039200
    cmp	r2, r0
    ble .Leu_080391E8
    adds	r0, #33	@ 0x21
    cmp	r2, r0
    ble .Leu_080391FA
.Leu_080391E8:
    ldr r0, .Leu_08039204
    cmp	r1, r0
    ble .Leu_08039208
    cmp	r2, #247	@ 0xf7
    ble .Leu_08039208
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #1
    cmp	r2, r0
    bgt .Leu_08039208
.Leu_080391FA:
    movs	r0, #1
    b .Leu_0803920A
    .align 2, 0
.Leu_08039200:
    .4byte 0x00000143
.Leu_08039204:
    .4byte 0x0000027F
.Leu_08039208:
    movs	r0, #0
.Leu_0803920A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391FC
    .thumb_func
func_080391FC:
    bx	lr
    .align 2, 0
    .global func_08039200
    .thumb_func
func_08039200:
    movs	r0, #0
    bx	lr
    .global func_08039204
    .thumb_func
func_08039204:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r5, r1, #0
    str	r2, [sp, #16]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r1, r8
    adds	r1, #16
    str	r1, [sp, #20]
    mov	r2, r8
    ldrh	r4, [r2, #16]
    cmp	r4, #0
    beq .Leu_0803923C
    subs	r4, #1
.Leu_0803923C:
    ldrh	r3, [r5, #4]
    mov	ip, r3
    movs	r1, #10
    ldrsh	r0, [r5, r1]
    mov	r9, r0
    movs	r2, #14
    ldrsh	r7, [r5, r2]
    movs	r0, #176	@ 0xb0
    lsls	r0, r0, #1
    cmp	r7, r0
    ble .Leu_0803925E
    add	r3, sp, #8
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Leu_08039268
.Leu_0803925E:
    add	r3, sp, #8
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Leu_08039268:
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    add	r1, sp, #8
    adds	r0, r1, #0
    movs	r2, #0
    ldrsh	r3, [r0, r2]
    mov	sl, r3
    movs	r3, #2
    ldrsh	r6, [r1, r3]
    mov	r0, ip
    cmp	r0, #2
    bne .Leu_080392FE
    mov	r1, sl
    mov	r2, r9
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Leu_0803928E
    negs	r0, r0
.Leu_0803928E:
    cmp	r0, #15
    bgt .Leu_0803929E
    subs	r0, r6, r7
    cmp	r0, #0
    bge .Leu_0803929A
    negs	r0, r0
.Leu_0803929A:
    cmp	r0, #15
    ble .Leu_080392FE
.Leu_0803929E:
    cmp	r4, #0
    bne .Leu_080392F8
    mov	r0, r9
    adds	r1, r7, #0
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_080392CA
    movs	r1, #0
    cmp	r7, r6
    blt .Leu_080392B8
    movs	r1, #1
.Leu_080392B8:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Leu_080392F0
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Leu_080392F0
.Leu_080392CA:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r3, [sp, #16]
    str	r3, [sp, #0]
    str	r0, [sp, #4]
    mov	r0, r9
    adds	r1, r7, #0
    mov	r2, sl
    adds	r3, r6, #0
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_080392F0
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_080392F0:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Leu_080392F8:
    ldr	r0, [sp, #20]
    strh	r4, [r0, #0]
    b .Leu_08039310
.Leu_080392FE:
    adds	r0, r5, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
    add	r1, sp, #12
    mov	r0, r8
    bl func_0809C098
.Leu_08039310:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803930C
    .thumb_func
func_0803930C:
    movs	r0, #1
    bx	lr
    .global func_08039310
    .thumb_func
func_08039310:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    adds	r5, r1, #0
    str	r2, [sp, #28]
    ldr	r0, [r5, #52]	@ 0x34
    str	r0, [sp, #32]
    adds	r0, #16
    mov	r8, r0
    ldr	r3, [r5, #0]
    ldrb	r1, [r0, #6]
    str	r1, [sp, #36]	@ 0x24
    ldr	r2, [sp, #32]
    ldrh	r6, [r2, #16]
    cmp	r6, #0
    beq .Leu_08039358
    subs	r6, #1
    cmp	r6, #0
    bne .Leu_08039358
    cmp	r1, #0
    beq .Leu_08039358
    subs	r1, #1
    str	r1, [sp, #36]	@ 0x24
.Leu_08039358:
    ldr	r0, [r3, #0]
    mov	r2, r8
    ldrb	r1, [r2, #7]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    bne .Leu_0803936E
    b .Leu_0803949C
.Leu_0803936E:
    ldrh	r0, [r4, #4]
    ldrh	r3, [r5, #4]
    cmp	r0, r3
    beq .Leu_08039378
    b .Leu_0803949C
.Leu_08039378:
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803938A
    b .Leu_0803949C
.Leu_0803938A:
    movs	r0, #10
    ldrsh	r2, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    movs	r0, #10
    ldrsh	r3, [r4, r0]
    mov	sl, r3
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r9, r1
    ldr	r0, [sp, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_08039458
    mov	r1, sl
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Leu_080393AE
    negs	r0, r0
.Leu_080393AE:
    cmp	r0, #15
    bgt .Leu_080393C0
    mov	r3, r9
    subs	r0, r3, r7
    cmp	r0, #0
    bge .Leu_080393BC
    negs	r0, r0
.Leu_080393BC:
    cmp	r0, #15
    ble .Leu_08039458
.Leu_080393C0:
    cmp	r6, #0
    beq .Leu_080393E8
    mov	r1, r8
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Leu_080393D2
    negs	r0, r0
.Leu_080393D2:
    cmp	r0, #15
    bgt .Leu_0803944C
    mov	r1, r8
    movs	r3, #4
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r7
    cmp	r0, #0
    bge .Leu_080393E4
    negs	r0, r0
.Leu_080393E4:
    cmp	r0, #15
    bgt .Leu_0803944C
.Leu_080393E8:
    adds	r0, r2, #0
    adds	r1, r7, #0
    str	r2, [sp, #40]	@ 0x28
    bl func_080391C0
    lsls	r0, r0, #24
    ldr	r2, [sp, #40]	@ 0x28
    cmp	r0, #0
    beq .Leu_08039414
    movs	r1, #0
    cmp	r7, r9
    blt .Leu_08039402
    movs	r1, #1
.Leu_08039402:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Leu_0803943A
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Leu_0803943A
.Leu_08039414:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r6, [sp, #28]
    str	r6, [sp, #0]
    str	r0, [sp, #4]
    adds	r0, r2, #0
    adds	r1, r7, #0
    mov	r2, sl
    mov	r3, r9
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Leu_0803943A
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_0803943A:
    movs	r0, #30
    bl func_080AB788
    adds	r6, r0, #1
    mov	r1, sl
    mov	r0, r8
    strh	r1, [r0, #2]
    mov	r2, r9
    strh	r2, [r0, #4]
.Leu_0803944C:
    add	r3, sp, #36	@ 0x24
    ldrb	r0, [r3, #0]
    mov	r3, r8
    strb	r0, [r3, #6]
    strh	r6, [r3, #0]
    b .Leu_0803955C
.Leu_08039458:
    ldr r1, .Leu_08039490
    ldr	r0, [sp, #8]
    ands	r0, r1
    movs	r1, #36	@ 0x24
    orrs	r0, r1
    ldr r1, .Leu_08039494
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #9
    orrs	r0, r1
    str	r0, [sp, #8]
    mov	r6, r8
    ldrb	r1, [r6, #7]
    lsls	r1, r1, #24
    ldr r2, .Leu_08039498
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #8]
    ldr	r0, [sp, #32]
    add	r1, sp, #8
    bl func_0809C0BC
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
    b .Leu_0803955C
    .align 2, 0
.Leu_08039490:
    .4byte 0xFFFF0000
.Leu_08039494:
    .4byte 0xFF00FFFF
.Leu_08039498:
    .4byte 0x00FFFFFF
.Leu_0803949C:
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Leu_080394BE
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Leu_080394C6
.Leu_080394BE:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Leu_080394C6:
    cmp	r6, #100	@ 0x64
    beq .Leu_08039548
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Leu_08039510
    ldr r1, .Leu_08039504
    ldr	r0, [sp, #12]
    ands	r0, r1
    str	r0, [sp, #12]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Leu_08039508
    add	r1, sp, #12
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    lsls	r3, r6, #24
    ldr r0, .Leu_0803950C
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    adds	r0, r4, #0
    bl func_0809C0AC
    b .Leu_0803955C
.Leu_08039504:
    .4byte 0xFFFF0000
.Leu_08039508:
    .4byte 0xFF00FFFF
.Leu_0803950C:
    .4byte 0x00FFFFFF
.Leu_08039510:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_0803953C
    ldr	r1, [sp, #20]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_08039540
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Leu_08039544
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Leu_0803955C
.Leu_0803953C:
    .4byte 0xFFFF0000
.Leu_08039540:
    .4byte 0xFF00FFFF
.Leu_08039544:
    .4byte 0x00FFFFFF
.Leu_08039548:
    ldr r1, .Leu_0803956C
    ldr	r0, [sp, #24]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #24]
    add	r1, sp, #24
    adds	r0, r4, #0
    bl func_0809C0A0
.Leu_0803955C:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Leu_0803956C:
    .4byte 0xFFFF0000
    .global func_0803955C
    .thumb_func
func_0803955C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #16
    adds	r5, r1, #0
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r6, r8
    adds	r6, #16
    mov	r1, r8
    ldrh	r4, [r1, #16]
    cmp	r4, #0
    beq .Leu_08039596
    subs	r4, #1
    cmp	r4, #0
    beq .Leu_08039596
    b .Leu_080396F6
.Leu_08039596:
    ldrb	r0, [r6, #2]
    cmp	r0, #0
    bne .Leu_0803959E
    b .Leu_080396E8
.Leu_0803959E:
    ldr	r4, [r5, #0]
    ldrh	r7, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    mov	r9, r2
    movs	r1, #14
    ldrsh	r0, [r5, r1]
    mov	sl, r0
    adds	r0, r4, #0
    adds	r1, r7, #0
    mov	r3, sl
    bl func_08039134
    adds	r1, r0, #0
    cmp	r1, #100	@ 0x64
    bne .Leu_080395C0
    ldrb	r1, [r6, #3]
.Leu_080395C0:
    ldr	r0, [r4, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r4, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_08039616
    ldrh	r0, [r4, #4]
    cmp	r0, r7
    bne .Leu_08039616
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08039616
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r6, r9
    subs	r0, r0, r6
    cmp	r0, #0
    bge .Leu_080395F8
    negs	r0, r0
.Leu_080395F8:
    cmp	r0, #15
    bgt .Leu_08039616
    mov	r0, sl
    subs	r3, r1, r0
    cmp	r3, #0
    bge .Leu_08039606
    negs	r3, r3
.Leu_08039606:
    cmp	r3, #15
    bgt .Leu_08039616
    ldr	r0, [r4, #20]
    adds	r0, #128	@ 0x80
    ldr	r1, [r0, #0]
    adds	r0, r4, #0
    bl _call_via_r1
.Leu_08039616:
    mov	r0, r8
    movs	r1, #4
    bl func_0809C068
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Leu_08039640
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Leu_08039648
.Leu_08039640:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Leu_08039648:
    cmp	r6, #100	@ 0x64
    beq .Leu_080396CC
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Leu_08039694
    ldr r1, .Leu_08039688
    ldr	r0, [sp, #0]
    ands	r0, r1
    str	r0, [sp, #0]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Leu_0803968C
    ldr	r1, [sp, #4]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Leu_08039690
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #4]
    adds	r0, r4, #0
    mov	r1, sp
    bl func_0809C0AC
    b .Leu_080396F8
    .align 2, 0
.Leu_08039688:
    .4byte 0xFFFF0000
.Leu_0803968C:
    .4byte 0xFF00FFFF
.Leu_08039690:
    .4byte 0x00FFFFFF
.Leu_08039694:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_080396C0
    ldr	r1, [sp, #8]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_080396C4
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Leu_080396C8
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #8]
    add	r1, sp, #8
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Leu_080396F8
.Leu_080396C0:
    .4byte 0xFFFF0000
.Leu_080396C4:
    .4byte 0xFF00FFFF
.Leu_080396C8:
    .4byte 0x00FFFFFF
.Leu_080396CC:
    ldr r1, .Leu_080396E4
    ldr	r0, [sp, #12]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #12]
    add	r1, sp, #12
    adds	r0, r4, #0
    bl func_0809C0A0
    b .Leu_080396F8
    .align 2, 0
.Leu_080396E4:
    .4byte 0xFFFF0000
.Leu_080396E8:
    movs	r4, #36	@ 0x24
    movs	r0, #1
    strb	r0, [r6, #2]
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Leu_080396F6:
    strh	r4, [r6, #0]
.Leu_080396F8:
    add	sp, #16
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_080396F4
    .thumb_func
func_080396F4:
    push	{lr}
    ldr	r0, [r1, #52]	@ 0x34
    ldrb	r0, [r0, #18]
    movs	r1, #0
    cmp	r0, #0
    beq .Leu_08039716
    movs	r1, #3
.Leu_08039716:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .global func_08039708
    .thumb_func
func_08039708:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r6, r1, #0
    mov	sl, r2
    ldr	r0, [r6, #52]	@ 0x34
    movs	r1, #16
    adds	r1, r1, r0
    mov	r9, r1
    ldr	r3, [r6, #0]
    ldrh	r2, [r0, #16]
    mov	r8, r2
    cmp	r2, #0
    beq .Leu_08039744
    movs	r4, #1
    negs	r4, r4
    add	r8, r4
.Leu_08039744:
    ldr	r1, [r0, #16]
    lsls	r0, r1, #9
    lsrs	r7, r0, #25
    cmp	r7, #0
    beq .Leu_08039750
    subs	r7, #1
.Leu_08039750:
    mov	r5, r9
    ldrb	r4, [r5, #3]
    cmp	r4, #0
    beq .Leu_0803975A
    subs	r4, #1
.Leu_0803975A:
    mov	r0, r8
    cmp	r0, #0
    beq .Leu_080397DA
    ldr	r2, [r3, #0]
    lsls	r0, r1, #8
    movs	r1, #0
    cmp	r0, #0
    bge .Leu_0803976C
    movs	r1, #43	@ 0x2b
.Leu_0803976C:
    ldr	r2, [r2, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Leu_080397DA
    ldrh	r0, [r3, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Leu_080397DA
    cmp	r4, #0
    bne .Leu_080397C0
    movs	r2, #10
    ldrsh	r0, [r6, r2]
    movs	r4, #14
    ldrsh	r1, [r6, r4]
    movs	r5, #10
    ldrsh	r2, [r3, r5]
    movs	r4, #14
    ldrsh	r3, [r3, r4]
    adds	r5, r6, #0
    adds	r5, #32
    ldrb	r4, [r5, #0]
    mov	ip, r4
    mov	r4, sl
    str	r4, [sp, #0]
    mov	r4, ip
    str	r4, [sp, #4]
    bl func_080ABE58
    adds	r1, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r0, r1
    beq .Leu_080397B8
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_080397B8:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Leu_080397C0:
    mov	r0, r8
    mov	r5, r9
    strh	r0, [r5, #0]
    movs	r0, #127	@ 0x7f
    ands	r7, r0
    ldrb	r1, [r5, #2]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r7
    strb	r0, [r5, #2]
    strb	r4, [r5, #3]
    b .Leu_080398A0
.Leu_080397DA:
    adds	r0, r6, #0
    bl func_080323C8
    ldr	r4, [r6, #52]	@ 0x34
    movs	r5, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Leu_08039802
    ldr	r0, [r6, #0]
    ldrh	r1, [r6, #4]
    movs	r3, #10
    ldrsh	r2, [r6, r3]
    movs	r5, #14
    ldrsh	r3, [r6, r5]
    bl func_08039134
    adds	r5, r0, #0
    b .Leu_0803980A
.Leu_08039802:
    adds	r0, r6, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Leu_0803980A:
    cmp	r5, #100	@ 0x64
    beq .Leu_0803988C
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Leu_08039854
    ldr r1, .Leu_08039848
    ldr	r0, [sp, #8]
    ands	r0, r1
    str	r0, [sp, #8]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Leu_0803984C
    ldr	r1, [sp, #12]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Leu_08039850
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #12]
    adds	r0, r4, #0
    add	r1, sp, #8
    bl func_0809C0AC
    b .Leu_080398A0
.Leu_08039848:
    .4byte 0xFFFF0000
.Leu_0803984C:
    .4byte 0xFF00FFFF
.Leu_08039850:
    .4byte 0x00FFFFFF
.Leu_08039854:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_08039880
    ldr	r1, [sp, #16]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_08039884
    ands	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Leu_08039888
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #16]
    add	r1, sp, #16
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Leu_080398A0
.Leu_08039880:
    .4byte 0xFFFF0000
.Leu_08039884:
    .4byte 0xFF00FFFF
.Leu_08039888:
    .4byte 0x00FFFFFF
.Leu_0803988C:
    ldr r1, .Leu_080398B0
    ldr	r0, [sp, #20]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0A0
.Leu_080398A0:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Leu_080398B0:
    .4byte 0xFFFF0000
    .global func_080398A0
    .thumb_func
func_080398A0:
    movs	r0, #2
    bx	lr
    .global func_080398A4
    .thumb_func
func_080398A4:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r0, sp
    adds	r1, r5, #0
    bl __5ActorRC5Actor
    ldr r3, .Leu_080399B8
    adds	r0, r6, #0
    adds	r1, r4, #0
    mov	r2, sp
    bl func_08020038
    ldr r0, .Leu_080399BC
    str	r0, [r6, #20]
    str	r5, [r6, #52]	@ 0x34
    adds	r1, r6, #0
    adds	r1, #56	@ 0x38
    movs	r0, #4
    movs	r3, #0
    movs	r2, #1
    negs	r2, r2
.Leu_080398E8:
    stmia	r1!, {r3}
    subs	r0, #1
    cmp	r0, r2
    bne .Leu_080398E8
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Leu_080399C0
    str	r0, [r4, #0]
    ldr	r0, [r6, #56]	@ 0x38
    cmp	r4, r0
    beq .Leu_08039906
    bl __builtin_delete
.Leu_08039906:
    str	r4, [r6, #56]	@ 0x38
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Leu_080399C4
    str	r0, [r4, #0]
    ldr	r0, [r6, #60]	@ 0x3c
    cmp	r4, r0
    beq .Leu_0803991E
    bl __builtin_delete
.Leu_0803991E:
    str	r4, [r6, #60]	@ 0x3c
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Leu_080399C8
    str	r0, [r4, #0]
    ldr	r0, [r6, #64]	@ 0x40
    cmp	r4, r0
    beq .Leu_08039936
    bl __builtin_delete
.Leu_08039936:
    str	r4, [r6, #64]	@ 0x40
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Leu_080399CC
    str	r0, [r4, #0]
    ldr	r0, [r6, #68]	@ 0x44
    cmp	r4, r0
    beq .Leu_0803994E
    bl __builtin_delete
.Leu_0803994E:
    str	r4, [r6, #68]	@ 0x44
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Leu_080399D0
    str	r0, [r4, #0]
    ldr	r0, [r6, #72]	@ 0x48
    cmp	r4, r0
    beq .Leu_08039966
    bl __builtin_delete
.Leu_08039966:
    str	r4, [r6, #72]	@ 0x48
    ldr	r0, [r6, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r6
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08020080
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080399A4
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Leu_080399A4:
    str	r4, [r6, #76]	@ 0x4c
    adds	r0, r6, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [r6, #80]	@ 0x50
    adds	r0, r6, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Leu_080399B8:
    .4byte 0x000009C7
.Leu_080399BC:
    .4byte vtable_unk_080E74DC
.Leu_080399C0:
    .4byte vtable_unk_080E74CC
.Leu_080399C4:
    .4byte vtable_unk_080E74BC
.Leu_080399C8:
    .4byte vtable_unk_080E74AC
.Leu_080399CC:
    .4byte vtable_unk_080E749C
.Leu_080399D0:
    .4byte vtable_unk_080E748C
    .global func_080399C0
    .thumb_func
func_080399C0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r7, r1, #0
    ldr r0, .Leu_08039A3C
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__5ActorRC13ActorLocation
    adds	r0, r5, #0
    adds	r0, #56	@ 0x38
    cmp	r0, #0
    beq .Leu_08039A10
    adds	r4, r5, #0
    adds	r4, #76	@ 0x4c
    cmp	r0, r4
    beq .Leu_08039A10
    adds	r6, r0, #0
.Leu_08039A04:
    subs	r4, #4
    ldr	r0, [r4, #0]
    bl __builtin_delete
    cmp	r6, r4
    bne .Leu_08039A04
.Leu_08039A10:
    ldr r0, .Leu_08039A40
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_08039A26
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_08039A26:
    movs	r0, #1
    ands	r0, r7
    cmp	r0, #0
    beq .Leu_08039A34
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_08039A34:
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Leu_08039A3C:
    .4byte vtable_unk_080E74DC
.Leu_08039A40:
    .4byte __vt_7AEntity
    .global func_08039A30
    .thumb_func
func_08039A30:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08039A5C
    .thumb_func
func_08039A5C:
    bx	lr
    .align 2, 0
    .global func_08039A60
    .thumb_func
func_08039A60:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #112	@ 0x70
    adds	r7, r0, #0
    ldr	r0, [r7, #0]
    mov	sl, r0
    ldrb	r0, [r1, #4]
    cmp	r0, #0
    bne .Leu_08039A8E
    b .Leu_08039BC0
.Leu_08039A8E:
    ldrh	r0, [r7, #4]
    cmp	r0, #2
    bne .Leu_08039A96
    b .Leu_08039BC0
.Leu_08039A96:
    mov	r1, sl
    ldr	r0, [r1, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r0, r2
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrh	r1, [r2, #10]
    ldr r0, .Leu_08039AD4
    ands	r0, r1
    cmp	r0, #20
    beq .Leu_08039AB6
    b .Leu_08039BC0
.Leu_08039AB6:
    ldr	r0, [r2, #0]
    cmp	r0, #0
    beq .Leu_08039ABE
    b .Leu_08039BC0
.Leu_08039ABE:
    movs	r0, #2
    bl func_080AB788
    cmp	r0, #0
    beq .Leu_08039AD8
    add	r0, sp, #68	@ 0x44
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Leu_08039AE2
.Leu_08039AD4:
    .4byte 0x000007FF
.Leu_08039AD8:
    add	r0, sp, #68	@ 0x44
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Leu_08039AE2:
    strh	r1, [r0, #0]
    strh	r2, [r0, #2]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [sp, #72]	@ 0x48
    add	r4, sp, #72	@ 0x48
    movs	r3, #0
    ldrsh	r2, [r4, r3]
    movs	r6, #2
    ldrsh	r3, [r4, r6]
    mov	r0, sl
    movs	r1, #2
    bl func_08039134
    str	r0, [sp, #108]	@ 0x6c
    cmp	r0, #100	@ 0x64
    beq .Leu_08039BC0
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #14
    bhi .Leu_08039BC0
    movs	r0, #0
    ldrsh	r6, [r4, r0]
    movs	r2, #2
    ldrsh	r1, [r4, r2]
    mov	r8, r1
    mov	r3, sp
    movs	r2, #2
    ldrh	r1, [r3, #0]
    ldr r4, .Leu_08039D2C
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #0]
    lsls	r6, r6, #16
    lsrs	r1, r6, #16
    movs	r0, #63	@ 0x3f
    mov	r9, r0
    ands	r1, r0
    lsls	r1, r1, #2
    ldrb	r5, [r3, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r5
    orrs	r0, r1
    strb	r0, [r3, #1]
    lsrs	r6, r6, #22
    ldrh	r1, [r3, #2]
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r6
    strh	r0, [r3, #2]
    mov	r1, r8
    lsls	r1, r1, #16
    mov	r8, r1
    lsrs	r0, r1, #16
    mov	r6, r9
    ands	r0, r6
    lsls	r0, r0, #2
    ldrb	r1, [r3, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r3, #3]
    mov	r0, r8
    lsrs	r0, r0, #22
    mov	r8, r0
    ldrh	r0, [r3, #4]
    ands	r4, r0
    mov	r1, r8
    orrs	r4, r1
    strh	r4, [r3, #4]
    add	r4, sp, #8
    movs	r5, #1
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    strb	r5, [r4, #6]
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__12AActorEntityRC13ActorLocation
    ldr r1, .Leu_08039D30
    ldr	r0, [sp, #76]	@ 0x4c
    ands	r0, r1
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Leu_08039D34
    add	r1, sp, #76	@ 0x4c
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    ldr	r6, [sp, #108]	@ 0x6c
    lsls	r3, r6, #24
    ldr r0, .Leu_08039D38
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    ldr	r0, [r7, #52]	@ 0x34
    bl func_0809C0AC
    adds	r0, r7, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Leu_08039BC0:
    ldrh	r5, [r7, #4]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    cmp	r5, r0
    bne .Leu_08039BCC
    b .Leu_08039D1A
.Leu_08039BCC:
    mov	r0, sl
    ldr	r1, [r0, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    mov	r1, sl
    adds	r2, r5, #0
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #84	@ 0x54
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    add	r4, sp, #16
    movs	r1, #32
    mov	r8, r1
    movs	r2, #0
    mov	r9, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #16]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #36	@ 0x24
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #84]	@ 0x54
    ldr	r1, [sp, #88]	@ 0x58
    str	r0, [sp, #48]	@ 0x30
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r8
    str	r3, [r4, #40]	@ 0x28
    mov	r6, r9
    str	r6, [r4, #44]	@ 0x2c
    str	r6, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r8, r4
    cmp	r3, #0
    beq .Leu_08039C4C
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Leu_08039C4C
    ldr	r1, [r3, #20]
    add	r4, sp, #92	@ 0x5c
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Leu_08039C4C:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Leu_08039C7C
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Leu_08039C7C
    ldr	r1, [r3, #20]
    add	r4, sp, #100	@ 0x64
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Leu_08039C7C:
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #8]
    adds	r1, r7, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r5, [r0, #0]
    ldr	r1, [r7, #76]	@ 0x4c
    adds	r6, r0, #0
    cmp	r4, r1
    bne .Leu_08039CBC
    ldr	r0, [r7, #80]	@ 0x50
    cmp	r5, r0
    beq .Leu_08039CCC
.Leu_08039CBC:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r7, #0
    bl func_08020080
.Leu_08039CCC:
    ldr	r0, [r7, #76]	@ 0x4c
    cmp	r4, r0
    beq .Leu_08039CE8
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_08039CE8
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Leu_08039CE8:
    str	r4, [r7, #76]	@ 0x4c
    str	r5, [r7, #80]	@ 0x50
    mov	r4, r8
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    ldrb	r1, [r6, #0]
    subs	r0, #1
    cmp	r0, #1
    bhi .Leu_08039D12
    cmp	r1, #1
    bhi .Leu_08039D12
    movs	r1, #10
    ldrsh	r0, [r7, r1]
    movs	r2, #14
    ldrsh	r1, [r7, r2]
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08039D12
    movs	r4, #0
.Leu_08039D12:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08020170
.Leu_08039D1A:
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_08039D3C
    subs	r0, #1
    b .Leu_08039D3E
.Leu_08039D2C:
    .4byte 0xFFFFFC00
.Leu_08039D30:
    .4byte 0xFFFF0000
.Leu_08039D34:
    .4byte 0xFF00FFFF
.Leu_08039D38:
    .4byte 0x00FFFFFF
.Leu_08039D3C:
    ldrh	r0, [r7, #38]	@ 0x26
.Leu_08039D3E:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Leu_08039D50
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Leu_08039D50:
    add	sp, #112	@ 0x70
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08039D4C
    .thumb_func
func_08039D4C:
    ldr r0, .Leu_08039D6C
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Leu_08039D6C:
    .4byte gUnk_080F16AE
    .global func_08039D5C
    .thumb_func
func_08039D5C:
    push	{lr}
    cmp	r1, #4
    bhi .Leu_08039DA4
    lsls	r0, r1, #2
    ldr r1, .Leu_08039D80
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_08039D80:
    .4byte .Leu_08039D84
.Leu_08039D84:
    .4byte .Leu_08039DA4
    .4byte .Leu_08039D98
    .4byte .Leu_08039D9E
    .4byte .Leu_08039DA4
    .4byte .Leu_08039DA4
.Leu_08039D98:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE003
.Leu_08039D9E:
    .hword 0x2080
    .4byte 0xE0000240
.Leu_08039DA4:
    movs	r0, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039D98
    .thumb_func
func_08039D98:
    ldr	r0, [r0, #52]	@ 0x34
    ldr	r1, [r0, #12]
    movs	r0, #4
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .global func_08039DA8
    .thumb_func
func_08039DA8:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Leu_08039E14
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_08039E1C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_08039E20
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    ldr r0, .Leu_08039E24
    ands	r1, r0
    ldr r0, .Leu_08039E28
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #15
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Leu_08039E14:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
.Leu_08039E1C:
    .4byte 0xFFFF0000
.Leu_08039E20:
    .4byte 0xFF80FFFF
.Leu_08039E24:
    .4byte 0xFF7FFFFF
.Leu_08039E28:
    .4byte 0x00FFFFFF
    .global func_08039E18
    .thumb_func
func_08039E18:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Leu_08039E86
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_08039E90
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_08039E94
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #16
    orrs	r1, r0
    ldr r0, .Leu_08039E98
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #4
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Leu_08039E86:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08039E90:
    .4byte 0xFFFF0000
.Leu_08039E94:
    .4byte 0xFF80FFFF
.Leu_08039E98:
    .4byte 0x00FFFFFF
    .global func_08039E88
    .thumb_func
func_08039E88:
    movs	r0, #2
    bx	lr
    ldr	r1, [r0, #52]	@ 0x34
    ldr	r1, [r1, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r0, [r1, #56]	@ 0x38
    bx	lr
    .global func_08039E98
    .thumb_func
func_08039E98:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r6, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    ldr r0, .Leu_08039F44
    str	r0, [r7, #76]	@ 0x4c
    str	r6, [r7, #0]
    movs	r4, #0
    strh	r5, [r7, #4]
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r0, r7, #0
    adds	r0, #8
    movs	r2, #3
    str	r2, [sp, #0]
    movs	r2, #27
    str	r2, [sp, #4]
    add	r2, sp, #8
    strb	r4, [r2, #0]
    adds	r2, r5, #0
    adds	r3, r6, #0
    bl func_080A4A00
    mov	r0, r9
    cmp	r0, #1
    bne .Leu_08039F50
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r5, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r4, r0, #0
    adds	r0, r5, #0
    adds	r1, r6, #0
    movs	r2, #2
    movs	r3, #15
    bl func_080A4740
    ldr r0, .Leu_08039F48
    str	r0, [r5, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r5
    mov	r8, r1
    ldr	r6, [r4, #0]
    add	r0, sp, #12
    ldr	r3, [r6, #12]
    adds	r1, r4, #0
    ldr r2, .Leu_08039F4C
    bl _call_via_r3
    ldr	r0, [sp, #12]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r6, #16]
    adds	r1, r4, #0
    bl _call_via_r3
    adds	r0, r5, #0
    adds	r0, #72	@ 0x48
    mov	r1, r9
    strb	r1, [r0, #0]
    b .Leu_08039F52
    .align 2, 0
.Leu_08039F44:
    .4byte vtable_unk_080E76BC
.Leu_08039F48:
    .4byte vtable_unk_080E602C
.Leu_08039F4C:
    .4byte 0x0000091A
.Leu_08039F50:
    movs	r5, #0
.Leu_08039F52:
    str	r5, [r7, #72]	@ 0x48
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08039F50
    .thumb_func
func_08039F50:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldr r0, .Leu_08039FA0
    str	r0, [r4, #76]	@ 0x4c
    ldr	r1, [r4, #72]	@ 0x48
    cmp	r1, #0
    beq .Leu_08039F80
    ldr	r0, [r1, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_08039F80:
    adds	r0, r4, #0
    adds	r0, #8
    movs	r1, #2
    bl func_080A47B4
    movs	r0, #1
    ands	r0, r5
    cmp	r0, #0
    beq .Leu_08039F98
    adds	r0, r4, #0
    bl __builtin_delete
.Leu_08039F98:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08039FA0:
    .4byte vtable_unk_080E76BC
    .global func_08039F90
    .thumb_func
func_08039F90:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    mov	sl, r0
    adds	r4, r1, #0
    mov	r9, r2
    mov	r8, r3
    ldr	r5, [sp, #104]	@ 0x68
    ldr	r6, [sp, #108]	@ 0x6c
    ldr	r7, [sp, #112]	@ 0x70
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #24]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r5, r5, r0
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #28]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r0, r6, r0
    str	r0, [sp, #64]	@ 0x40
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r6
    str	r0, [sp, #68]	@ 0x44
    add	r0, sp, #52	@ 0x34
    mov	r1, r8
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r9
    str	r3, [r0, #4]
    adds	r5, r7, #0
    mov	r9, r0
    cmp	r5, #0
    bge .Leu_08039FF6
    negs	r7, r5
.Leu_08039FF6:
    ldr	r4, [sp, #64]	@ 0x40
    subs	r4, r4, r7
    mov	r8, r4
    mov	r6, sl
    adds	r6, #8
    movs	r0, #3
    ldr	r7, [sp, #116]	@ 0x74
    ands	r0, r7
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    mov	r0, sl
    ldr	r1, [r0, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r0, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r9
    ldr	r1, [r1, #4]
    mov	ip, r1
    mov	r3, sl
    ldr	r2, [r3, #8]
    ldr	r1, [r3, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_0803A068
    ldrh	r0, [r6, #12]
    mov	r1, sl
    adds	r1, #24
    ldr	r3, [sp, #68]	@ 0x44
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    ldr	r1, [sp, #60]	@ 0x3c
    mov	r2, r8
    adds	r3, r4, #0
    ldr r4, .Leu_0803A064
    bl _call_via_r4
    b .Leu_0803A06A
.Leu_0803A064:
    .4byte func_030004DC
.Leu_0803A068:
    movs	r0, #0
.Leu_0803A06A:
    cmp	r0, #0
    beq .Leu_0803A0BE
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r8, r0
    cmp	r1, #0
    beq .Leu_0803A0BE
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_0803A09E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_0803A0B8
.Leu_0803A09E:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_0803A0B8
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_0803A0B8:
    movs	r0, #0
    mov	r4, r8
    strb	r0, [r4, #0]
.Leu_0803A0BE:
    mov	r7, sl
    ldr	r0, [r7, #72]	@ 0x48
    cmp	r0, #0
    beq .Leu_0803A148
    cmp	r5, #0
    blt .Leu_0803A148
    adds	r6, r0, #0
    mov	r5, r9
    movs	r0, #3
    ldr	r1, [sp, #116]	@ 0x74
    ands	r0, r1
    lsls	r3, r0, #2
    orrs	r3, r0
    lsls	r1, r0, #4
    orrs	r3, r1
    lsls	r0, r0, #6
    orrs	r3, r0
    adds	r7, r6, #0
    adds	r7, #40	@ 0x28
    ldr	r4, [r5, #4]
    mov	r8, r4
    adds	r0, r6, #0
    ldmia	r0!, {r2}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_0803A11C
    ldrh	r0, [r6, #12]
    adds	r1, r6, #0
    adds	r1, #16
    ldr	r4, [sp, #68]	@ 0x44
    str	r4, [sp, #0]
    str	r7, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r8
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #64]	@ 0x40
    ldr r4, .Leu_0803A118
    bl _call_via_r4
    b .Leu_0803A11E
    .align 2, 0
.Leu_0803A118:
    .4byte func_030004DC
.Leu_0803A11C:
    movs	r0, #0
.Leu_0803A11E:
    cmp	r0, #0
    beq .Leu_0803A148
    adds	r4, r6, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_0803A148
    ldr	r1, [r5, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_0803A148:
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803A144
    .thumb_func
func_0803A144:
    push	{r4, lr}
    adds	r4, r1, #0
    lsls	r2, r2, #24
    lsrs	r0, r2, #24
    cmp	r2, #0
    bge .Leu_0803A16E
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
.Leu_0803A16E:
    ldr r2, .Leu_0803A190
    lsls	r0, r0, #24
    asrs	r0, r0, #24
    lsls	r1, r0, #2
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #4]
    lsls	r1, r0, #1
    adds	r1, #1
    lsls	r1, r1, #1
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #6]
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803A190:
    .4byte gUnk_080F16C2
    .global func_0803A180
    .thumb_func
func_0803A180:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #72	@ 0x48
    mov	r8, r0
    adds	r4, r1, #0
    adds	r5, r2, #0
    movs	r0, #0
    mov	r9, r0
    mov	r2, r8
    ldr	r1, [r2, #0]
    ldr	r2, [r1, #0]
    mov	r0, sp
    ldr	r3, [r2, #52]	@ 0x34
    movs	r2, #0
    bl _call_via_r3
    movs	r6, #4
    ldrsh	r1, [r4, r6]
    movs	r7, #6
    ldrsh	r3, [r4, r7]
    add	r2, sp, #64	@ 0x40
    adds	r0, r1, #0
    subs	r0, #8
    strh	r0, [r2, #0]
    adds	r0, r3, #0
    subs	r0, #8
    strh	r0, [r2, #2]
    adds	r1, #8
    strh	r1, [r2, #4]
    adds	r3, #8
    strh	r3, [r2, #6]
    add	r3, sp, #12
    movs	r0, #32
    mov	ip, r0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    subs	r0, #65	@ 0x41
    str	r0, [r3, #4]
    str	r0, [r3, #8]
    str	r1, [r3, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r6, r7}
    stmia	r1!, {r2, r6, r7}
    ldr	r0, [sp, #64]	@ 0x40
    ldr	r1, [sp, #68]	@ 0x44
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r0, ip
    str	r0, [r3, #40]	@ 0x28
    mov	r1, r9
    str	r1, [r3, #44]	@ 0x2c
    str	r1, [r3, #48]	@ 0x30
    movs	r0, #18
    ldrsb	r0, [r4, r0]
    cmp	r0, #0
    beq .Leu_0803A2BA
    cmp	r0, #1
    bne .Leu_0803A2BA
    ldr	r0, [r4, #0]
    cmp	r0, #1
    beq .Leu_0803A248
    cmp	r0, #1
    bgt .Leu_0803A21E
    cmp	r0, #0
    beq .Leu_0803A228
    b .Leu_0803A2B6
.Leu_0803A21E:
    cmp	r0, #2
    beq .Leu_0803A268
    cmp	r0, #3
    beq .Leu_0803A288
    b .Leu_0803A2B6
.Leu_0803A228:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Leu_0803A23A
    adds	r0, r3, #0
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Leu_0803A23C
.Leu_0803A23A:
    adds	r0, r1, #0
.Leu_0803A23C:
    cmp	r0, #1
    ble .Leu_0803A2B6
    ldr	r0, [r4, #12]
    adds	r0, r0, r5
    str	r0, [r4, #12]
    b .Leu_0803A2BA
.Leu_0803A248:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Leu_0803A258
    adds	r0, r3, #0
    bl func_080AB8D0
    ldr	r1, [sp, #16]
.Leu_0803A258:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Leu_0803A2B6
    ldr	r0, [r4, #12]
    subs	r0, r0, r5
    str	r0, [r4, #12]
    b .Leu_0803A2BA
.Leu_0803A268:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Leu_0803A278
    adds	r0, r3, #0
    bl func_080AB948
    ldr	r1, [sp, #20]
.Leu_0803A278:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Leu_0803A2B6
    ldr	r0, [r4, #8]
    subs	r0, r0, r5
    str	r0, [r4, #8]
    b .Leu_0803A2BA
.Leu_0803A288:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Leu_0803A29A
    adds	r0, r3, #0
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Leu_0803A29C
.Leu_0803A29A:
    adds	r0, r1, #0
.Leu_0803A29C:
    cmp	r0, #1
    ble .Leu_0803A2B6
    ldr	r0, [r4, #8]
    adds	r0, r0, r5
    str	r0, [r4, #8]
    asrs	r0, r0, #16
    movs	r1, #145	@ 0x91
    lsls	r1, r1, #2
    cmp	r0, r1
    ble .Leu_0803A2BA
    movs	r0, #145	@ 0x91
    lsls	r0, r0, #18
    str	r0, [r4, #8]
.Leu_0803A2B6:
    movs	r0, #0
    strh	r0, [r4, #16]
.Leu_0803A2BA:
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    strh	r0, [r4, #4]
    movs	r6, #14
    ldrsh	r0, [r4, r6]
    strh	r0, [r4, #6]
    mov	r1, r8
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_0803A2E6
    mov	r0, r8
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_0803A2EA
    mov	r1, r8
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Leu_0803A2E8
.Leu_0803A2E6:
    movs	r0, #0
.Leu_0803A2E8:
    strb	r0, [r1, #0]
.Leu_0803A2EA:
    ldrh	r0, [r4, #16]
    subs	r0, #1
    strh	r0, [r4, #16]
    lsls	r0, r0, #16
    cmp	r0, #0
    bge .Leu_0803A324
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #16
    asrs	r1, r0, #16
    cmp	r1, #3
    bne .Leu_0803A30A
    movs	r0, #0
    strb	r0, [r4, #18]
    b .Leu_0803A316
.Leu_0803A30A:
    movs	r0, #1
    strb	r0, [r4, #18]
    ldr	r0, [r4, #0]
    bl func_080AB7A4
    str	r0, [r4, #0]
.Leu_0803A316:
    movs	r0, #31
    bl func_080AB788
    adds	r0, #16
    strh	r0, [r4, #16]
    movs	r7, #1
    mov	r9, r7
.Leu_0803A324:
    mov	r0, r9
    add	sp, #72	@ 0x48
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803A320
    .thumb_func
func_0803A320:
    ldr r0, .Leu_0803A344
    lsls	r1, r1, #16
    asrs	r1, r1, #15
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Leu_0803A344:
    .4byte gUnk_080F16D2
    .global func_0803A334
    .thumb_func
func_0803A334:
    ldr r2, .Leu_0803A360
    lsls	r1, r1, #16
    asrs	r1, r1, #16
    adds	r1, #64	@ 0x40
    movs	r0, #255	@ 0xff
    ands	r1, r0
    lsls	r1, r1, #1
    adds	r1, r1, r2
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Leu_0803A360:
    .4byte gUnk_080F16D2
    .global func_0803A350
    .thumb_func
func_0803A350:
    push	{r4, r5, r6, lr}
    adds	r6, r1, #0
    ldr	r0, [r0, #0]
    ldr	r1, [r0, #0]
    movs	r2, #166	@ 0xa6
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldr	r4, [r0, #0]
    ldr	r5, [r0, #4]
    cmp	r4, r5
    beq .Leu_0803A396
.Leu_0803A380:
    ldr	r0, [r4, #0]
    bl func_08008CD0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803A390
    ldr	r0, [r4, #0]
    b .Leu_0803A39A
.Leu_0803A390:
    adds	r4, #4
    cmp	r4, r5
    bne .Leu_0803A380
.Leu_0803A396:
    subs	r0, r5, #4
    ldr	r0, [r0, #0]
.Leu_0803A39A:
    lsls	r1, r6, #16
    lsrs	r1, r1, #16
    bl func_08008B6C
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_0803A394
    .thumb_func
func_0803A394:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    adds	r5, r2, #0
    lsls	r3, r3, #24
    lsrs	r3, r3, #24
    mov	r9, r3
    ldr r7, .Leu_0803A3F8
    cmp	r3, #0
    bne .Leu_0803A3C8
    ldr r7, .Leu_0803A3FC
.Leu_0803A3C8:
    movs	r0, #4
    mov	sl, r0
    mov	r1, r9
    cmp	r1, #0
    bne .Leu_0803A3D6
    movs	r2, #10
    mov	sl, r2
.Leu_0803A3D6:
    movs	r0, #99	@ 0x63
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    movs	r3, #0
    str	r3, [sp, #0]
    movs	r0, #0
    str	r0, [sp, #4]
    mov	ip, r0
    cmp	r5, #1
    beq .Leu_0803A410
    cmp	r5, #1
    bgt .Leu_0803A400
    cmp	r5, #0
    beq .Leu_0803A40A
    b .Leu_0803A420
.Leu_0803A3F8:
    .4byte gUnk_080F1904
.Leu_0803A3FC:
    .4byte gUnk_080F18D2
.Leu_0803A400:
    cmp	r5, #2
    beq .Leu_0803A416
    cmp	r5, #3
    beq .Leu_0803A41C
    b .Leu_0803A420
.Leu_0803A40A:
    movs	r1, #0
    mov	ip, r1
    b .Leu_0803A420
.Leu_0803A410:
    movs	r2, #1
    mov	ip, r2
    b .Leu_0803A420
.Leu_0803A416:
    movs	r3, #2
    mov	ip, r3
    b .Leu_0803A420
.Leu_0803A41C:
    movs	r5, #3
    mov	ip, r5
.Leu_0803A420:
    movs	r3, #0
    cmp	r3, sl
    bge .Leu_0803A46C
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    mov	r2, ip
    adds	r1, r7, r2
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Leu_0803A43C
    str	r3, [sp, #0]
    ldrb	r5, [r7, #4]
    str	r5, [sp, #4]
    b .Leu_0803A46C
.Leu_0803A43C:
    lsls	r0, r3, #2
    adds	r0, r0, r3
    adds	r0, r0, r7
    add	r0, ip
    ldrb	r0, [r0, #0]
    subs	r0, r4, r0
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    adds	r3, #1
    cmp	r3, sl
    bge .Leu_0803A46C
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    lsls	r1, r3, #2
    adds	r1, r1, r3
    adds	r2, r1, r7
    mov	r5, ip
    adds	r1, r2, r5
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Leu_0803A43C
    str	r3, [sp, #0]
    ldrb	r2, [r2, #4]
    str	r2, [sp, #4]
.Leu_0803A46C:
    ldr	r0, [sp, #0]
    cmp	r0, #0
    beq .Leu_0803A47C
    mov	r1, r9
    cmp	r1, #0
    beq .Leu_0803A47C
    adds	r0, #9
    str	r0, [sp, #0]
.Leu_0803A47C:
    ldr	r2, [sp, #4]
    cmp	r2, #1
    ble .Leu_0803A48E
    adds	r0, r2, #0
    subs	r0, #1
    bl func_080AB788
    adds	r0, #1
    str	r0, [sp, #4]
.Leu_0803A48E:
    ldr	r3, [sp, #4]
    cmp	r3, #0
    bgt .Leu_0803A496
    b .Leu_0803A796
.Leu_0803A496:
    movs	r0, #196	@ 0xc4
    lsls	r0, r0, #1
    bl func_080AB788
    adds	r5, r0, #0
    adds	r5, #184	@ 0xb8
    cmp	r5, #239	@ 0xef
    bgt .Leu_0803A4B4
    movs	r0, #56	@ 0x38
    bl func_080AB788
    movs	r1, #248	@ 0xf8
    lsls	r1, r1, #1
    adds	r7, r0, r1
    b .Leu_0803A4C0
.Leu_0803A4B4:
    movs	r0, #48	@ 0x30
    bl func_080AB788
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r7, r0, r2
.Leu_0803A4C0:
    ldr	r0, [sp, #0]
    subs	r0, #1
    cmp	r0, #11
    bls .Leu_0803A4CA
    b .Leu_0803A78A
.Leu_0803A4CA:
    lsls	r0, r0, #2
    ldr r1, .Leu_0803A4D4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_0803A4D4:
    .4byte .Leu_0803A4D8
.Leu_0803A4D8:
    .4byte .Leu_0803A508
    .4byte .Leu_0803A570
    .4byte .Leu_0803A58C
    .4byte .Leu_0803A5AC
    .4byte .Leu_0803A5CC
    .4byte .Leu_0803A61C
    .4byte .Leu_0803A684
    .4byte .Leu_0803A6A4
    .4byte .Leu_0803A6C4
    .4byte .Leu_0803A6E4
    .4byte .Leu_0803A704
    .4byte .Leu_0803A724
.Leu_0803A508:
    .4byte 0xF7C62064
    .4byte 0x1C04F86D
    .4byte 0x4A154641
    .4byte 0xF7FF2301
    .4byte 0x4814FCC9
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x210065A0
    .4byte 0x04005E68
    .4byte 0x1C3165E0
    .4byte 0x68B03108
    .4byte 0xD9002802
    .4byte 0x0080E119
    .4byte 0x18083004
    .4byte 0xD1002800
    .4byte 0x6004E110
    .4byte 0x0000E10E
    .4byte 0x000009B6
    .4byte vtable_unk_080E76A4
.Leu_0803A570:
    .4byte 0xF7C62064
    .4byte 0x1C04F839
    .4byte 0x22104641
    .4byte 0xF7FF2301
    .4byte 0x4801FC95
    .4byte 0x0000E7CA
    .4byte vtable_unk_080E768C
.Leu_0803A58C:
    .4byte 0xF7C62064
    .4byte 0x1C04F82B
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC87
    .4byte 0x0000E7BC
    .4byte 0x000003DB
    .4byte vtable_unk_080E7674
.Leu_0803A5AC:
    .4byte 0xF7C62064
    .4byte 0x1C04F81B
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC77
    .4byte 0x0000E7AC
    .4byte 0x00000806
    .4byte vtable_unk_080E765C
.Leu_0803A5CC:
    .4byte 0xF7C6206C
    .4byte 0x1C04F80B
    .4byte 0x4A0F4641
    .4byte 0xF7FF2301
    .4byte 0x480EFC67
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x220065A0
    .4byte 0x04005EA8
    .4byte 0x66A165E0
    .4byte 0x0000E79B
    .4byte 0x00000202
    .4byte vtable_unk_080E7644
.Leu_0803A61C:
    .4byte 0xF7C52088
    .4byte 0x1C05FFE3
    .4byte 0x22A94641
    .4byte 0x23010092
    .4byte 0xFC3EF7FF
    .4byte 0x64E84813
    .4byte 0x652C2400
    .4byte 0x31501C29
    .4byte 0x22011C28
    .4byte 0xF7FF4252
    .4byte 0x1C29FD89
    .4byte 0x70083178
    .4byte 0x20FF3101
    .4byte 0x1C287008
    .4byte 0x21003060
    .4byte 0x30028004
    .4byte 0x380E7001
    .4byte 0x5EC02300
    .4byte 0x65A80400
    .4byte 0x30561C28
    .4byte 0x5E402100
    .4byte 0x65E80400
    .4byte 0x31841C29
    .4byte 0x700820F8
    .4byte 0x0000E077
    .4byte vtable_unk_080E762C
.Leu_0803A684:
    .4byte 0xF7C52064
    .4byte 0x1C04FFAF
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC0B
    .4byte 0x0000E740
    .4byte 0x0000087B
    .4byte vtable_unk_080E7614
.Leu_0803A6A4:
    .4byte 0xF7C52064
    .4byte 0x1C04FF9F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBFB
    .4byte 0x0000E730
    .4byte 0x0000065C
    .4byte vtable_unk_080E75FC
.Leu_0803A6C4:
    .4byte 0xF7C52064
    .4byte 0x1C04FF8F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBEB
    .4byte 0x0000E720
    .4byte 0x000008F9
    .4byte vtable_unk_080E75E4
.Leu_0803A6E4:
    .4byte 0xF7C52064
    .4byte 0x1C04FF7F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBDB
    .4byte 0x0000E710
    .4byte 0x000009A9
    .4byte vtable_unk_080E75CC
.Leu_0803A704:
    .4byte 0xF7C52064
    .4byte 0x1C04FF6F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBCB
    .4byte 0x0000E700
    .4byte 0x000008FD
    .4byte vtable_unk_080E75B4
.Leu_0803A724:
    .4byte 0xF7C52064
    .4byte 0x1C05FF5F
    .4byte 0x22154641
    .4byte 0xF7FF2300
    .4byte 0x481CFBBB
    .4byte 0x240064E8
    .4byte 0x1C29652C
    .4byte 0x1C283150
    .4byte 0x42522201
    .4byte 0xFD06F7FF
    .4byte 0x30601C28
    .4byte 0x80042100
    .4byte 0x70013002
    .4byte 0x2200380E
    .4byte 0x04005E80
    .4byte 0x1C2865A8
    .4byte 0x23003056
    .4byte 0x04005EC0
    .4byte 0x1C3165E8
    .4byte 0x68B03108
    .4byte 0xD8082802
    .4byte 0x30040080
    .4byte 0x28001808
    .4byte 0x6005D000
    .4byte 0x300168B0
    .hword 0x60B0
.Leu_0803A78A:
    ldr	r5, [sp, #4]
    subs	r5, #1
    str	r5, [sp, #4]
    cmp	r5, #0
    ble .Leu_0803A796
    b .Leu_0803A496
.Leu_0803A796:
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte vtable_unk_080E759C
    .global func_0803A798
    .thumb_func
func_0803A798:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    movs	r0, #32
    bl __builtin_new
    adds	r5, r0, #0
    mov	r1, sp
    ldrh	r2, [r1, #0]
    ldr r3, .Leu_0803A810
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldrb	r4, [r1, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r4
    strb	r0, [r1, #1]
    ldrh	r4, [r1, #2]
    adds	r0, r3, #0
    ands	r0, r4
    strh	r0, [r1, #2]
    ldrb	r0, [r1, #3]
    ands	r2, r0
    strb	r2, [r1, #3]
    ldrh	r0, [r1, #4]
    ands	r3, r0
    strh	r3, [r1, #4]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Leu_0803A814
    str	r0, [r5, #20]
    mov	r0, r8
    str	r0, [r5, #24]
    movs	r0, #1
    strb	r0, [r5, #28]
    adds	r0, r5, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803A810:
    .4byte 0xFFFFFC00
.Leu_0803A814:
    .4byte vtable_unk_080E7568
    adds	r0, #48	@ 0x30
    movs	r1, #16
    ldrsh	r0, [r0, r1]
    bx	lr
    adds	r0, #48	@ 0x30
    strh	r1, [r0, #16]
    bx	lr
    .align 2, 0
    push	{lr}
    adds	r0, #48	@ 0x30
    bl func_0805E894
    pop	{r1}
    bx	r1
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #48	@ 0x30
    movs	r2, #0
    ldrh	r0, [r1, #14]
    cmp	r0, #0
    beq .Leu_0803A84C
    movs	r0, #16
    ldrsh	r1, [r1, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Leu_0803A84C:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_0803A878
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_0803A87C
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Leu_0803A87A
.Leu_0803A878:
    movs	r0, #0
.Leu_0803A87A:
    strb	r0, [r1, #0]
.Leu_0803A87C:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldrh	r0, [r4, #4]
    cmp	r0, r5
    beq .Leu_0803A8AC
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    strh	r5, [r4, #4]
.Leu_0803A8AC:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    ldr	r0, [r0, #0]
    bx	lr

    .else
    .ifdef REGION_DE
    @ ROM-verified DE Thumb entity UI code
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08035380
    .thumb_func
func_08035380:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #188	@ 0xbc
    adds	r6, r0, #0
    ldr	r5, [r6, #0]
    ldr	r1, [r6, #56]	@ 0x38
    cmp	r1, #0
    bne .Lde_080352AC
    b .Lde_0803580C
.Lde_080352AC:
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #112]	@ 0x70
    cmp	r0, #0
    bne .Lde_080352C0
    b .Lde_0803580C
.Lde_080352C0:
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    str	r0, [sp, #176]	@ 0xb0
    ldr	r0, [sp, #112]	@ 0x70
    ldrh	r0, [r0, #0]
    cmp	r1, r0
    bcc .Lde_080352D2
    b .Lde_0803580C
.Lde_080352D2:
    lsls	r1, r1, #3
    ldr	r2, [sp, #112]	@ 0x70
    ldr	r0, [r2, #4]
    adds	r7, r0, r1
    ldr	r3, [r7, #4]
    str	r3, [sp, #116]	@ 0x74
    cmp	r3, #0
    bne .Lde_080352E4
    b .Lde_0803580C
.Lde_080352E4:
    ldr	r0, [r5, #0]
    movs	r4, #162	@ 0xa2
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r1, [r0, #0]
    adds	r0, r5, #0
    bl _call_via_r1
    ldrh	r3, [r0, #10]
    lsls	r0, r3, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lde_08035302
    adds	r2, #24
.Lde_08035302:
    lsls	r1, r2, #4
    subs	r1, r1, r2
    lsls	r1, r1, #2
    lsls	r0, r3, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    movs	r0, #0
    str	r0, [sp, #120]	@ 0x78
    ldr	r2, [sp, #116]	@ 0x74
    ldr	r3, [r2, #0]
    cmp	r3, #0
    bne .Lde_0803531C
    b .Lde_080357D4
.Lde_0803531C:
    ldrh	r4, [r2, #4]
    cmp	r4, #0
    bne .Lde_08035324
    b .Lde_080357D4
.Lde_08035324:
    adds	r0, r6, #0
    adds	r0, #62	@ 0x3e
    ldrb	r2, [r0, #0]
    str	r0, [sp, #180]	@ 0xb4
    cmp	r2, r4
    bcc .Lde_08035332
    b .Lde_0803580C
.Lde_08035332:
    ldr	r4, [sp, #116]	@ 0x74
    ldrb	r0, [r4, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803533E
    b .Lde_0803554C
.Lde_0803533E:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #124]	@ 0x7c
    movs	r1, #0
    ldrb	r0, [r3, #4]
    lsls	r0, r0, #31
    cmp	r0, #0
    bne .Lde_08035350
    movs	r1, #1
.Lde_08035350:
    mov	r8, r1
    ldr	r0, [r6, #8]
    str	r0, [sp, #0]
    ldr	r0, [r6, #12]
    str	r0, [sp, #8]
    ldr	r0, [r6, #24]
    str	r0, [sp, #4]
    ldr	r0, [r6, #28]
    str	r0, [sp, #12]
    cmp	r1, #0
    beq .Lde_08035370
    mov	sl, sp
    mov	r7, sp
    adds	r7, #4
    str	r7, [sp, #128]	@ 0x80
    b .Lde_0803537A
.Lde_08035370:
    add	r0, sp, #8
    mov	sl, r0
    mov	r1, sp
    adds	r1, #12
    str	r1, [sp, #128]	@ 0x80
.Lde_0803537A:
    mov	r2, sl
    ldr	r1, [r2, #0]
    asrs	r3, r1, #16
    str	r3, [sp, #132]	@ 0x84
    ldr	r4, [sp, #128]	@ 0x80
    ldr	r0, [r4, #0]
    adds	r1, r1, r0
    str	r1, [sp, #136]	@ 0x88
    asrs	r7, r1, #16
    str	r7, [sp, #140]	@ 0x8c
    subs	r7, r7, r3
    movs	r3, #0
    adds	r0, r6, #0
    adds	r0, #64	@ 0x40
    ldrh	r2, [r0, #0]
    ldr r1, .Lde_080353C0
    str	r0, [sp, #184]	@ 0xb8
    cmp	r2, r1
    blt .Lde_080353A2
    movs	r3, #1
.Lde_080353A2:
    movs	r0, #1
    str	r0, [sp, #144]	@ 0x90
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Lde_080353D2
    movs	r4, #0
    str	r4, [sp, #144]	@ 0x90
    cmp	r3, #0
    beq .Lde_080353C4
    strb	r4, [r1, #0]
    b .Lde_080353C8
    .align 2, 0
.Lde_080353C0:
    .4byte 0x000002EE
.Lde_080353C4:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Lde_080353C8:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_080353D2
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Lde_080353D2:
    cmp	r3, #0
    bne .Lde_080354B4
    cmp	r7, #0
    beq .Lde_080354B4
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_080354B4
    ldrh	r0, [r4, #4]
    ldrh	r2, [r6, #4]
    cmp	r0, r2
    bne .Lde_080354B4
    ldr	r1, [r6, #20]
    add	r0, sp, #16
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #16]
    ldr	r1, [sp, #20]
    str	r0, [sp, #24]
    str	r1, [sp, #28]
    add	r5, sp, #24
    ldr	r1, [r4, #20]
    add	r0, sp, #32
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #32]
    ldr	r1, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    add	r4, sp, #40	@ 0x28
    mov	r3, r8
    cmp	r3, #0
    beq .Lde_0803542C
    adds	r2, r7, #0
    movs	r7, #0
    b .Lde_0803542E
.Lde_0803542C:
    movs	r2, #0
.Lde_0803542E:
    mov	r9, r7
    movs	r1, #0
    ldrsh	r0, [r5, r1]
    mov	ip, r0
    movs	r3, #4
    ldrsh	r1, [r4, r3]
    subs	r1, r0, r1
    movs	r7, #0
    ldrsh	r0, [r4, r7]
    movs	r7, #4
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    subs	r0, r0, r3
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Lde_080354B4
    add	r3, sp, #48	@ 0x30
    mov	r1, ip
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, r8
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Lde_080354B4
    movs	r5, #0
    str	r5, [sp, #144]	@ 0x90
.Lde_080354B4:
    ldr	r7, [sp, #144]	@ 0x90
    cmp	r7, #0
    beq .Lde_08035542
    ldr	r1, [sp, #124]	@ 0x7c
    movs	r2, #2
    ldrsh	r0, [r1, r2]
    ldr	r3, [sp, #132]	@ 0x84
    cmp	r3, r0
    beq .Lde_080354E4
    ldr	r4, [sp, #140]	@ 0x8c
    cmp	r4, r0
    beq .Lde_080354E4
    movs	r1, #0
    cmp	r0, r3
    bge .Lde_080354D4
    movs	r1, #1
.Lde_080354D4:
    ldr	r5, [sp, #140]	@ 0x8c
    cmp	r0, r5
    bge .Lde_080354E0
    cmp	r1, #0
    beq .Lde_080354E4
    b .Lde_0803552A
.Lde_080354E0:
    cmp	r1, #0
    beq .Lde_0803552A
.Lde_080354E4:
    lsls	r0, r0, #16
    mov	r7, sl
    str	r0, [r7, #0]
    movs	r1, #0
    ldr	r0, [sp, #128]	@ 0x80
    str	r1, [r0, #0]
    ldr	r2, [sp, #180]	@ 0xb4
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r3, [sp, #116]	@ 0x74
    ldrh	r3, [r3, #4]
    cmp	r0, r3
    bcs .Lde_0803550A
    movs	r4, #1
    str	r4, [sp, #120]	@ 0x78
    b .Lde_08035530
.Lde_0803550A:
    ldr	r5, [sp, #176]	@ 0xb0
    ldrb	r0, [r5, #0]
    adds	r0, #1
    ldr	r7, [sp, #112]	@ 0x70
    ldrh	r7, [r7, #0]
    cmp	r0, r7
    blt .Lde_0803551A
    b .Lde_0803580C
.Lde_0803551A:
    ldr	r0, [sp, #180]	@ 0xb4
    strb	r1, [r0, #0]
    ldrb	r0, [r5, #0]
    adds	r0, #1
    strb	r0, [r5, #0]
    movs	r1, #2
    str	r1, [sp, #120]	@ 0x78
    b .Lde_08035530
.Lde_0803552A:
    ldr	r2, [sp, #136]	@ 0x88
    mov	r3, sl
    str	r2, [r3, #0]
.Lde_08035530:
    ldr	r0, [sp, #0]
    str	r0, [r6, #8]
    ldr	r0, [sp, #8]
    str	r0, [r6, #12]
    ldr	r0, [sp, #4]
    str	r0, [r6, #24]
    ldr	r0, [sp, #12]
    str	r0, [r6, #28]
    b .Lde_080357FA
.Lde_08035542:
    ldr	r4, [sp, #184]	@ 0xb8
    ldrh	r0, [r4, #0]
    adds	r0, #1
    strh	r0, [r4, #0]
    b .Lde_080357FA
.Lde_0803554C:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #148]	@ 0x94
    movs	r2, #0
    ldrb	r0, [r3, #6]
    lsls	r0, r0, #29
    cmp	r0, #0
    blt .Lde_0803555E
    movs	r2, #1
.Lde_0803555E:
    mov	r8, r2
    movs	r2, #0
    ldr	r3, [sp, #176]	@ 0xb0
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldr	r4, [sp, #112]	@ 0x70
    ldrh	r4, [r4, #0]
    cmp	r0, r4
    bge .Lde_08035578
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lde_08035578
    movs	r2, #1
.Lde_08035578:
    mov	sl, r2
    cmp	r2, #0
    beq .Lde_08035596
    ldrh	r4, [r6, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #20]
    adds	r0, r5, #0
    bl _call_via_r1
    cmp	r4, r0
    beq .Lde_08035596
    movs	r0, #0
    ldr	r5, [sp, #180]	@ 0xb4
    strb	r0, [r5, #0]
    b .Lde_080357C0
.Lde_08035596:
    adds	r1, r6, #0
    adds	r1, #64	@ 0x40
    ldrh	r0, [r1, #0]
    str	r1, [sp, #184]	@ 0xb8
    cmp	r0, #0
    beq .Lde_080355A4
    b .Lde_08035788
.Lde_080355A4:
    ldr	r0, [r6, #8]
    str	r0, [sp, #56]	@ 0x38
    ldr	r0, [r6, #12]
    str	r0, [sp, #64]	@ 0x40
    ldr	r0, [r6, #24]
    str	r0, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #28]
    str	r0, [sp, #68]	@ 0x44
    mov	r1, r8
    cmp	r1, #0
    beq .Lde_080355C8
    mov	r2, sp
    adds	r2, #56	@ 0x38
    str	r2, [sp, #152]	@ 0x98
    mov	r3, sp
    adds	r3, #60	@ 0x3c
    str	r3, [sp, #156]	@ 0x9c
    b .Lde_080355D4
.Lde_080355C8:
    mov	r4, sp
    adds	r4, #64	@ 0x40
    str	r4, [sp, #152]	@ 0x98
    mov	r7, sp
    adds	r7, #68	@ 0x44
    str	r7, [sp, #156]	@ 0x9c
.Lde_080355D4:
    ldr	r1, [sp, #152]	@ 0x98
    ldr	r0, [r1, #0]
    asrs	r2, r0, #16
    str	r2, [sp, #160]	@ 0xa0
    ldr	r3, [sp, #156]	@ 0x9c
    ldr	r1, [r3, #0]
    adds	r0, r0, r1
    str	r0, [sp, #164]	@ 0xa4
    asrs	r4, r0, #16
    str	r4, [sp, #168]	@ 0xa8
    subs	r7, r4, r2
    movs	r0, #1
    str	r0, [sp, #172]	@ 0xac
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Lde_08035616
    movs	r3, #0
    str	r3, [sp, #172]	@ 0xac
    mov	r4, sl
    cmp	r4, #0
    beq .Lde_08035608
    strb	r3, [r1, #0]
    b .Lde_0803560C
.Lde_08035608:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Lde_0803560C:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_08035616
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Lde_08035616:
    mov	r2, sl
    cmp	r2, #0
    bne .Lde_080356FC
    cmp	r7, #0
    beq .Lde_080356FC
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_080356FC
    ldrh	r0, [r4, #4]
    ldrh	r3, [r6, #4]
    cmp	r0, r3
    bne .Lde_080356FC
    ldr	r1, [r6, #20]
    add	r0, sp, #72	@ 0x48
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #72]	@ 0x48
    ldr	r1, [sp, #76]	@ 0x4c
    str	r0, [sp, #80]	@ 0x50
    str	r1, [sp, #84]	@ 0x54
    add	r5, sp, #80	@ 0x50
    ldr	r1, [r4, #20]
    add	r0, sp, #88	@ 0x58
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #96]	@ 0x60
    str	r1, [sp, #100]	@ 0x64
    add	r4, sp, #96	@ 0x60
    mov	r0, r8
    cmp	r0, #0
    beq .Lde_08035674
    adds	r2, r7, #0
    movs	r1, #0
    mov	r9, r1
    b .Lde_08035678
.Lde_08035674:
    movs	r2, #0
    mov	r9, r7
.Lde_08035678:
    movs	r7, #0
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    movs	r0, #4
    ldrsh	r1, [r4, r0]
    subs	r1, r3, r1
    movs	r3, #0
    ldrsh	r0, [r4, r3]
    movs	r3, #4
    ldrsh	r7, [r5, r3]
    mov	ip, r7
    subs	r0, r0, r7
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Lde_080356FC
    add	r3, sp, #104	@ 0x68
    mov	r1, r8
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, ip
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Lde_080356FC
    movs	r5, #0
    str	r5, [sp, #172]	@ 0xac
.Lde_080356FC:
    ldr	r7, [sp, #172]	@ 0xac
    cmp	r7, #0
    beq .Lde_080357FA
    ldr	r0, [sp, #148]	@ 0x94
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    ldr	r3, [sp, #168]	@ 0xa8
    cmp	r3, r2
    beq .Lde_0803571A
    ldr	r4, [sp, #160]	@ 0xa0
    subs	r0, r2, r4
    subs	r1, r2, r3
    eors	r0, r1
    cmp	r0, #0
    bge .Lde_08035770
.Lde_0803571A:
    lsls	r0, r2, #16
    ldr	r5, [sp, #152]	@ 0x98
    str	r0, [r5, #0]
    movs	r1, #0
    ldr	r7, [sp, #156]	@ 0x9c
    str	r1, [r7, #0]
    mov	r0, sl
    cmp	r0, #0
    bne .Lde_08035734
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r0, [r2, #4]
    cmp	r0, #0
    bne .Lde_08035764
.Lde_08035734:
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Lde_0803575E
    strb	r1, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Lde_08035758
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Lde_08035758:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Lde_08035776
.Lde_0803575E:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Lde_08035776
.Lde_08035764:
    movs	r0, #1
    ldr	r2, [sp, #184]	@ 0xb8
    strh	r0, [r2, #0]
    movs	r3, #1
    str	r3, [sp, #120]	@ 0x78
    b .Lde_08035776
.Lde_08035770:
    ldr	r4, [sp, #164]	@ 0xa4
    ldr	r5, [sp, #152]	@ 0x98
    str	r4, [r5, #0]
.Lde_08035776:
    ldr	r0, [sp, #56]	@ 0x38
    str	r0, [r6, #8]
    ldr	r0, [sp, #64]	@ 0x40
    str	r0, [r6, #12]
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [r6, #24]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [r6, #28]
    b .Lde_080357FA
.Lde_08035788:
    mov	r7, sl
    cmp	r7, #0
    bne .Lde_0803579E
    adds	r0, #1
    strh	r0, [r1, #0]
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r2, [r2, #4]
    cmp	r0, r2
    bls .Lde_080357FA
.Lde_0803579E:
    movs	r0, #0
    strh	r0, [r1, #0]
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Lde_080357CE
    movs	r0, #0
    strb	r0, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Lde_080357C8
.Lde_080357C0:
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Lde_080357C8:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Lde_08035800
.Lde_080357CE:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Lde_08035800
.Lde_080357D4:
    ldr	r2, [sp, #176]	@ 0xb0
    ldrb	r0, [r2, #0]
    adds	r0, #1
    ldr	r3, [sp, #112]	@ 0x70
    ldrh	r3, [r3, #0]
    cmp	r0, r3
    bge .Lde_080357FA
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lde_080357FA
    adds	r1, r6, #0
    adds	r1, #62	@ 0x3e
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    movs	r4, #2
    str	r4, [sp, #120]	@ 0x78
.Lde_080357FA:
    ldr	r5, [sp, #120]	@ 0x78
    cmp	r5, #0
    ble .Lde_0803580C
.Lde_08035800:
    ldr	r0, [r6, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r6, #0
    ldr	r1, [sp, #120]	@ 0x78
    bl _call_via_r2
.Lde_0803580C:
    add	sp, #188	@ 0xbc
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08035908
    .thumb_func
func_08035908:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #68	@ 0x44
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Lde_0803584E
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803584E
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Lde_0803584E
    cmp	r0, r5
    beq .Lde_0803584E
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Lde_0803584E:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035940
    .thumb_func
func_08035940:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #70	@ 0x46
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Lde_08035886
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08035886
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Lde_08035886
    cmp	r0, r5
    beq .Lde_08035886
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Lde_08035886:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035978
    .thumb_func
func_08035978:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803594E
    ldr	r1, [r4, #56]	@ 0x38
    cmp	r1, #0
    beq .Lde_0803594E
    adds	r0, r4, #0
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r6, [r0, #0]
    cmp	r6, #0
    beq .Lde_0803594E
    adds	r0, r4, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    mov	r8, r0
    ldrh	r0, [r6, #0]
    cmp	r1, r0
    bcs .Lde_0803594E
    lsls	r1, r1, #3
    ldr	r0, [r6, #4]
    adds	r7, r0, r1
    ldr	r5, [r7, #4]
    cmp	r5, #0
    beq .Lde_0803594E
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r1, [r0, #10]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lde_080358F4
    adds	r2, #24
.Lde_080358F4:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r1, r0, r1
    ldr	r0, [r5, #0]
    cmp	r0, #0
    beq .Lde_08035934
    ldrh	r2, [r5, #4]
    cmp	r2, #0
    beq .Lde_08035934
    adds	r0, r4, #0
    adds	r0, #62	@ 0x3e
    ldrb	r0, [r0, #0]
    cmp	r0, r2
    bcs .Lde_0803594E
    ldrb	r0, [r5, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Lde_08035934
    movs	r2, #0
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    ldrh	r1, [r0, #0]
    ldr r0, .Lde_08035930
    cmp	r1, r0
    blt .Lde_0803594A
    b .Lde_08035948
    .align 2, 0
.Lde_08035930:
    .4byte 0x000002EE
.Lde_08035934:
    movs	r2, #0
    mov	r3, r8
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldrh	r6, [r6, #0]
    cmp	r0, r6
    bge .Lde_0803594A
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lde_0803594A
.Lde_08035948:
    movs	r2, #1
.Lde_0803594A:
    adds	r0, r2, #0
    b .Lde_08035950
.Lde_0803594E:
    movs	r0, #0
.Lde_08035950:
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035A48
    .thumb_func
func_08035A48:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r3, r1, #0
    ldrh	r1, [r4, #4]
    ldrh	r0, [r3, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r1, r0
    bne .Lde_080359EA
    movs	r0, #10
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #2]
    ldr r5, .Lde_080359F0
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lde_0803598C
    negs	r0, r0
.Lde_0803598C:
    cmp	r0, #151	@ 0x97
    bgt .Lde_080359EA
    movs	r0, #14
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #4]
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lde_080359AC
    negs	r0, r0
.Lde_080359AC:
    cmp	r0, #111	@ 0x6f
    bgt .Lde_080359EA
    adds	r0, r4, #0
    bl func_08035978
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_080359EA
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_080359EA
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r1, r4, #0
    adds	r1, #63	@ 0x3f
    movs	r0, #120	@ 0x78
    strb	r0, [r1, #0]
    ldr	r0, [r4, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    movs	r1, #1
    bl _call_via_r2
.Lde_080359EA:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Lde_080359F0:
    .4byte 0x000003FF
    .global func_08035AE0
    .thumb_func
func_08035AE0:
    push	{lr}
    adds	r1, r0, #0
    movs	r2, #0
    ldrh	r0, [r1, #4]
    cmp	r0, #29
    bne .Lde_08035A0A
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    cmp	r0, #55	@ 0x37
    bgt .Lde_08035A0A
    movs	r2, #1
.Lde_08035A0A:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .global func_08035AFC
    .thumb_func
func_08035AFC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035A3C
    str	r0, [sp, #0]
    ldr r0, .Lde_08035A40
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035A44
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035A48
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035A3C:
    .4byte gUnk_080F280C
.Lde_08035A40:
    .4byte 0x0000025F
.Lde_08035A44:
    .4byte 0x000003E2
.Lde_08035A48:
    .4byte vtable_unk_080E7198
    .global func_08035B38
    .thumb_func
func_08035B38:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035B64
    .thumb_func
func_08035B64:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035AA4
    str	r0, [sp, #0]
    ldr r0, .Lde_08035AA8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #248	@ 0xf8
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035AAC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08035AA4:
    .4byte ScheduleInfo_Unk_080F1A80
.Lde_08035AA8:
    .4byte 0x00000213
.Lde_08035AAC:
    .4byte vtable_unk_080E7158
    .global func_08035B9C
    .thumb_func
func_08035B9C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035BC8
    .thumb_func
func_08035BC8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035B08
    str	r0, [sp, #0]
    ldr r0, .Lde_08035B0C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035B10
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035B14
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035B08:
    .4byte gUnk_080F1FC0
.Lde_08035B0C:
    .4byte 0x0000022F
.Lde_08035B10:
    .4byte 0x000003E1
.Lde_08035B14:
    .4byte vtable_unk_080E7118
    .global func_08035C04
    .thumb_func
func_08035C04:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lde_08035B5C
    ldr r0, .Lde_08035B60
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lde_08035B64
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #3
    bne .Lde_08035BA8
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lde_08035BA8
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08035B56
    ldr r2, .Lde_08035B68
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_08035B70
.Lde_08035B56:
    ldr r7, .Lde_08035B6C
    b .Lde_08035BA8
    .align 2, 0
.Lde_08035B5C:
    .4byte 0x0000022F
.Lde_08035B60:
    .4byte 0x00000233
.Lde_08035B64:
    .4byte 0x00001CD4
.Lde_08035B68:
    .4byte 0x0000216B
.Lde_08035B6C:
    .4byte 0x0000023F
.Lde_08035B70:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_08035BA8
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_08035BA8
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08035BA8
    ldr r7, .Lde_08035BC4
    ldr r0, .Lde_08035BC8
    mov	r8, r0
.Lde_08035BA8:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08035BC4:
    .4byte 0x00000247
.Lde_08035BC8:
    .4byte 0x0000024B
    .global func_08035CB8
    .thumb_func
func_08035CB8:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_08035BE0
    adds	r0, r5, #0
    bl func_08035C04
.Lde_08035BE0:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08035CD4
    .thumb_func
func_08035CD4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08035C04
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035D04
    .thumb_func
func_08035D04:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035C44
    str	r0, [sp, #0]
    ldr r0, .Lde_08035C48
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035C4C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035C50
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035C44:
    .4byte gUnk_080F8678
.Lde_08035C48:
    .4byte 0x000009EF
.Lde_08035C4C:
    .4byte 0x00000406
.Lde_08035C50:
    .4byte vtable_unk_080E70D8
    .global func_08035D40
    .thumb_func
func_08035D40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #3
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035D70
    .thumb_func
func_08035D70:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035CB0
    str	r0, [sp, #0]
    ldr r0, .Lde_08035CB4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035CB8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035CBC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035CB0:
    .4byte gUnk_080F81BC
.Lde_08035CB4:
    .4byte 0x000009E7
.Lde_08035CB8:
    .4byte 0x00000405
.Lde_08035CBC:
    .4byte vtable_unk_080E7098
    .global func_08035DAC
    .thumb_func
func_08035DAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035DD8
    .thumb_func
func_08035DD8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035D18
    str	r0, [sp, #0]
    ldr r0, .Lde_08035D1C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035D20
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035D24
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035D18:
    .4byte gUnk_080F77FC
.Lde_08035D1C:
    .4byte 0x000009A1
.Lde_08035D20:
    .4byte 0x00000403
.Lde_08035D24:
    .4byte vtable_unk_080E7058
    .global func_08035E14
    .thumb_func
func_08035E14:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035E40
    .thumb_func
func_08035E40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035D80
    str	r0, [sp, #0]
    ldr r0, .Lde_08035D84
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035D88
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035D8C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035D80:
    .4byte gUnk_080F7294
.Lde_08035D84:
    .4byte 0x00000989
.Lde_08035D88:
    .4byte 0x00000402
.Lde_08035D8C:
    .4byte vtable_unk_080E7018
    .global func_08035E7C
    .thumb_func
func_08035E7C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035EAC
    .thumb_func
func_08035EAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035DF0
    str	r0, [sp, #0]
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035DF4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035DF0:
    .4byte gUnk_080F6370
.Lde_08035DF4:
    .4byte vtable_unk_080E6FD8
    .global func_08035EE4
    .thumb_func
func_08035EE4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F10
    .thumb_func
func_08035F10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035E50
    str	r0, [sp, #0]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035E54
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035E58
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08035E50:
    .4byte gUnk_080F66C4
.Lde_08035E54:
    .4byte 0x000003FD
.Lde_08035E58:
    .4byte vtable_unk_080E6F98
    .global func_08035F48
    .thumb_func
func_08035F48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F74
    .thumb_func
func_08035F74:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035EB4
    str	r0, [sp, #0]
    ldr r0, .Lde_08035EB8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035EBC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035EC0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035EB4:
    .4byte gUnk_080F49C0
.Lde_08035EB8:
    .4byte 0x0000080B
.Lde_08035EBC:
    .4byte 0x000003F5
.Lde_08035EC0:
    .4byte vtable_unk_080E6F58
    .global func_08035FB0
    .thumb_func
func_08035FB0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035FE0
    .thumb_func
func_08035FE0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035F20
    str	r0, [sp, #0]
    ldr r0, .Lde_08035F24
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035F28
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035F2C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035F20:
    .4byte gUnk_080F5540
.Lde_08035F24:
    .4byte 0x0000084B
.Lde_08035F28:
    .4byte 0x000003F7
.Lde_08035F2C:
    .4byte vtable_unk_080E6F18
    .global func_0803601C
    .thumb_func
func_0803601C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036048
    .thumb_func
func_08036048:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08035F88
    str	r0, [sp, #0]
    ldr r0, .Lde_08035F8C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08035F90
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08035F94
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08035F88:
    .4byte gUnk_080F4D74
.Lde_08035F8C:
    .4byte 0x00000813
.Lde_08035F90:
    .4byte 0x000003F6
.Lde_08035F94:
    .4byte vtable_unk_080E6ED8
    .global func_08036084
    .thumb_func
func_08036084:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lde_08035FDC
    ldr r0, .Lde_08035FE0
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lde_08035FE4
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #12
    bne .Lde_08036028
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lde_08036028
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08035FD6
    ldr r2, .Lde_08035FE8
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_08035FF0
.Lde_08035FD6:
    ldr r7, .Lde_08035FEC
    b .Lde_08036028
    .align 2, 0
.Lde_08035FDC:
    .4byte 0x00000813
.Lde_08035FE0:
    .4byte 0x00000817
.Lde_08035FE4:
    .4byte 0x00001CD4
.Lde_08035FE8:
    .4byte 0x0000216C
.Lde_08035FEC:
    .4byte 0x00000827
.Lde_08035FF0:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_08036028
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_08036028
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08036028
    ldr r7, .Lde_08036044
    ldr r0, .Lde_08036048
    mov	r8, r0
.Lde_08036028:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08036044:
    .4byte 0x0000082F
.Lde_08036048:
    .4byte 0x00000833
    .global func_08036138
    .thumb_func
func_08036138:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_08036060
    adds	r0, r5, #0
    bl func_08036084
.Lde_08036060:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036154
    .thumb_func
func_08036154:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036084
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036184
    .thumb_func
func_08036184:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_080360C4
    str	r0, [sp, #0]
    ldr r0, .Lde_080360C8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_080360CC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080360D0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080360C4:
    .4byte gUnk_080F59CC
.Lde_080360C8:
    .4byte 0x0000085F
.Lde_080360CC:
    .4byte 0x000003F9
.Lde_080360D0:
    .4byte vtable_unk_080E6E98
    .global func_080361C0
    .thumb_func
func_080361C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080361EC
    .thumb_func
func_080361EC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_0803612C
    str	r0, [sp, #0]
    ldr r0, .Lde_08036130
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036134
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036138
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803612C:
    .4byte gUnk_080F6B4C
.Lde_08036130:
    .4byte 0x000008E4
.Lde_08036134:
    .4byte 0x000003FF
.Lde_08036138:
    .4byte vtable_unk_080E6E58
    .global func_08036228
    .thumb_func
func_08036228:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036258
    .thumb_func
func_08036258:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036194
    str	r0, [sp, #0]
    ldr r0, .Lde_08036198
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    ldr r0, .Lde_0803619C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080361A0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036194:
    .4byte gUnk_080F33B8
.Lde_08036198:
    .4byte 0x00000685
.Lde_0803619C:
    .4byte 0x000003EE
.Lde_080361A0:
    .4byte vtable_unk_080E6E18
    .global func_08036290
    .thumb_func
func_08036290:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080362C0
    .thumb_func
func_080362C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036200
    str	r0, [sp, #0]
    ldr r0, .Lde_08036204
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036208
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_0803620C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036200:
    .4byte gUnk_080F61FC
.Lde_08036204:
    .4byte 0x000008B8
.Lde_08036208:
    .4byte 0x000003FB
.Lde_0803620C:
    .4byte vtable_unk_080E6DD8
    .global func_080362FC
    .thumb_func
func_080362FC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036328
    .thumb_func
func_08036328:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036268
    str	r0, [sp, #0]
    ldr r0, .Lde_0803626C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036270
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036274
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036268:
    .4byte gUnk_080F3408
.Lde_0803626C:
    .4byte 0x00000689
.Lde_08036270:
    .4byte 0x000003EF
.Lde_08036274:
    .4byte vtable_unk_080E6D98
    .global func_08036364
    .thumb_func
func_08036364:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036390
    .thumb_func
func_08036390:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_080362D0
    str	r0, [sp, #0]
    ldr r0, .Lde_080362D4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_080362D8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080362DC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080362D0:
    .4byte gUnk_080F3FD8
.Lde_080362D4:
    .4byte 0x000006C5
.Lde_080362D8:
    .4byte 0x000003F1
.Lde_080362DC:
    .4byte vtable_unk_080E6D58
    .global func_080363CC
    .thumb_func
func_080363CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080363F8
    .thumb_func
func_080363F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036338
    str	r0, [sp, #0]
    ldr r0, .Lde_0803633C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #252	@ 0xfc
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036340
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036338:
    .4byte gUnk_080F35E4
.Lde_0803633C:
    .4byte 0x00000691
.Lde_08036340:
    .4byte vtable_unk_080E6D18
    .global func_08036430
    .thumb_func
func_08036430:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lde_08036388
    ldr r0, .Lde_0803638C
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lde_08036390
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #19
    bne .Lde_080363D4
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lde_080363D4
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08036382
    ldr r2, .Lde_08036394
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803639C
.Lde_08036382:
    ldr r7, .Lde_08036398
    b .Lde_080363D4
    .align 2, 0
.Lde_08036388:
    .4byte 0x00000691
.Lde_0803638C:
    .4byte 0x00000695
.Lde_08036390:
    .4byte 0x00001CD4
.Lde_08036394:
    .4byte 0x0000216C
.Lde_08036398:
    .4byte 0x000006A1
.Lde_0803639C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_080363D4
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_080363D4
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_080363D4
    ldr r7, .Lde_080363F0
    ldr r0, .Lde_080363F4
    mov	r8, r0
.Lde_080363D4:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_080363F0:
    .4byte 0x000006AD
.Lde_080363F4:
    .4byte 0x000006B1
    .global func_080364E4
    .thumb_func
func_080364E4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_0803640C
    adds	r0, r5, #0
    bl func_08036430
.Lde_0803640C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036500
    .thumb_func
func_08036500:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036430
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036530
    .thumb_func
func_08036530:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036470
    str	r0, [sp, #0]
    movs	r0, #200	@ 0xc8
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #194	@ 0xc2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036474
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036470:
    .4byte gUnk_080F3010
.Lde_08036474:
    .4byte vtable_unk_080E6CD8
    .global func_08036564
    .thumb_func
func_08036564:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036590
    .thumb_func
func_08036590:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_080364D0
    str	r0, [sp, #0]
    ldr r0, .Lde_080364D4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_080364D8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080364DC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080364D0:
    .4byte gUnk_080F5D94
.Lde_080364D4:
    .4byte 0x00000884
.Lde_080364D8:
    .4byte 0x000003FA
.Lde_080364DC:
    .4byte vtable_unk_080E6C98
    .global func_080365CC
    .thumb_func
func_080365CC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lde_08036524
    ldr r0, .Lde_08036528
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lde_0803652C
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #21
    bne .Lde_08036570
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lde_08036570
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803651E
    ldr r2, .Lde_08036530
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_08036538
.Lde_0803651E:
    ldr r7, .Lde_08036534
    b .Lde_08036570
    .align 2, 0
.Lde_08036524:
    .4byte 0x00000884
.Lde_08036528:
    .4byte 0x00000888
.Lde_0803652C:
    .4byte 0x00001CD4
.Lde_08036530:
    .4byte 0x0000216C
.Lde_08036534:
    .4byte 0x0000089C
.Lde_08036538:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_08036570
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_08036570
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08036570
    ldr r7, .Lde_0803658C
    ldr r0, .Lde_08036590
    mov	r8, r0
.Lde_08036570:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_0803658C:
    .4byte 0x00000894
.Lde_08036590:
    .4byte 0x00000898
    .global func_08036680
    .thumb_func
func_08036680:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_080365A8
    adds	r0, r5, #0
    bl func_080365CC
.Lde_080365A8:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803669C
    .thumb_func
func_0803669C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_080365CC
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080366CC
    .thumb_func
func_080366CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_0803660C
    str	r0, [sp, #0]
    ldr r0, .Lde_08036610
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #3
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036614
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_0803660C:
    .4byte gUnk_080F6DE8
.Lde_08036610:
    .4byte 0x000008EC
.Lde_08036614:
    .4byte vtable_unk_080E6C58
    .global func_08036704
    .thumb_func
func_08036704:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036730
    .thumb_func
func_08036730:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036670
    str	r0, [sp, #0]
    ldr r0, .Lde_08036674
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #249	@ 0xf9
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036678
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036670:
    .4byte gUnk_080F2AF8
.Lde_08036674:
    .4byte 0x0000027B
.Lde_08036678:
    .4byte vtable_unk_080E6C18
    .global func_08036768
    .thumb_func
func_08036768:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Lde_080366B4
    movs	r5, #2
    ldr	r0, [r4, #52]	@ 0x34
    ldr r2, .Lde_080366B8
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_08036698
    adds	r1, #24
    movs	r5, #1
.Lde_08036698:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    ldr r1, .Lde_080366BC
    bl func_08035940
    adds	r0, r4, #0
    adds	r0, #33	@ 0x21
    strb	r5, [r0, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_080366B4:
    .4byte 0x0000027B
.Lde_080366B8:
    .4byte 0x00002181
.Lde_080366BC:
    .4byte 0x0000027F
    .global func_080367AC
    .thumb_func
func_080367AC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_080366D4
    adds	r0, r5, #0
    bl func_08036768
.Lde_080366D4:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080367C8
    .thumb_func
func_080367C8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036768
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080367F8
    .thumb_func
func_080367F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036738
    str	r0, [sp, #0]
    ldr r0, .Lde_0803673C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036740
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036744
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036738:
    .4byte gUnk_080F42F0
.Lde_0803673C:
    .4byte 0x000007B2
.Lde_08036740:
    .4byte 0x000003F2
.Lde_08036744:
    .4byte vtable_unk_080E6BD8
    .global func_08036834
    .thumb_func
func_08036834:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036860
    .thumb_func
func_08036860:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_080367A0
    str	r0, [sp, #0]
    ldr r0, .Lde_080367A4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #253	@ 0xfd
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080367A8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_080367A0:
    .4byte gUnk_080F4974
.Lde_080367A4:
    .4byte 0x000007F2
.Lde_080367A8:
    .4byte vtable_unk_080E6B98
    .global func_08036898
    .thumb_func
func_08036898:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080368C4
    .thumb_func
func_080368C4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036804
    str	r0, [sp, #0]
    ldr r0, .Lde_08036808
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_0803680C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036810
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036804:
    .4byte gUnk_080F43DC
.Lde_08036808:
    .4byte 0x000007BE
.Lde_0803680C:
    .4byte 0x000003F3
.Lde_08036810:
    .4byte vtable_unk_080E6B58
    .global func_08036900
    .thumb_func
func_08036900:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lde_08036864
    ldr r0, .Lde_08036868
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lde_0803686C
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #25
    bne .Lde_080368B4
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lde_080368B4
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803685E
    ldr r2, .Lde_08036870
    adds	r0, r5, r2
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    ldr r1, .Lde_08036874
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Lde_0803687C
.Lde_0803685E:
    ldr r7, .Lde_08036878
    b .Lde_080368B4
    .align 2, 0
.Lde_08036864:
    .4byte 0x000007BE
.Lde_08036868:
    .4byte 0x000007C2
.Lde_0803686C:
    .4byte 0x00001CD4
.Lde_08036870:
    .4byte 0x0000216B
.Lde_08036874:
    .4byte 0x0000216C
.Lde_08036878:
    .4byte 0x000007D2
.Lde_0803687C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_080368B4
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_080368B4
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_080368B4
    ldr r7, .Lde_080368D0
    ldr r0, .Lde_080368D4
    mov	r8, r0
.Lde_080368B4:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_080368D0:
    .4byte 0x000007CA
.Lde_080368D4:
    .4byte 0x000007CE
    .global func_080369C4
    .thumb_func
func_080369C4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_080368EC
    adds	r0, r5, #0
    bl func_08036900
.Lde_080368EC:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080369E0
    .thumb_func
func_080369E0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036900
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A10
    .thumb_func
func_08036A10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036950
    str	r0, [sp, #0]
    ldr r0, .Lde_08036954
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036958
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_0803695C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036950:
    .4byte gUnk_080F6FF8
.Lde_08036954:
    .4byte 0x00000902
.Lde_08036958:
    .4byte 0x00000401
.Lde_0803695C:
    .4byte vtable_unk_080E6B18
    .global func_08036A4C
    .thumb_func
func_08036A4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A78
    .thumb_func
func_08036A78:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_080369B8
    str	r0, [sp, #0]
    ldr r0, .Lde_080369BC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_080369C0
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_080369C4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080369B8:
    .4byte gUnk_080F7B40
.Lde_080369BC:
    .4byte 0x000009D3
.Lde_080369C0:
    .4byte 0x00000404
.Lde_080369C4:
    .4byte vtable_unk_080E6AD8
    .global func_08036AB4
    .thumb_func
func_08036AB4:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Lde_080369E4
    ldr r5, .Lde_080369E8
    ldrh	r0, [r4, #4]
    adds	r2, r0, #0
    cmp	r0, #17
    beq .Lde_080369F4
    cmp	r0, #17
    bgt .Lde_080369EC
    cmp	r0, #7
    beq .Lde_080369F4
    b .Lde_080369F8
    .align 2, 0
.Lde_080369E4:
    .4byte 0x000009D3
.Lde_080369E8:
    .4byte 0x000009D7
.Lde_080369EC:
    cmp	r2, #29
    beq .Lde_080369F4
    cmp	r2, #37	@ 0x25
    bne .Lde_080369F8
.Lde_080369F4:
    ldr r1, .Lde_08036A0C
    ldr r5, .Lde_08036A10
.Lde_080369F8:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035940
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Lde_08036A0C:
    .4byte 0x000009DF
.Lde_08036A10:
    .4byte 0x000009E3
    .global func_08036B00
    .thumb_func
func_08036B00:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_08036A28
    adds	r0, r5, #0
    bl func_08036AB4
.Lde_08036A28:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036B1C
    .thumb_func
func_08036B1C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036AB4
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036B4C
    .thumb_func
func_08036B4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036A8C
    str	r0, [sp, #0]
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #201	@ 0xc9
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036A90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036A8C:
    .4byte gUnk_080F2DC0
.Lde_08036A90:
    .4byte vtable_unk_080E6A98
    .global func_08036B80
    .thumb_func
func_08036B80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036BB0
    .thumb_func
func_08036BB0:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    movs	r0, #10
    ldrsh	r5, [r4, r0]
    movs	r2, #14
    ldrsh	r6, [r4, r2]
    adds	r0, r4, #0
    bl func_08034EB4
    ldrh	r0, [r4, #4]
    cmp	r0, #2
    bne .Lde_08036B04
    cmp	r5, #244	@ 0xf4
    bne .Lde_08036AE4
    cmp	r6, #171	@ 0xab
    beq .Lde_08036B04
.Lde_08036AE4:
    movs	r1, #10
    ldrsh	r0, [r4, r1]
    movs	r2, #14
    ldrsh	r1, [r4, r2]
    cmp	r0, #244	@ 0xf4
    bne .Lde_08036B04
    cmp	r1, #171	@ 0xab
    bne .Lde_08036B04
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Lde_08036B04:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036BF8
    .thumb_func
func_08036BF8:
    push	{r4, r5, r6, r7, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    movs	r0, #10
    ldrsh	r6, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_08036B54
    ldrh	r0, [r5, #4]
    cmp	r0, #2
    bne .Lde_08036B54
    cmp	r6, #244	@ 0xf4
    bne .Lde_08036B34
    cmp	r7, #171	@ 0xab
    beq .Lde_08036B54
.Lde_08036B34:
    movs	r2, #10
    ldrsh	r0, [r5, r2]
    movs	r2, #14
    ldrsh	r1, [r5, r2]
    cmp	r0, #244	@ 0xf4
    bne .Lde_08036B54
    cmp	r1, #171	@ 0xab
    bne .Lde_08036B54
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Lde_08036B54:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036C48
    .thumb_func
func_08036C48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036B88
    str	r0, [sp, #0]
    ldr r0, .Lde_08036B8C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #254	@ 0xfe
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036B90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08036B88:
    .4byte gUnk_080F597C
.Lde_08036B8C:
    .4byte 0x00000857
.Lde_08036B90:
    .4byte vtable_unk_080E6A58
    .global func_08036C80
    .thumb_func
func_08036C80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036CAC
    .thumb_func
func_08036CAC:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lde_08036BE8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036BEC
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lde_08036BE8:
    .4byte 0x00000679
.Lde_08036BEC:
    .4byte vtable_unk_080E6A18
    .global func_08036CDC
    .thumb_func
func_08036CDC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036D0C
    .thumb_func
func_08036D0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lde_08036C48
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036C4C
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lde_08036C48:
    .4byte 0x00000669
.Lde_08036C4C:
    .4byte vtable_unk_080E69D8
    .global func_08036D3C
    .thumb_func
func_08036D3C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036D68
    .thumb_func
func_08036D68:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lde_08036CA4
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036CA8
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036CA4:
    .4byte 0x000007FE
.Lde_08036CA8:
    .4byte vtable_unk_080E6998
    .global func_08036D98
    .thumb_func
func_08036D98:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036DC4
    .thumb_func
func_08036DC4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036D04
    str	r0, [sp, #0]
    ldr r0, .Lde_08036D08
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lde_08036D0C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036D10
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036D04:
    .4byte gUnk_080F6B10
.Lde_08036D08:
    .4byte 0x000008D8
.Lde_08036D0C:
    .4byte 0x000003FE
.Lde_08036D10:
    .4byte vtable_unk_080E6958
    .global func_08036E00
    .thumb_func
func_08036E00:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036E2C
    .thumb_func
func_08036E2C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lde_08036D74
    str	r0, [sp, #0]
    ldr r0, .Lde_08036D78
    str	r0, [sp, #4]
    adds	r0, #8
    str	r0, [sp, #8]
    ldr r0, .Lde_08036D7C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lde_08036D80
    str	r0, [r4, #20]
    adds	r1, r4, #0
    adds	r1, #72	@ 0x48
    movs	r0, #0
    strh	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036D74:
    .4byte gUnk_080F29C0
.Lde_08036D78:
    .4byte 0x00000267
.Lde_08036D7C:
    .4byte 0x000003E3
.Lde_08036D80:
    .4byte vtable_unk_080E6918
    .global func_08036E70
    .thumb_func
func_08036E70:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Lde_08036DB4
    adds	r0, r0, r1
    bl func_080A0384
    adds	r6, r0, #0
    cmp	r0, #0
    beq .Lde_08036DF4
    ldr r5, .Lde_08036DB8
    ldr r7, .Lde_08036DBC
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_08036DC0
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08036DE4
    movs	r5, #12
    b .Lde_08036DE4
.Lde_08036DB4:
    .4byte 0x00001CD4
.Lde_08036DB8:
    .4byte 0x00000267
.Lde_08036DBC:
    .4byte 0x0000026F
.Lde_08036DC0:
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08036DD4
    ldr r5, .Lde_08036DD0
    b .Lde_08036DE4
.Lde_08036DD0:
    .4byte 0x00000277
.Lde_08036DD4:
    adds	r0, r6, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08036DE4
    ldr r5, .Lde_08036DFC
    ldr r7, .Lde_08036E00
.Lde_08036DE4:
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035940
.Lde_08036DF4:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08036DFC:
    .4byte 0x0000026B
.Lde_08036E00:
    .4byte 0x00000273
    .global func_08036EF0
    .thumb_func
func_08036EF0:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lde_08036E18
    adds	r0, r5, #0
    bl func_08036E70
.Lde_08036E18:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036F0C
    .thumb_func
func_08036F0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    ldr r1, .Lde_08036E6C
    adds	r0, r0, r1
    bl func_080A0384
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_08036E70
    adds	r0, r5, #0
    bl func_08036E70
    adds	r0, r4, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    movs	r4, #1
    cmp	r0, #0
    beq .Lde_08036E4C
    movs	r4, #4
.Lde_08036E4C:
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r5, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    b .Lde_08036E72
    .align 2, 0
.Lde_08036E6C:
    .4byte 0x00001CD4
.Lde_08036E70:
    movs	r0, #0
.Lde_08036E72:
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036F68
    .thumb_func
func_08036F68:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r6, r1, #0
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Lde_08036F06
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Lde_08036EBC
    adds	r0, r0, r1
    bl func_080A0384
    cmp	r0, #0
    beq .Lde_08036F06
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lde_08036F06
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08036F06
    adds	r0, r4, #0
    adds	r0, #72	@ 0x48
    ldrh	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lde_08036EC0
    subs	r0, r1, #1
    b .Lde_08036F04
.Lde_08036EBC:
    .4byte 0x00001CD4
.Lde_08036EC0:
    mov	r1, sp
    ldr r0, .Lde_08036EDC
    ldmia	r0!, {r2, r3, r7}
    stmia	r1!, {r2, r3, r7}
    ldr	r0, [r0, #0]
    str	r0, [r1, #0]
    bl rand
    movs	r1, #100	@ 0x64
    bl __modsi3
    movs	r3, #0
    mov	r2, sp
    b .Lde_08036EE6
.Lde_08036EDC:
    .4byte gUnk_080F1514
.Lde_08036EE0:
    subs	r0, r0, r1
    adds	r2, #4
    adds	r3, #1
.Lde_08036EE6:
    cmp	r3, #3
    bhi .Lde_08036EF8
    ldrb	r1, [r2, #0]
    cmp	r0, r1
    bcs .Lde_08036EE0
    ldrh	r1, [r2, #2]
    adds	r0, r4, #0
    bl func_08035908
.Lde_08036EF8:
    bl rand
    movs	r1, #120	@ 0x78
    bl __modsi3
    adds	r0, #120	@ 0x78
.Lde_08036F04:
    strh	r0, [r5, #0]
.Lde_08036F06:
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_08034EB4
    add	sp, #16
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x47706B40
    .global func_08037008
    .thumb_func
func_08037008:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r4, r0, #0
    adds	r5, r2, #0
    ldr	r6, [sp, #20]
    str	r3, [sp, #0]
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lde_08036F58
    str	r0, [r4, #20]
    str	r5, [r4, #48]	@ 0x30
    adds	r1, r4, #0
    adds	r1, #52	@ 0x34
    movs	r0, #0
    strh	r0, [r4, #52]	@ 0x34
    strh	r0, [r1, #2]
    strh	r0, [r1, #4]
    strh	r0, [r1, #6]
    strh	r6, [r4, #60]	@ 0x3c
    strh	r0, [r4, #62]	@ 0x3e
    adds	r1, #12
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08036F58:
    .4byte vtable_unk_080E7328
    .global func_08037048
    .thumb_func
func_08037048:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lde_08036FA4
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldr r0, .Lde_08036FA8
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_08036F8E
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08036F8E:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lde_08036F9C
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_08036F9C:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Lde_08036FA4:
    .4byte vtable_unk_080E7328
.Lde_08036FA8:
    .4byte __vt_7AEntity
    .global func_08037098
    .thumb_func
func_08037098:
    push	{r4, r5, lr}
    adds	r3, r0, #0
    movs	r4, #0
    movs	r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r0, #0
    cmp	r0, #1
    beq .Lde_08036FD6
    cmp	r0, #1
    bgt .Lde_08036FC8
    cmp	r0, #0
    beq .Lde_08036FD2
    b .Lde_08036FE0
.Lde_08036FC8:
    cmp	r2, #2
    beq .Lde_08036FDA
    cmp	r2, #3
    beq .Lde_08036FDE
    b .Lde_08036FE0
.Lde_08036FD2:
    adds	r5, r1, #0
    b .Lde_08036FE0
.Lde_08036FD6:
    negs	r5, r1
    b .Lde_08036FE0
.Lde_08036FDA:
    negs	r4, r1
    b .Lde_08036FE0
.Lde_08036FDE:
    adds	r4, r1, #0
.Lde_08036FE0:
    str	r4, [r3, #24]
    str	r5, [r3, #28]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_08037022
    movs	r4, #0
    adds	r2, r0, #0
    adds	r2, #48	@ 0x30
    movs	r1, #0
    ldrh	r0, [r2, #14]
    cmp	r0, #0
    beq .Lde_0803700C
    movs	r0, #16
    ldrsh	r1, [r2, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r1, r0, #31
.Lde_0803700C:
    cmp	r1, #0
    beq .Lde_0803701C
    adds	r0, r2, #0
    bl func_0805E894
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803701E
.Lde_0803701C:
    movs	r4, #1
.Lde_0803701E:
    adds	r0, r4, #0
    b .Lde_08037024
.Lde_08037022:
    movs	r0, #1
.Lde_08037024:
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037118
    .thumb_func
func_08037118:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r7, r0, #0
    adds	r4, r1, #0
    ldr	r1, [r7, #8]
    ldr	r2, [r7, #12]
    ldr	r0, [r7, #24]
    adds	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r7, #28]
    adds	r0, r0, r2
    mov	r8, r0
    asrs	r1, r1, #16
    str	r1, [sp, #0]
    asrs	r6, r2, #16
    asrs	r0, r0, #16
    subs	r5, r0, r6
    mov	r1, r9
    asrs	r0, r1, #16
    ldr	r1, [sp, #0]
    subs	r1, r0, r1
    mov	sl, r1
    cmp	r5, #0
    ble .Lde_08037096
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lde_08037076
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Lde_08037078
.Lde_08037076:
    adds	r0, r1, #0
.Lde_08037078:
    cmp	r5, r0
    ble .Lde_08037096
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lde_0803708E
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Lde_08037090
.Lde_0803708E:
    adds	r0, r1, #0
.Lde_08037090:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Lde_08037096:
    cmp	r5, #0
    bge .Lde_080370CC
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lde_080370AC
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Lde_080370AE
.Lde_080370AC:
    adds	r0, r1, #0
.Lde_080370AE:
    cmp	r5, r0
    bge .Lde_080370CC
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lde_080370C4
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Lde_080370C6
.Lde_080370C4:
    adds	r0, r1, #0
.Lde_080370C6:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Lde_080370CC:
    mov	r0, sl
    cmp	r0, #0
    bge .Lde_08037106
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lde_080370E4
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Lde_080370E6
.Lde_080370E4:
    adds	r0, r1, #0
.Lde_080370E6:
    cmp	sl, r0
    bge .Lde_08037106
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lde_080370FC
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Lde_080370FE
.Lde_080370FC:
    adds	r0, r1, #0
.Lde_080370FE:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Lde_08037106:
    mov	r0, sl
    cmp	r0, #0
    ble .Lde_08037140
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lde_0803711E
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Lde_08037120
.Lde_0803711E:
    adds	r0, r1, #0
.Lde_08037120:
    cmp	sl, r0
    ble .Lde_08037140
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lde_08037136
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Lde_08037138
.Lde_08037136:
    adds	r0, r1, #0
.Lde_08037138:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Lde_08037140:
    mov	r0, r9
    str	r0, [r7, #8]
    mov	r1, r8
    str	r1, [r7, #12]
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037244
    .thumb_func
func_08037244:
    ldr	r2, [r1, #4]
    ldr	r1, [r1, #0]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    bx	lr
    .align 2, 0
    sub	sp, #8
    mov	r3, sp
    movs	r1, #0
    mov	r2, sp
    strh	r1, [r2, #0]
    strh	r1, [r3, #2]
    strh	r1, [r3, #4]
    strh	r1, [r3, #6]
    ldr	r1, [sp, #0]
    ldr	r2, [sp, #4]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    add	sp, #8
    bx	lr
    .global func_0803726C
    .thumb_func
func_0803726C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #96	@ 0x60
    adds	r7, r0, #0
    ldr	r4, [r7, #0]
    ldrh	r0, [r7, #4]
    mov	r8, r0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #20]
    adds	r0, r4, #0
    bl _call_via_r1
    cmp	r0, r8
    beq .Lde_080371A2
    b .Lde_08037316
.Lde_080371A2:
    ldr	r1, [r4, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r4, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #64	@ 0x40
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    str	r1, [sp, #88]	@ 0x58
    str	r2, [sp, #92]	@ 0x5c
    add	r4, sp, #12
    movs	r2, #32
    mov	r9, r2
    movs	r5, #0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r1, r9
    str	r1, [r4, #40]	@ 0x28
    str	r5, [r4, #44]	@ 0x2c
    str	r5, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r9, r4
    cmp	r3, #0
    beq .Lde_08037224
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Lde_08037224
    ldr	r1, [r3, #20]
    add	r4, sp, #72	@ 0x48
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lde_08037224:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lde_08037254
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Lde_08037254
    ldr	r1, [r3, #20]
    add	r4, sp, #80	@ 0x50
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lde_08037254:
    adds	r2, r7, #0
    adds	r2, #52	@ 0x34
    movs	r3, #4
    ldrsh	r0, [r2, r3]
    movs	r6, #52	@ 0x34
    ldrsh	r1, [r7, r6]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Lde_0803727E
    movs	r1, #6
    ldrsh	r0, [r2, r1]
    movs	r3, #2
    ldrsh	r1, [r2, r3]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Lde_0803727E
    mov	r0, r9
    adds	r1, r2, #0
    movs	r2, #0
    bl func_080ABA90
.Lde_0803727E:
    ldrh	r4, [r7, #62]	@ 0x3e
    cmp	r4, #0
    beq .Lde_08037300
    ldr	r5, [r7, #24]
    ldr	r6, [r7, #28]
    cmp	r5, #0
    bge .Lde_080372A4
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lde_0803729E
    add	r0, sp, #12
    bl func_080AB948
    ldr	r0, [sp, #20]
    b .Lde_080372A0
.Lde_0803729E:
    adds	r0, r1, #0
.Lde_080372A0:
    cmp	r0, #0
    bge .Lde_080372F8
.Lde_080372A4:
    cmp	r5, #0
    ble .Lde_080372C0
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lde_080372BA
    add	r0, sp, #12
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Lde_080372BC
.Lde_080372BA:
    adds	r0, r1, #0
.Lde_080372BC:
    cmp	r0, #0
    ble .Lde_080372F8
.Lde_080372C0:
    cmp	r6, #0
    bge .Lde_080372DC
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lde_080372D6
    add	r0, sp, #12
    bl func_080AB8D0
    ldr	r0, [sp, #16]
    b .Lde_080372D8
.Lde_080372D6:
    adds	r0, r1, #0
.Lde_080372D8:
    cmp	r0, #0
    bge .Lde_080372F8
.Lde_080372DC:
    cmp	r6, #0
    ble .Lde_080372FC
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lde_080372F2
    add	r0, sp, #12
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Lde_080372F4
.Lde_080372F2:
    adds	r0, r1, #0
.Lde_080372F4:
    cmp	r0, #0
    bgt .Lde_080372FC
.Lde_080372F8:
    movs	r4, #0
    b .Lde_0803730C
.Lde_080372FC:
    subs	r4, #1
    b .Lde_0803730C
.Lde_08037300:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #64]	@ 0x40
    adds	r0, r7, #0
    bl _call_via_r1
    adds	r4, r0, #0
.Lde_0803730C:
    strh	r4, [r7, #62]	@ 0x3e
    adds	r0, r7, #0
    mov	r1, r9
    bl func_08037118
.Lde_08037316:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_08037320
    subs	r0, #1
    b .Lde_08037322
.Lde_08037320:
    ldrh	r0, [r7, #38]	@ 0x26
.Lde_08037322:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Lde_08037334
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lde_08037334:
    add	sp, #96	@ 0x60
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037430
    .thumb_func
func_08037430:
    ldrh	r0, [r0, #60]	@ 0x3c
    bx	lr
    .global func_08037434
    .thumb_func
func_08037434:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #64	@ 0x40
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lde_0803735E
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    bl _call_via_r1
.Lde_0803735E:
    movs	r0, #0
    strh	r0, [r4, #62]	@ 0x3e
    adds	r0, r4, #0
    bl vfunc_10__7AEntity
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803745C
    .thumb_func
func_0803745C:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    adds	r4, #64	@ 0x40
    movs	r0, #0
    strb	r0, [r4, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037470
    .thumb_func
func_08037470:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #9
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0
    .global func_08037494
    .thumb_func
func_08037494:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lde_080373CC
    movs	r1, #1
.Lde_080373CC:
    lsls	r4, r1, #2
    adds	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Lde_0803744C
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #5
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lde_0803741C
    cmp	r1, #3
    beq .Lde_0803741C
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_0803741C
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_0803741C:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037628
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_08037442
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lde_08037442:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803744C:
    .4byte gUnk_080F1538
    .global func_0803753C
    .thumb_func
func_0803753C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #7
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #9
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037568
    .thumb_func
func_08037568:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Lde_08037514
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Lde_080374D6
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lde_080374D6:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #0
    beq .Lde_08037514
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Lde_08037514
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A17A0
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_0803751E
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Lde_0803751E
.Lde_08037514:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Lde_0803751E:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037618
    .thumb_func
func_08037618:
    ldr r0, .Lde_08037538
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lde_08037538:
    .4byte gUnk_080F1560
    .global func_08037628
    .thumb_func
func_08037628:
    push	{lr}
    cmp	r1, #1
    beq .Lde_08037546
    movs	r0, #0
    b .Lde_0803754A
.Lde_08037546:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lde_0803754A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803763C
    .thumb_func
func_0803763C:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lde_08037574
    movs	r1, #1
.Lde_08037574:
    lsls	r4, r1, #3
    subs	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Lde_080375F4
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #7
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lde_080375C4
    cmp	r1, #3
    beq .Lde_080375C4
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_080375C4
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_080375C4:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377D4
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080375EA
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lde_080375EA:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080375F4:
    .4byte gUnk_080F156C
    .global func_080376E4
    .thumb_func
func_080376E4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #2
    str	r1, [sp, #0]
    movs	r1, #12
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #12
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037714
    .thumb_func
func_08037714:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Lde_080376C0
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Lde_08037682
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lde_08037682:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #1
    beq .Lde_080376C0
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Lde_080376C0
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A1890
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080376CA
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Lde_080376CA
.Lde_080376C0:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Lde_080376CA:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080377C4
    .thumb_func
func_080377C4:
    ldr r0, .Lde_080376E4
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lde_080376E4:
    .4byte gUnk_080F15A4
    .global func_080377D4
    .thumb_func
func_080377D4:
    push	{lr}
    cmp	r1, #1
    beq .Lde_080376F2
    movs	r0, #0
    b .Lde_080376F6
.Lde_080376F2:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lde_080376F6:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080377E8
    .thumb_func
func_080377E8:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r4, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lde_08037720
    movs	r4, #1
.Lde_08037720:
    movs	r0, #52	@ 0x34
    muls	r4, r0
    ldr r0, .Lde_0803779C
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #13
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lde_0803776E
    cmp	r1, #3
    beq .Lde_0803776E
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_0803776E
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_0803776E:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378FC
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_08037794
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lde_08037794:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lde_0803779C:
    .4byte gUnk_080F15B4
    .global func_0803788C
    .thumb_func
func_0803788C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080378B8
    .thumb_func
func_080378B8:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A198C
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080377F6
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lde_080377F6:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080378EC
    .thumb_func
func_080378EC:
    ldr r0, .Lde_0803780C
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lde_0803780C:
    .4byte gUnk_080F161C
    .global func_080378FC
    .thumb_func
func_080378FC:
    push	{lr}
    cmp	r1, #12
    bhi .Lde_08037858
    lsls	r0, r1, #2
    ldr r1, .Lde_08037820
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_08037820:
    .4byte .Lde_08037824
.Lde_08037824:
    .4byte .Lde_08037858
    .4byte .Lde_0803785C
    .4byte .Lde_08037862
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037858
    .4byte .Lde_08037862
    .4byte .Lde_08037858
.Lde_08037858:
    movs	r0, #0
    b .Lde_08037866
.Lde_0803785C:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE001
.Lde_08037862:
    .hword 0x2080
    .hword 0x0240
.Lde_08037866:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037958
    .thumb_func
func_08037958:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr r5, .Lde_080378E8
    adds	r0, r5, #0
    movs	r1, #3
    bl func_080AB82C
    lsls	r4, r0, #2
    adds	r4, r4, r5
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lde_080378B8
    cmp	r1, #3
    beq .Lde_080378B8
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_080378B8
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_080378B8:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A48
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080378DE
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lde_080378DE:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080378E8:
    .4byte gUnk_080F1638
    .global func_080379D8
    .thumb_func
func_080379D8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037A04
    .thumb_func
func_08037A04:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A19EC
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_08037942
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lde_08037942:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037A38
    .thumb_func
func_08037A38:
    ldr r0, .Lde_08037958
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lde_08037958:
    .4byte gUnk_080F1644
    .global func_08037A48
    .thumb_func
func_08037A48:
    push	{lr}
    cmp	r1, #1
    beq .Lde_08037966
    movs	r0, #0
    b .Lde_0803796A
.Lde_08037966:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lde_0803796A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037A5C
    .thumb_func
func_08037A5C:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    ldr r3, .Lde_080379DC
    bl func_08037008
    ldr r0, .Lde_080379E0
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080379DC:
    .4byte 0x0000071C
.Lde_080379E0:
    .4byte vtable_unk_080E72E4
    .global func_08037AD0
    .thumb_func
func_08037AD0:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    bl func_08037008
    ldr r0, .Lde_08037A58
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08037A58:
    .4byte vtable_unk_080E72A0
    .global func_08037B48
    .thumb_func
func_08037B48:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Lde_08037A8C
    bl func_08037008
    ldr r0, .Lde_08037A90
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08037A8C:
    .4byte 0x00000379
.Lde_08037A90:
    .4byte vtable_unk_080E725C
    .global func_08037B80
    .thumb_func
func_08037B80:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Lde_08037AC4
    bl func_08037008
    ldr r0, .Lde_08037AC8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08037AC4:
    .4byte 0x00000207
.Lde_08037AC8:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Lde_08037AEC
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Lde_08037AF0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08037AEC:
    .4byte 0x00000207
.Lde_08037AF0:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Lde_08037B14
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Lde_08037B18
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08037B14:
    .4byte 0x00000379
.Lde_08037B18:
    .4byte vtable_unk_080E725C
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Lde_08037B78
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lde_08037B78:
    .4byte vtable_unk_080E72A0
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    ldr r3, .Lde_08037BD0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Lde_08037BD4
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lde_08037BD0:
    .4byte 0x0000071C
.Lde_08037BD4:
    .4byte vtable_unk_080E72E4
    .global func_08037CC4
    .thumb_func
func_08037CC4:
    push	{r4, lr}
    adds	r4, r0, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lde_08037BEC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_08037BEC:
    .4byte vtable_unk_080E7444
    .global func_08037CDC
    .thumb_func
func_08037CDC:
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r3, #14
    ldrsh	r1, [r1, r3]
    strh	r2, [r0, #0]
    adds	r1, #1
    strh	r1, [r0, #2]
    strh	r2, [r0, #4]
    strh	r1, [r0, #6]
    bx	lr
    .global func_08037CF0
    .thumb_func
func_08037CF0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037D08
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037D08
    .thumb_func
func_08037D08:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Lde_08037C7C
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #10
    bl func_080A4740
    ldr r0, .Lde_08037C80
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #125	@ 0x7d
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lde_08037C7C:
    .4byte vtable_unk_080E7478
.Lde_08037C80:
    .4byte vtable_unk_080E602C
    .global func_08037D70
    .thumb_func
func_08037D70:
    bx	lr
    .align 2, 0
    .global func_08037D74
    .thumb_func
func_08037D74:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r2, [r3, r0]
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    subs	r0, r2, r0
    mov	ip, r0
    ldr	r0, [r1, #0]
    ldr	r3, [r1, #8]
    str	r0, [sp, #20]
    str	r3, [sp, #24]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r2
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r2, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08037CF4
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r8
    mov	r2, ip
    movs	r3, #170	@ 0xaa
    ldr r4, .Lde_08037CF0
    bl _call_via_r4
    b .Lde_08037CF6
    .align 2, 0
.Lde_08037CF0:
    .4byte func_030004DC
.Lde_08037CF4:
    movs	r0, #0
.Lde_08037CF6:
    cmp	r0, #0
    beq .Lde_08037D20
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_08037D20
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_08037D20:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037E18
    .thumb_func
func_08037E18:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    mov	r0, sp
    adds	r1, r6, #0
    bl func_0800FFE0
    adds	r0, r4, #0
    adds	r1, r5, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lde_08037D58
    str	r0, [r4, #20]
    str	r6, [r4, #24]
    adds	r0, r4, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lde_08037D58:
    .4byte vtable_unk_080E73FC
    .global func_08037E48
    .thumb_func
func_08037E48:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lde_08037DA8
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl func_08010014
    ldr r0, .Lde_08037DAC
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_08037D90
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08037D90:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lde_08037D9E
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_08037D9E:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08037DA8:
    .4byte vtable_unk_080E73FC
.Lde_08037DAC:
    .4byte __vt_7AEntity
    .global func_08037E9C
    .thumb_func
func_08037E9C:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #88	@ 0x58
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037EF0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037EB4
    .thumb_func
func_08037EB4:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #24]
    ldrb	r1, [r1, #0]
    bl func_0800FFF4
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Lde_08037DDE
    bl func_08037F74
.Lde_08037DDE:
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037ED0
    .thumb_func
func_08037ED0:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_08037EF0
    .thumb_func
func_08037EF0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Lde_08037E6C
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #8
    bl func_080A4740
    ldr r0, .Lde_08037E70
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #53	@ 0x35
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    adds	r0, #84	@ 0x54
    strb	r2, [r0, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lde_08037E6C:
    .4byte vtable_unk_080E7430
.Lde_08037E70:
    .4byte vtable_unk_080E602C
    .global func_08037F60
    .thumb_func
func_08037F60:
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #84	@ 0x54
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Lde_08037E84
    subs	r0, #1
    strb	r0, [r1, #0]
.Lde_08037E84:
    pop	{r0}
    bx	r0
    .global func_08037F74
    .thumb_func
func_08037F74:
    adds	r0, #84	@ 0x54
    movs	r1, #10
    strb	r1, [r0, #0]
    bx	lr
    .global func_08037F7C
    .thumb_func
func_08037F7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r3, [r3, r0]
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    subs	r2, r3, r0
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    mov	ip, r1
    str	r0, [sp, #20]
    str	r1, [sp, #24]
    adds	r0, r4, #0
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08037EC8
    subs	r2, #2
.Lde_08037EC8:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r3
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r3, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08037F04
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    mov	r1, r8
    movs	r3, #170	@ 0xaa
    ldr r4, .Lde_08037F00
    bl _call_via_r4
    b .Lde_08037F06
.Lde_08037F00:
    .4byte func_030004DC
.Lde_08037F04:
    movs	r0, #0
.Lde_08037F06:
    cmp	r0, #0
    beq .Lde_08037F30
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_08037F30
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_08037F30:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038028
    .thumb_func
func_08038028:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r6, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lde_08037FA8
    str	r0, [r6, #20]
    str	r4, [r6, #24]
    movs	r0, #0
    str	r0, [r6, #28]
    adds	r1, r6, #0
    adds	r1, #37	@ 0x25
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    movs	r0, #49	@ 0x31
    strh	r0, [r6, #40]	@ 0x28
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_08037F9C
    ldrh	r0, [r4, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Lde_08037F9C
    adds	r0, r4, #0
    bl func_08020460
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08037F9C
    ldr	r1, [r4, #8]
    ldr	r2, [r4, #12]
    ldrh	r3, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r6, #0
    bl func_08038374
.Lde_08037F9C:
    adds	r0, r6, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08037FA8:
    .4byte vtable_unk_080E73B4
    .global func_08038098
    .thumb_func
func_08038098:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lde_08037FF8
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    ldr r0, .Lde_08037FFC
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_08037FE2
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08037FE2:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lde_08037FF0
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_08037FF0:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Lde_08037FF8:
    .4byte vtable_unk_080E73B4
.Lde_08037FFC:
    .4byte __vt_7AEntity
    .global func_080380EC
    .thumb_func
func_080380EC:
    adds	r2, r0, #0
    adds	r2, #36	@ 0x24
    strb	r1, [r2, #0]
    movs	r1, #168	@ 0xa8
    lsls	r1, r1, #13
    str	r1, [r0, #28]
    movs	r1, #192	@ 0xc0
    lsls	r1, r1, #10
    str	r1, [r0, #32]
    adds	r0, #37	@ 0x25
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038108
    .thumb_func
func_08038108:
    adds	r0, #37	@ 0x25
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038110
    .thumb_func
func_08038110:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #68	@ 0x44
    adds	r6, r0, #0
    adds	r4, r6, #0
    adds	r4, #37	@ 0x25
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_0803803A
    b .Lde_08038208
.Lde_0803803A:
    ldr	r7, [r6, #0]
    ldrh	r2, [r6, #4]
    ldr	r1, [r7, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r7, #0
    bl _call_via_r3
    mov	r8, sp
    ldr	r1, [r6, #32]
    ldr r0, .Lde_080380B4
    adds	r1, r1, r0
    str	r1, [r6, #32]
    ldr	r0, [r6, #28]
    adds	r0, r0, r1
    str	r0, [r6, #28]
    cmp	r0, #0
    bgt .Lde_08038060
    b .Lde_08038170
.Lde_08038060:
    ldr	r1, [r6, #20]
    add	r0, sp, #52	@ 0x34
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r1, [sp, #52]	@ 0x34
    ldr	r2, [sp, #56]	@ 0x38
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    add	r5, sp, #12
    movs	r2, #32
    mov	r8, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r5, #4]
    str	r0, [r5, #8]
    str	r1, [r5, #12]
    add	r1, sp, #28
    mov	r0, sp
    ldmia	r0!, {r2, r3, r4}
    stmia	r1!, {r2, r3, r4}
    ldr	r3, [sp, #60]	@ 0x3c
    ldr	r4, [sp, #64]	@ 0x40
    str	r3, [sp, #40]	@ 0x28
    str	r4, [sp, #44]	@ 0x2c
    mov	r4, r8
    str	r4, [r5, #36]	@ 0x24
    ldr	r4, [r6, #8]
    ldr	r7, [r6, #12]
    adds	r0, r6, #0
    adds	r0, #36	@ 0x24
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lde_080380C2
    cmp	r0, #1
    bgt .Lde_080380B8
    cmp	r0, #0
    beq .Lde_080380E8
    b .Lde_08038164
.Lde_080380B4:
    .4byte 0xFFFFB85D
.Lde_080380B8:
    cmp	r0, #2
    beq .Lde_08038144
    cmp	r0, #3
    beq .Lde_08038118
    b .Lde_08038164
.Lde_080380C2:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Lde_080380D4
    adds	r0, r5, #0
    bl func_080ABBC4
    ldr	r0, [sp, #16]
    b .Lde_080380D6
.Lde_080380D4:
    adds	r0, r1, #0
.Lde_080380D6:
    lsls	r1, r0, #16
    ldr r0, .Lde_080380E4
    cmp	r1, r0
    bgt .Lde_08038104
    ldr r5, .Lde_080380E4
    adds	r7, r7, r5
    b .Lde_08038164
.Lde_080380E4:
    .4byte 0xFFFE38E4
.Lde_080380E8:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Lde_080380FA
    adds	r0, r5, #0
    bl func_080ABBA0
    ldr	r0, [sp, #12]
    b .Lde_080380FC
.Lde_080380FA:
    adds	r0, r1, #0
.Lde_080380FC:
    lsls	r1, r0, #16
    ldr r0, .Lde_08038108
    cmp	r1, r0
    bgt .Lde_0803810C
.Lde_08038104:
    adds	r7, r7, r1
    b .Lde_08038164
.Lde_08038108:
    .4byte 0x0001C71B
.Lde_0803810C:
    ldr r0, .Lde_08038114
    adds	r7, r7, r0
    b .Lde_08038164
    .align 2, 0
.Lde_08038114:
    .4byte 0x0001C71C
.Lde_08038118:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Lde_0803812A
    adds	r0, r5, #0
    bl func_080ABC14
    ldr	r0, [sp, #24]
    b .Lde_0803812C
.Lde_0803812A:
    adds	r0, r1, #0
.Lde_0803812C:
    lsls	r1, r0, #16
    ldr r0, .Lde_0803813C
    cmp	r1, r0
    ble .Lde_08038136
    ldr r1, .Lde_08038140
.Lde_08038136:
    adds	r4, r4, r1
    b .Lde_08038164
    .align 2, 0
.Lde_0803813C:
    .4byte 0x0001C71B
.Lde_08038140:
    .4byte 0x0001C71C
.Lde_08038144:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Lde_08038156
    adds	r0, r5, #0
    bl func_080ABBEC
    ldr	r0, [sp, #20]
    b .Lde_08038158
.Lde_08038156:
    adds	r0, r1, #0
.Lde_08038158:
    lsls	r1, r0, #16
    ldr r0, .Lde_0803816C
    cmp	r1, r0
    bgt .Lde_08038136
    ldr r2, .Lde_0803816C
    adds	r4, r4, r2
.Lde_08038164:
    str	r4, [r6, #8]
    str	r7, [r6, #12]
    b .Lde_08038208
    .align 2, 0
.Lde_0803816C:
    .4byte 0xFFFE38E4
.Lde_08038170:
    movs	r0, #0
    str	r0, [r6, #28]
    strb	r0, [r4, #0]
    add	r4, sp, #12
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #24]
    adds	r1, r4, #0
    movs	r2, #6
    bl memcpy
    ldr	r0, [r6, #8]
    ldr	r1, [r6, #12]
    asrs	r0, r0, #19
    mov	ip, r0
    asrs	r3, r1, #19
    ldr	r1, [sp, #0]
    mov	r5, r8
    ldrh	r0, [r5, #8]
    cmp	r1, #0
    beq .Lde_080381BC
    cmp	ip, r0
    bhi .Lde_080381BC
    ldrh	r2, [r5, #10]
    cmp	r3, r2
    bhi .Lde_080381BC
    ldr	r2, [sp, #4]
    muls	r0, r3
    add	r0, ip
    cmp	r2, #0
    beq .Lde_080381B6
    adds	r0, r2, r0
    ldrb	r0, [r0, #0]
.Lde_080381B6:
    lsls	r0, r0, #2
    adds	r0, r1, r0
    b .Lde_080381BE
.Lde_080381BC:
    movs	r0, #0
.Lde_080381BE:
    cmp	r0, #0
    bne .Lde_080381D6
    ldr	r0, [r7, #0]
    movs	r3, #158	@ 0x9e
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #1
    bl _call_via_r2
    b .Lde_08038208
.Lde_080381D6:
    ldr	r0, [r0, #0]
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_080381F2
    ldr	r0, [r7, #0]
    movs	r4, #158	@ 0x9e
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
    bl _call_via_r2
    b .Lde_08038208
.Lde_080381F2:
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    cmp	r0, #0
    beq .Lde_08038208
    adds	r1, r4, #0
    bl func_0802151C
.Lde_08038208:
    add	sp, #68	@ 0x44
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038300
    .thumb_func
func_08038300:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r2, [r4, #16]
    cmp	r2, #0
    beq .Lde_08038228
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lde_08038228:
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038320
    .thumb_func
func_08038320:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_2C__7AEntityUi
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038334
    .thumb_func
func_08038334:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r1, r4, #0
    bl func_0803853C
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803834C
    .thumb_func
func_0803834C:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #4
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #4
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_0803836C
    .thumb_func
func_0803836C:
    movs	r1, #30
    ldrsh	r0, [r0, r1]
    bx	lr
    .align 2, 0
    .global func_08038374
    .thumb_func
func_08038374:
    push	{r4, r5, r6, lr}
    ldr	r5, [sp, #16]
    movs	r4, #38	@ 0x26
    adds	r4, r4, r0
    mov	ip, r4
    movs	r4, #1
    mov	r6, ip
    strb	r4, [r6, #0]
    str	r1, [r0, #8]
    str	r2, [r0, #12]
    adds	r1, r3, #0
    adds	r2, r5, #0
    bl func_08038398
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038398
    .thumb_func
func_08038398:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    movs	r3, #21
    ldr r4, .Lde_080382C8
    adds	r0, r1, r4
    cmp	r0, #61	@ 0x3d
    bls .Lde_080382BC
    b .Lde_080383DE
.Lde_080382BC:
    lsls	r0, r0, #2
    ldr r1, .Lde_080382CC
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_080382C8:
    .4byte 0xFFFFFCC8
.Lde_080382CC:
    .4byte .Lde_080382D0
.Lde_080382D0:
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383C8
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383CC
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383D0
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383D4
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383D8
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DE
    .4byte .Lde_080383DC
.Lde_080383C8:
    .4byte 0xE0082319
.Lde_080383CC:
    .4byte 0xE006231D
.Lde_080383D0:
    .4byte 0xE0042321
.Lde_080383D4:
    .4byte 0xE0022325
.Lde_080383D8:
    .4byte 0xE0002329
.Lde_080383DC:
    .hword 0x232D
.Lde_080383DE:
    adds	r1, r3, r2
    adds	r6, r1, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r1, r0
    beq .Lde_0803840A
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Lde_08038408
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Lde_08038408:
    strh	r6, [r5, #40]	@ 0x28
.Lde_0803840A:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_080384FC
    .thumb_func
func_080384FC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r0, #49	@ 0x31
    beq .Lde_08038440
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Lde_0803843C
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    movs	r1, #49	@ 0x31
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Lde_0803843C:
    movs	r0, #49	@ 0x31
    strh	r0, [r5, #40]	@ 0x28
.Lde_08038440:
    adds	r1, r5, #0
    adds	r1, #38	@ 0x26
    movs	r0, #0
    strb	r0, [r1, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803853C
    .thumb_func
func_0803853C:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r6, r0, #0
    adds	r4, r1, #0
    str	r4, [r6, #0]
    ldr r0, .Lde_08038490
    str	r0, [r6, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r6, #0
    adds	r0, #8
    ldrh	r2, [r4, #40]	@ 0x28
    movs	r4, #2
    str	r4, [sp, #0]
    movs	r4, #7
    str	r4, [sp, #4]
    add	r5, sp, #8
    movs	r4, #0
    strb	r4, [r5, #0]
    bl func_080A4A00
    adds	r0, r6, #0
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08038490:
    .4byte vtable_unk_080E73E8
    .global func_08038580
    .thumb_func
func_08038580:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_080384B8
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_080384BC
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lde_080384BA
.Lde_080384B8:
    movs	r0, #0
.Lde_080384BA:
    strb	r0, [r1, #0]
.Lde_080384BC:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080385B0
    .thumb_func
func_080385B0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r5, r0, #0
    mov	sl, r1
    ldr	r0, [r5, #0]
    mov	r9, r0
    movs	r1, #10
    ldrsh	r6, [r0, r1]
    mov	r2, sl
    movs	r3, #12
    ldrsh	r0, [r2, r3]
    subs	r0, r6, r0
    str	r0, [sp, #60]	@ 0x3c
    mov	r0, r9
    movs	r1, #14
    ldrsh	r4, [r0, r1]
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    subs	r0, r4, r0
    str	r0, [sp, #64]	@ 0x40
    mov	r0, r9
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r4
    mov	r8, r0
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    beq .Lde_08038510
    movs	r1, #1
    negs	r1, r1
    add	r8, r1
.Lde_08038510:
    add	r0, sp, #52	@ 0x34
    mov	r2, sl
    ldr	r1, [r2, #0]
    ldr	r2, [r2, #8]
    str	r1, [sp, #52]	@ 0x34
    str	r2, [r0, #4]
    ldr	r3, [sp, #64]	@ 0x40
    str	r3, [sp, #72]	@ 0x48
    movs	r7, #2
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    bne .Lde_0803855A
    mov	r0, r9
    bl func_0803836C
    ldr	r1, [sp, #64]	@ 0x40
    subs	r1, r1, r0
    str	r1, [sp, #72]	@ 0x48
    cmp	r0, #15
    ble .Lde_0803855A
    mov	r2, r9
    ldrh	r0, [r2, #4]
    cmp	r0, #8
    bgt .Lde_08038558
    cmp	r0, #2
    bne .Lde_0803855A
    ldr r3, .Lde_080385C0
    adds	r1, r6, r3
    ldr r0, .Lde_080385C4
    cmp	r1, r0
    bhi .Lde_0803855A
    cmp	r4, #175	@ 0xaf
    ble .Lde_0803855A
    subs	r0, #96	@ 0x60
    cmp	r4, r0
    bgt .Lde_0803855A
.Lde_08038558:
    movs	r7, #1
.Lde_0803855A:
    adds	r6, r5, #0
    adds	r6, #8
    mov	r0, sp
    adds	r0, #52	@ 0x34
    str	r0, [sp, #76]	@ 0x4c
    adds	r0, r7, #0
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    ldr	r1, [r5, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r5, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r1, [sp, #76]	@ 0x4c
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #8]
    ldr	r1, [r5, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_080385CC
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #24
    mov	r5, r8
    str	r5, [sp, #0]
    adds	r5, r7, #0
    str	r5, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #72]	@ 0x48
    adds	r3, r4, #0
    ldr r4, .Lde_080385C8
    bl _call_via_r4
    b .Lde_080385CE
    .align 2, 0
.Lde_080385C0:
    .4byte 0xFFFFFEF0
.Lde_080385C4:
    .4byte 0x000002AF
.Lde_080385C8:
    .4byte func_030004DC
.Lde_080385CC:
    movs	r0, #0
.Lde_080385CE:
    cmp	r0, #0
    beq .Lde_08038622
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lde_08038622
    ldr	r0, [sp, #76]	@ 0x4c
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08038604
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_0803861E
.Lde_08038604:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_0803861E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_0803861E:
    movs	r0, #0
    strb	r0, [r5, #0]
.Lde_08038622:
    ldr	r1, [sp, #68]	@ 0x44
    cmp	r1, #0
    bne .Lde_08038644
    mov	r2, r9
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #88]	@ 0x58
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    ldr	r5, [sp, #68]	@ 0x44
    str	r5, [sp, #0]
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r3, [sp, #64]	@ 0x40
    bl func_0803AE58
.Lde_08038644:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038740
    .thumb_func
func_08038740:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r2
    mov	r2, sp
    movs	r5, #8
    ldrh	r3, [r2, #0]
    ldr r4, .Lde_080386AC
    adds	r0, r4, #0
    ands	r0, r3
    orrs	r0, r5
    strh	r0, [r2, #0]
    ldrb	r5, [r2, #1]
    movs	r3, #3
    adds	r0, r3, #0
    ands	r0, r5
    strb	r0, [r2, #1]
    ldrh	r5, [r2, #2]
    adds	r0, r4, #0
    ands	r0, r5
    strh	r0, [r2, #2]
    ldrb	r0, [r2, #3]
    ands	r3, r0
    strb	r3, [r2, #3]
    ldrh	r0, [r2, #4]
    ands	r4, r0
    strh	r4, [r2, #4]
    adds	r0, r6, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lde_080386B0
    str	r0, [r6, #20]
    mov	r0, r8
    str	r0, [r6, #24]
    adds	r0, r6, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080386AC:
    .4byte 0xFFFFFC00
.Lde_080386B0:
    .4byte vtable_unk_080E7380
    .global func_080387A0
    .thumb_func
func_080387A0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #24
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08038820
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080387B8
    .thumb_func
func_080387B8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_080386D8
    bl func_08038DF0
.Lde_080386D8:
    pop	{r0}
    bx	r0
    .global func_080387C8
    .thumb_func
func_080387C8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_080386E8
    bl func_08038E90
.Lde_080386E8:
    pop	{r0}
    bx	r0
    .global func_080387D8
    .thumb_func
func_080387D8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Lde_080386F8
    movs	r0, #1
    b .Lde_080386FC
.Lde_080386F8:
    bl func_08038EA0
.Lde_080386FC:
    pop	{r1}
    bx	r1
    .global func_080387EC
    .thumb_func
func_080387EC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_0803870C
    bl func_08038EB8
.Lde_0803870C:
    pop	{r0}
    bx	r0
    .global func_080387FC
    .thumb_func
func_080387FC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_0803871C
    bl func_08038EE0
.Lde_0803871C:
    pop	{r0}
    bx	r0
    .global func_0803880C
    .thumb_func
func_0803880C:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Lde_0803872C
    movs	r0, #0
    b .Lde_08038730
.Lde_0803872C:
    bl func_080390D0
.Lde_08038730:
    pop	{r1}
    bx	r1
    .global func_08038820
    .thumb_func
func_08038820:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    str	r1, [r7, #0]
    ldr r0, .Lde_080387B0
    str	r0, [r7, #4]
    ldr	r0, [r1, #24]
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    mov	sl, r0
    cmp	r0, #1
    bne .Lde_080387B8
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r6, r0, #0
    mov	r0, r9
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #116]	@ 0x74
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Lde_080387B4
    str	r0, [r6, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r6
    mov	r8, r1
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r0, r6, #0
    adds	r0, #72	@ 0x48
    mov	r5, sl
    strb	r5, [r0, #0]
    b .Lde_080387BA
    .align 2, 0
.Lde_080387B0:
    .4byte vtable_unk_080E736C
.Lde_080387B4:
    .4byte vtable_unk_080E602C
.Lde_080387B8:
    movs	r6, #0
.Lde_080387BA:
    str	r6, [r7, #8]
    movs	r0, #0
    str	r0, [r7, #12]
    str	r0, [r7, #16]
    adds	r4, r7, #0
    adds	r4, #20
    str	r0, [r7, #20]
    movs	r0, #202	@ 0xca
    lsls	r0, r0, #1
    bl __builtin_new
    adds	r3, r0, #0
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    movs	r2, #0
    mov	r5, r9
    ldr	r0, [r5, #24]
    adds	r0, #93	@ 0x5d
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_080387EA
    movs	r2, #1
.Lde_080387EA:
    adds	r0, r3, #0
    bl func_080DCB7C
    mov	r9, r4
    mov	r8, r0
    ldr	r6, [r7, #20]
    cmp	r8, r6
    beq .Lde_08038824
    cmp	r6, #0
    beq .Lde_08038824
    ldr	r1, [r6, #0]
    lsls	r0, r1, #2
    adds	r0, r0, r1
    lsls	r0, r0, #4
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Lde_0803881E
.Lde_08038810:
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r4, #80	@ 0x50
    cmp	r4, r5
    bne .Lde_08038810
.Lde_0803881E:
    adds	r0, r6, #0
    bl __builtin_delete
.Lde_08038824:
    mov	r0, r8
    mov	r1, r9
    str	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08038928
    .thumb_func
func_08038928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    mov	r8, r0
    ldr	r0, [r0, #20]
    cmp	r0, #0
    beq .Lde_0803889E
    adds	r6, r0, #0
    movs	r7, #0
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcs .Lde_0803889E
    adds	r4, r6, #0
    adds	r4, #64	@ 0x40
    adds	r5, r6, #0
    adds	r5, #44	@ 0x2c
.Lde_08038860:
    ldrb	r0, [r4, #3]
    cmp	r0, #0
    bne .Lde_08038878
    adds	r0, r5, #0
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_0803887C
    movs	r0, #1
    strb	r0, [r4, #0]
    b .Lde_0803887C
.Lde_08038878:
    movs	r0, #0
    strb	r0, [r4, #3]
.Lde_0803887C:
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #12]
    subs	r1, r1, r0
    str	r1, [r4, #4]
    ldrb	r0, [r4, #16]
    lsls	r0, r0, #16
    cmn	r1, r0
    bge .Lde_08038892
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #17
    str	r0, [r4, #4]
.Lde_08038892:
    adds	r4, #80	@ 0x50
    adds	r5, #80	@ 0x50
    adds	r7, #1
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcc .Lde_08038860
.Lde_0803889E:
    mov	r0, r8
    ldr	r1, [r0, #12]
    cmp	r1, #0
    beq .Lde_080388C6
    adds	r3, r1, #0
    adds	r3, #80	@ 0x50
    ldrb	r0, [r3, #0]
    cmp	r0, #0
    beq .Lde_080388C6
    ldr	r0, [r1, #76]	@ 0x4c
    ldr r2, .Lde_08038908
    adds	r0, r0, r2
    str	r0, [r1, #76]	@ 0x4c
    movs	r2, #168	@ 0xa8
    lsls	r2, r2, #16
    cmp	r0, r2
    bgt .Lde_080388C6
    str	r2, [r1, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r3, #0]
.Lde_080388C6:
    mov	r1, r8
    ldr	r0, [r1, #16]
    cmp	r0, #0
    beq .Lde_08038974
    movs	r2, #0
    movs	r7, #0
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r5, r0, r1
    adds	r4, r0, #0
    adds	r4, #44	@ 0x2c
    adds	r6, r0, #0
    adds	r6, #67	@ 0x43
.Lde_080388E0:
    ldrb	r1, [r5, #0]
    cmp	r1, #0
    bne .Lde_0803891C
    ldrb	r0, [r4, #23]
    cmp	r0, #0
    bne .Lde_0803890C
    adds	r0, r4, #0
    str	r2, [sp, #0]
    bl func_0805E8F0
    adds	r1, r0, #0
    lsls	r0, r1, #30
    ldr	r2, [sp, #0]
    cmp	r0, #0
    bge .Lde_08038902
    movs	r0, #1
    strb	r0, [r4, #20]
.Lde_08038902:
    adds	r0, r1, #0
    b .Lde_08038910
    .align 2, 0
.Lde_08038908:
    .4byte 0xFFFF8000
.Lde_0803890C:
    strb	r1, [r6, #0]
    movs	r0, #2
.Lde_08038910:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lde_0803891E
    movs	r0, #1
    strb	r0, [r5, #0]
    b .Lde_0803891E
.Lde_0803891C:
    adds	r2, #1
.Lde_0803891E:
    adds	r5, #1
    adds	r4, #64	@ 0x40
    adds	r6, #64	@ 0x40
    adds	r7, #1
    cmp	r7, #4
    bls .Lde_080388E0
    movs	r0, #0
    cmp	r2, #5
    bne .Lde_08038932
    movs	r0, #1
.Lde_08038932:
    cmp	r0, #0
    beq .Lde_08038974
    mov	r7, r8
    adds	r7, #16
    movs	r2, #0
    mov	r9, r2
    mov	r0, r8
    ldr	r6, [r0, #16]
    cmp	r9, r6
    beq .Lde_08038970
    cmp	r6, #0
    beq .Lde_08038970
    ldr	r0, [r6, #0]
    lsls	r0, r0, #6
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Lde_0803896A
.Lde_08038958:
    ldr	r0, [r4, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r4, #0
    movs	r1, #2
    bl _call_via_r2
    adds	r4, #64	@ 0x40
    cmp	r4, r5
    bne .Lde_08038958
.Lde_0803896A:
    adds	r0, r6, #0
    bl __builtin_delete
.Lde_08038970:
    mov	r1, r9
    str	r1, [r7, #0]
.Lde_08038974:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038A70
    .thumb_func
func_08038A70:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #140	@ 0x8c
    str	r0, [sp, #92]	@ 0x5c
    movs	r2, #12
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #96]	@ 0x60
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #100]	@ 0x64
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #56]	@ 0x38
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #20]
    cmp	r0, #0
    bne .Lde_080389B0
    b .Lde_08038AB6
.Lde_080389B0:
    str	r0, [sp, #104]	@ 0x68
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #108]	@ 0x6c
    str	r1, [sp, #112]	@ 0x70
    movs	r1, #0
    str	r1, [sp, #116]	@ 0x74
    ldr	r2, [sp, #104]	@ 0x68
    ldr	r0, [r2, #0]
    cmp	r1, r0
    bcs .Lde_08038AB6
    adds	r5, r2, #0
    adds	r5, #64	@ 0x40
    adds	r2, #20
    str	r2, [sp, #136]	@ 0x88
    ldr	r6, [sp, #104]	@ 0x68
    adds	r6, #4
.Lde_080389D2:
    ldr	r0, [sp, #108]	@ 0x6c
    ldr	r1, [sp, #112]	@ 0x70
    str	r0, [sp, #60]	@ 0x3c
    str	r1, [sp, #64]	@ 0x40
    ldrb	r0, [r5, #17]
    cmp	r0, #0
    beq .Lde_08038A9A
    movs	r1, #6
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    movs	r1, #8
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #100]	@ 0x64
    subs	r4, r0, r2
    ldr r0, .Lde_08038A44
    mov	sl, r0
    add	r1, sp, #60	@ 0x3c
    mov	r8, r1
    ldr	r1, [r6, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r6, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, r8
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    ldr	r1, [r6, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08038A4C
    ldrh	r0, [r6, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #136]	@ 0x88
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Lde_08038A48
    bl _call_via_r4
    b .Lde_08038A4E
.Lde_08038A44:
    .4byte 0x00007FFF
.Lde_08038A48:
    .4byte func_030004DC
.Lde_08038A4C:
    movs	r0, #0
.Lde_08038A4E:
    cmp	r0, #0
    beq .Lde_08038A96
    ldrb	r0, [r5, #0]
    adds	r4, r5, #0
    cmp	r0, #0
    beq .Lde_08038A96
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    ldrb	r0, [r5, #1]
    cmp	r0, #0
    beq .Lde_08038A7C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_08038A92
.Lde_08038A7C:
    ldrb	r0, [r5, #2]
    cmp	r0, #0
    bne .Lde_08038A92
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r5, #2]
.Lde_08038A92:
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_08038A96:
    movs	r0, #0
    b .Lde_08038A9C
.Lde_08038A9A:
    movs	r0, #1
.Lde_08038A9C:
    strb	r0, [r5, #17]
    adds	r5, #80	@ 0x50
    ldr	r1, [sp, #136]	@ 0x88
    adds	r1, #80	@ 0x50
    str	r1, [sp, #136]	@ 0x88
    adds	r6, #80	@ 0x50
    ldr	r2, [sp, #116]	@ 0x74
    adds	r2, #1
    str	r2, [sp, #116]	@ 0x74
    ldr	r1, [sp, #104]	@ 0x68
    ldr	r0, [r1, #0]
    cmp	r2, r0
    bcc .Lde_080389D2
.Lde_08038AB6:
    ldr	r2, [sp, #92]	@ 0x5c
    ldr	r0, [r2, #8]
    cmp	r0, #0
    beq .Lde_08038B44
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #68]	@ 0x44
    str	r1, [sp, #72]	@ 0x48
    movs	r0, #150	@ 0x96
    lsls	r0, r0, #1
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, r0, r1
    mov	r9, r1
    movs	r0, #100	@ 0x64
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #68	@ 0x44
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08038B18
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Lde_08038B14
    bl _call_via_r4
    b .Lde_08038B1A
.Lde_08038B14:
    .4byte func_030004DC
.Lde_08038B18:
    movs	r0, #0
.Lde_08038B1A:
    cmp	r0, #0
    beq .Lde_08038B44
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_08038B44
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_08038B44:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #12]
    cmp	r0, #0
    beq .Lde_08038BDC
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #76]	@ 0x4c
    str	r1, [sp, #80]	@ 0x50
    adds	r0, r5, #0
    adds	r0, #81	@ 0x51
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #3
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, #240	@ 0xf0
    subs	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r5, #76]	@ 0x4c
    asrs	r0, r0, #16
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #76	@ 0x4c
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08038BB0
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Lde_08038BAC
    bl _call_via_r4
    b .Lde_08038BB2
    .align 2, 0
.Lde_08038BAC:
    .4byte func_030004DC
.Lde_08038BB0:
    movs	r0, #0
.Lde_08038BB2:
    cmp	r0, #0
    beq .Lde_08038BDC
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_08038BDC
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #0
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_08038BDC:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #16]
    cmp	r0, #0
    bne .Lde_08038BE6
    b .Lde_08038CF4
.Lde_08038BE6:
    str	r0, [sp, #120]	@ 0x78
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #84]	@ 0x54
    str	r1, [sp, #88]	@ 0x58
    movs	r2, #0
    str	r2, [sp, #124]	@ 0x7c
    ldr	r0, [sp, #120]	@ 0x78
    adds	r0, #20
    str	r0, [sp, #128]	@ 0x80
    ldr r1, .Lde_08038C7C
    str	r1, [sp, #132]	@ 0x84
    ldr	r5, [sp, #120]	@ 0x78
    adds	r5, #4
.Lde_08038C02:
    ldr	r2, [sp, #120]	@ 0x78
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r0, r2, r1
    ldr	r2, [sp, #124]	@ 0x7c
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lde_08038CDC
    ldr	r1, [sp, #132]	@ 0x84
    ldrh	r0, [r1, #0]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    ldrh	r0, [r1, #2]
    ldr	r1, [sp, #100]	@ 0x64
    subs	r4, r0, r1
    adds	r6, r5, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #8
    mov	sl, r2
    add	r0, sp, #84	@ 0x54
    mov	r8, r0
    ldr	r1, [r5, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r5, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r8
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #0]
    ldr	r1, [r5, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08038C84
    ldrh	r0, [r5, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #128]	@ 0x80
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Lde_08038C80
    bl _call_via_r4
    b .Lde_08038C86
    .align 2, 0
.Lde_08038C7C:
    .4byte gUnk_080F165E
.Lde_08038C80:
    .4byte func_030004DC
.Lde_08038C84:
    movs	r0, #0
.Lde_08038C86:
    cmp	r0, #0
    beq .Lde_08038CDC
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lde_08038CDC
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08038CBC
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_08038CD6
.Lde_08038CBC:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_08038CD6
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_08038CD6:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lde_08038CDC:
    ldr	r2, [sp, #128]	@ 0x80
    adds	r2, #64	@ 0x40
    str	r2, [sp, #128]	@ 0x80
    ldr	r0, [sp, #132]	@ 0x84
    adds	r0, #4
    str	r0, [sp, #132]	@ 0x84
    adds	r5, #64	@ 0x40
    ldr	r1, [sp, #124]	@ 0x7c
    adds	r1, #1
    str	r1, [sp, #124]	@ 0x7c
    cmp	r1, #4
    bls .Lde_08038C02
.Lde_08038CF4:
    add	sp, #140	@ 0x8c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038DF0
    .thumb_func
func_08038DF0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #8
    mov	r8, r0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r7, r0, #0
    mov	r1, r8
    ldr	r0, [r1, #0]
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r7, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Lde_08038DA0
    str	r0, [r7, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #72	@ 0x48
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    movs	r0, #144	@ 0x90
    lsls	r0, r0, #17
    str	r0, [r7, #76]	@ 0x4c
    adds	r0, r7, #0
    adds	r0, #80	@ 0x50
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r2, [r0, #0]
    mov	r5, r8
    adds	r5, #12
    adds	r6, r7, #0
    mov	r0, r8
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Lde_08038D92
    cmp	r4, #0
    beq .Lde_08038D92
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Lde_08038D92:
    str	r6, [r5, #0]
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lde_08038DA0:
    .4byte vtable_unk_080E602C
    .global func_08038E90
    .thumb_func
func_08038E90:
    ldr	r0, [r0, #12]
    movs	r1, #144	@ 0x90
    lsls	r1, r1, #17
    str	r1, [r0, #76]	@ 0x4c
    adds	r0, #80	@ 0x50
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .global func_08038EA0
    .thumb_func
func_08038EA0:
    push	{lr}
    ldr	r0, [r0, #12]
    movs	r1, #0
    adds	r0, #80	@ 0x50
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lde_08038DC4
    movs	r1, #1
.Lde_08038DC4:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08038EB8
    .thumb_func
func_08038EB8:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    adds	r5, #12
    movs	r6, #0
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Lde_08038DEC
    cmp	r4, #0
    beq .Lde_08038DEC
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Lde_08038DEC:
    str	r6, [r5, #0]
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08038EE0
    .thumb_func
func_08038EE0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #76	@ 0x4c
    mov	r9, r0
    movs	r0, #166	@ 0xa6
    lsls	r0, r0, #1
    bl __builtin_new
    mov	r2, r9
    ldr	r1, [r2, #0]
    adds	r5, r0, #0
    ldr	r6, [r1, #0]
    movs	r0, #0
    str	r0, [r5, #0]
    mov	sl, r0
    add	r3, sp, #8
    mov	r8, r3
    mov	r7, sl
    lsls	r0, r7, #2
    ldr r1, .Lde_08038E28
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_08038E28:
    .4byte .Lde_08038E2C
.Lde_08038E2C:
    .4byte .Lde_08038E40
    .4byte .Lde_08038E60
    .4byte .Lde_08038E60
    .4byte .Lde_08038EF0
    .4byte .Lde_08038EF0
.Lde_08038E40:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FD15
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0xE00E2202
.Lde_08038E60:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FD05
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332201
    .4byte 0xFD6EF06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC84F0A3
    .4byte 0x62604813
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFC16F06B
    .4byte 0x0000E046
    .4byte vtable_unk_080E681C
.Lde_08038EF0:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FCBD
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332200
    .4byte 0xFD26F06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC3CF0A3
    .4byte 0x6260482C
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFBCEF06B
    .4byte 0x004921A2
    .4byte 0x44501868
    .4byte 0x70012100
    .4byte 0x44922201
    .4byte 0x2B044653
    .4byte 0xE745D800
    .4byte 0x444F2710
    .4byte 0x1C2F46B8
    .4byte 0x69064648
    .4byte 0xD01442B7
    .4byte 0xD0122E00
    .4byte 0x01806830
    .4byte 0x18353004
    .4byte 0x42AC1D34
    .4byte 0x6A60D008
    .4byte 0x1C206882
    .4byte 0xF09A2102
    .4byte 0x3440FC5D
    .4byte 0xD1F642AC
    .4byte 0xF7C71C30
    .4byte 0x4641FB29
    .4byte 0xB013600F
    .4byte 0x4698BC38
    .4byte 0x46AA46A1
    .4byte 0xBC01BCF0
    .4byte 0x00004700
    .4byte vtable_unk_080E681C
    .global func_080390D0
    .thumb_func
func_080390D0:
    ldr	r1, [r0, #16]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    subs	r3, r1, #7
    strh	r3, [r0, #0]
    subs	r3, r2, #4
    strh	r3, [r0, #2]
    adds	r1, #7
    strh	r1, [r0, #4]
    adds	r2, #5
    strh	r2, [r0, #6]
    bx	lr
    .align 2, 0
    push	{lr}
    ldr	r0, [r0, #24]
    bl func_0800FFD0
    movs	r1, #0
    cmp	r0, #30
    bne .Lde_08039040
    movs	r1, #1
.Lde_08039040:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039134
    .thumb_func
func_08039134:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r6, r0, #0
    str	r1, [sp, #0]
    mov	sl, r2
    mov	r9, r3
    movs	r7, #100	@ 0x64
    movs	r0, #0
    mov	r8, r0
    movs	r5, #46	@ 0x2e
.Lde_08039064:
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r6, #0
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_080390BA
    ldrh	r0, [r4, #4]
    ldr	r1, [sp, #0]
    cmp	r0, r1
    bne .Lde_080390BA
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_080390BA
    movs	r2, #10
    ldrsh	r1, [r4, r2]
    mov	r0, sl
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    mov	r2, r9
    subs	r0, r0, r2
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r0, r1, r0
    adds	r1, r0, #0
    cmp	r7, #100	@ 0x64
    beq .Lde_080390B6
    cmp	r8, r0
    ble .Lde_080390BA
.Lde_080390B6:
    adds	r7, r5, #0
    mov	r8, r1
.Lde_080390BA:
    adds	r5, #1
    cmp	r5, #69	@ 0x45
    ble .Lde_08039064
    adds	r0, r7, #0
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391C0
    .thumb_func
func_080391C0:
    push	{lr}
    adds	r2, r0, #0
    cmp	r1, #56	@ 0x38
    bgt .Lde_080390E8
    ldr r0, .Lde_08039100
    cmp	r2, r0
    ble .Lde_080390E8
    adds	r0, #33	@ 0x21
    cmp	r2, r0
    ble .Lde_080390FA
.Lde_080390E8:
    ldr r0, .Lde_08039104
    cmp	r1, r0
    ble .Lde_08039108
    cmp	r2, #247	@ 0xf7
    ble .Lde_08039108
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #1
    cmp	r2, r0
    bgt .Lde_08039108
.Lde_080390FA:
    movs	r0, #1
    b .Lde_0803910A
    .align 2, 0
.Lde_08039100:
    .4byte 0x00000143
.Lde_08039104:
    .4byte 0x0000027F
.Lde_08039108:
    movs	r0, #0
.Lde_0803910A:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391FC
    .thumb_func
func_080391FC:
    bx	lr
    .align 2, 0
    .global func_08039200
    .thumb_func
func_08039200:
    movs	r0, #0
    bx	lr
    .global func_08039204
    .thumb_func
func_08039204:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r5, r1, #0
    str	r2, [sp, #16]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r1, r8
    adds	r1, #16
    str	r1, [sp, #20]
    mov	r2, r8
    ldrh	r4, [r2, #16]
    cmp	r4, #0
    beq .Lde_0803913C
    subs	r4, #1
.Lde_0803913C:
    ldrh	r3, [r5, #4]
    mov	ip, r3
    movs	r1, #10
    ldrsh	r0, [r5, r1]
    mov	r9, r0
    movs	r2, #14
    ldrsh	r7, [r5, r2]
    movs	r0, #176	@ 0xb0
    lsls	r0, r0, #1
    cmp	r7, r0
    ble .Lde_0803915E
    add	r3, sp, #8
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Lde_08039168
.Lde_0803915E:
    add	r3, sp, #8
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Lde_08039168:
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    add	r1, sp, #8
    adds	r0, r1, #0
    movs	r2, #0
    ldrsh	r3, [r0, r2]
    mov	sl, r3
    movs	r3, #2
    ldrsh	r6, [r1, r3]
    mov	r0, ip
    cmp	r0, #2
    bne .Lde_080391FE
    mov	r1, sl
    mov	r2, r9
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Lde_0803918E
    negs	r0, r0
.Lde_0803918E:
    cmp	r0, #15
    bgt .Lde_0803919E
    subs	r0, r6, r7
    cmp	r0, #0
    bge .Lde_0803919A
    negs	r0, r0
.Lde_0803919A:
    cmp	r0, #15
    ble .Lde_080391FE
.Lde_0803919E:
    cmp	r4, #0
    bne .Lde_080391F8
    mov	r0, r9
    adds	r1, r7, #0
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_080391CA
    movs	r1, #0
    cmp	r7, r6
    blt .Lde_080391B8
    movs	r1, #1
.Lde_080391B8:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Lde_080391F0
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Lde_080391F0
.Lde_080391CA:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r3, [sp, #16]
    str	r3, [sp, #0]
    str	r0, [sp, #4]
    mov	r0, r9
    adds	r1, r7, #0
    mov	r2, sl
    adds	r3, r6, #0
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_080391F0
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_080391F0:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Lde_080391F8:
    ldr	r0, [sp, #20]
    strh	r4, [r0, #0]
    b .Lde_08039210
.Lde_080391FE:
    adds	r0, r5, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
    add	r1, sp, #12
    mov	r0, r8
    bl func_0809C098
.Lde_08039210:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803930C
    .thumb_func
func_0803930C:
    movs	r0, #1
    bx	lr
    .global func_08039310
    .thumb_func
func_08039310:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    adds	r5, r1, #0
    str	r2, [sp, #28]
    ldr	r0, [r5, #52]	@ 0x34
    str	r0, [sp, #32]
    adds	r0, #16
    mov	r8, r0
    ldr	r3, [r5, #0]
    ldrb	r1, [r0, #6]
    str	r1, [sp, #36]	@ 0x24
    ldr	r2, [sp, #32]
    ldrh	r6, [r2, #16]
    cmp	r6, #0
    beq .Lde_08039258
    subs	r6, #1
    cmp	r6, #0
    bne .Lde_08039258
    cmp	r1, #0
    beq .Lde_08039258
    subs	r1, #1
    str	r1, [sp, #36]	@ 0x24
.Lde_08039258:
    ldr	r0, [r3, #0]
    mov	r2, r8
    ldrb	r1, [r2, #7]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    bne .Lde_0803926E
    b .Lde_0803939C
.Lde_0803926E:
    ldrh	r0, [r4, #4]
    ldrh	r3, [r5, #4]
    cmp	r0, r3
    beq .Lde_08039278
    b .Lde_0803939C
.Lde_08039278:
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803928A
    b .Lde_0803939C
.Lde_0803928A:
    movs	r0, #10
    ldrsh	r2, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    movs	r0, #10
    ldrsh	r3, [r4, r0]
    mov	sl, r3
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r9, r1
    ldr	r0, [sp, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_08039358
    mov	r1, sl
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Lde_080392AE
    negs	r0, r0
.Lde_080392AE:
    cmp	r0, #15
    bgt .Lde_080392C0
    mov	r3, r9
    subs	r0, r3, r7
    cmp	r0, #0
    bge .Lde_080392BC
    negs	r0, r0
.Lde_080392BC:
    cmp	r0, #15
    ble .Lde_08039358
.Lde_080392C0:
    cmp	r6, #0
    beq .Lde_080392E8
    mov	r1, r8
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lde_080392D2
    negs	r0, r0
.Lde_080392D2:
    cmp	r0, #15
    bgt .Lde_0803934C
    mov	r1, r8
    movs	r3, #4
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r7
    cmp	r0, #0
    bge .Lde_080392E4
    negs	r0, r0
.Lde_080392E4:
    cmp	r0, #15
    bgt .Lde_0803934C
.Lde_080392E8:
    adds	r0, r2, #0
    adds	r1, r7, #0
    str	r2, [sp, #40]	@ 0x28
    bl func_080391C0
    lsls	r0, r0, #24
    ldr	r2, [sp, #40]	@ 0x28
    cmp	r0, #0
    beq .Lde_08039314
    movs	r1, #0
    cmp	r7, r9
    blt .Lde_08039302
    movs	r1, #1
.Lde_08039302:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Lde_0803933A
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Lde_0803933A
.Lde_08039314:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r6, [sp, #28]
    str	r6, [sp, #0]
    str	r0, [sp, #4]
    adds	r0, r2, #0
    adds	r1, r7, #0
    mov	r2, sl
    mov	r3, r9
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lde_0803933A
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_0803933A:
    movs	r0, #30
    bl func_080AB788
    adds	r6, r0, #1
    mov	r1, sl
    mov	r0, r8
    strh	r1, [r0, #2]
    mov	r2, r9
    strh	r2, [r0, #4]
.Lde_0803934C:
    add	r3, sp, #36	@ 0x24
    ldrb	r0, [r3, #0]
    mov	r3, r8
    strb	r0, [r3, #6]
    strh	r6, [r3, #0]
    b .Lde_0803945C
.Lde_08039358:
    ldr r1, .Lde_08039390
    ldr	r0, [sp, #8]
    ands	r0, r1
    movs	r1, #36	@ 0x24
    orrs	r0, r1
    ldr r1, .Lde_08039394
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #9
    orrs	r0, r1
    str	r0, [sp, #8]
    mov	r6, r8
    ldrb	r1, [r6, #7]
    lsls	r1, r1, #24
    ldr r2, .Lde_08039398
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #8]
    ldr	r0, [sp, #32]
    add	r1, sp, #8
    bl func_0809C0BC
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
    b .Lde_0803945C
    .align 2, 0
.Lde_08039390:
    .4byte 0xFFFF0000
.Lde_08039394:
    .4byte 0xFF00FFFF
.Lde_08039398:
    .4byte 0x00FFFFFF
.Lde_0803939C:
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lde_080393BE
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Lde_080393C6
.Lde_080393BE:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lde_080393C6:
    cmp	r6, #100	@ 0x64
    beq .Lde_08039448
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lde_08039410
    ldr r1, .Lde_08039404
    ldr	r0, [sp, #12]
    ands	r0, r1
    str	r0, [sp, #12]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Lde_08039408
    add	r1, sp, #12
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    lsls	r3, r6, #24
    ldr r0, .Lde_0803940C
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    adds	r0, r4, #0
    bl func_0809C0AC
    b .Lde_0803945C
.Lde_08039404:
    .4byte 0xFFFF0000
.Lde_08039408:
    .4byte 0xFF00FFFF
.Lde_0803940C:
    .4byte 0x00FFFFFF
.Lde_08039410:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_0803943C
    ldr	r1, [sp, #20]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_08039440
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lde_08039444
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lde_0803945C
.Lde_0803943C:
    .4byte 0xFFFF0000
.Lde_08039440:
    .4byte 0xFF00FFFF
.Lde_08039444:
    .4byte 0x00FFFFFF
.Lde_08039448:
    ldr r1, .Lde_0803946C
    ldr	r0, [sp, #24]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #24]
    add	r1, sp, #24
    adds	r0, r4, #0
    bl func_0809C0A0
.Lde_0803945C:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lde_0803946C:
    .4byte 0xFFFF0000
    .global func_0803955C
    .thumb_func
func_0803955C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #16
    adds	r5, r1, #0
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r6, r8
    adds	r6, #16
    mov	r1, r8
    ldrh	r4, [r1, #16]
    cmp	r4, #0
    beq .Lde_08039496
    subs	r4, #1
    cmp	r4, #0
    beq .Lde_08039496
    b .Lde_080395F6
.Lde_08039496:
    ldrb	r0, [r6, #2]
    cmp	r0, #0
    bne .Lde_0803949E
    b .Lde_080395E8
.Lde_0803949E:
    ldr	r4, [r5, #0]
    ldrh	r7, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    mov	r9, r2
    movs	r1, #14
    ldrsh	r0, [r5, r1]
    mov	sl, r0
    adds	r0, r4, #0
    adds	r1, r7, #0
    mov	r3, sl
    bl func_08039134
    adds	r1, r0, #0
    cmp	r1, #100	@ 0x64
    bne .Lde_080394C0
    ldrb	r1, [r6, #3]
.Lde_080394C0:
    ldr	r0, [r4, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r4, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_08039516
    ldrh	r0, [r4, #4]
    cmp	r0, r7
    bne .Lde_08039516
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08039516
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r6, r9
    subs	r0, r0, r6
    cmp	r0, #0
    bge .Lde_080394F8
    negs	r0, r0
.Lde_080394F8:
    cmp	r0, #15
    bgt .Lde_08039516
    mov	r0, sl
    subs	r3, r1, r0
    cmp	r3, #0
    bge .Lde_08039506
    negs	r3, r3
.Lde_08039506:
    cmp	r3, #15
    bgt .Lde_08039516
    ldr	r0, [r4, #20]
    adds	r0, #128	@ 0x80
    ldr	r1, [r0, #0]
    adds	r0, r4, #0
    bl _call_via_r1
.Lde_08039516:
    mov	r0, r8
    movs	r1, #4
    bl func_0809C068
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lde_08039540
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Lde_08039548
.Lde_08039540:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lde_08039548:
    cmp	r6, #100	@ 0x64
    beq .Lde_080395CC
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lde_08039594
    ldr r1, .Lde_08039588
    ldr	r0, [sp, #0]
    ands	r0, r1
    str	r0, [sp, #0]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Lde_0803958C
    ldr	r1, [sp, #4]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lde_08039590
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #4]
    adds	r0, r4, #0
    mov	r1, sp
    bl func_0809C0AC
    b .Lde_080395F8
    .align 2, 0
.Lde_08039588:
    .4byte 0xFFFF0000
.Lde_0803958C:
    .4byte 0xFF00FFFF
.Lde_08039590:
    .4byte 0x00FFFFFF
.Lde_08039594:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_080395C0
    ldr	r1, [sp, #8]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_080395C4
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lde_080395C8
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #8]
    add	r1, sp, #8
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lde_080395F8
.Lde_080395C0:
    .4byte 0xFFFF0000
.Lde_080395C4:
    .4byte 0xFF00FFFF
.Lde_080395C8:
    .4byte 0x00FFFFFF
.Lde_080395CC:
    ldr r1, .Lde_080395E4
    ldr	r0, [sp, #12]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #12]
    add	r1, sp, #12
    adds	r0, r4, #0
    bl func_0809C0A0
    b .Lde_080395F8
    .align 2, 0
.Lde_080395E4:
    .4byte 0xFFFF0000
.Lde_080395E8:
    movs	r4, #36	@ 0x24
    movs	r0, #1
    strb	r0, [r6, #2]
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Lde_080395F6:
    strh	r4, [r6, #0]
.Lde_080395F8:
    add	sp, #16
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_080396F4
    .thumb_func
func_080396F4:
    push	{lr}
    ldr	r0, [r1, #52]	@ 0x34
    ldrb	r0, [r0, #18]
    movs	r1, #0
    cmp	r0, #0
    beq .Lde_08039616
    movs	r1, #3
.Lde_08039616:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .global func_08039708
    .thumb_func
func_08039708:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r6, r1, #0
    mov	sl, r2
    ldr	r0, [r6, #52]	@ 0x34
    movs	r1, #16
    adds	r1, r1, r0
    mov	r9, r1
    ldr	r3, [r6, #0]
    ldrh	r2, [r0, #16]
    mov	r8, r2
    cmp	r2, #0
    beq .Lde_08039644
    movs	r4, #1
    negs	r4, r4
    add	r8, r4
.Lde_08039644:
    ldr	r1, [r0, #16]
    lsls	r0, r1, #9
    lsrs	r7, r0, #25
    cmp	r7, #0
    beq .Lde_08039650
    subs	r7, #1
.Lde_08039650:
    mov	r5, r9
    ldrb	r4, [r5, #3]
    cmp	r4, #0
    beq .Lde_0803965A
    subs	r4, #1
.Lde_0803965A:
    mov	r0, r8
    cmp	r0, #0
    beq .Lde_080396DA
    ldr	r2, [r3, #0]
    lsls	r0, r1, #8
    movs	r1, #0
    cmp	r0, #0
    bge .Lde_0803966C
    movs	r1, #43	@ 0x2b
.Lde_0803966C:
    ldr	r2, [r2, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lde_080396DA
    ldrh	r0, [r3, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Lde_080396DA
    cmp	r4, #0
    bne .Lde_080396C0
    movs	r2, #10
    ldrsh	r0, [r6, r2]
    movs	r4, #14
    ldrsh	r1, [r6, r4]
    movs	r5, #10
    ldrsh	r2, [r3, r5]
    movs	r4, #14
    ldrsh	r3, [r3, r4]
    adds	r5, r6, #0
    adds	r5, #32
    ldrb	r4, [r5, #0]
    mov	ip, r4
    mov	r4, sl
    str	r4, [sp, #0]
    mov	r4, ip
    str	r4, [sp, #4]
    bl func_080ABE58
    adds	r1, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r0, r1
    beq .Lde_080396B8
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_080396B8:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Lde_080396C0:
    mov	r0, r8
    mov	r5, r9
    strh	r0, [r5, #0]
    movs	r0, #127	@ 0x7f
    ands	r7, r0
    ldrb	r1, [r5, #2]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r7
    strb	r0, [r5, #2]
    strb	r4, [r5, #3]
    b .Lde_080397A0
.Lde_080396DA:
    adds	r0, r6, #0
    bl func_080323C8
    ldr	r4, [r6, #52]	@ 0x34
    movs	r5, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lde_08039702
    ldr	r0, [r6, #0]
    ldrh	r1, [r6, #4]
    movs	r3, #10
    ldrsh	r2, [r6, r3]
    movs	r5, #14
    ldrsh	r3, [r6, r5]
    bl func_08039134
    adds	r5, r0, #0
    b .Lde_0803970A
.Lde_08039702:
    adds	r0, r6, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lde_0803970A:
    cmp	r5, #100	@ 0x64
    beq .Lde_0803978C
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lde_08039754
    ldr r1, .Lde_08039748
    ldr	r0, [sp, #8]
    ands	r0, r1
    str	r0, [sp, #8]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Lde_0803974C
    ldr	r1, [sp, #12]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Lde_08039750
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #12]
    adds	r0, r4, #0
    add	r1, sp, #8
    bl func_0809C0AC
    b .Lde_080397A0
.Lde_08039748:
    .4byte 0xFFFF0000
.Lde_0803974C:
    .4byte 0xFF00FFFF
.Lde_08039750:
    .4byte 0x00FFFFFF
.Lde_08039754:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_08039780
    ldr	r1, [sp, #16]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_08039784
    ands	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Lde_08039788
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #16]
    add	r1, sp, #16
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lde_080397A0
.Lde_08039780:
    .4byte 0xFFFF0000
.Lde_08039784:
    .4byte 0xFF00FFFF
.Lde_08039788:
    .4byte 0x00FFFFFF
.Lde_0803978C:
    ldr r1, .Lde_080397B0
    ldr	r0, [sp, #20]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0A0
.Lde_080397A0:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lde_080397B0:
    .4byte 0xFFFF0000
    .global func_080398A0
    .thumb_func
func_080398A0:
    movs	r0, #2
    bx	lr
    .global func_080398A4
    .thumb_func
func_080398A4:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r0, sp
    adds	r1, r5, #0
    bl __5ActorRC5Actor
    ldr r3, .Lde_080398B8
    adds	r0, r6, #0
    adds	r1, r4, #0
    mov	r2, sp
    bl func_08020038
    ldr r0, .Lde_080398BC
    str	r0, [r6, #20]
    str	r5, [r6, #52]	@ 0x34
    adds	r1, r6, #0
    adds	r1, #56	@ 0x38
    movs	r0, #4
    movs	r3, #0
    movs	r2, #1
    negs	r2, r2
.Lde_080397E8:
    stmia	r1!, {r3}
    subs	r0, #1
    cmp	r0, r2
    bne .Lde_080397E8
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lde_080398C0
    str	r0, [r4, #0]
    ldr	r0, [r6, #56]	@ 0x38
    cmp	r4, r0
    beq .Lde_08039806
    bl __builtin_delete
.Lde_08039806:
    str	r4, [r6, #56]	@ 0x38
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lde_080398C4
    str	r0, [r4, #0]
    ldr	r0, [r6, #60]	@ 0x3c
    cmp	r4, r0
    beq .Lde_0803981E
    bl __builtin_delete
.Lde_0803981E:
    str	r4, [r6, #60]	@ 0x3c
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lde_080398C8
    str	r0, [r4, #0]
    ldr	r0, [r6, #64]	@ 0x40
    cmp	r4, r0
    beq .Lde_08039836
    bl __builtin_delete
.Lde_08039836:
    str	r4, [r6, #64]	@ 0x40
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lde_080398CC
    str	r0, [r4, #0]
    ldr	r0, [r6, #68]	@ 0x44
    cmp	r4, r0
    beq .Lde_0803984E
    bl __builtin_delete
.Lde_0803984E:
    str	r4, [r6, #68]	@ 0x44
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lde_080398D0
    str	r0, [r4, #0]
    ldr	r0, [r6, #72]	@ 0x48
    cmp	r4, r0
    beq .Lde_08039866
    bl __builtin_delete
.Lde_08039866:
    str	r4, [r6, #72]	@ 0x48
    ldr	r0, [r6, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r6
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08020080
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080398A4
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lde_080398A4:
    str	r4, [r6, #76]	@ 0x4c
    adds	r0, r6, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [r6, #80]	@ 0x50
    adds	r0, r6, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lde_080398B8:
    .4byte 0x000009C7
.Lde_080398BC:
    .4byte vtable_unk_080E74DC
.Lde_080398C0:
    .4byte vtable_unk_080E74CC
.Lde_080398C4:
    .4byte vtable_unk_080E74BC
.Lde_080398C8:
    .4byte vtable_unk_080E74AC
.Lde_080398CC:
    .4byte vtable_unk_080E749C
.Lde_080398D0:
    .4byte vtable_unk_080E748C
    .global func_080399C0
    .thumb_func
func_080399C0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r7, r1, #0
    ldr r0, .Lde_0803993C
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__5ActorRC13ActorLocation
    adds	r0, r5, #0
    adds	r0, #56	@ 0x38
    cmp	r0, #0
    beq .Lde_08039910
    adds	r4, r5, #0
    adds	r4, #76	@ 0x4c
    cmp	r0, r4
    beq .Lde_08039910
    adds	r6, r0, #0
.Lde_08039904:
    subs	r4, #4
    ldr	r0, [r4, #0]
    bl __builtin_delete
    cmp	r6, r4
    bne .Lde_08039904
.Lde_08039910:
    ldr r0, .Lde_08039940
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_08039926
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08039926:
    movs	r0, #1
    ands	r0, r7
    cmp	r0, #0
    beq .Lde_08039934
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_08039934:
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lde_0803993C:
    .4byte vtable_unk_080E74DC
.Lde_08039940:
    .4byte __vt_7AEntity
    .global func_08039A30
    .thumb_func
func_08039A30:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08039A5C
    .thumb_func
func_08039A5C:
    bx	lr
    .align 2, 0
    .global func_08039A60
    .thumb_func
func_08039A60:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #112	@ 0x70
    adds	r7, r0, #0
    ldr	r0, [r7, #0]
    mov	sl, r0
    ldrb	r0, [r1, #4]
    cmp	r0, #0
    bne .Lde_0803998E
    b .Lde_08039AC0
.Lde_0803998E:
    ldrh	r0, [r7, #4]
    cmp	r0, #2
    bne .Lde_08039996
    b .Lde_08039AC0
.Lde_08039996:
    mov	r1, sl
    ldr	r0, [r1, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r0, r2
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrh	r1, [r2, #10]
    ldr r0, .Lde_080399D4
    ands	r0, r1
    cmp	r0, #20
    beq .Lde_080399B6
    b .Lde_08039AC0
.Lde_080399B6:
    ldr	r0, [r2, #0]
    cmp	r0, #0
    beq .Lde_080399BE
    b .Lde_08039AC0
.Lde_080399BE:
    movs	r0, #2
    bl func_080AB788
    cmp	r0, #0
    beq .Lde_080399D8
    add	r0, sp, #68	@ 0x44
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Lde_080399E2
.Lde_080399D4:
    .4byte 0x000007FF
.Lde_080399D8:
    add	r0, sp, #68	@ 0x44
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Lde_080399E2:
    strh	r1, [r0, #0]
    strh	r2, [r0, #2]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [sp, #72]	@ 0x48
    add	r4, sp, #72	@ 0x48
    movs	r3, #0
    ldrsh	r2, [r4, r3]
    movs	r6, #2
    ldrsh	r3, [r4, r6]
    mov	r0, sl
    movs	r1, #2
    bl func_08039134
    str	r0, [sp, #108]	@ 0x6c
    cmp	r0, #100	@ 0x64
    beq .Lde_08039AC0
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #14
    bhi .Lde_08039AC0
    movs	r0, #0
    ldrsh	r6, [r4, r0]
    movs	r2, #2
    ldrsh	r1, [r4, r2]
    mov	r8, r1
    mov	r3, sp
    movs	r2, #2
    ldrh	r1, [r3, #0]
    ldr r4, .Lde_08039C2C
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #0]
    lsls	r6, r6, #16
    lsrs	r1, r6, #16
    movs	r0, #63	@ 0x3f
    mov	r9, r0
    ands	r1, r0
    lsls	r1, r1, #2
    ldrb	r5, [r3, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r5
    orrs	r0, r1
    strb	r0, [r3, #1]
    lsrs	r6, r6, #22
    ldrh	r1, [r3, #2]
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r6
    strh	r0, [r3, #2]
    mov	r1, r8
    lsls	r1, r1, #16
    mov	r8, r1
    lsrs	r0, r1, #16
    mov	r6, r9
    ands	r0, r6
    lsls	r0, r0, #2
    ldrb	r1, [r3, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r3, #3]
    mov	r0, r8
    lsrs	r0, r0, #22
    mov	r8, r0
    ldrh	r0, [r3, #4]
    ands	r4, r0
    mov	r1, r8
    orrs	r4, r1
    strh	r4, [r3, #4]
    add	r4, sp, #8
    movs	r5, #1
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    strb	r5, [r4, #6]
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__12AActorEntityRC13ActorLocation
    ldr r1, .Lde_08039C30
    ldr	r0, [sp, #76]	@ 0x4c
    ands	r0, r1
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Lde_08039C34
    add	r1, sp, #76	@ 0x4c
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    ldr	r6, [sp, #108]	@ 0x6c
    lsls	r3, r6, #24
    ldr r0, .Lde_08039C38
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    ldr	r0, [r7, #52]	@ 0x34
    bl func_0809C0AC
    adds	r0, r7, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Lde_08039AC0:
    ldrh	r5, [r7, #4]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    cmp	r5, r0
    bne .Lde_08039ACC
    b .Lde_08039C1A
.Lde_08039ACC:
    mov	r0, sl
    ldr	r1, [r0, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    mov	r1, sl
    adds	r2, r5, #0
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #84	@ 0x54
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    add	r4, sp, #16
    movs	r1, #32
    mov	r8, r1
    movs	r2, #0
    mov	r9, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #16]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #36	@ 0x24
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #84]	@ 0x54
    ldr	r1, [sp, #88]	@ 0x58
    str	r0, [sp, #48]	@ 0x30
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r8
    str	r3, [r4, #40]	@ 0x28
    mov	r6, r9
    str	r6, [r4, #44]	@ 0x2c
    str	r6, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r8, r4
    cmp	r3, #0
    beq .Lde_08039B4C
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Lde_08039B4C
    ldr	r1, [r3, #20]
    add	r4, sp, #92	@ 0x5c
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lde_08039B4C:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lde_08039B7C
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Lde_08039B7C
    ldr	r1, [r3, #20]
    add	r4, sp, #100	@ 0x64
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lde_08039B7C:
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #8]
    adds	r1, r7, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r5, [r0, #0]
    ldr	r1, [r7, #76]	@ 0x4c
    adds	r6, r0, #0
    cmp	r4, r1
    bne .Lde_08039BBC
    ldr	r0, [r7, #80]	@ 0x50
    cmp	r5, r0
    beq .Lde_08039BCC
.Lde_08039BBC:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r7, #0
    bl func_08020080
.Lde_08039BCC:
    ldr	r0, [r7, #76]	@ 0x4c
    cmp	r4, r0
    beq .Lde_08039BE8
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_08039BE8
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Lde_08039BE8:
    str	r4, [r7, #76]	@ 0x4c
    str	r5, [r7, #80]	@ 0x50
    mov	r4, r8
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    ldrb	r1, [r6, #0]
    subs	r0, #1
    cmp	r0, #1
    bhi .Lde_08039C12
    cmp	r1, #1
    bhi .Lde_08039C12
    movs	r1, #10
    ldrsh	r0, [r7, r1]
    movs	r2, #14
    ldrsh	r1, [r7, r2]
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08039C12
    movs	r4, #0
.Lde_08039C12:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08020170
.Lde_08039C1A:
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_08039C3C
    subs	r0, #1
    b .Lde_08039C3E
.Lde_08039C2C:
    .4byte 0xFFFFFC00
.Lde_08039C30:
    .4byte 0xFFFF0000
.Lde_08039C34:
    .4byte 0xFF00FFFF
.Lde_08039C38:
    .4byte 0x00FFFFFF
.Lde_08039C3C:
    ldrh	r0, [r7, #38]	@ 0x26
.Lde_08039C3E:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Lde_08039C50
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lde_08039C50:
    add	sp, #112	@ 0x70
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08039D4C
    .thumb_func
func_08039D4C:
    ldr r0, .Lde_08039C6C
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lde_08039C6C:
    .4byte gUnk_080F16AE
    .global func_08039D5C
    .thumb_func
func_08039D5C:
    push	{lr}
    cmp	r1, #4
    bhi .Lde_08039CA4
    lsls	r0, r1, #2
    ldr r1, .Lde_08039C80
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_08039C80:
    .4byte .Lde_08039C84
.Lde_08039C84:
    .4byte .Lde_08039CA4
    .4byte .Lde_08039C98
    .4byte .Lde_08039C9E
    .4byte .Lde_08039CA4
    .4byte .Lde_08039CA4
.Lde_08039C98:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE003
.Lde_08039C9E:
    .hword 0x2080
    .4byte 0xE0000240
.Lde_08039CA4:
    movs	r0, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039D98
    .thumb_func
func_08039D98:
    ldr	r0, [r0, #52]	@ 0x34
    ldr	r1, [r0, #12]
    movs	r0, #4
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .global func_08039DA8
    .thumb_func
func_08039DA8:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Lde_08039D14
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_08039D1C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_08039D20
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    ldr r0, .Lde_08039D24
    ands	r1, r0
    ldr r0, .Lde_08039D28
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #15
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lde_08039D14:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
.Lde_08039D1C:
    .4byte 0xFFFF0000
.Lde_08039D20:
    .4byte 0xFF80FFFF
.Lde_08039D24:
    .4byte 0xFF7FFFFF
.Lde_08039D28:
    .4byte 0x00FFFFFF
    .global func_08039E18
    .thumb_func
func_08039E18:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Lde_08039D86
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_08039D90
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_08039D94
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #16
    orrs	r1, r0
    ldr r0, .Lde_08039D98
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #4
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lde_08039D86:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08039D90:
    .4byte 0xFFFF0000
.Lde_08039D94:
    .4byte 0xFF80FFFF
.Lde_08039D98:
    .4byte 0x00FFFFFF
    .global func_08039E88
    .thumb_func
func_08039E88:
    movs	r0, #2
    bx	lr
    ldr	r1, [r0, #52]	@ 0x34
    ldr	r1, [r1, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r0, [r1, #56]	@ 0x38
    bx	lr
    .global func_08039E98
    .thumb_func
func_08039E98:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r6, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    ldr r0, .Lde_08039E44
    str	r0, [r7, #76]	@ 0x4c
    str	r6, [r7, #0]
    movs	r4, #0
    strh	r5, [r7, #4]
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r0, r7, #0
    adds	r0, #8
    movs	r2, #3
    str	r2, [sp, #0]
    movs	r2, #27
    str	r2, [sp, #4]
    add	r2, sp, #8
    strb	r4, [r2, #0]
    adds	r2, r5, #0
    adds	r3, r6, #0
    bl func_080A4A00
    mov	r0, r9
    cmp	r0, #1
    bne .Lde_08039E50
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r5, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r4, r0, #0
    adds	r0, r5, #0
    adds	r1, r6, #0
    movs	r2, #2
    movs	r3, #15
    bl func_080A4740
    ldr r0, .Lde_08039E48
    str	r0, [r5, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r5
    mov	r8, r1
    ldr	r6, [r4, #0]
    add	r0, sp, #12
    ldr	r3, [r6, #12]
    adds	r1, r4, #0
    ldr r2, .Lde_08039E4C
    bl _call_via_r3
    ldr	r0, [sp, #12]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r6, #16]
    adds	r1, r4, #0
    bl _call_via_r3
    adds	r0, r5, #0
    adds	r0, #72	@ 0x48
    mov	r1, r9
    strb	r1, [r0, #0]
    b .Lde_08039E52
    .align 2, 0
.Lde_08039E44:
    .4byte vtable_unk_080E76BC
.Lde_08039E48:
    .4byte vtable_unk_080E602C
.Lde_08039E4C:
    .4byte 0x0000091A
.Lde_08039E50:
    movs	r5, #0
.Lde_08039E52:
    str	r5, [r7, #72]	@ 0x48
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08039F50
    .thumb_func
func_08039F50:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldr r0, .Lde_08039EA0
    str	r0, [r4, #76]	@ 0x4c
    ldr	r1, [r4, #72]	@ 0x48
    cmp	r1, #0
    beq .Lde_08039E80
    ldr	r0, [r1, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08039E80:
    adds	r0, r4, #0
    adds	r0, #8
    movs	r1, #2
    bl func_080A47B4
    movs	r0, #1
    ands	r0, r5
    cmp	r0, #0
    beq .Lde_08039E98
    adds	r0, r4, #0
    bl __builtin_delete
.Lde_08039E98:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08039EA0:
    .4byte vtable_unk_080E76BC
    .global func_08039F90
    .thumb_func
func_08039F90:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    mov	sl, r0
    adds	r4, r1, #0
    mov	r9, r2
    mov	r8, r3
    ldr	r5, [sp, #104]	@ 0x68
    ldr	r6, [sp, #108]	@ 0x6c
    ldr	r7, [sp, #112]	@ 0x70
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #24]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r5, r5, r0
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #28]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r0, r6, r0
    str	r0, [sp, #64]	@ 0x40
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r6
    str	r0, [sp, #68]	@ 0x44
    add	r0, sp, #52	@ 0x34
    mov	r1, r8
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r9
    str	r3, [r0, #4]
    adds	r5, r7, #0
    mov	r9, r0
    cmp	r5, #0
    bge .Lde_08039EF6
    negs	r7, r5
.Lde_08039EF6:
    ldr	r4, [sp, #64]	@ 0x40
    subs	r4, r4, r7
    mov	r8, r4
    mov	r6, sl
    adds	r6, #8
    movs	r0, #3
    ldr	r7, [sp, #116]	@ 0x74
    ands	r0, r7
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    mov	r0, sl
    ldr	r1, [r0, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r0, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r9
    ldr	r1, [r1, #4]
    mov	ip, r1
    mov	r3, sl
    ldr	r2, [r3, #8]
    ldr	r1, [r3, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08039F68
    ldrh	r0, [r6, #12]
    mov	r1, sl
    adds	r1, #24
    ldr	r3, [sp, #68]	@ 0x44
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    ldr	r1, [sp, #60]	@ 0x3c
    mov	r2, r8
    adds	r3, r4, #0
    ldr r4, .Lde_08039F64
    bl _call_via_r4
    b .Lde_08039F6A
.Lde_08039F64:
    .4byte func_030004DC
.Lde_08039F68:
    movs	r0, #0
.Lde_08039F6A:
    cmp	r0, #0
    beq .Lde_08039FBE
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r8, r0
    cmp	r1, #0
    beq .Lde_08039FBE
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08039F9E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_08039FB8
.Lde_08039F9E:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_08039FB8
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_08039FB8:
    movs	r0, #0
    mov	r4, r8
    strb	r0, [r4, #0]
.Lde_08039FBE:
    mov	r7, sl
    ldr	r0, [r7, #72]	@ 0x48
    cmp	r0, #0
    beq .Lde_0803A048
    cmp	r5, #0
    blt .Lde_0803A048
    adds	r6, r0, #0
    mov	r5, r9
    movs	r0, #3
    ldr	r1, [sp, #116]	@ 0x74
    ands	r0, r1
    lsls	r3, r0, #2
    orrs	r3, r0
    lsls	r1, r0, #4
    orrs	r3, r1
    lsls	r0, r0, #6
    orrs	r3, r0
    adds	r7, r6, #0
    adds	r7, #40	@ 0x28
    ldr	r4, [r5, #4]
    mov	r8, r4
    adds	r0, r6, #0
    ldmia	r0!, {r2}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_0803A01C
    ldrh	r0, [r6, #12]
    adds	r1, r6, #0
    adds	r1, #16
    ldr	r4, [sp, #68]	@ 0x44
    str	r4, [sp, #0]
    str	r7, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r8
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #64]	@ 0x40
    ldr r4, .Lde_0803A018
    bl _call_via_r4
    b .Lde_0803A01E
    .align 2, 0
.Lde_0803A018:
    .4byte func_030004DC
.Lde_0803A01C:
    movs	r0, #0
.Lde_0803A01E:
    cmp	r0, #0
    beq .Lde_0803A048
    adds	r4, r6, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_0803A048
    ldr	r1, [r5, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_0803A048:
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803A144
    .thumb_func
func_0803A144:
    push	{r4, lr}
    adds	r4, r1, #0
    lsls	r2, r2, #24
    lsrs	r0, r2, #24
    cmp	r2, #0
    bge .Lde_0803A06E
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
.Lde_0803A06E:
    ldr r2, .Lde_0803A090
    lsls	r0, r0, #24
    asrs	r0, r0, #24
    lsls	r1, r0, #2
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #4]
    lsls	r1, r0, #1
    adds	r1, #1
    lsls	r1, r1, #1
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #6]
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803A090:
    .4byte gUnk_080F16C2
    .global func_0803A180
    .thumb_func
func_0803A180:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #72	@ 0x48
    mov	r8, r0
    adds	r4, r1, #0
    adds	r5, r2, #0
    movs	r0, #0
    mov	r9, r0
    mov	r2, r8
    ldr	r1, [r2, #0]
    ldr	r2, [r1, #0]
    mov	r0, sp
    ldr	r3, [r2, #52]	@ 0x34
    movs	r2, #0
    bl _call_via_r3
    movs	r6, #4
    ldrsh	r1, [r4, r6]
    movs	r7, #6
    ldrsh	r3, [r4, r7]
    add	r2, sp, #64	@ 0x40
    adds	r0, r1, #0
    subs	r0, #8
    strh	r0, [r2, #0]
    adds	r0, r3, #0
    subs	r0, #8
    strh	r0, [r2, #2]
    adds	r1, #8
    strh	r1, [r2, #4]
    adds	r3, #8
    strh	r3, [r2, #6]
    add	r3, sp, #12
    movs	r0, #32
    mov	ip, r0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    subs	r0, #65	@ 0x41
    str	r0, [r3, #4]
    str	r0, [r3, #8]
    str	r1, [r3, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r6, r7}
    stmia	r1!, {r2, r6, r7}
    ldr	r0, [sp, #64]	@ 0x40
    ldr	r1, [sp, #68]	@ 0x44
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r0, ip
    str	r0, [r3, #40]	@ 0x28
    mov	r1, r9
    str	r1, [r3, #44]	@ 0x2c
    str	r1, [r3, #48]	@ 0x30
    movs	r0, #18
    ldrsb	r0, [r4, r0]
    cmp	r0, #0
    beq .Lde_0803A1BA
    cmp	r0, #1
    bne .Lde_0803A1BA
    ldr	r0, [r4, #0]
    cmp	r0, #1
    beq .Lde_0803A148
    cmp	r0, #1
    bgt .Lde_0803A11E
    cmp	r0, #0
    beq .Lde_0803A128
    b .Lde_0803A1B6
.Lde_0803A11E:
    cmp	r0, #2
    beq .Lde_0803A168
    cmp	r0, #3
    beq .Lde_0803A188
    b .Lde_0803A1B6
.Lde_0803A128:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lde_0803A13A
    adds	r0, r3, #0
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Lde_0803A13C
.Lde_0803A13A:
    adds	r0, r1, #0
.Lde_0803A13C:
    cmp	r0, #1
    ble .Lde_0803A1B6
    ldr	r0, [r4, #12]
    adds	r0, r0, r5
    str	r0, [r4, #12]
    b .Lde_0803A1BA
.Lde_0803A148:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lde_0803A158
    adds	r0, r3, #0
    bl func_080AB8D0
    ldr	r1, [sp, #16]
.Lde_0803A158:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Lde_0803A1B6
    ldr	r0, [r4, #12]
    subs	r0, r0, r5
    str	r0, [r4, #12]
    b .Lde_0803A1BA
.Lde_0803A168:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lde_0803A178
    adds	r0, r3, #0
    bl func_080AB948
    ldr	r1, [sp, #20]
.Lde_0803A178:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Lde_0803A1B6
    ldr	r0, [r4, #8]
    subs	r0, r0, r5
    str	r0, [r4, #8]
    b .Lde_0803A1BA
.Lde_0803A188:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lde_0803A19A
    adds	r0, r3, #0
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Lde_0803A19C
.Lde_0803A19A:
    adds	r0, r1, #0
.Lde_0803A19C:
    cmp	r0, #1
    ble .Lde_0803A1B6
    ldr	r0, [r4, #8]
    adds	r0, r0, r5
    str	r0, [r4, #8]
    asrs	r0, r0, #16
    movs	r1, #145	@ 0x91
    lsls	r1, r1, #2
    cmp	r0, r1
    ble .Lde_0803A1BA
    movs	r0, #145	@ 0x91
    lsls	r0, r0, #18
    str	r0, [r4, #8]
.Lde_0803A1B6:
    movs	r0, #0
    strh	r0, [r4, #16]
.Lde_0803A1BA:
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    strh	r0, [r4, #4]
    movs	r6, #14
    ldrsh	r0, [r4, r6]
    strh	r0, [r4, #6]
    mov	r1, r8
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_0803A1E6
    mov	r0, r8
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_0803A1EA
    mov	r1, r8
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lde_0803A1E8
.Lde_0803A1E6:
    movs	r0, #0
.Lde_0803A1E8:
    strb	r0, [r1, #0]
.Lde_0803A1EA:
    ldrh	r0, [r4, #16]
    subs	r0, #1
    strh	r0, [r4, #16]
    lsls	r0, r0, #16
    cmp	r0, #0
    bge .Lde_0803A224
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #16
    asrs	r1, r0, #16
    cmp	r1, #3
    bne .Lde_0803A20A
    movs	r0, #0
    strb	r0, [r4, #18]
    b .Lde_0803A216
.Lde_0803A20A:
    movs	r0, #1
    strb	r0, [r4, #18]
    ldr	r0, [r4, #0]
    bl func_080AB7A4
    str	r0, [r4, #0]
.Lde_0803A216:
    movs	r0, #31
    bl func_080AB788
    adds	r0, #16
    strh	r0, [r4, #16]
    movs	r7, #1
    mov	r9, r7
.Lde_0803A224:
    mov	r0, r9
    add	sp, #72	@ 0x48
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803A320
    .thumb_func
func_0803A320:
    ldr r0, .Lde_0803A244
    lsls	r1, r1, #16
    asrs	r1, r1, #15
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Lde_0803A244:
    .4byte gUnk_080F16D2
    .global func_0803A334
    .thumb_func
func_0803A334:
    ldr r2, .Lde_0803A260
    lsls	r1, r1, #16
    asrs	r1, r1, #16
    adds	r1, #64	@ 0x40
    movs	r0, #255	@ 0xff
    ands	r1, r0
    lsls	r1, r1, #1
    adds	r1, r1, r2
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Lde_0803A260:
    .4byte gUnk_080F16D2
    .global func_0803A350
    .thumb_func
func_0803A350:
    push	{r4, r5, r6, lr}
    adds	r6, r1, #0
    ldr	r0, [r0, #0]
    ldr	r1, [r0, #0]
    movs	r2, #166	@ 0xa6
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldr	r4, [r0, #0]
    ldr	r5, [r0, #4]
    cmp	r4, r5
    beq .Lde_0803A296
.Lde_0803A280:
    ldr	r0, [r4, #0]
    bl func_08008CD0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803A290
    ldr	r0, [r4, #0]
    b .Lde_0803A29A
.Lde_0803A290:
    adds	r4, #4
    cmp	r4, r5
    bne .Lde_0803A280
.Lde_0803A296:
    subs	r0, r5, #4
    ldr	r0, [r0, #0]
.Lde_0803A29A:
    lsls	r1, r6, #16
    lsrs	r1, r1, #16
    bl func_08008B6C
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_0803A394
    .thumb_func
func_0803A394:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    adds	r5, r2, #0
    lsls	r3, r3, #24
    lsrs	r3, r3, #24
    mov	r9, r3
    ldr r7, .Lde_0803A2F8
    cmp	r3, #0
    bne .Lde_0803A2C8
    ldr r7, .Lde_0803A2FC
.Lde_0803A2C8:
    movs	r0, #4
    mov	sl, r0
    mov	r1, r9
    cmp	r1, #0
    bne .Lde_0803A2D6
    movs	r2, #10
    mov	sl, r2
.Lde_0803A2D6:
    movs	r0, #99	@ 0x63
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    movs	r3, #0
    str	r3, [sp, #0]
    movs	r0, #0
    str	r0, [sp, #4]
    mov	ip, r0
    cmp	r5, #1
    beq .Lde_0803A310
    cmp	r5, #1
    bgt .Lde_0803A300
    cmp	r5, #0
    beq .Lde_0803A30A
    b .Lde_0803A320
.Lde_0803A2F8:
    .4byte gUnk_080F1904
.Lde_0803A2FC:
    .4byte gUnk_080F18D2
.Lde_0803A300:
    cmp	r5, #2
    beq .Lde_0803A316
    cmp	r5, #3
    beq .Lde_0803A31C
    b .Lde_0803A320
.Lde_0803A30A:
    movs	r1, #0
    mov	ip, r1
    b .Lde_0803A320
.Lde_0803A310:
    movs	r2, #1
    mov	ip, r2
    b .Lde_0803A320
.Lde_0803A316:
    movs	r3, #2
    mov	ip, r3
    b .Lde_0803A320
.Lde_0803A31C:
    movs	r5, #3
    mov	ip, r5
.Lde_0803A320:
    movs	r3, #0
    cmp	r3, sl
    bge .Lde_0803A36C
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    mov	r2, ip
    adds	r1, r7, r2
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Lde_0803A33C
    str	r3, [sp, #0]
    ldrb	r5, [r7, #4]
    str	r5, [sp, #4]
    b .Lde_0803A36C
.Lde_0803A33C:
    lsls	r0, r3, #2
    adds	r0, r0, r3
    adds	r0, r0, r7
    add	r0, ip
    ldrb	r0, [r0, #0]
    subs	r0, r4, r0
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    adds	r3, #1
    cmp	r3, sl
    bge .Lde_0803A36C
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    lsls	r1, r3, #2
    adds	r1, r1, r3
    adds	r2, r1, r7
    mov	r5, ip
    adds	r1, r2, r5
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Lde_0803A33C
    str	r3, [sp, #0]
    ldrb	r2, [r2, #4]
    str	r2, [sp, #4]
.Lde_0803A36C:
    ldr	r0, [sp, #0]
    cmp	r0, #0
    beq .Lde_0803A37C
    mov	r1, r9
    cmp	r1, #0
    beq .Lde_0803A37C
    adds	r0, #9
    str	r0, [sp, #0]
.Lde_0803A37C:
    ldr	r2, [sp, #4]
    cmp	r2, #1
    ble .Lde_0803A38E
    adds	r0, r2, #0
    subs	r0, #1
    bl func_080AB788
    adds	r0, #1
    str	r0, [sp, #4]
.Lde_0803A38E:
    ldr	r3, [sp, #4]
    cmp	r3, #0
    bgt .Lde_0803A396
    b .Lde_0803A696
.Lde_0803A396:
    movs	r0, #196	@ 0xc4
    lsls	r0, r0, #1
    bl func_080AB788
    adds	r5, r0, #0
    adds	r5, #184	@ 0xb8
    cmp	r5, #239	@ 0xef
    bgt .Lde_0803A3B4
    movs	r0, #56	@ 0x38
    bl func_080AB788
    movs	r1, #248	@ 0xf8
    lsls	r1, r1, #1
    adds	r7, r0, r1
    b .Lde_0803A3C0
.Lde_0803A3B4:
    movs	r0, #48	@ 0x30
    bl func_080AB788
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r7, r0, r2
.Lde_0803A3C0:
    ldr	r0, [sp, #0]
    subs	r0, #1
    cmp	r0, #11
    bls .Lde_0803A3CA
    b .Lde_0803A68A
.Lde_0803A3CA:
    lsls	r0, r0, #2
    ldr r1, .Lde_0803A3D4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_0803A3D4:
    .4byte .Lde_0803A3D8
.Lde_0803A3D8:
    .4byte .Lde_0803A408
    .4byte .Lde_0803A470
    .4byte .Lde_0803A48C
    .4byte .Lde_0803A4AC
    .4byte .Lde_0803A4CC
    .4byte .Lde_0803A51C
    .4byte .Lde_0803A584
    .4byte .Lde_0803A5A4
    .4byte .Lde_0803A5C4
    .4byte .Lde_0803A5E4
    .4byte .Lde_0803A604
    .4byte .Lde_0803A624
.Lde_0803A408:
    .4byte 0xF7C62064
    .4byte 0x1C04F8ED
    .4byte 0x4A154641
    .4byte 0xF7FF2301
    .4byte 0x4814FCC9
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x210065A0
    .4byte 0x04005E68
    .4byte 0x1C3165E0
    .4byte 0x68B03108
    .4byte 0xD9002802
    .4byte 0x0080E119
    .4byte 0x18083004
    .4byte 0xD1002800
    .4byte 0x6004E110
    .4byte 0x0000E10E
    .4byte 0x000009B6
    .4byte vtable_unk_080E76A4
.Lde_0803A470:
    .4byte 0xF7C62064
    .4byte 0x1C04F8B9
    .4byte 0x22104641
    .4byte 0xF7FF2301
    .4byte 0x4801FC95
    .4byte 0x0000E7CA
    .4byte vtable_unk_080E768C
.Lde_0803A48C:
    .4byte 0xF7C62064
    .4byte 0x1C04F8AB
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC87
    .4byte 0x0000E7BC
    .4byte 0x000003DB
    .4byte vtable_unk_080E7674
.Lde_0803A4AC:
    .4byte 0xF7C62064
    .4byte 0x1C04F89B
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC77
    .4byte 0x0000E7AC
    .4byte 0x00000806
    .4byte vtable_unk_080E765C
.Lde_0803A4CC:
    .4byte 0xF7C6206C
    .4byte 0x1C04F88B
    .4byte 0x4A0F4641
    .4byte 0xF7FF2301
    .4byte 0x480EFC67
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x220065A0
    .4byte 0x04005EA8
    .4byte 0x66A165E0
    .4byte 0x0000E79B
    .4byte 0x00000202
    .4byte vtable_unk_080E7644
.Lde_0803A51C:
    .4byte 0xF7C62088
    .4byte 0x1C05F863
    .4byte 0x22A94641
    .4byte 0x23010092
    .4byte 0xFC3EF7FF
    .4byte 0x64E84813
    .4byte 0x652C2400
    .4byte 0x31501C29
    .4byte 0x22011C28
    .4byte 0xF7FF4252
    .4byte 0x1C29FD89
    .4byte 0x70083178
    .4byte 0x20FF3101
    .4byte 0x1C287008
    .4byte 0x21003060
    .4byte 0x30028004
    .4byte 0x380E7001
    .4byte 0x5EC02300
    .4byte 0x65A80400
    .4byte 0x30561C28
    .4byte 0x5E402100
    .4byte 0x65E80400
    .4byte 0x31841C29
    .4byte 0x700820F8
    .4byte 0x0000E077
    .4byte vtable_unk_080E762C
.Lde_0803A584:
    .4byte 0xF7C62064
    .4byte 0x1C04F82F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC0B
    .4byte 0x0000E740
    .4byte 0x0000087B
    .4byte vtable_unk_080E7614
.Lde_0803A5A4:
    .4byte 0xF7C62064
    .4byte 0x1C04F81F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBFB
    .4byte 0x0000E730
    .4byte 0x0000065C
    .4byte vtable_unk_080E75FC
.Lde_0803A5C4:
    .4byte 0xF7C62064
    .4byte 0x1C04F80F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBEB
    .4byte 0x0000E720
    .4byte 0x000008F9
    .4byte vtable_unk_080E75E4
.Lde_0803A5E4:
    .4byte 0xF7C52064
    .4byte 0x1C04FFFF
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBDB
    .4byte 0x0000E710
    .4byte 0x000009A9
    .4byte vtable_unk_080E75CC
.Lde_0803A604:
    .4byte 0xF7C52064
    .4byte 0x1C04FFEF
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBCB
    .4byte 0x0000E700
    .4byte 0x000008FD
    .4byte vtable_unk_080E75B4
.Lde_0803A624:
    .4byte 0xF7C52064
    .4byte 0x1C05FFDF
    .4byte 0x22154641
    .4byte 0xF7FF2300
    .4byte 0x481CFBBB
    .4byte 0x240064E8
    .4byte 0x1C29652C
    .4byte 0x1C283150
    .4byte 0x42522201
    .4byte 0xFD06F7FF
    .4byte 0x30601C28
    .4byte 0x80042100
    .4byte 0x70013002
    .4byte 0x2200380E
    .4byte 0x04005E80
    .4byte 0x1C2865A8
    .4byte 0x23003056
    .4byte 0x04005EC0
    .4byte 0x1C3165E8
    .4byte 0x68B03108
    .4byte 0xD8082802
    .4byte 0x30040080
    .4byte 0x28001808
    .4byte 0x6005D000
    .4byte 0x300168B0
    .hword 0x60B0
.Lde_0803A68A:
    ldr	r5, [sp, #4]
    subs	r5, #1
    str	r5, [sp, #4]
    cmp	r5, #0
    ble .Lde_0803A696
    b .Lde_0803A396
.Lde_0803A696:
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte vtable_unk_080E759C
    .global func_0803A798
    .thumb_func
func_0803A798:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    movs	r0, #32
    bl __builtin_new
    adds	r5, r0, #0
    mov	r1, sp
    ldrh	r2, [r1, #0]
    ldr r3, .Lde_0803A710
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldrb	r4, [r1, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r4
    strb	r0, [r1, #1]
    ldrh	r4, [r1, #2]
    adds	r0, r3, #0
    ands	r0, r4
    strh	r0, [r1, #2]
    ldrb	r0, [r1, #3]
    ands	r2, r0
    strb	r2, [r1, #3]
    ldrh	r0, [r1, #4]
    ands	r3, r0
    strh	r3, [r1, #4]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lde_0803A714
    str	r0, [r5, #20]
    mov	r0, r8
    str	r0, [r5, #24]
    movs	r0, #1
    strb	r0, [r5, #28]
    adds	r0, r5, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803A710:
    .4byte 0xFFFFFC00
.Lde_0803A714:
    .4byte vtable_unk_080E7568
    adds	r0, #48	@ 0x30
    movs	r1, #16
    ldrsh	r0, [r0, r1]
    bx	lr
    adds	r0, #48	@ 0x30
    strh	r1, [r0, #16]
    bx	lr
    .align 2, 0
    push	{lr}
    adds	r0, #48	@ 0x30
    bl func_0805E894
    pop	{r1}
    bx	r1
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #48	@ 0x30
    movs	r2, #0
    ldrh	r0, [r1, #14]
    cmp	r0, #0
    beq .Lde_0803A74C
    movs	r0, #16
    ldrsh	r1, [r1, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Lde_0803A74C:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_0803A778
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_0803A77C
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lde_0803A77A
.Lde_0803A778:
    movs	r0, #0
.Lde_0803A77A:
    strb	r0, [r1, #0]
.Lde_0803A77C:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldrh	r0, [r4, #4]
    cmp	r0, r5
    beq .Lde_0803A7AC
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    strh	r5, [r4, #4]
.Lde_0803A7AC:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    ldr	r0, [r0, #0]
    bx	lr

    .else
    @ ROM-verified US Thumb entity UI code
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08035380
    .thumb_func
func_08035380:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #188	@ 0xbc
    adds	r6, r0, #0
    ldr	r5, [r6, #0]
    ldr	r1, [r6, #56]	@ 0x38
    cmp	r1, #0
    bne .Lus_08035398
    b .Lus_080358F8
.Lus_08035398:
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #112]	@ 0x70
    cmp	r0, #0
    bne .Lus_080353AC
    b .Lus_080358F8
.Lus_080353AC:
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    str	r0, [sp, #176]	@ 0xb0
    ldr	r0, [sp, #112]	@ 0x70
    ldrh	r0, [r0, #0]
    cmp	r1, r0
    bcc .Lus_080353BE
    b .Lus_080358F8
.Lus_080353BE:
    lsls	r1, r1, #3
    ldr	r2, [sp, #112]	@ 0x70
    ldr	r0, [r2, #4]
    adds	r7, r0, r1
    ldr	r3, [r7, #4]
    str	r3, [sp, #116]	@ 0x74
    cmp	r3, #0
    bne .Lus_080353D0
    b .Lus_080358F8
.Lus_080353D0:
    ldr	r0, [r5, #0]
    movs	r4, #162	@ 0xa2
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r1, [r0, #0]
    adds	r0, r5, #0
    bl _call_via_r1
    ldrh	r3, [r0, #10]
    lsls	r0, r3, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lus_080353EE
    adds	r2, #24
.Lus_080353EE:
    lsls	r1, r2, #4
    subs	r1, r1, r2
    lsls	r1, r1, #2
    lsls	r0, r3, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    movs	r0, #0
    str	r0, [sp, #120]	@ 0x78
    ldr	r2, [sp, #116]	@ 0x74
    ldr	r3, [r2, #0]
    cmp	r3, #0
    bne .Lus_08035408
    b .Lus_080358C0
.Lus_08035408:
    ldrh	r4, [r2, #4]
    cmp	r4, #0
    bne .Lus_08035410
    b .Lus_080358C0
.Lus_08035410:
    adds	r0, r6, #0
    adds	r0, #62	@ 0x3e
    ldrb	r2, [r0, #0]
    str	r0, [sp, #180]	@ 0xb4
    cmp	r2, r4
    bcc .Lus_0803541E
    b .Lus_080358F8
.Lus_0803541E:
    ldr	r4, [sp, #116]	@ 0x74
    ldrb	r0, [r4, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803542A
    b .Lus_08035638
.Lus_0803542A:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #124]	@ 0x7c
    movs	r1, #0
    ldrb	r0, [r3, #4]
    lsls	r0, r0, #31
    cmp	r0, #0
    bne .Lus_0803543C
    movs	r1, #1
.Lus_0803543C:
    mov	r8, r1
    ldr	r0, [r6, #8]
    str	r0, [sp, #0]
    ldr	r0, [r6, #12]
    str	r0, [sp, #8]
    ldr	r0, [r6, #24]
    str	r0, [sp, #4]
    ldr	r0, [r6, #28]
    str	r0, [sp, #12]
    cmp	r1, #0
    beq .Lus_0803545C
    mov	sl, sp
    mov	r7, sp
    adds	r7, #4
    str	r7, [sp, #128]	@ 0x80
    b .Lus_08035466
.Lus_0803545C:
    add	r0, sp, #8
    mov	sl, r0
    mov	r1, sp
    adds	r1, #12
    str	r1, [sp, #128]	@ 0x80
.Lus_08035466:
    mov	r2, sl
    ldr	r1, [r2, #0]
    asrs	r3, r1, #16
    str	r3, [sp, #132]	@ 0x84
    ldr	r4, [sp, #128]	@ 0x80
    ldr	r0, [r4, #0]
    adds	r1, r1, r0
    str	r1, [sp, #136]	@ 0x88
    asrs	r7, r1, #16
    str	r7, [sp, #140]	@ 0x8c
    subs	r7, r7, r3
    movs	r3, #0
    adds	r0, r6, #0
    adds	r0, #64	@ 0x40
    ldrh	r2, [r0, #0]
    ldr r1, .Lus_080354AC
    str	r0, [sp, #184]	@ 0xb8
    cmp	r2, r1
    blt .Lus_0803548E
    movs	r3, #1
.Lus_0803548E:
    movs	r0, #1
    str	r0, [sp, #144]	@ 0x90
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Lus_080354BE
    movs	r4, #0
    str	r4, [sp, #144]	@ 0x90
    cmp	r3, #0
    beq .Lus_080354B0
    strb	r4, [r1, #0]
    b .Lus_080354B4
    .align 2, 0
.Lus_080354AC:
    .4byte 0x000002EE
.Lus_080354B0:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Lus_080354B4:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_080354BE
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Lus_080354BE:
    cmp	r3, #0
    bne .Lus_080355A0
    cmp	r7, #0
    beq .Lus_080355A0
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_080355A0
    ldrh	r0, [r4, #4]
    ldrh	r2, [r6, #4]
    cmp	r0, r2
    bne .Lus_080355A0
    ldr	r1, [r6, #20]
    add	r0, sp, #16
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #16]
    ldr	r1, [sp, #20]
    str	r0, [sp, #24]
    str	r1, [sp, #28]
    add	r5, sp, #24
    ldr	r1, [r4, #20]
    add	r0, sp, #32
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #32]
    ldr	r1, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    add	r4, sp, #40	@ 0x28
    mov	r3, r8
    cmp	r3, #0
    beq .Lus_08035518
    adds	r2, r7, #0
    movs	r7, #0
    b .Lus_0803551A
.Lus_08035518:
    movs	r2, #0
.Lus_0803551A:
    mov	r9, r7
    movs	r1, #0
    ldrsh	r0, [r5, r1]
    mov	ip, r0
    movs	r3, #4
    ldrsh	r1, [r4, r3]
    subs	r1, r0, r1
    movs	r7, #0
    ldrsh	r0, [r4, r7]
    movs	r7, #4
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    subs	r0, r0, r3
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Lus_080355A0
    add	r3, sp, #48	@ 0x30
    mov	r1, ip
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, r8
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Lus_080355A0
    movs	r5, #0
    str	r5, [sp, #144]	@ 0x90
.Lus_080355A0:
    ldr	r7, [sp, #144]	@ 0x90
    cmp	r7, #0
    beq .Lus_0803562E
    ldr	r1, [sp, #124]	@ 0x7c
    movs	r2, #2
    ldrsh	r0, [r1, r2]
    ldr	r3, [sp, #132]	@ 0x84
    cmp	r3, r0
    beq .Lus_080355D0
    ldr	r4, [sp, #140]	@ 0x8c
    cmp	r4, r0
    beq .Lus_080355D0
    movs	r1, #0
    cmp	r0, r3
    bge .Lus_080355C0
    movs	r1, #1
.Lus_080355C0:
    ldr	r5, [sp, #140]	@ 0x8c
    cmp	r0, r5
    bge .Lus_080355CC
    cmp	r1, #0
    beq .Lus_080355D0
    b .Lus_08035616
.Lus_080355CC:
    cmp	r1, #0
    beq .Lus_08035616
.Lus_080355D0:
    lsls	r0, r0, #16
    mov	r7, sl
    str	r0, [r7, #0]
    movs	r1, #0
    ldr	r0, [sp, #128]	@ 0x80
    str	r1, [r0, #0]
    ldr	r2, [sp, #180]	@ 0xb4
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r3, [sp, #116]	@ 0x74
    ldrh	r3, [r3, #4]
    cmp	r0, r3
    bcs .Lus_080355F6
    movs	r4, #1
    str	r4, [sp, #120]	@ 0x78
    b .Lus_0803561C
.Lus_080355F6:
    ldr	r5, [sp, #176]	@ 0xb0
    ldrb	r0, [r5, #0]
    adds	r0, #1
    ldr	r7, [sp, #112]	@ 0x70
    ldrh	r7, [r7, #0]
    cmp	r0, r7
    blt .Lus_08035606
    b .Lus_080358F8
.Lus_08035606:
    ldr	r0, [sp, #180]	@ 0xb4
    strb	r1, [r0, #0]
    ldrb	r0, [r5, #0]
    adds	r0, #1
    strb	r0, [r5, #0]
    movs	r1, #2
    str	r1, [sp, #120]	@ 0x78
    b .Lus_0803561C
.Lus_08035616:
    ldr	r2, [sp, #136]	@ 0x88
    mov	r3, sl
    str	r2, [r3, #0]
.Lus_0803561C:
    ldr	r0, [sp, #0]
    str	r0, [r6, #8]
    ldr	r0, [sp, #8]
    str	r0, [r6, #12]
    ldr	r0, [sp, #4]
    str	r0, [r6, #24]
    ldr	r0, [sp, #12]
    str	r0, [r6, #28]
    b .Lus_080358E6
.Lus_0803562E:
    ldr	r4, [sp, #184]	@ 0xb8
    ldrh	r0, [r4, #0]
    adds	r0, #1
    strh	r0, [r4, #0]
    b .Lus_080358E6
.Lus_08035638:
    lsls	r0, r2, #3
    adds	r3, r3, r0
    str	r3, [sp, #148]	@ 0x94
    movs	r2, #0
    ldrb	r0, [r3, #6]
    lsls	r0, r0, #29
    cmp	r0, #0
    blt .Lus_0803564A
    movs	r2, #1
.Lus_0803564A:
    mov	r8, r2
    movs	r2, #0
    ldr	r3, [sp, #176]	@ 0xb0
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldr	r4, [sp, #112]	@ 0x70
    ldrh	r4, [r4, #0]
    cmp	r0, r4
    bge .Lus_08035664
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lus_08035664
    movs	r2, #1
.Lus_08035664:
    mov	sl, r2
    cmp	r2, #0
    beq .Lus_08035682
    ldrh	r4, [r6, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #20]
    adds	r0, r5, #0
    bl _call_via_r1
    cmp	r4, r0
    beq .Lus_08035682
    movs	r0, #0
    ldr	r5, [sp, #180]	@ 0xb4
    strb	r0, [r5, #0]
    b .Lus_080358AC
.Lus_08035682:
    adds	r1, r6, #0
    adds	r1, #64	@ 0x40
    ldrh	r0, [r1, #0]
    str	r1, [sp, #184]	@ 0xb8
    cmp	r0, #0
    beq .Lus_08035690
    b .Lus_08035874
.Lus_08035690:
    ldr	r0, [r6, #8]
    str	r0, [sp, #56]	@ 0x38
    ldr	r0, [r6, #12]
    str	r0, [sp, #64]	@ 0x40
    ldr	r0, [r6, #24]
    str	r0, [sp, #60]	@ 0x3c
    ldr	r0, [r6, #28]
    str	r0, [sp, #68]	@ 0x44
    mov	r1, r8
    cmp	r1, #0
    beq .Lus_080356B4
    mov	r2, sp
    adds	r2, #56	@ 0x38
    str	r2, [sp, #152]	@ 0x98
    mov	r3, sp
    adds	r3, #60	@ 0x3c
    str	r3, [sp, #156]	@ 0x9c
    b .Lus_080356C0
.Lus_080356B4:
    mov	r4, sp
    adds	r4, #64	@ 0x40
    str	r4, [sp, #152]	@ 0x98
    mov	r7, sp
    adds	r7, #68	@ 0x44
    str	r7, [sp, #156]	@ 0x9c
.Lus_080356C0:
    ldr	r1, [sp, #152]	@ 0x98
    ldr	r0, [r1, #0]
    asrs	r2, r0, #16
    str	r2, [sp, #160]	@ 0xa0
    ldr	r3, [sp, #156]	@ 0x9c
    ldr	r1, [r3, #0]
    adds	r0, r0, r1
    str	r0, [sp, #164]	@ 0xa4
    asrs	r4, r0, #16
    str	r4, [sp, #168]	@ 0xa8
    subs	r7, r4, r2
    movs	r0, #1
    str	r0, [sp, #172]	@ 0xac
    adds	r0, r6, #0
    adds	r0, #63	@ 0x3f
    ldrb	r2, [r0, #0]
    adds	r1, r0, #0
    cmp	r2, #0
    beq .Lus_08035702
    movs	r3, #0
    str	r3, [sp, #172]	@ 0xac
    mov	r4, sl
    cmp	r4, #0
    beq .Lus_080356F4
    strb	r3, [r1, #0]
    b .Lus_080356F8
.Lus_080356F4:
    subs	r0, r2, #1
    strb	r0, [r1, #0]
.Lus_080356F8:
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_08035702
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
.Lus_08035702:
    mov	r2, sl
    cmp	r2, #0
    bne .Lus_080357E8
    cmp	r7, #0
    beq .Lus_080357E8
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_080357E8
    ldrh	r0, [r4, #4]
    ldrh	r3, [r6, #4]
    cmp	r0, r3
    bne .Lus_080357E8
    ldr	r1, [r6, #20]
    add	r0, sp, #72	@ 0x48
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r0, [sp, #72]	@ 0x48
    ldr	r1, [sp, #76]	@ 0x4c
    str	r0, [sp, #80]	@ 0x50
    str	r1, [sp, #84]	@ 0x54
    add	r5, sp, #80	@ 0x50
    ldr	r1, [r4, #20]
    add	r0, sp, #88	@ 0x58
    ldr	r2, [r1, #12]
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #96]	@ 0x60
    str	r1, [sp, #100]	@ 0x64
    add	r4, sp, #96	@ 0x60
    mov	r0, r8
    cmp	r0, #0
    beq .Lus_08035760
    adds	r2, r7, #0
    movs	r1, #0
    mov	r9, r1
    b .Lus_08035764
.Lus_08035760:
    movs	r2, #0
    mov	r9, r7
.Lus_08035764:
    movs	r7, #0
    ldrsh	r3, [r5, r7]
    mov	r8, r3
    movs	r0, #4
    ldrsh	r1, [r4, r0]
    subs	r1, r3, r1
    movs	r3, #0
    ldrsh	r0, [r4, r3]
    movs	r3, #4
    ldrsh	r7, [r5, r3]
    mov	ip, r7
    subs	r0, r0, r7
    ands	r1, r0
    movs	r0, #2
    ldrsh	r7, [r5, r0]
    movs	r3, #6
    ldrsh	r0, [r4, r3]
    subs	r0, r7, r0
    ands	r1, r0
    movs	r3, #2
    ldrsh	r0, [r4, r3]
    movs	r3, #6
    ldrsh	r5, [r5, r3]
    subs	r0, r0, r5
    ands	r1, r0
    cmp	r1, #0
    blt .Lus_080357E8
    add	r3, sp, #104	@ 0x68
    mov	r1, r8
    adds	r0, r2, r1
    strh	r0, [r3, #0]
    mov	r1, r9
    adds	r0, r1, r7
    strh	r0, [r3, #2]
    mov	r7, ip
    adds	r0, r2, r7
    strh	r0, [r3, #4]
    adds	r0, r1, r5
    strh	r0, [r3, #6]
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    movs	r2, #4
    ldrsh	r0, [r4, r2]
    subs	r1, r1, r0
    movs	r5, #0
    ldrsh	r0, [r4, r5]
    movs	r7, #4
    ldrsh	r2, [r3, r7]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    movs	r5, #6
    ldrsh	r2, [r4, r5]
    subs	r0, r0, r2
    ands	r1, r0
    movs	r7, #2
    ldrsh	r0, [r4, r7]
    movs	r4, #6
    ldrsh	r2, [r3, r4]
    subs	r0, r0, r2
    ands	r1, r0
    cmp	r1, #0
    bge .Lus_080357E8
    movs	r5, #0
    str	r5, [sp, #172]	@ 0xac
.Lus_080357E8:
    ldr	r7, [sp, #172]	@ 0xac
    cmp	r7, #0
    beq .Lus_080358E6
    ldr	r0, [sp, #148]	@ 0x94
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    ldr	r3, [sp, #168]	@ 0xa8
    cmp	r3, r2
    beq .Lus_08035806
    ldr	r4, [sp, #160]	@ 0xa0
    subs	r0, r2, r4
    subs	r1, r2, r3
    eors	r0, r1
    cmp	r0, #0
    bge .Lus_0803585C
.Lus_08035806:
    lsls	r0, r2, #16
    ldr	r5, [sp, #152]	@ 0x98
    str	r0, [r5, #0]
    movs	r1, #0
    ldr	r7, [sp, #156]	@ 0x9c
    str	r1, [r7, #0]
    mov	r0, sl
    cmp	r0, #0
    bne .Lus_08035820
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r0, [r2, #4]
    cmp	r0, #0
    bne .Lus_08035850
.Lus_08035820:
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Lus_0803584A
    strb	r1, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Lus_08035844
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Lus_08035844:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Lus_08035862
.Lus_0803584A:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Lus_08035862
.Lus_08035850:
    movs	r0, #1
    ldr	r2, [sp, #184]	@ 0xb8
    strh	r0, [r2, #0]
    movs	r3, #1
    str	r3, [sp, #120]	@ 0x78
    b .Lus_08035862
.Lus_0803585C:
    ldr	r4, [sp, #164]	@ 0xa4
    ldr	r5, [sp, #152]	@ 0x98
    str	r4, [r5, #0]
.Lus_08035862:
    ldr	r0, [sp, #56]	@ 0x38
    str	r0, [r6, #8]
    ldr	r0, [sp, #64]	@ 0x40
    str	r0, [r6, #12]
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [r6, #24]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [r6, #28]
    b .Lus_080358E6
.Lus_08035874:
    mov	r7, sl
    cmp	r7, #0
    bne .Lus_0803588A
    adds	r0, #1
    strh	r0, [r1, #0]
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr	r2, [sp, #148]	@ 0x94
    ldrh	r2, [r2, #4]
    cmp	r0, r2
    bls .Lus_080358E6
.Lus_0803588A:
    movs	r0, #0
    strh	r0, [r1, #0]
    ldr	r3, [sp, #180]	@ 0xb4
    ldrb	r0, [r3, #0]
    adds	r0, #1
    strb	r0, [r3, #0]
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr	r4, [sp, #116]	@ 0x74
    ldrh	r4, [r4, #4]
    cmp	r0, r4
    bcc .Lus_080358BA
    movs	r0, #0
    strb	r0, [r3, #0]
    mov	r5, sl
    cmp	r5, #0
    beq .Lus_080358B4
.Lus_080358AC:
    ldr	r7, [sp, #176]	@ 0xb0
    ldrb	r0, [r7, #0]
    adds	r0, #1
    strb	r0, [r7, #0]
.Lus_080358B4:
    movs	r0, #2
    str	r0, [sp, #120]	@ 0x78
    b .Lus_080358EC
.Lus_080358BA:
    movs	r1, #1
    str	r1, [sp, #120]	@ 0x78
    b .Lus_080358EC
.Lus_080358C0:
    ldr	r2, [sp, #176]	@ 0xb0
    ldrb	r0, [r2, #0]
    adds	r0, #1
    ldr	r3, [sp, #112]	@ 0x70
    ldrh	r3, [r3, #0]
    cmp	r0, r3
    bge .Lus_080358E6
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lus_080358E6
    adds	r1, r6, #0
    adds	r1, #62	@ 0x3e
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrb	r0, [r2, #0]
    adds	r0, #1
    strb	r0, [r2, #0]
    movs	r4, #2
    str	r4, [sp, #120]	@ 0x78
.Lus_080358E6:
    ldr	r5, [sp, #120]	@ 0x78
    cmp	r5, #0
    ble .Lus_080358F8
.Lus_080358EC:
    ldr	r0, [r6, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r6, #0
    ldr	r1, [sp, #120]	@ 0x78
    bl _call_via_r2
.Lus_080358F8:
    add	sp, #188	@ 0xbc
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08035908
    .thumb_func
func_08035908:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #68	@ 0x44
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Lus_0803593A
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803593A
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Lus_0803593A
    cmp	r0, r5
    beq .Lus_0803593A
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Lus_0803593A:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035940
    .thumb_func
func_08035940:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r0, #70	@ 0x46
    ldrh	r6, [r0, #0]
    cmp	r5, r6
    beq .Lus_08035972
    strh	r5, [r0, #0]
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08035972
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r6
    bne .Lus_08035972
    cmp	r0, r5
    beq .Lus_08035972
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnim__12AActorEntityUi
.Lus_08035972:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08035978
    .thumb_func
func_08035978:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08035A3A
    ldr	r1, [r4, #56]	@ 0x38
    cmp	r1, #0
    beq .Lus_08035A3A
    adds	r0, r4, #0
    adds	r0, #60	@ 0x3c
    ldrb	r0, [r0, #0]
    ldr	r1, [r1, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r6, [r0, #0]
    cmp	r6, #0
    beq .Lus_08035A3A
    adds	r0, r4, #0
    adds	r0, #61	@ 0x3d
    ldrb	r1, [r0, #0]
    mov	r8, r0
    ldrh	r0, [r6, #0]
    cmp	r1, r0
    bcs .Lus_08035A3A
    lsls	r1, r1, #3
    ldr	r0, [r6, #4]
    adds	r7, r0, r1
    ldr	r5, [r7, #4]
    cmp	r5, #0
    beq .Lus_08035A3A
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r1, [r0, #10]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lus_080359E0
    adds	r2, #24
.Lus_080359E0:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r1, r0, r1
    ldr	r0, [r5, #0]
    cmp	r0, #0
    beq .Lus_08035A20
    ldrh	r2, [r5, #4]
    cmp	r2, #0
    beq .Lus_08035A20
    adds	r0, r4, #0
    adds	r0, #62	@ 0x3e
    ldrb	r0, [r0, #0]
    cmp	r0, r2
    bcs .Lus_08035A3A
    ldrb	r0, [r5, #11]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Lus_08035A20
    movs	r2, #0
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    ldrh	r1, [r0, #0]
    ldr r0, .Lus_08035A1C
    cmp	r1, r0
    blt .Lus_08035A36
    b .Lus_08035A34
    .align 2, 0
.Lus_08035A1C:
    .4byte 0x000002EE
.Lus_08035A20:
    movs	r2, #0
    mov	r3, r8
    ldrb	r0, [r3, #0]
    adds	r0, #1
    ldrh	r6, [r6, #0]
    cmp	r0, r6
    bge .Lus_08035A36
    ldrh	r7, [r7, #8]
    cmp	r1, r7
    bcc .Lus_08035A36
.Lus_08035A34:
    movs	r2, #1
.Lus_08035A36:
    adds	r0, r2, #0
    b .Lus_08035A3C
.Lus_08035A3A:
    movs	r0, #0
.Lus_08035A3C:
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035A48
    .thumb_func
func_08035A48:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r3, r1, #0
    ldrh	r1, [r4, #4]
    ldrh	r0, [r3, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r1, r0
    bne .Lus_08035AD6
    movs	r0, #10
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #2]
    ldr r5, .Lus_08035ADC
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lus_08035A78
    negs	r0, r0
.Lus_08035A78:
    cmp	r0, #151	@ 0x97
    bgt .Lus_08035AD6
    movs	r0, #14
    ldrsh	r2, [r4, r0]
    ldrb	r1, [r3, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r3, #4]
    ands	r0, r5
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lus_08035A98
    negs	r0, r0
.Lus_08035A98:
    cmp	r0, #111	@ 0x6f
    bgt .Lus_08035AD6
    adds	r0, r4, #0
    bl func_08035978
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08035AD6
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #40]	@ 0x28
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08035AD6
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r1, r4, #0
    adds	r1, #63	@ 0x3f
    movs	r0, #120	@ 0x78
    strb	r0, [r1, #0]
    ldr	r0, [r4, #20]
    ldr	r2, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    movs	r1, #1
    bl _call_via_r2
.Lus_08035AD6:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Lus_08035ADC:
    .4byte 0x000003FF
    .global func_08035AE0
    .thumb_func
func_08035AE0:
    push	{lr}
    adds	r1, r0, #0
    movs	r2, #0
    ldrh	r0, [r1, #4]
    cmp	r0, #29
    bne .Lus_08035AF6
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    cmp	r0, #55	@ 0x37
    bgt .Lus_08035AF6
    movs	r2, #1
.Lus_08035AF6:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .global func_08035AFC
    .thumb_func
func_08035AFC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035B28
    str	r0, [sp, #0]
    ldr r0, .Lus_08035B2C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035B30
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035B34
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035B28:
    .4byte gUnk_080F280C
.Lus_08035B2C:
    .4byte 0x0000025F
.Lus_08035B30:
    .4byte 0x000003E2
.Lus_08035B34:
    .4byte vtable_unk_080E7198
    .global func_08035B38
    .thumb_func
func_08035B38:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035B64
    .thumb_func
func_08035B64:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035B90
    str	r0, [sp, #0]
    ldr r0, .Lus_08035B94
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #248	@ 0xf8
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035B98
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08035B90:
    .4byte ScheduleInfo_Unk_080F1A80
.Lus_08035B94:
    .4byte 0x00000213
.Lus_08035B98:
    .4byte vtable_unk_080E7158
    .global func_08035B9C
    .thumb_func
func_08035B9C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035BC8
    .thumb_func
func_08035BC8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035BF4
    str	r0, [sp, #0]
    ldr r0, .Lus_08035BF8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035BFC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035C00
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035BF4:
    .4byte gUnk_080F1FC0
.Lus_08035BF8:
    .4byte 0x0000022F
.Lus_08035BFC:
    .4byte 0x000003E1
.Lus_08035C00:
    .4byte vtable_unk_080E7118
    .global func_08035C04
    .thumb_func
func_08035C04:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lus_08035C48
    ldr r0, .Lus_08035C4C
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lus_08035C50
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #3
    bne .Lus_08035C94
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lus_08035C94
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08035C42
    ldr r2, .Lus_08035C54
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_08035C5C
.Lus_08035C42:
    ldr r7, .Lus_08035C58
    b .Lus_08035C94
    .align 2, 0
.Lus_08035C48:
    .4byte 0x0000022F
.Lus_08035C4C:
    .4byte 0x00000233
.Lus_08035C50:
    .4byte 0x00001CD4
.Lus_08035C54:
    .4byte 0x0000216B
.Lus_08035C58:
    .4byte 0x0000023F
.Lus_08035C5C:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_08035C94
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_08035C94
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08035C94
    ldr r7, .Lus_08035CB0
    ldr r0, .Lus_08035CB4
    mov	r8, r0
.Lus_08035C94:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08035CB0:
    .4byte 0x00000247
.Lus_08035CB4:
    .4byte 0x0000024B
    .global func_08035CB8
    .thumb_func
func_08035CB8:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_08035CCC
    adds	r0, r5, #0
    bl func_08035C04
.Lus_08035CCC:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08035CD4
    .thumb_func
func_08035CD4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08035C04
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035D04
    .thumb_func
func_08035D04:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035D30
    str	r0, [sp, #0]
    ldr r0, .Lus_08035D34
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035D38
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035D3C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035D30:
    .4byte gUnk_080F8678
.Lus_08035D34:
    .4byte 0x000009EF
.Lus_08035D38:
    .4byte 0x00000406
.Lus_08035D3C:
    .4byte vtable_unk_080E70D8
    .global func_08035D40
    .thumb_func
func_08035D40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #3
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035D70
    .thumb_func
func_08035D70:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035D9C
    str	r0, [sp, #0]
    ldr r0, .Lus_08035DA0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035DA4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035DA8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035D9C:
    .4byte gUnk_080F81BC
.Lus_08035DA0:
    .4byte 0x000009E7
.Lus_08035DA4:
    .4byte 0x00000405
.Lus_08035DA8:
    .4byte vtable_unk_080E7098
    .global func_08035DAC
    .thumb_func
func_08035DAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035DD8
    .thumb_func
func_08035DD8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035E04
    str	r0, [sp, #0]
    ldr r0, .Lus_08035E08
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035E0C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035E10
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035E04:
    .4byte gUnk_080F77FC
.Lus_08035E08:
    .4byte 0x000009A1
.Lus_08035E0C:
    .4byte 0x00000403
.Lus_08035E10:
    .4byte vtable_unk_080E7058
    .global func_08035E14
    .thumb_func
func_08035E14:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035E40
    .thumb_func
func_08035E40:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035E6C
    str	r0, [sp, #0]
    ldr r0, .Lus_08035E70
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035E74
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035E78
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035E6C:
    .4byte gUnk_080F7294
.Lus_08035E70:
    .4byte 0x00000989
.Lus_08035E74:
    .4byte 0x00000402
.Lus_08035E78:
    .4byte vtable_unk_080E7018
    .global func_08035E7C
    .thumb_func
func_08035E7C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035EAC
    .thumb_func
func_08035EAC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035EDC
    str	r0, [sp, #0]
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035EE0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035EDC:
    .4byte gUnk_080F6370
.Lus_08035EE0:
    .4byte vtable_unk_080E6FD8
    .global func_08035EE4
    .thumb_func
func_08035EE4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F10
    .thumb_func
func_08035F10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035F3C
    str	r0, [sp, #0]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035F40
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035F44
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08035F3C:
    .4byte gUnk_080F66C4
.Lus_08035F40:
    .4byte 0x000003FD
.Lus_08035F44:
    .4byte vtable_unk_080E6F98
    .global func_08035F48
    .thumb_func
func_08035F48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08035F74
    .thumb_func
func_08035F74:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08035FA0
    str	r0, [sp, #0]
    ldr r0, .Lus_08035FA4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08035FA8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08035FAC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08035FA0:
    .4byte gUnk_080F49C0
.Lus_08035FA4:
    .4byte 0x0000080B
.Lus_08035FA8:
    .4byte 0x000003F5
.Lus_08035FAC:
    .4byte vtable_unk_080E6F58
    .global func_08035FB0
    .thumb_func
func_08035FB0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08035FE0
    .thumb_func
func_08035FE0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_0803600C
    str	r0, [sp, #0]
    ldr r0, .Lus_08036010
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08036014
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036018
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803600C:
    .4byte gUnk_080F5540
.Lus_08036010:
    .4byte 0x0000084B
.Lus_08036014:
    .4byte 0x000003F7
.Lus_08036018:
    .4byte vtable_unk_080E6F18
    .global func_0803601C
    .thumb_func
func_0803601C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036048
    .thumb_func
func_08036048:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036074
    str	r0, [sp, #0]
    ldr r0, .Lus_08036078
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_0803607C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036080
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036074:
    .4byte gUnk_080F4D74
.Lus_08036078:
    .4byte 0x00000813
.Lus_0803607C:
    .4byte 0x000003F6
.Lus_08036080:
    .4byte vtable_unk_080E6ED8
    .global func_08036084
    .thumb_func
func_08036084:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lus_080360C8
    ldr r0, .Lus_080360CC
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lus_080360D0
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #12
    bne .Lus_08036114
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lus_08036114
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_080360C2
    ldr r2, .Lus_080360D4
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_080360DC
.Lus_080360C2:
    ldr r7, .Lus_080360D8
    b .Lus_08036114
    .align 2, 0
.Lus_080360C8:
    .4byte 0x00000813
.Lus_080360CC:
    .4byte 0x00000817
.Lus_080360D0:
    .4byte 0x00001CD4
.Lus_080360D4:
    .4byte 0x0000216C
.Lus_080360D8:
    .4byte 0x00000827
.Lus_080360DC:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_08036114
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_08036114
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08036114
    ldr r7, .Lus_08036130
    ldr r0, .Lus_08036134
    mov	r8, r0
.Lus_08036114:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08036130:
    .4byte 0x0000082F
.Lus_08036134:
    .4byte 0x00000833
    .global func_08036138
    .thumb_func
func_08036138:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_0803614C
    adds	r0, r5, #0
    bl func_08036084
.Lus_0803614C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036154
    .thumb_func
func_08036154:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036084
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036184
    .thumb_func
func_08036184:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080361B0
    str	r0, [sp, #0]
    ldr r0, .Lus_080361B4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_080361B8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_080361BC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080361B0:
    .4byte gUnk_080F59CC
.Lus_080361B4:
    .4byte 0x0000085F
.Lus_080361B8:
    .4byte 0x000003F9
.Lus_080361BC:
    .4byte vtable_unk_080E6E98
    .global func_080361C0
    .thumb_func
func_080361C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080361EC
    .thumb_func
func_080361EC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036218
    str	r0, [sp, #0]
    ldr r0, .Lus_0803621C
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08036220
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036224
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036218:
    .4byte gUnk_080F6B4C
.Lus_0803621C:
    .4byte 0x000008E4
.Lus_08036220:
    .4byte 0x000003FF
.Lus_08036224:
    .4byte vtable_unk_080E6E58
    .global func_08036228
    .thumb_func
func_08036228:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036258
    .thumb_func
func_08036258:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036280
    str	r0, [sp, #0]
    ldr r0, .Lus_08036284
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    ldr r0, .Lus_08036288
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_0803628C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08036280:
    .4byte gUnk_080F33B8
.Lus_08036284:
    .4byte 0x00000685
.Lus_08036288:
    .4byte 0x000003EE
.Lus_0803628C:
    .4byte vtable_unk_080E6E18
    .global func_08036290
    .thumb_func
func_08036290:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080362C0
    .thumb_func
func_080362C0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080362EC
    str	r0, [sp, #0]
    ldr r0, .Lus_080362F0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_080362F4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_080362F8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080362EC:
    .4byte gUnk_080F61FC
.Lus_080362F0:
    .4byte 0x000008B8
.Lus_080362F4:
    .4byte 0x000003FB
.Lus_080362F8:
    .4byte vtable_unk_080E6DD8
    .global func_080362FC
    .thumb_func
func_080362FC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036328
    .thumb_func
func_08036328:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036354
    str	r0, [sp, #0]
    ldr r0, .Lus_08036358
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_0803635C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036360
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036354:
    .4byte gUnk_080F3408
.Lus_08036358:
    .4byte 0x00000689
.Lus_0803635C:
    .4byte 0x000003EF
.Lus_08036360:
    .4byte vtable_unk_080E6D98
    .global func_08036364
    .thumb_func
func_08036364:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036390
    .thumb_func
func_08036390:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080363BC
    str	r0, [sp, #0]
    ldr r0, .Lus_080363C0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_080363C4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_080363C8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080363BC:
    .4byte gUnk_080F3FD8
.Lus_080363C0:
    .4byte 0x000006C5
.Lus_080363C4:
    .4byte 0x000003F1
.Lus_080363C8:
    .4byte vtable_unk_080E6D58
    .global func_080363CC
    .thumb_func
func_080363CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080363F8
    .thumb_func
func_080363F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036424
    str	r0, [sp, #0]
    ldr r0, .Lus_08036428
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #252	@ 0xfc
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_0803642C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08036424:
    .4byte gUnk_080F35E4
.Lus_08036428:
    .4byte 0x00000691
.Lus_0803642C:
    .4byte vtable_unk_080E6D18
    .global func_08036430
    .thumb_func
func_08036430:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lus_08036474
    ldr r0, .Lus_08036478
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lus_0803647C
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #19
    bne .Lus_080364C0
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lus_080364C0
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803646E
    ldr r2, .Lus_08036480
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_08036488
.Lus_0803646E:
    ldr r7, .Lus_08036484
    b .Lus_080364C0
    .align 2, 0
.Lus_08036474:
    .4byte 0x00000691
.Lus_08036478:
    .4byte 0x00000695
.Lus_0803647C:
    .4byte 0x00001CD4
.Lus_08036480:
    .4byte 0x0000216C
.Lus_08036484:
    .4byte 0x000006A1
.Lus_08036488:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_080364C0
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_080364C0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_080364C0
    ldr r7, .Lus_080364DC
    ldr r0, .Lus_080364E0
    mov	r8, r0
.Lus_080364C0:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_080364DC:
    .4byte 0x000006AD
.Lus_080364E0:
    .4byte 0x000006B1
    .global func_080364E4
    .thumb_func
func_080364E4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_080364F8
    adds	r0, r5, #0
    bl func_08036430
.Lus_080364F8:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036500
    .thumb_func
func_08036500:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036430
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036530
    .thumb_func
func_08036530:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_0803655C
    str	r0, [sp, #0]
    movs	r0, #200	@ 0xc8
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #194	@ 0xc2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036560
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_0803655C:
    .4byte gUnk_080F3010
.Lus_08036560:
    .4byte vtable_unk_080E6CD8
    .global func_08036564
    .thumb_func
func_08036564:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036590
    .thumb_func
func_08036590:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080365BC
    str	r0, [sp, #0]
    ldr r0, .Lus_080365C0
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_080365C4
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_080365C8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080365BC:
    .4byte gUnk_080F5D94
.Lus_080365C0:
    .4byte 0x00000884
.Lus_080365C4:
    .4byte 0x000003FA
.Lus_080365C8:
    .4byte vtable_unk_080E6C98
    .global func_080365CC
    .thumb_func
func_080365CC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lus_08036610
    ldr r0, .Lus_08036614
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lus_08036618
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #21
    bne .Lus_0803665C
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lus_0803665C
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803660A
    ldr r2, .Lus_0803661C
    adds	r0, r5, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_08036624
.Lus_0803660A:
    ldr r7, .Lus_08036620
    b .Lus_0803665C
    .align 2, 0
.Lus_08036610:
    .4byte 0x00000884
.Lus_08036614:
    .4byte 0x00000888
.Lus_08036618:
    .4byte 0x00001CD4
.Lus_0803661C:
    .4byte 0x0000216C
.Lus_08036620:
    .4byte 0x0000089C
.Lus_08036624:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_0803665C
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_0803665C
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803665C
    ldr r7, .Lus_08036678
    ldr r0, .Lus_0803667C
    mov	r8, r0
.Lus_0803665C:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08036678:
    .4byte 0x00000894
.Lus_0803667C:
    .4byte 0x00000898
    .global func_08036680
    .thumb_func
func_08036680:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_08036694
    adds	r0, r5, #0
    bl func_080365CC
.Lus_08036694:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803669C
    .thumb_func
func_0803669C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_080365CC
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080366CC
    .thumb_func
func_080366CC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080366F8
    str	r0, [sp, #0]
    ldr r0, .Lus_080366FC
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #3
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036700
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_080366F8:
    .4byte gUnk_080F6DE8
.Lus_080366FC:
    .4byte 0x000008EC
.Lus_08036700:
    .4byte vtable_unk_080E6C58
    .global func_08036704
    .thumb_func
func_08036704:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036730
    .thumb_func
func_08036730:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_0803675C
    str	r0, [sp, #0]
    ldr r0, .Lus_08036760
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #249	@ 0xf9
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036764
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_0803675C:
    .4byte gUnk_080F2AF8
.Lus_08036760:
    .4byte 0x0000027B
.Lus_08036764:
    .4byte vtable_unk_080E6C18
    .global func_08036768
    .thumb_func
func_08036768:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Lus_080367A0
    movs	r5, #2
    ldr	r0, [r4, #52]	@ 0x34
    ldr r2, .Lus_080367A4
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_08036784
    adds	r1, #24
    movs	r5, #1
.Lus_08036784:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    ldr r1, .Lus_080367A8
    bl func_08035940
    adds	r0, r4, #0
    adds	r0, #33	@ 0x21
    strb	r5, [r0, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_080367A0:
    .4byte 0x0000027B
.Lus_080367A4:
    .4byte 0x00002181
.Lus_080367A8:
    .4byte 0x0000027F
    .global func_080367AC
    .thumb_func
func_080367AC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_080367C0
    adds	r0, r5, #0
    bl func_08036768
.Lus_080367C0:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080367C8
    .thumb_func
func_080367C8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036768
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080367F8
    .thumb_func
func_080367F8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036824
    str	r0, [sp, #0]
    ldr r0, .Lus_08036828
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_0803682C
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036830
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036824:
    .4byte gUnk_080F42F0
.Lus_08036828:
    .4byte 0x000007B2
.Lus_0803682C:
    .4byte 0x000003F2
.Lus_08036830:
    .4byte vtable_unk_080E6BD8
    .global func_08036834
    .thumb_func
func_08036834:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036860
    .thumb_func
func_08036860:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_0803688C
    str	r0, [sp, #0]
    ldr r0, .Lus_08036890
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #253	@ 0xfd
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036894
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_0803688C:
    .4byte gUnk_080F4974
.Lus_08036890:
    .4byte 0x000007F2
.Lus_08036894:
    .4byte vtable_unk_080E6B98
    .global func_08036898
    .thumb_func
func_08036898:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080368C4
    .thumb_func
func_080368C4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_080368F0
    str	r0, [sp, #0]
    ldr r0, .Lus_080368F4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_080368F8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_080368FC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080368F0:
    .4byte gUnk_080F43DC
.Lus_080368F4:
    .4byte 0x000007BE
.Lus_080368F8:
    .4byte 0x000003F3
.Lus_080368FC:
    .4byte vtable_unk_080E6B58
    .global func_08036900
    .thumb_func
func_08036900:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r4, r0, #0
    ldr r7, .Lus_08036950
    ldr r0, .Lus_08036954
    mov	r8, r0
    ldr	r5, [r4, #52]	@ 0x34
    ldr r1, .Lus_08036958
    adds	r6, r5, r1
    adds	r0, r6, #0
    bl func_080A0490
    cmp	r0, #25
    bne .Lus_080369A0
    ldrh	r0, [r4, #4]
    cmp	r0, #29
    bne .Lus_080369A0
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803694A
    ldr r2, .Lus_0803695C
    adds	r0, r5, r2
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    ldr r1, .Lus_08036960
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Lus_08036968
.Lus_0803694A:
    ldr r7, .Lus_08036964
    b .Lus_080369A0
    .align 2, 0
.Lus_08036950:
    .4byte 0x000007BE
.Lus_08036954:
    .4byte 0x000007C2
.Lus_08036958:
    .4byte 0x00001CD4
.Lus_0803695C:
    .4byte 0x0000216B
.Lus_08036960:
    .4byte 0x0000216C
.Lus_08036964:
    .4byte 0x000007D2
.Lus_08036968:
    adds	r0, r6, #0
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_080369A0
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_080369A0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r1, #10
    adds	r0, r5, #0
    bl func_08034C64
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_080369A0
    ldr r7, .Lus_080369BC
    ldr r0, .Lus_080369C0
    mov	r8, r0
.Lus_080369A0:
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035908
    adds	r0, r4, #0
    mov	r1, r8
    bl func_08035940
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_080369BC:
    .4byte 0x000007CA
.Lus_080369C0:
    .4byte 0x000007CE
    .global func_080369C4
    .thumb_func
func_080369C4:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_080369D8
    adds	r0, r5, #0
    bl func_08036900
.Lus_080369D8:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080369E0
    .thumb_func
func_080369E0:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036900
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A10
    .thumb_func
func_08036A10:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036A3C
    str	r0, [sp, #0]
    ldr r0, .Lus_08036A40
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08036A44
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036A48
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036A3C:
    .4byte gUnk_080F6FF8
.Lus_08036A40:
    .4byte 0x00000902
.Lus_08036A44:
    .4byte 0x00000401
.Lus_08036A48:
    .4byte vtable_unk_080E6B18
    .global func_08036A4C
    .thumb_func
func_08036A4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036A78
    .thumb_func
func_08036A78:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036AA4
    str	r0, [sp, #0]
    ldr r0, .Lus_08036AA8
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08036AAC
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036AB0
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036AA4:
    .4byte gUnk_080F7B40
.Lus_08036AA8:
    .4byte 0x000009D3
.Lus_08036AAC:
    .4byte 0x00000404
.Lus_08036AB0:
    .4byte vtable_unk_080E6AD8
    .global func_08036AB4
    .thumb_func
func_08036AB4:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    ldr r1, .Lus_08036AD0
    ldr r5, .Lus_08036AD4
    ldrh	r0, [r4, #4]
    adds	r2, r0, #0
    cmp	r0, #17
    beq .Lus_08036AE0
    cmp	r0, #17
    bgt .Lus_08036AD8
    cmp	r0, #7
    beq .Lus_08036AE0
    b .Lus_08036AE4
    .align 2, 0
.Lus_08036AD0:
    .4byte 0x000009D3
.Lus_08036AD4:
    .4byte 0x000009D7
.Lus_08036AD8:
    cmp	r2, #29
    beq .Lus_08036AE0
    cmp	r2, #37	@ 0x25
    bne .Lus_08036AE4
.Lus_08036AE0:
    ldr r1, .Lus_08036AF8
    ldr r5, .Lus_08036AFC
.Lus_08036AE4:
    adds	r0, r4, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035940
    pop	{r4, r5}
    pop	{r0}
    bx	r0
.Lus_08036AF8:
    .4byte 0x000009DF
.Lus_08036AFC:
    .4byte 0x000009E3
    .global func_08036B00
    .thumb_func
func_08036B00:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_08036B14
    adds	r0, r5, #0
    bl func_08036AB4
.Lus_08036B14:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036B1C
    .thumb_func
func_08036B1C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    bl func_08036AB4
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #5
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036B4C
    .thumb_func
func_08036B4C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036B78
    str	r0, [sp, #0]
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #2
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    adds	r0, #201	@ 0xc9
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036B7C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08036B78:
    .4byte gUnk_080F2DC0
.Lus_08036B7C:
    .4byte vtable_unk_080E6A98
    .global func_08036B80
    .thumb_func
func_08036B80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036BB0
    .thumb_func
func_08036BB0:
    push	{r4, r5, r6, lr}
    adds	r4, r0, #0
    movs	r0, #10
    ldrsh	r5, [r4, r0]
    movs	r2, #14
    ldrsh	r6, [r4, r2]
    adds	r0, r4, #0
    bl func_08034EB4
    ldrh	r0, [r4, #4]
    cmp	r0, #2
    bne .Lus_08036BF0
    cmp	r5, #244	@ 0xf4
    bne .Lus_08036BD0
    cmp	r6, #171	@ 0xab
    beq .Lus_08036BF0
.Lus_08036BD0:
    movs	r1, #10
    ldrsh	r0, [r4, r1]
    movs	r2, #14
    ldrsh	r1, [r4, r2]
    cmp	r0, #244	@ 0xf4
    bne .Lus_08036BF0
    cmp	r1, #171	@ 0xab
    bne .Lus_08036BF0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Lus_08036BF0:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036BF8
    .thumb_func
func_08036BF8:
    push	{r4, r5, r6, r7, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    movs	r0, #10
    ldrsh	r6, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_08036C40
    ldrh	r0, [r5, #4]
    cmp	r0, #2
    bne .Lus_08036C40
    cmp	r6, #244	@ 0xf4
    bne .Lus_08036C20
    cmp	r7, #171	@ 0xab
    beq .Lus_08036C40
.Lus_08036C20:
    movs	r2, #10
    ldrsh	r0, [r5, r2]
    movs	r2, #14
    ldrsh	r1, [r5, r2]
    cmp	r0, #244	@ 0xf4
    bne .Lus_08036C40
    cmp	r1, #171	@ 0xab
    bne .Lus_08036C40
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
.Lus_08036C40:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036C48
    .thumb_func
func_08036C48:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036C74
    str	r0, [sp, #0]
    ldr r0, .Lus_08036C78
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    movs	r0, #254	@ 0xfe
    lsls	r0, r0, #2
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036C7C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08036C74:
    .4byte gUnk_080F597C
.Lus_08036C78:
    .4byte 0x00000857
.Lus_08036C7C:
    .4byte vtable_unk_080E6A58
    .global func_08036C80
    .thumb_func
func_08036C80:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036CAC
    .thumb_func
func_08036CAC:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lus_08036CD4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036CD8
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lus_08036CD4:
    .4byte 0x00000679
.Lus_08036CD8:
    .4byte vtable_unk_080E6A18
    .global func_08036CDC
    .thumb_func
func_08036CDC:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #2
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036D0C
    .thumb_func
func_08036D0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lus_08036D34
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036D38
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lus_08036D34:
    .4byte 0x00000669
.Lus_08036D38:
    .4byte vtable_unk_080E69D8
    .global func_08036D3C
    .thumb_func
func_08036D3C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036D68
    .thumb_func
func_08036D68:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    movs	r4, #0
    str	r4, [sp, #0]
    ldr r0, .Lus_08036D90
    str	r0, [sp, #4]
    str	r0, [sp, #8]
    str	r4, [sp, #12]
    adds	r0, r5, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036D94
    str	r0, [r5, #20]
    adds	r0, r5, #0
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036D90:
    .4byte 0x000007FE
.Lus_08036D94:
    .4byte vtable_unk_080E6998
    .global func_08036D98
    .thumb_func
func_08036D98:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036DC4
    .thumb_func
func_08036DC4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036DF0
    str	r0, [sp, #0]
    ldr r0, .Lus_08036DF4
    str	r0, [sp, #4]
    adds	r0, #4
    str	r0, [sp, #8]
    ldr r0, .Lus_08036DF8
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036DFC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036DF0:
    .4byte gUnk_080F6B10
.Lus_08036DF4:
    .4byte 0x000008D8
.Lus_08036DF8:
    .4byte 0x000003FE
.Lus_08036DFC:
    .4byte vtable_unk_080E6958
    .global func_08036E00
    .thumb_func
func_08036E00:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #1
    str	r1, [sp, #0]
    movs	r1, #0
    str	r1, [sp, #4]
    str	r1, [sp, #8]
    add	r2, sp, #12
    strb	r1, [r2, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08036E2C
    .thumb_func
func_08036E2C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    ldr r0, .Lus_08036E60
    str	r0, [sp, #0]
    ldr r0, .Lus_08036E64
    str	r0, [sp, #4]
    adds	r0, #8
    str	r0, [sp, #8]
    ldr r0, .Lus_08036E68
    str	r0, [sp, #12]
    adds	r0, r4, #0
    bl __10ANpcEntityP10GameObjectP3NpcUiPCvUiUiUi
    ldr r0, .Lus_08036E6C
    str	r0, [r4, #20]
    adds	r1, r4, #0
    adds	r1, #72	@ 0x48
    movs	r0, #0
    strh	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08036E60:
    .4byte gUnk_080F29C0
.Lus_08036E64:
    .4byte 0x00000267
.Lus_08036E68:
    .4byte 0x000003E3
.Lus_08036E6C:
    .4byte vtable_unk_080E6918
    .global func_08036E70
    .thumb_func
func_08036E70:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Lus_08036EA0
    adds	r0, r0, r1
    bl func_080A0384
    adds	r6, r0, #0
    cmp	r0, #0
    beq .Lus_08036EE0
    ldr r5, .Lus_08036EA4
    ldr r7, .Lus_08036EA8
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_08036EAC
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08036ED0
    movs	r5, #12
    b .Lus_08036ED0
.Lus_08036EA0:
    .4byte 0x00001CD4
.Lus_08036EA4:
    .4byte 0x00000267
.Lus_08036EA8:
    .4byte 0x0000026F
.Lus_08036EAC:
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08036EC0
    ldr r5, .Lus_08036EBC
    b .Lus_08036ED0
.Lus_08036EBC:
    .4byte 0x00000277
.Lus_08036EC0:
    adds	r0, r6, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08036ED0
    ldr r5, .Lus_08036EE8
    ldr r7, .Lus_08036EEC
.Lus_08036ED0:
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_08035908
    adds	r0, r4, #0
    adds	r1, r7, #0
    bl func_08035940
.Lus_08036EE0:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08036EE8:
    .4byte 0x0000026B
.Lus_08036EEC:
    .4byte 0x00000273
    .global func_08036EF0
    .thumb_func
func_08036EF0:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08034F00
    cmp	r4, #1
    ble .Lus_08036F04
    adds	r0, r5, #0
    bl func_08036E70
.Lus_08036F04:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08036F0C
    .thumb_func
func_08036F0C:
    push	{r4, r5, lr}
    sub	sp, #16
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    ldr r1, .Lus_08036F58
    adds	r0, r0, r1
    bl func_080A0384
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_08036F5C
    adds	r0, r5, #0
    bl func_08036E70
    adds	r0, r4, #0
    bl func_0809EAE0
    lsls	r0, r0, #24
    movs	r4, #1
    cmp	r0, #0
    beq .Lus_08036F38
    movs	r4, #4
.Lus_08036F38:
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r5, #0
    movs	r2, #4
    movs	r3, #27
    bl func_080324BC
    b .Lus_08036F5E
    .align 2, 0
.Lus_08036F58:
    .4byte 0x00001CD4
.Lus_08036F5C:
    movs	r0, #0
.Lus_08036F5E:
    add	sp, #16
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08036F68
    .thumb_func
func_08036F68:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r6, r1, #0
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Lus_08036FF2
    ldr	r0, [r4, #52]	@ 0x34
    ldr r1, .Lus_08036FA8
    adds	r0, r0, r1
    bl func_080A0384
    cmp	r0, #0
    beq .Lus_08036FF2
    bl func_0809EAD8
    cmp	r0, #59	@ 0x3b
    bhi .Lus_08036FF2
    adds	r0, r4, #0
    bl func_08035AE0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08036FF2
    adds	r0, r4, #0
    adds	r0, #72	@ 0x48
    ldrh	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lus_08036FAC
    subs	r0, r1, #1
    b .Lus_08036FF0
.Lus_08036FA8:
    .4byte 0x00001CD4
.Lus_08036FAC:
    mov	r1, sp
    ldr r0, .Lus_08036FC8
    ldmia	r0!, {r2, r3, r7}
    stmia	r1!, {r2, r3, r7}
    ldr	r0, [r0, #0]
    str	r0, [r1, #0]
    bl rand
    movs	r1, #100	@ 0x64
    bl __modsi3
    movs	r3, #0
    mov	r2, sp
    b .Lus_08036FD2
.Lus_08036FC8:
    .4byte gUnk_080F1514
.Lus_08036FCC:
    subs	r0, r0, r1
    adds	r2, #4
    adds	r3, #1
.Lus_08036FD2:
    cmp	r3, #3
    bhi .Lus_08036FE4
    ldrb	r1, [r2, #0]
    cmp	r0, r1
    bcs .Lus_08036FCC
    ldrh	r1, [r2, #2]
    adds	r0, r4, #0
    bl func_08035908
.Lus_08036FE4:
    bl rand
    movs	r1, #120	@ 0x78
    bl __modsi3
    adds	r0, #120	@ 0x78
.Lus_08036FF0:
    strh	r0, [r5, #0]
.Lus_08036FF2:
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_08034EB4
    add	sp, #16
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x47706B40
    .global func_08037008
    .thumb_func
func_08037008:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r4, r0, #0
    adds	r5, r2, #0
    ldr	r6, [sp, #20]
    str	r3, [sp, #0]
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lus_08037044
    str	r0, [r4, #20]
    str	r5, [r4, #48]	@ 0x30
    adds	r1, r4, #0
    adds	r1, #52	@ 0x34
    movs	r0, #0
    strh	r0, [r4, #52]	@ 0x34
    strh	r0, [r1, #2]
    strh	r0, [r1, #4]
    strh	r0, [r1, #6]
    strh	r6, [r4, #60]	@ 0x3c
    strh	r0, [r4, #62]	@ 0x3e
    adds	r1, #12
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037044:
    .4byte vtable_unk_080E7328
    .global func_08037048
    .thumb_func
func_08037048:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lus_08037090
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldr r0, .Lus_08037094
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_0803707A
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_0803707A:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lus_08037088
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_08037088:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Lus_08037090:
    .4byte vtable_unk_080E7328
.Lus_08037094:
    .4byte __vt_7AEntity
    .global func_08037098
    .thumb_func
func_08037098:
    push	{r4, r5, lr}
    adds	r3, r0, #0
    movs	r4, #0
    movs	r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r0, #0
    cmp	r0, #1
    beq .Lus_080370C2
    cmp	r0, #1
    bgt .Lus_080370B4
    cmp	r0, #0
    beq .Lus_080370BE
    b .Lus_080370CC
.Lus_080370B4:
    cmp	r2, #2
    beq .Lus_080370C6
    cmp	r2, #3
    beq .Lus_080370CA
    b .Lus_080370CC
.Lus_080370BE:
    adds	r5, r1, #0
    b .Lus_080370CC
.Lus_080370C2:
    negs	r5, r1
    b .Lus_080370CC
.Lus_080370C6:
    negs	r4, r1
    b .Lus_080370CC
.Lus_080370CA:
    adds	r4, r1, #0
.Lus_080370CC:
    str	r4, [r3, #24]
    str	r5, [r3, #28]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_0803710E
    movs	r4, #0
    adds	r2, r0, #0
    adds	r2, #48	@ 0x30
    movs	r1, #0
    ldrh	r0, [r2, #14]
    cmp	r0, #0
    beq .Lus_080370F8
    movs	r0, #16
    ldrsh	r1, [r2, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r1, r0, #31
.Lus_080370F8:
    cmp	r1, #0
    beq .Lus_08037108
    adds	r0, r2, #0
    bl func_0805E894
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803710A
.Lus_08037108:
    movs	r4, #1
.Lus_0803710A:
    adds	r0, r4, #0
    b .Lus_08037110
.Lus_0803710E:
    movs	r0, #1
.Lus_08037110:
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037118
    .thumb_func
func_08037118:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r7, r0, #0
    adds	r4, r1, #0
    ldr	r1, [r7, #8]
    ldr	r2, [r7, #12]
    ldr	r0, [r7, #24]
    adds	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r7, #28]
    adds	r0, r0, r2
    mov	r8, r0
    asrs	r1, r1, #16
    str	r1, [sp, #0]
    asrs	r6, r2, #16
    asrs	r0, r0, #16
    subs	r5, r0, r6
    mov	r1, r9
    asrs	r0, r1, #16
    ldr	r1, [sp, #0]
    subs	r1, r0, r1
    mov	sl, r1
    cmp	r5, #0
    ble .Lus_08037182
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lus_08037162
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Lus_08037164
.Lus_08037162:
    adds	r0, r1, #0
.Lus_08037164:
    cmp	r5, r0
    ble .Lus_08037182
    ldr	r1, [r4, #0]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lus_0803717A
    adds	r0, r4, #0
    bl func_080AB85C
    ldr	r0, [r4, #0]
    b .Lus_0803717C
.Lus_0803717A:
    adds	r0, r1, #0
.Lus_0803717C:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Lus_08037182:
    cmp	r5, #0
    bge .Lus_080371B8
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lus_08037198
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Lus_0803719A
.Lus_08037198:
    adds	r0, r1, #0
.Lus_0803719A:
    cmp	r5, r0
    bge .Lus_080371B8
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lus_080371B0
    adds	r0, r4, #0
    bl func_080AB8D0
    ldr	r0, [r4, #4]
    b .Lus_080371B2
.Lus_080371B0:
    adds	r0, r1, #0
.Lus_080371B2:
    adds	r0, r6, r0
    lsls	r0, r0, #16
    mov	r8, r0
.Lus_080371B8:
    mov	r0, sl
    cmp	r0, #0
    bge .Lus_080371F2
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lus_080371D0
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Lus_080371D2
.Lus_080371D0:
    adds	r0, r1, #0
.Lus_080371D2:
    cmp	sl, r0
    bge .Lus_080371F2
    ldr	r1, [r4, #8]
    ldr	r0, [r4, #40]	@ 0x28
    cmn	r1, r0
    bge .Lus_080371E8
    adds	r0, r4, #0
    bl func_080AB948
    ldr	r0, [r4, #8]
    b .Lus_080371EA
.Lus_080371E8:
    adds	r0, r1, #0
.Lus_080371EA:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Lus_080371F2:
    mov	r0, sl
    cmp	r0, #0
    ble .Lus_0803722C
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lus_0803720A
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Lus_0803720C
.Lus_0803720A:
    adds	r0, r1, #0
.Lus_0803720C:
    cmp	sl, r0
    ble .Lus_0803722C
    ldr	r1, [r4, #12]
    ldr	r0, [r4, #40]	@ 0x28
    cmp	r1, r0
    ble .Lus_08037222
    adds	r0, r4, #0
    bl func_080AB9C4
    ldr	r0, [r4, #12]
    b .Lus_08037224
.Lus_08037222:
    adds	r0, r1, #0
.Lus_08037224:
    ldr	r1, [sp, #0]
    adds	r0, r1, r0
    lsls	r0, r0, #16
    mov	r9, r0
.Lus_0803722C:
    mov	r0, r9
    str	r0, [r7, #8]
    mov	r1, r8
    str	r1, [r7, #12]
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037244
    .thumb_func
func_08037244:
    ldr	r2, [r1, #4]
    ldr	r1, [r1, #0]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    bx	lr
    .align 2, 0
    sub	sp, #8
    mov	r3, sp
    movs	r1, #0
    mov	r2, sp
    strh	r1, [r2, #0]
    strh	r1, [r3, #2]
    strh	r1, [r3, #4]
    strh	r1, [r3, #6]
    ldr	r1, [sp, #0]
    ldr	r2, [sp, #4]
    str	r1, [r0, #52]	@ 0x34
    str	r2, [r0, #56]	@ 0x38
    add	sp, #8
    bx	lr
    .global func_0803726C
    .thumb_func
func_0803726C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #96	@ 0x60
    adds	r7, r0, #0
    ldr	r4, [r7, #0]
    ldrh	r0, [r7, #4]
    mov	r8, r0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #20]
    adds	r0, r4, #0
    bl _call_via_r1
    cmp	r0, r8
    beq .Lus_0803728E
    b .Lus_08037402
.Lus_0803728E:
    ldr	r1, [r4, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r4, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #64	@ 0x40
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    str	r1, [sp, #88]	@ 0x58
    str	r2, [sp, #92]	@ 0x5c
    add	r4, sp, #12
    movs	r2, #32
    mov	r9, r2
    movs	r5, #0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #88]	@ 0x58
    ldr	r1, [sp, #92]	@ 0x5c
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r1, r9
    str	r1, [r4, #40]	@ 0x28
    str	r5, [r4, #44]	@ 0x2c
    str	r5, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r9, r4
    cmp	r3, #0
    beq .Lus_08037310
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Lus_08037310
    ldr	r1, [r3, #20]
    add	r4, sp, #72	@ 0x48
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lus_08037310:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lus_08037340
    ldrh	r0, [r3, #4]
    cmp	r0, r8
    bne .Lus_08037340
    ldr	r1, [r3, #20]
    add	r4, sp, #80	@ 0x50
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r9
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lus_08037340:
    adds	r2, r7, #0
    adds	r2, #52	@ 0x34
    movs	r3, #4
    ldrsh	r0, [r2, r3]
    movs	r6, #52	@ 0x34
    ldrsh	r1, [r7, r6]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Lus_0803736A
    movs	r1, #6
    ldrsh	r0, [r2, r1]
    movs	r3, #2
    ldrsh	r1, [r2, r3]
    subs	r0, r0, r1
    cmp	r0, #0
    ble .Lus_0803736A
    mov	r0, r9
    adds	r1, r2, #0
    movs	r2, #0
    bl func_080ABA90
.Lus_0803736A:
    ldrh	r4, [r7, #62]	@ 0x3e
    cmp	r4, #0
    beq .Lus_080373EC
    ldr	r5, [r7, #24]
    ldr	r6, [r7, #28]
    cmp	r5, #0
    bge .Lus_08037390
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lus_0803738A
    add	r0, sp, #12
    bl func_080AB948
    ldr	r0, [sp, #20]
    b .Lus_0803738C
.Lus_0803738A:
    adds	r0, r1, #0
.Lus_0803738C:
    cmp	r0, #0
    bge .Lus_080373E4
.Lus_08037390:
    cmp	r5, #0
    ble .Lus_080373AC
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lus_080373A6
    add	r0, sp, #12
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Lus_080373A8
.Lus_080373A6:
    adds	r0, r1, #0
.Lus_080373A8:
    cmp	r0, #0
    ble .Lus_080373E4
.Lus_080373AC:
    cmp	r6, #0
    bge .Lus_080373C8
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lus_080373C2
    add	r0, sp, #12
    bl func_080AB8D0
    ldr	r0, [sp, #16]
    b .Lus_080373C4
.Lus_080373C2:
    adds	r0, r1, #0
.Lus_080373C4:
    cmp	r0, #0
    bge .Lus_080373E4
.Lus_080373C8:
    cmp	r6, #0
    ble .Lus_080373E8
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lus_080373DE
    add	r0, sp, #12
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Lus_080373E0
.Lus_080373DE:
    adds	r0, r1, #0
.Lus_080373E0:
    cmp	r0, #0
    bgt .Lus_080373E8
.Lus_080373E4:
    movs	r4, #0
    b .Lus_080373F8
.Lus_080373E8:
    subs	r4, #1
    b .Lus_080373F8
.Lus_080373EC:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #64]	@ 0x40
    adds	r0, r7, #0
    bl _call_via_r1
    adds	r4, r0, #0
.Lus_080373F8:
    strh	r4, [r7, #62]	@ 0x3e
    adds	r0, r7, #0
    mov	r1, r9
    bl func_08037118
.Lus_08037402:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_0803740C
    subs	r0, #1
    b .Lus_0803740E
.Lus_0803740C:
    ldrh	r0, [r7, #38]	@ 0x26
.Lus_0803740E:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Lus_08037420
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lus_08037420:
    add	sp, #96	@ 0x60
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037430
    .thumb_func
func_08037430:
    ldrh	r0, [r0, #60]	@ 0x3c
    bx	lr
    .global func_08037434
    .thumb_func
func_08037434:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #64	@ 0x40
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lus_0803744A
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #60]	@ 0x3c
    adds	r0, r4, #0
    bl _call_via_r1
.Lus_0803744A:
    movs	r0, #0
    strh	r0, [r4, #62]	@ 0x3e
    adds	r0, r4, #0
    bl vfunc_10__7AEntity
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803745C
    .thumb_func
func_0803745C:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    adds	r4, #64	@ 0x40
    movs	r0, #0
    strb	r0, [r4, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037470
    .thumb_func
func_08037470:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #9
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0
    .global func_08037494
    .thumb_func
func_08037494:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lus_080374B8
    movs	r1, #1
.Lus_080374B8:
    lsls	r4, r1, #2
    adds	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Lus_08037538
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #5
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lus_08037508
    cmp	r1, #3
    beq .Lus_08037508
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_08037508
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_08037508:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037628
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_0803752E
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lus_0803752E:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037538:
    .4byte gUnk_080F1538
    .global func_0803753C
    .thumb_func
func_0803753C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #7
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #9
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037568
    .thumb_func
func_08037568:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Lus_08037600
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Lus_080375C2
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lus_080375C2:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #0
    beq .Lus_08037600
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Lus_08037600
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A17A0
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037618
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_0803760A
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Lus_0803760A
.Lus_08037600:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Lus_0803760A:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037618
    .thumb_func
func_08037618:
    ldr r0, .Lus_08037624
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lus_08037624:
    .4byte gUnk_080F1560
    .global func_08037628
    .thumb_func
func_08037628:
    push	{lr}
    cmp	r1, #1
    beq .Lus_08037632
    movs	r0, #0
    b .Lus_08037636
.Lus_08037632:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lus_08037636:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803763C
    .thumb_func
func_0803763C:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r1, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lus_08037660
    movs	r1, #1
.Lus_08037660:
    lsls	r4, r1, #3
    subs	r4, r4, r1
    lsls	r4, r4, #2
    ldr r0, .Lus_080376E0
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #7
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lus_080376B0
    cmp	r1, #3
    beq .Lus_080376B0
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_080376B0
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_080376B0:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377D4
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_080376D6
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lus_080376D6:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080376E0:
    .4byte gUnk_080F156C
    .global func_080376E4
    .thumb_func
func_080376E4:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r1, #2
    str	r1, [sp, #0]
    movs	r1, #12
    str	r1, [sp, #4]
    movs	r2, #0
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #4
    movs	r3, #12
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037714
    .thumb_func
func_08037714:
    push	{r4, r5, lr}
    mov	r5, r8
    push	{r5}
    sub	sp, #8
    adds	r4, r0, #0
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r5, r1, #0
    ldrb	r0, [r1, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    subs	r0, #6
    cmp	r0, #9
    bhi .Lus_080377AC
    ldrb	r2, [r1, #8]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    ldrb	r3, [r1, #9]
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
    adds	r3, r3, r1
    cmp	r3, #6
    bls .Lus_0803776E
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lus_0803776E:
    movs	r0, #7
    ands	r3, r0
    cmp	r3, #1
    beq .Lus_080377AC
    ldr	r0, [r5, #0]
    cmp	r0, #0
    bne .Lus_080377AC
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    ldrb	r1, [r0, #0]
    lsls	r1, r1, #30
    lsrs	r1, r1, #30
    mov	r0, sp
    bl func_080A1890
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080377C4
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_080377B6
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
    b .Lus_080377B6
.Lus_080377AC:
    adds	r0, r4, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
.Lus_080377B6:
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080377C4
    .thumb_func
func_080377C4:
    ldr r0, .Lus_080377D0
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lus_080377D0:
    .4byte gUnk_080F15A4
    .global func_080377D4
    .thumb_func
func_080377D4:
    push	{lr}
    cmp	r1, #1
    beq .Lus_080377DE
    movs	r0, #0
    b .Lus_080377E2
.Lus_080377DE:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lus_080377E2:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080377E8
    .thumb_func
func_080377E8:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrb	r0, [r0, #10]
    lsls	r0, r0, #27
    lsrs	r0, r0, #27
    movs	r4, #0
    subs	r0, #6
    cmp	r0, #14
    bls .Lus_0803780C
    movs	r4, #1
.Lus_0803780C:
    movs	r0, #52	@ 0x34
    muls	r4, r0
    ldr r0, .Lus_08037888
    adds	r4, r4, r0
    adds	r0, r4, #0
    movs	r1, #13
    bl func_080AB82C
    lsls	r1, r0, #2
    adds	r4, r4, r1
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lus_0803785A
    cmp	r1, #3
    beq .Lus_0803785A
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_0803785A
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_0803785A:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378FC
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_08037880
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lus_08037880:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lus_08037888:
    .4byte gUnk_080F15B4
    .global func_0803788C
    .thumb_func
func_0803788C:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_080378B8
    .thumb_func
func_080378B8:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A198C
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_080378EC
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_080378E2
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lus_080378E2:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080378EC
    .thumb_func
func_080378EC:
    ldr r0, .Lus_080378F8
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lus_080378F8:
    .4byte gUnk_080F161C
    .global func_080378FC
    .thumb_func
func_080378FC:
    push	{lr}
    cmp	r1, #12
    bhi .Lus_08037944
    lsls	r0, r1, #2
    ldr r1, .Lus_0803790C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_0803790C:
    .4byte .Lus_08037910
.Lus_08037910:
    .4byte .Lus_08037944
    .4byte .Lus_08037948
    .4byte .Lus_0803794E
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_08037944
    .4byte .Lus_0803794E
    .4byte .Lus_08037944
.Lus_08037944:
    movs	r0, #0
    b .Lus_08037952
.Lus_08037948:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE001
.Lus_0803794E:
    .hword 0x2080
    .hword 0x0240
.Lus_08037952:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037958
    .thumb_func
func_08037958:
    push	{r4, r5, r6, r7, lr}
    adds	r6, r0, #0
    ldr r5, .Lus_080379D4
    adds	r0, r5, #0
    movs	r1, #3
    bl func_080AB82C
    lsls	r4, r0, #2
    adds	r4, r4, r5
    adds	r7, r0, #0
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB788
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r5, r1, r0
    movs	r0, #4
    bl func_080AB788
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lus_080379A4
    cmp	r1, #3
    beq .Lus_080379A4
    adds	r4, r6, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    bl func_080AB7A4
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_080379A4
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_080379A4:
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A48
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08037098
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_080379CA
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lus_080379CA:
    adds	r0, r5, #0
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080379D4:
    .4byte gUnk_080F1638
    .global func_080379D8
    .thumb_func
func_080379D8:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08037A04
    .thumb_func
func_08037A04:
    push	{r4, lr}
    sub	sp, #8
    adds	r4, r0, #0
    mov	r0, sp
    bl func_080A19EC
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r4, #0
    movs	r1, #0
    bl func_08037A38
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_08037A2E
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lus_08037A2E:
    add	sp, #8
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08037A38
    .thumb_func
func_08037A38:
    ldr r0, .Lus_08037A44
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lus_08037A44:
    .4byte gUnk_080F1644
    .global func_08037A48
    .thumb_func
func_08037A48:
    push	{lr}
    cmp	r1, #1
    beq .Lus_08037A52
    movs	r0, #0
    b .Lus_08037A56
.Lus_08037A52:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
.Lus_08037A56:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037A5C
    .thumb_func
func_08037A5C:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    ldr r3, .Lus_08037AC8
    bl func_08037008
    ldr r0, .Lus_08037ACC
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037AC8:
    .4byte 0x0000071C
.Lus_08037ACC:
    .4byte vtable_unk_080E72E4
    .global func_08037AD0
    .thumb_func
func_08037AD0:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #12
    adds	r6, r0, #0
    mov	r8, r1
    adds	r4, r2, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r5, r0, #0
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, r8
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    bl func_08037008
    ldr r0, .Lus_08037B44
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037B44:
    .4byte vtable_unk_080E72A0
    .global func_08037B48
    .thumb_func
func_08037B48:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Lus_08037B78
    bl func_08037008
    ldr r0, .Lus_08037B7C
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037B78:
    .4byte 0x00000379
.Lus_08037B7C:
    .4byte vtable_unk_080E725C
    .global func_08037B80
    .thumb_func
func_08037B80:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r6, r1, #0
    movs	r0, #68	@ 0x44
    bl __builtin_new
    adds	r4, r0, #0
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r6, #0
    ldr r3, .Lus_08037BB0
    bl func_08037008
    ldr r0, .Lus_08037BB4
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08037BB0:
    .4byte 0x00000207
.Lus_08037BB4:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Lus_08037BD8
    movs	r0, #10
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Lus_08037BDC
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08037BD8:
    .4byte 0x00000207
.Lus_08037BDC:
    .4byte vtable_unk_080E7218
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr r3, .Lus_08037C00
    movs	r0, #12
    str	r0, [sp, #0]
    adds	r0, r4, #0
    bl func_08037008
    ldr r0, .Lus_08037C04
    str	r0, [r4, #20]
    adds	r0, r4, #0
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08037C00:
    .4byte 0x00000379
.Lus_08037C04:
    .4byte vtable_unk_080E725C
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    movs	r3, #171	@ 0xab
    lsls	r3, r3, #2
    movs	r0, #11
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Lus_08037C64
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r3, sp, #4
    movs	r1, #230	@ 0xe6
    lsls	r1, r1, #2
    movs	r2, #144	@ 0x90
    lsls	r2, r2, #1
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    movs	r0, #164	@ 0xa4
    lsls	r0, r0, #1
    adds	r1, r1, r0
    strh	r1, [r3, #4]
    adds	r2, #8
    strh	r2, [r3, #6]
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lus_08037C64:
    .4byte vtable_unk_080E72A0
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    adds	r4, r3, #0
    ldr r3, .Lus_08037CBC
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r5, #0
    bl func_08037008
    ldr r0, .Lus_08037CC0
    str	r0, [r5, #20]
    adds	r2, r5, #0
    adds	r2, #68	@ 0x44
    movs	r0, #3
    ands	r4, r0
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r4
    strb	r0, [r2, #0]
    add	r2, sp, #4
    movs	r1, #176	@ 0xb0
    lsls	r1, r1, #1
    movs	r3, #216	@ 0xd8
    adds	r0, r2, #0
    strh	r1, [r0, #0]
    strh	r3, [r2, #2]
    adds	r1, #56	@ 0x38
    strh	r1, [r2, #4]
    movs	r0, #232	@ 0xe8
    strh	r0, [r2, #6]
    adds	r0, r5, #0
    adds	r1, r2, #0
    bl func_08037244
    adds	r0, r5, #0
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lus_08037CBC:
    .4byte 0x0000071C
.Lus_08037CC0:
    .4byte vtable_unk_080E72E4
    .global func_08037CC4
    .thumb_func
func_08037CC4:
    push	{r4, lr}
    adds	r4, r0, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lus_08037CD8
    str	r0, [r4, #20]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_08037CD8:
    .4byte vtable_unk_080E7444
    .global func_08037CDC
    .thumb_func
func_08037CDC:
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r3, #14
    ldrsh	r1, [r1, r3]
    strh	r2, [r0, #0]
    adds	r1, #1
    strh	r1, [r0, #2]
    strh	r2, [r0, #4]
    strh	r1, [r0, #6]
    bx	lr
    .global func_08037CF0
    .thumb_func
func_08037CF0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037D08
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037D08
    .thumb_func
func_08037D08:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Lus_08037D68
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #10
    bl func_080A4740
    ldr r0, .Lus_08037D6C
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #125	@ 0x7d
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lus_08037D68:
    .4byte vtable_unk_080E7478
.Lus_08037D6C:
    .4byte vtable_unk_080E602C
    .global func_08037D70
    .thumb_func
func_08037D70:
    bx	lr
    .align 2, 0
    .global func_08037D74
    .thumb_func
func_08037D74:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r2, [r3, r0]
    movs	r3, #14
    ldrsh	r0, [r1, r3]
    subs	r0, r2, r0
    mov	ip, r0
    ldr	r0, [r1, #0]
    ldr	r3, [r1, #8]
    str	r0, [sp, #20]
    str	r3, [sp, #24]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r2
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r2, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08037DE0
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r8
    mov	r2, ip
    movs	r3, #170	@ 0xaa
    ldr r4, .Lus_08037DDC
    bl _call_via_r4
    b .Lus_08037DE2
    .align 2, 0
.Lus_08037DDC:
    .4byte func_030004DC
.Lus_08037DE0:
    movs	r0, #0
.Lus_08037DE2:
    cmp	r0, #0
    beq .Lus_08037E0C
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_08037E0C
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_08037E0C:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08037E18
    .thumb_func
func_08037E18:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    mov	r0, sp
    adds	r1, r6, #0
    bl func_0800FFE0
    adds	r0, r4, #0
    adds	r1, r5, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lus_08037E44
    str	r0, [r4, #20]
    str	r6, [r4, #24]
    adds	r0, r4, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lus_08037E44:
    .4byte vtable_unk_080E73FC
    .global func_08037E48
    .thumb_func
func_08037E48:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lus_08037E94
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl func_08010014
    ldr r0, .Lus_08037E98
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_08037E7C
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_08037E7C:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lus_08037E8A
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_08037E8A:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08037E94:
    .4byte vtable_unk_080E73FC
.Lus_08037E98:
    .4byte __vt_7AEntity
    .global func_08037E9C
    .thumb_func
func_08037E9C:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #88	@ 0x58
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08037EF0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08037EB4
    .thumb_func
func_08037EB4:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r0, [r4, #24]
    ldrb	r1, [r1, #0]
    bl func_0800FFF4
    ldr	r0, [r4, #16]
    cmp	r0, #0
    beq .Lus_08037ECA
    bl func_08037F74
.Lus_08037ECA:
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08037ED0
    .thumb_func
func_08037ED0:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #5
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_08037EF0
    .thumb_func
func_08037EF0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r4, [r7, #0]
    ldr r0, .Lus_08037F58
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r5, r0, #0
    ldr	r1, [r4, #0]
    adds	r4, r7, #0
    adds	r4, #8
    adds	r0, r4, #0
    movs	r2, #2
    movs	r3, #8
    bl func_080A4740
    ldr r0, .Lus_08037F5C
    str	r0, [r4, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #48	@ 0x30
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #53	@ 0x35
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r7, #0
    adds	r0, #84	@ 0x54
    strb	r2, [r0, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Lus_08037F58:
    .4byte vtable_unk_080E7430
.Lus_08037F5C:
    .4byte vtable_unk_080E602C
    .global func_08037F60
    .thumb_func
func_08037F60:
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #84	@ 0x54
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    beq .Lus_08037F70
    subs	r0, #1
    strb	r0, [r1, #0]
.Lus_08037F70:
    pop	{r0}
    bx	r0
    .global func_08037F74
    .thumb_func
func_08037F74:
    adds	r0, #84	@ 0x54
    movs	r1, #10
    strb	r1, [r0, #0]
    bx	lr
    .global func_08037F7C
    .thumb_func
func_08037F7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #28
    adds	r4, r0, #0
    ldr	r3, [r4, #0]
    movs	r0, #10
    ldrsh	r2, [r3, r0]
    movs	r5, #12
    ldrsh	r0, [r1, r5]
    subs	r2, r2, r0
    mov	r8, r2
    movs	r0, #14
    ldrsh	r3, [r3, r0]
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    subs	r2, r3, r0
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    mov	ip, r1
    str	r0, [sp, #20]
    str	r1, [sp, #24]
    adds	r0, r4, #0
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08037FB4
    subs	r2, #2
.Lus_08037FB4:
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r7, r0, r3
    adds	r5, r4, #0
    adds	r5, #8
    adds	r6, r4, #0
    adds	r6, #48	@ 0x30
    ldr	r3, [r4, #8]
    ldr	r1, [r4, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08037FF0
    ldrh	r0, [r5, #12]
    adds	r1, r4, #0
    adds	r1, #24
    str	r7, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    mov	r1, r8
    movs	r3, #170	@ 0xaa
    ldr r4, .Lus_08037FEC
    bl _call_via_r4
    b .Lus_08037FF2
.Lus_08037FEC:
    .4byte func_030004DC
.Lus_08037FF0:
    movs	r0, #0
.Lus_08037FF2:
    cmp	r0, #0
    beq .Lus_0803801C
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_0803801C
    ldr	r1, [sp, #20]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_0803801C:
    add	sp, #28
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038028
    .thumb_func
func_08038028:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r6, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lus_08038094
    str	r0, [r6, #20]
    str	r4, [r6, #24]
    movs	r0, #0
    str	r0, [r6, #28]
    adds	r1, r6, #0
    adds	r1, #37	@ 0x25
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    movs	r0, #49	@ 0x31
    strh	r0, [r6, #40]	@ 0x28
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_08038088
    ldrh	r0, [r4, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Lus_08038088
    adds	r0, r4, #0
    bl func_08020460
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08038088
    ldr	r1, [r4, #8]
    ldr	r2, [r4, #12]
    ldrh	r3, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r6, #0
    bl func_08038374
.Lus_08038088:
    adds	r0, r6, #0
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08038094:
    .4byte vtable_unk_080E73B4
    .global func_08038098
    .thumb_func
func_08038098:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lus_080380E4
    str	r0, [r5, #20]
    ldr	r4, [r5, #24]
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C7AEntity
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    ldr r0, .Lus_080380E8
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_080380CE
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_080380CE:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lus_080380DC
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_080380DC:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
.Lus_080380E4:
    .4byte vtable_unk_080E73B4
.Lus_080380E8:
    .4byte __vt_7AEntity
    .global func_080380EC
    .thumb_func
func_080380EC:
    adds	r2, r0, #0
    adds	r2, #36	@ 0x24
    strb	r1, [r2, #0]
    movs	r1, #168	@ 0xa8
    lsls	r1, r1, #13
    str	r1, [r0, #28]
    movs	r1, #192	@ 0xc0
    lsls	r1, r1, #10
    str	r1, [r0, #32]
    adds	r0, #37	@ 0x25
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038108
    .thumb_func
func_08038108:
    adds	r0, #37	@ 0x25
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    .global func_08038110
    .thumb_func
func_08038110:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #68	@ 0x44
    adds	r6, r0, #0
    adds	r4, r6, #0
    adds	r4, #37	@ 0x25
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_08038126
    b .Lus_080382F4
.Lus_08038126:
    ldr	r7, [r6, #0]
    ldrh	r2, [r6, #4]
    ldr	r1, [r7, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    adds	r1, r7, #0
    bl _call_via_r3
    mov	r8, sp
    ldr	r1, [r6, #32]
    ldr r0, .Lus_080381A0
    adds	r1, r1, r0
    str	r1, [r6, #32]
    ldr	r0, [r6, #28]
    adds	r0, r0, r1
    str	r0, [r6, #28]
    cmp	r0, #0
    bgt .Lus_0803814C
    b .Lus_0803825C
.Lus_0803814C:
    ldr	r1, [r6, #20]
    add	r0, sp, #52	@ 0x34
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    ldr	r1, [sp, #52]	@ 0x34
    ldr	r2, [sp, #56]	@ 0x38
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    add	r5, sp, #12
    movs	r2, #32
    mov	r8, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r5, #4]
    str	r0, [r5, #8]
    str	r1, [r5, #12]
    add	r1, sp, #28
    mov	r0, sp
    ldmia	r0!, {r2, r3, r4}
    stmia	r1!, {r2, r3, r4}
    ldr	r3, [sp, #60]	@ 0x3c
    ldr	r4, [sp, #64]	@ 0x40
    str	r3, [sp, #40]	@ 0x28
    str	r4, [sp, #44]	@ 0x2c
    mov	r4, r8
    str	r4, [r5, #36]	@ 0x24
    ldr	r4, [r6, #8]
    ldr	r7, [r6, #12]
    adds	r0, r6, #0
    adds	r0, #36	@ 0x24
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lus_080381AE
    cmp	r0, #1
    bgt .Lus_080381A4
    cmp	r0, #0
    beq .Lus_080381D4
    b .Lus_08038250
.Lus_080381A0:
    .4byte 0xFFFFB85D
.Lus_080381A4:
    cmp	r0, #2
    beq .Lus_08038230
    cmp	r0, #3
    beq .Lus_08038204
    b .Lus_08038250
.Lus_080381AE:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Lus_080381C0
    adds	r0, r5, #0
    bl func_080ABBC4
    ldr	r0, [sp, #16]
    b .Lus_080381C2
.Lus_080381C0:
    adds	r0, r1, #0
.Lus_080381C2:
    lsls	r1, r0, #16
    ldr r0, .Lus_080381D0
    cmp	r1, r0
    bgt .Lus_080381F0
    ldr r5, .Lus_080381D0
    adds	r7, r7, r5
    b .Lus_08038250
.Lus_080381D0:
    .4byte 0xFFFE38E4
.Lus_080381D4:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Lus_080381E6
    adds	r0, r5, #0
    bl func_080ABBA0
    ldr	r0, [sp, #12]
    b .Lus_080381E8
.Lus_080381E6:
    adds	r0, r1, #0
.Lus_080381E8:
    lsls	r1, r0, #16
    ldr r0, .Lus_080381F4
    cmp	r1, r0
    bgt .Lus_080381F8
.Lus_080381F0:
    adds	r7, r7, r1
    b .Lus_08038250
.Lus_080381F4:
    .4byte 0x0001C71B
.Lus_080381F8:
    ldr r0, .Lus_08038200
    adds	r7, r7, r0
    b .Lus_08038250
    .align 2, 0
.Lus_08038200:
    .4byte 0x0001C71C
.Lus_08038204:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r1, r0
    ble .Lus_08038216
    adds	r0, r5, #0
    bl func_080ABC14
    ldr	r0, [sp, #24]
    b .Lus_08038218
.Lus_08038216:
    adds	r0, r1, #0
.Lus_08038218:
    lsls	r1, r0, #16
    ldr r0, .Lus_08038228
    cmp	r1, r0
    ble .Lus_08038222
    ldr r1, .Lus_0803822C
.Lus_08038222:
    adds	r4, r4, r1
    b .Lus_08038250
    .align 2, 0
.Lus_08038228:
    .4byte 0x0001C71B
.Lus_0803822C:
    .4byte 0x0001C71C
.Lus_08038230:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #48]	@ 0x30
    cmn	r1, r0
    bge .Lus_08038242
    adds	r0, r5, #0
    bl func_080ABBEC
    ldr	r0, [sp, #20]
    b .Lus_08038244
.Lus_08038242:
    adds	r0, r1, #0
.Lus_08038244:
    lsls	r1, r0, #16
    ldr r0, .Lus_08038258
    cmp	r1, r0
    bgt .Lus_08038222
    ldr r2, .Lus_08038258
    adds	r4, r4, r2
.Lus_08038250:
    str	r4, [r6, #8]
    str	r7, [r6, #12]
    b .Lus_080382F4
    .align 2, 0
.Lus_08038258:
    .4byte 0xFFFE38E4
.Lus_0803825C:
    movs	r0, #0
    str	r0, [r6, #28]
    strb	r0, [r4, #0]
    add	r4, sp, #12
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #24]
    adds	r1, r4, #0
    movs	r2, #6
    bl memcpy
    ldr	r0, [r6, #8]
    ldr	r1, [r6, #12]
    asrs	r0, r0, #19
    mov	ip, r0
    asrs	r3, r1, #19
    ldr	r1, [sp, #0]
    mov	r5, r8
    ldrh	r0, [r5, #8]
    cmp	r1, #0
    beq .Lus_080382A8
    cmp	ip, r0
    bhi .Lus_080382A8
    ldrh	r2, [r5, #10]
    cmp	r3, r2
    bhi .Lus_080382A8
    ldr	r2, [sp, #4]
    muls	r0, r3
    add	r0, ip
    cmp	r2, #0
    beq .Lus_080382A2
    adds	r0, r2, r0
    ldrb	r0, [r0, #0]
.Lus_080382A2:
    lsls	r0, r0, #2
    adds	r0, r1, r0
    b .Lus_080382AA
.Lus_080382A8:
    movs	r0, #0
.Lus_080382AA:
    cmp	r0, #0
    bne .Lus_080382C2
    ldr	r0, [r7, #0]
    movs	r3, #158	@ 0x9e
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #1
    bl _call_via_r2
    b .Lus_080382F4
.Lus_080382C2:
    ldr	r0, [r0, #0]
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_080382DE
    ldr	r0, [r7, #0]
    movs	r4, #158	@ 0x9e
    lsls	r4, r4, #1
    adds	r0, r0, r4
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
    bl _call_via_r2
    b .Lus_080382F4
.Lus_080382DE:
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #43	@ 0x2b
    bl _call_via_r2
    cmp	r0, #0
    beq .Lus_080382F4
    adds	r1, r4, #0
    bl func_0802151C
.Lus_080382F4:
    add	sp, #68	@ 0x44
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038300
    .thumb_func
func_08038300:
    push	{r4, lr}
    adds	r4, r0, #0
    ldr	r2, [r4, #16]
    cmp	r2, #0
    beq .Lus_08038314
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lus_08038314:
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038320
    .thumb_func
func_08038320:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_2C__7AEntityUi
    adds	r0, r4, #0
    bl func_08038110
    pop	{r4}
    pop	{r0}
    bx	r0
    .global func_08038334
    .thumb_func
func_08038334:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #72	@ 0x48
    bl __builtin_new
    adds	r1, r4, #0
    bl func_0803853C
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803834C
    .thumb_func
func_0803834C:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #4
    strh	r1, [r0, #0]
    subs	r1, r3, #4
    strh	r1, [r0, #2]
    adds	r2, #4
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .global func_0803836C
    .thumb_func
func_0803836C:
    movs	r1, #30
    ldrsh	r0, [r0, r1]
    bx	lr
    .align 2, 0
    .global func_08038374
    .thumb_func
func_08038374:
    push	{r4, r5, r6, lr}
    ldr	r5, [sp, #16]
    movs	r4, #38	@ 0x26
    adds	r4, r4, r0
    mov	ip, r4
    movs	r4, #1
    mov	r6, ip
    strb	r4, [r6, #0]
    str	r1, [r0, #8]
    str	r2, [r0, #12]
    adds	r1, r3, #0
    adds	r2, r5, #0
    bl func_08038398
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038398
    .thumb_func
func_08038398:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    movs	r3, #21
    ldr r4, .Lus_080383B4
    adds	r0, r1, r4
    cmp	r0, #61	@ 0x3d
    bls .Lus_080383A8
    b .Lus_080384CA
.Lus_080383A8:
    lsls	r0, r0, #2
    ldr r1, .Lus_080383B8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_080383B4:
    .4byte 0xFFFFFCC8
.Lus_080383B8:
    .4byte .Lus_080383BC
.Lus_080383BC:
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384B4
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384B8
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384BC
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384C0
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384C4
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384CA
    .4byte .Lus_080384C8
.Lus_080384B4:
    .4byte 0xE0082319
.Lus_080384B8:
    .4byte 0xE006231D
.Lus_080384BC:
    .4byte 0xE0042321
.Lus_080384C0:
    .4byte 0xE0022325
.Lus_080384C4:
    .4byte 0xE0002329
.Lus_080384C8:
    .hword 0x232D
.Lus_080384CA:
    adds	r1, r3, r2
    adds	r6, r1, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r1, r0
    beq .Lus_080384F6
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Lus_080384F4
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Lus_080384F4:
    strh	r6, [r5, #40]	@ 0x28
.Lus_080384F6:
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_080384FC
    .thumb_func
func_080384FC:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    ldrh	r0, [r5, #40]	@ 0x28
    cmp	r0, #49	@ 0x31
    beq .Lus_0803852C
    ldr	r4, [r5, #16]
    cmp	r4, #0
    beq .Lus_08038528
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    movs	r1, #49	@ 0x31
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
.Lus_08038528:
    movs	r0, #49	@ 0x31
    strh	r0, [r5, #40]	@ 0x28
.Lus_0803852C:
    adds	r1, r5, #0
    adds	r1, #38	@ 0x26
    movs	r0, #0
    strb	r0, [r1, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_0803853C
    .thumb_func
func_0803853C:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r6, r0, #0
    adds	r4, r1, #0
    str	r4, [r6, #0]
    ldr r0, .Lus_0803857C
    str	r0, [r6, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #100]	@ 0x64
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r6, #0
    adds	r0, #8
    ldrh	r2, [r4, #40]	@ 0x28
    movs	r4, #2
    str	r4, [sp, #0]
    movs	r4, #7
    str	r4, [sp, #4]
    add	r5, sp, #8
    movs	r4, #0
    strb	r4, [r5, #0]
    bl func_080A4A00
    adds	r0, r6, #0
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803857C:
    .4byte vtable_unk_080E73E8
    .global func_08038580
    .thumb_func
func_08038580:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_080385A4
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_080385A8
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lus_080385A6
.Lus_080385A4:
    movs	r0, #0
.Lus_080385A6:
    strb	r0, [r1, #0]
.Lus_080385A8:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_080385B0
    .thumb_func
func_080385B0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r5, r0, #0
    mov	sl, r1
    ldr	r0, [r5, #0]
    mov	r9, r0
    movs	r1, #10
    ldrsh	r6, [r0, r1]
    mov	r2, sl
    movs	r3, #12
    ldrsh	r0, [r2, r3]
    subs	r0, r6, r0
    str	r0, [sp, #60]	@ 0x3c
    mov	r0, r9
    movs	r1, #14
    ldrsh	r4, [r0, r1]
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    subs	r0, r4, r0
    str	r0, [sp, #64]	@ 0x40
    mov	r0, r9
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r4
    mov	r8, r0
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    beq .Lus_080385FC
    movs	r1, #1
    negs	r1, r1
    add	r8, r1
.Lus_080385FC:
    add	r0, sp, #52	@ 0x34
    mov	r2, sl
    ldr	r1, [r2, #0]
    ldr	r2, [r2, #8]
    str	r1, [sp, #52]	@ 0x34
    str	r2, [r0, #4]
    ldr	r3, [sp, #64]	@ 0x40
    str	r3, [sp, #72]	@ 0x48
    movs	r7, #2
    ldr	r0, [sp, #68]	@ 0x44
    cmp	r0, #0
    bne .Lus_08038646
    mov	r0, r9
    bl func_0803836C
    ldr	r1, [sp, #64]	@ 0x40
    subs	r1, r1, r0
    str	r1, [sp, #72]	@ 0x48
    cmp	r0, #15
    ble .Lus_08038646
    mov	r2, r9
    ldrh	r0, [r2, #4]
    cmp	r0, #8
    bgt .Lus_08038644
    cmp	r0, #2
    bne .Lus_08038646
    ldr r3, .Lus_080386AC
    adds	r1, r6, r3
    ldr r0, .Lus_080386B0
    cmp	r1, r0
    bhi .Lus_08038646
    cmp	r4, #175	@ 0xaf
    ble .Lus_08038646
    subs	r0, #96	@ 0x60
    cmp	r4, r0
    bgt .Lus_08038646
.Lus_08038644:
    movs	r7, #1
.Lus_08038646:
    adds	r6, r5, #0
    adds	r6, #8
    mov	r0, sp
    adds	r0, #52	@ 0x34
    str	r0, [sp, #76]	@ 0x4c
    adds	r0, r7, #0
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    ldr	r1, [r5, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r5, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r1, [sp, #76]	@ 0x4c
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #8]
    ldr	r1, [r5, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_080386B8
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #24
    mov	r5, r8
    str	r5, [sp, #0]
    adds	r5, r7, #0
    str	r5, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #72]	@ 0x48
    adds	r3, r4, #0
    ldr r4, .Lus_080386B4
    bl _call_via_r4
    b .Lus_080386BA
    .align 2, 0
.Lus_080386AC:
    .4byte 0xFFFFFEF0
.Lus_080386B0:
    .4byte 0x000002AF
.Lus_080386B4:
    .4byte func_030004DC
.Lus_080386B8:
    movs	r0, #0
.Lus_080386BA:
    cmp	r0, #0
    beq .Lus_0803870E
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lus_0803870E
    ldr	r0, [sp, #76]	@ 0x4c
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_080386F0
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_0803870A
.Lus_080386F0:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_0803870A
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_0803870A:
    movs	r0, #0
    strb	r0, [r5, #0]
.Lus_0803870E:
    ldr	r1, [sp, #68]	@ 0x44
    cmp	r1, #0
    bne .Lus_08038730
    mov	r2, r9
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #88]	@ 0x58
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    ldr	r5, [sp, #68]	@ 0x44
    str	r5, [sp, #0]
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r3, [sp, #64]	@ 0x40
    bl func_0803AE58
.Lus_08038730:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038740
    .thumb_func
func_08038740:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r2
    mov	r2, sp
    movs	r5, #8
    ldrh	r3, [r2, #0]
    ldr r4, .Lus_08038798
    adds	r0, r4, #0
    ands	r0, r3
    orrs	r0, r5
    strh	r0, [r2, #0]
    ldrb	r5, [r2, #1]
    movs	r3, #3
    adds	r0, r3, #0
    ands	r0, r5
    strb	r0, [r2, #1]
    ldrh	r5, [r2, #2]
    adds	r0, r4, #0
    ands	r0, r5
    strh	r0, [r2, #2]
    ldrb	r0, [r2, #3]
    ands	r3, r0
    strb	r3, [r2, #3]
    ldrh	r0, [r2, #4]
    ands	r4, r0
    strh	r4, [r2, #4]
    adds	r0, r6, #0
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lus_0803879C
    str	r0, [r6, #20]
    mov	r0, r8
    str	r0, [r6, #24]
    adds	r0, r6, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08038798:
    .4byte 0xFFFFFC00
.Lus_0803879C:
    .4byte vtable_unk_080E7380
    .global func_080387A0
    .thumb_func
func_080387A0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #24
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08038820
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080387B8
    .thumb_func
func_080387B8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_080387C4
    bl func_08038DF0
.Lus_080387C4:
    pop	{r0}
    bx	r0
    .global func_080387C8
    .thumb_func
func_080387C8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_080387D4
    bl func_08038E90
.Lus_080387D4:
    pop	{r0}
    bx	r0
    .global func_080387D8
    .thumb_func
func_080387D8:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Lus_080387E4
    movs	r0, #1
    b .Lus_080387E8
.Lus_080387E4:
    bl func_08038EA0
.Lus_080387E8:
    pop	{r1}
    bx	r1
    .global func_080387EC
    .thumb_func
func_080387EC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_080387F8
    bl func_08038EB8
.Lus_080387F8:
    pop	{r0}
    bx	r0
    .global func_080387FC
    .thumb_func
func_080387FC:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_08038808
    bl func_08038EE0
.Lus_08038808:
    pop	{r0}
    bx	r0
    .global func_0803880C
    .thumb_func
func_0803880C:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    bne .Lus_08038818
    movs	r0, #0
    b .Lus_0803881C
.Lus_08038818:
    bl func_080390D0
.Lus_0803881C:
    pop	{r1}
    bx	r1
    .global func_08038820
    .thumb_func
func_08038820:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    str	r1, [r7, #0]
    ldr r0, .Lus_0803889C
    str	r0, [r7, #4]
    ldr	r0, [r1, #24]
    adds	r0, #84	@ 0x54
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    mov	sl, r0
    cmp	r0, #1
    bne .Lus_080388A4
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r6, r0, #0
    mov	r0, r9
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #116]	@ 0x74
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Lus_080388A0
    str	r0, [r6, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r6
    mov	r8, r1
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r0, r6, #0
    adds	r0, #72	@ 0x48
    mov	r5, sl
    strb	r5, [r0, #0]
    b .Lus_080388A6
    .align 2, 0
.Lus_0803889C:
    .4byte vtable_unk_080E736C
.Lus_080388A0:
    .4byte vtable_unk_080E602C
.Lus_080388A4:
    movs	r6, #0
.Lus_080388A6:
    str	r6, [r7, #8]
    movs	r0, #0
    str	r0, [r7, #12]
    str	r0, [r7, #16]
    adds	r4, r7, #0
    adds	r4, #20
    str	r0, [r7, #20]
    movs	r0, #202	@ 0xca
    lsls	r0, r0, #1
    bl __builtin_new
    adds	r3, r0, #0
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    movs	r2, #0
    mov	r5, r9
    ldr	r0, [r5, #24]
    adds	r0, #93	@ 0x5d
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_080388D6
    movs	r2, #1
.Lus_080388D6:
    adds	r0, r3, #0
    bl func_080DCB7C
    mov	r9, r4
    mov	r8, r0
    ldr	r6, [r7, #20]
    cmp	r8, r6
    beq .Lus_08038910
    cmp	r6, #0
    beq .Lus_08038910
    ldr	r1, [r6, #0]
    lsls	r0, r1, #2
    adds	r0, r0, r1
    lsls	r0, r0, #4
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Lus_0803890A
.Lus_080388FC:
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r4, #80	@ 0x50
    cmp	r4, r5
    bne .Lus_080388FC
.Lus_0803890A:
    adds	r0, r6, #0
    bl __builtin_delete
.Lus_08038910:
    mov	r0, r8
    mov	r1, r9
    str	r0, [r1, #0]
    adds	r0, r7, #0
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08038928
    .thumb_func
func_08038928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    mov	r8, r0
    ldr	r0, [r0, #20]
    cmp	r0, #0
    beq .Lus_0803898A
    adds	r6, r0, #0
    movs	r7, #0
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcs .Lus_0803898A
    adds	r4, r6, #0
    adds	r4, #64	@ 0x40
    adds	r5, r6, #0
    adds	r5, #44	@ 0x2c
.Lus_0803894C:
    ldrb	r0, [r4, #3]
    cmp	r0, #0
    bne .Lus_08038964
    adds	r0, r5, #0
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_08038968
    movs	r0, #1
    strb	r0, [r4, #0]
    b .Lus_08038968
.Lus_08038964:
    movs	r0, #0
    strb	r0, [r4, #3]
.Lus_08038968:
    ldr	r1, [r4, #4]
    ldr	r0, [r4, #12]
    subs	r1, r1, r0
    str	r1, [r4, #4]
    ldrb	r0, [r4, #16]
    lsls	r0, r0, #16
    cmn	r1, r0
    bge .Lus_0803897E
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #17
    str	r0, [r4, #4]
.Lus_0803897E:
    adds	r4, #80	@ 0x50
    adds	r5, #80	@ 0x50
    adds	r7, #1
    ldr	r0, [r6, #0]
    cmp	r7, r0
    bcc .Lus_0803894C
.Lus_0803898A:
    mov	r0, r8
    ldr	r1, [r0, #12]
    cmp	r1, #0
    beq .Lus_080389B2
    adds	r3, r1, #0
    adds	r3, #80	@ 0x50
    ldrb	r0, [r3, #0]
    cmp	r0, #0
    beq .Lus_080389B2
    ldr	r0, [r1, #76]	@ 0x4c
    ldr r2, .Lus_080389F4
    adds	r0, r0, r2
    str	r0, [r1, #76]	@ 0x4c
    movs	r2, #168	@ 0xa8
    lsls	r2, r2, #16
    cmp	r0, r2
    bgt .Lus_080389B2
    str	r2, [r1, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r3, #0]
.Lus_080389B2:
    mov	r1, r8
    ldr	r0, [r1, #16]
    cmp	r0, #0
    beq .Lus_08038A60
    movs	r2, #0
    movs	r7, #0
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r5, r0, r1
    adds	r4, r0, #0
    adds	r4, #44	@ 0x2c
    adds	r6, r0, #0
    adds	r6, #67	@ 0x43
.Lus_080389CC:
    ldrb	r1, [r5, #0]
    cmp	r1, #0
    bne .Lus_08038A08
    ldrb	r0, [r4, #23]
    cmp	r0, #0
    bne .Lus_080389F8
    adds	r0, r4, #0
    str	r2, [sp, #0]
    bl func_0805E8F0
    adds	r1, r0, #0
    lsls	r0, r1, #30
    ldr	r2, [sp, #0]
    cmp	r0, #0
    bge .Lus_080389EE
    movs	r0, #1
    strb	r0, [r4, #20]
.Lus_080389EE:
    adds	r0, r1, #0
    b .Lus_080389FC
    .align 2, 0
.Lus_080389F4:
    .4byte 0xFFFF8000
.Lus_080389F8:
    strb	r1, [r6, #0]
    movs	r0, #2
.Lus_080389FC:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lus_08038A0A
    movs	r0, #1
    strb	r0, [r5, #0]
    b .Lus_08038A0A
.Lus_08038A08:
    adds	r2, #1
.Lus_08038A0A:
    adds	r5, #1
    adds	r4, #64	@ 0x40
    adds	r6, #64	@ 0x40
    adds	r7, #1
    cmp	r7, #4
    bls .Lus_080389CC
    movs	r0, #0
    cmp	r2, #5
    bne .Lus_08038A1E
    movs	r0, #1
.Lus_08038A1E:
    cmp	r0, #0
    beq .Lus_08038A60
    mov	r7, r8
    adds	r7, #16
    movs	r2, #0
    mov	r9, r2
    mov	r0, r8
    ldr	r6, [r0, #16]
    cmp	r9, r6
    beq .Lus_08038A5C
    cmp	r6, #0
    beq .Lus_08038A5C
    ldr	r0, [r6, #0]
    lsls	r0, r0, #6
    adds	r0, #4
    adds	r5, r6, r0
    adds	r4, r6, #4
    cmp	r4, r5
    beq .Lus_08038A56
.Lus_08038A44:
    ldr	r0, [r4, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r4, #0
    movs	r1, #2
    bl _call_via_r2
    adds	r4, #64	@ 0x40
    cmp	r4, r5
    bne .Lus_08038A44
.Lus_08038A56:
    adds	r0, r6, #0
    bl __builtin_delete
.Lus_08038A5C:
    mov	r1, r9
    str	r1, [r7, #0]
.Lus_08038A60:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08038A70
    .thumb_func
func_08038A70:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #140	@ 0x8c
    str	r0, [sp, #92]	@ 0x5c
    movs	r2, #12
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #96]	@ 0x60
    movs	r2, #14
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #100]	@ 0x64
    ldr	r0, [r1, #0]
    ldr	r1, [r1, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #56]	@ 0x38
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #20]
    cmp	r0, #0
    bne .Lus_08038A9C
    b .Lus_08038BA2
.Lus_08038A9C:
    str	r0, [sp, #104]	@ 0x68
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #108]	@ 0x6c
    str	r1, [sp, #112]	@ 0x70
    movs	r1, #0
    str	r1, [sp, #116]	@ 0x74
    ldr	r2, [sp, #104]	@ 0x68
    ldr	r0, [r2, #0]
    cmp	r1, r0
    bcs .Lus_08038BA2
    adds	r5, r2, #0
    adds	r5, #64	@ 0x40
    adds	r2, #20
    str	r2, [sp, #136]	@ 0x88
    ldr	r6, [sp, #104]	@ 0x68
    adds	r6, #4
.Lus_08038ABE:
    ldr	r0, [sp, #108]	@ 0x6c
    ldr	r1, [sp, #112]	@ 0x70
    str	r0, [sp, #60]	@ 0x3c
    str	r1, [sp, #64]	@ 0x40
    ldrb	r0, [r5, #17]
    cmp	r0, #0
    beq .Lus_08038B86
    movs	r1, #6
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    movs	r1, #8
    ldrsh	r0, [r5, r1]
    ldr	r2, [sp, #100]	@ 0x64
    subs	r4, r0, r2
    ldr r0, .Lus_08038B30
    mov	sl, r0
    add	r1, sp, #60	@ 0x3c
    mov	r8, r1
    ldr	r1, [r6, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r6, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, r8
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    ldr	r1, [r6, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08038B38
    ldrh	r0, [r6, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #136]	@ 0x88
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Lus_08038B34
    bl _call_via_r4
    b .Lus_08038B3A
.Lus_08038B30:
    .4byte 0x00007FFF
.Lus_08038B34:
    .4byte func_030004DC
.Lus_08038B38:
    movs	r0, #0
.Lus_08038B3A:
    cmp	r0, #0
    beq .Lus_08038B82
    ldrb	r0, [r5, #0]
    adds	r4, r5, #0
    cmp	r0, #0
    beq .Lus_08038B82
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    ldrb	r0, [r5, #1]
    cmp	r0, #0
    beq .Lus_08038B68
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_08038B7E
.Lus_08038B68:
    ldrb	r0, [r5, #2]
    cmp	r0, #0
    bne .Lus_08038B7E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r5, #2]
.Lus_08038B7E:
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_08038B82:
    movs	r0, #0
    b .Lus_08038B88
.Lus_08038B86:
    movs	r0, #1
.Lus_08038B88:
    strb	r0, [r5, #17]
    adds	r5, #80	@ 0x50
    ldr	r1, [sp, #136]	@ 0x88
    adds	r1, #80	@ 0x50
    str	r1, [sp, #136]	@ 0x88
    adds	r6, #80	@ 0x50
    ldr	r2, [sp, #116]	@ 0x74
    adds	r2, #1
    str	r2, [sp, #116]	@ 0x74
    ldr	r1, [sp, #104]	@ 0x68
    ldr	r0, [r1, #0]
    cmp	r2, r0
    bcc .Lus_08038ABE
.Lus_08038BA2:
    ldr	r2, [sp, #92]	@ 0x5c
    ldr	r0, [r2, #8]
    cmp	r0, #0
    beq .Lus_08038C30
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #68]	@ 0x44
    str	r1, [sp, #72]	@ 0x48
    movs	r0, #150	@ 0x96
    lsls	r0, r0, #1
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, r0, r1
    mov	r9, r1
    movs	r0, #100	@ 0x64
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #68	@ 0x44
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08038C04
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Lus_08038C00
    bl _call_via_r4
    b .Lus_08038C06
.Lus_08038C00:
    .4byte func_030004DC
.Lus_08038C04:
    movs	r0, #0
.Lus_08038C06:
    cmp	r0, #0
    beq .Lus_08038C30
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_08038C30
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_08038C30:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #12]
    cmp	r0, #0
    beq .Lus_08038CC8
    adds	r5, r0, #0
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #76]	@ 0x4c
    str	r1, [sp, #80]	@ 0x50
    adds	r0, r5, #0
    adds	r0, #81	@ 0x51
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #3
    ldr	r1, [sp, #96]	@ 0x60
    subs	r1, #240	@ 0xf0
    subs	r0, r0, r1
    mov	r9, r0
    ldr	r0, [r5, #76]	@ 0x4c
    asrs	r0, r0, #16
    ldr	r2, [sp, #100]	@ 0x64
    subs	r2, r0, r2
    mov	r8, r2
    add	r7, sp, #76	@ 0x4c
    adds	r6, r5, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r7, #4]
    adds	r0, r5, #0
    ldmia	r0!, {r3}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08038C9C
    ldrh	r1, [r5, #12]
    adds	r2, r5, #0
    adds	r2, #16
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    str	r0, [sp, #0]
    str	r6, [sp, #4]
    str	r3, [sp, #8]
    str	r1, [sp, #12]
    str	r2, [sp, #16]
    adds	r0, r4, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #255	@ 0xff
    ldr r4, .Lus_08038C98
    bl _call_via_r4
    b .Lus_08038C9E
    .align 2, 0
.Lus_08038C98:
    .4byte func_030004DC
.Lus_08038C9C:
    movs	r0, #0
.Lus_08038C9E:
    cmp	r0, #0
    beq .Lus_08038CC8
    adds	r4, r5, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_08038CC8
    ldr	r1, [r7, #0]
    adds	r2, r6, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r1, r6, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #0
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_08038CC8:
    ldr	r1, [sp, #92]	@ 0x5c
    ldr	r0, [r1, #16]
    cmp	r0, #0
    bne .Lus_08038CD2
    b .Lus_08038DE0
.Lus_08038CD2:
    str	r0, [sp, #120]	@ 0x78
    ldr	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #56]	@ 0x38
    str	r0, [sp, #84]	@ 0x54
    str	r1, [sp, #88]	@ 0x58
    movs	r2, #0
    str	r2, [sp, #124]	@ 0x7c
    ldr	r0, [sp, #120]	@ 0x78
    adds	r0, #20
    str	r0, [sp, #128]	@ 0x80
    ldr r1, .Lus_08038D68
    str	r1, [sp, #132]	@ 0x84
    ldr	r5, [sp, #120]	@ 0x78
    adds	r5, #4
.Lus_08038CEE:
    ldr	r2, [sp, #120]	@ 0x78
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r0, r2, r1
    ldr	r2, [sp, #124]	@ 0x7c
    adds	r0, r0, r2
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lus_08038DC8
    ldr	r1, [sp, #132]	@ 0x84
    ldrh	r0, [r1, #0]
    ldr	r2, [sp, #96]	@ 0x60
    subs	r2, r0, r2
    mov	r9, r2
    ldrh	r0, [r1, #2]
    ldr	r1, [sp, #100]	@ 0x64
    subs	r4, r0, r1
    adds	r6, r5, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #8
    mov	sl, r2
    add	r0, sp, #84	@ 0x54
    mov	r8, r0
    ldr	r1, [r5, #40]	@ 0x28
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #52]	@ 0x34
    lsls	r2, r2, #2
    ldr	r0, [r5, #44]	@ 0x2c
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r8
    ldr	r3, [r1, #4]
    ldr	r2, [r5, #0]
    ldr	r1, [r5, #8]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08038D70
    ldrh	r0, [r5, #12]
    mov	r1, sl
    str	r1, [sp, #0]
    adds	r1, r7, #0
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    ldr	r2, [sp, #128]	@ 0x80
    str	r2, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    adds	r2, r4, #0
    movs	r3, #255	@ 0xff
    ldr r4, .Lus_08038D6C
    bl _call_via_r4
    b .Lus_08038D72
    .align 2, 0
.Lus_08038D68:
    .4byte gUnk_080F165E
.Lus_08038D6C:
    .4byte func_030004DC
.Lus_08038D70:
    movs	r0, #0
.Lus_08038D72:
    cmp	r0, #0
    beq .Lus_08038DC8
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lus_08038DC8
    mov	r0, r8
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08038DA8
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_08038DC2
.Lus_08038DA8:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_08038DC2
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_08038DC2:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lus_08038DC8:
    ldr	r2, [sp, #128]	@ 0x80
    adds	r2, #64	@ 0x40
    str	r2, [sp, #128]	@ 0x80
    ldr	r0, [sp, #132]	@ 0x84
    adds	r0, #4
    str	r0, [sp, #132]	@ 0x84
    adds	r5, #64	@ 0x40
    ldr	r1, [sp, #124]	@ 0x7c
    adds	r1, #1
    str	r1, [sp, #124]	@ 0x7c
    cmp	r1, #4
    bls .Lus_08038CEE
.Lus_08038DE0:
    add	sp, #140	@ 0x8c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08038DF0
    .thumb_func
func_08038DF0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #8
    mov	r8, r0
    movs	r0, #84	@ 0x54
    bl __builtin_new
    adds	r7, r0, #0
    mov	r1, r8
    ldr	r0, [r1, #0]
    ldr	r4, [r0, #0]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r4, #0
    bl _call_via_r1
    adds	r5, r0, #0
    adds	r0, r7, #0
    adds	r1, r4, #0
    movs	r2, #6
    movs	r3, #27
    bl func_080A4740
    ldr r0, .Lus_08038E8C
    str	r0, [r7, #36]	@ 0x24
    adds	r6, r7, #0
    adds	r6, #40	@ 0x28
    ldr	r4, [r5, #0]
    mov	r0, sp
    ldr	r3, [r4, #12]
    adds	r1, r5, #0
    movs	r2, #0
    bl _call_via_r3
    ldr	r0, [sp, #0]
    ldrh	r2, [r0, #0]
    adds	r0, r6, #0
    ldr	r3, [r4, #16]
    adds	r1, r5, #0
    bl _call_via_r3
    adds	r1, r7, #0
    adds	r1, #72	@ 0x48
    movs	r2, #0
    movs	r0, #1
    strb	r0, [r1, #0]
    movs	r0, #144	@ 0x90
    lsls	r0, r0, #17
    str	r0, [r7, #76]	@ 0x4c
    adds	r0, r7, #0
    adds	r0, #80	@ 0x50
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r2, [r0, #0]
    mov	r5, r8
    adds	r5, #12
    adds	r6, r7, #0
    mov	r0, r8
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Lus_08038E7E
    cmp	r4, #0
    beq .Lus_08038E7E
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Lus_08038E7E:
    str	r6, [r5, #0]
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lus_08038E8C:
    .4byte vtable_unk_080E602C
    .global func_08038E90
    .thumb_func
func_08038E90:
    ldr	r0, [r0, #12]
    movs	r1, #144	@ 0x90
    lsls	r1, r1, #17
    str	r1, [r0, #76]	@ 0x4c
    adds	r0, #80	@ 0x50
    movs	r1, #1
    strb	r1, [r0, #0]
    bx	lr
    .global func_08038EA0
    .thumb_func
func_08038EA0:
    push	{lr}
    ldr	r0, [r0, #12]
    movs	r1, #0
    adds	r0, #80	@ 0x50
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lus_08038EB0
    movs	r1, #1
.Lus_08038EB0:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08038EB8
    .thumb_func
func_08038EB8:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    adds	r5, #12
    movs	r6, #0
    ldr	r4, [r0, #12]
    cmp	r6, r4
    beq .Lus_08038ED8
    cmp	r4, #0
    beq .Lus_08038ED8
    adds	r0, r4, #0
    movs	r1, #2
    bl func_080A47B4
    adds	r0, r4, #0
    bl __builtin_delete
.Lus_08038ED8:
    str	r6, [r5, #0]
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_08038EE0
    .thumb_func
func_08038EE0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #76	@ 0x4c
    mov	r9, r0
    movs	r0, #166	@ 0xa6
    lsls	r0, r0, #1
    bl __builtin_new
    mov	r2, r9
    ldr	r1, [r2, #0]
    adds	r5, r0, #0
    ldr	r6, [r1, #0]
    movs	r0, #0
    str	r0, [r5, #0]
    mov	sl, r0
    add	r3, sp, #8
    mov	r8, r3
    mov	r7, sl
    lsls	r0, r7, #2
    ldr r1, .Lus_08038F14
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_08038F14:
    .4byte .Lus_08038F18
.Lus_08038F18:
    .4byte .Lus_08038F2C
    .4byte .Lus_08038F4C
    .4byte .Lus_08038F4C
    .4byte .Lus_08038FDC
    .4byte .Lus_08038FDC
.Lus_08038F2C:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FCED
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0xE00E2202
.Lus_08038F4C:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FCDD
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332201
    .4byte 0xFD48F06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC5CF0A3
    .4byte 0x62604813
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFBF0F06B
    .4byte 0x0000E046
    .4byte vtable_unk_080E681C
.Lus_08038FDC:
    .4byte 0x6F816830
    .4byte 0xF09A1C30
    .4byte 0x1C01FC95
    .4byte 0x90002004
    .4byte 0x9001201C
    .4byte 0x46422000
    .4byte 0xA8037010
    .4byte 0x1C332200
    .4byte 0xFD00F06B
    .4byte 0x28046828
    .4byte 0x0180D82A
    .4byte 0x182C3004
    .4byte 0xD0222C00
    .4byte 0xA9031C20
    .4byte 0xFC14F0A3
    .4byte 0x6260482C
    .4byte 0x31281C21
    .4byte 0xC88CA80D
    .4byte 0xC888C18C
    .4byte 0xA812C188
    .4byte 0x1C207801
    .4byte 0x7001303C
    .4byte 0x30494668
    .4byte 0x1C217800
    .4byte 0x7008313D
    .4byte 0x304A4668
    .4byte 0x31017800
    .4byte 0x46687008
    .4byte 0x7801304B
    .4byte 0x303F1C20
    .4byte 0x68287001
    .4byte 0x60283001
    .4byte 0x2102A803
    .4byte 0xFBA8F06B
    .4byte 0x004921A2
    .4byte 0x44501868
    .4byte 0x70012100
    .4byte 0x44922201
    .4byte 0x2B044653
    .4byte 0xE745D800
    .4byte 0x444F2710
    .4byte 0x1C2F46B8
    .4byte 0x69064648
    .4byte 0xD01442B7
    .4byte 0xD0122E00
    .4byte 0x01806830
    .4byte 0x18353004
    .4byte 0x42AC1D34
    .4byte 0x6A60D008
    .4byte 0x1C206882
    .4byte 0xF09A2102
    .4byte 0x3440FC35
    .4byte 0xD1F642AC
    .4byte 0xF7C71C30
    .4byte 0x4641FAA9
    .4byte 0xB013600F
    .4byte 0x4698BC38
    .4byte 0x46AA46A1
    .4byte 0xBC01BCF0
    .4byte 0x00004700
    .4byte vtable_unk_080E681C
    .global func_080390D0
    .thumb_func
func_080390D0:
    ldr	r1, [r0, #16]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    adds	r0, #38	@ 0x26
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
    subs	r3, r1, #7
    strh	r3, [r0, #0]
    subs	r3, r2, #4
    strh	r3, [r0, #2]
    adds	r1, #7
    strh	r1, [r0, #4]
    adds	r2, #5
    strh	r2, [r0, #6]
    bx	lr
    .align 2, 0
    push	{lr}
    ldr	r0, [r0, #24]
    bl func_0800FFD0
    movs	r1, #0
    cmp	r0, #30
    bne .Lus_0803912C
    movs	r1, #1
.Lus_0803912C:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039134
    .thumb_func
func_08039134:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r6, r0, #0
    str	r1, [sp, #0]
    mov	sl, r2
    mov	r9, r3
    movs	r7, #100	@ 0x64
    movs	r0, #0
    mov	r8, r0
    movs	r5, #46	@ 0x2e
.Lus_08039150:
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r6, #0
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_080391A6
    ldrh	r0, [r4, #4]
    ldr	r1, [sp, #0]
    cmp	r0, r1
    bne .Lus_080391A6
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_080391A6
    movs	r2, #10
    ldrsh	r1, [r4, r2]
    mov	r0, sl
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    mov	r2, r9
    subs	r0, r0, r2
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r0, r1, r0
    adds	r1, r0, #0
    cmp	r7, #100	@ 0x64
    beq .Lus_080391A2
    cmp	r8, r0
    ble .Lus_080391A6
.Lus_080391A2:
    adds	r7, r5, #0
    mov	r8, r1
.Lus_080391A6:
    adds	r5, #1
    cmp	r5, #69	@ 0x45
    ble .Lus_08039150
    adds	r0, r7, #0
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391C0
    .thumb_func
func_080391C0:
    push	{lr}
    adds	r2, r0, #0
    cmp	r1, #56	@ 0x38
    bgt .Lus_080391D4
    ldr r0, .Lus_080391EC
    cmp	r2, r0
    ble .Lus_080391D4
    adds	r0, #33	@ 0x21
    cmp	r2, r0
    ble .Lus_080391E6
.Lus_080391D4:
    ldr r0, .Lus_080391F0
    cmp	r1, r0
    ble .Lus_080391F4
    cmp	r2, #247	@ 0xf7
    ble .Lus_080391F4
    movs	r0, #140	@ 0x8c
    lsls	r0, r0, #1
    cmp	r2, r0
    bgt .Lus_080391F4
.Lus_080391E6:
    movs	r0, #1
    b .Lus_080391F6
    .align 2, 0
.Lus_080391EC:
    .4byte 0x00000143
.Lus_080391F0:
    .4byte 0x0000027F
.Lus_080391F4:
    movs	r0, #0
.Lus_080391F6:
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080391FC
    .thumb_func
func_080391FC:
    bx	lr
    .align 2, 0
    .global func_08039200
    .thumb_func
func_08039200:
    movs	r0, #0
    bx	lr
    .global func_08039204
    .thumb_func
func_08039204:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r5, r1, #0
    str	r2, [sp, #16]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r1, r8
    adds	r1, #16
    str	r1, [sp, #20]
    mov	r2, r8
    ldrh	r4, [r2, #16]
    cmp	r4, #0
    beq .Lus_08039228
    subs	r4, #1
.Lus_08039228:
    ldrh	r3, [r5, #4]
    mov	ip, r3
    movs	r1, #10
    ldrsh	r0, [r5, r1]
    mov	r9, r0
    movs	r2, #14
    ldrsh	r7, [r5, r2]
    movs	r0, #176	@ 0xb0
    lsls	r0, r0, #1
    cmp	r7, r0
    ble .Lus_0803924A
    add	r3, sp, #8
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Lus_08039254
.Lus_0803924A:
    add	r3, sp, #8
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Lus_08039254:
    adds	r0, r3, #0
    strh	r1, [r0, #0]
    strh	r2, [r3, #2]
    add	r1, sp, #8
    adds	r0, r1, #0
    movs	r2, #0
    ldrsh	r3, [r0, r2]
    mov	sl, r3
    movs	r3, #2
    ldrsh	r6, [r1, r3]
    mov	r0, ip
    cmp	r0, #2
    bne .Lus_080392EA
    mov	r1, sl
    mov	r2, r9
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Lus_0803927A
    negs	r0, r0
.Lus_0803927A:
    cmp	r0, #15
    bgt .Lus_0803928A
    subs	r0, r6, r7
    cmp	r0, #0
    bge .Lus_08039286
    negs	r0, r0
.Lus_08039286:
    cmp	r0, #15
    ble .Lus_080392EA
.Lus_0803928A:
    cmp	r4, #0
    bne .Lus_080392E4
    mov	r0, r9
    adds	r1, r7, #0
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_080392B6
    movs	r1, #0
    cmp	r7, r6
    blt .Lus_080392A4
    movs	r1, #1
.Lus_080392A4:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Lus_080392DC
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Lus_080392DC
.Lus_080392B6:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r3, [sp, #16]
    str	r3, [sp, #0]
    str	r0, [sp, #4]
    mov	r0, r9
    adds	r1, r7, #0
    mov	r2, sl
    adds	r3, r6, #0
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_080392DC
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_080392DC:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Lus_080392E4:
    ldr	r0, [sp, #20]
    strh	r4, [r0, #0]
    b .Lus_080392FC
.Lus_080392EA:
    adds	r0, r5, #0
    movs	r1, #141	@ 0x8d
    lsls	r1, r1, #2
    bl SetMap__7AEntityUi
    add	r1, sp, #12
    mov	r0, r8
    bl func_0809C098
.Lus_080392FC:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803930C
    .thumb_func
func_0803930C:
    movs	r0, #1
    bx	lr
    .global func_08039310
    .thumb_func
func_08039310:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    adds	r5, r1, #0
    str	r2, [sp, #28]
    ldr	r0, [r5, #52]	@ 0x34
    str	r0, [sp, #32]
    adds	r0, #16
    mov	r8, r0
    ldr	r3, [r5, #0]
    ldrb	r1, [r0, #6]
    str	r1, [sp, #36]	@ 0x24
    ldr	r2, [sp, #32]
    ldrh	r6, [r2, #16]
    cmp	r6, #0
    beq .Lus_08039344
    subs	r6, #1
    cmp	r6, #0
    bne .Lus_08039344
    cmp	r1, #0
    beq .Lus_08039344
    subs	r1, #1
    str	r1, [sp, #36]	@ 0x24
.Lus_08039344:
    ldr	r0, [r3, #0]
    mov	r2, r8
    ldrb	r1, [r2, #7]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    bne .Lus_0803935A
    b .Lus_08039488
.Lus_0803935A:
    ldrh	r0, [r4, #4]
    ldrh	r3, [r5, #4]
    cmp	r0, r3
    beq .Lus_08039364
    b .Lus_08039488
.Lus_08039364:
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08039376
    b .Lus_08039488
.Lus_08039376:
    movs	r0, #10
    ldrsh	r2, [r5, r0]
    movs	r1, #14
    ldrsh	r7, [r5, r1]
    movs	r0, #10
    ldrsh	r3, [r4, r0]
    mov	sl, r3
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r9, r1
    ldr	r0, [sp, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_08039444
    mov	r1, sl
    subs	r0, r1, r2
    cmp	r0, #0
    bge .Lus_0803939A
    negs	r0, r0
.Lus_0803939A:
    cmp	r0, #15
    bgt .Lus_080393AC
    mov	r3, r9
    subs	r0, r3, r7
    cmp	r0, #0
    bge .Lus_080393A8
    negs	r0, r0
.Lus_080393A8:
    cmp	r0, #15
    ble .Lus_08039444
.Lus_080393AC:
    cmp	r6, #0
    beq .Lus_080393D4
    mov	r1, r8
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r2
    cmp	r0, #0
    bge .Lus_080393BE
    negs	r0, r0
.Lus_080393BE:
    cmp	r0, #15
    bgt .Lus_08039438
    mov	r1, r8
    movs	r3, #4
    ldrsh	r0, [r1, r3]
    subs	r0, r0, r7
    cmp	r0, #0
    bge .Lus_080393D0
    negs	r0, r0
.Lus_080393D0:
    cmp	r0, #15
    bgt .Lus_08039438
.Lus_080393D4:
    adds	r0, r2, #0
    adds	r1, r7, #0
    str	r2, [sp, #40]	@ 0x28
    bl func_080391C0
    lsls	r0, r0, #24
    ldr	r2, [sp, #40]	@ 0x28
    cmp	r0, #0
    beq .Lus_08039400
    movs	r1, #0
    cmp	r7, r9
    blt .Lus_080393EE
    movs	r1, #1
.Lus_080393EE:
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Lus_08039426
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
    b .Lus_08039426
.Lus_08039400:
    adds	r4, r5, #0
    adds	r4, #32
    ldrb	r0, [r4, #0]
    ldr	r6, [sp, #28]
    str	r6, [sp, #0]
    str	r0, [sp, #4]
    adds	r0, r2, #0
    adds	r1, r7, #0
    mov	r2, sl
    mov	r3, r9
    bl func_080ABC40
    adds	r1, r0, #0
    ldrb	r0, [r4, #0]
    cmp	r0, r1
    beq .Lus_08039426
    adds	r0, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_08039426:
    movs	r0, #30
    bl func_080AB788
    adds	r6, r0, #1
    mov	r1, sl
    mov	r0, r8
    strh	r1, [r0, #2]
    mov	r2, r9
    strh	r2, [r0, #4]
.Lus_08039438:
    add	r3, sp, #36	@ 0x24
    ldrb	r0, [r3, #0]
    mov	r3, r8
    strb	r0, [r3, #6]
    strh	r6, [r3, #0]
    b .Lus_08039548
.Lus_08039444:
    ldr r1, .Lus_0803947C
    ldr	r0, [sp, #8]
    ands	r0, r1
    movs	r1, #36	@ 0x24
    orrs	r0, r1
    ldr r1, .Lus_08039480
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #9
    orrs	r0, r1
    str	r0, [sp, #8]
    mov	r6, r8
    ldrb	r1, [r6, #7]
    lsls	r1, r1, #24
    ldr r2, .Lus_08039484
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #8]
    ldr	r0, [sp, #32]
    add	r1, sp, #8
    bl func_0809C0BC
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
    b .Lus_08039548
    .align 2, 0
.Lus_0803947C:
    .4byte 0xFFFF0000
.Lus_08039480:
    .4byte 0xFF00FFFF
.Lus_08039484:
    .4byte 0x00FFFFFF
.Lus_08039488:
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lus_080394AA
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Lus_080394B2
.Lus_080394AA:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lus_080394B2:
    cmp	r6, #100	@ 0x64
    beq .Lus_08039534
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lus_080394FC
    ldr r1, .Lus_080394F0
    ldr	r0, [sp, #12]
    ands	r0, r1
    str	r0, [sp, #12]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Lus_080394F4
    add	r1, sp, #12
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    lsls	r3, r6, #24
    ldr r0, .Lus_080394F8
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    adds	r0, r4, #0
    bl func_0809C0AC
    b .Lus_08039548
.Lus_080394F0:
    .4byte 0xFFFF0000
.Lus_080394F4:
    .4byte 0xFF00FFFF
.Lus_080394F8:
    .4byte 0x00FFFFFF
.Lus_080394FC:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_08039528
    ldr	r1, [sp, #20]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_0803952C
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lus_08039530
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lus_08039548
.Lus_08039528:
    .4byte 0xFFFF0000
.Lus_0803952C:
    .4byte 0xFF00FFFF
.Lus_08039530:
    .4byte 0x00FFFFFF
.Lus_08039534:
    ldr r1, .Lus_08039558
    ldr	r0, [sp, #24]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #24]
    add	r1, sp, #24
    adds	r0, r4, #0
    bl func_0809C0A0
.Lus_08039548:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lus_08039558:
    .4byte 0xFFFF0000
    .global func_0803955C
    .thumb_func
func_0803955C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #16
    adds	r5, r1, #0
    ldr	r0, [r5, #52]	@ 0x34
    mov	r8, r0
    mov	r6, r8
    adds	r6, #16
    mov	r1, r8
    ldrh	r4, [r1, #16]
    cmp	r4, #0
    beq .Lus_08039582
    subs	r4, #1
    cmp	r4, #0
    beq .Lus_08039582
    b .Lus_080396E2
.Lus_08039582:
    ldrb	r0, [r6, #2]
    cmp	r0, #0
    bne .Lus_0803958A
    b .Lus_080396D4
.Lus_0803958A:
    ldr	r4, [r5, #0]
    ldrh	r7, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    mov	r9, r2
    movs	r1, #14
    ldrsh	r0, [r5, r1]
    mov	sl, r0
    adds	r0, r4, #0
    adds	r1, r7, #0
    mov	r3, sl
    bl func_08039134
    adds	r1, r0, #0
    cmp	r1, #100	@ 0x64
    bne .Lus_080395AC
    ldrb	r1, [r6, #3]
.Lus_080395AC:
    ldr	r0, [r4, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r4, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_08039602
    ldrh	r0, [r4, #4]
    cmp	r0, r7
    bne .Lus_08039602
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #96]	@ 0x60
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08039602
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    movs	r3, #14
    ldrsh	r1, [r4, r3]
    mov	r6, r9
    subs	r0, r0, r6
    cmp	r0, #0
    bge .Lus_080395E4
    negs	r0, r0
.Lus_080395E4:
    cmp	r0, #15
    bgt .Lus_08039602
    mov	r0, sl
    subs	r3, r1, r0
    cmp	r3, #0
    bge .Lus_080395F2
    negs	r3, r3
.Lus_080395F2:
    cmp	r3, #15
    bgt .Lus_08039602
    ldr	r0, [r4, #20]
    adds	r0, #128	@ 0x80
    ldr	r1, [r0, #0]
    adds	r0, r4, #0
    bl _call_via_r1
.Lus_08039602:
    mov	r0, r8
    movs	r1, #4
    bl func_0809C068
    ldr	r4, [r5, #52]	@ 0x34
    movs	r6, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lus_0803962C
    ldr	r0, [r5, #0]
    ldrh	r1, [r5, #4]
    movs	r3, #10
    ldrsh	r2, [r5, r3]
    movs	r6, #14
    ldrsh	r3, [r5, r6]
    bl func_08039134
    adds	r6, r0, #0
    b .Lus_08039634
.Lus_0803962C:
    adds	r0, r5, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lus_08039634:
    cmp	r6, #100	@ 0x64
    beq .Lus_080396B8
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lus_08039680
    ldr r1, .Lus_08039674
    ldr	r0, [sp, #0]
    ands	r0, r1
    str	r0, [sp, #0]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Lus_08039678
    ldr	r1, [sp, #4]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lus_0803967C
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #4]
    adds	r0, r4, #0
    mov	r1, sp
    bl func_0809C0AC
    b .Lus_080396E4
    .align 2, 0
.Lus_08039674:
    .4byte 0xFFFF0000
.Lus_08039678:
    .4byte 0xFF00FFFF
.Lus_0803967C:
    .4byte 0x00FFFFFF
.Lus_08039680:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_080396AC
    ldr	r1, [sp, #8]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_080396B0
    ands	r1, r0
    lsls	r2, r6, #24
    ldr r0, .Lus_080396B4
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #8]
    add	r1, sp, #8
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lus_080396E4
.Lus_080396AC:
    .4byte 0xFFFF0000
.Lus_080396B0:
    .4byte 0xFF00FFFF
.Lus_080396B4:
    .4byte 0x00FFFFFF
.Lus_080396B8:
    ldr r1, .Lus_080396D0
    ldr	r0, [sp, #12]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #12]
    add	r1, sp, #12
    adds	r0, r4, #0
    bl func_0809C0A0
    b .Lus_080396E4
    .align 2, 0
.Lus_080396D0:
    .4byte 0xFFFF0000
.Lus_080396D4:
    movs	r4, #36	@ 0x24
    movs	r0, #1
    strb	r0, [r6, #2]
    adds	r0, r5, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Lus_080396E2:
    strh	r4, [r6, #0]
.Lus_080396E4:
    add	sp, #16
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_080396F4
    .thumb_func
func_080396F4:
    push	{lr}
    ldr	r0, [r1, #52]	@ 0x34
    ldrb	r0, [r0, #18]
    movs	r1, #0
    cmp	r0, #0
    beq .Lus_08039702
    movs	r1, #3
.Lus_08039702:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .global func_08039708
    .thumb_func
func_08039708:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #24
    adds	r6, r1, #0
    mov	sl, r2
    ldr	r0, [r6, #52]	@ 0x34
    movs	r1, #16
    adds	r1, r1, r0
    mov	r9, r1
    ldr	r3, [r6, #0]
    ldrh	r2, [r0, #16]
    mov	r8, r2
    cmp	r2, #0
    beq .Lus_08039730
    movs	r4, #1
    negs	r4, r4
    add	r8, r4
.Lus_08039730:
    ldr	r1, [r0, #16]
    lsls	r0, r1, #9
    lsrs	r7, r0, #25
    cmp	r7, #0
    beq .Lus_0803973C
    subs	r7, #1
.Lus_0803973C:
    mov	r5, r9
    ldrb	r4, [r5, #3]
    cmp	r4, #0
    beq .Lus_08039746
    subs	r4, #1
.Lus_08039746:
    mov	r0, r8
    cmp	r0, #0
    beq .Lus_080397C6
    ldr	r2, [r3, #0]
    lsls	r0, r1, #8
    movs	r1, #0
    cmp	r0, #0
    bge .Lus_08039758
    movs	r1, #43	@ 0x2b
.Lus_08039758:
    ldr	r2, [r2, #64]	@ 0x40
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lus_080397C6
    ldrh	r0, [r3, #4]
    ldrh	r1, [r6, #4]
    cmp	r0, r1
    bne .Lus_080397C6
    cmp	r4, #0
    bne .Lus_080397AC
    movs	r2, #10
    ldrsh	r0, [r6, r2]
    movs	r4, #14
    ldrsh	r1, [r6, r4]
    movs	r5, #10
    ldrsh	r2, [r3, r5]
    movs	r4, #14
    ldrsh	r3, [r3, r4]
    adds	r5, r6, #0
    adds	r5, #32
    ldrb	r4, [r5, #0]
    mov	ip, r4
    mov	r4, sl
    str	r4, [sp, #0]
    mov	r4, ip
    str	r4, [sp, #4]
    bl func_080ABE58
    adds	r1, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r0, r1
    beq .Lus_080397A4
    adds	r0, r6, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_080397A4:
    movs	r0, #30
    bl func_080AB788
    adds	r4, r0, #1
.Lus_080397AC:
    mov	r0, r8
    mov	r5, r9
    strh	r0, [r5, #0]
    movs	r0, #127	@ 0x7f
    ands	r7, r0
    ldrb	r1, [r5, #2]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r7
    strb	r0, [r5, #2]
    strb	r4, [r5, #3]
    b .Lus_0803988C
.Lus_080397C6:
    adds	r0, r6, #0
    bl func_080323C8
    ldr	r4, [r6, #52]	@ 0x34
    movs	r5, #100	@ 0x64
    adds	r0, r4, #0
    bl func_0809C060
    cmp	r0, #0
    beq .Lus_080397EE
    ldr	r0, [r6, #0]
    ldrh	r1, [r6, #4]
    movs	r3, #10
    ldrsh	r2, [r6, r3]
    movs	r5, #14
    ldrsh	r3, [r6, r5]
    bl func_08039134
    adds	r5, r0, #0
    b .Lus_080397F6
.Lus_080397EE:
    adds	r0, r6, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lus_080397F6:
    cmp	r5, #100	@ 0x64
    beq .Lus_08039878
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #69	@ 0x45
    bhi .Lus_08039840
    ldr r1, .Lus_08039834
    ldr	r0, [sp, #8]
    ands	r0, r1
    str	r0, [sp, #8]
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r2, .Lus_08039838
    ldr	r1, [sp, #12]
    ands	r1, r2
    orrs	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Lus_0803983C
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #12]
    adds	r0, r4, #0
    add	r1, sp, #8
    bl func_0809C0AC
    b .Lus_0803988C
.Lus_08039834:
    .4byte 0xFFFF0000
.Lus_08039838:
    .4byte 0xFF00FFFF
.Lus_0803983C:
    .4byte 0x00FFFFFF
.Lus_08039840:
    movs	r0, #60	@ 0x3c
    bl func_080AB788
    adds	r0, #120	@ 0x78
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_0803986C
    ldr	r1, [sp, #16]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_08039870
    ands	r1, r0
    lsls	r2, r5, #24
    ldr r0, .Lus_08039874
    ands	r1, r0
    orrs	r1, r2
    str	r1, [sp, #16]
    add	r1, sp, #16
    adds	r0, r4, #0
    bl func_0809C0BC
    b .Lus_0803988C
.Lus_0803986C:
    .4byte 0xFFFF0000
.Lus_08039870:
    .4byte 0xFF00FFFF
.Lus_08039874:
    .4byte 0x00FFFFFF
.Lus_08039878:
    ldr r1, .Lus_0803989C
    ldr	r0, [sp, #20]
    ands	r0, r1
    movs	r1, #180	@ 0xb4
    orrs	r0, r1
    str	r0, [sp, #20]
    add	r1, sp, #20
    adds	r0, r4, #0
    bl func_0809C0A0
.Lus_0803988C:
    add	sp, #24
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lus_0803989C:
    .4byte 0xFFFF0000
    .global func_080398A0
    .thumb_func
func_080398A0:
    movs	r0, #2
    bx	lr
    .global func_080398A4
    .thumb_func
func_080398A4:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r0, sp
    adds	r1, r5, #0
    bl __5ActorRC5Actor
    ldr r3, .Lus_080399A4
    adds	r0, r6, #0
    adds	r1, r4, #0
    mov	r2, sp
    bl func_08020038
    ldr r0, .Lus_080399A8
    str	r0, [r6, #20]
    str	r5, [r6, #52]	@ 0x34
    adds	r1, r6, #0
    adds	r1, #56	@ 0x38
    movs	r0, #4
    movs	r3, #0
    movs	r2, #1
    negs	r2, r2
.Lus_080398D4:
    stmia	r1!, {r3}
    subs	r0, #1
    cmp	r0, r2
    bne .Lus_080398D4
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lus_080399AC
    str	r0, [r4, #0]
    ldr	r0, [r6, #56]	@ 0x38
    cmp	r4, r0
    beq .Lus_080398F2
    bl __builtin_delete
.Lus_080398F2:
    str	r4, [r6, #56]	@ 0x38
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lus_080399B0
    str	r0, [r4, #0]
    ldr	r0, [r6, #60]	@ 0x3c
    cmp	r4, r0
    beq .Lus_0803990A
    bl __builtin_delete
.Lus_0803990A:
    str	r4, [r6, #60]	@ 0x3c
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lus_080399B4
    str	r0, [r4, #0]
    ldr	r0, [r6, #64]	@ 0x40
    cmp	r4, r0
    beq .Lus_08039922
    bl __builtin_delete
.Lus_08039922:
    str	r4, [r6, #64]	@ 0x40
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lus_080399B8
    str	r0, [r4, #0]
    ldr	r0, [r6, #68]	@ 0x44
    cmp	r4, r0
    beq .Lus_0803993A
    bl __builtin_delete
.Lus_0803993A:
    str	r4, [r6, #68]	@ 0x44
    movs	r0, #4
    bl __builtin_new
    adds	r4, r0, #0
    ldr r0, .Lus_080399BC
    str	r0, [r4, #0]
    ldr	r0, [r6, #72]	@ 0x48
    cmp	r4, r0
    beq .Lus_08039952
    bl __builtin_delete
.Lus_08039952:
    str	r4, [r6, #72]	@ 0x48
    ldr	r0, [r6, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r6
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r6, #0
    bl func_08020080
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r6, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_08039990
    adds	r0, r6, #0
    bl SetAnim__12AActorEntityUi
.Lus_08039990:
    str	r4, [r6, #76]	@ 0x4c
    adds	r0, r6, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    str	r0, [r6, #80]	@ 0x50
    adds	r0, r6, #0
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lus_080399A4:
    .4byte 0x000009C7
.Lus_080399A8:
    .4byte vtable_unk_080E74DC
.Lus_080399AC:
    .4byte vtable_unk_080E74CC
.Lus_080399B0:
    .4byte vtable_unk_080E74BC
.Lus_080399B4:
    .4byte vtable_unk_080E74AC
.Lus_080399B8:
    .4byte vtable_unk_080E749C
.Lus_080399BC:
    .4byte vtable_unk_080E748C
    .global func_080399C0
    .thumb_func
func_080399C0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r7, r1, #0
    ldr r0, .Lus_08039A28
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__5ActorRC13ActorLocation
    adds	r0, r5, #0
    adds	r0, #56	@ 0x38
    cmp	r0, #0
    beq .Lus_080399FC
    adds	r4, r5, #0
    adds	r4, #76	@ 0x4c
    cmp	r0, r4
    beq .Lus_080399FC
    adds	r6, r0, #0
.Lus_080399F0:
    subs	r4, #4
    ldr	r0, [r4, #0]
    bl __builtin_delete
    cmp	r6, r4
    bne .Lus_080399F0
.Lus_080399FC:
    ldr r0, .Lus_08039A2C
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_08039A12
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_08039A12:
    movs	r0, #1
    ands	r0, r7
    cmp	r0, #0
    beq .Lus_08039A20
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_08039A20:
    add	sp, #8
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Lus_08039A28:
    .4byte vtable_unk_080E74DC
.Lus_08039A2C:
    .4byte __vt_7AEntity
    .global func_08039A30
    .thumb_func
func_08039A30:
    push	{r4, lr}
    sub	sp, #16
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r1, #8
    str	r1, [sp, #4]
    str	r2, [sp, #8]
    add	r1, sp, #12
    strb	r2, [r1, #0]
    adds	r1, r4, #0
    movs	r2, #2
    movs	r3, #27
    bl func_080324BC
    add	sp, #16
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08039A5C
    .thumb_func
func_08039A5C:
    bx	lr
    .align 2, 0
    .global func_08039A60
    .thumb_func
func_08039A60:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #112	@ 0x70
    adds	r7, r0, #0
    ldr	r0, [r7, #0]
    mov	sl, r0
    ldrb	r0, [r1, #4]
    cmp	r0, #0
    bne .Lus_08039A7A
    b .Lus_08039BAC
.Lus_08039A7A:
    ldrh	r0, [r7, #4]
    cmp	r0, #2
    bne .Lus_08039A82
    b .Lus_08039BAC
.Lus_08039A82:
    mov	r1, sl
    ldr	r0, [r1, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r0, r2
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrh	r1, [r2, #10]
    ldr r0, .Lus_08039AC0
    ands	r0, r1
    cmp	r0, #20
    beq .Lus_08039AA2
    b .Lus_08039BAC
.Lus_08039AA2:
    ldr	r0, [r2, #0]
    cmp	r0, #0
    beq .Lus_08039AAA
    b .Lus_08039BAC
.Lus_08039AAA:
    movs	r0, #2
    bl func_080AB788
    cmp	r0, #0
    beq .Lus_08039AC4
    add	r0, sp, #68	@ 0x44
    movs	r1, #132	@ 0x84
    lsls	r1, r1, #1
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #2
    b .Lus_08039ACE
.Lus_08039AC0:
    .4byte 0x000007FF
.Lus_08039AC4:
    add	r0, sp, #68	@ 0x44
    movs	r1, #170	@ 0xaa
    lsls	r1, r1, #1
    movs	r2, #16
    negs	r2, r2
.Lus_08039ACE:
    strh	r1, [r0, #0]
    strh	r2, [r0, #2]
    ldr	r0, [sp, #68]	@ 0x44
    str	r0, [sp, #72]	@ 0x48
    add	r4, sp, #72	@ 0x48
    movs	r3, #0
    ldrsh	r2, [r4, r3]
    movs	r6, #2
    ldrsh	r3, [r4, r6]
    mov	r0, sl
    movs	r1, #2
    bl func_08039134
    str	r0, [sp, #108]	@ 0x6c
    cmp	r0, #100	@ 0x64
    beq .Lus_08039BAC
    movs	r0, #100	@ 0x64
    bl func_080AB788
    cmp	r0, #14
    bhi .Lus_08039BAC
    movs	r0, #0
    ldrsh	r6, [r4, r0]
    movs	r2, #2
    ldrsh	r1, [r4, r2]
    mov	r8, r1
    mov	r3, sp
    movs	r2, #2
    ldrh	r1, [r3, #0]
    ldr r4, .Lus_08039D18
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r3, #0]
    lsls	r6, r6, #16
    lsrs	r1, r6, #16
    movs	r0, #63	@ 0x3f
    mov	r9, r0
    ands	r1, r0
    lsls	r1, r1, #2
    ldrb	r5, [r3, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r5
    orrs	r0, r1
    strb	r0, [r3, #1]
    lsrs	r6, r6, #22
    ldrh	r1, [r3, #2]
    adds	r0, r4, #0
    ands	r0, r1
    orrs	r0, r6
    strh	r0, [r3, #2]
    mov	r1, r8
    lsls	r1, r1, #16
    mov	r8, r1
    lsrs	r0, r1, #16
    mov	r6, r9
    ands	r0, r6
    lsls	r0, r0, #2
    ldrb	r1, [r3, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r3, #3]
    mov	r0, r8
    lsrs	r0, r0, #22
    mov	r8, r0
    ldrh	r0, [r3, #4]
    ands	r4, r0
    mov	r1, r8
    orrs	r4, r1
    strh	r4, [r3, #4]
    add	r4, sp, #8
    movs	r5, #1
    adds	r0, r4, #0
    mov	r1, sp
    movs	r2, #6
    bl memcpy
    strb	r5, [r4, #6]
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__12AActorEntityRC13ActorLocation
    ldr r1, .Lus_08039D1C
    ldr	r0, [sp, #76]	@ 0x4c
    ands	r0, r1
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #8
    bl func_080AB788
    adds	r0, #3
    lsls	r0, r0, #24
    lsrs	r0, r0, #8
    ldr r3, .Lus_08039D20
    add	r1, sp, #76	@ 0x4c
    ldr	r2, [r1, #4]
    ands	r2, r3
    orrs	r2, r0
    ldr	r6, [sp, #108]	@ 0x6c
    lsls	r3, r6, #24
    ldr r0, .Lus_08039D24
    ands	r2, r0
    orrs	r2, r3
    str	r2, [r1, #4]
    ldr	r0, [r7, #52]	@ 0x34
    bl func_0809C0AC
    adds	r0, r7, #0
    movs	r1, #171	@ 0xab
    bl func_080200C4
.Lus_08039BAC:
    ldrh	r5, [r7, #4]
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    cmp	r5, r0
    bne .Lus_08039BB8
    b .Lus_08039D06
.Lus_08039BB8:
    mov	r0, sl
    ldr	r1, [r0, #0]
    mov	r0, sp
    ldr	r3, [r1, #52]	@ 0x34
    mov	r1, sl
    adds	r2, r5, #0
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #84	@ 0x54
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    add	r4, sp, #16
    movs	r1, #32
    mov	r8, r1
    movs	r2, #0
    mov	r9, r2
    movs	r1, #33	@ 0x21
    str	r1, [sp, #16]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #36	@ 0x24
    mov	r0, sp
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #84]	@ 0x54
    ldr	r1, [sp, #88]	@ 0x58
    str	r0, [sp, #48]	@ 0x30
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r8
    str	r3, [r4, #40]	@ 0x28
    mov	r6, r9
    str	r6, [r4, #44]	@ 0x2c
    str	r6, [r4, #48]	@ 0x30
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #0
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r8, r4
    cmp	r3, #0
    beq .Lus_08039C38
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Lus_08039C38
    ldr	r1, [r3, #20]
    add	r4, sp, #92	@ 0x5c
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lus_08039C38:
    ldr	r0, [r7, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]	@ 0x40
    movs	r1, #74	@ 0x4a
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    beq .Lus_08039C68
    ldrh	r0, [r3, #4]
    cmp	r0, r5
    bne .Lus_08039C68
    ldr	r1, [r3, #20]
    add	r4, sp, #100	@ 0x64
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    mov	r0, r8
    adds	r1, r4, #0
    movs	r2, #0
    bl func_080ABA90
.Lus_08039C68:
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #8]
    adds	r1, r7, #0
    mov	r2, r8
    bl _call_via_r3
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r7
    ldr	r0, [r0, #56]	@ 0x38
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    adds	r4, r0, #0
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r5, [r0, #0]
    ldr	r1, [r7, #76]	@ 0x4c
    adds	r6, r0, #0
    cmp	r4, r1
    bne .Lus_08039CA8
    ldr	r0, [r7, #80]	@ 0x50
    cmp	r5, r0
    beq .Lus_08039CB8
.Lus_08039CA8:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D5C
    adds	r1, r0, #0
    adds	r0, r7, #0
    bl func_08020080
.Lus_08039CB8:
    ldr	r0, [r7, #76]	@ 0x4c
    cmp	r4, r0
    beq .Lus_08039CD4
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08039D4C
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_08039CD4
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Lus_08039CD4:
    str	r4, [r7, #76]	@ 0x4c
    str	r5, [r7, #80]	@ 0x50
    mov	r4, r8
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #12]
    ldrb	r1, [r6, #0]
    subs	r0, #1
    cmp	r0, #1
    bhi .Lus_08039CFE
    cmp	r1, #1
    bhi .Lus_08039CFE
    movs	r1, #10
    ldrsh	r0, [r7, r1]
    movs	r2, #14
    ldrsh	r1, [r7, r2]
    bl func_080391C0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08039CFE
    movs	r4, #0
.Lus_08039CFE:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_08020170
.Lus_08039D06:
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    movs	r0, #0
    strb	r0, [r1, #0]
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_08039D28
    subs	r0, #1
    b .Lus_08039D2A
.Lus_08039D18:
    .4byte 0xFFFFFC00
.Lus_08039D1C:
    .4byte 0xFFFF0000
.Lus_08039D20:
    .4byte 0xFF00FFFF
.Lus_08039D24:
    .4byte 0x00FFFFFF
.Lus_08039D28:
    ldrh	r0, [r7, #38]	@ 0x26
.Lus_08039D2A:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r2, [r7, #16]
    cmp	r2, #0
    beq .Lus_08039D3C
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lus_08039D3C:
    add	sp, #112	@ 0x70
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08039D4C
    .thumb_func
func_08039D4C:
    ldr r0, .Lus_08039D58
    lsls	r1, r1, #1
    adds	r1, r1, r0
    ldrh	r0, [r1, #0]
    bx	lr
    .align 2, 0
.Lus_08039D58:
    .4byte gUnk_080F16AE
    .global func_08039D5C
    .thumb_func
func_08039D5C:
    push	{lr}
    cmp	r1, #4
    bhi .Lus_08039D90
    lsls	r0, r1, #2
    ldr r1, .Lus_08039D6C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_08039D6C:
    .4byte .Lus_08039D70
.Lus_08039D70:
    .4byte .Lus_08039D90
    .4byte .Lus_08039D84
    .4byte .Lus_08039D8A
    .4byte .Lus_08039D90
    .4byte .Lus_08039D90
.Lus_08039D84:
    .4byte __ewram_bss_end + 0x170
    .hword 0xE003
.Lus_08039D8A:
    .hword 0x2080
    .4byte 0xE0000240
.Lus_08039D90:
    movs	r0, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08039D98
    .thumb_func
func_08039D98:
    ldr	r0, [r0, #52]	@ 0x34
    ldr	r1, [r0, #12]
    movs	r0, #4
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    bx	lr
    .global func_08039DA8
    .thumb_func
func_08039DA8:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Lus_08039E00
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_08039E08
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_08039E0C
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    ldr r0, .Lus_08039E10
    ands	r1, r0
    ldr r0, .Lus_08039E14
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #15
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lus_08039E00:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
.Lus_08039E08:
    .4byte 0xFFFF0000
.Lus_08039E0C:
    .4byte 0xFF80FFFF
.Lus_08039E10:
    .4byte 0xFF7FFFFF
.Lus_08039E14:
    .4byte 0x00FFFFFF
    .global func_08039E18
    .thumb_func
func_08039E18:
    push	{r4, lr}
    sub	sp, #4
    adds	r4, r0, #0
    ldr	r0, [r4, #52]	@ 0x34
    ldr	r0, [r0, #12]
    cmp	r0, #1
    beq .Lus_08039E72
    movs	r0, #120	@ 0x78
    bl func_080AB788
    adds	r0, #240	@ 0xf0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_08039E7C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_08039E80
    ands	r1, r0
    movs	r0, #240	@ 0xf0
    lsls	r0, r0, #14
    orrs	r1, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #16
    orrs	r1, r0
    ldr r0, .Lus_08039E84
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r4, #52]	@ 0x34
    mov	r1, sp
    bl func_0809C0C8
    ldr	r0, [r4, #52]	@ 0x34
    movs	r1, #4
    bl func_0809C068
    adds	r0, r4, #0
    movs	r1, #2
    movs	r2, #0
    bl func_08032384
    adds	r0, r4, #0
    movs	r1, #170	@ 0xaa
    bl func_080200C4
.Lus_08039E72:
    add	sp, #4
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08039E7C:
    .4byte 0xFFFF0000
.Lus_08039E80:
    .4byte 0xFF80FFFF
.Lus_08039E84:
    .4byte 0x00FFFFFF
    .global func_08039E88
    .thumb_func
func_08039E88:
    movs	r0, #2
    bx	lr
    ldr	r1, [r0, #52]	@ 0x34
    ldr	r1, [r1, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r0, [r1, #56]	@ 0x38
    bx	lr
    .global func_08039E98
    .thumb_func
func_08039E98:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r6, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    ldr r0, .Lus_08039F30
    str	r0, [r7, #76]	@ 0x4c
    str	r6, [r7, #0]
    movs	r4, #0
    strh	r5, [r7, #4]
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r1, r0, #0
    adds	r0, r7, #0
    adds	r0, #8
    movs	r2, #3
    str	r2, [sp, #0]
    movs	r2, #27
    str	r2, [sp, #4]
    add	r2, sp, #8
    strb	r4, [r2, #0]
    adds	r2, r5, #0
    adds	r3, r6, #0
    bl func_080A4A00
    mov	r0, r9
    cmp	r0, #1
    bne .Lus_08039F3C
    movs	r0, #76	@ 0x4c
    bl __builtin_new
    adds	r5, r0, #0
    ldr	r0, [r6, #0]
    ldr	r1, [r0, #104]	@ 0x68
    adds	r0, r6, #0
    bl _call_via_r1
    adds	r4, r0, #0
    adds	r0, r5, #0
    adds	r1, r6, #0
    movs	r2, #2
    movs	r3, #15
    bl func_080A4740
    ldr r0, .Lus_08039F34
    str	r0, [r5, #36]	@ 0x24
    movs	r1, #40	@ 0x28
    adds	r1, r1, r5
    mov	r8, r1
    ldr	r6, [r4, #0]
    add	r0, sp, #12
    ldr	r3, [r6, #12]
    adds	r1, r4, #0
    ldr r2, .Lus_08039F38
    bl _call_via_r3
    ldr	r0, [sp, #12]
    ldrh	r2, [r0, #0]
    mov	r0, r8
    ldr	r3, [r6, #16]
    adds	r1, r4, #0
    bl _call_via_r3
    adds	r0, r5, #0
    adds	r0, #72	@ 0x48
    mov	r1, r9
    strb	r1, [r0, #0]
    b .Lus_08039F3E
    .align 2, 0
.Lus_08039F30:
    .4byte vtable_unk_080E76BC
.Lus_08039F34:
    .4byte vtable_unk_080E602C
.Lus_08039F38:
    .4byte 0x0000091A
.Lus_08039F3C:
    movs	r5, #0
.Lus_08039F3E:
    str	r5, [r7, #72]	@ 0x48
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08039F50
    .thumb_func
func_08039F50:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldr r0, .Lus_08039F8C
    str	r0, [r4, #76]	@ 0x4c
    ldr	r1, [r4, #72]	@ 0x48
    cmp	r1, #0
    beq .Lus_08039F6C
    ldr	r0, [r1, #36]	@ 0x24
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_08039F6C:
    adds	r0, r4, #0
    adds	r0, #8
    movs	r1, #2
    bl func_080A47B4
    movs	r0, #1
    ands	r0, r5
    cmp	r0, #0
    beq .Lus_08039F84
    adds	r0, r4, #0
    bl __builtin_delete
.Lus_08039F84:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08039F8C:
    .4byte vtable_unk_080E76BC
    .global func_08039F90
    .thumb_func
func_08039F90:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    mov	sl, r0
    adds	r4, r1, #0
    mov	r9, r2
    mov	r8, r3
    ldr	r5, [sp, #104]	@ 0x68
    ldr	r6, [sp, #108]	@ 0x6c
    ldr	r7, [sp, #112]	@ 0x70
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #24]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r5, r5, r0
    str	r5, [sp, #60]	@ 0x3c
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #28]
    adds	r0, r4, #0
    bl _call_via_r1
    subs	r0, r6, r0
    str	r0, [sp, #64]	@ 0x40
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r6
    str	r0, [sp, #68]	@ 0x44
    add	r0, sp, #52	@ 0x34
    mov	r1, r8
    str	r1, [sp, #52]	@ 0x34
    mov	r3, r9
    str	r3, [r0, #4]
    adds	r5, r7, #0
    mov	r9, r0
    cmp	r5, #0
    bge .Lus_08039FE2
    negs	r7, r5
.Lus_08039FE2:
    ldr	r4, [sp, #64]	@ 0x40
    subs	r4, r4, r7
    mov	r8, r4
    mov	r6, sl
    adds	r6, #8
    movs	r0, #3
    ldr	r7, [sp, #116]	@ 0x74
    ands	r0, r7
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    mov	r0, sl
    ldr	r1, [r0, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r0, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r1, r9
    ldr	r1, [r1, #4]
    mov	ip, r1
    mov	r3, sl
    ldr	r2, [r3, #8]
    ldr	r1, [r3, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_0803A054
    ldrh	r0, [r6, #12]
    mov	r1, sl
    adds	r1, #24
    ldr	r3, [sp, #68]	@ 0x44
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, ip
    ldr	r1, [sp, #60]	@ 0x3c
    mov	r2, r8
    adds	r3, r4, #0
    ldr r4, .Lus_0803A050
    bl _call_via_r4
    b .Lus_0803A056
.Lus_0803A050:
    .4byte func_030004DC
.Lus_0803A054:
    movs	r0, #0
.Lus_0803A056:
    cmp	r0, #0
    beq .Lus_0803A0AA
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r8, r0
    cmp	r1, #0
    beq .Lus_0803A0AA
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_0803A08A
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_0803A0A4
.Lus_0803A08A:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_0803A0A4
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_0803A0A4:
    movs	r0, #0
    mov	r4, r8
    strb	r0, [r4, #0]
.Lus_0803A0AA:
    mov	r7, sl
    ldr	r0, [r7, #72]	@ 0x48
    cmp	r0, #0
    beq .Lus_0803A134
    cmp	r5, #0
    blt .Lus_0803A134
    adds	r6, r0, #0
    mov	r5, r9
    movs	r0, #3
    ldr	r1, [sp, #116]	@ 0x74
    ands	r0, r1
    lsls	r3, r0, #2
    orrs	r3, r0
    lsls	r1, r0, #4
    orrs	r3, r1
    lsls	r0, r0, #6
    orrs	r3, r0
    adds	r7, r6, #0
    adds	r7, #40	@ 0x28
    ldr	r4, [r5, #4]
    mov	r8, r4
    adds	r0, r6, #0
    ldmia	r0!, {r2}
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_0803A108
    ldrh	r0, [r6, #12]
    adds	r1, r6, #0
    adds	r1, #16
    ldr	r4, [sp, #68]	@ 0x44
    str	r4, [sp, #0]
    str	r7, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r8
    ldr	r1, [sp, #60]	@ 0x3c
    ldr	r2, [sp, #64]	@ 0x40
    ldr r4, .Lus_0803A104
    bl _call_via_r4
    b .Lus_0803A10A
    .align 2, 0
.Lus_0803A104:
    .4byte func_030004DC
.Lus_0803A108:
    movs	r0, #0
.Lus_0803A10A:
    cmp	r0, #0
    beq .Lus_0803A134
    adds	r4, r6, #0
    adds	r4, #72	@ 0x48
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_0803A134
    ldr	r1, [r5, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_0803A134:
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_0803A144
    .thumb_func
func_0803A144:
    push	{r4, lr}
    adds	r4, r1, #0
    lsls	r2, r2, #24
    lsrs	r0, r2, #24
    cmp	r2, #0
    bge .Lus_0803A15A
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
.Lus_0803A15A:
    ldr r2, .Lus_0803A17C
    lsls	r0, r0, #24
    asrs	r0, r0, #24
    lsls	r1, r0, #2
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #4]
    lsls	r1, r0, #1
    adds	r1, #1
    lsls	r1, r1, #1
    adds	r1, r1, r2
    ldrh	r1, [r1, #0]
    strh	r1, [r4, #6]
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803A17C:
    .4byte gUnk_080F16C2
    .global func_0803A180
    .thumb_func
func_0803A180:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #72	@ 0x48
    mov	r8, r0
    adds	r4, r1, #0
    adds	r5, r2, #0
    movs	r0, #0
    mov	r9, r0
    mov	r2, r8
    ldr	r1, [r2, #0]
    ldr	r2, [r1, #0]
    mov	r0, sp
    ldr	r3, [r2, #52]	@ 0x34
    movs	r2, #0
    bl _call_via_r3
    movs	r6, #4
    ldrsh	r1, [r4, r6]
    movs	r7, #6
    ldrsh	r3, [r4, r7]
    add	r2, sp, #64	@ 0x40
    adds	r0, r1, #0
    subs	r0, #8
    strh	r0, [r2, #0]
    adds	r0, r3, #0
    subs	r0, #8
    strh	r0, [r2, #2]
    adds	r1, #8
    strh	r1, [r2, #4]
    adds	r3, #8
    strh	r3, [r2, #6]
    add	r3, sp, #12
    movs	r0, #32
    mov	ip, r0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #12]
    subs	r0, #65	@ 0x41
    str	r0, [r3, #4]
    str	r0, [r3, #8]
    str	r1, [r3, #12]
    add	r1, sp, #32
    mov	r0, sp
    ldmia	r0!, {r2, r6, r7}
    stmia	r1!, {r2, r6, r7}
    ldr	r0, [sp, #64]	@ 0x40
    ldr	r1, [sp, #68]	@ 0x44
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    mov	r0, ip
    str	r0, [r3, #40]	@ 0x28
    mov	r1, r9
    str	r1, [r3, #44]	@ 0x2c
    str	r1, [r3, #48]	@ 0x30
    movs	r0, #18
    ldrsb	r0, [r4, r0]
    cmp	r0, #0
    beq .Lus_0803A2A6
    cmp	r0, #1
    bne .Lus_0803A2A6
    ldr	r0, [r4, #0]
    cmp	r0, #1
    beq .Lus_0803A234
    cmp	r0, #1
    bgt .Lus_0803A20A
    cmp	r0, #0
    beq .Lus_0803A214
    b .Lus_0803A2A2
.Lus_0803A20A:
    cmp	r0, #2
    beq .Lus_0803A254
    cmp	r0, #3
    beq .Lus_0803A274
    b .Lus_0803A2A2
.Lus_0803A214:
    ldr	r1, [sp, #12]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lus_0803A226
    adds	r0, r3, #0
    bl func_080AB85C
    ldr	r0, [sp, #12]
    b .Lus_0803A228
.Lus_0803A226:
    adds	r0, r1, #0
.Lus_0803A228:
    cmp	r0, #1
    ble .Lus_0803A2A2
    ldr	r0, [r4, #12]
    adds	r0, r0, r5
    str	r0, [r4, #12]
    b .Lus_0803A2A6
.Lus_0803A234:
    ldr	r1, [sp, #16]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lus_0803A244
    adds	r0, r3, #0
    bl func_080AB8D0
    ldr	r1, [sp, #16]
.Lus_0803A244:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Lus_0803A2A2
    ldr	r0, [r4, #12]
    subs	r0, r0, r5
    str	r0, [r4, #12]
    b .Lus_0803A2A6
.Lus_0803A254:
    ldr	r1, [sp, #20]
    ldr	r0, [sp, #52]	@ 0x34
    cmn	r1, r0
    bge .Lus_0803A264
    adds	r0, r3, #0
    bl func_080AB948
    ldr	r1, [sp, #20]
.Lus_0803A264:
    movs	r0, #1
    negs	r0, r0
    cmp	r1, r0
    bge .Lus_0803A2A2
    ldr	r0, [r4, #8]
    subs	r0, r0, r5
    str	r0, [r4, #8]
    b .Lus_0803A2A6
.Lus_0803A274:
    ldr	r1, [sp, #24]
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    ble .Lus_0803A286
    adds	r0, r3, #0
    bl func_080AB9C4
    ldr	r0, [sp, #24]
    b .Lus_0803A288
.Lus_0803A286:
    adds	r0, r1, #0
.Lus_0803A288:
    cmp	r0, #1
    ble .Lus_0803A2A2
    ldr	r0, [r4, #8]
    adds	r0, r0, r5
    str	r0, [r4, #8]
    asrs	r0, r0, #16
    movs	r1, #145	@ 0x91
    lsls	r1, r1, #2
    cmp	r0, r1
    ble .Lus_0803A2A6
    movs	r0, #145	@ 0x91
    lsls	r0, r0, #18
    str	r0, [r4, #8]
.Lus_0803A2A2:
    movs	r0, #0
    strh	r0, [r4, #16]
.Lus_0803A2A6:
    movs	r2, #10
    ldrsh	r0, [r4, r2]
    strh	r0, [r4, #4]
    movs	r6, #14
    ldrsh	r0, [r4, r6]
    strh	r0, [r4, #6]
    mov	r1, r8
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_0803A2D2
    mov	r0, r8
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_0803A2D6
    mov	r1, r8
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lus_0803A2D4
.Lus_0803A2D2:
    movs	r0, #0
.Lus_0803A2D4:
    strb	r0, [r1, #0]
.Lus_0803A2D6:
    ldrh	r0, [r4, #16]
    subs	r0, #1
    strh	r0, [r4, #16]
    lsls	r0, r0, #16
    cmp	r0, #0
    bge .Lus_0803A310
    movs	r0, #3
    bl func_080AB788
    lsls	r0, r0, #16
    asrs	r1, r0, #16
    cmp	r1, #3
    bne .Lus_0803A2F6
    movs	r0, #0
    strb	r0, [r4, #18]
    b .Lus_0803A302
.Lus_0803A2F6:
    movs	r0, #1
    strb	r0, [r4, #18]
    ldr	r0, [r4, #0]
    bl func_080AB7A4
    str	r0, [r4, #0]
.Lus_0803A302:
    movs	r0, #31
    bl func_080AB788
    adds	r0, #16
    strh	r0, [r4, #16]
    movs	r7, #1
    mov	r9, r7
.Lus_0803A310:
    mov	r0, r9
    add	sp, #72	@ 0x48
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803A320
    .thumb_func
func_0803A320:
    ldr r0, .Lus_0803A330
    lsls	r1, r1, #16
    asrs	r1, r1, #15
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Lus_0803A330:
    .4byte gUnk_080F16D2
    .global func_0803A334
    .thumb_func
func_0803A334:
    ldr r2, .Lus_0803A34C
    lsls	r1, r1, #16
    asrs	r1, r1, #16
    adds	r1, #64	@ 0x40
    movs	r0, #255	@ 0xff
    ands	r1, r0
    lsls	r1, r1, #1
    adds	r1, r1, r2
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    bx	lr
    .align 2, 0
.Lus_0803A34C:
    .4byte gUnk_080F16D2
    .global func_0803A350
    .thumb_func
func_0803A350:
    push	{r4, r5, r6, lr}
    adds	r6, r1, #0
    ldr	r0, [r0, #0]
    ldr	r1, [r0, #0]
    movs	r2, #166	@ 0xa6
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldr	r4, [r0, #0]
    ldr	r5, [r0, #4]
    cmp	r4, r5
    beq .Lus_0803A382
.Lus_0803A36C:
    ldr	r0, [r4, #0]
    bl func_08008CD0
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803A37C
    ldr	r0, [r4, #0]
    b .Lus_0803A386
.Lus_0803A37C:
    adds	r4, #4
    cmp	r4, r5
    bne .Lus_0803A36C
.Lus_0803A382:
    subs	r0, r5, #4
    ldr	r0, [r0, #0]
.Lus_0803A386:
    lsls	r1, r6, #16
    lsrs	r1, r1, #16
    bl func_08008B6C
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .global func_0803A394
    .thumb_func
func_0803A394:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    adds	r5, r2, #0
    lsls	r3, r3, #24
    lsrs	r3, r3, #24
    mov	r9, r3
    ldr r7, .Lus_0803A3E4
    cmp	r3, #0
    bne .Lus_0803A3B4
    ldr r7, .Lus_0803A3E8
.Lus_0803A3B4:
    movs	r0, #4
    mov	sl, r0
    mov	r1, r9
    cmp	r1, #0
    bne .Lus_0803A3C2
    movs	r2, #10
    mov	sl, r2
.Lus_0803A3C2:
    movs	r0, #99	@ 0x63
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    movs	r3, #0
    str	r3, [sp, #0]
    movs	r0, #0
    str	r0, [sp, #4]
    mov	ip, r0
    cmp	r5, #1
    beq .Lus_0803A3FC
    cmp	r5, #1
    bgt .Lus_0803A3EC
    cmp	r5, #0
    beq .Lus_0803A3F6
    b .Lus_0803A40C
.Lus_0803A3E4:
    .4byte gUnk_080F1904
.Lus_0803A3E8:
    .4byte gUnk_080F18D2
.Lus_0803A3EC:
    cmp	r5, #2
    beq .Lus_0803A402
    cmp	r5, #3
    beq .Lus_0803A408
    b .Lus_0803A40C
.Lus_0803A3F6:
    movs	r1, #0
    mov	ip, r1
    b .Lus_0803A40C
.Lus_0803A3FC:
    movs	r2, #1
    mov	ip, r2
    b .Lus_0803A40C
.Lus_0803A402:
    movs	r3, #2
    mov	ip, r3
    b .Lus_0803A40C
.Lus_0803A408:
    movs	r5, #3
    mov	ip, r5
.Lus_0803A40C:
    movs	r3, #0
    cmp	r3, sl
    bge .Lus_0803A458
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    mov	r2, ip
    adds	r1, r7, r2
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Lus_0803A428
    str	r3, [sp, #0]
    ldrb	r5, [r7, #4]
    str	r5, [sp, #4]
    b .Lus_0803A458
.Lus_0803A428:
    lsls	r0, r3, #2
    adds	r0, r0, r3
    adds	r0, r0, r7
    add	r0, ip
    ldrb	r0, [r0, #0]
    subs	r0, r4, r0
    lsls	r0, r0, #16
    lsrs	r4, r0, #16
    adds	r3, #1
    cmp	r3, sl
    bge .Lus_0803A458
    lsls	r0, r4, #16
    asrs	r0, r0, #16
    lsls	r1, r3, #2
    adds	r1, r1, r3
    adds	r2, r1, r7
    mov	r5, ip
    adds	r1, r2, r5
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bge .Lus_0803A428
    str	r3, [sp, #0]
    ldrb	r2, [r2, #4]
    str	r2, [sp, #4]
.Lus_0803A458:
    ldr	r0, [sp, #0]
    cmp	r0, #0
    beq .Lus_0803A468
    mov	r1, r9
    cmp	r1, #0
    beq .Lus_0803A468
    adds	r0, #9
    str	r0, [sp, #0]
.Lus_0803A468:
    ldr	r2, [sp, #4]
    cmp	r2, #1
    ble .Lus_0803A47A
    adds	r0, r2, #0
    subs	r0, #1
    bl func_080AB788
    adds	r0, #1
    str	r0, [sp, #4]
.Lus_0803A47A:
    ldr	r3, [sp, #4]
    cmp	r3, #0
    bgt .Lus_0803A482
    b .Lus_0803A782
.Lus_0803A482:
    movs	r0, #196	@ 0xc4
    lsls	r0, r0, #1
    bl func_080AB788
    adds	r5, r0, #0
    adds	r5, #184	@ 0xb8
    cmp	r5, #239	@ 0xef
    bgt .Lus_0803A4A0
    movs	r0, #56	@ 0x38
    bl func_080AB788
    movs	r1, #248	@ 0xf8
    lsls	r1, r1, #1
    adds	r7, r0, r1
    b .Lus_0803A4AC
.Lus_0803A4A0:
    movs	r0, #48	@ 0x30
    bl func_080AB788
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r7, r0, r2
.Lus_0803A4AC:
    ldr	r0, [sp, #0]
    subs	r0, #1
    cmp	r0, #11
    bls .Lus_0803A4B6
    b .Lus_0803A776
.Lus_0803A4B6:
    lsls	r0, r0, #2
    ldr r1, .Lus_0803A4C0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_0803A4C0:
    .4byte .Lus_0803A4C4
.Lus_0803A4C4:
    .4byte .Lus_0803A4F4
    .4byte .Lus_0803A55C
    .4byte .Lus_0803A578
    .4byte .Lus_0803A598
    .4byte .Lus_0803A5B8
    .4byte .Lus_0803A608
    .4byte .Lus_0803A670
    .4byte .Lus_0803A690
    .4byte .Lus_0803A6B0
    .4byte .Lus_0803A6D0
    .4byte .Lus_0803A6F0
    .4byte .Lus_0803A710
.Lus_0803A4F4:
    .4byte 0xF7C62064
    .4byte 0x1C04F86D
    .4byte 0x4A154641
    .4byte 0xF7FF2301
    .4byte 0x4814FCC9
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x210065A0
    .4byte 0x04005E68
    .4byte 0x1C3165E0
    .4byte 0x68B03108
    .4byte 0xD9002802
    .4byte 0x0080E119
    .4byte 0x18083004
    .4byte 0xD1002800
    .4byte 0x6004E110
    .4byte 0x0000E10E
    .4byte 0x000009B6
    .4byte vtable_unk_080E76A4
.Lus_0803A55C:
    .4byte 0xF7C62064
    .4byte 0x1C04F839
    .4byte 0x22104641
    .4byte 0xF7FF2301
    .4byte 0x4801FC95
    .4byte 0x0000E7CA
    .4byte vtable_unk_080E768C
.Lus_0803A578:
    .4byte 0xF7C62064
    .4byte 0x1C04F82B
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC87
    .4byte 0x0000E7BC
    .4byte 0x000003DB
    .4byte vtable_unk_080E7674
.Lus_0803A598:
    .4byte 0xF7C62064
    .4byte 0x1C04F81B
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC77
    .4byte 0x0000E7AC
    .4byte 0x00000806
    .4byte vtable_unk_080E765C
.Lus_0803A5B8:
    .4byte 0xF7C6206C
    .4byte 0x1C04F80B
    .4byte 0x4A0F4641
    .4byte 0xF7FF2301
    .4byte 0x480EFC67
    .4byte 0x210064E0
    .4byte 0x1C226521
    .4byte 0x23003254
    .4byte 0x1C258015
    .4byte 0x802F3556
    .4byte 0x30601C20
    .4byte 0x30028001
    .4byte 0x23007003
    .4byte 0x04005ED0
    .4byte 0x220065A0
    .4byte 0x04005EA8
    .4byte 0x66A165E0
    .4byte 0x0000E79B
    .4byte 0x00000202
    .4byte vtable_unk_080E7644
.Lus_0803A608:
    .4byte 0xF7C52088
    .4byte 0x1C05FFE3
    .4byte 0x22A94641
    .4byte 0x23010092
    .4byte 0xFC3EF7FF
    .4byte 0x64E84813
    .4byte 0x652C2400
    .4byte 0x31501C29
    .4byte 0x22011C28
    .4byte 0xF7FF4252
    .4byte 0x1C29FD89
    .4byte 0x70083178
    .4byte 0x20FF3101
    .4byte 0x1C287008
    .4byte 0x21003060
    .4byte 0x30028004
    .4byte 0x380E7001
    .4byte 0x5EC02300
    .4byte 0x65A80400
    .4byte 0x30561C28
    .4byte 0x5E402100
    .4byte 0x65E80400
    .4byte 0x31841C29
    .4byte 0x700820F8
    .4byte 0x0000E077
    .4byte vtable_unk_080E762C
.Lus_0803A670:
    .4byte 0xF7C52064
    .4byte 0x1C04FFAF
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FC0B
    .4byte 0x0000E740
    .4byte 0x0000087B
    .4byte vtable_unk_080E7614
.Lus_0803A690:
    .4byte 0xF7C52064
    .4byte 0x1C04FF9F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBFB
    .4byte 0x0000E730
    .4byte 0x0000065C
    .4byte vtable_unk_080E75FC
.Lus_0803A6B0:
    .4byte 0xF7C52064
    .4byte 0x1C04FF8F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBEB
    .4byte 0x0000E720
    .4byte 0x000008F9
    .4byte vtable_unk_080E75E4
.Lus_0803A6D0:
    .4byte 0xF7C52064
    .4byte 0x1C04FF7F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBDB
    .4byte 0x0000E710
    .4byte 0x000009A9
    .4byte vtable_unk_080E75CC
.Lus_0803A6F0:
    .4byte 0xF7C52064
    .4byte 0x1C04FF6F
    .4byte 0x4A034641
    .4byte 0xF7FF2301
    .4byte 0x4802FBCB
    .4byte 0x0000E700
    .4byte 0x000008FD
    .4byte vtable_unk_080E75B4
.Lus_0803A710:
    .4byte 0xF7C52064
    .4byte 0x1C05FF5F
    .4byte 0x22154641
    .4byte 0xF7FF2300
    .4byte 0x481CFBBB
    .4byte 0x240064E8
    .4byte 0x1C29652C
    .4byte 0x1C283150
    .4byte 0x42522201
    .4byte 0xFD06F7FF
    .4byte 0x30601C28
    .4byte 0x80042100
    .4byte 0x70013002
    .4byte 0x2200380E
    .4byte 0x04005E80
    .4byte 0x1C2865A8
    .4byte 0x23003056
    .4byte 0x04005EC0
    .4byte 0x1C3165E8
    .4byte 0x68B03108
    .4byte 0xD8082802
    .4byte 0x30040080
    .4byte 0x28001808
    .4byte 0x6005D000
    .4byte 0x300168B0
    .hword 0x60B0
.Lus_0803A776:
    ldr	r5, [sp, #4]
    subs	r5, #1
    str	r5, [sp, #4]
    cmp	r5, #0
    ble .Lus_0803A782
    b .Lus_0803A482
.Lus_0803A782:
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte vtable_unk_080E759C
    .global func_0803A798
    .thumb_func
func_0803A798:
    push	{r4, r5, r6, lr}
    mov	r6, r8
    push	{r6}
    sub	sp, #8
    adds	r6, r0, #0
    mov	r8, r1
    movs	r0, #32
    bl __builtin_new
    adds	r5, r0, #0
    mov	r1, sp
    ldrh	r2, [r1, #0]
    ldr r3, .Lus_0803A7FC
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldrb	r4, [r1, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r4
    strb	r0, [r1, #1]
    ldrh	r4, [r1, #2]
    adds	r0, r3, #0
    ands	r0, r4
    strh	r0, [r1, #2]
    ldrb	r0, [r1, #3]
    ands	r2, r0
    strb	r2, [r1, #3]
    ldrh	r0, [r1, #4]
    ands	r3, r0
    strh	r3, [r1, #4]
    adds	r0, r5, #0
    adds	r1, r6, #0
    mov	r2, sp
    bl __7AEntityP10GameObjectRC8Location
    ldr r0, .Lus_0803A800
    str	r0, [r5, #20]
    mov	r0, r8
    str	r0, [r5, #24]
    movs	r0, #1
    strb	r0, [r5, #28]
    adds	r0, r5, #0
    add	sp, #8
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803A7FC:
    .4byte 0xFFFFFC00
.Lus_0803A800:
    .4byte vtable_unk_080E7568
    adds	r0, #48	@ 0x30
    movs	r1, #16
    ldrsh	r0, [r0, r1]
    bx	lr
    adds	r0, #48	@ 0x30
    strh	r1, [r0, #16]
    bx	lr
    .align 2, 0
    push	{lr}
    adds	r0, #48	@ 0x30
    bl func_0805E894
    pop	{r1}
    bx	r1
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #48	@ 0x30
    movs	r2, #0
    ldrh	r0, [r1, #14]
    cmp	r0, #0
    beq .Lus_0803A838
    movs	r0, #16
    ldrsh	r1, [r1, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Lus_0803A838:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_0803A864
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_0803A868
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lus_0803A866
.Lus_0803A864:
    movs	r0, #0
.Lus_0803A866:
    strb	r0, [r1, #0]
.Lus_0803A868:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldrh	r0, [r4, #4]
    cmp	r0, r5
    beq .Lus_0803A898
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl ResolveIndexedResourceHandle
    adds	r0, r4, #0
    adds	r0, #68	@ 0x44
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    strh	r5, [r4, #4]
.Lus_0803A898:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    ldr	r0, [r0, #0]
    bx	lr

    .endif
    .endif
    .endif

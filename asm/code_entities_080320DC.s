    .ifdef REGION_JP
    @ JP revision 0 counterpart, expressed as real Thumb instructions and relocations.
    @ Region-specific dispatch paths retain direct labels at their verified
    @ physical locations; no raw code incbin or offset aliases remain.

    .section .text
    .syntax unified
    .thumb
    .align 2, 0
    .global func_0803242C
    .thumb_func
func_0803242C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r3, r0, #0
    mov	r8, r1
    ldrh	r0, [r3, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_080321D4
    subs	r0, #1
    b .Ljp_080321D6
.Ljp_080321D4:
    ldrh	r0, [r3, #38]	@ 0x26
.Ljp_080321D6:
    strh	r0, [r3, #36]	@ 0x24
    ldr	r4, [r3, #40]	@ 0x28
    cmp	r4, #0
    beq .Ljp_0803223A
    movs	r2, #0
    adds	r0, r3, #0
    adds	r0, #46	@ 0x2e
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Ljp_080321EC
    movs	r2, #1
.Ljp_080321EC:
    mov	ip, r2
    cmp	r2, #0
    beq .Ljp_080321F6
    ldr	r2, [r3, #8]
    b .Ljp_080321F8
.Ljp_080321F6:
    ldr	r2, [r3, #12]
.Ljp_080321F8:
    asrs	r5, r2, #16
    movs	r0, #44	@ 0x2c
    ldrsh	r6, [r3, r0]
    subs	r0, r6, r5
    adds	r7, r0, #0
    cmp	r0, #0
    bne .Ljp_0803220A
    str	r0, [r3, #40]	@ 0x28
    b .Ljp_0803223A
.Ljp_0803220A:
    adds	r1, r2, r4
    cmp	r0, #0
    bgt .Ljp_08032212
    subs	r1, r2, r4
.Ljp_08032212:
    adds	r2, r1, #0
    asrs	r0, r2, #16
    cmp	r0, r5
    beq .Ljp_0803222E
    subs	r0, r6, r0
    cmp	r7, #0
    ble .Ljp_08032226
    cmp	r0, #0
    ble .Ljp_0803222A
    b .Ljp_0803222E
.Ljp_08032226:
    cmp	r0, #0
    blt .Ljp_0803222E
.Ljp_0803222A:
    movs	r0, #0
    str	r0, [r3, #40]	@ 0x28
.Ljp_0803222E:
    mov	r0, ip
    cmp	r0, #0
    beq .Ljp_08032238
    str	r2, [r3, #8]
    b .Ljp_0803223A
.Ljp_08032238:
    str	r2, [r3, #12]
.Ljp_0803223A:
    adds	r0, r3, #0
    mov	r1, r8
    bl vfunc_2C__7AEntityUi
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    .section .text.entity_ui_default_no_action_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_080324BC
    .thumb_func
func_080324BC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    add	r0, sp, #52	@ 0x34
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r4, [r7, #0]
    ldr r0, .Ljp_080322F0
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r5, [sp, #0]
    mov	r5, r9
    str	r5, [sp, #4]
    add	r5, sp, #8
    mov	r6, r8
    strb	r6, [r5, #0]
    bl func_080A4A00
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    movs	r2, #0
    strb	r2, [r5, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #40	@ 0x28
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r6, r3, #2
    strb	r6, [r0, #0]
    adds	r0, #1
    add	r5, sp, #48	@ 0x30
    ldrb	r5, [r5, #0]
    strb	r5, [r0, #0]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080322F0:
    .4byte vtable_unk_080E68B4
    .global func_08032560
    .thumb_func
func_08032560:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    mov	r9, r3
    ldr	r6, [sp, #48]	@ 0x30
    add	r0, sp, #64	@ 0x40
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r5, [r7, #0]
    ldr r0, .Ljp_0803239C
    str	r0, [r7, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r5, #34]	@ 0x22
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r4, [sp, #0]
    mov	r4, r9
    str	r4, [sp, #4]
    str	r6, [sp, #8]
    add	r4, sp, #12
    mov	r6, r8
    strb	r6, [r4, #0]
    bl func_080A49A0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    add	r4, sp, #8
    movs	r2, #0
    strb	r2, [r4, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #52	@ 0x34
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #56]	@ 0x38
    lsls	r3, r3, #2
    str	r3, [sp, #16]
    strb	r3, [r0, #0]
    adds	r0, #1
    add	r6, sp, #60	@ 0x3c
    ldrb	r6, [r6, #0]
    strb	r6, [r0, #0]
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0803239C:
    .4byte vtable_unk_080E68B4
    .global func_0803260C
    .thumb_func
func_0803260C:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_080323C4
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_080323C8
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Ljp_080323C6
.Ljp_080323C4:
    movs	r0, #0
.Ljp_080323C6:
    strb	r0, [r1, #0]
.Ljp_080323C8:
    adds	r1, r4, #0
    adds	r1, #138	@ 0x8a
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r5, r0, #30
    adds	r6, r1, #0
    cmp	r5, #0
    beq .Ljp_0803241E
    movs	r7, #0
    subs	r1, #3
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_080323FE
    adds	r0, r4, #0
    adds	r0, #112	@ 0x70
    bl func_0805E8F0
    adds	r2, r0, #0
    lsls	r0, r2, #30
    cmp	r0, #0
    bge .Ljp_080323FA
    adds	r1, r4, #0
    adds	r1, #132	@ 0x84
    movs	r0, #1
    strb	r0, [r1, #0]
.Ljp_080323FA:
    adds	r0, r2, #0
    b .Ljp_08032404
.Ljp_080323FE:
    movs	r0, #0
    strb	r0, [r1, #0]
    movs	r0, #2
.Ljp_08032404:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Ljp_08032410
    cmp	r5, #2
    beq .Ljp_08032410
    movs	r7, #1
.Ljp_08032410:
    cmp	r7, #0
    beq .Ljp_0803241E
    ldrb	r1, [r6, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #0]
.Ljp_0803241E:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08032690
    .thumb_func
func_08032690:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r6, r0, #0
    mov	sl, r1
    ldr	r0, [r6, #0]
    mov	r8, r0
    ldr	r1, [r0, #0]
    str	r1, [sp, #60]	@ 0x3c
    movs	r2, #10
    ldrsh	r1, [r0, r2]
    mov	r3, sl
    movs	r4, #12
    ldrsh	r0, [r3, r4]
    subs	r1, r1, r0
    str	r1, [sp, #64]	@ 0x40
    mov	r0, r8
    movs	r2, #14
    ldrsh	r1, [r0, r2]
    movs	r4, #14
    ldrsh	r0, [r3, r4]
    subs	r0, r1, r0
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r1
    str	r0, [sp, #72]	@ 0x48
    add	r2, sp, #52	@ 0x34
    ldr	r0, [r3, #0]
    ldr	r1, [r3, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r2, #4]
    adds	r0, r6, #0
    adds	r0, #138	@ 0x8a
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #0
    beq .Ljp_08032556
    cmp	r0, #0
    blt .Ljp_08032556
    cmp	r0, #2
    bgt .Ljp_08032556
    mov	r0, r8
    adds	r0, #32
    ldrb	r0, [r0, #0]
    lsrs	r1, r1, #2
    lsls	r1, r1, #4
    lsls	r0, r0, #2
    ldr r2, .Ljp_080324F8
    adds	r0, r0, r2
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    movs	r3, #2
    ldrsh	r1, [r1, r3]
    adds	r5, r6, #0
    adds	r5, #72	@ 0x48
    ldr	r4, [sp, #64]	@ 0x40
    adds	r0, r4, r0
    str	r0, [sp, #76]	@ 0x4c
    ldr	r0, [sp, #68]	@ 0x44
    adds	r0, r0, r1
    mov	r9, r0
    adds	r0, r6, #0
    adds	r0, #112	@ 0x70
    ldr	r1, [r6, #112]	@ 0x70
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #116]	@ 0x74
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r3, [sp, #56]	@ 0x38
    ldr	r2, [r6, #72]	@ 0x48
    ldr	r1, [r6, #80]	@ 0x50
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08032500
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #88	@ 0x58
    ldr	r4, [sp, #72]	@ 0x48
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #76]	@ 0x4c
    mov	r2, r9
    movs	r3, #85	@ 0x55
    ldr r4, .Ljp_080324FC
    bl _call_via_r4
    b .Ljp_08032502
.Ljp_080324F8:
    .4byte gUnk_080F1328
.Ljp_080324FC:
    .4byte func_030004DC
.Ljp_08032500:
    movs	r0, #0
.Ljp_08032502:
    cmp	r0, #0
    beq .Ljp_08032556
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Ljp_08032556
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08032536
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_08032550
.Ljp_08032536:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_08032550
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_08032550:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Ljp_08032556:
    adds	r0, r6, #0
    adds	r0, #139	@ 0x8b
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Ljp_08032580
    cmp	r0, #1
    ble .Ljp_08032568
    cmp	r0, #2
    beq .Ljp_08032584
.Ljp_08032568:
    mov	r0, r8
    adds	r0, #33	@ 0x21
    ldrb	r0, [r0, #0]
    movs	r1, #3
    ands	r0, r1
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    b .Ljp_08032586
.Ljp_08032580:
    movs	r4, #25
    b .Ljp_08032586
.Ljp_08032584:
    movs	r4, #26
.Ljp_08032586:
    adds	r5, r6, #0
    adds	r5, #8
    add	r2, sp, #52	@ 0x34
    mov	r8, r2
    ldr	r1, [r6, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r6, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r3, r8
    ldr	r3, [r3, #4]
    mov	r9, r3
    ldr	r2, [r6, #8]
    ldr	r1, [r6, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_080325E0
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #24
    ldr	r3, [sp, #72]	@ 0x48
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r9
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r4, #0
    ldr r4, .Ljp_080325DC
    bl _call_via_r4
    b .Ljp_080325E2
.Ljp_080325DC:
    .4byte func_030004DC
.Ljp_080325E0:
    movs	r0, #0
.Ljp_080325E2:
    cmp	r0, #0
    beq .Ljp_08032638
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Ljp_08032638
    mov	r4, r8
    ldr	r1, [r4, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08032618
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_08032632
.Ljp_08032618:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_08032632
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_08032632:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Ljp_08032638:
    adds	r0, r6, #0
    adds	r0, #136	@ 0x88
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Ljp_0803265A
    cmp	r0, #1
    bgt .Ljp_0803264C
    cmp	r0, #0
    beq .Ljp_08032656
    b .Ljp_0803265A
.Ljp_0803264C:
    cmp	r0, #2
    beq .Ljp_0803265E
    cmp	r0, #3
    bne .Ljp_0803265A
    b .Ljp_08032684
.Ljp_08032656:
    movs	r4, #0
    b .Ljp_08032660
.Ljp_0803265A:
    movs	r4, #1
    b .Ljp_08032660
.Ljp_0803265E:
    movs	r4, #2
.Ljp_08032660:
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r2, #0
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    adds	r2, r6, #0
    adds	r2, #137	@ 0x89
    movs	r3, #0
    ldrsb	r3, [r2, r3]
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r2, r3
    str	r4, [sp, #0]
    ldr	r2, [sp, #64]	@ 0x40
    bl func_0803AE58
.Ljp_08032684:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    .section .text.entity_ui_region_classification_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08032934
    .thumb_func
func_08032934:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r4, r2, #0
    ldrh	r0, [r4, #8]
    str	r0, [sp, #0]
    adds	r0, r5, #0
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Ljp_080326EC
    str	r0, [r5, #20]
    str	r4, [r5, #48]	@ 0x30
    adds	r0, r5, #0
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Ljp_080326EC:
    .4byte vtable_unk_080E6828
    .global func_080326F0
    .thumb_func
func_080326F0:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_08032740
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldrh	r1, [r5, #34]	@ 0x22
    ldr	r0, [r5, #48]	@ 0x30
    strh	r1, [r0, #8]
    ldr r0, .Ljp_08032744
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_08032728
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_08032728:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Ljp_08032736
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_08032736:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08032740:
    .4byte vtable_unk_080E6828
.Ljp_08032744:
    .4byte __vt_7AEntity
    .global func_08032748
    .thumb_func
func_08032748:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08032A00
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08032760
    .thumb_func
func_08032760:
    ldr	r0, [r0, #48]	@ 0x30
    ldrh	r0, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_08032768
    .thumb_func
func_08032768:
    ldr	r0, [r0, #48]	@ 0x30
    strh	r1, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_08032770
    .thumb_func
func_08032770:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #10
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0

    .section .text.entity_ui_constructor_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08032A30
    .thumb_func
func_08032A30:
    push	{lr}
    adds	r1, r0, #0
    ldrh	r0, [r1, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_080327D2
    subs	r0, #1
    b .Ljp_080327D4
.Ljp_080327D2:
    ldrh	r0, [r1, #38]	@ 0x26
.Ljp_080327D4:
    strh	r0, [r1, #36]	@ 0x24
    ldr	r2, [r1, #16]
    cmp	r2, #0
    beq .Ljp_080327E6
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Ljp_080327E6:
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_080327EC:
    push	{lr}
    adds	r0, #48	@ 0x30
    bl func_0805E894
    pop	{r1}
    bx	r1
.Ljp_080327F8:
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #48	@ 0x30
    movs	r2, #0
    ldrh	r0, [r1, #14]
    cmp	r0, #0
    beq .Ljp_08032810
    movs	r0, #16
    ldrsh	r1, [r1, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Ljp_08032810:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1
.Ljp_08032816:
    movs	r0, r0
    adds	r0, #68	@ 0x44
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032820:
    adds	r0, #139	@ 0x8b
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032828:
    adds	r0, #137	@ 0x89
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032830:
    adds	r0, #136	@ 0x88
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032838:
    adds	r0, #138	@ 0x8a
    ldrb	r2, [r0, #0]
    movs	r1, #4
    negs	r1, r1
    ands	r1, r2
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032848:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    lsls	r4, r2, #24
    lsrs	r4, r4, #24
    adds	r0, #112	@ 0x70
    bl ResolveIndexedResourceHandle
    adds	r0, r5, #0
    adds	r0, #132	@ 0x84
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    movs	r3, #1
    cmp	r4, #0
    beq .Ljp_08032870
    movs	r3, #2
.Ljp_08032870:
    adds	r2, r5, #0
    adds	r2, #138	@ 0x8a
    ldrb	r1, [r2, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #0]
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08032888:
    adds	r0, #138	@ 0x8a
    lsls	r1, r1, #2
    ldrb	r3, [r0, #0]
    movs	r2, #3
    ands	r2, r3
    orrs	r2, r1
    strb	r2, [r0, #0]
    bx	lr
.Ljp_08032898:
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
.Ljp_080328BC:
    ldrh	r0, [r0, #36]	@ 0x24
    bx	lr
.Ljp_080328C0:
    push	{lr}
    movs	r1, #0
    ldrh	r0, [r0, #36]	@ 0x24
    cmp	r0, #0
    bne .Ljp_080328CC
    movs	r1, #1
.Ljp_080328CC:
    adds	r0, r1, #0
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080328D4
    .thumb_func
func_080328D4:
    bx	lr
    .align 2, 0
.Ljp_080328D8:
    push	{lr}
    adds	r2, r0, #0
    ldrh	r0, [r2, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_080328E8
    adds	r0, r2, #0
    bl SetAnim__12AActorEntityUi
.Ljp_080328E8:
    pop	{r0}
    bx	r0
.Ljp_080328EC:
    ldrh	r0, [r0, #34]	@ 0x22
    bx	lr
.Ljp_080328F0:
    ldrh	r1, [r0, #34]	@ 0x22
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r1, r1, r0
    adds	r0, r1, #0
    bx	lr
.Ljp_080328FC:
    push	{lr}
    adds	r2, r0, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r1
    beq .Ljp_0803290E
    adds	r0, r2, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_0803290E:
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08032914:
    adds	r0, #32
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_0803291C:
    movs	r2, #14
    ldrsh	r1, [r0, r2]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r1
    bx	lr
.Ljp_08032928:
    adds	r0, #33	@ 0x21
    strb	r1, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032930:
    adds	r0, #33	@ 0x21
    ldrb	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_08032938:
    str	r1, [r0, #28]
    bx	lr
.Ljp_0803293C:
    ldr	r0, [r0, #28]
    bx	lr
.Ljp_08032940:
    str	r1, [r0, #24]
    bx	lr
.Ljp_08032944:
    ldr	r0, [r0, #24]
    bx	lr
    .global func_08032BB4
    .thumb_func
func_08032BB4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    mov	sl, r2
    str	r3, [sp, #48]	@ 0x30
    mov	r2, sp
    ldrb	r1, [r2, #0]
    movs	r4, #16
    negs	r4, r4
    adds	r0, r4, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    movs	r0, #0
    str	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #48]	@ 0x30
    cmp	r1, #37	@ 0x25
    beq .Ljp_08032976
    b .Ljp_08032BB0
.Ljp_08032976:
    ldr	r2, [sp, #44]	@ 0x2c
    ldr r3, .Ljp_080329C4
    adds	r7, r2, r3
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    bne .Ljp_08032988
    b .Ljp_08032BB0
.Ljp_08032988:
    movs	r6, #0
    str	r6, [sp, #56]	@ 0x38
    adds	r0, r7, #0
    bl GetPregnancyStallCapacity__C4Barn
    mov	r9, r0
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r0, r9
    bcs .Ljp_08032A3A
    add	r1, sp, #20
    mov	r8, r1
.Ljp_0803299E:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl GetPregnancyStallLinkedStall__C4BarnUi
    mvns	r0, r0
    lsrs	r4, r0, #31
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl HasBushelForPregnancyStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_080329C8
    cmp	r4, #0
    bne .Ljp_08032A34
    ldr	r2, [sp, #56]	@ 0x38
    adds	r2, #1
    str	r2, [sp, #56]	@ 0x38
    b .Ljp_08032A34
.Ljp_080329C4:
    .4byte 0x000005DC
.Ljp_080329C8:
    cmp	r4, #0
    beq .Ljp_08032A34
    add	r0, sp, #16
    adds	r1, r7, #0
    adds	r2, r6, #0
    bl method_0800D0C0__C4BarnUi
    ldr	r0, [sp, #16]
    str	r0, [sp, #20]
    mov	r3, r8
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    ldr	r2, [sp, #104]	@ 0x68
    subs	r1, r1, r2
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r5, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032A0A
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r5, r0
    bcs .Ljp_08032A34
.Ljp_08032A0A:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #5
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032A34
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Ljp_08032A34:
    adds	r6, #1
    cmp	r6, r9
    bcc .Ljp_0803299E
.Ljp_08032A3A:
    movs	r6, #0
    mov	r9, r6
    ldr	r1, [sp, #44]	@ 0x2c
    ldr r2, .Ljp_08032AC4
    adds	r0, r1, r2
    bl GetCapacity__C4Barn
    adds	r6, r0, #0
    movs	r5, #0
    cmp	r9, r6
    bcs .Ljp_08032A9A
.Ljp_08032A50:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetBarnAnimal__C4BarnUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08032A94
    mov	r3, sl
    ldr	r0, [r3, #0]
    adds	r1, r5, #0
    adds	r1, #54	@ 0x36
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    cmp	r0, #0
    beq .Ljp_08032A94
    ldrh	r0, [r0, #4]
    cmp	r0, #37	@ 0x25
    bne .Ljp_08032A94
    adds	r0, r4, #0
    bl HasBeenFed__C9Livestock
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032A94
    adds	r0, r4, #0
    bl IsPregnant__C10BarnAnimal
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032A94
    movs	r0, #1
    add	r9, r0
.Ljp_08032A94:
    adds	r5, #1
    cmp	r5, r6
    bcc .Ljp_08032A50
.Ljp_08032A9A:
    mov	r1, r9
    cmp	r1, #0
    bne .Ljp_08032AA2
    b .Ljp_08032BB0
.Ljp_08032AA2:
    str	r6, [sp, #60]	@ 0x3c
    movs	r2, #0
    mov	r8, r2
    movs	r4, #0
    cmp	r8, r6
    bcs .Ljp_08032AE2
.Ljp_08032AAE:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08032AC8
    ldr	r3, [sp, #56]	@ 0x38
    adds	r3, #1
    str	r3, [sp, #56]	@ 0x38
    b .Ljp_08032ADA
.Ljp_08032AC4:
    .4byte 0x000005DC
.Ljp_08032AC8:
    cmp	r4, #15
    bhi .Ljp_08032ADA
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Ljp_08032ADA:
    adds	r4, #1
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r4, r0
    bcc .Ljp_08032AAE
.Ljp_08032AE2:
    ldr	r1, [sp, #56]	@ 0x38
    cmp	r9, r1
    bls .Ljp_08032BB0
    movs	r3, #0
    movs	r4, #31
    movs	r5, #1
    ldr	r2, [sp, #112]	@ 0x70
.Ljp_08032AF0:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    bne .Ljp_08032B12
    ldr	r6, [sp, #56]	@ 0x38
    adds	r6, #1
    str	r6, [sp, #56]	@ 0x38
    ldrb	r1, [r2, #1]
    cmp	r1, #15
    bhi .Ljp_08032B12
    ands	r1, r4
    adds	r0, r5, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Ljp_08032B12:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Ljp_08032AF0
    ldr	r2, [sp, #56]	@ 0x38
    cmp	r9, r2
    bls .Ljp_08032BB0
    movs	r4, #0
    ldr	r3, [sp, #60]	@ 0x3c
    cmp	r4, r3
    bcs .Ljp_08032BB0
    mov	r6, sp
    adds	r6, #28
    str	r6, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r0, #16
    negs	r0, r0
    mov	r9, r0
.Ljp_08032B36:
    movs	r0, #0
    cmp	r4, #15
    bhi .Ljp_08032B4E
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r2, r8
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Ljp_08032B4E:
    cmp	r0, #0
    beq .Ljp_08032BA8
    add	r0, sp, #24
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800D074__C4BarnUi
    ldr	r0, [sp, #24]
    str	r0, [sp, #28]
    ldr	r3, [sp, #68]	@ 0x44
    movs	r6, #0
    ldrsh	r1, [r3, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r6, r1, #0
    muls	r6, r1
    adds	r1, r6, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032B90
    ldr	r3, [sp, #52]	@ 0x34
    cmp	r2, r3
    bcs .Ljp_08032BA8
.Ljp_08032B90:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #4
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Ljp_08032BA8:
    adds	r4, #1
    ldr	r6, [sp, #60]	@ 0x3c
    cmp	r4, r6
    bcc .Ljp_08032B36
.Ljp_08032BB0:
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r0, #17
    beq .Ljp_08032BB8
    b .Ljp_08032D20
.Ljp_08032BB8:
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #2
    adds	r7, r1, r2
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Coop
    cmp	r0, #0
    bne .Ljp_08032BCC
    b .Ljp_08032D20
.Ljp_08032BCC:
    adds	r0, r7, #0
    bl GetCapacity__C4Coop
    adds	r6, r0, #0
    movs	r3, #0
    mov	r9, r3
    movs	r5, #0
    cmp	r9, r6
    bcs .Ljp_08032C1C
.Ljp_08032BDE:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetChicken__C4CoopUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08032C16
    mov	r1, sl
    ldr	r0, [r1, #0]
    adds	r1, r5, #0
    adds	r1, #46	@ 0x2e
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    cmp	r0, #0
    beq .Ljp_08032C16
    ldrh	r0, [r0, #4]
    cmp	r0, #17
    bne .Ljp_08032C16
    adds	r0, r4, #0
    bl HasBeenFed__C9Livestock
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032C16
    movs	r2, #1
    add	r9, r2
.Ljp_08032C16:
    adds	r5, #1
    cmp	r5, r6
    bcc .Ljp_08032BDE
.Ljp_08032C1C:
    mov	r3, r9
    cmp	r3, #0
    beq .Ljp_08032D20
    str	r6, [sp, #64]	@ 0x40
    movs	r5, #0
    mov	r8, r5
    movs	r4, #0
    cmp	r8, r6
    bcs .Ljp_08032C5A
.Ljp_08032C2E:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForEnt__C4CoopUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08032C40
    adds	r5, #1
    b .Ljp_08032C52
.Ljp_08032C40:
    cmp	r4, #7
    bhi .Ljp_08032C52
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Ljp_08032C52:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Ljp_08032C2E
.Ljp_08032C5A:
    cmp	r9, r5
    bls .Ljp_08032D20
    movs	r3, #0
    movs	r4, #31
    movs	r6, #1
    ldr	r2, [sp, #112]	@ 0x70
.Ljp_08032C66:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Ljp_08032C84
    adds	r5, #1
    ldrb	r1, [r2, #1]
    cmp	r1, #7
    bhi .Ljp_08032C84
    ands	r1, r4
    adds	r0, r6, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Ljp_08032C84:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Ljp_08032C66
    cmp	r9, r5
    bls .Ljp_08032D20
    movs	r4, #0
    ldr	r2, [sp, #64]	@ 0x40
    cmp	r4, r2
    bcs .Ljp_08032D20
    mov	r3, sp
    adds	r3, #36	@ 0x24
    str	r3, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r6, #16
    negs	r6, r6
    mov	r9, r6
.Ljp_08032CA6:
    movs	r0, #0
    cmp	r4, #7
    bhi .Ljp_08032CBE
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r0, r8
    ands	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Ljp_08032CBE:
    cmp	r0, #0
    beq .Ljp_08032D18
    add	r0, sp, #32
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800C6F0__C4CoopUi
    ldr	r0, [sp, #32]
    str	r0, [sp, #36]	@ 0x24
    ldr	r2, [sp, #68]	@ 0x44
    movs	r3, #0
    ldrsh	r1, [r2, r3]
    ldr	r6, [sp, #104]	@ 0x68
    subs	r1, r1, r6
    movs	r3, #2
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032D00
    ldr	r6, [sp, #52]	@ 0x34
    cmp	r2, r6
    bcs .Ljp_08032D18
.Ljp_08032D00:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #3
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Ljp_08032D18:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Ljp_08032CA6
.Ljp_08032D20:
    movs	r6, #54	@ 0x36
    movs	r7, #16
    negs	r7, r7
.Ljp_08032D26:
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_08032DCE
    ldrh	r0, [r4, #4]
    ldr	r2, [sp, #48]	@ 0x30
    cmp	r0, r2
    bne .Ljp_08032DCE
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #80]	@ 0x50
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032D72
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #84]	@ 0x54
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032D72
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08032DCE
.Ljp_08032D72:
    movs	r3, #10
    ldrsh	r1, [r4, r3]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    adds	r5, r1, #0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032DA2
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    bcs .Ljp_08032DCE
.Ljp_08032DA2:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    adds	r0, r7, #0
    ands	r0, r1
    movs	r1, #6
    orrs	r0, r1
    strb	r0, [r4, #0]
    adds	r0, r6, #0
    subs	r0, #54	@ 0x36
    strb	r0, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032DCE
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Ljp_08032DCE:
    adds	r6, #1
    cmp	r6, #69	@ 0x45
    bls .Ljp_08032D26
    movs	r4, #46	@ 0x2e
.Ljp_08032DD6:
    mov	r6, sl
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r4, #0
    bl _call_via_r2
    adds	r4, #1
    cmp	r4, #53	@ 0x35
    bls .Ljp_08032DD6
    movs	r5, #76	@ 0x4c
    movs	r7, #16
    negs	r7, r7
.Ljp_08032DF0:
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r2, r0, #0
    cmp	r2, #0
    beq .Ljp_08032E68
    ldrh	r0, [r2, #4]
    ldr	r3, [sp, #48]	@ 0x30
    cmp	r0, r3
    bne .Ljp_08032E68
    movs	r6, #10
    ldrsh	r1, [r2, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    adds	r6, r1, #0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032E3C
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    bcs .Ljp_08032E68
.Ljp_08032E3C:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    adds	r0, r7, #0
    ands	r0, r1
    movs	r1, #8
    orrs	r0, r1
    strb	r0, [r4, #0]
    adds	r0, r5, #0
    subs	r0, #76	@ 0x4c
    strb	r0, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032E68
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r6, [sp, #52]	@ 0x34
.Ljp_08032E68:
    adds	r5, #1
    cmp	r5, #83	@ 0x53
    bls .Ljp_08032DF0
    ldr	r1, [sp, #40]	@ 0x28
    mov	r0, sp
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    ldr	r0, [sp, #40]	@ 0x28
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_080330F4
    .thumb_func
func_080330F4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #108	@ 0x6c
    str	r0, [sp, #68]	@ 0x44
    adds	r5, r1, #0
    adds	r7, r2, #0
    adds	r4, r3, #0
    ldr	r3, [sp, #140]	@ 0x8c
    add	r2, sp, #12
    ldrb	r1, [r2, #0]
    movs	r6, #16
    negs	r6, r6
    adds	r0, r6, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrb	r1, [r4, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #2]
    ldr r2, .Ljp_08032EE4
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    str	r0, [sp, #72]	@ 0x48
    ldrb	r1, [r4, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #4]
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    mov	sl, r0
    cmp	r3, #1
    bne .Ljp_08032ED8
    b .Ljp_0803301A
.Ljp_08032ED8:
    cmp	r3, #1
    bgt .Ljp_08032EE8
    cmp	r3, #0
    beq .Ljp_08032EF0
    b .Ljp_080332FE
    .align 2, 0
.Ljp_08032EE4:
    .4byte 0x000003FF
.Ljp_08032EE8:
    cmp	r3, #2
    bne .Ljp_08032EEE
    b .Ljp_080330D0
.Ljp_08032EEE:
    b .Ljp_080332FE
.Ljp_08032EF0:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    mov	r9, r0
    ldr r1, .Ljp_08032F88
    adds	r1, r5, r1
    str	r1, [sp, #80]	@ 0x50
    mov	r2, sp
    adds	r2, #32
    str	r2, [sp, #84]	@ 0x54
.Ljp_08032F02:
    movs	r7, #0
    mov	r3, r9
    lsls	r3, r3, #1
    str	r3, [sp, #100]	@ 0x64
    mov	r4, r9
    adds	r4, #1
    str	r4, [sp, #96]	@ 0x60
    ldr	r6, [sp, #72]	@ 0x48
    negs	r0, r6
    movs	r1, #140	@ 0x8c
    lsls	r1, r1, #1
    adds	r6, r0, r1
.Ljp_08032F1A:
    ldr	r0, [sp, #100]	@ 0x64
    adds	r0, #23
    lsls	r0, r0, #3
    mov	r2, sl
    subs	r0, r0, r2
    adds	r1, r6, #0
    muls	r1, r6
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    mov	r8, r1
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08032F42
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r8, r4
    bcs .Ljp_08033006
.Ljp_08032F42:
    movs	r0, #43	@ 0x2b
    mov	r1, r9
    muls	r1, r0
    adds	r0, r1, #0
    adds	r0, r7, r0
    lsls	r0, r0, #2
    ldr	r2, [sp, #80]	@ 0x50
    adds	r0, r2, r0
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r0, r0, #28
    cmp	r0, #5
    bne .Ljp_08032F82
    str	r1, [sp, #28]
    add	r0, sp, #20
    add	r1, sp, #28
    bl method_0800A4A4__9FieldPlot
    add	r5, sp, #20
    adds	r0, r5, #0
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08032F82
    adds	r0, r5, #0
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Ljp_08032F8C
    cmp	r0, #1
    beq .Ljp_08032FB4
.Ljp_08032F82:
    movs	r1, #0
    b .Ljp_08032FD2
    .align 2, 0
.Ljp_08032F88:
    .4byte 0x000009C8
.Ljp_08032F8C:
    add	r0, sp, #24
    adds	r1, r5, #0
    bl GetFood__C12RucksackItem
    add	r0, sp, #24
    ldrb	r1, [r0, #0]
    adds	r0, #1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #26
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    ldr	r0, [sp, #84]	@ 0x54
    bl __7ProductG4Food
    ldr	r0, [sp, #84]	@ 0x54
    b .Ljp_08032FC8
.Ljp_08032FB4:
    mov	r4, sp
    adds	r4, #33	@ 0x21
    adds	r0, r5, #0
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl __7ProductG7Article
    adds	r0, r4, #0
.Ljp_08032FC8:
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r1, r1, #31
.Ljp_08032FD2:
    cmp	r1, #0
    beq .Ljp_08033006
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #2
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r7, [r4, #1]
    mov	r3, r9
    strb	r3, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08033006
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r4}
    stmia	r1!, {r2, r4}
    mov	r3, r8
    str	r3, [sp, #76]	@ 0x4c
.Ljp_08033006:
    adds	r6, #16
    adds	r7, #1
    cmp	r7, #42	@ 0x2a
    bls .Ljp_08032F1A
    ldr	r4, [sp, #96]	@ 0x60
    mov	r9, r4
    cmp	r4, #24
    bhi .Ljp_08033018
    b .Ljp_08032F02
.Ljp_08033018:
    b .Ljp_080332FE
.Ljp_0803301A:
    movs	r0, #0
    str	r0, [sp, #88]	@ 0x58
    movs	r7, #0
    ldr r1, .Ljp_080330CC
    adds	r1, r1, r5
    mov	r9, r1
.Ljp_08033026:
    movs	r6, #0
    adds	r2, r7, #1
    mov	r8, r2
    ldr	r3, [sp, #72]	@ 0x48
    negs	r0, r3
    movs	r4, #140	@ 0x8c
    lsls	r4, r4, #1
    adds	r5, r0, r4
.Ljp_08033036:
    movs	r0, #43	@ 0x2b
    muls	r0, r7
    adds	r0, r6, r0
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r2, r0, #28
    movs	r3, #0
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_08033062
    subs	r0, r2, #1
    cmp	r0, #3
    bhi .Ljp_08033062
    lsls	r0, r1, #24
    lsrs	r0, r0, #26
    movs	r1, #20
    eors	r0, r1
    negs	r0, r0
    lsrs	r3, r0, #31
.Ljp_08033062:
    cmp	r3, #0
    beq .Ljp_080330BC
    lsls	r0, r7, #4
    adds	r0, #184	@ 0xb8
    mov	r1, sl
    subs	r0, r0, r1
    adds	r1, r5, #0
    muls	r1, r5
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r1, r1, r0
    adds	r2, r1, #0
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_0803308C
    ldr	r3, [sp, #88]	@ 0x58
    cmp	r1, r3
    bcs .Ljp_080330BC
.Ljp_0803308C:
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    strb	r7, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    str	r2, [sp, #104]	@ 0x68
    bl func_0809E968
    lsls	r0, r0, #24
    ldr	r2, [sp, #104]	@ 0x68
    cmp	r0, #0
    bne .Ljp_080330BC
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    str	r2, [sp, #88]	@ 0x58
.Ljp_080330BC:
    adds	r5, #16
    adds	r6, #1
    cmp	r6, #42	@ 0x2a
    bls .Ljp_08033036
    mov	r7, r8
    cmp	r7, #24
    bls .Ljp_08033026
    b .Ljp_080332FE
.Ljp_080330CC:
    .4byte 0x000009C8
.Ljp_080330D0:
    add	r0, sp, #36	@ 0x24
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    add	r6, sp, #40	@ 0x28
    mov	r8, r6
    add	r0, sp, #44	@ 0x2c
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [sp, #48]	@ 0x30
    add	r6, sp, #48	@ 0x30
    add	r0, sp, #52	@ 0x34
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #52]	@ 0x34
    str	r0, [sp, #56]	@ 0x38
    mov	r0, sp
    adds	r0, #56	@ 0x38
    str	r0, [sp, #92]	@ 0x5c
    add	r0, sp, #60	@ 0x3c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [sp, #64]	@ 0x40
    add	r1, sp, #64	@ 0x40
    mov	r9, r1
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r0, #17
    bne .Ljp_08033114
    b .Ljp_0803327E
.Ljp_08033114:
    cmp	r0, #17
    bgt .Ljp_0803311E
    cmp	r0, #2
    beq .Ljp_08033124
    b .Ljp_080332FE
.Ljp_0803311E:
    cmp	r0, #37	@ 0x25
    beq .Ljp_080331FA
    b .Ljp_080332FE
.Ljp_08033124:
    ldr	r2, [sp, #72]	@ 0x48
    str	r2, [sp, #0]
    mov	r3, sl
    str	r3, [sp, #4]
    ldr	r4, [sp, #144]	@ 0x90
    str	r4, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_08033152
    b .Ljp_080332FE
.Ljp_08033152:
    mov	r1, r8
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    mov	r2, r8
    movs	r1, #2
    ldrsh	r0, [r2, r1]
    mov	r2, sl
    subs	r1, r0, r2
    adds	r2, r3, #0
    muls	r2, r3
    adds	r0, r1, #0
    muls	r0, r1
    adds	r2, r2, r0
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    mov	r6, sl
    subs	r1, r0, r6
    adds	r0, r3, #0
    muls	r0, r3
    adds	r3, r1, #0
    muls	r3, r1
    adds	r1, r3, #0
    adds	r0, r0, r1
    cmp	r2, r0
    bhi .Ljp_080331AC
    ldr	r6, [sp, #92]	@ 0x5c
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Ljp_08033240
.Ljp_080331AC:
    mov	r6, r9
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Ljp_080331DE
    b .Ljp_080332FE
.Ljp_080331DE:
    ldr	r3, [sp, #92]	@ 0x5c
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Ljp_08033270
.Ljp_080331FA:
    ldr	r6, [sp, #72]	@ 0x48
    str	r6, [sp, #0]
    mov	r0, sl
    str	r0, [sp, #4]
    ldr	r1, [sp, #144]	@ 0x90
    str	r1, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_080332FE
    mov	r6, r8
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
.Ljp_08033240:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_080332FE
    mov	r3, r9
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
.Ljp_08033270:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    b .Ljp_080332FE
.Ljp_0803327E:
    ldr	r0, [sp, #72]	@ 0x48
    str	r0, [sp, #0]
    mov	r1, sl
    str	r1, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_080332FE
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_080332FE
    ldr	r1, [sp, #92]	@ 0x5c
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #0]
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    str	r0, [sp, #4]
    ldr	r6, [sp, #144]	@ 0x90
    str	r6, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
.Ljp_080332FE:
    ldr	r1, [sp, #68]	@ 0x44
    add	r0, sp, #12
    ldmia	r0!, {r4, r6}
    stmia	r1!, {r4, r6}
    ldr	r0, [sp, #68]	@ 0x44
    add	sp, #108	@ 0x6c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033584
    .thumb_func
func_08033584:
    push	{r4, r5, r6, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r3, r2, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Ljp_080333DC
    lsls	r0, r0, #2
    ldr r1, .Ljp_08033338
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08033338:
    .4byte .Ljp_0803333C
.Ljp_0803333C:
    .4byte .Ljp_080333DC
    .4byte .Ljp_08033360
    .4byte .Ljp_0803339C
    .4byte .Ljp_08033438
    .4byte .Ljp_08033454
    .4byte .Ljp_08033474
    .4byte .Ljp_0803349C
    .4byte .Ljp_080334E8
    .4byte .Ljp_080334F8
.Ljp_08033360:
    ldrb	r2, [r4, #2]
    ldr r0, .Ljp_08033398
    adds	r1, r5, r0
    movs	r0, #43	@ 0x2b
    muls	r0, r2
    ldrb	r4, [r4, #1]
    adds	r0, r0, r4
    lsls	r0, r0, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    lsls	r0, r1, #20
    lsrs	r2, r0, #28
    movs	r3, #0
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_08033394
    subs	r0, r2, #1
    cmp	r0, #3
    bhi .Ljp_08033394
    lsls	r0, r1, #24
    lsrs	r0, r0, #26
    movs	r1, #20
    eors	r0, r1
    negs	r0, r0
    lsrs	r3, r0, #31
.Ljp_08033394:
    adds	r0, r3, #0
    b .Ljp_0803350E
.Ljp_08033398:
    .4byte 0x000009C8
.Ljp_0803339C:
    ldrb	r2, [r4, #2]
    ldr r0, .Ljp_080333E0
    adds	r1, r5, r0
    movs	r0, #43	@ 0x2b
    muls	r0, r2
    ldrb	r4, [r4, #1]
    adds	r0, r0, r4
    lsls	r0, r0, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    lsls	r0, r1, #20
    lsrs	r0, r0, #28
    cmp	r0, #5
    bne .Ljp_080333DC
    str	r1, [sp, #8]
    add	r1, sp, #8
    mov	r0, sp
    bl method_0800A4A4__9FieldPlot
    mov	r0, sp
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080333DC
    mov	r0, sp
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Ljp_080333E4
    cmp	r0, #1
    beq .Ljp_08033418
.Ljp_080333DC:
    movs	r0, #0
    b .Ljp_0803350E
.Ljp_080333E0:
    .4byte 0x000009C8
.Ljp_080333E4:
    add	r4, sp, #12
    add	r0, sp, #4
    mov	r1, sp
    bl GetFood__C12RucksackItem
    add	r0, sp, #4
    ldrb	r1, [r0, #0]
    adds	r0, #1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #6
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    adds	r0, r4, #0
    bl __7ProductG4Food
    adds	r0, r4, #0
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r0, r1, #31
    b .Ljp_0803350E
.Ljp_08033418:
    mov	r4, sp
    adds	r4, #13
    mov	r0, sp
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl __7ProductG7Article
    adds	r0, r4, #0
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r0, r1, #31
    b .Ljp_0803350E
.Ljp_08033438:
    movs	r6, #0
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    adds	r5, r5, r0
    adds	r0, r5, #0
    bl GetStoredBushelCount__C4Coop
    cmp	r0, #0
    beq .Ljp_08033494
    ldrb	r1, [r4, #1]
    adds	r0, r5, #0
    bl HasBushelForEnt__C4CoopUi
    b .Ljp_0803348C
.Ljp_08033454:
    movs	r6, #0
    ldr r0, .Ljp_08033470
    adds	r5, r5, r0
    adds	r0, r5, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    beq .Ljp_08033494
    ldrb	r1, [r4, #1]
    adds	r0, r5, #0
    bl HasBushelForStall__C4BarnUi
    b .Ljp_0803348C
    .align 2, 0
.Ljp_08033470:
    .4byte 0x000005DC
.Ljp_08033474:
    movs	r6, #0
    ldr r0, .Ljp_08033498
    adds	r5, r5, r0
    adds	r0, r5, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    beq .Ljp_08033494
    ldrb	r1, [r4, #1]
    adds	r0, r5, #0
    bl HasBushelForPregnancyStall__C4BarnUi
.Ljp_0803348C:
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08033494
    movs	r6, #1
.Ljp_08033494:
    adds	r0, r6, #0
    b .Ljp_0803350E
.Ljp_08033498:
    .4byte 0x000005DC
.Ljp_0803349C:
    ldrb	r1, [r4, #1]
    adds	r1, #54	@ 0x36
    ldr	r0, [r3, #0]
    ldr	r2, [r0, #68]	@ 0x44
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r4, r0, #0
    movs	r5, #0
    cmp	r4, #0
    beq .Ljp_080334E4
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #80]	@ 0x50
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080334E2
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #84]	@ 0x54
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080334E2
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_080334E4
.Ljp_080334E2:
    movs	r5, #1
.Ljp_080334E4:
    adds	r0, r5, #0
    b .Ljp_0803350E
.Ljp_080334E8:
    ldrb	r1, [r4, #1]
    adds	r1, #46	@ 0x2e
    ldr	r0, [r3, #0]
    ldr	r2, [r0, #68]	@ 0x44
    adds	r0, r3, #0
    bl _call_via_r2
    b .Ljp_080333DC
.Ljp_080334F8:
    ldrb	r1, [r4, #1]
    adds	r1, #76	@ 0x4c
    ldr	r0, [r3, #0]
    ldr	r2, [r0, #68]	@ 0x44
    adds	r0, r3, #0
    bl _call_via_r2
    adds	r1, r0, #0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Ljp_0803350E:
    add	sp, #16
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033784
    .thumb_func
func_08033784:
    push	{r4, lr}
    adds	r3, r0, #0
    adds	r4, r2, #0
    ldrb	r0, [r3, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Ljp_08033586
    lsls	r0, r0, #2
    ldr r1, .Ljp_08033534
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08033534:
    .4byte .Ljp_08033538
.Ljp_08033538:
    .4byte .Ljp_08033586
    .4byte .Ljp_0803355C
    .4byte .Ljp_0803355C
    .4byte .Ljp_08033560
    .4byte .Ljp_08033564
    .4byte .Ljp_08033564
    .4byte .Ljp_08033568
    .4byte .Ljp_0803356E
    .4byte .Ljp_08033574
.Ljp_0803355C:
    movs	r0, #2
    b .Ljp_0803358E
.Ljp_08033560:
    movs	r0, #17
    b .Ljp_0803358E
.Ljp_08033564:
    movs	r0, #37	@ 0x25
    b .Ljp_0803358E
.Ljp_08033568:
    ldrb	r1, [r3, #1]
    adds	r1, #54	@ 0x36
    b .Ljp_08033578
.Ljp_0803356E:
    ldrb	r1, [r3, #1]
    adds	r1, #46	@ 0x2e
    b .Ljp_08033578
.Ljp_08033574:
    ldrb	r1, [r3, #1]
    adds	r1, #76	@ 0x4c
.Ljp_08033578:
    ldr	r0, [r4, #0]
    ldr	r2, [r0, #68]	@ 0x44
    adds	r0, r4, #0
    bl _call_via_r2
    cmp	r0, #0
    bne .Ljp_0803358C
.Ljp_08033586:
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    b .Ljp_0803358E
.Ljp_0803358C:
    ldrh	r0, [r0, #4]
.Ljp_0803358E:
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08033800
    .thumb_func
func_08033800:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, r1, #0
    adds	r1, r2, #0
    ldr	r2, [r0, #0]
    ldr	r2, [r2, #68]	@ 0x44
    bl _call_via_r2
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Ljp_080335B6
    movs	r2, #10
    ldrsh	r0, [r1, r2]
    movs	r2, #14
    ldrsh	r1, [r1, r2]
    strh	r0, [r4, #0]
    b .Ljp_080335B8
.Ljp_080335B6:
    strh	r1, [r4, #0]
.Ljp_080335B8:
    strh	r1, [r4, #2]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033830
    .thumb_func
func_08033830:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Ljp_08033608
    lsls	r0, r0, #2
    ldr r1, .Ljp_080335E0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_080335E0:
    .4byte .Ljp_080335E4
.Ljp_080335E4:
    .4byte .Ljp_08033608
    .4byte .Ljp_08033610
    .4byte .Ljp_08033610
    .4byte .Ljp_08033626
    .4byte .Ljp_08033636
    .4byte .Ljp_08033648
    .4byte .Ljp_0803365C
    .4byte .Ljp_08033662
    .4byte .Ljp_08033670
.Ljp_08033608:
    movs	r0, #0
    strh	r0, [r5, #0]
    strh	r0, [r5, #2]
    b .Ljp_0803367C
.Ljp_08033610:
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    lsls	r0, r0, #4
    movs	r2, #140	@ 0x8c
    lsls	r2, r2, #1
    adds	r0, r0, r2
    lsls	r1, r1, #4
    adds	r1, #184	@ 0xb8
    strh	r0, [r5, #0]
    strh	r1, [r5, #2]
    b .Ljp_0803367C
.Ljp_08033626:
    movs	r0, #255	@ 0xff
    lsls	r0, r0, #2
    adds	r1, r2, r0
    ldrb	r2, [r4, #1]
    adds	r0, r5, #0
    bl method_0800C6F0__C4CoopUi
    b .Ljp_0803367C
.Ljp_08033636:
    ldr r0, .Ljp_08033644
    adds	r1, r2, r0
    ldrb	r2, [r4, #1]
    adds	r0, r5, #0
    bl method_0800D074__C4BarnUi
    b .Ljp_0803367C
.Ljp_08033644:
    .4byte 0x000005DC
.Ljp_08033648:
    ldr r0, .Ljp_08033658
    adds	r1, r2, r0
    ldrb	r2, [r4, #1]
    adds	r0, r5, #0
    bl method_0800D0C0__C4BarnUi
    b .Ljp_0803367C
    .align 2, 0
.Ljp_08033658:
    .4byte 0x000005DC
.Ljp_0803365C:
    ldrb	r2, [r4, #1]
    adds	r2, #54	@ 0x36
    b .Ljp_08033666
.Ljp_08033662:
    ldrb	r2, [r4, #1]
    adds	r2, #46	@ 0x2e
.Ljp_08033666:
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08033800
    b .Ljp_0803367C
.Ljp_08033670:
    ldrb	r2, [r4, #1]
    adds	r2, #76	@ 0x4c
    adds	r0, r5, #0
    adds	r1, r3, #0
    bl func_08033800
.Ljp_0803367C:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_080338F0
    .thumb_func
func_080338F0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #2
    bl func_080AB1C0
    movs	r1, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #1
    adds	r4, r4, r2
    cmp	r0, r4
    bcs .Ljp_0803369E
    movs	r1, #1
.Ljp_0803369E:
    adds	r0, r1, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.entity_ui_harvest_sprite_task_experience_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08033928
    .thumb_func
func_08033928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    adds	r4, r3, #0
    ldr r1, .Ljp_08033738
    lsls	r0, r6, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    add	r0, sp, #4
    adds	r1, r4, #0
    bl func_080A03B8
    ldr r1, .Ljp_0803373C
    lsls	r0, r6, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    add	r2, sp, #4
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Ljp_08033740
    str	r0, [r7, #20]
    adds	r0, r7, #0
    adds	r0, #48	@ 0x30
    movs	r5, #0
    strb	r6, [r0, #0]
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_080A03D4
    str	r0, [r7, #52]	@ 0x34
    movs	r0, #135	@ 0x87
    lsls	r0, r0, #3
    adds	r4, r4, r0
    str	r4, [r7, #56]	@ 0x38
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [r7, #60]	@ 0x3c
    adds	r0, r7, #0
    adds	r0, #65	@ 0x41
    strb	r5, [r0, #0]
    adds	r0, #1
    strb	r5, [r0, #0]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    mov	r8, r0
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Ljp_0803379C
    lsls	r0, r0, #2
    ldr r1, .Ljp_08033744
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08033738:
    .4byte gUnk_080F149C
.Ljp_0803373C:
    .4byte gUnk_080F14E2
.Ljp_08033740:
    .4byte vtable_unk_080E68C8
.Ljp_08033744:
    .4byte .Ljp_08033748
.Ljp_08033748:
    .4byte .Ljp_0803376C
    .4byte .Ljp_0803379A
    .4byte .Ljp_08033764
    .4byte .Ljp_08033780
    .4byte .Ljp_08033760
    .4byte .Ljp_0803379A
.Ljp_08033760:
    movs	r5, #4
    b .Ljp_0803379C
.Ljp_08033764:
    ldr	r0, [r7, #52]	@ 0x34
    adds	r0, #34	@ 0x22
    ldrb	r5, [r0, #0]
    b .Ljp_0803379C
.Ljp_0803376C:
    add	r4, sp, #12
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_0809E804
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__12AActorEntityRC13ActorLocation
    b .Ljp_0803379C
.Ljp_08033780:
    movs	r5, #1
    ldr	r4, [r7, #52]	@ 0x34
    adds	r0, r4, #0
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    bl func_08033914
    mov	r8, r0
    b .Ljp_0803379C
.Ljp_0803379A:
    movs	r5, #1
.Ljp_0803379C:
    mvns	r1, r5
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    strb	r1, [r0, #0]
    subs	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    mov	r3, r8
    bl func_08034180
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033A2C
    .thumb_func
func_08033A2C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_0803380C
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__3NpcRC13ActorLocation
    ldr r0, .Ljp_08033810
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Ljp_080337F4
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Ljp_080337F4:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Ljp_08033802
    adds	r0, r5, #0
    bl __builtin_delete
.Ljp_08033802:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_0803380C:
    .4byte vtable_unk_080E68C8
.Ljp_08033810:
    .4byte __vt_7AEntity
    .global func_08033A80
    .thumb_func
func_08033A80:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    movs	r0, #212	@ 0xd4
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08034A14
    adds	r5, r0, #0
    movs	r1, #1
    negs	r1, r1
    adds	r4, #64	@ 0x40
    ldrb	r0, [r4, #0]
    cmp	r0, #2
    beq .Ljp_08033838
    cmp	r0, #3
    beq .Ljp_0803383C
    b .Ljp_0803383E
.Ljp_08033838:
    movs	r1, #8
    b .Ljp_08033842
.Ljp_0803383C:
    movs	r1, #5
.Ljp_0803383E:
    cmp	r1, #0
    blt .Ljp_0803386E
.Ljp_08033842:
    adds	r0, r5, #0
    adds	r0, #112	@ 0x70
    bl ResolveIndexedResourceHandle
    adds	r0, r5, #0
    adds	r0, #132	@ 0x84
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r3, r5, #0
    adds	r3, #138	@ 0x8a
    movs	r2, #2
    ldrb	r1, [r3, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r3, #0]
.Ljp_0803386E:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033AE4
    .thumb_func
func_08033AE4:
    push	{lr}
    movs	r1, #0
    strb	r1, [r0, #6]
    adds	r2, r0, #0
    adds	r2, #66	@ 0x42
    movs	r1, #1
    strb	r1, [r2, #0]
    bl func_08033B7C
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08033AFC
    .thumb_func
func_08033AFC:
    ldr r1, .Ljp_080338A0
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Ljp_080338A0:
    .4byte gUnk_080F14D4
    .global func_08033B10
    .thumb_func
func_08033B10:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    ldr	r0, [r4, #52]	@ 0x34
    bl SetChangedLocation__3Npc
    pop	{r4}
    pop	{r0}
    bx	r0

    .section .text.entity_ui_unknown_flag_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08033B84
    .thumb_func
func_08033B84:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Ljp_08033924
    bl func_08034BFC
.Ljp_08033924:
    pop	{r0}
    bx	r0
    .global func_08033B94
    .thumb_func
func_08033B94:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #172	@ 0xac
    adds	r7, r0, #0
    adds	r2, r1, #0
    ldr	r0, [r7, #52]	@ 0x34
    mov	r8, r0
    ldr	r1, [r7, #0]
    mov	sl, r1
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Ljp_0803396C
    lsls	r0, r0, #2
    ldr r1, .Ljp_08033950
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_08033950:
    .4byte .Ljp_08033954
.Ljp_08033954:
    .4byte .Ljp_0803396C
    .4byte .Ljp_080339F8
    .4byte .Ljp_08033A28
    .4byte .Ljp_08033B90
    .4byte .Ljp_08033DE8
    .4byte .Ljp_08033E0C
.Ljp_0803396C:
    ldrb	r0, [r2, #4]
    cmp	r0, #0
    bne .Ljp_08033974
    b .Ljp_08033EA4
.Ljp_08033974:
    mov	r0, r8
    bl GetCurrentTask__C13HarvestSprite
    cmp	r0, #3
    bne .Ljp_08033980
    b .Ljp_08033EA4
.Ljp_08033980:
    mov	r0, r8
    bl GetWorkDaysLeft__C13HarvestSprite
    cmp	r0, #0
    bne .Ljp_0803398C
    b .Ljp_08033EA4
.Ljp_0803398C:
    mov	r2, sl
    ldr	r0, [r2, #0]
    movs	r3, #162	@ 0xa2
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrb	r1, [r2, #10]
    movs	r0, #31
    ands	r0, r1
    cmp	r0, #6
    beq .Ljp_080339AC
    b .Ljp_08033EA4
.Ljp_080339AC:
    ldrh	r0, [r2, #10]
    lsls	r0, r0, #21
    lsrs	r0, r0, #26
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    adds	r1, #1
    cmp	r0, r1
    beq .Ljp_080339C0
    b .Ljp_08033EA4
.Ljp_080339C0:
    ldr	r0, [r2, #0]
    subs	r0, #3
    cmp	r0, #1
    bls .Ljp_080339F0
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #1
    movs	r3, #8
    negs	r3, r3
    adds	r0, r7, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    add	r1, sp, #72	@ 0x48
    mov	r0, r8
    bl method_0809E7D0__13HarvestSprite
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #0
    bl func_08034180
    b .Ljp_08033EA4
.Ljp_080339F0:
    mov	r0, r8
    bl TaskDayUpdate__13HarvestSprite
    b .Ljp_08033EA4
.Ljp_080339F8:
    ldrh	r0, [r7, #4]
    cmp	r0, #2
    beq .Ljp_08033A1C
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #1
    movs	r3, #8
    negs	r3, r3
    adds	r0, r7, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #0
    bl func_08034180
.Ljp_08033A1C:
    movs	r4, #14
    ldrsh	r0, [r7, r4]
    cmp	r0, #119	@ 0x77
    bgt .Ljp_08033A26
    b .Ljp_08033EA4
.Ljp_08033A26:
    b .Ljp_08033DFC
.Ljp_08033A28:
    mov	r5, r8
    adds	r5, #32
    str	r5, [sp, #148]	@ 0x94
    mov	r6, r8
    ldrh	r0, [r6, #32]
    cmp	r0, #0
    beq .Ljp_08033A38
    b .Ljp_08033B88
.Ljp_08033A38:
    adds	r0, r7, #0
    bl func_08034940
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08033A46
    b .Ljp_08033EA4
.Ljp_08033A46:
    ldrb	r0, [r5, #3]
    cmp	r0, #0
    beq .Ljp_08033A56
    subs	r0, #1
    strb	r0, [r5, #3]
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08033A64
.Ljp_08033A56:
    adds	r0, r7, #0
    bl func_08034260
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08033A64
    b .Ljp_08033EA4
.Ljp_08033A64:
    ldr r5, .Ljp_08033AA4
    adds	r0, r5, #0
    movs	r1, #5
    bl func_080AB264
    lsls	r4, r0, #2
    adds	r4, r4, r5
    movs	r6, #0
    ldr	r1, [sp, #148]	@ 0x94
    strb	r0, [r1, #2]
    movs	r5, #60	@ 0x3c
    ldrb	r0, [r4, #2]
    muls	r0, r5
    bl func_080AB1C0
    ldrb	r1, [r4, #1]
    muls	r1, r5
    adds	r1, r1, r0
    ldr	r2, [sp, #148]	@ 0x94
    strh	r1, [r2, #0]
    ldrh	r4, [r7, #4]
    add	r0, sp, #76	@ 0x4c
    strh	r6, [r0, #0]
    strh	r6, [r0, #2]
    mov	r9, r0
    cmp	r4, #17
    beq .Ljp_08033AE6
    cmp	r4, #17
    bgt .Ljp_08033AA8
    cmp	r4, #2
    beq .Ljp_08033AAE
    b .Ljp_08033AFE
.Ljp_08033AA4:
    .4byte gUnk_080F143C
.Ljp_08033AA8:
    cmp	r4, #37	@ 0x25
    beq .Ljp_08033ACC
    b .Ljp_08033AFE
.Ljp_08033AAE:
    movs	r0, #72	@ 0x48
    bl func_080AB1C0
    adds	r0, #128	@ 0x80
    mov	r3, r9
    strh	r0, [r3, #0]
    movs	r0, #72	@ 0x48
    bl func_080AB1C0
    movs	r5, #148	@ 0x94
    lsls	r5, r5, #1
    adds	r0, r0, r5
    mov	r6, r9
    strh	r0, [r6, #2]
    b .Ljp_08033AFE
.Ljp_08033ACC:
    movs	r0, #104	@ 0x68
    bl func_080AB1C0
    adds	r0, #72	@ 0x48
    mov	r1, r9
    strh	r0, [r1, #0]
    movs	r0, #48	@ 0x30
    bl func_080AB1C0
    adds	r0, #96	@ 0x60
    mov	r2, r9
    strh	r0, [r2, #2]
    b .Ljp_08033AFE
.Ljp_08033AE6:
    movs	r0, #64	@ 0x40
    bl func_080AB1C0
    adds	r0, #144	@ 0x90
    mov	r3, r9
    strh	r0, [r3, #0]
    movs	r0, #48	@ 0x30
    bl func_080AB1C0
    adds	r0, #112	@ 0x70
    mov	r5, r9
    strh	r0, [r5, #2]
.Ljp_08033AFE:
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    mov	r8, r0
    mov	r6, sl
    ldr	r1, [r6, #0]
    add	r0, sp, #8
    ldr	r3, [r1, #52]	@ 0x34
    mov	r1, sl
    adds	r2, r4, #0
    bl _call_via_r3
    ldr	r1, [r7, #20]
    add	r0, sp, #80	@ 0x50
    ldr	r2, [r1, #12]
    adds	r1, r7, #0
    bl _call_via_r2
    ldr	r0, [sp, #80]	@ 0x50
    ldr	r1, [sp, #84]	@ 0x54
    str	r0, [sp, #164]	@ 0xa4
    str	r1, [sp, #168]	@ 0xa8
    add	r4, sp, #20
    movs	r1, #32
    mov	sl, r1
    movs	r5, #0
    movs	r1, #33	@ 0x21
    str	r1, [sp, #20]
    movs	r0, #33	@ 0x21
    negs	r0, r0
    str	r0, [r4, #4]
    str	r0, [r4, #8]
    str	r1, [r4, #12]
    add	r1, sp, #40	@ 0x28
    add	r0, sp, #8
    ldmia	r0!, {r2, r3, r6}
    stmia	r1!, {r2, r3, r6}
    ldr	r0, [sp, #164]	@ 0xa4
    ldr	r1, [sp, #168]	@ 0xa8
    str	r0, [sp, #52]	@ 0x34
    str	r1, [sp, #56]	@ 0x38
    mov	r1, sl
    str	r1, [r4, #40]	@ 0x28
    str	r5, [r4, #44]	@ 0x2c
    str	r5, [r4, #48]	@ 0x30
    movs	r2, #10
    ldrsh	r0, [r7, r2]
    movs	r3, #14
    ldrsh	r1, [r7, r3]
    mov	r5, r9
    movs	r6, #0
    ldrsh	r2, [r5, r6]
    add	r3, sp, #76	@ 0x4c
    movs	r5, #2
    ldrsh	r3, [r3, r5]
    str	r4, [sp, #0]
    mov	r6, r8
    str	r6, [sp, #4]
    bl func_080AB678
    adds	r2, r0, #0
    ldr	r0, [sp, #148]	@ 0x94
    ldrb	r1, [r0, #2]
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    bl func_08034180
    b .Ljp_08033EA4
.Ljp_08033B88:
    subs	r0, #1
    mov	r1, r8
    strh	r0, [r1, #32]
    b .Ljp_08033EA4
.Ljp_08033B90:
    mov	r2, r8
    adds	r2, #32
    str	r2, [sp, #152]	@ 0x98
    adds	r4, r7, #0
    adds	r4, #48	@ 0x30
    ldrb	r0, [r4, #0]
    ldr	r1, [r7, #56]	@ 0x38
    lsls	r0, r0, #3
    adds	r1, r1, r0
    mov	r9, r1
    ldr	r1, [r7, #60]	@ 0x3c
    mov	r0, r9
    mov	r2, sl
    bl func_08033784
    adds	r6, r0, #0
    ldrh	r5, [r7, #4]
    movs	r0, #10
    ldrsh	r3, [r7, r0]
    str	r3, [sp, #156]	@ 0x9c
    movs	r2, #14
    ldrsh	r1, [r7, r2]
    str	r1, [sp, #160]	@ 0xa0
    add	r0, sp, #88	@ 0x58
    strh	r3, [r0, #0]
    strh	r1, [r0, #2]
    cmp	r6, r5
    bne .Ljp_08033BDA
    ldr	r2, [r7, #60]	@ 0x3c
    add	r0, sp, #92	@ 0x5c
    mov	r1, r9
    mov	r3, sl
    bl func_08033830
    ldr	r0, [sp, #92]	@ 0x5c
    str	r0, [sp, #88]	@ 0x58
    b .Ljp_08033C2A
.Ljp_08033BDA:
    cmp	r5, #17
    beq .Ljp_08033C1A
    cmp	r5, #17
    bgt .Ljp_08033BE8
    cmp	r5, #2
    beq .Ljp_08033BEE
    b .Ljp_08033C26
.Ljp_08033BE8:
    cmp	r5, #37	@ 0x25
    beq .Ljp_08033C0E
    b .Ljp_08033C26
.Ljp_08033BEE:
    cmp	r6, #17
    beq .Ljp_08033C02
    cmp	r6, #37	@ 0x25
    bne .Ljp_08033C26
    add	r0, sp, #96	@ 0x60
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #96]	@ 0x60
    str	r0, [sp, #88]	@ 0x58
    b .Ljp_08033C2A
.Ljp_08033C02:
    add	r0, sp, #100	@ 0x64
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #100]	@ 0x64
    str	r0, [sp, #88]	@ 0x58
    b .Ljp_08033C2A
.Ljp_08033C0E:
    add	r0, sp, #104	@ 0x68
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #104]	@ 0x68
    str	r0, [sp, #88]	@ 0x58
    b .Ljp_08033C2A
.Ljp_08033C1A:
    add	r0, sp, #108	@ 0x6c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #108]	@ 0x6c
    str	r0, [sp, #88]	@ 0x58
    b .Ljp_08033C2A
.Ljp_08033C26:
    movs	r6, #141	@ 0x8d
    lsls	r6, r6, #2
.Ljp_08033C2A:
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    cmp	r6, r0
    beq .Ljp_08033D22
    add	r3, sp, #88	@ 0x58
    movs	r2, #0
    ldrsh	r0, [r3, r2]
    ldr	r1, [sp, #156]	@ 0x9c
    subs	r0, r0, r1
    cmp	r0, #0
    bge .Ljp_08033C42
    negs	r0, r0
.Ljp_08033C42:
    cmp	r0, #7
    bgt .Ljp_08033D22
    movs	r3, #90	@ 0x5a
    add	r3, sp
    movs	r2, #0
    ldrsh	r0, [r3, r2]
    ldr	r1, [sp, #160]	@ 0xa0
    subs	r0, r0, r1
    cmp	r0, #0
    bge .Ljp_08033C58
    negs	r0, r0
.Ljp_08033C58:
    cmp	r0, #7
    bgt .Ljp_08033D22
    adds	r0, r7, #0
    bl func_08034940
    lsls	r0, r0, #24
    lsrs	r1, r0, #24
    cmp	r1, #0
    beq .Ljp_08033C6C
    b .Ljp_08033EA4
.Ljp_08033C6C:
    cmp	r6, r5
    bne .Ljp_08033CA4
    adds	r0, r7, #0
    bl func_0803436C
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08033C7E
    b .Ljp_08033DFC
.Ljp_08033C7E:
    ldr r1, .Ljp_08033CA0
    ldr	r0, [sp, #112]	@ 0x70
    ands	r0, r1
    movs	r1, #60	@ 0x3c
    orrs	r0, r1
    str	r0, [sp, #112]	@ 0x70
    add	r1, sp, #112	@ 0x70
    mov	r0, r8
    bl method_0809E7F0__13HarvestSpritePC15UnkBarnAnimal2C
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #4
    b .Ljp_08033E66
    .align 2, 0
.Ljp_08033CA0:
    .4byte 0xFFFF0000
.Ljp_08033CA4:
    movs	r4, #2
    add	r0, sp, #116	@ 0x74
    strh	r1, [r0, #0]
    strh	r1, [r0, #2]
    mov	r8, r0
    cmp	r5, #17
    beq .Ljp_08033CEC
    cmp	r5, #17
    bgt .Ljp_08033CBC
    cmp	r5, #2
    beq .Ljp_08033CC2
    b .Ljp_08033CF6
.Ljp_08033CBC:
    cmp	r5, #37	@ 0x25
    beq .Ljp_08033CE2
    b .Ljp_08033CF6
.Ljp_08033CC2:
    cmp	r6, #17
    beq .Ljp_08033CD6
    cmp	r6, #37	@ 0x25
    bne .Ljp_08033CF6
    movs	r4, #37	@ 0x25
    add	r0, sp, #120	@ 0x78
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #120]	@ 0x78
    b .Ljp_08033CF4
.Ljp_08033CD6:
    movs	r4, #17
    add	r0, sp, #124	@ 0x7c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #124]	@ 0x7c
    b .Ljp_08033CF4
.Ljp_08033CE2:
    add	r0, sp, #128	@ 0x80
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #128]	@ 0x80
    b .Ljp_08033CF4
.Ljp_08033CEC:
    add	r0, sp, #132	@ 0x84
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #132]	@ 0x84
.Ljp_08033CF4:
    str	r0, [sp, #116]	@ 0x74
.Ljp_08033CF6:
    mov	r3, r8
    movs	r5, #0
    ldrsh	r2, [r3, r5]
    add	r0, sp, #116	@ 0x74
    movs	r6, #2
    ldrsh	r3, [r0, r6]
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl SetLocation__7AEntityUiii
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
    movs	r3, #0
    bl func_08034180
    movs	r0, #0
    ldr	r1, [sp, #152]	@ 0x98
    strh	r0, [r1, #0]
    b .Ljp_08033EA4
.Ljp_08033D22:
    ldr	r2, [sp, #152]	@ 0x98
    ldrh	r0, [r2, #0]
    cmp	r0, #0
    bne .Ljp_08033DE0
    adds	r0, r7, #0
    bl func_08034940
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08033D38
    b .Ljp_08033EA4
.Ljp_08033D38:
    ldrb	r1, [r4, #0]
    ldr	r0, [r7, #56]	@ 0x38
    lsls	r1, r1, #3
    adds	r0, r0, r1
    ldr	r1, [r7, #60]	@ 0x3c
    mov	r2, sl
    bl func_08033584
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08033DFC
    mov	r0, r8
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    mov	r0, r8
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    bl func_08033914
    adds	r6, r0, #0
    add	r4, sp, #88	@ 0x58
    movs	r3, #0
    ldrsh	r1, [r4, r3]
    adds	r5, r4, #0
    movs	r2, #2
    ldrsh	r0, [r5, r2]
    ldr	r3, [sp, #160]	@ 0xa0
    subs	r0, r0, r3
    ldr	r4, [sp, #156]	@ 0x9c
    subs	r1, r1, r4
    cmp	r1, #0
    bge .Ljp_08033D7C
    negs	r1, r1
.Ljp_08033D7C:
    cmp	r0, #0
    bge .Ljp_08033D82
    negs	r0, r0
.Ljp_08033D82:
    adds	r0, r1, r0
    lsrs	r1, r0, #31
    adds	r0, r0, r1
    asrs	r0, r0, #1
    lsls	r0, r0, #16
    adds	r1, r6, #0
    bl __divsi3
    add	r3, sp, #140	@ 0x8c
    str	r0, [r3, #0]
    movs	r2, #180	@ 0xb4
    add	r0, sp, #136	@ 0x88
    str	r2, [r0, #0]
    ldr	r1, [r3, #0]
    cmp	r2, r1
    bls .Ljp_08033DA4
    adds	r0, r3, #0
.Ljp_08033DA4:
    ldr	r0, [r0, #0]
    bl func_080AB1C0
    ldr	r1, [sp, #152]	@ 0x98
    strh	r0, [r1, #0]
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r4, [r0, #0]
    add	r0, sp, #8
    bl func_080AB474
    add	r0, sp, #88	@ 0x58
    movs	r3, #0
    ldrsh	r2, [r0, r3]
    movs	r1, #2
    ldrsh	r3, [r5, r1]
    add	r5, sp, #8
    str	r5, [sp, #0]
    str	r4, [sp, #4]
    ldr	r0, [sp, #156]	@ 0x9c
    ldr	r1, [sp, #160]	@ 0xa0
    bl func_080AB678
    adds	r2, r0, #0
    adds	r0, r7, #0
    movs	r1, #1
    adds	r3, r6, #0
    bl func_08034180
    b .Ljp_08033EA4
.Ljp_08033DE0:
    subs	r0, #1
    ldr	r6, [sp, #152]	@ 0x98
    strh	r0, [r6, #0]
    b .Ljp_08033EA4
.Ljp_08033DE8:
    mov	r1, r8
    ldrh	r0, [r1, #32]
    cmp	r0, #0
    bne .Ljp_08033E04
    adds	r0, r7, #0
    bl func_08034940
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08033EA4
.Ljp_08033DFC:
    adds	r0, r7, #0
    bl func_080342D8
    b .Ljp_08033EA4
.Ljp_08033E04:
    subs	r0, #1
    mov	r2, r8
    strh	r0, [r2, #32]
    b .Ljp_08033EA4
.Ljp_08033E0C:
    movs	r3, #10
    ldrsh	r1, [r7, r3]
    movs	r0, #180	@ 0xb4
    lsls	r0, r0, #1
    cmp	r1, r0
    bne .Ljp_08033E6E
    ldr	r0, [r7, #28]
    cmp	r0, #0
    blt .Ljp_08033E2E
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #1
    bl func_08034180
    b .Ljp_08033EA4
.Ljp_08033E2E:
    movs	r4, #14
    ldrsh	r1, [r7, r4]
    movs	r0, #8
    negs	r0, r0
    cmp	r1, r0
    bgt .Ljp_08033EA4
    mov	r0, r8
    bl TaskDayUpdate__13HarvestSprite
    add	r1, sp, #144	@ 0x90
    mov	r0, r8
    bl method_0809E7C8__13HarvestSprite
    adds	r0, r7, #0
    adds	r0, #48	@ 0x30
    ldrb	r1, [r0, #0]
    add	r0, sp, #8
    bl func_0809E804
    adds	r0, r7, #0
    add	r1, sp, #8
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds	r0, r7, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #0
.Ljp_08033E66:
    movs	r3, #0
    bl func_08034180
    b .Ljp_08033EA4
.Ljp_08033E6E:
    ldr	r2, [r7, #24]
    movs	r3, #0
    ldr r0, .Ljp_08033E88
    cmp	r1, r0
    bgt .Ljp_08033E7A
    movs	r3, #1
.Ljp_08033E7A:
    adds	r0, r3, #0
    cmp	r0, #0
    beq .Ljp_08033E8C
    cmp	r2, #0
    ble .Ljp_08033E90
    b .Ljp_08033EA4
    .align 2, 0
.Ljp_08033E88:
    .4byte 0x00000167
.Ljp_08033E8C:
    cmp	r2, #0
    blt .Ljp_08033EA4
.Ljp_08033E90:
    movs	r2, #2
    cmp	r0, #0
    beq .Ljp_08033E98
    movs	r2, #3
.Ljp_08033E98:
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    bl func_08034180
.Ljp_08033EA4:
    adds	r4, r7, #0
    adds	r4, #66	@ 0x42
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Ljp_08033ECC
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    ldrb	r1, [r0, #0]
    adds	r0, r7, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08033EC8
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08033EC8:
    movs	r0, #0
    strb	r0, [r4, #0]
.Ljp_08033ECC:
    ldr	r1, [r7, #28]
    cmp	r1, #0
    beq .Ljp_08033ED8
    ldr	r0, [r7, #12]
    adds	r0, r0, r1
    str	r0, [r7, #12]
.Ljp_08033ED8:
    ldr	r1, [r7, #24]
    cmp	r1, #0
    beq .Ljp_08033EE4
    ldr	r0, [r7, #8]
    adds	r0, r0, r1
    str	r0, [r7, #8]
.Ljp_08033EE4:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Ljp_08033EEE
    subs	r0, #1
    b .Ljp_08033EF0
.Ljp_08033EEE:
    ldrh	r0, [r7, #38]	@ 0x26
.Ljp_08033EF0:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r4, [r7, #16]
    cmp	r4, #0
    beq .Ljp_08033F02
    ldr	r0, [r4, #4]
    ldr	r1, [r0, #12]
    adds	r0, r4, #0
    bl _call_via_r1
.Ljp_08033F02:
    add	sp, #172	@ 0xac
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034180
    .thumb_func
func_08034180:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r7, r1, #0
    adds	r5, r2, #0
    adds	r6, r3, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Ljp_08033F30
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Ljp_08033F30:
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r5
    beq .Ljp_08033F42
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Ljp_08033F42:
    adds	r0, r4, #0
    adds	r0, #66	@ 0x42
    movs	r1, #0
    strb	r1, [r0, #0]
    cmp	r7, #1
    beq .Ljp_08033F64
    cmp	r7, #1
    bgt .Ljp_08033F58
    cmp	r7, #0
    beq .Ljp_08033F5C
    b .Ljp_08033F9E
.Ljp_08033F58:
    cmp	r7, #4
    bgt .Ljp_08033F9E
.Ljp_08033F5C:
    movs	r0, #0
    str	r0, [r4, #24]
    str	r0, [r4, #28]
    b .Ljp_08033F9E
.Ljp_08033F64:
    adds	r0, r6, #0
    cmp	r6, #0
    bge .Ljp_08033F6C
    negs	r0, r6
.Ljp_08033F6C:
    adds	r6, r0, #0
    cmp	r5, #1
    beq .Ljp_08033F8C
    cmp	r5, #1
    bgt .Ljp_08033F7C
    cmp	r5, #0
    beq .Ljp_08033F86
    b .Ljp_08033F9E
.Ljp_08033F7C:
    cmp	r5, #2
    beq .Ljp_08033F94
    cmp	r5, #3
    beq .Ljp_08033F9A
    b .Ljp_08033F9E
.Ljp_08033F86:
    str	r6, [r4, #28]
    str	r1, [r4, #24]
    b .Ljp_08033F9E
.Ljp_08033F8C:
    negs	r0, r6
    str	r0, [r4, #28]
    str	r1, [r4, #24]
    b .Ljp_08033F9E
.Ljp_08033F94:
    negs	r0, r6
    str	r0, [r4, #24]
    b .Ljp_08033F9C
.Ljp_08033F9A:
    str	r6, [r4, #24]
.Ljp_08033F9C:
    str	r1, [r4, #28]
.Ljp_08033F9E:
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    adds	r5, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r7, r0
    beq .Ljp_08033FD2
    movs	r1, #1
    negs	r1, r1
    cmp	r7, #2
    beq .Ljp_08033FB8
    cmp	r7, #3
    beq .Ljp_08033FBC
    b .Ljp_08033FBE
.Ljp_08033FB8:
    movs	r1, #8
    b .Ljp_08033FC2
.Ljp_08033FBC:
    movs	r1, #5
.Ljp_08033FBE:
    cmp	r1, #0
    blt .Ljp_08033FCC
.Ljp_08033FC2:
    adds	r0, r4, #0
    movs	r2, #1
    bl func_08032384
    b .Ljp_08033FD2
.Ljp_08033FCC:
    adds	r0, r4, #0
    bl func_080323C8
.Ljp_08033FD2:
    strb	r7, [r5, #0]
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.entity_ui_animation_lookup_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08034260
    .thumb_func
func_08034260:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #28
    adds	r6, r0, #0
    adds	r7, r6, #0
    adds	r7, #65	@ 0x41
    ldrb	r0, [r7, #0]
    cmp	r0, #0
    beq .Ljp_08034008
    movs	r0, #0
    b .Ljp_0803405E
.Ljp_08034008:
    ldr	r5, [r6, #0]
    add	r4, sp, #16
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #52]	@ 0x34
    bl GetCurrentTask__C13HarvestSprite
    ldr	r1, [r6, #60]	@ 0x3c
    str	r0, [sp, #0]
    ldr	r0, [r6, #56]	@ 0x38
    str	r0, [sp, #4]
    add	r0, sp, #8
    adds	r2, r5, #0
    adds	r3, r4, #0
    bl func_080330F4
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_0803403E
    movs	r0, #1
    strb	r0, [r7, #0]
    movs	r0, #0
    b .Ljp_0803405E
.Ljp_0803403E:
    ldr	r0, [r6, #56]	@ 0x38
    adds	r1, r6, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    add	r2, sp, #8
    bl func_0809E988
    ldr r1, .Ljp_08034068
    ldr	r0, [sp, #24]
    ands	r0, r1
    str	r0, [sp, #24]
    ldr	r0, [r6, #52]	@ 0x34
    add	r1, sp, #24
    bl method_0809E7E4__13HarvestSpritePC15UnkBarnAnimal2C
    movs	r0, #1
.Ljp_0803405E:
    add	sp, #28
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_08034068:
    .4byte 0xFFFF0000
    .global func_080342D8
    .thumb_func
func_080342D8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    bl GetFriendship__C3Npc
    bl func_080338F0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803408E
    adds	r0, r5, #0
    bl func_08034260
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_080340EA
.Ljp_0803408E:
    movs	r0, #180	@ 0xb4
    bl func_080AB1C0
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Ljp_080340F4
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Ljp_080340F8
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r4, [r5, #52]	@ 0x34
    adds	r0, r4, #0
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    adds	r1, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    subs	r0, r0, r1
    bl func_080AB1C0
    lsrs	r0, r0, #6
    adds	r0, #2
    lsls	r0, r0, #24
    ldr r2, .Ljp_080340FC
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r1, sp
    bl method_0809E7D8__13HarvestSpritePC15UnkBarnAnimal2C
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r5, #0
    movs	r1, #0
    movs	r3, #0
    bl func_08034180
.Ljp_080340EA:
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_080340F4:
    .4byte 0xFFFF0000
.Ljp_080340F8:
    .4byte 0xFF00FFFF
.Ljp_080340FC:
    .4byte 0x00FFFFFF
    .global func_0803436C
    .thumb_func
func_0803436C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    str	r0, [sp, #36]	@ 0x24
    ldr	r0, [r0, #0]
    str	r0, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    adds	r3, #48	@ 0x30
    ldrb	r1, [r3, #0]
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #56]	@ 0x38
    lsls	r1, r1, #3
    mov	r2, sp
    adds	r1, r0, r1
    ldmia	r1!, {r4, r5}
    stmia	r2!, {r4, r5}
    ldrb	r1, [r3, #0]
    bl func_0809E994
    ldr	r0, [sp, #36]	@ 0x24
    ldr	r1, [r0, #60]	@ 0x3c
    mov	r0, sp
    ldr	r2, [sp, #40]	@ 0x28
    bl func_08033584
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_08034140
    b .Ljp_0803468E
.Ljp_08034140:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r5, [r1, #16]
    cmp	r5, #0
    beq .Ljp_080341AE
    ldr	r2, [r1, #60]	@ 0x3c
    add	r4, sp, #24
    adds	r0, r4, #0
    mov	r1, sp
    ldr	r3, [sp, #40]	@ 0x28
    bl func_08033830
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    beq .Ljp_08034178
    cmp	r0, #4
    bgt .Ljp_0803416C
    cmp	r0, #3
    beq .Ljp_08034172
    b .Ljp_08034198
.Ljp_0803416C:
    cmp	r0, #5
    beq .Ljp_08034192
    b .Ljp_08034198
.Ljp_08034172:
    ldrh	r0, [r4, #2]
    subs	r0, #24
    b .Ljp_08034196
.Ljp_08034178:
    movs	r0, #2
    ldrsh	r2, [r4, r0]
    mov	r0, sp
    ldrb	r0, [r0, #1]
    movs	r1, #7
    ands	r0, r1
    adds	r1, r2, #0
    adds	r1, #24
    cmp	r0, #3
    bhi .Ljp_0803418E
    subs	r1, #56	@ 0x38
.Ljp_0803418E:
    strh	r1, [r4, #2]
    b .Ljp_08034198
.Ljp_08034192:
    ldrh	r0, [r4, #2]
    subs	r0, #40	@ 0x28
.Ljp_08034196:
    strh	r0, [r4, #2]
.Ljp_08034198:
    ldr	r0, [sp, #36]	@ 0x24
    adds	r0, #48	@ 0x30
    ldrb	r1, [r0, #0]
    movs	r0, #0
    ldrsh	r2, [r4, r0]
    add	r0, sp, #24
    movs	r4, #2
    ldrsh	r3, [r0, r4]
    adds	r0, r5, #0
    bl func_08034BFC
.Ljp_080341AE:
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bls .Ljp_080341BC
    b .Ljp_0803468E
.Ljp_080341BC:
    lsls	r0, r0, #2
    ldr r1, .Ljp_080341C8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_080341C8:
    .4byte .Ljp_080341CC
.Ljp_080341CC:
    .4byte .Ljp_0803468E
    .4byte .Ljp_080341F0
    .4byte .Ljp_08034278
    .4byte .Ljp_0803437E
    .4byte .Ljp_080343AA
    .4byte .Ljp_080343D8
    .4byte .Ljp_08034414
    .4byte .Ljp_08034580
    .4byte .Ljp_080345C8
.Ljp_080341F0:
    ldr	r5, [sp, #40]	@ 0x28
    ldr	r5, [r5, #0]
    mov	r9, r5
    movs	r0, #216	@ 0xd8
    add	r9, r0
    ldr	r1, [sp, #36]	@ 0x24
    movs	r2, #10
    ldrsh	r6, [r1, r2]
    movs	r5, #14
    ldrsh	r4, [r1, r5]
    mov	r8, r4
    add	r4, sp, #8
    movs	r2, #2
    ldrh	r1, [r4, #0]
    ldr r3, .Ljp_08034274
    adds	r0, r3, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r4, #0]
    lsls	r6, r6, #16
    lsrs	r1, r6, #16
    movs	r0, #63	@ 0x3f
    mov	sl, r0
    ands	r1, r0
    lsls	r1, r1, #2
    ldrb	r5, [r4, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r5
    orrs	r0, r1
    strb	r0, [r4, #1]
    lsrs	r6, r6, #22
    ldrh	r1, [r4, #2]
    adds	r0, r3, #0
    ands	r0, r1
    orrs	r0, r6
    strh	r0, [r4, #2]
    mov	r1, r8
    lsls	r1, r1, #16
    mov	r8, r1
    lsrs	r0, r1, #16
    mov	r5, sl
    ands	r0, r5
    lsls	r0, r0, #2
    ldrb	r1, [r4, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r4, #3]
    mov	r0, r8
    lsrs	r0, r0, #22
    mov	r8, r0
    ldrh	r0, [r4, #4]
    ands	r3, r0
    mov	r1, r8
    orrs	r3, r1
    strh	r3, [r4, #4]
    mov	r5, r9
    ldr	r2, [r5, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r4, #0
    bl _call_via_r2
    movs	r6, #1
    mov	r8, r4
    b .Ljp_08034692
    .align 2, 0
.Ljp_08034274:
    .4byte 0xFFFFFC00
.Ljp_08034278:
    add	r0, sp, #8
    mov	r9, r0
    bl __12RucksackItem
    ldr	r1, [sp, #40]	@ 0x28
    ldr	r1, [r1, #0]
    mov	r8, r1
    movs	r2, #224	@ 0xe0
    add	r8, r2
    ldr	r4, [sp, #36]	@ 0x24
    movs	r0, #10
    ldrsh	r5, [r4, r0]
    movs	r1, #14
    ldrsh	r6, [r4, r1]
    add	r7, sp, #16
    movs	r2, #2
    ldrh	r1, [r7, #0]
    ldr r3, .Ljp_08034314
    adds	r0, r3, #0
    ands	r0, r1
    orrs	r0, r2
    strh	r0, [r7, #0]
    lsls	r5, r5, #16
    lsrs	r1, r5, #16
    movs	r2, #63	@ 0x3f
    mov	sl, r2
    ands	r1, r2
    lsls	r1, r1, #2
    ldrb	r4, [r7, #1]
    movs	r2, #3
    adds	r0, r2, #0
    ands	r0, r4
    orrs	r0, r1
    strb	r0, [r7, #1]
    lsrs	r5, r5, #22
    ldrh	r1, [r7, #2]
    adds	r0, r3, #0
    ands	r0, r1
    orrs	r0, r5
    strh	r0, [r7, #2]
    lsls	r6, r6, #16
    lsrs	r0, r6, #16
    mov	r4, sl
    ands	r0, r4
    lsls	r0, r0, #2
    ldrb	r1, [r7, #3]
    ands	r2, r1
    orrs	r2, r0
    strb	r2, [r7, #3]
    lsrs	r6, r6, #22
    ldrh	r0, [r7, #4]
    ands	r3, r0
    orrs	r3, r6
    strh	r3, [r7, #4]
    mov	r5, r8
    ldr	r3, [r5, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r7, #0
    mov	r2, r9
    bl _call_via_r3
    mov	r0, r9
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    mov	r8, r9
    cmp	r0, #0
    beq .Ljp_08034302
    b .Ljp_0803468E
.Ljp_08034302:
    mov	r0, r8
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Ljp_08034318
    cmp	r0, #1
    beq .Ljp_08034354
    b .Ljp_0803468E
    .align 2, 0
.Ljp_08034314:
    .4byte 0xFFFFFC00
.Ljp_08034318:
    ldr	r0, [sp, #40]	@ 0x28
    ldr	r4, [r0, #0]
    movs	r1, #174	@ 0xae
    lsls	r1, r1, #1
    adds	r4, r4, r1
    add	r5, sp, #28
    adds	r0, r7, #0
    mov	r1, r8
    bl GetFood__C12RucksackItem
    ldrb	r1, [r7, #0]
    mov	r0, sp
    adds	r0, #17
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #18
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    adds	r0, r5, #0
    bl __7ProductG4Food
    ldr	r2, [r4, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r5, #0
    bl _call_via_r2
    b .Ljp_0803437A
.Ljp_08034354:
    ldr	r2, [sp, #40]	@ 0x28
    ldr	r4, [r2, #0]
    movs	r5, #174	@ 0xae
    lsls	r5, r5, #1
    adds	r4, r4, r5
    mov	r5, sp
    adds	r5, #29
    mov	r0, r8
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r5, #0
    bl __7ProductG7Article
    ldr	r2, [r4, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r5, #0
    bl _call_via_r2
.Ljp_0803437A:
    movs	r6, #0
    b .Ljp_08034692
.Ljp_0803437E:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r0, [r1, #60]	@ 0x3c
    movs	r4, #255	@ 0xff
    lsls	r4, r4, #2
    adds	r0, r0, r4
    movs	r1, #1
    bl SubtractStoredBushels__4CoopUi
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #60]	@ 0x3c
    adds	r0, r0, r4
    mov	r1, sp
    ldrb	r1, [r1, #1]
    bl SetEntBushel__4CoopUi
    ldr	r4, [sp, #40]	@ 0x28
    ldr	r0, [r4, #0]
    adds	r0, #160	@ 0xa0
    mov	r1, sp
    ldrb	r1, [r1, #1]
    ldr	r2, [r0, #0]
    b .Ljp_08034402
.Ljp_080343AA:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r0, [r1, #60]	@ 0x3c
    ldr r4, .Ljp_080343D4
    adds	r0, r0, r4
    movs	r1, #1
    bl SubtractStoredBushels__4BarnUi
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #60]	@ 0x3c
    adds	r0, r0, r4
    mov	r1, sp
    ldrb	r1, [r1, #1]
    bl SetBushelForStall__4BarnUi
    ldr	r4, [sp, #40]	@ 0x28
    ldr	r0, [r4, #0]
    adds	r0, #156	@ 0x9c
    mov	r1, sp
    ldrb	r1, [r1, #1]
    ldr	r2, [r0, #0]
    b .Ljp_08034402
.Ljp_080343D4:
    .4byte 0x000005DC
.Ljp_080343D8:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r0, [r1, #60]	@ 0x3c
    ldr r4, .Ljp_08034410
    adds	r0, r0, r4
    movs	r1, #1
    bl SubtractStoredBushels__4BarnUi
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #60]	@ 0x3c
    adds	r0, r0, r4
    mov	r1, sp
    ldrb	r1, [r1, #1]
    bl SetBushelForPregnancyStall__4BarnUi
    ldr	r4, [sp, #40]	@ 0x28
    ldr	r2, [r4, #0]
    adds	r2, #156	@ 0x9c
    mov	r0, sp
    ldrb	r1, [r0, #1]
    adds	r1, #16
    ldr	r2, [r2, #0]
.Ljp_08034402:
    adds	r0, r4, #0
    bl _call_via_r2
    movs	r6, #2
    add	r5, sp, #8
    mov	r8, r5
    b .Ljp_08034692
.Ljp_08034410:
    .4byte 0x000005DC
.Ljp_08034414:
    mov	r0, sp
    ldrb	r1, [r0, #1]
    adds	r1, #54	@ 0x36
    ldr	r2, [sp, #40]	@ 0x28
    ldr	r0, [r2, #0]
    ldr	r2, [r0, #64]	@ 0x40
    ldr	r0, [sp, #40]	@ 0x28
    bl _call_via_r2
    adds	r7, r0, #0
    cmp	r7, #0
    bne .Ljp_0803442E
    b .Ljp_0803468E
.Ljp_0803442E:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #80]	@ 0x50
    adds	r0, r7, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_08034448
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r7, #0
    bl _call_via_r1
.Ljp_08034448:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #84]	@ 0x54
    adds	r0, r7, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    add	r4, sp, #8
    mov	r8, r4
    cmp	r0, #0
    beq .Ljp_080344E8
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #116]	@ 0x74
    adds	r0, r7, #0
    bl _call_via_r1
    movs	r1, #28
    cmp	r0, #5
    bhi .Ljp_080344AA
    lsls	r0, r0, #2
    ldr r1, .Ljp_08034478
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08034478:
    .4byte .Ljp_0803447C
.Ljp_0803447C:
    .4byte .Ljp_08034494
    .4byte .Ljp_08034498
    .4byte .Ljp_0803449C
    .4byte .Ljp_080344A0
    .4byte .Ljp_080344A4
    .4byte .Ljp_080344A8
.Ljp_08034494:
    movs	r1, #28
    b .Ljp_080344AA
.Ljp_08034498:
    movs	r1, #29
    b .Ljp_080344AA
.Ljp_0803449C:
    movs	r1, #30
    b .Ljp_080344AA
.Ljp_080344A0:
    movs	r1, #31
    b .Ljp_080344AA
.Ljp_080344A4:
    movs	r1, #32
    b .Ljp_080344AA
.Ljp_080344A8:
    movs	r1, #33	@ 0x21
.Ljp_080344AA:
    ldr	r5, [sp, #40]	@ 0x28
    ldr	r4, [r5, #0]
    movs	r0, #174	@ 0xae
    lsls	r0, r0, #1
    adds	r4, r4, r0
    mov	r6, sp
    adds	r6, #30
    add	r5, sp, #8
    adds	r0, r5, #0
    bl __4FoodUi
    ldrb	r1, [r5, #0]
    mov	r0, sp
    adds	r0, #9
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #10
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    adds	r0, r6, #0
    bl __7ProductG4Food
    ldr	r2, [r4, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r6, #0
    bl _call_via_r2
    mov	r8, r5
.Ljp_080344E8:
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r7, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803456E
    ldr	r0, [r7, #20]
    ldr	r1, [r0, #120]	@ 0x78
    adds	r0, r7, #0
    bl _call_via_r1
    movs	r1, #5
    cmp	r0, #5
    bhi .Ljp_08034546
    lsls	r0, r0, #2
    ldr r1, .Ljp_08034514
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_08034514:
    .4byte .Ljp_08034518
.Ljp_08034518:
    .4byte .Ljp_08034530
    .4byte .Ljp_08034534
    .4byte .Ljp_08034538
    .4byte .Ljp_0803453C
    .4byte .Ljp_08034540
    .4byte .Ljp_08034544
.Ljp_08034530:
    movs	r1, #5
    b .Ljp_08034546
.Ljp_08034534:
    movs	r1, #6
    b .Ljp_08034546
.Ljp_08034538:
    movs	r1, #7
    b .Ljp_08034546
.Ljp_0803453C:
    movs	r1, #8
    b .Ljp_08034546
.Ljp_08034540:
    movs	r1, #9
    b .Ljp_08034546
.Ljp_08034544:
    movs	r1, #10
.Ljp_08034546:
    ldr	r2, [sp, #40]	@ 0x28
    ldr	r5, [r2, #0]
    movs	r4, #174	@ 0xae
    lsls	r4, r4, #1
    adds	r5, r5, r4
    mov	r6, sp
    adds	r6, #31
    add	r4, sp, #32
    adds	r0, r4, #0
    bl __7ArticleUi
    ldrb	r1, [r4, #0]
    adds	r0, r6, #0
    bl __7ProductG7Article
    ldr	r2, [r5, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r6, #0
    bl _call_via_r2
.Ljp_0803456E:
    ldr	r0, [r7, #20]
    adds	r0, #136	@ 0x88
    ldr	r2, [r0, #0]
    adds	r0, r7, #0
    movs	r1, #60	@ 0x3c
    bl _call_via_r2
    movs	r6, #2
    b .Ljp_08034692
.Ljp_08034580:
    mov	r0, sp
    ldrb	r1, [r0, #1]
    adds	r1, #46	@ 0x2e
    ldr	r5, [sp, #40]	@ 0x28
    ldr	r0, [r5, #0]
    ldr	r2, [r0, #64]	@ 0x40
    adds	r0, r5, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Ljp_0803468E
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #80]	@ 0x50
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_080345B2
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #112]	@ 0x70
    adds	r0, r4, #0
    bl _call_via_r1
.Ljp_080345B2:
    ldr	r0, [r4, #20]
    adds	r0, #136	@ 0x88
    ldr	r2, [r0, #0]
    adds	r0, r4, #0
    movs	r1, #60	@ 0x3c
    bl _call_via_r2
    movs	r6, #2
    add	r0, sp, #8
    mov	r8, r0
    b .Ljp_08034692
.Ljp_080345C8:
    mov	r0, sp
    ldrb	r1, [r0, #1]
    adds	r4, r1, #0
    adds	r4, #76	@ 0x4c
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #60]	@ 0x3c
    movs	r5, #255	@ 0xff
    lsls	r5, r5, #2
    adds	r0, r0, r5
    bl GetEgg__C4CoopUi
    cmp	r0, #0
    beq .Ljp_0803468E
    ldrb	r0, [r0, #6]
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    movs	r7, #15
    cmp	r0, #5
    bhi .Ljp_0803462A
    lsls	r0, r0, #2
    ldr r1, .Ljp_080345F8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_080345F8:
    .4byte .Ljp_080345FC
.Ljp_080345FC:
    .4byte .Ljp_08034614
    .4byte .Ljp_08034618
    .4byte .Ljp_0803461C
    .4byte .Ljp_08034620
    .4byte .Ljp_08034624
    .4byte .Ljp_08034628
.Ljp_08034614:
    movs	r7, #15
    b .Ljp_0803462A
.Ljp_08034618:
    movs	r7, #16
    b .Ljp_0803462A
.Ljp_0803461C:
    movs	r7, #17
    b .Ljp_0803462A
.Ljp_08034620:
    movs	r7, #18
    b .Ljp_0803462A
.Ljp_08034624:
    movs	r7, #19
    b .Ljp_0803462A
.Ljp_08034628:
    movs	r7, #20
.Ljp_0803462A:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r0, [r1, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #60]	@ 0x3c
    adds	r1, r4, #0
    bl _call_via_r2
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #60]	@ 0x3c
    movs	r4, #255	@ 0xff
    lsls	r4, r4, #2
    adds	r0, r0, r4
    mov	r1, sp
    ldrb	r1, [r1, #1]
    bl method_0800C9B8__4CoopUi
    ldr	r5, [sp, #40]	@ 0x28
    ldr	r4, [r5, #0]
    movs	r0, #174	@ 0xae
    lsls	r0, r0, #1
    adds	r4, r4, r0
    mov	r6, sp
    adds	r6, #33	@ 0x21
    add	r5, sp, #8
    adds	r0, r5, #0
    adds	r1, r7, #0
    bl __4FoodUi
    ldrb	r1, [r5, #0]
    mov	r0, sp
    adds	r0, #9
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #10
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    adds	r0, r6, #0
    bl __7ProductG4Food
    ldr	r2, [r4, #0]
    ldr	r0, [sp, #40]	@ 0x28
    adds	r1, r6, #0
    bl _call_via_r2
    movs	r6, #2
    mov	r8, r5
    b .Ljp_08034692
.Ljp_0803468E:
    movs	r0, #0
    b .Ljp_080346BE
.Ljp_08034692:
    ldr r1, .Ljp_080346D0
    mov	r0, r8
    movs	r2, #3
    bl memcpy
    cmp	r6, #3
    beq .Ljp_080346BC
    movs	r0, #200	@ 0xc8
    bl func_080AB1C0
    mov	r2, r8
    adds	r1, r2, r6
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bcs .Ljp_080346BC
    ldr	r4, [sp, #36]	@ 0x24
    ldr	r0, [r4, #52]	@ 0x34
    adds	r1, r6, #0
    movs	r2, #1
    bl AddTaskExp__13HarvestSpriteQ213HarvestSprite4Taski
.Ljp_080346BC:
    movs	r0, #1
.Ljp_080346BE:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_080346D0:
    .4byte gUnk_080F1496
    .global func_08034940
    .thumb_func
func_08034940:
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r2, [r0, #10]
    lsls	r0, r2, #27
    lsrs	r0, r0, #27
    cmp	r0, #5
    bls .Ljp_08034710
    subs	r0, #6
    lsls	r1, r0, #4
    subs	r1, r1, r0
    lsls	r1, r1, #2
    lsls	r0, r2, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    adds	r0, r5, #0
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    ldr r2, .Ljp_0803473C
    adds	r0, r0, r2
    cmp	r1, r0
    bcc .Ljp_0803479C
.Ljp_08034710:
    ldrh	r0, [r5, #4]
    cmp	r0, #17
    beq .Ljp_08034740
    cmp	r0, #17
    ble .Ljp_08034758
    cmp	r0, #37	@ 0x25
    bne .Ljp_08034758
    mov	r4, sp
    mov	r0, sp
    bl smethod_08009ADC__4Farm
    mov	r0, sp
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    b .Ljp_08034758
    .align 2, 0
.Ljp_0803473C:
    .4byte 0x00000385
.Ljp_08034740:
    add	r4, sp, #4
    adds	r0, r4, #0
    bl smethod_08009AE8__4Farm
    movs	r1, #0
    ldrsh	r2, [r4, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
.Ljp_08034758:
    ldr	r0, [r5, #56]	@ 0x38
    adds	r1, r5, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    bl func_0809E994
    ldr	r0, [r5, #52]	@ 0x34
    add	r1, sp, #8
    bl method_0809E7FC__13HarvestSprite
    movs	r2, #10
    ldrsh	r1, [r5, r2]
    movs	r0, #180	@ 0xb4
    lsls	r0, r0, #1
    cmp	r1, r0
    bne .Ljp_0803477C
    movs	r2, #1
    b .Ljp_08034786
.Ljp_0803477C:
    ldr r0, .Ljp_08034798
    movs	r2, #2
    cmp	r1, r0
    bgt .Ljp_08034786
    movs	r2, #3
.Ljp_08034786:
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r5, #0
    movs	r1, #1
    bl func_08034180
    movs	r0, #1
    b .Ljp_0803479E
    .align 2, 0
.Ljp_08034798:
    .4byte 0x00000167
.Ljp_0803479C:
    movs	r0, #0
.Ljp_0803479E:
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08034A14
    .thumb_func
func_08034A14:
    push	{r4, r5, r6, lr}
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6}
    sub	sp, #16
    mov	r8, r0
    adds	r4, r1, #0
    ldr r0, .Ljp_08034828
    mov	r9, r0
    adds	r5, r4, #0
    adds	r5, #48	@ 0x30
    ldrb	r0, [r5, #0]
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r3, [r0, #0]
    movs	r6, #0
    str	r6, [sp, #0]
    movs	r0, #4
    str	r0, [sp, #4]
    str	r6, [sp, #8]
    add	r0, sp, #12
    strb	r6, [r0, #0]
    mov	r0, r8
    movs	r2, #3
    bl func_080324BC
    ldr r0, .Ljp_0803482C
    mov	r1, r8
    str	r0, [r1, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldr r2, .Ljp_08034830
    ldrb	r5, [r5, #0]
    lsls	r0, r5, #1
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    ldr	r3, [r4, #0]
    lsls	r5, r5, #2
    add	r5, r9
    mov	r0, r8
    adds	r0, #140	@ 0x8c
    movs	r4, #2
    str	r4, [sp, #0]
    ldr	r4, [r5, #0]
    str	r4, [sp, #4]
    add	r4, sp, #8
    strb	r6, [r4, #0]
    bl func_080A4A00
    mov	r0, r8
    adds	r0, #208	@ 0xd0
    strh	r6, [r0, #0]
    mov	r0, r8
    add	sp, #16
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Ljp_08034828:
    .4byte gUnk_080F14B8
.Ljp_0803482C:
    .4byte vtable_unk_080E6904
.Ljp_08034830:
    .4byte gUnk_080F14F0
    .global func_08034AA0
    .thumb_func
func_08034AA0:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0803260C
    adds	r0, r4, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08034874
    adds	r1, r4, #0
    adds	r1, #203	@ 0xcb
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Ljp_08034866
    adds	r0, r4, #0
    adds	r0, #180	@ 0xb4
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_0803486A
    adds	r1, r4, #0
    adds	r1, #200	@ 0xc8
    movs	r0, #1
    b .Ljp_08034868
.Ljp_08034866:
    movs	r0, #0
.Ljp_08034868:
    strb	r0, [r1, #0]
.Ljp_0803486A:
    adds	r1, r4, #0
    adds	r1, #208	@ 0xd0
    ldrh	r0, [r1, #0]
    subs	r0, #1
    strh	r0, [r1, #0]
.Ljp_08034874:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034AE8
    .thumb_func
func_08034AE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #60	@ 0x3c
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08032690
    adds	r0, r5, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_0803497E
    add	r3, sp, #52	@ 0x34
    ldr	r0, [r4, #0]
    ldr	r1, [r4, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r3, #4]
    adds	r0, r5, #0
    adds	r0, #204	@ 0xcc
    movs	r2, #0
    ldrsh	r1, [r0, r2]
    adds	r0, #2
    movs	r6, #0
    ldrsh	r2, [r0, r6]
    movs	r6, #12
    ldrsh	r0, [r4, r6]
    subs	r1, r1, r0
    mov	r9, r1
    movs	r1, #14
    ldrsh	r0, [r4, r1]
    subs	r0, r2, r0
    mov	r8, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r4, r0, r2
    adds	r6, r5, #0
    adds	r6, #140	@ 0x8c
    mov	sl, r3
    adds	r0, r5, #0
    adds	r0, #180	@ 0xb4
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    adds	r0, #4
    lsls	r2, r2, #2
    ldr	r0, [r0, #0]
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, sl
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    adds	r0, r5, #0
    adds	r0, #144	@ 0x90
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_08034928
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #156	@ 0x9c
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #85	@ 0x55
    ldr r4, .Ljp_08034924
    bl _call_via_r4
    b .Ljp_0803492A
    .align 2, 0
.Ljp_08034924:
    .4byte func_030004DC
.Ljp_08034928:
    movs	r0, #0
.Ljp_0803492A:
    cmp	r0, #0
    beq .Ljp_0803497E
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Ljp_0803497E
    mov	r0, sl
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_08034960
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Ljp_0803497A
.Ljp_08034960:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Ljp_0803497A
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Ljp_0803497A:
    movs	r0, #0
    strb	r0, [r5, #0]
.Ljp_0803497E:
    add	sp, #60	@ 0x3c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.entity_ui_resource_setup_after
    .syntax unified
    .thumb
    .align 2, 0
    .global func_08034C64
    .thumb_func
func_08034C64:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r1, #0
    ldr r4, .Ljp_08034A70
    ldr	r1, [r4, #0]
    bl _call_via_r1
    ldr	r1, [r4, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r5, [r0, #0]
    cmp	r5, #0
    beq .Ljp_08034A74
    ldrh	r1, [r6, #0]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Ljp_08034A20
    adds	r2, #24
.Ljp_08034A20:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r0, r0, r1
    str	r0, [sp, #4]
    ldr	r4, [r5, #4]
    ldrh	r1, [r5, #0]
    lsls	r1, r1, #3
    adds	r1, r4, r1
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080D7ECC
    subs	r0, r0, r4
    asrs	r0, r0, #3
    subs	r0, #1
    ldrh	r1, [r5, #0]
    cmp	r0, r1
    bcs .Ljp_08034A74
    ldr	r1, [r5, #4]
    lsls	r0, r0, #3
    adds	r0, r0, r1
    ldr	r0, [r0, #4]
    cmp	r0, #0
    beq .Ljp_08034A74
    ldrh	r1, [r0, #10]
    lsls	r1, r1, #22
    lsrs	r1, r1, #22
    movs	r0, #29
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    b .Ljp_08034A76
    .align 2, 0
.Ljp_08034A70:
    .4byte gUnk_080F221C
.Ljp_08034A74:
    movs	r0, #0
.Ljp_08034A76:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0

    .else
    .ifdef REGION_EU
    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803242C
    .thumb_func
func_0803242C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r3, r0, #0
    mov	r8, r1
    ldrh	r0, [r3, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_08032454
    subs	r0, #1
    b .Leu_08032456
.Leu_08032454:
    ldrh	r0, [r3, #38]	@ 0x26
.Leu_08032456:
    strh	r0, [r3, #36]	@ 0x24
    ldr	r4, [r3, #40]	@ 0x28
    cmp	r4, #0
    beq .Leu_080324BA
    movs	r2, #0
    adds	r0, r3, #0
    adds	r0, #46	@ 0x2e
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Leu_0803246C
    movs	r2, #1
.Leu_0803246C:
    mov	ip, r2
    cmp	r2, #0
    beq .Leu_08032476
    ldr	r2, [r3, #8]
    b .Leu_08032478
.Leu_08032476:
    ldr	r2, [r3, #12]
.Leu_08032478:
    asrs	r5, r2, #16
    movs	r0, #44	@ 0x2c
    ldrsh	r6, [r3, r0]
    subs	r0, r6, r5
    adds	r7, r0, #0
    cmp	r0, #0
    bne .Leu_0803248A
    str	r0, [r3, #40]	@ 0x28
    b .Leu_080324BA
.Leu_0803248A:
    adds	r1, r2, r4
    cmp	r0, #0
    bgt .Leu_08032492
    subs	r1, r2, r4
.Leu_08032492:
    adds	r2, r1, #0
    asrs	r0, r2, #16
    cmp	r0, r5
    beq .Leu_080324AE
    subs	r0, r6, r0
    cmp	r7, #0
    ble .Leu_080324A6
    cmp	r0, #0
    ble .Leu_080324AA
    b .Leu_080324AE
.Leu_080324A6:
    cmp	r0, #0
    blt .Leu_080324AE
.Leu_080324AA:
    movs	r0, #0
    str	r0, [r3, #40]	@ 0x28
.Leu_080324AE:
    mov	r0, ip
    cmp	r0, #0
    beq .Leu_080324B8
    str	r2, [r3, #8]
    b .Leu_080324BA
.Leu_080324B8:
    str	r2, [r3, #12]
.Leu_080324BA:
    adds	r0, r3, #0
    mov	r1, r8
    bl vfunc_2C__7AEntityUi
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_default_no_action_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_080324BC
    .thumb_func
func_080324BC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    add	r0, sp, #52	@ 0x34
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r4, [r7, #0]
    ldr r0, .Leu_08032570
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r5, [sp, #0]
    mov	r5, r9
    str	r5, [sp, #4]
    add	r5, sp, #8
    mov	r6, r8
    strb	r6, [r5, #0]
    bl func_080A4A00
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    movs	r2, #0
    strb	r2, [r5, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #40	@ 0x28
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r6, r3, #2
    strb	r6, [r0, #0]
    adds	r0, #1
    add	r5, sp, #48	@ 0x30
    ldrb	r5, [r5, #0]
    strb	r5, [r0, #0]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_08032570:
    .4byte vtable_unk_080E68B4
    .global func_08032560
    .thumb_func
func_08032560:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    mov	r9, r3
    ldr	r6, [sp, #48]	@ 0x30
    add	r0, sp, #64	@ 0x40
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r5, [r7, #0]
    ldr r0, .Leu_0803261C
    str	r0, [r7, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r5, #34]	@ 0x22
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r4, [sp, #0]
    mov	r4, r9
    str	r4, [sp, #4]
    str	r6, [sp, #8]
    add	r4, sp, #12
    mov	r6, r8
    strb	r6, [r4, #0]
    bl func_080A49A0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    add	r4, sp, #8
    movs	r2, #0
    strb	r2, [r4, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #52	@ 0x34
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #56]	@ 0x38
    lsls	r3, r3, #2
    str	r3, [sp, #16]
    strb	r3, [r0, #0]
    adds	r0, #1
    add	r6, sp, #60	@ 0x3c
    ldrb	r6, [r6, #0]
    strb	r6, [r0, #0]
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803261C:
    .4byte vtable_unk_080E68B4
    .global func_0803260C
    .thumb_func
func_0803260C:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_08032644
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_08032648
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Leu_08032646
.Leu_08032644:
    movs	r0, #0
.Leu_08032646:
    strb	r0, [r1, #0]
.Leu_08032648:
    adds	r1, r4, #0
    adds	r1, #138	@ 0x8a
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r5, r0, #30
    adds	r6, r1, #0
    cmp	r5, #0
    beq .Leu_0803269E
    movs	r7, #0
    subs	r1, #3
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_0803267E
    adds	r0, r4, #0
    adds	r0, #112	@ 0x70
    bl func_0805E8F0
    adds	r2, r0, #0
    lsls	r0, r2, #30
    cmp	r0, #0
    bge .Leu_0803267A
    adds	r1, r4, #0
    adds	r1, #132	@ 0x84
    movs	r0, #1
    strb	r0, [r1, #0]
.Leu_0803267A:
    adds	r0, r2, #0
    b .Leu_08032684
.Leu_0803267E:
    movs	r0, #0
    strb	r0, [r1, #0]
    movs	r0, #2
.Leu_08032684:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Leu_08032690
    cmp	r5, #2
    beq .Leu_08032690
    movs	r7, #1
.Leu_08032690:
    cmp	r7, #0
    beq .Leu_0803269E
    ldrb	r1, [r6, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #0]
.Leu_0803269E:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08032690
    .thumb_func
func_08032690:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r6, r0, #0
    mov	sl, r1
    ldr	r0, [r6, #0]
    mov	r8, r0
    ldr	r1, [r0, #0]
    str	r1, [sp, #60]	@ 0x3c
    movs	r2, #10
    ldrsh	r1, [r0, r2]
    mov	r3, sl
    movs	r4, #12
    ldrsh	r0, [r3, r4]
    subs	r1, r1, r0
    str	r1, [sp, #64]	@ 0x40
    mov	r0, r8
    movs	r2, #14
    ldrsh	r1, [r0, r2]
    movs	r4, #14
    ldrsh	r0, [r3, r4]
    subs	r0, r1, r0
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r1
    str	r0, [sp, #72]	@ 0x48
    add	r2, sp, #52	@ 0x34
    ldr	r0, [r3, #0]
    ldr	r1, [r3, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r2, #4]
    adds	r0, r6, #0
    adds	r0, #138	@ 0x8a
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #0
    beq .Leu_080327D6
    cmp	r0, #0
    blt .Leu_080327D6
    cmp	r0, #2
    bgt .Leu_080327D6
    mov	r0, r8
    adds	r0, #32
    ldrb	r0, [r0, #0]
    lsrs	r1, r1, #2
    lsls	r1, r1, #4
    lsls	r0, r0, #2
    ldr r2, .Leu_08032778
    adds	r0, r0, r2
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    movs	r3, #2
    ldrsh	r1, [r1, r3]
    adds	r5, r6, #0
    adds	r5, #72	@ 0x48
    ldr	r4, [sp, #64]	@ 0x40
    adds	r0, r4, r0
    str	r0, [sp, #76]	@ 0x4c
    ldr	r0, [sp, #68]	@ 0x44
    adds	r0, r0, r1
    mov	r9, r0
    adds	r0, r6, #0
    adds	r0, #112	@ 0x70
    ldr	r1, [r6, #112]	@ 0x70
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #116]	@ 0x74
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r3, [sp, #56]	@ 0x38
    ldr	r2, [r6, #72]	@ 0x48
    ldr	r1, [r6, #80]	@ 0x50
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08032780
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #88	@ 0x58
    ldr	r4, [sp, #72]	@ 0x48
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #76]	@ 0x4c
    mov	r2, r9
    movs	r3, #85	@ 0x55
    ldr r4, .Leu_0803277C
    bl _call_via_r4
    b .Leu_08032782
.Leu_08032778:
    .4byte gUnk_080F1328
.Leu_0803277C:
    .4byte func_030004DC
.Leu_08032780:
    movs	r0, #0
.Leu_08032782:
    cmp	r0, #0
    beq .Leu_080327D6
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Leu_080327D6
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_080327B6
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_080327D0
.Leu_080327B6:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_080327D0
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_080327D0:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Leu_080327D6:
    adds	r0, r6, #0
    adds	r0, #139	@ 0x8b
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Leu_08032800
    cmp	r0, #1
    ble .Leu_080327E8
    cmp	r0, #2
    beq .Leu_08032804
.Leu_080327E8:
    mov	r0, r8
    adds	r0, #33	@ 0x21
    ldrb	r0, [r0, #0]
    movs	r1, #3
    ands	r0, r1
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    b .Leu_08032806
.Leu_08032800:
    movs	r4, #25
    b .Leu_08032806
.Leu_08032804:
    movs	r4, #26
.Leu_08032806:
    adds	r5, r6, #0
    adds	r5, #8
    add	r2, sp, #52	@ 0x34
    mov	r8, r2
    ldr	r1, [r6, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r6, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r3, r8
    ldr	r3, [r3, #4]
    mov	r9, r3
    ldr	r2, [r6, #8]
    ldr	r1, [r6, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08032860
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #24
    ldr	r3, [sp, #72]	@ 0x48
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r9
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r4, #0
    ldr r4, .Leu_0803285C
    bl _call_via_r4
    b .Leu_08032862
.Leu_0803285C:
    .4byte func_030004DC
.Leu_08032860:
    movs	r0, #0
.Leu_08032862:
    cmp	r0, #0
    beq .Leu_080328B8
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Leu_080328B8
    mov	r4, r8
    ldr	r1, [r4, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08032898
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_080328B2
.Leu_08032898:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_080328B2
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_080328B2:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Leu_080328B8:
    adds	r0, r6, #0
    adds	r0, #136	@ 0x88
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Leu_080328DA
    cmp	r0, #1
    bgt .Leu_080328CC
    cmp	r0, #0
    beq .Leu_080328D6
    b .Leu_080328DA
.Leu_080328CC:
    cmp	r0, #2
    beq .Leu_080328DE
    cmp	r0, #3
    bne .Leu_080328DA
    b .Leu_08032904
.Leu_080328D6:
    movs	r4, #0
    b .Leu_080328E0
.Leu_080328DA:
    movs	r4, #1
    b .Leu_080328E0
.Leu_080328DE:
    movs	r4, #2
.Leu_080328E0:
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r2, #0
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    adds	r2, r6, #0
    adds	r2, #137	@ 0x89
    movs	r3, #0
    ldrsb	r3, [r2, r3]
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r2, r3
    str	r4, [sp, #0]
    ldr	r2, [sp, #64]	@ 0x40
    bl func_0803AE58
.Leu_08032904:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_region_classification_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032934
    .thumb_func
func_08032934:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r4, r2, #0
    ldrh	r0, [r4, #8]
    str	r0, [sp, #0]
    adds	r0, r5, #0
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Leu_0803296C
    str	r0, [r5, #20]
    str	r4, [r5, #48]	@ 0x30
    adds	r0, r5, #0
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Leu_0803296C:
    .4byte vtable_unk_080E6828
    .global func_0803295C
    .thumb_func
func_0803295C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Leu_080329C0
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldrh	r1, [r5, #34]	@ 0x22
    ldr	r0, [r5, #48]	@ 0x30
    strh	r1, [r0, #8]
    ldr r0, .Leu_080329C4
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_080329A8
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_080329A8:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Leu_080329B6
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_080329B6:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_080329C0:
    .4byte vtable_unk_080E6828
.Leu_080329C4:
    .4byte __vt_7AEntity
    .global func_080329B4
    .thumb_func
func_080329B4:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08032A00
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080329CC
    .thumb_func
func_080329CC:
    ldr	r0, [r0, #48]	@ 0x30
    ldrh	r0, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329D4
    .thumb_func
func_080329D4:
    ldr	r0, [r0, #48]	@ 0x30
    strh	r1, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329DC
    .thumb_func
func_080329DC:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #10
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_constructor_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032A30
    .thumb_func
func_08032A30:
    push	{lr}
    adds	r1, r0, #0
    ldrh	r0, [r1, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_08032A52
    subs	r0, #1
    b .Leu_08032A54
.Leu_08032A52:
    ldrh	r0, [r1, #38]	@ 0x26
.Leu_08032A54:
    strh	r0, [r1, #36]	@ 0x24
    ldr	r2, [r1, #16]
    cmp	r2, #0
    beq .Leu_08032A66
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Leu_08032A66:
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x3030B500
    .4byte 0xFF1AF02B
    .4byte 0x4708BC02
    .4byte 0x1C01B500
    .4byte 0x22003130
    .4byte 0x280089C8
    .4byte 0x2010D004
    .4byte 0x42485E09
    .4byte 0x0FC24308
    .4byte 0xBC021C10
    .4byte 0x00004708
    .4byte 0x78003044
    .4byte 0x00004770
    .4byte 0x7001308B
    .4byte 0x00004770
    .4byte 0x70013089
    .4byte 0x00004770
    .4byte 0x70013088
    .4byte 0x00004770
    .4byte 0x7802308A
    .4byte 0x42492104
    .4byte 0x70014011
    .4byte 0x00004770
    .4byte 0x1C05B530
    .4byte 0x0E240614
    .4byte 0xF02B3070
    .4byte 0x1C28FECF
    .4byte 0x22003084
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0x2C002301
    .4byte 0x2302D000
    .4byte 0x328A1C2A
    .4byte 0x20047811
    .4byte 0x40084240
    .4byte 0x70104318
    .4byte 0xBC01BC30
    .4byte 0x00004700
    .4byte 0x0089308A
    .4byte 0x22037803
    .4byte 0x430A401A
    .4byte 0x47707002
    .4byte 0x1C04B510
    .4byte 0xF02B3030
    .4byte 0x1C20FEA9
    .4byte 0x22003044
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0xBC01BC10
    .4byte 0x00004700
    .4byte 0x47708C80
    .4byte 0x2100B500
    .4byte 0x28008C80
    .4byte 0x2101D100
    .4byte 0xBC021C08
    .4byte 0x00004708
    .global func_08032B40
    .thumb_func
func_08032B40:
    bx	lr
    .hword 0x0000
    .4byte 0x1C02B500
    .4byte 0x42888C50
    .4byte 0x1C10D002
    .4byte 0xFB2EF7FF
    .4byte 0x4700BC01
    .4byte 0x47708C40
    .4byte 0x30208C41
    .4byte 0x18097800
    .4byte 0x47701C08
    .4byte 0x1C02B500
    .4byte 0x78003020
    .4byte 0xD0024288
    .4byte 0xF7FF1C10
    .4byte 0xBC01FB0F
    .4byte 0x00004700
    .4byte 0x78003020
    .4byte 0x00004770
    .4byte 0x5E81220E
    .4byte __ewram_bss_end + 0x170
    .4byte 0x47701A40
    .4byte 0x70013021
    .4byte 0x00004770
    .4byte 0x78003021
    .4byte 0x00004770
    .4byte 0x477061C1
    .4byte 0x477069C0
    .4byte 0x47706181
    .4byte 0x47706980
    .global func_08032BB4
    .thumb_func
func_08032BB4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    mov	sl, r2
    str	r3, [sp, #48]	@ 0x30
    mov	r2, sp
    ldrb	r1, [r2, #0]
    movs	r4, #16
    negs	r4, r4
    adds	r0, r4, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    movs	r0, #0
    str	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #48]	@ 0x30
    cmp	r1, #37	@ 0x25
    beq .Leu_08032BF6
    b .Leu_08032E30
.Leu_08032BF6:
    ldr	r2, [sp, #44]	@ 0x2c
    ldr r3, .Leu_08032C44
    adds	r7, r2, r3
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    bne .Leu_08032C08
    b .Leu_08032E30
.Leu_08032C08:
    movs	r6, #0
    str	r6, [sp, #56]	@ 0x38
    adds	r0, r7, #0
    bl GetPregnancyStallCapacity__C4Barn
    mov	r9, r0
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r0, r9
    bcs .Leu_08032CBA
    add	r1, sp, #20
    mov	r8, r1
.Leu_08032C1E:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl GetPregnancyStallLinkedStall__C4BarnUi
    mvns	r0, r0
    lsrs	r4, r0, #31
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl HasBushelForPregnancyStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08032C48
    cmp	r4, #0
    bne .Leu_08032CB4
    ldr	r2, [sp, #56]	@ 0x38
    adds	r2, #1
    str	r2, [sp, #56]	@ 0x38
    b .Leu_08032CB4
.Leu_08032C44:
    .4byte 0x000005DC
.Leu_08032C48:
    cmp	r4, #0
    beq .Leu_08032CB4
    add	r0, sp, #16
    adds	r1, r7, #0
    adds	r2, r6, #0
    bl method_0800D0C0__C4BarnUi
    ldr	r0, [sp, #16]
    str	r0, [sp, #20]
    mov	r3, r8
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    ldr	r2, [sp, #104]	@ 0x68
    subs	r1, r1, r2
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r5, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_08032C8A
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r5, r0
    bcs .Leu_08032CB4
.Leu_08032C8A:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #5
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08032CB4
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Leu_08032CB4:
    adds	r6, #1
    cmp	r6, r9
    bcc .Leu_08032C1E
.Leu_08032CBA:
    movs	r6, #0
    mov	r9, r6
    ldr	r1, [sp, #44]	@ 0x2c
    ldr r2, .Leu_08032D44
    adds	r0, r1, r2
    bl GetCapacity__C4Barn
    adds	r6, r0, #0
    movs	r5, #0
    cmp	r9, r6
    bcs .Leu_08032D1A
.Leu_08032CD0:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetBarnAnimal__C4BarnUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_08032D14
    mov	r3, sl
    ldr	r0, [r3, #0]
    adds	r1, r5, #0
    adds	r1, #54	@ 0x36
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    .hword 0x2800
    .4byte 0x8880D010
    .4byte 0xD10D2825
    .4byte 0xF0681C20
    .4byte 0x0600FC17
    .4byte 0xD1072800
    .4byte 0xF0681C20
    .4byte 0x0600FDEB
    .4byte 0xD1012800
    .4byte 0x44812001
.Leu_08032D14:
    adds	r5, #1
    cmp	r5, r6
    bcc .Leu_08032CD0
.Leu_08032D1A:
    mov	r1, r9
    cmp	r1, #0
    bne .Leu_08032D22
    b .Leu_08032E30
.Leu_08032D22:
    str	r6, [sp, #60]	@ 0x3c
    movs	r2, #0
    mov	r8, r2
    movs	r4, #0
    cmp	r8, r6
    bcs .Leu_08032D62
.Leu_08032D2E:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08032D48
    ldr	r3, [sp, #56]	@ 0x38
    adds	r3, #1
    str	r3, [sp, #56]	@ 0x38
    b .Leu_08032D5A
.Leu_08032D44:
    .4byte 0x000005DC
.Leu_08032D48:
    cmp	r4, #15
    bhi .Leu_08032D5A
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Leu_08032D5A:
    adds	r4, #1
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r4, r0
    bcc .Leu_08032D2E
.Leu_08032D62:
    ldr	r1, [sp, #56]	@ 0x38
    cmp	r9, r1
    bls .Leu_08032E30
    movs	r3, #0
    movs	r4, #31
    movs	r5, #1
    ldr	r2, [sp, #112]	@ 0x70
.Leu_08032D70:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    bne .Leu_08032D92
    ldr	r6, [sp, #56]	@ 0x38
    adds	r6, #1
    str	r6, [sp, #56]	@ 0x38
    ldrb	r1, [r2, #1]
    cmp	r1, #15
    bhi .Leu_08032D92
    ands	r1, r4
    adds	r0, r5, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Leu_08032D92:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Leu_08032D70
    ldr	r2, [sp, #56]	@ 0x38
    cmp	r9, r2
    bls .Leu_08032E30
    movs	r4, #0
    ldr	r3, [sp, #60]	@ 0x3c
    cmp	r4, r3
    bcs .Leu_08032E30
    mov	r6, sp
    adds	r6, #28
    str	r6, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r0, #16
    negs	r0, r0
    mov	r9, r0
.Leu_08032DB6:
    movs	r0, #0
    cmp	r4, #15
    bhi .Leu_08032DCE
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r2, r8
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Leu_08032DCE:
    cmp	r0, #0
    beq .Leu_08032E28
    add	r0, sp, #24
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800D074__C4BarnUi
    ldr	r0, [sp, #24]
    str	r0, [sp, #28]
    ldr	r3, [sp, #68]	@ 0x44
    movs	r6, #0
    ldrsh	r1, [r3, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r6, r1, #0
    muls	r6, r1
    adds	r1, r6, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_08032E10
    ldr	r3, [sp, #52]	@ 0x34
    cmp	r2, r3
    bcs .Leu_08032E28
.Leu_08032E10:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #4
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Leu_08032E28:
    adds	r4, #1
    ldr	r6, [sp, #60]	@ 0x3c
    cmp	r4, r6
    bcc .Leu_08032DB6
.Leu_08032E30:
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r0, #17
    beq .Leu_08032E38
    b .Leu_08032FA0
.Leu_08032E38:
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #2
    adds	r7, r1, r2
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Coop
    cmp	r0, #0
    bne .Leu_08032E4C
    b .Leu_08032FA0
.Leu_08032E4C:
    adds	r0, r7, #0
    bl GetCapacity__C4Coop
    adds	r6, r0, #0
    movs	r3, #0
    mov	r9, r3
    movs	r5, #0
    cmp	r9, r6
    bcs .Leu_08032E9C
.Leu_08032E5E:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetChicken__C4CoopUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Leu_08032E96
    mov	r1, sl
    ldr	r0, [r1, #0]
    adds	r1, r5, #0
    adds	r1, #46	@ 0x2e
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    .4byte 0xD00A2800
    .4byte 0x28118880
    .4byte 0x1C20D107
    .4byte 0xFB50F068
    .4byte 0x28000600
    .4byte 0x2201D101
    .hword 0x4491
.Leu_08032E96:
    adds	r5, #1
    cmp	r5, r6
    bcc .Leu_08032E5E
.Leu_08032E9C:
    mov	r3, r9
    cmp	r3, #0
    beq .Leu_08032FA0
    str	r6, [sp, #64]	@ 0x40
    movs	r5, #0
    mov	r8, r5
    movs	r4, #0
    cmp	r8, r6
    bcs .Leu_08032EDA
.Leu_08032EAE:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForEnt__C4CoopUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_08032EC0
    adds	r5, #1
    b .Leu_08032ED2
.Leu_08032EC0:
    cmp	r4, #7
    bhi .Leu_08032ED2
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Leu_08032ED2:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Leu_08032EAE
.Leu_08032EDA:
    cmp	r9, r5
    bls .Leu_08032FA0
    movs	r3, #0
    movs	r4, #31
    movs	r6, #1
    ldr	r2, [sp, #112]	@ 0x70
.Leu_08032EE6:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Leu_08032F04
    adds	r5, #1
    ldrb	r1, [r2, #1]
    cmp	r1, #7
    bhi .Leu_08032F04
    ands	r1, r4
    adds	r0, r6, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Leu_08032F04:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Leu_08032EE6
    cmp	r9, r5
    bls .Leu_08032FA0
    movs	r4, #0
    ldr	r2, [sp, #64]	@ 0x40
    cmp	r4, r2
    bcs .Leu_08032FA0
    mov	r3, sp
    adds	r3, #36	@ 0x24
    str	r3, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r6, #16
    negs	r6, r6
    mov	r9, r6
.Leu_08032F26:
    movs	r0, #0
    cmp	r4, #7
    bhi .Leu_08032F3E
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r0, r8
    ands	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Leu_08032F3E:
    cmp	r0, #0
    beq .Leu_08032F98
    add	r0, sp, #32
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800C6F0__C4CoopUi
    ldr	r0, [sp, #32]
    str	r0, [sp, #36]	@ 0x24
    ldr	r2, [sp, #68]	@ 0x44
    movs	r3, #0
    ldrsh	r1, [r2, r3]
    ldr	r6, [sp, #104]	@ 0x68
    subs	r1, r1, r6
    movs	r3, #2
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_08032F80
    ldr	r6, [sp, #52]	@ 0x34
    cmp	r2, r6
    bcs .Leu_08032F98
.Leu_08032F80:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #3
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Leu_08032F98:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Leu_08032F26
.Leu_08032FA0:
    movs	r6, #54	@ 0x36
    movs	r7, #16
    negs	r7, r7
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r6, #0
    bl _call_via_r2
    .4byte 0x2C001C04
    .4byte 0x88A0D049
    .4byte 0x42909A0C
    .4byte 0x6960D145
    .4byte 0x1C206D01
    .4byte 0xFCC8F0A0
    .4byte 0x28000600
    .4byte 0x6960D10F
    .4byte 0x1C206D41
    .4byte 0xFCC0F0A0
    .4byte 0x28000600
    .4byte 0x6960D107
    .4byte 0x1C206D81
    .4byte 0xFCB8F0A0
    .4byte 0x28000600
    .4byte 0x230AD02D
    .4byte 0x981A5EE1
    .4byte 0x220E1A09
    .4byte 0x9B1B5EA0
    .4byte 0x1C0A1AC0
    .4byte 0x1C11434A
    .4byte 0x43431C03
    .4byte 0x18091C18
    .4byte 0x46681C0D
    .4byte 0x07007800
    .4byte 0xD0022800
    .4byte 0x4281980D
    .4byte 0xAC02D215
    .4byte 0x1C387821
    .4byte 0x21064008
    .4byte 0x70204308
    .4byte 0x38361C30
    .4byte 0x981C7060
    .4byte 0xF06B1C21
    .4byte 0x0600FCAD
    .4byte 0xD1042800
    .4byte 0x1C204669
    .4byte 0xC10CC80C
    .4byte 0x3601950D
    .4byte 0xD9A82E45
    .4byte 0x4656242E
    .4byte 0x6C426830
    .4byte 0x1C214650
    .4byte 0xFC7EF0A0
    .4byte 0x2C353401
    .4byte 0x254CD9F5
    .4byte 0x427F2710
    .4byte 0x68084651
    .4byte 0x46506C42
    .4byte 0xF0A01C29
    .4byte 0x1C02FC71
    .4byte 0xD0312A00
    .4byte 0x9B0C8890
    .4byte 0xD12D4298
    .4byte 0x5F91260A
    .4byte 0x1A09981A
    .4byte 0x5ED0230E
    .4byte 0x1B809E1B
    .4byte 0x434A1C0A
    .4byte 0x1C031C11
    .4byte 0x1C184343
    .4byte 0x1C0E1809
    .4byte 0x78004668
    .4byte 0x28000700
    .4byte 0x980DD002
    .4byte 0xD2154281
    .4byte 0x7821AC02
    .4byte 0x40081C38
    .4byte 0x43082108
    .4byte 0x1C287020
    .4byte 0x7060384C
    .4byte 0x1C21981C
    .4byte 0xFC60F06B
    .4byte 0x28000600
    .4byte 0x4669D104
    .4byte 0xC80C1C20
    .4byte 0x960DC10C
    .4byte 0x2D533501
    .4byte 0x990AD9C0
    .4byte 0xC8444668
    .4byte 0x980AC144
    .4byte 0xBC38B012
    .4byte 0x46A14698
    .4byte 0xBCF046AA
    .4byte 0x4708BC02
    .global func_080330F4
    .thumb_func
func_080330F4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #108	@ 0x6c
    str	r0, [sp, #68]	@ 0x44
    adds	r5, r1, #0
    adds	r7, r2, #0
    adds	r4, r3, #0
    ldr	r3, [sp, #140]	@ 0x8c
    add	r2, sp, #12
    ldrb	r1, [r2, #0]
    movs	r6, #16
    negs	r6, r6
    adds	r0, r6, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrb	r1, [r4, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #2]
    ldr r2, .Leu_08033164
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    str	r0, [sp, #72]	@ 0x48
    ldrb	r1, [r4, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #4]
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    mov	sl, r0
    cmp	r3, #1
    bne .Leu_08033158
    b .Leu_0803329A
.Leu_08033158:
    cmp	r3, #1
    bgt .Leu_08033168
    cmp	r3, #0
    beq .Leu_08033170
    b .Leu_0803357E
    .align 2, 0
.Leu_08033164:
    .4byte 0x000003FF
.Leu_08033168:
    cmp	r3, #2
    bne .Leu_0803316E
    b .Leu_08033350
.Leu_0803316E:
    b .Leu_0803357E
.Leu_08033170:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    mov	r9, r0
    ldr r1, .Leu_08033208
    adds	r1, r5, r1
    str	r1, [sp, #80]	@ 0x50
    mov	r2, sp
    adds	r2, #32
    str	r2, [sp, #84]	@ 0x54
.Leu_08033182:
    movs	r7, #0
    mov	r3, r9
    lsls	r3, r3, #1
    str	r3, [sp, #100]	@ 0x64
    mov	r4, r9
    adds	r4, #1
    str	r4, [sp, #96]	@ 0x60
    ldr	r6, [sp, #72]	@ 0x48
    negs	r0, r6
    movs	r1, #140	@ 0x8c
    lsls	r1, r1, #1
    adds	r6, r0, r1
.Leu_0803319A:
    ldr	r0, [sp, #100]	@ 0x64
    adds	r0, #23
    lsls	r0, r0, #3
    mov	r2, sl
    subs	r0, r0, r2
    adds	r1, r6, #0
    muls	r1, r6
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    mov	r8, r1
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_080331C2
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r8, r4
    bcs .Leu_08033286
.Leu_080331C2:
    movs	r0, #43	@ 0x2b
    mov	r1, r9
    muls	r1, r0
    adds	r0, r1, #0
    adds	r0, r7, r0
    lsls	r0, r0, #2
    ldr	r2, [sp, #80]	@ 0x50
    adds	r0, r2, r0
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r0, r0, #28
    cmp	r0, #5
    bne .Leu_08033202
    str	r1, [sp, #28]
    add	r0, sp, #20
    add	r1, sp, #28
    bl method_0800A4A4__9FieldPlot
    add	r5, sp, #20
    adds	r0, r5, #0
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08033202
    adds	r0, r5, #0
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Leu_0803320C
    cmp	r0, #1
    beq .Leu_08033234
.Leu_08033202:
    movs	r1, #0
    b .Leu_08033252
    .align 2, 0
.Leu_08033208:
    .4byte 0x000009C8
.Leu_0803320C:
    add	r0, sp, #24
    adds	r1, r5, #0
    bl GetFood__C12RucksackItem
    add	r0, sp, #24
    ldrb	r1, [r0, #0]
    adds	r0, #1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #26
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    ldr	r0, [sp, #84]	@ 0x54
    bl __7ProductG4Food
    ldr	r0, [sp, #84]	@ 0x54
    b .Leu_08033248
.Leu_08033234:
    mov	r4, sp
    adds	r4, #33	@ 0x21
    adds	r0, r5, #0
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl __7ProductG7Article
    adds	r0, r4, #0
.Leu_08033248:
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r1, r1, #31
.Leu_08033252:
    cmp	r1, #0
    beq .Leu_08033286
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #2
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r7, [r4, #1]
    mov	r3, r9
    strb	r3, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_08033286
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r4}
    stmia	r1!, {r2, r4}
    mov	r3, r8
    str	r3, [sp, #76]	@ 0x4c
.Leu_08033286:
    adds	r6, #16
    adds	r7, #1
    cmp	r7, #42	@ 0x2a
    bls .Leu_0803319A
    ldr	r4, [sp, #96]	@ 0x60
    mov	r9, r4
    cmp	r4, #24
    bhi .Leu_08033298
    b .Leu_08033182
.Leu_08033298:
    b .Leu_0803357E
.Leu_0803329A:
    movs	r0, #0
    str	r0, [sp, #88]	@ 0x58
    movs	r7, #0
    ldr r1, .Leu_0803334C
    adds	r1, r1, r5
    mov	r9, r1
.Leu_080332A6:
    movs	r6, #0
    adds	r2, r7, #1
    mov	r8, r2
    ldr	r3, [sp, #72]	@ 0x48
    negs	r0, r3
    movs	r4, #140	@ 0x8c
    lsls	r4, r4, #1
    adds	r5, r0, r4
.Leu_080332B6:
    movs	r0, #43	@ 0x2b
    muls	r0, r7
    adds	r0, r6, r0
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r2, r0, #28
    movs	r3, #0
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_080332E2
    subs	r0, r2, #1
    cmp	r0, #3
    bhi .Leu_080332E2
    lsls	r0, r1, #24
    lsrs	r0, r0, #26
    movs	r1, #20
    eors	r0, r1
    negs	r0, r0
    lsrs	r3, r0, #31
.Leu_080332E2:
    cmp	r3, #0
    beq .Leu_0803333C
    lsls	r0, r7, #4
    adds	r0, #184	@ 0xb8
    mov	r1, sl
    subs	r0, r0, r1
    adds	r1, r5, #0
    muls	r1, r5
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r1, r1, r0
    adds	r2, r1, #0
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_0803330C
    ldr	r3, [sp, #88]	@ 0x58
    cmp	r1, r3
    bcs .Leu_0803333C
.Leu_0803330C:
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    strb	r7, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    str	r2, [sp, #104]	@ 0x68
    bl func_0809E968
    lsls	r0, r0, #24
    ldr	r2, [sp, #104]	@ 0x68
    cmp	r0, #0
    bne .Leu_0803333C
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    str	r2, [sp, #88]	@ 0x58
.Leu_0803333C:
    adds	r5, #16
    adds	r6, #1
    cmp	r6, #42	@ 0x2a
    bls .Leu_080332B6
    mov	r7, r8
    cmp	r7, #24
    bls .Leu_080332A6
    b .Leu_0803357E
.Leu_0803334C:
    .4byte 0x000009C8
.Leu_08033350:
    add	r0, sp, #36	@ 0x24
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    add	r6, sp, #40	@ 0x28
    mov	r8, r6
    add	r0, sp, #44	@ 0x2c
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [sp, #48]	@ 0x30
    add	r6, sp, #48	@ 0x30
    add	r0, sp, #52	@ 0x34
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #52]	@ 0x34
    str	r0, [sp, #56]	@ 0x38
    mov	r0, sp
    adds	r0, #56	@ 0x38
    str	r0, [sp, #92]	@ 0x5c
    add	r0, sp, #60	@ 0x3c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [sp, #64]	@ 0x40
    add	r1, sp, #64	@ 0x40
    mov	r9, r1
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r0, #17
    bne .Leu_08033394
    b .Leu_080334FE
.Leu_08033394:
    cmp	r0, #17
    bgt .Leu_0803339E
    cmp	r0, #2
    beq .Leu_080333A4
    b .Leu_0803357E
.Leu_0803339E:
    cmp	r0, #37	@ 0x25
    beq .Leu_0803347A
    b .Leu_0803357E
.Leu_080333A4:
    ldr	r2, [sp, #72]	@ 0x48
    str	r2, [sp, #0]
    mov	r3, sl
    str	r3, [sp, #4]
    ldr	r4, [sp, #144]	@ 0x90
    str	r4, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_080333D2
    b .Leu_0803357E
.Leu_080333D2:
    mov	r1, r8
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    mov	r2, r8
    movs	r1, #2
    ldrsh	r0, [r2, r1]
    mov	r2, sl
    subs	r1, r0, r2
    adds	r2, r3, #0
    muls	r2, r3
    adds	r0, r1, #0
    muls	r0, r1
    adds	r2, r2, r0
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    mov	r6, sl
    subs	r1, r0, r6
    adds	r0, r3, #0
    muls	r0, r3
    adds	r3, r1, #0
    muls	r3, r1
    adds	r1, r3, #0
    adds	r0, r0, r1
    cmp	r2, r0
    bhi .Leu_0803342C
    ldr	r6, [sp, #92]	@ 0x5c
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Leu_080334C0
.Leu_0803342C:
    mov	r6, r9
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Leu_0803345E
    b .Leu_0803357E
.Leu_0803345E:
    ldr	r3, [sp, #92]	@ 0x5c
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Leu_080334F0
.Leu_0803347A:
    ldr	r6, [sp, #72]	@ 0x48
    str	r6, [sp, #0]
    mov	r0, sl
    str	r0, [sp, #4]
    ldr	r1, [sp, #144]	@ 0x90
    str	r1, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Leu_0803357E
    mov	r6, r8
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
.Leu_080334C0:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Leu_0803357E
    mov	r3, r9
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
.Leu_080334F0:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    b .Leu_0803357E
.Leu_080334FE:
    ldr	r0, [sp, #72]	@ 0x48
    str	r0, [sp, #0]
    mov	r1, sl
    str	r1, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Leu_0803357E
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Leu_0803357E
    ldr	r1, [sp, #92]	@ 0x5c
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #0]
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    str	r0, [sp, #4]
    ldr	r6, [sp, #144]	@ 0x90
    str	r6, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
.Leu_0803357E:
    ldr	r1, [sp, #68]	@ 0x44
    add	r0, sp, #12
    ldmia	r0!, {r4, r6}
    stmia	r1!, {r4, r6}
    ldr	r0, [sp, #68]	@ 0x44
    add	sp, #108	@ 0x6c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033584
    .thumb_func
func_08033584:
    push	{r4, r5, r6, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r3, r2, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Leu_0803365C
    lsls	r0, r0, #2
    ldr r1, .Leu_080335B8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_080335B8:
    .4byte .Leu_080335BC
.Leu_080335BC:
    .4byte .Leu_0803365C
    .4byte .Leu_080335E0
    .4byte .Leu_0803361C
    .4byte .Leu_080336B8
    .4byte .Leu_080336D4
    .4byte .Leu_080336F4
    .4byte .Leu_0803371C
    .4byte .Leu_08033768
    .4byte .Leu_08033778
.Leu_080335E0:
    .4byte 0x480D78A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F020508
    .4byte 0x07882300
    .4byte 0x28010F80
    .4byte 0x1E50D108
    .4byte 0xD8052803
    .4byte 0x0E800608
    .4byte 0x40482114
    .4byte 0x0FC34240
    .4byte 0xE0BA1C18
    .4byte 0x000009C8
.Leu_0803361C:
    .4byte 0x481078A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F000508
    .4byte 0xD1112805
    .4byte 0xA9029102
    .4byte 0xF7D64668
    .4byte 0x4668FF3B
    .4byte 0xFD1CF7DB
    .4byte 0x28000600
    .4byte 0x4668D106
    .4byte 0xFD2EF7DB
    .4byte 0xD0052800
    .4byte 0xD01D2801
.Leu_0803365C:
    movs	r0, #0
    b .Leu_0803378E
    .4byte 0x000009C8
    .4byte 0xA801AC03
    .4byte 0xF7DB4669
    .4byte 0xA801FD25
    .4byte 0x30017801
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x78093106
    .4byte 0x43010409
    .4byte 0xF7DA1C20
    .4byte 0x1C20FD43
    .4byte 0xFD8EF7DA
    .4byte 0x43014241
    .4byte 0xE07A0FC8
    .4byte 0x340D466C
    .4byte 0xF7DB4668
    .4byte 0x1C01FD2D
    .4byte 0xF7DA1C20
    .4byte 0x1C20FD59
    .4byte 0xFD7EF7DA
    .4byte 0x43014241
    .4byte 0xE06A0FC8
.Leu_080336B8:
    .4byte 0x20FF2600
    .4byte 0x182D0080
    .4byte 0xF7D81C28
    .4byte 0x2800FF5B
    .4byte 0x7861D024
    .4byte 0xF7D81C28
    .4byte 0xE01BFF6D
.Leu_080336D4:
    .4byte 0x48062600
    .4byte 0x1C28182D
    .4byte 0xFBD0F7D9
    .4byte 0xD0172800
    .4byte 0x1C287861
    .4byte 0xFBE8F7D9
    .4byte 0x0000E00E
    .4byte 0x000005DC
.Leu_080336F4:
    .4byte 0x48082600
    .4byte 0x1C28182D
    .4byte 0xFBC0F7D9
    .4byte 0xD0072800
    .4byte 0x1C287861
    .4byte 0xFBEEF7D9
    .4byte 0x28000600
    .4byte 0x2601D100
    .4byte 0xE03A1C30
    .4byte 0x000005DC
.Leu_0803371C:
    .4byte 0x31367861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C04F91B
    .4byte 0x2C002500
    .4byte 0x6960D018
    .4byte 0x1C206D01
    .4byte 0xF910F0A0
    .4byte 0x28000600
    .4byte 0x6960D10F
    .4byte 0x1C206D41
    .4byte 0xF908F0A0
    .4byte 0x28000600
    .4byte 0x6960D107
    .4byte 0x1C206D81
    .4byte 0xF900F0A0
    .4byte 0x28000600
    .4byte 0x2501D000
    .4byte 0xE0121C28
.Leu_08033768:
    .4byte 0x312E7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0xE771F8F5
.Leu_08033778:
    .4byte 0x314C7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C01F8ED
    .4byte 0x43084248
    .hword 0x0FC0
.Leu_0803378E:
    add	sp, #16
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033784
    .thumb_func
func_08033784:
    push	{r4, lr}
    adds	r3, r0, #0
    adds	r4, r2, #0
    ldrb	r0, [r3, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Leu_08033806
    lsls	r0, r0, #2
    ldr r1, .Leu_080337B4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_080337B4:
    .4byte .Leu_080337B8
.Leu_080337B8:
    .4byte .Leu_08033806
    .4byte .Leu_080337DC
    .4byte .Leu_080337DC
    .4byte .Leu_080337E0
    .4byte .Leu_080337E4
    .4byte .Leu_080337E4
    .4byte .Leu_080337E8
    .4byte .Leu_080337EE
    .4byte .Leu_080337F4
.Leu_080337DC:
    .4byte 0xE0162002
.Leu_080337E0:
    .4byte 0xE0142011
.Leu_080337E4:
    .4byte 0xE0122025
.Leu_080337E8:
    .4byte 0x31367859
    .hword 0xE004
.Leu_080337EE:
    .hword 0x7859
    .4byte 0xE001312E
.Leu_080337F4:
    .4byte 0x314C7859
    .4byte 0x6C426820
    .4byte 0xF0A01C20
    .4byte 0x2800F8AF
    .hword 0xD102
.Leu_08033806:
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    b .Leu_0803380E
    .hword 0x8880
.Leu_0803380E:
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08033800
    .thumb_func
func_08033800:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, r1, #0
    adds	r1, r2, #0
    ldr	r2, [r0, #0]
    ldr	r2, [r2, #68]	@ 0x44
    bl _call_via_r2
    .4byte 0x29001C01
    .4byte 0x220AD005
    .4byte 0x220E5E88
    .4byte 0x80205E89
    .4byte 0x8021E000
    .4byte 0x1C208061
    .4byte 0xBC02BC10
    .4byte 0x00004708
    .global func_08033830
    .thumb_func
func_08033830:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Leu_08033888
    lsls	r0, r0, #2
    ldr r1, .Leu_08033860
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_08033860:
    .4byte .Leu_08033864
.Leu_08033864:
    .4byte .Leu_08033888
    .4byte .Leu_08033890
    .4byte .Leu_08033890
    .4byte .Leu_080338A6
    .4byte .Leu_080338B6
    .4byte .Leu_080338C8
    .4byte .Leu_080338DC
    .4byte .Leu_080338E2
    .4byte .Leu_080338F0
.Leu_08033888:
    movs	r0, #0
    strh	r0, [r5, #0]
    strh	r0, [r5, #2]
    b .Leu_080338FC
.Leu_08033890:
    .4byte 0x78A17860
    .4byte 0x228C0100
    .4byte 0x18800052
    .4byte 0x31B80109
    .4byte 0x80698028
    .hword 0xE02A
.Leu_080338A6:
    .hword 0x20FF
    .4byte 0x18110080
    .4byte 0x1C287862
    .4byte 0xFF28F7D8
    .hword 0xE022
.Leu_080338B6:
    .hword 0x4803
    .4byte 0x78621811
    .4byte 0xF7D91C28
    .4byte 0xE01BFBE3
    .4byte 0x000005DC
.Leu_080338C8:
    .4byte 0x18114803
    .4byte 0x1C287862
    .4byte 0xFC00F7D9
    .4byte 0x0000E012
    .4byte 0x000005DC
.Leu_080338DC:
    .4byte 0x32367862
    .hword 0xE001
.Leu_080338E2:
    .hword 0x7862
    .4byte 0x1C28322E
    .4byte 0xF7FF1C19
    .4byte 0xE005FF93
.Leu_080338F0:
    .4byte 0x324C7862
    .4byte 0x1C191C28
    .4byte 0xFF8CF7FF
.Leu_080338FC:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_080338F0
    .thumb_func
func_080338F0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #2
    bl func_080AB788
    movs	r1, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #1
    adds	r4, r4, r2
    cmp	r0, r4
    bcs .Leu_0803391E
    movs	r1, #1
.Leu_0803391E:
    adds	r0, r1, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_harvest_sprite_task_experience_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033928
    .thumb_func
func_08033928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    adds	r4, r3, #0
    ldr r1, .Leu_080339B8
    lsls	r0, r6, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    add	r0, sp, #4
    adds	r1, r4, #0
    bl func_080A03B8
    ldr r1, .Leu_080339BC
    lsls	r0, r6, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    add	r2, sp, #4
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Leu_080339C0
    str	r0, [r7, #20]
    adds	r0, r7, #0
    adds	r0, #48	@ 0x30
    movs	r5, #0
    strb	r6, [r0, #0]
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_080A099C
    str	r0, [r7, #52]	@ 0x34
    movs	r0, #135	@ 0x87
    lsls	r0, r0, #3
    adds	r4, r4, r0
    str	r4, [r7, #56]	@ 0x38
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [r7, #60]	@ 0x3c
    adds	r0, r7, #0
    adds	r0, #65	@ 0x41
    strb	r5, [r0, #0]
    adds	r0, #1
    strb	r5, [r0, #0]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    mov	r8, r0
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Leu_08033A1C
    lsls	r0, r0, #2
    ldr r1, .Leu_080339C4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_080339B8:
    .4byte gUnk_080F149C
.Leu_080339BC:
    .4byte gUnk_080F14E2
.Leu_080339C0:
    .4byte vtable_unk_080E68C8
.Leu_080339C4:
    .4byte .Leu_080339C8
.Leu_080339C8:
    .4byte .Leu_080339EC
    .4byte .Leu_08033A1A
    .4byte .Leu_080339E4
    .4byte .Leu_08033A00
    .4byte .Leu_080339E0
    .4byte .Leu_08033A1A
.Leu_080339E0:
    .4byte 0xE01B2504
.Leu_080339E4:
    .4byte 0x30226B78
    .4byte 0xE0177805
.Leu_080339EC:
    .4byte 0x1C20AC03
    .4byte 0xF06A1C31
    .4byte 0x1C38FF1F
    .4byte 0xF7FE1C21
    .4byte 0xE00DFB99
.Leu_08033A00:
    .4byte 0x6B7C2501
    .4byte 0xF06A1C20
    .4byte 0x1C01FE41
    .4byte 0xF06A1C20
    .4byte 0xF7FFFE45
    .4byte 0x4680FF89
    .hword 0xE000
.Leu_08033A1A:
    .hword 0x2501
.Leu_08033A1C:
    mvns	r1, r5
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    strb	r1, [r0, #0]
    subs	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    mov	r3, r8
    bl func_08034180
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033A2C
    .thumb_func
func_08033A2C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Leu_08033A8C
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__3NpcRC13ActorLocation
    ldr r0, .Leu_08033A90
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Leu_08033A74
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Leu_08033A74:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Leu_08033A82
    adds	r0, r5, #0
    bl __builtin_delete
.Leu_08033A82:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08033A8C:
    .4byte vtable_unk_080E68C8
.Leu_08033A90:
    .4byte __vt_7AEntity
    .global func_08033A80
    .thumb_func
func_08033A80:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    movs	r0, #212	@ 0xd4
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08034A14
    adds	r5, r0, #0
    movs	r1, #1
    negs	r1, r1
    adds	r4, #64	@ 0x40
    ldrb	r0, [r4, #0]
    cmp	r0, #2
    beq .Leu_08033AB8
    cmp	r0, #3
    beq .Leu_08033ABC
    b .Leu_08033ABE
.Leu_08033AB8:
    movs	r1, #8
    b .Leu_08033AC2
.Leu_08033ABC:
    movs	r1, #5
.Leu_08033ABE:
    cmp	r1, #0
    blt .Leu_08033AEE
.Leu_08033AC2:
    adds	r0, r5, #0
    adds	r0, #112	@ 0x70
    bl ResolveIndexedResourceHandle
    adds	r0, r5, #0
    adds	r0, #132	@ 0x84
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r3, r5, #0
    adds	r3, #138	@ 0x8a
    movs	r2, #2
    ldrb	r1, [r3, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r3, #0]
.Leu_08033AEE:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033AE4
    .thumb_func
func_08033AE4:
    push	{lr}
    movs	r1, #0
    strb	r1, [r0, #6]
    adds	r2, r0, #0
    adds	r2, #66	@ 0x42
    movs	r1, #1
    strb	r1, [r2, #0]
    bl func_08033B7C
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08033AFC
    .thumb_func
func_08033AFC:
    ldr r1, .Leu_08033B20
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Leu_08033B20:
    .4byte gUnk_080F14D4
    .global func_08033B10
    .thumb_func
func_08033B10:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    ldr	r0, [r4, #52]	@ 0x34
    bl SetChangedLocation__3Npc
    pop	{r4}
    pop	{r0}
    bx	r0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_unknown_flag_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033B84
    .thumb_func
func_08033B84:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Leu_08033BA4
    bl func_08034BFC
.Leu_08033BA4:
    pop	{r0}
    bx	r0
    .global func_08033B94
    .thumb_func
func_08033B94:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #172	@ 0xac
    adds	r7, r0, #0
    adds	r2, r1, #0
    ldr	r0, [r7, #52]	@ 0x34
    mov	r8, r0
    ldr	r1, [r7, #0]
    mov	sl, r1
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Leu_08033BEC
    lsls	r0, r0, #2
    ldr r1, .Leu_08033BD0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_08033BD0:
    .4byte .Leu_08033BD4
.Leu_08033BD4:
    .4byte .Leu_08033BEC
    .4byte .Leu_08033C78
    .4byte .Leu_08033CA8
    .4byte .Leu_08033E10
    .4byte .Leu_08034068
    .4byte .Leu_0803408C
.Leu_08033BEC:
    ldrb	r0, [r2, #4]
    cmp	r0, #0
    bne .Leu_08033BF4
    b .Leu_08034124
.Leu_08033BF4:
    mov	r0, r8
    bl GetCurrentTask__C13HarvestSprite
    cmp	r0, #3
    bne .Leu_08033C00
    b .Leu_08034124
.Leu_08033C00:
    mov	r0, r8
    bl GetWorkDaysLeft__C13HarvestSprite
    cmp	r0, #0
    bne .Leu_08033C0C
    b .Leu_08034124
.Leu_08033C0C:
    mov	r2, sl
    ldr	r0, [r2, #0]
    movs	r3, #162	@ 0xa2
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrb	r1, [r2, #10]
    movs	r0, #31
    ands	r0, r1
    cmp	r0, #6
    beq .Leu_08033C2C
    b .Leu_08034124
.Leu_08033C2C:
    ldrh	r0, [r2, #10]
    lsls	r0, r0, #21
    lsrs	r0, r0, #26
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    adds	r1, #1
    cmp	r0, r1
    beq .Leu_08033C40
    b .Leu_08034124
.Leu_08033C40:
    ldr	r0, [r2, #0]
    subs	r0, #3
    cmp	r0, #1
    bls .Leu_08033C70
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #1
    movs	r3, #8
    negs	r3, r3
    adds	r0, r7, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    add	r1, sp, #72	@ 0x48
    mov	r0, r8
    bl method_0809E7D0__13HarvestSprite
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #0
    bl func_08034180
    b .Leu_08034124
.Leu_08033C70:
    mov	r0, r8
    bl TaskDayUpdate__13HarvestSprite
    b .Leu_08034124
.Leu_08033C78:
    .4byte 0x280288B8
    .4byte 0x22B4D00E
    .4byte 0x23080052
    .4byte 0x1C38425B
    .4byte 0xF7EC2102
    .4byte 0x2380F8FF
    .4byte 0x1C38021B
    .4byte 0x22002101
    .4byte 0xFA7CF000
    .4byte 0x5F38240E
    .4byte 0xDC002877
    .4byte 0xE1E9E23E
.Leu_08033CA8:
    .4byte 0x35204645
    .4byte 0x46469525
    .4byte 0x28008C30
    .4byte 0xE0A7D000
    .4byte 0xF0001C38
    .4byte 0x0600FE4B
    .4byte 0xD0002800
    .4byte 0x78E8E22E
    .4byte 0xD0042800
    .4byte 0x70E83801
    .4byte 0x28000600
    .4byte 0x1C38D106
    .4byte 0xFACCF000
    .4byte 0x28000600
    .4byte 0xE21FD000
    .4byte 0x1C284D0F
    .4byte 0xF0772105
    .4byte 0x0084FDB7
    .4byte 0x26001964
    .4byte 0x70889925
    .4byte 0x78A0253C
    .4byte 0xF0774368
    .4byte 0x7861FD5B
    .4byte 0x18094369
    .4byte 0x80119A25
    .4byte 0xA81388BC
    .4byte 0x80468006
    .4byte 0x2C114681
    .4byte 0x2C11D025
    .4byte 0x2C02DC04
    .4byte 0xE02CD005
    .4byte gUnk_080F143C
    .4byte 0xD00F2C25
    .4byte 0x2048E027
    .4byte 0xFD42F077
    .4byte 0x464B3080
    .4byte 0x20488018
    .4byte 0xFD3CF077
    .4byte 0x006D2594
    .4byte 0x464E1940
    .4byte 0xE0188070
    .4byte 0xF0772068
    .4byte 0x3048FD33
    .4byte 0x80084649
    .4byte 0xF0772030
    .4byte 0x3060FD2D
    .4byte 0x8050464A
    .4byte 0x2040E00B
    .4byte 0xFD26F077
    .4byte 0x464B3090
    .4byte 0x20308018
    .4byte 0xFD20F077
    .4byte 0x464D3070
    .4byte 0x1C388068
    .4byte 0x78003020
    .4byte 0x46564680
    .4byte 0xA8026831
    .4byte 0x46516B4B
    .4byte 0xF09F1C22
    .4byte 0x6979FDE7
    .4byte 0x68CAA814
    .4byte 0xF09F1C39
    .4byte 0x9814FDDF
    .4byte 0x90299915
    .4byte 0xAC05912A
    .4byte 0x468A2120
    .4byte 0x21212500
    .4byte 0x20219105
    .4byte 0x60604240
    .4byte 0x60E160A0
    .4byte 0xA802A90A
    .4byte 0xC14CC84C
    .4byte 0x992A9829
    .4byte 0x910E900D
    .4byte 0x62A14651
    .4byte 0x632562E5
    .4byte 0x5EB8220A
    .4byte 0x5EF9230E
    .4byte 0x2600464D
    .4byte 0xAB135FAA
    .4byte 0x5F5B2502
    .4byte 0x46469400
    .4byte 0xF0779601
    .4byte 0x1C02FF3D
    .4byte 0x78819825
    .4byte 0x021B2380
    .4byte 0xF0001C38
    .4byte 0xE18DF9C7
    .4byte 0x46413801
    .4byte 0xE1898408
.Leu_08033E10:
    .4byte 0x32204642
    .4byte 0x1C3C9226
    .4byte 0x78203430
    .4byte 0x00C06BB9
    .4byte 0x46891809
    .4byte 0x46486BF9
    .4byte 0xF7FF4652
    .4byte 0x1C06FCB5
    .4byte 0x200A88BD
    .4byte 0x93275E3B
    .4byte 0x5EB9220E
    .4byte 0xA8169128
    .4byte 0x80418003
    .4byte 0xD10842AE
    .4byte 0xA8176BFA
    .4byte 0x46534649
    .4byte 0xFCF8F7FF
    .4byte 0x90169817
    .4byte 0x2D11E027
    .4byte 0x2D11D01D
    .4byte 0x2D02DC02
    .4byte 0xE01ED003
    .4byte 0xD0102D25
    .4byte 0x2E11E01B
    .4byte 0x2E25D007
    .4byte 0xA818D117
    .4byte 0xFE3AF7D5
    .4byte 0x90169818
    .4byte 0xA819E013
    .4byte 0xFE3AF7D5
    .4byte 0x90169819
    .4byte 0xA81AE00D
    .4byte 0xFFECF7D8
    .4byte 0x9016981A
    .4byte 0xA81BE007
    .4byte 0xFB64F7D8
    .4byte 0x9016981B
    .4byte 0x268DE001
    .4byte 0x208D00B6
    .4byte 0x42860080
    .4byte 0xAB16D077
    .4byte 0x5E982200
    .4byte 0x1A409927
    .4byte 0xDA002800
    .4byte 0x28074240
    .4byte 0x235ADC6D
    .4byte 0x2200446B
    .4byte 0x99285E98
    .4byte 0x28001A40
    .4byte 0x4240DA00
    .4byte 0xDC622807
    .4byte 0xF0001C38
    .4byte 0x0600FD39
    .4byte 0x29000E01
    .4byte 0xE11BD000
    .4byte 0xD11942AE
    .4byte 0xF0001C38
    .4byte 0x0600FA45
    .4byte 0xD1002800
    .4byte 0x4908E0BE
    .4byte 0x4008981C
    .4byte 0x4308213C
    .4byte 0xA91C901C
    .4byte 0xF06A4640
    .4byte 0x1C38FC87
    .4byte 0x78023020
    .4byte 0x21041C38
    .4byte 0x0000E0E3
    .4byte 0xFFFF0000
    .4byte 0xA81D2402
    .4byte 0x80418001
    .4byte 0x2D114680
    .4byte 0x2D11D01C
    .4byte 0x2D02DC02
    .4byte 0xE01CD003
    .4byte 0xD0102D25
    .4byte 0x2E11E019
    .4byte 0x2E25D007
    .4byte 0x2425D115
    .4byte 0xF7D8A81E
    .4byte 0x981EFF8D
    .4byte 0x2411E00E
    .4byte 0xF7D8A81F
    .4byte 0x981FFB05
    .4byte 0xA820E008
    .4byte 0xFDC4F7D5
    .4byte 0xE0039820
    .4byte 0xF7D5A821
    .4byte 0x9821FDC5
    .4byte 0x4643901D
    .4byte 0x5F5A2500
    .4byte 0x2602A81D
    .4byte 0x1C385F83
    .4byte 0xF7EB1C21
    .4byte 0x1C38FF81
    .4byte 0x78023020
    .4byte 0x21001C38
    .4byte 0xF0002300
    .4byte 0x2000F8FD
    .4byte 0x80089926
    .4byte 0x9A26E0C0
    .4byte 0x28008810
    .4byte 0x1C38D15A
    .4byte 0xFCD2F000
    .4byte 0x28000600
    .4byte 0xE0B5D000
    .4byte 0x6BB87821
    .4byte 0x184000C9
    .4byte 0x46526BF9
    .4byte 0xFAE8F7FF
    .4byte 0x28000600
    .4byte 0x4640D056
    .4byte 0xFB5CF06A
    .4byte 0x46401C01
    .4byte 0xFB60F06A
    .4byte 0xFCA4F7FF
    .4byte 0xAC161C06
    .4byte 0x5EE12300
    .4byte 0x22021C25
    .4byte 0x9B285EA8
    .4byte 0x9C271AC0
    .4byte 0x29001B09
    .4byte 0x4249DA00
    .4byte 0xDA002800
    .4byte 0x18084240
    .4byte 0x18400FC1
    .4byte 0x04001040
    .4byte 0xF09C1C31
    .4byte 0xAB23FF81
    .4byte 0x22B46018
    .4byte 0x6002A822
    .4byte 0x428A6819
    .4byte 0x1C18D900
    .4byte 0xF0776800
    .4byte 0x9926FBC7
    .4byte 0x1C388008
    .4byte 0x78043020
    .4byte 0xF077A802
    .4byte 0xA816FD19
    .4byte 0x5EC22300
    .4byte 0x5E6B2102
    .4byte 0x9500AD02
    .4byte 0x98279401
    .4byte 0xF0779928
    .4byte 0x1C02FE0F
    .4byte 0x21011C38
    .4byte 0xF0001C33
    .4byte 0xE061F89B
    .4byte 0x9E263801
    .4byte 0xE05D8030
.Leu_08034068:
    .4byte 0x8C084641
    .4byte 0xD1092800
    .4byte 0xF0001C38
    .4byte 0x0600FC6F
    .4byte 0xD1532800
    .4byte 0xF0001C38
    .4byte 0xE04FF935
    .4byte 0x46423801
    .4byte 0xE04B8410
.Leu_0803408C:
    .4byte 0x5EF9230A
    .4byte 0x004020B4
    .4byte 0xD12A4281
    .4byte 0x280069F8
    .4byte 0x2380DB07
    .4byte 0x1C38021B
    .4byte 0x22012101
    .4byte 0xF874F000
    .4byte 0x240EE03A
    .4byte 0x20085F39
    .4byte 0x42814240
    .4byte 0x4640DC34
    .4byte 0xFB66F06A
    .4byte 0x4640A924
    .4byte 0xFB98F06A
    .4byte 0x30301C38
    .4byte 0xA8027801
    .4byte 0xFBB0F06A
    .4byte 0xA9021C38
    .4byte 0xF82AF7FE
    .4byte 0x30201C38
    .4byte 0x1C387802
    .4byte 0x23002100
    .4byte 0xF854F000
    .4byte 0x69BAE01A
    .4byte 0x48052300
    .4byte 0xDC004281
    .4byte 0x1C182301
    .4byte 0xD0052800
    .4byte 0xDD052A00
    .4byte 0x0000E00E
    .4byte 0x00000167
    .4byte 0xDB092A00
    .4byte 0x28002202
    .4byte 0x2203D000
    .4byte 0x021B2380
    .4byte 0x21011C38
    .4byte 0xF838F000
.Leu_08034124:
    adds	r4, r7, #0
    adds	r4, #66	@ 0x42
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Leu_0803414C
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    ldrb	r1, [r0, #0]
    adds	r0, r7, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_08034148
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Leu_08034148:
    movs	r0, #0
    strb	r0, [r4, #0]
.Leu_0803414C:
    ldr	r1, [r7, #28]
    cmp	r1, #0
    beq .Leu_08034158
    ldr	r0, [r7, #12]
    adds	r0, r0, r1
    str	r0, [r7, #12]
.Leu_08034158:
    ldr	r1, [r7, #24]
    cmp	r1, #0
    beq .Leu_08034164
    ldr	r0, [r7, #8]
    adds	r0, r0, r1
    str	r0, [r7, #8]
.Leu_08034164:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Leu_0803416E
    subs	r0, #1
    b .Leu_08034170
.Leu_0803416E:
    ldrh	r0, [r7, #38]	@ 0x26
.Leu_08034170:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r4, [r7, #16]
    cmp	r4, #0
    beq .Leu_08034182
    ldr	r0, [r4, #4]
    ldr	r1, [r0, #12]
    adds	r0, r4, #0
    bl _call_via_r1
.Leu_08034182:
    add	sp, #172	@ 0xac
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034180
    .thumb_func
func_08034180:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r7, r1, #0
    adds	r5, r2, #0
    adds	r6, r3, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Leu_080341B0
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Leu_080341B0:
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r5
    beq .Leu_080341C2
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Leu_080341C2:
    adds	r0, r4, #0
    adds	r0, #66	@ 0x42
    movs	r1, #0
    strb	r1, [r0, #0]
    cmp	r7, #1
    beq .Leu_080341E4
    cmp	r7, #1
    bgt .Leu_080341D8
    cmp	r7, #0
    beq .Leu_080341DC
    b .Leu_0803421E
.Leu_080341D8:
    cmp	r7, #4
    bgt .Leu_0803421E
.Leu_080341DC:
    movs	r0, #0
    str	r0, [r4, #24]
    str	r0, [r4, #28]
    b .Leu_0803421E
.Leu_080341E4:
    adds	r0, r6, #0
    cmp	r6, #0
    bge .Leu_080341EC
    negs	r0, r6
.Leu_080341EC:
    adds	r6, r0, #0
    cmp	r5, #1
    beq .Leu_0803420C
    cmp	r5, #1
    bgt .Leu_080341FC
    cmp	r5, #0
    beq .Leu_08034206
    b .Leu_0803421E
.Leu_080341FC:
    cmp	r5, #2
    beq .Leu_08034214
    cmp	r5, #3
    beq .Leu_0803421A
    b .Leu_0803421E
.Leu_08034206:
    str	r6, [r4, #28]
    str	r1, [r4, #24]
    b .Leu_0803421E
.Leu_0803420C:
    negs	r0, r6
    str	r0, [r4, #28]
    str	r1, [r4, #24]
    b .Leu_0803421E
.Leu_08034214:
    negs	r0, r6
    str	r0, [r4, #24]
    b .Leu_0803421C
.Leu_0803421A:
    str	r6, [r4, #24]
.Leu_0803421C:
    str	r1, [r4, #28]
.Leu_0803421E:
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    adds	r5, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r7, r0
    beq .Leu_08034252
    movs	r1, #1
    negs	r1, r1
    cmp	r7, #2
    beq .Leu_08034238
    cmp	r7, #3
    beq .Leu_0803423C
    b .Leu_0803423E
.Leu_08034238:
    movs	r1, #8
    b .Leu_08034242
.Leu_0803423C:
    movs	r1, #5
.Leu_0803423E:
    cmp	r1, #0
    blt .Leu_0803424C
.Leu_08034242:
    adds	r0, r4, #0
    movs	r2, #1
    bl func_08032384
    b .Leu_08034252
.Leu_0803424C:
    adds	r0, r4, #0
    bl func_080323C8
.Leu_08034252:
    strb	r7, [r5, #0]
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_animation_lookup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034260
    .thumb_func
func_08034260:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #28
    adds	r6, r0, #0
    adds	r7, r6, #0
    adds	r7, #65	@ 0x41
    ldrb	r0, [r7, #0]
    cmp	r0, #0
    beq .Leu_08034288
    movs	r0, #0
    b .Leu_080342DE
.Leu_08034288:
    ldr	r5, [r6, #0]
    add	r4, sp, #16
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #52]	@ 0x34
    bl GetCurrentTask__C13HarvestSprite
    ldr	r1, [r6, #60]	@ 0x3c
    str	r0, [sp, #0]
    ldr	r0, [r6, #56]	@ 0x38
    str	r0, [sp, #4]
    add	r0, sp, #8
    adds	r2, r5, #0
    adds	r3, r4, #0
    bl func_080330F4
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Leu_080342BE
    movs	r0, #1
    strb	r0, [r7, #0]
    movs	r0, #0
    b .Leu_080342DE
.Leu_080342BE:
    ldr	r0, [r6, #56]	@ 0x38
    adds	r1, r6, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    add	r2, sp, #8
    bl func_0809E988
    ldr r1, .Leu_080342E8
    ldr	r0, [sp, #24]
    ands	r0, r1
    str	r0, [sp, #24]
    ldr	r0, [r6, #52]	@ 0x34
    add	r1, sp, #24
    bl method_0809E7E4__13HarvestSpritePC15UnkBarnAnimal2C
    movs	r0, #1
.Leu_080342DE:
    add	sp, #28
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_080342E8:
    .4byte 0xFFFF0000
    .global func_080342D8
    .thumb_func
func_080342D8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    bl GetFriendship__C3Npc
    bl func_080338F0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803430E
    adds	r0, r5, #0
    bl func_08034260
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803436A
.Leu_0803430E:
    movs	r0, #180	@ 0xb4
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Leu_08034374
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Leu_08034378
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r4, [r5, #52]	@ 0x34
    adds	r0, r4, #0
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    adds	r1, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    subs	r0, r0, r1
    bl func_080AB788
    lsrs	r0, r0, #6
    adds	r0, #2
    lsls	r0, r0, #24
    ldr r2, .Leu_0803437C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r1, sp
    bl method_0809E7D8__13HarvestSpritePC15UnkBarnAnimal2C
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r5, #0
    movs	r1, #0
    movs	r3, #0
    bl func_08034180
.Leu_0803436A:
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Leu_08034374:
    .4byte 0xFFFF0000
.Leu_08034378:
    .4byte 0xFF00FFFF
.Leu_0803437C:
    .4byte 0x00FFFFFF
    .global func_0803436C
    .thumb_func
func_0803436C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    str	r0, [sp, #36]	@ 0x24
    ldr	r0, [r0, #0]
    str	r0, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    adds	r3, #48	@ 0x30
    ldrb	r1, [r3, #0]
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #56]	@ 0x38
    lsls	r1, r1, #3
    mov	r2, sp
    adds	r1, r0, r1
    ldmia	r1!, {r4, r5}
    stmia	r2!, {r4, r5}
    ldrb	r1, [r3, #0]
    bl func_0809E994
    ldr	r0, [sp, #36]	@ 0x24
    ldr	r1, [r0, #60]	@ 0x3c
    mov	r0, sp
    ldr	r2, [sp, #40]	@ 0x28
    bl func_08033584
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_080343C0
    b .Leu_0803490E
.Leu_080343C0:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r5, [r1, #16]
    cmp	r5, #0
    beq .Leu_0803442E
    ldr	r2, [r1, #60]	@ 0x3c
    add	r4, sp, #24
    adds	r0, r4, #0
    mov	r1, sp
    ldr	r3, [sp, #40]	@ 0x28
    bl func_08033830
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    beq .Leu_080343F8
    cmp	r0, #4
    bgt .Leu_080343EC
    cmp	r0, #3
    beq .Leu_080343F2
    b .Leu_08034418
.Leu_080343EC:
    cmp	r0, #5
    beq .Leu_08034412
    b .Leu_08034418
.Leu_080343F2:
    ldrh	r0, [r4, #2]
    subs	r0, #24
    b .Leu_08034416
.Leu_080343F8:
    movs	r0, #2
    ldrsh	r2, [r4, r0]
    mov	r0, sp
    ldrb	r0, [r0, #1]
    movs	r1, #7
    ands	r0, r1
    adds	r1, r2, #0
    adds	r1, #24
    cmp	r0, #3
    bhi .Leu_0803440E
    subs	r1, #56	@ 0x38
.Leu_0803440E:
    strh	r1, [r4, #2]
    b .Leu_08034418
.Leu_08034412:
    ldrh	r0, [r4, #2]
    subs	r0, #40	@ 0x28
.Leu_08034416:
    strh	r0, [r4, #2]
.Leu_08034418:
    ldr	r0, [sp, #36]	@ 0x24
    adds	r0, #48	@ 0x30
    ldrb	r1, [r0, #0]
    movs	r0, #0
    ldrsh	r2, [r4, r0]
    add	r0, sp, #24
    movs	r4, #2
    ldrsh	r3, [r0, r4]
    adds	r0, r5, #0
    bl func_08034BFC
.Leu_0803442E:
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bls .Leu_0803443C
    b .Leu_0803490E
.Leu_0803443C:
    lsls	r0, r0, #2
    ldr r1, .Leu_08034448
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Leu_08034448:
    .4byte .Leu_0803444C
.Leu_0803444C:
    .4byte .Leu_0803490E
    .4byte .Leu_08034470
    .4byte .Leu_080344F8
    .4byte .Leu_080345FE
    .4byte .Leu_0803462A
    .4byte .Leu_08034658
    .4byte .Leu_08034694
    .4byte .Leu_08034800
    .4byte .Leu_08034848
.Leu_08034470:
    .4byte 0x682D9D0A
    .4byte 0x20D846A9
    .4byte 0x99094481
    .4byte 0x5E8E220A
    .4byte 0x5F4C250E
    .4byte 0xAC0246A0
    .4byte 0x88212202
    .4byte 0x1C184B19
    .4byte 0x43104008
    .4byte 0x04368020
    .4byte 0x203F0C31
    .4byte 0x40014682
    .4byte 0x78650089
    .4byte 0x1C102203
    .4byte 0x43084028
    .4byte 0x0DB67060
    .4byte 0x1C188861
    .4byte 0x43304008
    .4byte 0x46418060
    .4byte 0x46880409
    .4byte 0x46550C08
    .4byte 0x00804028
    .4byte 0x400A78E1
    .4byte 0x70E24302
    .4byte 0x0D804640
    .4byte 0x88A04680
    .4byte 0x46414003
    .4byte 0x80A3430B
    .4byte 0x682A464D
    .4byte 0x1C21980A
    .4byte 0xFA3AF09F
    .4byte 0x46A02601
    .4byte 0x0000E20F
    .4byte 0xFFFFFC00
.Leu_080344F8:
    .4byte 0x4681A802
    .4byte 0xFD80F7DA
    .4byte 0x6809990A
    .4byte 0x22E04688
    .4byte 0x9C094490
    .4byte 0x5E25200A
    .4byte 0x5E66210E
    .4byte 0x2202AF04
    .4byte 0x4B1E8839
    .4byte 0x40081C18
    .4byte 0x80384310
    .4byte 0x0C29042D
    .4byte 0x4692223F
    .4byte 0x00894011
    .4byte 0x2203787C
    .4byte 0x40201C10
    .4byte 0x70784308
    .4byte 0x88790DAD
    .4byte 0x40081C18
    .4byte 0x80784328
    .4byte 0x0C300436
    .4byte 0x40204654
    .4byte 0x78F90080
    .4byte 0x4302400A
    .4byte 0x0DB670FA
    .4byte 0x400388B8
    .4byte 0x80BB4333
    .4byte 0x682B4645
    .4byte 0x1C39980A
    .4byte 0xF09F464A
    .4byte 0x4648F9F9
    .4byte 0xFD84F7DA
    .4byte 0x46C80600
    .4byte 0xD0002800
    .4byte 0x4640E1C5
    .4byte 0xFD94F7DA
    .4byte 0xD0052800
    .4byte 0xD0212801
    .4byte 0x0000E1BD
    .4byte 0xFFFFFC00
    .4byte 0x6804980A
    .4byte 0x004921AE
    .4byte 0xAD071864
    .4byte 0x46411C38
    .4byte 0xFD86F7DA
    .4byte 0x46687839
    .4byte 0x78003011
    .4byte 0x43080200
    .4byte 0x31124669
    .4byte 0x04097809
    .4byte 0x1C284301
    .4byte 0xFDA4F7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0xE012F9C7
    .4byte 0x68149A0A
    .4byte 0x006D25AE
    .4byte 0x466D1964
    .4byte 0x4640351D
    .4byte 0xFD8AF7DA
    .4byte 0x1C281C01
    .4byte 0xFDB6F7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0x2600F9B3
    .hword 0xE189
.Leu_080345FE:
    .hword 0x9909
    .4byte 0x24FF6BC8
    .4byte 0x190000A4
    .4byte 0xF7D82101
    .4byte 0x9A09F8EF
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xF906F7D8
    .4byte 0x68209C0A
    .4byte 0x466930A0
    .4byte 0x68027849
    .hword 0xE02B
.Leu_0803462A:
    .hword 0x9909
    .4byte 0x4C096BC8
    .4byte 0x21011900
    .4byte 0xFE2EF7D8
    .4byte 0x6BD09A09
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9C0AFE45
    .4byte 0x309C6820
    .4byte 0x78494669
    .4byte 0xE0166802
    .4byte 0x000005DC
.Leu_08034658:
    .4byte 0x6BC89909
    .4byte 0x19004C0C
    .4byte 0xF7D82101
    .4byte 0x9A09FE17
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xFE6AF7D8
    .4byte 0x68229C0A
    .4byte 0x4668329C
    .4byte 0x31107841
    .4byte 0x1C206812
    .4byte 0xF96CF09F
    .4byte 0xAD022602
    .4byte 0xE14046A8
    .4byte 0x000005DC
.Leu_08034694:
    .4byte 0x78414668
    .4byte 0x9A0A3136
    .4byte 0x6C026810
    .4byte 0xF09F980A
    .4byte 0x1C07F95D
    .4byte 0xD1002F00
    .4byte 0x6978E12F
    .4byte 0x1C386D01
    .4byte 0xF952F09F
    .4byte 0x28000600
    .4byte 0x6978D004
    .4byte 0x1C386F01
    .4byte 0xF94AF09F
    .4byte 0x6D416978
    .4byte 0xF09F1C38
    .4byte 0x0600F945
    .4byte 0x46A0AC02
    .4byte 0xD0452800
    .4byte 0x6F416978
    .4byte 0xF09F1C38
    .4byte 0x211CF93B
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Leu_080346FC
.Leu_080346FC:
    .4byte .Leu_08034714
    .4byte .Leu_08034718
    .4byte .Leu_0803471C
    .4byte .Leu_08034720
    .4byte .Leu_08034724
    .4byte .Leu_08034728
.Leu_08034714:
    .4byte 0xE008211C
.Leu_08034718:
    .4byte 0xE006211D
.Leu_0803471C:
    .4byte 0xE004211E
.Leu_08034720:
    .4byte 0xE002211F
.Leu_08034724:
    .4byte 0xE0002120
.Leu_08034728:
    .4byte 0x9D0A2121
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x361E466E
    .4byte 0x1C28AD02
    .4byte 0xFABEF7D9
    .4byte 0x46687829
    .4byte 0x78003009
    .4byte 0x43080200
    .4byte 0x310A4669
    .4byte 0x04097809
    .4byte 0x1C304301
    .4byte 0xFCDAF7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C31
    .4byte 0x46A8F8FD
    .4byte 0x6D816978
    .4byte 0xF09F1C38
    .4byte 0x0600F8F5
    .4byte 0xD03A2800
    .4byte 0x6F816978
    .4byte 0xF09F1C38
    .4byte 0x2105F8ED
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Leu_08034798
.Leu_08034798:
    .4byte .Leu_080347B0
    .4byte .Leu_080347B4
    .4byte .Leu_080347B8
    .4byte .Leu_080347BC
    .4byte .Leu_080347C0
    .4byte .Leu_080347C4
.Leu_080347B0:
    .4byte 0xE0082105
.Leu_080347B4:
    .4byte 0xE0062106
.Leu_080347B8:
    .4byte 0xE0042107
.Leu_080347BC:
    .4byte 0xE0022108
.Leu_080347C0:
    .4byte 0xE0002109
.Leu_080347C4:
    .4byte 0x9A0A210A
    .4byte 0x24AE6815
    .4byte 0x192D0064
    .4byte 0x361F466E
    .4byte 0x1C20AC08
    .4byte 0xFBC4F7D9
    .4byte 0x1C307821
    .4byte 0xFCBCF7D9
    .4byte 0x980A682A
    .4byte 0xF09F1C31
    .4byte 0x6978F8B9
    .4byte 0x68023088
    .4byte 0x213C1C38
    .4byte 0xF8B2F09F
    .4byte 0xE0882602
.Leu_08034800:
    .4byte 0x78414668
    .4byte 0x9D0A312E
    .4byte 0x6C026828
    .4byte 0xF09F1C28
    .4byte 0x1C04F8A7
    .4byte 0xD07A2C00
    .4byte 0x6D016960
    .4byte 0xF09F1C20
    .4byte 0x0600F89D
    .4byte 0xD0042800
    .4byte 0x6F016960
    .4byte 0xF09F1C20
    .4byte 0x6960F895
    .4byte 0x68023088
    .4byte 0x213C1C20
    .4byte 0xF890F09F
    .4byte 0xA8022602
    .4byte 0xE0644680
.Leu_08034848:
    .4byte 0x78414668
    .4byte 0x344C1C0C
    .4byte 0x6BD09A09
    .4byte 0x00AD25FF
    .4byte 0xF7D71940
    .4byte 0x2800FF2B
    .4byte 0x7980D055
    .4byte 0x0F400740
    .4byte 0x2805270F
    .4byte 0x0080D81D
    .4byte 0x18404901
    .4byte 0x46876800
    .4byte .Leu_0803487C
.Leu_0803487C:
    .4byte .Leu_08034894
    .4byte .Leu_08034898
    .4byte .Leu_0803489C
    .4byte .Leu_080348A0
    .4byte .Leu_080348A4
    .4byte .Leu_080348A8
.Leu_08034894:
    .4byte 0xE008270F
.Leu_08034898:
    .4byte 0xE0062710
.Leu_0803489C:
    .4byte 0xE0042711
.Leu_080348A0:
    .4byte 0xE0022712
.Leu_080348A4:
    .4byte 0xE0002713
.Leu_080348A8:
    .4byte 0x99092714
    .4byte 0x68016808
    .4byte 0x1C216BCA
    .4byte 0xF854F09F
    .4byte 0x6BD09A09
    .4byte 0x00A424FF
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9D0AF881
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x3621466E
    .4byte 0x1C28AD02
    .4byte 0xF7D91C39
    .4byte 0x7829F9ED
    .4byte 0x30094668
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x7809310A
    .4byte 0x43010409
    .4byte 0xF7D91C30
    .4byte 0x6822FC09
    .4byte 0x1C31980A
    .4byte 0xF82CF09F
    .4byte 0x46A82602
    .hword 0xE001
.Leu_0803490E:
    movs	r0, #0
    b .Leu_0803493E
    .hword 0x490F
    .4byte 0x22034640
    .4byte 0xF862F09F
    .4byte 0xD00D2E03
    .4byte 0xF07620C8
    .4byte 0x4642FF49
    .4byte 0x78091991
    .4byte 0xD2054288
    .4byte 0x6B609C09
    .4byte 0x22011C31
    .4byte 0xFEC8F069
    .hword 0x2001
.Leu_0803493E:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .hword 0x0000
    .4byte gUnk_080F1496
    .global func_08034940
    .thumb_func
func_08034940:
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r2, [r0, #10]
    lsls	r0, r2, #27
    lsrs	r0, r0, #27
    cmp	r0, #5
    bls .Leu_08034990
    subs	r0, #6
    lsls	r1, r0, #4
    subs	r1, r1, r0
    lsls	r1, r1, #2
    lsls	r0, r2, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    adds	r0, r5, #0
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    ldr r2, .Leu_080349BC
    adds	r0, r0, r2
    cmp	r1, r0
    bcc .Leu_08034A1C
.Leu_08034990:
    ldrh	r0, [r5, #4]
    cmp	r0, #17
    beq .Leu_080349C0
    cmp	r0, #17
    ble .Leu_080349D8
    cmp	r0, #37	@ 0x25
    bne .Leu_080349D8
    mov	r4, sp
    mov	r0, sp
    bl smethod_08009ADC__4Farm
    mov	r0, sp
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    b .Leu_080349D8
    .align 2, 0
.Leu_080349BC:
    .4byte 0x00000385
.Leu_080349C0:
    add	r4, sp, #4
    adds	r0, r4, #0
    bl smethod_08009AE8__4Farm
    movs	r1, #0
    ldrsh	r2, [r4, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
.Leu_080349D8:
    ldr	r0, [r5, #56]	@ 0x38
    adds	r1, r5, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    bl func_0809E994
    ldr	r0, [r5, #52]	@ 0x34
    add	r1, sp, #8
    bl method_0809E7FC__13HarvestSprite
    movs	r2, #10
    ldrsh	r1, [r5, r2]
    movs	r0, #180	@ 0xb4
    lsls	r0, r0, #1
    cmp	r1, r0
    bne .Leu_080349FC
    movs	r2, #1
    b .Leu_08034A06
.Leu_080349FC:
    ldr r0, .Leu_08034A18
    movs	r2, #2
    cmp	r1, r0
    bgt .Leu_08034A06
    movs	r2, #3
.Leu_08034A06:
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r5, #0
    movs	r1, #1
    bl func_08034180
    movs	r0, #1
    b .Leu_08034A1E
    .align 2, 0
.Leu_08034A18:
    .4byte 0x00000167
.Leu_08034A1C:
    movs	r0, #0
.Leu_08034A1E:
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08034A14
    .thumb_func
func_08034A14:
    push	{r4, r5, r6, lr}
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6}
    sub	sp, #16
    mov	r8, r0
    adds	r4, r1, #0
    ldr r0, .Leu_08034AA8
    mov	r9, r0
    adds	r5, r4, #0
    adds	r5, #48	@ 0x30
    ldrb	r0, [r5, #0]
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r3, [r0, #0]
    movs	r6, #0
    str	r6, [sp, #0]
    movs	r0, #4
    str	r0, [sp, #4]
    str	r6, [sp, #8]
    add	r0, sp, #12
    strb	r6, [r0, #0]
    mov	r0, r8
    movs	r2, #3
    bl func_080324BC
    ldr r0, .Leu_08034AAC
    mov	r1, r8
    str	r0, [r1, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldr r2, .Leu_08034AB0
    ldrb	r5, [r5, #0]
    lsls	r0, r5, #1
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    ldr	r3, [r4, #0]
    lsls	r5, r5, #2
    add	r5, r9
    mov	r0, r8
    adds	r0, #140	@ 0x8c
    movs	r4, #2
    str	r4, [sp, #0]
    ldr	r4, [r5, #0]
    str	r4, [sp, #4]
    add	r4, sp, #8
    strb	r6, [r4, #0]
    bl func_080A4A00
    mov	r0, r8
    adds	r0, #208	@ 0xd0
    strh	r6, [r0, #0]
    mov	r0, r8
    add	sp, #16
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Leu_08034AA8:
    .4byte gUnk_080F14B8
.Leu_08034AAC:
    .4byte vtable_unk_080E6904
.Leu_08034AB0:
    .4byte gUnk_080F14F0
    .global func_08034AA0
    .thumb_func
func_08034AA0:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0803260C
    adds	r0, r4, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08034AF4
    adds	r1, r4, #0
    adds	r1, #203	@ 0xcb
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Leu_08034AE6
    adds	r0, r4, #0
    adds	r0, #180	@ 0xb4
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Leu_08034AEA
    adds	r1, r4, #0
    adds	r1, #200	@ 0xc8
    movs	r0, #1
    b .Leu_08034AE8
.Leu_08034AE6:
    movs	r0, #0
.Leu_08034AE8:
    strb	r0, [r1, #0]
.Leu_08034AEA:
    adds	r1, r4, #0
    adds	r1, #208	@ 0xd0
    ldrh	r0, [r1, #0]
    subs	r0, #1
    strh	r0, [r1, #0]
.Leu_08034AF4:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034AE8
    .thumb_func
func_08034AE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #60	@ 0x3c
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08032690
    adds	r0, r5, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08034BFE
    add	r3, sp, #52	@ 0x34
    ldr	r0, [r4, #0]
    ldr	r1, [r4, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r3, #4]
    adds	r0, r5, #0
    adds	r0, #204	@ 0xcc
    movs	r2, #0
    ldrsh	r1, [r0, r2]
    adds	r0, #2
    movs	r6, #0
    ldrsh	r2, [r0, r6]
    movs	r6, #12
    ldrsh	r0, [r4, r6]
    subs	r1, r1, r0
    mov	r9, r1
    movs	r1, #14
    ldrsh	r0, [r4, r1]
    subs	r0, r2, r0
    mov	r8, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r4, r0, r2
    adds	r6, r5, #0
    adds	r6, #140	@ 0x8c
    mov	sl, r3
    adds	r0, r5, #0
    adds	r0, #180	@ 0xb4
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    adds	r0, #4
    lsls	r2, r2, #2
    ldr	r0, [r0, #0]
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, sl
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    adds	r0, r5, #0
    adds	r0, #144	@ 0x90
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_08034BA8
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #156	@ 0x9c
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #85	@ 0x55
    ldr r4, .Leu_08034BA4
    bl _call_via_r4
    b .Leu_08034BAA
    .align 2, 0
.Leu_08034BA4:
    .4byte func_030004DC
.Leu_08034BA8:
    movs	r0, #0
.Leu_08034BAA:
    cmp	r0, #0
    beq .Leu_08034BFE
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Leu_08034BFE
    mov	r0, sl
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Leu_08034BE0
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Leu_08034BFA
.Leu_08034BE0:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Leu_08034BFA
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Leu_08034BFA:
    movs	r0, #0
    strb	r0, [r5, #0]
.Leu_08034BFE:
    add	sp, #60	@ 0x3c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ EU entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_resource_setup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034C64
    .thumb_func
func_08034C64:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r1, #0
    ldr r4, .Leu_08034CF0
    ldr	r1, [r4, #0]
    bl _call_via_r1
    ldr	r1, [r4, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r5, [r0, #0]
    cmp	r5, #0
    beq .Leu_08034CF4
    ldrh	r1, [r6, #0]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Leu_08034CA0
    adds	r2, #24
.Leu_08034CA0:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r0, r0, r1
    str	r0, [sp, #4]
    ldr	r4, [r5, #4]
    ldrh	r1, [r5, #0]
    lsls	r1, r1, #3
    adds	r1, r4, r1
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080D7ECC
    subs	r0, r0, r4
    asrs	r0, r0, #3
    subs	r0, #1
    ldrh	r1, [r5, #0]
    cmp	r0, r1
    bcs .Leu_08034CF4
    ldr	r1, [r5, #4]
    lsls	r0, r0, #3
    adds	r0, r0, r1
    ldr	r0, [r0, #4]
    cmp	r0, #0
    beq .Leu_08034CF4
    ldrh	r1, [r0, #10]
    lsls	r1, r1, #22
    lsrs	r1, r1, #22
    movs	r0, #29
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    b .Leu_08034CF6
    .align 2, 0
.Leu_08034CF0:
    .4byte gUnk_080F29C0
.Leu_08034CF4:
    movs	r0, #0
.Leu_08034CF6:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .else
    .ifdef REGION_DE
    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803242C
    .thumb_func
func_0803242C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r3, r0, #0
    mov	r8, r1
    ldrh	r0, [r3, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_08032354
    subs	r0, #1
    b .Lde_08032356
.Lde_08032354:
    ldrh	r0, [r3, #38]	@ 0x26
.Lde_08032356:
    strh	r0, [r3, #36]	@ 0x24
    ldr	r4, [r3, #40]	@ 0x28
    cmp	r4, #0
    beq .Lde_080323BA
    movs	r2, #0
    adds	r0, r3, #0
    adds	r0, #46	@ 0x2e
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lde_0803236C
    movs	r2, #1
.Lde_0803236C:
    mov	ip, r2
    cmp	r2, #0
    beq .Lde_08032376
    ldr	r2, [r3, #8]
    b .Lde_08032378
.Lde_08032376:
    ldr	r2, [r3, #12]
.Lde_08032378:
    asrs	r5, r2, #16
    movs	r0, #44	@ 0x2c
    ldrsh	r6, [r3, r0]
    subs	r0, r6, r5
    adds	r7, r0, #0
    cmp	r0, #0
    bne .Lde_0803238A
    str	r0, [r3, #40]	@ 0x28
    b .Lde_080323BA
.Lde_0803238A:
    adds	r1, r2, r4
    cmp	r0, #0
    bgt .Lde_08032392
    subs	r1, r2, r4
.Lde_08032392:
    adds	r2, r1, #0
    asrs	r0, r2, #16
    cmp	r0, r5
    beq .Lde_080323AE
    subs	r0, r6, r0
    cmp	r7, #0
    ble .Lde_080323A6
    cmp	r0, #0
    ble .Lde_080323AA
    b .Lde_080323AE
.Lde_080323A6:
    cmp	r0, #0
    blt .Lde_080323AE
.Lde_080323AA:
    movs	r0, #0
    str	r0, [r3, #40]	@ 0x28
.Lde_080323AE:
    mov	r0, ip
    cmp	r0, #0
    beq .Lde_080323B8
    str	r2, [r3, #8]
    b .Lde_080323BA
.Lde_080323B8:
    str	r2, [r3, #12]
.Lde_080323BA:
    adds	r0, r3, #0
    mov	r1, r8
    bl vfunc_2C__7AEntityUi
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_default_no_action_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_080324BC
    .thumb_func
func_080324BC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    add	r0, sp, #52	@ 0x34
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r4, [r7, #0]
    ldr r0, .Lde_08032470
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r5, [sp, #0]
    mov	r5, r9
    str	r5, [sp, #4]
    add	r5, sp, #8
    mov	r6, r8
    strb	r6, [r5, #0]
    bl func_080A4A00
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    movs	r2, #0
    strb	r2, [r5, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #40	@ 0x28
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r6, r3, #2
    strb	r6, [r0, #0]
    adds	r0, #1
    add	r5, sp, #48	@ 0x30
    ldrb	r5, [r5, #0]
    strb	r5, [r0, #0]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_08032470:
    .4byte vtable_unk_080E68B4
    .global func_08032560
    .thumb_func
func_08032560:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    mov	r9, r3
    ldr	r6, [sp, #48]	@ 0x30
    add	r0, sp, #64	@ 0x40
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r5, [r7, #0]
    ldr r0, .Lde_0803251C
    str	r0, [r7, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r5, #34]	@ 0x22
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r4, [sp, #0]
    mov	r4, r9
    str	r4, [sp, #4]
    str	r6, [sp, #8]
    add	r4, sp, #12
    mov	r6, r8
    strb	r6, [r4, #0]
    bl func_080A49A0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    add	r4, sp, #8
    movs	r2, #0
    strb	r2, [r4, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #52	@ 0x34
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #56]	@ 0x38
    lsls	r3, r3, #2
    str	r3, [sp, #16]
    strb	r3, [r0, #0]
    adds	r0, #1
    add	r6, sp, #60	@ 0x3c
    ldrb	r6, [r6, #0]
    strb	r6, [r0, #0]
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803251C:
    .4byte vtable_unk_080E68B4
    .global func_0803260C
    .thumb_func
func_0803260C:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_08032544
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_08032548
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lde_08032546
.Lde_08032544:
    movs	r0, #0
.Lde_08032546:
    strb	r0, [r1, #0]
.Lde_08032548:
    adds	r1, r4, #0
    adds	r1, #138	@ 0x8a
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r5, r0, #30
    adds	r6, r1, #0
    cmp	r5, #0
    beq .Lde_0803259E
    movs	r7, #0
    subs	r1, #3
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_0803257E
    adds	r0, r4, #0
    adds	r0, #112	@ 0x70
    bl func_0805E8F0
    adds	r2, r0, #0
    lsls	r0, r2, #30
    cmp	r0, #0
    bge .Lde_0803257A
    adds	r1, r4, #0
    adds	r1, #132	@ 0x84
    movs	r0, #1
    strb	r0, [r1, #0]
.Lde_0803257A:
    adds	r0, r2, #0
    b .Lde_08032584
.Lde_0803257E:
    movs	r0, #0
    strb	r0, [r1, #0]
    movs	r0, #2
.Lde_08032584:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lde_08032590
    cmp	r5, #2
    beq .Lde_08032590
    movs	r7, #1
.Lde_08032590:
    cmp	r7, #0
    beq .Lde_0803259E
    ldrb	r1, [r6, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #0]
.Lde_0803259E:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08032690
    .thumb_func
func_08032690:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r6, r0, #0
    mov	sl, r1
    ldr	r0, [r6, #0]
    mov	r8, r0
    ldr	r1, [r0, #0]
    str	r1, [sp, #60]	@ 0x3c
    movs	r2, #10
    ldrsh	r1, [r0, r2]
    mov	r3, sl
    movs	r4, #12
    ldrsh	r0, [r3, r4]
    subs	r1, r1, r0
    str	r1, [sp, #64]	@ 0x40
    mov	r0, r8
    movs	r2, #14
    ldrsh	r1, [r0, r2]
    movs	r4, #14
    ldrsh	r0, [r3, r4]
    subs	r0, r1, r0
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r1
    str	r0, [sp, #72]	@ 0x48
    add	r2, sp, #52	@ 0x34
    ldr	r0, [r3, #0]
    ldr	r1, [r3, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r2, #4]
    adds	r0, r6, #0
    adds	r0, #138	@ 0x8a
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #0
    beq .Lde_080326D6
    cmp	r0, #0
    blt .Lde_080326D6
    cmp	r0, #2
    bgt .Lde_080326D6
    mov	r0, r8
    adds	r0, #32
    ldrb	r0, [r0, #0]
    lsrs	r1, r1, #2
    lsls	r1, r1, #4
    lsls	r0, r0, #2
    ldr r2, .Lde_08032678
    adds	r0, r0, r2
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    movs	r3, #2
    ldrsh	r1, [r1, r3]
    adds	r5, r6, #0
    adds	r5, #72	@ 0x48
    ldr	r4, [sp, #64]	@ 0x40
    adds	r0, r4, r0
    str	r0, [sp, #76]	@ 0x4c
    ldr	r0, [sp, #68]	@ 0x44
    adds	r0, r0, r1
    mov	r9, r0
    adds	r0, r6, #0
    adds	r0, #112	@ 0x70
    ldr	r1, [r6, #112]	@ 0x70
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #116]	@ 0x74
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r3, [sp, #56]	@ 0x38
    ldr	r2, [r6, #72]	@ 0x48
    ldr	r1, [r6, #80]	@ 0x50
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08032680
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #88	@ 0x58
    ldr	r4, [sp, #72]	@ 0x48
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #76]	@ 0x4c
    mov	r2, r9
    movs	r3, #85	@ 0x55
    ldr r4, .Lde_0803267C
    bl _call_via_r4
    b .Lde_08032682
.Lde_08032678:
    .4byte gUnk_080F1328
.Lde_0803267C:
    .4byte func_030004DC
.Lde_08032680:
    movs	r0, #0
.Lde_08032682:
    cmp	r0, #0
    beq .Lde_080326D6
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lde_080326D6
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_080326B6
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_080326D0
.Lde_080326B6:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_080326D0
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_080326D0:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lde_080326D6:
    adds	r0, r6, #0
    adds	r0, #139	@ 0x8b
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lde_08032700
    cmp	r0, #1
    ble .Lde_080326E8
    cmp	r0, #2
    beq .Lde_08032704
.Lde_080326E8:
    mov	r0, r8
    adds	r0, #33	@ 0x21
    ldrb	r0, [r0, #0]
    movs	r1, #3
    ands	r0, r1
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    b .Lde_08032706
.Lde_08032700:
    movs	r4, #25
    b .Lde_08032706
.Lde_08032704:
    movs	r4, #26
.Lde_08032706:
    adds	r5, r6, #0
    adds	r5, #8
    add	r2, sp, #52	@ 0x34
    mov	r8, r2
    ldr	r1, [r6, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r6, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r3, r8
    ldr	r3, [r3, #4]
    mov	r9, r3
    ldr	r2, [r6, #8]
    ldr	r1, [r6, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08032760
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #24
    ldr	r3, [sp, #72]	@ 0x48
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r9
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r4, #0
    ldr r4, .Lde_0803275C
    bl _call_via_r4
    b .Lde_08032762
.Lde_0803275C:
    .4byte func_030004DC
.Lde_08032760:
    movs	r0, #0
.Lde_08032762:
    cmp	r0, #0
    beq .Lde_080327B8
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lde_080327B8
    mov	r4, r8
    ldr	r1, [r4, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08032798
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_080327B2
.Lde_08032798:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_080327B2
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_080327B2:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lde_080327B8:
    adds	r0, r6, #0
    adds	r0, #136	@ 0x88
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lde_080327DA
    cmp	r0, #1
    bgt .Lde_080327CC
    cmp	r0, #0
    beq .Lde_080327D6
    b .Lde_080327DA
.Lde_080327CC:
    cmp	r0, #2
    beq .Lde_080327DE
    cmp	r0, #3
    bne .Lde_080327DA
    b .Lde_08032804
.Lde_080327D6:
    movs	r4, #0
    b .Lde_080327E0
.Lde_080327DA:
    movs	r4, #1
    b .Lde_080327E0
.Lde_080327DE:
    movs	r4, #2
.Lde_080327E0:
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r2, #0
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    adds	r2, r6, #0
    adds	r2, #137	@ 0x89
    movs	r3, #0
    ldrsb	r3, [r2, r3]
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r2, r3
    str	r4, [sp, #0]
    ldr	r2, [sp, #64]	@ 0x40
    bl func_0803AE58
.Lde_08032804:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_region_classification_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032934
    .thumb_func
func_08032934:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r4, r2, #0
    ldrh	r0, [r4, #8]
    str	r0, [sp, #0]
    adds	r0, r5, #0
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lde_0803286C
    str	r0, [r5, #20]
    str	r4, [r5, #48]	@ 0x30
    adds	r0, r5, #0
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lde_0803286C:
    .4byte vtable_unk_080E6828
    .global func_0803295C
    .thumb_func
func_0803295C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lde_080328C0
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldrh	r1, [r5, #34]	@ 0x22
    ldr	r0, [r5, #48]	@ 0x30
    strh	r1, [r0, #8]
    ldr r0, .Lde_080328C4
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_080328A8
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_080328A8:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lde_080328B6
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_080328B6:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_080328C0:
    .4byte vtable_unk_080E6828
.Lde_080328C4:
    .4byte __vt_7AEntity
    .global func_080329B4
    .thumb_func
func_080329B4:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08032A00
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080329CC
    .thumb_func
func_080329CC:
    ldr	r0, [r0, #48]	@ 0x30
    ldrh	r0, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329D4
    .thumb_func
func_080329D4:
    ldr	r0, [r0, #48]	@ 0x30
    strh	r1, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329DC
    .thumb_func
func_080329DC:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #10
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_constructor_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032A30
    .thumb_func
func_08032A30:
    push	{lr}
    adds	r1, r0, #0
    ldrh	r0, [r1, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_08032952
    subs	r0, #1
    b .Lde_08032954
.Lde_08032952:
    ldrh	r0, [r1, #38]	@ 0x26
.Lde_08032954:
    strh	r0, [r1, #36]	@ 0x24
    ldr	r2, [r1, #16]
    cmp	r2, #0
    beq .Lde_08032966
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lde_08032966:
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x3030B500
    .4byte 0xFF0CF02B
    .4byte 0x4708BC02
    .4byte 0x1C01B500
    .4byte 0x22003130
    .4byte 0x280089C8
    .4byte 0x2010D004
    .4byte 0x42485E09
    .4byte 0x0FC24308
    .4byte 0xBC021C10
    .4byte 0x00004708
    .4byte 0x78003044
    .4byte 0x00004770
    .4byte 0x7001308B
    .4byte 0x00004770
    .4byte 0x70013089
    .4byte 0x00004770
    .4byte 0x70013088
    .4byte 0x00004770
    .4byte 0x7802308A
    .4byte 0x42492104
    .4byte 0x70014011
    .4byte 0x00004770
    .4byte 0x1C05B530
    .4byte 0x0E240614
    .4byte 0xF02B3070
    .4byte 0x1C28FEC1
    .4byte 0x22003084
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0x2C002301
    .4byte 0x2302D000
    .4byte 0x328A1C2A
    .4byte 0x20047811
    .4byte 0x40084240
    .4byte 0x70104318
    .4byte 0xBC01BC30
    .4byte 0x00004700
    .4byte 0x0089308A
    .4byte 0x22037803
    .4byte 0x430A401A
    .4byte 0x47707002
    .4byte 0x1C04B510
    .4byte 0xF02B3030
    .4byte 0x1C20FE9B
    .4byte 0x22003044
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0xBC01BC10
    .4byte 0x00004700
    .4byte 0x47708C80
    .4byte 0x2100B500
    .4byte 0x28008C80
    .4byte 0x2101D100
    .4byte 0xBC021C08
    .4byte 0x00004708
    .global func_08032B40
    .thumb_func
func_08032B40:
    bx	lr
    .hword 0x0000
    .4byte 0x1C02B500
    .4byte 0x42888C50
    .4byte 0x1C10D002
    .4byte 0xFB2EF7FF
    .4byte 0x4700BC01
    .4byte 0x47708C40
    .4byte 0x30208C41
    .4byte 0x18097800
    .4byte 0x47701C08
    .4byte 0x1C02B500
    .4byte 0x78003020
    .4byte 0xD0024288
    .4byte 0xF7FF1C10
    .4byte 0xBC01FB0F
    .4byte 0x00004700
    .4byte 0x78003020
    .4byte 0x00004770
    .4byte 0x5E81220E
    .4byte __ewram_bss_end + 0x170
    .4byte 0x47701A40
    .4byte 0x70013021
    .4byte 0x00004770
    .4byte 0x78003021
    .4byte 0x00004770
    .4byte 0x477061C1
    .4byte 0x477069C0
    .4byte 0x47706181
    .4byte 0x47706980
    .global func_08032BB4
    .thumb_func
func_08032BB4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    mov	sl, r2
    str	r3, [sp, #48]	@ 0x30
    mov	r2, sp
    ldrb	r1, [r2, #0]
    movs	r4, #16
    negs	r4, r4
    adds	r0, r4, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    movs	r0, #0
    str	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #48]	@ 0x30
    cmp	r1, #37	@ 0x25
    beq .Lde_08032AF6
    b .Lde_08032D30
.Lde_08032AF6:
    ldr	r2, [sp, #44]	@ 0x2c
    ldr r3, .Lde_08032B44
    adds	r7, r2, r3
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    bne .Lde_08032B08
    b .Lde_08032D30
.Lde_08032B08:
    movs	r6, #0
    str	r6, [sp, #56]	@ 0x38
    adds	r0, r7, #0
    bl GetPregnancyStallCapacity__C4Barn
    mov	r9, r0
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r0, r9
    bcs .Lde_08032BBA
    add	r1, sp, #20
    mov	r8, r1
.Lde_08032B1E:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl GetPregnancyStallLinkedStall__C4BarnUi
    mvns	r0, r0
    lsrs	r4, r0, #31
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl HasBushelForPregnancyStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08032B48
    cmp	r4, #0
    bne .Lde_08032BB4
    ldr	r2, [sp, #56]	@ 0x38
    adds	r2, #1
    str	r2, [sp, #56]	@ 0x38
    b .Lde_08032BB4
.Lde_08032B44:
    .4byte 0x000005DC
.Lde_08032B48:
    cmp	r4, #0
    beq .Lde_08032BB4
    add	r0, sp, #16
    adds	r1, r7, #0
    adds	r2, r6, #0
    bl method_0800D0C0__C4BarnUi
    ldr	r0, [sp, #16]
    str	r0, [sp, #20]
    mov	r3, r8
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    ldr	r2, [sp, #104]	@ 0x68
    subs	r1, r1, r2
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r5, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_08032B8A
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r5, r0
    bcs .Lde_08032BB4
.Lde_08032B8A:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #5
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08032BB4
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Lde_08032BB4:
    adds	r6, #1
    cmp	r6, r9
    bcc .Lde_08032B1E
.Lde_08032BBA:
    movs	r6, #0
    mov	r9, r6
    ldr	r1, [sp, #44]	@ 0x2c
    ldr r2, .Lde_08032C44
    adds	r0, r1, r2
    bl GetCapacity__C4Barn
    adds	r6, r0, #0
    movs	r5, #0
    cmp	r9, r6
    bcs .Lde_08032C1A
.Lde_08032BD0:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetBarnAnimal__C4BarnUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_08032C14
    mov	r3, sl
    ldr	r0, [r3, #0]
    adds	r1, r5, #0
    adds	r1, #54	@ 0x36
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    .hword 0x2800
    .4byte 0x8880D010
    .4byte 0xD10D2825
    .4byte 0xF0681C20
    .4byte 0x0600FC2F
    .4byte 0xD1072800
    .4byte 0xF0681C20
    .4byte 0x0600FE03
    .4byte 0xD1012800
    .4byte 0x44812001
.Lde_08032C14:
    adds	r5, #1
    cmp	r5, r6
    bcc .Lde_08032BD0
.Lde_08032C1A:
    mov	r1, r9
    cmp	r1, #0
    bne .Lde_08032C22
    b .Lde_08032D30
.Lde_08032C22:
    str	r6, [sp, #60]	@ 0x3c
    movs	r2, #0
    mov	r8, r2
    movs	r4, #0
    cmp	r8, r6
    bcs .Lde_08032C62
.Lde_08032C2E:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08032C48
    ldr	r3, [sp, #56]	@ 0x38
    adds	r3, #1
    str	r3, [sp, #56]	@ 0x38
    b .Lde_08032C5A
.Lde_08032C44:
    .4byte 0x000005DC
.Lde_08032C48:
    cmp	r4, #15
    bhi .Lde_08032C5A
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Lde_08032C5A:
    adds	r4, #1
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r4, r0
    bcc .Lde_08032C2E
.Lde_08032C62:
    ldr	r1, [sp, #56]	@ 0x38
    cmp	r9, r1
    bls .Lde_08032D30
    movs	r3, #0
    movs	r4, #31
    movs	r5, #1
    ldr	r2, [sp, #112]	@ 0x70
.Lde_08032C70:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    bne .Lde_08032C92
    ldr	r6, [sp, #56]	@ 0x38
    adds	r6, #1
    str	r6, [sp, #56]	@ 0x38
    ldrb	r1, [r2, #1]
    cmp	r1, #15
    bhi .Lde_08032C92
    ands	r1, r4
    adds	r0, r5, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Lde_08032C92:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Lde_08032C70
    ldr	r2, [sp, #56]	@ 0x38
    cmp	r9, r2
    bls .Lde_08032D30
    movs	r4, #0
    ldr	r3, [sp, #60]	@ 0x3c
    cmp	r4, r3
    bcs .Lde_08032D30
    mov	r6, sp
    adds	r6, #28
    str	r6, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r0, #16
    negs	r0, r0
    mov	r9, r0
.Lde_08032CB6:
    movs	r0, #0
    cmp	r4, #15
    bhi .Lde_08032CCE
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r2, r8
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Lde_08032CCE:
    cmp	r0, #0
    beq .Lde_08032D28
    add	r0, sp, #24
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800D074__C4BarnUi
    ldr	r0, [sp, #24]
    str	r0, [sp, #28]
    ldr	r3, [sp, #68]	@ 0x44
    movs	r6, #0
    ldrsh	r1, [r3, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r6, r1, #0
    muls	r6, r1
    adds	r1, r6, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_08032D10
    ldr	r3, [sp, #52]	@ 0x34
    cmp	r2, r3
    bcs .Lde_08032D28
.Lde_08032D10:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #4
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Lde_08032D28:
    adds	r4, #1
    ldr	r6, [sp, #60]	@ 0x3c
    cmp	r4, r6
    bcc .Lde_08032CB6
.Lde_08032D30:
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r0, #17
    beq .Lde_08032D38
    b .Lde_08032EA0
.Lde_08032D38:
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #2
    adds	r7, r1, r2
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Coop
    cmp	r0, #0
    bne .Lde_08032D4C
    b .Lde_08032EA0
.Lde_08032D4C:
    adds	r0, r7, #0
    bl GetCapacity__C4Coop
    adds	r6, r0, #0
    movs	r3, #0
    mov	r9, r3
    movs	r5, #0
    cmp	r9, r6
    bcs .Lde_08032D9C
.Lde_08032D5E:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetChicken__C4CoopUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lde_08032D96
    mov	r1, sl
    ldr	r0, [r1, #0]
    adds	r1, r5, #0
    adds	r1, #46	@ 0x2e
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    .4byte 0xD00A2800
    .4byte 0x28118880
    .4byte 0x1C20D107
    .4byte 0xFB68F068
    .4byte 0x28000600
    .4byte 0x2201D101
    .hword 0x4491
.Lde_08032D96:
    adds	r5, #1
    cmp	r5, r6
    bcc .Lde_08032D5E
.Lde_08032D9C:
    mov	r3, r9
    cmp	r3, #0
    beq .Lde_08032EA0
    str	r6, [sp, #64]	@ 0x40
    movs	r5, #0
    mov	r8, r5
    movs	r4, #0
    cmp	r8, r6
    bcs .Lde_08032DDA
.Lde_08032DAE:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForEnt__C4CoopUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_08032DC0
    adds	r5, #1
    b .Lde_08032DD2
.Lde_08032DC0:
    cmp	r4, #7
    bhi .Lde_08032DD2
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Lde_08032DD2:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Lde_08032DAE
.Lde_08032DDA:
    cmp	r9, r5
    bls .Lde_08032EA0
    movs	r3, #0
    movs	r4, #31
    movs	r6, #1
    ldr	r2, [sp, #112]	@ 0x70
.Lde_08032DE6:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Lde_08032E04
    adds	r5, #1
    ldrb	r1, [r2, #1]
    cmp	r1, #7
    bhi .Lde_08032E04
    ands	r1, r4
    adds	r0, r6, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Lde_08032E04:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Lde_08032DE6
    cmp	r9, r5
    bls .Lde_08032EA0
    movs	r4, #0
    ldr	r2, [sp, #64]	@ 0x40
    cmp	r4, r2
    bcs .Lde_08032EA0
    mov	r3, sp
    adds	r3, #36	@ 0x24
    str	r3, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r6, #16
    negs	r6, r6
    mov	r9, r6
.Lde_08032E26:
    movs	r0, #0
    cmp	r4, #7
    bhi .Lde_08032E3E
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r0, r8
    ands	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Lde_08032E3E:
    cmp	r0, #0
    beq .Lde_08032E98
    add	r0, sp, #32
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800C6F0__C4CoopUi
    ldr	r0, [sp, #32]
    str	r0, [sp, #36]	@ 0x24
    ldr	r2, [sp, #68]	@ 0x44
    movs	r3, #0
    ldrsh	r1, [r2, r3]
    ldr	r6, [sp, #104]	@ 0x68
    subs	r1, r1, r6
    movs	r3, #2
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_08032E80
    ldr	r6, [sp, #52]	@ 0x34
    cmp	r2, r6
    bcs .Lde_08032E98
.Lde_08032E80:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #3
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Lde_08032E98:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Lde_08032E26
.Lde_08032EA0:
    movs	r6, #54	@ 0x36
    movs	r7, #16
    negs	r7, r7
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r6, #0
    bl _call_via_r2
    .4byte 0x2C001C04
    .4byte 0x88A0D049
    .4byte 0x42909A0C
    .4byte 0x6960D145
    .4byte 0x1C206D01
    .4byte 0xFCD4F0A0
    .4byte 0x28000600
    .4byte 0x6960D10F
    .4byte 0x1C206D41
    .4byte 0xFCCCF0A0
    .4byte 0x28000600
    .4byte 0x6960D107
    .4byte 0x1C206D81
    .4byte 0xFCC4F0A0
    .4byte 0x28000600
    .4byte 0x230AD02D
    .4byte 0x981A5EE1
    .4byte 0x220E1A09
    .4byte 0x9B1B5EA0
    .4byte 0x1C0A1AC0
    .4byte 0x1C11434A
    .4byte 0x43431C03
    .4byte 0x18091C18
    .4byte 0x46681C0D
    .4byte 0x07007800
    .4byte 0xD0022800
    .4byte 0x4281980D
    .4byte 0xAC02D215
    .4byte 0x1C387821
    .4byte 0x21064008
    .4byte 0x70204308
    .4byte 0x38361C30
    .4byte 0x981C7060
    .4byte 0xF06B1C21
    .4byte 0x0600FCC5
    .4byte 0xD1042800
    .4byte 0x1C204669
    .4byte 0xC10CC80C
    .4byte 0x3601950D
    .4byte 0xD9A82E45
    .4byte 0x4656242E
    .4byte 0x6C426830
    .4byte 0x1C214650
    .4byte 0xFC8AF0A0
    .4byte 0x2C353401
    .4byte 0x254CD9F5
    .4byte 0x427F2710
    .4byte 0x68084651
    .4byte 0x46506C42
    .4byte 0xF0A01C29
    .4byte 0x1C02FC7D
    .4byte 0xD0312A00
    .4byte 0x9B0C8890
    .4byte 0xD12D4298
    .4byte 0x5F91260A
    .4byte 0x1A09981A
    .4byte 0x5ED0230E
    .4byte 0x1B809E1B
    .4byte 0x434A1C0A
    .4byte 0x1C031C11
    .4byte 0x1C184343
    .4byte 0x1C0E1809
    .4byte 0x78004668
    .4byte 0x28000700
    .4byte 0x980DD002
    .4byte 0xD2154281
    .4byte 0x7821AC02
    .4byte 0x40081C38
    .4byte 0x43082108
    .4byte 0x1C287020
    .4byte 0x7060384C
    .4byte 0x1C21981C
    .4byte 0xFC78F06B
    .4byte 0x28000600
    .4byte 0x4669D104
    .4byte 0xC80C1C20
    .4byte 0x960DC10C
    .4byte 0x2D533501
    .4byte 0x990AD9C0
    .4byte 0xC8444668
    .4byte 0x980AC144
    .4byte 0xBC38B012
    .4byte 0x46A14698
    .4byte 0xBCF046AA
    .4byte 0x4708BC02
    .global func_080330F4
    .thumb_func
func_080330F4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #108	@ 0x6c
    str	r0, [sp, #68]	@ 0x44
    adds	r5, r1, #0
    adds	r7, r2, #0
    adds	r4, r3, #0
    ldr	r3, [sp, #140]	@ 0x8c
    add	r2, sp, #12
    ldrb	r1, [r2, #0]
    movs	r6, #16
    negs	r6, r6
    adds	r0, r6, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrb	r1, [r4, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #2]
    ldr r2, .Lde_08033064
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    str	r0, [sp, #72]	@ 0x48
    ldrb	r1, [r4, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #4]
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    mov	sl, r0
    cmp	r3, #1
    bne .Lde_08033058
    b .Lde_0803319A
.Lde_08033058:
    cmp	r3, #1
    bgt .Lde_08033068
    cmp	r3, #0
    beq .Lde_08033070
    b .Lde_0803347E
    .align 2, 0
.Lde_08033064:
    .4byte 0x000003FF
.Lde_08033068:
    cmp	r3, #2
    bne .Lde_0803306E
    b .Lde_08033250
.Lde_0803306E:
    b .Lde_0803347E
.Lde_08033070:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    mov	r9, r0
    ldr r1, .Lde_08033108
    adds	r1, r5, r1
    str	r1, [sp, #80]	@ 0x50
    mov	r2, sp
    adds	r2, #32
    str	r2, [sp, #84]	@ 0x54
.Lde_08033082:
    movs	r7, #0
    mov	r3, r9
    lsls	r3, r3, #1
    str	r3, [sp, #100]	@ 0x64
    mov	r4, r9
    adds	r4, #1
    str	r4, [sp, #96]	@ 0x60
    ldr	r6, [sp, #72]	@ 0x48
    negs	r0, r6
    movs	r1, #140	@ 0x8c
    lsls	r1, r1, #1
    adds	r6, r0, r1
.Lde_0803309A:
    ldr	r0, [sp, #100]	@ 0x64
    adds	r0, #23
    lsls	r0, r0, #3
    mov	r2, sl
    subs	r0, r0, r2
    adds	r1, r6, #0
    muls	r1, r6
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    mov	r8, r1
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_080330C2
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r8, r4
    bcs .Lde_08033186
.Lde_080330C2:
    movs	r0, #43	@ 0x2b
    mov	r1, r9
    muls	r1, r0
    adds	r0, r1, #0
    adds	r0, r7, r0
    lsls	r0, r0, #2
    ldr	r2, [sp, #80]	@ 0x50
    adds	r0, r2, r0
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r0, r0, #28
    cmp	r0, #5
    bne .Lde_08033102
    str	r1, [sp, #28]
    add	r0, sp, #20
    add	r1, sp, #28
    bl method_0800A4A4__9FieldPlot
    add	r5, sp, #20
    adds	r0, r5, #0
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08033102
    adds	r0, r5, #0
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Lde_0803310C
    cmp	r0, #1
    beq .Lde_08033134
.Lde_08033102:
    movs	r1, #0
    b .Lde_08033152
    .align 2, 0
.Lde_08033108:
    .4byte 0x000009C8
.Lde_0803310C:
    add	r0, sp, #24
    adds	r1, r5, #0
    bl GetFood__C12RucksackItem
    add	r0, sp, #24
    ldrb	r1, [r0, #0]
    adds	r0, #1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #26
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    ldr	r0, [sp, #84]	@ 0x54
    bl __7ProductG4Food
    ldr	r0, [sp, #84]	@ 0x54
    b .Lde_08033148
.Lde_08033134:
    mov	r4, sp
    adds	r4, #33	@ 0x21
    adds	r0, r5, #0
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl __7ProductG7Article
    adds	r0, r4, #0
.Lde_08033148:
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r1, r1, #31
.Lde_08033152:
    cmp	r1, #0
    beq .Lde_08033186
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #2
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r7, [r4, #1]
    mov	r3, r9
    strb	r3, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_08033186
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r4}
    stmia	r1!, {r2, r4}
    mov	r3, r8
    str	r3, [sp, #76]	@ 0x4c
.Lde_08033186:
    adds	r6, #16
    adds	r7, #1
    cmp	r7, #42	@ 0x2a
    bls .Lde_0803309A
    ldr	r4, [sp, #96]	@ 0x60
    mov	r9, r4
    cmp	r4, #24
    bhi .Lde_08033198
    b .Lde_08033082
.Lde_08033198:
    b .Lde_0803347E
.Lde_0803319A:
    movs	r0, #0
    str	r0, [sp, #88]	@ 0x58
    movs	r7, #0
    ldr r1, .Lde_0803324C
    adds	r1, r1, r5
    mov	r9, r1
.Lde_080331A6:
    movs	r6, #0
    adds	r2, r7, #1
    mov	r8, r2
    ldr	r3, [sp, #72]	@ 0x48
    negs	r0, r3
    movs	r4, #140	@ 0x8c
    lsls	r4, r4, #1
    adds	r5, r0, r4
.Lde_080331B6:
    movs	r0, #43	@ 0x2b
    muls	r0, r7
    adds	r0, r6, r0
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r2, r0, #28
    movs	r3, #0
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_080331E2
    subs	r0, r2, #1
    cmp	r0, #3
    bhi .Lde_080331E2
    lsls	r0, r1, #24
    lsrs	r0, r0, #26
    movs	r1, #20
    eors	r0, r1
    negs	r0, r0
    lsrs	r3, r0, #31
.Lde_080331E2:
    cmp	r3, #0
    beq .Lde_0803323C
    lsls	r0, r7, #4
    adds	r0, #184	@ 0xb8
    mov	r1, sl
    subs	r0, r0, r1
    adds	r1, r5, #0
    muls	r1, r5
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r1, r1, r0
    adds	r2, r1, #0
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_0803320C
    ldr	r3, [sp, #88]	@ 0x58
    cmp	r1, r3
    bcs .Lde_0803323C
.Lde_0803320C:
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    strb	r7, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    str	r2, [sp, #104]	@ 0x68
    bl func_0809E968
    lsls	r0, r0, #24
    ldr	r2, [sp, #104]	@ 0x68
    cmp	r0, #0
    bne .Lde_0803323C
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    str	r2, [sp, #88]	@ 0x58
.Lde_0803323C:
    adds	r5, #16
    adds	r6, #1
    cmp	r6, #42	@ 0x2a
    bls .Lde_080331B6
    mov	r7, r8
    cmp	r7, #24
    bls .Lde_080331A6
    b .Lde_0803347E
.Lde_0803324C:
    .4byte 0x000009C8
.Lde_08033250:
    add	r0, sp, #36	@ 0x24
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    add	r6, sp, #40	@ 0x28
    mov	r8, r6
    add	r0, sp, #44	@ 0x2c
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [sp, #48]	@ 0x30
    add	r6, sp, #48	@ 0x30
    add	r0, sp, #52	@ 0x34
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #52]	@ 0x34
    str	r0, [sp, #56]	@ 0x38
    mov	r0, sp
    adds	r0, #56	@ 0x38
    str	r0, [sp, #92]	@ 0x5c
    add	r0, sp, #60	@ 0x3c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [sp, #64]	@ 0x40
    add	r1, sp, #64	@ 0x40
    mov	r9, r1
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r0, #17
    bne .Lde_08033294
    b .Lde_080333FE
.Lde_08033294:
    cmp	r0, #17
    bgt .Lde_0803329E
    cmp	r0, #2
    beq .Lde_080332A4
    b .Lde_0803347E
.Lde_0803329E:
    cmp	r0, #37	@ 0x25
    beq .Lde_0803337A
    b .Lde_0803347E
.Lde_080332A4:
    ldr	r2, [sp, #72]	@ 0x48
    str	r2, [sp, #0]
    mov	r3, sl
    str	r3, [sp, #4]
    ldr	r4, [sp, #144]	@ 0x90
    str	r4, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_080332D2
    b .Lde_0803347E
.Lde_080332D2:
    mov	r1, r8
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    mov	r2, r8
    movs	r1, #2
    ldrsh	r0, [r2, r1]
    mov	r2, sl
    subs	r1, r0, r2
    adds	r2, r3, #0
    muls	r2, r3
    adds	r0, r1, #0
    muls	r0, r1
    adds	r2, r2, r0
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    mov	r6, sl
    subs	r1, r0, r6
    adds	r0, r3, #0
    muls	r0, r3
    adds	r3, r1, #0
    muls	r3, r1
    adds	r1, r3, #0
    adds	r0, r0, r1
    cmp	r2, r0
    bhi .Lde_0803332C
    ldr	r6, [sp, #92]	@ 0x5c
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Lde_080333C0
.Lde_0803332C:
    mov	r6, r9
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lde_0803335E
    b .Lde_0803347E
.Lde_0803335E:
    ldr	r3, [sp, #92]	@ 0x5c
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Lde_080333F0
.Lde_0803337A:
    ldr	r6, [sp, #72]	@ 0x48
    str	r6, [sp, #0]
    mov	r0, sl
    str	r0, [sp, #4]
    ldr	r1, [sp, #144]	@ 0x90
    str	r1, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lde_0803347E
    mov	r6, r8
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
.Lde_080333C0:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lde_0803347E
    mov	r3, r9
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
.Lde_080333F0:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    b .Lde_0803347E
.Lde_080333FE:
    ldr	r0, [sp, #72]	@ 0x48
    str	r0, [sp, #0]
    mov	r1, sl
    str	r1, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lde_0803347E
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lde_0803347E
    ldr	r1, [sp, #92]	@ 0x5c
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #0]
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    str	r0, [sp, #4]
    ldr	r6, [sp, #144]	@ 0x90
    str	r6, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
.Lde_0803347E:
    ldr	r1, [sp, #68]	@ 0x44
    add	r0, sp, #12
    ldmia	r0!, {r4, r6}
    stmia	r1!, {r4, r6}
    ldr	r0, [sp, #68]	@ 0x44
    add	sp, #108	@ 0x6c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033584
    .thumb_func
func_08033584:
    push	{r4, r5, r6, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r3, r2, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lde_0803355C
    lsls	r0, r0, #2
    ldr r1, .Lde_080334B8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_080334B8:
    .4byte .Lde_080334BC
.Lde_080334BC:
    .4byte .Lde_0803355C
    .4byte .Lde_080334E0
    .4byte .Lde_0803351C
    .4byte .Lde_080335B8
    .4byte .Lde_080335D4
    .4byte .Lde_080335F4
    .4byte .Lde_0803361C
    .4byte .Lde_08033668
    .4byte .Lde_08033678
.Lde_080334E0:
    .4byte 0x480D78A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F020508
    .4byte 0x07882300
    .4byte 0x28010F80
    .4byte 0x1E50D108
    .4byte 0xD8052803
    .4byte 0x0E800608
    .4byte 0x40482114
    .4byte 0x0FC34240
    .4byte 0xE0BA1C18
    .4byte 0x000009C8
.Lde_0803351C:
    .4byte 0x481078A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F000508
    .4byte 0xD1112805
    .4byte 0xA9029102
    .4byte 0xF7D64668
    .4byte 0x4668FFC1
    .4byte 0xFDA2F7DB
    .4byte 0x28000600
    .4byte 0x4668D106
    .4byte 0xFDB4F7DB
    .4byte 0xD0052800
    .4byte 0xD01D2801
.Lde_0803355C:
    movs	r0, #0
    b .Lde_0803368E
    .4byte 0x000009C8
    .4byte 0xA801AC03
    .4byte 0xF7DB4669
    .4byte 0xA801FDAB
    .4byte 0x30017801
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x78093106
    .4byte 0x43010409
    .4byte 0xF7DA1C20
    .4byte 0x1C20FDC9
    .4byte 0xFE14F7DA
    .4byte 0x43014241
    .4byte 0xE07A0FC8
    .4byte 0x340D466C
    .4byte 0xF7DB4668
    .4byte 0x1C01FDB3
    .4byte 0xF7DA1C20
    .4byte 0x1C20FDDF
    .4byte 0xFE04F7DA
    .4byte 0x43014241
    .4byte 0xE06A0FC8
.Lde_080335B8:
    .4byte 0x20FF2600
    .4byte 0x182D0080
    .4byte 0xF7D81C28
    .4byte 0x2800FFE1
    .4byte 0x7861D024
    .4byte 0xF7D81C28
    .4byte 0xE01BFFF3
.Lde_080335D4:
    .4byte 0x48062600
    .4byte 0x1C28182D
    .4byte 0xFC56F7D9
    .4byte 0xD0172800
    .4byte 0x1C287861
    .4byte 0xFC6EF7D9
    .4byte 0x0000E00E
    .4byte 0x000005DC
.Lde_080335F4:
    .4byte 0x48082600
    .4byte 0x1C28182D
    .4byte 0xFC46F7D9
    .4byte 0xD0072800
    .4byte 0x1C287861
    .4byte 0xFC74F7D9
    .4byte 0x28000600
    .4byte 0x2601D100
    .4byte 0xE03A1C30
    .4byte 0x000005DC
.Lde_0803361C:
    .4byte 0x31367861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C04F927
    .4byte 0x2C002500
    .4byte 0x6960D018
    .4byte 0x1C206D01
    .4byte 0xF91CF0A0
    .4byte 0x28000600
    .4byte 0x6960D10F
    .4byte 0x1C206D41
    .4byte 0xF914F0A0
    .4byte 0x28000600
    .4byte 0x6960D107
    .4byte 0x1C206D81
    .4byte 0xF90CF0A0
    .4byte 0x28000600
    .4byte 0x2501D000
    .4byte 0xE0121C28
.Lde_08033668:
    .4byte 0x312E7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0xE771F901
.Lde_08033678:
    .4byte 0x314C7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C01F8F9
    .4byte 0x43084248
    .hword 0x0FC0
.Lde_0803368E:
    add	sp, #16
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033784
    .thumb_func
func_08033784:
    push	{r4, lr}
    adds	r3, r0, #0
    adds	r4, r2, #0
    ldrb	r0, [r3, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lde_08033706
    lsls	r0, r0, #2
    ldr r1, .Lde_080336B4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_080336B4:
    .4byte .Lde_080336B8
.Lde_080336B8:
    .4byte .Lde_08033706
    .4byte .Lde_080336DC
    .4byte .Lde_080336DC
    .4byte .Lde_080336E0
    .4byte .Lde_080336E4
    .4byte .Lde_080336E4
    .4byte .Lde_080336E8
    .4byte .Lde_080336EE
    .4byte .Lde_080336F4
.Lde_080336DC:
    .4byte 0xE0162002
.Lde_080336E0:
    .4byte 0xE0142011
.Lde_080336E4:
    .4byte 0xE0122025
.Lde_080336E8:
    .4byte 0x31367859
    .hword 0xE004
.Lde_080336EE:
    .hword 0x7859
    .4byte 0xE001312E
.Lde_080336F4:
    .4byte 0x314C7859
    .4byte 0x6C426820
    .4byte 0xF0A01C20
    .4byte 0x2800F8BB
    .hword 0xD102
.Lde_08033706:
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    b .Lde_0803370E
    .hword 0x8880
.Lde_0803370E:
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08033800
    .thumb_func
func_08033800:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, r1, #0
    adds	r1, r2, #0
    ldr	r2, [r0, #0]
    ldr	r2, [r2, #68]	@ 0x44
    bl _call_via_r2
    .4byte 0x29001C01
    .4byte 0x220AD005
    .4byte 0x220E5E88
    .4byte 0x80205E89
    .4byte 0x8021E000
    .4byte 0x1C208061
    .4byte 0xBC02BC10
    .4byte 0x00004708
    .global func_08033830
    .thumb_func
func_08033830:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lde_08033788
    lsls	r0, r0, #2
    ldr r1, .Lde_08033760
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_08033760:
    .4byte .Lde_08033764
.Lde_08033764:
    .4byte .Lde_08033788
    .4byte .Lde_08033790
    .4byte .Lde_08033790
    .4byte .Lde_080337A6
    .4byte .Lde_080337B6
    .4byte .Lde_080337C8
    .4byte .Lde_080337DC
    .4byte .Lde_080337E2
    .4byte .Lde_080337F0
.Lde_08033788:
    movs	r0, #0
    strh	r0, [r5, #0]
    strh	r0, [r5, #2]
    b .Lde_080337FC
.Lde_08033790:
    .4byte 0x78A17860
    .4byte 0x228C0100
    .4byte 0x18800052
    .4byte 0x31B80109
    .4byte 0x80698028
    .hword 0xE02A
.Lde_080337A6:
    .hword 0x20FF
    .4byte 0x18110080
    .4byte 0x1C287862
    .4byte 0xFFAEF7D8
    .hword 0xE022
.Lde_080337B6:
    .hword 0x4803
    .4byte 0x78621811
    .4byte 0xF7D91C28
    .4byte 0xE01BFC69
    .4byte 0x000005DC
.Lde_080337C8:
    .4byte 0x18114803
    .4byte 0x1C287862
    .4byte 0xFC86F7D9
    .4byte 0x0000E012
    .4byte 0x000005DC
.Lde_080337DC:
    .4byte 0x32367862
    .hword 0xE001
.Lde_080337E2:
    .hword 0x7862
    .4byte 0x1C28322E
    .4byte 0xF7FF1C19
    .4byte 0xE005FF93
.Lde_080337F0:
    .4byte 0x324C7862
    .4byte 0x1C191C28
    .4byte 0xFF8CF7FF
.Lde_080337FC:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_080338F0
    .thumb_func
func_080338F0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #2
    bl func_080AB788
    movs	r1, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #1
    adds	r4, r4, r2
    cmp	r0, r4
    bcs .Lde_0803381E
    movs	r1, #1
.Lde_0803381E:
    adds	r0, r1, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_harvest_sprite_task_experience_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033928
    .thumb_func
func_08033928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    adds	r4, r3, #0
    ldr r1, .Lde_080338B8
    lsls	r0, r6, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    add	r0, sp, #4
    adds	r1, r4, #0
    bl func_080A03B8
    ldr r1, .Lde_080338BC
    lsls	r0, r6, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    add	r2, sp, #4
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lde_080338C0
    str	r0, [r7, #20]
    adds	r0, r7, #0
    adds	r0, #48	@ 0x30
    movs	r5, #0
    strb	r6, [r0, #0]
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_080A099C
    str	r0, [r7, #52]	@ 0x34
    movs	r0, #135	@ 0x87
    lsls	r0, r0, #3
    adds	r4, r4, r0
    str	r4, [r7, #56]	@ 0x38
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [r7, #60]	@ 0x3c
    adds	r0, r7, #0
    adds	r0, #65	@ 0x41
    strb	r5, [r0, #0]
    adds	r0, #1
    strb	r5, [r0, #0]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    mov	r8, r0
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Lde_0803391C
    lsls	r0, r0, #2
    ldr r1, .Lde_080338C4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_080338B8:
    .4byte gUnk_080F149C
.Lde_080338BC:
    .4byte gUnk_080F14E2
.Lde_080338C0:
    .4byte vtable_unk_080E68C8
.Lde_080338C4:
    .4byte .Lde_080338C8
.Lde_080338C8:
    .4byte .Lde_080338EC
    .4byte .Lde_0803391A
    .4byte .Lde_080338E4
    .4byte .Lde_08033900
    .4byte .Lde_080338E0
    .4byte .Lde_0803391A
.Lde_080338E0:
    .4byte 0xE01B2504
.Lde_080338E4:
    .4byte 0x30226B78
    .4byte 0xE0177805
.Lde_080338EC:
    .4byte 0x1C20AC03
    .4byte 0xF06A1C31
    .4byte 0x1C38FF37
    .4byte 0xF7FE1C21
    .4byte 0xE00DFB99
.Lde_08033900:
    .4byte 0x6B7C2501
    .4byte 0xF06A1C20
    .4byte 0x1C01FE59
    .4byte 0xF06A1C20
    .4byte 0xF7FFFE5D
    .4byte 0x4680FF89
    .hword 0xE000
.Lde_0803391A:
    .hword 0x2501
.Lde_0803391C:
    mvns	r1, r5
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    strb	r1, [r0, #0]
    subs	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    mov	r3, r8
    bl func_08034180
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033A2C
    .thumb_func
func_08033A2C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lde_0803398C
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__3NpcRC13ActorLocation
    ldr r0, .Lde_08033990
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lde_08033974
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lde_08033974:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lde_08033982
    adds	r0, r5, #0
    bl __builtin_delete
.Lde_08033982:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_0803398C:
    .4byte vtable_unk_080E68C8
.Lde_08033990:
    .4byte __vt_7AEntity
    .global func_08033A80
    .thumb_func
func_08033A80:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    movs	r0, #212	@ 0xd4
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08034A14
    adds	r5, r0, #0
    movs	r1, #1
    negs	r1, r1
    adds	r4, #64	@ 0x40
    ldrb	r0, [r4, #0]
    cmp	r0, #2
    beq .Lde_080339B8
    cmp	r0, #3
    beq .Lde_080339BC
    b .Lde_080339BE
.Lde_080339B8:
    movs	r1, #8
    b .Lde_080339C2
.Lde_080339BC:
    movs	r1, #5
.Lde_080339BE:
    cmp	r1, #0
    blt .Lde_080339EE
.Lde_080339C2:
    adds	r0, r5, #0
    adds	r0, #112	@ 0x70
    bl ResolveIndexedResourceHandle
    adds	r0, r5, #0
    adds	r0, #132	@ 0x84
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r3, r5, #0
    adds	r3, #138	@ 0x8a
    movs	r2, #2
    ldrb	r1, [r3, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r3, #0]
.Lde_080339EE:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033AE4
    .thumb_func
func_08033AE4:
    push	{lr}
    movs	r1, #0
    strb	r1, [r0, #6]
    adds	r2, r0, #0
    adds	r2, #66	@ 0x42
    movs	r1, #1
    strb	r1, [r2, #0]
    bl func_08033B7C
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08033AFC
    .thumb_func
func_08033AFC:
    ldr r1, .Lde_08033A20
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Lde_08033A20:
    .4byte gUnk_080F14D4
    .global func_08033B10
    .thumb_func
func_08033B10:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    ldr	r0, [r4, #52]	@ 0x34
    bl SetChangedLocation__3Npc
    pop	{r4}
    pop	{r0}
    bx	r0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_unknown_flag_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033B84
    .thumb_func
func_08033B84:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lde_08033AA4
    bl func_08034BFC
.Lde_08033AA4:
    pop	{r0}
    bx	r0
    .global func_08033B94
    .thumb_func
func_08033B94:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #172	@ 0xac
    adds	r7, r0, #0
    adds	r2, r1, #0
    ldr	r0, [r7, #52]	@ 0x34
    mov	r8, r0
    ldr	r1, [r7, #0]
    mov	sl, r1
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Lde_08033AEC
    lsls	r0, r0, #2
    ldr r1, .Lde_08033AD0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_08033AD0:
    .4byte .Lde_08033AD4
.Lde_08033AD4:
    .4byte .Lde_08033AEC
    .4byte .Lde_08033B78
    .4byte .Lde_08033BA8
    .4byte .Lde_08033D10
    .4byte .Lde_08033F68
    .4byte .Lde_08033F8C
.Lde_08033AEC:
    ldrb	r0, [r2, #4]
    cmp	r0, #0
    bne .Lde_08033AF4
    b .Lde_08034024
.Lde_08033AF4:
    mov	r0, r8
    bl GetCurrentTask__C13HarvestSprite
    cmp	r0, #3
    bne .Lde_08033B00
    b .Lde_08034024
.Lde_08033B00:
    mov	r0, r8
    bl GetWorkDaysLeft__C13HarvestSprite
    cmp	r0, #0
    bne .Lde_08033B0C
    b .Lde_08034024
.Lde_08033B0C:
    mov	r2, sl
    ldr	r0, [r2, #0]
    movs	r3, #162	@ 0xa2
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrb	r1, [r2, #10]
    movs	r0, #31
    ands	r0, r1
    cmp	r0, #6
    beq .Lde_08033B2C
    b .Lde_08034024
.Lde_08033B2C:
    ldrh	r0, [r2, #10]
    lsls	r0, r0, #21
    lsrs	r0, r0, #26
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    adds	r1, #1
    cmp	r0, r1
    beq .Lde_08033B40
    b .Lde_08034024
.Lde_08033B40:
    ldr	r0, [r2, #0]
    subs	r0, #3
    cmp	r0, #1
    bls .Lde_08033B70
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #1
    movs	r3, #8
    negs	r3, r3
    adds	r0, r7, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    add	r1, sp, #72	@ 0x48
    mov	r0, r8
    bl method_0809E7D0__13HarvestSprite
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #0
    bl func_08034180
    b .Lde_08034024
.Lde_08033B70:
    mov	r0, r8
    bl TaskDayUpdate__13HarvestSprite
    b .Lde_08034024
.Lde_08033B78:
    .4byte 0x280288B8
    .4byte 0x22B4D00E
    .4byte 0x23080052
    .4byte 0x1C38425B
    .4byte 0xF7EC2102
    .4byte 0x2380F8FF
    .4byte 0x1C38021B
    .4byte 0x22002101
    .4byte 0xFA7CF000
    .4byte 0x5F38240E
    .4byte 0xDC002877
    .4byte 0xE1E9E23E
.Lde_08033BA8:
    .4byte 0x35204645
    .4byte 0x46469525
    .4byte 0x28008C30
    .4byte 0xE0A7D000
    .4byte 0xF0001C38
    .4byte 0x0600FE4B
    .4byte 0xD0002800
    .4byte 0x78E8E22E
    .4byte 0xD0042800
    .4byte 0x70E83801
    .4byte 0x28000600
    .4byte 0x1C38D106
    .4byte 0xFACCF000
    .4byte 0x28000600
    .4byte 0xE21FD000
    .4byte 0x1C284D0F
    .4byte 0xF0772105
    .4byte 0x0084FDCF
    .4byte 0x26001964
    .4byte 0x70889925
    .4byte 0x78A0253C
    .4byte 0xF0774368
    .4byte 0x7861FD73
    .4byte 0x18094369
    .4byte 0x80119A25
    .4byte 0xA81388BC
    .4byte 0x80468006
    .4byte 0x2C114681
    .4byte 0x2C11D025
    .4byte 0x2C02DC04
    .4byte 0xE02CD005
    .4byte gUnk_080F143C
    .4byte 0xD00F2C25
    .4byte 0x2048E027
    .4byte 0xFD5AF077
    .4byte 0x464B3080
    .4byte 0x20488018
    .4byte 0xFD54F077
    .4byte 0x006D2594
    .4byte 0x464E1940
    .4byte 0xE0188070
    .4byte 0xF0772068
    .4byte 0x3048FD4B
    .4byte 0x80084649
    .4byte 0xF0772030
    .4byte 0x3060FD45
    .4byte 0x8050464A
    .4byte 0x2040E00B
    .4byte 0xFD3EF077
    .4byte 0x464B3090
    .4byte 0x20308018
    .4byte 0xFD38F077
    .4byte 0x464D3070
    .4byte 0x1C388068
    .4byte 0x78003020
    .4byte 0x46564680
    .4byte 0xA8026831
    .4byte 0x46516B4B
    .4byte 0xF09F1C22
    .4byte 0x6979FDF3
    .4byte 0x68CAA814
    .4byte 0xF09F1C39
    .4byte 0x9814FDEB
    .4byte 0x90299915
    .4byte 0xAC05912A
    .4byte 0x468A2120
    .4byte 0x21212500
    .4byte 0x20219105
    .4byte 0x60604240
    .4byte 0x60E160A0
    .4byte 0xA802A90A
    .4byte 0xC14CC84C
    .4byte 0x992A9829
    .4byte 0x910E900D
    .4byte 0x62A14651
    .4byte 0x632562E5
    .4byte 0x5EB8220A
    .4byte 0x5EF9230E
    .4byte 0x2600464D
    .4byte 0xAB135FAA
    .4byte 0x5F5B2502
    .4byte 0x46469400
    .4byte 0xF0779601
    .4byte 0x1C02FF55
    .4byte 0x78819825
    .4byte 0x021B2380
    .4byte 0xF0001C38
    .4byte 0xE18DF9C7
    .4byte 0x46413801
    .4byte 0xE1898408
.Lde_08033D10:
    .4byte 0x32204642
    .4byte 0x1C3C9226
    .4byte 0x78203430
    .4byte 0x00C06BB9
    .4byte 0x46891809
    .4byte 0x46486BF9
    .4byte 0xF7FF4652
    .4byte 0x1C06FCB5
    .4byte 0x200A88BD
    .4byte 0x93275E3B
    .4byte 0x5EB9220E
    .4byte 0xA8169128
    .4byte 0x80418003
    .4byte 0xD10842AE
    .4byte 0xA8176BFA
    .4byte 0x46534649
    .4byte 0xFCF8F7FF
    .4byte 0x90169817
    .4byte 0x2D11E027
    .4byte 0x2D11D01D
    .4byte 0x2D02DC02
    .4byte 0xE01ED003
    .4byte 0xD0102D25
    .4byte 0x2E11E01B
    .4byte 0x2E25D007
    .4byte 0xA818D117
    .4byte 0xFEC0F7D5
    .4byte 0x90169818
    .4byte 0xA819E013
    .4byte 0xFEC0F7D5
    .4byte 0x90169819
    .4byte 0xA81AE00D
    .4byte 0xF872F7D9
    .4byte 0x9016981A
    .4byte 0xA81BE007
    .4byte 0xFBEAF7D8
    .4byte 0x9016981B
    .4byte 0x268DE001
    .4byte 0x208D00B6
    .4byte 0x42860080
    .4byte 0xAB16D077
    .4byte 0x5E982200
    .4byte 0x1A409927
    .4byte 0xDA002800
    .4byte 0x28074240
    .4byte 0x235ADC6D
    .4byte 0x2200446B
    .4byte 0x99285E98
    .4byte 0x28001A40
    .4byte 0x4240DA00
    .4byte 0xDC622807
    .4byte 0xF0001C38
    .4byte 0x0600FD39
    .4byte 0x29000E01
    .4byte 0xE11BD000
    .4byte 0xD11942AE
    .4byte 0xF0001C38
    .4byte 0x0600FA45
    .4byte 0xD1002800
    .4byte 0x4908E0BE
    .4byte 0x4008981C
    .4byte 0x4308213C
    .4byte 0xA91C901C
    .4byte 0xF06A4640
    .4byte 0x1C38FC9F
    .4byte 0x78023020
    .4byte 0x21041C38
    .4byte 0x0000E0E3
    .4byte 0xFFFF0000
    .4byte 0xA81D2402
    .4byte 0x80418001
    .4byte 0x2D114680
    .4byte 0x2D11D01C
    .4byte 0x2D02DC02
    .4byte 0xE01CD003
    .4byte 0xD0102D25
    .4byte 0x2E11E019
    .4byte 0x2E25D007
    .4byte 0x2425D115
    .4byte 0xF7D9A81E
    .4byte 0x981EF813
    .4byte 0x2411E00E
    .4byte 0xF7D8A81F
    .4byte 0x981FFB8B
    .4byte 0xA820E008
    .4byte 0xFE4AF7D5
    .4byte 0xE0039820
    .4byte 0xF7D5A821
    .4byte 0x9821FE4B
    .4byte 0x4643901D
    .4byte 0x5F5A2500
    .4byte 0x2602A81D
    .4byte 0x1C385F83
    .4byte 0xF7EB1C21
    .4byte 0x1C38FF81
    .4byte 0x78023020
    .4byte 0x21001C38
    .4byte 0xF0002300
    .4byte 0x2000F8FD
    .4byte 0x80089926
    .4byte 0x9A26E0C0
    .4byte 0x28008810
    .4byte 0x1C38D15A
    .4byte 0xFCD2F000
    .4byte 0x28000600
    .4byte 0xE0B5D000
    .4byte 0x6BB87821
    .4byte 0x184000C9
    .4byte 0x46526BF9
    .4byte 0xFAE8F7FF
    .4byte 0x28000600
    .4byte 0x4640D056
    .4byte 0xFB74F06A
    .4byte 0x46401C01
    .4byte 0xFB78F06A
    .4byte 0xFCA4F7FF
    .4byte 0xAC161C06
    .4byte 0x5EE12300
    .4byte 0x22021C25
    .4byte 0x9B285EA8
    .4byte 0x9C271AC0
    .4byte 0x29001B09
    .4byte 0x4249DA00
    .4byte 0xDA002800
    .4byte 0x18084240
    .4byte 0x18400FC1
    .4byte 0x04001040
    .4byte 0xF09C1C31
    .4byte 0xAB23FF8D
    .4byte 0x22B46018
    .4byte 0x6002A822
    .4byte 0x428A6819
    .4byte 0x1C18D900
    .4byte 0xF0776800
    .4byte 0x9926FBDF
    .4byte 0x1C388008
    .4byte 0x78043020
    .4byte 0xF077A802
    .4byte 0xA816FD31
    .4byte 0x5EC22300
    .4byte 0x5E6B2102
    .4byte 0x9500AD02
    .4byte 0x98279401
    .4byte 0xF0779928
    .4byte 0x1C02FE27
    .4byte 0x21011C38
    .4byte 0xF0001C33
    .4byte 0xE061F89B
    .4byte 0x9E263801
    .4byte 0xE05D8030
.Lde_08033F68:
    .4byte 0x8C084641
    .4byte 0xD1092800
    .4byte 0xF0001C38
    .4byte 0x0600FC6F
    .4byte 0xD1532800
    .4byte 0xF0001C38
    .4byte 0xE04FF935
    .4byte 0x46423801
    .4byte 0xE04B8410
.Lde_08033F8C:
    .4byte 0x5EF9230A
    .4byte 0x004020B4
    .4byte 0xD12A4281
    .4byte 0x280069F8
    .4byte 0x2380DB07
    .4byte 0x1C38021B
    .4byte 0x22012101
    .4byte 0xF874F000
    .4byte 0x240EE03A
    .4byte 0x20085F39
    .4byte 0x42814240
    .4byte 0x4640DC34
    .4byte 0xFB7EF06A
    .4byte 0x4640A924
    .4byte 0xFBB0F06A
    .4byte 0x30301C38
    .4byte 0xA8027801
    .4byte 0xFBC8F06A
    .4byte 0xA9021C38
    .4byte 0xF82AF7FE
    .4byte 0x30201C38
    .4byte 0x1C387802
    .4byte 0x23002100
    .4byte 0xF854F000
    .4byte 0x69BAE01A
    .4byte 0x48052300
    .4byte 0xDC004281
    .4byte 0x1C182301
    .4byte 0xD0052800
    .4byte 0xDD052A00
    .4byte 0x0000E00E
    .4byte 0x00000167
    .4byte 0xDB092A00
    .4byte 0x28002202
    .4byte 0x2203D000
    .4byte 0x021B2380
    .4byte 0x21011C38
    .4byte 0xF838F000
.Lde_08034024:
    adds	r4, r7, #0
    adds	r4, #66	@ 0x42
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lde_0803404C
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    ldrb	r1, [r0, #0]
    adds	r0, r7, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_08034048
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Lde_08034048:
    movs	r0, #0
    strb	r0, [r4, #0]
.Lde_0803404C:
    ldr	r1, [r7, #28]
    cmp	r1, #0
    beq .Lde_08034058
    ldr	r0, [r7, #12]
    adds	r0, r0, r1
    str	r0, [r7, #12]
.Lde_08034058:
    ldr	r1, [r7, #24]
    cmp	r1, #0
    beq .Lde_08034064
    ldr	r0, [r7, #8]
    adds	r0, r0, r1
    str	r0, [r7, #8]
.Lde_08034064:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_0803406E
    subs	r0, #1
    b .Lde_08034070
.Lde_0803406E:
    ldrh	r0, [r7, #38]	@ 0x26
.Lde_08034070:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r4, [r7, #16]
    cmp	r4, #0
    beq .Lde_08034082
    ldr	r0, [r4, #4]
    ldr	r1, [r0, #12]
    adds	r0, r4, #0
    bl _call_via_r1
.Lde_08034082:
    add	sp, #172	@ 0xac
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034180
    .thumb_func
func_08034180:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r7, r1, #0
    adds	r5, r2, #0
    adds	r6, r3, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lde_080340B0
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lde_080340B0:
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r5
    beq .Lde_080340C2
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lde_080340C2:
    adds	r0, r4, #0
    adds	r0, #66	@ 0x42
    movs	r1, #0
    strb	r1, [r0, #0]
    cmp	r7, #1
    beq .Lde_080340E4
    cmp	r7, #1
    bgt .Lde_080340D8
    cmp	r7, #0
    beq .Lde_080340DC
    b .Lde_0803411E
.Lde_080340D8:
    cmp	r7, #4
    bgt .Lde_0803411E
.Lde_080340DC:
    movs	r0, #0
    str	r0, [r4, #24]
    str	r0, [r4, #28]
    b .Lde_0803411E
.Lde_080340E4:
    adds	r0, r6, #0
    cmp	r6, #0
    bge .Lde_080340EC
    negs	r0, r6
.Lde_080340EC:
    adds	r6, r0, #0
    cmp	r5, #1
    beq .Lde_0803410C
    cmp	r5, #1
    bgt .Lde_080340FC
    cmp	r5, #0
    beq .Lde_08034106
    b .Lde_0803411E
.Lde_080340FC:
    cmp	r5, #2
    beq .Lde_08034114
    cmp	r5, #3
    beq .Lde_0803411A
    b .Lde_0803411E
.Lde_08034106:
    str	r6, [r4, #28]
    str	r1, [r4, #24]
    b .Lde_0803411E
.Lde_0803410C:
    negs	r0, r6
    str	r0, [r4, #28]
    str	r1, [r4, #24]
    b .Lde_0803411E
.Lde_08034114:
    negs	r0, r6
    str	r0, [r4, #24]
    b .Lde_0803411C
.Lde_0803411A:
    str	r6, [r4, #24]
.Lde_0803411C:
    str	r1, [r4, #28]
.Lde_0803411E:
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    adds	r5, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r7, r0
    beq .Lde_08034152
    movs	r1, #1
    negs	r1, r1
    cmp	r7, #2
    beq .Lde_08034138
    cmp	r7, #3
    beq .Lde_0803413C
    b .Lde_0803413E
.Lde_08034138:
    movs	r1, #8
    b .Lde_08034142
.Lde_0803413C:
    movs	r1, #5
.Lde_0803413E:
    cmp	r1, #0
    blt .Lde_0803414C
.Lde_08034142:
    adds	r0, r4, #0
    movs	r2, #1
    bl func_08032384
    b .Lde_08034152
.Lde_0803414C:
    adds	r0, r4, #0
    bl func_080323C8
.Lde_08034152:
    strb	r7, [r5, #0]
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_animation_lookup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034260
    .thumb_func
func_08034260:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #28
    adds	r6, r0, #0
    adds	r7, r6, #0
    adds	r7, #65	@ 0x41
    ldrb	r0, [r7, #0]
    cmp	r0, #0
    beq .Lde_08034188
    movs	r0, #0
    b .Lde_080341DE
.Lde_08034188:
    ldr	r5, [r6, #0]
    add	r4, sp, #16
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #52]	@ 0x34
    bl GetCurrentTask__C13HarvestSprite
    ldr	r1, [r6, #60]	@ 0x3c
    str	r0, [sp, #0]
    ldr	r0, [r6, #56]	@ 0x38
    str	r0, [sp, #4]
    add	r0, sp, #8
    adds	r2, r5, #0
    adds	r3, r4, #0
    bl func_080330F4
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lde_080341BE
    movs	r0, #1
    strb	r0, [r7, #0]
    movs	r0, #0
    b .Lde_080341DE
.Lde_080341BE:
    ldr	r0, [r6, #56]	@ 0x38
    adds	r1, r6, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    add	r2, sp, #8
    bl func_0809E988
    ldr r1, .Lde_080341E8
    ldr	r0, [sp, #24]
    ands	r0, r1
    str	r0, [sp, #24]
    ldr	r0, [r6, #52]	@ 0x34
    add	r1, sp, #24
    bl method_0809E7E4__13HarvestSpritePC15UnkBarnAnimal2C
    movs	r0, #1
.Lde_080341DE:
    add	sp, #28
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_080341E8:
    .4byte 0xFFFF0000
    .global func_080342D8
    .thumb_func
func_080342D8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    bl GetFriendship__C3Npc
    bl func_080338F0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803420E
    adds	r0, r5, #0
    bl func_08034260
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803426A
.Lde_0803420E:
    movs	r0, #180	@ 0xb4
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lde_08034274
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lde_08034278
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r4, [r5, #52]	@ 0x34
    adds	r0, r4, #0
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    adds	r1, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    subs	r0, r0, r1
    bl func_080AB788
    lsrs	r0, r0, #6
    adds	r0, #2
    lsls	r0, r0, #24
    ldr r2, .Lde_0803427C
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r1, sp
    bl method_0809E7D8__13HarvestSpritePC15UnkBarnAnimal2C
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r5, #0
    movs	r1, #0
    movs	r3, #0
    bl func_08034180
.Lde_0803426A:
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lde_08034274:
    .4byte 0xFFFF0000
.Lde_08034278:
    .4byte 0xFF00FFFF
.Lde_0803427C:
    .4byte 0x00FFFFFF
    .global func_0803436C
    .thumb_func
func_0803436C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    str	r0, [sp, #36]	@ 0x24
    ldr	r0, [r0, #0]
    str	r0, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    adds	r3, #48	@ 0x30
    ldrb	r1, [r3, #0]
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #56]	@ 0x38
    lsls	r1, r1, #3
    mov	r2, sp
    adds	r1, r0, r1
    ldmia	r1!, {r4, r5}
    stmia	r2!, {r4, r5}
    ldrb	r1, [r3, #0]
    bl func_0809E994
    ldr	r0, [sp, #36]	@ 0x24
    ldr	r1, [r0, #60]	@ 0x3c
    mov	r0, sp
    ldr	r2, [sp, #40]	@ 0x28
    bl func_08033584
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_080342C0
    b .Lde_0803480E
.Lde_080342C0:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r5, [r1, #16]
    cmp	r5, #0
    beq .Lde_0803432E
    ldr	r2, [r1, #60]	@ 0x3c
    add	r4, sp, #24
    adds	r0, r4, #0
    mov	r1, sp
    ldr	r3, [sp, #40]	@ 0x28
    bl func_08033830
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    beq .Lde_080342F8
    cmp	r0, #4
    bgt .Lde_080342EC
    cmp	r0, #3
    beq .Lde_080342F2
    b .Lde_08034318
.Lde_080342EC:
    cmp	r0, #5
    beq .Lde_08034312
    b .Lde_08034318
.Lde_080342F2:
    ldrh	r0, [r4, #2]
    subs	r0, #24
    b .Lde_08034316
.Lde_080342F8:
    movs	r0, #2
    ldrsh	r2, [r4, r0]
    mov	r0, sp
    ldrb	r0, [r0, #1]
    movs	r1, #7
    ands	r0, r1
    adds	r1, r2, #0
    adds	r1, #24
    cmp	r0, #3
    bhi .Lde_0803430E
    subs	r1, #56	@ 0x38
.Lde_0803430E:
    strh	r1, [r4, #2]
    b .Lde_08034318
.Lde_08034312:
    ldrh	r0, [r4, #2]
    subs	r0, #40	@ 0x28
.Lde_08034316:
    strh	r0, [r4, #2]
.Lde_08034318:
    ldr	r0, [sp, #36]	@ 0x24
    adds	r0, #48	@ 0x30
    ldrb	r1, [r0, #0]
    movs	r0, #0
    ldrsh	r2, [r4, r0]
    add	r0, sp, #24
    movs	r4, #2
    ldrsh	r3, [r0, r4]
    adds	r0, r5, #0
    bl func_08034BFC
.Lde_0803432E:
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bls .Lde_0803433C
    b .Lde_0803480E
.Lde_0803433C:
    lsls	r0, r0, #2
    ldr r1, .Lde_08034348
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lde_08034348:
    .4byte .Lde_0803434C
.Lde_0803434C:
    .4byte .Lde_0803480E
    .4byte .Lde_08034370
    .4byte .Lde_080343F8
    .4byte .Lde_080344FE
    .4byte .Lde_0803452A
    .4byte .Lde_08034558
    .4byte .Lde_08034594
    .4byte .Lde_08034700
    .4byte .Lde_08034748
.Lde_08034370:
    .4byte 0x682D9D0A
    .4byte 0x20D846A9
    .4byte 0x99094481
    .4byte 0x5E8E220A
    .4byte 0x5F4C250E
    .4byte 0xAC0246A0
    .4byte 0x88212202
    .4byte 0x1C184B19
    .4byte 0x43104008
    .4byte 0x04368020
    .4byte 0x203F0C31
    .4byte 0x40014682
    .4byte 0x78650089
    .4byte 0x1C102203
    .4byte 0x43084028
    .4byte 0x0DB67060
    .4byte 0x1C188861
    .4byte 0x43304008
    .4byte 0x46418060
    .4byte 0x46880409
    .4byte 0x46550C08
    .4byte 0x00804028
    .4byte 0x400A78E1
    .4byte 0x70E24302
    .4byte 0x0D804640
    .4byte 0x88A04680
    .4byte 0x46414003
    .4byte 0x80A3430B
    .4byte 0x682A464D
    .4byte 0x1C21980A
    .4byte 0xFA46F09F
    .4byte 0x46A02601
    .4byte 0x0000E20F
    .4byte 0xFFFFFC00
.Lde_080343F8:
    .4byte 0x4681A802
    .4byte 0xFE06F7DA
    .4byte 0x6809990A
    .4byte 0x22E04688
    .4byte 0x9C094490
    .4byte 0x5E25200A
    .4byte 0x5E66210E
    .4byte 0x2202AF04
    .4byte 0x4B1E8839
    .4byte 0x40081C18
    .4byte 0x80384310
    .4byte 0x0C29042D
    .4byte 0x4692223F
    .4byte 0x00894011
    .4byte 0x2203787C
    .4byte 0x40201C10
    .4byte 0x70784308
    .4byte 0x88790DAD
    .4byte 0x40081C18
    .4byte 0x80784328
    .4byte 0x0C300436
    .4byte 0x40204654
    .4byte 0x78F90080
    .4byte 0x4302400A
    .4byte 0x0DB670FA
    .4byte 0x400388B8
    .4byte 0x80BB4333
    .4byte 0x682B4645
    .4byte 0x1C39980A
    .4byte 0xF09F464A
    .4byte 0x4648FA05
    .4byte 0xFE0AF7DA
    .4byte 0x46C80600
    .4byte 0xD0002800
    .4byte 0x4640E1C5
    .4byte 0xFE1AF7DA
    .4byte 0xD0052800
    .4byte 0xD0212801
    .4byte 0x0000E1BD
    .4byte 0xFFFFFC00
    .4byte 0x6804980A
    .4byte 0x004921AE
    .4byte 0xAD071864
    .4byte 0x46411C38
    .4byte 0xFE0CF7DA
    .4byte 0x46687839
    .4byte 0x78003011
    .4byte 0x43080200
    .4byte 0x31124669
    .4byte 0x04097809
    .4byte 0x1C284301
    .4byte 0xFE2AF7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0xE012F9D3
    .4byte 0x68149A0A
    .4byte 0x006D25AE
    .4byte 0x466D1964
    .4byte 0x4640351D
    .4byte 0xFE10F7DA
    .4byte 0x1C281C01
    .4byte 0xFE3CF7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0x2600F9BF
    .hword 0xE189
.Lde_080344FE:
    .hword 0x9909
    .4byte 0x24FF6BC8
    .4byte 0x190000A4
    .4byte 0xF7D82101
    .4byte 0x9A09F975
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xF98CF7D8
    .4byte 0x68209C0A
    .4byte 0x466930A0
    .4byte 0x68027849
    .hword 0xE02B
.Lde_0803452A:
    .hword 0x9909
    .4byte 0x4C096BC8
    .4byte 0x21011900
    .4byte 0xFEB4F7D8
    .4byte 0x6BD09A09
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9C0AFECB
    .4byte 0x309C6820
    .4byte 0x78494669
    .4byte 0xE0166802
    .4byte 0x000005DC
.Lde_08034558:
    .4byte 0x6BC89909
    .4byte 0x19004C0C
    .4byte 0xF7D82101
    .4byte 0x9A09FE9D
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xFEF0F7D8
    .4byte 0x68229C0A
    .4byte 0x4668329C
    .4byte 0x31107841
    .4byte 0x1C206812
    .4byte 0xF978F09F
    .4byte 0xAD022602
    .4byte 0xE14046A8
    .4byte 0x000005DC
.Lde_08034594:
    .4byte 0x78414668
    .4byte 0x9A0A3136
    .4byte 0x6C026810
    .4byte 0xF09F980A
    .4byte 0x1C07F969
    .4byte 0xD1002F00
    .4byte 0x6978E12F
    .4byte 0x1C386D01
    .4byte 0xF95EF09F
    .4byte 0x28000600
    .4byte 0x6978D004
    .4byte 0x1C386F01
    .4byte 0xF956F09F
    .4byte 0x6D416978
    .4byte 0xF09F1C38
    .4byte 0x0600F951
    .4byte 0x46A0AC02
    .4byte 0xD0452800
    .4byte 0x6F416978
    .4byte 0xF09F1C38
    .4byte 0x211CF947
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Lde_080345FC
.Lde_080345FC:
    .4byte .Lde_08034614
    .4byte .Lde_08034618
    .4byte .Lde_0803461C
    .4byte .Lde_08034620
    .4byte .Lde_08034624
    .4byte .Lde_08034628
.Lde_08034614:
    .4byte 0xE008211C
.Lde_08034618:
    .4byte 0xE006211D
.Lde_0803461C:
    .4byte 0xE004211E
.Lde_08034620:
    .4byte 0xE002211F
.Lde_08034624:
    .4byte 0xE0002120
.Lde_08034628:
    .4byte 0x9D0A2121
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x361E466E
    .4byte 0x1C28AD02
    .4byte 0xFB44F7D9
    .4byte 0x46687829
    .4byte 0x78003009
    .4byte 0x43080200
    .4byte 0x310A4669
    .4byte 0x04097809
    .4byte 0x1C304301
    .4byte 0xFD60F7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C31
    .4byte 0x46A8F909
    .4byte 0x6D816978
    .4byte 0xF09F1C38
    .4byte 0x0600F901
    .4byte 0xD03A2800
    .4byte 0x6F816978
    .4byte 0xF09F1C38
    .4byte 0x2105F8F9
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Lde_08034698
.Lde_08034698:
    .4byte .Lde_080346B0
    .4byte .Lde_080346B4
    .4byte .Lde_080346B8
    .4byte .Lde_080346BC
    .4byte .Lde_080346C0
    .4byte .Lde_080346C4
.Lde_080346B0:
    .4byte 0xE0082105
.Lde_080346B4:
    .4byte 0xE0062106
.Lde_080346B8:
    .4byte 0xE0042107
.Lde_080346BC:
    .4byte 0xE0022108
.Lde_080346C0:
    .4byte 0xE0002109
.Lde_080346C4:
    .4byte 0x9A0A210A
    .4byte 0x24AE6815
    .4byte 0x192D0064
    .4byte 0x361F466E
    .4byte 0x1C20AC08
    .4byte 0xFC4AF7D9
    .4byte 0x1C307821
    .4byte 0xFD42F7D9
    .4byte 0x980A682A
    .4byte 0xF09F1C31
    .4byte 0x6978F8C5
    .4byte 0x68023088
    .4byte 0x213C1C38
    .4byte 0xF8BEF09F
    .4byte 0xE0882602
.Lde_08034700:
    .4byte 0x78414668
    .4byte 0x9D0A312E
    .4byte 0x6C026828
    .4byte 0xF09F1C28
    .4byte 0x1C04F8B3
    .4byte 0xD07A2C00
    .4byte 0x6D016960
    .4byte 0xF09F1C20
    .4byte 0x0600F8A9
    .4byte 0xD0042800
    .4byte 0x6F016960
    .4byte 0xF09F1C20
    .4byte 0x6960F8A1
    .4byte 0x68023088
    .4byte 0x213C1C20
    .4byte 0xF89CF09F
    .4byte 0xA8022602
    .4byte 0xE0644680
.Lde_08034748:
    .4byte 0x78414668
    .4byte 0x344C1C0C
    .4byte 0x6BD09A09
    .4byte 0x00AD25FF
    .4byte 0xF7D71940
    .4byte 0x2800FFB1
    .4byte 0x7980D055
    .4byte 0x0F400740
    .4byte 0x2805270F
    .4byte 0x0080D81D
    .4byte 0x18404901
    .4byte 0x46876800
    .4byte .Lde_0803477C
.Lde_0803477C:
    .4byte .Lde_08034794
    .4byte .Lde_08034798
    .4byte .Lde_0803479C
    .4byte .Lde_080347A0
    .4byte .Lde_080347A4
    .4byte .Lde_080347A8
.Lde_08034794:
    .4byte 0xE008270F
.Lde_08034798:
    .4byte 0xE0062710
.Lde_0803479C:
    .4byte 0xE0042711
.Lde_080347A0:
    .4byte 0xE0022712
.Lde_080347A4:
    .4byte 0xE0002713
.Lde_080347A8:
    .4byte 0x99092714
    .4byte 0x68016808
    .4byte 0x1C216BCA
    .4byte 0xF860F09F
    .4byte 0x6BD09A09
    .4byte 0x00A424FF
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9D0AF907
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x3621466E
    .4byte 0x1C28AD02
    .4byte 0xF7D91C39
    .4byte 0x7829FA73
    .4byte 0x30094668
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x7809310A
    .4byte 0x43010409
    .4byte 0xF7D91C30
    .4byte 0x6822FC8F
    .4byte 0x1C31980A
    .4byte 0xF838F09F
    .4byte 0x46A82602
    .hword 0xE001
.Lde_0803480E:
    movs	r0, #0
    b .Lde_0803483E
    .hword 0x490F
    .4byte 0x22034640
    .4byte 0xF86EF09F
    .4byte 0xD00D2E03
    .4byte 0xF07620C8
    .4byte 0x4642FF61
    .4byte 0x78091991
    .4byte 0xD2054288
    .4byte 0x6B609C09
    .4byte 0x22011C31
    .4byte 0xFEE0F069
    .hword 0x2001
.Lde_0803483E:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .hword 0x0000
    .4byte gUnk_080F1496
    .global func_08034940
    .thumb_func
func_08034940:
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r2, [r0, #10]
    lsls	r0, r2, #27
    lsrs	r0, r0, #27
    cmp	r0, #5
    bls .Lde_08034890
    subs	r0, #6
    lsls	r1, r0, #4
    subs	r1, r1, r0
    lsls	r1, r1, #2
    lsls	r0, r2, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    adds	r0, r5, #0
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    ldr r2, .Lde_080348BC
    adds	r0, r0, r2
    cmp	r1, r0
    bcc .Lde_0803491C
.Lde_08034890:
    ldrh	r0, [r5, #4]
    cmp	r0, #17
    beq .Lde_080348C0
    cmp	r0, #17
    ble .Lde_080348D8
    cmp	r0, #37	@ 0x25
    bne .Lde_080348D8
    mov	r4, sp
    mov	r0, sp
    bl smethod_08009ADC__4Farm
    mov	r0, sp
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    b .Lde_080348D8
    .align 2, 0
.Lde_080348BC:
    .4byte 0x00000385
.Lde_080348C0:
    add	r4, sp, #4
    adds	r0, r4, #0
    bl smethod_08009AE8__4Farm
    movs	r1, #0
    ldrsh	r2, [r4, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
.Lde_080348D8:
    ldr	r0, [r5, #56]	@ 0x38
    adds	r1, r5, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    bl func_0809E994
    ldr	r0, [r5, #52]	@ 0x34
    add	r1, sp, #8
    bl method_0809E7FC__13HarvestSprite
    movs	r2, #10
    ldrsh	r1, [r5, r2]
    movs	r0, #180	@ 0xb4
    lsls	r0, r0, #1
    cmp	r1, r0
    bne .Lde_080348FC
    movs	r2, #1
    b .Lde_08034906
.Lde_080348FC:
    ldr r0, .Lde_08034918
    movs	r2, #2
    cmp	r1, r0
    bgt .Lde_08034906
    movs	r2, #3
.Lde_08034906:
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r5, #0
    movs	r1, #1
    bl func_08034180
    movs	r0, #1
    b .Lde_0803491E
    .align 2, 0
.Lde_08034918:
    .4byte 0x00000167
.Lde_0803491C:
    movs	r0, #0
.Lde_0803491E:
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08034A14
    .thumb_func
func_08034A14:
    push	{r4, r5, r6, lr}
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6}
    sub	sp, #16
    mov	r8, r0
    adds	r4, r1, #0
    ldr r0, .Lde_080349A8
    mov	r9, r0
    adds	r5, r4, #0
    adds	r5, #48	@ 0x30
    ldrb	r0, [r5, #0]
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r3, [r0, #0]
    movs	r6, #0
    str	r6, [sp, #0]
    movs	r0, #4
    str	r0, [sp, #4]
    str	r6, [sp, #8]
    add	r0, sp, #12
    strb	r6, [r0, #0]
    mov	r0, r8
    movs	r2, #3
    bl func_080324BC
    ldr r0, .Lde_080349AC
    mov	r1, r8
    str	r0, [r1, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldr r2, .Lde_080349B0
    ldrb	r5, [r5, #0]
    lsls	r0, r5, #1
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    ldr	r3, [r4, #0]
    lsls	r5, r5, #2
    add	r5, r9
    mov	r0, r8
    adds	r0, #140	@ 0x8c
    movs	r4, #2
    str	r4, [sp, #0]
    ldr	r4, [r5, #0]
    str	r4, [sp, #4]
    add	r4, sp, #8
    strb	r6, [r4, #0]
    bl func_080A4A00
    mov	r0, r8
    adds	r0, #208	@ 0xd0
    strh	r6, [r0, #0]
    mov	r0, r8
    add	sp, #16
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lde_080349A8:
    .4byte gUnk_080F14B8
.Lde_080349AC:
    .4byte vtable_unk_080E6904
.Lde_080349B0:
    .4byte gUnk_080F14F0
    .global func_08034AA0
    .thumb_func
func_08034AA0:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0803260C
    adds	r0, r4, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_080349F4
    adds	r1, r4, #0
    adds	r1, #203	@ 0xcb
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lde_080349E6
    adds	r0, r4, #0
    adds	r0, #180	@ 0xb4
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lde_080349EA
    adds	r1, r4, #0
    adds	r1, #200	@ 0xc8
    movs	r0, #1
    b .Lde_080349E8
.Lde_080349E6:
    movs	r0, #0
.Lde_080349E8:
    strb	r0, [r1, #0]
.Lde_080349EA:
    adds	r1, r4, #0
    adds	r1, #208	@ 0xd0
    ldrh	r0, [r1, #0]
    subs	r0, #1
    strh	r0, [r1, #0]
.Lde_080349F4:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034AE8
    .thumb_func
func_08034AE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #60	@ 0x3c
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08032690
    adds	r0, r5, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08034AFE
    add	r3, sp, #52	@ 0x34
    ldr	r0, [r4, #0]
    ldr	r1, [r4, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r3, #4]
    adds	r0, r5, #0
    adds	r0, #204	@ 0xcc
    movs	r2, #0
    ldrsh	r1, [r0, r2]
    adds	r0, #2
    movs	r6, #0
    ldrsh	r2, [r0, r6]
    movs	r6, #12
    ldrsh	r0, [r4, r6]
    subs	r1, r1, r0
    mov	r9, r1
    movs	r1, #14
    ldrsh	r0, [r4, r1]
    subs	r0, r2, r0
    mov	r8, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r4, r0, r2
    adds	r6, r5, #0
    adds	r6, #140	@ 0x8c
    mov	sl, r3
    adds	r0, r5, #0
    adds	r0, #180	@ 0xb4
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    adds	r0, #4
    lsls	r2, r2, #2
    ldr	r0, [r0, #0]
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, sl
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    adds	r0, r5, #0
    adds	r0, #144	@ 0x90
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_08034AA8
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #156	@ 0x9c
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #85	@ 0x55
    ldr r4, .Lde_08034AA4
    bl _call_via_r4
    b .Lde_08034AAA
    .align 2, 0
.Lde_08034AA4:
    .4byte func_030004DC
.Lde_08034AA8:
    movs	r0, #0
.Lde_08034AAA:
    cmp	r0, #0
    beq .Lde_08034AFE
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lde_08034AFE
    mov	r0, sl
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lde_08034AE0
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lde_08034AFA
.Lde_08034AE0:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lde_08034AFA
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lde_08034AFA:
    movs	r0, #0
    strb	r0, [r5, #0]
.Lde_08034AFE:
    add	sp, #60	@ 0x3c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_resource_setup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034C64
    .thumb_func
func_08034C64:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r1, #0
    ldr r4, .Lde_08034BF0
    ldr	r1, [r4, #0]
    bl _call_via_r1
    ldr	r1, [r4, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r5, [r0, #0]
    cmp	r5, #0
    beq .Lde_08034BF4
    ldrh	r1, [r6, #0]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lde_08034BA0
    adds	r2, #24
.Lde_08034BA0:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r0, r0, r1
    str	r0, [sp, #4]
    ldr	r4, [r5, #4]
    ldrh	r1, [r5, #0]
    lsls	r1, r1, #3
    adds	r1, r4, r1
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080D7ECC
    subs	r0, r0, r4
    asrs	r0, r0, #3
    subs	r0, #1
    ldrh	r1, [r5, #0]
    cmp	r0, r1
    bcs .Lde_08034BF4
    ldr	r1, [r5, #4]
    lsls	r0, r0, #3
    adds	r0, r0, r1
    ldr	r0, [r0, #4]
    cmp	r0, #0
    beq .Lde_08034BF4
    ldrh	r1, [r0, #10]
    lsls	r1, r1, #22
    lsrs	r1, r1, #22
    movs	r0, #29
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    b .Lde_08034BF6
    .align 2, 0
.Lde_08034BF0:
    .4byte gUnk_080F29C0
.Lde_08034BF4:
    movs	r0, #0
.Lde_08034BF6:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .else
    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803242C
    .thumb_func
func_0803242C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r3, r0, #0
    mov	r8, r1
    ldrh	r0, [r3, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_08032440
    subs	r0, #1
    b .Lus_08032442
.Lus_08032440:
    ldrh	r0, [r3, #38]	@ 0x26
.Lus_08032442:
    strh	r0, [r3, #36]	@ 0x24
    ldr	r4, [r3, #40]	@ 0x28
    cmp	r4, #0
    beq .Lus_080324A6
    movs	r2, #0
    adds	r0, r3, #0
    adds	r0, #46	@ 0x2e
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    bne .Lus_08032458
    movs	r2, #1
.Lus_08032458:
    mov	ip, r2
    cmp	r2, #0
    beq .Lus_08032462
    ldr	r2, [r3, #8]
    b .Lus_08032464
.Lus_08032462:
    ldr	r2, [r3, #12]
.Lus_08032464:
    asrs	r5, r2, #16
    movs	r0, #44	@ 0x2c
    ldrsh	r6, [r3, r0]
    subs	r0, r6, r5
    adds	r7, r0, #0
    cmp	r0, #0
    bne .Lus_08032476
    str	r0, [r3, #40]	@ 0x28
    b .Lus_080324A6
.Lus_08032476:
    adds	r1, r2, r4
    cmp	r0, #0
    bgt .Lus_0803247E
    subs	r1, r2, r4
.Lus_0803247E:
    adds	r2, r1, #0
    asrs	r0, r2, #16
    cmp	r0, r5
    beq .Lus_0803249A
    subs	r0, r6, r0
    cmp	r7, #0
    ble .Lus_08032492
    cmp	r0, #0
    ble .Lus_08032496
    b .Lus_0803249A
.Lus_08032492:
    cmp	r0, #0
    blt .Lus_0803249A
.Lus_08032496:
    movs	r0, #0
    str	r0, [r3, #40]	@ 0x28
.Lus_0803249A:
    mov	r0, ip
    cmp	r0, #0
    beq .Lus_080324A4
    str	r2, [r3, #8]
    b .Lus_080324A6
.Lus_080324A4:
    str	r2, [r3, #12]
.Lus_080324A6:
    adds	r0, r3, #0
    mov	r1, r8
    bl vfunc_2C__7AEntityUi
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_default_no_action_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_080324BC
    .thumb_func
func_080324BC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r4, r1, #0
    adds	r5, r2, #0
    mov	r9, r3
    add	r0, sp, #52	@ 0x34
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r4, [r7, #0]
    ldr r0, .Lus_0803255C
    str	r0, [r7, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r4, #34]	@ 0x22
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r5, [sp, #0]
    mov	r5, r9
    str	r5, [sp, #4]
    add	r5, sp, #8
    mov	r6, r8
    strb	r6, [r5, #0]
    bl func_080A4A00
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r4, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    movs	r2, #0
    strb	r2, [r5, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #40	@ 0x28
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r6, r3, #2
    strb	r6, [r0, #0]
    adds	r0, #1
    add	r5, sp, #48	@ 0x30
    ldrb	r5, [r5, #0]
    strb	r5, [r0, #0]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803255C:
    .4byte vtable_unk_080E68B4
    .global func_08032560
    .thumb_func
func_08032560:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r4, r2, #0
    mov	r9, r3
    ldr	r6, [sp, #48]	@ 0x30
    add	r0, sp, #64	@ 0x40
    ldrb	r0, [r0, #0]
    mov	r8, r0
    str	r5, [r7, #0]
    ldr r0, .Lus_08032608
    str	r0, [r7, #4]
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldrh	r2, [r5, #34]	@ 0x22
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    adds	r2, r2, r0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #8
    str	r4, [sp, #0]
    mov	r4, r9
    str	r4, [sp, #4]
    str	r6, [sp, #8]
    add	r4, sp, #12
    mov	r6, r8
    strb	r6, [r4, #0]
    bl func_080A49A0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #108]	@ 0x6c
    bl _call_via_r1
    adds	r1, r0, #0
    ldr	r3, [r5, #0]
    adds	r0, r7, #0
    adds	r0, #72	@ 0x48
    movs	r2, #2
    str	r2, [sp, #0]
    movs	r2, #14
    str	r2, [sp, #4]
    add	r4, sp, #8
    movs	r2, #0
    strb	r2, [r4, #0]
    movs	r2, #0
    bl func_080A4A00
    adds	r0, r7, #0
    adds	r0, #136	@ 0x88
    movs	r1, #0
    add	r2, sp, #52	@ 0x34
    ldrb	r2, [r2, #0]
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r0, #1
    ldr	r3, [sp, #56]	@ 0x38
    lsls	r3, r3, #2
    str	r3, [sp, #16]
    strb	r3, [r0, #0]
    adds	r0, #1
    add	r6, sp, #60	@ 0x3c
    ldrb	r6, [r6, #0]
    strb	r6, [r0, #0]
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_08032608:
    .4byte vtable_unk_080E68B4
    .global func_0803260C
    .thumb_func
func_0803260C:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r1, r4, #0
    adds	r1, #71	@ 0x47
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_08032630
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_08032634
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Lus_08032632
.Lus_08032630:
    movs	r0, #0
.Lus_08032632:
    strb	r0, [r1, #0]
.Lus_08032634:
    adds	r1, r4, #0
    adds	r1, #138	@ 0x8a
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r5, r0, #30
    adds	r6, r1, #0
    cmp	r5, #0
    beq .Lus_0803268A
    movs	r7, #0
    subs	r1, #3
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_0803266A
    adds	r0, r4, #0
    adds	r0, #112	@ 0x70
    bl func_0805E8F0
    adds	r2, r0, #0
    lsls	r0, r2, #30
    cmp	r0, #0
    bge .Lus_08032666
    adds	r1, r4, #0
    adds	r1, #132	@ 0x84
    movs	r0, #1
    strb	r0, [r1, #0]
.Lus_08032666:
    adds	r0, r2, #0
    b .Lus_08032670
.Lus_0803266A:
    movs	r0, #0
    strb	r0, [r1, #0]
    movs	r0, #2
.Lus_08032670:
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lus_0803267C
    cmp	r5, #2
    beq .Lus_0803267C
    movs	r7, #1
.Lus_0803267C:
    cmp	r7, #0
    beq .Lus_0803268A
    ldrb	r1, [r6, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #0]
.Lus_0803268A:
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .global func_08032690
    .thumb_func
func_08032690:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #80	@ 0x50
    adds	r6, r0, #0
    mov	sl, r1
    ldr	r0, [r6, #0]
    mov	r8, r0
    ldr	r1, [r0, #0]
    str	r1, [sp, #60]	@ 0x3c
    movs	r2, #10
    ldrsh	r1, [r0, r2]
    mov	r3, sl
    movs	r4, #12
    ldrsh	r0, [r3, r4]
    subs	r1, r1, r0
    str	r1, [sp, #64]	@ 0x40
    mov	r0, r8
    movs	r2, #14
    ldrsh	r1, [r0, r2]
    movs	r4, #14
    ldrsh	r0, [r3, r4]
    subs	r0, r1, r0
    str	r0, [sp, #68]	@ 0x44
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r0, r0, r1
    str	r0, [sp, #72]	@ 0x48
    add	r2, sp, #52	@ 0x34
    ldr	r0, [r3, #0]
    ldr	r1, [r3, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r2, #4]
    adds	r0, r6, #0
    adds	r0, #138	@ 0x8a
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #0
    beq .Lus_080327C2
    cmp	r0, #0
    blt .Lus_080327C2
    cmp	r0, #2
    bgt .Lus_080327C2
    mov	r0, r8
    adds	r0, #32
    ldrb	r0, [r0, #0]
    lsrs	r1, r1, #2
    lsls	r1, r1, #4
    lsls	r0, r0, #2
    ldr r2, .Lus_08032764
    adds	r0, r0, r2
    adds	r1, r1, r0
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    movs	r3, #2
    ldrsh	r1, [r1, r3]
    adds	r5, r6, #0
    adds	r5, #72	@ 0x48
    ldr	r4, [sp, #64]	@ 0x40
    adds	r0, r4, r0
    str	r0, [sp, #76]	@ 0x4c
    ldr	r0, [sp, #68]	@ 0x44
    adds	r0, r0, r1
    mov	r9, r0
    adds	r0, r6, #0
    adds	r0, #112	@ 0x70
    ldr	r1, [r6, #112]	@ 0x70
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #116]	@ 0x74
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    ldr	r3, [sp, #56]	@ 0x38
    ldr	r2, [r6, #72]	@ 0x48
    ldr	r1, [r6, #80]	@ 0x50
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_0803276C
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #88	@ 0x58
    ldr	r4, [sp, #72]	@ 0x48
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    ldr	r1, [sp, #76]	@ 0x4c
    mov	r2, r9
    movs	r3, #85	@ 0x55
    ldr r4, .Lus_08032768
    bl _call_via_r4
    b .Lus_0803276E
.Lus_08032764:
    .4byte gUnk_080F1328
.Lus_08032768:
    .4byte func_030004DC
.Lus_0803276C:
    movs	r0, #0
.Lus_0803276E:
    cmp	r0, #0
    beq .Lus_080327C2
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lus_080327C2
    ldr	r1, [sp, #52]	@ 0x34
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_080327A2
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_080327BC
.Lus_080327A2:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_080327BC
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_080327BC:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lus_080327C2:
    adds	r0, r6, #0
    adds	r0, #139	@ 0x8b
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lus_080327EC
    cmp	r0, #1
    ble .Lus_080327D4
    cmp	r0, #2
    beq .Lus_080327F0
.Lus_080327D4:
    mov	r0, r8
    adds	r0, #33	@ 0x21
    ldrb	r0, [r0, #0]
    movs	r1, #3
    ands	r0, r1
    lsls	r4, r0, #2
    orrs	r4, r0
    lsls	r1, r0, #4
    orrs	r4, r1
    lsls	r0, r0, #6
    orrs	r4, r0
    b .Lus_080327F2
.Lus_080327EC:
    movs	r4, #25
    b .Lus_080327F2
.Lus_080327F0:
    movs	r4, #26
.Lus_080327F2:
    adds	r5, r6, #0
    adds	r5, #8
    add	r2, sp, #52	@ 0x34
    mov	r8, r2
    ldr	r1, [r6, #48]	@ 0x30
    ldr	r3, [r1, #0]
    ldrh	r2, [r6, #60]	@ 0x3c
    lsls	r2, r2, #2
    ldr	r0, [r6, #52]	@ 0x34
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r3, r8
    ldr	r3, [r3, #4]
    mov	r9, r3
    ldr	r2, [r6, #8]
    ldr	r1, [r6, #16]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_0803284C
    ldrh	r0, [r5, #12]
    adds	r1, r6, #0
    adds	r1, #24
    ldr	r3, [sp, #72]	@ 0x48
    str	r3, [sp, #0]
    adds	r3, r7, #0
    str	r3, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    mov	r0, r9
    ldr	r1, [sp, #64]	@ 0x40
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r4, #0
    ldr r4, .Lus_08032848
    bl _call_via_r4
    b .Lus_0803284E
.Lus_08032848:
    .4byte func_030004DC
.Lus_0803284C:
    movs	r0, #0
.Lus_0803284E:
    cmp	r0, #0
    beq .Lus_080328A4
    adds	r0, r5, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    mov	r9, r0
    cmp	r1, #0
    beq .Lus_080328A4
    mov	r4, r8
    ldr	r1, [r4, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r5, #0
    bl func_080A480C
    adds	r0, r5, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08032884
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_0803289E
.Lus_08032884:
    adds	r4, r5, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_0803289E
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r5, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_0803289E:
    movs	r0, #0
    mov	r1, r9
    strb	r0, [r1, #0]
.Lus_080328A4:
    adds	r0, r6, #0
    adds	r0, #136	@ 0x88
    ldrb	r0, [r0, #0]
    cmp	r0, #1
    beq .Lus_080328C6
    cmp	r0, #1
    bgt .Lus_080328B8
    cmp	r0, #0
    beq .Lus_080328C2
    b .Lus_080328C6
.Lus_080328B8:
    cmp	r0, #2
    beq .Lus_080328CA
    cmp	r0, #3
    bne .Lus_080328C6
    b .Lus_080328F0
.Lus_080328C2:
    movs	r4, #0
    b .Lus_080328CC
.Lus_080328C6:
    movs	r4, #1
    b .Lus_080328CC
.Lus_080328CA:
    movs	r4, #2
.Lus_080328CC:
    ldr	r2, [sp, #60]	@ 0x3c
    ldr	r0, [r2, #0]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r2, #0
    bl _call_via_r1
    mov	r3, sl
    ldr	r1, [r3, #8]
    adds	r2, r6, #0
    adds	r2, #137	@ 0x89
    movs	r3, #0
    ldrsb	r3, [r2, r3]
    ldr	r2, [sp, #68]	@ 0x44
    adds	r3, r2, r3
    str	r4, [sp, #0]
    ldr	r2, [sp, #64]	@ 0x40
    bl func_0803AE58
.Lus_080328F0:
    add	sp, #80	@ 0x50
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_region_classification_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032934
    .thumb_func
func_08032934:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r4, r2, #0
    ldrh	r0, [r4, #8]
    str	r0, [sp, #0]
    adds	r0, r5, #0
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lus_08032958
    str	r0, [r5, #20]
    str	r4, [r5, #48]	@ 0x30
    adds	r0, r5, #0
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
.Lus_08032958:
    .4byte vtable_unk_080E6828
    .global func_0803295C
    .thumb_func
func_0803295C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lus_080329AC
    str	r0, [r5, #20]
    ldr	r4, [r5, #48]	@ 0x30
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    mov	r0, sp
    ldmia	r0!, {r1, r2}
    stmia	r4!, {r1, r2}
    ldrh	r1, [r5, #34]	@ 0x22
    ldr	r0, [r5, #48]	@ 0x30
    strh	r1, [r0, #8]
    ldr r0, .Lus_080329B0
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_08032994
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_08032994:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lus_080329A2
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_080329A2:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_080329AC:
    .4byte vtable_unk_080E6828
.Lus_080329B0:
    .4byte __vt_7AEntity
    .global func_080329B4
    .thumb_func
func_080329B4:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #140	@ 0x8c
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08032A00
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_080329CC
    .thumb_func
func_080329CC:
    ldr	r0, [r0, #48]	@ 0x30
    ldrh	r0, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329D4
    .thumb_func
func_080329D4:
    ldr	r0, [r0, #48]	@ 0x30
    strh	r1, [r0, #10]
    bx	lr
    .align 2, 0
    .global func_080329DC
    .thumb_func
func_080329DC:
    push	{r4, lr}
    movs	r3, #10
    ldrsh	r2, [r1, r3]
    movs	r4, #14
    ldrsh	r3, [r1, r4]
    subs	r1, r2, #7
    strh	r1, [r0, #0]
    adds	r1, r3, #0
    subs	r1, #10
    strh	r1, [r0, #2]
    adds	r2, #7
    strh	r2, [r0, #4]
    adds	r3, #4
    strh	r3, [r0, #6]
    pop	{r4}
    pop	{r2}
    bx	r2
    .align 2, 0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_constructor_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08032A30
    .thumb_func
func_08032A30:
    push	{lr}
    adds	r1, r0, #0
    ldrh	r0, [r1, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_08032A3E
    subs	r0, #1
    b .Lus_08032A40
.Lus_08032A3E:
    ldrh	r0, [r1, #38]	@ 0x26
.Lus_08032A40:
    strh	r0, [r1, #36]	@ 0x24
    ldr	r2, [r1, #16]
    cmp	r2, #0
    beq .Lus_08032A52
    ldr	r0, [r2, #4]
    ldr	r1, [r0, #12]
    adds	r0, r2, #0
    bl _call_via_r1
.Lus_08032A52:
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte 0x3030B500
    .4byte 0xFF1AF02B
    .4byte 0x4708BC02
    .4byte 0x1C01B500
    .4byte 0x22003130
    .4byte 0x280089C8
    .4byte 0x2010D004
    .4byte 0x42485E09
    .4byte 0x0FC24308
    .4byte 0xBC021C10
    .4byte 0x00004708
    .4byte 0x78003044
    .4byte 0x00004770
    .4byte 0x7001308B
    .4byte 0x00004770
    .4byte 0x70013089
    .4byte 0x00004770
    .4byte 0x70013088
    .4byte 0x00004770
    .4byte 0x7802308A
    .4byte 0x42492104
    .4byte 0x70014011
    .4byte 0x00004770
    .4byte 0x1C05B530
    .4byte 0x0E240614
    .4byte 0xF02B3070
    .4byte 0x1C28FECF
    .4byte 0x22003084
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0x2C002301
    .4byte 0x2302D000
    .4byte 0x328A1C2A
    .4byte 0x20047811
    .4byte 0x40084240
    .4byte 0x70104318
    .4byte 0xBC01BC30
    .4byte 0x00004700
    .4byte 0x0089308A
    .4byte 0x22037803
    .4byte 0x430A401A
    .4byte 0x47707002
    .4byte 0x1C04B510
    .4byte 0xF02B3030
    .4byte 0x1C20FEA9
    .4byte 0x22003044
    .4byte 0x70012101
    .4byte 0x70023002
    .4byte 0x70013001
    .4byte 0xBC01BC10
    .4byte 0x00004700
    .4byte 0x47708C80
    .4byte 0x2100B500
    .4byte 0x28008C80
    .4byte 0x2101D100
    .4byte 0xBC021C08
    .4byte 0x00004708
    .global func_08032B40
    .thumb_func
func_08032B40:
    bx	lr
    .hword 0x0000
    .4byte 0x1C02B500
    .4byte 0x42888C50
    .4byte 0x1C10D002
    .4byte 0xFB2EF7FF
    .4byte 0x4700BC01
    .4byte 0x47708C40
    .4byte 0x30208C41
    .4byte 0x18097800
    .4byte 0x47701C08
    .4byte 0x1C02B500
    .4byte 0x78003020
    .4byte 0xD0024288
    .4byte 0xF7FF1C10
    .4byte 0xBC01FB0F
    .4byte 0x00004700
    .4byte 0x78003020
    .4byte 0x00004770
    .4byte 0x5E81220E
    .4byte __ewram_bss_end + 0x170
    .4byte 0x47701A40
    .4byte 0x70013021
    .4byte 0x00004770
    .4byte 0x78003021
    .4byte 0x00004770
    .4byte 0x477061C1
    .4byte 0x477069C0
    .4byte 0x47706181
    .4byte 0x47706980
    .global func_08032BB4
    .thumb_func
func_08032BB4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #72	@ 0x48
    str	r0, [sp, #40]	@ 0x28
    str	r1, [sp, #44]	@ 0x2c
    mov	sl, r2
    str	r3, [sp, #48]	@ 0x30
    mov	r2, sp
    ldrb	r1, [r2, #0]
    movs	r4, #16
    negs	r4, r4
    adds	r0, r4, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    movs	r0, #0
    str	r0, [sp, #52]	@ 0x34
    ldr	r1, [sp, #48]	@ 0x30
    cmp	r1, #37	@ 0x25
    beq .Lus_08032BE2
    b .Lus_08032E1C
.Lus_08032BE2:
    ldr	r2, [sp, #44]	@ 0x2c
    ldr r3, .Lus_08032C30
    adds	r7, r2, r3
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Barn
    cmp	r0, #0
    bne .Lus_08032BF4
    b .Lus_08032E1C
.Lus_08032BF4:
    movs	r6, #0
    str	r6, [sp, #56]	@ 0x38
    adds	r0, r7, #0
    bl GetPregnancyStallCapacity__C4Barn
    mov	r9, r0
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r0, r9
    bcs .Lus_08032CA6
    add	r1, sp, #20
    mov	r8, r1
.Lus_08032C0A:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl GetPregnancyStallLinkedStall__C4BarnUi
    mvns	r0, r0
    lsrs	r4, r0, #31
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl HasBushelForPregnancyStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08032C34
    cmp	r4, #0
    bne .Lus_08032CA0
    ldr	r2, [sp, #56]	@ 0x38
    adds	r2, #1
    str	r2, [sp, #56]	@ 0x38
    b .Lus_08032CA0
.Lus_08032C30:
    .4byte 0x000005DC
.Lus_08032C34:
    cmp	r4, #0
    beq .Lus_08032CA0
    add	r0, sp, #16
    adds	r1, r7, #0
    adds	r2, r6, #0
    bl method_0800D0C0__C4BarnUi
    ldr	r0, [sp, #16]
    str	r0, [sp, #20]
    mov	r3, r8
    movs	r0, #0
    ldrsh	r1, [r3, r0]
    ldr	r2, [sp, #104]	@ 0x68
    subs	r1, r1, r2
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r5, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_08032C76
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r5, r0
    bcs .Lus_08032CA0
.Lus_08032C76:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #5
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032CA0
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Lus_08032CA0:
    adds	r6, #1
    cmp	r6, r9
    bcc .Lus_08032C0A
.Lus_08032CA6:
    movs	r6, #0
    mov	r9, r6
    ldr	r1, [sp, #44]	@ 0x2c
    ldr r2, .Lus_08032D30
    adds	r0, r1, r2
    bl GetCapacity__C4Barn
    adds	r6, r0, #0
    movs	r5, #0
    cmp	r9, r6
    bcs .Lus_08032D06
.Lus_08032CBC:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetBarnAnimal__C4BarnUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_08032D00
    mov	r3, sl
    ldr	r0, [r3, #0]
    adds	r1, r5, #0
    adds	r1, #54	@ 0x36
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    cmp	r0, #0
    beq .Lus_08032D00
    ldrh	r0, [r0, #4]
    cmp	r0, #37	@ 0x25
    bne .Lus_08032D00
    adds	r0, r4, #0
    bl HasBeenFed__C9Livestock
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032D00
    adds	r0, r4, #0
    bl IsPregnant__C10BarnAnimal
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032D00
    movs	r0, #1
    add	r9, r0
.Lus_08032D00:
    adds	r5, #1
    cmp	r5, r6
    bcc .Lus_08032CBC
.Lus_08032D06:
    mov	r1, r9
    cmp	r1, #0
    bne .Lus_08032D0E
    b .Lus_08032E1C
.Lus_08032D0E:
    str	r6, [sp, #60]	@ 0x3c
    movs	r2, #0
    mov	r8, r2
    movs	r4, #0
    cmp	r8, r6
    bcs .Lus_08032D4E
.Lus_08032D1A:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForStall__C4BarnUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08032D34
    ldr	r3, [sp, #56]	@ 0x38
    adds	r3, #1
    str	r3, [sp, #56]	@ 0x38
    b .Lus_08032D46
.Lus_08032D30:
    .4byte 0x000005DC
.Lus_08032D34:
    cmp	r4, #15
    bhi .Lus_08032D46
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Lus_08032D46:
    adds	r4, #1
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r4, r0
    bcc .Lus_08032D1A
.Lus_08032D4E:
    ldr	r1, [sp, #56]	@ 0x38
    cmp	r9, r1
    bls .Lus_08032E1C
    movs	r3, #0
    movs	r4, #31
    movs	r5, #1
    ldr	r2, [sp, #112]	@ 0x70
.Lus_08032D5C:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    bne .Lus_08032D7E
    ldr	r6, [sp, #56]	@ 0x38
    adds	r6, #1
    str	r6, [sp, #56]	@ 0x38
    ldrb	r1, [r2, #1]
    cmp	r1, #15
    bhi .Lus_08032D7E
    ands	r1, r4
    adds	r0, r5, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Lus_08032D7E:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Lus_08032D5C
    ldr	r2, [sp, #56]	@ 0x38
    cmp	r9, r2
    bls .Lus_08032E1C
    movs	r4, #0
    ldr	r3, [sp, #60]	@ 0x3c
    cmp	r4, r3
    bcs .Lus_08032E1C
    mov	r6, sp
    adds	r6, #28
    str	r6, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r0, #16
    negs	r0, r0
    mov	r9, r0
.Lus_08032DA2:
    movs	r0, #0
    cmp	r4, #15
    bhi .Lus_08032DBA
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r2, r8
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Lus_08032DBA:
    cmp	r0, #0
    beq .Lus_08032E14
    add	r0, sp, #24
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800D074__C4BarnUi
    ldr	r0, [sp, #24]
    str	r0, [sp, #28]
    ldr	r3, [sp, #68]	@ 0x44
    movs	r6, #0
    ldrsh	r1, [r3, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #2
    ldrsh	r0, [r3, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r6, r1, #0
    muls	r6, r1
    adds	r1, r6, #0
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_08032DFC
    ldr	r3, [sp, #52]	@ 0x34
    cmp	r2, r3
    bcs .Lus_08032E14
.Lus_08032DFC:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #4
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Lus_08032E14:
    adds	r4, #1
    ldr	r6, [sp, #60]	@ 0x3c
    cmp	r4, r6
    bcc .Lus_08032DA2
.Lus_08032E1C:
    ldr	r0, [sp, #48]	@ 0x30
    cmp	r0, #17
    beq .Lus_08032E24
    b .Lus_08032F8C
.Lus_08032E24:
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r2, #255	@ 0xff
    lsls	r2, r2, #2
    adds	r7, r1, r2
    adds	r0, r7, #0
    bl GetStoredBushelCount__C4Coop
    cmp	r0, #0
    bne .Lus_08032E38
    b .Lus_08032F8C
.Lus_08032E38:
    adds	r0, r7, #0
    bl GetCapacity__C4Coop
    adds	r6, r0, #0
    movs	r3, #0
    mov	r9, r3
    movs	r5, #0
    cmp	r9, r6
    bcs .Lus_08032E88
.Lus_08032E4A:
    adds	r0, r7, #0
    adds	r1, r5, #0
    bl GetChicken__C4CoopUi
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_08032E82
    mov	r1, sl
    ldr	r0, [r1, #0]
    adds	r1, r5, #0
    adds	r1, #46	@ 0x2e
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    bl _call_via_r2
    cmp	r0, #0
    beq .Lus_08032E82
    ldrh	r0, [r0, #4]
    cmp	r0, #17
    bne .Lus_08032E82
    adds	r0, r4, #0
    bl HasBeenFed__C9Livestock
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032E82
    movs	r2, #1
    add	r9, r2
.Lus_08032E82:
    adds	r5, #1
    cmp	r5, r6
    bcc .Lus_08032E4A
.Lus_08032E88:
    mov	r3, r9
    cmp	r3, #0
    beq .Lus_08032F8C
    str	r6, [sp, #64]	@ 0x40
    movs	r5, #0
    mov	r8, r5
    movs	r4, #0
    cmp	r8, r6
    bcs .Lus_08032EC6
.Lus_08032E9A:
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl HasBushelForEnt__C4CoopUi
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_08032EAC
    adds	r5, #1
    b .Lus_08032EBE
.Lus_08032EAC:
    cmp	r4, #7
    bhi .Lus_08032EBE
    movs	r1, #31
    ands	r1, r4
    movs	r0, #1
    lsls	r0, r1
    mov	r6, r8
    orrs	r6, r0
    mov	r8, r6
.Lus_08032EBE:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Lus_08032E9A
.Lus_08032EC6:
    cmp	r9, r5
    bls .Lus_08032F8C
    movs	r3, #0
    movs	r4, #31
    movs	r6, #1
    ldr	r2, [sp, #112]	@ 0x70
.Lus_08032ED2:
    ldrb	r0, [r2, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #3
    bne .Lus_08032EF0
    adds	r5, #1
    ldrb	r1, [r2, #1]
    cmp	r1, #7
    bhi .Lus_08032EF0
    ands	r1, r4
    adds	r0, r6, #0
    lsls	r0, r1
    mov	r1, r8
    bics	r1, r0
    mov	r8, r1
.Lus_08032EF0:
    adds	r2, #8
    adds	r3, #1
    cmp	r3, #6
    bls .Lus_08032ED2
    cmp	r9, r5
    bls .Lus_08032F8C
    movs	r4, #0
    ldr	r2, [sp, #64]	@ 0x40
    cmp	r4, r2
    bcs .Lus_08032F8C
    mov	r3, sp
    adds	r3, #36	@ 0x24
    str	r3, [sp, #68]	@ 0x44
    add	r5, sp, #8
    movs	r6, #16
    negs	r6, r6
    mov	r9, r6
.Lus_08032F12:
    movs	r0, #0
    cmp	r4, #7
    bhi .Lus_08032F2A
    movs	r0, #31
    ands	r0, r4
    movs	r1, #1
    lsls	r1, r0
    mov	r0, r8
    ands	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Lus_08032F2A:
    cmp	r0, #0
    beq .Lus_08032F84
    add	r0, sp, #32
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl method_0800C6F0__C4CoopUi
    ldr	r0, [sp, #32]
    str	r0, [sp, #36]	@ 0x24
    ldr	r2, [sp, #68]	@ 0x44
    movs	r3, #0
    ldrsh	r1, [r2, r3]
    ldr	r6, [sp, #104]	@ 0x68
    subs	r1, r1, r6
    movs	r3, #2
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r2, r1, r0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_08032F6C
    ldr	r6, [sp, #52]	@ 0x34
    cmp	r2, r6
    bcs .Lus_08032F84
.Lus_08032F6C:
    ldrb	r1, [r5, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #3
    orrs	r0, r1
    strb	r0, [r5, #0]
    strb	r4, [r5, #1]
    mov	r1, sp
    adds	r0, r5, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    str	r2, [sp, #52]	@ 0x34
.Lus_08032F84:
    adds	r4, #1
    ldr	r0, [sp, #64]	@ 0x40
    cmp	r4, r0
    bcc .Lus_08032F12
.Lus_08032F8C:
    movs	r6, #54	@ 0x36
    movs	r7, #16
    negs	r7, r7
.Lus_08032F92:
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r6, #0
    bl _call_via_r2
    adds	r4, r0, #0
    cmp	r4, #0
    beq .Lus_0803303A
    ldrh	r0, [r4, #4]
    ldr	r2, [sp, #48]	@ 0x30
    cmp	r0, r2
    bne .Lus_0803303A
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #80]	@ 0x50
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032FDE
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #84]	@ 0x54
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08032FDE
    ldr	r0, [r4, #20]
    ldr	r1, [r0, #88]	@ 0x58
    adds	r0, r4, #0
    bl _call_via_r1
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803303A
.Lus_08032FDE:
    movs	r3, #10
    ldrsh	r1, [r4, r3]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r2, #14
    ldrsh	r0, [r4, r2]
    ldr	r3, [sp, #108]	@ 0x6c
    subs	r0, r0, r3
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    adds	r5, r1, #0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_0803300E
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    bcs .Lus_0803303A
.Lus_0803300E:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    adds	r0, r7, #0
    ands	r0, r1
    movs	r1, #6
    orrs	r0, r1
    strb	r0, [r4, #0]
    adds	r0, r6, #0
    subs	r0, #54	@ 0x36
    strb	r0, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803303A
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r5, [sp, #52]	@ 0x34
.Lus_0803303A:
    adds	r6, #1
    cmp	r6, #69	@ 0x45
    bls .Lus_08032F92
    movs	r4, #46	@ 0x2e
.Lus_08033042:
    mov	r6, sl
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r4, #0
    bl _call_via_r2
    adds	r4, #1
    cmp	r4, #53	@ 0x35
    bls .Lus_08033042
    movs	r5, #76	@ 0x4c
    movs	r7, #16
    negs	r7, r7
.Lus_0803305C:
    mov	r1, sl
    ldr	r0, [r1, #0]
    ldr	r2, [r0, #68]	@ 0x44
    mov	r0, sl
    adds	r1, r5, #0
    bl _call_via_r2
    adds	r2, r0, #0
    cmp	r2, #0
    beq .Lus_080330D4
    ldrh	r0, [r2, #4]
    ldr	r3, [sp, #48]	@ 0x30
    cmp	r0, r3
    bne .Lus_080330D4
    movs	r6, #10
    ldrsh	r1, [r2, r6]
    ldr	r0, [sp, #104]	@ 0x68
    subs	r1, r1, r0
    movs	r3, #14
    ldrsh	r0, [r2, r3]
    ldr	r6, [sp, #108]	@ 0x6c
    subs	r0, r0, r6
    adds	r2, r1, #0
    muls	r2, r1
    adds	r1, r2, #0
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    adds	r6, r1, #0
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_080330A8
    ldr	r0, [sp, #52]	@ 0x34
    cmp	r1, r0
    bcs .Lus_080330D4
.Lus_080330A8:
    add	r4, sp, #8
    ldrb	r1, [r4, #0]
    adds	r0, r7, #0
    ands	r0, r1
    movs	r1, #8
    orrs	r0, r1
    strb	r0, [r4, #0]
    adds	r0, r5, #0
    subs	r0, #76	@ 0x4c
    strb	r0, [r4, #1]
    ldr	r0, [sp, #112]	@ 0x70
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_080330D4
    mov	r1, sp
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    str	r6, [sp, #52]	@ 0x34
.Lus_080330D4:
    adds	r5, #1
    cmp	r5, #83	@ 0x53
    bls .Lus_0803305C
    ldr	r1, [sp, #40]	@ 0x28
    mov	r0, sp
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    ldr	r0, [sp, #40]	@ 0x28
    add	sp, #72	@ 0x48
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_080330F4
    .thumb_func
func_080330F4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #108	@ 0x6c
    str	r0, [sp, #68]	@ 0x44
    adds	r5, r1, #0
    adds	r7, r2, #0
    adds	r4, r3, #0
    ldr	r3, [sp, #140]	@ 0x8c
    add	r2, sp, #12
    ldrb	r1, [r2, #0]
    movs	r6, #16
    negs	r6, r6
    adds	r0, r6, #0
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrb	r1, [r4, #1]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #2]
    ldr r2, .Lus_08033150
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    str	r0, [sp, #72]	@ 0x48
    ldrb	r1, [r4, #3]
    lsrs	r1, r1, #2
    ldrh	r0, [r4, #4]
    ands	r0, r2
    lsls	r0, r0, #6
    orrs	r0, r1
    lsls	r0, r0, #16
    asrs	r0, r0, #16
    mov	sl, r0
    cmp	r3, #1
    bne .Lus_08033144
    b .Lus_08033286
.Lus_08033144:
    cmp	r3, #1
    bgt .Lus_08033154
    cmp	r3, #0
    beq .Lus_0803315C
    b .Lus_0803356A
    .align 2, 0
.Lus_08033150:
    .4byte 0x000003FF
.Lus_08033154:
    cmp	r3, #2
    bne .Lus_0803315A
    b .Lus_0803333C
.Lus_0803315A:
    b .Lus_0803356A
.Lus_0803315C:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    mov	r9, r0
    ldr r1, .Lus_080331F4
    adds	r1, r5, r1
    str	r1, [sp, #80]	@ 0x50
    mov	r2, sp
    adds	r2, #32
    str	r2, [sp, #84]	@ 0x54
.Lus_0803316E:
    movs	r7, #0
    mov	r3, r9
    lsls	r3, r3, #1
    str	r3, [sp, #100]	@ 0x64
    mov	r4, r9
    adds	r4, #1
    str	r4, [sp, #96]	@ 0x60
    ldr	r6, [sp, #72]	@ 0x48
    negs	r0, r6
    movs	r1, #140	@ 0x8c
    lsls	r1, r1, #1
    adds	r6, r0, r1
.Lus_08033186:
    ldr	r0, [sp, #100]	@ 0x64
    adds	r0, #23
    lsls	r0, r0, #3
    mov	r2, sl
    subs	r0, r0, r2
    adds	r1, r6, #0
    muls	r1, r6
    adds	r3, r0, #0
    muls	r3, r0
    adds	r0, r3, #0
    adds	r1, r1, r0
    mov	r8, r1
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_080331AE
    ldr	r4, [sp, #76]	@ 0x4c
    cmp	r8, r4
    bcs .Lus_08033272
.Lus_080331AE:
    movs	r0, #43	@ 0x2b
    mov	r1, r9
    muls	r1, r0
    adds	r0, r1, #0
    adds	r0, r7, r0
    lsls	r0, r0, #2
    ldr	r2, [sp, #80]	@ 0x50
    adds	r0, r2, r0
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r0, r0, #28
    cmp	r0, #5
    bne .Lus_080331EE
    str	r1, [sp, #28]
    add	r0, sp, #20
    add	r1, sp, #28
    bl method_0800A4A4__9FieldPlot
    add	r5, sp, #20
    adds	r0, r5, #0
    bl IsEmpty__C12RucksackItem
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_080331EE
    adds	r0, r5, #0
    bl GetKind__C12RucksackItem
    cmp	r0, #0
    beq .Lus_080331F8
    cmp	r0, #1
    beq .Lus_08033220
.Lus_080331EE:
    movs	r1, #0
    b .Lus_0803323E
    .align 2, 0
.Lus_080331F4:
    .4byte 0x000009C8
.Lus_080331F8:
    add	r0, sp, #24
    adds	r1, r5, #0
    bl GetFood__C12RucksackItem
    add	r0, sp, #24
    ldrb	r1, [r0, #0]
    adds	r0, #1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #8
    orrs	r0, r1
    mov	r1, sp
    adds	r1, #26
    ldrb	r1, [r1, #0]
    lsls	r1, r1, #16
    orrs	r1, r0
    ldr	r0, [sp, #84]	@ 0x54
    bl __7ProductG4Food
    ldr	r0, [sp, #84]	@ 0x54
    b .Lus_08033234
.Lus_08033220:
    mov	r4, sp
    adds	r4, #33	@ 0x21
    adds	r0, r5, #0
    bl GetArticle__C12RucksackItem
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl __7ProductG7Article
    adds	r0, r4, #0
.Lus_08033234:
    bl GetPrice__C7Product
    negs	r1, r0
    orrs	r1, r0
    lsrs	r1, r1, #31
.Lus_0803323E:
    cmp	r1, #0
    beq .Lus_08033272
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #2
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r7, [r4, #1]
    mov	r3, r9
    strb	r3, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    bl func_0809E968
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08033272
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r4}
    stmia	r1!, {r2, r4}
    mov	r3, r8
    str	r3, [sp, #76]	@ 0x4c
.Lus_08033272:
    adds	r6, #16
    adds	r7, #1
    cmp	r7, #42	@ 0x2a
    bls .Lus_08033186
    ldr	r4, [sp, #96]	@ 0x60
    mov	r9, r4
    cmp	r4, #24
    bhi .Lus_08033284
    b .Lus_0803316E
.Lus_08033284:
    b .Lus_0803356A
.Lus_08033286:
    movs	r0, #0
    str	r0, [sp, #88]	@ 0x58
    movs	r7, #0
    ldr r1, .Lus_08033338
    adds	r1, r1, r5
    mov	r9, r1
.Lus_08033292:
    movs	r6, #0
    adds	r2, r7, #1
    mov	r8, r2
    ldr	r3, [sp, #72]	@ 0x48
    negs	r0, r3
    movs	r4, #140	@ 0x8c
    lsls	r4, r4, #1
    adds	r5, r0, r4
.Lus_080332A2:
    movs	r0, #43	@ 0x2b
    muls	r0, r7
    adds	r0, r6, r0
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r1, [r0, #0]
    lsls	r0, r1, #20
    lsrs	r2, r0, #28
    movs	r3, #0
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_080332CE
    subs	r0, r2, #1
    cmp	r0, #3
    bhi .Lus_080332CE
    lsls	r0, r1, #24
    lsrs	r0, r0, #26
    movs	r1, #20
    eors	r0, r1
    negs	r0, r0
    lsrs	r3, r0, #31
.Lus_080332CE:
    cmp	r3, #0
    beq .Lus_08033328
    lsls	r0, r7, #4
    adds	r0, #184	@ 0xb8
    mov	r1, sl
    subs	r0, r0, r1
    adds	r1, r5, #0
    muls	r1, r5
    adds	r2, r0, #0
    muls	r2, r0
    adds	r0, r2, #0
    adds	r1, r1, r0
    adds	r2, r1, #0
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_080332F8
    ldr	r3, [sp, #88]	@ 0x58
    cmp	r1, r3
    bcs .Lus_08033328
.Lus_080332F8:
    add	r4, sp, #20
    ldrb	r1, [r4, #0]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r4, #0]
    strb	r6, [r4, #1]
    strb	r7, [r4, #2]
    ldr	r0, [sp, #144]	@ 0x90
    adds	r1, r4, #0
    str	r2, [sp, #104]	@ 0x68
    bl func_0809E968
    lsls	r0, r0, #24
    ldr	r2, [sp, #104]	@ 0x68
    cmp	r0, #0
    bne .Lus_08033328
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    str	r2, [sp, #88]	@ 0x58
.Lus_08033328:
    adds	r5, #16
    adds	r6, #1
    cmp	r6, #42	@ 0x2a
    bls .Lus_080332A2
    mov	r7, r8
    cmp	r7, #24
    bls .Lus_08033292
    b .Lus_0803356A
.Lus_08033338:
    .4byte 0x000009C8
.Lus_0803333C:
    add	r0, sp, #36	@ 0x24
    bl smethod_08009ADC__4Farm
    ldr	r0, [sp, #36]	@ 0x24
    str	r0, [sp, #40]	@ 0x28
    add	r6, sp, #40	@ 0x28
    mov	r8, r6
    add	r0, sp, #44	@ 0x2c
    bl smethod_08009AE8__4Farm
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [sp, #48]	@ 0x30
    add	r6, sp, #48	@ 0x30
    add	r0, sp, #52	@ 0x34
    bl method_0800CE58__4Barn
    ldr	r0, [sp, #52]	@ 0x34
    str	r0, [sp, #56]	@ 0x38
    mov	r0, sp
    adds	r0, #56	@ 0x38
    str	r0, [sp, #92]	@ 0x5c
    add	r0, sp, #60	@ 0x3c
    bl method_0800C554__4Coop
    ldr	r0, [sp, #60]	@ 0x3c
    str	r0, [sp, #64]	@ 0x40
    add	r1, sp, #64	@ 0x40
    mov	r9, r1
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    cmp	r0, #17
    bne .Lus_08033380
    b .Lus_080334EA
.Lus_08033380:
    cmp	r0, #17
    bgt .Lus_0803338A
    cmp	r0, #2
    beq .Lus_08033390
    b .Lus_0803356A
.Lus_0803338A:
    cmp	r0, #37	@ 0x25
    beq .Lus_08033466
    b .Lus_0803356A
.Lus_08033390:
    ldr	r2, [sp, #72]	@ 0x48
    str	r2, [sp, #0]
    mov	r3, sl
    str	r3, [sp, #4]
    ldr	r4, [sp, #144]	@ 0x90
    str	r4, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_080333BE
    b .Lus_0803356A
.Lus_080333BE:
    mov	r1, r8
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    mov	r2, r8
    movs	r1, #2
    ldrsh	r0, [r2, r1]
    mov	r2, sl
    subs	r1, r0, r2
    adds	r2, r3, #0
    muls	r2, r3
    adds	r0, r1, #0
    muls	r0, r1
    adds	r2, r2, r0
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    ldr	r1, [sp, #72]	@ 0x48
    subs	r3, r0, r1
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    mov	r6, sl
    subs	r1, r0, r6
    adds	r0, r3, #0
    muls	r0, r3
    adds	r3, r1, #0
    muls	r3, r1
    adds	r1, r3, #0
    adds	r0, r0, r1
    cmp	r2, r0
    bhi .Lus_08033418
    ldr	r6, [sp, #92]	@ 0x5c
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Lus_080334AC
.Lus_08033418:
    mov	r6, r9
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    beq .Lus_0803344A
    b .Lus_0803356A
.Lus_0803344A:
    ldr	r3, [sp, #92]	@ 0x5c
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    b .Lus_080334DC
.Lus_08033466:
    ldr	r6, [sp, #72]	@ 0x48
    str	r6, [sp, #0]
    mov	r0, sl
    str	r0, [sp, #4]
    ldr	r1, [sp, #144]	@ 0x90
    str	r1, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lus_0803356A
    mov	r6, r8
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #0]
    movs	r2, #2
    ldrsh	r0, [r6, r2]
    str	r0, [sp, #4]
    ldr	r3, [sp, #144]	@ 0x90
    str	r3, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
.Lus_080334AC:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r6}
    stmia	r1!, {r2, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lus_0803356A
    mov	r3, r9
    movs	r6, #0
    ldrsh	r0, [r3, r6]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r3, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
.Lus_080334DC:
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r4}
    stmia	r1!, {r3, r4}
    b .Lus_0803356A
.Lus_080334EA:
    ldr	r0, [sp, #72]	@ 0x48
    str	r0, [sp, #0]
    mov	r1, sl
    str	r1, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    add	r4, sp, #20
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #17
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lus_0803356A
    movs	r3, #0
    ldrsh	r0, [r6, r3]
    str	r0, [sp, #0]
    movs	r1, #2
    ldrsh	r0, [r6, r1]
    str	r0, [sp, #4]
    ldr	r2, [sp, #144]	@ 0x90
    str	r2, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #2
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r3, r6}
    stmia	r1!, {r3, r6}
    add	r0, sp, #12
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lus_0803356A
    ldr	r1, [sp, #92]	@ 0x5c
    movs	r2, #0
    ldrsh	r0, [r1, r2]
    str	r0, [sp, #0]
    movs	r3, #2
    ldrsh	r0, [r1, r3]
    str	r0, [sp, #4]
    ldr	r6, [sp, #144]	@ 0x90
    str	r6, [sp, #8]
    adds	r0, r4, #0
    adds	r1, r5, #0
    adds	r2, r7, #0
    movs	r3, #37	@ 0x25
    bl func_08032BB4
    add	r1, sp, #12
    adds	r0, r4, #0
    ldmia	r0!, {r2, r3}
    stmia	r1!, {r2, r3}
.Lus_0803356A:
    ldr	r1, [sp, #68]	@ 0x44
    add	r0, sp, #12
    ldmia	r0!, {r4, r6}
    stmia	r1!, {r4, r6}
    ldr	r0, [sp, #68]	@ 0x44
    add	sp, #108	@ 0x6c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033584
    .thumb_func
func_08033584:
    push	{r4, r5, r6, lr}
    sub	sp, #16
    adds	r4, r0, #0
    adds	r5, r1, #0
    adds	r3, r2, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lus_08033648
    lsls	r0, r0, #2
    ldr r1, .Lus_080335A4
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_080335A4:
    .4byte .Lus_080335A8
.Lus_080335A8:
    .4byte .Lus_08033648
    .4byte .Lus_080335CC
    .4byte .Lus_08033608
    .4byte .Lus_080336A4
    .4byte .Lus_080336C0
    .4byte .Lus_080336E0
    .4byte .Lus_08033708
    .4byte .Lus_08033754
    .4byte .Lus_08033764
.Lus_080335CC:
    .4byte 0x480D78A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F020508
    .4byte 0x07882300
    .4byte 0x28010F80
    .4byte 0x1E50D108
    .4byte 0xD8052803
    .4byte 0x0E800608
    .4byte 0x40482114
    .4byte 0x0FC34240
    .4byte 0xE0BA1C18
    .4byte 0x000009C8
.Lus_08033608:
    .4byte 0x481078A2
    .4byte 0x202B1829
    .4byte 0x78644350
    .4byte 0x00801900
    .4byte 0x68091809
    .4byte 0x0F000508
    .4byte 0xD1112805
    .4byte 0xA9029102
    .4byte 0xF7D64668
    .4byte 0x4668FF3B
    .4byte 0xFD1CF7DB
    .4byte 0x28000600
    .4byte 0x4668D106
    .4byte 0xFD2EF7DB
    .4byte 0xD0052800
    .4byte 0xD01D2801
.Lus_08033648:
    movs	r0, #0
    b .Lus_0803377A
    .4byte 0x000009C8
    .4byte 0xA801AC03
    .4byte 0xF7DB4669
    .4byte 0xA801FD25
    .4byte 0x30017801
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x78093106
    .4byte 0x43010409
    .4byte 0xF7DA1C20
    .4byte 0x1C20FD43
    .4byte 0xFD8EF7DA
    .4byte 0x43014241
    .4byte 0xE07A0FC8
    .4byte 0x340D466C
    .4byte 0xF7DB4668
    .4byte 0x1C01FD2D
    .4byte 0xF7DA1C20
    .4byte 0x1C20FD59
    .4byte 0xFD7EF7DA
    .4byte 0x43014241
    .4byte 0xE06A0FC8
.Lus_080336A4:
    .4byte 0x20FF2600
    .4byte 0x182D0080
    .4byte 0xF7D81C28
    .4byte 0x2800FF5B
    .4byte 0x7861D024
    .4byte 0xF7D81C28
    .4byte 0xE01BFF6D
.Lus_080336C0:
    .4byte 0x48062600
    .4byte 0x1C28182D
    .4byte 0xFBD0F7D9
    .4byte 0xD0172800
    .4byte 0x1C287861
    .4byte 0xFBE8F7D9
    .4byte 0x0000E00E
    .4byte 0x000005DC
.Lus_080336E0:
    .4byte 0x48082600
    .4byte 0x1C28182D
    .4byte 0xFBC0F7D9
    .4byte 0xD0072800
    .4byte 0x1C287861
    .4byte 0xFBEEF7D9
    .4byte 0x28000600
    .4byte 0x2601D100
    .4byte 0xE03A1C30
    .4byte 0x000005DC
.Lus_08033708:
    .4byte 0x31367861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C04F8FF
    .4byte 0x2C002500
    .4byte 0x6960D018
    .4byte 0x1C206D01
    .4byte 0xF8F4F0A0
    .4byte 0x28000600
    .4byte 0x6960D10F
    .4byte 0x1C206D41
    .4byte 0xF8ECF0A0
    .4byte 0x28000600
    .4byte 0x6960D107
    .4byte 0x1C206D81
    .4byte 0xF8E4F0A0
    .4byte 0x28000600
    .4byte 0x2501D000
    .4byte 0xE0121C28
.Lus_08033754:
    .4byte 0x312E7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0xE771F8D9
.Lus_08033764:
    .4byte 0x314C7861
    .4byte 0x6C426818
    .4byte 0xF0A01C18
    .4byte 0x1C01F8D1
    .4byte 0x43084248
    .hword 0x0FC0
.Lus_0803377A:
    add	sp, #16
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033784
    .thumb_func
func_08033784:
    push	{r4, lr}
    adds	r3, r0, #0
    adds	r4, r2, #0
    ldrb	r0, [r3, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lus_080337F2
    lsls	r0, r0, #2
    ldr r1, .Lus_080337A0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_080337A0:
    .4byte .Lus_080337A4
.Lus_080337A4:
    .4byte .Lus_080337F2
    .4byte .Lus_080337C8
    .4byte .Lus_080337C8
    .4byte .Lus_080337CC
    .4byte .Lus_080337D0
    .4byte .Lus_080337D0
    .4byte .Lus_080337D4
    .4byte .Lus_080337DA
    .4byte .Lus_080337E0
.Lus_080337C8:
    .4byte 0xE0162002
.Lus_080337CC:
    .4byte 0xE0142011
.Lus_080337D0:
    .4byte 0xE0122025
.Lus_080337D4:
    .4byte 0x31367859
    .hword 0xE004
.Lus_080337DA:
    .hword 0x7859
    .4byte 0xE001312E
.Lus_080337E0:
    .4byte 0x314C7859
    .4byte 0x6C426820
    .4byte 0xF0A01C20
    .4byte 0x2800F893
    .hword 0xD102
.Lus_080337F2:
    movs	r0, #141	@ 0x8d
    lsls	r0, r0, #2
    b .Lus_080337FA
    .hword 0x8880
.Lus_080337FA:
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_08033800
    .thumb_func
func_08033800:
    push	{r4, lr}
    adds	r4, r0, #0
    adds	r0, r1, #0
    adds	r1, r2, #0
    ldr	r2, [r0, #0]
    ldr	r2, [r2, #68]	@ 0x44
    bl _call_via_r2
    adds	r1, r0, #0
    cmp	r1, #0
    beq .Lus_08033822
    movs	r2, #10
    ldrsh	r0, [r1, r2]
    movs	r2, #14
    ldrsh	r1, [r1, r2]
    strh	r0, [r4, #0]
    b .Lus_08033824
.Lus_08033822:
    strh	r1, [r4, #0]
.Lus_08033824:
    strh	r1, [r4, #2]
    adds	r0, r4, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033830
    .thumb_func
func_08033830:
    push	{r4, r5, lr}
    adds	r5, r0, #0
    adds	r4, r1, #0
    ldrb	r0, [r4, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bhi .Lus_08033874
    lsls	r0, r0, #2
    ldr r1, .Lus_0803384C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_0803384C:
    .4byte .Lus_08033850
.Lus_08033850:
    .4byte .Lus_08033874
    .4byte .Lus_0803387C
    .4byte .Lus_0803387C
    .4byte .Lus_08033892
    .4byte .Lus_080338A2
    .4byte .Lus_080338B4
    .4byte .Lus_080338C8
    .4byte .Lus_080338CE
    .4byte .Lus_080338DC
.Lus_08033874:
    movs	r0, #0
    strh	r0, [r5, #0]
    strh	r0, [r5, #2]
    b .Lus_080338E8
.Lus_0803387C:
    .4byte 0x78A17860
    .4byte 0x228C0100
    .4byte 0x18800052
    .4byte 0x31B80109
    .4byte 0x80698028
    .hword 0xE02A
.Lus_08033892:
    .hword 0x20FF
    .4byte 0x18110080
    .4byte 0x1C287862
    .4byte 0xFF28F7D8
    .hword 0xE022
.Lus_080338A2:
    .hword 0x4803
    .4byte 0x78621811
    .4byte 0xF7D91C28
    .4byte 0xE01BFBE3
    .4byte 0x000005DC
.Lus_080338B4:
    .4byte 0x18114803
    .4byte 0x1C287862
    .4byte 0xFC00F7D9
    .4byte 0x0000E012
    .4byte 0x000005DC
.Lus_080338C8:
    .4byte 0x32367862
    .hword 0xE001
.Lus_080338CE:
    .hword 0x7862
    .4byte 0x1C28322E
    .4byte 0xF7FF1C19
    .4byte 0xE005FF93
.Lus_080338DC:
    .4byte 0x324C7862
    .4byte 0x1C191C28
    .4byte 0xFF8CF7FF
.Lus_080338E8:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_080338F0
    .thumb_func
func_080338F0:
    push	{r4, lr}
    adds	r4, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #2
    bl func_080AB788
    movs	r1, #0
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #1
    adds	r4, r4, r2
    cmp	r0, r4
    bcs .Lus_0803390A
    movs	r1, #1
.Lus_0803390A:
    adds	r0, r1, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_harvest_sprite_task_experience_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033928
    .thumb_func
func_08033928:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #20
    adds	r7, r0, #0
    adds	r5, r1, #0
    adds	r6, r2, #0
    adds	r4, r3, #0
    ldr r1, .Lus_080339A4
    lsls	r0, r6, #2
    adds	r0, r0, r1
    ldr	r2, [r0, #0]
    add	r0, sp, #4
    adds	r1, r4, #0
    bl func_080A03B8
    ldr r1, .Lus_080339A8
    lsls	r0, r6, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    str	r0, [sp, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    add	r2, sp, #4
    movs	r3, #2
    bl __12AActorEntityP10GameObjectRC13ActorLocationUiUi
    ldr r0, .Lus_080339AC
    str	r0, [r7, #20]
    adds	r0, r7, #0
    adds	r0, #48	@ 0x30
    movs	r5, #0
    strb	r6, [r0, #0]
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl func_080A099C
    str	r0, [r7, #52]	@ 0x34
    movs	r0, #135	@ 0x87
    lsls	r0, r0, #3
    adds	r4, r4, r0
    str	r4, [r7, #56]	@ 0x38
    ldr	r0, [sp, #44]	@ 0x2c
    str	r0, [r7, #60]	@ 0x3c
    adds	r0, r7, #0
    adds	r0, #65	@ 0x41
    strb	r5, [r0, #0]
    adds	r0, #1
    strb	r5, [r0, #0]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    mov	r8, r0
    ldr	r0, [r7, #52]	@ 0x34
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Lus_08033A08
    lsls	r0, r0, #2
    ldr r1, .Lus_080339B0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_080339A4:
    .4byte gUnk_080F149C
.Lus_080339A8:
    .4byte gUnk_080F14E2
.Lus_080339AC:
    .4byte vtable_unk_080E68C8
.Lus_080339B0:
    .4byte .Lus_080339B4
.Lus_080339B4:
    .4byte .Lus_080339D8
    .4byte .Lus_08033A06
    .4byte .Lus_080339D0
    .4byte .Lus_080339EC
    .4byte .Lus_080339CC
    .4byte .Lus_08033A06
.Lus_080339CC:
    .4byte 0xE01B2504
.Lus_080339D0:
    .4byte 0x30226B78
    .4byte 0xE0177805
.Lus_080339D8:
    .4byte 0x1C20AC03
    .4byte 0xF06A1C31
    .4byte 0x1C38FF11
    .4byte 0xF7FE1C21
    .4byte 0xE00DFB99
.Lus_080339EC:
    .4byte 0x6B7C2501
    .4byte 0xF06A1C20
    .4byte 0x1C01FE33
    .4byte 0xF06A1C20
    .4byte 0xF7FFFE37
    .4byte 0x4680FF89
    .hword 0xE000
.Lus_08033A06:
    .hword 0x2501
.Lus_08033A08:
    mvns	r1, r5
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    strb	r1, [r0, #0]
    subs	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r7, #0
    adds	r1, r5, #0
    mov	r3, r8
    bl func_08034180
    adds	r0, r7, #0
    add	sp, #20
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_08033A2C
    .thumb_func
func_08033A2C:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r5, r0, #0
    adds	r6, r1, #0
    ldr r0, .Lus_08033A78
    str	r0, [r5, #20]
    ldr	r4, [r5, #52]	@ 0x34
    mov	r0, sp
    adds	r1, r5, #0
    bl GetLocation__C12AActorEntity
    adds	r0, r4, #0
    mov	r1, sp
    bl SetLocation__3NpcRC13ActorLocation
    ldr r0, .Lus_08033A7C
    str	r0, [r5, #20]
    ldr	r1, [r5, #16]
    cmp	r1, #0
    beq .Lus_08033A60
    ldr	r0, [r1, #4]
    ldr	r2, [r0, #8]
    adds	r0, r1, #0
    movs	r1, #3
    bl _call_via_r2
.Lus_08033A60:
    movs	r0, #1
    ands	r0, r6
    cmp	r0, #0
    beq .Lus_08033A6E
    adds	r0, r5, #0
    bl __builtin_delete
.Lus_08033A6E:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08033A78:
    .4byte vtable_unk_080E68C8
.Lus_08033A7C:
    .4byte __vt_7AEntity
    .global func_08033A80
    .thumb_func
func_08033A80:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    movs	r0, #212	@ 0xd4
    bl __builtin_new
    adds	r1, r4, #0
    bl func_08034A14
    adds	r5, r0, #0
    movs	r1, #1
    negs	r1, r1
    adds	r4, #64	@ 0x40
    ldrb	r0, [r4, #0]
    cmp	r0, #2
    beq .Lus_08033AA4
    cmp	r0, #3
    beq .Lus_08033AA8
    b .Lus_08033AAA
.Lus_08033AA4:
    movs	r1, #8
    b .Lus_08033AAE
.Lus_08033AA8:
    movs	r1, #5
.Lus_08033AAA:
    cmp	r1, #0
    blt .Lus_08033ADA
.Lus_08033AAE:
    adds	r0, r5, #0
    adds	r0, #112	@ 0x70
    bl ResolveIndexedResourceHandle
    adds	r0, r5, #0
    adds	r0, #132	@ 0x84
    movs	r2, #0
    movs	r1, #1
    strb	r1, [r0, #0]
    adds	r0, #2
    strb	r2, [r0, #0]
    adds	r0, #1
    strb	r1, [r0, #0]
    adds	r3, r5, #0
    adds	r3, #138	@ 0x8a
    movs	r2, #2
    ldrb	r1, [r3, #0]
    movs	r0, #4
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r3, #0]
.Lus_08033ADA:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08033AE4
    .thumb_func
func_08033AE4:
    push	{lr}
    movs	r1, #0
    strb	r1, [r0, #6]
    adds	r2, r0, #0
    adds	r2, #66	@ 0x42
    movs	r1, #1
    strb	r1, [r2, #0]
    bl func_08033B7C
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08033AFC
    .thumb_func
func_08033AFC:
    ldr r1, .Lus_08033B0C
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #1
    adds	r0, r0, r1
    ldrh	r0, [r0, #0]
    bx	lr
    .align 2, 0
.Lus_08033B0C:
    .4byte gUnk_080F14D4
    .global func_08033B10
    .thumb_func
func_08033B10:
    push	{r4, lr}
    adds	r4, r0, #0
    bl vfunc_14__7AEntity
    ldr	r0, [r4, #52]	@ 0x34
    bl SetChangedLocation__3Npc
    pop	{r4}
    pop	{r0}
    bx	r0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_unknown_flag_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08033B84
    .thumb_func
func_08033B84:
    push	{lr}
    ldr	r0, [r0, #16]
    cmp	r0, #0
    beq .Lus_08033B90
    bl func_08034BFC
.Lus_08033B90:
    pop	{r0}
    bx	r0
    .global func_08033B94
    .thumb_func
func_08033B94:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #172	@ 0xac
    adds	r7, r0, #0
    adds	r2, r1, #0
    ldr	r0, [r7, #52]	@ 0x34
    mov	r8, r0
    ldr	r1, [r7, #0]
    mov	sl, r1
    ldr	r0, [r0, #28]
    cmp	r0, #5
    bhi .Lus_08033BD8
    lsls	r0, r0, #2
    ldr r1, .Lus_08033BBC
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_08033BBC:
    .4byte .Lus_08033BC0
.Lus_08033BC0:
    .4byte .Lus_08033BD8
    .4byte .Lus_08033C64
    .4byte .Lus_08033C94
    .4byte .Lus_08033DFC
    .4byte .Lus_08034054
    .4byte .Lus_08034078
.Lus_08033BD8:
    ldrb	r0, [r2, #4]
    cmp	r0, #0
    bne .Lus_08033BE0
    b .Lus_08034110
.Lus_08033BE0:
    mov	r0, r8
    bl GetCurrentTask__C13HarvestSprite
    cmp	r0, #3
    bne .Lus_08033BEC
    b .Lus_08034110
.Lus_08033BEC:
    mov	r0, r8
    bl GetWorkDaysLeft__C13HarvestSprite
    cmp	r0, #0
    bne .Lus_08033BF8
    b .Lus_08034110
.Lus_08033BF8:
    mov	r2, sl
    ldr	r0, [r2, #0]
    movs	r3, #162	@ 0xa2
    lsls	r3, r3, #1
    adds	r0, r0, r3
    ldr	r1, [r0, #0]
    mov	r0, sl
    bl _call_via_r1
    adds	r2, r0, #0
    ldrb	r1, [r2, #10]
    movs	r0, #31
    ands	r0, r1
    cmp	r0, #6
    beq .Lus_08033C18
    b .Lus_08034110
.Lus_08033C18:
    ldrh	r0, [r2, #10]
    lsls	r0, r0, #21
    lsrs	r0, r0, #26
    adds	r1, r7, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    adds	r1, #1
    cmp	r0, r1
    beq .Lus_08033C2C
    b .Lus_08034110
.Lus_08033C2C:
    ldr	r0, [r2, #0]
    subs	r0, #3
    cmp	r0, #1
    bls .Lus_08033C5C
    movs	r2, #180	@ 0xb4
    lsls	r2, r2, #1
    movs	r3, #8
    negs	r3, r3
    adds	r0, r7, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    add	r1, sp, #72	@ 0x48
    mov	r0, r8
    bl method_0809E7D0__13HarvestSprite
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r7, #0
    movs	r1, #1
    movs	r2, #0
    bl func_08034180
    b .Lus_08034110
.Lus_08033C5C:
    mov	r0, r8
    bl TaskDayUpdate__13HarvestSprite
    b .Lus_08034110
.Lus_08033C64:
    .4byte 0x280288B8
    .4byte 0x22B4D00E
    .4byte 0x23080052
    .4byte 0x1C38425B
    .4byte 0xF7EC2102
    .4byte 0x2380F8FF
    .4byte 0x1C38021B
    .4byte 0x22002101
    .4byte 0xFA7CF000
    .4byte 0x5F38240E
    .4byte 0xDC002877
    .4byte 0xE1E9E23E
.Lus_08033C94:
    .4byte 0x35204645
    .4byte 0x46469525
    .4byte 0x28008C30
    .4byte 0xE0A7D000
    .4byte 0xF0001C38
    .4byte 0x0600FE4B
    .4byte 0xD0002800
    .4byte 0x78E8E22E
    .4byte 0xD0042800
    .4byte 0x70E83801
    .4byte 0x28000600
    .4byte 0x1C38D106
    .4byte 0xFACCF000
    .4byte 0x28000600
    .4byte 0xE21FD000
    .4byte 0x1C284D0F
    .4byte 0xF0772105
    .4byte 0x0084FDA9
    .4byte 0x26001964
    .4byte 0x70889925
    .4byte 0x78A0253C
    .4byte 0xF0774368
    .4byte 0x7861FD4D
    .4byte 0x18094369
    .4byte 0x80119A25
    .4byte 0xA81388BC
    .4byte 0x80468006
    .4byte 0x2C114681
    .4byte 0x2C11D025
    .4byte 0x2C02DC04
    .4byte 0xE02CD005
    .4byte gUnk_080F143C
    .4byte 0xD00F2C25
    .4byte 0x2048E027
    .4byte 0xFD34F077
    .4byte 0x464B3080
    .4byte 0x20488018
    .4byte 0xFD2EF077
    .4byte 0x006D2594
    .4byte 0x464E1940
    .4byte 0xE0188070
    .4byte 0xF0772068
    .4byte 0x3048FD25
    .4byte 0x80084649
    .4byte 0xF0772030
    .4byte 0x3060FD1F
    .4byte 0x8050464A
    .4byte 0x2040E00B
    .4byte 0xFD18F077
    .4byte 0x464B3090
    .4byte 0x20308018
    .4byte 0xFD12F077
    .4byte 0x464D3070
    .4byte 0x1C388068
    .4byte 0x78003020
    .4byte 0x46564680
    .4byte 0xA8026831
    .4byte 0x46516B4B
    .4byte 0xF09F1C22
    .4byte 0x6979FDCB
    .4byte 0x68CAA814
    .4byte 0xF09F1C39
    .4byte 0x9814FDC3
    .4byte 0x90299915
    .4byte 0xAC05912A
    .4byte 0x468A2120
    .4byte 0x21212500
    .4byte 0x20219105
    .4byte 0x60604240
    .4byte 0x60E160A0
    .4byte 0xA802A90A
    .4byte 0xC14CC84C
    .4byte 0x992A9829
    .4byte 0x910E900D
    .4byte 0x62A14651
    .4byte 0x632562E5
    .4byte 0x5EB8220A
    .4byte 0x5EF9230E
    .4byte 0x2600464D
    .4byte 0xAB135FAA
    .4byte 0x5F5B2502
    .4byte 0x46469400
    .4byte 0xF0779601
    .4byte 0x1C02FF2F
    .4byte 0x78819825
    .4byte 0x021B2380
    .4byte 0xF0001C38
    .4byte 0xE18DF9C7
    .4byte 0x46413801
    .4byte 0xE1898408
.Lus_08033DFC:
    .4byte 0x32204642
    .4byte 0x1C3C9226
    .4byte 0x78203430
    .4byte 0x00C06BB9
    .4byte 0x46891809
    .4byte 0x46486BF9
    .4byte 0xF7FF4652
    .4byte 0x1C06FCB5
    .4byte 0x200A88BD
    .4byte 0x93275E3B
    .4byte 0x5EB9220E
    .4byte 0xA8169128
    .4byte 0x80418003
    .4byte 0xD10842AE
    .4byte 0xA8176BFA
    .4byte 0x46534649
    .4byte 0xFCF8F7FF
    .4byte 0x90169817
    .4byte 0x2D11E027
    .4byte 0x2D11D01D
    .4byte 0x2D02DC02
    .4byte 0xE01ED003
    .4byte 0xD0102D25
    .4byte 0x2E11E01B
    .4byte 0x2E25D007
    .4byte 0xA818D117
    .4byte 0xFE3AF7D5
    .4byte 0x90169818
    .4byte 0xA819E013
    .4byte 0xFE3AF7D5
    .4byte 0x90169819
    .4byte 0xA81AE00D
    .4byte 0xFFECF7D8
    .4byte 0x9016981A
    .4byte 0xA81BE007
    .4byte 0xFB64F7D8
    .4byte 0x9016981B
    .4byte 0x268DE001
    .4byte 0x208D00B6
    .4byte 0x42860080
    .4byte 0xAB16D077
    .4byte 0x5E982200
    .4byte 0x1A409927
    .4byte 0xDA002800
    .4byte 0x28074240
    .4byte 0x235ADC6D
    .4byte 0x2200446B
    .4byte 0x99285E98
    .4byte 0x28001A40
    .4byte 0x4240DA00
    .4byte 0xDC622807
    .4byte 0xF0001C38
    .4byte 0x0600FD39
    .4byte 0x29000E01
    .4byte 0xE11BD000
    .4byte 0xD11942AE
    .4byte 0xF0001C38
    .4byte 0x0600FA45
    .4byte 0xD1002800
    .4byte 0x4908E0BE
    .4byte 0x4008981C
    .4byte 0x4308213C
    .4byte 0xA91C901C
    .4byte 0xF06A4640
    .4byte 0x1C38FC79
    .4byte 0x78023020
    .4byte 0x21041C38
    .4byte 0x0000E0E3
    .4byte 0xFFFF0000
    .4byte 0xA81D2402
    .4byte 0x80418001
    .4byte 0x2D114680
    .4byte 0x2D11D01C
    .4byte 0x2D02DC02
    .4byte 0xE01CD003
    .4byte 0xD0102D25
    .4byte 0x2E11E019
    .4byte 0x2E25D007
    .4byte 0x2425D115
    .4byte 0xF7D8A81E
    .4byte 0x981EFF8D
    .4byte 0x2411E00E
    .4byte 0xF7D8A81F
    .4byte 0x981FFB05
    .4byte 0xA820E008
    .4byte 0xFDC4F7D5
    .4byte 0xE0039820
    .4byte 0xF7D5A821
    .4byte 0x9821FDC5
    .4byte 0x4643901D
    .4byte 0x5F5A2500
    .4byte 0x2602A81D
    .4byte 0x1C385F83
    .4byte 0xF7EB1C21
    .4byte 0x1C38FF81
    .4byte 0x78023020
    .4byte 0x21001C38
    .4byte 0xF0002300
    .4byte 0x2000F8FD
    .4byte 0x80089926
    .4byte 0x9A26E0C0
    .4byte 0x28008810
    .4byte 0x1C38D15A
    .4byte 0xFCD2F000
    .4byte 0x28000600
    .4byte 0xE0B5D000
    .4byte 0x6BB87821
    .4byte 0x184000C9
    .4byte 0x46526BF9
    .4byte 0xFAE8F7FF
    .4byte 0x28000600
    .4byte 0x4640D056
    .4byte 0xFB4EF06A
    .4byte 0x46401C01
    .4byte 0xFB52F06A
    .4byte 0xFCA4F7FF
    .4byte 0xAC161C06
    .4byte 0x5EE12300
    .4byte 0x22021C25
    .4byte 0x9B285EA8
    .4byte 0x9C271AC0
    .4byte 0x29001B09
    .4byte 0x4249DA00
    .4byte 0xDA002800
    .4byte 0x18084240
    .4byte 0x18400FC1
    .4byte 0x04001040
    .4byte 0xF09C1C31
    .4byte 0xAB23FF65
    .4byte 0x22B46018
    .4byte 0x6002A822
    .4byte 0x428A6819
    .4byte 0x1C18D900
    .4byte 0xF0776800
    .4byte 0x9926FBB9
    .4byte 0x1C388008
    .4byte 0x78043020
    .4byte 0xF077A802
    .4byte 0xA816FD0B
    .4byte 0x5EC22300
    .4byte 0x5E6B2102
    .4byte 0x9500AD02
    .4byte 0x98279401
    .4byte 0xF0779928
    .4byte 0x1C02FE01
    .4byte 0x21011C38
    .4byte 0xF0001C33
    .4byte 0xE061F89B
    .4byte 0x9E263801
    .4byte 0xE05D8030
.Lus_08034054:
    .4byte 0x8C084641
    .4byte 0xD1092800
    .4byte 0xF0001C38
    .4byte 0x0600FC6F
    .4byte 0xD1532800
    .4byte 0xF0001C38
    .4byte 0xE04FF935
    .4byte 0x46423801
    .4byte 0xE04B8410
.Lus_08034078:
    .4byte 0x5EF9230A
    .4byte 0x004020B4
    .4byte 0xD12A4281
    .4byte 0x280069F8
    .4byte 0x2380DB07
    .4byte 0x1C38021B
    .4byte 0x22012101
    .4byte 0xF874F000
    .4byte 0x240EE03A
    .4byte 0x20085F39
    .4byte 0x42814240
    .4byte 0x4640DC34
    .4byte 0xFB58F06A
    .4byte 0x4640A924
    .4byte 0xFB8AF06A
    .4byte 0x30301C38
    .4byte 0xA8027801
    .4byte 0xFBA2F06A
    .4byte 0xA9021C38
    .4byte 0xF82AF7FE
    .4byte 0x30201C38
    .4byte 0x1C387802
    .4byte 0x23002100
    .4byte 0xF854F000
    .4byte 0x69BAE01A
    .4byte 0x48052300
    .4byte 0xDC004281
    .4byte 0x1C182301
    .4byte 0xD0052800
    .4byte 0xDD052A00
    .4byte 0x0000E00E
    .4byte 0x00000167
    .4byte 0xDB092A00
    .4byte 0x28002202
    .4byte 0x2203D000
    .4byte 0x021B2380
    .4byte 0x21011C38
    .4byte 0xF838F000
.Lus_08034110:
    adds	r4, r7, #0
    adds	r4, #66	@ 0x42
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    beq .Lus_08034138
    adds	r0, r7, #0
    adds	r0, #64	@ 0x40
    ldrb	r1, [r0, #0]
    adds	r0, r7, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r7, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_08034134
    adds	r0, r7, #0
    bl SetAnim__12AActorEntityUi
.Lus_08034134:
    movs	r0, #0
    strb	r0, [r4, #0]
.Lus_08034138:
    ldr	r1, [r7, #28]
    cmp	r1, #0
    beq .Lus_08034144
    ldr	r0, [r7, #12]
    adds	r0, r0, r1
    str	r0, [r7, #12]
.Lus_08034144:
    ldr	r1, [r7, #24]
    cmp	r1, #0
    beq .Lus_08034150
    ldr	r0, [r7, #8]
    adds	r0, r0, r1
    str	r0, [r7, #8]
.Lus_08034150:
    ldrh	r0, [r7, #36]	@ 0x24
    cmp	r0, #0
    beq .Lus_0803415A
    subs	r0, #1
    b .Lus_0803415C
.Lus_0803415A:
    ldrh	r0, [r7, #38]	@ 0x26
.Lus_0803415C:
    strh	r0, [r7, #36]	@ 0x24
    ldr	r4, [r7, #16]
    cmp	r4, #0
    beq .Lus_0803416E
    ldr	r0, [r4, #4]
    ldr	r1, [r0, #12]
    adds	r0, r4, #0
    bl _call_via_r1
.Lus_0803416E:
    add	sp, #172	@ 0xac
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034180
    .thumb_func
func_08034180:
    push	{r4, r5, r6, r7, lr}
    adds	r4, r0, #0
    adds	r7, r1, #0
    adds	r5, r2, #0
    adds	r6, r3, #0
    bl func_08034248
    adds	r1, r0, #0
    ldrh	r0, [r4, #34]	@ 0x22
    cmp	r0, r1
    beq .Lus_0803419C
    adds	r0, r4, #0
    bl SetAnim__12AActorEntityUi
.Lus_0803419C:
    adds	r0, r4, #0
    adds	r0, #32
    ldrb	r0, [r0, #0]
    cmp	r0, r5
    beq .Lus_080341AE
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl SetAnimFacing__12AActorEntityUi
.Lus_080341AE:
    adds	r0, r4, #0
    adds	r0, #66	@ 0x42
    movs	r1, #0
    strb	r1, [r0, #0]
    cmp	r7, #1
    beq .Lus_080341D0
    cmp	r7, #1
    bgt .Lus_080341C4
    cmp	r7, #0
    beq .Lus_080341C8
    b .Lus_0803420A
.Lus_080341C4:
    cmp	r7, #4
    bgt .Lus_0803420A
.Lus_080341C8:
    movs	r0, #0
    str	r0, [r4, #24]
    str	r0, [r4, #28]
    b .Lus_0803420A
.Lus_080341D0:
    adds	r0, r6, #0
    cmp	r6, #0
    bge .Lus_080341D8
    negs	r0, r6
.Lus_080341D8:
    adds	r6, r0, #0
    cmp	r5, #1
    beq .Lus_080341F8
    cmp	r5, #1
    bgt .Lus_080341E8
    cmp	r5, #0
    beq .Lus_080341F2
    b .Lus_0803420A
.Lus_080341E8:
    cmp	r5, #2
    beq .Lus_08034200
    cmp	r5, #3
    beq .Lus_08034206
    b .Lus_0803420A
.Lus_080341F2:
    str	r6, [r4, #28]
    str	r1, [r4, #24]
    b .Lus_0803420A
.Lus_080341F8:
    negs	r0, r6
    str	r0, [r4, #28]
    str	r1, [r4, #24]
    b .Lus_0803420A
.Lus_08034200:
    negs	r0, r6
    str	r0, [r4, #24]
    b .Lus_08034208
.Lus_08034206:
    str	r6, [r4, #24]
.Lus_08034208:
    str	r1, [r4, #28]
.Lus_0803420A:
    adds	r0, r4, #0
    adds	r0, #64	@ 0x40
    adds	r5, r0, #0
    ldrb	r0, [r5, #0]
    cmp	r7, r0
    beq .Lus_0803423E
    movs	r1, #1
    negs	r1, r1
    cmp	r7, #2
    beq .Lus_08034224
    cmp	r7, #3
    beq .Lus_08034228
    b .Lus_0803422A
.Lus_08034224:
    movs	r1, #8
    b .Lus_0803422E
.Lus_08034228:
    movs	r1, #5
.Lus_0803422A:
    cmp	r1, #0
    blt .Lus_08034238
.Lus_0803422E:
    adds	r0, r4, #0
    movs	r2, #1
    bl func_08032384
    b .Lus_0803423E
.Lus_08034238:
    adds	r0, r4, #0
    bl func_080323C8
.Lus_0803423E:
    strb	r7, [r5, #0]
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_animation_lookup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034260
    .thumb_func
func_08034260:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #28
    adds	r6, r0, #0
    adds	r7, r6, #0
    adds	r7, #65	@ 0x41
    ldrb	r0, [r7, #0]
    cmp	r0, #0
    beq .Lus_08034274
    movs	r0, #0
    b .Lus_080342CA
.Lus_08034274:
    ldr	r5, [r6, #0]
    add	r4, sp, #16
    adds	r0, r4, #0
    adds	r1, r6, #0
    bl GetLocation__C7AEntity
    ldr	r0, [r6, #52]	@ 0x34
    bl GetCurrentTask__C13HarvestSprite
    ldr	r1, [r6, #60]	@ 0x3c
    str	r0, [sp, #0]
    ldr	r0, [r6, #56]	@ 0x38
    str	r0, [sp, #4]
    add	r0, sp, #8
    adds	r2, r5, #0
    adds	r3, r4, #0
    bl func_080330F4
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Lus_080342AA
    movs	r0, #1
    strb	r0, [r7, #0]
    movs	r0, #0
    b .Lus_080342CA
.Lus_080342AA:
    ldr	r0, [r6, #56]	@ 0x38
    adds	r1, r6, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    add	r2, sp, #8
    bl func_0809E988
    ldr r1, .Lus_080342D4
    ldr	r0, [sp, #24]
    ands	r0, r1
    str	r0, [sp, #24]
    ldr	r0, [r6, #52]	@ 0x34
    add	r1, sp, #24
    bl method_0809E7E4__13HarvestSpritePC15UnkBarnAnimal2C
    movs	r0, #1
.Lus_080342CA:
    add	sp, #28
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_080342D4:
    .4byte 0xFFFF0000
    .global func_080342D8
    .thumb_func
func_080342D8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr	r0, [r5, #52]	@ 0x34
    bl GetFriendship__C3Npc
    bl func_080338F0
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_080342FA
    adds	r0, r5, #0
    bl func_08034260
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_08034356
.Lus_080342FA:
    movs	r0, #180	@ 0xb4
    bl func_080AB788
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    ldr r2, .Lus_08034360
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    ldr r0, .Lus_08034364
    ands	r1, r0
    str	r1, [sp, #0]
    ldr	r4, [r5, #52]	@ 0x34
    adds	r0, r4, #0
    bl GetCurrentTask__C13HarvestSprite
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    adds	r1, r0, #0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    subs	r0, r0, r1
    bl func_080AB788
    lsrs	r0, r0, #6
    adds	r0, #2
    lsls	r0, r0, #24
    ldr r2, .Lus_08034368
    ldr	r1, [sp, #0]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #0]
    ldr	r0, [r5, #52]	@ 0x34
    mov	r1, sp
    bl method_0809E7D8__13HarvestSpritePC15UnkBarnAnimal2C
    adds	r0, r5, #0
    adds	r0, #32
    ldrb	r2, [r0, #0]
    adds	r0, r5, #0
    movs	r1, #0
    movs	r3, #0
    bl func_08034180
.Lus_08034356:
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.Lus_08034360:
    .4byte 0xFFFF0000
.Lus_08034364:
    .4byte 0xFF00FFFF
.Lus_08034368:
    .4byte 0x00FFFFFF
    .global func_0803436C
    .thumb_func
func_0803436C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    str	r0, [sp, #36]	@ 0x24
    ldr	r0, [r0, #0]
    str	r0, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    adds	r3, #48	@ 0x30
    ldrb	r1, [r3, #0]
    ldr	r2, [sp, #36]	@ 0x24
    ldr	r0, [r2, #56]	@ 0x38
    lsls	r1, r1, #3
    mov	r2, sp
    adds	r1, r0, r1
    ldmia	r1!, {r4, r5}
    stmia	r2!, {r4, r5}
    ldrb	r1, [r3, #0]
    bl func_0809E994
    ldr	r0, [sp, #36]	@ 0x24
    ldr	r1, [r0, #60]	@ 0x3c
    mov	r0, sp
    ldr	r2, [sp, #40]	@ 0x28
    bl func_08033584
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_080343AC
    b .Lus_080348FA
.Lus_080343AC:
    ldr	r1, [sp, #36]	@ 0x24
    ldr	r5, [r1, #16]
    cmp	r5, #0
    beq .Lus_0803441A
    ldr	r2, [r1, #60]	@ 0x3c
    add	r4, sp, #24
    adds	r0, r4, #0
    mov	r1, sp
    ldr	r3, [sp, #40]	@ 0x28
    bl func_08033830
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    beq .Lus_080343E4
    cmp	r0, #4
    bgt .Lus_080343D8
    cmp	r0, #3
    beq .Lus_080343DE
    b .Lus_08034404
.Lus_080343D8:
    cmp	r0, #5
    beq .Lus_080343FE
    b .Lus_08034404
.Lus_080343DE:
    ldrh	r0, [r4, #2]
    subs	r0, #24
    b .Lus_08034402
.Lus_080343E4:
    movs	r0, #2
    ldrsh	r2, [r4, r0]
    mov	r0, sp
    ldrb	r0, [r0, #1]
    movs	r1, #7
    ands	r0, r1
    adds	r1, r2, #0
    adds	r1, #24
    cmp	r0, #3
    bhi .Lus_080343FA
    subs	r1, #56	@ 0x38
.Lus_080343FA:
    strh	r1, [r4, #2]
    b .Lus_08034404
.Lus_080343FE:
    ldrh	r0, [r4, #2]
    subs	r0, #40	@ 0x28
.Lus_08034402:
    strh	r0, [r4, #2]
.Lus_08034404:
    ldr	r0, [sp, #36]	@ 0x24
    adds	r0, #48	@ 0x30
    ldrb	r1, [r0, #0]
    movs	r0, #0
    ldrsh	r2, [r4, r0]
    add	r0, sp, #24
    movs	r4, #2
    ldrsh	r3, [r0, r4]
    adds	r0, r5, #0
    bl func_08034BFC
.Lus_0803441A:
    mov	r0, sp
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #8
    bls .Lus_08034428
    b .Lus_080348FA
.Lus_08034428:
    lsls	r0, r0, #2
    ldr r1, .Lus_08034434
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Lus_08034434:
    .4byte .Lus_08034438
.Lus_08034438:
    .4byte .Lus_080348FA
    .4byte .Lus_0803445C
    .4byte .Lus_080344E4
    .4byte .Lus_080345EA
    .4byte .Lus_08034616
    .4byte .Lus_08034644
    .4byte .Lus_08034680
    .4byte .Lus_080347EC
    .4byte .Lus_08034834
.Lus_0803445C:
    .4byte 0x682D9D0A
    .4byte 0x20D846A9
    .4byte 0x99094481
    .4byte 0x5E8E220A
    .4byte 0x5F4C250E
    .4byte 0xAC0246A0
    .4byte 0x88212202
    .4byte 0x1C184B19
    .4byte 0x43104008
    .4byte 0x04368020
    .4byte 0x203F0C31
    .4byte 0x40014682
    .4byte 0x78650089
    .4byte 0x1C102203
    .4byte 0x43084028
    .4byte 0x0DB67060
    .4byte 0x1C188861
    .4byte 0x43304008
    .4byte 0x46418060
    .4byte 0x46880409
    .4byte 0x46550C08
    .4byte 0x00804028
    .4byte 0x400A78E1
    .4byte 0x70E24302
    .4byte 0x0D804640
    .4byte 0x88A04680
    .4byte 0x46414003
    .4byte 0x80A3430B
    .4byte 0x682A464D
    .4byte 0x1C21980A
    .4byte 0xFA1EF09F
    .4byte 0x46A02601
    .4byte 0x0000E20F
    .4byte 0xFFFFFC00
.Lus_080344E4:
    .4byte 0x4681A802
    .4byte 0xFD80F7DA
    .4byte 0x6809990A
    .4byte 0x22E04688
    .4byte 0x9C094490
    .4byte 0x5E25200A
    .4byte 0x5E66210E
    .4byte 0x2202AF04
    .4byte 0x4B1E8839
    .4byte 0x40081C18
    .4byte 0x80384310
    .4byte 0x0C29042D
    .4byte 0x4692223F
    .4byte 0x00894011
    .4byte 0x2203787C
    .4byte 0x40201C10
    .4byte 0x70784308
    .4byte 0x88790DAD
    .4byte 0x40081C18
    .4byte 0x80784328
    .4byte 0x0C300436
    .4byte 0x40204654
    .4byte 0x78F90080
    .4byte 0x4302400A
    .4byte 0x0DB670FA
    .4byte 0x400388B8
    .4byte 0x80BB4333
    .4byte 0x682B4645
    .4byte 0x1C39980A
    .4byte 0xF09F464A
    .4byte 0x4648F9DD
    .4byte 0xFD84F7DA
    .4byte 0x46C80600
    .4byte 0xD0002800
    .4byte 0x4640E1C5
    .4byte 0xFD94F7DA
    .4byte 0xD0052800
    .4byte 0xD0212801
    .4byte 0x0000E1BD
    .4byte 0xFFFFFC00
    .4byte 0x6804980A
    .4byte 0x004921AE
    .4byte 0xAD071864
    .4byte 0x46411C38
    .4byte 0xFD86F7DA
    .4byte 0x46687839
    .4byte 0x78003011
    .4byte 0x43080200
    .4byte 0x31124669
    .4byte 0x04097809
    .4byte 0x1C284301
    .4byte 0xFDA4F7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0xE012F9AB
    .4byte 0x68149A0A
    .4byte 0x006D25AE
    .4byte 0x466D1964
    .4byte 0x4640351D
    .4byte 0xFD8AF7DA
    .4byte 0x1C281C01
    .4byte 0xFDB6F7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C29
    .4byte 0x2600F997
    .hword 0xE189
.Lus_080345EA:
    .hword 0x9909
    .4byte 0x24FF6BC8
    .4byte 0x190000A4
    .4byte 0xF7D82101
    .4byte 0x9A09F8EF
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xF906F7D8
    .4byte 0x68209C0A
    .4byte 0x466930A0
    .4byte 0x68027849
    .hword 0xE02B
.Lus_08034616:
    .hword 0x9909
    .4byte 0x4C096BC8
    .4byte 0x21011900
    .4byte 0xFE2EF7D8
    .4byte 0x6BD09A09
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9C0AFE45
    .4byte 0x309C6820
    .4byte 0x78494669
    .4byte 0xE0166802
    .4byte 0x000005DC
.Lus_08034644:
    .4byte 0x6BC89909
    .4byte 0x19004C0C
    .4byte 0xF7D82101
    .4byte 0x9A09FE17
    .4byte 0x19006BD0
    .4byte 0x78494669
    .4byte 0xFE6AF7D8
    .4byte 0x68229C0A
    .4byte 0x4668329C
    .4byte 0x31107841
    .4byte 0x1C206812
    .4byte 0xF950F09F
    .4byte 0xAD022602
    .4byte 0xE14046A8
    .4byte 0x000005DC
.Lus_08034680:
    .4byte 0x78414668
    .4byte 0x9A0A3136
    .4byte 0x6C026810
    .4byte 0xF09F980A
    .4byte 0x1C07F941
    .4byte 0xD1002F00
    .4byte 0x6978E12F
    .4byte 0x1C386D01
    .4byte 0xF936F09F
    .4byte 0x28000600
    .4byte 0x6978D004
    .4byte 0x1C386F01
    .4byte 0xF92EF09F
    .4byte 0x6D416978
    .4byte 0xF09F1C38
    .4byte 0x0600F929
    .4byte 0x46A0AC02
    .4byte 0xD0452800
    .4byte 0x6F416978
    .4byte 0xF09F1C38
    .4byte 0x211CF91F
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Lus_080346E8
.Lus_080346E8:
    .4byte .Lus_08034700
    .4byte .Lus_08034704
    .4byte .Lus_08034708
    .4byte .Lus_0803470C
    .4byte .Lus_08034710
    .4byte .Lus_08034714
.Lus_08034700:
    .4byte 0xE008211C
.Lus_08034704:
    .4byte 0xE006211D
.Lus_08034708:
    .4byte 0xE004211E
.Lus_0803470C:
    .4byte 0xE002211F
.Lus_08034710:
    .4byte 0xE0002120
.Lus_08034714:
    .4byte 0x9D0A2121
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x361E466E
    .4byte 0x1C28AD02
    .4byte 0xFABEF7D9
    .4byte 0x46687829
    .4byte 0x78003009
    .4byte 0x43080200
    .4byte 0x310A4669
    .4byte 0x04097809
    .4byte 0x1C304301
    .4byte 0xFCDAF7D9
    .4byte 0x980A6822
    .4byte 0xF09F1C31
    .4byte 0x46A8F8E1
    .4byte 0x6D816978
    .4byte 0xF09F1C38
    .4byte 0x0600F8D9
    .4byte 0xD03A2800
    .4byte 0x6F816978
    .4byte 0xF09F1C38
    .4byte 0x2105F8D1
    .4byte 0xD81E2805
    .4byte 0x49020080
    .4byte 0x68001840
    .4byte 0x00004687
    .4byte .Lus_08034784
.Lus_08034784:
    .4byte .Lus_0803479C
    .4byte .Lus_080347A0
    .4byte .Lus_080347A4
    .4byte .Lus_080347A8
    .4byte .Lus_080347AC
    .4byte .Lus_080347B0
.Lus_0803479C:
    .4byte 0xE0082105
.Lus_080347A0:
    .4byte 0xE0062106
.Lus_080347A4:
    .4byte 0xE0042107
.Lus_080347A8:
    .4byte 0xE0022108
.Lus_080347AC:
    .4byte 0xE0002109
.Lus_080347B0:
    .4byte 0x9A0A210A
    .4byte 0x24AE6815
    .4byte 0x192D0064
    .4byte 0x361F466E
    .4byte 0x1C20AC08
    .4byte 0xFBC4F7D9
    .4byte 0x1C307821
    .4byte 0xFCBCF7D9
    .4byte 0x980A682A
    .4byte 0xF09F1C31
    .4byte 0x6978F89D
    .4byte 0x68023088
    .4byte 0x213C1C38
    .4byte 0xF896F09F
    .4byte 0xE0882602
.Lus_080347EC:
    .4byte 0x78414668
    .4byte 0x9D0A312E
    .4byte 0x6C026828
    .4byte 0xF09F1C28
    .4byte 0x1C04F88B
    .4byte 0xD07A2C00
    .4byte 0x6D016960
    .4byte 0xF09F1C20
    .4byte 0x0600F881
    .4byte 0xD0042800
    .4byte 0x6F016960
    .4byte 0xF09F1C20
    .4byte 0x6960F879
    .4byte 0x68023088
    .4byte 0x213C1C20
    .4byte 0xF874F09F
    .4byte 0xA8022602
    .4byte 0xE0644680
.Lus_08034834:
    .4byte 0x78414668
    .4byte 0x344C1C0C
    .4byte 0x6BD09A09
    .4byte 0x00AD25FF
    .4byte 0xF7D71940
    .4byte 0x2800FF2B
    .4byte 0x7980D055
    .4byte 0x0F400740
    .4byte 0x2805270F
    .4byte 0x0080D81D
    .4byte 0x18404901
    .4byte 0x46876800
    .4byte .Lus_08034868
.Lus_08034868:
    .4byte .Lus_08034880
    .4byte .Lus_08034884
    .4byte .Lus_08034888
    .4byte .Lus_0803488C
    .4byte .Lus_08034890
    .4byte .Lus_08034894
.Lus_08034880:
    .4byte 0xE008270F
.Lus_08034884:
    .4byte 0xE0062710
.Lus_08034888:
    .4byte 0xE0042711
.Lus_0803488C:
    .4byte 0xE0022712
.Lus_08034890:
    .4byte 0xE0002713
.Lus_08034894:
    .4byte 0x99092714
    .4byte 0x68016808
    .4byte 0x1C216BCA
    .4byte 0xF838F09F
    .4byte 0x6BD09A09
    .4byte 0x00A424FF
    .4byte 0x46691900
    .4byte 0xF7D87849
    .4byte 0x9D0AF881
    .4byte 0x20AE682C
    .4byte 0x18240040
    .4byte 0x3621466E
    .4byte 0x1C28AD02
    .4byte 0xF7D91C39
    .4byte 0x7829F9ED
    .4byte 0x30094668
    .4byte 0x02007800
    .4byte 0x46694308
    .4byte 0x7809310A
    .4byte 0x43010409
    .4byte 0xF7D91C30
    .4byte 0x6822FC09
    .4byte 0x1C31980A
    .4byte 0xF810F09F
    .4byte 0x46A82602
    .hword 0xE001
.Lus_080348FA:
    movs	r0, #0
    b .Lus_0803492A
    .hword 0x490F
    .4byte 0x22034640
    .4byte 0xF846F09F
    .4byte 0xD00D2E03
    .4byte 0xF07620C8
    .4byte 0x4642FF3B
    .4byte 0x78091991
    .4byte 0xD2054288
    .4byte 0x6B609C09
    .4byte 0x22011C31
    .4byte 0xFEBAF069
    .hword 0x2001
.Lus_0803492A:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .hword 0x0000
    .4byte gUnk_080F1496
    .global func_08034940
    .thumb_func
func_08034940:
    push	{r4, r5, lr}
    sub	sp, #12
    adds	r5, r0, #0
    ldr	r0, [r5, #0]
    ldr	r1, [r0, #0]
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r1, r1, r2
    ldr	r1, [r1, #0]
    bl _call_via_r1
    ldrh	r2, [r0, #10]
    lsls	r0, r2, #27
    lsrs	r0, r0, #27
    cmp	r0, #5
    bls .Lus_0803497C
    subs	r0, #6
    lsls	r1, r0, #4
    subs	r1, r1, r0
    lsls	r1, r1, #2
    lsls	r0, r2, #21
    lsrs	r0, r0, #26
    adds	r1, r1, r0
    adds	r0, r5, #0
    adds	r0, #48	@ 0x30
    ldrb	r0, [r0, #0]
    ldr r2, .Lus_080349A8
    adds	r0, r0, r2
    cmp	r1, r0
    bcc .Lus_08034A08
.Lus_0803497C:
    ldrh	r0, [r5, #4]
    cmp	r0, #17
    beq .Lus_080349AC
    cmp	r0, #17
    ble .Lus_080349C4
    cmp	r0, #37	@ 0x25
    bne .Lus_080349C4
    mov	r4, sp
    mov	r0, sp
    bl smethod_08009ADC__4Farm
    mov	r0, sp
    movs	r1, #0
    ldrsh	r2, [r0, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
    b .Lus_080349C4
    .align 2, 0
.Lus_080349A8:
    .4byte 0x00000385
.Lus_080349AC:
    add	r4, sp, #4
    adds	r0, r4, #0
    bl smethod_08009AE8__4Farm
    movs	r1, #0
    ldrsh	r2, [r4, r1]
    movs	r0, #2
    ldrsh	r3, [r4, r0]
    adds	r0, r5, #0
    movs	r1, #2
    bl SetLocation__7AEntityUiii
.Lus_080349C4:
    ldr	r0, [r5, #56]	@ 0x38
    adds	r1, r5, #0
    adds	r1, #48	@ 0x30
    ldrb	r1, [r1, #0]
    bl func_0809E994
    ldr	r0, [r5, #52]	@ 0x34
    add	r1, sp, #8
    bl method_0809E7FC__13HarvestSprite
    movs	r2, #10
    ldrsh	r1, [r5, r2]
    movs	r0, #180	@ 0xb4
    lsls	r0, r0, #1
    cmp	r1, r0
    bne .Lus_080349E8
    movs	r2, #1
    b .Lus_080349F2
.Lus_080349E8:
    ldr r0, .Lus_08034A04
    movs	r2, #2
    cmp	r1, r0
    bgt .Lus_080349F2
    movs	r2, #3
.Lus_080349F2:
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #8
    adds	r0, r5, #0
    movs	r1, #1
    bl func_08034180
    movs	r0, #1
    b .Lus_08034A0A
    .align 2, 0
.Lus_08034A04:
    .4byte 0x00000167
.Lus_08034A08:
    movs	r0, #0
.Lus_08034A0A:
    add	sp, #12
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_08034A14
    .thumb_func
func_08034A14:
    push	{r4, r5, r6, lr}
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6}
    sub	sp, #16
    mov	r8, r0
    adds	r4, r1, #0
    ldr r0, .Lus_08034A94
    mov	r9, r0
    adds	r5, r4, #0
    adds	r5, #48	@ 0x30
    ldrb	r0, [r5, #0]
    lsls	r0, r0, #2
    add	r0, r9
    ldr	r3, [r0, #0]
    movs	r6, #0
    str	r6, [sp, #0]
    movs	r0, #4
    str	r0, [sp, #4]
    str	r6, [sp, #8]
    add	r0, sp, #12
    strb	r6, [r0, #0]
    mov	r0, r8
    movs	r2, #3
    bl func_080324BC
    ldr r0, .Lus_08034A98
    mov	r1, r8
    str	r0, [r1, #4]
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r1, [r1, #104]	@ 0x68
    bl _call_via_r1
    adds	r1, r0, #0
    ldr r2, .Lus_08034A9C
    ldrb	r5, [r5, #0]
    lsls	r0, r5, #1
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    ldr	r3, [r4, #0]
    lsls	r5, r5, #2
    add	r5, r9
    mov	r0, r8
    adds	r0, #140	@ 0x8c
    movs	r4, #2
    str	r4, [sp, #0]
    ldr	r4, [r5, #0]
    str	r4, [sp, #4]
    add	r4, sp, #8
    strb	r6, [r4, #0]
    bl func_080A4A00
    mov	r0, r8
    adds	r0, #208	@ 0xd0
    strh	r6, [r0, #0]
    mov	r0, r8
    add	sp, #16
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
.Lus_08034A94:
    .4byte gUnk_080F14B8
.Lus_08034A98:
    .4byte vtable_unk_080E6904
.Lus_08034A9C:
    .4byte gUnk_080F14F0
    .global func_08034AA0
    .thumb_func
func_08034AA0:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0803260C
    adds	r0, r4, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08034AE0
    adds	r1, r4, #0
    adds	r1, #203	@ 0xcb
    ldrb	r0, [r1, #0]
    cmp	r0, #0
    bne .Lus_08034AD2
    adds	r0, r4, #0
    adds	r0, #180	@ 0xb4
    bl func_0805E8F0
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Lus_08034AD6
    adds	r1, r4, #0
    adds	r1, #200	@ 0xc8
    movs	r0, #1
    b .Lus_08034AD4
.Lus_08034AD2:
    movs	r0, #0
.Lus_08034AD4:
    strb	r0, [r1, #0]
.Lus_08034AD6:
    adds	r1, r4, #0
    adds	r1, #208	@ 0xd0
    ldrh	r0, [r1, #0]
    subs	r0, #1
    strh	r0, [r1, #0]
.Lus_08034AE0:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global func_08034AE8
    .thumb_func
func_08034AE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #60	@ 0x3c
    adds	r5, r0, #0
    adds	r4, r1, #0
    bl func_08032690
    adds	r0, r5, #0
    adds	r0, #208	@ 0xd0
    ldrh	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08034BEA
    add	r3, sp, #52	@ 0x34
    ldr	r0, [r4, #0]
    ldr	r1, [r4, #8]
    str	r0, [sp, #52]	@ 0x34
    str	r1, [r3, #4]
    adds	r0, r5, #0
    adds	r0, #204	@ 0xcc
    movs	r2, #0
    ldrsh	r1, [r0, r2]
    adds	r0, #2
    movs	r6, #0
    ldrsh	r2, [r0, r6]
    movs	r6, #12
    ldrsh	r0, [r4, r6]
    subs	r1, r1, r0
    mov	r9, r1
    movs	r1, #14
    ldrsh	r0, [r4, r1]
    subs	r0, r2, r0
    mov	r8, r0
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #8
    subs	r4, r0, r2
    adds	r6, r5, #0
    adds	r6, #140	@ 0x8c
    mov	sl, r3
    adds	r0, r5, #0
    adds	r0, #180	@ 0xb4
    ldr	r1, [r0, #0]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #12]
    adds	r0, #4
    lsls	r2, r2, #2
    ldr	r0, [r0, #0]
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #20
    ldr	r3, [r3, #16]
    bl _call_via_r3
    add	r7, sp, #20
    mov	r2, sl
    ldr	r3, [r2, #4]
    ldr	r2, [r6, #0]
    adds	r0, r5, #0
    adds	r0, #144	@ 0x90
    ldr	r1, [r0, #4]
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_08034B94
    ldrh	r0, [r6, #12]
    adds	r1, r5, #0
    adds	r1, #156	@ 0x9c
    str	r4, [sp, #0]
    adds	r4, r7, #0
    str	r4, [sp, #4]
    str	r2, [sp, #8]
    str	r0, [sp, #12]
    str	r1, [sp, #16]
    adds	r0, r3, #0
    mov	r1, r9
    mov	r2, r8
    movs	r3, #85	@ 0x55
    ldr r4, .Lus_08034B90
    bl _call_via_r4
    b .Lus_08034B96
    .align 2, 0
.Lus_08034B90:
    .4byte func_030004DC
.Lus_08034B94:
    movs	r0, #0
.Lus_08034B96:
    cmp	r0, #0
    beq .Lus_08034BEA
    adds	r0, r6, #0
    adds	r0, #60	@ 0x3c
    ldrb	r1, [r0, #0]
    adds	r5, r0, #0
    cmp	r1, #0
    beq .Lus_08034BEA
    mov	r0, sl
    ldr	r1, [r0, #0]
    adds	r2, r7, #0
    adds	r2, #8
    adds	r0, r6, #0
    bl func_080A480C
    adds	r0, r6, #0
    adds	r0, #61	@ 0x3d
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Lus_08034BCC
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    b .Lus_08034BE6
.Lus_08034BCC:
    adds	r4, r6, #0
    adds	r4, #62	@ 0x3e
    ldrb	r0, [r4, #0]
    cmp	r0, #0
    bne .Lus_08034BE6
    adds	r1, r7, #0
    adds	r1, #16
    adds	r0, r6, #0
    movs	r2, #1
    bl func_080A4944
    movs	r0, #1
    strb	r0, [r4, #0]
.Lus_08034BE6:
    movs	r0, #0
    strb	r0, [r5, #0]
.Lus_08034BEA:
    add	sp, #60	@ 0x3c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    @ US/EU/DE entity UI code, actual Thumb instructions and relocations.
    .section .text.entity_ui_resource_setup_after
    .syntax unified
    .thumb
    .align 2, 0

    .global func_08034C64
    .thumb_func
func_08034C64:
    push	{r4, r5, r6, lr}
    sub	sp, #8
    adds	r6, r1, #0
    ldr r4, .Lus_08034CDC
    ldr	r1, [r4, #0]
    bl _call_via_r1
    ldr	r1, [r4, #8]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r5, [r0, #0]
    cmp	r5, #0
    beq .Lus_08034CE0
    ldrh	r1, [r6, #0]
    lsls	r0, r1, #27
    lsrs	r0, r0, #27
    subs	r2, r0, #6
    cmp	r2, #0
    bge .Lus_08034C8C
    adds	r2, #24
.Lus_08034C8C:
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #2
    lsls	r1, r1, #21
    lsrs	r1, r1, #26
    adds	r0, r0, r1
    str	r0, [sp, #4]
    ldr	r4, [r5, #4]
    ldrh	r1, [r5, #0]
    lsls	r1, r1, #3
    adds	r1, r4, r1
    movs	r0, #0
    str	r0, [sp, #0]
    adds	r0, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080D7ECC
    subs	r0, r0, r4
    asrs	r0, r0, #3
    subs	r0, #1
    ldrh	r1, [r5, #0]
    cmp	r0, r1
    bcs .Lus_08034CE0
    ldr	r1, [r5, #4]
    lsls	r0, r0, #3
    adds	r0, r0, r1
    ldr	r0, [r0, #4]
    cmp	r0, #0
    beq .Lus_08034CE0
    ldrh	r1, [r0, #10]
    lsls	r1, r1, #22
    lsrs	r1, r1, #22
    movs	r0, #29
    eors	r1, r0
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
    b .Lus_08034CE2
    .align 2, 0
.Lus_08034CDC:
    .4byte gUnk_080F29C0
.Lus_08034CE0:
    movs	r0, #0
.Lus_08034CE2:
    add	sp, #8
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .endif
    .endif
    .endif

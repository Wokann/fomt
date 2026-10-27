    .syntax unified
    .section .text, "ax", %progbits
    .thumb
    .align 2, 0

    .global Lookup__22GameSceneTextVariablesUi
    .thumb_func
Lookup__22GameSceneTextVariablesUi:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #32
    adds	r6, r0, #0
    adds	r5, r1, #0
    ldr r1, .Lscene_text_lookup_1
    adds	r0, r2, r1
    cmp	r0, #12
    bls .Lscene_text_lookup_0
    b .Lscene_text_lookup_37
.Lscene_text_lookup_0:
    lsls	r0, r0, #2
    ldr r1, .Lscene_text_lookup_2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lscene_text_lookup_1:
    .4byte 0xFFFF00DF
.Lscene_text_lookup_2:
    .4byte .Lscene_text_lookup_3
.Lscene_text_lookup_3:
    .4byte .Lscene_text_lookup_4
    .4byte .Lscene_text_lookup_9
    .4byte .Lscene_text_lookup_14
    .4byte .Lscene_text_lookup_23
    .4byte .Lscene_text_lookup_24
    .4byte .Lscene_text_lookup_24
    .4byte .Lscene_text_lookup_24
    .4byte .Lscene_text_lookup_24
    .4byte .Lscene_text_lookup_16
    .4byte .Lscene_text_lookup_18
    .4byte .Lscene_text_lookup_26
    .4byte .Lscene_text_lookup_28
    .4byte .Lscene_text_lookup_30
.Lscene_text_lookup_4:
    ldr	r0, [r5, #4]
    adds	r0, #20
    bl method_08009B20__C4Farm
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lscene_text_lookup_7
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_5
    adds	r0, r0, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lscene_text_lookup_7
    ldr r5, .Lscene_text_lookup_6
    b .Lscene_text_lookup_32
.Lscene_text_lookup_5:
    .4byte 0x000021C8
.Lscene_text_lookup_6:
    .4byte gText_Moneybags
.Lscene_text_lookup_7:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_8
    adds	r0, r0, r1
    bl GetName__C6Farmer
    adds	r5, r0, #0
    b .Lscene_text_lookup_33
    .align 2, 0
.Lscene_text_lookup_8:
    .4byte 0x00001BD8
.Lscene_text_lookup_9:
    ldr	r0, [r5, #4]
    adds	r0, #20
    bl GetHorse__C4Farm
    mov	r7, sp
    cmp	r0, #0
    beq .Lscene_text_lookup_10
    bl GetName__C6Animal
    adds	r5, r0, #0
    b .Lscene_text_lookup_11
.Lscene_text_lookup_10:
    ldr r5, .Lscene_text_lookup_13
.Lscene_text_lookup_11:
    adds	r0, r5, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, #31
    bls .Lscene_text_lookup_12
    movs	r4, #31
.Lscene_text_lookup_12:
    adds	r0, r7, #0
    adds	r1, r5, #0
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    b .Lscene_text_lookup_35
.Lscene_text_lookup_13:
    .4byte gText_EmptyUiLabel
.Lscene_text_lookup_14:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_15
    adds	r0, r0, r1
    bl GetName__C6Animal
    adds	r5, r0, #0
    b .Lscene_text_lookup_33
    .align 2, 0
.Lscene_text_lookup_15:
    .4byte 0x00001C70
.Lscene_text_lookup_16:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_17
    adds	r0, r0, r1
    bl GetSpouseNickname__C6Farmer
    adds	r5, r0, #0
    b .Lscene_text_lookup_33
    .align 2, 0
.Lscene_text_lookup_17:
    .4byte 0x00001BD8
.Lscene_text_lookup_18:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_19
    adds	r0, r0, r1
    bl func_080A0384
    adds	r7, r0, #0
    cmp	r7, #0
    beq .Lscene_text_lookup_20
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_19
    adds	r0, r0, r1
    bl func_080A0384
    bl GetName__5Child
    adds	r5, r0, #0
    b .Lscene_text_lookup_33
    .align 2, 0
.Lscene_text_lookup_19:
    .4byte 0x00001CD4
.Lscene_text_lookup_20:
    ldr r5, .Lscene_text_lookup_22
    adds	r0, r5, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, #31
    bls .Lscene_text_lookup_21
    movs	r4, #31
.Lscene_text_lookup_21:
    mov	r0, sp
    adds	r1, r5, #0
    adds	r2, r4, #0
    bl memcpy
    mov	r1, sp
    adds	r0, r1, r4
    strb	r7, [r0, #0]
    movs	r0, #1
    strb	r0, [r6, #0]
    adds	r0, r6, #4
    bl strcpy
    b .Lscene_text_lookup_38
.Lscene_text_lookup_22:
    .4byte gText_UnnamedSetting
.Lscene_text_lookup_23:
    ldr	r0, [r5, #4]
    adds	r0, #20
    bl GetName__C4Farm
    adds	r5, r0, #0
    b .Lscene_text_lookup_33
.Lscene_text_lookup_24:
    movs	r4, #1
    lsls	r1, r2, #1
    adds	r1, r1, r2
    lsls	r1, r1, #3
    adds	r1, r1, r5
    ldr r0, .Lscene_text_lookup_25
    adds	r1, r1, r0
    mov	r0, sp
    bl strcpy
    strb	r4, [r6, #0]
    b .Lscene_text_lookup_36
.Lscene_text_lookup_25:
    .4byte 0xFFE81490
.Lscene_text_lookup_26:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_27
    b .Lscene_text_lookup_31
    .align 2, 0
.Lscene_text_lookup_27:
    .4byte 0x000021E0
.Lscene_text_lookup_28:
    ldr	r0, [r5, #4]
    ldr r1, .Lscene_text_lookup_29
    b .Lscene_text_lookup_31
    .align 2, 0
.Lscene_text_lookup_29:
    .4byte 0x000021F0
.Lscene_text_lookup_30:
    ldr	r0, [r5, #4]
    movs	r1, #136	@ 0x88
    lsls	r1, r1, #6
.Lscene_text_lookup_31:
    adds	r5, r0, r1
.Lscene_text_lookup_32:
    adds	r0, r5, #0
.Lscene_text_lookup_33:
    bl strlen
    adds	r4, r0, #0
    cmp	r4, #31
    bls .Lscene_text_lookup_34
    movs	r4, #31
.Lscene_text_lookup_34:
    mov	r0, sp
    adds	r1, r5, #0
    adds	r2, r4, #0
    bl memcpy
    mov	r0, sp
    adds	r1, r0, r4
.Lscene_text_lookup_35:
    movs	r0, #0
    strb	r0, [r1, #0]
    movs	r0, #1
    strb	r0, [r6, #0]
.Lscene_text_lookup_36:
    adds	r0, r6, #4
    mov	r1, sp
    bl strcpy
    b .Lscene_text_lookup_38
.Lscene_text_lookup_37:
    mov	r1, sp
    movs	r0, #0
    strb	r0, [r1, #0]
    strb	r0, [r6, #0]
    adds	r0, r6, #4
    bl strcpy
.Lscene_text_lookup_38:
    adds	r0, r6, #0
    add	sp, #32
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0

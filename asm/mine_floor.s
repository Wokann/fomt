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
    bl PlaceSpringMineItems__14MineFloorStateUiiPC21MineFloorExcludedCell
    b .Ljp_0809CB66
.Ljp_0809CB5A:
    adds	r0, r6, #0
    mov	r1, r8
    mov	r2, sl
    mov	r3, sp
    bl PlaceLakeMineItems__14MineFloorStateUiiPC21MineFloorExcludedCell
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
    .section .text.GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .align 2, 0
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
    bl PlaceSpringMineItems__14MineFloorStateUiiPC21MineFloorExcludedCell
    b .L0809D12E
.L0809D122:
    adds r0, r6, #0
    mov r1, r8
    mov r2, sl
    mov r3, sp
    bl PlaceLakeMineItems__14MineFloorStateUiiPC21MineFloorExcludedCell
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

    .section .text.GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .align 2, 0
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

    .endif

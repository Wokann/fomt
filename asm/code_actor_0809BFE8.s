    .ifdef REGION_JP
    @ JP revision 0 counterpart, expressed as real Thumb instructions and relocations.
    @ Actor behavior uses region-specific tables and branch targets.  The JP
    @ object stays byte-exact, with each external entry at its real location.

    .section .text.code_actor_0809C160
    .syntax unified
    .thumb
    .align 2, 0
    .Lcode_actor_0809C160:
    push	{lr}
    adds	r0, r1, #0
    bl GetId__C4Tool
    subs	r0, #5
    cmp	r0, #40	@ 0x28
    bhi .Ljp_0809BC5C
    lsls	r0, r0, #2
    ldr r1, .Ljp_0809BBB0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0809BBB0:
    .4byte .Ljp_0809BBB4
.Ljp_0809BBB4:
    .4byte .Ljp_0809BC58
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC58
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC58
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC58
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC58
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC5C
    .4byte .Ljp_0809BC58
.Ljp_0809BC58:
    movs	r0, #1
    b .Ljp_0809BC5E
.Ljp_0809BC5C:
    movs	r0, #0
.Ljp_0809BC5E:
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.code_actor_0809C318
    .align 2, 0
    .Lcode_actor_0809C318:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0809C22C
    adds	r4, #6
    adds	r4, r4, r0
    ldrb	r0, [r4, #0]
    pop	{r4}
    pop	{r1}
    bx	r1

    .section .text.code_actor_0809C38C
    .align 2, 0
    .Lcode_actor_0809C38C:
    push	{lr}
    adds	r1, r0, #0
    movs	r2, #0
    ldrb	r0, [r1, #7]
    cmp	r0, #0
    beq .Ljp_0809BDEE
    ldrb	r0, [r1, #6]
    cmp	r0, #0
    beq .Ljp_0809BDEE
    ldrb	r0, [r1, #8]
    cmp	r0, #0
    beq .Ljp_0809BDEE
    ldrb	r0, [r1, #9]
    cmp	r0, #0
    beq .Ljp_0809BDEE
    ldrb	r0, [r1, #10]
    cmp	r0, #0
    beq .Ljp_0809BDEE
    ldrb	r0, [r1, #11]
    negs	r0, r0
    lsrs	r2, r0, #31
.Ljp_0809BDEE:
    adds	r0, r2, #0
    pop	{r1}
    bx	r1

    .section .text.code_actor_0809C3BC
    .align 2, 0
    .Lcode_actor_0809C3BC:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0809C22C
    adds	r3, r0, #0
    adds	r1, r4, r3
    ldrb	r2, [r1, #0]
    cmp	r2, #0
    bne .Ljp_0809BE12
    movs	r0, #1
    strb	r0, [r1, #0]
    adds	r0, r4, #0
    adds	r0, #12
    adds	r0, r0, r3
    strb	r2, [r0, #0]
.Ljp_0809BE12:
    pop	{r4}
    pop	{r0}
    bx	r0

    .section .text.code_actor_0809C3E0
    .align 2, 0
    .Lcode_actor_0809C3E0:
    push	{r4, r5, r6, lr}
    adds	r2, r0, #0
    movs	r5, #0
    adds	r6, r2, r1
    ldrb	r0, [r6, #0]
    cmp	r0, #0
    beq .Ljp_0809BE50
    adds	r0, r2, #0
    adds	r0, #12
    adds	r4, r0, r1
    ldr r0, .Ljp_0809BE40
    adds	r0, r1, r0
    ldrb	r3, [r4, #0]
    ldrb	r0, [r0, #0]
    cmp	r3, r0
    bcs .Ljp_0809BE44
    adds	r0, r3, #1
    strb	r0, [r4, #0]
    b .Ljp_0809BE50
    .align 2, 0
.Ljp_0809BE40:
    .4byte gActorStateMaxValues
.Ljp_0809BE44:
    strb	r5, [r6, #0]
    adds	r0, r2, #6
    adds	r0, r0, r1
    movs	r1, #1
    strb	r1, [r0, #0]
    movs	r5, #1
.Ljp_0809BE50:
    adds	r0, r5, #0
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1

    .section .text.code_actor_0809C420
    .align 2, 0
    .Lcode_actor_0809C420:
    push	{lr}
    adds	r2, r0, #0
    adds	r0, r2, r1
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_0809BE76
    cmp	r1, #0
    beq .Ljp_0809BE6C
    cmp	r1, #3
    bne .Ljp_0809BE76
.Ljp_0809BE6C:
    adds	r0, r2, #0
    adds	r0, #12
    adds	r0, r0, r1
    movs	r1, #0
    strb	r1, [r0, #0]
.Ljp_0809BE76:
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.code_actor_0809C444
    .align 2, 0
    .Lcode_actor_0809C444:
    push	{r4, r5, lr}
    adds	r4, r0, #0
    movs	r5, #0
    bl func_0809C22C
    adds	r1, r0, #0
    adds	r0, r4, r1
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_0809BEA2
    cmp	r1, #0
    beq .Ljp_0809BE98
    cmp	r1, #3
    bne .Ljp_0809BEA2
.Ljp_0809BE98:
    adds	r0, r4, #0
    bl func_0809C3E0
    lsls	r0, r0, #24
    lsrs	r5, r0, #24
.Ljp_0809BEA2:
    adds	r0, r5, #0
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.code_actor_0809C474
    .align 2, 0
    .Lcode_actor_0809C474:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    bl func_0809C22C
    adds	r4, r0, #0
    movs	r6, #0
    adds	r0, r5, r4
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_0809BEE4
    cmp	r4, #1
    beq .Ljp_0809BEC8
    cmp	r4, #4
    bne .Ljp_0809BED4
.Ljp_0809BEC8:
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_0809C3E0
    lsls	r0, r0, #24
    lsrs	r6, r0, #24
.Ljp_0809BED4:
    cmp	r4, #0
    beq .Ljp_0809BEDC
    cmp	r4, #3
    bne .Ljp_0809BEE4
.Ljp_0809BEDC:
    adds	r0, r5, #0
    adds	r1, r4, #0
    bl func_0809C420
.Ljp_0809BEE4:
    adds	r0, r6, #0
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1

    .section .text.code_actor_0809C4B4
    .align 2, 0
    .Lcode_actor_0809C4B4:
    push	{r4, lr}
    adds	r4, r0, #0
    bl func_0809C22C
    adds	r1, r0, #0
    movs	r2, #0
    adds	r0, r4, r1
    ldrb	r0, [r0, #0]
    cmp	r0, #0
    beq .Ljp_0809BF12
    cmp	r1, #5
    beq .Ljp_0809BF08
    cmp	r1, #2
    bne .Ljp_0809BF12
.Ljp_0809BF08:
    adds	r0, r4, #0
    bl func_0809C3E0
    lsls	r0, r0, #24
    lsrs	r2, r0, #24
.Ljp_0809BF12:
    adds	r0, r2, #0
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.code_actor_0809C4E4
    .align 2, 0
    .Lcode_actor_0809C4E4:
    movs	r1, #0
    str	r1, [r0, #0]
    bx	lr
    .align 2, 0

    .section .text.code_actor_0809C4EC
    .align 2, 0
    .Lcode_actor_0809C4EC:
    push	{lr}
    adds	r3, r0, #0
    movs	r2, #0
    cmp	r1, #13
    bhi .Ljp_0809BF40
    movs	r0, #31
    ands	r0, r1
    movs	r2, #1
    lsls	r2, r0
    ldr	r1, [r3, #0]
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Ljp_0809BF40:
    movs	r0, #1
    eors	r0, r2
    pop	{r1}
    bx	r1
    .global func_0809C510
    .thumb_func
func_0809C510:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    adds	r4, r2, #0
    lsls	r3, r3, #24
    lsrs	r3, r3, #24
    adds	r6, r3, #0
    movs	r0, #0
    cmp	r4, #13
    bhi .Ljp_0809BF6C
    movs	r0, #31
    ands	r0, r4
    movs	r2, #1
    lsls	r2, r0
    ldr	r1, [r1, #0]
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r0, r0, #31
.Ljp_0809BF6C:
    cmp	r0, #0
    beq .Ljp_0809BFAC
    cmp	r4, #13
    bne .Ljp_0809BF8C
    cmp	r3, #0
    beq .Ljp_0809BF8C
    ldr r0, .Ljp_0809BF84
    adds	r0, #156	@ 0x9c
    ldrb	r1, [r0, #8]
    ldrb	r2, [r0, #9]
    ldr r0, .Ljp_0809BF88
    b .Ljp_0809BFD8
.Ljp_0809BF84:
    .4byte gActorDataSelectionEntries
.Ljp_0809BF88:
    .4byte gFieldRenderRectDescriptors + 0x780
.Ljp_0809BF8C:
    ldr r2, .Ljp_0809BFA8
    lsls	r0, r4, #1
    adds	r0, r0, r4
    lsls	r0, r0, #2
    adds	r1, r2, #4
    adds	r1, r0, r1
    adds	r0, r0, r2
    ldrb	r2, [r0, #8]
    ldrb	r3, [r0, #9]
    ldr	r0, [r1, #0]
    str	r0, [r5, #0]
    str	r2, [r5, #4]
    str	r3, [r5, #8]
    b .Ljp_0809BFDE
.Ljp_0809BFA8:
    .4byte gActorDataSelectionEntries
.Ljp_0809BFAC:
    cmp	r4, #13
    bne .Ljp_0809BFC8
    cmp	r6, #0
    beq .Ljp_0809BFC8
    ldr r0, .Ljp_0809BFC0
    adds	r0, #156	@ 0x9c
    ldrb	r1, [r0, #8]
    ldrb	r2, [r0, #9]
    ldr r0, .Ljp_0809BFC4
    b .Ljp_0809BFD8
.Ljp_0809BFC0:
    .4byte gActorDataSelectionEntries
.Ljp_0809BFC4:
    .4byte gFieldRenderRectDescriptors + 0x768
.Ljp_0809BFC8:
    ldr r1, .Ljp_0809BFE8
    lsls	r0, r4, #1
    adds	r0, r0, r4
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldrb	r1, [r0, #8]
    ldrb	r2, [r0, #9]
    ldr	r0, [r0, #0]
.Ljp_0809BFD8:
    str	r0, [r5, #0]
    str	r1, [r5, #4]
    str	r2, [r5, #8]
.Ljp_0809BFDE:
    adds	r0, r5, #0
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0809BFE8:
    .4byte gActorDataSelectionEntries

    .section .text.code_actor_0809C5B4
    .Lcode_actor_0809C5B4:

    .section .text.code_actor_0809C5D0
    .Lcode_actor_0809C5D0:

    .section .text.code_actor_0809C5EC
    .Lcode_actor_0809C5EC:

    .section .text.code_actor_0809C5F4
    .Lcode_actor_0809C5F4:

    .section .text.code_actor_0809C600
    .Lcode_actor_0809C600:

    .section .text.code_actor_0809C644
    .align 2, 0
    .Lcode_actor_0809C644:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r0, sp
    strh	r1, [r0, #0]
    adds	r0, r5, #4
    ldr	r4, [r5, #0]
    lsls	r4, r4, #1
    adds	r4, #4
    adds	r4, r5, r4
    adds	r1, r4, #0
    mov	r2, sp
    bl func_080E3E28
    adds	r3, r0, #0
    cmp	r3, r4
    beq .Ljp_0809C0C2
    ldr	r0, [r5, #0]
    cmp	r0, #0
    beq .Ljp_0809C0C2
    lsls	r0, r0, #1
    adds	r0, #4
    adds	r0, r5, r0
    adds	r1, r3, #2
    cmp	r1, r0
    beq .Ljp_0809C0BC
    cmp	r0, r1
    beq .Ljp_0809C0BC
    subs	r2, r0, r1
    adds	r0, r3, #0
    bl memmove
.Ljp_0809C0BC:
    ldr	r0, [r5, #0]
    subs	r0, #1
    str	r0, [r5, #0]
.Ljp_0809C0C2:
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.code_actor_0809C694
    .Lcode_actor_0809C694:

    .section .text.code_actor_0809C6AC
    .Lcode_actor_0809C6AC:

    .section .text.code_actor_0809C6B0
    .Lcode_actor_0809C6B0:

    .section .text.code_actor_0809C6BC
    .align 2, 0
    .Lcode_actor_0809C6BC:
    .global func_0809C6BC
    .thumb_func
func_0809C6BC:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #4
    adds	r7, r0, #0
    movs	r0, #0
    str	r0, [r7, #0]
    ldr r0, .Ljp_0809C4F0
    strh	r0, [r7, #12]
    movs	r5, #7
    negs	r5, r5
    movs	r0, #0
    strb	r0, [r7, #14]
    subs	r0, #3
    mov	r9, r0
    movs	r4, #25
    negs	r4, r4
    movs	r0, #0
    strb	r0, [r7, #15]
    strb	r0, [r7, #16]
    ldrb	r1, [r7, #17]
    subs	r0, #2
    ands	r0, r1
    mov	r1, r9
    ands	r0, r1
    movs	r2, #5
    negs	r2, r2
    ands	r0, r2
    movs	r1, #9
    negs	r1, r1
    ands	r0, r1
    subs	r2, #12
    ands	r0, r2
    movs	r3, #97	@ 0x61
    negs	r3, r3
    ands	r0, r3
    strb	r0, [r7, #17]
    ldr	r0, [r7, #16]
    ldr r1, .Ljp_0809C4F4
    mov	r8, r1
    ands	r0, r1
    str	r0, [r7, #16]
    ldrb	r1, [r7, #18]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #18]
    ldrh	r1, [r7, #18]
    ldr r6, .Ljp_0809C4F8
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #18]
    ldrb	r1, [r7, #19]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    strb	r0, [r7, #19]
    ldrb	r1, [r7, #20]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #20]
    ldrh	r1, [r7, #20]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #20]
    ldrb	r1, [r7, #21]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #21]
    ldr	r0, [r7, #20]
    mov	r1, r8
    ands	r0, r1
    str	r0, [r7, #20]
    ldrb	r1, [r7, #22]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #22]
    ldrh	r1, [r7, #22]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #22]
    ldrb	r1, [r7, #23]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    ands	r0, r2
    strb	r0, [r7, #23]
    ldrb	r1, [r7, #24]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #24]
    ldrh	r1, [r7, #24]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #24]
    ldrb	r1, [r7, #25]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #25]
    ldr	r0, [r7, #24]
    mov	r2, r8
    ands	r0, r2
    str	r0, [r7, #24]
    ldrb	r1, [r7, #26]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #26]
    ldrh	r1, [r7, #26]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #26]
    ldrb	r1, [r7, #27]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r7, #27]
    ldrb	r1, [r7, #28]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #28]
    ldrh	r1, [r7, #28]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #28]
    ldrb	r1, [r7, #29]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #29]
    ldr	r0, [r7, #28]
    ands	r0, r2
    str	r0, [r7, #28]
    ldrb	r1, [r7, #30]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r7, #30]
    ldrh	r1, [r7, #30]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #30]
    ldrb	r1, [r7, #31]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    strb	r0, [r7, #31]
    adds	r2, r7, #0
    adds	r2, #32
    ldrb	r1, [r2, #0]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #32]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #32]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldr	r0, [r7, #32]
    mov	r1, r8
    ands	r0, r1
    str	r0, [r7, #32]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    movs	r1, #33	@ 0x21
    negs	r1, r1
    ands	r0, r1
    subs	r1, #32
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #15
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #8
    negs	r0, r0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #36]	@ 0x24
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #36]	@ 0x24
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #38	@ 0x26
    movs	r2, #4
    negs	r2, r2
    mov	sl, r2
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, r7, #0
    adds	r2, #42	@ 0x2a
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #42]	@ 0x2a
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #42]	@ 0x2a
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    movs	r1, #9
    negs	r1, r1
    ands	r0, r1
    subs	r1, #40	@ 0x28
    ands	r0, r1
    movs	r1, #63	@ 0x3f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #44	@ 0x2c
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r2, #2
    ldrb	r1, [r2, #0]
    mov	r0, sl
    ands	r0, r1
    movs	r1, #13
    negs	r1, r1
    ands	r0, r1
    subs	r1, #36	@ 0x24
    ands	r0, r1
    strb	r0, [r2, #0]
    ldr	r0, [r7, #44]	@ 0x2c
    ldr r2, .Ljp_0809C4FC
    mov	ip, r2
    ands	r0, r2
    str	r0, [r7, #44]	@ 0x2c
    adds	r2, r7, #0
    adds	r2, #46	@ 0x2e
    ldrb	r1, [r2, #0]
    movs	r0, #5
    negs	r0, r0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #47	@ 0x2f
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, #8
    ldrb	r1, [r2, #0]
    mov	r0, sl
    ands	r0, r1
    movs	r1, #5
    negs	r1, r1
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #54]	@ 0x36
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #54]	@ 0x36
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #56	@ 0x38
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, #3
    ldrb	r1, [r2, #0]
    mov	r0, sl
    ands	r0, r1
    movs	r1, #29
    negs	r1, r1
    ands	r0, r1
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #58]	@ 0x3a
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r7, #58]	@ 0x3a
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #2
    negs	r0, r0
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r7, #60]	@ 0x3c
    ldr r0, .Ljp_0809C500
    ands	r0, r1
    strh	r0, [r7, #60]	@ 0x3c
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #13
    negs	r0, r0
    ands	r0, r1
    movs	r1, #49	@ 0x31
    negs	r1, r1
    ands	r0, r1
    strb	r0, [r2, #0]
    ldr	r0, [r7, #60]	@ 0x3c
    mov	r2, ip
    ands	r0, r2
    str	r0, [r7, #60]	@ 0x3c
    adds	r2, r7, #0
    adds	r2, #62	@ 0x3e
    ldrb	r1, [r2, #0]
    movs	r0, #13
    negs	r0, r0
    ands	r0, r1
    movs	r1, #49	@ 0x31
    negs	r1, r1
    ands	r0, r1
    movs	r1, #63	@ 0x3f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #63	@ 0x3f
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r2, #2
    ldrb	r1, [r2, #0]
    subs	r0, #2
    ands	r0, r1
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    strb	r0, [r2, #0]
    ldr	r0, [r7, #64]	@ 0x40
    ldr r1, .Ljp_0809C504
    ands	r0, r1
    str	r0, [r7, #64]	@ 0x40
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    movs	r1, #33	@ 0x21
    negs	r1, r1
    ands	r0, r1
    movs	r1, #63	@ 0x3f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #67	@ 0x43
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, #11
    ldrb	r1, [r2, #0]
    mov	r0, sl
    ands	r0, r1
    movs	r1, #5
    negs	r1, r1
    ands	r0, r1
    subs	r1, #4
    ands	r0, r1
    subs	r1, #8
    ands	r0, r1
    subs	r1, #16
    ands	r0, r1
    subs	r1, #32
    ands	r0, r1
    strb	r0, [r2, #0]
    ldr	r0, [r7, #76]	@ 0x4c
    mov	r2, r8
    ands	r0, r2
    str	r0, [r7, #76]	@ 0x4c
    adds	r2, r7, #0
    adds	r2, #78	@ 0x4e
    ldrb	r1, [r2, #0]
    mov	r0, r9
    ands	r0, r1
    movs	r1, #13
    negs	r1, r1
    ands	r0, r1
    subs	r1, #4
    ands	r0, r1
    ands	r0, r3
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    adds	r0, r6, #0
    ands	r0, r1
    b .Ljp_0809C508
.Ljp_0809C4F0:
    .4byte 0x0000FFFF
.Ljp_0809C4F4:
    .4byte 0xFFFE7FFF
.Ljp_0809C4F8:
    .4byte 0xFFFFFE7F
.Ljp_0809C4FC:
    .4byte 0xFFFC3FFF
.Ljp_0809C500:
    .4byte 0xFFFFFC7F
.Ljp_0809C504:
    .4byte 0xFFFE1FFF
.Ljp_0809C508:
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #15
    negs	r0, r0
    ands	r0, r1
    movs	r1, #49	@ 0x31
    negs	r1, r1
    ands	r0, r1
    subs	r1, #16
    ands	r0, r1
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #80	@ 0x50
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, #3
    ldrb	r1, [r2, #0]
    subs	r0, #2
    ands	r0, r1
    ands	r0, r5
    movs	r1, #9
    negs	r1, r1
    ands	r0, r1
    subs	r1, #40	@ 0x28
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    ldr r0, .Ljp_0809C794
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    movs	r1, #9
    negs	r1, r1
    ands	r0, r1
    subs	r1, #40	@ 0x28
    ands	r0, r1
    movs	r1, #63	@ 0x3f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #84	@ 0x54
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    movs	r2, #63	@ 0x3f
    mov	r8, r2
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, r7, #0
    adds	r2, #89	@ 0x59
    ldrb	r1, [r2, #0]
    mov	r0, sl
    ands	r0, r1
    movs	r1, #5
    negs	r1, r1
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    strb	r0, [r2, #0]
    ldr	r0, [r7, #88]	@ 0x58
    ldr r1, .Ljp_0809C798
    ands	r0, r1
    str	r0, [r7, #88]	@ 0x58
    adds	r1, r7, #0
    adds	r1, #90	@ 0x5a
    ldrh	r0, [r1, #0]
    ands	r6, r0
    strh	r6, [r1, #0]
    adds	r2, #2
    ldrb	r1, [r2, #0]
    adds	r0, r5, #0
    ands	r0, r1
    ands	r0, r4
    ands	r0, r3
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #92	@ 0x5c
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r1, #1
    ldrb	r0, [r1, #0]
    mov	r2, sl
    ands	r2, r0
    movs	r0, #13
    negs	r0, r0
    ands	r2, r0
    subs	r0, #36	@ 0x24
    ands	r2, r0
    strb	r2, [r1, #0]
    ldrh	r2, [r1, #0]
    ldr r3, .Ljp_0809C79C
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldr	r0, [r7, #104]	@ 0x68
    ldr r6, .Ljp_0809C7A0
    ands	r0, r6
    str	r0, [r7, #104]	@ 0x68
    adds	r2, r7, #0
    adds	r2, #106	@ 0x6a
    ldrh	r1, [r2, #0]
    adds	r0, r3, #0
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    mov	r0, r8
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #108	@ 0x6c
    ldrb	r2, [r1, #0]
    subs	r4, #39	@ 0x27
    adds	r0, r4, #0
    ands	r0, r2
    strb	r0, [r1, #0]
    ldrh	r2, [r1, #0]
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldr	r0, [r7, #108]	@ 0x6c
    ands	r0, r6
    str	r0, [r7, #108]	@ 0x6c
    adds	r2, r7, #0
    adds	r2, #110	@ 0x6e
    ldrh	r1, [r2, #0]
    adds	r0, r3, #0
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    mov	r0, r8
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #112	@ 0x70
    ldrb	r2, [r1, #0]
    adds	r0, r4, #0
    ands	r0, r2
    strb	r0, [r1, #0]
    ldrh	r2, [r1, #0]
    adds	r0, r3, #0
    ands	r0, r2
    strh	r0, [r1, #0]
    ldr	r0, [r7, #112]	@ 0x70
    ands	r0, r6
    str	r0, [r7, #112]	@ 0x70
    adds	r1, #2
    ldrh	r0, [r1, #0]
    ands	r3, r0
    strh	r3, [r1, #0]
    adds	r1, #1
    ldrb	r0, [r1, #0]
    mov	r2, r8
    ands	r2, r0
    strb	r2, [r1, #0]
    adds	r1, #1
    ldrb	r0, [r1, #0]
    ands	r4, r0
    strb	r4, [r1, #0]
    ldrh	r2, [r1, #0]
    ldr r0, .Ljp_0809C794
    ands	r0, r2
    strh	r0, [r1, #0]
    adds	r1, #1
    ldrb	r0, [r1, #0]
    ands	r5, r0
    movs	r0, #9
    negs	r0, r0
    ands	r5, r0
    movs	r2, #17
    negs	r2, r2
    ands	r5, r2
    subs	r0, #24
    ands	r5, r0
    subs	r2, #48	@ 0x30
    ands	r5, r2
    movs	r0, #127	@ 0x7f
    ands	r5, r0
    strb	r5, [r1, #0]
    adds	r2, r7, #0
    adds	r2, #118	@ 0x76
    ldrb	r1, [r2, #0]
    subs	r0, #129	@ 0x81
    ands	r0, r1
    mov	r1, r9
    ands	r0, r1
    movs	r1, #5
    negs	r1, r1
    ands	r0, r1
    subs	r1, #4
    ands	r0, r1
    subs	r1, #8
    ands	r0, r1
    subs	r1, #16
    ands	r0, r1
    subs	r1, #32
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    ldr r0, .Ljp_0809C7A4
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, #1
    ldrb	r1, [r2, #0]
    movs	r0, #121	@ 0x79
    negs	r0, r0
    ands	r0, r1
    movs	r1, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #120	@ 0x78
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    adds	r2, #3
    ldrb	r0, [r2, #0]
    movs	r1, #2
    negs	r1, r1
    ands	r1, r0
    strb	r1, [r2, #0]
    ldrh	r1, [r2, #0]
    ldr r0, .Ljp_0809C7A8
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r1, r7, #0
    adds	r1, #123	@ 0x7b
    ldrb	r0, [r1, #0]
    mov	r2, r9
    ands	r2, r0
    movs	r0, #5
    negs	r0, r0
    ands	r2, r0
    movs	r6, #9
    negs	r6, r6
    ands	r2, r6
    movs	r5, #17
    negs	r5, r5
    ands	r2, r5
    movs	r4, #33	@ 0x21
    negs	r4, r4
    ands	r2, r4
    movs	r3, #65	@ 0x41
    negs	r3, r3
    ands	r2, r3
    movs	r0, #127	@ 0x7f
    ands	r2, r0
    strb	r2, [r1, #0]
    adds	r1, #1
    movs	r2, #5
    negs	r2, r2
    movs	r0, #0
    strb	r0, [r1, #0]
    adds	r1, #1
    strb	r0, [r1, #0]
    movs	r1, #126	@ 0x7e
    adds	r1, r1, r7
    mov	r8, r1
    ldrb	r1, [r1, #0]
    subs	r0, #4
    ands	r0, r1
    ands	r0, r2
    ands	r0, r6
    ands	r0, r5
    ands	r0, r4
    ands	r0, r3
    mov	r2, r8
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    ldr r0, .Ljp_0809C7AC
    ands	r0, r1
    strh	r0, [r2, #0]
    adds	r2, r7, #0
    adds	r2, #127	@ 0x7f
    ldrb	r1, [r2, #0]
    movs	r0, #3
    ands	r0, r1
    strb	r0, [r2, #0]
    adds	r0, r7, #0
    add	sp, #4
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_0809C794:
    .4byte 0xFFFFFE3F
.Ljp_0809C798:
    .4byte 0xFFFC7FFF
.Ljp_0809C79C:
    .4byte 0xFFFFC03F
.Ljp_0809C7A0:
    .4byte 0xFFC03FFF
.Ljp_0809C7A4:
    .4byte 0xFFFFF87F
.Ljp_0809C7A8:
    .4byte 0xFFFFFE01
.Ljp_0809C7AC:
    .4byte 0xFFFFFC7F

    .section .text.code_actor_0809CD78

    .section .text.code_actor_0809CD98
    .Lcode_actor_0809CD98:

    .section .text.code_actor_0809CDCC
    .Lcode_actor_0809CDCC:

    .section .text.code_actor_0809CDEC
    .Lcode_actor_0809CDEC:

    .section .text.code_actor_0809CE1C
    .Lcode_actor_0809CE1C:

    .section .text.code_actor_0809CE24
    .Lcode_actor_0809CE24:

    .section .text.code_actor_0809CE30
    .align 2, 0
    .Lcode_actor_0809CE30:
    push	{lr}
    adds	r0, r1, #0
    subs	r0, #53	@ 0x35
    cmp	r0, #5
    bhi .Ljp_0809C898
    lsls	r0, r0, #2
    ldr r1, .Ljp_0809C87C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0809C87C:
    .4byte .Ljp_0809C880
.Ljp_0809C880:
    .4byte .Ljp_0809C898
    .4byte .Ljp_0809C89C
    .4byte .Ljp_0809C8A0
    .4byte .Ljp_0809C8A4
    .4byte .Ljp_0809C8A8
    .4byte .Ljp_0809C8AC
.Ljp_0809C898:
    movs	r0, #252	@ 0xfc
    b .Ljp_0809C8AE
.Ljp_0809C89C:
    movs	r0, #249	@ 0xf9
    b .Ljp_0809C8AE
.Ljp_0809C8A0:
    movs	r0, #254	@ 0xfe
    b .Ljp_0809C8AE
.Ljp_0809C8A4:
    movs	r0, #253	@ 0xfd
    b .Ljp_0809C8AE
.Ljp_0809C8A8:
    movs	r0, #250	@ 0xfa
    b .Ljp_0809C8AE
.Ljp_0809C8AC:
    movs	r0, #251	@ 0xfb
.Ljp_0809C8AE:
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.code_actor_0809CE7C
    .Lcode_actor_0809CE7C:

    .section .text.code_actor_0809CE8C
    .align 2, 0
    .Lcode_actor_0809CE8C:
    .global func_0809CE8C
    .thumb_func
func_0809CE8C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    adds	r7, r0, #0
    movs	r0, #0
    str	r0, [r7, #0]
    ldr r0, .Ljp_0809C95C
    adds	r2, r7, r0
    movs	r0, #2
    negs	r0, r0
    movs	r3, #3
    negs	r3, r3
    movs	r4, #5
    negs	r4, r4
    movs	r5, #9
    negs	r5, r5
    movs	r6, #17
    negs	r6, r6
    movs	r1, #33	@ 0x21
    negs	r1, r1
    mov	r8, r1
    movs	r1, #0
    strb	r1, [r2, #0]
    ldr r1, .Ljp_0809C960
    adds	r2, r7, r1
    movs	r1, #0
    strb	r1, [r2, #0]
    ldr r1, .Ljp_0809C964
    adds	r2, r7, r1
    ldrb	r1, [r2, #0]
    ands	r0, r1
    ands	r0, r3
    ands	r0, r4
    ands	r0, r5
    ands	r0, r6
    mov	r1, r8
    ands	r0, r1
    strb	r0, [r2, #0]
    movs	r0, #0
    movs	r1, #16
    negs	r1, r1
    mov	r8, r1
    ldr r6, .Ljp_0809C968
    movs	r5, #3
.Ljp_0809C91C:
    movs	r3, #0
    lsls	r1, r0, #3
    adds	r4, r0, #1
    subs	r1, r1, r0
    lsls	r1, r1, #3
    adds	r0, r7, #4
    adds	r2, r1, r0
.Ljp_0809C92A:
    ldrb	r1, [r2, #0]
    mov	r0, r8
    ands	r0, r1
    strb	r0, [r2, #0]
    ldrh	r1, [r2, #0]
    adds	r0, r6, #0
    ands	r0, r1
    strh	r0, [r2, #0]
    ldrb	r1, [r2, #1]
    adds	r0, r5, #0
    ands	r0, r1
    strb	r0, [r2, #1]
    adds	r2, #2
    adds	r3, #1
    cmp	r3, #27
    bls .Ljp_0809C92A
    adds	r0, r4, #0
    cmp	r0, #27
    bls .Ljp_0809C91C
    adds	r0, r7, #0
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
.Ljp_0809C95C:
    .4byte 0x00000624
.Ljp_0809C960:
    .4byte 0x00000625
.Ljp_0809C964:
    .4byte 0x00000626
.Ljp_0809C968:
    .4byte 0xFFFFFC0F
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
    bl func_0809D8A4
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
    bl func_0809D8B8
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
    bl func_0809D470 + 0x90
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
    bl func_0809D8A4
    str	r0, [sp, #12]
    mov	r0, sl
    bl func_0809D8B8
    str	r0, [sp, #16]
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl func_0809D418
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
    .4byte gUnk_08103F98
.Ljp_0809CCA4:
    .4byte gUnk_08103F84
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
    bl func_0809D470
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
    .4byte gUnk_08103FE4
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
    .4byte gUnk_0810400C

    .section .text.code_actor_0809D418
    .Lcode_actor_0809D418:

    .section .text.code_actor_0809D470
    .align 2, 0
    .Lcode_actor_0809D470:
    .global func_0809D470
    .thumb_func
func_0809D470:
    push	{lr}
    cmp	r1, #152	@ 0x98
    beq .Ljp_0809CF0A
    cmp	r1, #152	@ 0x98
    bhi .Ljp_0809CED8
    cmp	r1, #40	@ 0x28
    beq .Ljp_0809CF06
    cmp	r1, #40	@ 0x28
    bhi .Ljp_0809CEC4
    cmp	r1, #20
    beq .Ljp_0809CEFE
    cmp	r1, #30
    beq .Ljp_0809CF02
    b .Ljp_0809CF12
.Ljp_0809CEC4:
    cmp	r1, #102	@ 0x66
    beq .Ljp_0809CF0A
    cmp	r1, #102	@ 0x66
    bhi .Ljp_0809CED2
    cmp	r1, #60	@ 0x3c
    beq .Ljp_0809CF0A
    b .Ljp_0809CF12
.Ljp_0809CED2:
    cmp	r1, #123	@ 0x7b
    beq .Ljp_0809CF0A
    b .Ljp_0809CF12
.Ljp_0809CED8:
    cmp	r1, #190	@ 0xbe
    beq .Ljp_0809CF0A
    cmp	r1, #190	@ 0xbe
    bhi .Ljp_0809CEEA
    cmp	r1, #155	@ 0x9b
    beq .Ljp_0809CF0A
    cmp	r1, #171	@ 0xab
    beq .Ljp_0809CF0A
    b .Ljp_0809CF12
.Ljp_0809CEEA:
    cmp	r1, #222	@ 0xde
    beq .Ljp_0809CF0A
    cmp	r1, #222	@ 0xde
    bhi .Ljp_0809CEF8
    cmp	r1, #202	@ 0xca
    beq .Ljp_0809CF0A
    b .Ljp_0809CF12
.Ljp_0809CEF8:
    cmp	r1, #255	@ 0xff
    beq .Ljp_0809CF0E
    b .Ljp_0809CF12
.Ljp_0809CEFE:
    movs	r0, #12
    b .Ljp_0809CF32
.Ljp_0809CF02:
    movs	r0, #14
    b .Ljp_0809CF32
.Ljp_0809CF06:
    movs	r0, #16
    b .Ljp_0809CF32
.Ljp_0809CF0A:
    movs	r0, #18
    b .Ljp_0809CF32
.Ljp_0809CF0E:
    movs	r0, #20
    b .Ljp_0809CF32
.Ljp_0809CF12:
    adds	r0, r1, #0
    cmp	r0, #10
    bls .Ljp_0809CF32
    movs	r0, #11
    cmp	r1, #19
    bls .Ljp_0809CF32
    movs	r0, #13
    cmp	r1, #29
    bls .Ljp_0809CF32
    movs	r0, #15
    cmp	r1, #39	@ 0x27
    bls .Ljp_0809CF32
    movs	r0, #19
    cmp	r1, #230	@ 0xe6
    bhi .Ljp_0809CF32
    movs	r0, #17
.Ljp_0809CF32:
    pop	{r1}
    bx	r1
    .align 2, 0
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
    bl func_0809D8A4
    str	r0, [sp, #12]
    mov	r0, sl
    bl func_0809D8B8
    str	r0, [sp, #16]
    mov	r0, sl
    ldr	r1, [sp, #0]
    bl func_0809D79C
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
    .4byte gUnk_08103B38
.Ljp_0809D034:
    .4byte gUnk_08103B10
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
    bl func_0809D7D8
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
    .4byte gUnk_08103C3C
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
    .4byte gUnk_08103C74
    .global func_0809D79C
    .thumb_func
func_0809D79C:
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

    .section .text.code_actor_0809D7D8

    .section .text.code_actor_0809D8A0
    .Lcode_actor_0809D8A0:

    .section .text.code_actor_0809D8A4
    .Lcode_actor_0809D8A4:

    .section .text.code_actor_0809D8B8
    .Lcode_actor_0809D8B8:

    .section .text.code_actor_0809D8D4
    .Lcode_actor_0809D8D4:

    .section .text.code_actor_0809D8E8
    .align 2, 0
    .Lcode_actor_0809D8E8:
    .global func_0809D8E8
    .thumb_func
func_0809D8E8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r6, r0, #0
    mov	sl, r2
    adds	r2, r3, #0
    movs	r0, #0
    str	r0, [sp, #0]
    lsls	r7, r1, #1
    mov	r1, sl
    lsls	r3, r1, #3
    subs	r0, r3, r1
    lsls	r0, r0, #3
    adds	r0, r7, r0
    adds	r4, r6, r0
    ldrb	r0, [r4, #4]
    lsls	r0, r0, #28
    cmp	r0, #0
    bne .Ljp_0809D3DA
    ldrb	r1, [r4, #5]
    lsrs	r1, r1, #2
    adds	r0, r6, #0
    str	r3, [sp, #4]
    bl func_0809DA00
    str	r0, [sp, #0]
    ldr	r3, [sp, #4]
    cmp	r0, #1
    bne .Ljp_0809D3B4
    ldrb	r0, [r4, #4]
    movs	r1, #16
    negs	r1, r1
    ands	r1, r0
    movs	r0, #2
    orrs	r1, r0
    strb	r1, [r4, #4]
    movs	r2, #0
    str	r2, [sp, #0]
    movs	r5, #0
    mov	r9, r7
    mov	r8, r3
    b .Ljp_0809D3A8
.Ljp_0809D37A:
    movs	r4, #0
    adds	r7, r5, #1
    b .Ljp_0809D39C
.Ljp_0809D380:
    lsls	r0, r4, #1
    lsls	r1, r5, #3
    subs	r1, r1, r5
    lsls	r1, r1, #3
    adds	r0, r0, r1
    adds	r2, r6, r0
    ldrb	r1, [r2, #5]
    lsrs	r0, r1, #2
    cmp	r0, #1
    bne .Ljp_0809D39A
    movs	r0, #3
    ands	r0, r1
    strb	r0, [r2, #5]
.Ljp_0809D39A:
    adds	r4, #1
.Ljp_0809D39C:
    adds	r0, r6, #0
    bl func_0809D8A4
    cmp	r4, r0
    blt .Ljp_0809D380
    adds	r5, r7, #0
.Ljp_0809D3A8:
    adds	r0, r6, #0
    bl func_0809D8B8
    cmp	r5, r0
    blt .Ljp_0809D37A
    b .Ljp_0809D3C6
.Ljp_0809D3B4:
    ldrb	r0, [r4, #4]
    movs	r1, #16
    negs	r1, r1
    ands	r1, r0
    movs	r0, #1
    orrs	r1, r0
    strb	r1, [r4, #4]
    mov	r9, r7
    mov	r8, r3
.Ljp_0809D3C6:
    mov	r1, r8
    mov	r2, sl
    subs	r0, r1, r2
    lsls	r0, r0, #3
    add	r0, r9
    adds	r0, r6, r0
    ldrb	r2, [r0, #5]
    movs	r1, #3
    ands	r1, r2
    strb	r1, [r0, #5]
.Ljp_0809D3DA:
    ldr	r0, [sp, #0]
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0809D9B4
    .thumb_func
func_0809D9B4:
    push	{r4, r5, r6, lr}
    adds	r5, r0, #0
    movs	r6, #0
    lsls	r1, r1, #1
    lsls	r0, r2, #3
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r4, r5, r1
    ldrb	r0, [r4, #4]
    lsls	r0, r0, #28
    lsrs	r0, r0, #28
    cmp	r0, #4
    bne .Ljp_0809D42A
    ldrh	r1, [r4, #4]
    lsls	r1, r1, #22
    lsrs	r1, r1, #26
    adds	r0, r5, #0
    adds	r2, r3, #0
    bl func_0809DA00
    adds	r6, r0, #0
    ldrb	r1, [r4, #4]
    movs	r0, #16
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r4, #4]
    ldrh	r1, [r4, #4]
    ldr r0, .Ljp_0809D434
    ands	r0, r1
    strh	r0, [r4, #4]
.Ljp_0809D42A:
    adds	r0, r6, #0
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0809D434:
    .4byte 0xFFFFFC0F
    .global func_0809DA00
    .thumb_func
func_0809DA00:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #16
    adds	r5, r0, #0
    mov	r8, r1
    adds	r6, r2, #0
    mov	r0, r8
    subs	r0, #3
    cmp	r0, #31
    bls .Ljp_0809D450
    b .Ljp_0809D954
.Ljp_0809D450:
    lsls	r0, r0, #2
    ldr r1, .Ljp_0809D45C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
    .align 2, 0
.Ljp_0809D45C:
    .4byte .Ljp_0809D460
.Ljp_0809D460:
    .4byte .Ljp_0809D4E0
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D53A
    .4byte .Ljp_0809D5D4
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D634
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D954
    .4byte .Ljp_0809D66E
    .4byte .Ljp_0809D7DE
    .4byte .Ljp_0809D934
.Ljp_0809D4E0:
    ldr r0, .Ljp_0809D50C
    adds	r1, r6, r0
    mov	r0, sp
    bl func_0800E924
    mov	r0, sp
    ldrh	r0, [r0, #0]
    lsls	r0, r0, #22
    ldr r1, .Ljp_0809D510
    cmp	r0, r1
    bgt .Ljp_0809D518
    ldr r1, .Ljp_0809D514
    adds	r2, r5, r1
    ldrb	r1, [r2, #0]
    movs	r0, #4
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0809D506
    b .Ljp_0809D668
.Ljp_0809D506:
    movs	r0, #4
    b .Ljp_0809D528
    .align 2, 0
.Ljp_0809D50C:
    .4byte 0x00001BD8
.Ljp_0809D510:
    .4byte 0x4CC00000
.Ljp_0809D514:
    .4byte 0x00000625
.Ljp_0809D518:
    ldr r0, .Ljp_0809D530
    adds	r2, r5, r0
    ldrb	r1, [r2, #0]
    movs	r0, #1
    ands	r0, r1
    cmp	r0, #0
    bne .Ljp_0809D534
    movs	r0, #1
.Ljp_0809D528:
    orrs	r0, r1
    strb	r0, [r2, #0]
    b .Ljp_0809D954
    .align 2, 0
.Ljp_0809D530:
    .4byte 0x00000624
.Ljp_0809D534:
    movs	r1, #0
    mov	r8, r1
    b .Ljp_0809D954
.Ljp_0809D53A:
    movs	r4, #0
    ldr r2, .Ljp_0809D588
    adds	r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs	r1, #1
    negs	r1, r1
    cmp	r0, r1
    bne .Ljp_0809D54E
    movs	r4, #1
.Ljp_0809D54E:
    ldr r1, .Ljp_0809D58C
    adds	r0, r6, r1
    bl func_0809ED04
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0809D55E
    movs	r4, #1
.Ljp_0809D55E:
    adds	r0, r5, #0
    mov	r1, r8
    adds	r2, r6, #0
    bl func_0809DF2C
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0809D570
    movs	r4, #1
.Ljp_0809D570:
    cmp	r4, #1
    beq .Ljp_0809D668
    movs	r1, #81	@ 0x51
    mov	r0, r8
    subs	r0, #4
    cmp	r0, #5
    bhi .Ljp_0809D5C2
    lsls	r0, r0, #2
    ldr r1, .Ljp_0809D590
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0809D588:
    .4byte 0x00001C38
.Ljp_0809D58C:
    .4byte 0x00001DAC
.Ljp_0809D590:
    .4byte .Ljp_0809D594
.Ljp_0809D594:
    .4byte .Ljp_0809D5AC
    .4byte .Ljp_0809D5B0
    .4byte .Ljp_0809D5B4
    .4byte .Ljp_0809D5B8
    .4byte .Ljp_0809D5BC
    .4byte .Ljp_0809D5C0
.Ljp_0809D5AC:
    movs	r1, #5
    b .Ljp_0809D5C2
.Ljp_0809D5B0:
    movs	r1, #13
    b .Ljp_0809D5C2
.Ljp_0809D5B4:
    movs	r1, #21
    b .Ljp_0809D5C2
.Ljp_0809D5B8:
    movs	r1, #29
    b .Ljp_0809D5C2
.Ljp_0809D5BC:
    movs	r1, #37	@ 0x25
    b .Ljp_0809D5C2
.Ljp_0809D5C0:
    movs	r1, #45	@ 0x2d
.Ljp_0809D5C2:
    cmp	r1, #81	@ 0x51
    bne .Ljp_0809D5C8
    b .Ljp_0809D954
.Ljp_0809D5C8:
    movs	r2, #210	@ 0xd2
    lsls	r2, r2, #6
    adds	r0, r6, r2
    bl func_0809C3BC
    b .Ljp_0809D954
.Ljp_0809D5D4:
    movs	r7, #0
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #8]
    ldrb	r0, [r6, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #12]
    add	r2, sp, #12
    add	r0, sp, #8
    cmp	r3, r1
    bls .Ljp_0809D5F4
    adds	r0, r2, #0
.Ljp_0809D5F4:
    ldr	r0, [r0, #0]
    cmp	r0, #2
    bhi .Ljp_0809D5FC
    movs	r7, #1
.Ljp_0809D5FC:
    ldr r0, .Ljp_0809D62C
    adds	r4, r5, r0
    ldrb	r1, [r4, #0]
    movs	r0, #16
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0809D60C
    movs	r7, #1
.Ljp_0809D60C:
    ldr r1, .Ljp_0809D630
    adds	r0, r6, r1
    bl GetFirstFreeToolSlot__C8Rucksack
    movs	r1, #1
    negs	r1, r1
    cmp	r0, r1
    bne .Ljp_0809D61E
    movs	r7, #1
.Ljp_0809D61E:
    cmp	r7, #0
    bne .Ljp_0809D668
    ldrb	r0, [r4, #0]
    movs	r1, #16
    orrs	r0, r1
    strb	r0, [r4, #0]
    b .Ljp_0809D954
.Ljp_0809D62C:
    .4byte 0x00000625
.Ljp_0809D630:
    .4byte 0x00001C38
.Ljp_0809D634:
    movs	r7, #0
    movs	r1, #210	@ 0xd2
    lsls	r1, r1, #6
    adds	r0, r6, r1
    bl func_0809C38C
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0809D648
    movs	r7, #1
.Ljp_0809D648:
    movs	r4, #4
.Ljp_0809D64A:
    adds	r0, r5, #0
    adds	r1, r4, #0
    adds	r2, r6, #0
    bl func_0809DF2C
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0809D65C
    movs	r7, #1
.Ljp_0809D65C:
    adds	r4, #1
    cmp	r4, #9
    ble .Ljp_0809D64A
    cmp	r7, #1
    beq .Ljp_0809D668
    b .Ljp_0809D954
.Ljp_0809D668:
    movs	r2, #0
    mov	r8, r2
    b .Ljp_0809D954
.Ljp_0809D66E:
    movs	r4, #0
    movs	r1, #250	@ 0xfa
    lsls	r1, r1, #1
    adds	r0, r6, r1
    bl GetShelf__9FarmHouse
    cmp	r0, #0
    bne .Ljp_0809D680
    movs	r4, #1
.Ljp_0809D680:
    adds	r0, r5, #0
    bl func_0809DFAC
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    cmp	r0, #8
    bne .Ljp_0809D6A0
    ldr r2, .Ljp_0809D6D0
    adds	r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs	r1, #1
    negs	r1, r1
    cmp	r0, r1
    bne .Ljp_0809D6A0
    movs	r4, #1
.Ljp_0809D6A0:
    cmp	r4, #0
    beq .Ljp_0809D6A6
    b .Ljp_0809D7D6
.Ljp_0809D6A6:
    ldr r0, .Ljp_0809D6D4
    adds	r1, r6, r0
    mov	r0, sp
    bl func_0800E924
    mov	r0, sp
    ldrh	r0, [r0, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    subs	r0, #52	@ 0x34
    cmp	r0, #155	@ 0x9b
    beq .Ljp_0809D758
    cmp	r0, #155	@ 0x9b
    bgt .Ljp_0809D6E2
    cmp	r0, #102	@ 0x66
    beq .Ljp_0809D710
    cmp	r0, #102	@ 0x66
    bgt .Ljp_0809D6D8
    cmp	r0, #60	@ 0x3c
    beq .Ljp_0809D6FA
    b .Ljp_0809D7D4
.Ljp_0809D6D0:
    .4byte 0x00001C38
.Ljp_0809D6D4:
    .4byte 0x00001BD8
.Ljp_0809D6D8:
    cmp	r0, #123	@ 0x7b
    beq .Ljp_0809D728
    cmp	r0, #152	@ 0x98
    beq .Ljp_0809D740
    b .Ljp_0809D7D4
.Ljp_0809D6E2:
    cmp	r0, #190	@ 0xbe
    beq .Ljp_0809D788
    cmp	r0, #190	@ 0xbe
    bgt .Ljp_0809D6F0
    cmp	r0, #171	@ 0xab
    beq .Ljp_0809D770
    b .Ljp_0809D7D4
.Ljp_0809D6F0:
    cmp	r0, #202	@ 0xca
    beq .Ljp_0809D7A0
    cmp	r0, #222	@ 0xde
    beq .Ljp_0809D7B8
    b .Ljp_0809D7D4
.Ljp_0809D6FA:
    ldr r2, .Ljp_0809D70C
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D7C6
    b .Ljp_0809D7D4
    .align 2, 0
.Ljp_0809D70C:
    .4byte 0x00000625
.Ljp_0809D710:
    ldr r0, .Ljp_0809D724
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #64	@ 0x40
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #64	@ 0x40
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D724:
    .4byte 0x00000625
.Ljp_0809D728:
    ldr r2, .Ljp_0809D73C
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #128	@ 0x80
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #128	@ 0x80
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D73C:
    .4byte 0x00000625
.Ljp_0809D740:
    ldr r0, .Ljp_0809D754
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #1
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #1
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D754:
    .4byte 0x00000626
.Ljp_0809D758:
    ldr r2, .Ljp_0809D76C
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #2
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #2
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D76C:
    .4byte 0x00000626
.Ljp_0809D770:
    ldr r0, .Ljp_0809D784
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #4
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #4
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D784:
    .4byte 0x00000626
.Ljp_0809D788:
    ldr r2, .Ljp_0809D79C
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #8
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #8
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D79C:
    .4byte 0x00000626
.Ljp_0809D7A0:
    ldr r0, .Ljp_0809D7B4
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #16
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #16
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D7B4:
    .4byte 0x00000626
.Ljp_0809D7B8:
    ldr r2, .Ljp_0809D7D0
.Ljp_0809D7BA:
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
.Ljp_0809D7C6:
    movs	r0, #32
.Ljp_0809D7C8:
    orrs	r0, r2
    strb	r0, [r1, #0]
    b .Ljp_0809D7D6
    .align 2, 0
.Ljp_0809D7D0:
    .4byte 0x00000626
.Ljp_0809D7D4:
    movs	r4, #1
.Ljp_0809D7D6:
    cmp	r4, #1
    beq .Ljp_0809D7DC
    b .Ljp_0809D954
.Ljp_0809D7DC:
    b .Ljp_0809D950
.Ljp_0809D7DE:
    movs	r4, #0
    movs	r1, #250	@ 0xfa
    lsls	r1, r1, #1
    adds	r0, r6, r1
    bl GetShelf__9FarmHouse
    cmp	r0, #0
    bne .Ljp_0809D7F0
    movs	r4, #1
.Ljp_0809D7F0:
    adds	r0, r5, #0
    bl func_0809E02C
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    cmp	r0, #8
    bne .Ljp_0809D810
    ldr r2, .Ljp_0809D840
    adds	r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs	r1, #1
    negs	r1, r1
    cmp	r0, r1
    bne .Ljp_0809D810
    movs	r4, #1
.Ljp_0809D810:
    cmp	r4, #0
    bne .Ljp_0809D7D6
    ldr r0, .Ljp_0809D844
    adds	r1, r6, r0
    mov	r0, sp
    bl func_0800E924
    mov	r0, sp
    ldrh	r0, [r0, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r1, .Ljp_0809D848
    adds	r0, r0, r1
    cmp	r0, #120	@ 0x78
    beq .Ljp_0809D8CC
    cmp	r0, #120	@ 0x78
    bgt .Ljp_0809D856
    cmp	r0, #40	@ 0x28
    beq .Ljp_0809D884
    cmp	r0, #40	@ 0x28
    bgt .Ljp_0809D84C
    cmp	r0, #0
    beq .Ljp_0809D86E
    b .Ljp_0809D7D4
.Ljp_0809D840:
    .4byte 0x00001C38
.Ljp_0809D844:
    .4byte 0x00001BD8
.Ljp_0809D848:
    .4byte 0xFFFFFECC
.Ljp_0809D84C:
    cmp	r0, #60	@ 0x3c
    beq .Ljp_0809D89C
    cmp	r0, #80	@ 0x50
    beq .Ljp_0809D8B4
    b .Ljp_0809D7D4
.Ljp_0809D856:
    cmp	r0, #160	@ 0xa0
    beq .Ljp_0809D8EC
    cmp	r0, #160	@ 0xa0
    bgt .Ljp_0809D864
    cmp	r0, #140	@ 0x8c
    beq .Ljp_0809D8D4
    b .Ljp_0809D7D4
.Ljp_0809D864:
    cmp	r0, #180	@ 0xb4
    beq .Ljp_0809D904
    cmp	r0, #255	@ 0xff
    beq .Ljp_0809D91C
    b .Ljp_0809D7D4
.Ljp_0809D86E:
    ldr r2, .Ljp_0809D880
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #2
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D92C
    b .Ljp_0809D7D4
    .align 2, 0
.Ljp_0809D880:
    .4byte 0x00000624
.Ljp_0809D884:
    ldr r0, .Ljp_0809D898
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #4
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #4
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D898:
    .4byte 0x00000624
.Ljp_0809D89C:
    ldr r2, .Ljp_0809D8B0
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #8
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #8
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D8B0:
    .4byte 0x00000624
.Ljp_0809D8B4:
    ldr r0, .Ljp_0809D8C8
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #16
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D7D4
    movs	r0, #16
    b .Ljp_0809D7C8
    .align 2, 0
.Ljp_0809D8C8:
    .4byte 0x00000624
.Ljp_0809D8CC:
    ldr r2, .Ljp_0809D8D0
    b .Ljp_0809D7BA
.Ljp_0809D8D0:
    .4byte 0x00000624
.Ljp_0809D8D4:
    ldr r0, .Ljp_0809D8E8
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #64	@ 0x40
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D8E4
    b .Ljp_0809D7D4
.Ljp_0809D8E4:
    movs	r0, #64	@ 0x40
    b .Ljp_0809D7C8
.Ljp_0809D8E8:
    .4byte 0x00000624
.Ljp_0809D8EC:
    ldr r2, .Ljp_0809D900
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #128	@ 0x80
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D8FC
    b .Ljp_0809D7D4
.Ljp_0809D8FC:
    movs	r0, #128	@ 0x80
    b .Ljp_0809D7C8
.Ljp_0809D900:
    .4byte 0x00000624
.Ljp_0809D904:
    ldr r0, .Ljp_0809D918
    adds	r1, r5, r0
    ldrb	r2, [r1, #0]
    movs	r0, #1
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D914
    b .Ljp_0809D7D4
.Ljp_0809D914:
    movs	r0, #1
    b .Ljp_0809D7C8
.Ljp_0809D918:
    .4byte 0x00000625
.Ljp_0809D91C:
    ldr r2, .Ljp_0809D930
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #2
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0809D92C
    b .Ljp_0809D7D4
.Ljp_0809D92C:
    movs	r0, #2
    b .Ljp_0809D7C8
.Ljp_0809D930:
    .4byte 0x00000625
.Ljp_0809D934:
    ldr r2, .Ljp_0809D94C
    adds	r1, r5, r2
    ldrb	r2, [r1, #0]
    movs	r0, #8
    ands	r0, r2
    cmp	r0, #0
    bne .Ljp_0809D950
    movs	r0, #8
    orrs	r0, r2
    strb	r0, [r1, #0]
    b .Ljp_0809D954
    .align 2, 0
.Ljp_0809D94C:
    .4byte 0x00000625
.Ljp_0809D950:
    movs	r0, #0
    mov	r8, r0
.Ljp_0809D954:
    mov	r0, r8
    add	sp, #16
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0

    .section .text.code_actor_0809DF2C
    .Lcode_actor_0809DF2C:

    .section .text.code_actor_0809DFAC
    .Lcode_actor_0809DFAC:

    .section .text.code_actor_0809E02C
    .Lcode_actor_0809E02C:

    .section .text.code_actor_0809E0AC

    .section .text.code_actor_0809E118
    .align 2, 0
    .Lcode_actor_0809E118:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    adds	r7, r1, #0
    movs	r6, #0
    b .Ljp_0809DB9A
.Ljp_0809DB5C:
    movs	r4, #0
    adds	r3, r6, #1
    b .Ljp_0809DB8A
.Ljp_0809DB62:
    lsls	r2, r4, #1
    lsls	r0, r6, #3
    subs	r0, r0, r6
    lsls	r0, r0, #3
    adds	r2, r2, r0
    adds	r2, r5, r2
    ldrh	r0, [r2, #4]
    lsls	r0, r0, #22
    lsrs	r0, r0, #26
    adds	r0, r7, r0
    ldrb	r1, [r0, #0]
    adds	r1, #1
    strb	r1, [r0, #0]
    ldrb	r1, [r2, #5]
    lsrs	r1, r1, #2
    adds	r1, r7, r1
    ldrb	r0, [r1, #0]
    adds	r0, #1
    strb	r0, [r1, #0]
    adds	r4, #1
.Ljp_0809DB8A:
    adds	r0, r5, #0
    str	r3, [sp, #0]
    bl func_0809D8A4
    ldr	r3, [sp, #0]
    cmp	r4, r0
    bcc .Ljp_0809DB62
    adds	r6, r3, #0
.Ljp_0809DB9A:
    adds	r0, r5, #0
    bl func_0809D8B8
    cmp	r6, r0
    bcc .Ljp_0809DB5C
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    .section .text.code_actor_0809E174
    .Lcode_actor_0809E174:

    .section .text.code_actor_0809E184
    .Lcode_actor_0809E184:

    .section .text.code_actor_0809E194
    .Lcode_actor_0809E194:

    .section .text.code_actor_0809E1A4
    .Lcode_actor_0809E1A4:

    .section .text.code_actor_0809E1B4
    .align 2, 0
    .Lcode_actor_0809E1B4:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #16
    adds	r7, r0, #0
    adds	r6, r1, #0
    ldr r0, .Ljp_0809DC74
    adds	r5, r2, r0
    mov	r0, sp
    adds	r1, r5, #0
    bl func_0800E924
    mov	r0, sp
    ldrh	r0, [r0, #0]
    lsls	r0, r0, #22
    ldr r1, .Ljp_0809DC78
    cmp	r0, r1
    ble .Ljp_0809DC90
    add	r4, sp, #8
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_0800E924
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r1, .Ljp_0809DC7C
    adds	r4, r0, r1
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_0809D79C
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
    bl func_0809D7D8
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
    .4byte gUnk_08103B38
.Ljp_0809DC84:
    .4byte gUnk_08103B10
.Ljp_0809DC88:
    .4byte gUnk_08103C74
.Ljp_0809DC8C:
    .4byte gUnk_08103C3C
.Ljp_0809DC90:
    add	r4, sp, #8
    adds	r0, r4, #0
    adds	r1, r5, #0
    bl func_0800E924
    ldrh	r0, [r4, #0]
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    adds	r4, r0, #0
    subs	r4, #52	@ 0x34
    adds	r0, r7, #0
    adds	r1, r4, #0
    bl func_0809D418
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
    bl func_0809D470
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
    .4byte gUnk_08103F98
.Ljp_0809DD00:
    .4byte gUnk_08103F84
.Ljp_0809DD04:
    .4byte gUnk_0810400C
.Ljp_0809DD08:
    .4byte gUnk_08103FE4

    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED
    .thumb

.section .text.code_actor_0809C160
.L0809C160:
    @ The dispatcher is byte-identical in the western releases.  Its table
    @ contains only intra-section addresses, so emit real local relocations
    @ instead of retaining US absolute words in the EU/DE builds.
    push {lr}
    adds r0, r1, #0
    bl GetId__C4Tool
    subs r0, #5
    cmp r0, #0x28
    bhi .L0809C160_false
    lsls r0, r0, #2
    ldr r1, .L0809C160_dispatch_table_literal
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
.L0809C160_dispatch_table_literal:
    .4byte .L0809C160_dispatch_table
.L0809C160_dispatch_table:
    .4byte .L0809C160_true
    .4byte .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false
    .4byte .L0809C160_true
    .4byte .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false
    .4byte .L0809C160_true
    .4byte .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false
    .4byte .L0809C160_true
    .4byte .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false
    .4byte .L0809C160_true
    .4byte .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false, .L0809C160_false
    .4byte .L0809C160_true
.L0809C160_true:
    movs r0, #1
    b .L0809C160_return
.L0809C160_false:
    movs r0, #0
.L0809C160_return:
    pop {r1}
    bx r1
    .align 2, 0

    .section .text.code_actor_0809C318
.L0809C318:
    .byte 0x10, 0xB5, 0x04, 0x1C
    bl func_0809C22C
    .byte 0x06, 0x34, 0x24, 0x18, 0x20, 0x78, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

    .section .text.code_actor_0809C38C
.L0809C38C:

    .section .text.code_actor_0809C3BC
.L0809C3BC:

    .section .text.code_actor_0809C3E0
.L0809C3E0:

    .section .text.code_actor_0809C420
.L0809C420:

    .section .text.code_actor_0809C444
.L0809C444:

    .section .text.code_actor_0809C474
.L0809C474:

    .section .text.code_actor_0809C4B4
.L0809C4B4:

    .section .text.code_actor_0809C4E4
.L0809C4E4:

    .section .text.code_actor_0809C4EC
.L0809C4EC:
    .byte 0x00, 0xB5, 0x03, 0x1C
    .byte 0x00, 0x22, 0x0D, 0x29, 0x08, 0xD8, 0x1F, 0x20, 0x08, 0x40, 0x01, 0x22, 0x82, 0x40, 0x19, 0x68
    .byte 0x11, 0x40, 0x48, 0x42, 0x08, 0x43, 0xC2, 0x0F, 0x01, 0x20, 0x50, 0x40, 0x02, 0xBC, 0x08, 0x47

    thumb_func_start func_0809C510
func_0809C510: @ 0x0809C510
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r4, r2, #0
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    adds r6, r3, #0
    movs r0, #0
    cmp r4, #0xd
    bhi .L0809C534
    movs r0, #0x1f
    ands r0, r4
    movs r2, #1
    lsls r2, r0
    ldr r1, [r1]
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
.L0809C534:
    cmp r0, #0
    beq .L0809C574
    cmp r4, #0xd
    bne .L0809C554
    cmp r3, #0
    beq .L0809C554
    ldr r0, .L0809C54C @ =gActorDataSelectionEntries
    adds r0, #0x9c
    ldrb r1, [r0, #8]
    ldrb r2, [r0, #9]
    ldr r0, .L0809C550 @ =gFieldRenderRectDescriptors + 0x780
    b .L0809C5A0
    .align 2, 0
.L0809C54C: .4byte gActorDataSelectionEntries
.L0809C550: .4byte gFieldRenderRectDescriptors + 0x780
.L0809C554:
    ldr r2, .L0809C570 @ =gActorDataSelectionEntries
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    adds r1, r2, #4
    adds r1, r0, r1
    adds r0, r0, r2
    ldrb r2, [r0, #8]
    ldrb r3, [r0, #9]
    ldr r0, [r1]
    str r0, [r5]
    str r2, [r5, #4]
    str r3, [r5, #8]
    b .L0809C5A6
    .align 2, 0
.L0809C570: .4byte gActorDataSelectionEntries
.L0809C574:
    cmp r4, #0xd
    bne .L0809C590
    cmp r6, #0
    beq .L0809C590
    ldr r0, .L0809C588 @ =gActorDataSelectionEntries
    adds r0, #0x9c
    ldrb r1, [r0, #8]
    ldrb r2, [r0, #9]
    ldr r0, .L0809C58C @ =gFieldRenderRectDescriptors + 0x768
    b .L0809C5A0
    .align 2, 0
.L0809C588: .4byte gActorDataSelectionEntries
.L0809C58C: .4byte gFieldRenderRectDescriptors + 0x768
.L0809C590:
    ldr r1, .L0809C5B0 @ =gActorDataSelectionEntries
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r0, #8]
    ldrb r2, [r0, #9]
    ldr r0, [r0]
.L0809C5A0:
    str r0, [r5]
    str r1, [r5, #4]
    str r2, [r5, #8]
.L0809C5A6:
    adds r0, r5, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
.L0809C5B0: .4byte gActorDataSelectionEntries

    .section .text.code_actor_0809C5B4
.L0809C5B4:

    .section .text.code_actor_0809C5D0
.L0809C5D0:

    .section .text.code_actor_0809C5EC
.L0809C5EC:

    .section .text.code_actor_0809C5F4
.L0809C5F4:

    .section .text.code_actor_0809C600
.L0809C600:

    .section .text.code_actor_0809C644

    thumb_func_start func_0809C644
func_0809C644: @ 0x0809C644
    push {r4, r5, lr}
    sub sp, #4
    adds r5, r0, #0
    mov r0, sp
    strh r1, [r0]
    adds r0, r5, #4
    ldr r4, [r5]
    lsls r4, r4, #1
    adds r4, #4
    adds r4, r5, r4
    adds r1, r4, #0
    mov r2, sp
    bl func_080E3E28
    adds r3, r0, #0
    cmp r3, r4
    beq .L0809C68A
    ldr r0, [r5]
    cmp r0, #0
    beq .L0809C68A
    lsls r0, r0, #1
    adds r0, #4
    adds r0, r5, r0
    adds r1, r3, #2
    cmp r1, r0
    beq .L0809C684
    cmp r0, r1
    beq .L0809C684
    subs r2, r0, r1
    adds r0, r3, #0
    bl memmove
.L0809C684:
    ldr r0, [r5]
    subs r0, #1
    str r0, [r5]
.L0809C68A:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    .section .text.code_actor_0809C694
.L0809C694:

    .section .text.code_actor_0809C6AC
.L0809C6AC:

    .section .text.code_actor_0809C6B0
.L0809C6B0:

    .section .text.code_actor_0809C6BC
.L0809C6BC:
    thumb_func_start func_0809C6BC
func_0809C6BC: @ 0x0809C6BC
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r7, r0, #0
    movs r0, #0
    str r0, [r7]
    ldr r0, .L0809CAB8 @ =0x0000FFFF
    strh r0, [r7, #0xc]
    movs r5, #7
    rsbs r5, r5, #0
    movs r0, #0
    strb r0, [r7, #0xe]
    subs r0, #3
    mov sb, r0
    movs r4, #0x19
    rsbs r4, r4, #0
    movs r0, #0
    strb r0, [r7, #0xf]
    strb r0, [r7, #0x10]
    ldrb r1, [r7, #0x11]
    subs r0, #2
    ands r0, r1
    mov r1, sb
    ands r0, r1
    movs r2, #5
    rsbs r2, r2, #0
    ands r0, r2
    movs r1, #9
    rsbs r1, r1, #0
    ands r0, r1
    subs r2, #0xc
    ands r0, r2
    movs r3, #0x61
    rsbs r3, r3, #0
    ands r0, r3
    strb r0, [r7, #0x11]
    ldr r0, [r7, #0x10]
    ldr r1, .L0809CABC @ =0xFFFE7FFF
    mov r8, r1
    ands r0, r1
    str r0, [r7, #0x10]
    ldrb r1, [r7, #0x12]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x12]
    ldrh r1, [r7, #0x12]
    ldr r6, .L0809CAC0 @ =0xFFFFFE7F
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x12]
    ldrb r1, [r7, #0x13]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r2, #0x7f
    ands r0, r2
    strb r0, [r7, #0x13]
    ldrb r1, [r7, #0x14]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x14]
    ldrh r1, [r7, #0x14]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x14]
    ldrb r1, [r7, #0x15]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x15]
    ldr r0, [r7, #0x14]
    mov r1, r8
    ands r0, r1
    str r0, [r7, #0x14]
    ldrb r1, [r7, #0x16]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x16]
    ldrh r1, [r7, #0x16]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x16]
    ldrb r1, [r7, #0x17]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    ands r0, r2
    strb r0, [r7, #0x17]
    ldrb r1, [r7, #0x18]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x18]
    ldrh r1, [r7, #0x18]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x18]
    ldrb r1, [r7, #0x19]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x19]
    ldr r0, [r7, #0x18]
    mov r2, r8
    ands r0, r2
    str r0, [r7, #0x18]
    ldrb r1, [r7, #0x1a]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x1a]
    ldrh r1, [r7, #0x1a]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x1a]
    ldrb r1, [r7, #0x1b]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r7, #0x1b]
    ldrb r1, [r7, #0x1c]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x1c]
    ldrh r1, [r7, #0x1c]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x1c]
    ldrb r1, [r7, #0x1d]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x1d]
    ldr r0, [r7, #0x1c]
    ands r0, r2
    str r0, [r7, #0x1c]
    ldrb r1, [r7, #0x1e]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r7, #0x1e]
    ldrh r1, [r7, #0x1e]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x1e]
    ldrb r1, [r7, #0x1f]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r2, #0x7f
    ands r0, r2
    strb r0, [r7, #0x1f]
    adds r2, r7, #0
    adds r2, #0x20
    ldrb r1, [r2]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x20]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x20]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldr r0, [r7, #0x20]
    mov r1, r8
    ands r0, r1
    str r0, [r7, #0x20]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x20
    ands r0, r1
    strb r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #0xf
    ands r0, r1
    strb r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #8
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x24]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x24]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x26
    movs r2, #4
    rsbs r2, r2, #0
    mov sl, r2
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, r7, #0
    adds r2, #0x2a
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x2a]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x2a]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    movs r1, #9
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x28
    ands r0, r1
    movs r1, #0x3f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x2c
    movs r0, #0
    strb r0, [r1]
    adds r2, #2
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #0xd
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x24
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r7, #0x2c]
    ldr r2, .L0809CAC4 @ =0xFFFC3FFF
    mov ip, r2
    ands r0, r2
    str r0, [r7, #0x2c]
    adds r2, r7, #0
    adds r2, #0x2e
    ldrb r1, [r2]
    movs r0, #5
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x2f
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, #8
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #5
    rsbs r1, r1, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x36]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x36]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x38
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, #3
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #0x1d
    rsbs r1, r1, #0
    ands r0, r1
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x3a]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r7, #0x3a]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r7, #0x3c]
    ldr r0, .L0809CAC8 @ =0xFFFFFC7F
    ands r0, r1
    strh r0, [r7, #0x3c]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x31
    rsbs r1, r1, #0
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r7, #0x3c]
    mov r2, ip
    ands r0, r2
    str r0, [r7, #0x3c]
    adds r2, r7, #0
    adds r2, #0x3e
    ldrb r1, [r2]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x31
    rsbs r1, r1, #0
    ands r0, r1
    movs r1, #0x3f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x3f
    movs r0, #0
    strb r0, [r1]
    adds r2, #2
    ldrb r1, [r2]
    subs r0, #2
    ands r0, r1
    ands r0, r5
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    strb r0, [r2]
    ldr r0, [r7, #0x40]
    ldr r1, .L0809CACC @ =0xFFFE1FFF
    ands r0, r1
    str r0, [r7, #0x40]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r0, r1
    movs r1, #0x3f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x43
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, #0xb
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #5
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #4
    ands r0, r1
    subs r1, #8
    ands r0, r1
    subs r1, #0x10
    ands r0, r1
    subs r1, #0x20
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r7, #0x4c]
    mov r2, r8
    ands r0, r2
    str r0, [r7, #0x4c]
    adds r2, r7, #0
    adds r2, #0x4e
    ldrb r1, [r2]
    mov r0, sb
    ands r0, r1
    movs r1, #0xd
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #4
    ands r0, r1
    ands r0, r3
    strb r0, [r2]
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    b .L0809CAD0
    .align 2, 0
.L0809CAB8: .4byte 0x0000FFFF
.L0809CABC: .4byte 0xFFFE7FFF
.L0809CAC0: .4byte 0xFFFFFE7F
.L0809CAC4: .4byte 0xFFFC3FFF
.L0809CAC8: .4byte 0xFFFFFC7F
.L0809CACC: .4byte 0xFFFE1FFF
.L0809CAD0:
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x31
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x10
    ands r0, r1
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x50
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, #3
    ldrb r1, [r2]
    subs r0, #2
    ands r0, r1
    ands r0, r5
    movs r1, #9
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x28
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    ldr r0, .L0809CD5C @ =0xFFFFFE3F
    ands r0, r1
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    movs r1, #9
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x28
    ands r0, r1
    movs r1, #0x3f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x54
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    movs r2, #0x3f
    mov r8, r2
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, r7, #0
    adds r2, #0x59
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #5
    rsbs r1, r1, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    strb r0, [r2]
    ldr r0, [r7, #0x58]
    ldr r1, .L0809CD60 @ =0xFFFC7FFF
    ands r0, r1
    str r0, [r7, #0x58]
    adds r1, r7, #0
    adds r1, #0x5a
    ldrh r0, [r1]
    ands r6, r0
    strh r6, [r1]
    adds r2, #2
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    ands r0, r4
    ands r0, r3
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x5c
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #1
    ldrb r0, [r1]
    mov r2, sl
    ands r2, r0
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r2, r0
    subs r0, #0x24
    ands r2, r0
    strb r2, [r1]
    ldrh r2, [r1]
    ldr r3, .L0809CD64 @ =0xFFFFC03F
    adds r0, r3, #0
    ands r0, r2
    strh r0, [r1]
    ldr r0, [r7, #0x68]
    ldr r6, .L0809CD68 @ =0xFFC03FFF
    ands r0, r6
    str r0, [r7, #0x68]
    adds r2, r7, #0
    adds r2, #0x6a
    ldrh r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    mov r0, r8
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x6c
    ldrb r2, [r1]
    subs r4, #0x27
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1]
    ldrh r2, [r1]
    adds r0, r3, #0
    ands r0, r2
    strh r0, [r1]
    ldr r0, [r7, #0x6c]
    ands r0, r6
    str r0, [r7, #0x6c]
    adds r2, r7, #0
    adds r2, #0x6e
    ldrh r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    mov r0, r8
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x70
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1]
    ldrh r2, [r1]
    adds r0, r3, #0
    ands r0, r2
    strh r0, [r1]
    ldr r0, [r7, #0x70]
    ands r0, r6
    str r0, [r7, #0x70]
    adds r1, #2
    ldrh r0, [r1]
    ands r3, r0
    strh r3, [r1]
    adds r1, #1
    ldrb r0, [r1]
    mov r2, r8
    ands r2, r0
    strb r2, [r1]
    adds r1, #1
    ldrb r0, [r1]
    ands r4, r0
    strb r4, [r1]
    ldrh r2, [r1]
    ldr r0, .L0809CD5C @ =0xFFFFFE3F
    ands r0, r2
    strh r0, [r1]
    adds r1, #1
    ldrb r0, [r1]
    ands r5, r0
    movs r0, #9
    rsbs r0, r0, #0
    ands r5, r0
    movs r2, #0x11
    rsbs r2, r2, #0
    ands r5, r2
    subs r0, #0x18
    ands r5, r0
    subs r2, #0x30
    ands r5, r2
    movs r0, #0x7f
    ands r5, r0
    strb r5, [r1]
    adds r2, r7, #0
    adds r2, #0x76
    ldrb r1, [r2]
    subs r0, #0x81
    ands r0, r1
    mov r1, sb
    ands r0, r1
    movs r1, #5
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #4
    ands r0, r1
    subs r1, #8
    ands r0, r1
    subs r1, #0x10
    ands r0, r1
    subs r1, #0x20
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    ldr r0, .L0809CD6C @ =0xFFFFF87F
    ands r0, r1
    strh r0, [r2]
    adds r2, #1
    ldrb r1, [r2]
    movs r0, #0x79
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r1, r7, #0
    adds r1, #0x78
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r2, #3
    ldrb r0, [r2]
    movs r1, #2
    rsbs r1, r1, #0
    ands r1, r0
    strb r1, [r2]
    ldrh r1, [r2]
    ldr r0, .L0809CD70 @ =0xFFFFFE01
    ands r0, r1
    strh r0, [r2]
    adds r1, r7, #0
    adds r1, #0x7b
    ldrb r0, [r1]
    mov r2, sb
    ands r2, r0
    movs r0, #5
    rsbs r0, r0, #0
    ands r2, r0
    movs r6, #9
    rsbs r6, r6, #0
    ands r2, r6
    movs r5, #0x11
    rsbs r5, r5, #0
    ands r2, r5
    movs r4, #0x21
    rsbs r4, r4, #0
    ands r2, r4
    movs r3, #0x41
    rsbs r3, r3, #0
    ands r2, r3
    movs r0, #0x7f
    ands r2, r0
    strb r2, [r1]
    adds r1, #1
    movs r2, #5
    rsbs r2, r2, #0
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    movs r1, #0x7e
    adds r1, r1, r7
    mov r8, r1
    ldrb r1, [r1]
    subs r0, #4
    ands r0, r1
    ands r0, r2
    ands r0, r6
    ands r0, r5
    ands r0, r4
    ands r0, r3
    mov r2, r8
    strb r0, [r2]
    ldrh r1, [r2]
    ldr r0, .L0809CD74 @ =0xFFFFFC7F
    ands r0, r1
    strh r0, [r2]
    adds r2, r7, #0
    adds r2, #0x7f
    ldrb r1, [r2]
    movs r0, #3
    ands r0, r1
    strb r0, [r2]
    adds r0, r7, #0
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0809CD5C: .4byte 0xFFFFFE3F
.L0809CD60: .4byte 0xFFFC7FFF
.L0809CD64: .4byte 0xFFFFC03F
.L0809CD68: .4byte 0xFFC03FFF
.L0809CD6C: .4byte 0xFFFFF87F
.L0809CD70: .4byte 0xFFFFFE01
.L0809CD74: .4byte 0xFFFFFC7F

    .section .text.code_actor_0809CD78

    .section .text.code_actor_0809CD98
.L0809CD98:

    .section .text.code_actor_0809CDCC
.L0809CDCC:

    .section .text.code_actor_0809CDEC
.L0809CDEC:

    .section .text.code_actor_0809CE1C
.L0809CE1C:

    .section .text.code_actor_0809CE24
.L0809CE24:

    .section .text.code_actor_0809CE30
.L0809CE30:
    .section .text.code_actor_0809CE30
.L0809CE30:

    .section .text.code_actor_0809CE7C
.L0809CE7C:

    .section .text.code_actor_0809CE8C
.L0809CE8C:
    thumb_func_start func_0809CE8C
func_0809CE8C: @ 0x0809CE8C
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r7, r0, #0
    movs r0, #0
    str r0, [r7]
    ldr r0, .L0809CF24 @ =0x00000624
    adds r2, r7, r0
    movs r0, #2
    rsbs r0, r0, #0
    movs r3, #3
    rsbs r3, r3, #0
    movs r4, #5
    rsbs r4, r4, #0
    movs r5, #9
    rsbs r5, r5, #0
    movs r6, #0x11
    rsbs r6, r6, #0
    movs r1, #0x21
    rsbs r1, r1, #0
    mov r8, r1
    movs r1, #0
    strb r1, [r2]
    ldr r1, .L0809CF28 @ =0x00000625
    adds r2, r7, r1
    movs r1, #0
    strb r1, [r2]
    ldr r1, .L0809CF2C @ =0x00000626
    adds r2, r7, r1
    ldrb r1, [r2]
    ands r0, r1
    ands r0, r3
    ands r0, r4
    ands r0, r5
    ands r0, r6
    mov r1, r8
    ands r0, r1
    strb r0, [r2]
    movs r0, #0
    movs r1, #0x10
    rsbs r1, r1, #0
    mov r8, r1
    ldr r6, .L0809CF30 @ =0xFFFFFC0F
    movs r5, #3
.L0809CEE4:
    movs r3, #0
    lsls r1, r0, #3
    adds r4, r0, #1
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r0, r7, #4
    adds r2, r1, r0
.L0809CEF2:
    ldrb r1, [r2]
    mov r0, r8
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    strh r0, [r2]
    ldrb r1, [r2, #1]
    adds r0, r5, #0
    ands r0, r1
    strb r0, [r2, #1]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x1b
    bls .L0809CEF2
    adds r0, r4, #0
    cmp r0, #0x1b
    bls .L0809CEE4
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0809CF24: .4byte 0x00000624
.L0809CF28: .4byte 0x00000625
.L0809CF2C: .4byte 0x00000626
.L0809CF30: .4byte 0xFFFFFC0F

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
    bl func_0809D8A4
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
    bl func_0809D8B8
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
    bl func_0809D8A4
    str r0, [sp, #0xc]
    mov r0, sl
    bl func_0809D8B8
    str r0, [sp, #0x10]
    mov r0, sl
    ldr r1, [sp]
    bl func_0809D418
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
    ldr r4, .L0809D268 @ =gUnk_08103F98
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
    ldr r1, .L0809D26C @ =gUnk_08103F84
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
.L0809D268: .4byte gUnk_08103F98
.L0809D26C: .4byte gUnk_08103F84
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
    bl func_0809D470
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
    ldr r1, .L0809D368 @ =gUnk_08103FE4
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
.L0809D368: .4byte gUnk_08103FE4
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
    ldr r1, .L0809D414 @ =gUnk_0810400C
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
.L0809D414: .4byte gUnk_0810400C

    .section .text.code_actor_0809D418

    .section .text.code_actor_0809D470
    thumb_func_start func_0809D470
func_0809D470: @ 0x0809D470
    push {lr}
    cmp r1, #0x98
    beq .L0809D4D2
    cmp r1, #0x98
    bhi .L0809D4A0
    cmp r1, #0x28
    beq .L0809D4CE
    cmp r1, #0x28
    bhi .L0809D48C
    cmp r1, #0x14
    beq .L0809D4C6
    cmp r1, #0x1e
    beq .L0809D4CA
    b .L0809D4DA
.L0809D48C:
    cmp r1, #0x66
    beq .L0809D4D2
    cmp r1, #0x66
    bhi .L0809D49A
    cmp r1, #0x3c
    beq .L0809D4D2
    b .L0809D4DA
.L0809D49A:
    cmp r1, #0x7b
    beq .L0809D4D2
    b .L0809D4DA
.L0809D4A0:
    cmp r1, #0xbe
    beq .L0809D4D2
    cmp r1, #0xbe
    bhi .L0809D4B2
    cmp r1, #0x9b
    beq .L0809D4D2
    cmp r1, #0xab
    beq .L0809D4D2
    b .L0809D4DA
.L0809D4B2:
    cmp r1, #0xde
    beq .L0809D4D2
    cmp r1, #0xde
    bhi .L0809D4C0
    cmp r1, #0xca
    beq .L0809D4D2
    b .L0809D4DA
.L0809D4C0:
    cmp r1, #0xff
    beq .L0809D4D6
    b .L0809D4DA
.L0809D4C6:
    movs r0, #0xc
    b .L0809D4FA
.L0809D4CA:
    movs r0, #0xe
    b .L0809D4FA
.L0809D4CE:
    movs r0, #0x10
    b .L0809D4FA
.L0809D4D2:
    movs r0, #0x12
    b .L0809D4FA
.L0809D4D6:
    movs r0, #0x14
    b .L0809D4FA
.L0809D4DA:
    adds r0, r1, #0
    cmp r0, #0xa
    bls .L0809D4FA
    movs r0, #0xb
    cmp r1, #0x13
    bls .L0809D4FA
    movs r0, #0xd
    cmp r1, #0x1d
    bls .L0809D4FA
    movs r0, #0xf
    cmp r1, #0x27
    bls .L0809D4FA
    movs r0, #0x13
    cmp r1, #0xe6
    bhi .L0809D4FA
    movs r0, #0x11
.L0809D4FA:
    pop {r1}
    bx r1
    .align 2, 0

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
    bl func_0809D8A4
    str r0, [sp, #0xc]
    mov r0, sl
    bl func_0809D8B8
    str r0, [sp, #0x10]
    mov r0, sl
    ldr r1, [sp]
    bl func_0809D79C
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
    ldr r1, .L0809D5F8 @ =gUnk_08103B38
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
    ldr r1, .L0809D5FC @ =gUnk_08103B10
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
.L0809D5F8: .4byte gUnk_08103B38
.L0809D5FC: .4byte gUnk_08103B10
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
    bl func_0809D7D8
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
    ldr r1, .L0809D6F8 @ =gUnk_08103C3C
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
.L0809D6F8: .4byte gUnk_08103C3C
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
    ldr r1, .L0809D798 @ =gUnk_08103C74
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
.L0809D798: .4byte gUnk_08103C74

    thumb_func_start func_0809D79C
func_0809D79C: @ 0x0809D79C
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

    .section .text.code_actor_0809D7D8

    .section .text.code_actor_0809D8A0
.L0809D8A0:

    .section .text.code_actor_0809D8A4
.L0809D8A4:

    .section .text.code_actor_0809D8B8
.L0809D8B8:

    .section .text.code_actor_0809D8D4
.L0809D8D4:

    .section .text.code_actor_0809D8E8
    thumb_func_start func_0809D8E8
func_0809D8E8: @ 0x0809D8E8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r6, r0, #0
    mov sl, r2
    adds r2, r3, #0
    movs r0, #0
    str r0, [sp]
    lsls r7, r1, #1
    mov r1, sl
    lsls r3, r1, #3
    subs r0, r3, r1
    lsls r0, r0, #3
    adds r0, r7, r0
    adds r4, r6, r0
    ldrb r0, [r4, #4]
    lsls r0, r0, #0x1c
    cmp r0, #0
    bne .L0809D9A2
    ldrb r1, [r4, #5]
    lsrs r1, r1, #2
    adds r0, r6, #0
    str r3, [sp, #4]
    bl func_0809DA00
    str r0, [sp]
    ldr r3, [sp, #4]
    cmp r0, #1
    bne .L0809D97C
    ldrb r0, [r4, #4]
    movs r1, #0x10
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #2
    orrs r1, r0
    strb r1, [r4, #4]
    movs r2, #0
    str r2, [sp]
    movs r5, #0
    mov sb, r7
    mov r8, r3
    b .L0809D970
.L0809D942:
    movs r4, #0
    adds r7, r5, #1
    b .L0809D964
.L0809D948:
    lsls r0, r4, #1
    lsls r1, r5, #3
    subs r1, r1, r5
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r2, r6, r0
    ldrb r1, [r2, #5]
    lsrs r0, r1, #2
    cmp r0, #1
    bne .L0809D962
    movs r0, #3
    ands r0, r1
    strb r0, [r2, #5]
.L0809D962:
    adds r4, #1
.L0809D964:
    adds r0, r6, #0
    bl func_0809D8A4
    cmp r4, r0
    blt .L0809D948
    adds r5, r7, #0
.L0809D970:
    adds r0, r6, #0
    bl func_0809D8B8
    cmp r5, r0
    blt .L0809D942
    b .L0809D98E
.L0809D97C:
    ldrb r0, [r4, #4]
    movs r1, #0x10
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    strb r1, [r4, #4]
    mov sb, r7
    mov r8, r3
.L0809D98E:
    mov r1, r8
    mov r2, sl
    subs r0, r1, r2
    lsls r0, r0, #3
    add r0, sb
    adds r0, r6, r0
    ldrb r2, [r0, #5]
    movs r1, #3
    ands r1, r2
    strb r1, [r0, #5]
.L0809D9A2:
    ldr r0, [sp]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start func_0809D9B4
func_0809D9B4: @ 0x0809D9B4
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    movs r6, #0
    lsls r1, r1, #1
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r1, r1, r0
    adds r4, r5, r1
    ldrb r0, [r4, #4]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1c
    cmp r0, #4
    bne .L0809D9F2
    ldrh r1, [r4, #4]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x1a
    adds r0, r5, #0
    adds r2, r3, #0
    bl func_0809DA00
    adds r6, r0, #0
    ldrb r1, [r4, #4]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #4]
    ldrh r1, [r4, #4]
    ldr r0, .L0809D9FC @ =0xFFFFFC0F
    ands r0, r1
    strh r0, [r4, #4]
.L0809D9F2:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
.L0809D9FC: .4byte 0xFFFFFC0F

    thumb_func_start func_0809DA00
func_0809DA00: @ 0x0809DA00
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x10
    adds r5, r0, #0
    mov r8, r1
    adds r6, r2, #0
    mov r0, r8
    subs r0, #3
    cmp r0, #0x1f
    bls .L0809DA18
    b .L0809DF1C
.L0809DA18:
    lsls r0, r0, #2
    ldr r1, .L0809DA24 @ =.L0809DA28
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0809DA24: .4byte .L0809DA28
.L0809DA28: @ jump table
    .4byte .L0809DAA8 @ case 0
    .4byte .L0809DB02 @ case 1
    .4byte .L0809DB02 @ case 2
    .4byte .L0809DB02 @ case 3
    .4byte .L0809DB02 @ case 4
    .4byte .L0809DB02 @ case 5
    .4byte .L0809DB02 @ case 6
    .4byte .L0809DB9C @ case 7
    .4byte .L0809DF1C @ case 8
    .4byte .L0809DF1C @ case 9
    .4byte .L0809DF1C @ case 10
    .4byte .L0809DF1C @ case 11
    .4byte .L0809DF1C @ case 12
    .4byte .L0809DF1C @ case 13
    .4byte .L0809DF1C @ case 14
    .4byte .L0809DF1C @ case 15
    .4byte .L0809DF1C @ case 16
    .4byte .L0809DF1C @ case 17
    .4byte .L0809DF1C @ case 18
    .4byte .L0809DF1C @ case 19
    .4byte .L0809DBFC @ case 20
    .4byte .L0809DF1C @ case 21
    .4byte .L0809DF1C @ case 22
    .4byte .L0809DF1C @ case 23
    .4byte .L0809DF1C @ case 24
    .4byte .L0809DF1C @ case 25
    .4byte .L0809DF1C @ case 26
    .4byte .L0809DF1C @ case 27
    .4byte .L0809DF1C @ case 28
    .4byte .L0809DC36 @ case 29
    .4byte .L0809DDA6 @ case 30
    .4byte .L0809DEFC @ case 31
.L0809DAA8:
    ldr r0, .L0809DAD4 @ =0x00001BD8
    adds r1, r6, r0
    mov r0, sp
    bl func_0800E924
    mov r0, sp
    ldrh r0, [r0]
    lsls r0, r0, #0x16
    ldr r1, .L0809DAD8 @ =0x4CC00000
    cmp r0, r1
    bgt .L0809DAE0
    ldr r1, .L0809DADC @ =0x00000625
    adds r2, r5, r1
    ldrb r1, [r2]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq .L0809DACE
    b .L0809DC30
.L0809DACE:
    movs r0, #4
    b .L0809DAF0
    .align 2, 0
.L0809DAD4: .4byte 0x00001BD8
.L0809DAD8: .4byte 0x4CC00000
.L0809DADC: .4byte 0x00000625
.L0809DAE0:
    ldr r0, .L0809DAF8 @ =0x00000624
    adds r2, r5, r0
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne .L0809DAFC
    movs r0, #1
.L0809DAF0:
    orrs r0, r1
    strb r0, [r2]
    b .L0809DF1C
    .align 2, 0
.L0809DAF8: .4byte 0x00000624
.L0809DAFC:
    movs r1, #0
    mov r8, r1
    b .L0809DF1C
.L0809DB02:
    movs r4, #0
    ldr r2, .L0809DB50 @ =0x00001C38
    adds r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, r1
    bne .L0809DB16
    movs r4, #1
.L0809DB16:
    ldr r1, .L0809DB54 @ =0x00001DAC
    adds r0, r6, r1
    bl func_0809ED04
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0809DB26
    movs r4, #1
.L0809DB26:
    adds r0, r5, #0
    mov r1, r8
    adds r2, r6, #0
    bl func_0809DF2C
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0809DB38
    movs r4, #1
.L0809DB38:
    cmp r4, #1
    beq .L0809DC30
    movs r1, #0x51
    mov r0, r8
    subs r0, #4
    cmp r0, #5
    bhi .L0809DB8A
    lsls r0, r0, #2
    ldr r1, .L0809DB58 @ =.L0809DB5C
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0809DB50: .4byte 0x00001C38
.L0809DB54: .4byte 0x00001DAC
.L0809DB58: .4byte .L0809DB5C
.L0809DB5C: @ jump table
    .4byte .L0809DB74 @ case 0
    .4byte .L0809DB78 @ case 1
    .4byte .L0809DB7C @ case 2
    .4byte .L0809DB80 @ case 3
    .4byte .L0809DB84 @ case 4
    .4byte .L0809DB88 @ case 5
.L0809DB74:
    movs r1, #5
    b .L0809DB8A
.L0809DB78:
    movs r1, #0xd
    b .L0809DB8A
.L0809DB7C:
    movs r1, #0x15
    b .L0809DB8A
.L0809DB80:
    movs r1, #0x1d
    b .L0809DB8A
.L0809DB84:
    movs r1, #0x25
    b .L0809DB8A
.L0809DB88:
    movs r1, #0x2d
.L0809DB8A:
    cmp r1, #0x51
    bne .L0809DB90
    b .L0809DF1C
.L0809DB90:
    movs r2, #0xd2
    lsls r2, r2, #6
    adds r0, r6, r2
    bl func_0809C3BC
    b .L0809DF1C
.L0809DB9C:
    movs r7, #0
    movs r3, #0xc8
    str r3, [sp, #8]
    ldrb r0, [r6, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #0xc]
    add r2, sp, #0xc
    add r0, sp, #8
    cmp r3, r1
    bls .L0809DBBC
    adds r0, r2, #0
.L0809DBBC:
    ldr r0, [r0]
    cmp r0, #2
    bhi .L0809DBC4
    movs r7, #1
.L0809DBC4:
    ldr r0, .L0809DBF4 @ =0x00000625
    adds r4, r5, r0
    ldrb r1, [r4]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq .L0809DBD4
    movs r7, #1
.L0809DBD4:
    ldr r1, .L0809DBF8 @ =0x00001C38
    adds r0, r6, r1
    bl GetFirstFreeToolSlot__C8Rucksack
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, r1
    bne .L0809DBE6
    movs r7, #1
.L0809DBE6:
    cmp r7, #0
    bne .L0809DC30
    ldrb r0, [r4]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r4]
    b .L0809DF1C
    .align 2, 0
.L0809DBF4: .4byte 0x00000625
.L0809DBF8: .4byte 0x00001C38
.L0809DBFC:
    movs r7, #0
    movs r1, #0xd2
    lsls r1, r1, #6
    adds r0, r6, r1
    bl func_0809C38C
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0809DC10
    movs r7, #1
.L0809DC10:
    movs r4, #4
.L0809DC12:
    adds r0, r5, #0
    adds r1, r4, #0
    adds r2, r6, #0
    bl func_0809DF2C
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0809DC24
    movs r7, #1
.L0809DC24:
    adds r4, #1
    cmp r4, #9
    ble .L0809DC12
    cmp r7, #1
    beq .L0809DC30
    b .L0809DF1C
.L0809DC30:
    movs r2, #0
    mov r8, r2
    b .L0809DF1C
.L0809DC36:
    movs r4, #0
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    bl GetShelf__9FarmHouse
    cmp r0, #0
    bne .L0809DC48
    movs r4, #1
.L0809DC48:
    adds r0, r5, #0
    bl func_0809DFAC
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #8
    bne .L0809DC68
    ldr r2, .L0809DC98 @ =0x00001C38
    adds r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, r1
    bne .L0809DC68
    movs r4, #1
.L0809DC68:
    cmp r4, #0
    beq .L0809DC6E
    b .L0809DD9E
.L0809DC6E:
    ldr r0, .L0809DC9C @ =0x00001BD8
    adds r1, r6, r0
    mov r0, sp
    bl func_0800E924
    mov r0, sp
    ldrh r0, [r0]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    subs r0, #0x34
    cmp r0, #0x9b
    beq .L0809DD20
    cmp r0, #0x9b
    bgt .L0809DCAA
    cmp r0, #0x66
    beq .L0809DCD8
    cmp r0, #0x66
    bgt .L0809DCA0
    cmp r0, #0x3c
    beq .L0809DCC2
    b .L0809DD9C
    .align 2, 0
.L0809DC98: .4byte 0x00001C38
.L0809DC9C: .4byte 0x00001BD8
.L0809DCA0:
    cmp r0, #0x7b
    beq .L0809DCF0
    cmp r0, #0x98
    beq .L0809DD08
    b .L0809DD9C
.L0809DCAA:
    cmp r0, #0xbe
    beq .L0809DD50
    cmp r0, #0xbe
    bgt .L0809DCB8
    cmp r0, #0xab
    beq .L0809DD38
    b .L0809DD9C
.L0809DCB8:
    cmp r0, #0xca
    beq .L0809DD68
    cmp r0, #0xde
    beq .L0809DD80
    b .L0809DD9C
.L0809DCC2:
    ldr r2, .L0809DCD4 @ =0x00000625
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq .L0809DD8E
    b .L0809DD9C
    .align 2, 0
.L0809DCD4: .4byte 0x00000625
.L0809DCD8:
    ldr r0, .L0809DCEC @ =0x00000625
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #0x40
    b .L0809DD90
    .align 2, 0
.L0809DCEC: .4byte 0x00000625
.L0809DCF0:
    ldr r2, .L0809DD04 @ =0x00000625
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #0x80
    b .L0809DD90
    .align 2, 0
.L0809DD04: .4byte 0x00000625
.L0809DD08:
    ldr r0, .L0809DD1C @ =0x00000626
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #1
    b .L0809DD90
    .align 2, 0
.L0809DD1C: .4byte 0x00000626
.L0809DD20:
    ldr r2, .L0809DD34 @ =0x00000626
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #2
    b .L0809DD90
    .align 2, 0
.L0809DD34: .4byte 0x00000626
.L0809DD38:
    ldr r0, .L0809DD4C @ =0x00000626
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #4
    b .L0809DD90
    .align 2, 0
.L0809DD4C: .4byte 0x00000626
.L0809DD50:
    ldr r2, .L0809DD64 @ =0x00000626
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #8
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #8
    b .L0809DD90
    .align 2, 0
.L0809DD64: .4byte 0x00000626
.L0809DD68:
    ldr r0, .L0809DD7C @ =0x00000626
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #0x10
    b .L0809DD90
    .align 2, 0
.L0809DD7C: .4byte 0x00000626
.L0809DD80:
    ldr r2, .L0809DD98 @ =0x00000626
.L0809DD82:
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
.L0809DD8E:
    movs r0, #0x20
.L0809DD90:
    orrs r0, r2
    strb r0, [r1]
    b .L0809DD9E
    .align 2, 0
.L0809DD98: .4byte 0x00000626
.L0809DD9C:
    movs r4, #1
.L0809DD9E:
    cmp r4, #1
    beq .L0809DDA4
    b .L0809DF1C
.L0809DDA4:
    b .L0809DF18
.L0809DDA6:
    movs r4, #0
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    bl GetShelf__9FarmHouse
    cmp r0, #0
    bne .L0809DDB8
    movs r4, #1
.L0809DDB8:
    adds r0, r5, #0
    bl func_0809E02C
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #8
    bne .L0809DDD8
    ldr r2, .L0809DE08 @ =0x00001C38
    adds r0, r6, r2
    bl GetFirstFreeToolSlot__C8Rucksack
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, r1
    bne .L0809DDD8
    movs r4, #1
.L0809DDD8:
    cmp r4, #0
    bne .L0809DD9E
    ldr r0, .L0809DE0C @ =0x00001BD8
    adds r1, r6, r0
    mov r0, sp
    bl func_0800E924
    mov r0, sp
    ldrh r0, [r0]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    ldr r1, .L0809DE10 @ =0xFFFFFECC
    adds r0, r0, r1
    cmp r0, #0x78
    beq .L0809DE94
    cmp r0, #0x78
    bgt .L0809DE1E
    cmp r0, #0x28
    beq .L0809DE4C
    cmp r0, #0x28
    bgt .L0809DE14
    cmp r0, #0
    beq .L0809DE36
    b .L0809DD9C
    .align 2, 0
.L0809DE08: .4byte 0x00001C38
.L0809DE0C: .4byte 0x00001BD8
.L0809DE10: .4byte 0xFFFFFECC
.L0809DE14:
    cmp r0, #0x3c
    beq .L0809DE64
    cmp r0, #0x50
    beq .L0809DE7C
    b .L0809DD9C
.L0809DE1E:
    cmp r0, #0xa0
    beq .L0809DEB4
    cmp r0, #0xa0
    bgt .L0809DE2C
    cmp r0, #0x8c
    beq .L0809DE9C
    b .L0809DD9C
.L0809DE2C:
    cmp r0, #0xb4
    beq .L0809DECC
    cmp r0, #0xff
    beq .L0809DEE4
    b .L0809DD9C
.L0809DE36:
    ldr r2, .L0809DE48 @ =0x00000624
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq .L0809DEF4
    b .L0809DD9C
    .align 2, 0
.L0809DE48: .4byte 0x00000624
.L0809DE4C:
    ldr r0, .L0809DE60 @ =0x00000624
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #4
    b .L0809DD90
    .align 2, 0
.L0809DE60: .4byte 0x00000624
.L0809DE64:
    ldr r2, .L0809DE78 @ =0x00000624
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #8
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #8
    b .L0809DD90
    .align 2, 0
.L0809DE78: .4byte 0x00000624
.L0809DE7C:
    ldr r0, .L0809DE90 @ =0x00000624
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    bne .L0809DD9C
    movs r0, #0x10
    b .L0809DD90
    .align 2, 0
.L0809DE90: .4byte 0x00000624
.L0809DE94:
    ldr r2, .L0809DE98 @ =0x00000624
    b .L0809DD82
    .align 2, 0
.L0809DE98: .4byte 0x00000624
.L0809DE9C:
    ldr r0, .L0809DEB0 @ =0x00000624
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq .L0809DEAC
    b .L0809DD9C
.L0809DEAC:
    movs r0, #0x40
    b .L0809DD90
    .align 2, 0
.L0809DEB0: .4byte 0x00000624
.L0809DEB4:
    ldr r2, .L0809DEC8 @ =0x00000624
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    beq .L0809DEC4
    b .L0809DD9C
.L0809DEC4:
    movs r0, #0x80
    b .L0809DD90
    .align 2, 0
.L0809DEC8: .4byte 0x00000624
.L0809DECC:
    ldr r0, .L0809DEE0 @ =0x00000625
    adds r1, r5, r0
    ldrb r2, [r1]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    beq .L0809DEDC
    b .L0809DD9C
.L0809DEDC:
    movs r0, #1
    b .L0809DD90
    .align 2, 0
.L0809DEE0: .4byte 0x00000625
.L0809DEE4:
    ldr r2, .L0809DEF8 @ =0x00000625
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq .L0809DEF4
    b .L0809DD9C
.L0809DEF4:
    movs r0, #2
    b .L0809DD90
    .align 2, 0
.L0809DEF8: .4byte 0x00000625
.L0809DEFC:
    ldr r2, .L0809DF14 @ =0x00000625
    adds r1, r5, r2
    ldrb r2, [r1]
    movs r0, #8
    ands r0, r2
    cmp r0, #0
    bne .L0809DF18
    movs r0, #8
    orrs r0, r2
    strb r0, [r1]
    b .L0809DF1C
    .align 2, 0
.L0809DF14: .4byte 0x00000625
.L0809DF18:
    movs r0, #0
    mov r8, r0
.L0809DF1C:
    mov r0, r8
    add sp, #0x10
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    .section .text.code_actor_0809DF2C
.L0809DF2C:

    .section .text.code_actor_0809DFAC

    .section .text.code_actor_0809E02C

    .section .text.code_actor_0809E0AC

    .section .text.code_actor_0809E118
.L0809E118:
    .byte 0xF0, 0xB5, 0x81, 0xB0, 0x05, 0x1C, 0x0F, 0x1C
    .byte 0x00, 0x26, 0x1E, 0xE0, 0x00, 0x24, 0x73, 0x1C, 0x13, 0xE0, 0x62, 0x00, 0xF0, 0x00, 0x80, 0x1B
    .byte 0xC0, 0x00, 0x12, 0x18, 0xAA, 0x18, 0x90, 0x88, 0x80, 0x05, 0x80, 0x0E, 0x38, 0x18, 0x01, 0x78
    .byte 0x01, 0x31, 0x01, 0x70, 0x51, 0x79, 0x89, 0x08, 0x79, 0x18, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70
    .byte 0x01, 0x34, 0x28, 0x1C, 0x00, 0x93
    bl func_0809D8A4
    .byte 0x00, 0x9B, 0x84, 0x42, 0xE4, 0xD3
    .byte 0x1E, 0x1C, 0x28, 0x1C
    bl func_0809D8B8
    .byte 0x86, 0x42, 0xDB, 0xD3, 0x01, 0xB0, 0xF0, 0xBC
    .byte 0x01, 0xBC, 0x00, 0x47

    .section .text.code_actor_0809E174
.L0809E174:

    .section .text.code_actor_0809E184
.L0809E184:

    .section .text.code_actor_0809E194
.L0809E194:

    .section .text.code_actor_0809E1A4
.L0809E1A4:

    .section .text.code_actor_0809E1B4
.L0809E1B4:
    .byte 0xF0, 0xB5, 0x84, 0xB0, 0x07, 0x1C, 0x0E, 0x1C, 0x1F, 0x48, 0x15, 0x18
    .byte 0x68, 0x46, 0x29, 0x1C
    bl func_0800E924
    .byte 0x68, 0x46, 0x00, 0x88, 0x80, 0x05, 0x1C, 0x49
    .byte 0x88, 0x42, 0x41, 0xDD, 0x02, 0xAC, 0x20, 0x1C, 0x29, 0x1C
    bl func_0800E924
    .byte 0x20, 0x88
    .byte 0x80, 0x05, 0x80, 0x0D, 0x17, 0x49, 0x44, 0x18, 0x38, 0x1C, 0x21, 0x1C
    bl func_0809D79C
    .byte 0x02, 0x1C, 0x15, 0x49, 0x90, 0x00, 0x80, 0x18, 0x40, 0x00, 0x42, 0x18, 0x13, 0x4D, 0x04, 0x23
    .byte 0x01, 0xCD, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA
    .byte 0x38, 0x1C, 0x21, 0x1C
    bl func_0809D7D8
    .byte 0x02, 0x1C, 0x0D, 0x49, 0xD0, 0x00, 0x80, 0x1A
    .byte 0x40, 0x00, 0x42, 0x18, 0x0B, 0x4C, 0x09, 0x23, 0x01, 0xCC, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70
    .byte 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA, 0x3F, 0xE0, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .byte 0x00, 0x00, 0xC0, 0x4C, 0xCC, 0xFE, 0xFF, 0xFF
    .4byte gUnk_08103B38
    .4byte gUnk_08103B10
    .4byte gUnk_08103C74
    .4byte gUnk_08103C3C
    .byte 0x02, 0xAC, 0x20, 0x1C, 0x29, 0x1C
    bl func_0800E924
    .byte 0x20, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x04, 0x1C, 0x34, 0x3C, 0x38, 0x1C, 0x21, 0x1C
    bl func_0809D418
    .byte 0x02, 0x1C, 0x13, 0x49, 0x90, 0x00, 0x80, 0x18, 0x42, 0x18, 0x12, 0x4D
    .byte 0x09, 0x23, 0x01, 0xCD, 0x30, 0x18, 0x11, 0x78, 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B
    .byte 0xF7, 0xDA, 0x38, 0x1C, 0x21, 0x1C
    bl func_0809D470
    .byte 0x02, 0x1C, 0x0B, 0x49, 0x90, 0x00
    .byte 0x80, 0x18, 0x40, 0x00, 0x42, 0x18, 0x0A, 0x4C, 0x0D, 0x23, 0x01, 0xCC, 0x30, 0x18, 0x11, 0x78
    .byte 0x01, 0x70, 0x01, 0x32, 0x01, 0x3B, 0x00, 0x2B, 0xF7, 0xDA, 0x04, 0xB0, 0xF0, 0xBC, 0x01, 0xBC
    .byte 0x00, 0x47, 0x00, 0x00
    .4byte gUnk_08103F98
    .4byte gUnk_08103F84
    .4byte gUnk_0810400C
    .4byte gUnk_08103FE4
    .endif

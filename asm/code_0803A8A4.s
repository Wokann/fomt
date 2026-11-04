    .include "six/asm/hw/video.s"
    @ ROM-verified four-region Thumb implementation.
    @ Compiler-owned C++ functions are linked between the retained native runs.
    .ifdef REGION_JP
    @ ROM-verified JP Thumb code_0803A8A4/main
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803A8A4
    .thumb_func
func_0803A8A4:
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .hword 0x0000
    .4byte vtable_unk_080E759C
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
    ldr r3, .Ljp_0803A590
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
    ldr r0, .Ljp_0803A594
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
.Ljp_0803A590:
    .4byte 0xFFFFFC00
.Ljp_0803A594:
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
    bl WouldIndexedResourceHandleWrap
    pop	{r1}
    bx	r1
    push	{lr}
    adds	r1, r0, #0
    adds	r1, #48	@ 0x30
    movs	r2, #0
    ldrh	r0, [r1, #14]
    cmp	r0, #0
    beq .Ljp_0803A5CC
    movs	r0, #16
    ldrsh	r1, [r1, r0]
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Ljp_0803A5CC:
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
    bne .Ljp_0803A5F8
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    bl UpdateIndexedResourceHandle
    lsls	r0, r0, #30
    cmp	r0, #0
    bge .Ljp_0803A5FC
    adds	r1, r4, #0
    adds	r1, #68	@ 0x44
    movs	r0, #1
    b .Ljp_0803A5FA
.Ljp_0803A5F8:
    movs	r0, #0
.Ljp_0803A5FA:
    strb	r0, [r1, #0]
.Ljp_0803A5FC:
    pop	{r4}
    pop	{r0}
    bx	r0
    .align 2, 0
    push	{r4, r5, lr}
    adds	r4, r0, #0
    adds	r5, r1, #0
    ldrh	r0, [r4, #4]
    cmp	r0, r5
    beq .Ljp_0803A62C
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
.Ljp_0803A62C:
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
    ldr	r0, [r0, #0]
    bx	lr
    .section .text.ui_text_window_native, "ax", %progbits
    .align 2, 0
    .global __12UiTextWindowiiUiUiUiUiUiUi
    .thumb_func
__12UiTextWindowiiUiUiUiUiUiUi:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    mov	ip, r0
    ldr	r0, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #48]	@ 0x30
    ldr	r4, [sp, #52]	@ 0x34
    ldr	r6, [sp, #56]	@ 0x38
    movs	r7, #0
    mov	r9, r7
    mov	r7, ip
    strh	r1, [r7, #0]
    strh	r2, [r7, #2]
    strh	r3, [r7, #4]
    strh	r0, [r7, #6]
    movs	r0, #3
    ands	r5, r0
    ldrb	r0, [r7, #8]
    movs	r1, #4
    negs	r1, r1
    mov	r8, r1
    mov	r2, r8
    ands	r2, r0
    orrs	r2, r5
    adds	r0, r4, #0
    movs	r7, #31
    ands	r0, r7
    lsls	r0, r0, #2
    subs	r1, #121	@ 0x79
    ands	r2, r1
    orrs	r2, r0
    mov	r8, r2
    mov	r0, ip
    strb	r2, [r0, #8]
    lsrs	r1, r4, #3
    movs	r0, #3
    ands	r1, r0
    lsls	r1, r1, #7
    mov	r2, ip
    ldrh	r0, [r2, #8]
    ldr r3, .Ljp_0803B810
    ands	r3, r0
    orrs	r3, r1
    strh	r3, [r2, #8]
    movs	r0, #7
    ands	r4, r0
    lsls	r4, r4, #6
    adds	r4, #20
    ldr r7, .Ljp_0803B814
    str	r7, [sp, #0]
    lsls	r4, r4, #9
    ldr	r5, [r2, #8]
    ldr r0, .Ljp_0803B818
    ands	r5, r0
    orrs	r5, r4
    str	r5, [r2, #8]
    movs	r0, #15
    ands	r6, r0
    lsls	r6, r6, #3
    ldrb	r0, [r2, #10]
    movs	r1, #121	@ 0x79
    negs	r1, r1
    mov	sl, r1
    mov	r2, sl
    ands	r2, r0
    orrs	r2, r6
    mov	sl, r2
    mov	r6, ip
    strb	r2, [r6, #10]
    movs	r0, #255	@ 0xff
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r0
    lsls	r1, r1, #7
    ldrh	r2, [r6, #10]
    ldr r0, .Ljp_0803B81C
    ands	r0, r2
    orrs	r0, r1
    strh	r0, [r6, #10]
    ldrb	r1, [r6, #11]
    movs	r0, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r6, #11]
    ldrb	r1, [r6, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #12]
    movs	r7, #0
    strb	r7, [r6, #13]
    mov	r2, ip
    adds	r2, #16
    mov	r0, r9
    str	r0, [r6, #16]
    str	r0, [r2, #4]
    ldr r0, .Ljp_0803B820
    str	r0, [r2, #8]
    adds	r1, r2, #0
    adds	r1, #16
    str	r1, [r2, #12]
    mov	r6, r9
    str	r6, [r1, #4]
    ldr r0, .Ljp_0803B824
    str	r0, [r1, #8]
    mov	r0, ip
    adds	r0, #28
    str	r0, [r2, #16]
    str	r1, [r2, #20]
    lsls	r3, r3, #23
    lsrs	r3, r3, #30
    lsls	r5, r5, #13
    lsrs	r7, r5, #22
    lsls	r3, r3, #9
    adds	r2, r3, r7
    ldr r0, .Ljp_0803B828
    ldr	r0, [r0, #0]
    lsrs	r5, r0, #5
    movs	r4, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Ljp_0803B758
    movs	r4, #1
.Ljp_0803B758:
    mov	r1, ip
    adds	r1, #44	@ 0x2c
    ldr r0, .Ljp_0803B82C
    ldr	r3, [r0, #0]
    lsls	r2, r2, #5
    movs	r0, #192	@ 0xc0
    lsls	r0, r0, #19
    adds	r2, r2, r0
    mov	r6, r9
    mov	r0, ip
    str	r6, [r0, #44]	@ 0x2c
    str	r6, [r1, #4]
    ldr r0, .Ljp_0803B830
    str	r0, [r1, #8]
    str	r3, [r1, #12]
    str	r2, [r1, #16]
    strb	r5, [r1, #20]
    strb	r4, [r1, #21]
    movs	r2, #0
    strb	r2, [r1, #22]
    mov	r6, ip
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    cmp	r0, #0
    bge .Ljp_0803B78C
    adds	r0, #7
.Ljp_0803B78C:
    asrs	r0, r0, #3
    str	r0, [sp, #4]
    mov	r2, ip
    movs	r0, #2
    ldrsh	r6, [r2, r0]
    cmp	r6, #0
    bge .Ljp_0803B79C
    adds	r6, #7
.Ljp_0803B79C:
    asrs	r6, r6, #3
    str	r6, [sp, #8]
    mov	r1, ip
    ldrh	r4, [r1, #4]
    lsrs	r4, r4, #3
    ldrh	r1, [r1, #6]
    lsrs	r1, r1, #3
    mov	r2, r8
    lsls	r3, r2, #25
    lsrs	r3, r3, #27
    mov	r6, sl
    lsls	r5, r6, #25
    mov	r2, ip
    adds	r2, #68	@ 0x44
    mov	r0, r9
    mov	r6, ip
    str	r0, [r6, #68]	@ 0x44
    str	r0, [r2, #4]
    ldr r0, .Ljp_0803B834
    str	r0, [r2, #8]
    ldr	r0, [sp, #4]
    str	r0, [r2, #12]
    ldr	r6, [sp, #8]
    str	r6, [r2, #16]
    str	r4, [r2, #20]
    str	r1, [r2, #24]
    movs	r0, #31
    ands	r3, r0
    ldrb	r1, [r2, #28]
    subs	r0, #63	@ 0x3f
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #28]
    ldr	r1, [sp, #0]
    ands	r7, r1
    lsls	r3, r7, #5
    ldrh	r1, [r2, #28]
    ldr r0, .Ljp_0803B838
    ands	r0, r1
    orrs	r0, r3
    strh	r0, [r2, #28]
    lsrs	r5, r5, #28
    lsls	r5, r5, #15
    ldr	r0, [r2, #28]
    ldr r1, .Ljp_0803B83C
    ands	r0, r1
    orrs	r0, r5
    str	r0, [r2, #28]
    mov	r0, ip
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Ljp_0803B810:
    .4byte 0xFFFFFE7F
.Ljp_0803B814:
    .4byte 0x000003FF
.Ljp_0803B818:
    .4byte 0xFFF801FF
.Ljp_0803B81C:
    .4byte 0xFFFF807F
.Ljp_0803B820:
    .4byte __vt_18HardwareLinkedList
.Ljp_0803B824:
    .4byte __vt_12HardwareLink
.Ljp_0803B828:
    .4byte gUiSharedTileByteCount
.Ljp_0803B82C:
    .4byte gUiSharedTiles
.Ljp_0803B830:
    .4byte __vt_29UiTextWindowTileUploadCommand
.Ljp_0803B834:
    .4byte __vt_25UiTextWindowBorderCommand
.Ljp_0803B838:
    .4byte 0xFFFF801F
.Ljp_0803B83C:
    .4byte 0xFFF87FFF
    .global Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2
    .thumb_func
Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    adds	r4, r2, #0
    mov	sl, r3
    ldrb	r2, [r7, #11]
    lsrs	r1, r2, #7
    ldrb	r0, [r7, #12]
    movs	r3, #127	@ 0x7f
    ands	r0, r3
    lsls	r0, r0, #1
    orrs	r0, r1
    cmp	r0, #1
    beq .Ljp_0803B870
    cmp	r0, #1
    ble .Ljp_0803B8AC
    cmp	r0, #2
    beq .Ljp_0803B890
    b .Ljp_0803B8AC
.Ljp_0803B870:
    ldrb	r0, [r7, #13]
    cmp	r0, #8
    bls .Ljp_0803B88C
    movs	r0, #128	@ 0x80
    orrs	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r7, #12]
    b .Ljp_0803B8AC
.Ljp_0803B88C:
    adds	r0, #1
    b .Ljp_0803B8AA
.Ljp_0803B890:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    bne .Ljp_0803B8A8
    adds	r0, r3, #0
    ands	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r7, #12]
    b .Ljp_0803B8AC
.Ljp_0803B8A8:
    subs	r0, #1
.Ljp_0803B8AA:
    strb	r0, [r7, #13]
.Ljp_0803B8AC:
    adds	r3, r7, #0
    adds	r3, #16
    movs	r2, #0
    adds	r1, r3, #0
    adds	r1, #16
    ldr	r0, [r3, #12]
    cmp	r0, r1
    bne .Ljp_0803B8BE
    movs	r2, #1
.Ljp_0803B8BE:
    cmp	r2, #0
    bne .Ljp_0803B8CE
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #28]
    adds	r0, r4, #0
    adds	r1, r3, #0
    bl _call_via_r2
.Ljp_0803B8CE:
    ldrb	r0, [r7, #11]
    lsrs	r0, r0, #7
    ldrb	r1, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r1, r2
    lsls	r1, r1, #1
    orrs	r1, r0
    cmp	r1, #0
    bne .Ljp_0803B8E2
    b .Ljp_0803BA3C
.Ljp_0803B8E2:
    movs	r0, #0
    mov	r8, r0
    ldrb	r4, [r7, #8]
    lsls	r2, r4, #30
    lsrs	r2, r2, #30
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    lsls	r0, r2
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #6
    adds	r1, r3, #0
    orrs	r0, r1
    mov	r5, r9
    ldrh	r1, [r5, #0]
    orrs	r0, r1
    strh	r0, [r5, #0]
    lsls	r3, r2, #1
    lsls	r2, r2, #2
    mov	r5, sp
    ldrh	r1, [r7, #8]
    lsls	r1, r1, #23
    lsrs	r1, r1, #30
    lsls	r1, r1, #2
    lsls	r0, r4, #25
    lsrs	r0, r0, #27
    lsls	r0, r0, #8
    orrs	r1, r0
    movs	r0, #64	@ 0x40
    orrs	r1, r0
    strh	r1, [r5, #0]
    adds	r3, #8
    add	r3, r9
    strh	r1, [r3, #0]
    mov	r0, sp
    mov	r1, r8
    strh	r1, [r0, #0]
    adds	r0, r2, #0
    adds	r0, #16
    add	r0, r9
    strh	r1, [r0, #0]
    mov	r1, sp
    ldrh	r5, [r7, #2]
    negs	r0, r5
    strh	r0, [r1, #0]
    adds	r2, #18
    add	r2, r9
    strh	r0, [r2, #0]
    ldrb	r6, [r7, #13]
    strb	r4, [r1, #4]
    cmp	r6, #8
    bls .Ljp_0803B970
    mov	r3, sp
    ldrh	r0, [r7, #0]
    lsls	r2, r0, #8
    ldrh	r1, [r7, #4]
    adds	r0, r0, r1
    orrs	r2, r0
    strh	r2, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r2, [r0, #0]
    mov	r2, sp
    lsls	r1, r5, #8
    ldrh	r0, [r7, #6]
    adds	r0, r5, r0
    orrs	r1, r0
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #68	@ 0x44
    strh	r1, [r0, #0]
    b .Ljp_0803B9D8
.Ljp_0803B970:
    ldrh	r4, [r7, #6]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    mov	r8, r0
    movs	r2, #2
    ldrsh	r5, [r7, r2]
    adds	r4, r5, r4
    adds	r5, r5, r4
    lsrs	r0, r5, #31
    adds	r5, r5, r0
    asrs	r5, r5, #1
    mov	r3, r8
    lsrs	r0, r3, #31
    add	r0, r8
    asrs	r0, r0, #1
    subs	r5, r5, r0
    ldrh	r4, [r7, #4]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    movs	r1, #0
    ldrsh	r2, [r7, r1]
    adds	r4, r2, r4
    adds	r2, r2, r4
    lsrs	r1, r2, #31
    adds	r2, r2, r1
    asrs	r2, r2, #1
    lsrs	r1, r0, #31
    adds	r1, r0, r1
    asrs	r1, r1, #1
    subs	r2, r2, r1
    mov	r3, sp
    lsls	r1, r2, #8
    adds	r2, r2, r0
    orrs	r1, r2
    strh	r1, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r1, [r0, #0]
    mov	r1, sp
    lsls	r0, r5, #8
    add	r5, r8
    orrs	r0, r5
    strh	r0, [r1, #0]
    mov	r1, r9
    adds	r1, #68	@ 0x44
    strh	r0, [r1, #0]
.Ljp_0803B9D8:
    mov	r0, sp
    movs	r1, #63	@ 0x3f
    strh	r1, [r0, #0]
    mov	r3, r9
    adds	r3, #72	@ 0x48
    strh	r1, [r3, #0]
    mov	r2, sp
    ldrb	r4, [r2, #4]
    lsls	r0, r4, #30
    lsrs	r0, r0, #30
    movs	r4, #1
    lsls	r4, r0
    bics	r1, r4
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #74	@ 0x4a
    strh	r1, [r0, #0]
    ldrh	r0, [r7, #10]
    lsls	r0, r0, #17
    lsrs	r2, r0, #24
    cmp	r2, #2
    bne .Ljp_0803BA14
    ldrh	r0, [r3, #0]
    movs	r1, #32
    orrs	r0, r1
    strh	r0, [r3, #0]
    ldr r0, .Ljp_0803BA38
    orrs	r4, r0
    mov	r5, r9
    str	r4, [r5, #80]	@ 0x50
.Ljp_0803BA14:
    cmp	r2, #1
    bne .Ljp_0803BA6C
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    blt .Ljp_0803BA6C
    mov	r1, sl
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
    b .Ljp_0803BA6C
    .align 2, 0
.Ljp_0803BA38:
    .4byte 0x08083F40
.Ljp_0803BA3C:
    ldrb	r0, [r7, #8]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #1
    lsls	r1, r0
    mov	r2, r9
    ldrh	r0, [r2, #0]
    bics	r0, r1
    strh	r0, [r2, #0]
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Ljp_0803BA6C
    mov	r4, sl
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #20]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
.Ljp_0803BA6C:
    ldrb	r1, [r7, #11]
    lsrs	r1, r1, #7
    ldrb	r0, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    lsls	r0, r0, #1
    orrs	r0, r1
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    @ Remaining control-widget code after the recovered border constructor.
    .section .text.main_menu_widget_update_impl, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0
    .global UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
    .thumb_func
UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #116	@ 0x74
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r2, [sp, #68]	@ 0x44
    adds	r1, r3, #0
    ldr	r3, [sp, #152]	@ 0x98
    ldr	r5, [sp, #156]	@ 0x9c
    ldr	r2, [sp, #148]	@ 0x94
    bl Update__13ControlWidgetP20HardwareDisplayStateP18HardwareLinkedListT2
    str	r0, [sp, #72]	@ 0x48
    cmp	r0, #0
    bge .Ljp_0803BDE2
    b .Ljp_0803C29A
.Ljp_0803BDE2:
    cmp	r0, #2
    bgt .Ljp_0803BDE8
    b .Ljp_0803C29A
.Ljp_0803BDE8:
    cmp	r0, #3
    beq .Ljp_0803BDEE
    b .Ljp_0803C29A
.Ljp_0803BDEE:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    ldrb	r0, [r7, #15]
    cmp	r0, #0
    beq .Ljp_0803BE70
    ldrh	r3, [r4, #8]
    adds	r2, r3, #0
    lsls	r1, r2, #26
    lsrs	r1, r1, #31
    lsls	r0, r2, #27
    lsrs	r0, r0, #31
    orrs	r1, r0
    cmp	r1, #0
    beq .Ljp_0803BE5C
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    beq .Ljp_0803BE20
    ldrb	r0, [r7, #12]
    cmp	r0, #0
    bne .Ljp_0803BE1C
    movs	r0, #6
    b .Ljp_0803BE38
.Ljp_0803BE1C:
    subs	r0, #1
    b .Ljp_0803BE38
.Ljp_0803BE20:
    movs	r0, #16
    ands	r2, r0
    cmp	r2, #0
    beq .Ljp_0803BE3A
    ldrb	r0, [r7, #12]
    cmp	r0, #6
    bne .Ljp_0803BE36
    add	r1, sp, #76	@ 0x4c
    ldrb	r1, [r1, #0]
    strb	r1, [r7, #12]
    b .Ljp_0803BE3A
.Ljp_0803BE36:
    adds	r0, #1
.Ljp_0803BE38:
    strb	r0, [r7, #12]
.Ljp_0803BE3A:
    cmp	r5, #0
    beq .Ljp_0803BE46
    adds	r0, r5, #0
    movs	r1, #203	@ 0xcb
    bl Start__23HardwareMusicPlayerSlotUs
.Ljp_0803BE46:
    ldr r0, .Ljp_0803BE58
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #20
    strb	r0, [r7, #14]
    b .Ljp_0803BE70
.Ljp_0803BE58:
    .4byte gMenuEntryLabels
.Ljp_0803BE5C:
    movs	r0, #1
    ands	r3, r0
    cmp	r3, #0
    beq .Ljp_0803BE70
    cmp	r5, #0
    beq .Ljp_0803BE70
    adds	r0, r5, #0
    movs	r1, #197	@ 0xc5
    bl Start__23HardwareMusicPlayerSlotUs
.Ljp_0803BE70:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    beq .Ljp_0803BED6
    ldr	r4, [r7, #8]
    ldr	r0, [r4, #80]	@ 0x50
    ldr	r1, [r0, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #44]	@ 0x2c
    lsls	r2, r2, #2
    ldr	r0, [r0, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    ldr	r5, [sp, #20]
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r2, r0, #0
    add	r1, sp, #20
    ldr	r0, [sp, #20]
    movs	r3, #0
    cmp	r0, #0
    beq .Ljp_0803BEAA
    ldrh	r3, [r1, #4]
.Ljp_0803BEAA:
    adds	r1, r4, #0
    adds	r1, #56	@ 0x38
    lsls	r0, r2, #5
    ldr r2, .Ljp_0803C264
    adds	r0, r0, r2
    str	r5, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
    ldr r1, .Ljp_0803C268
    ldrb	r0, [r7, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r7, #13]
.Ljp_0803BED6:
    ldrb	r0, [r7, #14]
    subs	r0, #1
    strb	r0, [r7, #14]
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803BEE6
    movs	r0, #40	@ 0x28
    strb	r0, [r7, #14]
.Ljp_0803BEE6:
    ldrb	r0, [r7, #14]
    cmp	r0, #19
    bhi .Ljp_0803BFE2
    ldr	r0, [r7, #8]
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #4
    adds	r1, #16
    mov	r8, r1
    ldr	r4, [r0, #80]	@ 0x50
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r9, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Ljp_0803BF62
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Ljp_0803BF46
    ldrh	r3, [r1, #4]
.Ljp_0803BF46:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r5, .Ljp_0803C26C
    adds	r0, r0, r5
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r2, [sp, #148]	@ 0x94
    ldr	r0, [r2, #8]
    ldr	r2, [r0, #16]
    ldr	r0, [sp, #148]	@ 0x94
    bl _call_via_r2
.Ljp_0803BF62:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    add	r0, r8
    ldr r1, .Ljp_0803C270
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Ljp_0803C274
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #36]	@ 0x24
    add	r4, sp, #36	@ 0x24
    ldrb	r0, [r4, #0]
    adds	r0, #150	@ 0x96
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr r1, .Ljp_0803C278
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    mov	r3, r9
    lsls	r1, r3, #16
    lsrs	r1, r1, #16
    movs	r0, #15
    ands	r1, r0
    lsls	r1, r1, #12
    ldr r2, .Ljp_0803C27C
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Ljp_0803C280
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #5
    ldr	r1, [sp, #36]	@ 0x24
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r2, [r5, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Ljp_0803BFE2
    lsls	r0, r2, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r5, #0]
.Ljp_0803BFE2:
    ldr	r0, [r7, #8]
    mov	sl, r0
    movs	r1, #0
    mov	r9, r1
    mov	r2, sp
    adds	r2, #44	@ 0x2c
    str	r2, [sp, #96]	@ 0x60
    ldr	r3, [sp, #76]	@ 0x4c
    negs	r3, r3
    str	r3, [sp, #104]	@ 0x68
    mov	r4, sp
    adds	r4, #60	@ 0x3c
    str	r4, [sp, #100]	@ 0x64
    movs	r5, #16
    str	r5, [sp, #108]	@ 0x6c
.Ljp_0803C000:
    mov	r1, r9
    lsls	r0, r1, #2
    add	r0, sl
    ldr	r4, [r0, #84]	@ 0x54
    mov	r0, sl
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r8, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Ljp_0803C074
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Ljp_0803C058
    ldrh	r3, [r1, #4]
.Ljp_0803C058:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r2, .Ljp_0803C26C
    adds	r0, r0, r2
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
.Ljp_0803C074:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r0, r0, r4
    ldr r1, .Ljp_0803C270
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Ljp_0803C274
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #96]	@ 0x60
    ldrb	r1, [r5, #0]
    adds	r1, #150	@ 0x96
    lsls	r1, r1, #24
    lsrs	r1, r1, #24
    ldr r0, .Ljp_0803C278
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #44]	@ 0x2c
    mov	r0, r8
    lsls	r1, r0, #16
    lsrs	r1, r1, #16
    movs	r2, #15
    ands	r1, r2
    lsls	r1, r1, #12
    add	r4, sp, #44	@ 0x2c
    ldr	r0, [r4, #4]
    ldr r3, .Ljp_0803C27C
    ands	r0, r3
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Ljp_0803C280
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r5, #128	@ 0x80
    lsls	r5, r5, #5
    orrs	r1, r5
    str	r1, [sp, #44]	@ 0x2c
    ldr	r0, [sp, #68]	@ 0x44
    ldrb	r2, [r0, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Ljp_0803C0FA
    lsls	r0, r2, #3
    adds	r0, #4
    ldr	r3, [sp, #68]	@ 0x44
    adds	r0, r3, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r3, #0]
.Ljp_0803C0FA:
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r4, #16
    str	r4, [sp, #108]	@ 0x6c
    movs	r5, #1
    add	r9, r5
    mov	r0, r9
    cmp	r0, #6
    bhi .Ljp_0803C10C
    b .Ljp_0803C000
.Ljp_0803C10C:
    ldr	r7, [r7, #8]
    mov	r8, r7
    ldr	r1, [sp, #76]	@ 0x4c
    cmp	r1, #0
    beq .Ljp_0803C144
    add	r0, sp, #52	@ 0x34
    movs	r4, #12
    movs	r5, #2
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    mov	r6, r8
    adds	r6, #116	@ 0x74
    adds	r1, r6, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    add	r0, sp, #56	@ 0x38
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #56]	@ 0x38
    ldr	r2, [sp, #76]	@ 0x4c
    str	r2, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Ljp_0803C144:
    mov	r0, r8
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    ldr	r3, [sp, #104]	@ 0x68
    ldr	r4, [sp, #76]	@ 0x4c
    orrs	r3, r4
    mov	r5, r8
    adds	r5, #112	@ 0x70
    str	r5, [sp, #80]	@ 0x50
    lsrs	r1, r3, #31
    str	r1, [sp, #84]	@ 0x54
    movs	r1, #0
    movs	r2, #0
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    ldr r2, .Ljp_0803C284
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #24
    orrs	r1, r2
    ldr r2, .Ljp_0803C288
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #7
    orrs	r1, r2
    str	r1, [sp, #60]	@ 0x3c
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    movs	r2, #15
    ands	r0, r2
    lsls	r0, r0, #12
    ldr	r3, [sp, #100]	@ 0x64
    ldr	r1, [r3, #4]
    ldr r4, .Ljp_0803C27C
    ands	r1, r4
    orrs	r1, r0
    str	r1, [r3, #4]
    ldr	r0, [sp, #60]	@ 0x3c
    ldr r5, .Ljp_0803C278
    ands	r0, r5
    movs	r1, #142	@ 0x8e
    orrs	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #5
    orrs	r0, r1
    str	r0, [sp, #60]	@ 0x3c
    movs	r4, #0
    mov	r2, r8
    adds	r2, #116	@ 0x74
    str	r2, [sp, #88]	@ 0x58
.Ljp_0803C1AE:
    lsls	r0, r4, #3
    ldr	r3, [sp, #80]	@ 0x50
    adds	r0, r0, r3
    movs	r5, #193	@ 0xc1
    lsls	r5, r5, #2
    adds	r0, r0, r5
    ldr	r1, [r0, #4]
    bl GetObjTileIndex
    mov	r8, r0
    lsls	r0, r4, #5
    mov	sl, r0
    adds	r1, r4, #1
    str	r1, [sp, #92]	@ 0x5c
    ldr	r2, [sp, #84]	@ 0x54
    cmp	r2, #0
    beq .Ljp_0803C22C
    movs	r3, #0
    lsls	r2, r4, #1
    lsls	r1, r4, #2
    movs	r4, #128	@ 0x80
    mov	r9, r4
    adds	r1, r1, r2
    lsls	r1, r1, #3
    ldr	r5, [sp, #80]	@ 0x50
    movs	r4, #202	@ 0xca
    lsls	r4, r4, #2
    adds	r0, r5, r4
    adds	r4, r1, r0
    mov	r5, r8
    lsls	r0, r5, #5
    ldr r5, .Ljp_0803C26C
    adds	r7, r0, r5
    lsls	r2, r2, #6
    ldr	r0, [sp, #88]	@ 0x58
    adds	r6, r2, r0
    ldr	r2, [sp, #80]	@ 0x50
    movs	r5, #199	@ 0xc7
    lsls	r5, r5, #2
    adds	r0, r2, r5
    adds	r5, r1, r0
.Ljp_0803C200:
    str	r6, [r4, #0]
    str	r7, [r4, #4]
    mov	r0, r9
    str	r0, [r4, #8]
    ldr	r1, [sp, #148]	@ 0x94
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    adds	r0, r1, #0
    adds	r1, r5, #0
    str	r3, [sp, #112]	@ 0x70
    bl _call_via_r2
    adds	r4, #24
    adds	r7, #128	@ 0x80
    movs	r2, #192	@ 0xc0
    lsls	r2, r2, #1
    adds	r6, r6, r2
    adds	r5, #24
    ldr	r3, [sp, #112]	@ 0x70
    adds	r3, #1
    cmp	r3, #1
    bls .Ljp_0803C200
.Ljp_0803C22C:
    mov	r3, r8
    lsls	r1, r3, #22
    lsrs	r1, r1, #22
    ldr r2, .Ljp_0803C280
    ldr	r4, [sp, #100]	@ 0x64
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    mov	r1, sl
    adds	r1, #136	@ 0x88
    ldr r0, .Ljp_0803C270
    ands	r1, r0
    lsls	r1, r1, #16
    ldr r0, .Ljp_0803C274
    ldr	r2, [sp, #60]	@ 0x3c
    ands	r2, r0
    orrs	r2, r1
    str	r2, [sp, #60]	@ 0x3c
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r3, [r5, #0]
    cmp	r3, #127	@ 0x7f
    bhi .Ljp_0803C294
    lsls	r0, r3, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r2, [r0, #0]
    b .Ljp_0803C28C
.Ljp_0803C264:
    .word OBJ_PALETTE
.Ljp_0803C268:
    .4byte gMenuEntryLabels
.Ljp_0803C26C:
    .word OBJ_VRAM0
.Ljp_0803C270:
    .4byte 0x000001FF
.Ljp_0803C274:
    .4byte 0xFE00FFFF
.Ljp_0803C278:
    .4byte 0xFFFFFF00
.Ljp_0803C27C:
    .4byte 0xFFFF0FFF
.Ljp_0803C280:
    .4byte 0xFFFFFC00
.Ljp_0803C284:
    .4byte 0x3FFFFFFF
.Ljp_0803C288:
    .4byte 0xFFFF3FFF
.Ljp_0803C28C:
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r3, #1
    strb	r0, [r5, #0]
.Ljp_0803C294:
    ldr	r4, [sp, #92]	@ 0x5c
    cmp	r4, #2
    bls .Ljp_0803C1AE
.Ljp_0803C29A:
    ldr	r0, [sp, #72]	@ 0x48
    add	sp, #116	@ 0x74
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .section .text.map_clock_status_calendar, "ax", %progbits
    .align 2, 0
    .global UpdateMapClockStatusHudCalendar
    .thumb_func
UpdateMapClockStatusHudCalendar:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #40	@ 0x28
    str	r1, [sp, #32]
    lsls	r2, r2, #24
    lsrs	r2, r2, #24
    str	r2, [sp, #36]	@ 0x24
    ldr	r7, [r0, #0]
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    beq .Ljp_0803CB42
    cmp	r0, #1
    ble .Ljp_0803CB3C
    cmp	r0, #2
    beq .Ljp_0803CB48
    cmp	r0, #3
    beq .Ljp_0803CB4E
.Ljp_0803CB3C:
    movs	r5, #11
    movs	r6, #12
    b .Ljp_0803CB52
.Ljp_0803CB42:
    movs	r5, #13
    movs	r6, #14
    b .Ljp_0803CB52
.Ljp_0803CB48:
    movs	r5, #15
    movs	r6, #16
    b .Ljp_0803CB52
.Ljp_0803CB4E:
    movs	r5, #17
    movs	r6, #18
.Ljp_0803CB52:
    adds	r0, r7, #0
    adds	r0, #132	@ 0x84
    lsls	r1, r5, #5
    ldr r2, .Ljp_0803CBF0
    mov	r9, r2
    add	r1, r9
    movs	r2, #32
    bl memcpy
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #1
    adds	r4, r7, r0
    movs	r1, #1
    mov	r8, r1
    mov	r2, r8
    strb	r2, [r4, #0]
    lsls	r1, r6, #5
    add	r1, r9
    adds	r0, r7, #0
    adds	r0, #164	@ 0xa4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    ldr	r1, [sp, #32]
    ldrb	r3, [r1, #1]
    lsls	r0, r3, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    adds	r6, r0, #0
    ldrb	r2, [r1, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    lsls	r3, r3, #30
    lsrs	r3, r3, #30
    adds	r2, #6
    lsls	r1, r3, #4
    subs	r1, r1, r3
    lsls	r1, r1, #1
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r1, r6
    subs	r1, #1
    cmp	r1, #6
    bls .Ljp_0803CBBC
    adds	r0, r1, #0
    movs	r1, #7
    bl __umodsi3
    adds	r1, r0, #0
.Ljp_0803CBBC:
    movs	r0, #7
    ands	r1, r0
    mov	sl, r1
    adds	r0, r6, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r6, #0
    movs	r1, #10
    bl __umodsi3
    adds	r6, r0, #0
    cmp	r5, #0
    ble .Ljp_0803CBF4
    lsls	r1, r5, #5
    add	r1, r9
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    strb	r2, [r4, #0]
    b .Ljp_0803CC0E
    .align 2, 0
.Ljp_0803CBF0:
    .4byte gMapClockStatusGlyphTiles
.Ljp_0803CBF4:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
.Ljp_0803CC0E:
    lsls	r1, r6, #5
    ldr r2, .Ljp_0803CCA4
    mov	r9, r2
    add	r1, r9
    adds	r0, r7, #0
    adds	r0, #228	@ 0xe4
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r8, r0
    mov	r1, r8
    strb	r1, [r4, #0]
    mov	r1, sl
    adds	r1, #21
    lsls	r1, r1, #5
    add	r1, r9
    movs	r2, #244	@ 0xf4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    movs	r0, #172	@ 0xac
    lsls	r0, r0, #2
    adds	r1, r7, r0
    mov	r2, r8
    strb	r2, [r1, #0]
    ldr	r2, [sp, #32]
    ldr	r0, [r2, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    adds	r5, r0, #0
    movs	r0, #30
    mov	sl, r1
    cmp	r5, #11
    bhi .Ljp_0803CC5A
    movs	r0, #28
.Ljp_0803CC5A:
    lsls	r1, r0, #5
    add	r1, r9
    movs	r2, #130	@ 0x82
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    cmp	r5, #11
    bls .Ljp_0803CC74
    subs	r5, #12
.Ljp_0803CC74:
    adds	r0, r5, #0
    movs	r1, #10
    bl __udivsi3
    adds	r6, r0, #0
    adds	r0, r5, #0
    movs	r1, #10
    bl __umodsi3
    adds	r5, r0, #0
    cmp	r6, #0
    ble .Ljp_0803CCA8
    lsls	r1, r6, #5
    add	r1, r9
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    b .Ljp_0803CCC4
    .align 2, 0
.Ljp_0803CCA4:
    .4byte gMapClockStatusGlyphTiles
.Ljp_0803CCA8:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #1
    adds	r0, r7, r1
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    strb	r2, [r4, #0]
.Ljp_0803CCC4:
    lsls	r1, r5, #5
    ldr r0, .Ljp_0803CD60
    mov	r9, r0
    add	r1, r9
    movs	r2, #178	@ 0xb2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r8, r0
    mov	r1, r8
    strb	r1, [r4, #0]
    ldr	r2, [sp, #32]
    ldr	r0, [r2, #0]
    lsls	r0, r0, #5
    lsrs	r0, r0, #26
    movs	r1, #10
    bl __udivsi3
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    lsls	r4, r0, #2
    adds	r4, r4, r0
    lsls	r4, r4, #1
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    lsls	r5, r5, #5
    add	r5, r9
    movs	r0, #138	@ 0x8a
    lsls	r0, r0, #2
    adds	r6, r7, r0
    movs	r1, #146	@ 0x92
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r5, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    mov	r2, sl
    strb	r0, [r2, #0]
    lsls	r4, r4, #5
    add	r4, r9
    movs	r1, #154	@ 0x9a
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r4, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    mov	r2, sl
    strb	r0, [r2, #0]
    ldr	r1, [sp, #36]	@ 0x24
    cmp	r1, #0
    beq .Ljp_0803CD64
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #1
    add	r1, r9
    adds	r0, r6, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    mov	r2, sl
    strb	r0, [r2, #0]
    b .Ljp_0803CD7E
    .align 2, 0
.Ljp_0803CD60:
    .4byte gMapClockStatusGlyphTiles
.Ljp_0803CD64:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r6, #0
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    mov	r1, sl
    strb	r2, [r1, #0]
.Ljp_0803CD7E:
    add	sp, #40	@ 0x28
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.farming_calendar_helpers, "ax", %progbits
    .align 2, 0
    .global DecodeGameDayDate
    .thumb_func
DecodeGameDayDate:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r5, r1, #0
    ldrb	r3, [r5, #1]
    add	r4, sp, #8
    strb	r3, [r4, #0]
    ldrb	r2, [r5, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
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
    mov	r8, r4
    cmp	r3, #6
    bls .Ljp_0803D1E6
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Ljp_0803D1E6:
    movs	r1, #8
    negs	r1, r1
    movs	r0, #7
    ands	r0, r3
    ands	r1, r6
    adds	r6, r1, #0
    orrs	r6, r0
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #0]
    ldrb	r0, [r5, #0]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #4]
    add	r0, sp, #4
    mov	r2, sp
    cmp	r3, r1
    bls .Ljp_0803D212
    adds	r2, r0, #0
.Ljp_0803D212:
    ldr	r4, [r2, #0]
    ldr	r0, [r5, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    cmp	r0, #5
    bhi .Ljp_0803D286
    mov	r5, r8
    ldrb	r3, [r5, #0]
    lsls	r0, r3, #25
    lsrs	r2, r0, #27
    cmp	r2, #0
    bne .Ljp_0803D242
    lsls	r0, r3, #30
    lsrs	r0, r0, #30
    movs	r1, #4
    negs	r1, r1
    subs	r0, #1
    movs	r2, #3
    ands	r0, r2
    ands	r1, r3
    orrs	r1, r0
    strb	r1, [r5, #0]
    movs	r2, #29
    b .Ljp_0803D244
.Ljp_0803D242:
    subs	r2, #1
.Ljp_0803D244:
    movs	r0, #31
    ands	r2, r0
    lsls	r2, r2, #2
    ldrb	r1, [r5, #0]
    movs	r0, #125	@ 0x7d
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r5, #0]
    mov	r0, r8
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #3
    bne .Ljp_0803D26C
    lsls	r0, r1, #25
    lsrs	r0, r0, #27
    cmp	r0, #29
    bne .Ljp_0803D26C
    subs	r4, #1
.Ljp_0803D26C:
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    movs	r1, #6
    cmp	r0, #1
    ble .Ljp_0803D278
    subs	r1, r0, #1
.Ljp_0803D278:
    movs	r0, #7
    ands	r1, r0
    movs	r0, #8
    negs	r0, r0
    ands	r0, r6
    adds	r6, r0, #0
    orrs	r6, r1
.Ljp_0803D286:
    strb	r4, [r7, #0]
    mov	r1, r8
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    strb	r0, [r7, #1]
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    strb	r0, [r7, #2]
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    strb	r0, [r7, #3]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803D644
    .thumb_func
func_0803D644:
    push	{r4, lr}
    sub	sp, #8
    lsls	r2, r0, #4
    subs	r2, r2, r0
    lsls	r2, r2, #1
    subs	r2, #1
    adds	r2, r2, r1
    str	r2, [sp, #4]
    ldr r0, .Ljp_0803D2F8
    adds	r4, r0, #0
    adds	r4, #14
    movs	r1, #0
    str	r1, [sp, #0]
    adds	r1, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080E0E80
    adds	r1, r0, #0
    movs	r2, #0
    cmp	r1, r4
    beq .Ljp_0803D2EE
    ldr	r0, [sp, #4]
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bcc .Ljp_0803D2EE
    movs	r2, #1
.Ljp_0803D2EE:
    adds	r0, r2, #0
    add	sp, #8
    pop	{r4}
    pop	{r1}
    bx	r1
.Ljp_0803D2F8:
    .4byte gUnk_080F1A66
    .section .text.npc_schedule_after
    .global func_0803DA24
    .thumb_func
func_0803DA24:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803D6B0
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0803D6B4
    movs	r0, #0
    b .Ljp_0803D6E8
.Ljp_0803D6B0:
    .4byte 0x000021CA
.Ljp_0803D6B4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803D6D4
    movs	r0, #4
    b .Ljp_0803D6E8
.Ljp_0803D6D4:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803D6E6
    cmp	r4, #2
    bne .Ljp_0803D6E2
    movs	r0, #3
    b .Ljp_0803D6E8
.Ljp_0803D6E2:
    movs	r0, #1
    b .Ljp_0803D6E8
.Ljp_0803D6E6:
    movs	r0, #2
.Ljp_0803D6E8:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DA7C
    .thumb_func
func_0803DA7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803D73C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Ljp_0803D70A
    b .Ljp_0803D896
.Ljp_0803D70A:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Ljp_0803D740
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    cmp	r4, #3
    bne .Ljp_0803D7DE
    cmp	r7, #2
    bne .Ljp_0803D744
    mov	r0, r8
    cmp	r0, #13
    bne .Ljp_0803D744
    movs	r0, #22
    b .Ljp_0803D8C8
.Ljp_0803D73C:
    .4byte 0x000021CA
.Ljp_0803D740:
    .4byte 0x00001CD4
.Ljp_0803D744:
    ldr r1, .Ljp_0803D758
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803D75C
    movs	r0, #23
    b .Ljp_0803D8C8
    .align 2, 0
.Ljp_0803D758:
    .4byte 0x0000216B
.Ljp_0803D75C:
    ldr r1, .Ljp_0803D794
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Ljp_0803D798
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803D788
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803D788
    cmp	r0, #4
    bne .Ljp_0803D7AC
.Ljp_0803D788:
    cmp	r4, #0
    beq .Ljp_0803D7A0
    cmp	r6, #0
    beq .Ljp_0803D79C
    movs	r0, #13
    b .Ljp_0803D8C8
.Ljp_0803D794:
    .4byte 0x00002148
.Ljp_0803D798:
    .4byte 0x00001CD4
.Ljp_0803D79C:
    movs	r0, #12
    b .Ljp_0803D8C8
.Ljp_0803D7A0:
    cmp	r6, #0
    beq .Ljp_0803D7A8
    movs	r0, #15
    b .Ljp_0803D8C8
.Ljp_0803D7A8:
    movs	r0, #14
    b .Ljp_0803D8C8
.Ljp_0803D7AC:
    cmp	r6, #0
    beq .Ljp_0803D7C2
    mov	r0, r9
    cmp	r0, #0
    bne .Ljp_0803D7C2
    cmp	r4, #0
    beq .Ljp_0803D7BE
    movs	r0, #8
    b .Ljp_0803D8C8
.Ljp_0803D7BE:
    movs	r0, #11
    b .Ljp_0803D8C8
.Ljp_0803D7C2:
    cmp	r4, #0
    beq .Ljp_0803D7D2
    cmp	r6, #0
    beq .Ljp_0803D7CE
    movs	r0, #7
    b .Ljp_0803D8C8
.Ljp_0803D7CE:
    movs	r0, #6
    b .Ljp_0803D8C8
.Ljp_0803D7D2:
    cmp	r6, #0
    beq .Ljp_0803D7DA
    movs	r0, #10
    b .Ljp_0803D8C8
.Ljp_0803D7DA:
    movs	r0, #9
    b .Ljp_0803D8C8
.Ljp_0803D7DE:
    ldr r1, .Ljp_0803D800
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Ljp_0803D812
    cmp	r7, #1
    bne .Ljp_0803D896
    movs	r0, #1
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803D804
    movs	r0, #19
    b .Ljp_0803D8C8
.Ljp_0803D800:
    .4byte 0x00001D6C
.Ljp_0803D804:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803D80E
    movs	r0, #20
    b .Ljp_0803D8C8
.Ljp_0803D80E:
    movs	r0, #21
    b .Ljp_0803D8C8
.Ljp_0803D812:
    cmp	r7, #2
    bne .Ljp_0803D834
    mov	r0, r8
    cmp	r0, #30
    bne .Ljp_0803D834
    ldr r1, .Ljp_0803D830
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803D834
    movs	r0, #17
    b .Ljp_0803D8C8
    .align 2, 0
.Ljp_0803D830:
    .4byte 0x000021A3
.Ljp_0803D834:
    ldr r1, .Ljp_0803D86C
    adds	r0, r5, r1
    movs	r1, #3
    bl func_080A01F8
    cmp	r7, #3
    bne .Ljp_0803D878
    mov	r1, r8
    cmp	r1, #14
    bne .Ljp_0803D878
    cmp	r4, #0
    bne .Ljp_0803D878
    cmp	r0, #0
    beq .Ljp_0803D878
    bl GetLove__C12Bachelorette
    ldr r1, .Ljp_0803D870
    cmp	r0, r1
    bls .Ljp_0803D878
    ldr r1, .Ljp_0803D874
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803D878
    movs	r0, #18
    b .Ljp_0803D8C8
.Ljp_0803D86C:
    .4byte 0x00001CD4
.Ljp_0803D870:
    .4byte 0x0000270F
.Ljp_0803D874:
    .4byte 0x000021A3
.Ljp_0803D878:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803D88A
    movs	r0, #16
    b .Ljp_0803D8C8
.Ljp_0803D88A:
    ldr r1, .Ljp_0803D89C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Ljp_0803D8A0
.Ljp_0803D896:
    movs	r0, #0
    b .Ljp_0803D8C8
    .align 2, 0
.Ljp_0803D89C:
    .4byte 0x0000215A
.Ljp_0803D8A0:
    mov	r0, r9
    cmp	r0, #0
    bne .Ljp_0803D8BC
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803D8B8
    cmp	r7, #1
    bne .Ljp_0803D8B4
    movs	r0, #5
    b .Ljp_0803D8C8
.Ljp_0803D8B4:
    movs	r0, #3
    b .Ljp_0803D8C8
.Ljp_0803D8B8:
    movs	r0, #4
    b .Ljp_0803D8C8
.Ljp_0803D8BC:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803D8C6
    movs	r0, #2
    b .Ljp_0803D8C8
.Ljp_0803D8C6:
    movs	r0, #1
.Ljp_0803D8C8:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DC64
    .thumb_func
func_0803DC64:
    push	{r4, lr}
    sub	sp, #4
    adds	r2, r0, #0
    ldr r1, .Ljp_0803D8F0
    adds	r0, r2, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0803D8F4
    movs	r0, #0
    b .Ljp_0803D91E
.Ljp_0803D8F0:
    .4byte 0x000021CA
.Ljp_0803D8F4:
    mov	r4, sp
    adds	r1, r2, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803D914
    movs	r0, #3
    b .Ljp_0803D91E
.Ljp_0803D914:
    cmp	r4, #0
    beq .Ljp_0803D91C
    movs	r0, #1
    b .Ljp_0803D91E
.Ljp_0803D91C:
    movs	r0, #2
.Ljp_0803D91E:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DCB4
    .thumb_func
func_0803DCB4:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r0, .Ljp_0803D958
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetChild__C13NpcCollection
    cmp	r0, #0
    bne .Ljp_0803D93E
    b .Ljp_0803DA52
.Ljp_0803D93E:
    bl GetAgeDays__C5Child
    cmp	r0, #59	@ 0x3b
    bls .Ljp_0803D948
    b .Ljp_0803DA4E
.Ljp_0803D948:
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #31
    bne .Ljp_0803D95C
    movs	r0, #3
    b .Ljp_0803DA54
.Ljp_0803D958:
    .4byte 0x00001CD4
.Ljp_0803D95C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Ljp_0803D97A
    cmp	r1, #13
    bne .Ljp_0803D97A
    movs	r0, #5
    b .Ljp_0803DA54
.Ljp_0803D97A:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803DA24
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803DA24
    cmp	r0, #4
    beq .Ljp_0803DA24
    ldr r1, .Ljp_0803D9A4
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    subs	r0, r6, #3
    cmp	r0, #28
    bhi .Ljp_0803DA4A
    lsls	r0, r0, #2
    ldr r1, .Ljp_0803D9A8
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0803D9A4:
    .4byte 0x00002148
.Ljp_0803D9A8:
    .4byte .Ljp_0803D9AC
.Ljp_0803D9AC:
    .4byte .Ljp_0803DA28
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA20
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA32
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA40
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA46
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
    .4byte .Ljp_0803DA4A
.Ljp_0803DA20:
    cmp	r4, #1
    bne .Ljp_0803DA4A
.Ljp_0803DA24:
    movs	r0, #2
    b .Ljp_0803DA54
.Ljp_0803DA28:
    cmp	r2, #0
    beq .Ljp_0803DA24
    cmp	r4, #0
    bne .Ljp_0803DA4A
    b .Ljp_0803DA24
.Ljp_0803DA32:
    cmp	r2, #0
    beq .Ljp_0803DA24
    cmp	r4, #2
    beq .Ljp_0803DA24
    cmp	r4, #0
    bne .Ljp_0803DA4A
    b .Ljp_0803DA24
.Ljp_0803DA40:
    cmp	r4, #3
    bne .Ljp_0803DA4A
    b .Ljp_0803DA24
.Ljp_0803DA46:
    cmp	r2, #0
    beq .Ljp_0803DA24
.Ljp_0803DA4A:
    movs	r0, #1
    b .Ljp_0803DA54
.Ljp_0803DA4E:
    movs	r0, #4
    b .Ljp_0803DA54
.Ljp_0803DA52:
    movs	r0, #0
.Ljp_0803DA54:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803DDE8
    .thumb_func
func_0803DDE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DABC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    blt .Ljp_0803DAB6
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    mov	r0, sp
    ldrb	r6, [r0, #0]
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Ljp_0803DAC0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803DAB6
    subs	r1, #12
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Ljp_0803DAC4
    cmp	r6, #1
    bhi .Ljp_0803DAB6
    cmp	r6, #1
    bne .Ljp_0803DAC4
    cmp	r7, #3
    bne .Ljp_0803DAC4
    mov	r0, r8
    cmp	r0, #28
    bls .Ljp_0803DAC4
.Ljp_0803DAB6:
    movs	r0, #0
    b .Ljp_0803DB32
    .align 2, 0
.Ljp_0803DABC:
    .4byte 0x000021CA
.Ljp_0803DAC0:
    .4byte 0x00002181
.Ljp_0803DAC4:
    ldr r1, .Ljp_0803DAD8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803DADC
    movs	r0, #5
    b .Ljp_0803DB32
    .align 2, 0
.Ljp_0803DAD8:
    .4byte 0x00002181
.Ljp_0803DADC:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DAEE
    movs	r0, #4
    b .Ljp_0803DB32
.Ljp_0803DAEE:
    cmp	r6, #1
    bne .Ljp_0803DB10
    cmp	r7, #2
    bne .Ljp_0803DB10
    mov	r0, r8
    cmp	r0, #15
    bne .Ljp_0803DB10
    ldr r1, .Ljp_0803DB0C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803DB10
.Ljp_0803DB08:
    movs	r0, #2
    b .Ljp_0803DB32
.Ljp_0803DB0C:
    .4byte 0x00002175
.Ljp_0803DB10:
    ldr r1, .Ljp_0803DB2C
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Ljp_0803DB30
    cmp	r4, #6
    bne .Ljp_0803DB08
    movs	r0, #3
    b .Ljp_0803DB32
.Ljp_0803DB2C:
    .4byte 0x00002174
.Ljp_0803DB30:
    movs	r0, #1
.Ljp_0803DB32:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DECC
    .thumb_func
func_0803DECC:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803DB62
    movs	r0, #1
    b .Ljp_0803DB64
.Ljp_0803DB62:
    movs	r0, #2
.Ljp_0803DB64:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DEF8
    .thumb_func
func_0803DEF8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DB84
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Ljp_0803DB88
    movs	r0, #0
    b .Ljp_0803DBBC
    .align 2, 0
.Ljp_0803DB84:
    .4byte 0x000021CA
.Ljp_0803DB88:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DBA8
    movs	r0, #4
    b .Ljp_0803DBBC
.Ljp_0803DBA8:
    cmp	r4, #3
    bne .Ljp_0803DBBA
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803DBB6
    movs	r0, #2
    b .Ljp_0803DBBC
.Ljp_0803DBB6:
    movs	r0, #3
    b .Ljp_0803DBBC
.Ljp_0803DBBA:
    movs	r0, #1
.Ljp_0803DBBC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DBC4
    .thumb_func
func_0803DBC4:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Ljp_0803DBDC
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Ljp_0803DBE0
    movs	r0, #0
    b .Ljp_0803DBFE
    .align 2, 0
.Ljp_0803DBDC:
    .4byte 0x000021CA
.Ljp_0803DBE0:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803DBFC
    movs	r0, #1
    b .Ljp_0803DBFE
.Ljp_0803DBFC:
    movs	r0, #2
.Ljp_0803DBFE:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DC08
    .thumb_func
func_0803DC08:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Ljp_0803DC20
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Ljp_0803DC24
    movs	r0, #0
    b .Ljp_0803DC54
    .align 2, 0
.Ljp_0803DC20:
    .4byte 0x000021CA
.Ljp_0803DC24:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DC42
    movs	r0, #4
    b .Ljp_0803DC54
.Ljp_0803DC42:
    cmp	r4, #2
    bne .Ljp_0803DC4A
    movs	r0, #2
    b .Ljp_0803DC54
.Ljp_0803DC4A:
    cmp	r4, #0
    beq .Ljp_0803DC52
    movs	r0, #1
    b .Ljp_0803DC54
.Ljp_0803DC52:
    movs	r0, #3
.Ljp_0803DC54:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DC5C
    .thumb_func
func_0803DC5C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DC7C
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0803DC80
    movs	r0, #0
    b .Ljp_0803DE08
    .align 2, 0
.Ljp_0803DC7C:
    .4byte 0x000021CA
.Ljp_0803DC80:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r7, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Ljp_0803DCB4
    adds	r4, r5, r1
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #19
    bne .Ljp_0803DD5E
    mov	r0, r8
    cmp	r0, #2
    bne .Ljp_0803DCC0
    cmp	r7, #9
    bne .Ljp_0803DCB8
    movs	r0, #21
    b .Ljp_0803DE08
.Ljp_0803DCB4:
    .4byte 0x00001CD4
.Ljp_0803DCB8:
    cmp	r7, #13
    bne .Ljp_0803DCC0
    movs	r0, #22
    b .Ljp_0803DE08
.Ljp_0803DCC0:
    ldr r1, .Ljp_0803DCD4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803DCD8
    movs	r0, #23
    b .Ljp_0803DE08
    .align 2, 0
.Ljp_0803DCD4:
    .4byte 0x0000216C
.Ljp_0803DCD8:
    ldr r1, .Ljp_0803DD10
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Ljp_0803DD14
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803DD04
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803DD04
    cmp	r0, #4
    bne .Ljp_0803DD28
.Ljp_0803DD04:
    cmp	r4, #0
    beq .Ljp_0803DD1C
    cmp	r6, #0
    beq .Ljp_0803DD18
    movs	r0, #18
    b .Ljp_0803DE08
.Ljp_0803DD10:
    .4byte 0x00002148
.Ljp_0803DD14:
    .4byte 0x00001CD4
.Ljp_0803DD18:
    movs	r0, #17
    b .Ljp_0803DE08
.Ljp_0803DD1C:
    cmp	r6, #0
    beq .Ljp_0803DD24
    movs	r0, #20
    b .Ljp_0803DE08
.Ljp_0803DD24:
    movs	r0, #19
    b .Ljp_0803DE08
.Ljp_0803DD28:
    cmp	r6, #0
    beq .Ljp_0803DD42
    mov	r0, r9
    cmp	r0, #0
    beq .Ljp_0803DD36
    cmp	r0, #2
    bne .Ljp_0803DD42
.Ljp_0803DD36:
    cmp	r4, #0
    beq .Ljp_0803DD3E
    movs	r0, #13
    b .Ljp_0803DE08
.Ljp_0803DD3E:
    movs	r0, #16
    b .Ljp_0803DE08
.Ljp_0803DD42:
    cmp	r4, #0
    beq .Ljp_0803DD52
    cmp	r6, #0
    beq .Ljp_0803DD4E
    movs	r0, #12
    b .Ljp_0803DE08
.Ljp_0803DD4E:
    movs	r0, #11
    b .Ljp_0803DE08
.Ljp_0803DD52:
    cmp	r6, #0
    beq .Ljp_0803DD5A
    movs	r0, #15
    b .Ljp_0803DE08
.Ljp_0803DD5A:
    movs	r0, #14
    b .Ljp_0803DE08
.Ljp_0803DD5E:
    ldr r1, .Ljp_0803DD7C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Ljp_0803DD8E
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DD80
    movs	r0, #10
    b .Ljp_0803DE08
.Ljp_0803DD7C:
    .4byte 0x00001EB8
.Ljp_0803DD80:
    mov	r0, r9
    cmp	r0, #0
    bne .Ljp_0803DD8A
    movs	r0, #7
    b .Ljp_0803DE08
.Ljp_0803DD8A:
    movs	r0, #6
    b .Ljp_0803DE08
.Ljp_0803DD8E:
    adds	r0, r4, #0
    movs	r1, #19
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Ljp_0803DDCC
    cmp	r7, #14
    bne .Ljp_0803DDCC
    cmp	r6, #0
    bne .Ljp_0803DDCC
    cmp	r0, #0
    beq .Ljp_0803DDCC
    bl GetLove__C12Bachelorette
    ldr r1, .Ljp_0803DDC4
    cmp	r0, r1
    bls .Ljp_0803DDCC
    ldr r1, .Ljp_0803DDC8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803DDCC
    movs	r0, #9
    b .Ljp_0803DE08
.Ljp_0803DDC4:
    .4byte 0x0000270F
.Ljp_0803DDC8:
    .4byte 0x000021A4
.Ljp_0803DDCC:
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DDDE
    movs	r0, #8
    b .Ljp_0803DE08
.Ljp_0803DDDE:
    mov	r0, r9
    cmp	r0, #0
    bne .Ljp_0803DDE8
    movs	r0, #3
    b .Ljp_0803DE08
.Ljp_0803DDE8:
    mov	r1, r9
    cmp	r1, #2
    bne .Ljp_0803DDFC
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803DDF8
    movs	r0, #4
    b .Ljp_0803DE08
.Ljp_0803DDF8:
    movs	r0, #5
    b .Ljp_0803DE08
.Ljp_0803DDFC:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803DE06
    movs	r0, #2
    b .Ljp_0803DE08
.Ljp_0803DE06:
    movs	r0, #1
.Ljp_0803DE08:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DE18
    .thumb_func
func_0803DE18:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DE30
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Ljp_0803DE34
    movs	r0, #0
    b .Ljp_0803DE68
    .align 2, 0
.Ljp_0803DE30:
    .4byte 0x000021CA
.Ljp_0803DE34:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DE54
    movs	r0, #4
    b .Ljp_0803DE68
.Ljp_0803DE54:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803DE66
    cmp	r4, #2
    bne .Ljp_0803DE62
    movs	r0, #3
    b .Ljp_0803DE68
.Ljp_0803DE62:
    movs	r0, #1
    b .Ljp_0803DE68
.Ljp_0803DE66:
    movs	r0, #2
.Ljp_0803DE68:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DE70
    .thumb_func
func_0803DE70:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DE88
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Ljp_0803DE8C
    movs	r0, #0
    b .Ljp_0803DECE
    .align 2, 0
.Ljp_0803DE88:
    .4byte 0x000021CA
.Ljp_0803DE8C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r4, [r4, #2]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803DEAE
    movs	r0, #2
    b .Ljp_0803DECE
.Ljp_0803DEAE:
    ldr r1, .Ljp_0803DEC8
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    cmp	r6, #2
    bne .Ljp_0803DECC
    cmp	r4, #5
    bne .Ljp_0803DECC
    cmp	r0, #25
    beq .Ljp_0803DECC
    movs	r0, #3
    b .Ljp_0803DECE
    .align 2, 0
.Ljp_0803DEC8:
    .4byte 0x00001CD4
.Ljp_0803DECC:
    movs	r0, #1
.Ljp_0803DECE:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DED8
    .thumb_func
func_0803DED8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803DEF4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Ljp_0803DEF8
    movs	r0, #0
    b .Ljp_0803E072
.Ljp_0803DEF4:
    .4byte 0x000021CA
.Ljp_0803DEF8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r6, [r4, #2]
    ldr r1, .Ljp_0803DF28
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    mov	r0, r8
    cmp	r0, #2
    bne .Ljp_0803DF2C
    cmp	r6, #5
    bne .Ljp_0803DF2C
    cmp	r4, #25
    beq .Ljp_0803DF30
    movs	r0, #5
    b .Ljp_0803E072
    .align 2, 0
.Ljp_0803DF28:
    .4byte 0x00001CD4
.Ljp_0803DF2C:
    cmp	r4, #25
    bne .Ljp_0803DFD8
.Ljp_0803DF30:
    mov	r1, r8
    cmp	r1, #2
    bne .Ljp_0803DF46
    cmp	r6, #9
    bne .Ljp_0803DF3E
    movs	r0, #16
    b .Ljp_0803E072
.Ljp_0803DF3E:
    cmp	r6, #13
    bne .Ljp_0803DF46
    movs	r0, #17
    b .Ljp_0803E072
.Ljp_0803DF46:
    ldr r1, .Ljp_0803DF64
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Ljp_0803DF68
    movs	r0, #18
    b .Ljp_0803E072
.Ljp_0803DF64:
    .4byte 0x0000216B
.Ljp_0803DF68:
    ldr r1, .Ljp_0803DFA4
    adds	r0, r5, r1
    ldrb	r4, [r0, #0]
    ldr r1, .Ljp_0803DFA8
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r7, r1, #31
    mov	r9, r7
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803DF96
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803DF96
    cmp	r0, #4
    bne .Ljp_0803DFBC
.Ljp_0803DF96:
    mov	r0, r9
    cmp	r0, #0
    beq .Ljp_0803DFB0
    cmp	r4, #0
    beq .Ljp_0803DFAC
    movs	r0, #13
    b .Ljp_0803E072
.Ljp_0803DFA4:
    .4byte 0x00002148
.Ljp_0803DFA8:
    .4byte 0x00001CD4
.Ljp_0803DFAC:
    movs	r0, #12
    b .Ljp_0803E072
.Ljp_0803DFB0:
    cmp	r4, #0
    beq .Ljp_0803DFB8
    movs	r0, #15
    b .Ljp_0803E072
.Ljp_0803DFB8:
    movs	r0, #14
    b .Ljp_0803E072
.Ljp_0803DFBC:
    cmp	r7, #0
    beq .Ljp_0803DFCC
    cmp	r4, #0
    beq .Ljp_0803DFC8
    movs	r0, #9
    b .Ljp_0803E072
.Ljp_0803DFC8:
    movs	r0, #8
    b .Ljp_0803E072
.Ljp_0803DFCC:
    cmp	r4, #0
    beq .Ljp_0803DFD4
    movs	r0, #11
    b .Ljp_0803E072
.Ljp_0803DFD4:
    movs	r0, #10
    b .Ljp_0803E072
.Ljp_0803DFD8:
    ldr r1, .Ljp_0803DFFC
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Ljp_0803E004
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803E062
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E000
    movs	r0, #3
    b .Ljp_0803E072
.Ljp_0803DFFC:
    .4byte 0x00001F38
.Ljp_0803E000:
    movs	r0, #4
    b .Ljp_0803E072
.Ljp_0803E004:
    ldr r1, .Ljp_0803E048
    adds	r0, r5, r1
    movs	r1, #25
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Ljp_0803E054
    cmp	r6, #14
    bne .Ljp_0803E054
    cmp	r4, #0
    bne .Ljp_0803E054
    cmp	r0, #0
    beq .Ljp_0803E054
    bl GetLove__C12Bachelorette
    ldr r1, .Ljp_0803E04C
    cmp	r0, r1
    bls .Ljp_0803E054
    ldr r1, .Ljp_0803E050
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #2
    beq .Ljp_0803E054
    movs	r0, #7
    b .Ljp_0803E072
.Ljp_0803E048:
    .4byte 0x00001CD4
.Ljp_0803E04C:
    .4byte 0x0000270F
.Ljp_0803E050:
    .4byte 0x000021A3
.Ljp_0803E054:
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E066
.Ljp_0803E062:
    movs	r0, #6
    b .Ljp_0803E072
.Ljp_0803E066:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803E070
    movs	r0, #2
    b .Ljp_0803E072
.Ljp_0803E070:
    movs	r0, #1
.Ljp_0803E072:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    @ ROM-verified JP Thumb code_0803A8A4/code_0803E448
    .section .text.code_0803E448
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803E0BC
    .thumb_func
func_0803E0BC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E0D4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803E0D8
    movs	r0, #0
    b .Ljp_0803E10C
    .align 2, 0
.Ljp_0803E0D4:
    .4byte 0x000021CA
.Ljp_0803E0D8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E0F8
    movs	r0, #4
    b .Ljp_0803E10C
.Ljp_0803E0F8:
    cmp	r4, #1
    bne .Ljp_0803E10A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E106
    movs	r0, #2
    b .Ljp_0803E10C
.Ljp_0803E106:
    movs	r0, #3
    b .Ljp_0803E10C
.Ljp_0803E10A:
    movs	r0, #1
.Ljp_0803E10C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E114
    .thumb_func
func_0803E114:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E130
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803E134
    movs	r0, #0
    b .Ljp_0803E284
.Ljp_0803E130:
    .4byte 0x000021CA
.Ljp_0803E134:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Ljp_0803E164
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #12
    bne .Ljp_0803E1E2
    cmp	r7, #2
    bne .Ljp_0803E170
    cmp	r6, #9
    bne .Ljp_0803E168
    movs	r0, #16
    b .Ljp_0803E284
.Ljp_0803E164:
    .4byte 0x00001CD4
.Ljp_0803E168:
    cmp	r6, #13
    bne .Ljp_0803E170
    movs	r0, #17
    b .Ljp_0803E284
.Ljp_0803E170:
    ldr r1, .Ljp_0803E184
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803E188
    movs	r0, #18
    b .Ljp_0803E284
    .align 2, 0
.Ljp_0803E184:
    .4byte 0x0000216C
.Ljp_0803E188:
    ldr r1, .Ljp_0803E1BC
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803E1B0
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803E1B0
    cmp	r0, #4
    bne .Ljp_0803E1C4
.Ljp_0803E1B0:
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_0803E1C0
    movs	r0, #14
    b .Ljp_0803E284
    .align 2, 0
.Ljp_0803E1BC:
    .4byte 0x00001CD4
.Ljp_0803E1C0:
    movs	r0, #15
    b .Ljp_0803E284
.Ljp_0803E1C4:
    mov	r1, r9
    cmp	r1, #1
    bne .Ljp_0803E1D6
    cmp	r4, #0
    beq .Ljp_0803E1D2
    movs	r0, #11
    b .Ljp_0803E284
.Ljp_0803E1D2:
    movs	r0, #13
    b .Ljp_0803E284
.Ljp_0803E1D6:
    cmp	r4, #0
    beq .Ljp_0803E1DE
    movs	r0, #10
    b .Ljp_0803E284
.Ljp_0803E1DE:
    movs	r0, #12
    b .Ljp_0803E284
.Ljp_0803E1E2:
    ldr r1, .Ljp_0803E200
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Ljp_0803E21C
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E204
    movs	r0, #9
    b .Ljp_0803E284
.Ljp_0803E200:
    .4byte 0x00001E28
.Ljp_0803E204:
    mov	r0, r9
    cmp	r0, #4
    bne .Ljp_0803E218
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E214
    movs	r0, #5
    b .Ljp_0803E284
.Ljp_0803E214:
    movs	r0, #6
    b .Ljp_0803E284
.Ljp_0803E218:
    movs	r0, #4
    b .Ljp_0803E284
.Ljp_0803E21C:
    adds	r0, r4, #0
    movs	r1, #12
    bl func_080A01F8
    cmp	r7, #3
    bne .Ljp_0803E25C
    cmp	r6, #14
    bne .Ljp_0803E25C
    mov	r1, r8
    cmp	r1, #0
    bne .Ljp_0803E25C
    cmp	r0, #0
    beq .Ljp_0803E25C
    bl GetLove__C12Bachelorette
    ldr r1, .Ljp_0803E254
    cmp	r0, r1
    bls .Ljp_0803E25C
    ldr r1, .Ljp_0803E258
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803E25C
    movs	r0, #7
    b .Ljp_0803E284
    .align 2, 0
.Ljp_0803E254:
    .4byte 0x0000270F
.Ljp_0803E258:
    .4byte 0x000021A5
.Ljp_0803E25C:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E26E
    movs	r0, #8
    b .Ljp_0803E284
.Ljp_0803E26E:
    mov	r0, r9
    cmp	r0, #1
    bne .Ljp_0803E282
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E27E
    movs	r0, #2
    b .Ljp_0803E284
.Ljp_0803E27E:
    movs	r0, #3
    b .Ljp_0803E284
.Ljp_0803E282:
    movs	r0, #1
.Ljp_0803E284:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E294
    .thumb_func
func_0803E294:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E2AC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803E2B0
    movs	r0, #0
    b .Ljp_0803E2EE
    .align 2, 0
.Ljp_0803E2AC:
    .4byte 0x000021CA
.Ljp_0803E2B0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E2D0
    movs	r0, #5
    b .Ljp_0803E2EE
.Ljp_0803E2D0:
    cmp	r4, #1
    bne .Ljp_0803E2E2
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E2DE
    movs	r0, #3
    b .Ljp_0803E2EE
.Ljp_0803E2DE:
    movs	r0, #4
    b .Ljp_0803E2EE
.Ljp_0803E2E2:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803E2EC
    movs	r0, #2
    b .Ljp_0803E2EE
.Ljp_0803E2EC:
    movs	r0, #1
.Ljp_0803E2EE:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E2F8
    .thumb_func
func_0803E2F8:
    .global func_0803E684
    .thumb_func
func_0803E684:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    adds	r6, r0, #0
    ldrb	r0, [r4, #2]
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E324
    movs	r0, #2
    b .Ljp_0803E356
.Ljp_0803E324:
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #4]
    ldrb	r0, [r5, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #8]
    add	r2, sp, #8
    add	r0, sp, #4
    cmp	r3, r1
    bls .Ljp_0803E342
    adds	r0, r2, #0
.Ljp_0803E342:
    ldr	r0, [r0, #0]
    cmp	r0, #1
    bhi .Ljp_0803E354
    cmp	r6, #0
    bne .Ljp_0803E354
    cmp	r4, #2
    bhi .Ljp_0803E354
    movs	r0, #0
    b .Ljp_0803E356
.Ljp_0803E354:
    movs	r0, #1
.Ljp_0803E356:
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E360
    .thumb_func
func_0803E360:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r3, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #3
    bne .Ljp_0803E3B4
    cmp	r3, #2
    bne .Ljp_0803E3B4
    ldr r1, .Ljp_0803E3A8
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #134	@ 0x86
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #6
    cmp	r0, r1
    bne .Ljp_0803E3B4
    ldr r1, .Ljp_0803E3AC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803E3B0
    movs	r0, #7
    b .Ljp_0803E3EC
    .align 2, 0
.Ljp_0803E3A8:
    .4byte 0x00002178
.Ljp_0803E3AC:
    .4byte 0x0000217A
.Ljp_0803E3B0:
    movs	r0, #0
    b .Ljp_0803E3EC
.Ljp_0803E3B4:
    adds	r0, r2, #0
    adds	r1, r3, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E3C6
    movs	r0, #6
    b .Ljp_0803E3EC
.Ljp_0803E3C6:
    cmp	r4, #6
    bne .Ljp_0803E3D8
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E3D4
    movs	r0, #2
    b .Ljp_0803E3EC
.Ljp_0803E3D4:
    movs	r0, #3
    b .Ljp_0803E3EC
.Ljp_0803E3D8:
    cmp	r4, #0
    bne .Ljp_0803E3EA
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E3E6
    movs	r0, #4
    b .Ljp_0803E3EC
.Ljp_0803E3E6:
    movs	r0, #5
    b .Ljp_0803E3EC
.Ljp_0803E3EA:
    movs	r0, #1
.Ljp_0803E3EC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E3F4
    .thumb_func
func_0803E3F4:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E410
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Ljp_0803E414
    movs	r0, #0
    b .Ljp_0803E54E
.Ljp_0803E410:
    .4byte 0x000021CA
.Ljp_0803E414:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Ljp_0803E444
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #21
    bne .Ljp_0803E4C2
    cmp	r7, #2
    bne .Ljp_0803E450
    cmp	r6, #9
    bne .Ljp_0803E448
    movs	r0, #14
    b .Ljp_0803E54E
.Ljp_0803E444:
    .4byte 0x00001CD4
.Ljp_0803E448:
    cmp	r6, #13
    bne .Ljp_0803E450
    movs	r0, #15
    b .Ljp_0803E54E
.Ljp_0803E450:
    ldr r1, .Ljp_0803E464
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Ljp_0803E468
    movs	r0, #16
    b .Ljp_0803E54E
    .align 2, 0
.Ljp_0803E464:
    .4byte 0x0000216C
.Ljp_0803E468:
    ldr r1, .Ljp_0803E49C
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803E490
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Ljp_0803E490
    cmp	r0, #4
    bne .Ljp_0803E4A4
.Ljp_0803E490:
    mov	r0, r8
    cmp	r0, #0
    beq .Ljp_0803E4A0
    movs	r0, #12
    b .Ljp_0803E54E
    .align 2, 0
.Ljp_0803E49C:
    .4byte 0x00001CD4
.Ljp_0803E4A0:
    movs	r0, #13
    b .Ljp_0803E54E
.Ljp_0803E4A4:
    mov	r1, r9
    cmp	r1, #3
    bne .Ljp_0803E4B6
    cmp	r4, #0
    beq .Ljp_0803E4B2
    movs	r0, #9
    b .Ljp_0803E54E
.Ljp_0803E4B2:
    movs	r0, #11
    b .Ljp_0803E54E
.Ljp_0803E4B6:
    cmp	r4, #0
    beq .Ljp_0803E4BE
    movs	r0, #8
    b .Ljp_0803E54E
.Ljp_0803E4BE:
    movs	r0, #10
    b .Ljp_0803E54E
.Ljp_0803E4C2:
    ldr r1, .Ljp_0803E4E0
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Ljp_0803E4F2
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E4E4
    movs	r0, #7
    b .Ljp_0803E54E
.Ljp_0803E4E0:
    .4byte 0x00001EE4
.Ljp_0803E4E4:
    mov	r0, r9
    cmp	r0, #3
    bne .Ljp_0803E4EE
    movs	r0, #4
    b .Ljp_0803E54E
.Ljp_0803E4EE:
    movs	r0, #3
    b .Ljp_0803E54E
.Ljp_0803E4F2:
    adds	r0, r4, #0
    movs	r1, #21
    bl func_080A01F8
    cmp	r7, #3
    bne .Ljp_0803E530
    cmp	r6, #14
    bne .Ljp_0803E530
    mov	r1, r8
    cmp	r1, #0
    bne .Ljp_0803E530
    cmp	r0, #0
    beq .Ljp_0803E530
    bl GetLove__C12Bachelorette
    ldr r1, .Ljp_0803E528
    cmp	r0, r1
    bls .Ljp_0803E530
    ldr r1, .Ljp_0803E52C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803E530
    movs	r0, #6
    b .Ljp_0803E54E
.Ljp_0803E528:
    .4byte 0x0000270F
.Ljp_0803E52C:
    .4byte 0x000021A4
.Ljp_0803E530:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E542
    movs	r0, #5
    b .Ljp_0803E54E
.Ljp_0803E542:
    mov	r0, r9
    cmp	r0, #3
    beq .Ljp_0803E54C
    movs	r0, #1
    b .Ljp_0803E54E
.Ljp_0803E54C:
    movs	r0, #2
.Ljp_0803E54E:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803E55C
    .thumb_func
func_0803E55C:
    .global func_0803E8E8
    .thumb_func
func_0803E8E8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E598
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    blt .Ljp_0803E5BC
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #2
    bne .Ljp_0803E5A0
    cmp	r1, #30
    bne .Ljp_0803E5A0
    ldr r3, .Ljp_0803E59C
    adds	r0, r5, r3
    ldrb	r0, [r0, #0]
    lsrs	r0, r0, #6
    cmp	r0, #2
    beq .Ljp_0803E5A0
    movs	r0, #5
    b .Ljp_0803E5DC
.Ljp_0803E598:
    .4byte 0x000021CA
.Ljp_0803E59C:
    .4byte 0x000021A2
.Ljp_0803E5A0:
    adds	r0, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E5B0
    movs	r0, #4
    b .Ljp_0803E5DC
.Ljp_0803E5B0:
    ldr r1, .Ljp_0803E5C0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Ljp_0803E5C4
.Ljp_0803E5BC:
    movs	r0, #0
    b .Ljp_0803E5DC
.Ljp_0803E5C0:
    .4byte 0x0000215A
.Ljp_0803E5C4:
    cmp	r4, #1
    beq .Ljp_0803E5CC
    cmp	r4, #3
    bne .Ljp_0803E5D0
.Ljp_0803E5CC:
    movs	r0, #3
    b .Ljp_0803E5DC
.Ljp_0803E5D0:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803E5DA
    movs	r0, #2
    b .Ljp_0803E5DC
.Ljp_0803E5DA:
    movs	r0, #1
.Ljp_0803E5DC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E5E4
    .thumb_func
func_0803E5E4:
    .global func_0803E970
    .thumb_func
func_0803E970:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    adds	r6, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E60C
    movs	r0, #5
    b .Ljp_0803E64E
.Ljp_0803E60C:
    ldr r1, .Ljp_0803E61C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Ljp_0803E620
    movs	r0, #0
    b .Ljp_0803E64E
.Ljp_0803E61C:
    .4byte 0x000021CA
.Ljp_0803E620:
    ldr r1, .Ljp_0803E63C
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Ljp_0803E644
    cmp	r4, #6
    bne .Ljp_0803E640
    movs	r0, #4
    b .Ljp_0803E64E
.Ljp_0803E63C:
    .4byte 0x00002174
.Ljp_0803E640:
    movs	r0, #3
    b .Ljp_0803E64E
.Ljp_0803E644:
    cmp	r6, #6
    beq .Ljp_0803E64C
    movs	r0, #1
    b .Ljp_0803E64E
.Ljp_0803E64C:
    movs	r0, #2
.Ljp_0803E64E:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E658
    .thumb_func
func_0803E658:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r2, [r4, #3]
    adds	r4, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E680
    movs	r0, #5
    b .Ljp_0803E6C6
.Ljp_0803E680:
    ldr r1, .Ljp_0803E690
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Ljp_0803E694
    movs	r0, #0
    b .Ljp_0803E6C6
.Ljp_0803E690:
    .4byte 0x000021CA
.Ljp_0803E694:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E6C4
    cmp	r4, #6
    bne .Ljp_0803E6C0
    ldr r1, .Ljp_0803E6B8
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Ljp_0803E6BC
    movs	r0, #4
    b .Ljp_0803E6C6
    .align 2, 0
.Ljp_0803E6B8:
    .4byte 0x00002174
.Ljp_0803E6BC:
    movs	r0, #3
    b .Ljp_0803E6C6
.Ljp_0803E6C0:
    movs	r0, #1
    b .Ljp_0803E6C6
.Ljp_0803E6C4:
    movs	r0, #2
.Ljp_0803E6C6:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .section .text.npc_schedule_van_after, "ax", %progbits
    .align 2, 0
    .global func_0803E70C
    .thumb_func
func_0803E70C:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Ljp_0803E724
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Ljp_0803E728
    movs	r0, #0
    b .Ljp_0803E746
    .align 2, 0
.Ljp_0803E724:
    .4byte 0x000021CA
.Ljp_0803E728:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803E744
    movs	r0, #1
    b .Ljp_0803E746
.Ljp_0803E744:
    movs	r0, #2
.Ljp_0803E746:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E750
    .thumb_func
func_0803E750:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E768
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #124	@ 0x7c
    ands	r0, r1
    cmp	r0, #0
    beq .Ljp_0803E76C
    movs	r0, #0
    b .Ljp_0803E7AC
.Ljp_0803E768:
    .4byte 0x000021CA
.Ljp_0803E76C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Ljp_0803E78A
    cmp	r1, #3
    bne .Ljp_0803E78A
    movs	r0, #9
    b .Ljp_0803E7AC
.Ljp_0803E78A:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E798
    movs	r0, #8
    b .Ljp_0803E7AC
.Ljp_0803E798:
    cmp	r4, #1
    beq .Ljp_0803E7A6
    cmp	r4, #3
    beq .Ljp_0803E7A6
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Ljp_0803E7AA
.Ljp_0803E7A6:
    movs	r0, #1
    b .Ljp_0803E7AC
.Ljp_0803E7AA:
    movs	r0, #2
.Ljp_0803E7AC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E7B4
    .thumb_func
func_0803E7B4:
    .global func_0803EB40
    .thumb_func
func_0803EB40:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E7EC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    blt .Ljp_0803E806
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #1
    bne .Ljp_0803E806
    movs	r0, #1
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E7F0
    movs	r0, #4
    b .Ljp_0803E808
.Ljp_0803E7EC:
    .4byte 0x000021CA
.Ljp_0803E7F0:
    cmp	r4, #0
    bne .Ljp_0803E802
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E7FE
    movs	r0, #2
    b .Ljp_0803E808
.Ljp_0803E7FE:
    movs	r0, #3
    b .Ljp_0803E808
.Ljp_0803E802:
    movs	r0, #1
    b .Ljp_0803E808
.Ljp_0803E806:
    movs	r0, #0
.Ljp_0803E808:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E810
    .thumb_func
func_0803E810:
    .global func_0803EB9C
    .thumb_func
func_0803EB9C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E82C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803E830
    movs	r0, #0
    b .Ljp_0803E8AA
    .align 2, 0
.Ljp_0803E82C:
    .4byte 0x000021CA
.Ljp_0803E830:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Ljp_0803E864
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    adds	r7, r0, #0
    cmp	r7, #4
    bls .Ljp_0803E87E
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E868
    movs	r0, #9
    b .Ljp_0803E8AA
.Ljp_0803E864:
    .4byte 0x00001E28
.Ljp_0803E868:
    cmp	r4, #4
    bne .Ljp_0803E87A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E876
    movs	r0, #6
    b .Ljp_0803E8AA
.Ljp_0803E876:
    movs	r0, #7
    b .Ljp_0803E8AA
.Ljp_0803E87A:
    movs	r0, #5
    b .Ljp_0803E8AA
.Ljp_0803E87E:
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E890
    movs	r0, #8
    b .Ljp_0803E8AA
.Ljp_0803E890:
    cmp	r7, #0
    beq .Ljp_0803E8A8
    cmp	r4, #1
    bne .Ljp_0803E89C
    movs	r0, #3
    b .Ljp_0803E8AA
.Ljp_0803E89C:
    cmp	r4, #4
    bne .Ljp_0803E8A4
    movs	r0, #4
    b .Ljp_0803E8AA
.Ljp_0803E8A4:
    movs	r0, #2
    b .Ljp_0803E8AA
.Ljp_0803E8A8:
    movs	r0, #1
.Ljp_0803E8AA:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E8B8
    .thumb_func
func_0803E8B8:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Ljp_0803E8D0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Ljp_0803E8D4
    movs	r0, #0
    b .Ljp_0803E92C
    .align 2, 0
.Ljp_0803E8D0:
    .4byte 0x000021CA
.Ljp_0803E8D4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E8F4
    movs	r0, #4
    b .Ljp_0803E92C
.Ljp_0803E8F4:
    ldr r0, .Ljp_0803E914
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetOrder__C7Saibara
    cmp	r0, #0
    beq .Ljp_0803E918
    adds	r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803E918
    movs	r0, #5
    b .Ljp_0803E92C
    .align 2, 0
.Ljp_0803E914:
    .4byte 0x00001DAC
.Ljp_0803E918:
    cmp	r6, #4
    bne .Ljp_0803E92A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803E926
    movs	r0, #2
    b .Ljp_0803E92C
.Ljp_0803E926:
    movs	r0, #3
    b .Ljp_0803E92C
.Ljp_0803E92A:
    movs	r0, #1
.Ljp_0803E92C:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803E934
    .thumb_func
func_0803E934:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803E95A
    movs	r0, #5
    b .Ljp_0803EA38
.Ljp_0803E95A:
    ldr	r7, [r5, #8]
    ldr r0, .Ljp_0803E99C
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #0
    beq .Ljp_0803EA18
    adds	r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803EA18
    adds	r0, r4, #0
    bl IsConstructionOrderedToday__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Ljp_0803EA18
    subs	r0, r7, #3
    cmp	r0, #1
    bls .Ljp_0803EA18
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #13
    bhi .Ljp_0803EA18
    lsls	r0, r0, #2
    ldr r1, .Ljp_0803E9A0
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Ljp_0803E99C:
    .4byte 0x00001F64
.Ljp_0803E9A0:
    .4byte .Ljp_0803E9A4
.Ljp_0803E9A4:
    .4byte .Ljp_0803EA18
    .4byte .Ljp_0803E9DC
    .4byte .Ljp_0803EA00
    .4byte .Ljp_0803EA04
    .4byte .Ljp_0803EA08
    .4byte .Ljp_0803EA0C
    .4byte .Ljp_0803EA0C
    .4byte .Ljp_0803EA0C
    .4byte .Ljp_0803EA10
    .4byte .Ljp_0803EA10
    .4byte .Ljp_0803EA10
    .4byte .Ljp_0803EA14
    .4byte .Ljp_0803EA14
    .4byte .Ljp_0803EA14
.Ljp_0803E9DC:
    movs	r1, #250	@ 0xfa
    lsls	r1, r1, #1
    adds	r0, r5, r1
    bl GetUpgradeLevel__C9FarmHouse
    cmp	r0, #1
    beq .Ljp_0803E9F8
    cmp	r0, #1
    bcc .Ljp_0803E9F4
    cmp	r0, #2
    beq .Ljp_0803E9FC
    b .Ljp_0803EA18
.Ljp_0803E9F4:
    movs	r0, #6
    b .Ljp_0803EA38
.Ljp_0803E9F8:
    movs	r0, #7
    b .Ljp_0803EA38
.Ljp_0803E9FC:
    movs	r0, #13
    b .Ljp_0803EA38
.Ljp_0803EA00:
    movs	r0, #8
    b .Ljp_0803EA38
.Ljp_0803EA04:
    movs	r0, #9
    b .Ljp_0803EA38
.Ljp_0803EA08:
    movs	r0, #14
    b .Ljp_0803EA38
.Ljp_0803EA0C:
    movs	r0, #10
    b .Ljp_0803EA38
.Ljp_0803EA10:
    movs	r0, #11
    b .Ljp_0803EA38
.Ljp_0803EA14:
    movs	r0, #12
    b .Ljp_0803EA38
.Ljp_0803EA18:
    cmp	r6, #5
    bgt .Ljp_0803EA26
    cmp	r6, #4
    bge .Ljp_0803EA2E
    cmp	r6, #0
    beq .Ljp_0803EA36
    b .Ljp_0803EA2A
.Ljp_0803EA26:
    cmp	r6, #6
    beq .Ljp_0803EA32
.Ljp_0803EA2A:
    movs	r0, #1
    b .Ljp_0803EA38
.Ljp_0803EA2E:
    movs	r0, #2
    b .Ljp_0803EA38
.Ljp_0803EA32:
    movs	r0, #3
    b .Ljp_0803EA38
.Ljp_0803EA36:
    movs	r0, #4
.Ljp_0803EA38:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EA40
    .thumb_func
func_0803EA40:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    adds	r7, r0, #0
    ldrb	r4, [r4, #3]
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803EA6C
    movs	r0, #5
    b .Ljp_0803EABC
.Ljp_0803EA6C:
    cmp	r6, #2
    bne .Ljp_0803EA8C
    cmp	r7, #30
    bne .Ljp_0803EA8C
    ldr r1, .Ljp_0803EA88
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Ljp_0803EA8C
    movs	r0, #6
    b .Ljp_0803EABC
    .align 2, 0
.Ljp_0803EA88:
    .4byte 0x000021A2
.Ljp_0803EA8C:
    ldr r1, .Ljp_0803EA9C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Ljp_0803EAA0
    movs	r0, #0
    b .Ljp_0803EABC
.Ljp_0803EA9C:
    .4byte 0x0000215A
.Ljp_0803EAA0:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803EABA
    cmp	r4, #1
    bne .Ljp_0803EAAE
    movs	r0, #1
    b .Ljp_0803EABC
.Ljp_0803EAAE:
    cmp	r4, #3
    bne .Ljp_0803EAB6
    movs	r0, #2
    b .Ljp_0803EABC
.Ljp_0803EAB6:
    movs	r0, #3
    b .Ljp_0803EABC
.Ljp_0803EABA:
    movs	r0, #4
.Ljp_0803EABC:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EAC4
    .thumb_func
func_0803EAC4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Ljp_0803EAEA
    movs	r0, #4
    b .Ljp_0803EAFE
.Ljp_0803EAEA:
    cmp	r4, #1
    bne .Ljp_0803EAFC
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Ljp_0803EAF8
    movs	r0, #2
    b .Ljp_0803EAFE
.Ljp_0803EAF8:
    movs	r0, #3
    b .Ljp_0803EAFE
.Ljp_0803EAFC:
    movs	r0, #1
.Ljp_0803EAFE:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .else
    .ifdef REGION_EU
    @ ROM-verified EU Thumb code_0803A8A4/main
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .section .text.ui_text_window_native, "ax", %progbits
    .align 2, 0
    .global __12UiTextWindowiiUiUiUiUiUiUi
    .thumb_func
__12UiTextWindowiiUiUiUiUiUiUi:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    mov	ip, r0
    ldr	r0, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #48]	@ 0x30
    ldr	r4, [sp, #52]	@ 0x34
    ldr	r6, [sp, #56]	@ 0x38
    movs	r7, #0
    mov	r9, r7
    mov	r7, ip
    strh	r1, [r7, #0]
    strh	r2, [r7, #2]
    strh	r3, [r7, #4]
    strh	r0, [r7, #6]
    movs	r0, #3
    ands	r5, r0
    ldrb	r0, [r7, #8]
    movs	r1, #4
    negs	r1, r1
    mov	r8, r1
    mov	r2, r8
    ands	r2, r0
    orrs	r2, r5
    adds	r0, r4, #0
    movs	r7, #31
    ands	r0, r7
    lsls	r0, r0, #2
    subs	r1, #121	@ 0x79
    ands	r2, r1
    orrs	r2, r0
    mov	r8, r2
    mov	r0, ip
    strb	r2, [r0, #8]
    lsrs	r1, r4, #3
    movs	r0, #3
    ands	r1, r0
    lsls	r1, r1, #7
    mov	r2, ip
    ldrh	r0, [r2, #8]
    ldr r3, .Leu_0803BA90
    ands	r3, r0
    orrs	r3, r1
    strh	r3, [r2, #8]
    movs	r0, #7
    ands	r4, r0
    lsls	r4, r4, #6
    adds	r4, #20
    ldr r7, .Leu_0803BA94
    str	r7, [sp, #0]
    lsls	r4, r4, #9
    ldr	r5, [r2, #8]
    ldr r0, .Leu_0803BA98
    ands	r5, r0
    orrs	r5, r4
    str	r5, [r2, #8]
    movs	r0, #15
    ands	r6, r0
    lsls	r6, r6, #3
    ldrb	r0, [r2, #10]
    movs	r1, #121	@ 0x79
    negs	r1, r1
    mov	sl, r1
    mov	r2, sl
    ands	r2, r0
    orrs	r2, r6
    mov	sl, r2
    mov	r6, ip
    strb	r2, [r6, #10]
    movs	r0, #255	@ 0xff
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r0
    lsls	r1, r1, #7
    ldrh	r2, [r6, #10]
    ldr r0, .Leu_0803BA9C
    ands	r0, r2
    orrs	r0, r1
    strh	r0, [r6, #10]
    ldrb	r1, [r6, #11]
    movs	r0, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r6, #11]
    ldrb	r1, [r6, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #12]
    movs	r7, #0
    strb	r7, [r6, #13]
    mov	r2, ip
    adds	r2, #16
    mov	r0, r9
    str	r0, [r6, #16]
    str	r0, [r2, #4]
    ldr r0, .Leu_0803BAA0
    str	r0, [r2, #8]
    adds	r1, r2, #0
    adds	r1, #16
    str	r1, [r2, #12]
    mov	r6, r9
    str	r6, [r1, #4]
    ldr r0, .Leu_0803BAA4
    str	r0, [r1, #8]
    mov	r0, ip
    adds	r0, #28
    str	r0, [r2, #16]
    str	r1, [r2, #20]
    lsls	r3, r3, #23
    lsrs	r3, r3, #30
    lsls	r5, r5, #13
    lsrs	r7, r5, #22
    lsls	r3, r3, #9
    adds	r2, r3, r7
    ldr r0, .Leu_0803BAA8
    ldr	r0, [r0, #0]
    lsrs	r5, r0, #5
    movs	r4, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Leu_0803B9D8
    movs	r4, #1
.Leu_0803B9D8:
    mov	r1, ip
    adds	r1, #44	@ 0x2c
    ldr r0, .Leu_0803BAAC
    ldr	r3, [r0, #0]
    lsls	r2, r2, #5
    movs	r0, #192	@ 0xc0
    lsls	r0, r0, #19
    adds	r2, r2, r0
    mov	r6, r9
    mov	r0, ip
    str	r6, [r0, #44]	@ 0x2c
    str	r6, [r1, #4]
    ldr r0, .Leu_0803BAB0
    str	r0, [r1, #8]
    str	r3, [r1, #12]
    str	r2, [r1, #16]
    strb	r5, [r1, #20]
    strb	r4, [r1, #21]
    movs	r2, #0
    strb	r2, [r1, #22]
    mov	r6, ip
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    cmp	r0, #0
    bge .Leu_0803BA0C
    adds	r0, #7
.Leu_0803BA0C:
    asrs	r0, r0, #3
    str	r0, [sp, #4]
    mov	r2, ip
    movs	r0, #2
    ldrsh	r6, [r2, r0]
    cmp	r6, #0
    bge .Leu_0803BA1C
    adds	r6, #7
.Leu_0803BA1C:
    asrs	r6, r6, #3
    str	r6, [sp, #8]
    mov	r1, ip
    ldrh	r4, [r1, #4]
    lsrs	r4, r4, #3
    ldrh	r1, [r1, #6]
    lsrs	r1, r1, #3
    mov	r2, r8
    lsls	r3, r2, #25
    lsrs	r3, r3, #27
    mov	r6, sl
    lsls	r5, r6, #25
    mov	r2, ip
    adds	r2, #68	@ 0x44
    mov	r0, r9
    mov	r6, ip
    str	r0, [r6, #68]	@ 0x44
    str	r0, [r2, #4]
    ldr r0, .Leu_0803BAB4
    str	r0, [r2, #8]
    ldr	r0, [sp, #4]
    str	r0, [r2, #12]
    ldr	r6, [sp, #8]
    str	r6, [r2, #16]
    str	r4, [r2, #20]
    str	r1, [r2, #24]
    movs	r0, #31
    ands	r3, r0
    ldrb	r1, [r2, #28]
    subs	r0, #63	@ 0x3f
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #28]
    ldr	r1, [sp, #0]
    ands	r7, r1
    lsls	r3, r7, #5
    ldrh	r1, [r2, #28]
    ldr r0, .Leu_0803BAB8
    ands	r0, r1
    orrs	r0, r3
    strh	r0, [r2, #28]
    lsrs	r5, r5, #28
    lsls	r5, r5, #15
    ldr	r0, [r2, #28]
    ldr r1, .Leu_0803BABC
    ands	r0, r1
    orrs	r0, r5
    str	r0, [r2, #28]
    mov	r0, ip
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Leu_0803BA90:
    .4byte 0xFFFFFE7F
.Leu_0803BA94:
    .4byte 0x000003FF
.Leu_0803BA98:
    .4byte 0xFFF801FF
.Leu_0803BA9C:
    .4byte 0xFFFF807F
.Leu_0803BAA0:
    .4byte __vt_18HardwareLinkedList
.Leu_0803BAA4:
    .4byte __vt_12HardwareLink
.Leu_0803BAA8:
    .4byte gUiSharedTileByteCount
.Leu_0803BAAC:
    .4byte gUiSharedTiles
.Leu_0803BAB0:
    .4byte __vt_29UiTextWindowTileUploadCommand
.Leu_0803BAB4:
    .4byte __vt_25UiTextWindowBorderCommand
.Leu_0803BAB8:
    .4byte 0xFFFF801F
.Leu_0803BABC:
    .4byte 0xFFF87FFF
    .global Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2
    .thumb_func
Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    adds	r4, r2, #0
    mov	sl, r3
    ldrb	r2, [r7, #11]
    lsrs	r1, r2, #7
    ldrb	r0, [r7, #12]
    movs	r3, #127	@ 0x7f
    ands	r0, r3
    lsls	r0, r0, #1
    orrs	r0, r1
    cmp	r0, #1
    beq .Leu_0803BAF0
    cmp	r0, #1
    ble .Leu_0803BB2C
    cmp	r0, #2
    beq .Leu_0803BB10
    b .Leu_0803BB2C
.Leu_0803BAF0:
    ldrb	r0, [r7, #13]
    cmp	r0, #8
    bls .Leu_0803BB0C
    movs	r0, #128	@ 0x80
    orrs	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r7, #12]
    b .Leu_0803BB2C
.Leu_0803BB0C:
    adds	r0, #1
    b .Leu_0803BB2A
.Leu_0803BB10:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    bne .Leu_0803BB28
    adds	r0, r3, #0
    ands	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r7, #12]
    b .Leu_0803BB2C
.Leu_0803BB28:
    subs	r0, #1
.Leu_0803BB2A:
    strb	r0, [r7, #13]
.Leu_0803BB2C:
    adds	r3, r7, #0
    adds	r3, #16
    movs	r2, #0
    adds	r1, r3, #0
    adds	r1, #16
    ldr	r0, [r3, #12]
    cmp	r0, r1
    bne .Leu_0803BB3E
    movs	r2, #1
.Leu_0803BB3E:
    cmp	r2, #0
    bne .Leu_0803BB4E
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #28]
    adds	r0, r4, #0
    adds	r1, r3, #0
    bl _call_via_r2
.Leu_0803BB4E:
    ldrb	r0, [r7, #11]
    lsrs	r0, r0, #7
    ldrb	r1, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r1, r2
    lsls	r1, r1, #1
    orrs	r1, r0
    cmp	r1, #0
    bne .Leu_0803BB62
    b .Leu_0803BCBC
.Leu_0803BB62:
    movs	r0, #0
    mov	r8, r0
    ldrb	r4, [r7, #8]
    lsls	r2, r4, #30
    lsrs	r2, r2, #30
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    lsls	r0, r2
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #6
    adds	r1, r3, #0
    orrs	r0, r1
    mov	r5, r9
    ldrh	r1, [r5, #0]
    orrs	r0, r1
    strh	r0, [r5, #0]
    lsls	r3, r2, #1
    lsls	r2, r2, #2
    mov	r5, sp
    ldrh	r1, [r7, #8]
    lsls	r1, r1, #23
    lsrs	r1, r1, #30
    lsls	r1, r1, #2
    lsls	r0, r4, #25
    lsrs	r0, r0, #27
    lsls	r0, r0, #8
    orrs	r1, r0
    movs	r0, #64	@ 0x40
    orrs	r1, r0
    strh	r1, [r5, #0]
    adds	r3, #8
    add	r3, r9
    strh	r1, [r3, #0]
    mov	r0, sp
    mov	r1, r8
    strh	r1, [r0, #0]
    adds	r0, r2, #0
    adds	r0, #16
    add	r0, r9
    strh	r1, [r0, #0]
    mov	r1, sp
    ldrh	r5, [r7, #2]
    negs	r0, r5
    strh	r0, [r1, #0]
    adds	r2, #18
    add	r2, r9
    strh	r0, [r2, #0]
    ldrb	r6, [r7, #13]
    strb	r4, [r1, #4]
    cmp	r6, #8
    bls .Leu_0803BBF0
    mov	r3, sp
    ldrh	r0, [r7, #0]
    lsls	r2, r0, #8
    ldrh	r1, [r7, #4]
    adds	r0, r0, r1
    orrs	r2, r0
    strh	r2, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r2, [r0, #0]
    mov	r2, sp
    lsls	r1, r5, #8
    ldrh	r0, [r7, #6]
    adds	r0, r5, r0
    orrs	r1, r0
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #68	@ 0x44
    strh	r1, [r0, #0]
    b .Leu_0803BC58
.Leu_0803BBF0:
    ldrh	r4, [r7, #6]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    mov	r8, r0
    movs	r2, #2
    ldrsh	r5, [r7, r2]
    adds	r4, r5, r4
    adds	r5, r5, r4
    lsrs	r0, r5, #31
    adds	r5, r5, r0
    asrs	r5, r5, #1
    mov	r3, r8
    lsrs	r0, r3, #31
    add	r0, r8
    asrs	r0, r0, #1
    subs	r5, r5, r0
    ldrh	r4, [r7, #4]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    movs	r1, #0
    ldrsh	r2, [r7, r1]
    adds	r4, r2, r4
    adds	r2, r2, r4
    lsrs	r1, r2, #31
    adds	r2, r2, r1
    asrs	r2, r2, #1
    lsrs	r1, r0, #31
    adds	r1, r0, r1
    asrs	r1, r1, #1
    subs	r2, r2, r1
    mov	r3, sp
    lsls	r1, r2, #8
    adds	r2, r2, r0
    orrs	r1, r2
    strh	r1, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r1, [r0, #0]
    mov	r1, sp
    lsls	r0, r5, #8
    add	r5, r8
    orrs	r0, r5
    strh	r0, [r1, #0]
    mov	r1, r9
    adds	r1, #68	@ 0x44
    strh	r0, [r1, #0]
.Leu_0803BC58:
    mov	r0, sp
    movs	r1, #63	@ 0x3f
    strh	r1, [r0, #0]
    mov	r3, r9
    adds	r3, #72	@ 0x48
    strh	r1, [r3, #0]
    mov	r2, sp
    ldrb	r4, [r2, #4]
    lsls	r0, r4, #30
    lsrs	r0, r0, #30
    movs	r4, #1
    lsls	r4, r0
    bics	r1, r4
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #74	@ 0x4a
    strh	r1, [r0, #0]
    ldrh	r0, [r7, #10]
    lsls	r0, r0, #17
    lsrs	r2, r0, #24
    cmp	r2, #2
    bne .Leu_0803BC94
    ldrh	r0, [r3, #0]
    movs	r1, #32
    orrs	r0, r1
    strh	r0, [r3, #0]
    ldr r0, .Leu_0803BCB8
    orrs	r4, r0
    mov	r5, r9
    str	r4, [r5, #80]	@ 0x50
.Leu_0803BC94:
    cmp	r2, #1
    bne .Leu_0803BCEC
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    blt .Leu_0803BCEC
    mov	r1, sl
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
    b .Leu_0803BCEC
    .align 2, 0
.Leu_0803BCB8:
    .4byte 0x08083F40
.Leu_0803BCBC:
    ldrb	r0, [r7, #8]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #1
    lsls	r1, r0
    mov	r2, r9
    ldrh	r0, [r2, #0]
    bics	r0, r1
    strh	r0, [r2, #0]
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Leu_0803BCEC
    mov	r4, sl
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #20]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
.Leu_0803BCEC:
    ldrb	r1, [r7, #11]
    lsrs	r1, r1, #7
    ldrb	r0, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    lsls	r0, r0, #1
    orrs	r0, r1
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    @ Remaining control-widget code after the recovered border constructor.
    .section .text.main_menu_widget_update_impl, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0
    .global UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
    .thumb_func
UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #116	@ 0x74
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r2, [sp, #68]	@ 0x44
    adds	r1, r3, #0
    ldr	r3, [sp, #152]	@ 0x98
    ldr	r5, [sp, #156]	@ 0x9c
    ldr	r2, [sp, #148]	@ 0x94
    bl Update__13ControlWidgetP20HardwareDisplayStateP18HardwareLinkedListT2
    str	r0, [sp, #72]	@ 0x48
    cmp	r0, #0
    bge .Leu_0803C062
    b .Leu_0803C51A
.Leu_0803C062:
    cmp	r0, #2
    bgt .Leu_0803C068
    b .Leu_0803C51A
.Leu_0803C068:
    cmp	r0, #3
    beq .Leu_0803C06E
    b .Leu_0803C51A
.Leu_0803C06E:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    ldrb	r0, [r7, #15]
    cmp	r0, #0
    beq .Leu_0803C0F0
    ldrh	r3, [r4, #8]
    adds	r2, r3, #0
    lsls	r1, r2, #26
    lsrs	r1, r1, #31
    lsls	r0, r2, #27
    lsrs	r0, r0, #31
    orrs	r1, r0
    cmp	r1, #0
    beq .Leu_0803C0DC
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    beq .Leu_0803C0A0
    ldrb	r0, [r7, #12]
    cmp	r0, #0
    bne .Leu_0803C09C
    movs	r0, #6
    b .Leu_0803C0B8
.Leu_0803C09C:
    subs	r0, #1
    b .Leu_0803C0B8
.Leu_0803C0A0:
    movs	r0, #16
    ands	r2, r0
    cmp	r2, #0
    beq .Leu_0803C0BA
    ldrb	r0, [r7, #12]
    cmp	r0, #6
    bne .Leu_0803C0B6
    add	r1, sp, #76	@ 0x4c
    ldrb	r1, [r1, #0]
    strb	r1, [r7, #12]
    b .Leu_0803C0BA
.Leu_0803C0B6:
    adds	r0, #1
.Leu_0803C0B8:
    strb	r0, [r7, #12]
.Leu_0803C0BA:
    cmp	r5, #0
    beq .Leu_0803C0C6
    adds	r0, r5, #0
    movs	r1, #203	@ 0xcb
    bl Start__23HardwareMusicPlayerSlotUs
.Leu_0803C0C6:
    ldr r0, .Leu_0803C0D8
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #20
    strb	r0, [r7, #14]
    b .Leu_0803C0F0
.Leu_0803C0D8:
    .4byte gMenuEntryLabels
.Leu_0803C0DC:
    movs	r0, #1
    ands	r3, r0
    cmp	r3, #0
    beq .Leu_0803C0F0
    cmp	r5, #0
    beq .Leu_0803C0F0
    adds	r0, r5, #0
    movs	r1, #197	@ 0xc5
    bl Start__23HardwareMusicPlayerSlotUs
.Leu_0803C0F0:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    beq .Leu_0803C156
    ldr	r4, [r7, #8]
    ldr	r0, [r4, #80]	@ 0x50
    ldr	r1, [r0, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #44]	@ 0x2c
    lsls	r2, r2, #2
    ldr	r0, [r0, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    ldr	r5, [sp, #20]
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r2, r0, #0
    add	r1, sp, #20
    ldr	r0, [sp, #20]
    movs	r3, #0
    cmp	r0, #0
    beq .Leu_0803C12A
    ldrh	r3, [r1, #4]
.Leu_0803C12A:
    adds	r1, r4, #0
    adds	r1, #56	@ 0x38
    lsls	r0, r2, #5
    ldr r2, .Leu_0803C4E4
    adds	r0, r0, r2
    str	r5, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
    ldr r1, .Leu_0803C4E8
    ldrb	r0, [r7, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r7, #13]
.Leu_0803C156:
    ldrb	r0, [r7, #14]
    subs	r0, #1
    strb	r0, [r7, #14]
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803C166
    movs	r0, #40	@ 0x28
    strb	r0, [r7, #14]
.Leu_0803C166:
    ldrb	r0, [r7, #14]
    cmp	r0, #19
    bhi .Leu_0803C262
    ldr	r0, [r7, #8]
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #4
    adds	r1, #16
    mov	r8, r1
    ldr	r4, [r0, #80]	@ 0x50
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r9, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Leu_0803C1E2
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Leu_0803C1C6
    ldrh	r3, [r1, #4]
.Leu_0803C1C6:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r5, .Leu_0803C4EC
    adds	r0, r0, r5
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r2, [sp, #148]	@ 0x94
    ldr	r0, [r2, #8]
    ldr	r2, [r0, #16]
    ldr	r0, [sp, #148]	@ 0x94
    bl _call_via_r2
.Leu_0803C1E2:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    add	r0, r8
    ldr r1, .Leu_0803C4F0
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Leu_0803C4F4
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #36]	@ 0x24
    add	r4, sp, #36	@ 0x24
    ldrb	r0, [r4, #0]
    adds	r0, #150	@ 0x96
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr r1, .Leu_0803C4F8
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    mov	r3, r9
    lsls	r1, r3, #16
    lsrs	r1, r1, #16
    movs	r0, #15
    ands	r1, r0
    lsls	r1, r1, #12
    ldr r2, .Leu_0803C4FC
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Leu_0803C500
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #5
    ldr	r1, [sp, #36]	@ 0x24
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r2, [r5, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Leu_0803C262
    lsls	r0, r2, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r5, #0]
.Leu_0803C262:
    ldr	r0, [r7, #8]
    mov	sl, r0
    movs	r1, #0
    mov	r9, r1
    mov	r2, sp
    adds	r2, #44	@ 0x2c
    str	r2, [sp, #96]	@ 0x60
    ldr	r3, [sp, #76]	@ 0x4c
    negs	r3, r3
    str	r3, [sp, #104]	@ 0x68
    mov	r4, sp
    adds	r4, #60	@ 0x3c
    str	r4, [sp, #100]	@ 0x64
    movs	r5, #16
    str	r5, [sp, #108]	@ 0x6c
.Leu_0803C280:
    mov	r1, r9
    lsls	r0, r1, #2
    add	r0, sl
    ldr	r4, [r0, #84]	@ 0x54
    mov	r0, sl
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r8, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Leu_0803C2F4
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Leu_0803C2D8
    ldrh	r3, [r1, #4]
.Leu_0803C2D8:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r2, .Leu_0803C4EC
    adds	r0, r0, r2
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
.Leu_0803C2F4:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r0, r0, r4
    ldr r1, .Leu_0803C4F0
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Leu_0803C4F4
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #96]	@ 0x60
    ldrb	r1, [r5, #0]
    adds	r1, #150	@ 0x96
    lsls	r1, r1, #24
    lsrs	r1, r1, #24
    ldr r0, .Leu_0803C4F8
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #44]	@ 0x2c
    mov	r0, r8
    lsls	r1, r0, #16
    lsrs	r1, r1, #16
    movs	r2, #15
    ands	r1, r2
    lsls	r1, r1, #12
    add	r4, sp, #44	@ 0x2c
    ldr	r0, [r4, #4]
    ldr r3, .Leu_0803C4FC
    ands	r0, r3
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Leu_0803C500
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r5, #128	@ 0x80
    lsls	r5, r5, #5
    orrs	r1, r5
    str	r1, [sp, #44]	@ 0x2c
    ldr	r0, [sp, #68]	@ 0x44
    ldrb	r2, [r0, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Leu_0803C37A
    lsls	r0, r2, #3
    adds	r0, #4
    ldr	r3, [sp, #68]	@ 0x44
    adds	r0, r3, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r3, #0]
.Leu_0803C37A:
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r4, #16
    str	r4, [sp, #108]	@ 0x6c
    movs	r5, #1
    add	r9, r5
    mov	r0, r9
    cmp	r0, #6
    bhi .Leu_0803C38C
    b .Leu_0803C280
.Leu_0803C38C:
    ldr	r7, [r7, #8]
    mov	r8, r7
    ldr	r1, [sp, #76]	@ 0x4c
    cmp	r1, #0
    beq .Leu_0803C3C4
    add	r0, sp, #52	@ 0x34
    movs	r4, #12
    movs	r5, #2
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    mov	r6, r8
    adds	r6, #116	@ 0x74
    adds	r1, r6, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    add	r0, sp, #56	@ 0x38
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #56]	@ 0x38
    ldr	r2, [sp, #76]	@ 0x4c
    str	r2, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Leu_0803C3C4:
    mov	r0, r8
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    ldr	r3, [sp, #104]	@ 0x68
    ldr	r4, [sp, #76]	@ 0x4c
    orrs	r3, r4
    mov	r5, r8
    adds	r5, #112	@ 0x70
    str	r5, [sp, #80]	@ 0x50
    lsrs	r1, r3, #31
    str	r1, [sp, #84]	@ 0x54
    movs	r1, #0
    movs	r2, #0
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    ldr r2, .Leu_0803C504
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #24
    orrs	r1, r2
    ldr r2, .Leu_0803C508
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #7
    orrs	r1, r2
    str	r1, [sp, #60]	@ 0x3c
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    movs	r2, #15
    ands	r0, r2
    lsls	r0, r0, #12
    ldr	r3, [sp, #100]	@ 0x64
    ldr	r1, [r3, #4]
    ldr r4, .Leu_0803C4FC
    ands	r1, r4
    orrs	r1, r0
    str	r1, [r3, #4]
    ldr	r0, [sp, #60]	@ 0x3c
    ldr r5, .Leu_0803C4F8
    ands	r0, r5
    movs	r1, #142	@ 0x8e
    orrs	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #5
    orrs	r0, r1
    str	r0, [sp, #60]	@ 0x3c
    movs	r4, #0
    mov	r2, r8
    adds	r2, #116	@ 0x74
    str	r2, [sp, #88]	@ 0x58
.Leu_0803C42E:
    lsls	r0, r4, #3
    ldr	r3, [sp, #80]	@ 0x50
    adds	r0, r0, r3
    movs	r5, #193	@ 0xc1
    lsls	r5, r5, #2
    adds	r0, r0, r5
    ldr	r1, [r0, #4]
    bl GetObjTileIndex
    mov	r8, r0
    lsls	r0, r4, #5
    mov	sl, r0
    adds	r1, r4, #1
    str	r1, [sp, #92]	@ 0x5c
    ldr	r2, [sp, #84]	@ 0x54
    cmp	r2, #0
    beq .Leu_0803C4AC
    movs	r3, #0
    lsls	r2, r4, #1
    lsls	r1, r4, #2
    movs	r4, #128	@ 0x80
    mov	r9, r4
    adds	r1, r1, r2
    lsls	r1, r1, #3
    ldr	r5, [sp, #80]	@ 0x50
    movs	r4, #202	@ 0xca
    lsls	r4, r4, #2
    adds	r0, r5, r4
    adds	r4, r1, r0
    mov	r5, r8
    lsls	r0, r5, #5
    ldr r5, .Leu_0803C4EC
    adds	r7, r0, r5
    lsls	r2, r2, #6
    ldr	r0, [sp, #88]	@ 0x58
    adds	r6, r2, r0
    ldr	r2, [sp, #80]	@ 0x50
    movs	r5, #199	@ 0xc7
    lsls	r5, r5, #2
    adds	r0, r2, r5
    adds	r5, r1, r0
.Leu_0803C480:
    str	r6, [r4, #0]
    str	r7, [r4, #4]
    mov	r0, r9
    str	r0, [r4, #8]
    ldr	r1, [sp, #148]	@ 0x94
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    adds	r0, r1, #0
    adds	r1, r5, #0
    str	r3, [sp, #112]	@ 0x70
    bl _call_via_r2
    adds	r4, #24
    adds	r7, #128	@ 0x80
    movs	r2, #192	@ 0xc0
    lsls	r2, r2, #1
    adds	r6, r6, r2
    adds	r5, #24
    ldr	r3, [sp, #112]	@ 0x70
    adds	r3, #1
    cmp	r3, #1
    bls .Leu_0803C480
.Leu_0803C4AC:
    mov	r3, r8
    lsls	r1, r3, #22
    lsrs	r1, r1, #22
    ldr r2, .Leu_0803C500
    ldr	r4, [sp, #100]	@ 0x64
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    mov	r1, sl
    adds	r1, #136	@ 0x88
    ldr r0, .Leu_0803C4F0
    ands	r1, r0
    lsls	r1, r1, #16
    ldr r0, .Leu_0803C4F4
    ldr	r2, [sp, #60]	@ 0x3c
    ands	r2, r0
    orrs	r2, r1
    str	r2, [sp, #60]	@ 0x3c
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r3, [r5, #0]
    cmp	r3, #127	@ 0x7f
    bhi .Leu_0803C514
    lsls	r0, r3, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r2, [r0, #0]
    b .Leu_0803C50C
.Leu_0803C4E4:
    .word OBJ_PALETTE
.Leu_0803C4E8:
    .4byte gMenuEntryLabels
.Leu_0803C4EC:
    .word OBJ_VRAM0
.Leu_0803C4F0:
    .4byte 0x000001FF
.Leu_0803C4F4:
    .4byte 0xFE00FFFF
.Leu_0803C4F8:
    .4byte 0xFFFFFF00
.Leu_0803C4FC:
    .4byte 0xFFFF0FFF
.Leu_0803C500:
    .4byte 0xFFFFFC00
.Leu_0803C504:
    .4byte 0x3FFFFFFF
.Leu_0803C508:
    .4byte 0xFFFF3FFF
.Leu_0803C50C:
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r3, #1
    strb	r0, [r5, #0]
.Leu_0803C514:
    ldr	r4, [sp, #92]	@ 0x5c
    cmp	r4, #2
    bls .Leu_0803C42E
.Leu_0803C51A:
    ldr	r0, [sp, #72]	@ 0x48
    add	sp, #116	@ 0x74
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .section .text.map_clock_status_calendar, "ax", %progbits
    .align 2, 0
    .global UpdateMapClockStatusHudCalendar
    .thumb_func
UpdateMapClockStatusHudCalendar:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #48	@ 0x30
    str	r1, [sp, #32]
    lsls	r2, r2, #24
    lsrs	r2, r2, #24
    str	r2, [sp, #36]	@ 0x24
    ldr	r7, [r0, #0]
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    beq .Leu_0803CD92
    cmp	r0, #1
    ble .Leu_0803CD8C
    cmp	r0, #2
    beq .Leu_0803CD98
    cmp	r0, #3
    beq .Leu_0803CD9E
.Leu_0803CD8C:
    movs	r5, #11
    movs	r6, #12
    b .Leu_0803CDA2
.Leu_0803CD92:
    movs	r5, #13
    movs	r6, #14
    b .Leu_0803CDA2
.Leu_0803CD98:
    movs	r5, #15
    movs	r6, #16
    b .Leu_0803CDA2
.Leu_0803CD9E:
    movs	r5, #17
    movs	r6, #18
.Leu_0803CDA2:
    adds	r0, r7, #0
    adds	r0, #132	@ 0x84
    lsls	r1, r5, #5
    ldr r2, .Leu_0803CE44
    mov	sl, r2
    add	r1, sl
    movs	r2, #32
    bl memcpy
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #1
    adds	r4, r7, r0
    movs	r1, #1
    mov	r8, r1
    mov	r2, r8
    strb	r2, [r4, #0]
    lsls	r1, r6, #5
    add	r1, sl
    adds	r0, r7, #0
    adds	r0, #164	@ 0xa4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    ldr	r1, [sp, #32]
    ldrb	r3, [r1, #1]
    lsls	r0, r3, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    adds	r5, r0, #0
    ldrb	r2, [r1, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    lsls	r3, r3, #30
    lsrs	r3, r3, #30
    adds	r2, #6
    lsls	r1, r3, #4
    subs	r1, r1, r3
    lsls	r1, r1, #1
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r1, r5
    subs	r1, #1
    mov	r9, r4
    cmp	r1, #6
    bls .Leu_0803CE0E
    adds	r0, r1, #0
    movs	r1, #7
    bl __umodsi3
    adds	r1, r0, #0
.Leu_0803CE0E:
    movs	r0, #7
    adds	r6, r0, #0
    ands	r6, r1
    adds	r0, r5, #0
    movs	r1, #10
    bl __udivsi3
    adds	r4, r0, #0
    adds	r0, r5, #0
    movs	r1, #10
    bl __umodsi3
    adds	r5, r0, #0
    cmp	r4, #0
    ble .Leu_0803CE48
    lsls	r1, r4, #5
    add	r1, sl
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    mov	r2, r9
    strb	r0, [r2, #0]
    b .Leu_0803CE64
    .align 2, 0
.Leu_0803CE44:
    .4byte gMapClockStatusGlyphTiles
.Leu_0803CE48:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    mov	r1, r9
    strb	r2, [r1, #0]
.Leu_0803CE64:
    lsls	r1, r5, #5
    ldr r0, .Leu_0803CE88
    adds	r1, r1, r0
    adds	r0, r7, #0
    adds	r0, #228	@ 0xe4
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r1, r9
    strb	r0, [r1, #0]
    cmp	r6, #6
    bhi .Leu_0803CEAC
    lsls	r0, r6, #2
    ldr r1, .Leu_0803CE8C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_0803CE88:
    .4byte gMapClockStatusGlyphTiles
.Leu_0803CE8C:
    .4byte .Leu_0803CE90
.Leu_0803CE90:
    .4byte .Leu_0803CEAC
    .4byte .Leu_0803CEB8
    .4byte .Leu_0803CEC4
    .4byte .Leu_0803CED0
    .4byte .Leu_0803CEDC
    .4byte .Leu_0803CEE8
    .4byte .Leu_0803CEF4
.Leu_0803CEAC:
    movs	r0, #96	@ 0x60
    str	r0, [sp, #0]
    movs	r0, #97	@ 0x61
    str	r0, [sp, #4]
    movs	r0, #98	@ 0x62
    b .Leu_0803CEFE
.Leu_0803CEB8:
    .4byte 0x90002063
    .4byte 0x90012064
    .4byte 0xE01C2065
.Leu_0803CEC4:
    .4byte 0x90002066
    .4byte 0x90012067
    .4byte 0xE0162068
.Leu_0803CED0:
    .4byte 0x90002069
    .4byte 0x9001206A
    .4byte 0xE010206B
.Leu_0803CEDC:
    .4byte 0x9000206C
    .4byte 0x9001206D
    .4byte 0xE00A206E
.Leu_0803CEE8:
    .4byte 0x9000206F
    .4byte 0x90012070
    .4byte 0xE0042071
.Leu_0803CEF4:
    .4byte 0x90002072
    .4byte 0x90012073
    .hword 0x2074
.Leu_0803CEFE:
    str	r0, [sp, #8]
    movs	r2, #212	@ 0xd4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    ldr	r1, [sp, #0]
    lsls	r1, r1, #5
    ldr r2, .Leu_0803CFA4
    mov	r8, r2
    add	r1, r8
    movs	r2, #32
    bl memcpy
    movs	r0, #172	@ 0xac
    lsls	r0, r0, #2
    adds	r4, r7, r0
    movs	r6, #1
    strb	r6, [r4, #0]
    ldr	r1, [sp, #4]
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #228	@ 0xe4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    strb	r6, [r4, #0]
    ldr	r1, [sp, #8]
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #244	@ 0xf4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    strb	r6, [r4, #0]
    ldr	r1, [sp, #32]
    ldr	r0, [r1, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    adds	r5, r0, #0
    movs	r1, #30
    str	r4, [sp, #44]	@ 0x2c
    cmp	r5, #11
    bhi .Leu_0803CF5C
    movs	r1, #28
.Leu_0803CF5C:
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #130	@ 0x82
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, r9
    strb	r6, [r0, #0]
    movs	r4, #12
    cmp	r5, #12
    beq .Leu_0803CF7E
    adds	r4, r5, #0
    cmp	r4, #11
    bls .Leu_0803CF7E
    subs	r4, #12
.Leu_0803CF7E:
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    cmp	r5, #0
    ble .Leu_0803CFA8
    lsls	r1, r5, #5
    ldr r0, .Leu_0803CFA4
    adds	r1, r1, r0
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    b .Leu_0803CFBA
.Leu_0803CFA4:
    .4byte gMapClockStatusGlyphTiles
.Leu_0803CFA8:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    mov	r1, sp
.Leu_0803CFBA:
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r1, r9
    strb	r0, [r1, #0]
    lsls	r1, r4, #5
    ldr r2, .Leu_0803D064
    mov	sl, r2
    add	r1, sl
    movs	r2, #178	@ 0xb2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r8, r0
    mov	r2, r8
    mov	r1, r9
    strb	r2, [r1, #0]
    ldr	r1, [sp, #32]
    ldr	r0, [r1, #0]
    lsls	r0, r0, #5
    lsrs	r0, r0, #26
    movs	r1, #10
    bl __udivsi3
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    lsls	r4, r0, #2
    adds	r4, r4, r0
    lsls	r4, r4, #1
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    lsls	r5, r5, #5
    add	r5, sl
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r6, r7, r2
    movs	r1, #146	@ 0x92
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r5, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    lsls	r4, r4, #5
    add	r4, sl
    movs	r1, #154	@ 0x9a
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r4, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    ldr	r1, [sp, #36]	@ 0x24
    cmp	r1, #0
    beq .Leu_0803D068
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #1
    add	r1, sl
    adds	r0, r6, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    b .Leu_0803D082
    .align 2, 0
.Leu_0803D064:
    .4byte gMapClockStatusGlyphTiles
.Leu_0803D068:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r6, #0
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    ldr	r1, [sp, #44]	@ 0x2c
    strb	r2, [r1, #0]
.Leu_0803D082:
    add	sp, #48	@ 0x30
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.farming_calendar_helpers, "ax", %progbits
    .align 2, 0
    .global DecodeGameDayDate
    .thumb_func
DecodeGameDayDate:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r5, r1, #0
    ldrb	r3, [r5, #1]
    add	r4, sp, #8
    strb	r3, [r4, #0]
    ldrb	r2, [r5, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
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
    mov	r8, r4
    cmp	r3, #6
    bls .Leu_0803D586
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Leu_0803D586:
    movs	r1, #8
    negs	r1, r1
    movs	r0, #7
    ands	r0, r3
    ands	r1, r6
    adds	r6, r1, #0
    orrs	r6, r0
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #0]
    ldrb	r0, [r5, #0]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #4]
    add	r0, sp, #4
    mov	r2, sp
    cmp	r3, r1
    bls .Leu_0803D5B2
    adds	r2, r0, #0
.Leu_0803D5B2:
    ldr	r4, [r2, #0]
    ldr	r0, [r5, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    cmp	r0, #5
    bhi .Leu_0803D626
    mov	r5, r8
    ldrb	r3, [r5, #0]
    lsls	r0, r3, #25
    lsrs	r2, r0, #27
    cmp	r2, #0
    bne .Leu_0803D5E2
    lsls	r0, r3, #30
    lsrs	r0, r0, #30
    movs	r1, #4
    negs	r1, r1
    subs	r0, #1
    movs	r2, #3
    ands	r0, r2
    ands	r1, r3
    orrs	r1, r0
    strb	r1, [r5, #0]
    movs	r2, #29
    b .Leu_0803D5E4
.Leu_0803D5E2:
    subs	r2, #1
.Leu_0803D5E4:
    movs	r0, #31
    ands	r2, r0
    lsls	r2, r2, #2
    ldrb	r1, [r5, #0]
    movs	r0, #125	@ 0x7d
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r5, #0]
    mov	r0, r8
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #3
    bne .Leu_0803D60C
    lsls	r0, r1, #25
    lsrs	r0, r0, #27
    cmp	r0, #29
    bne .Leu_0803D60C
    subs	r4, #1
.Leu_0803D60C:
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    movs	r1, #6
    cmp	r0, #1
    ble .Leu_0803D618
    subs	r1, r0, #1
.Leu_0803D618:
    movs	r0, #7
    ands	r1, r0
    movs	r0, #8
    negs	r0, r0
    ands	r0, r6
    adds	r6, r0, #0
    orrs	r6, r1
.Leu_0803D626:
    strb	r4, [r7, #0]
    mov	r1, r8
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    strb	r0, [r7, #1]
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    strb	r0, [r7, #2]
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    strb	r0, [r7, #3]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803D644
    .thumb_func
func_0803D644:
    push	{r4, lr}
    sub	sp, #8
    lsls	r2, r0, #4
    subs	r2, r2, r0
    lsls	r2, r2, #1
    subs	r2, #1
    adds	r2, r2, r1
    str	r2, [sp, #4]
    ldr r0, .Leu_0803D698
    adds	r4, r0, #0
    adds	r4, #14
    movs	r1, #0
    str	r1, [sp, #0]
    adds	r1, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080E0E80
    adds	r1, r0, #0
    movs	r2, #0
    cmp	r1, r4
    beq .Leu_0803D68E
    ldr	r0, [sp, #4]
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bcc .Leu_0803D68E
    movs	r2, #1
.Leu_0803D68E:
    adds	r0, r2, #0
    add	sp, #8
    pop	{r4}
    pop	{r1}
    bx	r1
.Leu_0803D698:
    .4byte gUnk_080F1A66
    .section .text.npc_schedule_after
    .global func_0803DA24
    .thumb_func
func_0803DA24:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803DA50
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Leu_0803DA54
    movs	r0, #0
    b .Leu_0803DA88
.Leu_0803DA50:
    .4byte 0x000021CA
.Leu_0803DA54:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DA74
    movs	r0, #4
    b .Leu_0803DA88
.Leu_0803DA74:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803DA86
    cmp	r4, #2
    bne .Leu_0803DA82
    movs	r0, #3
    b .Leu_0803DA88
.Leu_0803DA82:
    movs	r0, #1
    b .Leu_0803DA88
.Leu_0803DA86:
    movs	r0, #2
.Leu_0803DA88:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DA7C
    .thumb_func
func_0803DA7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803DADC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Leu_0803DAAA
    b .Leu_0803DC36
.Leu_0803DAAA:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Leu_0803DAE0
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    cmp	r4, #3
    bne .Leu_0803DB7E
    cmp	r7, #2
    bne .Leu_0803DAE4
    mov	r0, r8
    cmp	r0, #13
    bne .Leu_0803DAE4
    movs	r0, #22
    b .Leu_0803DC68
.Leu_0803DADC:
    .4byte 0x000021CA
.Leu_0803DAE0:
    .4byte 0x00001CD4
.Leu_0803DAE4:
    ldr r1, .Leu_0803DAF8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803DAFC
    movs	r0, #23
    b .Leu_0803DC68
    .align 2, 0
.Leu_0803DAF8:
    .4byte 0x0000216B
.Leu_0803DAFC:
    ldr r1, .Leu_0803DB34
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Leu_0803DB38
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803DB28
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803DB28
    cmp	r0, #4
    bne .Leu_0803DB4C
.Leu_0803DB28:
    cmp	r4, #0
    beq .Leu_0803DB40
    cmp	r6, #0
    beq .Leu_0803DB3C
    movs	r0, #13
    b .Leu_0803DC68
.Leu_0803DB34:
    .4byte 0x00002148
.Leu_0803DB38:
    .4byte 0x00001CD4
.Leu_0803DB3C:
    movs	r0, #12
    b .Leu_0803DC68
.Leu_0803DB40:
    cmp	r6, #0
    beq .Leu_0803DB48
    movs	r0, #15
    b .Leu_0803DC68
.Leu_0803DB48:
    movs	r0, #14
    b .Leu_0803DC68
.Leu_0803DB4C:
    cmp	r6, #0
    beq .Leu_0803DB62
    mov	r0, r9
    cmp	r0, #0
    bne .Leu_0803DB62
    cmp	r4, #0
    beq .Leu_0803DB5E
    movs	r0, #8
    b .Leu_0803DC68
.Leu_0803DB5E:
    movs	r0, #11
    b .Leu_0803DC68
.Leu_0803DB62:
    cmp	r4, #0
    beq .Leu_0803DB72
    cmp	r6, #0
    beq .Leu_0803DB6E
    movs	r0, #7
    b .Leu_0803DC68
.Leu_0803DB6E:
    movs	r0, #6
    b .Leu_0803DC68
.Leu_0803DB72:
    cmp	r6, #0
    beq .Leu_0803DB7A
    movs	r0, #10
    b .Leu_0803DC68
.Leu_0803DB7A:
    movs	r0, #9
    b .Leu_0803DC68
.Leu_0803DB7E:
    ldr r1, .Leu_0803DBA0
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Leu_0803DBB2
    cmp	r7, #1
    bne .Leu_0803DC36
    movs	r0, #1
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DBA4
    movs	r0, #19
    b .Leu_0803DC68
.Leu_0803DBA0:
    .4byte 0x00001D6C
.Leu_0803DBA4:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803DBAE
    movs	r0, #20
    b .Leu_0803DC68
.Leu_0803DBAE:
    movs	r0, #21
    b .Leu_0803DC68
.Leu_0803DBB2:
    cmp	r7, #2
    bne .Leu_0803DBD4
    mov	r0, r8
    cmp	r0, #30
    bne .Leu_0803DBD4
    ldr r1, .Leu_0803DBD0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803DBD4
    movs	r0, #17
    b .Leu_0803DC68
    .align 2, 0
.Leu_0803DBD0:
    .4byte 0x000021A3
.Leu_0803DBD4:
    ldr r1, .Leu_0803DC0C
    adds	r0, r5, r1
    movs	r1, #3
    bl func_080A01F8
    cmp	r7, #3
    bne .Leu_0803DC18
    mov	r1, r8
    cmp	r1, #14
    bne .Leu_0803DC18
    cmp	r4, #0
    bne .Leu_0803DC18
    cmp	r0, #0
    beq .Leu_0803DC18
    bl GetLove__C12Bachelorette
    ldr r1, .Leu_0803DC10
    cmp	r0, r1
    bls .Leu_0803DC18
    ldr r1, .Leu_0803DC14
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803DC18
    movs	r0, #18
    b .Leu_0803DC68
.Leu_0803DC0C:
    .4byte 0x00001CD4
.Leu_0803DC10:
    .4byte 0x0000270F
.Leu_0803DC14:
    .4byte 0x000021A3
.Leu_0803DC18:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DC2A
    movs	r0, #16
    b .Leu_0803DC68
.Leu_0803DC2A:
    ldr r1, .Leu_0803DC3C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Leu_0803DC40
.Leu_0803DC36:
    movs	r0, #0
    b .Leu_0803DC68
    .align 2, 0
.Leu_0803DC3C:
    .4byte 0x0000215A
.Leu_0803DC40:
    mov	r0, r9
    cmp	r0, #0
    bne .Leu_0803DC5C
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803DC58
    cmp	r7, #1
    bne .Leu_0803DC54
    movs	r0, #5
    b .Leu_0803DC68
.Leu_0803DC54:
    movs	r0, #3
    b .Leu_0803DC68
.Leu_0803DC58:
    movs	r0, #4
    b .Leu_0803DC68
.Leu_0803DC5C:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803DC66
    movs	r0, #2
    b .Leu_0803DC68
.Leu_0803DC66:
    movs	r0, #1
.Leu_0803DC68:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DC64
    .thumb_func
func_0803DC64:
    push	{r4, lr}
    sub	sp, #4
    adds	r2, r0, #0
    ldr r1, .Leu_0803DC90
    adds	r0, r2, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Leu_0803DC94
    movs	r0, #0
    b .Leu_0803DCBE
.Leu_0803DC90:
    .4byte 0x000021CA
.Leu_0803DC94:
    mov	r4, sp
    adds	r1, r2, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DCB4
    movs	r0, #3
    b .Leu_0803DCBE
.Leu_0803DCB4:
    cmp	r4, #0
    beq .Leu_0803DCBC
    movs	r0, #1
    b .Leu_0803DCBE
.Leu_0803DCBC:
    movs	r0, #2
.Leu_0803DCBE:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DCB4
    .thumb_func
func_0803DCB4:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r0, .Leu_0803DCF8
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetChild__C13NpcCollection
    cmp	r0, #0
    bne .Leu_0803DCDE
    b .Leu_0803DDF2
.Leu_0803DCDE:
    bl GetAgeDays__C5Child
    cmp	r0, #59	@ 0x3b
    bls .Leu_0803DCE8
    b .Leu_0803DDEE
.Leu_0803DCE8:
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #31
    bne .Leu_0803DCFC
    movs	r0, #3
    b .Leu_0803DDF4
.Leu_0803DCF8:
    .4byte 0x00001CD4
.Leu_0803DCFC:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Leu_0803DD1A
    cmp	r1, #13
    bne .Leu_0803DD1A
    movs	r0, #5
    b .Leu_0803DDF4
.Leu_0803DD1A:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803DDC4
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803DDC4
    cmp	r0, #4
    beq .Leu_0803DDC4
    ldr r1, .Leu_0803DD44
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    subs	r0, r6, #3
    cmp	r0, #28
    bhi .Leu_0803DDEA
    lsls	r0, r0, #2
    ldr r1, .Leu_0803DD48
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_0803DD44:
    .4byte 0x00002148
.Leu_0803DD48:
    .4byte .Leu_0803DD4C
.Leu_0803DD4C:
    .4byte .Leu_0803DDC8
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDC0
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDD2
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDE0
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDE6
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
    .4byte .Leu_0803DDEA
.Leu_0803DDC0:
    .4byte 0xD1122C01
.Leu_0803DDC4:
    movs	r0, #2
    b .Leu_0803DDF4
.Leu_0803DDC8:
    .4byte 0xD0FB2A00
    .4byte 0xD10C2C00
    .hword 0xE7F8
.Leu_0803DDD2:
    .hword 0x2A00
    .4byte 0x2C02D0F6
    .4byte 0x2C00D0F4
    .4byte 0xE7F1D105
.Leu_0803DDE0:
    .4byte 0xD1022C03
    .hword 0xE7EE
.Leu_0803DDE6:
    .hword 0x2A00
    .hword 0xD0EC
.Leu_0803DDEA:
    movs	r0, #1
    b .Leu_0803DDF4
.Leu_0803DDEE:
    movs	r0, #4
    b .Leu_0803DDF4
.Leu_0803DDF2:
    movs	r0, #0
.Leu_0803DDF4:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803DDE8
    .thumb_func
func_0803DDE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803DE5C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    blt .Leu_0803DE56
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    mov	r0, sp
    ldrb	r6, [r0, #0]
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Leu_0803DE60
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803DE56
    subs	r1, #12
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Leu_0803DE64
    cmp	r6, #1
    bhi .Leu_0803DE56
    cmp	r6, #1
    bne .Leu_0803DE64
    cmp	r7, #3
    bne .Leu_0803DE64
    mov	r0, r8
    cmp	r0, #28
    bls .Leu_0803DE64
.Leu_0803DE56:
    movs	r0, #0
    b .Leu_0803DED2
    .align 2, 0
.Leu_0803DE5C:
    .4byte 0x000021CA
.Leu_0803DE60:
    .4byte 0x00002181
.Leu_0803DE64:
    ldr r1, .Leu_0803DE78
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803DE7C
    movs	r0, #5
    b .Leu_0803DED2
    .align 2, 0
.Leu_0803DE78:
    .4byte 0x00002181
.Leu_0803DE7C:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DE8E
    movs	r0, #4
    b .Leu_0803DED2
.Leu_0803DE8E:
    cmp	r6, #1
    bne .Leu_0803DEB0
    cmp	r7, #2
    bne .Leu_0803DEB0
    mov	r0, r8
    cmp	r0, #15
    bne .Leu_0803DEB0
    ldr r1, .Leu_0803DEAC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803DEB0
.Leu_0803DEA8:
    movs	r0, #2
    b .Leu_0803DED2
.Leu_0803DEAC:
    .4byte 0x00002175
.Leu_0803DEB0:
    ldr r1, .Leu_0803DECC
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Leu_0803DED0
    cmp	r4, #6
    bne .Leu_0803DEA8
    movs	r0, #3
    b .Leu_0803DED2
.Leu_0803DECC:
    .4byte 0x00002174
.Leu_0803DED0:
    movs	r0, #1
.Leu_0803DED2:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DECC
    .thumb_func
func_0803DECC:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803DF02
    movs	r0, #1
    b .Leu_0803DF04
.Leu_0803DF02:
    movs	r0, #2
.Leu_0803DF04:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DEF8
    .thumb_func
func_0803DEF8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803DF24
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Leu_0803DF28
    movs	r0, #0
    b .Leu_0803DF5C
    .align 2, 0
.Leu_0803DF24:
    .4byte 0x000021CA
.Leu_0803DF28:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DF48
    movs	r0, #4
    b .Leu_0803DF5C
.Leu_0803DF48:
    cmp	r4, #3
    bne .Leu_0803DF5A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803DF56
    movs	r0, #2
    b .Leu_0803DF5C
.Leu_0803DF56:
    movs	r0, #3
    b .Leu_0803DF5C
.Leu_0803DF5A:
    movs	r0, #1
.Leu_0803DF5C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DF50
    .thumb_func
func_0803DF50:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Leu_0803DF7C
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Leu_0803DF80
    movs	r0, #0
    b .Leu_0803DF9E
    .align 2, 0
.Leu_0803DF7C:
    .4byte 0x000021CA
.Leu_0803DF80:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803DF9C
    movs	r0, #1
    b .Leu_0803DF9E
.Leu_0803DF9C:
    movs	r0, #2
.Leu_0803DF9E:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DF94
    .thumb_func
func_0803DF94:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Leu_0803DFC0
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Leu_0803DFC4
    movs	r0, #0
    b .Leu_0803DFF4
    .align 2, 0
.Leu_0803DFC0:
    .4byte 0x000021CA
.Leu_0803DFC4:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803DFE2
    movs	r0, #4
    b .Leu_0803DFF4
.Leu_0803DFE2:
    cmp	r4, #2
    bne .Leu_0803DFEA
    movs	r0, #2
    b .Leu_0803DFF4
.Leu_0803DFEA:
    cmp	r4, #0
    beq .Leu_0803DFF2
    movs	r0, #1
    b .Leu_0803DFF4
.Leu_0803DFF2:
    movs	r0, #3
.Leu_0803DFF4:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DFE8
    .thumb_func
func_0803DFE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E01C
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Leu_0803E020
    movs	r0, #0
    b .Leu_0803E1A8
    .align 2, 0
.Leu_0803E01C:
    .4byte 0x000021CA
.Leu_0803E020:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r7, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Leu_0803E054
    adds	r4, r5, r1
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #19
    bne .Leu_0803E0FE
    mov	r0, r8
    cmp	r0, #2
    bne .Leu_0803E060
    cmp	r7, #9
    bne .Leu_0803E058
    movs	r0, #21
    b .Leu_0803E1A8
.Leu_0803E054:
    .4byte 0x00001CD4
.Leu_0803E058:
    cmp	r7, #13
    bne .Leu_0803E060
    movs	r0, #22
    b .Leu_0803E1A8
.Leu_0803E060:
    ldr r1, .Leu_0803E074
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803E078
    movs	r0, #23
    b .Leu_0803E1A8
    .align 2, 0
.Leu_0803E074:
    .4byte 0x0000216C
.Leu_0803E078:
    ldr r1, .Leu_0803E0B0
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Leu_0803E0B4
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803E0A4
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803E0A4
    cmp	r0, #4
    bne .Leu_0803E0C8
.Leu_0803E0A4:
    cmp	r4, #0
    beq .Leu_0803E0BC
    cmp	r6, #0
    beq .Leu_0803E0B8
    movs	r0, #18
    b .Leu_0803E1A8
.Leu_0803E0B0:
    .4byte 0x00002148
.Leu_0803E0B4:
    .4byte 0x00001CD4
.Leu_0803E0B8:
    movs	r0, #17
    b .Leu_0803E1A8
.Leu_0803E0BC:
    cmp	r6, #0
    beq .Leu_0803E0C4
    movs	r0, #20
    b .Leu_0803E1A8
.Leu_0803E0C4:
    movs	r0, #19
    b .Leu_0803E1A8
.Leu_0803E0C8:
    cmp	r6, #0
    beq .Leu_0803E0E2
    mov	r0, r9
    cmp	r0, #0
    beq .Leu_0803E0D6
    cmp	r0, #2
    bne .Leu_0803E0E2
.Leu_0803E0D6:
    cmp	r4, #0
    beq .Leu_0803E0DE
    movs	r0, #13
    b .Leu_0803E1A8
.Leu_0803E0DE:
    movs	r0, #16
    b .Leu_0803E1A8
.Leu_0803E0E2:
    cmp	r4, #0
    beq .Leu_0803E0F2
    cmp	r6, #0
    beq .Leu_0803E0EE
    movs	r0, #12
    b .Leu_0803E1A8
.Leu_0803E0EE:
    movs	r0, #11
    b .Leu_0803E1A8
.Leu_0803E0F2:
    cmp	r6, #0
    beq .Leu_0803E0FA
    movs	r0, #15
    b .Leu_0803E1A8
.Leu_0803E0FA:
    movs	r0, #14
    b .Leu_0803E1A8
.Leu_0803E0FE:
    ldr r1, .Leu_0803E11C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Leu_0803E12E
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E120
    movs	r0, #10
    b .Leu_0803E1A8
.Leu_0803E11C:
    .4byte 0x00001EB8
.Leu_0803E120:
    mov	r0, r9
    cmp	r0, #0
    bne .Leu_0803E12A
    movs	r0, #7
    b .Leu_0803E1A8
.Leu_0803E12A:
    movs	r0, #6
    b .Leu_0803E1A8
.Leu_0803E12E:
    adds	r0, r4, #0
    movs	r1, #19
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Leu_0803E16C
    cmp	r7, #14
    bne .Leu_0803E16C
    cmp	r6, #0
    bne .Leu_0803E16C
    cmp	r0, #0
    beq .Leu_0803E16C
    bl GetLove__C12Bachelorette
    ldr r1, .Leu_0803E164
    cmp	r0, r1
    bls .Leu_0803E16C
    ldr r1, .Leu_0803E168
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803E16C
    movs	r0, #9
    b .Leu_0803E1A8
.Leu_0803E164:
    .4byte 0x0000270F
.Leu_0803E168:
    .4byte 0x000021A4
.Leu_0803E16C:
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E17E
    movs	r0, #8
    b .Leu_0803E1A8
.Leu_0803E17E:
    mov	r0, r9
    cmp	r0, #0
    bne .Leu_0803E188
    movs	r0, #3
    b .Leu_0803E1A8
.Leu_0803E188:
    mov	r1, r9
    cmp	r1, #2
    bne .Leu_0803E19C
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E198
    movs	r0, #4
    b .Leu_0803E1A8
.Leu_0803E198:
    movs	r0, #5
    b .Leu_0803E1A8
.Leu_0803E19C:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803E1A6
    movs	r0, #2
    b .Leu_0803E1A8
.Leu_0803E1A6:
    movs	r0, #1
.Leu_0803E1A8:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E1A4
    .thumb_func
func_0803E1A4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E1D0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Leu_0803E1D4
    movs	r0, #0
    b .Leu_0803E208
    .align 2, 0
.Leu_0803E1D0:
    .4byte 0x000021CA
.Leu_0803E1D4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E1F4
    movs	r0, #4
    b .Leu_0803E208
.Leu_0803E1F4:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E206
    cmp	r4, #2
    bne .Leu_0803E202
    movs	r0, #3
    b .Leu_0803E208
.Leu_0803E202:
    movs	r0, #1
    b .Leu_0803E208
.Leu_0803E206:
    movs	r0, #2
.Leu_0803E208:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E1FC
    .thumb_func
func_0803E1FC:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E228
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Leu_0803E22C
    movs	r0, #0
    b .Leu_0803E26E
    .align 2, 0
.Leu_0803E228:
    .4byte 0x000021CA
.Leu_0803E22C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r4, [r4, #2]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E24E
    movs	r0, #2
    b .Leu_0803E26E
.Leu_0803E24E:
    ldr r1, .Leu_0803E268
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    cmp	r6, #2
    bne .Leu_0803E26C
    cmp	r4, #5
    bne .Leu_0803E26C
    cmp	r0, #25
    beq .Leu_0803E26C
    movs	r0, #3
    b .Leu_0803E26E
    .align 2, 0
.Leu_0803E268:
    .4byte 0x00001CD4
.Leu_0803E26C:
    movs	r0, #1
.Leu_0803E26E:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E264
    .thumb_func
func_0803E264:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E294
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Leu_0803E298
    movs	r0, #0
    b .Leu_0803E412
.Leu_0803E294:
    .4byte 0x000021CA
.Leu_0803E298:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r6, [r4, #2]
    ldr r1, .Leu_0803E2C8
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    mov	r0, r8
    cmp	r0, #2
    bne .Leu_0803E2CC
    cmp	r6, #5
    bne .Leu_0803E2CC
    cmp	r4, #25
    beq .Leu_0803E2D0
    movs	r0, #5
    b .Leu_0803E412
    .align 2, 0
.Leu_0803E2C8:
    .4byte 0x00001CD4
.Leu_0803E2CC:
    cmp	r4, #25
    bne .Leu_0803E378
.Leu_0803E2D0:
    mov	r1, r8
    cmp	r1, #2
    bne .Leu_0803E2E6
    cmp	r6, #9
    bne .Leu_0803E2DE
    movs	r0, #16
    b .Leu_0803E412
.Leu_0803E2DE:
    cmp	r6, #13
    bne .Leu_0803E2E6
    movs	r0, #17
    b .Leu_0803E412
.Leu_0803E2E6:
    ldr r1, .Leu_0803E304
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Leu_0803E308
    movs	r0, #18
    b .Leu_0803E412
.Leu_0803E304:
    .4byte 0x0000216B
.Leu_0803E308:
    ldr r1, .Leu_0803E344
    adds	r0, r5, r1
    ldrb	r4, [r0, #0]
    ldr r1, .Leu_0803E348
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r7, r1, #31
    mov	r9, r7
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803E336
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803E336
    cmp	r0, #4
    bne .Leu_0803E35C
.Leu_0803E336:
    mov	r0, r9
    cmp	r0, #0
    beq .Leu_0803E350
    cmp	r4, #0
    beq .Leu_0803E34C
    movs	r0, #13
    b .Leu_0803E412
.Leu_0803E344:
    .4byte 0x00002148
.Leu_0803E348:
    .4byte 0x00001CD4
.Leu_0803E34C:
    movs	r0, #12
    b .Leu_0803E412
.Leu_0803E350:
    cmp	r4, #0
    beq .Leu_0803E358
    movs	r0, #15
    b .Leu_0803E412
.Leu_0803E358:
    movs	r0, #14
    b .Leu_0803E412
.Leu_0803E35C:
    cmp	r7, #0
    beq .Leu_0803E36C
    cmp	r4, #0
    beq .Leu_0803E368
    movs	r0, #9
    b .Leu_0803E412
.Leu_0803E368:
    movs	r0, #8
    b .Leu_0803E412
.Leu_0803E36C:
    cmp	r4, #0
    beq .Leu_0803E374
    movs	r0, #11
    b .Leu_0803E412
.Leu_0803E374:
    movs	r0, #10
    b .Leu_0803E412
.Leu_0803E378:
    ldr r1, .Leu_0803E39C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Leu_0803E3A4
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803E402
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E3A0
    movs	r0, #3
    b .Leu_0803E412
.Leu_0803E39C:
    .4byte 0x00001F38
.Leu_0803E3A0:
    movs	r0, #4
    b .Leu_0803E412
.Leu_0803E3A4:
    ldr r1, .Leu_0803E3E8
    adds	r0, r5, r1
    movs	r1, #25
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Leu_0803E3F4
    cmp	r6, #14
    bne .Leu_0803E3F4
    cmp	r4, #0
    bne .Leu_0803E3F4
    cmp	r0, #0
    beq .Leu_0803E3F4
    bl GetLove__C12Bachelorette
    ldr r1, .Leu_0803E3EC
    cmp	r0, r1
    bls .Leu_0803E3F4
    ldr r1, .Leu_0803E3F0
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #2
    beq .Leu_0803E3F4
    movs	r0, #7
    b .Leu_0803E412
.Leu_0803E3E8:
    .4byte 0x00001CD4
.Leu_0803E3EC:
    .4byte 0x0000270F
.Leu_0803E3F0:
    .4byte 0x000021A3
.Leu_0803E3F4:
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E406
.Leu_0803E402:
    movs	r0, #6
    b .Leu_0803E412
.Leu_0803E406:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803E410
    movs	r0, #2
    b .Leu_0803E412
.Leu_0803E410:
    movs	r0, #1
.Leu_0803E412:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    @ ROM-verified EU Thumb code_0803A8A4/code_0803E448
    .section .text.code_0803E448
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803E448
    .thumb_func
func_0803E448:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E474
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803E478
    movs	r0, #0
    b .Leu_0803E4AC
    .align 2, 0
.Leu_0803E474:
    .4byte 0x000021CA
.Leu_0803E478:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E498
    movs	r0, #4
    b .Leu_0803E4AC
.Leu_0803E498:
    cmp	r4, #1
    bne .Leu_0803E4AA
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E4A6
    movs	r0, #2
    b .Leu_0803E4AC
.Leu_0803E4A6:
    movs	r0, #3
    b .Leu_0803E4AC
.Leu_0803E4AA:
    movs	r0, #1
.Leu_0803E4AC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E4A0
    .thumb_func
func_0803E4A0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E4D0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803E4D4
    movs	r0, #0
    b .Leu_0803E624
.Leu_0803E4D0:
    .4byte 0x000021CA
.Leu_0803E4D4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Leu_0803E504
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #12
    bne .Leu_0803E582
    cmp	r7, #2
    bne .Leu_0803E510
    cmp	r6, #9
    bne .Leu_0803E508
    movs	r0, #16
    b .Leu_0803E624
.Leu_0803E504:
    .4byte 0x00001CD4
.Leu_0803E508:
    cmp	r6, #13
    bne .Leu_0803E510
    movs	r0, #17
    b .Leu_0803E624
.Leu_0803E510:
    ldr r1, .Leu_0803E524
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803E528
    movs	r0, #18
    b .Leu_0803E624
    .align 2, 0
.Leu_0803E524:
    .4byte 0x0000216C
.Leu_0803E528:
    ldr r1, .Leu_0803E55C
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803E550
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803E550
    cmp	r0, #4
    bne .Leu_0803E564
.Leu_0803E550:
    mov	r0, r8
    cmp	r0, #0
    beq .Leu_0803E560
    movs	r0, #14
    b .Leu_0803E624
    .align 2, 0
.Leu_0803E55C:
    .4byte 0x00001CD4
.Leu_0803E560:
    movs	r0, #15
    b .Leu_0803E624
.Leu_0803E564:
    mov	r1, r9
    cmp	r1, #1
    bne .Leu_0803E576
    cmp	r4, #0
    beq .Leu_0803E572
    movs	r0, #11
    b .Leu_0803E624
.Leu_0803E572:
    movs	r0, #13
    b .Leu_0803E624
.Leu_0803E576:
    cmp	r4, #0
    beq .Leu_0803E57E
    movs	r0, #10
    b .Leu_0803E624
.Leu_0803E57E:
    movs	r0, #12
    b .Leu_0803E624
.Leu_0803E582:
    ldr r1, .Leu_0803E5A0
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Leu_0803E5BC
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E5A4
    movs	r0, #9
    b .Leu_0803E624
.Leu_0803E5A0:
    .4byte 0x00001E28
.Leu_0803E5A4:
    mov	r0, r9
    cmp	r0, #4
    bne .Leu_0803E5B8
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E5B4
    movs	r0, #5
    b .Leu_0803E624
.Leu_0803E5B4:
    movs	r0, #6
    b .Leu_0803E624
.Leu_0803E5B8:
    movs	r0, #4
    b .Leu_0803E624
.Leu_0803E5BC:
    adds	r0, r4, #0
    movs	r1, #12
    bl func_080A01F8
    cmp	r7, #3
    bne .Leu_0803E5FC
    cmp	r6, #14
    bne .Leu_0803E5FC
    mov	r1, r8
    cmp	r1, #0
    bne .Leu_0803E5FC
    cmp	r0, #0
    beq .Leu_0803E5FC
    bl GetLove__C12Bachelorette
    ldr r1, .Leu_0803E5F4
    cmp	r0, r1
    bls .Leu_0803E5FC
    ldr r1, .Leu_0803E5F8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803E5FC
    movs	r0, #7
    b .Leu_0803E624
    .align 2, 0
.Leu_0803E5F4:
    .4byte 0x0000270F
.Leu_0803E5F8:
    .4byte 0x000021A5
.Leu_0803E5FC:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E60E
    movs	r0, #8
    b .Leu_0803E624
.Leu_0803E60E:
    mov	r0, r9
    cmp	r0, #1
    bne .Leu_0803E622
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E61E
    movs	r0, #2
    b .Leu_0803E624
.Leu_0803E61E:
    movs	r0, #3
    b .Leu_0803E624
.Leu_0803E622:
    movs	r0, #1
.Leu_0803E624:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E620
    .thumb_func
func_0803E620:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E64C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803E650
    movs	r0, #0
    b .Leu_0803E68E
    .align 2, 0
.Leu_0803E64C:
    .4byte 0x000021CA
.Leu_0803E650:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E670
    movs	r0, #5
    b .Leu_0803E68E
.Leu_0803E670:
    cmp	r4, #1
    bne .Leu_0803E682
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E67E
    movs	r0, #3
    b .Leu_0803E68E
.Leu_0803E67E:
    movs	r0, #4
    b .Leu_0803E68E
.Leu_0803E682:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803E68C
    movs	r0, #2
    b .Leu_0803E68E
.Leu_0803E68C:
    movs	r0, #1
.Leu_0803E68E:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E684
    .thumb_func
func_0803E684:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    adds	r6, r0, #0
    ldrb	r0, [r4, #2]
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E6C4
    movs	r0, #2
    b .Leu_0803E6F6
.Leu_0803E6C4:
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #4]
    ldrb	r0, [r5, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #8]
    add	r2, sp, #8
    add	r0, sp, #4
    cmp	r3, r1
    bls .Leu_0803E6E2
    adds	r0, r2, #0
.Leu_0803E6E2:
    ldr	r0, [r0, #0]
    cmp	r0, #1
    bhi .Leu_0803E6F4
    cmp	r6, #0
    bne .Leu_0803E6F4
    cmp	r4, #2
    bhi .Leu_0803E6F4
    movs	r0, #0
    b .Leu_0803E6F6
.Leu_0803E6F4:
    movs	r0, #1
.Leu_0803E6F6:
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E6EC
    .thumb_func
func_0803E6EC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r3, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #3
    bne .Leu_0803E754
    cmp	r3, #2
    bne .Leu_0803E754
    ldr r1, .Leu_0803E748
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #134	@ 0x86
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #6
    cmp	r0, r1
    bne .Leu_0803E754
    ldr r1, .Leu_0803E74C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803E750
    movs	r0, #7
    b .Leu_0803E78C
    .align 2, 0
.Leu_0803E748:
    .4byte 0x00002178
.Leu_0803E74C:
    .4byte 0x0000217A
.Leu_0803E750:
    movs	r0, #0
    b .Leu_0803E78C
.Leu_0803E754:
    adds	r0, r2, #0
    adds	r1, r3, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E766
    movs	r0, #6
    b .Leu_0803E78C
.Leu_0803E766:
    cmp	r4, #6
    bne .Leu_0803E778
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E774
    movs	r0, #2
    b .Leu_0803E78C
.Leu_0803E774:
    movs	r0, #3
    b .Leu_0803E78C
.Leu_0803E778:
    cmp	r4, #0
    bne .Leu_0803E78A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803E786
    movs	r0, #4
    b .Leu_0803E78C
.Leu_0803E786:
    movs	r0, #5
    b .Leu_0803E78C
.Leu_0803E78A:
    movs	r0, #1
.Leu_0803E78C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E780
    .thumb_func
func_0803E780:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E7B0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Leu_0803E7B4
    movs	r0, #0
    b .Leu_0803E8EE
.Leu_0803E7B0:
    .4byte 0x000021CA
.Leu_0803E7B4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Leu_0803E7E4
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #21
    bne .Leu_0803E862
    cmp	r7, #2
    bne .Leu_0803E7F0
    cmp	r6, #9
    bne .Leu_0803E7E8
    movs	r0, #14
    b .Leu_0803E8EE
.Leu_0803E7E4:
    .4byte 0x00001CD4
.Leu_0803E7E8:
    cmp	r6, #13
    bne .Leu_0803E7F0
    movs	r0, #15
    b .Leu_0803E8EE
.Leu_0803E7F0:
    ldr r1, .Leu_0803E804
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Leu_0803E808
    movs	r0, #16
    b .Leu_0803E8EE
    .align 2, 0
.Leu_0803E804:
    .4byte 0x0000216C
.Leu_0803E808:
    ldr r1, .Leu_0803E83C
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803E830
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Leu_0803E830
    cmp	r0, #4
    bne .Leu_0803E844
.Leu_0803E830:
    mov	r0, r8
    cmp	r0, #0
    beq .Leu_0803E840
    movs	r0, #12
    b .Leu_0803E8EE
    .align 2, 0
.Leu_0803E83C:
    .4byte 0x00001CD4
.Leu_0803E840:
    movs	r0, #13
    b .Leu_0803E8EE
.Leu_0803E844:
    mov	r1, r9
    cmp	r1, #3
    bne .Leu_0803E856
    cmp	r4, #0
    beq .Leu_0803E852
    movs	r0, #9
    b .Leu_0803E8EE
.Leu_0803E852:
    movs	r0, #11
    b .Leu_0803E8EE
.Leu_0803E856:
    cmp	r4, #0
    beq .Leu_0803E85E
    movs	r0, #8
    b .Leu_0803E8EE
.Leu_0803E85E:
    movs	r0, #10
    b .Leu_0803E8EE
.Leu_0803E862:
    ldr r1, .Leu_0803E880
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Leu_0803E892
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E884
    movs	r0, #7
    b .Leu_0803E8EE
.Leu_0803E880:
    .4byte 0x00001EE4
.Leu_0803E884:
    mov	r0, r9
    cmp	r0, #3
    bne .Leu_0803E88E
    movs	r0, #4
    b .Leu_0803E8EE
.Leu_0803E88E:
    movs	r0, #3
    b .Leu_0803E8EE
.Leu_0803E892:
    adds	r0, r4, #0
    movs	r1, #21
    bl func_080A01F8
    cmp	r7, #3
    bne .Leu_0803E8D0
    cmp	r6, #14
    bne .Leu_0803E8D0
    mov	r1, r8
    cmp	r1, #0
    bne .Leu_0803E8D0
    cmp	r0, #0
    beq .Leu_0803E8D0
    bl GetLove__C12Bachelorette
    ldr r1, .Leu_0803E8C8
    cmp	r0, r1
    bls .Leu_0803E8D0
    ldr r1, .Leu_0803E8CC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803E8D0
    movs	r0, #6
    b .Leu_0803E8EE
.Leu_0803E8C8:
    .4byte 0x0000270F
.Leu_0803E8CC:
    .4byte 0x000021A4
.Leu_0803E8D0:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E8E2
    movs	r0, #5
    b .Leu_0803E8EE
.Leu_0803E8E2:
    mov	r0, r9
    cmp	r0, #3
    beq .Leu_0803E8EC
    movs	r0, #1
    b .Leu_0803E8EE
.Leu_0803E8EC:
    movs	r0, #2
.Leu_0803E8EE:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803E8E8
    .thumb_func
func_0803E8E8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803E938
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    blt .Leu_0803E95C
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #2
    bne .Leu_0803E940
    cmp	r1, #30
    bne .Leu_0803E940
    ldr r3, .Leu_0803E93C
    adds	r0, r5, r3
    ldrb	r0, [r0, #0]
    lsrs	r0, r0, #6
    cmp	r0, #2
    beq .Leu_0803E940
    movs	r0, #5
    b .Leu_0803E97C
.Leu_0803E938:
    .4byte 0x000021CA
.Leu_0803E93C:
    .4byte 0x000021A2
.Leu_0803E940:
    adds	r0, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E950
    movs	r0, #4
    b .Leu_0803E97C
.Leu_0803E950:
    ldr r1, .Leu_0803E960
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Leu_0803E964
.Leu_0803E95C:
    movs	r0, #0
    b .Leu_0803E97C
.Leu_0803E960:
    .4byte 0x0000215A
.Leu_0803E964:
    cmp	r4, #1
    beq .Leu_0803E96C
    cmp	r4, #3
    bne .Leu_0803E970
.Leu_0803E96C:
    movs	r0, #3
    b .Leu_0803E97C
.Leu_0803E970:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803E97A
    movs	r0, #2
    b .Leu_0803E97C
.Leu_0803E97A:
    movs	r0, #1
.Leu_0803E97C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E970
    .thumb_func
func_0803E970:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    adds	r6, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803E9AC
    movs	r0, #5
    b .Leu_0803E9EE
.Leu_0803E9AC:
    ldr r1, .Leu_0803E9BC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Leu_0803E9C0
    movs	r0, #0
    b .Leu_0803E9EE
.Leu_0803E9BC:
    .4byte 0x000021CA
.Leu_0803E9C0:
    ldr r1, .Leu_0803E9DC
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Leu_0803E9E4
    cmp	r4, #6
    bne .Leu_0803E9E0
    movs	r0, #4
    b .Leu_0803E9EE
.Leu_0803E9DC:
    .4byte 0x00002174
.Leu_0803E9E0:
    movs	r0, #3
    b .Leu_0803E9EE
.Leu_0803E9E4:
    cmp	r6, #6
    beq .Leu_0803E9EC
    movs	r0, #1
    b .Leu_0803E9EE
.Leu_0803E9EC:
    movs	r0, #2
.Leu_0803E9EE:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E9E4
    .thumb_func
func_0803E9E4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r2, [r4, #3]
    adds	r4, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EA20
    movs	r0, #5
    b .Leu_0803EA66
.Leu_0803EA20:
    ldr r1, .Leu_0803EA30
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Leu_0803EA34
    movs	r0, #0
    b .Leu_0803EA66
.Leu_0803EA30:
    .4byte 0x000021CA
.Leu_0803EA34:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803EA64
    cmp	r4, #6
    bne .Leu_0803EA60
    ldr r1, .Leu_0803EA58
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Leu_0803EA5C
    movs	r0, #4
    b .Leu_0803EA66
    .align 2, 0
.Leu_0803EA58:
    .4byte 0x00002174
.Leu_0803EA5C:
    movs	r0, #3
    b .Leu_0803EA66
.Leu_0803EA60:
    movs	r0, #1
    b .Leu_0803EA66
.Leu_0803EA64:
    movs	r0, #2
.Leu_0803EA66:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .section .text.npc_schedule_van_after, "ax", %progbits
    .align 2, 0
    .global func_0803EA98
    .thumb_func
func_0803EA98:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Leu_0803EAC4
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Leu_0803EAC8
    movs	r0, #0
    b .Leu_0803EAE6
    .align 2, 0
.Leu_0803EAC4:
    .4byte 0x000021CA
.Leu_0803EAC8:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803EAE4
    movs	r0, #1
    b .Leu_0803EAE6
.Leu_0803EAE4:
    movs	r0, #2
.Leu_0803EAE6:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EADC
    .thumb_func
func_0803EADC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803EB08
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #124	@ 0x7c
    ands	r0, r1
    cmp	r0, #0
    beq .Leu_0803EB0C
    movs	r0, #0
    b .Leu_0803EB4C
.Leu_0803EB08:
    .4byte 0x000021CA
.Leu_0803EB0C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Leu_0803EB2A
    cmp	r1, #3
    bne .Leu_0803EB2A
    movs	r0, #9
    b .Leu_0803EB4C
.Leu_0803EB2A:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EB38
    movs	r0, #8
    b .Leu_0803EB4C
.Leu_0803EB38:
    cmp	r4, #1
    beq .Leu_0803EB46
    cmp	r4, #3
    beq .Leu_0803EB46
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Leu_0803EB4A
.Leu_0803EB46:
    movs	r0, #1
    b .Leu_0803EB4C
.Leu_0803EB4A:
    movs	r0, #2
.Leu_0803EB4C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB40
    .thumb_func
func_0803EB40:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803EB8C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    blt .Leu_0803EBA6
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #1
    bne .Leu_0803EBA6
    movs	r0, #1
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EB90
    movs	r0, #4
    b .Leu_0803EBA8
.Leu_0803EB8C:
    .4byte 0x000021CA
.Leu_0803EB90:
    cmp	r4, #0
    bne .Leu_0803EBA2
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803EB9E
    movs	r0, #2
    b .Leu_0803EBA8
.Leu_0803EB9E:
    movs	r0, #3
    b .Leu_0803EBA8
.Leu_0803EBA2:
    movs	r0, #1
    b .Leu_0803EBA8
.Leu_0803EBA6:
    movs	r0, #0
.Leu_0803EBA8:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB9C
    .thumb_func
func_0803EB9C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803EBCC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803EBD0
    movs	r0, #0
    b .Leu_0803EC4A
    .align 2, 0
.Leu_0803EBCC:
    .4byte 0x000021CA
.Leu_0803EBD0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Leu_0803EC04
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    adds	r7, r0, #0
    cmp	r7, #4
    bls .Leu_0803EC1E
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EC08
    movs	r0, #9
    b .Leu_0803EC4A
.Leu_0803EC04:
    .4byte 0x00001E28
.Leu_0803EC08:
    cmp	r4, #4
    bne .Leu_0803EC1A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803EC16
    movs	r0, #6
    b .Leu_0803EC4A
.Leu_0803EC16:
    movs	r0, #7
    b .Leu_0803EC4A
.Leu_0803EC1A:
    movs	r0, #5
    b .Leu_0803EC4A
.Leu_0803EC1E:
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EC30
    movs	r0, #8
    b .Leu_0803EC4A
.Leu_0803EC30:
    cmp	r7, #0
    beq .Leu_0803EC48
    cmp	r4, #1
    bne .Leu_0803EC3C
    movs	r0, #3
    b .Leu_0803EC4A
.Leu_0803EC3C:
    cmp	r4, #4
    bne .Leu_0803EC44
    movs	r0, #4
    b .Leu_0803EC4A
.Leu_0803EC44:
    movs	r0, #2
    b .Leu_0803EC4A
.Leu_0803EC48:
    movs	r0, #1
.Leu_0803EC4A:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EC44
    .thumb_func
func_0803EC44:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Leu_0803EC70
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Leu_0803EC74
    movs	r0, #0
    b .Leu_0803ECCC
    .align 2, 0
.Leu_0803EC70:
    .4byte 0x000021CA
.Leu_0803EC74:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EC94
    movs	r0, #4
    b .Leu_0803ECCC
.Leu_0803EC94:
    ldr r0, .Leu_0803ECB4
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetOrder__C7Saibara
    cmp	r0, #0
    beq .Leu_0803ECB8
    adds	r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803ECB8
    movs	r0, #5
    b .Leu_0803ECCC
    .align 2, 0
.Leu_0803ECB4:
    .4byte 0x00001DAC
.Leu_0803ECB8:
    cmp	r6, #4
    bne .Leu_0803ECCA
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803ECC6
    movs	r0, #2
    b .Leu_0803ECCC
.Leu_0803ECC6:
    movs	r0, #3
    b .Leu_0803ECCC
.Leu_0803ECCA:
    movs	r0, #1
.Leu_0803ECCC:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803ECC0
    .thumb_func
func_0803ECC0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803ECFA
    movs	r0, #5
    b .Leu_0803EDD8
.Leu_0803ECFA:
    ldr	r7, [r5, #8]
    ldr r0, .Leu_0803ED3C
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #0
    beq .Leu_0803EDB8
    adds	r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803EDB8
    adds	r0, r4, #0
    bl IsConstructionOrderedToday__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Leu_0803EDB8
    subs	r0, r7, #3
    cmp	r0, #1
    bls .Leu_0803EDB8
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #13
    bhi .Leu_0803EDB8
    lsls	r0, r0, #2
    ldr r1, .Leu_0803ED40
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Leu_0803ED3C:
    .4byte 0x00001F64
.Leu_0803ED40:
    .4byte .Leu_0803ED44
.Leu_0803ED44:
    .4byte .Leu_0803EDB8
    .4byte .Leu_0803ED7C
    .4byte .Leu_0803EDA0
    .4byte .Leu_0803EDA4
    .4byte .Leu_0803EDA8
    .4byte .Leu_0803EDAC
    .4byte .Leu_0803EDAC
    .4byte .Leu_0803EDAC
    .4byte .Leu_0803EDB0
    .4byte .Leu_0803EDB0
    .4byte .Leu_0803EDB0
    .4byte .Leu_0803EDB4
    .4byte .Leu_0803EDB4
    .4byte .Leu_0803EDB4
.Leu_0803ED7C:
    .4byte 0x004921FA
    .4byte 0xF7CD1868
    .4byte 0x2801F8D1
    .4byte 0x2801D006
    .4byte 0x2802D302
    .4byte 0xE011D004
    .4byte 0xE01F2006
    .4byte 0xE01D2007
    .4byte 0xE01B200D
.Leu_0803EDA0:
    .4byte 0xE0192008
.Leu_0803EDA4:
    .4byte 0xE0172009
.Leu_0803EDA8:
    .4byte 0xE015200E
.Leu_0803EDAC:
    .4byte 0xE013200A
.Leu_0803EDB0:
    .4byte 0xE011200B
.Leu_0803EDB4:
    .4byte 0xE00F200C
.Leu_0803EDB8:
    cmp	r6, #5
    bgt .Leu_0803EDC6
    cmp	r6, #4
    bge .Leu_0803EDCE
    cmp	r6, #0
    beq .Leu_0803EDD6
    b .Leu_0803EDCA
.Leu_0803EDC6:
    cmp	r6, #6
    beq .Leu_0803EDD2
.Leu_0803EDCA:
    movs	r0, #1
    b .Leu_0803EDD8
.Leu_0803EDCE:
    movs	r0, #2
    b .Leu_0803EDD8
.Leu_0803EDD2:
    movs	r0, #3
    b .Leu_0803EDD8
.Leu_0803EDD6:
    movs	r0, #4
.Leu_0803EDD8:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EDCC
    .thumb_func
func_0803EDCC:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    adds	r7, r0, #0
    ldrb	r4, [r4, #3]
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EE0C
    movs	r0, #5
    b .Leu_0803EE5C
.Leu_0803EE0C:
    cmp	r6, #2
    bne .Leu_0803EE2C
    cmp	r7, #30
    bne .Leu_0803EE2C
    ldr r1, .Leu_0803EE28
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Leu_0803EE2C
    movs	r0, #6
    b .Leu_0803EE5C
    .align 2, 0
.Leu_0803EE28:
    .4byte 0x000021A2
.Leu_0803EE2C:
    ldr r1, .Leu_0803EE3C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Leu_0803EE40
    movs	r0, #0
    b .Leu_0803EE5C
.Leu_0803EE3C:
    .4byte 0x0000215A
.Leu_0803EE40:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803EE5A
    cmp	r4, #1
    bne .Leu_0803EE4E
    movs	r0, #1
    b .Leu_0803EE5C
.Leu_0803EE4E:
    cmp	r4, #3
    bne .Leu_0803EE56
    movs	r0, #2
    b .Leu_0803EE5C
.Leu_0803EE56:
    movs	r0, #3
    b .Leu_0803EE5C
.Leu_0803EE5A:
    movs	r0, #4
.Leu_0803EE5C:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EE50
    .thumb_func
func_0803EE50:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Leu_0803EE8A
    movs	r0, #4
    b .Leu_0803EE9E
.Leu_0803EE8A:
    cmp	r4, #1
    bne .Leu_0803EE9C
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Leu_0803EE98
    movs	r0, #2
    b .Leu_0803EE9E
.Leu_0803EE98:
    movs	r0, #3
    b .Leu_0803EE9E
.Leu_0803EE9C:
    movs	r0, #1
.Leu_0803EE9E:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .else
    .ifdef REGION_DE
    @ ROM-verified DE Thumb code_0803A8A4/main
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .section .text.ui_text_window_native, "ax", %progbits
    .align 2, 0
    .global __12UiTextWindowiiUiUiUiUiUiUi
    .thumb_func
__12UiTextWindowiiUiUiUiUiUiUi:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    mov	ip, r0
    ldr	r0, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #48]	@ 0x30
    ldr	r4, [sp, #52]	@ 0x34
    ldr	r6, [sp, #56]	@ 0x38
    movs	r7, #0
    mov	r9, r7
    mov	r7, ip
    strh	r1, [r7, #0]
    strh	r2, [r7, #2]
    strh	r3, [r7, #4]
    strh	r0, [r7, #6]
    movs	r0, #3
    ands	r5, r0
    ldrb	r0, [r7, #8]
    movs	r1, #4
    negs	r1, r1
    mov	r8, r1
    mov	r2, r8
    ands	r2, r0
    orrs	r2, r5
    adds	r0, r4, #0
    movs	r7, #31
    ands	r0, r7
    lsls	r0, r0, #2
    subs	r1, #121	@ 0x79
    ands	r2, r1
    orrs	r2, r0
    mov	r8, r2
    mov	r0, ip
    strb	r2, [r0, #8]
    lsrs	r1, r4, #3
    movs	r0, #3
    ands	r1, r0
    lsls	r1, r1, #7
    mov	r2, ip
    ldrh	r0, [r2, #8]
    ldr r3, .Lde_0803B990
    ands	r3, r0
    orrs	r3, r1
    strh	r3, [r2, #8]
    movs	r0, #7
    ands	r4, r0
    lsls	r4, r4, #6
    adds	r4, #20
    ldr r7, .Lde_0803B994
    str	r7, [sp, #0]
    lsls	r4, r4, #9
    ldr	r5, [r2, #8]
    ldr r0, .Lde_0803B998
    ands	r5, r0
    orrs	r5, r4
    str	r5, [r2, #8]
    movs	r0, #15
    ands	r6, r0
    lsls	r6, r6, #3
    ldrb	r0, [r2, #10]
    movs	r1, #121	@ 0x79
    negs	r1, r1
    mov	sl, r1
    mov	r2, sl
    ands	r2, r0
    orrs	r2, r6
    mov	sl, r2
    mov	r6, ip
    strb	r2, [r6, #10]
    movs	r0, #255	@ 0xff
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r0
    lsls	r1, r1, #7
    ldrh	r2, [r6, #10]
    ldr r0, .Lde_0803B99C
    ands	r0, r2
    orrs	r0, r1
    strh	r0, [r6, #10]
    ldrb	r1, [r6, #11]
    movs	r0, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r6, #11]
    ldrb	r1, [r6, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #12]
    movs	r7, #0
    strb	r7, [r6, #13]
    mov	r2, ip
    adds	r2, #16
    mov	r0, r9
    str	r0, [r6, #16]
    str	r0, [r2, #4]
    ldr r0, .Lde_0803B9A0
    str	r0, [r2, #8]
    adds	r1, r2, #0
    adds	r1, #16
    str	r1, [r2, #12]
    mov	r6, r9
    str	r6, [r1, #4]
    ldr r0, .Lde_0803B9A4
    str	r0, [r1, #8]
    mov	r0, ip
    adds	r0, #28
    str	r0, [r2, #16]
    str	r1, [r2, #20]
    lsls	r3, r3, #23
    lsrs	r3, r3, #30
    lsls	r5, r5, #13
    lsrs	r7, r5, #22
    lsls	r3, r3, #9
    adds	r2, r3, r7
    ldr r0, .Lde_0803B9A8
    ldr	r0, [r0, #0]
    lsrs	r5, r0, #5
    movs	r4, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Lde_0803B8D8
    movs	r4, #1
.Lde_0803B8D8:
    mov	r1, ip
    adds	r1, #44	@ 0x2c
    ldr r0, .Lde_0803B9AC
    ldr	r3, [r0, #0]
    lsls	r2, r2, #5
    movs	r0, #192	@ 0xc0
    lsls	r0, r0, #19
    adds	r2, r2, r0
    mov	r6, r9
    mov	r0, ip
    str	r6, [r0, #44]	@ 0x2c
    str	r6, [r1, #4]
    ldr r0, .Lde_0803B9B0
    str	r0, [r1, #8]
    str	r3, [r1, #12]
    str	r2, [r1, #16]
    strb	r5, [r1, #20]
    strb	r4, [r1, #21]
    movs	r2, #0
    strb	r2, [r1, #22]
    mov	r6, ip
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    cmp	r0, #0
    bge .Lde_0803B90C
    adds	r0, #7
.Lde_0803B90C:
    asrs	r0, r0, #3
    str	r0, [sp, #4]
    mov	r2, ip
    movs	r0, #2
    ldrsh	r6, [r2, r0]
    cmp	r6, #0
    bge .Lde_0803B91C
    adds	r6, #7
.Lde_0803B91C:
    asrs	r6, r6, #3
    str	r6, [sp, #8]
    mov	r1, ip
    ldrh	r4, [r1, #4]
    lsrs	r4, r4, #3
    ldrh	r1, [r1, #6]
    lsrs	r1, r1, #3
    mov	r2, r8
    lsls	r3, r2, #25
    lsrs	r3, r3, #27
    mov	r6, sl
    lsls	r5, r6, #25
    mov	r2, ip
    adds	r2, #68	@ 0x44
    mov	r0, r9
    mov	r6, ip
    str	r0, [r6, #68]	@ 0x44
    str	r0, [r2, #4]
    ldr r0, .Lde_0803B9B4
    str	r0, [r2, #8]
    ldr	r0, [sp, #4]
    str	r0, [r2, #12]
    ldr	r6, [sp, #8]
    str	r6, [r2, #16]
    str	r4, [r2, #20]
    str	r1, [r2, #24]
    movs	r0, #31
    ands	r3, r0
    ldrb	r1, [r2, #28]
    subs	r0, #63	@ 0x3f
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #28]
    ldr	r1, [sp, #0]
    ands	r7, r1
    lsls	r3, r7, #5
    ldrh	r1, [r2, #28]
    ldr r0, .Lde_0803B9B8
    ands	r0, r1
    orrs	r0, r3
    strh	r0, [r2, #28]
    lsrs	r5, r5, #28
    lsls	r5, r5, #15
    ldr	r0, [r2, #28]
    ldr r1, .Lde_0803B9BC
    ands	r0, r1
    orrs	r0, r5
    str	r0, [r2, #28]
    mov	r0, ip
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lde_0803B990:
    .4byte 0xFFFFFE7F
.Lde_0803B994:
    .4byte 0x000003FF
.Lde_0803B998:
    .4byte 0xFFF801FF
.Lde_0803B99C:
    .4byte 0xFFFF807F
.Lde_0803B9A0:
    .4byte __vt_18HardwareLinkedList
.Lde_0803B9A4:
    .4byte __vt_12HardwareLink
.Lde_0803B9A8:
    .4byte gUiSharedTileByteCount
.Lde_0803B9AC:
    .4byte gUiSharedTiles
.Lde_0803B9B0:
    .4byte __vt_29UiTextWindowTileUploadCommand
.Lde_0803B9B4:
    .4byte __vt_25UiTextWindowBorderCommand
.Lde_0803B9B8:
    .4byte 0xFFFF801F
.Lde_0803B9BC:
    .4byte 0xFFF87FFF
    .global Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2
    .thumb_func
Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    adds	r4, r2, #0
    mov	sl, r3
    ldrb	r2, [r7, #11]
    lsrs	r1, r2, #7
    ldrb	r0, [r7, #12]
    movs	r3, #127	@ 0x7f
    ands	r0, r3
    lsls	r0, r0, #1
    orrs	r0, r1
    cmp	r0, #1
    beq .Lde_0803B9F0
    cmp	r0, #1
    ble .Lde_0803BA2C
    cmp	r0, #2
    beq .Lde_0803BA10
    b .Lde_0803BA2C
.Lde_0803B9F0:
    ldrb	r0, [r7, #13]
    cmp	r0, #8
    bls .Lde_0803BA0C
    movs	r0, #128	@ 0x80
    orrs	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r7, #12]
    b .Lde_0803BA2C
.Lde_0803BA0C:
    adds	r0, #1
    b .Lde_0803BA2A
.Lde_0803BA10:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    bne .Lde_0803BA28
    adds	r0, r3, #0
    ands	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r7, #12]
    b .Lde_0803BA2C
.Lde_0803BA28:
    subs	r0, #1
.Lde_0803BA2A:
    strb	r0, [r7, #13]
.Lde_0803BA2C:
    adds	r3, r7, #0
    adds	r3, #16
    movs	r2, #0
    adds	r1, r3, #0
    adds	r1, #16
    ldr	r0, [r3, #12]
    cmp	r0, r1
    bne .Lde_0803BA3E
    movs	r2, #1
.Lde_0803BA3E:
    cmp	r2, #0
    bne .Lde_0803BA4E
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #28]
    adds	r0, r4, #0
    adds	r1, r3, #0
    bl _call_via_r2
.Lde_0803BA4E:
    ldrb	r0, [r7, #11]
    lsrs	r0, r0, #7
    ldrb	r1, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r1, r2
    lsls	r1, r1, #1
    orrs	r1, r0
    cmp	r1, #0
    bne .Lde_0803BA62
    b .Lde_0803BBBC
.Lde_0803BA62:
    movs	r0, #0
    mov	r8, r0
    ldrb	r4, [r7, #8]
    lsls	r2, r4, #30
    lsrs	r2, r2, #30
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    lsls	r0, r2
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #6
    adds	r1, r3, #0
    orrs	r0, r1
    mov	r5, r9
    ldrh	r1, [r5, #0]
    orrs	r0, r1
    strh	r0, [r5, #0]
    lsls	r3, r2, #1
    lsls	r2, r2, #2
    mov	r5, sp
    ldrh	r1, [r7, #8]
    lsls	r1, r1, #23
    lsrs	r1, r1, #30
    lsls	r1, r1, #2
    lsls	r0, r4, #25
    lsrs	r0, r0, #27
    lsls	r0, r0, #8
    orrs	r1, r0
    movs	r0, #64	@ 0x40
    orrs	r1, r0
    strh	r1, [r5, #0]
    adds	r3, #8
    add	r3, r9
    strh	r1, [r3, #0]
    mov	r0, sp
    mov	r1, r8
    strh	r1, [r0, #0]
    adds	r0, r2, #0
    adds	r0, #16
    add	r0, r9
    strh	r1, [r0, #0]
    mov	r1, sp
    ldrh	r5, [r7, #2]
    negs	r0, r5
    strh	r0, [r1, #0]
    adds	r2, #18
    add	r2, r9
    strh	r0, [r2, #0]
    ldrb	r6, [r7, #13]
    strb	r4, [r1, #4]
    cmp	r6, #8
    bls .Lde_0803BAF0
    mov	r3, sp
    ldrh	r0, [r7, #0]
    lsls	r2, r0, #8
    ldrh	r1, [r7, #4]
    adds	r0, r0, r1
    orrs	r2, r0
    strh	r2, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r2, [r0, #0]
    mov	r2, sp
    lsls	r1, r5, #8
    ldrh	r0, [r7, #6]
    adds	r0, r5, r0
    orrs	r1, r0
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #68	@ 0x44
    strh	r1, [r0, #0]
    b .Lde_0803BB58
.Lde_0803BAF0:
    ldrh	r4, [r7, #6]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    mov	r8, r0
    movs	r2, #2
    ldrsh	r5, [r7, r2]
    adds	r4, r5, r4
    adds	r5, r5, r4
    lsrs	r0, r5, #31
    adds	r5, r5, r0
    asrs	r5, r5, #1
    mov	r3, r8
    lsrs	r0, r3, #31
    add	r0, r8
    asrs	r0, r0, #1
    subs	r5, r5, r0
    ldrh	r4, [r7, #4]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    movs	r1, #0
    ldrsh	r2, [r7, r1]
    adds	r4, r2, r4
    adds	r2, r2, r4
    lsrs	r1, r2, #31
    adds	r2, r2, r1
    asrs	r2, r2, #1
    lsrs	r1, r0, #31
    adds	r1, r0, r1
    asrs	r1, r1, #1
    subs	r2, r2, r1
    mov	r3, sp
    lsls	r1, r2, #8
    adds	r2, r2, r0
    orrs	r1, r2
    strh	r1, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r1, [r0, #0]
    mov	r1, sp
    lsls	r0, r5, #8
    add	r5, r8
    orrs	r0, r5
    strh	r0, [r1, #0]
    mov	r1, r9
    adds	r1, #68	@ 0x44
    strh	r0, [r1, #0]
.Lde_0803BB58:
    mov	r0, sp
    movs	r1, #63	@ 0x3f
    strh	r1, [r0, #0]
    mov	r3, r9
    adds	r3, #72	@ 0x48
    strh	r1, [r3, #0]
    mov	r2, sp
    ldrb	r4, [r2, #4]
    lsls	r0, r4, #30
    lsrs	r0, r0, #30
    movs	r4, #1
    lsls	r4, r0
    bics	r1, r4
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #74	@ 0x4a
    strh	r1, [r0, #0]
    ldrh	r0, [r7, #10]
    lsls	r0, r0, #17
    lsrs	r2, r0, #24
    cmp	r2, #2
    bne .Lde_0803BB94
    ldrh	r0, [r3, #0]
    movs	r1, #32
    orrs	r0, r1
    strh	r0, [r3, #0]
    ldr r0, .Lde_0803BBB8
    orrs	r4, r0
    mov	r5, r9
    str	r4, [r5, #80]	@ 0x50
.Lde_0803BB94:
    cmp	r2, #1
    bne .Lde_0803BBEC
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    blt .Lde_0803BBEC
    mov	r1, sl
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
    b .Lde_0803BBEC
    .align 2, 0
.Lde_0803BBB8:
    .4byte 0x08083F40
.Lde_0803BBBC:
    ldrb	r0, [r7, #8]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #1
    lsls	r1, r0
    mov	r2, r9
    ldrh	r0, [r2, #0]
    bics	r0, r1
    strh	r0, [r2, #0]
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lde_0803BBEC
    mov	r4, sl
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #20]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
.Lde_0803BBEC:
    ldrb	r1, [r7, #11]
    lsrs	r1, r1, #7
    ldrb	r0, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    lsls	r0, r0, #1
    orrs	r0, r1
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    @ Remaining control-widget code after the recovered border constructor.
    .section .text.main_menu_widget_update_impl, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0
    .global UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
    .thumb_func
UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #116	@ 0x74
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r2, [sp, #68]	@ 0x44
    adds	r1, r3, #0
    ldr	r3, [sp, #152]	@ 0x98
    ldr	r5, [sp, #156]	@ 0x9c
    ldr	r2, [sp, #148]	@ 0x94
    bl Update__13ControlWidgetP20HardwareDisplayStateP18HardwareLinkedListT2
    str	r0, [sp, #72]	@ 0x48
    cmp	r0, #0
    bge .Lde_0803BF62
    b .Lde_0803C41A
.Lde_0803BF62:
    cmp	r0, #2
    bgt .Lde_0803BF68
    b .Lde_0803C41A
.Lde_0803BF68:
    cmp	r0, #3
    beq .Lde_0803BF6E
    b .Lde_0803C41A
.Lde_0803BF6E:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    ldrb	r0, [r7, #15]
    cmp	r0, #0
    beq .Lde_0803BFF0
    ldrh	r3, [r4, #8]
    adds	r2, r3, #0
    lsls	r1, r2, #26
    lsrs	r1, r1, #31
    lsls	r0, r2, #27
    lsrs	r0, r0, #31
    orrs	r1, r0
    cmp	r1, #0
    beq .Lde_0803BFDC
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    beq .Lde_0803BFA0
    ldrb	r0, [r7, #12]
    cmp	r0, #0
    bne .Lde_0803BF9C
    movs	r0, #6
    b .Lde_0803BFB8
.Lde_0803BF9C:
    subs	r0, #1
    b .Lde_0803BFB8
.Lde_0803BFA0:
    movs	r0, #16
    ands	r2, r0
    cmp	r2, #0
    beq .Lde_0803BFBA
    ldrb	r0, [r7, #12]
    cmp	r0, #6
    bne .Lde_0803BFB6
    add	r1, sp, #76	@ 0x4c
    ldrb	r1, [r1, #0]
    strb	r1, [r7, #12]
    b .Lde_0803BFBA
.Lde_0803BFB6:
    adds	r0, #1
.Lde_0803BFB8:
    strb	r0, [r7, #12]
.Lde_0803BFBA:
    cmp	r5, #0
    beq .Lde_0803BFC6
    adds	r0, r5, #0
    movs	r1, #203	@ 0xcb
    bl Start__23HardwareMusicPlayerSlotUs
.Lde_0803BFC6:
    ldr r0, .Lde_0803BFD8
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #20
    strb	r0, [r7, #14]
    b .Lde_0803BFF0
.Lde_0803BFD8:
    .4byte gMenuEntryLabels
.Lde_0803BFDC:
    movs	r0, #1
    ands	r3, r0
    cmp	r3, #0
    beq .Lde_0803BFF0
    cmp	r5, #0
    beq .Lde_0803BFF0
    adds	r0, r5, #0
    movs	r1, #197	@ 0xc5
    bl Start__23HardwareMusicPlayerSlotUs
.Lde_0803BFF0:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    beq .Lde_0803C056
    ldr	r4, [r7, #8]
    ldr	r0, [r4, #80]	@ 0x50
    ldr	r1, [r0, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #44]	@ 0x2c
    lsls	r2, r2, #2
    ldr	r0, [r0, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    ldr	r5, [sp, #20]
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r2, r0, #0
    add	r1, sp, #20
    ldr	r0, [sp, #20]
    movs	r3, #0
    cmp	r0, #0
    beq .Lde_0803C02A
    ldrh	r3, [r1, #4]
.Lde_0803C02A:
    adds	r1, r4, #0
    adds	r1, #56	@ 0x38
    lsls	r0, r2, #5
    ldr r2, .Lde_0803C3E4
    adds	r0, r0, r2
    str	r5, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
    ldr r1, .Lde_0803C3E8
    ldrb	r0, [r7, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r7, #13]
.Lde_0803C056:
    ldrb	r0, [r7, #14]
    subs	r0, #1
    strb	r0, [r7, #14]
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803C066
    movs	r0, #40	@ 0x28
    strb	r0, [r7, #14]
.Lde_0803C066:
    ldrb	r0, [r7, #14]
    cmp	r0, #19
    bhi .Lde_0803C162
    ldr	r0, [r7, #8]
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #4
    adds	r1, #16
    mov	r8, r1
    ldr	r4, [r0, #80]	@ 0x50
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r9, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Lde_0803C0E2
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Lde_0803C0C6
    ldrh	r3, [r1, #4]
.Lde_0803C0C6:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r5, .Lde_0803C3EC
    adds	r0, r0, r5
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r2, [sp, #148]	@ 0x94
    ldr	r0, [r2, #8]
    ldr	r2, [r0, #16]
    ldr	r0, [sp, #148]	@ 0x94
    bl _call_via_r2
.Lde_0803C0E2:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    add	r0, r8
    ldr r1, .Lde_0803C3F0
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Lde_0803C3F4
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #36]	@ 0x24
    add	r4, sp, #36	@ 0x24
    ldrb	r0, [r4, #0]
    adds	r0, #150	@ 0x96
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr r1, .Lde_0803C3F8
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    mov	r3, r9
    lsls	r1, r3, #16
    lsrs	r1, r1, #16
    movs	r0, #15
    ands	r1, r0
    lsls	r1, r1, #12
    ldr r2, .Lde_0803C3FC
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Lde_0803C400
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #5
    ldr	r1, [sp, #36]	@ 0x24
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r2, [r5, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Lde_0803C162
    lsls	r0, r2, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r5, #0]
.Lde_0803C162:
    ldr	r0, [r7, #8]
    mov	sl, r0
    movs	r1, #0
    mov	r9, r1
    mov	r2, sp
    adds	r2, #44	@ 0x2c
    str	r2, [sp, #96]	@ 0x60
    ldr	r3, [sp, #76]	@ 0x4c
    negs	r3, r3
    str	r3, [sp, #104]	@ 0x68
    mov	r4, sp
    adds	r4, #60	@ 0x3c
    str	r4, [sp, #100]	@ 0x64
    movs	r5, #16
    str	r5, [sp, #108]	@ 0x6c
.Lde_0803C180:
    mov	r1, r9
    lsls	r0, r1, #2
    add	r0, sl
    ldr	r4, [r0, #84]	@ 0x54
    mov	r0, sl
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r8, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Lde_0803C1F4
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Lde_0803C1D8
    ldrh	r3, [r1, #4]
.Lde_0803C1D8:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r2, .Lde_0803C3EC
    adds	r0, r0, r2
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
.Lde_0803C1F4:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r0, r0, r4
    ldr r1, .Lde_0803C3F0
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Lde_0803C3F4
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #96]	@ 0x60
    ldrb	r1, [r5, #0]
    adds	r1, #150	@ 0x96
    lsls	r1, r1, #24
    lsrs	r1, r1, #24
    ldr r0, .Lde_0803C3F8
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #44]	@ 0x2c
    mov	r0, r8
    lsls	r1, r0, #16
    lsrs	r1, r1, #16
    movs	r2, #15
    ands	r1, r2
    lsls	r1, r1, #12
    add	r4, sp, #44	@ 0x2c
    ldr	r0, [r4, #4]
    ldr r3, .Lde_0803C3FC
    ands	r0, r3
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Lde_0803C400
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r5, #128	@ 0x80
    lsls	r5, r5, #5
    orrs	r1, r5
    str	r1, [sp, #44]	@ 0x2c
    ldr	r0, [sp, #68]	@ 0x44
    ldrb	r2, [r0, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Lde_0803C27A
    lsls	r0, r2, #3
    adds	r0, #4
    ldr	r3, [sp, #68]	@ 0x44
    adds	r0, r3, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r3, #0]
.Lde_0803C27A:
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r4, #16
    str	r4, [sp, #108]	@ 0x6c
    movs	r5, #1
    add	r9, r5
    mov	r0, r9
    cmp	r0, #6
    bhi .Lde_0803C28C
    b .Lde_0803C180
.Lde_0803C28C:
    ldr	r7, [r7, #8]
    mov	r8, r7
    ldr	r1, [sp, #76]	@ 0x4c
    cmp	r1, #0
    beq .Lde_0803C2C4
    add	r0, sp, #52	@ 0x34
    movs	r4, #12
    movs	r5, #2
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    mov	r6, r8
    adds	r6, #116	@ 0x74
    adds	r1, r6, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    add	r0, sp, #56	@ 0x38
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #56]	@ 0x38
    ldr	r2, [sp, #76]	@ 0x4c
    str	r2, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Lde_0803C2C4:
    mov	r0, r8
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    ldr	r3, [sp, #104]	@ 0x68
    ldr	r4, [sp, #76]	@ 0x4c
    orrs	r3, r4
    mov	r5, r8
    adds	r5, #112	@ 0x70
    str	r5, [sp, #80]	@ 0x50
    lsrs	r1, r3, #31
    str	r1, [sp, #84]	@ 0x54
    movs	r1, #0
    movs	r2, #0
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    ldr r2, .Lde_0803C404
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #24
    orrs	r1, r2
    ldr r2, .Lde_0803C408
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #7
    orrs	r1, r2
    str	r1, [sp, #60]	@ 0x3c
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    movs	r2, #15
    ands	r0, r2
    lsls	r0, r0, #12
    ldr	r3, [sp, #100]	@ 0x64
    ldr	r1, [r3, #4]
    ldr r4, .Lde_0803C3FC
    ands	r1, r4
    orrs	r1, r0
    str	r1, [r3, #4]
    ldr	r0, [sp, #60]	@ 0x3c
    ldr r5, .Lde_0803C3F8
    ands	r0, r5
    movs	r1, #142	@ 0x8e
    orrs	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #5
    orrs	r0, r1
    str	r0, [sp, #60]	@ 0x3c
    movs	r4, #0
    mov	r2, r8
    adds	r2, #116	@ 0x74
    str	r2, [sp, #88]	@ 0x58
.Lde_0803C32E:
    lsls	r0, r4, #3
    ldr	r3, [sp, #80]	@ 0x50
    adds	r0, r0, r3
    movs	r5, #193	@ 0xc1
    lsls	r5, r5, #2
    adds	r0, r0, r5
    ldr	r1, [r0, #4]
    bl GetObjTileIndex
    mov	r8, r0
    lsls	r0, r4, #5
    mov	sl, r0
    adds	r1, r4, #1
    str	r1, [sp, #92]	@ 0x5c
    ldr	r2, [sp, #84]	@ 0x54
    cmp	r2, #0
    beq .Lde_0803C3AC
    movs	r3, #0
    lsls	r2, r4, #1
    lsls	r1, r4, #2
    movs	r4, #128	@ 0x80
    mov	r9, r4
    adds	r1, r1, r2
    lsls	r1, r1, #3
    ldr	r5, [sp, #80]	@ 0x50
    movs	r4, #202	@ 0xca
    lsls	r4, r4, #2
    adds	r0, r5, r4
    adds	r4, r1, r0
    mov	r5, r8
    lsls	r0, r5, #5
    ldr r5, .Lde_0803C3EC
    adds	r7, r0, r5
    lsls	r2, r2, #6
    ldr	r0, [sp, #88]	@ 0x58
    adds	r6, r2, r0
    ldr	r2, [sp, #80]	@ 0x50
    movs	r5, #199	@ 0xc7
    lsls	r5, r5, #2
    adds	r0, r2, r5
    adds	r5, r1, r0
.Lde_0803C380:
    str	r6, [r4, #0]
    str	r7, [r4, #4]
    mov	r0, r9
    str	r0, [r4, #8]
    ldr	r1, [sp, #148]	@ 0x94
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    adds	r0, r1, #0
    adds	r1, r5, #0
    str	r3, [sp, #112]	@ 0x70
    bl _call_via_r2
    adds	r4, #24
    adds	r7, #128	@ 0x80
    movs	r2, #192	@ 0xc0
    lsls	r2, r2, #1
    adds	r6, r6, r2
    adds	r5, #24
    ldr	r3, [sp, #112]	@ 0x70
    adds	r3, #1
    cmp	r3, #1
    bls .Lde_0803C380
.Lde_0803C3AC:
    mov	r3, r8
    lsls	r1, r3, #22
    lsrs	r1, r1, #22
    ldr r2, .Lde_0803C400
    ldr	r4, [sp, #100]	@ 0x64
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    mov	r1, sl
    adds	r1, #136	@ 0x88
    ldr r0, .Lde_0803C3F0
    ands	r1, r0
    lsls	r1, r1, #16
    ldr r0, .Lde_0803C3F4
    ldr	r2, [sp, #60]	@ 0x3c
    ands	r2, r0
    orrs	r2, r1
    str	r2, [sp, #60]	@ 0x3c
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r3, [r5, #0]
    cmp	r3, #127	@ 0x7f
    bhi .Lde_0803C414
    lsls	r0, r3, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r2, [r0, #0]
    b .Lde_0803C40C
.Lde_0803C3E4:
    .word OBJ_PALETTE
.Lde_0803C3E8:
    .4byte gMenuEntryLabels
.Lde_0803C3EC:
    .word OBJ_VRAM0
.Lde_0803C3F0:
    .4byte 0x000001FF
.Lde_0803C3F4:
    .4byte 0xFE00FFFF
.Lde_0803C3F8:
    .4byte 0xFFFFFF00
.Lde_0803C3FC:
    .4byte 0xFFFF0FFF
.Lde_0803C400:
    .4byte 0xFFFFFC00
.Lde_0803C404:
    .4byte 0x3FFFFFFF
.Lde_0803C408:
    .4byte 0xFFFF3FFF
.Lde_0803C40C:
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r3, #1
    strb	r0, [r5, #0]
.Lde_0803C414:
    ldr	r4, [sp, #92]	@ 0x5c
    cmp	r4, #2
    bls .Lde_0803C32E
.Lde_0803C41A:
    ldr	r0, [sp, #72]	@ 0x48
    add	sp, #116	@ 0x74
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .section .text.map_clock_status_calendar, "ax", %progbits
    .align 2, 0
    .global UpdateMapClockStatusHudCalendar
    .thumb_func
UpdateMapClockStatusHudCalendar:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #44	@ 0x2c
    str	r1, [sp, #32]
    lsls	r2, r2, #24
    lsrs	r2, r2, #24
    str	r2, [sp, #36]	@ 0x24
    ldr	r7, [r0, #0]
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    beq .Lde_0803CCC2
    cmp	r0, #1
    ble .Lde_0803CCBC
    cmp	r0, #2
    beq .Lde_0803CCC8
    cmp	r0, #3
    beq .Lde_0803CCCE
.Lde_0803CCBC:
    movs	r5, #11
    movs	r6, #12
    b .Lde_0803CCD2
.Lde_0803CCC2:
    movs	r5, #13
    movs	r6, #14
    b .Lde_0803CCD2
.Lde_0803CCC8:
    movs	r5, #15
    movs	r6, #16
    b .Lde_0803CCD2
.Lde_0803CCCE:
    movs	r5, #17
    movs	r6, #18
.Lde_0803CCD2:
    adds	r0, r7, #0
    adds	r0, #132	@ 0x84
    lsls	r1, r5, #5
    ldr r2, .Lde_0803CD74
    mov	r9, r2
    add	r1, r9
    movs	r2, #32
    bl memcpy
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #1
    adds	r4, r7, r0
    movs	r1, #1
    mov	r8, r1
    mov	r2, r8
    strb	r2, [r4, #0]
    lsls	r1, r6, #5
    add	r1, r9
    adds	r0, r7, #0
    adds	r0, #164	@ 0xa4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    ldr	r1, [sp, #32]
    ldrb	r3, [r1, #1]
    lsls	r0, r3, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    adds	r5, r0, #0
    ldrb	r2, [r1, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    lsls	r3, r3, #30
    lsrs	r3, r3, #30
    adds	r2, #6
    lsls	r1, r3, #4
    subs	r1, r1, r3
    lsls	r1, r1, #1
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r1, r5
    subs	r1, #1
    str	r4, [sp, #40]	@ 0x28
    cmp	r1, #6
    bls .Lde_0803CD3E
    adds	r0, r1, #0
    movs	r1, #7
    bl __umodsi3
    adds	r1, r0, #0
.Lde_0803CD3E:
    movs	r0, #7
    adds	r6, r0, #0
    ands	r6, r1
    adds	r0, r5, #0
    movs	r1, #10
    bl __udivsi3
    adds	r4, r0, #0
    adds	r0, r5, #0
    movs	r1, #10
    bl __umodsi3
    adds	r5, r0, #0
    cmp	r4, #0
    ble .Lde_0803CD78
    lsls	r1, r4, #5
    add	r1, r9
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #40]	@ 0x28
    strb	r0, [r2, #0]
    b .Lde_0803CD94
    .align 2, 0
.Lde_0803CD74:
    .4byte gMapClockStatusGlyphTiles
.Lde_0803CD78:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    ldr	r1, [sp, #40]	@ 0x28
    strb	r2, [r1, #0]
.Lde_0803CD94:
    lsls	r1, r5, #5
    ldr r0, .Lde_0803CDB8
    adds	r1, r1, r0
    adds	r0, r7, #0
    adds	r0, #228	@ 0xe4
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    ldr	r1, [sp, #40]	@ 0x28
    strb	r0, [r1, #0]
    cmp	r6, #6
    bhi .Lde_0803CDDC
    lsls	r0, r6, #2
    ldr r1, .Lde_0803CDBC
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_0803CDB8:
    .4byte gMapClockStatusGlyphTiles
.Lde_0803CDBC:
    .4byte .Lde_0803CDC0
.Lde_0803CDC0:
    .4byte .Lde_0803CDDC
    .4byte .Lde_0803CDE8
    .4byte .Lde_0803CDF4
    .4byte .Lde_0803CE00
    .4byte .Lde_0803CE0C
    .4byte .Lde_0803CE18
    .4byte .Lde_0803CE24
.Lde_0803CDDC:
    movs	r0, #96	@ 0x60
    str	r0, [sp, #0]
    movs	r0, #97	@ 0x61
    str	r0, [sp, #4]
    movs	r0, #98	@ 0x62
    b .Lde_0803CE2E
.Lde_0803CDE8:
    .4byte 0x90002063
    .4byte 0x90012064
    .4byte 0xE01C2065
.Lde_0803CDF4:
    .4byte 0x90002066
    .4byte 0x90012067
    .4byte 0xE0162068
.Lde_0803CE00:
    .4byte 0x90002069
    .4byte 0x9001206A
    .4byte 0xE010206B
.Lde_0803CE0C:
    .4byte 0x9000206C
    .4byte 0x9001206D
    .4byte 0xE00A206E
.Lde_0803CE18:
    .4byte 0x9000206F
    .4byte 0x90012070
    .4byte 0xE0042071
.Lde_0803CE24:
    .4byte 0x90002072
    .4byte 0x90012073
    .hword 0x2074
.Lde_0803CE2E:
    str	r0, [sp, #8]
    movs	r2, #212	@ 0xd4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    ldr	r1, [sp, #0]
    lsls	r1, r1, #5
    ldr r2, .Lde_0803CEB0
    mov	r9, r2
    add	r1, r9
    movs	r2, #32
    bl memcpy
    movs	r0, #172	@ 0xac
    lsls	r0, r0, #2
    adds	r5, r7, r0
    movs	r1, #1
    mov	sl, r1
    mov	r2, sl
    strb	r2, [r5, #0]
    ldr	r1, [sp, #4]
    lsls	r1, r1, #5
    add	r1, r9
    movs	r2, #228	@ 0xe4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, sl
    strb	r0, [r5, #0]
    ldr	r1, [sp, #8]
    lsls	r1, r1, #5
    add	r1, r9
    movs	r2, #244	@ 0xf4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, sl
    strb	r0, [r5, #0]
    ldr	r1, [sp, #32]
    ldr	r4, [r1, #0]
    lsls	r4, r4, #11
    lsrs	r4, r4, #27
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r6, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    mov	r8, r5
    cmp	r6, #0
    ble .Lde_0803CEB4
    lsls	r1, r6, #5
    add	r1, r9
    movs	r2, #178	@ 0xb2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    b .Lde_0803CEC6
    .align 2, 0
.Lde_0803CEB0:
    .4byte gMapClockStatusGlyphTiles
.Lde_0803CEB4:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    movs	r2, #178	@ 0xb2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    mov	r1, sp
.Lde_0803CEC6:
    movs	r2, #32
    bl memcpy
    mov	r1, sl
    ldr	r0, [sp, #40]	@ 0x28
    strb	r1, [r0, #0]
    lsls	r1, r4, #5
    ldr r2, .Lde_0803CF64
    mov	r9, r2
    add	r1, r9
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    movs	r6, #1
    mov	r0, r8
    strb	r6, [r0, #0]
    ldr	r1, [sp, #32]
    ldr	r0, [r1, #0]
    lsls	r0, r0, #5
    lsrs	r0, r0, #26
    movs	r1, #10
    bl __udivsi3
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    lsls	r4, r0, #2
    adds	r4, r4, r0
    lsls	r4, r4, #1
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    lsls	r5, r5, #5
    add	r5, r9
    movs	r2, #154	@ 0x9a
    lsls	r2, r2, #2
    adds	r0, r7, r2
    adds	r1, r5, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r6, [r0, #0]
    lsls	r4, r4, #5
    add	r4, r9
    movs	r1, #162	@ 0xa2
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r4, #0
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    strb	r6, [r2, #0]
    ldr	r0, [sp, #36]	@ 0x24
    cmp	r0, #0
    beq .Lde_0803CF68
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #1
    add	r1, r9
    movs	r2, #146	@ 0x92
    lsls	r2, r2, #2
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r6, [r0, #0]
    b .Lde_0803CF84
    .align 2, 0
.Lde_0803CF64:
    .4byte gMapClockStatusGlyphTiles
.Lde_0803CF68:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    movs	r1, #146	@ 0x92
    lsls	r1, r1, #2
    adds	r0, r7, r1
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    strb	r6, [r2, #0]
.Lde_0803CF84:
    add	sp, #44	@ 0x2c
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0

    .section .text.farming_calendar_helpers, "ax", %progbits
    .align 2, 0
    .global DecodeGameDayDate
    .thumb_func
DecodeGameDayDate:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r5, r1, #0
    ldrb	r3, [r5, #1]
    add	r4, sp, #8
    strb	r3, [r4, #0]
    ldrb	r2, [r5, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
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
    mov	r8, r4
    cmp	r3, #6
    bls .Lde_0803D46A
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lde_0803D46A:
    movs	r1, #8
    negs	r1, r1
    movs	r0, #7
    ands	r0, r3
    ands	r1, r6
    adds	r6, r1, #0
    orrs	r6, r0
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #0]
    ldrb	r0, [r5, #0]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #4]
    add	r0, sp, #4
    mov	r2, sp
    cmp	r3, r1
    bls .Lde_0803D496
    adds	r2, r0, #0
.Lde_0803D496:
    ldr	r4, [r2, #0]
    ldr	r0, [r5, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    cmp	r0, #5
    bhi .Lde_0803D50A
    mov	r5, r8
    ldrb	r3, [r5, #0]
    lsls	r0, r3, #25
    lsrs	r2, r0, #27
    cmp	r2, #0
    bne .Lde_0803D4C6
    lsls	r0, r3, #30
    lsrs	r0, r0, #30
    movs	r1, #4
    negs	r1, r1
    subs	r0, #1
    movs	r2, #3
    ands	r0, r2
    ands	r1, r3
    orrs	r1, r0
    strb	r1, [r5, #0]
    movs	r2, #29
    b .Lde_0803D4C8
.Lde_0803D4C6:
    subs	r2, #1
.Lde_0803D4C8:
    movs	r0, #31
    ands	r2, r0
    lsls	r2, r2, #2
    ldrb	r1, [r5, #0]
    movs	r0, #125	@ 0x7d
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r5, #0]
    mov	r0, r8
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #3
    bne .Lde_0803D4F0
    lsls	r0, r1, #25
    lsrs	r0, r0, #27
    cmp	r0, #29
    bne .Lde_0803D4F0
    subs	r4, #1
.Lde_0803D4F0:
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    movs	r1, #6
    cmp	r0, #1
    ble .Lde_0803D4FC
    subs	r1, r0, #1
.Lde_0803D4FC:
    movs	r0, #7
    ands	r1, r0
    movs	r0, #8
    negs	r0, r0
    ands	r0, r6
    adds	r6, r0, #0
    orrs	r6, r1
.Lde_0803D50A:
    strb	r4, [r7, #0]
    mov	r1, r8
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    strb	r0, [r7, #1]
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    strb	r0, [r7, #2]
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    strb	r0, [r7, #3]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803D644
    .thumb_func
func_0803D644:
    push	{r4, lr}
    sub	sp, #8
    lsls	r2, r0, #4
    subs	r2, r2, r0
    lsls	r2, r2, #1
    subs	r2, #1
    adds	r2, r2, r1
    str	r2, [sp, #4]
    ldr r0, .Lde_0803D57C
    adds	r4, r0, #0
    adds	r4, #14
    movs	r1, #0
    str	r1, [sp, #0]
    adds	r1, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080E0E80
    adds	r1, r0, #0
    movs	r2, #0
    cmp	r1, r4
    beq .Lde_0803D572
    ldr	r0, [sp, #4]
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bcc .Lde_0803D572
    movs	r2, #1
.Lde_0803D572:
    adds	r0, r2, #0
    add	sp, #8
    pop	{r4}
    pop	{r1}
    bx	r1
.Lde_0803D57C:
    .4byte gUnk_080F1A66
    .section .text.npc_schedule_after
    .global func_0803DA24
    .thumb_func
func_0803DA24:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803D934
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lde_0803D938
    movs	r0, #0
    b .Lde_0803D96C
.Lde_0803D934:
    .4byte 0x000021CA
.Lde_0803D938:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803D958
    movs	r0, #4
    b .Lde_0803D96C
.Lde_0803D958:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803D96A
    cmp	r4, #2
    bne .Lde_0803D966
    movs	r0, #3
    b .Lde_0803D96C
.Lde_0803D966:
    movs	r0, #1
    b .Lde_0803D96C
.Lde_0803D96A:
    movs	r0, #2
.Lde_0803D96C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DA7C
    .thumb_func
func_0803DA7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803D9C0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lde_0803D98E
    b .Lde_0803DB1A
.Lde_0803D98E:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Lde_0803D9C4
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    cmp	r4, #3
    bne .Lde_0803DA62
    cmp	r7, #2
    bne .Lde_0803D9C8
    mov	r0, r8
    cmp	r0, #13
    bne .Lde_0803D9C8
    movs	r0, #22
    b .Lde_0803DB4C
.Lde_0803D9C0:
    .4byte 0x000021CA
.Lde_0803D9C4:
    .4byte 0x00001CD4
.Lde_0803D9C8:
    ldr r1, .Lde_0803D9DC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803D9E0
    movs	r0, #23
    b .Lde_0803DB4C
    .align 2, 0
.Lde_0803D9DC:
    .4byte 0x0000216B
.Lde_0803D9E0:
    ldr r1, .Lde_0803DA18
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Lde_0803DA1C
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803DA0C
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803DA0C
    cmp	r0, #4
    bne .Lde_0803DA30
.Lde_0803DA0C:
    cmp	r4, #0
    beq .Lde_0803DA24
    cmp	r6, #0
    beq .Lde_0803DA20
    movs	r0, #13
    b .Lde_0803DB4C
.Lde_0803DA18:
    .4byte 0x00002148
.Lde_0803DA1C:
    .4byte 0x00001CD4
.Lde_0803DA20:
    movs	r0, #12
    b .Lde_0803DB4C
.Lde_0803DA24:
    cmp	r6, #0
    beq .Lde_0803DA2C
    movs	r0, #15
    b .Lde_0803DB4C
.Lde_0803DA2C:
    movs	r0, #14
    b .Lde_0803DB4C
.Lde_0803DA30:
    cmp	r6, #0
    beq .Lde_0803DA46
    mov	r0, r9
    cmp	r0, #0
    bne .Lde_0803DA46
    cmp	r4, #0
    beq .Lde_0803DA42
    movs	r0, #8
    b .Lde_0803DB4C
.Lde_0803DA42:
    movs	r0, #11
    b .Lde_0803DB4C
.Lde_0803DA46:
    cmp	r4, #0
    beq .Lde_0803DA56
    cmp	r6, #0
    beq .Lde_0803DA52
    movs	r0, #7
    b .Lde_0803DB4C
.Lde_0803DA52:
    movs	r0, #6
    b .Lde_0803DB4C
.Lde_0803DA56:
    cmp	r6, #0
    beq .Lde_0803DA5E
    movs	r0, #10
    b .Lde_0803DB4C
.Lde_0803DA5E:
    movs	r0, #9
    b .Lde_0803DB4C
.Lde_0803DA62:
    ldr r1, .Lde_0803DA84
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lde_0803DA96
    cmp	r7, #1
    bne .Lde_0803DB1A
    movs	r0, #1
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DA88
    movs	r0, #19
    b .Lde_0803DB4C
.Lde_0803DA84:
    .4byte 0x00001D6C
.Lde_0803DA88:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803DA92
    movs	r0, #20
    b .Lde_0803DB4C
.Lde_0803DA92:
    movs	r0, #21
    b .Lde_0803DB4C
.Lde_0803DA96:
    cmp	r7, #2
    bne .Lde_0803DAB8
    mov	r0, r8
    cmp	r0, #30
    bne .Lde_0803DAB8
    ldr r1, .Lde_0803DAB4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803DAB8
    movs	r0, #17
    b .Lde_0803DB4C
    .align 2, 0
.Lde_0803DAB4:
    .4byte 0x000021A3
.Lde_0803DAB8:
    ldr r1, .Lde_0803DAF0
    adds	r0, r5, r1
    movs	r1, #3
    bl func_080A01F8
    cmp	r7, #3
    bne .Lde_0803DAFC
    mov	r1, r8
    cmp	r1, #14
    bne .Lde_0803DAFC
    cmp	r4, #0
    bne .Lde_0803DAFC
    cmp	r0, #0
    beq .Lde_0803DAFC
    bl GetLove__C12Bachelorette
    ldr r1, .Lde_0803DAF4
    cmp	r0, r1
    bls .Lde_0803DAFC
    ldr r1, .Lde_0803DAF8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803DAFC
    movs	r0, #18
    b .Lde_0803DB4C
.Lde_0803DAF0:
    .4byte 0x00001CD4
.Lde_0803DAF4:
    .4byte 0x0000270F
.Lde_0803DAF8:
    .4byte 0x000021A3
.Lde_0803DAFC:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DB0E
    movs	r0, #16
    b .Lde_0803DB4C
.Lde_0803DB0E:
    ldr r1, .Lde_0803DB20
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lde_0803DB24
.Lde_0803DB1A:
    movs	r0, #0
    b .Lde_0803DB4C
    .align 2, 0
.Lde_0803DB20:
    .4byte 0x0000215A
.Lde_0803DB24:
    mov	r0, r9
    cmp	r0, #0
    bne .Lde_0803DB40
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803DB3C
    cmp	r7, #1
    bne .Lde_0803DB38
    movs	r0, #5
    b .Lde_0803DB4C
.Lde_0803DB38:
    movs	r0, #3
    b .Lde_0803DB4C
.Lde_0803DB3C:
    movs	r0, #4
    b .Lde_0803DB4C
.Lde_0803DB40:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803DB4A
    movs	r0, #2
    b .Lde_0803DB4C
.Lde_0803DB4A:
    movs	r0, #1
.Lde_0803DB4C:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DC64
    .thumb_func
func_0803DC64:
    push	{r4, lr}
    sub	sp, #4
    adds	r2, r0, #0
    ldr r1, .Lde_0803DB74
    adds	r0, r2, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lde_0803DB78
    movs	r0, #0
    b .Lde_0803DBA2
.Lde_0803DB74:
    .4byte 0x000021CA
.Lde_0803DB78:
    mov	r4, sp
    adds	r1, r2, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DB98
    movs	r0, #3
    b .Lde_0803DBA2
.Lde_0803DB98:
    cmp	r4, #0
    beq .Lde_0803DBA0
    movs	r0, #1
    b .Lde_0803DBA2
.Lde_0803DBA0:
    movs	r0, #2
.Lde_0803DBA2:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DCB4
    .thumb_func
func_0803DCB4:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r0, .Lde_0803DBDC
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetChild__C13NpcCollection
    cmp	r0, #0
    bne .Lde_0803DBC2
    b .Lde_0803DCD6
.Lde_0803DBC2:
    bl GetAgeDays__C5Child
    cmp	r0, #59	@ 0x3b
    bls .Lde_0803DBCC
    b .Lde_0803DCD2
.Lde_0803DBCC:
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #31
    bne .Lde_0803DBE0
    movs	r0, #3
    b .Lde_0803DCD8
.Lde_0803DBDC:
    .4byte 0x00001CD4
.Lde_0803DBE0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Lde_0803DBFE
    cmp	r1, #13
    bne .Lde_0803DBFE
    movs	r0, #5
    b .Lde_0803DCD8
.Lde_0803DBFE:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803DCA8
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803DCA8
    cmp	r0, #4
    beq .Lde_0803DCA8
    ldr r1, .Lde_0803DC28
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    subs	r0, r6, #3
    cmp	r0, #28
    bhi .Lde_0803DCCE
    lsls	r0, r0, #2
    ldr r1, .Lde_0803DC2C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_0803DC28:
    .4byte 0x00002148
.Lde_0803DC2C:
    .4byte .Lde_0803DC30
.Lde_0803DC30:
    .4byte .Lde_0803DCAC
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCA4
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCB6
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCC4
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCA
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
    .4byte .Lde_0803DCCE
.Lde_0803DCA4:
    .4byte 0xD1122C01
.Lde_0803DCA8:
    movs	r0, #2
    b .Lde_0803DCD8
.Lde_0803DCAC:
    .4byte 0xD0FB2A00
    .4byte 0xD10C2C00
    .hword 0xE7F8
.Lde_0803DCB6:
    .hword 0x2A00
    .4byte 0x2C02D0F6
    .4byte 0x2C00D0F4
    .4byte 0xE7F1D105
.Lde_0803DCC4:
    .4byte 0xD1022C03
    .hword 0xE7EE
.Lde_0803DCCA:
    .hword 0x2A00
    .hword 0xD0EC
.Lde_0803DCCE:
    movs	r0, #1
    b .Lde_0803DCD8
.Lde_0803DCD2:
    movs	r0, #4
    b .Lde_0803DCD8
.Lde_0803DCD6:
    movs	r0, #0
.Lde_0803DCD8:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803DDE8
    .thumb_func
func_0803DDE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803DD40
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    blt .Lde_0803DD3A
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    mov	r0, sp
    ldrb	r6, [r0, #0]
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Lde_0803DD44
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803DD3A
    subs	r1, #12
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Lde_0803DD48
    cmp	r6, #1
    bhi .Lde_0803DD3A
    cmp	r6, #1
    bne .Lde_0803DD48
    cmp	r7, #3
    bne .Lde_0803DD48
    mov	r0, r8
    cmp	r0, #28
    bls .Lde_0803DD48
.Lde_0803DD3A:
    movs	r0, #0
    b .Lde_0803DDB6
    .align 2, 0
.Lde_0803DD40:
    .4byte 0x000021CA
.Lde_0803DD44:
    .4byte 0x00002181
.Lde_0803DD48:
    ldr r1, .Lde_0803DD5C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803DD60
    movs	r0, #5
    b .Lde_0803DDB6
    .align 2, 0
.Lde_0803DD5C:
    .4byte 0x00002181
.Lde_0803DD60:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DD72
    movs	r0, #4
    b .Lde_0803DDB6
.Lde_0803DD72:
    cmp	r6, #1
    bne .Lde_0803DD94
    cmp	r7, #2
    bne .Lde_0803DD94
    mov	r0, r8
    cmp	r0, #15
    bne .Lde_0803DD94
    ldr r1, .Lde_0803DD90
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803DD94
.Lde_0803DD8C:
    movs	r0, #2
    b .Lde_0803DDB6
.Lde_0803DD90:
    .4byte 0x00002175
.Lde_0803DD94:
    ldr r1, .Lde_0803DDB0
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lde_0803DDB4
    cmp	r4, #6
    bne .Lde_0803DD8C
    movs	r0, #3
    b .Lde_0803DDB6
.Lde_0803DDB0:
    .4byte 0x00002174
.Lde_0803DDB4:
    movs	r0, #1
.Lde_0803DDB6:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DECC
    .thumb_func
func_0803DECC:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803DDE6
    movs	r0, #1
    b .Lde_0803DDE8
.Lde_0803DDE6:
    movs	r0, #2
.Lde_0803DDE8:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DEF8
    .thumb_func
func_0803DEF8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803DE08
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lde_0803DE0C
    movs	r0, #0
    b .Lde_0803DE40
    .align 2, 0
.Lde_0803DE08:
    .4byte 0x000021CA
.Lde_0803DE0C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DE2C
    movs	r0, #4
    b .Lde_0803DE40
.Lde_0803DE2C:
    cmp	r4, #3
    bne .Lde_0803DE3E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803DE3A
    movs	r0, #2
    b .Lde_0803DE40
.Lde_0803DE3A:
    movs	r0, #3
    b .Lde_0803DE40
.Lde_0803DE3E:
    movs	r0, #1
.Lde_0803DE40:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DF50
    .thumb_func
func_0803DF50:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lde_0803DE60
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lde_0803DE64
    movs	r0, #0
    b .Lde_0803DE82
    .align 2, 0
.Lde_0803DE60:
    .4byte 0x000021CA
.Lde_0803DE64:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803DE80
    movs	r0, #1
    b .Lde_0803DE82
.Lde_0803DE80:
    movs	r0, #2
.Lde_0803DE82:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DF94
    .thumb_func
func_0803DF94:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lde_0803DEA4
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lde_0803DEA8
    movs	r0, #0
    b .Lde_0803DED8
    .align 2, 0
.Lde_0803DEA4:
    .4byte 0x000021CA
.Lde_0803DEA8:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803DEC6
    movs	r0, #4
    b .Lde_0803DED8
.Lde_0803DEC6:
    cmp	r4, #2
    bne .Lde_0803DECE
    movs	r0, #2
    b .Lde_0803DED8
.Lde_0803DECE:
    cmp	r4, #0
    beq .Lde_0803DED6
    movs	r0, #1
    b .Lde_0803DED8
.Lde_0803DED6:
    movs	r0, #3
.Lde_0803DED8:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DFE8
    .thumb_func
func_0803DFE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803DF00
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lde_0803DF04
    movs	r0, #0
    b .Lde_0803E08C
    .align 2, 0
.Lde_0803DF00:
    .4byte 0x000021CA
.Lde_0803DF04:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r7, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Lde_0803DF38
    adds	r4, r5, r1
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #19
    bne .Lde_0803DFE2
    mov	r0, r8
    cmp	r0, #2
    bne .Lde_0803DF44
    cmp	r7, #9
    bne .Lde_0803DF3C
    movs	r0, #21
    b .Lde_0803E08C
.Lde_0803DF38:
    .4byte 0x00001CD4
.Lde_0803DF3C:
    cmp	r7, #13
    bne .Lde_0803DF44
    movs	r0, #22
    b .Lde_0803E08C
.Lde_0803DF44:
    ldr r1, .Lde_0803DF58
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803DF5C
    movs	r0, #23
    b .Lde_0803E08C
    .align 2, 0
.Lde_0803DF58:
    .4byte 0x0000216C
.Lde_0803DF5C:
    ldr r1, .Lde_0803DF94
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Lde_0803DF98
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803DF88
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803DF88
    cmp	r0, #4
    bne .Lde_0803DFAC
.Lde_0803DF88:
    cmp	r4, #0
    beq .Lde_0803DFA0
    cmp	r6, #0
    beq .Lde_0803DF9C
    movs	r0, #18
    b .Lde_0803E08C
.Lde_0803DF94:
    .4byte 0x00002148
.Lde_0803DF98:
    .4byte 0x00001CD4
.Lde_0803DF9C:
    movs	r0, #17
    b .Lde_0803E08C
.Lde_0803DFA0:
    cmp	r6, #0
    beq .Lde_0803DFA8
    movs	r0, #20
    b .Lde_0803E08C
.Lde_0803DFA8:
    movs	r0, #19
    b .Lde_0803E08C
.Lde_0803DFAC:
    cmp	r6, #0
    beq .Lde_0803DFC6
    mov	r0, r9
    cmp	r0, #0
    beq .Lde_0803DFBA
    cmp	r0, #2
    bne .Lde_0803DFC6
.Lde_0803DFBA:
    cmp	r4, #0
    beq .Lde_0803DFC2
    movs	r0, #13
    b .Lde_0803E08C
.Lde_0803DFC2:
    movs	r0, #16
    b .Lde_0803E08C
.Lde_0803DFC6:
    cmp	r4, #0
    beq .Lde_0803DFD6
    cmp	r6, #0
    beq .Lde_0803DFD2
    movs	r0, #12
    b .Lde_0803E08C
.Lde_0803DFD2:
    movs	r0, #11
    b .Lde_0803E08C
.Lde_0803DFD6:
    cmp	r6, #0
    beq .Lde_0803DFDE
    movs	r0, #15
    b .Lde_0803E08C
.Lde_0803DFDE:
    movs	r0, #14
    b .Lde_0803E08C
.Lde_0803DFE2:
    ldr r1, .Lde_0803E000
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lde_0803E012
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E004
    movs	r0, #10
    b .Lde_0803E08C
.Lde_0803E000:
    .4byte 0x00001EB8
.Lde_0803E004:
    mov	r0, r9
    cmp	r0, #0
    bne .Lde_0803E00E
    movs	r0, #7
    b .Lde_0803E08C
.Lde_0803E00E:
    movs	r0, #6
    b .Lde_0803E08C
.Lde_0803E012:
    adds	r0, r4, #0
    movs	r1, #19
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Lde_0803E050
    cmp	r7, #14
    bne .Lde_0803E050
    cmp	r6, #0
    bne .Lde_0803E050
    cmp	r0, #0
    beq .Lde_0803E050
    bl GetLove__C12Bachelorette
    ldr r1, .Lde_0803E048
    cmp	r0, r1
    bls .Lde_0803E050
    ldr r1, .Lde_0803E04C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803E050
    movs	r0, #9
    b .Lde_0803E08C
.Lde_0803E048:
    .4byte 0x0000270F
.Lde_0803E04C:
    .4byte 0x000021A4
.Lde_0803E050:
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E062
    movs	r0, #8
    b .Lde_0803E08C
.Lde_0803E062:
    mov	r0, r9
    cmp	r0, #0
    bne .Lde_0803E06C
    movs	r0, #3
    b .Lde_0803E08C
.Lde_0803E06C:
    mov	r1, r9
    cmp	r1, #2
    bne .Lde_0803E080
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E07C
    movs	r0, #4
    b .Lde_0803E08C
.Lde_0803E07C:
    movs	r0, #5
    b .Lde_0803E08C
.Lde_0803E080:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803E08A
    movs	r0, #2
    b .Lde_0803E08C
.Lde_0803E08A:
    movs	r0, #1
.Lde_0803E08C:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E1A4
    .thumb_func
func_0803E1A4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E0B4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lde_0803E0B8
    movs	r0, #0
    b .Lde_0803E0EC
    .align 2, 0
.Lde_0803E0B4:
    .4byte 0x000021CA
.Lde_0803E0B8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E0D8
    movs	r0, #4
    b .Lde_0803E0EC
.Lde_0803E0D8:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E0EA
    cmp	r4, #2
    bne .Lde_0803E0E6
    movs	r0, #3
    b .Lde_0803E0EC
.Lde_0803E0E6:
    movs	r0, #1
    b .Lde_0803E0EC
.Lde_0803E0EA:
    movs	r0, #2
.Lde_0803E0EC:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E1FC
    .thumb_func
func_0803E1FC:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E10C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lde_0803E110
    movs	r0, #0
    b .Lde_0803E152
    .align 2, 0
.Lde_0803E10C:
    .4byte 0x000021CA
.Lde_0803E110:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r4, [r4, #2]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E132
    movs	r0, #2
    b .Lde_0803E152
.Lde_0803E132:
    ldr r1, .Lde_0803E14C
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    cmp	r6, #2
    bne .Lde_0803E150
    cmp	r4, #5
    bne .Lde_0803E150
    cmp	r0, #25
    beq .Lde_0803E150
    movs	r0, #3
    b .Lde_0803E152
    .align 2, 0
.Lde_0803E14C:
    .4byte 0x00001CD4
.Lde_0803E150:
    movs	r0, #1
.Lde_0803E152:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E264
    .thumb_func
func_0803E264:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E178
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lde_0803E17C
    movs	r0, #0
    b .Lde_0803E2F6
.Lde_0803E178:
    .4byte 0x000021CA
.Lde_0803E17C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r6, [r4, #2]
    ldr r1, .Lde_0803E1AC
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    mov	r0, r8
    cmp	r0, #2
    bne .Lde_0803E1B0
    cmp	r6, #5
    bne .Lde_0803E1B0
    cmp	r4, #25
    beq .Lde_0803E1B4
    movs	r0, #5
    b .Lde_0803E2F6
    .align 2, 0
.Lde_0803E1AC:
    .4byte 0x00001CD4
.Lde_0803E1B0:
    cmp	r4, #25
    bne .Lde_0803E25C
.Lde_0803E1B4:
    mov	r1, r8
    cmp	r1, #2
    bne .Lde_0803E1CA
    cmp	r6, #9
    bne .Lde_0803E1C2
    movs	r0, #16
    b .Lde_0803E2F6
.Lde_0803E1C2:
    cmp	r6, #13
    bne .Lde_0803E1CA
    movs	r0, #17
    b .Lde_0803E2F6
.Lde_0803E1CA:
    ldr r1, .Lde_0803E1E8
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Lde_0803E1EC
    movs	r0, #18
    b .Lde_0803E2F6
.Lde_0803E1E8:
    .4byte 0x0000216B
.Lde_0803E1EC:
    ldr r1, .Lde_0803E228
    adds	r0, r5, r1
    ldrb	r4, [r0, #0]
    ldr r1, .Lde_0803E22C
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r7, r1, #31
    mov	r9, r7
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803E21A
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803E21A
    cmp	r0, #4
    bne .Lde_0803E240
.Lde_0803E21A:
    mov	r0, r9
    cmp	r0, #0
    beq .Lde_0803E234
    cmp	r4, #0
    beq .Lde_0803E230
    movs	r0, #13
    b .Lde_0803E2F6
.Lde_0803E228:
    .4byte 0x00002148
.Lde_0803E22C:
    .4byte 0x00001CD4
.Lde_0803E230:
    movs	r0, #12
    b .Lde_0803E2F6
.Lde_0803E234:
    cmp	r4, #0
    beq .Lde_0803E23C
    movs	r0, #15
    b .Lde_0803E2F6
.Lde_0803E23C:
    movs	r0, #14
    b .Lde_0803E2F6
.Lde_0803E240:
    cmp	r7, #0
    beq .Lde_0803E250
    cmp	r4, #0
    beq .Lde_0803E24C
    movs	r0, #9
    b .Lde_0803E2F6
.Lde_0803E24C:
    movs	r0, #8
    b .Lde_0803E2F6
.Lde_0803E250:
    cmp	r4, #0
    beq .Lde_0803E258
    movs	r0, #11
    b .Lde_0803E2F6
.Lde_0803E258:
    movs	r0, #10
    b .Lde_0803E2F6
.Lde_0803E25C:
    ldr r1, .Lde_0803E280
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lde_0803E288
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803E2E6
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E284
    movs	r0, #3
    b .Lde_0803E2F6
.Lde_0803E280:
    .4byte 0x00001F38
.Lde_0803E284:
    movs	r0, #4
    b .Lde_0803E2F6
.Lde_0803E288:
    ldr r1, .Lde_0803E2CC
    adds	r0, r5, r1
    movs	r1, #25
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Lde_0803E2D8
    cmp	r6, #14
    bne .Lde_0803E2D8
    cmp	r4, #0
    bne .Lde_0803E2D8
    cmp	r0, #0
    beq .Lde_0803E2D8
    bl GetLove__C12Bachelorette
    ldr r1, .Lde_0803E2D0
    cmp	r0, r1
    bls .Lde_0803E2D8
    ldr r1, .Lde_0803E2D4
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #2
    beq .Lde_0803E2D8
    movs	r0, #7
    b .Lde_0803E2F6
.Lde_0803E2CC:
    .4byte 0x00001CD4
.Lde_0803E2D0:
    .4byte 0x0000270F
.Lde_0803E2D4:
    .4byte 0x000021A3
.Lde_0803E2D8:
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E2EA
.Lde_0803E2E6:
    movs	r0, #6
    b .Lde_0803E2F6
.Lde_0803E2EA:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803E2F4
    movs	r0, #2
    b .Lde_0803E2F6
.Lde_0803E2F4:
    movs	r0, #1
.Lde_0803E2F6:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    @ ROM-verified DE Thumb code_0803A8A4/code_0803E448
    .section .text.code_0803E448
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803E448
    .thumb_func
func_0803E448:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E358
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803E35C
    movs	r0, #0
    b .Lde_0803E390
    .align 2, 0
.Lde_0803E358:
    .4byte 0x000021CA
.Lde_0803E35C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E37C
    movs	r0, #4
    b .Lde_0803E390
.Lde_0803E37C:
    cmp	r4, #1
    bne .Lde_0803E38E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E38A
    movs	r0, #2
    b .Lde_0803E390
.Lde_0803E38A:
    movs	r0, #3
    b .Lde_0803E390
.Lde_0803E38E:
    movs	r0, #1
.Lde_0803E390:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E4A0
    .thumb_func
func_0803E4A0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E3B4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803E3B8
    movs	r0, #0
    b .Lde_0803E508
.Lde_0803E3B4:
    .4byte 0x000021CA
.Lde_0803E3B8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Lde_0803E3E8
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #12
    bne .Lde_0803E466
    cmp	r7, #2
    bne .Lde_0803E3F4
    cmp	r6, #9
    bne .Lde_0803E3EC
    movs	r0, #16
    b .Lde_0803E508
.Lde_0803E3E8:
    .4byte 0x00001CD4
.Lde_0803E3EC:
    cmp	r6, #13
    bne .Lde_0803E3F4
    movs	r0, #17
    b .Lde_0803E508
.Lde_0803E3F4:
    ldr r1, .Lde_0803E408
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803E40C
    movs	r0, #18
    b .Lde_0803E508
    .align 2, 0
.Lde_0803E408:
    .4byte 0x0000216C
.Lde_0803E40C:
    ldr r1, .Lde_0803E440
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803E434
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803E434
    cmp	r0, #4
    bne .Lde_0803E448
.Lde_0803E434:
    mov	r0, r8
    cmp	r0, #0
    beq .Lde_0803E444
    movs	r0, #14
    b .Lde_0803E508
    .align 2, 0
.Lde_0803E440:
    .4byte 0x00001CD4
.Lde_0803E444:
    movs	r0, #15
    b .Lde_0803E508
.Lde_0803E448:
    mov	r1, r9
    cmp	r1, #1
    bne .Lde_0803E45A
    cmp	r4, #0
    beq .Lde_0803E456
    movs	r0, #11
    b .Lde_0803E508
.Lde_0803E456:
    movs	r0, #13
    b .Lde_0803E508
.Lde_0803E45A:
    cmp	r4, #0
    beq .Lde_0803E462
    movs	r0, #10
    b .Lde_0803E508
.Lde_0803E462:
    movs	r0, #12
    b .Lde_0803E508
.Lde_0803E466:
    ldr r1, .Lde_0803E484
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lde_0803E4A0
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E488
    movs	r0, #9
    b .Lde_0803E508
.Lde_0803E484:
    .4byte 0x00001E28
.Lde_0803E488:
    mov	r0, r9
    cmp	r0, #4
    bne .Lde_0803E49C
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E498
    movs	r0, #5
    b .Lde_0803E508
.Lde_0803E498:
    movs	r0, #6
    b .Lde_0803E508
.Lde_0803E49C:
    movs	r0, #4
    b .Lde_0803E508
.Lde_0803E4A0:
    adds	r0, r4, #0
    movs	r1, #12
    bl func_080A01F8
    cmp	r7, #3
    bne .Lde_0803E4E0
    cmp	r6, #14
    bne .Lde_0803E4E0
    mov	r1, r8
    cmp	r1, #0
    bne .Lde_0803E4E0
    cmp	r0, #0
    beq .Lde_0803E4E0
    bl GetLove__C12Bachelorette
    ldr r1, .Lde_0803E4D8
    cmp	r0, r1
    bls .Lde_0803E4E0
    ldr r1, .Lde_0803E4DC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803E4E0
    movs	r0, #7
    b .Lde_0803E508
    .align 2, 0
.Lde_0803E4D8:
    .4byte 0x0000270F
.Lde_0803E4DC:
    .4byte 0x000021A5
.Lde_0803E4E0:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E4F2
    movs	r0, #8
    b .Lde_0803E508
.Lde_0803E4F2:
    mov	r0, r9
    cmp	r0, #1
    bne .Lde_0803E506
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E502
    movs	r0, #2
    b .Lde_0803E508
.Lde_0803E502:
    movs	r0, #3
    b .Lde_0803E508
.Lde_0803E506:
    movs	r0, #1
.Lde_0803E508:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E620
    .thumb_func
func_0803E620:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E530
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803E534
    movs	r0, #0
    b .Lde_0803E572
    .align 2, 0
.Lde_0803E530:
    .4byte 0x000021CA
.Lde_0803E534:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E554
    movs	r0, #5
    b .Lde_0803E572
.Lde_0803E554:
    cmp	r4, #1
    bne .Lde_0803E566
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E562
    movs	r0, #3
    b .Lde_0803E572
.Lde_0803E562:
    movs	r0, #4
    b .Lde_0803E572
.Lde_0803E566:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803E570
    movs	r0, #2
    b .Lde_0803E572
.Lde_0803E570:
    movs	r0, #1
.Lde_0803E572:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E684
    .thumb_func
func_0803E684:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    adds	r6, r0, #0
    ldrb	r0, [r4, #2]
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E5A8
    movs	r0, #2
    b .Lde_0803E5DA
.Lde_0803E5A8:
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #4]
    ldrb	r0, [r5, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #8]
    add	r2, sp, #8
    add	r0, sp, #4
    cmp	r3, r1
    bls .Lde_0803E5C6
    adds	r0, r2, #0
.Lde_0803E5C6:
    ldr	r0, [r0, #0]
    cmp	r0, #1
    bhi .Lde_0803E5D8
    cmp	r6, #0
    bne .Lde_0803E5D8
    cmp	r4, #2
    bhi .Lde_0803E5D8
    movs	r0, #0
    b .Lde_0803E5DA
.Lde_0803E5D8:
    movs	r0, #1
.Lde_0803E5DA:
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E6EC
    .thumb_func
func_0803E6EC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r3, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #3
    bne .Lde_0803E638
    cmp	r3, #2
    bne .Lde_0803E638
    ldr r1, .Lde_0803E62C
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #134	@ 0x86
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #6
    cmp	r0, r1
    bne .Lde_0803E638
    ldr r1, .Lde_0803E630
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803E634
    movs	r0, #7
    b .Lde_0803E670
    .align 2, 0
.Lde_0803E62C:
    .4byte 0x00002178
.Lde_0803E630:
    .4byte 0x0000217A
.Lde_0803E634:
    movs	r0, #0
    b .Lde_0803E670
.Lde_0803E638:
    adds	r0, r2, #0
    adds	r1, r3, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E64A
    movs	r0, #6
    b .Lde_0803E670
.Lde_0803E64A:
    cmp	r4, #6
    bne .Lde_0803E65C
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E658
    movs	r0, #2
    b .Lde_0803E670
.Lde_0803E658:
    movs	r0, #3
    b .Lde_0803E670
.Lde_0803E65C:
    cmp	r4, #0
    bne .Lde_0803E66E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E66A
    movs	r0, #4
    b .Lde_0803E670
.Lde_0803E66A:
    movs	r0, #5
    b .Lde_0803E670
.Lde_0803E66E:
    movs	r0, #1
.Lde_0803E670:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E780
    .thumb_func
func_0803E780:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E694
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lde_0803E698
    movs	r0, #0
    b .Lde_0803E7D2
.Lde_0803E694:
    .4byte 0x000021CA
.Lde_0803E698:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Lde_0803E6C8
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #21
    bne .Lde_0803E746
    cmp	r7, #2
    bne .Lde_0803E6D4
    cmp	r6, #9
    bne .Lde_0803E6CC
    movs	r0, #14
    b .Lde_0803E7D2
.Lde_0803E6C8:
    .4byte 0x00001CD4
.Lde_0803E6CC:
    cmp	r6, #13
    bne .Lde_0803E6D4
    movs	r0, #15
    b .Lde_0803E7D2
.Lde_0803E6D4:
    ldr r1, .Lde_0803E6E8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lde_0803E6EC
    movs	r0, #16
    b .Lde_0803E7D2
    .align 2, 0
.Lde_0803E6E8:
    .4byte 0x0000216C
.Lde_0803E6EC:
    ldr r1, .Lde_0803E720
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803E714
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lde_0803E714
    cmp	r0, #4
    bne .Lde_0803E728
.Lde_0803E714:
    mov	r0, r8
    cmp	r0, #0
    beq .Lde_0803E724
    movs	r0, #12
    b .Lde_0803E7D2
    .align 2, 0
.Lde_0803E720:
    .4byte 0x00001CD4
.Lde_0803E724:
    movs	r0, #13
    b .Lde_0803E7D2
.Lde_0803E728:
    mov	r1, r9
    cmp	r1, #3
    bne .Lde_0803E73A
    cmp	r4, #0
    beq .Lde_0803E736
    movs	r0, #9
    b .Lde_0803E7D2
.Lde_0803E736:
    movs	r0, #11
    b .Lde_0803E7D2
.Lde_0803E73A:
    cmp	r4, #0
    beq .Lde_0803E742
    movs	r0, #8
    b .Lde_0803E7D2
.Lde_0803E742:
    movs	r0, #10
    b .Lde_0803E7D2
.Lde_0803E746:
    ldr r1, .Lde_0803E764
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lde_0803E776
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E768
    movs	r0, #7
    b .Lde_0803E7D2
.Lde_0803E764:
    .4byte 0x00001EE4
.Lde_0803E768:
    mov	r0, r9
    cmp	r0, #3
    bne .Lde_0803E772
    movs	r0, #4
    b .Lde_0803E7D2
.Lde_0803E772:
    movs	r0, #3
    b .Lde_0803E7D2
.Lde_0803E776:
    adds	r0, r4, #0
    movs	r1, #21
    bl func_080A01F8
    cmp	r7, #3
    bne .Lde_0803E7B4
    cmp	r6, #14
    bne .Lde_0803E7B4
    mov	r1, r8
    cmp	r1, #0
    bne .Lde_0803E7B4
    cmp	r0, #0
    beq .Lde_0803E7B4
    bl GetLove__C12Bachelorette
    ldr r1, .Lde_0803E7AC
    cmp	r0, r1
    bls .Lde_0803E7B4
    ldr r1, .Lde_0803E7B0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803E7B4
    movs	r0, #6
    b .Lde_0803E7D2
.Lde_0803E7AC:
    .4byte 0x0000270F
.Lde_0803E7B0:
    .4byte 0x000021A4
.Lde_0803E7B4:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E7C6
    movs	r0, #5
    b .Lde_0803E7D2
.Lde_0803E7C6:
    mov	r0, r9
    cmp	r0, #3
    beq .Lde_0803E7D0
    movs	r0, #1
    b .Lde_0803E7D2
.Lde_0803E7D0:
    movs	r0, #2
.Lde_0803E7D2:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803E8E8
    .thumb_func
func_0803E8E8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E81C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    blt .Lde_0803E840
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #2
    bne .Lde_0803E824
    cmp	r1, #30
    bne .Lde_0803E824
    ldr r3, .Lde_0803E820
    adds	r0, r5, r3
    ldrb	r0, [r0, #0]
    lsrs	r0, r0, #6
    cmp	r0, #2
    beq .Lde_0803E824
    movs	r0, #5
    b .Lde_0803E860
.Lde_0803E81C:
    .4byte 0x000021CA
.Lde_0803E820:
    .4byte 0x000021A2
.Lde_0803E824:
    adds	r0, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E834
    movs	r0, #4
    b .Lde_0803E860
.Lde_0803E834:
    ldr r1, .Lde_0803E844
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lde_0803E848
.Lde_0803E840:
    movs	r0, #0
    b .Lde_0803E860
.Lde_0803E844:
    .4byte 0x0000215A
.Lde_0803E848:
    cmp	r4, #1
    beq .Lde_0803E850
    cmp	r4, #3
    bne .Lde_0803E854
.Lde_0803E850:
    movs	r0, #3
    b .Lde_0803E860
.Lde_0803E854:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803E85E
    movs	r0, #2
    b .Lde_0803E860
.Lde_0803E85E:
    movs	r0, #1
.Lde_0803E860:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E970
    .thumb_func
func_0803E970:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    adds	r6, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E890
    movs	r0, #5
    b .Lde_0803E8D2
.Lde_0803E890:
    ldr r1, .Lde_0803E8A0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lde_0803E8A4
    movs	r0, #0
    b .Lde_0803E8D2
.Lde_0803E8A0:
    .4byte 0x000021CA
.Lde_0803E8A4:
    ldr r1, .Lde_0803E8C0
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lde_0803E8C8
    cmp	r4, #6
    bne .Lde_0803E8C4
    movs	r0, #4
    b .Lde_0803E8D2
.Lde_0803E8C0:
    .4byte 0x00002174
.Lde_0803E8C4:
    movs	r0, #3
    b .Lde_0803E8D2
.Lde_0803E8C8:
    cmp	r6, #6
    beq .Lde_0803E8D0
    movs	r0, #1
    b .Lde_0803E8D2
.Lde_0803E8D0:
    movs	r0, #2
.Lde_0803E8D2:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E9E4
    .thumb_func
func_0803E9E4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r2, [r4, #3]
    adds	r4, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803E904
    movs	r0, #5
    b .Lde_0803E94A
.Lde_0803E904:
    ldr r1, .Lde_0803E914
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lde_0803E918
    movs	r0, #0
    b .Lde_0803E94A
.Lde_0803E914:
    .4byte 0x000021CA
.Lde_0803E918:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803E948
    cmp	r4, #6
    bne .Lde_0803E944
    ldr r1, .Lde_0803E93C
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lde_0803E940
    movs	r0, #4
    b .Lde_0803E94A
    .align 2, 0
.Lde_0803E93C:
    .4byte 0x00002174
.Lde_0803E940:
    movs	r0, #3
    b .Lde_0803E94A
.Lde_0803E944:
    movs	r0, #1
    b .Lde_0803E94A
.Lde_0803E948:
    movs	r0, #2
.Lde_0803E94A:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .section .text.npc_schedule_van_after, "ax", %progbits
    .align 2, 0
    .global func_0803EA98
    .thumb_func
func_0803EA98:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lde_0803E9A8
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lde_0803E9AC
    movs	r0, #0
    b .Lde_0803E9CA
    .align 2, 0
.Lde_0803E9A8:
    .4byte 0x000021CA
.Lde_0803E9AC:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803E9C8
    movs	r0, #1
    b .Lde_0803E9CA
.Lde_0803E9C8:
    movs	r0, #2
.Lde_0803E9CA:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EADC
    .thumb_func
func_0803EADC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803E9EC
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #124	@ 0x7c
    ands	r0, r1
    cmp	r0, #0
    beq .Lde_0803E9F0
    movs	r0, #0
    b .Lde_0803EA30
.Lde_0803E9EC:
    .4byte 0x000021CA
.Lde_0803E9F0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Lde_0803EA0E
    cmp	r1, #3
    bne .Lde_0803EA0E
    movs	r0, #9
    b .Lde_0803EA30
.Lde_0803EA0E:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EA1C
    movs	r0, #8
    b .Lde_0803EA30
.Lde_0803EA1C:
    cmp	r4, #1
    beq .Lde_0803EA2A
    cmp	r4, #3
    beq .Lde_0803EA2A
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lde_0803EA2E
.Lde_0803EA2A:
    movs	r0, #1
    b .Lde_0803EA30
.Lde_0803EA2E:
    movs	r0, #2
.Lde_0803EA30:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB40
    .thumb_func
func_0803EB40:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803EA70
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    blt .Lde_0803EA8A
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #1
    bne .Lde_0803EA8A
    movs	r0, #1
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EA74
    movs	r0, #4
    b .Lde_0803EA8C
.Lde_0803EA70:
    .4byte 0x000021CA
.Lde_0803EA74:
    cmp	r4, #0
    bne .Lde_0803EA86
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803EA82
    movs	r0, #2
    b .Lde_0803EA8C
.Lde_0803EA82:
    movs	r0, #3
    b .Lde_0803EA8C
.Lde_0803EA86:
    movs	r0, #1
    b .Lde_0803EA8C
.Lde_0803EA8A:
    movs	r0, #0
.Lde_0803EA8C:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB9C
    .thumb_func
func_0803EB9C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803EAB0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803EAB4
    movs	r0, #0
    b .Lde_0803EB2E
    .align 2, 0
.Lde_0803EAB0:
    .4byte 0x000021CA
.Lde_0803EAB4:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Lde_0803EAE8
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    adds	r7, r0, #0
    cmp	r7, #4
    bls .Lde_0803EB02
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EAEC
    movs	r0, #9
    b .Lde_0803EB2E
.Lde_0803EAE8:
    .4byte 0x00001E28
.Lde_0803EAEC:
    cmp	r4, #4
    bne .Lde_0803EAFE
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803EAFA
    movs	r0, #6
    b .Lde_0803EB2E
.Lde_0803EAFA:
    movs	r0, #7
    b .Lde_0803EB2E
.Lde_0803EAFE:
    movs	r0, #5
    b .Lde_0803EB2E
.Lde_0803EB02:
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EB14
    movs	r0, #8
    b .Lde_0803EB2E
.Lde_0803EB14:
    cmp	r7, #0
    beq .Lde_0803EB2C
    cmp	r4, #1
    bne .Lde_0803EB20
    movs	r0, #3
    b .Lde_0803EB2E
.Lde_0803EB20:
    cmp	r4, #4
    bne .Lde_0803EB28
    movs	r0, #4
    b .Lde_0803EB2E
.Lde_0803EB28:
    movs	r0, #2
    b .Lde_0803EB2E
.Lde_0803EB2C:
    movs	r0, #1
.Lde_0803EB2E:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EC44
    .thumb_func
func_0803EC44:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lde_0803EB54
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lde_0803EB58
    movs	r0, #0
    b .Lde_0803EBB0
    .align 2, 0
.Lde_0803EB54:
    .4byte 0x000021CA
.Lde_0803EB58:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EB78
    movs	r0, #4
    b .Lde_0803EBB0
.Lde_0803EB78:
    ldr r0, .Lde_0803EB98
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetOrder__C7Saibara
    cmp	r0, #0
    beq .Lde_0803EB9C
    adds	r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803EB9C
    movs	r0, #5
    b .Lde_0803EBB0
    .align 2, 0
.Lde_0803EB98:
    .4byte 0x00001DAC
.Lde_0803EB9C:
    cmp	r6, #4
    bne .Lde_0803EBAE
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803EBAA
    movs	r0, #2
    b .Lde_0803EBB0
.Lde_0803EBAA:
    movs	r0, #3
    b .Lde_0803EBB0
.Lde_0803EBAE:
    movs	r0, #1
.Lde_0803EBB0:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803ECC0
    .thumb_func
func_0803ECC0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803EBDE
    movs	r0, #5
    b .Lde_0803ECBC
.Lde_0803EBDE:
    ldr	r7, [r5, #8]
    ldr r0, .Lde_0803EC20
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #0
    beq .Lde_0803EC9C
    adds	r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803EC9C
    adds	r0, r4, #0
    bl IsConstructionOrderedToday__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lde_0803EC9C
    subs	r0, r7, #3
    cmp	r0, #1
    bls .Lde_0803EC9C
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #13
    bhi .Lde_0803EC9C
    lsls	r0, r0, #2
    ldr r1, .Lde_0803EC24
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lde_0803EC20:
    .4byte 0x00001F64
.Lde_0803EC24:
    .4byte .Lde_0803EC28
.Lde_0803EC28:
    .4byte .Lde_0803EC9C
    .4byte .Lde_0803EC60
    .4byte .Lde_0803EC84
    .4byte .Lde_0803EC88
    .4byte .Lde_0803EC8C
    .4byte .Lde_0803EC90
    .4byte .Lde_0803EC90
    .4byte .Lde_0803EC90
    .4byte .Lde_0803EC94
    .4byte .Lde_0803EC94
    .4byte .Lde_0803EC94
    .4byte .Lde_0803EC98
    .4byte .Lde_0803EC98
    .4byte .Lde_0803EC98
.Lde_0803EC60:
    .4byte 0x004921FA
    .4byte 0xF7CD1868
    .4byte 0x2801F965
    .4byte 0x2801D006
    .4byte 0x2802D302
    .4byte 0xE011D004
    .4byte 0xE01F2006
    .4byte 0xE01D2007
    .4byte 0xE01B200D
.Lde_0803EC84:
    .4byte 0xE0192008
.Lde_0803EC88:
    .4byte 0xE0172009
.Lde_0803EC8C:
    .4byte 0xE015200E
.Lde_0803EC90:
    .4byte 0xE013200A
.Lde_0803EC94:
    .4byte 0xE011200B
.Lde_0803EC98:
    .4byte 0xE00F200C
.Lde_0803EC9C:
    cmp	r6, #5
    bgt .Lde_0803ECAA
    cmp	r6, #4
    bge .Lde_0803ECB2
    cmp	r6, #0
    beq .Lde_0803ECBA
    b .Lde_0803ECAE
.Lde_0803ECAA:
    cmp	r6, #6
    beq .Lde_0803ECB6
.Lde_0803ECAE:
    movs	r0, #1
    b .Lde_0803ECBC
.Lde_0803ECB2:
    movs	r0, #2
    b .Lde_0803ECBC
.Lde_0803ECB6:
    movs	r0, #3
    b .Lde_0803ECBC
.Lde_0803ECBA:
    movs	r0, #4
.Lde_0803ECBC:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EDCC
    .thumb_func
func_0803EDCC:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    adds	r7, r0, #0
    ldrb	r4, [r4, #3]
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803ECF0
    movs	r0, #5
    b .Lde_0803ED40
.Lde_0803ECF0:
    cmp	r6, #2
    bne .Lde_0803ED10
    cmp	r7, #30
    bne .Lde_0803ED10
    ldr r1, .Lde_0803ED0C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lde_0803ED10
    movs	r0, #6
    b .Lde_0803ED40
    .align 2, 0
.Lde_0803ED0C:
    .4byte 0x000021A2
.Lde_0803ED10:
    ldr r1, .Lde_0803ED20
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lde_0803ED24
    movs	r0, #0
    b .Lde_0803ED40
.Lde_0803ED20:
    .4byte 0x0000215A
.Lde_0803ED24:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803ED3E
    cmp	r4, #1
    bne .Lde_0803ED32
    movs	r0, #1
    b .Lde_0803ED40
.Lde_0803ED32:
    cmp	r4, #3
    bne .Lde_0803ED3A
    movs	r0, #2
    b .Lde_0803ED40
.Lde_0803ED3A:
    movs	r0, #3
    b .Lde_0803ED40
.Lde_0803ED3E:
    movs	r0, #4
.Lde_0803ED40:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EE50
    .thumb_func
func_0803EE50:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lde_0803ED6E
    movs	r0, #4
    b .Lde_0803ED82
.Lde_0803ED6E:
    cmp	r4, #1
    bne .Lde_0803ED80
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lde_0803ED7C
    movs	r0, #2
    b .Lde_0803ED82
.Lde_0803ED7C:
    movs	r0, #3
    b .Lde_0803ED82
.Lde_0803ED80:
    movs	r0, #1
.Lde_0803ED82:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .else
    @ ROM-verified US Thumb code_0803A8A4/main
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .section .text.ui_text_window_native, "ax", %progbits
    .align 2, 0
    .global __12UiTextWindowiiUiUiUiUiUiUi
    .thumb_func
__12UiTextWindowiiUiUiUiUiUiUi:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    mov	ip, r0
    ldr	r0, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #48]	@ 0x30
    ldr	r4, [sp, #52]	@ 0x34
    ldr	r6, [sp, #56]	@ 0x38
    movs	r7, #0
    mov	r9, r7
    mov	r7, ip
    strh	r1, [r7, #0]
    strh	r2, [r7, #2]
    strh	r3, [r7, #4]
    strh	r0, [r7, #6]
    movs	r0, #3
    ands	r5, r0
    ldrb	r0, [r7, #8]
    movs	r1, #4
    negs	r1, r1
    mov	r8, r1
    mov	r2, r8
    ands	r2, r0
    orrs	r2, r5
    adds	r0, r4, #0
    movs	r7, #31
    ands	r0, r7
    lsls	r0, r0, #2
    subs	r1, #121	@ 0x79
    ands	r2, r1
    orrs	r2, r0
    mov	r8, r2
    mov	r0, ip
    strb	r2, [r0, #8]
    lsrs	r1, r4, #3
    movs	r0, #3
    ands	r1, r0
    lsls	r1, r1, #7
    mov	r2, ip
    ldrh	r0, [r2, #8]
    ldr r3, .Lus_0803BA7C
    ands	r3, r0
    orrs	r3, r1
    strh	r3, [r2, #8]
    movs	r0, #7
    ands	r4, r0
    lsls	r4, r4, #6
    adds	r4, #20
    ldr r7, .Lus_0803BA80
    str	r7, [sp, #0]
    lsls	r4, r4, #9
    ldr	r5, [r2, #8]
    ldr r0, .Lus_0803BA84
    ands	r5, r0
    orrs	r5, r4
    str	r5, [r2, #8]
    movs	r0, #15
    ands	r6, r0
    lsls	r6, r6, #3
    ldrb	r0, [r2, #10]
    movs	r1, #121	@ 0x79
    negs	r1, r1
    mov	sl, r1
    mov	r2, sl
    ands	r2, r0
    orrs	r2, r6
    mov	sl, r2
    mov	r6, ip
    strb	r2, [r6, #10]
    movs	r0, #255	@ 0xff
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r0
    lsls	r1, r1, #7
    ldrh	r2, [r6, #10]
    ldr r0, .Lus_0803BA88
    ands	r0, r2
    orrs	r0, r1
    strh	r0, [r6, #10]
    ldrb	r1, [r6, #11]
    movs	r0, #127	@ 0x7f
    ands	r0, r1
    strb	r0, [r6, #11]
    ldrb	r1, [r6, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r6, #12]
    movs	r7, #0
    strb	r7, [r6, #13]
    mov	r2, ip
    adds	r2, #16
    mov	r0, r9
    str	r0, [r6, #16]
    str	r0, [r2, #4]
    ldr r0, .Lus_0803BA8C
    str	r0, [r2, #8]
    adds	r1, r2, #0
    adds	r1, #16
    str	r1, [r2, #12]
    mov	r6, r9
    str	r6, [r1, #4]
    ldr r0, .Lus_0803BA90
    str	r0, [r1, #8]
    mov	r0, ip
    adds	r0, #28
    str	r0, [r2, #16]
    str	r1, [r2, #20]
    lsls	r3, r3, #23
    lsrs	r3, r3, #30
    lsls	r5, r5, #13
    lsrs	r7, r5, #22
    lsls	r3, r3, #9
    adds	r2, r3, r7
    ldr r0, .Lus_0803BA94
    ldr	r0, [r0, #0]
    lsrs	r5, r0, #5
    movs	r4, #0
    ldr	r0, [sp, #60]	@ 0x3c
    cmp	r0, #1
    bne .Lus_0803B9C4
    movs	r4, #1
.Lus_0803B9C4:
    mov	r1, ip
    adds	r1, #44	@ 0x2c
    ldr r0, .Lus_0803BA98
    ldr	r3, [r0, #0]
    lsls	r2, r2, #5
    movs	r0, #192	@ 0xc0
    lsls	r0, r0, #19
    adds	r2, r2, r0
    mov	r6, r9
    mov	r0, ip
    str	r6, [r0, #44]	@ 0x2c
    str	r6, [r1, #4]
    ldr r0, .Lus_0803BA9C
    str	r0, [r1, #8]
    str	r3, [r1, #12]
    str	r2, [r1, #16]
    strb	r5, [r1, #20]
    strb	r4, [r1, #21]
    movs	r2, #0
    strb	r2, [r1, #22]
    mov	r6, ip
    movs	r1, #0
    ldrsh	r0, [r6, r1]
    cmp	r0, #0
    bge .Lus_0803B9F8
    adds	r0, #7
.Lus_0803B9F8:
    asrs	r0, r0, #3
    str	r0, [sp, #4]
    mov	r2, ip
    movs	r0, #2
    ldrsh	r6, [r2, r0]
    cmp	r6, #0
    bge .Lus_0803BA08
    adds	r6, #7
.Lus_0803BA08:
    asrs	r6, r6, #3
    str	r6, [sp, #8]
    mov	r1, ip
    ldrh	r4, [r1, #4]
    lsrs	r4, r4, #3
    ldrh	r1, [r1, #6]
    lsrs	r1, r1, #3
    mov	r2, r8
    lsls	r3, r2, #25
    lsrs	r3, r3, #27
    mov	r6, sl
    lsls	r5, r6, #25
    mov	r2, ip
    adds	r2, #68	@ 0x44
    mov	r0, r9
    mov	r6, ip
    str	r0, [r6, #68]	@ 0x44
    str	r0, [r2, #4]
    ldr r0, .Lus_0803BAA0
    str	r0, [r2, #8]
    ldr	r0, [sp, #4]
    str	r0, [r2, #12]
    ldr	r6, [sp, #8]
    str	r6, [r2, #16]
    str	r4, [r2, #20]
    str	r1, [r2, #24]
    movs	r0, #31
    ands	r3, r0
    ldrb	r1, [r2, #28]
    subs	r0, #63	@ 0x3f
    ands	r0, r1
    orrs	r0, r3
    strb	r0, [r2, #28]
    ldr	r1, [sp, #0]
    ands	r7, r1
    lsls	r3, r7, #5
    ldrh	r1, [r2, #28]
    ldr r0, .Lus_0803BAA4
    ands	r0, r1
    orrs	r0, r3
    strh	r0, [r2, #28]
    lsrs	r5, r5, #28
    lsls	r5, r5, #15
    ldr	r0, [r2, #28]
    ldr r1, .Lus_0803BAA8
    ands	r0, r1
    orrs	r0, r5
    str	r0, [r2, #28]
    mov	r0, ip
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lus_0803BA7C:
    .4byte 0xFFFFFE7F
.Lus_0803BA80:
    .4byte 0x000003FF
.Lus_0803BA84:
    .4byte 0xFFF801FF
.Lus_0803BA88:
    .4byte 0xFFFF807F
.Lus_0803BA8C:
    .4byte __vt_18HardwareLinkedList
.Lus_0803BA90:
    .4byte __vt_12HardwareLink
.Lus_0803BA94:
    .4byte gUiSharedTileByteCount
.Lus_0803BA98:
    .4byte gUiSharedTiles
.Lus_0803BA9C:
    .4byte __vt_29UiTextWindowTileUploadCommand
.Lus_0803BAA0:
    .4byte __vt_25UiTextWindowBorderCommand
.Lus_0803BAA4:
    .4byte 0xFFFF801F
.Lus_0803BAA8:
    .4byte 0xFFF87FFF
    .global Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2
    .thumb_func
Update__12UiTextWindowP20HardwareDisplayStateP18HardwareLinkedListT2:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #8
    adds	r7, r0, #0
    mov	r9, r1
    adds	r4, r2, #0
    mov	sl, r3
    ldrb	r2, [r7, #11]
    lsrs	r1, r2, #7
    ldrb	r0, [r7, #12]
    movs	r3, #127	@ 0x7f
    ands	r0, r3
    lsls	r0, r0, #1
    orrs	r0, r1
    cmp	r0, #1
    beq .Lus_0803BADC
    cmp	r0, #1
    ble .Lus_0803BB18
    cmp	r0, #2
    beq .Lus_0803BAFC
    b .Lus_0803BB18
.Lus_0803BADC:
    ldrb	r0, [r7, #13]
    cmp	r0, #8
    bls .Lus_0803BAF8
    movs	r0, #128	@ 0x80
    orrs	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    movs	r1, #1
    orrs	r0, r1
    strb	r0, [r7, #12]
    b .Lus_0803BB18
.Lus_0803BAF8:
    adds	r0, #1
    b .Lus_0803BB16
.Lus_0803BAFC:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    bne .Lus_0803BB14
    adds	r0, r3, #0
    ands	r0, r2
    strb	r0, [r7, #11]
    ldrb	r1, [r7, #12]
    movs	r0, #128	@ 0x80
    negs	r0, r0
    ands	r0, r1
    strb	r0, [r7, #12]
    b .Lus_0803BB18
.Lus_0803BB14:
    subs	r0, #1
.Lus_0803BB16:
    strb	r0, [r7, #13]
.Lus_0803BB18:
    adds	r3, r7, #0
    adds	r3, #16
    movs	r2, #0
    adds	r1, r3, #0
    adds	r1, #16
    ldr	r0, [r3, #12]
    cmp	r0, r1
    bne .Lus_0803BB2A
    movs	r2, #1
.Lus_0803BB2A:
    cmp	r2, #0
    bne .Lus_0803BB3A
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #28]
    adds	r0, r4, #0
    adds	r1, r3, #0
    bl _call_via_r2
.Lus_0803BB3A:
    ldrb	r0, [r7, #11]
    lsrs	r0, r0, #7
    ldrb	r1, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r1, r2
    lsls	r1, r1, #1
    orrs	r1, r0
    cmp	r1, #0
    bne .Lus_0803BB4E
    b .Lus_0803BCA8
.Lus_0803BB4E:
    movs	r0, #0
    mov	r8, r0
    ldrb	r4, [r7, #8]
    lsls	r2, r4, #30
    lsrs	r2, r2, #30
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #1
    lsls	r0, r2
    movs	r3, #128	@ 0x80
    lsls	r3, r3, #6
    adds	r1, r3, #0
    orrs	r0, r1
    mov	r5, r9
    ldrh	r1, [r5, #0]
    orrs	r0, r1
    strh	r0, [r5, #0]
    lsls	r3, r2, #1
    lsls	r2, r2, #2
    mov	r5, sp
    ldrh	r1, [r7, #8]
    lsls	r1, r1, #23
    lsrs	r1, r1, #30
    lsls	r1, r1, #2
    lsls	r0, r4, #25
    lsrs	r0, r0, #27
    lsls	r0, r0, #8
    orrs	r1, r0
    movs	r0, #64	@ 0x40
    orrs	r1, r0
    strh	r1, [r5, #0]
    adds	r3, #8
    add	r3, r9
    strh	r1, [r3, #0]
    mov	r0, sp
    mov	r1, r8
    strh	r1, [r0, #0]
    adds	r0, r2, #0
    adds	r0, #16
    add	r0, r9
    strh	r1, [r0, #0]
    mov	r1, sp
    ldrh	r5, [r7, #2]
    negs	r0, r5
    strh	r0, [r1, #0]
    adds	r2, #18
    add	r2, r9
    strh	r0, [r2, #0]
    ldrb	r6, [r7, #13]
    strb	r4, [r1, #4]
    cmp	r6, #8
    bls .Lus_0803BBDC
    mov	r3, sp
    ldrh	r0, [r7, #0]
    lsls	r2, r0, #8
    ldrh	r1, [r7, #4]
    adds	r0, r0, r1
    orrs	r2, r0
    strh	r2, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r2, [r0, #0]
    mov	r2, sp
    lsls	r1, r5, #8
    ldrh	r0, [r7, #6]
    adds	r0, r5, r0
    orrs	r1, r0
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #68	@ 0x44
    strh	r1, [r0, #0]
    b .Lus_0803BC44
.Lus_0803BBDC:
    ldrh	r4, [r7, #6]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    mov	r8, r0
    movs	r2, #2
    ldrsh	r5, [r7, r2]
    adds	r4, r5, r4
    adds	r5, r5, r4
    lsrs	r0, r5, #31
    adds	r5, r5, r0
    asrs	r5, r5, #1
    mov	r3, r8
    lsrs	r0, r3, #31
    add	r0, r8
    asrs	r0, r0, #1
    subs	r5, r5, r0
    ldrh	r4, [r7, #4]
    adds	r0, r4, #0
    muls	r0, r6
    movs	r1, #9
    bl __udivsi3
    movs	r1, #0
    ldrsh	r2, [r7, r1]
    adds	r4, r2, r4
    adds	r2, r2, r4
    lsrs	r1, r2, #31
    adds	r2, r2, r1
    asrs	r2, r2, #1
    lsrs	r1, r0, #31
    adds	r1, r0, r1
    asrs	r1, r1, #1
    subs	r2, r2, r1
    mov	r3, sp
    lsls	r1, r2, #8
    adds	r2, r2, r0
    orrs	r1, r2
    strh	r1, [r3, #0]
    mov	r0, r9
    adds	r0, #64	@ 0x40
    strh	r1, [r0, #0]
    mov	r1, sp
    lsls	r0, r5, #8
    add	r5, r8
    orrs	r0, r5
    strh	r0, [r1, #0]
    mov	r1, r9
    adds	r1, #68	@ 0x44
    strh	r0, [r1, #0]
.Lus_0803BC44:
    mov	r0, sp
    movs	r1, #63	@ 0x3f
    strh	r1, [r0, #0]
    mov	r3, r9
    adds	r3, #72	@ 0x48
    strh	r1, [r3, #0]
    mov	r2, sp
    ldrb	r4, [r2, #4]
    lsls	r0, r4, #30
    lsrs	r0, r0, #30
    movs	r4, #1
    lsls	r4, r0
    bics	r1, r4
    strh	r1, [r2, #0]
    mov	r0, r9
    adds	r0, #74	@ 0x4a
    strh	r1, [r0, #0]
    ldrh	r0, [r7, #10]
    lsls	r0, r0, #17
    lsrs	r2, r0, #24
    cmp	r2, #2
    bne .Lus_0803BC80
    ldrh	r0, [r3, #0]
    movs	r1, #32
    orrs	r0, r1
    strh	r0, [r3, #0]
    ldr r0, .Lus_0803BCA4
    orrs	r4, r0
    mov	r5, r9
    str	r4, [r5, #80]	@ 0x50
.Lus_0803BC80:
    cmp	r2, #1
    bne .Lus_0803BCD8
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    blt .Lus_0803BCD8
    mov	r1, sl
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
    b .Lus_0803BCD8
    .align 2, 0
.Lus_0803BCA4:
    .4byte 0x08083F40
.Lus_0803BCA8:
    ldrb	r0, [r7, #8]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #1
    lsls	r1, r0
    mov	r2, r9
    ldrh	r0, [r2, #0]
    bics	r0, r1
    strh	r0, [r2, #0]
    adds	r3, r7, #0
    adds	r3, #44	@ 0x2c
    ldr	r1, [r7, #44]	@ 0x2c
    negs	r0, r1
    orrs	r0, r1
    cmp	r0, #0
    bge .Lus_0803BCD8
    mov	r4, sl
    ldr	r0, [r4, #8]
    ldr	r2, [r0, #20]
    mov	r0, sl
    adds	r1, r3, #0
    bl _call_via_r2
.Lus_0803BCD8:
    ldrb	r1, [r7, #11]
    lsrs	r1, r1, #7
    ldrb	r0, [r7, #12]
    movs	r2, #127	@ 0x7f
    ands	r0, r2
    lsls	r0, r0, #1
    orrs	r0, r1
    add	sp, #8
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    @ Remaining control-widget code after the recovered border constructor.
    .section .text.main_menu_widget_update_impl, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0
    .global UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot
    .thumb_func
UpdateImpl__14MainMenuWidgetP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListT4P23HardwareMusicPlayerSlot:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #116	@ 0x74
    adds	r7, r0, #0
    adds	r4, r1, #0
    str	r2, [sp, #68]	@ 0x44
    adds	r1, r3, #0
    ldr	r3, [sp, #152]	@ 0x98
    ldr	r5, [sp, #156]	@ 0x9c
    ldr	r2, [sp, #148]	@ 0x94
    bl Update__13ControlWidgetP20HardwareDisplayStateP18HardwareLinkedListT2
    str	r0, [sp, #72]	@ 0x48
    cmp	r0, #0
    bge .Lus_0803C04E
    b .Lus_0803C506
.Lus_0803C04E:
    cmp	r0, #2
    bgt .Lus_0803C054
    b .Lus_0803C506
.Lus_0803C054:
    cmp	r0, #3
    beq .Lus_0803C05A
    b .Lus_0803C506
.Lus_0803C05A:
    movs	r0, #0
    str	r0, [sp, #76]	@ 0x4c
    ldrb	r0, [r7, #15]
    cmp	r0, #0
    beq .Lus_0803C0DC
    ldrh	r3, [r4, #8]
    adds	r2, r3, #0
    lsls	r1, r2, #26
    lsrs	r1, r1, #31
    lsls	r0, r2, #27
    lsrs	r0, r0, #31
    orrs	r1, r0
    cmp	r1, #0
    beq .Lus_0803C0C8
    movs	r0, #32
    ands	r0, r2
    cmp	r0, #0
    beq .Lus_0803C08C
    ldrb	r0, [r7, #12]
    cmp	r0, #0
    bne .Lus_0803C088
    movs	r0, #6
    b .Lus_0803C0A4
.Lus_0803C088:
    subs	r0, #1
    b .Lus_0803C0A4
.Lus_0803C08C:
    movs	r0, #16
    ands	r2, r0
    cmp	r2, #0
    beq .Lus_0803C0A6
    ldrb	r0, [r7, #12]
    cmp	r0, #6
    bne .Lus_0803C0A2
    add	r1, sp, #76	@ 0x4c
    ldrb	r1, [r1, #0]
    strb	r1, [r7, #12]
    b .Lus_0803C0A6
.Lus_0803C0A2:
    adds	r0, #1
.Lus_0803C0A4:
    strb	r0, [r7, #12]
.Lus_0803C0A6:
    cmp	r5, #0
    beq .Lus_0803C0B2
    adds	r0, r5, #0
    movs	r1, #203	@ 0xcb
    bl Start__23HardwareMusicPlayerSlotUs
.Lus_0803C0B2:
    ldr r0, .Lus_0803C0C4
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #2
    adds	r1, r1, r0
    ldr	r1, [r1, #0]
    str	r1, [sp, #76]	@ 0x4c
    movs	r0, #20
    strb	r0, [r7, #14]
    b .Lus_0803C0DC
.Lus_0803C0C4:
    .4byte gMenuEntryLabels
.Lus_0803C0C8:
    movs	r0, #1
    ands	r3, r0
    cmp	r3, #0
    beq .Lus_0803C0DC
    cmp	r5, #0
    beq .Lus_0803C0DC
    adds	r0, r5, #0
    movs	r1, #197	@ 0xc5
    bl Start__23HardwareMusicPlayerSlotUs
.Lus_0803C0DC:
    ldrb	r0, [r7, #13]
    cmp	r0, #0
    beq .Lus_0803C142
    ldr	r4, [r7, #8]
    ldr	r0, [r4, #80]	@ 0x50
    ldr	r1, [r0, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r0, #44]	@ 0x2c
    lsls	r2, r2, #2
    ldr	r0, [r0, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    ldr	r5, [sp, #20]
    adds	r0, r4, #0
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r2, r0, #0
    add	r1, sp, #20
    ldr	r0, [sp, #20]
    movs	r3, #0
    cmp	r0, #0
    beq .Lus_0803C116
    ldrh	r3, [r1, #4]
.Lus_0803C116:
    adds	r1, r4, #0
    adds	r1, #56	@ 0x38
    lsls	r0, r2, #5
    ldr r2, .Lus_0803C4D0
    adds	r0, r0, r2
    str	r5, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
    ldr r1, .Lus_0803C4D4
    ldrb	r0, [r7, #12]
    lsls	r0, r0, #2
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    str	r0, [sp, #76]	@ 0x4c
    movs	r0, #0
    strb	r0, [r7, #13]
.Lus_0803C142:
    ldrb	r0, [r7, #14]
    subs	r0, #1
    strb	r0, [r7, #14]
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803C152
    movs	r0, #40	@ 0x28
    strb	r0, [r7, #14]
.Lus_0803C152:
    ldrb	r0, [r7, #14]
    cmp	r0, #19
    bhi .Lus_0803C24E
    ldr	r0, [r7, #8]
    ldrb	r1, [r7, #12]
    lsls	r1, r1, #4
    adds	r1, #16
    mov	r8, r1
    ldr	r4, [r0, #80]	@ 0x50
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r9, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Lus_0803C1CE
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Lus_0803C1B2
    ldrh	r3, [r1, #4]
.Lus_0803C1B2:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r5, .Lus_0803C4D8
    adds	r0, r0, r5
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r2, [sp, #148]	@ 0x94
    ldr	r0, [r2, #8]
    ldr	r2, [r0, #16]
    ldr	r0, [sp, #148]	@ 0x94
    bl _call_via_r2
.Lus_0803C1CE:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #36]	@ 0x24
    str	r1, [sp, #40]	@ 0x28
    ldr	r3, [sp, #36]	@ 0x24
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    add	r0, r8
    ldr r1, .Lus_0803C4DC
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Lus_0803C4E0
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #36]	@ 0x24
    add	r4, sp, #36	@ 0x24
    ldrb	r0, [r4, #0]
    adds	r0, #150	@ 0x96
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    ldr r1, .Lus_0803C4E4
    ands	r1, r2
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    mov	r3, r9
    lsls	r1, r3, #16
    lsrs	r1, r1, #16
    movs	r0, #15
    ands	r1, r0
    lsls	r1, r1, #12
    ldr r2, .Lus_0803C4E8
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Lus_0803C4EC
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    movs	r0, #128	@ 0x80
    lsls	r0, r0, #5
    ldr	r1, [sp, #36]	@ 0x24
    orrs	r1, r0
    str	r1, [sp, #36]	@ 0x24
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r2, [r5, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Lus_0803C24E
    lsls	r0, r2, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r5, #0]
.Lus_0803C24E:
    ldr	r0, [r7, #8]
    mov	sl, r0
    movs	r1, #0
    mov	r9, r1
    mov	r2, sp
    adds	r2, #44	@ 0x2c
    str	r2, [sp, #96]	@ 0x60
    ldr	r3, [sp, #76]	@ 0x4c
    negs	r3, r3
    str	r3, [sp, #104]	@ 0x68
    mov	r4, sp
    adds	r4, #60	@ 0x3c
    str	r4, [sp, #100]	@ 0x64
    movs	r5, #16
    str	r5, [sp, #108]	@ 0x6c
.Lus_0803C26C:
    mov	r1, r9
    lsls	r0, r1, #2
    add	r0, sl
    ldr	r4, [r0, #84]	@ 0x54
    mov	r0, sl
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    adds	r6, r4, #0
    mov	r8, r0
    adds	r5, r6, #0
    adds	r5, #32
    adds	r0, r5, #0
    bl UpdateIndexedResourceHandle
    adds	r4, r0, #0
    lsls	r4, r4, #30
    lsrs	r4, r4, #31
    ldr	r1, [r6, #32]
    ldr	r3, [r1, #0]
    ldrh	r2, [r5, #12]
    lsls	r2, r2, #2
    ldr	r0, [r6, #36]	@ 0x24
    adds	r0, r0, r2
    ldrh	r2, [r0, #0]
    add	r0, sp, #4
    ldr	r3, [r3, #16]
    bl _call_via_r3
    cmp	r4, #0
    beq .Lus_0803C2E0
    ldr	r4, [sp, #12]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    adds	r2, r0, #0
    add	r1, sp, #12
    ldr	r0, [sp, #12]
    movs	r3, #0
    cmp	r0, #0
    beq .Lus_0803C2C4
    ldrh	r3, [r1, #4]
.Lus_0803C2C4:
    adds	r1, r6, #0
    adds	r1, #8
    lsls	r0, r2, #5
    ldr r2, .Lus_0803C4D8
    adds	r0, r0, r2
    str	r4, [r1, #12]
    str	r0, [r1, #16]
    str	r3, [r1, #20]
    ldr	r3, [sp, #148]	@ 0x94
    ldr	r0, [r3, #8]
    ldr	r2, [r0, #16]
    adds	r0, r3, #0
    bl _call_via_r2
.Lus_0803C2E0:
    ldr	r0, [sp, #4]
    ldr	r1, [r0, #4]
    ldr	r0, [r0, #0]
    str	r0, [sp, #44]	@ 0x2c
    str	r1, [sp, #48]	@ 0x30
    ldr	r3, [sp, #44]	@ 0x2c
    lsls	r0, r3, #7
    lsrs	r0, r0, #23
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r0, r0, r4
    ldr r1, .Lus_0803C4DC
    ands	r0, r1
    lsls	r0, r0, #16
    ldr r2, .Lus_0803C4E0
    ands	r2, r3
    orrs	r2, r0
    str	r2, [sp, #44]	@ 0x2c
    ldr	r5, [sp, #96]	@ 0x60
    ldrb	r1, [r5, #0]
    adds	r1, #150	@ 0x96
    lsls	r1, r1, #24
    lsrs	r1, r1, #24
    ldr r0, .Lus_0803C4E4
    ands	r0, r2
    orrs	r0, r1
    str	r0, [sp, #44]	@ 0x2c
    mov	r0, r8
    lsls	r1, r0, #16
    lsrs	r1, r1, #16
    movs	r2, #15
    ands	r1, r2
    lsls	r1, r1, #12
    add	r4, sp, #44	@ 0x2c
    ldr	r0, [r4, #4]
    ldr r3, .Lus_0803C4E8
    ands	r0, r3
    orrs	r0, r1
    str	r0, [r4, #4]
    ldr	r1, [r6, #4]
    adds	r0, r6, #0
    bl GetObjTileIndex
    lsls	r0, r0, #22
    lsrs	r0, r0, #22
    ldr r2, .Lus_0803C4EC
    ldr	r1, [r4, #4]
    ands	r1, r2
    orrs	r1, r0
    str	r1, [r4, #4]
    ldr	r1, [sp, #44]	@ 0x2c
    movs	r5, #128	@ 0x80
    lsls	r5, r5, #5
    orrs	r1, r5
    str	r1, [sp, #44]	@ 0x2c
    ldr	r0, [sp, #68]	@ 0x44
    ldrb	r2, [r0, #0]
    cmp	r2, #127	@ 0x7f
    bhi .Lus_0803C366
    lsls	r0, r2, #3
    adds	r0, #4
    ldr	r3, [sp, #68]	@ 0x44
    adds	r0, r3, r0
    str	r1, [r0, #0]
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r2, #1
    strb	r0, [r3, #0]
.Lus_0803C366:
    ldr	r4, [sp, #108]	@ 0x6c
    adds	r4, #16
    str	r4, [sp, #108]	@ 0x6c
    movs	r5, #1
    add	r9, r5
    mov	r0, r9
    cmp	r0, #6
    bhi .Lus_0803C378
    b .Lus_0803C26C
.Lus_0803C378:
    ldr	r7, [r7, #8]
    mov	r8, r7
    ldr	r1, [sp, #76]	@ 0x4c
    cmp	r1, #0
    beq .Lus_0803C3B0
    add	r0, sp, #52	@ 0x34
    movs	r4, #12
    movs	r5, #2
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #52]	@ 0x34
    mov	r6, r8
    adds	r6, #116	@ 0x74
    adds	r1, r6, #0
    movs	r2, #0
    bl Clear2DGfxBuffer
    add	r0, sp, #56	@ 0x38
    strh	r4, [r0, #0]
    strh	r5, [r0, #2]
    ldr	r0, [sp, #56]	@ 0x38
    ldr	r2, [sp, #76]	@ 0x4c
    str	r2, [sp, #0]
    adds	r1, r6, #0
    movs	r2, #0
    movs	r3, #0
    bl DrawStringTo2DGfxBuffer
.Lus_0803C3B0:
    mov	r0, r8
    adds	r0, #48	@ 0x30
    ldr	r1, [r0, #4]
    bl GetObjPaletteBank
    ldr	r3, [sp, #104]	@ 0x68
    ldr	r4, [sp, #76]	@ 0x4c
    orrs	r3, r4
    mov	r5, r8
    adds	r5, #112	@ 0x70
    str	r5, [sp, #80]	@ 0x50
    lsrs	r1, r3, #31
    str	r1, [sp, #84]	@ 0x54
    movs	r1, #0
    movs	r2, #0
    str	r1, [sp, #60]	@ 0x3c
    str	r2, [sp, #64]	@ 0x40
    ldr r2, .Lus_0803C4F0
    ldr	r1, [sp, #60]	@ 0x3c
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #24
    orrs	r1, r2
    ldr r2, .Lus_0803C4F4
    ands	r1, r2
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #7
    orrs	r1, r2
    str	r1, [sp, #60]	@ 0x3c
    lsls	r0, r0, #16
    lsrs	r0, r0, #16
    movs	r2, #15
    ands	r0, r2
    lsls	r0, r0, #12
    ldr	r3, [sp, #100]	@ 0x64
    ldr	r1, [r3, #4]
    ldr r4, .Lus_0803C4E8
    ands	r1, r4
    orrs	r1, r0
    str	r1, [r3, #4]
    ldr	r0, [sp, #60]	@ 0x3c
    ldr r5, .Lus_0803C4E4
    ands	r0, r5
    movs	r1, #142	@ 0x8e
    orrs	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #5
    orrs	r0, r1
    str	r0, [sp, #60]	@ 0x3c
    movs	r4, #0
    mov	r2, r8
    adds	r2, #116	@ 0x74
    str	r2, [sp, #88]	@ 0x58
.Lus_0803C41A:
    lsls	r0, r4, #3
    ldr	r3, [sp, #80]	@ 0x50
    adds	r0, r0, r3
    movs	r5, #193	@ 0xc1
    lsls	r5, r5, #2
    adds	r0, r0, r5
    ldr	r1, [r0, #4]
    bl GetObjTileIndex
    mov	r8, r0
    lsls	r0, r4, #5
    mov	sl, r0
    adds	r1, r4, #1
    str	r1, [sp, #92]	@ 0x5c
    ldr	r2, [sp, #84]	@ 0x54
    cmp	r2, #0
    beq .Lus_0803C498
    movs	r3, #0
    lsls	r2, r4, #1
    lsls	r1, r4, #2
    movs	r4, #128	@ 0x80
    mov	r9, r4
    adds	r1, r1, r2
    lsls	r1, r1, #3
    ldr	r5, [sp, #80]	@ 0x50
    movs	r4, #202	@ 0xca
    lsls	r4, r4, #2
    adds	r0, r5, r4
    adds	r4, r1, r0
    mov	r5, r8
    lsls	r0, r5, #5
    ldr r5, .Lus_0803C4D8
    adds	r7, r0, r5
    lsls	r2, r2, #6
    ldr	r0, [sp, #88]	@ 0x58
    adds	r6, r2, r0
    ldr	r2, [sp, #80]	@ 0x50
    movs	r5, #199	@ 0xc7
    lsls	r5, r5, #2
    adds	r0, r2, r5
    adds	r5, r1, r0
.Lus_0803C46C:
    str	r6, [r4, #0]
    str	r7, [r4, #4]
    mov	r0, r9
    str	r0, [r4, #8]
    ldr	r1, [sp, #148]	@ 0x94
    ldr	r0, [r1, #8]
    ldr	r2, [r0, #16]
    adds	r0, r1, #0
    adds	r1, r5, #0
    str	r3, [sp, #112]	@ 0x70
    bl _call_via_r2
    adds	r4, #24
    adds	r7, #128	@ 0x80
    movs	r2, #192	@ 0xc0
    lsls	r2, r2, #1
    adds	r6, r6, r2
    adds	r5, #24
    ldr	r3, [sp, #112]	@ 0x70
    adds	r3, #1
    cmp	r3, #1
    bls .Lus_0803C46C
.Lus_0803C498:
    mov	r3, r8
    lsls	r1, r3, #22
    lsrs	r1, r1, #22
    ldr r2, .Lus_0803C4EC
    ldr	r4, [sp, #100]	@ 0x64
    ldr	r0, [r4, #4]
    ands	r0, r2
    orrs	r0, r1
    str	r0, [r4, #4]
    mov	r1, sl
    adds	r1, #136	@ 0x88
    ldr r0, .Lus_0803C4DC
    ands	r1, r0
    lsls	r1, r1, #16
    ldr r0, .Lus_0803C4E0
    ldr	r2, [sp, #60]	@ 0x3c
    ands	r2, r0
    orrs	r2, r1
    str	r2, [sp, #60]	@ 0x3c
    ldr	r5, [sp, #68]	@ 0x44
    ldrb	r3, [r5, #0]
    cmp	r3, #127	@ 0x7f
    bhi .Lus_0803C500
    lsls	r0, r3, #3
    adds	r0, #4
    adds	r0, r5, r0
    str	r2, [r0, #0]
    b .Lus_0803C4F8
.Lus_0803C4D0:
    .word OBJ_PALETTE
.Lus_0803C4D4:
    .4byte gMenuEntryLabels
.Lus_0803C4D8:
    .word OBJ_VRAM0
.Lus_0803C4DC:
    .4byte 0x000001FF
.Lus_0803C4E0:
    .4byte 0xFE00FFFF
.Lus_0803C4E4:
    .4byte 0xFFFFFF00
.Lus_0803C4E8:
    .4byte 0xFFFF0FFF
.Lus_0803C4EC:
    .4byte 0xFFFFFC00
.Lus_0803C4F0:
    .4byte 0x3FFFFFFF
.Lus_0803C4F4:
    .4byte 0xFFFF3FFF
.Lus_0803C4F8:
    ldrh	r1, [r4, #4]
    strh	r1, [r0, #4]
    adds	r0, r3, #1
    strb	r0, [r5, #0]
.Lus_0803C500:
    ldr	r4, [sp, #92]	@ 0x5c
    cmp	r4, #2
    bls .Lus_0803C41A
.Lus_0803C506:
    ldr	r0, [sp, #72]	@ 0x48
    add	sp, #116	@ 0x74
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .section .text.map_clock_status_calendar, "ax", %progbits
    .align 2, 0
    .global UpdateMapClockStatusHudCalendar
    .thumb_func
UpdateMapClockStatusHudCalendar:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #48	@ 0x30
    str	r1, [sp, #32]
    lsls	r2, r2, #24
    lsrs	r2, r2, #24
    str	r2, [sp, #36]	@ 0x24
    ldr	r7, [r0, #0]
    ldrb	r0, [r1, #1]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    beq .Lus_0803CD7E
    cmp	r0, #1
    ble .Lus_0803CD78
    cmp	r0, #2
    beq .Lus_0803CD84
    cmp	r0, #3
    beq .Lus_0803CD8A
.Lus_0803CD78:
    movs	r5, #11
    movs	r6, #12
    b .Lus_0803CD8E
.Lus_0803CD7E:
    movs	r5, #13
    movs	r6, #14
    b .Lus_0803CD8E
.Lus_0803CD84:
    movs	r5, #15
    movs	r6, #16
    b .Lus_0803CD8E
.Lus_0803CD8A:
    movs	r5, #17
    movs	r6, #18
.Lus_0803CD8E:
    adds	r0, r7, #0
    adds	r0, #132	@ 0x84
    lsls	r1, r5, #5
    ldr r2, .Lus_0803CE30
    mov	sl, r2
    add	r1, sl
    movs	r2, #32
    bl memcpy
    movs	r0, #198	@ 0xc6
    lsls	r0, r0, #1
    adds	r4, r7, r0
    movs	r1, #1
    mov	r8, r1
    mov	r2, r8
    strb	r2, [r4, #0]
    lsls	r1, r6, #5
    add	r1, sl
    adds	r0, r7, #0
    adds	r0, #164	@ 0xa4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    strb	r0, [r4, #0]
    ldr	r1, [sp, #32]
    ldrb	r3, [r1, #1]
    lsls	r0, r3, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    adds	r5, r0, #0
    ldrb	r2, [r1, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
    lsls	r3, r3, #30
    lsrs	r3, r3, #30
    adds	r2, #6
    lsls	r1, r3, #4
    subs	r1, r1, r3
    lsls	r1, r1, #1
    lsls	r0, r2, #4
    subs	r0, r0, r2
    lsls	r0, r0, #3
    adds	r1, r1, r0
    adds	r1, r1, r5
    subs	r1, #1
    mov	r9, r4
    cmp	r1, #6
    bls .Lus_0803CDFA
    adds	r0, r1, #0
    movs	r1, #7
    bl __umodsi3
    adds	r1, r0, #0
.Lus_0803CDFA:
    movs	r0, #7
    adds	r6, r0, #0
    ands	r6, r1
    adds	r0, r5, #0
    movs	r1, #10
    bl __udivsi3
    adds	r4, r0, #0
    adds	r0, r5, #0
    movs	r1, #10
    bl __umodsi3
    adds	r5, r0, #0
    cmp	r4, #0
    ble .Lus_0803CE34
    lsls	r1, r4, #5
    add	r1, sl
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    mov	r2, r9
    strb	r0, [r2, #0]
    b .Lus_0803CE50
    .align 2, 0
.Lus_0803CE30:
    .4byte gMapClockStatusGlyphTiles
.Lus_0803CE34:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r7, #0
    adds	r0, #196	@ 0xc4
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    mov	r1, r9
    strb	r2, [r1, #0]
.Lus_0803CE50:
    lsls	r1, r5, #5
    ldr r0, .Lus_0803CE74
    adds	r1, r1, r0
    adds	r0, r7, #0
    adds	r0, #228	@ 0xe4
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r1, r9
    strb	r0, [r1, #0]
    cmp	r6, #6
    bhi .Lus_0803CE98
    lsls	r0, r6, #2
    ldr r1, .Lus_0803CE78
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_0803CE74:
    .4byte gMapClockStatusGlyphTiles
.Lus_0803CE78:
    .4byte .Lus_0803CE7C
.Lus_0803CE7C:
    .4byte .Lus_0803CE98
    .4byte .Lus_0803CEA4
    .4byte .Lus_0803CEB0
    .4byte .Lus_0803CEBC
    .4byte .Lus_0803CEC8
    .4byte .Lus_0803CED4
    .4byte .Lus_0803CEE0
.Lus_0803CE98:
    movs	r0, #96	@ 0x60
    str	r0, [sp, #0]
    movs	r0, #97	@ 0x61
    str	r0, [sp, #4]
    movs	r0, #98	@ 0x62
    b .Lus_0803CEEA
.Lus_0803CEA4:
    .4byte 0x90002063
    .4byte 0x90012064
    .4byte 0xE01C2065
.Lus_0803CEB0:
    .4byte 0x90002066
    .4byte 0x90012067
    .4byte 0xE0162068
.Lus_0803CEBC:
    .4byte 0x90002069
    .4byte 0x9001206A
    .4byte 0xE010206B
.Lus_0803CEC8:
    .4byte 0x9000206C
    .4byte 0x9001206D
    .4byte 0xE00A206E
.Lus_0803CED4:
    .4byte 0x9000206F
    .4byte 0x90012070
    .4byte 0xE0042071
.Lus_0803CEE0:
    .4byte 0x90002072
    .4byte 0x90012073
    .hword 0x2074
.Lus_0803CEEA:
    str	r0, [sp, #8]
    movs	r2, #212	@ 0xd4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    ldr	r1, [sp, #0]
    lsls	r1, r1, #5
    ldr r2, .Lus_0803CF90
    mov	r8, r2
    add	r1, r8
    movs	r2, #32
    bl memcpy
    movs	r0, #172	@ 0xac
    lsls	r0, r0, #2
    adds	r4, r7, r0
    movs	r6, #1
    strb	r6, [r4, #0]
    ldr	r1, [sp, #4]
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #228	@ 0xe4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    strb	r6, [r4, #0]
    ldr	r1, [sp, #8]
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #244	@ 0xf4
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    strb	r6, [r4, #0]
    ldr	r1, [sp, #32]
    ldr	r0, [r1, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    adds	r5, r0, #0
    movs	r1, #30
    str	r4, [sp, #44]	@ 0x2c
    cmp	r5, #11
    bhi .Lus_0803CF48
    movs	r1, #28
.Lus_0803CF48:
    lsls	r1, r1, #5
    add	r1, r8
    movs	r2, #130	@ 0x82
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    mov	r0, r9
    strb	r6, [r0, #0]
    movs	r4, #12
    cmp	r5, #12
    beq .Lus_0803CF6A
    adds	r4, r5, #0
    cmp	r4, #11
    bls .Lus_0803CF6A
    subs	r4, #12
.Lus_0803CF6A:
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    cmp	r5, #0
    ble .Lus_0803CF94
    lsls	r1, r5, #5
    ldr r0, .Lus_0803CF90
    adds	r1, r1, r0
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    b .Lus_0803CFA6
.Lus_0803CF90:
    .4byte gMapClockStatusGlyphTiles
.Lus_0803CF94:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    movs	r2, #162	@ 0xa2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    mov	r1, sp
.Lus_0803CFA6:
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r1, r9
    strb	r0, [r1, #0]
    lsls	r1, r4, #5
    ldr r2, .Lus_0803D050
    mov	sl, r2
    add	r1, sl
    movs	r2, #178	@ 0xb2
    lsls	r2, r2, #1
    adds	r0, r7, r2
    movs	r2, #32
    bl memcpy
    movs	r0, #1
    mov	r8, r0
    mov	r2, r8
    mov	r1, r9
    strb	r2, [r1, #0]
    ldr	r1, [sp, #32]
    ldr	r0, [r1, #0]
    lsls	r0, r0, #5
    lsrs	r0, r0, #26
    movs	r1, #10
    bl __udivsi3
    lsls	r0, r0, #24
    lsrs	r0, r0, #24
    lsls	r4, r0, #2
    adds	r4, r4, r0
    lsls	r4, r4, #1
    adds	r0, r4, #0
    movs	r1, #10
    bl __udivsi3
    adds	r5, r0, #0
    adds	r0, r4, #0
    movs	r1, #10
    bl __umodsi3
    adds	r4, r0, #0
    lsls	r5, r5, #5
    add	r5, sl
    movs	r2, #138	@ 0x8a
    lsls	r2, r2, #2
    adds	r6, r7, r2
    movs	r1, #146	@ 0x92
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r5, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    lsls	r4, r4, #5
    add	r4, sl
    movs	r1, #154	@ 0x9a
    lsls	r1, r1, #2
    adds	r0, r7, r1
    adds	r1, r4, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    ldr	r1, [sp, #36]	@ 0x24
    cmp	r1, #0
    beq .Lus_0803D054
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #1
    add	r1, sl
    adds	r0, r6, #0
    movs	r2, #32
    bl memcpy
    mov	r0, r8
    ldr	r2, [sp, #44]	@ 0x2c
    strb	r0, [r2, #0]
    b .Lus_0803D06E
    .align 2, 0
.Lus_0803D050:
    .4byte gMapClockStatusGlyphTiles
.Lus_0803D054:
    mov	r0, sp
    movs	r1, #0
    movs	r2, #32
    bl memset
    adds	r0, r6, #0
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r2, r8
    ldr	r1, [sp, #44]	@ 0x2c
    strb	r2, [r1, #0]
.Lus_0803D06E:
    add	sp, #48	@ 0x30
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0

    .section .text.farming_calendar_helpers, "ax", %progbits
    .align 2, 0
    .global DecodeGameDayDate
    .thumb_func
DecodeGameDayDate:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #12
    adds	r7, r0, #0
    adds	r5, r1, #0
    ldrb	r3, [r5, #1]
    add	r4, sp, #8
    strb	r3, [r4, #0]
    ldrb	r2, [r5, #0]
    lsls	r2, r2, #29
    lsrs	r2, r2, #29
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
    mov	r8, r4
    cmp	r3, #6
    bls .Lus_0803D572
    adds	r0, r3, #0
    movs	r1, #7
    bl __umodsi3
    adds	r3, r0, #0
.Lus_0803D572:
    movs	r1, #8
    negs	r1, r1
    movs	r0, #7
    ands	r0, r3
    ands	r1, r6
    adds	r6, r1, #0
    orrs	r6, r0
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #0]
    ldrb	r0, [r5, #0]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #4]
    add	r0, sp, #4
    mov	r2, sp
    cmp	r3, r1
    bls .Lus_0803D59E
    adds	r2, r0, #0
.Lus_0803D59E:
    ldr	r4, [r2, #0]
    ldr	r0, [r5, #0]
    lsls	r0, r0, #11
    lsrs	r0, r0, #27
    cmp	r0, #5
    bhi .Lus_0803D612
    mov	r5, r8
    ldrb	r3, [r5, #0]
    lsls	r0, r3, #25
    lsrs	r2, r0, #27
    cmp	r2, #0
    bne .Lus_0803D5CE
    lsls	r0, r3, #30
    lsrs	r0, r0, #30
    movs	r1, #4
    negs	r1, r1
    subs	r0, #1
    movs	r2, #3
    ands	r0, r2
    ands	r1, r3
    orrs	r1, r0
    strb	r1, [r5, #0]
    movs	r2, #29
    b .Lus_0803D5D0
.Lus_0803D5CE:
    subs	r2, #1
.Lus_0803D5D0:
    movs	r0, #31
    ands	r2, r0
    lsls	r2, r2, #2
    ldrb	r1, [r5, #0]
    movs	r0, #125	@ 0x7d
    negs	r0, r0
    ands	r0, r1
    orrs	r0, r2
    strb	r0, [r5, #0]
    mov	r0, r8
    ldrb	r1, [r0, #0]
    lsls	r0, r1, #30
    lsrs	r0, r0, #30
    cmp	r0, #3
    bne .Lus_0803D5F8
    lsls	r0, r1, #25
    lsrs	r0, r0, #27
    cmp	r0, #29
    bne .Lus_0803D5F8
    subs	r4, #1
.Lus_0803D5F8:
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    movs	r1, #6
    cmp	r0, #1
    ble .Lus_0803D604
    subs	r1, r0, #1
.Lus_0803D604:
    movs	r0, #7
    ands	r1, r0
    movs	r0, #8
    negs	r0, r0
    ands	r0, r6
    adds	r6, r0, #0
    orrs	r6, r1
.Lus_0803D612:
    strb	r4, [r7, #0]
    mov	r1, r8
    ldrb	r0, [r1, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    strb	r0, [r7, #1]
    add	r0, sp, #8
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #27
    adds	r0, #1
    strb	r0, [r7, #2]
    lsls	r0, r6, #29
    lsrs	r0, r0, #29
    strb	r0, [r7, #3]
    adds	r0, r7, #0
    add	sp, #12
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803D644
    .thumb_func
func_0803D644:
    push	{r4, lr}
    sub	sp, #8
    lsls	r2, r0, #4
    subs	r2, r2, r0
    lsls	r2, r2, #1
    subs	r2, #1
    adds	r2, r2, r1
    str	r2, [sp, #4]
    ldr r0, .Lus_0803D684
    adds	r4, r0, #0
    adds	r4, #14
    movs	r1, #0
    str	r1, [sp, #0]
    adds	r1, r4, #0
    add	r2, sp, #4
    movs	r3, #0
    bl func_080E0E80
    adds	r1, r0, #0
    movs	r2, #0
    cmp	r1, r4
    beq .Lus_0803D67A
    ldr	r0, [sp, #4]
    ldrb	r1, [r1, #0]
    cmp	r0, r1
    bcc .Lus_0803D67A
    movs	r2, #1
.Lus_0803D67A:
    adds	r0, r2, #0
    add	sp, #8
    pop	{r4}
    pop	{r1}
    bx	r1
.Lus_0803D684:
    .4byte gUnk_080F1A66
    .section .text.npc_schedule_after
    .global func_0803DA24
    .thumb_func
func_0803DA24:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803DA3C
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lus_0803DA40
    movs	r0, #0
    b .Lus_0803DA74
.Lus_0803DA3C:
    .4byte 0x000021CA
.Lus_0803DA40:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DA60
    movs	r0, #4
    b .Lus_0803DA74
.Lus_0803DA60:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803DA72
    cmp	r4, #2
    bne .Lus_0803DA6E
    movs	r0, #3
    b .Lus_0803DA74
.Lus_0803DA6E:
    movs	r0, #1
    b .Lus_0803DA74
.Lus_0803DA72:
    movs	r0, #2
.Lus_0803DA74:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DA7C
    .thumb_func
func_0803DA7C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803DAC8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lus_0803DA96
    b .Lus_0803DC22
.Lus_0803DA96:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Lus_0803DACC
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    cmp	r4, #3
    bne .Lus_0803DB6A
    cmp	r7, #2
    bne .Lus_0803DAD0
    mov	r0, r8
    cmp	r0, #13
    bne .Lus_0803DAD0
    movs	r0, #22
    b .Lus_0803DC54
.Lus_0803DAC8:
    .4byte 0x000021CA
.Lus_0803DACC:
    .4byte 0x00001CD4
.Lus_0803DAD0:
    ldr r1, .Lus_0803DAE4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_0803DAE8
    movs	r0, #23
    b .Lus_0803DC54
    .align 2, 0
.Lus_0803DAE4:
    .4byte 0x0000216B
.Lus_0803DAE8:
    ldr r1, .Lus_0803DB20
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Lus_0803DB24
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803DB14
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803DB14
    cmp	r0, #4
    bne .Lus_0803DB38
.Lus_0803DB14:
    cmp	r4, #0
    beq .Lus_0803DB2C
    cmp	r6, #0
    beq .Lus_0803DB28
    movs	r0, #13
    b .Lus_0803DC54
.Lus_0803DB20:
    .4byte 0x00002148
.Lus_0803DB24:
    .4byte 0x00001CD4
.Lus_0803DB28:
    movs	r0, #12
    b .Lus_0803DC54
.Lus_0803DB2C:
    cmp	r6, #0
    beq .Lus_0803DB34
    movs	r0, #15
    b .Lus_0803DC54
.Lus_0803DB34:
    movs	r0, #14
    b .Lus_0803DC54
.Lus_0803DB38:
    cmp	r6, #0
    beq .Lus_0803DB4E
    mov	r0, r9
    cmp	r0, #0
    bne .Lus_0803DB4E
    cmp	r4, #0
    beq .Lus_0803DB4A
    movs	r0, #8
    b .Lus_0803DC54
.Lus_0803DB4A:
    movs	r0, #11
    b .Lus_0803DC54
.Lus_0803DB4E:
    cmp	r4, #0
    beq .Lus_0803DB5E
    cmp	r6, #0
    beq .Lus_0803DB5A
    movs	r0, #7
    b .Lus_0803DC54
.Lus_0803DB5A:
    movs	r0, #6
    b .Lus_0803DC54
.Lus_0803DB5E:
    cmp	r6, #0
    beq .Lus_0803DB66
    movs	r0, #10
    b .Lus_0803DC54
.Lus_0803DB66:
    movs	r0, #9
    b .Lus_0803DC54
.Lus_0803DB6A:
    ldr r1, .Lus_0803DB8C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lus_0803DB9E
    cmp	r7, #1
    bne .Lus_0803DC22
    movs	r0, #1
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DB90
    movs	r0, #19
    b .Lus_0803DC54
.Lus_0803DB8C:
    .4byte 0x00001D6C
.Lus_0803DB90:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803DB9A
    movs	r0, #20
    b .Lus_0803DC54
.Lus_0803DB9A:
    movs	r0, #21
    b .Lus_0803DC54
.Lus_0803DB9E:
    cmp	r7, #2
    bne .Lus_0803DBC0
    mov	r0, r8
    cmp	r0, #30
    bne .Lus_0803DBC0
    ldr r1, .Lus_0803DBBC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803DBC0
    movs	r0, #17
    b .Lus_0803DC54
    .align 2, 0
.Lus_0803DBBC:
    .4byte 0x000021A3
.Lus_0803DBC0:
    ldr r1, .Lus_0803DBF8
    adds	r0, r5, r1
    movs	r1, #3
    bl func_080A01F8
    cmp	r7, #3
    bne .Lus_0803DC04
    mov	r1, r8
    cmp	r1, #14
    bne .Lus_0803DC04
    cmp	r4, #0
    bne .Lus_0803DC04
    cmp	r0, #0
    beq .Lus_0803DC04
    bl GetLove__C12Bachelorette
    ldr r1, .Lus_0803DBFC
    cmp	r0, r1
    bls .Lus_0803DC04
    ldr r1, .Lus_0803DC00
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803DC04
    movs	r0, #18
    b .Lus_0803DC54
.Lus_0803DBF8:
    .4byte 0x00001CD4
.Lus_0803DBFC:
    .4byte 0x0000270F
.Lus_0803DC00:
    .4byte 0x000021A3
.Lus_0803DC04:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DC16
    movs	r0, #16
    b .Lus_0803DC54
.Lus_0803DC16:
    ldr r1, .Lus_0803DC28
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lus_0803DC2C
.Lus_0803DC22:
    movs	r0, #0
    b .Lus_0803DC54
    .align 2, 0
.Lus_0803DC28:
    .4byte 0x0000215A
.Lus_0803DC2C:
    mov	r0, r9
    cmp	r0, #0
    bne .Lus_0803DC48
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803DC44
    cmp	r7, #1
    bne .Lus_0803DC40
    movs	r0, #5
    b .Lus_0803DC54
.Lus_0803DC40:
    movs	r0, #3
    b .Lus_0803DC54
.Lus_0803DC44:
    movs	r0, #4
    b .Lus_0803DC54
.Lus_0803DC48:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803DC52
    movs	r0, #2
    b .Lus_0803DC54
.Lus_0803DC52:
    movs	r0, #1
.Lus_0803DC54:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DC64
    .thumb_func
func_0803DC64:
    push	{r4, lr}
    sub	sp, #4
    adds	r2, r0, #0
    ldr r1, .Lus_0803DC7C
    adds	r0, r2, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lus_0803DC80
    movs	r0, #0
    b .Lus_0803DCAA
.Lus_0803DC7C:
    .4byte 0x000021CA
.Lus_0803DC80:
    mov	r4, sp
    adds	r1, r2, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DCA0
    movs	r0, #3
    b .Lus_0803DCAA
.Lus_0803DCA0:
    cmp	r4, #0
    beq .Lus_0803DCA8
    movs	r0, #1
    b .Lus_0803DCAA
.Lus_0803DCA8:
    movs	r0, #2
.Lus_0803DCAA:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DCB4
    .thumb_func
func_0803DCB4:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r0, .Lus_0803DCE4
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetChild__C13NpcCollection
    cmp	r0, #0
    bne .Lus_0803DCCA
    b .Lus_0803DDDE
.Lus_0803DCCA:
    bl GetAgeDays__C5Child
    cmp	r0, #59	@ 0x3b
    bls .Lus_0803DCD4
    b .Lus_0803DDDA
.Lus_0803DCD4:
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #31
    bne .Lus_0803DCE8
    movs	r0, #3
    b .Lus_0803DDE0
.Lus_0803DCE4:
    .4byte 0x00001CD4
.Lus_0803DCE8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Lus_0803DD06
    cmp	r1, #13
    bne .Lus_0803DD06
    movs	r0, #5
    b .Lus_0803DDE0
.Lus_0803DD06:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803DDB0
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803DDB0
    cmp	r0, #4
    beq .Lus_0803DDB0
    ldr r1, .Lus_0803DD30
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    subs	r0, r6, #3
    cmp	r0, #28
    bhi .Lus_0803DDD6
    lsls	r0, r0, #2
    ldr r1, .Lus_0803DD34
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_0803DD30:
    .4byte 0x00002148
.Lus_0803DD34:
    .4byte .Lus_0803DD38
.Lus_0803DD38:
    .4byte .Lus_0803DDB4
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDAC
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDBE
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDCC
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD2
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
    .4byte .Lus_0803DDD6
.Lus_0803DDAC:
    .4byte 0xD1122C01
.Lus_0803DDB0:
    movs	r0, #2
    b .Lus_0803DDE0
.Lus_0803DDB4:
    .4byte 0xD0FB2A00
    .4byte 0xD10C2C00
    .hword 0xE7F8
.Lus_0803DDBE:
    .hword 0x2A00
    .4byte 0x2C02D0F6
    .4byte 0x2C00D0F4
    .4byte 0xE7F1D105
.Lus_0803DDCC:
    .4byte 0xD1022C03
    .hword 0xE7EE
.Lus_0803DDD2:
    .hword 0x2A00
    .hword 0xD0EC
.Lus_0803DDD6:
    movs	r0, #1
    b .Lus_0803DDE0
.Lus_0803DDDA:
    movs	r0, #4
    b .Lus_0803DDE0
.Lus_0803DDDE:
    movs	r0, #0
.Lus_0803DDE0:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803DDE8
    .thumb_func
func_0803DDE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803DE48
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    blt .Lus_0803DE42
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    mov	r0, sp
    ldrb	r6, [r0, #0]
    ldrb	r7, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Lus_0803DE4C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803DE42
    subs	r1, #12
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    blt .Lus_0803DE50
    cmp	r6, #1
    bhi .Lus_0803DE42
    cmp	r6, #1
    bne .Lus_0803DE50
    cmp	r7, #3
    bne .Lus_0803DE50
    mov	r0, r8
    cmp	r0, #28
    bls .Lus_0803DE50
.Lus_0803DE42:
    movs	r0, #0
    b .Lus_0803DEBE
    .align 2, 0
.Lus_0803DE48:
    .4byte 0x000021CA
.Lus_0803DE4C:
    .4byte 0x00002181
.Lus_0803DE50:
    ldr r1, .Lus_0803DE64
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_0803DE68
    movs	r0, #5
    b .Lus_0803DEBE
    .align 2, 0
.Lus_0803DE64:
    .4byte 0x00002181
.Lus_0803DE68:
    adds	r0, r7, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DE7A
    movs	r0, #4
    b .Lus_0803DEBE
.Lus_0803DE7A:
    cmp	r6, #1
    bne .Lus_0803DE9C
    cmp	r7, #2
    bne .Lus_0803DE9C
    mov	r0, r8
    cmp	r0, #15
    bne .Lus_0803DE9C
    ldr r1, .Lus_0803DE98
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803DE9C
.Lus_0803DE94:
    movs	r0, #2
    b .Lus_0803DEBE
.Lus_0803DE98:
    .4byte 0x00002175
.Lus_0803DE9C:
    ldr r1, .Lus_0803DEB8
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lus_0803DEBC
    cmp	r4, #6
    bne .Lus_0803DE94
    movs	r0, #3
    b .Lus_0803DEBE
.Lus_0803DEB8:
    .4byte 0x00002174
.Lus_0803DEBC:
    movs	r0, #1
.Lus_0803DEBE:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DECC
    .thumb_func
func_0803DECC:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803DEEE
    movs	r0, #1
    b .Lus_0803DEF0
.Lus_0803DEEE:
    movs	r0, #2
.Lus_0803DEF0:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DEF8
    .thumb_func
func_0803DEF8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803DF10
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lus_0803DF14
    movs	r0, #0
    b .Lus_0803DF48
    .align 2, 0
.Lus_0803DF10:
    .4byte 0x000021CA
.Lus_0803DF14:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DF34
    movs	r0, #4
    b .Lus_0803DF48
.Lus_0803DF34:
    cmp	r4, #3
    bne .Lus_0803DF46
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803DF42
    movs	r0, #2
    b .Lus_0803DF48
.Lus_0803DF42:
    movs	r0, #3
    b .Lus_0803DF48
.Lus_0803DF46:
    movs	r0, #1
.Lus_0803DF48:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803DF50
    .thumb_func
func_0803DF50:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lus_0803DF68
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lus_0803DF6C
    movs	r0, #0
    b .Lus_0803DF8A
    .align 2, 0
.Lus_0803DF68:
    .4byte 0x000021CA
.Lus_0803DF6C:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803DF88
    movs	r0, #1
    b .Lus_0803DF8A
.Lus_0803DF88:
    movs	r0, #2
.Lus_0803DF8A:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803DF94
    .thumb_func
func_0803DF94:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lus_0803DFAC
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lus_0803DFB0
    movs	r0, #0
    b .Lus_0803DFE0
    .align 2, 0
.Lus_0803DFAC:
    .4byte 0x000021CA
.Lus_0803DFB0:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803DFCE
    movs	r0, #4
    b .Lus_0803DFE0
.Lus_0803DFCE:
    cmp	r4, #2
    bne .Lus_0803DFD6
    movs	r0, #2
    b .Lus_0803DFE0
.Lus_0803DFD6:
    cmp	r4, #0
    beq .Lus_0803DFDE
    movs	r0, #1
    b .Lus_0803DFE0
.Lus_0803DFDE:
    movs	r0, #3
.Lus_0803DFE0:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .global func_0803DFE8
    .thumb_func
func_0803DFE8:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E008
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #12
    ands	r0, r1
    cmp	r0, #0
    beq .Lus_0803E00C
    movs	r0, #0
    b .Lus_0803E194
    .align 2, 0
.Lus_0803E008:
    .4byte 0x000021CA
.Lus_0803E00C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r7, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r1, .Lus_0803E040
    adds	r4, r5, r1
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r6, r0, #0
    cmp	r6, #19
    bne .Lus_0803E0EA
    mov	r0, r8
    cmp	r0, #2
    bne .Lus_0803E04C
    cmp	r7, #9
    bne .Lus_0803E044
    movs	r0, #21
    b .Lus_0803E194
.Lus_0803E040:
    .4byte 0x00001CD4
.Lus_0803E044:
    cmp	r7, #13
    bne .Lus_0803E04C
    movs	r0, #22
    b .Lus_0803E194
.Lus_0803E04C:
    ldr r1, .Lus_0803E060
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_0803E064
    movs	r0, #23
    b .Lus_0803E194
    .align 2, 0
.Lus_0803E060:
    .4byte 0x0000216C
.Lus_0803E064:
    ldr r1, .Lus_0803E09C
    adds	r0, r5, r1
    ldrb	r6, [r0, #0]
    ldr r1, .Lus_0803E0A0
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803E090
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803E090
    cmp	r0, #4
    bne .Lus_0803E0B4
.Lus_0803E090:
    cmp	r4, #0
    beq .Lus_0803E0A8
    cmp	r6, #0
    beq .Lus_0803E0A4
    movs	r0, #18
    b .Lus_0803E194
.Lus_0803E09C:
    .4byte 0x00002148
.Lus_0803E0A0:
    .4byte 0x00001CD4
.Lus_0803E0A4:
    movs	r0, #17
    b .Lus_0803E194
.Lus_0803E0A8:
    cmp	r6, #0
    beq .Lus_0803E0B0
    movs	r0, #20
    b .Lus_0803E194
.Lus_0803E0B0:
    movs	r0, #19
    b .Lus_0803E194
.Lus_0803E0B4:
    cmp	r6, #0
    beq .Lus_0803E0CE
    mov	r0, r9
    cmp	r0, #0
    beq .Lus_0803E0C2
    cmp	r0, #2
    bne .Lus_0803E0CE
.Lus_0803E0C2:
    cmp	r4, #0
    beq .Lus_0803E0CA
    movs	r0, #13
    b .Lus_0803E194
.Lus_0803E0CA:
    movs	r0, #16
    b .Lus_0803E194
.Lus_0803E0CE:
    cmp	r4, #0
    beq .Lus_0803E0DE
    cmp	r6, #0
    beq .Lus_0803E0DA
    movs	r0, #12
    b .Lus_0803E194
.Lus_0803E0DA:
    movs	r0, #11
    b .Lus_0803E194
.Lus_0803E0DE:
    cmp	r6, #0
    beq .Lus_0803E0E6
    movs	r0, #15
    b .Lus_0803E194
.Lus_0803E0E6:
    movs	r0, #14
    b .Lus_0803E194
.Lus_0803E0EA:
    ldr r1, .Lus_0803E108
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lus_0803E11A
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E10C
    movs	r0, #10
    b .Lus_0803E194
.Lus_0803E108:
    .4byte 0x00001EB8
.Lus_0803E10C:
    mov	r0, r9
    cmp	r0, #0
    bne .Lus_0803E116
    movs	r0, #7
    b .Lus_0803E194
.Lus_0803E116:
    movs	r0, #6
    b .Lus_0803E194
.Lus_0803E11A:
    adds	r0, r4, #0
    movs	r1, #19
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Lus_0803E158
    cmp	r7, #14
    bne .Lus_0803E158
    cmp	r6, #0
    bne .Lus_0803E158
    cmp	r0, #0
    beq .Lus_0803E158
    bl GetLove__C12Bachelorette
    ldr r1, .Lus_0803E150
    cmp	r0, r1
    bls .Lus_0803E158
    ldr r1, .Lus_0803E154
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803E158
    movs	r0, #9
    b .Lus_0803E194
.Lus_0803E150:
    .4byte 0x0000270F
.Lus_0803E154:
    .4byte 0x000021A4
.Lus_0803E158:
    mov	r0, r8
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E16A
    movs	r0, #8
    b .Lus_0803E194
.Lus_0803E16A:
    mov	r0, r9
    cmp	r0, #0
    bne .Lus_0803E174
    movs	r0, #3
    b .Lus_0803E194
.Lus_0803E174:
    mov	r1, r9
    cmp	r1, #2
    bne .Lus_0803E188
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E184
    movs	r0, #4
    b .Lus_0803E194
.Lus_0803E184:
    movs	r0, #5
    b .Lus_0803E194
.Lus_0803E188:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803E192
    movs	r0, #2
    b .Lus_0803E194
.Lus_0803E192:
    movs	r0, #1
.Lus_0803E194:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E1A4
    .thumb_func
func_0803E1A4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E1BC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    cmp	r0, #0
    bge .Lus_0803E1C0
    movs	r0, #0
    b .Lus_0803E1F4
    .align 2, 0
.Lus_0803E1BC:
    .4byte 0x000021CA
.Lus_0803E1C0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E1E0
    movs	r0, #4
    b .Lus_0803E1F4
.Lus_0803E1E0:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E1F2
    cmp	r4, #2
    bne .Lus_0803E1EE
    movs	r0, #3
    b .Lus_0803E1F4
.Lus_0803E1EE:
    movs	r0, #1
    b .Lus_0803E1F4
.Lus_0803E1F2:
    movs	r0, #2
.Lus_0803E1F4:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E1FC
    .thumb_func
func_0803E1FC:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E214
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lus_0803E218
    movs	r0, #0
    b .Lus_0803E25A
    .align 2, 0
.Lus_0803E214:
    .4byte 0x000021CA
.Lus_0803E218:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r4, [r4, #2]
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E23A
    movs	r0, #2
    b .Lus_0803E25A
.Lus_0803E23A:
    ldr r1, .Lus_0803E254
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    cmp	r6, #2
    bne .Lus_0803E258
    cmp	r4, #5
    bne .Lus_0803E258
    cmp	r0, #25
    beq .Lus_0803E258
    movs	r0, #3
    b .Lus_0803E25A
    .align 2, 0
.Lus_0803E254:
    .4byte 0x00001CD4
.Lus_0803E258:
    movs	r0, #1
.Lus_0803E25A:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E264
    .thumb_func
func_0803E264:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E280
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lus_0803E284
    movs	r0, #0
    b .Lus_0803E3FE
.Lus_0803E280:
    .4byte 0x000021CA
.Lus_0803E284:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    mov	r8, r0
    ldrb	r6, [r4, #2]
    ldr r1, .Lus_0803E2B4
    adds	r0, r5, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds	r4, r0, #0
    mov	r0, r8
    cmp	r0, #2
    bne .Lus_0803E2B8
    cmp	r6, #5
    bne .Lus_0803E2B8
    cmp	r4, #25
    beq .Lus_0803E2BC
    movs	r0, #5
    b .Lus_0803E3FE
    .align 2, 0
.Lus_0803E2B4:
    .4byte 0x00001CD4
.Lus_0803E2B8:
    cmp	r4, #25
    bne .Lus_0803E364
.Lus_0803E2BC:
    mov	r1, r8
    cmp	r1, #2
    bne .Lus_0803E2D2
    cmp	r6, #9
    bne .Lus_0803E2CA
    movs	r0, #16
    b .Lus_0803E3FE
.Lus_0803E2CA:
    cmp	r6, #13
    bne .Lus_0803E2D2
    movs	r0, #17
    b .Lus_0803E3FE
.Lus_0803E2D2:
    ldr r1, .Lus_0803E2F0
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #1
    bne .Lus_0803E2F4
    movs	r0, #18
    b .Lus_0803E3FE
.Lus_0803E2F0:
    .4byte 0x0000216B
.Lus_0803E2F4:
    ldr r1, .Lus_0803E330
    adds	r0, r5, r1
    ldrb	r4, [r0, #0]
    ldr r1, .Lus_0803E334
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r7, r1, #31
    mov	r9, r7
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803E322
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803E322
    cmp	r0, #4
    bne .Lus_0803E348
.Lus_0803E322:
    mov	r0, r9
    cmp	r0, #0
    beq .Lus_0803E33C
    cmp	r4, #0
    beq .Lus_0803E338
    movs	r0, #13
    b .Lus_0803E3FE
.Lus_0803E330:
    .4byte 0x00002148
.Lus_0803E334:
    .4byte 0x00001CD4
.Lus_0803E338:
    movs	r0, #12
    b .Lus_0803E3FE
.Lus_0803E33C:
    cmp	r4, #0
    beq .Lus_0803E344
    movs	r0, #15
    b .Lus_0803E3FE
.Lus_0803E344:
    movs	r0, #14
    b .Lus_0803E3FE
.Lus_0803E348:
    cmp	r7, #0
    beq .Lus_0803E358
    cmp	r4, #0
    beq .Lus_0803E354
    movs	r0, #9
    b .Lus_0803E3FE
.Lus_0803E354:
    movs	r0, #8
    b .Lus_0803E3FE
.Lus_0803E358:
    cmp	r4, #0
    beq .Lus_0803E360
    movs	r0, #11
    b .Lus_0803E3FE
.Lus_0803E360:
    movs	r0, #10
    b .Lus_0803E3FE
.Lus_0803E364:
    ldr r1, .Lus_0803E388
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lus_0803E390
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803E3EE
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E38C
    movs	r0, #3
    b .Lus_0803E3FE
.Lus_0803E388:
    .4byte 0x00001F38
.Lus_0803E38C:
    movs	r0, #4
    b .Lus_0803E3FE
.Lus_0803E390:
    ldr r1, .Lus_0803E3D4
    adds	r0, r5, r1
    movs	r1, #25
    bl func_080A01F8
    mov	r1, r8
    cmp	r1, #3
    bne .Lus_0803E3E0
    cmp	r6, #14
    bne .Lus_0803E3E0
    cmp	r4, #0
    bne .Lus_0803E3E0
    cmp	r0, #0
    beq .Lus_0803E3E0
    bl GetLove__C12Bachelorette
    ldr r1, .Lus_0803E3D8
    cmp	r0, r1
    bls .Lus_0803E3E0
    ldr r1, .Lus_0803E3DC
    adds	r0, r5, r1
    ldrb	r2, [r0, #0]
    lsrs	r2, r2, #7
    adds	r1, #1
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    movs	r1, #1
    ands	r0, r1
    lsls	r0, r0, #1
    orrs	r0, r2
    cmp	r0, #2
    beq .Lus_0803E3E0
    movs	r0, #7
    b .Lus_0803E3FE
.Lus_0803E3D4:
    .4byte 0x00001CD4
.Lus_0803E3D8:
    .4byte 0x0000270F
.Lus_0803E3DC:
    .4byte 0x000021A3
.Lus_0803E3E0:
    mov	r0, r8
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E3F2
.Lus_0803E3EE:
    movs	r0, #6
    b .Lus_0803E3FE
.Lus_0803E3F2:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803E3FC
    movs	r0, #2
    b .Lus_0803E3FE
.Lus_0803E3FC:
    movs	r0, #1
.Lus_0803E3FE:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    @ ROM-verified US Thumb code_0803A8A4/code_0803E448
    .section .text.code_0803E448
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0803E448
    .thumb_func
func_0803E448:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E460
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803E464
    movs	r0, #0
    b .Lus_0803E498
    .align 2, 0
.Lus_0803E460:
    .4byte 0x000021CA
.Lus_0803E464:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E484
    movs	r0, #4
    b .Lus_0803E498
.Lus_0803E484:
    cmp	r4, #1
    bne .Lus_0803E496
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E492
    movs	r0, #2
    b .Lus_0803E498
.Lus_0803E492:
    movs	r0, #3
    b .Lus_0803E498
.Lus_0803E496:
    movs	r0, #1
.Lus_0803E498:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E4A0
    .thumb_func
func_0803E4A0:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E4BC
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803E4C0
    movs	r0, #0
    b .Lus_0803E610
.Lus_0803E4BC:
    .4byte 0x000021CA
.Lus_0803E4C0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Lus_0803E4F0
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #12
    bne .Lus_0803E56E
    cmp	r7, #2
    bne .Lus_0803E4FC
    cmp	r6, #9
    bne .Lus_0803E4F4
    movs	r0, #16
    b .Lus_0803E610
.Lus_0803E4F0:
    .4byte 0x00001CD4
.Lus_0803E4F4:
    cmp	r6, #13
    bne .Lus_0803E4FC
    movs	r0, #17
    b .Lus_0803E610
.Lus_0803E4FC:
    ldr r1, .Lus_0803E510
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_0803E514
    movs	r0, #18
    b .Lus_0803E610
    .align 2, 0
.Lus_0803E510:
    .4byte 0x0000216C
.Lus_0803E514:
    ldr r1, .Lus_0803E548
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803E53C
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803E53C
    cmp	r0, #4
    bne .Lus_0803E550
.Lus_0803E53C:
    mov	r0, r8
    cmp	r0, #0
    beq .Lus_0803E54C
    movs	r0, #14
    b .Lus_0803E610
    .align 2, 0
.Lus_0803E548:
    .4byte 0x00001CD4
.Lus_0803E54C:
    movs	r0, #15
    b .Lus_0803E610
.Lus_0803E550:
    mov	r1, r9
    cmp	r1, #1
    bne .Lus_0803E562
    cmp	r4, #0
    beq .Lus_0803E55E
    movs	r0, #11
    b .Lus_0803E610
.Lus_0803E55E:
    movs	r0, #13
    b .Lus_0803E610
.Lus_0803E562:
    cmp	r4, #0
    beq .Lus_0803E56A
    movs	r0, #10
    b .Lus_0803E610
.Lus_0803E56A:
    movs	r0, #12
    b .Lus_0803E610
.Lus_0803E56E:
    ldr r1, .Lus_0803E58C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lus_0803E5A8
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E590
    movs	r0, #9
    b .Lus_0803E610
.Lus_0803E58C:
    .4byte 0x00001E28
.Lus_0803E590:
    mov	r0, r9
    cmp	r0, #4
    bne .Lus_0803E5A4
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E5A0
    movs	r0, #5
    b .Lus_0803E610
.Lus_0803E5A0:
    movs	r0, #6
    b .Lus_0803E610
.Lus_0803E5A4:
    movs	r0, #4
    b .Lus_0803E610
.Lus_0803E5A8:
    adds	r0, r4, #0
    movs	r1, #12
    bl func_080A01F8
    cmp	r7, #3
    bne .Lus_0803E5E8
    cmp	r6, #14
    bne .Lus_0803E5E8
    mov	r1, r8
    cmp	r1, #0
    bne .Lus_0803E5E8
    cmp	r0, #0
    beq .Lus_0803E5E8
    bl GetLove__C12Bachelorette
    ldr r1, .Lus_0803E5E0
    cmp	r0, r1
    bls .Lus_0803E5E8
    ldr r1, .Lus_0803E5E4
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #30
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803E5E8
    movs	r0, #7
    b .Lus_0803E610
    .align 2, 0
.Lus_0803E5E0:
    .4byte 0x0000270F
.Lus_0803E5E4:
    .4byte 0x000021A5
.Lus_0803E5E8:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E5FA
    movs	r0, #8
    b .Lus_0803E610
.Lus_0803E5FA:
    mov	r0, r9
    cmp	r0, #1
    bne .Lus_0803E60E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E60A
    movs	r0, #2
    b .Lus_0803E610
.Lus_0803E60A:
    movs	r0, #3
    b .Lus_0803E610
.Lus_0803E60E:
    movs	r0, #1
.Lus_0803E610:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E620
    .thumb_func
func_0803E620:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E638
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803E63C
    movs	r0, #0
    b .Lus_0803E67A
    .align 2, 0
.Lus_0803E638:
    .4byte 0x000021CA
.Lus_0803E63C:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E65C
    movs	r0, #5
    b .Lus_0803E67A
.Lus_0803E65C:
    cmp	r4, #1
    bne .Lus_0803E66E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E66A
    movs	r0, #3
    b .Lus_0803E67A
.Lus_0803E66A:
    movs	r0, #4
    b .Lus_0803E67A
.Lus_0803E66E:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803E678
    movs	r0, #2
    b .Lus_0803E67A
.Lus_0803E678:
    movs	r0, #1
.Lus_0803E67A:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E684
    .thumb_func
func_0803E684:
    push	{r4, r5, r6, lr}
    sub	sp, #12
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    adds	r6, r0, #0
    ldrb	r0, [r4, #2]
    adds	r4, r0, #0
    adds	r0, r6, #0
    adds	r1, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E6B0
    movs	r0, #2
    b .Lus_0803E6E2
.Lus_0803E6B0:
    movs	r3, #200	@ 0xc8
    str	r3, [sp, #4]
    ldrb	r0, [r5, #16]
    lsrs	r2, r0, #3
    lsls	r1, r2, #3
    subs	r1, r1, r2
    lsls	r0, r0, #29
    lsrs	r0, r0, #29
    adds	r1, r1, r0
    str	r1, [sp, #8]
    add	r2, sp, #8
    add	r0, sp, #4
    cmp	r3, r1
    bls .Lus_0803E6CE
    adds	r0, r2, #0
.Lus_0803E6CE:
    ldr	r0, [r0, #0]
    cmp	r0, #1
    bhi .Lus_0803E6E0
    cmp	r6, #0
    bne .Lus_0803E6E0
    cmp	r4, #2
    bhi .Lus_0803E6E0
    movs	r0, #0
    b .Lus_0803E6E2
.Lus_0803E6E0:
    movs	r0, #1
.Lus_0803E6E2:
    add	sp, #12
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E6EC
    .thumb_func
func_0803E6EC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r3, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #3
    bne .Lus_0803E740
    cmp	r3, #2
    bne .Lus_0803E740
    ldr r1, .Lus_0803E734
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #134	@ 0x86
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #128	@ 0x80
    lsls	r1, r1, #6
    cmp	r0, r1
    bne .Lus_0803E740
    ldr r1, .Lus_0803E738
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803E73C
    movs	r0, #7
    b .Lus_0803E778
    .align 2, 0
.Lus_0803E734:
    .4byte 0x00002178
.Lus_0803E738:
    .4byte 0x0000217A
.Lus_0803E73C:
    movs	r0, #0
    b .Lus_0803E778
.Lus_0803E740:
    adds	r0, r2, #0
    adds	r1, r3, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E752
    movs	r0, #6
    b .Lus_0803E778
.Lus_0803E752:
    cmp	r4, #6
    bne .Lus_0803E764
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E760
    movs	r0, #2
    b .Lus_0803E778
.Lus_0803E760:
    movs	r0, #3
    b .Lus_0803E778
.Lus_0803E764:
    cmp	r4, #0
    bne .Lus_0803E776
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803E772
    movs	r0, #4
    b .Lus_0803E778
.Lus_0803E772:
    movs	r0, #5
    b .Lus_0803E778
.Lus_0803E776:
    movs	r0, #1
.Lus_0803E778:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E780
    .thumb_func
func_0803E780:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r9
    mov	r6, r8
    push	{r6, r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E79C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lus_0803E7A0
    movs	r0, #0
    b .Lus_0803E8DA
.Lus_0803E79C:
    .4byte 0x000021CA
.Lus_0803E7A0:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r7, [r4, #1]
    ldrb	r6, [r4, #2]
    ldrb	r4, [r4, #3]
    mov	r9, r4
    ldr r0, .Lus_0803E7D0
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetSpouseCharacterId__C13NpcCollection
    mov	r8, r0
    cmp	r0, #21
    bne .Lus_0803E84E
    cmp	r7, #2
    bne .Lus_0803E7DC
    cmp	r6, #9
    bne .Lus_0803E7D4
    movs	r0, #14
    b .Lus_0803E8DA
.Lus_0803E7D0:
    .4byte 0x00001CD4
.Lus_0803E7D4:
    cmp	r6, #13
    bne .Lus_0803E7DC
    movs	r0, #15
    b .Lus_0803E8DA
.Lus_0803E7DC:
    ldr r1, .Lus_0803E7F0
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #29
    lsrs	r0, r0, #30
    cmp	r0, #1
    bne .Lus_0803E7F4
    movs	r0, #16
    b .Lus_0803E8DA
    .align 2, 0
.Lus_0803E7F0:
    .4byte 0x0000216C
.Lus_0803E7F4:
    ldr r1, .Lus_0803E828
    adds	r0, r5, r1
    bl GetChild__C13NpcCollection
    negs	r1, r0
    orrs	r1, r0
    lsrs	r4, r1, #31
    mov	r8, r4
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803E81C
    ldr	r0, [r5, #8]
    cmp	r0, #3
    beq .Lus_0803E81C
    cmp	r0, #4
    bne .Lus_0803E830
.Lus_0803E81C:
    mov	r0, r8
    cmp	r0, #0
    beq .Lus_0803E82C
    movs	r0, #12
    b .Lus_0803E8DA
    .align 2, 0
.Lus_0803E828:
    .4byte 0x00001CD4
.Lus_0803E82C:
    movs	r0, #13
    b .Lus_0803E8DA
.Lus_0803E830:
    mov	r1, r9
    cmp	r1, #3
    bne .Lus_0803E842
    cmp	r4, #0
    beq .Lus_0803E83E
    movs	r0, #9
    b .Lus_0803E8DA
.Lus_0803E83E:
    movs	r0, #11
    b .Lus_0803E8DA
.Lus_0803E842:
    cmp	r4, #0
    beq .Lus_0803E84A
    movs	r0, #8
    b .Lus_0803E8DA
.Lus_0803E84A:
    movs	r0, #10
    b .Lus_0803E8DA
.Lus_0803E84E:
    ldr r1, .Lus_0803E86C
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp	r0, #4
    bls .Lus_0803E87E
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E870
    movs	r0, #7
    b .Lus_0803E8DA
.Lus_0803E86C:
    .4byte 0x00001EE4
.Lus_0803E870:
    mov	r0, r9
    cmp	r0, #3
    bne .Lus_0803E87A
    movs	r0, #4
    b .Lus_0803E8DA
.Lus_0803E87A:
    movs	r0, #3
    b .Lus_0803E8DA
.Lus_0803E87E:
    adds	r0, r4, #0
    movs	r1, #21
    bl func_080A01F8
    cmp	r7, #3
    bne .Lus_0803E8BC
    cmp	r6, #14
    bne .Lus_0803E8BC
    mov	r1, r8
    cmp	r1, #0
    bne .Lus_0803E8BC
    cmp	r0, #0
    beq .Lus_0803E8BC
    bl GetLove__C12Bachelorette
    ldr r1, .Lus_0803E8B4
    cmp	r0, r1
    bls .Lus_0803E8BC
    ldr r1, .Lus_0803E8B8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803E8BC
    movs	r0, #6
    b .Lus_0803E8DA
.Lus_0803E8B4:
    .4byte 0x0000270F
.Lus_0803E8B8:
    .4byte 0x000021A4
.Lus_0803E8BC:
    adds	r0, r7, #0
    adds	r1, r6, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E8CE
    movs	r0, #5
    b .Lus_0803E8DA
.Lus_0803E8CE:
    mov	r0, r9
    cmp	r0, #3
    beq .Lus_0803E8D8
    movs	r0, #1
    b .Lus_0803E8DA
.Lus_0803E8D8:
    movs	r0, #2
.Lus_0803E8DA:
    add	sp, #4
    pop	{r3, r4}
    mov	r8, r3
    mov	r9, r4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803E8E8
    .thumb_func
func_0803E8E8:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803E924
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    blt .Lus_0803E948
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r2, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r2, #2
    bne .Lus_0803E92C
    cmp	r1, #30
    bne .Lus_0803E92C
    ldr r3, .Lus_0803E928
    adds	r0, r5, r3
    ldrb	r0, [r0, #0]
    lsrs	r0, r0, #6
    cmp	r0, #2
    beq .Lus_0803E92C
    movs	r0, #5
    b .Lus_0803E968
.Lus_0803E924:
    .4byte 0x000021CA
.Lus_0803E928:
    .4byte 0x000021A2
.Lus_0803E92C:
    adds	r0, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E93C
    movs	r0, #4
    b .Lus_0803E968
.Lus_0803E93C:
    ldr r1, .Lus_0803E94C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lus_0803E950
.Lus_0803E948:
    movs	r0, #0
    b .Lus_0803E968
.Lus_0803E94C:
    .4byte 0x0000215A
.Lus_0803E950:
    cmp	r4, #1
    beq .Lus_0803E958
    cmp	r4, #3
    bne .Lus_0803E95C
.Lus_0803E958:
    movs	r0, #3
    b .Lus_0803E968
.Lus_0803E95C:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803E966
    movs	r0, #2
    b .Lus_0803E968
.Lus_0803E966:
    movs	r0, #1
.Lus_0803E968:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803E970
    .thumb_func
func_0803E970:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    adds	r6, r4, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803E998
    movs	r0, #5
    b .Lus_0803E9DA
.Lus_0803E998:
    ldr r1, .Lus_0803E9A8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lus_0803E9AC
    movs	r0, #0
    b .Lus_0803E9DA
.Lus_0803E9A8:
    .4byte 0x000021CA
.Lus_0803E9AC:
    ldr r1, .Lus_0803E9C8
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lus_0803E9D0
    cmp	r4, #6
    bne .Lus_0803E9CC
    movs	r0, #4
    b .Lus_0803E9DA
.Lus_0803E9C8:
    .4byte 0x00002174
.Lus_0803E9CC:
    movs	r0, #3
    b .Lus_0803E9DA
.Lus_0803E9D0:
    cmp	r6, #6
    beq .Lus_0803E9D8
    movs	r0, #1
    b .Lus_0803E9DA
.Lus_0803E9D8:
    movs	r0, #2
.Lus_0803E9DA:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803E9E4
    .thumb_func
func_0803E9E4:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r2, [r4, #3]
    adds	r4, r2, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EA0C
    movs	r0, #5
    b .Lus_0803EA52
.Lus_0803EA0C:
    ldr r1, .Lus_0803EA1C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #25
    cmp	r0, #0
    bge .Lus_0803EA20
    movs	r0, #0
    b .Lus_0803EA52
.Lus_0803EA1C:
    .4byte 0x000021CA
.Lus_0803EA20:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803EA50
    cmp	r4, #6
    bne .Lus_0803EA4C
    ldr r1, .Lus_0803EA44
    adds	r0, r5, r1
    ldr	r0, [r0, #0]
    movs	r1, #194	@ 0xc2
    lsls	r1, r1, #11
    ands	r0, r1
    movs	r1, #130	@ 0x82
    lsls	r1, r1, #11
    cmp	r0, r1
    bne .Lus_0803EA48
    movs	r0, #4
    b .Lus_0803EA52
    .align 2, 0
.Lus_0803EA44:
    .4byte 0x00002174
.Lus_0803EA48:
    movs	r0, #3
    b .Lus_0803EA52
.Lus_0803EA4C:
    movs	r0, #1
    b .Lus_0803EA52
.Lus_0803EA50:
    movs	r0, #2
.Lus_0803EA52:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .section .text.npc_schedule_van_after, "ax", %progbits
    .align 2, 0
    .global func_0803EA98
    .thumb_func
func_0803EA98:
    push	{r4, lr}
    sub	sp, #4
    adds	r1, r0, #0
    ldr r2, .Lus_0803EAB0
    adds	r0, r1, r2
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    cmp	r0, #0
    bge .Lus_0803EAB4
    movs	r0, #0
    b .Lus_0803EAD2
    .align 2, 0
.Lus_0803EAB0:
    .4byte 0x000021CA
.Lus_0803EAB4:
    mov	r4, sp
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803EAD0
    movs	r0, #1
    b .Lus_0803EAD2
.Lus_0803EAD0:
    movs	r0, #2
.Lus_0803EAD2:
    add	sp, #4
    pop	{r4}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EADC
    .thumb_func
func_0803EADC:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803EAF4
    adds	r0, r5, r1
    ldrb	r1, [r0, #0]
    movs	r0, #124	@ 0x7c
    ands	r0, r1
    cmp	r0, #0
    beq .Lus_0803EAF8
    movs	r0, #0
    b .Lus_0803EB38
.Lus_0803EAF4:
    .4byte 0x000021CA
.Lus_0803EAF8:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #2
    bne .Lus_0803EB16
    cmp	r1, #3
    bne .Lus_0803EB16
    movs	r0, #9
    b .Lus_0803EB38
.Lus_0803EB16:
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EB24
    movs	r0, #8
    b .Lus_0803EB38
.Lus_0803EB24:
    cmp	r4, #1
    beq .Lus_0803EB32
    cmp	r4, #3
    beq .Lus_0803EB32
    ldr	r0, [r5, #8]
    cmp	r0, #0
    beq .Lus_0803EB36
.Lus_0803EB32:
    movs	r0, #1
    b .Lus_0803EB38
.Lus_0803EB36:
    movs	r0, #2
.Lus_0803EB38:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB40
    .thumb_func
func_0803EB40:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803EB78
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    blt .Lus_0803EB92
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    cmp	r0, #1
    bne .Lus_0803EB92
    movs	r0, #1
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EB7C
    movs	r0, #4
    b .Lus_0803EB94
.Lus_0803EB78:
    .4byte 0x000021CA
.Lus_0803EB7C:
    cmp	r4, #0
    bne .Lus_0803EB8E
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803EB8A
    movs	r0, #2
    b .Lus_0803EB94
.Lus_0803EB8A:
    movs	r0, #3
    b .Lus_0803EB94
.Lus_0803EB8E:
    movs	r0, #1
    b .Lus_0803EB94
.Lus_0803EB92:
    movs	r0, #0
.Lus_0803EB94:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .global func_0803EB9C
    .thumb_func
func_0803EB9C:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803EBB8
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803EBBC
    movs	r0, #0
    b .Lus_0803EC36
    .align 2, 0
.Lus_0803EBB8:
    .4byte 0x000021CA
.Lus_0803EBBC:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    mov	r8, r0
    ldrb	r4, [r4, #3]
    ldr r1, .Lus_0803EBF0
    adds	r0, r5, r1
    bl GetRivalEventCount__C12Bachelorette
    adds	r7, r0, #0
    cmp	r7, #4
    bls .Lus_0803EC0A
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EBF4
    movs	r0, #9
    b .Lus_0803EC36
.Lus_0803EBF0:
    .4byte 0x00001E28
.Lus_0803EBF4:
    cmp	r4, #4
    bne .Lus_0803EC06
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803EC02
    movs	r0, #6
    b .Lus_0803EC36
.Lus_0803EC02:
    movs	r0, #7
    b .Lus_0803EC36
.Lus_0803EC06:
    movs	r0, #5
    b .Lus_0803EC36
.Lus_0803EC0A:
    adds	r0, r6, #0
    mov	r1, r8
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EC1C
    movs	r0, #8
    b .Lus_0803EC36
.Lus_0803EC1C:
    cmp	r7, #0
    beq .Lus_0803EC34
    cmp	r4, #1
    bne .Lus_0803EC28
    movs	r0, #3
    b .Lus_0803EC36
.Lus_0803EC28:
    cmp	r4, #4
    bne .Lus_0803EC30
    movs	r0, #4
    b .Lus_0803EC36
.Lus_0803EC30:
    movs	r0, #2
    b .Lus_0803EC36
.Lus_0803EC34:
    movs	r0, #1
.Lus_0803EC36:
    add	sp, #4
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
    .global func_0803EC44
    .thumb_func
func_0803EC44:
    push	{r4, r5, r6, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .Lus_0803EC5C
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #27
    cmp	r0, #0
    bge .Lus_0803EC60
    movs	r0, #0
    b .Lus_0803ECB8
    .align 2, 0
.Lus_0803EC5C:
    .4byte 0x000021CA
.Lus_0803EC60:
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EC80
    movs	r0, #4
    b .Lus_0803ECB8
.Lus_0803EC80:
    ldr r0, .Lus_0803ECA0
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetOrder__C7Saibara
    cmp	r0, #0
    beq .Lus_0803ECA4
    adds	r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803ECA4
    movs	r0, #5
    b .Lus_0803ECB8
    .align 2, 0
.Lus_0803ECA0:
    .4byte 0x00001DAC
.Lus_0803ECA4:
    cmp	r6, #4
    bne .Lus_0803ECB6
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803ECB2
    movs	r0, #2
    b .Lus_0803ECB8
.Lus_0803ECB2:
    movs	r0, #3
    b .Lus_0803ECB8
.Lus_0803ECB6:
    movs	r0, #1
.Lus_0803ECB8:
    add	sp, #4
    pop	{r4, r5, r6}
    pop	{r1}
    bx	r1
    .global func_0803ECC0
    .thumb_func
func_0803ECC0:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r6, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803ECE6
    movs	r0, #5
    b .Lus_0803EDC4
.Lus_0803ECE6:
    ldr	r7, [r5, #8]
    ldr r0, .Lus_0803ED28
    adds	r4, r5, r0
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #0
    beq .Lus_0803EDA4
    adds	r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803EDA4
    adds	r0, r4, #0
    bl IsConstructionOrderedToday__C4Gotz
    lsls	r0, r0, #24
    cmp	r0, #0
    bne .Lus_0803EDA4
    subs	r0, r7, #3
    cmp	r0, #1
    bls .Lus_0803EDA4
    adds	r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp	r0, #13
    bhi .Lus_0803EDA4
    lsls	r0, r0, #2
    ldr r1, .Lus_0803ED2C
    adds	r0, r0, r1
    ldr	r0, [r0, #0]
    mov	pc, r0
.Lus_0803ED28:
    .4byte 0x00001F64
.Lus_0803ED2C:
    .4byte .Lus_0803ED30
.Lus_0803ED30:
    .4byte .Lus_0803EDA4
    .4byte .Lus_0803ED68
    .4byte .Lus_0803ED8C
    .4byte .Lus_0803ED90
    .4byte .Lus_0803ED94
    .4byte .Lus_0803ED98
    .4byte .Lus_0803ED98
    .4byte .Lus_0803ED98
    .4byte .Lus_0803ED9C
    .4byte .Lus_0803ED9C
    .4byte .Lus_0803ED9C
    .4byte .Lus_0803EDA0
    .4byte .Lus_0803EDA0
    .4byte .Lus_0803EDA0
.Lus_0803ED68:
    .4byte 0x004921FA
    .4byte 0xF7CD1868
    .4byte 0x2801F8D1
    .4byte 0x2801D006
    .4byte 0x2802D302
    .4byte 0xE011D004
    .4byte 0xE01F2006
    .4byte 0xE01D2007
    .4byte 0xE01B200D
.Lus_0803ED8C:
    .4byte 0xE0192008
.Lus_0803ED90:
    .4byte 0xE0172009
.Lus_0803ED94:
    .4byte 0xE015200E
.Lus_0803ED98:
    .4byte 0xE013200A
.Lus_0803ED9C:
    .4byte 0xE011200B
.Lus_0803EDA0:
    .4byte 0xE00F200C
.Lus_0803EDA4:
    cmp	r6, #5
    bgt .Lus_0803EDB2
    cmp	r6, #4
    bge .Lus_0803EDBA
    cmp	r6, #0
    beq .Lus_0803EDC2
    b .Lus_0803EDB6
.Lus_0803EDB2:
    cmp	r6, #6
    beq .Lus_0803EDBE
.Lus_0803EDB6:
    movs	r0, #1
    b .Lus_0803EDC4
.Lus_0803EDBA:
    movs	r0, #2
    b .Lus_0803EDC4
.Lus_0803EDBE:
    movs	r0, #3
    b .Lus_0803EDC4
.Lus_0803EDC2:
    movs	r0, #4
.Lus_0803EDC4:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EDCC
    .thumb_func
func_0803EDCC:
    push	{r4, r5, r6, r7, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r6, [r4, #1]
    ldrb	r0, [r4, #2]
    adds	r7, r0, #0
    ldrb	r4, [r4, #3]
    adds	r0, r6, #0
    adds	r1, r7, #0
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EDF8
    movs	r0, #5
    b .Lus_0803EE48
.Lus_0803EDF8:
    cmp	r6, #2
    bne .Lus_0803EE18
    cmp	r7, #30
    bne .Lus_0803EE18
    ldr r1, .Lus_0803EE14
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #26
    lsrs	r0, r0, #30
    cmp	r0, #2
    beq .Lus_0803EE18
    movs	r0, #6
    b .Lus_0803EE48
    .align 2, 0
.Lus_0803EE14:
    .4byte 0x000021A2
.Lus_0803EE18:
    ldr r1, .Lus_0803EE28
    adds	r0, r5, r1
    ldrb	r0, [r0, #0]
    lsls	r0, r0, #28
    cmp	r0, #0
    bge .Lus_0803EE2C
    movs	r0, #0
    b .Lus_0803EE48
.Lus_0803EE28:
    .4byte 0x0000215A
.Lus_0803EE2C:
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803EE46
    cmp	r4, #1
    bne .Lus_0803EE3A
    movs	r0, #1
    b .Lus_0803EE48
.Lus_0803EE3A:
    cmp	r4, #3
    bne .Lus_0803EE42
    movs	r0, #2
    b .Lus_0803EE48
.Lus_0803EE42:
    movs	r0, #3
    b .Lus_0803EE48
.Lus_0803EE46:
    movs	r0, #4
.Lus_0803EE48:
    add	sp, #4
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .global func_0803EE50
    .thumb_func
func_0803EE50:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    mov	r4, sp
    adds	r1, r5, #0
    adds	r1, #16
    mov	r0, sp
    bl DecodeGameDayDate
    ldrb	r0, [r4, #1]
    ldrb	r1, [r4, #2]
    ldrb	r4, [r4, #3]
    bl func_0803D644
    lsls	r0, r0, #24
    cmp	r0, #0
    beq .Lus_0803EE76
    movs	r0, #4
    b .Lus_0803EE8A
.Lus_0803EE76:
    cmp	r4, #1
    bne .Lus_0803EE88
    ldr	r0, [r5, #8]
    cmp	r0, #0
    bne .Lus_0803EE84
    movs	r0, #2
    b .Lus_0803EE8A
.Lus_0803EE84:
    movs	r0, #3
    b .Lus_0803EE8A
.Lus_0803EE88:
    movs	r0, #1
.Lus_0803EE8A:
    add	sp, #4
    pop	{r4, r5}
    pop	{r1}
    bx	r1
    .align 2, 0
    .endif
    .endif
    .endif


    @ One native constructor body shared by all four ROM regions.
    @ The C++ trial is not byte-matched; keep genuine Thumb instructions.
    .section .text.world_sprite_groups_constructor, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0
    .global __22EntityAuxiliarySpritesP10GameObject
    .thumb_func
__22EntityAuxiliarySpritesP10GameObject:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    sub	sp, #48	@ 0x30
    mov	r9, r0
    mov	sl, r1
    mov	r6, r9
    stmia	r6!, {r1}
    movs	r7, #2
    add	r0, sp, #32
    mov	r8, r0
    mov	r1, sp
    adds	r1, #36	@ 0x24
    str	r1, [sp, #44]	@ 0x2c
    movs	r5, #0
    adds	r4, r6, #0
.Lworld_sprite_constructor_0:
    str	r5, [r4, #0]
    strh	r5, [r4, #4]
    str	r5, [r4, #8]
    strh	r5, [r4, #12]
    str	r5, [r4, #16]
    strh	r5, [r4, #20]
    str	r5, [r4, #24]
    strh	r5, [r4, #28]
    adds	r0, r6, #0
    adds	r0, #32
    bl InitializeObjTilePoolOwner
    str	r5, [r4, #36]	@ 0x24
    adds	r4, #44	@ 0x2c
    adds	r6, #44	@ 0x2c
    subs	r7, #1
    movs	r0, #1
    negs	r0, r0
    cmp	r7, r0
    bne .Lworld_sprite_constructor_0
    mov	r6, r9
    adds	r6, #136	@ 0x88
    movs	r0, #0
    str	r0, [r6, #0]
    mov	r0, r9
    adds	r0, #156	@ 0x9c
    movs	r4, #1
    strb	r4, [r0, #0]
    mov	r2, sl
    ldr	r0, [r2, #0]
    ldr	r2, [r0, #72]	@ 0x48
    mov	r0, sl
    movs	r1, #15
    bl _call_via_r2
    mov	r3, r8
    strb	r0, [r3, #0]
    adds	r5, r6, #0
    ldr	r2, [r5, #0]
    cmp	r4, r2
    bls .Lworld_sprite_constructor_1
    mov	r0, r9
    adds	r0, #140	@ 0x8c
    adds	r2, #4
    adds	r2, r5, r2
    ldrb	r1, [r3, #0]
    subs	r2, r2, r0
    bl memset
    ldr	r2, [r5, #0]
    adds	r0, r2, #4
    adds	r0, r5, r0
    add	r1, sp, #32
    ldrb	r1, [r1, #0]
    subs	r2, r4, r2
    bl memset
    str	r4, [r5, #0]
    b .Lworld_sprite_constructor_2
.Lworld_sprite_constructor_1:
    mov	r0, r9
    adds	r0, #140	@ 0x8c
    mov	r4, r9
    adds	r4, #141	@ 0x8d
    mov	r2, r8
    ldrb	r1, [r2, #0]
    subs	r2, r4, r0
    bl memset
    ldr	r0, [r5, #0]
    adds	r0, #4
    adds	r0, r5, r0
    subs	r0, r0, r4
    ldr	r1, [r6, #0]
    subs	r1, r1, r0
    str	r1, [r6, #0]
.Lworld_sprite_constructor_2:
    mov	r3, sl
    ldr	r0, [r3, #0]
    ldr	r1, [r0, #104]	@ 0x68
    mov	r0, sl
    bl _call_via_r1
    mov	r8, r0
    movs	r7, #0
.Lworld_sprite_constructor_3:
    movs	r0, #44	@ 0x2c
    adds	r6, r7, #0
    muls	r6, r0
    add	r6, r9
    adds	r4, r6, #4
    ldr r0, .Lworld_sprite_constructor_4
    adds	r2, r7, r0
    mov	r1, r8
    ldr	r5, [r1, #0]
    ldr	r0, [sp, #44]	@ 0x2c
    ldr	r3, [r5, #12]
    bl _call_via_r3
    ldr	r0, [sp, #36]	@ 0x24
    ldrh	r2, [r0, #0]
    mov	r0, sp
    ldr	r3, [r5, #16]
    mov	r1, r8
    bl _call_via_r3
    mov	r0, sp
    mov	r1, sp
    movs	r2, #32
    bl memcpy
    mov	r0, sp
    ldmia	r0!, {r1, r2, r3}
    stmia	r4!, {r1, r2, r3}
    ldmia	r0!, {r1, r2, r3}
    stmia	r4!, {r1, r2, r3}
    ldmia	r0!, {r2, r3}
    stmia	r4!, {r2, r3}
    adds	r4, r6, #0
    adds	r4, #36	@ 0x24
    ldr	r1, [r4, #4]
    adds	r0, r4, #0
    bl ReleaseObjTileHandle
    adds	r0, r4, #0
    movs	r1, #2
    bl AllocateObjTileHandle
    adds	r1, r0, #0
    str	r1, [r4, #4]
    adds	r0, r4, #0
    bl GetObjTileIndex
    strh	r0, [r6, #44]	@ 0x2c
    adds	r7, #1
    cmp	r7, #2
    bls .Lworld_sprite_constructor_3
    mov	r0, r9
    add	sp, #48	@ 0x30
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r1}
    bx	r1
    .align 2, 0
.Lworld_sprite_constructor_4:
    .4byte 0x0000091A

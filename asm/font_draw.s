@ Native shared Thumb implementations not yet matched by ordinary C/C++.
@ Calls use the actual symbols declared in include/font.hh.

	.syntax divided
	.thumb

@ Copy the decoded glyph quadrants which fit the aligned 4bpp buffer.
	.section .text.font_draw_normal,"ax",%progbits
	.align 2, 0
	.globl	DrawCharacterGlyphTo2DGfxBuffer
	.type	 DrawCharacterGlyphTo2DGfxBuffer,function
	.thumb_func
DrawCharacterGlyphTo2DGfxBuffer:
	push	{r4, r5, r6, r7, lr}
	mov	r7, sl
	mov	r6, r9
	mov	r5, r8
	push	{r5, r6, r7}
	add	sp, sp, #-0x8c
	add	r5, r0, #0
	mov	r9, r1
	add	r6, r2, #0
	add	r7, r3, #0
	ldr	r1, [sp, #0xac]
	add	r0, sp, #0x4
	bl	DrawCharacterGlyph
	mov	sl, r0
	sub	r0, r0, #0x1
	cmp	r0, #0x1
	bhi	.Lfont_draw_normal_16	@cond_branch
	lsr	r4, r6, #0x3
	str	r4, [sp, #0x84]
	lsr	r2, r7, #0x3
	lsl	r0, r5, #0x10
	lsr	r0, r0, #0x10
	mov	r8, r0
	lsr	r0, r5, #0x10
	mov	ip, r0
	cmp	r4, r8
	bcs	.Lfont_draw_normal_19	@cond_branch
	cmp	r2, r0
	bcs	.Lfont_draw_normal_19	@cond_branch
	mov	r1, #0x0
	mov	r3, #0x7
	add	r0, r6, #0
	and	r0, r0, r3
	cmp	r0, #0
	bne	.Lfont_draw_normal_20	@cond_branch
	mov	r1, #0x1
.Lfont_draw_normal_20:
	cmp	r1, #0
	beq	.Lfont_draw_normal_22	@cond_branch
	mov	r1, #0x0
	add	r0, r7, #0
	and	r0, r0, r3
	cmp	r0, #0
	bne	.Lfont_draw_normal_23	@cond_branch
	mov	r1, #0x1
.Lfont_draw_normal_23:
	cmp	r1, #0
	beq	.Lfont_draw_normal_22	@cond_branch
	mov	r0, #0x0
	str	r0, [sp, #0x88]
	add	r0, r4, #0x1
	cmp	r0, r8
	bcs	.Lfont_draw_normal_25	@cond_branch
	mov	r1, #0x1
	str	r1, [sp, #0x88]
.Lfont_draw_normal_25:
	mov	r7, #0x0
	add	r5, r2, #0x1
	cmp	r5, ip
	bcs	.Lfont_draw_normal_26	@cond_branch
	mov	r7, #0x1
.Lfont_draw_normal_26:
	mov	r0, r8
	mul	r0, r0, r2
	add	r0, r0, r4
	lsl	r0, r0, #0x5
	mov	r2, r9
	add	r6, r0, r2
	add	r0, sp, #0x4
	add	r1, r6, #0
	mov	r2, #0x8
	bl	CpuFastSet
	cmp	r7, #0
	beq	.Lfont_draw_normal_27	@cond_branch
	mov	r1, r8
	mul	r1, r1, r5
	add	r1, r1, r4
	lsl	r1, r1, #0x5
	add	r1, r1, r9
	add	r0, sp, #0x44
	mov	r2, #0x8
	bl	CpuFastSet
.Lfont_draw_normal_27:
	ldr	r0, [sp, #0x88]
	cmp	r0, #0
	beq	.Lfont_draw_normal_19	@cond_branch
	mov	r1, sl
	cmp	r1, #0x1
	bls	.Lfont_draw_normal_19	@cond_branch
	add	r1, r6, #0
	add	r1, r1, #0x20
	add	r0, sp, #0x24
	mov	r2, #0x8
	bl	CpuFastSet
	cmp	r7, #0
	beq	.Lfont_draw_normal_19	@cond_branch
	mov	r0, r8
	mul	r0, r0, r5
	ldr	r2, [sp, #0x84]
	add	r1, r2, r0
	lsl	r0, r1, #0x5
	mov	r2, r9
	add	r1, r0, r2
	add	r1, r1, #0x20
	add	r0, sp, #0x64
	mov	r2, #0x8
	bl	CpuFastSet
	b	.Lfont_draw_normal_19
.Lfont_draw_normal_I1_396:
.Lfont_draw_normal_22:
	add	r0, sp, #0x4
	str	r0, [sp]
	add	r0, r5, #0
	mov	r1, r9
	add	r2, r6, #0
	add	r3, r7, #0
	bl	DrawCharacterGlyphTo2DGfxBufferUnaligned
.Lfont_draw_normal_I1_413:
.Lfont_draw_normal_19:
	mov	r0, sl
	b	.Lfont_draw_normal_31
.Lfont_draw_normal_I1_421:
.Lfont_draw_normal_16:
	mov	r0, #0x0
.Lfont_draw_normal_I1_426:
.Lfont_draw_normal_31:
	add	sp, sp, #0x8c
	pop	{r3, r4, r5}
	mov	r8, r3
	mov	r9, r4
	mov	sl, r5
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
.Lfont_draw_normal_fe1:
	.size	 DrawCharacterGlyphTo2DGfxBuffer,.Lfont_draw_normal_fe1-DrawCharacterGlyphTo2DGfxBuffer
	.align 2, 0

@ Compose a glyph with the requested foreground/background palette pair.
	.section .text.font_draw_ext,"ax",%progbits
	.align 2, 0
	.globl	DrawCharacterGlyphTo2DGfxBufferExt
	.type	 DrawCharacterGlyphTo2DGfxBufferExt,function
	.thumb_func
DrawCharacterGlyphTo2DGfxBufferExt:
	push	{r4, r5, r6, r7, lr}
	mov	r7, sl
	mov	r6, r9
	mov	r5, r8
	push	{r5, r6, r7}
	add	sp, sp, #-0xa0
	add	r4, r0, #0
	mov	sl, r1
	add	r5, r2, #0
	add	r6, r3, #0
	ldr	r1, [sp, #0xc0]
	add	r0, sp, #0xc
	bl	DrawCharacterGlyph
	str	r0, [sp, #0x8c]
	sub	r0, r0, #0x1
	cmp	r0, #0x1
	bls	.Lfont_draw_ext_CB32
	b	.Lfont_draw_ext_4	@long jump
.Lfont_draw_ext_CB32:
	lsr	r0, r5, #0x3
	mov	ip, r0
	lsr	r3, r6, #0x3
	lsl	r0, r4, #0x10
	lsr	r0, r0, #0x10
	mov	r8, r0
	lsr	r0, r4, #0x10
	add	r7, r0, #0
	cmp	ip, r8
	bcc	.Lfont_draw_ext_CB52
	b	.Lfont_draw_ext_7	@long jump
.Lfont_draw_ext_CB52:
	cmp	r3, r0
	bcc	.Lfont_draw_ext_CB54
	b	.Lfont_draw_ext_7	@long jump
.Lfont_draw_ext_CB54:
	mov	r1, #0x0
	mov	r2, #0x7
	add	r0, r5, #0
	and	r0, r0, r2
	cmp	r0, #0
	bne	.Lfont_draw_ext_8	@cond_branch
	mov	r1, #0x1
.Lfont_draw_ext_8:
	cmp	r1, #0
	bne	.Lfont_draw_ext_CB74
	b	.Lfont_draw_ext_10	@long jump
.Lfont_draw_ext_CB74:
	mov	r1, #0x0
	add	r0, r6, #0
	and	r0, r0, r2
	cmp	r0, #0
	bne	.Lfont_draw_ext_11	@cond_branch
	mov	r1, #0x1
.Lfont_draw_ext_11:
	cmp	r1, #0
	bne	.Lfont_draw_ext_CB92
	b	.Lfont_draw_ext_10	@long jump
.Lfont_draw_ext_CB92:
	mov	r1, #0x0
	mov	r0, ip
	add	r0, r0, #0x1
	cmp	r0, r8
	bcs	.Lfont_draw_ext_13	@cond_branch
	mov	r1, #0x1
.Lfont_draw_ext_13:
	str	r1, [sp, #0x90]
	mov	r0, #0x0
	add	r1, r3, #0x1
	str	r1, [sp, #0x98]
	cmp	r1, r7
	bcs	.Lfont_draw_ext_14	@cond_branch
	mov	r0, #0x1
.Lfont_draw_ext_14:
	str	r0, [sp, #0x94]
	mov	r0, r8
	.code	16
	mul	r0, r0, r3
	.code	16
	add	r3, r0, #0
	mov	r1, ip
	.code	16
	add	r2, r3, r1
	lsl	r2, r2, #0x5
	ldr	r0, [sp, #0xc8]
	.code	16
	ldr	r1, [sp, #0xc4]
	.code	16
	sub	r6, r0, r1
	mov	r0, #0xf
	and	r0, r0, r1
	lsl	r1, r0, #0x4
	orr	r0, r0, r1
	lsl	r1, r0, #0x8
	orr	r0, r0, r1
	lsl	r5, r0, #0x10
	orr	r5, r5, r0
	mov	r0, sl
	.code	16
	add	r7, r2, r0
	add	r4, sp, #0xc
	add	r2, sp, #0x2c
	str	r3, [sp, #0x9c]
	mov	r9, r6
	cmp	r4, r2
	beq	.Lfont_draw_ext_15	@cond_branch
	ldr	r3, .Lfont_draw_ext_44
.Lfont_draw_ext_16:
	ldmia	r4!, {r0}
	add	r1, r0, #0
	and	r1, r1, r3
	lsr	r0, r0, #0x1
	and	r0, r0, r3
	orr	r1, r1, r0
	mul	r1, r1, r6
	add	r1, r5, r1
	add	r1, r1, r0
	stmia	r7!, {r1}
	cmp	r4, r2
	bne	.Lfont_draw_ext_16	@cond_branch
.Lfont_draw_ext_15:
	ldr	r1, [sp, #0x94]
	.code	16
	cmp	r1, #0
	beq	.Lfont_draw_ext_21	@cond_branch
	ldr	r0, [sp, #0x98]
	.code	16
	mov	r2, r8
	mul	r2, r2, r0
	add	r2, r2, ip
	lsl	r2, r2, #0x5
	mov	r7, r9
	mov	r0, #0xf
	ldr	r1, [sp, #0xc4]
	.code	16
	and	r0, r0, r1
	lsl	r1, r0, #0x4
	orr	r0, r0, r1
	lsl	r1, r0, #0x8
	orr	r0, r0, r1
	lsl	r3, r0, #0x10
	orr	r3, r3, r0
	mov	r0, sl
	.code	16
	add	r6, r2, r0
	add	r2, sp, #0x4c
	add	r4, sp, #0x6c
	cmp	r2, r4
	beq	.Lfont_draw_ext_21	@cond_branch
	ldr	r5, .Lfont_draw_ext_44
.Lfont_draw_ext_23:
	ldmia	r2!, {r0}
	add	r1, r0, #0
	and	r1, r1, r5
	lsr	r0, r0, #0x1
	and	r0, r0, r5
	orr	r1, r1, r0
	mul	r1, r1, r7
	add	r1, r3, r1
	add	r1, r1, r0
	stmia	r6!, {r1}
	cmp	r2, r4
	bne	.Lfont_draw_ext_23	@cond_branch
.Lfont_draw_ext_21:
	ldr	r1, [sp, #0x90]
	.code	16
	cmp	r1, #0
	beq	.Lfont_draw_ext_7	@cond_branch
	ldr	r0, [sp, #0x8c]
	.code	16
	cmp	r0, #0x1
	bls	.Lfont_draw_ext_7	@cond_branch
	ldr	r3, [sp, #0x9c]
	.code	16
	add	r3, r3, ip
	lsl	r0, r3, #0x5
	.code	16
	mov	r1, sl
	.code	16
	add	r3, r0, r1
	mov	r7, r9
	mov	r0, #0xf
	ldr	r1, [sp, #0xc4]
	.code	16
	and	r0, r0, r1
	lsl	r1, r0, #0x4
	orr	r0, r0, r1
	lsl	r1, r0, #0x8
	orr	r0, r0, r1
	lsl	r2, r0, #0x10
	orr	r2, r2, r0
	add	r6, r3, #0
	add	r6, r6, #0x20
	add	r5, sp, #0x2c
	add	r4, r5, #0
	add	r4, r4, #0x20
	cmp	r5, r4
	beq	.Lfont_draw_ext_30	@cond_branch
	ldr	r3, .Lfont_draw_ext_44
.Lfont_draw_ext_31:
	ldmia	r5!, {r0}
	add	r1, r0, #0
	and	r1, r1, r3
	lsr	r0, r0, #0x1
	and	r0, r0, r3
	orr	r1, r1, r0
	mul	r1, r1, r7
	add	r1, r2, r1
	add	r1, r1, r0
	stmia	r6!, {r1}
	cmp	r5, r4
	bne	.Lfont_draw_ext_31	@cond_branch
.Lfont_draw_ext_30:
	ldr	r0, [sp, #0x94]
	.code	16
	cmp	r0, #0
	beq	.Lfont_draw_ext_7	@cond_branch
	ldr	r1, [sp, #0x98]
	.code	16
	mov	r0, r8
	.code	16
	mul	r0, r0, r1
	mov	r1, ip
	.code	16
	add	r2, r1, r0
	lsl	r0, r2, #0x5
	.code	16
	mov	r1, sl
	.code	16
	add	r2, r0, r1
	mov	r7, r9
	mov	r0, #0xf
	ldr	r1, [sp, #0xc4]
	.code	16
	and	r0, r0, r1
	lsl	r1, r0, #0x4
	orr	r0, r0, r1
	lsl	r1, r0, #0x8
	orr	r0, r0, r1
	lsl	r4, r0, #0x10
	orr	r4, r4, r0
	add	r6, r2, #0
	add	r6, r6, #0x20
	add	r3, sp, #0x6c
	add	r2, sp, #0x8c
	cmp	r3, r2
	beq	.Lfont_draw_ext_7	@cond_branch
	ldr	r5, .Lfont_draw_ext_44
.Lfont_draw_ext_38:
	ldmia	r3!, {r0}
	add	r1, r0, #0
	and	r1, r1, r5
	lsr	r0, r0, #0x1
	and	r0, r0, r5
	orr	r1, r1, r0
	mul	r1, r1, r7
	add	r1, r4, r1
	add	r1, r1, r0
	stmia	r6!, {r1}
	cmp	r3, r2
	bne	.Lfont_draw_ext_38	@cond_branch
	b	.Lfont_draw_ext_7
.Lfont_draw_ext_45:
	.align	2, 0
.Lfont_draw_ext_44:
	.word	0x11111111
.Lfont_draw_ext_I1_891:
.Lfont_draw_ext_10:
	add	r0, sp, #0xc
	.code	16
	str	r0, [sp]
	ldr	r1, [sp, #0xc4]
	.code	16
	str	r1, [sp, #0x4]
	ldr	r0, [sp, #0xc8]
	str	r0, [sp, #0x8]
	add	r0, r4, #0
	mov	r1, sl
	add	r2, r5, #0
	add	r3, r6, #0
	bl	DrawCharacterGlyphTo2DGfxBufferExtUnaligned
.Lfont_draw_ext_I1_931:
.Lfont_draw_ext_7:
	ldr	r0, [sp, #0x8c]
	b	.Lfont_draw_ext_43
.Lfont_draw_ext_I1_938:
.Lfont_draw_ext_4:
	mov	r0, #0x0
.Lfont_draw_ext_43:
	add	sp, sp, #0xa0
	pop	{r3, r4, r5}
	mov	r8, r3
	mov	r9, r4
	mov	sl, r5
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
.Lfont_draw_ext_fe1:
	.size	 DrawCharacterGlyphTo2DGfxBufferExt,.Lfont_draw_ext_fe1-DrawCharacterGlyphTo2DGfxBufferExt
	.align 2, 0

@ Fill an aligned tile rectangle, or the whole buffer when it is covered.
	.section .text.font_draw_clear_rectangle,"ax",%progbits
	.align 2, 0
	.globl	Clear2DGfxBufferRect
	.type	 Clear2DGfxBufferRect,function
	.thumb_func
Clear2DGfxBufferRect:
	push	{r4, r5, r6, r7, lr}
	mov	r7, r9
	mov	r6, r8
	push	{r6, r7}
	add	sp, sp, #-0x4
	mov	r8, r1
	add	r5, r2, #0
	ldr	r1, [sp, #0x20]
	mov	ip, r1
	ldr	r6, [sp, #0x24]
	ldr	r1, [sp, #0x28]
	mov	r2, #0xf
	and	r1, r1, r2
	lsl	r2, r1, #0x4
	orr	r1, r1, r2
	lsl	r2, r1, #0x8
	orr	r1, r1, r2
	lsl	r2, r1, #0x10
	orr	r2, r2, r1
	mov	r9, r2
	lsl	r1, r0, #0x10
	lsr	r2, r1, #0x10
	lsr	r0, r0, #0x10
	lsl	r1, r2, #0x3
	lsl	r4, r0, #0x3
	cmp	r5, #0
	bne	.Lfont_draw_clear_rectangle_36	@cond_branch
	cmp	r3, #0
	bne	.Lfont_draw_clear_rectangle_36	@cond_branch
	cmp	ip, r1
	bcc	.Lfont_draw_clear_rectangle_36	@cond_branch
	cmp	r6, r4
	bcc	.Lfont_draw_clear_rectangle_36	@cond_branch
	lsl	r0, r0, #0x5
	mul	r2, r2, r0
	mov	r7, r9
	str	r7, [sp]
	lsr	r2, r2, #0x2
	ldr	r0, .Lfont_draw_clear_rectangle_fomt_cpu_fastset_mask_0
	and	r2, r2, r0
	mov	r0, #0x80
	lsl	r0, r0, #0x11
	orr	r2, r2, r0
	mov	r0, sp
	mov	r1, r8
	bl	CpuFastSet
	b	.Lfont_draw_clear_rectangle_35
	.align	2, 0
.Lfont_draw_clear_rectangle_fomt_cpu_fastset_mask_0:
	.word	0x1fffff
.Lfont_draw_clear_rectangle_36:
	cmp	r5, r2
	bcs	.Lfont_draw_clear_rectangle_35	@cond_branch
	cmp	r3, r0
	bcs	.Lfont_draw_clear_rectangle_35	@cond_branch
	mov	r7, ip
	add	r0, r5, r7
	cmp	r0, r1
	bcc	.Lfont_draw_clear_rectangle_39	@cond_branch
	sub	r1, r1, r5
	mov	ip, r1
.Lfont_draw_clear_rectangle_39:
	add	r0, r3, r6
	cmp	r0, r4
	bcc	.Lfont_draw_clear_rectangle_40	@cond_branch
	sub	r6, r4, r3
.Lfont_draw_clear_rectangle_40:
	mov	r1, #0x0
	mov	r4, #0x7
	add	r0, r5, #0
	and	r0, r0, r4
	cmp	r0, #0
	bne	.Lfont_draw_clear_rectangle_41	@cond_branch
	mov	r1, #0x1
.Lfont_draw_clear_rectangle_41:
	cmp	r1, #0
	beq	.Lfont_draw_clear_rectangle_35	@cond_branch
	mov	r1, #0x0
	add	r0, r3, #0
	and	r0, r0, r4
	cmp	r0, #0
	bne	.Lfont_draw_clear_rectangle_43	@cond_branch
	mov	r1, #0x1
.Lfont_draw_clear_rectangle_43:
	cmp	r1, #0
	beq	.Lfont_draw_clear_rectangle_35	@cond_branch
	mov	r1, #0x0
	mov	r0, ip
	and	r0, r0, r4
	cmp	r0, #0
	bne	.Lfont_draw_clear_rectangle_45	@cond_branch
	mov	r1, #0x1
.Lfont_draw_clear_rectangle_45:
	cmp	r1, #0
	beq	.Lfont_draw_clear_rectangle_35	@cond_branch
	mov	r1, #0x0
	add	r0, r6, #0
	and	r0, r0, r4
	cmp	r0, #0
	bne	.Lfont_draw_clear_rectangle_47	@cond_branch
	mov	r1, #0x1
.Lfont_draw_clear_rectangle_47:
	cmp	r1, #0
	beq	.Lfont_draw_clear_rectangle_35	@cond_branch
	lsr	r6, r6, #0x3
	lsr	r0, r3, #0x3
	mul	r0, r0, r2
	lsr	r1, r5, #0x3
	add	r0, r0, r1
	lsl	r0, r0, #0x5
	mov	r1, r8
	add	r5, r1, r0
	lsl	r7, r2, #0x5
	ldr	r4, .Lfont_draw_clear_rectangle_54
	mov	r2, ip
	and	r4, r4, r2
	ldr	r0, .Lfont_draw_clear_rectangle_58
	and	r4, r4, r0
	mov	r0, #0x80
	lsl	r0, r0, #0x11
	mov	r8, r0
.Lfont_draw_clear_rectangle_49:
	mov	r1, r9
	str	r1, [sp]
	mov	r0, sp
	add	r1, r5, #0
	mov	r2, r8
	orr	r2, r2, r4
	bl	CpuFastSet
	add	r5, r5, r7
	sub	r6, r6, #0x1
	cmp	r6, #0
	bne	.Lfont_draw_clear_rectangle_49	@cond_branch
.Lfont_draw_clear_rectangle_35:
	add	sp, sp, #0x4
	pop	{r3, r4}
	mov	r8, r3
	mov	r9, r4
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.Lfont_draw_clear_rectangle_55:
	.align	2, 0
.Lfont_draw_clear_rectangle_54: .word 0x3ffffff8
.Lfont_draw_clear_rectangle_58: .word 0x1fffff
.Lfont_draw_clear_rectangle_fe3:
	.size	 Clear2DGfxBufferRect,.Lfont_draw_clear_rectangle_fe3-Clear2DGfxBufferRect
	.align 2, 0

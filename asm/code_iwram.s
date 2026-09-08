    .section .iwram, "awx"

    .macro inc from, to
    .incbin "baserom_us.gba", 0x75B9F8 + \from - 0x03000490, \to - \from
    .endm

    .global func_03000490
    .type func_03000490, function
    .thumb
func_03000490:
    inc 0x03000490, 0x030004C0

    .global __new_handler
    .type __new_handler, object
__new_handler:
    inc 0x030004C0, 0x030004DC

    .global func_030004DC
    .type func_030004DC, function
    .arm
func_030004DC:
    inc 0x030004DC, 0x03000714

    .global DrawGlyph2Tile
    .type DrawGlyph2Tile, function
    .arm
DrawGlyph2Tile:
    @ r0 is a 24-byte, 16-pixel-wide 1bpp glyph; r1 is the 16x16-tile
    @ scratch buffer. Each source row becomes 4bpp pixels plus its shadow.
    push {r4, r5, r6, r7, r8, r9, sl, lr}
    sub sp, sp, #4
    mov sl, r0
    mov lr, r1
    mov r9, #0
    mov r2, r9
    mov r5, r9
    mov r3, r5
.LDrawGlyph2TileClear:
    str r3, [lr, #32]
    add r5, r5, #1
    str r3, [lr], #4
    cmp r5, #1
    bls .LDrawGlyph2TileClear
.LDrawGlyph2TileLine:
    mov r1, #1
    mov r4, #128
    mov ip, #0
    mov r0, ip
    tst sl, #3
    ldreq r6, [sl]
    lsrne r6, r6, #16
    add sl, sl, #2
    mov r7, r2, lsr #28
    mov r9, r9, lsl #4
    mov r2, r2, lsl #4
    str r2, [sp]
.LDrawGlyph2TilePixel:
    tst r6, r4
    orr r3, ip, r1
    movne ip, r3
    ands r2, r6, r4, lsl #8
    orr r3, r0, r1
    movne r0, r3
    mov r1, r1, lsl #4
    movs r4, r4, lsr #1
    bne .LDrawGlyph2TilePixel
    mov r3, ip, lsr #28
    orr r0, r3, r0, lsl #4
    mov ip, ip, lsl #4
    mov r8, r0, lsl #4
    orr r2, r8, r7
    mov r7, ip, lsr #28
    orr r3, r7, r9
    orr r3, r2, r3
    bic r3, r3, r0
    orr r1, r0, r3, lsl #1
    mov r9, r0
    add r5, r5, #1
    ldr r2, [sp]
    cmp r5, #8
    orr r3, r2, ip, lsl #4
    bic r3, r3, ip
    str r1, [lr, #32]
    orr r3, ip, r3, lsl #1
    str r3, [lr], #4
    mov r2, ip
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #13
    bls .LDrawGlyph2TileLine
    orr r3, r8, r7
    mov r9, r4
    mov r3, r3, lsl #1
    mov r2, r2, lsl #5
    str r3, [lr, #32]
    add r5, r5, #1
    str r2, [lr], #4
    cmp r5, #8
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #15
    bhi .LDrawGlyph2TileDone
    mov r2, r9
.LDrawGlyph2TileBottomPadding:
    str r2, [lr, #32]
    add r5, r5, #1
    str r2, [lr], #4
    cmp r5, #8
    add r3, lr, #32
    moveq lr, r3
    cmp r5, #15
    bls .LDrawGlyph2TileBottomPadding
.LDrawGlyph2TileDone:
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, r9, sl, lr}
    bx lr

    .global func_03000714
    .set func_03000714, DrawGlyph2Tile

    .global DrawGlyph1Tile
    .type DrawGlyph1Tile, function
    .arm
DrawGlyph1Tile:
    @ r0 is a 12-byte, 8-pixel-wide 1bpp glyph; r1 is the same scratch
    @ buffer. The right-hand tile receives the generated shadow pixels.
    push {r4, r5, r6, r7, r8, lr}
    mov r4, r0
    mov r0, #0
    mov r8, r0
    mov r3, r0
.LDrawGlyph1TileClear:
    str r3, [r1, #32]
    add r0, r0, #1
    str r3, [r1], #4
    cmp r0, #1
    bls .LDrawGlyph1TileClear
.LDrawGlyph1TileLine:
    mov lr, #1
    mov r6, #128
    mov ip, #0
    tst r4, #3
    ldreq r5, [r4]
    lsrne r5, r5, #8
    add r4, r4, #1
    mov r7, r8, lsr #28
    mov r2, r8, lsl #4
.LDrawGlyph1TilePixel:
    tst r5, r6
    orr r3, ip, lr
    movne ip, r3
    mov lr, lr, lsl #4
    movs r6, r6, lsr #1
    bne .LDrawGlyph1TilePixel
    mov ip, ip, lsl #4
    orr r3, r2, ip, lsl #4
    bic r3, r3, ip
    mov r8, ip
    mov lr, ip, lsr #28
    orr r2, lr, r7
    mov r2, r2, lsl #1
    orr r3, ip, r3, lsl #1
    str r2, [r1, #32]
    add r0, r0, #1
    str r3, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #13
    bls .LDrawGlyph1TileLine
    mov r3, lr, lsl #1
    mov r2, r8, lsl #5
    mov r8, r6
    str r3, [r1, #32]
    add r0, r0, #1
    str r2, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #15
    bhi .LDrawGlyph1TileDone
    mov r2, r8
.LDrawGlyph1TileBottomPadding:
    str r2, [r1, #32]
    add r0, r0, #1
    str r2, [r1], #4
    cmp r0, #8
    add r3, r1, #32
    moveq r1, r3
    cmp r0, #15
    bls .LDrawGlyph1TileBottomPadding
.LDrawGlyph1TileDone:
    pop {r4, r5, r6, r7, r8, lr}
    bx lr

    .global func_0300085C
    .set func_0300085C, DrawGlyph1Tile

    .global func_03000958
    .type func_03000958, function
    .arm
func_03000958:
    inc 0x03000958, 0x03000A1C

    .global func_03000A1C
    .type func_03000A1C, function
    .arm
func_03000A1C:
    inc 0x03000A1C, 0x03000C08

    .global func_03000C08
    .type func_03000C08, function
    .arm
func_03000C08:
    inc 0x03000C08, 0x03000C2C

    .global func_03000C2C
    .type func_03000C2C, function
    .arm
func_03000C2C:
    inc 0x03000C2C, 0x03000CD4

    .global gUnk_03000CD4
    .type gUnk_03000CD4, object
gUnk_03000CD4: @ new handler
    inc 0x03000CD4, 0x03000CD8

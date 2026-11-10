    .include "asm/macro.inc"
    .syntax unified

    @ Only Unpack uses the ordinary C ABI. Helpers share the bit buffer in
    @ r2/r3, bit count/result in r4, workspace in r7 and state in r8-r11.
    @ The LZ copier also returns through its explicit even continuation labels.
    @ Do not expose these internal register protocols as C declarations.
    .section .text, "ax", %progbits
    .thumb

    thumb_func_start Unpack
Unpack:
    push {r4, r5, r6, r7, lr}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7}
    ldr r2, .L080D11C8 @ =0xFFFFFBE0
    add sp, r2
    mov r7, sp
    ldm r0!, {r4}
    lsrs r4, r4, #8
    push {r4}
    mov r8, r4
    subs r1, #2
    add r8, r1
    movs r2, #0
    adds r3, r2, #0
    movs r4, #8
    bl ReadUnpackBits
    str r4, [r7]
    adds r6, r4, #0
    lsls r4, r4, #0x1b
    lsrs r4, r4, #0x1e
    subs r4, #1
    beq .L080D1068
    subs r4, #1
    beq .L080D106E
    ldr r5, .L080D11CC @ =ReadUnpackRawByte
    b .L080D1076
.L080D1068:
    movs r4, #4
    ldr r5, .L080D11D0 @ =ReadUnpackHuffman4Byte
    b .L080D1072
.L080D106E:
    movs r4, #8
    ldr r5, .L080D11D4 @ =ReadUnpackHuffman8Byte
.L080D1072:
    bl BuildUnpackHuffmanTree
.L080D1076:
    mov sb, r5
    push {r1}
    lsls r6, r6, #0x1d
    lsrs r6, r6, #0x1d
    subs r6, #1
    beq .L080D1094
    subs r6, #1
    beq .L080D109A
    subs r6, #1
    beq .L080D10A0
    subs r6, #1
    beq .L080D10A6
    bl DecodeUnpackLz0
    b .L080D10AA
.L080D1094:
    bl DecodeUnpackLz1
    b .L080D10AA
.L080D109A:
    bl DecodeUnpackLz2
    b .L080D10AA
.L080D10A0:
    bl DecodeUnpackLz3
    b .L080D10AA
.L080D10A6:
    bl DecodeUnpackRawBytes
.L080D10AA:
    pop {r0}
    ldr r4, [r7]
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x1d
    subs r4, #1
    beq .L080D10C4
    subs r4, #1
    beq .L080D10CA
    subs r4, #1
    beq .L080D10D0
    subs r4, #1
    beq .L080D10D6
    b .L080D10DA
.L080D10C4:
    bl UndoUnpackNibbleDelta
    b .L080D10DA
.L080D10CA:
    bl UndoUnpackByteDelta
    b .L080D10DA
.L080D10D0:
    bl UndoUnpackHalfwordDelta
    b .L080D10DA
.L080D10D6:
    bl UndoUnpackByteLaneDelta
.L080D10DA:
    pop {r0}
    ldr r2, .L080D11D8 @ =0x00000420
    add sp, r2
    pop {r4, r5, r6, r7}
    mov r8, r4
    mov sb, r5
    mov sl, r6
    mov fp, r7
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start BuildUnpackHuffmanTree
BuildUnpackHuffmanTree:
    push {r1, r5, r6, lr}
    mov sl, r4
    movs r6, #1
    subs r5, r6, #2
    lsls r6, r4
    adds r4, r5, #0
    adds r1, r7, #0
    adds r1, #0x20
.L080D1100:
    stm r1!, {r4, r5}
    subs r6, #2
    bgt .L080D1100
    movs r4, #0x20
    mov fp, r4
    movs r5, #0
    mov ip, r5
    mov r6, sl
    lsls r6, r6, #1
.L080D1112:
    lsls r5, r5, #1
    mov r4, sl
    bl ReadUnpackBits
    tst r4, r4
    beq .L080D1160
    push {r6}
.L080D1120:
    mov sb, r4
    movs r1, #0x20
    mov r6, ip
    tst r6, r6
    beq .L080D1146
.L080D112A:
    adds r4, r5, #0
    lsrs r4, r6
    lsls r4, r4, #0x1f
    lsrs r4, r4, #0x1e
    adds r4, r4, r1
    ldrsh r1, [r7, r4]
    tst r1, r1
    bpl .L080D1142
    mov r1, fp
    adds r1, #4
    mov fp, r1
    strh r1, [r7, r4]
.L080D1142:
    subs r6, #1
    bne .L080D112A
.L080D1146:
    lsls r6, r5, #0x1f
    lsrs r6, r6, #0x1e
    adds r6, r6, r1
    mov r4, sl
    bl ReadUnpackBits
    mvns r4, r4
    strh r4, [r7, r6]
    adds r5, #1
    mov r4, sb
    subs r4, #1
    bne .L080D1120
    pop {r6}
.L080D1160:
    movs r1, #1
    add ip, r1
    subs r6, #1
    bne .L080D1112
    pop {r1, r5, r6, pc}

    non_word_aligned_thumb_func_start ReadUnpackRawByte
ReadUnpackRawByte:
    movs r4, #8
    b ReadUnpackBits

    non_word_aligned_thumb_func_start ReadUnpackHuffman4Byte
ReadUnpackHuffman4Byte:
    push {r5, r6, lr}
    bl ReadUnpackHuffmanSymbol
    lsls r6, r4, #4
    bl ReadUnpackHuffmanSymbol
    orrs r4, r6
    pop {r5, r6, pc}

    non_word_aligned_thumb_func_start ReadUnpackHuffman8Byte
ReadUnpackHuffman8Byte:
    push {r5, lr}
    bl ReadUnpackHuffmanSymbol
    pop {r5, pc}

    non_word_aligned_thumb_func_start ReadUnpackHuffmanSymbol
ReadUnpackHuffmanSymbol:
    movs r4, #0x20
.L080D1188:
    subs r3, #1
    bmi RefillUnpackHuffmanBits
.L080D118C:
    lsrs r5, r2, #0x1f
    lsls r2, r2, #1
    lsls r5, r5, #1
    adds r5, r5, r4
    ldrsh r4, [r7, r5]
    tst r4, r4
    bpl .L080D1188
    mvns r4, r4
    bx lr

    non_word_aligned_thumb_func_start RefillUnpackHuffmanBits
RefillUnpackHuffmanBits:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D118C
    non_word_aligned_thumb_func_start ReadUnpackBits
ReadUnpackBits:
    push {r5, r6, lr}
    movs r5, #0x20
    subs r5, r5, r4
    adds r6, r2, #0
    lsrs r6, r5
    subs r3, r3, r4
    bmi RefillUnpackBitField
    lsls r2, r4
    adds r4, r6, #0
    pop {r5, r6, pc}

    thumb_func_start RefillUnpackBitField
RefillUnpackBitField:
    ldm r0!, {r2}
    rsbs r5, r3, #0
    adds r4, r2, #0
    lsls r2, r5
    adds r3, #0x20
    lsrs r4, r3
    orrs r4, r6
    pop {r5, r6, pc}
    .align 2, 0
.L080D11C8: .word 0xFFFFFBE0
.L080D11CC: .word ReadUnpackRawByte
.L080D11D0: .word ReadUnpackHuffman4Byte
.L080D11D4: .word ReadUnpackHuffman8Byte
.L080D11D8: .word 0x00000420

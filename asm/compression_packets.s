    .include "asm/macro.inc"
    .syntax unified

    @ Packet and delta decoders share Unpack's internal register ABI.
    @ ReadUnpackBits is a real entry in the stream decoder, not a C call.
    .section .text, "ax", %progbits
    .thumb

    thumb_func_start DecodeUnpackRawBytes
DecodeUnpackRawBytes:
    push {lr}
    mov r6, r8
    subs r6, r6, r1
.L080D120A:
    mov lr, pc
    bx sb
.L080D120E:
    adds r1, #1
    lsls r5, r1, #31
    bmi .L080D121A
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1, #0]
.L080D121A:
    mov sl, r4
    subs r6, #1
    bne .L080D120A
    pop {r4}
    bx r4

    thumb_func_start DecodeUnpackLz0
DecodeUnpackLz0:
    push {lr}
    movs r5, #2
    bl ReadUnpackDistanceLadder
    ldr r4, .L080D150C
    mov ip, r4
.L080D1230:
    movs r4, #2
    bl ReadUnpackBits
    cmp r4, #2
    blo .L080D125C
    beq .L080D1274
    movs r4, #6
    bl ReadUnpackBits
    adds r6, r4, #1
    movs r4, #8
    bl ReadUnpackBits
    adds r1, #1
    lsls r5, r1, #0x1f
    bmi .L080D1256
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1]
.L080D1256:
    mov sl, r4
    movs r5, #1
    b CopyUnpackBackReference
.L080D125C:
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    movs r4, #6
    bl ReadUnpackBits
    adds r6, r4, #3
    b CopyUnpackBackReference
.L080D1274:
    movs r4, #6
    bl ReadUnpackBits
    adds r6, r4, #1
.L080D127C:
    mov lr, pc
    bx sb
.L080D1280:
    adds r1, #1
    lsls r5, r1, #31
    bmi .L080D128C
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1, #0]
.L080D128C:
    mov sl, r4
    subs r6, #1
    bne .L080D127C
.LUnpackLz0Continue:
    cmp r1, r8
    bcc .L080D1230
    pop {r4}
    bx r4

    non_word_aligned_thumb_func_start DecodeUnpackLz1
DecodeUnpackLz1:
    push {lr}
    movs r5, #4
    bl ReadUnpackDistanceLadder
    ldr r4, .L080D1510
    mov ip, r4
.L080D12A6:
    subs r3, #1
    bmi .L080D12E6
.L080D12AA:
    lsls r2, r2, #1
    blo .L080D12CC
    movs r4, #2
    bl ReadUnpackBits
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    movs r4, #4
    bl ReadUnpackBits
    adds r6, r4, #3
    b CopyUnpackBackReference
.L080D12CC:
    mov lr, pc
    bx sb
.L080D12D0:
    adds r1, #1
    lsls r6, r1, #31
    bmi .L080D12DC
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1, #0]
.L080D12DC:
    mov sl, r4
.LUnpackLz1Continue:
    cmp r1, r8
    bcc .L080D12A6
    pop {r4}
    bx r4
.L080D12E6:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D12AA

    thumb_func_start DecodeUnpackLz2
DecodeUnpackLz2:
    push {lr}
    movs r5, #7
    bl ReadUnpackDistanceLadder
    ldr r4, .L080D1514
    mov ip, r4
.L080D12F8:
    subs r3, #1
    bmi .L080D1390
.L080D12FC:
    lsls r2, r2, #1
    blo .L080D1376
    movs r4, #3
    bl ReadUnpackBits
    cmp r4, #7
    beq .L080D1322
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    movs r4, #4
    bl ReadUnpackBits
    adds r6, r4, #3
    b CopyUnpackBackReference
.L080D1322:
    movs r6, #0
.L080D1324:
    movs r4, #4
    bl ReadUnpackBits
    lsls r6, r6, #4
    adds r6, r6, r4
    lsrs r6, r6, #1
    bhs .L080D1324
    subs r3, #1
    bmi .L080D1396
.L080D1336:
    lsls r2, r2, #1
    blo .L080D135C
    movs r4, #3
    bl ReadUnpackBits
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    movs r4, #4
    bl ReadUnpackBits
    lsls r6, r6, #4
    adds r6, r6, r4
    adds r6, #3
    b CopyUnpackBackReference
.L080D135C:
    adds r6, #1
.L080D135E:
    mov lr, pc
    bx sb
.L080D1362:
    adds r1, #1
    lsls r5, r1, #31
    bmi .L080D136E
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1, #0]
.L080D136E:
    mov sl, r4
    subs r6, #1
    bne .L080D135E
    b .LUnpackLz2Continue
.L080D1376:
    mov lr, pc
    bx sb
.L080D137A:
    adds r1, #1
    lsls r5, r1, #31
    bmi .L080D1386
    lsls r4, r4, #8
    add r4, sl
    strh r4, [r1, #0]
.L080D1386:
    mov sl, r4
.LUnpackLz2Continue:
    cmp r1, r8
    bcc .L080D12F8
    pop {r4}
    bx r4
.L080D1390:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D12FC
.L080D1396:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D1336

    thumb_func_start DecodeUnpackLz3
DecodeUnpackLz3:
    push {lr}
    movs r5, #3
    bl ReadUnpackDistanceLadder
.L080D13A4:
    subs r3, #1
    bmi .L080D1450
.L080D13A8:
    lsls r2, r2, #1
    bhs .L080D13C0
    mov lr, pc
    bx sb
.L080D13B0:
    adds r5, r4, #0
    mov lr, pc
    bx sb
    lsls r4, r4, #8
    orrs r4, r5
    adds r1, #2
    strh r4, [r1, #0]
    b .L080D1448
.L080D13C0:
    movs r4, #2
    bl ReadUnpackBits
    cmp r4, #3
    beq .L080D13E4
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    lsls r5, r5, #1
    movs r4, #3
    bl ReadUnpackBits
    adds r6, r4, #2
    b .L080D143A
.L080D13E4:
    movs r6, #0
.L080D13E6:
    movs r4, #3
    bl ReadUnpackBits
    lsls r6, r6, #3
    adds r6, r6, r4
    lsrs r6, r6, #1
    bhs .L080D13E6
    subs r3, #1
    bmi .L080D1456
.L080D13F8:
    lsls r2, r2, #1
    blo .L080D1420
    movs r4, #2
    bl ReadUnpackBits
    lsls r5, r4, #2
    adds r5, r5, r7
    ldrb r4, [r5, #6]
    bl ReadUnpackBits
    ldrh r5, [r5, #4]
    adds r5, r5, r4
    lsls r5, r5, #1
    movs r4, #3
    bl ReadUnpackBits
    lsls r6, r6, #3
    adds r6, r6, r4
    adds r6, #2
    b .L080D143A
.L080D1420:
    adds r6, #1
.L080D1422:
    mov lr, pc
    bx sb
.L080D1426:
    adds r5, r4, #0
    mov lr, pc
    bx sb
    lsls r4, r4, #8
    adds r4, r4, r5
    adds r1, #2
    strh r4, [r1, #0]
    subs r6, #1
    bne .L080D1422
    b .L080D1448
.L080D143A:
    subs r5, r1, r5
.L080D143C:
    adds r5, #2
    ldrh r4, [r5]
    adds r1, #2
    strh r4, [r1]
    subs r6, #1
    bne .L080D143C
.L080D1448:
    cmp r1, r8
    blo .L080D13A4
    pop {r4}
    bx r4
.L080D1450:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D13A8
.L080D1456:
    ldm r0!, {r2}
    adds r3, #0x20
    b .L080D13F8
    .global CopyUnpackBackReference
    .thumb_func
CopyUnpackBackReference:
    mov lr, ip
    push {r2, lr}
    mov r2, sl
    cmp r5, #1
    beq RepeatUnpackPreviousByte
    lsls r4, r5, #0x1f
    bne CopyUnpackOddDistanceBackReference
    subs r5, r1, r5
    lsls r4, r5, #0x1f
    beq .L080D1482
    adds r5, #1
    ldrh r4, [r5]
    lsrs r4, r4, #8
    lsls r4, r4, #8
    orrs r4, r2
    adds r1, #1
    strh r4, [r1]
    subs r6, #1
    beq .L080D1494
.L080D1482:
    adds r5, #2
    ldrh r4, [r5]
    adds r1, #2
    strh r4, [r1]
    subs r6, #2
    bgt .L080D1482
    lsls r4, r4, #0x18
    lsrs r2, r4, #0x18
    adds r1, r1, r6
.L080D1494:
    mov sl, r2
    pop {r2, pc}

    thumb_func_start CopyUnpackOddDistanceBackReference
CopyUnpackOddDistanceBackReference:
    subs r5, r1, r5
    lsls r4, r5, #0x1f
    beq .L080D14AA
    adds r5, #1
    ldrh r2, [r5]
    lsrs r2, r2, #8
    adds r1, #1
    subs r6, #1
    beq .L080D14C2
.L080D14AA:
    subs r1, #1
.L080D14AC:
    adds r5, #2
    ldrh r4, [r5]
    lsls r4, r4, #8
    orrs r4, r2
    adds r1, #2
    strh r4, [r1]
    lsrs r2, r4, #0x10
    subs r6, #2
    bgt .L080D14AC
    adds r6, #1
    adds r1, r1, r6
.L080D14C2:
    mov sl, r2
    pop {r2, pc}

    non_word_aligned_thumb_func_start RepeatUnpackPreviousByte
RepeatUnpackPreviousByte:
    lsls r4, r1, #0x1f
    bpl .L080D14D4
    lsls r4, r2, #8
    orrs r4, r2
    adds r1, #1
    adds r6, #1
    b .L080D14DE
.L080D14D4:
    ldrh r4, [r1]
    lsrs r4, r4, #8
    lsls r2, r4, #8
    orrs r4, r2
.L080D14DC:
    adds r1, #2
.L080D14DE:
    strh r4, [r1]
    subs r6, #2
    bgt .L080D14DC
    lsrs r2, r4, #8
    adds r1, r1, r6
    mov sl, r2
    pop {r2, pc}

    thumb_func_start ReadUnpackDistanceLadder
ReadUnpackDistanceLadder:
    push {r1, r7, lr}
    movs r6, #1
.L080D14F0:
    movs r4, #4
    bl ReadUnpackBits
    adds r4, #1
    strb r4, [r7, #6]
    strh r6, [r7, #4]
    adds r7, #4
    movs r1, #1
    lsls r1, r4
    adds r6, r6, r1
    subs r5, #1
    bne .L080D14F0
    pop {r1, r7, pc}
    .align 2, 0
    @ LZ modes 0/1/2 return from the shared back-reference copier here.
    @ These even labels are popped into pc, not used as Thumb function pointers.
.L080D150C: .word .LUnpackLz0Continue
.L080D1510: .word .LUnpackLz1Continue
.L080D1514: .word .LUnpackLz2Continue

    thumb_func_start UndoUnpackNibbleDelta
UndoUnpackNibbleDelta:
    movs r6, #0xf
    movs r5, #0
.L080D151C:
    ldrh r2, [r0, #2]
    lsrs r1, r2, #4
    lsrs r3, r2, #0xc
    lsrs r4, r2, #8
    adds r1, r1, r5
    adds r2, r2, r1
    adds r3, r3, r2
    adds r5, r4, r3
    ands r1, r6
    ands r2, r6
    ands r5, r6
    lsls r1, r1, #4
    lsls r3, r3, #0xc
    lsls r4, r5, #8
    orrs r1, r2
    orrs r1, r3
    orrs r1, r4
    strh r1, [r0, #2]
    adds r0, #2
    cmp r0, r8
    blo .L080D151C
    bx lr

    thumb_func_start UndoUnpackByteDelta
UndoUnpackByteDelta:
    movs r5, #0xff
    movs r4, #0
.L080D154C:
    ldrh r2, [r0, #2]
    lsrs r3, r2, #8
    adds r2, r2, r4
    ands r2, r5
    adds r4, r3, r2
    lsls r1, r4, #8
    orrs r1, r2
    strh r1, [r0, #2]
    adds r0, #2
    cmp r0, r8
    blo .L080D154C
    bx lr

    thumb_func_start UndoUnpackHalfwordDelta
UndoUnpackHalfwordDelta:
    movs r4, #0
.L080D1566:
    ldrh r2, [r0, #2]
    adds r4, r4, r2
    strh r4, [r0, #2]
    adds r0, #2
    cmp r0, r8
    blo .L080D1566
    bx lr

    thumb_func_start UndoUnpackByteLaneDelta
UndoUnpackByteLaneDelta:
    movs r3, #0xff
    lsls r6, r3, #8
    movs r4, #0
    movs r5, #0
.L080D157C:
    ldrh r2, [r0, #2]
    adds r4, r4, r2
    ands r4, r3
    adds r5, r5, r2
    ands r5, r6
    adds r1, r5, #0
    orrs r1, r4
    strh r1, [r0, #2]
    adds r0, #2
    cmp r0, r8
    blo .L080D157C
    bx lr

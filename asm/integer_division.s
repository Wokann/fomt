    .include "asm/macro.inc"
    .include "six/asm/hw/svc.s"

    .syntax unified
    .text
    .thumb
    .align 2, 0

.LDivideByZero:
    push {lr}
    movs r0, #0
    pop {r1}
    bx r1

    thumb_func_start __divsi3
__divsi3:
    cmp r1, #0
    beq .LDivideByZero
    svc #SVC_DIV
    bx lr

    thumb_func_start __modsi3
__modsi3:
    cmp r1, #0
    beq .LDivideByZero
    svc #SVC_DIV
    adds r0, r1, #0
    bx lr

    non_word_aligned_thumb_func_start __udivsi3
__udivsi3:
    @ The BIOS signed division also works when both operands have bit 31 clear.
    adds r3, r0, #0
    orrs r3, r1
    bpl __divsi3
    cmp r1, #0
    beq .LDivideByZero
    movs r3, #1
    movs r2, #0
    push {r4}
    cmp r0, r1
    blo .LDivDone
    movs r4, #1
    lsls r4, r4, #0x1c
.LDivScaleFour:
    cmp r1, r4
    bhs .LDivStartScaleOne
    cmp r1, r0
    bhs .LDivStartScaleOne
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .LDivScaleFour
.LDivStartScaleOne:
    lsls r4, r4, #3
.LDivScaleOne:
    cmp r1, r4
    bhs .LDivSubtract
    cmp r1, r0
    bhs .LDivSubtract
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .LDivScaleOne
.LDivSubtract:
    cmp r0, r1
    blo .LDivTryHalf
    subs r0, r0, r1
    orrs r2, r3
.LDivTryHalf:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .LDivTryQuarter
    subs r0, r0, r4
    lsrs r4, r3, #1
    orrs r2, r4
.LDivTryQuarter:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .LDivTryEighth
    subs r0, r0, r4
    lsrs r4, r3, #2
    orrs r2, r4
.LDivTryEighth:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .LDivNext
    subs r0, r0, r4
    lsrs r4, r3, #3
    orrs r2, r4
.LDivNext:
    cmp r0, #0
    beq .LDivDone
    lsrs r3, r3, #4
    beq .LDivDone
    lsrs r1, r1, #4
    b .LDivSubtract
.LDivDone:
    adds r0, r2, #0
    pop {r4}
    bx lr

    non_word_aligned_thumb_func_start __umodsi3
__umodsi3:
    adds r3, r0, #0
    orrs r3, r1
    bpl __modsi3
    cmp r1, #0
    beq .LDivideByZero
    movs r3, #1
    cmp r0, r1
    bhs .LModScale
    bx lr

.LModScale:
    push {r4}
    movs r4, #1
    lsls r4, r4, #0x1c
.LModScaleFour:
    cmp r1, r4
    bhs .LModStartScaleOne
    cmp r1, r0
    bhs .LModStartScaleOne
    lsls r1, r1, #4
    lsls r3, r3, #4
    b .LModScaleFour
.LModStartScaleOne:
    lsls r4, r4, #3
.LModScaleOne:
    cmp r1, r4
    bhs .LModSubtract
    cmp r1, r0
    bhs .LModSubtract
    lsls r1, r1, #1
    lsls r3, r3, #1
    b .LModScaleOne
.LModSubtract:
    movs r2, #0
    cmp r0, r1
    blo .LModTryHalf
    subs r0, r0, r1
.LModTryHalf:
    lsrs r4, r1, #1
    cmp r0, r4
    blo .LModTryQuarter
    subs r0, r0, r4
    mov ip, r3
    movs r4, #1
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.LModTryQuarter:
    lsrs r4, r1, #2
    cmp r0, r4
    blo .LModTryEighth
    subs r0, r0, r4
    mov ip, r3
    movs r4, #2
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.LModTryEighth:
    lsrs r4, r1, #3
    cmp r0, r4
    blo .LModNext
    subs r0, r0, r4
    mov ip, r3
    movs r4, #3
    rors r3, r4
    orrs r2, r3
    mov r3, ip
.LModNext:
    mov ip, r3
    cmp r0, #0
    beq .LModFinish
    lsrs r3, r3, #4
    beq .LModFinish
    lsrs r1, r1, #4
    b .LModSubtract
.LModFinish:
    movs r4, #0xe
    lsls r4, r4, #0x1c
    ands r2, r4
    bne .LModRestoreRemainder
    pop {r4}
    bx lr

.LModRestoreRemainder:
    @ Undo excess subtractions from the final partial group of quotient bits.
    mov r3, ip
    movs r4, #3
    rors r3, r4
    tst r2, r3
    beq .LModRestoreQuarter
    lsrs r4, r1, #3
    adds r0, r0, r4
.LModRestoreQuarter:
    mov r3, ip
    movs r4, #2
    rors r3, r4
    tst r2, r3
    beq .LModRestoreHalf
    lsrs r4, r1, #2
    adds r0, r0, r4
.LModRestoreHalf:
    mov r3, ip
    movs r4, #1
    rors r3, r4
    tst r2, r3
    beq .LModDone
    lsrs r4, r1, #1
    adds r0, r0, r4
.LModDone:
    pop {r4}
    bx lr
    .align 2, 0

    .include "asm/macro.inc"
    .syntax unified

    @ HardwareResource(u8 const &): native preallocation and retained entries.
    @ Keep this common four-region body until the full C++ constructor matches.
    .text
    .thumb
    .align 2, 0

    thumb_func_start __16HardwareResourceRCUc
__16HardwareResourceRCUc:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x20
    str r0, [sp, #0x14]
    adds r4, r1, #0
    movs r0, #0x14
    bl __builtin_new
    adds r7, r0, #0
    movs r0, #0
    str r0, [r7]
    str r0, [r7, #4]
    adds r1, r7, #0
    adds r1, #8
    str r0, [r1, #4]
.L080075B0:
    ldrb r6, [r4]
    adds r0, r7, #0
    adds r1, r6, #0
    bl Reserve__23HardwareResourceStorageUi
    subs r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0xff
    bne .L080075C6
    b .L08007706
.L080075C6:
    add r0, sp, #4
    mov r9, r0
.L080075CA:
    mov r0, r9
    bl func_08007128
    mov r0, r9
    bl AllocateHardwarePoolHandle
    str r0, [sp, #8]
.L080075D8:
    ldr r4, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r4, r0
    beq .L08007602
    cmp r4, #0
    beq .L080075F6
    adds r0, r4, #0
    bl func_08007128
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainHardwarePoolHandle
    str r0, [r4, #4]
.L080075F6:
    ldr r0, [r7, #4]
    adds r0, #8
    str r0, [r7, #4]
    subs r6, #1
    str r6, [sp, #0x1c]
    b .L080076EA
.L08007602:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x10]
    ldr r1, [r7]
    subs r0, r4, r1
    asrs r4, r0, #3
    str r4, [sp, #0xc]
    add r2, sp, #0x10
    add r0, sp, #0xc
    cmp r4, #1
    bcs .L0800761A
    adds r0, r2, #0
.L0800761A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0800763A
    lsls r4, r0, #3
    adds r0, r4, #0
    bl malloc
    str r4, [sp, #0x18]
    cmp r0, #0
    bne .L08007636
    adds r0, r4, #0
    bl RetryMemoryAllocation
.L08007636:
    ldr r1, [r7]
    b .L08007640
.L0800763A:
    movs r0, #0
    movs r2, #0
    str r2, [sp, #0x18]
.L08007640:
    adds r5, r0, #0
    mov sl, r5
    adds r5, r1, #0
    mov r4, sl
.L08007648:
    subs r6, #1
    str r6, [sp, #0x1c]
.L08007650:
    cmp r5, r8
    beq .L0800766C
.L08007654:
    cmp r4, #0
    beq .L08007664
    adds r0, r4, #0
    bl func_08007128
    ldr r1, [r5, #4]
    adds r0, r4, #0
    bl RetainHardwarePoolHandle
    str r0, [r4, #4]
.L08007664:
    adds r5, #8
    adds r4, #8
    cmp r5, r8
    bne .L08007654
.L0800766C:
    adds r5, r4, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bne .L0800768E
    cmp r5, #0
    beq .L0800768A
    adds r0, r5, #0
    bl func_08007128
    mov r0, r9
    ldr r1, [r0, #4]
    adds r0, r5, #0
    bl RetainHardwarePoolHandle
    str r0, [r5, #4]
.L0800768A:
    adds r5, #8
    b .L080076B6
.L0800768E:
    adds r6, r0, #0
    adds r4, r5, #0
.L08007696:
    cmp r6, #0
    beq .L080076B4
.L0800769A:
    cmp r4, #0
    beq .L080076AC
    adds r0, r4, #0
    bl func_08007128
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainHardwarePoolHandle
    str r0, [r4, #4]
.L080076AC:
    subs r6, #1
    adds r4, #8
    cmp r6, #0
    bne .L0800769A
.L080076B4:
    adds r5, r4, #0
.L080076B6:
    ldr r6, [r7, #4]
    ldr r4, [r7]
.L080076BA:
    cmp r4, r6
    beq .L080076D4
.L080076BE:
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseHardwarePoolHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._17HardwarePoolOwner
    adds r4, #8
    cmp r4, r6
    bne .L080076BE
.L080076D4:
    ldr r0, [r7]
    cmp r0, #0
    beq .L080076DE
    bl free
.L080076DE:
    ldr r0, [sp, #0x18]
    add r0, sl
    mov r1, sl
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
.L080076EA:
    ldr r1, [sp, #8]
    mov r0, r9
    bl ReleaseHardwarePoolHandle
    mov r0, r9
    movs r1, #2
    bl _._17HardwarePoolOwner
    ldr r2, [sp, #0x1c]
    lsls r0, r2, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0xff
    beq .L08007706
    b .L080075CA
.L08007706:
    ldr r0, [r7]
    str r0, [r7, #0x10]
    ldr r0, [sp, #0x14]
    str r7, [r0]
    add sp, #0x20
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_end __16HardwareResourceRCUc

    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

    .section .text.hardware_allocator_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08007578
func_08007578:
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
    bl func_0800745C
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
    bl func_0800745C
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
    bl func_0800745C
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
    bl func_0800745C
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
    bl func_080073E0
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
    bl func_080073E0
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

    .section .text.hardware_mask_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08007874
func_08007874: @ 0x08007874
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    str r0, [sp, #8]
    ldr r0, .L080079B4 @ =gUnk_03000408
    ldr r4, [r0]
    cmp r4, #0
    beq .L0800788C
    b .L08007992
.L0800788C:
    ldr r0, .L080079B8 @ =0x0000092C
    bl __builtin_new
    mov r8, r0
    str r4, [sp]
    mov r1, r8
    adds r1, #0x20
    mov r2, sp
    adds r2, #4
    str r2, [sp, #0x2c]
    cmp r8, r1
    beq .L080078AC
    movs r2, #0
.L080078A6:
    stm r0!, {r2}
    cmp r0, r1
    bne .L080078A6
.L080078AC:
    mov r0, r8
    adds r0, #0x24
    movs r1, #0x80
    lsls r1, r1, #1
    movs r2, #0
    bl InitializeHardwareSharedStateFreeList
    mov r1, r8
    str r0, [r1, #0x20]
    ldr r1, .L080079BC @ =0x00000824
    add r1, r8
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r1, #1]
    ldr r2, .L080079C0 @ =0x00000828
    add r2, r8
    movs r4, #1
    mov r0, r8
    adds r0, #0x20
    str r0, [sp, #0x20]
    str r1, [sp, #0xc]
    movs r1, #0x92
    lsls r1, r1, #4
    add r1, r8
    str r1, [sp, #0x10]
    ldr r0, .L080079C4 @ =0x00000924
    add r0, r8
    str r0, [sp, #0x14]
    ldr r1, .L080079C8 @ =0x00000928
    add r1, r8
    str r1, [sp, #0x18]
    ldr r0, .L080079CC @ =0x0000092A
    add r0, r8
    str r0, [sp, #0x1c]
    movs r7, #0
    mov ip, r4
    movs r6, #1
    rsbs r6, r6, #0
.L080078FA:
    strb r7, [r2]
    mov r1, ip
    strb r1, [r2, #1]
    adds r0, r2, #4
    movs r3, #1
    adds r2, #0x7c
    str r2, [sp, #0x28]
    subs r4, #1
    str r4, [sp, #0x24]
.L0800790C:
    strb r7, [r0]
    mov r2, ip
    strb r2, [r0, #1]
    adds r2, r0, #4
    movs r1, #1
    adds r0, #0x3c
    mov sb, r0
    subs r3, #1
    mov sl, r3
.L0800791E:
    strb r7, [r2]
    mov r0, ip
    strb r0, [r2, #1]
    adds r0, r2, #4
    movs r3, #1
    adds r4, r2, #0
    adds r4, #0x1c
    subs r5, r1, #1
.L0800792E:
    strb r7, [r0]
    mov r1, ip
    strb r1, [r0, #1]
    adds r1, r0, #4
    movs r2, #1
    adds r0, #0xc
    subs r3, #1
.L0800793C:
    stm r1!, {r7}
    subs r2, #1
    cmp r2, r6
    bne .L0800793C
    cmp r3, r6
    bne .L0800792E
    adds r2, r4, #0
    adds r1, r5, #0
    cmp r1, r6
    bne .L0800791E
    mov r0, sb
    mov r3, sl
    cmp r3, r6
    bne .L0800790C
    ldr r2, [sp, #0x28]
    ldr r4, [sp, #0x24]
    cmp r4, r6
    bne .L080078FA
    movs r0, #0
    ldr r2, [sp, #0x10]
    strh r0, [r2]
    ldr r1, [sp, #0x14]
    str r0, [r1]
    ldr r2, [sp, #0x18]
    strh r0, [r2]
    ldr r1, [sp, #0x1c]
    strh r0, [r1]
    str r0, [sp, #4]
    mov r0, r8
    ldr r2, [sp, #0x20]
    cmp r8, r2
    beq .L08007986
    ldr r1, [sp, #0x2c]
    ldr r3, [r1]
.L08007980:
    stm r0!, {r3}
    cmp r0, r2
    bne .L08007980
.L08007986:
    ldr r0, [sp, #0xc]
    bl Clear__20HardwareTileTree1024
    mov r2, r8
    ldr r0, .L080079B4 @ =gUnk_03000408
    str r2, [r0]
.L08007992:
    ldr r0, .L080079B4 @ =gUnk_03000408
    ldr r1, [r0]
    ldr r2, .L080079C4 @ =0x00000924
    adds r1, r1, r2
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    ldr r0, [sp, #8]
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080079B4: .4byte gUnk_03000408
.L080079B8: .4byte 0x0000092C
.L080079BC: .4byte 0x00000824
.L080079C0: .4byte 0x00000828
.L080079C4: .4byte 0x00000924
.L080079C8: .4byte 0x00000928
.L080079CC: .4byte 0x0000092A
    .section .text.hardware_refcount_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08007A28
func_08007A28: @ 0x08007A28
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    str r1, [sp]
    str r2, [sp, #4]
    ldr r0, .L08007B44 @ =gUnk_03000408
    ldr r5, [r0]
    ldr r0, .L08007B48 @ =0x0000092A
    adds r4, r5, r0
    ldrh r0, [r4]
    cmp r0, #0
    beq .L08007A5A
    ldr r1, .L08007B4C @ =0x00000824
    adds r0, r5, r1
    ldr r2, .L08007B50 @ =0x00000928
    adds r1, r5, r2
    ldrh r1, [r1]
    ldrh r2, [r4]
    bl Unreserve__20HardwareTileTree1024UiUi
    movs r0, #0
    strh r0, [r4]
.L08007A5A:
    ldr r0, [sp, #4]
    cmp r0, #0
    beq .L08007B32
    ldr r1, [sp]
    adds r1, r1, r0
    str r1, [sp, #8]
    movs r7, #0
    movs r2, #0x92
    lsls r2, r2, #4
    adds r0, r5, r2
    ldrh r1, [r0]
    str r4, [sp, #0x14]
    subs r2, #0xfc
    adds r2, r5, r2
    str r2, [sp, #0xc]
    ldr r2, .L08007B50 @ =0x00000928
    adds r2, r5, r2
    str r2, [sp, #0x10]
    mov sl, r0
    cmp r1, #0
    beq .L08007B18
    movs r0, #0x24
    adds r0, r0, r5
    mov r8, r0
    mov r6, r8
.L08007A8C:
    movs r0, #0
    cmp r7, #0xff
    bhi .L08007AAA
    lsrs r1, r7, #5
    lsls r1, r1, #2
    adds r1, r5, r1
    movs r0, #0x1f
    ands r0, r7
    movs r2, #1
    lsls r2, r0
    ldr r1, [r1]
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
.L08007AAA:
    cmp r0, #0
    beq .L08007B04
    ldrh r0, [r6]
    lsls r4, r0, #0x16
    lsrs r3, r4, #0x16
    ldrb r0, [r6, #1]
    lsls r2, r0, #0x1a
    lsrs r1, r2, #0x1c
    movs r0, #1
    mov sb, r0
    lsls r0, r1
    adds r0, r3, r0
    ldr r1, [sp]
    cmp r1, r0
    bhs .L08007B04
    ldr r0, [sp, #8]
    cmp r3, r0
    bhs .L08007B04
    adds r1, r3, #0
    lsrs r2, r2, #0x1c
    ldr r0, [sp, #0xc]
    bl Free__20HardwareTileTree1024UiUi
    movs r0, #0
    strh r0, [r6, #4]
    ldr r0, [r5, #0x20]
    str r0, [r6]
    mov r1, r8
    str r1, [r5, #0x20]
    cmp r7, #0xff
    bhi .L08007AFC
    lsrs r2, r7, #5
    lsls r2, r2, #2
    adds r2, r5, r2
    movs r0, #0x1f
    ands r0, r7
    mov r1, sb
    lsls r1, r0
    ldr r0, [r2]
    bics r0, r1
    str r0, [r2]
.L08007AFC:
    mov r2, sl
    ldrh r0, [r2]
    subs r0, #1
    strh r0, [r2]
.L08007B04:
    adds r6, #8
    movs r0, #8
    add r8, r0
    adds r7, #1
    mov r1, sl
    ldrh r0, [r1]
    cmp r0, #0
    beq .L08007B18
    cmp r7, #0xff
    bls .L08007A8C
.L08007B18:
    ldr r0, [sp, #0xc]
    ldr r1, [sp]
    ldr r2, [sp, #4]
    bl Reserve__20HardwareTileTree1024UiUi
    mov r2, sp
    ldrh r0, [r2]
    ldr r2, [sp, #0x10]
    strh r0, [r2]
    mov r1, sp
    ldrh r2, [r1, #4]
    ldr r1, [sp, #0x14]
    strh r2, [r1]
.L08007B32:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08007B44: .4byte gUnk_03000408
.L08007B48: .4byte 0x0000092A
.L08007B4C: .4byte 0x00000824
.L08007B50: .4byte 0x00000928

    .section .text.hardware_state_properties_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08008190
func_08008190:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    movs r0, #0xa0
    bl __builtin_new
    str r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r3, #7
    movs r2, #0
    movs r4, #1
    negs r4, r4
.L080081B2:
    str r2, [r1]
    str r2, [r1, #4]
    adds r0, r1, #0
    adds r0, #8
    str r2, [r0, #4]
    adds r1, #0x14
    subs r3, #1
    cmp r3, r4
    bne .L080081B2
    movs r0, #0
    str r0, [sp, #0x20]
.L080081C8:
    ldr r1, [sp, #0x18]
    ldr r2, [sp, #0x20]
    adds r0, r1, r2
    lsls r1, r2, #2
    adds r1, r1, r2
    lsls r1, r1, #2
    ldr r2, [sp, #0x1c]
    adds r7, r1, r2
    ldrb r6, [r0]
    adds r0, r7, #0
    adds r1, r6, #0
    bl Reserve__18HardwareStateGroupUi
    subs r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, [sp, #0x20]
    adds r0, #1
    str r0, [sp, #0x24]
    cmp r6, #0xff
    bne .L080081F4
    b .L08008336
.L080081F4:
    add r1, sp, #4
    mov r9, r1
.L080081F8:
    mov r0, r9
    bl func_08007874
    mov r0, r9
    ldr r1, [sp, #0x20]
    bl AllocateHardwareSharedStateHandle
    str r0, [sp, #8]
    ldr r4, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r4, r0
    beq .L08008232
.L08008210:
    cmp r4, #0
    beq .L08008226
    adds r0, r4, #0
    bl func_08007874
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainHardwareSharedStateHandle
    str r0, [r4, #4]
.L08008226:
    ldr r0, [r7, #4]
    adds r0, #8
    str r0, [r7, #4]
    subs r6, #1
    str r6, [sp, #0x28]
    b .L0800831A
.L08008232:
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
    bcs .L0800824A
    adds r0, r2, #0
.L0800824A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0800826A
    lsls r4, r0, #3
    adds r0, r4, #0
    bl malloc
    str r4, [sp, #0x2c]
    cmp r0, #0
    bne .L08008266
    adds r0, r4, #0
    bl RetryMemoryAllocation
.L08008266:
    ldr r1, [r7]
    b .L08008270
.L0800826A:
    movs r0, #0
    movs r2, #0
    str r2, [sp, #0x2c]
.L08008270:
    adds r5, r0, #0
    mov sl, r5
    adds r5, r1, #0
    mov r4, sl
.L0800827C:
    subs r6, #1
    str r6, [sp, #0x28]
.L08008280:
    cmp r5, r8
    beq .L0800829C
.L08008284:
    cmp r4, #0
    beq .L08008294
    adds r0, r4, #0
    bl func_08007874
    ldr r1, [r5, #4]
    adds r0, r4, #0
    bl RetainHardwareSharedStateHandle
    str r0, [r4, #4]
.L08008294:
    adds r5, #8
    adds r4, #8
    cmp r5, r8
    bne .L08008284
.L0800829C:
    adds r5, r4, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bne .L080082BE
    cmp r5, #0
    beq .L080082BA
    adds r0, r5, #0
    bl func_08007874
    mov r0, r9
    ldr r1, [r0, #4]
    adds r0, r5, #0
    bl RetainHardwareSharedStateHandle
    str r0, [r5, #4]
.L080082BA:
    adds r5, #8
    b .L080082E6
.L080082BE:
    adds r6, r0, #0
    adds r4, r5, #0
.L080082C2:
    cmp r6, #0
    beq .L080082E4
.L080082C6:
    cmp r4, #0
    beq .L080082DC
    adds r0, r4, #0
    bl func_08007874
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainHardwareSharedStateHandle
    str r0, [r4, #4]
.L080082DC:
    subs r6, #1
    adds r4, #8
    cmp r6, #0
    bne .L080082C6
.L080082E4:
    adds r5, r4, #0
.L080082E6:
    ldr r6, [r7, #4]
    ldr r4, [r7]
.L080082EA:
    cmp r4, r6
    beq .L08008304
.L080082EE:
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl ReleaseHardwareSharedStateHandle
    adds r0, r4, #0
    movs r1, #2
    bl func_080079E8
    adds r4, #8
    cmp r4, r6
    bne .L080082EE
.L08008304:
    ldr r0, [r7]
    cmp r0, #0
    beq .L0800830E
    bl free
.L0800830E:
    ldr r0, [sp, #0x2c]
    add r0, sl
    mov r1, sl
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
.L0800831A:
    ldr r1, [sp, #8]
    mov r0, r9
    bl ReleaseHardwareSharedStateHandle
    mov r0, r9
    movs r1, #2
    bl func_080079E8
    ldr r2, [sp, #0x28]
    lsls r0, r2, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0xff
    beq .L08008336
    b .L080081F8
.L08008336:
    ldr r0, [r7]
    str r0, [r7, #0x10]
    ldr r0, [sp, #0x24]
    str r0, [sp, #0x20]
    cmp r0, #7
    bhi .L08008344
    b .L080081C8
.L08008344:
    ldr r1, [sp, #0x1c]
    ldr r2, [sp, #0x14]
    str r1, [r2]
    adds r0, r2, #0
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    .section .text.hardware_blend_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_080093AC
func_080093AC: @ 0x080093AC
    push {r4, r5, r6, r7, lr}
    ldr r5, [r0]
    movs r0, #4
    ldrsh r7, [r5, r0]
    cmp r7, #0
    beq .L0800949C
    ldrh r4, [r5, #0xe]
    ldr r0, [r5, #8]
    cmp r0, #0
    beq .L08009422
    movs r6, #0
    cmp r0, #1
    beq .L080093CE
    cmp r0, #2
    bne .L080093D0
    movs r6, #0xc0
    b .L080093D0
.L080093CE:
    movs r6, #0x80
.L080093D0:
    ldr r3, [r5]
    cmp r3, #0
    beq .L080093DC
    adds r2, r3, #0
    adds r2, #0x50
    b .L080093DE
.L080093DC:
    ldr r2, .L080093F4 @ =0x04000050
.L080093DE:
    ldrh r1, [r2]
    ldr r0, .L080093F8 @ =0x0000FF3F
    ands r0, r1
    orrs r0, r6
    strh r0, [r2]
    cmp r3, #0
    beq .L080093FC
    adds r1, r3, #0
    adds r1, #0x54
    b .L080093FE
    .align 2, 0
.L080093F4: .4byte 0x04000050
.L080093F8: .4byte 0x0000FF3F
.L080093FC:
    ldr r1, .L08009408 @ =0x04000054
.L080093FE:
    ldr r0, .L0800940C @ =0x0000FFFE
    cmp r4, r0
    bls .L08009410
    movs r0, #0x10
    b .L08009420
    .align 2, 0
.L08009408: .4byte 0x04000054
.L0800940C: .4byte 0x0000FFFE
.L08009410:
    cmp r4, #0
    bne .L08009418
    movs r0, #0
    b .L08009420
.L08009418:
    lsls r0, r4, #4
    subs r0, r0, r4
    lsrs r0, r0, #0x10
    adds r0, #1
.L08009420:
    strh r0, [r1]
.L08009422:
    ldrb r0, [r5, #0xc]
    cmp r0, #0
    beq .L08009460
    ldr r0, .L08009434 @ =0x0000FFFE
    cmp r4, r0
    bls .L08009438
    movs r1, #0xf
    b .L0800944A
    .align 2, 0
.L08009434: .4byte 0x0000FFFE
.L08009438:
    cmp r4, #0
    bne .L08009440
    movs r1, #0
    b .L0800944A
.L08009440:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #1
    lsrs r0, r0, #0x10
    adds r1, r0, #1
.L0800944A:
    lsls r0, r1, #4
    orrs r1, r0
    lsls r0, r1, #8
    orrs r1, r0
    ldr r0, [r5]
    cmp r0, #0
    beq .L0800945C
    adds r0, #0x4c
    b .L0800945E
.L0800945C:
    ldr r0, .L0800946C @ =0x0400004C
.L0800945E:
    strh r1, [r0]
.L08009460:
    cmp r7, #0
    blt .L08009474
    ldr r0, .L08009470 @ =0x0000FFFF
    cmp r4, r0
    beq .L08009478
    b .L0800947E
    .align 2, 0
.L0800946C: .4byte 0x0400004C
.L08009470: .4byte 0x0000FFFF
.L08009474:
    cmp r4, #0
    bne .L0800947E
.L08009478:
    movs r0, #0
    strh r0, [r5, #4]
    b .L0800949E
.L0800947E:
    adds r0, r4, r7
    cmp r0, #0
    bge .L08009488
    movs r0, #0
    b .L08009490
.L08009488:
    ldr r1, .L08009498 @ =0x0000FFFF
    cmp r0, r1
    ble .L08009490
    adds r0, r1, #0
.L08009490:
    strh r0, [r5, #0xe]
    movs r0, #1
    b .L0800949E
    .align 2, 0
.L08009498: .4byte 0x0000FFFF
.L0800949C:
    movs r0, #0
.L0800949E:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

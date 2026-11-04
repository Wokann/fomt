    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"
    .SYNTAX UNIFIED

    .section .text.hardware_state_properties_after, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start InitializeHardwareStateOwnerGroups
InitializeHardwareStateOwnerGroups:
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
    bl InitializeObjTilePoolOwner
    mov r0, r9
    ldr r1, [sp, #0x20]
    bl AllocateObjTileHandle
    str r0, [sp, #8]
    ldr r4, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r4, r0
    beq .L08008232
.L08008210:
    cmp r4, #0
    beq .L08008226
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainObjTileHandle
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
    bl InitializeObjTilePoolOwner
    ldr r1, [r5, #4]
    adds r0, r4, #0
    bl RetainObjTileHandle
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
    bl InitializeObjTilePoolOwner
    mov r0, r9
    ldr r1, [r0, #4]
    adds r0, r5, #0
    bl RetainObjTileHandle
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
    bl InitializeObjTilePoolOwner
    mov r2, r9
    ldr r1, [r2, #4]
    adds r0, r4, #0
    bl RetainObjTileHandle
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
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
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
    bl ReleaseObjTileHandle
    mov r0, r9
    movs r1, #2
    bl _._16ObjTilePoolOwner
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

    thumb_func_start Update__23HardwareBlendController
Update__23HardwareBlendController:
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
    movs r6, #BLD_MODE_BLACK
    b .L080093D0
.L080093CE:
    movs r6, #BLD_MODE_WHITE
.L080093D0:
    ldr r3, [r5]
    cmp r3, #0
    beq .L080093DC
    adds r2, r3, #0
    adds r2, #OFF_BLDCNT
    b .L080093DE
.L080093DC:
    ldr r2, .L080093F4 @ =REG_BLDCNT
.L080093DE:
    ldrh r1, [r2]
    ldr r0, .L080093F8 @ =(0xFFFF & ~(((1 << BF_BLD_MODE_LENGTH) - 1) << BF_BLD_MODE_OFFSET))
    ands r0, r1
    orrs r0, r6
    strh r0, [r2]
    cmp r3, #0
    beq .L080093FC
    adds r1, r3, #0
    adds r1, #OFF_BLDCOEFF
    b .L080093FE
    .align 2, 0
.L080093F4: .word REG_BLDCNT
.L080093F8: .word (0xFFFF & ~(((1 << BF_BLD_MODE_LENGTH) - 1) << BF_BLD_MODE_OFFSET))
.L080093FC:
    ldr r1, .L08009408 @ =REG_BLDCOEFF
.L080093FE:
    ldr r0, .L0800940C @ =0x0000FFFE
    cmp r4, r0
    bls .L08009410
    movs r0, #0x10
    b .L08009420
    .align 2, 0
.L08009408: .word REG_BLDCOEFF
.L0800940C: .word 0x0000FFFE
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
.L08009434: .word 0x0000FFFE
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
    adds r0, #OFF_MOSAIC
    b .L0800945E
.L0800945C:
    ldr r0, .L0800946C @ =REG_MOSAIC
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
.L0800946C: .word REG_MOSAIC
.L08009470: .word 0x0000FFFF
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
.L08009498: .word 0x0000FFFF
.L0800949C:
    movs r0, #0
.L0800949E:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

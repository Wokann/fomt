    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"
    .SYNTAX UNIFIED

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
    movs r1, #((1 << BF_MOSAIC_BG_H_LENGTH) - 1)
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
    lsls r0, r1, #BF_MOSAIC_BG_V_OFFSET
    orrs r1, r0
    lsls r0, r1, #BF_MOSAIC_OBJ_H_OFFSET
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

    .include "six/asm/hw/video.s"
    .syntax unified
    .thumb
    .section .text, "ax", %progbits
    .align 2, 0

    @ Packed RGB flash setup; the three channels are packed by VM 0x127.
    @ This verified common native body remains assembly, not recovered C++.
    .global FlashScreenColor__9GameSceneUi
    .type FlashScreenColor__9GameSceneUi, %function
    .thumb_func
FlashScreenColor__9GameSceneUi:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x54
    ldr r5, [r0, #4]
    adds r0, r5, #0
    adds r0, #0xea
    movs r4, #1
    strb r4, [r0]
    adds r3, r5, #0
    adds r3, #0xec
    strh r1, [r3]
    adds r2, r5, #0
    adds r2, #0x10
    ldrh r0, [r5, #0x10]
    movs r6, #0x80
    lsls r6, r6, #1
    adds r1, r6, #0
    orrs r0, r1
    strh r0, [r5, #0x10]
    mov r1, sp
    ldr r0, .L080147A4 @ =0x00001F0C
    strh r0, [r1]
    strh r0, [r5, #0x18]
    mov r0, sp
    movs r7, #0
    strh r7, [r0]
    movs r0, #0
    strh r0, [r2, #0x10]
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    strh r1, [r5, #0x22]
    ldrh r1, [r3]
    mov r8, r5
    add r0, sp, #4
    ldr r2, .L080147A8
    movs r3, #2
    bl __21DmaTransferDescriptorUiPvUi
    add r2, sp, #4
    mov sb, r2
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080147AC
    cmp r1, #0
    beq .L0801476C
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r3, r4, r6}
    stm r0!, {r3, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
.L0801476C:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    movs r7, #3
    lsls r7, r7, #9
    str r7, [sp, #0x38]
    movs r0, #0
    str r0, [sp, #0x3c]
    movs r1, #0x1f
    lsls r1, r1, #0xb
    str r1, [sp, #0x40]
    adds r2, r5, #0
    adds r2, #0x60
    str r2, [sp, #0x44]
    adds r3, r5, #0
    adds r3, #0xee
    str r3, [sp, #0x30]
    adds r4, r5, #0
    adds r4, #0x62
    str r4, [sp, #0x48]
    adds r6, r5, #0
    adds r6, #0xef
    str r6, [sp, #0x34]
    adds r7, r5, #0
    adds r7, #0x9c
    str r7, [sp, #0x2c]
    b .L080148A0
    .align 2, 0
.L080147A4: .4byte 0x00001F0C
.L080147A8: .word BG_PALETTE + 2
.L080147AC:
    str r1, [sp, #0x4c]
    str r4, [sp, #0x18]
    ldr r0, [r5]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x14]
    add r1, sp, #0x18
    add r0, sp, #0x14
    cmp r4, #1
    bhs .L080147C2
    adds r0, r1, #0
.L080147C2:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080147E0
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L080147E4
    mov r0, sl
    bl RetryMemoryAllocation
    b .L080147E4
.L080147E0:
    movs r0, #0
    mov sl, r0
.L080147E4:
    adds r4, r0, #0
    str r4, [sp, #0x50]
    mov r3, r8
    ldr r2, [r3]
    adds r3, r4, #0
    movs r4, #3
    lsls r4, r4, #9
    str r4, [sp, #0x38]
    movs r6, #0
    lsls r6, r6, #0xc
    str r6, [sp, #0x3c]
    movs r7, #0x1f
    lsls r7, r7, #0xb
    str r7, [sp, #0x40]
    adds r0, r5, #0
    adds r0, #0x60
    str r0, [sp, #0x44]
    adds r1, r5, #0
    adds r1, #0xee
    str r1, [sp, #0x30]
    adds r4, r5, #0
    adds r4, #0x62
    str r4, [sp, #0x48]
    adds r6, r5, #0
    adds r6, #0xef
    str r6, [sp, #0x34]
    adds r7, r5, #0
    adds r7, #0x9c
    str r7, [sp, #0x2c]
    b .L08014834
.L08014820:
    cmp r3, #0
    beq .L08014830
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08014830:
    adds r2, #0x10
    adds r3, #0x10
.L08014834:
    ldr r0, [sp, #0x4c]
    cmp r2, r0
    bne .L08014820
    adds r4, r3, #0
    ldr r0, [sp, #0x18]
    cmp r0, #1
    bne .L08014856
    cmp r4, #0
    beq .L08014852
    adds r0, r4, #0
    mov r1, sb
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08014852:
    adds r4, #0x10
    b .L08014878
.L08014856:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08014876
.L0801485E:
    cmp r2, #0
    beq .L0801486E
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0801486E:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L0801485E
.L08014876:
    adds r4, r2, #0
.L08014878:
    mov r7, r8
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0801488A
.L08014884:
    adds r1, #0x10
    cmp r1, r2
    bne .L08014884
.L0801488A:
    cmp r0, #0
    beq .L08014892
    bl free
.L08014892:
    ldr r0, [sp, #0x50]
    add r0, sl
    ldr r1, [sp, #0x50]
    mov r2, r8
    str r1, [r2]
    str r4, [r2, #4]
    str r0, [r2, #0xc]
.L080148A0:
    ldr r1, .L080148E0 @ =0x11111111
    ldr r3, [sp, #0x38]
    movs r4, #0xf4
    lsls r4, r4, #1
    adds r2, r3, r4
    mov r8, r5
    lsls r2, r2, #5
    movs r6, #0xc0
    lsls r6, r6, #0x13
    adds r2, r2, r6
    mov r0, sp
    movs r3, #0x20
    bl __21DmaTransferDescriptorUiPvUi
    mov sl, sp
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080148E4
    cmp r1, #0
    beq .L080148D6
    adds r0, r1, #0
    mov r1, sp
    ldm r1!, {r2, r3, r7}
    stm r0!, {r2, r3, r7}
    ldr r1, [r1]
    str r1, [r0]
.L080148D6:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L080149B0
    .align 2, 0
.L080148E0: .4byte 0x11111111
.L080148E4:
    str r1, [sp, #0x4c]
    movs r0, #1
    str r0, [sp, #0x20]
    ldr r0, [r5]
    adds r4, r1, #0
    subs r0, r4, r0
    asrs r4, r0, #4
    str r4, [sp, #0x1c]
    add r1, sp, #0x20
    add r0, sp, #0x1c
    cmp r4, #1
    bhs .L080148FE
    adds r0, r1, #0
.L080148FE:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0801491C
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L08014920
    mov r0, sb
    bl RetryMemoryAllocation
    b .L08014920
.L0801491C:
    movs r0, #0
    mov sb, r0
.L08014920:
    adds r4, r0, #0
    str r4, [sp, #0x50]
    mov r6, r8
    ldr r2, [r6]
    adds r3, r4, #0
    ldr r7, [sp, #0x4c]
    cmp r2, r7
    beq .L0801494A
.L08014930:
    cmp r3, #0
    beq .L08014940
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08014940:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [sp, #0x4c]
    cmp r2, r0
    bne .L08014930
.L0801494A:
    adds r4, r3, #0
    ldr r0, [sp, #0x20]
    cmp r0, #1
    bne .L08014966
    cmp r4, #0
    beq .L08014962
    adds r0, r4, #0
    mov r1, sl
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08014962:
    adds r4, #0x10
    b .L08014988
.L08014966:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08014986
.L0801496E:
    cmp r2, #0
    beq .L0801497E
    adds r0, r2, #0
    mov r1, sl
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L0801497E:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L0801496E
.L08014986:
    adds r4, r2, #0
.L08014988:
    mov r7, r8
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .L0801499A
.L08014994:
    adds r1, #0x10
    cmp r1, r2
    bne .L08014994
.L0801499A:
    cmp r0, #0
    beq .L080149A2
    bl free
.L080149A2:
    ldr r0, [sp, #0x50]
    add r0, sb
    ldr r1, [sp, #0x50]
    mov r2, r8
    str r1, [r2]
    str r4, [r2, #4]
    str r0, [r2, #0xc]
.L080149B0:
    movs r3, #0xf0
    lsls r3, r3, #8
    adds r0, r3, #0
    ldr r1, [sp, #0x3c]
    ands r1, r0
    movs r4, #0xf4
    lsls r4, r4, #1
    orrs r1, r4
    lsls r0, r1, #0x10
    orrs r1, r0
    ldr r6, [sp, #0x40]
    movs r7, #0xc0
    lsls r7, r7, #0x13
    adds r2, r6, r7
    mov r0, sp
    movs r3, #0xa0
    lsls r3, r3, #3
    bl __21DmaTransferDescriptorUiPvUi
    mov sb, sp
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080149F8
    cmp r1, #0
    beq .L080149F0
    adds r0, r1, #0
    mov r1, sp
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L080149F0:
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L08014AB8
.L080149F8:
    mov sl, r1
    movs r0, #1
    str r0, [sp, #0x28]
    ldr r0, [r5]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x24]
    add r1, sp, #0x28
    add r0, sp, #0x24
    cmp r4, #1
    bhs .L08014A10
    adds r0, r1, #0
.L08014A10:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08014A2E
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .L08014A32
    mov r0, r8
    bl RetryMemoryAllocation
    b .L08014A32
.L08014A2E:
    movs r0, #0
    mov r8, r0
.L08014A32:
    adds r4, r0, #0
    str r4, [sp, #0x50]
    ldr r2, [r5]
    adds r3, r4, #0
    cmp r2, sl
    beq .L08014A56
.L08014A3E:
    cmp r3, #0
    beq .L08014A4E
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08014A4E:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, sl
    bne .L08014A3E
.L08014A56:
    adds r4, r3, #0
    ldr r0, [sp, #0x28]
    cmp r0, #1
    bne .L08014A72
    cmp r4, #0
    beq .L08014A6E
    adds r0, r4, #0
    mov r1, sb
    ldm r1!, {r2, r6, r7}
    stm r0!, {r2, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08014A6E:
    adds r4, #0x10
    b .L08014A94
.L08014A72:
    adds r3, r0, #0
    adds r2, r4, #0
    cmp r3, #0
    beq .L08014A92
.L08014A7A:
    cmp r2, #0
    beq .L08014A8A
    adds r0, r2, #0
    mov r1, sb
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
.L08014A8A:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08014A7A
.L08014A92:
    adds r4, r2, #0
.L08014A94:
    ldr r2, [r5, #4]
    ldr r0, [r5]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08014AA4
.L08014A9E:
    adds r1, #0x10
    cmp r1, r2
    bne .L08014A9E
.L08014AA4:
    cmp r0, #0
    beq .L08014AAC
    bl free
.L08014AAC:
    ldr r0, [sp, #0x50]
    add r0, r8
    ldr r1, [sp, #0x50]
    str r1, [r5]
    str r4, [r5, #4]
    str r0, [r5, #0xc]
.L08014AB8:
    mov r1, sp
    ldr r2, .L08014AF0 @ =0x00003E41
    adds r0, r2, #0
    strh r0, [r1]
    ldr r3, [sp, #0x44]
    strh r0, [r3]
    movs r2, #0
    movs r0, #0x10
    ldr r4, [sp, #0x30]
    strb r0, [r4]
    ldr r0, .L08014AF4 @ =0x00001010
    strh r0, [r1]
    ldr r6, [sp, #0x48]
    strh r0, [r6]
    ldr r7, [sp, #0x34]
    strb r2, [r7]
    movs r0, #0x1a
    ldr r1, [sp, #0x2c]
    str r0, [r1]
    add sp, #0x54
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08014AF0: .4byte 0x00003E41
.L08014AF4: .4byte 0x00001010
    .size FlashScreenColor__9GameSceneUi, . - FlashScreenColor__9GameSceneUi

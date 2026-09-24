    .section .text
    .syntax unified
    .thumb
    .global AttemptBirth__4BarnUi
    .thumb_func
AttemptBirth__4BarnUi:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x50
    mov sl, r0
    adds r4, r1, #0
    bl IsReadyToGiveBirth__C4BarnUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lauto_0800D8A4
    b .Lauto_0800D9C6
    .Lauto_0800D8A4:
    mov r0, sl
    adds r0, #7
    adds r0, r0, r4
    movs r1, #0
    ldrsb r1, [r0, r1]
    mov sb, r1
    movs r1, #0xff
    strb r1, [r0]
    add r0, sp, #0x48
    mov r1, sl
    adds r2, r4, #0
    bl method_0800D1D8__C4BarnUi
    ldr r0, [sp, #0x48]
    str r0, [sp, #0x4c]
    add r0, sp, #0x4c
    movs r1, #0
    ldrsh r5, [r0, r1]
    movs r1, #2
    ldrsh r6, [r0, r1]
    add r7, sp, #8
    movs r2, #0x25
    ldrh r1, [r7]
    ldr r3, [pc, #0xac]
    adds r0, r3, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r7]
    lsls r5, r5, #0x10
    lsrs r1, r5, #0x10
    movs r0, #0x3f
    mov r8, r0
    ands r1, r0
    lsls r1, r1, #2
    ldrb r4, [r7, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r4
    orrs r0, r1
    strb r0, [r7, #1]
    lsrs r5, r5, #0x16
    ldrh r1, [r7, #2]
    adds r0, r3, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r7, #2]
    lsls r6, r6, #0x10
    lsrs r0, r6, #0x10
    mov r1, r8
    ands r0, r1
    lsls r0, r0, #2
    ldrb r1, [r7, #3]
    ands r2, r1
    orrs r2, r0
    strb r2, [r7, #3]
    lsrs r6, r6, #0x16
    ldrh r0, [r7, #4]
    ands r3, r0
    orrs r3, r6
    strh r3, [r7, #4]
    mov r5, sp
    movs r4, #2
    mov r0, sp
    adds r1, r7, #0
    movs r2, #6
    bl memcpy
    strb r4, [r5, #6]
    mov r1, sb
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r0, r0, #2
    adds r0, #0x2c
    mov r1, sl
    adds r4, r1, r0
    adds r0, r4, #0
    bl AsCow__Q24Barn3Ent
    adds r6, r0, #0
    cmp r6, #0
    beq .Lauto_0800D984
    bl ResetPregnancy__10BarnAnimal
    add r4, sp, #0x10
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0
    movs r3, #0
    bl __3CowRC13ActorLocationUiUi
    bl rand
    adds r5, r0, #0
    adds r0, r6, #0
    bl GetAffection__C6Animal
    .byte 0x01, 0x1C, 0x49, 0x08, 0x28, 0x1C, 0xC2, 0xF0, 0xCC, 0xFE, 0x01, 0x1C, 0x20, 0x1C, 0x8D, 0xF0
    .byte 0xB5, 0xF9, 0x50, 0x46, 0x21, 0x1C, 0xFF, 0xF7, 0x55, 0xFD, 0x24, 0xE0, 0x00, 0xFC, 0xFF, 0xFF
    .Lauto_0800D984:
    adds r0, r4, #0
    bl AsSheep__Q24Barn3Ent
    cmp r0, #0
    beq .Lauto_0800D9C6
    bl ResetPregnancy__10BarnAnimal
    adds r0, r7, #0
    mov r1, sp
    movs r2, #0
    movs r3, #0
    bl __5SheepRC13ActorLocationUiUi
    bl rand
    adds r4, r0, #0
    movs r0, #0
    bl GetAffection__C6Animal
    adds r1, r0, #0
    lsrs r1, r1, #1
    adds r0, r4, #0
    bl __umodsi3
    adds r1, r0, #0
    adds r0, r7, #0
    bl AddAffection__6Animali
    mov r0, sl
    adds r1, r7, #0
    bl InsertSheep__4BarnRC5Sheep
    b .Lauto_0800D9CA
    .Lauto_0800D9C6:
    movs r0, #1
    rsbs r0, r0, #0
    .Lauto_0800D9CA:
    add sp, #0x50
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .syntax divided

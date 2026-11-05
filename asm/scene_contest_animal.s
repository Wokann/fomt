    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start ClearContestAnimal__9GameScene14MaryAnimalKind
ClearContestAnimal__9GameScene14MaryAnimalKind:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r6, [r0, #4]
    cmp r1, #(.LclearContestHorse - .LclearContestHandlers) / 4 - 1
    bls .L080168E4
    b .LclearContestDone
.L080168E4:
    lsls r0, r1, #2
    ldr r1, .L080168F0 @ =.LclearContestHandlers
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L080168F0: .word .LclearContestHandlers
.LclearContestHandlers: @ jump table
    .word .LclearContestHorse @ ANIMAL_KIND_HORSE
    .word .LclearContestBarn @ ANIMAL_KIND_COW
    .word .LclearContestBarn @ ANIMAL_KIND_SHEEP
    .word .LclearContestChicken @ ANIMAL_KIND_CHICKEN
    .word .LclearContestDog @ ANIMAL_KIND_DOG
.LclearContestHorse:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    cmp r0, #0
    beq .L0801691E
    b .LclearContestDone
.L0801691E:
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2c
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016956
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016956
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016956:
    cmp r4, #0
    bne .L0801695C
    b .LclearContestDone
.L0801695C:
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbc
    lsls r2, r2, #2
    movs r3, #0x84
    bl SetLocation__7AEntityUiii
    b .LclearContestDone
.LclearContestBarn:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D058__C4Barn
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    bne .L0801698A
    b .LclearContestDone
.L0801698A:
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D858__4Barn
    adds r5, r7, #0
    adds r5, #0x36
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r5, r0, #0
    cmp r5, #0
    beq .L080169D4
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r5, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080169D4
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r5, #0
    bl _call_via_r1
.L080169D4:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0xbe
    lsls r0, r0, #3
    adds r1, r1, r0
    mov r4, sp
    mov r0, sp
    adds r2, r7, #0
    bl method_0800D074__C4BarnUi
    cmp r5, #0
    bne .L080169EE
    b .LclearContestDone
.L080169EE:
    mov r0, sp
    movs r1, #0
    ldrsh r2, [r0, r1]
    movs r0, #2
    ldrsh r3, [r4, r0]
    adds r0, r5, #0
    movs r1, #0x25
    bl SetLocation__7AEntityUiii
    b .LclearContestDone
.LclearContestChicken:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetUnkEnt__C4Coop
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    beq .LclearContestDone
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800CBC0__4Coop
    adds r5, r7, #0
    adds r5, #0x2e
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016A68
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016A68
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016A68:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r1, r1, r0
    add r5, sp, #4
    adds r0, r5, #0
    adds r2, r7, #0
    bl method_0800C6F0__C4CoopUi
    cmp r4, #0
    beq .LclearContestDone
    movs r1, #0
    ldrsh r2, [r5, r1]
    movs r0, #2
    ldrsh r3, [r5, r0]
    adds r0, r4, #0
    movs r1, #0x11
    bl SetLocation__7AEntityUiii
    b .LclearContestDone
.LclearContestDog:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    cmp r0, #0
    bne .LclearContestDone
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2b
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016ADE
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016ADE
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016ADE:
    cmp r4, #0
    beq .LclearContestDone
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbf
    lsls r2, r2, #1
    movs r3, #0x52
    bl SetLocation__7AEntityUiii
.LclearContestDone:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start GetContestAnimalIndex__9GameScene14MaryAnimalKind
GetContestAnimalIndex__9GameScene14MaryAnimalKind:
    push {lr}
    ldr r2, [r0, #4]
    cmp r1, #(.LgetContestHorse - .LgetContestHandlers) / 4 - 1
    bhi .LnoContestAnimal
    lsls r0, r1, #2
    ldr r1, .L08016B10 @ =.LgetContestHandlers
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08016B10: .word .LgetContestHandlers
.LgetContestHandlers: @ jump table
    .word .LgetContestHorse @ ANIMAL_KIND_HORSE
    .word .LgetContestBarn @ ANIMAL_KIND_COW
    .word .LgetContestBarn @ ANIMAL_KIND_SHEEP
    .word .LgetContestChicken @ ANIMAL_KIND_CHICKEN
    .word .LgetContestDog @ ANIMAL_KIND_DOG
.LgetContestHorse:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r2, [r0]
    ldr r1, .L08016B50 @ =0x0000219A
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne .LfixedContestAnimal
    ldr r1, .L08016B54 @ =0x000021A1
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne .LfixedContestAnimal
.LnoContestAnimal:
    movs r1, #1
    rsbs r1, r1, #0
    b .L08016B9C
    .align 2, 0
.L08016B50: .word 0x0000219A
.L08016B54: .word 0x000021A1
.LgetContestDog:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    ldr r1, .L08016B74 @ =0x0000219C
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, #0
    beq .L08016B9C
.LfixedContestAnimal:
    movs r1, #0
    b .L08016B9C
    .align 2, 0
.L08016B74: .word 0x0000219C
.LgetContestBarn:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D058__C4Barn
    b .L08016B9A
.LgetContestChicken:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetUnkEnt__C4Coop
.L08016B9A:
    adds r1, r0, #0
.L08016B9C:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0

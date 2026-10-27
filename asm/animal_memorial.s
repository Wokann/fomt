    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    @ Append matching chicken, cow and sheep names to the existing message.
    @ Text pointers are relocations; this 932-byte body remains native.
    thumb_func_start AppendAnimalMemorialNames
AppendAnimalMemorialNames: @ 0x08011934
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    str r0, [sp, #8]
    str r1, [sp, #0xc]
    mov sb, r2
    ldr r1, .Lmemorial_names_01 @ =gText_AnimalMemorial_LineBreak
    mov r0, sp
    movs r2, #3
    bl memcpy
    add r0, sp, #4
    ldr r1, .Lmemorial_names_02 @ =gText_AnimalMemorial_Continue
    movs r2, #2
    bl memcpy
    movs r0, #1
    str r0, [sp, #0x10]
    movs r1, #0
    mov sl, r1
    ldr r0, [sp, #8]
    adds r0, #0x8c
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Coop
    str r0, [sp, #0x14]
    movs r0, #0
    str r0, [sp, #0x18]
    ldr r1, [sp, #0x14]
    cmp sl, r1
    bhs .Lmemorial_names_11
.Lmemorial_names_00:
    ldr r0, [sp, #8]
    adds r0, #0x8c
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    ldr r1, [sp, #0x18]
    bl GetChicken__4CoopUi
    adds r7, r0, #0
    cmp r7, #0
    beq .Lmemorial_names_10
    bl GetLifeState__C9Livestock
    ldr r1, [sp, #0xc]
    cmp r0, r1
    bne .Lmemorial_names_10
    ldr r2, [sp, #0x10]
    cmp r2, #0
    beq .Lmemorial_names_03
    movs r0, #0
    str r0, [sp, #0x10]
    b .Lmemorial_names_05
    .align 2, 0
.Lmemorial_names_01: .4byte gText_AnimalMemorial_LineBreak
.Lmemorial_names_02: .4byte gText_AnimalMemorial_Continue
.Lmemorial_names_03:
    ldr r1, .Lmemorial_names_13 @ =gText_AnimalMemorial_LineBreak
    mov r8, r1
    mov r0, sb
    bl strlen
    mov r2, sb
    adds r6, r2, r0
    ldr r1, .Lmemorial_names_14 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .Lmemorial_names_05
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_04
    adds r4, r5, #0
.Lmemorial_names_04:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    mov r2, sp
    ldrb r2, [r2, #0x10]
    strb r2, [r0]
.Lmemorial_names_05:
    adds r0, r7, #0
    bl GetName__C6Animal
    adds r7, r0, #0
    adds r4, r7, #0
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r2, .Lmemorial_names_14 @ =0x00000383
    subs r5, r2, r0
    cmp r5, #0
    beq .Lmemorial_names_07
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_06
    adds r4, r5, #0
.Lmemorial_names_06:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_07:
    movs r0, #1
    add sl, r0
    mov r1, sl
    cmp r1, #2
    bls .Lmemorial_names_10
    ldr r7, .Lmemorial_names_15 @ =gText_AnimalMemorial_Continue
    mov r0, sb
    bl strlen
    mov r2, sb
    adds r6, r2, r0
    ldr r1, .Lmemorial_names_14 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .Lmemorial_names_09
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_08
    adds r4, r5, #0
.Lmemorial_names_08:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_09:
    movs r2, #0
    mov sl, r2
.Lmemorial_names_10:
    ldr r0, [sp, #0x18]
    adds r0, #1
    str r0, [sp, #0x18]
    ldr r1, [sp, #0x14]
    cmp r0, r1
    blo .Lmemorial_names_00
.Lmemorial_names_11:
    ldr r4, [sp, #8]
    adds r4, #0x8c
    ldr r0, [r4]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Barn
    str r0, [sp, #0x1c]
    movs r0, #0
    str r0, [sp, #0x20]
    str r4, [sp, #0x28]
    ldr r1, [sp, #0x1c]
    cmp r0, r1
    bhs .Lmemorial_names_24
.Lmemorial_names_12:
    ldr r2, [sp, #0x28]
    ldr r0, [r2]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, [sp, #0x20]
    bl GetCow__4BarnUi
    adds r7, r0, #0
    cmp r7, #0
    beq .Lmemorial_names_23
    bl GetLifeState__C9Livestock
    ldr r2, [sp, #0xc]
    cmp r0, r2
    bne .Lmemorial_names_23
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq .Lmemorial_names_16
    movs r1, #0
    str r1, [sp, #0x10]
    b .Lmemorial_names_18
    .align 2, 0
.Lmemorial_names_13: .4byte gText_AnimalMemorial_LineBreak
.Lmemorial_names_14: .4byte 0x00000383
.Lmemorial_names_15: .4byte gText_AnimalMemorial_Continue
.Lmemorial_names_16:
    ldr r2, .Lmemorial_names_26 @ =gText_AnimalMemorial_LineBreak
    mov r8, r2
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r2, .Lmemorial_names_27 @ =0x00000383
    subs r5, r2, r0
    cmp r5, #0
    beq .Lmemorial_names_18
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_17
    adds r4, r5, #0
.Lmemorial_names_17:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    mov r1, sp
    ldrb r1, [r1, #0x10]
    strb r1, [r0]
.Lmemorial_names_18:
    adds r0, r7, #0
    bl GetName__C6Animal
    mov r8, r0
    mov r6, r8
    mov r0, sb
    bl strlen
    mov r2, sb
    adds r7, r2, r0
    ldr r1, .Lmemorial_names_27 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .Lmemorial_names_20
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_19
    adds r4, r5, #0
.Lmemorial_names_19:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_20:
    movs r2, #1
    add sl, r2
    mov r0, sl
    cmp r0, #2
    bls .Lmemorial_names_23
    ldr r7, .Lmemorial_names_28 @ =gText_AnimalMemorial_Continue
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r2, .Lmemorial_names_27 @ =0x00000383
    subs r5, r2, r0
    cmp r5, #0
    beq .Lmemorial_names_22
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_21
    adds r4, r5, #0
.Lmemorial_names_21:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_22:
    movs r0, #0
    mov sl, r0
.Lmemorial_names_23:
    ldr r1, [sp, #0x20]
    adds r1, #1
    str r1, [sp, #0x20]
    ldr r2, [sp, #0x1c]
    cmp r1, r2
    blo .Lmemorial_names_12
.Lmemorial_names_24:
    movs r0, #0
    str r0, [sp, #0x24]
    ldr r1, [sp, #0x1c]
    cmp r0, r1
    bhs .Lmemorial_names_37
.Lmemorial_names_25:
    ldr r2, [sp, #0x28]
    ldr r0, [r2]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, [sp, #0x24]
    bl GetSheep__4BarnUi
    adds r7, r0, #0
    cmp r7, #0
    beq .Lmemorial_names_36
    bl GetLifeState__C9Livestock
    ldr r2, [sp, #0xc]
    cmp r0, r2
    bne .Lmemorial_names_36
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq .Lmemorial_names_29
    movs r1, #0
    str r1, [sp, #0x10]
    b .Lmemorial_names_31
    .align 2, 0
.Lmemorial_names_26: .4byte gText_AnimalMemorial_LineBreak
.Lmemorial_names_27: .4byte 0x00000383
.Lmemorial_names_28: .4byte gText_AnimalMemorial_Continue
.Lmemorial_names_29:
    ldr r2, .Lmemorial_names_40 @ =gText_AnimalMemorial_LineBreak
    mov r8, r2
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r2, .Lmemorial_names_41 @ =0x00000383
    subs r5, r2, r0
    cmp r5, #0
    beq .Lmemorial_names_31
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_30
    adds r4, r5, #0
.Lmemorial_names_30:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    mov r1, sp
    ldrb r1, [r1, #0x10]
    strb r1, [r0]
.Lmemorial_names_31:
    adds r0, r7, #0
    bl GetName__C6Animal
    mov r8, r0
    mov r6, r8
    mov r0, sb
    bl strlen
    mov r2, sb
    adds r7, r2, r0
    ldr r1, .Lmemorial_names_41 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .Lmemorial_names_33
    adds r0, r6, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_32
    adds r4, r5, #0
.Lmemorial_names_32:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_33:
    movs r2, #1
    add sl, r2
    mov r0, sl
    cmp r0, #2
    bls .Lmemorial_names_36
    ldr r7, .Lmemorial_names_42 @ =gText_AnimalMemorial_Continue
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r2, .Lmemorial_names_41 @ =0x00000383
    subs r5, r2, r0
    cmp r5, #0
    beq .Lmemorial_names_35
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_34
    adds r4, r5, #0
.Lmemorial_names_34:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_35:
    movs r0, #0
    mov sl, r0
.Lmemorial_names_36:
    ldr r1, [sp, #0x24]
    adds r1, #1
    str r1, [sp, #0x24]
    ldr r2, [sp, #0x1c]
    cmp r1, r2
    blo .Lmemorial_names_25
.Lmemorial_names_37:
    mov r0, sl
    cmp r0, #0
    beq .Lmemorial_names_39
    ldr r7, .Lmemorial_names_42 @ =gText_AnimalMemorial_Continue
    mov r0, sb
    bl strlen
    mov r1, sb
    adds r6, r1, r0
    ldr r1, .Lmemorial_names_41 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .Lmemorial_names_39
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Lmemorial_names_38
    adds r4, r5, #0
.Lmemorial_names_38:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.Lmemorial_names_39:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lmemorial_names_40: .4byte gText_AnimalMemorial_LineBreak
.Lmemorial_names_41: .4byte 0x00000383
.Lmemorial_names_42: .4byte gText_AnimalMemorial_Continue

    thumb_func_end AppendAnimalMemorialNames

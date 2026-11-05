    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start GenerateMineFloorLayout
GenerateMineFloorLayout:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x88
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r7, [r0, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r7, #0
    adds r0, #0xa8
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080159DA
    b .L08015B1A
.L080159DA:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L080159FC
    cmp r1, #0x33
    ble .L080159FC
    ldr r0, .L080159F8 @ =0x00000133
    cmp r1, r0
    bgt .L080159FC
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015A16
    movs r1, #1
    b .L08015A18
    .align 2, 0
.L080159F8: .word 0x00000133
.L080159FC:
    cmp r5, #1
    bne .L08015A16
    ldr r0, .L08015B50 @ =0x00000133
    cmp r1, r0
    ble .L08015A16
    ldr r0, .L08015B54 @ =0x00000233
    cmp r1, r0
    bgt .L08015A16
    ldr r2, .L08015B58 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015A18
.L08015A16:
    movs r1, #0
.L08015A18:
    cmp r1, #0
    beq .L08015B1A
    ldr r1, [r3, #0x14]
    add r4, sp, #0x3c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015A34
    adds r0, #7
.L08015A34:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015A40
    adds r1, #7
.L08015A40:
    asrs r1, r1, #3
    add r0, sp, #0x44
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015A66
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015A60
    ldr r0, [sp, #0x44]
    str r0, [r1]
.L08015A60:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015A66:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015A70
    adds r0, #7
.L08015A70:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015A7C
    adds r1, #7
.L08015A7C:
    asrs r1, r1, #3
    add r0, sp, #0x48
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015AA2
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015A9C
    ldr r0, [sp, #0x48]
    str r0, [r1]
.L08015A9C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015AA2:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015AAC
    adds r0, #7
.L08015AAC:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015AB8
    adds r1, #7
.L08015AB8:
    asrs r1, r1, #3
    add r0, sp, #0x4c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015ADE
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015AD8
    ldr r0, [sp, #0x4c]
    str r0, [r1]
.L08015AD8:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015ADE:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015AE8
    adds r0, #7
.L08015AE8:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015AF4
    adds r1, #7
.L08015AF4:
    asrs r1, r1, #3
    add r0, sp, #0x50
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015B1A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015B14
    ldr r0, [sp, #0x50]
    str r0, [r1]
.L08015B14:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015B1A:
    adds r4, r7, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    mov r8, r4
    cmp r3, #0
    bne .L08015B34
    b .L08015C7A
.L08015B34:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L08015B5C
    cmp r1, #0x33
    ble .L08015B5C
    ldr r0, .L08015B50 @ =0x00000133
    cmp r1, r0
    bgt .L08015B5C
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015B76
    movs r1, #1
    b .L08015B78
    .align 2, 0
.L08015B50: .word 0x00000133
.L08015B54: .word 0x00000233
.L08015B58: .word 0xFFFFFECC
.L08015B5C:
    cmp r5, #1
    bne .L08015B76
    ldr r0, .L08015CAC @ =0x00000133
    cmp r1, r0
    ble .L08015B76
    ldr r0, .L08015CB0 @ =0x00000233
    cmp r1, r0
    bgt .L08015B76
    ldr r2, .L08015CB4 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015B78
.L08015B76:
    movs r1, #0
.L08015B78:
    cmp r1, #0
    beq .L08015C7A
    ldr r1, [r3, #0x14]
    add r4, sp, #0x54
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015B94
    adds r0, #7
.L08015B94:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015BA0
    adds r1, #7
.L08015BA0:
    asrs r1, r1, #3
    add r0, sp, #0x5c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015BC6
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015BC0
    ldr r0, [sp, #0x5c]
    str r0, [r1]
.L08015BC0:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015BC6:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015BD0
    adds r0, #7
.L08015BD0:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015BDC
    adds r1, #7
.L08015BDC:
    asrs r1, r1, #3
    add r0, sp, #0x60
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C02
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015BFC
    ldr r0, [sp, #0x60]
    str r0, [r1]
.L08015BFC:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C02:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015C0C
    adds r0, #7
.L08015C0C:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015C18
    adds r1, #7
.L08015C18:
    asrs r1, r1, #3
    add r0, sp, #0x64
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C3E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015C38
    ldr r0, [sp, #0x64]
    str r0, [r1]
.L08015C38:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C3E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015C48
    adds r0, #7
.L08015C48:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015C54
    adds r1, #7
.L08015C54:
    asrs r1, r1, #3
    add r0, sp, #0x68
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C7A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015C74
    ldr r0, [sp, #0x68]
    str r0, [r1]
.L08015C74:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C7A:
    mov r1, r8
    ldr r0, [r1]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08015C90
    b .L08015DD6
.L08015C90:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L08015CB8
    cmp r1, #0x33
    ble .L08015CB8
    ldr r0, .L08015CAC @ =0x00000133
    cmp r1, r0
    bgt .L08015CB8
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015CD2
    movs r1, #1
    b .L08015CD4
    .align 2, 0
.L08015CAC: .word 0x00000133
.L08015CB0: .word 0x00000233
.L08015CB4: .word 0xFFFFFECC
.L08015CB8:
    cmp r5, #1
    bne .L08015CD2
    ldr r0, .L08015E20 @ =0x00000133
    cmp r1, r0
    ble .L08015CD2
    ldr r0, .L08015E24 @ =0x00000233
    cmp r1, r0
    bgt .L08015CD2
    ldr r2, .L08015E28 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015CD4
.L08015CD2:
    movs r1, #0
.L08015CD4:
    cmp r1, #0
    beq .L08015DD6
    ldr r1, [r3, #0x14]
    add r4, sp, #0x6c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015CF0
    adds r0, #7
.L08015CF0:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015CFC
    adds r1, #7
.L08015CFC:
    asrs r1, r1, #3
    add r0, sp, #0x74
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D22
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D1C
    ldr r0, [sp, #0x74]
    str r0, [r1]
.L08015D1C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D22:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015D2C
    adds r0, #7
.L08015D2C:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015D38
    adds r1, #7
.L08015D38:
    asrs r1, r1, #3
    add r0, sp, #0x78
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D5E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D58
    ldr r0, [sp, #0x78]
    str r0, [r1]
.L08015D58:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D5E:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015D68
    adds r0, #7
.L08015D68:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015D74
    adds r1, #7
.L08015D74:
    asrs r1, r1, #3
    add r0, sp, #0x7c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D9A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D94
    ldr r0, [sp, #0x7c]
    str r0, [r1]
.L08015D94:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D9A:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015DA4
    adds r0, #7
.L08015DA4:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015DB0
    adds r1, #7
.L08015DB0:
    asrs r1, r1, #3
    add r0, sp, #0x80
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015DD6
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015DD0
    ldr r0, [sp, #0x80]
    str r0, [r1]
.L08015DD0:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015DD6:
    ldr r2, [sp, #8]
    movs r3, #0
    add r4, sp, #0xc
    cmp r2, #0
    beq .L08015DE2
    adds r3, r4, #0
.L08015DE2:
    adds r0, r7, #0
    adds r0, #0x8c
    ldr r1, [r0]
    ldr r0, .L08015E2C @ =0x00002E58
    adds r1, r1, r0
    str r3, [sp]
    str r2, [sp, #4]
    add r0, sp, #0x84
    adds r2, r5, #0
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    adds r0, r4, #0
    cmp r0, r1
    beq .L08015E12
.L08015E0C:
    adds r0, #4
    cmp r0, r1
    bne .L08015E0C
.L08015E12:
    add sp, #0x88
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08015E20: .word 0x00000133
.L08015E24: .word 0x00000233
.L08015E28: .word 0xFFFFFECC
.L08015E2C: .word 0x00002E58

    thumb_func_start DescendMineFloor
DescendMineFloor:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xe8
    ldr r0, [r0, #4]
    str r0, [sp, #0xd8]
    adds r4, r0, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    add r0, sp, #0x3c
    movs r3, #0
    strb r3, [r0]
    strb r3, [r0, #1]
    adds r1, r2, #0
    subs r1, #0x34
    adds r7, r0, #0
    cmp r1, #0xff
    bls .L08015E64
    b .L08016250
.L08015E64:
    adds r0, r2, #1
    mov r8, r0
    adds r6, r2, #0
    subs r6, #0x33
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08015E82
    b .L08015F9C
.L08015E82:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L08015E9A
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L08015E9A
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015E9A
    movs r2, #1
.L08015E9A:
    cmp r2, #0
    beq .L08015F9C
    ldr r1, [r3, #0x14]
    add r4, sp, #0x40
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015EB6
    adds r0, #7
.L08015EB6:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015EC2
    adds r1, #7
.L08015EC2:
    asrs r1, r1, #3
    add r0, sp, #0x48
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015EE8
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015EE2
    ldr r0, [sp, #0x48]
    str r0, [r1]
.L08015EE2:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015EE8:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015EF2
    adds r0, #7
.L08015EF2:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015EFE
    adds r1, #7
.L08015EFE:
    asrs r1, r1, #3
    add r0, sp, #0x4c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F24
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F1E
    ldr r0, [sp, #0x4c]
    str r0, [r1]
.L08015F1E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F24:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015F2E
    adds r0, #7
.L08015F2E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015F3A
    adds r1, #7
.L08015F3A:
    asrs r1, r1, #3
    add r0, sp, #0x50
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F60
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F5A
    ldr r0, [sp, #0x50]
    str r0, [r1]
.L08015F5A:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F60:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015F6A
    adds r0, #7
.L08015F6A:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015F76
    adds r1, #7
.L08015F76:
    asrs r1, r1, #3
    add r0, sp, #0x54
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F9C
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F96
    ldr r0, [sp, #0x54]
    str r0, [r1]
.L08015F96:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F9C:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .L08015FB6
    b .L080160D0
.L08015FB6:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L08015FCE
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L08015FCE
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015FCE
    movs r2, #1
.L08015FCE:
    cmp r2, #0
    beq .L080160D0
    ldr r1, [r3, #0x14]
    add r4, sp, #0x58
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015FEA
    adds r0, #7
.L08015FEA:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015FF6
    adds r1, #7
.L08015FF6:
    asrs r1, r1, #3
    add r0, sp, #0x60
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801601C
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016016
    ldr r0, [sp, #0x60]
    str r0, [r1]
.L08016016:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801601C:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016026
    adds r0, #7
.L08016026:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016032
    adds r1, #7
.L08016032:
    asrs r1, r1, #3
    add r0, sp, #0x64
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016058
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016052
    ldr r0, [sp, #0x64]
    str r0, [r1]
.L08016052:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016058:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016062
    adds r0, #7
.L08016062:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L0801606E
    adds r1, #7
.L0801606E:
    asrs r1, r1, #3
    add r0, sp, #0x68
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016094
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L0801608E
    ldr r0, [sp, #0x68]
    str r0, [r1]
.L0801608E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016094:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801609E
    adds r0, #7
.L0801609E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L080160AA
    adds r1, #7
.L080160AA:
    asrs r1, r1, #3
    add r0, sp, #0x6c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080160D0
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L080160CA
    ldr r0, [sp, #0x6c]
    str r0, [r1]
.L080160CA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080160D0:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080160E6
    b .L0801620A
.L080160E6:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L080160FE
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L080160FE
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L080160FE
    movs r2, #1
.L080160FE:
    cmp r2, #0
    bne .L08016104
    b .L0801620A
.L08016104:
    ldr r1, [r3, #0x14]
    add r4, sp, #0x70
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801611C
    adds r0, #7
.L0801611C:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016128
    adds r1, #7
.L08016128:
    asrs r1, r1, #3
    add r0, sp, #0x78
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801614E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016148
    ldr r0, [sp, #0x78]
    str r0, [r1]
.L08016148:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801614E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016158
    adds r0, #7
.L08016158:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016164
    adds r1, #7
.L08016164:
    asrs r1, r1, #3
    add r0, sp, #0x7c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801618A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016184
    ldr r0, [sp, #0x7c]
    str r0, [r1]
.L08016184:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801618A:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016194
    adds r0, #7
.L08016194:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    b .L080161A4
    .align 2, 0
.L080161A0: .word 0x00000133
.L080161A4:
    bge .L080161A8
    adds r1, #7
.L080161A8:
    asrs r1, r1, #3
    add r0, sp, #0x80
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080161CE
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L080161C8
    ldr r0, [sp, #0x80]
    str r0, [r1]
.L080161C8:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080161CE:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080161D8
    adds r0, #7
.L080161D8:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L080161E4
    adds r1, #7
.L080161E4:
    asrs r1, r1, #3
    add r0, sp, #0x84
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801620A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016204
    ldr r0, [sp, #0x84]
    str r0, [r1]
.L08016204:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801620A:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .L08016216
    adds r2, r5, #0
.L08016216:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, .L0801624C @ =0x00002E58
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0x88
    movs r2, #0
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0x88
    cmp r1, r2
    bne .L08016244
    b .L0801664A
.L08016244:
    adds r1, #4
    cmp r1, r2
    bne .L08016244
    b .L0801664A
    .align 2, 0
.L0801624C: .word 0x00002E58
.L08016250:
    ldr r1, .L0801656C @ =0xFFFFFECC
    adds r0, r2, r1
    cmp r0, #0xff
    bls .L0801625A
    b .L08016740
.L0801625A:
    adds r0, r2, #1
    mov r8, r0
    adds r1, #1
    adds r6, r2, r1
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08016278
    b .L08016394
.L08016278:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L08016292
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L08016292
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L08016292
    movs r2, #1
.L08016292:
    cmp r2, #0
    beq .L08016394
    ldr r1, [r3, #0x14]
    add r4, sp, #0x8c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080162AE
    adds r0, #7
.L080162AE:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080162BA
    adds r0, #7
.L080162BA:
    asrs r0, r0, #3
    add r1, sp, #0x94
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080162E0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080162DA
    ldr r0, [r1]
    str r0, [r2]
.L080162DA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080162E0:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080162EA
    adds r0, #7
.L080162EA:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080162F6
    adds r0, #7
.L080162F6:
    asrs r0, r0, #3
    add r1, sp, #0x98
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801631C
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016316
    ldr r0, [r1]
    str r0, [r2]
.L08016316:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801631C:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016326
    adds r0, #7
.L08016326:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016332
    adds r0, #7
.L08016332:
    asrs r0, r0, #3
    add r1, sp, #0x9c
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016358
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016352
    ldr r0, [r1]
    str r0, [r2]
.L08016352:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016358:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016362
    adds r0, #7
.L08016362:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L0801636E
    adds r0, #7
.L0801636E:
    asrs r0, r0, #3
    add r1, sp, #0xa0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016394
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801638E
    ldr r0, [r1]
    str r0, [r2]
.L0801638E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016394:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .L080163AE
    b .L080164CA
.L080163AE:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L080163C8
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L080163C8
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L080163C8
    movs r2, #1
.L080163C8:
    cmp r2, #0
    beq .L080164CA
    ldr r1, [r3, #0x14]
    add r4, sp, #0xa4
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080163E4
    adds r0, #7
.L080163E4:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080163F0
    adds r0, #7
.L080163F0:
    asrs r0, r0, #3
    add r1, sp, #0xac
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016416
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016410
    ldr r0, [r1]
    str r0, [r2]
.L08016410:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016416:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016420
    adds r0, #7
.L08016420:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L0801642C
    adds r0, #7
.L0801642C:
    asrs r0, r0, #3
    add r1, sp, #0xb0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016452
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801644C
    ldr r0, [r1]
    str r0, [r2]
.L0801644C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016452:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801645C
    adds r0, #7
.L0801645C:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016468
    adds r0, #7
.L08016468:
    asrs r0, r0, #3
    add r1, sp, #0xb4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801648E
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016488
    ldr r0, [r1]
    str r0, [r2]
.L08016488:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801648E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016498
    adds r0, #7
.L08016498:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080164A4
    adds r0, #7
.L080164A4:
    asrs r0, r0, #3
    add r1, sp, #0xb8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080164CA
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080164C4
    ldr r0, [r1]
    str r0, [r2]
.L080164C4:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080164CA:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080164E0
    b .L0801660C
.L080164E0:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L080164FA
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L080164FA
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L080164FA
    movs r2, #1
.L080164FA:
    cmp r2, #0
    bne .L08016500
    b .L0801660C
.L08016500:
    ldr r1, [r3, #0x14]
    add r4, sp, #0xbc
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016518
    adds r0, #7
.L08016518:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016524
    adds r0, #7
.L08016524:
    asrs r0, r0, #3
    add r1, sp, #0xc4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801654A
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016544
    ldr r0, [r1]
    str r0, [r2]
.L08016544:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801654A:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016554
    adds r0, #7
.L08016554:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016560
    adds r0, #7
.L08016560:
    asrs r0, r0, #3
    add r1, sp, #0xc8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    b .L08016578
    .align 2, 0
.L0801656C: .word 0xFFFFFECC
.L08016570: .word 0x00000133
.L08016574: .word 0x00000233
.L08016578:
    cmp r0, #0xb
    bhi .L08016594
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801658E
    ldr r0, [r1]
    str r0, [r2]
.L0801658E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016594:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801659E
    adds r0, #7
.L0801659E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080165AA
    adds r0, #7
.L080165AA:
    asrs r0, r0, #3
    add r1, sp, #0xcc
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080165D0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080165CA
    ldr r0, [r1]
    str r0, [r2]
.L080165CA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080165D0:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080165DA
    adds r0, #7
.L080165DA:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080165E6
    adds r0, #7
.L080165E6:
    asrs r0, r0, #3
    add r1, sp, #0xd0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801660C
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016606
    ldr r0, [r1]
    str r0, [r2]
.L08016606:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801660C:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .L08016618
    adds r2, r5, #0
.L08016618:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, .L08016668 @ =0x00002E58
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0xd4
    movs r2, #1
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0xd4
    cmp r1, r2
    beq .L0801664A
.L08016644:
    adds r1, #4
    cmp r1, r2
    bne .L08016644
.L0801664A:
    ldr r0, [r0]
    str r0, [sp, #0x3c]
    ldr r0, [r4]
    ldr r4, .L08016668 @ =0x00002E58
    adds r0, r0, r4
    bl GetLayoutKind__C14MineFloorState
    cmp r0, #4
    bhi .L08016740
    lsls r0, r0, #2
    ldr r1, .L0801666C @ =.LmineLayoutDestinations
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08016668: .word 0x00002E58
.L0801666C: .word .LmineLayoutDestinations
.LmineLayoutDestinations: @ GetLayoutKind values 0 through 4
    .word .LenterNextMineFloor @ case 0
    .word .LenterNextMineFloor @ case 1
    .word .LenterNextMineFloor @ case 2
    .word .LenterNextMineFloor @ case 3
    .word .LenterNextMineFloor @ case 4
.LenterNextMineFloor:
    ldrb r0, [r7]
    lsls r0, r0, #4
    adds r0, #0x10
    mov sl, r0
    add r0, sp, #0x3c
    ldrb r0, [r0, #1]
    lsls r0, r0, #4
    adds r7, r0, #0
    adds r7, #0x38
    movs r0, #8
    add sl, r0
    adds r7, #8
    ldr r1, [sp, #0xe0]
    ldr r0, [r1]
    ldr r2, [r0]
    adds r2, #0xb4
    str r2, [sp, #0xdc]
    add r6, sp, #8
    ldr r3, .L08016750 @ =0x000003FF
    mov sb, r3
    mov r4, r8
    mov r1, sb
    ands r4, r1
    ldrh r2, [r6]
    ldr r5, .L08016754 @ =0xFFFFFC00
    adds r1, r5, #0
    ands r1, r2
    orrs r1, r4
    strh r1, [r6]
    mov r2, sl
    lsls r4, r2, #0x10
    lsrs r2, r4, #0x10
    movs r3, #0x3f
    mov ip, r3
    ands r2, r3
    lsls r2, r2, #2
    str r2, [sp, #0xe4]
    ldrb r1, [r6, #1]
    mov r8, r1
    movs r3, #3
    adds r1, r3, #0
    mov r2, r8
    ands r1, r2
    ldr r2, [sp, #0xe4]
    orrs r1, r2
    strb r1, [r6, #1]
    lsrs r4, r4, #0x16
    mov r1, sb
    ands r4, r1
    ldrh r2, [r6, #2]
    adds r1, r5, #0
    ands r1, r2
    orrs r1, r4
    strh r1, [r6, #2]
    lsls r2, r7, #0x10
    lsrs r1, r2, #0x10
    mov r4, ip
    ands r1, r4
    lsls r1, r1, #2
    ldrb r4, [r6, #3]
    ands r3, r4
    orrs r3, r1
    strb r3, [r6, #3]
    lsrs r2, r2, #0x16
    mov r1, sb
    ands r2, r1
    ldrh r1, [r6, #4]
    ands r5, r1
    orrs r5, r2
    strh r5, [r6, #4]
    ldr r2, [sp, #0xdc]
    ldr r3, [r2]
    adds r1, r6, #0
    movs r2, #1
    bl _call_via_r3
    ldr r0, [sp, #0xd8]
    bl func_080D7F08
    movs r4, #0
    ldr r3, [sp, #0xe0]
    ldr r0, [r3]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    str r7, [sp]
    str r4, [sp, #4]
    ldr r0, [sp, #0xd8]
    movs r1, #0
    mov r3, sl
    bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi
.L08016740:
    add sp, #0xe8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08016750: .word 0x000003FF
.L08016754: .word 0xFFFFFC00

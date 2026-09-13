    .ifdef REGION_JP
    @ JP revision 0 game-scene glue.
    .section .text
    .syntax unified
    .thumb
jp_game_scene_start:
    .incbin "baserom_jp.gba", 0x1002C, 0x2FC

    .global func_0801004C
    .thumb_set func_0801004C, jp_game_scene_start
    .global func_08010158
    .thumb_set func_08010158, jp_game_scene_start + 0x10C
    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED

    thumb_func_start func_0801004C
func_0801004C: @ 0x0801004C
    push {r4, r5, r6, r7, lr}
    sub sp, #0x1c
    adds r7, r0, #0
    adds r5, r1, #0
    mov r0, sp
    bl func_08008980
    movs r1, #0
    str r1, [sp, #4]
    movs r2, #0xd9
    lsls r2, r2, #2
    adds r0, r5, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08010070
    add r4, sp, #8
    str r1, [sp, #8]
    b .L08010076
.L08010070:
    add r4, sp, #8
    movs r0, #1
    str r0, [sp, #8]
.L08010076:
    movs r0, #8
    bl __builtin_new
    ldr r1, [r5, #4]
    adds r2, r4, #0
    bl func_08011DC4
    adds r5, r0, #0
    ldr r1, [sp, #4]
    adds r6, r4, #0
    cmp r5, r1
    beq .L0801009E
    cmp r1, #0
    beq .L0801009E
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801009E:
    str r5, [sp, #4]
    ldr r0, [sp, #4]
    movs r4, #0
    str r4, [sp, #4]
    str r0, [sp, #8]
    adds r0, r6, #0
    bl func_0800082C
    str r4, [sp, #8]
    add r0, sp, #0x14
    str r6, [sp, #0x14]
    str r4, [r0, #4]
    str r4, [r6]
    str r4, [r7]
    ldr r1, [sp, #8]
    cmp r1, #0
    beq .L080100CC
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080100CC:
    ldr r1, [sp, #4]
    cmp r1, #0
    beq .L080100DE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080100DE:
    mov r0, sp
    movs r1, #2
    bl func_08008A68
    adds r0, r7, #0
    add sp, #0x1c
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.L080100F0:
    .byte 0x02, 0x48, 0x00, 0x68, 0x02, 0x49, 0x40, 0x18, 0x70, 0x47, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0x24, 0x05, 0x00, 0x00, 0x02, 0x48, 0x00, 0x68, 0x02, 0x49, 0x40, 0x18, 0x70, 0x47, 0x00, 0x00
    .byte 0x0C, 0x04, 0x00, 0x03, 0xDC, 0x04, 0x00, 0x00, 0x02, 0x48, 0x00, 0x68, 0xDE, 0x21, 0x89, 0x00
    .byte 0x40, 0x18, 0x70, 0x47, 0x0C, 0x04, 0x00, 0x03, 0x02, 0x48, 0x00, 0x68, 0xDB, 0x21, 0x89, 0x00
    .byte 0x40, 0x18, 0x70, 0x47, 0x0C, 0x04, 0x00, 0x03, 0x02, 0x48, 0x00, 0x68, 0xDA, 0x21, 0x89, 0x00
    .byte 0x40, 0x18, 0x70, 0x47, 0x0C, 0x04, 0x00, 0x03, 0x19, 0x20, 0x70, 0x47, 0x01, 0x48, 0x00, 0x68
    .byte 0x08, 0x30, 0x70, 0x47, 0x0C, 0x04, 0x00, 0x03

    thumb_func_start func_08010158
func_08010158: @ 0x08010158
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, .L08010198 @ =vtable_unk_080E5BF8
    str r0, [r4]
    ldr r1, .L0801019C @ =gUnk_0300040C
    movs r0, #0
    str r0, [r1]
    movs r1, #0xde
    lsls r1, r1, #2
    adds r0, r4, r1
    movs r1, #2
    bl func_080D7E64
    adds r0, r4, #0
    adds r0, #8
    movs r1, #2
    bl _._13AScriptEngine
    ldr r0, [r4, #4]
    cmp r0, #0
    beq .L0801018A
    movs r1, #3
    bl func_080D4480
.L0801018A:
    adds r0, r4, #0
    adds r1, r5, #0
    bl func_080007EC
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.L08010198: .4byte vtable_unk_080E5BF8
.L0801019C: .4byte gUnk_0300040C
.L080101A0:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r6, r0, #0
    mov r8, r1
    ldr r0, .L08010254
    str r0, [r6]
    ldr r1, [r1]
    movs r4, #0
    mov r0, r8
    str r4, [r0]
    str r1, [r6, #4]
    adds r0, r6, #0
    adds r0, #8
    bl __12ScriptEnginePv
    movs r1, #0xd9
    lsls r1, r1, #2
    adds r0, r6, r1
    strb r4, [r0]
    movs r0, #0xdb
    lsls r0, r0, #2
    adds r1, r6, r0
    strb r4, [r1]
    movs r0, #0x1d
    str r0, [r1, #4]
    movs r1, #0xdd
    lsls r1, r1, #2
    adds r2, r6, r1
    ldrb r1, [r2]
    subs r0, #0x3d
    ands r0, r1
    movs r1, #6
    orrs r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    ldr r0, .L08010258
    ands r0, r1
    strh r0, [r2]
    movs r1, #0xde
    lsls r1, r1, #2
    adds r0, r6, r1
    str r4, [r0]
    adds r1, #0x14
    adds r0, r6, r1
    str r4, [r0]
    movs r1, #0x9a
    lsls r1, r1, #3
    adds r0, r6, r1
    str r4, [r0]
    ldr r0, .L0801025C
    adds r4, r6, r0
    movs r5, #5
    movs r7, #1
    negs r7, r7
.L0801020E:
    adds r0, r4, #0
    bl func_080D4130
    adds r4, #0xc
    subs r5, #1
    cmp r5, r7
    bne .L0801020E
    ldr r1, .L08010260
    adds r4, r6, r1
    movs r5, #3
    movs r7, #1
    negs r7, r7
.L08010226:
    adds r0, r4, #0
    bl func_080D40CC
    adds r4, #0xc
    subs r5, #1
    cmp r5, r7
    bne .L08010226
    ldr r0, .L08010264
    str r6, [r0]
    mov r1, r8
    ldr r0, [r1]
    cmp r0, #0
    beq .L08010246
    movs r1, #3
    bl func_080D4480
.L08010246:
    adds r0, r6, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L08010254: .4byte vtable_unk_080E5BF8
.L08010258: .4byte 0xFFFFF81F
.L0801025C: .4byte 0x000004DC
.L08010260: .4byte 0x00000524
.L08010264: .4byte gUnk_0300040C

.L08010268:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    adds r7, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    mov r8, r3
    ldr r4, [sp, #0x1c]
    ldr r0, .L08010330
    str r0, [r7]
    ldr r0, .L08010334
    bl __builtin_new
    str r4, [sp]
    adds r1, r5, #0
    adds r2, r6, #0
    mov r3, r8
    bl func_08010358
    adds r1, r0, #0
    str r1, [r7, #4]
    adds r0, r7, #0
    adds r0, #8
    bl __12ScriptEnginePv
    movs r0, #0xd9
    lsls r0, r0, #2
    adds r1, r7, r0
    movs r3, #0
    movs r0, #1
    strb r0, [r1]
    movs r0, #0xda
    lsls r0, r0, #2
    adds r1, r7, r0
    movs r0, #0xab
    str r0, [r1]
    movs r0, #0xdb
    lsls r0, r0, #2
    adds r1, r7, r0
    strb r3, [r1]
    movs r0, #0x1d
    str r0, [r1, #4]
    movs r1, #0xdd
    lsls r1, r1, #2
    adds r2, r7, r1
    ldrb r1, [r2]
    subs r0, #0x3d
    ands r0, r1
    movs r1, #6
    orrs r0, r1
    strb r0, [r2]
    ldrh r1, [r2]
    ldr r0, .L08010338
    ands r0, r1
    strh r0, [r2]
    movs r1, #0xde
    lsls r1, r1, #2
    adds r0, r7, r1
    str r3, [r0]
    adds r1, #0x14
    adds r0, r7, r1
    str r3, [r0]
    movs r1, #0x9a
    lsls r1, r1, #3
    adds r0, r7, r1
    str r3, [r0]
    ldr r0, .L0801033C
    adds r4, r7, r0
    movs r5, #5
    movs r6, #1
    negs r6, r6
.L080102F8:
    adds r0, r4, #0
    bl func_080D4130
    adds r4, #0xc
    subs r5, #1
    cmp r5, r6
    bne .L080102F8
    ldr r1, .L08010340
    adds r4, r7, r1
    movs r5, #3
    movs r6, #1
    negs r6, r6
.L08010310:
    adds r0, r4, #0
    bl func_080D40CC
    adds r4, #0xc
    subs r5, #1
    cmp r5, r6
    bne .L08010310
    ldr r0, .L08010344
    str r7, [r0]
    adds r0, r7, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L08010330: .4byte vtable_unk_080E5BF8
.L08010334: .4byte 0x000034F4
.L08010338: .4byte 0xFFFFF81F
.L0801033C: .4byte 0x000004DC
.L08010340: .4byte 0x00000524
.L08010344: .4byte gUnk_0300040C
    .endif

    .ifdef REGION_JP
    @ JP revision 0 game-scene glue.
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .global func_0801004C
    .thumb_func
func_0801004C:
    push {r4, r5, r6, r7, lr}
    sub sp, #28
    adds r7, r0, #0
    adds r5, r1, #0
    mov r0, sp
    bl func_08008980
    movs r1, #0
    str r1, [sp, #4]
    movs r2, #217 @ 0xd9
    lsls r2, r2, #2
    adds r0, r5, r2
    ldrb r0, [r0, #0]
    cmp r0, #0
    beq .Ljp_08010050
    add r4, sp, #8
    str r1, [sp, #8]
    b .Ljp_08010056
.Ljp_08010050:
    add r4, sp, #8
    movs r0, #1
    str r0, [sp, #8]
.Ljp_08010056:
    movs r0, #8
    bl __builtin_new
    ldr r1, [r5, #4]
    adds r2, r4, #0
    bl func_08011DC4
    adds r5, r0, #0
    ldr r1, [sp, #4]
    adds r6, r4, #0
    cmp r5, r1
    beq .Ljp_0801007E
    cmp r1, #0
    beq .Ljp_0801007E
    ldr r0, [r1, #0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_0801007E:
    str r5, [sp, #4]
    ldr r0, [sp, #4]
    movs r4, #0
    str r4, [sp, #4]
    str r0, [sp, #8]
    adds r0, r6, #0
    bl func_0800082C
    str r4, [sp, #8]
    add r0, sp, #20
    str r6, [sp, #20]
    str r4, [r0, #4]
    str r4, [r6, #0]
    str r4, [r7, #0]
    ldr r1, [sp, #8]
    cmp r1, #0
    beq .Ljp_080100AC
    ldr r0, [r1, #0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_080100AC:
    ldr r1, [sp, #4]
    cmp r1, #0
    beq .Ljp_080100BE
    ldr r0, [r1, #0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_080100BE:
    mov r0, sp
    movs r1, #2
    bl func_08008A68
    adds r0, r7, #0
    add sp, #28
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Ljp_080100D0:
    ldr r0, .Ljp_080100DC
    ldr r0, [r0, #0]
    ldr r1, .Ljp_080100E0
    adds r0, r0, r1
    bx lr
    .align 2, 0
.Ljp_080100DC:
    .4byte gUnk_0300040C
.Ljp_080100E0:
    .4byte 0x00000524
.Ljp_080100E4:
    ldr r0, .Ljp_080100F0
    ldr r0, [r0, #0]
    ldr r1, .Ljp_080100F4
    adds r0, r0, r1
    bx lr
    .align 2, 0
.Ljp_080100F0:
    .4byte gUnk_0300040C
.Ljp_080100F4:
    .4byte 0x000004DC
.Ljp_080100F8:
    ldr r0, .Ljp_08010104
    ldr r0, [r0, #0]
    movs r1, #222 @ 0xde
    lsls r1, r1, #2
    adds r0, r0, r1
    bx lr
.Ljp_08010104:
    .4byte gUnk_0300040C
.Ljp_08010108:
    ldr r0, .Ljp_08010114
    ldr r0, [r0, #0]
    movs r1, #219 @ 0xdb
    lsls r1, r1, #2
    adds r0, r0, r1
    bx lr
.Ljp_08010114:
    .4byte gUnk_0300040C
.Ljp_08010118:
    ldr r0, .Ljp_08010124
    ldr r0, [r0, #0]
    movs r1, #218 @ 0xda
    lsls r1, r1, #2
    adds r0, r0, r1
    bx lr
.Ljp_08010124:
    .4byte gUnk_0300040C
.Ljp_08010128:
    movs r0, #25
    bx lr
.Ljp_0801012C:
    ldr r0, .Ljp_08010134
    ldr r0, [r0, #0]
    adds r0, #8
    bx lr
.Ljp_08010134:
    .4byte gUnk_0300040C

    .global func_08010158
    .thumb_func
func_08010158:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, .Ljp_08010178
    str r0, [r4, #0]
    ldr r1, .Ljp_0801017C
    movs r0, #0
    str r0, [r1, #0]
    movs r1, #222 @ 0xde
    lsls r1, r1, #2
    adds r0, r4, r1
    movs r1, #2
    bl func_080D7E64
    adds r0, r4, #0
    adds r0, #8
    movs r1, #2
    bl func_0803EB3C
    ldr r0, [r4, #4]
    cmp r0, #0
    beq .Ljp_0801016A
    movs r1, #3
    bl func_080D4480
.Ljp_0801016A:
    adds r0, r4, #0
    adds r1, r5, #0
    bl func_080007EC
    pop {r4, r5}
    pop {r0}
    bx r0
.Ljp_08010178:
    .4byte vtable_unk_080E5BF8
.Ljp_0801017C:
    .4byte gUnk_0300040C
.Ljp_08010180:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r6, r0, #0
    mov r8, r1
    ldr r0, .Ljp_08010234
    str r0, [r6, #0]
    ldr r1, [r1, #0]
    movs r4, #0
    mov r0, r8
    str r4, [r0, #0]
    str r1, [r6, #4]
    adds r0, r6, #0
    adds r0, #8
    bl __12ScriptEnginePv
    movs r1, #217 @ 0xd9
    lsls r1, r1, #2
    adds r0, r6, r1
    strb r4, [r0, #0]
    movs r0, #219 @ 0xdb
    lsls r0, r0, #2
    adds r1, r6, r0
    strb r4, [r1, #0]
    movs r0, #29
    str r0, [r1, #4]
    movs r1, #221 @ 0xdd
    lsls r1, r1, #2
    adds r2, r6, r1
    ldrb r1, [r2, #0]
    subs r0, #61 @ 0x3d
    ands r0, r1
    movs r1, #6
    orrs r0, r1
    strb r0, [r2, #0]
    ldrh r1, [r2, #0]
    ldr r0, .Ljp_08010238
    ands r0, r1
    strh r0, [r2, #0]
    movs r1, #222 @ 0xde
    lsls r1, r1, #2
    adds r0, r6, r1
    str r4, [r0, #0]
    adds r1, #20
    adds r0, r6, r1
    str r4, [r0, #0]
    movs r1, #154 @ 0x9a
    lsls r1, r1, #3
    adds r0, r6, r1
    str r4, [r0, #0]
    ldr r0, .Ljp_0801023C
    adds r4, r6, r0
    movs r5, #5
    movs r7, #1
    negs r7, r7
.Ljp_080101EE:
    adds r0, r4, #0
    bl func_080D4130
    adds r4, #12
    subs r5, #1
    cmp r5, r7
    bne .Ljp_080101EE
    ldr r1, .Ljp_08010240
    adds r4, r6, r1
    movs r5, #3
    movs r7, #1
    negs r7, r7
.Ljp_08010206:
    adds r0, r4, #0
    bl func_080D40CC
    adds r4, #12
    subs r5, #1
    cmp r5, r7
    bne .Ljp_08010206
    ldr r0, .Ljp_08010244
    str r6, [r0, #0]
    mov r1, r8
    ldr r0, [r1, #0]
    cmp r0, #0
    beq .Ljp_08010226
    movs r1, #3
    bl func_080D4480
.Ljp_08010226:
    adds r0, r6, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Ljp_08010234:
    .4byte vtable_unk_080E5BF8
.Ljp_08010238:
    .4byte 0xFFFFF81F
.Ljp_0801023C:
    .4byte 0x000004DC
.Ljp_08010240:
    .4byte 0x00000524
.Ljp_08010244:
    .4byte gUnk_0300040C
.Ljp_08010248:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    adds r7, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    mov r8, r3
    ldr r4, [sp, #28]
    ldr r0, .Ljp_08010310
    str r0, [r7, #0]
    ldr r0, .Ljp_08010314
    bl __builtin_new
    str r4, [sp, #0]
    adds r1, r5, #0
    adds r2, r6, #0
    mov r3, r8
    bl func_08010358
    adds r1, r0, #0
    str r1, [r7, #4]
    adds r0, r7, #0
    adds r0, #8
    bl __12ScriptEnginePv
    movs r0, #217 @ 0xd9
    lsls r0, r0, #2
    adds r1, r7, r0
    movs r3, #0
    movs r0, #1
    strb r0, [r1, #0]
    movs r0, #218 @ 0xda
    lsls r0, r0, #2
    adds r1, r7, r0
    movs r0, #171 @ 0xab
    str r0, [r1, #0]
    movs r0, #219 @ 0xdb
    lsls r0, r0, #2
    adds r1, r7, r0
    strb r3, [r1, #0]
    movs r0, #29
    str r0, [r1, #4]
    movs r1, #221 @ 0xdd
    lsls r1, r1, #2
    adds r2, r7, r1
    ldrb r1, [r2, #0]
    subs r0, #61 @ 0x3d
    ands r0, r1
    movs r1, #6
    orrs r0, r1
    strb r0, [r2, #0]
    ldrh r1, [r2, #0]
    ldr r0, .Ljp_08010318
    ands r0, r1
    strh r0, [r2, #0]
    movs r1, #222 @ 0xde
    lsls r1, r1, #2
    adds r0, r7, r1
    str r3, [r0, #0]
    adds r1, #20
    adds r0, r7, r1
    str r3, [r0, #0]
    movs r1, #154 @ 0x9a
    lsls r1, r1, #3
    adds r0, r7, r1
    str r3, [r0, #0]
    ldr r0, .Ljp_0801031C
    adds r4, r7, r0
    movs r5, #5
    movs r6, #1
    negs r6, r6
.Ljp_080102D8:
    adds r0, r4, #0
    bl func_080D4130
    adds r4, #12
    subs r5, #1
    cmp r5, r6
    bne .Ljp_080102D8
    ldr r1, .Ljp_08010320
    adds r4, r7, r1
    movs r5, #3
    movs r6, #1
    negs r6, r6
.Ljp_080102F0:
    adds r0, r4, #0
    bl func_080D40CC
    adds r4, #12
    subs r5, #1
    cmp r5, r6
    bne .Ljp_080102F0
    ldr r0, .Ljp_08010324
    str r7, [r0, #0]
    adds r0, r7, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Ljp_08010310:
    .4byte vtable_unk_080E5BF8
.Ljp_08010314:
    .4byte 0x000034F4
.Ljp_08010318:
    .4byte 0xFFFFF81F
.Ljp_0801031C:
    .4byte 0x000004DC
.Ljp_08010320:
    .4byte 0x00000524
.Ljp_08010324:
    .4byte gUnk_0300040C
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

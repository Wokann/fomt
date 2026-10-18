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
    bl __9GameSceneP18GameStateSaveImageRC22GameSceneResumeRequest
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
    bl SceneMain
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
    .section .text.game_scene_post, "ax", %progbits
    .thumb
    .align 2, 0

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
    bl _._13AScriptEngine
    ldr r0, [r4, #4]
    cmp r0, #0
    beq .Ljp_0801016A
    movs r1, #3
    bl func_080D4480
.Ljp_0801016A:
    adds r0, r4, #0
    adds r1, r5, #0
    bl _._6AScene
    pop {r4, r5}
    pop {r0}
    bx r0
.Ljp_08010178:
    .4byte __vt_25GameSceneScriptController
.Ljp_0801017C:
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
    bl __9GameSceneP18GameStateSaveImageRC22GameSceneResumeRequest
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
    bl SceneMain
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
    .section .text.game_scene_post, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08010158
func_08010158: @ 0x08010158
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, .L08010198 @ =__vt_25GameSceneScriptController
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
    bl _._6AScene
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.L08010198: .4byte __vt_25GameSceneScriptController
.L0801019C: .4byte gUnk_0300040C
    .endif

    .include "asm/macro.inc"
    .syntax unified

    @ The startup-controller Run method is shared C++ in game_scene.cc.
    @ Its destruction remains this shared native body in every region.
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

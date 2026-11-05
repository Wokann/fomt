    .include "asm/macro.inc"

    .syntax unified
    .thumb
    .text

    @ Update work state, farm/building transitions and the actor animation.
    thumb_func_start UpdateHarvestSpriteActor
UpdateHarvestSpriteActor:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #172
    adds r7, r0, #0
    adds r2, r1, #0
    ldr r0, [r7, #52]
    mov r8, r0
    ldr r1, [r7, #0]
    mov sl, r1
    ldr r0, [r0, #28]
    cmp r0, #(.LharvestSpriteUpdateStatesEnd - .LharvestSpriteUpdateStates) / 4 - 1
    bhi .LharvestSpriteUpdate_044
    lsls r0, r0, #2
    ldr r1, .LharvestSpriteUpdate_028
    adds r0, r0, r1
    ldr r0, [r0, #0]
    mov pc, r0
.LharvestSpriteUpdate_028: .word .LharvestSpriteUpdateStates
.LharvestSpriteUpdateStates:
    .word .LharvestSpriteUpdate_044
    .word .LharvestSpriteUpdate_0D0
    .word .LharvestSpriteUpdate_100
    .word .LharvestSpriteUpdate_268
    .word .LharvestSpriteUpdate_4C0
    .word .LharvestSpriteUpdate_4E4
.LharvestSpriteUpdateStatesEnd:
.LharvestSpriteUpdate_044:
    ldrb r0, [r2, #4]
    cmp r0, #0
    bne .LharvestSpriteUpdate_04C
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_04C:
    mov r0, r8
    bl GetCurrentTask__C13HarvestSprite
    cmp r0, #3
    bne .LharvestSpriteUpdate_058
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_058:
    mov r0, r8
    bl GetWorkDaysLeft__C13HarvestSprite
    cmp r0, #0
    bne .LharvestSpriteUpdate_064
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_064:
    mov r2, sl
    ldr r0, [r2, #0]
    movs r3, #162
    lsls r3, r3, #1
    adds r0, r0, r3
    ldr r1, [r0, #0]
    mov r0, sl
    bl _call_via_r1
    adds r2, r0, #0
    ldrb r1, [r2, #10]
    movs r0, #31
    ands r0, r1
    cmp r0, #6
    beq .LharvestSpriteUpdate_084
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_084:
    ldrh r0, [r2, #10]
    lsls r0, r0, #21
    lsrs r0, r0, #26
    adds r1, r7, #0
    adds r1, #48
    ldrb r1, [r1, #0]
    adds r1, #1
    cmp r0, r1
    beq .LharvestSpriteUpdate_098
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_098:
    ldr r0, [r2, #0]
    subs r0, #3
    cmp r0, #1
    bls .LharvestSpriteUpdate_0C8
    movs r2, #180
    lsls r2, r2, #1
    movs r3, #8
    negs r3, r3
    adds r0, r7, #0
    movs r1, #2
    bl SetLocation__7AEntityUiii
    add r1, sp, #72
    mov r0, r8
    bl method_0809E7D0__13HarvestSpritePCv
    movs r3, #128
    lsls r3, r3, #8
    adds r0, r7, #0
    movs r1, #1
    movs r2, #0
    bl func_08034180
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_0C8:
    mov r0, r8
    bl TaskDayUpdate__13HarvestSprite
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_0D0:
    ldrh r0, [r7, #4]
    cmp r0, #2
    beq .LharvestSpriteUpdate_0F4
    movs r2, #180
    lsls r2, r2, #1
    movs r3, #8
    negs r3, r3
    adds r0, r7, #0
    movs r1, #2
    bl SetLocation__7AEntityUiii
    movs r3, #128
    lsls r3, r3, #8
    adds r0, r7, #0
    movs r1, #1
    movs r2, #0
    bl func_08034180
.LharvestSpriteUpdate_0F4:
    movs r4, #14
    ldrsh r0, [r7, r4]
    cmp r0, #119
    bgt .LharvestSpriteUpdate_0FE
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_0FE:
    b .LharvestSpriteUpdate_4D4
.LharvestSpriteUpdate_100:
    mov r5, r8
    adds r5, #32
    str r5, [sp, #148]
    mov r6, r8
    ldrh r0, [r6, #32]
    cmp r0, #0
    beq .LharvestSpriteUpdate_110
    b .LharvestSpriteUpdate_260
.LharvestSpriteUpdate_110:
    adds r0, r7, #0
    bl func_08034940
    lsls r0, r0, #24
    cmp r0, #0
    beq .LharvestSpriteUpdate_11E
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_11E:
    ldrb r0, [r5, #3]
    cmp r0, #0
    beq .LharvestSpriteUpdate_12E
    subs r0, #1
    strb r0, [r5, #3]
    lsls r0, r0, #24
    cmp r0, #0
    bne .LharvestSpriteUpdate_13C
.LharvestSpriteUpdate_12E:
    adds r0, r7, #0
    bl func_08034260
    lsls r0, r0, #24
    cmp r0, #0
    beq .LharvestSpriteUpdate_13C
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_13C:
    ldr r5, .LharvestSpriteUpdate_17C
    adds r0, r5, #0
    movs r1, #5
    bl SelectActorBehaviorTimingIndex
    lsls r4, r0, #2
    adds r4, r4, r5
    movs r6, #0
    ldr r1, [sp, #148]
    strb r0, [r1, #2]
    movs r5, #60
    ldrb r0, [r4, #2]
    muls r0, r5
    bl RandomBelow
    ldrb r1, [r4, #1]
    muls r1, r5
    adds r1, r1, r0
    ldr r2, [sp, #148]
    strh r1, [r2, #0]
    ldrh r4, [r7, #4]
    add r0, sp, #76
    strh r6, [r0, #0]
    strh r6, [r0, #2]
    mov r9, r0
    cmp r4, #17
    beq .LharvestSpriteUpdate_1BE
    cmp r4, #17
    bgt .LharvestSpriteUpdate_180
    cmp r4, #2
    beq .LharvestSpriteUpdate_186
    b .LharvestSpriteUpdate_1D6
.LharvestSpriteUpdate_17C: .word gUnk_080F143C
.LharvestSpriteUpdate_180:
    cmp r4, #37
    beq .LharvestSpriteUpdate_1A4
    b .LharvestSpriteUpdate_1D6
.LharvestSpriteUpdate_186:
    movs r0, #72
    bl RandomBelow
    adds r0, #128
    mov r3, r9
    strh r0, [r3, #0]
    movs r0, #72
    bl RandomBelow
    movs r5, #148
    lsls r5, r5, #1
    adds r0, r0, r5
    mov r6, r9
    strh r0, [r6, #2]
    b .LharvestSpriteUpdate_1D6
.LharvestSpriteUpdate_1A4:
    movs r0, #104
    bl RandomBelow
    adds r0, #72
    mov r1, r9
    strh r0, [r1, #0]
    movs r0, #48
    bl RandomBelow
    adds r0, #96
    mov r2, r9
    strh r0, [r2, #2]
    b .LharvestSpriteUpdate_1D6
.LharvestSpriteUpdate_1BE:
    movs r0, #64
    bl RandomBelow
    adds r0, #144
    mov r3, r9
    strh r0, [r3, #0]
    movs r0, #48
    bl RandomBelow
    adds r0, #112
    mov r5, r9
    strh r0, [r5, #2]
.LharvestSpriteUpdate_1D6:
    adds r0, r7, #0
    adds r0, #32
    ldrb r0, [r0, #0]
    mov r8, r0
    mov r6, sl
    ldr r1, [r6, #0]
    add r0, sp, #8
    ldr r3, [r1, #52]
    mov r1, sl
    adds r2, r4, #0
    bl _call_via_r3
    ldr r1, [r7, #20]
    add r0, sp, #80
    ldr r2, [r1, #12]
    adds r1, r7, #0
    bl _call_via_r2
    ldr r0, [sp, #80]
    ldr r1, [sp, #84]
    str r0, [sp, #164]
    str r1, [sp, #168]
    add r4, sp, #20
    movs r1, #32
    mov sl, r1
    movs r5, #0
    movs r1, #33
    str r1, [sp, #20]
    movs r0, #33
    negs r0, r0
    str r0, [r4, #4]
    str r0, [r4, #8]
    str r1, [r4, #12]
    add r1, sp, #40
    add r0, sp, #8
    ldmia r0!, {r2, r3, r6}
    stmia r1!, {r2, r3, r6}
    ldr r0, [sp, #164]
    ldr r1, [sp, #168]
    str r0, [sp, #52]
    str r1, [sp, #56]
    mov r1, sl
    str r1, [r4, #40]
    str r5, [r4, #44]
    str r5, [r4, #48]
    movs r2, #10
    ldrsh r0, [r7, r2]
    movs r3, #14
    ldrsh r1, [r7, r3]
    mov r5, r9
    movs r6, #0
    ldrsh r2, [r5, r6]
    add r3, sp, #76
    movs r5, #2
    ldrsh r3, [r3, r5]
    str r4, [sp, #0]
    mov r6, r8
    str r6, [sp, #4]
    bl SelectApproachFacing
    adds r2, r0, #0
    ldr r0, [sp, #148]
    ldrb r1, [r0, #2]
    movs r3, #128
    lsls r3, r3, #8
    adds r0, r7, #0
    bl func_08034180
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_260:
    subs r0, #1
    mov r1, r8
    strh r0, [r1, #32]
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_268:
    mov r2, r8
    adds r2, #32
    str r2, [sp, #152]
    adds r4, r7, #0
    adds r4, #48
    ldrb r0, [r4, #0]
    ldr r1, [r7, #56]
    lsls r0, r0, #3
    adds r1, r1, r0
    mov r9, r1
    ldr r1, [r7, #60]
    mov r0, r9
    mov r2, sl
    bl func_08033784
    adds r6, r0, #0
    ldrh r5, [r7, #4]
    movs r0, #10
    ldrsh r3, [r7, r0]
    str r3, [sp, #156]
    movs r2, #14
    ldrsh r1, [r7, r2]
    str r1, [sp, #160]
    add r0, sp, #88
    strh r3, [r0, #0]
    strh r1, [r0, #2]
    cmp r6, r5
    bne .LharvestSpriteUpdate_2B2
    ldr r2, [r7, #60]
    add r0, sp, #92
    mov r1, r9
    mov r3, sl
    bl func_08033830
    ldr r0, [sp, #92]
    str r0, [sp, #88]
    b .LharvestSpriteUpdate_302
.LharvestSpriteUpdate_2B2:
    cmp r5, #17
    beq .LharvestSpriteUpdate_2F2
    cmp r5, #17
    bgt .LharvestSpriteUpdate_2C0
    cmp r5, #2
    beq .LharvestSpriteUpdate_2C6
    b .LharvestSpriteUpdate_2FE
.LharvestSpriteUpdate_2C0:
    cmp r5, #37
    beq .LharvestSpriteUpdate_2E6
    b .LharvestSpriteUpdate_2FE
.LharvestSpriteUpdate_2C6:
    cmp r6, #17
    beq .LharvestSpriteUpdate_2DA
    cmp r6, #37
    bne .LharvestSpriteUpdate_2FE
    add r0, sp, #96
    bl smethod_08009ADC__4Farm
    ldr r0, [sp, #96]
    str r0, [sp, #88]
    b .LharvestSpriteUpdate_302
.LharvestSpriteUpdate_2DA:
    add r0, sp, #100
    bl smethod_08009AE8__4Farm
    ldr r0, [sp, #100]
    str r0, [sp, #88]
    b .LharvestSpriteUpdate_302
.LharvestSpriteUpdate_2E6:
    add r0, sp, #104
    bl method_0800CE58__4Barn
    ldr r0, [sp, #104]
    str r0, [sp, #88]
    b .LharvestSpriteUpdate_302
.LharvestSpriteUpdate_2F2:
    add r0, sp, #108
    bl method_0800C554__4Coop
    ldr r0, [sp, #108]
    str r0, [sp, #88]
    b .LharvestSpriteUpdate_302
.LharvestSpriteUpdate_2FE:
    movs r6, #141
    lsls r6, r6, #2
.LharvestSpriteUpdate_302:
    movs r0, #141
    lsls r0, r0, #2
    cmp r6, r0
    beq .LharvestSpriteUpdate_3FA
    add r3, sp, #88
    movs r2, #0
    ldrsh r0, [r3, r2]
    ldr r1, [sp, #156]
    subs r0, r0, r1
    cmp r0, #0
    bge .LharvestSpriteUpdate_31A
    negs r0, r0
.LharvestSpriteUpdate_31A:
    cmp r0, #7
    bgt .LharvestSpriteUpdate_3FA
    movs r3, #90
    add r3, sp
    movs r2, #0
    ldrsh r0, [r3, r2]
    ldr r1, [sp, #160]
    subs r0, r0, r1
    cmp r0, #0
    bge .LharvestSpriteUpdate_330
    negs r0, r0
.LharvestSpriteUpdate_330:
    cmp r0, #7
    bgt .LharvestSpriteUpdate_3FA
    adds r0, r7, #0
    bl func_08034940
    lsls r0, r0, #24
    lsrs r1, r0, #24
    cmp r1, #0
    beq .LharvestSpriteUpdate_344
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_344:
    cmp r6, r5
    bne .LharvestSpriteUpdate_37C
    adds r0, r7, #0
    bl func_0803436C
    lsls r0, r0, #24
    cmp r0, #0
    bne .LharvestSpriteUpdate_356
    b .LharvestSpriteUpdate_4D4
.LharvestSpriteUpdate_356:
    ldr r1, .LharvestSpriteUpdate_378
    ldr r0, [sp, #112]
    ands r0, r1
    movs r1, #60
    orrs r0, r1
    str r0, [sp, #112]
    add r1, sp, #112
    mov r0, r8
    bl method_0809E7F0__13HarvestSpritePC15UnkBarnAnimal2C
    adds r0, r7, #0
    adds r0, #32
    ldrb r2, [r0, #0]
    adds r0, r7, #0
    movs r1, #4
    b .LharvestSpriteUpdate_53E
    .align 2, 0
.LharvestSpriteUpdate_378: .word 0xFFFF0000
.LharvestSpriteUpdate_37C:
    movs r4, #2
    add r0, sp, #116
    strh r1, [r0, #0]
    strh r1, [r0, #2]
    mov r8, r0
    cmp r5, #17
    beq .LharvestSpriteUpdate_3C4
    cmp r5, #17
    bgt .LharvestSpriteUpdate_394
    cmp r5, #2
    beq .LharvestSpriteUpdate_39A
    b .LharvestSpriteUpdate_3CE
.LharvestSpriteUpdate_394:
    cmp r5, #37
    beq .LharvestSpriteUpdate_3BA
    b .LharvestSpriteUpdate_3CE
.LharvestSpriteUpdate_39A:
    cmp r6, #17
    beq .LharvestSpriteUpdate_3AE
    cmp r6, #37
    bne .LharvestSpriteUpdate_3CE
    movs r4, #37
    add r0, sp, #120
    bl method_0800CE58__4Barn
    ldr r0, [sp, #120]
    b .LharvestSpriteUpdate_3CC
.LharvestSpriteUpdate_3AE:
    movs r4, #17
    add r0, sp, #124
    bl method_0800C554__4Coop
    ldr r0, [sp, #124]
    b .LharvestSpriteUpdate_3CC
.LharvestSpriteUpdate_3BA:
    add r0, sp, #128
    bl smethod_08009ADC__4Farm
    ldr r0, [sp, #128]
    b .LharvestSpriteUpdate_3CC
.LharvestSpriteUpdate_3C4:
    add r0, sp, #132
    bl smethod_08009AE8__4Farm
    ldr r0, [sp, #132]
.LharvestSpriteUpdate_3CC:
    str r0, [sp, #116]
.LharvestSpriteUpdate_3CE:
    mov r3, r8
    movs r5, #0
    ldrsh r2, [r3, r5]
    add r0, sp, #116
    movs r6, #2
    ldrsh r3, [r0, r6]
    adds r0, r7, #0
    adds r1, r4, #0
    bl SetLocation__7AEntityUiii
    adds r0, r7, #0
    adds r0, #32
    ldrb r2, [r0, #0]
    adds r0, r7, #0
    movs r1, #0
    movs r3, #0
    bl func_08034180
    movs r0, #0
    ldr r1, [sp, #152]
    strh r0, [r1, #0]
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_3FA:
    ldr r2, [sp, #152]
    ldrh r0, [r2, #0]
    cmp r0, #0
    bne .LharvestSpriteUpdate_4B8
    adds r0, r7, #0
    bl func_08034940
    lsls r0, r0, #24
    cmp r0, #0
    beq .LharvestSpriteUpdate_410
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_410:
    ldrb r1, [r4, #0]
    ldr r0, [r7, #56]
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, [r7, #60]
    mov r2, sl
    bl func_08033584
    lsls r0, r0, #24
    cmp r0, #0
    beq .LharvestSpriteUpdate_4D4
    mov r0, r8
    bl GetCurrentTask__C13HarvestSprite
    adds r1, r0, #0
    mov r0, r8
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    bl func_08033914
    adds r6, r0, #0
    add r4, sp, #88
    movs r3, #0
    ldrsh r1, [r4, r3]
    adds r5, r4, #0
    movs r2, #2
    ldrsh r0, [r5, r2]
    ldr r3, [sp, #160]
    subs r0, r0, r3
    ldr r4, [sp, #156]
    subs r1, r1, r4
    cmp r1, #0
    bge .LharvestSpriteUpdate_454
    negs r1, r1
.LharvestSpriteUpdate_454:
    cmp r0, #0
    bge .LharvestSpriteUpdate_45A
    negs r0, r0
.LharvestSpriteUpdate_45A:
    adds r0, r1, r0
    lsrs r1, r0, #31
    adds r0, r0, r1
    asrs r0, r0, #1
    lsls r0, r0, #16
    adds r1, r6, #0
    bl __divsi3
    add r3, sp, #140
    str r0, [r3, #0]
    movs r2, #180
    add r0, sp, #136
    str r2, [r0, #0]
    ldr r1, [r3, #0]
    cmp r2, r1
    bls .LharvestSpriteUpdate_47C
    adds r0, r3, #0
.LharvestSpriteUpdate_47C:
    ldr r0, [r0, #0]
    bl RandomBelow
    ldr r1, [sp, #152]
    strh r0, [r1, #0]
    adds r0, r7, #0
    adds r0, #32
    ldrb r4, [r0, #0]
    add r0, sp, #8
    bl Empty__19ActorMovementBounds
    add r0, sp, #88
    movs r3, #0
    ldrsh r2, [r0, r3]
    movs r1, #2
    ldrsh r3, [r5, r1]
    add r5, sp, #8
    str r5, [sp, #0]
    str r4, [sp, #4]
    ldr r0, [sp, #156]
    ldr r1, [sp, #160]
    bl SelectApproachFacing
    adds r2, r0, #0
    adds r0, r7, #0
    movs r1, #1
    adds r3, r6, #0
    bl func_08034180
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_4B8:
    subs r0, #1
    ldr r6, [sp, #152]
    strh r0, [r6, #0]
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_4C0:
    mov r1, r8
    ldrh r0, [r1, #32]
    cmp r0, #0
    bne .LharvestSpriteUpdate_4DC
    adds r0, r7, #0
    bl func_08034940
    lsls r0, r0, #24
    cmp r0, #0
    bne .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_4D4:
    adds r0, r7, #0
    bl func_080342D8
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_4DC:
    subs r0, #1
    mov r2, r8
    strh r0, [r2, #32]
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_4E4:
    movs r3, #10
    ldrsh r1, [r7, r3]
    movs r0, #180
    lsls r0, r0, #1
    cmp r1, r0
    bne .LharvestSpriteUpdate_546
    ldr r0, [r7, #28]
    cmp r0, #0
    blt .LharvestSpriteUpdate_506
    movs r3, #128
    lsls r3, r3, #8
    adds r0, r7, #0
    movs r1, #1
    movs r2, #1
    bl func_08034180
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_506:
    movs r4, #14
    ldrsh r1, [r7, r4]
    movs r0, #8
    negs r0, r0
    cmp r1, r0
    bgt .LharvestSpriteUpdate_57C
    mov r0, r8
    bl TaskDayUpdate__13HarvestSprite
    add r1, sp, #144
    mov r0, r8
    bl method_0809E7C8__13HarvestSpritePCv
    adds r0, r7, #0
    adds r0, #48
    ldrb r1, [r0, #0]
    add r0, sp, #8
    bl InitializeHarvestSpriteHutLocation__FP13ActorLocationUi
    adds r0, r7, #0
    add r1, sp, #8
    bl SetLocation__12AActorEntityRC13ActorLocation
    adds r0, r7, #0
    adds r0, #32
    ldrb r2, [r0, #0]
    adds r0, r7, #0
    movs r1, #0
.LharvestSpriteUpdate_53E:
    movs r3, #0
    bl func_08034180
    b .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_546:
    ldr r2, [r7, #24]
    movs r3, #0
    ldr r0, .LharvestSpriteUpdate_560
    cmp r1, r0
    bgt .LharvestSpriteUpdate_552
    movs r3, #1
.LharvestSpriteUpdate_552:
    adds r0, r3, #0
    cmp r0, #0
    beq .LharvestSpriteUpdate_564
    cmp r2, #0
    ble .LharvestSpriteUpdate_568
    b .LharvestSpriteUpdate_57C
    .align 2, 0
.LharvestSpriteUpdate_560: .word 0x00000167
.LharvestSpriteUpdate_564:
    cmp r2, #0
    blt .LharvestSpriteUpdate_57C
.LharvestSpriteUpdate_568:
    movs r2, #2
    cmp r0, #0
    beq .LharvestSpriteUpdate_570
    movs r2, #3
.LharvestSpriteUpdate_570:
    movs r3, #128
    lsls r3, r3, #8
    adds r0, r7, #0
    movs r1, #1
    bl func_08034180
.LharvestSpriteUpdate_57C:
    adds r4, r7, #0
    adds r4, #66
    ldrb r0, [r4, #0]
    cmp r0, #0
    beq .LharvestSpriteUpdate_5A4
    adds r0, r7, #0
    adds r0, #64
    ldrb r1, [r0, #0]
    adds r0, r7, #0
    bl func_08034248
    adds r1, r0, #0
    ldrh r0, [r7, #34]
    cmp r0, r1
    beq .LharvestSpriteUpdate_5A0
    adds r0, r7, #0
    bl SetAnim__12AActorEntityUi
.LharvestSpriteUpdate_5A0:
    movs r0, #0
    strb r0, [r4, #0]
.LharvestSpriteUpdate_5A4:
    ldr r1, [r7, #28]
    cmp r1, #0
    beq .LharvestSpriteUpdate_5B0
    ldr r0, [r7, #12]
    adds r0, r0, r1
    str r0, [r7, #12]
.LharvestSpriteUpdate_5B0:
    ldr r1, [r7, #24]
    cmp r1, #0
    beq .LharvestSpriteUpdate_5BC
    ldr r0, [r7, #8]
    adds r0, r0, r1
    str r0, [r7, #8]
.LharvestSpriteUpdate_5BC:
    ldrh r0, [r7, #36]
    cmp r0, #0
    beq .LharvestSpriteUpdate_5C6
    subs r0, #1
    b .LharvestSpriteUpdate_5C8
.LharvestSpriteUpdate_5C6:
    ldrh r0, [r7, #38]
.LharvestSpriteUpdate_5C8:
    strh r0, [r7, #36]
    ldr r4, [r7, #16]
    cmp r4, #0
    beq .LharvestSpriteUpdate_5DA
    ldr r0, [r4, #4]
    ldr r1, [r0, #12]
    adds r0, r4, #0
    bl _call_via_r1
.LharvestSpriteUpdate_5DA:
    add sp, #172
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

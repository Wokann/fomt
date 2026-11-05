    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start ChangeMap__14GameSceneWorldRC8Locationb
ChangeMap__14GameSceneWorldRC8Locationb:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x24
    adds r7, r0, #0
    mov r8, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    str r2, [sp, #0xc]
    adds r4, r7, #0
    adds r4, #8
    movs r0, #0xcc
    lsls r0, r0, #1
    adds r5, r7, r0
    cmp r4, r5
    beq .L08019C26
.L08019C10:
    ldr r2, [r4]
    cmp r2, #0
    beq .L08019C20
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x14]
    adds r0, r2, #0
    bl _call_via_r1
.L08019C20:
    adds r4, #4
    cmp r4, r5
    bne .L08019C10
.L08019C26:
    ldr r0, .L08019DF8 @ =gUnk_0300040C
    ldr r0, [r0]
    ldr r1, .L08019DFC @ =0x000004DC
    adds r1, r1, r0
    mov sl, r1
    movs r5, #0
    adds r2, r7, #0
    adds r2, #8
    str r2, [sp, #0x18]
    movs r3, #0xcc
    lsls r3, r3, #1
    adds r3, r7, r3
    str r3, [sp, #0x1c]
    ldr r0, .L08019E00 @ =0x0000107C
    adds r0, r0, r7
    mov sb, r0
    movs r6, #0
    ldr r1, .L08019E04 @ =0x000010B0
    adds r4, r7, r1
.L08019C4C:
    ldr r1, [r4]
    cmp r6, r1
    beq .L08019C62
    cmp r1, #0
    beq .L08019C62
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08019C62:
    stm r4!, {r6}
    adds r5, #1
    cmp r5, #6
    blo .L08019C4C
    mov r2, r8
    ldrh r0, [r2]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    cmp r0, #2
    beq .L08019C92
    ldr r2, [r7, #4]
    ldr r0, [r2]
    cmp r0, #2
    bne .L08019C92
    ldr r3, .L08019E08 @ =0x00001050
    adds r0, r7, r3
    ldr r1, [r0]
    cmp r1, #0
    beq .L08019C92
    ldr r0, [r2, #0x2c]
    movs r2, #0xb0
    lsls r2, r2, #8
    bl CopyHardwareDma3
.L08019C92:
    ldr r0, [r7, #4]
    ldr r2, .L08019E0C @ =0x00001048
    adds r1, r7, r2
    ldr r2, [r1]
    ldr r3, .L08019E10 @ =0x0000104C
    adds r1, r7, r3
    ldrb r3, [r1]
    movs r1, #0x1e
    subs r1, r1, r3
    str r1, [sp]
    mov r1, r8
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    ldr r0, .L08019E14 @ =0x00001024
    adds r4, r7, r0
    movs r5, #0
    ldr r0, [r4]
    cmp r5, r0
    beq .L08019CC2
    cmp r0, #0
    beq .L08019CC2
    movs r1, #3
    bl _._22EntityAuxiliarySprites
.L08019CC2:
    str r5, [r4]
    mov r4, sb
    movs r5, #0
    ldr r0, [r4]
    cmp r5, r0
    beq .L08019CD8
    cmp r0, #0
    beq .L08019CD8
    movs r1, #3
    bl _._22GameSceneWeatherEffect
.L08019CD8:
    str r5, [r4]
    ldr r1, .L08019E18 @ =0x00001028
    adds r4, r7, r1
    movs r5, #0
    ldr r0, [r4]
    cmp r5, r0
    beq .L08019CF0
    cmp r0, #0
    beq .L08019CF0
    movs r1, #3
    bl _._18WorldSpriteEffects
.L08019CF0:
    str r5, [r4]
    movs r2, #0
    str r2, [sp, #0x10]
    mov r3, sl
    str r3, [sp, #0x20]
.L08019CFA:
    ldr r1, [sp, #0x20]
    ldrb r0, [r1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    str r0, [sp, #0x14]
    cmp r0, #1
    bne .L08019D98
    ldrh r4, [r1, #2]
    lsls r4, r4, #0x16
    lsrs r4, r4, #0x16
    ldr r0, [r7]
    ldr r1, [r0, #0x14]
    adds r0, r7, #0
    bl _call_via_r1
    cmp r4, r0
    bne .L08019D98
    ldr r2, .L08019E04 @ =0x000010B0
    adds r2, r2, r7
    mov sb, r2
    ldr r3, [sp, #0x10]
    lsls r0, r3, #2
    add sb, r0
    movs r0, #0x4c
    bl __builtin_new
    adds r6, r0, #0
    ldr r0, [r7]
    ldr r1, [r0, #0x64]
    adds r0, r7, #0
    bl _call_via_r1
    adds r5, r0, #0
    ldr r0, [sp, #0x20]
    ldrh r0, [r0, #8]
    mov sl, r0
    adds r0, r6, #0
    adds r1, r7, #0
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .L08019E1C @ =__vt_20GameSceneGroupSprite
    str r0, [r6, #0x24]
    movs r1, #0x28
    adds r1, r1, r6
    mov r8, r1
    ldr r4, [r5]
    add r0, sp, #4
    ldr r3, [r4, #0xc]
    adds r1, r5, #0
    mov r2, sl
    bl _call_via_r3
    ldr r0, [sp, #4]
    ldrh r2, [r0]
    mov r0, r8
    ldr r3, [r4, #0x10]
    adds r1, r5, #0
    bl _call_via_r3
    adds r0, r6, #0
    adds r0, #0x48
    mov r2, sp
    ldrb r2, [r2, #0x14]
    strb r2, [r0]
    mov r4, sb
    ldr r1, [r4]
    cmp r6, r1
    beq .L08019D96
    cmp r1, #0
    beq .L08019D96
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08019D96:
    str r6, [r4]
.L08019D98:
    ldr r3, [sp, #0x20]
    adds r3, #0xc
    str r3, [sp, #0x20]
    ldr r0, [sp, #0x10]
    adds r0, #1
    str r0, [sp, #0x10]
    cmp r0, #6
    blo .L08019CFA
    movs r0, #0xa0
    bl __builtin_new
    adds r1, r7, #0
    bl __22EntityAuxiliarySpritesP10GameObject
    ldr r1, .L08019E14 @ =0x00001024
    adds r5, r7, r1
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L08019DCA
    cmp r0, #0
    beq .L08019DCA
    movs r1, #3
    bl _._22EntityAuxiliarySprites
.L08019DCA:
    str r4, [r5]
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08019E52
    ldr r0, [r7, #4]
    ldr r1, [r0]
    ldr r2, .L08019E20 @ =0x00001038
    adds r0, r7, r2
    ldr r0, [r0]
    adds r0, #8
    cmp r1, #0x2e
    beq .L08019E2C
    cmp r1, #0x2e
    ble .L08019E24
    cmp r1, #0x2f
    beq .L08019E30
    b .L08019E34
    .align 2, 0
.L08019DF8: .word gUnk_0300040C
.L08019DFC: .word 0x000004DC
.L08019E00: .word 0x0000107C
.L08019E04: .word 0x000010B0
.L08019E08: .word 0x00001050
.L08019E0C: .word 0x00001048
.L08019E10: .word 0x0000104C
.L08019E14: .word 0x00001024
.L08019E18: .word 0x00001028
.L08019E1C: .word __vt_20GameSceneGroupSprite
.L08019E20: .word 0x00001038
.L08019E24:
    cmp r1, #0x2c
    blt .L08019E34
    movs r0, #0
    b .L08019E36
.L08019E2C:
    movs r0, #1
    b .L08019E36
.L08019E30:
    movs r0, #2
    b .L08019E36
.L08019E34:
    ldr r0, [r0]
.L08019E36:
    cmp r0, #1
    beq .L08019E40
    cmp r0, #2
    beq .L08019E4A
    b .L08019E52
.L08019E40:
    adds r0, r7, #0
    movs r1, #1
    bl SetWorldWeatherEffect
    b .L08019E52
.L08019E4A:
    adds r0, r7, #0
    movs r1, #0
    bl SetWorldWeatherEffect
.L08019E52:
    movs r0, #4
    bl __builtin_new
    ldr r1, [r7, #4]
    ldr r2, [r1, #4]
    adds r1, r7, #0
    bl __18WorldSpriteEffectsP10GameObjecti
    ldr r3, .L08019F28 @ =0x00001028
    adds r5, r7, r3
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L08019E78
    cmp r0, #0
    beq .L08019E78
    movs r1, #3
    bl _._18WorldSpriteEffects
.L08019E78:
    str r4, [r5]
    adds r0, r7, #0
    bl RefreshWorldFireplaceSprite
    adds r0, r7, #0
    bl RefreshWorldVase
    adds r0, r7, #0
    bl RefreshWorldBeachHouseSprite
    adds r0, r7, #0
    bl RefreshWorldHillSeasonalSprites
    adds r0, r7, #0
    bl RefreshWorldWinterAndFireplaceSprites
    adds r0, r7, #0
    bl RepositionBlockedFarmHouseEntities
    ldr r4, [sp, #0x18]
    ldr r5, [sp, #0x1c]
    cmp r4, r5
    beq .L08019EBC
.L08019EA6:
    ldr r2, [r4]
    cmp r2, #0
    beq .L08019EB6
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x10]
    adds r0, r2, #0
    bl _call_via_r1
.L08019EB6:
    adds r4, #4
    cmp r4, r5
    bne .L08019EA6
.L08019EBC:
    ldr r0, [sp, #0xc]
    cmp r0, #0
    beq .L08019EEC
    ldr r1, .L08019F2C @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, .L08019F30 @ =0x0000214C
    adds r0, r0, r2
    bl HasRegisteredEvents__C14GameEventState
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08019EE6
    ldr r3, .L08019F34 @ =0x00001054
    adds r0, r7, r3
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08019EEC
.L08019EE6:
    adds r0, r7, #0
    bl UpdateWorldBackgroundAudio
.L08019EEC:
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08019F16
    movs r1, #0x82
    lsls r1, r1, #5
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, [r0]
    lsls r1, r2, #0xb
    lsrs r1, r1, #0x1b
    lsls r2, r2, #5
    lsrs r2, r2, #0x1a
    adds r0, r7, #0
    movs r3, #1
    bl UpdateWorldTimeOfDayPalettes
.L08019F16:
    add sp, #0x24
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08019F28: .word 0x00001028
.L08019F2C: .word 0x00001038
.L08019F30: .word 0x0000214C
.L08019F34: .word 0x00001054

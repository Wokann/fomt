    .include "asm/macro.inc"
    .include "six/asm/hw/memory.s"
    .include "six/asm/hw/video.s"

    .syntax unified
    .thumb
    .text

    @ JP uses 384 bytes of stack locals and the overseas builds use 324.
    thumb_func_start InitializeShopScreenDisplay
InitializeShopScreenDisplay:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    .ifdef REGION_JP
    sub sp, #384
    mov sl, r0
    bl GetHardwareDisplayState
    add r2, sp, #12
    movs r3, #226
    lsls r3, r3, #5
    adds r1, r3, #0
    strh r1, [r2, #0]
    strh r1, [r0, #8]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r4, .Lshop210
    adds r1, r4, #0
    strh r1, [r2, #0]
    strh r1, [r0, #10]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r5, .Lshop214
    adds r1, r5, #0
    strh r1, [r2, #0]
    strh r1, [r0, #12]
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #12
    movs r7, #250
    lsls r7, r7, #5
    adds r1, r7, #0
    .else
    sub sp, #324
    adds r7, r0, #0
    bl GetHardwareDisplayState
    add r2, sp, #12
    movs r3, #226
    lsls r3, r3, #5
    adds r1, r3, #0
    strh r1, [r2, #0]
    strh r1, [r0, #8]
    adds r0, r7, #0
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r4, .Lshop210
    adds r1, r4, #0
    strh r1, [r2, #0]
    strh r1, [r0, #10]
    adds r0, r7, #0
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r5, .Lshop214
    adds r1, r5, #0
    strh r1, [r2, #0]
    strh r1, [r0, #12]
    adds r0, r7, #0
    bl GetHardwareDisplayState
    add r2, sp, #12
    movs r6, #250
    lsls r6, r6, #5
    adds r1, r6, #0
    .endif
    strh r1, [r2, #0]
    strh r1, [r0, #14]
    movs r4, #1
    negs r4, r4
    ldr r0, .Lshop218
    mov sb, r0
    movs r5, #128
    lsls r5, r5, #4
    adds r0, r4, #0
    mov r1, sb
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r6, .Lshop21C
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r1, .Lshop220
    adds r0, r4, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    movs r1, #192
    lsls r1, r1, #19
    mov r8, r1
    movs r2, #128
    lsls r2, r2, #8
    movs r0, #0
    bl FillHardwareDma3
    .ifdef REGION_JP
    mov r0, sl
    .else
    adds r0, r7, #0
    .endif
    bl GetHardwareDisplayState
    add r1, sp, #12
    movs r3, #242
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1, #0]
    movs r4, #0
    strh r2, [r0, #0]
    ldr r0, .LshopSharedTiles
    ldr r0, [r0, #0]
    ldr r1, .LshopSharedTileByteCount
    ldr r2, [r1, #0]
    mov r1, r8
    bl CopyHardwareDma3
    ldr r0, .Lshop22C
    adds r1, r6, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    movs r0, #3
    str r0, [sp, #0]
    str r4, [sp, #4]
    str r4, [sp, #8]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #0
    movs r3, #30
    bl DrawUiTextWindowBorder
    ldr r0, .LshopSharedPalette
    ldr r0, [r0, #0]
    movs r1, #160
    lsls r1, r1, #19
    movs r2, #32
    bl CopyHardwareDma3
    ldr r0, .Lshop234
    mov r1, sb
    adds r2, r5, #0
    bl FillHardwareDma3
    .ifdef REGION_JP
    mov r0, sl
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r4, .Lshop238
    adds r1, r4, #0
    strh r1, [r2, #0]
    strh r1, [r0, #30]
    movs r5, #0
    mov sb, r5
    movs r7, #130
    lsls r7, r7, #1
    add r7, sp
    mov r8, r7
    mov r0, sp
    adds r0, #20
    str r0, [sp, #320]
    movs r1, #132
    lsls r1, r1, #1
    add r1, sp
    str r1, [sp, #360]
    movs r2, #134
    lsls r2, r2, #1
    add r2, sp
    str r2, [sp, #364]
    mov r3, sp
    adds r3, #148
    str r3, [sp, #328]
    mov r4, sp
    adds r4, #164
    str r4, [sp, #332]
    mov r5, sp
    adds r5, #180
    str r5, [sp, #336]
    mov r7, sp
    adds r7, #196
    str r7, [sp, #344]
    adds r0, #192
    str r0, [sp, #348]
    mov r1, sp
    adds r1, #228
    str r1, [sp, #352]
    mov r2, sp
    adds r2, #244
    str r2, [sp, #356]
    ldr r5, .Lshop23C
    movs r7, #2
    mov r6, r8
    ldr r4, .LshopDigits
.Lshop13A:
    ldrh r1, [r4, #0]
    strh r7, [r6, #0]
    mov r3, r8
    strh r7, [r3, #2]
    ldr r0, [r6, #0]
    str r1, [sp, #0]
    movs r1, #0
    str r1, [sp, #4]
    movs r2, #1
    str r2, [sp, #8]
    add r1, sp, #20
    movs r2, #0
    movs r3, #0
    bl DrawCharacterGlyphTo2DGfxBufferExt
    ldr r0, [sp, #320]
    adds r1, r5, #0
    movs r2, #128
    bl CopyHardwareDma3
    adds r5, #128
    adds r4, #2
    movs r3, #1
    add sb, r3
    mov r0, sb
    cmp r0, #9
    ble .Lshop13A
    movs r0, #210
    lsls r0, r0, #2
    add r0, sl
    bl func_08050D5C
    movs r4, #2
    movs r6, #0
    add r0, sp, #264
    strh r4, [r0, #0]
    ldr r1, [sp, #360]
    strh r4, [r1, #2]
    ldr r0, [r0, #0]
    ldr r5, .Lshop244
    add r5, sl
    adds r1, r5, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .LshopGoldUnit
    movs r2, #1
    mov r8, r2
    add r0, sp, #268
    strh r4, [r0, #0]
    ldr r3, [sp, #364]
    strh r4, [r3, #2]
    ldr r0, [r0, #0]
    str r1, [sp, #0]
    str r6, [sp, #4]
    str r2, [sp, #8]
    adds r1, r5, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r6, r0, #0
    add r0, sp, #148
    adds r1, r5, #0
    ldr r2, .Lshop24C
    movs r3, #128
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r4, [sp, #328]
    mov sb, r4
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp25C
    cmp r1, #0
    beq .LshopJp1F0
    adds r0, r1, #0
    adds r1, r4, #0
    ldmia r1!, {r2, r5, r7}
    stmia r0!, {r2, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp1F0:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    mov r3, sl
    adds r3, #28
    str r3, [sp, #324]
    movs r4, #202
    lsls r4, r4, #3
    add r4, sl
    str r4, [sp, #372]
    ldr r5, .Lshop250
    add r5, sl
    str r5, [sp, #340]
    ldr r7, .Lshop254
    add r7, sl
    str r7, [sp, #368]
    .else
    adds r0, r7, #0
    bl GetHardwareDisplayState
    add r2, sp, #12
    ldr r4, .Lshop238
    adds r1, r4, #0
    strh r1, [r2, #0]
    strh r1, [r0, #30]
    movs r5, #0
    mov sl, r5
    add r6, sp, #196
    mov r8, r6
    mov r0, sp
    adds r0, #20
    str r0, [sp, #304]
    mov r1, sp
    adds r1, #200
    str r1, [sp, #284]
    adds r2, #192
    str r2, [sp, #288]
    mov r3, sp
    adds r3, #84
    str r3, [sp, #256]
    mov r4, sp
    adds r4, #100
    str r4, [sp, #260]
    mov r5, sp
    adds r5, #116
    str r5, [sp, #264]
    mov r6, sp
    adds r6, #132
    str r6, [sp, #268]
    adds r0, #128
    str r0, [sp, #272]
    subs r1, #36
    str r1, [sp, #276]
    subs r2, #24
    str r2, [sp, #280]
    movs r3, #1
    mov sb, r3
    ldr r5, .Lshop23C
    mov r6, r8
    ldr r4, .LshopDigits
.Lshop13A:
    ldrh r1, [r4, #0]
    mov r0, sb
    strh r0, [r6, #0]
    movs r3, #2
    mov r2, r8
    strh r3, [r2, #2]
    ldr r0, [r6, #0]
    str r1, [sp, #0]
    movs r1, #0
    str r1, [sp, #4]
    mov r2, sb
    str r2, [sp, #8]
    add r1, sp, #20
    movs r2, #0
    movs r3, #0
    bl DrawCharacterGlyphTo2DGfxBufferExt
    ldr r0, [sp, #304]
    adds r1, r5, #0
    movs r2, #64
    bl CopyHardwareDma3
    adds r5, #64
    adds r4, #2
    movs r3, #1
    add sl, r3
    mov r0, sl
    cmp r0, #9
    ble .Lshop13A
    movs r1, #210
    lsls r1, r1, #2
    adds r0, r7, r1
    bl func_08050D5C
    movs r4, #2
    movs r6, #0
    add r0, sp, #200
    strh r4, [r0, #0]
    ldr r2, [sp, #284]
    strh r4, [r2, #2]
    ldr r0, [r0, #0]
    ldr r3, .Lshop244
    adds r5, r7, r3
    adds r1, r5, #0
    movs r2, #0
    bl Clear2DGfxBuffer
    ldr r1, .LshopGoldUnit
    movs r0, #1
    mov sb, r0
    add r0, sp, #204
    strh r4, [r0, #0]
    ldr r2, [sp, #288]
    strh r4, [r2, #2]
    ldr r0, [r0, #0]
    str r1, [sp, #0]
    str r6, [sp, #4]
    mov r3, sb
    str r3, [sp, #8]
    adds r1, r5, #0
    movs r2, #0
    movs r3, #0
    bl DrawStringTo2DGfxBufferExt
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    str r0, [sp, #312]
    add r0, sp, #84
    adds r1, r5, #0
    ldr r2, .Lshop24C
    movs r3, #128
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r4, [sp, #256]
    mov sl, r4
    ldr r5, [sp, #312]
    ldr r1, [r5, #4]
    ldr r0, [r5, #12]
    cmp r1, r0
    beq .Lshop258
    cmp r1, #0
    beq .Lshop1EC
    adds r0, r1, #0
    adds r1, r4, #0
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop1EC:
    ldr r4, [sp, #312]
    ldr r0, [r4, #4]
    adds r0, #16
    str r0, [r4, #4]
    adds r5, r7, #0
    adds r5, #28
    str r5, [sp, #308]
    movs r6, #202
    lsls r6, r6, #3
    adds r6, r7, r6
    str r6, [sp, #300]
    ldr r0, .Lshop250
    adds r0, r7, r0
    str r0, [sp, #292]
    ldr r1, .Lshop254
    adds r1, r7, r1
    str r1, [sp, #296]
    .endif
    b .Lshop34C
    .align 2, 0
.Lshop210: .word 0x1D42
.Lshop214: .word 0x3E41
.Lshop218: .word MEM_VRAM + 0xE800
.Lshop21C: .word MEM_VRAM + 0xF000
.Lshop220: .word MEM_VRAM + 0xF800
.LshopSharedTiles: .word gUiSharedTiles
.LshopSharedTileByteCount: .word gUiSharedTileByteCount
.Lshop22C: .word 0x30003
.LshopSharedPalette: .word gUiSharedPalette
.Lshop234: .word 0x3FF03FF
.Lshop238: .word 0x1EB
.Lshop23C: .word MEM_VRAM + 0x1400
.LshopDigits: .word gShopDigitGlyphs
.Lshop244: .word 0x454
.LshopGoldUnit: .word gText_ShopCommon_GoldUnit
.Lshop24C: .word MEM_VRAM + 0x400
.Lshop250: .word 0x56C
.Lshop254: .word 0x5DC
    .ifdef REGION_JP
.LshopJp25C:
    str r1, [sp, #376]
    add r1, sp, #276
    mov r0, r8
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r2, [sp, #376]
    subs r0, r2, r0
    asrs r4, r0, #4
    add r0, sp, #272
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #272
    cmp r4, r0
    bcs .LshopJp27C
    adds r1, r2, #0
.LshopJp27C:
    ldr r0, [r1, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop294
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lshop298
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lshop298
.Lshop294:
    movs r0, #0
    mov r8, r0
.Lshop298:
    adds r5, r0, #0
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    mov r4, sl
    adds r4, #28
    str r4, [sp, #324]
    movs r5, #202
    lsls r5, r5, #3
    add r5, sl
    str r5, [sp, #372]
    ldr r7, .Lshop2F4
    add r7, sl
    str r7, [sp, #340]
    ldr r0, .Lshop2F8
    add r0, sl
    str r0, [sp, #368]
    ldr r1, [sp, #376]
    cmp r2, r1
    beq .Lshop2D8
.Lshop2C0:
    cmp r3, #0
    beq .Lshop2D0
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop2D0:
    adds r2, #16
    adds r3, #16
    ldr r0, [sp, #376]
    cmp r2, r0
    bne .Lshop2C0
.Lshop2D8:
    adds r5, r3, #0
    add r0, sp, #276
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJp308
    cmp r5, #0
    beq .Lshop2F0
    adds r0, r5, #0
    mov r1, sb
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop2F0:
    adds r5, #16
    b .LshopJp32A
    .align 2, 0
.Lshop2F4: .word 0x56C
.Lshop2F8: .word 0x5DC
.LshopJp308:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lshop322
.Lshop304:
    cmp r2, #0
    beq .LshopJp320
    adds r0, r2, #0
    mov r1, sb
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp320:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .Lshop304
.Lshop322:
    adds r5, r2, #0
.LshopJp32A:
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    .else
.Lshop258:
    mov r8, r1
    add r1, sp, #212
    mov r2, sb
    str r2, [r1, #0]
    ldr r3, [sp, #312]
    ldr r0, [r3, #0]
    mov r4, r8
    subs r0, r4, r0
    asrs r4, r0, #4
    add r0, sp, #208
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    cmp r4, r2
    bcs .Lshop276
    adds r0, r1, #0
.Lshop276:
    ldr r0, [r0, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop294
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop298
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop298
.Lshop294:
    movs r0, #0
    mov sb, r0
.Lshop298:
    adds r5, r0, #0
    str r5, [sp, #316]
    ldr r5, [sp, #312]
    ldr r2, [r5, #0]
    ldr r3, [sp, #316]
    adds r6, r7, #0
    adds r6, #28
    str r6, [sp, #308]
    movs r0, #202
    lsls r0, r0, #3
    adds r0, r7, r0
    str r0, [sp, #300]
    ldr r1, .Lshop2F4
    adds r1, r7, r1
    str r1, [sp, #292]
    ldr r4, .Lshop2F8
    adds r4, r7, r4
    str r4, [sp, #296]
    cmp r2, r8
    beq .Lshop2D8
.Lshop2C0:
    cmp r3, #0
    beq .Lshop2D0
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop2D0:
    adds r2, #16
    adds r3, #16
    cmp r2, r8
    bne .Lshop2C0
.Lshop2D8:
    adds r5, r3, #0
    ldr r1, [sp, #212]
    cmp r1, #1
    bne .Lshop2FC
    cmp r5, #0
    beq .Lshop2F0
    adds r0, r5, #0
    mov r1, sl
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop2F0:
    adds r5, #16
    b .Lshop324
    .align 2, 0
.Lshop2F4: .word 0x56C
.Lshop2F8: .word 0x5DC
.Lshop2FC:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .Lshop322
.Lshop304:
    cmp r2, #0
    beq .Lshop314
    adds r0, r2, #0
    mov r1, sl
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop314:
    movs r0, #1
    negs r0, r0
    add r8, r0
    adds r2, #16
    mov r1, r8
    cmp r1, #0
    bne .Lshop304
.Lshop322:
    adds r5, r2, #0
.Lshop324:
    ldr r3, [sp, #312]
    ldr r2, [r3, #4]
    ldr r0, [r3, #0]
    .endif
    adds r1, r0, #0
    cmp r0, r2
    beq .Lshop336
.Lshop330:
    adds r1, #16
    cmp r1, r2
    bne .Lshop330
.Lshop336:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJp342
    bl free
.LshopJp342:
    ldr r0, [sp, #380]
    add r0, r8
    ldr r7, [sp, #380]
    str r7, [r6, #0]
    .else
    beq .Lshop33E
    bl free
.Lshop33E:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r4, [sp, #316]
    ldr r6, [sp, #312]
    str r4, [r6, #0]
    .endif
    str r5, [r6, #4]
    str r0, [r6, #12]
.Lshop34C:
    ldr r0, .Lshop3B4
    movs r1, #0
    str r1, [sp, #0]
    movs r1, #32
    str r1, [sp, #4]
    movs r2, #2
    movs r3, #2
    bl Fill2DGfxTilemapRect
    .ifdef REGION_JP
    mov r0, sl
    bl func_080C8550
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    movs r0, #213
    lsls r0, r0, #2
    add r0, sl
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    adds r2, r0, #0
    adds r6, r4, #0
    ldr r1, .LshopObjTiles
    lsls r2, r2, #5
    ldr r0, .Lshop3BC
    adds r2, r2, r0
    add r0, sp, #148
    movs r3, #128
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [sp, #328]
    mov sb, r1
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp3C0
    cmp r1, #0
    beq .LshopJp3AA
    adds r0, r1, #0
    ldr r1, [sp, #328]
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp3AA:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .LshopJp48E
    .align 2, 0
.Lshop3B4: .word MEM_VRAM + 0xFFB4
.LshopObjTiles: .word gFarmStatusCreatureIcon11Tiles
.Lshop3BC: .word OBJ_VRAM0
.LshopJp3C0:
    str r1, [sp, #376]
    movs r0, #1
    add r1, sp, #284
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r5, [sp, #376]
    subs r0, r5, r0
    asrs r4, r0, #4
    add r0, sp, #280
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #280
    cmp r4, r0
    bcs .LshopJp3E0
    adds r1, r2, #0
.LshopJp3E0:
    ldr r0, [r1, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop3FC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lshop400
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lshop400
.Lshop3FC:
    movs r0, #0
    mov r8, r0
.Lshop400:
    adds r5, r0, #0
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    ldr r7, [sp, #376]
    cmp r2, r7
    beq .Lshop426
.Lshop40E:
    cmp r3, #0
    beq .Lshop41E
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop41E:
    adds r2, #16
    adds r3, #16
    ldr r0, [sp, #376]
    cmp r2, r0
    bne .Lshop40E
.Lshop426:
    adds r5, r3, #0
    add r0, sp, #284
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJp448
    cmp r5, #0
    beq .Lshop43E
    adds r0, r5, #0
    mov r1, sb
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop43E:
    adds r5, #16
    b .Lshop46C
.LshopJp448:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lshop468
.Lshop44A:
    cmp r2, #0
    beq .LshopJp460
    adds r0, r2, #0
    mov r1, sb
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp460:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .Lshop44A
.Lshop468:
    adds r5, r2, #0
.Lshop46C:
    .else
    adds r0, r7, #0
    bl func_080C8550
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    movs r1, #213
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetObjTileIndex
    adds r2, r0, #0
    str r4, [sp, #312]
    ldr r1, .LshopObjTiles
    lsls r2, r2, #5
    ldr r3, .Lshop3BC
    adds r2, r2, r3
    add r0, sp, #84
    movs r3, #128
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r4, [sp, #256]
    mov sl, r4
    ldr r5, [sp, #312]
    ldr r1, [r5, #4]
    ldr r0, [r5, #12]
    cmp r1, r0
    beq .Lshop3C0
    cmp r1, #0
    beq .Lshop3AA
    adds r0, r1, #0
    adds r1, r4, #0
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop3AA:
    ldr r4, [sp, #312]
    ldr r0, [r4, #4]
    adds r0, #16
    str r0, [r4, #4]
    b .Lshop492
    .align 2, 0
.Lshop3B4: .word MEM_VRAM + 0xFFB4
.LshopObjTiles: .word gFarmStatusCreatureIcon11Tiles
.Lshop3BC: .word OBJ_VRAM0
.Lshop3C0:
    mov r8, r1
    movs r0, #1
    add r1, sp, #220
    str r0, [r1, #0]
    ldr r5, [sp, #312]
    ldr r0, [r5, #0]
    mov r6, r8
    subs r0, r6, r0
    asrs r4, r0, #4
    add r0, sp, #216
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    cmp r4, r2
    bcs .Lshop3DE
    adds r0, r1, #0
.Lshop3DE:
    ldr r0, [r0, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop3FC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop400
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop400
.Lshop3FC:
    movs r0, #0
    mov sb, r0
.Lshop400:
    adds r5, r0, #0
    str r5, [sp, #316]
    ldr r0, [sp, #312]
    ldr r2, [r0, #0]
    adds r3, r5, #0
    cmp r2, r8
    beq .Lshop426
.Lshop40E:
    cmp r3, #0
    beq .Lshop41E
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop41E:
    adds r2, #16
    adds r3, #16
    cmp r2, r8
    bne .Lshop40E
.Lshop426:
    adds r5, r3, #0
    ldr r1, [sp, #220]
    cmp r1, #1
    bne .Lshop442
    cmp r5, #0
    beq .Lshop43E
    adds r0, r5, #0
    mov r1, sl
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop43E:
    adds r5, #16
    b .Lshop46A
.Lshop442:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .Lshop468
.Lshop44A:
    cmp r2, #0
    beq .Lshop45A
    adds r0, r2, #0
    mov r1, sl
    ldmia r1!, {r3, r5, r6}
    stmia r0!, {r3, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop45A:
    movs r4, #1
    negs r4, r4
    add r8, r4
    adds r2, #16
    mov r5, r8
    cmp r5, #0
    bne .Lshop44A
.Lshop468:
    adds r5, r2, #0
.Lshop46A:
    ldr r6, [sp, #312]
    .endif
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    adds r1, r0, #0
    cmp r0, r2
    beq .Lshop47C
.Lshop476:
    adds r1, #16
    cmp r1, r2
    bne .Lshop476
.Lshop47C:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJp482
    bl free
.LshopJp482:
    ldr r0, [sp, #380]
    add r0, r8
    ldr r7, [sp, #380]
    str r7, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.LshopJp48E:
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    movs r0, #215
    lsls r0, r0, #2
    add r0, sl
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    adds r6, r4, #0
    ldr r1, .LshopObjPalette
    lsls r2, r2, #5
    ldr r0, .Lshop4E8
    adds r2, r2, r0
    add r0, sp, #148
    movs r3, #32
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [sp, #328]
    mov sb, r1
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp4E4
    cmp r1, #0
    beq .LshopJp4D2
    adds r0, r1, #0
    ldr r1, [sp, #328]
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp4D2:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .Lshop5BE
    .align 2, 0
.LshopObjPalette: .word gFarmStatusCreatureIcon11Palette
.Lshop4E8: .word OBJ_PALETTE
.LshopJp4E4:
    str r1, [sp, #376]
    movs r0, #1
    add r1, sp, #292
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r5, [sp, #376]
    subs r0, r5, r0
    asrs r4, r0, #4
    add r0, sp, #288
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #288
    cmp r4, r0
    bcs .LshopJp504
    adds r1, r2, #0
.LshopJp504:
    ldr r0, [r1, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop528
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lshop52C
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lshop52C
.Lshop528:
    movs r0, #0
    mov r8, r0
.Lshop52C:
    adds r5, r0, #0
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    ldr r7, [sp, #376]
    cmp r2, r7
    beq .Lshop552
.Lshop53A:
    cmp r3, #0
    beq .Lshop54A
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop54A:
    adds r2, #16
    adds r3, #16
    ldr r0, [sp, #376]
    cmp r2, r0
    bne .Lshop53A
.Lshop552:
    adds r5, r3, #0
    add r0, sp, #292
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJp56C
    cmp r5, #0
    beq .Lshop56A
    adds r0, r5, #0
    mov r1, sb
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop56A:
    adds r5, #16
    b .Lshop598
.LshopJp56C:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lshop594
.Lshop576:
    cmp r2, #0
    beq .LshopJp584
    adds r0, r2, #0
    mov r1, sb
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp584:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .Lshop576
.Lshop594:
    adds r5, r2, #0
.Lshop598:
    .else
    beq .Lshop484
    bl free
.Lshop484:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r1, [sp, #316]
    ldr r2, [sp, #312]
    str r1, [r2, #0]
    str r5, [r2, #4]
    str r0, [r2, #12]
.Lshop492:
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    movs r3, #215
    lsls r3, r3, #2
    adds r0, r7, r3
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    str r4, [sp, #312]
    ldr r1, .LshopObjPalette
    lsls r2, r2, #5
    ldr r4, .Lshop4E8
    adds r2, r2, r4
    add r0, sp, #84
    movs r3, #32
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r5, [sp, #256]
    mov sl, r5
    ldr r6, [sp, #312]
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .Lshop4EC
    cmp r1, #0
    beq .Lshop4D8
    adds r0, r1, #0
    adds r1, r5, #0
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop4D8:
    ldr r5, [sp, #312]
    ldr r0, [r5, #4]
    adds r0, #16
    str r0, [r5, #4]
    b .Lshop5BE
    .align 2, 0
.LshopObjPalette: .word gFarmStatusCreatureIcon11Palette
.Lshop4E8: .word OBJ_PALETTE
.Lshop4EC:
    mov r8, r1
    movs r0, #1
    add r1, sp, #228
    str r0, [r1, #0]
    ldr r6, [sp, #312]
    ldr r0, [r6, #0]
    mov r2, r8
    subs r0, r2, r0
    asrs r4, r0, #4
    add r0, sp, #224
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    cmp r4, r2
    bcs .Lshop50A
    adds r0, r1, #0
.Lshop50A:
    ldr r0, [r0, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop528
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop52C
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop52C
.Lshop528:
    movs r0, #0
    mov sb, r0
.Lshop52C:
    adds r5, r0, #0
    str r5, [sp, #316]
    ldr r3, [sp, #312]
    ldr r2, [r3, #0]
    adds r3, r5, #0
    cmp r2, r8
    beq .Lshop552
.Lshop53A:
    cmp r3, #0
    beq .Lshop54A
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop54A:
    adds r2, #16
    adds r3, #16
    cmp r2, r8
    bne .Lshop53A
.Lshop552:
    adds r5, r3, #0
    ldr r1, [sp, #228]
    cmp r1, #1
    bne .Lshop56E
    cmp r5, #0
    beq .Lshop56A
    adds r0, r5, #0
    mov r1, sl
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop56A:
    adds r5, #16
    b .Lshop596
.Lshop56E:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .Lshop594
.Lshop576:
    cmp r2, #0
    beq .Lshop586
    adds r0, r2, #0
    mov r1, sl
    ldmia r1!, {r3, r5, r6}
    stmia r0!, {r3, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop586:
    movs r4, #1
    negs r4, r4
    add r8, r4
    adds r2, #16
    mov r5, r8
    cmp r5, #0
    bne .Lshop576
.Lshop594:
    adds r5, r2, #0
.Lshop596:
    ldr r6, [sp, #312]
    .endif
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    adds r1, r0, #0
    cmp r0, r2
    beq .Lshop5A8
.Lshop5A2:
    adds r1, #16
    cmp r1, r2
    bne .Lshop5A2
.Lshop5A8:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJp5A6
    bl free
.LshopJp5A6:
    ldr r0, [sp, #380]
    add r0, r8
    ldr r7, [sp, #380]
    str r7, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.Lshop5BE:
    movs r0, #76
    bl __builtin_new
    adds r5, r0, #0
    mov r0, sl
    bl GetHardwareInterruptList
    adds r4, r0, #0
    mov r0, sl
    bl GetHardwareDisplayState
    adds r3, r0, #0
    ldr r0, .Lshop6E8
    str r0, [sp, #0]
    adds r0, r5, #0
    movs r1, #100
    adds r2, r4, #0
    bl __11ScrollStateUiP18HardwareLinkedListP20HardwareDisplayStatePUc
    ldr r6, [sp, #324]
    adds r5, r0, #0
    mov r0, sl
    ldr r4, [r0, #28]
    .else
    beq .Lshop5B0
    bl free
.Lshop5B0:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r1, [sp, #316]
    ldr r2, [sp, #312]
    str r1, [r2, #0]
    str r5, [r2, #4]
    str r0, [r2, #12]
.Lshop5BE:
    movs r0, #76
    bl __builtin_new
    adds r5, r0, #0
    adds r0, r7, #0
    bl GetHardwareInterruptList
    adds r4, r0, #0
    adds r0, r7, #0
    bl GetHardwareDisplayState
    adds r3, r0, #0
    ldr r0, .Lshop6E8
    str r0, [sp, #0]
    adds r0, r5, #0
    movs r1, #100
    adds r2, r4, #0
    bl __11ScrollStateUiP18HardwareLinkedListP20HardwareDisplayStatePUc
    ldr r6, [sp, #308]
    adds r5, r0, #0
    ldr r4, [r7, #28]
    .endif
    cmp r5, r4
    beq .Lshop61E
    cmp r4, #0
    beq .Lshop61E
    adds r0, r4, #0
    adds r0, #40
    movs r1, #2
    bl _._25ScrollBufferUploadCommand
    adds r0, r4, #0
    adds r0, #24
    ldr r2, [r0, #4]
    ldr r1, [r4, #24]
    cmp r1, r2
    beq .Lshop60E
.Lshop608:
    adds r1, #64
    cmp r1, r2
    bne .Lshop608
.Lshop60E:
    ldr r0, [r0, #0]
    cmp r0, #0
    beq .Lshop618
    bl free
.Lshop618:
    adds r0, r4, #0
    bl __builtin_delete
.Lshop61E:
    str r5, [r6, #0]
    .ifdef REGION_JP
    mov r0, sl
    bl GetHardwareDisplayState
    ldrh r1, [r0, #4]
    movs r2, #32
    orrs r1, r2
    strh r1, [r0, #4]
    mov r0, sl
    .else
    adds r0, r7, #0
    bl GetHardwareDisplayState
    ldrh r1, [r0, #4]
    movs r2, #32
    orrs r1, r2
    strh r1, [r0, #4]
    adds r0, r7, #0
    .endif
    bl GetHardwareDisplayState
    ldrh r1, [r0, #4]
    movs r3, #184
    lsls r3, r3, #5
    adds r2, r3, #0
    orrs r1, r2
    strh r1, [r0, #4]
    movs r0, #4
    bl AcknowledgeAndEnableInterrupts
    movs r0, #0
    movs r1, #4
    bl SetInterruptNestingMask
    .ifdef REGION_JP
    ldr r1, .Lshop6EC
    add r1, sl
    strh r0, [r1, #0]
    ldr r0, .Lshop6F0
    add r0, sl
    movs r2, #232
    strh r2, [r0, #0]
    ldr r1, .Lshop6F4
    add r1, sl
    movs r0, #24
    strh r0, [r1, #0]
    ldr r0, .Lshop6F8
    add r0, sl
    strh r2, [r0, #0]
    ldr r1, .Lshop6FC
    add r1, sl
    movs r0, #96
    strh r0, [r1, #0]
    ldr r0, .Lshop700
    add r0, sl
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #372]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #332]
    ldr r3, [r3, #16]
    bl _call_via_r3
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r7, [sp, #336]
    ldr r5, [r7, #0]
    movs r0, #219
    lsls r0, r0, #2
    add r0, sl
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [r7, #0]
    movs r3, #0
    cmp r0, #0
    beq .LshopJp6A8
    ldrh r3, [r7, #4]
.LshopJp6A8:
    adds r6, r4, #0
    lsls r2, r2, #5
    ldr r0, .Lshop704
    adds r2, r2, r0
    add r0, sp, #148
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [sp, #328]
    mov sb, r1
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp6FC
    cmp r1, #0
    beq .Lshop6E0
    adds r0, r1, #0
    ldr r1, [sp, #328]
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop6E0:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .LshopJp7CA
    .else
    ldr r4, .Lshop6EC
    adds r1, r7, r4
    strh r0, [r1, #0]
    ldr r5, .Lshop6F0
    adds r0, r7, r5
    movs r2, #232
    strh r2, [r0, #0]
    ldr r6, .Lshop6F4
    adds r1, r7, r6
    movs r0, #24
    strh r0, [r1, #0]
    ldr r1, .Lshop6F8
    adds r0, r7, r1
    strh r2, [r0, #0]
    ldr r2, .Lshop6FC
    adds r1, r7, r2
    movs r0, #96
    strh r0, [r1, #0]
    ldr r3, .Lshop700
    adds r0, r7, r3
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #300]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #260]
    ldr r3, [r3, #16]
    bl _call_via_r3
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r5, [sp, #116]
    movs r6, #219
    lsls r6, r6, #2
    adds r0, r7, r6
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [sp, #116]
    movs r3, #0
    cmp r0, #0
    beq .Lshop6B2
    ldr r0, [sp, #264]
    ldrh r3, [r0, #4]
.Lshop6B2:
    str r4, [sp, #312]
    lsls r2, r2, #5
    ldr r1, .Lshop704
    adds r2, r2, r1
    add r0, sp, #84
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r2, [sp, #256]
    mov sl, r2
    ldr r1, [r4, #4]
    ldr r0, [r4, #12]
    cmp r1, r0
    beq .Lshop708
    cmp r1, #0
    beq .Lshop6DE
    adds r0, r1, #0
    adds r1, r2, #0
    ldmia r1!, {r3, r4, r5}
    stmia r0!, {r3, r4, r5}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop6DE:
    ldr r6, [sp, #312]
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .Lshop7DA
    .endif
    .align 2, 0
.Lshop6E8: .word MEM_VRAM + 0xE800
.Lshop6EC: .word 0x434
.Lshop6F0: .word 0x564
.Lshop6F4: .word 0x566
.Lshop6F8: .word 0x59C
.Lshop6FC: .word 0x59E
.Lshop700: .word 0x64C
.Lshop704: .word OBJ_PALETTE
    .ifdef REGION_JP
.LshopJp6FC:
    str r1, [sp, #376]
    movs r0, #1
    add r1, sp, #300
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r5, [sp, #376]
    subs r0, r5, r0
    asrs r4, r0, #4
    add r0, sp, #296
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #296
    cmp r4, r0
    bcs .LshopJp71C
    adds r1, r2, #0
.LshopJp71C:
    ldr r0, [r1, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop744
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lshop748
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lshop748
.Lshop744:
    movs r0, #0
    mov r8, r0
.Lshop748:
    adds r5, r0, #0
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    ldr r7, [sp, #376]
    cmp r2, r7
    beq .Lshop76E
.Lshop756:
    cmp r3, #0
    beq .Lshop766
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop766:
    adds r2, #16
    adds r3, #16
    ldr r0, [sp, #376]
    cmp r2, r0
    bne .Lshop756
.Lshop76E:
    adds r5, r3, #0
    add r0, sp, #300
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJp784
    cmp r5, #0
    beq .Lshop786
    adds r0, r5, #0
    mov r1, sb
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop786:
    adds r5, #16
    b .LshopJp7A6
.LshopJp784:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lshop7B0
.Lshop792:
    cmp r2, #0
    beq .LshopJp79C
    adds r0, r2, #0
    mov r1, sb
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp79C:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .Lshop792
.Lshop7B0:
    adds r5, r2, #0
.LshopJp7A6:
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    .else
.Lshop708:
    mov r8, r1
    movs r0, #1
    add r1, sp, #236
    str r0, [r1, #0]
    ldr r2, [sp, #312]
    ldr r0, [r2, #0]
    mov r3, r8
    subs r0, r3, r0
    asrs r4, r0, #4
    add r0, sp, #232
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    cmp r4, r2
    bcs .Lshop726
    adds r0, r1, #0
.Lshop726:
    ldr r0, [r0, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop744
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop748
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop748
.Lshop744:
    movs r0, #0
    mov sb, r0
.Lshop748:
    adds r5, r0, #0
    str r5, [sp, #316]
    ldr r4, [sp, #312]
    ldr r2, [r4, #0]
    adds r3, r5, #0
    cmp r2, r8
    beq .Lshop76E
.Lshop756:
    cmp r3, #0
    beq .Lshop766
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop766:
    adds r2, #16
    adds r3, #16
    cmp r2, r8
    bne .Lshop756
.Lshop76E:
    adds r5, r3, #0
    ldr r1, [sp, #236]
    cmp r1, #1
    bne .Lshop78A
    cmp r5, #0
    beq .Lshop786
    adds r0, r5, #0
    mov r1, sl
    ldmia r1!, {r2, r3, r6}
    stmia r0!, {r2, r3, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop786:
    adds r5, #16
    b .Lshop7B2
.Lshop78A:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .Lshop7B0
.Lshop792:
    cmp r2, #0
    beq .Lshop7A2
    adds r0, r2, #0
    mov r1, sl
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop7A2:
    movs r0, #1
    negs r0, r0
    add r8, r0
    adds r2, #16
    mov r1, r8
    cmp r1, #0
    bne .Lshop792
.Lshop7B0:
    adds r5, r2, #0
.Lshop7B2:
    ldr r3, [sp, #312]
    ldr r2, [r3, #4]
    ldr r0, [r3, #0]
    .endif
    adds r1, r0, #0
    cmp r0, r2
    beq .Lshop7C4
.Lshop7BE:
    adds r1, #16
    cmp r1, r2
    bne .Lshop7BE
.Lshop7C4:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJp7BE
    bl free
.LshopJp7BE:
    ldr r0, [sp, #380]
    add r0, r8
    ldr r7, [sp, #380]
    str r7, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.LshopJp7CA:
    movs r0, #173
    lsls r0, r0, #3
    add r0, sl
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #340]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #344]
    ldr r3, [r3, #16]
    bl _call_via_r3
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r7, [sp, #348]
    ldr r5, [r7, #0]
    movs r0, #225
    lsls r0, r0, #2
    add r0, sl
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [r7, #0]
    movs r3, #0
    cmp r0, #0
    beq .LshopJp80C
    ldrh r3, [r7, #4]
.LshopJp80C:
    adds r6, r4, #0
    lsls r2, r2, #5
    ldr r0, .Lshop854
    adds r2, r2, r0
    add r0, sp, #148
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [sp, #328]
    mov sb, r1
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp844
    cmp r1, #0
    beq .LshopJp838
    adds r0, r1, #0
    ldr r1, [sp, #328]
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp838:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .LshopJp912
    .align 2, 0
.Lshop854: .word OBJ_PALETTE
.LshopJp844:
    str r1, [sp, #376]
    movs r0, #1
    add r1, sp, #308
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r5, [sp, #376]
    subs r0, r5, r0
    asrs r4, r0, #4
    add r0, sp, #304
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #304
    cmp r4, r0
    bcs .LshopJp864
    adds r1, r2, #0
.LshopJp864:
    ldr r0, [r1, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop894
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov r8, r4
    cmp r0, #0
    bne .Lshop898
    mov r0, r8
    bl RetryMemoryAllocation
    b .Lshop898
.Lshop894:
    movs r0, #0
    mov r8, r0
.Lshop898:
    adds r5, r0, #0
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    ldr r7, [sp, #376]
    cmp r2, r7
    beq .Lshop8BE
.Lshop8A6:
    cmp r3, #0
    beq .Lshop8B6
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop8B6:
    adds r2, #16
    adds r3, #16
    ldr r0, [sp, #376]
    cmp r2, r0
    bne .Lshop8A6
.Lshop8BE:
    adds r5, r3, #0
    add r0, sp, #308
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJp8CC
    cmp r5, #0
    beq .Lshop8D6
    adds r0, r5, #0
    mov r1, sb
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop8D6:
    adds r5, #16
    b .Lshop904
.LshopJp8CC:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lshop900
.Lshop8E2:
    cmp r2, #0
    beq .LshopJp8E4
    adds r0, r2, #0
    mov r1, sb
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopJp8E4:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .Lshop8E2
.Lshop900:
    adds r5, r2, #0
.Lshop904:
    .else
    beq .Lshop7CC
    bl free
.Lshop7CC:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r4, [sp, #316]
    ldr r6, [sp, #312]
    str r4, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.Lshop7DA:
    movs r1, #173
    lsls r1, r1, #3
    adds r0, r7, r1
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #292]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #268]
    ldr r3, [r3, #16]
    bl _call_via_r3
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r6, [sp, #272]
    ldr r5, [r6, #0]
    movs r1, #225
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [r6, #0]
    movs r3, #0
    cmp r0, #0
    beq .Lshop81C
    ldrh r3, [r6, #4]
.Lshop81C:
    str r4, [sp, #312]
    lsls r2, r2, #5
    ldr r4, .Lshop854
    adds r2, r2, r4
    add r0, sp, #84
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r5, [sp, #256]
    mov sl, r5
    ldr r6, [sp, #312]
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .Lshop858
    cmp r1, #0
    beq .Lshop84A
    adds r0, r1, #0
    adds r1, r5, #0
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop84A:
    ldr r5, [sp, #312]
    ldr r0, [r5, #4]
    adds r0, #16
    str r0, [r5, #4]
    b .Lshop92A
    .align 2, 0
.Lshop854: .word OBJ_PALETTE
.Lshop858:
    mov r8, r1
    movs r0, #1
    add r1, sp, #244
    str r0, [r1, #0]
    ldr r6, [sp, #312]
    ldr r0, [r6, #0]
    mov r2, r8
    subs r0, r2, r0
    asrs r4, r0, #4
    add r0, sp, #240
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    cmp r4, r2
    bcs .Lshop876
    adds r0, r1, #0
.Lshop876:
    ldr r0, [r0, #0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop894
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop898
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop898
.Lshop894:
    movs r0, #0
    mov sb, r0
.Lshop898:
    adds r5, r0, #0
    str r5, [sp, #316]
    ldr r3, [sp, #312]
    ldr r2, [r3, #0]
    adds r3, r5, #0
    cmp r2, r8
    beq .Lshop8BE
.Lshop8A6:
    cmp r3, #0
    beq .Lshop8B6
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r6}
    stmia r0!, {r4, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop8B6:
    adds r2, #16
    adds r3, #16
    cmp r2, r8
    bne .Lshop8A6
.Lshop8BE:
    adds r5, r3, #0
    ldr r1, [sp, #244]
    cmp r1, #1
    bne .Lshop8DA
    cmp r5, #0
    beq .Lshop8D6
    adds r0, r5, #0
    mov r1, sl
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop8D6:
    adds r5, #16
    b .Lshop902
.Lshop8DA:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .Lshop900
.Lshop8E2:
    cmp r2, #0
    beq .Lshop8F2
    adds r0, r2, #0
    mov r1, sl
    ldmia r1!, {r3, r5, r6}
    stmia r0!, {r3, r5, r6}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop8F2:
    movs r4, #1
    negs r4, r4
    add r8, r4
    adds r2, #16
    mov r5, r8
    cmp r5, #0
    bne .Lshop8E2
.Lshop900:
    adds r5, r2, #0
.Lshop902:
    ldr r6, [sp, #312]
    .endif
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    adds r1, r0, #0
    cmp r0, r2
    beq .Lshop914
.Lshop90E:
    adds r1, #16
    cmp r1, r2
    bne .Lshop90E
.Lshop914:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJp906
    bl free
.LshopJp906:
    ldr r0, [sp, #380]
    add r0, r8
    ldr r7, [sp, #380]
    str r7, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.LshopJp912:
    movs r0, #187
    lsls r0, r0, #3
    add r0, sl
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #368]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #352]
    ldr r3, [r3, #16]
    bl _call_via_r3
    mov r0, sl
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r7, [sp, #356]
    ldr r5, [r7, #0]
    movs r0, #231
    lsls r0, r0, #2
    add r0, sl
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [r7, #0]
    movs r3, #0
    cmp r0, #0
    beq .Lshop96C
    ldrh r3, [r7, #4]
.Lshop96C:
    adds r6, r4, #0
    lsls r2, r2, #5
    ldr r0, .Lshop9A0
    adds r2, r2, r0
    add r0, sp, #148
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [sp, #328]
    mov r8, r1
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .LshopJp98C
    cmp r1, #0
    beq .Lshop998
    adds r0, r1, #0
    mov r1, r8
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop998:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .LshopJpA56
    .align 2, 0
.Lshop9A0: .word OBJ_PALETTE
.LshopJp98C:
    mov sl, r1
    movs r0, #1
    add r1, sp, #316
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    mov r5, sl
    subs r0, r5, r0
    asrs r4, r0, #4
    add r0, sp, #312
    str r4, [r0, #0]
    adds r2, r1, #0
    ldr r0, [r1, #0]
    add r1, sp, #312
    cmp r4, r0
    bcs .LshopJp9AC
    adds r1, r2, #0
.LshopJp9AC:
    ldr r0, [r1, #0]
    .else
    beq .Lshop91C
    bl free
.Lshop91C:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r1, [sp, #316]
    ldr r2, [sp, #312]
    str r1, [r2, #0]
    str r5, [r2, #4]
    str r0, [r2, #12]
.Lshop92A:
    movs r3, #187
    lsls r3, r3, #3
    adds r0, r7, r3
    ldr r1, [r0, #0]
    ldr r3, [r1, #0]
    ldrh r2, [r0, #12]
    lsls r2, r2, #2
    ldr r4, [sp, #296]
    ldr r0, [r4, #0]
    adds r0, r0, r2
    ldrh r2, [r0, #0]
    ldr r0, [sp, #276]
    ldr r3, [r3, #16]
    bl _call_via_r3
    adds r0, r7, #0
    bl GetHardwareDmaQueue
    adds r4, r0, #0
    ldr r6, [sp, #280]
    ldr r5, [r6, #0]
    movs r1, #231
    lsls r1, r1, #2
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetObjPaletteBank
    adds r2, r0, #0
    ldr r0, [r6, #0]
    movs r3, #0
    cmp r0, #0
    beq .Lshop96C
    ldrh r3, [r6, #4]
.Lshop96C:
    adds r6, r4, #0
    lsls r2, r2, #5
    ldr r4, .Lshop9A0
    adds r2, r2, r4
    add r0, sp, #84
    adds r1, r5, #0
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r5, [sp, #256]
    mov r8, r5
    ldr r1, [r6, #4]
    ldr r0, [r6, #12]
    cmp r1, r0
    beq .Lshop9A4
    cmp r1, #0
    beq .Lshop998
    adds r0, r1, #0
    mov r1, r8
    ldmia r1!, {r2, r3, r7}
    stmia r0!, {r2, r3, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.Lshop998:
    ldr r0, [r6, #4]
    adds r0, #16
    str r0, [r6, #4]
    b .LshopA70
    .align 2, 0
.Lshop9A0: .word OBJ_PALETTE
.Lshop9A4:
    str r1, [sp, #320]
    movs r0, #1
    add r1, sp, #252
    str r0, [r1, #0]
    ldr r0, [r6, #0]
    ldr r4, [sp, #320]
    subs r0, r4, r0
    asrs r4, r0, #4
    add r0, sp, #248
    str r4, [r0, #0]
    ldr r2, [r1, #0]
    mov sl, r1
    cmp r4, r2
    bcs .Lshop9C2
    mov r0, sl
.Lshop9C2:
    ldr r0, [r0, #0]
    .endif
    adds r0, r4, r0
    cmp r0, #0
    beq .Lshop9E0
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .Lshop9E4
    mov r0, sb
    bl RetryMemoryAllocation
    b .Lshop9E4
.Lshop9E0:
    movs r0, #0
    mov sb, r0
.Lshop9E4:
    adds r5, r0, #0
    .ifdef REGION_JP
    str r5, [sp, #380]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    cmp r2, sl
    .else
    str r5, [sp, #316]
    ldr r2, [r6, #0]
    adds r3, r5, #0
    ldr r5, [sp, #320]
    cmp r2, r5
    .endif
    beq .LshopA0C
.Lshop9F2:
    cmp r3, #0
    beq .LshopA02
    adds r0, r3, #0
    adds r1, r2, #0
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopA02:
    adds r2, #16
    adds r3, #16
    .ifdef REGION_JP
    cmp r2, sl
    bne .Lshop9F2
.LshopA0C:
    adds r5, r3, #0
    add r0, sp, #316
    ldr r0, [r0, #0]
    cmp r0, #1
    bne .LshopJpA10
    cmp r5, #0
    beq .LshopA26
    adds r0, r5, #0
    mov r1, r8
    ldmia r1!, {r2, r3, r7}
    stmia r0!, {r2, r3, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopA26:
    adds r5, #16
    b .LshopA4C
.LshopJpA10:
    adds r3, r0, #0
    .else
    ldr r7, [sp, #320]
    cmp r2, r7
    bne .Lshop9F2
.LshopA0C:
    adds r5, r3, #0
    mov r0, sl
    ldr r1, [r0, #0]
    cmp r1, #1
    bne .LshopA2A
    cmp r5, #0
    beq .LshopA26
    adds r0, r5, #0
    mov r1, r8
    ldmia r1!, {r2, r3, r4}
    stmia r0!, {r2, r3, r4}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopA26:
    adds r5, #16
    b .LshopA4C
.LshopA2A:
    adds r3, r1, #0
    .endif
    adds r2, r5, #0
    cmp r3, #0
    beq .LshopA4A
.LshopA32:
    cmp r2, #0
    beq .LshopA42
    adds r0, r2, #0
    mov r1, r8
    ldmia r1!, {r4, r5, r7}
    stmia r0!, {r4, r5, r7}
    ldr r1, [r1, #0]
    str r1, [r0, #0]
.LshopA42:
    subs r3, #1
    adds r2, #16
    cmp r3, #0
    bne .LshopA32
.LshopA4A:
    adds r5, r2, #0
.LshopA4C:
    ldr r2, [r6, #4]
    ldr r0, [r6, #0]
    adds r1, r0, #0
    cmp r0, r2
    beq .LshopA5C
.LshopA56:
    adds r1, #16
    cmp r1, r2
    bne .LshopA56
.LshopA5C:
    cmp r0, #0
    .ifdef REGION_JP
    beq .LshopJpA4A
    bl free
.LshopJpA4A:
    ldr r0, [sp, #380]
    add r0, sb
    ldr r1, [sp, #380]
    str r1, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.LshopJpA56:
    add sp, #384
    .else
    beq .LshopA64
    bl free
.LshopA64:
    ldr r0, [sp, #316]
    add r0, sb
    ldr r7, [sp, #316]
    str r7, [r6, #0]
    str r5, [r6, #4]
    str r0, [r6, #12]
.LshopA70:
    add sp, #324
    .endif
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .ifdef REGION_JP
    .align 2, 0
    .endif

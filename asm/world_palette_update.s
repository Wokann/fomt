    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start UpdateWorldTimeOfDayPalettes
UpdateWorldTimeOfDayPalettes:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc4
    str r0, [sp, #0x90]
    adds r4, r1, #0
    adds r7, r2, #0
    lsls r3, r3, #0x18
    lsrs r6, r3, #0x18
    bl GetWorldTimeOfDayPeriod
    adds r1, r0, #0
    ldr r0, [sp, #0x90]
    ldr r3, .L0801A198 @ =0x00001048
    adds r2, r0, r3
    ldr r0, [r2]
    cmp r0, r1
    bne .L0801A172
    lsls r0, r4, #0x18
    str r0, [sp, #0xa8]
    lsls r3, r7, #0x18
    str r3, [sp, #0xac]
    cmp r6, #0
    bne .L0801A172
    b .L0801A7B0
.L0801A172:
    str r1, [r2]
    ldr r6, [sp, #0x90]
    ldr r0, [r6, #4]
    bl SetWorldMapTimeOfDayPalette
    ldr r0, [r6, #4]
    ldr r1, [r0]
    ldr r2, .L0801A19C @ =0x00001038
    adds r0, r6, r2
    ldr r0, [r0]
    adds r0, #8
    cmp r1, #0x2e
    beq .L0801A1A8
    cmp r1, #0x2e
    ble .L0801A1A0
    cmp r1, #0x2f
    beq .L0801A1AC
    b .L0801A1B0
    .align 2, 0
.L0801A198: .word 0x00001048
.L0801A19C: .word 0x00001038
.L0801A1A0:
    cmp r1, #0x2c
    blt .L0801A1B0
    movs r1, #0
    b .L0801A1B2
.L0801A1A8:
    movs r1, #1
    b .L0801A1B2
.L0801A1AC:
    movs r1, #2
    b .L0801A1B2
.L0801A1B0:
    ldr r1, [r0]
.L0801A1B2:
    movs r6, #0xce
    lsls r6, r6, #1
    ldr r3, [sp, #0x90]
    adds r6, r3, r6
    str r6, [sp, #0x94]
    ldr r2, .L0801A21C @ =0x00001048
    adds r0, r3, r2
    ldr r0, [r0]
    str r0, [sp, #0x98]
    str r1, [sp, #0x9c]
    movs r3, #0
    mov r8, r3
    lsls r4, r4, #0x18
    str r4, [sp, #0xa8]
    lsls r4, r7, #0x18
    str r4, [sp, #0xac]
.L0801A1D2:
    ldr r0, [sp, #0x94]
    adds r0, #0x20
    mov r6, r8
    lsls r1, r6, #5
    add r1, r8
    lsls r1, r1, #2
    adds r5, r0, r1
    adds r0, r5, #0
    adds r0, #0x83
    ldrb r0, [r0]
    cmp r0, #0
    bne .L0801A220
    adds r1, r5, #0
    adds r1, #0x20
    adds r0, r5, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r4, r6}
    stm r1!, {r4, r6}
    adds r1, r5, #0
    adds r1, #0x40
    adds r0, r5, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r4, r6}
    stm r1!, {r4, r6}
    adds r1, r5, #0
    adds r1, #0x82
    movs r0, #1
    strb r0, [r1]
    add r0, r8
    mov sb, r0
    b .L0801A7A4
    .align 2, 0
.L0801A21C: .word 0x00001048
.L0801A220:
    adds r1, r5, #0
    adds r1, #0x82
    str r1, [sp, #0xc0]
    movs r2, #1
    add r2, r8
    mov sb, r2
    ldr r3, [sp, #0x9c]
    cmp r3, #(.LblendClearWeatherPalette - .LweatherPaletteCases) / 4 - 1
    bls .L0801A234
    b .L0801A79E
.L0801A234:
    lsls r0, r3, #2
    ldr r1, .L0801A240 @ =.LweatherPaletteCases
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801A240: .word .LweatherPaletteCases
.LweatherPaletteCases:
    .word .LblendClearWeatherPalette @ WEATHER_SUNNY
    .word .L0801A4BC @ WEATHER_RAIN
    .word .L0801A4BC @ WEATHER_SNOW
    .word .LblendClearWeatherPalette @ WEATHER_TYPHOON
    .word .LblendClearWeatherPalette @ WEATHER_SNOWSTORM
.LblendClearWeatherPalette:
    ldr r4, [sp, #0x98]
    cmp r4, #1
    bne .L0801A260
    b .L0801A3A0
.L0801A260:
    cmp r4, #1
    bgt .L0801A274
    cmp r4, #0
    beq .L0801A330
    adds r5, #0x82
    str r5, [sp, #0xc0]
    movs r6, #1
    add r6, r8
    mov sb, r6
    b .L0801A79E
.L0801A274:
    ldr r0, [sp, #0x98]
    cmp r0, #2
    bne .L0801A27C
    b .L0801A404
.L0801A27C:
    adds r1, r5, #0
    adds r1, #0x82
    str r1, [sp, #0xc0]
    movs r2, #1
    add r2, r8
    mov sb, r2
    cmp r0, #3
    beq .L0801A28E
    b .L0801A79E
.L0801A28E:
    add r2, sp, #0x20
    movs r3, #0xa
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A320 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r0, r5, #0
    adds r0, #0x20
    ldr r3, .L0801A324 @ =0x00002529
    str r3, [sp, #0x24]
    mov r1, sp
    adds r6, r2, #0
    adds r7, r0, #0
    add r4, sp, #0x28
    mov r8, r4
    add r4, sp, #0x2c
    mov sl, r4
    adds r4, r2, #0
    cmp sp, r4
    beq .L0801A2D2
    adds r4, r3, #0
.L0801A2CA:
    strh r4, [r1]
    adds r1, #2
    cmp r1, r6
    bne .L0801A2CA
.L0801A2D2:
    ldr r3, [r2]
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A328 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #9
    add r2, sp, #0x28
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa8
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A320 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, r8
    ldr r0, .L0801A32C @ =0x00001BAA
    str r0, [sp, #0x2c]
    mov r0, sp
    add r2, sp, #0x20
    cmp sp, r2
    bne .L0801A310
    b .L0801A6D8
.L0801A310:
    mov r6, sl
    ldr r1, [r6]
.L0801A314:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A314
    b .L0801A6D8
    .align 2, 0
.L0801A320: .word 0xFFFFFC1F
.L0801A324: .word 0x00002529
.L0801A328: .word BlendRgb5PaletteBank
.L0801A32C: .word 0x00001BAA
.L0801A330:
    add r2, sp, #0x30
    movs r3, #9
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa8
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A394 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r6, r5, #0
    adds r6, #0x20
    ldr r0, .L0801A398 @ =0x00001BAA
    str r0, [sp, #0x34]
    mov r1, sp
    add r4, sp, #0x20
    adds r7, r6, #0
    ldr r3, .L0801A39C @ =BlendRgb5PaletteBank
    mov ip, r3
    adds r3, r5, #0
    adds r3, #0x82
    str r3, [sp, #0xc0]
    movs r3, #1
    add r3, r8
    mov sb, r3
    cmp sp, r4
    beq .L0801A378
.L0801A370:
    strh r0, [r1]
    adds r1, #2
    cmp r1, r4
    bne .L0801A370
.L0801A378:
    ldr r3, [r2]
    adds r0, r6, #0
    mov r1, sp
    adds r2, r5, #0
    bl _call_via_ip
    adds r0, r7, #0
    adds r0, #0x20
    adds r1, r5, #0
    movs r2, #0x20
    bl memcpy
    b .L0801A79E
    .align 2, 0
.L0801A394: .word 0xFFFFFC1F
.L0801A398: .word 0x00001BAA
.L0801A39C: .word BlendRgb5PaletteBank
.L0801A3A0:
    adds r4, r5, #0
    adds r4, #0x20
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x20
    bl memcpy
    add r2, sp, #0x38
    movs r3, #3
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xd8
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A400 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, #0x20
    adds r3, r2, #0
    movs r1, #8
    lsls r2, r1, #5
    movs r0, #0x20
    orrs r2, r0
    lsls r1, r1, #0xa
    orrs r2, r1
    str r2, [sp, #0x3c]
    mov r0, sp
    add r1, sp, #0x20
    adds r6, r5, #0
    adds r6, #0x82
    str r6, [sp, #0xc0]
    movs r6, #1
    add r6, r8
    mov sb, r6
    cmp sp, r1
    bne .L0801A3F4
    b .L0801A6D8
.L0801A3F4:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .L0801A3F4
    b .L0801A6D8
    .align 2, 0
.L0801A400: .word 0xFFFFFC1F
.L0801A404:
    add r2, sp, #0x40
    movs r3, #3
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xd8
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A4B0 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r6, r5, #0
    adds r6, #0x20
    adds r3, r2, #0
    movs r1, #8
    lsls r2, r1, #5
    movs r0, #0x20
    orrs r2, r0
    lsls r1, r1, #0xa
    orrs r2, r1
    str r2, [sp, #0x44]
    mov r4, sp
    add r0, sp, #0x20
    adds r7, r6, #0
    add r1, sp, #0x48
    mov sl, r1
    mov r1, sp
    adds r1, #0x4c
    str r1, [sp, #0xb0]
    adds r1, r5, #0
    adds r1, #0x82
    str r1, [sp, #0xc0]
    movs r1, #1
    add r1, r8
    mov sb, r1
    cmp sp, r0
    beq .L0801A460
    adds r1, r2, #0
.L0801A458:
    strh r1, [r4]
    adds r4, #2
    cmp r4, r0
    bne .L0801A458
.L0801A460:
    ldr r3, [r3]
    adds r0, r6, #0
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A4B4 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #0xa
    add r2, sp, #0x48
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A4B0 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, sl
    ldr r0, .L0801A4B8 @ =0x00002529
    str r0, [sp, #0x4c]
    mov r0, sp
    add r2, sp, #0x20
    cmp sp, r2
    bne .L0801A4A0
    b .L0801A6D8
.L0801A4A0:
    ldr r6, [sp, #0xb0]
    ldr r1, [r6]
.L0801A4A4:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A4A4
    b .L0801A6D8
    .align 2, 0
.L0801A4B0: .word 0xFFFFFC1F
.L0801A4B4: .word BlendRgb5PaletteBank
.L0801A4B8: .word 0x00002529
.L0801A4BC:
    ldr r0, [sp, #0x98]
    cmp r0, #1
    bne .L0801A4C4
    b .L0801A63C
.L0801A4C4:
    cmp r0, #1
    bgt .L0801A4D8
    cmp r0, #0
    beq .L0801A590
    adds r5, #0x82
    str r5, [sp, #0xc0]
    movs r1, #1
    add r1, r8
    mov sb, r1
    b .L0801A79E
.L0801A4D8:
    ldr r2, [sp, #0x98]
    cmp r2, #2
    bne .L0801A4E0
    b .L0801A6F4
.L0801A4E0:
    adds r3, r5, #0
    adds r3, #0x82
    str r3, [sp, #0xc0]
    movs r4, #1
    add r4, r8
    mov sb, r4
    cmp r2, #3
    beq .L0801A4F2
    b .L0801A79E
.L0801A4F2:
    add r2, sp, #0x50
    movs r3, #0xa
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A580 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r6, r5, #0
    adds r6, #0x20
    ldr r0, .L0801A584 @ =0x00002529
    str r0, [sp, #0x54]
    mov r1, sp
    add r4, sp, #0x20
    adds r7, r6, #0
    add r3, sp, #0x58
    mov r8, r3
    add r3, sp, #0x5c
    mov sl, r3
    cmp sp, r4
    beq .L0801A532
.L0801A52A:
    strh r0, [r1]
    adds r1, #2
    cmp r1, r4
    bne .L0801A52A
.L0801A532:
    ldr r3, [r2]
    adds r0, r6, #0
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A588 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #0xa
    add r2, sp, #0x58
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A580 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, r8
    ldr r0, .L0801A58C @ =0x00006A32
    str r0, [sp, #0x5c]
    mov r0, sp
    add r2, sp, #0x20
    cmp sp, r2
    bne .L0801A572
    b .L0801A6D8
.L0801A572:
    mov r6, sl
    ldr r1, [r6]
.L0801A576:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A576
    b .L0801A6D8
    .align 2, 0
.L0801A580: .word 0xFFFFFC1F
.L0801A584: .word 0x00002529
.L0801A588: .word BlendRgb5PaletteBank
.L0801A58C: .word 0x00006A32
.L0801A590:
    add r2, sp, #0x60
    movs r3, #0xa
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A630 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x20
    adds r0, r0, r5
    mov ip, r0
    ldr r6, .L0801A634 @ =0x00006A32
    str r6, [sp, #0x64]
    mov r1, sp
    add r4, sp, #0x20
    mov r7, ip
    add r3, sp, #0x68
    mov sl, r3
    mov r0, sp
    adds r0, #0x6c
    str r0, [sp, #0xb4]
    adds r3, r5, #0
    adds r3, #0x82
    str r3, [sp, #0xc0]
    movs r0, #1
    add r0, r8
    mov sb, r0
    cmp sp, r4
    beq .L0801A5E2
    adds r0, r6, #0
.L0801A5DA:
    strh r0, [r1]
    adds r1, #2
    cmp r1, r4
    bne .L0801A5DA
.L0801A5E2:
    ldr r3, [r2]
    mov r0, ip
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A638 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #0xa
    add r2, sp, #0x68
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A630 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, sl
    ldr r0, .L0801A634 @ =0x00006A32
    str r0, [sp, #0x6c]
    mov r0, sp
    add r2, sp, #0x20
    cmp sp, r2
    beq .L0801A6D8
    ldr r6, [sp, #0xb4]
    ldr r1, [r6]
.L0801A624:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A624
    b .L0801A6D8
    .align 2, 0
.L0801A630: .word 0xFFFFFC1F
.L0801A634: .word 0x00006A32
.L0801A638: .word BlendRgb5PaletteBank
.L0801A63C:
    add r2, sp, #0x70
    movs r3, #0xa
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A6E8 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x20
    adds r0, r0, r5
    mov ip, r0
    ldr r6, .L0801A6EC @ =0x00006A32
    str r6, [sp, #0x74]
    mov r1, sp
    add r4, sp, #0x20
    mov r7, ip
    add r3, sp, #0x78
    mov sl, r3
    mov r0, sp
    adds r0, #0x7c
    str r0, [sp, #0xb8]
    adds r3, r5, #0
    adds r3, #0x82
    str r3, [sp, #0xc0]
    movs r0, #1
    add r0, r8
    mov sb, r0
    cmp sp, r4
    beq .L0801A68E
    adds r0, r6, #0
.L0801A686:
    strh r0, [r1]
    adds r1, #2
    cmp r1, r4
    bne .L0801A686
.L0801A68E:
    ldr r3, [r2]
    mov r0, ip
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A6F0 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #0xa
    add r2, sp, #0x78
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A6E8 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, sl
    ldr r0, .L0801A6EC @ =0x00006A32
    str r0, [sp, #0x7c]
    mov r0, sp
    add r2, sp, #0x20
    cmp sp, r2
    beq .L0801A6D8
    ldr r6, [sp, #0xb8]
    ldr r1, [r6]
.L0801A6D0:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A6D0
.L0801A6D8:
    ldr r3, [r3]
    adds r0, r4, #0
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A6F0 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    b .L0801A79E
    .align 2, 0
.L0801A6E8: .word 0xFFFFFC1F
.L0801A6EC: .word 0x00006A32
.L0801A6F0: .word BlendRgb5PaletteBank
.L0801A6F4:
    add r2, sp, #0x80
    movs r3, #0xa
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A898 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r6, r5, #0
    adds r6, #0x20
    ldr r4, .L0801A89C @ =0x00006A32
    add r0, sp, #0x84
    str r4, [r0]
    mov r0, sp
    add r1, sp, #0x20
    adds r7, r6, #0
    add r3, sp, #0x88
    mov sl, r3
    mov r3, sp
    adds r3, #0x8c
    str r3, [sp, #0xbc]
    adds r3, r5, #0
    adds r3, #0x82
    str r3, [sp, #0xc0]
    movs r3, #1
    add r3, r8
    mov sb, r3
    cmp sp, r1
    beq .L0801A744
.L0801A73C:
    strh r4, [r0]
    adds r0, #2
    cmp r0, r1
    bne .L0801A73C
.L0801A744:
    ldr r3, [r2]
    adds r0, r6, #0
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A8A0 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r3, #0xa
    add r2, sp, #0x88
    ldrb r1, [r2]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #2
    ldrh r1, [r2]
    ldr r0, .L0801A898 @ =0xFFFFFC1F
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r7, #0
    adds r4, #0x20
    mov r3, sl
    ldr r0, .L0801A8A4 @ =0x00002529
    ldr r6, [sp, #0xbc]
    str r0, [r6]
    mov r0, sp
    add r2, sp, #0x20
    add r1, sp, #0x8c
    cmp sp, r2
    beq .L0801A790
    ldr r1, [r1]
.L0801A788:
    strh r1, [r0]
    adds r0, #2
    cmp r0, r2
    bne .L0801A788
.L0801A790:
    ldr r3, [r3]
    adds r0, r4, #0
    mov r1, sp
    adds r2, r5, #0
    ldr r4, .L0801A8A0 @ =BlendRgb5PaletteBank
    bl _call_via_r4
.L0801A79E:
    movs r0, #1
    ldr r1, [sp, #0xc0]
    strb r0, [r1]
.L0801A7A4:
    mov r8, sb
    mov r2, r8
    cmp r2, #0x16
    bhs .L0801A7AE
    b .L0801A1D2
.L0801A7AE:
    movs r6, #1
.L0801A7B0:
    ldr r3, [sp, #0xa8]
    lsrs r4, r3, #0x18
    ldr r0, [sp, #0xac]
    lsrs r5, r0, #0x18
    ldr r1, [sp, #0x90]
    ldr r2, .L0801A8A8 @ =0x00001038
    adds r0, r1, r2
    ldr r0, [r0]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    adds r2, r0, #0
    ldr r3, [sp, #0x90]
    ldr r1, .L0801A8AC @ =0x00001048
    adds r0, r3, r1
    ldr r3, [r0]
    adds r0, r4, #0
    adds r1, r5, #0
    bl GetTimeOfDayTransitionValue
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r2, [sp, #0x90]
    ldr r3, .L0801A8B0 @ =0x0000104C
    adds r5, r2, r3
    ldrb r0, [r5]
    cmp r0, r1
    bne .L0801A7EC
    cmp r6, #0
    beq .L0801A886
.L0801A7EC:
    strb r1, [r5]
    ldr r4, [sp, #0x90]
    ldr r0, [r4, #4]
    ldrb r1, [r5]
    movs r4, #0x1e
    subs r2, r4, r1
    bl BlendTimeOfDayPalettes__17GameSceneWorldMapUiUi
    ldrb r1, [r5]
    subs r4, r4, r1
    movs r6, #0
    mov sb, r6
    movs r0, #0x1f
    ands r1, r0
    str r1, [sp, #0xa4]
    ldr r0, [sp, #0x90]
    ldr r1, .L0801A8B4 @ =0x0000023E
    adds r0, r0, r1
    mov r8, r0
    ldr r2, [sp, #0x90]
    movs r3, #0xfe
    lsls r3, r3, #1
    adds r7, r2, r3
    movs r0, #0xee
    lsls r0, r0, #1
    adds r6, r2, r0
    subs r1, #0x22
    adds r5, r2, r1
    movs r0, #0x1f
    ands r4, r0
    lsls r4, r4, #5
    mov sl, r4
.L0801A82C:
    movs r2, #0x20
    rsbs r2, r2, #0
    adds r1, r2, #0
    ldr r0, [sp, #0xa0]
    ands r0, r1
    ldr r3, [sp, #0xa4]
    orrs r0, r3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r1, .L0801A8B8 @ =0xFFFFFF00
    ldr r4, [sp, #0xa0]
    ands r4, r1
    orrs r4, r0
    str r4, [sp, #0xa0]
    ldr r0, .L0801A898 @ =0xFFFFFC1F
    adds r1, r0, #0
    adds r0, r4, #0
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r1, .L0801A8BC @ =0xFFFF0000
    ands r4, r1
    orrs r4, r0
    str r4, [sp, #0xa0]
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    adds r3, r4, #0
    ldr r4, .L0801A8A0 @ =BlendRgb5PaletteBank
    bl _call_via_r4
    movs r0, #1
    mov r2, r8
    strb r0, [r2]
    movs r3, #0x84
    add r8, r3
    adds r7, #0x84
    adds r6, #0x84
    adds r5, #0x84
    add sb, r0
    mov r4, sb
    cmp r4, #0x16
    blo .L0801A82C
.L0801A886:
    add sp, #0xc4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801A898: .word 0xFFFFFC1F
.L0801A89C: .word 0x00006A32
.L0801A8A0: .word BlendRgb5PaletteBank
.L0801A8A4: .word 0x00002529
.L0801A8A8: .word 0x00001038
.L0801A8AC: .word 0x00001048
.L0801A8B0: .word 0x0000104C
.L0801A8B4: .word 0x0000023E
.L0801A8B8: .word 0xFFFFFF00
.L0801A8BC: .word 0xFFFF0000

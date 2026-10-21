    .include "asm/macro.inc"
    @ Background setup and regional animation helpers; the loop is in C++.
    .section .text
    .syntax unified
    .thumb
    .align 2, 0

    .section .text.intro_scene_core_after_startup

    thumb_func_start InitializeIntroSceneBackground
InitializeIntroSceneBackground:
    push	{r4, r5, lr}
    sub	sp, #4
    adds	r5, r0, #0
    ldr r1, .L08000FE0
    movs	r0, #0
    movs	r2, #32
    bl FillHardwareDma3
    movs	r0, #1
    negs	r0, r0
    ldr r4, .L08000FE4
    movs	r2, #128	@ 0x80
    lsls	r2, r2, #4
    adds	r1, r4, #0
    bl FillHardwareDma3
    ldr r0, .L08000FE8
    movs	r1, #192	@ 0xc0
    lsls	r1, r1, #19
    bl Unpack
    ldr r0, .L08000FEC
    movs	r1, #160	@ 0xa0
    lsls	r1, r1, #19
    movs	r2, #32
    bl CopyHardwareDma3
    ldr r0, .L08000FF0
    adds	r1, r4, #0
    bl Unpack
    adds	r0, r5, #0
    bl func_08008918
    mov	r1, sp
    movs	r3, #132	@ 0x84
    lsls	r3, r3, #4
    adds	r2, r3, #0
    strh	r2, [r1, #0]
    movs	r4, #0
    strh	r2, [r0, #0]
    adds	r0, r5, #0
    bl func_08008918
    mov	r2, sp
    ldr r3, .L08000FF4
    adds	r1, r3, #0
    strh	r1, [r2, #0]
    strh	r1, [r0, #14]
    adds	r0, r5, #0
    bl func_08008918
    mov	r1, sp
    strh	r4, [r1, #0]
    strh	r4, [r0, #28]
    adds	r0, r5, #0
    bl func_08008918
    mov	r1, sp
    strh	r4, [r1, #0]
    strh	r4, [r0, #30]
    add	sp, #4
    pop	{r4, r5}
    pop	{r0}
    bx	r0
    .align 2, 0
.L08000FE0:
    .4byte 0x06007FE0
.L08000FE4:
    .4byte 0x0600F800
.L08000FE8:
    .4byte gSharedSceneBackgroundTiles
.L08000FEC:
    .4byte gSharedSceneBackgroundPalette
.L08000FF0:
    .4byte gSharedSceneBackgroundLayer1Tilemap
.L08000FF4:
    .4byte 0x00001F43
    thumb_func_end InitializeIntroSceneBackground

    .section .text.intro_scene_core_after_sequence

    thumb_func_start InitializeIntroSceneSequenceResources
InitializeIntroSceneSequenceResources: @ 0x080019D8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L08001DAC @ =0xFFFFEFC8
    add sp, r4
    adds r7, r0, #0
    ldr r1, .L08001DB0 @ =0x06007FE0
    movs r0, #0
    movs r2, #0x20
    bl FillHardwareDma3
    movs r4, #1
    rsbs r4, r4, #0
    ldr r1, .L08001DB4 @ =0x0600C000
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r4, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r1, .L08001DB8 @ =0x0600D000
    adds r0, r4, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r1, .L08001DBC @ =0x0600E000
    adds r0, r4, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r1, .L08001DC0 @ =0x0600F000
    adds r0, r4, #0
    adds r2, r5, #0
    bl FillHardwareDma3
    ldr r0, .L08001DC4 @ =gIntroSceneStartupTiles
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl Unpack
    ldr r0, .L08001DC8 @ =gIntroSceneStartupPaletteBanks
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r2, #0x80
    lsls r2, r2, #2
    bl CopyHardwareDma3
    movs r4, #0
    add r0, sp, #8
    mov sb, r0
    add r1, sp, #0x10
    mov sl, r1
    mov r2, sp
    adds r2, #0x18
    ldr r3, .L08001DCC @ =0x00001030
    add r3, sp
    str r2, [r3]
    mov r5, sp
    adds r5, #0x20
    ldr r0, .L08001DD0 @ =0x00001034
    add r0, sp
    str r5, [r0]
    ldr r1, .L08001DD4 @ =0x00006BA4
    adds r1, r7, r1
    ldr r2, .L08001DD8 @ =0x0000101C
    add r2, sp
    str r1, [r2]
    ldr r3, .L08001DDC @ =0x00006BC4
    adds r3, r7, r3
    movs r5, #0x81
    lsls r5, r5, #5
    add r5, sp
    str r3, [r5]
    ldr r0, .L08001DE0 @ =0x00006AA4
    adds r0, r7, r0
    movs r1, #0x80
    lsls r1, r1, #5
    add r1, sp
    str r0, [r1]
    ldr r2, .L08001DE4 @ =0x00006AC4
    adds r2, r7, r2
    ldr r3, .L08001DE8 @ =0x00001004
    add r3, sp
    str r2, [r3]
    ldr r5, .L08001DEC @ =0x00006AE4
    adds r5, r7, r5
    ldr r0, .L08001DF0 @ =0x00001008
    add r0, sp
    str r5, [r0]
    ldr r1, .L08001DF4 @ =0x00006B04
    adds r1, r7, r1
    ldr r2, .L08001DF8 @ =0x0000100C
    add r2, sp
    str r1, [r2]
    ldr r3, .L08001DFC @ =0x00006B24
    adds r3, r7, r3
    ldr r5, .L08001E00 @ =0x00001010
    add r5, sp
    str r3, [r5]
    ldr r0, .L08001E04 @ =0x00006B44
    adds r0, r7, r0
    ldr r1, .L08001E08 @ =0x00001014
    add r1, sp
    str r0, [r1]
    ldr r2, .L08001E0C @ =0x00006B84
    adds r2, r7, r2
    ldr r3, .L08001E10 @ =0x00001018
    add r3, sp
    str r2, [r3]
    ldr r5, .L08001E14 @ =0x00006BE4
    adds r5, r7, r5
    ldr r0, .L08001E18 @ =0x00001024
    add r0, sp
    str r5, [r0]
.L08001AC0:
    ldr r1, .L08001E1C @ =gUnk_080E8684
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r0, [r0]
    mov r1, sp
    bl Unpack
    lsls r0, r4, #0xc
    movs r3, #0
    adds r4, #1
    mov r8, r4
    ldr r1, .L08001E20 @ =0x00006C04
    adds r1, r7, r1
    ldr r2, .L08001E24 @ =0x00001028
    add r2, sp
    str r1, [r2]
    ldr r4, .L08001E28 @ =0x00006C24
    adds r4, r7, r4
    ldr r5, .L08001E2C @ =0x0000102C
    add r5, sp
    str r4, [r5]
    movs r1, #0xc0
    lsls r1, r1, #8
    adds r1, r1, r0
    mov ip, r1
.L08001AF2:
    lsls r2, r3, #6
    lsls r1, r3, #7
    adds r6, r3, #1
    add r0, sp, #0x40
    adds r4, r1, r0
    mov r5, sp
    adds r3, r1, r5
    add r2, ip
    movs r5, #0x1f
.L08001B04:
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r1, r2, r0
    ldrh r0, [r3]
    strh r0, [r1]
    ldr r0, .L08001E30 @ =0x06000800
    adds r1, r2, r0
    ldrh r0, [r4]
    strh r0, [r1]
    adds r4, #2
    adds r3, #2
    adds r2, #2
    subs r5, #1
    cmp r5, #0
    bge .L08001B04
    adds r3, r6, #0
    cmp r3, #0x1f
    ble .L08001AF2
    mov r4, r8
    cmp r4, #3
    ble .L08001AC0
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    movs r3, #0xfa
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r1]
    movs r4, #0
    strh r2, [r0]
    adds r0, r7, #0
    bl func_08008918
    mov r2, sp
    ldr r5, .L08001E34 @ =0x00005843
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #8]
    adds r0, r7, #0
    bl func_08008918
    mov r2, sp
    ldr r3, .L08001E38 @ =0x00005A42
    adds r1, r3, #0
    strh r1, [r2]
    strh r1, [r0, #0xa]
    adds r0, r7, #0
    bl func_08008918
    mov r2, sp
    ldr r5, .L08001E3C @ =0x00005C41
    adds r1, r5, #0
    strh r1, [r2]
    strh r1, [r0, #0xc]
    adds r0, r7, #0
    bl func_08008918
    mov r2, sp
    ldr r3, .L08001E40 @ =0x00005E40
    adds r1, r3, #0
    strh r1, [r2]
    strh r1, [r0, #0xe]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x10]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x12]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x14]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x16]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x18]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x1a]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x1c]
    adds r0, r7, #0
    bl func_08008918
    mov r1, sp
    strh r4, [r1]
    strh r4, [r0, #0x1e]
    mov r0, sp
    str r4, [sp]
    strh r4, [r0, #4]
    str r4, [sp, #8]
    mov r5, sb
    strh r4, [r5, #4]
    str r4, [sp, #0x10]
    mov r0, sl
    strh r4, [r0, #4]
    str r4, [sp, #0x18]
    ldr r1, .L08001DCC @ =0x00001030
    add r1, sp
    ldr r1, [r1]
    strh r4, [r1, #4]
    ldr r2, .L08001E44 @ =0x00006BA0
    adds r0, r7, r2
    ldr r1, [r0]
    ldr r3, [r1]
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    ldr r4, .L08001DD8 @ =0x0000101C
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x20
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    ldr r5, .L08001DD0 @ =0x00001034
    add r5, sp
    ldr r6, [r5]
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r4, r5}
    stm r1!, {r4, r5}
    ldr r0, [sp, #0x10]
    movs r1, #0x90
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, .L08001E48 @ =0x05000320
    movs r2, #0xe0
    bl CopyHardwareDma3
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L08001C5A
    mov r3, sb
    ldrh r2, [r3, #4]
.L08001C5A:
    ldr r1, .L08001E4C @ =0x06010000
    bl CopyHardwareDma3
    ldr r0, [sp, #8]
    movs r1, #0
    cmp r0, #0
    beq .L08001C6C
    mov r4, sb
    ldrh r1, [r4, #4]
.L08001C6C:
    lsrs r0, r1, #5
    ldr r5, .L08001E50 @ =0x00006C60
    adds r4, r7, r5
    strh r0, [r4]
    ldr r1, .L08001E54 @ =0x00006BB8
    adds r0, r7, r1
    movs r2, #0xf0
    lsls r2, r2, #0xf
    mov r8, r2
    str r2, [r0]
    ldr r3, .L08001E58 @ =0x00006BBC
    adds r1, r7, r3
    ldr r0, .L08001E5C @ =0xFFA00000
    str r0, [r1]
    subs r5, #0xa0
    adds r0, r7, r5
    ldr r1, [r0]
    ldr r2, [r1]
    mov ip, r2
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    movs r3, #0x81
    lsls r3, r3, #5
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    mov r5, ip
    ldr r3, [r5, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r3, [sp, #8]
    movs r5, #0
    ldrsh r0, [r4, r5]
    lsls r0, r0, #5
    ldr r2, .L08001E4C @ =0x06010000
    adds r1, r0, r2
    movs r2, #0
    cmp r3, #0
    beq .L08001CDE
    mov r4, sb
    ldrh r2, [r4, #4]
.L08001CDE:
    adds r0, r3, #0
    bl CopyHardwareDma3
    ldr r5, .L08001E60 @ =0x00006BD8
    adds r0, r7, r5
    mov r1, r8
    str r1, [r0]
    ldr r2, .L08001E64 @ =0x00006BDC
    adds r1, r7, r2
    movs r0, #0xb0
    lsls r0, r0, #0xf
    str r0, [r1]
    ldr r3, .L08001E68 @ =0x00006AA0
    adds r4, r7, r3
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    movs r4, #0x80
    lsls r4, r4, #5
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    movs r5, #0xd9
    lsls r5, r5, #7
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L08001E6C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08001D5C
    mov r3, sl
    ldrh r2, [r3, #4]
.L08001D5C:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L08001E70 @ =0x00006AB8
    adds r0, r7, r4
    movs r5, #0x84
    lsls r5, r5, #0x11
    str r5, [r0]
    ldr r1, .L08001E74 @ =0x00006ABC
    adds r0, r7, r1
    movs r2, #0x94
    lsls r2, r2, #0x10
    mov r8, r2
    str r2, [r0]
    ldr r3, .L08001E78 @ =0x00006AC0
    adds r4, r7, r3
    ldr r1, .L08001E7C @ =0x00000342
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L08001DE8 @ =0x00001004
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    b .L08001E80
    .align 2, 0
.L08001DAC: .4byte 0xFFFFEFC8
.L08001DB0: .4byte 0x06007FE0
.L08001DB4: .4byte 0x0600C000
.L08001DB8: .4byte 0x0600D000
.L08001DBC: .4byte 0x0600E000
.L08001DC0: .4byte 0x0600F000
.L08001DC4: .4byte gIntroSceneStartupTiles
.L08001DC8: .4byte gIntroSceneStartupPaletteBanks
.L08001DCC: .4byte 0x00001030
.L08001DD0: .4byte 0x00001034
.L08001DD4: .4byte 0x00006BA4
.L08001DD8: .4byte 0x0000101C
.L08001DDC: .4byte 0x00006BC4
.L08001DE0: .4byte 0x00006AA4
.L08001DE4: .4byte 0x00006AC4
.L08001DE8: .4byte 0x00001004
.L08001DEC: .4byte 0x00006AE4
.L08001DF0: .4byte 0x00001008
.L08001DF4: .4byte 0x00006B04
.L08001DF8: .4byte 0x0000100C
.L08001DFC: .4byte 0x00006B24
.L08001E00: .4byte 0x00001010
.L08001E04: .4byte 0x00006B44
.L08001E08: .4byte 0x00001014
.L08001E0C: .4byte 0x00006B84
.L08001E10: .4byte 0x00001018
.L08001E14: .4byte 0x00006BE4
.L08001E18: .4byte 0x00001024
.L08001E1C: .4byte gIntroSceneStartupUnpackSources
.L08001E20: .4byte 0x00006C04
.L08001E24: .4byte 0x00001028
.L08001E28: .4byte 0x00006C24
.L08001E2C: .4byte 0x0000102C
.L08001E30: .4byte 0x06000800
.L08001E34: .4byte 0x00005843
.L08001E38: .4byte 0x00005A42
.L08001E3C: .4byte 0x00005C41
.L08001E40: .4byte 0x00005E40
.L08001E44: .4byte 0x00006BA0
.L08001E48: .4byte 0x05000320
.L08001E4C: .4byte 0x06010000
.L08001E50: .4byte 0x00006C60
.L08001E54: .4byte 0x00006BB8
.L08001E58: .4byte 0x00006BBC
.L08001E5C:
    @ Resource 8 starts at Y=-56 pixels in JP, -96 in the other releases.
    .ifdef REGION_JP
    .4byte 0xFFC80000
    .else
    .4byte 0xFFA00000
    .endif
.L08001E60: .4byte 0x00006BD8
.L08001E64: .4byte 0x00006BDC
.L08001E68: .4byte 0x00006AA0
.L08001E6C: .4byte 0x05000200
.L08001E70: .4byte 0x00006AB8
.L08001E74: .4byte 0x00006ABC
.L08001E78: .4byte 0x00006AC0
.L08001E7C: .4byte 0x00000342
.L08001E80:
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r4, [sp, #0x10]
    ldr r1, .L08002258 @ =0x00006CB8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08001EAE
    mov r3, sl
    ldrh r2, [r3, #4]
.L08001EAE:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L08002260 @ =0x00006AD8
    adds r0, r7, r4
    str r5, [r0]
    ldr r5, .L08002264 @ =0x00006ADC
    adds r0, r7, r5
    mov r1, r8
    str r1, [r0]
    ldr r2, .L08002268 @ =0x00006AE0
    adds r0, r7, r2
    ldr r1, [r0]
    ldr r3, [r1]
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    ldr r4, .L0800226C @ =0x00001008
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    ldr r5, .L08002270 @ =0x00006C90
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08001F1A
    mov r3, sl
    ldrh r2, [r3, #4]
.L08001F1A:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L08002274 @ =0x00006AF8
    adds r0, r7, r4
    movs r5, #0xa0
    lsls r5, r5, #0xe
    str r5, [r0]
    ldr r0, .L08002278 @ =0x00006AFC
    adds r1, r7, r0
    movs r0, #0xa8
    lsls r0, r0, #0xf
    str r0, [r1]
    movs r1, #0xd6
    lsls r1, r1, #7
    adds r4, r7, r1
    ldr r1, .L0800227C @ =0x000002B2
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L08002280 @ =0x0000100C
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    ldr r5, .L08002284 @ =0x00006CA0
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08001F96
    mov r3, sl
    ldrh r2, [r3, #4]
.L08001F96:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L08002288 @ =0x00006B18
    adds r1, r7, r4
    movs r0, #0x88
    lsls r0, r0, #0x11
    str r0, [r1]
    ldr r5, .L0800228C @ =0x00006B1C
    adds r0, r7, r5
    mov r1, r8
    str r1, [r0]
    ldr r2, .L08002290 @ =0x00006B20
    adds r4, r7, r2
    ldr r1, .L08002294 @ =0x00000924
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L08002298 @ =0x00001010
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r5, .L0800229C @ =0x00006B38
    adds r1, r7, r5
    ldr r0, .L080022A0 @ =0xFFF00000
    str r0, [r1]
    ldr r1, .L080022A4 @ =0x00006B3C
    adds r0, r7, r1
    mov r2, r8
    str r2, [r0]
    ldr r3, .L080022A8 @ =0x00006B40
    adds r4, r7, r3
    movs r5, #0xe6
    lsls r5, r5, #3
    adds r0, r4, #0
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    ldr r1, .L080022AC @ =0x00006B60
    adds r0, r7, r1
    adds r1, r5, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L080022B0 @ =0x00001014
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    ldr r5, .L080022B4 @ =0x00006CC8
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L0800206E
    mov r3, sl
    ldrh r2, [r3, #4]
.L0800206E:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L080022B8 @ =0x00006B58
    adds r0, r7, r4
    movs r5, #0xa0
    lsls r5, r5, #0xe
    str r5, [r0]
    ldr r1, .L080022BC @ =0x00006B5C
    adds r0, r7, r1
    movs r2, #0x80
    lsls r2, r2, #0xe
    str r2, [r0]
    ldr r3, .L080022C0 @ =0x00006B78
    adds r1, r7, r3
    movs r0, #0xc8
    lsls r0, r0, #0x10
    str r0, [r1]
    adds r4, #0x24
    adds r0, r7, r4
    str r2, [r0]
    movs r5, #0xd7
    lsls r5, r5, #7
    adds r4, r7, r5
    ldr r1, .L080022C4 @ =0x0000091A
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r0, .L080022C8 @ =0x00001018
    add r0, sp
    ldr r0, [r0]
    mov r8, r0
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r5, [sp, #0x10]
    ldr r1, .L080022CC @ =0x00006CE8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L080020FC
    mov r3, sl
    ldrh r2, [r3, #4]
.L080020FC:
    adds r0, r5, #0
    bl CopyHardwareDma3
    ldr r5, [sp, #8]
    ldr r1, .L080022D0 @ =0x00006CD0
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L080022D4 @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L08002120
    mov r3, sb
    ldrh r2, [r3, #4]
.L08002120:
    adds r0, r5, #0
    bl CopyHardwareDma3
    ldr r1, .L080022D8 @ =0x0000091B
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    mov r5, r8
    ldr r0, [r5]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r5, [sp, #8]
    ldr r1, .L080022DC @ =0x00006CD8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L080022D4 @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L0800217E
    mov r3, sb
    ldrh r2, [r3, #4]
.L0800217E:
    adds r0, r5, #0
    bl CopyHardwareDma3
    ldr r1, .L080022E0 @ =0x0000091C
    adds r0, r4, #0
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L080022C8 @ =0x00001018
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #8]
    ldr r5, .L080022E4 @ =0x00006CE0
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L080022D4 @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L080021E0
    mov r3, sb
    ldrh r2, [r3, #4]
.L080021E0:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r5, .L080022E8 @ =0x00006BE0
    adds r4, r7, r5
    adds r0, r4, #0
    .ifdef REGION_JP
    movs r1, #2
    .else
    movs r1, #1
    .endif
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L080022EC @ =0x00001024
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    movs r5, #0xda
    lsls r5, r5, #7
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L0800225C @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08002248
    mov r3, sl
    ldrh r2, [r3, #4]
.L08002248:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, [sp, #8]
    ldr r5, .L080022F0 @ =0x00006CF0
    adds r0, r7, r5
    ldr r1, [r0, #4]
    b .L080022F4
    .align 2, 0
.L08002258: .4byte 0x00006CB8
.L0800225C: .4byte 0x05000200
.L08002260: .4byte 0x00006AD8
.L08002264: .4byte 0x00006ADC
.L08002268: .4byte 0x00006AE0
.L0800226C: .4byte 0x00001008
.L08002270: .4byte 0x00006C90
.L08002274: .4byte 0x00006AF8
.L08002278: .4byte 0x00006AFC
.L0800227C: .4byte 0x000002B2
.L08002280: .4byte 0x0000100C
.L08002284: .4byte 0x00006CA0
.L08002288: .4byte 0x00006B18
.L0800228C: .4byte 0x00006B1C
.L08002290: .4byte 0x00006B20
.L08002294: .4byte 0x00000924
.L08002298: .4byte 0x00001010
.L0800229C: .4byte 0x00006B38
.L080022A0: .4byte 0xFFF00000
.L080022A4: .4byte 0x00006B3C
.L080022A8: .4byte 0x00006B40
.L080022AC: .4byte 0x00006B60
.L080022B0: .4byte 0x00001014
.L080022B4: .4byte 0x00006CC8
.L080022B8: .4byte 0x00006B58
.L080022BC: .4byte 0x00006B5C
.L080022C0: .4byte 0x00006B78
.L080022C4: .4byte 0x0000091A
.L080022C8: .4byte 0x00001018
.L080022CC: .4byte 0x00006CE8
.L080022D0: .4byte 0x00006CD0
.L080022D4: .4byte 0x06010000
.L080022D8: .4byte 0x0000091B
.L080022DC: .4byte 0x00006CD8
.L080022E0: .4byte 0x0000091C
.L080022E4: .4byte 0x00006CE0
.L080022E8: .4byte 0x00006BE0
.L080022EC: .4byte 0x00001024
.L080022F0: .4byte 0x00006CF0
.L080022F4:
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L0800249C @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L0800230A
    mov r3, sb
    ldrh r2, [r3, #4]
.L0800230A:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L080024A0 @ =0x00006BFC
    adds r0, r7, r4
    movs r5, #0xe0
    lsls r5, r5, #0xf
    str r5, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r4, r7, r0
    adds r0, r4, #0
    .ifdef REGION_JP
    movs r1, #5
    .else
    movs r1, #4
    .endif
    bl ResolveIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r4, .L080024A4 @ =0x00001028
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r4, [sp, #8]
    ldr r1, .L080024A8 @ =0x00006CF8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L0800249C @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L0800237C
    mov r3, sb
    ldrh r2, [r3, #4]
.L0800237C:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L080024AC @ =0x00006C1C
    adds r0, r7, r4
    str r5, [r0]
    ldr r5, .L080024B0 @ =0x00006C20
    adds r0, r7, r5
    ldr r1, [r0]
    ldr r3, [r1]
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    ldr r4, .L080024B4 @ =0x0000102C
    add r4, sp
    ldr r4, [r4]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r6, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r0, r6, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl memcpy
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r4, r5}
    stm r1!, {r2, r4, r5}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    ldr r5, .L080024B8 @ =0x00006D10
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L080024BC @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L080023E0
    mov r3, sl
    ldrh r2, [r3, #4]
.L080023E0:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, [sp, #8]
    ldr r5, .L080024C0 @ =0x00006D08
    adds r0, r7, r5
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L0800249C @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L08002404
    mov r3, sb
    ldrh r2, [r3, #4]
.L08002404:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L080024C4 @ =0x00006C38
    adds r0, r7, r4
    movs r5, #0xf0
    lsls r5, r5, #0xf
    str r5, [r0]
    ldr r0, .L080024C8 @ =0x00006C3C
    adds r1, r7, r0
    movs r0, #0x90
    lsls r0, r0, #0x10
    str r0, [r1]
    ldr r2, .L080024CC @ =0x00006A40
    adds r1, r7, r2
    adds r0, r6, #0
    movs r2, #0
    bl GetGroupData__C22IndexedResourceArchiveUi
    mov r1, sp
    adds r0, r6, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r4, [sp, #0x10]
    ldr r1, .L080024D0 @ =0x00006D20
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl func_080074C0
    lsls r0, r0, #5
    ldr r2, .L080024BC @ =0x05000200
    adds r1, r0, r2
    ldr r0, [sp, #0x10]
    movs r2, #0
    cmp r0, #0
    beq .L08002458
    mov r3, sl
    ldrh r2, [r3, #4]
.L08002458:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, [sp, #8]
    ldr r1, .L080024D4 @ =0x00006D18
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    lsls r0, r0, #5
    ldr r2, .L0800249C @ =0x06010000
    adds r1, r0, r2
    ldr r0, [sp, #8]
    movs r2, #0
    cmp r0, #0
    beq .L0800247C
    mov r3, sb
    ldrh r2, [r3, #4]
.L0800247C:
    adds r0, r4, #0
    bl CopyHardwareDma3
    ldr r4, .L080024D8 @ =0x00006C5C
    adds r0, r7, r4
    str r5, [r0]
    ldr r3, .L080024DC @ =0x00001038
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0800249C: .4byte 0x06010000
.L080024A0: .4byte 0x00006BFC
.L080024A4: .4byte 0x00001028
.L080024A8: .4byte 0x00006CF8
.L080024AC: .4byte 0x00006C1C
.L080024B0: .4byte 0x00006C20
.L080024B4: .4byte 0x0000102C
.L080024B8: .4byte 0x00006D10
.L080024BC: .4byte 0x05000200
.L080024C0: .4byte 0x00006D08
.L080024C4: .4byte 0x00006C38
.L080024C8: .4byte 0x00006C3C
.L080024CC: .4byte 0x00006A40
.L080024D0: .4byte 0x00006D20
.L080024D4: .4byte 0x00006D18
.L080024D8: .4byte 0x00006C5C
.L080024DC: .4byte 0x00001038

    @ Frame drawing remains explicit Thumb until ordinary C++ matches.
    thumb_func_start RenderIntroSceneFrame
RenderIntroSceneFrame:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xa4
    adds r7, r0, #0
    mov r0, sp
    movs r1, #0
    movs r2, #0
    mov r8, r2
    mov r3, r8
    strh r3, [r0]
    strh r3, [r0, #2]
    strh r3, [r0, #4]
    strh r3, [r0, #6]
    strh r3, [r0, #8]
    mov r4, r8
    str r4, [sp, #0xc]
    strb r1, [r0, #0x10]
    strb r1, [r0, #0x11]
    str r4, [sp, #0x14]
    strb r1, [r0, #0x18]
    add r6, sp, #0x1c
    str r4, [sp, #0x1c]
    strh r4, [r6, #4]
    add r5, sp, #0x24
    str r4, [sp, #0x24]
    mov r0, r8
    strh r0, [r5, #4]
    add r0, sp, #0x2c
    mov r1, r8
    str r1, [sp, #0x2c]
    strh r1, [r0, #4]
    add r0, sp, #0x34
    str r1, [sp, #0x34]
    mov r2, r8
    strh r2, [r0, #4]
    ldr r3, .L080028E0 @ =0x00006AB4
    adds r4, r7, r3
    ldr r1, .L080028E4 @ =0x00006AA0
    adds r0, r7, r1
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r2, .L080028E8 @ =0x00006AD4
    adds r4, r7, r2
    ldr r3, .L080028EC @ =0x00006AC0
    adds r0, r7, r3
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r0, .L080028F0 @ =0x00006AF4
    adds r4, r7, r0
    ldr r1, .L080028F4 @ =0x00006AE0
    adds r0, r7, r1
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r2, .L080028F8 @ =0x00006B14
    adds r4, r7, r2
    movs r3, #0xd6
    lsls r3, r3, #7
    adds r0, r7, r3
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r0, .L080028FC @ =0x00006B34
    adds r4, r7, r0
    ldr r1, .L08002900 @ =0x00006B20
    adds r0, r7, r1
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r2, .L08002904 @ =0x00006B54
    adds r4, r7, r2
    ldr r3, .L08002908 @ =0x00006B40
    adds r0, r7, r3
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r4, .L0800290C @ =0x00006C6D
    adds r4, r4, r7
    mov sl, r4
    movs r0, #0
    ldrsb r0, [r4, r0]
    add r5, sp, #0x3c
    mov sb, r5
    cmp r0, #0
    bne .L08002596
    b .L080027C4
.L08002596:
    ldr r6, .L08002910 @ =0x00006C20
    adds r4, r7, r6
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r5, .L08002914 @ =0x00006C24
    adds r0, r7, r5
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    mov r1, r8
    strh r1, [r0, #8]
    ldr r2, .L08002918 @ =0x00006D08
    adds r0, r7, r2
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r3, .L0800291C @ =0x00006D10
    adds r0, r7, r3
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    movs r0, #1
    strb r0, [r1, #0x18]
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08002618
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002618:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    ldr r5, .L08002920 @ =0x00006BF4
    adds r4, r7, r5
    ldr r6, .L08002924 @ =0x00006BE0
    adds r5, r7, r6
    adds r0, r5, #0
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r1, [r5]
    ldr r3, [r1]
    ldrh r2, [r5, #0xc]
    ldr r4, .L08002928 @ =0x00006BE4
    adds r0, r7, r4
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r4, r6}
    stm r1!, {r2, r4, r6}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    movs r6, #0x1a
    ldrsh r1, [r5, r6]
    mov r0, sp
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r5, r0]
    mov r0, sp
    strh r1, [r0, #2]
    ldr r1, .L0800292C @ =0x00006CF0
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    movs r2, #0xda
    lsls r2, r2, #7
    adds r6, r7, r2
    ldr r1, [r6, #4]
    adds r0, r6, #0
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    adds r0, r7, #0
    bl func_08008920
    ldr r1, [sp, #0x1c]
    movs r2, #0
    cmp r1, #0
    beq .L080026A6
    mov r3, sp
    ldrh r2, [r3, #0x20]
.L080026A6:
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r4, sl
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r0, #2
    bne .L0800273E
    ldr r5, .L08002930 @ =0x00006C14
    adds r4, r7, r5
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r5, r7, r0
    adds r0, r5, #0
    bl UpdateIndexedResourceHandle
    str r0, [r4]
    ldr r1, [r5]
    ldr r3, [r1]
    ldrh r2, [r5, #0xc]
    ldr r4, .L08002934 @ =0x00006C04
    adds r0, r7, r4
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    movs r4, #0x1a
    ldrsh r1, [r5, r4]
    mov r0, sp
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r5, r0]
    mov r0, sp
    strh r1, [r0, #2]
    ldr r1, .L08002938 @ =0x00006CF8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r1, [r6, #4]
    adds r0, r6, #0
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    adds r0, r7, #0
    bl func_08008920
    ldr r1, [sp, #0x1c]
    movs r2, #0
    cmp r1, #0
    beq .L08002738
    mov r3, sp
    ldrh r2, [r3, #0x20]
.L08002738:
    mov r3, sp
    bl DrawIndexedResourceSprites
.L0800273E:
    ldr r5, .L0800293C @ =0x00006C40
    adds r4, r7, r5
    adds r0, r4, #0
    bl UpdateIndexedResourceHandle
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r6, .L08002940 @ =0x00006C44
    adds r0, r7, r6
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r5, r6}
    stm r1!, {r5, r6}
    movs r0, #0x1a
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0]
    movs r2, #0x1e
    ldrsh r1, [r4, r2]
    strh r1, [r0, #2]
    ldr r3, .L08002944 @ =0x00006D18
    adds r0, r7, r3
    ldr r1, [r0, #4]
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r4, .L08002948 @ =0x00006D20
    adds r0, r7, r4
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L080027BC
    mov r5, sp
    ldrh r2, [r5, #0x20]
.L080027BC:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
.L080027C4:
    ldr r6, .L0800294C @ =0x00006BA0
    adds r4, r7, r6
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r5, .L08002950 @ =0x00006BA4
    adds r0, r7, r5
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    movs r6, #0
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r6, [r0, #8]
    strh r6, [r0, #6]
    strh r6, [r0, #4]
    mov r1, sp
    movs r0, #1
    strb r0, [r1, #0x18]
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08002830
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002830:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    ldr r5, .L08002954 @ =0x00006D32
    adds r0, r7, r5
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #9
    bgt .L08002846
    b .L08002976
.L08002846:
    adds r0, r7, #0
    bl func_08008920
    ldr r2, .L08002958 @ =0x00006C64
    adds r5, r7, r2
    adds r0, #4
    ldrh r1, [r5]
    strh r1, [r0, #6]
    ldrh r1, [r5, #2]
    strh r1, [r0, #0xe]
    ldrh r1, [r5, #4]
    strh r1, [r0, #0x16]
    ldrh r1, [r5, #6]
    strh r1, [r0, #0x1e]
    ldr r3, .L0800295C @ =0x00006BC0
    adds r3, r3, r7
    mov r8, r3
    ldr r1, [r3]
    ldr r4, [r1]
    ldrh r2, [r3, #0xc]
    ldr r3, .L08002960 @ =0x00006BC4
    adds r0, r7, r3
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r4, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r4}
    stm r1!, {r2, r4}
    mov r3, r8
    movs r4, #0x1a
    ldrsh r1, [r3, r4]
    mov r0, sp
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r3, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r6, [r0, #8]
    mov r1, sp
    ldr r2, .L08002964 @ =0x00006C60
    adds r0, r7, r2
    ldrh r0, [r0]
    strh r0, [r1, #6]
    mov r0, sp
    strh r6, [r0, #4]
    movs r0, #0
    strb r0, [r1, #0x11]
    movs r3, #0
    ldrsh r1, [r5, r3]
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne .L0800296C
    ldr r4, .L08002968 @ =0x00006C6A
    adds r0, r7, r4
    movs r5, #0
    ldrsh r0, [r0, r5]
    cmp r0, r1
    bne .L0800296C
    str r6, [sp, #0x14]
    b .L08002970
    .align 2, 0
.L080028E0: .4byte 0x00006AB4
.L080028E4: .4byte 0x00006AA0
.L080028E8: .4byte 0x00006AD4
.L080028EC: .4byte 0x00006AC0
.L080028F0: .4byte 0x00006AF4
.L080028F4: .4byte 0x00006AE0
.L080028F8: .4byte 0x00006B14
.L080028FC: .4byte 0x00006B34
.L08002900: .4byte 0x00006B20
.L08002904: .4byte 0x00006B54
.L08002908: .4byte 0x00006B40
.L0800290C: .4byte 0x00006C6D
.L08002910: .4byte 0x00006C20
.L08002914: .4byte 0x00006C24
.L08002918: .4byte 0x00006D08
.L0800291C: .4byte 0x00006D10
.L08002920: .4byte 0x00006BF4
.L08002924: .4byte 0x00006BE0
.L08002928: .4byte 0x00006BE4
.L0800292C: .4byte 0x00006CF0
.L08002930: .4byte 0x00006C14
.L08002934: .4byte 0x00006C04
.L08002938: .4byte 0x00006CF8
.L0800293C: .4byte 0x00006C40
.L08002940: .4byte 0x00006C44
.L08002944: .4byte 0x00006D18
.L08002948: .4byte 0x00006D20
.L0800294C: .4byte 0x00006BA0
.L08002950: .4byte 0x00006BA4
.L08002954: .4byte 0x00006D32
.L08002958: .4byte 0x00006C64
.L0800295C: .4byte 0x00006BC0
.L08002960: .4byte 0x00006BC4
.L08002964: .4byte 0x00006C60
.L08002968: .4byte 0x00006C6A
.L0800296C:
    movs r0, #1
    str r0, [sp, #0x14]
.L08002970:
    @ JP submits resource 9 after setting its affine parameters. The overseas
    @ originals prepare those parameters but proceed without this submission.
    .ifdef REGION_JP
    mov r0, sp
    movs r1, #1
    strb r1, [r0, #0x18]
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .Lintro_frame_affine_sprite_count
    mov r6, sp
    ldrh r2, [r6, #0x20]
.Lintro_frame_affine_sprite_count:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    .else
    mov r1, sp
    movs r0, #1
    strb r0, [r1, #0x18]
    .endif
.L08002976:
    .ifdef REGION_JP
    ldr r0, .L08002A68 @ =0x00006AA0
    adds r4, r7, r0
    .else
    ldr r6, .L08002A68 @ =0x00006AA0
    adds r4, r7, r6
    .endif
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r5, .L08002A6C @ =0x00006AA4
    adds r0, r7, r5
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    movs r5, #0
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r5, [r0, #8]
    ldr r1, .L08002A70 @ =0x00006C78
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    movs r2, #0xd9
    lsls r2, r2, #7
    adds r0, r7, r2
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    str r5, [sp, #0x14]
    mov r0, sp
    movs r3, #1
    mov sl, r3
    mov r5, sl
    strb r5, [r0, #0x18]
    ldr r6, .L08002A74 @ =0x00006AB4
    adds r0, r7, r6
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    ldr r1, .L08002A78 @ =0x00006AC4
    adds r1, r7, r1
    str r1, [sp, #0x8c]
    ldr r2, .L08002A7C @ =0x00006AE4
    adds r2, r7, r2
    str r2, [sp, #0x90]
    ldr r3, .L08002A80 @ =0x00006B04
    adds r3, r7, r3
    str r3, [sp, #0x94]
    ldr r5, .L08002A84 @ =0x00006B24
    adds r5, r7, r5
    str r5, [sp, #0x98]
    cmp r0, #0
    blt .L08002A14
    b .L08002B84
.L08002A14:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r6, [sp, #0x24]
    mov r8, r6
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L08002A36
    mov r0, sp
    ldrh r3, [r0, #0x28]
.L08002A36:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r1, .L08002A88 @ =0x06010000
    adds r2, r2, r1
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L08002A8C
    cmp r1, #0
    beq .L08002A5E
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08002A5E:
    ldr r5, [sp, #0x9c]
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L08002B84
    .align 2, 0
.L08002A68: .4byte 0x00006AA0
.L08002A6C: .4byte 0x00006AA4
.L08002A70: .4byte 0x00006C78
.L08002A74: .4byte 0x00006AB4
.L08002A78: .4byte 0x00006AC4
.L08002A7C: .4byte 0x00006AE4
.L08002A80: .4byte 0x00006B04
.L08002A84: .4byte 0x00006B24
.L08002A88: .4byte 0x06010000
.L08002A8C:
    mov r8, r1
    mov r6, sl
    str r6, [sp, #0x60]
    ldr r1, [sp, #0x9c]
    ldr r0, [r1]
    mov r2, r8
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x5c]
    add r1, sp, #0x60
    add r0, sp, #0x5c
    cmp r4, #1
    bhs .L08002AA8
    adds r0, r1, #0
.L08002AA8:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08002AC6
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L08002ACA
    mov r0, sl
    bl RetryMemoryAllocation
    b .L08002ACA
.L08002AC6:
    movs r0, #0
    mov sl, r0
.L08002ACA:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r3, [sp, #0x9c]
    ldr r2, [r3]
    adds r3, r5, #0
    ldr r4, .L08002B24 @ =0x00006AC4
    adds r4, r7, r4
    str r4, [sp, #0x8c]
    ldr r5, .L08002B28 @ =0x00006AE4
    adds r5, r7, r5
    str r5, [sp, #0x90]
    ldr r6, .L08002B2C @ =0x00006B04
    adds r6, r7, r6
    str r6, [sp, #0x94]
    ldr r0, .L08002B30 @ =0x00006B24
    adds r0, r7, r0
    str r0, [sp, #0x98]
    cmp r2, r8
    beq .L08002B08
.L08002AF0:
    cmp r3, #0
    beq .L08002B00
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002B00:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L08002AF0
.L08002B08:
    adds r5, r3, #0
    ldr r0, [sp, #0x60]
    cmp r0, #1
    bne .L08002B34
    cmp r5, #0
    beq .L08002B20
    adds r0, r5, #0
    add r1, sp, #0x3c
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08002B20:
    adds r5, #0x10
    b .L08002B5C
    .align 2, 0
.L08002B24: .4byte 0x00006AC4
.L08002B28: .4byte 0x00006AE4
.L08002B2C: .4byte 0x00006B04
.L08002B30: .4byte 0x00006B24
.L08002B34:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .L08002B5A
.L08002B3C:
    cmp r2, #0
    beq .L08002B4C
    adds r0, r2, #0
    add r1, sp, #0x3c
    ldm r1!, {r3, r5, r6}
    stm r0!, {r3, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002B4C:
    movs r4, #1
    rsbs r4, r4, #0
    add r8, r4
    adds r2, #0x10
    mov r5, r8
    cmp r5, #0
    bne .L08002B3C
.L08002B5A:
    adds r5, r2, #0
.L08002B5C:
    ldr r6, [sp, #0x9c]
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08002B6E
.L08002B68:
    adds r1, #0x10
    cmp r1, r2
    bne .L08002B68
.L08002B6E:
    cmp r0, #0
    beq .L08002B76
    bl free
.L08002B76:
    ldr r0, [sp, #0xa0]
    add r0, sl
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x9c]
    str r1, [r2]
    str r5, [r2, #4]
    str r0, [r2, #0xc]
.L08002B84:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08002B9A
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002B9A:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    movs r6, #2
    ldrsh r2, [r0, r6]
    adds r0, r7, #0
    movs r3, #1
    bl SubmitIntroSceneSprite
    ldr r0, .L08002C88 @ =0x00006AC0
    adds r4, r7, r0
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r5, [sp, #0x8c]
    ldr r0, [r5]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    movs r2, #0
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r2, [r0, #8]
    ldr r1, .L08002C8C @ =0x00006CB0
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r2, .L08002C90 @ =0x00006CB8
    adds r0, r7, r2
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    mov r0, sp
    movs r3, #1
    mov sl, r3
    mov r5, sl
    strb r5, [r0, #0x18]
    ldr r6, .L08002C94 @ =0x00006AD4
    adds r0, r7, r6
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    cmp r0, #0
    blt .L08002C34
    b .L08002D6A
.L08002C34:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r0, [sp, #0x24]
    mov r8, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L08002C56
    mov r1, sp
    ldrh r3, [r1, #0x28]
.L08002C56:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r4, .L08002C98 @ =0x06010000
    adds r2, r2, r4
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L08002C9C
    cmp r1, #0
    beq .L08002C7E
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r2, r5, r6}
    stm r0!, {r2, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002C7E:
    ldr r3, [sp, #0x9c]
    ldr r0, [r3, #4]
    adds r0, #0x10
    str r0, [r3, #4]
    b .L08002D6A
    .align 2, 0
.L08002C88: .4byte 0x00006AC0
.L08002C8C: .4byte 0x00006CB0
.L08002C90: .4byte 0x00006CB8
.L08002C94: .4byte 0x00006AD4
.L08002C98: .4byte 0x06010000
.L08002C9C:
    mov r8, r1
    mov r4, sl
    str r4, [sp, #0x68]
    ldr r5, [sp, #0x9c]
    ldr r0, [r5]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x64]
    add r1, sp, #0x68
    add r0, sp, #0x64
    cmp r4, #1
    bhs .L08002CB6
    adds r0, r1, #0
.L08002CB6:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08002CD4
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L08002CD8
    mov r0, sl
    bl RetryMemoryAllocation
    b .L08002CD8
.L08002CD4:
    movs r0, #0
    mov sl, r0
.L08002CD8:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r6, [sp, #0x9c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, r8
    beq .L08002CFE
.L08002CE6:
    cmp r3, #0
    beq .L08002CF6
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002CF6:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L08002CE6
.L08002CFE:
    adds r5, r3, #0
    ldr r0, [sp, #0x68]
    cmp r0, #1
    bne .L08002D1A
    cmp r5, #0
    beq .L08002D16
    adds r0, r5, #0
    add r1, sp, #0x3c
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08002D16:
    adds r5, #0x10
    b .L08002D42
.L08002D1A:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .L08002D40
.L08002D22:
    cmp r2, #0
    beq .L08002D32
    adds r0, r2, #0
    add r1, sp, #0x3c
    ldm r1!, {r3, r5, r6}
    stm r0!, {r3, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002D32:
    movs r4, #1
    rsbs r4, r4, #0
    add r8, r4
    adds r2, #0x10
    mov r5, r8
    cmp r5, #0
    bne .L08002D22
.L08002D40:
    adds r5, r2, #0
.L08002D42:
    ldr r6, [sp, #0x9c]
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08002D54
.L08002D4E:
    adds r1, #0x10
    cmp r1, r2
    bne .L08002D4E
.L08002D54:
    cmp r0, #0
    beq .L08002D5C
    bl free
.L08002D5C:
    ldr r0, [sp, #0xa0]
    add r0, sl
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x9c]
    str r1, [r2]
    str r5, [r2, #4]
    str r0, [r2, #0xc]
.L08002D6A:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08002D80
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002D80:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    movs r6, #2
    ldrsh r2, [r0, r6]
    adds r0, r7, #0
    movs r3, #0
    bl SubmitIntroSceneSprite
    ldr r1, .L08002E80 @ =0x00006C6C
    adds r0, r7, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne .L08002DAA
    b .L08002FE2
.L08002DAA:
    ldr r2, .L08002E84 @ =0x00006B40
    adds r4, r7, r2
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    ldr r5, .L08002E88 @ =0x00006B44
    adds r0, r7, r5
    lsls r2, r2, #2
    ldr r0, [r0]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    movs r2, #0
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r2, [r0, #8]
    ldr r1, .L08002E8C @ =0x00006CC0
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r2, .L08002E90 @ =0x00006CC8
    adds r0, r7, r2
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    mov r0, sp
    movs r3, #1
    mov sl, r3
    mov r5, sl
    strb r5, [r0, #0x18]
    ldr r6, .L08002E94 @ =0x00006B54
    adds r0, r7, r6
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    cmp r0, #0
    blt .L08002E2C
    b .L08002F6A
.L08002E2C:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r0, [sp, #0x24]
    mov r8, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L08002E4E
    mov r1, sp
    ldrh r3, [r1, #0x28]
.L08002E4E:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r4, .L08002E98 @ =0x06010000
    adds r2, r2, r4
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L08002E9C
    cmp r1, #0
    beq .L08002E76
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r2, r5, r6}
    stm r0!, {r2, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002E76:
    ldr r3, [sp, #0x9c]
    ldr r0, [r3, #4]
    adds r0, #0x10
    str r0, [r3, #4]
    b .L08002F6A
    .align 2, 0
.L08002E80: .4byte 0x00006C6C
.L08002E84: .4byte 0x00006B40
.L08002E88: .4byte 0x00006B44
.L08002E8C: .4byte 0x00006CC0
.L08002E90: .4byte 0x00006CC8
.L08002E94: .4byte 0x00006B54
.L08002E98: .4byte 0x06010000
.L08002E9C:
    mov r8, r1
    mov r4, sl
    str r4, [sp, #0x70]
    ldr r5, [sp, #0x9c]
    ldr r0, [r5]
    subs r0, r1, r0
    asrs r4, r0, #4
    str r4, [sp, #0x6c]
    add r1, sp, #0x70
    add r0, sp, #0x6c
    cmp r4, #1
    bhs .L08002EB6
    adds r0, r1, #0
.L08002EB6:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08002ED4
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L08002ED8
    mov r0, sl
    bl RetryMemoryAllocation
    b .L08002ED8
.L08002ED4:
    movs r0, #0
    mov sl, r0
.L08002ED8:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r6, [sp, #0x9c]
    ldr r2, [r6]
    adds r3, r5, #0
    cmp r2, r8
    beq .L08002EFE
.L08002EE6:
    cmp r3, #0
    beq .L08002EF6
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002EF6:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L08002EE6
.L08002EFE:
    adds r5, r3, #0
    ldr r0, [sp, #0x70]
    cmp r0, #1
    bne .L08002F1A
    cmp r5, #0
    beq .L08002F16
    adds r0, r5, #0
    add r1, sp, #0x3c
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08002F16:
    adds r5, #0x10
    b .L08002F42
.L08002F1A:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .L08002F40
.L08002F22:
    cmp r2, #0
    beq .L08002F32
    adds r0, r2, #0
    add r1, sp, #0x3c
    ldm r1!, {r3, r5, r6}
    stm r0!, {r3, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08002F32:
    movs r4, #1
    rsbs r4, r4, #0
    add r8, r4
    adds r2, #0x10
    mov r5, r8
    cmp r5, #0
    bne .L08002F22
.L08002F40:
    adds r5, r2, #0
.L08002F42:
    ldr r6, [sp, #0x9c]
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08002F54
.L08002F4E:
    adds r1, #0x10
    cmp r1, r2
    bne .L08002F4E
.L08002F54:
    cmp r0, #0
    beq .L08002F5C
    bl free
.L08002F5C:
    ldr r0, [sp, #0xa0]
    add r0, sl
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x9c]
    str r1, [r2]
    str r5, [r2, #4]
    str r0, [r2, #0xc]
.L08002F6A:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08002F80
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002F80:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    ldrh r0, [r0, #2]
    cmp r0, #0x94
    bne .L08002FA0
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    adds r0, r7, #0
    movs r2, #0x94
    movs r3, #0
    bl SubmitIntroSceneSprite
.L08002FA0:
    ldr r6, .L080030C0 @ =0x00006B60
    adds r2, r7, r6
    movs r0, #0x1a
    ldrsh r1, [r2, r0]
    mov r0, sp
    strh r1, [r0]
    movs r3, #0x1e
    ldrsh r1, [r2, r3]
    strh r1, [r0, #2]
    adds r0, r7, #0
    bl func_08008920
    ldr r1, [sp, #0x1c]
    movs r2, #0
    cmp r1, #0
    beq .L08002FC4
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L08002FC4:
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    ldrh r0, [r0, #2]
    cmp r0, #0x94
    bne .L08002FE2
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    adds r0, r7, #0
    movs r2, #0x94
    movs r3, #0
    bl SubmitIntroSceneSprite
.L08002FE2:
    ldr r6, .L080030C4 @ =0x00006AE0
    adds r4, r7, r6
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r5, [sp, #0x90]
    ldr r0, [r5]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r2, sp
    ldr r3, .L080030C8 @ =0x00006D30
    adds r0, r7, r3
    ldrh r0, [r0]
    subs r1, r1, r0
    movs r3, #0
    strh r1, [r2]
    movs r5, #0x1e
    ldrsh r1, [r4, r5]
    mov r0, sp
    strh r1, [r0, #2]
    strh r3, [r0, #8]
    ldr r6, .L080030CC @ =0x00006C88
    adds r4, r7, r6
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r1, .L080030D0 @ =0x00006C90
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    mov r0, sp
    movs r2, #1
    mov sl, r2
    mov r3, sl
    strb r3, [r0, #0x18]
    ldr r5, .L080030D4 @ =0x00006AF4
    adds r0, r7, r5
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    cmp r0, #0
    blt .L0800306A
    b .L080031AC
.L0800306A:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r6, [sp, #0x24]
    mov r8, r6
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L0800308C
    mov r0, sp
    ldrh r3, [r0, #0x28]
.L0800308C:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r1, .L080030D8 @ =0x06010000
    adds r2, r2, r1
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080030DC
    cmp r1, #0
    beq .L080030B4
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L080030B4:
    ldr r5, [sp, #0x9c]
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L080031AC
    .align 2, 0
.L080030C0: .4byte 0x00006B60
.L080030C4: .4byte 0x00006AE0
.L080030C8: .4byte 0x00006D30
.L080030CC: .4byte 0x00006C88
.L080030D0: .4byte 0x00006C90
.L080030D4: .4byte 0x00006AF4
.L080030D8: .4byte 0x06010000
.L080030DC:
    mov r8, r1
    mov r6, sl
    str r6, [sp, #0x78]
    ldr r1, [sp, #0x9c]
    ldr r0, [r1]
    mov r2, r8
    subs r0, r2, r0
    asrs r4, r0, #4
    str r4, [sp, #0x74]
    add r1, sp, #0x78
    add r0, sp, #0x74
    cmp r4, #1
    bhs .L080030F8
    adds r0, r1, #0
.L080030F8:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08003116
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L0800311A
    mov r0, sl
    bl RetryMemoryAllocation
    b .L0800311A
.L08003116:
    movs r0, #0
    mov sl, r0
.L0800311A:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r3, [sp, #0x9c]
    ldr r2, [r3]
    adds r3, r5, #0
    cmp r2, r8
    beq .L08003140
.L08003128:
    cmp r3, #0
    beq .L08003138
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08003138:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L08003128
.L08003140:
    adds r5, r3, #0
    ldr r0, [sp, #0x78]
    cmp r0, #1
    bne .L0800315C
    cmp r5, #0
    beq .L08003158
    adds r0, r5, #0
    add r1, sp, #0x3c
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08003158:
    adds r5, #0x10
    b .L08003184
.L0800315C:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .L08003182
.L08003164:
    cmp r2, #0
    beq .L08003174
    adds r0, r2, #0
    add r1, sp, #0x3c
    ldm r1!, {r3, r5, r6}
    stm r0!, {r3, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08003174:
    movs r4, #1
    rsbs r4, r4, #0
    add r8, r4
    adds r2, #0x10
    mov r5, r8
    cmp r5, #0
    bne .L08003164
.L08003182:
    adds r5, r2, #0
.L08003184:
    ldr r6, [sp, #0x9c]
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08003196
.L08003190:
    adds r1, #0x10
    cmp r1, r2
    bne .L08003190
.L08003196:
    cmp r0, #0
    beq .L0800319E
    bl free
.L0800319E:
    ldr r0, [sp, #0xa0]
    add r0, sl
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x9c]
    str r1, [r2]
    str r5, [r2, #4]
    str r0, [r2, #0xc]
.L080031AC:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L080031C2
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L080031C2:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    movs r6, #2
    ldrsh r2, [r0, r6]
    adds r0, r7, #0
    movs r3, #2
    bl SubmitIntroSceneSprite
    movs r0, #0xd6
    lsls r0, r0, #7
    adds r4, r7, r0
    ldr r1, [r4]
    ldr r3, [r1]
    ldrh r2, [r4, #0xc]
    lsls r2, r2, #2
    ldr r5, [sp, #0x94]
    ldr r0, [r5]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sb
    mov r1, sb
    movs r2, #0x20
    bl memcpy
    add r1, sp, #0x1c
    mov r0, sb
    ldm r0!, {r2, r3, r6}
    stm r1!, {r2, r3, r6}
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    movs r6, #0x1a
    ldrsh r1, [r4, r6]
    mov r0, sp
    movs r2, #0
    strh r1, [r0]
    movs r0, #0x1e
    ldrsh r1, [r4, r0]
    mov r0, sp
    strh r1, [r0, #2]
    strh r2, [r0, #8]
    ldr r1, .L080032B4 @ =0x00006C98
    adds r4, r7, r1
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r2, .L080032B8 @ =0x00006CA0
    adds r0, r7, r2
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    mov r0, sp
    movs r3, #1
    mov sl, r3
    mov r5, sl
    strb r5, [r0, #0x18]
    ldr r6, .L080032BC @ =0x00006B14
    adds r0, r7, r6
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    cmp r0, #0
    blt .L0800325E
    b .L08003396
.L0800325E:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r0, [sp, #0x24]
    mov r8, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L08003280
    mov r1, sp
    ldrh r3, [r1, #0x28]
.L08003280:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r4, .L080032C0 @ =0x06010000
    adds r2, r2, r4
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080032C4
    cmp r1, #0
    beq .L080032A8
    adds r0, r1, #0
    mov r1, sb
    ldm r1!, {r2, r5, r6}
    stm r0!, {r2, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L080032A8:
    ldr r3, [sp, #0x9c]
    ldr r0, [r3, #4]
    adds r0, #0x10
    str r0, [r3, #4]
    b .L08003396
    .align 2, 0
.L080032B4: .4byte 0x00006C98
.L080032B8: .4byte 0x00006CA0
.L080032BC: .4byte 0x00006B14
.L080032C0: .4byte 0x06010000
.L080032C4:
    mov r8, r1
    add r0, sp, #0x80
    mov r4, sl
    str r4, [r0]
    ldr r5, [sp, #0x9c]
    ldr r1, [r5]
    mov r6, r8
    subs r1, r6, r1
    asrs r4, r1, #4
    str r4, [sp, #0x7c]
    ldr r1, [r0]
    add r2, sp, #0x7c
    cmp r4, r1
    bhs .L080032E2
    adds r2, r0, #0
.L080032E2:
    ldr r0, [r2]
    adds r0, r4, r0
    cmp r0, #0
    beq .L08003300
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sl, r4
    cmp r0, #0
    bne .L08003304
    mov r0, sl
    bl RetryMemoryAllocation
    b .L08003304
.L08003300:
    movs r0, #0
    mov sl, r0
.L08003304:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r0, [sp, #0x9c]
    ldr r2, [r0]
    adds r3, r5, #0
    cmp r2, r8
    beq .L0800332A
.L08003312:
    cmp r3, #0
    beq .L08003322
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08003322:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L08003312
.L0800332A:
    adds r5, r3, #0
    ldr r0, [sp, #0x80]
    cmp r0, #1
    bne .L08003346
    cmp r5, #0
    beq .L08003342
    adds r0, r5, #0
    add r1, sp, #0x3c
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L08003342:
    adds r5, #0x10
    b .L0800336E
.L08003346:
    mov r8, r0
    adds r2, r5, #0
    cmp r0, #0
    beq .L0800336C
.L0800334E:
    cmp r2, #0
    beq .L0800335E
    adds r0, r2, #0
    add r1, sp, #0x3c
    ldm r1!, {r3, r5, r6}
    stm r0!, {r3, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L0800335E:
    movs r4, #1
    rsbs r4, r4, #0
    add r8, r4
    adds r2, #0x10
    mov r5, r8
    cmp r5, #0
    bne .L0800334E
.L0800336C:
    adds r5, r2, #0
.L0800336E:
    ldr r6, [sp, #0x9c]
    ldr r2, [r6, #4]
    ldr r0, [r6]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08003380
.L0800337A:
    adds r1, #0x10
    cmp r1, r2
    bne .L0800337A
.L08003380:
    cmp r0, #0
    beq .L08003388
    bl free
.L08003388:
    ldr r0, [sp, #0xa0]
    add r0, sl
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x9c]
    str r1, [r2]
    str r5, [r2, #4]
    str r0, [r2, #0xc]
.L08003396:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L080033AC
    mov r4, sp
    ldrh r2, [r4, #0x20]
.L080033AC:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    movs r5, #0
    ldrsh r1, [r0, r5]
    movs r6, #2
    ldrsh r2, [r0, r6]
    adds r0, r7, #0
    movs r3, #2
    bl SubmitIntroSceneSprite
    ldr r0, .L08003498 @ =0x00006B20
    adds r5, r7, r0
    ldr r1, [r5]
    ldr r3, [r1]
    ldrh r2, [r5, #0xc]
    lsls r2, r2, #2
    ldr r4, [sp, #0x98]
    ldr r0, [r4]
    adds r0, r0, r2
    ldrh r2, [r0]
    add r0, sp, #0x3c
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r4, sb
    adds r0, r4, #0
    adds r1, r4, #0
    movs r2, #0x20
    bl memcpy
    add r0, sp, #0x1c
    ldm r4!, {r1, r2, r6}
    stm r0!, {r1, r2, r6}
    ldm r4!, {r1, r3, r6}
    stm r0!, {r1, r3, r6}
    ldm r4!, {r2, r3}
    stm r0!, {r2, r3}
    movs r4, #0x1a
    ldrsh r1, [r5, r4]
    mov r0, sp
    movs r2, #0
    strh r1, [r0]
    movs r6, #0x1e
    ldrsh r1, [r5, r6]
    strh r1, [r0, #2]
    strh r2, [r0, #8]
    ldr r0, .L0800349C @ =0x00006CA8
    adds r4, r7, r0
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    mov r1, sp
    strh r0, [r1, #6]
    ldr r1, .L080034A0 @ =0x00006CC8
    adds r0, r7, r1
    ldr r1, [r0, #4]
    bl func_080074C0
    mov r1, sp
    strh r0, [r1, #4]
    mov r0, sp
    movs r2, #1
    strb r2, [r0, #0x18]
    ldr r3, .L080034A4 @ =0x00006B34
    adds r0, r7, r3
    ldrb r0, [r0]
    lsls r0, r0, #0x1e
    cmp r0, #0
    blt .L08003440
    b .L0800357E
.L08003440:
    adds r0, r7, #0
    bl func_08008910
    adds r5, r0, #0
    ldr r6, [sp, #0x24]
    mov r8, r6
    ldr r1, [r4, #4]
    adds r0, r4, #0
    bl GetHardwareSharedStateTileIndex
    adds r2, r0, #0
    ldr r0, [sp, #0x24]
    movs r3, #0
    cmp r0, #0
    beq .L08003462
    mov r0, sp
    ldrh r3, [r0, #0x28]
.L08003462:
    str r5, [sp, #0x9c]
    lsls r2, r2, #5
    ldr r1, .L080034A8 @ =0x06010000
    adds r2, r2, r1
    mov r0, sb
    mov r1, r8
    bl __21DmaTransferDescriptorPCvPvUi
    mov sl, sb
    ldr r1, [r5, #4]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    beq .L080034AC
    cmp r1, #0
    beq .L0800348C
    adds r0, r1, #0
    mov r1, sl
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    ldr r1, [r1]
    str r1, [r0]
.L0800348C:
    ldr r5, [sp, #0x9c]
    ldr r0, [r5, #4]
    adds r0, #0x10
    str r0, [r5, #4]
    b .L0800357E
    .align 2, 0
.L08003498: .4byte 0x00006B20
.L0800349C: .4byte 0x00006CA8
.L080034A0: .4byte 0x00006CC8
.L080034A4: .4byte 0x00006B34
.L080034A8: .4byte 0x06010000
.L080034AC:
    mov r8, r1
    add r1, sp, #0x88
    movs r6, #1
    str r6, [r1]
    ldr r2, [sp, #0x9c]
    ldr r0, [r2]
    mov r3, r8
    subs r0, r3, r0
    asrs r4, r0, #4
    add r0, sp, #0x84
    str r4, [r0]
    ldr r2, [r1]
    cmp r4, r2
    bhs .L080034CA
    adds r0, r1, #0
.L080034CA:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080034E8
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    mov sb, r4
    cmp r0, #0
    bne .L080034EC
    mov r0, sb
    bl RetryMemoryAllocation
    b .L080034EC
.L080034E8:
    movs r0, #0
    mov sb, r0
.L080034EC:
    adds r5, r0, #0
    str r5, [sp, #0xa0]
    ldr r4, [sp, #0x9c]
    ldr r2, [r4]
    adds r3, r5, #0
    cmp r2, r8
    beq .L08003512
.L080034FA:
    cmp r3, #0
    beq .L0800350A
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L0800350A:
    adds r2, #0x10
    adds r3, #0x10
    cmp r2, r8
    bne .L080034FA
.L08003512:
    adds r5, r3, #0
    ldr r1, [sp, #0x88]
    cmp r1, #1
    bne .L0800352E
    cmp r5, #0
    beq .L0800352A
    adds r0, r5, #0
    mov r1, sl
    ldm r1!, {r2, r3, r6}
    stm r0!, {r2, r3, r6}
    ldr r1, [r1]
    str r1, [r0]
.L0800352A:
    adds r5, #0x10
    b .L08003556
.L0800352E:
    mov r8, r1
    adds r2, r5, #0
    cmp r1, #0
    beq .L08003554
.L08003536:
    cmp r2, #0
    beq .L08003546
    adds r0, r2, #0
    mov r1, sl
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08003546:
    movs r0, #1
    rsbs r0, r0, #0
    add r8, r0
    adds r2, #0x10
    mov r1, r8
    cmp r1, #0
    bne .L08003536
.L08003554:
    adds r5, r2, #0
.L08003556:
    ldr r3, [sp, #0x9c]
    ldr r2, [r3, #4]
    ldr r0, [r3]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08003568
.L08003562:
    adds r1, #0x10
    cmp r1, r2
    bne .L08003562
.L08003568:
    cmp r0, #0
    beq .L08003570
    bl free
.L08003570:
    ldr r0, [sp, #0xa0]
    add r0, sb
    ldr r4, [sp, #0xa0]
    ldr r6, [sp, #0x9c]
    str r4, [r6]
    str r5, [r6, #4]
    str r0, [r6, #0xc]
.L0800357E:
    adds r0, r7, #0
    bl func_08008920
    adds r3, r0, #0
    ldr r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r2, #0
    cmp r1, #0
    beq .L08003594
    mov r0, sp
    ldrh r2, [r0, #0x20]
.L08003594:
    adds r0, r3, #0
    mov r3, sp
    bl DrawIndexedResourceSprites
    mov r0, sp
    movs r2, #0
    ldrsh r1, [r0, r2]
    movs r3, #2
    ldrsh r2, [r0, r3]
    adds r0, r7, #0
    movs r3, #2
    bl SubmitIntroSceneSprite
    add sp, #0xa4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_end RenderIntroSceneFrame

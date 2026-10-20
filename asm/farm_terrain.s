    .syntax unified
    .cpu arm7tdmi
    .thumb
    .section .text, "ax", %progbits
    .align 2, 0

    @ Farm terrain setup: indexed attributes, plot blocking and building patches.
    @ Shared instructions use actual regional symbols; no ROM byte fallback.
    .global ApplyMapTerrainPatch
    .type ApplyMapTerrainPatch, %function
    .thumb_func
ApplyMapTerrainPatch:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r5, r0, #0
    adds r6, r1, #0
    adds r4, r2, #0
    cmp r5, #0
    beq .L080171EC
    cmp r6, #0
    beq .L080171EC
    ldr r2, [r4, #0x14]
    cmp r2, #0
    beq .L080171EC
    ldr r0, [r4, #0x10]
    mov r8, r0
    cmp r0, #0
    beq .L080171EC
    ldrb r7, [r4]
    adds r0, r3, r7
    cmp r0, r6
    bhi .L080171EC
    lsls r1, r3, #2
    adds r1, r5, r1
    ldr r0, [sp, #0x1c]
    muls r0, r6, r0
    lsls r0, r0, #2
    adds r5, r1, r0
    ldrb r4, [r4, #1]
    mov ip, r4
    movs r0, #0
    cmp r0, ip
    bhs .L080171EC
    lsls r6, r6, #2
    mov sb, r6
.L080171C6:
    movs r1, #0
    adds r6, r0, #1
    cmp r1, r7
    bhs .L080171E4
    mov r3, r8
    adds r4, r5, #0
.L080171D2:
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r0, [r0]
    stm r4!, {r0}
    adds r2, #1
    adds r1, #1
    cmp r1, r7
    blo .L080171D2
.L080171E4:
    add r5, sb
    adds r0, r6, #0
    cmp r0, ip
    blo .L080171C6
.L080171EC:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    .size ApplyMapTerrainPatch, . - ApplyMapTerrainPatch

    .global InitializeFarmTerrain
    .type InitializeFarmTerrain, %function
    .thumb_func
InitializeFarmTerrain:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    str r0, [sp, #4]
    str r1, [sp, #8]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    str r2, [sp, #0xc]
    rsbs r0, r2, #0
    orrs r0, r2
    lsrs r0, r0, #0x1f
    bl GetMapData
    adds r3, r0, #0
    ldrh r0, [r3, #0x20]
    mov sb, r0
    ldrh r0, [r3, #0x22]
    movs r2, #0
    mov r4, sb
    muls r4, r0, r4
    cmp r2, r4
    bhs .L08017242
    ldr r5, [sp, #4]
.L0801722C:
    ldr r0, [r3, #0x1c]
    adds r0, r0, r2
    ldrb r0, [r0]
    ldr r1, [r3, #0x18]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    stm r5!, {r0}
    adds r2, #1
    cmp r2, r4
    blo .L0801722C
.L08017242:
    movs r1, #0
    ldr r0, .L080172D8 @ =0x000009C8
    ldr r2, [sp, #8]
    adds r0, r2, r0
    str r0, [sp, #0x10]
    movs r2, #2
    rsbs r2, r2, #0
    mov r8, r2
.L08017252:
    lsls r0, r1, #1
    adds r0, #0x16
    mov sl, r0
    movs r7, #0
    adds r0, r1, #1
    str r0, [sp, #0x14]
    movs r6, #0x22
    movs r0, #0xac
    muls r0, r1, r0
    ldr r1, [sp, #0x10]
    adds r5, r0, r1
.L08017268:
    mov r2, sb
    mov r4, sl
    muls r4, r2, r4
    adds r4, r6, r4
    adds r0, r5, #0
    bl IsTerrainBlocking__C9FieldPlot
    lsls r3, r4, #2
    ldr r1, [sp, #4]
    adds r3, r3, r1
    add r4, sb
    lsls r4, r4, #2
    adds r4, r4, r1
    movs r2, #1
    ands r2, r0
    ldrb r1, [r4, #4]
    mov r0, r8
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #4]
    ldrb r1, [r4]
    mov r0, r8
    ands r0, r1
    orrs r0, r2
    strb r0, [r4]
    ldrb r1, [r3, #4]
    mov r0, r8
    ands r0, r1
    orrs r0, r2
    strb r0, [r3, #4]
    ldrb r1, [r3]
    mov r0, r8
    ands r0, r1
    orrs r0, r2
    strb r0, [r3]
    adds r6, #2
    adds r5, #4
    adds r7, #1
    cmp r7, #0x2a
    bls .L08017268
    ldr r1, [sp, #0x14]
    cmp r1, #0x18
    bls .L08017252
    ldr r2, [sp, #8]
    movs r1, #0xf0
    lsls r1, r1, #1
    adds r0, r2, r1
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    beq .L08017300
    cmp r0, #1
    blo .L080172DC
    cmp r0, #2
    beq .L08017324
    b .L0801733A
    .align 2, 0
.L080172D8: .4byte 0x000009C8
.L080172DC:
    ldr r2, .L080172F8 @ =gFieldRenderRectDescriptors
    ldr r0, [sp, #0xc]
    cmp r0, #0
    beq .L080172E6
    ldr r2, .L080172FC @ =gFieldRenderRectDescriptors + 0x18
.L080172E6:
    movs r0, #3
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0x1a
    bl ApplyMapTerrainPatch
    b .L0801733A
    .align 2, 0
.L080172F8: .4byte gFieldRenderRectDescriptors
.L080172FC: .4byte gFieldRenderRectDescriptors + 0x18
.L08017300:
    ldr r2, .L0801731C @ =gFieldRenderRectDescriptors + 0x30
    ldr r1, [sp, #0xc]
    cmp r1, #0
    beq .L0801730A
    ldr r2, .L08017320 @ =gFieldRenderRectDescriptors + 0x48
.L0801730A:
    movs r0, #3
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0x12
    bl ApplyMapTerrainPatch
    b .L0801733A
    .align 2, 0
.L0801731C: .4byte gFieldRenderRectDescriptors + 0x30
.L08017320: .4byte gFieldRenderRectDescriptors + 0x48
.L08017324:
    ldr r2, .L08017350 @ =gFieldRenderRectDescriptors + 0x60
    ldr r1, [sp, #0xc]
    cmp r1, #0
    beq .L0801732E
    ldr r2, .L08017354 @ =gFieldRenderRectDescriptors + 0x78
.L0801732E:
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0xa
    bl ApplyMapTerrainPatch
.L0801733A:
    ldr r2, [sp, #8]
    ldr r1, .L08017358 @ =0x000005DC
    adds r0, r2, r1
    bl GetUpgradeLevel__C4Barn
    cmp r0, #0
    beq .L0801735C
    cmp r0, #1
    beq .L08017380
    b .L08017398
    .align 2, 0
.L08017350: .4byte gFieldRenderRectDescriptors + 0x60
.L08017354: .4byte gFieldRenderRectDescriptors + 0x78
.L08017358: .4byte 0x000005DC
.L0801735C:
    ldr r2, .L08017378 @ =gFieldRenderRectDescriptors + 0x90
    ldr r0, [sp, #0xc]
    cmp r0, #0
    beq .L08017366
    ldr r2, .L0801737C @ =gFieldRenderRectDescriptors + 0xA8
.L08017366:
    movs r0, #2
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0x3a
    bl ApplyMapTerrainPatch
    b .L08017398
    .align 2, 0
.L08017378: .4byte gFieldRenderRectDescriptors + 0x90
.L0801737C: .4byte gFieldRenderRectDescriptors + 0xA8
.L08017380:
    ldr r2, .L080173B0 @ =gFieldRenderRectDescriptors + 0xC0
    ldr r1, [sp, #0xc]
    cmp r1, #0
    beq .L0801738A
    ldr r2, .L080173B4 @ =gFieldRenderRectDescriptors + 0xD8
.L0801738A:
    movs r0, #2
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0x3a
    bl ApplyMapTerrainPatch
.L08017398:
    ldr r2, [sp, #8]
    movs r1, #0xff
    lsls r1, r1, #2
    adds r0, r2, r1
    bl GetUpgradeLevel__C4Coop
    cmp r0, #0
    beq .L080173B8
    cmp r0, #1
    beq .L080173DC
    b .L080173F4
    .align 2, 0
.L080173B0: .4byte gFieldRenderRectDescriptors + 0xC0
.L080173B4: .4byte gFieldRenderRectDescriptors + 0xD8
.L080173B8:
    ldr r2, .L080173D4 @ =gFieldRenderRectDescriptors + 0xF0
    ldr r0, [sp, #0xc]
    cmp r0, #0
    beq .L080173C2
    ldr r2, .L080173D8 @ =gFieldRenderRectDescriptors + 0x108
.L080173C2:
    movs r0, #0x34
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0xe
    bl ApplyMapTerrainPatch
    b .L080173F4
    .align 2, 0
.L080173D4: .4byte gFieldRenderRectDescriptors + 0xF0
.L080173D8: .4byte gFieldRenderRectDescriptors + 0x108
.L080173DC:
    ldr r2, .L08017404 @ =gFieldRenderRectDescriptors + 0x120
    ldr r1, [sp, #0xc]
    cmp r1, #0
    beq .L080173E6
    ldr r2, .L08017408 @ =gFieldRenderRectDescriptors + 0x138
.L080173E6:
    movs r0, #0x34
    str r0, [sp]
    ldr r0, [sp, #4]
    mov r1, sb
    movs r3, #0xe
    bl ApplyMapTerrainPatch
.L080173F4:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08017404: .4byte gFieldRenderRectDescriptors + 0x120
.L08017408: .4byte gFieldRenderRectDescriptors + 0x138

    .size InitializeFarmTerrain, . - InitializeFarmTerrain

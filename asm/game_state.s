    .ifdef REGION_JP
    @ JP revision 0 counterpart of asm/game_state.s.
    @
    @ The US module is 0x274 bytes longer.  This file keeps the existing
    @ object path while selecting static JP ROM ranges at matched boundaries.
    @ Exported entry points are additionally checked from JP call targets.
    @ Nothing here is generated during the build.

    .section .text
    .syntax unified
    .thumb


    .section .text.game_state_after_startup_accessors
    .global DayUpdate__18GameStateSaveImage
    .thumb_func
DayUpdate__18GameStateSaveImage:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r6, r0, #0
    ldrb r1, [r6]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r6]
    ldr r0, [r6, #0xc]
    str r0, [r6, #8]
    ldrb r0, [r6, #0x11]
    lsls r1, r0, #0x1e
    movs r3, #3
    lsrs r1, r1, #0x1e
    movs r4, #4
    rsbs r4, r4, #0
    adds r2, r4, #0
    mov r5, sb
    ands r2, r5
    orrs r2, r1
    mov sb, r2
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    adds r5, r0, #1
    cmp r0, #0x1e
    bne .Ljp_08010F82
    lsls r0, r2, #0x1e
    lsrs r0, r0, #0x1e
    adds r0, #1
    ands r0, r3
    ands r2, r4
    orrs r2, r0
    mov sb, r2
    movs r5, #1
.Ljp_08010F82:
    movs r0, #0
    mov r8, r0
    movs r2, #0
    movs r1, #0x14
    adds r1, r1, r6
    mov sl, r1
    adds r0, r6, #0
    adds r0, #0x11
    str r0, [sp, #0x18]
    adds r1, r6, #0
    adds r1, #8
    str r1, [sp, #0x14]
    mov r1, sb
    lsls r0, r1, #0x1e
    lsrs r3, r0, #0x1e
    ldr r4, .Ljp_080110CC @ =gMandatorySunnyCalendarDates
.Ljp_08010FA2:
    adds r0, r2, r4
    ldrb r1, [r0]
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r3, r0
    bne .Ljp_08010FBA
    lsls r0, r1, #0x19
    lsrs r0, r0, #0x1b
    cmp r5, r0
    bne .Ljp_08010FBA
    movs r0, #1
    mov r8, r0
.Ljp_08010FBA:
    adds r2, #1
    cmp r2, #0x18
    ble .Ljp_08010FA2
    ldr r1, .Ljp_080110D0 @ =0x00001CD4
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetPartnerCharacterId__C13NpcCollection
    cmp r0, #0
    bne .Ljp_08011036
    adds r0, r4, #0
    bl GetWeddingDate__C13NpcCollection
    adds r4, r0, #0
    mov ip, r4
    movs r3, #0xc8
    str r3, [sp, #4]
    ldrb r0, [r6, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #8]
    add r0, sp, #8
    add r2, sp, #4
    cmp r3, r1
    bls .Ljp_08010FF6
    adds r2, r0, #0
.Ljp_08010FF6:
    ldr r7, [r2]
    str r3, [sp, #0xc]
    ldrb r0, [r4]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #0x10]
    add r2, sp, #0x10
    add r0, sp, #0xc
    cmp r3, r1
    bls .Ljp_08011014
    adds r0, r2, #0
.Ljp_08011014:
    ldr r0, [r0]
    cmp r7, r0
    bne .Ljp_08011036
    mov r0, sb
    lsls r1, r0, #0x1e
    mov r0, ip
    ldrb r2, [r0, #1]
    lsls r0, r2, #0x1e
    cmp r1, r0
    bne .Ljp_08011036
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    cmp r5, r0
    bne .Ljp_08011036
    movs r1, #1
    mov r8, r1
.Ljp_08011036:
    ldr r5, .Ljp_080110D4 @ =0x00001D6C
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .Ljp_08011052
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .Ljp_08011052
    movs r0, #1
    mov r8, r0
.Ljp_08011052:
    ldr r1, .Ljp_080110D8 @ =0x00001E28
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .Ljp_0801106E
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .Ljp_0801106E
    movs r5, #1
    mov r8, r5
.Ljp_0801106E:
    ldr r0, .Ljp_080110DC @ =0x00001EB8
    adds r4, r6, r0
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .Ljp_0801108A
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .Ljp_0801108A
    movs r1, #1
    mov r8, r1
.Ljp_0801108A:
    ldr r5, .Ljp_080110E0 @ =0x00001EE4
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .Ljp_080110A6
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .Ljp_080110A6
    movs r0, #1
    mov r8, r0
.Ljp_080110A6:
    ldr r1, .Ljp_080110E4 @ =0x00001F38
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .Ljp_080110C2
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .Ljp_080110C2
    movs r5, #1
    mov r8, r5
.Ljp_080110C2:
    mov r0, r8
    cmp r0, #1
    bne .Ljp_080110E8
    movs r0, #0
    b .Ljp_0801114A
    .align 2, 0
.Ljp_080110CC: .4byte gMandatorySunnyCalendarDates
.Ljp_080110D0: .4byte 0x00001CD4
.Ljp_080110D4: .4byte 0x00001D6C
.Ljp_080110D8: .4byte 0x00001E28
.Ljp_080110DC: .4byte 0x00001EB8
.Ljp_080110E0: .4byte 0x00001EE4
.Ljp_080110E4: .4byte 0x00001F38
.Ljp_080110E8:
    bl rand
    asrs r2, r0, #2
    movs r0, #0xff
    ands r2, r0
    mov r1, sb
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .Ljp_08011118
    cmp r0, #1
    bgt .Ljp_08011106
    cmp r0, #0
    beq .Ljp_08011110
    b .Ljp_0801114C
.Ljp_08011106:
    cmp r0, #2
    beq .Ljp_0801112A
    cmp r0, #3
    beq .Ljp_08011136
    b .Ljp_0801114C
.Ljp_08011110:
    cmp r2, #0xb3
    bls .Ljp_0801114A
    movs r0, #1
    b .Ljp_0801114A
.Ljp_08011118:
    cmp r2, #0xe5
    bhi .Ljp_08011120
    movs r0, #0
    b .Ljp_0801114A
.Ljp_08011120:
    subs r2, #0xe6
    cmp r2, #0xc
    bls .Ljp_0801114A
    movs r0, #3
    b .Ljp_0801114A
.Ljp_0801112A:
    cmp r2, #0xcd
    bhi .Ljp_08011132
    movs r0, #0
    b .Ljp_0801114A
.Ljp_08011132:
    movs r0, #1
    b .Ljp_0801114A
.Ljp_08011136:
    cmp r2, #0x7f
    bhi .Ljp_0801113E
    movs r0, #0
    b .Ljp_0801114A
.Ljp_0801113E:
    subs r2, #0x80
    cmp r2, #0x65
    bhi .Ljp_08011148
    movs r0, #2
    b .Ljp_0801114A
.Ljp_08011148:
    movs r0, #4
.Ljp_0801114A:
    str r0, [r6, #0xc]
.Ljp_0801114C:
    ldr r1, [r6, #8]
    mov r0, sl
    ldr r2, [sp, #0x18]
    bl DayUpdate__4FarmiRC8GameDate
    ldrb r1, [r6, #0x11]
    lsls r0, r1, #0x19
    lsrs r0, r0, #0x1b
    cmp r0, #0
    bne .Ljp_08011180
    lsls r0, r1, #0x1e
    lsrs r7, r0, #0x1e
    ldr r5, .Ljp_080111E0 @ =0x000009DC
    adds r4, r6, r5
    ldr r1, .Ljp_080111E4 @ =0x00001AA8
    adds r0, r6, r1
    cmp r4, r0
    bhs .Ljp_08011180
    adds r5, r0, #0
.Ljp_08011172:
    adds r0, r4, #0
    adds r1, r7, #0
    bl method_0800AB08__9FieldPlot6Season
    adds r4, #4
    cmp r4, r5
    blo .Ljp_08011172
.Ljp_08011180:
    ldr r0, .Ljp_080111E8 @ =0x00001BD8
    adds r5, r6, r0
    adds r0, r5, #0
    bl func_0800EE60
    ldr r1, .Ljp_080111EC @ =0x00001C70
    adds r0, r6, r1
    bl DayUpdate__3Dog
    ldr r1, .Ljp_080111F0 @ =0x00002C74
    adds r0, r6, r1
    bl UpdateTVShoppingDeliveryCountdown
    ldr r0, .Ljp_080111F4 @ =0x00001CD4
    adds r4, r6, r0
    ldr r1, .Ljp_080111F8 @ =0x0000214C
    adds r2, r6, r1
    mov r0, sl
    str r0, [sp]
    adds r0, r4, #0
    ldr r1, [sp, #0x14]
    adds r3, r5, #0
    bl DayUpdate__13NpcCollectionRC14GameStateClockRC14GameEventStateRC6FarmerRC4Farm
    adds r0, r4, #0
    adds r1, r6, #0
    bl InitializeSchedules__13NpcCollectionRC18GameStateSaveImage
    ldr r1, .Ljp_080111FC @ =0x00001F64
    adds r4, r6, r1
    adds r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_080111CA
    b .Ljp_08011308
.Ljp_080111CA:
    adds r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp r0, #0xd
    bls .Ljp_080111D6
    b .Ljp_080112F8
.Ljp_080111D6:
    lsls r0, r0, #2
    ldr r1, .Ljp_08011200 @ =.Ljp_08011204
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Ljp_080111E0: .4byte 0x000009DC
.Ljp_080111E4: .4byte 0x00001AA8
.Ljp_080111E8: .4byte 0x00001BD8
.Ljp_080111EC: .4byte 0x00001C70
.Ljp_080111F0: .4byte 0x00002C74
.Ljp_080111F4: .4byte 0x00001CD4
.Ljp_080111F8: .4byte 0x0000214C
.Ljp_080111FC: .4byte 0x00001F64
.Ljp_08011200: .4byte .Ljp_08011204
.Ljp_08011204: @ jump table
    .4byte .Ljp_080112F8 @ case 0
    .4byte .Ljp_0801123C @ case 1
    .4byte .Ljp_0801125C @ case 2
    .4byte .Ljp_08011268 @ case 3
    .4byte .Ljp_08011274 @ case 4
    .4byte .Ljp_0801127C @ case 5
    .4byte .Ljp_0801128A @ case 6
    .4byte .Ljp_08011298 @ case 7
    .4byte .Ljp_080112A6 @ case 8
    .4byte .Ljp_080112B4 @ case 9
    .4byte .Ljp_080112C2 @ case 10
    .4byte .Ljp_080112D0 @ case 11
    .4byte .Ljp_080112DE @ case 12
    .4byte .Ljp_080112EC @ case 13
.Ljp_0801123C:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    bhi .Ljp_08011254
    adds r0, r4, #0
    bl UpgradeHouseLevel__9FarmHouse
    b .Ljp_080112F8
.Ljp_08011254:
    adds r0, r4, #0
    bl AddBathroom__9FarmHouse
    b .Ljp_080112F8
.Ljp_0801125C:
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r6, r1
    bl Upgrade__4Coop
    b .Ljp_080112F8
.Ljp_08011268:
    movs r5, #0xbe
    lsls r5, r5, #3
    adds r0, r6, r5
    bl Upgrade__4Barn
    b .Ljp_080112F8
.Ljp_08011274:
    adds r0, r6, #0
    bl SetFlag1__18GameStateSaveImage
    b .Ljp_080112F8
.Ljp_0801127C:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #0
    bl SetWindowStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_0801128A:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #1
    bl SetWindowStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_08011298:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #2
    bl SetWindowStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112A6:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #0
    bl SetMailboxStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112B4:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #1
    bl SetMailboxStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112C2:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #2
    bl SetMailboxStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112D0:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #0
    bl SetDoghouseStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112DE:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #1
    bl SetDoghouseStyle__9FarmHouseUi
    b .Ljp_080112F8
.Ljp_080112EC:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #2
    bl SetDoghouseStyle__9FarmHouseUi
.Ljp_080112F8:
    ldr r5, .Ljp_08011304 @ =0x00001F64
    adds r0, r6, r5
    bl FinishConstruction__4Gotz
    b .Ljp_0801130E
    .align 2, 0
.Ljp_08011304: .4byte 0x00001F64
.Ljp_08011308:
    adds r0, r4, #0
    bl UpdateConstructionWorksite__4Gotz
.Ljp_0801130E:
    ldr r0, .Ljp_08011334 @ =0x00001DAC
    adds r4, r6, r0
    adds r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Ljp_0801138A
    adds r0, r4, #0
    bl GetOrder__C7Saibara
    cmp r0, #0x24
    beq .Ljp_08011358
    cmp r0, #0x24
    bgt .Ljp_08011338
    cmp r0, #0x23
    beq .Ljp_0801133E
    b .Ljp_0801138A
    .align 2, 0
.Ljp_08011334: .4byte 0x00001DAC
.Ljp_08011338:
    cmp r0, #0x25
    beq .Ljp_08011372
    b .Ljp_0801138A
.Ljp_0801133E:
    movs r1, #0x82
    lsls r1, r1, #3
    adds r4, r6, r1
    adds r0, r4, #0
    bl method_0800C5C4__C4Coop
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_0801138A
    adds r0, r4, #0
    bl method_0800C888__4Coop
    b .Ljp_0801138A
.Ljp_08011358:
    movs r5, #0xbe
    lsls r5, r5, #3
    adds r4, r6, r5
    adds r0, r4, #0
    bl method_0800CF00__C4Barn
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_0801138A
    adds r0, r4, #0
    bl method_0800D3A0__4Barn
    b .Ljp_0801138A
.Ljp_08011372:
    movs r0, #0xbe
    lsls r0, r0, #3
    adds r4, r6, r0
    adds r0, r4, #0
    bl method_0800CF08__C4Barn
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_0801138A
    adds r0, r4, #0
    bl method_0800D3B8__4Barn
.Ljp_0801138A:
    ldrb r0, [r6, #0x11]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    cmp r0, #0
    bne .Ljp_080113A4
    ldr r1, .Ljp_080113A0 @ =0x00001AA8
    adds r0, r6, r1
    bl UpdateMoneyAccountRecordHistory
    b .Ljp_080113AC
    .align 2, 0
.Ljp_080113A0: .4byte 0x00001AA8
.Ljp_080113A4:
    ldr r5, .Ljp_080113E0 @ =0x00001AA8
    adds r0, r6, r5
    bl AppendMoneyAccountRecord30
.Ljp_080113AC:
    ldr r1, .Ljp_080113E4 @ =0x000034C8
    adds r0, r6, r1
    bl Reset__14FieldItemState
    ldr r5, .Ljp_080113E8 @ =0x000034DC
    adds r0, r6, r5
    bl ResetActorRuntimeState
    ldrb r1, [r6, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r6, #3]
    ldrb r1, [r6, #4]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r6, #4]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Ljp_080113E0: .4byte 0x00001AA8
.Ljp_080113E4: .4byte 0x000034C8
.Ljp_080113E8: .4byte 0x000034DC
    .section .text.game_state_after_display_options

    .global __18GameStateSaveImageR10SramAccessUiRUi
    .thumb_func
__18GameStateSaveImageR10SramAccessUiRUi:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r7, r0, #0
    str r1, [sp, #0x14]
    mov sl, r2
    adds r6, r3, #0
    adds r1, r7, #0
    adds r1, #8
    movs r0, #0
    mov sb, r0
    str r0, [r7, #8]
    str r0, [r1, #4]
    mov r2, sb
    strb r2, [r1, #8]
    ldrb r2, [r1, #9]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    movs r3, #0x7d
    rsbs r3, r3, #0
    mov r8, r3
    ands r0, r3
    strb r0, [r1, #9]
    ldrb r2, [r1, #0xa]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1, #0xa]
    ldrh r2, [r1, #0xa]
    ldr r0, .Ljp_08011850 @ =0xFFFFF81F
    ands r0, r2
    strh r0, [r1, #0xa]
    adds r0, r7, #0
    adds r0, #0x14
    ldr r5, .Ljp_08011854 @ =gText_LoadError
    adds r1, r5, #0
    bl __4FarmPCc
    ldr r1, .Ljp_08011858 @ =0x00001AA8
    adds r0, r7, r1
    bl InitializeMoneyAccount
    ldr r2, .Ljp_0801185C @ =0x00001BD8
    adds r0, r7, r2
    mov r1, sp
    ldrb r1, [r1]
    ands r4, r1
    mov r1, sp
    strb r4, [r1]
    mov r3, r8
    ands r4, r3
    strb r4, [r1]
    adds r1, r5, #0
    mov r2, sp
    bl __6FarmerPCcRC8GameDate
    ldr r1, .Ljp_08011860 @ =0x00001C70
    adds r0, r7, r1
    adds r1, r5, #0
    bl __3DogPCc
    movs r2, #0xe5
    lsls r2, r2, #5
    adds r0, r7, r2
    bl __9MoreItems
    ldr r3, .Ljp_08011864 @ =0x00001CCC
    adds r1, r7, r3
    movs r4, #0x8d
    lsls r4, r4, #2
    ldrh r2, [r1]
    ldr r3, .Ljp_08011868 @ =0xFFFFFC00
    adds r0, r3, #0
    ands r0, r2
    orrs r0, r4
    strh r0, [r1]
    movs r5, #0
    ldrb r4, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r4
    strb r0, [r1, #1]
    ldrh r4, [r1, #2]
    adds r0, r3, #0
    ands r0, r4
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    strb r2, [r1, #3]
    ldrh r0, [r1, #4]
    ands r3, r0
    strh r3, [r1, #4]
    ldr r1, .Ljp_0801186C @ =0x00001CD4
    adds r0, r7, r1
    bl __13NpcCollection
    ldr r2, .Ljp_08011870 @ =0x0000214C
    adds r0, r7, r2
    bl __14GameEventState
    ldr r3, .Ljp_08011874 @ =0x000021CC
    adds r2, r7, r3
    movs r0, #1
    str r0, [r2]
    mov r0, sb
    str r0, [r2, #4]
    ldr r1, .Ljp_08011878 @ =0x000021E0
    adds r0, r7, r1
    strb r5, [r0]
    adds r3, #0x24
    adds r0, r7, r3
    strb r5, [r0]
    adds r1, #0x20
    adds r0, r7, r1
    strb r5, [r0]
    mov r3, sb
    str r3, [sp, #4]
    subs r1, #0x2c
    adds r0, r7, r1
    movs r1, #8
    add r5, sp, #8
    add r3, sp, #0xc
    mov sb, r3
    movs r3, #0
.Ljp_08011732:
    strb r3, [r0]
    subs r1, #1
    adds r0, #1
    cmp r1, #0
    bgt .Ljp_08011732
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r2, #0
    adds r0, #0x10
    movs r1, #4
    ldr r2, .Ljp_0801187C @ =0x00002C48
    adds r4, r7, r2
    ldr r3, .Ljp_08011880 @ =0x00002C4A
    adds r3, r3, r7
    mov r8, r3
    ldr r2, [r5]
.Ljp_08011752:
    strb r2, [r0]
    subs r1, #1
    adds r0, #1
    cmp r1, #0
    bgt .Ljp_08011752
    ldr r1, .Ljp_08011884 @ =0x00002210
    adds r0, r7, r1
    bl InitializeGameDisplayOptions
    ldr r2, .Ljp_08011888 @ =0x00002214
    adds r0, r7, r2
    bl __22CookingRecipeInventory
    ldr r3, .Ljp_0801188C @ =0x00002C1C
    adds r2, r7, r3
    ldrb r0, [r4]
    movs r1, #3
    orrs r0, r1
    strb r0, [r4]
    ldr r0, [r2, #0x2c]
    ldr r1, .Ljp_08011890 @ =0xFFF80003
    ands r0, r1
    str r0, [r2, #0x2c]
    mov r0, r8
    ldrb r1, [r0]
    movs r0, #9
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x11
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x10
    ands r0, r1
    subs r1, #0x20
    ands r0, r1
    movs r1, #0x7f
    ands r0, r1
    mov r1, r8
    strb r0, [r1]
    ldr r2, .Ljp_08011894 @ =0x00002C4C
    adds r0, r7, r2
    movs r1, #9
    movs r2, #0
    movs r3, #1
    rsbs r3, r3, #0
.Ljp_080117AC:
    strb r2, [r0]
    strh r2, [r0, #2]
    adds r0, #4
    subs r1, #1
    cmp r1, r3
    bne .Ljp_080117AC
    ldr r3, .Ljp_08011898 @ =0x00002C74
    adds r0, r7, r3
    bl InitializeTVShoppingOrderState
    movs r1, #0xb2
    lsls r1, r1, #6
    adds r0, r7, r1
    bl __14FishingRecords
    ldr r2, .Ljp_0801189C @ =0x00002E58
    adds r0, r7, r2
    bl __14MineFloorState
    movs r3, #0xd2
    lsls r3, r3, #6
    adds r0, r7, r3
    bl __15CursedToolState
    ldr r0, .Ljp_080118A0 @ =0x00003494
    adds r2, r7, r0
    movs r3, #2
    movs r5, #0x10
    rsbs r5, r5, #0
    movs r4, #1
    rsbs r4, r4, #0
.Ljp_080117EA:
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    strb r0, [r2]
    adds r2, #0x10
    subs r3, #1
    cmp r3, r4
    bne .Ljp_080117EA
    ldr r1, .Ljp_080118A4 @ =0x000034C8
    adds r0, r7, r1
    bl __14FieldItemState
    ldr r2, .Ljp_080118A8 @ =0x000034D8
    adds r0, r7, r2
    bl __13MapPatchFlags
    ldr r3, .Ljp_080118AC @ =0x000034DC
    adds r0, r7, r3
    bl __18Unk_Actor_0809BFE8
    movs r5, #0
    str r5, [r6]
    str r5, [sp, #0xc]
    ldr r0, [sp, #0x14]
    mov r1, sb
    mov r2, sl
    movs r3, #4
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Ljp_080118EE
    ldr r4, [sp, #0xc]
    ldr r0, .Ljp_080118B0 @ =0x000034F4
    cmp r4, r0
    bne .Ljp_080118EE
    mov r2, sl
    adds r2, #4
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    adds r3, r4, #0
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_080118B8
    ldr r2, .Ljp_080118B4 @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0x80
    lsls r1, r1, #0xa
    b .Ljp_080118F6
    .align 2, 0
.Ljp_08011850: .4byte 0xFFFFF81F
.Ljp_08011854: .4byte gText_LoadError
.Ljp_08011858: .4byte 0x00001AA8
.Ljp_0801185C: .4byte 0x00001BD8
.Ljp_08011860: .4byte 0x00001C70
.Ljp_08011864: .4byte 0x00001CCC
.Ljp_08011868: .4byte 0xFFFFFC00
.Ljp_0801186C: .4byte 0x00001CD4
.Ljp_08011870: .4byte 0x0000214C
.Ljp_08011874: .4byte 0x000021CC
.Ljp_08011878: .4byte 0x000021E0
.Ljp_0801187C: .4byte 0x00002C48
.Ljp_08011880: .4byte 0x00002C4A
.Ljp_08011884: .4byte 0x00002210
.Ljp_08011888: .4byte 0x00002214
.Ljp_0801188C: .4byte 0x00002C1C
.Ljp_08011890: .4byte 0xFFF80003
.Ljp_08011894: .4byte 0x00002C4C
.Ljp_08011898: .4byte 0x00002C74
.Ljp_0801189C: .4byte 0x00002E58
.Ljp_080118A0: .4byte 0x00003494
.Ljp_080118A4: .4byte 0x000034C8
.Ljp_080118A8: .4byte 0x000034D8
.Ljp_080118AC: .4byte 0x000034DC
.Ljp_080118B0: .4byte 0x000034F4
.Ljp_080118B4: .4byte gSramAccessStatus
.Ljp_080118B8:
    ldr r2, .Ljp_080118D8 @ =0x000034F8
    add r2, sl
    str r5, [sp, #0x10]
    add r1, sp, #0x10
    ldr r0, [sp, #0x14]
    movs r3, #4
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_080118E0
    ldr r2, .Ljp_080118DC @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0xc0
    lsls r1, r1, #0xa
    b .Ljp_080118F6
    .align 2, 0
.Ljp_080118D8: .4byte 0x000034F8
.Ljp_080118DC: .4byte gSramAccessStatus
.Ljp_080118E0:
    adds r0, r7, #0
    adds r1, r4, #0
    bl CalculateSaveImageChecksum
    ldr r1, [sp, #0x10]
    cmp r0, r1
    beq .Ljp_080118FE
.Ljp_080118EE:
    ldr r2, .Ljp_08011910 @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0x80
    lsls r1, r1, #9
.Ljp_080118F6:
    orrs r0, r1
    ldrh r1, [r2]
    orrs r0, r1
    str r0, [r6]
.Ljp_080118FE:
    adds r0, r7, #0
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Ljp_08011910: .4byte gSramAccessStatus

    .section .text.game_scene_after_actor_commands, "ax", %progbits

    .global ShowLivestockNeglectDeathSummary
    .thumb_func
ShowLivestockNeglectDeathSummary:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .Ljp_08014FE4
    add sp, r4
    ldr r0, [r0, #4]
    mov sl, r0
    mov r4, sl
    adds r4, #240
    movs r7, #0
    ldr r0, [r4, #0]
    cmp r7, r0
    beq .Ljp_08014C92
    bl __builtin_delete
.Ljp_08014C92:
    str r7, [r4, #0]
    mov r0, sp
    strb r7, [r0, #0]
    ldr r1, .Ljp_08014FE8
    add r0, sp, #900
    movs r2, #3
    bl memcpy
    ldr r1, .Ljp_08014FEC
    add r0, sp, #904
    movs r2, #2
    bl memcpy
    ldr r1, .Ljp_08014FF0
    add r0, sp, #908
    movs r2, #2
    bl memcpy
    mov r9, sp
    ldr r0, .Ljp_08014FF4
    mov r8, r0
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014CEA
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014CDC
    adds r4, r5, #0
.Ljp_08014CDC:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    strb r7, [r0, #0]
.Ljp_08014CEA:
    mov r0, sl
    adds r0, #140
    ldr r0, [r0, #0]
    adds r0, #20
    bl GetName__C4Farm
    mov r8, r0
    mov r6, r9
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014D2A
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014D1A
    adds r4, r5, #0
.Ljp_08014D1A:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014D2A:
    ldr r0, .Ljp_08014FFC
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014D5C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014D4C
    adds r4, r5, #0
.Ljp_08014D4C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014D5C:
    ldr r1, .Ljp_08014FE8
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014D8E
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014D7E
    adds r4, r5, #0
.Ljp_08014D7E:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014D8E:
    ldr r0, .Ljp_08015000
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014DC0
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014DB0
    adds r4, r5, #0
.Ljp_08014DB0:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014DC0:
    ldr r1, .Ljp_08014FE8
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014DF2
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014DE2
    adds r4, r5, #0
.Ljp_08014DE2:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014DF2:
    ldr r0, .Ljp_08015004
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014E24
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014E14
    adds r4, r5, #0
.Ljp_08014E14:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014E24:
    ldr r1, .Ljp_08014FEC
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014E56
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014E46
    adds r4, r5, #0
.Ljp_08014E46:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014E56:
    ldr r0, .Ljp_08014FE8
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014E88
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014E78
    adds r4, r5, #0
.Ljp_08014E78:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014E88:
    ldr r7, .Ljp_08014FF0
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014EB8
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014EA8
    adds r4, r5, #0
.Ljp_08014EA8:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014EB8:
    mov r0, sl
    movs r1, #2
    mov r2, sp
    bl AppendAnimalMemorialNames
    mov r8, sp
    ldr r7, .Ljp_08014FF0
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014EF6
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014EE6
    adds r4, r5, #0
.Ljp_08014EE6:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014EF6:
    mov r6, r8
    ldr r0, .Ljp_08015008
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014F2A
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014F1A
    adds r4, r5, #0
.Ljp_08014F1A:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014F2A:
    ldr r1, .Ljp_08014FE8
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014F5C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014F4C
    adds r4, r5, #0
.Ljp_08014F4C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014F5C:
    ldr r0, .Ljp_0801500C
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014F8E
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014F7E
    adds r4, r5, #0
.Ljp_08014F7E:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014F8E:
    ldr r7, .Ljp_08014FEC
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    ldr r1, .Ljp_08014FF8
    subs r5, r1, r0
    cmp r5, #0
    beq .Ljp_08014FBE
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .Ljp_08014FAE
    adds r4, r5, #0
.Ljp_08014FAE:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1, #0]
.Ljp_08014FBE:
    movs r0, #225
    lsls r0, r0, #2
    bl __builtin_new
    adds r4, r0, #0
    mov r1, sp
    bl strcpy
    mov r5, sl
    adds r5, #240
    ldr r0, [r5, #0]
    cmp r4, r0
    beq .Ljp_08014FDC
    bl __builtin_delete
.Ljp_08014FDC:
    str r4, [r5, #0]
    mov r0, sl
    adds r0, #172
    b .Ljp_08015010
.Ljp_08014FE4: .4byte 0xFFFFFC70
.Ljp_08014FE8: .4byte gText_AnimalMemorial_LineBreak
.Ljp_08014FEC: .4byte gText_AnimalMemorial_Continue
.Ljp_08014FF0: .4byte gText_AnimalMemorial_PageBreak
.Ljp_08014FF4: .4byte gText_AnimalMemorial_Header
.Ljp_08014FF8: .4byte 0x00000383
.Ljp_08014FFC: .4byte gText_AnimalMemorial_FarmPrefix
.Ljp_08015000: .4byte gText_AnimalMemorial_PassedAway
.Ljp_08015004: .4byte gText_AnimalMemorial_NamesIntro
.Ljp_08015008: .4byte gText_AnimalMemorial_PrayerIntro
.Ljp_0801500C: .4byte gText_AnimalMemorial_PrayerEnding
.Ljp_08015010:
    ldr r1, [r0, #0]
    cmp r1, #0
    beq .Ljp_0801502E
    adds r0, #4
    ldr r3, [r0, #0]
    adds r0, r1, #0
    adds r1, r4, #0
    movs r2, #128
    lsls r2, r2, #1
    bl func_08050DC8
    mov r1, sl
    adds r1, #156
    movs r0, #16
    str r0, [r1, #0]
.Ljp_0801502E:
    movs r3, #228
    lsls r3, r3, #2
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
    .global RemoveLivestockDeadFromNeglect
    .thumb_func
RemoveLivestockDeadFromNeglect:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, [r0, #4]
    mov r8, r0
    mov r5, r8
    adds r5, #140
    ldr r0, [r5, #0]
    movs r1, #130
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Coop
    adds r6, r0, #0
    movs r4, #0
    cmp r4, r6
    bcs .Ljp_080150A6
    mov r7, r8
    adds r7, #168
.Ljp_0801506A:
    ldr r0, [r5, #0]
    movs r1, #130
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    beq .Ljp_080150A0
    bl GetLifeState__C9Livestock
    cmp r0, #2
    bne .Ljp_080150A0
    ldr r0, [r7, #0]
    ldr r2, [r0, #0]
    adds r1, r4, #0
    adds r1, #46
    ldr r2, [r2, #60]
    bl _call_via_r2
    ldr r0, [r5, #0]
    movs r1, #130
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4CoopUi
.Ljp_080150A0:
    adds r4, #1
    cmp r4, r6
    bcc .Ljp_0801506A
.Ljp_080150A6:
    mov r4, r8
    adds r4, #140
    ldr r0, [r4, #0]
    ldr r1, .Ljp_0801514C
    adds r5, r0, r1
    adds r0, r5, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #24
    adds r6, r4, #0
    cmp r0, #0
    bne .Ljp_080150EC
    adds r0, r5, #0
    bl GetKind__C8HeldItem
    cmp r0, #3
    bne .Ljp_080150EC
    ldr r4, [r6, #0]
    movs r0, #130
    lsls r0, r0, #3
    adds r4, r4, r0
    adds r0, r5, #0
    bl GetHeldChickenSlot
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .Ljp_080150EC
    ldr r0, [r6, #0]
    ldr r1, .Ljp_0801514C
    adds r0, r0, r1
    bl ClearHeldItem
.Ljp_080150EC:
    ldr r0, [r6, #0]
    movs r1, #190
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Barn
    adds r7, r0, #0
    movs r4, #0
    cmp r4, r7
    bcs .Ljp_08015142
    adds r5, r6, #0
    mov r6, r8
    adds r6, #168
.Ljp_08015106:
    ldr r0, [r5, #0]
    movs r1, #190
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetBarnAnimal__4BarnUi
    cmp r0, #0
    beq .Ljp_0801513C
    bl GetLifeState__C9Livestock
    cmp r0, #2
    bne .Ljp_0801513C
    ldr r0, [r6, #0]
    ldr r2, [r0, #0]
    adds r1, r4, #0
    adds r1, #54
    ldr r2, [r2, #60]
    bl _call_via_r2
    ldr r0, [r5, #0]
    movs r1, #190
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4BarnUi
.Ljp_0801513C:
    adds r4, #1
    cmp r4, r7
    bcc .Ljp_08015106
.Ljp_08015142:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Ljp_0801514C: .4byte 0x00001C2C
    .global ShowNaturalLivestockDeathSummary
    .thumb_func
ShowNaturalLivestockDeathSummary:
    push	{r4, r5, r6, r7, lr}
    mov	r7, sl
    mov	r6, r9
    mov	r5, r8
    push	{r5, r6, r7}
    ldr	r4, .Ljp_080154C4
    add	sp, r4
    ldr	r0, [r0, #4]
    mov	sl, r0
    mov	r4, sl
    adds	r4, #240
    movs	r7, #0
    ldr	r0, [r4, #0]
    cmp	r7, r0
    beq .Ljp_08015172
    bl __builtin_delete
.Ljp_08015172:
    str	r7, [r4, #0]
    mov	r0, sp
    strb	r7, [r0, #0]
    ldr	r1, .Ljp_080154C8
    add	r0, sp, #900
    movs	r2, #3
    bl memcpy
    ldr	r1, .Ljp_080154CC
    add	r0, sp, #904
    movs	r2, #2
    bl memcpy
    ldr	r1, .Ljp_080154D0
    add	r0, sp, #908
    movs	r2, #2
    bl memcpy
    mov	r9, sp
    ldr	r0, .Ljp_080154D4
    mov	r8, r0
    mov	r0, sp
    bl strlen
    mov	r1, sp
    adds	r6, r1, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_080151CA
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080151BC
    adds	r4, r5, #0
.Ljp_080151BC:
    adds	r0, r6, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r0, r6, r4
    strb	r7, [r0, #0]
.Ljp_080151CA:
    mov	r0, sl
    adds	r0, #140
    ldr	r0, [r0, #0]
    adds	r0, #20
    bl GetName__C4Farm
    mov	r8, r0
    mov	r6, r9
    mov	r4, r8
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801520A
    adds	r0, r4, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080151FA
    adds	r4, r5, #0
.Ljp_080151FA:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801520A:
    ldr	r0, .Ljp_080154DC
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801523C
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_0801522C
    adds	r4, r5, #0
.Ljp_0801522C:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801523C:
    ldr	r1, .Ljp_080154C8
    mov	r8, r1
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801526E
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_0801525E
    adds	r4, r5, #0
.Ljp_0801525E:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801526E:
    ldr	r0, .Ljp_080154E0
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_080152A0
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_08015290
    adds	r4, r5, #0
.Ljp_08015290:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080152A0:
    ldr	r1, .Ljp_080154C8
    mov	r8, r1
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_080152D2
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080152C2
    adds	r4, r5, #0
.Ljp_080152C2:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080152D2:
    ldr	r0, .Ljp_080154E4
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_08015304
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080152F4
    adds	r4, r5, #0
.Ljp_080152F4:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08015304:
    ldr	r1, .Ljp_080154CC
    mov	r8, r1
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_08015336
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_08015326
    adds	r4, r5, #0
.Ljp_08015326:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08015336:
    ldr	r0, .Ljp_080154C8
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_08015368
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_08015358
    adds	r4, r5, #0
.Ljp_08015358:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08015368:
    ldr	r7, .Ljp_080154D0
    adds	r0, r6, #0
    bl strlen
    adds	r6, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_08015398
    adds	r0, r7, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_08015388
    adds	r4, r5, #0
.Ljp_08015388:
    adds	r0, r6, #0
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r6, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_08015398:
    mov	r0, sl
    movs	r1, #1
    mov	r2, sp
    bl AppendAnimalMemorialNames
    mov	r8, sp
    ldr	r7, .Ljp_080154D0
    mov	r0, sp
    bl strlen
    mov	r1, sp
    adds	r6, r1, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_080153D6
    adds	r0, r7, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080153C6
    adds	r4, r5, #0
.Ljp_080153C6:
    adds	r0, r6, #0
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r6, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_080153D6:
    mov	r6, r8
    ldr	r0, .Ljp_080154E8
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801540A
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_080153FA
    adds	r4, r5, #0
.Ljp_080153FA:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801540A:
    ldr	r1, .Ljp_080154C8
    mov	r8, r1
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801543C
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_0801542C
    adds	r4, r5, #0
.Ljp_0801542C:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801543C:
    ldr	r0, .Ljp_080154EC
    mov	r8, r0
    adds	r0, r6, #0
    bl strlen
    adds	r7, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801546E
    mov	r0, r8
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_0801545E
    adds	r4, r5, #0
.Ljp_0801545E:
    adds	r0, r7, #0
    mov	r1, r8
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r7, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801546E:
    ldr	r7, .Ljp_080154CC
    adds	r0, r6, #0
    bl strlen
    adds	r6, r6, r0
    ldr	r1, .Ljp_080154D8
    subs	r5, r1, r0
    cmp	r5, #0
    beq .Ljp_0801549E
    adds	r0, r7, #0
    bl strlen
    adds	r4, r0, #0
    cmp	r4, r5
    bls .Ljp_0801548E
    adds	r4, r5, #0
.Ljp_0801548E:
    adds	r0, r6, #0
    adds	r1, r7, #0
    adds	r2, r4, #0
    bl memcpy
    adds	r1, r6, r4
    movs	r0, #0
    strb	r0, [r1, #0]
.Ljp_0801549E:
    movs	r0, #225
    lsls	r0, r0, #2
    bl __builtin_new
    adds	r4, r0, #0
    mov	r1, sp
    bl strcpy
    mov	r5, sl
    adds	r5, #240
    ldr	r0, [r5, #0]
    cmp	r4, r0
    beq .Ljp_080154BC
    bl __builtin_delete
.Ljp_080154BC:
    str	r4, [r5, #0]
    mov	r0, sl
    adds	r0, #172
    b .Ljp_080154F0
.Ljp_080154C4: .4byte 0xFFFFFC70
.Ljp_080154C8: .4byte gText_AnimalMemorial_LineBreak
.Ljp_080154CC: .4byte gText_AnimalMemorial_Continue
.Ljp_080154D0: .4byte gText_AnimalMemorial_PageBreak
.Ljp_080154D4: .4byte gText_AnimalMemorial_Header
.Ljp_080154D8: .4byte 0x00000383
.Ljp_080154DC: .4byte gText_AnimalMemorial_FarmPrefix
.Ljp_080154E0: .4byte gText_AnimalMemorial_PassedNaturalLife
.Ljp_080154E4: .4byte gText_AnimalMemorial_NamesIntro
.Ljp_080154E8: .4byte gText_AnimalMemorial_PrayerIntro
.Ljp_080154EC: .4byte gText_AnimalMemorial_PrayerEnding
.Ljp_080154F0:
    ldr	r1, [r0, #0]
    cmp	r1, #0
    beq .Ljp_0801550E
    adds	r0, #4
    ldr	r3, [r0, #0]
    adds	r0, r1, #0
    adds	r1, r4, #0
    movs	r2, #128
    lsls	r2, r2, #1
    bl func_08050DC8
    mov	r1, sl
    adds	r1, #156
    movs	r0, #16
    str	r0, [r1, #0]
.Ljp_0801550E:
    movs	r3, #228
    lsls	r3, r3, #2
    add	sp, r3
    pop	{r3, r4, r5}
    mov	r8, r3
    mov	r9, r4
    mov	sl, r5
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
    .global RemoveNaturallyDeadLivestock
    .thumb_func
RemoveNaturallyDeadLivestock:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    ldr	r0, [r0, #4]
    mov	r8, r0
    mov	r5, r8
    adds	r5, #140
    ldr	r0, [r5, #0]
    movs	r1, #130
    lsls	r1, r1, #3
    adds	r0, r0, r1
    bl GetCapacity__C4Coop
    adds	r6, r0, #0
    movs	r4, #0
    cmp	r4, r6
    bcs .Ljp_08015586
    mov	r7, r8
    adds	r7, #168
.Ljp_0801554A:
    ldr	r0, [r5, #0]
    movs	r1, #130
    lsls	r1, r1, #3
    adds	r0, r0, r1
    adds	r1, r4, #0
    bl GetChicken__4CoopUi
    cmp	r0, #0
    beq .Ljp_08015580
    bl GetLifeState__C9Livestock
    cmp	r0, #1
    bne .Ljp_08015580
    ldr	r0, [r7, #0]
    ldr	r2, [r0, #0]
    adds	r1, r4, #0
    adds	r1, #46
    ldr	r2, [r2, #60]
    bl _call_via_r2
    ldr	r0, [r5, #0]
    movs	r1, #130
    lsls	r1, r1, #3
    adds	r0, r0, r1
    adds	r1, r4, #0
    bl RemoveAndRememberUnk__4CoopUi
.Ljp_08015580:
    adds	r4, #1
    cmp	r4, r6
    bcc .Ljp_0801554A
.Ljp_08015586:
    mov	r4, r8
    adds	r4, #140
    ldr	r0, [r4, #0]
    ldr	r1, .Ljp_0801562C
    adds	r5, r0, r1
    adds	r0, r5, #0
    bl IsHeldItemEmpty
    lsls	r0, r0, #24
    adds	r6, r4, #0
    cmp	r0, #0
    bne .Ljp_080155CC
    adds	r0, r5, #0
    bl GetKind__C8HeldItem
    cmp	r0, #3
    bne .Ljp_080155CC
    ldr	r4, [r6, #0]
    movs	r0, #130
    lsls	r0, r0, #3
    adds	r4, r4, r0
    adds	r0, r5, #0
    bl GetHeldChickenSlot
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetChicken__4CoopUi
    cmp	r0, #0
    bne .Ljp_080155CC
    ldr	r0, [r6, #0]
    ldr	r1, .Ljp_0801562C
    adds	r0, r0, r1
    bl ClearHeldItem
.Ljp_080155CC:
    ldr	r0, [r6, #0]
    movs	r1, #190
    lsls	r1, r1, #3
    adds	r0, r0, r1
    bl GetCapacity__C4Barn
    adds	r7, r0, #0
    movs	r4, #0
    cmp	r4, r7
    bcs .Ljp_08015622
    adds	r5, r6, #0
    mov	r6, r8
    adds	r6, #168
.Ljp_080155E6:
    ldr	r0, [r5, #0]
    movs	r1, #190
    lsls	r1, r1, #3
    adds	r0, r0, r1
    adds	r1, r4, #0
    bl GetBarnAnimal__4BarnUi
    cmp	r0, #0
    beq .Ljp_0801561C
    bl GetLifeState__C9Livestock
    cmp	r0, #1
    bne .Ljp_0801561C
    ldr	r0, [r6, #0]
    ldr	r2, [r0, #0]
    adds	r1, r4, #0
    adds	r1, #54
    ldr	r2, [r2, #60]
    bl _call_via_r2
    ldr	r0, [r5, #0]
    movs	r1, #190
    lsls	r1, r1, #3
    adds	r0, r0, r1
    adds	r1, r4, #0
    bl RemoveAndRememberUnk__4BarnUi
.Ljp_0801561C:
    adds	r4, #1
    cmp	r4, r7
    bcc .Ljp_080155E6
.Ljp_08015622:
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
.Ljp_0801562C: .4byte 0x00001C2C
    .section .text.game_scene_field_item_tool_after, "ax", %progbits
    .align 2, 0

    .section .text.game_scene_palette_resource_selector_after, "ax", %progbits
    .align 2, 0

    .global SetWorldSpritePaletteColors
    .thumb_func
SetWorldSpritePaletteColors:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc0
    adds r7, r0, #0
    mov r8, r1
    str r2, [sp, #0x90]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov sl, r3
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lraw_game_state_2129_2
    movs r0, #0xde
    lsls r0, r0, #1
    adds r4, r7, r0
    ldr r1, [sp, #0x90]
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r0, r4, #0
    mov r1, r8
    movs r2, #0x20
    bl memcpy
    adds r1, r4, #0
    adds r1, #0x82
    movs r0, #1
    strb r0, [r1]
    adds r4, #0x83
    mov r2, sl
    strb r2, [r4]
    b .Lraw_game_state_2242_14
.Lraw_game_state_2129_2:
    ldr r0, [r7, #4]
    ldr r1, [r0]
    ldr r3, .Lraw_game_state_2130_12
    adds r0, r7, r3
    ldr r0, [r0]
    adds r0, #8
    cmp r1, #0x2e
    beq .Lraw_game_state_2131_8
    cmp r1, #0x2e
    ble .Lraw_game_state_2131_0
    cmp r1, #0x2f
    beq .Lraw_game_state_2131_12
    b .Lraw_game_state_2132_0
.Lraw_game_state_2130_12: .word 0x00001038
.Lraw_game_state_2131_0:
    cmp r1, #0x2c
    blt .Lraw_game_state_2132_0
    movs r3, #0
    b .Lraw_game_state_2132_2
.Lraw_game_state_2131_8:
    movs r3, #1
    b .Lraw_game_state_2132_2
.Lraw_game_state_2131_12:
    movs r3, #2
    b .Lraw_game_state_2132_2
.Lraw_game_state_2132_0:
    ldr r3, [r0]
.Lraw_game_state_2132_2:
    ldr r4, .Lraw_game_state_2140_12
    adds r0, r7, r4
    ldrb r1, [r0]
    movs r2, #0x1e
    movs r5, #0xce
    lsls r5, r5, #1
    adds r5, r5, r7
    mov sb, r5
    ldr r6, .Lraw_game_state_2141_0
    adds r0, r7, r6
    ldr r6, [r0]
    str r1, [sp, #0x94]
    subs r2, r2, r1
    str r2, [sp, #0x98]
    movs r0, #0xde
    lsls r0, r0, #1
    adds r4, r7, r0
    ldr r1, [sp, #0x90]
    lsls r5, r1, #5
    adds r0, r5, r1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r0, r4, #0
    mov r1, r8
    movs r2, #0x20
    str r3, [sp, #0xbc]
    bl memcpy
    adds r2, r4, #0
    adds r2, #0x82
    movs r0, #1
    mov ip, r0
    mov r1, ip
    strb r1, [r2]
    adds r0, r4, #0
    adds r0, #0x83
    mov r1, sl
    strb r1, [r0]
    mov r8, r4
    str r5, [sp, #0xa0]
    ldr r3, [sp, #0xbc]
    mov r4, sl
    cmp r4, #0
    bne .Lraw_game_state_2141_4
    mov r1, r8
    adds r1, #0x20
    mov r0, r8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    mov r1, r8
    adds r1, #0x40
    mov r0, r8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    mov r5, ip
    strb r5, [r2]
    movs r6, #0xde
    lsls r6, r6, #1
    adds r6, r6, r7
    mov sl, r6
    b .Lraw_game_state_2237_2
.Lraw_game_state_2140_12: .word 0x0000104C
.Lraw_game_state_2141_0: .word 0x00001048
.Lraw_game_state_2141_4:
    str r2, [sp, #0xb8]
    movs r0, #0xde
    lsls r0, r0, #1
    adds r0, r0, r7
    mov sl, r0
    cmp r3, #4
    bls .Lraw_game_state_2142_4
    b .Lraw_game_state_2236_12
.Lraw_game_state_2142_4:
    lsls r0, r3, #2
    ldr r1, .Lraw_game_state_2143_0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Lraw_game_state_2143_0: .word .Lswitch_0801B8B0
.Lswitch_0801B8B0: .word .Lraw_game_state_2144_8
    .word .Lraw_game_state_2188_0
    .word .Lraw_game_state_2188_0
    .word .Lraw_game_state_2144_8
    .word .Lraw_game_state_2144_8
.Lraw_game_state_2144_8:
    cmp r6, #1
    bne .Lraw_game_state_2144_14
    b .Lraw_game_state_2168_0
.Lraw_game_state_2144_14:
    cmp r6, #1
    bgt .Lraw_game_state_2146_4
    cmp r6, #0
    beq .Lraw_game_state_2159_4
    mov r1, r8
    adds r1, #0x82
    str r1, [sp, #0xb8]
    movs r2, #0x20
    add r2, sb
    mov sl, r2
    b .Lraw_game_state_2236_12
.Lraw_game_state_2146_4:
    cmp r6, #2
    bne .Lraw_game_state_2146_10
    b .Lraw_game_state_2174_8
.Lraw_game_state_2146_10:
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r4, #0x20
    add r4, sb
    mov sl, r4
    cmp r6, #3
    beq .Lraw_game_state_2147_12
    b .Lraw_game_state_2236_12
.Lraw_game_state_2147_12:
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
    ldr r0, .Lraw_game_state_2156_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r3, .Lraw_game_state_2157_0
    str r3, [sp, #0x24]
    mov r1, sp
    adds r6, r2, #0
    adds r5, r0, #0
    add r7, sp, #0x28
    add r4, sp, #0x2c
    mov sb, r4
    adds r4, r2, #0
    cmp sp, r4
    beq .Lraw_game_state_2151_14
    adds r4, r3, #0
.Lraw_game_state_2151_6:
    strh r4, [r1]
    adds r1, #2
    cmp r1, r6
    bne .Lraw_game_state_2151_6
.Lraw_game_state_2151_14:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2158_0
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
    ldr r0, .Lraw_game_state_2156_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_2159_0
    str r0, [sp, #0x2c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_2155_12
    b .Lraw_game_state_2223_8
.Lraw_game_state_2155_12:
    mov r5, sb
    ldr r2, [r5]
.Lraw_game_state_2156_0:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2156_0
    b .Lraw_game_state_2223_8
    .align 2, 0
.Lraw_game_state_2156_12: .word 0xFFFFFC1F
.Lraw_game_state_2157_0: .word 0x00002529
.Lraw_game_state_2158_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2159_0: .word 0x00001BAA
.Lraw_game_state_2159_4:
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
    ldr r0, .Lraw_game_state_2165_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_2166_0
    str r6, [sp, #0x34]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_2164_0
.Lraw_game_state_2163_8:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_2163_8
.Lraw_game_state_2164_0:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2167_0
    bl _call_via_r4
    adds r0, r5, #0
    adds r0, #0x20
    mov r1, r8
    movs r2, #0x20
    bl memcpy
    b .Lraw_game_state_2236_12
    .align 2, 0
.Lraw_game_state_2165_12: .word 0xFFFFFC1F
.Lraw_game_state_2166_0: .word 0x00001BAA
.Lraw_game_state_2167_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2168_0:
    mov r4, r8
    adds r4, #0x20
    adds r0, r4, #0
    mov r1, r8
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
    ldr r0, .Lraw_game_state_2174_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, #0x20
    movs r0, #8
    lsls r6, r0, #5
    movs r1, #0x20
    orrs r6, r1
    lsls r0, r0, #0xa
    orrs r6, r0
    str r6, [sp, #0x3c]
    mov r0, sp
    add r1, sp, #0x20
    mov r5, r8
    adds r5, #0x82
    str r5, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r1
    beq .Lraw_game_state_2174_0
.Lraw_game_state_2173_8:
    strh r6, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2173_8
.Lraw_game_state_2174_0:
    ldr r3, [r2]
    b .Lraw_game_state_2223_10
.Lraw_game_state_2174_4: .word 0xFFFFFC1F
.Lraw_game_state_2174_8:
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
    ldr r0, .Lraw_game_state_2185_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r7, r8
    adds r7, #0x20
    adds r3, r2, #0
    movs r0, #8
    lsls r2, r0, #5
    movs r1, #0x20
    orrs r2, r1
    lsls r0, r0, #0xa
    orrs r2, r0
    str r2, [sp, #0x44]
    mov r4, sp
    add r6, sp, #0x20
    adds r5, r7, #0
    mov r0, sp
    adds r0, #0x48
    str r0, [sp, #0xa4]
    mov r1, sp
    adds r1, #0x4c
    str r1, [sp, #0xa8]
    mov r0, r8
    adds r0, #0x82
    str r0, [sp, #0xb8]
    movs r1, #0x20
    add r1, sb
    mov sl, r1
    cmp sp, r6
    beq .Lraw_game_state_2180_6
    adds r0, r2, #0
.Lraw_game_state_2179_14:
    strh r0, [r4]
    adds r4, #2
    cmp r4, r6
    bne .Lraw_game_state_2179_14
.Lraw_game_state_2180_6:
    ldr r3, [r3]
    adds r0, r7, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2186_0
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
    ldr r0, .Lraw_game_state_2185_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    ldr r3, [sp, #0xa4]
    ldr r0, .Lraw_game_state_2187_0
    str r0, [sp, #0x4c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_2184_6
    b .Lraw_game_state_2223_8
.Lraw_game_state_2184_6:
    ldr r5, [sp, #0xa8]
    ldr r2, [r5]
.Lraw_game_state_2184_10:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2184_10
    b .Lraw_game_state_2223_8
.Lraw_game_state_2185_4: .word 0xFFFFFC1F
.Lraw_game_state_2186_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2187_0: .word 0x00002529
.Lraw_game_state_2188_0:
    cmp r6, #1
    bne .Lraw_game_state_2188_6
    b .Lraw_game_state_2214_0
.Lraw_game_state_2188_6:
    cmp r6, #1
    bgt .Lraw_game_state_2189_12
    cmp r6, #0
    beq .Lraw_game_state_2203_0
    mov r6, r8
    adds r6, #0x82
    str r6, [sp, #0xb8]
    movs r0, #0x20
    add r0, sb
    mov sl, r0
    b .Lraw_game_state_2236_12
.Lraw_game_state_2189_12:
    cmp r6, #2
    bne .Lraw_game_state_2190_2
    b .Lraw_game_state_2226_0
.Lraw_game_state_2190_2:
    mov r1, r8
    adds r1, #0x82
    str r1, [sp, #0xb8]
    movs r2, #0x20
    add r2, sb
    mov sl, r2
    cmp r6, #3
    beq .Lraw_game_state_2191_4
    b .Lraw_game_state_2236_12
.Lraw_game_state_2191_4:
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
    ldr r0, .Lraw_game_state_2200_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_2200_4
    str r6, [sp, #0x54]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x58
    add r3, sp, #0x5c
    mov sb, r3
    cmp sp, r4
    beq .Lraw_game_state_2195_2
.Lraw_game_state_2194_10:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_2194_10
.Lraw_game_state_2195_2:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2201_0
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
    ldr r0, .Lraw_game_state_2200_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_2202_0
    str r0, [sp, #0x5c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_2199_0
    b .Lraw_game_state_2223_8
.Lraw_game_state_2199_0:
    mov r5, sb
    ldr r2, [r5]
.Lraw_game_state_2199_4:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2199_4
    b .Lraw_game_state_2223_8
    .align 2, 0
.Lraw_game_state_2200_0: .word 0xFFFFFC1F
.Lraw_game_state_2200_4: .word 0x00002529
.Lraw_game_state_2201_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2202_0: .word 0x00006A32
.Lraw_game_state_2203_0:
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
    ldr r0, .Lraw_game_state_2212_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_2212_12
    str r6, [sp, #0x64]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x68
    mov r3, sp
    adds r3, #0x6c
    str r3, [sp, #0xac]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_2207_12
.Lraw_game_state_2207_4:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_2207_4
.Lraw_game_state_2207_12:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2213_0
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
    ldr r0, .Lraw_game_state_2212_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_2212_12
    str r0, [sp, #0x6c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    beq .Lraw_game_state_2223_8
    ldr r5, [sp, #0xac]
    ldr r2, [r5]
.Lraw_game_state_2211_12:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2211_12
    b .Lraw_game_state_2223_8
    .align 2, 0
.Lraw_game_state_2212_8: .word 0xFFFFFC1F
.Lraw_game_state_2212_12: .word 0x00006A32
.Lraw_game_state_2213_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2214_0:
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
    ldr r0, .Lraw_game_state_2224_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_2224_12
    str r6, [sp, #0x74]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x78
    mov r3, sp
    adds r3, #0x7c
    str r3, [sp, #0xb0]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_2219_0
.Lraw_game_state_2218_8:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_2218_8
.Lraw_game_state_2219_0:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2225_0
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
    ldr r0, .Lraw_game_state_2224_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_2224_12
    str r0, [sp, #0x7c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    beq .Lraw_game_state_2223_8
    ldr r5, [sp, #0xb0]
    ldr r2, [r5]
.Lraw_game_state_2223_0:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2223_0
.Lraw_game_state_2223_8:
    ldr r3, [r3]
.Lraw_game_state_2223_10:
    adds r0, r4, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2225_0
    bl _call_via_r4
    b .Lraw_game_state_2236_12
.Lraw_game_state_2224_8: .word 0xFFFFFC1F
.Lraw_game_state_2224_12: .word 0x00006A32
.Lraw_game_state_2225_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2226_0:
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
    ldr r0, .Lraw_game_state_2244_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r6, r8
    adds r6, #0x20
    ldr r4, .Lraw_game_state_2244_4
    add r0, sp, #0x84
    str r4, [r0]
    mov r0, sp
    add r1, sp, #0x20
    adds r5, r6, #0
    add r7, sp, #0x88
    mov r3, sp
    adds r3, #0x8c
    str r3, [sp, #0xb4]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r1
    beq .Lraw_game_state_2231_2
.Lraw_game_state_2230_10:
    strh r4, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2230_10
.Lraw_game_state_2231_2:
    ldr r3, [r2]
    adds r0, r6, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2245_0
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
    ldr r0, .Lraw_game_state_2244_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_2246_0
    ldr r5, [sp, #0xb4]
    str r0, [r5]
    mov r0, sp
    add r1, sp, #0x20
    add r2, sp, #0x8c
    cmp sp, r1
    beq .Lraw_game_state_2235_14
    ldr r2, [r2]
.Lraw_game_state_2235_6:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_2235_6
.Lraw_game_state_2235_14:
    ldr r3, [r3]
    adds r0, r4, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_2245_0
    bl _call_via_r4
.Lraw_game_state_2236_12:
    movs r0, #1
    ldr r6, [sp, #0xb8]
    strb r0, [r6]
.Lraw_game_state_2237_2:
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x90]
    adds r0, r1, r2
    lsls r0, r0, #2
    mov r3, sl
    adds r5, r3, r0
    adds r0, r5, #0
    adds r0, #0x60
    adds r1, r5, #0
    adds r1, #0x20
    adds r2, r5, #0
    adds r2, #0x40
    movs r3, #0x1f
    ldr r4, [sp, #0x94]
    ands r4, r3
    movs r3, #0x20
    rsbs r3, r3, #0
    ldr r6, [sp, #0x9c]
    ands r3, r6
    orrs r3, r4
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    ldr r4, .Lraw_game_state_2247_0
    ands r6, r4
    orrs r6, r3
    movs r3, #0x1f
    ldr r4, [sp, #0x98]
    ands r4, r3
    lsls r4, r4, #5
    ldr r3, .Lraw_game_state_2244_0
    ands r3, r6
    orrs r3, r4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, .Lraw_game_state_2247_4
    ands r6, r4
    orrs r6, r3
    str r6, [sp, #0x9c]
    adds r3, r6, #0
    ldr r4, .Lraw_game_state_2245_0
    bl _call_via_r4
    adds r1, r5, #0
    adds r1, #0x82
    movs r0, #1
    strb r0, [r1]
.Lraw_game_state_2242_14:
    add sp, #0xc0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lraw_game_state_2244_0: .word 0xFFFFFC1F
.Lraw_game_state_2244_4: .word 0x00006A32
.Lraw_game_state_2245_0: .word BlendRgb5PaletteBank
.Lraw_game_state_2246_0: .word 0x00002529
.Lraw_game_state_2247_0: .word 0xFFFFFF00
.Lraw_game_state_2247_4: .word 0xFFFF0000
    .section .text.game_scene_farm_plot_query_after, "ax", %progbits

    .global loc_0801BF2C
    .thumb_func
    loc_0801BF2C:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    adds r4, r0, #0
    adds r3, r1, #0
    adds r7, r2, #0
    movs r0, #0
    mov sb, r0
    ldrh r0, [r3]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    subs r0, #0x34
    ldr r1, .Lraw_game_state_2270_0
    cmp r0, r1
    bhi .Lraw_game_state_2282_0
    ldr r1, .Lraw_game_state_2270_4
    adds r0, r4, r1
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_2270_8
    adds r6, r0, r1
    ldrb r1, [r3, #1]
    lsrs r1, r1, #2
    ldrh r0, [r3, #2]
    ldr r2, .Lraw_game_state_2270_12
    ands r0, r2
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bge .Lraw_game_state_2266_0
    adds r0, #7
.Lraw_game_state_2266_0:
    asrs r5, r0, #3
    ldrb r1, [r3, #3]
    lsrs r1, r1, #2
    ldrh r0, [r3, #4]
    ands r0, r2
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bge .Lraw_game_state_2267_8
    adds r0, #7
.Lraw_game_state_2267_8:
    asrs r4, r0, #3
    adds r0, r6, #0
    bl GetLayoutKind__C14MineFloorState
    cmp r0, #4
    bhi .Lraw_game_state_2273_4
    lsls r0, r0, #2
    ldr r1, .Lraw_game_state_2271_0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Lraw_game_state_2270_0: .word 0x000001FF
.Lraw_game_state_2270_4: .word 0x00001038
.Lraw_game_state_2270_8: .word 0x00002E58
.Lraw_game_state_2270_12: .word 0x000003FF
.Lraw_game_state_2271_0: .word .Lswitch_0801BFB4
.Lswitch_0801BFB4: .word .Lraw_game_state_2273_4
    .word .Lraw_game_state_2272_8
    .word .Lraw_game_state_2273_4
    .word .Lraw_game_state_2272_14
    .word .Lraw_game_state_2273_4
.Lraw_game_state_2272_8:
    movs r1, #2
    mov r8, r1
    b .Lraw_game_state_2273_8
.Lraw_game_state_2272_14:
    movs r1, #2
    mov r8, r1
    b .Lraw_game_state_2273_8
.Lraw_game_state_2273_4:
    movs r0, #2
    mov r8, r0
.Lraw_game_state_2273_8:
    movs r3, #7
    cmp r5, #2
    blo .Lraw_game_state_2282_0
    cmp r4, r3
    blo .Lraw_game_state_2282_0
    adds r0, r6, #0
    str r3, [sp]
    bl GetWidth__C14MineFloorState
    lsls r0, r0, #1
    add r0, r8
    cmp r0, r5
    bls .Lraw_game_state_2282_0
    adds r0, r6, #0
    bl GetHeight__C14MineFloorState
    lsls r0, r0, #1
    ldr r3, [sp]
    adds r0, r3, r0
    cmp r0, r4
    bls .Lraw_game_state_2282_0
    mov r1, r8
    subs r2, r5, r1
    lsrs r2, r2, #1
    subs r1, r4, r3
    lsrs r1, r1, #1
    lsls r0, r2, #1
    add r0, r8
    strh r0, [r7]
    lsls r0, r1, #1
    adds r0, r3, r0
    strh r0, [r7, #2]
    strh r2, [r7, #4]
    strh r1, [r7, #6]
    movs r0, #1
    mov sb, r0
.Lraw_game_state_2282_0:
    mov r0, sb
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .section .text.game_scene_farm_plot_action_after, "ax", %progbits
    .align 2, 0

    .global func_0801C3DC
    .thumb_func
func_0801C3DC:
    bx lr
    .align 2, 0
    .global func_0801C3E0
    .thumb_func
func_0801C3E0:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0xc
    adds r7, r0, #0
    movs r2, #0
    mov sb, r2
    ldr r0, .Lraw_game_state_2380_2
    adds r0, r0, r7
    mov r8, r0
    ldr r0, .Lraw_game_state_2380_6
    adds r6, r7, r0
    .Lauto_0801C18E:
    ldrb r1, [r6]
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #2
    bne .Lauto_0801C1F6
    movs r2, #4
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    subs r2, #9
    adds r0, r2, #0
    ands r1, r0
    strb r1, [r6]
    movs r0, #0x40
    bl __builtin_new
    adds r4, r0, #0
    ldr r0, [r7]
    ldr r1, [r0, #0x68]
    adds r0, r7, #0
    bl _call_via_r1
    adds r1, r0, #0
    movs r0, #3
    str r0, [sp]
    movs r0, #0x1a
    str r0, [sp, #4]
    add r2, sp, #8
    movs r0, #0
    strb r0, [r2]
    adds r0, r4, #0
    ldr r2, .Lraw_game_state_2380_10
    adds r3, r7, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    mov r5, r8
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lauto_0801C1F2
    cmp r1, #0
    beq .Lauto_0801C1F2
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801C1F2:
    str r4, [r5]
    movs r2, #1
    .Lauto_0801C1F6:
    movs r0, #0xc
    add r8, r0
    adds r6, #0xc
    movs r0, #1
    add sb, r0
    mov r0, sb
    cmp r0, #3
    bls .Lauto_0801C18E
    cmp r2, #0
    beq .Lauto_0801C214
    ldr r0, [r7, #8]
    movs r1, #2
    movs r2, #0
    bl StartActorSpriteEffect
    .Lauto_0801C214:
    add sp, #0xc
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lraw_game_state_2380_2: .word 0x00001088
.Lraw_game_state_2380_6: .word 0x00001081
.Lraw_game_state_2380_10: .word 0x0000086F
    .global func_0801C49C
    .thumb_func
func_0801C49C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    adds r4, r0, #0
    mov sb, r1
    mov r8, r2
    movs r0, #0
    str r0, [r2]
    add r6, sp, #4
    adds r0, r4, #0
    adds r2, r6, #0
    bl loc_0801BF2C
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801C2D0
    ldr r0, .Lraw_game_state_2455_0
    adds r5, r4, r0
    ldr r0, [r5]
    ldr r1, .Lraw_game_state_2455_4
    adds r0, r0, r1
    adds r7, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    bl GetCellType__C14MineFloorStateUiUi
    movs r2, #0
    mov sl, r2
    cmp r0, #0
    bne .Lauto_0801C276
    movs r0, #1
    mov sl, r0
    .Lauto_0801C276:
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    ldr r3, [r5]
    adds r0, r7, #0
    bl DigSoil__14MineFloorStateUiUiR18GameStateSaveImage
    mov r1, r8
    str r0, [r1]
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    mov r2, sb
    ldrh r1, [r2]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    cmp r0, r1
    bne .Lauto_0801C2C4
    ldr r5, [r4, #4]
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellType__C14MineFloorStateUiUi
    adds r4, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellTilemap__C14MineFloorStateUiUi
    add r1, sp, #4
    ldrh r1, [r1]
    ldrh r2, [r6, #2]
    str r0, [sp]
    adds r0, r5, #0
    adds r3, r4, #0
    bl func_080A9F78
    .Lauto_0801C2C4:
    mov r0, sl
    b .Lauto_0801C2D2
.Lraw_game_state_2455_0: .word 0x00001038
.Lraw_game_state_2455_4: .word 0x00002E58
    .Lauto_0801C2D0:
    movs r0, #0
    .Lauto_0801C2D2:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
    .global CreateWorldEventIcon
    .thumb_func
CreateWorldEventIcon:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    mov sb, r0
    mov sl, r1
    adds r5, r2, #0
    adds r6, r3, #0
    ldr r7, [sp, #0x2c]
    ldr r0, [sp, #0x30]
    lsls r2, r0, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #8]
    ldr r0, .Lraw_game_state_2549_0
    ldr r4, [r0]
    ldr r0, .Lraw_game_state_2549_4
    adds r4, r4, r0
    lsls r0, r1, #1
    add r0, sl
    lsls r0, r0, #2
    adds r4, r4, r0
    ldrb r1, [r4]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r4]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    ldr r1, .Lraw_game_state_2549_8
    mov r8, r1
    mov r1, r8
    ands r0, r1
    ldrh r3, [r4, #2]
    ldr r2, .Lraw_game_state_2549_12
    adds r1, r2, #0
    ands r1, r3
    orrs r1, r0
    strh r1, [r4, #2]
    lsls r5, r5, #0x10
    lsrs r1, r5, #0x10
    movs r0, #0x3f
    ands r1, r0
    lsls r1, r1, #2
    ldrb r3, [r4, #3]
    movs r0, #3
    mov ip, r0
    movs r0, #3
    ands r0, r3
    orrs r0, r1
    strb r0, [r4, #3]
    lsrs r5, r5, #0x16
    mov r1, r8
    ands r5, r1
    ldrh r0, [r4, #4]
    ands r2, r0
    orrs r2, r5
    strh r2, [r4, #4]
    lsls r6, r6, #0x10
    lsrs r6, r6, #6
    ldr r0, [r4, #4]
    ldr r1, .Lraw_game_state_2550_0
    ands r0, r1
    orrs r0, r6
    str r0, [r4, #4]
    mov r0, ip
    ands r7, r0
    lsls r2, r7, #2
    ldrb r1, [r4]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4]
    mov r1, sp
    ldrh r1, [r1, #8]
    strh r1, [r4, #8]
    ldr r0, .Lraw_game_state_2550_4
    add r0, sb
    mov r8, r0
    mov r1, sl
    lsls r1, r1, #2
    mov sl, r1
    add r8, sl
    movs r0, #0x4c
    bl __builtin_new
    adds r5, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x64]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    adds r0, r5, #0
    mov r1, sb
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .Lraw_game_state_2551_0
    str r0, [r5, #0x24]
    movs r0, #0x28
    adds r0, r0, r5
    mov sb, r0
    ldr r6, [r4]
    mov r0, sp
    ldr r3, [r6, #0xc]
    adds r1, r4, #0
    ldr r2, [sp, #8]
    bl _call_via_r3
    ldr r0, [sp]
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r6, #0x10]
    adds r1, r4, #0
    bl _call_via_r3
    adds r1, r5, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    mov r4, r8
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_2547_14
    cmp r1, #0
    beq .Lraw_game_state_2547_14
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_2547_14:
    str r5, [r4]
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Lraw_game_state_2549_0: .word gUnk_0300040C
.Lraw_game_state_2549_4: .word 0x000004DC
.Lraw_game_state_2549_8: .word 0x000003FF
.Lraw_game_state_2549_12: .word 0xFFFFFC00
.Lraw_game_state_2550_0: .word 0xFC0003FF
.Lraw_game_state_2550_4: .word 0x000010B0
.Lraw_game_state_2551_0: .4byte __vt_20GameSceneGroupSprite
    .global RemoveWorldEventIcon
    .thumb_func
RemoveWorldEventIcon:
    push {r4, r5, lr}
    ldr r2, .Lraw_game_state_2589_0
    ldr r3, [r2]
    ldr r2, .Lraw_game_state_2589_4
    adds r3, r3, r2
    lsls r2, r1, #1
    adds r2, r2, r1
    lsls r2, r2, #2
    adds r3, r3, r2
    ldrb r4, [r3]
    movs r2, #4
    rsbs r2, r2, #0
    ands r2, r4
    strb r2, [r3]
    ldr r2, .Lraw_game_state_2589_8
    adds r0, r0, r2
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lauto_0801C46C
    cmp r1, #0
    beq .Lauto_0801C46C
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801C46C:
    str r5, [r4]
    pop {r4, r5}
    pop {r0}
    bx r0
.Lraw_game_state_2589_0: .word gUnk_0300040C
.Lraw_game_state_2589_4: .word 0x000004DC
.Lraw_game_state_2589_8: .word 0x000010B0
    .global loc_0801C480
    .thumb_func
    loc_0801C480:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    adds r7, r0, #0
    mov r8, r1
    mov sb, r2
    str r3, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    ldr r0, [r7]
    ldr r1, [r0, #0x14]
    adds r0, r7, #0
    bl _call_via_r1
    cmp r0, #2
    beq .Lauto_0801C4A8
    b .Lauto_0801C5F6
    .Lauto_0801C4A8:
    mov r1, r8
    lsls r0, r1, #1
    adds r0, #0x22
    str r0, [sp, #0xc]
    mov r2, sb
    lsls r0, r2, #1
    adds r0, #0x16
    mov sl, r0
    movs r2, #0
    ldr r3, .Lraw_game_state_2647_8
    adds r5, r7, r3
    ldr r0, .Lraw_game_state_2647_12
    adds r4, r7, r0
    .Lauto_0801C4C2:
    ldrb r1, [r5]
    lsls r0, r1, #0x1e
    lsrs r6, r0, #0x1e
    cmp r6, #1
    bne .Lauto_0801C548
    ldr r3, [sp, #0xc]
    ldrh r0, [r4]
    cmp r3, r0
    bne .Lauto_0801C548
    ldrh r3, [r4, #2]
    cmp sl, r3
    bne .Lauto_0801C548
    lsls r0, r1, #0x1c
    lsrs r0, r0, #0x1e
    cmp r0, #2
    bne .Lraw_game_state_2638_12
    b .Lauto_0801C5F6
.Lraw_game_state_2638_12:
    ldr r1, .Lraw_game_state_2648_0
    adds r0, r7, r1
    ldr r0, [r0]
    movs r1, #0
    movs r2, #0xc0
    bl PlaySong__9GameSceneiUi
    ldrb r1, [r5]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r1, r0
    movs r0, #8
    orrs r1, r0
    strb r1, [r5]
    ldr r4, [r4, #4]
    adds r0, r4, #0
    adds r0, #0x28
    ldr r1, .Lraw_game_state_2648_4
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x3c
    movs r1, #0
    strb r6, [r0]
    adds r0, #2
    strb r1, [r0]
    adds r0, #1
    strb r6, [r0]
    ldr r3, .Lraw_game_state_2648_8
    adds r0, r7, r3
    ldr r0, [r0]
    ldr r5, .Lraw_game_state_2648_12
    adds r0, r0, r5
    bl func_0800EEF8
    b .Lauto_0801C5F6
    .align 2, 0
.Lraw_game_state_2647_8: .word 0x00001081
.Lraw_game_state_2647_12: .word 0x00001084
.Lraw_game_state_2648_0: .word 0x00001054
.Lraw_game_state_2648_4: .word 0x00000873
.Lraw_game_state_2648_8: .word 0x00001038
.Lraw_game_state_2648_12: .word 0x00001BD8
    .Lauto_0801C548:
    adds r5, #0xc
    adds r4, #0xc
    adds r2, #1
    cmp r2, #3
    bls .Lauto_0801C4C2
    movs r0, #0
    cmp r0, #0
    bne .Lauto_0801C5F6
    ldr r0, .Lraw_game_state_2700_0
    adds r6, r7, r0
    ldr r1, [r6]
    ldr r5, .Lraw_game_state_2700_4
    adds r1, r1, r5
    movs r0, #0x2b
    mov r4, sb
    muls r4, r0, r4
    add r4, r8
    lsls r4, r4, #2
    adds r1, r1, r4
    str r1, [sp, #0x10]
    adds r0, r1, #0
    ldr r1, [sp, #4]
    bl method_0800A238__9FieldPloti
    str r0, [sp, #8]
    ldr r7, [r7, #4]
    ldr r0, [r6]
    adds r3, r0, r5
    adds r4, r3, r4
    mov r1, sb
    adds r1, #1
    movs r0, #0
    mov r2, r8
    cmp r2, #0
    blt .Lauto_0801C59C
    cmp r1, #0
    blt .Lauto_0801C59C
    cmp r2, #0x2a
    bgt .Lauto_0801C59C
    cmp r1, #0x18
    bgt .Lauto_0801C59C
    movs r0, #1
    .Lauto_0801C59C:
    cmp r0, #0
    beq .Lauto_0801C5B4
    movs r0, #0x2b
    muls r0, r1, r0
    add r0, r8
    lsls r0, r0, #2
    adds r1, r3, r0
    b .Lauto_0801C5B6
.Lraw_game_state_2700_0: .word 0x00001038
.Lraw_game_state_2700_4: .word 0x000009DC
    .Lauto_0801C5B4:
    movs r1, #0
    .Lauto_0801C5B6:
    mov r2, sb
    subs r2, #1
    movs r0, #0
    mov r5, r8
    cmp r5, #0
    blt .Lauto_0801C5D0
    cmp r2, #0
    blt .Lauto_0801C5D0
    cmp r5, #0x2a
    bgt .Lauto_0801C5D0
    cmp r2, #0x18
    bgt .Lauto_0801C5D0
    movs r0, #1
    .Lauto_0801C5D0:
    cmp r0, #0
    beq .Lauto_0801C5E0
    movs r0, #0x2b
    muls r0, r2, r0
    add r0, r8
    lsls r0, r0, #2
    adds r2, r3, r0
    b .Lauto_0801C5E2
    .Lauto_0801C5E0:
    movs r2, #0
    .Lauto_0801C5E2:
    adds r0, r4, #0
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    adds r0, r7, #0
    ldr r1, [sp, #0xc]
    mov r2, sl
    ldr r3, [sp, #0x10]
    bl RefreshFieldPlotTiles
    .Lauto_0801C5F6:
    ldr r0, [sp, #8]
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .global loc_0801C608
    .thumb_func
    loc_0801C608:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r7, r0, #0
    mov sl, r3
    ldr r3, .Lraw_game_state_2785_2
    adds r0, r7, r3
    ldr r3, [r0]
    ldr r0, .Lraw_game_state_2785_6
    adds r3, r3, r0
    movs r0, #0x2b
    muls r0, r2, r0
    adds r0, r1, r0
    lsls r0, r0, #2
    adds r4, r3, r0
    adds r6, r1, #0
    mov r8, r2
    adds r0, r4, #0
    bl method_0800A78C__C9FieldPlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801C6AA
    adds r0, r4, #0
    bl func_0801740C
    cmp r0, #1
    beq .Lauto_0801C65C
    cmp r0, #1
    ble .Lauto_0801C670
    cmp r0, #2
    beq .Lauto_0801C660
    cmp r0, #3
    beq .Lauto_0801C668
    b .Lauto_0801C670
    .align 2, 0
.Lraw_game_state_2785_2: .word 0x00001038
.Lraw_game_state_2785_6: .word 0x000009DC
    .Lauto_0801C65C:
    subs r6, #1
    b .Lauto_0801C670
    .Lauto_0801C660:
    movs r1, #1
    rsbs r1, r1, #0
    add r8, r1
    b .Lauto_0801C670
    .Lauto_0801C668:
    subs r6, #1
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
    .Lauto_0801C670:
    adds r0, r7, #0
    adds r1, r6, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801C480
    mov sb, r0
    adds r5, r6, #1
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801C480
    mov r4, r8
    adds r4, #1
    adds r0, r7, #0
    adds r1, r6, #0
    adds r2, r4, #0
    mov r3, sl
    bl loc_0801C480
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    mov r3, sl
    bl loc_0801C480
    b .Lauto_0801C6B8
    .Lauto_0801C6AA:
    adds r0, r7, #0
    adds r1, r6, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801C480
    mov sb, r0
    .Lauto_0801C6B8:
    ldr r0, [r7]
    ldr r1, [r0, #0x14]
    adds r0, r7, #0
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_0801C79A
    mov r3, sb
    cmp r3, #8
    bhi .Lauto_0801C79A
    lsls r0, r3, #2
    ldr r1, .Lraw_game_state_2847_2
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Lraw_game_state_2847_2: .word .Lauto_0801C6DC
    .Lauto_0801C6DC:
    .word .Lauto_0801C79A
    .word .Lauto_0801C79A
    .word .Lauto_0801C79A
    .word .Lauto_0801C700
    .word .Lauto_0801C720
    .word .Lauto_0801C740
    .word .Lauto_0801C79A
    .word .Lauto_0801C760
    .word .Lauto_0801C780
    .Lauto_0801C700:
    ldr r1, .Lraw_game_state_2854_12
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #3
    bl func_080AB0C4
    b .Lauto_0801C79A
.Lraw_game_state_2854_12: .word 0x00001028
    .Lauto_0801C720:
    ldr r1, .Lraw_game_state_2857_12
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #1
    bl func_080AB0C4
    b .Lauto_0801C79A
.Lraw_game_state_2857_12: .word 0x00001028
    .Lauto_0801C740:
    ldr r1, .Lraw_game_state_2860_12
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #2
    bl func_080AB0C4
    b .Lauto_0801C79A
.Lraw_game_state_2860_12: .word 0x00001028
    .Lauto_0801C760:
    ldr r1, .Lraw_game_state_2863_12
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x90
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #8
    bl func_080AB0C4
    b .Lauto_0801C79A
.Lraw_game_state_2863_12: .word 0x00001028
    .Lauto_0801C780:
    ldr r1, .Lraw_game_state_2876_2
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x90
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #6
    bl func_080AB0C4
    .Lauto_0801C79A:
    movs r0, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_2876_2: .word 0x00001028
    .global func_0801CA1C
    .thumb_func
func_0801CA1C:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x24
    adds r5, r0, #0
    adds r6, r1, #0
    adds r7, r2, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    adds r0, r5, #0
    adds r1, r6, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    beq loc_0801C7F4
    add r0, sp, #4
    ldrh r1, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldr r0, .Lraw_game_state_2910_0
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl loc_0801C608
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b loc_0801C85E
.Lraw_game_state_2910_0: .4byte gUnk_080F0800
    .global loc_0801C7F4
    .thumb_func
    loc_0801C7F4:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, .Lraw_game_state_2937_0
    adds r0, r7, r0
    ldrb r2, [r0]
    str r4, [sp]
    adds r0, r5, #0
    adds r1, r6, #0
    movs r3, #1
    bl loc_0801CE98
    ldrb r0, [r4]
    cmp r0, #0
    beq loc_0801C858
    ldr r0, [r4, #4]
    cmp r0, #6
    beq loc_0801C828
    cmp r0, #9
    beq loc_0801C844
    movs r0, #0
    b loc_0801C85E
.Lraw_game_state_2937_0: .4byte gUnk_080F0800
    .global loc_0801C828
    .thumb_func
    loc_0801C828:
    ldr r1, .Lraw_game_state_2951_2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #6
    bl func_080AB0C4
    b .Lauto_0801C858
    .align 2, 0
.Lraw_game_state_2951_2: .word 0x00001028
    .global loc_0801C844
    .thumb_func
    loc_0801C844:
    ldr r1, .Lraw_game_state_2978_2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x18
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #9
    bl func_080AB0C4
    .global loc_0801C858
    .thumb_func
    loc_0801C858:
    .Lauto_0801C858:
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    .global loc_0801C85E
    .thumb_func
    loc_0801C85E:
    add sp, #0x24
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_2978_2: .word 0x00001028
    .global func_0801CAD8
    .thumb_func
func_0801CAD8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    mov r8, r0
    mov sb, r1
    adds r5, r2, #0
    movs r0, #0
    str r0, [r5]
    add r6, sp, #4
    mov r0, r8
    adds r2, r6, #0
    bl loc_0801BF2C
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801C930
    ldr r4, .Lraw_game_state_3035_8
    add r4, r8
    ldr r0, [r4]
    ldr r1, .Lraw_game_state_3035_12
    adds r0, r0, r1
    adds r7, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    bl GetCellType__C14MineFloorStateUiUi
    movs r1, #0
    cmp r0, #4
    bne .Lauto_0801C8AE
    movs r1, #1
    .Lauto_0801C8AE:
    mov sl, r1
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    ldr r3, [r4]
    adds r0, r7, #0
    bl BreakRock__14MineFloorStateUiUiR18GameStateSaveImage
    str r0, [r5]
    mov r2, r8
    ldr r0, [r2]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    mov r2, sb
    ldrh r1, [r2]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    cmp r0, r1
    bne .Lraw_game_state_3035_4
    mov r0, r8
    ldr r5, [r0, #4]
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellType__C14MineFloorStateUiUi
    adds r4, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellTilemap__C14MineFloorStateUiUi
    add r1, sp, #4
    ldrh r1, [r1]
    ldrh r2, [r6, #2]
    str r0, [sp]
    adds r0, r5, #0
    adds r3, r4, #0
    bl func_080A9F78
    mov r1, sl
    cmp r1, #0
    beq .Lraw_game_state_3035_4
    ldr r0, .Lraw_game_state_3036_0
    add r0, r8
    ldr r0, [r0]
    add r1, sp, #4
    ldrh r1, [r1]
    lsls r1, r1, #3
    adds r1, #8
    ldrh r2, [r6, #2]
    lsls r2, r2, #3
    adds r2, #0x10
    movs r3, #5
    bl func_080AB0C4
.Lraw_game_state_3035_4:
    mov r0, sl
    b .Lraw_game_state_3039_0
.Lraw_game_state_3035_8: .word 0x00001038
.Lraw_game_state_3035_12: .word 0x00002E58
.Lraw_game_state_3036_0: .word 0x00001028
    .Lauto_0801C930:
    movs r0, #0
.Lraw_game_state_3039_0:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
    .global func_0801CBB0
    .thumb_func
func_0801CBB0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov sb, r0
    str r1, [sp, #0x38]
    mov sl, r2
    movs r6, #0
    cmp r1, #2
    bne loc_0801C9B4
    movs r1, #0
    ldr r0, .Lraw_game_state_3104_0
    add r0, sl
    mov r8, r0
    .Lauto_0801C964:
    movs r5, #0
    adds r7, r1, #1
    movs r0, #0xac
    adds r4, r1, #0
    muls r4, r0, r4
    .Lauto_0801C96E:
    ldr r0, .Lraw_game_state_3105_0
    add r0, sb
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_3105_4
    adds r0, r0, r1
    adds r0, r0, r4
    mov r2, r8
    ldrb r1, [r2]
    bl method_0800A238__9FieldPloti
    movs r2, #0
    adds r1, r6, #0
    cmp r0, #0
    beq .Lauto_0801C98E
    movs r1, #1
    orrs r1, r6
    .Lauto_0801C98E:
    cmp r1, #0
    beq .Lauto_0801C994
    movs r2, #1
    .Lauto_0801C994:
    adds r6, r2, #0
    adds r4, #4
    adds r5, #1
    cmp r5, #0x2a
    bls .Lauto_0801C96E
    adds r1, r7, #0
    cmp r1, #0x18
    bls .Lauto_0801C964
    b loc_0801CA32
    .align 2, 0
.Lraw_game_state_3104_0: .4byte gUnk_080F0800
.Lraw_game_state_3105_0: .word 0x00001038
.Lraw_game_state_3105_4: .word 0x000009DC
    .global loc_0801C9B4
    .thumb_func
    loc_0801C9B4:
    ldr r4, .Lraw_game_state_3199_2
    add r4, sb
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r3, .Lraw_game_state_3199_6
    adds r7, r0, r3
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, .Lraw_game_state_3200_0
    add sl, r0
    .Lauto_0801C9D0:
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    bl IsAvailable__C14FieldItemStateUii
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801CA2C
    add r0, sp, #0xc
    adds r1, r7, #0
    adds r2, r5, #0
    bl GetRecord__C14FieldItemStateUi
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0x38]
    cmp r0, r1
    bne .Lauto_0801CA2C
    movs r0, #0
    strb r0, [r4]
    movs r2, #1
    strb r2, [r4, #0x10]
    ldr r0, .Lraw_game_state_3199_2
    add r0, sb
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, .Lraw_game_state_3199_6
    adds r1, r1, r3
    mov r3, sl
    ldrb r2, [r3]
    str r2, [sp]
    add r2, sp, #4
    movs r3, #1
    strb r3, [r2]
    str r4, [sp, #8]
    adds r2, r5, #0
    mov r3, r8
    bl func_080174C8
    rsbs r0, r6, #0
    orrs r0, r6
    lsrs r6, r0, #0x1f
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    orrs r6, r0
    .Lauto_0801CA2C:
    adds r5, #1
    cmp r5, #0x73
    bls .Lauto_0801C9D0
    .global loc_0801CA32
    .thumb_func
    loc_0801CA32:
    cmp r6, #0
    beq .Lauto_0801CA54
    mov r2, sb
    ldr r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #1
    adds r0, r0, r3
    add r1, sp, #0x30
    ldr r2, .Lraw_game_state_3201_0
    movs r3, #0
    str r2, [sp, #0x30]
    str r3, [r1, #4]
    ldr r3, [r0]
    mov r0, sb
    movs r2, #0
    bl _call_via_r3
    .Lauto_0801CA54:
    adds r0, r6, #0
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_3199_2: .word 0x00001038
.Lraw_game_state_3199_6: .word 0x000034C8
.Lraw_game_state_3200_0: .4byte gUnk_080F0800
.Lraw_game_state_3201_0: .word 0x000003DD
    .global loc_0801CA78
    .thumb_func
    loc_0801CA78:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    mov r8, r2
    adds r1, r3, #0
    ldr r0, .Lraw_game_state_3264_0
    adds r7, r4, r0
    ldr r2, [r7]
    ldr r3, .Lraw_game_state_3264_4
    adds r2, r2, r3
    movs r0, #0x2b
    mov r3, r8
    muls r3, r0, r3
    adds r0, r3, #0
    adds r0, r5, r0
    lsls r6, r0, #2
    adds r2, r2, r6
    mov sb, r2
    mov r0, sb
    bl method_0800A33C__9FieldPloti
    str r0, [sp, #4]
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_0801CB3E
    ldr r4, [r4, #4]
    mov sl, r4
    ldr r0, [r7]
    ldr r1, .Lraw_game_state_3264_4
    adds r2, r0, r1
    adds r4, r2, r6
    mov r1, r8
    adds r1, #1
    movs r0, #0
    cmp r5, #0
    blt .Lauto_0801CAE0
    cmp r1, #0
    blt .Lauto_0801CAE0
    cmp r5, #0x2a
    bgt .Lauto_0801CAE0
    cmp r1, #0x18
    bgt .Lauto_0801CAE0
    movs r0, #1
    .Lauto_0801CAE0:
    cmp r0, #0
    beq .Lauto_0801CAF8
    movs r0, #0x2b
    muls r0, r1, r0
    adds r0, r5, r0
    lsls r0, r0, #2
    adds r1, r2, r0
    b .Lauto_0801CAFA
.Lraw_game_state_3264_0: .word 0x00001038
.Lraw_game_state_3264_4: .word 0x000009DC
    .Lauto_0801CAF8:
    movs r1, #0
    .Lauto_0801CAFA:
    mov r3, r8
    subs r3, #1
    movs r0, #0
    cmp r5, #0
    blt .Lauto_0801CB12
    cmp r3, #0
    blt .Lauto_0801CB12
    cmp r5, #0x2a
    bgt .Lauto_0801CB12
    cmp r3, #0x18
    bgt .Lauto_0801CB12
    movs r0, #1
    .Lauto_0801CB12:
    cmp r0, #0
    beq .Lauto_0801CB22
    movs r0, #0x2b
    muls r0, r3, r0
    adds r0, r5, r0
    lsls r0, r0, #2
    adds r2, r2, r0
    b .Lauto_0801CB24
    .Lauto_0801CB22:
    movs r2, #0
    .Lauto_0801CB24:
    adds r0, r4, #0
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    lsls r1, r5, #1
    adds r1, #0x22
    mov r3, r8
    lsls r2, r3, #1
    adds r2, #0x16
    str r0, [sp]
    mov r0, sl
    mov r3, sb
    bl RefreshFieldPlotTiles
    .Lauto_0801CB3E:
    ldr r0, [sp, #4]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .global loc_0801CB50
    .thumb_func
    loc_0801CB50:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r0, #0
    mov sl, r3
    ldr r3, .Lraw_game_state_3351_2
    adds r0, r6, r3
    ldr r3, [r0]
    ldr r0, .Lraw_game_state_3351_6
    adds r3, r3, r0
    movs r0, #0x2b
    muls r0, r2, r0
    adds r0, r1, r0
    lsls r0, r0, #2
    adds r4, r3, r0
    adds r7, r1, #0
    mov r8, r2
    adds r0, r4, #0
    bl method_0800A78C__C9FieldPlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801CBF2
    adds r0, r4, #0
    bl func_0801740C
    cmp r0, #1
    beq .Lauto_0801CBA4
    cmp r0, #1
    ble .Lauto_0801CBB8
    cmp r0, #2
    beq .Lauto_0801CBA8
    cmp r0, #3
    beq .Lauto_0801CBB0
    b .Lauto_0801CBB8
    .align 2, 0
.Lraw_game_state_3351_2: .word 0x00001038
.Lraw_game_state_3351_6: .word 0x000009DC
    .Lauto_0801CBA4:
    subs r7, #1
    b .Lauto_0801CBB8
    .Lauto_0801CBA8:
    movs r1, #1
    rsbs r1, r1, #0
    add r8, r1
    b .Lauto_0801CBB8
    .Lauto_0801CBB0:
    subs r7, #1
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
    .Lauto_0801CBB8:
    adds r0, r6, #0
    adds r1, r7, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801CA78
    mov sb, r0
    adds r5, r7, #1
    adds r0, r6, #0
    adds r1, r5, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801CA78
    mov r4, r8
    adds r4, #1
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    mov r3, sl
    bl loc_0801CA78
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    mov r3, sl
    bl loc_0801CA78
    b .Lauto_0801CC00
    .Lauto_0801CBF2:
    adds r0, r6, #0
    adds r1, r7, #0
    mov r2, r8
    mov r3, sl
    bl loc_0801CA78
    mov sb, r0
    .Lauto_0801CC00:
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_0801CC78
    mov r3, sb
    cmp r3, #1
    beq .Lauto_0801CC1E
    cmp r3, #1
    ble .Lauto_0801CC78
    cmp r3, #2
    beq .Lauto_0801CC50
    b .Lauto_0801CC78
    .Lauto_0801CC1E:
    ldr r1, .Lraw_game_state_3433_0
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #1
    bl method_08009B68__4FarmUi
    ldr r2, .Lraw_game_state_3433_4
    adds r0, r6, r2
    ldr r0, [r0]
    lsls r1, r7, #4
    movs r3, #0x8c
    lsls r3, r3, #1
    adds r1, r1, r3
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xbb
    movs r3, #4
    bl func_080AB0C4
    b .Lauto_0801CC78
.Lraw_game_state_3433_0: .word 0x00001038
.Lraw_game_state_3433_4: .word 0x00001028
    .Lauto_0801CC50:
    ldr r1, .Lraw_game_state_3462_0
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #6
    bl method_08009B68__4FarmUi
    ldr r2, .Lraw_game_state_3462_4
    adds r0, r6, r2
    ldr r0, [r0]
    lsls r1, r7, #4
    movs r3, #0x90
    lsls r3, r3, #1
    adds r1, r1, r3
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #7
    bl func_080AB0C4
    .Lauto_0801CC78:
    movs r0, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Lraw_game_state_3462_0: .word 0x00001038
.Lraw_game_state_3462_4: .word 0x00001028
    .global func_0801CEFC
    .thumb_func
func_0801CEFC:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x24
    adds r5, r0, #0
    adds r6, r1, #0
    adds r7, r2, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    adds r0, r5, #0
    adds r1, r6, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    beq loc_0801CCD4
    add r0, sp, #4
    ldrh r1, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldr r0, .Lraw_game_state_3496_0
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl loc_0801CB50
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b loc_0801CD3E
.Lraw_game_state_3496_0: .4byte gUnk_080F0800 + 7
    .global loc_0801CCD4
    .thumb_func
    loc_0801CCD4:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, .Lraw_game_state_3523_0
    adds r0, r7, r0
    ldrb r2, [r0]
    str r4, [sp]
    adds r0, r5, #0
    adds r1, r6, #0
    movs r3, #0
    bl loc_0801CE98
    ldrb r0, [r4]
    cmp r0, #0
    beq loc_0801CD38
    ldr r0, [r4, #4]
    cmp r0, #4
    beq loc_0801CD24
    cmp r0, #7
    beq loc_0801CD08
    movs r0, #0
    b loc_0801CD3E
.Lraw_game_state_3523_0: .4byte gUnk_080F0800 + 7
    .global loc_0801CD08
    .thumb_func
    loc_0801CD08:
    ldr r1, .Lraw_game_state_3537_2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #7
    bl func_080AB0C4
    b .Lauto_0801CD38
    .align 2, 0
.Lraw_game_state_3537_2: .word 0x00001028
    .global loc_0801CD24
    .thumb_func
    loc_0801CD24:
    ldr r1, .Lraw_game_state_3564_2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #8
    ldr r2, [r4, #0xc]
    adds r2, #0xb
    movs r3, #4
    bl func_080AB0C4
    .global loc_0801CD38
    .thumb_func
    loc_0801CD38:
    .Lauto_0801CD38:
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    .global loc_0801CD3E
    .thumb_func
    loc_0801CD3E:
    add sp, #0x24
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_3564_2: .word 0x00001028
    .global func_0801CFB8
    .thumb_func
func_0801CFB8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r0, [sp, #0x38]
    mov sb, r1
    mov sl, r2
    movs r6, #0
    cmp r1, #2
    bne loc_0801CDD4
    movs r1, #0
    ldr r2, .Lraw_game_state_3632_2
    adds r7, r0, r2
    ldr r0, .Lraw_game_state_3633_0
    add sl, r0
    .Lauto_0801CD6E:
    movs r5, #0
    adds r3, r1, #1
    mov sb, r3
    movs r2, #0x2b
    adds r0, r1, #0
    muls r0, r2, r0
    mov r8, r0
    .Lauto_0801CD7C:
    ldr r0, [r7]
    ldr r3, .Lraw_game_state_3634_0
    adds r0, r0, r3
    mov r2, r8
    adds r1, r5, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov r3, sl
    ldrb r1, [r3]
    bl method_0800A33C__9FieldPloti
    adds r4, r0, #0
    subs r0, r4, #1
    cmp r0, #1
    bhi .Lauto_0801CDA4
    ldr r0, [r7]
    adds r0, #0x14
    movs r1, #1
    bl method_08009B68__4FarmUi
    .Lauto_0801CDA4:
    movs r1, #0
    adds r0, r6, #0
    cmp r4, #0
    beq .Lauto_0801CDB0
    movs r0, #1
    orrs r0, r6
    .Lauto_0801CDB0:
    cmp r0, #0
    beq .Lauto_0801CDB6
    movs r1, #1
    .Lauto_0801CDB6:
    adds r6, r1, #0
    adds r5, #1
    cmp r5, #0x2a
    bls .Lauto_0801CD7C
    mov r1, sb
    cmp r1, #0x18
    bls .Lauto_0801CD6E
    b loc_0801CE54
    .align 2, 0
.Lraw_game_state_3632_2: .word 0x00001038
.Lraw_game_state_3633_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_3634_0: .word 0x000009DC
    .global loc_0801CDD4
    .thumb_func
    loc_0801CDD4:
    ldr r0, [sp, #0x38]
    ldr r1, .Lraw_game_state_3729_0
    adds r4, r0, r1
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r2, .Lraw_game_state_3729_4
    adds r7, r0, r2
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, .Lraw_game_state_3730_0
    add sl, r0
    .Lauto_0801CDF2:
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    bl IsAvailable__C14FieldItemStateUii
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801CE4E
    add r0, sp, #0xc
    adds r1, r7, #0
    adds r2, r5, #0
    bl GetRecord__C14FieldItemStateUi
    ldr r0, [sp, #0x10]
    cmp r0, sb
    bne .Lauto_0801CE4E
    movs r3, #0
    strb r3, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r1, [sp, #0x38]
    ldr r2, .Lraw_game_state_3729_0
    adds r0, r1, r2
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, .Lraw_game_state_3729_4
    adds r1, r1, r3
    mov r3, sl
    ldrb r2, [r3]
    str r2, [sp]
    add r2, sp, #4
    movs r3, #0
    strb r3, [r2]
    str r4, [sp, #8]
    adds r2, r5, #0
    mov r3, r8
    bl func_080174C8
    rsbs r0, r6, #0
    orrs r0, r6
    lsrs r6, r0, #0x1f
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    orrs r6, r0
    .Lauto_0801CE4E:
    adds r5, #1
    cmp r5, #0x73
    bls .Lauto_0801CDF2
    .global loc_0801CE54
    .thumb_func
    loc_0801CE54:
    cmp r6, #0
    beq .Lauto_0801CE76
    ldr r2, [sp, #0x38]
    ldr r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #1
    adds r0, r0, r3
    add r1, sp, #0x30
    ldr r2, .Lraw_game_state_3731_0
    movs r3, #0
    str r2, [sp, #0x30]
    str r3, [r1, #4]
    ldr r3, [r0]
    ldr r0, [sp, #0x38]
    movs r2, #0
    bl _call_via_r3
    .Lauto_0801CE76:
    adds r0, r6, #0
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Lraw_game_state_3729_0: .word 0x00001038
.Lraw_game_state_3729_4: .word 0x000034C8
.Lraw_game_state_3730_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_3731_0: .word 0x000003CF
    .global loc_0801CE98
    .thumb_func
    loc_0801CE98:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    mov sl, r0
    adds r5, r1, #0
    str r2, [sp, #0x28]
    ldr r0, [sp, #0x50]
    mov sb, r0
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x2c]
    ldr r7, .Lraw_game_state_3760_0
    add r7, sl
    ldr r0, [r7]
    ldr r1, .Lraw_game_state_3760_4
    adds r6, r0, r1
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldrb r0, [r5, #1]
    lsrs r0, r0, #2
    ldrh r1, [r5, #2]
    ldr r3, .Lraw_game_state_3760_8
    ands r1, r3
    lsls r1, r1, #6
    orrs r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldrb r2, [r5, #3]
    lsrs r2, r2, #2
    ldrh r0, [r5, #4]
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    add r2, sp, #0x1c
    strh r1, [r2]
    strh r0, [r2, #2]
    adds r1, #1
    strh r1, [r2, #4]
    adds r0, #1
    strh r0, [r2, #6]
    ldrh r1, [r5]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    adds r0, r6, #0
    mov r3, r8
    bl Find__C14FieldItemStateUiRC3Boxi
    adds r4, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    cmp r4, r0
    beq .Lraw_game_state_3766_4
    add r0, sp, #0xc
    adds r1, r6, #0
    adds r2, r4, #0
    bl GetRecord__C14FieldItemStateUi
    add r6, sp, #0xc
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r2, .Lraw_game_state_3760_4
    adds r1, r1, r2
    ldr r3, [sp, #0x28]
    str r3, [sp]
    add r2, sp, #4
    add r7, sp, #0x2c
    ldrb r7, [r7]
    strb r7, [r2]
    mov r2, sb
    str r2, [sp, #8]
    adds r2, r4, #0
    mov r3, r8
    bl func_080174C8
    mov r3, sb
    ldrb r0, [r3]
    cmp r0, #0
    beq .Lraw_game_state_3766_0
    ldrh r0, [r5]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    mov r7, sl
    ldr r1, [r7, #4]
    ldr r2, [r1]
    adds r5, r1, #0
    cmp r0, r2
    bne .Lraw_game_state_3766_0
    ldr r0, [r3, #4]
    cmp r0, #6
    beq .Lraw_game_state_3762_0
    cmp r0, #6
    bgt .Lraw_game_state_3760_12
    cmp r0, #4
    beq .Lraw_game_state_3761_6
    b .Lraw_game_state_3766_4
    .align 2, 0
.Lraw_game_state_3760_0: .word 0x00001038
.Lraw_game_state_3760_4: .word 0x000034C8
.Lraw_game_state_3760_8: .word 0x000003FF
.Lraw_game_state_3760_12:
    cmp r0, #7
    beq .Lraw_game_state_3761_12
    cmp r0, #9
    beq .Lraw_game_state_3762_4
    b .Lraw_game_state_3766_4
.Lraw_game_state_3761_6:
    movs r3, #2
    movs r4, #2
    b .Lraw_game_state_3762_8
.Lraw_game_state_3761_12:
    movs r3, #4
    b .Lraw_game_state_3762_6
.Lraw_game_state_3762_0:
    movs r3, #4
    b .Lraw_game_state_3762_6
.Lraw_game_state_3762_4:
    movs r3, #6
.Lraw_game_state_3762_6:
    movs r4, #4
.Lraw_game_state_3762_8:
    movs r1, #8
    ldrsh r0, [r6, r1]
    cmp r0, #0
    bge .Lraw_game_state_3763_2
    adds r0, #7
.Lraw_game_state_3763_2:
    asrs r1, r0, #3
    movs r2, #0xa
    ldrsh r0, [r6, r2]
    cmp r0, #0
    bge .Lraw_game_state_3763_14
    adds r0, #7
.Lraw_game_state_3763_14:
    asrs r0, r0, #3
    add r2, sp, #0x24
    strh r1, [r2]
    strh r0, [r2, #2]
    str r4, [sp]
    adds r0, r5, #0
    movs r1, #1
    bl ClearWorldMapTileRectangle
.Lraw_game_state_3766_0:
    movs r0, #1
    b .Lraw_game_state_3766_6
.Lraw_game_state_3766_4:
    movs r0, #0
.Lraw_game_state_3766_6:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
    .global func_0801D23C
    .thumb_func
func_0801D23C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov r8, r0
    adds r4, r1, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    mov r0, r8
    adds r1, r4, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lauto_0801D000
    b .Lauto_0801D17E
    .Lauto_0801D000:
    ldr r0, [sp, #4]
    bl method_0800A3C8__9FieldPlot
    str r0, [sp, #0x10]
    cmp r0, #1
    beq .Lauto_0801D01E
    rsbs r0, r0, #0
    str r0, [sp, #0x24]
    ldr r1, [sp, #0x10]
    cmp r1, #1
    bgt .Lauto_0801D018
    b .Lauto_0801D174
    .Lauto_0801D018:
    cmp r1, #2
    beq .Lauto_0801D030
    b .Lauto_0801D174
    .Lauto_0801D01E:
    ldr r0, .Lraw_game_state_3852_8
    add r0, r8
    ldr r0, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    movs r1, #1
    bl AddStoredBushels__4BarnUi
    .Lauto_0801D030:
    mov r3, r8
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_0801D05C
    ldr r0, .Lraw_game_state_3852_12
    add r0, r8
    ldr r0, [r0]
    add r1, sp, #4
    ldrh r1, [r1, #4]
    lsls r1, r1, #3
    adds r1, #8
    add r2, sp, #4
    ldrh r2, [r2, #6]
    lsls r2, r2, #3
    adds r2, #0x10
    movs r3, #0
    bl func_080AB0C4
    .Lauto_0801D05C:
    mov r1, r8
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    ldrh r1, [r4]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    ldr r2, [sp, #0x10]
    rsbs r2, r2, #0
    str r2, [sp, #0x24]
    cmp r0, r1
    beq .Lraw_game_state_3847_2
    b .Lauto_0801D174
.Lraw_game_state_3847_2:
    ldr r0, .Lraw_game_state_3852_8
    add r0, r8
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x14
    str r3, [sp, #0x14]
    add r0, sp, #4
    ldrh r4, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldrh r0, [r0, #4]
    str r0, [sp, #0x18]
    add r0, sp, #4
    ldrh r0, [r0, #6]
    ldr r3, .Lraw_game_state_3853_0
    adds r3, r1, r3
    str r3, [sp, #0x20]
    subs r0, #2
    mov sb, r0
    movs r1, #0x2b
    adds r0, r2, #0
    muls r0, r1, r0
    adds r0, r0, r4
    adds r6, r0, #0
    subs r6, #0x2b
    subs r5, r2, #1
    movs r2, #2
    str r2, [sp, #0x1c]
.Lraw_game_state_3850_8:
    movs r0, #0
    cmp r4, #0
    blt .Lraw_game_state_3851_12
    cmp r5, #0
    blt .Lraw_game_state_3851_12
    cmp r4, #0x2a
    bgt .Lraw_game_state_3851_12
    cmp r5, #0x18
    bgt .Lraw_game_state_3851_12
    movs r0, #1
.Lraw_game_state_3851_12:
    cmp r0, #0
    beq .Lraw_game_state_3853_4
    lsls r0, r6, #2
    ldr r1, [sp, #0x20]
    adds r3, r1, r0
    b .Lraw_game_state_3853_6
.Lraw_game_state_3852_8: .word 0x00001038
.Lraw_game_state_3852_12: .word 0x00001028
.Lraw_game_state_3853_0: .word 0x000009DC
.Lraw_game_state_3853_4:
    movs r3, #0
.Lraw_game_state_3853_6:
    adds r7, r3, #0
    cmp r7, #0
    beq .Lraw_game_state_3863_0
    mov r2, r8
    ldr r2, [r2, #4]
    mov sl, r2
    ldr r3, [sp, #0x14]
    ldr r0, .Lraw_game_state_3857_8
    adds r2, r3, r0
    adds r3, r5, #0
    lsls r0, r6, #2
    adds r0, r0, r2
    mov ip, r0
    adds r0, r5, #1
    movs r1, #0
    cmp r4, #0
    blt .Lraw_game_state_3856_6
    cmp r0, #0
    blt .Lraw_game_state_3856_6
    cmp r4, #0x2a
    bgt .Lraw_game_state_3856_6
    cmp r0, #0x18
    bgt .Lraw_game_state_3856_6
    movs r1, #1
.Lraw_game_state_3856_6:
    cmp r1, #0
    beq .Lraw_game_state_3857_12
    movs r1, #0x2b
    muls r0, r1, r0
    adds r0, r4, r0
    lsls r0, r0, #2
    adds r1, r2, r0
    b .Lraw_game_state_3857_14
    .align 2, 0
.Lraw_game_state_3857_8: .word 0x000009C8
.Lraw_game_state_3857_12:
    movs r1, #0
.Lraw_game_state_3857_14:
    subs r0, r3, #1
    movs r3, #0
    cmp r4, #0
    blt .Lraw_game_state_3859_4
    cmp r0, #0
    blt .Lraw_game_state_3859_4
    cmp r4, #0x2a
    bgt .Lraw_game_state_3859_4
    cmp r0, #0x18
    bgt .Lraw_game_state_3859_4
    movs r3, #1
.Lraw_game_state_3859_4:
    cmp r3, #0
    beq .Lraw_game_state_3860_4
    movs r3, #0x2b
    muls r0, r3, r0
    adds r0, r4, r0
    lsls r0, r0, #2
    adds r2, r2, r0
    b .Lraw_game_state_3860_6
.Lraw_game_state_3860_4:
    movs r2, #0
.Lraw_game_state_3860_6:
    mov r0, ip
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    mov r0, sl
    ldr r1, [sp, #0x18]
    mov r2, sb
    adds r3, r7, #0
    bl RefreshFieldPlotTiles
.Lraw_game_state_3863_0:
    movs r0, #2
    add sb, r0
    adds r6, #0x2b
    adds r5, #1
    ldr r1, [sp, #0x1c]
    subs r1, #1
    str r1, [sp, #0x1c]
    cmp r1, #0
    bge .Lraw_game_state_3850_8
    .Lauto_0801D174:
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x10]
    orrs r2, r3
    lsrs r0, r2, #0x1f
    b .Lauto_0801D180
    .Lauto_0801D17E:
    movs r0, #0
    .Lauto_0801D180:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .section .text.game_scene_after_record_player_album, "ax", %progbits
    .align 2, 0

    .global func_0801DEB4
    .thumb_func
func_0801DEB4:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x20
    mov sl, r0
    adds r7, r1, #0
    movs r0, #0
    str r0, [sp, #4]
    mov r8, r0
    movs r1, #0
    str r1, [sp, #8]
    mov ip, r1
    movs r4, #0
    ldr r0, .Lraw_game_state_4031_0
    add r0, sl
    ldr r0, [r0]
    ldr r2, .Lraw_game_state_4031_4
    adds r2, r0, r2
    str r2, [sp, #0x18]
    .Lauto_0801DC72:
    movs r3, #0
    adds r6, r4, #1
    mov sb, r6
    movs r5, #0x8c
    lsls r5, r5, #1
    movs r0, #0xac
    muls r0, r4, r0
    ldr r1, [sp, #0x18]
    adds r2, r0, r1
    lsls r0, r4, #4
    adds r0, #0xb8
    str r0, [sp, #0x1c]
    .Lauto_0801DC8A:
    ldr r1, [r2]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x1a
    cmp r0, #0x14
    bne .Lauto_0801DCD0
    lsls r0, r1, #0x14
    lsrs r0, r0, #0x1c
    cmp r0, #5
    bne .Lauto_0801DCD0
    movs r6, #0
    ldrsh r1, [r7, r6]
    subs r1, r5, r1
    movs r6, #2
    ldrsh r0, [r7, r6]
    ldr r6, [sp, #0x1c]
    subs r0, r6, r0
    adds r6, r1, #0
    muls r6, r1, r6
    adds r1, r6, #0
    adds r6, r0, #0
    muls r6, r0, r6
    adds r0, r6, #0
    adds r1, r1, r0
    adds r0, r1, #0
    mov r6, ip
    cmp r6, #0
    beq .Lauto_0801DCC6
    ldr r6, [sp, #4]
    cmp r1, r6
    bge .Lauto_0801DCD0
    .Lauto_0801DCC6:
    movs r1, #1
    mov ip, r1
    mov r8, r3
    str r4, [sp, #8]
    str r0, [sp, #4]
    .Lauto_0801DCD0:
    adds r5, #0x10
    adds r2, #4
    adds r3, #1
    cmp r3, #0x2a
    bls .Lauto_0801DC8A
    movs r1, #0x2b
    mov r4, sb
    cmp r4, #0x18
    bls .Lauto_0801DC72
    mov r2, ip
    cmp r2, #0
    bne .Lauto_0801DCEA
    b .Lauto_0801DE06
    .Lauto_0801DCEA:
    ldr r0, .Lraw_game_state_4031_0
    add r0, sl
    ldr r0, [r0]
    ldr r3, .Lraw_game_state_4031_4
    adds r0, r0, r3
    ldr r6, [sp, #8]
    muls r1, r6, r1
    mov r7, r8
    adds r4, r7, r1
    lsls r1, r4, #2
    adds r0, r0, r1
    bl method_0800A3C8__9FieldPlot
    mov r1, sl
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sl
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_0801DE02
    lsls r0, r7, #1
    adds r0, #0x22
    str r0, [sp, #0xc]
    lsls r0, r6, #1
    mov r2, sl
    ldr r2, [r2, #4]
    str r2, [sp, #0x10]
    adds r0, #0x14
    mov sb, r0
    adds r5, r4, #0
    subs r5, #0x2b
    adds r4, r6, #0
    subs r4, #1
    movs r3, #2
    str r3, [sp, #0x14]
    .Lauto_0801DD32:
    ldr r0, .Lraw_game_state_4031_0
    add r0, sl
    ldr r0, [r0]
    ldr r6, .Lraw_game_state_4031_4
    adds r1, r0, r6
    movs r0, #0
    mov r7, r8
    cmp r7, #0
    blt .Lauto_0801DD52
    cmp r4, #0
    blt .Lauto_0801DD52
    cmp r7, #0x2a
    bgt .Lauto_0801DD52
    cmp r4, #0x18
    bgt .Lauto_0801DD52
    movs r0, #1
    .Lauto_0801DD52:
    cmp r0, #0
    beq .Lauto_0801DD64
    lsls r0, r5, #2
    adds r3, r1, r0
    b .Lauto_0801DD66
.Lraw_game_state_4031_0: .word 0x00001038
.Lraw_game_state_4031_4: .word 0x000009DC
    .Lauto_0801DD64:
    movs r3, #0
    .Lauto_0801DD66:
    adds r6, r3, #0
    cmp r6, #0
    beq .Lauto_0801DDF0
    ldr r0, .Lraw_game_state_4068_2
    add r0, sl
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_4068_6
    adds r2, r0, r1
    adds r3, r4, #0
    lsls r0, r5, #2
    adds r0, r0, r2
    mov ip, r0
    adds r0, r4, #1
    movs r1, #0
    mov r7, r8
    cmp r7, #0
    blt .Lauto_0801DD96
    cmp r0, #0
    blt .Lauto_0801DD96
    cmp r7, #0x2a
    bgt .Lauto_0801DD96
    cmp r0, #0x18
    bgt .Lauto_0801DD96
    movs r1, #1
    .Lauto_0801DD96:
    cmp r1, #0
    beq .Lauto_0801DDB0
    movs r1, #0x2b
    muls r0, r1, r0
    add r0, r8
    lsls r0, r0, #2
    adds r1, r2, r0
    b .Lauto_0801DDB2
    .align 2, 0
.Lraw_game_state_4068_2: .word 0x00001038
.Lraw_game_state_4068_6: .word 0x000009DC
    .Lauto_0801DDB0:
    movs r1, #0
    .Lauto_0801DDB2:
    subs r0, r3, #1
    movs r3, #0
    mov r7, r8
    cmp r7, #0
    blt .Lauto_0801DDCA
    cmp r0, #0
    blt .Lauto_0801DDCA
    cmp r7, #0x2a
    bgt .Lauto_0801DDCA
    cmp r0, #0x18
    bgt .Lauto_0801DDCA
    movs r3, #1
    .Lauto_0801DDCA:
    cmp r3, #0
    beq .Lauto_0801DDDA
    movs r3, #0x2b
    muls r0, r3, r0
    add r0, r8
    lsls r0, r0, #2
    adds r2, r2, r0
    b .Lauto_0801DDDC
    .Lauto_0801DDDA:
    movs r2, #0
    .Lauto_0801DDDC:
    mov r0, ip
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0xc]
    mov r2, sb
    adds r3, r6, #0
    bl RefreshFieldPlotTiles
    .Lauto_0801DDF0:
    movs r6, #2
    add sb, r6
    adds r5, #0x2b
    adds r4, #1
    ldr r7, [sp, #0x14]
    subs r7, #1
    str r7, [sp, #0x14]
    cmp r7, #0
    bge .Lauto_0801DD32
    .Lauto_0801DE02:
    movs r0, #1
    b .Lauto_0801DE08
    .Lauto_0801DE06:
    movs r0, #0
    .Lauto_0801DE08:
    add sp, #0x20
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .global func_0801E084
    .thumb_func
func_0801E084:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x4c
    str r0, [sp, #0x40]
    bl loc_0801E6A0
    movs r0, #0
    str r0, [sp, #0x44]
    movs r1, #0
    str r1, [sp, #0x48]
    .Lauto_0801DE32:
    ldr r2, [sp, #0x48]
    mov sb, r2
    ldr r3, [sp, #0x40]
    ldr r0, [r3]
    ldr r2, [r0, #0x40]
    adds r0, r3, #0
    ldr r1, [sp, #0x48]
    bl _call_via_r2
    adds r7, r0, #0
    cmp r7, #0
    bne .Lauto_0801DE4C
    b .Lauto_0801E3C4
    .Lauto_0801DE4C:
    movs r0, #0
    mov sl, r0
    ldr r0, [sp, #0x48]
    subs r0, #0x2b
    cmp r0, #0x28
    bls .Lauto_0801DE5A
    b .Lauto_0801E030
    .Lauto_0801DE5A:
    lsls r0, r0, #2
    ldr r1, .Lraw_game_state_4170_0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
.Lraw_game_state_4170_0: .word .Lauto_0801DE68
    .Lauto_0801DE68:
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801E030
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801E030
    .word .Lauto_0801E030
    .word .Lauto_0801E030
    .word .Lauto_0801E030
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF0C
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .word .Lauto_0801DF1E
    .Lauto_0801DF0C:
    ldr r1, [sp, #0x40]
    ldr r2, .Lraw_game_state_4190_14
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r0, [r0, #8]
    subs r0, #3
    cmp r0, #1
    bhi .Lauto_0801DF1E
    b .Lauto_0801E038
    .Lauto_0801DF1E:
    ldrh r2, [r7, #4]
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r2, r0
    bne .Lraw_game_state_4187_12
    b .Lauto_0801E038
.Lraw_game_state_4187_12:
    ldr r3, [sp, #0x40]
    ldr r5, [r3, #4]
    ldr r0, [r5]
    cmp r2, r0
    bne .Lraw_game_state_4191_2
    ldr r0, [r5, #4]
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r0, [sp, #0x40]
    ldr r4, [r0, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    movs r2, #0
    ldr r0, [r4, #0x2c]
    add r1, sp, #4
    str r0, [sp, #4]
    str r2, [sp, #8]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x18
    b .Lraw_game_state_4193_2
.Lraw_game_state_4190_14: .word 0x00001038
.Lraw_game_state_4191_2:
    cmp r2, #2
    bne .Lraw_game_state_4196_2
    add r3, sp, #4
    ldr r1, [sp, #0x40]
    ldr r2, .Lraw_game_state_4195_10
    adds r0, r1, r2
    ldr r0, [r0]
    movs r1, #0x80
    movs r2, #0x58
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    strh r1, [r3, #8]
    strh r2, [r3, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x20
.Lraw_game_state_4193_2:
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r7, #0
    bl _call_via_r2
    add r0, sp, #4
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801E030
    b .Lauto_0801E038
    .align 2, 0
.Lraw_game_state_4195_10: .word 0x00001050
.Lraw_game_state_4196_2:
    add r3, sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, .Lraw_game_state_4227_0
    adds r0, r1, #0
    ands r2, r0
    ldrh r1, [r3]
    ldr r4, .Lraw_game_state_4227_4
    adds r0, r4, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r3]
    ldrb r1, [r3, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3, #1]
    ldrh r1, [r3, #2]
    adds r0, r4, #0
    ands r0, r1
    strh r0, [r3, #2]
    ldrb r0, [r3, #3]
    ands r2, r0
    strb r2, [r3, #3]
    ldrh r0, [r3, #4]
    ands r4, r0
    strh r4, [r3, #4]
    movs r0, #0x1e
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    movs r2, #3
    movs r3, #0
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    movs r2, #1
    str r2, [sp, #0x44]
    ldr r3, [sp, #0x40]
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r0, [sp, #0x40]
    ldr r4, [r0, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    ldr r0, [r4, #0x2c]
    add r1, sp, #4
    str r0, [sp, #4]
    mov r2, r8
    str r2, [sp, #8]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x28
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r7, #0
    bl _call_via_r2
    add r0, sp, #4
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801E030
    movs r3, #1
    mov sl, r3
    .Lauto_0801E030:
    mov r0, sl
    cmp r0, #0
    bne .Lauto_0801E038
    b .Lauto_0801E3C4
    .Lauto_0801E038:
    mov r0, sb
    subs r0, #0x2b
    cmp r0, #0x28
    bls .Lauto_0801E042
    b .Lauto_0801E3C4
    .Lauto_0801E042:
    lsls r0, r0, #2
    ldr r1, .Lraw_game_state_4227_8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
.Lraw_game_state_4227_0: .word 0x000003FF
.Lraw_game_state_4227_4: .word 0xFFFFFC00
.Lraw_game_state_4227_8: .word .Lswitch_0801E058
.Lswitch_0801E058: .word .Lraw_game_state_4238_0
    .word .Lraw_game_state_4242_8
    .word .Lauto_0801E3C4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4245_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lraw_game_state_4262_4
    .word .Lauto_0801E3C4
    .word .Lauto_0801E3C4
    .word .Lauto_0801E3C4
    .word .Lauto_0801E3C4
    .word .Lraw_game_state_4279_12
    .word .Lraw_game_state_4280_10
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
    .word .Lraw_game_state_4259_4
.Lraw_game_state_4238_0:
    cmp r7, #0
    bne .Lraw_game_state_4238_6
    b .Lauto_0801E3C4
.Lraw_game_state_4238_6:
    add r1, sp, #0x10
    movs r3, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_4242_4
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    movs r5, #0xf8
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #5
    ldrh r3, [r1, #2]
    adds r0, r4, #0
    ands r0, r3
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    movs r0, #0x48
    orrs r2, r0
    strb r2, [r1, #3]
    movs r2, #1
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r2
    b .Lraw_game_state_4277_14
.Lraw_game_state_4242_4: .word 0xFFFFFC00
.Lraw_game_state_4242_8:
    cmp r7, #0
    bne .Lraw_game_state_4242_14
    b .Lauto_0801E3C4
.Lraw_game_state_4242_14:
    add r1, sp, #0xc
    movs r6, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_4245_0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1]
    movs r5, #0xc0
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #0xb
    b .Lraw_game_state_4276_4
.Lraw_game_state_4245_0: .word 0xFFFFFC00
.Lraw_game_state_4245_4:
    cmp r7, #0
    bne .Lraw_game_state_4245_10
    b .Lauto_0801E3C4
.Lraw_game_state_4245_10:
    ldrh r1, [r7, #4]
    cmp r1, #0x11
    beq .Lraw_game_state_4246_8
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r1, r0
    bne .Lraw_game_state_4255_4
.Lraw_game_state_4246_8:
    mov r2, sb
    subs r2, #0x2e
    ldr r1, [sp, #0x40]
    ldr r3, .Lraw_game_state_4254_12
    adds r0, r1, r3
    ldr r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r1, r1, r0
    add r0, sp, #0x30
    bl method_0800C6F0__C4CoopUi
    ldr r0, [sp, #0x30]
    str r0, [sp, #0x34]
    add r0, sp, #0x34
    movs r1, #0
    ldrsh r6, [r0, r1]
    movs r3, #2
    ldrsh r2, [r0, r3]
    mov r8, r2
    add r1, sp, #0xc
    movs r3, #0x11
    ldrh r2, [r1]
    ldr r5, .Lraw_game_state_4255_0
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    lsls r6, r6, #0x10
    lsrs r2, r6, #0x10
    movs r0, #0x3f
    mov sb, r0
    ands r2, r0
    lsls r2, r2, #2
    ldrb r4, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r4
    orrs r0, r2
    strb r0, [r1, #1]
    lsrs r6, r6, #0x16
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1, #2]
    mov r2, r8
    lsls r2, r2, #0x10
    mov r8, r2
    lsrs r0, r2, #0x10
    mov r2, sb
    ands r0, r2
    lsls r0, r0, #2
    ldrb r2, [r1, #3]
    ands r3, r2
    orrs r3, r0
    strb r3, [r1, #3]
    mov r3, r8
    lsrs r3, r3, #0x16
    ldrh r0, [r1, #4]
    ands r5, r0
    orrs r5, r3
    strh r5, [r1, #4]
    add r5, sp, #4
    movs r4, #1
    b .Lraw_game_state_4278_4
.Lraw_game_state_4254_12: .word 0x00001038
.Lraw_game_state_4255_0: .word 0xFFFFFC00
.Lraw_game_state_4255_4:
    add r1, sp, #0xc
    movs r5, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_4259_0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strh r0, [r1]
    ldrb r2, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r2
    movs r2, #0x3c
    orrs r0, r2
    strb r0, [r1, #1]
    ldrh r2, [r1, #2]
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r3, r0
    movs r0, #0x30
    orrs r3, r0
    strb r3, [r1, #3]
    movs r2, #8
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r2
    b .Lraw_game_state_4277_14
.Lraw_game_state_4259_0: .word 0xFFFFFC00
.Lraw_game_state_4259_4:
    cmp r7, #0
    bne .Lraw_game_state_4259_10
    b .Lauto_0801E3C4
.Lraw_game_state_4259_10:
    ldr r1, [sp, #0x40]
    ldr r0, [r1]
    ldr r2, [r0, #0x3c]
    adds r0, r1, #0
    mov r1, sb
    bl _call_via_r2
    ldr r2, [sp, #0x40]
    ldr r3, .Lraw_game_state_4262_0
    adds r0, r2, r3
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    mov r1, sb
    subs r1, #0x4c
    bl method_0800C9B8__4CoopUi
    b .Lauto_0801E3C4
.Lraw_game_state_4262_0: .word 0x00001038
.Lraw_game_state_4262_4:
    cmp r7, #0
    bne .Lraw_game_state_4262_10
    b .Lauto_0801E3C4
.Lraw_game_state_4262_10:
    ldrh r1, [r7, #4]
    cmp r1, #0x25
    beq .Lraw_game_state_4263_8
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r1, r0
    bne .Lraw_game_state_4274_4
.Lraw_game_state_4263_8:
    movs r2, #0x36
    rsbs r2, r2, #0
    add r2, sb
    mov sl, r2
    ldr r3, [sp, #0x40]
    ldr r1, .Lraw_game_state_4273_12
    adds r0, r3, r1
    ldr r1, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r1, r1, r2
    add r0, sp, #0x38
    mov r2, sl
    bl method_0800D074__C4BarnUi
    ldr r0, [sp, #0x38]
    str r0, [sp, #0x3c]
    add r0, sp, #0x3c
    movs r3, #0
    ldrsh r6, [r0, r3]
    movs r2, #2
    ldrsh r1, [r0, r2]
    mov r8, r1
    add r1, sp, #0xc
    movs r3, #0x25
    ldrh r2, [r1]
    ldr r5, .Lraw_game_state_4274_0
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    lsls r6, r6, #0x10
    lsrs r2, r6, #0x10
    movs r3, #0x3f
    mov sb, r3
    ands r2, r3
    lsls r2, r2, #2
    ldrb r4, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r4
    orrs r0, r2
    strb r0, [r1, #1]
    lsrs r6, r6, #0x16
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1, #2]
    mov r0, r8
    lsls r0, r0, #0x10
    mov r8, r0
    lsrs r0, r0, #0x10
    mov r2, sb
    ands r0, r2
    lsls r0, r0, #2
    ldrb r2, [r1, #3]
    ands r3, r2
    orrs r3, r0
    strb r3, [r1, #3]
    mov r3, r8
    lsrs r3, r3, #0x16
    ldrh r0, [r1, #4]
    ands r5, r0
    orrs r5, r3
    strh r5, [r1, #4]
    mov r0, sl
    lsrs r0, r0, #2
    mov sl, r0
    movs r0, #1
    mov r2, sl
    ands r2, r0
    mov sl, r2
    add r4, sp, #4
    adds r0, r4, #0
    movs r2, #6
    bl memcpy
    mov r3, sl
    strb r3, [r4, #6]
    b .Lraw_game_state_4278_14
    .align 2, 0
.Lraw_game_state_4273_12: .word 0x00001038
.Lraw_game_state_4274_0: .word 0xFFFFFC00
.Lraw_game_state_4274_4:
    add r1, sp, #0xc
    movs r6, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_4279_8
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1]
    movs r5, #0xe0
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #7
.Lraw_game_state_4276_4:
    ldrh r3, [r1, #2]
    adds r0, r4, #0
    ands r0, r3
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    movs r0, #0x10
    orrs r2, r0
    strb r2, [r1, #3]
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r6
.Lraw_game_state_4277_14:
    strh r4, [r1, #4]
    add r5, sp, #4
    movs r4, #0
.Lraw_game_state_4278_4:
    adds r0, r5, #0
    movs r2, #6
    bl memcpy
    strb r4, [r5, #6]
.Lraw_game_state_4278_14:
    adds r0, r7, #0
    add r1, sp, #4
    bl SetLocation__12AActorEntityRC13ActorLocation
    b .Lauto_0801E3C4
.Lraw_game_state_4279_8: .word 0xFFFFFC00
.Lraw_game_state_4279_12:
    adds r0, r7, #0
    movs r1, #2
    movs r2, #0xe0
    movs r3, #0xa8
    bl SetLocation__7AEntityUiii
    b .Lauto_0801E3C4
.Lraw_game_state_4280_10:
    ldr r1, [sp, #0x40]
    ldr r0, [r1]
    ldr r2, [r0, #0x3c]
    adds r0, r1, #0
    mov r1, sb
    bl _call_via_r2
    ldr r2, [sp, #0x40]
    ldr r3, .LworldActorSaveOffset
    adds r0, r2, r3
    ldr r0, [r0]
    ldr r1, .LworldActorFarmerOffset
    adds r0, r0, r1
    bl func_0800ED2C
    .Lauto_0801E3C4:
    ldr r2, [sp, #0x48]
    adds r2, #1
    str r2, [sp, #0x48]
    cmp r2, #0x63
    bgt .Lauto_0801E3D0
    b .Lauto_0801DE32
    .Lauto_0801E3D0:
    ldr r3, [sp, #0x44]
    cmp r3, #0
    beq .Lauto_0801E3F8
    ldr r0, [sp, #0x40]
    ldr r4, [r0]
    adds r4, #0xb4
    ldr r1, .LworldActorSaveOffset
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, .LworldActorFarmerOffset
    adds r1, r1, r2
    add r0, sp, #4
    bl GetLocation__C6Farmer
    ldr r3, [r4]
    ldr r0, [sp, #0x40]
    add r1, sp, #4
    movs r2, #0
    bl _call_via_r3
    .Lauto_0801E3F8:
    add sp, #0x4c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.LworldActorSaveOffset: .word 0x1038
.LworldActorFarmerOffset: .word 0x1BD8

    .section .text.world_after_farmhouse_relocation, "ax", %progbits
    .global loc_0801E6A0
    .thumb_func
    loc_0801E6A0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x40
    mov r8, r0
    movs r0, #0
    str r0, [sp, #0x34]
    movs r4, #0
    .Lauto_0801E6B4:
    mov r1, r8
    ldr r0, [r1]
    ldr r2, [r0, #0x40]
    mov r0, r8
    adds r1, r4, #0
    bl _call_via_r2
    adds r3, r0, #0
    adds r4, #1
    mov sl, r4
    cmp r3, #0
    beq .Lauto_0801E7AC
    ldrh r0, [r3, #4]
    cmp r0, #2
    bne .Lauto_0801E7AC
    ldr r1, [r3, #0x14]
    add r0, sp, #4
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    add r4, sp, #0xc
    adds r6, r4, #0
    movs r5, #0
    str r5, [sp, #0x14]
    ldrh r0, [r4]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x13
    subs r0, #0x22
    asrs r0, r0, #1
    str r0, [sp, #0x18]
    add r1, sp, #0x18
    add r2, sp, #0x14
    cmp r5, r0
    bge .Lauto_0801E704
    adds r2, r1, #0
    .Lauto_0801E704:
    ldr r2, [r2]
    mov sb, r2
    movs r1, #0x2a
    str r1, [sp, #0x1c]
    movs r2, #4
    ldrsh r0, [r4, r2]
    subs r0, #1
    asrs r0, r0, #3
    subs r0, #0x22
    asrs r0, r0, #1
    str r0, [sp, #0x20]
    add r2, sp, #0x20
    add r3, sp, #0x1c
    cmp r1, r0
    ble .Lauto_0801E724
    adds r3, r2, #0
    .Lauto_0801E724:
    ldr r7, [r3]
    str r5, [sp, #0x24]
    ldrh r0, [r4, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x13
    subs r0, #0x16
    asrs r0, r0, #1
    str r0, [sp, #0x28]
    add r1, sp, #0x28
    add r2, sp, #0x24
    cmp r5, r0
    bge .Lraw_game_state_4395_6
    adds r2, r1, #0
.Lraw_game_state_4395_6:
    ldr r4, [r2]
    movs r1, #0x18
    str r1, [sp, #0x2c]
    movs r2, #6
    ldrsh r0, [r6, r2]
    subs r0, #1
    asrs r0, r0, #3
    subs r0, #0x16
    asrs r0, r0, #1
    str r0, [sp, #0x30]
    add r2, sp, #0x30
    add r3, sp, #0x2c
    cmp r1, r0
    ble .Lraw_game_state_4397_4
    adds r3, r2, #0
.Lraw_game_state_4397_4:
    ldr r2, [r3]
    adds r1, r4, #0
    cmp r1, r2
    bgt .Lauto_0801E7AC
    mov r0, sb
    lsls r3, r0, #2
.Lraw_game_state_4398_0:
    mov r4, sb
    adds r6, r1, #1
    cmp r4, r7
    bgt .Lraw_game_state_4401_14
    movs r0, #0xac
    muls r0, r1, r0
    adds r5, r3, r0
.Lraw_game_state_4398_14:
    ldr r0, .Lraw_game_state_4432_0
    add r0, r8
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_4432_4
    adds r0, r0, r1
    adds r1, r0, r5
    ldr r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x1a
    cmp r0, #0x15
    bne .Lraw_game_state_4401_6
    mov r0, sp
    str r2, [sp, #0x38]
    str r3, [sp, #0x3c]
    bl method_0800A4A4__9FieldPlot
    movs r0, #1
    str r0, [sp, #0x34]
    ldr r3, [sp, #0x3c]
    ldr r2, [sp, #0x38]
.Lraw_game_state_4401_6:
    adds r5, #4
    adds r4, #1
    cmp r4, r7
    ble .Lraw_game_state_4398_14
.Lraw_game_state_4401_14:
    adds r1, r6, #0
    cmp r1, r2
    ble .Lraw_game_state_4398_0
    .Lauto_0801E7AC:
    mov r4, sl
    cmp r4, #0x63
    bgt .Lauto_0801E7B4
    b .Lauto_0801E6B4
    .Lauto_0801E7B4:
    ldr r1, [sp, #0x34]
    cmp r1, #0
    beq .Lauto_0801E81A
    mov r2, r8
    ldr r5, [r2, #4]
    ldr r0, [r5]
    cmp r0, #2
    bne .Lauto_0801E7F4
    adds r0, r5, #0
    adds r0, #0x90
    ldr r4, [r0]
    ldr r0, .Lraw_game_state_4432_8
    add r0, r8
    ldr r1, [r0]
    ldr r0, .Lraw_game_state_4432_12
    add r0, r8
    ldrb r2, [r0]
    movs r3, #0x1e
    subs r3, r3, r2
    ldr r4, [r4, #0x14]
    adds r0, r5, #0
    bl _call_via_r4
    b .Lauto_0801E81A
.Lraw_game_state_4432_0: .word 0x00001038
.Lraw_game_state_4432_4: .word 0x000009DC
.Lraw_game_state_4432_8: .word 0x00001048
.Lraw_game_state_4432_12: .word 0x0000104C
    .Lauto_0801E7F4:
    ldr r0, .Lraw_game_state_4461_2
    add r0, r8
    ldr r5, [r0]
    ldr r0, .Lraw_game_state_4461_6
    add r0, r8
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0x14
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    movs r2, #0
    cmp r0, #3
    bne .Lauto_0801E812
    movs r2, #1
    .Lauto_0801E812:
    adds r0, r5, #0
    adds r1, r4, #0
    bl InitializeFarmTerrain
    .Lauto_0801E81A:
    add sp, #0x40
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lraw_game_state_4461_2: .word 0x00001050
.Lraw_game_state_4461_6: .word 0x00001038
    .global func_0801EAA0
    .thumb_func
func_0801EAA0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .Lraw_game_state_4609_0
    add sp, r4
    adds r7, r0, #0
    str r1, [sp, #0x330]
    ldr r1, .Lraw_game_state_4609_4
    adds r0, r7, r1
    ldr r0, [r0]
    adds r0, #0x12
    str r0, [sp, #0x334]
    ldr r3, .Lraw_game_state_4609_8
    adds r0, r7, r3
    ldrb r0, [r0]
    str r0, [sp, #0x338]
    cmp r0, #0
    beq .Lauto_0801E86C
    ldr r0, [r7]
    movs r4, #0x94
    lsls r4, r4, #1
    adds r0, r0, r4
    ldr r1, [r0]
    adds r0, r7, #0
    bl _call_via_r1
    .Lauto_0801E86C:
    adds r5, r7, #0
    adds r5, #8
    str r5, [sp, #0x33c]
    movs r0, #0xcc
    lsls r0, r0, #1
    adds r0, r7, r0
    str r0, [sp, #0x340]
    adds r4, r5, #0
    adds r6, r4, #0
    movs r3, #0xca
    lsls r3, r3, #2
    add r3, sp
    mov r8, r3
    cmp r6, r0
    beq .Lauto_0801E8A2
    .Lauto_0801E88A:
    ldr r2, [r4]
    cmp r2, #0
    beq .Lauto_0801E89A
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x14]
    adds r0, r2, #0
    bl _call_via_r1
    .Lauto_0801E89A:
    adds r4, #4
    ldr r0, [sp, #0x340]
    cmp r4, r0
    bne .Lauto_0801E88A
    .Lauto_0801E8A2:
    movs r0, #0
    str r0, [sp]
    movs r3, #0
    adds r4, r6, #0
    ldr r2, .Lraw_game_state_4610_0
    .Lauto_0801E8AC:
    ldr r0, [r2]
    lsls r0, r0, #2
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_0801E8D0
    ldr r0, [sp]
    cmp r0, #0x63
    bhi .Lauto_0801E8D0
    lsls r0, r0, #2
    adds r0, #4
    add r0, sp
    cmp r0, #0
    beq .Lauto_0801E8CA
    str r1, [r0]
    .Lauto_0801E8CA:
    ldr r0, [sp]
    adds r0, #1
    str r0, [sp]
    .Lauto_0801E8D0:
    adds r2, #4
    adds r3, #1
    cmp r3, #9
    bls .Lauto_0801E8AC
    ldr r0, [sp]
    lsls r0, r0, #2
    adds r0, #4
    add r0, sp
    mov sb, r0
    movs r2, #0xca
    lsls r2, r2, #1
    mov r3, sp
    adds r1, r3, r2
    movs r0, #0
    str r0, [r1]
    movs r5, #0
    ldr r4, .Lraw_game_state_4611_0
    .Lauto_0801E8F2:
    ldr r0, [r4]
    lsls r0, r0, #2
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r3, #0
    beq .Lauto_0801E91A
    mov r0, sp
    adds r1, r0, r2
    ldr r0, [r1]
    cmp r0, #0x63
    bhi .Lauto_0801E91A
    lsls r0, r0, #2
    adds r0, #4
    adds r0, r1, r0
    cmp r0, #0
    beq .Lauto_0801E914
    str r3, [r0]
    .Lauto_0801E914:
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    .Lauto_0801E91A:
    adds r4, #4
    adds r5, #1
    cmp r5, #0x23
    bls .Lauto_0801E8F2
    add r1, sp, #0x194
    ldr r0, [r1]
    lsls r0, r0, #2
    adds r0, #4
    adds r1, r1, r0
    str r1, [sp, #0x344]
    movs r1, #0
    add r0, sp, #0x328
    str r1, [r0]
    mov r3, r8
    strb r1, [r3, #4]
    movs r4, #0x82
    lsls r4, r4, #5
    adds r6, r7, r4
    movs r5, #3
    mov sl, r5
    b loc_0801E976
.Lraw_game_state_4609_0: .word 0xFFFFFCB0
.Lraw_game_state_4609_4: .word 0x00001038
.Lraw_game_state_4609_8: .word 0x0000103C
.Lraw_game_state_4610_0: .4byte gUnk_080F0748
.Lraw_game_state_4611_0: .4byte gUnk_080F0770
    .Lauto_0801E958:
    movs r0, #0
    mov r1, r8
    strb r0, [r1, #4]
    b .Lauto_0801E976
    .Lauto_0801E960:
    add r4, sp, #4
    cmp r4, sb
    beq .Lauto_0801E976
    .Lauto_0801E966:
    ldm r4!, {r0}
    ldr r1, [r0, #0x14]
    ldr r2, [r1, #0x18]
    mov r1, r8
    bl _call_via_r2
    cmp r4, sb
    bne .Lauto_0801E966
    .global loc_0801E976
    .thumb_func
    loc_0801E976:
    .Lauto_0801E976:
    ldrb r0, [r6, #4]
    adds r0, #1
    cmp r0, #0x19
    bhs .Lauto_0801E984
    strb r0, [r6, #4]
    movs r0, #0
    b .Lauto_0801EA9A
    .Lauto_0801E984:
    movs r0, #0
    strb r0, [r6, #4]
    ldr r4, [r6]
    ldr r1, [r4]
    lsls r1, r1, #5
    lsrs r1, r1, #0x1a
    adds r1, #1
    movs r2, #0x3f
    ands r2, r1
    lsls r2, r2, #5
    ldrh r3, [r4, #2]
    ldr r5, .Lraw_game_state_4795_0
    adds r0, r5, #0
    ands r0, r3
    orrs r0, r2
    strh r0, [r4, #2]
    movs r0, #0x3f
    ands r1, r0
    cmp r1, #0x3b
    bls .Lauto_0801EA98
    ldr r1, [r6]
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    strh r0, [r1, #2]
    ldr r3, [r6]
    ldr r1, [r3]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x1b
    adds r1, #1
    movs r4, #0x1f
    mov ip, r4
    mov r5, ip
    ands r1, r5
    ldrb r2, [r3, #2]
    movs r4, #0x20
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #2]
    cmp r1, #0x17
    bls .Lauto_0801EA98
    ldr r1, [r6]
    ldrb r2, [r1, #2]
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1, #2]
    ldr r3, [r6]
    ldrb r2, [r3, #1]
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    cmp r0, #0x1e
    bne .Lraw_game_state_4674_2
    lsls r0, r2, #0x1e
    lsrs r0, r0, #0x1e
    mov r1, sl
    ands r0, r1
    movs r1, #4
    rsbs r1, r1, #0
    add r4, sp, #0x348
    ldrb r4, [r4]
    ands r1, r4
    orrs r1, r0
    adds r0, #1
    mov r5, sl
    ands r0, r5
    movs r4, #4
    rsbs r4, r4, #0
    ands r1, r4
    orrs r1, r0
    add r5, sp, #0x348
    strb r1, [r5]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    mov r0, sl
    ands r1, r0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #1]
    movs r0, #0
.Lraw_game_state_4674_2:
    mov r1, ip
    ands r0, r1
    lsls r2, r0, #2
    ldrb r1, [r3, #1]
    movs r0, #0x7d
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r3, #1]
    add r3, sp, #0x34c
    ldrb r0, [r3]
    movs r3, #4
    rsbs r3, r3, #0
    ands r0, r3
    movs r4, #0x7d
    rsbs r4, r4, #0
    ands r0, r4
    add r5, sp, #0x34c
    strb r0, [r5]
    ldr r2, [r6]
    movs r3, #0
    ldrb r1, [r2, #1]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    bne .Lraw_game_state_4677_8
    movs r3, #1
.Lraw_game_state_4677_8:
    cmp r3, #0
    beq .Lauto_0801EA98
    adds r4, r2, #0
    ldrb r3, [r4]
    lsls r0, r3, #0x1d
    lsrs r0, r0, #0x1d
    adds r2, r0, #1
    cmp r2, #6
    bls .Lraw_game_state_4679_14
    movs r2, #0
    lsrs r1, r3, #3
    cmp r1, #0x1c
    bhi .Lraw_game_state_4679_14
    adds r1, #1
    lsls r1, r1, #3
    movs r0, #7
    ands r0, r3
    orrs r0, r1
    strb r0, [r4]
.Lraw_game_state_4679_14:
    movs r0, #7
    ands r2, r0
    ldrb r0, [r4]
    movs r3, #8
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4]
    .Lauto_0801EA98:
    movs r0, #1
    .Lauto_0801EA9A:
    cmp r0, #0
    bne .Lauto_0801EAA0
    b .Lauto_0801E960
    .Lauto_0801EAA0:
    movs r0, #1
    mov r4, r8
    strb r0, [r4, #4]
    add r4, sp, #0x198
    ldr r5, [sp, #0x344]
    cmp r4, r5
    beq .Lauto_0801EAC0
    .Lauto_0801EAAE:
    ldm r4!, {r0}
    ldr r1, [r0, #0x14]
    ldr r2, [r1, #0x18]
    mov r1, r8
    bl _call_via_r2
    ldr r0, [sp, #0x344]
    cmp r4, r0
    bne .Lauto_0801EAAE
    .Lauto_0801EAC0:
    ldr r1, [sp, #0x330]
    ldrh r2, [r1]
    ldr r0, .Lraw_game_state_4795_4
    ldr r4, [sp, #0x334]
    ldrh r3, [r4]
    adds r1, r0, #0
    ands r1, r2
    ands r0, r3
    cmp r1, r0
    beq .Lauto_0801EAD6
    b .Lauto_0801E958
    .Lauto_0801EAD6:
    ldr r4, [sp, #0x33c]
    ldr r5, [sp, #0x340]
    cmp r4, r5
    beq .Lauto_0801EAF6
    .Lauto_0801EADE:
    ldr r2, [r4]
    cmp r2, #0
    beq .Lauto_0801EAEE
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x10]
    adds r0, r2, #0
    bl _call_via_r1
    .Lauto_0801EAEE:
    adds r4, #4
    ldr r0, [sp, #0x340]
    cmp r4, r0
    bne .Lauto_0801EADE
    .Lauto_0801EAF6:
    ldr r1, [sp, #0x338]
    cmp r1, #0
    beq .Lauto_0801EB0C
    ldr r0, [r7]
    movs r3, #0x92
    lsls r3, r3, #1
    adds r0, r0, r3
    ldr r1, [r0]
    adds r0, r7, #0
    bl _call_via_r1
    .Lauto_0801EB0C:
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne .Lauto_0801EB36
    movs r4, #0x82
    lsls r4, r4, #5
    adds r0, r7, r4
    ldr r0, [r0]
    ldr r2, [r0]
    lsls r1, r2, #0xb
    lsrs r1, r1, #0x1b
    lsls r2, r2, #5
    lsrs r2, r2, #0x1a
    adds r0, r7, #0
    movs r3, #0
    bl UpdateWorldTimeOfDayPalettes

    .Lauto_0801EB36:
    ldr r0, [r7, #8]
    ldr r1, [r0, #0x14]
    adds r1, #0xa4
    ldr r1, [r1]
    bl _call_via_r1
    ldr r5, .Lraw_game_state_4795_8
    adds r0, r7, r5
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801EB6C
    ldr r1, .Lraw_game_state_4795_12
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r3, .Lraw_game_state_4796_0
    adds r0, r0, r3
    bl HasRegisteredEvents__C14GameEventState
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lauto_0801EB6C
    adds r0, r7, #0
    bl UpdateWorldBackgroundAudio
    .Lauto_0801EB6C:
    movs r3, #0xd4
    lsls r3, r3, #2
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Lraw_game_state_4795_0: .word 0xFFFFF81F
.Lraw_game_state_4795_4: .word 0x000007FF
.Lraw_game_state_4795_8: .word 0x00001054
.Lraw_game_state_4795_12: .word 0x00001038
.Lraw_game_state_4796_0: .word 0x0000214C
    .global func_0801EE00
    .thumb_func
func_0801EE00:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov sl, r0
    mov sb, r1
    adds r7, r2, #0
    ldr r1, [r0]
    mov r0, sb
    ldrh r2, [r0]
    lsls r2, r2, #0x16
    lsrs r2, r2, #0x16
    add r0, sp, #0xc
    ldr r3, [r1, #0x34]
    mov r1, sl
    bl _call_via_r3
    mov r1, sb
    ldrb r0, [r1, #1]
    lsrs r0, r0, #2
    ldrh r1, [r1, #2]
    ldr r3, .Lraw_game_state_4835_8
    ands r1, r3
    lsls r1, r1, #6
    orrs r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r2, sb
    ldrb r0, [r2, #3]
    lsrs r0, r0, #2
    ldrh r2, [r2, #4]
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    add r0, sp, #0xc
    bl IsMapTerrainFlag1Footprint
    movs r1, #1
    eors r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x2c]
    movs r3, #0
    str r3, [sp, #0x30]
    movs r6, #1
    mov r4, sp
    adds r4, #0x28
    str r4, [sp, #0x38]
    mov r0, sp
    adds r0, #8
    str r0, [sp, #0x34]
    ldr r1, [sp, #0x2c]
    cmp r1, #0
    beq .Lraw_game_state_4825_14
    b .Lraw_game_state_4851_0
.Lraw_game_state_4825_14:
    mov r2, sl
    ldr r0, [r2]
    movs r3, #0xa6
    lsls r3, r3, #1
    adds r0, r0, r3
    ldr r1, [r0]
    mov r0, sl
    bl _call_via_r1
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .Lraw_game_state_4830_10
.Lraw_game_state_4827_8:
    ldr r0, [r4]
    bl IsUnpaused__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_4835_12
    adds r4, #4
    cmp r4, r5
    bne .Lraw_game_state_4827_8
.Lraw_game_state_4830_10:
    subs r0, r5, #4
    ldr r0, [r0]
.Lraw_game_state_4830_14:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    mov r0, sb
    bl GetFieldPlotPositionRuleResult
    cmp r0, #2
    beq .Lraw_game_state_4848_0
    cmp r0, #2
    bgt .Lraw_game_state_4836_0
    cmp r0, #0
    beq .Lraw_game_state_4848_12
    b .Lraw_game_state_4851_0
.Lraw_game_state_4835_8: .word 0x000003FF
.Lraw_game_state_4835_12:
    ldr r0, [r4]
    b .Lraw_game_state_4830_14
.Lraw_game_state_4836_0:
    cmp r0, #4
    beq .Lraw_game_state_4836_10
    cmp r0, #6
    beq .Lraw_game_state_4840_8
    b .Lraw_game_state_4851_0
.Lraw_game_state_4836_10:
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .Lraw_game_state_4851_0
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #0xa0
    bne .Lraw_game_state_4851_0
    ldr r0, .Lraw_game_state_4840_4
    add r0, sl
    ldr r0, [r0]
    bl SetFlag4__18GameStateSaveImage
    b .Lraw_game_state_4851_0
    .align 2, 0
.Lraw_game_state_4840_4: .word 0x00001038
.Lraw_game_state_4840_8:
    movs r5, #0
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .Lraw_game_state_4843_12
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #0xe
    ble .Lraw_game_state_4843_12
    add r4, sp, #0x10
    adds r0, r4, #0
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    adds r0, r4, #0
    bl GetId__C4Food
    cmp r0, #0x14
    bgt .Lraw_game_state_4843_12
    movs r5, #1
.Lraw_game_state_4843_12:
    cmp r5, #0
    beq .Lraw_game_state_4851_0
    mov r4, sl
    ldr r6, [r4, #8]
    ldr r0, [r6, #0x14]
    mov r8, r0
    add r5, sp, #0x14
    add r4, sp, #0x18
    adds r0, r4, #0
    movs r1, #0x15
    bl __4FoodUi
    ldrb r1, [r4]
    mov r0, sp
    adds r0, #0x19
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r0, r1
    mov r1, sp
    adds r1, #0x1a
    ldrb r1, [r1]
    lsls r1, r1, #0x10
    orrs r1, r0
    adds r0, r5, #0
    bl __12RucksackItemG4Food
    mov r1, r8
    ldr r3, [r1, #0x5c]
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #0
    bl _call_via_r3
    b .Lraw_game_state_4850_14
.Lraw_game_state_4848_0:
    ldr r2, .Lraw_game_state_4848_8
    str r2, [sp, #0x30]
    b .Lraw_game_state_4850_14
    .align 2, 0
.Lraw_game_state_4848_8: .word 0x0000023B
.Lraw_game_state_4848_12:
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .Lraw_game_state_4851_0
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #2
    bne .Lraw_game_state_4851_0
    movs r3, #0x8f
    lsls r3, r3, #2
    str r3, [sp, #0x30]
.Lraw_game_state_4850_14:
    movs r6, #0
.Lraw_game_state_4851_0:
    ldr r4, [sp, #0x30]
    cmp r4, #0
    beq .Lraw_game_state_4853_0
    mov r1, sl
    ldr r0, [r1]
    movs r2, #0xa0
    lsls r2, r2, #1
    adds r0, r0, r2
    add r1, sp, #0x1c
    movs r2, #0
    str r4, [sp, #0x1c]
    str r2, [r1, #4]
    ldr r3, [r0]
    mov r0, sl
    bl _call_via_r3
.Lraw_game_state_4853_0:
    cmp r6, #0
    beq .Lraw_game_state_4854_8
    ldr r0, .Lraw_game_state_4857_4
    add r0, sl
    ldr r2, [r0]
    ldr r3, .Lraw_game_state_4857_8
    adds r0, r2, r3
    ldr r4, .Lraw_game_state_4857_12
    adds r2, r2, r4
    mov r1, sb
    bl func_080A1484
.Lraw_game_state_4854_8:
    adds r0, r7, #0
    bl IsWrapped__C12RucksackItem
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lraw_game_state_4861_2
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    beq .Lraw_game_state_4856_2
    cmp r0, #1
    beq .Lraw_game_state_4858_0
.Lraw_game_state_4856_2:
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetIconId__C4Food
    b .Lraw_game_state_4859_10
    .align 2, 0
.Lraw_game_state_4857_4: .word 0x00001038
.Lraw_game_state_4857_8: .word 0x00001CD4
.Lraw_game_state_4857_12: .word 0x0000214C
.Lraw_game_state_4858_0:
    adds r0, r7, #0
    bl GetArticle__C12RucksackItem
    add r4, sp, #0x24
    strb r0, [r4]
    adds r0, r4, #0
    bl GetId__C7Article
    cmp r0, #0x1b
    beq .Lraw_game_state_4860_0
    adds r0, r4, #0
    bl GetIconId__C7Article
.Lraw_game_state_4859_10:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    b .Lraw_game_state_4861_6
.Lraw_game_state_4860_0:
    mov r1, sb
    ldrh r0, [r1]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    movs r5, #3
    cmp r0, #8
    bgt .Lraw_game_state_4861_6
    movs r5, #4
    b .Lraw_game_state_4861_6
.Lraw_game_state_4861_2:
    movs r5, #0xb0
    lsls r5, r5, #1
.Lraw_game_state_4861_6:
    mov r2, sb
    ldrb r0, [r2, #1]
    lsrs r0, r0, #2
    ldrh r2, [r2, #2]
    ldr r3, .Lraw_game_state_4875_0
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    mov r4, sb
    ldrb r1, [r4, #3]
    lsrs r1, r1, #2
    ldrh r0, [r4, #4]
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    add r1, sp, #0x28
    strh r2, [r1]
    ldr r1, [sp, #0x38]
    strh r0, [r1, #2]
    mov r2, sl
    ldr r0, [r2]
    ldr r1, [r0, #0x64]
    mov r0, sl
    bl _call_via_r1
    ldr r4, .Lraw_game_state_4875_4
    add r4, sl
    adds r6, r0, #0
    adds r7, r5, #0
    ldr r0, [sp, #0x28]
    str r0, [r4, #4]
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_4867_0
    cmp r1, #0
    beq .Lraw_game_state_4867_0
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_4867_0:
    str r5, [r4]
    add r3, sp, #0x2c
    ldrb r3, [r3]
    strb r3, [r4, #8]
    ldr r5, [sp, #0x2c]
    cmp r5, #0
    beq .Lraw_game_state_4875_8
    movs r0, #0x40
    bl __builtin_new
    movs r1, #2
    str r1, [sp]
    movs r1, #3
    str r1, [sp, #4]
    movs r1, #0
    ldr r2, [sp, #0x34]
    strb r1, [r2]
    adds r1, r6, #0
    adds r2, r7, #0
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    adds r5, r0, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_4874_4
    cmp r1, #0
    beq .Lraw_game_state_4874_4
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_4874_4:
    str r5, [r4]
    movs r1, #0
    movs r0, #0x10
    strb r0, [r4, #9]
    strb r1, [r4, #0xa]
    b .Lraw_game_state_4882_0
.Lraw_game_state_4875_0: .word 0x000003FF
.Lraw_game_state_4875_4: .word 0x0000102C
.Lraw_game_state_4875_8:
    movs r0, #0x40
    bl __builtin_new
    movs r1, #2
    str r1, [sp]
    movs r1, #3
    str r1, [sp, #4]
    ldr r3, [sp, #0x34]
    strb r5, [r3]
    adds r1, r6, #0
    ldr r2, .Lraw_game_state_4883_0
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    adds r5, r0, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_4881_12
    cmp r1, #0
    beq .Lraw_game_state_4881_12
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_4881_12:
    str r5, [r4]
    movs r0, #0
.Lraw_game_state_4882_0:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Lraw_game_state_4883_0: .word 0x000001A9
    .global RefreshWorldFireplaceSprite
    .thumb_func
RefreshWorldFireplaceSprite:
    push {r4, r5, r6, lr}
    sub sp, #0xc
    adds r6, r0, #0
    movs r0, #0x83
    lsls r0, r0, #5
    adds r1, r6, r0
    movs r0, #0
    strb r0, [r1]
    ldr r1, .Lworld_construction_jp_0801F198 @ =0x0000105C
    adds r4, r6, r1
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lworld_construction_jp_0801F178
    cmp r1, #0
    beq .Lworld_construction_jp_0801F178
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lworld_construction_jp_0801F178:
    str r5, [r4]
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    subs r0, #0xa
    cmp r0, #0x1d
    bls .Lworld_construction_jp_0801F18C
    b .Lworld_construction_jp_0801F2CA
.Lworld_construction_jp_0801F18C:
    lsls r0, r0, #2
    ldr r1, .Lworld_construction_jp_0801F19C @ =.Lworld_construction_jp_0801F1A0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Lworld_construction_jp_0801F198: .4byte 0x0000105C
.Lworld_construction_jp_0801F19C: .4byte .Lworld_construction_jp_0801F1A0
.Lworld_construction_jp_0801F1A0: @ jump table
    .4byte .Lworld_construction_jp_0801F26C @ case 0
    .4byte .Lworld_construction_jp_0801F2CA @ case 1
    .4byte .Lworld_construction_jp_0801F2CA @ case 2
    .4byte .Lworld_construction_jp_0801F2CA @ case 3
    .4byte .Lworld_construction_jp_0801F2CA @ case 4
    .4byte .Lworld_construction_jp_0801F2CA @ case 5
    .4byte .Lworld_construction_jp_0801F2CA @ case 6
    .4byte .Lworld_construction_jp_0801F2CA @ case 7
    .4byte .Lworld_construction_jp_0801F248 @ case 8
    .4byte .Lworld_construction_jp_0801F2CA @ case 9
    .4byte .Lworld_construction_jp_0801F2CA @ case 10
    .4byte .Lworld_construction_jp_0801F2CA @ case 11
    .4byte .Lworld_construction_jp_0801F2CA @ case 12
    .4byte .Lworld_construction_jp_0801F2CA @ case 13
    .4byte .Lworld_construction_jp_0801F2CA @ case 14
    .4byte .Lworld_construction_jp_0801F2CA @ case 15
    .4byte .Lworld_construction_jp_0801F2CA @ case 16
    .4byte .Lworld_construction_jp_0801F26C @ case 17
    .4byte .Lworld_construction_jp_0801F2CA @ case 18
    .4byte .Lworld_construction_jp_0801F218 @ case 19
    .4byte .Lworld_construction_jp_0801F2CA @ case 20
    .4byte .Lworld_construction_jp_0801F2CA @ case 21
    .4byte .Lworld_construction_jp_0801F2CA @ case 22
    .4byte .Lworld_construction_jp_0801F2CA @ case 23
    .4byte .Lworld_construction_jp_0801F2CA @ case 24
    .4byte .Lworld_construction_jp_0801F2CA @ case 25
    .4byte .Lworld_construction_jp_0801F2CA @ case 26
    .4byte .Lworld_construction_jp_0801F2CA @ case 27
    .4byte .Lworld_construction_jp_0801F2CA @ case 28
    .4byte .Lworld_construction_jp_0801F258 @ case 29
.Lworld_construction_jp_0801F218:
    ldr r0, .Lworld_construction_jp_0801F244 @ =0x00001038
    adds r4, r6, r0
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #2
    bne .Lworld_construction_jp_0801F2CA
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl IsFireplaceLighted__C9FarmHouse
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    b .Lworld_construction_jp_0801F280
    .align 2, 0
.Lworld_construction_jp_0801F244: .4byte 0x00001038
.Lworld_construction_jp_0801F248:
    ldr r1, .Lworld_construction_jp_0801F254 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    ldrb r0, [r0, #3]
    lsrs r5, r0, #7
    b .Lworld_construction_jp_0801F280
    .align 2, 0
.Lworld_construction_jp_0801F254: .4byte 0x00001038
.Lworld_construction_jp_0801F258:
    ldr r1, .Lworld_construction_jp_0801F268 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1f
    lsrs r5, r0, #0x1f
    b .Lworld_construction_jp_0801F280
    .align 2, 0
.Lworld_construction_jp_0801F268: .4byte 0x00001038
.Lworld_construction_jp_0801F26C:
    ldr r1, .Lworld_construction_jp_0801F2D4 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    movs r5, #0
    cmp r0, #3
    bne .Lworld_construction_jp_0801F280
    movs r5, #1
.Lworld_construction_jp_0801F280:
    movs r0, #0x40
    bl __builtin_new
    adds r4, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x60]
    adds r0, r6, #0
    bl _call_via_r1
    adds r1, r0, #0
    movs r0, #2
    str r0, [sp]
    movs r0, #0x1b
    str r0, [sp, #4]
    add r2, sp, #8
    movs r0, #0
    strb r0, [r2]
    adds r0, r4, #0
    adds r2, r5, #0
    adds r3, r6, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    ldr r1, .Lworld_construction_jp_0801F2D8 @ =0x0000105C
    adds r5, r6, r1
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lworld_construction_jp_0801F2C8
    cmp r1, #0
    beq .Lworld_construction_jp_0801F2C8
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lworld_construction_jp_0801F2C8:
    str r4, [r5]
.Lworld_construction_jp_0801F2CA:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
.Lworld_construction_jp_0801F2D4: .4byte 0x00001038
.Lworld_construction_jp_0801F2D8: .4byte 0x0000105C

    .global RefreshWorldBeachHouseSprite
    .thumb_func
RefreshWorldBeachHouseSprite:
    push {r4, r5, lr}
    sub sp, #0xc
    adds r4, r0, #0
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    cmp r0, #0x23
    bne .Lworld_construction_jp_0801F3B8
    ldr r1, .Lworld_construction_jp_0801F320 @ =0x00001038
    adds r0, r4, r1
    ldr r0, [r0]
    ldrb r0, [r0, #0x12]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1b
    cmp r0, #3
    bls .Lworld_construction_jp_0801F370
    cmp r0, #8
    bhi .Lworld_construction_jp_0801F328
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .Lworld_construction_jp_0801F324 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #0
    b .Lworld_construction_jp_0801F38A
    .align 2, 0
.Lworld_construction_jp_0801F320: .4byte 0x00001038
.Lworld_construction_jp_0801F324: .4byte 0x00000FF4
.Lworld_construction_jp_0801F328:
    cmp r0, #0xf
    bhi .Lworld_construction_jp_0801F34C
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .Lworld_construction_jp_0801F348 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #1
    b .Lworld_construction_jp_0801F38A
    .align 2, 0
.Lworld_construction_jp_0801F348: .4byte 0x00000FF4
.Lworld_construction_jp_0801F34C:
    cmp r0, #0x12
    bhi .Lworld_construction_jp_0801F370
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .Lworld_construction_jp_0801F36C @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #2
    b .Lworld_construction_jp_0801F38A
    .align 2, 0
.Lworld_construction_jp_0801F36C: .4byte 0x00000FF4
.Lworld_construction_jp_0801F370:
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .Lworld_construction_jp_0801F3B0 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #3
.Lworld_construction_jp_0801F38A:
    adds r3, r4, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    ldr r1, .Lworld_construction_jp_0801F3B4 @ =0x00001064
    adds r5, r4, r1
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lworld_construction_jp_0801F3AC
    cmp r1, #0
    beq .Lworld_construction_jp_0801F3AC
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lworld_construction_jp_0801F3AC:
    str r4, [r5]
    b .Lworld_construction_jp_0801F3D6
    .align 2, 0
.Lworld_construction_jp_0801F3B0: .4byte 0x00000FF4
.Lworld_construction_jp_0801F3B4: .4byte 0x00001064
.Lworld_construction_jp_0801F3B8:
    ldr r2, .Lworld_construction_jp_0801F3E0 @ =0x00001064
    adds r4, r4, r2
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lworld_construction_jp_0801F3D4
    cmp r1, #0
    beq .Lworld_construction_jp_0801F3D4
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lworld_construction_jp_0801F3D4:
    str r5, [r4]
.Lworld_construction_jp_0801F3D6:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.Lworld_construction_jp_0801F3E0: .4byte 0x00001064

    .global RefreshWorldVase
    .thumb_func
    RefreshWorldVase:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x40
    adds r6, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    cmp r0, #0x1d
    bne .Lauto_0801F27C
    ldr r1, .Lraw_game_state_5264_0
    adds r0, r6, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetVaseArticleId__C9FarmHouse
    adds r1, r0, #0
    cmp r1, #0x5f
    beq .Lauto_0801F29A
    add r4, sp, #0x34
    adds r0, r4, #0
    bl __7ArticleUi
    adds r0, r4, #0
    bl GetIconId__C7Article
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldr r3, .Lraw_game_state_5264_4
    adds r3, r3, r6
    mov sb, r3
    ldr r4, [r3]
    cmp r4, #0
    beq .Lauto_0801F224
    ldr r0, [r6]
    ldr r1, [r0, #0x64]
    adds r0, r6, #0
    bl _call_via_r1
    adds r1, r0, #0
    add r0, sp, #0x20
    adds r2, r7, #0
    movs r3, #0x80
    lsls r3, r3, #1
    bl __21IndexedResourceHandleP23IndexedResourceProviderUii
    add r0, sp, #0x20
    ldr r1, [sp, #0x20]
    ldr r3, [r1]
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    ldr r0, [sp, #0x24]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sp
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sp
    mov r1, sp
    movs r2, #0x20
    bl memcpy
    adds r1, r4, #0
    adds r1, #0x28
    mov r0, sp
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r5}
    stm r1!, {r2, r5}
    adds r1, r4, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    b .Lauto_0801F29A
.Lraw_game_state_5264_0: .word 0x00001038
.Lraw_game_state_5264_4: .word 0x00001068
    .Lauto_0801F224:
    movs r0, #0x4c
    bl __builtin_new
    adds r5, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x64]
    adds r0, r6, #0
    bl _call_via_r1
    adds r4, r0, #0
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .Lraw_game_state_5303_0
    str r0, [r5, #0x24]
    movs r3, #0x28
    adds r3, r3, r5
    mov r8, r3
    ldr r6, [r4]
    add r0, sp, #0x38
    ldr r3, [r6, #0xc]
    adds r1, r4, #0
    adds r2, r7, #0
    bl _call_via_r3
    ldr r0, [sp, #0x38]
    ldrh r2, [r0]
    mov r0, r8
    ldr r3, [r6, #0x10]
    adds r1, r4, #0
    bl _call_via_r3
    adds r1, r5, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    mov r4, sb
    b .Lauto_0801F282
    .align 2, 0
.Lraw_game_state_5303_0: .4byte __vt_20GameSceneGroupSprite
    .Lauto_0801F27C:
    ldr r5, .Lraw_game_state_5329_0
    adds r4, r6, r5
    movs r5, #0
    .Lauto_0801F282:
    ldr r1, [r4]
    cmp r5, r1
    beq .Lauto_0801F298
    cmp r1, #0
    beq .Lauto_0801F298
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801F298:
    str r5, [r4]
    .Lauto_0801F29A:
    add sp, #0x40
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Lraw_game_state_5329_0: .word 0x00001068
    .section .text.world_shipping_after, "ax", %progbits

    .global SetWorldWeatherEffect
    .thumb_func
SetWorldWeatherEffect:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    adds r4, r0, #0
    adds r6, r1, #0
    movs r0, #0
    mov r8, r0
    cmp r6, #0
    beq .Lworld_construction_jp_0801FAEC
    cmp r6, #1
    bne .Lworld_construction_jp_0801FAF2
    ldr r1, .Lworld_construction_jp_0801FAE8 @ =0x00000ED4
    adds r1, r1, r4
    mov r8, r1
    b .Lworld_construction_jp_0801FAF2
    .align 2, 0
.Lworld_construction_jp_0801FAE8: .4byte 0x00000ED4
.Lworld_construction_jp_0801FAEC:
    ldr r0, .Lworld_construction_jp_0801FB38 @ =0x00000EA4
    adds r0, r0, r4
    mov r8, r0
.Lworld_construction_jp_0801FAF2:
    mov r1, r8
    cmp r1, #0
    beq .Lworld_construction_jp_0801FB68
    movs r7, #0x20
    ldr r0, [r4, #4]
    ldr r5, [r0]
    cmp r5, #2
    bne .Lworld_construction_jp_0801FB3E
    movs r3, #0
    adds r1, r4, #0
    adds r1, #8
    movs r0, #0xcc
    lsls r0, r0, #1
    adds r2, r4, r0
    cmp r1, r2
    beq .Lworld_construction_jp_0801FB26
.Lworld_construction_jp_0801FB12:
    ldr r0, [r1]
    cmp r0, #0
    beq .Lworld_construction_jp_0801FB20
    ldrh r0, [r0, #4]
    cmp r0, r5
    bne .Lworld_construction_jp_0801FB20
    adds r3, #1
.Lworld_construction_jp_0801FB20:
    adds r1, #4
    cmp r1, r2
    bne .Lworld_construction_jp_0801FB12
.Lworld_construction_jp_0801FB26:
    adds r0, r3, #0
    adds r0, #0xa
    cmp r0, #0xa
    bls .Lworld_construction_jp_0801FB3E
    cmp r3, #0x15
    bhi .Lworld_construction_jp_0801FB3C
    movs r0, #0x20
    subs r7, r0, r3
    b .Lworld_construction_jp_0801FB3E
    .align 2, 0
.Lworld_construction_jp_0801FB38: .4byte 0x00000EA4
.Lworld_construction_jp_0801FB3C:
    movs r7, #0xa
.Lworld_construction_jp_0801FB3E:
    ldr r0, .Lworld_construction_jp_0801FB74 @ =0x0000046C
    bl __builtin_new
    str r7, [sp]
    adds r1, r4, #0
    mov r2, r8
    adds r3, r6, #0
    bl __22GameSceneWeatherEffectP10GameObjectP23IndexedResourceProviderQ222GameSceneWeatherEffect4KindUi
    ldr r1, .Lworld_construction_jp_0801FB78 @ =0x0000107C
    adds r5, r4, r1
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .Lworld_construction_jp_0801FB66
    cmp r0, #0
    beq .Lworld_construction_jp_0801FB66
    movs r1, #3
    bl _._22GameSceneWeatherEffect
.Lworld_construction_jp_0801FB66:
    str r4, [r5]
.Lworld_construction_jp_0801FB68:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lworld_construction_jp_0801FB74: .4byte 0x0000046C
.Lworld_construction_jp_0801FB78: .4byte 0x0000107C

    .else

    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED


    .section .text.game_state_after_startup_accessors
    thumb_func_start DayUpdate__18GameStateSaveImage
DayUpdate__18GameStateSaveImage: @ US 0x08010F54
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r6, r0, #0
    ldrb r1, [r6]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r6]
    ldr r0, [r6, #0xc]
    str r0, [r6, #8]
    ldrb r0, [r6, #0x11]
    lsls r1, r0, #0x1e
    movs r3, #3
    lsrs r1, r1, #0x1e
    movs r4, #4
    rsbs r4, r4, #0
    adds r2, r4, #0
    mov r5, sb
    ands r2, r5
    orrs r2, r1
    mov sb, r2
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    adds r5, r0, #1
    cmp r0, #0x1e
    bne .L08010FA2
    lsls r0, r2, #0x1e
    lsrs r0, r0, #0x1e
    adds r0, #1
    ands r0, r3
    ands r2, r4
    orrs r2, r0
    mov sb, r2
    movs r5, #1
.L08010FA2:
    movs r0, #0
    mov r8, r0
    movs r2, #0
    movs r1, #0x14
    adds r1, r1, r6
    mov sl, r1
    adds r0, r6, #0
    adds r0, #0x11
    str r0, [sp, #0x18]
    adds r1, r6, #0
    adds r1, #8
    str r1, [sp, #0x14]
    mov r1, sb
    lsls r0, r1, #0x1e
    lsrs r3, r0, #0x1e
    ldr r4, .L080110EC @ =gMandatorySunnyCalendarDates
.L08010FC2:
    adds r0, r2, r4
    ldrb r1, [r0]
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r3, r0
    bne .L08010FDA
    lsls r0, r1, #0x19
    lsrs r0, r0, #0x1b
    cmp r5, r0
    bne .L08010FDA
    movs r0, #1
    mov r8, r0
.L08010FDA:
    adds r2, #1
    cmp r2, #0x18
    ble .L08010FC2
    ldr r1, .L080110F0 @ =0x00001CD4
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetPartnerCharacterId__C13NpcCollection
    cmp r0, #0
    bne .L08011056
    adds r0, r4, #0
    bl GetWeddingDate__C13NpcCollection
    adds r4, r0, #0
    mov ip, r4
    movs r3, #0xc8
    str r3, [sp, #4]
    ldrb r0, [r6, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #8]
    add r0, sp, #8
    add r2, sp, #4
    cmp r3, r1
    bls .L08011016
    adds r2, r0, #0
.L08011016:
    ldr r7, [r2]
    str r3, [sp, #0xc]
    ldrb r0, [r4]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #0x10]
    add r2, sp, #0x10
    add r0, sp, #0xc
    cmp r3, r1
    bls .L08011034
    adds r0, r2, #0
.L08011034:
    ldr r0, [r0]
    cmp r7, r0
    bne .L08011056
    mov r0, sb
    lsls r1, r0, #0x1e
    mov r0, ip
    ldrb r2, [r0, #1]
    lsls r0, r2, #0x1e
    cmp r1, r0
    bne .L08011056
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    cmp r5, r0
    bne .L08011056
    movs r1, #1
    mov r8, r1
.L08011056:
    ldr r5, .L080110F4 @ =0x00001D6C
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .L08011072
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .L08011072
    movs r0, #1
    mov r8, r0
.L08011072:
    ldr r1, .L080110F8 @ =0x00001E28
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .L0801108E
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .L0801108E
    movs r5, #1
    mov r8, r5
.L0801108E:
    ldr r0, .L080110FC @ =0x00001EB8
    adds r4, r6, r0
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .L080110AA
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .L080110AA
    movs r1, #1
    mov r8, r1
.L080110AA:
    ldr r5, .L08011100 @ =0x00001EE4
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .L080110C6
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .L080110C6
    movs r0, #1
    mov r8, r0
.L080110C6:
    ldr r1, .L08011104 @ =0x00001F38
    adds r4, r6, r1
    adds r0, r4, #0
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bne .L080110E2
    adds r0, r4, #0
    bl GetDaysSinceRivalEvent__C12Bachelorette
    cmp r0, #5
    bne .L080110E2
    movs r5, #1
    mov r8, r5
.L080110E2:
    mov r0, r8
    cmp r0, #1
    bne .L08011108
    movs r0, #0
    b .L0801116A
    .align 2, 0
.L080110EC: .4byte gMandatorySunnyCalendarDates
.L080110F0: .4byte 0x00001CD4
.L080110F4: .4byte 0x00001D6C
.L080110F8: .4byte 0x00001E28
.L080110FC: .4byte 0x00001EB8
.L08011100: .4byte 0x00001EE4
.L08011104: .4byte 0x00001F38
.L08011108:
    bl rand
    asrs r2, r0, #2
    movs r0, #0xff
    ands r2, r0
    mov r1, sb
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .L08011138
    cmp r0, #1
    bgt .L08011126
    cmp r0, #0
    beq .L08011130
    b .L0801116C
.L08011126:
    cmp r0, #2
    beq .L0801114A
    cmp r0, #3
    beq .L08011156
    b .L0801116C
.L08011130:
    cmp r2, #0xb3
    bls .L0801116A
    movs r0, #1
    b .L0801116A
.L08011138:
    cmp r2, #0xe5
    bhi .L08011140
    movs r0, #0
    b .L0801116A
.L08011140:
    subs r2, #0xe6
    cmp r2, #0xc
    bls .L0801116A
    movs r0, #3
    b .L0801116A
.L0801114A:
    cmp r2, #0xcd
    bhi .L08011152
    movs r0, #0
    b .L0801116A
.L08011152:
    movs r0, #1
    b .L0801116A
.L08011156:
    cmp r2, #0x7f
    bhi .L0801115E
    movs r0, #0
    b .L0801116A
.L0801115E:
    subs r2, #0x80
    cmp r2, #0x65
    bhi .L08011168
    movs r0, #2
    b .L0801116A
.L08011168:
    movs r0, #4
.L0801116A:
    str r0, [r6, #0xc]
.L0801116C:
    ldr r1, [r6, #8]
    mov r0, sl
    ldr r2, [sp, #0x18]
    bl DayUpdate__4FarmiRC8GameDate
    ldrb r1, [r6, #0x11]
    lsls r0, r1, #0x19
    lsrs r0, r0, #0x1b
    cmp r0, #0
    bne .L080111A0
    lsls r0, r1, #0x1e
    lsrs r7, r0, #0x1e
    ldr r5, .L08011200 @ =0x000009DC
    adds r4, r6, r5
    ldr r1, .L08011204 @ =0x00001AA8
    adds r0, r6, r1
    cmp r4, r0
    bhs .L080111A0
    adds r5, r0, #0
.L08011192:
    adds r0, r4, #0
    adds r1, r7, #0
    bl method_0800AB08__9FieldPlot6Season
    adds r4, #4
    cmp r4, r5
    blo .L08011192
.L080111A0:
    ldr r0, .L08011208 @ =0x00001BD8
    adds r5, r6, r0
    adds r0, r5, #0
    bl func_0800EE60
    ldr r1, .L0801120C @ =0x00001C70
    adds r0, r6, r1
    bl DayUpdate__3Dog
    ldr r1, .L08011210 @ =0x00002C74
    adds r0, r6, r1
    bl UpdateTVShoppingDeliveryCountdown
    ldr r0, .L08011214 @ =0x00001CD4
    adds r4, r6, r0
    ldr r1, .L08011218 @ =0x0000214C
    adds r2, r6, r1
    mov r0, sl
    str r0, [sp]
    adds r0, r4, #0
    ldr r1, [sp, #0x14]
    adds r3, r5, #0
    bl DayUpdate__13NpcCollectionRC14GameStateClockRC14GameEventStateRC6FarmerRC4Farm
    adds r0, r4, #0
    adds r1, r6, #0
    bl InitializeSchedules__13NpcCollectionRC18GameStateSaveImage
    ldr r1, .L0801121C @ =0x00001F64
    adds r4, r6, r1
    adds r0, r4, #0
    bl IsConstructionComplete__C4Gotz
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080111EA
    b .L08011328
.L080111EA:
    adds r0, r4, #0
    bl GetConstruction__C4Gotz
    cmp r0, #0xd
    bls .L080111F6
    b .L08011318
.L080111F6:
    lsls r0, r0, #2
    ldr r1, .L08011220 @ =.L08011224
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08011200: .4byte 0x000009DC
.L08011204: .4byte 0x00001AA8
.L08011208: .4byte 0x00001BD8
.L0801120C: .4byte 0x00001C70
.L08011210: .4byte 0x00002C74
.L08011214: .4byte 0x00001CD4
.L08011218: .4byte 0x0000214C
.L0801121C: .4byte 0x00001F64
.L08011220: .4byte .L08011224
.L08011224: @ jump table
    .4byte .L08011318 @ case 0
    .4byte .L0801125C @ case 1
    .4byte .L0801127C @ case 2
    .4byte .L08011288 @ case 3
    .4byte .L08011294 @ case 4
    .4byte .L0801129C @ case 5
    .4byte .L080112AA @ case 6
    .4byte .L080112B8 @ case 7
    .4byte .L080112C6 @ case 8
    .4byte .L080112D4 @ case 9
    .4byte .L080112E2 @ case 10
    .4byte .L080112F0 @ case 11
    .4byte .L080112FE @ case 12
    .4byte .L0801130C @ case 13
.L0801125C:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r4, r6, r5
    adds r0, r4, #0
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    bhi .L08011274
    adds r0, r4, #0
    bl UpgradeHouseLevel__9FarmHouse
    b .L08011318
.L08011274:
    adds r0, r4, #0
    bl AddBathroom__9FarmHouse
    b .L08011318
.L0801127C:
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r6, r1
    bl Upgrade__4Coop
    b .L08011318
.L08011288:
    movs r5, #0xbe
    lsls r5, r5, #3
    adds r0, r6, r5
    bl Upgrade__4Barn
    b .L08011318
.L08011294:
    adds r0, r6, #0
    bl SetFlag1__18GameStateSaveImage
    b .L08011318
.L0801129C:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #0
    bl SetWindowStyle__9FarmHouseUi
    b .L08011318
.L080112AA:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #1
    bl SetWindowStyle__9FarmHouseUi
    b .L08011318
.L080112B8:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #2
    bl SetWindowStyle__9FarmHouseUi
    b .L08011318
.L080112C6:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #0
    bl SetMailboxStyle__9FarmHouseUi
    b .L08011318
.L080112D4:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #1
    bl SetMailboxStyle__9FarmHouseUi
    b .L08011318
.L080112E2:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #2
    bl SetMailboxStyle__9FarmHouseUi
    b .L08011318
.L080112F0:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #0
    bl SetDoghouseStyle__9FarmHouseUi
    b .L08011318
.L080112FE:
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r6, r5
    movs r1, #1
    bl SetDoghouseStyle__9FarmHouseUi
    b .L08011318
.L0801130C:
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r6, r1
    movs r1, #2
    bl SetDoghouseStyle__9FarmHouseUi
.L08011318:
    ldr r5, .L08011324 @ =0x00001F64
    adds r0, r6, r5
    bl FinishConstruction__4Gotz
    b .L0801132E
    .align 2, 0
.L08011324: .4byte 0x00001F64
.L08011328:
    adds r0, r4, #0
    bl UpdateConstructionWorksite__4Gotz
.L0801132E:
    ldr r0, .L08011354 @ =0x00001DAC
    adds r4, r6, r0
    adds r0, r4, #0
    bl IsOrderComplete__C7Saibara
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L080113AA
    adds r0, r4, #0
    bl GetOrder__C7Saibara
    cmp r0, #0x24
    beq .L08011378
    cmp r0, #0x24
    bgt .L08011358
    cmp r0, #0x23
    beq .L0801135E
    b .L080113AA
    .align 2, 0
.L08011354: .4byte 0x00001DAC
.L08011358:
    cmp r0, #0x25
    beq .L08011392
    b .L080113AA
.L0801135E:
    movs r1, #0x82
    lsls r1, r1, #3
    adds r4, r6, r1
    adds r0, r4, #0
    bl method_0800C5C4__C4Coop
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080113AA
    adds r0, r4, #0
    bl method_0800C888__4Coop
    b .L080113AA
.L08011378:
    movs r5, #0xbe
    lsls r5, r5, #3
    adds r4, r6, r5
    adds r0, r4, #0
    bl method_0800CF00__C4Barn
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080113AA
    adds r0, r4, #0
    bl method_0800D3A0__4Barn
    b .L080113AA
.L08011392:
    movs r0, #0xbe
    lsls r0, r0, #3
    adds r4, r6, r0
    adds r0, r4, #0
    bl method_0800CF08__C4Barn
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080113AA
    adds r0, r4, #0
    bl method_0800D3B8__4Barn
.L080113AA:
    ldrb r0, [r6, #0x11]
    lsls r0, r0, #0x19
    lsrs r0, r0, #0x1b
    cmp r0, #0
    bne .L080113C4
    ldr r1, .L080113C0 @ =0x00001AA8
    adds r0, r6, r1
    bl UpdateMoneyAccountRecordHistory
    b .L080113CC
    .align 2, 0
.L080113C0: .4byte 0x00001AA8
.L080113C4:
    ldr r5, .L08011400 @ =0x00001AA8
    adds r0, r6, r5
    bl AppendMoneyAccountRecord30
.L080113CC:
    ldr r1, .L08011404 @ =0x000034C8
    adds r0, r6, r1
    bl Reset__14FieldItemState
    ldr r5, .L08011408 @ =0x000034DC
    adds r0, r6, r5
    bl ResetActorRuntimeState
    ldrb r1, [r6, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r6, #3]
    ldrb r1, [r6, #4]
    movs r0, #2
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r6, #4]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08011400: .4byte 0x00001AA8
.L08011404: .4byte 0x000034C8
.L08011408: .4byte 0x000034DC

    .section .text.game_state_after_display_options

    thumb_func_start __18GameStateSaveImageR10SramAccessUiRUi
__18GameStateSaveImageR10SramAccessUiRUi: @ 0x08011650
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r7, r0, #0
    str r1, [sp, #0x14]
    mov sl, r2
    adds r6, r3, #0
    adds r1, r7, #0
    adds r1, #8
    movs r0, #0
    mov sb, r0
    str r0, [r7, #8]
    str r0, [r1, #4]
    mov r2, sb
    strb r2, [r1, #8]
    ldrb r2, [r1, #9]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    movs r3, #0x7d
    rsbs r3, r3, #0
    mov r8, r3
    ands r0, r3
    strb r0, [r1, #9]
    ldrb r2, [r1, #0xa]
    movs r0, #0x20
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1, #0xa]
    ldrh r2, [r1, #0xa]
    ldr r0, .L08011870 @ =0xFFFFF81F
    ands r0, r2
    strh r0, [r1, #0xa]
    adds r0, r7, #0
    adds r0, #0x14
    ldr r5, .L08011874 @ =gText_LoadError
    adds r1, r5, #0
    bl __4FarmPCc
    ldr r1, .L08011878 @ =0x00001AA8
    adds r0, r7, r1
    bl InitializeMoneyAccount
    ldr r2, .L0801187C @ =0x00001BD8
    adds r0, r7, r2
    mov r1, sp
    ldrb r1, [r1]
    ands r4, r1
    mov r1, sp
    strb r4, [r1]
    mov r3, r8
    ands r4, r3
    strb r4, [r1]
    adds r1, r5, #0
    mov r2, sp
    bl __6FarmerPCcRC8GameDate
    ldr r1, .L08011880 @ =0x00001C70
    adds r0, r7, r1
    adds r1, r5, #0
    bl __3DogPCc
    movs r2, #0xe5
    lsls r2, r2, #5
    adds r0, r7, r2
    bl __9MoreItems
    ldr r3, .L08011884 @ =0x00001CCC
    adds r1, r7, r3
    movs r4, #0x8d
    lsls r4, r4, #2
    ldrh r2, [r1]
    ldr r3, .L08011888 @ =0xFFFFFC00
    adds r0, r3, #0
    ands r0, r2
    orrs r0, r4
    strh r0, [r1]
    movs r5, #0
    ldrb r4, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r4
    strb r0, [r1, #1]
    ldrh r4, [r1, #2]
    adds r0, r3, #0
    ands r0, r4
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    strb r2, [r1, #3]
    ldrh r0, [r1, #4]
    ands r3, r0
    strh r3, [r1, #4]
    ldr r1, .L0801188C @ =0x00001CD4
    adds r0, r7, r1
    bl __13NpcCollection
    ldr r2, .L08011890 @ =0x0000214C
    adds r0, r7, r2
    bl __14GameEventState
    ldr r3, .L08011894 @ =0x000021CC
    adds r2, r7, r3
    movs r0, #1
    str r0, [r2]
    mov r0, sb
    str r0, [r2, #4]
    ldr r1, .L08011898 @ =0x000021E0
    adds r0, r7, r1
    strb r5, [r0]
    adds r3, #0x24
    adds r0, r7, r3
    strb r5, [r0]
    adds r1, #0x20
    adds r0, r7, r1
    strb r5, [r0]
    mov r3, sb
    str r3, [sp, #4]
    subs r1, #0x2c
    adds r0, r7, r1
    movs r1, #8
    add r5, sp, #8
    add r3, sp, #0xc
    mov sb, r3
    movs r3, #0
.L08011752:
    strb r3, [r0]
    subs r1, #1
    adds r0, #1
    cmp r1, #0
    bgt .L08011752
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r2, #0
    adds r0, #0x10
    movs r1, #4
    ldr r2, .L0801189C @ =0x00002C48
    adds r4, r7, r2
    ldr r3, .L080118A0 @ =0x00002C4A
    adds r3, r3, r7
    mov r8, r3
    ldr r2, [r5]
.L08011772:
    strb r2, [r0]
    subs r1, #1
    adds r0, #1
    cmp r1, #0
    bgt .L08011772
    ldr r1, .L080118A4 @ =0x00002210
    adds r0, r7, r1
    bl InitializeGameDisplayOptions
    ldr r2, .L080118A8 @ =0x00002214
    adds r0, r7, r2
    bl __22CookingRecipeInventory
    ldr r3, .L080118AC @ =0x00002C1C
    adds r2, r7, r3
    ldrb r0, [r4]
    movs r1, #3
    orrs r0, r1
    strb r0, [r4]
    ldr r0, [r2, #0x2c]
    ldr r1, .L080118B0 @ =0xFFF80003
    ands r0, r1
    str r0, [r2, #0x2c]
    mov r0, r8
    ldrb r1, [r0]
    movs r0, #9
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x11
    rsbs r1, r1, #0
    ands r0, r1
    subs r1, #0x10
    ands r0, r1
    subs r1, #0x20
    ands r0, r1
    movs r1, #0x7f
    ands r0, r1
    mov r1, r8
    strb r0, [r1]
    ldr r2, .L080118B4 @ =0x00002C4C
    adds r0, r7, r2
    movs r1, #9
    movs r2, #0
    movs r3, #1
    rsbs r3, r3, #0
.L080117CC:
    strb r2, [r0]
    strh r2, [r0, #2]
    adds r0, #4
    subs r1, #1
    cmp r1, r3
    bne .L080117CC
    ldr r3, .L080118B8 @ =0x00002C74
    adds r0, r7, r3
    bl InitializeTVShoppingOrderState
    movs r1, #0xb2
    lsls r1, r1, #6
    adds r0, r7, r1
    bl __14FishingRecords
    ldr r2, .L080118BC @ =0x00002E58
    adds r0, r7, r2
    bl __14MineFloorState
    movs r3, #0xd2
    lsls r3, r3, #6
    adds r0, r7, r3
    bl __15CursedToolState
    ldr r0, .L080118C0 @ =0x00003494
    adds r2, r7, r0
    movs r3, #2
    movs r5, #0x10
    rsbs r5, r5, #0
    movs r4, #1
    rsbs r4, r4, #0
.L0801180A:
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    strb r0, [r2]
    adds r2, #0x10
    subs r3, #1
    cmp r3, r4
    bne .L0801180A
    ldr r1, .L080118C4 @ =0x000034C8
    adds r0, r7, r1
    bl __14FieldItemState
    ldr r2, .L080118C8 @ =0x000034D8
    adds r0, r7, r2
    bl __13MapPatchFlags
    ldr r3, .L080118CC @ =0x000034DC
    adds r0, r7, r3
    bl __18Unk_Actor_0809BFE8
    movs r5, #0
    str r5, [r6]
    str r5, [sp, #0xc]
    ldr r0, [sp, #0x14]
    mov r1, sb
    mov r2, sl
    movs r3, #4
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801190E
    ldr r4, [sp, #0xc]
    ldr r0, .L080118D0 @ =0x000034F4
    cmp r4, r0
    bne .L0801190E
    mov r2, sl
    adds r2, #4
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    adds r3, r4, #0
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080118D8
    ldr r2, .L080118D4 @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0x80
    lsls r1, r1, #0xa
    b .L08011916
    .align 2, 0
.L08011870: .4byte 0xFFFFF81F
.L08011874: .4byte gText_LoadError
.L08011878: .4byte 0x00001AA8
.L0801187C: .4byte 0x00001BD8
.L08011880: .4byte 0x00001C70
.L08011884: .4byte 0x00001CCC
.L08011888: .4byte 0xFFFFFC00
.L0801188C: .4byte 0x00001CD4
.L08011890: .4byte 0x0000214C
.L08011894: .4byte 0x000021CC
.L08011898: .4byte 0x000021E0
.L0801189C: .4byte 0x00002C48
.L080118A0: .4byte 0x00002C4A
.L080118A4: .4byte 0x00002210
.L080118A8: .4byte 0x00002214
.L080118AC: .4byte 0x00002C1C
.L080118B0: .4byte 0xFFF80003
.L080118B4: .4byte 0x00002C4C
.L080118B8: .4byte 0x00002C74
.L080118BC: .4byte 0x00002E58
.L080118C0: .4byte 0x00003494
.L080118C4: .4byte 0x000034C8
.L080118C8: .4byte 0x000034D8
.L080118CC: .4byte 0x000034DC
.L080118D0: .4byte 0x000034F4
.L080118D4: .4byte gSramAccessStatus
.L080118D8:
    ldr r2, .L080118F8 @ =0x000034F8
    add r2, sl
    str r5, [sp, #0x10]
    add r1, sp, #0x10
    ldr r0, [sp, #0x14]
    movs r3, #4
    bl Read__10SramAccessPvUiUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08011900
    ldr r2, .L080118FC @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0xc0
    lsls r1, r1, #0xa
    b .L08011916
    .align 2, 0
.L080118F8: .4byte 0x000034F8
.L080118FC: .4byte gSramAccessStatus
.L08011900:
    adds r0, r7, #0
    adds r1, r4, #0
    bl CalculateSaveImageChecksum
    ldr r1, [sp, #0x10]
    cmp r0, r1
    beq .L0801191E
.L0801190E:
    ldr r2, .L08011930 @ =gSramAccessStatus
    ldr r0, [r6]
    movs r1, #0x80
    lsls r1, r1, #9
.L08011916:
    orrs r0, r1
    ldrh r1, [r2]
    orrs r0, r1
    str r0, [r6]
.L0801191E:
    adds r0, r7, #0
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L08011930: .4byte gSramAccessStatus

    .section .text.game_scene_after_actor_commands, "ax", %progbits

    thumb_func_start ShowLivestockNeglectDeathSummary
ShowLivestockNeglectDeathSummary: @ 0x08014D9C
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L0801510C @ =0xFFFFFC70
    add sp, r4
    ldr r0, [r0, #4]
    mov sl, r0
    mov r4, sl
    adds r4, #0xf0
    movs r7, #0
    ldr r0, [r4]
    cmp r7, r0
    beq .L08014DBE
    bl __builtin_delete
.L08014DBE:
    str r7, [r4]
    mov r0, sp
    strb r7, [r0]
    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak
    add r0, sp, #0x384
    movs r2, #3
    bl memcpy
    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue
    add r0, sp, #0x388
    movs r2, #2
    bl memcpy
    ldr r1, .L08015118 @ =gText_AnimalMemorial_PageBreak
    add r0, sp, #0x38c
    movs r2, #2
    bl memcpy
    mov sb, sp
    ldr r0, .L0801511C @ =gText_AnimalMemorial_Header
    mov r8, r0
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014E16
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014E08
    adds r4, r5, #0
.L08014E08:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    strb r7, [r0]
.L08014E16:
    mov r6, sb
    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014E4A
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014E3A
    adds r4, r5, #0
.L08014E3A:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014E4A:
    ldr r1, .L08015124 @ =gText_AnimalMemorial_FarmPrefix
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014E7C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014E6C
    adds r4, r5, #0
.L08014E6C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014E7C:
    mov r0, sl
    adds r0, #0x8c
    ldr r0, [r0]
    adds r0, #0x14
    bl GetName__C4Farm
    mov r8, r0
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014EBA
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014EAA
    adds r4, r5, #0
.L08014EAA:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014EBA:
    .ifdef REGION_DE
    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak
    .else
    ldr r0, .L08015128 @ =gText_AnimalMemorial_FarmSuffix
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014EEC
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014EDC
    adds r4, r5, #0
.L08014EDC:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014EEC:
    .ifdef REGION_DE
    ldr r1, .L08015128 @ =gText_AnimalMemorial_PassedAway
    .else
    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak
    .endif
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014F1E
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014F0E
    adds r4, r5, #0
.L08014F0E:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014F1E:
    .ifdef REGION_DE
    ldr r0, .L08015114 @ =gText_AnimalMemorial_Continue
    .else
    ldr r0, .L0801512C @ =gText_AnimalMemorial_PassedAway
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014F50
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014F40
    adds r4, r5, #0
.L08014F40:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014F50:
    .ifdef REGION_DE
    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak
    .else
    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue
    .endif
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014F82
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014F72
    adds r4, r5, #0
.L08014F72:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014F82:
    .ifdef REGION_DE
    ldr r0, .L0801512C @ =gText_AnimalMemorial_NamesIntro
    .else
    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014FB4
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014FA4
    adds r4, r5, #0
.L08014FA4:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014FB4:
    .ifdef REGION_DE
    ldr r1, .L08015114 @ =gText_AnimalMemorial_Continue
    .else
    ldr r1, .L08015130 @ =gText_AnimalMemorial_NamesIntro
    .endif
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08014FE6
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08014FD6
    adds r4, r5, #0
.L08014FD6:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08014FE6:
    .ifdef REGION_DE
    ldr r0, .L08015110 @ =gText_AnimalMemorial_LineBreak
    .else
    ldr r0, .L08015114 @ =gText_AnimalMemorial_Continue
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    .ifdef REGION_DE
    beq .L0801504A
    .else
    beq .L08015018
    .endif
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015008
    adds r4, r5, #0
.L08015008:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .ifndef REGION_DE
.L08015018:
    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801504A
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801503A
    adds r4, r5, #0
.L0801503A:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .endif
.L0801504A:
    ldr r7, .L08015118 @ =gText_AnimalMemorial_PageBreak
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801507A
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801506A
    adds r4, r5, #0
.L0801506A:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L0801507A:
    mov r0, sl
    movs r1, #2
    mov r2, sp
    bl AppendAnimalMemorialNames
    mov r8, sp
    ldr r7, .L08015118 @ =gText_AnimalMemorial_PageBreak
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080150B8
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080150A8
    adds r4, r5, #0
.L080150A8:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L080150B8:
    mov r6, r8
    .ifdef REGION_DE
    ldr r0, .L08015130 @ =gText_AnimalMemorial_PrayerIntro
    .else
    ldr r0, .L08015134 @ =gText_AnimalMemorial_PrayerIntro
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080150EC
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080150DC
    adds r4, r5, #0
.L080150DC:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080150EC:
    ldr r1, .L08015110 @ =gText_AnimalMemorial_LineBreak
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L08015120 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801514C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    .ifdef REGION_DE
.L08015138:
    bls .L0801513C
    adds r4, r5, #0
.L0801513C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .else
    b .L08015138
    .align 2, 0
.L0801510C: .4byte 0xFFFFFC70
.L08015110: .4byte gText_AnimalMemorial_LineBreak
.L08015114: .4byte gText_AnimalMemorial_Continue
.L08015118: .4byte gText_AnimalMemorial_PageBreak
.L0801511C: .4byte gText_AnimalMemorial_Header
.L08015120: .4byte 0x00000383
.L08015124: .4byte gText_AnimalMemorial_FarmPrefix
.L08015128: .4byte gText_AnimalMemorial_FarmSuffix
.L0801512C: .4byte gText_AnimalMemorial_PassedAway
.L08015130: .4byte gText_AnimalMemorial_NamesIntro
.L08015134: .4byte gText_AnimalMemorial_PrayerIntro
.L08015138:
    bls .L0801513C
    adds r4, r5, #0
.L0801513C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .endif
.L0801514C:
    .ifdef REGION_DE
    ldr r0, .L08015134 @ =gText_AnimalMemorial_PrayerEnding
    .else
    ldr r0, .L08015204 @ =gText_AnimalMemorial_PrayerEnding
    .endif
	mov r8, r0
	adds r0, r6, #0
	bl strlen
	adds r7, r6, r0
	.ifdef REGION_DE
	ldr r1, .L08015120 @ =0x00000383
	.else
	ldr r1, .L08015208 @ =0x00000383
	.endif
	subs r5, r1, r0
    cmp r5, #0
    beq .L0801517E
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    .ifdef REGION_DE
    b .L0801516E_de
    .align 2, 0
.L0801510C: .4byte 0xFFFFFC70
.L08015110: .4byte gText_AnimalMemorial_LineBreak
.L08015114: .4byte gText_AnimalMemorial_Continue
.L08015118: .4byte gText_AnimalMemorial_PageBreak
.L0801511C: .4byte gText_AnimalMemorial_Header
.L08015120: .4byte 0x00000383
.L08015124: .4byte gText_AnimalMemorial_FarmPrefix
.L08015128: .4byte gText_AnimalMemorial_PassedAway
.L0801512C: .4byte gText_AnimalMemorial_NamesIntro
.L08015130: .4byte gText_AnimalMemorial_PrayerIntro
.L08015134: .4byte gText_AnimalMemorial_PrayerEnding
    .else
    bls .L0801516E
    adds r4, r5, #0
    .endif
.L0801516E_de:
    .ifdef REGION_DE
    bls .L0801516E
    adds r4, r5, #0
    .endif
.L0801516E:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L0801517E:
    ldr r7, .L0801520C @ =gText_AnimalMemorial_Continue
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    ldr r1, .L08015208 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080151AE
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801519E
    adds r4, r5, #0
.L0801519E:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L080151AE:
    movs r0, #0xe1
    lsls r0, r0, #2
    bl __builtin_new
    adds r4, r0, #0
    mov r1, sp
    bl strcpy
    mov r5, sl
    adds r5, #0xf0
    ldr r0, [r5]
    cmp r4, r0
    beq .L080151CC
    bl __builtin_delete
.L080151CC:
    str r4, [r5]
    mov r0, sl
    adds r0, #0xac
    ldr r1, [r0]
    cmp r1, #0
    beq .L080151F0
    adds r0, #4
    ldr r3, [r0]
    adds r0, r1, #0
    adds r1, r4, #0
    movs r2, #0x80
    lsls r2, r2, #1
    bl func_08050DC8
    mov r1, sl
    adds r1, #0x9c
    movs r0, #0x10
    str r0, [r1]
.L080151F0:
    movs r3, #0xe4
    lsls r3, r3, #2
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.ifdef REGION_DE
.L0801520C: .4byte gText_AnimalMemorial_Continue
.L08015208: .4byte 0x00000383
.else
.L08015204: .4byte gText_AnimalMemorial_PrayerEnding
.L08015208: .4byte 0x00000383
.L0801520C: .4byte gText_AnimalMemorial_Continue
.endif

    thumb_func_start RemoveLivestockDeadFromNeglect
RemoveLivestockDeadFromNeglect: @ 0x08015210
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, [r0, #4]
    mov r8, r0
    mov r5, r8
    adds r5, #0x8c
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Coop
    adds r6, r0, #0
    movs r4, #0
    cmp r4, r6
    bhs .L08015272
    mov r7, r8
    adds r7, #0xa8
.L08015236:
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    beq .L0801526C
    bl GetLifeState__C9Livestock
    cmp r0, #2
    bne .L0801526C
    ldr r0, [r7]
    ldr r2, [r0]
    adds r1, r4, #0
    adds r1, #0x2e
    ldr r2, [r2, #0x3c]
    bl _call_via_r2
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4CoopUi
.L0801526C:
    adds r4, #1
    cmp r4, r6
    blo .L08015236
.L08015272:
    mov r4, r8
    adds r4, #0x8c
    ldr r0, [r4]
    ldr r1, .L08015318 @ =0x00001C2C
    adds r5, r0, r1
    adds r0, r5, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    adds r6, r4, #0
    cmp r0, #0
    bne .L080152B8
    adds r0, r5, #0
    bl GetKind__C8HeldItem
    cmp r0, #3
    bne .L080152B8
    ldr r4, [r6]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r4, r4, r0
    adds r0, r5, #0
    bl GetHeldChickenSlot
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .L080152B8
    ldr r0, [r6]
    ldr r1, .L08015318 @ =0x00001C2C
    adds r0, r0, r1
    bl ClearHeldItem
.L080152B8:
    ldr r0, [r6]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Barn
    adds r7, r0, #0
    movs r4, #0
    cmp r4, r7
    bhs .L0801530E
    adds r5, r6, #0
    mov r6, r8
    adds r6, #0xa8
.L080152D2:
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetBarnAnimal__4BarnUi
    cmp r0, #0
    beq .L08015308
    bl GetLifeState__C9Livestock
    cmp r0, #2
    bne .L08015308
    ldr r0, [r6]
    ldr r2, [r0]
    adds r1, r4, #0
    adds r1, #0x36
    ldr r2, [r2, #0x3c]
    bl _call_via_r2
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4BarnUi
.L08015308:
    adds r4, #1
    cmp r4, r7
    blo .L080152D2
.L0801530E:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08015318: .4byte 0x00001C2C

    thumb_func_start ShowNaturalLivestockDeathSummary
ShowNaturalLivestockDeathSummary: @ 0x0801531C
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L0801568C @ =0xFFFFFC70
    add sp, r4
    ldr r0, [r0, #4]
    mov sl, r0
    mov r4, sl
    adds r4, #0xf0
    movs r7, #0
    ldr r0, [r4]
    cmp r7, r0
    beq .L0801533E
    bl __builtin_delete
.L0801533E:
    str r7, [r4]
    mov r0, sp
    strb r7, [r0]
    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak
    add r0, sp, #0x384
    movs r2, #3
    bl memcpy
    ldr r1, .L08015694 @ =gText_AnimalMemorial_Continue
    add r0, sp, #0x388
    movs r2, #2
    bl memcpy
    ldr r1, .L08015698 @ =gText_AnimalMemorial_PageBreak
    add r0, sp, #0x38c
    movs r2, #2
    bl memcpy
    mov sb, sp
    ldr r0, .L0801569C @ =gText_AnimalMemorial_Header
    mov r8, r0
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08015396
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015388
    adds r4, r5, #0
.L08015388:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r0, r6, r4
    strb r7, [r0]
.L08015396:
    mov r6, sb
    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080153CA
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080153BA
    adds r4, r5, #0
.L080153BA:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080153CA:
    ldr r1, .L080156A4 @ =gText_AnimalMemorial_FarmPrefix
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080153FC
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080153EC
    adds r4, r5, #0
.L080153EC:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080153FC:
    mov r0, sl
    adds r0, #0x8c
    ldr r0, [r0]
    adds r0, #0x14
    bl GetName__C4Farm
    mov r8, r0
    mov r4, r8
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801543A
    adds r0, r4, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801542A
    adds r4, r5, #0
.L0801542A:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L0801543A:
    .ifdef REGION_DE
    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak
    .else
    ldr r0, .L080156A8 @ =gText_AnimalMemorial_FarmSuffix
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801546C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801545C
    adds r4, r5, #0
.L0801545C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L0801546C:
    .ifdef REGION_DE
    ldr r1, .L080156A8 @ =gText_AnimalMemorial_NamesIntro
    .else
    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak
    .endif
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801549E
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801548E
    adds r4, r5, #0
.L0801548E:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L0801549E:
    .ifdef REGION_DE
    ldr r0, .L08015694 @ =gText_AnimalMemorial_Continue
    .else
    ldr r0, .L080156AC @ =gText_AnimalMemorial_PassedAway
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080154D0
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080154C0
    adds r4, r5, #0
.L080154C0:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080154D0:
    .ifdef REGION_DE
    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak
    .else
    ldr r1, .L08015694 @ =gText_AnimalMemorial_Continue
    .endif
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    .ifdef REGION_DE
    beq .L080155CA
    .else
    beq .L08015502
    .endif
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080154F2
    adds r4, r5, #0
.L080154F2:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .ifndef REGION_DE
.L08015502:
    ldr r0, .L08015690 @ =gText_AnimalMemorial_LineBreak
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08015534
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015524
    adds r4, r5, #0
.L08015524:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08015534:
    ldr r1, .L080156B0 @ =gText_AnimalMemorial_NamesIntro
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08015566
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015556
    adds r4, r5, #0
.L08015556:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08015566:
    ldr r0, .L08015694 @ =gText_AnimalMemorial_Continue
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08015598
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015588
    adds r4, r5, #0
.L08015588:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L08015598:
    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080155CA
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080155BA
    adds r4, r5, #0
.L080155BA:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
    .endif
.L080155CA:
    ldr r7, .L08015698 @ =gText_AnimalMemorial_PageBreak
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080155FA
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080155EA
    adds r4, r5, #0
.L080155EA:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L080155FA:
    mov r0, sl
    movs r1, #1
    mov r2, sp
    bl AppendAnimalMemorialNames
    mov r8, sp
    ldr r7, .L08015698 @ =gText_AnimalMemorial_PageBreak
    mov r0, sp
    bl strlen
    mov r1, sp
    adds r6, r1, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L08015638
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L08015628
    adds r4, r5, #0
.L08015628:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L08015638:
    mov r6, r8
    .ifdef REGION_DE
    ldr r0, .L080156AC @ =gText_AnimalMemorial_PrayerIntro
    .else
    ldr r0, .L080156B4 @ =gText_AnimalMemorial_PrayerIntro
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801566C
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801565C
    adds r4, r5, #0
.L0801565C:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L0801566C:
    ldr r1, .L08015690 @ =gText_AnimalMemorial_LineBreak
    mov r8, r1
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    ldr r1, .L080156A0 @ =0x00000383
    subs r5, r1, r0
    cmp r5, #0
    beq .L080156CC
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    .ifndef REGION_DE
    b .L080156B8
    .align 2, 0
.L0801568C: .4byte 0xFFFFFC70
.L08015690: .4byte gText_AnimalMemorial_LineBreak
.L08015694: .4byte gText_AnimalMemorial_Continue
.L08015698: .4byte gText_AnimalMemorial_PageBreak
.L0801569C: .4byte gText_AnimalMemorial_Header
.L080156A0: .4byte 0x00000383
.L080156A4: .4byte gText_AnimalMemorial_FarmPrefix
.L080156A8: .4byte gText_AnimalMemorial_FarmSuffix
.L080156AC: .4byte gText_AnimalMemorial_PassedAway
.L080156B0: .4byte gText_AnimalMemorial_NamesIntro
.L080156B4: .4byte gText_AnimalMemorial_PrayerIntro
    .endif
.L080156B8:
    bls .L080156BC
    adds r4, r5, #0
.L080156BC:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080156CC:
    .ifdef REGION_DE
    ldr r0, .L080156B4 @ =gText_AnimalMemorial_PrayerEnding
    .else
    ldr r0, .L08015784 @ =gText_AnimalMemorial_PrayerEnding
    .endif
    mov r8, r0
    adds r0, r6, #0
    bl strlen
    adds r7, r6, r0
    .ifdef REGION_DE
    ldr r1, .L080156A0 @ =0x00000383
    .else
    ldr r1, .L08015788 @ =0x00000383
    .endif
    subs r5, r1, r0
    cmp r5, #0
    beq .L080156FE
    mov r0, r8
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L080156EE
    adds r4, r5, #0
.L080156EE:
    adds r0, r7, #0
    mov r1, r8
    adds r2, r4, #0
    bl memcpy
    adds r1, r7, r4
    movs r0, #0
    strb r0, [r1]
.L080156FE:
    .ifdef REGION_DE
    ldr r7, .L08015694 @ =gText_AnimalMemorial_Continue
    .else
    ldr r7, .L0801578C @ =gText_AnimalMemorial_Continue
    .endif
    adds r0, r6, #0
    bl strlen
    adds r6, r6, r0
    .ifdef REGION_DE
    ldr r1, .L080156A0 @ =0x00000383
    .else
    ldr r1, .L08015788 @ =0x00000383
    .endif
    subs r5, r1, r0
    cmp r5, #0
    beq .L0801572E
    adds r0, r7, #0
    bl strlen
    adds r4, r0, #0
    cmp r4, r5
    bls .L0801571E
    adds r4, r5, #0
.L0801571E:
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl memcpy
    adds r1, r6, r4
    movs r0, #0
    strb r0, [r1]
.L0801572E:
    movs r0, #0xe1
    lsls r0, r0, #2
    bl __builtin_new
    adds r4, r0, #0
    mov r1, sp
    bl strcpy
    mov r5, sl
    adds r5, #0xf0
    ldr r0, [r5]
    cmp r4, r0
    beq .L0801574C
    bl __builtin_delete
.L0801574C:
    str r4, [r5]
    mov r0, sl
    adds r0, #0xac
    ldr r1, [r0]
    cmp r1, #0
    beq .L08015770
    adds r0, #4
    ldr r3, [r0]
    adds r0, r1, #0
    adds r1, r4, #0
    movs r2, #0x80
    lsls r2, r2, #1
    bl func_08050DC8
    mov r1, sl
    adds r1, #0x9c
    movs r0, #0x10
    str r0, [r1]
.L08015770:
    movs r3, #0xe4
    lsls r3, r3, #2
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .ifdef REGION_DE
    b RemoveNaturallyDeadLivestock
    .align 2, 0
.L0801568C: .4byte 0xFFFFFC70
.L08015690: .4byte gText_AnimalMemorial_LineBreak
.L08015694: .4byte gText_AnimalMemorial_Continue
.L08015698: .4byte gText_AnimalMemorial_PageBreak
.L0801569C: .4byte gText_AnimalMemorial_DeathHeader
.L080156A0: .4byte 0x00000383
.L080156A4: .4byte gText_AnimalMemorial_DeathFarmPrefix
.L080156A8: .4byte gText_AnimalMemorial_NamesIntro
.L080156AC: .4byte gText_AnimalMemorial_PrayerIntro
.L080156B4: .4byte gText_AnimalMemorial_PrayerEnding
    .else
    .align 2, 0
.L08015784: .4byte gText_AnimalMemorial_PrayerEnding
.L08015788: .4byte 0x00000383
.L0801578C: .4byte gText_AnimalMemorial_Continue
    .endif

    thumb_func_start RemoveNaturallyDeadLivestock
RemoveNaturallyDeadLivestock: @ 0x08015790
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, [r0, #4]
    mov r8, r0
    mov r5, r8
    adds r5, #0x8c
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Coop
    adds r6, r0, #0
    movs r4, #0
    cmp r4, r6
    bhs .L080157F2
    mov r7, r8
    adds r7, #0xa8
.L080157B6:
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    beq .L080157EC
    bl GetLifeState__C9Livestock
    cmp r0, #1
    bne .L080157EC
    ldr r0, [r7]
    ldr r2, [r0]
    adds r1, r4, #0
    adds r1, #0x2e
    ldr r2, [r2, #0x3c]
    bl _call_via_r2
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4CoopUi
.L080157EC:
    adds r4, #1
    cmp r4, r6
    blo .L080157B6
.L080157F2:
    mov r4, r8
    adds r4, #0x8c
    ldr r0, [r4]
    ldr r1, .L08015898 @ =0x00001C2C
    adds r5, r0, r1
    adds r0, r5, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    adds r6, r4, #0
    cmp r0, #0
    bne .L08015838
    adds r0, r5, #0
    bl GetKind__C8HeldItem
    cmp r0, #3
    bne .L08015838
    ldr r4, [r6]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r4, r4, r0
    adds r0, r5, #0
    bl GetHeldChickenSlot
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .L08015838
    ldr r0, [r6]
    ldr r1, .L08015898 @ =0x00001C2C
    adds r0, r0, r1
    bl ClearHeldItem
.L08015838:
    ldr r0, [r6]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Barn
    adds r7, r0, #0
    movs r4, #0
    cmp r4, r7
    bhs .L0801588E
    adds r5, r6, #0
    mov r6, r8
    adds r6, #0xa8
.L08015852:
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetBarnAnimal__4BarnUi
    cmp r0, #0
    beq .L08015888
    bl GetLifeState__C9Livestock
    cmp r0, #1
    bne .L08015888
    ldr r0, [r6]
    ldr r2, [r0]
    adds r1, r4, #0
    adds r1, #0x36
    ldr r2, [r2, #0x3c]
    bl _call_via_r2
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl RemoveAndRememberUnk__4BarnUi
.L08015888:
    adds r4, #1
    cmp r4, r7
    blo .L08015852
.L0801588E:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08015898: .4byte 0x00001C2C

    .section .text.game_scene_field_item_tool_after, "ax", %progbits
    .align 2, 0

    .section .text.game_scene_palette_resource_selector_after, "ax", %progbits
    .align 2, 0

.L0801B9E8:
    .global SetWorldSpritePaletteColors
    .thumb_func
SetWorldSpritePaletteColors:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc0
    adds r7, r0, #0
    mov r8, r1
    str r2, [sp, #0x90]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov sl, r3
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lraw_game_state_7848_10
    movs r0, #0xde
    lsls r0, r0, #1
    adds r4, r7, r0
    ldr r1, [sp, #0x90]
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r0, r4, #0
    mov r1, r8
    movs r2, #0x20
    bl memcpy
    adds r1, r4, #0
    adds r1, #0x82
    movs r0, #1
    strb r0, [r1]
    adds r4, #0x83
    mov r2, sl
    strb r2, [r4]
    b .Lraw_game_state_7986_6
.Lraw_game_state_7848_10:
    ldr r0, [r7, #4]
    ldr r1, [r0]
    ldr r3, .Lraw_game_state_7850_4
    adds r0, r7, r3
    ldr r0, [r0]
    adds r0, #8
    cmp r1, #0x2e
    beq .Lraw_game_state_7851_0
    cmp r1, #0x2e
    ble .Lraw_game_state_7850_8
    cmp r1, #0x2f
    beq .Lraw_game_state_7851_4
    b .Lraw_game_state_7851_8
.Lraw_game_state_7850_4: .word 0x00001038
.Lraw_game_state_7850_8:
    cmp r1, #0x2c
    blt .Lraw_game_state_7851_8
    movs r3, #0
    b .Lraw_game_state_7851_10
.Lraw_game_state_7851_0:
    movs r3, #1
    b .Lraw_game_state_7851_10
.Lraw_game_state_7851_4:
    movs r3, #2
    b .Lraw_game_state_7851_10
.Lraw_game_state_7851_8:
    ldr r3, [r0]
.Lraw_game_state_7851_10:
    ldr r4, .Lraw_game_state_7861_4
    adds r0, r7, r4
    ldrb r1, [r0]
    movs r2, #0x1e
    movs r5, #0xce
    lsls r5, r5, #1
    adds r5, r5, r7
    mov sb, r5
    ldr r6, .Lraw_game_state_7861_8
    adds r0, r7, r6
    ldr r6, [r0]
    str r1, [sp, #0x94]
    subs r2, r2, r1
    str r2, [sp, #0x98]
    movs r0, #0xde
    lsls r0, r0, #1
    adds r4, r7, r0
    ldr r1, [sp, #0x90]
    lsls r5, r1, #5
    adds r0, r5, r1
    lsls r0, r0, #2
    adds r4, r4, r0
    adds r0, r4, #0
    mov r1, r8
    movs r2, #0x20
    str r3, [sp, #0xbc]
    bl memcpy
    adds r2, r4, #0
    adds r2, #0x82
    movs r0, #1
    mov ip, r0
    mov r1, ip
    strb r1, [r2]
    adds r0, r4, #0
    adds r0, #0x83
    mov r1, sl
    strb r1, [r0]
    mov r8, r4
    str r5, [sp, #0xa0]
    ldr r3, [sp, #0xbc]
    mov r4, sl
    cmp r4, #0
    bne .Lraw_game_state_7861_12
    mov r1, r8
    adds r1, #0x20
    mov r0, r8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    mov r1, r8
    adds r1, #0x40
    mov r0, r8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    mov r5, ip
    strb r5, [r2]
    movs r6, #0xde
    lsls r6, r6, #1
    adds r6, r6, r7
    mov sl, r6
    b .Lraw_game_state_7978_6
.Lraw_game_state_7861_4: .word 0x0000104C
.Lraw_game_state_7861_8: .word 0x00001048
.Lraw_game_state_7861_12:
    str r2, [sp, #0xb8]
    movs r0, #0xde
    lsls r0, r0, #1
    adds r0, r0, r7
    mov sl, r0
    cmp r3, #4
    bls .Lraw_game_state_7862_12
    b .Lraw_game_state_7978_0
.Lraw_game_state_7862_12:
    lsls r0, r3, #2
    ldr r1, .L0801B9E8_case_table_1_address
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801B9E8_case_table_1_address: .4byte .L0801B9E8_case_table_1
.L0801B9E8_case_table_1: .4byte .L0801B9E8 + 0x148
    .4byte .L0801B9E8 + 0x3A0
    .4byte .L0801B9E8 + 0x3A0
    .4byte .L0801B9E8 + 0x148
    .4byte .L0801B9E8 + 0x148
    cmp r6, #1
    bne .Lraw_game_state_7872_6
    b .Lraw_game_state_7897_0
.Lraw_game_state_7872_6:
    cmp r6, #1
    bgt .Lraw_game_state_7873_12
    cmp r6, #0
    beq .Lraw_game_state_7887_4
    mov r1, r8
    adds r1, #0x82
    str r1, [sp, #0xb8]
    movs r2, #0x20
    add r2, sb
    mov sl, r2
    b .Lraw_game_state_7978_0
.Lraw_game_state_7873_12:
    cmp r6, #2
    bne .Lraw_game_state_7874_2
    b .Lraw_game_state_7905_0
.Lraw_game_state_7874_2:
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r4, #0x20
    add r4, sb
    mov sl, r4
    cmp r6, #3
    beq .Lraw_game_state_7875_4
    b .Lraw_game_state_7978_0
.Lraw_game_state_7875_4:
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
    ldr r0, .Lraw_game_state_7885_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r3, .Lraw_game_state_7885_8
    str r3, [sp, #0x24]
    mov r1, sp
    adds r6, r2, #0
    adds r5, r0, #0
    add r7, sp, #0x28
    add r4, sp, #0x2c
    mov sb, r4
    adds r4, r2, #0
    cmp sp, r4
    beq .Lraw_game_state_7879_6
    adds r4, r3, #0
.Lraw_game_state_7878_14:
    strh r4, [r1]
    adds r1, #2
    cmp r1, r6
    bne .Lraw_game_state_7878_14
.Lraw_game_state_7879_6:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7886_0
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
    ldr r0, .Lraw_game_state_7885_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_7887_0
    str r0, [sp, #0x2c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_7884_4
    b .Lraw_game_state_7959_0
.Lraw_game_state_7884_4:
    mov r5, sb
    ldr r2, [r5]
.Lraw_game_state_7884_8:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7884_8
    b .Lraw_game_state_7959_0
    .align 2, 0
.Lraw_game_state_7885_4: .word 0xFFFFFC1F
.Lraw_game_state_7885_8: .word 0x00002529
.Lraw_game_state_7886_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7887_0: .word 0x00001BAA
.Lraw_game_state_7887_4:
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
    ldr r0, .Lraw_game_state_7895_4
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_7895_8
    str r6, [sp, #0x34]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_7891_8
.Lraw_game_state_7891_0:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_7891_0
.Lraw_game_state_7891_8:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7896_0
    bl _call_via_r4
    adds r0, r5, #0
    adds r0, #0x20
    mov r1, r8
    movs r2, #0x20
    bl memcpy
    b .Lraw_game_state_7978_0
    .align 2, 0
.Lraw_game_state_7895_4: .word 0xFFFFFC1F
.Lraw_game_state_7895_8: .word 0x00001BAA
.Lraw_game_state_7896_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7897_0:
    mov r4, r8
    adds r4, #0x20
    adds r0, r4, #0
    mov r1, r8
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
    ldr r0, .Lraw_game_state_7904_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, #0x20
    movs r0, #8
    lsls r6, r0, #5
    movs r1, #0x20
    orrs r6, r1
    lsls r0, r0, #0xa
    orrs r6, r0
    str r6, [sp, #0x3c]
    mov r0, sp
    add r1, sp, #0x20
    mov r5, r8
    adds r5, #0x82
    str r5, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r1
    beq .Lraw_game_state_7904_8
.Lraw_game_state_7904_0:
    strh r6, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7904_0
.Lraw_game_state_7904_8:
    ldr r3, [r2]
    b .Lraw_game_state_7959_2
.Lraw_game_state_7904_12: .word 0xFFFFFC1F
.Lraw_game_state_7905_0:
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
    ldr r0, .Lraw_game_state_7917_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r7, r8
    adds r7, #0x20
    adds r3, r2, #0
    movs r0, #8
    lsls r2, r0, #5
    movs r1, #0x20
    orrs r2, r1
    lsls r0, r0, #0xa
    orrs r2, r0
    str r2, [sp, #0x44]
    mov r4, sp
    add r6, sp, #0x20
    adds r5, r7, #0
    mov r0, sp
    adds r0, #0x48
    str r0, [sp, #0xa4]
    mov r1, sp
    adds r1, #0x4c
    str r1, [sp, #0xa8]
    mov r0, r8
    adds r0, #0x82
    str r0, [sp, #0xb8]
    movs r1, #0x20
    add r1, sb
    mov sl, r1
    cmp sp, r6
    beq .Lraw_game_state_7910_14
    adds r0, r2, #0
.Lraw_game_state_7910_6:
    strh r0, [r4]
    adds r4, #2
    cmp r4, r6
    bne .Lraw_game_state_7910_6
.Lraw_game_state_7910_14:
    ldr r3, [r3]
    adds r0, r7, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7918_0
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
    ldr r0, .Lraw_game_state_7917_12
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    ldr r3, [sp, #0xa4]
    ldr r0, .Lraw_game_state_7919_0
    str r0, [sp, #0x4c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_7916_14
    b .Lraw_game_state_7959_0
.Lraw_game_state_7916_14:
    ldr r5, [sp, #0xa8]
    ldr r2, [r5]
.Lraw_game_state_7917_2:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7917_2
    b .Lraw_game_state_7959_0
.Lraw_game_state_7917_12: .word 0xFFFFFC1F
.Lraw_game_state_7918_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7919_0: .word 0x00002529
    cmp r6, #1
    bne .Lraw_game_state_7919_10
    b .Lraw_game_state_7948_0
.Lraw_game_state_7919_10:
    cmp r6, #1
    bgt .Lraw_game_state_7921_4
    cmp r6, #0
    beq .Lraw_game_state_7935_4
    mov r6, r8
    adds r6, #0x82
    str r6, [sp, #0xb8]
    movs r0, #0x20
    add r0, sb
    mov sl, r0
    b .Lraw_game_state_7978_0
.Lraw_game_state_7921_4:
    cmp r6, #2
    bne .Lraw_game_state_7921_10
    b .Lraw_game_state_7964_0
.Lraw_game_state_7921_10:
    mov r1, r8
    adds r1, #0x82
    str r1, [sp, #0xb8]
    movs r2, #0x20
    add r2, sb
    mov sl, r2
    cmp r6, #3
    beq .Lraw_game_state_7922_12
    b .Lraw_game_state_7978_0
.Lraw_game_state_7922_12:
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
    ldr r0, .Lraw_game_state_7933_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_7933_12
    str r6, [sp, #0x54]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x58
    add r3, sp, #0x5c
    mov sb, r3
    cmp sp, r4
    beq .Lraw_game_state_7926_10
.Lraw_game_state_7926_2:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_7926_2
.Lraw_game_state_7926_10:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7934_0
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
    ldr r0, .Lraw_game_state_7933_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_7935_0
    str r0, [sp, #0x5c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    bne .Lraw_game_state_7932_8
    b .Lraw_game_state_7959_0
.Lraw_game_state_7932_8:
    mov r5, sb
    ldr r2, [r5]
.Lraw_game_state_7932_12:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7932_12
    b .Lraw_game_state_7959_0
    .align 2, 0
.Lraw_game_state_7933_8: .word 0xFFFFFC1F
.Lraw_game_state_7933_12: .word 0x00002529
.Lraw_game_state_7934_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7935_0: .word 0x00006A32
.Lraw_game_state_7935_4:
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
    ldr r0, .Lraw_game_state_7946_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_7946_4
    str r6, [sp, #0x64]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x68
    mov r3, sp
    adds r3, #0x6c
    str r3, [sp, #0xac]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_7940_4
.Lraw_game_state_7939_12:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_7939_12
.Lraw_game_state_7940_4:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7947_0
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
    ldr r0, .Lraw_game_state_7946_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_7946_4
    str r0, [sp, #0x6c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    beq .Lraw_game_state_7959_0
    ldr r5, [sp, #0xac]
    ldr r2, [r5]
.Lraw_game_state_7945_4:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7945_4
    b .Lraw_game_state_7959_0
    .align 2, 0
.Lraw_game_state_7946_0: .word 0xFFFFFC1F
.Lraw_game_state_7946_4: .word 0x00006A32
.Lraw_game_state_7947_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7948_0:
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
    ldr r0, .Lraw_game_state_7962_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r0, r8
    adds r0, #0x20
    ldr r6, .Lraw_game_state_7962_4
    str r6, [sp, #0x74]
    mov r1, sp
    add r4, sp, #0x20
    adds r5, r0, #0
    add r7, sp, #0x78
    mov r3, sp
    adds r3, #0x7c
    str r3, [sp, #0xb0]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r4
    beq .Lraw_game_state_7953_8
.Lraw_game_state_7953_0:
    strh r6, [r1]
    adds r1, #2
    cmp r1, r4
    bne .Lraw_game_state_7953_0
.Lraw_game_state_7953_8:
    ldr r3, [r2]
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7963_0
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
    ldr r0, .Lraw_game_state_7962_0
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_7962_4
    str r0, [sp, #0x7c]
    mov r0, sp
    add r1, sp, #0x20
    cmp sp, r1
    beq .Lraw_game_state_7959_0
    ldr r5, [sp, #0xb0]
    ldr r2, [r5]
.Lraw_game_state_7958_8:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7958_8
.Lraw_game_state_7959_0:
    ldr r3, [r3]
.Lraw_game_state_7959_2:
    adds r0, r4, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7963_0
    bl _call_via_r4
    b .Lraw_game_state_7978_0
.Lraw_game_state_7962_0: .word 0xFFFFFC1F
.Lraw_game_state_7962_4: .word 0x00006A32
.Lraw_game_state_7963_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7964_0:
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
    ldr r0, .Lraw_game_state_7987_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    mov r6, r8
    adds r6, #0x20
    ldr r4, .Lraw_game_state_7987_12
    add r0, sp, #0x84
    str r4, [r0]
    mov r0, sp
    add r1, sp, #0x20
    adds r5, r6, #0
    add r7, sp, #0x88
    mov r3, sp
    adds r3, #0x8c
    str r3, [sp, #0xb4]
    mov r3, r8
    adds r3, #0x82
    str r3, [sp, #0xb8]
    movs r3, #0x20
    add r3, sb
    mov sl, r3
    cmp sp, r1
    beq .Lraw_game_state_7969_10
.Lraw_game_state_7969_2:
    strh r4, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7969_2
.Lraw_game_state_7969_10:
    ldr r3, [r2]
    adds r0, r6, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7988_0
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
    ldr r0, .Lraw_game_state_7987_8
    ands r0, r1
    orrs r0, r3
    strh r0, [r2]
    adds r4, r5, #0
    adds r4, #0x20
    adds r3, r7, #0
    ldr r0, .Lraw_game_state_7989_0
    ldr r5, [sp, #0xb4]
    str r0, [r5]
    mov r0, sp
    add r1, sp, #0x20
    add r2, sp, #0x8c
    cmp sp, r1
    beq .Lraw_game_state_7976_6
    ldr r2, [r2]
.Lraw_game_state_7975_14:
    strh r2, [r0]
    adds r0, #2
    cmp r0, r1
    bne .Lraw_game_state_7975_14
.Lraw_game_state_7976_6:
    ldr r3, [r3]
    adds r0, r4, #0
    mov r1, sp
    mov r2, r8
    ldr r4, .Lraw_game_state_7988_0
    bl _call_via_r4
.Lraw_game_state_7978_0:
    movs r0, #1
    ldr r6, [sp, #0xb8]
    strb r0, [r6]
.Lraw_game_state_7978_6:
    ldr r1, [sp, #0xa0]
    ldr r2, [sp, #0x90]
    adds r0, r1, r2
    lsls r0, r0, #2
    mov r3, sl
    adds r5, r3, r0
    adds r0, r5, #0
    adds r0, #0x60
    adds r1, r5, #0
    adds r1, #0x20
    adds r2, r5, #0
    adds r2, #0x40
    movs r3, #0x1f
    ldr r4, [sp, #0x94]
    ands r4, r3
    movs r3, #0x20
    rsbs r3, r3, #0
    ldr r6, [sp, #0x9c]
    ands r3, r6
    orrs r3, r4
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    ldr r4, .Lraw_game_state_7989_4
    ands r6, r4
    orrs r6, r3
    movs r3, #0x1f
    ldr r4, [sp, #0x98]
    ands r4, r3
    lsls r4, r4, #5
    ldr r3, .Lraw_game_state_7987_8
    ands r3, r6
    orrs r3, r4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, .Lraw_game_state_7989_8
    ands r6, r4
    orrs r6, r3
    str r6, [sp, #0x9c]
    adds r3, r6, #0
    ldr r4, .Lraw_game_state_7988_0
    bl _call_via_r4
    adds r1, r5, #0
    adds r1, #0x82
    movs r0, #1
    strb r0, [r1]
.Lraw_game_state_7986_6:
    add sp, #0xc0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lraw_game_state_7987_8: .word 0xFFFFFC1F
.Lraw_game_state_7987_12: .word 0x00006A32
.Lraw_game_state_7988_0: .word BlendRgb5PaletteBank
.Lraw_game_state_7989_0: .word 0x00002529
.Lraw_game_state_7989_4: .word 0xFFFFFF00
.Lraw_game_state_7989_8: .word 0xFFFF0000
    .section .text.game_scene_farm_plot_query_after, "ax", %progbits

    thumb_func_start func_0801C198
func_0801C198: @ 0x0801C198
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    adds r4, r0, #0
    adds r3, r1, #0
    adds r7, r2, #0
    movs r0, #0
    mov sb, r0
    ldrh r0, [r3]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    subs r0, #0x34
    ldr r1, .L0801C20C @ =0x000001FF
    cmp r0, r1
    bhi .L0801C28C
    ldr r1, .L0801C210 @ =0x00001038
    adds r0, r4, r1
    ldr r0, [r0]
    ldr r1, .L0801C214 @ =0x00002E58
    adds r6, r0, r1
    ldrb r1, [r3, #1]
    lsrs r1, r1, #2
    ldrh r0, [r3, #2]
    ldr r2, .L0801C218 @ =0x000003FF
    ands r0, r2
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bge .L0801C1DC
    adds r0, #7
.L0801C1DC:
    asrs r5, r0, #3
    ldrb r1, [r3, #3]
    lsrs r1, r1, #2
    ldrh r0, [r3, #4]
    ands r0, r2
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bge .L0801C1F4
    adds r0, #7
.L0801C1F4:
    asrs r4, r0, #3
    adds r0, r6, #0
    bl GetLayoutKind__C14MineFloorState
    cmp r0, #4
    bhi .L0801C240
    lsls r0, r0, #2
    ldr r1, .L0801C21C @ =.L0801C220
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801C20C: .4byte 0x000001FF
.L0801C210: .4byte 0x00001038
.L0801C214: .4byte 0x00002E58
.L0801C218: .4byte 0x000003FF
.L0801C21C: .4byte .L0801C220
.L0801C220: @ jump table
    .4byte .L0801C240 @ case 0
    .4byte .L0801C234 @ case 1
    .4byte .L0801C240 @ case 2
    .4byte .L0801C23A @ case 3
    .4byte .L0801C240 @ case 4
.L0801C234:
    movs r1, #2
    mov r8, r1
    b .L0801C244
.L0801C23A:
    movs r1, #2
    mov r8, r1
    b .L0801C244
.L0801C240:
    movs r0, #2
    mov r8, r0
.L0801C244:
    movs r3, #7
    cmp r5, #2
    blo .L0801C28C
    cmp r4, r3
    blo .L0801C28C
    adds r0, r6, #0
    str r3, [sp]
    bl GetWidth__C14MineFloorState
    lsls r0, r0, #1
    add r0, r8
    cmp r0, r5
    bls .L0801C28C
    adds r0, r6, #0
    bl GetHeight__C14MineFloorState
    lsls r0, r0, #1
    ldr r3, [sp]
    adds r0, r3, r0
    cmp r0, r4
    bls .L0801C28C
    mov r1, r8
    subs r2, r5, r1
    lsrs r2, r2, #1
    subs r1, r4, r3
    lsrs r1, r1, #1
    lsls r0, r2, #1
    add r0, r8
    strh r0, [r7]
    lsls r0, r1, #1
    adds r0, r3, r0
    strh r0, [r7, #2]
    strh r2, [r7, #4]
    strh r1, [r7, #6]
    movs r0, #1
    mov sb, r0
.L0801C28C:
    mov r0, sb
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    .section .text.game_scene_farm_plot_action_after, "ax", %progbits
    .align 2, 0

.L0801C3DC:
    .global func_0801C3DC
    .thumb_func
func_0801C3DC:
    bx lr
    .align 2, 0
    .global func_0801C3E0
    .thumb_func
func_0801C3E0:
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0xc
    adds r7, r0, #0
    movs r2, #0
    mov sb, r2
    ldr r0, .Lraw_game_state_8150_0
    adds r0, r0, r7
    mov r8, r0
    ldr r0, .Lraw_game_state_8150_4
    adds r6, r7, r0
.Lraw_game_state_8132_10:
    ldrb r1, [r6]
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #2
    bne .Lraw_game_state_8146_2
    movs r2, #4
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    subs r2, #9
    adds r0, r2, #0
    ands r1, r0
    strb r1, [r6]
    movs r0, #0x40
    bl __builtin_new
    adds r4, r0, #0
    ldr r0, [r7]
    ldr r1, [r0, #0x68]
    adds r0, r7, #0
    bl _call_via_r1
    adds r1, r0, #0
    movs r0, #3
    str r0, [sp]
    movs r0, #0x1a
    str r0, [sp, #4]
    add r2, sp, #8
    movs r0, #0
    strb r0, [r2]
    adds r0, r4, #0
    ldr r2, .Lraw_game_state_8150_8
    adds r3, r7, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    mov r5, r8
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lraw_game_state_8145_0
    cmp r1, #0
    beq .Lraw_game_state_8145_0
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_8145_0:
    str r4, [r5]
    movs r2, #1
.Lraw_game_state_8146_2:
    movs r0, #0xc
    add r8, r0
    adds r6, #0xc
    movs r0, #1
    add sb, r0
    mov r0, sb
    cmp r0, #3
    bls .Lraw_game_state_8132_10
    cmp r2, #0
    beq .Lraw_game_state_8149_0
    ldr r0, [r7, #8]
    movs r1, #2
    movs r2, #0
    bl StartActorSpriteEffect
.Lraw_game_state_8149_0:
    add sp, #0xc
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.Lraw_game_state_8150_0: .word 0x00001088
.Lraw_game_state_8150_4: .word 0x00001081
.Lraw_game_state_8150_8: .word 0x0000086F
    .global func_0801C49C
    .thumb_func
func_0801C49C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    adds r4, r0, #0
    mov sb, r1
    mov r8, r2
    movs r0, #0
    str r0, [r2]
    add r6, sp, #4
    adds r0, r4, #0
    adds r2, r6, #0
    bl func_0801C198
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_8175_12
    ldr r0, .Lraw_game_state_8175_4
    adds r5, r4, r0
    ldr r0, [r5]
    ldr r1, .Lraw_game_state_8175_8
    adds r0, r0, r1
    adds r7, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    bl GetCellType__C14MineFloorStateUiUi
    movs r2, #0
    mov sl, r2
    cmp r0, #0
    bne .Lraw_game_state_8163_2
    movs r0, #1
    mov sl, r0
.Lraw_game_state_8163_2:
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    ldr r3, [r5]
    adds r0, r7, #0
    bl DigSoil__14MineFloorStateUiUiR18GameStateSaveImage
    mov r1, r8
    str r0, [r1]
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    mov r2, sb
    ldrh r1, [r2]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    cmp r0, r1
    bne .Lraw_game_state_8175_0
    ldr r5, [r4, #4]
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellType__C14MineFloorStateUiUi
    adds r4, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellTilemap__C14MineFloorStateUiUi
    add r1, sp, #4
    ldrh r1, [r1]
    ldrh r2, [r6, #2]
    str r0, [sp]
    adds r0, r5, #0
    adds r3, r4, #0
    bl func_080AA540
.Lraw_game_state_8175_0:
    mov r0, sl
    b .Lraw_game_state_8175_14
.Lraw_game_state_8175_4: .word 0x00001038
.Lraw_game_state_8175_8: .word 0x00002E58
.Lraw_game_state_8175_12:
    movs r0, #0
.Lraw_game_state_8175_14:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
    .global CreateWorldEventIcon
    .thumb_func
CreateWorldEventIcon:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    mov sb, r0
    mov sl, r1
    adds r5, r2, #0
    adds r6, r3, #0
    ldr r7, [sp, #0x2c]
    ldr r0, [sp, #0x30]
    lsls r2, r0, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #8]
    ldr r0, .Lraw_game_state_8211_0
    ldr r4, [r0]
    ldr r0, .Lraw_game_state_8211_4
    adds r4, r4, r0
    lsls r0, r1, #1
    add r0, sl
    lsls r0, r0, #2
    adds r4, r4, r0
    ldrb r1, [r4]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r4]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    ldr r1, .Lraw_game_state_8211_8
    mov r8, r1
    mov r1, r8
    ands r0, r1
    ldrh r3, [r4, #2]
    ldr r2, .Lraw_game_state_8211_12
    adds r1, r2, #0
    ands r1, r3
    orrs r1, r0
    strh r1, [r4, #2]
    lsls r5, r5, #0x10
    lsrs r1, r5, #0x10
    movs r0, #0x3f
    ands r1, r0
    lsls r1, r1, #2
    ldrb r3, [r4, #3]
    movs r0, #3
    mov ip, r0
    movs r0, #3
    ands r0, r3
    orrs r0, r1
    strb r0, [r4, #3]
    lsrs r5, r5, #0x16
    mov r1, r8
    ands r5, r1
    ldrh r0, [r4, #4]
    ands r2, r0
    orrs r2, r5
    strh r2, [r4, #4]
    lsls r6, r6, #0x10
    lsrs r6, r6, #6
    ldr r0, [r4, #4]
    ldr r1, .Lraw_game_state_8212_0
    ands r0, r1
    orrs r0, r6
    str r0, [r4, #4]
    mov r0, ip
    ands r7, r0
    lsls r2, r7, #2
    ldrb r1, [r4]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4]
    mov r1, sp
    ldrh r1, [r1, #8]
    strh r1, [r4, #8]
    ldr r0, .Lraw_game_state_8212_4
    add r0, sb
    mov r8, r0
    mov r1, sl
    lsls r1, r1, #2
    mov sl, r1
    add r8, sl
    movs r0, #0x4c
    bl __builtin_new
    adds r5, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x64]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    adds r0, r5, #0
    mov r1, sb
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .Lraw_game_state_8213_0
    str r0, [r5, #0x24]
    movs r0, #0x28
    adds r0, r0, r5
    mov sb, r0
    ldr r6, [r4]
    mov r0, sp
    ldr r3, [r6, #0xc]
    adds r1, r4, #0
    ldr r2, [sp, #8]
    bl _call_via_r3
    ldr r0, [sp]
    ldrh r2, [r0]
    mov r0, sb
    ldr r3, [r6, #0x10]
    adds r1, r4, #0
    bl _call_via_r3
    adds r1, r5, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    mov r4, r8
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_8209_0
    cmp r1, #0
    beq .Lraw_game_state_8209_0
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_8209_0:
    str r5, [r4]
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Lraw_game_state_8211_0: .word gUnk_0300040C
.Lraw_game_state_8211_4: .word 0x000004DC
.Lraw_game_state_8211_8: .word 0x000003FF
.Lraw_game_state_8211_12: .word 0xFFFFFC00
.Lraw_game_state_8212_0: .word 0xFC0003FF
.Lraw_game_state_8212_4: .word 0x000010B0
.Lraw_game_state_8213_0: .4byte __vt_20GameSceneGroupSprite
    .global RemoveWorldEventIcon
    .thumb_func
RemoveWorldEventIcon:
    push {r4, r5, lr}
    ldr r2, .Lraw_game_state_8224_0
    ldr r3, [r2]
    ldr r2, .Lraw_game_state_8224_4
    adds r3, r3, r2
    lsls r2, r1, #1
    adds r2, r2, r1
    lsls r2, r2, #2
    adds r3, r3, r2
    ldrb r4, [r3]
    movs r2, #4
    rsbs r2, r2, #0
    ands r2, r4
    strb r2, [r3]
    ldr r2, .Lraw_game_state_8224_8
    adds r0, r0, r2
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .Lraw_game_state_8223_0
    cmp r1, #0
    beq .Lraw_game_state_8223_0
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Lraw_game_state_8223_0:
    str r5, [r4]
    pop {r4, r5}
    pop {r0}
    bx r0
.Lraw_game_state_8224_0: .word gUnk_0300040C
.Lraw_game_state_8224_4: .word 0x000004DC
.Lraw_game_state_8224_8: .word 0x000010B0

    thumb_func_start func_0801C6EC
func_0801C6EC: @ 0x0801C6EC
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    adds r7, r0, #0
    mov r8, r1
    mov sb, r2
    str r3, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    ldr r0, [r7]
    ldr r1, [r0, #0x14]
    adds r0, r7, #0
    bl _call_via_r1
    cmp r0, #2
    beq .L0801C714
    b .L0801C862
.L0801C714:
    mov r1, r8
    lsls r0, r1, #1
    adds r0, #0x22
    str r0, [sp, #0xc]
    mov r2, sb
    lsls r0, r2, #1
    adds r0, #0x16
    mov sl, r0
    movs r2, #0
    ldr r3, .L0801C79C @ =0x00001081
    adds r5, r7, r3
    ldr r0, .L0801C7A0 @ =0x00001084
    adds r4, r7, r0
.L0801C72E:
    ldrb r1, [r5]
    lsls r0, r1, #0x1e
    lsrs r6, r0, #0x1e
    cmp r6, #1
    bne .L0801C7B4
    ldr r3, [sp, #0xc]
    ldrh r0, [r4]
    cmp r3, r0
    bne .L0801C7B4
    ldrh r3, [r4, #2]
    cmp sl, r3
    bne .L0801C7B4
    lsls r0, r1, #0x1c
    lsrs r0, r0, #0x1e
    cmp r0, #2
    bne .L0801C750
    b .L0801C862
.L0801C750:
    ldr r1, .L0801C7A4 @ =0x00001054
    adds r0, r7, r1
    ldr r0, [r0]
    movs r1, #0
    movs r2, #0xc0
    bl PlaySong__9GameSceneiUi
    ldrb r1, [r5]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r1, r0
    movs r0, #8
    orrs r1, r0
    strb r1, [r5]
    ldr r4, [r4, #4]
    adds r0, r4, #0
    adds r0, #0x28
    ldr r1, .L0801C7A8 @ =0x00000873
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x3c
    movs r1, #0
    strb r6, [r0]
    adds r0, #2
    strb r1, [r0]
    adds r0, #1
    strb r6, [r0]
    ldr r3, .L0801C7AC @ =0x00001038
    adds r0, r7, r3
    ldr r0, [r0]
    ldr r5, .L0801C7B0 @ =0x00001BD8
    adds r0, r0, r5
    bl func_0800EEF8
    b .L0801C862
    .align 2, 0
.L0801C79C: .4byte 0x00001081
.L0801C7A0: .4byte 0x00001084
.L0801C7A4: .4byte 0x00001054
.L0801C7A8: .4byte 0x00000873
.L0801C7AC: .4byte 0x00001038
.L0801C7B0: .4byte 0x00001BD8
.L0801C7B4:
    adds r5, #0xc
    adds r4, #0xc
    adds r2, #1
    cmp r2, #3
    bls .L0801C72E
    movs r0, #0
    cmp r0, #0
    bne .L0801C862
    ldr r0, .L0801C818 @ =0x00001038
    adds r6, r7, r0
    ldr r1, [r6]
    ldr r5, .L0801C81C @ =0x000009DC
    adds r1, r1, r5
    movs r0, #0x2b
    mov r4, sb
    muls r4, r0, r4
    add r4, r8
    lsls r4, r4, #2
    adds r1, r1, r4
    str r1, [sp, #0x10]
    adds r0, r1, #0
    ldr r1, [sp, #4]
    bl method_0800A238__9FieldPloti
    str r0, [sp, #8]
    ldr r7, [r7, #4]
    ldr r0, [r6]
    adds r3, r0, r5
    adds r4, r3, r4
    mov r1, sb
    adds r1, #1
    movs r0, #0
    mov r2, r8
    cmp r2, #0
    blt .L0801C808
    cmp r1, #0
    blt .L0801C808
    cmp r2, #0x2a
    bgt .L0801C808
    cmp r1, #0x18
    bgt .L0801C808
    movs r0, #1
.L0801C808:
    cmp r0, #0
    beq .L0801C820
    movs r0, #0x2b
    muls r0, r1, r0
    add r0, r8
    lsls r0, r0, #2
    adds r1, r3, r0
    b .L0801C822
    .align 2, 0
.L0801C818: .4byte 0x00001038
.L0801C81C: .4byte 0x000009DC
.L0801C820:
    movs r1, #0
.L0801C822:
    mov r2, sb
    subs r2, #1
    movs r0, #0
    mov r5, r8
    cmp r5, #0
    blt .L0801C83C
    cmp r2, #0
    blt .L0801C83C
    cmp r5, #0x2a
    bgt .L0801C83C
    cmp r2, #0x18
    bgt .L0801C83C
    movs r0, #1
.L0801C83C:
    cmp r0, #0
    beq .L0801C84C
    movs r0, #0x2b
    muls r0, r2, r0
    add r0, r8
    lsls r0, r0, #2
    adds r2, r3, r0
    b .L0801C84E
.L0801C84C:
    movs r2, #0
.L0801C84E:
    adds r0, r4, #0
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    adds r0, r7, #0
    ldr r1, [sp, #0xc]
    mov r2, sl
    ldr r3, [sp, #0x10]
    bl RefreshFieldPlotTiles
.L0801C862:
    ldr r0, [sp, #8]
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start func_0801C874
func_0801C874: @ 0x0801C874
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r7, r0, #0
    mov sl, r3
    ldr r3, .L0801C8C0 @ =0x00001038
    adds r0, r7, r3
    ldr r3, [r0]
    ldr r0, .L0801C8C4 @ =0x000009DC
    adds r3, r3, r0
    movs r0, #0x2b
    muls r0, r2, r0
    adds r0, r1, r0
    lsls r0, r0, #2
    adds r4, r3, r0
    adds r6, r1, #0
    mov r8, r2
    adds r0, r4, #0
    bl method_0800A78C__C9FieldPlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801C916
    adds r0, r4, #0
    bl func_0801740C
    cmp r0, #1
    beq .L0801C8C8
    cmp r0, #1
    ble .L0801C8DC
    cmp r0, #2
    beq .L0801C8CC
    cmp r0, #3
    beq .L0801C8D4
    b .L0801C8DC
    .align 2, 0
.L0801C8C0: .4byte 0x00001038
.L0801C8C4: .4byte 0x000009DC
.L0801C8C8:
    subs r6, #1
    b .L0801C8DC
.L0801C8CC:
    movs r1, #1
    rsbs r1, r1, #0
    add r8, r1
    b .L0801C8DC
.L0801C8D4:
    subs r6, #1
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
.L0801C8DC:
    adds r0, r7, #0
    adds r1, r6, #0
    mov r2, r8
    mov r3, sl
    bl func_0801C6EC
    mov sb, r0
    adds r5, r6, #1
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    mov r3, sl
    bl func_0801C6EC
    mov r4, r8
    adds r4, #1
    adds r0, r7, #0
    adds r1, r6, #0
    adds r2, r4, #0
    mov r3, sl
    bl func_0801C6EC
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    mov r3, sl
    bl func_0801C6EC
    b .L0801C924
.L0801C916:
    adds r0, r7, #0
    adds r1, r6, #0
    mov r2, r8
    mov r3, sl
    bl func_0801C6EC
    mov sb, r0
.L0801C924:
    ldr r0, [r7]
    ldr r1, [r0, #0x14]
    adds r0, r7, #0
    bl _call_via_r1
    cmp r0, #2
    bne .L0801CA06
    mov r3, sb
    cmp r3, #8
    bhi .L0801CA06
    lsls r0, r3, #2
    ldr r1, .L0801C944 @ =.L0801C948
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801C944: .4byte .L0801C948
.L0801C948: @ jump table
    .4byte .L0801CA06 @ case 0
    .4byte .L0801CA06 @ case 1
    .4byte .L0801CA06 @ case 2
    .4byte .L0801C96C @ case 3
    .4byte .L0801C98C @ case 4
    .4byte .L0801C9AC @ case 5
    .4byte .L0801CA06 @ case 6
    .4byte .L0801C9CC @ case 7
    .4byte .L0801C9EC @ case 8
.L0801C96C:
    ldr r1, .L0801C988 @ =0x00001028
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #3
    bl func_080AB68C
    b .L0801CA06
    .align 2, 0
.L0801C988: .4byte 0x00001028
.L0801C98C:
    ldr r1, .L0801C9A8 @ =0x00001028
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #1
    bl func_080AB68C
    b .L0801CA06
    .align 2, 0
.L0801C9A8: .4byte 0x00001028
.L0801C9AC:
    ldr r1, .L0801C9C8 @ =0x00001028
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xc0
    movs r3, #2
    bl func_080AB68C
    b .L0801CA06
    .align 2, 0
.L0801C9C8: .4byte 0x00001028
.L0801C9CC:
    ldr r1, .L0801C9E8 @ =0x00001028
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x90
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #8
    bl func_080AB68C
    b .L0801CA06
    .align 2, 0
.L0801C9E8: .4byte 0x00001028
.L0801C9EC:
    ldr r1, .L0801CA18 @ =0x00001028
    adds r0, r7, r1
    ldr r0, [r0]
    lsls r1, r6, #4
    movs r2, #0x90
    lsls r2, r2, #1
    adds r1, r1, r2
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #6
    bl func_080AB68C
.L0801CA06:
    movs r0, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801CA18: .4byte 0x00001028
.L0801CA1C:
    .global func_0801CA1C
    .thumb_func
func_0801CA1C:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x24
    adds r5, r0, #0
    adds r6, r1, #0
    adds r7, r2, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    adds r0, r5, #0
    adds r1, r6, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_8637_0
    add r0, sp, #4
    ldrh r1, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldr r0, .Lraw_game_state_8636_0
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl func_0801C874
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b .Lraw_game_state_8649_6
.Lraw_game_state_8636_0: .4byte gUnk_080F0800
.Lraw_game_state_8637_0:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, .Lraw_game_state_8642_0
    adds r0, r7, r0
    ldrb r2, [r0]
    str r4, [sp]
    adds r0, r5, #0
    adds r1, r6, #0
    movs r3, #1
    bl func_0801D104
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lraw_game_state_8649_0
    ldr r0, [r4, #4]
    cmp r0, #6
    beq .Lraw_game_state_8643_0
    cmp r0, #9
    beq .Lraw_game_state_8647_0
    movs r0, #0
    b .Lraw_game_state_8649_6
.Lraw_game_state_8642_0: .4byte gUnk_080F0800
.Lraw_game_state_8643_0:
    ldr r1, .Lraw_game_state_8646_4
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #6
    bl func_080AB68C
    b .Lraw_game_state_8649_0
    .align 2, 0
.Lraw_game_state_8646_4: .word 0x00001028
.Lraw_game_state_8647_0:
    ldr r1, .Lraw_game_state_8650_4
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x18
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #9
    bl func_080AB68C
.Lraw_game_state_8649_0:
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
.Lraw_game_state_8649_6:
    add sp, #0x24
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_8650_4: .word 0x00001028
    .global func_0801CAD8
    .thumb_func
func_0801CAD8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    mov r8, r0
    mov sb, r1
    adds r5, r2, #0
    movs r0, #0
    str r0, [r5]
    add r6, sp, #4
    mov r0, r8
    adds r2, r6, #0
    bl func_0801C198
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_8679_12
    ldr r4, .Lraw_game_state_8679_0
    add r4, r8
    ldr r0, [r4]
    ldr r1, .Lraw_game_state_8679_4
    adds r0, r0, r1
    adds r7, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    bl GetCellType__C14MineFloorStateUiUi
    movs r1, #0
    cmp r0, #4
    bne .Lraw_game_state_8661_8
    movs r1, #1
.Lraw_game_state_8661_8:
    mov sl, r1
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    ldr r3, [r4]
    adds r0, r7, #0
    bl BreakRock__14MineFloorStateUiUiR18GameStateSaveImage
    str r0, [r5]
    mov r2, r8
    ldr r0, [r2]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    mov r2, sb
    ldrh r1, [r2]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    cmp r0, r1
    bne .Lraw_game_state_8678_0
    mov r0, r8
    ldr r5, [r0, #4]
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellType__C14MineFloorStateUiUi
    adds r4, r0, #0
    ldrh r1, [r6, #4]
    ldrh r2, [r6, #6]
    adds r0, r7, #0
    bl GetCellTilemap__C14MineFloorStateUiUi
    add r1, sp, #4
    ldrh r1, [r1]
    ldrh r2, [r6, #2]
    str r0, [sp]
    adds r0, r5, #0
    adds r3, r4, #0
    bl func_080AA540
    mov r1, sl
    cmp r1, #0
    beq .Lraw_game_state_8678_0
    ldr r0, .Lraw_game_state_8679_8
    add r0, r8
    ldr r0, [r0]
    add r1, sp, #4
    ldrh r1, [r1]
    lsls r1, r1, #3
    adds r1, #8
    ldrh r2, [r6, #2]
    lsls r2, r2, #3
    adds r2, #0x10
    movs r3, #5
    bl func_080AB68C
.Lraw_game_state_8678_0:
    mov r0, sl
    b .Lraw_game_state_8679_14
.Lraw_game_state_8679_0: .word 0x00001038
.Lraw_game_state_8679_4: .word 0x00002E58
.Lraw_game_state_8679_8: .word 0x00001028
.Lraw_game_state_8679_12:
    movs r0, #0
.Lraw_game_state_8679_14:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
    .global func_0801CBB0
    .thumb_func
func_0801CBB0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov sb, r0
    str r1, [sp, #0x38]
    mov sl, r2
    movs r6, #0
    cmp r1, #2
    bne .Lraw_game_state_8695_0
    movs r1, #0
    ldr r0, .Lraw_game_state_8693_0
    add r0, sl
    mov r8, r0
.Lraw_game_state_8686_0:
    movs r5, #0
    adds r7, r1, #1
    movs r0, #0xac
    adds r4, r1, #0
    muls r4, r0, r4
.Lraw_game_state_8686_10:
    ldr r0, .Lraw_game_state_8694_0
    add r0, sb
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_8694_4
    adds r0, r0, r1
    adds r0, r0, r4
    mov r2, r8
    ldrb r1, [r2]
    bl method_0800A238__9FieldPloti
    movs r2, #0
    adds r1, r6, #0
    cmp r0, #0
    beq .Lraw_game_state_8690_10
    movs r1, #1
    orrs r1, r6
.Lraw_game_state_8690_10:
    cmp r1, #0
    beq .Lraw_game_state_8691_0
    movs r2, #1
.Lraw_game_state_8691_0:
    adds r6, r2, #0
    adds r4, #4
    adds r5, #1
    cmp r5, #0x2a
    bls .Lraw_game_state_8686_10
    adds r1, r7, #0
    cmp r1, #0x18
    bls .Lraw_game_state_8686_0
    b .Lraw_game_state_8709_14
    .align 2, 0
.Lraw_game_state_8693_0: .4byte gUnk_080F0800
.Lraw_game_state_8694_0: .word 0x00001038
.Lraw_game_state_8694_4: .word 0x000009DC
.Lraw_game_state_8695_0:
    ldr r4, .Lraw_game_state_8714_4
    add r4, sb
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r3, .Lraw_game_state_8714_8
    adds r7, r0, r3
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, .Lraw_game_state_8715_0
    add sl, r0
.Lraw_game_state_8698_12:
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    bl IsAvailable__C14FieldItemStateUii
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_8709_8
    add r0, sp, #0xc
    adds r1, r7, #0
    adds r2, r5, #0
    bl GetRecord__C14FieldItemStateUi
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0x38]
    cmp r0, r1
    bne .Lraw_game_state_8709_8
    movs r0, #0
    strb r0, [r4]
    movs r2, #1
    strb r2, [r4, #0x10]
    ldr r0, .Lraw_game_state_8714_4
    add r0, sb
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, .Lraw_game_state_8714_8
    adds r1, r1, r3
    mov r3, sl
    ldrb r2, [r3]
    str r2, [sp]
    add r2, sp, #4
    movs r3, #1
    strb r3, [r2]
    str r4, [sp, #8]
    adds r2, r5, #0
    mov r3, r8
    bl func_080174C8
    rsbs r0, r6, #0
    orrs r0, r6
    lsrs r6, r0, #0x1f
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    orrs r6, r0
.Lraw_game_state_8709_8:
    adds r5, #1
    cmp r5, #0x73
    bls .Lraw_game_state_8698_12
.Lraw_game_state_8709_14:
    cmp r6, #0
    beq .Lraw_game_state_8713_0
    mov r2, sb
    ldr r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #1
    adds r0, r0, r3
    add r1, sp, #0x30
    ldr r2, .Lraw_game_state_8716_0
    movs r3, #0
    str r2, [sp, #0x30]
    str r3, [r1, #4]
    ldr r3, [r0]
    mov r0, sb
    movs r2, #0
    bl _call_via_r3
.Lraw_game_state_8713_0:
    adds r0, r6, #0
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_8714_4: .word 0x00001038
.Lraw_game_state_8714_8: .word 0x000034C8
.Lraw_game_state_8715_0: .4byte gUnk_080F0800
.Lraw_game_state_8716_0: .word 0x000003DD

    thumb_func_start func_0801CCE4
func_0801CCE4: @ 0x0801CCE4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    mov r8, r2
    adds r1, r3, #0
    ldr r0, .L0801CD5C @ =0x00001038
    adds r7, r4, r0
    ldr r2, [r7]
    ldr r3, .L0801CD60 @ =0x000009DC
    adds r2, r2, r3
    movs r0, #0x2b
    mov r3, r8
    muls r3, r0, r3
    adds r0, r3, #0
    adds r0, r5, r0
    lsls r6, r0, #2
    adds r2, r2, r6
    mov sb, r2
    mov r0, sb
    bl method_0800A33C__9FieldPloti
    str r0, [sp, #4]
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    cmp r0, #2
    bne .L0801CDAA
    ldr r4, [r4, #4]
    mov sl, r4
    ldr r0, [r7]
    ldr r1, .L0801CD60 @ =0x000009DC
    adds r2, r0, r1
    adds r4, r2, r6
    mov r1, r8
    adds r1, #1
    movs r0, #0
    cmp r5, #0
    blt .L0801CD4C
    cmp r1, #0
    blt .L0801CD4C
    cmp r5, #0x2a
    bgt .L0801CD4C
    cmp r1, #0x18
    bgt .L0801CD4C
    movs r0, #1
.L0801CD4C:
    cmp r0, #0
    beq .L0801CD64
    movs r0, #0x2b
    muls r0, r1, r0
    adds r0, r5, r0
    lsls r0, r0, #2
    adds r1, r2, r0
    b .L0801CD66
    .align 2, 0
.L0801CD5C: .4byte 0x00001038
.L0801CD60: .4byte 0x000009DC
.L0801CD64:
    movs r1, #0
.L0801CD66:
    mov r3, r8
    subs r3, #1
    movs r0, #0
    cmp r5, #0
    blt .L0801CD7E
    cmp r3, #0
    blt .L0801CD7E
    cmp r5, #0x2a
    bgt .L0801CD7E
    cmp r3, #0x18
    bgt .L0801CD7E
    movs r0, #1
.L0801CD7E:
    cmp r0, #0
    beq .L0801CD8E
    movs r0, #0x2b
    muls r0, r3, r0
    adds r0, r5, r0
    lsls r0, r0, #2
    adds r2, r2, r0
    b .L0801CD90
.L0801CD8E:
    movs r2, #0
.L0801CD90:
    adds r0, r4, #0
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    lsls r1, r5, #1
    adds r1, #0x22
    mov r3, r8
    lsls r2, r3, #1
    adds r2, #0x16
    str r0, [sp]
    mov r0, sl
    mov r3, sb
    bl RefreshFieldPlotTiles
.L0801CDAA:
    ldr r0, [sp, #4]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start func_0801CDBC
func_0801CDBC: @ 0x0801CDBC
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r0, #0
    mov sl, r3
    ldr r3, .L0801CE08 @ =0x00001038
    adds r0, r6, r3
    ldr r3, [r0]
    ldr r0, .L0801CE0C @ =0x000009DC
    adds r3, r3, r0
    movs r0, #0x2b
    muls r0, r2, r0
    adds r0, r1, r0
    lsls r0, r0, #2
    adds r4, r3, r0
    adds r7, r1, #0
    mov r8, r2
    adds r0, r4, #0
    bl method_0800A78C__C9FieldPlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801CE5E
    adds r0, r4, #0
    bl func_0801740C
    cmp r0, #1
    beq .L0801CE10
    cmp r0, #1
    ble .L0801CE24
    cmp r0, #2
    beq .L0801CE14
    cmp r0, #3
    beq .L0801CE1C
    b .L0801CE24
    .align 2, 0
.L0801CE08: .4byte 0x00001038
.L0801CE0C: .4byte 0x000009DC
.L0801CE10:
    subs r7, #1
    b .L0801CE24
.L0801CE14:
    movs r1, #1
    rsbs r1, r1, #0
    add r8, r1
    b .L0801CE24
.L0801CE1C:
    subs r7, #1
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
.L0801CE24:
    adds r0, r6, #0
    adds r1, r7, #0
    mov r2, r8
    mov r3, sl
    bl func_0801CCE4
    mov sb, r0
    adds r5, r7, #1
    adds r0, r6, #0
    adds r1, r5, #0
    mov r2, r8
    mov r3, sl
    bl func_0801CCE4
    mov r4, r8
    adds r4, #1
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    mov r3, sl
    bl func_0801CCE4
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    mov r3, sl
    bl func_0801CCE4
    b .L0801CE6C
.L0801CE5E:
    adds r0, r6, #0
    adds r1, r7, #0
    mov r2, r8
    mov r3, sl
    bl func_0801CCE4
    mov sb, r0
.L0801CE6C:
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    cmp r0, #2
    bne .L0801CEE4
    mov r3, sb
    cmp r3, #1
    beq .L0801CE8A
    cmp r3, #1
    ble .L0801CEE4
    cmp r3, #2
    beq .L0801CEBC
    b .L0801CEE4
.L0801CE8A:
    ldr r1, .L0801CEB4 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #1
    bl method_08009B68__4FarmUi
    ldr r2, .L0801CEB8 @ =0x00001028
    adds r0, r6, r2
    ldr r0, [r0]
    lsls r1, r7, #4
    movs r3, #0x8c
    lsls r3, r3, #1
    adds r1, r1, r3
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xbb
    movs r3, #4
    bl func_080AB68C
    b .L0801CEE4
    .align 2, 0
.L0801CEB4: .4byte 0x00001038
.L0801CEB8: .4byte 0x00001028
.L0801CEBC:
    ldr r1, .L0801CEF4 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #6
    bl method_08009B68__4FarmUi
    ldr r2, .L0801CEF8 @ =0x00001028
    adds r0, r6, r2
    ldr r0, [r0]
    lsls r1, r7, #4
    movs r3, #0x90
    lsls r3, r3, #1
    adds r1, r1, r3
    mov r3, r8
    lsls r2, r3, #4
    adds r2, #0xd0
    movs r3, #7
    bl func_080AB68C
.L0801CEE4:
    movs r0, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801CEF4: .4byte 0x00001038
.L0801CEF8: .4byte 0x00001028
.L0801CEFC:
    .global func_0801CEFC
    .thumb_func
func_0801CEFC:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x24
    adds r5, r0, #0
    adds r6, r1, #0
    adds r7, r2, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    adds r0, r5, #0
    adds r1, r6, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_9000_0
    add r0, sp, #4
    ldrh r1, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldr r0, .Lraw_game_state_8999_0
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl func_0801CDBC
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b .Lraw_game_state_9012_6
.Lraw_game_state_8999_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_9000_0:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, .Lraw_game_state_9005_0
    adds r0, r7, r0
    ldrb r2, [r0]
    str r4, [sp]
    adds r0, r5, #0
    adds r1, r6, #0
    movs r3, #0
    bl func_0801D104
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lraw_game_state_9012_0
    ldr r0, [r4, #4]
    cmp r0, #4
    beq .Lraw_game_state_9010_0
    cmp r0, #7
    beq .Lraw_game_state_9006_0
    movs r0, #0
    b .Lraw_game_state_9012_6
.Lraw_game_state_9005_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_9006_0:
    ldr r1, .Lraw_game_state_9009_4
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #7
    bl func_080AB68C
    b .Lraw_game_state_9012_0
    .align 2, 0
.Lraw_game_state_9009_4: .word 0x00001028
.Lraw_game_state_9010_0:
    ldr r1, .Lraw_game_state_9013_4
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #8
    ldr r2, [r4, #0xc]
    adds r2, #0xb
    movs r3, #4
    bl func_080AB68C
.Lraw_game_state_9012_0:
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
.Lraw_game_state_9012_6:
    add sp, #0x24
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Lraw_game_state_9013_4: .word 0x00001028
    .global func_0801CFB8
    .thumb_func
func_0801CFB8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r0, [sp, #0x38]
    mov sb, r1
    mov sl, r2
    movs r6, #0
    cmp r1, #2
    bne .Lraw_game_state_9031_0
    movs r1, #0
    ldr r2, .Lraw_game_state_9028_4
    adds r7, r0, r2
    ldr r0, .Lraw_game_state_9029_0
    add sl, r0
.Lraw_game_state_9019_10:
    movs r5, #0
    adds r3, r1, #1
    mov sb, r3
    movs r2, #0x2b
    adds r0, r1, #0
    muls r0, r2, r0
    mov r8, r0
.Lraw_game_state_9020_8:
    ldr r0, [r7]
    ldr r3, .Lraw_game_state_9030_0
    adds r0, r0, r3
    mov r2, r8
    adds r1, r5, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov r3, sl
    ldrb r1, [r3]
    bl method_0800A33C__9FieldPloti
    adds r4, r0, #0
    subs r0, r4, #1
    cmp r0, #1
    bhi .Lraw_game_state_9026_0
    ldr r0, [r7]
    adds r0, #0x14
    movs r1, #1
    bl method_08009B68__4FarmUi
.Lraw_game_state_9026_0:
    movs r1, #0
    adds r0, r6, #0
    cmp r4, #0
    beq .Lraw_game_state_9026_12
    movs r0, #1
    orrs r0, r6
.Lraw_game_state_9026_12:
    cmp r0, #0
    beq .Lraw_game_state_9027_2
    movs r1, #1
.Lraw_game_state_9027_2:
    adds r6, r1, #0
    adds r5, #1
    cmp r5, #0x2a
    bls .Lraw_game_state_9020_8
    mov r1, sb
    cmp r1, #0x18
    bls .Lraw_game_state_9019_10
    b .Lraw_game_state_9047_0
    .align 2, 0
.Lraw_game_state_9028_4: .word 0x00001038
.Lraw_game_state_9029_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_9030_0: .word 0x000009DC
.Lraw_game_state_9031_0:
    ldr r0, [sp, #0x38]
    ldr r1, .Lraw_game_state_9051_4
    adds r4, r0, r1
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r2, .Lraw_game_state_9051_8
    adds r7, r0, r2
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, .Lraw_game_state_9052_0
    add sl, r0
.Lraw_game_state_9034_14:
    adds r0, r7, #0
    adds r1, r5, #0
    mov r2, r8
    bl IsAvailable__C14FieldItemStateUii
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lraw_game_state_9046_10
    add r0, sp, #0xc
    adds r1, r7, #0
    adds r2, r5, #0
    bl GetRecord__C14FieldItemStateUi
    ldr r0, [sp, #0x10]
    cmp r0, sb
    bne .Lraw_game_state_9046_10
    movs r3, #0
    strb r3, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r1, [sp, #0x38]
    ldr r2, .Lraw_game_state_9051_4
    adds r0, r1, r2
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, .Lraw_game_state_9051_8
    adds r1, r1, r3
    mov r3, sl
    ldrb r2, [r3]
    str r2, [sp]
    add r2, sp, #4
    movs r3, #0
    strb r3, [r2]
    str r4, [sp, #8]
    adds r2, r5, #0
    mov r3, r8
    bl func_080174C8
    rsbs r0, r6, #0
    orrs r0, r6
    lsrs r6, r0, #0x1f
    ldrb r0, [r4, #0x10]
    movs r1, #1
    eors r0, r1
    orrs r6, r0
.Lraw_game_state_9046_10:
    adds r5, #1
    cmp r5, #0x73
    bls .Lraw_game_state_9034_14
.Lraw_game_state_9047_0:
    cmp r6, #0
    beq .Lraw_game_state_9050_0
    ldr r2, [sp, #0x38]
    ldr r0, [r2]
    movs r3, #0xa0
    lsls r3, r3, #1
    adds r0, r0, r3
    add r1, sp, #0x30
    ldr r2, .Lraw_game_state_9053_0
    movs r3, #0
    str r2, [sp, #0x30]
    str r3, [r1, #4]
    ldr r3, [r0]
    ldr r0, [sp, #0x38]
    movs r2, #0
    bl _call_via_r3
.Lraw_game_state_9050_0:
    adds r0, r6, #0
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.Lraw_game_state_9051_4: .word 0x00001038
.Lraw_game_state_9051_8: .word 0x000034C8
.Lraw_game_state_9052_0: .4byte gUnk_080F0800 + 7
.Lraw_game_state_9053_0: .word 0x000003CF

    thumb_func_start func_0801D104
func_0801D104: @ 0x0801D104
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    mov sl, r0
    adds r5, r1, #0
    str r2, [sp, #0x28]
    ldr r0, [sp, #0x50]
    mov sb, r0
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x2c]
    ldr r7, .L0801D1D4 @ =0x00001038
    add r7, sl
    ldr r0, [r7]
    ldr r1, .L0801D1D8 @ =0x000034C8
    adds r6, r0, r1
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldrb r0, [r5, #1]
    lsrs r0, r0, #2
    ldrh r1, [r5, #2]
    ldr r3, .L0801D1DC @ =0x000003FF
    ands r1, r3
    lsls r1, r1, #6
    orrs r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldrb r2, [r5, #3]
    lsrs r2, r2, #2
    ldrh r0, [r5, #4]
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    add r2, sp, #0x1c
    strh r1, [r2]
    strh r0, [r2, #2]
    adds r1, #1
    strh r1, [r2, #4]
    adds r0, #1
    strh r0, [r2, #6]
    ldrh r1, [r5]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    adds r0, r6, #0
    mov r3, r8
    bl Find__C14FieldItemStateUiRC3Boxi
    adds r4, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    cmp r4, r0
    beq .L0801D228
    add r0, sp, #0xc
    adds r1, r6, #0
    adds r2, r4, #0
    bl GetRecord__C14FieldItemStateUi
    add r6, sp, #0xc
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r2, .L0801D1D8 @ =0x000034C8
    adds r1, r1, r2
    ldr r3, [sp, #0x28]
    str r3, [sp]
    add r2, sp, #4
    add r7, sp, #0x2c
    ldrb r7, [r7]
    strb r7, [r2]
    mov r2, sb
    str r2, [sp, #8]
    adds r2, r4, #0
    mov r3, r8
    bl func_080174C8
    mov r3, sb
    ldrb r0, [r3]
    cmp r0, #0
    beq .L0801D224
    ldrh r0, [r5]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    mov r7, sl
    ldr r1, [r7, #4]
    ldr r2, [r1]
    adds r5, r1, #0
    cmp r0, r2
    bne .L0801D224
    ldr r0, [r3, #4]
    cmp r0, #6
    beq .L0801D1F4
    cmp r0, #6
    bgt .L0801D1E0
    cmp r0, #4
    beq .L0801D1EA
    b .L0801D228
    .align 2, 0
.L0801D1D4: .4byte 0x00001038
.L0801D1D8: .4byte 0x000034C8
.L0801D1DC: .4byte 0x000003FF
.L0801D1E0:
    cmp r0, #7
    beq .L0801D1F0
    cmp r0, #9
    beq .L0801D1F8
    b .L0801D228
.L0801D1EA:
    movs r3, #2
    movs r4, #2
    b .L0801D1FC
.L0801D1F0:
    movs r3, #4
    b .L0801D1FA
.L0801D1F4:
    movs r3, #4
    b .L0801D1FA
.L0801D1F8:
    movs r3, #6
.L0801D1FA:
    movs r4, #4
.L0801D1FC:
    movs r1, #8
    ldrsh r0, [r6, r1]
    cmp r0, #0
    bge .L0801D206
    adds r0, #7
.L0801D206:
    asrs r1, r0, #3
    movs r2, #0xa
    ldrsh r0, [r6, r2]
    cmp r0, #0
    bge .L0801D212
    adds r0, #7
.L0801D212:
    asrs r0, r0, #3
    add r2, sp, #0x24
    strh r1, [r2]
    strh r0, [r2, #2]
    str r4, [sp]
    adds r0, r5, #0
    movs r1, #1
    bl ClearWorldMapTileRectangle
.L0801D224:
    movs r0, #1
    b .L0801D22A
.L0801D228:
    movs r0, #0
.L0801D22A:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801D23C:
    .global func_0801D23C
    .thumb_func
func_0801D23C:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    mov r8, r0
    adds r4, r1, #0
    add r1, sp, #4
    movs r0, #0
    str r0, [sp, #4]
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strh r0, [r1, #8]
    strh r0, [r1, #0xa]
    mov r0, r8
    adds r1, r4, #0
    add r2, sp, #4
    bl TryGetFarmPlotAtLocation
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lraw_game_state_9225_8
    b .Lraw_game_state_9259_10
.Lraw_game_state_9225_8:
    ldr r0, [sp, #4]
    bl method_0800A3C8__9FieldPlot
    str r0, [sp, #0x10]
    cmp r0, #1
    beq .Lraw_game_state_9228_10
    rsbs r0, r0, #0
    str r0, [sp, #0x24]
    ldr r1, [sp, #0x10]
    cmp r1, #1
    bgt .Lraw_game_state_9228_4
    b .Lraw_game_state_9259_0
.Lraw_game_state_9228_4:
    cmp r1, #2
    beq .Lraw_game_state_9231_0
    b .Lraw_game_state_9259_0
.Lraw_game_state_9228_10:
    ldr r0, .Lraw_game_state_9245_12
    add r0, r8
    ldr r0, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    movs r1, #1
    bl AddStoredBushels__4BarnUi
.Lraw_game_state_9231_0:
    mov r3, r8
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    cmp r0, #2
    bne .Lraw_game_state_9237_0
    ldr r0, .Lraw_game_state_9246_0
    add r0, r8
    ldr r0, [r0]
    add r1, sp, #4
    ldrh r1, [r1, #4]
    lsls r1, r1, #3
    adds r1, #8
    add r2, sp, #4
    ldrh r2, [r2, #6]
    lsls r2, r2, #3
    adds r2, #0x10
    movs r3, #0
    bl func_080AB68C
.Lraw_game_state_9237_0:
    mov r1, r8
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, r8
    bl _call_via_r1
    ldrh r1, [r4]
    lsls r1, r1, #0x16
    lsrs r1, r1, #0x16
    ldr r2, [sp, #0x10]
    rsbs r2, r2, #0
    str r2, [sp, #0x24]
    cmp r0, r1
    beq .Lraw_game_state_9240_6
    b .Lraw_game_state_9259_0
.Lraw_game_state_9240_6:
    ldr r0, .Lraw_game_state_9245_12
    add r0, r8
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x14
    str r3, [sp, #0x14]
    add r0, sp, #4
    ldrh r4, [r0, #8]
    ldrh r2, [r0, #0xa]
    ldrh r0, [r0, #4]
    str r0, [sp, #0x18]
    add r0, sp, #4
    ldrh r0, [r0, #6]
    ldr r3, .Lraw_game_state_9246_4
    adds r3, r1, r3
    str r3, [sp, #0x20]
    subs r0, #2
    mov sb, r0
    movs r1, #0x2b
    adds r0, r2, #0
    muls r0, r1, r0
    adds r0, r0, r4
    adds r6, r0, #0
    subs r6, #0x2b
    subs r5, r2, #1
    movs r2, #2
    str r2, [sp, #0x1c]
.Lraw_game_state_9243_12:
    movs r0, #0
    cmp r4, #0
    blt .Lraw_game_state_9245_0
    cmp r5, #0
    blt .Lraw_game_state_9245_0
    cmp r4, #0x2a
    bgt .Lraw_game_state_9245_0
    cmp r5, #0x18
    bgt .Lraw_game_state_9245_0
    movs r0, #1
.Lraw_game_state_9245_0:
    cmp r0, #0
    beq .Lraw_game_state_9246_8
    lsls r0, r6, #2
    ldr r1, [sp, #0x20]
    adds r3, r1, r0
    b .Lraw_game_state_9246_10
.Lraw_game_state_9245_12: .word 0x00001038
.Lraw_game_state_9246_0: .word 0x00001028
.Lraw_game_state_9246_4: .word 0x000009DC
.Lraw_game_state_9246_8:
    movs r3, #0
.Lraw_game_state_9246_10:
    adds r7, r3, #0
    cmp r7, #0
    beq .Lraw_game_state_9257_0
    mov r2, r8
    ldr r2, [r2, #4]
    mov sl, r2
    ldr r3, [sp, #0x14]
    ldr r0, .Lraw_game_state_9250_12
    adds r2, r3, r0
    adds r3, r5, #0
    lsls r0, r6, #2
    adds r0, r0, r2
    mov ip, r0
    adds r0, r5, #1
    movs r1, #0
    cmp r4, #0
    blt .Lraw_game_state_9249_10
    cmp r0, #0
    blt .Lraw_game_state_9249_10
    cmp r4, #0x2a
    bgt .Lraw_game_state_9249_10
    cmp r0, #0x18
    bgt .Lraw_game_state_9249_10
    movs r1, #1
.Lraw_game_state_9249_10:
    cmp r1, #0
    beq .Lraw_game_state_9251_0
    movs r1, #0x2b
    muls r0, r1, r0
    adds r0, r4, r0
    lsls r0, r0, #2
    adds r1, r2, r0
    b .Lraw_game_state_9251_2
    .align 2, 0
.Lraw_game_state_9250_12: .word 0x000009C8
.Lraw_game_state_9251_0:
    movs r1, #0
.Lraw_game_state_9251_2:
    subs r0, r3, #1
    movs r3, #0
    cmp r4, #0
    blt .Lraw_game_state_9252_8
    cmp r0, #0
    blt .Lraw_game_state_9252_8
    cmp r4, #0x2a
    bgt .Lraw_game_state_9252_8
    cmp r0, #0x18
    bgt .Lraw_game_state_9252_8
    movs r3, #1
.Lraw_game_state_9252_8:
    cmp r3, #0
    beq .Lraw_game_state_9253_8
    movs r3, #0x2b
    muls r0, r3, r0
    adds r0, r4, r0
    lsls r0, r0, #2
    adds r2, r2, r0
    b .Lraw_game_state_9253_10
.Lraw_game_state_9253_8:
    movs r2, #0
.Lraw_game_state_9253_10:
    mov r0, ip
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    mov r0, sl
    ldr r1, [sp, #0x18]
    mov r2, sb
    adds r3, r7, #0
    bl RefreshFieldPlotTiles
.Lraw_game_state_9257_0:
    movs r0, #2
    add sb, r0
    adds r6, #0x2b
    adds r5, #1
    ldr r1, [sp, #0x1c]
    subs r1, #1
    str r1, [sp, #0x1c]
    cmp r1, #0
    bge .Lraw_game_state_9243_12
.Lraw_game_state_9259_0:
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x10]
    orrs r2, r3
    lsrs r0, r2, #0x1f
    b .Lraw_game_state_9259_12
.Lraw_game_state_9259_10:
    movs r0, #0
.Lraw_game_state_9259_12:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .section .text.game_scene_after_record_player_album, "ax", %progbits
    .align 2, 0

    thumb_func_start func_0801DEB4
func_0801DEB4: @ 0x0801DEB4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x20
    mov sl, r0
    adds r7, r1, #0
    movs r0, #0
    str r0, [sp, #4]
    mov r8, r0
    movs r1, #0
    str r1, [sp, #8]
    mov ip, r1
    movs r4, #0
    ldr r0, .L0801DFC8 @ =0x00001038
    add r0, sl
    ldr r0, [r0]
    ldr r2, .L0801DFCC @ =0x000009DC
    adds r2, r0, r2
    str r2, [sp, #0x18]
.L0801DEDE:
    movs r3, #0
    adds r6, r4, #1
    mov sb, r6
    movs r5, #0x8c
    lsls r5, r5, #1
    movs r0, #0xac
    muls r0, r4, r0
    ldr r1, [sp, #0x18]
    adds r2, r0, r1
    lsls r0, r4, #4
    adds r0, #0xb8
    str r0, [sp, #0x1c]
.L0801DEF6:
    ldr r1, [r2]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x1a
    cmp r0, #0x14
    bne .L0801DF3C
    lsls r0, r1, #0x14
    lsrs r0, r0, #0x1c
    cmp r0, #5
    bne .L0801DF3C
    movs r6, #0
    ldrsh r1, [r7, r6]
    subs r1, r5, r1
    movs r6, #2
    ldrsh r0, [r7, r6]
    ldr r6, [sp, #0x1c]
    subs r0, r6, r0
    adds r6, r1, #0
    muls r6, r1, r6
    adds r1, r6, #0
    adds r6, r0, #0
    muls r6, r0, r6
    adds r0, r6, #0
    adds r1, r1, r0
    adds r0, r1, #0
    mov r6, ip
    cmp r6, #0
    beq .L0801DF32
    ldr r6, [sp, #4]
    cmp r1, r6
    bge .L0801DF3C
.L0801DF32:
    movs r1, #1
    mov ip, r1
    mov r8, r3
    str r4, [sp, #8]
    str r0, [sp, #4]
.L0801DF3C:
    adds r5, #0x10
    adds r2, #4
    adds r3, #1
    cmp r3, #0x2a
    bls .L0801DEF6
    movs r1, #0x2b
    mov r4, sb
    cmp r4, #0x18
    bls .L0801DEDE
    mov r2, ip
    cmp r2, #0
    bne .L0801DF56
    b .L0801E072
.L0801DF56:
    ldr r0, .L0801DFC8 @ =0x00001038
    add r0, sl
    ldr r0, [r0]
    ldr r3, .L0801DFCC @ =0x000009DC
    adds r0, r0, r3
    ldr r6, [sp, #8]
    muls r1, r6, r1
    mov r7, r8
    adds r4, r7, r1
    lsls r1, r4, #2
    adds r0, r0, r1
    bl method_0800A3C8__9FieldPlot
    mov r1, sl
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sl
    bl _call_via_r1
    cmp r0, #2
    bne .L0801E06E
    lsls r0, r7, #1
    adds r0, #0x22
    str r0, [sp, #0xc]
    lsls r0, r6, #1
    mov r2, sl
    ldr r2, [r2, #4]
    str r2, [sp, #0x10]
    adds r0, #0x14
    mov sb, r0
    adds r5, r4, #0
    subs r5, #0x2b
    adds r4, r6, #0
    subs r4, #1
    movs r3, #2
    str r3, [sp, #0x14]
.L0801DF9E:
    ldr r0, .L0801DFC8 @ =0x00001038
    add r0, sl
    ldr r0, [r0]
    ldr r6, .L0801DFCC @ =0x000009DC
    adds r1, r0, r6
    movs r0, #0
    mov r7, r8
    cmp r7, #0
    blt .L0801DFBE
    cmp r4, #0
    blt .L0801DFBE
    cmp r7, #0x2a
    bgt .L0801DFBE
    cmp r4, #0x18
    bgt .L0801DFBE
    movs r0, #1
.L0801DFBE:
    cmp r0, #0
    beq .L0801DFD0
    lsls r0, r5, #2
    adds r3, r1, r0
    b .L0801DFD2
    .align 2, 0
.L0801DFC8: .4byte 0x00001038
.L0801DFCC: .4byte 0x000009DC
.L0801DFD0:
    movs r3, #0
.L0801DFD2:
    adds r6, r3, #0
    cmp r6, #0
    beq .L0801E05C
    ldr r0, .L0801E014 @ =0x00001038
    add r0, sl
    ldr r0, [r0]
    ldr r1, .L0801E018 @ =0x000009DC
    adds r2, r0, r1
    adds r3, r4, #0
    lsls r0, r5, #2
    adds r0, r0, r2
    mov ip, r0
    adds r0, r4, #1
    movs r1, #0
    mov r7, r8
    cmp r7, #0
    blt .L0801E002
    cmp r0, #0
    blt .L0801E002
    cmp r7, #0x2a
    bgt .L0801E002
    cmp r0, #0x18
    bgt .L0801E002
    movs r1, #1
.L0801E002:
    cmp r1, #0
    beq .L0801E01C
    movs r1, #0x2b
    muls r0, r1, r0
    add r0, r8
    lsls r0, r0, #2
    adds r1, r2, r0
    b .L0801E01E
    .align 2, 0
.L0801E014: .4byte 0x00001038
.L0801E018: .4byte 0x000009DC
.L0801E01C:
    movs r1, #0
.L0801E01E:
    subs r0, r3, #1
    movs r3, #0
    mov r7, r8
    cmp r7, #0
    blt .L0801E036
    cmp r0, #0
    blt .L0801E036
    cmp r7, #0x2a
    bgt .L0801E036
    cmp r0, #0x18
    bgt .L0801E036
    movs r3, #1
.L0801E036:
    cmp r3, #0
    beq .L0801E046
    movs r3, #0x2b
    muls r0, r3, r0
    add r0, r8
    lsls r0, r0, #2
    adds r2, r2, r0
    b .L0801E048
.L0801E046:
    movs r2, #0
.L0801E048:
    mov r0, ip
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    str r0, [sp]
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0xc]
    mov r2, sb
    adds r3, r6, #0
    bl RefreshFieldPlotTiles
.L0801E05C:
    movs r6, #2
    add sb, r6
    adds r5, #0x2b
    adds r4, #1
    ldr r7, [sp, #0x14]
    subs r7, #1
    str r7, [sp, #0x14]
    cmp r7, #0
    bge .L0801DF9E
.L0801E06E:
    movs r0, #1
    b .L0801E074
.L0801E072:
    movs r0, #0
.L0801E074:
    add sp, #0x20
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
.L0801E084:
    .global func_0801E084
    .thumb_func
func_0801E084:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x4c
    str r0, [sp, #0x40]
    bl func_0801E90C
    movs r0, #0
    str r0, [sp, #0x44]
    movs r1, #0
    str r1, [sp, #0x48]
.Lraw_game_state_9517_8:
    ldr r2, [sp, #0x48]
    mov sb, r2
    ldr r3, [sp, #0x40]
    ldr r0, [r3]
    ldr r2, [r0, #0x40]
    adds r0, r3, #0
    ldr r1, [sp, #0x48]
    bl _call_via_r2
    adds r7, r0, #0
    cmp r7, #0
    bne .Lraw_game_state_9520_8
    b .L0801E630
.Lraw_game_state_9520_8:
    movs r0, #0
    mov sl, r0
    ldr r0, [sp, #0x48]
    subs r0, #0x2b
    cmp r0, #0x28
    bls .Lraw_game_state_9521_6
    b .L0801E29C
.Lraw_game_state_9521_6:
    lsls r0, r0, #2
    ldr r1, .Lraw_game_state_9522_0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
.Lraw_game_state_9522_0: .4byte .L0801E0D4
.L0801E0D4: .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E29C
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E29C
    .4byte .L0801E29C
    .4byte .L0801E29C
    .4byte .L0801E29C
    .4byte .L0801E18A
    .4byte .L0801E178
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
    .4byte .L0801E18A
.L0801E178:
    ldr r1, [sp, #0x40]
    ldr r2, .Lraw_game_state_9576_8
    adds r0, r1, r2
    ldr r0, [r0]
    ldr r0, [r0, #8]
    subs r0, #3
    cmp r0, #1
    bhi .L0801E18A
    b .Lraw_game_state_9603_4
.L0801E18A:
    ldrh r2, [r7, #4]
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r2, r0
    bne .Lraw_game_state_9570_6
    b .Lraw_game_state_9603_4
.Lraw_game_state_9570_6:
    ldr r3, [sp, #0x40]
    ldr r5, [r3, #4]
    ldr r0, [r5]
    cmp r2, r0
    bne .Lraw_game_state_9576_12
    ldr r0, [r5, #4]
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r0, [sp, #0x40]
    ldr r4, [r0, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    movs r2, #0
    ldr r0, [r4, #0x2c]
    add r1, sp, #4
    str r0, [sp, #4]
    str r2, [sp, #8]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x18
    b .Lraw_game_state_9578_12
.Lraw_game_state_9576_8: .word 0x00001038
.Lraw_game_state_9576_12:
    cmp r2, #2
    bne .Lraw_game_state_9584_12
    add r3, sp, #4
    ldr r1, [sp, #0x40]
    ldr r2, .Lraw_game_state_9584_8
    adds r0, r1, r2
    ldr r0, [r0]
    movs r1, #0x80
    movs r2, #0x58
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    strh r1, [r3, #8]
    strh r2, [r3, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x20
.Lraw_game_state_9578_12:
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r7, #0
    bl _call_via_r2
    add r0, sp, #4
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801E29C
    b .Lraw_game_state_9603_4
    .align 2, 0
.Lraw_game_state_9584_8: .word 0x00001050
.Lraw_game_state_9584_12:
    add r3, sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, .Lraw_game_state_9604_8
    adds r0, r1, #0
    ands r2, r0
    ldrh r1, [r3]
    ldr r4, .Lraw_game_state_9604_12
    adds r0, r4, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r3]
    ldrb r1, [r3, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3, #1]
    ldrh r1, [r3, #2]
    adds r0, r4, #0
    ands r0, r1
    strh r0, [r3, #2]
    ldrb r0, [r3, #3]
    ands r2, r0
    strb r2, [r3, #3]
    ldrh r0, [r3, #4]
    ands r4, r0
    strh r4, [r3, #4]
    movs r0, #0x1e
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    movs r2, #3
    movs r3, #0
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    movs r2, #1
    str r2, [sp, #0x44]
    ldr r3, [sp, #0x40]
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r0, [sp, #0x40]
    ldr r4, [r0, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    ldr r0, [r4, #0x2c]
    add r1, sp, #4
    str r0, [sp, #4]
    mov r2, r8
    str r2, [sp, #8]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    ldr r1, [r7, #0x14]
    add r4, sp, #0x28
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r7, #0
    bl _call_via_r2
    add r0, sp, #4
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801E29C
    movs r3, #1
    mov sl, r3
.L0801E29C:
    mov r0, sl
    cmp r0, #0
    bne .Lraw_game_state_9603_4
    b .L0801E630
.Lraw_game_state_9603_4:
    mov r0, sb
    subs r0, #0x2b
    cmp r0, #0x28
    bls .Lraw_game_state_9603_14
    b .L0801E630
.Lraw_game_state_9603_14:
    lsls r0, r0, #2
    ldr r1, .Lraw_game_state_9605_0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
.Lraw_game_state_9604_8: .word 0x000003FF
.Lraw_game_state_9604_12: .word 0xFFFFFC00
.Lraw_game_state_9605_0: .4byte .L0801E2C4
.L0801E2C4: .4byte .L0801E368
    .4byte .L0801E3B0
    .4byte .L0801E630
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E3DC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E4EC
    .4byte .L0801E630
    .4byte .L0801E630
    .4byte .L0801E630
    .4byte .L0801E630
    .4byte .L0801E604
    .4byte .L0801E612
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
    .4byte .L0801E4BC
.L0801E368:
    cmp r7, #0
    bne .Lraw_game_state_9649_6
    b .L0801E630
.Lraw_game_state_9649_6:
    add r1, sp, #0x10
    movs r3, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_9653_12
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    movs r5, #0xf8
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #5
    ldrh r3, [r1, #2]
    adds r0, r4, #0
    ands r0, r3
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    movs r0, #0x48
    orrs r2, r0
    strb r2, [r1, #3]
    movs r2, #1
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r2
    b .Lraw_game_state_9705_6
.Lraw_game_state_9653_12: .word 0xFFFFFC00
.L0801E3B0:
    cmp r7, #0
    bne .Lraw_game_state_9655_6
    b .L0801E630
.Lraw_game_state_9655_6:
    add r1, sp, #0xc
    movs r6, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_9657_8
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1]
    movs r5, #0xc0
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #0xb
    b .Lraw_game_state_9703_12
.Lraw_game_state_9657_8: .word 0xFFFFFC00
.L0801E3DC:
    cmp r7, #0
    bne .Lraw_game_state_9660_2
    b .L0801E630
.Lraw_game_state_9660_2:
    ldrh r1, [r7, #4]
    cmp r1, #0x11
    beq .Lraw_game_state_9661_0
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r1, r0
    bne .Lraw_game_state_9671_12
.Lraw_game_state_9661_0:
    mov r2, sb
    subs r2, #0x2e
    ldr r1, [sp, #0x40]
    ldr r3, .Lraw_game_state_9671_4
    adds r0, r1, r3
    ldr r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r1, r1, r0
    add r0, sp, #0x30
    bl method_0800C6F0__C4CoopUi
    ldr r0, [sp, #0x30]
    str r0, [sp, #0x34]
    add r0, sp, #0x34
    movs r1, #0
    ldrsh r6, [r0, r1]
    movs r3, #2
    ldrsh r2, [r0, r3]
    mov r8, r2
    add r1, sp, #0xc
    movs r3, #0x11
    ldrh r2, [r1]
    ldr r5, .Lraw_game_state_9671_8
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    lsls r6, r6, #0x10
    lsrs r2, r6, #0x10
    movs r0, #0x3f
    mov sb, r0
    ands r2, r0
    lsls r2, r2, #2
    ldrb r4, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r4
    orrs r0, r2
    strb r0, [r1, #1]
    lsrs r6, r6, #0x16
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1, #2]
    mov r2, r8
    lsls r2, r2, #0x10
    mov r8, r2
    lsrs r0, r2, #0x10
    mov r2, sb
    ands r0, r2
    lsls r0, r0, #2
    ldrb r2, [r1, #3]
    ands r3, r2
    orrs r3, r0
    strb r3, [r1, #3]
    mov r3, r8
    lsrs r3, r3, #0x16
    ldrh r0, [r1, #4]
    ands r5, r0
    orrs r5, r3
    strh r5, [r1, #4]
    add r5, sp, #4
    movs r4, #1
    b .Lraw_game_state_9705_12
.Lraw_game_state_9671_4: .word 0x00001038
.Lraw_game_state_9671_8: .word 0xFFFFFC00
.Lraw_game_state_9671_12:
    add r1, sp, #0xc
    movs r5, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_9675_8
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strh r0, [r1]
    ldrb r2, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r2
    movs r2, #0x3c
    orrs r0, r2
    strb r0, [r1, #1]
    ldrh r2, [r1, #2]
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r3, r0
    movs r0, #0x30
    orrs r3, r0
    strb r3, [r1, #3]
    movs r2, #8
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r2
    b .Lraw_game_state_9705_6
.Lraw_game_state_9675_8: .word 0xFFFFFC00
.L0801E4BC:
    cmp r7, #0
    bne .Lraw_game_state_9678_2
    b .L0801E630
.Lraw_game_state_9678_2:
    ldr r1, [sp, #0x40]
    ldr r0, [r1]
    ldr r2, [r0, #0x3c]
    adds r0, r1, #0
    mov r1, sb
    bl _call_via_r2
    ldr r2, [sp, #0x40]
    ldr r3, .Lraw_game_state_9683_2
    adds r0, r2, r3
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    mov r1, sb
    subs r1, #0x4c
    bl method_0800C9B8__4CoopUi
    b .L0801E630
.Lraw_game_state_9683_2: .word 0x00001038
.L0801E4EC:
    cmp r7, #0
    bne .Lraw_game_state_9686_2
    b .L0801E630
.Lraw_game_state_9686_2:
    ldrh r1, [r7, #4]
    cmp r1, #0x25
    beq .Lraw_game_state_9687_0
    movs r0, #0x8d
    lsls r0, r0, #2
    cmp r1, r0
    bne .Lraw_game_state_9701_12
.Lraw_game_state_9687_0:
    movs r2, #0x36
    rsbs r2, r2, #0
    add r2, sb
    mov sl, r2
    ldr r3, [sp, #0x40]
    ldr r1, .Lraw_game_state_9701_4
    adds r0, r3, r1
    ldr r1, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r1, r1, r2
    add r0, sp, #0x38
    mov r2, sl
    bl method_0800D074__C4BarnUi
    ldr r0, [sp, #0x38]
    str r0, [sp, #0x3c]
    add r0, sp, #0x3c
    movs r3, #0
    ldrsh r6, [r0, r3]
    movs r2, #2
    ldrsh r1, [r0, r2]
    mov r8, r1
    add r1, sp, #0xc
    movs r3, #0x25
    ldrh r2, [r1]
    ldr r5, .Lraw_game_state_9701_8
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r3
    strh r0, [r1]
    lsls r6, r6, #0x10
    lsrs r2, r6, #0x10
    movs r3, #0x3f
    mov sb, r3
    ands r2, r3
    lsls r2, r2, #2
    ldrb r4, [r1, #1]
    movs r3, #3
    adds r0, r3, #0
    ands r0, r4
    orrs r0, r2
    strb r0, [r1, #1]
    lsrs r6, r6, #0x16
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1, #2]
    mov r0, r8
    lsls r0, r0, #0x10
    mov r8, r0
    lsrs r0, r0, #0x10
    mov r2, sb
    ands r0, r2
    lsls r0, r0, #2
    ldrb r2, [r1, #3]
    ands r3, r2
    orrs r3, r0
    strb r3, [r1, #3]
    mov r3, r8
    lsrs r3, r3, #0x16
    ldrh r0, [r1, #4]
    ands r5, r0
    orrs r5, r3
    strh r5, [r1, #4]
    mov r0, sl
    lsrs r0, r0, #2
    mov sl, r0
    movs r0, #1
    mov r2, sl
    ands r2, r0
    mov sl, r2
    add r4, sp, #4
    adds r0, r4, #0
    movs r2, #6
    bl memcpy
    mov r3, sl
    strb r3, [r4, #6]
    b .Lraw_game_state_9707_2
    .align 2, 0
.Lraw_game_state_9701_4: .word 0x00001038
.Lraw_game_state_9701_8: .word 0xFFFFFC00
.Lraw_game_state_9701_12:
    add r1, sp, #0xc
    movs r6, #2
    ldrh r2, [r1]
    ldr r4, .Lraw_game_state_9710_0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r6
    strh r0, [r1]
    movs r5, #0xe0
    ldrb r3, [r1, #1]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1, #1]
    movs r5, #7
.Lraw_game_state_9703_12:
    ldrh r3, [r1, #2]
    adds r0, r4, #0
    ands r0, r3
    orrs r0, r5
    strh r0, [r1, #2]
    ldrb r0, [r1, #3]
    ands r2, r0
    movs r0, #0x10
    orrs r2, r0
    strb r2, [r1, #3]
    ldrh r0, [r1, #4]
    ands r4, r0
    orrs r4, r6
.Lraw_game_state_9705_6:
    strh r4, [r1, #4]
    add r5, sp, #4
    movs r4, #0
.Lraw_game_state_9705_12:
    adds r0, r5, #0
    movs r2, #6
    bl memcpy
    strb r4, [r5, #6]
.Lraw_game_state_9707_2:
    adds r0, r7, #0
    add r1, sp, #4
    bl SetLocation__12AActorEntityRC13ActorLocation
    b .L0801E630
.Lraw_game_state_9710_0: .word 0xFFFFFC00
.L0801E604:
    adds r0, r7, #0
    movs r1, #2
    movs r2, #0xe0
    movs r3, #0xa8
    bl SetLocation__7AEntityUiii
    b .L0801E630
.L0801E612:
    ldr r1, [sp, #0x40]
    ldr r0, [r1]
    ldr r2, [r0, #0x3c]
    adds r0, r1, #0
    mov r1, sb
    bl _call_via_r2
    ldr r2, [sp, #0x40]
    ldr r3, .Lraw_game_state_9728_4
    adds r0, r2, r3
    ldr r0, [r0]
    ldr r1, .Lraw_game_state_9728_8
    adds r0, r0, r1
    bl func_0800ED2C
.L0801E630:
    ldr r2, [sp, #0x48]
    adds r2, #1
    str r2, [sp, #0x48]
    cmp r2, #0x63
    bgt .Lraw_game_state_9721_12
    b .Lraw_game_state_9517_8
.Lraw_game_state_9721_12:
    ldr r3, [sp, #0x44]
    cmp r3, #0
    beq .Lraw_game_state_9727_0
    ldr r0, [sp, #0x40]
    ldr r4, [r0]
    adds r4, #0xb4
    ldr r1, .Lraw_game_state_9728_4
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, .Lraw_game_state_9728_8
    adds r1, r1, r2
    add r0, sp, #4
    bl GetLocation__C6Farmer
    ldr r3, [r4]
    ldr r0, [sp, #0x40]
    add r1, sp, #4
    movs r2, #0
    bl _call_via_r3
.Lraw_game_state_9727_0:
    add sp, #0x4c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
.Lraw_game_state_9728_4: .word 0x00001038
.Lraw_game_state_9728_8: .word 0x00001BD8

    .section .text.world_after_farmhouse_relocation, "ax", %progbits
    thumb_func_start func_0801E90C
func_0801E90C: @ 0x0801E90C
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x40
    mov r8, r0
    movs r0, #0
    str r0, [sp, #0x34]
    movs r4, #0
.L0801E920:
    mov r1, r8
    ldr r0, [r1]
    ldr r2, [r0, #0x40]
    mov r0, r8
    adds r1, r4, #0
    bl _call_via_r2
    adds r3, r0, #0
    adds r4, #1
    mov sl, r4
    cmp r3, #0
    beq .L0801EA18
    ldrh r0, [r3, #4]
    cmp r0, #2
    bne .L0801EA18
    ldr r1, [r3, #0x14]
    add r0, sp, #4
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    add r4, sp, #0xc
    adds r6, r4, #0
    movs r5, #0
    str r5, [sp, #0x14]
    ldrh r0, [r4]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x13
    subs r0, #0x22
    asrs r0, r0, #1
    str r0, [sp, #0x18]
    add r1, sp, #0x18
    add r2, sp, #0x14
    cmp r5, r0
    bge .L0801E970
    adds r2, r1, #0
.L0801E970:
    ldr r2, [r2]
    mov sb, r2
    movs r1, #0x2a
    str r1, [sp, #0x1c]
    movs r2, #4
    ldrsh r0, [r4, r2]
    subs r0, #1
    asrs r0, r0, #3
    subs r0, #0x22
    asrs r0, r0, #1
    str r0, [sp, #0x20]
    add r2, sp, #0x20
    add r3, sp, #0x1c
    cmp r1, r0
    ble .L0801E990
    adds r3, r2, #0
.L0801E990:
    ldr r7, [r3]
    str r5, [sp, #0x24]
    ldrh r0, [r4, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x13
    subs r0, #0x16
    asrs r0, r0, #1
    str r0, [sp, #0x28]
    add r1, sp, #0x28
    add r2, sp, #0x24
    cmp r5, r0
    bge .L0801E9AA
    adds r2, r1, #0
.L0801E9AA:
    ldr r4, [r2]
    movs r1, #0x18
    str r1, [sp, #0x2c]
    movs r2, #6
    ldrsh r0, [r6, r2]
    subs r0, #1
    asrs r0, r0, #3
    subs r0, #0x16
    asrs r0, r0, #1
    str r0, [sp, #0x30]
    add r2, sp, #0x30
    add r3, sp, #0x2c
    cmp r1, r0
    ble .L0801E9C8
    adds r3, r2, #0
.L0801E9C8:
    ldr r2, [r3]
    adds r1, r4, #0
    cmp r1, r2
    bgt .L0801EA18
    mov r0, sb
    lsls r3, r0, #2
.L0801E9D4:
    mov r4, sb
    adds r6, r1, #1
    cmp r4, r7
    bgt .L0801EA12
    movs r0, #0xac
    muls r0, r1, r0
    adds r5, r3, r0
.L0801E9E2:
    ldr r0, .L0801EA50 @ =0x00001038
    add r0, r8
    ldr r0, [r0]
    ldr r1, .L0801EA54 @ =0x000009DC
    adds r0, r0, r1
    adds r1, r0, r5
    ldr r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x1a
    cmp r0, #0x15
    bne .L0801EA0A
    mov r0, sp
    str r2, [sp, #0x38]
    str r3, [sp, #0x3c]
    bl method_0800A4A4__9FieldPlot
    movs r0, #1
    str r0, [sp, #0x34]
    ldr r3, [sp, #0x3c]
    ldr r2, [sp, #0x38]
.L0801EA0A:
    adds r5, #4
    adds r4, #1
    cmp r4, r7
    ble .L0801E9E2
.L0801EA12:
    adds r1, r6, #0
    cmp r1, r2
    ble .L0801E9D4
.L0801EA18:
    mov r4, sl
    cmp r4, #0x63
    bgt .L0801EA20
    b .L0801E920
.L0801EA20:
    ldr r1, [sp, #0x34]
    cmp r1, #0
    beq .L0801EA86
    mov r2, r8
    ldr r5, [r2, #4]
    ldr r0, [r5]
    cmp r0, #2
    bne .L0801EA60
    adds r0, r5, #0
    adds r0, #0x90
    ldr r4, [r0]
    ldr r0, .L0801EA58 @ =0x00001048
    add r0, r8
    ldr r1, [r0]
    ldr r0, .L0801EA5C @ =0x0000104C
    add r0, r8
    ldrb r2, [r0]
    movs r3, #0x1e
    subs r3, r3, r2
    ldr r4, [r4, #0x14]
    adds r0, r5, #0
    bl _call_via_r4
    b .L0801EA86
    .align 2, 0
.L0801EA50: .4byte 0x00001038
.L0801EA54: .4byte 0x000009DC
.L0801EA58: .4byte 0x00001048
.L0801EA5C: .4byte 0x0000104C
.L0801EA60:
    ldr r0, .L0801EA98 @ =0x00001050
    add r0, r8
    ldr r5, [r0]
    ldr r0, .L0801EA9C @ =0x00001038
    add r0, r8
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0x14
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    movs r2, #0
    cmp r0, #3
    bne .L0801EA7E
    movs r2, #1
.L0801EA7E:
    adds r0, r5, #0
    adds r1, r4, #0
    bl InitializeFarmTerrain
.L0801EA86:
    add sp, #0x40
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801EA98: .4byte 0x00001050
.L0801EA9C: .4byte 0x00001038

    thumb_func_start func_0801EAA0
func_0801EAA0: @ 0x0801EAA0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L0801EBB0 @ =0xFFFFFCB0
    add sp, r4
    adds r7, r0, #0
    str r1, [sp, #0x330]
    ldr r1, .L0801EBB4 @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    adds r0, #0x12
    str r0, [sp, #0x334]
    ldr r3, .L0801EBB8 @ =0x0000103C
    adds r0, r7, r3
    ldrb r0, [r0]
    str r0, [sp, #0x338]
    cmp r0, #0
    beq .L0801EAD8
    ldr r0, [r7]
    movs r4, #0x94
    lsls r4, r4, #1
    adds r0, r0, r4
    ldr r1, [r0]
    adds r0, r7, #0
    bl _call_via_r1
.L0801EAD8:
    adds r5, r7, #0
    adds r5, #8
    str r5, [sp, #0x33c]
    movs r0, #0xcc
    lsls r0, r0, #1
    adds r0, r7, r0
    str r0, [sp, #0x340]
    adds r4, r5, #0
    adds r6, r4, #0
    movs r3, #0xca
    lsls r3, r3, #2
    add r3, sp
    mov r8, r3
    cmp r6, r0
    beq .L0801EB0E
.L0801EAF6:
    ldr r2, [r4]
    cmp r2, #0
    beq .L0801EB06
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x14]
    adds r0, r2, #0
    bl _call_via_r1
.L0801EB06:
    adds r4, #4
    ldr r0, [sp, #0x340]
    cmp r4, r0
    bne .L0801EAF6
.L0801EB0E:
    movs r0, #0
    str r0, [sp]
    movs r3, #0
    adds r4, r6, #0
    ldr r2, .L0801EBBC @ =gUnk_080F0748
.L0801EB18:
    ldr r0, [r2]
    lsls r0, r0, #2
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r1, #0
    beq .L0801EB3C
    ldr r0, [sp]
    cmp r0, #0x63
    bhi .L0801EB3C
    lsls r0, r0, #2
    adds r0, #4
    add r0, sp
    cmp r0, #0
    beq .L0801EB36
    str r1, [r0]
.L0801EB36:
    ldr r0, [sp]
    adds r0, #1
    str r0, [sp]
.L0801EB3C:
    adds r2, #4
    adds r3, #1
    cmp r3, #9
    bls .L0801EB18
    ldr r0, [sp]
    lsls r0, r0, #2
    adds r0, #4
    add r0, sp
    mov sb, r0
    movs r2, #0xca
    lsls r2, r2, #1
    mov r3, sp
    adds r1, r3, r2
    movs r0, #0
    str r0, [r1]
    movs r5, #0
    ldr r4, .L0801EBC0 @ =gUnk_080F0770
.L0801EB5E:
    ldr r0, [r4]
    lsls r0, r0, #2
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r3, #0
    beq .L0801EB86
    mov r0, sp
    adds r1, r0, r2
    ldr r0, [r1]
    cmp r0, #0x63
    bhi .L0801EB86
    lsls r0, r0, #2
    adds r0, #4
    adds r0, r1, r0
    cmp r0, #0
    beq .L0801EB80
    str r3, [r0]
.L0801EB80:
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
.L0801EB86:
    adds r4, #4
    adds r5, #1
    cmp r5, #0x23
    bls .L0801EB5E
    add r1, sp, #0x194
    ldr r0, [r1]
    lsls r0, r0, #2
    adds r0, #4
    adds r1, r1, r0
    str r1, [sp, #0x344]
    movs r1, #0
    add r0, sp, #0x328
    str r1, [r0]
    mov r3, r8
    strb r1, [r3, #4]
    movs r4, #0x82
    lsls r4, r4, #5
    adds r6, r7, r4
    movs r5, #3
    mov sl, r5
    b .L0801EBE2
    .align 2, 0
.L0801EBB0: .4byte 0xFFFFFCB0
.L0801EBB4: .4byte 0x00001038
.L0801EBB8: .4byte 0x0000103C
.L0801EBBC: .4byte gUnk_080F0748
.L0801EBC0: .4byte gUnk_080F0770
.L0801EBC4:
    movs r0, #0
    mov r1, r8
    strb r0, [r1, #4]
    b .L0801EBE2
.L0801EBCC:
    add r4, sp, #4
    cmp r4, sb
    beq .L0801EBE2
.L0801EBD2:
    ldm r4!, {r0}
    ldr r1, [r0, #0x14]
    ldr r2, [r1, #0x18]
    mov r1, r8
    bl _call_via_r2
    cmp r4, sb
    bne .L0801EBD2
.L0801EBE2:
    ldrb r0, [r6, #4]
    adds r0, #1
    cmp r0, #0x19
    bhs .L0801EBF0
    strb r0, [r6, #4]
    movs r0, #0
    b .L0801ED06
.L0801EBF0:
    movs r0, #0
    strb r0, [r6, #4]
    ldr r4, [r6]
    ldr r1, [r4]
    lsls r1, r1, #5
    lsrs r1, r1, #0x1a
    adds r1, #1
    movs r2, #0x3f
    ands r2, r1
    lsls r2, r2, #5
    ldrh r3, [r4, #2]
    ldr r5, .L0801EDEC @ =0xFFFFF81F
    adds r0, r5, #0
    ands r0, r3
    orrs r0, r2
    strh r0, [r4, #2]
    movs r0, #0x3f
    ands r1, r0
    cmp r1, #0x3b
    bls .L0801ED04
    ldr r1, [r6]
    ldrh r2, [r1, #2]
    adds r0, r5, #0
    ands r0, r2
    strh r0, [r1, #2]
    ldr r3, [r6]
    ldr r1, [r3]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x1b
    adds r1, #1
    movs r4, #0x1f
    mov ip, r4
    mov r5, ip
    ands r1, r5
    ldrb r2, [r3, #2]
    movs r4, #0x20
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #2]
    cmp r1, #0x17
    bls .L0801ED04
    ldr r1, [r6]
    ldrb r2, [r1, #2]
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1, #2]
    ldr r3, [r6]
    ldrb r2, [r3, #1]
    lsls r0, r2, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    cmp r0, #0x1e
    bne .L0801EC96
    lsls r0, r2, #0x1e
    lsrs r0, r0, #0x1e
    mov r1, sl
    ands r0, r1
    movs r1, #4
    rsbs r1, r1, #0
    add r4, sp, #0x348
    ldrb r4, [r4]
    ands r1, r4
    orrs r1, r0
    adds r0, #1
    mov r5, sl
    ands r0, r5
    movs r4, #4
    rsbs r4, r4, #0
    ands r1, r4
    orrs r1, r0
    add r5, sp, #0x348
    strb r1, [r5]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    mov r0, sl
    ands r1, r0
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #1]
    movs r0, #0
.L0801EC96:
    mov r1, ip
    ands r0, r1
    lsls r2, r0, #2
    ldrb r1, [r3, #1]
    movs r0, #0x7d
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r3, #1]
    add r3, sp, #0x34c
    ldrb r0, [r3]
    movs r3, #4
    rsbs r3, r3, #0
    ands r0, r3
    movs r4, #0x7d
    rsbs r4, r4, #0
    ands r0, r4
    add r5, sp, #0x34c
    strb r0, [r5]
    ldr r2, [r6]
    movs r3, #0
    ldrb r1, [r2, #1]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    bne .L0801ECCC
    movs r3, #1
.L0801ECCC:
    cmp r3, #0
    beq .L0801ED04
    adds r4, r2, #0
    ldrb r3, [r4]
    lsls r0, r3, #0x1d
    lsrs r0, r0, #0x1d
    adds r2, r0, #1
    cmp r2, #6
    bls .L0801ECF2
    movs r2, #0
    lsrs r1, r3, #3
    cmp r1, #0x1c
    bhi .L0801ECF2
    adds r1, #1
    lsls r1, r1, #3
    movs r0, #7
    ands r0, r3
    orrs r0, r1
    strb r0, [r4]
.L0801ECF2:
    movs r0, #7
    ands r2, r0
    ldrb r0, [r4]
    movs r3, #8
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4]
.L0801ED04:
    movs r0, #1
.L0801ED06:
    cmp r0, #0
    bne .L0801ED0C
    b .L0801EBCC
.L0801ED0C:
    movs r0, #1
    mov r4, r8
    strb r0, [r4, #4]
    add r4, sp, #0x198
    ldr r5, [sp, #0x344]
    cmp r4, r5
    beq .L0801ED2C
.L0801ED1A:
    ldm r4!, {r0}
    ldr r1, [r0, #0x14]
    ldr r2, [r1, #0x18]
    mov r1, r8
    bl _call_via_r2
    ldr r0, [sp, #0x344]
    cmp r4, r0
    bne .L0801ED1A
.L0801ED2C:
    ldr r1, [sp, #0x330]
    ldrh r2, [r1]
    ldr r0, .L0801EDF0 @ =0x000007FF
    ldr r4, [sp, #0x334]
    ldrh r3, [r4]
    adds r1, r0, #0
    ands r1, r2
    ands r0, r3
    cmp r1, r0
    beq .L0801ED42
    b .L0801EBC4
.L0801ED42:
    ldr r4, [sp, #0x33c]
    ldr r5, [sp, #0x340]
    cmp r4, r5
    beq .L0801ED62
.L0801ED4A:
    ldr r2, [r4]
    cmp r2, #0
    beq .L0801ED5A
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x10]
    adds r0, r2, #0
    bl _call_via_r1
.L0801ED5A:
    adds r4, #4
    ldr r0, [sp, #0x340]
    cmp r4, r0
    bne .L0801ED4A
.L0801ED62:
    ldr r1, [sp, #0x338]
    cmp r1, #0
    beq .L0801ED78
    ldr r0, [r7]
    movs r3, #0x92
    lsls r3, r3, #1
    adds r0, r0, r3
    ldr r1, [r0]
    adds r0, r7, #0
    bl _call_via_r1
.L0801ED78:
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne .L0801EDA2
    movs r4, #0x82
    lsls r4, r4, #5
    adds r0, r7, r4
    ldr r0, [r0]
    ldr r2, [r0]
    lsls r1, r2, #0xb
    lsrs r1, r1, #0x1b
    lsls r2, r2, #5
    lsrs r2, r2, #0x1a
    adds r0, r7, #0
    movs r3, #0
    bl UpdateWorldTimeOfDayPalettes
.L0801EDA2:
    ldr r0, [r7, #8]
    ldr r1, [r0, #0x14]
    adds r1, #0xa4
    ldr r1, [r1]
    bl _call_via_r1
    ldr r5, .L0801EDF4 @ =0x00001054
    adds r0, r7, r5
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801EDD8
    ldr r1, .L0801EDF8 @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r3, .L0801EDFC @ =0x0000214C
    adds r0, r0, r3
    bl HasRegisteredEvents__C14GameEventState
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801EDD8
    adds r0, r7, #0
    bl UpdateWorldBackgroundAudio
.L0801EDD8:
    movs r3, #0xd4
    lsls r3, r3, #2
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801EDEC: .4byte 0xFFFFF81F
.L0801EDF0: .4byte 0x000007FF
.L0801EDF4: .4byte 0x00001054
.L0801EDF8: .4byte 0x00001038
.L0801EDFC: .4byte 0x0000214C

    thumb_func_start func_0801EE00
func_0801EE00: @ 0x0801EE00
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov sl, r0
    mov sb, r1
    adds r7, r2, #0
    ldr r1, [r0]
    mov r0, sb
    ldrh r2, [r0]
    lsls r2, r2, #0x16
    lsrs r2, r2, #0x16
    add r0, sp, #0xc
    ldr r3, [r1, #0x34]
    mov r1, sl
    bl _call_via_r3
    mov r1, sb
    ldrb r0, [r1, #1]
    lsrs r0, r0, #2
    ldrh r1, [r1, #2]
    ldr r3, .L0801EEC0 @ =0x000003FF
    ands r1, r3
    lsls r1, r1, #6
    orrs r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r2, sb
    ldrb r0, [r2, #3]
    lsrs r0, r0, #2
    ldrh r2, [r2, #4]
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    add r0, sp, #0xc
    bl IsMapTerrainFlag1Footprint
    movs r1, #1
    eors r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x2c]
    movs r3, #0
    str r3, [sp, #0x30]
    movs r6, #1
    mov r4, sp
    adds r4, #0x28
    str r4, [sp, #0x38]
    mov r0, sp
    adds r0, #8
    str r0, [sp, #0x34]
    ldr r1, [sp, #0x2c]
    cmp r1, #0
    beq .L0801EE76
    b .L0801EFA8
.L0801EE76:
    mov r2, sl
    ldr r0, [r2]
    movs r3, #0xa6
    lsls r3, r3, #1
    adds r0, r0, r3
    ldr r1, [r0]
    mov r0, sl
    bl _call_via_r1
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .L0801EEA2
.L0801EE90:
    ldr r0, [r4]
    bl IsUnpaused__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801EEC4
    adds r4, #4
    cmp r4, r5
    bne .L0801EE90
.L0801EEA2:
    subs r0, r5, #4
    ldr r0, [r0]
.L0801EEA6:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    mov r0, sb
    bl GetFieldPlotPositionRuleResult
    cmp r0, #2
    beq .L0801EF78
    cmp r0, #2
    bgt .L0801EEC8
    cmp r0, #0
    beq .L0801EF84
    b .L0801EFA8
    .align 2, 0
.L0801EEC0: .4byte 0x000003FF
.L0801EEC4:
    ldr r0, [r4]
    b .L0801EEA6
.L0801EEC8:
    cmp r0, #4
    beq .L0801EED2
    cmp r0, #6
    beq .L0801EF00
    b .L0801EFA8
.L0801EED2:
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .L0801EFA8
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #0xa0
    bne .L0801EFA8
    ldr r0, .L0801EEFC @ =0x00001038
    add r0, sl
    ldr r0, [r0]
    bl SetFlag4__18GameStateSaveImage
    b .L0801EFA8
    .align 2, 0
.L0801EEFC: .4byte 0x00001038
.L0801EF00:
    movs r5, #0
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .L0801EF34
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #0xe
    ble .L0801EF34
    add r4, sp, #0x10
    adds r0, r4, #0
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    adds r0, r4, #0
    bl GetId__C4Food
    cmp r0, #0x14
    bgt .L0801EF34
    movs r5, #1
.L0801EF34:
    cmp r5, #0
    beq .L0801EFA8
    mov r4, sl
    ldr r6, [r4, #8]
    ldr r0, [r6, #0x14]
    mov r8, r0
    add r5, sp, #0x14
    add r4, sp, #0x18
    adds r0, r4, #0
    movs r1, #0x15
    bl __4FoodUi
    ldrb r1, [r4]
    mov r0, sp
    adds r0, #0x19
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r0, r1
    mov r1, sp
    adds r1, #0x1a
    ldrb r1, [r1]
    lsls r1, r1, #0x10
    orrs r1, r0
    adds r0, r5, #0
    bl __12RucksackItemG4Food
    mov r1, r8
    ldr r3, [r1, #0x5c]
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #0
    bl _call_via_r3
    b .L0801EFA6
.L0801EF78:
    ldr r2, .L0801EF80 @ =0x0000023B
    str r2, [sp, #0x30]
    b .L0801EFA6
    .align 2, 0
.L0801EF80: .4byte 0x0000023B
.L0801EF84:
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    bne .L0801EFA8
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetId__C4Food
    cmp r0, #2
    bne .L0801EFA8
    movs r3, #0x8f
    lsls r3, r3, #2
    str r3, [sp, #0x30]
.L0801EFA6:
    movs r6, #0
.L0801EFA8:
    ldr r4, [sp, #0x30]
    cmp r4, #0
    beq .L0801EFC8
    mov r1, sl
    ldr r0, [r1]
    movs r2, #0xa0
    lsls r2, r2, #1
    adds r0, r0, r2
    add r1, sp, #0x1c
    movs r2, #0
    str r4, [sp, #0x1c]
    str r2, [r1, #4]
    ldr r3, [r0]
    mov r0, sl
    bl _call_via_r3
.L0801EFC8:
    cmp r6, #0
    beq .L0801EFE0
    ldr r0, .L0801F00C @ =0x00001038
    add r0, sl
    ldr r2, [r0]
    ldr r3, .L0801F010 @ =0x00001CD4
    adds r0, r2, r3
    ldr r4, .L0801F014 @ =0x0000214C
    adds r2, r2, r4
    mov r1, sb
    bl func_080A1484
.L0801EFE0:
    adds r0, r7, #0
    bl IsWrapped__C12RucksackItem
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801F04A
    adds r0, r7, #0
    bl GetKind__C12RucksackItem
    cmp r0, #0
    beq .L0801EFFA
    cmp r0, #1
    beq .L0801F018
.L0801EFFA:
    add r0, sp, #0xc
    adds r1, r7, #0
    bl GetFood__C12RucksackItem
    add r0, sp, #0xc
    bl GetIconId__C4Food
    b .L0801F032
    .align 2, 0
.L0801F00C: .4byte 0x00001038
.L0801F010: .4byte 0x00001CD4
.L0801F014: .4byte 0x0000214C
.L0801F018:
    adds r0, r7, #0
    bl GetArticle__C12RucksackItem
    add r4, sp, #0x24
    strb r0, [r4]
    adds r0, r4, #0
    bl GetId__C7Article
    cmp r0, #0x1b
    beq .L0801F038
    adds r0, r4, #0
    bl GetIconId__C7Article
.L0801F032:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    b .L0801F04E
.L0801F038:
    mov r1, sb
    ldrh r0, [r1]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    movs r5, #3
    cmp r0, #8
    bgt .L0801F04E
    movs r5, #4
    b .L0801F04E
.L0801F04A:
    movs r5, #0xb0
    lsls r5, r5, #1
.L0801F04E:
    mov r2, sb
    ldrb r0, [r2, #1]
    lsrs r0, r0, #2
    ldrh r2, [r2, #2]
    ldr r3, .L0801F0F8 @ =0x000003FF
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    mov r4, sb
    ldrb r1, [r4, #3]
    lsrs r1, r1, #2
    ldrh r0, [r4, #4]
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    add r1, sp, #0x28
    strh r2, [r1]
    ldr r1, [sp, #0x38]
    strh r0, [r1, #2]
    mov r2, sl
    ldr r0, [r2]
    ldr r1, [r0, #0x64]
    mov r0, sl
    bl _call_via_r1
    ldr r4, .L0801F0FC @ =0x0000102C
    add r4, sl
    adds r6, r0, #0
    adds r7, r5, #0
    ldr r0, [sp, #0x28]
    str r0, [r4, #4]
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F0A8
    cmp r1, #0
    beq .L0801F0A8
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F0A8:
    str r5, [r4]
    add r3, sp, #0x2c
    ldrb r3, [r3]
    strb r3, [r4, #8]
    ldr r5, [sp, #0x2c]
    cmp r5, #0
    beq .L0801F100
    movs r0, #0x40
    bl __builtin_new
    movs r1, #2
    str r1, [sp]
    movs r1, #3
    str r1, [sp, #4]
    movs r1, #0
    ldr r2, [sp, #0x34]
    strb r1, [r2]
    adds r1, r6, #0
    adds r2, r7, #0
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    adds r5, r0, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F0EC
    cmp r1, #0
    beq .L0801F0EC
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F0EC:
    str r5, [r4]
    movs r1, #0
    movs r0, #0x10
    strb r0, [r4, #9]
    strb r1, [r4, #0xa]
    b .L0801F138
    .align 2, 0
.L0801F0F8: .4byte 0x000003FF
.L0801F0FC: .4byte 0x0000102C
.L0801F100:
    movs r0, #0x40
    bl __builtin_new
    movs r1, #2
    str r1, [sp]
    movs r1, #3
    str r1, [sp, #4]
    ldr r3, [sp, #0x34]
    strb r5, [r3]
    adds r1, r6, #0
    ldr r2, .L0801F148 @ =0x000001A9
    mov r3, sl
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    adds r5, r0, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F134
    cmp r1, #0
    beq .L0801F134
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F134:
    str r5, [r4]
    movs r0, #0
.L0801F138:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801F148: .4byte 0x000001A9

    thumb_func_start RefreshWorldFireplaceSprite
RefreshWorldFireplaceSprite: @ 0x0801F14C
    push {r4, r5, r6, lr}
    sub sp, #0xc
    adds r6, r0, #0
    movs r0, #0x83
    lsls r0, r0, #5
    adds r1, r6, r0
    movs r0, #0
    strb r0, [r1]
    ldr r1, .L0801F198 @ =0x0000105C
    adds r4, r6, r1
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F178
    cmp r1, #0
    beq .L0801F178
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F178:
    str r5, [r4]
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    subs r0, #0xa
    cmp r0, #0x1d
    bls .L0801F18C
    b .L0801F2CA
.L0801F18C:
    lsls r0, r0, #2
    ldr r1, .L0801F19C @ =.L0801F1A0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801F198: .4byte 0x0000105C
.L0801F19C: .4byte .L0801F1A0
.L0801F1A0: @ jump table
    .4byte .L0801F26C @ case 0
    .4byte .L0801F2CA @ case 1
    .4byte .L0801F2CA @ case 2
    .4byte .L0801F2CA @ case 3
    .4byte .L0801F2CA @ case 4
    .4byte .L0801F2CA @ case 5
    .4byte .L0801F2CA @ case 6
    .4byte .L0801F2CA @ case 7
    .4byte .L0801F248 @ case 8
    .4byte .L0801F2CA @ case 9
    .4byte .L0801F2CA @ case 10
    .4byte .L0801F2CA @ case 11
    .4byte .L0801F2CA @ case 12
    .4byte .L0801F2CA @ case 13
    .4byte .L0801F2CA @ case 14
    .4byte .L0801F2CA @ case 15
    .4byte .L0801F2CA @ case 16
    .4byte .L0801F26C @ case 17
    .4byte .L0801F2CA @ case 18
    .4byte .L0801F218 @ case 19
    .4byte .L0801F2CA @ case 20
    .4byte .L0801F2CA @ case 21
    .4byte .L0801F2CA @ case 22
    .4byte .L0801F2CA @ case 23
    .4byte .L0801F2CA @ case 24
    .4byte .L0801F2CA @ case 25
    .4byte .L0801F2CA @ case 26
    .4byte .L0801F2CA @ case 27
    .4byte .L0801F2CA @ case 28
    .4byte .L0801F258 @ case 29
.L0801F218:
    ldr r0, .L0801F244 @ =0x00001038
    adds r4, r6, r0
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #2
    bne .L0801F2CA
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl IsFireplaceLighted__C9FarmHouse
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    b .L0801F280
    .align 2, 0
.L0801F244: .4byte 0x00001038
.L0801F248:
    ldr r1, .L0801F254 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    ldrb r0, [r0, #3]
    lsrs r5, r0, #7
    b .L0801F280
    .align 2, 0
.L0801F254: .4byte 0x00001038
.L0801F258:
    ldr r1, .L0801F268 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1f
    lsrs r5, r0, #0x1f
    b .L0801F280
    .align 2, 0
.L0801F268: .4byte 0x00001038
.L0801F26C:
    ldr r1, .L0801F2D4 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    movs r5, #0
    cmp r0, #3
    bne .L0801F280
    movs r5, #1
.L0801F280:
    movs r0, #0x40
    bl __builtin_new
    adds r4, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x60]
    adds r0, r6, #0
    bl _call_via_r1
    adds r1, r0, #0
    movs r0, #2
    str r0, [sp]
    movs r0, #0x1b
    str r0, [sp, #4]
    add r2, sp, #8
    movs r0, #0
    strb r0, [r2]
    adds r0, r4, #0
    adds r2, r5, #0
    adds r3, r6, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    ldr r1, .L0801F2D8 @ =0x0000105C
    adds r5, r6, r1
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L0801F2C8
    cmp r1, #0
    beq .L0801F2C8
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F2C8:
    str r4, [r5]
.L0801F2CA:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
.L0801F2D4: .4byte 0x00001038
.L0801F2D8: .4byte 0x0000105C

    thumb_func_start RefreshWorldBeachHouseSprite
RefreshWorldBeachHouseSprite: @ 0x0801F2DC
    push {r4, r5, lr}
    sub sp, #0xc
    adds r4, r0, #0
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    adds r0, r4, #0
    bl _call_via_r1
    cmp r0, #0x23
    bne .L0801F3B8
    ldr r1, .L0801F320 @ =0x00001038
    adds r0, r4, r1
    ldr r0, [r0]
    ldrb r0, [r0, #0x12]
    lsls r0, r0, #0x1b
    lsrs r0, r0, #0x1b
    cmp r0, #3
    bls .L0801F370
    cmp r0, #8
    bhi .L0801F328
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .L0801F324 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #0
    b .L0801F38A
    .align 2, 0
.L0801F320: .4byte 0x00001038
.L0801F324: .4byte 0x00000FF4
.L0801F328:
    cmp r0, #0xf
    bhi .L0801F34C
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .L0801F348 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #1
    b .L0801F38A
    .align 2, 0
.L0801F348: .4byte 0x00000FF4
.L0801F34C:
    cmp r0, #0x12
    bhi .L0801F370
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .L0801F36C @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #2
    b .L0801F38A
    .align 2, 0
.L0801F36C: .4byte 0x00000FF4
.L0801F370:
    movs r0, #0x40
    bl __builtin_new
    ldr r2, .L0801F3B0 @ =0x00000FF4
    adds r1, r4, r2
    movs r2, #5
    str r2, [sp]
    movs r2, #0x1b
    str r2, [sp, #4]
    add r3, sp, #8
    movs r2, #0
    strb r2, [r3]
    movs r2, #3
.L0801F38A:
    adds r3, r4, #0
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    ldr r1, .L0801F3B4 @ =0x00001064
    adds r5, r4, r1
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L0801F3AC
    cmp r1, #0
    beq .L0801F3AC
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F3AC:
    str r4, [r5]
    b .L0801F3D6
    .align 2, 0
.L0801F3B0: .4byte 0x00000FF4
.L0801F3B4: .4byte 0x00001064
.L0801F3B8:
    ldr r2, .L0801F3E0 @ =0x00001064
    adds r4, r4, r2
    movs r5, #0
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F3D4
    cmp r1, #0
    beq .L0801F3D4
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F3D4:
    str r5, [r4]
.L0801F3D6:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.L0801F3E0: .4byte 0x00001064

    thumb_func_start RefreshWorldVase
RefreshWorldVase: @ 0x0801F3E4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x40
    adds r6, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    adds r0, r6, #0
    bl _call_via_r1
    cmp r0, #0x1d
    bne .L0801F4E8
    ldr r1, .L0801F488 @ =0x00001038
    adds r0, r6, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetVaseArticleId__C9FarmHouse
    adds r1, r0, #0
    cmp r1, #0x5f
    beq .L0801F506
    add r4, sp, #0x34
    adds r0, r4, #0
    bl __7ArticleUi
    adds r0, r4, #0
    bl GetIconId__C7Article
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldr r3, .L0801F48C @ =0x00001068
    adds r3, r3, r6
    mov sb, r3
    ldr r4, [r3]
    cmp r4, #0
    beq .L0801F490
    ldr r0, [r6]
    ldr r1, [r0, #0x64]
    adds r0, r6, #0
    bl _call_via_r1
    adds r1, r0, #0
    add r0, sp, #0x20
    adds r2, r7, #0
    movs r3, #0x80
    lsls r3, r3, #1
    bl __21IndexedResourceHandleP23IndexedResourceProviderUii
    add r0, sp, #0x20
    ldr r1, [sp, #0x20]
    ldr r3, [r1]
    ldrh r2, [r0, #0xc]
    lsls r2, r2, #2
    ldr r0, [sp, #0x24]
    adds r0, r0, r2
    ldrh r2, [r0]
    mov r0, sp
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    mov r0, sp
    mov r1, sp
    movs r2, #0x20
    bl memcpy
    adds r1, r4, #0
    adds r1, #0x28
    mov r0, sp
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r5}
    stm r1!, {r2, r5}
    adds r1, r4, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    b .L0801F506
    .align 2, 0
.L0801F488: .4byte 0x00001038
.L0801F48C: .4byte 0x00001068
.L0801F490:
    movs r0, #0x4c
    bl __builtin_new
    adds r5, r0, #0
    ldr r0, [r6]
    ldr r1, [r0, #0x64]
    adds r0, r6, #0
    bl _call_via_r1
    adds r4, r0, #0
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .L0801F4E4 @ =__vt_20GameSceneGroupSprite
    str r0, [r5, #0x24]
    movs r3, #0x28
    adds r3, r3, r5
    mov r8, r3
    ldr r6, [r4]
    add r0, sp, #0x38
    ldr r3, [r6, #0xc]
    adds r1, r4, #0
    adds r2, r7, #0
    bl _call_via_r3
    ldr r0, [sp, #0x38]
    ldrh r2, [r0]
    mov r0, r8
    ldr r3, [r6, #0x10]
    adds r1, r4, #0
    bl _call_via_r3
    adds r1, r5, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    mov r4, sb
    b .L0801F4EE
    .align 2, 0
.L0801F4E4: .4byte __vt_20GameSceneGroupSprite
.L0801F4E8:
    ldr r5, .L0801F514 @ =0x00001068
    adds r4, r6, r5
    movs r5, #0
.L0801F4EE:
    ldr r1, [r4]
    cmp r5, r1
    beq .L0801F504
    cmp r1, #0
    beq .L0801F504
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801F504:
    str r5, [r4]
.L0801F506:
    add sp, #0x40
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801F514: .4byte 0x00001068
.L0801F518:
    .section .text.world_shipping_after, "ax", %progbits

    thumb_func_start SetWorldWeatherEffect
SetWorldWeatherEffect: @ 0x0801FAC8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    adds r4, r0, #0
    adds r6, r1, #0
    movs r0, #0
    mov r8, r0
    cmp r6, #0
    beq .L0801FAEC
    cmp r6, #1
    bne .L0801FAF2
    ldr r1, .L0801FAE8 @ =0x00000ED4
    adds r1, r1, r4
    mov r8, r1
    b .L0801FAF2
    .align 2, 0
.L0801FAE8: .4byte 0x00000ED4
.L0801FAEC:
    ldr r0, .L0801FB38 @ =0x00000EA4
    adds r0, r0, r4
    mov r8, r0
.L0801FAF2:
    mov r1, r8
    cmp r1, #0
    beq .L0801FB68
    movs r7, #0x20
    ldr r0, [r4, #4]
    ldr r5, [r0]
    cmp r5, #2
    bne .L0801FB3E
    movs r3, #0
    adds r1, r4, #0
    adds r1, #8
    movs r0, #0xcc
    lsls r0, r0, #1
    adds r2, r4, r0
    cmp r1, r2
    beq .L0801FB26
.L0801FB12:
    ldr r0, [r1]
    cmp r0, #0
    beq .L0801FB20
    ldrh r0, [r0, #4]
    cmp r0, r5
    bne .L0801FB20
    adds r3, #1
.L0801FB20:
    adds r1, #4
    cmp r1, r2
    bne .L0801FB12
.L0801FB26:
    adds r0, r3, #0
    adds r0, #0xa
    cmp r0, #0xa
    bls .L0801FB3E
    cmp r3, #0x15
    bhi .L0801FB3C
    movs r0, #0x20
    subs r7, r0, r3
    b .L0801FB3E
    .align 2, 0
.L0801FB38: .4byte 0x00000EA4
.L0801FB3C:
    movs r7, #0xa
.L0801FB3E:
    ldr r0, .L0801FB74 @ =0x0000046C
    bl __builtin_new
    str r7, [sp]
    adds r1, r4, #0
    mov r2, r8
    adds r3, r6, #0
    bl __22GameSceneWeatherEffectP10GameObjectP23IndexedResourceProviderQ222GameSceneWeatherEffect4KindUi
    ldr r1, .L0801FB78 @ =0x0000107C
    adds r5, r4, r1
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L0801FB66
    cmp r0, #0
    beq .L0801FB66
    movs r1, #3
    bl _._22GameSceneWeatherEffect
.L0801FB66:
    str r4, [r5]
.L0801FB68:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801FB74: .4byte 0x0000046C
.L0801FB78: .4byte 0x0000107C

    @ All overseas virtual-table entries above are direct physical labels.
    @ The verified source positions are shared by US, EU, and DE.

    .endif

    @ Native save-image copy construction. Keep this complete entry separate
    @ from its C++ destructor and the event-state member's native constructor.
    @ This shared body is already instruction source in all four regions.

	.section .text.game_state_copy
    .align 2, 0
    .global __18GameStateSaveImageRC18GameStateSaveImage
    .thumb
    .thumb_func
    .type __18GameStateSaveImageRC18GameStateSaveImage, function
__18GameStateSaveImageRC18GameStateSaveImage: @ 0x080D4178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r3, [r6]
	lsls r1, r3, #0x1f
	lsrs r1, r1, #0x1f
	ldrb r2, [r5]
	movs r4, #2
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #2
	ands r1, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #4
	ands r1, r3
	subs r2, #2
	ands r0, r2
	orrs r0, r1
	movs r1, #8
	ands r1, r3
	subs r2, #4
	ands r0, r2
	orrs r0, r1
	movs r1, #0x10
	ands r1, r3
	subs r2, #8
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	ldrh r0, [r6]
	movs r1, #0xff
	lsls r1, r1, #5
	ands r1, r0
	ldrh r2, [r5]
	ldr r0, .L080D441C @ =0xFFFFE01F
	ands r0, r2
	orrs r0, r1
	strh r0, [r5]
	ldr r2, [r6]
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r2, r0
	ldr r0, [r5]
	ldr r1, .L080D4420 @ =0xFFFC1FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r5]
	ldrh r0, [r6, #2]
	movs r1, #0xfe
	lsls r1, r1, #1
	ands r1, r0
	ldrh r2, [r5, #2]
	ldr r0, .L080D4424 @ =0xFFFFFE03
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	ldrb r2, [r6, #3]
	movs r1, #0x7e
	ands r1, r2
	ldrb r3, [r5, #3]
	movs r0, #0x7f
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	lsrs r2, r2, #7
	lsls r2, r2, #7
	movs r1, #0x7f
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #3]
	ldrb r0, [r6, #4]
	lsls r0, r0, #0x1f
	lsrs r0, r0, #0x1f
	ldrb r1, [r5, #4]
	ands r4, r1
	orrs r4, r0
	strb r4, [r5, #4]
	adds r1, r5, #0
	adds r1, #8
	adds r0, r6, #0
	adds r0, #8
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	adds r0, r5, #0
	adds r0, #0x14
	adds r1, r6, #0
	adds r1, #0x14
	bl __4FarmRC4Farm
	ldr r1, .L080D4428 @ =0x00001AA8
	adds r0, r5, r1
	adds r1, r6, r1
	bl __12MoneyAccountRC12MoneyAccount
	ldr r1, .L080D442C @ =0x00001BD8
	adds r0, r5, r1
	adds r1, r6, r1
	bl __6FarmerRC6Farmer
	ldr r1, .L080D4430 @ =0x00001C70
	adds r0, r5, r1
	adds r1, r6, r1
	bl __as__3DogRC3Dog
	movs r0, #0xe5
	lsls r0, r0, #5
	adds r1, r5, r0
	adds r0, r0, r6
	mov ip, r0
	movs r0, #0
	str r0, [r1]
	mov r0, ip
	ldr r7, [r0]
	ldr r2, .L080D4434 @ =0x00001CA4
	adds r0, r6, r2
	adds r4, r0, r7
	adds r2, r0, #0
	ldr r0, .L080D4434 @ =0x00001CA4
	adds r3, r5, r0
	cmp r2, r4
	beq .L080D428E
.L080D427E:
	cmp r3, #0
	beq .L080D4286
	ldrb r0, [r2]
	strb r0, [r3]
.L080D4286:
	adds r2, #1
	adds r3, #1
	cmp r2, r4
	bne .L080D427E
.L080D428E:
	str r7, [r1]
	adds r0, r1, #0
	adds r0, #0x24
	mov r1, ip
	adds r1, #0x24
	movs r2, #6
	bl memcpy
	ldr r1, .L080D4438 @ =0x00001CCC
	adds r0, r5, r1
	adds r1, r6, r1
	movs r2, #6
	bl memcpy
	ldr r1, .L080D443C @ =0x00001CD4
	adds r0, r5, r1
	adds r1, r6, r1
	bl __13NpcCollectionRC13NpcCollection
	ldr r1, .L080D4440 @ =0x0000214C
	adds r0, r5, r1
	adds r1, r6, r1
	bl __14GameEventStateRC14GameEventState
	ldr r0, .L080D4444 @ =0x000021CC
	adds r4, r5, r0
	adds r0, r0, r6
	mov ip, r0
	ldr r0, [r0]
	str r0, [r4]
	mov r1, ip
	ldr r0, [r1, #4]
	str r0, [r4, #4]
	ldr r3, .L080D4448 @ =0x000021D4
	adds r2, r5, r3
	movs r3, #7
	ldr r0, .L080D4448 @ =0x000021D4
	adds r1, r6, r0
	movs r7, #1
	rsbs r7, r7, #0
.L080D42DE:
	ldrb r0, [r1]
	strb r0, [r2]
	adds r2, #1
	adds r1, #1
	subs r3, #1
	cmp r3, r7
	bne .L080D42DE
	adds r3, r4, #0
	adds r3, #0x10
	movs r1, #3
	mov r2, ip
	adds r2, #0x10
	adds r7, r4, #0
	adds r7, #0x14
	movs r0, #0x14
	add r0, ip
	mov r8, r0
	movs r0, #0x24
	adds r0, r0, r4
	mov sb, r0
	movs r0, #0x24
	add r0, ip
	mov sl, r0
	adds r4, #0x34
	str r4, [sp]
	mov r4, ip
	adds r4, #0x34
	str r4, [sp, #4]
	movs r4, #1
	rsbs r4, r4, #0
.L080D431A:
	ldrb r0, [r2]
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	subs r1, #1
	cmp r1, r4
	bne .L080D431A
	adds r0, r7, #0
	mov r1, r8
	bl strcpy
	mov r0, sb
	mov r1, sl
	bl strcpy
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl strcpy
	ldr r0, .L080D444C @ =0x00002210
	adds r1, r5, r0
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, .L080D4450 @ =0x00002214
	adds r0, r5, r1
	adds r1, r6, r1
	ldr r2, .L080D4454 @ =0x00000A08
	bl memcpy
	ldr r1, .L080D4458 @ =0x00002C1C
	adds r0, r5, r1
	adds r1, r6, r1
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r0, .L080D445C @ =0x00002C4C
	adds r1, r5, r0
	adds r0, r6, r0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080D4460 @ =0x00002C74
	adds r1, r5, r0
	adds r0, r6, r0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	movs r1, #0xb2
	lsls r1, r1, #6
	adds r0, r5, r1
	adds r1, r6, r1
	movs r2, #0xec
	lsls r2, r2, #1
	bl memcpy
	ldr r1, .L080D4464 @ =0x00002E58
	adds r0, r5, r1
	adds r1, r6, r1
	movs r2, #0xc5
	lsls r2, r2, #3
	bl memcpy
	movs r0, #0xd2
	lsls r0, r0, #6
	adds r1, r5, r0
	adds r0, r6, r0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldr r1, .L080D4468 @ =0x00003494
	adds r0, r5, r1
	adds r1, r6, r1
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r0, .L080D446C @ =0x000034C4
	adds r1, r6, r0
	ldrb r1, [r1]
	adds r0, r5, r0
	strb r1, [r0]
	ldr r0, .L080D4470 @ =0x000034C5
	adds r1, r6, r0
	ldrb r1, [r1]
	adds r0, r5, r0
	strb r1, [r0]
	ldr r0, .L080D4474 @ =0x000034C8
	adds r1, r5, r0
	adds r0, r6, r0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080D4478 @ =0x000034D8
	adds r1, r5, r0
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, .L080D447C @ =0x000034DC
	adds r0, r5, r1
	adds r1, r6, r1
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	adds r0, r5, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080D441C: .4byte 0xFFFFE01F
.L080D4420: .4byte 0xFFFC1FFF
.L080D4424: .4byte 0xFFFFFE03
.L080D4428: .4byte 0x00001AA8
.L080D442C: .4byte 0x00001BD8
.L080D4430: .4byte 0x00001C70
.L080D4434: .4byte 0x00001CA4
.L080D4438: .4byte 0x00001CCC
.L080D443C: .4byte 0x00001CD4
.L080D4440: .4byte 0x0000214C
.L080D4444: .4byte 0x000021CC
.L080D4448: .4byte 0x000021D4
.L080D444C: .4byte 0x00002210
.L080D4450: .4byte 0x00002214
.L080D4454: .4byte 0x00000A08
.L080D4458: .4byte 0x00002C1C
.L080D445C: .4byte 0x00002C4C
.L080D4460: .4byte 0x00002C74
.L080D4464: .4byte 0x00002E58
.L080D4468: .4byte 0x00003494
.L080D446C: .4byte 0x000034C4
.L080D4470: .4byte 0x000034C5
.L080D4474: .4byte 0x000034C8
.L080D4478: .4byte 0x000034D8
.L080D447C: .4byte 0x000034DC

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

    .section .text.game_scene_after_screen_flash, "ax", %progbits
    .thumb
    .align 2, 0

    .global func_08014AF8
    .thumb_func
func_08014AF8:
    push {r4, r5, r6, lr}
    sub sp, #0xc
    ldr r5, [r0, #4]
    adds r4, r5, #0
    adds r4, #0xa8
    movs r6, #0
    ldr r1, [r4]
    cmp r6, r1
    beq .Ljp_080149EE
    cmp r1, #0
    beq .Ljp_080149EE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_080149EE:
    str r6, [r4]
    adds r4, r5, #0
    adds r4, #0x8c
    ldr r0, [r4]
    bl DayUpdate__18GameStateSaveImage
    adds r6, r5, #0
    adds r6, #0xa8
    ldr r1, [r4]
    adds r0, r5, #0
    adds r0, #0x88
    ldr r2, [r0]
    mov r0, sp
    movs r3, #0
    bl func_0801F910
    ldr r1, [sp]
    mov r0, sp
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0
    str r0, [sp]
    adds r4, r1, #0
    ldr r1, [r6]
    adds r5, r6, #0
    cmp r4, r1
    beq .Ljp_08014A34
    cmp r1, #0
    beq .Ljp_08014A34
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_08014A34:
    str r4, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .Ljp_08014A48
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_08014A48:
    ldr r0, [r5]
    ldr r1, [r0]
    movs r2, #0x9c
    lsls r2, r2, #1
    adds r1, r1, r2
    ldr r1, [r1]
    bl _call_via_r1
    ldr r0, [r5]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0
    bl _call_via_r2
    adds r4, r0, #0
    ldr r0, .Ljp_08014A88 @ =gUnk_0300040C
    ldr r1, [r0]
    movs r2, #0xdb
    lsls r2, r2, #2
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq .Ljp_08014AA2
    adds r2, #8
    adds r0, r1, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r1, r0, #0x1b
    cmp r1, #5
    bhi .Ljp_08014A8C
    movs r0, #6
    b .Ljp_08014A8E
    .align 2, 0
.Ljp_08014A88: .4byte gUnk_0300040C
.Ljp_08014A8C:
    movs r0, #0x1e
.Ljp_08014A8E:
    subs r2, r0, r1
    ldr r0, [r4, #0x14]
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r2, r2, #1
    rsbs r2, r2, #0
    ldr r3, [r0, #0x64]
    adds r0, r4, #0
    bl _call_via_r3
.Ljp_08014AA2:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    .section .text.game_scene_after_actor_commands, "ax", %progbits

    .global func_08014C70
    .thumb_func
func_08014C70:
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
    .global func_08015044
    .thumb_func
func_08015044:
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
    bl func_0800F190
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
    bl func_0800F344
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .Ljp_080150EC
    ldr r0, [r6, #0]
    ldr r1, .Ljp_0801514C
    adds r0, r0, r1
    bl func_0800F390
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
    .global func_08015150
    .thumb_func
func_08015150:
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
    .global func_08015524
    .thumb_func
func_08015524:
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
    bl func_0800F190
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
    bl func_0800F344
    adds	r1, r0, #0
    adds	r0, r4, #0
    bl GetChicken__4CoopUi
    cmp	r0, #0
    bne .Ljp_080155CC
    ldr	r0, [r6, #0]
    ldr	r1, .Ljp_0801562C
    adds	r0, r0, r1
    bl func_0800F390
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
    .section .text.game_scene_after_player_presentation, "ax", %progbits

    .global func_08015744
    .thumb_func
func_08015744:
    push	{r4, r5, r6, r7, lr}
    mov	r7, r8
    push	{r7}
    sub	sp, #136
    adds	r5, r1, #0
    adds	r6, r2, #0
    ldr	r7, [r0, #4]
    movs	r0, #0
    str	r0, [sp, #8]
    adds	r0, r7, #0
    adds	r0, #168
    ldr	r0, [r0, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]
    movs	r1, #74
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    bne .Ljp_0801576E
    b .Ljp_080158AE
.Ljp_0801576E:
    ldrh	r1, [r3, #4]
    cmp	r5, #0
    bne .Ljp_08015790
    cmp	r1, #51
    ble .Ljp_08015790
    ldr	r0, .Ljp_0801578C
    cmp	r1, r0
    bgt .Ljp_08015790
    adds	r0, r1, #0
    subs	r0, #52
    cmp	r6, r0
    bne .Ljp_080157AA
    movs	r1, #1
    b .Ljp_080157AC
    .align 2, 0
.Ljp_0801578C: .4byte 0x00000133
.Ljp_08015790:
    cmp	r5, #1
    bne .Ljp_080157AA
    ldr	r0, .Ljp_080158E4
    cmp	r1, r0
    ble .Ljp_080157AA
    ldr	r0, .Ljp_080158E8
    cmp	r1, r0
    bgt .Ljp_080157AA
    ldr	r2, .Ljp_080158EC
    adds	r0, r1, r2
    movs	r1, #1
    cmp	r6, r0
    beq .Ljp_080157AC
.Ljp_080157AA:
    movs	r1, #0
.Ljp_080157AC:
    cmp	r1, #0
    beq .Ljp_080158AE
    ldr	r1, [r3, #20]
    add	r4, sp, #60
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_080157C8
    adds	r0, #7
.Ljp_080157C8:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_080157D4
    adds	r1, #7
.Ljp_080157D4:
    asrs	r1, r1, #3
    add	r0, sp, #68
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_080157FA
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_080157F4
    ldr	r0, [sp, #68]
    str	r0, [r1, #0]
.Ljp_080157F4:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_080157FA:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015804
    adds	r0, #7
.Ljp_08015804:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015810
    adds	r1, #7
.Ljp_08015810:
    asrs	r1, r1, #3
    add	r0, sp, #72
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015836
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015830
    ldr	r0, [sp, #72]
    str	r0, [r1, #0]
.Ljp_08015830:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015836:
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015840
    adds	r0, #7
.Ljp_08015840:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_0801584C
    adds	r1, #7
.Ljp_0801584C:
    asrs	r1, r1, #3
    add	r0, sp, #76
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015872
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_0801586C
    ldr	r0, [sp, #76]
    str	r0, [r1, #0]
.Ljp_0801586C:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015872:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_0801587C
    adds	r0, #7
.Ljp_0801587C:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015888
    adds	r1, #7
.Ljp_08015888:
    asrs	r1, r1, #3
    add	r0, sp, #80
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_080158AE
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_080158A8
    ldr	r0, [sp, #80]
    str	r0, [r1, #0]
.Ljp_080158A8:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_080158AE:
    adds	r4, r7, #0
    adds	r4, #168
    ldr	r0, [r4, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]
    movs	r1, #43
    bl _call_via_r2
    adds	r3, r0, #0
    mov	r8, r4
    cmp	r3, #0
    bne .Ljp_080158C8
    b .Ljp_08015A0E
.Ljp_080158C8:
    ldrh	r1, [r3, #4]
    cmp	r5, #0
    bne .Ljp_080158F0
    cmp	r1, #51
    ble .Ljp_080158F0
    ldr	r0, .Ljp_080158E4
    cmp	r1, r0
    bgt .Ljp_080158F0
    adds	r0, r1, #0
    subs	r0, #52
    cmp	r6, r0
    bne .Ljp_0801590A
    movs	r1, #1
    b .Ljp_0801590C
.Ljp_080158E4: .4byte 0x00000133
.Ljp_080158E8: .4byte 0x00000233
.Ljp_080158EC: .4byte 0xFFFFFECC
.Ljp_080158F0:
    cmp	r5, #1
    bne .Ljp_0801590A
    ldr	r0, .Ljp_08015A40
    cmp	r1, r0
    ble .Ljp_0801590A
    ldr	r0, .Ljp_08015A44
    cmp	r1, r0
    bgt .Ljp_0801590A
    ldr	r2, .Ljp_08015A48
    adds	r0, r1, r2
    movs	r1, #1
    cmp	r6, r0
    beq .Ljp_0801590C
.Ljp_0801590A:
    movs	r1, #0
.Ljp_0801590C:
    cmp	r1, #0
    beq .Ljp_08015A0E
    ldr	r1, [r3, #20]
    add	r4, sp, #84
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015928
    adds	r0, #7
.Ljp_08015928:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015934
    adds	r1, #7
.Ljp_08015934:
    asrs	r1, r1, #3
    add	r0, sp, #92
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_0801595A
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015954
    ldr	r0, [sp, #92]
    str	r0, [r1, #0]
.Ljp_08015954:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_0801595A:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015964
    adds	r0, #7
.Ljp_08015964:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015970
    adds	r1, #7
.Ljp_08015970:
    asrs	r1, r1, #3
    add	r0, sp, #96
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015996
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015990
    ldr	r0, [sp, #96]
    str	r0, [r1, #0]
.Ljp_08015990:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015996:
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_080159A0
    adds	r0, #7
.Ljp_080159A0:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_080159AC
    adds	r1, #7
.Ljp_080159AC:
    asrs	r1, r1, #3
    add	r0, sp, #100
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_080159D2
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_080159CC
    ldr	r0, [sp, #100]
    str	r0, [r1, #0]
.Ljp_080159CC:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_080159D2:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_080159DC
    adds	r0, #7
.Ljp_080159DC:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_080159E8
    adds	r1, #7
.Ljp_080159E8:
    asrs	r1, r1, #3
    add	r0, sp, #104
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015A0E
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015A08
    ldr	r0, [sp, #104]
    str	r0, [r1, #0]
.Ljp_08015A08:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015A0E:
    mov	r1, r8
    ldr	r0, [r1, #0]
    ldr	r1, [r0, #0]
    ldr	r2, [r1, #64]
    movs	r1, #75
    bl _call_via_r2
    adds	r3, r0, #0
    cmp	r3, #0
    bne .Ljp_08015A24
    b .Ljp_08015B6A
.Ljp_08015A24:
    ldrh	r1, [r3, #4]
    cmp	r5, #0
    bne .Ljp_08015A4C
    cmp	r1, #51
    ble .Ljp_08015A4C
    ldr	r0, .Ljp_08015A40
    cmp	r1, r0
    bgt .Ljp_08015A4C
    adds	r0, r1, #0
    subs	r0, #52
    cmp	r6, r0
    bne .Ljp_08015A66
    movs	r1, #1
    b .Ljp_08015A68
.Ljp_08015A40: .4byte 0x00000133
.Ljp_08015A44: .4byte 0x00000233
.Ljp_08015A48: .4byte 0xFFFFFECC
.Ljp_08015A4C:
    cmp	r5, #1
    bne .Ljp_08015A66
    ldr	r0, .Ljp_08015BB4
    cmp	r1, r0
    ble .Ljp_08015A66
    ldr	r0, .Ljp_08015BB8
    cmp	r1, r0
    bgt .Ljp_08015A66
    ldr	r2, .Ljp_08015BBC
    adds	r0, r1, r2
    movs	r1, #1
    cmp	r6, r0
    beq .Ljp_08015A68
.Ljp_08015A66:
    movs	r1, #0
.Ljp_08015A68:
    cmp	r1, #0
    beq .Ljp_08015B6A
    ldr	r1, [r3, #20]
    add	r4, sp, #108
    adds	r0, r4, #0
    ldr	r2, [r1, #12]
    adds	r1, r3, #0
    bl _call_via_r2
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015A84
    adds	r0, #7
.Ljp_08015A84:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015A90
    adds	r1, #7
.Ljp_08015A90:
    asrs	r1, r1, #3
    add	r0, sp, #116
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015AB6
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015AB0
    ldr	r0, [sp, #116]
    str	r0, [r1, #0]
.Ljp_08015AB0:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015AB6:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015AC0
    adds	r0, #7
.Ljp_08015AC0:
    asrs	r2, r0, #3
    movs	r0, #2
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015ACC
    adds	r1, #7
.Ljp_08015ACC:
    asrs	r1, r1, #3
    add	r0, sp, #120
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015AF2
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015AEC
    ldr	r0, [sp, #120]
    str	r0, [r1, #0]
.Ljp_08015AEC:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015AF2:
    movs	r1, #0
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015AFC
    adds	r0, #7
.Ljp_08015AFC:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015B08
    adds	r1, #7
.Ljp_08015B08:
    asrs	r1, r1, #3
    add	r0, sp, #124
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015B2E
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015B28
    ldr	r0, [sp, #124]
    str	r0, [r1, #0]
.Ljp_08015B28:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015B2E:
    movs	r1, #4
    ldrsh	r0, [r4, r1]
    cmp	r0, #0
    bge .Ljp_08015B38
    adds	r0, #7
.Ljp_08015B38:
    asrs	r2, r0, #3
    movs	r0, #6
    ldrsh	r1, [r4, r0]
    cmp	r1, #0
    bge .Ljp_08015B44
    adds	r1, #7
.Ljp_08015B44:
    asrs	r1, r1, #3
    add	r0, sp, #128
    strb	r2, [r0, #0]
    strb	r1, [r0, #1]
    ldr	r0, [sp, #8]
    cmp	r0, #11
    bhi .Ljp_08015B6A
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    cmp	r1, #0
    beq .Ljp_08015B64
    ldr	r0, [sp, #128]
    str	r0, [r1, #0]
.Ljp_08015B64:
    ldr	r0, [sp, #8]
    adds	r0, #1
    str	r0, [sp, #8]
.Ljp_08015B6A:
    ldr	r2, [sp, #8]
    movs	r3, #0
    add	r4, sp, #12
    cmp	r2, #0
    beq .Ljp_08015B76
    adds	r3, r4, #0
.Ljp_08015B76:
    adds	r0, r7, #0
    adds	r0, #140
    ldr	r1, [r0, #0]
    ldr	r0, .Ljp_08015BC0
    adds	r1, r1, r0
    str	r3, [sp, #0]
    str	r2, [sp, #4]
    add	r0, sp, #132
    adds	r2, r5, #0
    adds	r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr	r0, [sp, #8]
    lsls	r0, r0, #2
    adds	r0, #4
    mov	r1, sp
    adds	r1, r1, r0
    adds	r1, #8
    adds	r0, r4, #0
    cmp	r0, r1
    beq .Ljp_08015BA6
.Ljp_08015BA0:
    adds	r0, #4
    cmp	r0, r1
    bne .Ljp_08015BA0
.Ljp_08015BA6:
    add	sp, #136
    pop	{r3}
    mov	r8, r3
    pop	{r4, r5, r6, r7}
    pop	{r0}
    bx	r0
    .align 2, 0
.Ljp_08015BB4: .4byte 0x00000133
.Ljp_08015BB8: .4byte 0x00000233
.Ljp_08015BBC: .4byte 0xFFFFFECC
.Ljp_08015BC0: .4byte 0x00002E58
    .global func_08015BC4
    .thumb_func
func_08015BC4:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xe8
    ldr r0, [r0, #4]
    str r0, [sp, #0xd8]
    adds r4, r0, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    add r0, sp, #0x3c
    movs r3, #0
    strb r3, [r0]
    strb r3, [r0, #1]
    adds r1, r2, #0
    subs r1, #0x34
    adds r7, r0, #0
    cmp r1, #0xff
    bls .Lauto_08015BF8
    b .Lauto_08015FE4
    .Lauto_08015BF8:
    adds r0, r2, #1
    mov r8, r0
    adds r6, r2, #0
    subs r6, #0x33
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .Lauto_08015C16
    b .Lauto_08015D30
    .Lauto_08015C16:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .Lauto_08015C2E
    ldr r0, [pc, #0x314]
    cmp r1, r0
    bgt .Lauto_08015C2E
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .Lauto_08015C2E
    movs r2, #1
    .Lauto_08015C2E:
    cmp r2, #0
    beq .Lauto_08015D30
    ldr r1, [r3, #0x14]
    add r4, sp, #0x40
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015C4A
    adds r0, #7
    .Lauto_08015C4A:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015C56
    adds r1, #7
    .Lauto_08015C56:
    asrs r1, r1, #3
    add r0, sp, #0x48
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015C7C
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015C76
    ldr r0, [sp, #0x48]
    str r0, [r1]
    .Lauto_08015C76:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015C7C:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015C86
    adds r0, #7
    .Lauto_08015C86:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015C92
    adds r1, #7
    .Lauto_08015C92:
    asrs r1, r1, #3
    add r0, sp, #0x4c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015CB8
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015CB2
    ldr r0, [sp, #0x4c]
    str r0, [r1]
    .Lauto_08015CB2:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015CB8:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015CC2
    adds r0, #7
    .Lauto_08015CC2:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015CCE
    adds r1, #7
    .Lauto_08015CCE:
    asrs r1, r1, #3
    add r0, sp, #0x50
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015CF4
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015CEE
    ldr r0, [sp, #0x50]
    str r0, [r1]
    .Lauto_08015CEE:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015CF4:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015CFE
    adds r0, #7
    .Lauto_08015CFE:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015D0A
    adds r1, #7
    .Lauto_08015D0A:
    asrs r1, r1, #3
    add r0, sp, #0x54
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015D30
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015D2A
    ldr r0, [sp, #0x54]
    str r0, [r1]
    .Lauto_08015D2A:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015D30:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .Lauto_08015D4A
    b .Lauto_08015E64
    .Lauto_08015D4A:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .Lauto_08015D62
    ldr r0, [pc, #0x1e0]
    cmp r1, r0
    bgt .Lauto_08015D62
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .Lauto_08015D62
    movs r2, #1
    .Lauto_08015D62:
    cmp r2, #0
    beq .Lauto_08015E64
    ldr r1, [r3, #0x14]
    add r4, sp, #0x58
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015D7E
    adds r0, #7
    .Lauto_08015D7E:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015D8A
    adds r1, #7
    .Lauto_08015D8A:
    asrs r1, r1, #3
    add r0, sp, #0x60
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015DB0
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015DAA
    ldr r0, [sp, #0x60]
    str r0, [r1]
    .Lauto_08015DAA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015DB0:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015DBA
    adds r0, #7
    .Lauto_08015DBA:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015DC6
    adds r1, #7
    .Lauto_08015DC6:
    asrs r1, r1, #3
    add r0, sp, #0x64
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015DEC
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015DE6
    ldr r0, [sp, #0x64]
    str r0, [r1]
    .Lauto_08015DE6:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015DEC:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015DF6
    adds r0, #7
    .Lauto_08015DF6:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015E02
    adds r1, #7
    .Lauto_08015E02:
    asrs r1, r1, #3
    add r0, sp, #0x68
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015E28
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015E22
    ldr r0, [sp, #0x68]
    str r0, [r1]
    .Lauto_08015E22:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015E28:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015E32
    adds r0, #7
    .Lauto_08015E32:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015E3E
    adds r1, #7
    .Lauto_08015E3E:
    asrs r1, r1, #3
    add r0, sp, #0x6c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015E64
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015E5E
    ldr r0, [sp, #0x6c]
    str r0, [r1]
    .Lauto_08015E5E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015E64:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .Lauto_08015E7A
    b .Lauto_08015F9E
    .Lauto_08015E7A:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .Lauto_08015E92
    ldr r0, [pc, #0xb0]
    cmp r1, r0
    bgt .Lauto_08015E92
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .Lauto_08015E92
    movs r2, #1
    .Lauto_08015E92:
    cmp r2, #0
    bne .Lauto_08015E98
    b .Lauto_08015F9E
    .Lauto_08015E98:
    ldr r1, [r3, #0x14]
    add r4, sp, #0x70
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015EB0
    adds r0, #7
    .Lauto_08015EB0:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015EBC
    adds r1, #7
    .Lauto_08015EBC:
    asrs r1, r1, #3
    add r0, sp, #0x78
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015EE2
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015EDC
    ldr r0, [sp, #0x78]
    str r0, [r1]
    .Lauto_08015EDC:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015EE2:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015EEC
    adds r0, #7
    .Lauto_08015EEC:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015EF8
    adds r1, #7
    .Lauto_08015EF8:
    asrs r1, r1, #3
    add r0, sp, #0x7c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015F1E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015F18
    ldr r0, [sp, #0x7c]
    str r0, [r1]
    .Lauto_08015F18:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015F1E:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015F28
    adds r0, #7
    .Lauto_08015F28:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    b .Lauto_08015F38
    .byte 0x00, 0x00, 0x33, 0x01, 0x00, 0x00
    .Lauto_08015F38:
    bge .Lauto_08015F3C
    adds r1, #7
    .Lauto_08015F3C:
    asrs r1, r1, #3
    add r0, sp, #0x80
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015F62
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015F5C
    ldr r0, [sp, #0x80]
    str r0, [r1]
    .Lauto_08015F5C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015F62:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08015F6C
    adds r0, #7
    .Lauto_08015F6C:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .Lauto_08015F78
    adds r1, #7
    .Lauto_08015F78:
    asrs r1, r1, #3
    add r0, sp, #0x84
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08015F9E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .Lauto_08015F98
    ldr r0, [sp, #0x84]
    str r0, [r1]
    .Lauto_08015F98:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08015F9E:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .Lauto_08015FAA
    adds r2, r5, #0
    .Lauto_08015FAA:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, [pc, #0x2c]
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0x88
    movs r2, #0
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0x88
    cmp r1, r2
    bne .Lauto_08015FD8
    b .Lauto_080163DE
    .Lauto_08015FD8:
    adds r1, #4
    cmp r1, r2
    bne .Lauto_08015FD8
    b .Lauto_080163DE
    .byte 0x58, 0x2E, 0x00, 0x00
    .Lauto_08015FE4:
    ldr r1, [pc, #0x318]
    adds r0, r2, r1
    cmp r0, #0xff
    bls .Lauto_08015FEE
    b .Lauto_080164D4
    .Lauto_08015FEE:
    adds r0, r2, #1
    mov r8, r0
    adds r1, #1
    adds r6, r2, r1
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .Lauto_0801600C
    b .Lauto_08016128
    .Lauto_0801600C:
    ldrh r1, [r3, #4]
    ldr r0, [pc, #0x2f4]
    movs r2, #0
    cmp r1, r0
    ble .Lauto_08016026
    ldr r0, [pc, #0x2f0]
    cmp r1, r0
    bgt .Lauto_08016026
    ldr r4, [pc, #0x2e0]
    adds r0, r1, r4
    cmp r6, r0
    bne .Lauto_08016026
    movs r2, #1
    .Lauto_08016026:
    cmp r2, #0
    beq .Lauto_08016128
    ldr r1, [r3, #0x14]
    add r4, sp, #0x8c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08016042
    adds r0, #7
    .Lauto_08016042:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_0801604E
    adds r0, #7
    .Lauto_0801604E:
    asrs r0, r0, #3
    add r1, sp, #0x94
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08016074
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_0801606E
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_0801606E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08016074:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_0801607E
    adds r0, #7
    .Lauto_0801607E:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_0801608A
    adds r0, #7
    .Lauto_0801608A:
    asrs r0, r0, #3
    add r1, sp, #0x98
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080160B0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_080160AA
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_080160AA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080160B0:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080160BA
    adds r0, #7
    .Lauto_080160BA:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_080160C6
    adds r0, #7
    .Lauto_080160C6:
    asrs r0, r0, #3
    add r1, sp, #0x9c
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080160EC
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_080160E6
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_080160E6:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080160EC:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080160F6
    adds r0, #7
    .Lauto_080160F6:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_08016102
    adds r0, #7
    .Lauto_08016102:
    asrs r0, r0, #3
    add r1, sp, #0xa0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08016128
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_08016122
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_08016122:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08016128:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .Lauto_08016142
    b .Lauto_0801625E
    .Lauto_08016142:
    ldrh r1, [r3, #4]
    ldr r0, [pc, #0x1bc]
    movs r2, #0
    cmp r1, r0
    ble .Lauto_0801615C
    ldr r0, [pc, #0x1b8]
    cmp r1, r0
    bgt .Lauto_0801615C
    ldr r4, [pc, #0x1ac]
    adds r0, r1, r4
    cmp r6, r0
    bne .Lauto_0801615C
    movs r2, #1
    .Lauto_0801615C:
    cmp r2, #0
    beq .Lauto_0801625E
    ldr r1, [r3, #0x14]
    add r4, sp, #0xa4
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08016178
    adds r0, #7
    .Lauto_08016178:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_08016184
    adds r0, #7
    .Lauto_08016184:
    asrs r0, r0, #3
    add r1, sp, #0xac
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080161AA
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_080161A4
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_080161A4:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080161AA:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080161B4
    adds r0, #7
    .Lauto_080161B4:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_080161C0
    adds r0, #7
    .Lauto_080161C0:
    asrs r0, r0, #3
    add r1, sp, #0xb0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080161E6
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_080161E0
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_080161E0:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080161E6:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080161F0
    adds r0, #7
    .Lauto_080161F0:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_080161FC
    adds r0, #7
    .Lauto_080161FC:
    asrs r0, r0, #3
    add r1, sp, #0xb4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08016222
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_0801621C
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_0801621C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08016222:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_0801622C
    adds r0, #7
    .Lauto_0801622C:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_08016238
    adds r0, #7
    .Lauto_08016238:
    asrs r0, r0, #3
    add r1, sp, #0xb8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_0801625E
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_08016258
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_08016258:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_0801625E:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .Lauto_08016274
    b .Lauto_080163A0
    .Lauto_08016274:
    ldrh r1, [r3, #4]
    ldr r0, [pc, #0x8c]
    movs r2, #0
    cmp r1, r0
    ble .Lauto_0801628E
    ldr r0, [pc, #0x88]
    cmp r1, r0
    bgt .Lauto_0801628E
    ldr r4, [pc, #0x78]
    adds r0, r1, r4
    cmp r6, r0
    bne .Lauto_0801628E
    movs r2, #1
    .Lauto_0801628E:
    cmp r2, #0
    bne .Lauto_08016294
    b .Lauto_080163A0
    .Lauto_08016294:
    ldr r1, [r3, #0x14]
    add r4, sp, #0xbc
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080162AC
    adds r0, #7
    .Lauto_080162AC:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_080162B8
    adds r0, #7
    .Lauto_080162B8:
    asrs r0, r0, #3
    add r1, sp, #0xc4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080162DE
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_080162D8
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_080162D8:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080162DE:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_080162E8
    adds r0, #7
    .Lauto_080162E8:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_080162F4
    adds r0, #7
    .Lauto_080162F4:
    asrs r0, r0, #3
    add r1, sp, #0xc8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    b .Lauto_0801630C
    .byte 0xCC, 0xFE, 0xFF, 0xFF, 0x33, 0x01, 0x00, 0x00, 0x33, 0x02, 0x00, 0x00
    .Lauto_0801630C:
    cmp r0, #0xb
    bhi .Lauto_08016328
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_08016322
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_08016322:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08016328:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_08016332
    adds r0, #7
    .Lauto_08016332:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_0801633E
    adds r0, #7
    .Lauto_0801633E:
    asrs r0, r0, #3
    add r1, sp, #0xcc
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_08016364
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_0801635E
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_0801635E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_08016364:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .Lauto_0801636E
    adds r0, #7
    .Lauto_0801636E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .Lauto_0801637A
    adds r0, #7
    .Lauto_0801637A:
    asrs r0, r0, #3
    add r1, sp, #0xd0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .Lauto_080163A0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .Lauto_0801639A
    ldr r0, [r1]
    str r0, [r2]
    .Lauto_0801639A:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
    .Lauto_080163A0:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .Lauto_080163AC
    adds r2, r5, #0
    .Lauto_080163AC:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, [pc, #0x48]
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0xd4
    movs r2, #1
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0xd4
    cmp r1, r2
    beq .Lauto_080163DE
    .Lauto_080163D8:
    adds r1, #4
    cmp r1, r2
    bne .Lauto_080163D8
    .Lauto_080163DE:
    ldr r0, [r0]
    str r0, [sp, #0x3c]
    ldr r0, [r4]
    ldr r4, [pc, #0x14]
    adds r0, r0, r4
    bl GetLayoutKind__C14MineFloorState
    cmp r0, #4
    bhi .Lauto_080164D4
    lsls r0, r0, #2
    ldr r1, [pc, #0xc]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00, 0x04, 0x64, 0x01, 0x08, 0x18, 0x64, 0x01, 0x08, 0x18, 0x64
    .byte 0x01, 0x08, 0x18, 0x64, 0x01, 0x08, 0x18, 0x64, 0x01, 0x08, 0x18, 0x64, 0x01, 0x08, 0x38, 0x78
    .byte 0x00, 0x01, 0x10, 0x30, 0x82, 0x46, 0x0F, 0xA8, 0x40, 0x78, 0x00, 0x01, 0x07, 0x1C, 0x38, 0x37
    .byte 0x08, 0x20, 0x82, 0x44, 0x08, 0x37, 0x38, 0x99, 0x08, 0x68, 0x02, 0x68, 0xB4, 0x32, 0x37, 0x92
    .byte 0x02, 0xAE, 0x29, 0x4B, 0x99, 0x46, 0x44, 0x46, 0x49, 0x46, 0x0C, 0x40, 0x32, 0x88, 0x27, 0x4D
    .byte 0x29, 0x1C, 0x11, 0x40, 0x21, 0x43, 0x31, 0x80, 0x52, 0x46, 0x14, 0x04, 0x22, 0x0C, 0x3F, 0x23
    .byte 0x9C, 0x46, 0x1A, 0x40, 0x92, 0x00, 0x39, 0x92, 0x71, 0x78, 0x88, 0x46, 0x03, 0x23, 0x19, 0x1C
    .byte 0x42, 0x46, 0x11, 0x40, 0x39, 0x9A, 0x11, 0x43, 0x71, 0x70, 0xA4, 0x0D, 0x49, 0x46, 0x0C, 0x40
    .byte 0x72, 0x88, 0x29, 0x1C, 0x11, 0x40, 0x21, 0x43, 0x71, 0x80, 0x3A, 0x04, 0x11, 0x0C, 0x64, 0x46
    .byte 0x21, 0x40, 0x89, 0x00, 0xF4, 0x78, 0x23, 0x40, 0x0B, 0x43, 0xF3, 0x70, 0x92, 0x0D, 0x49, 0x46
    .byte 0x0A, 0x40, 0xB1, 0x88, 0x0D, 0x40, 0x15, 0x43, 0xB5, 0x80, 0x37, 0x9A, 0x13, 0x68, 0x31, 0x1C
    .byte 0x01, 0x22, 0xBC, 0xF0, 0x10, 0xFE, 0x36, 0x98
    bl func_080D7F08
    .byte 0x00, 0x24, 0x38, 0x9B
    .byte 0x18, 0x68, 0x01, 0x68, 0x49, 0x69, 0xBC, 0xF0, 0x02, 0xFE, 0x02, 0x1C, 0x00, 0x97, 0x01, 0x94
    .byte 0x36, 0x98, 0x00, 0x21, 0x53, 0x46
    bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi
    .Lauto_080164D4:
    add sp, #0xe8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .4byte 0x000003FF
    .4byte 0xFFFFFC00
    .section .text.game_scene_after_contest_registration, "ax", %progbits

    .global func_08016668
    .thumb_func
func_08016668:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r6, [r0, #4]
    cmp r1, #4
    bls .Ljp_08016678
    b .Ljp_08016884
.Ljp_08016678:
    lsls r0, r1, #2
    ldr r1, .Ljp_08016684 @ =.Ljp_08016688
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.Ljp_08016684: .4byte .Ljp_08016688
.Ljp_08016688: @ jump table
    .4byte .Ljp_0801669C @ case 0
    .4byte .Ljp_08016700 @ case 1
    .4byte .Ljp_08016700 @ case 2
    .4byte .Ljp_08016796 @ case 3
    .4byte .Ljp_08016826 @ case 4
.Ljp_0801669C:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    cmp r0, #0
    beq .Ljp_080166B2
    b .Ljp_08016884
.Ljp_080166B2:
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2c
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .Ljp_080166EA
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_080166EA
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.Ljp_080166EA:
    cmp r4, #0
    bne .Ljp_080166F0
    b .Ljp_08016884
.Ljp_080166F0:
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbc
    lsls r2, r2, #2
    movs r3, #0x84
    bl SetLocation__7AEntityUiii
    b .Ljp_08016884
.Ljp_08016700:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D058__C4Barn
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    bne .Ljp_0801671E
    b .Ljp_08016884
.Ljp_0801671E:
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D858__4Barn
    adds r5, r7, #0
    adds r5, #0x36
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r5, r0, #0
    cmp r5, #0
    beq .Ljp_08016768
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r5, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_08016768
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r5, #0
    bl _call_via_r1
.Ljp_08016768:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0xbe
    lsls r0, r0, #3
    adds r1, r1, r0
    mov r4, sp
    mov r0, sp
    adds r2, r7, #0
    bl method_0800D074__C4BarnUi
    cmp r5, #0
    bne .Ljp_08016782
    b .Ljp_08016884
.Ljp_08016782:
    mov r0, sp
    movs r1, #0
    ldrsh r2, [r0, r1]
    movs r0, #2
    ldrsh r3, [r4, r0]
    adds r0, r5, #0
    movs r1, #0x25
    bl SetLocation__7AEntityUiii
    b .Ljp_08016884
.Ljp_08016796:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetUnkEnt__C4Coop
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    beq .Ljp_08016884
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800CBC0__4Coop
    adds r5, r7, #0
    adds r5, #0x2e
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .Ljp_080167FC
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_080167FC
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.Ljp_080167FC:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r1, r1, r0
    add r5, sp, #4
    adds r0, r5, #0
    adds r2, r7, #0
    bl method_0800C6F0__C4CoopUi
    cmp r4, #0
    beq .Ljp_08016884
    movs r1, #0
    ldrsh r2, [r5, r1]
    movs r0, #2
    ldrsh r3, [r5, r0]
    adds r0, r4, #0
    movs r1, #0x11
    bl SetLocation__7AEntityUiii
    b .Ljp_08016884
.Ljp_08016826:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    cmp r0, #0
    bne .Ljp_08016884
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2b
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .Ljp_08016872
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Ljp_08016872
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.Ljp_08016872:
    cmp r4, #0
    beq .Ljp_08016884
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbf
    lsls r2, r2, #1
    movs r3, #0x52
    bl SetLocation__7AEntityUiii
.Ljp_08016884:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .global func_08016890
    .thumb_func
func_08016890:
    push {lr}
    ldr r2, [r0, #4]
    cmp r1, #4
    bhi .Lauto_080168DE
    lsls r0, r1, #2
    ldr r1, [pc, #8]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0xA8, 0x68, 0x01, 0x08
    .Lauto_080168A8:
    .byte 0xBC, 0x68, 0x01, 0x08, 0x0C, 0x69, 0x01, 0x08, 0x0C, 0x69, 0x01, 0x08, 0x1E, 0x69, 0x01, 0x08
    .byte 0xEC, 0x68, 0x01, 0x08
    .Lauto_080168BC:
    .byte 0x10, 0x1C, 0x8C, 0x30, 0x02, 0x68, 0x08, 0x49, 0x50, 0x18, 0x01, 0x78, 0x02, 0x20, 0x08, 0x40
    .byte 0x00, 0x28, 0x19, 0xD1, 0x05, 0x49, 0x50, 0x18, 0x01, 0x78, 0x04, 0x20, 0x08, 0x40, 0x00, 0x28
    .byte 0x12, 0xD1
    .Lauto_080168DE:
    movs r1, #1
    rsbs r1, r1, #0
    b .Lauto_08016930
    .byte 0x9A, 0x21, 0x00, 0x00, 0xA1, 0x21, 0x00, 0x00
    .Lauto_080168EC:
    .byte 0x10, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0x05, 0x49, 0x40, 0x18, 0x01, 0x78, 0x10, 0x20, 0x08, 0x40
    .byte 0x01, 0x21, 0x49, 0x42, 0x00, 0x28, 0x15, 0xD0, 0x00, 0x21, 0x13, 0xE0, 0x9C, 0x21, 0x00, 0x00
    .Lauto_0801690C:
    .byte 0x10, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0xBE, 0x21, 0xC9, 0x00, 0x40, 0x18, 0xF6, 0xF7, 0x8E, 0xFB
    .byte 0x07, 0xE0
    .Lauto_0801691E:
    .byte 0x10, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x40, 0x18, 0xF5, 0xF7, 0xC5, 0xFE
    .byte 0x01, 0x1C
    .Lauto_08016930:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .byte 0x00, 0x00
    .section .text.game_scene_field_item_tool_after, "ax", %progbits
    .align 2, 0

    .global func_08017348
    .thumb_func
func_08017348:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r7, r0, #0
    str r1, [sp, #0x18]
    mov sl, r2
    str r3, [sp, #0x1c]
    add r0, sp, #0x50
    ldrb r0, [r0]
    str r0, [sp, #0x20]
    ldr r0, [pc, #0x264]
    str r0, [r7]
    ldr r1, [pc, #0x264]
    adds r0, r7, #0
    stm r0!, {r1}
    ldr r2, [sp, #0x1c]
    ldr r1, [r2]
    movs r3, #0
    str r3, [r2]
    str r1, [sp, #4]
    add r1, sp, #4
    bl __18GameSceneWorldDataG22GameSceneWorldMapOwner
    ldr r0, [pc, #0x250]
    adds r0, r0, r7
    mov r8, r0
    ldr r1, [sp, #0x18]
    str r1, [r0]
    ldr r2, [pc, #0x24c]
    adds r0, r7, r2
    movs r3, #0
    strb r3, [r0]
    movs r0, #0x82
    lsls r0, r0, #5
    adds r4, r7, r0
    mov r2, r8
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x10
    str r0, [r4]
    strb r3, [r4, #4]
    ldr r3, [pc, #0x234]
    adds r3, r3, r7
    mov sb, r3
    ldr r1, [r1, #0x10]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x1b
    adds r0, r7, #0
    bl GetWorldTimeOfDayPeriod
    mov r1, sb
    str r0, [r1]
    ldr r0, [r4]
    .byte 0x04, 0x68, 0xE5, 0x02, 0xED, 0x0E, 0x64, 0x01, 0xA4, 0x0E, 0x42, 0x46, 0x10, 0x68, 0x10, 0x30
    .byte 0xF6, 0xF7, 0x9C, 0xFF, 0x02, 0x1C, 0x48, 0x46, 0x03, 0x68, 0x28, 0x1C, 0x21, 0x1C
    bl GetTimeOfDayTransitionValue
    .byte 0x80, 0x4A, 0xB9, 0x18, 0x08, 0x70, 0x7F, 0x4B, 0xFC, 0x18, 0xB0, 0x20, 0x00, 0x02
    bl __builtin_vec_new
    .byte 0x20, 0x60, 0x7D, 0x49, 0x78, 0x18, 0x52, 0x46, 0x02, 0x60, 0x7C, 0x4B
    .byte 0xF8, 0x18, 0x00, 0x21, 0x01, 0x60, 0x7B, 0x4A, 0xB8, 0x18, 0x01, 0x60, 0x0C, 0x33, 0xF8, 0x18
    .byte 0x01, 0x60, 0x79, 0x49, 0x78, 0x18, 0x00, 0x22, 0x02, 0x60, 0x08, 0x33, 0xF9, 0x18, 0x01, 0x20
    .byte 0x02, 0xAA, 0x90, 0x46, 0x00, 0x23, 0x01, 0x22, 0x52, 0x42, 0x08, 0xC1, 0x01, 0x38, 0x90, 0x42
    .byte 0xFB, 0xD1, 0x72, 0x4B, 0xF9, 0x18, 0x01, 0x20, 0x71, 0x4A, 0xD2, 0x19, 0x91, 0x46, 0x00, 0x23
    .byte 0x01, 0x22, 0x52, 0x42, 0x08, 0xC1, 0x01, 0x38, 0x90, 0x42, 0xFB, 0xD1, 0x6C, 0x4B, 0xF9, 0x18
    .byte 0x00, 0x20, 0x08, 0x60, 0x84, 0x20, 0x40, 0x01, 0x3A, 0x18, 0x03, 0x23, 0x04, 0x26, 0x76, 0x42
    .byte 0x00, 0x25, 0x01, 0x24, 0x64, 0x42, 0x51, 0x78, 0x30, 0x1C, 0x08, 0x40, 0x50, 0x70, 0x95, 0x60
    .byte 0x0C, 0x32, 0x01, 0x3B, 0xA3, 0x42, 0xF6, 0xD1, 0x62, 0x4A, 0xB9, 0x18, 0x05, 0x20, 0x00, 0x23
    .byte 0x01, 0x22, 0x52, 0x42, 0x08, 0xC1, 0x01, 0x38, 0x90, 0x42, 0xFB, 0xD1, 0x5E, 0x4B, 0xF9, 0x18
    .byte 0x00, 0x20, 0x08, 0x70, 0x7C, 0x68, 0x50, 0x48, 0x3E, 0x18, 0x31, 0x68, 0x5B, 0x4A, 0x89, 0x18
    .byte 0x40, 0x46
    bl GetLocation__C6Farmer
    .byte 0x4E, 0x4B, 0xF8, 0x18, 0x02, 0x68, 0x4D, 0x49, 0x78, 0x18
    .byte 0x03, 0x78, 0x1E, 0x20, 0xC0, 0x1A, 0x00, 0x90, 0x20, 0x1C, 0x41, 0x46
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    .byte 0x78, 0x68, 0x00, 0x68, 0x02, 0x28, 0x10, 0xD0, 0x47, 0x4A, 0xB8, 0x18, 0x05, 0x68, 0x30, 0x68
    .byte 0x04, 0x1C, 0x14, 0x34, 0x10, 0x30, 0xF6, 0xF7, 0x19, 0xFF, 0x00, 0x22, 0x03, 0x28, 0x00, 0xD1
    .byte 0x01, 0x22, 0x28, 0x1C, 0x21, 0x1C
    bl InitializeFarmTerrain
    .byte 0x08, 0x9B, 0x00, 0x2B, 0x14, 0xD0
    .byte 0x39, 0x49, 0x78, 0x18, 0x00, 0x68, 0x46, 0x4A, 0x80, 0x18
    bl HasRegisteredEvents__C14GameEventState
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x07, 0xD0, 0x39, 0x4B, 0xF8, 0x18, 0x00, 0x68
    bl IsBackgroundMusicActive__9GameScene
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x02, 0xD1, 0x38, 0x1C
    bl UpdateWorldBackgroundAudio
    .byte 0xA0, 0x20
    bl __builtin_new
    .byte 0x39, 0x1C
    bl __22EntityAuxiliarySpritesP10GameObject
    .byte 0x3B, 0x49, 0x7D, 0x18, 0x04, 0x1C, 0x28, 0x68, 0x84, 0x42
    .byte 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._22EntityAuxiliarySprites
    .byte 0x2C, 0x60, 0x36, 0x4A
    .byte 0xBC, 0x18, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    .byte 0x93, 0xF0, 0xE8, 0xFB, 0x25, 0x60, 0x04, 0x20
    bl __builtin_new
    .byte 0x79, 0x68, 0x4A, 0x68
    .byte 0x39, 0x1C, 0x93, 0xF0, 0x51, 0xFA, 0x2C, 0x4B, 0xFD, 0x18, 0x04, 0x1C, 0x28, 0x68, 0x84, 0x42
    .byte 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21, 0x93, 0xF0, 0xD4, 0xFB, 0x2C, 0x60, 0x00, 0x24
    .byte 0x38, 0x1C, 0x21, 0x1C, 0x03, 0xF0, 0x7A, 0xF8, 0x01, 0x34, 0x63, 0x2C, 0xF8, 0xD9, 0x4C, 0x46
    .byte 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._22GameSceneWeatherEffect
    .byte 0x25, 0x60, 0x78, 0x68, 0x40, 0x68, 0x8C, 0xF0, 0x96, 0xFD, 0x24, 0x30, 0x00, 0x78
    .byte 0x00, 0x28, 0x4A, 0xD1, 0x78, 0x68, 0x01, 0x68, 0x07, 0x4A, 0xB8, 0x18, 0x00, 0x68, 0x08, 0x30
    .byte 0x2E, 0x29, 0x2F, 0xD0, 0x2E, 0x29, 0x29, 0xDD, 0x2F, 0x29, 0x2D, 0xD0, 0x2E, 0xE0, 0x00, 0x00
    .byte 0x78, 0x54, 0x0E, 0x08, 0x04, 0x53, 0x0E, 0x08, 0x38, 0x10, 0x00, 0x00, 0x3C, 0x10, 0x00, 0x00
    .byte 0x48, 0x10, 0x00, 0x00, 0x4C, 0x10, 0x00, 0x00, 0x50, 0x10, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00
    .byte 0x58, 0x10, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x68, 0x10, 0x00, 0x00, 0x74, 0x10, 0x00, 0x00
    .byte 0x7C, 0x10, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00, 0xC8, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .byte 0x4C, 0x21, 0x00, 0x00, 0x24, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x2C, 0x29, 0x05, 0xDB
    .byte 0x00, 0x20, 0x04, 0xE0, 0x01, 0x20, 0x02, 0xE0, 0x02, 0x20, 0x00, 0xE0, 0x00, 0x68, 0x01, 0x28
    .byte 0x02, 0xD0, 0x02, 0x28, 0x05, 0xD0, 0x08, 0xE0, 0x38, 0x1C, 0x01, 0x21, 0x08, 0xF0, 0x12, 0xF9
    .byte 0x03, 0xE0, 0x38, 0x1C, 0x00, 0x21, 0x08, 0xF0, 0x0D, 0xF9, 0x38, 0x1C, 0x07, 0xF0, 0x4C, 0xFC
    .byte 0x38, 0x1C
    bl RefreshWorldVase
    .byte 0x38, 0x1C, 0x07, 0xF0, 0x0E, 0xFD, 0x38, 0x1C
    bl RefreshWorldHillSeasonalSprites
    .byte 0x38, 0x1C
    bl RefreshWorldWinterAndFireplaceSprites
    .byte 0x39, 0x48, 0x00, 0x68, 0x00, 0x23, 0x09, 0x93
    .byte 0x38, 0x49, 0x79, 0x18, 0x0A, 0x91, 0x38, 0x4A, 0x86, 0x18, 0x30, 0x78, 0x80, 0x07, 0x80, 0x0F
    .byte 0x82, 0x46, 0x01, 0x28, 0x3C, 0xD1, 0x70, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x79, 0x68, 0x09, 0x68
    .byte 0x88, 0x42, 0x35, 0xD1, 0x31, 0x4B, 0xDB, 0x19, 0x98, 0x46, 0x09, 0x99, 0x88, 0x00, 0x80, 0x44
    .byte 0x4C, 0x20
    bl __builtin_new
    .byte 0x04, 0x1C, 0x32, 0x89, 0x91, 0x46, 0x39, 0x1C, 0x02, 0x22
    .byte 0x1B, 0x23
    bl __19GameSceneSpriteBaseP10GameObjectUii
    .byte 0x2A, 0x48, 0x60, 0x62, 0x23, 0x1C, 0x28, 0x33, 0x0B, 0x93
    .byte 0x0A, 0x98, 0x05, 0x68, 0x04, 0xA8, 0xEB, 0x68, 0x0A, 0x99, 0x4A, 0x46, 0xBB, 0xF0, 0x04, 0xFD
    .byte 0x04, 0x98, 0x02, 0x88, 0x0B, 0x98, 0x2B, 0x69, 0x0A, 0x99, 0xBB, 0xF0, 0xFD, 0xFC, 0x20, 0x1C
    .byte 0x48, 0x30, 0x51, 0x46, 0x01, 0x70, 0x45, 0x46, 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xBB, 0xF0, 0xEB, 0xFC, 0x2C, 0x60
    .byte 0x0C, 0x36, 0x09, 0x9A, 0x01, 0x32, 0x09, 0x92, 0x06, 0x2A, 0xB6, 0xD3, 0x06, 0x9B, 0x15, 0x49
    .byte 0x58, 0x18, 0x00, 0x78, 0x00, 0x28, 0x05, 0xD0, 0x38, 0x1C
    bl SuspendWorldUpdates
    .byte 0x38, 0x1C
    bl ResumeWorldUpdates
    .byte 0x07, 0x9A, 0x11, 0x68, 0x00, 0x29, 0x07, 0xD0, 0x08, 0x1C, 0x90, 0x30
    .byte 0x00, 0x68, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xBB, 0xF0, 0xCC, 0xFC, 0x38, 0x1C, 0x0C, 0xB0
    .byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .byte 0x0C, 0x04, 0x00, 0x03, 0xE4, 0x0D, 0x00, 0x00, 0xDC, 0x04, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00
    .4byte __vt_20GameSceneGroupSprite
    .byte 0xC4, 0x34, 0x00, 0x00
    .global func_080179CC
    .thumb_func
func_080179CC:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    adds r6, r0, #0
    mov r8, r1
    ldr r0, [pc, #0x74]
    str r0, [r6]
    ldr r1, [pc, #0x74]
    adds r0, r6, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_0801781A
    ldr r0, [pc, #0x70]
    adds r4, r6, r0
    ldr r0, [r4]
    ldr r1, [pc, #0x6c]
    adds r0, r0, r1
    bl func_0800ED2C
    ldr r0, [r4]
    ldr r1, [pc, #0x68]
    adds r7, r0, r1
    ldr r1, [pc, #0x68]
    adds r0, r6, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne .Lauto_0801781A
    adds r0, r6, #0
    bl GetSongPlayerPool__20GameSceneWorldPrefix
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .Lauto_080177B8
    .Lauto_080177A6:
    ldr r0, [r4]
    bl IsActive__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_08017804
    adds r4, #4
    cmp r4, r5
    bne .Lauto_080177A6
    .Lauto_080177B8:
    subs r0, r5, #4
    ldr r0, [r0]
    .Lauto_080177BC:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    adds r0, r7, #0
    bl func_080A45A8
    cmp r0, #2
    beq .Lauto_08017808
    ldr r1, [pc, #0x1c]
    adds r0, r6, r1
    ldr r2, [r0]
    ldr r1, [pc, #0x28]
    adds r0, r2, r1
    ldr r1, [pc, #0x28]
    adds r2, r2, r1
    adds r1, r7, #0
    bl func_080A1484
    b .Lauto_0801781A
    .byte 0x00, 0x00, 0x04, 0x53, 0x0E, 0x08, 0xC8, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B
    .byte 0x00, 0x00, 0xCC, 0x1C, 0x00, 0x00, 0xC9, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x4C, 0x21
    .byte 0x00, 0x00
    .Lauto_08017804:
    ldr r0, [r4]
    b .Lauto_080177BC
    .Lauto_08017808:
    ldr r0, [pc, #0x44]
    movs r1, #0
    str r0, [sp]
    str r1, [sp, #4]
    adds r0, r6, #0
    mov r1, sp
    movs r2, #0
    bl QueueWorldScript
    .Lauto_0801781A:
    ldr r1, [pc, #0x38]
    adds r0, r6, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_08017828
    bl __builtin_vec_delete
    .Lauto_08017828:
    ldr r0, [pc, #0x2c]
    adds r5, r6, r0
    adds r7, r6, #4
    cmp r5, #0
    beq .Lauto_08017860
    ldr r1, [pc, #0x28]
    adds r4, r6, r1
    .Lauto_08017836:
    cmp r5, r4
    beq .Lauto_08017860
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_08017836
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    b .Lauto_08017836
    .byte 0x3B, 0x02, 0x00, 0x00, 0x50, 0x10, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00, 0xC8, 0x10, 0x00, 0x00
    .Lauto_08017860:
    movs r1, #0x84
    lsls r1, r1, #5
    adds r0, r6, r1
    cmp r0, #0
    beq .Lauto_08017890
    adds r1, #0x30
    adds r4, r6, r1
    cmp r0, r4
    beq .Lauto_08017890
    movs r0, #0x84
    lsls r0, r0, #5
    adds r5, r6, r0
    .Lauto_08017878:
    subs r4, #0xc
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .Lauto_0801788C
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801788C:
    cmp r5, r4
    bne .Lauto_08017878
    .Lauto_08017890:
    ldr r1, [pc, #0xe0]
    adds r4, r6, r1
    ldr r0, [r4]
    cmp r0, #0
    beq .Lauto_080178A0
    movs r1, #3
    bl _._22GameSceneWeatherEffect
    .Lauto_080178A0:
    ldr r1, [pc, #0xd4]
    adds r0, r6, r1
    cmp r0, #0
    beq .Lauto_080178C6
    cmp r0, r4
    beq .Lauto_080178C6
    adds r5, r0, #0
    .Lauto_080178AE:
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_080178C2
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080178C2:
    cmp r5, r4
    bne .Lauto_080178AE
    .Lauto_080178C6:
    ldr r1, [pc, #0xb4]
    adds r0, r6, r1
    cmp r0, #0
    beq .Lauto_080178F2
    adds r1, #8
    adds r4, r6, r1
    cmp r0, r4
    beq .Lauto_080178F2
    ldr r0, [pc, #0xa4]
    adds r5, r6, r0
    .Lauto_080178DA:
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_080178EE
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080178EE:
    cmp r5, r4
    bne .Lauto_080178DA
    .Lauto_080178F2:
    ldr r1, [pc, #0x8c]
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_08017908
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_08017908:
    ldr r1, [pc, #0x78]
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_0801791E
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801791E:
    ldr r1, [pc, #0x68]
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_08017934
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_08017934:
    ldr r1, [pc, #0x54]
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .Lauto_0801794A
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_0801794A:
    adds r0, r7, #0
    movs r1, #2
    bl _._18GameSceneWorldData
    ldr r0, [pc, #0x3c]
    str r0, [r6]
    movs r0, #1
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    beq .Lauto_08017966
    adds r0, r6, #0
    bl __builtin_delete
    .Lauto_08017966:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x7C, 0x10, 0x00, 0x00, 0x74, 0x10, 0x00, 0x00, 0x6C, 0x10, 0x00, 0x00, 0x68, 0x10
    .byte 0x00, 0x00, 0x64, 0x10, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x58, 0x10, 0x00, 0x00, 0xE0, 0x55
    .byte 0x0E, 0x08
    .section .text.world_update_after_pause_query, "ax", %progbits
    .align 2, 0

    .global func_08017C30
    .thumb_func
func_08017C30:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov r8, r0
    str r1, [sp, #0x28]
    ldr r4, [pc, #0x130]
    add r4, r8
    ldr r0, [r4]
    ldr r1, [pc, #0x130]
    adds r0, r0, r1
    bl func_0800E4FC
    str r0, [sp, #0x2c]
    ldr r1, [pc, #0x128]
    add r1, r8
    ldrb r0, [r1]
    add r2, sp, #0x20
    mov sb, r2
    cmp r0, #0
    bne .Lauto_080179F4
    b .Lauto_08017B52
    .Lauto_080179F4:
    movs r0, #0
    strb r0, [r1]
    mov r3, r8
    ldr r0, [r3]
    ldr r2, [r0, #0x3c]
    mov r0, r8
    movs r1, #0x4b
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [pc, #0x100]
    adds r0, r0, r1
    bl func_0800ED2C
    ldr r0, [r4]
    ldr r2, [pc, #0x100]
    adds r6, r0, r2
    ldr r0, [pc, #0x100]
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08017A22
    b .Lauto_08017B52
    .Lauto_08017A22:
    mov r3, r8
    ldr r0, [r3]
    movs r1, #0xa6
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    mov r0, r8
    bl _call_via_r1
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .Lauto_08017A4E
    .Lauto_08017A3C:
    ldr r0, [r4]
    bl IsActive__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_08017B30
    adds r4, #4
    cmp r4, r5
    bne .Lauto_08017A3C
    .Lauto_08017A4E:
    subs r0, r5, #4
    ldr r0, [r0]
    .Lauto_08017A52:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    adds r0, r6, #0
    bl func_080A45A8
    cmp r0, #2
    beq .Lauto_08017B34
    ldr r0, [pc, #0xa4]
    add r0, r8
    ldr r2, [r0]
    ldr r3, [pc, #0xb0]
    adds r0, r2, r3
    ldr r1, [pc, #0xb0]
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_080A1484
    ldrb r0, [r6, #1]
    lsrs r0, r0, #2
    ldrh r2, [r6, #2]
    ldr r3, [pc, #0xa4]
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    .byte 0xF1, 0x78, 0x89, 0x08, 0xB0, 0x88, 0x18, 0x40, 0x80, 0x01, 0x08, 0x43, 0x00, 0x04, 0x00, 0x14
    .byte 0x03, 0xAB, 0x19, 0x1C, 0x0A, 0x80, 0x58, 0x80, 0x42, 0x46, 0x10, 0x68, 0x41, 0x6E, 0x40, 0x46
    .byte 0xBB, 0xF0, 0x10, 0xFB, 0x1F, 0x4D, 0x45, 0x44, 0x06, 0x1C, 0x03, 0x98, 0x68, 0x60, 0x00, 0x24
    .byte 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C
    .byte 0x03, 0x21, 0xBB, 0xF0, 0x01, 0xFB, 0x2C, 0x60, 0x00, 0x24, 0x2C, 0x72, 0x40, 0x20
    bl __builtin_new
    .byte 0x02, 0x21, 0x00, 0x91, 0x03, 0x21, 0x01, 0x91, 0x02, 0xA9, 0x0C, 0x70, 0x31, 0x1C
    .byte 0x11, 0x4A, 0x43, 0x46
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x04, 0x1C, 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0
    .byte 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xBB, 0xF0, 0xE4, 0xFA
    .byte 0x2C, 0x60, 0x24, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00, 0xC8, 0x10, 0x00, 0x00
    .byte 0xCC, 0x1C, 0x00, 0x00, 0xC9, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x4C, 0x21, 0x00, 0x00
    .byte 0xFF, 0x03, 0x00, 0x00, 0x2C, 0x10, 0x00, 0x00, 0xA9, 0x01, 0x00, 0x00
    .Lauto_08017B30:
    ldr r0, [r4]
    b .Lauto_08017A52
    .Lauto_08017B34:
    mov r3, r8
    ldr r0, [r3]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r0, r1
    add r1, sp, #0x10
    ldr r2, [pc, #0x98]
    movs r3, #0
    str r2, [sp, #0x10]
    str r3, [r1, #4]
    ldr r3, [r0]
    mov r0, r8
    movs r2, #0
    bl _call_via_r3
    .Lauto_08017B52:
    mov r2, r8
    ldr r0, [r2]
    ldr r2, [r0, #0x40]
    mov r0, r8
    movs r1, #0
    bl _call_via_r2
    adds r6, r0, #0
    mov r3, r8
    ldr r0, [r3, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r1, [r1]
    ldr r1, [r1, #0xc]
    bl _call_via_r1
    mov r1, r8
    ldr r0, [r1, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    mov sl, r0
    mov r2, r8
    ldr r0, [r2, #4]
    ldr r0, [r0]
    str r0, [sp, #0x30]
    movs r3, #0
    str r3, [sp, #0x34]
    ldr r0, [pc, #0x50]
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08017B9A
    b .Lauto_08017D96
    .Lauto_08017B9A:
    ldr r0, [pc, #0x48]
    add r0, r8
    ldr r0, [r0]
    ldr r1, [pc, #0x44]
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08017BAC
    b .Lauto_08017D96
    .Lauto_08017BAC:
    mov r2, sl
    cmp r2, #0
    beq .Lauto_08017BB4
    b .Lauto_08017D96
    .Lauto_08017BB4:
    ldr r0, [r6, #0x14]
    adds r0, #0x98
    ldr r1, [r0]
    adds r0, r6, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_08017BC8
    b .Lauto_08017D96
    .Lauto_08017BC8:
    movs r5, #0x82
    lsls r5, r5, #5
    add r5, r8
    ldrb r0, [r5, #4]
    adds r0, #1
    cmp r0, #0x19
    bhs .Lauto_08017BEC
    strb r0, [r5, #4]
    movs r0, #0
    b .Lauto_08017CC2
    .byte 0x3B, 0x02, 0x00, 0x00, 0x3C, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xC4, 0x34, 0x00, 0x00
    .Lauto_08017BEC:
    mov r3, sl
    strb r3, [r5, #4]
    ldr r4, [r5]
    ldr r1, [r4]
    lsls r1, r1, #5
    lsrs r1, r1, #0x1a
    adds r1, #1
    movs r2, #0x3f
    ands r2, r1
    lsls r2, r2, #5
    ldrh r3, [r4, #2]
    ldr r7, [pc, #0x110]
    adds r0, r7, #0
    ands r0, r3
    orrs r0, r2
    strh r0, [r4, #2]
    movs r0, #0x3f
    ands r1, r0
    cmp r1, #0x3b
    bls .Lauto_08017CC0
    ldr r2, [r5]
    ldrh r1, [r2, #2]
    adds r0, r7, #0
    ands r0, r1
    strh r0, [r2, #2]
    ldr r2, [r5]
    .byte 0x11, 0x68, 0xC9, 0x02, 0xC9, 0x0E, 0x01, 0x31, 0x1F, 0x27, 0x39, 0x40, 0x93, 0x78, 0x20, 0x24
    .byte 0x64, 0x42, 0x20, 0x1C, 0x18, 0x40, 0x08, 0x43, 0x90, 0x70, 0x17, 0x29, 0x40, 0xD9, 0x2A, 0x68
    .byte 0x91, 0x78, 0x20, 0x1C, 0x08, 0x40, 0x90, 0x70, 0x2C, 0x68, 0x63, 0x78, 0x58, 0x06, 0xC0, 0x0E
    .byte 0x01, 0x30, 0x1E, 0x28, 0x0A, 0xD1, 0x98, 0x07, 0x80, 0x0F, 0x04, 0x21, 0x49, 0x42, 0x01, 0x30
    .byte 0x03, 0x22, 0x10, 0x40, 0x19, 0x40, 0x01, 0x43, 0x61, 0x70, 0x00, 0x20, 0x38, 0x40, 0x82, 0x00
    .byte 0x61, 0x78, 0x7D, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43, 0x60, 0x70, 0x2A, 0x68, 0x00, 0x23
    .byte 0x51, 0x78, 0x7F, 0x20, 0x08, 0x40, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x23, 0x00, 0x2B, 0x17, 0xD0
    .byte 0x15, 0x78, 0x68, 0x07, 0x40, 0x0F, 0x43, 0x1C, 0x06, 0x2B, 0x09, 0xD9, 0x00, 0x23, 0xE9, 0x08
    .byte 0x1C, 0x29, 0x05, 0xD8, 0x01, 0x31, 0xC9, 0x00, 0x07, 0x20, 0x28, 0x40, 0x08, 0x43, 0x10, 0x70
    .byte 0x07, 0x20, 0x03, 0x40, 0x11, 0x78, 0x08, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .Lauto_08017CC0:
    movs r0, #1
    .Lauto_08017CC2:
    cmp r0, #0
    beq .Lauto_08017D96
    movs r0, #0x82
    lsls r0, r0, #5
    add r0, r8
    ldr r0, [r0]
    ldr r0, [r0]
    lsls r1, r0, #0xb
    lsrs r5, r1, #0x1b
    lsls r0, r0, #5
    lsrs r4, r0, #0x1a
    cmp r5, #6
    bne .Lauto_08017D1C
    cmp r4, #0
    bne .Lauto_08017D1C
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #0xa
    bl _call_via_r3
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .Lauto_08017D92
    mov r0, r8
    ldr r2, [r0]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r2, r2, r1
    add r1, sp, #0x18
    ldr r0, [pc, #0x14]
    str r0, [sp, #0x18]
    str r4, [r1, #4]
    ldr r3, [r2]
    mov r0, r8
    movs r2, #2
    bl _call_via_r3
    b .Lauto_08017D92
    .byte 0x00, 0x00, 0x1F, 0xF8, 0xFF, 0xFF, 0xD5, 0x03, 0x00, 0x00
    .Lauto_08017D1C:
    mov r0, r8
    adds r1, r5, #0
    adds r2, r4, #0
    movs r3, #0
    bl UpdateWorldTimeOfDayPalettes
    cmp r5, #0x14
    bne .Lauto_08017D4C
    cmp r4, #0
    bne .Lauto_08017D4C
    ldr r0, [pc, #0x14]
    add r0, r8
    ldr r0, [r0]
    movs r1, #0
    movs r2, #0x9e
    bl PlaySong__9GameSceneiUi
    mov r0, r8
    bl UpdateWorldBackgroundAudio
    b .Lauto_08017D92
    .byte 0x00, 0x00, 0x54, 0x10, 0x00, 0x00
    .Lauto_08017D4C:
    cmp r5, #0
    bne .Lauto_08017D64
    cmp r4, #0
    bne .Lauto_08017D64
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #3
    bl _call_via_r3
    b .Lauto_08017D92
    .Lauto_08017D64:
    cmp r5, #2
    bne .Lauto_08017D7C
    cmp r4, #0
    bne .Lauto_08017D7C
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #4
    bl _call_via_r3
    b .Lauto_08017D92
    .Lauto_08017D7C:
    cmp r5, #4
    bne .Lauto_08017D92
    cmp r4, #0
    bne .Lauto_08017D92
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #5
    bl _call_via_r3
    .Lauto_08017D92:
    movs r2, #1
    str r2, [sp, #0x34]
    .Lauto_08017D96:
    mov r5, r8
    adds r5, #8
    movs r7, #0xcc
    lsls r7, r7, #1
    add r7, r8
    ldr r3, [sp, #0x28]
    ldr r0, [r3]
    str r0, [sp, #0x20]
    add r0, sp, #0x34
    ldrb r1, [r0]
    mov r0, sb
    strb r1, [r0, #4]
    cmp r5, r7
    beq .Lauto_08017DF8
    .Lauto_08017DB2:
    ldr r4, [r5]
    adds r6, r4, #0
    cmp r4, #0
    beq .Lauto_08017DF2
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_08017DD8
    ldr r0, [r4, #0x14]
    ldr r2, [r0, #0x2c]
    adds r0, r4, #0
    mov r1, sb
    bl _call_via_r2
    b .Lauto_08017DF2
    .Lauto_08017DD8:
    mov r1, sl
    cmp r1, #0
    beq .Lauto_08017DE6
    ldr r2, [sp, #0x30]
    ldrh r4, [r4, #4]
    cmp r2, r4
    bne .Lauto_08017DF2
    .Lauto_08017DE6:
    ldr r0, [r6, #0x14]
    ldr r2, [r0, #0x18]
    adds r0, r6, #0
    mov r1, sb
    bl _call_via_r2
    .Lauto_08017DF2:
    adds r5, #4
    cmp r5, r7
    bne .Lauto_08017DB2
    .Lauto_08017DF8:
    ldr r0, [pc, #0x44]
    add r0, r8
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_08017E06
    bl UpdateParticles__22GameSceneWeatherEffect
    .Lauto_08017E06:
    ldr r0, [pc, #0x3c]
    add r0, r8
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_08017E14
    bl func_080AADB8
    .Lauto_08017E14:
    movs r6, #0
    ldr r5, [pc, #0x30]
    add r5, r8
    .Lauto_08017E1A:
    ldr r4, [r5]
    cmp r4, #0
    beq .Lauto_08017E50
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08017E4C
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08017E50
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08017E4E
    .byte 0x7C, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x6C, 0x10, 0x00, 0x00
    .Lauto_08017E4C:
    movs r0, #0
    .Lauto_08017E4E:
    strb r0, [r1]
    .Lauto_08017E50:
    adds r5, #4
    adds r6, #1
    cmp r6, #1
    bls .Lauto_08017E1A
    movs r6, #0
    ldr r5, [pc, #0x28]
    add r5, r8
    .Lauto_08017E5E:
    ldr r4, [r5]
    cmp r4, #0
    beq .Lauto_08017E8C
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08017E88
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08017E8C
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08017E8A
    .byte 0x74, 0x10, 0x00, 0x00
    .Lauto_08017E88:
    movs r0, #0
    .Lauto_08017E8A:
    strb r0, [r1]
    .Lauto_08017E8C:
    adds r5, #4
    adds r6, #1
    cmp r6, #1
    bls .Lauto_08017E5E
    movs r3, #0
    mov sl, r3
    ldr r0, [pc, #0x28]
    add r0, r8
    mov sb, r0
    movs r6, #0x84
    lsls r6, r6, #5
    add r6, r8
    .byte 0x71, 0x78, 0x88, 0x07, 0x87, 0x0F, 0x01, 0x2F, 0x00, 0xD0, 0x8E, 0xE0, 0x08, 0x07, 0x85, 0x0F
    .byte 0x01, 0x2D, 0x3F, 0xD0, 0x01, 0x2D, 0x05, 0xDC, 0x00, 0x2D, 0x06, 0xD0, 0x85, 0xE0, 0x00, 0x00
    .byte 0x88, 0x10, 0x00, 0x00, 0x02, 0x2D, 0x53, 0xD0, 0x7F, 0xE0, 0xB4, 0x68, 0x21, 0x1C, 0x3F, 0x31
    .byte 0x08, 0x78, 0x00, 0x28, 0x0C, 0xD1, 0x20, 0x1C, 0x28, 0x30
    bl UpdateIndexedResourceHandle
    .byte 0x01, 0x1C
    .byte 0x88, 0x07, 0x00, 0x28, 0x02, 0xDA, 0x20, 0x1C, 0x3C, 0x30, 0x07, 0x70, 0x08, 0x1C, 0x01, 0xE0
    .byte 0x0D, 0x70, 0x02, 0x20, 0x40, 0x07, 0x00, 0x28, 0x67, 0xDA, 0x71, 0x78, 0x0D, 0x22, 0x52, 0x42
    .byte 0x10, 0x1C, 0x01, 0x40, 0x04, 0x20, 0x01, 0x43, 0x71, 0x70, 0xB4, 0x68, 0x20, 0x1C, 0x28, 0x30
    .byte 0x07, 0x49
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x3C, 0x30, 0x00, 0x22, 0x01, 0x21, 0x01, 0x70
    .byte 0x02, 0x30, 0x02, 0x70, 0x01, 0x30, 0x01, 0x70, 0x78, 0x20, 0x30, 0x70, 0x4D, 0xE0, 0x00, 0x00
    .byte 0x6B, 0x08, 0x00, 0x00, 0x30, 0x78, 0x01, 0x38, 0x30, 0x70, 0x00, 0x06, 0x07, 0x0E, 0x00, 0x2F
    .byte 0x43, 0xD1, 0x0D, 0x23, 0x5B, 0x42, 0x18, 0x1C, 0x08, 0x40, 0x08, 0x21, 0x08, 0x43, 0x70, 0x70
    .byte 0xB4, 0x68, 0x20, 0x1C, 0x28, 0x30, 0x05, 0x49
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x3C, 0x30
    .byte 0x05, 0x70, 0x02, 0x30, 0x07, 0x70, 0x01, 0x30, 0x05, 0x70, 0x2E, 0xE0, 0x73, 0x08, 0x00, 0x00
    .byte 0xB4, 0x68, 0x21, 0x1C, 0x3F, 0x31, 0x08, 0x78, 0x00, 0x28, 0x0C, 0xD1, 0x20, 0x1C, 0x28, 0x30
    bl UpdateIndexedResourceHandle
    .byte 0x01, 0x1C, 0x88, 0x07, 0x00, 0x28, 0x02, 0xDA, 0x20, 0x1C, 0x3C, 0x30
    .byte 0x07, 0x70, 0x08, 0x1C, 0x02, 0xE0, 0x00, 0x20, 0x08, 0x70, 0x02, 0x20, 0x40, 0x07, 0x00, 0x28
    .byte 0x13, 0xDA, 0x70, 0x78, 0x04, 0x22, 0x52, 0x42, 0x11, 0x1C, 0x08, 0x40, 0x70, 0x70, 0x4C, 0x46
    .byte 0x00, 0x25, 0xB1, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xBB, 0xF0, 0x80, 0xF8, 0x25, 0x60, 0x0C, 0x23, 0x99, 0x44, 0x0C, 0x36
    .byte 0x01, 0x20, 0x82, 0x44, 0x51, 0x46, 0x03, 0x29, 0x00, 0xD8, 0x61, 0xE7, 0x19, 0x48, 0x40, 0x44
    .byte 0x00, 0x78, 0x00, 0x28, 0x08, 0xD1, 0x43, 0x46, 0x9A, 0x68, 0x58, 0x68, 0x0A, 0x23, 0xD1, 0x5E
    .byte 0x0E, 0x23, 0xD2, 0x5E
    bl SetWorldMapCameraPosition
    .byte 0x13, 0x4C, 0x44, 0x44, 0x20, 0x68, 0x13, 0x49
    .byte 0x40, 0x18, 0xF6, 0xF7, 0x69, 0xFA, 0x0B, 0x9A, 0x90, 0x42, 0x12, 0xD0, 0x10, 0x48, 0x40, 0x44
    .byte 0x00, 0x68
    bl IsBackgroundMusicActive__9GameScene
    .byte 0x00, 0x06, 0x00, 0x28, 0x0A, 0xD0, 0x20, 0x68, 0x0D, 0x4B
    .byte 0xC0, 0x18
    bl HasRegisteredEvents__C14GameEventState
    .byte 0x00, 0x06, 0x00, 0x28, 0x02, 0xD1, 0x40, 0x46
    bl UpdateWorldBackgroundAudio
    .byte 0x0F, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC
    .byte 0x00, 0x47, 0x00, 0x00, 0x3C, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .byte 0x54, 0x10, 0x00, 0x00, 0x4C, 0x21, 0x00, 0x00
    .global func_080182C8
    .thumb_func
func_080182C8:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [pc, #0x210]
    add sp, r4
    mov sb, r0
    ldr r0, [pc, #0x20c]
    add r0, sp
    str r1, [r0]
    movs r0, #0
    ldr r1, [pc, #0x208]
    add r1, sp
    str r0, [r1]
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    movs r2, #0x20
    ldr r0, [pc, #0x1fc]
    add r0, sp
    ldr r0, [r0]
    .Lauto_08018088:
    strb r0, [r1]
    subs r2, #1
    adds r1, #1
    cmp r2, #0
    bgt .Lauto_08018088
    ldr r0, [pc, #0x1f0]
    add r0, sb
    ldr r2, [r0]
    ldr r3, [pc, #0x1e0]
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r4, r2, #0
    adds r4, #0x9c
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_080180B4
    adds r0, r2, #0
    bl PrepareResources__22EntityAuxiliarySpritesR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
    .Lauto_080180B4:
    ldr r0, [pc, #0x1d0]
    add r0, sb
    ldr r2, [r0]
    cmp r2, #0
    beq .Lauto_080180DA
    ldr r4, [pc, #0x1bc]
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4]
    adds r4, r2, #0
    adds r4, #0xe5
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_080180DA
    adds r0, r2, #0
    bl func_0803AEBC
    movs r0, #0
    strb r0, [r4]
    .Lauto_080180DA:
    mov r5, sb
    ldr r0, [r5, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r4, [r1]
    ldr r6, [pc, #0x194]
    add r6, sp
    ldr r6, [r6]
    ldr r1, [r6]
    ldr r2, [r6, #4]
    ldr r3, [r6, #0xc]
    ldr r4, [r4, #0x10]
    bl _call_via_r4
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    movs r2, #0xdb
    lsls r2, r2, #4
    add r2, sb
    ldrb r0, [r2]
    ldr r1, [pc, #0x184]
    add r1, sb
    strb r0, [r1]
    movs r3, #0
    ldr r6, [pc, #0x180]
    add r6, sp
    str r2, [r6]
    movs r0, #0xcc
    lsls r0, r0, #4
    add r0, sp
    str r1, [r0]
    ldrb r1, [r1]
    cmp r3, r1
    bhs .Lauto_08018152
    movs r5, #0xde
    lsls r5, r5, #1
    add r5, sb
    ldr r2, [pc, #0x16c]
    add r2, sb
    .Lauto_0801812A:
    ldrb r0, [r2]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .Lauto_08018144
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r1, r0, #5
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r1, r5, r1
    adds r1, #0x80
    movs r0, #0xff
    strb r0, [r1]
    .Lauto_08018144:
    adds r2, #0xc
    adds r3, #1
    ldr r6, [pc, #0x14c]
    adds r0, r4, r6
    ldrb r0, [r0]
    cmp r3, r0
    blo .Lauto_0801812A
    .Lauto_08018152:
    ldr r1, [pc, #0x148]
    adds r0, r4, r1
    movs r2, #0
    strb r2, [r0]
    ldr r3, [pc, #0x120]
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3, #8]
    ldrb r1, [r0]
    movs r0, #0x7c
    subs r0, r0, r1
    movs r4, #0xc7
    lsls r4, r4, #4
    add r4, sp
    str r0, [r4]
    cmp r0, #0x80
    bls .Lauto_08018178
    bl loc_08019604
    .Lauto_08018178:
    add r0, sp, #0x14
    strb r2, [r0]
    add r0, sp, #0x18
    movs r1, #3
    mov r5, sb
    ldr r4, [r5]
    mov r6, sb
    adds r6, #8
    ldr r2, [pc, #0x114]
    add r2, sp
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r5, #0xcc
    lsls r5, r5, #1
    add r5, sb
    ldr r2, [pc, #0x108]
    add r2, sp
    str r5, [r2]
    ldr r3, [pc, #0x104]
    add r3, sp
    ldr r5, [pc, #0x104]
    add r5, sp
    str r3, [r5]
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
    .Lauto_080181B0:
    str r3, [r0]
    movs r5, #0x81
    lsls r5, r5, #2
    adds r0, r0, r5
    subs r1, #1
    cmp r1, r2
    bne .Lauto_080181B0
    ldr r1, [r4, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldr r5, [pc, #0xd8]
    add r5, sp
    ldr r2, [pc, #0xa0]
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    ldr r2, [r2, #4]
    str r1, [r5]
    str r2, [r5, #4]
    add r1, sp, #0x14
    str r1, [r5, #8]
    strh r4, [r5, #0xc]
    strh r0, [r5, #0xe]
    ldr r2, [pc, #0xc4]
    add r2, sp
    str r6, [r2]
    ldr r3, [pc, #0xc0]
    add r3, sp
    str r6, [r3]
    ldr r4, [r2]
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_0801820E
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #0x1c]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r2
    .Lauto_0801820E:
    ldr r0, [pc, #0x78]
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_0801821E
    add r1, sp, #0x14
    bl Draw__22GameSceneWeatherEffectP21WorldSpriteDrawBuffer
    .Lauto_0801821E:
    ldr r0, [pc, #0x9c]
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .Lauto_08018230
    ldr r2, [r5]
    add r1, sp, #0x14
    bl func_080AAE48
    .Lauto_08018230:
    ldr r1, [r5]
    ldr r2, [r5, #8]
    ldr r0, [pc, #0x68]
    add r0, sp
    str r1, [r0]
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    str r2, [r5, #4]
    ldr r0, [pc, #0x78]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_08018250
    b .Lauto_08018612
    .Lauto_08018250:
    movs r5, #0
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_080182C4
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    .byte 0x02, 0x1C, 0x90, 0x07, 0x00, 0x28, 0x03, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70
    .byte 0x10, 0x1C, 0x28, 0xE0, 0x20, 0xF3, 0xFF, 0xFF, 0x6C, 0x0C, 0x00, 0x00, 0x58, 0x0C, 0x00, 0x00
    .byte 0x24, 0x10, 0x00, 0x00, 0x7C, 0x10, 0x00, 0x00, 0xB1, 0x0D, 0x00, 0x00, 0xBC, 0x0C, 0x00, 0x00
    .byte 0x1D, 0x0D, 0x00, 0x00, 0x15, 0x0C, 0x00, 0x00, 0x14, 0x0C, 0x00, 0x00, 0x5C, 0x0C, 0x00, 0x00
    .byte 0xC4, 0x0C, 0x00, 0x00, 0x28, 0x08, 0x00, 0x00, 0xC8, 0x0C, 0x00, 0x00, 0x28, 0x0C, 0x00, 0x00
    .byte 0x98, 0x0C, 0x00, 0x00, 0x74, 0x0C, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .Lauto_080182C4:
    movs r0, #0
    strb r0, [r1]
    .byte 0x02, 0x20, 0x40, 0x07, 0x00, 0x28, 0x06, 0xDA, 0x83, 0x20, 0x40, 0x01, 0x48, 0x44, 0x00, 0x78
    .byte 0x00, 0x28, 0x00, 0xD0, 0x01, 0x25, 0x00, 0x2D, 0x14, 0xD0, 0x83, 0x20, 0x40, 0x01, 0x48, 0x44
    .byte 0x00, 0x24, 0x04, 0x70, 0x0F, 0x48, 0x48, 0x44, 0x05, 0x68, 0x28, 0x1C, 0x28, 0x30, 0x01, 0x21
    bl ResolveIndexedResourceHandle
    .byte 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x30, 0x04, 0x70
    .byte 0x01, 0x30, 0x01, 0x70, 0x4E, 0x46, 0x30, 0x68, 0x41, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xD8, 0xFE
    .byte 0x0A, 0x38, 0x1D, 0x28, 0x00, 0xD9, 0x78, 0xE1, 0x80, 0x00, 0x03, 0x49, 0x40, 0x18, 0x00, 0x68
    .byte 0x87, 0x46, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x34, 0x83, 0x01, 0x08, 0x04, 0x85, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x76, 0x84, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x20, 0x85, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0xAC, 0x83, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08, 0x12, 0x86, 0x01, 0x08
    .byte 0xE8, 0x84, 0x01, 0x08, 0x21, 0x48, 0x48, 0x44, 0x05, 0x68, 0x49, 0x46, 0x08, 0x68, 0x81, 0x69
    .byte 0x48, 0x46, 0xBA, 0xF0, 0x85, 0xFE, 0x30, 0x24, 0x20, 0x1A, 0x80, 0x46, 0x4A, 0x46, 0x10, 0x68
    .byte 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0x7C, 0xFE, 0x27, 0x1A, 0xCB, 0x23, 0x1B, 0x01, 0x6B, 0x44
    .byte 0x1B, 0x68, 0x9A, 0x46, 0x16, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00
    .byte 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xBA, 0xF0, 0x6D, 0xFE, 0x26, 0x1C
    .byte 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68
    .byte 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x19, 0xDA, 0xA9, 0x89, 0x2A, 0x1C, 0x10, 0x32, 0x09, 0x48
    .byte 0x00, 0x90, 0x01, 0x96, 0x02, 0x93, 0x03, 0x91, 0x04, 0x92, 0x20, 0x1C, 0x41, 0x46, 0x3A, 0x1C
    .byte 0xFF, 0x23, 0x05, 0x4C, 0xBA, 0xF0, 0x52, 0xFE, 0x09, 0xE0, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28
    .byte 0x00, 0xD1, 0xE2, 0xE0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x07, 0x1C, 0x00, 0x29, 0x00, 0xD1
    .byte 0xDB, 0xE0, 0x52, 0x46, 0x11, 0x68, 0x32, 0x1C, 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x00, 0xD0, 0xB8, 0xE0, 0xBE, 0xE0, 0x1A, 0x48
    .byte 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0x20, 0xFE
    .byte 0x68, 0x21, 0x09, 0x1A, 0x88, 0x46, 0x4D, 0x46, 0x28, 0x68, 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0
    .byte 0x17, 0xFE, 0x30, 0x21, 0x0F, 0x1A, 0x25, 0x1C, 0xCB, 0x26, 0x36, 0x01, 0x6E, 0x44, 0x36, 0x68
    .byte 0xB2, 0x46, 0x0E, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A
    .byte 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xBA, 0xF0, 0x06, 0xFE, 0x26, 0x1C, 0xCB, 0x20
    .byte 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68, 0x48, 0x42
    .byte 0x08, 0x43, 0x00, 0x28, 0x98, 0xDB, 0xB1, 0xE7, 0x5C, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .byte 0x05, 0x48, 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0
    .byte 0xE7, 0xFD, 0x18, 0x21, 0xC5, 0xE7, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x05, 0x48, 0x48, 0x44
    .byte 0x04, 0x68, 0x4B, 0x46, 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xD9, 0xFD, 0x38, 0x21
    .byte 0xB7, 0xE7, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x22, 0x48, 0x48, 0x44, 0x04, 0x68, 0x4B, 0x46
    .byte 0x18, 0x68, 0x81, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xCB, 0xFD, 0x68, 0x21, 0x09, 0x1A, 0x88, 0x46
    .byte 0x4D, 0x46, 0x28, 0x68, 0xC1, 0x69, 0x48, 0x46, 0xBA, 0xF0, 0xC2, 0xFD, 0x30, 0x21, 0x0F, 0x1A
    .byte 0x25, 0x1C, 0xCB, 0x26, 0x36, 0x01, 0x6E, 0x44, 0x36, 0x68, 0xB2, 0x46, 0x16, 0x4C, 0x6C, 0x44
    .byte 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C
    .byte 0x1B, 0x69, 0xBA, 0xF0, 0xB1, 0xFD, 0x26, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68
    .byte 0x44, 0x68, 0x28, 0x1C, 0x08, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x19, 0xDA
    .byte 0xA9, 0x89, 0x2A, 0x1C, 0x10, 0x32, 0x09, 0x48, 0x00, 0x90, 0x01, 0x96, 0x02, 0x93, 0x03, 0x91
    .byte 0x04, 0x92, 0x20, 0x1C, 0x41, 0x46, 0x3A, 0x1C, 0xFF, 0x23, 0x05, 0x4C, 0xBA, 0xF0, 0x96, 0xFD
    .byte 0x09, 0xE0, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x27, 0xD0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78
    .byte 0x07, 0x1C, 0x00, 0x29, 0x21, 0xD0, 0x52, 0x46, 0x11, 0x68, 0x32, 0x1C, 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x06, 0xD0, 0x31, 0x1C
    .byte 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0C, 0xE0, 0x2C, 0x1C, 0x3E, 0x34
    .byte 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x31, 0x1C, 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x38, 0x70
    .Lauto_08018612:
    ldr r0, [pc, #0x2c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_0801861E
    b .Lauto_0801873A
    .Lauto_0801861E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08018644
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08018648
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08018646
    .byte 0x00, 0x00, 0x64, 0x10, 0x00, 0x00
    .Lauto_08018644:
    movs r0, #0
    .Lauto_08018646:
    strb r0, [r1]
    .Lauto_08018648:
    ldr r0, [pc, #0x88]
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x58
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x10
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x58]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_080186E4
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b .Lauto_080186E6
    .byte 0x00, 0x00, 0x64, 0x10, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_080186E4:
    movs r0, #0
    .Lauto_080186E6:
    cmp r0, #0
    beq .Lauto_0801873A
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_0801873A
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_0801871C
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018736
    .Lauto_0801871C:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018736
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018736:
    movs r0, #0
    strb r0, [r7]
    .Lauto_0801873A:
    movs r3, #0
    ldr r4, [pc, #0xb0]
    add r4, sp
    str r3, [r4]
    movs r5, #0xde
    lsls r5, r5, #2
    movs r6, #0xcd
    lsls r6, r6, #4
    add r6, sp
    str r5, [r6]
    ldr r0, [pc, #0xa4]
    add r0, sb
    ldr r1, [pc, #0xa4]
    add r1, sp
    str r0, [r1]
    .Lauto_08018758:
    ldr r2, [pc, #0x9c]
    add r2, sp
    ldr r2, [r2]
    ldr r4, [r2]
    cmp r4, #0
    beq .Lauto_0801885E
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r5, #0xcd
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    subs r0, r5, r0
    mov r8, r0
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xf0
    lsls r1, r1, #1
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, [pc, #0x60]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018808
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    ldr r4, [pc, #0x28]
    str r4, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x18]
    bl _call_via_r4
    b .Lauto_0801880A
    .byte 0x78, 0x0C, 0x00, 0x00, 0x6C, 0x10, 0x00, 0x00, 0xD4, 0x0C, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .byte 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018808:
    movs r0, #0
    .Lauto_0801880A:
    cmp r0, #0
    beq .Lauto_0801885E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_0801885E
    mov r0, sl
    ldr r1, [r0]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018840
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_0801885A
    .Lauto_08018840:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_0801885A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_0801885A:
    movs r0, #0
    strb r0, [r7]
    .Lauto_0801885E:
    movs r2, #0xcd
    lsls r2, r2, #4
    add r2, sp
    ldr r1, [r2]
    adds r1, #0x28
    str r1, [r2]
    ldr r4, [pc, #0x44]
    add r4, sp
    ldr r3, [r4]
    adds r3, #4
    str r3, [r4]
    ldr r6, [pc, #0x3c]
    add r6, sp
    ldr r5, [r6]
    adds r5, #1
    str r5, [r6]
    cmp r5, #1
    bhi .Lauto_08018884
    b .Lauto_08018758
    .Lauto_08018884:
    ldr r4, [pc, #0x30]
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .Lauto_08018890
    b .Lauto_08018B0A
    .Lauto_08018890:
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #2
    bne .Lauto_080188A2
    b .Lauto_08018A22
    .Lauto_080188A2:
    cmp r0, #2
    bgt .Lauto_080188BC
    cmp r0, #0
    bne .Lauto_080188AC
    b .Lauto_080189FC
    .Lauto_080188AC:
    b .Lauto_08018B0A
    .byte 0x00, 0x00, 0xD4, 0x0C, 0x00, 0x00, 0x78, 0x0C, 0x00, 0x00, 0x74, 0x10, 0x00, 0x00
    .Lauto_080188BC:
    cmp r0, #3
    beq .Lauto_0801898E
    cmp r0, #7
    beq .Lauto_080188C6
    b .Lauto_08018B0A
    .Lauto_080188C6:
    ldr r4, [r4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x86
    subs r7, r1, r0
    adds r5, r4, #0
    movs r4, #0xcb
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    mov sl, r4
    ldr r4, [pc, #0x54]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_0801895C
    .Lauto_0801892C:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x20]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x10]
    bl _call_via_r4
    b .Lauto_0801895E
    .byte 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_0801895C:
    movs r0, #0
    .Lauto_0801895E:
    cmp r0, #0
    bne .Lauto_08018964
    b .Lauto_08018B0A
    .Lauto_08018964:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .Lauto_08018972
    b .Lauto_08018B0A
    .Lauto_08018972:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_0801898C
    b .Lauto_08018ADE
    .Lauto_0801898C:
    b .Lauto_08018AEC
    .Lauto_0801898E:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x9b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x76
    .Lauto_080189B2:
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x34]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .Lauto_0801892C
    b .Lauto_0801895C
    .byte 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .Lauto_080189FC:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xb0
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    b .Lauto_080189B2
    .Lauto_08018A22:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x88
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x54]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018AB4
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x1c]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0xc]
    bl _call_via_r4
    b .Lauto_08018AB6
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018AB4:
    movs r0, #0
    .Lauto_08018AB6:
    cmp r0, #0
    beq .Lauto_08018B0A
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018B0A
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018AEC
    .Lauto_08018ADE:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018B06
    .Lauto_08018AEC:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018B06
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018B06:
    movs r0, #0
    strb r0, [r7]
    .Lauto_08018B0A:
    ldr r0, [pc, #0x8c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    beq .Lauto_08018C02
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r1, [pc, #0x78]
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x13
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018BAC
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b .Lauto_08018BAE
    .byte 0x78, 0x10, 0x00, 0x00, 0x35, 0x02, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018BAC:
    movs r0, #0
    .Lauto_08018BAE:
    cmp r0, #0
    beq .Lauto_08018C02
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018C02
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018BE4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018BFE
    .Lauto_08018BE4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018BFE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .Lauto_08018BFE:
    movs r0, #0
    strb r0, [r7]
    .Lauto_08018C02:
    ldr r0, [pc, #0x2c]
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .Lauto_08018C0E
    b loc_08018E56
    .Lauto_08018C0E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08018C34
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .Lauto_08018C38
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .Lauto_08018C36
    .byte 0x00, 0x00, 0x58, 0x10, 0x00, 0x00
    .Lauto_08018C34:
    movs r0, #0
    .Lauto_08018C36:
    strb r0, [r1]
    .Lauto_08018C38:
    ldr r0, [pc, #0x28]
    add r0, sb
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl GetUpgradeLevel__C9FarmHouse
    adds r5, r0, #0
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .Lauto_08018C68
    cmp r0, #0x27
    bne .Lauto_08018C60
    b loc_08018D5E
    .Lauto_08018C60:
    b loc_08018E56
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_08018C68:
    ldr r0, [pc, #0x94]
    add r0, sb
    ldr r6, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, [pc, #0x88]
    lsls r5, r5, #1
    adds r1, r5, r4
    ldrb r1, [r1]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r4, #1
    adds r5, r5, r4
    ldrb r1, [r5]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge loc_08018D14
    ldrh r1, [r6, #0xc]
    adds r2, r6, #0
    adds r2, #0x10
    ldr r0, [pc, #0x28]
    str r0, [sp]
    str r5, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x18]
    bl _call_via_r4
    b loc_08018D16
    .byte 0x00, 0x00, 0x58, 0x10, 0x00, 0x00
    .4byte gUnk_080F06FD
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .global loc_08018D14
    .thumb_func
    loc_08018D14:
    movs r0, #0
    .global loc_08018D16
    .thumb_func
    loc_08018D16:
    cmp r0, #0
    bne .Lauto_08018D1C
    b loc_08018E56
    .Lauto_08018D1C:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .Lauto_08018D2A
    b loc_08018E56
    .Lauto_08018D2A:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018D4A
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b loc_08018E30
    .Lauto_08018D4A:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_08018D56
    b loc_08018E52
    .Lauto_08018D56:
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b loc_08018E48
    .global loc_08018D5E
    .thumb_func
    loc_08018D5E:
    ldr r0, [pc, #0x8c]
    add r0, sb
    ldr r5, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, [pc, #0x7c]
    ldrb r1, [r4]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldrb r1, [r4, #1]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, [pc, #0x5c]
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r4, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge loc_08018E00
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x24]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #0x14]
    bl _call_via_r4
    b loc_08018E02
    .byte 0x58, 0x10, 0x00, 0x00
    .4byte gUnk_080F06FD
    .byte 0x38, 0x0C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .global loc_08018E00
    .thumb_func
    loc_08018E00:
    movs r0, #0
    .global loc_08018E02
    .thumb_func
    loc_08018E02:
    cmp r0, #0
    beq .Lauto_08018E56
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .Lauto_08018E56
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .Lauto_08018E38
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    .global loc_08018E30
    .thumb_func
    loc_08018E30:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .Lauto_08018E52
    .Lauto_08018E38:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_08018E52
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    .global loc_08018E48
    .thumb_func
    loc_08018E48:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
    .global loc_08018E52
    .thumb_func
    loc_08018E52:
    .Lauto_08018E52:
    movs r0, #0
    strb r0, [r7]
    .global loc_08018E56
    .thumb_func
    loc_08018E56:
    .Lauto_08018E56:
    ldr r4, [pc, #0x3c]
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .Lauto_08018E62
    b .Lauto_08018FC6
    .Lauto_08018E62:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .Lauto_08018E74
    b .Lauto_08018FC6
    .Lauto_08018E74:
    ldr r0, [pc, #0x20]
    add r0, sb
    ldr r0, [r0]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    beq .Lauto_08018EE0
    cmp r0, #1
    blo .Lauto_08018E9C
    cmp r0, #2
    beq .Lauto_08018F20
    b .Lauto_08018FC6
    .byte 0x00, 0x00, 0x68, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_08018E9C:
    ldr r4, [r4]
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xa0
    subs r1, r1, r0
    mov r8, r1
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    adds r6, r5, #0
    adds r6, #0x28
    .Lauto_08018ECE:
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .Lauto_08018F6E
    b .Lauto_08018F98
    .Lauto_08018EE0:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8c
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    b .Lauto_08018ECE
    .Lauto_08018F20:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xac
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .Lauto_08018F98
    .Lauto_08018F6E:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, [pc, #0x18]
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, [pc, #8]
    bl _call_via_r4
    b .Lauto_08018F9A
    .byte 0xFF, 0xFF, 0xFF, 0x01
    .4byte SubmitWorldSpriteRecords
    .Lauto_08018F98:
    movs r0, #0
    .Lauto_08018F9A:
    cmp r0, #0
    beq .Lauto_08018FC6
    adds r4, r5, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .Lauto_08018FC6
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
    .Lauto_08018FC6:
    ldr r1, [pc, #0x40]
    add r1, sb
    ldr r4, [r1]
    rsbs r0, r4, #0
    orrs r0, r4
    cmp r0, #0
    blt .Lauto_08018FD6
    b .Lauto_08019296
    .Lauto_08018FD6:
    adds r5, r1, #0
    ldrb r2, [r5, #8]
    cmp r2, #0
    beq .Lauto_0801903E
    ldrb r0, [r5, #9]
    subs r0, #1
    movs r2, #0
    .byte 0x68, 0x72, 0x00, 0x06, 0x00, 0x28, 0x0F, 0xD1, 0x29, 0x68, 0x8A, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xBA, 0xF0, 0x65, 0xF8, 0x00, 0x20
    .byte 0x28, 0x60, 0x14, 0xE0, 0x2C, 0x10, 0x00, 0x00, 0x2C, 0x68, 0x21, 0x1C, 0x3F, 0x31, 0x08, 0x78
    .byte 0x00, 0x28, 0x0B, 0xD1, 0x20, 0x1C, 0x28, 0x30
    bl UpdateIndexedResourceHandle
    .byte 0x80, 0x07, 0x00, 0x28
    .byte 0x05, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70, 0x00, 0xE0, 0x0A, 0x70, 0xA8, 0x7A
    .byte 0x01, 0x30, 0x07, 0x21, 0x08, 0x40, 0xA8, 0x72, 0x24, 0xE0
    .Lauto_0801903E:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .Lauto_08019064
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    .byte 0x02, 0x1C, 0x90, 0x07, 0x00, 0x28, 0x03, 0xDA, 0x21, 0x1C, 0x3C, 0x31, 0x01, 0x20, 0x08, 0x70
    .byte 0x10, 0x1C, 0x01, 0xE0
    .Lauto_08019064:
    strb r2, [r1]
    movs r0, #2
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .Lauto_08019088
    movs r4, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .Lauto_08019086
    cmp r1, #0
    beq .Lauto_08019086
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_08019086:
    str r4, [r5]
    .Lauto_08019088:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r2, r0, #0
    ldr r1, [pc, #0xa8]
    add r1, sb
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    ldr r0, [pc, #0xa0]
    add r0, sp
    str r6, [r0]
    ldr r5, [r1]
    rsbs r0, r5, #0
    orrs r0, r5
    cmp r0, #0
    blt .Lauto_080190C2
    b .Lauto_08019296
    .Lauto_080190C2:
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne .Lauto_080190CA
    b .Lauto_080191C4
    .Lauto_080190CA:
    ldrb r0, [r1, #0xa]
    cmp r0, #2
    bhi .Lauto_080190D2
    b .Lauto_08019296
    .Lauto_080190D2:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    movs r6, #0xc8
    lsls r6, r6, #4
    add r6, sp
    str r0, [r6]
    movs r0, #6
    ldrsh r1, [r1, r0]
    subs r2, r1, r2
    mov sl, r2
    .byte 0x80, 0x20, 0x00, 0x02, 0x40, 0x1A, 0x80, 0x46, 0x2E, 0x1C, 0x19, 0x4C, 0x6C, 0x44, 0xA9, 0x6A
    .byte 0x0B, 0x68, 0xAA, 0x8E, 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69
    .byte 0xB9, 0xF0, 0xE2, 0xFF, 0x27, 0x1C, 0xCB, 0x21, 0x09, 0x01, 0x69, 0x44, 0x09, 0x68, 0x4B, 0x68
    .byte 0x28, 0x1C, 0x04, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x1C, 0xDA, 0xA8, 0x89
    .byte 0x29, 0x1C, 0x10, 0x31, 0x44, 0x46, 0x00, 0x94, 0x01, 0x97, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91
    .byte 0x18, 0x1C, 0xC8, 0x25, 0x2D, 0x01, 0x6D, 0x44, 0x29, 0x68, 0x52, 0x46, 0xAA, 0x23, 0x05, 0x4C
    .byte 0xB9, 0xF0, 0xC4, 0xFF, 0x09, 0xE0, 0x00, 0x00, 0x2C, 0x10, 0x00, 0x00, 0x7C, 0x0C, 0x00, 0x00
    .byte 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x00, 0xD1, 0x96, 0xE0
    .byte 0x30, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x05, 0x1C, 0x00, 0x29, 0x00, 0xD1, 0x8F, 0xE0, 0x0A, 0x48
    .byte 0x68, 0x44, 0x00, 0x68, 0x01, 0x68, 0x3A, 0x1C, 0x08, 0x32, 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x30, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x08, 0xD0, 0x39, 0x1C, 0x10, 0x31, 0x30, 0x1C
    .byte 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0, 0x7C, 0x0C, 0x00, 0x00, 0x34, 0x1C, 0x3E, 0x34
    .byte 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x39, 0x1C, 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x28, 0x70, 0x68, 0xE0
    .Lauto_080191C4:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    mov sl, r0
    movs r4, #6
    ldrsh r1, [r1, r4]
    subs r2, r1, r2
    mov r8, r2
    .byte 0x80, 0x20, 0x00, 0x02, 0x47, 0x1A, 0x15, 0x4C, 0x6C, 0x44, 0xA9, 0x6A, 0x0B, 0x68, 0xAA, 0x8E
    .byte 0x92, 0x00, 0xE8, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xB9, 0xF0, 0x6E, 0xFF
    .byte 0x26, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x43, 0x68, 0x28, 0x1C, 0x04, 0xC8
    .byte 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x14, 0xDA, 0xA8, 0x89, 0x29, 0x1C, 0x10, 0x31
    .byte 0x00, 0x97, 0x01, 0x96, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x18, 0x1C, 0x51, 0x46, 0x42, 0x46
    .byte 0xAA, 0x23, 0x03, 0x4C, 0xB9, 0xF0, 0x54, 0xFF, 0x05, 0xE0, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x2B, 0xD0, 0x28, 0x1C, 0x3C, 0x30, 0x01, 0x78
    .byte 0x07, 0x1C, 0x00, 0x29, 0x25, 0xD0, 0x0A, 0x4A, 0x6A, 0x44, 0x12, 0x68, 0x11, 0x68, 0x32, 0x1C
    .byte 0x08, 0x32, 0x28, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x28, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28
    .byte 0x08, 0xD0, 0x31, 0x1C, 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0
    .byte 0x7C, 0x0C, 0x00, 0x00, 0x2C, 0x1C, 0x3E, 0x34, 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x31, 0x1C
    .byte 0x10, 0x31, 0x28, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20
    .byte 0x38, 0x70
    .Lauto_08019296:
    movs r3, #0
    ldr r4, [pc, #0xc4]
    add r4, sp
    str r3, [r4]
    ldr r7, [pc, #0xc4]
    add r7, sb
    ldr r5, [pc, #0xc4]
    add r5, sb
    ldr r6, [pc, #0xc4]
    add r6, sp
    str r5, [r6]
    .Lauto_080192AC:
    ldr r1, [pc, #0xbc]
    add r1, sp
    ldr r1, [r1]
    ldrb r0, [r1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .Lauto_080192BE
    b .Lauto_080193E0
    .Lauto_080192BE:
    ldrh r4, [r7]
    lsls r4, r4, #3
    adds r4, #8
    ldrh r5, [r7, #2]
    lsls r5, r5, #3
    adds r5, #8
    ldr r6, [r7, #4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r3, [pc, #0x94]
    add r3, sp
    str r4, [r3]
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r5, r0
    mov sl, r0
    .byte 0x80, 0x20, 0x00, 0x02, 0x40, 0x1B, 0x80, 0x46, 0xCB, 0x25, 0x2D, 0x01, 0x6D, 0x44, 0x2D, 0x68
    .byte 0x1C, 0x48, 0x68, 0x44, 0x05, 0x60, 0x1C, 0x4C, 0x6C, 0x44, 0xB1, 0x6A, 0x0B, 0x68, 0xB2, 0x8E
    .byte 0x92, 0x00, 0xF0, 0x6A, 0x80, 0x18, 0x02, 0x88, 0x20, 0x1C, 0x1B, 0x69, 0xB9, 0xF0, 0xD8, 0xFE
    .byte 0x25, 0x1C, 0xCB, 0x20, 0x00, 0x01, 0x68, 0x44, 0x00, 0x68, 0x43, 0x68, 0x30, 0x1C, 0x04, 0xC8
    .byte 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x22, 0xDA, 0xB0, 0x89, 0x31, 0x1C, 0x10, 0x31
    .byte 0x44, 0x46, 0x00, 0x94, 0x01, 0x95, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x18, 0x1C, 0x08, 0x4A
    .byte 0x6A, 0x44, 0x11, 0x68, 0x52, 0x46, 0xAA, 0x23, 0x08, 0x4C, 0xB9, 0xF0, 0xBB, 0xFE, 0x10, 0xE0
    .byte 0x84, 0x0C, 0x00, 0x00, 0x84, 0x10, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0xCC, 0x0C, 0x00, 0x00
    .byte 0x88, 0x0C, 0x00, 0x00, 0x8C, 0x0C, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x2C, 0xD0, 0x30, 0x1C, 0x3C, 0x30, 0x01, 0x78, 0x80, 0x46, 0x00, 0x29
    .byte 0x26, 0xD0, 0x0A, 0x4B, 0x6B, 0x44, 0x1B, 0x68, 0x19, 0x68, 0x2A, 0x1C, 0x08, 0x32, 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x30, 0x1C, 0x3D, 0x30, 0x00, 0x78, 0x00, 0x28, 0x08, 0xD0, 0x29, 0x1C
    .byte 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x0E, 0xE0, 0x8C, 0x0C, 0x00, 0x00
    .byte 0x34, 0x1C, 0x3E, 0x34, 0x20, 0x78, 0x00, 0x28, 0x07, 0xD1, 0x29, 0x1C, 0x10, 0x31, 0x30, 0x1C
    .byte 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x01, 0x20, 0x20, 0x70, 0x00, 0x20, 0x44, 0x46, 0x20, 0x70
    .Lauto_080193E0:
    adds r7, #0xc
    ldr r6, [pc, #0x108]
    add r6, sp
    ldr r5, [r6]
    adds r5, #0xc
    str r5, [r6]
    ldr r1, [pc, #0x100]
    add r1, sp
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    cmp r0, #3
    bhi .Lauto_080193FC
    b .Lauto_080192AC
    .Lauto_080193FC:
    ldr r0, [pc, #0xf4]
    ldr r0, [r0]
    movs r2, #0
    movs r3, #0xc9
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    ldr r4, [pc, #0xec]
    adds r7, r0, r4
    .Lauto_0801940E:
    ldrb r0, [r7]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .Lauto_0801941A
    b .Lauto_0801953E
    .Lauto_0801941A:
    ldrh r4, [r7, #2]
    lsls r4, r4, #0x16
    lsrs r4, r4, #0x16
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r4, r0
    beq .Lauto_08019432
    b .Lauto_0801953E
    .Lauto_08019432:
    ldrb r1, [r7, #3]
    lsrs r1, r1, #2
    ldrh r4, [r7, #4]
    ldr r0, [pc, #0xc0]
    ands r4, r0
    lsls r4, r4, #6
    orrs r4, r1
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r6, [r7, #4]
    lsls r6, r6, #6
    asrs r6, r6, #0x10
    ldrb r5, [r7]
    lsls r5, r5, #0x1c
    lsrs r5, r5, #0x1e
    ldr r0, [pc, #0xac]
    add r0, sb
    movs r2, #0xc9
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #2
    adds r0, r0, r1
    ldr r0, [r0]
    mov r8, r0
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r1, [pc, #0x90]
    add r1, sp
    str r4, [r1]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r6, r0
    mov ip, r0
    .byte 0x80, 0x20, 0x00, 0x02, 0x80, 0x1B, 0x82, 0x46, 0x46, 0x46, 0xCB, 0x23, 0x1B, 0x01, 0x6B, 0x44
    .byte 0x1B, 0x68, 0x98, 0x46, 0xAB, 0x00, 0x2B, 0x43, 0x28, 0x01, 0x03, 0x43, 0xAD, 0x01, 0x2B, 0x43
    .byte 0x35, 0x1C, 0x28, 0x35, 0x44, 0x46, 0x64, 0x68, 0x15, 0x48, 0x68, 0x44, 0x04, 0x60, 0x30, 0x1C
    .byte 0x04, 0xC8, 0x41, 0x68, 0x48, 0x42, 0x08, 0x43, 0x00, 0x28, 0x25, 0xDA, 0xB0, 0x89, 0x31, 0x1C
    .byte 0x10, 0x31, 0x54, 0x46, 0x00, 0x94, 0x01, 0x95, 0x02, 0x92, 0x03, 0x90, 0x04, 0x91, 0x0C, 0x49
    .byte 0x69, 0x44, 0x08, 0x68, 0x09, 0x4A, 0x6A, 0x44, 0x11, 0x68, 0x62, 0x46, 0x09, 0x4C, 0xB9, 0xF0
    .byte 0xF5, 0xFD, 0x12, 0xE0, 0xCC, 0x0C, 0x00, 0x00, 0x84, 0x0C, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0xDC, 0x04, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00, 0x94, 0x0C, 0x00, 0x00
    .byte 0xD8, 0x0C, 0x00, 0x00
    .4byte SubmitWorldSpriteRecords
    .byte 0x00, 0x20, 0x00, 0x28, 0x13, 0xD0, 0x34, 0x1C
    .byte 0x48, 0x34, 0x20, 0x78, 0x00, 0x28, 0x0E, 0xD0, 0x43, 0x46, 0x19, 0x68, 0x2A, 0x1C, 0x08, 0x32
    .byte 0x30, 0x1C
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    .byte 0x29, 0x1C, 0x10, 0x31, 0x30, 0x1C, 0x01, 0x22
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    .byte 0x00, 0x20, 0x20, 0x70
    .Lauto_0801953E:
    adds r7, #0xc
    movs r5, #0xc9
    lsls r5, r5, #4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    str r4, [r5]
    cmp r4, #6
    bhs .Lauto_08019552
    b .Lauto_0801940E
    .Lauto_08019552:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    ldr r5, [r0]
    cmp r5, #0x64
    blo .Lauto_08019560
    movs r5, #0
    .Lauto_08019560:
    lsls r0, r5, #2
    ldr r1, [pc, #0x24]
    add r1, sp
    ldr r1, [r1]
    adds r6, r1, r0
    ldr r2, [pc, #0x20]
    add r2, sp
    ldr r7, [r2]
    adds r4, r6, #0
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r3, #0xc7
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    cmp r0, r3
    blo .Lauto_08019590
    subs r0, r4, r1
    b .Lauto_080195D6
    .byte 0x00, 0x00, 0x98, 0x0C, 0x00, 0x00, 0xC4, 0x0C, 0x00, 0x00
    .Lauto_08019590:
    ldr r0, [pc, #0x170]
    add r0, sp
    ldr r0, [r0]
    cmp r4, r0
    beq .Lauto_080195AE
    ldr r3, [r4]
    cmp r3, #0
    beq .Lauto_080195AE
    ldr r0, [r3, #0x14]
    ldr r1, [pc, #0x164]
    add r1, sp
    ldr r2, [r0, #0x1c]
    adds r0, r3, #0
    bl _call_via_r2
    .Lauto_080195AE:
    adds r4, #4
    cmp r4, r7
    bne .Lauto_080195BA
    ldr r1, [pc, #0x154]
    add r1, sp
    ldr r4, [r1]
    .Lauto_080195BA:
    cmp r4, r6
    beq .Lauto_080195D8
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r2, #0xc7
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    cmp r0, r2
    blo .Lauto_08019590
    ldr r3, [pc, #0x13c]
    add r3, sp
    ldr r3, [r3]
    subs r0, r4, r3
    .Lauto_080195D6:
    asrs r5, r0, #2
    .Lauto_080195D8:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    str r5, [r0]
    ldr r4, [pc, #0x12c]
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4, #8]
    add r0, sp, #0x14
    bl func_08094A3C
    ldr r5, [pc, #0x124]
    add r5, sp
    ldr r0, [r5]
    add r6, sp, #0x18
    cmp r6, r0
    beq .Lauto_08019604
    adds r1, r6, #0
    .Lauto_080195FC:
    ldr r2, [pc, #0x118]
    adds r0, r0, r2
    cmp r1, r0
    bne .Lauto_080195FC
    .global loc_08019604
    .thumb_func
    loc_08019604:
    .Lauto_08019604:
    mov r3, sb
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #1
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    ldr r5, [pc, #0x100]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0xec]
    add r6, sp
    ldr r6, [r6]
    ldr r7, [r6]
    adds r2, r1, #0
    eors r2, r0
    movs r3, #0xca
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r4, #0
    ldr r5, [pc, #0xe8]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0xe4]
    add r6, sp
    ldr r6, [r6]
    ldrb r6, [r6]
    ldr r0, [pc, #0xe0]
    add r0, sp
    str r6, [r0]
    cmp r4, r6
    blo .Lauto_08019650
    b .Lauto_080198A4
    .Lauto_08019650:
    ldr r1, [pc, #0xc8]
    add r1, sp
    ldr r1, [r1]
    ldr r2, [pc, #0xd4]
    adds r0, r1, r2
    ldr r2, [pc, #0xc4]
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov sl, r0
    ldrb r0, [r0, #9]
    lsrs r0, r0, #7
    adds r2, #1
    ldr r4, [pc, #0xbc]
    add r4, sp
    str r2, [r4]
    cmp r0, #0
    beq .Lauto_0801967C
    b .Lauto_0801988C
    .Lauto_0801967C:
    mov r5, sl
    movs r1, #9
    ldrsb r1, [r5, r1]
    ldr r6, [pc, #0x98]
    add r6, sp
    ldr r2, [r6]
    adds r2, #0x20
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    mov r8, r2
    mov r4, r8
    adds r4, #0x82
    ldrb r0, [r4]
    cmp r0, #0
    bne .Lauto_080196A6
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    beq .Lauto_080196A6
    b .Lauto_0801988C
    .Lauto_080196A6:
    mov r1, r8
    adds r1, #0x60
    movs r0, #0xca
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    cmp r0, #0
    bne .Lauto_080196B8
    mov r1, r8
    .Lauto_080196B8:
    mov r3, sl
    ldrb r2, [r3, #8]
    lsls r2, r2, #5
    ldr r5, [pc, #0x74]
    adds r2, r2, r5
    add r0, sp, #0x14
    movs r3, #0x20
    bl __21DmaTransferDescriptorPCvPvUi
    mov r6, sp
    adds r6, #0x14
    ldr r0, [pc, #0x68]
    add r0, sp
    str r6, [r0]
    ldr r1, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r1, r0
    beq .Lauto_0801973C
    cmp r1, #0
    beq .Lauto_080196EC
    adds r0, r1, #0
    add r1, sp, #0x14
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080196EC:
    ldr r0, [r7, #4]
    adds r0, #0x10
    str r0, [r7, #4]
    mov r8, r4
    ldr r0, [pc, #0x28]
    add r0, sp
    ldr r6, [r0]
    adds r6, #1
    ldr r0, [pc, #0x30]
    add r0, sp
    str r6, [r0]
    b .Lauto_08019872
    .byte 0x74, 0x0C, 0x00, 0x00, 0x28, 0x0C, 0x00, 0x00, 0x98, 0x0C, 0x00, 0x00, 0x6C, 0x0C, 0x00, 0x00
    .byte 0xC8, 0x0C, 0x00, 0x00, 0xFC, 0xFD, 0xFF, 0xFF, 0x9C, 0x0C, 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00
    .byte 0xBC, 0x0C, 0x00, 0x00, 0xA8, 0x0C, 0x00, 0x00, 0x78, 0x0B, 0x00, 0x00, 0xB4, 0x0C, 0x00, 0x00
    .byte 0x00, 0x02, 0x00, 0x05, 0xAC, 0x0C, 0x00, 0x00
    .Lauto_0801973C:
    ldr r2, [pc, #0x40]
    add r2, sp
    str r1, [r2]
    movs r0, #1
    ldr r2, [pc, #0x3c]
    add r2, sp
    str r0, [r2]
    ldr r0, [r7]
    subs r0, r1, r0
    asrs r4, r0, #4
    ldr r0, [pc, #0x34]
    add r0, sp
    str r4, [r0]
    ldr r1, [r2]
    cmp r4, r1
    bhs .Lauto_0801975E
    adds r0, r2, #0
    .Lauto_0801975E:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .Lauto_08019790
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    ldr r5, [pc, #0x1c]
    add r5, sp
    str r4, [r5]
    cmp r0, #0
    bne .Lauto_08019798
    adds r0, r4, #0
    bl RetryMemoryAllocation
    b .Lauto_08019798
    .byte 0xDC, 0x0C, 0x00, 0x00, 0x68, 0x0C, 0x00, 0x00, 0x64, 0x0C, 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00
    .Lauto_08019790:
    movs r0, #0
    ldr r6, [pc, #0x70]
    add r6, sp
    str r0, [r6]
    .Lauto_08019798:
    adds r5, r0, #0
    ldr r0, [pc, #0x6c]
    add r0, sp
    str r5, [r0]
    ldr r2, [r7]
    adds r3, r5, #0
    movs r1, #0x82
    add r8, r1
    ldr r5, [pc, #0x60]
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    ldr r5, [pc, #0x5c]
    add r5, sp
    str r4, [r5]
    ldr r6, [pc, #0x5c]
    add r6, sp
    ldr r6, [r6]
    cmp r2, r6
    beq .Lauto_080197DE
    .Lauto_080197C0:
    cmp r3, #0
    beq .Lauto_080197D0
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080197D0:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, [pc, #0x3c]
    add r0, sp
    ldr r0, [r0]
    cmp r2, r0
    bne .Lauto_080197C0
    .Lauto_080197DE:
    adds r5, r3, #0
    ldr r0, [pc, #0x34]
    add r0, sp
    ldr r0, [r0]
    cmp r0, #1
    bne .Lauto_08019820
    cmp r5, #0
    beq .Lauto_080197FE
    adds r0, r5, #0
    ldr r2, [pc, #0x28]
    add r2, sp
    ldr r1, [r2]
    ldm r1!, {r3, r4, r6}
    stm r0!, {r3, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_080197FE:
    adds r5, #0x10
    b .Lauto_08019846
    .byte 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00, 0xD8, 0x0C, 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00, 0xB4, 0x0C
    .byte 0x00, 0x00, 0xDC, 0x0C, 0x00, 0x00, 0x68, 0x0C, 0x00, 0x00, 0xAC, 0x0C, 0x00, 0x00
    .Lauto_08019820:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .Lauto_08019844
    .Lauto_08019828:
    cmp r2, #0
    beq .Lauto_0801983C
    adds r0, r2, #0
    ldr r4, [pc, #0xd0]
    add r4, sp
    ldr r1, [r4]
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    .Lauto_0801983C:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .Lauto_08019828
    .Lauto_08019844:
    adds r5, r2, #0
    .Lauto_08019846:
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .Lauto_08019856
    .Lauto_08019850:
    adds r1, #0x10
    cmp r1, r2
    bne .Lauto_08019850
    .Lauto_08019856:
    cmp r0, #0
    beq .Lauto_0801985E
    bl free
    .Lauto_0801985E:
    ldr r6, [pc, #0xa4]
    add r6, sp
    ldr r6, [r6]
    ldr r1, [pc, #0xa0]
    add r1, sp
    ldr r1, [r1]
    adds r0, r6, r1
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
    .Lauto_08019872:
    movs r0, #0
    mov r3, r8
    strb r0, [r3]
    mov r4, sl
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    bne .Lauto_0801988C
    .byte 0x60, 0x7A, 0xC0, 0x09, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0xA0, 0x72
    .Lauto_0801988C:
    ldr r5, [pc, #0x7c]
    add r5, sp
    ldr r5, [r5]
    ldr r6, [pc, #0x7c]
    add r6, sp
    str r5, [r6]
    ldr r0, [pc, #0x78]
    add r0, sp
    ldr r6, [r0]
    cmp r5, r6
    bhs .Lauto_080198A4
    b .Lauto_08019650
    .Lauto_080198A4:
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    ldr r3, [pc, #0x6c]
    add r3, sp
    ldr r3, [r3]
    ldrb r2, [r3]
    movs r4, #0xcc
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    ldrb r4, [r4]
    cmp r2, r4
    bhs .Lauto_080198EA
    movs r5, #0xff
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r6, [pc, #0x50]
    adds r0, r0, r6
    adds r3, r0, r1
    ldr r1, [pc, #0x50]
    add r1, sb
    .Lauto_080198D2:
    ldrb r4, [r3]
    lsrs r0, r4, #7
    cmp r0, #0
    bne .Lauto_080198E0
    adds r0, r4, #0
    orrs r0, r5
    strb r0, [r3]
    .Lauto_080198E0:
    adds r3, #0xc
    adds r2, #1
    ldrb r0, [r1]
    cmp r2, r0
    blo .Lauto_080198D2
    .Lauto_080198EA:
    movs r3, #0xce
    lsls r3, r3, #4
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0xAC, 0x0C, 0x00, 0x00, 0xB8, 0x0C, 0x00, 0x00, 0xD8, 0x0C, 0x00, 0x00, 0xB4, 0x0C
    .byte 0x00, 0x00, 0xA4, 0x0C, 0x00, 0x00, 0xA8, 0x0C, 0x00, 0x00, 0xBC, 0x0C, 0x00, 0x00, 0x81, 0x0B
    .byte 0x00, 0x00, 0xB1, 0x0D, 0x00, 0x00
    .section .text.world_after_palette_refresh, "ax", %progbits
    .align 2, 0

    .global func_08019BEC
    .thumb_func
func_08019BEC:
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
    beq .Lauto_080199BA
    .Lauto_080199A4:
    ldr r2, [r4]
    cmp r2, #0
    beq .Lauto_080199B4
    ldr r0, [r2, #0x14]
    ldr r1, [r0, #0x14]
    adds r0, r2, #0
    bl _call_via_r1
    .Lauto_080199B4:
    adds r4, #4
    cmp r4, r5
    bne .Lauto_080199A4
    .Lauto_080199BA:
    ldr r0, [pc, #0x1d0]
    ldr r0, [r0]
    ldr r1, [pc, #0x1d0]
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
    ldr r0, [pc, #0x1bc]
    adds r0, r0, r7
    mov sb, r0
    movs r6, #0
    ldr r1, [pc, #0x1b8]
    adds r4, r7, r1
    .Lauto_080199E0:
    ldr r1, [r4]
    cmp r6, r1
    beq .Lauto_080199F6
    cmp r1, #0
    beq .Lauto_080199F6
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    .Lauto_080199F6:
    stm r4!, {r6}
    adds r5, #1
    cmp r5, #6
    blo .Lauto_080199E0
    mov r2, r8
    .byte 0x10, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x02, 0x28, 0x0D, 0xD0, 0x7A, 0x68, 0x10, 0x68, 0x02, 0x28
    .byte 0x09, 0xD1, 0x62, 0x4B, 0xF8, 0x18, 0x01, 0x68, 0x00, 0x29, 0x04, 0xD0, 0xD0, 0x6A, 0xB0, 0x22
    .byte 0x12, 0x02
    bl CopyHardwareDma3
    .byte 0x78, 0x68, 0x5D, 0x4A, 0xB9, 0x18, 0x0A, 0x68, 0x5D, 0x4B
    .byte 0xF9, 0x18, 0x0B, 0x78, 0x1E, 0x21, 0xC9, 0x1A, 0x00, 0x91, 0x41, 0x46
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    .byte 0x59, 0x48, 0x3C, 0x18, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0
    .byte 0x03, 0x21
    bl _._22EntityAuxiliarySprites
    .byte 0x25, 0x60, 0x4C, 0x46, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42
    .byte 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._22GameSceneWeatherEffect
    .byte 0x25, 0x60, 0x4F, 0x49
    .byte 0x7C, 0x18, 0x00, 0x25, 0x20, 0x68, 0x85, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    .byte 0x91, 0xF0, 0x4C, 0xF9, 0x25, 0x60, 0x00, 0x22, 0x04, 0x92, 0x53, 0x46, 0x08, 0x93, 0x08, 0x99
    .byte 0x08, 0x78, 0x80, 0x07, 0x80, 0x0F, 0x05, 0x90, 0x01, 0x28, 0x47, 0xD1, 0x4C, 0x88, 0xA4, 0x05
    .byte 0xA4, 0x0D, 0x38, 0x68, 0x41, 0x69, 0x38, 0x1C, 0xB9, 0xF0, 0x0E, 0xFB, 0x84, 0x42, 0x3D, 0xD1
    .byte 0x39, 0x4A, 0xD2, 0x19, 0x91, 0x46, 0x04, 0x9B, 0x98, 0x00, 0x81, 0x44, 0x4C, 0x20
    bl __builtin_new
    .byte 0x06, 0x1C, 0x38, 0x68, 0x41, 0x6E, 0x38, 0x1C, 0xB9, 0xF0, 0xFD, 0xFA, 0x05, 0x1C
    .byte 0x08, 0x98, 0x00, 0x89, 0x82, 0x46, 0x30, 0x1C, 0x39, 0x1C, 0x02, 0x22, 0x1B, 0x23
    bl __19GameSceneSpriteBaseP10GameObjectUii
    .byte 0x33, 0x48, 0x70, 0x62, 0x28, 0x21, 0x89, 0x19, 0x88, 0x46, 0x2C, 0x68, 0x01, 0xA8
    .byte 0xE3, 0x68, 0x29, 0x1C, 0x52, 0x46, 0xB9, 0xF0, 0xEB, 0xFA, 0x01, 0x98, 0x02, 0x88, 0x40, 0x46
    .byte 0x23, 0x69, 0x29, 0x1C, 0xB9, 0xF0, 0xE4, 0xFA, 0x30, 0x1C, 0x48, 0x30, 0x6A, 0x46, 0x12, 0x7D
    .byte 0x02, 0x70, 0x4C, 0x46, 0x21, 0x68, 0x8E, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A
    .byte 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB9, 0xF0, 0xD1, 0xFA, 0x26, 0x60, 0x08, 0x9B, 0x0C, 0x33
    .byte 0x08, 0x93, 0x04, 0x98, 0x01, 0x30, 0x04, 0x90, 0x06, 0x28, 0xA8, 0xD3, 0xA0, 0x20
    bl __builtin_new
    .byte 0x39, 0x1C
    bl __22EntityAuxiliarySpritesP10GameObject
    .byte 0x17, 0x49, 0x7D, 0x18, 0x04, 0x1C, 0x28, 0x68
    .byte 0x84, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._22EntityAuxiliarySprites
    .byte 0x2C, 0x60
    .byte 0x78, 0x68, 0x40, 0x68, 0x8A, 0xF0, 0xB4, 0xFA, 0x24, 0x30, 0x00, 0x78, 0x00, 0x28, 0x3A, 0xD1
    .byte 0x78, 0x68, 0x01, 0x68, 0x0F, 0x4A, 0xB8, 0x18, 0x00, 0x68, 0x08, 0x30, 0x2E, 0x29, 0x1F, 0xD0
    .byte 0x2E, 0x29, 0x19, 0xDD, 0x2F, 0x29, 0x1D, 0xD0, 0x1E, 0xE0, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x03
    .byte 0xDC, 0x04, 0x00, 0x00, 0x7C, 0x10, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00, 0x50, 0x10, 0x00, 0x00
    .byte 0x48, 0x10, 0x00, 0x00, 0x4C, 0x10, 0x00, 0x00, 0x24, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .4byte __vt_20GameSceneGroupSprite
    .byte 0x38, 0x10, 0x00, 0x00, 0x2C, 0x29, 0x05, 0xDB, 0x00, 0x20, 0x04, 0xE0
    .byte 0x01, 0x20, 0x02, 0xE0, 0x02, 0x20, 0x00, 0xE0, 0x00, 0x68, 0x01, 0x28, 0x02, 0xD0, 0x02, 0x28
    .byte 0x05, 0xD0, 0x08, 0xE0, 0x38, 0x1C, 0x01, 0x21, 0x05, 0xF0, 0x40, 0xFE, 0x03, 0xE0, 0x38, 0x1C
    .byte 0x00, 0x21, 0x05, 0xF0, 0x3B, 0xFE, 0x04, 0x20
    bl __builtin_new
    .byte 0x79, 0x68, 0x4A, 0x68
    .byte 0x39, 0x1C, 0x90, 0xF0, 0x05, 0xFF, 0x31, 0x4B, 0xFD, 0x18, 0x04, 0x1C, 0x28, 0x68, 0x84, 0x42
    .byte 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21, 0x91, 0xF0, 0x88, 0xF8, 0x2C, 0x60, 0x38, 0x1C
    .byte 0x05, 0xF0, 0x66, 0xF9, 0x38, 0x1C
    bl RefreshWorldVase
    .byte 0x38, 0x1C, 0x05, 0xF0, 0x28, 0xFA
    .byte 0x38, 0x1C
    bl RefreshWorldHillSeasonalSprites
    .byte 0x38, 0x1C
    bl RefreshWorldWinterAndFireplaceSprites
    .byte 0x38, 0x1C, 0x04, 0xF0
    .byte 0xEF, 0xFB, 0x06, 0x9C, 0x07, 0x9D, 0xAC, 0x42, 0x0A, 0xD0, 0x22, 0x68, 0x00, 0x2A, 0x04, 0xD0
    .byte 0x50, 0x69, 0x01, 0x69, 0x10, 0x1C, 0xB9, 0xF0, 0x3F, 0xFA, 0x04, 0x34, 0xAC, 0x42, 0xF4, 0xD1
    .byte 0x03, 0x98, 0x00, 0x28, 0x14, 0xD0, 0x1A, 0x49, 0x78, 0x18, 0x00, 0x68, 0x19, 0x4A, 0x80, 0x18
    bl HasRegisteredEvents__C14GameEventState
    .byte 0x00, 0x06, 0x00, 0x28, 0x07, 0xD0, 0x17, 0x4B, 0xF8, 0x18, 0x00, 0x68
    bl IsBackgroundMusicActive__9GameScene
    .byte 0x00, 0x06, 0x00, 0x28, 0x02, 0xD1, 0x38, 0x1C
    bl UpdateWorldBackgroundAudio
    .byte 0x78, 0x68, 0x40, 0x68, 0x8A, 0xF0, 0x24, 0xFA, 0x24, 0x30, 0x00, 0x78, 0x00, 0x28, 0x0C, 0xD1
    .byte 0x82, 0x21, 0x49, 0x01, 0x78, 0x18, 0x00, 0x68, 0x02, 0x68, 0xD1, 0x02, 0xC9, 0x0E, 0x52, 0x01
    .byte 0x92, 0x0E, 0x38, 0x1C, 0x01, 0x23
    bl UpdateWorldTimeOfDayPalettes
    .byte 0x09, 0xB0, 0x38, 0xBC, 0x98, 0x46
    .byte 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x4C, 0x21, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00

    .section .text.game_scene_after_map_terrain, "ax", %progbits
    .align 2, 0

    .global UpdateWorldTimeOfDayPalettes
    .thumb_func
    UpdateWorldTimeOfDayPalettes:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc4
    str r0, [sp, #0x90]
    adds r4, r1, #0
    .byte 0x17, 0x1C, 0x1B, 0x06, 0x1E, 0x0E
    bl GetWorldTimeOfDayPeriod
    .byte 0x01, 0x1C, 0x24, 0x98, 0x0F, 0x4B
    .byte 0xC2, 0x18, 0x10, 0x68, 0x88, 0x42, 0x06, 0xD1, 0x20, 0x06, 0x2A, 0x90, 0x3B, 0x06, 0x2B, 0x93
    .byte 0x00, 0x2E, 0x00, 0xD1, 0x1E, 0xE3, 0x11, 0x60, 0x24, 0x9E, 0x70, 0x68
    bl SetWorldMapTimeOfDayPalette
    .byte 0x70, 0x68, 0x01, 0x68, 0x06, 0x4A, 0xB0, 0x18, 0x00, 0x68, 0x08, 0x30, 0x2E, 0x29, 0x0D, 0xD0
    .byte 0x2E, 0x29, 0x07, 0xDD, 0x2F, 0x29, 0x0B, 0xD0, 0x0C, 0xE0, 0x00, 0x00, 0x48, 0x10, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x2C, 0x29, 0x05, 0xDB, 0x00, 0x21, 0x04, 0xE0, 0x01, 0x21, 0x02, 0xE0
    .byte 0x02, 0x21, 0x00, 0xE0, 0x01, 0x68, 0xCE, 0x26, 0x76, 0x00, 0x24, 0x9B, 0x9E, 0x19, 0x25, 0x96
    .byte 0x17, 0x4A, 0x98, 0x18, 0x00, 0x68, 0x26, 0x90, 0x27, 0x91, 0x00, 0x23, 0x98, 0x46, 0x24, 0x06
    .byte 0x2A, 0x94, 0x3C, 0x06, 0x2B, 0x94, 0x25, 0x98, 0x20, 0x30, 0x46, 0x46, 0x71, 0x01, 0x41, 0x44
    .byte 0x89, 0x00, 0x45, 0x18, 0x28, 0x1C, 0x83, 0x30, 0x00, 0x78, 0x00, 0x28, 0x1A, 0xD1, 0x29, 0x1C
    .byte 0x20, 0x31, 0x28, 0x1C, 0x1C, 0xC8, 0x1C, 0xC1, 0x4C, 0xC8, 0x4C, 0xC1, 0x50, 0xC8, 0x50, 0xC1
    .byte 0x29, 0x1C, 0x40, 0x31, 0x28, 0x1C, 0x1C, 0xC8, 0x1C, 0xC1, 0x4C, 0xC8, 0x4C, 0xC1, 0x50, 0xC8
    .byte 0x50, 0xC1, 0x29, 0x1C, 0x82, 0x31, 0x01, 0x20, 0x08, 0x70, 0x40, 0x44, 0x81, 0x46, 0xC3, 0xE2
    .byte 0x48, 0x10, 0x00, 0x00, 0x29, 0x1C, 0x82, 0x31, 0x30, 0x91, 0x01, 0x22, 0x42, 0x44, 0x91, 0x46
    .byte 0x27, 0x9B, 0x04, 0x2B, 0x00, 0xD9, 0xB4, 0xE2, 0x98, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68
    .byte 0x87, 0x46, 0x00, 0x00, 0xD8, 0x9F, 0x01, 0x08, 0xEC, 0x9F, 0x01, 0x08, 0x50, 0xA2, 0x01, 0x08
    .byte 0x50, 0xA2, 0x01, 0x08, 0xEC, 0x9F, 0x01, 0x08, 0xEC, 0x9F, 0x01, 0x08, 0x26, 0x9C, 0x01, 0x2C
    .byte 0x00, 0xD1, 0x9F, 0xE0, 0x01, 0x2C, 0x07, 0xDC, 0x00, 0x2C, 0x63, 0xD0, 0x82, 0x35, 0x30, 0x95
    .byte 0x01, 0x26, 0x46, 0x44, 0xB1, 0x46, 0x94, 0xE2, 0x26, 0x98, 0x02, 0x28, 0x00, 0xD1, 0xC3, 0xE0
    .byte 0x29, 0x1C, 0x82, 0x31, 0x30, 0x91, 0x01, 0x22, 0x42, 0x44, 0x91, 0x46, 0x03, 0x28, 0x00, 0xD0
    .byte 0x87, 0xE2, 0x08, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x1E, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80
    .byte 0x28, 0x1C, 0x20, 0x30, 0x1C, 0x4B, 0x09, 0x93, 0x69, 0x46, 0x16, 0x1C, 0x07, 0x1C, 0x0A, 0xAC
    .byte 0xA0, 0x46, 0x0B, 0xAC, 0xA2, 0x46, 0x14, 0x1C, 0xA5, 0x45, 0x04, 0xD0, 0x1C, 0x1C, 0x0C, 0x80
    .byte 0x02, 0x31, 0xB1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x2A, 0x1C, 0x13, 0x4C, 0xB9, 0xF0
    .byte 0x31, 0xF8, 0x09, 0x23, 0x0A, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80
    .byte 0x3C, 0x1C, 0x20, 0x34, 0x43, 0x46, 0x0A, 0x48, 0x0B, 0x90, 0x68, 0x46, 0x08, 0xAA, 0x95, 0x45
    .byte 0x00, 0xD1, 0xE3, 0xE1, 0x56, 0x46, 0x31, 0x68, 0x01, 0x80, 0x02, 0x30, 0x90, 0x42, 0xFB, 0xD1
    .byte 0xDC, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0xAA, 0x1B, 0x00, 0x00, 0x0C, 0xAA, 0x09, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x13, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x2E, 0x1C, 0x20, 0x36, 0x11, 0x48, 0x0D, 0x90, 0x69, 0x46, 0x08, 0xAC, 0x37, 0x1C
    .byte 0x0F, 0x4B, 0x9C, 0x46, 0x2B, 0x1C, 0x82, 0x33, 0x30, 0x93, 0x01, 0x23, 0x43, 0x44, 0x99, 0x46
    .byte 0xA5, 0x45, 0x03, 0xD0, 0x08, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x30, 0x1C
    .byte 0x69, 0x46, 0x2A, 0x1C, 0xB8, 0xF0, 0xEE, 0xFF, 0x38, 0x1C, 0x20, 0x30, 0x29, 0x1C, 0x20, 0x22
    .byte 0xB9, 0xF0, 0x14, 0xF8, 0x05, 0xE2, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0xAA, 0x1B, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x2C, 0x1C, 0x20, 0x34, 0x20, 0x1C, 0x29, 0x1C, 0x20, 0x22, 0xB9, 0xF0
    .byte 0x05, 0xF8, 0x0E, 0xAA, 0x03, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x70, 0xD8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0E, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80
    .byte 0x20, 0x34, 0x13, 0x1C, 0x08, 0x21, 0x4A, 0x01, 0x20, 0x20, 0x02, 0x43, 0x89, 0x02, 0x0A, 0x43
    .byte 0x0F, 0x92, 0x68, 0x46, 0x08, 0xA9, 0x2E, 0x1C, 0x82, 0x36, 0x30, 0x96, 0x01, 0x26, 0x46, 0x44
    .byte 0xB1, 0x46, 0x8D, 0x45, 0x00, 0xD1, 0x71, 0xE1, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1
    .byte 0x6C, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x10, 0xAA, 0x03, 0x23, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xD8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x25, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2E, 0x1C, 0x20, 0x36, 0x13, 0x1C, 0x08, 0x21, 0x4A, 0x01
    .byte 0x20, 0x20, 0x02, 0x43, 0x89, 0x02, 0x0A, 0x43, 0x11, 0x92, 0x6C, 0x46, 0x08, 0xA8, 0x37, 0x1C
    .byte 0x12, 0xA9, 0x8A, 0x46, 0x69, 0x46, 0x4C, 0x31, 0x2C, 0x91, 0x29, 0x1C, 0x82, 0x31, 0x30, 0x91
    .byte 0x01, 0x21, 0x41, 0x44, 0x89, 0x46, 0x85, 0x45, 0x04, 0xD0, 0x11, 0x1C, 0x21, 0x80, 0x02, 0x34
    .byte 0x84, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x30, 0x1C, 0x69, 0x46, 0x2A, 0x1C, 0x12, 0x4C, 0xB8, 0xF0
    .byte 0x69, 0xFF, 0x0A, 0x23, 0x12, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80
    .byte 0x3C, 0x1C, 0x20, 0x34, 0x53, 0x46, 0x09, 0x48, 0x13, 0x90, 0x68, 0x46, 0x08, 0xAA, 0x95, 0x45
    .byte 0x00, 0xD1, 0x1B, 0xE1, 0x2C, 0x9E, 0x31, 0x68, 0x01, 0x80, 0x02, 0x30, 0x90, 0x42, 0xFB, 0xD1
    .byte 0x14, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00
    .byte 0x26, 0x98, 0x01, 0x28, 0x00, 0xD1, 0xBB, 0xE0, 0x01, 0x28, 0x07, 0xDC, 0x00, 0x28, 0x61, 0xD0
    .byte 0x82, 0x35, 0x30, 0x95, 0x01, 0x21, 0x41, 0x44, 0x89, 0x46, 0x62, 0xE1, 0x26, 0x9A, 0x02, 0x2A
    .byte 0x00, 0xD1, 0x09, 0xE1, 0x2B, 0x1C, 0x82, 0x33, 0x30, 0x93, 0x01, 0x24, 0x44, 0x44, 0xA1, 0x46
    .byte 0x03, 0x2A, 0x00, 0xD0, 0x55, 0xE1, 0x14, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x1D, 0x48, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x80, 0x2E, 0x1C, 0x20, 0x36, 0x1B, 0x48, 0x15, 0x90, 0x69, 0x46, 0x08, 0xAC
    .byte 0x37, 0x1C, 0x16, 0xAB, 0x98, 0x46, 0x17, 0xAB, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0, 0x08, 0x80
    .byte 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x30, 0x1C, 0x69, 0x46, 0x2A, 0x1C, 0x13, 0x4C
    .byte 0xB8, 0xF0, 0x00, 0xFF, 0x0A, 0x23, 0x16, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x3C, 0x1C, 0x20, 0x34, 0x43, 0x46, 0x09, 0x48, 0x17, 0x90, 0x68, 0x46, 0x08, 0xAA
    .byte 0x95, 0x45, 0x00, 0xD1, 0xB2, 0xE0, 0x56, 0x46, 0x31, 0x68, 0x01, 0x80, 0x02, 0x30, 0x90, 0x42
    .byte 0xFB, 0xD1, 0xAB, 0xE0, 0x1F, 0xFC, 0xFF, 0xFF, 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x32, 0x6A, 0x00, 0x00, 0x18, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x22, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x20, 0x20, 0x40, 0x19, 0x84, 0x46, 0x1F, 0x4E, 0x19, 0x96, 0x69, 0x46, 0x08, 0xAC
    .byte 0x67, 0x46, 0x1A, 0xAB, 0x9A, 0x46, 0x68, 0x46, 0x6C, 0x30, 0x2D, 0x90, 0x2B, 0x1C, 0x82, 0x33
    .byte 0x30, 0x93, 0x01, 0x20, 0x40, 0x44, 0x81, 0x46, 0xA5, 0x45, 0x04, 0xD0, 0x30, 0x1C, 0x08, 0x80
    .byte 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x60, 0x46, 0x69, 0x46, 0x2A, 0x1C, 0x13, 0x4C
    .byte 0xB8, 0xF0, 0xA8, 0xFE, 0x0A, 0x23, 0x1A, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x3C, 0x1C, 0x20, 0x34, 0x53, 0x46, 0x07, 0x48, 0x1B, 0x90, 0x68, 0x46, 0x08, 0xAA
    .byte 0x95, 0x45, 0x5B, 0xD0, 0x2D, 0x9E, 0x31, 0x68, 0x01, 0x80, 0x02, 0x30, 0x90, 0x42, 0xFB, 0xD1
    .byte 0x54, 0xE0, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x1C, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x25, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x20, 0x20
    .byte 0x40, 0x19, 0x84, 0x46, 0x22, 0x4E, 0x1D, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x67, 0x46, 0x1E, 0xAB
    .byte 0x9A, 0x46, 0x68, 0x46, 0x7C, 0x30, 0x2E, 0x90, 0x2B, 0x1C, 0x82, 0x33, 0x30, 0x93, 0x01, 0x20
    .byte 0x40, 0x44, 0x81, 0x46, 0xA5, 0x45, 0x04, 0xD0, 0x30, 0x1C, 0x08, 0x80, 0x02, 0x31, 0xA1, 0x42
    .byte 0xFB, 0xD1, 0x13, 0x68, 0x60, 0x46, 0x69, 0x46, 0x2A, 0x1C, 0x16, 0x4C, 0xB8, 0xF0, 0x52, 0xFE
    .byte 0x0A, 0x23, 0x1E, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0D, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x3C, 0x1C
    .byte 0x20, 0x34, 0x53, 0x46, 0x0A, 0x48, 0x1F, 0x90, 0x68, 0x46, 0x08, 0xAA, 0x95, 0x45, 0x05, 0xD0
    .byte 0x2E, 0x9E, 0x31, 0x68, 0x01, 0x80, 0x02, 0x30, 0x90, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x20, 0x1C
    .byte 0x69, 0x46, 0x2A, 0x1C, 0x03, 0x4C, 0xB8, 0xF0, 0x2D, 0xFE, 0x5A, 0xE0, 0x1F, 0xFC, 0xFF, 0xFF
    .byte 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x20, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x63, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2E, 0x1C, 0x20, 0x36, 0x61, 0x4C, 0x21, 0xA8, 0x04, 0x60
    .byte 0x68, 0x46, 0x08, 0xA9, 0x37, 0x1C, 0x22, 0xAB, 0x9A, 0x46, 0x6B, 0x46, 0x8C, 0x33, 0x2F, 0x93
    .byte 0x2B, 0x1C, 0x82, 0x33, 0x30, 0x93, 0x01, 0x23, 0x43, 0x44, 0x99, 0x46, 0x8D, 0x45, 0x03, 0xD0
    .byte 0x04, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x30, 0x1C, 0x69, 0x46, 0x2A, 0x1C
    .byte 0x54, 0x4C, 0xB8, 0xF0, 0xF7, 0xFD, 0x0A, 0x23, 0x22, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x4B, 0x48, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x80, 0x3C, 0x1C, 0x20, 0x34, 0x53, 0x46, 0x4B, 0x48, 0x2F, 0x9E, 0x30, 0x60
    .byte 0x68, 0x46, 0x08, 0xAA, 0x23, 0xA9, 0x95, 0x45, 0x04, 0xD0, 0x09, 0x68, 0x01, 0x80, 0x02, 0x30
    .byte 0x90, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x20, 0x1C, 0x69, 0x46, 0x2A, 0x1C, 0x41, 0x4C, 0xB8, 0xF0
    .byte 0xD1, 0xFD, 0x01, 0x20, 0x30, 0x99, 0x08, 0x70, 0xC8, 0x46, 0x42, 0x46, 0x16, 0x2A, 0x00, 0xD2
    .byte 0x11, 0xE5, 0x01, 0x26, 0x2A, 0x9B, 0x1C, 0x0E, 0x2B, 0x98, 0x05, 0x0E, 0x24, 0x99, 0x3B, 0x4A
    .byte 0x88, 0x18, 0x00, 0x68, 0x10, 0x30, 0xF3, 0xF7, 0xD5, 0xFE, 0x02, 0x1C, 0x24, 0x9B, 0x38, 0x49
    .byte 0x58, 0x18, 0x03, 0x68, 0x20, 0x1C, 0x29, 0x1C
    bl GetTimeOfDayTransitionValue
    .byte 0x00, 0x06, 0x01, 0x0E
    .byte 0x24, 0x9A, 0x34, 0x4B, 0xD5, 0x18, 0x28, 0x78, 0x88, 0x42, 0x01, 0xD1, 0x00, 0x2E, 0x4C, 0xD0
    .byte 0x29, 0x70, 0x24, 0x9C, 0x60, 0x68, 0x29, 0x78, 0x1E, 0x24, 0x62, 0x1A
    bl BlendTimeOfDayPalettes__17GameSceneWorldMapUiUi
    .byte 0x29, 0x78, 0x64, 0x1A, 0x00, 0x26, 0xB1, 0x46, 0x1F, 0x20, 0x01, 0x40, 0x29, 0x91, 0x24, 0x98
    .byte 0x29, 0x49, 0x40, 0x18, 0x80, 0x46, 0x24, 0x9A, 0xFE, 0x23, 0x5B, 0x00, 0xD7, 0x18, 0xEE, 0x20
    .byte 0x40, 0x00, 0x16, 0x18, 0x22, 0x39, 0x55, 0x18, 0x1F, 0x20, 0x04, 0x40, 0x64, 0x01, 0xA2, 0x46
    .byte 0x20, 0x22, 0x52, 0x42, 0x11, 0x1C, 0x28, 0x98, 0x08, 0x40, 0x29, 0x9B, 0x18, 0x43, 0x00, 0x06
    .byte 0x00, 0x0E, 0x1E, 0x49, 0x28, 0x9C, 0x0C, 0x40, 0x04, 0x43, 0x28, 0x94, 0x13, 0x48, 0x01, 0x1C
    .byte 0x20, 0x1C, 0x08, 0x40, 0x51, 0x46, 0x08, 0x43, 0x00, 0x04, 0x00, 0x0C, 0x18, 0x49, 0x0C, 0x40
    .byte 0x04, 0x43, 0x28, 0x94, 0x28, 0x1C, 0x31, 0x1C, 0x3A, 0x1C, 0x23, 0x1C, 0x0D, 0x4C, 0xB8, 0xF0
    .byte 0x69, 0xFD, 0x01, 0x20, 0x42, 0x46, 0x10, 0x70, 0x84, 0x23, 0x98, 0x44, 0x84, 0x37, 0x84, 0x36
    .byte 0x84, 0x35, 0x81, 0x44, 0x4C, 0x46, 0x16, 0x2C, 0xD2, 0xD3, 0x31, 0xB0, 0x38, 0xBC, 0x98, 0x46
    .byte 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF
    .byte 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0x48, 0x10, 0x00, 0x00, 0x4C, 0x10, 0x00, 0x00, 0x3E, 0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF
    .byte 0x00, 0x00, 0xFF, 0xFF
    .section .text.game_scene_after_time_of_day_period, "ax", %progbits
    .align 2, 0

    .global func_0801A8E0
    .thumb_func
func_0801A8E0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r6, r0, #0
    mov sl, r1
    adds r0, #8
    lsls r7, r1, #2
    adds r4, r0, r7
    ldr r1, [r4]
    cmp r1, #0
    beq .Lauto_0801A6A0
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    movs r0, #0
    str r0, [r4]
    .Lauto_0801A6A0:
    movs r5, #0
    mov r0, sl
    cmp r0, #0x5d
    bls .Lauto_0801A6AC
    bl loc_0801B1F8
    .Lauto_0801A6AC:
    ldr r0, [pc, #4]
    adds r0, r7, r0
    ldr r0, [r0]
    mov pc, r0
    .byte 0xB8, 0xA6, 0x01, 0x08
    .Lauto_0801A6B8:
    .byte 0x30, 0xA8, 0x01, 0x08, 0x78, 0xAC, 0x01, 0x08, 0x98, 0xAC, 0x01, 0x08, 0xB8, 0xAC, 0x01, 0x08
    .byte 0xD8, 0xAC, 0x01, 0x08, 0xF8, 0xAC, 0x01, 0x08, 0x18, 0xAD, 0x01, 0x08, 0x38, 0xAD, 0x01, 0x08
    .byte 0x58, 0xAD, 0x01, 0x08, 0x78, 0xAD, 0x01, 0x08, 0x98, 0xAD, 0x01, 0x08, 0xB8, 0xAD, 0x01, 0x08
    .byte 0xD8, 0xAD, 0x01, 0x08, 0xF8, 0xAD, 0x01, 0x08, 0x18, 0xAE, 0x01, 0x08, 0x38, 0xAE, 0x01, 0x08
    .byte 0x58, 0xAE, 0x01, 0x08, 0x78, 0xAE, 0x01, 0x08, 0x98, 0xAE, 0x01, 0x08, 0xB8, 0xAE, 0x01, 0x08
    .byte 0xD8, 0xAE, 0x01, 0x08, 0xF8, 0xAE, 0x01, 0x08, 0x18, 0xAF, 0x01, 0x08, 0x38, 0xAF, 0x01, 0x08
    .byte 0x58, 0xAF, 0x01, 0x08, 0x78, 0xAF, 0x01, 0x08, 0x98, 0xAF, 0x01, 0x08, 0xB8, 0xAF, 0x01, 0x08
    .byte 0xD8, 0xAF, 0x01, 0x08, 0xF8, 0xAF, 0x01, 0x08, 0x18, 0xB0, 0x01, 0x08, 0x38, 0xB0, 0x01, 0x08
    .byte 0x58, 0xB0, 0x01, 0x08, 0x78, 0xB0, 0x01, 0x08, 0x98, 0xB0, 0x01, 0x08, 0xB8, 0xB0, 0x01, 0x08
    .byte 0x60, 0xAB, 0x01, 0x08, 0x88, 0xAB, 0x01, 0x08, 0xB0, 0xAB, 0x01, 0x08, 0xD8, 0xAB, 0x01, 0x08
    .byte 0x00, 0xAC, 0x01, 0x08, 0x28, 0xAC, 0x01, 0x08, 0x50, 0xAC, 0x01, 0x08, 0x44, 0xA8, 0x01, 0x08
    .byte 0xA4, 0xA8, 0x01, 0x08, 0x04, 0xB1, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08
    .byte 0x00, 0xA9, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08
    .byte 0x00, 0xA9, 0x01, 0x08, 0x00, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08
    .byte 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08
    .byte 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08
    .byte 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08
    .byte 0x90, 0xA9, 0x01, 0x08, 0x90, 0xA9, 0x01, 0x08, 0x24, 0xB1, 0x01, 0x08, 0x24, 0xB1, 0x01, 0x08
    .byte 0x24, 0xB1, 0x01, 0x08, 0x24, 0xB1, 0x01, 0x08, 0x08, 0xAB, 0x01, 0x08, 0x5C, 0xAA, 0x01, 0x08
    .byte 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08
    .byte 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08, 0x12, 0xAA, 0x01, 0x08
    .byte 0xE8, 0xB0, 0x01, 0x08, 0x50, 0xB1, 0x01, 0x08, 0x50, 0xB1, 0x01, 0x08, 0x50, 0xB1, 0x01, 0x08
    .byte 0x78, 0xB1, 0x01, 0x08, 0x78, 0xB1, 0x01, 0x08, 0x78, 0xB1, 0x01, 0x08, 0xA0, 0xB1, 0x01, 0x08
    .byte 0xC0, 0xB1, 0x01, 0x08, 0xE0, 0xB1, 0x01, 0x08
    .Lauto_0801A830:
    .byte 0x03, 0x49, 0x70, 0x18, 0x01, 0x68, 0x30, 0x1C, 0x10, 0xF0, 0x22, 0xFF, 0x00, 0xF0, 0xDB, 0xFC
    .byte 0x38, 0x10, 0x00, 0x00
    .Lauto_0801A844:
    .byte 0x13, 0x4A, 0xB7, 0x18, 0x3A, 0x68, 0x13, 0x49, 0x50, 0x18, 0x01, 0x78, 0x10, 0x20, 0x08, 0x40
    .byte 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0xCE, 0xFC, 0x0F, 0x48, 0x14, 0x18, 0x20, 0x1C, 0xF4, 0xF7
    .byte 0x85, 0xFC, 0x00, 0x06, 0x00, 0x28, 0x06, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x02, 0x28
    .byte 0x01, 0xD1, 0x00, 0xF0, 0xBF, 0xFC, 0x44, 0x20
    bl __builtin_new
    .byte 0x3B, 0x68, 0x07, 0x49
    .byte 0x5A, 0x18, 0x5C, 0x31, 0x5B, 0x18, 0x31, 0x1C, 0x05, 0xF0, 0x0A, 0xFC, 0x00, 0xF0, 0xB1, 0xFC
    .byte 0x38, 0x10, 0x00, 0x00, 0x9C, 0x21, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00
    .Lauto_0801A8A4:
    .byte 0x13, 0x4A, 0xB0, 0x18, 0x02, 0x68, 0x13, 0x49, 0x50, 0x18, 0x01, 0x78, 0x02, 0x20, 0x08, 0x40
    .byte 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0x9E, 0xFC, 0x0F, 0x49, 0x50, 0x18, 0x01, 0x78, 0x04, 0x20
    .byte 0x08, 0x40, 0x00, 0x28, 0x01, 0xD0, 0x00, 0xF0, 0x95, 0xFC, 0x10, 0x1C, 0x14, 0x30, 0xEF, 0xF7
    .byte 0xB7, 0xF9, 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1, 0x00, 0xF0, 0x8C, 0xFC, 0x40, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C, 0x06, 0xF0, 0xB1, 0xFD, 0x00, 0xF0, 0x82, 0xFC, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x9A, 0x21, 0x00, 0x00, 0xA1, 0x21, 0x00, 0x00
    .Lauto_0801A900:
    .byte 0x57, 0x46, 0x2E, 0x3F, 0x20, 0x4A, 0xB0, 0x18, 0x00, 0x68, 0x20, 0x49, 0x44, 0x18, 0x20, 0x1C
    .byte 0xF4, 0xF7, 0x2E, 0xFC, 0x00, 0x06, 0x00, 0x28, 0x0B, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x03, 0x28, 0x06, 0xD1, 0x20, 0x1C, 0xF4, 0xF7, 0xFD, 0xFC, 0xB8, 0x42, 0x01, 0xD1, 0x00, 0xF0
    .byte 0x63, 0xFC, 0x15, 0x4A, 0xB4, 0x18, 0x20, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x88, 0x46, 0x40, 0x44
    .byte 0xF1, 0xF7, 0xBA, 0xFE, 0x87, 0x42, 0x01, 0xD1, 0x00, 0xF0, 0x56, 0xFC, 0x20, 0x68, 0x82, 0x22
    .byte 0xD2, 0x00, 0x80, 0x18, 0xF1, 0xF7, 0xFC, 0xFD, 0x87, 0x42, 0x01, 0xD3, 0x00, 0xF0, 0x4C, 0xFC
    .byte 0x20, 0x68, 0x40, 0x44, 0x39, 0x1C, 0xF1, 0xF7, 0x85, 0xFF, 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    .byte 0x00, 0xF0, 0x42, 0xFC, 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C, 0x07, 0xF0
    .byte 0xDD, 0xFB, 0x00, 0xF0, 0x38, 0xFC, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00
    .Lauto_0801A990:
    .byte 0x54, 0x46, 0x36, 0x3C, 0xA1, 0x46, 0x14, 0x48, 0x37, 0x18, 0x38, 0x68, 0xBE, 0x21, 0xC9, 0x00
    .byte 0x88, 0x46, 0x40, 0x44, 0xF2, 0xF7, 0x48, 0xFB, 0x84, 0x42, 0x01, 0xD1, 0x00, 0xF0, 0x24, 0xFC
    .byte 0x38, 0x68, 0xBE, 0x22, 0xD2, 0x00, 0x80, 0x18, 0xF2, 0xF7, 0x4C, 0xFA, 0x84, 0x42, 0x01, 0xD3
    .byte 0x00, 0xF0, 0x1A, 0xFC, 0x38, 0x68, 0x40, 0x44, 0x21, 0x1C, 0xF2, 0xF7, 0xF1, 0xFC, 0x04, 0x1C
    .byte 0x00, 0x2C, 0x0B, 0xD0, 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C, 0x07, 0xF0
    .byte 0xE5, 0xFF, 0x00, 0xF0, 0x08, 0xFC, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x38, 0x68, 0x40, 0x44
    .byte 0x49, 0x46, 0xF2, 0xF7, 0xF1, 0xFC, 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1, 0x00, 0xF0, 0xFC, 0xFB
    .byte 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C, 0x08, 0xF0, 0x17, 0xFE, 0x00, 0xF0
    .byte 0xF2, 0xFB
    .Lauto_0801AA12:
    .byte 0x57, 0x46, 0x4C, 0x3F, 0x10, 0x48, 0x34, 0x18, 0x20, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x40, 0x18
    .byte 0xF1, 0xF7, 0x95, 0xFD, 0x87, 0x42, 0x01, 0xD3, 0x00, 0xF0, 0xE5, 0xFB, 0x20, 0x68, 0x82, 0x22
    .byte 0xD2, 0x00, 0x80, 0x18, 0x39, 0x1C, 0xF1, 0xF7, 0x22, 0xFE, 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    .byte 0x00, 0xF0, 0xD9, 0xFB, 0x18, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C, 0x1D, 0xF0
    .byte 0x02, 0xF8, 0x00, 0xF0, 0xCF, 0xFB, 0x38, 0x10, 0x00, 0x00
    .Lauto_0801AA5C:
    .byte 0x25, 0x48, 0x34, 0x18, 0x20, 0x68, 0x25, 0x49, 0x40, 0x18, 0xF3, 0xF7, 0x5B, 0xFF, 0x00, 0x06
    .byte 0x00, 0x28, 0x01, 0xD1, 0x00, 0xF0, 0xC2, 0xFB, 0x20, 0x68, 0x21, 0x4A, 0x84, 0x18, 0x20, 0x1C
    .byte 0xF4, 0xF7, 0x78, 0xFB, 0x00, 0x06, 0x00, 0x28, 0x10, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x01, 0x28, 0x0B, 0xD1, 0x20, 0x1C
    bl GetArticle__C8HeldItem
    .byte 0x01, 0xA9, 0x08, 0x70, 0x08, 0x1C
    .byte 0xF3, 0xF7, 0x4A, 0xFA, 0x35, 0x28, 0x01, 0xD1, 0x00, 0xF0, 0xA8, 0xFB, 0x12, 0x48, 0x34, 0x18
    .byte 0x20, 0x68, 0x14, 0x49, 0x40, 0x18, 0x35, 0x21, 0xF4, 0xF7, 0x1E, 0xFE, 0x07, 0x1C, 0x01, 0x20
    .byte 0x40, 0x42, 0x87, 0x42, 0x00, 0xD0, 0x99, 0xE3, 0x20, 0x68, 0xFA, 0x22, 0x52, 0x00, 0x80, 0x18
    .byte 0xF1, 0xF7, 0xB8, 0xFA, 0x00, 0x28, 0x05, 0xD0, 0x35, 0x21, 0xF0, 0xF7, 0xA5, 0xFF, 0xB8, 0x42
    .byte 0x00, 0xD0, 0x8B, 0xE3, 0x2C, 0x20
    bl __builtin_new
    .byte 0x22, 0x68, 0x06, 0x49, 0x52, 0x18
    .byte 0x31, 0x1C, 0x1D, 0xF0, 0x65, 0xF9, 0x80, 0xE3, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .byte 0x2C, 0x1C, 0x00, 0x00, 0x38, 0x1C, 0x00, 0x00, 0xCC, 0x1C, 0x00, 0x00
    .Lauto_0801AB08:
    .byte 0x12, 0x4A, 0xB7, 0x18, 0x38, 0x68, 0x12, 0x49, 0x40, 0x18, 0xF3, 0xF7, 0xFF, 0xFE, 0x00, 0x06
    .byte 0x00, 0x28, 0x00, 0xD1, 0x6C, 0xE3, 0x38, 0x68, 0x0E, 0x4A, 0x84, 0x18, 0x20, 0x1C, 0xF4, 0xF7
    .byte 0x23, 0xFB, 0x00, 0x06, 0x00, 0x28, 0x05, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x04, 0x28
    .byte 0x00, 0xD1, 0x5D, 0xE3, 0x1C, 0x20
    bl __builtin_new
    .byte 0x3A, 0x68, 0xE5, 0x21, 0x49, 0x01
    .byte 0x52, 0x18, 0x31, 0x1C, 0x1D, 0xF0, 0x2E, 0xF8, 0x51, 0xE3, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0xD8, 0x1B, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00
    .Lauto_0801AB60:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x00, 0x22, 0x18, 0xF0, 0xA0, 0xFD, 0x3B, 0xE3, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801AB88:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x01, 0x22, 0x18, 0xF0, 0x8C, 0xFD, 0x27, 0xE3, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801ABB0:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x02, 0x22, 0x18, 0xF0, 0x78, 0xFD, 0x13, 0xE3, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801ABD8:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x03, 0x22, 0x18, 0xF0, 0x64, 0xFD, 0xFF, 0xE2, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801AC00:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x04, 0x22, 0x18, 0xF0, 0x50, 0xFD, 0xEB, 0xE2, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801AC28:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x05, 0x22, 0x18, 0xF0, 0x3C, 0xFD, 0xD7, 0xE2, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801AC50:
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18
    .byte 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x06, 0x22, 0x18, 0xF0, 0x28, 0xFD, 0xC3, 0xE2, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801AC78:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x01, 0xFE, 0xB2, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x44, 0x1D, 0x00, 0x00
    .Lauto_0801AC98:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x25, 0xFE, 0xA2, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x58, 0x1D, 0x00, 0x00
    .Lauto_0801ACB8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x47, 0xFE, 0x92, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x6C, 0x1D, 0x00, 0x00
    .Lauto_0801ACD8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0xD5, 0xFE, 0x82, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x84, 0x1D, 0x00, 0x00
    .Lauto_0801ACF8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0xFB, 0xFE, 0x72, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x98, 0x1D, 0x00, 0x00
    .Lauto_0801AD18:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x1F, 0xFF, 0x62, 0xE2, 0x38, 0x10, 0x00, 0x00, 0xAC, 0x1D, 0x00, 0x00
    .Lauto_0801AD38:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x43, 0xFF, 0x52, 0xE2, 0x38, 0x10, 0x00, 0x00, 0xC4, 0x1D, 0x00, 0x00
    .Lauto_0801AD58:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x69, 0xFF, 0x42, 0xE2, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1D, 0x00, 0x00
    .Lauto_0801AD78:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0x8B, 0xFF, 0x32, 0xE2, 0x38, 0x10, 0x00, 0x00, 0xEC, 0x1D, 0x00, 0x00
    .Lauto_0801AD98:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0xF0, 0x21, 0x49, 0x01
    .byte 0x5A, 0x18, 0x31, 0x1C, 0x1A, 0xF0, 0xAC, 0xFF, 0x21, 0xE2, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_0801ADB8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0xD3, 0xFF, 0x12, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x14, 0x1E, 0x00, 0x00
    .Lauto_0801ADD8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1A, 0xF0, 0xF7, 0xFF, 0x02, 0xE2, 0x38, 0x10, 0x00, 0x00, 0x28, 0x1E, 0x00, 0x00
    .Lauto_0801ADF8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0xF2, 0x21, 0x49, 0x01
    .byte 0x5A, 0x18, 0x31, 0x1C, 0x1B, 0xF0, 0x84, 0xF8, 0xF1, 0xE1, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .Lauto_0801AE18:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xA9, 0xF8, 0xE2, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x54, 0x1E, 0x00, 0x00
    .Lauto_0801AE38:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xCF, 0xF8, 0xD2, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x68, 0x1E, 0x00, 0x00
    .Lauto_0801AE58:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xF3, 0xF8, 0xC2, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x7C, 0x1E, 0x00, 0x00
    .Lauto_0801AE78:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x17, 0xF9, 0xB2, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x90, 0x1E, 0x00, 0x00
    .Lauto_0801AE98:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x3B, 0xF9, 0xA2, 0xE1, 0x38, 0x10, 0x00, 0x00, 0xA4, 0x1E, 0x00, 0x00
    .Lauto_0801AEB8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x5F, 0xF9, 0x92, 0xE1, 0x38, 0x10, 0x00, 0x00, 0xB8, 0x1E, 0x00, 0x00
    .Lauto_0801AED8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xEB, 0xF9, 0x82, 0xE1, 0x38, 0x10, 0x00, 0x00, 0xD0, 0x1E, 0x00, 0x00
    .Lauto_0801AEF8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x0B, 0xFA, 0x72, 0xE1, 0x38, 0x10, 0x00, 0x00, 0xE4, 0x1E, 0x00, 0x00
    .Lauto_0801AF18:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x99, 0xFA, 0x62, 0xE1, 0x38, 0x10, 0x00, 0x00, 0xFC, 0x1E, 0x00, 0x00
    .Lauto_0801AF38:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xBB, 0xFA, 0x52, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x10, 0x1F, 0x00, 0x00
    .Lauto_0801AF58:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x0F, 0xFB, 0x42, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x24, 0x1F, 0x00, 0x00
    .Lauto_0801AF78:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x65, 0xFB, 0x32, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x38, 0x1F, 0x00, 0x00
    .Lauto_0801AF98:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xFB, 0xFB, 0x22, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x50, 0x1F, 0x00, 0x00
    .Lauto_0801AFB8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x1F, 0xFC, 0x12, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x64, 0x1F, 0x00, 0x00
    .Lauto_0801AFD8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x79, 0xFC, 0x02, 0xE1, 0x38, 0x10, 0x00, 0x00, 0x7C, 0x1F, 0x00, 0x00
    .Lauto_0801AFF8:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xE7, 0xFC, 0xF2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x90, 0x1F, 0x00, 0x00
    .Lauto_0801B018:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x09, 0xFD, 0xE2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xA4, 0x1F, 0x00, 0x00
    .Lauto_0801B038:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x29, 0xFD, 0xD2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xB8, 0x1F, 0x00, 0x00
    .Lauto_0801B058:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x47, 0xFD, 0xC2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD0, 0x1F, 0x00, 0x00
    .Lauto_0801B078:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0x65, 0xFD, 0xB2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xE4, 0x1F, 0x00, 0x00
    .Lauto_0801B098:
    .byte 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68, 0x03, 0x49, 0x5A, 0x18
    .byte 0x31, 0x1C, 0x1B, 0xF0, 0xA3, 0xFA, 0xA2, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xFC, 0x1F, 0x00, 0x00
    .Lauto_0801B0B8:
    .byte 0x09, 0x4A, 0xB7, 0x18, 0x38, 0x68, 0x09, 0x49, 0x40, 0x18
    bl GetChild__13NpcCollection
    .byte 0x04, 0x1C
    .byte 0x00, 0x2C, 0x00, 0xD1, 0x94, 0xE0, 0x4C, 0x20
    bl __builtin_new
    .byte 0x3B, 0x68, 0x31, 0x1C
    .byte 0x22, 0x1C, 0x1B, 0xF0, 0x71, 0xFD, 0x8A, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801B0E8:
    .byte 0x04, 0x4A, 0xB0, 0x18, 0x01, 0x68, 0x04, 0x48, 0x09, 0x18, 0x30, 0x1C, 0x1F, 0xF0, 0x1A, 0xFA
    .byte 0x7D, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x94, 0x34, 0x00, 0x00
    .Lauto_0801B104:
    .byte 0x54, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0A, 0x68, 0x03, 0x49, 0x52, 0x18
    .byte 0x31, 0x1C, 0x1E, 0xF0, 0x8F, 0xFA, 0x6C, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xDC, 0x34, 0x00, 0x00
    .Lauto_0801B124:
    .byte 0x55, 0x46, 0x46, 0x3D, 0x07, 0x48, 0x04, 0x68, 0x07, 0x4A, 0xA4, 0x18, 0x34, 0x20
    bl __builtin_new
    .byte 0x69, 0x00, 0x49, 0x19, 0x89, 0x00, 0x64, 0x18, 0x31, 0x1C, 0x22, 0x1C, 0x17, 0xF0
    .byte 0xC1, 0xFA, 0x56, 0xE0, 0x0C, 0x04, 0x00, 0x03, 0x24, 0x05, 0x00, 0x00
    .Lauto_0801B150:
    .byte 0x54, 0x46, 0x55, 0x3C, 0x06, 0x49, 0x70, 0x18, 0x00, 0x68, 0x06, 0x4A, 0x80, 0x18
    .byte 0x21, 0x1C
    bl GetSouthTownNpcLocation1__13NpcCollectionUi
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x22, 0x1C, 0x1C, 0xF0, 0x41, 0xFB, 0x42, 0xE0, 0x38, 0x10
    .byte 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801B178:
    .byte 0x54, 0x46, 0x58, 0x3C, 0x06, 0x49, 0x70, 0x18, 0x00, 0x68, 0x06, 0x4A, 0x80, 0x18
    .byte 0x21, 0x1C
    bl GetSouthTownNpcLocation2__13NpcCollectionUi
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x22, 0x1C, 0x1C, 0xF0, 0x67, 0xFB, 0x2E, 0xE0, 0x38, 0x10
    .byte 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801B1A0:
    .byte 0x05, 0x49, 0x70, 0x18, 0x00, 0x68, 0x05, 0x4A, 0x80, 0x18
    bl GetYodelRanchHouseNpcLocation__13NpcCollection
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x1C, 0xF0, 0x93, 0xFB, 0x1E, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801B1C0:
    .byte 0x05, 0x49, 0x70, 0x18, 0x00, 0x68, 0x05, 0x4A, 0x80, 0x18
    bl GetInnSecondFloorNpcLocation__13NpcCollection
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x1C, 0xF0, 0x9F, 0xFB, 0x0E, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00
    .Lauto_0801B1E0:
    .byte 0x1C, 0x20
    bl __builtin_new
    .byte 0x0F, 0x4A, 0xB1, 0x18, 0x0A, 0x68, 0x0E, 0x49, 0x52, 0x18
    .byte 0x31, 0x1C, 0x1D, 0xF0, 0x6F, 0xF9, 0x05, 0x1C
    .global loc_0801B1F8
    .thumb_func
    loc_0801B1F8:
    cmp r5, #0
    beq .Lauto_0801B212
    adds r0, r6, #0
    adds r0, #8
    mov r2, sl
    lsls r1, r2, #2
    adds r0, r0, r1
    str r5, [r0]
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x10]
    adds r0, r5, #0
    bl _call_via_r1
    .Lauto_0801B212:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x4C, 0x21, 0x00, 0x00
    .global func_0801B498
    .thumb_func
func_0801B498:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    adds r7, r1, #0
    mov sb, r2
    movs r1, #0x64
    str r1, [sp, #8]
    movs r2, #1
    str r2, [sp, #0xc]
    adds r3, r0, #0
    adds r3, #8
    str r3, [sp, #0x10]
    mov r8, sp
    adds r0, #0xc
    mov sl, r0
    .Lauto_0801B250:
    mov r4, sl
    ldr r5, [r4]
    cmp r5, #0
    beq .Lauto_0801B330
    .byte 0x38, 0x88, 0x80, 0x05, 0x80, 0x0D, 0xA9, 0x88, 0x88, 0x42, 0x65, 0xD1, 0x69, 0x69, 0x68, 0x46
    .byte 0xCA, 0x68, 0x29, 0x1C, 0xB7, 0xF0, 0x2E, 0xFF, 0x4B, 0x46, 0x00, 0x24, 0x1A, 0x5F, 0x41, 0x46
    .byte 0x04, 0x23, 0xC8, 0x5E, 0x12, 0x1A, 0x00, 0x24, 0x08, 0x5F, 0x4B, 0x46, 0x04, 0x24, 0x19, 0x5F
    .byte 0x40, 0x1A, 0x02, 0x40, 0x02, 0x21, 0x58, 0x5E, 0x43, 0x46, 0x06, 0x24, 0x19, 0x5F, 0x40, 0x1A
    .byte 0x02, 0x40, 0x02, 0x21, 0x58, 0x5E, 0x4B, 0x46, 0x06, 0x24, 0x19, 0x5F, 0x40, 0x1A, 0x02, 0x40
    .byte 0x00, 0x2A, 0x41, 0xDA, 0x02, 0x98, 0x64, 0x28, 0x3C, 0xD0, 0x80, 0x00, 0x04, 0x99, 0x08, 0x18
    .byte 0x04, 0x68, 0x0A, 0x23, 0xE2, 0x5E, 0x79, 0x78, 0x89, 0x08, 0x78, 0x88, 0x22, 0x4B, 0x9C, 0x46
    .byte 0x18, 0x40, 0x80, 0x01, 0x08, 0x43, 0x00, 0x04, 0x06, 0x14, 0x93, 0x1B, 0x00, 0x2B, 0x00, 0xDA
    .byte 0x5B, 0x42, 0x0E, 0x20, 0x22, 0x5E, 0xF9, 0x78, 0x89, 0x08, 0xB8, 0x88, 0x64, 0x46, 0x20, 0x40
    .byte 0x80, 0x01, 0x08, 0x43, 0x00, 0x04, 0x04, 0x14, 0x11, 0x1B, 0x00, 0x29, 0x00, 0xDA, 0x49, 0x42
    .byte 0x18, 0x1C, 0x58, 0x43, 0x0A, 0x1C, 0x4A, 0x43, 0x11, 0x1C, 0x42, 0x18, 0x0A, 0x23, 0xE8, 0x5E
    .byte 0x83, 0x1B, 0x00, 0x2B, 0x00, 0xDA, 0x5B, 0x42, 0x0E, 0x21, 0x68, 0x5E, 0x01, 0x1B, 0x00, 0x29
    .byte 0x00, 0xDA, 0x49, 0x42, 0x18, 0x1C, 0x58, 0x43, 0x0B, 0x1C, 0x4B, 0x43, 0x19, 0x1C, 0x40, 0x18
    .byte 0x82, 0x42, 0x01, 0xDB, 0x03, 0x9C, 0x02, 0x94
    .Lauto_0801B330:
    movs r0, #4
    add sl, r0
    ldr r1, [sp, #0xc]
    adds r1, #1
    str r1, [sp, #0xc]
    cmp r1, #0x63
    bls .Lauto_0801B250
    ldr r0, [sp, #8]
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0xFF, 0x03, 0x00, 0x00
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
    .byte 0x24, 0x92, 0x1B, 0x06, 0x1B, 0x0E, 0x9A, 0x46, 0x78, 0x68, 0x40, 0x68, 0x88, 0xF0, 0x9A, 0xFC
    .byte 0x24, 0x30, 0x00, 0x78, 0x00, 0x28, 0x14, 0xD0, 0xDE, 0x20, 0x40, 0x00, 0x3C, 0x18, 0x24, 0x99
    .byte 0x48, 0x01, 0x40, 0x18, 0x80, 0x00, 0x24, 0x18, 0x20, 0x1C, 0x41, 0x46, 0x20, 0x22, 0xB7, 0xF0
    .byte 0xC7, 0xFC, 0x21, 0x1C, 0x82, 0x31, 0x01, 0x20, 0x08, 0x70, 0x83, 0x34, 0x52, 0x46, 0x22, 0x70
    .byte 0x3D, 0xE3, 0x78, 0x68, 0x01, 0x68, 0x05, 0x4B, 0xF8, 0x18, 0x00, 0x68, 0x08, 0x30, 0x2E, 0x29
    .byte 0x0A, 0xD0, 0x2E, 0x29, 0x04, 0xDD, 0x2F, 0x29, 0x08, 0xD0, 0x09, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0x2C, 0x29, 0x05, 0xDB, 0x00, 0x23, 0x04, 0xE0, 0x01, 0x23, 0x02, 0xE0, 0x02, 0x23, 0x00, 0xE0
    .byte 0x03, 0x68, 0x22, 0x4C, 0x38, 0x19, 0x01, 0x78, 0x1E, 0x22, 0xCE, 0x25, 0x6D, 0x00, 0xED, 0x19
    .byte 0xA9, 0x46, 0x1F, 0x4E, 0xB8, 0x19, 0x06, 0x68, 0x25, 0x91, 0x52, 0x1A, 0x26, 0x92, 0xDE, 0x20
    .byte 0x40, 0x00, 0x3C, 0x18, 0x24, 0x99, 0x4D, 0x01, 0x68, 0x18, 0x80, 0x00, 0x24, 0x18, 0x20, 0x1C
    .byte 0x41, 0x46, 0x20, 0x22, 0x2F, 0x93, 0xB7, 0xF0, 0x8B, 0xFC, 0x22, 0x1C, 0x82, 0x32, 0x01, 0x20
    .byte 0x84, 0x46, 0x61, 0x46, 0x11, 0x70, 0x20, 0x1C, 0x83, 0x30, 0x51, 0x46, 0x01, 0x70, 0xA0, 0x46
    .byte 0x28, 0x95, 0x2F, 0x9B, 0x54, 0x46, 0x00, 0x2C, 0x1C, 0xD1, 0x41, 0x46, 0x20, 0x31, 0x40, 0x46
    .byte 0x68, 0xC8, 0x68, 0xC1, 0x70, 0xC8, 0x70, 0xC1, 0x18, 0xC8, 0x18, 0xC1, 0x41, 0x46, 0x40, 0x31
    .byte 0x40, 0x46, 0x68, 0xC8, 0x68, 0xC1, 0x70, 0xC8, 0x70, 0xC1, 0x18, 0xC8, 0x18, 0xC1, 0x65, 0x46
    .byte 0x15, 0x70, 0xDE, 0x26, 0x76, 0x00, 0xF6, 0x19, 0xB2, 0x46, 0xB2, 0xE2, 0x4C, 0x10, 0x00, 0x00
    .byte 0x48, 0x10, 0x00, 0x00, 0x2E, 0x92, 0xDE, 0x20, 0x40, 0x00, 0xC0, 0x19, 0x82, 0x46, 0x04, 0x2B
    .byte 0x00, 0xD9, 0xA3, 0xE2, 0x98, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00
    .byte 0xB0, 0xB8, 0x01, 0x08, 0xC4, 0xB8, 0x01, 0x08, 0x1C, 0xBB, 0x01, 0x08, 0x1C, 0xBB, 0x01, 0x08
    .byte 0xC4, 0xB8, 0x01, 0x08, 0xC4, 0xB8, 0x01, 0x08, 0x01, 0x2E, 0x00, 0xD1, 0x9C, 0xE0, 0x01, 0x2E
    .byte 0x08, 0xDC, 0x00, 0x2E, 0x62, 0xD0, 0x41, 0x46, 0x82, 0x31, 0x2E, 0x91, 0x20, 0x22, 0x4A, 0x44
    .byte 0x92, 0x46, 0x83, 0xE2, 0x02, 0x2E, 0x00, 0xD1, 0xBE, 0xE0, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93
    .byte 0x20, 0x24, 0x4C, 0x44, 0xA2, 0x46, 0x03, 0x2E, 0x00, 0xD0, 0x77, 0xE2, 0x08, 0xAA, 0x0A, 0x23
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x1E, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x1C, 0x4B
    .byte 0x09, 0x93, 0x69, 0x46, 0x16, 0x1C, 0x05, 0x1C, 0x0A, 0xAF, 0x0B, 0xAC, 0xA1, 0x46, 0x14, 0x1C
    .byte 0xA5, 0x45, 0x04, 0xD0, 0x1C, 0x1C, 0x0C, 0x80, 0x02, 0x31, 0xB1, 0x42, 0xFB, 0xD1, 0x13, 0x68
    .byte 0x69, 0x46, 0x42, 0x46, 0x13, 0x4C, 0xB7, 0xF0, 0xC7, 0xFB, 0x09, 0x23, 0x0A, 0xAA, 0x11, 0x78
    .byte 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00, 0x11, 0x88
    .byte 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x0A, 0x48
    .byte 0x0B, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x00, 0xD1, 0xD5, 0xE1, 0x4D, 0x46, 0x2A, 0x68
    .byte 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0xCE, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF
    .byte 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0xAA, 0x1B, 0x00, 0x00, 0x0C, 0xAA, 0x09, 0x23
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x12, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x10, 0x4E
    .byte 0x0D, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23
    .byte 0x4B, 0x44, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1
    .byte 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x07, 0x4C, 0xB7, 0xF0, 0x76, 0xFB, 0x28, 0x1C, 0x20, 0x30
    .byte 0x41, 0x46, 0x20, 0x22, 0xB7, 0xF0, 0xAC, 0xFB, 0xF8, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF
    .byte 0xAA, 0x1B, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x44, 0x46, 0x20, 0x34, 0x20, 0x1C, 0x41, 0x46
    .byte 0x20, 0x22, 0xB7, 0xF0, 0x9D, 0xFB, 0x0E, 0xAA, 0x03, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xD8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0D, 0x48, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x80, 0x20, 0x34, 0x08, 0x20, 0x46, 0x01, 0x20, 0x21, 0x0E, 0x43, 0x80, 0x02
    .byte 0x06, 0x43, 0x0F, 0x96, 0x68, 0x46, 0x08, 0xA9, 0x45, 0x46, 0x82, 0x35, 0x2E, 0x95, 0x20, 0x23
    .byte 0x4B, 0x44, 0x9A, 0x46, 0x8D, 0x45, 0x03, 0xD0, 0x06, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1
    .byte 0x13, 0x68, 0x62, 0xE1, 0x1F, 0xFC, 0xFF, 0xFF, 0x10, 0xAA, 0x03, 0x23, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xD8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x25, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x47, 0x46, 0x20, 0x37, 0x13, 0x1C, 0x08, 0x20, 0x42, 0x01
    .byte 0x20, 0x21, 0x0A, 0x43, 0x80, 0x02, 0x02, 0x43, 0x11, 0x92, 0x6C, 0x46, 0x08, 0xAE, 0x3D, 0x1C
    .byte 0x68, 0x46, 0x48, 0x30, 0x29, 0x90, 0x69, 0x46, 0x4C, 0x31, 0x2A, 0x91, 0x40, 0x46, 0x82, 0x30
    .byte 0x2E, 0x90, 0x20, 0x21, 0x49, 0x44, 0x8A, 0x46, 0xB5, 0x45, 0x04, 0xD0, 0x10, 0x1C, 0x20, 0x80
    .byte 0x02, 0x34, 0xB4, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x38, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x12, 0x4C
    .byte 0xB7, 0xF0, 0x02, 0xFB, 0x0A, 0x23, 0x12, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x29, 0x9B, 0x08, 0x48, 0x13, 0x90, 0x68, 0x46, 0x08, 0xA9
    .byte 0x8D, 0x45, 0x00, 0xD1, 0x10, 0xE1, 0x2A, 0x9D, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42
    .byte 0xFB, 0xD1, 0x09, 0xE1, 0x1F, 0xFC, 0xFF, 0xFF
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00
    .byte 0x01, 0x2E, 0x00, 0xD1, 0xB6, 0xE0, 0x01, 0x2E, 0x08, 0xDC, 0x00, 0x2E, 0x60, 0xD0, 0x46, 0x46
    .byte 0x82, 0x36, 0x2E, 0x96, 0x20, 0x20, 0x48, 0x44, 0x82, 0x46, 0x57, 0xE1, 0x02, 0x2E, 0x00, 0xD1
    .byte 0x00, 0xE1, 0x41, 0x46, 0x82, 0x31, 0x2E, 0x91, 0x20, 0x22, 0x4A, 0x44, 0x92, 0x46, 0x03, 0x2E
    .byte 0x00, 0xD0, 0x4B, 0xE1, 0x14, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x1D, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x1B, 0x4E, 0x15, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C
    .byte 0x16, 0xAF, 0x17, 0xAB, 0x99, 0x46, 0xA5, 0x45, 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42
    .byte 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x13, 0x4C, 0xB7, 0xF0, 0x9D, 0xFA, 0x0A, 0x23
    .byte 0x16, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23
    .byte 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34
    .byte 0x3B, 0x1C, 0x0A, 0x48, 0x17, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x00, 0xD1, 0xAB, 0xE0
    .byte 0x4D, 0x46, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0xA4, 0xE0, 0x00, 0x00
    .byte 0x1F, 0xFC, 0xFF, 0xFF, 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x32, 0x6A, 0x00, 0x00
    .byte 0x18, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x20, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46
    .byte 0x20, 0x30, 0x1E, 0x4E, 0x19, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C, 0x1A, 0xAF, 0x6B, 0x46
    .byte 0x6C, 0x33, 0x2B, 0x93, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46
    .byte 0xA5, 0x45, 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46
    .byte 0x42, 0x46, 0x13, 0x4C, 0xB7, 0xF0, 0x48, 0xFA, 0x0A, 0x23, 0x1A, 0xAA, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x07, 0x48, 0x1B, 0x90
    .byte 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x57, 0xD0, 0x2B, 0x9D, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30
    .byte 0x88, 0x42, 0xFB, 0xD1, 0x50, 0xE0, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x1C, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x23, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x21, 0x4E, 0x1D, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C
    .byte 0x1E, 0xAF, 0x6B, 0x46, 0x7C, 0x33, 0x2C, 0x93, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23
    .byte 0x4B, 0x44, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1
    .byte 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x16, 0x4C, 0xB7, 0xF0, 0xF6, 0xF9, 0x0A, 0x23, 0x1E, 0xAA
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x0D, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C
    .byte 0x0A, 0x48, 0x1F, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x05, 0xD0, 0x2C, 0x9D, 0x2A, 0x68
    .byte 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x20, 0x1C, 0x69, 0x46, 0x42, 0x46
    .byte 0x03, 0x4C, 0xB7, 0xF0, 0xD1, 0xF9, 0x59, 0xE0, 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x20, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x41, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x46, 0x46, 0x20, 0x36, 0x3F, 0x4C, 0x21, 0xA8, 0x04, 0x60, 0x68, 0x46, 0x08, 0xA9
    .byte 0x35, 0x1C, 0x22, 0xAF, 0x6B, 0x46, 0x8C, 0x33, 0x2D, 0x93, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93
    .byte 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0x8D, 0x45, 0x03, 0xD0, 0x04, 0x80, 0x02, 0x30, 0x88, 0x42
    .byte 0xFB, 0xD1, 0x13, 0x68, 0x30, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x33, 0x4C, 0xB7, 0xF0, 0x9C, 0xF9
    .byte 0x0A, 0x23, 0x22, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x2A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C
    .byte 0x20, 0x34, 0x3B, 0x1C, 0x29, 0x48, 0x2D, 0x9D, 0x28, 0x60, 0x68, 0x46, 0x08, 0xA9, 0x23, 0xAA
    .byte 0x8D, 0x45, 0x04, 0xD0, 0x12, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x1B, 0x68
    .byte 0x20, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x20, 0x4C, 0xB7, 0xF0, 0x76, 0xF9, 0x01, 0x20, 0x2E, 0x9E
    .byte 0x30, 0x70, 0x28, 0x99, 0x24, 0x9A, 0x88, 0x18, 0x80, 0x00, 0x53, 0x46, 0x1D, 0x18, 0x28, 0x1C
    .byte 0x60, 0x30, 0x29, 0x1C, 0x20, 0x31, 0x2A, 0x1C, 0x40, 0x32, 0x1F, 0x23, 0x25, 0x9C, 0x1C, 0x40
    .byte 0x20, 0x23, 0x5B, 0x42, 0x27, 0x9E, 0x33, 0x40, 0x23, 0x43, 0x1B, 0x06, 0x1B, 0x0E, 0x14, 0x4C
    .byte 0x26, 0x40, 0x1E, 0x43, 0x1F, 0x23, 0x26, 0x9C, 0x1C, 0x40, 0x64, 0x01, 0x0C, 0x4B, 0x33, 0x40
    .byte 0x23, 0x43, 0x1B, 0x04, 0x1B, 0x0C, 0x0F, 0x4C, 0x26, 0x40, 0x1E, 0x43, 0x27, 0x96, 0x33, 0x1C
    .byte 0x09, 0x4C, 0xB7, 0xF0, 0x49, 0xF9, 0x29, 0x1C, 0x82, 0x31, 0x01, 0x20, 0x08, 0x70, 0x30, 0xB0
    .byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
    .byte 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00
    .byte 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF
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
    .byte 0x18, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x34, 0x38, 0x15, 0x49, 0x88, 0x42, 0x68, 0xD8, 0x15, 0x49
    .byte 0x60, 0x18, 0x00, 0x68, 0x14, 0x49, 0x46, 0x18, 0x59, 0x78, 0x89, 0x08, 0x58, 0x88, 0x13, 0x4A
    .byte 0x10, 0x40, 0x80, 0x01, 0x08, 0x43, 0x00, 0x04, 0x00, 0x14, 0x00, 0x28, 0x00, 0xDA, 0x07, 0x30
    .byte 0xC5, 0x10, 0xD9, 0x78, 0x89, 0x08, 0x98, 0x88, 0x10, 0x40, 0x80, 0x01, 0x08, 0x43, 0x00, 0x04
    .byte 0x00, 0x14, 0x00, 0x28, 0x00, 0xDA, 0x07, 0x30, 0xC4, 0x10, 0x30, 0x1C
    bl GetLayoutKind__C14MineFloorState
    .byte 0x04, 0x28, 0x1F, 0xD8, 0x80, 0x00, 0x06, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00
    .byte 0xFF, 0x01, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00
    .byte 0xB4, 0xBF, 0x01, 0x08, 0xD4, 0xBF, 0x01, 0x08, 0xC8, 0xBF, 0x01, 0x08, 0xD4, 0xBF, 0x01, 0x08
    .byte 0xCE, 0xBF, 0x01, 0x08, 0xD4, 0xBF, 0x01, 0x08, 0x02, 0x21, 0x88, 0x46, 0x04, 0xE0, 0x02, 0x21
    .byte 0x88, 0x46, 0x01, 0xE0, 0x02, 0x20, 0x80, 0x46, 0x07, 0x23, 0x02, 0x2D, 0x20, 0xD3, 0x9C, 0x42
    .byte 0x1E, 0xD3, 0x30, 0x1C, 0x00, 0x93
    bl GetWidth__C14MineFloorState
    .byte 0x40, 0x00, 0x40, 0x44, 0xA8, 0x42
    .byte 0x16, 0xD9, 0x30, 0x1C
    bl GetHeight__C14MineFloorState
    .byte 0x40, 0x00, 0x00, 0x9B, 0x18, 0x18, 0xA0, 0x42
    .byte 0x0E, 0xD9, 0x41, 0x46, 0x6A, 0x1A, 0x52, 0x08, 0xE1, 0x1A, 0x49, 0x08, 0x50, 0x00, 0x40, 0x44
    .byte 0x38, 0x80, 0x48, 0x00, 0x18, 0x18, 0x78, 0x80, 0xBA, 0x80, 0xF9, 0x80, 0x01, 0x20, 0x81, 0x46
    .byte 0x48, 0x46, 0x01, 0xB0, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
    .section .text.game_scene_farm_plot_action_after, "ax", %progbits
    .align 2, 0

    .global func_0801C3DC
    .thumb_func
func_0801C3DC:
    bx lr
    .byte 0x00, 0x00
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
    ldr r0, [pc, #0x9c]
    adds r0, r0, r7
    mov r8, r0
    ldr r0, [pc, #0x9c]
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
    ldr r2, [pc, #0x58]
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
    .byte 0x00, 0x00, 0x88, 0x10, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0x6F, 0x08, 0x00, 0x00
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
    ldr r0, [pc, #0x70]
    adds r5, r4, r0
    ldr r0, [r5]
    ldr r1, [pc, #0x6c]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00
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
    .byte 0x00, 0x00
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
    ldr r0, [pc, #0x110]
    ldr r4, [r0]
    ldr r0, [pc, #0x110]
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
    ldr r1, [pc, #0xec]
    mov r8, r1
    mov r1, r8
    ands r0, r1
    ldrh r3, [r4, #2]
    ldr r2, [pc, #0xe8]
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
    .byte 0xA2, 0x80, 0x36, 0x04, 0xB6, 0x09, 0x60, 0x68, 0x2D, 0x49, 0x08, 0x40, 0x30, 0x43, 0x60, 0x60
    .byte 0x60, 0x46, 0x07, 0x40, 0xBA, 0x00, 0x21, 0x78, 0x0D, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43
    .byte 0x20, 0x70, 0x69, 0x46, 0x09, 0x89, 0x21, 0x81, 0x26, 0x48, 0x48, 0x44, 0x80, 0x46, 0x51, 0x46
    .byte 0x89, 0x00, 0x8A, 0x46, 0xD0, 0x44, 0x4C, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x49, 0x46
    .byte 0x08, 0x68, 0x41, 0x6E, 0x48, 0x46, 0xB6, 0xF0, 0x8D, 0xFE, 0x04, 0x1C, 0x28, 0x1C, 0x49, 0x46
    .byte 0x02, 0x22, 0x1B, 0x23
    bl __19GameSceneSpriteBaseP10GameObjectUii
    .byte 0x1B, 0x48, 0x68, 0x62, 0x28, 0x20, 0x40, 0x19
    .byte 0x81, 0x46, 0x26, 0x68, 0x68, 0x46, 0xF3, 0x68, 0x21, 0x1C, 0x02, 0x9A, 0xB6, 0xF0, 0x7E, 0xFE
    .byte 0x00, 0x98, 0x02, 0x88, 0x48, 0x46, 0x33, 0x69, 0x21, 0x1C, 0xB6, 0xF0, 0x77, 0xFE, 0x29, 0x1C
    .byte 0x48, 0x31, 0x01, 0x20, 0x08, 0x70, 0x44, 0x46, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB6, 0xF0, 0x65, 0xFE, 0x25, 0x60
    .byte 0x03, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .byte 0x0C, 0x04, 0x00, 0x03, 0xDC, 0x04, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF
    .byte 0xFF, 0x03, 0x00, 0xFC, 0xB0, 0x10, 0x00, 0x00
    .4byte __vt_20GameSceneGroupSprite
    .global RemoveWorldEventIcon
    .thumb_func
RemoveWorldEventIcon:
    push {r4, r5, lr}
    ldr r2, [pc, #0x40]
    ldr r3, [r2]
    ldr r2, [pc, #0x40]
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
    ldr r2, [pc, #0x2c]
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
    .byte 0x0C, 0x04, 0x00, 0x03, 0xDC, 0x04, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00
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
    ldr r3, [pc, #0x74]
    adds r5, r7, r3
    ldr r0, [pc, #0x74]
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
    .byte 0x36, 0xD1, 0x08, 0x07, 0x80, 0x0F, 0x02, 0x28, 0x00, 0xD1, 0x88, 0xE0, 0x14, 0x49, 0x78, 0x18
    .byte 0x00, 0x68, 0x00, 0x21, 0xC0, 0x22
    bl PlaySong__9GameSceneiUi
    .byte 0x29, 0x78, 0x0D, 0x22, 0x52, 0x42
    .byte 0x10, 0x1C, 0x01, 0x40, 0x08, 0x20, 0x01, 0x43, 0x29, 0x70, 0x64, 0x68, 0x20, 0x1C, 0x28, 0x30
    .byte 0x0C, 0x49
    bl ResolveIndexedResourceHandle
    .byte 0x20, 0x1C, 0x3C, 0x30, 0x00, 0x21, 0x06, 0x70, 0x02, 0x30
    .byte 0x01, 0x70, 0x01, 0x30, 0x06, 0x70, 0x08, 0x4B, 0xF8, 0x18, 0x00, 0x68, 0x07, 0x4D, 0x40, 0x19
    .byte 0xF2, 0xF7, 0xD6, 0xFC, 0x63, 0xE0, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0x84, 0x10, 0x00, 0x00
    .byte 0x54, 0x10, 0x00, 0x00, 0x73, 0x08, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00
    .Lauto_0801C548:
    adds r5, #0xc
    adds r4, #0xc
    adds r2, #1
    cmp r2, #3
    bls .Lauto_0801C4C2
    movs r0, #0
    cmp r0, #0
    bne .Lauto_0801C5F6
    ldr r0, [pc, #0x50]
    adds r6, r7, r0
    ldr r1, [r6]
    ldr r5, [pc, #0x50]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
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
    ldr r3, [pc, #0x3c]
    adds r0, r7, r3
    ldr r3, [r0]
    ldr r0, [pc, #0x38]
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
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
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
    ldr r1, [pc, #8]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x00, 0x00, 0xDC, 0xC6, 0x01, 0x08
    .Lauto_0801C6DC:
    .byte 0x9A, 0xC7, 0x01, 0x08, 0x9A, 0xC7, 0x01, 0x08, 0x9A, 0xC7, 0x01, 0x08, 0x00, 0xC7, 0x01, 0x08
    .byte 0x20, 0xC7, 0x01, 0x08, 0x40, 0xC7, 0x01, 0x08, 0x9A, 0xC7, 0x01, 0x08, 0x60, 0xC7, 0x01, 0x08
    .byte 0x80, 0xC7, 0x01, 0x08
    .Lauto_0801C700:
    .byte 0x06, 0x49, 0x78, 0x18, 0x00, 0x68, 0x31, 0x01, 0x8C, 0x22, 0x52, 0x00, 0x89, 0x18, 0x43, 0x46
    .byte 0x1A, 0x01, 0xC0, 0x32, 0x03, 0x23, 0x8E, 0xF0, 0xD5, 0xFC, 0x3E, 0xE0, 0x28, 0x10, 0x00, 0x00
    .Lauto_0801C720:
    .byte 0x06, 0x49, 0x78, 0x18, 0x00, 0x68, 0x31, 0x01, 0x8C, 0x22, 0x52, 0x00, 0x89, 0x18, 0x43, 0x46
    .byte 0x1A, 0x01, 0xC0, 0x32, 0x01, 0x23, 0x8E, 0xF0, 0xC5, 0xFC, 0x2E, 0xE0, 0x28, 0x10, 0x00, 0x00
    .Lauto_0801C740:
    .byte 0x06, 0x49, 0x78, 0x18, 0x00, 0x68, 0x31, 0x01, 0x8C, 0x22, 0x52, 0x00, 0x89, 0x18, 0x43, 0x46
    .byte 0x1A, 0x01, 0xC0, 0x32, 0x02, 0x23, 0x8E, 0xF0, 0xB5, 0xFC, 0x1E, 0xE0, 0x28, 0x10, 0x00, 0x00
    .Lauto_0801C760:
    .byte 0x06, 0x49, 0x78, 0x18, 0x00, 0x68, 0x31, 0x01, 0x90, 0x22, 0x52, 0x00, 0x89, 0x18, 0x43, 0x46
    .byte 0x1A, 0x01, 0xD0, 0x32, 0x08, 0x23, 0x8E, 0xF0, 0xA5, 0xFC, 0x0E, 0xE0, 0x28, 0x10, 0x00, 0x00
    .Lauto_0801C780:
    .byte 0x0A, 0x49, 0x78, 0x18, 0x00, 0x68, 0x31, 0x01, 0x90, 0x22, 0x52, 0x00, 0x89, 0x18, 0x43, 0x46
    .byte 0x1A, 0x01, 0xD0, 0x32, 0x06, 0x23, 0x8E, 0xF0, 0x95, 0xFC
    .Lauto_0801C79A:
    movs r0, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
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
    ldr r0, [pc, #0x10]
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl loc_0801C608
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b loc_0801C85E
    .4byte gUnk_080F0800
    .global loc_0801C7F4
    .thumb_func
    loc_0801C7F4:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, [pc, #0x24]
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
    .4byte gUnk_080F0800
    .global loc_0801C828
    .thumb_func
    loc_0801C828:
    ldr r1, [pc, #0x14]
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #6
    bl func_080AB0C4
    b .Lauto_0801C858
    .byte 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .global loc_0801C844
    .thumb_func
    loc_0801C844:
    ldr r1, [pc, #0x20]
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
    .byte 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
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
    ldr r4, [pc, #0x90]
    add r4, r8
    ldr r0, [r4]
    ldr r1, [pc, #0x8c]
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
    .byte 0x11, 0x88, 0x89, 0x05, 0x89, 0x0D, 0x88, 0x42, 0x24, 0xD1, 0x40, 0x46, 0x45, 0x68, 0xB1, 0x88
    .byte 0xF2, 0x88, 0x38, 0x1C
    bl GetCellType__C14MineFloorStateUiUi
    .byte 0x04, 0x1C, 0xB1, 0x88, 0xF2, 0x88, 0x38, 0x1C
    bl GetCellTilemap__C14MineFloorStateUiUi
    .byte 0x01, 0xA9, 0x09, 0x88, 0x72, 0x88, 0x00, 0x90, 0x28, 0x1C, 0x23, 0x1C
    .byte 0x8D, 0xF0, 0x3C, 0xFB, 0x51, 0x46, 0x00, 0x29, 0x0C, 0xD0, 0x09, 0x48, 0x40, 0x44, 0x00, 0x68
    .byte 0x01, 0xA9, 0x09, 0x88, 0xC9, 0x00, 0x08, 0x31, 0x72, 0x88, 0xD2, 0x00, 0x10, 0x32, 0x05, 0x23
    .byte 0x8E, 0xF0, 0xD2, 0xFB, 0x50, 0x46, 0x06, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00
    .byte 0x28, 0x10, 0x00, 0x00
    .Lauto_0801C930:
    movs r0, #0
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .byte 0x00, 0x00
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
    ldr r0, [pc, #0x48]
    add r0, sl
    mov r8, r0
    .Lauto_0801C964:
    movs r5, #0
    adds r7, r1, #1
    movs r0, #0xac
    adds r4, r1, #0
    muls r4, r0, r4
    .Lauto_0801C96E:
    ldr r0, [pc, #0x3c]
    add r0, sb
    ldr r0, [r0]
    ldr r1, [pc, #0x38]
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
    .byte 0x00, 0x00
    .4byte gUnk_080F0800
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
    .global loc_0801C9B4
    .thumb_func
    loc_0801C9B4:
    ldr r4, [pc, #0xb0]
    add r4, sb
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r3, [pc, #0xa4]
    adds r7, r0, r3
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, [pc, #0xa0]
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
    ldr r0, [pc, #0x6c]
    add r0, sb
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, [pc, #0x64]
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
    ldr r2, [pc, #0x30]
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
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xC8, 0x34, 0x00, 0x00
    .4byte gUnk_080F0800
    .byte 0xDD, 0x03, 0x00, 0x00
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
    ldr r0, [pc, #0x60]
    adds r7, r4, r0
    ldr r2, [r7]
    ldr r3, [pc, #0x60]
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
    ldr r1, [pc, #0x30]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
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
    ldr r3, [pc, #0x3c]
    adds r0, r6, r3
    ldr r3, [r0]
    ldr r0, [pc, #0x38]
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
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
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
    ldr r1, [pc, #0x28]
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #1
    bl method_08009B68__4FarmUi
    ldr r2, [pc, #0x1c]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .Lauto_0801CC50:
    ldr r1, [pc, #0x34]
    adds r0, r6, r1
    ldr r0, [r0]
    adds r0, #0x14
    movs r1, #6
    bl method_08009B68__4FarmUi
    ldr r2, [pc, #0x2c]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
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
    ldr r0, [pc, #0x10]
    adds r0, r7, r0
    ldrb r3, [r0]
    adds r0, r5, #0
    bl loc_0801CB50
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b loc_0801CD3E
    .4byte gUnk_080F0800 + 7
    .global loc_0801CCD4
    .thumb_func
    loc_0801CCD4:
    add r4, sp, #0x10
    movs r0, #0
    strb r0, [r4]
    movs r0, #1
    strb r0, [r4, #0x10]
    ldr r0, [pc, #0x24]
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
    .4byte gUnk_080F0800 + 7
    .global loc_0801CD08
    .thumb_func
    loc_0801CD08:
    ldr r1, [pc, #0x14]
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r1, [r4, #8]
    adds r1, #0x10
    ldr r2, [r4, #0xc]
    adds r2, #0x20
    movs r3, #7
    bl func_080AB0C4
    b .Lauto_0801CD38
    .byte 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .global loc_0801CD24
    .thumb_func
    loc_0801CD24:
    ldr r1, [pc, #0x20]
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
    .byte 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
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
    ldr r2, [pc, #0x60]
    adds r7, r0, r2
    ldr r0, [pc, #0x60]
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
    ldr r3, [pc, #0x50]
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
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .4byte gUnk_080F0800 + 7
    .byte 0xDC, 0x09, 0x00, 0x00
    .global loc_0801CDD4
    .thumb_func
    loc_0801CDD4:
    ldr r0, [sp, #0x38]
    ldr r1, [pc, #0xb0]
    adds r4, r0, r1
    ldr r0, [r4]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    mov r8, r0
    ldr r0, [r4]
    ldr r2, [pc, #0xa4]
    adds r7, r0, r2
    movs r5, #0x60
    add r4, sp, #0x1c
    ldr r0, [pc, #0xa0]
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
    ldr r2, [pc, #0x68]
    adds r0, r1, r2
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x14
    ldr r3, [pc, #0x64]
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
    ldr r2, [pc, #0x2c]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0xC8, 0x34, 0x00, 0x00
    .4byte gUnk_080F0800 + 7
    .byte 0xCF, 0x03, 0x00, 0x00
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
    .byte 0x81, 0x46, 0x1B, 0x06, 0x1B, 0x0E, 0x0B, 0x93, 0x2C, 0x4F, 0x57, 0x44, 0x38, 0x68, 0x2C, 0x49
    .byte 0x46, 0x18, 0x10, 0x30, 0xF1, 0xF7, 0x20, 0xFA, 0x80, 0x46, 0x68, 0x78, 0x80, 0x08, 0x69, 0x88
    .byte 0x28, 0x4B, 0x19, 0x40, 0x89, 0x01, 0x01, 0x43, 0x09, 0x04, 0x09, 0x14, 0xEA, 0x78, 0x92, 0x08
    .byte 0xA8, 0x88, 0x18, 0x40, 0x80, 0x01, 0x10, 0x43, 0x00, 0x04, 0x00, 0x14, 0x07, 0xAA, 0x11, 0x80
    .byte 0x50, 0x80, 0x01, 0x31, 0x91, 0x80, 0x01, 0x30, 0xD0, 0x80, 0x29, 0x88, 0x89, 0x05, 0x89, 0x0D
    .byte 0x30, 0x1C, 0x43, 0x46
    bl Find__C14FieldItemStateUiRC3Boxi
    .byte 0x04, 0x1C, 0x01, 0x20, 0x40, 0x42, 0x84, 0x42, 0x56, 0xD0, 0x03, 0xA8, 0x31, 0x1C, 0x22, 0x1C
    bl GetRecord__C14FieldItemStateUi
    .byte 0x03, 0xAE, 0x39, 0x68, 0x08, 0x1C, 0x14, 0x30, 0x12, 0x4A, 0x89, 0x18, 0x0A, 0x9B, 0x00, 0x93
    .byte 0x01, 0xAA, 0x0B, 0xAF, 0x3F, 0x78, 0x17, 0x70, 0x4A, 0x46, 0x02, 0x92, 0x22, 0x1C, 0x43, 0x46
    bl func_080174C8
    .byte 0x4B, 0x46, 0x18, 0x78, 0x00, 0x28, 0x39, 0xD0, 0x28, 0x88, 0x80, 0x05
    .byte 0x80, 0x0D, 0x57, 0x46, 0x79, 0x68, 0x0A, 0x68, 0x0D, 0x1C, 0x90, 0x42, 0x30, 0xD1, 0x58, 0x68
    .byte 0x06, 0x28, 0x15, 0xD0, 0x06, 0x28, 0x09, 0xDC, 0x04, 0x28, 0x0C, 0xD0, 0x2A, 0xE0, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xC8, 0x34, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x07, 0x28, 0x05, 0xD0
    .byte 0x09, 0x28, 0x07, 0xD0, 0x1E, 0xE0, 0x02, 0x23, 0x02, 0x24, 0x05, 0xE0, 0x04, 0x23, 0x02, 0xE0
    .byte 0x04, 0x23, 0x00, 0xE0, 0x06, 0x23, 0x04, 0x24, 0x08, 0x21, 0x70, 0x5E, 0x00, 0x28, 0x00, 0xDA
    .byte 0x07, 0x30, 0xC1, 0x10, 0x0A, 0x22, 0xB0, 0x5E, 0x00, 0x28, 0x00, 0xDA, 0x07, 0x30, 0xC0, 0x10
    .byte 0x09, 0xAA, 0x11, 0x80, 0x50, 0x80, 0x00, 0x94, 0x28, 0x1C, 0x01, 0x21
    bl ClearWorldMapTileRectangle
    .byte 0x01, 0x20, 0x00, 0xE0, 0x00, 0x20, 0x0C, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46
    .byte 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
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
    ldr r0, [pc, #0xb0]
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
    ldr r0, [pc, #0x90]
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
    .byte 0x21, 0x88, 0x89, 0x05, 0x89, 0x0D, 0x04, 0x9A, 0x52, 0x42, 0x09, 0x92, 0x88, 0x42, 0x00, 0xD0
    .byte 0x7C, 0xE0, 0x15, 0x48, 0x40, 0x44, 0x01, 0x68, 0x0B, 0x1C, 0x14, 0x33, 0x05, 0x93, 0x01, 0xA8
    .byte 0x04, 0x89, 0x42, 0x89, 0x80, 0x88, 0x06, 0x90, 0x01, 0xA8, 0xC0, 0x88, 0x10, 0x4B, 0xCB, 0x18
    .byte 0x08, 0x93, 0x02, 0x38, 0x81, 0x46, 0x2B, 0x21, 0x10, 0x1C, 0x48, 0x43, 0x00, 0x19, 0x06, 0x1C
    .byte 0x2B, 0x3E, 0x55, 0x1E, 0x02, 0x22, 0x07, 0x92, 0x00, 0x20, 0x00, 0x2C, 0x06, 0xDB, 0x00, 0x2D
    .byte 0x04, 0xDB, 0x2A, 0x2C, 0x02, 0xDC, 0x18, 0x2D, 0x00, 0xDC, 0x01, 0x20, 0x00, 0x28, 0x09, 0xD0
    .byte 0xB0, 0x00, 0x08, 0x99, 0x0B, 0x18, 0x06, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .byte 0xDC, 0x09, 0x00, 0x00, 0x00, 0x23, 0x1F, 0x1C, 0x00, 0x2F, 0x3E, 0xD0, 0x42, 0x46, 0x52, 0x68
    .byte 0x92, 0x46, 0x05, 0x9B, 0x0C, 0x48, 0x1A, 0x18, 0x2B, 0x1C, 0xB0, 0x00, 0x80, 0x18, 0x84, 0x46
    .byte 0x68, 0x1C, 0x00, 0x21, 0x00, 0x2C, 0x06, 0xDB, 0x00, 0x28, 0x04, 0xDB, 0x2A, 0x2C, 0x02, 0xDC
    .byte 0x18, 0x28, 0x00, 0xDC, 0x01, 0x21, 0x00, 0x29, 0x08, 0xD0, 0x2B, 0x21, 0x48, 0x43, 0x20, 0x18
    .byte 0x80, 0x00, 0x11, 0x18, 0x03, 0xE0, 0x00, 0x00, 0xC8, 0x09, 0x00, 0x00, 0x00, 0x21, 0x58, 0x1E
    .byte 0x00, 0x23, 0x00, 0x2C, 0x06, 0xDB, 0x00, 0x28, 0x04, 0xDB, 0x2A, 0x2C, 0x02, 0xDC, 0x18, 0x28
    .byte 0x00, 0xDC, 0x01, 0x23, 0x00, 0x2B, 0x05, 0xD0, 0x2B, 0x23, 0x58, 0x43, 0x20, 0x18, 0x80, 0x00
    .byte 0x12, 0x18, 0x00, 0xE0, 0x00, 0x22, 0x60, 0x46, 0xED, 0xF7, 0xF4, 0xFE, 0x00, 0x90, 0x50, 0x46
    .byte 0x06, 0x99, 0x4A, 0x46, 0x3B, 0x1C
    bl RefreshFieldPlotTiles
    .byte 0x02, 0x20, 0x81, 0x44, 0x2B, 0x36
    .byte 0x01, 0x35, 0x07, 0x99, 0x01, 0x39, 0x07, 0x91, 0x00, 0x29, 0x9D, 0xDA
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
    ldr r0, [pc, #0xf4]
    add r0, sl
    ldr r0, [r0]
    ldr r2, [pc, #0xf0]
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
    ldr r0, [pc, #0x70]
    add r0, sl
    ldr r0, [r0]
    ldr r3, [pc, #0x6c]
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
    ldr r0, [pc, #0x28]
    add r0, sl
    ldr r0, [r0]
    ldr r6, [pc, #0x24]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
    .Lauto_0801DD64:
    movs r3, #0
    .Lauto_0801DD66:
    adds r6, r3, #0
    cmp r6, #0
    beq .Lauto_0801DDF0
    ldr r0, [pc, #0x38]
    add r0, sl
    ldr r0, [r0]
    ldr r1, [pc, #0x38]
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
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
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
    ldr r1, [pc, #4]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0x68, 0xDE, 0x01, 0x08
    .Lauto_0801DE68:
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x30, 0xE0, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x30, 0xE0, 0x01, 0x08
    .byte 0x30, 0xE0, 0x01, 0x08, 0x30, 0xE0, 0x01, 0x08, 0x30, 0xE0, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x0C, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08, 0x1E, 0xDF, 0x01, 0x08
    .byte 0x1E, 0xDF, 0x01, 0x08
    .Lauto_0801DF0C:
    .byte 0x10, 0x99, 0x13, 0x4A, 0x88, 0x18, 0x00, 0x68, 0x80, 0x68, 0x03, 0x38, 0x01, 0x28, 0x00, 0xD8
    .byte 0x8C, 0xE0
    .Lauto_0801DF1E:
    .byte 0xBA, 0x88, 0x8D, 0x20, 0x80, 0x00, 0x82, 0x42, 0x00, 0xD1, 0x86, 0xE0, 0x10, 0x9B, 0x5D, 0x68
    .byte 0x28, 0x68, 0x82, 0x42, 0x15, 0xD1, 0x68, 0x68, 0x86, 0xF0, 0xCB, 0xF8, 0x05, 0x8C, 0x46, 0x8C
    .byte 0x10, 0x98, 0x44, 0x68, 0x60, 0x68, 0x86, 0xF0, 0xC4, 0xF8, 0x00, 0x22, 0xE0, 0x6A, 0x01, 0xA9
    .byte 0x01, 0x90, 0x02, 0x92, 0x0D, 0x81, 0x4E, 0x81, 0x79, 0x69, 0x06, 0xAC, 0x11, 0xE0, 0x38, 0x10
    .byte 0x00, 0x00, 0x02, 0x2A, 0x1D, 0xD1, 0x01, 0xAB, 0x10, 0x99, 0x0C, 0x4A, 0x88, 0x18, 0x00, 0x68
    .byte 0x80, 0x21, 0x58, 0x22, 0x01, 0x90, 0x00, 0x20, 0x02, 0x90, 0x19, 0x81, 0x5A, 0x81, 0x79, 0x69
    .byte 0x08, 0xAC, 0x20, 0x1C, 0xCA, 0x68, 0x39, 0x1C, 0xB5, 0xF0, 0xA1, 0xF8, 0x01, 0xA8, 0x21, 0x1C
    bl IsMapTerrainBoxBlocked
    .byte 0x00, 0x06, 0x00, 0x28, 0x4B, 0xD0, 0x4E, 0xE0, 0x00, 0x00, 0x50, 0x10
    .byte 0x00, 0x00, 0x01, 0xAB, 0x00, 0x20, 0x80, 0x46, 0x29, 0x49, 0x08, 0x1C, 0x02, 0x40, 0x19, 0x88
    .byte 0x28, 0x4C, 0x20, 0x1C, 0x08, 0x40, 0x10, 0x43, 0x18, 0x80, 0x59, 0x78, 0x03, 0x22, 0x10, 0x1C
    .byte 0x08, 0x40, 0x58, 0x70, 0x59, 0x88, 0x20, 0x1C, 0x08, 0x40, 0x58, 0x80, 0xD8, 0x78, 0x02, 0x40
    .byte 0xDA, 0x70, 0x98, 0x88, 0x04, 0x40, 0x9C, 0x80, 0x1E, 0x20, 0x00, 0x90, 0x28, 0x1C, 0x19, 0x1C
    .byte 0x03, 0x22, 0x00, 0x23
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    .byte 0x01, 0x22, 0x11, 0x92, 0x10, 0x9B, 0x58, 0x68
    .byte 0x40, 0x68, 0x86, 0xF0, 0x6E, 0xF8, 0x05, 0x8C, 0x46, 0x8C, 0x10, 0x98, 0x44, 0x68, 0x60, 0x68
    .byte 0x86, 0xF0, 0x67, 0xF8, 0xE0, 0x6A, 0x01, 0xA9, 0x01, 0x90, 0x42, 0x46, 0x02, 0x92, 0x0D, 0x81
    .byte 0x4E, 0x81, 0x79, 0x69, 0x0A, 0xAC, 0x20, 0x1C, 0xCA, 0x68, 0x39, 0x1C, 0xB5, 0xF0, 0x57, 0xF8
    .byte 0x01, 0xA8, 0x21, 0x1C
    bl IsMapTerrainBoxBlocked
    .byte 0x00, 0x06, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x23
    .byte 0x9A, 0x46
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
    ldr r1, [pc, #0xc]
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .byte 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x58, 0xE0, 0x01, 0x08, 0xFC, 0xE0, 0x01, 0x08
    .byte 0x44, 0xE1, 0x01, 0x08, 0xC4, 0xE3, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08
    .byte 0x70, 0xE1, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08
    .byte 0x70, 0xE1, 0x01, 0x08, 0x70, 0xE1, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08
    .byte 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08
    .byte 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08
    .byte 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08
    .byte 0x80, 0xE2, 0x01, 0x08, 0x80, 0xE2, 0x01, 0x08, 0xC4, 0xE3, 0x01, 0x08, 0xC4, 0xE3, 0x01, 0x08
    .byte 0xC4, 0xE3, 0x01, 0x08, 0xC4, 0xE3, 0x01, 0x08, 0x98, 0xE3, 0x01, 0x08, 0xA6, 0xE3, 0x01, 0x08
    .byte 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08
    .byte 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08, 0x50, 0xE2, 0x01, 0x08
    .byte 0x00, 0x2F, 0x00, 0xD1, 0x60, 0xE1, 0x04, 0xA9, 0x02, 0x23, 0x0A, 0x88, 0x0D, 0x4C, 0x20, 0x1C
    .byte 0x10, 0x40, 0x18, 0x43, 0x08, 0x80, 0xF8, 0x25, 0x4B, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40
    .byte 0x28, 0x43, 0x48, 0x70, 0x05, 0x25, 0x4B, 0x88, 0x20, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x80
    .byte 0xC8, 0x78, 0x02, 0x40, 0x48, 0x20, 0x02, 0x43, 0xCA, 0x70, 0x01, 0x22, 0x88, 0x88, 0x04, 0x40
    .byte 0x14, 0x43, 0x1C, 0xE1, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x2F, 0x00, 0xD1, 0x3C, 0xE1, 0x03, 0xA9
    .byte 0x02, 0x26, 0x0A, 0x88, 0x06, 0x4C, 0x20, 0x1C, 0x10, 0x40, 0x30, 0x43, 0x08, 0x80, 0xC0, 0x25
    .byte 0x4B, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x70, 0x0B, 0x25, 0xF9, 0xE0
    .byte 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x2F, 0x00, 0xD1, 0x26, 0xE1, 0xB9, 0x88, 0x11, 0x29, 0x03, 0xD0
    .byte 0x8D, 0x20, 0x80, 0x00, 0x81, 0x42, 0x45, 0xD1, 0x4A, 0x46, 0x2E, 0x3A, 0x10, 0x99, 0x1F, 0x4B
    .byte 0xC8, 0x18, 0x01, 0x68, 0x82, 0x20, 0xC0, 0x00, 0x09, 0x18, 0x0C, 0xA8, 0xEE, 0xF7, 0x9A, 0xFA
    .byte 0x0C, 0x98, 0x0D, 0x90, 0x0D, 0xA8, 0x00, 0x21, 0x46, 0x5E, 0x02, 0x23, 0xC2, 0x5E, 0x90, 0x46
    .byte 0x03, 0xA9, 0x11, 0x23, 0x0A, 0x88, 0x16, 0x4D, 0x28, 0x1C, 0x10, 0x40, 0x18, 0x43, 0x08, 0x80
    .byte 0x36, 0x04, 0x32, 0x0C, 0x3F, 0x20, 0x81, 0x46, 0x02, 0x40, 0x92, 0x00, 0x4C, 0x78, 0x03, 0x23
    .byte 0x18, 0x1C, 0x20, 0x40, 0x10, 0x43, 0x48, 0x70, 0xB6, 0x0D, 0x4A, 0x88, 0x28, 0x1C, 0x10, 0x40
    .byte 0x30, 0x43, 0x48, 0x80, 0x42, 0x46, 0x12, 0x04, 0x90, 0x46, 0x10, 0x0C, 0x4A, 0x46, 0x10, 0x40
    .byte 0x80, 0x00, 0xCA, 0x78, 0x13, 0x40, 0x03, 0x43, 0xCB, 0x70, 0x43, 0x46, 0x9B, 0x0D, 0x88, 0x88
    .byte 0x05, 0x40, 0x1D, 0x43, 0x8D, 0x80, 0x01, 0xAD, 0x01, 0x24, 0xBB, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0x00, 0xFC, 0xFF, 0xFF, 0x03, 0xA9, 0x02, 0x25, 0x0A, 0x88, 0x0D, 0x4C, 0x20, 0x1C, 0x10, 0x40
    .byte 0x28, 0x43, 0x08, 0x80, 0x4A, 0x78, 0x03, 0x23, 0x18, 0x1C, 0x10, 0x40, 0x3C, 0x22, 0x10, 0x43
    .byte 0x48, 0x70, 0x4A, 0x88, 0x20, 0x1C, 0x10, 0x40, 0x28, 0x43, 0x48, 0x80, 0xC8, 0x78, 0x03, 0x40
    .byte 0x30, 0x20, 0x03, 0x43, 0xCB, 0x70, 0x08, 0x22, 0x88, 0x88, 0x04, 0x40, 0x14, 0x43, 0x96, 0xE0
    .byte 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x2F, 0x00, 0xD1, 0xB6, 0xE0, 0x10, 0x99, 0x08, 0x68, 0xC2, 0x6B
    .byte 0x08, 0x1C, 0x49, 0x46, 0xB4, 0xF0, 0x34, 0xFF, 0x10, 0x9A, 0x05, 0x4B, 0xD0, 0x18, 0x00, 0x68
    .byte 0x82, 0x21, 0xC9, 0x00, 0x40, 0x18, 0x49, 0x46, 0x4C, 0x39, 0xEE, 0xF7, 0x8F, 0xFB, 0xA3, 0xE0
    .byte 0x38, 0x10, 0x00, 0x00, 0x00, 0x2F, 0x00, 0xD1, 0x9E, 0xE0, 0xB9, 0x88, 0x25, 0x29, 0x03, 0xD0
    .byte 0x8D, 0x20, 0x80, 0x00, 0x81, 0x42, 0x55, 0xD1, 0x36, 0x22, 0x52, 0x42, 0x4A, 0x44, 0x92, 0x46
    .byte 0x10, 0x9B, 0x26, 0x49, 0x58, 0x18, 0x01, 0x68, 0xBE, 0x22, 0xD2, 0x00, 0x89, 0x18, 0x0E, 0xA8
    .byte 0x52, 0x46, 0xEE, 0xF7, 0xD1, 0xFE, 0x0E, 0x98, 0x0F, 0x90, 0x0F, 0xA8, 0x00, 0x23, 0xC6, 0x5E
    .byte 0x02, 0x22, 0x81, 0x5E, 0x88, 0x46, 0x03, 0xA9, 0x25, 0x23, 0x0A, 0x88, 0x1C, 0x4D, 0x28, 0x1C
    .byte 0x10, 0x40, 0x18, 0x43, 0x08, 0x80, 0x36, 0x04, 0x32, 0x0C, 0x3F, 0x23, 0x99, 0x46, 0x1A, 0x40
    .byte 0x92, 0x00, 0x4C, 0x78, 0x03, 0x23, 0x18, 0x1C, 0x20, 0x40, 0x10, 0x43, 0x48, 0x70, 0xB6, 0x0D
    .byte 0x4A, 0x88, 0x28, 0x1C, 0x10, 0x40, 0x30, 0x43, 0x48, 0x80, 0x40, 0x46, 0x00, 0x04, 0x80, 0x46
    .byte 0x00, 0x0C, 0x4A, 0x46, 0x10, 0x40, 0x80, 0x00, 0xCA, 0x78, 0x13, 0x40, 0x03, 0x43, 0xCB, 0x70
    .byte 0x43, 0x46, 0x9B, 0x0D, 0x88, 0x88, 0x05, 0x40, 0x1D, 0x43, 0x8D, 0x80, 0x50, 0x46, 0x80, 0x08
    .byte 0x82, 0x46, 0x01, 0x20, 0x52, 0x46, 0x02, 0x40, 0x92, 0x46, 0x01, 0xAC, 0x20, 0x1C, 0x06, 0x22
    .byte 0xB4, 0xF0, 0x0E, 0xFF, 0x53, 0x46, 0xA3, 0x71, 0x29, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0x00, 0xFC, 0xFF, 0xFF, 0x03, 0xA9, 0x02, 0x26, 0x0A, 0x88, 0x13, 0x4C, 0x20, 0x1C, 0x10, 0x40
    .byte 0x30, 0x43, 0x08, 0x80, 0xE0, 0x25, 0x4B, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40, 0x28, 0x43
    .byte 0x48, 0x70, 0x07, 0x25, 0x4B, 0x88, 0x20, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x80, 0xC8, 0x78
    .byte 0x02, 0x40, 0x10, 0x20, 0x02, 0x43, 0xCA, 0x70, 0x88, 0x88, 0x04, 0x40, 0x34, 0x43, 0x8C, 0x80
    .byte 0x01, 0xAD, 0x00, 0x24, 0x28, 0x1C, 0x06, 0x22, 0xB4, 0xF0, 0xE2, 0xFE, 0xAC, 0x71, 0x38, 0x1C
    .byte 0x01, 0xA9, 0x13, 0xF0, 0x8F, 0xFD, 0x17, 0xE0, 0x00, 0xFC, 0xFF, 0xFF, 0x38, 0x1C, 0x02, 0x21
    .byte 0xE0, 0x22, 0xA8, 0x23, 0x01, 0xF0, 0x34, 0xFC, 0x0E, 0xE0, 0x10, 0x99, 0x08, 0x68, 0xC2, 0x6B
    .byte 0x08, 0x1C, 0x49, 0x46, 0xB4, 0xF0, 0x8C, 0xFE, 0x10, 0x9A, 0x14, 0x4B, 0xD0, 0x18, 0x00, 0x68
    .byte 0x13, 0x49, 0x40, 0x18, 0xF0, 0xF7, 0xA4, 0xFC
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
    ldr r1, [pc, #0x28]
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, [pc, #0x28]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00, 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46
    .byte 0xE0, 0xB4, 0x86, 0xB0, 0x07, 0x1C, 0x78, 0x68, 0x40, 0x68, 0x2A, 0x28, 0x0E, 0xD0, 0x2A, 0x28
    .byte 0x02, 0xDC, 0x29, 0x28, 0x03, 0xD0, 0x2C, 0xE1, 0x2B, 0x28, 0x0B, 0xD0, 0x29, 0xE1, 0x02, 0x49
    .byte 0x05, 0x91, 0x05, 0x21, 0x09, 0xE0, 0x00, 0x00
    .4byte gUnk_080F0704
    .byte 0x00, 0x49, 0x02, 0xE0
    .4byte gUnk_080F0718
    .byte 0x14, 0x49, 0x05, 0x91, 0x06, 0x21, 0x8A, 0x46, 0x85, 0xF0, 0x3C, 0xFE, 0x05, 0x8C, 0x46, 0x8C
    .byte 0x7C, 0x68, 0x60, 0x68, 0x85, 0xF0, 0x36, 0xFE, 0x00, 0x22, 0xE0, 0x6A, 0x69, 0x46, 0x00, 0x90
    .byte 0x01, 0x92, 0x0D, 0x81, 0x4E, 0x81, 0x90, 0x46, 0x46, 0x46, 0x38, 0x68, 0x02, 0x6C, 0x38, 0x1C
    .byte 0x41, 0x46, 0xB4, 0xF0, 0x25, 0xFE, 0x05, 0x1C, 0x00, 0x2D, 0x00, 0xD1, 0xF9, 0xE0, 0x00, 0x20
    .byte 0x81, 0x46, 0x40, 0x46, 0x2B, 0x38, 0x28, 0x28, 0x6D, 0xD8, 0x80, 0x00, 0x02, 0x49, 0x40, 0x18
    .byte 0x00, 0x68, 0x87, 0x46
    .4byte gUnk_080F0730
    .byte 0xA8, 0xE4, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08
    .byte 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08
    .byte 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08, 0x72, 0xE5, 0x01, 0x08
    .byte 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08
    .byte 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08
    .byte 0x4C, 0xE5, 0x01, 0x08, 0x4C, 0xE5, 0x01, 0x08, 0xA8, 0x88, 0x1D, 0x28, 0x0F, 0xD1, 0x69, 0x69
    .byte 0x03, 0xAC, 0x20, 0x1C, 0xCA, 0x68, 0x29, 0x1C, 0xB4, 0xF0, 0xB6, 0xFD, 0x68, 0x46, 0x21, 0x1C
    bl IsMapTerrainBoxBlocked
    .byte 0x00, 0x06, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x21, 0x89, 0x46, 0x48, 0x46
    .byte 0x00, 0x28, 0x00, 0xD1, 0x81, 0xE0, 0x30, 0x1C, 0x2B, 0x38, 0x28, 0x28, 0x58, 0xD8, 0x80, 0x00
    .byte 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x90, 0xE5, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08, 0x34, 0xE6, 0x01, 0x08
    .byte 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08
    .byte 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08, 0x5A, 0xE6, 0x01, 0x08
    .byte 0x00, 0x2D, 0x22, 0xD0, 0xB2, 0xF0, 0xB0, 0xF9, 0x51, 0x46, 0xB2, 0xF0, 0x62, 0xF8, 0x80, 0x00
    .byte 0x05, 0x99, 0x08, 0x18, 0x00, 0x21, 0x42, 0x5E, 0x02, 0x21, 0x43, 0x5E, 0x28, 0x1C, 0x1D, 0x21
    .byte 0x01, 0xF0, 0xDA, 0xFA, 0x11, 0xE0, 0x00, 0x2D, 0x0F, 0xD0, 0x38, 0x68, 0xC2, 0x6B, 0x38, 0x1C
    .byte 0x31, 0x1C, 0xB4, 0xF0, 0x31, 0xFD, 0x0C, 0x49, 0x78, 0x18, 0x00, 0x68, 0x82, 0x21, 0xC9, 0x00
    .byte 0x40, 0x18, 0x31, 0x1C, 0x4C, 0x39, 0xEE, 0xF7, 0x8D, 0xF9, 0x01, 0x20, 0x80, 0x44, 0x41, 0x46
    .byte 0x63, 0x29, 0x00, 0xDC, 0xF4, 0xE6, 0x06, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46
    .byte 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
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
    .byte 0x60, 0x88, 0x00, 0x04, 0xC0, 0x14, 0x16, 0x38, 0x40, 0x10, 0x0A, 0x90, 0x0A, 0xA9, 0x09, 0xAA
    .byte 0x85, 0x42, 0x00, 0xDA, 0x0A, 0x1C, 0x14, 0x68, 0x18, 0x21, 0x0B, 0x91, 0x06, 0x22, 0xB0, 0x5E
    .byte 0x01, 0x38, 0xC0, 0x10, 0x16, 0x38, 0x40, 0x10, 0x0C, 0x90, 0x0C, 0xAA, 0x0B, 0xAB, 0x81, 0x42
    .byte 0x00, 0xDD, 0x13, 0x1C, 0x1A, 0x68, 0x21, 0x1C, 0x91, 0x42, 0x23, 0xDC, 0x48, 0x46, 0x83, 0x00
    .byte 0x4C, 0x46, 0x4E, 0x1C, 0xBC, 0x42, 0x1A, 0xDC, 0xAC, 0x20, 0x48, 0x43, 0x1D, 0x18, 0x1B, 0x48
    .byte 0x40, 0x44, 0x00, 0x68, 0x1A, 0x49, 0x40, 0x18, 0x41, 0x19, 0x08, 0x68, 0x00, 0x06, 0x80, 0x0E
    .byte 0x15, 0x28, 0x08, 0xD1, 0x68, 0x46, 0x0E, 0x92, 0x0F, 0x93, 0xEB, 0xF7, 0x8B, 0xFE, 0x01, 0x20
    .byte 0x0D, 0x90, 0x0F, 0x9B, 0x0E, 0x9A, 0x04, 0x35, 0x01, 0x34, 0xBC, 0x42, 0xE7, 0xDD, 0x31, 0x1C
    .byte 0x91, 0x42, 0xDD, 0xDD
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
    ldr r0, [pc, #0x20]
    add r0, r8
    ldr r1, [r0]
    ldr r0, [pc, #0x1c]
    add r0, r8
    ldrb r2, [r0]
    movs r3, #0x1e
    subs r3, r3, r2
    ldr r4, [r4, #0x14]
    adds r0, r5, #0
    bl _call_via_r4
    b .Lauto_0801E81A
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00, 0x48, 0x10, 0x00, 0x00, 0x4C, 0x10, 0x00, 0x00
    .Lauto_0801E7F4:
    ldr r0, [pc, #0x34]
    add r0, r8
    ldr r5, [r0]
    ldr r0, [pc, #0x34]
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
    .byte 0x00, 0x00, 0x50, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .global func_0801EAA0
    .thumb_func
func_0801EAA0:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [pc, #0x104]
    add sp, r4
    adds r7, r0, #0
    str r1, [sp, #0x330]
    ldr r1, [pc, #0x100]
    adds r0, r7, r1
    ldr r0, [r0]
    adds r0, #0x12
    str r0, [sp, #0x334]
    ldr r3, [pc, #0xf8]
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
    ldr r2, [pc, #0xa4]
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
    ldr r4, [pc, #0x60]
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
    .byte 0xB0, 0xFC, 0xFF, 0xFF, 0x38, 0x10, 0x00, 0x00, 0x3C, 0x10, 0x00, 0x00
    .4byte gUnk_080F0748
    .4byte gUnk_080F0770
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
    ldr r5, [pc, #0x1e4]
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
    .byte 0x19, 0x68, 0xC9, 0x02, 0xC9, 0x0E, 0x01, 0x31, 0x1F, 0x24, 0xA4, 0x46, 0x65, 0x46, 0x29, 0x40
    .byte 0x9A, 0x78, 0x20, 0x24, 0x64, 0x42, 0x20, 0x1C, 0x10, 0x40, 0x08, 0x43, 0x98, 0x70, 0x17, 0x29
    .byte 0x5E, 0xD9, 0x31, 0x68, 0x8A, 0x78, 0x20, 0x1C, 0x10, 0x40, 0x88, 0x70, 0x33, 0x68, 0x5A, 0x78
    .byte 0x50, 0x06, 0xC0, 0x0E, 0x01, 0x30, 0x1E, 0x28, 0x1B, 0xD1, 0x90, 0x07, 0x80, 0x0F, 0x51, 0x46
    .byte 0x08, 0x40, 0x04, 0x21, 0x49, 0x42, 0xD2, 0xAC, 0x24, 0x78, 0x21, 0x40, 0x01, 0x43, 0x01, 0x30
    .byte 0x55, 0x46, 0x28, 0x40, 0x04, 0x24, 0x64, 0x42, 0x21, 0x40, 0x01, 0x43, 0xD2, 0xAD, 0x29, 0x70
    .byte 0x89, 0x07, 0x89, 0x0F, 0x50, 0x46, 0x01, 0x40, 0x20, 0x1C, 0x10, 0x40, 0x08, 0x43, 0x58, 0x70
    .byte 0x00, 0x20, 0x61, 0x46, 0x08, 0x40, 0x82, 0x00, 0x59, 0x78, 0x7D, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x10, 0x43, 0x58, 0x70, 0xD3, 0xAB, 0x18, 0x78, 0x04, 0x23, 0x5B, 0x42, 0x18, 0x40, 0x7D, 0x24
    .byte 0x64, 0x42, 0x20, 0x40, 0xD3, 0xAD, 0x28, 0x70, 0x32, 0x68, 0x00, 0x23, 0x51, 0x78, 0x7F, 0x20
    .byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD1, 0x01, 0x23, 0x00, 0x2B, 0x19, 0xD0, 0x14, 0x1C, 0x23, 0x78
    .byte 0x58, 0x07, 0x40, 0x0F, 0x42, 0x1C, 0x06, 0x2A, 0x09, 0xD9, 0x00, 0x22, 0xD9, 0x08, 0x1C, 0x29
    .byte 0x05, 0xD8, 0x01, 0x31, 0xC9, 0x00, 0x07, 0x20, 0x18, 0x40, 0x08, 0x43, 0x20, 0x70, 0x07, 0x20
    .byte 0x02, 0x40, 0x20, 0x78, 0x08, 0x23, 0x5B, 0x42, 0x19, 0x1C, 0x08, 0x40, 0x10, 0x43, 0x20, 0x70
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
    ldr r0, [pc, #0xbc]
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
    .byte 0x02, 0x68, 0xD1, 0x02, 0xC9, 0x0E, 0x52, 0x01, 0x92, 0x0E, 0x38, 0x1C, 0x00, 0x23
    bl UpdateWorldTimeOfDayPalettes

    .Lauto_0801EB36:
    ldr r0, [r7, #8]
    ldr r1, [r0, #0x14]
    adds r1, #0xa4
    ldr r1, [r1]
    bl _call_via_r1
    ldr r5, [pc, #0x44]
    adds r0, r7, r5
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .Lauto_0801EB6C
    ldr r1, [pc, #0x38]
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r3, [pc, #0x34]
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
    .byte 0x1F, 0xF8, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x54, 0x10, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0x4C, 0x21, 0x00, 0x00
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
    .byte 0x48, 0x78, 0x80, 0x08, 0x49, 0x88, 0x24, 0x4B, 0x19, 0x40, 0x89, 0x01, 0x01, 0x43, 0x09, 0x04
    .byte 0x09, 0x14, 0x4A, 0x46, 0xD0, 0x78, 0x80, 0x08, 0x92, 0x88, 0x1A, 0x40, 0x92, 0x01, 0x02, 0x43
    .byte 0x12, 0x04, 0x12, 0x14, 0x03, 0xA8
    bl IsMapTerrainFlag1Footprint
    .byte 0x01, 0x21, 0x48, 0x40, 0x00, 0x06
    .byte 0x00, 0x0E, 0x0B, 0x90, 0x00, 0x23, 0x0C, 0x93, 0x01, 0x26, 0x6C, 0x46, 0x28, 0x34, 0x0E, 0x94
    .byte 0x68, 0x46, 0x08, 0x30, 0x0D, 0x90, 0x0B, 0x99, 0x00, 0x29, 0x00, 0xD0, 0x98, 0xE0, 0x52, 0x46
    .byte 0x10, 0x68, 0xA6, 0x23, 0x5B, 0x00, 0xC0, 0x18, 0x01, 0x68, 0x50, 0x46, 0xB4, 0xF0, 0x56, 0xFA
    .byte 0x04, 0x68, 0x45, 0x68, 0xAC, 0x42, 0x08, 0xD0, 0x20, 0x68
    bl IsActive__C23HardwareMusicPlayerSlot
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x13, 0xD0, 0x04, 0x34, 0xAC, 0x42, 0xF6, 0xD1, 0x28, 0x1F, 0x00, 0x68, 0x6D, 0x21
    bl Start__23HardwareMusicPlayerSlotUs
    .byte 0x48, 0x46, 0x85, 0xF0, 0xCD, 0xF9, 0x02, 0x28, 0x60, 0xD0, 0x02, 0x28
    .byte 0x06, 0xDC, 0x00, 0x28, 0x62, 0xD0, 0x73, 0xE0, 0xFF, 0x03, 0x00, 0x00, 0x20, 0x68, 0xEE, 0xE7
    .byte 0x04, 0x28, 0x02, 0xD0, 0x06, 0x28, 0x17, 0xD0, 0x6A, 0xE0, 0x38, 0x1C, 0xF0, 0xF7, 0x08, 0xFA
    .byte 0x00, 0x28, 0x65, 0xD1, 0x03, 0xA8, 0x39, 0x1C, 0xF0, 0xF7, 0x06, 0xFA, 0x03, 0xA8, 0xEF, 0xF7
    .byte 0x0B, 0xF8, 0xA0, 0x28, 0x5C, 0xD1, 0x03, 0x48, 0x50, 0x44, 0x00, 0x68
    bl SetFlag4__18GameStateSaveImage
    .byte 0x56, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x00, 0x25, 0x38, 0x1C, 0xF0, 0xF7, 0xF0, 0xF9
    .byte 0x00, 0x28, 0x13, 0xD1, 0x03, 0xA8, 0x39, 0x1C, 0xF0, 0xF7, 0xEE, 0xF9, 0x03, 0xA8, 0xEE, 0xF7
    .byte 0xF3, 0xFF, 0x0E, 0x28, 0x0A, 0xDD, 0x04, 0xAC, 0x20, 0x1C, 0x39, 0x1C, 0xF0, 0xF7, 0xE4, 0xF9
    .byte 0x20, 0x1C, 0xEE, 0xF7, 0xE9, 0xFF, 0x14, 0x28, 0x00, 0xDC, 0x01, 0x25, 0x00, 0x2D, 0x37, 0xD0
    .byte 0x54, 0x46, 0xA6, 0x68, 0x70, 0x69, 0x80, 0x46, 0x05, 0xAD, 0x06, 0xAC, 0x20, 0x1C, 0x15, 0x21
    .byte 0xEE, 0xF7, 0xD4, 0xFF, 0x21, 0x78, 0x68, 0x46, 0x19, 0x30, 0x00, 0x78, 0x00, 0x02, 0x08, 0x43
    .byte 0x69, 0x46, 0x1A, 0x31, 0x09, 0x78, 0x09, 0x04, 0x01, 0x43, 0x28, 0x1C, 0xF0, 0xF7, 0x74, 0xF9
    .byte 0x41, 0x46, 0xCB, 0x6D, 0x30, 0x1C, 0x29, 0x1C, 0x00, 0x22, 0xB4, 0xF0, 0xE3, 0xF9, 0x16, 0xE0
    .byte 0x01, 0x4A, 0x0C, 0x92, 0x13, 0xE0, 0x00, 0x00, 0x3B, 0x02, 0x00, 0x00, 0x38, 0x1C, 0xF0, 0xF7
    .byte 0xAF, 0xF9, 0x00, 0x28, 0x0C, 0xD1, 0x03, 0xA8, 0x39, 0x1C, 0xF0, 0xF7, 0xAD, 0xF9, 0x03, 0xA8
    .byte 0xEE, 0xF7, 0xB2, 0xFF, 0x02, 0x28, 0x03, 0xD1, 0x8F, 0x23, 0x9B, 0x00, 0x0C, 0x93, 0x00, 0x26
    .byte 0x0C, 0x9C, 0x00, 0x2C, 0x0C, 0xD0, 0x51, 0x46, 0x08, 0x68, 0xA0, 0x22, 0x52, 0x00, 0x80, 0x18
    .byte 0x07, 0xA9, 0x00, 0x22, 0x07, 0x94, 0x4A, 0x60, 0x03, 0x68, 0x50, 0x46, 0xB4, 0xF0, 0xBA, 0xF9
    .byte 0x00, 0x2E, 0x09, 0xD0, 0x0F, 0x48, 0x50, 0x44, 0x02, 0x68, 0x0F, 0x4B, 0xD0, 0x18, 0x0F, 0x4C
    .byte 0x12, 0x19, 0x49, 0x46, 0x82, 0xF0, 0xA4, 0xF8, 0x38, 0x1C, 0xF0, 0xF7, 0xC1, 0xF9, 0x00, 0x06
    .byte 0x00, 0x28, 0x2E, 0xD1, 0x38, 0x1C, 0xF0, 0xF7, 0x7B, 0xF9, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x28
    .byte 0x0E, 0xD0, 0x03, 0xA8, 0x39, 0x1C, 0xF0, 0xF7, 0x77, 0xF9, 0x03, 0xA8, 0xEE, 0xF7, 0x92, 0xFF
    .byte 0x13, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x4C, 0x21, 0x00, 0x00
    .byte 0x38, 0x1C, 0xF0, 0xF7, 0x8B, 0xF9, 0x09, 0xAC, 0x20, 0x70, 0x20, 0x1C, 0xEF, 0xF7, 0xBC, 0xF8
    .byte 0x1B, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xEF, 0xF7, 0xCF, 0xF8, 0x00, 0x04, 0x05, 0x0C, 0x0A, 0xE0
    .byte 0x49, 0x46, 0x08, 0x88, 0x80, 0x05, 0x80, 0x0D, 0x03, 0x25, 0x08, 0x28, 0x03, 0xDC, 0x04, 0x25
    .byte 0x01, 0xE0, 0xB0, 0x25, 0x6D, 0x00, 0x4A, 0x46, 0x50, 0x78, 0x80, 0x08, 0x52, 0x88, 0x28, 0x4B
    .byte 0x1A, 0x40, 0x92, 0x01, 0x02, 0x43, 0x4C, 0x46, 0xE1, 0x78, 0x89, 0x08, 0xA0, 0x88, 0x18, 0x40
    .byte 0x80, 0x01, 0x08, 0x43, 0x00, 0x04, 0x00, 0x14, 0x0A, 0xA9, 0x0A, 0x80, 0x0E, 0x99, 0x48, 0x80
    .byte 0x52, 0x46, 0x10, 0x68, 0x41, 0x6E, 0x50, 0x46, 0xB4, 0xF0, 0x58, 0xF9, 0x1D, 0x4C, 0x54, 0x44
    .byte 0x06, 0x1C, 0x2F, 0x1C, 0x0A, 0x98, 0x60, 0x60, 0x00, 0x25, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0
    .byte 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB4, 0xF0, 0x48, 0xF9
    .byte 0x25, 0x60, 0x0B, 0xAB, 0x1B, 0x78, 0x23, 0x72, 0x0B, 0x9D, 0x00, 0x2D, 0x24, 0xD0, 0x40, 0x20
    bl __builtin_new
    .byte 0x02, 0x21, 0x00, 0x91, 0x03, 0x21, 0x01, 0x91, 0x00, 0x21, 0x0D, 0x9A
    .byte 0x11, 0x70, 0x31, 0x1C, 0x3A, 0x1C, 0x53, 0x46
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x05, 0x1C, 0x21, 0x68
    .byte 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
    .byte 0xB4, 0xF0, 0x26, 0xF9, 0x25, 0x60, 0x00, 0x21, 0x10, 0x20, 0x60, 0x72, 0xA1, 0x72, 0x1F, 0xE0
    .byte 0xFF, 0x03, 0x00, 0x00, 0x2C, 0x10, 0x00, 0x00, 0x40, 0x20
    bl __builtin_new
    .byte 0x02, 0x21
    .byte 0x00, 0x91, 0x03, 0x21, 0x01, 0x91, 0x0D, 0x9B, 0x1D, 0x70, 0x31, 0x1C, 0x0C, 0x4A, 0x53, 0x46
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x05, 0x1C, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0
    .byte 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB4, 0xF0, 0x02, 0xF9, 0x25, 0x60, 0x00, 0x20
    .byte 0x0F, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
    .byte 0xA9, 0x01, 0x00, 0x00
    .byte 0x70, 0xB5, 0x83, 0xB0, 0x06, 0x1C, 0x83, 0x20, 0x40, 0x01, 0x31, 0x18, 0x00, 0x20, 0x08, 0x70
    .byte 0x0E, 0x49, 0x74, 0x18, 0x00, 0x25, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0
    .byte 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB4, 0xF0, 0xE0, 0xF8, 0x25, 0x60, 0x30, 0x68
    .byte 0x41, 0x69, 0x30, 0x1C, 0xB4, 0xF0, 0xD8, 0xF8, 0x0A, 0x38, 0x1D, 0x28, 0x00, 0xD9, 0x9E, 0xE0
    .byte 0x80, 0x00, 0x03, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .byte 0x34, 0xEF, 0x01, 0x08, 0x00, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0xDC, 0xEF, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x00, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0xAC, 0xEF, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08
    .byte 0x5E, 0xF0, 0x01, 0x08, 0x5E, 0xF0, 0x01, 0x08, 0xEC, 0xEF, 0x01, 0x08, 0x0A, 0x48, 0x34, 0x18
    .byte 0x20, 0x68, 0xFA, 0x21, 0x49, 0x00, 0x40, 0x18, 0xEC, 0xF7, 0x9C, 0xFF, 0x02, 0x28, 0x4E, 0xD1
    .byte 0x20, 0x68, 0xFA, 0x21, 0x49, 0x00, 0x40, 0x18, 0xEC, 0xF7, 0xEC, 0xFF, 0x00, 0x06, 0x00, 0x0E
    .byte 0x41, 0x42, 0x01, 0x43, 0xCD, 0x0F, 0x1D, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x02, 0x49, 0x70, 0x18
    .byte 0x00, 0x68, 0xC0, 0x78, 0xC5, 0x09, 0x15, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x03, 0x49, 0x70, 0x18
    .byte 0x00, 0x68, 0x00, 0x79, 0xC0, 0x07, 0xC5, 0x0F, 0x0C, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0x19, 0x49, 0x70, 0x18, 0x00, 0x68, 0x10, 0x30, 0xEF, 0xF7, 0x7C, 0xF9, 0x00, 0x25, 0x03, 0x28
    .byte 0x00, 0xD1, 0x01, 0x25, 0x40, 0x20
    bl __builtin_new
    .byte 0x04, 0x1C, 0x30, 0x68, 0x01, 0x6E
    .byte 0x30, 0x1C, 0xB4, 0xF0, 0x51, 0xF8, 0x01, 0x1C, 0x02, 0x20, 0x00, 0x90, 0x1B, 0x20, 0x01, 0x90
    .byte 0x02, 0xAA, 0x00, 0x20, 0x10, 0x70, 0x20, 0x1C, 0x2A, 0x1C, 0x33, 0x1C
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x0A, 0x49, 0x75, 0x18, 0x04, 0x1C, 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0
    .byte 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB4, 0xF0, 0x38, 0xF8, 0x2C, 0x60, 0x03, 0xB0
    .byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x5C, 0x10, 0x00, 0x00
    .byte 0x30, 0xB5, 0x83, 0xB0, 0x04, 0x1C, 0x20, 0x68, 0x41, 0x69, 0x20, 0x1C, 0xB4, 0xF0, 0x24, 0xF8
    .byte 0x23, 0x28, 0x63, 0xD1, 0x0B, 0x49, 0x60, 0x18, 0x00, 0x68, 0x80, 0x7C, 0xC0, 0x06, 0xC0, 0x0E
    .byte 0x03, 0x28, 0x37, 0xD9, 0x08, 0x28, 0x11, 0xD8, 0x40, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A
    .byte 0xA1, 0x18, 0x05, 0x22, 0x00, 0x92, 0x1B, 0x22, 0x01, 0x92, 0x02, 0xAB, 0x00, 0x22, 0x1A, 0x70
    .byte 0x00, 0x22, 0x34, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xF4, 0x0F, 0x00, 0x00, 0x0F, 0x28, 0x0F, 0xD8
    .byte 0x40, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xA1, 0x18, 0x05, 0x22, 0x00, 0x92, 0x1B, 0x22
    .byte 0x01, 0x92, 0x02, 0xAB, 0x00, 0x22, 0x1A, 0x70, 0x01, 0x22, 0x20, 0xE0, 0xF4, 0x0F, 0x00, 0x00
    .byte 0x12, 0x28, 0x0F, 0xD8, 0x40, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xA1, 0x18, 0x05, 0x22
    .byte 0x00, 0x92, 0x1B, 0x22, 0x01, 0x92, 0x02, 0xAB, 0x00, 0x22, 0x1A, 0x70, 0x02, 0x22, 0x0E, 0xE0
    .byte 0xF4, 0x0F, 0x00, 0x00, 0x40, 0x20
    bl __builtin_new
    .byte 0x0E, 0x4A, 0xA1, 0x18, 0x05, 0x22
    .byte 0x00, 0x92, 0x1B, 0x22, 0x01, 0x92, 0x02, 0xAB, 0x00, 0x22, 0x1A, 0x70, 0x03, 0x22, 0x23, 0x1C
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x08, 0x49, 0x65, 0x18, 0x04, 0x1C, 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0
    .byte 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21, 0xB3, 0xF0, 0xC6, 0xFF
    .byte 0x2C, 0x60, 0x12, 0xE0, 0xF4, 0x0F, 0x00, 0x00, 0x64, 0x10, 0x00, 0x00, 0x09, 0x4A, 0xA4, 0x18
    .byte 0x00, 0x25, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21, 0xB3, 0xF0, 0xB2, 0xFF, 0x25, 0x60, 0x03, 0xB0, 0x30, 0xBC, 0x01, 0xBC
    .byte 0x00, 0x47, 0x00, 0x00, 0x64, 0x10, 0x00, 0x00
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
    ldr r1, [pc, #0x88]
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
    ldr r3, [pc, #0x64]
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
    .byte 0x38, 0x10, 0x00, 0x00, 0x68, 0x10, 0x00, 0x00
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
    ldr r0, [pc, #0x30]
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
    .byte 0x00, 0x00
    .4byte __vt_20GameSceneGroupSprite
    .Lauto_0801F27C:
    ldr r5, [pc, #0x28]
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
    .byte 0x68, 0x10, 0x00, 0x00
    .section .text.world_shipping_after, "ax", %progbits

    .byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x81, 0xB0, 0x04, 0x1C, 0x0E, 0x1C, 0x00, 0x20, 0x80, 0x46
    .byte 0x00, 0x2E, 0x07, 0xD0, 0x01, 0x2E, 0x08, 0xD1, 0x01, 0x49, 0x09, 0x19, 0x88, 0x46, 0x04, 0xE0
    .byte 0xD4, 0x0E, 0x00, 0x00, 0x12, 0x48, 0x00, 0x19, 0x80, 0x46, 0x41, 0x46, 0x00, 0x29, 0x37, 0xD0
    .byte 0x20, 0x27, 0x60, 0x68, 0x05, 0x68, 0x02, 0x2D, 0x1D, 0xD1, 0x00, 0x23, 0x21, 0x1C, 0x08, 0x31
    .byte 0xCC, 0x20, 0x40, 0x00, 0x22, 0x18, 0x91, 0x42, 0x09, 0xD0, 0x08, 0x68, 0x00, 0x28, 0x03, 0xD0
    .byte 0x80, 0x88, 0xA8, 0x42, 0x00, 0xD1, 0x01, 0x33, 0x04, 0x31, 0x91, 0x42, 0xF5, 0xD1, 0x18, 0x1C
    .byte 0x0A, 0x30, 0x0A, 0x28, 0x07, 0xD9, 0x15, 0x2B, 0x04, 0xD8, 0x20, 0x20, 0xC7, 0x1A, 0x02, 0xE0
    .byte 0xA4, 0x0E, 0x00, 0x00, 0x0A, 0x27, 0x0D, 0x48
    bl __builtin_new
    .byte 0x00, 0x97, 0x21, 0x1C
    .byte 0x42, 0x46, 0x33, 0x1C
    bl __22GameSceneWeatherEffectP10GameObjectP23IndexedResourceProviderQ222GameSceneWeatherEffect4KindUi
    .byte 0x09, 0x49, 0x65, 0x18, 0x04, 0x1C, 0x28, 0x68
    .byte 0x84, 0x42, 0x04, 0xD0, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x21
    bl _._22GameSceneWeatherEffect
    .byte 0x2C, 0x60
    .byte 0x01, 0xB0, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x6C, 0x04, 0x00, 0x00
    .byte 0x7C, 0x10, 0x00, 0x00
    .global func_0801F910
    .thumb_func
func_0801F910:
    push {r4, r5, r6, r7, lr}
    sub sp, #0x14
    adds r7, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    movs r0, #0xbc
    bl __builtin_new
    adds r1, r5, #0
    bl func_080A6474
    str r0, [sp, #8]
    ldr r0, .Ljp_0801F96C
    bl __builtin_new
    add r3, sp, #8
    mov r1, sp
    strb r4, [r1]
    adds r1, r5, #0
    adds r2, r6, #0
    bl func_08017348
    str r0, [sp, #4]
    add r1, sp, #4
    str r1, [sp, #0xc]
    str r0, [sp, #0x10]
    adds r2, r1, #0
    movs r1, #0
    str r1, [r2]
    str r0, [r7]
    ldr r1, [sp, #4]
    cmp r1, #0
    beq .Ljp_0801F962
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.Ljp_0801F962:
    adds r0, r7, #0
    add sp, #0x14
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.Ljp_0801F96C: .4byte 0x000010CC
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

    .section .text.game_scene_after_screen_flash, "ax", %progbits
    .thumb
    .align 2, 0

    thumb_func_start func_08014AF8
func_08014AF8: @ 0x08014AF8
    push {r4, r5, r6, lr}
    sub sp, #0xc
    ldr r5, [r0, #4]
    adds r4, r5, #0
    adds r4, #0xa8
    movs r6, #0
    ldr r1, [r4]
    cmp r6, r1
    beq .L08014B1A
    cmp r1, #0
    beq .L08014B1A
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08014B1A:
    str r6, [r4]
    adds r4, r5, #0
    adds r4, #0x8c
    ldr r0, [r4]
    bl DayUpdate__18GameStateSaveImage
    adds r6, r5, #0
    adds r6, #0xa8
    ldr r1, [r4]
    adds r0, r5, #0
    adds r0, #0x88
    ldr r2, [r0]
    mov r0, sp
    movs r3, #0
    bl func_0801FB7C
    ldr r1, [sp]
    mov r0, sp
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0
    str r0, [sp]
    adds r4, r1, #0
    ldr r1, [r6]
    adds r5, r6, #0
    cmp r4, r1
    beq .L08014B60
    cmp r1, #0
    beq .L08014B60
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08014B60:
    str r4, [r6]
    ldr r1, [sp]
    cmp r1, #0
    beq .L08014B74
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08014B74:
    ldr r0, [r5]
    ldr r1, [r0]
    movs r2, #0x9c
    lsls r2, r2, #1
    adds r1, r1, r2
    ldr r1, [r1]
    bl _call_via_r1
    ldr r0, [r5]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0
    bl _call_via_r2
    adds r4, r0, #0
    ldr r0, .L08014BB4 @ =gUnk_0300040C
    ldr r1, [r0]
    movs r2, #0xdb
    lsls r2, r2, #2
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08014BCE
    adds r2, #8
    adds r0, r1, r2
    ldrh r0, [r0]
    lsls r0, r0, #0x1b
    lsrs r1, r0, #0x1b
    cmp r1, #5
    bhi .L08014BB8
    movs r0, #6
    b .L08014BBA
    .align 2, 0
.L08014BB4: .4byte gUnk_0300040C
.L08014BB8:
    movs r0, #0x1e
.L08014BBA:
    subs r2, r0, r1
    ldr r0, [r4, #0x14]
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r2, r2, #1
    rsbs r2, r2, #0
    ldr r3, [r0, #0x64]
    adds r0, r4, #0
    bl _call_via_r3
.L08014BCE:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    .section .text.game_scene_after_actor_commands, "ax", %progbits

    thumb_func_start func_08014D9C
func_08014D9C: @ 0x08014D9C
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

    thumb_func_start func_08015210
func_08015210: @ 0x08015210
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
    bl func_0800F190
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
    bl func_0800F344
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .L080152B8
    ldr r0, [r6]
    ldr r1, .L08015318 @ =0x00001C2C
    adds r0, r0, r1
    bl func_0800F390
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

    thumb_func_start func_0801531C
func_0801531C: @ 0x0801531C
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
    b func_08015790
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

    thumb_func_start func_08015790
func_08015790: @ 0x08015790
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
    bl func_0800F190
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
    bl func_0800F344
    adds r1, r0, #0
    adds r0, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .L08015838
    ldr r0, [r6]
    ldr r1, .L08015898 @ =0x00001C2C
    adds r0, r0, r1
    bl func_0800F390
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

    .section .text.game_scene_after_player_presentation, "ax", %progbits

    thumb_func_start func_080159B0
func_080159B0: @ 0x080159B0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x88
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r7, [r0, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r7, #0
    adds r0, #0xa8
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080159DA
    b .L08015B1A
.L080159DA:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L080159FC
    cmp r1, #0x33
    ble .L080159FC
    ldr r0, .L080159F8 @ =0x00000133
    cmp r1, r0
    bgt .L080159FC
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015A16
    movs r1, #1
    b .L08015A18
    .align 2, 0
.L080159F8: .4byte 0x00000133
.L080159FC:
    cmp r5, #1
    bne .L08015A16
    ldr r0, .L08015B50 @ =0x00000133
    cmp r1, r0
    ble .L08015A16
    ldr r0, .L08015B54 @ =0x00000233
    cmp r1, r0
    bgt .L08015A16
    ldr r2, .L08015B58 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015A18
.L08015A16:
    movs r1, #0
.L08015A18:
    cmp r1, #0
    beq .L08015B1A
    ldr r1, [r3, #0x14]
    add r4, sp, #0x3c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015A34
    adds r0, #7
.L08015A34:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015A40
    adds r1, #7
.L08015A40:
    asrs r1, r1, #3
    add r0, sp, #0x44
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015A66
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015A60
    ldr r0, [sp, #0x44]
    str r0, [r1]
.L08015A60:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015A66:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015A70
    adds r0, #7
.L08015A70:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015A7C
    adds r1, #7
.L08015A7C:
    asrs r1, r1, #3
    add r0, sp, #0x48
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015AA2
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015A9C
    ldr r0, [sp, #0x48]
    str r0, [r1]
.L08015A9C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015AA2:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015AAC
    adds r0, #7
.L08015AAC:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015AB8
    adds r1, #7
.L08015AB8:
    asrs r1, r1, #3
    add r0, sp, #0x4c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015ADE
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015AD8
    ldr r0, [sp, #0x4c]
    str r0, [r1]
.L08015AD8:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015ADE:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015AE8
    adds r0, #7
.L08015AE8:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015AF4
    adds r1, #7
.L08015AF4:
    asrs r1, r1, #3
    add r0, sp, #0x50
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015B1A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015B14
    ldr r0, [sp, #0x50]
    str r0, [r1]
.L08015B14:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015B1A:
    adds r4, r7, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    mov r8, r4
    cmp r3, #0
    bne .L08015B34
    b .L08015C7A
.L08015B34:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L08015B5C
    cmp r1, #0x33
    ble .L08015B5C
    ldr r0, .L08015B50 @ =0x00000133
    cmp r1, r0
    bgt .L08015B5C
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015B76
    movs r1, #1
    b .L08015B78
    .align 2, 0
.L08015B50: .4byte 0x00000133
.L08015B54: .4byte 0x00000233
.L08015B58: .4byte 0xFFFFFECC
.L08015B5C:
    cmp r5, #1
    bne .L08015B76
    ldr r0, .L08015CAC @ =0x00000133
    cmp r1, r0
    ble .L08015B76
    ldr r0, .L08015CB0 @ =0x00000233
    cmp r1, r0
    bgt .L08015B76
    ldr r2, .L08015CB4 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015B78
.L08015B76:
    movs r1, #0
.L08015B78:
    cmp r1, #0
    beq .L08015C7A
    ldr r1, [r3, #0x14]
    add r4, sp, #0x54
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015B94
    adds r0, #7
.L08015B94:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015BA0
    adds r1, #7
.L08015BA0:
    asrs r1, r1, #3
    add r0, sp, #0x5c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015BC6
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015BC0
    ldr r0, [sp, #0x5c]
    str r0, [r1]
.L08015BC0:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015BC6:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015BD0
    adds r0, #7
.L08015BD0:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015BDC
    adds r1, #7
.L08015BDC:
    asrs r1, r1, #3
    add r0, sp, #0x60
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C02
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015BFC
    ldr r0, [sp, #0x60]
    str r0, [r1]
.L08015BFC:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C02:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015C0C
    adds r0, #7
.L08015C0C:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015C18
    adds r1, #7
.L08015C18:
    asrs r1, r1, #3
    add r0, sp, #0x64
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C3E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015C38
    ldr r0, [sp, #0x64]
    str r0, [r1]
.L08015C38:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C3E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015C48
    adds r0, #7
.L08015C48:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015C54
    adds r1, #7
.L08015C54:
    asrs r1, r1, #3
    add r0, sp, #0x68
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015C7A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015C74
    ldr r0, [sp, #0x68]
    str r0, [r1]
.L08015C74:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015C7A:
    mov r1, r8
    ldr r0, [r1]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08015C90
    b .L08015DD6
.L08015C90:
    ldrh r1, [r3, #4]
    cmp r5, #0
    bne .L08015CB8
    cmp r1, #0x33
    ble .L08015CB8
    ldr r0, .L08015CAC @ =0x00000133
    cmp r1, r0
    bgt .L08015CB8
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015CD2
    movs r1, #1
    b .L08015CD4
    .align 2, 0
.L08015CAC: .4byte 0x00000133
.L08015CB0: .4byte 0x00000233
.L08015CB4: .4byte 0xFFFFFECC
.L08015CB8:
    cmp r5, #1
    bne .L08015CD2
    ldr r0, .L08015E20 @ =0x00000133
    cmp r1, r0
    ble .L08015CD2
    ldr r0, .L08015E24 @ =0x00000233
    cmp r1, r0
    bgt .L08015CD2
    ldr r2, .L08015E28 @ =0xFFFFFECC
    adds r0, r1, r2
    movs r1, #1
    cmp r6, r0
    beq .L08015CD4
.L08015CD2:
    movs r1, #0
.L08015CD4:
    cmp r1, #0
    beq .L08015DD6
    ldr r1, [r3, #0x14]
    add r4, sp, #0x6c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015CF0
    adds r0, #7
.L08015CF0:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015CFC
    adds r1, #7
.L08015CFC:
    asrs r1, r1, #3
    add r0, sp, #0x74
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D22
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D1C
    ldr r0, [sp, #0x74]
    str r0, [r1]
.L08015D1C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D22:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015D2C
    adds r0, #7
.L08015D2C:
    asrs r2, r0, #3
    movs r0, #2
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015D38
    adds r1, #7
.L08015D38:
    asrs r1, r1, #3
    add r0, sp, #0x78
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D5E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D58
    ldr r0, [sp, #0x78]
    str r0, [r1]
.L08015D58:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D5E:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015D68
    adds r0, #7
.L08015D68:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015D74
    adds r1, #7
.L08015D74:
    asrs r1, r1, #3
    add r0, sp, #0x7c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015D9A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015D94
    ldr r0, [sp, #0x7c]
    str r0, [r1]
.L08015D94:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015D9A:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015DA4
    adds r0, #7
.L08015DA4:
    asrs r2, r0, #3
    movs r0, #6
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bge .L08015DB0
    adds r1, #7
.L08015DB0:
    asrs r1, r1, #3
    add r0, sp, #0x80
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015DD6
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015DD0
    ldr r0, [sp, #0x80]
    str r0, [r1]
.L08015DD0:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015DD6:
    ldr r2, [sp, #8]
    movs r3, #0
    add r4, sp, #0xc
    cmp r2, #0
    beq .L08015DE2
    adds r3, r4, #0
.L08015DE2:
    adds r0, r7, #0
    adds r0, #0x8c
    ldr r1, [r0]
    ldr r0, .L08015E2C @ =0x00002E58
    adds r1, r1, r0
    str r3, [sp]
    str r2, [sp, #4]
    add r0, sp, #0x84
    adds r2, r5, #0
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    adds r0, r4, #0
    cmp r0, r1
    beq .L08015E12
.L08015E0C:
    adds r0, #4
    cmp r0, r1
    bne .L08015E0C
.L08015E12:
    add sp, #0x88
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08015E20: .4byte 0x00000133
.L08015E24: .4byte 0x00000233
.L08015E28: .4byte 0xFFFFFECC
.L08015E2C: .4byte 0x00002E58

    thumb_func_start func_08015E30
func_08015E30: @ 0x08015E30
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xe8
    ldr r0, [r0, #4]
    str r0, [sp, #0xd8]
    adds r4, r0, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    add r0, sp, #0x3c
    movs r3, #0
    strb r3, [r0]
    strb r3, [r0, #1]
    adds r1, r2, #0
    subs r1, #0x34
    adds r7, r0, #0
    cmp r1, #0xff
    bls .L08015E64
    b .L08016250
.L08015E64:
    adds r0, r2, #1
    mov r8, r0
    adds r6, r2, #0
    subs r6, #0x33
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08015E82
    b .L08015F9C
.L08015E82:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L08015E9A
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L08015E9A
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015E9A
    movs r2, #1
.L08015E9A:
    cmp r2, #0
    beq .L08015F9C
    ldr r1, [r3, #0x14]
    add r4, sp, #0x40
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015EB6
    adds r0, #7
.L08015EB6:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015EC2
    adds r1, #7
.L08015EC2:
    asrs r1, r1, #3
    add r0, sp, #0x48
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015EE8
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015EE2
    ldr r0, [sp, #0x48]
    str r0, [r1]
.L08015EE2:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015EE8:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015EF2
    adds r0, #7
.L08015EF2:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015EFE
    adds r1, #7
.L08015EFE:
    asrs r1, r1, #3
    add r0, sp, #0x4c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F24
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F1E
    ldr r0, [sp, #0x4c]
    str r0, [r1]
.L08015F1E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F24:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015F2E
    adds r0, #7
.L08015F2E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015F3A
    adds r1, #7
.L08015F3A:
    asrs r1, r1, #3
    add r0, sp, #0x50
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F60
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F5A
    ldr r0, [sp, #0x50]
    str r0, [r1]
.L08015F5A:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F60:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015F6A
    adds r0, #7
.L08015F6A:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015F76
    adds r1, #7
.L08015F76:
    asrs r1, r1, #3
    add r0, sp, #0x54
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08015F9C
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08015F96
    ldr r0, [sp, #0x54]
    str r0, [r1]
.L08015F96:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08015F9C:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .L08015FB6
    b .L080160D0
.L08015FB6:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L08015FCE
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L08015FCE
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L08015FCE
    movs r2, #1
.L08015FCE:
    cmp r2, #0
    beq .L080160D0
    ldr r1, [r3, #0x14]
    add r4, sp, #0x58
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08015FEA
    adds r0, #7
.L08015FEA:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08015FF6
    adds r1, #7
.L08015FF6:
    asrs r1, r1, #3
    add r0, sp, #0x60
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801601C
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016016
    ldr r0, [sp, #0x60]
    str r0, [r1]
.L08016016:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801601C:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016026
    adds r0, #7
.L08016026:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016032
    adds r1, #7
.L08016032:
    asrs r1, r1, #3
    add r0, sp, #0x64
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016058
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016052
    ldr r0, [sp, #0x64]
    str r0, [r1]
.L08016052:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016058:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016062
    adds r0, #7
.L08016062:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L0801606E
    adds r1, #7
.L0801606E:
    asrs r1, r1, #3
    add r0, sp, #0x68
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016094
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L0801608E
    ldr r0, [sp, #0x68]
    str r0, [r1]
.L0801608E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016094:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801609E
    adds r0, #7
.L0801609E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L080160AA
    adds r1, #7
.L080160AA:
    asrs r1, r1, #3
    add r0, sp, #0x6c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080160D0
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L080160CA
    ldr r0, [sp, #0x6c]
    str r0, [r1]
.L080160CA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080160D0:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080160E6
    b .L0801620A
.L080160E6:
    ldrh r1, [r3, #4]
    movs r2, #0
    cmp r1, #0x33
    ble .L080160FE
    ldr r0, .L080161A0 @ =0x00000133
    cmp r1, r0
    bgt .L080160FE
    adds r0, r1, #0
    subs r0, #0x34
    cmp r6, r0
    bne .L080160FE
    movs r2, #1
.L080160FE:
    cmp r2, #0
    bne .L08016104
    b .L0801620A
.L08016104:
    ldr r1, [r3, #0x14]
    add r4, sp, #0x70
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801611C
    adds r0, #7
.L0801611C:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016128
    adds r1, #7
.L08016128:
    asrs r1, r1, #3
    add r0, sp, #0x78
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801614E
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016148
    ldr r0, [sp, #0x78]
    str r0, [r1]
.L08016148:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801614E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016158
    adds r0, #7
.L08016158:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L08016164
    adds r1, #7
.L08016164:
    asrs r1, r1, #3
    add r0, sp, #0x7c
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801618A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016184
    ldr r0, [sp, #0x7c]
    str r0, [r1]
.L08016184:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801618A:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016194
    adds r0, #7
.L08016194:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    b .L080161A4
    .align 2, 0
.L080161A0: .4byte 0x00000133
.L080161A4:
    bge .L080161A8
    adds r1, #7
.L080161A8:
    asrs r1, r1, #3
    add r0, sp, #0x80
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080161CE
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L080161C8
    ldr r0, [sp, #0x80]
    str r0, [r1]
.L080161C8:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080161CE:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080161D8
    adds r0, #7
.L080161D8:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r1, [r4, r3]
    cmp r1, #0
    bge .L080161E4
    adds r1, #7
.L080161E4:
    asrs r1, r1, #3
    add r0, sp, #0x84
    strb r2, [r0]
    strb r1, [r0, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801620A
    lsls r0, r0, #2
    adds r0, #4
    mov r1, sp
    adds r1, r1, r0
    adds r1, #8
    cmp r1, #0
    beq .L08016204
    ldr r0, [sp, #0x84]
    str r0, [r1]
.L08016204:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801620A:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .L08016216
    adds r2, r5, #0
.L08016216:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, .L0801624C @ =0x00002E58
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0x88
    movs r2, #0
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0x88
    cmp r1, r2
    bne .L08016244
    b .L0801664A
.L08016244:
    adds r1, #4
    cmp r1, r2
    bne .L08016244
    b .L0801664A
    .align 2, 0
.L0801624C: .4byte 0x00002E58
.L08016250:
    ldr r1, .L0801656C @ =0xFFFFFECC
    adds r0, r2, r1
    cmp r0, #0xff
    bls .L0801625A
    b .L08016740
.L0801625A:
    adds r0, r2, #1
    mov r8, r0
    adds r1, #1
    adds r6, r2, r1
    str r3, [sp, #8]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4a
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L08016278
    b .L08016394
.L08016278:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L08016292
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L08016292
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L08016292
    movs r2, #1
.L08016292:
    cmp r2, #0
    beq .L08016394
    ldr r1, [r3, #0x14]
    add r4, sp, #0x8c
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080162AE
    adds r0, #7
.L080162AE:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080162BA
    adds r0, #7
.L080162BA:
    asrs r0, r0, #3
    add r1, sp, #0x94
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080162E0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080162DA
    ldr r0, [r1]
    str r0, [r2]
.L080162DA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080162E0:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080162EA
    adds r0, #7
.L080162EA:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080162F6
    adds r0, #7
.L080162F6:
    asrs r0, r0, #3
    add r1, sp, #0x98
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801631C
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016316
    ldr r0, [r1]
    str r0, [r2]
.L08016316:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801631C:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016326
    adds r0, #7
.L08016326:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016332
    adds r0, #7
.L08016332:
    asrs r0, r0, #3
    add r1, sp, #0x9c
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016358
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016352
    ldr r0, [r1]
    str r0, [r2]
.L08016352:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016358:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016362
    adds r0, #7
.L08016362:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L0801636E
    adds r0, #7
.L0801636E:
    asrs r0, r0, #3
    add r1, sp, #0xa0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016394
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801638E
    ldr r0, [r1]
    str r0, [r2]
.L0801638E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016394:
    ldr r4, [sp, #0xd8]
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r3, r0, #0
    str r4, [sp, #0xe0]
    cmp r3, #0
    bne .L080163AE
    b .L080164CA
.L080163AE:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L080163C8
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L080163C8
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L080163C8
    movs r2, #1
.L080163C8:
    cmp r2, #0
    beq .L080164CA
    ldr r1, [r3, #0x14]
    add r4, sp, #0xa4
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080163E4
    adds r0, #7
.L080163E4:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080163F0
    adds r0, #7
.L080163F0:
    asrs r0, r0, #3
    add r1, sp, #0xac
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016416
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016410
    ldr r0, [r1]
    str r0, [r2]
.L08016410:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016416:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016420
    adds r0, #7
.L08016420:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L0801642C
    adds r0, #7
.L0801642C:
    asrs r0, r0, #3
    add r1, sp, #0xb0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L08016452
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801644C
    ldr r0, [r1]
    str r0, [r2]
.L0801644C:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016452:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801645C
    adds r0, #7
.L0801645C:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016468
    adds r0, #7
.L08016468:
    asrs r0, r0, #3
    add r1, sp, #0xb4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801648E
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016488
    ldr r0, [r1]
    str r0, [r2]
.L08016488:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801648E:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016498
    adds r0, #7
.L08016498:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080164A4
    adds r0, #7
.L080164A4:
    asrs r0, r0, #3
    add r1, sp, #0xb8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080164CA
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080164C4
    ldr r0, [r1]
    str r0, [r2]
.L080164C4:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080164CA:
    ldr r4, [sp, #0xe0]
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x4b
    bl _call_via_r2
    adds r3, r0, #0
    cmp r3, #0
    bne .L080164E0
    b .L0801660C
.L080164E0:
    ldrh r1, [r3, #4]
    ldr r0, .L08016570 @ =0x00000133
    movs r2, #0
    cmp r1, r0
    ble .L080164FA
    ldr r0, .L08016574 @ =0x00000233
    cmp r1, r0
    bgt .L080164FA
    ldr r4, .L0801656C @ =0xFFFFFECC
    adds r0, r1, r4
    cmp r6, r0
    bne .L080164FA
    movs r2, #1
.L080164FA:
    cmp r2, #0
    bne .L08016500
    b .L0801660C
.L08016500:
    ldr r1, [r3, #0x14]
    add r4, sp, #0xbc
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r3, #0
    bl _call_via_r2
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016518
    adds r0, #7
.L08016518:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016524
    adds r0, #7
.L08016524:
    asrs r0, r0, #3
    add r1, sp, #0xc4
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801654A
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016544
    ldr r0, [r1]
    str r0, [r2]
.L08016544:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801654A:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L08016554
    adds r0, #7
.L08016554:
    asrs r2, r0, #3
    movs r3, #2
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L08016560
    adds r0, #7
.L08016560:
    asrs r0, r0, #3
    add r1, sp, #0xc8
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    b .L08016578
    .align 2, 0
.L0801656C: .4byte 0xFFFFFECC
.L08016570: .4byte 0x00000133
.L08016574: .4byte 0x00000233
.L08016578:
    cmp r0, #0xb
    bhi .L08016594
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L0801658E
    ldr r0, [r1]
    str r0, [r2]
.L0801658E:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L08016594:
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L0801659E
    adds r0, #7
.L0801659E:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080165AA
    adds r0, #7
.L080165AA:
    asrs r0, r0, #3
    add r1, sp, #0xcc
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L080165D0
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L080165CA
    ldr r0, [r1]
    str r0, [r2]
.L080165CA:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L080165D0:
    movs r1, #4
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bge .L080165DA
    adds r0, #7
.L080165DA:
    asrs r2, r0, #3
    movs r3, #6
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bge .L080165E6
    adds r0, #7
.L080165E6:
    asrs r0, r0, #3
    add r1, sp, #0xd0
    strb r2, [r1]
    strb r0, [r1, #1]
    ldr r0, [sp, #8]
    cmp r0, #0xb
    bhi .L0801660C
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    cmp r2, #0
    beq .L08016606
    ldr r0, [r1]
    str r0, [r2]
.L08016606:
    ldr r0, [sp, #8]
    adds r0, #1
    str r0, [sp, #8]
.L0801660C:
    movs r2, #0
    ldr r0, [sp, #8]
    add r5, sp, #0xc
    cmp r0, #0
    beq .L08016618
    adds r2, r5, #0
.L08016618:
    ldr r4, [sp, #0xd8]
    adds r4, #0x8c
    ldr r1, [r4]
    ldr r3, .L08016668 @ =0x00002E58
    adds r1, r1, r3
    str r2, [sp]
    str r0, [sp, #4]
    add r0, sp, #0xd4
    movs r2, #1
    adds r3, r6, #0
    bl GenerateLayout__14MineFloorState12MaryMineKindUiPC17MineFloorPositionUi
    ldr r0, [sp, #8]
    lsls r0, r0, #2
    adds r0, #4
    mov r2, sp
    adds r2, r2, r0
    adds r2, #8
    adds r1, r5, #0
    add r0, sp, #0xd4
    cmp r1, r2
    beq .L0801664A
.L08016644:
    adds r1, #4
    cmp r1, r2
    bne .L08016644
.L0801664A:
    ldr r0, [r0]
    str r0, [sp, #0x3c]
    ldr r0, [r4]
    ldr r4, .L08016668 @ =0x00002E58
    adds r0, r0, r4
    bl GetLayoutKind__C14MineFloorState
    cmp r0, #4
    bhi .L08016740
    lsls r0, r0, #2
    ldr r1, .L0801666C @ =.L08016670
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08016668: .4byte 0x00002E58
.L0801666C: .4byte .L08016670
.L08016670: @ jump table
    .4byte .L08016684 @ case 0
    .4byte .L08016684 @ case 1
    .4byte .L08016684 @ case 2
    .4byte .L08016684 @ case 3
    .4byte .L08016684 @ case 4
.L08016684:
    ldrb r0, [r7]
    lsls r0, r0, #4
    adds r0, #0x10
    mov sl, r0
    add r0, sp, #0x3c
    ldrb r0, [r0, #1]
    lsls r0, r0, #4
    adds r7, r0, #0
    adds r7, #0x38
    movs r0, #8
    add sl, r0
    adds r7, #8
    ldr r1, [sp, #0xe0]
    ldr r0, [r1]
    ldr r2, [r0]
    adds r2, #0xb4
    str r2, [sp, #0xdc]
    add r6, sp, #8
    ldr r3, .L08016750 @ =0x000003FF
    mov sb, r3
    mov r4, r8
    mov r1, sb
    ands r4, r1
    ldrh r2, [r6]
    ldr r5, .L08016754 @ =0xFFFFFC00
    adds r1, r5, #0
    ands r1, r2
    orrs r1, r4
    strh r1, [r6]
    mov r2, sl
    lsls r4, r2, #0x10
    lsrs r2, r4, #0x10
    movs r3, #0x3f
    mov ip, r3
    ands r2, r3
    lsls r2, r2, #2
    str r2, [sp, #0xe4]
    ldrb r1, [r6, #1]
    mov r8, r1
    movs r3, #3
    adds r1, r3, #0
    mov r2, r8
    ands r1, r2
    ldr r2, [sp, #0xe4]
    orrs r1, r2
    strb r1, [r6, #1]
    lsrs r4, r4, #0x16
    mov r1, sb
    ands r4, r1
    ldrh r2, [r6, #2]
    adds r1, r5, #0
    ands r1, r2
    orrs r1, r4
    strh r1, [r6, #2]
    lsls r2, r7, #0x10
    lsrs r1, r2, #0x10
    mov r4, ip
    ands r1, r4
    lsls r1, r1, #2
    ldrb r4, [r6, #3]
    ands r3, r4
    orrs r3, r1
    strb r3, [r6, #3]
    lsrs r2, r2, #0x16
    mov r1, sb
    ands r2, r1
    ldrh r1, [r6, #4]
    ands r5, r1
    orrs r5, r2
    strh r5, [r6, #4]
    ldr r2, [sp, #0xdc]
    ldr r3, [r2]
    adds r1, r6, #0
    movs r2, #1
    bl _call_via_r3
    ldr r0, [sp, #0xd8]
    bl func_080D7F08
    movs r4, #0
    ldr r3, [sp, #0xe0]
    ldr r0, [r3]
    ldr r1, [r0]
    ldr r1, [r1, #0x14]
    bl _call_via_r1
    adds r2, r0, #0
    str r7, [sp]
    str r4, [sp, #4]
    ldr r0, [sp, #0xd8]
    movs r1, #0
    mov r3, sl
    bl RelocateEntityToMap__FP14GameSceneStateiUiiiUi
.L08016740:
    add sp, #0xe8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08016750: .4byte 0x000003FF
.L08016754: .4byte 0xFFFFFC00
    .section .text.game_scene_after_contest_registration, "ax", %progbits

    thumb_func_start func_080168D4
func_080168D4: @ 0x080168D4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r6, [r0, #4]
    cmp r1, #4
    bls .L080168E4
    b .L08016AF0
.L080168E4:
    lsls r0, r1, #2
    ldr r1, .L080168F0 @ =.L080168F4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L080168F0: .4byte .L080168F4
.L080168F4: @ jump table
    .4byte .L08016908 @ case 0
    .4byte .L0801696C @ case 1
    .4byte .L0801696C @ case 2
    .4byte .L08016A02 @ case 3
    .4byte .L08016A92 @ case 4
.L08016908:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    cmp r0, #0
    beq .L0801691E
    b .L08016AF0
.L0801691E:
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2c
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2c
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016956
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016956
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016956:
    cmp r4, #0
    bne .L0801695C
    b .L08016AF0
.L0801695C:
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbc
    lsls r2, r2, #2
    movs r3, #0x84
    bl SetLocation__7AEntityUiii
    b .L08016AF0
.L0801696C:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D058__C4Barn
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    bne .L0801698A
    b .L08016AF0
.L0801698A:
    ldr r0, [r4]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D858__4Barn
    adds r5, r7, #0
    adds r5, #0x36
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r5, r0, #0
    cmp r5, #0
    beq .L080169D4
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r5, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080169D4
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r5, #0
    bl _call_via_r1
.L080169D4:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0xbe
    lsls r0, r0, #3
    adds r1, r1, r0
    mov r4, sp
    mov r0, sp
    adds r2, r7, #0
    bl method_0800D074__C4BarnUi
    cmp r5, #0
    bne .L080169EE
    b .L08016AF0
.L080169EE:
    mov r0, sp
    movs r1, #0
    ldrsh r2, [r0, r1]
    movs r0, #2
    ldrsh r3, [r4, r0]
    adds r0, r5, #0
    movs r1, #0x25
    bl SetLocation__7AEntityUiii
    b .L08016AF0
.L08016A02:
    adds r4, r6, #0
    adds r4, #0x8c
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetUnkEnt__C4Coop
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    mov r8, r4
    cmp r7, r0
    beq .L08016AF0
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800CBC0__4Coop
    adds r5, r7, #0
    adds r5, #0x2e
    adds r4, #0x1c
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    adds r1, r5, #0
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    adds r1, r5, #0
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016A68
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016A68
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016A68:
    mov r0, r8
    ldr r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #3
    adds r1, r1, r0
    add r5, sp, #4
    adds r0, r5, #0
    adds r2, r7, #0
    bl method_0800C6F0__C4CoopUi
    cmp r4, #0
    beq .L08016AF0
    movs r1, #0
    ldrsh r2, [r5, r1]
    movs r0, #2
    ldrsh r3, [r5, r0]
    adds r0, r4, #0
    movs r1, #0x11
    bl SetLocation__7AEntityUiii
    b .L08016AF0
.L08016A92:
    adds r4, r6, #0
    adds r4, #0xa8
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    cmp r0, #0
    bne .L08016AF0
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x38]
    movs r1, #0x2b
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r2, [r1, #0x40]
    movs r1, #0x2b
    bl _call_via_r2
    adds r4, r0, #0
    cmp r4, #0
    beq .L08016ADE
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08016ADE
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x20]
    adds r0, r4, #0
    bl _call_via_r1
.L08016ADE:
    cmp r4, #0
    beq .L08016AF0
    adds r0, r4, #0
    movs r1, #2
    movs r2, #0xbf
    lsls r2, r2, #1
    movs r3, #0x52
    bl SetLocation__7AEntityUiii
.L08016AF0:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start func_08016AFC
func_08016AFC: @ 0x08016AFC
    push {lr}
    ldr r2, [r0, #4]
    cmp r1, #4
    bhi .L08016B4A
    lsls r0, r1, #2
    ldr r1, .L08016B10 @ =.L08016B14
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08016B10: .4byte .L08016B14
.L08016B14: @ jump table
    .4byte .L08016B28 @ case 0
    .4byte .L08016B78 @ case 1
    .4byte .L08016B78 @ case 2
    .4byte .L08016B8A @ case 3
    .4byte .L08016B58 @ case 4
.L08016B28:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r2, [r0]
    ldr r1, .L08016B50 @ =0x0000219A
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne .L08016B70
    ldr r1, .L08016B54 @ =0x000021A1
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne .L08016B70
.L08016B4A:
    movs r1, #1
    rsbs r1, r1, #0
    b .L08016B9C
    .align 2, 0
.L08016B50: .4byte 0x0000219A
.L08016B54: .4byte 0x000021A1
.L08016B58:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    ldr r1, .L08016B74 @ =0x0000219C
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, #0
    beq .L08016B9C
.L08016B70:
    movs r1, #0
    b .L08016B9C
    .align 2, 0
.L08016B74: .4byte 0x0000219C
.L08016B78:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl method_0800D058__C4Barn
    b .L08016B9A
.L08016B8A:
    adds r0, r2, #0
    adds r0, #0x8c
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetUnkEnt__C4Coop
.L08016B9A:
    adds r1, r0, #0
.L08016B9C:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0

    .section .text.game_scene_field_item_tool_after, "ax", %progbits
    .align 2, 0

    thumb_func_start func_080175B4
func_080175B4: @ 0x080175B4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    adds r7, r0, #0
    str r1, [sp, #0x18]
    mov sl, r2
    str r3, [sp, #0x1c]
    add r0, sp, #0x50
    ldrb r0, [r0]
    str r0, [sp, #0x20]
    ldr r0, .L08017834 @ =vtable_unk_080E6038
    str r0, [r7]
    ldr r1, .L08017838 @ =vtable_unk_080E5EC4
    adds r0, r7, #0
    stm r0!, {r1}
    ldr r2, [sp, #0x1c]
    ldr r1, [r2]
    movs r3, #0
    str r3, [r2]
    str r1, [sp, #4]
    add r1, sp, #4
    bl __18GameSceneWorldDataG22GameSceneWorldMapOwner
    ldr r0, .L0801783C @ =0x00001038
    adds r0, r0, r7
    mov r8, r0
    ldr r1, [sp, #0x18]
    str r1, [r0]
    ldr r2, .L08017840 @ =0x0000103C
    adds r0, r7, r2
    movs r3, #0
    strb r3, [r0]
    movs r0, #0x82
    lsls r0, r0, #5
    adds r4, r7, r0
    mov r2, r8
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x10
    str r0, [r4]
    strb r3, [r4, #4]
    ldr r3, .L08017844 @ =0x00001048
    adds r3, r3, r7
    mov sb, r3
    ldr r1, [r1, #0x10]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x1b
    adds r0, r7, #0
    bl GetWorldTimeOfDayPeriod
    mov r1, sb
    str r0, [r1]
    ldr r0, [r4]
    ldr r4, [r0]
    lsls r5, r4, #0xb
    lsrs r5, r5, #0x1b
    lsls r4, r4, #5
    lsrs r4, r4, #0x1a
    mov r2, r8
    ldr r0, [r2]
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    adds r2, r0, #0
    mov r0, sb
    ldr r3, [r0]
    adds r0, r5, #0
    adds r1, r4, #0
    bl GetTimeOfDayTransitionValue
    ldr r2, .L08017848 @ =0x0000104C
    adds r1, r7, r2
    strb r0, [r1]
    ldr r3, .L0801784C @ =0x00001050
    adds r4, r7, r3
    movs r0, #0xb0
    lsls r0, r0, #8
    bl __builtin_vec_new
    str r0, [r4]
    ldr r1, .L08017850 @ =0x00001054
    adds r0, r7, r1
    mov r2, sl
    str r2, [r0]
    ldr r3, .L08017854 @ =0x00001058
    adds r0, r7, r3
    movs r1, #0
    str r1, [r0]
    ldr r2, .L08017858 @ =0x0000105C
    adds r0, r7, r2
    str r1, [r0]
    adds r3, #0xc
    adds r0, r7, r3
    str r1, [r0]
    ldr r1, .L0801785C @ =0x00001068
    adds r0, r7, r1
    movs r2, #0
    str r2, [r0]
    adds r3, #8
    adds r1, r7, r3
    movs r0, #1
    add r2, sp, #8
    mov r8, r2
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L0801768E:
    stm r1!, {r3}
    subs r0, #1
    cmp r0, r2
    bne .L0801768E
    ldr r3, .L08017860 @ =0x00001074
    adds r1, r7, r3
    movs r0, #1
    ldr r2, .L08017864 @ =0x0000107C
    adds r2, r2, r7
    mov sb, r2
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L080176A8:
    stm r1!, {r3}
    subs r0, #1
    cmp r0, r2
    bne .L080176A8
    ldr r3, .L08017864 @ =0x0000107C
    adds r1, r7, r3
    movs r0, #0
    str r0, [r1]
    movs r0, #0x84
    lsls r0, r0, #5
    adds r2, r7, r0
    movs r3, #3
    movs r6, #4
    rsbs r6, r6, #0
    movs r5, #0
    movs r4, #1
    rsbs r4, r4, #0
.L080176CA:
    ldrb r1, [r2, #1]
    adds r0, r6, #0
    ands r0, r1
    strb r0, [r2, #1]
    str r5, [r2, #8]
    adds r2, #0xc
    subs r3, #1
    cmp r3, r4
    bne .L080176CA
    ldr r2, .L08017868 @ =0x000010B0
    adds r1, r7, r2
    movs r0, #5
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L080176E8:
    stm r1!, {r3}
    subs r0, #1
    cmp r0, r2
    bne .L080176E8
    ldr r3, .L0801786C @ =0x000010C8
    adds r1, r7, r3
    movs r0, #0
    strb r0, [r1]
    ldr r4, [r7, #4]
    ldr r0, .L0801783C @ =0x00001038
    adds r6, r7, r0
    ldr r1, [r6]
    ldr r2, .L08017870 @ =0x00001BD8
    adds r1, r1, r2
    mov r0, r8
    bl GetLocation__C6Farmer
    ldr r3, .L08017844 @ =0x00001048
    adds r0, r7, r3
    ldr r2, [r0]
    ldr r1, .L08017848 @ =0x0000104C
    adds r0, r7, r1
    ldrb r3, [r0]
    movs r0, #0x1e
    subs r0, r0, r3
    str r0, [sp]
    adds r0, r4, #0
    mov r1, r8
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    ldr r0, [r7, #4]
    ldr r0, [r0]
    cmp r0, #2
    beq .L0801774E
    ldr r2, .L0801784C @ =0x00001050
    adds r0, r7, r2
    ldr r5, [r0]
    ldr r0, [r6]
    adds r4, r0, #0
    adds r4, #0x14
    adds r0, #0x10
    bl GetCalendarEffectiveSeason
    movs r2, #0
    cmp r0, #3
    bne .L08017746
    movs r2, #1
.L08017746:
    adds r0, r5, #0
    adds r1, r4, #0
    bl InitializeFarmTerrain
.L0801774E:
    ldr r3, [sp, #0x20]
    cmp r3, #0
    beq .L0801777E
    ldr r1, .L0801783C @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    ldr r2, .L08017874 @ =0x0000214C
    adds r0, r0, r2
    bl HasRegisteredEvents__C14GameEventState
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08017778
    ldr r3, .L08017850 @ =0x00001054
    adds r0, r7, r3
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801777E
.L08017778:
    adds r0, r7, #0
    bl UpdateWorldBackgroundAudio
.L0801777E:
    movs r0, #0xa0
    bl __builtin_new
    adds r1, r7, #0
    bl __22EntityAuxiliarySpritesP10GameObject
    ldr r1, .L08017878 @ =0x00001024
    adds r5, r7, r1
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L080177A0
    cmp r0, #0
    beq .L080177A0
    movs r1, #3
    bl _._22EntityAuxiliarySprites
.L080177A0:
    str r4, [r5]
    ldr r2, .L0801787C @ =0x00001028
    adds r4, r7, r2
    movs r5, #0
    ldr r0, [r4]
    cmp r5, r0
    beq .L080177B8
    cmp r0, #0
    beq .L080177B8
    movs r1, #3
    bl func_080AB2E4
.L080177B8:
    str r5, [r4]
    movs r0, #4
    bl __builtin_new
    ldr r1, [r7, #4]
    ldr r2, [r1, #4]
    adds r1, r7, #0
    bl func_080AAFC8
    ldr r3, .L0801787C @ =0x00001028
    adds r5, r7, r3
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L080177E0
    cmp r0, #0
    beq .L080177E0
    movs r1, #3
    bl func_080AB2E4
.L080177E0:
    str r4, [r5]
    movs r4, #0
.L080177E4:
    adds r0, r7, #0
    adds r1, r4, #0
    bl func_0801A8E0
    adds r4, #1
    cmp r4, #0x63
    bls .L080177E4
    mov r4, sb
    movs r5, #0
    ldr r0, [r4]
    cmp r5, r0
    beq .L08017806
    cmp r0, #0
    beq .L08017806
    movs r1, #3
    bl _._22GameSceneWeatherEffect
.L08017806:
    str r5, [r4]
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne .L080178AE
    ldr r0, [r7, #4]
    ldr r1, [r0]
    ldr r2, .L0801783C @ =0x00001038
    adds r0, r7, r2
    ldr r0, [r0]
    adds r0, #8
    cmp r1, #0x2e
    beq .L08017888
    cmp r1, #0x2e
    ble .L08017880
    cmp r1, #0x2f
    beq .L0801788C
    b .L08017890
    .align 2, 0
.L08017834: .4byte vtable_unk_080E6038
.L08017838: .4byte vtable_unk_080E5EC4
.L0801783C: .4byte 0x00001038
.L08017840: .4byte 0x0000103C
.L08017844: .4byte 0x00001048
.L08017848: .4byte 0x0000104C
.L0801784C: .4byte 0x00001050
.L08017850: .4byte 0x00001054
.L08017854: .4byte 0x00001058
.L08017858: .4byte 0x0000105C
.L0801785C: .4byte 0x00001068
.L08017860: .4byte 0x00001074
.L08017864: .4byte 0x0000107C
.L08017868: .4byte 0x000010B0
.L0801786C: .4byte 0x000010C8
.L08017870: .4byte 0x00001BD8
.L08017874: .4byte 0x0000214C
.L08017878: .4byte 0x00001024
.L0801787C: .4byte 0x00001028
.L08017880:
    cmp r1, #0x2c
    blt .L08017890
    movs r0, #0
    b .L08017892
.L08017888:
    movs r0, #1
    b .L08017892
.L0801788C:
    movs r0, #2
    b .L08017892
.L08017890:
    ldr r0, [r0]
.L08017892:
    cmp r0, #1
    beq .L0801789C
    cmp r0, #2
    beq .L080178A6
    b .L080178AE
.L0801789C:
    adds r0, r7, #0
    movs r1, #1
    bl func_0801FAC8
    b .L080178AE
.L080178A6:
    adds r0, r7, #0
    movs r1, #0
    bl func_0801FAC8
.L080178AE:
    adds r0, r7, #0
    bl func_0801F14C
    adds r0, r7, #0
    bl RefreshWorldVase
    adds r0, r7, #0
    bl func_0801F2DC
    adds r0, r7, #0
    bl RefreshWorldHillSeasonalSprites
    adds r0, r7, #0
    bl RefreshWorldWinterAndFireplaceSprites
    ldr r0, .L080179B4 @ =gUnk_0300040C
    ldr r0, [r0]
    movs r3, #0
    str r3, [sp, #0x24]
    ldr r1, .L080179B8 @ =0x00000DE4
    adds r1, r7, r1
    str r1, [sp, #0x28]
    ldr r2, .L080179BC @ =0x000004DC
    adds r6, r0, r2
.L080178DE:
    ldrb r0, [r6]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    mov sl, r0
    cmp r0, #1
    bne .L08017964
    ldrh r0, [r6, #2]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    ldr r1, [r7, #4]
    ldr r1, [r1]
    cmp r0, r1
    bne .L08017964
    ldr r3, .L080179C0 @ =0x000010B0
    adds r3, r3, r7
    mov r8, r3
    ldr r1, [sp, #0x24]
    lsls r0, r1, #2
    add r8, r0
    movs r0, #0x4c
    bl __builtin_new
    adds r4, r0, #0
    ldrh r2, [r6, #8]
    mov sb, r2
    adds r1, r7, #0
    movs r2, #2
    movs r3, #0x1b
    bl __19GameSceneSpriteBaseP10GameObjectUii
    ldr r0, .L080179C4 @ =__vt_20GameSceneGroupSprite
    str r0, [r4, #0x24]
    adds r3, r4, #0
    adds r3, #0x28
    str r3, [sp, #0x2c]
    ldr r0, [sp, #0x28]
    ldr r5, [r0]
    add r0, sp, #0x10
    ldr r3, [r5, #0xc]
    ldr r1, [sp, #0x28]
    mov r2, sb
    bl _call_via_r3
    ldr r0, [sp, #0x10]
    ldrh r2, [r0]
    ldr r0, [sp, #0x2c]
    ldr r3, [r5, #0x10]
    ldr r1, [sp, #0x28]
    bl _call_via_r3
    adds r0, r4, #0
    adds r0, #0x48
    mov r1, sl
    strb r1, [r0]
    mov r5, r8
    ldr r1, [r5]
    cmp r4, r1
    beq .L08017962
    cmp r1, #0
    beq .L08017962
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017962:
    str r4, [r5]
.L08017964:
    adds r6, #0xc
    ldr r2, [sp, #0x24]
    adds r2, #1
    str r2, [sp, #0x24]
    cmp r2, #6
    blo .L080178DE
    ldr r3, [sp, #0x18]
    ldr r1, .L080179C8 @ =0x000034C4
    adds r0, r3, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08017988
    adds r0, r7, #0
    bl SuspendWorldUpdates
    adds r0, r7, #0
    bl ResumeWorldUpdates
.L08017988:
    ldr r2, [sp, #0x1c]
    ldr r1, [r2]
    cmp r1, #0
    beq .L080179A0
    adds r0, r1, #0
    adds r0, #0x90
    ldr r0, [r0]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080179A0:
    adds r0, r7, #0
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080179B4: .4byte gUnk_0300040C
.L080179B8: .4byte 0x00000DE4
.L080179BC: .4byte 0x000004DC
.L080179C0: .4byte 0x000010B0
.L080179C4: .4byte __vt_20GameSceneGroupSprite
.L080179C8: .4byte 0x000034C4

    thumb_func_start func_080179CC
func_080179CC: @ 0x080179CC
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    adds r6, r0, #0
    mov r8, r1
    ldr r0, .L08017A50 @ =vtable_unk_080E5EC4
    str r0, [r6]
    ldr r1, .L08017A54 @ =0x000010C8
    adds r0, r6, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08017A86
    ldr r0, .L08017A58 @ =0x00001038
    adds r4, r6, r0
    ldr r0, [r4]
    ldr r1, .L08017A5C @ =0x00001BD8
    adds r0, r0, r1
    bl func_0800ED2C
    ldr r0, [r4]
    ldr r1, .L08017A60 @ =0x00001CCC
    adds r7, r0, r1
    ldr r1, .L08017A64 @ =0x000010C9
    adds r0, r6, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08017A86
    adds r0, r6, #0
    bl GetSongPlayerPool__20GameSceneWorldPrefix
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .L08017A24
.L08017A12:
    ldr r0, [r4]
    bl IsActive__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08017A70
    adds r4, #4
    cmp r4, r5
    bne .L08017A12
.L08017A24:
    subs r0, r5, #4
    ldr r0, [r0]
.L08017A28:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    adds r0, r7, #0
    bl func_080A45A8
    cmp r0, #2
    beq .L08017A74
    ldr r1, .L08017A58 @ =0x00001038
    adds r0, r6, r1
    ldr r2, [r0]
    ldr r1, .L08017A68 @ =0x00001CD4
    adds r0, r2, r1
    ldr r1, .L08017A6C @ =0x0000214C
    adds r2, r2, r1
    adds r1, r7, #0
    bl func_080A1484
    b .L08017A86
    .align 2, 0
.L08017A50: .4byte vtable_unk_080E5EC4
.L08017A54: .4byte 0x000010C8
.L08017A58: .4byte 0x00001038
.L08017A5C: .4byte 0x00001BD8
.L08017A60: .4byte 0x00001CCC
.L08017A64: .4byte 0x000010C9
.L08017A68: .4byte 0x00001CD4
.L08017A6C: .4byte 0x0000214C
.L08017A70:
    ldr r0, [r4]
    b .L08017A28
.L08017A74:
    ldr r0, .L08017ABC @ =0x0000023B
    movs r1, #0
    str r0, [sp]
    str r1, [sp, #4]
    adds r0, r6, #0
    mov r1, sp
    movs r2, #0
    bl QueueWorldScript
.L08017A86:
    ldr r1, .L08017AC0 @ =0x00001050
    adds r0, r6, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .L08017A94
    bl __builtin_vec_delete
.L08017A94:
    ldr r0, .L08017AC4 @ =0x000010B0
    adds r5, r6, r0
    adds r7, r6, #4
    cmp r5, #0
    beq .L08017ACC
    ldr r1, .L08017AC8 @ =0x000010C8
    adds r4, r6, r1
.L08017AA2:
    cmp r5, r4
    beq .L08017ACC
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .L08017AA2
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    b .L08017AA2
    .align 2, 0
.L08017ABC: .4byte 0x0000023B
.L08017AC0: .4byte 0x00001050
.L08017AC4: .4byte 0x000010B0
.L08017AC8: .4byte 0x000010C8
.L08017ACC:
    movs r1, #0x84
    lsls r1, r1, #5
    adds r0, r6, r1
    cmp r0, #0
    beq .L08017AFC
    adds r1, #0x30
    adds r4, r6, r1
    cmp r0, r4
    beq .L08017AFC
    movs r0, #0x84
    lsls r0, r0, #5
    adds r5, r6, r0
.L08017AE4:
    subs r4, #0xc
    ldr r1, [r4, #8]
    cmp r1, #0
    beq .L08017AF8
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017AF8:
    cmp r5, r4
    bne .L08017AE4
.L08017AFC:
    ldr r1, .L08017BE0 @ =0x0000107C
    adds r4, r6, r1
    ldr r0, [r4]
    cmp r0, #0
    beq .L08017B0C
    movs r1, #3
    bl _._22GameSceneWeatherEffect
.L08017B0C:
    ldr r1, .L08017BE4 @ =0x00001074
    adds r0, r6, r1
    cmp r0, #0
    beq .L08017B32
    cmp r0, r4
    beq .L08017B32
    adds r5, r0, #0
.L08017B1A:
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .L08017B2E
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017B2E:
    cmp r5, r4
    bne .L08017B1A
.L08017B32:
    ldr r1, .L08017BE8 @ =0x0000106C
    adds r0, r6, r1
    cmp r0, #0
    beq .L08017B5E
    adds r1, #8
    adds r4, r6, r1
    cmp r0, r4
    beq .L08017B5E
    ldr r0, .L08017BE8 @ =0x0000106C
    adds r5, r6, r0
.L08017B46:
    subs r4, #4
    ldr r1, [r4]
    cmp r1, #0
    beq .L08017B5A
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017B5A:
    cmp r5, r4
    bne .L08017B46
.L08017B5E:
    ldr r1, .L08017BEC @ =0x00001068
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .L08017B74
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017B74:
    ldr r1, .L08017BF0 @ =0x00001064
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .L08017B8A
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017B8A:
    ldr r1, .L08017BF4 @ =0x0000105C
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .L08017BA0
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017BA0:
    ldr r1, .L08017BF8 @ =0x00001058
    adds r0, r6, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .L08017BB6
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017BB6:
    adds r0, r7, #0
    movs r1, #2
    bl _._18GameSceneWorldData
    ldr r0, .L08017BFC @ =vtable_unk_080E61A0
    str r0, [r6]
    movs r0, #1
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    beq .L08017BD2
    adds r0, r6, #0
    bl __builtin_delete
.L08017BD2:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08017BE0: .4byte 0x0000107C
.L08017BE4: .4byte 0x00001074
.L08017BE8: .4byte 0x0000106C
.L08017BEC: .4byte 0x00001068
.L08017BF0: .4byte 0x00001064
.L08017BF4: .4byte 0x0000105C
.L08017BF8: .4byte 0x00001058
.L08017BFC: .4byte vtable_unk_080E61A0

    .section .text.world_update_after_pause_query, "ax", %progbits
    .align 2, 0

    thumb_func_start func_08017C30
func_08017C30: @ 0x08017C30
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    mov r8, r0
    str r1, [sp, #0x28]
    ldr r4, .L08017D74 @ =0x00001038
    add r4, r8
    ldr r0, [r4]
    ldr r1, .L08017D78 @ =0x00001BD8
    adds r0, r0, r1
    bl func_0800E4FC
    str r0, [sp, #0x2c]
    ldr r1, .L08017D7C @ =0x000010C8
    add r1, r8
    ldrb r0, [r1]
    add r2, sp, #0x20
    mov sb, r2
    cmp r0, #0
    bne .L08017C60
    b .L08017DBE
.L08017C60:
    movs r0, #0
    strb r0, [r1]
    mov r3, r8
    ldr r0, [r3]
    ldr r2, [r0, #0x3c]
    mov r0, r8
    movs r1, #0x4b
    bl _call_via_r2
    ldr r0, [r4]
    ldr r1, .L08017D78 @ =0x00001BD8
    adds r0, r0, r1
    bl func_0800ED2C
    ldr r0, [r4]
    ldr r2, .L08017D80 @ =0x00001CCC
    adds r6, r0, r2
    ldr r0, .L08017D84 @ =0x000010C9
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08017C8E
    b .L08017DBE
.L08017C8E:
    mov r3, r8
    ldr r0, [r3]
    movs r1, #0xa6
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, [r0]
    mov r0, r8
    bl _call_via_r1
    ldr r4, [r0]
    ldr r5, [r0, #4]
    cmp r4, r5
    beq .L08017CBA
.L08017CA8:
    ldr r0, [r4]
    bl IsActive__C23HardwareMusicPlayerSlot
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08017D9C
    adds r4, #4
    cmp r4, r5
    bne .L08017CA8
.L08017CBA:
    subs r0, r5, #4
    ldr r0, [r0]
.L08017CBE:
    movs r1, #0x6d
    bl Start__23HardwareMusicPlayerSlotUs
    adds r0, r6, #0
    bl func_080A45A8
    cmp r0, #2
    beq .L08017DA0
    ldr r0, .L08017D74 @ =0x00001038
    add r0, r8
    ldr r2, [r0]
    ldr r3, .L08017D88 @ =0x00001CD4
    adds r0, r2, r3
    ldr r1, .L08017D8C @ =0x0000214C
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_080A1484
    ldrb r0, [r6, #1]
    lsrs r0, r0, #2
    ldrh r2, [r6, #2]
    ldr r3, .L08017D90 @ =0x000003FF
    ands r2, r3
    lsls r2, r2, #6
    orrs r2, r0
    ldrb r1, [r6, #3]
    lsrs r1, r1, #2
    ldrh r0, [r6, #4]
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    add r3, sp, #0xc
    adds r1, r3, #0
    strh r2, [r1]
    strh r0, [r3, #2]
    mov r2, r8
    ldr r0, [r2]
    ldr r1, [r0, #0x64]
    mov r0, r8
    bl _call_via_r1
    ldr r5, .L08017D94 @ =0x0000102C
    add r5, r8
    adds r6, r0, #0
    ldr r0, [sp, #0xc]
    str r0, [r5, #4]
    movs r4, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L08017D36
    cmp r1, #0
    beq .L08017D36
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017D36:
    str r4, [r5]
    movs r4, #0
    strb r4, [r5, #8]
    movs r0, #0x40
    bl __builtin_new
    movs r1, #2
    str r1, [sp]
    movs r1, #3
    str r1, [sp, #4]
    add r1, sp, #8
    strb r4, [r1]
    adds r1, r6, #0
    ldr r2, .L08017D98 @ =0x000001A9
    mov r3, r8
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    adds r4, r0, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L08017D70
    cmp r1, #0
    beq .L08017D70
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08017D70:
    str r4, [r5]
    b .L08017DBE
    .align 2, 0
.L08017D74: .4byte 0x00001038
.L08017D78: .4byte 0x00001BD8
.L08017D7C: .4byte 0x000010C8
.L08017D80: .4byte 0x00001CCC
.L08017D84: .4byte 0x000010C9
.L08017D88: .4byte 0x00001CD4
.L08017D8C: .4byte 0x0000214C
.L08017D90: .4byte 0x000003FF
.L08017D94: .4byte 0x0000102C
.L08017D98: .4byte 0x000001A9
.L08017D9C:
    ldr r0, [r4]
    b .L08017CBE
.L08017DA0:
    mov r3, r8
    ldr r0, [r3]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r0, r1
    add r1, sp, #0x10
    ldr r2, .L08017E48 @ =0x0000023B
    movs r3, #0
    str r2, [sp, #0x10]
    str r3, [r1, #4]
    ldr r3, [r0]
    mov r0, r8
    movs r2, #0
    bl _call_via_r3
.L08017DBE:
    mov r2, r8
    ldr r0, [r2]
    ldr r2, [r0, #0x40]
    mov r0, r8
    movs r1, #0
    bl _call_via_r2
    adds r6, r0, #0
    mov r3, r8
    ldr r0, [r3, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r1, [r1]
    ldr r1, [r1, #0xc]
    bl _call_via_r1
    mov r1, r8
    ldr r0, [r1, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r0, [r0]
    mov sl, r0
    mov r2, r8
    ldr r0, [r2, #4]
    ldr r0, [r0]
    str r0, [sp, #0x30]
    movs r3, #0
    str r3, [sp, #0x34]
    ldr r0, .L08017E4C @ =0x0000103C
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08017E06
    b .L08018002
.L08017E06:
    ldr r0, .L08017E50 @ =0x00001038
    add r0, r8
    ldr r0, [r0]
    ldr r1, .L08017E54 @ =0x000034C4
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08017E18
    b .L08018002
.L08017E18:
    mov r2, sl
    cmp r2, #0
    beq .L08017E20
    b .L08018002
.L08017E20:
    ldr r0, [r6, #0x14]
    adds r0, #0x98
    ldr r1, [r0]
    adds r0, r6, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08017E34
    b .L08018002
.L08017E34:
    movs r5, #0x82
    lsls r5, r5, #5
    add r5, r8
    ldrb r0, [r5, #4]
    adds r0, #1
    cmp r0, #0x19
    bhs .L08017E58
    strb r0, [r5, #4]
    movs r0, #0
    b .L08017F2E
    .align 2, 0
.L08017E48: .4byte 0x0000023B
.L08017E4C: .4byte 0x0000103C
.L08017E50: .4byte 0x00001038
.L08017E54: .4byte 0x000034C4
.L08017E58:
    mov r3, sl
    strb r3, [r5, #4]
    ldr r4, [r5]
    ldr r1, [r4]
    lsls r1, r1, #5
    lsrs r1, r1, #0x1a
    adds r1, #1
    movs r2, #0x3f
    ands r2, r1
    lsls r2, r2, #5
    ldrh r3, [r4, #2]
    ldr r7, .L08017F80 @ =0xFFFFF81F
    adds r0, r7, #0
    ands r0, r3
    orrs r0, r2
    strh r0, [r4, #2]
    movs r0, #0x3f
    ands r1, r0
    cmp r1, #0x3b
    bls .L08017F2C
    ldr r2, [r5]
    ldrh r1, [r2, #2]
    adds r0, r7, #0
    ands r0, r1
    strh r0, [r2, #2]
    ldr r2, [r5]
    ldr r1, [r2]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x1b
    adds r1, #1
    movs r7, #0x1f
    ands r1, r7
    ldrb r3, [r2, #2]
    movs r4, #0x20
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2, #2]
    cmp r1, #0x17
    bls .L08017F2C
    ldr r2, [r5]
    ldrb r1, [r2, #2]
    adds r0, r4, #0
    ands r0, r1
    strb r0, [r2, #2]
    ldr r4, [r5]
    ldrb r3, [r4, #1]
    lsls r0, r3, #0x19
    lsrs r0, r0, #0x1b
    adds r0, #1
    cmp r0, #0x1e
    bne .L08017ED8
    lsls r0, r3, #0x1e
    lsrs r0, r0, #0x1e
    movs r1, #4
    rsbs r1, r1, #0
    adds r0, #1
    movs r2, #3
    ands r0, r2
    ands r1, r3
    orrs r1, r0
    strb r1, [r4, #1]
    movs r0, #0
.L08017ED8:
    ands r0, r7
    lsls r2, r0, #2
    ldrb r1, [r4, #1]
    movs r0, #0x7d
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #1]
    ldr r2, [r5]
    movs r3, #0
    ldrb r1, [r2, #1]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    bne .L08017EF8
    movs r3, #1
.L08017EF8:
    cmp r3, #0
    beq .L08017F2C
    ldrb r5, [r2]
    lsls r0, r5, #0x1d
    lsrs r0, r0, #0x1d
    adds r3, r0, #1
    cmp r3, #6
    bls .L08017F1C
    movs r3, #0
    lsrs r1, r5, #3
    cmp r1, #0x1c
    bhi .L08017F1C
    adds r1, #1
    lsls r1, r1, #3
    movs r0, #7
    ands r0, r5
    orrs r0, r1
    strb r0, [r2]
.L08017F1C:
    movs r0, #7
    ands r3, r0
    ldrb r1, [r2]
    movs r0, #8
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r3
    strb r0, [r2]
.L08017F2C:
    movs r0, #1
.L08017F2E:
    cmp r0, #0
    beq .L08018002
    movs r0, #0x82
    lsls r0, r0, #5
    add r0, r8
    ldr r0, [r0]
    ldr r0, [r0]
    lsls r1, r0, #0xb
    lsrs r5, r1, #0x1b
    lsls r0, r0, #5
    lsrs r4, r0, #0x1a
    cmp r5, #6
    bne .L08017F88
    cmp r4, #0
    bne .L08017F88
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #0xa
    bl _call_via_r3
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08017FFE
    mov r0, r8
    ldr r2, [r0]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r2, r2, r1
    add r1, sp, #0x18
    ldr r0, .L08017F84 @ =0x000003D5
    str r0, [sp, #0x18]
    str r4, [r1, #4]
    ldr r3, [r2]
    mov r0, r8
    movs r2, #2
    bl _call_via_r3
    b .L08017FFE
    .align 2, 0
.L08017F80: .4byte 0xFFFFF81F
.L08017F84: .4byte 0x000003D5
.L08017F88:
    mov r0, r8
    adds r1, r5, #0
    adds r2, r4, #0
    movs r3, #0
    bl UpdateWorldTimeOfDayPalettes
    cmp r5, #0x14
    bne .L08017FB8
    cmp r4, #0
    bne .L08017FB8
    ldr r0, .L08017FB4 @ =0x00001054
    add r0, r8
    ldr r0, [r0]
    movs r1, #0
    movs r2, #0x9e
    bl PlaySong__9GameSceneiUi
    mov r0, r8
    bl UpdateWorldBackgroundAudio
    b .L08017FFE
    .align 2, 0
.L08017FB4: .4byte 0x00001054
.L08017FB8:
    cmp r5, #0
    bne .L08017FD0
    cmp r4, #0
    bne .L08017FD0
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #3
    bl _call_via_r3
    b .L08017FFE
.L08017FD0:
    cmp r5, #2
    bne .L08017FE8
    cmp r4, #0
    bne .L08017FE8
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #4
    bl _call_via_r3
    b .L08017FFE
.L08017FE8:
    cmp r5, #4
    bne .L08017FFE
    cmp r4, #0
    bne .L08017FFE
    ldr r0, [r6, #0x14]
    ldr r3, [r0, #0x64]
    adds r0, r6, #0
    movs r1, #0
    movs r2, #5
    bl _call_via_r3
.L08017FFE:
    movs r2, #1
    str r2, [sp, #0x34]
.L08018002:
    mov r5, r8
    adds r5, #8
    movs r7, #0xcc
    lsls r7, r7, #1
    add r7, r8
    ldr r3, [sp, #0x28]
    ldr r0, [r3]
    str r0, [sp, #0x20]
    add r0, sp, #0x34
    ldrb r1, [r0]
    mov r0, sb
    strb r1, [r0, #4]
    cmp r5, r7
    beq .L08018064
.L0801801E:
    ldr r4, [r5]
    adds r6, r4, #0
    cmp r4, #0
    beq .L0801805E
    ldr r0, [r4, #0x14]
    ldr r1, [r0, #0x28]
    adds r0, r4, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L08018044
    ldr r0, [r4, #0x14]
    ldr r2, [r0, #0x2c]
    adds r0, r4, #0
    mov r1, sb
    bl _call_via_r2
    b .L0801805E
.L08018044:
    mov r1, sl
    cmp r1, #0
    beq .L08018052
    ldr r2, [sp, #0x30]
    ldrh r4, [r4, #4]
    cmp r2, r4
    bne .L0801805E
.L08018052:
    ldr r0, [r6, #0x14]
    ldr r2, [r0, #0x18]
    adds r0, r6, #0
    mov r1, sb
    bl _call_via_r2
.L0801805E:
    adds r5, #4
    cmp r5, r7
    bne .L0801801E
.L08018064:
    ldr r0, .L080180AC @ =0x0000107C
    add r0, r8
    ldr r0, [r0]
    cmp r0, #0
    beq .L08018072
    bl UpdateParticles__22GameSceneWeatherEffect
.L08018072:
    ldr r0, .L080180B0 @ =0x00001028
    add r0, r8
    ldr r0, [r0]
    cmp r0, #0
    beq .L08018080
    bl func_080AB380
.L08018080:
    movs r6, #0
    ldr r5, .L080180B4 @ =0x0000106C
    add r5, r8
.L08018086:
    ldr r4, [r5]
    cmp r4, #0
    beq .L080180BC
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080180B8
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L080180BC
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L080180BA
    .align 2, 0
.L080180AC: .4byte 0x0000107C
.L080180B0: .4byte 0x00001028
.L080180B4: .4byte 0x0000106C
.L080180B8:
    movs r0, #0
.L080180BA:
    strb r0, [r1]
.L080180BC:
    adds r5, #4
    adds r6, #1
    cmp r6, #1
    bls .L08018086
    movs r6, #0
    ldr r5, .L080180F0 @ =0x00001074
    add r5, r8
.L080180CA:
    ldr r4, [r5]
    cmp r4, #0
    beq .L080180F8
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080180F4
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L080180F8
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L080180F6
    .align 2, 0
.L080180F0: .4byte 0x00001074
.L080180F4:
    movs r0, #0
.L080180F6:
    strb r0, [r1]
.L080180F8:
    adds r5, #4
    adds r6, #1
    cmp r6, #1
    bls .L080180CA
    movs r3, #0
    mov sl, r3
    ldr r0, .L08018130 @ =0x00001088
    add r0, r8
    mov sb, r0
    movs r6, #0x84
    lsls r6, r6, #5
    add r6, r8
.L08018110:
    ldrb r1, [r6, #1]
    lsls r0, r1, #0x1e
    lsrs r7, r0, #0x1e
    cmp r7, #1
    beq .L0801811C
    b .L0801823A
.L0801811C:
    lsls r0, r1, #0x1c
    lsrs r5, r0, #0x1e
    cmp r5, #1
    beq .L080181A4
    cmp r5, #1
    bgt .L08018134
    cmp r5, #0
    beq .L0801813A
    b .L0801823A
    .align 2, 0
.L08018130: .4byte 0x00001088
.L08018134:
    cmp r5, #2
    beq .L080181E0
    b .L0801823A
.L0801813A:
    ldr r4, [r6, #8]
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018160
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r1, r0, #0
    lsls r0, r1, #0x1e
    cmp r0, #0
    bge .L0801815C
    adds r0, r4, #0
    adds r0, #0x3c
    strb r7, [r0]
.L0801815C:
    adds r0, r1, #0
    b .L08018164
.L08018160:
    strb r5, [r1]
    movs r0, #2
.L08018164:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L0801823A
    ldrb r1, [r6, #1]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r1, r0
    movs r0, #4
    orrs r1, r0
    strb r1, [r6, #1]
    ldr r4, [r6, #8]
    adds r0, r4, #0
    adds r0, #0x28
    ldr r1, .L080181A0 @ =0x0000086B
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x3c
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r2, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r0, #0x78
    strb r0, [r6]
    b .L0801823A
    .align 2, 0
.L080181A0: .4byte 0x0000086B
.L080181A4:
    ldrb r0, [r6]
    subs r0, #1
    strb r0, [r6]
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0
    bne .L0801823A
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r6, #1]
    ldr r4, [r6, #8]
    adds r0, r4, #0
    adds r0, #0x28
    ldr r1, .L080181DC @ =0x00000873
    bl ResolveIndexedResourceHandle
    adds r0, r4, #0
    adds r0, #0x3c
    strb r5, [r0]
    adds r0, #2
    strb r7, [r0]
    adds r0, #1
    strb r5, [r0]
    b .L0801823A
    .align 2, 0
.L080181DC: .4byte 0x00000873
.L080181E0:
    ldr r4, [r6, #8]
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018206
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r1, r0, #0
    lsls r0, r1, #0x1e
    cmp r0, #0
    bge .L08018202
    adds r0, r4, #0
    adds r0, #0x3c
    strb r7, [r0]
.L08018202:
    adds r0, r1, #0
    b .L0801820C
.L08018206:
    movs r0, #0
    strb r0, [r1]
    movs r0, #2
.L0801820C:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L0801823A
    ldrb r0, [r6, #1]
    movs r2, #4
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    strb r0, [r6, #1]
    mov r4, sb
    movs r5, #0
    ldr r1, [r6, #8]
    cmp r5, r1
    beq .L08018238
    cmp r1, #0
    beq .L08018238
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L08018238:
    str r5, [r4]
.L0801823A:
    movs r3, #0xc
    add sb, r3
    adds r6, #0xc
    movs r0, #1
    add sl, r0
    mov r1, sl
    cmp r1, #3
    bhi .L0801824C
    b .L08018110
.L0801824C:
    ldr r0, .L080182B4 @ =0x0000103C
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0
    bne .L08018268
    mov r3, r8
    ldr r2, [r3, #8]
    ldr r0, [r3, #4]
    movs r3, #0xa
    ldrsh r1, [r2, r3]
    movs r3, #0xe
    ldrsh r2, [r2, r3]
    bl SetWorldMapCameraPosition
.L08018268:
    ldr r4, .L080182B8 @ =0x00001038
    add r4, r8
    ldr r0, [r4]
    ldr r1, .L080182BC @ =0x00001BD8
    adds r0, r0, r1
    bl func_0800E4FC
    ldr r2, [sp, #0x2c]
    cmp r0, r2
    beq .L080182A2
    ldr r0, .L080182C0 @ =0x00001054
    add r0, r8
    ldr r0, [r0]
    bl IsBackgroundMusicActive__9GameScene
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L080182A2
    ldr r0, [r4]
    ldr r3, .L080182C4 @ =0x0000214C
    adds r0, r0, r3
    bl HasRegisteredEvents__C14GameEventState
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L080182A2
    mov r0, r8
    bl UpdateWorldBackgroundAudio
.L080182A2:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L080182B4: .4byte 0x0000103C
.L080182B8: .4byte 0x00001038
.L080182BC: .4byte 0x00001BD8
.L080182C0: .4byte 0x00001054
.L080182C4: .4byte 0x0000214C

    thumb_func_start func_080182C8
func_080182C8: @ 0x080182C8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, .L080184E4 @ =0xFFFFF320
    add sp, r4
    mov sb, r0
    ldr r0, .L080184E8 @ =0x00000C6C
    add r0, sp
    str r1, [r0]
    movs r0, #0
    ldr r1, .L080184EC @ =0x00000C58
    add r1, sp
    str r0, [r1]
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    movs r2, #0x20
    ldr r0, .L080184EC @ =0x00000C58
    add r0, sp
    ldr r0, [r0]
.L080182F4:
    strb r0, [r1]
    subs r2, #1
    adds r1, #1
    cmp r2, #0
    bgt .L080182F4
    ldr r0, .L080184F0 @ =0x00001024
    add r0, sb
    ldr r2, [r0]
    ldr r3, .L080184E8 @ =0x00000C6C
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r4, r2, #0
    adds r4, #0x9c
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018320
    adds r0, r2, #0
    bl PrepareResources__22EntityAuxiliarySpritesR16HardwareDmaQueue
    movs r0, #0
    strb r0, [r4]
.L08018320:
    ldr r0, .L080184F4 @ =0x0000107C
    add r0, sb
    ldr r2, [r0]
    cmp r2, #0
    beq .L08018346
    ldr r4, .L080184E8 @ =0x00000C6C
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4]
    adds r4, r2, #0
    adds r4, #0xe5
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018346
    adds r0, r2, #0
    bl func_0803B128
    movs r0, #0
    strb r0, [r4]
.L08018346:
    mov r5, sb
    ldr r0, [r5, #4]
    adds r1, r0, #0
    adds r1, #0x90
    ldr r4, [r1]
    ldr r6, .L080184E8 @ =0x00000C6C
    add r6, sp
    ldr r6, [r6]
    ldr r1, [r6]
    ldr r2, [r6, #4]
    ldr r3, [r6, #0xc]
    ldr r4, [r4, #0x10]
    bl _call_via_r4
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    movs r2, #0xdb
    lsls r2, r2, #4
    add r2, sb
    ldrb r0, [r2]
    ldr r1, .L080184F8 @ =0x00000DB1
    add r1, sb
    strb r0, [r1]
    movs r3, #0
    ldr r6, .L080184FC @ =0x00000CBC
    add r6, sp
    str r2, [r6]
    movs r0, #0xcc
    lsls r0, r0, #4
    add r0, sp
    str r1, [r0]
    ldrb r1, [r1]
    cmp r3, r1
    bhs .L080183BE
    movs r5, #0xde
    lsls r5, r5, #1
    add r5, sb
    ldr r2, .L08018500 @ =0x00000D1D
    add r2, sb
.L08018396:
    ldrb r0, [r2]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .L080183B0
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r1, r0, #5
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r1, r5, r1
    adds r1, #0x80
    movs r0, #0xff
    strb r0, [r1]
.L080183B0:
    adds r2, #0xc
    adds r3, #1
    ldr r6, .L08018504 @ =0x00000C15
    adds r0, r4, r6
    ldrb r0, [r0]
    cmp r3, r0
    blo .L08018396
.L080183BE:
    ldr r1, .L08018508 @ =0x00000C14
    adds r0, r4, r1
    movs r2, #0
    strb r2, [r0]
    ldr r3, .L080184E8 @ =0x00000C6C
    add r3, sp
    ldr r3, [r3]
    ldr r0, [r3, #8]
    ldrb r1, [r0]
    movs r0, #0x7c
    subs r0, r0, r1
    movs r4, #0xc7
    lsls r4, r4, #4
    add r4, sp
    str r0, [r4]
    cmp r0, #0x80
    bls .L080183E4
    bl .L08019870
.L080183E4:
    add r0, sp, #0x14
    strb r2, [r0]
    add r0, sp, #0x18
    movs r1, #3
    mov r5, sb
    ldr r4, [r5]
    mov r6, sb
    adds r6, #8
    ldr r2, .L0801850C @ =0x00000C5C
    add r2, sp
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r5, #0xcc
    lsls r5, r5, #1
    add r5, sb
    ldr r2, .L08018510 @ =0x00000CC4
    add r2, sp
    str r5, [r2]
    ldr r3, .L08018514 @ =0x00000828
    add r3, sp
    ldr r5, .L08018518 @ =0x00000CC8
    add r5, sp
    str r3, [r5]
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
.L0801841C:
    str r3, [r0]
    movs r5, #0x81
    lsls r5, r5, #2
    adds r0, r0, r5
    subs r1, #1
    cmp r1, r2
    bne .L0801841C
    ldr r1, [r4, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldr r5, .L0801851C @ =0x00000C28
    add r5, sp
    ldr r2, .L080184E8 @ =0x00000C6C
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    ldr r2, [r2, #4]
    str r1, [r5]
    str r2, [r5, #4]
    add r1, sp, #0x14
    str r1, [r5, #8]
    strh r4, [r5, #0xc]
    strh r0, [r5, #0xe]
    ldr r2, .L08018520 @ =0x00000C98
    add r2, sp
    str r6, [r2]
    ldr r3, .L08018524 @ =0x00000C74
    add r3, sp
    str r6, [r3]
    ldr r4, [r2]
    ldr r1, [r4]
    cmp r1, #0
    beq .L0801847A
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #0x1c]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r2
.L0801847A:
    ldr r0, .L080184F4 @ =0x0000107C
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .L0801848A
    add r1, sp, #0x14
    bl Draw__22GameSceneWeatherEffectP21WorldSpriteDrawBuffer
.L0801848A:
    ldr r0, .L08018528 @ =0x00001028
    add r0, sb
    ldr r0, [r0]
    cmp r0, #0
    beq .L0801849C
    ldr r2, [r5]
    add r1, sp, #0x14
    bl func_080AB410
.L0801849C:
    ldr r1, [r5]
    ldr r2, [r5, #8]
    ldr r0, .L0801850C @ =0x00000C5C
    add r0, sp
    str r1, [r0]
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    str r2, [r5, #4]
    ldr r0, .L0801852C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L080184BC
    b .L0801887E
.L080184BC:
    movs r5, #0
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018530
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r2, r0, #0
    lsls r0, r2, #0x1e
    cmp r0, #0
    bge .L080184E0
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
.L080184E0:
    adds r0, r2, #0
    b .L08018536
    .align 2, 0
.L080184E4: .4byte 0xFFFFF320
.L080184E8: .4byte 0x00000C6C
.L080184EC: .4byte 0x00000C58
.L080184F0: .4byte 0x00001024
.L080184F4: .4byte 0x0000107C
.L080184F8: .4byte 0x00000DB1
.L080184FC: .4byte 0x00000CBC
.L08018500: .4byte 0x00000D1D
.L08018504: .4byte 0x00000C15
.L08018508: .4byte 0x00000C14
.L0801850C: .4byte 0x00000C5C
.L08018510: .4byte 0x00000CC4
.L08018514: .4byte 0x00000828
.L08018518: .4byte 0x00000CC8
.L0801851C: .4byte 0x00000C28
.L08018520: .4byte 0x00000C98
.L08018524: .4byte 0x00000C74
.L08018528: .4byte 0x00001028
.L0801852C: .4byte 0x0000105C
.L08018530:
    movs r0, #0
    strb r0, [r1]
    movs r0, #2
.L08018536:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L0801854A
    movs r0, #0x83
    lsls r0, r0, #5
    add r0, sb
    ldrb r0, [r0]
    cmp r0, #0
    beq .L0801854A
    movs r5, #1
.L0801854A:
    cmp r5, #0
    beq .L08018578
    movs r0, #0x83
    lsls r0, r0, #5
    add r0, sb
    movs r4, #0
    strb r4, [r0]
    ldr r0, .L08018598 @ =0x0000105C
    add r0, sb
    ldr r5, [r0]
    adds r0, r5, #0
    adds r0, #0x28
    movs r1, #1
    bl ResolveIndexedResourceHandle
    adds r0, r5, #0
    adds r0, #0x3c
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r4, [r0]
    adds r0, #1
    strb r1, [r0]
.L08018578:
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    subs r0, #0xa
    cmp r0, #0x1d
    bls .L0801858C
    b .L0801887E
.L0801858C:
    lsls r0, r0, #2
    ldr r1, .L0801859C @ =.L080185A0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L08018598: .4byte 0x0000105C
.L0801859C: .4byte .L080185A0
.L080185A0: @ jump table
    .4byte .L08018770 @ case 0
    .4byte .L0801887E @ case 1
    .4byte .L0801887E @ case 2
    .4byte .L0801887E @ case 3
    .4byte .L0801887E @ case 4
    .4byte .L0801887E @ case 5
    .4byte .L0801887E @ case 6
    .4byte .L0801887E @ case 7
    .4byte .L080186E2 @ case 8
    .4byte .L0801887E @ case 9
    .4byte .L0801887E @ case 10
    .4byte .L0801887E @ case 11
    .4byte .L0801887E @ case 12
    .4byte .L0801887E @ case 13
    .4byte .L0801887E @ case 14
    .4byte .L0801887E @ case 15
    .4byte .L0801887E @ case 16
    .4byte .L0801878C @ case 17
    .4byte .L0801887E @ case 18
    .4byte .L08018618 @ case 19
    .4byte .L0801887E @ case 20
    .4byte .L0801887E @ case 21
    .4byte .L0801887E @ case 22
    .4byte .L0801887E @ case 23
    .4byte .L0801887E @ case 24
    .4byte .L0801887E @ case 25
    .4byte .L0801887E @ case 26
    .4byte .L0801887E @ case 27
    .4byte .L0801887E @ case 28
    .4byte .L08018754 @ case 29
.L08018618:
    ldr r0, .L080186A0 @ =0x0000105C
    add r0, sb
    ldr r5, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r4, #0x30
    subs r0, r4, r0
    mov r8, r0
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r7, r4, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, .L080186A4 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080186B0
.L0801867C:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L080186A8 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xff
    ldr r4, .L080186AC @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080186B2
    .align 2, 0
.L080186A0: .4byte 0x0000105C
.L080186A4: .4byte 0x00000C38
.L080186A8: .4byte 0x01FFFFFF
.L080186AC: .4byte SubmitWorldSpriteRecords
.L080186B0:
    movs r0, #0
.L080186B2:
    cmp r0, #0
    bne .L080186B8
    b .L0801887E
.L080186B8:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L080186C6
    b .L0801887E
.L080186C6:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080186E0
    b .L08018852
.L080186E0:
    b .L08018860
.L080186E2:
    ldr r0, .L0801874C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x68
.L080186F6:
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018750 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L0801867C
    b .L080186B0
    .align 2, 0
.L0801874C: .4byte 0x0000105C
.L08018750: .4byte 0x00000C38
.L08018754:
    ldr r0, .L0801876C @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x18
    b .L080186F6
    .align 2, 0
.L0801876C: .4byte 0x0000105C
.L08018770:
    ldr r0, .L08018788 @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x38
    b .L080186F6
    .align 2, 0
.L08018788: .4byte 0x0000105C
.L0801878C:
    ldr r0, .L08018818 @ =0x0000105C
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x68
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L0801881C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018828
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018820 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xff
    ldr r4, .L08018824 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801882A
    .align 2, 0
.L08018818: .4byte 0x0000105C
.L0801881C: .4byte 0x00000C38
.L08018820: .4byte 0x01FFFFFF
.L08018824: .4byte SubmitWorldSpriteRecords
.L08018828:
    movs r0, #0
.L0801882A:
    cmp r0, #0
    beq .L0801887E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L0801887E
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018860
.L08018852:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L0801887A
.L08018860:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L0801887A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L0801887A:
    movs r0, #0
    strb r0, [r7]
.L0801887E:
    ldr r0, .L080188AC @ =0x00001064
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L0801888A
    b .L080189A6
.L0801888A:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080188B0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L080188B4
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L080188B2
    .align 2, 0
.L080188AC: .4byte 0x00001064
.L080188B0:
    movs r0, #0
.L080188B2:
    strb r0, [r1]
.L080188B4:
    ldr r0, .L08018940 @ =0x00001064
    add r0, sb
    ldr r4, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x58
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x10
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018944 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018950
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018948 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L0801894C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018952
    .align 2, 0
.L08018940: .4byte 0x00001064
.L08018944: .4byte 0x00000C38
.L08018948: .4byte 0x01FFFFFF
.L0801894C: .4byte SubmitWorldSpriteRecords
.L08018950:
    movs r0, #0
.L08018952:
    cmp r0, #0
    beq .L080189A6
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L080189A6
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018988
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080189A2
.L08018988:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080189A2
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080189A2:
    movs r0, #0
    strb r0, [r7]
.L080189A6:
    movs r3, #0
    ldr r4, .L08018A5C @ =0x00000C78
    add r4, sp
    str r3, [r4]
    movs r5, #0xde
    lsls r5, r5, #2
    movs r6, #0xcd
    lsls r6, r6, #4
    add r6, sp
    str r5, [r6]
    ldr r0, .L08018A60 @ =0x0000106C
    add r0, sb
    ldr r1, .L08018A64 @ =0x00000CD4
    add r1, sp
    str r0, [r1]
.L080189C4:
    ldr r2, .L08018A64 @ =0x00000CD4
    add r2, sp
    ldr r2, [r2]
    ldr r4, [r2]
    cmp r4, #0
    beq .L08018ACA
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r5, #0xcd
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    subs r0, r5, r0
    mov r8, r0
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xf0
    lsls r1, r1, #1
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, .L08018A68 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018A74
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    ldr r4, .L08018A6C @ =0x01FFFFFF
    str r4, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018A70 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018A76
    .align 2, 0
.L08018A5C: .4byte 0x00000C78
.L08018A60: .4byte 0x0000106C
.L08018A64: .4byte 0x00000CD4
.L08018A68: .4byte 0x00000C38
.L08018A6C: .4byte 0x01FFFFFF
.L08018A70: .4byte SubmitWorldSpriteRecords
.L08018A74:
    movs r0, #0
.L08018A76:
    cmp r0, #0
    beq .L08018ACA
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018ACA
    mov r0, sl
    ldr r1, [r0]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018AAC
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018AC6
.L08018AAC:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018AC6
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018AC6:
    movs r0, #0
    strb r0, [r7]
.L08018ACA:
    movs r2, #0xcd
    lsls r2, r2, #4
    add r2, sp
    ldr r1, [r2]
    adds r1, #0x28
    str r1, [r2]
    ldr r4, .L08018B1C @ =0x00000CD4
    add r4, sp
    ldr r3, [r4]
    adds r3, #4
    str r3, [r4]
    ldr r6, .L08018B20 @ =0x00000C78
    add r6, sp
    ldr r5, [r6]
    adds r5, #1
    str r5, [r6]
    cmp r5, #1
    bhi .L08018AF0
    b .L080189C4
.L08018AF0:
    ldr r4, .L08018B24 @ =0x00001074
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .L08018AFC
    b .L08018D76
.L08018AFC:
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #2
    bne .L08018B0E
    b .L08018C8E
.L08018B0E:
    cmp r0, #2
    bgt .L08018B28
    cmp r0, #0
    bne .L08018B18
    b .L08018C68
.L08018B18:
    b .L08018D76
    .align 2, 0
.L08018B1C: .4byte 0x00000CD4
.L08018B20: .4byte 0x00000C78
.L08018B24: .4byte 0x00001074
.L08018B28:
    cmp r0, #3
    beq .L08018BFA
    cmp r0, #7
    beq .L08018B32
    b .L08018D76
.L08018B32:
    ldr r4, [r4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x86
    subs r7, r1, r0
    adds r5, r4, #0
    movs r4, #0xcb
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    mov sl, r4
    ldr r4, .L08018BBC @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018BC8
.L08018B98:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018BC0 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018BC4 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018BCA
    .align 2, 0
.L08018BBC: .4byte 0x00000C38
.L08018BC0: .4byte 0x01FFFFFF
.L08018BC4: .4byte SubmitWorldSpriteRecords
.L08018BC8:
    movs r0, #0
.L08018BCA:
    cmp r0, #0
    bne .L08018BD0
    b .L08018D76
.L08018BD0:
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L08018BDE
    b .L08018D76
.L08018BDE:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018BF8
    b .L08018D4A
.L08018BF8:
    b .L08018D58
.L08018BFA:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x9b
    lsls r1, r1, #2
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x76
.L08018C1E:
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018C64 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L08018B98
    b .L08018BC8
    .align 2, 0
.L08018C64: .4byte 0x00000C38
.L08018C68:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xb0
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    b .L08018C1E
.L08018C8E:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x88
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x23
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018D14 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018D20
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018D18 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018D1C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018D22
    .align 2, 0
.L08018D14: .4byte 0x00000C38
.L08018D18: .4byte 0x01FFFFFF
.L08018D1C: .4byte SubmitWorldSpriteRecords
.L08018D20:
    movs r0, #0
.L08018D22:
    cmp r0, #0
    beq .L08018D76
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018D76
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018D58
.L08018D4A:
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018D72
.L08018D58:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018D72
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018D72:
    movs r0, #0
    strb r0, [r7]
.L08018D76:
    ldr r0, .L08018E04 @ =0x00001078
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    beq .L08018E6E
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r1, .L08018E08 @ =0x00000235
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x13
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    ldr r4, .L08018E0C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018E18
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08018E10 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0x55
    ldr r4, .L08018E14 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018E1A
    .align 2, 0
.L08018E04: .4byte 0x00001078
.L08018E08: .4byte 0x00000235
.L08018E0C: .4byte 0x00000C38
.L08018E10: .4byte 0x01FFFFFF
.L08018E14: .4byte SubmitWorldSpriteRecords
.L08018E18:
    movs r0, #0
.L08018E1A:
    cmp r0, #0
    beq .L08018E6E
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08018E6E
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018E50
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08018E6A
.L08018E50:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08018E6A
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08018E6A:
    movs r0, #0
    strb r0, [r7]
.L08018E6E:
    ldr r0, .L08018E9C @ =0x00001058
    add r0, sb
    ldr r4, [r0]
    cmp r4, #0
    bne .L08018E7A
    b .L080190C2
.L08018E7A:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L08018EA0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L08018EA4
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    b .L08018EA2
    .align 2, 0
.L08018E9C: .4byte 0x00001058
.L08018EA0:
    movs r0, #0
.L08018EA2:
    strb r0, [r1]
.L08018EA4:
    ldr r0, .L08018ED0 @ =0x00001038
    add r0, sb
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl GetUpgradeLevel__C9FarmHouse
    adds r5, r0, #0
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .L08018ED4
    cmp r0, #0x27
    bne .L08018ECC
    b .L08018FCA
.L08018ECC:
    b .L080190C2
    .align 2, 0
.L08018ED0: .4byte 0x00001038
.L08018ED4:
    ldr r0, .L08018F6C @ =0x00001058
    add r0, sb
    ldr r6, [r0]
    mov r1, sb
    ldr r0, [r1]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, .L08018F70 @ =gUnk_080F06FD
    lsls r5, r5, #1
    adds r1, r5, r4
    ldrb r1, [r1]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r4, #1
    adds r5, r5, r4
    ldrb r1, [r5]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov sl, r3
    ldr r4, .L08018F74 @ =0x00000C38
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08018F80
    ldrh r1, [r6, #0xc]
    adds r2, r6, #0
    adds r2, #0x10
    ldr r0, .L08018F78 @ =0x01FFFFFF
    str r0, [sp]
    str r5, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08018F7C @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08018F82
    .align 2, 0
.L08018F6C: .4byte 0x00001058
.L08018F70: .4byte gUnk_080F06FD
.L08018F74: .4byte 0x00000C38
.L08018F78: .4byte 0x01FFFFFF
.L08018F7C: .4byte SubmitWorldSpriteRecords
.L08018F80:
    movs r0, #0
.L08018F82:
    cmp r0, #0
    bne .L08018F88
    b .L080190C2
.L08018F88:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne .L08018F96
    b .L080190C2
.L08018F96:
    mov r2, sl
    ldr r1, [r2]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08018FB6
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b .L0801909C
.L08018FB6:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08018FC2
    b .L080190BE
.L08018FC2:
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    b .L080190B4
.L08018FCA:
    ldr r0, .L08019058 @ =0x00001058
    add r0, sb
    ldr r5, [r0]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    ldr r4, .L0801905C @ =gUnk_080F06FD
    ldrb r1, [r4]
    lsls r1, r1, #3
    subs r1, r1, r0
    mov r8, r1
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    ldrb r1, [r4, #1]
    lsls r1, r1, #3
    subs r7, r1, r0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    ldr r4, .L08019060 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r4, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L0801906C
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L08019064 @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08019068 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801906E
    .align 2, 0
.L08019058: .4byte 0x00001058
.L0801905C: .4byte gUnk_080F06FD
.L08019060: .4byte 0x00000C38
.L08019064: .4byte 0x01FFFFFF
.L08019068: .4byte SubmitWorldSpriteRecords
.L0801906C:
    movs r0, #0
.L0801906E:
    cmp r0, #0
    beq .L080190C2
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L080190C2
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080190A4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
.L0801909C:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080190BE
.L080190A4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080190BE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
.L080190B4:
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080190BE:
    movs r0, #0
    strb r0, [r7]
.L080190C2:
    ldr r4, .L08019100 @ =0x00001068
    add r4, sb
    ldr r0, [r4]
    cmp r0, #0
    bne .L080190CE
    b .L08019232
.L080190CE:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r0, #0x1d
    beq .L080190E0
    b .L08019232
.L080190E0:
    ldr r0, .L08019104 @ =0x00001038
    add r0, sb
    ldr r0, [r0]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    bl GetUpgradeLevel__C9FarmHouse
    cmp r0, #1
    beq .L0801914C
    cmp r0, #1
    blo .L08019108
    cmp r0, #2
    beq .L0801918C
    b .L08019232
    .align 2, 0
.L08019100: .4byte 0x00001068
.L08019104: .4byte 0x00001038
.L08019108:
    ldr r4, [r4]
    mov r6, sb
    ldr r0, [r6]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xa0
    subs r1, r1, r0
    mov r8, r1
    ldr r0, [r6]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    mov sl, r0
    adds r6, r5, #0
    adds r6, #0x28
.L0801913A:
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    blt .L080191DA
    b .L08019204
.L0801914C:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x8c
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    b .L0801913A
.L0801918C:
    ldr r4, [r4]
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0xac
    lsls r1, r1, #1
    subs r1, r1, r0
    mov r8, r1
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    movs r1, #0x30
    subs r7, r1, r0
    adds r5, r4, #0
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    mov sl, r6
    adds r6, r5, #0
    adds r6, #0x28
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r4, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r3}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L08019204
.L080191DA:
    ldrh r1, [r5, #0xc]
    adds r2, r5, #0
    adds r2, #0x10
    ldr r0, .L080191FC @ =0x01FFFFFF
    str r0, [sp]
    str r6, [sp, #4]
    str r3, [sp, #8]
    str r1, [sp, #0xc]
    str r2, [sp, #0x10]
    adds r0, r4, #0
    mov r1, r8
    adds r2, r7, #0
    movs r3, #0xaa
    ldr r4, .L08019200 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L08019206
    .align 2, 0
.L080191FC: .4byte 0x01FFFFFF
.L08019200: .4byte SubmitWorldSpriteRecords
.L08019204:
    movs r0, #0
.L08019206:
    cmp r0, #0
    beq .L08019232
    adds r4, r5, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .L08019232
    mov r2, sl
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
.L08019232:
    ldr r1, .L08019274 @ =0x0000102C
    add r1, sb
    ldr r4, [r1]
    rsbs r0, r4, #0
    orrs r0, r4
    cmp r0, #0
    blt .L08019242
    b .L08019502
.L08019242:
    adds r5, r1, #0
    ldrb r2, [r5, #8]
    cmp r2, #0
    beq .L080192AA
    ldrb r0, [r5, #9]
    subs r0, #1
    movs r2, #0
    strb r0, [r5, #9]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L08019278
    ldr r1, [r5]
    cmp r2, r1
    beq .L0801926E
    cmp r1, #0
    beq .L0801926E
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801926E:
    movs r0, #0
    str r0, [r5]
    b .L0801929E
    .align 2, 0
.L08019274: .4byte 0x0000102C
.L08019278:
    ldr r4, [r5]
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L0801929C
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    lsls r0, r0, #0x1e
    cmp r0, #0
    bge .L0801929E
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
    b .L0801929E
.L0801929C:
    strb r2, [r1]
.L0801929E:
    ldrb r0, [r5, #0xa]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r5, #0xa]
    b .L080192F4
.L080192AA:
    adds r1, r4, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #0
    bne .L080192D0
    adds r0, r4, #0
    adds r0, #0x28
    bl UpdateIndexedResourceHandle
    adds r2, r0, #0
    lsls r0, r2, #0x1e
    cmp r0, #0
    bge .L080192CC
    adds r1, r4, #0
    adds r1, #0x3c
    movs r0, #1
    strb r0, [r1]
.L080192CC:
    adds r0, r2, #0
    b .L080192D4
.L080192D0:
    strb r2, [r1]
    movs r0, #2
.L080192D4:
    lsls r0, r0, #0x1d
    cmp r0, #0
    bge .L080192F4
    movs r4, #0
    ldr r1, [r5]
    cmp r4, r1
    beq .L080192F2
    cmp r1, #0
    beq .L080192F2
    ldr r0, [r1, #0x24]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L080192F2:
    str r4, [r5]
.L080192F4:
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    adds r4, r0, #0
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    adds r2, r0, #0
    ldr r1, .L080193BC @ =0x0000102C
    add r1, sb
    movs r6, #0xcb
    lsls r6, r6, #4
    add r6, sp
    ldr r6, [r6]
    ldr r0, .L080193C0 @ =0x00000C7C
    add r0, sp
    str r6, [r0]
    ldr r5, [r1]
    rsbs r0, r5, #0
    orrs r0, r5
    cmp r0, #0
    blt .L0801932E
    b .L08019502
.L0801932E:
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne .L08019336
    b .L08019430
.L08019336:
    ldrb r0, [r1, #0xa]
    cmp r0, #2
    bhi .L0801933E
    b .L08019502
.L0801933E:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    movs r6, #0xc8
    lsls r6, r6, #4
    add r6, sp
    str r0, [r6]
    movs r0, #6
    ldrsh r1, [r1, r0]
    subs r2, r1, r2
    mov sl, r2
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r1
    mov r8, r0
    adds r6, r5, #0
    ldr r4, .L080193C4 @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r7, r4, #0
    movs r1, #0xcb
    lsls r1, r1, #4
    add r1, sp
    ldr r1, [r1]
    ldr r3, [r1, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080193CC
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    mov r4, r8
    str r4, [sp]
    str r7, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    movs r5, #0xc8
    lsls r5, r5, #4
    add r5, sp
    ldr r1, [r5]
    mov r2, sl
    movs r3, #0xaa
    ldr r4, .L080193C8 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080193CE
    .align 2, 0
.L080193BC: .4byte 0x0000102C
.L080193C0: .4byte 0x00000C7C
.L080193C4: .4byte 0x00000C38
.L080193C8: .4byte SubmitWorldSpriteRecords
.L080193CC:
    movs r0, #0
.L080193CE:
    cmp r0, #0
    bne .L080193D4
    b .L08019502
.L080193D4:
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r5, r0, #0
    cmp r1, #0
    bne .L080193E2
    b .L08019502
.L080193E2:
    ldr r0, .L0801940C @ =0x00000C7C
    add r0, sp
    ldr r0, [r0]
    ldr r1, [r0]
    adds r2, r7, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L08019410
    adds r1, r7, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L0801942A
    .align 2, 0
.L0801940C: .4byte 0x00000C7C
.L08019410:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L0801942A
    adds r1, r7, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L0801942A:
    movs r0, #0
    strb r0, [r5]
    b .L08019502
.L08019430:
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r0, r0, r4
    mov sl, r0
    movs r4, #6
    ldrsh r1, [r1, r4]
    subs r2, r1, r2
    mov r8, r2
    movs r0, #0x80
    lsls r0, r0, #8
    subs r7, r0, r1
    ldr r4, .L0801949C @ =0x00000C38
    add r4, sp
    ldr r1, [r5, #0x28]
    ldr r3, [r1]
    ldrh r2, [r5, #0x34]
    lsls r2, r2, #2
    ldr r0, [r5, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r6, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r3, [r0, #4]
    adds r0, r5, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080194A4
    ldrh r0, [r5, #0xc]
    adds r1, r5, #0
    adds r1, #0x10
    str r7, [sp]
    str r6, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    mov r1, sl
    mov r2, r8
    movs r3, #0xaa
    ldr r4, .L080194A0 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080194A6
    .align 2, 0
.L0801949C: .4byte 0x00000C38
.L080194A0: .4byte SubmitWorldSpriteRecords
.L080194A4:
    movs r0, #0
.L080194A6:
    cmp r0, #0
    beq .L08019502
    adds r0, r5, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    beq .L08019502
    ldr r2, .L080194E0 @ =0x00000C7C
    add r2, sp
    ldr r2, [r2]
    ldr r1, [r2]
    adds r2, r6, #0
    adds r2, #8
    adds r0, r5, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r5, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L080194E4
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L080194FE
    .align 2, 0
.L080194E0: .4byte 0x00000C7C
.L080194E4:
    adds r4, r5, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L080194FE
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L080194FE:
    movs r0, #0
    strb r0, [r7]
.L08019502:
    movs r3, #0
    ldr r4, .L080195CC @ =0x00000C84
    add r4, sp
    str r3, [r4]
    ldr r7, .L080195D0 @ =0x00001084
    add r7, sb
    ldr r5, .L080195D4 @ =0x00001081
    add r5, sb
    ldr r6, .L080195D8 @ =0x00000CCC
    add r6, sp
    str r5, [r6]
.L08019518:
    ldr r1, .L080195D8 @ =0x00000CCC
    add r1, sp
    ldr r1, [r1]
    ldrb r0, [r1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .L0801952A
    b .L0801964C
.L0801952A:
    ldrh r4, [r7]
    lsls r4, r4, #3
    adds r4, #8
    ldrh r5, [r7, #2]
    lsls r5, r5, #3
    adds r5, #8
    ldr r6, [r7, #4]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r3, .L080195DC @ =0x00000C88
    add r3, sp
    str r4, [r3]
    mov r4, sb
    ldr r0, [r4]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r5, r0
    mov sl, r0
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r5
    mov r8, r0
    movs r5, #0xcb
    lsls r5, r5, #4
    add r5, sp
    ldr r5, [r5]
    ldr r0, .L080195E0 @ =0x00000C8C
    add r0, sp
    str r5, [r0]
    ldr r4, .L080195E4 @ =0x00000C38
    add r4, sp
    ldr r1, [r6, #0x28]
    ldr r3, [r1]
    ldrh r2, [r6, #0x34]
    lsls r2, r2, #2
    ldr r0, [r6, #0x2c]
    adds r0, r0, r2
    ldrh r2, [r0]
    adds r0, r4, #0
    ldr r3, [r3, #0x10]
    bl _call_via_r3
    adds r5, r4, #0
    movs r0, #0xcb
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    ldr r3, [r0, #4]
    adds r0, r6, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L080195EC
    ldrh r0, [r6, #0xc]
    adds r1, r6, #0
    adds r1, #0x10
    mov r4, r8
    str r4, [sp]
    str r5, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    adds r0, r3, #0
    ldr r2, .L080195DC @ =0x00000C88
    add r2, sp
    ldr r1, [r2]
    mov r2, sl
    movs r3, #0xaa
    ldr r4, .L080195E8 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L080195EE
    .align 2, 0
.L080195CC: .4byte 0x00000C84
.L080195D0: .4byte 0x00001084
.L080195D4: .4byte 0x00001081
.L080195D8: .4byte 0x00000CCC
.L080195DC: .4byte 0x00000C88
.L080195E0: .4byte 0x00000C8C
.L080195E4: .4byte 0x00000C38
.L080195E8: .4byte SubmitWorldSpriteRecords
.L080195EC:
    movs r0, #0
.L080195EE:
    cmp r0, #0
    beq .L0801964C
    adds r0, r6, #0
    adds r0, #0x3c
    ldrb r1, [r0]
    mov r8, r0
    cmp r1, #0
    beq .L0801964C
    ldr r3, .L08019628 @ =0x00000C8C
    add r3, sp
    ldr r3, [r3]
    ldr r1, [r3]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r0, r6, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #0
    beq .L0801962C
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    b .L08019646
    .align 2, 0
.L08019628: .4byte 0x00000C8C
.L0801962C:
    adds r4, r6, #0
    adds r4, #0x3e
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08019646
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #1
    strb r0, [r4]
.L08019646:
    movs r0, #0
    mov r4, r8
    strb r0, [r4]
.L0801964C:
    adds r7, #0xc
    ldr r6, .L08019758 @ =0x00000CCC
    add r6, sp
    ldr r5, [r6]
    adds r5, #0xc
    str r5, [r6]
    ldr r1, .L0801975C @ =0x00000C84
    add r1, sp
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    cmp r0, #3
    bhi .L08019668
    b .L08019518
.L08019668:
    ldr r0, .L08019760 @ =gUnk_0300040C
    ldr r0, [r0]
    movs r2, #0
    movs r3, #0xc9
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    ldr r4, .L08019764 @ =0x000004DC
    adds r7, r0, r4
.L0801967A:
    ldrb r0, [r7]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    beq .L08019686
    b .L080197AA
.L08019686:
    ldrh r4, [r7, #2]
    lsls r4, r4, #0x16
    lsrs r4, r4, #0x16
    mov r5, sb
    ldr r0, [r5]
    ldr r1, [r0, #0x14]
    mov r0, sb
    bl _call_via_r1
    cmp r4, r0
    beq .L0801969E
    b .L080197AA
.L0801969E:
    ldrb r1, [r7, #3]
    lsrs r1, r1, #2
    ldrh r4, [r7, #4]
    ldr r0, .L08019768 @ =0x000003FF
    ands r4, r0
    lsls r4, r4, #6
    orrs r4, r1
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r6, [r7, #4]
    lsls r6, r6, #6
    asrs r6, r6, #0x10
    ldrb r5, [r7]
    lsls r5, r5, #0x1c
    lsrs r5, r5, #0x1e
    ldr r0, .L0801976C @ =0x000010B0
    add r0, sb
    movs r2, #0xc9
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #2
    adds r0, r0, r1
    ldr r0, [r0]
    mov r8, r0
    mov r3, sb
    ldr r0, [r3]
    ldr r1, [r0, #0x18]
    mov r0, sb
    bl _call_via_r1
    subs r4, r4, r0
    ldr r1, .L08019770 @ =0x00000C94
    add r1, sp
    str r4, [r1]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, [r0, #0x1c]
    mov r0, sb
    bl _call_via_r1
    subs r0, r6, r0
    mov ip, r0
    movs r0, #0x80
    lsls r0, r0, #8
    subs r0, r0, r6
    mov sl, r0
    mov r6, r8
    movs r3, #0xcb
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    mov r8, r3
    lsls r3, r5, #2
    orrs r3, r5
    lsls r0, r5, #4
    orrs r3, r0
    lsls r5, r5, #6
    orrs r3, r5
    adds r5, r6, #0
    adds r5, #0x28
    mov r4, r8
    ldr r4, [r4, #4]
    ldr r0, .L08019774 @ =0x00000CD8
    add r0, sp
    str r4, [r0]
    adds r0, r6, #0
    ldm r0!, {r2}
    ldr r1, [r0, #4]
    rsbs r0, r1, #0
    orrs r0, r1
    cmp r0, #0
    bge .L0801977C
    ldrh r0, [r6, #0xc]
    adds r1, r6, #0
    adds r1, #0x10
    mov r4, sl
    str r4, [sp]
    str r5, [sp, #4]
    str r2, [sp, #8]
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    ldr r1, .L08019774 @ =0x00000CD8
    add r1, sp
    ldr r0, [r1]
    ldr r2, .L08019770 @ =0x00000C94
    add r2, sp
    ldr r1, [r2]
    mov r2, ip
    ldr r4, .L08019778 @ =SubmitWorldSpriteRecords
    bl _call_via_r4
    b .L0801977E
    .align 2, 0
.L08019758: .4byte 0x00000CCC
.L0801975C: .4byte 0x00000C84
.L08019760: .4byte gUnk_0300040C
.L08019764: .4byte 0x000004DC
.L08019768: .4byte 0x000003FF
.L0801976C: .4byte 0x000010B0
.L08019770: .4byte 0x00000C94
.L08019774: .4byte 0x00000CD8
.L08019778: .4byte SubmitWorldSpriteRecords
.L0801977C:
    movs r0, #0
.L0801977E:
    cmp r0, #0
    beq .L080197AA
    adds r4, r6, #0
    adds r4, #0x48
    ldrb r0, [r4]
    cmp r0, #0
    beq .L080197AA
    mov r3, r8
    ldr r1, [r3]
    adds r2, r5, #0
    adds r2, #8
    adds r0, r6, #0
    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange
    adds r1, r5, #0
    adds r1, #0x10
    adds r0, r6, #0
    movs r2, #1
    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc
    movs r0, #0
    strb r0, [r4]
.L080197AA:
    adds r7, #0xc
    movs r5, #0xc9
    lsls r5, r5, #4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    str r4, [r5]
    cmp r4, #6
    bhs .L080197BE
    b .L0801967A
.L080197BE:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    ldr r5, [r0]
    cmp r5, #0x64
    blo .L080197CC
    movs r5, #0
.L080197CC:
    lsls r0, r5, #2
    ldr r1, .L080197F4 @ =0x00000C98
    add r1, sp
    ldr r1, [r1]
    adds r6, r1, r0
    ldr r2, .L080197F8 @ =0x00000CC4
    add r2, sp
    ldr r7, [r2]
    adds r4, r6, #0
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r3, #0xc7
    lsls r3, r3, #4
    add r3, sp
    ldr r3, [r3]
    cmp r0, r3
    blo .L080197FC
    subs r0, r4, r1
    b .L08019842
    .align 2, 0
.L080197F4: .4byte 0x00000C98
.L080197F8: .4byte 0x00000CC4
.L080197FC:
    ldr r0, .L08019970 @ =0x00000C74
    add r0, sp
    ldr r0, [r0]
    cmp r4, r0
    beq .L0801981A
    ldr r3, [r4]
    cmp r3, #0
    beq .L0801981A
    ldr r0, [r3, #0x14]
    ldr r1, .L08019974 @ =0x00000C28
    add r1, sp
    ldr r2, [r0, #0x1c]
    adds r0, r3, #0
    bl _call_via_r2
.L0801981A:
    adds r4, #4
    cmp r4, r7
    bne .L08019826
    ldr r1, .L08019978 @ =0x00000C98
    add r1, sp
    ldr r4, [r1]
.L08019826:
    cmp r4, r6
    beq .L08019844
    add r0, sp, #0x14
    ldrb r0, [r0]
    movs r2, #0xc7
    lsls r2, r2, #4
    add r2, sp
    ldr r2, [r2]
    cmp r0, r2
    blo .L080197FC
    ldr r3, .L08019978 @ =0x00000C98
    add r3, sp
    ldr r3, [r3]
    subs r0, r4, r3
.L08019842:
    asrs r5, r0, #2
.L08019844:
    movs r0, #0xcc
    lsls r0, r0, #1
    add r0, sb
    str r5, [r0]
    ldr r4, .L0801997C @ =0x00000C6C
    add r4, sp
    ldr r4, [r4]
    ldr r1, [r4, #8]
    add r0, sp, #0x14
    bl func_08094A3C
    ldr r5, .L08019980 @ =0x00000CC8
    add r5, sp
    ldr r0, [r5]
    add r6, sp, #0x18
    cmp r6, r0
    beq .L08019870
    adds r1, r6, #0
.L08019868:
    ldr r2, .L08019984 @ =0xFFFFFDFC
    adds r0, r0, r2
    cmp r1, r0
    bne .L08019868
.L08019870:
    mov r3, sb
    ldr r0, [r3, #4]
    ldr r0, [r0, #4]
    bl GetMapData
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #1
    movs r4, #0xce
    lsls r4, r4, #1
    add r4, sb
    ldr r5, .L08019988 @ =0x00000C9C
    add r5, sp
    str r4, [r5]
    ldr r6, .L0801997C @ =0x00000C6C
    add r6, sp
    ldr r6, [r6]
    ldr r7, [r6]
    adds r2, r1, #0
    eors r2, r0
    movs r3, #0xca
    lsls r3, r3, #4
    add r3, sp
    str r2, [r3]
    movs r4, #0
    ldr r5, .L0801998C @ =0x00000CA4
    add r5, sp
    str r4, [r5]
    ldr r6, .L08019990 @ =0x00000CBC
    add r6, sp
    ldr r6, [r6]
    ldrb r6, [r6]
    ldr r0, .L08019994 @ =0x00000CA8
    add r0, sp
    str r6, [r0]
    cmp r4, r6
    blo .L080198BC
    b .L08019B10
.L080198BC:
    ldr r1, .L08019988 @ =0x00000C9C
    add r1, sp
    ldr r1, [r1]
    ldr r2, .L08019998 @ =0x00000B78
    adds r0, r1, r2
    ldr r2, .L0801998C @ =0x00000CA4
    add r2, sp
    ldr r2, [r2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r0, r0, r1
    mov sl, r0
    ldrb r0, [r0, #9]
    lsrs r0, r0, #7
    adds r2, #1
    ldr r4, .L0801999C @ =0x00000CB4
    add r4, sp
    str r2, [r4]
    cmp r0, #0
    beq .L080198E8
    b .L08019AF8
.L080198E8:
    mov r5, sl
    movs r1, #9
    ldrsb r1, [r5, r1]
    ldr r6, .L08019988 @ =0x00000C9C
    add r6, sp
    ldr r2, [r6]
    adds r2, #0x20
    lsls r0, r1, #5
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    mov r8, r2
    mov r4, r8
    adds r4, #0x82
    ldrb r0, [r4]
    cmp r0, #0
    bne .L08019912
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    beq .L08019912
    b .L08019AF8
.L08019912:
    mov r1, r8
    adds r1, #0x60
    movs r0, #0xca
    lsls r0, r0, #4
    add r0, sp
    ldr r0, [r0]
    cmp r0, #0
    bne .L08019924
    mov r1, r8
.L08019924:
    mov r3, sl
    ldrb r2, [r3, #8]
    lsls r2, r2, #5
    ldr r5, .L080199A0 @ =0x05000200
    adds r2, r2, r5
    add r0, sp, #0x14
    movs r3, #0x20
    bl __21DmaTransferDescriptorPCvPvUi
    mov r6, sp
    adds r6, #0x14
    ldr r0, .L080199A4 @ =0x00000CAC
    add r0, sp
    str r6, [r0]
    ldr r1, [r7, #4]
    ldr r0, [r7, #0xc]
    cmp r1, r0
    beq .L080199A8
    cmp r1, #0
    beq .L08019958
    adds r0, r1, #0
    add r1, sp, #0x14
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, [r1]
    str r1, [r0]
.L08019958:
    ldr r0, [r7, #4]
    adds r0, #0x10
    str r0, [r7, #4]
    mov r8, r4
    ldr r0, .L0801998C @ =0x00000CA4
    add r0, sp
    ldr r6, [r0]
    adds r6, #1
    ldr r0, .L0801999C @ =0x00000CB4
    add r0, sp
    str r6, [r0]
    b .L08019ADE
    .align 2, 0
.L08019970: .4byte 0x00000C74
.L08019974: .4byte 0x00000C28
.L08019978: .4byte 0x00000C98
.L0801997C: .4byte 0x00000C6C
.L08019980: .4byte 0x00000CC8
.L08019984: .4byte 0xFFFFFDFC
.L08019988: .4byte 0x00000C9C
.L0801998C: .4byte 0x00000CA4
.L08019990: .4byte 0x00000CBC
.L08019994: .4byte 0x00000CA8
.L08019998: .4byte 0x00000B78
.L0801999C: .4byte 0x00000CB4
.L080199A0: .4byte 0x05000200
.L080199A4: .4byte 0x00000CAC
.L080199A8:
    ldr r2, .L080199EC @ =0x00000CDC
    add r2, sp
    str r1, [r2]
    movs r0, #1
    ldr r2, .L080199F0 @ =0x00000C68
    add r2, sp
    str r0, [r2]
    ldr r0, [r7]
    subs r0, r1, r0
    asrs r4, r0, #4
    ldr r0, .L080199F4 @ =0x00000C64
    add r0, sp
    str r4, [r0]
    ldr r1, [r2]
    cmp r4, r1
    bhs .L080199CA
    adds r0, r2, #0
.L080199CA:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L080199FC
    lsls r4, r0, #4
    adds r0, r4, #0
    bl malloc
    ldr r5, .L080199F8 @ =0x00000CB8
    add r5, sp
    str r4, [r5]
    cmp r0, #0
    bne .L08019A04
    adds r0, r4, #0
    bl RetryMemoryAllocation
    b .L08019A04
    .align 2, 0
.L080199EC: .4byte 0x00000CDC
.L080199F0: .4byte 0x00000C68
.L080199F4: .4byte 0x00000C64
.L080199F8: .4byte 0x00000CB8
.L080199FC:
    movs r0, #0
    ldr r6, .L08019A70 @ =0x00000CB8
    add r6, sp
    str r0, [r6]
.L08019A04:
    adds r5, r0, #0
    ldr r0, .L08019A74 @ =0x00000CD8
    add r0, sp
    str r5, [r0]
    ldr r2, [r7]
    adds r3, r5, #0
    movs r1, #0x82
    add r8, r1
    ldr r5, .L08019A78 @ =0x00000CA4
    add r5, sp
    ldr r4, [r5]
    adds r4, #1
    ldr r5, .L08019A7C @ =0x00000CB4
    add r5, sp
    str r4, [r5]
    ldr r6, .L08019A80 @ =0x00000CDC
    add r6, sp
    ldr r6, [r6]
    cmp r2, r6
    beq .L08019A4A
.L08019A2C:
    cmp r3, #0
    beq .L08019A3C
    adds r0, r3, #0
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019A3C:
    adds r2, #0x10
    adds r3, #0x10
    ldr r0, .L08019A80 @ =0x00000CDC
    add r0, sp
    ldr r0, [r0]
    cmp r2, r0
    bne .L08019A2C
.L08019A4A:
    adds r5, r3, #0
    ldr r0, .L08019A84 @ =0x00000C68
    add r0, sp
    ldr r0, [r0]
    cmp r0, #1
    bne .L08019A8C
    cmp r5, #0
    beq .L08019A6A
    adds r0, r5, #0
    ldr r2, .L08019A88 @ =0x00000CAC
    add r2, sp
    ldr r1, [r2]
    ldm r1!, {r3, r4, r6}
    stm r0!, {r3, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019A6A:
    adds r5, #0x10
    b .L08019AB2
    .align 2, 0
.L08019A70: .4byte 0x00000CB8
.L08019A74: .4byte 0x00000CD8
.L08019A78: .4byte 0x00000CA4
.L08019A7C: .4byte 0x00000CB4
.L08019A80: .4byte 0x00000CDC
.L08019A84: .4byte 0x00000C68
.L08019A88: .4byte 0x00000CAC
.L08019A8C:
    adds r3, r0, #0
    adds r2, r5, #0
    cmp r3, #0
    beq .L08019AB0
.L08019A94:
    cmp r2, #0
    beq .L08019AA8
    adds r0, r2, #0
    ldr r4, .L08019B6C @ =0x00000CAC
    add r4, sp
    ldr r1, [r4]
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
.L08019AA8:
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bne .L08019A94
.L08019AB0:
    adds r5, r2, #0
.L08019AB2:
    ldr r2, [r7, #4]
    ldr r0, [r7]
    adds r1, r0, #0
    cmp r0, r2
    beq .L08019AC2
.L08019ABC:
    adds r1, #0x10
    cmp r1, r2
    bne .L08019ABC
.L08019AC2:
    cmp r0, #0
    beq .L08019ACA
    bl free
.L08019ACA:
    ldr r6, .L08019B70 @ =0x00000CB8
    add r6, sp
    ldr r6, [r6]
    ldr r1, .L08019B74 @ =0x00000CD8
    add r1, sp
    ldr r1, [r1]
    adds r0, r6, r1
    str r1, [r7]
    str r5, [r7, #4]
    str r0, [r7, #0xc]
.L08019ADE:
    movs r0, #0
    mov r3, r8
    strb r0, [r3]
    mov r4, sl
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    bne .L08019AF8
    ldrb r0, [r4, #9]
    lsrs r0, r0, #7
    cmp r0, #0
    bne .L08019AF8
    movs r0, #1
    strb r0, [r4, #0xa]
.L08019AF8:
    ldr r5, .L08019B78 @ =0x00000CB4
    add r5, sp
    ldr r5, [r5]
    ldr r6, .L08019B7C @ =0x00000CA4
    add r6, sp
    str r5, [r6]
    ldr r0, .L08019B80 @ =0x00000CA8
    add r0, sp
    ldr r6, [r0]
    cmp r5, r6
    bhs .L08019B10
    b .L080198BC
.L08019B10:
    movs r1, #0xce
    lsls r1, r1, #1
    add r1, sb
    ldr r3, .L08019B84 @ =0x00000CBC
    add r3, sp
    ldr r3, [r3]
    ldrb r2, [r3]
    movs r4, #0xcc
    lsls r4, r4, #4
    add r4, sp
    ldr r4, [r4]
    ldrb r4, [r4]
    cmp r2, r4
    bhs .L08019B56
    movs r5, #0xff
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r6, .L08019B88 @ =0x00000B81
    adds r0, r0, r6
    adds r3, r0, r1
    ldr r1, .L08019B8C @ =0x00000DB1
    add r1, sb
.L08019B3E:
    ldrb r4, [r3]
    lsrs r0, r4, #7
    cmp r0, #0
    bne .L08019B4C
    adds r0, r4, #0
    orrs r0, r5
    strb r0, [r3]
.L08019B4C:
    adds r3, #0xc
    adds r2, #1
    ldrb r0, [r1]
    cmp r2, r0
    blo .L08019B3E
.L08019B56:
    movs r3, #0xce
    lsls r3, r3, #4
    add sp, r3
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08019B6C: .4byte 0x00000CAC
.L08019B70: .4byte 0x00000CB8
.L08019B74: .4byte 0x00000CD8
.L08019B78: .4byte 0x00000CB4
.L08019B7C: .4byte 0x00000CA4
.L08019B80: .4byte 0x00000CA8
.L08019B84: .4byte 0x00000CBC
.L08019B88: .4byte 0x00000B81
.L08019B8C: .4byte 0x00000DB1

    .section .text.world_after_palette_refresh, "ax", %progbits
    .align 2, 0

    thumb_func_start func_08019BEC
func_08019BEC: @ 0x08019BEC
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
    bl func_080AB2E4
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
.L08019DF8: .4byte gUnk_0300040C
.L08019DFC: .4byte 0x000004DC
.L08019E00: .4byte 0x0000107C
.L08019E04: .4byte 0x000010B0
.L08019E08: .4byte 0x00001050
.L08019E0C: .4byte 0x00001048
.L08019E10: .4byte 0x0000104C
.L08019E14: .4byte 0x00001024
.L08019E18: .4byte 0x00001028
.L08019E1C: .4byte __vt_20GameSceneGroupSprite
.L08019E20: .4byte 0x00001038
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
    bl func_0801FAC8
    b .L08019E52
.L08019E4A:
    adds r0, r7, #0
    movs r1, #0
    bl func_0801FAC8
.L08019E52:
    movs r0, #4
    bl __builtin_new
    ldr r1, [r7, #4]
    ldr r2, [r1, #4]
    adds r1, r7, #0
    bl func_080AAFC8
    ldr r3, .L08019F28 @ =0x00001028
    adds r5, r7, r3
    adds r4, r0, #0
    ldr r0, [r5]
    cmp r4, r0
    beq .L08019E78
    cmp r0, #0
    beq .L08019E78
    movs r1, #3
    bl func_080AB2E4
.L08019E78:
    str r4, [r5]
    adds r0, r7, #0
    bl func_0801F14C
    adds r0, r7, #0
    bl RefreshWorldVase
    adds r0, r7, #0
    bl func_0801F2DC
    adds r0, r7, #0
    bl RefreshWorldHillSeasonalSprites
    adds r0, r7, #0
    bl RefreshWorldWinterAndFireplaceSprites
    adds r0, r7, #0
    bl func_0801E67C
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
.L08019F28: .4byte 0x00001028
.L08019F2C: .4byte 0x00001038
.L08019F30: .4byte 0x0000214C
.L08019F34: .4byte 0x00001054

    .section .text.game_scene_after_map_terrain, "ax", %progbits
    .align 2, 0

    thumb_func_start UpdateWorldTimeOfDayPalettes
UpdateWorldTimeOfDayPalettes: @ 0x0801A13C
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
.L0801A198: .4byte 0x00001048
.L0801A19C: .4byte 0x00001038
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
.L0801A21C: .4byte 0x00001048
.L0801A220:
    adds r1, r5, #0
    adds r1, #0x82
    str r1, [sp, #0xc0]
    movs r2, #1
    add r2, r8
    mov sb, r2
    ldr r3, [sp, #0x9c]
    cmp r3, #4
    bls .L0801A234
    b .L0801A79E
.L0801A234:
    lsls r0, r3, #2
    ldr r1, .L0801A240 @ =.L0801A244
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801A240: .4byte .L0801A244
.L0801A244: @ jump table
    .4byte .L0801A258 @ case 0
    .4byte .L0801A4BC @ case 1
    .4byte .L0801A4BC @ case 2
    .4byte .L0801A258 @ case 3
    .4byte .L0801A258 @ case 4
.L0801A258:
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
.L0801A320: .4byte 0xFFFFFC1F
.L0801A324: .4byte 0x00002529
.L0801A328: .4byte BlendRgb5PaletteBank
.L0801A32C: .4byte 0x00001BAA
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
.L0801A394: .4byte 0xFFFFFC1F
.L0801A398: .4byte 0x00001BAA
.L0801A39C: .4byte BlendRgb5PaletteBank
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
.L0801A400: .4byte 0xFFFFFC1F
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
.L0801A4B0: .4byte 0xFFFFFC1F
.L0801A4B4: .4byte BlendRgb5PaletteBank
.L0801A4B8: .4byte 0x00002529
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
.L0801A580: .4byte 0xFFFFFC1F
.L0801A584: .4byte 0x00002529
.L0801A588: .4byte BlendRgb5PaletteBank
.L0801A58C: .4byte 0x00006A32
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
.L0801A630: .4byte 0xFFFFFC1F
.L0801A634: .4byte 0x00006A32
.L0801A638: .4byte BlendRgb5PaletteBank
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
.L0801A6E8: .4byte 0xFFFFFC1F
.L0801A6EC: .4byte 0x00006A32
.L0801A6F0: .4byte BlendRgb5PaletteBank
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
.L0801A898: .4byte 0xFFFFFC1F
.L0801A89C: .4byte 0x00006A32
.L0801A8A0: .4byte BlendRgb5PaletteBank
.L0801A8A4: .4byte 0x00002529
.L0801A8A8: .4byte 0x00001038
.L0801A8AC: .4byte 0x00001048
.L0801A8B0: .4byte 0x0000104C
.L0801A8B4: .4byte 0x0000023E
.L0801A8B8: .4byte 0xFFFFFF00
.L0801A8BC: .4byte 0xFFFF0000

    .section .text.game_scene_after_time_of_day_period, "ax", %progbits
    .align 2, 0

    thumb_func_start func_0801A8E0
func_0801A8E0: @ 0x0801A8E0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r6, r0, #0
    mov sl, r1
    adds r0, #8
    lsls r7, r1, #2
    adds r4, r0, r7
    ldr r1, [r4]
    cmp r1, #0
    beq .L0801A90C
    ldr r0, [r1, #0x14]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
    movs r0, #0
    str r0, [r4]
.L0801A90C:
    movs r5, #0
    mov r0, sl
    cmp r0, #0x5d
    bls .L0801A918
    bl sub_0801B464
.L0801A918:
    ldr r0, .L0801A920 @ =0x0801A924
    adds r0, r7, r0
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801A920: .4byte .L0801A924
.L0801A924:
    @ The handlers below remain in one contiguous raw block.  Keep the jump
    @ table relocatable so each regional layout dispatches to its own offset.
    .4byte .L0801A924 + 0x178, .L0801A924 + 0x5C0, .L0801A924 + 0x5E0
    .4byte .L0801A924 + 0x600, .L0801A924 + 0x620, .L0801A924 + 0x640
    .4byte .L0801A924 + 0x660, .L0801A924 + 0x680, .L0801A924 + 0x6A0
    .4byte .L0801A924 + 0x6C0, .L0801A924 + 0x6E0, .L0801A924 + 0x700
    .4byte .L0801A924 + 0x720, .L0801A924 + 0x740, .L0801A924 + 0x760
    .4byte .L0801A924 + 0x780, .L0801A924 + 0x7A0, .L0801A924 + 0x7C0
    .4byte .L0801A924 + 0x7E0, .L0801A924 + 0x800, .L0801A924 + 0x820
    .4byte .L0801A924 + 0x840, .L0801A924 + 0x860, .L0801A924 + 0x880
    .4byte .L0801A924 + 0x8A0, .L0801A924 + 0x8C0, .L0801A924 + 0x8E0
    .4byte .L0801A924 + 0x900, .L0801A924 + 0x920, .L0801A924 + 0x940
    .4byte .L0801A924 + 0x960, .L0801A924 + 0x980, .L0801A924 + 0x9A0
    .4byte .L0801A924 + 0x9C0, .L0801A924 + 0x9E0, .L0801A924 + 0xA00
    .4byte .L0801A924 + 0x4A8, .L0801A924 + 0x4D0, .L0801A924 + 0x4F8
    .4byte .L0801A924 + 0x520, .L0801A924 + 0x548, .L0801A924 + 0x570
    .4byte .L0801A924 + 0x598, .L0801A924 + 0x18C, .L0801A924 + 0x1EC
    .4byte .L0801A924 + 0xA4C, .L0801A924 + 0x248, .L0801A924 + 0x248
    .4byte .L0801A924 + 0x248, .L0801A924 + 0x248, .L0801A924 + 0x248
    .4byte .L0801A924 + 0x248, .L0801A924 + 0x248, .L0801A924 + 0x248
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0x2D8, .L0801A924 + 0x2D8
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0x2D8, .L0801A924 + 0x2D8
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0x2D8, .L0801A924 + 0x2D8
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0x2D8, .L0801A924 + 0x2D8
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0x2D8, .L0801A924 + 0x2D8
    .4byte .L0801A924 + 0x2D8, .L0801A924 + 0xA6C, .L0801A924 + 0xA6C
    .4byte .L0801A924 + 0xA6C, .L0801A924 + 0xA6C, .L0801A924 + 0x450
    .4byte .L0801A924 + 0x3A4, .L0801A924 + 0x35A, .L0801A924 + 0x35A
    .4byte .L0801A924 + 0x35A, .L0801A924 + 0x35A, .L0801A924 + 0x35A
    .4byte .L0801A924 + 0x35A, .L0801A924 + 0x35A, .L0801A924 + 0x35A
    .4byte .L0801A924 + 0xA30, .L0801A924 + 0xA98, .L0801A924 + 0xA98
    .4byte .L0801A924 + 0xA98, .L0801A924 + 0xAC0, .L0801A924 + 0xAC0
    .4byte .L0801A924 + 0xAC0, .L0801A924 + 0xAE8, .L0801A924 + 0xB08
    .4byte .L0801A924 + 0xB28
    .byte 0x03, 0x49, 0x70, 0x18
    .byte 0x01, 0x68, 0x30, 0x1C
    bl func_0802B8EC
    bl func_0801A8E0 + 0xb82
    .byte 0x38, 0x10, 0x00, 0x00
    .byte 0x13, 0x4A, 0xB7, 0x18, 0x3A, 0x68, 0x13, 0x49, 0x50, 0x18, 0x01, 0x78, 0x10, 0x20, 0x08, 0x40
    .byte 0x00, 0x28, 0x01, 0xD0
    bl sub_0801B464
    .byte 0x0F, 0x48, 0x14, 0x18, 0x20, 0x1C
    bl func_0800F190
    .byte 0x00, 0x06, 0x00, 0x28, 0x06, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x02, 0x28
    .byte 0x01, 0xD1
    bl sub_0801B464
    .byte 0x44, 0x20
    bl __builtin_new
    .byte 0x3B, 0x68, 0x07, 0x49
    .byte 0x5A, 0x18, 0x5C, 0x31, 0x5B, 0x18, 0x31, 0x1C
    bl func_08020310
    bl func_0801A8E0 + 0xb82
    .byte 0x38, 0x10, 0x00, 0x00, 0x9C, 0x21, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00
    .byte 0x13, 0x4A, 0xB0, 0x18, 0x02, 0x68, 0x13, 0x49, 0x50, 0x18, 0x01, 0x78, 0x02, 0x20, 0x08, 0x40
    .byte 0x00, 0x28, 0x01, 0xD0
    bl sub_0801B464
    .byte 0x0F, 0x49, 0x50, 0x18, 0x01, 0x78, 0x04, 0x20
    .byte 0x08, 0x40, 0x00, 0x28, 0x01, 0xD0
    bl sub_0801B464
    .byte 0x10, 0x1C, 0x14, 0x30
    bl GetHorse__4Farm
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x40, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C
    bl func_080216BC
    bl func_0801A8E0 + 0xb82
    .byte 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x9A, 0x21, 0x00, 0x00, 0xA1, 0x21, 0x00, 0x00, 0x57, 0x46, 0x2E, 0x3F
    .byte 0x20, 0x4A, 0xB0, 0x18, 0x00, 0x68, 0x20, 0x49, 0x44, 0x18, 0x20, 0x1C
    bl func_0800F190
    .byte 0x00, 0x06, 0x00, 0x28, 0x0B, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x03, 0x28, 0x06, 0xD1
    .byte 0x20, 0x1C
    bl func_0800F344
    .byte 0xB8, 0x42, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x15, 0x4A
    .byte 0xB4, 0x18, 0x20, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x88, 0x46, 0x40, 0x44
    bl GetUnkEnt__C4Coop
    .byte 0x87, 0x42, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x20, 0x68, 0x82, 0x22, 0xD2, 0x00, 0x80, 0x18
    bl GetCapacity__C4Coop
    .byte 0x87, 0x42, 0x01, 0xD3
    bl sub_0801B464
    .byte 0x20, 0x68, 0x40, 0x44
    .byte 0x39, 0x1C
    bl GetChicken__4CoopUi
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C
    bl func_080223A8
    bl func_0801A8E0 + 0xb82
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x54, 0x46, 0x36, 0x3C
    .byte 0xA1, 0x46, 0x14, 0x48, 0x37, 0x18, 0x38, 0x68, 0xBE, 0x21, 0xC9, 0x00, 0x88, 0x46, 0x40, 0x44
    bl method_0800D058__C4Barn
    .byte 0x84, 0x42, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x38, 0x68, 0xBE, 0x22
    .byte 0xD2, 0x00, 0x80, 0x18
    bl GetCapacity__C4Barn
    .byte 0x84, 0x42, 0x01, 0xD3
    bl sub_0801B464
    .byte 0x38, 0x68, 0x40, 0x44, 0x21, 0x1C
    bl GetCow__4BarnUi
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x0B, 0xD0
    .byte 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C
    bl func_08022C18
    bl func_0801A8E0 + 0xb82
    .byte 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x38, 0x68, 0x40, 0x44, 0x49, 0x46
    bl GetSheep__4BarnUi
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x3C, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C
    bl func_080238A8
    bl func_0801A8E0 + 0xb82
    .byte 0x57, 0x46
    .byte 0x4C, 0x3F, 0x10, 0x48, 0x34, 0x18, 0x20, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x40, 0x18
    bl GetCapacity__C4Coop
    .byte 0x87, 0x42, 0x01, 0xD3
    bl sub_0801B464
    .byte 0x20, 0x68, 0x82, 0x22, 0xD2, 0x00
    .byte 0x80, 0x18, 0x39, 0x1C
    bl GetEgg__C4CoopUi
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x18, 0x20
    bl __builtin_new
    .byte 0x31, 0x1C, 0x22, 0x1C
    bl func_08037CC4
    bl func_0801A8E0 + 0xb82
    .byte 0x38, 0x10, 0x00, 0x00, 0x25, 0x48, 0x34, 0x18, 0x20, 0x68, 0x25, 0x49
    .byte 0x40, 0x18
    bl func_0800E940
    .byte 0x00, 0x06, 0x00, 0x28, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x20, 0x68, 0x21, 0x4A, 0x84, 0x18, 0x20, 0x1C
    bl func_0800F190
    .byte 0x00, 0x06, 0x00, 0x28
    .byte 0x10, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x01, 0x28, 0x0B, 0xD1, 0x20, 0x1C
    bl GetArticle__C8HeldItem
    .byte 0x01, 0xA9, 0x08, 0x70, 0x08, 0x1C
    bl GetId__C7Article
    .byte 0x35, 0x28, 0x01, 0xD1
    bl sub_0801B464
    .byte 0x12, 0x48, 0x34, 0x18, 0x20, 0x68, 0x14, 0x49, 0x40, 0x18, 0x35, 0x21
    bl GetFirstSlotWithArticle__C8RucksackUi
    .byte 0x07, 0x1C, 0x01, 0x20, 0x40, 0x42, 0x87, 0x42, 0x00, 0xD0, 0x99, 0xE3
    .byte 0x20, 0x68, 0xFA, 0x22, 0x52, 0x00, 0x80, 0x18
    bl GetShelf__9FarmHouse
    .byte 0x00, 0x28, 0x05, 0xD0
    .byte 0x35, 0x21
    bl GetFirstSlotWith__C5ShelfUi
    .byte 0xB8, 0x42, 0x00, 0xD0, 0x8B, 0xE3, 0x2C, 0x20
    bl __builtin_new
    .byte 0x22, 0x68, 0x06, 0x49, 0x52, 0x18, 0x31, 0x1C
    bl func_08038028
    .byte 0x80, 0xE3
    .byte 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x38, 0x1C, 0x00, 0x00
    .byte 0xCC, 0x1C, 0x00, 0x00, 0x12, 0x4A, 0xB7, 0x18, 0x38, 0x68, 0x12, 0x49, 0x40, 0x18
    bl func_0800E934
    .byte 0x00, 0x06, 0x00, 0x28, 0x00, 0xD1, 0x6C, 0xE3, 0x38, 0x68, 0x0E, 0x4A, 0x84, 0x18
    .byte 0x20, 0x1C
    bl func_0800F190
    .byte 0x00, 0x06, 0x00, 0x28, 0x05, 0xD1, 0x20, 0x1C
    bl GetKind__C8HeldItem
    .byte 0x04, 0x28, 0x00, 0xD1, 0x5D, 0xE3, 0x1C, 0x20
    bl __builtin_new
    .byte 0x3A, 0x68
    .byte 0xE5, 0x21, 0x49, 0x01, 0x52, 0x18, 0x31, 0x1C
    bl func_08037E18
    .byte 0x51, 0xE3, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00, 0x2C, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91
    .byte 0x31, 0x1C, 0x00, 0x22
    bl func_08033928
    .byte 0x3B, 0xE3, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68
    .byte 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x01, 0x22
    bl func_08033928
    .byte 0x27, 0xE3, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91
    .byte 0x31, 0x1C, 0x02, 0x22
    bl func_08033928
    .byte 0x13, 0xE3, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68
    .byte 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x03, 0x22
    bl func_08033928
    .byte 0xFF, 0xE2, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91
    .byte 0x31, 0x1C, 0x04, 0x22
    bl func_08033928
    .byte 0xEB, 0xE2, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68
    .byte 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91, 0x31, 0x1C, 0x05, 0x22
    bl func_08033928
    .byte 0xD7, 0xE2, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x44, 0x20
    bl __builtin_new
    .byte 0x06, 0x4A, 0xB1, 0x18, 0x09, 0x68, 0x05, 0x4A, 0x8B, 0x18, 0x14, 0x31, 0x00, 0x91
    .byte 0x31, 0x1C, 0x06, 0x22
    bl func_08033928
    .byte 0xC3, 0xE2, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035AFC
    .byte 0xB2, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x44, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035B64
    .byte 0xA2, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x58, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035BC8
    .byte 0x92, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x6C, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035D04
    .byte 0x82, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x84, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035D70
    .byte 0x72, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x98, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035DD8
    .byte 0x62, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0xAC, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035E40
    .byte 0x52, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0xC4, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035EAC
    .byte 0x42, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0xD8, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035F10
    .byte 0x32, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0xEC, 0x1D, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0xF0, 0x21, 0x49, 0x01, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035F74
    .byte 0x21, 0xE2, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08035FE0
    .byte 0x12, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x14, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036048
    .byte 0x02, 0xE2, 0x38, 0x10, 0x00, 0x00
    .byte 0x28, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x05, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0xF2, 0x21, 0x49, 0x01, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036184
    .byte 0xF1, 0xE1, 0x00, 0x00
    .byte 0x38, 0x10, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080361EC
    .byte 0xE2, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x54, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036258
    .byte 0xD2, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x68, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080362C0
    .byte 0xC2, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x7C, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036328
    .byte 0xB2, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x90, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036390
    .byte 0xA2, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0xA4, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080363F8
    .byte 0x92, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0xB8, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036530
    .byte 0x82, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0xD0, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036590
    .byte 0x72, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0xE4, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080366CC
    .byte 0x62, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0xFC, 0x1E, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036730
    .byte 0x52, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x10, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080367F8
    .byte 0x42, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x24, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_080368C4
    .byte 0x32, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x38, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036A10
    .byte 0x22, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x50, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036A78
    .byte 0x12, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x64, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036B4C
    .byte 0x02, 0xE1, 0x38, 0x10, 0x00, 0x00
    .byte 0x7C, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036C48
    .byte 0xF2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0x90, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036CAC
    .byte 0xE2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xA4, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036D0C
    .byte 0xD2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xB8, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036D68
    .byte 0xC2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xD0, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036DC4
    .byte 0xB2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xE4, 0x1F, 0x00, 0x00, 0x48, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0B, 0x68
    .byte 0x03, 0x49, 0x5A, 0x18, 0x31, 0x1C
    bl func_08036860
    .byte 0xA2, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xFC, 0x1F, 0x00, 0x00, 0x09, 0x4A, 0xB7, 0x18, 0x38, 0x68, 0x09, 0x49, 0x40, 0x18
    bl GetChild__13NpcCollection
    .byte 0x04, 0x1C, 0x00, 0x2C, 0x00, 0xD1, 0x94, 0xE0, 0x4C, 0x20
    bl __builtin_new
    .byte 0x3B, 0x68, 0x31, 0x1C, 0x22, 0x1C
    bl func_08036E2C
    .byte 0x8A, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x04, 0x4A, 0xB0, 0x18, 0x01, 0x68, 0x04, 0x48, 0x09, 0x18, 0x30, 0x1C
    bl func_0803A798
    .byte 0x7D, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x94, 0x34, 0x00, 0x00
    .byte 0x54, 0x20
    bl __builtin_new
    .byte 0x04, 0x4A, 0xB1, 0x18, 0x0A, 0x68, 0x03, 0x49, 0x52, 0x18
    .byte 0x31, 0x1C
    bl func_080398A4
    .byte 0x6C, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xDC, 0x34, 0x00, 0x00
    .byte 0x55, 0x46, 0x46, 0x3D, 0x07, 0x48, 0x04, 0x68, 0x07, 0x4A, 0xA4, 0x18, 0x34, 0x20
    bl __builtin_new
    .byte 0x69, 0x00, 0x49, 0x19, 0x89, 0x00, 0x64, 0x18, 0x31, 0x1C, 0x22, 0x1C
    bl func_08032934
    .byte 0x56, 0xE0, 0x0C, 0x04, 0x00, 0x03, 0x24, 0x05, 0x00, 0x00, 0x54, 0x46, 0x55, 0x3C
    .byte 0x06, 0x49, 0x70, 0x18, 0x00, 0x68, 0x06, 0x4A, 0x80, 0x18, 0x21, 0x1C
    bl GetSouthTownNpcLocation1__13NpcCollectionUi
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x22, 0x1C
    bl func_08037A5C
    .byte 0x42, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0xD4, 0x1C, 0x00, 0x00, 0x54, 0x46, 0x58, 0x3C, 0x06, 0x49, 0x70, 0x18, 0x00, 0x68, 0x06, 0x4A
    .byte 0x80, 0x18, 0x21, 0x1C
    bl GetSouthTownNpcLocation2__13NpcCollectionUi
    .byte 0x01, 0x1C, 0x30, 0x1C, 0x22, 0x1C
    bl func_08037AD0
    .byte 0x2E, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x05, 0x49, 0x70, 0x18
    .byte 0x00, 0x68, 0x05, 0x4A, 0x80, 0x18
    bl GetYodelRanchHouseNpcLocation__13NpcCollection
    .byte 0x01, 0x1C, 0x30, 0x1C
    bl func_08037B48
    .byte 0x1E, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x05, 0x49, 0x70, 0x18
    .byte 0x00, 0x68, 0x05, 0x4A, 0x80, 0x18
    bl GetInnSecondFloorNpcLocation__13NpcCollection
    .byte 0x01, 0x1C, 0x30, 0x1C
    bl func_08037B80
    .byte 0x0E, 0xE0, 0x38, 0x10, 0x00, 0x00, 0xD4, 0x1C, 0x00, 0x00, 0x1C, 0x20
    bl __builtin_new
    .byte 0x0F, 0x4A, 0xB1, 0x18, 0x0A, 0x68, 0x0E, 0x49, 0x52, 0x18, 0x31, 0x1C
    bl func_08038740
    .byte 0x05, 0x1C

    thumb_func_start sub_0801B464
sub_0801B464: @ 0x0801B464
    cmp r5, #0
    beq .L0801B47E
    adds r0, r6, #0
    adds r0, #8
    mov r2, sl
    lsls r1, r2, #2
    adds r0, r0, r1
    str r5, [r0]
    ldr r0, [r5, #0x14]
    ldr r1, [r0, #0x10]
    adds r0, r5, #0
    bl _call_via_r1
.L0801B47E:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801B490:
    .4byte 0x00001038
    .4byte 0x0000214C
.L0801B498:
    .global func_0801B498
    .thumb_func
func_0801B498:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    adds r7, r1, #0
    mov sb, r2
    movs r1, #0x64
    str r1, [sp, #8]
    movs r2, #1
    str r2, [sp, #0xc]
    adds r3, r0, #0
    adds r3, #8
    str r3, [sp, #0x10]
    mov r8, sp
    adds r0, #0xc
    mov sl, r0
.L0801B498_loop:
    mov r4, sl
    ldr r5, [r4]
    cmp r5, #0
    beq .L0801B498_next
    ldrh r0, [r7]
    lsls r0, r0, #0x16
    lsrs r0, r0, #0x16
    ldrh r1, [r5, #4]
    cmp r0, r1
    bne .L0801B498_next
    ldr r1, [r5, #0x14]
    mov r0, sp
    ldr r2, [r1, #0xc]
    adds r1, r5, #0
    bl _call_via_r2
    mov r3, sb
    movs r4, #0
    ldrsh r2, [r3, r4]
    mov r1, r8
    movs r3, #4
    ldrsh r0, [r1, r3]
    subs r2, r2, r0
    movs r4, #0
    ldrsh r0, [r1, r4]
    mov r3, sb
    movs r4, #4
    ldrsh r1, [r3, r4]
    subs r0, r0, r1
    ands r2, r0
    movs r1, #2
    ldrsh r0, [r3, r1]
    mov r3, r8
    movs r4, #6
    ldrsh r1, [r3, r4]
    subs r0, r0, r1
    ands r2, r0
    movs r1, #2
    ldrsh r0, [r3, r1]
    mov r3, sb
    movs r4, #6
    ldrsh r1, [r3, r4]
    subs r0, r0, r1
    ands r2, r0
    cmp r2, #0
    bge .L0801B498_next
    ldr r0, [sp, #8]
    cmp r0, #0x64
    beq .L0801B498_set_best
    lsls r0, r0, #2
    ldr r1, [sp, #0x10]
    adds r0, r1, r0
    ldr r4, [r0]
    movs r3, #0xa
    ldrsh r2, [r4, r3]
    ldrb r1, [r7, #1]
    lsrs r1, r1, #2
    ldrh r0, [r7, #2]
    ldr r3, .L0801B498_mask
    mov ip, r3
    ands r0, r3
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    subs r3, r2, r6
    cmp r3, #0
    bge .L0801B498_x_positive
    negs r3, r3
.L0801B498_x_positive:
    movs r0, #0xe
    ldrsh r2, [r4, r0]
    ldrb r1, [r7, #3]
    lsrs r1, r1, #2
    ldrh r0, [r7, #4]
    mov r4, ip
    ands r0, r4
    lsls r0, r0, #6
    orrs r0, r1
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    subs r1, r2, r4
    cmp r1, #0
    bge .L0801B498_y_positive
    negs r1, r1
.L0801B498_y_positive:
    adds r0, r3, #0
    muls r0, r3
    adds r2, r1, #0
    muls r2, r1
    adds r1, r2, #0
    adds r2, r0, r1
    movs r3, #0xa
    ldrsh r0, [r5, r3]
    subs r3, r0, r6
    cmp r3, #0
    bge .L0801B498_candidate_x_positive
    negs r3, r3
.L0801B498_candidate_x_positive:
    movs r1, #0xe
    ldrsh r0, [r5, r1]
    subs r1, r0, r4
    cmp r1, #0
    bge .L0801B498_candidate_y_positive
    negs r1, r1
.L0801B498_candidate_y_positive:
    adds r0, r3, #0
    muls r0, r3
    adds r3, r1, #0
    muls r3, r1
    adds r1, r3, #0
    adds r0, r0, r1
    cmp r2, r0
    blt .L0801B498_next
.L0801B498_set_best:
    ldr r4, [sp, #0xc]
    str r4, [sp, #8]
.L0801B498_next:
    movs r0, #4
    add sl, r0
    ldr r1, [sp, #0xc]
    adds r1, #1
    str r1, [sp, #0xc]
    cmp r1, #0x63
    bls .L0801B498_loop
    ldr r0, [sp, #8]
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801B498_mask:
    .4byte 0x000003FF
    .section .text.game_scene_palette_resource_selector_after, "ax", %progbits
    .align 2, 0

.L0801B9E8:
    .global SetWorldSpritePaletteColors
    .thumb_func
SetWorldSpritePaletteColors:
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46
    .byte 0xE0, 0xB4, 0xB0, 0xB0, 0x07, 0x1C, 0x88, 0x46, 0x24, 0x92, 0x1B, 0x06, 0x1B, 0x0E, 0x9A, 0x46
    .byte 0x78, 0x68, 0x40, 0x68
    bl GetMapData
    .byte 0x24, 0x30, 0x00, 0x78, 0x00, 0x28, 0x14, 0xD0
    .byte 0xDE, 0x20, 0x40, 0x00, 0x3C, 0x18, 0x24, 0x99, 0x48, 0x01, 0x40, 0x18, 0x80, 0x00, 0x24, 0x18
    .byte 0x20, 0x1C, 0x41, 0x46, 0x20, 0x22
    bl memcpy
    .byte 0x21, 0x1C, 0x82, 0x31, 0x01, 0x20
    .byte 0x08, 0x70, 0x83, 0x34, 0x52, 0x46, 0x22, 0x70, 0x3D, 0xE3, 0x78, 0x68, 0x01, 0x68, 0x05, 0x4B
    .byte 0xF8, 0x18, 0x00, 0x68, 0x08, 0x30, 0x2E, 0x29, 0x0A, 0xD0, 0x2E, 0x29, 0x04, 0xDD, 0x2F, 0x29
    .byte 0x08, 0xD0, 0x09, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x2C, 0x29, 0x05, 0xDB, 0x00, 0x23, 0x04, 0xE0
    .byte 0x01, 0x23, 0x02, 0xE0, 0x02, 0x23, 0x00, 0xE0, 0x03, 0x68, 0x22, 0x4C, 0x38, 0x19, 0x01, 0x78
    .byte 0x1E, 0x22, 0xCE, 0x25, 0x6D, 0x00, 0xED, 0x19, 0xA9, 0x46, 0x1F, 0x4E, 0xB8, 0x19, 0x06, 0x68
    .byte 0x25, 0x91, 0x52, 0x1A, 0x26, 0x92, 0xDE, 0x20, 0x40, 0x00, 0x3C, 0x18, 0x24, 0x99, 0x4D, 0x01
    .byte 0x68, 0x18, 0x80, 0x00, 0x24, 0x18, 0x20, 0x1C, 0x41, 0x46, 0x20, 0x22, 0x2F, 0x93
    bl memcpy
    .byte 0x22, 0x1C, 0x82, 0x32, 0x01, 0x20, 0x84, 0x46, 0x61, 0x46, 0x11, 0x70, 0x20, 0x1C
    .byte 0x83, 0x30, 0x51, 0x46, 0x01, 0x70, 0xA0, 0x46, 0x28, 0x95, 0x2F, 0x9B, 0x54, 0x46, 0x00, 0x2C
    .byte 0x1C, 0xD1, 0x41, 0x46, 0x20, 0x31, 0x40, 0x46, 0x68, 0xC8, 0x68, 0xC1, 0x70, 0xC8, 0x70, 0xC1
    .byte 0x18, 0xC8, 0x18, 0xC1, 0x41, 0x46, 0x40, 0x31, 0x40, 0x46, 0x68, 0xC8, 0x68, 0xC1, 0x70, 0xC8
    .byte 0x70, 0xC1, 0x18, 0xC8, 0x18, 0xC1, 0x65, 0x46, 0x15, 0x70, 0xDE, 0x26, 0x76, 0x00, 0xF6, 0x19
    .byte 0xB2, 0x46, 0xB2, 0xE2, 0x4C, 0x10, 0x00, 0x00, 0x48, 0x10, 0x00, 0x00, 0x2E, 0x92, 0xDE, 0x20
    .byte 0x40, 0x00, 0xC0, 0x19, 0x82, 0x46, 0x04, 0x2B, 0x00, 0xD9, 0xA3, 0xE2, 0x98, 0x00, 0x02, 0x49
    .byte 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00
.L0801B9E8_case_table_1_address:
    .4byte .L0801B9E8_case_table_1
.L0801B9E8_case_table_1:
    .4byte .L0801B9E8 + 0x148
    .4byte .L0801B9E8 + 0x3A0
    .4byte .L0801B9E8 + 0x3A0
    .4byte .L0801B9E8 + 0x148
    .4byte .L0801B9E8 + 0x148
    .byte 0x01, 0x2E, 0x00, 0xD1, 0x9C, 0xE0, 0x01, 0x2E, 0x08, 0xDC, 0x00, 0x2E, 0x62, 0xD0, 0x41, 0x46
    .byte 0x82, 0x31, 0x2E, 0x91, 0x20, 0x22, 0x4A, 0x44, 0x92, 0x46, 0x83, 0xE2, 0x02, 0x2E, 0x00, 0xD1
    .byte 0xBE, 0xE0, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x24, 0x4C, 0x44, 0xA2, 0x46, 0x03, 0x2E
    .byte 0x00, 0xD0, 0x77, 0xE2, 0x08, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x1E, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x1C, 0x4B, 0x09, 0x93, 0x69, 0x46, 0x16, 0x1C, 0x05, 0x1C
    .byte 0x0A, 0xAF, 0x0B, 0xAC, 0xA1, 0x46, 0x14, 0x1C, 0xA5, 0x45, 0x04, 0xD0, 0x1C, 0x1C, 0x0C, 0x80
    .byte 0x02, 0x31, 0xB1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x13, 0x4C
    bl _call_via_r4
    .byte 0x09, 0x23, 0x0A, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80
    .byte 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x0A, 0x48, 0x0B, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45
    .byte 0x00, 0xD1, 0xD5, 0xE1, 0x4D, 0x46, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1
    .byte 0xCE, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0xAA, 0x1B, 0x00, 0x00, 0x0C, 0xAA, 0x09, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x12, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x10, 0x4E, 0x0D, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C
    .byte 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0
    .byte 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x07, 0x4C
    bl _call_via_r4
    .byte 0x28, 0x1C, 0x20, 0x30, 0x41, 0x46, 0x20, 0x22
    bl memcpy
    .byte 0xF8, 0xE1, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0xAA, 0x1B, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x44, 0x46, 0x20, 0x34, 0x20, 0x1C, 0x41, 0x46, 0x20, 0x22
    bl memcpy
    .byte 0x0E, 0xAA
    .byte 0x03, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xD8, 0x23
    .byte 0x9B, 0x00, 0x11, 0x88, 0x0D, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x20, 0x34, 0x08, 0x20
    .byte 0x46, 0x01, 0x20, 0x21, 0x0E, 0x43, 0x80, 0x02, 0x06, 0x43, 0x0F, 0x96, 0x68, 0x46, 0x08, 0xA9
    .byte 0x45, 0x46, 0x82, 0x35, 0x2E, 0x95, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0x8D, 0x45, 0x03, 0xD0
    .byte 0x06, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x62, 0xE1, 0x1F, 0xFC, 0xFF, 0xFF
    .byte 0x10, 0xAA, 0x03, 0x23, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xD8, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x25, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x47, 0x46
    .byte 0x20, 0x37, 0x13, 0x1C, 0x08, 0x20, 0x42, 0x01, 0x20, 0x21, 0x0A, 0x43, 0x80, 0x02, 0x02, 0x43
    .byte 0x11, 0x92, 0x6C, 0x46, 0x08, 0xAE, 0x3D, 0x1C, 0x68, 0x46, 0x48, 0x30, 0x29, 0x90, 0x69, 0x46
    .byte 0x4C, 0x31, 0x2A, 0x91, 0x40, 0x46, 0x82, 0x30, 0x2E, 0x90, 0x20, 0x21, 0x49, 0x44, 0x8A, 0x46
    .byte 0xB5, 0x45, 0x04, 0xD0, 0x10, 0x1C, 0x20, 0x80, 0x02, 0x34, 0xB4, 0x42, 0xFB, 0xD1, 0x1B, 0x68
    .byte 0x38, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x12, 0x4C
    bl _call_via_r4
    .byte 0x0A, 0x23, 0x12, 0xAA
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x29, 0x9B
    .byte 0x08, 0x48, 0x13, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x00, 0xD1, 0x10, 0xE1, 0x2A, 0x9D
    .byte 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x09, 0xE1, 0x1F, 0xFC, 0xFF, 0xFF
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00, 0x01, 0x2E, 0x00, 0xD1, 0xB6, 0xE0, 0x01, 0x2E
    .byte 0x08, 0xDC, 0x00, 0x2E, 0x60, 0xD0, 0x46, 0x46, 0x82, 0x36, 0x2E, 0x96, 0x20, 0x20, 0x48, 0x44
    .byte 0x82, 0x46, 0x57, 0xE1, 0x02, 0x2E, 0x00, 0xD1, 0x00, 0xE1, 0x41, 0x46, 0x82, 0x31, 0x2E, 0x91
    .byte 0x20, 0x22, 0x4A, 0x44, 0x92, 0x46, 0x03, 0x2E, 0x00, 0xD0, 0x4B, 0xE1, 0x14, 0xAA, 0x0A, 0x23
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x1D, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x1B, 0x4E
    .byte 0x15, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C, 0x16, 0xAF, 0x17, 0xAB, 0x99, 0x46, 0xA5, 0x45
    .byte 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46
    .byte 0x13, 0x4C
    bl _call_via_r4
    .byte 0x0A, 0x23, 0x16, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x0A, 0x48, 0x17, 0x90, 0x68, 0x46
    .byte 0x08, 0xA9, 0x8D, 0x45, 0x00, 0xD1, 0xAB, 0xE0, 0x4D, 0x46, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30
    .byte 0x88, 0x42, 0xFB, 0xD1, 0xA4, 0xE0, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x29, 0x25, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x32, 0x6A, 0x00, 0x00, 0x18, 0xAA, 0x0A, 0x23, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x20, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x1E, 0x4E, 0x19, 0x96, 0x69, 0x46
    .byte 0x08, 0xAC, 0x05, 0x1C, 0x1A, 0xAF, 0x6B, 0x46, 0x6C, 0x33, 0x2B, 0x93, 0x43, 0x46, 0x82, 0x33
    .byte 0x2E, 0x93, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0, 0x0E, 0x80, 0x02, 0x31
    .byte 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x13, 0x4C
    bl _call_via_r4
    .byte 0x0A, 0x23, 0x1A, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70
    .byte 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C
    .byte 0x20, 0x34, 0x3B, 0x1C, 0x07, 0x48, 0x1B, 0x90, 0x68, 0x46, 0x08, 0xA9, 0x8D, 0x45, 0x57, 0xD0
    .byte 0x2B, 0x9D, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x50, 0xE0, 0x00, 0x00
    .byte 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x1C, 0xAA, 0x0A, 0x23
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x23, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x40, 0x46, 0x20, 0x30, 0x21, 0x4E
    .byte 0x1D, 0x96, 0x69, 0x46, 0x08, 0xAC, 0x05, 0x1C, 0x1E, 0xAF, 0x6B, 0x46, 0x7C, 0x33, 0x2C, 0x93
    .byte 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0xA5, 0x45, 0x03, 0xD0
    .byte 0x0E, 0x80, 0x02, 0x31, 0xA1, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x69, 0x46, 0x42, 0x46, 0x16, 0x4C
    bl _call_via_r4
    .byte 0x0A, 0x23, 0x1E, 0xAA, 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40
    .byte 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x0D, 0x48, 0x08, 0x40, 0x18, 0x43
    .byte 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x0A, 0x48, 0x1F, 0x90, 0x68, 0x46, 0x08, 0xA9
    .byte 0x8D, 0x45, 0x05, 0xD0, 0x2C, 0x9D, 0x2A, 0x68, 0x02, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1
    .byte 0x1B, 0x68, 0x20, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x03, 0x4C
    bl _call_via_r4
    .byte 0x59, 0xE0
    .byte 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x20, 0xAA, 0x0A, 0x23
    .byte 0x11, 0x78, 0x20, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00
    .byte 0x11, 0x88, 0x41, 0x48, 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x46, 0x46, 0x20, 0x36, 0x3F, 0x4C
    .byte 0x21, 0xA8, 0x04, 0x60, 0x68, 0x46, 0x08, 0xA9, 0x35, 0x1C, 0x22, 0xAF, 0x6B, 0x46, 0x8C, 0x33
    .byte 0x2D, 0x93, 0x43, 0x46, 0x82, 0x33, 0x2E, 0x93, 0x20, 0x23, 0x4B, 0x44, 0x9A, 0x46, 0x8D, 0x45
    .byte 0x03, 0xD0, 0x04, 0x80, 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x13, 0x68, 0x30, 0x1C, 0x69, 0x46
    .byte 0x42, 0x46, 0x33, 0x4C
    bl _call_via_r4
    .byte 0x0A, 0x23, 0x22, 0xAA, 0x11, 0x78, 0x20, 0x20
    .byte 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x10, 0x70, 0xA0, 0x23, 0x9B, 0x00, 0x11, 0x88, 0x2A, 0x48
    .byte 0x08, 0x40, 0x18, 0x43, 0x10, 0x80, 0x2C, 0x1C, 0x20, 0x34, 0x3B, 0x1C, 0x29, 0x48, 0x2D, 0x9D
    .byte 0x28, 0x60, 0x68, 0x46, 0x08, 0xA9, 0x23, 0xAA, 0x8D, 0x45, 0x04, 0xD0, 0x12, 0x68, 0x02, 0x80
    .byte 0x02, 0x30, 0x88, 0x42, 0xFB, 0xD1, 0x1B, 0x68, 0x20, 0x1C, 0x69, 0x46, 0x42, 0x46, 0x20, 0x4C
    bl _call_via_r4
    .byte 0x01, 0x20, 0x2E, 0x9E, 0x30, 0x70, 0x28, 0x99, 0x24, 0x9A, 0x88, 0x18
    .byte 0x80, 0x00, 0x53, 0x46, 0x1D, 0x18, 0x28, 0x1C, 0x60, 0x30, 0x29, 0x1C, 0x20, 0x31, 0x2A, 0x1C
    .byte 0x40, 0x32, 0x1F, 0x23, 0x25, 0x9C, 0x1C, 0x40, 0x20, 0x23, 0x5B, 0x42, 0x27, 0x9E, 0x33, 0x40
    .byte 0x23, 0x43, 0x1B, 0x06, 0x1B, 0x0E, 0x14, 0x4C, 0x26, 0x40, 0x1E, 0x43, 0x1F, 0x23, 0x26, 0x9C
    .byte 0x1C, 0x40, 0x64, 0x01, 0x0C, 0x4B, 0x33, 0x40, 0x23, 0x43, 0x1B, 0x04, 0x1B, 0x0C, 0x0F, 0x4C
    .byte 0x26, 0x40, 0x1E, 0x43, 0x27, 0x96, 0x33, 0x1C, 0x09, 0x4C
    bl _call_via_r4
    .byte 0x29, 0x1C
    .byte 0x82, 0x31, 0x01, 0x20, 0x08, 0x70, 0x30, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46
    .byte 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x1F, 0xFC, 0xFF, 0xFF, 0x32, 0x6A, 0x00, 0x00
    .word BlendRgb5PaletteBank
    .byte 0x29, 0x25, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF
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
    .byte 0x70, 0x47, 0x00, 0x00
    .global func_0801C3E0
    .thumb_func
func_0801C3E0:
    .byte 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x83, 0xB0, 0x07, 0x1C, 0x00, 0x22, 0x91, 0x46
    .byte 0x27, 0x48, 0xC0, 0x19, 0x80, 0x46, 0x27, 0x48, 0x3E, 0x18, 0x31, 0x78, 0x88, 0x07, 0x80, 0x0F
    .byte 0x02, 0x28, 0x2E, 0xD1, 0x04, 0x22, 0x52, 0x42, 0x10, 0x1C, 0x01, 0x40, 0x01, 0x20, 0x01, 0x43
    .byte 0x09, 0x3A, 0x10, 0x1C, 0x01, 0x40, 0x31, 0x70, 0x40, 0x20
    bl __builtin_new
    .byte 0x04, 0x1C
    .byte 0x38, 0x68, 0x81, 0x6E, 0x38, 0x1C
    bl _call_via_r1
    .byte 0x01, 0x1C, 0x03, 0x20, 0x00, 0x90
    .byte 0x1A, 0x20, 0x01, 0x90, 0x02, 0xAA, 0x00, 0x20, 0x10, 0x70, 0x20, 0x1C, 0x16, 0x4A, 0x3B, 0x1C
    bl __22GameSceneIndexedSpriteP23IndexedResourceProviderUiP10GameObjectUiib
    .byte 0x45, 0x46, 0x04, 0x1C, 0x29, 0x68, 0x8C, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
    bl _call_via_r2
    .byte 0x2C, 0x60
    .byte 0x01, 0x22, 0x0C, 0x20, 0x80, 0x44, 0x0C, 0x36, 0x01, 0x20, 0x81, 0x44, 0x48, 0x46, 0x03, 0x28
    .byte 0xC3, 0xD9, 0x00, 0x2A, 0x04, 0xD0, 0xB8, 0x68, 0x02, 0x21, 0x00, 0x22
    bl StartActorSpriteEffect
    .byte 0x03, 0xB0, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
    .byte 0x88, 0x10, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0x6F, 0x08, 0x00, 0x00
    .global func_0801C49C
    .thumb_func
func_0801C49C:
    .byte 0xF0, 0xB5, 0x57, 0x46
    .byte 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x83, 0xB0, 0x04, 0x1C, 0x89, 0x46, 0x90, 0x46, 0x00, 0x20
    .byte 0x10, 0x60, 0x01, 0xAE, 0x20, 0x1C, 0x32, 0x1C
    bl func_0801C198
    .byte 0x00, 0x06, 0x00, 0x28
    .byte 0x3C, 0xD0, 0x1C, 0x48, 0x25, 0x18, 0x28, 0x68, 0x1B, 0x49, 0x40, 0x18, 0x07, 0x1C, 0xB1, 0x88
    .byte 0xF2, 0x88
    bl GetCellType__C14MineFloorStateUiUi
    .byte 0x00, 0x22, 0x92, 0x46, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20
    .byte 0x82, 0x46, 0xB1, 0x88, 0xF2, 0x88, 0x2B, 0x68, 0x38, 0x1C
    bl DigSoil__14MineFloorStateUiUiR18GameStateSaveImage
    .byte 0x41, 0x46
    .byte 0x08, 0x60, 0x20, 0x68, 0x41, 0x69, 0x20, 0x1C
    bl _call_via_r1
    .byte 0x4A, 0x46, 0x11, 0x88
    .byte 0x89, 0x05, 0x89, 0x0D, 0x88, 0x42, 0x13, 0xD1, 0x65, 0x68, 0xB1, 0x88, 0xF2, 0x88, 0x38, 0x1C
    bl GetCellType__C14MineFloorStateUiUi
    .byte 0x04, 0x1C, 0xB1, 0x88, 0xF2, 0x88, 0x38, 0x1C
    bl GetCellTilemap__C14MineFloorStateUiUi
    .byte 0x01, 0xA9, 0x09, 0x88, 0x72, 0x88, 0x00, 0x90, 0x28, 0x1C, 0x23, 0x1C
    bl func_080AA540
    .byte 0x50, 0x46, 0x04, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00, 0x00, 0x20, 0x03, 0xB0
    .byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .global CreateWorldEventIcon
    .thumb_func
CreateWorldEventIcon:
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x83, 0xB0, 0x81, 0x46, 0x8A, 0x46
    .byte 0x15, 0x1C, 0x1E, 0x1C, 0x0B, 0x9F, 0x0C, 0x98, 0x02, 0x04, 0x12, 0x0C, 0x02, 0x92, 0x44, 0x48
    .byte 0x04, 0x68, 0x44, 0x48, 0x24, 0x18, 0x48, 0x00, 0x50, 0x44, 0x80, 0x00, 0x24, 0x18, 0x21, 0x78
    .byte 0x04, 0x20, 0x40, 0x42, 0x08, 0x40, 0x01, 0x21, 0x08, 0x43, 0x20, 0x70, 0x49, 0x46, 0x08, 0x68
    .byte 0x41, 0x69, 0x48, 0x46
    bl _call_via_r1
    .byte 0x3B, 0x49, 0x88, 0x46, 0x41, 0x46, 0x08, 0x40
    .byte 0x63, 0x88, 0x3A, 0x4A, 0x11, 0x1C, 0x19, 0x40, 0x01, 0x43, 0x61, 0x80, 0x2D, 0x04, 0x29, 0x0C
    .byte 0x3F, 0x20, 0x01, 0x40, 0x89, 0x00, 0xE3, 0x78, 0x03, 0x20, 0x84, 0x46, 0x03, 0x20, 0x18, 0x40
    .byte 0x08, 0x43, 0xE0, 0x70, 0xAD, 0x0D, 0x41, 0x46, 0x0D, 0x40, 0xA0, 0x88, 0x02, 0x40, 0x2A, 0x43
    .byte 0xA2, 0x80, 0x36, 0x04, 0xB6, 0x09, 0x60, 0x68, 0x2D, 0x49, 0x08, 0x40, 0x30, 0x43, 0x60, 0x60
    .byte 0x60, 0x46, 0x07, 0x40, 0xBA, 0x00, 0x21, 0x78, 0x0D, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43
    .byte 0x20, 0x70, 0x69, 0x46, 0x09, 0x89, 0x21, 0x81, 0x26, 0x48, 0x48, 0x44, 0x80, 0x46, 0x51, 0x46
    .byte 0x89, 0x00, 0x8A, 0x46, 0xD0, 0x44, 0x4C, 0x20
    bl __builtin_new
    .byte 0x05, 0x1C, 0x49, 0x46
    .byte 0x08, 0x68, 0x41, 0x6E, 0x48, 0x46
    bl _call_via_r1
    .byte 0x04, 0x1C, 0x28, 0x1C, 0x49, 0x46, 0x02, 0x22, 0x1B, 0x23
    bl __19GameSceneSpriteBaseP10GameObjectUii
    .byte 0x1B, 0x48, 0x68, 0x62, 0x28, 0x20, 0x40, 0x19
    .byte 0x81, 0x46, 0x26, 0x68, 0x68, 0x46, 0xF3, 0x68, 0x21, 0x1C, 0x02, 0x9A
    bl _call_via_r3
    .byte 0x00, 0x98, 0x02, 0x88, 0x48, 0x46, 0x33, 0x69, 0x21, 0x1C
    bl _call_via_r3
    .byte 0x29, 0x1C
    .byte 0x48, 0x31, 0x01, 0x20, 0x08, 0x70, 0x44, 0x46, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29
    .byte 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68, 0x08, 0x1C, 0x03, 0x21
    bl _call_via_r2
    .byte 0x25, 0x60
    .byte 0x03, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .byte 0x0C, 0x04, 0x00, 0x03, 0xDC, 0x04, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF
    .byte 0xFF, 0x03, 0x00, 0xFC, 0xB0, 0x10, 0x00, 0x00
    .4byte __vt_20GameSceneGroupSprite
    .global RemoveWorldEventIcon
    .thumb_func
RemoveWorldEventIcon:
    .byte 0x30, 0xB5, 0x10, 0x4A
    .byte 0x13, 0x68, 0x10, 0x4A, 0x9B, 0x18, 0x4A, 0x00, 0x52, 0x18, 0x92, 0x00, 0x9B, 0x18, 0x1C, 0x78
    .byte 0x04, 0x22, 0x52, 0x42, 0x22, 0x40, 0x1A, 0x70, 0x0B, 0x4A, 0x80, 0x18, 0x89, 0x00, 0x44, 0x18
    .byte 0x00, 0x25, 0x21, 0x68, 0x8D, 0x42, 0x07, 0xD0, 0x00, 0x29, 0x05, 0xD0, 0x48, 0x6A, 0x82, 0x68
    .byte 0x08, 0x1C, 0x03, 0x21
    bl _call_via_r2
    .byte 0x25, 0x60, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
    .byte 0x0C, 0x04, 0x00, 0x03, 0xDC, 0x04, 0x00, 0x00, 0xB0, 0x10, 0x00, 0x00

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
    .byte 0xF0, 0xB5, 0x89, 0xB0
    .byte 0x05, 0x1C, 0x0E, 0x1C, 0x17, 0x1C, 0x01, 0xA9, 0x00, 0x20, 0x01, 0x90, 0x88, 0x80, 0xC8, 0x80
    .byte 0x08, 0x81, 0x48, 0x81, 0x28, 0x1C, 0x31, 0x1C, 0x01, 0xAA
    bl TryGetFarmPlotAtLocation
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x0D, 0xD0, 0x01, 0xA8, 0x01, 0x89, 0x42, 0x89, 0x04, 0x48, 0x38, 0x18, 0x03, 0x78
    .byte 0x28, 0x1C
    bl func_0801C874
    .byte 0x00, 0x06, 0x00, 0x0E, 0x36, 0xE0
    .4byte gUnk_080F0800
    .byte 0x04, 0xAC, 0x00, 0x20, 0x20, 0x70, 0x01, 0x20, 0x20, 0x74, 0x09, 0x48, 0x38, 0x18, 0x02, 0x78
    .byte 0x00, 0x94, 0x28, 0x1C, 0x31, 0x1C, 0x01, 0x23
    bl func_0801D104
    .byte 0x20, 0x78, 0x00, 0x28
    .byte 0x20, 0xD0, 0x60, 0x68, 0x06, 0x28, 0x05, 0xD0, 0x09, 0x28, 0x11, 0xD0, 0x00, 0x20, 0x1C, 0xE0
    .4byte gUnk_080F0800
    .byte 0x05, 0x49, 0x68, 0x18, 0x00, 0x68, 0xA1, 0x68, 0x10, 0x31, 0xE2, 0x68
    .byte 0x20, 0x32, 0x06, 0x23
    bl func_080AB68C
    .byte 0x0C, 0xE0, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .byte 0x08, 0x49, 0x68, 0x18, 0x00, 0x68, 0xA1, 0x68, 0x18, 0x31, 0xE2, 0x68, 0x20, 0x32, 0x09, 0x23
    bl func_080AB68C
    .byte 0x20, 0x7C, 0x01, 0x21, 0x48, 0x40, 0x09, 0xB0, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .global func_0801CAD8
    .thumb_func
func_0801CAD8:
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46
    .byte 0xE0, 0xB4, 0x83, 0xB0, 0x80, 0x46, 0x89, 0x46, 0x15, 0x1C, 0x00, 0x20, 0x28, 0x60, 0x01, 0xAE
    .byte 0x40, 0x46, 0x32, 0x1C
    bl func_0801C198
    .byte 0x00, 0x06, 0x00, 0x28, 0x4E, 0xD0, 0x24, 0x4C
    .byte 0x44, 0x44, 0x20, 0x68, 0x23, 0x49, 0x40, 0x18, 0x07, 0x1C, 0xB1, 0x88, 0xF2, 0x88
    bl GetCellType__C14MineFloorStateUiUi
    .byte 0x00, 0x21, 0x04, 0x28, 0x00, 0xD1, 0x01, 0x21, 0x8A, 0x46, 0xB1, 0x88, 0xF2, 0x88
    .byte 0x23, 0x68, 0x38, 0x1C
    bl BreakRock__14MineFloorStateUiUiR18GameStateSaveImage
    .byte 0x28, 0x60, 0x42, 0x46, 0x10, 0x68, 0x41, 0x69, 0x40, 0x46
    bl _call_via_r1
    .byte 0x4A, 0x46, 0x11, 0x88, 0x89, 0x05, 0x89, 0x0D, 0x88, 0x42
    .byte 0x24, 0xD1, 0x40, 0x46, 0x45, 0x68, 0xB1, 0x88, 0xF2, 0x88, 0x38, 0x1C
    bl GetCellType__C14MineFloorStateUiUi
    .byte 0x04, 0x1C, 0xB1, 0x88, 0xF2, 0x88, 0x38, 0x1C
    bl GetCellTilemap__C14MineFloorStateUiUi
    .byte 0x01, 0xA9, 0x09, 0x88
    .byte 0x72, 0x88, 0x00, 0x90, 0x28, 0x1C, 0x23, 0x1C
    bl func_080AA540
    .byte 0x51, 0x46, 0x00, 0x29
    .byte 0x0C, 0xD0, 0x09, 0x48, 0x40, 0x44, 0x00, 0x68, 0x01, 0xA9, 0x09, 0x88, 0xC9, 0x00, 0x08, 0x31
    .byte 0x72, 0x88, 0xD2, 0x00, 0x10, 0x32, 0x05, 0x23
    bl func_080AB68C
    .byte 0x50, 0x46, 0x06, 0xE0
    .byte 0x38, 0x10, 0x00, 0x00, 0x58, 0x2E, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00, 0x00, 0x20, 0x03, 0xB0
    .byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
    .global func_0801CBB0
    .thumb_func
func_0801CBB0:
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x8F, 0xB0, 0x81, 0x46, 0x0E, 0x91
    .byte 0x92, 0x46, 0x00, 0x26, 0x02, 0x29, 0x2B, 0xD1, 0x00, 0x21, 0x12, 0x48, 0x50, 0x44, 0x80, 0x46
    .byte 0x00, 0x25, 0x4F, 0x1C, 0xAC, 0x20, 0x0C, 0x1C, 0x44, 0x43, 0x0F, 0x48, 0x48, 0x44, 0x00, 0x68
    .byte 0x0E, 0x49, 0x40, 0x18, 0x00, 0x19, 0x42, 0x46, 0x11, 0x78
    bl method_0800A238__9FieldPloti
    .byte 0x00, 0x22
    .byte 0x31, 0x1C, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x21, 0x31, 0x43, 0x00, 0x29, 0x00, 0xD0, 0x01, 0x22
    .byte 0x16, 0x1C, 0x04, 0x34, 0x01, 0x35, 0x2A, 0x2D, 0xE7, 0xD9, 0x39, 0x1C, 0x18, 0x29, 0xDF, 0xD9
    .byte 0x45, 0xE0, 0x00, 0x00
    .4byte gUnk_080F0800
    .byte 0x38, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00
    .byte 0x2C, 0x4C, 0x4C, 0x44, 0x20, 0x68, 0x10, 0x30
    bl GetCalendarEffectiveSeason
    .byte 0x80, 0x46, 0x20, 0x68
    .byte 0x29, 0x4B, 0xC7, 0x18, 0x60, 0x25, 0x07, 0xAC, 0x28, 0x48, 0x82, 0x44, 0x38, 0x1C, 0x29, 0x1C
    .byte 0x42, 0x46
    bl IsAvailable__C14FieldItemStateUii
    .byte 0x00, 0x06, 0x00, 0x28, 0x25, 0xD0, 0x03, 0xA8, 0x39, 0x1C, 0x2A, 0x1C
    bl GetRecord__C14FieldItemStateUi
    .byte 0x04, 0x98, 0x0E, 0x99, 0x88, 0x42, 0x1C, 0xD1, 0x00, 0x20
    .byte 0x20, 0x70, 0x01, 0x22, 0x22, 0x74, 0x1B, 0x48, 0x48, 0x44, 0x01, 0x68, 0x08, 0x1C, 0x14, 0x30
    .byte 0x19, 0x4B, 0xC9, 0x18, 0x53, 0x46, 0x1A, 0x78, 0x00, 0x92, 0x01, 0xAA, 0x01, 0x23, 0x13, 0x70
    .byte 0x02, 0x94, 0x2A, 0x1C, 0x43, 0x46
    bl func_080174C8
    .byte 0x70, 0x42, 0x30, 0x43, 0xC6, 0x0F
    .byte 0x20, 0x7C, 0x01, 0x21, 0x48, 0x40, 0x06, 0x43, 0x01, 0x35, 0x73, 0x2D, 0xCE, 0xD9, 0x00, 0x2E
    .byte 0x0E, 0xD0, 0x4A, 0x46, 0x10, 0x68, 0xA0, 0x23, 0x5B, 0x00, 0xC0, 0x18, 0x0C, 0xA9, 0x0C, 0x4A
    .byte 0x00, 0x23, 0x0C, 0x92, 0x4B, 0x60, 0x03, 0x68, 0x48, 0x46, 0x00, 0x22
    bl _call_via_r3
    .byte 0x30, 0x1C, 0x0F, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0xC8, 0x34, 0x00, 0x00
    .4byte gUnk_080F0800
    .byte 0xDD, 0x03, 0x00, 0x00

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
    .byte 0xF0, 0xB5, 0x89, 0xB0
    .byte 0x05, 0x1C, 0x0E, 0x1C, 0x17, 0x1C, 0x01, 0xA9, 0x00, 0x20, 0x01, 0x90, 0x88, 0x80, 0xC8, 0x80
    .byte 0x08, 0x81, 0x48, 0x81, 0x28, 0x1C, 0x31, 0x1C, 0x01, 0xAA
    bl TryGetFarmPlotAtLocation
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x0D, 0xD0, 0x01, 0xA8, 0x01, 0x89, 0x42, 0x89, 0x04, 0x48, 0x38, 0x18, 0x03, 0x78
    .byte 0x28, 0x1C
    bl func_0801CDBC
    .byte 0x00, 0x06, 0x00, 0x0E, 0x36, 0xE0
    .4byte gUnk_080F0800 + 7
    .byte 0x04, 0xAC, 0x00, 0x20, 0x20, 0x70, 0x01, 0x20, 0x20, 0x74, 0x09, 0x48, 0x38, 0x18, 0x02, 0x78
    .byte 0x00, 0x94, 0x28, 0x1C, 0x31, 0x1C, 0x00, 0x23
    bl func_0801D104
    .byte 0x20, 0x78, 0x00, 0x28
    .byte 0x20, 0xD0, 0x60, 0x68, 0x04, 0x28, 0x13, 0xD0, 0x07, 0x28, 0x03, 0xD0, 0x00, 0x20, 0x1C, 0xE0
    .4byte gUnk_080F0800 + 7
    .byte 0x05, 0x49, 0x68, 0x18, 0x00, 0x68, 0xA1, 0x68, 0x10, 0x31, 0xE2, 0x68
    .byte 0x20, 0x32, 0x07, 0x23
    bl func_080AB68C
    .byte 0x0C, 0xE0, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .byte 0x08, 0x49, 0x68, 0x18, 0x00, 0x68, 0xA1, 0x68, 0x08, 0x31, 0xE2, 0x68, 0x0B, 0x32, 0x04, 0x23
    bl func_080AB68C
    .byte 0x20, 0x7C, 0x01, 0x21, 0x48, 0x40, 0x09, 0xB0, 0xF0, 0xBC, 0x02, 0xBC
    .byte 0x08, 0x47, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
    .global func_0801CFB8
    .thumb_func
func_0801CFB8:
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46
    .byte 0xE0, 0xB4, 0x8F, 0xB0, 0x0E, 0x90, 0x89, 0x46, 0x92, 0x46, 0x00, 0x26, 0x02, 0x29, 0x37, 0xD1
    .byte 0x00, 0x21, 0x18, 0x4A, 0x87, 0x18, 0x18, 0x48, 0x82, 0x44, 0x00, 0x25, 0x4B, 0x1C, 0x99, 0x46
    .byte 0x2B, 0x22, 0x08, 0x1C, 0x50, 0x43, 0x80, 0x46, 0x38, 0x68, 0x14, 0x4B, 0xC0, 0x18, 0x42, 0x46
    .byte 0xA9, 0x18, 0x89, 0x00, 0x40, 0x18, 0x53, 0x46, 0x19, 0x78
    bl method_0800A33C__9FieldPloti
    .byte 0x04, 0x1C
    .byte 0x60, 0x1E, 0x01, 0x28, 0x04, 0xD8, 0x38, 0x68, 0x14, 0x30, 0x01, 0x21
    bl method_08009B68__4FarmUi
    .byte 0x00, 0x21, 0x30, 0x1C, 0x00, 0x2C, 0x01, 0xD0, 0x01, 0x20, 0x30, 0x43, 0x00, 0x28, 0x00, 0xD0
    .byte 0x01, 0x21, 0x0E, 0x1C, 0x01, 0x35, 0x2A, 0x2D, 0xDE, 0xD9, 0x49, 0x46, 0x18, 0x29, 0xD4, 0xD9
    .byte 0x46, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00
    .4byte gUnk_080F0800 + 7
    .byte 0xDC, 0x09, 0x00, 0x00
    .byte 0x0E, 0x98, 0x2C, 0x49, 0x44, 0x18, 0x20, 0x68, 0x10, 0x30
    bl GetCalendarEffectiveSeason
    .byte 0x80, 0x46
    .byte 0x20, 0x68, 0x29, 0x4A, 0x87, 0x18, 0x60, 0x25, 0x07, 0xAC, 0x28, 0x48, 0x82, 0x44, 0x38, 0x1C
    .byte 0x29, 0x1C, 0x42, 0x46
    bl IsAvailable__C14FieldItemStateUii
    .byte 0x00, 0x06, 0x00, 0x28, 0x25, 0xD0, 0x03, 0xA8
    .byte 0x39, 0x1C, 0x2A, 0x1C
    bl GetRecord__C14FieldItemStateUi
    .byte 0x04, 0x98, 0x48, 0x45, 0x1D, 0xD1, 0x00, 0x23
    .byte 0x23, 0x70, 0x01, 0x20, 0x20, 0x74, 0x0E, 0x99, 0x1A, 0x4A, 0x88, 0x18, 0x01, 0x68, 0x08, 0x1C
    .byte 0x14, 0x30, 0x19, 0x4B, 0xC9, 0x18, 0x53, 0x46, 0x1A, 0x78, 0x00, 0x92, 0x01, 0xAA, 0x00, 0x23
    .byte 0x13, 0x70, 0x02, 0x94, 0x2A, 0x1C, 0x43, 0x46
    bl func_080174C8
    .byte 0x70, 0x42, 0x30, 0x43
    .byte 0xC6, 0x0F, 0x20, 0x7C, 0x01, 0x21, 0x48, 0x40, 0x06, 0x43, 0x01, 0x35, 0x73, 0x2D, 0xCE, 0xD9
    .byte 0x00, 0x2E, 0x0E, 0xD0, 0x0E, 0x9A, 0x10, 0x68, 0xA0, 0x23, 0x5B, 0x00, 0xC0, 0x18, 0x0C, 0xA9
    .byte 0x0B, 0x4A, 0x00, 0x23, 0x0C, 0x92, 0x4B, 0x60, 0x03, 0x68, 0x0E, 0x98, 0x00, 0x22
    bl _call_via_r3
    .byte 0x30, 0x1C, 0x0F, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC
    .byte 0x02, 0xBC, 0x08, 0x47, 0x38, 0x10, 0x00, 0x00, 0xC8, 0x34, 0x00, 0x00
    .4byte gUnk_080F0800 + 7
    .byte 0xCF, 0x03, 0x00, 0x00

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
    .byte 0xF0, 0xB5, 0x57, 0x46
    .byte 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x8A, 0xB0, 0x80, 0x46, 0x0C, 0x1C, 0x01, 0xA9, 0x00, 0x20
    .byte 0x01, 0x90, 0x88, 0x80, 0xC8, 0x80, 0x08, 0x81, 0x48, 0x81, 0x40, 0x46, 0x21, 0x1C, 0x01, 0xAA
    bl TryGetFarmPlotAtLocation
    .byte 0x00, 0x06, 0x00, 0x28, 0x00, 0xD1, 0xBE, 0xE0, 0x01, 0x98
    bl method_0800A3C8__9FieldPlot
    .byte 0x04, 0x90, 0x01, 0x28, 0x08, 0xD0, 0x40, 0x42, 0x09, 0x90, 0x04, 0x99, 0x01, 0x29
    .byte 0x00, 0xDC, 0xAD, 0xE0, 0x02, 0x29, 0x09, 0xD0, 0xAA, 0xE0, 0x2C, 0x48, 0x40, 0x44, 0x00, 0x68
    .byte 0xBE, 0x22, 0xD2, 0x00, 0x80, 0x18, 0x01, 0x21
    bl AddStoredBushels__4BarnUi
    .byte 0x43, 0x46, 0x18, 0x68, 0x41, 0x69, 0x40, 0x46
    bl _call_via_r1
    .byte 0x02, 0x28, 0x0D, 0xD1, 0x24, 0x48, 0x40, 0x44
    .byte 0x00, 0x68, 0x01, 0xA9, 0x89, 0x88, 0xC9, 0x00, 0x08, 0x31, 0x01, 0xAA, 0xD2, 0x88, 0xD2, 0x00
    .byte 0x10, 0x32, 0x00, 0x23
    bl func_080AB68C
    .byte 0x41, 0x46, 0x08, 0x68, 0x41, 0x69, 0x40, 0x46
    bl _call_via_r1
    .byte 0x21, 0x88, 0x89, 0x05, 0x89, 0x0D, 0x04, 0x9A, 0x52, 0x42, 0x09, 0x92
    .byte 0x88, 0x42, 0x00, 0xD0, 0x7C, 0xE0, 0x15, 0x48, 0x40, 0x44, 0x01, 0x68, 0x0B, 0x1C, 0x14, 0x33
    .byte 0x05, 0x93, 0x01, 0xA8, 0x04, 0x89, 0x42, 0x89, 0x80, 0x88, 0x06, 0x90, 0x01, 0xA8, 0xC0, 0x88
    .byte 0x10, 0x4B, 0xCB, 0x18, 0x08, 0x93, 0x02, 0x38, 0x81, 0x46, 0x2B, 0x21, 0x10, 0x1C, 0x48, 0x43
    .byte 0x00, 0x19, 0x06, 0x1C, 0x2B, 0x3E, 0x55, 0x1E, 0x02, 0x22, 0x07, 0x92, 0x00, 0x20, 0x00, 0x2C
    .byte 0x06, 0xDB, 0x00, 0x2D, 0x04, 0xDB, 0x2A, 0x2C, 0x02, 0xDC, 0x18, 0x2D, 0x00, 0xDC, 0x01, 0x20
    .byte 0x00, 0x28, 0x09, 0xD0, 0xB0, 0x00, 0x08, 0x99, 0x0B, 0x18, 0x06, 0xE0, 0x38, 0x10, 0x00, 0x00
    .byte 0x28, 0x10, 0x00, 0x00, 0xDC, 0x09, 0x00, 0x00, 0x00, 0x23, 0x1F, 0x1C, 0x00, 0x2F, 0x3E, 0xD0
    .byte 0x42, 0x46, 0x52, 0x68, 0x92, 0x46, 0x05, 0x9B, 0x0C, 0x48, 0x1A, 0x18, 0x2B, 0x1C, 0xB0, 0x00
    .byte 0x80, 0x18, 0x84, 0x46, 0x68, 0x1C, 0x00, 0x21, 0x00, 0x2C, 0x06, 0xDB, 0x00, 0x28, 0x04, 0xDB
    .byte 0x2A, 0x2C, 0x02, 0xDC, 0x18, 0x28, 0x00, 0xDC, 0x01, 0x21, 0x00, 0x29, 0x08, 0xD0, 0x2B, 0x21
    .byte 0x48, 0x43, 0x20, 0x18, 0x80, 0x00, 0x11, 0x18, 0x03, 0xE0, 0x00, 0x00, 0xC8, 0x09, 0x00, 0x00
    .byte 0x00, 0x21, 0x58, 0x1E, 0x00, 0x23, 0x00, 0x2C, 0x06, 0xDB, 0x00, 0x28, 0x04, 0xDB, 0x2A, 0x2C
    .byte 0x02, 0xDC, 0x18, 0x28, 0x00, 0xDC, 0x01, 0x23, 0x00, 0x2B, 0x05, 0xD0, 0x2B, 0x23, 0x58, 0x43
    .byte 0x20, 0x18, 0x80, 0x00, 0x12, 0x18, 0x00, 0xE0, 0x00, 0x22, 0x60, 0x46
    bl method_0800AF5C__C9FieldPlotPC9FieldPlotT1
    .byte 0x00, 0x90, 0x50, 0x46, 0x06, 0x99, 0x4A, 0x46, 0x3B, 0x1C
    bl RefreshFieldPlotTiles
    .byte 0x02, 0x20
    .byte 0x81, 0x44, 0x2B, 0x36, 0x01, 0x35, 0x07, 0x99, 0x01, 0x39, 0x07, 0x91, 0x00, 0x29, 0x9D, 0xDA
    .byte 0x09, 0x9A, 0x04, 0x9B, 0x1A, 0x43, 0xD0, 0x0F, 0x00, 0xE0, 0x00, 0x20, 0x0A, 0xB0, 0x38, 0xBC
    .byte 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
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
    .byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x93, 0xB0
    .byte 0x10, 0x90
    bl func_0801E90C
    .byte 0x00, 0x20, 0x11, 0x90, 0x00, 0x21, 0x12, 0x91, 0x12, 0x9A
    .byte 0x91, 0x46, 0x10, 0x9B, 0x18, 0x68, 0x02, 0x6C, 0x18, 0x1C, 0x12, 0x99
    bl _call_via_r2
    .byte 0x07, 0x1C, 0x00, 0x2F, 0x00, 0xD1, 0xBB, 0xE2, 0x00, 0x20, 0x82, 0x46, 0x12, 0x98, 0x2B, 0x38
    .byte 0x28, 0x28, 0x00, 0xD9, 0xEA, 0xE0, 0x80, 0x00, 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46
    .4byte .L0801E0D4
.L0801E0D4:
    .4byte .L0801E18A
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
    .byte 0x10, 0x99, 0x13, 0x4A, 0x88, 0x18, 0x00, 0x68
    .byte 0x80, 0x68, 0x03, 0x38, 0x01, 0x28, 0x00, 0xD8, 0x8C, 0xE0
.L0801E18A:
    .byte 0xBA, 0x88, 0x8D, 0x20, 0x80, 0x00
    .byte 0x82, 0x42, 0x00, 0xD1, 0x86, 0xE0, 0x10, 0x9B, 0x5D, 0x68, 0x28, 0x68, 0x82, 0x42, 0x15, 0xD1
    .byte 0x68, 0x68
    bl GetMapData
    .byte 0x05, 0x8C, 0x46, 0x8C, 0x10, 0x98, 0x44, 0x68, 0x60, 0x68
    bl GetMapData
    .byte 0x00, 0x22, 0xE0, 0x6A, 0x01, 0xA9, 0x01, 0x90, 0x02, 0x92, 0x0D, 0x81
    .byte 0x4E, 0x81, 0x79, 0x69, 0x06, 0xAC, 0x11, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x02, 0x2A, 0x1D, 0xD1
    .byte 0x01, 0xAB, 0x10, 0x99, 0x0C, 0x4A, 0x88, 0x18, 0x00, 0x68, 0x80, 0x21, 0x58, 0x22, 0x01, 0x90
    .byte 0x00, 0x20, 0x02, 0x90, 0x19, 0x81, 0x5A, 0x81, 0x79, 0x69, 0x08, 0xAC, 0x20, 0x1C, 0xCA, 0x68
    .byte 0x39, 0x1C
    bl _call_via_r2
    .byte 0x01, 0xA8, 0x21, 0x1C
    bl IsMapTerrainBoxBlocked
    .byte 0x00, 0x06
    .byte 0x00, 0x28, 0x4B, 0xD0, 0x4E, 0xE0, 0x00, 0x00, 0x50, 0x10, 0x00, 0x00, 0x01, 0xAB, 0x00, 0x20
    .byte 0x80, 0x46, 0x29, 0x49, 0x08, 0x1C, 0x02, 0x40, 0x19, 0x88, 0x28, 0x4C, 0x20, 0x1C, 0x08, 0x40
    .byte 0x10, 0x43, 0x18, 0x80, 0x59, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x08, 0x40, 0x58, 0x70, 0x59, 0x88
    .byte 0x20, 0x1C, 0x08, 0x40, 0x58, 0x80, 0xD8, 0x78, 0x02, 0x40, 0xDA, 0x70, 0x98, 0x88, 0x04, 0x40
    .byte 0x9C, 0x80, 0x1E, 0x20, 0x00, 0x90, 0x28, 0x1C, 0x19, 0x1C, 0x03, 0x22, 0x00, 0x23
    bl SetLocation__17GameSceneWorldMapRC8LocationiUiUi
    .byte 0x01, 0x22, 0x11, 0x92, 0x10, 0x9B, 0x58, 0x68, 0x40, 0x68
    bl GetMapData
    .byte 0x05, 0x8C, 0x46, 0x8C, 0x10, 0x98, 0x44, 0x68, 0x60, 0x68
    bl GetMapData
    .byte 0xE0, 0x6A
    .byte 0x01, 0xA9, 0x01, 0x90, 0x42, 0x46, 0x02, 0x92, 0x0D, 0x81, 0x4E, 0x81, 0x79, 0x69, 0x0A, 0xAC
    .byte 0x20, 0x1C, 0xCA, 0x68, 0x39, 0x1C
    bl _call_via_r2
    .byte 0x01, 0xA8, 0x21, 0x1C
    bl IsMapTerrainBoxBlocked
    .byte 0x00, 0x06, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x23, 0x9A, 0x46
.L0801E29C:
    .byte 0x50, 0x46, 0x00, 0x28
    .byte 0x00, 0xD1, 0xC5, 0xE1, 0x48, 0x46, 0x2B, 0x38, 0x28, 0x28, 0x00, 0xD9, 0xC0, 0xE1, 0x80, 0x00
    .byte 0x03, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF
    .4byte .L0801E2C4
.L0801E2C4:
    .4byte .L0801E368
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
    .byte 0x00, 0x2F, 0x00, 0xD1, 0x60, 0xE1, 0x04, 0xA9
    .byte 0x02, 0x23, 0x0A, 0x88, 0x0D, 0x4C, 0x20, 0x1C, 0x10, 0x40, 0x18, 0x43, 0x08, 0x80, 0xF8, 0x25
    .byte 0x4B, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x70, 0x05, 0x25, 0x4B, 0x88
    .byte 0x20, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x80, 0xC8, 0x78, 0x02, 0x40, 0x48, 0x20, 0x02, 0x43
    .byte 0xCA, 0x70, 0x01, 0x22, 0x88, 0x88, 0x04, 0x40, 0x14, 0x43, 0x1C, 0xE1, 0x00, 0xFC, 0xFF, 0xFF
.L0801E3B0:
    .byte 0x00, 0x2F, 0x00, 0xD1, 0x3C, 0xE1, 0x03, 0xA9, 0x02, 0x26, 0x0A, 0x88, 0x06, 0x4C, 0x20, 0x1C
    .byte 0x10, 0x40, 0x30, 0x43, 0x08, 0x80, 0xC0, 0x25, 0x4B, 0x78, 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40
    .byte 0x28, 0x43, 0x48, 0x70, 0x0B, 0x25, 0xF9, 0xE0, 0x00, 0xFC, 0xFF, 0xFF
.L0801E3DC:
    .byte 0x00, 0x2F, 0x00, 0xD1
    .byte 0x26, 0xE1, 0xB9, 0x88, 0x11, 0x29, 0x03, 0xD0, 0x8D, 0x20, 0x80, 0x00, 0x81, 0x42, 0x45, 0xD1
    .byte 0x4A, 0x46, 0x2E, 0x3A, 0x10, 0x99, 0x1F, 0x4B, 0xC8, 0x18, 0x01, 0x68, 0x82, 0x20, 0xC0, 0x00
    .byte 0x09, 0x18, 0x0C, 0xA8
    bl method_0800C6F0__C4CoopUi
    .byte 0x0C, 0x98, 0x0D, 0x90, 0x0D, 0xA8, 0x00, 0x21
    .byte 0x46, 0x5E, 0x02, 0x23, 0xC2, 0x5E, 0x90, 0x46, 0x03, 0xA9, 0x11, 0x23, 0x0A, 0x88, 0x16, 0x4D
    .byte 0x28, 0x1C, 0x10, 0x40, 0x18, 0x43, 0x08, 0x80, 0x36, 0x04, 0x32, 0x0C, 0x3F, 0x20, 0x81, 0x46
    .byte 0x02, 0x40, 0x92, 0x00, 0x4C, 0x78, 0x03, 0x23, 0x18, 0x1C, 0x20, 0x40, 0x10, 0x43, 0x48, 0x70
    .byte 0xB6, 0x0D, 0x4A, 0x88, 0x28, 0x1C, 0x10, 0x40, 0x30, 0x43, 0x48, 0x80, 0x42, 0x46, 0x12, 0x04
    .byte 0x90, 0x46, 0x10, 0x0C, 0x4A, 0x46, 0x10, 0x40, 0x80, 0x00, 0xCA, 0x78, 0x13, 0x40, 0x03, 0x43
    .byte 0xCB, 0x70, 0x43, 0x46, 0x9B, 0x0D, 0x88, 0x88, 0x05, 0x40, 0x1D, 0x43, 0x8D, 0x80, 0x01, 0xAD
    .byte 0x01, 0x24, 0xBB, 0xE0, 0x38, 0x10, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x03, 0xA9, 0x02, 0x25
    .byte 0x0A, 0x88, 0x0D, 0x4C, 0x20, 0x1C, 0x10, 0x40, 0x28, 0x43, 0x08, 0x80, 0x4A, 0x78, 0x03, 0x23
    .byte 0x18, 0x1C, 0x10, 0x40, 0x3C, 0x22, 0x10, 0x43, 0x48, 0x70, 0x4A, 0x88, 0x20, 0x1C, 0x10, 0x40
    .byte 0x28, 0x43, 0x48, 0x80, 0xC8, 0x78, 0x03, 0x40, 0x30, 0x20, 0x03, 0x43, 0xCB, 0x70, 0x08, 0x22
    .byte 0x88, 0x88, 0x04, 0x40, 0x14, 0x43, 0x96, 0xE0, 0x00, 0xFC, 0xFF, 0xFF
.L0801E4BC:
    .byte 0x00, 0x2F, 0x00, 0xD1
    .byte 0xB6, 0xE0, 0x10, 0x99, 0x08, 0x68, 0xC2, 0x6B, 0x08, 0x1C, 0x49, 0x46
    bl _call_via_r2
    .byte 0x10, 0x9A, 0x05, 0x4B, 0xD0, 0x18, 0x00, 0x68, 0x82, 0x21, 0xC9, 0x00, 0x40, 0x18, 0x49, 0x46
    .byte 0x4C, 0x39
    bl method_0800C9B8__4CoopUi
    .byte 0xA3, 0xE0, 0x38, 0x10, 0x00, 0x00
.L0801E4EC:
    .byte 0x00, 0x2F, 0x00, 0xD1
    .byte 0x9E, 0xE0, 0xB9, 0x88, 0x25, 0x29, 0x03, 0xD0, 0x8D, 0x20, 0x80, 0x00, 0x81, 0x42, 0x55, 0xD1
    .byte 0x36, 0x22, 0x52, 0x42, 0x4A, 0x44, 0x92, 0x46, 0x10, 0x9B, 0x26, 0x49, 0x58, 0x18, 0x01, 0x68
    .byte 0xBE, 0x22, 0xD2, 0x00, 0x89, 0x18, 0x0E, 0xA8, 0x52, 0x46
    bl method_0800D074__C4BarnUi
    .byte 0x0E, 0x98
    .byte 0x0F, 0x90, 0x0F, 0xA8, 0x00, 0x23, 0xC6, 0x5E, 0x02, 0x22, 0x81, 0x5E, 0x88, 0x46, 0x03, 0xA9
    .byte 0x25, 0x23, 0x0A, 0x88, 0x1C, 0x4D, 0x28, 0x1C, 0x10, 0x40, 0x18, 0x43, 0x08, 0x80, 0x36, 0x04
    .byte 0x32, 0x0C, 0x3F, 0x23, 0x99, 0x46, 0x1A, 0x40, 0x92, 0x00, 0x4C, 0x78, 0x03, 0x23, 0x18, 0x1C
    .byte 0x20, 0x40, 0x10, 0x43, 0x48, 0x70, 0xB6, 0x0D, 0x4A, 0x88, 0x28, 0x1C, 0x10, 0x40, 0x30, 0x43
    .byte 0x48, 0x80, 0x40, 0x46, 0x00, 0x04, 0x80, 0x46, 0x00, 0x0C, 0x4A, 0x46, 0x10, 0x40, 0x80, 0x00
    .byte 0xCA, 0x78, 0x13, 0x40, 0x03, 0x43, 0xCB, 0x70, 0x43, 0x46, 0x9B, 0x0D, 0x88, 0x88, 0x05, 0x40
    .byte 0x1D, 0x43, 0x8D, 0x80, 0x50, 0x46, 0x80, 0x08, 0x82, 0x46, 0x01, 0x20, 0x52, 0x46, 0x02, 0x40
    .byte 0x92, 0x46, 0x01, 0xAC, 0x20, 0x1C, 0x06, 0x22
    bl memcpy
    .byte 0x53, 0x46, 0xA3, 0x71
    .byte 0x29, 0xE0, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x03, 0xA9, 0x02, 0x26
    .byte 0x0A, 0x88, 0x13, 0x4C, 0x20, 0x1C, 0x10, 0x40, 0x30, 0x43, 0x08, 0x80, 0xE0, 0x25, 0x4B, 0x78
    .byte 0x03, 0x22, 0x10, 0x1C, 0x18, 0x40, 0x28, 0x43, 0x48, 0x70, 0x07, 0x25, 0x4B, 0x88, 0x20, 0x1C
    .byte 0x18, 0x40, 0x28, 0x43, 0x48, 0x80, 0xC8, 0x78, 0x02, 0x40, 0x10, 0x20, 0x02, 0x43, 0xCA, 0x70
    .byte 0x88, 0x88, 0x04, 0x40, 0x34, 0x43, 0x8C, 0x80, 0x01, 0xAD, 0x00, 0x24, 0x28, 0x1C, 0x06, 0x22
    bl memcpy
    .byte 0xAC, 0x71, 0x38, 0x1C, 0x01, 0xA9
    bl SetLocation__12AActorEntityRC13ActorLocation
    .byte 0x17, 0xE0
    .byte 0x00, 0xFC, 0xFF, 0xFF
.L0801E604:
    .byte 0x38, 0x1C, 0x02, 0x21, 0xE0, 0x22, 0xA8, 0x23
    bl SetLocation__7AEntityUiii
    .byte 0x0E, 0xE0
.L0801E612:
    .byte 0x10, 0x99, 0x08, 0x68, 0xC2, 0x6B, 0x08, 0x1C, 0x49, 0x46
    bl _call_via_r2
    .byte 0x10, 0x9A, 0x14, 0x4B, 0xD0, 0x18, 0x00, 0x68, 0x13, 0x49, 0x40, 0x18
    bl func_0800ED2C
.L0801E630:
    .byte 0x12, 0x9A, 0x01, 0x32, 0x12, 0x92, 0x63, 0x2A, 0x00, 0xDC, 0x30, 0xE5, 0x11, 0x9B, 0x00, 0x2B
    .byte 0x10, 0xD0, 0x10, 0x98, 0x04, 0x68, 0xB4, 0x34, 0x0A, 0x49, 0x40, 0x18, 0x01, 0x68, 0x0A, 0x4A
    .byte 0x89, 0x18, 0x01, 0xA8
    bl GetLocation__C6Farmer
    .byte 0x23, 0x68, 0x10, 0x98, 0x01, 0xA9, 0x00, 0x22
    bl _call_via_r3
    .byte 0x13, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC
    .byte 0x01, 0xBC, 0x00, 0x47, 0x38, 0x10, 0x00, 0x00, 0xD8, 0x1B, 0x00, 0x00

    thumb_func_start func_0801E67C
func_0801E67C: @ 0x0801E67C
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r7, r0, #0
    ldr r0, [r7, #4]
    ldr r0, [r0, #4]
    cmp r0, #0x2a
    beq .L0801E6B0
    cmp r0, #0x2a
    bgt .L0801E69C
    cmp r0, #0x29
    beq .L0801E6A2
    b .L0801E8F6
.L0801E69C:
    cmp r0, #0x2b
    beq .L0801E6B8
    b .L0801E8F6
.L0801E6A2:
    ldr r1, .L0801E6AC @ =gUnk_080F0704
    str r1, [sp, #0x14]
    movs r1, #5
    b .L0801E6BE
    .align 2, 0
.L0801E6AC: .4byte gUnk_080F0704
.L0801E6B0:
    ldr r1, .L0801E6B4 @ =gUnk_080F0718
    b .L0801E6BA
    .align 2, 0
.L0801E6B4: .4byte gUnk_080F0718
.L0801E6B8:
    ldr r1, .L0801E70C @ =gUnk_080F0730
.L0801E6BA:
    str r1, [sp, #0x14]
    movs r1, #6
.L0801E6BE:
    mov sl, r1
    bl GetMapData
    ldrh r5, [r0, #0x20]
    ldrh r6, [r0, #0x22]
    ldr r4, [r7, #4]
    ldr r0, [r4, #4]
    bl GetMapData
    movs r2, #0
    ldr r0, [r4, #0x2c]
    mov r1, sp
    str r0, [sp]
    str r2, [sp, #4]
    strh r5, [r1, #8]
    strh r6, [r1, #0xa]
    mov r8, r2
.L0801E6E0:
    mov r6, r8
    ldr r0, [r7]
    ldr r2, [r0, #0x40]
    adds r0, r7, #0
    mov r1, r8
    bl _call_via_r2
    adds r5, r0, #0
    cmp r5, #0
    bne .L0801E6F6
    b .L0801E8EA
.L0801E6F6:
    movs r0, #0
    mov sb, r0
    mov r0, r8
    subs r0, #0x2b
    cmp r0, #0x28
    bhi .L0801E7DE
    lsls r0, r0, #2
    ldr r1, .L0801E710 @ =.L0801E714
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801E70C: .4byte gUnk_080F0730
.L0801E710: .4byte .L0801E714
.L0801E714: @ jump table
    .4byte .L0801E7B8 @ case 0
    .4byte .L0801E7DE @ case 1
    .4byte .L0801E7DE @ case 2
    .4byte .L0801E7B8 @ case 3
    .4byte .L0801E7B8 @ case 4
    .4byte .L0801E7B8 @ case 5
    .4byte .L0801E7B8 @ case 6
    .4byte .L0801E7B8 @ case 7
    .4byte .L0801E7B8 @ case 8
    .4byte .L0801E7B8 @ case 9
    .4byte .L0801E7B8 @ case 10
    .4byte .L0801E7DE @ case 11
    .4byte .L0801E7DE @ case 12
    .4byte .L0801E7DE @ case 13
    .4byte .L0801E7DE @ case 14
    .4byte .L0801E7DE @ case 15
    .4byte .L0801E7DE @ case 16
    .4byte .L0801E7DE @ case 17
    .4byte .L0801E7DE @ case 18
    .4byte .L0801E7DE @ case 19
    .4byte .L0801E7DE @ case 20
    .4byte .L0801E7DE @ case 21
    .4byte .L0801E7DE @ case 22
    .4byte .L0801E7DE @ case 23
    .4byte .L0801E7DE @ case 24
    .4byte .L0801E7DE @ case 25
    .4byte .L0801E7DE @ case 26
    .4byte .L0801E7DE @ case 27
    .4byte .L0801E7DE @ case 28
    .4byte .L0801E7DE @ case 29
    .4byte .L0801E7DE @ case 30
    .4byte .L0801E7B8 @ case 31
    .4byte .L0801E7B8 @ case 32
    .4byte .L0801E7B8 @ case 33
    .4byte .L0801E7B8 @ case 34
    .4byte .L0801E7B8 @ case 35
    .4byte .L0801E7B8 @ case 36
    .4byte .L0801E7B8 @ case 37
    .4byte .L0801E7B8 @ case 38
    .4byte .L0801E7B8 @ case 39
    .4byte .L0801E7B8 @ case 40
.L0801E7B8:
    ldrh r0, [r5, #4]
    cmp r0, #0x1d
    bne .L0801E7DE
    ldr r1, [r5, #0x14]
    add r4, sp, #0xc
    adds r0, r4, #0
    ldr r2, [r1, #0xc]
    adds r1, r5, #0
    bl _call_via_r2
    mov r0, sp
    adds r1, r4, #0
    bl IsMapTerrainBoxBlocked
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .L0801E7DE
    movs r1, #1
    mov sb, r1
.L0801E7DE:
    mov r0, sb
    cmp r0, #0
    bne .L0801E7E6
    b .L0801E8EA
.L0801E7E6:
    adds r0, r6, #0
    subs r0, #0x2b
    cmp r0, #0x28
    bhi .L0801E8A0
    lsls r0, r0, #2
    ldr r1, .L0801E7F8 @ =.L0801E7FC
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801E7F8: .4byte .L0801E7FC
.L0801E7FC: @ jump table
    .4byte .L0801E8A0 @ case 0
    .4byte .L0801E8A0 @ case 1
    .4byte .L0801E8A0 @ case 2
    .4byte .L0801E8A0 @ case 3
    .4byte .L0801E8A0 @ case 4
    .4byte .L0801E8A0 @ case 5
    .4byte .L0801E8A0 @ case 6
    .4byte .L0801E8A0 @ case 7
    .4byte .L0801E8A0 @ case 8
    .4byte .L0801E8A0 @ case 9
    .4byte .L0801E8A0 @ case 10
    .4byte .L0801E8A0 @ case 11
    .4byte .L0801E8A0 @ case 12
    .4byte .L0801E8A0 @ case 13
    .4byte .L0801E8A0 @ case 14
    .4byte .L0801E8A0 @ case 15
    .4byte .L0801E8A0 @ case 16
    .4byte .L0801E8A0 @ case 17
    .4byte .L0801E8A0 @ case 18
    .4byte .L0801E8A0 @ case 19
    .4byte .L0801E8A0 @ case 20
    .4byte .L0801E8A0 @ case 21
    .4byte .L0801E8A0 @ case 22
    .4byte .L0801E8A0 @ case 23
    .4byte .L0801E8A0 @ case 24
    .4byte .L0801E8A0 @ case 25
    .4byte .L0801E8A0 @ case 26
    .4byte .L0801E8A0 @ case 27
    .4byte .L0801E8A0 @ case 28
    .4byte .L0801E8A0 @ case 29
    .4byte .L0801E8A0 @ case 30
    .4byte .L0801E8A0 @ case 31
    .4byte .L0801E8A0 @ case 32
    .4byte .L0801E8C6 @ case 33
    .4byte .L0801E8C6 @ case 34
    .4byte .L0801E8C6 @ case 35
    .4byte .L0801E8C6 @ case 36
    .4byte .L0801E8C6 @ case 37
    .4byte .L0801E8C6 @ case 38
    .4byte .L0801E8C6 @ case 39
    .4byte .L0801E8C6 @ case 40
.L0801E8A0:
    cmp r5, #0
    beq .L0801E8EA
    bl rand
    mov r1, sl
    bl __umodsi3
    lsls r0, r0, #2
    ldr r1, [sp, #0x14]
    adds r0, r1, r0
    movs r1, #0
    ldrsh r2, [r0, r1]
    movs r1, #2
    ldrsh r3, [r0, r1]
    adds r0, r5, #0
    movs r1, #0x1d
    bl SetLocation__7AEntityUiii
    b .L0801E8EA
.L0801E8C6:
    cmp r5, #0
    beq .L0801E8EA
    ldr r0, [r7]
    ldr r2, [r0, #0x3c]
    adds r0, r7, #0
    adds r1, r6, #0
    bl _call_via_r2
    ldr r1, .L0801E908 @ =0x00001038
    adds r0, r7, r1
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r6, #0
    subs r1, #0x4c
    bl method_0800C9B8__4CoopUi
.L0801E8EA:
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #0x63
    bgt .L0801E8F6
    b .L0801E6E0
.L0801E8F6:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L0801E908: .4byte 0x00001038

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
    bl IsActive__C23HardwareMusicPlayerSlot
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
    bl func_080A45A8
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

    thumb_func_start func_0801F14C
func_0801F14C: @ 0x0801F14C
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

    thumb_func_start func_0801F2DC
func_0801F2DC: @ 0x0801F2DC
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

    thumb_func_start func_0801FAC8
func_0801FAC8: @ 0x0801FAC8
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

    thumb_func_start func_0801FB7C
func_0801FB7C: @ 0x0801FB7C
    push {r4, r5, r6, r7, lr}
    sub sp, #0x14
    adds r7, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    movs r0, #0xbc
    bl __builtin_new
    adds r1, r5, #0
    bl func_080A6474
    str r0, [sp, #8]
    ldr r0, .L0801FBD8 @ =0x000010CC
    bl __builtin_new
    add r3, sp, #8
    mov r1, sp
    strb r4, [r1]
    adds r1, r5, #0
    adds r2, r6, #0
    bl func_080175B4
    str r0, [sp, #4]
    add r1, sp, #4
    str r1, [sp, #0xc]
    str r0, [sp, #0x10]
    adds r2, r1, #0
    movs r1, #0
    str r1, [r2]
    str r0, [r7]
    ldr r1, [sp, #4]
    cmp r1, #0
    beq .L0801FBCE
    ldr r0, [r1]
    ldr r2, [r0, #8]
    adds r0, r1, #0
    movs r1, #3
    bl _call_via_r2
.L0801FBCE:
    adds r0, r7, #0
    add sp, #0x14
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L0801FBD8: .4byte 0x000010CC
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

    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start RefreshWorldEntitySlot
RefreshWorldEntitySlot:
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
    cmp r0, #(.LslotPlayer - .LworldEntitySlotHandlers) / 4 - 1
    bls .L0801A918
    bl .LstoreWorldEntity
.L0801A918:
    ldr r0, .L0801A920
    adds r0, r7, r0
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.L0801A920: .word .LworldEntitySlotHandlers
.LworldEntitySlotHandlers:
    .word .LslotPlayer @ ENTITY_PLAYER
    .word .LslotLillia @ ENTITY_LILLIA
    .word .LslotRick @ ENTITY_RICK
    .word .LslotPopuri @ ENTITY_POPURI
    .word .LslotBarley @ ENTITY_BARLEY
    .word .LslotMay @ ENTITY_MAY
    .word .LslotSaibara @ ENTITY_SAIBARA
    .word .LslotGray @ ENTITY_GRAY
    .word .LslotDuke @ ENTITY_DUKE
    .word .LslotManna @ ENTITY_MANNA
    .word .LslotBasil @ ENTITY_BASIL
    .word .LslotAnna @ ENTITY_ANNA
    .word .LslotMary @ ENTITY_MARY
    .word .LslotThomas @ ENTITY_THOMAS
    .word .LslotHarris @ ENTITY_HARRIS
    .word .LslotEllen @ ENTITY_ELLEN
    .word .LslotStu @ ENTITY_STU
    .word .LslotJeff @ ENTITY_JEFF
    .word .LslotSasha @ ENTITY_SASHA
    .word .LslotKaren @ ENTITY_KAREN
    .word .LslotDoctor @ ENTITY_DOCTOR
    .word .LslotElli @ ENTITY_ELLI
    .word .LslotCarter @ ENTITY_CARTER
    .word .LslotCliff @ ENTITY_CLIFF
    .word .LslotDoug @ ENTITY_DOUG
    .word .LslotAnn @ ENTITY_ANN
    .word .LslotKai @ ENTITY_KAI
    .word .LslotGotz @ ENTITY_GOTZ
    .word .LslotZack @ ENTITY_ZACK
    .word .LslotWon @ ENTITY_WON
    .word .LslotGourmet @ ENTITY_GOURMET
    .word .LslotHarvestGoddess @ ENTITY_HARVEST_GODDESS
    .word .LslotKappa @ ENTITY_KAPPA
    .word .LslotVan @ ENTITY_VAN
    .word .LslotLouOrRuby @ ENTITY_LOU_OR_RUBY
    .word .LslotChild @ ENTITY_CHILD
    .word .LslotStaid @ ENTITY_STAID
    .word .LslotNappy @ ENTITY_NAPPY
    .word .LslotBold @ ENTITY_BOLD
    .word .LslotChef @ ENTITY_CHEF
    .word .LslotAqua @ ENTITY_AQUA
    .word .LslotHoggy @ ENTITY_HOGGY
    .word .LslotTimid @ ENTITY_TIMID
    .word .LslotFarmDog @ ENTITY_FARM_DOG
    .word .LslotFarmHorse @ ENTITY_FARM_HORSE
    .word .LslotFrisbee @ ENTITY_FRISBEE
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_1
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_2
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_3
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_4
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_5
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_6
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_7
    .word .LslotCoopChicken @ ENTITY_ANIMAL_CHICKEN_SLOT_8
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_1
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_2
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_3
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_4
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_5
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_6
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_7
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_8
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_9
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_10
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_11
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_12
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_13
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_14
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_15
    .word .LslotBarnAnimal @ ENTITY_BARN_ANIMAL_SLOT_16
    .word .LslotScriptVisualEffect @ ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0
    .word .LslotScriptVisualEffect @ ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1
    .word .LslotScriptVisualEffect @ ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2
    .word .LslotScriptVisualEffect @ ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3
    .word .LslotBasket @ ENTITY_BASKET
    .word .LslotBall @ ENTITY_BALL
    .word .LslotCoopEgg @ entity slot 76
    .word .LslotCoopEgg @ entity slot 77
    .word .LslotCoopEgg @ entity slot 78
    .word .LslotCoopEgg @ entity slot 79
    .word .LslotCoopEgg @ entity slot 80
    .word .LslotCoopEgg @ entity slot 81
    .word .LslotCoopEgg @ entity slot 82
    .word .LslotCoopEgg @ entity slot 83
    .word .Lslot84 @ entity slot 84
    .word .LslotSouthTownFirst @ entity slot 85
    .word .LslotSouthTownFirst @ entity slot 86
    .word .LslotSouthTownFirst @ entity slot 87
    .word .LslotSouthTownSecond @ entity slot 88
    .word .LslotSouthTownSecond @ entity slot 89
    .word .LslotSouthTownSecond @ entity slot 90
    .word .LslotYodelRanchHouse @ entity slot 91
    .word .LslotInnSecondFloor @ entity slot 92
    .word .Lslot93 @ entity slot 93
.LslotPlayer:
    ldr r1, .L0801AAAC
    adds r0, r6, r1
    ldr r1, [r0]
    adds r0, r6, #0
    bl CreateWorldPlayerEntity
    bl .LuseCreatedEntity
    .align 2, 0
.L0801AAAC: .word 0x00001038
.LslotFarmDog:
    ldr r2, .L0801AB00
    adds r7, r6, r2
    ldr r2, [r7]
    ldr r1, .L0801AB04
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq .L0801AAC8
    bl .LstoreWorldEntity
.L0801AAC8:
    ldr r0, .L0801AB08
    adds r4, r2, r0
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801AAE6
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #2
    bne .L0801AAE6
    bl .LstoreWorldEntity
.L0801AAE6:
    movs r0, #0x44
    bl __builtin_new
    ldr r3, [r7]
    ldr r1, .L0801AB0C
    adds r2, r3, r1
    adds r1, #0x5c
    adds r3, r3, r1
    adds r1, r6, #0
    bl InitWorldDogEntity
    bl .LuseCreatedEntity
    .align 2, 0
.L0801AB00: .word 0x00001038
.L0801AB04: .word 0x0000219C
.L0801AB08: .word 0x00001C2C
.L0801AB0C: .word 0x00001C70
.LslotFarmHorse:
    ldr r2, .L0801AB60
    adds r0, r6, r2
    ldr r2, [r0]
    ldr r1, .L0801AB64
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq .L0801AB28
    bl .LstoreWorldEntity
.L0801AB28:
    ldr r1, .L0801AB68
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq .L0801AB3A
    bl .LstoreWorldEntity
.L0801AB3A:
    adds r0, r2, #0
    adds r0, #0x14
    bl GetHorse__4Farm
    adds r4, r0, #0
    cmp r4, #0
    bne .L0801AB4C
    bl .LstoreWorldEntity
.L0801AB4C:
    movs r0, #0x40
    bl __builtin_new
    adds r1, r6, #0
    adds r2, r4, #0
    bl InitWorldHorseEntity
    bl .LuseCreatedEntity
    .align 2, 0
.L0801AB60: .word 0x00001038
.L0801AB64: .word 0x0000219A
.L0801AB68: .word 0x000021A1
.LslotCoopChicken:
    mov r7, sl
    subs r7, #0x2e
    ldr r2, .L0801ABF4
    adds r0, r6, r2
    ldr r0, [r0]
    ldr r1, .L0801ABF8
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801AB9E
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #3
    bne .L0801AB9E
    adds r0, r4, #0
    bl GetHeldChickenSlot
    cmp r0, r7
    bne .L0801AB9E
    bl .LstoreWorldEntity
.L0801AB9E:
    ldr r2, .L0801ABF4
    adds r4, r6, r2
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    mov r8, r1
    add r0, r8
    bl GetUnkEnt__C4Coop
    cmp r7, r0
    bne .L0801ABB8
    bl .LstoreWorldEntity
.L0801ABB8:
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Coop
    cmp r7, r0
    blo .L0801ABCC
    bl .LstoreWorldEntity
.L0801ABCC:
    ldr r0, [r4]
    add r0, r8
    adds r1, r7, #0
    bl GetChicken__4CoopUi
    adds r4, r0, #0
    cmp r4, #0
    bne .L0801ABE0
    bl .LstoreWorldEntity
.L0801ABE0:
    movs r0, #0x3c
    bl __builtin_new
    adds r1, r6, #0
    adds r2, r4, #0
    bl InitWorldChickenEntity
    bl .LuseCreatedEntity
    .align 2, 0
.L0801ABF4: .word 0x00001038
.L0801ABF8: .word 0x00001C2C
.LslotBarnAnimal:
    mov r4, sl
    subs r4, #0x36
    mov sb, r4
    ldr r0, .L0801AC54
    adds r7, r6, r0
    ldr r0, [r7]
    movs r1, #0xbe
    lsls r1, r1, #3
    mov r8, r1
    add r0, r8
    bl method_0800D058__C4Barn
    cmp r4, r0
    bne .L0801AC1C
    bl .LstoreWorldEntity
.L0801AC1C:
    ldr r0, [r7]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Barn
    cmp r4, r0
    blo .L0801AC30
    bl .LstoreWorldEntity
.L0801AC30:
    ldr r0, [r7]
    add r0, r8
    adds r1, r4, #0
    bl GetCow__4BarnUi
    adds r4, r0, #0
    cmp r4, #0
    beq .L0801AC58
    movs r0, #0x3c
    bl __builtin_new
    adds r1, r6, #0
    adds r2, r4, #0
    bl InitWorldCowEntity
    bl .LuseCreatedEntity
    .align 2, 0
.L0801AC54: .word 0x00001038
.L0801AC58:
    ldr r0, [r7]
    add r0, r8
    mov r1, sb
    bl GetSheep__4BarnUi
    adds r4, r0, #0
    cmp r4, #0
    bne .L0801AC6C
    bl .LstoreWorldEntity
.L0801AC6C:
    movs r0, #0x3c
    bl __builtin_new
    adds r1, r6, #0
    adds r2, r4, #0
    bl InitWorldSheepEntity
    bl .LuseCreatedEntity
.LslotCoopEgg:
    mov r7, sl
    subs r7, #0x4c
    ldr r0, .L0801ACC4
    adds r4, r6, r0
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetCapacity__C4Coop
    cmp r7, r0
    blo .L0801AC9A
    bl .LstoreWorldEntity
.L0801AC9A:
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    adds r1, r7, #0
    bl GetEgg__C4CoopUi
    adds r4, r0, #0
    cmp r4, #0
    bne .L0801ACB2
    bl .LstoreWorldEntity
.L0801ACB2:
    movs r0, #0x18
    bl __builtin_new
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_08037CC4
    bl .LuseCreatedEntity
    .align 2, 0
.L0801ACC4: .word 0x00001038
.LslotBall:
    ldr r0, .L0801AD60
    adds r4, r6, r0
    ldr r0, [r4]
    ldr r1, .L0801AD64
    adds r0, r0, r1
    bl func_0800E940
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801ACE0
    bl .LstoreWorldEntity
.L0801ACE0:
    ldr r0, [r4]
    ldr r2, .L0801AD68
    adds r4, r0, r2
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801AD14
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #1
    bne .L0801AD14
    adds r0, r4, #0
    bl GetArticle__C8HeldItem
    add r1, sp, #4
    strb r0, [r1]
    adds r0, r1, #0
    bl GetId__C7Article
    cmp r0, #0x35
    bne .L0801AD14
    bl .LstoreWorldEntity
.L0801AD14:
    ldr r0, .L0801AD60
    adds r4, r6, r0
    ldr r0, [r4]
    ldr r1, .L0801AD6C
    adds r0, r0, r1
    movs r1, #0x35
    bl GetFirstSlotWithArticle__C8RucksackUi
    adds r7, r0, #0
    movs r0, #1
    rsbs r0, r0, #0
    cmp r7, r0
    beq .L0801AD30
    b .LstoreWorldEntity
.L0801AD30:
    ldr r0, [r4]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetShelf__9FarmHouse
    cmp r0, #0
    beq .L0801AD4C
    movs r1, #0x35
    bl GetFirstSlotWith__C5ShelfUi
    cmp r0, r7
    beq .L0801AD4C
    b .LstoreWorldEntity
.L0801AD4C:
    movs r0, #0x2c
    bl __builtin_new
    ldr r2, [r4]
    ldr r1, .L0801AD70
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_08038028
    b .LuseCreatedEntity
    .align 2, 0
.L0801AD60: .word 0x00001038
.L0801AD64: .word 0x00001BD8
.L0801AD68: .word 0x00001C2C
.L0801AD6C: .word 0x00001C38
.L0801AD70: .word 0x00001CCC
.LslotBasket:
    ldr r2, .L0801ADC0
    adds r7, r6, r2
    ldr r0, [r7]
    ldr r1, .L0801ADC4
    adds r0, r0, r1
    bl func_0800E934
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801AD8A
    b .LstoreWorldEntity
.L0801AD8A:
    ldr r0, [r7]
    ldr r2, .L0801ADC8
    adds r4, r0, r2
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .L0801ADA8
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #4
    bne .L0801ADA8
    b .LstoreWorldEntity
.L0801ADA8:
    movs r0, #0x1c
    bl __builtin_new
    ldr r2, [r7]
    movs r1, #0xe5
    lsls r1, r1, #5
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_08037E18
    b .LuseCreatedEntity
    .align 2, 0
.L0801ADC0: .word 0x00001038
.L0801ADC4: .word 0x00001BD8
.L0801ADC8: .word 0x00001C2C
.LslotStaid:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801ADEC
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801ADF0
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #0
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801ADEC: .word 0x00001038
.L0801ADF0: .word 0x00001CD4
.LslotNappy:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AE14
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AE18
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #1
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AE14: .word 0x00001038
.L0801AE18: .word 0x00001CD4
.LslotBold:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AE3C
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AE40
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #2
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AE3C: .word 0x00001038
.L0801AE40: .word 0x00001CD4
.LslotChef:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AE64
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AE68
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #3
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AE64: .word 0x00001038
.L0801AE68: .word 0x00001CD4
.LslotAqua:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AE8C
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AE90
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #4
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AE8C: .word 0x00001038
.L0801AE90: .word 0x00001CD4
.LslotHoggy:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AEB4
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AEB8
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #5
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AEB4: .word 0x00001038
.L0801AEB8: .word 0x00001CD4
.LslotTimid:
    movs r0, #0x44
    bl __builtin_new
    ldr r2, .L0801AEDC
    adds r1, r6, r2
    ldr r1, [r1]
    ldr r2, .L0801AEE0
    adds r3, r1, r2
    adds r1, #0x14
    str r1, [sp]
    adds r1, r6, #0
    movs r2, #6
    bl func_08033928
    b .LuseCreatedEntity
    .align 2, 0
.L0801AEDC: .word 0x00001038
.L0801AEE0: .word 0x00001CD4
.LslotLillia:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AEFC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AF00
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035AFC
    b .LuseCreatedEntity
    .align 2, 0
.L0801AEFC: .word 0x00001038
.L0801AF00: .word 0x00001D44
.LslotRick:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AF1C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AF20
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035B64
    b .LuseCreatedEntity
    .align 2, 0
.L0801AF1C: .word 0x00001038
.L0801AF20: .word 0x00001D58
.LslotPopuri:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AF3C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AF40
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035BC8
    b .LuseCreatedEntity
    .align 2, 0
.L0801AF3C: .word 0x00001038
.L0801AF40: .word 0x00001D6C
.LslotBarley:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AF5C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AF60
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035D04
    b .LuseCreatedEntity
    .align 2, 0
.L0801AF5C: .word 0x00001038
.L0801AF60: .word 0x00001D84
.LslotMay:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AF7C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AF80
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035D70
    b .LuseCreatedEntity
    .align 2, 0
.L0801AF7C: .word 0x00001038
.L0801AF80: .word 0x00001D98
.LslotSaibara:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AF9C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AFA0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035DD8
    b .LuseCreatedEntity
    .align 2, 0
.L0801AF9C: .word 0x00001038
.L0801AFA0: .word 0x00001DAC
.LslotGray:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AFBC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AFC0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035E40
    b .LuseCreatedEntity
    .align 2, 0
.L0801AFBC: .word 0x00001038
.L0801AFC0: .word 0x00001DC4
.LslotDuke:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AFDC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801AFE0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035EAC
    b .LuseCreatedEntity
    .align 2, 0
.L0801AFDC: .word 0x00001038
.L0801AFE0: .word 0x00001DD8
.LslotManna:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801AFFC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B000
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035F10
    b .LuseCreatedEntity
    .align 2, 0
.L0801AFFC: .word 0x00001038
.L0801B000: .word 0x00001DEC
.LslotBasil:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B020
    adds r1, r6, r2
    ldr r3, [r1]
    movs r1, #0xf0
    lsls r1, r1, #5
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035F74
    b .LuseCreatedEntity
    .align 2, 0
.L0801B020: .word 0x00001038
.LslotAnna:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B03C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B040
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08035FE0
    b .LuseCreatedEntity
    .align 2, 0
.L0801B03C: .word 0x00001038
.L0801B040: .word 0x00001E14
.LslotMary:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B05C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B060
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036048
    b .LuseCreatedEntity
    .align 2, 0
.L0801B05C: .word 0x00001038
.L0801B060: .word 0x00001E28
.LslotThomas:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B080
    adds r1, r6, r2
    ldr r3, [r1]
    movs r1, #0xf2
    lsls r1, r1, #5
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036184
    b .LuseCreatedEntity
    .align 2, 0
.L0801B080: .word 0x00001038
.LslotHarris:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B09C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B0A0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080361EC
    b .LuseCreatedEntity
    .align 2, 0
.L0801B09C: .word 0x00001038
.L0801B0A0: .word 0x00001E54
.LslotEllen:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B0BC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B0C0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036258
    b .LuseCreatedEntity
    .align 2, 0
.L0801B0BC: .word 0x00001038
.L0801B0C0: .word 0x00001E68
.LslotStu:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B0DC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B0E0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080362C0
    b .LuseCreatedEntity
    .align 2, 0
.L0801B0DC: .word 0x00001038
.L0801B0E0: .word 0x00001E7C
.LslotJeff:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B0FC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B100
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036328
    b .LuseCreatedEntity
    .align 2, 0
.L0801B0FC: .word 0x00001038
.L0801B100: .word 0x00001E90
.LslotSasha:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B11C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B120
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036390
    b .LuseCreatedEntity
    .align 2, 0
.L0801B11C: .word 0x00001038
.L0801B120: .word 0x00001EA4
.LslotKaren:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B13C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B140
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080363F8
    b .LuseCreatedEntity
    .align 2, 0
.L0801B13C: .word 0x00001038
.L0801B140: .word 0x00001EB8
.LslotDoctor:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B15C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B160
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036530
    b .LuseCreatedEntity
    .align 2, 0
.L0801B15C: .word 0x00001038
.L0801B160: .word 0x00001ED0
.LslotElli:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B17C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B180
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036590
    b .LuseCreatedEntity
    .align 2, 0
.L0801B17C: .word 0x00001038
.L0801B180: .word 0x00001EE4
.LslotCarter:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B19C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B1A0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080366CC
    b .LuseCreatedEntity
    .align 2, 0
.L0801B19C: .word 0x00001038
.L0801B1A0: .word 0x00001EFC
.LslotCliff:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B1BC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B1C0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036730
    b .LuseCreatedEntity
    .align 2, 0
.L0801B1BC: .word 0x00001038
.L0801B1C0: .word 0x00001F10
.LslotDoug:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B1DC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B1E0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080367F8
    b .LuseCreatedEntity
    .align 2, 0
.L0801B1DC: .word 0x00001038
.L0801B1E0: .word 0x00001F24
.LslotAnn:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B1FC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B200
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_080368C4
    b .LuseCreatedEntity
    .align 2, 0
.L0801B1FC: .word 0x00001038
.L0801B200: .word 0x00001F38
.LslotKai:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B21C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B220
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036A10
    b .LuseCreatedEntity
    .align 2, 0
.L0801B21C: .word 0x00001038
.L0801B220: .word 0x00001F50
.LslotGotz:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B23C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B240
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036A78
    b .LuseCreatedEntity
    .align 2, 0
.L0801B23C: .word 0x00001038
.L0801B240: .word 0x00001F64
.LslotZack:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B25C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B260
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036B4C
    b .LuseCreatedEntity
    .align 2, 0
.L0801B25C: .word 0x00001038
.L0801B260: .word 0x00001F7C
.LslotWon:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B27C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B280
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036C48
    b .LuseCreatedEntity
    .align 2, 0
.L0801B27C: .word 0x00001038
.L0801B280: .word 0x00001F90
.LslotGourmet:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B29C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B2A0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036CAC
    b .LuseCreatedEntity
    .align 2, 0
.L0801B29C: .word 0x00001038
.L0801B2A0: .word 0x00001FA4
.LslotHarvestGoddess:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B2BC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B2C0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036D0C
    b .LuseCreatedEntity
    .align 2, 0
.L0801B2BC: .word 0x00001038
.L0801B2C0: .word 0x00001FB8
.LslotKappa:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B2DC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B2E0
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036D68
    b .LuseCreatedEntity
    .align 2, 0
.L0801B2DC: .word 0x00001038
.L0801B2E0: .word 0x00001FD0
.LslotVan:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B2FC
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B300
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036DC4
    b .LuseCreatedEntity
    .align 2, 0
.L0801B2FC: .word 0x00001038
.L0801B300: .word 0x00001FE4
.LslotLouOrRuby:
    movs r0, #0x48
    bl __builtin_new
    ldr r2, .L0801B31C
    adds r1, r6, r2
    ldr r3, [r1]
    ldr r1, .L0801B320
    adds r2, r3, r1
    adds r1, r6, #0
    bl func_08036860
    b .LuseCreatedEntity
    .align 2, 0
.L0801B31C: .word 0x00001038
.L0801B320: .word 0x00001FFC
.LslotChild:
    ldr r2, .L0801B34C
    adds r7, r6, r2
    ldr r0, [r7]
    ldr r1, .L0801B350
    adds r0, r0, r1
    bl GetChild__13NpcCollection
    adds r4, r0, #0
    cmp r4, #0
    bne .L0801B33A
    b .LstoreWorldEntity
.L0801B33A:
    movs r0, #0x4c
    bl __builtin_new
    ldr r3, [r7]
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_08036E2C
    b .LuseCreatedEntity
    .align 2, 0
.L0801B34C: .word 0x00001038
.L0801B350: .word 0x00001CD4
.Lslot84:
    ldr r2, .L0801B368
    adds r0, r6, r2
    ldr r1, [r0]
    ldr r0, .L0801B36C
    adds r1, r1, r0
    adds r0, r6, #0
    bl CreateWorldSlot84Entity
    b .LuseCreatedEntity
    .align 2, 0
.L0801B368: .word 0x00001038
.L0801B36C: .word 0x00003494
.LslotFrisbee:
    movs r0, #0x54
    bl __builtin_new
    ldr r2, .L0801B388
    adds r1, r6, r2
    ldr r2, [r1]
    ldr r1, .L0801B38C
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_080398A4
    b .LuseCreatedEntity
    .align 2, 0
.L0801B388: .word 0x00001038
.L0801B38C: .word 0x000034DC
.LslotScriptVisualEffect:
    mov r5, sl
    subs r5, #0x46
    ldr r0, .L0801B3B4
    ldr r4, [r0]
    ldr r2, .L0801B3B8
    adds r4, r4, r2
    movs r0, #0x34
    bl __builtin_new
    lsls r1, r5, #1
    adds r1, r1, r5
    lsls r1, r1, #2
    adds r4, r4, r1
    adds r1, r6, #0
    adds r2, r4, #0
    bl func_08032934
    b .LuseCreatedEntity
    .align 2, 0
.L0801B3B4: .word gUnk_0300040C
.L0801B3B8: .word 0x00000524
.LslotSouthTownFirst:
    mov r4, sl
    subs r4, #0x55
    ldr r1, .L0801B3DC
    adds r0, r6, r1
    ldr r0, [r0]
    ldr r2, .L0801B3E0
    adds r0, r0, r2
    adds r1, r4, #0
    bl GetSouthTownNpcLocation1__13NpcCollectionUi
    adds r1, r0, #0
    adds r0, r6, #0
    adds r2, r4, #0
    bl func_08037A5C
    b .LuseCreatedEntity
    .align 2, 0
.L0801B3DC: .word 0x00001038
.L0801B3E0: .word 0x00001CD4
.LslotSouthTownSecond:
    mov r4, sl
    subs r4, #0x58
    ldr r1, .L0801B404
    adds r0, r6, r1
    ldr r0, [r0]
    ldr r2, .L0801B408
    adds r0, r0, r2
    adds r1, r4, #0
    bl GetSouthTownNpcLocation2__13NpcCollectionUi
    adds r1, r0, #0
    adds r0, r6, #0
    adds r2, r4, #0
    bl func_08037AD0
    b .LuseCreatedEntity
    .align 2, 0
.L0801B404: .word 0x00001038
.L0801B408: .word 0x00001CD4
.LslotYodelRanchHouse:
    ldr r1, .L0801B424
    adds r0, r6, r1
    ldr r0, [r0]
    ldr r2, .L0801B428
    adds r0, r0, r2
    bl GetYodelRanchHouseNpcLocation__13NpcCollection
    adds r1, r0, #0
    adds r0, r6, #0
    bl func_08037B48
    b .LuseCreatedEntity
    .align 2, 0
.L0801B424: .word 0x00001038
.L0801B428: .word 0x00001CD4
.LslotInnSecondFloor:
    ldr r1, .L0801B444
    adds r0, r6, r1
    ldr r0, [r0]
    ldr r2, .L0801B448
    adds r0, r0, r2
    bl GetInnSecondFloorNpcLocation__13NpcCollection
    adds r1, r0, #0
    adds r0, r6, #0
    bl func_08037B80
    b .LuseCreatedEntity
    .align 2, 0
.L0801B444: .word 0x00001038
.L0801B448: .word 0x00001CD4
.Lslot93:
    movs r0, #0x1c
    bl __builtin_new
    ldr r2, .L0801B490
    adds r1, r6, r2
    ldr r2, [r1]
    ldr r1, .L0801B494
    adds r2, r2, r1
    adds r1, r6, #0
    bl func_08038740
.LuseCreatedEntity:
    adds r5, r0, #0
.LstoreWorldEntity:
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
.L0801B490: .word 0x00001038
.L0801B494: .word 0x0000214C

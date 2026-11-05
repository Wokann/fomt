    .include "asm/macro.inc"
    .syntax unified
    .thumb
    .text

    thumb_func_start OnCall__12ScriptEnginei
OnCall__12ScriptEnginei:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x40
    adds r5, r0, #0
    @ Native callable IDs 0x000 through 0x146.
    movs r0, #0xa3
    lsls r0, r0, #1
    cmp r1, r0
    bls .LscriptCall_001A
    bl .LscriptCall_5C96
.LscriptCall_001A:
    lsls r0, r1, #2
    ldr r1, .LscriptCall_0024 @ =.LnativeScriptCallHandlers
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_0024: .word .LnativeScriptCallHandlers
.LnativeScriptCallHandlers: @ jump table
    .word .LscriptCall_0544 @ 0x000 NULL
    .word .LscriptCall_054C @ 0x001 NULL
    .word .LscriptCall_0564 @ 0x002 SetEntityPosition
    .word .LscriptCall_05D6 @ 0x003 GetEntityX
    .word .LscriptCall_0610 @ 0x004 GetEntityY
    .word .LscriptCall_064A @ 0x005 SetEntityFacing
    .word .LscriptCall_072E @ 0x006 GetEntityFacing
    .word .LscriptCall_06E8 @ 0x007 SetEntitySpritePriority
    .word .LscriptCall_0768 @ 0x008 MoveEntityXTo
    .word .LscriptCall_07C2 @ 0x009 MoveEntityXToRaw
    .word .LscriptCall_081A @ 0x00A MoveEntityYTo
    .word .LscriptCall_0874 @ 0x00B MoveEntityYToRaw
    .word .LscriptCall_08CC @ 0x00C WaitForEntityMovement
    .word .LscriptCall_08FA @ 0x00D SetEntityAnim
    .word .LscriptCall_0940 @ 0x00E NoOp014
    .word .LscriptCall_096E @ 0x00F HideEntity
    .word .LscriptCall_0A22 @ 0x010 SetEntityAuxRenderProfile
    .word .LscriptCall_099C @ 0x011 StartEntityEffect
    .word .LscriptCall_09F4 @ 0x012 StopEntityEffect
    .word .LscriptCall_18E8 @ 0x013 GetOppositeFacing
    .word .LscriptCall_1984 @ 0x014 GetEntityLocation
    .word .LscriptCall_0690 @ 0x015 OffsetEntityPosition
    .word .LscriptCall_0A68 @ 0x016 ChangeMap
    .word .LscriptCall_0AD0 @ 0x017 PanCameraTo
    .word .LscriptCall_0B28 @ 0x018 WaitForCameraMovement
    .word .LscriptCall_0B40 @ 0x019 PlayBGM
    .word .LscriptCall_0BA4 @ 0x01A StopBGM
    .word .LscriptCall_0BBC @ 0x01B PlaySong
    .word .LscriptCall_0C02 @ 0x01C StopAllSongs
    .word .LscriptCall_5BA8 @ 0x01D FadeOutBGM
    .word .LscriptCall_0C1A @ 0x01E ResetTalkUi
    .word .LscriptCall_0C32 @ 0x01F TalkOpen
    .word .LscriptCall_0C4A @ 0x020 TalkClose
    .word .LscriptCall_0D00 @ 0x021 TalkMessage
    .word .LscriptCall_0C62 @ 0x022 TalkMessageSlow
    .word .LscriptCall_0CB0 @ 0x023 TalkAppendMessage
    .word .LscriptCall_0DE4 @ 0x024 TalkPromptChoice2
    .word .LscriptCall_0EA0 @ 0x025 TalkPromptChoice3
    .word .LscriptCall_0F8C @ 0x026 TalkPromptChoice4
    .word .LscriptCall_10A4 @ 0x027 TalkChoice2
    .word .LscriptCall_1134 @ 0x028 TalkChoice3
    .word .LscriptCall_11F0 @ 0x029 TalkChoice4
    .word .LscriptCall_12DC @ 0x02A TalkChoice5
    .word .LscriptCall_13F8 @ 0x02B TalkChoice6
    .word .LscriptCall_0D50 @ 0x02C SetTalkNameplateCharacter
    .word .LscriptCall_0D7E @ 0x02D SetTalkNameplateText
    .word .LscriptCall_0DCC @ 0x02E ClearTalkNameplate
    .word .LscriptCall_1540 @ 0x02F SetTalkPortrait
    .word .LscriptCall_156E @ 0x030 ClearTalkPortrait
    .word .LscriptCall_1586 @ 0x031 ShowTalkHeartIndicator
    .word .LscriptCall_15B4 @ 0x032 HideTalkHeartIndicator
    .word .LscriptCall_15CC @ 0x033 FadeOutScreen
    .word .LscriptCall_161A @ 0x034 FadeInScreen
    .word .LscriptCall_1668 @ 0x035 FadeInScreenWithoutSceneHook
    .word .LscriptCall_16B6 @ 0x036 WaitFrames
    .word .LscriptCall_16E0 @ 0x037 CallScript
    .word .LscriptCall_1710 @ 0x038 SetTextVariableNumber
    .word .LscriptCall_1756 @ 0x039 SetTextVariableNumberFieldWidth
    .word .LscriptCall_17AE @ 0x03A SetTextVariableString
    .word .LscriptCall_1814 @ 0x03B RandomU15
    .word .LscriptCall_1830 @ 0x03C RandomIntInclusive
    .word .LscriptCall_1888 @ 0x03D VarGet
    .word .LscriptCall_18B0 @ 0x03E VarSet
    .word .LscriptCall_19BE @ 0x03F IsPlayerHoldingNothing
    .word .LscriptCall_1A56 @ 0x040 GetPlayerHeldItemKind
    .word .LscriptCall_1AA8 @ 0x041 IsPlayerHeldItemWrapped
    .word .LscriptCall_1AFA @ 0x042 GetPlayerHeldFoodId
    .word .LscriptCall_1B60 @ 0x043 GetPlayerHeldArticleId
    .word .LscriptCall_1BC8 @ 0x044 GetPlayerHeldChickenId
    .word .LscriptCall_1C24 @ 0x045 UsePlayerHeldItem
    .word .LscriptCall_1C38 @ 0x046 ClearPlayerHeldItem
    .word .LscriptCall_1C50 @ 0x047 SetPlayerHeldFood
    .word .LscriptCall_1CA4 @ 0x048 SetPlayerHeldArticle
    .word .LscriptCall_1CE4 @ 0x049 SetPlayerHeldWrappedFood
    .word .LscriptCall_1D36 @ 0x04A SetPlayerHeldWrappedArticle
    .word .LscriptCall_19DC @ 0x04B CanDiscardPlayerHeldArticle
    .word .LscriptCall_1D76 @ 0x04C TryShipPlayerHeldItem
    .word .LscriptCall_1DB4 @ 0x04D ThrowPlayerHeldItem
    .word .LscriptCall_1DC6 @ 0x04E GetPlayerHeldToolId
    .word .LscriptCall_1E18 @ 0x04F GetPlayerHeldToolStackCount
    .word .LscriptCall_1E60 @ 0x050 SetPlayerHeldTool
    .word .LscriptCall_1F84 @ 0x051 ClearPlayerHeldTool
    .word .LscriptCall_1FA8 @ 0x052 FindFoodInRucksack
    .word .LscriptCall_1FE0 @ 0x053 FindArticleInRucksack
    .word .LscriptCall_2018 @ 0x054 ClearRucksackItemSlot
    .word .LscriptCall_2054 @ 0x055 GetFirstFreeRucksackToolSlot
    .word .LscriptCall_206C @ 0x056 GetFirstFreeRucksackItemSlot
    .word .LscriptCall_2090 @ 0x057 AddArticleToRucksack
    .word .LscriptCall_20D8 @ 0x058 AddFoodToRucksack
    .word .LscriptCall_2120 @ 0x059 AddToolToRucksack
    .word .LscriptCall_5B7A @ 0x05A ShowPlayerHoldingTool
    .word .LscriptCall_49B0 @ 0x05B ChangePlayerStaminaAndFatigue
    .word .LscriptCall_4702 @ 0x05C IsPlayerHoldingTool
    .word .LscriptCall_47F2 @ 0x05D PlayerOwnsTool
    .word .LscriptCall_481C @ 0x05E PlayerOwnsFood
    .word .LscriptCall_4846 @ 0x05F PlayerOwnsArticle
    .word .LscriptCall_5912 @ 0x060 RemoveAllOwnedArticles
    .word .LscriptCall_51B8 @ 0x061 ObtainPowerBerry
    .word .LscriptCall_51D0 @ 0x062 ObtainMysticBerry
    .word .LscriptCall_51E8 @ 0x063 IsPlayerRidingHorse
    .word .LscriptCall_56C4 @ 0x064 EnterHotSpringBathingState
    .word .LscriptCall_56D8 @ 0x065 ExitHotSpringBathingState
    .word .LscriptCall_56EC @ 0x066 PreservePlayerLocationForNextDay
    .word .LscriptCall_5700 @ 0x067 ClearPreservedPlayerLocation
    .word .LscriptCall_5714 @ 0x068 GetPreservedPlayerMapId
    .word .LscriptCall_5734 @ 0x069 EatRandomMeal
    .word .LscriptCall_574C @ 0x06A PreparePlayerForScriptedAnimation
    .word .LscriptCall_5760 @ 0x06B RestorePlayerAfterScriptedAnimation
    .word .LscriptCall_520C @ 0x06C GetPresentedItemKind
    .word .LscriptCall_522E @ 0x06D GetPresentedItemId
    .word .LscriptCall_5250 @ 0x06E IsPresentedItemGiftWrapped
    .word .LscriptCall_4774 @ 0x06F CanReceiveTool
    .word .LscriptCall_479E @ 0x070 CanReceiveFood
    .word .LscriptCall_47C8 @ 0x071 CanReceiveArticle
    .word .LscriptCall_492A @ 0x072 GivePlayerBasket
    .word .LscriptCall_4958 @ 0x073 PlayerHasBasket
    .word .LscriptCall_4980 @ 0x074 UpgradeRucksack
    .word .LscriptCall_4998 @ 0x075 GetRucksackUpgradeLevel
    .word .LscriptCall_58E2 @ 0x076 SetPlayerActorUpdateSuspended
    .word .LscriptCall_2168 @ 0x077 HasLocalLinkMilestone
    .word .LscriptCall_21B0 @ 0x078 HasReceivedLinkMilestone
    .word .LscriptCall_21F8 @ 0x079 SetLocalLinkMilestone
    .word .LscriptCall_223C @ 0x07A ClearLocalLinkMilestone
    .word .LscriptCall_2280 @ 0x07B IsCharacterBirthdayToday
    .word .LscriptCall_22F0 @ 0x07C GetNpcFriendship
    .word .LscriptCall_2334 @ 0x07D AddNpcFriendship
    .word .LscriptCall_2388 @ 0x07E SetNpcFriendship
    .word .LscriptCall_23DC @ 0x07F GetDaysSinceLastSpokenToNpc
    .word .LscriptCall_2420 @ 0x080 MarkNpcSpokenTo
    .word .LscriptCall_245C @ 0x081 WasNpcSpokenToToday
    .word .LscriptCall_24A4 @ 0x082 WasNpcSpokenToJustNow
    .word .LscriptCall_24EC @ 0x083 HasMetNpc
    .word .LscriptCall_2534 @ 0x084 MarkNpcGifted
    .word .LscriptCall_2570 @ 0x085 WasNpcGiftedToday
    .word .LscriptCall_25B8 @ 0x086 GetCharacterLove
    .word .LscriptCall_25FC @ 0x087 AddCharacterLove
    .word .LscriptCall_2650 @ 0x088 SetCharacterLove
    .word .LscriptCall_26A4 @ 0x089 SetEntityEventScript
    .word .LscriptCall_26EA @ 0x08A ClearEntityEventScript
    .word .LscriptCall_2718 @ 0x08B OpenSupermarketShop
    .word .LscriptCall_2730 @ 0x08C PurchaseSupermarketItem
    .word .LscriptCall_278E @ 0x08D OpenWonShop
    .word .LscriptCall_27A6 @ 0x08E OpenCarpenterShop
    .word .LscriptCall_27BE @ 0x08F OpenBlacksmithShop
    .word .LscriptCall_27D6 @ 0x090 OpenClinicShop
    .word .LscriptCall_27EE @ 0x091 OpenBeachCafeShop
    .word .LscriptCall_2806 @ 0x092 OpenYodelRanchShop
    .word .LscriptCall_281E @ 0x093 OpenWineryShop
    .word .LscriptCall_2836 @ 0x094 OpenInnShop
    .word .LscriptCall_284E @ 0x095 OpenPoultryFarmShop
    .word .LscriptCall_275E @ 0x096 OpenSpecialMerchantShop
    .word .LscriptCall_2776 @ 0x097 OpenGiftWrappingMenu
    .word .LscriptCall_2866 @ 0x098 ShowReferencePage
    .word .LscriptCall_2894 @ 0x099 OpenBookList
    .word .LscriptCall_28AC @ 0x09A OpenLetterList
    .word .LscriptCall_28C4 @ 0x09B OpenCalendar
    .word .LscriptCall_28DC @ 0x09C OpenShelf
    .word .LscriptCall_28F4 @ 0x09D OpenToolChest
    .word .LscriptCall_290C @ 0x09E OpenRefrigerator
    .word .LscriptCall_2924 @ 0x09F OpenClock
    .word .LscriptCall_2C14 @ 0x0A0 OpenCookingMenu
    .word .LscriptCall_2C2C @ 0x0A1 OpenRecipeList
    .word .LscriptCall_2C44 @ 0x0A2 RunGameCubeLink
    .word .LscriptCall_3C56 @ 0x0A3 OpenNameEntry
    .word .LscriptCall_2C5C @ 0x0A4 StartFarmInheritanceFlashback
    .word .LscriptCall_2C74 @ 0x0A5 OpenNameEntryKeyboard
    .word .LscriptCall_2C8C @ 0x0A6 OpenRucksackMenu
    .word .LscriptCall_2CC0 @ 0x0A7 SelectFestivalAnimal
    .word .LscriptCall_2CEE @ 0x0A8 RunStaffCredits
    .word .LscriptCall_2D06 @ 0x0A9 OpenFarmingTutorial
    .word .LscriptCall_293C @ 0x0AA PrepareClockMenuTransition
    .word .LscriptCall_2954 @ 0x0AB RestoreAfterClockMenu
    .word .LscriptCall_296C @ 0x0AC PrepareCookingMenuTransition
    .word .LscriptCall_2984 @ 0x0AD RestoreAfterCookingMenu
    .word .LscriptCall_299C @ 0x0AE PrepareRecipeMenuTransition
    .word .LscriptCall_29B4 @ 0x0AF RestoreAfterRecipeMenu
    .word .LscriptCall_2B5A @ 0x0B0 RecordPlayerHasAlbum
    .word .LscriptCall_2B82 @ 0x0B1 SwapRecordPlayerAlbum
    .word .LscriptCall_2BF2 @ 0x0B2 RemoveRecordPlayerAlbum
    .word .LscriptCall_3D6C @ 0x0B3 LightFireplaceAtLocation
    .word .LscriptCall_3D9A @ 0x0B4 IsFireplaceLitAtLocation
    .word .LscriptCall_3E3C @ 0x0B5 SetVaseArticleId
    .word .LscriptCall_3E6A @ 0x0B6 GetVaseArticleId
    .word .LscriptCall_29CC @ 0x0B7 IsChickenFeedTroughFilled
    .word .LscriptCall_2A02 @ 0x0B8 FillChickenFeedTrough
    .word .LscriptCall_3EBC @ 0x0B9 BeginEggIncubation
    .word .LscriptCall_3EEA @ 0x0BA IsIncubatorOccupied
    .word .LscriptCall_5272 @ 0x0BB GetIncubatorCapacity
    .word .LscriptCall_5294 @ 0x0BC IsEggReadyToHatch
    .word .LscriptCall_52C8 @ 0x0BD AttemptEggHatch
    .word .LscriptCall_2A46 @ 0x0BE IsBarnFeedTroughFilled
    .word .LscriptCall_2A9C @ 0x0BF FillBarnFeedTrough
    .word .LscriptCall_2AFC @ 0x0C0 StartShipmentBoxDepositAnimation
    .word .LscriptCall_5322 @ 0x0C1 GetPregnancyStallCapacity
    .word .LscriptCall_5344 @ 0x0C2 IsBarnAnimalReadyToGiveBirth
    .word .LscriptCall_5378 @ 0x0C3 AttemptBarnAnimalBirth
    .word .LscriptCall_5560 @ 0x0C4 BuildMountainCottage
    .word .LscriptCall_556E @ 0x0C5 BuildSeasideCottage
    .word .LscriptCall_3C9C @ 0x0C6 HasGoldenLumberOnFarm
    .word .LscriptCall_557C @ 0x0C7 OpenDoor
    .word .LscriptCall_55A6 @ 0x0C8 CloseDoor
    .word .LscriptCall_2BC2 @ 0x0C9 RedrawRucksackShelfAfterPurchase
    .word .LscriptCall_2BDA @ 0x0CA RedrawBlueFeatherShelfAfterPurchase
    .word .LscriptCall_2D34 @ 0x0CB GetHarvestSpriteCurrentTask
    .word .LscriptCall_2D78 @ 0x0CC GetHarvestSpriteWorkDaysLeft
    .word .LscriptCall_2DBC @ 0x0CD GetHarvestSpriteTaskExperience
    .word .LscriptCall_2E14 @ 0x0CE HasHarvestSpritePlayedMinigameToday
    .word .LscriptCall_2E5C @ 0x0CF HasHarvestSpriteMinigameExperience
    .word .LscriptCall_2EC4 @ 0x0D0 StartHarvestSpriteTask
    .word .LscriptCall_2F2C @ 0x0D1 ScheduleHarvestSpriteTaskToEndAfterToday
    .word .LscriptCall_2F68 @ 0x0D2 IsHarvestSpriteDailyWorkComplete
    .word .LscriptCall_2FA2 @ 0x0D3 RunHarvestSpriteAnimalCareMinigame
    .word .LscriptCall_2FFE @ 0x0D4 RunHarvestSpriteHarvestingMinigame
    .word .LscriptCall_2FD0 @ 0x0D5 RunHarvestSpriteWateringMinigame
    .word .LscriptCall_302C @ 0x0D6 RunChickenFestivalContest
    .word .LscriptCall_3044 @ 0x0D7 RunHorseRace
    .word .LscriptCall_3072 @ 0x0D8 PrepareHorseRaceEntries
    .word .LscriptCall_30CC @ 0x0D9 OpenHorseRaceMedalExchange
    .word .LscriptCall_30E4 @ 0x0DA RunFrisbeeGame
    .word .LscriptCall_3118 @ 0x0DB RunFrisbeeTournamentRound
    .word .LscriptCall_3130 @ 0x0DC PrepareAnimalFestivalOpponents
    .word .LscriptCall_3158 @ 0x0DD GetTVShoppingSelection
    .word .LscriptCall_317C @ 0x0DE GetPendingTVShoppingItem
    .word .LscriptCall_31A0 @ 0x0DF IsTVShoppingDeliveryReady
    .word .LscriptCall_31C8 @ 0x0E0 SetTVShoppingSelection
    .word .LscriptCall_31F8 @ 0x0E1 ConfirmTVShoppingOrder
    .word .LscriptCall_3210 @ 0x0E2 CompleteTVShoppingDelivery
    .word .LscriptCall_33BC @ 0x0E3 IsVacationVillaBuilt
    .word .LscriptCall_33E0 @ 0x0E4 AreAllRequiredVillagersAtMaxFriendship
    .word .LscriptCall_3408 @ 0x0E5 HasShippedOneOfEachCrop
    .word .LscriptCall_343E @ 0x0E6 AreAllFarmAnimalsAtMaxAffection
    .word .LscriptCall_345C @ 0x0E7 HasShippedOneOfEachMineral
    .word .LscriptCall_3472 @ 0x0E8 HasCaughtEveryFishSpecies
    .word .LscriptCall_3496 @ 0x0E9 GetTotalFishCaught
    .word .LscriptCall_34B8 @ 0x0EA HasObtainedMythicTool
    .word .LscriptCall_3428 @ 0x0EB HasShippedOneOfEachProduct
    .word .LscriptCall_34D6 @ 0x0EC GetMoney
    .word .LscriptCall_34F8 @ 0x0ED AddMoney
    .word .LscriptCall_3528 @ 0x0EE SubtractMoney
    .word .LscriptCall_3D3C @ 0x0EF EnableScriptedNpcControl
    .word .LscriptCall_3D54 @ 0x0F0 DisableScriptedNpcControl
    .word .LscriptCall_3F20 @ 0x0F1 GetBlacksmithOrderId
    .word .LscriptCall_3F44 @ 0x0F2 IsBlacksmithOrderReady
    .word .LscriptCall_3F6C @ 0x0F3 CollectBlacksmithOrder
    .word .LscriptCall_44E0 @ 0x0F4 SetGameTime
    .word .LscriptCall_4554 @ 0x0F5 IsLetterWaiting
    .word .LscriptCall_458A @ 0x0F6 HasReceivedLetter
    .word .LscriptCall_45C0 @ 0x0F7 DeliverLetter
    .word .LscriptCall_45EC @ 0x0F8 MarkLetterRead
    .word .LscriptCall_4618 @ 0x0F9 GetWaitingLetterCount
    .word .LscriptCall_462E @ 0x0FA GetSavedLetterCount
    .word .LscriptCall_5514 @ 0x0FB ShowTelevisionMessage
    .word .LscriptCall_2B14 @ 0x0FC SetTelevisionProgram
    .word .LscriptCall_2B42 @ 0x0FD EndTelevisionProgram
    .word .LscriptCall_49F6 @ 0x0FE RefreshAllNpcSchedules
    .word .LscriptCall_4A0E @ 0x0FF DoesAnimalExist
    .word .LscriptCall_4A5A @ 0x100 CreateFarmHorse
    .word .LscriptCall_4AE4 @ 0x101 RemoveFarmHorse
    .word .LscriptCall_4B2A @ 0x102 GetAnimalName
    .word .LscriptCall_4B96 @ 0x103 GetInteractingAnimalIndex
    .word .LscriptCall_4BB0 @ 0x104 HasAnimalBeenTalkedTo
    .word .LscriptCall_4BFA @ 0x105 SetAnimalTalkedTo
    .word .LscriptCall_4C86 @ 0x106 AddAnimalAffection
    .word .LscriptCall_4CDE @ 0x107 IsAnimalUnhappy
    .word .LscriptCall_4D28 @ 0x108 IsAnimalSick
    .word .LscriptCall_4D72 @ 0x109 IsAnimalPregnant
    .word .LscriptCall_4DBC @ 0x10A GetAnimalHealthyPregnancyDays
    .word .LscriptCall_4C3E @ 0x10B GetAnimalAge
    .word .LscriptCall_4E04 @ 0x10C GetAnimalAffection
    .word .LscriptCall_4E4C @ 0x10D GetAnimalGrowthStage
    .word .LscriptCall_4F3A @ 0x10E IsSheepSheared
    .word .LscriptCall_5036 @ 0x10F CountAnimalsByLifeState
    .word .LscriptCall_5158 @ 0x110 ShowLivestockNeglectDeathSummary
    .word .LscriptCall_5170 @ 0x111 RemoveLivestockDeadFromNeglect
    .word .LscriptCall_5188 @ 0x112 ShowNaturalLivestockDeathSummary
    .word .LscriptCall_51A0 @ 0x113 RemoveNaturallyDeadLivestock
    .word .LscriptCall_53D2 @ 0x114 IsCowAtBarnSlot
    .word .LscriptCall_48D0 @ 0x115 GetCowCount
    .word .LscriptCall_48E6 @ 0x116 GetSheepCount
    .word .LscriptCall_4908 @ 0x117 GetChickenCount
    .word .LscriptCall_4F74 @ 0x118 SetContestAnimal
    .word .LscriptCall_4FBA @ 0x119 ClearContestAnimal
    .word .LscriptCall_4FE8 @ 0x11A GetContestAnimalIndex
    .word .LscriptCall_547C @ 0x11B SetTextVariableToCaughtFishName
    .word .LscriptCall_54B4 @ 0x11C GetCaughtFishSize
    .word .LscriptCall_54D4 @ 0x11D IsCaughtFishMaximumSize
    .word .LscriptCall_54F4 @ 0x11E IsCaughtFishKing
    .word .LscriptCall_3558 @ 0x11F SelectMoonViewingPartner
    .word .LscriptCall_387E @ 0x120 GetCookingFestivalDishRating
    .word .LscriptCall_3B7C @ 0x121 SelectThomasStockingGift
    .word .LscriptCall_3BA8 @ 0x122 GetRandomSpouseGiftArticleId
    .word .LscriptCall_3BDE @ 0x123 UnlockNextVanAlbum
    .word .LscriptCall_3C04 @ 0x124 AreAllVanAlbumsAvailable
    .word .LscriptCall_3CB2 @ 0x125 SetPlayerNicknameForSpouse
    .word .LscriptCall_4650 @ 0x126 PlacePlayerAtFarmhouseBed
    .word .LscriptCall_46A0 @ 0x127 FlashScreenColor
    .word .LscriptCall_475C @ 0x128 RebuildMapEntitiesForNewDay
    .word .LscriptCall_5AF0 @ 0x129 CureAllSickLivestock
    .word .LscriptCall_5A4E @ 0x12A AddAffectionToAllFarmAnimals
    .word .LscriptCall_4870 @ 0x12B EnableShootingStarShippingBonus
    .word .LscriptCall_4888 @ 0x12C GetAmountShipped
    .word .LscriptCall_544C @ 0x12D CreatePlayerChildEntity
    .word .LscriptCall_5B04 @ 0x12E RelocateEntityToMap
    .word .LscriptCall_566C @ 0x12F CreateNewYearSunriseEffect
    .word .LscriptCall_5680 @ 0x130 PlayNewYearSunriseEffect
    .word .LscriptCall_5698 @ 0x131 DestroyNewYearSunriseEffect
    .word .LscriptCall_56AC @ 0x132 PlayStarSparkleEffect
    .word .LscriptCall_5BBA @ 0x133 GetKnownRecipeCount
    .word .LscriptCall_4716 @ 0x134 GenerateMineFloorLayout
    .word .LscriptCall_5464 @ 0x135 DescendMineFloor
    .word .LscriptCall_55D0 @ 0x136 IsToolCursed
    .word .LscriptCall_5604 @ 0x137 AdvanceCursedToolLiftProgress
    .word .LscriptCall_5638 @ 0x138 AttemptChurchCursedToolRemoval
    .word .LscriptCall_5778 @ 0x139 CreateEventIcon
    .word .LscriptCall_5806 @ 0x13A RemoveEventIcon
    .word .LscriptCall_585E @ 0x13B GetFoodIconId
    .word .LscriptCall_589E @ 0x13C GetArticleIconId
    .word .LscriptCall_5830 @ 0x13D GetToolIconId
    .word .LscriptCall_5C96 @ 0x13E NoOpTutorialFieldTile
    .word .LscriptCall_5C96 @ 0x13F NoOpTutorialFieldObject
    .word .LscriptCall_5C96 @ 0x140 NoOpTutorialEggDefinition
    .word .LscriptCall_5C96 @ 0x141 NoOpTutorialEggSelection
    .word .LscriptCall_5BEC @ 0x142 BeginHoldingActorGraphic
    .word .LscriptCall_5C96 @ 0x143 NoOpAnimalEventEntityInitialization
    .word .LscriptCall_5C42 @ 0x144 SetTextVariableToProductName
    .word .LscriptCall_5C1E @ 0x145 GetEventContextValue
    .word .LscriptCall_1EB8 @ 0x146 CycleBackwardToNonCursedTool
.LnativeScriptCallHandlersEnd:
.LscriptCall_0544:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    b .LscriptCall_0552
.LscriptCall_054C:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r1, r5, r2
.LscriptCall_0552:
    ldr r0, [r1]
    cmp r0, #0
    bne .LscriptCall_055C
    bl .LscriptCall_5C96
.LscriptCall_055C:
    subs r0, #1
    str r0, [r1]
    bl .LscriptCall_5C96
.LscriptCall_0564:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r2, r5, r3
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_0582
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0582:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0594
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0594:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_05A6
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_05A6:
    ldr r4, [r2]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_05B8
    subs r0, r4, #1
    str r0, [r2]
.LscriptCall_05B8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_05C8
    bl .LscriptCall_5C96
.LscriptCall_05C8:
    mov r6, r8
    str r6, [sp]
    adds r2, r7, #0
    bl SetEntityPosition__9GameSceneUiiiUi
    bl .LscriptCall_5C96
.LscriptCall_05D6:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_05F2
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_05F2:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_0602
    bl .LscriptCall_501E
.LscriptCall_0602:
    adds r0, r1, #0
    adds r1, r3, #0
    bl GetEntityX__9GameSceneUi
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_0610:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_062C
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_062C:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_063C
    bl .LscriptCall_501E
.LscriptCall_063C:
    adds r0, r1, #0
    adds r1, r3, #0
    bl GetEntityY__9GameSceneUi
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_064A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0666
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_0666:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_0678
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_0678:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0688
    bl .LscriptCall_5C96
.LscriptCall_0688:
    bl SetEntityFacing__9GameSceneUiUi
    bl .LscriptCall_5C96
.LscriptCall_0690:
    adds r7, r5, #0
    adds r7, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r6, r5, r4
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_06AC
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_06AC:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_06BE
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_06BE:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_06D0
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_06D0:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_06E0
    bl .LscriptCall_5C96
.LscriptCall_06E0:
    bl OffsetEntityPosition__9GameSceneUiii
    bl .LscriptCall_5C96
.LscriptCall_06E8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0704
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_0704:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_0716
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_0716:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0726
    bl .LscriptCall_5C96
.LscriptCall_0726:
    bl SetEntitySpritePriority__9GameSceneUiUi
    bl .LscriptCall_5C96
.LscriptCall_072E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_074A
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_074A:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_075A
    bl .LscriptCall_501E
.LscriptCall_075A:
    adds r0, r1, #0
    adds r1, r3, #0
    bl GetEntityFacing__9GameSceneUi
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_0768:
    adds r7, r5, #0
    adds r7, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r6, r5, r2
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0784
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0784:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0796
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0796:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_07A8
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_07A8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_07B8
    bl .LscriptCall_5C96
.LscriptCall_07B8:
    lsls r3, r3, #0x10
    bl MoveEntityXTo__9GameSceneUiUii
    bl .LscriptCall_5C96
.LscriptCall_07C2:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_07DE
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_07DE:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_07F0
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_07F0:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_0802
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_0802:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0812
    bl .LscriptCall_5C96
.LscriptCall_0812:
    bl MoveEntityXTo__9GameSceneUiUii
    bl .LscriptCall_5C96
.LscriptCall_081A:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0836
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0836:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0848
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0848:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_085A
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_085A:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_086A
    bl .LscriptCall_5C96
.LscriptCall_086A:
    lsls r3, r3, #0x10
    bl MoveEntityYTo__9GameSceneUiUii
    bl .LscriptCall_5C96
.LscriptCall_0874:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0890
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0890:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_08A2
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_08A2:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_08B4
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_08B4:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_08C4
    bl .LscriptCall_5C96
.LscriptCall_08C4:
    bl MoveEntityYTo__9GameSceneUiUii
    bl .LscriptCall_5C96
.LscriptCall_08CC:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_08E2
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_08E2:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_08F2
    bl .LscriptCall_1DAE
.LscriptCall_08F2:
    bl WaitForEntityMovement__9GameSceneUi
    bl .LscriptCall_1DAE
.LscriptCall_08FA:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0916
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_0916:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_0928
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_0928:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0938
    bl .LscriptCall_5C96
.LscriptCall_0938:
    bl SetEntityAnim__9GameSceneUiUi
    bl .LscriptCall_5C96
.LscriptCall_0940:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_0956
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_0956:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0966
    bl .LscriptCall_5C96
.LscriptCall_0966:
    bl NoOp014__9GameScenei
    bl .LscriptCall_5C96
.LscriptCall_096E:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_0984
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_0984:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0994
    bl .LscriptCall_5C96
.LscriptCall_0994:
    bl HideEntity__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_099C:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_09B8
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_09B8:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_09CA
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_09CA:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_09DC
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_09DC:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_09EC
    bl .LscriptCall_5C96
.LscriptCall_09EC:
    bl StartEntityEffect__9GameSceneUiUiUi
    bl .LscriptCall_5C96
.LscriptCall_09F4:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_0A0A
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_0A0A:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0A1A
    bl .LscriptCall_5C96
.LscriptCall_0A1A:
    bl StopEntityEffect__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_0A22:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0A3E
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_0A3E:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_0A50
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_0A50:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0A60
    bl .LscriptCall_5C96
.LscriptCall_0A60:
    bl SetEntityAuxRenderProfile__9GameSceneUiUi
    bl .LscriptCall_5C96
.LscriptCall_0A68:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0A84
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0A84:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0A96
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0A96:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_0AA8
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_0AA8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_0AB8
    bl ChangeMap__9GameSceneUiii
.LscriptCall_0AB8:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_0ACC @ =0x000034D8
    adds r0, r0, r1
    bl ClearAll__13MapPatchFlags
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_0ACC: .word 0x000034D8
.LscriptCall_0AD0:
    adds r7, r5, #0
    adds r7, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r6, r5, r2
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0AEC
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0AEC:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0AFE
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_0AFE:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_0B10
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_0B10:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0B20
    bl .LscriptCall_5C96
.LscriptCall_0B20:
    bl PanCameraTo__9GameSceneiiUi
    bl .LscriptCall_5C96
.LscriptCall_0B28:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0B38
    bl .LscriptCall_1DAE
.LscriptCall_0B38:
    bl WaitForCameraMovement__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_0B40:
    adds r4, r5, #0
    adds r4, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_0B5C
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_0B5C:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r2, #0
    beq .LscriptCall_0B6E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_0B6E:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r4, [r0]
    cmp r4, #0
    bne .LscriptCall_0B7E
    bl .LscriptCall_5C96
.LscriptCall_0B7E:
    add r0, sp, #0xc
    movs r2, #0
    movs r3, #0
    movs r1, #0x80
    lsls r1, r1, #1
    strh r1, [r0]
    strh r1, [r0, #2]
    strh r3, [r0, #4]
    strb r2, [r0, #6]
    strb r2, [r0, #7]
    strb r2, [r0, #8]
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r7, #0
    add r3, sp, #0xc
    bl PlayBGM__9GameSceneiUiRC20GameSceneBgmSettings
    bl .LscriptCall_5C96
.LscriptCall_0BA4:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0BB4
    bl .LscriptCall_5C96
.LscriptCall_0BB4:
    bl StopBGM__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_0BBC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_0BD8
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_0BD8:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_0BEA
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_0BEA:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0BFA
    bl .LscriptCall_5C96
.LscriptCall_0BFA:
    bl PlaySong__9GameSceneiUi
    bl .LscriptCall_5C96
.LscriptCall_0C02:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0C12
    bl .LscriptCall_5C96
.LscriptCall_0C12:
    bl StopAllSongs__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_0C1A:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0C2A
    bl .LscriptCall_5C96
.LscriptCall_0C2A:
    bl TalkResetUi__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_0C32:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0C42
    bl .LscriptCall_1DAE
.LscriptCall_0C42:
    bl TalkOpen__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_0C4A:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0C5A
    bl .LscriptCall_1DAE
.LscriptCall_0C5A:
    bl TalkClose__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_0C62:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_0C78
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0C78:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0C88
    bl .LscriptCall_1DAE
.LscriptCall_0C88:
    adds r2, r0, #0
    ldr r0, [r5, #0x10]
    cmp r3, r0
    bhi .LscriptCall_0C9E
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_0CA0
.LscriptCall_0C9E:
    ldr r1, .LscriptCall_0CAC @ =gText_ScriptEngineUi_Error
.LscriptCall_0CA0:
    adds r0, r2, #0
    movs r2, #0x40
    bl TalkMessage__9GameScenePCcUi
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_0CAC: .word gText_ScriptEngineUi_Error
.LscriptCall_0CB0:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_0CC6
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0CC6:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0CD6
    bl .LscriptCall_1DAE
.LscriptCall_0CD6:
    adds r2, r0, #0
    ldr r0, [r5, #0x10]
    cmp r3, r0
    bhi .LscriptCall_0CEC
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_0CEE
.LscriptCall_0CEC:
    ldr r1, .LscriptCall_0CFC @ =gText_ScriptEngineUi_Error
.LscriptCall_0CEE:
    adds r0, r2, #0
    movs r2, #0
    bl TalkMessage__9GameScenePCcUi
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_0CFC: .word gText_ScriptEngineUi_Error
.LscriptCall_0D00:
    movs r3, #0xda
    lsls r3, r3, #1
    adds r2, r5, r3
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_0D16
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0D16:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0D26
    bl .LscriptCall_1DAE
.LscriptCall_0D26:
    adds r4, r0, #0
    ldr r0, [r5, #0x10]
    cmp r3, r0
    bhi .LscriptCall_0D3C
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_0D3E
.LscriptCall_0D3C:
    ldr r1, .LscriptCall_0D4C @ =gText_ScriptEngineUi_Error
.LscriptCall_0D3E:
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r4, #0
    bl TalkMessage__9GameScenePCcUi
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_0D4C: .word gText_ScriptEngineUi_Error
.LscriptCall_0D50:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_0D66
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_0D66:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0D76
    bl .LscriptCall_5C96
.LscriptCall_0D76:
    bl TalkSetNameplateCharacter__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_0D7E:
    movs r3, #0xda
    lsls r3, r3, #1
    adds r2, r5, r3
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_0D94
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0D94:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0DA4
    bl .LscriptCall_5C96
.LscriptCall_0DA4:
    adds r2, r0, #0
    ldr r0, [r5, #0x10]
    cmp r3, r0
    bhi .LscriptCall_0DBA
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_0DBC
.LscriptCall_0DBA:
    ldr r1, .LscriptCall_0DC8 @ =gText_ScriptEngineUi_Error
.LscriptCall_0DBC:
    adds r0, r2, #0
    bl TalkSetNameplateText__9GameScenePCc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_0DC8: .word gText_ScriptEngineUi_Error
.LscriptCall_0DCC:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0DDC
    bl .LscriptCall_5C96
.LscriptCall_0DDC:
    bl TalkClearNameplate__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_0DE4:
    adds r3, r5, #0
    adds r3, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_0E02
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0E02:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_0E14
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0E14:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0E26
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0E26:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0E36
    bl .LscriptCall_1DAE
.LscriptCall_0E36:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_0E4A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r6, r1, r0
    b .LscriptCall_0E4C
.LscriptCall_0E4A:
    ldr r6, .LscriptCall_0E60 @ =gText_ScriptEngineUi_Error
.LscriptCall_0E4C:
    cmp r7, r4
    bhi .LscriptCall_0E64
    ldr r1, [r5, #0x14]
    lsls r0, r7, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_0E66
    .align 2, 0
.LscriptCall_0E60: .word gText_ScriptEngineUi_Error
.LscriptCall_0E64:
    ldr r2, .LscriptCall_0E7C @ =gText_ScriptEngineUi_Error
.LscriptCall_0E66:
    cmp r8, r4
    bhi .LscriptCall_0E80
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_0E82
    .align 2, 0
.LscriptCall_0E7C: .word gText_ScriptEngineUi_Error
.LscriptCall_0E80:
    ldr r3, .LscriptCall_0E9C @ =gText_ScriptEngineUi_Error
.LscriptCall_0E82:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r1, #0
    str r1, [sp]
    str r1, [sp, #4]
    adds r1, r6, #0
    bl TalkPromptChoices__9GameScenePCcN41
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_0E9C: .word gText_ScriptEngineUi_Error
.LscriptCall_0EA0:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_0EBE
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0EBE:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_0ED2
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0ED2:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_0EE4
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0EE4:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0EF6
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0EF6:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_0F06
    bl .LscriptCall_1DAE
.LscriptCall_0F06:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_0F1A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r7, r1, r0
    b .LscriptCall_0F1C
.LscriptCall_0F1A:
    ldr r7, .LscriptCall_0F30 @ =gText_ScriptEngineUi_Error
.LscriptCall_0F1C:
    cmp r6, r4
    bhi .LscriptCall_0F34
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_0F36
    .align 2, 0
.LscriptCall_0F30: .word gText_ScriptEngineUi_Error
.LscriptCall_0F34:
    ldr r2, .LscriptCall_0F4C @ =gText_ScriptEngineUi_Error
.LscriptCall_0F36:
    cmp r8, r4
    bhi .LscriptCall_0F50
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_0F52
    .align 2, 0
.LscriptCall_0F4C: .word gText_ScriptEngineUi_Error
.LscriptCall_0F50:
    ldr r3, .LscriptCall_0F68 @ =gText_ScriptEngineUi_Error
.LscriptCall_0F52:
    cmp sb, r4
    bhi .LscriptCall_0F6C
    ldr r1, [r5, #0x14]
    mov r4, sb
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_0F6E
    .align 2, 0
.LscriptCall_0F68: .word gText_ScriptEngineUi_Error
.LscriptCall_0F6C:
    ldr r1, .LscriptCall_0F88 @ =gText_ScriptEngineUi_Error
.LscriptCall_0F6E:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    str r1, [sp]
    movs r1, #0
    str r1, [sp, #4]
    adds r1, r7, #0
    bl TalkPromptChoices__9GameScenePCcN41
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_0F88: .word gText_ScriptEngineUi_Error
.LscriptCall_0F8C:
    adds r3, r5, #0
    adds r3, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sl, r0
    cmp r1, #0
    beq .LscriptCall_0FAA
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0FAA:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_0FBE
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0FBE:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_0FD2
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0FD2:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_0FE4
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0FE4:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_0FF6
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_0FF6:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1006
    bl .LscriptCall_1DAE
.LscriptCall_1006:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_101A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r7, r1, r0
    b .LscriptCall_101C
.LscriptCall_101A:
    ldr r7, .LscriptCall_1030 @ =gText_ScriptEngineUi_Error
.LscriptCall_101C:
    cmp r6, r4
    bhi .LscriptCall_1034
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_1036
    .align 2, 0
.LscriptCall_1030: .word gText_ScriptEngineUi_Error
.LscriptCall_1034:
    ldr r2, .LscriptCall_104C @ =gText_ScriptEngineUi_Error
.LscriptCall_1036:
    cmp r8, r4
    bhi .LscriptCall_1050
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_1052
    .align 2, 0
.LscriptCall_104C: .word gText_ScriptEngineUi_Error
.LscriptCall_1050:
    ldr r3, .LscriptCall_1068 @ =gText_ScriptEngineUi_Error
.LscriptCall_1052:
    cmp sb, r4
    bhi .LscriptCall_106C
    ldr r1, [r5, #0x14]
    mov r6, sb
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r6, r1, r0
    b .LscriptCall_106E
    .align 2, 0
.LscriptCall_1068: .word gText_ScriptEngineUi_Error
.LscriptCall_106C:
    ldr r6, .LscriptCall_1084 @ =gText_ScriptEngineUi_Error
.LscriptCall_106E:
    cmp sl, r4
    bhi .LscriptCall_1088
    ldr r1, [r5, #0x14]
    mov r4, sl
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_108A
    .align 2, 0
.LscriptCall_1084: .word gText_ScriptEngineUi_Error
.LscriptCall_1088:
    ldr r1, .LscriptCall_10A0 @ =gText_ScriptEngineUi_Error
.LscriptCall_108A:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    str r6, [sp]
    str r1, [sp, #4]
    adds r1, r7, #0
    bl TalkPromptChoices__9GameScenePCcN41
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_10A0: .word gText_ScriptEngineUi_Error
.LscriptCall_10A4:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_10C0
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_10C0:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_10D2
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_10D2:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_10E2
    bl .LscriptCall_1DAE
.LscriptCall_10E2:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_10F6
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_10F8
.LscriptCall_10F6:
    ldr r3, .LscriptCall_110C @ =gText_ScriptEngineUi_Error
.LscriptCall_10F8:
    cmp r6, r4
    bhi .LscriptCall_1110
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_1112
    .align 2, 0
.LscriptCall_110C: .word gText_ScriptEngineUi_Error
.LscriptCall_1110:
    ldr r2, .LscriptCall_1130 @ =gText_ScriptEngineUi_Error
.LscriptCall_1112:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r1, #0
    str r1, [sp]
    str r1, [sp, #4]
    str r1, [sp, #8]
    adds r1, r3, #0
    movs r3, #0
    bl TalkChoices__9GameScenePCcN51
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_1130: .word gText_ScriptEngineUi_Error
.LscriptCall_1134:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_1152
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1152:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_1164
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1164:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_1176
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1176:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1186
    bl .LscriptCall_1DAE
.LscriptCall_1186:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_119A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r6, r1, r0
    b .LscriptCall_119C
.LscriptCall_119A:
    ldr r6, .LscriptCall_11B0 @ =gText_ScriptEngineUi_Error
.LscriptCall_119C:
    cmp r7, r4
    bhi .LscriptCall_11B4
    ldr r1, [r5, #0x14]
    lsls r0, r7, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_11B6
    .align 2, 0
.LscriptCall_11B0: .word gText_ScriptEngineUi_Error
.LscriptCall_11B4:
    ldr r2, .LscriptCall_11CC @ =gText_ScriptEngineUi_Error
.LscriptCall_11B6:
    cmp r8, r4
    bhi .LscriptCall_11D0
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_11D2
    .align 2, 0
.LscriptCall_11CC: .word gText_ScriptEngineUi_Error
.LscriptCall_11D0:
    ldr r3, .LscriptCall_11EC @ =gText_ScriptEngineUi_Error
.LscriptCall_11D2:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r1, #0
    str r1, [sp]
    str r1, [sp, #4]
    str r1, [sp, #8]
    adds r1, r6, #0
    bl TalkChoices__9GameScenePCcN51
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_11EC: .word gText_ScriptEngineUi_Error
.LscriptCall_11F0:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_120E
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_120E:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_1222
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1222:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_1234
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1234:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_1246
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1246:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1256
    bl .LscriptCall_1DAE
.LscriptCall_1256:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_126A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r7, r1, r0
    b .LscriptCall_126C
.LscriptCall_126A:
    ldr r7, .LscriptCall_1280 @ =gText_ScriptEngineUi_Error
.LscriptCall_126C:
    cmp r6, r4
    bhi .LscriptCall_1284
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_1286
    .align 2, 0
.LscriptCall_1280: .word gText_ScriptEngineUi_Error
.LscriptCall_1284:
    ldr r2, .LscriptCall_129C @ =gText_ScriptEngineUi_Error
.LscriptCall_1286:
    cmp r8, r4
    bhi .LscriptCall_12A0
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_12A2
    .align 2, 0
.LscriptCall_129C: .word gText_ScriptEngineUi_Error
.LscriptCall_12A0:
    ldr r3, .LscriptCall_12B8 @ =gText_ScriptEngineUi_Error
.LscriptCall_12A2:
    cmp sb, r4
    bhi .LscriptCall_12BC
    ldr r1, [r5, #0x14]
    mov r4, sb
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_12BE
    .align 2, 0
.LscriptCall_12B8: .word gText_ScriptEngineUi_Error
.LscriptCall_12BC:
    ldr r1, .LscriptCall_12D8 @ =gText_ScriptEngineUi_Error
.LscriptCall_12BE:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    str r1, [sp]
    movs r1, #0
    str r1, [sp, #4]
    str r1, [sp, #8]
    adds r1, r7, #0
    bl TalkChoices__9GameScenePCcN51
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_12D8: .word gText_ScriptEngineUi_Error
.LscriptCall_12DC:
    adds r3, r5, #0
    adds r3, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sl, r0
    cmp r1, #0
    beq .LscriptCall_12FA
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_12FA:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_130E
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_130E:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_1322
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1322:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_1334
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1334:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_1346
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1346:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1356
    bl .LscriptCall_1DAE
.LscriptCall_1356:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_136A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r7, r1, r0
    b .LscriptCall_136C
.LscriptCall_136A:
    ldr r7, .LscriptCall_1380 @ =gText_ScriptEngineUi_Error
.LscriptCall_136C:
    cmp r6, r4
    bhi .LscriptCall_1384
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_1386
    .align 2, 0
.LscriptCall_1380: .word gText_ScriptEngineUi_Error
.LscriptCall_1384:
    ldr r2, .LscriptCall_139C @ =gText_ScriptEngineUi_Error
.LscriptCall_1386:
    cmp r8, r4
    bhi .LscriptCall_13A0
    ldr r1, [r5, #0x14]
    mov r3, r8
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_13A2
    .align 2, 0
.LscriptCall_139C: .word gText_ScriptEngineUi_Error
.LscriptCall_13A0:
    ldr r3, .LscriptCall_13B8 @ =gText_ScriptEngineUi_Error
.LscriptCall_13A2:
    cmp sb, r4
    bhi .LscriptCall_13BC
    ldr r1, [r5, #0x14]
    mov r6, sb
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r6, r1, r0
    b .LscriptCall_13BE
    .align 2, 0
.LscriptCall_13B8: .word gText_ScriptEngineUi_Error
.LscriptCall_13BC:
    ldr r6, .LscriptCall_13D4 @ =gText_ScriptEngineUi_Error
.LscriptCall_13BE:
    cmp sl, r4
    bhi .LscriptCall_13D8
    ldr r1, [r5, #0x14]
    mov r4, sl
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_13DA
    .align 2, 0
.LscriptCall_13D4: .word gText_ScriptEngineUi_Error
.LscriptCall_13D8:
    ldr r1, .LscriptCall_13F4 @ =gText_ScriptEngineUi_Error
.LscriptCall_13DA:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    str r6, [sp]
    str r1, [sp, #4]
    movs r1, #0
    str r1, [sp, #8]
    adds r1, r7, #0
    bl TalkChoices__9GameScenePCcN51
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_13F4: .word gText_ScriptEngineUi_Error
.LscriptCall_13F8:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov ip, r0
    cmp r1, #0
    beq .LscriptCall_1416
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1416:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sl, r0
    cmp r1, #0
    beq .LscriptCall_142A
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_142A:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_143E
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_143E:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_1450
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1450:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_1462
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1462:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_1474
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_1474:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1484
    bl .LscriptCall_1DAE
.LscriptCall_1484:
    ldr r4, [r5, #0x10]
    cmp r3, r4
    bhi .LscriptCall_149A
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    mov r8, r1
    b .LscriptCall_149E
.LscriptCall_149A:
    ldr r2, .LscriptCall_14B0 @ =gText_ScriptEngineUi_Error
    mov r8, r2
.LscriptCall_149E:
    cmp r6, r4
    bhi .LscriptCall_14B4
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_14B6
    .align 2, 0
.LscriptCall_14B0: .word gText_ScriptEngineUi_Error
.LscriptCall_14B4:
    ldr r2, .LscriptCall_14C8 @ =gText_ScriptEngineUi_Error
.LscriptCall_14B6:
    cmp r7, r4
    bhi .LscriptCall_14CC
    ldr r1, [r5, #0x14]
    lsls r0, r7, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r3, r1, r0
    b .LscriptCall_14CE
    .align 2, 0
.LscriptCall_14C8: .word gText_ScriptEngineUi_Error
.LscriptCall_14CC:
    ldr r3, .LscriptCall_14E4 @ =gText_ScriptEngineUi_Error
.LscriptCall_14CE:
    cmp sb, r4
    bhi .LscriptCall_14E8
    ldr r1, [r5, #0x14]
    mov r6, sb
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r7, r1, r0
    b .LscriptCall_14EA
    .align 2, 0
.LscriptCall_14E4: .word gText_ScriptEngineUi_Error
.LscriptCall_14E8:
    ldr r7, .LscriptCall_1500 @ =gText_ScriptEngineUi_Error
.LscriptCall_14EA:
    cmp sl, r4
    bhi .LscriptCall_1504
    ldr r1, [r5, #0x14]
    mov r6, sl
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r6, r1, r0
    b .LscriptCall_1506
    .align 2, 0
.LscriptCall_1500: .word gText_ScriptEngineUi_Error
.LscriptCall_1504:
    ldr r6, .LscriptCall_151C @ =gText_ScriptEngineUi_Error
.LscriptCall_1506:
    cmp ip, r4
    bhi .LscriptCall_1520
    ldr r1, [r5, #0x14]
    mov r4, ip
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_1522
    .align 2, 0
.LscriptCall_151C: .word gText_ScriptEngineUi_Error
.LscriptCall_1520:
    ldr r1, .LscriptCall_153C @ =gText_ScriptEngineUi_Error
.LscriptCall_1522:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    str r7, [sp]
    str r6, [sp, #4]
    str r1, [sp, #8]
    mov r1, r8
    bl TalkChoices__9GameScenePCcN51
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_153C: .word gText_ScriptEngineUi_Error
.LscriptCall_1540:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_1556
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1556:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1566
    bl .LscriptCall_5C96
.LscriptCall_1566:
    bl TalkSetPortrait__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_156E:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_157E
    bl .LscriptCall_5C96
.LscriptCall_157E:
    bl TalkClearPortrait__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_1586:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_159C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_159C:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_15AC
    bl .LscriptCall_5C96
.LscriptCall_15AC:
    bl TalkShowHeartIndicator__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_15B4:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_15C4
    bl .LscriptCall_5C96
.LscriptCall_15C4:
    bl TalkHideHeartIndicator__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_15CC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_15E8
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_15E8:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r3, #0
    beq .LscriptCall_15FA
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_15FA:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_1608
    b .LscriptCall_1DAE
.LscriptCall_1608:
    mov r3, sp
    movs r0, #1
    strb r0, [r3]
    adds r0, r1, #0
    adds r1, r6, #0
    movs r3, #1
    bl FadeScreen__9GameSceneUiibT3
    b .LscriptCall_1DAE
.LscriptCall_161A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_1636
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_1636:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r3, #0
    beq .LscriptCall_1648
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_1648:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_1656
    b .LscriptCall_1DAE
.LscriptCall_1656:
    mov r3, sp
    movs r0, #1
    strb r0, [r3]
    adds r0, r1, #0
    adds r1, r6, #0
    movs r3, #0
    bl FadeScreen__9GameSceneUiibT3
    b .LscriptCall_1DAE
.LscriptCall_1668:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_1684
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_1684:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r3, #0
    beq .LscriptCall_1696
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_1696:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_16A4
    b .LscriptCall_1DAE
.LscriptCall_16A4:
    mov r3, sp
    movs r0, #0
    strb r0, [r3]
    adds r0, r1, #0
    adds r1, r6, #0
    movs r3, #0
    bl FadeScreen__9GameSceneUiibT3
    b .LscriptCall_1DAE
.LscriptCall_16B6:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_16CC
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_16CC:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_16DA
    b .LscriptCall_1DAE
.LscriptCall_16DA:
    bl WaitFrames__9GameScenei
    b .LscriptCall_1DAE
.LscriptCall_16E0:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_16F6
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_16F6:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1706
    bl .LscriptCall_5C96
.LscriptCall_1706:
    movs r2, #0
    bl CallScript__9GameSceneii
    bl .LscriptCall_5C96
.LscriptCall_1710:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_172C
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_172C:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_173E
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_173E:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_174E
    bl .LscriptCall_5C96
.LscriptCall_174E:
    bl TextVariableSetNumber__9GameSceneUii
    bl .LscriptCall_5C96
.LscriptCall_1756:
    adds r7, r5, #0
    adds r7, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_1772
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_1772:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_1784
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_1784:
    ldr r4, [r6]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r7, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_1796
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_1796:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_17A6
    bl .LscriptCall_5C96
.LscriptCall_17A6:
    bl TextVariableSetNumberFieldWidth__9GameSceneUiiUi
    bl .LscriptCall_5C96
.LscriptCall_17AE:
    adds r4, r5, #0
    adds r4, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_17CA
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_17CA:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r4, [r0]
    cmp r2, #0
    beq .LscriptCall_17DC
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_17DC:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_17EC
    bl .LscriptCall_5C96
.LscriptCall_17EC:
    adds r3, r0, #0
    ldr r0, [r5, #0x10]
    cmp r6, r0
    bhi .LscriptCall_1802
    ldr r1, [r5, #0x14]
    lsls r0, r6, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r2, r1, r0
    b .LscriptCall_1804
.LscriptCall_1802:
    ldr r2, .LscriptCall_1810 @ =gText_ScriptEngineUi_Error
.LscriptCall_1804:
    adds r0, r3, #0
    adds r1, r4, #0
    bl TextVariableSetString__9GameSceneUiPCc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_1810: .word gText_ScriptEngineUi_Error
.LscriptCall_1814:
    bl rand
    adds r4, r0, #0
    ldr r0, .LscriptCall_182C @ =0x00007FFF
    ands r4, r0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_182C: .word 0x00007FFF
.LscriptCall_1830:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_184C
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_184C:
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r5, [r0]
    cmp r1, #0
    beq .LscriptCall_185E
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_185E:
    cmp r5, r7
    bgt .LscriptCall_1874
    bl rand
    subs r1, r7, r5
    adds r1, #1
    bl __modsi3
    adds r2, r0, r5
    bl .LscriptCall_588A
.LscriptCall_1874:
    ldr r2, [r4]
    cmp r2, #0x63
    bls .LscriptCall_187E
    bl .LscriptCall_5C96
.LscriptCall_187E:
    lsls r0, r2, #2
    adds r0, r6, r0
    movs r1, #0
    bl .LscriptCall_541A
.LscriptCall_1888:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_18A4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_18A4:
    adds r0, r5, #0
    bl VarGet__12ScriptEngineUi
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_18B0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_18CC
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_18CC:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_18DE
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_18DE:
    adds r0, r5, #0
    bl VarSet__12ScriptEngineUii
    bl .LscriptCall_5C96
.LscriptCall_18E8:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r4, [r1]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r2, r0
    ldr r3, [r0]
    adds r6, r1, #0
    mov r8, r2
    cmp r4, #0
    beq .LscriptCall_1908
    subs r0, r4, #1
    str r0, [r6]
.LscriptCall_1908:
    cmp r3, #1
    beq .LscriptCall_1934
    cmp r3, #1
    bgt .LscriptCall_1916
    cmp r3, #0
    beq .LscriptCall_1920
    b .LscriptCall_1970
.LscriptCall_1916:
    cmp r3, #2
    beq .LscriptCall_1948
    cmp r3, #3
    beq .LscriptCall_195C
    b .LscriptCall_1970
.LscriptCall_1920:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_192A
    bl .LscriptCall_5C96
.LscriptCall_192A:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #1
    bl .LscriptCall_3E32
.LscriptCall_1934:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_193E
    bl .LscriptCall_5C96
.LscriptCall_193E:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #0
    bl .LscriptCall_3E32
.LscriptCall_1948:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_1952
    bl .LscriptCall_5C96
.LscriptCall_1952:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #3
    bl .LscriptCall_3E32
.LscriptCall_195C:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_1966
    bl .LscriptCall_5C96
.LscriptCall_1966:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #2
    bl .LscriptCall_3E32
.LscriptCall_1970:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_197A
    bl .LscriptCall_5C96
.LscriptCall_197A:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #1
    bl .LscriptCall_3E32
.LscriptCall_1984:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_19A0
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_19A0:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_19B0
    bl .LscriptCall_501E
.LscriptCall_19B0:
    adds r0, r1, #0
    adds r1, r3, #0
    bl GetEntityMap__9GameSceneUi
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_19BE:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_19D8 @ =0x00001C2C
    adds r0, r0, r3
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    bl .LscriptCall_5BCC
    .align 2, 0
.LscriptCall_19D8: .word 0x00001C2C
.LscriptCall_19DC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_1A34 @ =0x00001C2C
    adds r4, r0, r2
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1A38
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    adds r6, r0, #0
    cmp r6, #1
    bne .LscriptCall_1A38
    adds r0, r4, #0
    bl GetArticle__C8HeldItem
    adds r1, r0, #0
    add r0, sp, #0x18
    strb r1, [r0]
    bl CanBeDiscarded__C7Article
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_1A38
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r3, [r1]
    cmp r3, #0x63
    bls .LscriptCall_1A2A
    bl .LscriptCall_5C96
.LscriptCall_1A2A:
    lsls r0, r3, #2
    adds r0, r2, r0
    str r6, [r0]
    bl .LscriptCall_5BE2
    .align 2, 0
.LscriptCall_1A34: .word 0x00001C2C
.LscriptCall_1A38:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1A4C
    bl .LscriptCall_5C96
.LscriptCall_1A4C:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1A56:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1A84 @ =0x00001C2C
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1A88
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_1A84: .word 0x00001C2C
.LscriptCall_1A88:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1A9C
    bl .LscriptCall_5C96
.LscriptCall_1A9C:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #1
    rsbs r1, r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1AA8:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1AD8 @ =0x00001C2C
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1ADC
    adds r0, r4, #0
    bl func_0800F388
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_1AD8: .word 0x00001C2C
.LscriptCall_1ADC:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1AF0
    bl .LscriptCall_5C96
.LscriptCall_1AF0:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1AFA:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1B3C @ =0x00001C2C
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1B40
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #0
    bne .LscriptCall_1B40
    add r0, sp, #0xc
    adds r1, r4, #0
    bl func_0800F20C
    add r0, sp, #0xc
    bl GetId__C4Food
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_1B3C: .word 0x00001C2C
.LscriptCall_1B40:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1B54
    bl .LscriptCall_5C96
.LscriptCall_1B54:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #1
    rsbs r1, r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1B60:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1BA4 @ =0x00001C2C
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1BA8
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #1
    bne .LscriptCall_1BA8
    adds r0, r4, #0
    bl GetArticle__C8HeldItem
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x19
    strb r1, [r0]
    bl GetId__C7Article
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_1BA4: .word 0x00001C2C
.LscriptCall_1BA8:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1BBC
    bl .LscriptCall_5C96
.LscriptCall_1BBC:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #1
    rsbs r1, r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1BC8:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1C00 @ =0x00001C2C
    adds r4, r0, r1
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1C04
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #3
    bne .LscriptCall_1C04
    adds r0, r4, #0
    bl GetHeldChickenSlot
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_1C00: .word 0x00001C2C
.LscriptCall_1C04:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_1C18
    bl .LscriptCall_5C96
.LscriptCall_1C18:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #1
    rsbs r1, r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_1C24:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1C32
    b .LscriptCall_1DAE
.LscriptCall_1C32:
    bl UsePlayerHeldItem__9GameScene
    b .LscriptCall_1DAE
.LscriptCall_1C38:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_1C48
    bl .LscriptCall_5C96
.LscriptCall_1C48:
    bl ClearPlayerHeldItem__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_1C50:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r3, r5, r2
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_1C66
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1C66:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r5, [r0]
    cmp r5, #0
    bne .LscriptCall_1C74
    b .LscriptCall_1DAE
.LscriptCall_1C74:
    add r4, sp, #0x10
    adds r0, r4, #0
    bl __4FoodUi
    ldrb r1, [r4]
    mov r0, sp
    adds r0, #0x11
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r0, r1
    mov r1, sp
    adds r1, #0x12
    ldrb r1, [r1]
    lsls r1, r1, #0x10
    orrs r1, r0
    add r0, sp, #0xc
    bl __12RucksackItemG4Food
    adds r0, r5, #0
    add r1, sp, #0xc
    movs r2, #0
    bl SetPlayerHeldItem__9GameSceneRC12RucksackItemb
    b .LscriptCall_1DAE
.LscriptCall_1CA4:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_1CBA
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1CBA:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r5, [r0]
    cmp r5, #0
    beq .LscriptCall_1DAE
    mov r4, sp
    adds r4, #0x1a
    adds r0, r4, #0
    bl __7ArticleUi
    ldrb r1, [r4]
    add r0, sp, #0xc
    bl __12RucksackItemG7Article
    adds r0, r5, #0
    add r1, sp, #0xc
    movs r2, #0
    bl SetPlayerHeldItem__9GameSceneRC12RucksackItemb
    b .LscriptCall_1DAE
.LscriptCall_1CE4:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_1CFA
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1CFA:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r5, [r0]
    cmp r5, #0
    beq .LscriptCall_1DAE
    add r4, sp, #0x10
    adds r0, r4, #0
    bl __4FoodUi
    ldrb r1, [r4]
    mov r0, sp
    adds r0, #0x11
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r0, r1
    mov r1, sp
    adds r1, #0x12
    ldrb r1, [r1]
    lsls r1, r1, #0x10
    orrs r1, r0
    add r0, sp, #0xc
    bl __12RucksackItemG4Food
    adds r0, r5, #0
    add r1, sp, #0xc
    movs r2, #1
    bl SetPlayerHeldItem__9GameSceneRC12RucksackItemb
    b .LscriptCall_1DAE
.LscriptCall_1D36:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_1D4C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1D4C:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r5, [r0]
    cmp r5, #0
    beq .LscriptCall_1DAE
    mov r4, sp
    adds r4, #0x1b
    adds r0, r4, #0
    bl __7ArticleUi
    ldrb r1, [r4]
    add r0, sp, #0xc
    bl __12RucksackItemG7Article
    adds r0, r5, #0
    add r1, sp, #0xc
    movs r2, #1
    bl SetPlayerHeldItem__9GameSceneRC12RucksackItemb
    b .LscriptCall_1DAE
.LscriptCall_1D76:
    movs r4, #0
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_1D8C
    bl TryShipPlayerHeldItem__9GameScene
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
.LscriptCall_1D8C:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r3, [r1]
    cmp r3, #0x63
    bhi .LscriptCall_1DA6
    lsls r0, r3, #2
    adds r0, r2, r0
    str r4, [r0]
    adds r0, r3, #1
    str r0, [r1]
.LscriptCall_1DA6:
    cmp r4, #0
    bne .LscriptCall_1DAE
    bl .LscriptCall_5C96
.LscriptCall_1DAE:
    movs r0, #1
    bl .LscriptCall_5C98
.LscriptCall_1DB4:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_1DAE
    bl ThrowPlayerHeldItem__9GameScene
    b .LscriptCall_1DAE
.LscriptCall_1DC6:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_1E14 @ =0x00001C34
    adds r4, r0, r1
    movs r6, #1
    rsbs r6, r6, #0
    adds r0, r4, #0
    bl IsEmpty__C9ToolStack
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1DF4
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    add r0, sp, #0x1c
    strb r1, [r0]
    bl GetId__C4Tool
    adds r6, r0, #0
.LscriptCall_1DF4:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r3, [r1]
    cmp r3, #0x63
    bls .LscriptCall_1E08
    bl .LscriptCall_5C96
.LscriptCall_1E08:
    lsls r0, r3, #2
    adds r0, r2, r0
    str r6, [r0]
    bl .LscriptCall_5BE2
    .align 2, 0
.LscriptCall_1E14: .word 0x00001C34
.LscriptCall_1E18:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_1E5C @ =0x00001C34
    adds r4, r0, r6
    movs r6, #1
    rsbs r6, r6, #0
    adds r0, r4, #0
    bl IsEmpty__C9ToolStack
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_1E3C
    adds r0, r4, #0
    bl GetAmount__C9ToolStack
    adds r6, r0, #0
.LscriptCall_1E3C:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    ldr r3, [r1]
    cmp r3, #0x63
    bls .LscriptCall_1E50
    bl .LscriptCall_5C96
.LscriptCall_1E50:
    lsls r0, r3, #2
    adds r0, r2, r0
    str r6, [r0]
    bl .LscriptCall_5BE2
    .align 2, 0
.LscriptCall_1E5C: .word 0x00001C34
.LscriptCall_1E60:
    adds r4, r5, #0
    adds r4, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r3, r5, r1
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_1E7C
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_1E7C:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_1E8E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_1E8E:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r5, [r0]
    ldr r3, .LscriptCall_1EB4 @ =0x00001C34
    adds r5, r5, r3
    mov r4, sp
    adds r4, #0x1d
    adds r0, r4, #0
    bl __4ToolUi
    ldrb r1, [r4]
    add r0, sp, #0xc
    adds r2, r6, #0
    bl __9ToolStackG4ToolUi
    adds r0, r5, #0
    b .LscriptCall_1F98
    .align 2, 0
.LscriptCall_1EB4: .word 0x00001C34
.LscriptCall_1EB8:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_1EC8 @ =0x00001BD8
    adds r7, r0, r6
    movs r6, #0
    b .LscriptCall_1F54
    .align 2, 0
.LscriptCall_1EC8: .word 0x00001BD8
.LscriptCall_1ECC:
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x1e
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #5
    beq .LscriptCall_1F52
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x1f
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #0xd
    beq .LscriptCall_1F52
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    add r0, sp, #0x20
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #0x15
    beq .LscriptCall_1F52
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x21
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #0x1d
    beq .LscriptCall_1F52
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x22
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #0x25
    beq .LscriptCall_1F52
    adds r0, r4, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x23
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, #0x2d
    beq .LscriptCall_1F52
    bl .LscriptCall_5C96
.LscriptCall_1F52:
    adds r6, #1
.LscriptCall_1F54:
    cmp r6, #9
    bls .LscriptCall_1F5C
    bl .LscriptCall_5C96
.LscriptCall_1F5C:
    adds r0, r7, #0
    bl func_0800EC4C
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_1F80 @ =0x00001C34
    adds r4, r0, r2
    adds r0, r4, #0
    bl IsEmpty__C9ToolStack
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_1ECC
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_1F80: .word 0x00001C34
.LscriptCall_1F84:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r4, [r0]
    ldr r6, .LscriptCall_1FA4 @ =0x00001C34
    adds r4, r4, r6
    add r0, sp, #0xc
    bl __9ToolStack
    adds r0, r4, #0
.LscriptCall_1F98:
    add r1, sp, #0xc
    movs r2, #2
    bl memcpy
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_1FA4: .word 0x00001C34
.LscriptCall_1FA8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_1FC4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_1FC4:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_1FDC @ =0x00001C38
    adds r0, r0, r3
    bl GetFirstSlotWithFood__C8RucksackUi
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_1FDC: .word 0x00001C38
.LscriptCall_1FE0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_1FFC
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_1FFC:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2014 @ =0x00001C38
    adds r0, r0, r3
    bl GetFirstSlotWithArticle__C8RucksackUi
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2014: .word 0x00001C38
.LscriptCall_2018:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_202E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_202E:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_2050 @ =0x00001C38
    adds r0, r0, r2
    bl GetItemAt__8RucksackUi
    adds r4, r0, #0
    add r0, sp, #0xc
    bl __12RucksackItem
    ldr r0, [sp, #0xc]
    str r0, [r4]
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2050: .word 0x00001C38
.LscriptCall_2054:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_2068 @ =0x00001C38
    adds r0, r0, r4
    bl GetFirstFreeToolSlot__C8Rucksack
    bl .LscriptCall_5BCA
    .align 2, 0
.LscriptCall_2068: .word 0x00001C38
.LscriptCall_206C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_208C @ =0x00001C38
    adds r0, r0, r2
    bl GetFirstFreeItemSlot__C8Rucksack
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_208C: .word 0x00001C38
.LscriptCall_2090:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_20AC
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_20AC:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_20BE
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_20BE:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r3, .LscriptCall_20D4 @ =0x00001C38
    adds r0, r0, r3
    bl AddAmountOfArticle__8RucksackUiUi
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_20D4: .word 0x00001C38
.LscriptCall_20D8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_20F4
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_20F4:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_2106
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_2106:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r3, .LscriptCall_211C @ =0x00001C38
    adds r0, r0, r3
    bl AddAmountOfFood__8RucksackUiUi
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_211C: .word 0x00001C38
.LscriptCall_2120:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_213C
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_213C:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_214E
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_214E:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r3, .LscriptCall_2164 @ =0x00001C38
    adds r0, r0, r3
    bl AddAmountOfTool__8RucksackUiUi
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2164: .word 0x00001C38
.LscriptCall_2168:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_2184
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2184:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    adds r2, r3, #0
    cmp r3, #0
    bge .LscriptCall_2194
    adds r2, r3, #7
.LscriptCall_2194:
    asrs r2, r2, #3
    lsls r1, r2, #3
    subs r1, r3, r1
    ldr r3, .LscriptCall_21AC @ =0x000021DC
    adds r0, r0, r3
    adds r0, r0, r2
    ldrb r2, [r0]
    asrs r2, r1
    movs r0, #1
    ands r2, r0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_21AC: .word 0x000021DC
.LscriptCall_21B0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_21CC
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_21CC:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    adds r2, r3, #0
    cmp r3, #0
    bge .LscriptCall_21DC
    adds r2, r3, #7
.LscriptCall_21DC:
    asrs r2, r2, #3
    lsls r1, r2, #3
    subs r1, r3, r1
    ldr r3, .LscriptCall_21F4 @ =0x000021D4
    adds r0, r0, r3
    adds r0, r0, r2
    ldrb r2, [r0]
    asrs r2, r1
    movs r0, #1
    ands r2, r0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_21F4: .word 0x000021D4
.LscriptCall_21F8:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r1, r5, r4
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_220E
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_220E:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r2, [r0]
    adds r0, r3, #0
    cmp r3, #0
    bge .LscriptCall_221E
    adds r0, r3, #7
.LscriptCall_221E:
    asrs r0, r0, #3
    lsls r1, r0, #3
    subs r1, r3, r1
    ldr r3, .LscriptCall_2238 @ =0x000021DC
    adds r2, r2, r3
    adds r2, r2, r0
    movs r0, #1
    lsls r0, r1
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2238: .word 0x000021DC
.LscriptCall_223C:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_2252
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_2252:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r2, [r0]
    adds r1, r3, #0
    cmp r3, #0
    bge .LscriptCall_2262
    adds r1, r3, #7
.LscriptCall_2262:
    asrs r1, r1, #3
    lsls r0, r1, #3
    subs r0, r3, r0
    ldr r3, .LscriptCall_227C @ =0x000021DC
    adds r2, r2, r3
    adds r2, r2, r1
    movs r1, #1
    lsls r1, r0
    ldrb r0, [r2]
    bics r0, r1
    strb r0, [r2]
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_227C: .word 0x000021DC
.LscriptCall_2280:
    movs r4, #0x24
    adds r4, r4, r5
    mov r8, r4
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    ldr r2, [r6]
    lsls r0, r2, #2
    subs r0, #4
    add r0, r8
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_229E
    subs r0, r2, #1
    str r0, [r6]
.LscriptCall_229E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldrb r5, [r0, #0x11]
    ldr r2, .LscriptCall_22E8 @ =0x00001CD4
    adds r4, r0, r2
    ldr r3, .LscriptCall_22EC @ =0x00001BD8
    adds r0, r0, r3
    bl GetBirthday__C6Farmer
    add r2, sp, #0x24
    strb r0, [r2]
    adds r0, r4, #0
    adds r1, r7, #0
    bl func_0809FE74
    movs r3, #0
    movs r1, #0x7f
    adds r2, r1, #0
    ands r2, r5
    ands r1, r0
    cmp r2, r1
    bne .LscriptCall_22D0
    movs r3, #1
.LscriptCall_22D0:
    adds r2, r3, #0
    ldr r1, [r6]
    cmp r1, #0x63
    bls .LscriptCall_22DC
    bl .LscriptCall_5C96
.LscriptCall_22DC:
    lsls r0, r1, #2
    add r0, r8
    str r2, [r0]
    bl .LscriptCall_5150
    .align 2, 0
.LscriptCall_22E8: .word 0x00001CD4
.LscriptCall_22EC: .word 0x00001BD8
.LscriptCall_22F0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_230C
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_230C:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2330 @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2326
    bl .LscriptCall_588A
.LscriptCall_2326:
    bl GetFriendship__C3Npc
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2330: .word 0x00001CD4
.LscriptCall_2334:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r4, [r0]
    cmp r2, #0
    beq .LscriptCall_2350
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2350:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2362
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2362:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_2384 @ =0x00001CD4
    adds r0, r0, r2
    bl GetNpc__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_237A
    bl .LscriptCall_5C96
.LscriptCall_237A:
    adds r1, r4, #0
    bl AddFriendship__3Npci
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2384: .word 0x00001CD4
.LscriptCall_2388:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r4, [r0]
    cmp r2, #0
    beq .LscriptCall_23A4
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_23A4:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_23B6
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_23B6:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_23D8 @ =0x00001CD4
    adds r0, r0, r2
    bl GetNpc__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_23CE
    bl .LscriptCall_5C96
.LscriptCall_23CE:
    adds r1, r4, #0
    bl SetFriendship__3Npci
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_23D8: .word 0x00001CD4
.LscriptCall_23DC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_23F8
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_23F8:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_241C @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2412
    bl .LscriptCall_588A
.LscriptCall_2412:
    bl GetDaysSinceLastSpoken__C3Npc
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_241C: .word 0x00001CD4
.LscriptCall_2420:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2436
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2436:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_2458 @ =0x00001CD4
    adds r0, r0, r2
    bl GetNpc__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_244E
    bl .LscriptCall_5C96
.LscriptCall_244E:
    bl SetSpokenTo__3Npc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2458: .word 0x00001CD4
.LscriptCall_245C:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2478
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2478:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_24A0 @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2492
    bl .LscriptCall_588A
.LscriptCall_2492:
    bl HasBeenSpokenToToday__C3Npc
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_24A0: .word 0x00001CD4
.LscriptCall_24A4:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_24C0
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_24C0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_24E8 @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_24DA
    bl .LscriptCall_588A
.LscriptCall_24DA:
    bl HasBeenSpokenToJustNow__C3Npc
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_24E8: .word 0x00001CD4
.LscriptCall_24EC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2508
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2508:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2530 @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2522
    bl .LscriptCall_588A
.LscriptCall_2522:
    bl HasBeenMet__C3Npc
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2530: .word 0x00001CD4
.LscriptCall_2534:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_254A
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_254A:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_256C @ =0x00001CD4
    adds r0, r0, r2
    bl GetNpc__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_2562
    bl .LscriptCall_5C96
.LscriptCall_2562:
    bl SetGifted__3Npc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_256C: .word 0x00001CD4
.LscriptCall_2570:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_258C
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_258C:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_25B4 @ =0x00001CD4
    adds r0, r0, r3
    bl GetNpc__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_25A6
    bl .LscriptCall_588A
.LscriptCall_25A6:
    bl HasBeenGiftedToday__C3Npc
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_25B4: .word 0x00001CD4
.LscriptCall_25B8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_25D4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_25D4:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_25F8 @ =0x00001CD4
    adds r0, r0, r3
    bl GetBachelorette__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_25EE
    bl .LscriptCall_588A
.LscriptCall_25EE:
    bl GetLove__C12Bachelorette
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_25F8: .word 0x00001CD4
.LscriptCall_25FC:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r4, [r0]
    cmp r2, #0
    beq .LscriptCall_2618
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2618:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_262A
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_262A:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_264C @ =0x00001CD4
    adds r0, r0, r2
    bl GetBachelorette__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_2642
    bl .LscriptCall_5C96
.LscriptCall_2642:
    adds r1, r4, #0
    bl AddLove__12Bachelorettei
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_264C: .word 0x00001CD4
.LscriptCall_2650:
    adds r1, r5, #0
    adds r1, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r4, [r0]
    cmp r2, #0
    beq .LscriptCall_266C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_266C:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r1, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_267E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_267E:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_26A0 @ =0x00001CD4
    adds r0, r0, r2
    bl GetBachelorette__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_2696
    bl .LscriptCall_5C96
.LscriptCall_2696:
    adds r1, r4, #0
    bl SetLove__12Bachelorettei
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_26A0: .word 0x00001CD4
.LscriptCall_26A4:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_26C0
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_26C0:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_26D2
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_26D2:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_26E2
    bl .LscriptCall_5C96
.LscriptCall_26E2:
    bl SetEntityEventScript__9GameSceneUii
    bl .LscriptCall_5C96
.LscriptCall_26EA:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2700
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2700:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2710
    bl .LscriptCall_5C96
.LscriptCall_2710:
    bl ClearEntityEventScript__9GameSceneUi
    bl .LscriptCall_5C96
.LscriptCall_2718:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2728
    bl .LscriptCall_1DAE
.LscriptCall_2728:
    bl OpenSupermarketShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2730:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2746
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2746:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2756
    bl .LscriptCall_1DAE
.LscriptCall_2756:
    bl OpenSupermarketPurchase__9GameScene21MarySupermarketItemId
    bl .LscriptCall_1DAE
.LscriptCall_275E:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_276E
    bl .LscriptCall_1DAE
.LscriptCall_276E:
    bl OpenSpecialMerchantShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2776:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2786
    bl .LscriptCall_1DAE
.LscriptCall_2786:
    bl OpenGiftWrappingMenu__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_278E:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_279E
    bl .LscriptCall_1DAE
.LscriptCall_279E:
    bl OpenWonShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_27A6:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_27B6
    bl .LscriptCall_1DAE
.LscriptCall_27B6:
    bl OpenCarpenterShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_27BE:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_27CE
    bl .LscriptCall_1DAE
.LscriptCall_27CE:
    bl OpenBlacksmithShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_27D6:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_27E6
    bl .LscriptCall_1DAE
.LscriptCall_27E6:
    bl OpenClinicShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_27EE:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_27FE
    bl .LscriptCall_1DAE
.LscriptCall_27FE:
    bl OpenBeachCafeShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2806:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2816
    bl .LscriptCall_1DAE
.LscriptCall_2816:
    bl OpenYodelRanchShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_281E:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_282E
    bl .LscriptCall_1DAE
.LscriptCall_282E:
    bl OpenWineryShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2836:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2846
    bl .LscriptCall_1DAE
.LscriptCall_2846:
    bl OpenInnShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_284E:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_285E
    bl .LscriptCall_1DAE
.LscriptCall_285E:
    bl OpenPoultryFarmShop__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2866:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r3, r5, r2
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_287C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_287C:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_288C
    bl .LscriptCall_1DAE
.LscriptCall_288C:
    bl ShowReferencePage__9GameScenei
    bl .LscriptCall_1DAE
.LscriptCall_2894:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_28A4
    bl .LscriptCall_1DAE
.LscriptCall_28A4:
    bl OpenBookList__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_28AC:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_28BC
    bl .LscriptCall_1DAE
.LscriptCall_28BC:
    bl OpenLetterList__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_28C4:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_28D4
    bl .LscriptCall_1DAE
.LscriptCall_28D4:
    bl OpenCalendar__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_28DC:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_28EC
    bl .LscriptCall_1DAE
.LscriptCall_28EC:
    bl OpenShelf__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_28F4:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2904
    bl .LscriptCall_1DAE
.LscriptCall_2904:
    bl OpenToolChest__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_290C:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_291C
    bl .LscriptCall_1DAE
.LscriptCall_291C:
    bl OpenRefrigerator__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2924:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2934
    bl .LscriptCall_1DAE
.LscriptCall_2934:
    bl OpenClock__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_293C:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_294C
    bl .LscriptCall_5C96
.LscriptCall_294C:
    bl PrepareClockMenuTransition__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2954:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2964
    bl .LscriptCall_5C96
.LscriptCall_2964:
    bl RestoreAfterClockMenu__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_296C:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_297C
    bl .LscriptCall_5C96
.LscriptCall_297C:
    bl PrepareCookingMenuTransition__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2984:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2994
    bl .LscriptCall_5C96
.LscriptCall_2994:
    bl RestoreAfterCookingMenu__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_299C:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_29AC
    bl .LscriptCall_5C96
.LscriptCall_29AC:
    bl PrepareRecipeMenuTransition__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_29B4:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_29C4
    bl .LscriptCall_5C96
.LscriptCall_29C4:
    bl RestoreAfterRecipeMenu__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_29CC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_29E8
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_29E8:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl HasBushelForEnt__C4CoopUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_2A02:
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r4, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2A18
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_2A18:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl SetEntBushel__4CoopUi
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2A3C
    bl .LscriptCall_5C96
.LscriptCall_2A3C:
    adds r1, r4, #0
    bl RefreshChickenFeedTrough__9GameScene30MaryChickenCoopFeedTroughIndex
    bl .LscriptCall_5C96
.LscriptCall_2A46:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2A62
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2A62:
    cmp r1, #0xf
    ble .LscriptCall_2A82
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    subs r1, #0x10
    bl HasBushelForPregnancyStall__C4BarnUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_2A82:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    bl HasBushelForStall__C4BarnUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_2A9C:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r1, r5, r4
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r4, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2AB2
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_2AB2:
    cmp r4, #0xf
    ble .LscriptCall_2ACE
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    subs r1, #0x10
    bl SetBushelForPregnancyStall__4BarnUi
    b .LscriptCall_2AE2
.LscriptCall_2ACE:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    adds r1, r4, #0
    bl SetBushelForStall__4BarnUi
.LscriptCall_2AE2:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2AF2
    bl .LscriptCall_5C96
.LscriptCall_2AF2:
    adds r1, r4, #0
    bl RefreshBarnFeedTrough__9GameScene23MaryBarnFeedTroughIndex
    bl .LscriptCall_5C96
.LscriptCall_2AFC:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2B0C
    bl .LscriptCall_5C96
.LscriptCall_2B0C:
    bl StartShipmentBoxDepositAnimation__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2B14:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r3, r5, r2
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2B2A
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2B2A:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2B3A
    bl .LscriptCall_5C96
.LscriptCall_2B3A:
    bl SetTelevisionProgram__9GameScene23MaryTelevisionProgramId
    bl .LscriptCall_5C96
.LscriptCall_2B42:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2B52
    bl .LscriptCall_5C96
.LscriptCall_2B52:
    bl EndTelevisionProgram__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2B5A:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl GetRecordPlayer__9FarmHouse
    bl HasAlbum__C12RecordPlayer
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_2B82:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2B9E
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2B9E:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_2BB0
    bl SwapRecordPlayerAlbum__9GameScene17MaryItemArticleId
    adds r1, r0, #0
.LscriptCall_2BB0:
    ldr r2, [r4]
    cmp r2, #0x63
    bls .LscriptCall_2BBA
    bl .LscriptCall_5C96
.LscriptCall_2BBA:
    lsls r0, r2, #2
    adds r0, r6, r0
    bl .LscriptCall_541A
.LscriptCall_2BC2:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2BD2
    bl .LscriptCall_5C96
.LscriptCall_2BD2:
    bl RedrawRucksackShelfAfterPurchase__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2BDA:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2BEA
    bl .LscriptCall_5C96
.LscriptCall_2BEA:
    bl RedrawBlueFeatherShelfAfterPurchase__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_2BF2:
    movs r4, #0
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_2C06
    bl RemoveRecordPlayerAlbum__9GameScene
    adds r4, r0, #0
.LscriptCall_2C06:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_2C14:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2C24
    bl .LscriptCall_1DAE
.LscriptCall_2C24:
    bl OpenCookingMenu__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2C2C:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2C3C
    bl .LscriptCall_1DAE
.LscriptCall_2C3C:
    bl OpenRecipeList__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2C44:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2C54
    bl .LscriptCall_1DAE
.LscriptCall_2C54:
    bl RunGameCubeLink__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2C5C:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2C6C
    bl .LscriptCall_1DAE
.LscriptCall_2C6C:
    bl StartFarmInheritanceFlashback__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2C74:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2C84
    bl .LscriptCall_1DAE
.LscriptCall_2C84:
    bl OpenRucksackMenu__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2C8C:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2CA2
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_2CA2:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2CB2
    bl .LscriptCall_1DAE
.LscriptCall_2CB2:
    rsbs r1, r3, #0
    orrs r1, r3
    lsrs r1, r1, #0x1f
    bl OpenTownMap__9GameSceneUc
    bl .LscriptCall_1DAE
.LscriptCall_2CC0:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r3, r5, r2
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2CD6
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2CD6:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2CE6
    bl .LscriptCall_1DAE
.LscriptCall_2CE6:
    bl SelectFestivalAnimal__9GameScene22MaryFestivalAnimalKind
    bl .LscriptCall_1DAE
.LscriptCall_2CEE:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2CFE
    bl .LscriptCall_1DAE
.LscriptCall_2CFE:
    bl RunStaffCredits__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_2D06:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2D1C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2D1C:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2D2C
    bl .LscriptCall_1DAE
.LscriptCall_2D2C:
    bl OpenFarmingTutorial__9GameScene23MaryFarmingTutorialKind
    bl .LscriptCall_1DAE
.LscriptCall_2D34:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2D50
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2D50:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2D74 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    movs r2, #3
    cmp r0, #0
    bne .LscriptCall_2D6A
    bl .LscriptCall_588A
.LscriptCall_2D6A:
    bl GetCurrentTask__C13HarvestSprite
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2D74: .word 0x00001CD4
.LscriptCall_2D78:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2D94
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2D94:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2DB8 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2DAE
    bl .LscriptCall_588A
.LscriptCall_2DAE:
    bl GetWorkDaysLeft__C13HarvestSprite
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2DB8: .word 0x00001CD4
.LscriptCall_2DBC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_2DD8
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2DD8:
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2DEA
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2DEA:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2E10 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2E04
    bl .LscriptCall_588A
.LscriptCall_2E04:
    adds r1, r7, #0
    bl GetTaskExp__C13HarvestSpriteQ213HarvestSprite4Task
    adds r2, r0, #0
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2E10: .word 0x00001CD4
.LscriptCall_2E14:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2E30
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2E30:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2E58 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_2E4A
    bl .LscriptCall_588A
.LscriptCall_2E4A:
    bl HasPlayedMinigameToday__C13HarvestSprite
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
    .align 2, 0
.LscriptCall_2E58: .word 0x00001CD4
.LscriptCall_2E5C:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_2E78
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2E78:
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2E8A
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2E8A:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2EC0 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    movs r1, #0
    cmp r0, #0
    beq .LscriptCall_2EAC
    adds r1, r7, #0
    bl GetMinigameExp__C13HarvestSpriteQ213HarvestSprite4Task
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
.LscriptCall_2EAC:
    ldr r2, [r4]
    cmp r2, #0x63
    bls .LscriptCall_2EB6
    bl .LscriptCall_5C96
.LscriptCall_2EB6:
    lsls r0, r2, #2
    adds r0, r6, r0
    bl .LscriptCall_541A
    .align 2, 0
.LscriptCall_2EC0: .word 0x00001CD4
.LscriptCall_2EC4:
    adds r4, r5, #0
    adds r4, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_2EE0
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_2EE0:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r2, #0
    beq .LscriptCall_2EF2
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2EF2:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2F04
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2F04:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_2F28 @ =0x00001CD4
    adds r0, r0, r3
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_2F1C
    bl .LscriptCall_5C96
.LscriptCall_2F1C:
    adds r1, r6, #0
    adds r2, r7, #0
    bl StartTask__13HarvestSpriteQ213HarvestSprite4Taski
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2F28: .word 0x00001CD4
.LscriptCall_2F2C:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2F42
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2F42:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_2F64 @ =0x00001CD4
    adds r0, r0, r2
    bl GetHarvestSpriteByCharacterId__13NpcCollectionUi
    cmp r0, #0
    bne .LscriptCall_2F5A
    bl .LscriptCall_5C96
.LscriptCall_2F5A:
    bl method_0809E6EC__13HarvestSprite
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_2F64: .word 0x00001CD4
.LscriptCall_2F68:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_2F84
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_2F84:
    movs r2, #0
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2F96
    bl .LscriptCall_588A
.LscriptCall_2F96:
    bl IsHarvestSpriteDailyWorkComplete__9GameScene15MaryCharacterId
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_2FA2:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2FB8
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2FB8:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2FC8
    bl .LscriptCall_1DAE
.LscriptCall_2FC8:
    bl RunHarvestSpriteAnimalCareMinigame__9GameScene15MaryCharacterId
    bl .LscriptCall_1DAE
.LscriptCall_2FD0:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_2FE6
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_2FE6:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_2FF6
    bl .LscriptCall_1DAE
.LscriptCall_2FF6:
    bl RunHarvestSpriteWateringMinigame__9GameScene15MaryCharacterId
    bl .LscriptCall_1DAE
.LscriptCall_2FFE:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_3014
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_3014:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3024
    bl .LscriptCall_1DAE
.LscriptCall_3024:
    bl RunHarvestSpriteHarvestingMinigame__9GameScene15MaryCharacterId
    bl .LscriptCall_1DAE
.LscriptCall_302C:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_303C
    bl .LscriptCall_1DAE
.LscriptCall_303C:
    bl RunChickenFestivalContest__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_3044:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r3, r5, r2
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_305A
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_305A:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_306A
    bl .LscriptCall_1DAE
.LscriptCall_306A:
    bl RunHorseRace__9GameScene25MaryFestivalHorseRaceMode
    bl .LscriptCall_1DAE
.LscriptCall_3072:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_3088
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_3088:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r1, [r0]
    ldr r0, .LscriptCall_30C8 @ =0x00002C1C
    adds r5, r1, r0
    rsbs r0, r3, #0
    orrs r0, r3
    lsrs r4, r0, #0x1f
    movs r3, #0xc8
    str r3, [sp, #0x28]
    ldrb r0, [r1, #0x10]
    lsrs r2, r0, #3
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r0, r0, #0x1d
    lsrs r0, r0, #0x1d
    adds r1, r1, r0
    str r1, [sp, #0x2c]
    add r0, sp, #0x2c
    add r2, sp, #0x28
    cmp r3, r1
    bls .LscriptCall_30B8
    adds r2, r0, #0
.LscriptCall_30B8:
    ldr r2, [r2]
    adds r0, r5, #0
    adds r1, r4, #0
    bl PrepareHorseRaceEntries
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_30C8: .word 0x00002C1C
.LscriptCall_30CC:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_30DC
    bl .LscriptCall_1DAE
.LscriptCall_30DC:
    bl OpenHorseRaceMedalExchange__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_30E4:
    movs r2, #0xda
    lsls r2, r2, #1
    adds r1, r5, r2
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_30FA
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_30FA:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_310A
    bl .LscriptCall_1DAE
.LscriptCall_310A:
    rsbs r1, r3, #0
    orrs r1, r3
    lsrs r1, r1, #0x1f
    bl RunFrisbeeGame__9GameSceneb
    bl .LscriptCall_1DAE
.LscriptCall_3118:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3128
    bl .LscriptCall_1DAE
.LscriptCall_3128:
    bl ShowFrisbeeScoreboard__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_3130:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    ldr r2, .LscriptCall_3150 @ =0x00002C4C
    adds r0, r1, r2
    ldr r3, .LscriptCall_3154 @ =0x00001C9C
    adds r1, r1, r3
    ldr r1, [r1]
    lsls r1, r1, #0xb
    lsrs r1, r1, #0x18
    bl Generate__23AnimalFestivalOpponentsUi
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_3150: .word 0x00002C4C
.LscriptCall_3154: .word 0x00001C9C
.LscriptCall_3158:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_3178 @ =0x00002C74
    adds r0, r0, r6
    bl GetTVShoppingSelection
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3178: .word 0x00002C74
.LscriptCall_317C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_319C @ =0x00002C74
    adds r0, r0, r2
    bl GetTVShoppingPendingItem
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_319C: .word 0x00002C74
.LscriptCall_31A0:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_31C4 @ =0x00002C74
    adds r0, r0, r6
    bl IsTVShoppingDeliveryReady
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_31C4: .word 0x00002C74
.LscriptCall_31C8:
    movs r1, #0xda
    lsls r1, r1, #1
    adds r3, r5, r1
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_31DE
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_31DE:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_31F4 @ =0x00002C74
    adds r0, r0, r3
    bl SetTVShoppingSelection
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_31F4: .word 0x00002C74
.LscriptCall_31F8:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_320C @ =0x00002C74
    adds r0, r0, r6
    bl ConfirmTVShoppingOrder
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_320C: .word 0x00002C74
.LscriptCall_3210:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_3230 @ =0x00002C74
    adds r0, r0, r2
    bl GetTVShoppingPendingItem
    cmp r0, #0xf
    bls .LscriptCall_3226
    b .LscriptCall_33A2
.LscriptCall_3226:
    lsls r0, r0, #2
    ldr r1, .LscriptCall_3234 @ =.LscriptCall_3238
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_3230: .word 0x00002C74
.LscriptCall_3234: .word .LscriptCall_3238
.LscriptCall_3238: @ jump table
    .word .LscriptCall_3278 @ case 0
    .word .LscriptCall_328C @ case 1
    .word .LscriptCall_32A0 @ case 2
    .word .LscriptCall_32B4 @ case 3
    .word .LscriptCall_32C8 @ case 4
    .word .LscriptCall_32DC @ case 5
    .word .LscriptCall_32F0 @ case 6
    .word .LscriptCall_3304 @ case 7
    .word .LscriptCall_3318 @ case 8
    .word .LscriptCall_332C @ case 9
    .word .LscriptCall_3340 @ case 10
    .word .LscriptCall_3354 @ case 11
    .word .LscriptCall_3368 @ case 12
    .word .LscriptCall_337C @ case 13
    .word .LscriptCall_3390 @ case 14
    .word .LscriptCall_33A2 @ case 15
.LscriptCall_3278:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r4, #0xfa
    lsls r4, r4, #1
    adds r0, r0, r4
    bl AddClock__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_328C:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl AddMirror__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_32A0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl AddFridge__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_32B4:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0xfa
    lsls r6, r6, #1
    adds r0, r0, r6
    bl AddShelf__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_32C8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl AddKitchen__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_32DC:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r4, #0xfa
    lsls r4, r4, #1
    adds r0, r0, r4
    bl AddCarpet__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_32F0:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl AddLargeBed__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3304:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl AddKitchenKnife__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3318:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0xfa
    lsls r6, r6, #1
    adds r0, r0, r6
    bl AddKitchenFryingPan__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_332C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl AddKitchenPot__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3340:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r4, #0xfa
    lsls r4, r4, #1
    adds r0, r0, r4
    bl AddKitchenMixer__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3354:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl AddKitchenWhisk__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3368:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r0, r3
    bl KitchenRollingPin__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_337C:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0xfa
    lsls r6, r6, #1
    adds r0, r0, r6
    bl AddKitchenOven__9FarmHouse
    b .LscriptCall_33A2
.LscriptCall_3390:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl AddKitchenSeasoningSet__9FarmHouse
.LscriptCall_33A2:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_33B8 @ =0x00002C74
    adds r0, r0, r4
    bl CompleteTVShoppingDelivery
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_33B8: .word 0x00002C74
.LscriptCall_33BC:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_33DC @ =0x00001AA8
    adds r0, r0, r1
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1e
    lsrs r4, r0, #0x1f
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_33DC: .word 0x00001AA8
.LscriptCall_33E0:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_3404 @ =0x00001CD4
    adds r0, r0, r6
    bl func_080A0518
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3404: .word 0x00001CD4
.LscriptCall_3408:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    adds r0, #0x54
    bl HasShippedOneOfEachCrop__C11ShippingBin
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_3428:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    adds r0, #0x54
    bl HasShippedOneOfEachProduct__C11ShippingBin
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    bl .LscriptCall_5BCC
.LscriptCall_343E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    bl AllAnimalsHaveHighAffection__C18GameStateSaveImage
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_345C:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    adds r0, #0x54
    bl HasShippedOneOfEachMineral__C11ShippingBin
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    bl .LscriptCall_5BCC
.LscriptCall_3472:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xb2
    lsls r2, r2, #6
    adds r0, r0, r2
    bl HasCaughtEveryFishSpecies__C14FishingRecords
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_3496:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0xb2
    lsls r6, r6, #6
    adds r0, r0, r6
    bl GetTotalFishCaught__C14FishingRecords
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_34B8:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    bl GetFlag3__C18GameStateSaveImage
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_34D6:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_34F4 @ =0x00001AA8
    adds r0, r0, r6
    ldr r4, [r0]
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_34F4: .word 0x00001AA8
.LscriptCall_34F8:
    movs r1, #0xda
    lsls r1, r1, #1
    adds r3, r5, r1
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_350E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_350E:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_3524 @ =0x00001AA8
    adds r0, r0, r3
    bl AddMoneyToAccount
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_3524: .word 0x00001AA8
.LscriptCall_3528:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_353E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_353E:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r2, .LscriptCall_3554 @ =0x00001AA8
    adds r0, r0, r2
    bl SubtractMoneyFromAccount
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_3554: .word 0x00001AA8
.LscriptCall_3558:
    movs r3, #0x64
    mov sb, r3
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r4, r5, r6
    ldr r0, [r4]
    ldr r1, .LscriptCall_3594 @ =0x00001CD4
    adds r0, r0, r1
    bl GetSpouseCharacterId__C13NpcCollection
    adds r6, r0, #0
    cmp r6, #0
    beq .LscriptCall_3574
    b .LscriptCall_36E6
.LscriptCall_3574:
    ldr r0, [r4]
    ldr r2, .LscriptCall_3598 @ =0x00001D6C
    adds r0, r0, r2
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bhi .LscriptCall_359C
    ldr r0, [r4]
    ldr r3, .LscriptCall_3598 @ =0x00001D6C
    adds r0, r0, r3
    bl GetLove__C12Bachelorette
    add r1, sp, #0xc
    strh r0, [r1]
    b .LscriptCall_35A0
    .align 2, 0
.LscriptCall_3594: .word 0x00001CD4
.LscriptCall_3598: .word 0x00001D6C
.LscriptCall_359C:
    add r0, sp, #0xc
    strh r6, [r0]
.LscriptCall_35A0:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r4, r5, r6
    ldr r0, [r4]
    ldr r1, .LscriptCall_35C4 @ =0x00001E28
    adds r0, r0, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bhi .LscriptCall_35C8
    ldr r0, [r4]
    ldr r2, .LscriptCall_35C4 @ =0x00001E28
    adds r0, r0, r2
    bl GetLove__C12Bachelorette
    add r1, sp, #0xc
    b .LscriptCall_35CC
    .align 2, 0
.LscriptCall_35C4: .word 0x00001E28
.LscriptCall_35C8:
    add r1, sp, #0xc
    movs r0, #0
.LscriptCall_35CC:
    strh r0, [r1, #2]
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r4, r5, r3
    ldr r0, [r4]
    ldr r6, .LscriptCall_35F0 @ =0x00001EB8
    adds r0, r0, r6
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bhi .LscriptCall_35F4
    ldr r0, [r4]
    adds r0, r0, r6
    bl GetLove__C12Bachelorette
    add r1, sp, #0xc
    b .LscriptCall_35F8
    .align 2, 0
.LscriptCall_35F0: .word 0x00001EB8
.LscriptCall_35F4:
    add r1, sp, #0xc
    movs r0, #0
.LscriptCall_35F8:
    strh r0, [r1, #4]
    movs r0, #0xd4
    lsls r0, r0, #2
    adds r4, r5, r0
    ldr r0, [r4]
    ldr r1, .LscriptCall_361C @ =0x00001EE4
    adds r0, r0, r1
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bhi .LscriptCall_3620
    ldr r0, [r4]
    ldr r2, .LscriptCall_361C @ =0x00001EE4
    adds r0, r0, r2
    bl GetLove__C12Bachelorette
    add r1, sp, #0xc
    b .LscriptCall_3624
    .align 2, 0
.LscriptCall_361C: .word 0x00001EE4
.LscriptCall_3620:
    add r1, sp, #0xc
    movs r0, #0
.LscriptCall_3624:
    strh r0, [r1, #6]
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r4, r5, r3
    ldr r0, [r4]
    ldr r6, .LscriptCall_3648 @ =0x00001F38
    adds r0, r0, r6
    bl GetRivalEventCount__C12Bachelorette
    cmp r0, #4
    bhi .LscriptCall_364C
    ldr r0, [r4]
    adds r0, r0, r6
    bl GetLove__C12Bachelorette
    add r1, sp, #0xc
    b .LscriptCall_3650
    .align 2, 0
.LscriptCall_3648: .word 0x00001F38
.LscriptCall_364C:
    add r1, sp, #0xc
    movs r0, #0
.LscriptCall_3650:
    strh r0, [r1, #8]
    movs r7, #1
    rsbs r7, r7, #0
    ldr r2, .LscriptCall_3674 @ =0x00007530
    movs r4, #0
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    adds r5, #0x24
    mov r8, r5
    add r5, sp, #0xc
.LscriptCall_3666:
    ldrh r0, [r5]
    cmp r0, r2
    bls .LscriptCall_3678
    adds r7, r4, #0
    adds r2, r0, #0
    b .LscriptCall_3698
    .align 2, 0
.LscriptCall_3674: .word 0x00007530
.LscriptCall_3678:
    cmp r0, r2
    bne .LscriptCall_3698
    movs r0, #1
    rsbs r0, r0, #0
    cmp r7, r0
    beq .LscriptCall_3696
    str r2, [sp, #0x3c]
    bl rand
    asrs r0, r0, #8
    movs r1, #1
    ands r0, r1
    ldr r2, [sp, #0x3c]
    cmp r0, #0
    bne .LscriptCall_3698
.LscriptCall_3696:
    adds r7, r4, #0
.LscriptCall_3698:
    adds r5, #2
    adds r4, #1
    cmp r4, #4
    ble .LscriptCall_3666
    cmp r7, #4
    bls .LscriptCall_36A6
    b .LscriptCall_37A6
.LscriptCall_36A6:
    lsls r0, r7, #2
    ldr r1, .LscriptCall_36B0 @ =.LscriptCall_36B4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_36B0: .word .LscriptCall_36B4
.LscriptCall_36B4: @ jump table
    .word .LscriptCall_36C8 @ case 0
    .word .LscriptCall_36CE @ case 1
    .word .LscriptCall_36D4 @ case 2
    .word .LscriptCall_36DA @ case 3
    .word .LscriptCall_36E0 @ case 4
.LscriptCall_36C8:
    movs r1, #3
    mov sb, r1
    b .LscriptCall_37A6
.LscriptCall_36CE:
    movs r2, #0xc
    mov sb, r2
    b .LscriptCall_37A6
.LscriptCall_36D4:
    movs r3, #0x13
    mov sb, r3
    b .LscriptCall_37A6
.LscriptCall_36DA:
    movs r4, #0x15
    mov sb, r4
    b .LscriptCall_37A6
.LscriptCall_36E0:
    movs r0, #0x19
    mov sb, r0
    b .LscriptCall_37A6
.LscriptCall_36E6:
    ldr r0, [r4]
    ldr r1, .LscriptCall_370C @ =0x00001CD4
    adds r0, r0, r1
    bl GetSpouseCharacterId__C13NpcCollection
    subs r0, #3
    movs r2, #0xda
    lsls r2, r2, #1
    adds r6, r5, r2
    movs r3, #0x24
    adds r3, r3, r5
    mov r8, r3
    cmp r0, #0x16
    bhi .LscriptCall_37A6
    lsls r0, r0, #2
    ldr r1, .LscriptCall_3710 @ =.LscriptCall_3714
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_370C: .word 0x00001CD4
.LscriptCall_3710: .word .LscriptCall_3714
.LscriptCall_3714: @ jump table
    .word .LscriptCall_3770 @ case 0
    .word .LscriptCall_37A6 @ case 1
    .word .LscriptCall_37A6 @ case 2
    .word .LscriptCall_37A6 @ case 3
    .word .LscriptCall_37A6 @ case 4
    .word .LscriptCall_37A6 @ case 5
    .word .LscriptCall_37A6 @ case 6
    .word .LscriptCall_37A6 @ case 7
    .word .LscriptCall_37A6 @ case 8
    .word .LscriptCall_377C @ case 9
    .word .LscriptCall_37A6 @ case 10
    .word .LscriptCall_37A6 @ case 11
    .word .LscriptCall_37A6 @ case 12
    .word .LscriptCall_37A6 @ case 13
    .word .LscriptCall_37A6 @ case 14
    .word .LscriptCall_37A6 @ case 15
    .word .LscriptCall_3780 @ case 16
    .word .LscriptCall_37A6 @ case 17
    .word .LscriptCall_378C @ case 18
    .word .LscriptCall_37A6 @ case 19
    .word .LscriptCall_37A6 @ case 20
    .word .LscriptCall_37A6 @ case 21
    .word .LscriptCall_3798 @ case 22
.LscriptCall_3770:
    movs r4, #3
    mov sb, r4
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    b .LscriptCall_37A2
.LscriptCall_377C:
    movs r1, #0xc
    b .LscriptCall_379A
.LscriptCall_3780:
    movs r3, #0x13
    mov sb, r3
    movs r4, #0xda
    lsls r4, r4, #1
    adds r6, r5, r4
    b .LscriptCall_37A2
.LscriptCall_378C:
    movs r6, #0x15
    mov sb, r6
    movs r0, #0xda
    lsls r0, r0, #1
    adds r6, r5, r0
    b .LscriptCall_37A2
.LscriptCall_3798:
    movs r1, #0x19
.LscriptCall_379A:
    mov sb, r1
    movs r2, #0xda
    lsls r2, r2, #1
    adds r6, r5, r2
.LscriptCall_37A2:
    adds r5, #0x24
    mov r8, r5
.LscriptCall_37A6:
    mov r3, sb
    cmp r3, #0x64
    bne .LscriptCall_37B0
    movs r4, #3
    mov sb, r4
.LscriptCall_37B0:
    mov r0, sb
    subs r0, #3
    cmp r0, #0x16
    bhi .LscriptCall_3824
    lsls r0, r0, #2
    ldr r1, .LscriptCall_37C4 @ =.LscriptCall_37C8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_37C4: .word .LscriptCall_37C8
.LscriptCall_37C8: @ jump table
    .word .LscriptCall_3848 @ case 0
    .word .LscriptCall_3824 @ case 1
    .word .LscriptCall_3824 @ case 2
    .word .LscriptCall_3824 @ case 3
    .word .LscriptCall_3824 @ case 4
    .word .LscriptCall_3824 @ case 5
    .word .LscriptCall_3824 @ case 6
    .word .LscriptCall_3824 @ case 7
    .word .LscriptCall_3824 @ case 8
    .word .LscriptCall_385A @ case 9
    .word .LscriptCall_3824 @ case 10
    .word .LscriptCall_3824 @ case 11
    .word .LscriptCall_3824 @ case 12
    .word .LscriptCall_3824 @ case 13
    .word .LscriptCall_3824 @ case 14
    .word .LscriptCall_3824 @ case 15
    .word .LscriptCall_3824 @ case 16
    .word .LscriptCall_3824 @ case 17
    .word .LscriptCall_386C @ case 18
    .word .LscriptCall_3824 @ case 19
    .word .LscriptCall_3824 @ case 20
    .word .LscriptCall_3824 @ case 21
    .word .LscriptCall_3836 @ case 22
.LscriptCall_3824:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_382E
    bl .LscriptCall_5C96
.LscriptCall_382E:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #0
    b .LscriptCall_3E32
.LscriptCall_3836:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3840
    bl .LscriptCall_5C96
.LscriptCall_3840:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #1
    b .LscriptCall_3E32
.LscriptCall_3848:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3852
    bl .LscriptCall_5C96
.LscriptCall_3852:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #2
    b .LscriptCall_3E32
.LscriptCall_385A:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3864
    bl .LscriptCall_5C96
.LscriptCall_3864:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #3
    b .LscriptCall_3E32
.LscriptCall_386C:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3876
    bl .LscriptCall_5C96
.LscriptCall_3876:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #4
    b .LscriptCall_3E32
.LscriptCall_387E:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r7, [r0]
    ldr r0, .LscriptCall_38B4 @ =0x00001C2C
    adds r4, r7, r0
    movs r6, #5
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_38A2
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #0
    beq .LscriptCall_38BC
.LscriptCall_38A2:
    ldr r0, .LscriptCall_38B8 @ =gUnk_0300040C
    ldr r0, [r0]
    movs r1, #0xda
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #0xab
    str r1, [r0]
    b .LscriptCall_3B5E
    .align 2, 0
.LscriptCall_38B4: .word 0x00001C2C
.LscriptCall_38B8: .word gUnk_0300040C
.LscriptCall_38BC:
    add r0, sp, #0xc
    adds r1, r4, #0
    bl func_0800F20C
    add r6, sp, #0xc
    ldr r0, .LscriptCall_38F4 @ =gUnk_0300040C
    ldr r4, [r0]
    movs r2, #0xda
    lsls r2, r2, #2
    adds r4, r4, r2
    adds r0, r6, #0
    bl GetId__C4Food
    str r0, [r4]
    ldr r3, .LscriptCall_38F8 @ =0x0000219B
    adds r0, r7, r3
    ldrb r0, [r0]
    lsls r0, r0, #0x1c
    lsrs r7, r0, #0x1d
    movs r4, #0
    cmp r7, #4
    bls .LscriptCall_38EA
    b .LscriptCall_3B08
.LscriptCall_38EA:
    lsls r0, r7, #2
    ldr r1, .LscriptCall_38FC @ =.LscriptCall_3900
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_38F4: .word gUnk_0300040C
.LscriptCall_38F8: .word 0x0000219B
.LscriptCall_38FC: .word .LscriptCall_3900
.LscriptCall_3900: @ jump table
    .word .LscriptCall_3914 @ case 0
    .word .LscriptCall_395E @ case 1
    .word .LscriptCall_3A90 @ case 2
    .word .LscriptCall_3ABC @ case 3
    .word .LscriptCall_3AD0 @ case 4
.LscriptCall_3914:
    adds r0, r6, #0
    bl GetId__C4Food
    cmp r0, #0x5c
    bne .LscriptCall_3920
    b .LscriptCall_3B0C
.LscriptCall_3920:
    cmp r0, #0x5c
    bgt .LscriptCall_393E
    cmp r0, #0x3e
    bne .LscriptCall_392A
    b .LscriptCall_3B0C
.LscriptCall_392A:
    cmp r0, #0x3e
    bge .LscriptCall_3930
    b .LscriptCall_3B08
.LscriptCall_3930:
    cmp r0, #0x5a
    ble .LscriptCall_3936
    b .LscriptCall_3B08
.LscriptCall_3936:
    cmp r0, #0x54
    bge .LscriptCall_393C
    b .LscriptCall_3B08
.LscriptCall_393C:
    b .LscriptCall_3B0C
.LscriptCall_393E:
    cmp r0, #0x6f
    bne .LscriptCall_3944
    b .LscriptCall_3B0C
.LscriptCall_3944:
    cmp r0, #0x6f
    bgt .LscriptCall_3950
    cmp r0, #0x64
    bne .LscriptCall_394E
    b .LscriptCall_3B0C
.LscriptCall_394E:
    b .LscriptCall_3B08
.LscriptCall_3950:
    cmp r0, #0x91
    bne .LscriptCall_3956
    b .LscriptCall_3B0C
.LscriptCall_3956:
    cmp r0, #0x9b
    beq .LscriptCall_395C
    b .LscriptCall_3B08
.LscriptCall_395C:
    b .LscriptCall_3B0C
.LscriptCall_395E:
    adds r0, r6, #0
    bl GetId__C4Food
    subs r0, #0x65
    cmp r0, #0x44
    bls .LscriptCall_396C
    b .LscriptCall_3B08
.LscriptCall_396C:
    lsls r0, r0, #2
    ldr r1, .LscriptCall_3978 @ =.LscriptCall_397C
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_3978: .word .LscriptCall_397C
.LscriptCall_397C: @ jump table
    .word .LscriptCall_3B0C @ case 0
    .word .LscriptCall_3B08 @ case 1
    .word .LscriptCall_3B08 @ case 2
    .word .LscriptCall_3B0C @ case 3
    .word .LscriptCall_3B0C @ case 4
    .word .LscriptCall_3B08 @ case 5
    .word .LscriptCall_3B08 @ case 6
    .word .LscriptCall_3B08 @ case 7
    .word .LscriptCall_3B08 @ case 8
    .word .LscriptCall_3B08 @ case 9
    .word .LscriptCall_3B08 @ case 10
    .word .LscriptCall_3B08 @ case 11
    .word .LscriptCall_3B0C @ case 12
    .word .LscriptCall_3B08 @ case 13
    .word .LscriptCall_3B0C @ case 14
    .word .LscriptCall_3B08 @ case 15
    .word .LscriptCall_3B0C @ case 16
    .word .LscriptCall_3B08 @ case 17
    .word .LscriptCall_3B08 @ case 18
    .word .LscriptCall_3B08 @ case 19
    .word .LscriptCall_3B08 @ case 20
    .word .LscriptCall_3B08 @ case 21
    .word .LscriptCall_3B08 @ case 22
    .word .LscriptCall_3B08 @ case 23
    .word .LscriptCall_3B08 @ case 24
    .word .LscriptCall_3B08 @ case 25
    .word .LscriptCall_3B08 @ case 26
    .word .LscriptCall_3B08 @ case 27
    .word .LscriptCall_3B08 @ case 28
    .word .LscriptCall_3B08 @ case 29
    .word .LscriptCall_3B08 @ case 30
    .word .LscriptCall_3B08 @ case 31
    .word .LscriptCall_3B08 @ case 32
    .word .LscriptCall_3B08 @ case 33
    .word .LscriptCall_3B08 @ case 34
    .word .LscriptCall_3B08 @ case 35
    .word .LscriptCall_3B08 @ case 36
    .word .LscriptCall_3B08 @ case 37
    .word .LscriptCall_3B0C @ case 38
    .word .LscriptCall_3B0C @ case 39
    .word .LscriptCall_3B08 @ case 40
    .word .LscriptCall_3B0C @ case 41
    .word .LscriptCall_3B0C @ case 42
    .word .LscriptCall_3B0C @ case 43
    .word .LscriptCall_3B08 @ case 44
    .word .LscriptCall_3B08 @ case 45
    .word .LscriptCall_3B08 @ case 46
    .word .LscriptCall_3B0C @ case 47
    .word .LscriptCall_3B08 @ case 48
    .word .LscriptCall_3B0C @ case 49
    .word .LscriptCall_3B0C @ case 50
    .word .LscriptCall_3B0C @ case 51
    .word .LscriptCall_3B08 @ case 52
    .word .LscriptCall_3B08 @ case 53
    .word .LscriptCall_3B08 @ case 54
    .word .LscriptCall_3B08 @ case 55
    .word .LscriptCall_3B0C @ case 56
    .word .LscriptCall_3B08 @ case 57
    .word .LscriptCall_3B08 @ case 58
    .word .LscriptCall_3B08 @ case 59
    .word .LscriptCall_3B08 @ case 60
    .word .LscriptCall_3B08 @ case 61
    .word .LscriptCall_3B08 @ case 62
    .word .LscriptCall_3B08 @ case 63
    .word .LscriptCall_3B08 @ case 64
    .word .LscriptCall_3B08 @ case 65
    .word .LscriptCall_3B0C @ case 66
    .word .LscriptCall_3B08 @ case 67
    .word .LscriptCall_3B0C @ case 68
.LscriptCall_3A90:
    adds r0, r6, #0
    bl GetId__C4Food
    cmp r0, #0x7c
    bgt .LscriptCall_3AA8
    cmp r0, #0x7a
    bge .LscriptCall_3B0C
    cmp r0, #0x40
    beq .LscriptCall_3B0C
    cmp r0, #0x53
    beq .LscriptCall_3B0C
    b .LscriptCall_3B08
.LscriptCall_3AA8:
    cmp r0, #0x93
    bgt .LscriptCall_3AB6
    cmp r0, #0x92
    bge .LscriptCall_3B0C
    cmp r0, #0x7e
    beq .LscriptCall_3B0C
    b .LscriptCall_3B08
.LscriptCall_3AB6:
    cmp r0, #0x9e
    bne .LscriptCall_3B08
    b .LscriptCall_3B0C
.LscriptCall_3ABC:
    adds r0, r6, #0
    bl GetId__C4Food
    cmp r0, #0x83
    blt .LscriptCall_3B08
    cmp r0, #0x86
    ble .LscriptCall_3B0C
    cmp r0, #0x9f
    bne .LscriptCall_3B08
    b .LscriptCall_3B0C
.LscriptCall_3AD0:
    adds r0, r6, #0
    bl GetId__C4Food
    cmp r0, #0x79
    bgt .LscriptCall_3AF6
    cmp r0, #0x76
    bge .LscriptCall_3B06
    cmp r0, #0x4d
    beq .LscriptCall_3B06
    cmp r0, #0x4d
    bgt .LscriptCall_3AEC
    cmp r0, #0x3f
    beq .LscriptCall_3B06
    b .LscriptCall_3B08
.LscriptCall_3AEC:
    cmp r0, #0x51
    beq .LscriptCall_3B06
    cmp r0, #0x6d
    beq .LscriptCall_3B06
    b .LscriptCall_3B08
.LscriptCall_3AF6:
    cmp r0, #0x81
    beq .LscriptCall_3B06
    cmp r0, #0x81
    blt .LscriptCall_3B08
    cmp r0, #0xa6
    bgt .LscriptCall_3B08
    cmp r0, #0xa3
    blt .LscriptCall_3B08
.LscriptCall_3B06:
    movs r4, #1
.LscriptCall_3B08:
    cmp r4, #0
    beq .LscriptCall_3B5C
.LscriptCall_3B0C:
    adds r0, r6, #0
    bl GetStaminaGain__C4Food
    adds r4, r0, #0
    adds r0, r6, #0
    bl GetFatigueGain__C4Food
    subs r4, r4, r0
    ldr r2, .LscriptCall_3B2C @ =gUnk_080F9EC5
    lsls r1, r7, #2
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r4, r0
    ble .LscriptCall_3B30
    movs r6, #0
    b .LscriptCall_3B5E
    .align 2, 0
.LscriptCall_3B2C: .word gCookingFestivalDishCategoryRatingThresholds
.LscriptCall_3B30:
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r4, r0
    ble .LscriptCall_3B3E
    movs r6, #1
    b .LscriptCall_3B5E
.LscriptCall_3B3E:
    adds r0, r2, #2
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r4, r0
    ble .LscriptCall_3B4C
    movs r6, #2
    b .LscriptCall_3B5E
.LscriptCall_3B4C:
    adds r0, r2, #3
    adds r0, r1, r0
    movs r6, #4
    ldrb r0, [r0]
    cmp r4, r0
    ble .LscriptCall_3B5E
    movs r6, #3
    b .LscriptCall_3B5E
.LscriptCall_3B5C:
    movs r6, #5
.LscriptCall_3B5E:
    adds r2, r5, #0
    adds r2, #0x24
    movs r4, #0xda
    lsls r4, r4, #1
    adds r1, r5, r4
    ldr r3, [r1]
    cmp r3, #0x63
    bls .LscriptCall_3B72
    bl .LscriptCall_5C96
.LscriptCall_3B72:
    lsls r0, r3, #2
    adds r0, r2, r0
    str r6, [r0]
    bl .LscriptCall_5BE2
.LscriptCall_3B7C:
    bl rand
    asrs r1, r0, #4
    movs r0, #0xff
    ands r1, r0
    movs r2, #0
    ldr r3, .LscriptCall_3B98 @ =gUnk_080F9ED9
.LscriptCall_3B8A:
    adds r0, r2, r3
    ldrb r0, [r0]
    cmp r1, r0
    bhi .LscriptCall_3B9C
    adds r4, r2, #1
    bl .LscriptCall_5BCC
    .align 2, 0
.LscriptCall_3B98: .word gThomasStockingGiftSelectionWeights
.LscriptCall_3B9C:
    subs r1, r1, r0
    adds r2, #1
    cmp r2, #4
    bls .LscriptCall_3B8A
    bl .LscriptCall_5C96
.LscriptCall_3BA8:
    bl rand
    asrs r1, r0, #4
    movs r0, #0xff
    ands r1, r0
    movs r3, #0
    ldr r2, .LscriptCall_3BCC @ =gUnk_080F9EE0
.LscriptCall_3BB6:
    ldrb r0, [r2]
    cmp r1, r0
    bhi .LscriptCall_3BD0
    ldrh r4, [r2, #2]
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3BCC: .word gSpouseGiftArticleSelectionEntries
.LscriptCall_3BD0:
    subs r1, r1, r0
    adds r2, #4
    adds r3, #1
    cmp r3, #4
    bls .LscriptCall_3BB6
    bl .LscriptCall_5C96
.LscriptCall_3BDE:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_3C00 @ =0x00001FE4
    adds r0, r0, r2
    bl UnlockNextAlbum__3Van
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3C00: .word 0x00001FE4
.LscriptCall_3C04:
    movs r4, #1
    mov sb, r4
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_3C24 @ =0x00001FE4
    adds r7, r0, r1
    movs r4, #0
    movs r2, #0xda
    lsls r2, r2, #1
    adds r6, r5, r2
    adds r5, #0x24
    mov r8, r5
    b .LscriptCall_3C2A
    .align 2, 0
.LscriptCall_3C24: .word 0x00001FE4
.LscriptCall_3C28:
    adds r4, #1
.LscriptCall_3C2A:
    cmp r4, #9
    bhi .LscriptCall_3C40
    adds r0, r7, #0
    adds r1, r4, #0
    bl IsAlbumAvailable__C3VanUi
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_3C28
    movs r3, #0
    mov sb, r3
.LscriptCall_3C40:
    ldr r1, [r6]
    cmp r1, #0x63
    bls .LscriptCall_3C4A
    bl .LscriptCall_5C96
.LscriptCall_3C4A:
    lsls r0, r1, #2
    add r0, r8
    mov r4, sb
    str r4, [r0]
    bl .LscriptCall_5150
.LscriptCall_3C56:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_3C72
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_3C72:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_3C84
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_3C84:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3C94
    bl .LscriptCall_1DAE
.LscriptCall_3C94:
    bl OpenNameEntry__9GameScene17MaryNameEntryKindi
    bl .LscriptCall_1DAE
.LscriptCall_3C9C:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    adds r0, #0x14
    bl HasGoldenLumber__C4Farm
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    bl .LscriptCall_5BCC
.LscriptCall_3CB2:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r1, [r3]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r2, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_3CC8
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_3CC8:
    ldr r0, [r5, #0x10]
    cmp r2, r0
    bhi .LscriptCall_3CDC
    ldr r1, [r5, #0x14]
    lsls r0, r2, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r4, r1, r0
    b .LscriptCall_3CDE
.LscriptCall_3CDC:
    ldr r4, .LscriptCall_3D14 @ =gText_ScriptEngineUi_Error
.LscriptCall_3CDE:
    adds r0, r4, #0
    bl strlen
    cmp r0, #1
    bls .LscriptCall_3D20
    ldrb r0, [r4]
    lsls r0, r0, #8
    ldrb r1, [r4, #1]
    adds r0, r0, r1
    ldr r1, .LscriptCall_3D18 @ =0x0000FF21
    cmp r0, r1
    bne .LscriptCall_3D20
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r4, [r0]
    ldr r2, .LscriptCall_3D1C @ =0x00001BD8
    adds r4, r4, r2
    adds r0, r4, #0
    bl GetName__C6Farmer
    adds r1, r0, #0
    adds r0, r4, #0
    bl SetSpouseNickname__6FarmerPCc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_3D14: .word gText_ScriptEngineUi_Error
.LscriptCall_3D18: .word 0x0000FF21
.LscriptCall_3D1C: .word 0x00001BD8
.LscriptCall_3D20:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r6, .LscriptCall_3D38 @ =0x00001BD8
    adds r0, r0, r6
    adds r1, r4, #0
    bl SetSpouseNickname__6FarmerPCc
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_3D38: .word 0x00001BD8
.LscriptCall_3D3C:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3D4C
    bl .LscriptCall_5C96
.LscriptCall_3D4C:
    bl EnableScriptedNpcControl__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_3D54:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3D64
    bl .LscriptCall_5C96
.LscriptCall_3D64:
    bl DisableScriptedNpcControl__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_3D6C:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_3D82
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_3D82:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3D92
    bl .LscriptCall_5C96
.LscriptCall_3D92:
    bl LightFireplaceAtLocation__9GameScene9MaryMapId
    bl .LscriptCall_5C96
.LscriptCall_3D9A:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    ldr r3, [r1]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r2, r0
    ldr r4, [r0]
    adds r6, r1, #0
    mov r8, r2
    cmp r3, #0
    beq .LscriptCall_3DBA
    subs r0, r3, #1
    str r0, [r6]
.LscriptCall_3DBA:
    cmp r4, #0x1d
    beq .LscriptCall_3DDE
    cmp r4, #0x1d
    bgt .LscriptCall_3DC8
    cmp r4, #0x12
    beq .LscriptCall_3E08
    b .LscriptCall_3DCC
.LscriptCall_3DC8:
    cmp r4, #0x27
    beq .LscriptCall_3E16
.LscriptCall_3DCC:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3DD6
    bl .LscriptCall_5C96
.LscriptCall_3DD6:
    lsls r0, r3, #2
    add r0, r8
    movs r1, #0
    b .LscriptCall_3E32
.LscriptCall_3DDE:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl IsFireplaceLighted__C9FarmHouse
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r1, [r6]
    cmp r1, #0x63
    bls .LscriptCall_3DFE
    bl .LscriptCall_5C96
.LscriptCall_3DFE:
    lsls r0, r1, #2
    add r0, r8
    str r2, [r0]
    bl .LscriptCall_5150
.LscriptCall_3E08:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldrb r0, [r0, #3]
    lsrs r1, r0, #7
    b .LscriptCall_3E24
.LscriptCall_3E16:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x1f
    lsrs r1, r0, #0x1f
.LscriptCall_3E24:
    ldr r3, [r6]
    cmp r3, #0x63
    bls .LscriptCall_3E2E
    bl .LscriptCall_5C96
.LscriptCall_3E2E:
    lsls r0, r3, #2
    add r0, r8
.LscriptCall_3E32:
    str r1, [r0]
    adds r0, r3, #1
    str r0, [r6]
    bl .LscriptCall_5C96
.LscriptCall_3E3C:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_3E52
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_3E52:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3E62
    bl .LscriptCall_5C96
.LscriptCall_3E62:
    bl SetVaseArticleId__9GameScene17MaryItemArticleId
    bl .LscriptCall_5C96
.LscriptCall_3E6A:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r4, r5, r3
    ldr r0, [r4]
    movs r6, #0xfa
    lsls r6, r6, #1
    adds r0, r0, r6
    bl GetVaseArticleId__C9FarmHouse
    cmp r0, #0x5f
    bne .LscriptCall_3EA0
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r3, [r2]
    cmp r3, #0x63
    bls .LscriptCall_3E94
    bl .LscriptCall_5C96
.LscriptCall_3E94:
    lsls r0, r3, #2
    adds r0, r1, r0
    movs r1, #1
    rsbs r1, r1, #0
    bl .LscriptCall_5C3A
.LscriptCall_3EA0:
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl GetVaseArticleId__C9FarmHouse
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_3EBC:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_3ED2
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_3ED2:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_3EE2
    bl .LscriptCall_5C96
.LscriptCall_3EE2:
    bl BeginEggIncubation__9GameScene29MaryChickenCoopIncubatorIndex
    bl .LscriptCall_5C96
.LscriptCall_3EEA:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_3F06
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_3F06:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0x82
    lsls r3, r3, #3
    adds r0, r0, r3
    bl IsIncubatorOccupied__C4CoopUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_3F20:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_3F40 @ =0x00001DAC
    adds r0, r0, r6
    bl GetOrder__C7Saibara
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3F40: .word 0x00001DAC
.LscriptCall_3F44:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_3F68 @ =0x00001DAC
    adds r0, r0, r2
    bl IsOrderComplete__C7Saibara
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_3F68: .word 0x00001DAC
.LscriptCall_3F6C:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_3F94 @ =0x00001DAC
    adds r0, r0, r6
    bl GetOrder__C7Saibara
    mov sl, r0
    movs r6, #0x51
    movs r7, #0x5f
    subs r0, #1
    cmp r0, #0x24
    bls .LscriptCall_3F8A
    b .LscriptCall_42C6
.LscriptCall_3F8A:
    lsls r0, r0, #2
    ldr r1, .LscriptCall_3F98 @ =.LscriptCall_3F9C
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_3F94: .word 0x00001DAC
.LscriptCall_3F98: .word .LscriptCall_3F9C
.LscriptCall_3F9C: @ jump table
    .word .LscriptCall_4030 @ case 0
    .word .LscriptCall_4030 @ case 1
    .word .LscriptCall_4030 @ case 2
    .word .LscriptCall_4030 @ case 3
    .word .LscriptCall_4030 @ case 4
    .word .LscriptCall_409C @ case 5
    .word .LscriptCall_409C @ case 6
    .word .LscriptCall_409C @ case 7
    .word .LscriptCall_409C @ case 8
    .word .LscriptCall_409C @ case 9
    .word .LscriptCall_4108 @ case 10
    .word .LscriptCall_4108 @ case 11
    .word .LscriptCall_4108 @ case 12
    .word .LscriptCall_4108 @ case 13
    .word .LscriptCall_4108 @ case 14
    .word .LscriptCall_4174 @ case 15
    .word .LscriptCall_4174 @ case 16
    .word .LscriptCall_4174 @ case 17
    .word .LscriptCall_4174 @ case 18
    .word .LscriptCall_4174 @ case 19
    .word .LscriptCall_41E0 @ case 20
    .word .LscriptCall_41E0 @ case 21
    .word .LscriptCall_41E0 @ case 22
    .word .LscriptCall_41E0 @ case 23
    .word .LscriptCall_41E0 @ case 24
    .word .LscriptCall_424C @ case 25
    .word .LscriptCall_424C @ case 26
    .word .LscriptCall_424C @ case 27
    .word .LscriptCall_424C @ case 28
    .word .LscriptCall_424C @ case 29
    .word .LscriptCall_42B8 @ case 30
    .word .LscriptCall_42BC @ case 31
    .word .LscriptCall_42C0 @ case 32
    .word .LscriptCall_42C4 @ case 33
    .word .LscriptCall_42C6 @ case 34
    .word .LscriptCall_42C6 @ case 35
    .word .LscriptCall_42C6 @ case 36
.LscriptCall_4030:
    adds r0, r5, #0
    movs r1, #0
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_407C
    mov r0, sl
    subs r0, #1
    cmp r0, #4
    bhi .LscriptCall_4068
    lsls r0, r0, #2
    ldr r1, .LscriptCall_4050 @ =.LscriptCall_4054
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_4050: .word .LscriptCall_4054
.LscriptCall_4054: @ jump table
    .word .LscriptCall_4068 @ case 0
    .word .LscriptCall_406C @ case 1
    .word .LscriptCall_4070 @ case 2
    .word .LscriptCall_4074 @ case 3
    .word .LscriptCall_4078 @ case 4
.LscriptCall_4068:
    movs r6, #1
    b .LscriptCall_42C6
.LscriptCall_406C:
    movs r6, #2
    b .LscriptCall_42C6
.LscriptCall_4070:
    movs r6, #3
    b .LscriptCall_42C6
.LscriptCall_4074:
    movs r6, #4
    b .LscriptCall_42C6
.LscriptCall_4078:
    movs r6, #7
    b .LscriptCall_42C6
.LscriptCall_407C:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_4098 @ =0x00001BD8
    adds r0, r0, r2
    movs r1, #1
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #0
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_4098: .word 0x00001BD8
.LscriptCall_409C:
    adds r0, r5, #0
    movs r1, #8
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_40E8
    mov r0, sl
    subs r0, #6
    cmp r0, #4
    bhi .LscriptCall_40D4
    lsls r0, r0, #2
    ldr r1, .LscriptCall_40BC @ =.LscriptCall_40C0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_40BC: .word .LscriptCall_40C0
.LscriptCall_40C0: @ jump table
    .word .LscriptCall_40D4 @ case 0
    .word .LscriptCall_40D8 @ case 1
    .word .LscriptCall_40DC @ case 2
    .word .LscriptCall_40E0 @ case 3
    .word .LscriptCall_40E4 @ case 4
.LscriptCall_40D4:
    movs r6, #9
    b .LscriptCall_42C6
.LscriptCall_40D8:
    movs r6, #0xa
    b .LscriptCall_42C6
.LscriptCall_40DC:
    movs r6, #0xb
    b .LscriptCall_42C6
.LscriptCall_40E0:
    movs r6, #0xc
    b .LscriptCall_42C6
.LscriptCall_40E4:
    movs r6, #0xf
    b .LscriptCall_42C6
.LscriptCall_40E8:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_4104 @ =0x00001BD8
    adds r0, r0, r4
    movs r1, #0
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #8
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_4104: .word 0x00001BD8
.LscriptCall_4108:
    adds r0, r5, #0
    movs r1, #0x10
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_4154
    mov r0, sl
    subs r0, #0xb
    cmp r0, #4
    bhi .LscriptCall_4140
    lsls r0, r0, #2
    ldr r1, .LscriptCall_4128 @ =.LscriptCall_412C
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_4128: .word .LscriptCall_412C
.LscriptCall_412C: @ jump table
    .word .LscriptCall_4140 @ case 0
    .word .LscriptCall_4144 @ case 1
    .word .LscriptCall_4148 @ case 2
    .word .LscriptCall_414C @ case 3
    .word .LscriptCall_4150 @ case 4
.LscriptCall_4140:
    movs r6, #0x11
    b .LscriptCall_42C6
.LscriptCall_4144:
    movs r6, #0x12
    b .LscriptCall_42C6
.LscriptCall_4148:
    movs r6, #0x13
    b .LscriptCall_42C6
.LscriptCall_414C:
    movs r6, #0x14
    b .LscriptCall_42C6
.LscriptCall_4150:
    movs r6, #0x17
    b .LscriptCall_42C6
.LscriptCall_4154:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    ldr r1, .LscriptCall_4170 @ =0x00001BD8
    adds r0, r0, r1
    movs r1, #2
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #0x10
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_4170: .word 0x00001BD8
.LscriptCall_4174:
    adds r0, r5, #0
    movs r1, #0x18
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_41C0
    mov r0, sl
    subs r0, #0x10
    cmp r0, #4
    bhi .LscriptCall_41AC
    lsls r0, r0, #2
    ldr r1, .LscriptCall_4194 @ =.LscriptCall_4198
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_4194: .word .LscriptCall_4198
.LscriptCall_4198: @ jump table
    .word .LscriptCall_41AC @ case 0
    .word .LscriptCall_41B0 @ case 1
    .word .LscriptCall_41B4 @ case 2
    .word .LscriptCall_41B8 @ case 3
    .word .LscriptCall_41BC @ case 4
.LscriptCall_41AC:
    movs r6, #0x19
    b .LscriptCall_42C6
.LscriptCall_41B0:
    movs r6, #0x1a
    b .LscriptCall_42C6
.LscriptCall_41B4:
    movs r6, #0x1b
    b .LscriptCall_42C6
.LscriptCall_41B8:
    movs r6, #0x1c
    b .LscriptCall_42C6
.LscriptCall_41BC:
    movs r6, #0x1f
    b .LscriptCall_42C6
.LscriptCall_41C0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_41DC @ =0x00001BD8
    adds r0, r0, r3
    movs r1, #3
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #0x18
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_41DC: .word 0x00001BD8
.LscriptCall_41E0:
    adds r0, r5, #0
    movs r1, #0x20
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_422C
    mov r0, sl
    subs r0, #0x15
    cmp r0, #4
    bhi .LscriptCall_4218
    lsls r0, r0, #2
    ldr r1, .LscriptCall_4200 @ =.LscriptCall_4204
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_4200: .word .LscriptCall_4204
.LscriptCall_4204: @ jump table
    .word .LscriptCall_4218 @ case 0
    .word .LscriptCall_421C @ case 1
    .word .LscriptCall_4220 @ case 2
    .word .LscriptCall_4224 @ case 3
    .word .LscriptCall_4228 @ case 4
.LscriptCall_4218:
    movs r6, #0x21
    b .LscriptCall_42C6
.LscriptCall_421C:
    movs r6, #0x22
    b .LscriptCall_42C6
.LscriptCall_4220:
    movs r6, #0x23
    b .LscriptCall_42C6
.LscriptCall_4224:
    movs r6, #0x24
    b .LscriptCall_42C6
.LscriptCall_4228:
    movs r6, #0x27
    b .LscriptCall_42C6
.LscriptCall_422C:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_4248 @ =0x00001BD8
    adds r0, r0, r6
    movs r1, #4
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #0x20
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_4248: .word 0x00001BD8
.LscriptCall_424C:
    adds r0, r5, #0
    movs r1, #0x28
    bl func_0804E354
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_4298
    mov r0, sl
    subs r0, #0x1a
    cmp r0, #4
    bhi .LscriptCall_4284
    lsls r0, r0, #2
    ldr r1, .LscriptCall_426C @ =.LscriptCall_4270
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_426C: .word .LscriptCall_4270
.LscriptCall_4270: @ jump table
    .word .LscriptCall_4284 @ case 0
    .word .LscriptCall_4288 @ case 1
    .word .LscriptCall_428C @ case 2
    .word .LscriptCall_4290 @ case 3
    .word .LscriptCall_4294 @ case 4
.LscriptCall_4284:
    movs r6, #0x29
    b .LscriptCall_42C6
.LscriptCall_4288:
    movs r6, #0x2a
    b .LscriptCall_42C6
.LscriptCall_428C:
    movs r6, #0x2b
    b .LscriptCall_42C6
.LscriptCall_4290:
    movs r6, #0x2c
    b .LscriptCall_42C6
.LscriptCall_4294:
    movs r6, #0x2f
    b .LscriptCall_42C6
.LscriptCall_4298:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_42B4 @ =0x00001BD8
    adds r0, r0, r2
    movs r1, #5
    bl func_0800EB2C
    bl func_0800EFD8
    movs r6, #0x28
    b .LscriptCall_42C6
    .align 2, 0
.LscriptCall_42B4: .word 0x00001BD8
.LscriptCall_42B8:
    movs r7, #0x2c
    b .LscriptCall_42C6
.LscriptCall_42BC:
    movs r7, #0x2d
    b .LscriptCall_42C6
.LscriptCall_42C0:
    movs r7, #0x2e
    b .LscriptCall_42C6
.LscriptCall_42C4:
    movs r7, #0x2f
.LscriptCall_42C6:
    movs r3, #3
    mov sb, r3
    movs r4, #0
    mov r8, r4
    cmp r6, #0x51
    bne .LscriptCall_42D4
    b .LscriptCall_442A
.LscriptCall_42D4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_4314 @ =0x00001C34
    adds r7, r0, r2
    adds r0, r7, #0
    bl IsEmpty__C9ToolStack
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_4318
    add r4, sp, #0x30
    adds r0, r4, #0
    adds r1, r6, #0
    bl __4ToolUi
    ldrb r1, [r4]
    add r0, sp, #0xc
    movs r2, #1
    bl __9ToolStackG4ToolUi
    adds r0, r7, #0
    add r1, sp, #0xc
    movs r2, #2
    bl memcpy
    movs r3, #0
    mov sb, r3
    movs r4, #1
    mov r8, r4
    b .LscriptCall_439C
    .align 2, 0
.LscriptCall_4314: .word 0x00001C34
.LscriptCall_4318:
    movs r4, #0
    adds r0, r7, #0
    bl GetTool__C9ToolStack
    adds r1, r0, #0
    mov r0, sp
    adds r0, #0x31
    strb r1, [r0]
    bl GetId__C4Tool
    cmp r0, r6
    bne .LscriptCall_433C
    adds r0, r7, #0
    bl GetAmount__C9ToolStack
    cmp r0, #0x62
    bhi .LscriptCall_433C
    movs r4, #1
.LscriptCall_433C:
    cmp r4, #0
    beq .LscriptCall_4352
    adds r0, r7, #0
    movs r1, #1
    bl AddAmount__9ToolStackUi
    movs r6, #0
    mov sb, r6
    movs r0, #1
    mov r8, r0
    b .LscriptCall_439C
.LscriptCall_4352:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r4, r5, r1
    ldr r0, [r4]
    ldr r2, .LscriptCall_4374 @ =0x00001C38
    adds r0, r0, r2
    adds r1, r6, #0
    movs r2, #1
    bl AddAmountOfTool__8RucksackUiUi
    cmp r0, #0
    bne .LscriptCall_4378
    movs r3, #1
    mov sb, r3
    mov r8, r3
    b .LscriptCall_439C
    .align 2, 0
.LscriptCall_4374: .word 0x00001C38
.LscriptCall_4378:
    ldr r0, [r4]
    movs r4, #0xe0
    lsls r4, r4, #2
    adds r0, r0, r4
    adds r1, r6, #0
    movs r2, #1
    bl AddAmountOf__9ToolChestUiUi
    cmp r0, #0
    bne .LscriptCall_4394
    movs r6, #2
    mov sb, r6
    movs r0, #1
    mov r8, r0
.LscriptCall_4394:
    mov r1, r8
    cmp r1, #0
    bne .LscriptCall_439C
    b .LscriptCall_44BC
.LscriptCall_439C:
    mov r0, sl
    subs r0, #5
    cmp r0, #0x19
    bls .LscriptCall_43A6
    b .LscriptCall_44A6
.LscriptCall_43A6:
    lsls r0, r0, #2
    ldr r1, .LscriptCall_43B0 @ =.LscriptCall_43B4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_43B0: .word .LscriptCall_43B4
.LscriptCall_43B4: @ jump table
    .word .LscriptCall_441C @ case 0
    .word .LscriptCall_44A6 @ case 1
    .word .LscriptCall_44A6 @ case 2
    .word .LscriptCall_44A6 @ case 3
    .word .LscriptCall_44A6 @ case 4
    .word .LscriptCall_441C @ case 5
    .word .LscriptCall_44A6 @ case 6
    .word .LscriptCall_44A6 @ case 7
    .word .LscriptCall_44A6 @ case 8
    .word .LscriptCall_44A6 @ case 9
    .word .LscriptCall_441C @ case 10
    .word .LscriptCall_44A6 @ case 11
    .word .LscriptCall_44A6 @ case 12
    .word .LscriptCall_44A6 @ case 13
    .word .LscriptCall_44A6 @ case 14
    .word .LscriptCall_441C @ case 15
    .word .LscriptCall_44A6 @ case 16
    .word .LscriptCall_44A6 @ case 17
    .word .LscriptCall_44A6 @ case 18
    .word .LscriptCall_44A6 @ case 19
    .word .LscriptCall_441C @ case 20
    .word .LscriptCall_44A6 @ case 21
    .word .LscriptCall_44A6 @ case 22
    .word .LscriptCall_44A6 @ case 23
    .word .LscriptCall_44A6 @ case 24
    .word .LscriptCall_441C @ case 25
.LscriptCall_441C:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    bl SetFlag3__18GameStateSaveImage
    b .LscriptCall_44A6
.LscriptCall_442A:
    cmp r7, #0x5f
    beq .LscriptCall_44A2
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r4, r5, r3
    ldr r0, [r4]
    ldr r1, .LscriptCall_4460 @ =0x00001C2C
    adds r6, r0, r1
    adds r0, r6, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    beq .LscriptCall_4464
    mov r4, sp
    adds r4, #0x32
    adds r0, r4, #0
    adds r1, r7, #0
    bl __7ArticleUi
    ldrb r1, [r4]
    adds r0, r6, #0
    bl func_0800F3E8
    movs r2, #0
    mov sb, r2
    b .LscriptCall_44AC
    .align 2, 0
.LscriptCall_4460: .word 0x00001C2C
.LscriptCall_4464:
    ldr r0, [r4]
    ldr r3, .LscriptCall_447C @ =0x00001C38
    adds r0, r0, r3
    adds r1, r7, #0
    movs r2, #1
    bl AddAmountOfArticle__8RucksackUiUi
    cmp r0, #0
    bne .LscriptCall_4480
    movs r4, #1
    mov sb, r4
    b .LscriptCall_44AC
    .align 2, 0
.LscriptCall_447C: .word 0x00001C38
.LscriptCall_4480:
    ldr r0, [r4]
    movs r6, #0xfa
    lsls r6, r6, #1
    adds r0, r0, r6
    bl GetShelf__9FarmHouse
    cmp r0, #0
    beq .LscriptCall_44A6
    adds r1, r7, #0
    movs r2, #1
    bl AddAmountOf__5ShelfUiUi
    cmp r0, #0
    bne .LscriptCall_44A6
    movs r0, #2
    mov sb, r0
    b .LscriptCall_44AC
.LscriptCall_44A2:
    movs r1, #1
    mov r8, r1
.LscriptCall_44A6:
    mov r2, r8
    cmp r2, #0
    beq .LscriptCall_44BC
.LscriptCall_44AC:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_44DC @ =0x00001DAC
    adds r0, r0, r4
    bl CollectOrder__7Saibara
.LscriptCall_44BC:
    adds r2, r5, #0
    adds r2, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r1, r5, r6
    ldr r3, [r1]
    cmp r3, #0x63
    bls .LscriptCall_44D0
    bl .LscriptCall_5C96
.LscriptCall_44D0:
    lsls r0, r3, #2
    adds r0, r2, r0
    mov r2, sb
    str r2, [r0]
    bl .LscriptCall_5BE2
    .align 2, 0
.LscriptCall_44DC: .word 0x00001DAC
.LscriptCall_44E0:
    adds r3, r5, #0
    adds r3, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r4, r5, r6
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_44FC
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_44FC:
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r3, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_450E
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_450E:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r5, [r0]
    cmp r5, #0
    bne .LscriptCall_451E
    bl .LscriptCall_5C96
.LscriptCall_451E:
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    add r1, sp, #0x34
    movs r0, #0x1f
    ands r3, r0
    ldrb r4, [r1]
    subs r0, #0x3f
    ands r0, r4
    orrs r0, r3
    strb r0, [r1]
    movs r0, #0x3f
    ands r2, r0
    lsls r2, r2, #5
    ldrh r3, [r1]
    ldr r0, .LscriptCall_4550 @ =0xFFFFF81F
    ands r0, r3
    orrs r0, r2
    strh r0, [r1]
    adds r0, r5, #0
    bl SetGameTime__9GameSceneRC8GameTime
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_4550: .word 0xFFFFF81F
.LscriptCall_4554:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_4570
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_4570:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    bl method_0800BD14__C12Unk_0800BC58Ui
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_458A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_45A6
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_45A6:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r0, r3
    bl method_0800BD40__C12Unk_0800BC58Ui
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_45C0:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_45D6
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_45D6:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    bl method_0800BCB0__12Unk_0800BC58Ui
    bl .LscriptCall_5C96
.LscriptCall_45EC:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_4602
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_4602:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    bl method_0800BCD0__12Unk_0800BC58Ui
    bl .LscriptCall_5C96
.LscriptCall_4618:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r0, r4
    bl method_0800BD6C__C12Unk_0800BC58
    bl .LscriptCall_5BCA
.LscriptCall_462E:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    bl method_0800BDEC__C12Unk_0800BC58
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_4650:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r6, r5, r4
    ldr r0, [r6]
    cmp r0, #0
    bne .LscriptCall_4660
    bl .LscriptCall_5C96
.LscriptCall_4660:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetUpgradeLevel__C9FarmHouse
    ldr r2, [r6]
    ldr r1, .LscriptCall_469C @ =gFarmHouseBedXPositions
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    adds r0, r2, #0
    movs r1, #0x1d
    adds r2, r4, #0
    movs r3, #0x70
    bl ChangeMap__9GameSceneUiii
    ldr r0, [r6]
    movs r1, #2
    str r1, [sp]
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x70
    bl SetEntityPosition__9GameSceneUiiiUi
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_469C: .word gFarmHouseBedXPositions
.LscriptCall_46A0:
    adds r4, r5, #0
    adds r4, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r3, r5, r6
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_46BC
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_46BC:
    ldr r1, [r3]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r1, #0
    beq .LscriptCall_46CE
    subs r0, r1, #1
    str r0, [r3]
.LscriptCall_46CE:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_46E0
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_46E0:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r2, [r0]
    cmp r2, #0
    bne .LscriptCall_46F0
    bl .LscriptCall_1DAE
.LscriptCall_46F0:
    lsls r0, r6, #5
    orrs r1, r0
    lsls r0, r7, #0xa
    orrs r1, r0
    adds r0, r2, #0
    bl FlashScreenColor__9GameSceneUi
    bl .LscriptCall_1DAE
.LscriptCall_4702:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    bl IsPlayerHoldingTool__9GameScene
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    bl .LscriptCall_5BCC
.LscriptCall_4716:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4732
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4732:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4744
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4744:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4754
    bl .LscriptCall_5C96
.LscriptCall_4754:
    bl GenerateMineFloorLayout
    bl .LscriptCall_5C96
.LscriptCall_475C:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_476C
    bl .LscriptCall_5C96
.LscriptCall_476C:
    bl RebuildMapEntitiesForNewDay__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_4774:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_4790
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_4790:
    adds r0, r5, #0
    bl func_0804E0F8
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_479E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_47BA
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_47BA:
    adds r0, r5, #0
    bl func_0804E17C
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_47C8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_47E4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_47E4:
    adds r0, r5, #0
    bl func_0804E1D4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_47F2:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_480E
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_480E:
    adds r0, r5, #0
    bl func_0804E354
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_481C:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_4838
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_4838:
    adds r0, r5, #0
    bl func_0804E2C0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4846:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_4862
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_4862:
    adds r0, r5, #0
    bl func_0804E22C
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4870:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_4884 @ =0x000034C5
    adds r0, r0, r3
    movs r1, #1
    strb r1, [r0]
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_4884: .word 0x000034C5
.LscriptCall_4888:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_48A4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_48A4:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r5, r5, r1
    ldr r0, [r5]
    adds r0, #0x54
    adds r1, r7, #0
    bl IsDisplayEnabled__C11ShippingBini
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne .LscriptCall_48C0
    bl .LscriptCall_588A
.LscriptCall_48C0:
    ldr r0, [r5]
    adds r0, #0x54
    adds r1, r7, #0
    bl GetAmountShipped__C11ShippingBini
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_48D0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    bl CountCows__C4Barn
    bl .LscriptCall_5BCA
.LscriptCall_48E6:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl CountSheeps__C4Barn
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_4908:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0x82
    lsls r6, r6, #3
    adds r0, r0, r6
    bl CountChickens__C4Coop
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_492A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_4954 @ =0x00001BD8
    adds r0, r0, r2
    bl func_0800ED14
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_494A
    bl .LscriptCall_1DAE
.LscriptCall_494A:
    bl GivePlayerBasket__9GameScene
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_4954: .word 0x00001BD8
.LscriptCall_4958:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    ldr r6, .LscriptCall_497C @ =0x00001BD8
    adds r0, r0, r6
    bl func_0800E934
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
    .align 2, 0
.LscriptCall_497C: .word 0x00001BD8
.LscriptCall_4980:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_4994 @ =0x00001C38
    adds r0, r0, r2
    bl Upgrade__8Rucksack
    bl .LscriptCall_5C96
    .align 2, 0
.LscriptCall_4994: .word 0x00001C38
.LscriptCall_4998:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_49AC @ =0x00001C38
    adds r0, r0, r4
    bl GetUpgradeLevel__C8Rucksack
    bl .LscriptCall_5BCA
    .align 2, 0
.LscriptCall_49AC: .word 0x00001C38
.LscriptCall_49B0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_49CC
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_49CC:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_49DE
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_49DE:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_49EE
    bl .LscriptCall_5C96
.LscriptCall_49EE:
    bl ChangePlayerStaminaAndFatigue__9GameSceneii
    bl .LscriptCall_5C96
.LscriptCall_49F6:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4A06
    bl .LscriptCall_5C96
.LscriptCall_4A06:
    bl RefreshAllNpcSchedules__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_4A0E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4A2A
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4A2A:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4A3C
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4A3C:
    adds r0, r5, #0
    bl func_0804E3D8
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
    ldr r2, [r4]
    cmp r2, #0x63
    bls .LscriptCall_4A52
    bl .LscriptCall_5C96
.LscriptCall_4A52:
    lsls r0, r2, #2
    adds r0, r6, r0
    bl .LscriptCall_541A
.LscriptCall_4A5A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r2, r5, r1
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_4A78
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_4A78:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_4A8C
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_4A8C:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_4A9E
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_4A9E:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_4AB0
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_4AB0:
    ldr r4, [r2]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r4, #0
    beq .LscriptCall_4AC2
    subs r0, r4, #1
    str r0, [r2]
.LscriptCall_4AC2:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4AD2
    bl .LscriptCall_5C96
.LscriptCall_4AD2:
    mov r4, r8
    str r4, [sp]
    mov r6, sb
    str r6, [sp, #4]
    adds r2, r7, #0
    bl CreateFarmHorse__9GameScene8MaryBool23MaryAnimalHorseAgeStage9MaryMapIdii
    bl .LscriptCall_5C96
.LscriptCall_4AE4:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4B00
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4B00:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4B12
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4B12:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4B22
    bl .LscriptCall_5C96
.LscriptCall_4B22:
    bl RemoveFarmHorse__9GameScene8MaryBooli
    bl .LscriptCall_5C96
.LscriptCall_4B2A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4B46
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4B46:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4B58
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4B58:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r3, #0
    beq .LscriptCall_4B6A
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4B6A:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r1, r0, #0
    cmp r1, #0
    bne .LscriptCall_4B7A
    bl .LscriptCall_5C96
.LscriptCall_4B7A:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r4, [r0]
    cmp r4, #0
    bne .LscriptCall_4B8A
    bl .LscriptCall_5C96
.LscriptCall_4B8A:
    adds r0, r1, #0
    bl GetName__C6Animal
    adds r2, r0, #0
    bl .LscriptCall_54AA
.LscriptCall_4B96:
    movs r4, #0
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4BA8
    bl .LscriptCall_5BCC
.LscriptCall_4BA8:
    bl GetInteractingAnimalIndex__9GameScene
    bl .LscriptCall_5BCA
.LscriptCall_4BB0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4BCC
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4BCC:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4BDE
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4BDE:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4BEE
    bl .LscriptCall_588A
.LscriptCall_4BEE:
    bl HasBeenTalkedTo__C6Animal
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4BFA:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4C16
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4C16:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4C28
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4C28:
    adds r0, r5, #0
    bl func_0804E3D8
    cmp r0, #0
    bne .LscriptCall_4C36
    bl .LscriptCall_5C96
.LscriptCall_4C36:
    bl SetTalkedTo__6Animal
    bl .LscriptCall_5C96
.LscriptCall_4C3E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4C5A
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4C5A:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4C6C
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4C6C:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4C7C
    bl .LscriptCall_588A
.LscriptCall_4C7C:
    bl GetAge__C6Animal
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_4C86:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r2, #0
    beq .LscriptCall_4CA2
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_4CA2:
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4CB4
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4CB4:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4CC6
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4CC6:
    adds r0, r5, #0
    bl func_0804E3D8
    cmp r0, #0
    bne .LscriptCall_4CD4
    bl .LscriptCall_5C96
.LscriptCall_4CD4:
    adds r1, r7, #0
    bl AddAffection__6Animali
    bl .LscriptCall_5C96
.LscriptCall_4CDE:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4CFA
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4CFA:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4D0C
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4D0C:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4D1C
    bl .LscriptCall_588A
.LscriptCall_4D1C:
    bl IsUnhappy__C9Livestock
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4D28:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4D44
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4D44:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4D56
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4D56:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4D66
    bl .LscriptCall_588A
.LscriptCall_4D66:
    bl IsSick__C9Livestock
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4D72:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r4, r5, r2
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4D8E
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4D8E:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4DA0
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4DA0:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4DB0
    bl .LscriptCall_588A
.LscriptCall_4DB0:
    bl IsPregnant__C10BarnAnimal
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4DBC:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4DD8
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4DD8:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4DEA
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4DEA:
    adds r0, r5, #0
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4DFA
    bl .LscriptCall_588A
.LscriptCall_4DFA:
    bl GetDaysPregnantHealthy__C10BarnAnimal
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_4E04:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4E20
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4E20:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4E32
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4E32:
    adds r0, r5, #0
    bl func_0804E3D8
    movs r2, #0
    cmp r0, #0
    bne .LscriptCall_4E42
    bl .LscriptCall_588A
.LscriptCall_4E42:
    bl GetAffection__C6Animal
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_4E4C:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r3, [r1]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r2, r0
    ldr r4, [r0]
    adds r6, r1, #0
    mov r8, r2
    cmp r3, #0
    beq .LscriptCall_4E6C
    subs r0, r3, #1
    str r0, [r6]
.LscriptCall_4E6C:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    add r0, r8
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4E7E
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_4E7E:
    movs r7, #0
    cmp r2, #4
    bls .LscriptCall_4E86
    b .LscriptCall_5140
.LscriptCall_4E86:
    lsls r0, r2, #2
    ldr r1, .LscriptCall_4E90 @ =.LscriptCall_4E94
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_4E90: .word .LscriptCall_4E94
.LscriptCall_4E94: @ jump table
    .word .LscriptCall_4EA8 @ case 0
    .word .LscriptCall_4ED8 @ case 1
    .word .LscriptCall_4EF8 @ case 2
    .word .LscriptCall_4F18 @ case 3
    .word .LscriptCall_4EC2 @ case 4
.LscriptCall_4EA8:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    adds r0, #0x14
    bl GetHorse__4Farm
    cmp r0, #0
    bne .LscriptCall_4EBC
    b .LscriptCall_5140
.LscriptCall_4EBC:
    bl GetGrowthStage__C5Horse
    b .LscriptCall_4F36
.LscriptCall_4EC2:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_4ED4 @ =0x00001C70
    adds r0, r0, r2
    bl GetGrowthStage__C3Dog
    b .LscriptCall_4F36
    .align 2, 0
.LscriptCall_4ED4: .word 0x00001C70
.LscriptCall_4ED8:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetCow__4BarnUi
    cmp r0, #0
    bne .LscriptCall_4EF2
    b .LscriptCall_5140
.LscriptCall_4EF2:
    bl GetGrowthStage__C3Cow
    b .LscriptCall_4F36
.LscriptCall_4EF8:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    adds r1, r4, #0
    bl GetSheep__4BarnUi
    cmp r0, #0
    bne .LscriptCall_4F12
    b .LscriptCall_5140
.LscriptCall_4F12:
    bl GetGrowthStage__C5Sheep
    b .LscriptCall_4F36
.LscriptCall_4F18:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    bne .LscriptCall_4F32
    b .LscriptCall_5140
.LscriptCall_4F32:
    bl GetGrowthStage__C7Chicken
.LscriptCall_4F36:
    adds r7, r0, #0
    b .LscriptCall_5140
.LscriptCall_4F3A:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4F56
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4F56:
    adds r0, r5, #0
    movs r1, #2
    bl func_0804E3D8
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_4F68
    bl .LscriptCall_588A
.LscriptCall_4F68:
    bl IsSheared__C5Sheep
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    bl .LscriptCall_588A
.LscriptCall_4F74:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r1, [r4]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_4F90
    subs r0, r1, #1
    str r0, [r4]
.LscriptCall_4F90:
    ldr r3, [r4]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r3, #0
    beq .LscriptCall_4FA2
    subs r0, r3, #1
    str r0, [r4]
.LscriptCall_4FA2:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4FB2
    bl .LscriptCall_5C96
.LscriptCall_4FB2:
    bl SetContestAnimal__9GameScene14MaryAnimalKind19MaryAnimalSlotIndex
    bl .LscriptCall_5C96
.LscriptCall_4FBA:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_4FD0
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_4FD0:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_4FE0
    bl .LscriptCall_5C96
.LscriptCall_4FE0:
    bl ClearContestAnimal__9GameScene14MaryAnimalKind
    bl .LscriptCall_5C96
.LscriptCall_4FE8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r2, #0
    beq .LscriptCall_5004
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_5004:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    beq .LscriptCall_501E
    adds r0, r1, #0
    adds r1, r3, #0
    bl GetContestAnimalIndex__9GameScene14MaryAnimalKind
    adds r2, r0, #0
    bl .LscriptCall_588A
.LscriptCall_501E:
    ldr r3, [r4]
    cmp r3, #0x63
    bls .LscriptCall_5028
    bl .LscriptCall_5C96
.LscriptCall_5028:
    lsls r0, r3, #2
    adds r0, r6, r0
    str r1, [r0]
    adds r0, r3, #1
    str r0, [r4]
    bl .LscriptCall_5C96
.LscriptCall_5036:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r3, [r1]
    lsls r0, r3, #2
    subs r0, #4
    adds r0, r2, r0
    ldr r0, [r0]
    mov sb, r0
    adds r6, r1, #0
    mov r8, r2
    cmp r3, #0
    beq .LscriptCall_5058
    subs r0, r3, #1
    str r0, [r6]
.LscriptCall_5058:
    ldr r1, [r6]
    lsls r0, r1, #2
    subs r0, #4
    add r0, r8
    ldr r2, [r0]
    cmp r1, #0
    beq .LscriptCall_506A
    subs r0, r1, #1
    str r0, [r6]
.LscriptCall_506A:
    movs r7, #0
    cmp r2, #4
    bhi .LscriptCall_5140
    lsls r0, r2, #2
    ldr r1, .LscriptCall_507C @ =.LscriptCall_5080
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
.LscriptCall_507C: .word .LscriptCall_5080
.LscriptCall_5080: @ jump table
    .word .LscriptCall_5140 @ case 0
    .word .LscriptCall_5094 @ case 1
    .word .LscriptCall_50CE @ case 2
    .word .LscriptCall_5108 @ case 3
    .word .LscriptCall_5140 @ case 4
.LscriptCall_5094:
    movs r4, #0
    movs r0, #0xd4
    lsls r0, r0, #2
    adds r5, r5, r0
    b .LscriptCall_50BC
.LscriptCall_509E:
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetCow__4BarnUi
    cmp r0, #0
    beq .LscriptCall_50BA
    bl GetLifeState__C9Livestock
    cmp r0, sb
    bne .LscriptCall_50BA
    adds r7, #1
.LscriptCall_50BA:
    adds r4, #1
.LscriptCall_50BC:
    ldr r0, [r5]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Barn
    cmp r4, r0
    blo .LscriptCall_509E
    b .LscriptCall_5140
.LscriptCall_50CE:
    movs r4, #0
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r5, r5, r3
    b .LscriptCall_50F6
.LscriptCall_50D8:
    ldr r0, [r5]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetSheep__4BarnUi
    cmp r0, #0
    beq .LscriptCall_50F4
    bl GetLifeState__C9Livestock
    cmp r0, sb
    bne .LscriptCall_50F4
    adds r7, #1
.LscriptCall_50F4:
    adds r4, #1
.LscriptCall_50F6:
    ldr r0, [r5]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Barn
    cmp r4, r0
    blo .LscriptCall_50D8
    b .LscriptCall_5140
.LscriptCall_5108:
    movs r4, #0
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r5, r5, r3
    b .LscriptCall_5130
.LscriptCall_5112:
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #3
    adds r0, r0, r1
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    beq .LscriptCall_512E
    bl GetLifeState__C9Livestock
    cmp r0, sb
    bne .LscriptCall_512E
    adds r7, #1
.LscriptCall_512E:
    adds r4, #1
.LscriptCall_5130:
    ldr r0, [r5]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r0, r0, r2
    bl GetCapacity__C4Coop
    cmp r4, r0
    blo .LscriptCall_5112
.LscriptCall_5140:
    ldr r1, [r6]
    cmp r1, #0x63
    bls .LscriptCall_514A
    bl .LscriptCall_5C96
.LscriptCall_514A:
    lsls r0, r1, #2
    add r0, r8
    str r7, [r0]
.LscriptCall_5150:
    adds r0, r1, #1
    str r0, [r6]
    bl .LscriptCall_5C96
.LscriptCall_5158:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5168
    bl .LscriptCall_1DAE
.LscriptCall_5168:
    bl ShowLivestockNeglectDeathSummary
    bl .LscriptCall_1DAE
.LscriptCall_5170:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5180
    bl .LscriptCall_5C96
.LscriptCall_5180:
    bl RemoveLivestockDeadFromNeglect
    bl .LscriptCall_5C96
.LscriptCall_5188:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5198
    bl .LscriptCall_1DAE
.LscriptCall_5198:
    bl ShowNaturalLivestockDeathSummary
    bl .LscriptCall_1DAE
.LscriptCall_51A0:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_51B0
    bl .LscriptCall_5C96
.LscriptCall_51B0:
    bl RemoveNaturallyDeadLivestock
    bl .LscriptCall_5C96
.LscriptCall_51B8:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_51C8
    bl .LscriptCall_1DAE
.LscriptCall_51C8:
    bl ObtainPowerBerry__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_51D0:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_51E0
    bl .LscriptCall_1DAE
.LscriptCall_51E0:
    bl ObtainMysticBerry__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_51E8:
    movs r4, #0
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_51FE
    bl IsPlayerRidingHorse__9GameScene
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
.LscriptCall_51FE:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_520C:
    movs r4, #0
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5220
    bl GetPresentedItemKind__9GameScene
    adds r4, r0, #0
.LscriptCall_5220:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_522E:
    movs r4, #0
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5242
    bl GetPresentedItemId__9GameScene
    adds r4, r0, #0
.LscriptCall_5242:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_5250:
    movs r4, #0
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5264
    bl IsPresentedItemGiftWrapped__9GameScene
    adds r4, r0, #0
.LscriptCall_5264:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_5272:
    movs r4, #0xd4
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    movs r6, #0x82
    lsls r6, r6, #3
    adds r0, r0, r6
    bl GetIncubatorCapacity__C4Coop
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    bl .LscriptCall_5BD6
.LscriptCall_5294:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_52B0
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_52B0:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0x82
    lsls r3, r3, #3
    adds r0, r0, r3
    bl ShouldHatch__4CoopUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b .LscriptCall_588A
.LscriptCall_52C8:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_52E4
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_52E4:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0x82
    lsls r3, r3, #3
    adds r0, r0, r3
    bl AttemptHatch__4CoopUi
    adds r1, r0, #0
    ldr r2, [r4]
    cmp r2, #0x63
    bhi .LscriptCall_5308
    lsls r0, r2, #2
    adds r0, r6, r0
    str r1, [r0]
    adds r0, r2, #1
    str r0, [r4]
.LscriptCall_5308:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5318
    bl .LscriptCall_5C96
.LscriptCall_5318:
    adds r1, #0x2e
    bl RefreshEntity__9GameScene12MaryEntityId
    bl .LscriptCall_5C96
.LscriptCall_5322:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    movs r1, #0xbe
    lsls r1, r1, #3
    adds r0, r0, r1
    bl GetPregnancyStallCapacity__C4Barn
    adds r4, r0, #0
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    bl .LscriptCall_5BD6
.LscriptCall_5344:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_5360
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_5360:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    bl IsReadyToGiveBirth__C4BarnUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b .LscriptCall_588A
.LscriptCall_5378:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_5394
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_5394:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    bl AttemptBirth__4BarnUi
    adds r1, r0, #0
    ldr r2, [r4]
    cmp r2, #0x63
    bhi .LscriptCall_53B8
    lsls r0, r2, #2
    adds r0, r6, r0
    str r1, [r0]
    adds r0, r2, #1
    str r0, [r4]
.LscriptCall_53B8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_53C8
    bl .LscriptCall_5C96
.LscriptCall_53C8:
    adds r1, #0x36
    bl RefreshEntity__9GameScene12MaryEntityId
    bl .LscriptCall_5C96
.LscriptCall_53D2:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r2, #0
    beq .LscriptCall_53F0
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_53F0:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r5, r5, r1
    ldr r0, [r5]
    movs r2, #0xbe
    lsls r2, r2, #3
    adds r0, r0, r2
    mov r1, r8
    bl GetCow__4BarnUi
    adds r7, r0, #0
    cmp r7, #0
    beq .LscriptCall_5424
    ldr r2, [r4]
    cmp r2, #0x63
    bls .LscriptCall_5414
    bl .LscriptCall_5C96
.LscriptCall_5414:
    lsls r0, r2, #2
    adds r0, r6, r0
    movs r1, #1
.LscriptCall_541A:
    str r1, [r0]
    adds r0, r2, #1
    str r0, [r4]
    bl .LscriptCall_5C96
.LscriptCall_5424:
    ldr r0, [r5]
    movs r3, #0xbe
    lsls r3, r3, #3
    adds r0, r0, r3
    mov r1, r8
    bl GetSheep__4BarnUi
    adds r2, r0, #0
    cmp r2, #0
    bne .LscriptCall_543A
    b .LscriptCall_588A
.LscriptCall_543A:
    ldr r1, [r4]
    cmp r1, #0x63
    bls .LscriptCall_5444
    bl .LscriptCall_5C96
.LscriptCall_5444:
    lsls r0, r1, #2
    adds r0, r6, r0
    str r7, [r0]
    b .LscriptCall_5898
.LscriptCall_544C:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_545C
    bl .LscriptCall_5C96
.LscriptCall_545C:
    bl CreatePlayerChildEntity__9GameScene
    bl .LscriptCall_5C96
.LscriptCall_5464:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5474
    bl .LscriptCall_5C96
.LscriptCall_5474:
    bl DescendMineFloor
    bl .LscriptCall_5C96
.LscriptCall_547C:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r6, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_5492
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_5492:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r4, [r0]
    cmp r4, #0
    bne .LscriptCall_54A2
    bl .LscriptCall_5C96
.LscriptCall_54A2:
    adds r0, r4, #0
    bl GetCaughtFish__9GameScene
    ldr r2, [r0]
.LscriptCall_54AA:
    adds r0, r4, #0
    adds r1, r6, #0
    bl TextVariableSetString__9GameSceneUiPCc
    b .LscriptCall_5C96
.LscriptCall_54B4:
    movs r4, #0
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_54C8
    bl GetCaughtFish__9GameScene
    ldrh r4, [r0, #4]
.LscriptCall_54C8:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    b .LscriptCall_5BD6
.LscriptCall_54D4:
    movs r4, #0
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_54E8
    bl GetCaughtFish__9GameScene
    ldrb r4, [r0, #0x14]
.LscriptCall_54E8:
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r5, r0
    b .LscriptCall_5BD6
.LscriptCall_54F4:
    movs r4, #0
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5508
    bl GetCaughtFish__9GameScene
    ldrb r4, [r0, #0xd]
.LscriptCall_5508:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    b .LscriptCall_5BD6
.LscriptCall_5514:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r2, r5, r4
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r1, #0
    beq .LscriptCall_552A
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_552A:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_553A
    bl .LscriptCall_1DAE
.LscriptCall_553A:
    adds r2, r0, #0
    ldr r0, [r5, #0x10]
    cmp r3, r0
    bhi .LscriptCall_5550
    ldr r1, [r5, #0x14]
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    ldr r0, [r0]
    adds r1, r1, r0
    b .LscriptCall_5552
.LscriptCall_5550:
    ldr r1, .LscriptCall_555C @ =gText_ScriptEngineUi_Error
.LscriptCall_5552:
    adds r0, r2, #0
    bl TalkTelevisionMessage__9GameScenePCc
    bl .LscriptCall_1DAE
    .align 2, 0
.LscriptCall_555C: .word gText_ScriptEngineUi_Error
.LscriptCall_5560:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    bl SetFlag0__18GameStateSaveImage
    b .LscriptCall_5C96
.LscriptCall_556E:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    bl SetFlag2__18GameStateSaveImage
    b .LscriptCall_5C96
.LscriptCall_557C:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_5592
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_5592:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_55A0
    b .LscriptCall_5C96
.LscriptCall_55A0:
    bl OpenDoor__9GameScene13MaryDoorIndex
    b .LscriptCall_5C96
.LscriptCall_55A6:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_55BC
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_55BC:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_55CA
    b .LscriptCall_5C96
.LscriptCall_55CA:
    bl CloseDoor__9GameScene13MaryDoorIndex
    b .LscriptCall_5C96
.LscriptCall_55D0:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r4, r5, r3
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_55EC
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_55EC:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xd2
    lsls r3, r3, #6
    adds r0, r0, r3
    bl IsCursed__C15CursedToolStateUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b .LscriptCall_588A
.LscriptCall_5604:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_5620
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_5620:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xd2
    lsls r3, r3, #6
    adds r0, r0, r3
    bl AdvanceEquippedDays__15CursedToolStateUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b .LscriptCall_588A
.LscriptCall_5638:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r4, r5, r0
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_5654
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_5654:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    movs r3, #0xd2
    lsls r3, r3, #6
    adds r0, r0, r3
    bl AttemptChurchRemoval__15CursedToolStateUi
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b .LscriptCall_588A
.LscriptCall_566C:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_567A
    b .LscriptCall_5C96
.LscriptCall_567A:
    bl CreateNewYearSunriseEffect__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5680:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5690
    bl .LscriptCall_1DAE
.LscriptCall_5690:
    bl PlayNewYearSunriseEffect__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_5698:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_56A6
    b .LscriptCall_5C96
.LscriptCall_56A6:
    bl DestroyNewYearSunriseEffect__9GameScene
    b .LscriptCall_5C96
.LscriptCall_56AC:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_56BC
    bl .LscriptCall_1DAE
.LscriptCall_56BC:
    bl PlayStarSparkleEffect__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_56C4:
    movs r3, #0xd5
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_56D4
    bl EnterHotSpringBathingState__9GameScene
.LscriptCall_56D4:
    movs r0, #2
    b .LscriptCall_5C98
.LscriptCall_56D8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_56E6
    b .LscriptCall_5C96
.LscriptCall_56E6:
    bl ExitHotSpringBathingState__9GameScene
    b .LscriptCall_5C96
.LscriptCall_56EC:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_56FA
    b .LscriptCall_5C96
.LscriptCall_56FA:
    bl PreservePlayerLocationForNextDay__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5700:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_570E
    b .LscriptCall_5C96
.LscriptCall_570E:
    bl ClearPreservedPlayerLocation__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5714:
    movs r4, #0x1d
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5728
    bl GetPreservedPlayerMapId__9GameScene
    adds r4, r0, #0
.LscriptCall_5728:
    adds r2, r5, #0
    adds r2, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    b .LscriptCall_5BD6
.LscriptCall_5734:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5744
    bl .LscriptCall_1DAE
.LscriptCall_5744:
    bl EatRandomMeal__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_574C:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_575A
    b .LscriptCall_5C96
.LscriptCall_575A:
    bl PreparePlayerForScriptedAnimation__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5760:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5770
    bl .LscriptCall_1DAE
.LscriptCall_5770:
    bl RestorePlayerAfterScriptedAnimation__9GameScene
    bl .LscriptCall_1DAE
.LscriptCall_5778:
    adds r6, r5, #0
    adds r6, #0x24
    movs r3, #0xda
    lsls r3, r3, #1
    adds r2, r5, r3
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov sb, r0
    cmp r1, #0
    beq .LscriptCall_5796
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_5796:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_57AA
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_57AA:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_57BC
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_57BC:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_57CE
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_57CE:
    ldr r4, [r2]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r4, #0
    beq .LscriptCall_57E0
    subs r0, r4, #1
    str r0, [r2]
.LscriptCall_57E0:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_57EE
    b .LscriptCall_5C96
.LscriptCall_57EE:
    mov r0, r8
    str r0, [sp]
    mov r2, sb
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    adds r0, r1, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl CreateEventIcon__9GameScene17MaryEventIconSlotii18MaryEventIconLayeri
    b .LscriptCall_5C96
.LscriptCall_5806:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_581C
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_581C:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_582A
    b .LscriptCall_5C96
.LscriptCall_582A:
    bl RemoveEventIcon__9GameScene17MaryEventIconSlot
    b .LscriptCall_5C96
.LscriptCall_5830:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r5, r5, r0
    ldr r2, [r5]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_584C
    subs r0, r2, #1
    str r0, [r5]
.LscriptCall_584C:
    mov r4, sp
    adds r4, #0x36
    adds r0, r4, #0
    bl __4ToolUi
    adds r0, r4, #0
    bl GetIconId__C4Tool
    b .LscriptCall_58CA
.LscriptCall_585E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r1, #0xda
    lsls r1, r1, #1
    adds r4, r5, r1
    ldr r2, [r4]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_587A
    subs r0, r2, #1
    str r0, [r4]
.LscriptCall_587A:
    add r0, sp, #0xc
    bl __4FoodUi
    add r0, sp, #0xc
    bl GetIconId__C4Food
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
.LscriptCall_588A:
    ldr r1, [r4]
    cmp r1, #0x63
    bls .LscriptCall_5892
    b .LscriptCall_5C96
.LscriptCall_5892:
    lsls r0, r1, #2
    adds r0, r6, r0
    str r2, [r0]
.LscriptCall_5898:
    adds r0, r1, #1
    str r0, [r4]
    b .LscriptCall_5C96
.LscriptCall_589E:
    adds r6, r5, #0
    adds r6, #0x24
    movs r2, #0xda
    lsls r2, r2, #1
    adds r5, r5, r2
    ldr r2, [r5]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_58BA
    subs r0, r2, #1
    str r0, [r5]
.LscriptCall_58BA:
    mov r4, sp
    adds r4, #0x37
    adds r0, r4, #0
    bl __7ArticleUi
    adds r0, r4, #0
    bl GetIconId__C7Article
.LscriptCall_58CA:
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r1, [r5]
    cmp r1, #0x63
    bls .LscriptCall_58D6
    b .LscriptCall_5C96
.LscriptCall_58D6:
    lsls r0, r1, #2
    adds r0, r6, r0
    str r2, [r0]
    adds r0, r1, #1
    str r0, [r5]
    b .LscriptCall_5C96
.LscriptCall_58E2:
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r3, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_58F8
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_58F8:
    movs r4, #0xd5
    lsls r4, r4, #2
    adds r0, r5, r4
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5906
    b .LscriptCall_5C96
.LscriptCall_5906:
    rsbs r1, r3, #0
    orrs r1, r3
    lsrs r1, r1, #0x1f
    bl SetPlayerActorUpdateSuspended__9GameScene8MaryBool
    b .LscriptCall_5C96
.LscriptCall_5912:
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r1, [r2]
    lsls r0, r1, #2
    adds r0, r0, r5
    ldr r0, [r0, #0x20]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_592A
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_592A:
    movs r1, #0xd4
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    ldr r2, .LscriptCall_5980 @ =0x00001C2C
    adds r4, r0, r2
    adds r0, r4, #0
    bl IsHeldItemEmpty
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_596E
    adds r0, r4, #0
    bl GetKind__C8HeldItem
    cmp r0, #1
    bne .LscriptCall_596E
    adds r0, r4, #0
    bl GetArticle__C8HeldItem
    add r1, sp, #0x38
    strb r0, [r1]
    adds r0, r1, #0
    bl GetId__C7Article
    movs r1, #0
    cmp r0, r8
    bne .LscriptCall_5964
    movs r1, #1
.LscriptCall_5964:
    cmp r1, #0
    beq .LscriptCall_596E
    adds r0, r4, #0
    bl ClearHeldItem
.LscriptCall_596E:
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    ldr r4, .LscriptCall_5984 @ =0x00001C38
    adds r7, r0, r4
    movs r6, #0
    b .LscriptCall_59D0
    .align 2, 0
.LscriptCall_5980: .word 0x00001C2C
.LscriptCall_5984: .word 0x00001C38
.LscriptCall_5988:
    adds r0, r7, #0
    adds r1, r6, #0
    bl GetItemAt__8RucksackUi
    adds r4, r0, #0
    bl IsEmpty__C12RucksackItem
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_59CE
    adds r0, r4, #0
    bl GetKind__C12RucksackItem
    cmp r0, #1
    bne .LscriptCall_59CE
    adds r0, r4, #0
    bl GetArticle__C12RucksackItem
    mov r1, sp
    adds r1, #0x39
    strb r0, [r1]
    adds r0, r1, #0
    bl GetId__C7Article
    movs r1, #0
    cmp r0, r8
    bne .LscriptCall_59C0
    movs r1, #1
.LscriptCall_59C0:
    cmp r1, #0
    beq .LscriptCall_59CE
    add r0, sp, #0xc
    bl __12RucksackItem
    ldr r0, [sp, #0xc]
    str r0, [r4]
.LscriptCall_59CE:
    adds r6, #1
.LscriptCall_59D0:
    adds r0, r7, #0
    bl GetSize__C8Rucksack
    cmp r6, r0
    blo .LscriptCall_5988
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r4, r5, r6
    ldr r0, [r4]
    movs r1, #0xfa
    lsls r1, r1, #1
    adds r0, r0, r1
    bl GetShelf__9FarmHouse
    cmp r0, #0
    bne .LscriptCall_59F2
    b .LscriptCall_5C96
.LscriptCall_59F2:
    ldr r0, [r4]
    movs r2, #0xfa
    lsls r2, r2, #1
    adds r0, r0, r2
    bl GetShelf__9FarmHouse
    adds r7, r0, #0
    movs r5, #0
.LscriptCall_5A02:
    adds r0, r7, #0
    adds r1, r5, #0
    bl GetArticleStackAt__5ShelfUi
    adds r4, r0, #0
    adds r6, r4, #0
    bl IsEmpty__C12ArticleStack
    lsls r0, r0, #0x18
    cmp r0, #0
    bne .LscriptCall_5A46
    adds r0, r4, #0
    bl GetArticle__C12ArticleStack
    mov r1, sp
    adds r1, #0x3a
    strb r0, [r1]
    adds r0, r1, #0
    bl GetId__C7Article
    movs r1, #0
    cmp r0, r8
    bne .LscriptCall_5A32
    movs r1, #1
.LscriptCall_5A32:
    cmp r1, #0
    beq .LscriptCall_5A46
    add r0, sp, #0xc
    bl __12ArticleStack
    adds r0, r6, #0
    add r1, sp, #0xc
    movs r2, #2
    bl memcpy
.LscriptCall_5A46:
    adds r5, #1
    cmp r5, #0x3f
    bls .LscriptCall_5A02
    b .LscriptCall_5C96
.LscriptCall_5A4E:
    movs r3, #0xda
    lsls r3, r3, #1
    adds r1, r5, r3
    ldr r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r7, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_5A64
    subs r0, r2, #1
    str r0, [r1]
.LscriptCall_5A64:
    movs r6, #0xd4
    lsls r6, r6, #2
    adds r4, r5, r6
    ldr r0, [r4]
    ldr r1, .LscriptCall_5A9C @ =0x00001C70
    adds r0, r0, r1
    adds r1, r7, #0
    bl AddAffection__6Animali
    ldr r0, [r4]
    adds r0, #0x14
    bl GetHorse__4Farm
    cmp r0, #0
    beq .LscriptCall_5A90
    ldr r0, [r4]
    adds r0, #0x14
    bl GetHorse__4Farm
    adds r1, r7, #0
    bl AddAffection__6Animali
.LscriptCall_5A90:
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #3
    adds r6, r0, r2
    movs r4, #0
    b .LscriptCall_5AB4
    .align 2, 0
.LscriptCall_5A9C: .word 0x00001C70
.LscriptCall_5AA0:
    adds r0, r6, #0
    adds r1, r4, #0
    bl GetChicken__4CoopUi
    cmp r0, #0
    beq .LscriptCall_5AB2
    adds r1, r7, #0
    bl AddAffection__6Animali
.LscriptCall_5AB2:
    adds r4, #1
.LscriptCall_5AB4:
    adds r0, r6, #0
    bl GetCapacity__C4Coop
    cmp r4, r0
    blo .LscriptCall_5AA0
    movs r3, #0xd4
    lsls r3, r3, #2
    adds r0, r5, r3
    ldr r0, [r0]
    movs r4, #0xbe
    lsls r4, r4, #3
    adds r5, r0, r4
    movs r4, #0
    b .LscriptCall_5AE4
.LscriptCall_5AD0:
    adds r0, r5, #0
    adds r1, r4, #0
    bl GetBarnAnimal__4BarnUi
    cmp r0, #0
    beq .LscriptCall_5AE2
    adds r1, r7, #0
    bl AddAffection__6Animali
.LscriptCall_5AE2:
    adds r4, #1
.LscriptCall_5AE4:
    adds r0, r5, #0
    bl GetCapacity__C4Barn
    cmp r4, r0
    blo .LscriptCall_5AD0
    b .LscriptCall_5C96
.LscriptCall_5AF0:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5AFE
    b .LscriptCall_5C96
.LscriptCall_5AFE:
    bl CureAllSickLivestock__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5B04:
    adds r6, r5, #0
    adds r6, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r2, r5, r0
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r0, [r0]
    mov r8, r0
    cmp r1, #0
    beq .LscriptCall_5B22
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_5B22:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r3, [r0]
    cmp r1, #0
    beq .LscriptCall_5B34
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_5B34:
    ldr r1, [r2]
    lsls r0, r1, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r7, [r0]
    cmp r1, #0
    beq .LscriptCall_5B46
    subs r0, r1, #1
    str r0, [r2]
.LscriptCall_5B46:
    ldr r4, [r2]
    lsls r0, r4, #2
    subs r0, #4
    adds r0, r6, r0
    ldr r6, [r0]
    cmp r4, #0
    beq .LscriptCall_5B58
    subs r0, r4, #1
    str r0, [r2]
.LscriptCall_5B58:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r1, [r0]
    cmp r1, #0
    bne .LscriptCall_5B66
    b .LscriptCall_5C96
.LscriptCall_5B66:
    mov r2, r8
    str r2, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r1, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl RelocateEntityToMap__9GameSceneiUiiiUi
    b .LscriptCall_5C96
.LscriptCall_5B7A:
    movs r4, #0xda
    lsls r4, r4, #1
    adds r3, r5, r4
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_5B90
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_5B90:
    movs r6, #0xd5
    lsls r6, r6, #2
    adds r0, r5, r6
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5BA0
    bl .LscriptCall_1DAE
.LscriptCall_5BA0:
    bl ShowPlayerHoldingTool__9GameScene14MaryItemToolId
    bl .LscriptCall_1DAE
.LscriptCall_5BA8:
    movs r1, #0xd5
    lsls r1, r1, #2
    adds r0, r5, r1
    ldr r0, [r0]
    cmp r0, #0
    beq .LscriptCall_5C96
    bl FadeOutBackgroundMusic__9GameScene
    b .LscriptCall_5C96
.LscriptCall_5BBA:
    movs r2, #0xd4
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    ldr r3, .LscriptCall_5BE8 @ =0x00002214
    adds r0, r0, r3
    bl CountLearnedRecipes__C22CookingRecipeInventory
.LscriptCall_5BCA:
    adds r4, r0, #0
.LscriptCall_5BCC:
    adds r2, r5, #0
    adds r2, #0x24
    movs r6, #0xda
    lsls r6, r6, #1
    adds r1, r5, r6
.LscriptCall_5BD6:
    ldr r3, [r1]
    cmp r3, #0x63
    bhi .LscriptCall_5C96
    lsls r0, r3, #2
    adds r0, r2, r0
    str r4, [r0]
.LscriptCall_5BE2:
    adds r0, r3, #1
    str r0, [r1]
    b .LscriptCall_5C96
    .align 2, 0
.LscriptCall_5BE8: .word 0x00002214
.LscriptCall_5BEC:
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    adds r0, r0, r5
    ldr r1, [r0, #0x20]
    cmp r2, #0
    beq .LscriptCall_5C02
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_5C02:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r0, [r0]
    cmp r0, #0
    bne .LscriptCall_5C12
    bl .LscriptCall_1DAE
.LscriptCall_5C12:
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl BeginHoldingActorGraphic__9GameScene15MaryAnimationId
    bl .LscriptCall_1DAE
.LscriptCall_5C1E:
    adds r4, r5, #0
    adds r4, #0x24
    movs r3, #0xd6
    lsls r3, r3, #2
    adds r1, r5, r3
    movs r6, #0xda
    lsls r6, r6, #1
    adds r2, r5, r6
    ldr r3, [r2]
    cmp r3, #0x63
    bhi .LscriptCall_5C96
    lsls r0, r3, #2
    adds r0, r4, r0
    ldr r1, [r1]
.LscriptCall_5C3A:
    str r1, [r0]
    adds r0, r3, #1
    str r0, [r2]
    b .LscriptCall_5C96
.LscriptCall_5C42:
    adds r4, r5, #0
    adds r4, #0x24
    movs r0, #0xda
    lsls r0, r0, #1
    adds r3, r5, r0
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r1, [r0]
    cmp r2, #0
    beq .LscriptCall_5C5E
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_5C5E:
    ldr r2, [r3]
    lsls r0, r2, #2
    subs r0, #4
    adds r0, r4, r0
    ldr r6, [r0]
    cmp r2, #0
    beq .LscriptCall_5C70
    subs r0, r2, #1
    str r0, [r3]
.LscriptCall_5C70:
    movs r2, #0xd5
    lsls r2, r2, #2
    adds r0, r5, r2
    ldr r5, [r0]
    cmp r5, #0
    beq .LscriptCall_5C96
    mov r4, sp
    adds r4, #0x3b
    adds r0, r4, #0
    bl __7ProductUi
    adds r0, r4, #0
    bl GetName__C7Product
    adds r2, r0, #0
    adds r0, r5, #0
    adds r1, r6, #0
    bl TextVariableSetString__9GameSceneUiPCc
.LscriptCall_5C96:
    movs r0, #0
.LscriptCall_5C98:
    add sp, #0x40
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

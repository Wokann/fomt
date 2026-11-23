#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0139_LocationInteraction_ChurchConfessional.mary.h"

void EventScript_0139_LocationInteraction_ChurchConfessional(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, unused_6, var_7, var_8, var_9;
    var_7 = 0;
    var_3 = FALSE;
    var_5 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_HOUR);
    if (VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
    {
        var_3 = FALSE;
    }
    else
    {
        if (GetEntityLocation(ENTITY_CARTER) != MAP_NORTH_SIDE_TOWN && GetEntityLocation(ENTITY_CARTER) != MAP_CHURCH)
        {
            var_3 = TRUE;
        }
        else
        {
            var_3 = FALSE;
        }
    }
    if (var_3 == TRUE)
    {
        var_2 = FALSE;
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_11);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityXTo(ENTITY_PLAYER, X(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        MoveEntityYTo(ENTITY_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        do
        {
            if (var_2 != TRUE)
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_InitialServicePrompt);
            }
            else
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt);
            }
            var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool, gText_LocationInteraction_ChurchConfessional_ChoiceConfess, gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    if (GetPlayerHeldToolId() == ITEM_TOOL_SICKLE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HOE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_AXE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HAMMER_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_WATERING_CAN_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_FISHING_ROD_CURSED)
                    {
                        var_0 = TalkPromptChoice2(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt, gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee, gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval);
                        switch (var_0)
                        {
                            case PROMPT_CHOICE_OPTION_1:
                                if (GetMoney() >= 1000)
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer);
                                    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
                                    WaitFrames(60);
                                    SubtractMoney(1000);
                                    var_2 = FALSE;
                                    var_8 = GetPlayerHeldToolId();
                                    var_9 = var_8 + 1;
                                    var_7 = AttemptChurchCursedToolRemoval(var_8);
                                    if (var_7)
                                    {
                                        SetPlayerHeldTool(var_9, 1);
                                    }
                                    CycleBackwardToNonCursedTool();
                                }
                                else
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval);
                                    var_2 = TRUE;
                                }
                                break;
                            case PROMPT_CHOICE_OPTION_2:
                                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt);
                                var_2 = TRUE;
                                break;
                        }
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped);
                        var_2 = TRUE;
                    }
                    break;
                case CHOICE_OPTION_2:
                    if (VarGet(VAR_CHURCH_CONFESSION_USED_TODAY) == TRUE)
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay);
                        var_2 = TRUE;
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt);
                        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED) == TRUE)
                        {
                            var_1 = RandomIntInclusive(1, 4);
                        }
                        else
                        {
                            var_1 = RandomIntInclusive(0, 4);
                        }
                        switch (var_1)
                        {
                            case 0:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep, gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites, gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_STAID, 2);
                                                AddNpcFriendship(CHARACTER_NAPPY, 2);
                                                AddNpcFriendship(CHARACTER_BOLD, 2);
                                                AddNpcFriendship(CHARACTER_CHEF, 2);
                                                AddNpcFriendship(CHARACTER_AQUA, 2);
                                                AddNpcFriendship(CHARACTER_HOGGY, 2);
                                                AddNpcFriendship(CHARACTER_TIMID, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected);
                                                break;
                                        }
                                        break;
                                    mary_dead_jump:
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 9);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven);
                                                VarSet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED, TRUE);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                            case 4:
                                            case 5:
                                            case 6:
                                            case 7:
                                            case 8:
                                            case 9:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 1:
                            case 2:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals, gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed, gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 3:
                            case 4:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty, gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate, gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue);
                                                ChangePlayerStaminaAndFatigue(0, mary_negated_int(-2));
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete);
                        VarSet(VAR_CHURCH_CONFESSION_USED_TODAY, TRUE);
                        var_2 = FALSE;
                    }
                    break;
                case CHOICE_OPTION_3:
                    TalkMessage(gText_LocationInteraction_ChurchConfessional_Greeting);
                    var_2 = FALSE;
                    break;
            }
        }
        while (var_2 == TRUE);
        TalkMessage(gText_LocationInteraction_ChurchConfessional_Farewell);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityYTo(ENTITY_PLAYER, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        CloseDoor(DOOR_SLOT_11);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionalClosed);
        TalkClose();
    }
    if (var_7)
    {
        switch (var_9)
        {
            case ITEM_TOOL_HOE_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_HOE_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedHoePurified);
                TalkClose();
                break;
            case ITEM_TOOL_WATERING_CAN_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_WATERING_CAN_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified);
                TalkClose();
                break;
        }
    }
}

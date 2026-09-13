#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_ChurchConfessional_InitialServicePrompt[] =
        "Is something the matter?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt[] =
        "Can I help you with \r\n"
        "anything else?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool[] =
        "Remove a cursed tool.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfess[] =
        "I want to confess.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi[] =
        "Just saying 'hi'.";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt[] =
        "That will be 1,000 G.";

    const char gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee[] =
        "OK.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval[] =
        "No, thanks.";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer[] =
        "In that case, let us pray...{Press}\p"
        "Oh Harvest Goddess, please\r\n"
        "help us remove this \r\n"
        "unjust curse...{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval[] =
        "Sorry, but you don't seem\r\n"
        "to have enough Gold.\r\n"
        "Come back another time.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt[] =
        "Are you sure now?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped[] =
        "But nothing you have\r\n"
        "is cursed!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay[] =
        "Repent once each day.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt[] =
        "What do you wish\r\n"
        "to repent for?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep[] =
        "I hardly get any sleep.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites[] =
        "I'm overworking the HS.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess[] =
        "I want to marry the HG.";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven[] =
        "Sleep is very important\r\n"
        "for everyone, you know!{Press}\p"
        "I know you're very busy,\r\n"
        "but you really should get\r\n"
        "some rest once in a while.{Press}The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected[] =
        "Failing to sleep is to \r\n"
        "reject the nature granted\r\n"
        "you by the Harvest Goddess!{Press}\p"
        "You have displeased Her!{Press}\p"
        "She has not forgiven you,\r\n"
        "and someday you will\r\n"
        "pay the price.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven[] =
        "Do not fret. The Harvest\r\n"
        "Sprites help you because\r\n"
        "they wish to.{Press}\p"
        "However, I suggest giving\r\n"
        "then a present for their\r\n"
        "efforts to keep them happy.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected[] =
        "What do you mean, you make\r\n"
        "the Harvest Sprites work too\r\n"
        "hard?! How dare you repay{Press}\r\n"
        "their kindness by exploiting\r\n"
        "them! Don't you give them\r\n"
        "gifts, you scoundrel?{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven[] =
        "So you want to marry the\r\n"
        "Harvest goddess, do you?\r\n"
        "I'm sure she is very {Press}\r\n"
        "flattered by your attention.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected[] =
        "Wh-what!?...You say you\r\n"
        "want to marry the Harvest\r\n"
        "Goddess!? That's blasphemy!{Press}\r\n"
        "Of course, I do too, but...\r\n"
        "Wait! Forget I said that!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals[] =
        "I don't care for animals.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed[] =
        "Worked until I collapsed.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer[] =
        "Townspeople don't like me.";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven[] =
        "Don't forget that your\r\n"
        "animals give you their own\r\n"
        "milk, eggs, and wool to use!{Press}\p"
        "Express your gratitude \r\n"
        "by caring for them well!{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected[] =
        "What do you think the\r\n"
        "animals were put into your\r\n"
        "care by the Harvest Goddess{Press}\r\n"
        "for?!{Press}\p"
        "They give of themselves to\r\n"
        "you, so you must repay this\r\n"
        "debt by treating them as{Press}\r\n"
        "well as you can! Oh those\r\n"
        "poor animals!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven[] =
        "Your desire to work hard is\r\n"
        "very admirable. However, \r\n"
        "your body has its limits.{Press}\p"
        "If you work until you\r\n"
        "collapse, you are ignoring \r\n"
        "the limits the Harvest {Press}\r\n"
        "Goddess has placed on us.{Press}\p"
        "Next time, take some \r\n"
        "sustenance or rest before \r\n"
        "working so hard.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected[] =
        "What do you mean, working\r\n"
        "the body given to you by \r\n"
        "your parents into the{Press}\r\n"
        "ground? You must show more\r\n"
        "respect and gratitude to \r\n"
        "your body!!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship[] =
        "If the townspeople do not\r\n"
        "favor you, it's for a {Press}\p"
        "reason. Look inside your own\r\n"
        "heart first, then seek to\r\n"
        "make amends with those {Press}\r\n"
        "around you.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected[] =
        "Now even I don't like you\r\n"
        "very much! Let us end this\r\n"
        "conversation now!{Press}\r\n"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty[] =
        "I was cruel to my animals.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate[] =
        "I slept in late.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering[] =
        "I littered in the road.";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven[] =
        "The human heart is a weak\r\n"
        "thing, and often we seek to\r\n"
        "make ourselves feel better{Press}\r\n"
        "by cruelty to those weaker \r\n"
        "in strength. {Press}\p"
        "Remember that true \r\n"
        "strength lies in kindness\r\n"
        "to fellow creatures, \r\n"
        "especially those weaker \r\n"
        "than you.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected[] =
        "I can't believe this!\r\n"
        "How can you be so...so...\r\n"
        "cruel to poor, helpless{Press}\r\n"
        "animals! Oh, the humanity!{Press}\p"
        "I think there is no saving\r\n"
        "such a dark soul!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue[] =
        "Do not worry.\r\n"
        "Sometimes the flesh is weak\r\n"
        "even when the spirit is{Press}\r\n"
        "willing.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected[] =
        "Sleeping in is the sign of\r\n"
        "sloth in the heart!{Press}\p"
        "Who knows how many others\r\n"
        "you inconvenience by your\r\n"
        "laziness! You will not gain {Press}\r\n"
        "friends living like that!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven[] =
        "Throwing away your own\r\n"
        "garbage should be natural.{Press}\p"
        "Throwing away others'\r\n"
        "garbage is smiled upon by\r\n"
        "the Harvest Goddess.{Press}\p"
        "The Harvest Goddess has\r\n"
        "now forgiven you.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected[] =
        "...........................\r\n"
        "...........................\r\n"
        "I'm so flabbergasted, I lost\r\n"
        "the power of speech!{Press}\p"
        "What would you think if \r\n"
        "someone threw their garbage\r\n"
        "away in your bedroom!?{Press}\r\n"
        "You wouldn't like it, \r\n"
        "would you?!{Press}\p"
        "The Harvest Goddess has not\r\n"
        "forgiven you, and someday\r\n"
        "you will pay the price!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete[] =
        "That is enough for \r\n"
        "today's confession.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Greeting[] =
        "Hello. How are you?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Farewell[] =
        "Come again any time.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionalClosed[] =
        "It's locked.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedHoePurified[] =
        "The curse on the Hoe\r\n"
        "has been lifted!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified[] =
        "The curse on the Watering\r\n"
        "Can has been lifted!{Press}";
};

void EventScript_LocationInteraction_ChurchConfessional(void)
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

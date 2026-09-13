#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_PermanentWineryJob_AskToHelpAtWineryUntilFive[] =
        "Can you help out \r\n"
        "until about 5PM?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceAcceptWineryHelp[] =
        "Of course.";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceDeclineWineryHelp[] =
        "Sorry, I can't.";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CannotWorkWhileHoldingItem[] =
        "You can't work with \r\n"
        "something in your hand, \r\n"
        "you know!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_KeepUpTheGoodWork[] =
        "Do a good job, now!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_BothOfYouKeepUpTheGoodWork[] =
        "Do a good job, you two!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeTellsPlayerToKeepWorking[] =
        "No sloughing off, now!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WagesDeposited[] =
        "Thanks for helping out. \r\n"
        "I've deposited your pay.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ThanksForHelpOffersGrapeJuice[] =
        "Thanks for all your help.\r\n"
        "Here is fresh grape juice.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeExplainsHarvestedGrapesBecomeWine[] =
        "Look forward to tasting\r\n"
        "the Wine made of the\r\n"
        "Grapes you picked! {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerOffersCliffPermanentJob[] =
        "Cliff, what do you think \r\n"
        "about working here at Aja\r\n"
        "Winery full time? {Press}\p"
        "The harvest is over, but \r\n"
        "Wine making is a year-\r\n"
        "round job!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAsksIfJobOfferIsSerious[] =
        "Really!?...\r\n"
        "You're serious?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WineryNeedsHelpAfterAjaLeft[] =
        "With Aja gone off to \r\n"
        "the city, it's awful hard \r\n"
        "for just Manna and me. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAcceptsPermanentJob[] =
        "Thanks. You won't \r\n"
        "regret it!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffThanksPlayerForWineryOpportunity[] =
        "This is all thanks to you, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeWelcomesCliffToWinery[] =
        "I'm glad to have you \r\n"
        "with us, Cliff.{Press}\p"
        "Now, let me show you how\r\n"
        "some other things are \r\n"
        "done around here...{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeReturnsEveryoneToWork[] =
        "Back to work, I guess!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeThanksPlayerForInvitingCliff[] =
        "Thanks for thinking of \r\n"
        "inviting Cliff, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerContinuesWineryWork[] =
        "Now...Back to work!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_InspiredByCliffsWineryWork[] =
        "It's good to see Cliff \r\n"
        "so happy about his work. {Press}";
};

void EventScript_NPCEvent_Cliff_PermanentWineryJob(void)
{
    int var_0;
    ChangeMap(MAP_AJA_WINERY_1F, X(92), Y(153));
    SetEntityPosition(ENTITY_PLAYER, X(92), Y(153), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MANNA, X(92), Y(124), FACING_DOWN);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_AskToHelpAtWineryUntilFive);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceAcceptWineryHelp, gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceDeclineWineryHelp);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            if (IsPlayerHoldingNothing() == FALSE)
            {
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_MANNA);
                TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_CannotWorkWhileHoldingItem);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_NORTH_SIDE_TOWN, X(232), Y(488));
                SetEntityPosition(ENTITY_PLAYER, X(232), Y(488), FACING_DOWN);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                return;
            }
            else
            {
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_MANNA);
                TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_KeepUpTheGoodWork);
                TalkClose();
                VarSet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_NORTH_SIDE_TOWN, X(348), Y(483));
                if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
                {
                    SetEntityPosition(ENTITY_CLIFF, X(329), Y(474), FACING_RIGHT);
                    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
                }
                SetEntityPosition(ENTITY_PLAYER, X(348), Y(483), FACING_RIGHT);
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                else
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                }
                SetEntityPosition(ENTITY_DUKE, X(371), Y(483), FACING_LEFT);
                SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_DUKE);
                if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE)
                {
                    TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_KeepUpTheGoodWork);
                    TalkClose();
                }
                else
                {
                    TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_BothOfYouKeepUpTheGoodWork);
                    TalkClose();
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                    WaitFrames(60);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    WaitFrames(30);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_CLIFF);
                    TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_DukeTellsPlayerToKeepWorking);
                    TalkClose();
                    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
                    WaitFrames(30);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                    WaitFrames(60);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_NORTH_SIDE_TOWN, X(232), Y(508));
                SetGameTime(17, 0);
                AddMoney(1000);
                AddNpcFriendship(CHARACTER_DUKE, 20);
                AddNpcFriendship(CHARACTER_MANNA, 20);
                if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE)
                {
                    SetEntityPosition(ENTITY_PLAYER, X(232), Y(508), FACING_UP);
                    if (IsPlayerHoldingNothing() == TRUE)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                }
                else
                {
                    SetEntityPosition(ENTITY_PLAYER, X(217), Y(508), FACING_UP);
                    if (IsPlayerHoldingNothing() == TRUE)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                    SetEntityPosition(ENTITY_CLIFF, X(241), Y(508), FACING_UP);
                    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
                }
                SetEntityPosition(ENTITY_MANNA, X(217), Y(487), FACING_DOWN);
                SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
                SetEntityPosition(ENTITY_DUKE, X(243), Y(487), FACING_DOWN);
                SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_DUKE);
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_WagesDeposited);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_MANNA);
                TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_ThanksForHelpOffersGrapeJuice);
                TalkClose();
                SetPlayerHeldFood(ITEM_FOOD_WINE);
                WaitFrames(60);
                PlaySong(AUDIO_START, AUDIO_SFX_DRINK);
                ClearPlayerHeldItem();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_DRINK);
                WaitFrames(72);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                WaitFrames(30);
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_S);
                WaitFrames(60);
                PlaySong(AUDIO_START, AUDIO_SFX_EAT);
                ClearPlayerHeldItem();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_EAT);
                WaitFrames(24);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                WaitFrames(30);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_DUKE);
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_DukeExplainsHarvestedGrapesBecomeWine);
                TalkClose();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                WaitFrames(60);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                WaitFrames(30);
                if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE)
                {
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    HideEntity(ENTITY_DUKE);
                    HideEntity(ENTITY_MANNA);
                    ChangeMap(MAP_NORTH_SIDE_TOWN, X(232), Y(508));
                    SetEntityPosition(ENTITY_PLAYER, X(232), Y(508), FACING_DOWN);
                    if (IsPlayerHoldingNothing() == TRUE)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                }
                else
                {
                    WaitFrames(60);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_DUKE);
                    TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_PlayerOffersCliffPermanentJob);
                    TalkClose();
                    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
                    WaitFrames(60);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_CLIFF);
                    TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_CliffAsksIfJobOfferIsSerious);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_MANNA);
                    TalkMessageSlow(gText_NPCEvent_Cliff_PermanentWineryJob_WineryNeedsHelpAfterAjaLeft);
                    TalkClose();
                    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
                    WaitFrames(60);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_CLIFF);
                    TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_CliffAcceptsPermanentJob);
                    TalkClose();
                    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
                    SetEntityFacing(ENTITY_CLIFF, FACING_LEFT);
                    WaitFrames(30);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_CLIFF);
                    TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_CliffThanksPlayerForWineryOpportunity);
                    TalkClose();
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                    WaitFrames(60);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    WaitFrames(30);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    HideEntity(ENTITY_DUKE);
                    HideEntity(ENTITY_MANNA);
                    HideEntity(ENTITY_CLIFF);
                    ChangeMap(MAP_NORTH_SIDE_TOWN, X(217), Y(508));
                    SetEntityPosition(ENTITY_PLAYER, X(217), Y(508), FACING_DOWN);
                    if (IsPlayerHoldingNothing() == TRUE)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                    AddNpcFriendship(CHARACTER_CLIFF, 20);
                }
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(231), Y(484));
            if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
            {
                SetEntityPosition(ENTITY_CLIFF, X(330), Y(472), FACING_RIGHT);
                SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
            }
            SetEntityPosition(ENTITY_PLAYER, X(231), Y(484), FACING_DOWN);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            SetEntityPosition(ENTITY_DUKE, X(316), Y(483), FACING_RIGHT);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            WaitFrames(30);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(262), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
            if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
            {
                SetEntityFacing(ENTITY_CLIFF, FACING_LEFT);
            }
            WaitFrames(30);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            WaitFrames(30);
            if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_DUKE);
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_DukeWelcomesCliffToWinery);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_DukeReturnsEveryoneToWork);
                TalkClose();
                PlacePlayerAtFarmhouseBed();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                SetGameTime(17, 0);
                AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
                AddNpcFriendship(CHARACTER_MANNA, mary_negated_int(-10));
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_DUKE);
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_DukeThanksPlayerForInvitingCliff);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_CLIFF);
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_PlayerContinuesWineryWork);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_NPCEvent_Cliff_PermanentWineryJob_InspiredByCliffsWineryWork);
                TalkClose();
                PlacePlayerAtFarmhouseBed();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                SetGameTime(17, 0);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            break;
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    MarkNpcSpokenTo(CHARACTER_DUKE);
    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
    {
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    VarSet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_CLIFF_WINERY_EMPLOYMENT_STATUS, CLIFF_WINERY_PERMANENT_EMPLOYEE);
}

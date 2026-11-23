#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0343_NPCEvent_Spouse_BedtimeDialogue.mary.h"

void EventScript_0343_NPCEvent_Spouse_BedtimeDialogue(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    var_0 = FALSE;
    var_1 = VarGet(VAR_SEASON);
    var_2 = VarGet(VAR_DAY);
    var_4 = VarGet(VAR_HOUR);
    var_3 = VarGet(VAR_DAY_OF_WEEK);
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            var_0 = FALSE;
        }
        else
        {
            if (var_4 >= 20)
            {
                if (var_1 == SEASON_SPRING && var_2 == DAY_22 || var_1 == SEASON_FALL && var_2 == DAY_13)
                {
                    var_0 = FALSE;
                }
                else
                {
                    var_0 = TRUE;
                }
            }
            else
            {
                var_0 = FALSE;
            }
        }
    }
    else
    {
        if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            if (VarGet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                var_0 = FALSE;
            }
            else
            {
                if (var_4 >= 20)
                {
                    if (var_1 == SEASON_FALL && var_2 == DAY_13)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        var_0 = TRUE;
                    }
                }
                else
                {
                    var_0 = FALSE;
                }
            }
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (var_4 >= 20)
                    {
                        if (var_1 == SEASON_SPRING && var_2 == DAY_22 || var_1 == SEASON_FALL && var_2 == DAY_13)
                        {
                            var_0 = FALSE;
                        }
                        else
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        var_0 = FALSE;
                    }
                }
            }
            else
            {
                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (VarGet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        if (var_4 >= 20)
                        {
                            if (var_1 == SEASON_FALL && var_2 == DAY_13)
                            {
                                var_0 = FALSE;
                            }
                            else
                            {
                                var_0 = TRUE;
                            }
                        }
                        else
                        {
                            var_0 = FALSE;
                        }
                    }
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        if (VarGet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            var_0 = FALSE;
                        }
                        else
                        {
                            if (var_4 >= 20)
                            {
                                if (var_1 == SEASON_FALL && var_2 == DAY_13)
                                {
                                    var_0 = FALSE;
                                }
                                else
                                {
                                    var_0 = TRUE;
                                }
                            }
                            else
                            {
                                var_0 = FALSE;
                            }
                        }
                    }
                    else
                    {
                        var_0 = FALSE;
                    }
                }
            }
        }
    }
    if (var_0 == TRUE)
    {
        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IN_BED_AWAKE);
            WaitFrames(15);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            if (GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_GREEN_MIN)
            {
                if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
                {
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_SorryIDontFeelLikeTalking);
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_PleaseLeaveMeAlone);
                }
            }
            else
            {
                if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
                {
                    if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
                    {
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
#if defined(REGION_JP)
                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Karen30000To39999_FirstConversation);
#else
                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_Karen30000To39999_Ann40000To49999_PopuriAtLeast60000_FirstConversation);
#endif
                    }
                    else
                    {
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IAlwaysWantToGoPlay);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_ORANGE_MIN)
                    {
                        if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                            ShowTalkHeartIndicator(CHARACTER_KAREN);
#if defined(REGION_JP)
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_Karen40000To49999_Mary30000To39999_FirstConversation);
#else
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_KarenAndElli40000To49999_FirstConversation);
#endif
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_KAREN);
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IfYouDontGoToSleep);
                        }
                    }
                    else
                    {
                        if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_RED_MIN)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
                                ShowTalkHeartIndicator(CHARACTER_KAREN);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_GoodNightGoodWorkToday);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
                                ShowTalkHeartIndicator(CHARACTER_KAREN);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_TomorrowsAnotherDay);
                            }
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_RED_MIN)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
                                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_NickNameGoodNight);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
                                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ICantWaitUntilMorningSleeping);
                                }
                            }
                        }
                    }
                }
            }
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_SETTLE_IN_BED);
            WaitFrames(15);
        }
        else
        {
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_REACTION);
                WaitFrames(15);
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN)
                {
                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                    {
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_PopuriBelow30000FirstConversationSilentPause);
                    }
                    else
                    {
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ICantStandThisAnyMore);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                    {
                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IStayedUpLateWaitingFor);
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ImGoingToBedNowThough);
                        }
                    }
                    else
                    {
                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_ORANGE_MIN)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IGetTiredSoEasilyYou);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_LookMyHandsAreAlreadyWarm);
                            }
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_RED_MIN)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_YouLookBeatHardDayOn);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_TheBestThingForAHard);
                                }
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_RED_MIN)
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
#if defined(REGION_JP)
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_PopuriAtLeast60000_FirstConversation);
#else
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_Karen30000To39999_Ann40000To49999_PopuriAtLeast60000_FirstConversation);
#endif
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ArenYouTiredIMGoing);
                                    }
                                }
                            }
                        }
                    }
                }
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_POPURI);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_SETTLE_IN_BED);
                WaitFrames(15);
            }
            else
            {
                if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED_AWAKE);
                    WaitFrames(15);
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    if (GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_GREEN_MIN)
                    {
                        if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
                            ShowTalkHeartIndicator(CHARACTER_ANN);
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_HahIFeelSoDepressed);
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
                            ShowTalkHeartIndicator(CHARACTER_ANN);
                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_FineDoWhateverYouWant);
                        }
                    }
                    else
                    {
                        if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                                ShowTalkHeartIndicator(CHARACTER_ANN);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_YawnImSoTiredToday);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                                ShowTalkHeartIndicator(CHARACTER_ANN);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_YouShouldGetToSleepNow);
                            }
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_ORANGE_MIN)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                                    ShowTalkHeartIndicator(CHARACTER_ANN);
#if defined(REGION_JP)
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Ann40000To49999_FirstConversation);
#else
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_Karen30000To39999_Ann40000To49999_PopuriAtLeast60000_FirstConversation);
#endif
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                                    ShowTalkHeartIndicator(CHARACTER_ANN);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_BetterGetToSleepNowSo);
                                }
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_RED_MIN)
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                                        ShowTalkHeartIndicator(CHARACTER_ANN);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_GoodNightYouveGotAFull);
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                                        ShowTalkHeartIndicator(CHARACTER_ANN);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IHopeTomorrowWillBeAs);
                                    }
                                }
                                else
                                {
                                    if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_RED_MIN)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
                                            ShowTalkHeartIndicator(CHARACTER_ANN);
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_AnnAtLeast60000FirstConversationSilentPause);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                                            ShowTalkHeartIndicator(CHARACTER_ANN);
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_BoyTheDaysSureGoQuickly);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_ANN);
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_SETTLE_IN_BED);
                    WaitFrames(15);
                }
                else
                {
                    if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED_AWAKE);
                        WaitFrames(15);
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        if (GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_GREEN_MIN)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                                ShowTalkHeartIndicator(CHARACTER_MARY);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_DontYouThinkYoureALittle);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
                                ShowTalkHeartIndicator(CHARACTER_MARY);
                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IKnowYouNeedToWork);
                            }
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                                    ShowTalkHeartIndicator(CHARACTER_MARY);
#if defined(REGION_JP)
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_Karen40000To49999_Mary30000To39999_FirstConversation);
#else
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Mary30000To49999_FirstConversation);
#endif
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                                    ShowTalkHeartIndicator(CHARACTER_MARY);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IllGoToBedLaterIm);
                                }
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_ORANGE_MIN)
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                                        ShowTalkHeartIndicator(CHARACTER_MARY);
#if defined(REGION_JP)
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_MaryAndElli40000To49999_FirstConversation);
#else
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Mary30000To49999_FirstConversation);
#endif
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                                        ShowTalkHeartIndicator(CHARACTER_MARY);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_DontWorryIWontGoAnywhere);
                                    }
                                }
                                else
                                {
                                    if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_RED_MIN)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                                            ShowTalkHeartIndicator(CHARACTER_MARY);
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_YouSureLookTiredGoTo);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
                                            ShowTalkHeartIndicator(CHARACTER_MARY);
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_LetMeKnowIfYouDream);
                                        }
                                    }
                                    else
                                    {
                                        if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_RED_MIN)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_MARY);
                                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ILikeStayingUpLateAt);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_MARY);
                                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_IWishWeCouldWakeUp);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_MARY);
                        SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_SETTLE_IN_BED);
                        WaitFrames(15);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IN_BED_AWAKE);
                            WaitFrames(15);
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            if (GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_GREEN_MIN)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_SorryButImTiredAndDont);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ElliBelow30000RepeatConversationSilentPause);
                                }
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ImSoTired);
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                                        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_ImSoSleepy);
                                    }
                                }
                                else
                                {
                                    if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_ORANGE_MIN)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                                            ShowTalkHeartIndicator(CHARACTER_ELLI);
#if defined(REGION_JP)
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_MaryAndElli40000To49999_FirstConversation);
#else
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_Shared_KarenAndElli40000To49999_FirstConversation);
#endif
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                                            ShowTalkHeartIndicator(CHARACTER_ELLI);
                                            TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_DontStayUpLateGoTo);
                                        }
                                    }
                                    else
                                    {
                                        if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_RED_MIN)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_ELLI);
                                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_GoToBedEarlySoYoure);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                                                ShowTalkHeartIndicator(CHARACTER_ELLI);
                                                TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_HurryUpAndGoToSleep);
                                            }
                                        }
                                        else
                                        {
                                            if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_RED_MIN)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
                                                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_GoodNightNickName);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
                                                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                                                    TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_GoToBedBeforeMe);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            TalkClose();
                            MarkNpcSpokenTo(CHARACTER_ELLI);
                            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_SETTLE_IN_BED);
                            WaitFrames(15);
                        }
                    }
                }
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_NPCEvent_Spouse_BedtimeDialogue_BigBed);
        TalkClose();
    }
}

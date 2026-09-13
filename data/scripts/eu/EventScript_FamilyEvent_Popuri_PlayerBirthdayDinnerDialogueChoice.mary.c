#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "You know what day it is\r\n"
        "today, right...?{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy[] =
        "I can't believe you're so\r\n"
        "busy you even forgot your \r\n"
        "own birthday!{Press}\p"
        "Eat this and go to bed\r\n"
        "early, {NickName}.{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis[] =
        "Happy birthday! \r\n"
        "I've been planning this for\r\n"
        "a long time!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday[] =
        "How can you confuse my\r\n"
        "birthday with your own?!\r\n"
        "You're unbelievable!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether[] =
        "Let's be together always,\r\n"
        "OK? No matter how old we \r\n"
        "get...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow[] =
        "What are you talking \r\n"
        "about!? How can you not \r\n"
        "remember your own birthday!{Press}\p"
        "I can't believe you...!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
                        TalkClose();
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                        WaitFrames(60);
                        if (IsPlayerHoldingNothing())
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                        }
                        else
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                        }
                        WaitFrames(60);
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
                        TalkClose();
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                        WaitFrames(60);
                        if (IsPlayerHoldingNothing())
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                        }
                        else
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                        }
                        WaitFrames(60);
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
